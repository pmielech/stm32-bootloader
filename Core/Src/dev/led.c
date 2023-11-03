/*
 * led.c
 *
 *  Created on: 3 lis 2023
 *      Author: patryk
 */


#include "led.h"


#define LONG_BLINK 2000u



void vLedProc(sys_process_t * sys_proc){


	switch(*sys_proc){

	case INIT:
		vLedBlinkMultiple();

		break;

	case BOOTLOADER:
		vLedBlinkLongTick();
		break;

	}

}

void vLedBlinkMultiple(void){
	int i;
	for(i = 0; i <= 5; i++){
	    HAL_GPIO_TogglePin(SYS_LED_GPIO_Port, SYS_LED_Pin);
	    HAL_Delay(50);

	}
	HAL_GPIO_WritePin(SYS_LED_GPIO_Port, SYS_LED_Pin, GPIO_PIN_RESET);


}

void vLedBlinkLongTick(void){
	static uint32_t tick_start = 0;
	if(tick_start == 0){
		tick_start = HAL_GetTick();

	}
	uint32_t tick = HAL_GetTick();

	if (LONG_BLINK <= tick - tick_start)
	{
	    HAL_GPIO_TogglePin(SYS_LED_GPIO_Port, SYS_LED_Pin);
	    tick_start = 0;
	}
}
