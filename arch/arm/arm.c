#include "interrupt.h"
#include "clcd.h"

void init_arch() {
  init_clcd();
  init_interrupts();
}
