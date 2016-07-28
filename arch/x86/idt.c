#include "idt.h"
#include <printk.h>

struct idt_entry_t idt[256];
const struct idt_ptr_t idt_ptr = {
                                   .limit = (sizeof(struct idt_entry_t) * 256) - 1,
                                   .base  = (unsigned int) &idt
                                 };

void init_idt() {
  int i;
  unsigned int* idt_addr = (unsigned int*) idt;
  for(i = 0; i < 256 * 2; i++) {
    idt_addr[i] = 0;
  }

  asm volatile ("lidt %0" : : "m" (idt_ptr));
}
