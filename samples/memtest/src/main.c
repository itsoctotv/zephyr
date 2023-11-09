/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdint.h>



static inline void writeMem_32(uint32_t data, uintptr_t mem_addr);
static inline uint32_t readMem_32(uint32_t mem_addr);



int main(void)
{
	printf("Booted.\n\n");

	printf("Read Val: 0x%x\n", readMem_32(0x60000000));

	writeMem_32(0x12345678, 0x60000000);
	printf("Wrote: 0x%x to: 0x%x\n",0x12345678,0x60000000);

	printf("Read val: 0x%x\n", readMem_32(0x60000000));
	
	return 0;
}

static inline void writeMem_32(uint32_t data, uintptr_t mem_addr){

	*(volatile uint32_t *)mem_addr = data;
	
}

static inline uint32_t readMem_32(uint32_t mem_addr){

	uint32_t val;
	val = *(volatile uint32_t *)mem_addr;
	return val;
}

