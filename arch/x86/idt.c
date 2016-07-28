#include "idt.h"

struct idt_entry_t idt[256];
const struct idt_ptr_t idt_ptr = {
                                   .limit = (sizeof(struct idt_entry_t) * 256) - 1,
                                   .base  = (unsigned int) &idt
                                 };

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
	/* Assign the base values */
	idt[num].base_lo = (base & 0xFFFF);
	idt[num].base_hi = (base >> 16) & 0xFFFF;

	/* Set the other fields */
	idt[num].sel = sel;
	idt[num].always0 = 0;
	idt[num].flags = flags;
}

void init_idt() {
  int i;
  unsigned int* idt_addr = (unsigned int*) idt;
  for(i = 0; i < 256 * 2; i++) {
    idt_addr[i] = 0;
  }

  asm volatile ("lidt %0" : : "m" (idt_ptr));
}
