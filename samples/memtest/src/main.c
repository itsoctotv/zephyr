/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdint.h>
#include <zephyr/kernel.h>

void memWrite(uint32_t addr, char data);
void memRead(uint32_t addr);

#define LIMIT			1500

/*

TODO:
fill the PSRAM 512KB (struct bit array)

Random locations with pointer and counter that counts lineary and fills the specific memory address

maybe:
- https://barrgroup.com/embedded-systems/how-to/memory-test-suite-c


*/





// !!! https://stackoverflow.com/questions/5610298/why-does-int-pointer-increment-by-4-rather-than-1 !!!



int main(){


	uint32_t addr = 0x60000000;
	for(int i = 0; i < LIMIT; i++){

		memRead(addr);
		addr += sizeof(addr);
		
	}

	char count = 1;
	addr = 0x60000000;
	printf("WRITING MEM\n");
	k_msleep(2000);
	for(int i = 0; i < LIMIT; i++){
	
		memWrite(addr, count);
		/*if(count > 0xff){
			count = 0;
		}*/
		count++;
		addr += sizeof(addr);
	}
	printf("DONE\n");
	k_msleep(2000);
	addr = 0x60000000;
	for(int i = 0; i < LIMIT; i++){

		memRead(addr);
		addr += sizeof(addr);
		
	}
	printf("memtest complete");
	return 0;
}

void memWrite(uint32_t addr, char data){
	volatile uint32_t *ptr = (uint32_t *)addr;
	*ptr = data;
}

void memRead(uint32_t addr){
	volatile uint32_t *readaddr = (uint32_t *)addr;
	printf("%p: %02x \n",readaddr, *readaddr);
}

