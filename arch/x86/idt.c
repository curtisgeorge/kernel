#include <stdint.h>
#include <idt.h>
#include <asm/lidt.h>
#include <asm.h>

idt_entry_t idt[256];
const idt_ptr_t idt_ptr = {
                            .limit = (sizeof(idt_entry_t) * 256) - 1,
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
  uint64_t* idt_addr = (uint64_t*) idt;
  for(i = 0; i < 256; i++) {
    idt_addr[i] = 0;
  }

  lidt(&idt_ptr);
}
