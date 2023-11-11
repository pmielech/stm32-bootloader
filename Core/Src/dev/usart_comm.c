/*
 * usart_comm.c
 *
 *  Created on: Nov 11, 2023
 *      Author: patryk
 */

#include <usart.h>
#include <main.h>
#include <string.h>
#include <stdlib.h>


#include "usart_comm.h"
#include "main_process.h"

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;

extern sys_process_t sys_process;


uint8_t UartRxBuffer[UART_RX_BUFFER] = {0};
uint8_t ReceiveBuf[UART_RX_BUFFER];
uint8_t OperationalBuf[UART_RX_BUFFER];

uint8_t initUsartDma(void){
	uint8_t ret= 0;
	ret += HAL_UARTEx_ReceiveToIdle_DMA(&huart2, UartRxBuffer, UART_RX_BUFFER);
	__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);

	return ret;
}


int __io_putchar(int ch)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    return 1;
}


void resetUartDmaRxBuffer(UART_HandleTypeDef  *huart, uint16_t Size) {
    __HAL_DMA_DISABLE(huart->hdmarx);
    huart->hdmarx->Instance->CNDTR = Size;
    __HAL_DMA_ENABLE(huart->hdmarx);
}

void sys_command(uint32_t received_msg){

	switch(received_msg){

	case CMD_RESET:
        NVIC_SystemReset();
		break;

	case CMD_APP_UPDATE:
		sys_process = UPDATE;
		break;

	}



}
void clearDmaBuffer(){
    memset(UartRxBuffer, 0u, UART_RX_BUFFER);

    resetUartDmaRxBuffer(&huart2, UART_RX_BUFFER);
    HAL_UARTEx_ReceiveToIdle_DMA(&huart2, UartRxBuffer, UART_RX_BUFFER);
    __HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);

}

uint32_t convertCharToUint32(const char * buffer){
	return (uint32_t)strtol(buffer, NULL, 16);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){

    static uint8_t callbackHandler = 0;

    if(huart->Instance == USART2){
        callbackHandler = 0u;

        if(sys_process == UPDATE){


        } else {

        	sys_command(convertCharToUint32((const char*)UartRxBuffer));

        }

        clearDmaBuffer();

    }

    else {
        callbackHandler++;
    }

    if(callbackHandler > UART_RX_BUFFER-1u){

        clearDmaBuffer();

    }


}


