#include "gdt.h"
#include "asm.h"

gdt_entry_t gdt[3] = {
                       {
                         .limit_low = 0x0000,
                         .base_low = 0x0000,
                         .base_middle = 0x00,
                         .access = 0x00,
                         .granularity = 0x00,
                         .base_high = 0x00
                       },
                       {
                         .limit_low = 0xFFFF,
                         .base_low = 0x0000,
                         .base_middle = 0x00,
                         .access = 0x9A,
                         .granularity = 0xCF,
                         .base_high = 0x00
                       },
                       {
                         .limit_low = 0xFFFF,
                         .base_low = 0x0000,
                         .base_middle = 0x00,
                         .access = 0x92,
                         .granularity = 0xCF,
                         .base_high = 0x00
                       }
                     };

const gdt_ptr_t gdt_ptr = {
                            .limit = (sizeof(gdt_entry_t) * 3) - 1,
                            .base = (uint32_t) &gdt
                          };

static void gdt_flush() {
  asm volatile("lgdt %0" : : "m" (gdt_ptr));
  asm volatile("movl $0x10, %eax\n \
                movl %eax, %ds\n \
                movl %eax, %es\n \
                movl %eax, %fs\n \
                movl %eax, %gs\n \
                movl %eax, %ss\n \
                ljmp $(0x08), $flush\n \
                flush:");
}

void init_gdt() {
  gdt_flush();
}
