/*
 * bootloader.c
 *
 *  Created on: 2 lis 2023
 *      Author: patryk
 */

#include "bootloader.h"
#include "main.h"



extern UART_HandleTypeDef huart2;

void JumpToApp(void)
{
	uint32_t* reset_vector_entry = (uint32_t*)(FLASH_APP_ADDR + 4U);
	uint32_t* reset_vector = (uint32_t*)(*reset_vector_entry);
	void_func make_jump = (void_func)reset_vector;

	Regs_DeInit();
	make_jump();
}



void Regs_DeInit(void){

	HAL_UART_DeInit(&huart2);
	DMA_DeInit();
	GPIO_DeInit();

	HAL_DeInit();
}

void GPIO_DeInit(void){

	HAL_GPIO_WritePin(SYS_LED_GPIO_Port, SYS_LED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_DeInit(SYS_LED_GPIO_Port, SYS_LED_Pin);

	__HAL_RCC_GPIOA_CLK_DISABLE();


}

void DMA_DeInit(void){

	 HAL_NVIC_DisableIRQ(DMA1_Channel6_IRQn);
	  __HAL_RCC_DMA1_CLK_DISABLE();

}


