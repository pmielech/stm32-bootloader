/*
 * main_process.c
 *
 *  Created on: Nov 11, 2023
 *      Author: patryk
 */


#include <main_process.h>
#include "bootloader.h"
#include "led.h"

#define BOOT_TIME  5000

sys_process_t sys_process = INIT;

static uint32_t prog_iter = 0;

void main_proc(void){


	for(;;){

		prog_iter++;
		vLedProc(&sys_process);
		prog_delay(BOOT_TIME);


	}


}

void prog_delay(uint32_t def_ticks){
	static uint32_t tick_start = 0;

	if(tick_start == 0){
		tick_start = HAL_GetTick();

	}
	uint32_t tick = HAL_GetTick();

	if (def_ticks <= tick - tick_start)
	{
		prog_iter = 0;
		tick_start = 0;

	}



}

