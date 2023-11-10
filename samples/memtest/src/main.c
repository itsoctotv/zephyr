/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdint.h>

void memWrite();
void memDump();

/*

TODO:
fill the PSRAM 512KB (struct bit array)

Random locations with pointer and counter that counts lineary and fills the specific memory address

maybe:
- https://barrgroup.com/embedded-systems/how-to/memory-test-suite-c


*/



int main(){

	printf("Writing mem\n\n");
	memWrite();
	printf("Reading it\n\n");
	memDump();

	return 0;
}
void memWrite(){
 //0x60000000 0x60080000
	//uint32_t val = *(volatile uint32_t *)mem_addr;
	uint8_t i = 0x01;
	for(uint32_t begin = 0x60000000; begin < 0x60000050; begin += 0x00000001){
		volatile uint32_t *ptr = (uint32_t *)begin;
		*ptr = i;
		i += 0x01;
	}
}

void memDump(){
	for(uint32_t addresscount = 0x60000000; addresscount < 0x60000050; 
					addresscount = addresscount + 0x00000001){

		volatile char *ptr = (char *)addresscount;
		printf("%p  ",ptr);	//address
		
		for(char valuecounter = 0x00; valuecounter < 0x08; valuecounter += 0x01){
			//volatile char *ptr2 = (char *)begin;

			printf("%2x  ", *ptr);	
			
		}
		printf("\n");
		
		
	}
}
