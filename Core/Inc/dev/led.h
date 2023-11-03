/*
 * led.h
 *
 *  Created on: 3 lis 2023
 *      Author: patryk
 */

#ifndef INC_DEV_LED_H_
#define INC_DEV_LED_H_

#include "main_proc.h"
#include "stm32f3xx.h"
#include "main.h"



void vLedProc(sys_process_t * sys_proc);
void vLedBlinkMultiple(void);
void vLedBlinkLongTick(void);

#endif /* INC_DEV_LED_H_ */
