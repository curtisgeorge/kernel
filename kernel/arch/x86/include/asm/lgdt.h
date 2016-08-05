#ifndef ASM_LGDT_H
#define ASM_LGDT_H

#include <gdt.h>

/**
 * Inline function to load the gdt register
 */
static inline void lgdt(const gdt_ptr_t* gdt_ptr) {
  asm volatile ("lgdt %0" : : "m"(*gdt_ptr));
}

#endif
