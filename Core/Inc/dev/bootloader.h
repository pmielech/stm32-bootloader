/*
 * bootloader.h
 *
 *  Created on: 2 lis 2023
 *      Author: patryk
 */

#ifndef INC_DEV_BOOTLOADER_H_
#define INC_DEV_BOOTLOADER_H_

#include <stdio.h>


#define BOOTLOADER_START 	0x8000000
#define BOOTLOADER_SIZE 	22

#define FLASH_APP_ADDR		BOOTLOADER_START + (BOOTLOADER_SIZE * 1000 * 1024) //0x8005800

#endif /* INC_DEV_BOOTLOADER_H_ */
