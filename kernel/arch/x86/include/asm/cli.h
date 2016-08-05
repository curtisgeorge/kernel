#ifndef ASM_CLI_H
#define ASM_CLI_H

/**
 * Inline function to execute cli instruction (disable interrupts)
 */
static inline void cli() {
  asm volatile("cli");
}

#endif
