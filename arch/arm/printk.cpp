#include "uart0.h"

void printk(const char* s) {
  uart0_puts(s);
}
