#pragma once

static inline void copy_interrupt_table() {
  asm volatile ("mov r0, #0x0\n \
                 ldr r1, =interrupt_table_start\n \
                 ldr r3, =interrupt_table_end\n \
                 copy_loop_start:\n \
                 ldr r2, [r1, #0x0]\n \
                 str r2, [r0, #0x0]\n \
                 add r0, r0, #0x4\n \
                 add r1, r1, #0x4\n \
                 cmp r1, r3\n \
                 bne copy_loop_start");
}

static inline void enable_irq() {
#if __ARM_ARCH >= 6
  asm volatile ("cpsie i");
#else
  asm volatile ("mrs r1, cpsr\n \
                 bic r1, r1, #0x80\n \
                 msr cpsr_c, r1");
#endif
}

static inline void disable_irq() {
#if __ARM_ARCH >= 6
  asm volatile ("cpsid i");
#else
  asm volatile ("mrs r1, cpsr\n \
                 orr r1, r1, #0x80\n \
                 msr cpsr_c, r1");
#endif
}

static inline void enable_fiq() {
#if __ARM_ARCH >= 6
  asm volatile ("cpsie f");
#else
  asm volatile ("mrs r1, cpsr\n \
                 bic r1, r1, #0x40\n \
                 msr cpsr_c, r1");
#endif
}

static inline void disable_fiq() {
#if __ARM_ARCH >= 6
  asm volatile ("cpsid f");
#else
  asm volatile ("mrs r1, cpsr\n \
                 orr r1, r1, #0x40\n \
                 msr cpsr_c, r1");
#endif
}

static inline void enable_irq_and_fiq() {
#if __ARM_ARCH >= 6
  asm volatile ("cpsie if");
#else
  asm volatile ("mrs r1, cpsr\n \
                 bic r1, r1, #0xC0\n \
                 msr cpsr_c, r1");
#endif
}

static inline void disable_irq_and_fiq() {
#if __ARM_ARCH >= 6
  asm volatile ("cpsid if");
#else
  asm volatile ("mrs r1, cpsr\n \
                 orr r1, r1, #0xC0\n \
                 msr cpsr_c, r1");
#endif
}
