#ifndef ASM_H
#define ASM_H

#include "gdt.h"

void gdt_flush() {
  asm volatile("lgdt %0" : : "m" (gdt_ptr));
  asm volatile("movl $0x10, %eax\n \
                movl %eax, %ds\n \
                movl %eax, %es\n \
                movl %eax, %fs\n \
                movl %eax, %gs\n \
                movl %eax, %ss\n \
                ljmp $(0x08), $flush\n \
                flush:");
}

#endif
