#ifndef GDT_H
#define GDT_H

struct gdt_ptr_t
{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

struct gdt_entry_t {
  unsigned short limit_low;
  unsigned short base_low;
  unsigned char base_middle;
  unsigned char access;
  unsigned char granularity;
  unsigned char base_high;
} __attribute__((packed));

extern const struct gdt_entry_t gdt[3];
extern const struct gdt_ptr_t gdt_ptr;

void init_gdt();

#endif
