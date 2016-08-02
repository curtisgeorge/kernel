#include <printk.h>
#include "asm.h"

void init_interrupts() {
  copy_interrupt_table();
}

void handle_syscall() {
  printk("syscall");
}

void dispatch_interrupts() {
  printk("Unknown interrupt");
}
