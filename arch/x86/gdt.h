#ifndef GDT_H
#define GDT_H

#include <stdint.h>

struct gdt_ptr_t {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

struct gdt_entry_t {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t granularity;
  uint8_t base_high;
} __attribute__((packed));

extern gdt_entry_t gdt[3];
extern const gdt_ptr_t gdt_ptr;

void init_gdt();

#endif
