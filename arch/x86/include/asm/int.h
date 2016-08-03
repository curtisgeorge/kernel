#ifndef ASM_INT_H
#define ASM_INT_H

#include <stdint.h>

static inline void interrupt(uint32_t int_num) {
  asm volatile("int %0" : : "N"(int_num));
}

#endif
