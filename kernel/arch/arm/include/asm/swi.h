#pragma once

#include <stdint.h>

/*
 * In order to get the argument of the swi instruction
 * we have to check the link register minus 4.
 * The value stored there is the full swi instruction,
 * we can get the argument by masking off the top byte.
 */
static inline uint32_t get_swi_no() {
  uint32_t swi_no;
  asm volatile("ldr %0, [lr, #-4]" : "=r"(swi_no));
  return (swi_no & 0x00FFFFFF);
}
