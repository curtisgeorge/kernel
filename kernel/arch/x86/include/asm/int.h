#ifndef ASM_INT_H
#define ASM_INT_H

#include <stdint.h>

/**
 * Inline functon that executes an interrupt
 */
static inline void interrupt(uint16_t int_num) {
  asm volatile("int %0" : : "N"(int_num));
}

#endif
