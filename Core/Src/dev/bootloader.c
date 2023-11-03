/*
 * bootloader.c
 *
 *  Created on: 2 lis 2023
 *      Author: patryk
 */

#include "bootloader.h"


//void JumpToApp(void)
//{
//	uint32_t JumpAddress;
//	pFunction Jump_To_Application;
//
//	//check if there is something "installed" in the app FLASH region
//	if(((*(uint32_t*) FLASH_APP_ADDR) & 0x2FFE0000) == 0x20000000)
//	{
//		printf("APP Start ...\r\n");
//		HAL_Delay(100);
//		//jump to the application
//		JumpAddress = *(uint32_t *) (FLASH_APP_ADDR + 4 );
//		Jump_To_Application = (pFunction) JumpAddress;
//		//initialize application's stack pointer
//		__set_MSP(*(uint32_t *)FLASH_APP_ADDR);
//		Jump_To_Application();
//	}
//	else
//	{
//		//there is no application installed
//		printf("No APP found\r\n");
//	}
//}
