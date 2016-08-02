#ifndef ASM_H
#define ASM_H

#include <stdint.h>
#include "gdt.h"
#include "idt.h"

static inline void sti() {
  asm volatile ( "sti" );
}

static inline void cli() {
  asm volatile ( "cli" );
}

static inline void hlt() {
  asm volatile ( "hlt" );
}

static inline void lgdt(const gdt_ptr_t* gdt_ptr) {
  asm volatile ( "lgdt %0" : : "m" (*gdt_ptr) );
}

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

static inline void lidt(const idt_ptr_t* idt_ptr) {
  asm volatile ( "lidt %0" : : "m" (*idt_ptr) );
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

static inline void load_page_dir(uint32_t page_dir) {
  asm volatile ("mov %0, %%cr3" : : "r"(page_dir));
}

static inline void enable_pse() {
  asm volatile ("mov %%cr4, %%ecx\n \
                 or $0x00000010, %%ecx\n \
                 mov %%ecx, %%cr4" : : :  "%ecx" );
}

static inline uint32_t get_cr0() {
  uint32_t cr0;
  asm volatile ("mov %%cr0, %0" : "=r"(cr0));
  return cr0;
}

static inline void set_cr0(uint32_t cr0) {
  asm volatile ("mov %0, %%cr0" : : "r"(cr0));
}

static inline void enable_paging() {
  uint32_t cr0 = get_cr0();
  cr0 |= 0x80000000;
  set_cr0(cr0);
}

static inline void enable_wp() {
  uint32_t cr0 = get_cr0();
  cr0 |= 0x00010000;
  set_cr0(cr0);
}

#endif
