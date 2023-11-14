/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdint.h>
#include <zephyr/kernel.h>

void memWrite(uint32_t addr, int32_t data);
void memRead(uint32_t addr);

#define LIMIT			4096
#define ADDRESS			0x60000000
/*

TODO:
fill the PSRAM 512KB (struct bit array)

Random locations with pointer and counter that counts lineary and fills the specific memory address

maybe:
- https://barrgroup.com/embedded-systems/how-to/memory-test-suite-c

*/

// !!! https://stackoverflow.com/questions/5610298/why-does-int-pointer-increment-by-4-rather-than-1 !!!



int main(){


	uint32_t addr = ADDRESS;
	for(int i = 0; i < LIMIT; i++){

		memRead(addr);
		addr += sizeof(uint32_t);
		
	}

	int32_t count = 1;
	addr = ADDRESS;
	printf("WRITING MEM\n");
	k_msleep(1000);
	for(int i = 0; i < LIMIT; i++){
	
		memWrite(addr, count);
		/*if(count > 0xff){
			count = 0;
		}*/
		count++;
		addr += sizeof(uint32_t);
	}
	printf("DONE\n");
	k_msleep(1000);
	addr = ADDRESS;
	for(int i = 0; i < LIMIT; i++){

		memRead(addr);
		addr += sizeof(uint32_t);
		
	}
	printf("memtest complete");
	return 0;
}

void memWrite(uint32_t addr, int32_t data){
	volatile uint32_t *ptr = (uint32_t *)addr;
	*ptr = data;
}

void memRead(uint32_t addr){
	volatile uint32_t *readaddr = (uint32_t *)addr;
	printf("%p: %08x \n",readaddr, *readaddr);
}

