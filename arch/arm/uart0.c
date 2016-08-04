#include <stdint.h>
#include "pic.h"

volatile uint32_t * const UART0DR = (uint32_t *)0x101f1000;

/* serial port register offsets */
#define UART_DATA        0x00 
#define UART_FLAGS       0x06
#define UART_INT_ENABLE  0x0e
#define UART_INT_TARGET  0x0f
#define UART_INT_CLEAR   0x11

/* serial port bitmasks */
#define UART_RECEIVE  0x10
#define UART_TRANSMIT 0x20

void uart0_init() {
  UART0DR[UART_INT_ENABLE] = UART_RECEIVE;
  enable_irq_line(12);
}

void uart0_puts(const char *s) {
  while(*s != '\0') { /* Loop until end of string */
    *UART0DR = (uint32_t)(*s); /* Transmit char */
    s++; /* Next char */
  }
}

char uart0_receive() {
  return (char) *UART0DR;
}
