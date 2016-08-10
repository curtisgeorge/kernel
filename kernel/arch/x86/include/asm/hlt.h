#pragma once

/**
 * Inline function to execute hlt instruction (halt)
 */
static inline void hlt() {
  asm volatile("hlt");
}
