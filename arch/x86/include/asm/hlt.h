#ifndef ASM_HLT_H
#define ASM_HLT_H

/**
 * Inline function to execute hlt instruction (halt)
 */
static inline void hlt() {
  asm volatile("hlt");
}

#endif
