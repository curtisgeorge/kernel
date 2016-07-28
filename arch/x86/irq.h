#ifndef IRQ_H
#define IRQ_H

struct regs
{
	unsigned int ds;					/* data segment selector */
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;	/* pushed by 'pusha' */
	unsigned int int_no, err_code;				/* our 'push byte #' and ecodes do this */
	unsigned int eip, cs, eflags, useresp, ss;              /* pushed by the processor automatically */
};

void remap_irqs();

#endif
