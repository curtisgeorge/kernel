#include <printk.h>
#include "irq.h"
#include "asm.h"
#include "keyboard_map.h"

extern void _irq0();
extern void _irq1();
extern void _irq2();
extern void _irq3();
extern void _irq4();
extern void _irq5();
extern void _irq6();
extern void _irq7();
extern void _irq8();
extern void _irq9();
extern void _irq10();
extern void _irq11();
extern void _irq12();
extern void _irq13();
extern void _irq14();
extern void _irq15();
extern void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

void remap_irqs() {
  // reset the master and slave PIC
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  // remap master to int 32 - 39
  // and slave to int 40 - 47
  outb(0x21, 0x20);
  outb(0xA1, 0x28);
  // setup master/slave cascade over IR2
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  // Set it to 80x86 mode and we are done
  outb(0x21, 0x01);
  outb(0xA1, 0x01);

  // Mask all IRQs except IRQ1 (keyboard)
  outb(0x21, 0xFC);
  outb(0xA1, 0xFF);

  uint32_t frequency = 20;
  // (1193180 Hz) by, to get our required frequency. Important to note is 
  // that the divisor must be small enough to fit into 16-bits. 
  uint32_t divisor = 1193180 / frequency; 
  // Send the command byte. 
  outb(0x43, 0x36); // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
  uint8_t l = (uint8_t)(divisor & 0xFF);
  uint8_t h = (uint8_t)( (divisor>>8) & 0xFF );
  // Send the frequency divisor.
  outb(0x40, l);
  outb(0x40, h);

  // Register IRQ handlers
  idt_set_gate(32, (unsigned)_irq0, 0x08, 0x8E);
  idt_set_gate(33, (unsigned)_irq1, 0x08, 0x8E);
  idt_set_gate(34, (unsigned)_irq2, 0x08, 0x8E);
  idt_set_gate(35, (unsigned)_irq3, 0x08, 0x8E);
  idt_set_gate(36, (unsigned)_irq4, 0x08, 0x8E);
  idt_set_gate(37, (unsigned)_irq5, 0x08, 0x8E);
  idt_set_gate(38, (unsigned)_irq6, 0x08, 0x8E);
  idt_set_gate(39, (unsigned)_irq7, 0x08, 0x8E);
  idt_set_gate(40, (unsigned)_irq8, 0x08, 0x8E);
  idt_set_gate(41, (unsigned)_irq9, 0x08, 0x8E);
  idt_set_gate(42, (unsigned)_irq10, 0x08, 0x8E);
  idt_set_gate(43, (unsigned)_irq11, 0x08, 0x8E);
  idt_set_gate(44, (unsigned)_irq12, 0x08, 0x8E);
  idt_set_gate(45, (unsigned)_irq13, 0x08, 0x8E);
  idt_set_gate(46, (unsigned)_irq14, 0x08, 0x8E);
  idt_set_gate(47, (unsigned)_irq15, 0x08, 0x8E);
}

void irq_handler(struct regs* r)
{
  if (r->int_no >= 40) {
    outb(0xA0, 0x20);
  }
  outb(0x20, 0x20);
  if(r->int_no == 32) {
    printk("tick");
  }
  else if (r->int_no == 33) {
    uint8_t status = inb(0x64);
    if(status & 1) {
      uint8_t val = inb(0x60);
      if(val & 0x80) {
        return;
      }
      char str[2];
      str[0] = keyboard_map[val];
      str[1] = '\0';
      printk(str);
    }
  }
}
