#include "uart0.h"
#include "clcd.h"

void printk(const char* s) {
  uart0_puts(s);
  clcd_puts(s);
}
