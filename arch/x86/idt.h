#ifndef IDT_H
#define IDT_H

#include <stdint.h>

typedef struct
{
  uint16_t base_lo;
  uint16_t sel;	/* Our kernel segment goes here! */
  uint8_t always0;	/* This will ALWAYS be set to 0! */
  uint8_t flags;	/* Set using the above table! */
  uint16_t base_hi;
} __attribute__((packed)) idt_entry_t;

typedef struct
{
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void init_idt();

#endif
