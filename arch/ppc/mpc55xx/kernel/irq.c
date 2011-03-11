
/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

/* ----------------------------[includes]------------------------------------*/
/* ----------------------------[private define]------------------------------*/
/* ----------------------------[private macro]-------------------------------*/
/* ----------------------------[private typedef]-----------------------------*/
/* ----------------------------[private function prototypes]-----------------*/
/* ----------------------------[private variables]---------------------------*/
/* ----------------------------[private functions]---------------------------*/
/* ----------------------------[public functions]----------------------------*/


/* ----------------------------[includes]------------------------------------*/

#include "internal.h"
#include "irq_types.h"
#include "mpc55xx.h"
#include "pcb.h"
#include "sys.h"
#include "internal.h"
#include "task_i.h"
#include "hooks.h"
#include "debug.h"
#include "isr.h"
#include <stdint.h>

/* ----------------------------[private define]------------------------------*/
/* ----------------------------[private macro]-------------------------------*/
/* ----------------------------[private typedef]-----------------------------*/
typedef void (*f_t)( uint32_t *);

/* ----------------------------[private function prototypes]-----------------*/
//extern uintptr_t Irq_VectorTable[NUMBER_OF_INTERRUPTS_AND_EXCEPTIONS];
//extern uint8 Irq_IsrTypeTable[NUMBER_OF_INTERRUPTS_AND_EXCEPTIONS];
//extern const OsIsrConstType *Irq_Map[NUMBER_OF_INTERRUPTS_AND_EXCEPTIONS];

static void dumpExceptionRegs( uint32_t *regs );

/* ----------------------------[private variables]---------------------------*/
extern void exception_tbl(void);

/* ----------------------------[private functions]---------------------------*/
/* ----------------------------[public functions]----------------------------*/

// write 0 to pop INTC stack
void Irq_Init( void ) {
	  // Check alignment for the exception table
	  assert(((uint32)exception_tbl & 0xfff)==0);
	  set_spr(SPR_IVPR,(uint32)exception_tbl);

	  ramlog_str("Test\n");
	  ramlog_hex(0x10);
	  ramlog_dec(20);

	  // TODO: The 5516 simulator still thinks it's a 5554 so setup the rest
#if (defined(CFG_SIMULATOR) && defined(CFG_MPC5516)) || defined(CFG_MPC5567) || defined(CFG_MPC5554)
	    set_spr(SPR_IVOR0,((uint32_t)&exception_tbl+0x0) );
	    set_spr(SPR_IVOR1,((uint32_t)&exception_tbl+0x10) );
	    set_spr(SPR_IVOR2,((uint32_t)&exception_tbl+0x20) );
	    set_spr(SPR_IVOR3,((uint32_t)&exception_tbl+0x30) );
	    set_spr(SPR_IVOR4,((uint32_t)&exception_tbl+0x40) );
	    set_spr(SPR_IVOR5,((uint32_t)&exception_tbl+0x50) );
	    set_spr(SPR_IVOR6,((uint32_t)&exception_tbl+0x60) );
	    set_spr(SPR_IVOR7,((uint32_t)&exception_tbl+0x70) );
	    set_spr(SPR_IVOR8,((uint32_t)&exception_tbl+0x80) );
	    set_spr(SPR_IVOR9,((uint32_t)&exception_tbl+0x90) );
	    set_spr(SPR_IVOR10,((uint32_t)&exception_tbl+0xa0) );
	    set_spr(SPR_IVOR11,((uint32_t)&exception_tbl+0xb0) );
	    set_spr(SPR_IVOR12,((uint32_t)&exception_tbl+0xc0) );
	    set_spr(SPR_IVOR13,((uint32_t)&exception_tbl+0xd0) );
	    set_spr(SPR_IVOR14,((uint32_t)&exception_tbl+0xe0) );
#if defined(CFG_SPE)
	    // SPE exceptions...map to dummy
	    set_spr(SPR_IVOR32,((uint32_t)&exception_tbl+0xf0) );
	    set_spr(SPR_IVOR33,((uint32_t)&exception_tbl+0xf0) );
	    set_spr(SPR_IVOR34,((uint32_t)&exception_tbl+0xf0) );
#endif
#endif

	  //
	  // Setup INTC
	  //
	  // according to manual
	  //
	  // 1. configure VTES_PRC0,VTES_PRC1,HVEN_PRC0 and HVEN_PRC1 in INTC_MCR
	  // 2. configure VTBA_PRCx in INTC_IACKR_PRCx
	  // 3. raise the PRIx fields and set the PRC_SELx fields to the desired processor in INTC_PSRx_x
	  // 4. set the enable bits or clear the mask bits for the peripheral interrupt requests
	  // 5. lower PRI in INTC_CPR_PRCx to zero
	  // 6. enable processor(s) recognition of interrupts

	  // Z1 init

	#if defined(CFG_MPC5516)
	  INTC.MCR.B.HVEN_PRC0 = 0; // Soft vector mode
	  INTC.MCR.B.VTES_PRC0 = 0; // 4 byte offset between entries
	#elif defined(CFG_MPC5554) || defined(CFG_MPC5567)
	  INTC.MCR.B.HVEN = 0; // Soft vector mode
	  INTC.MCR.B.VTES = 0; // 4 byte offset between entries
	#endif

	  // Pop the FIFO queue
	  for (int i = 0; i < 15; i++)
	  {
	#if defined(CFG_MPC5516)
	    INTC.EOIR_PRC0.R = 0;
	#elif defined(CFG_MPC5554) || defined(CFG_MPC5567)
	    INTC.EOIR.R = 0;
	#endif
	  }

	  // Accept interrupts
	#if defined(CFG_MPC5516)
	  INTC.CPR_PRC0.B.PRI = 0;
	#elif defined(CFG_MPC5554) || defined(CFG_MPC5567)
	  INTC.CPR.B.PRI = 0;
	#endif
}

