#pragma once

#include <stdint.h>

static inline uint32_t get_swi_no() {
  uint32_t swi_no;
  asm volatile("ldr %0, [lr, #-4]" : "=r"(swi_no));
  return (swi_no & 0x00FFFFFF);
}
