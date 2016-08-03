#ifndef ASM_STI_H
#define ASM_STI_H

/**
 * Inline function to execute sti instruction (enable interrupts)
 */
static inline void sti() {
  asm volatile("sti");
}

#endif
