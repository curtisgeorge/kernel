#include <printk.h>

extern "C" void _isr80();
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

void init_isrs() {
  idt_set_gate(0x80, (unsigned)_isr80, 0x08, 0x8E | 0x60);
}

extern "C"
void _fault_handler() {
  printk("fault");
}
