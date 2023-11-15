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

//#define LIMIT			1024
#define ADDRESS			0x60000000
/*

maybe:
- https://barrgroup.com/embedded-systems/how-to/memory-test-suite-c

*/

// https://stackoverflow.com/questions/5610298/why-does-int-pointer-increment-by-4-rather-than-1



int main(){


	uint32_t address = ADDRESS;
	int val = 1;
	/*
	printf("%x, %x\n",address, val);
	address++;
	printf("%x\n",address);
	
*/ 
	//printf("start writing 0s\n");
	/*for(int i = 0; i < 3000; i++){
		
		memWrite(address, 0);
		k_msleep(10);
		val++;
		address++;
	}*/
	printf("Done\nStart writing mem\n");
	address = ADDRESS;
	
	for(int i = 0; i < 3000; i++){
		
		memWrite(address, val);
		

		val++;
		address++;
		//k_usleep(100);
	}
	printf("Done\nReading mem\n");
	address = ADDRESS;
	for(int i = 0; i < 3000; i++){

		memRead(address);
		address++;
		//k_usleep(100);
	}
	//printf("%x, %x\n",address, val);
	//printf("%x\n",address);
	/*
	memRead(address);
	memWrite(address, val);
	memRead(address);
	*/

	printf("memtest complete");
	return 0;
}

void memWrite(uint32_t addr, char data){
	volatile uint32_t* ptr = (uint32_t *)addr;
	*ptr = data;
}

void memRead(uint32_t addr){
	volatile uint32_t* readaddr = (uint32_t *)addr;
	char read_val = *readaddr;
	printf("%p: %08d \n",readaddr, read_val);
}

