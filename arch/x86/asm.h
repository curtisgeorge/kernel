#ifndef ASM_H
#define ASM_H

static inline void outb(unsigned short port, unsigned char val)
{
  asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

#endif
