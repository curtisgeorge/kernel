#ifndef IDT_H
#define IDT_H

struct idt_entry_t
{
  unsigned short base_lo;
  unsigned short sel;	/* Our kernel segment goes here! */
  unsigned char always0;	/* This will ALWAYS be set to 0! */
  unsigned char flags;	/* Set using the above table! */
  unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr_t
{
  unsigned short limit;
  unsigned int base;
} __attribute__((packed));

void init_idt();

#endif
