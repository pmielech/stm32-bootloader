/*
 * bootloader.h
 *
 *  Created on: 2 lis 2023
 *      Author: patryk
 */

#ifndef INC_DEV_BOOTLOADER_H_
#define INC_DEV_BOOTLOADER_H_

#include <stdio.h>

#define LOCATE_FUNC __attribute__((section(".bootsection")))
#define FLASH_APP_ADDR 0x8000000

#endif /* INC_DEV_BOOTLOADER_H_ */
