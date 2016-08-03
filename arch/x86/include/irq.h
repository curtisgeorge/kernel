#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

typedef struct {
  uint32_t gs, fs, es, ds;
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32_t int_no, err_code;
  uint32_t eip, cs, eflags, useresp, ss;
} regs;

void remap_irqs();

#endif
