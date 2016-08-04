#include <stdint.h>

volatile uint32_t* PIC = (uint32_t*) 0x10140000;

void enable_irq_line(uint32_t irq) {
  PIC[0x04] = (1 << irq);
}

uint32_t get_status() {
  return PIC[0x0];
}
