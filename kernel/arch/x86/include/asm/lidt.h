#ifndef ASM_LIDT_H
#define ASM_LIDT_H

#include <idt.h>

static inline void lidt(const idt_ptr_t* idt_ptr) {
  asm volatile ("lidt %0" : : "m"(*idt_ptr));
}

#endif
