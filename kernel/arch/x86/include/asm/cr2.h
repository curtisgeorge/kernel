#pragma once

#include <stdint.h>

/*
 * CR2 is an x86 control register.  It holds the faulting address
 * if a pauge fault occurs.  This provides and inline assembly
 * method to get the value out of cr2.
 */

static inline void get_cr2() {
  uint32_t cr2;
  asm volatile ("mov %%cr2 %0" : "=r"(cr2));
  return cr2;
}
