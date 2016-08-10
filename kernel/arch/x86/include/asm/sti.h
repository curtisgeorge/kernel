#pragma once

/**
 * Inline function to execute sti instruction (enable interrupts)
 */
static inline void sti() {
  asm volatile("sti");
}
