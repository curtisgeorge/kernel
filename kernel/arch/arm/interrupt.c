#include <printk.h>
#include "pic.h"
#include "timer.h"
#include "uart0.h"
#include <asm/copy_interrupt_table.h>
#include <asm/cpsr.h>
#include <asm/stack.h>
#include <asm/swi.h>
#include <syscall_handler.h>

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

void __attribute__((interrupt("SWI"))) swi_handler() {
  register uint32_t r0 asm("r0");
  register uint32_t r1 asm("r1");
  register uint32_t r2 asm("r2");
  register uint32_t r3 asm("r3");
  uint32_t swi_no = get_swi_no();
  if(swi_no == 0x80) {
    syscall_handler(r0, r1, r2, r3);
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
