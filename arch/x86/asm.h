#ifndef ASM_H
#define ASM_H

static inline void sti() {
  asm volatile ( "sti" );
}

static inline void cli() {
  asm volatile ( "cli" );
}

static inline void hlt() {
  asm volatile ( "hlt" );
}

static inline void outb(unsigned short port, unsigned char val)
{
  asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

#endif
