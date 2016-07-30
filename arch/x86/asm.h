#ifndef ASM_H
#define ASM_H

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

static inline void lgdt(const struct gdt_ptr_t* gdt_ptr) {
  asm volatile ( "lgdt %0" : : "m" (*gdt_ptr) );
}

static inline void reset_segment_regs() {
  asm volatile("movl $0x10, %%eax\n \
                movl %%eax, %%ds\n \
                movl %%eax, %%es\n \
                movl %%eax, %%fs\n \
                movl %%eax, %%gs\n \
                movl %%eax, %%ss\n \
                ljmp $(0x08), $flush\n \
                flush:" : : : "%eax" );
}

static inline void lidt(const struct idt_ptr_t* idt_ptr) {
  asm volatile ( "lidt %0" : : "m" (*idt_ptr) );
}

static inline void outb(unsigned short port, unsigned char val)
{
  asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}


static inline unsigned char inb(unsigned short port)
{
    unsigned char ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

static inline void load_page_dir(unsigned int page_dir) {
  asm volatile ("mov %0, %%cr3" : : "r"(page_dir));

}

static inline void enable_pse() {
  asm volatile ("mov %%cr4, %%ecx\n \
                 or $0x00000010, %%ecx\n \
                 mov %%ecx, %%cr4" : : :  "%ecx" );
}

static inline void enable_paging() {
  asm volatile ("mov %%cr0, %%ecx\n \
                 or $0x80000000, %%ecx\n \
                 mov %%ecx, %%cr0" : : : "%ecx");

}

#endif
