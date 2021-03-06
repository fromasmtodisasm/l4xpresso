/*
L4Xpresso
Copyright (c) 2011, Sergey Klyaus

File: /leo4-mcu/kernel/include/platform/armv7m.h
Author: myaut

@LICENSE
*/

#ifndef ARMV7M_H_
#define ARMV7M_H_

#include <types.h>
#include <platform/link.h>

__INLINE void wait_for_interrupt() {
	__ASM volatile ("wfi");
}

__INLINE uint32_t read_msp() {
	uint32_t result;

	__ASM volatile ("mrs r0, msp\n"
					"mov %0, r0"
					: "=r"(result)
					:
					: "r0");

	return result;
}

enum register_stack_t {
	/*Saved by hardware*/
	REG_R0,
	REG_R1,
	REG_R2,
	REG_R3,
	REG_R12,
	REG_LR,
	REG_PC,
	REG_xPSR
};

#define RESERVED_STACK		8 * sizeof(uint32_t)

#endif /* ARMV7M_H_ */