void Irq_EOI( void ) {
#if defined(CFG_MPC5516)
	volatile struct INTC_tag *intc = &INTC;
	intc->EOIR_PRC0.R = 0;
#elif defined(CFG_MPC5554)||defined(CFG_MPC5567)
	volatile struct INTC_tag *intc = &INTC;
	intc->EOIR.R = 0;
#endif
}

#if 0
/**
 *
 * @param stack_p Ptr to the current stack.
 *
 * The stack holds C, NVGPR, VGPR and the EXC frame.
 *
 */
void *Irq_Entry( void *stack_p )
{
	uint32_t vector;
	uint32_t *stack = (uint32_t *)stack_p;
	uint32_t exc_vector = (EXC_OFF_FROM_BOTTOM+EXC_VECTOR_OFF)  / sizeof(uint32_t);
	const OsIsrConstType *isr;

	// Check for exception
	if( stack[exc_vector]>=CRITICAL_INPUT_EXCEPTION )
	{
		vector = stack[exc_vector];
	}
	else
	{
#if defined(CFG_MPC5516)
		struct INTC_tag *intc = &INTC;
		vector = (intc->IACKR_PRC0.B.INTVEC_PRC0);
#elif defined(CFG_MPC5554)||defined(CFG_MPC5567)
		volatile struct INTC_tag *intc = &INTC;
		vector = (intc->IACKR.B.INTVEC);
#endif
		// save the vector for later
		stack[exc_vector] = vector;

		// Check for software interrupt
		if((uint32_t)vector<=INTC_SSCIR0_CLR7)
		{
			// Clear soft int
			intc->SSCIR[vector].B.CLR = 1;
			asm("mbar 0");
		}
	}

	isr = Os_IsrGet(exc_vector);
	if( isr->type == ISR_TYPE_1 ) {
		isr->entry();
		return stack;
	} else {
		return Os_Isr(stack, vector);
	}
}
#endif


static inline int osPrioToCpuPio( uint8_t prio ) {
	assert(prio<32);
	return prio>>1;		// Os have 32 -> 16
}

void Irq_SetPriority( Cpu_t cpu,  IrqType vector, uint8_t prio ) {
#if defined(CFG_MPC5516)
	INTC.PSR[vector].B.PRC_SEL = cpu;
#endif
	INTC.PSR[vector].B.PRI = prio;
}



#if 0
/**
 * Attach an ISR type 1 to the interrupt controller.
 *
 * @param entry
 * @param int_ctrl
 * @param vector
 * @param prio
 */
