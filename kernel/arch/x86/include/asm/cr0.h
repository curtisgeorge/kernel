#pragma once

#include <stdint.h>

/* 
 * CR0 is an x86 control register. CR0 has various control flags that modify the basic operation of the processor.
 * This provides some inline functions to use that register.  The flags for CR0 are defined below.
 *
 * Bit Name Full Name            Description
 * 0   PE   Protected Mode       Enable If 1, system is in protected mode, else system is in real mode
 * 1   MP   Monitor co-processor Controls interaction of WAIT/FWAIT instructions with TS flag in CR0
 * 2   EM   Emulation            If set, no x87 floating point unit present, if clear, x87 FPU present
 * 3   TS   Task switched        Allows saving x87 task context upon a task switch only after x87 instruction used
 * 4   ET   Extension type       On the 386, it allowed to specify whether the external math coprocessor was an 80287 or 80387
 * 5   NE   Numeric error        Enable internal x87 floating point error reporting when set, else enables PC style x87 error detection
 * 16  WP   Write protect        When set, the CPU can't write to read-only pages when privilege level is 0
 * 18  AM   Alignment mask       Alignment check enabled if AM set, AC flag (in EFLAGS register) set, and privilege level is 3
 * 29  NW   Not-write through    Globally enables/disable write-through caching
 * 30  CD   Cache disable        Globally enables/disable the memory cache
 * 31  PG   Paging               If 1, enable paging and use the CR3 register, else disable paging
 */
enum CR0_FLAGS { PE = 0x1, MP = 0x2, EM = 0x4, TS = 0x8, ET = 0x10, NE = 0x20, WP = 0x10000, AM = 0x40000, NW = 0x20000000, CD = 0x40000000, PG = 0x80000000 };

static inline uint32_t get_cr0() {
  uint32_t cr0;
  asm volatile ("movl %%cr0, %0" : "=r"(cr0));
  return cr0;
}

static inline void set_cr0(uint32_t cr0) {
  asm volatile ("movl %0, %%cr0" : : "r"(cr0));
}

static inline void set_cr0_flags(uint32_t flags) {
  set_cr0(get_cr0() | flags);
}

static inline void clear_cr0_flags(uint32_t flags) {
  set_cr0(get_cr0() & ~flags);
}
