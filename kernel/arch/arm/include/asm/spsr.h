#pragma once

#include <stdint.h>

static inline uint32_t get_spsr() {
  uint32_t spsr;
  asm volatile ("mrs %0, spsr" : "=r"(ret));
  return spsr;
}

static inline void set_spsr(uint32_t spsr) {
  asm volatile ("msr spsr, %0" :  : "r"(spsr));
}