void Irq_AttachIsr1( void (*entry)(void), void *int_ctrl, uint32_t vector,uint8_t prio) {
	Irq_VectorTable[vector] = (void *)entry;
	Irq_SetIsrType(vector, ISR_TYPE_1);

	if (vector < INTC_NUMBER_OF_INTERRUPTS) {
		Irq_SetPriority(CPU_CORE0,vector + IRQ_INTERRUPT_OFFSET, osPrioToCpuPio(prio));
	} else if ((vector >= CRITICAL_INPUT_EXCEPTION) && (vector
			<= DEBUG_EXCEPTION)) {
	} else {
		/* Invalid vector! */
		assert(0);
	}

}
#endif


void Irq_EnableVector( int16_t vector, int priority, int core ) {

	if (vector < INTC_NUMBER_OF_INTERRUPTS) {
		Irq_SetPriority(core,vector + IRQ_INTERRUPT_OFFSET, osPrioToCpuPio(priority));
	} else if ((vector >= CRITICAL_INPUT_EXCEPTION)
			&& (vector<= DEBUG_EXCEPTION)) {
	} else {
		/* Invalid vector! */
		assert(0);
	}
}



#if 0

/**
 *
 * @param isrPtr
 * @param type
 * @param int_ctrl
 */
ISRType Irq_Attach( int vector ) {
//	Os_Sys.isrCnt
//	uint32_t vector = isrPtr->vector;

	//Irq_VectorTable[vector] = (uintptr_t)isrPtr;
//	Irq_IsrTypeTable[vector] = type;
//	Irq_VectorTable[vector] = isrPtr;


	if (vector < INTC_NUMBER_OF_INTERRUPTS) {
		Irq_SetPriority(Irq_Map[vector]->core ,vector + IRQ_INTERRUPT_OFFSET, osPrioToCpuPio(Irq_Map[vector]->priority));
	} else if ((vector >= CRITICAL_INPUT_EXCEPTION)
			&& (vector<= DEBUG_EXCEPTION)) {
	} else {
		/* Invalid vector! */
		assert(0);
	}


	return;
}
#endif

#if 0
/**
 * Attach a ISR type 2 to the interrupt controller.
 *
 * @param tid
 * @param int_ctrl
 * @param vector
 */
void Irq_AttachIsr2(TaskType tid,void *int_ctrl,IrqType vector ) {
	OsTaskVarType *pcb;

	pcb = Os_TaskGet(tid);
	Irq_VectorTable[vector] = (void *)pcb;
	Irq_IsrTypeTable[vector] = PROC_ISR2;

	if (vector < INTC_NUMBER_OF_INTERRUPTS) {
		Irq_SetPriority(CPU_CORE0,vector + IRQ_INTERRUPT_OFFSET, osPrioToCpuPio(pcb->prio));
	} else if ((vector >= CRITICAL_INPUT_EXCEPTION) && (vector
			<= DEBUG_EXCEPTION)) {
	} else {
		/* Invalid vector! */
		assert(0);
	}
}
#endif


/**
 * Generates a soft interrupt
 * @param vector
 */
void Irq_GenerateSoftInt( IrqType vector ) {
	if( vector > INTC_SSCIR0_CLR7 ) {
		assert(0);
	}

	INTC.SSCIR[vector].B.SET = 1;
}

/**
 * Get the current priority from the interrupt controller.
 * @param cpu
 * @return
 */
uint8_t Irq_GetCurrentPriority( Cpu_t cpu) {

	uint8_t prio = 0;

#if defined(CFG_MPC5516)
	if( cpu == CPU_Z1 ) {
		prio = INTC.CPR_PRC0.B.PRI;
	} else if ( cpu == CPU_Z0 ) {
		prio = INTC.CPR_PRC1.B.PRI;
	}
#elif defined(CFG_MPC5554)||defined(CFG_MPC5567)
	prio = INTC.CPR.B.PRI;
#endif

	return prio;
}



void dummy (void);

// Critical Input Interrupt
void IVOR0Exception (uint32_t *regs)
{
//	srr0 = get_spr(SPR_SRR0);
//	srr1 = get_spr(SPR_SRR0);
//	ExceptionSave(srr0,srr1,esr,mcsr,dear;)
	// CSRR0, CSSR1
	// Nothing more
	dumpExceptionRegs(regs);
	while (1);
}

