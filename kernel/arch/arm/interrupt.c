#include <printk.h>
#include "asm.h"
#include "pic.h"
#include "timer.h"
#include "uart0.h"

void init_interrupts() {
  copy_interrupt_table();
  asm volatile("cps #0x12");
  asm volatile("ldr sp, =irq_stack_top");
  asm volatile("cps #0x17");
  asm volatile("ldr sp, =abort_stack_top");
  asm volatile("cps #0x13");
}

void __attribute__((interrupt("ABORT"))) handle_abort() {
  printk("Abort");
  while(1) {}
}

void __attribute__((interrupt("SWI"))) handle_syscall() {
  uint32_t int_no;
  asm volatile("ldr %0, [lr, #-4]" : "=r"(int_no));
  int_no &= 0x00FFFFFF;
  if(int_no == 0x80) {
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
