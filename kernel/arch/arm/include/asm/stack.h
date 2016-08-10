#pragma once

static inline void set_irq_stack() {
  asm volatile("ldr sp, =irq_stack_top");
}

static inline void set_abort_stack() {
  asm volatile("ldr sp, =abort_stack_top");
}
