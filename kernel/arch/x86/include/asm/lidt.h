#pragma once

#include <idt.h>

static inline void lidt(const idt_ptr_t* idt_ptr) {
  asm volatile ("lidt %0" : : "m"(*idt_ptr));
}
