#include <stdint.h>
#include "idt.h"
#include "asm.h"

struct idt_entry_t idt[256];
const struct idt_ptr_t idt_ptr = {
                                   .limit = (sizeof(struct idt_entry_t) * 256) - 1,
                                   .base  = (uint32_t) &idt
                                 };

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
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
  uint32_t* idt_addr = (uint32_t*) idt;
  for(i = 0; i < 256 * 2; i++) {
    idt_addr[i] = 0;
  }

  lidt(&idt_ptr);
}
