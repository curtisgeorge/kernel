#include <stdint.h>
#include "gdt.h"
#include "asm.h"

const struct gdt_entry_t gdt[3] = {
                                    {
                                      .base_low = 0x0000,
                                      .base_middle = 0x00,
                                      .base_high = 0x00,
                                      .limit_low = 0x0000,
                                      .granularity = 0x00, 
                                      .access = 0x00
                                    },
                                    {
                                      .base_low = 0x0000,
                                      .base_middle = 0x00,
                                      .base_high = 0x00,
                                      .limit_low = 0xFFFF,
                                      .granularity = 0xCF, 
                                      .access = 0x9A
                                    },
                                    {
                                      .base_low = 0x0000,
                                      .base_middle = 0x00,
                                      .base_high = 0x00,
                                      .limit_low = 0xFFFF,
                                      .granularity = 0xCF, 
                                      .access = 0x92
                                    }
                                  };

const struct gdt_ptr_t gdt_ptr = {
                                   .limit = (sizeof(struct gdt_entry_t) * 3) - 1,
                                   .base = (uint32_t) &gdt
                                 };


static void gdt_flush() {
  lgdt(&gdt_ptr);
  reset_segment_regs();
}

void init_gdt() {
  gdt_flush();
}
