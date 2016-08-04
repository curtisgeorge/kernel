#include "interrupt.h"
#include "uart0.h"
#include "clcd.h"
#include "timer.h"
#include "paging.h"
#include "asm.h"

void init_arch() {
  uart0_init();
  init_clcd();
  init_interrupts();
  init_timer();
  init_paging();
  enable_irq();
}
