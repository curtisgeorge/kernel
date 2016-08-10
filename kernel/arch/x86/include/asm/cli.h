#pragma once

/**
 * Inline function to execute cli instruction (disable interrupts)
 */
static inline void cli() {
  asm volatile("cli");
}
