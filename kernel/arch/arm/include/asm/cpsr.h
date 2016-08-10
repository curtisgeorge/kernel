#pragma once

#include <stdint.h>

/*
 * The CPSR is ARM Current Program Status Register.  It sets the current
 * operating mode, and enables / disables IRQs and FIQs.
 * These are inline functions to use the CPSR register.
 */
enum CPSR_MODES { MODE_USR = 0x10, MODE_FIQ = 0x11, MODE_IRQ = 0x12, MODE_SVC = 0x13, MODE_ABT = 0x17, MODE_UND = 0x1B, MODE_SYS = 0x1F };

static inline uint32_t get_cpsr() {
  uint32_t cpsr;
  asm volatile ("mrs %0, cpsr" : "=r"(cpsr));
  return cpsr;
}

static inline void set_cpsr(uint32_t cpsr) {
  asm volatile ("msr cpsr, %0" : : "r"(cpsr));
}

static inline void set_mode(uint32_t mode) {
  set_cpsr((get_cpsr() & 0xFFFFFFE0) | mode);
}

static inline void enable_irq() {
#if __ARM_ARCH >= 6
  // ARM 6 and newer has a single instruction way of enabling IRQs
  asm volatile ("cpsie i");
#else
  // Otherwise we have to do it this way, which takes 3 instructions
  set_cpsr(get_cpsr() & 0xFFFFFF7F);
#endif
}
