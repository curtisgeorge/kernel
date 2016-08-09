#pragma once

#include <stdint.h>

/*
 * CR3 is an x86 control register.  CR3 holds the address of the page directory
 * when paging is enabled in CR0.
 */

static inline uint32_t get_cr3() {
  uint32_t cr3;
  asm volatile ("movl %%cr3, %0" : "=r"(cr3));
  return cr3;
}

static inline void set_cr3(uint32_t cr3) {
  asm volatile ("movl %0, %%cr3" : : "r"(cr3));
}
