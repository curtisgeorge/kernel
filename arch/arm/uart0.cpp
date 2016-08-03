#include <stdint.h>

volatile uint32_t * const UART0DR = (uint32_t *)0x101f1000;
 
void uart0_puts(const char *s) {
  while(*s != '\0') { /* Loop until end of string */
    *UART0DR = (uint32_t)(*s); /* Transmit char */
    s++; /* Next char */
  }
}
