#include <printk.h>
#include "pic.h"
#include "timer.h"
#include "uart0.h"
#include <asm/copy_interrupt_table.h>
#include <asm/cpsr.h>
#include <asm/stack.h>
#include <asm/swi.h>

void init_interrupts() {
  copy_interrupt_table();
  set_mode(MODE_IRQ);
  set_irq_stack();
  set_mode(MODE_ABT);
  set_abort_stack();
  set_mode(MODE_SVC);
}

void __attribute__((interrupt("ABORT"))) handle_abort() {
  printk("Abort");
  while(1) {}
}

void __attribute__((interrupt("SWI"))) handle_syscall() {
  uint32_t swi_no = get_swi_no();
  if(swi_no == 0x80) {
    register uint32_t syscall_no asm("r0");
    if(syscall_no == 0x4) {
      register const char* s asm("r1");
      printk(s);
    }
  }
  else {
    printk("Unknown SWI");
  }
}

struct regs {
  uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr;
};

void dispatch_interrupts(struct regs* r) {
  uint32_t status = get_status();
  if(status & (1u << 5)) {
    //printk("tick");
    timer_clear_interrupt();
  }
  else if(status & (1u << 12)) {
    char str[2];
    str[0] = uart0_receive();
    str[1] = '\0';
    printk(str);
  }
  else {
    printk("Unknown interrupt");
    while(1) {}
  }
}
