#pragma once

#include <stdint.h>
#include "idt.h"

static inline void reset_segment_regs() {
  uint32_t val = 0x10;
  asm volatile("movl %0, %%ds\n"
               "movl %0, %%es\n"
               "movl %0, %%fs\n"
               "movl %0, %%gs\n"
               "movl %0, %%ss\n"
               "ljmp $(0x08), $1f\n"
               "1:" : : "r"(val));
}

static inline void outb(uint16_t port, uint8_t val)
{
  asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}


static inline uint8_t inb(uint16_t port)
{
  uint8_t ret;
  asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
  return ret;
}

static inline void enable_pse() {
  asm volatile ("mov %%cr4, %%ecx\n \
                 or $0x00000010, %%ecx\n \
                 mov %%ecx, %%cr4" : : :  "%ecx" );
}