// Machine check
void IVOR1Exception (uint32_t *regs)
{
	// CSRR0, CSSR1
	// MCSR - Source of machine check
	dumpExceptionRegs(regs);
   while (1);
}
// Data Storage Interrupt
void IVOR2Exception (uint32_t *regs)
{
	// SRR0, SRR1
	// ESR - lots of stuff
	dumpExceptionRegs(regs);
   while (1);
}

// Instruction Storage Interrupt
void IVOR3Exception (uint32_t *regs)
{
	// SRR0, SRR1
	// ESR - lots of stuff
	dumpExceptionRegs(regs);
   while (1);
}

// Alignment Interrupt
void IVOR5Exception (uint32_t *regs)
{
	// SRR0, SRR1
	// ESR - lots of stuff
	// DEAR - Address of load store that caused the exception
	dumpExceptionRegs(regs);
   while (1);
}

// Program Interrupt
void IVOR6Exception (uint32_t *regs)
{
	// SRR0, SRR1
	// ESR - lots of stuff
	dumpExceptionRegs(regs);
	while (1);
}

// Floating point unavailable
void IVOR7Exception (uint32_t *regs)
{
	// SRR0, SRR1
	dumpExceptionRegs(regs);
   while (1);
}

// System call
void IVOR8Exception (uint32_t *regs)
{
	// SRR0, SRR1
	// ESR
	dumpExceptionRegs(regs);
	while (1);
}

// Aux processor Unavailable
void IVOR9Exception (uint32_t *regs)
{
	// Does not happen on e200
	dumpExceptionRegs(regs);
	while (1);
}
#if 0
// Decrementer
void IVOR10Exception (uint32_t *regs)
{
	// SRR0, SRR1
	while (1);
}
#endif

// FIT
void IVOR11Exception (uint32_t *regs)
{
	// SRR0, SRR1
	dumpExceptionRegs(regs);
	while (1);
}

// Watchdog Timer
void IVOR12Exception (uint32_t *regs)
{
	// SRR0, SRR1
	dumpExceptionRegs(regs);
	while (1);
}

// Data TLB Error Interrupt
void IVOR13Exception (uint32_t *regs)
{

	// SRR0, SRR1
	// ESR - lots
	// DEAR -
	while (1);
}

// Instruction TLB Error Interupt
void IVOR14Exception (uint32_t *regs)
{
	// SRR0, SRR1
	// ESR - MIF set, All others cleared
	dumpExceptionRegs(regs);
	while (1);
}

void IVOR15Exception (uint32_t *regs)
{
	// Debug
	dumpExceptionRegs(regs);
	while (1);
}

#if defined(CFG_CONSOLE_T32) || defined(CFG_CONSOLE_WINIDEA)

typedef struct {
	uint32_t sp;
	uint32_t bc;  // backchain
	uint32_t pad;
	uint32_t srr0;
	uint32_t srr1;
	uint32_t lr;
	uint32_t ctr;
	uint32_t xer;
	uint32_t cr;
	uint32_t esr;
	uint32_t mcsr;
	uint32_t dear;
	uint32_t vector;
	uint32_t r3;
	uint32_t r4;
} exc_stack_t;



static void dumpExceptionRegs( uint32_t *regs ) {
	exc_stack_t *r = (exc_stack_t *)regs;

	LDEBUG_PRINTF("sp   %08x  srr0 %08x  srr1 %08x\n",r->sp,r->srr0,r->srr1);
	LDEBUG_PRINTF("lr   %08x  ctr  %08x  xer  %08x\n",r->lr,r->ctr,r->xer);
	LDEBUG_PRINTF("cr   %08x  esr  %08x  mcsr %08x\n",r->cr,r->esr,r->mcsr);
	LDEBUG_PRINTF("dear %08x  vec  %08x  r3   %08x\n",r->dear,r->vector,r->r3);
	LDEBUG_PRINTF("r4   %08x\n",r->r4);
}

#else
static void dumpExceptionRegs( uint32_t *regs ) {
}
#endif

