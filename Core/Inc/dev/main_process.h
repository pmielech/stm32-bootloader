/*
 * main_proc.h
 *
 *  Created on: 3 lis 2023
 *      Author: patryk
 */

#ifndef INC_DEV_MAIN_PROCESS_H_
#define INC_DEV_MAIN_PROCESS_H_

#include "main.h"

typedef enum{
	INIT,
	BOOTLOADER,
	UPDATE,
	APP

} sys_process_t;

uint8_t initUsartDma(void);
void main_proc(void);
void prog_delay(uint32_t def_ticks);

#endif /* INC_DEV_MAIN_PROCESS_H_ */
