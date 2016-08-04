#ifndef PIC_H
#define PIC_H

#include <stdint.h>

void enable_irq_line(uint32_t);
uint32_t get_status();

#endif
