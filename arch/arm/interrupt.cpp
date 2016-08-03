#include <printk.h>
#include "asm.h"

void init_interrupts() {
  copy_interrupt_table();
}

extern "C"
void handle_syscall() {
  printk("syscall");
}

extern "C"
void dispatch_interrupts() {
}
