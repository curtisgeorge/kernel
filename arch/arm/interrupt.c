#include <printk.h>
#include "asm.h"

void init_interrupts() {
  copy_interrupt_table();
}

void __attribute__((interrupt("SWI"))) handle_syscall() {
  const char* s;
  asm volatile("mov %0, r1" : "=r"(s));
  printk(s);
}

void __attribute__((interrupt("IRQ"))) dispatch_interrupts() {
  printk("Unknown interrupt");
}
