/* 
 * REDUCE VIRTUAL MACHINE 
 *
 * MIPS64-like ISA
 * no 32 bit mode
 *
 */


#ifndef __VM_H__
#define __VM_H__

#include "vmmem.h"

/*
 * memory layout
 *
 * kuseg 0xFFFF FFFF 8000 0000
 * kseg0 0xFFFF FFFF A000 0000
 * kseg1 0xFFFF FFFF C000 0000
 * kseg2 0xFFFF FFFF FFFF FFFF
 *
 */

typedef struct vm_t 
{
	uint64_t pc;		/* program count			*/
	uint64_t gpr[32];	/* 64 bit general purpose use register 	*/
	uint64_t fpr[32];	/* 64 bit float register 		*/
	uint64_t cpr[32];	/* 64 bit co-processor register 	*/

	vm_mem_t *kuseg;	/* cached and mapped 			*/
	vm_mem_t *kseg0;	/* cacned and not mapped 		*/
	vm_mem_t *kseg1;	/* not cached and not mapped 		*/
	vm_mem_t *kseg2;	/* cached and mapped			*/
} vm_t;

vm_t *
vm_create();

void
vm_step();

void
vm_t *
vm_destroy();


#endif /* __VM_H__ */

