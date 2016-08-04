#include <stdint.h>

uint32_t page_dir[4096] __attribute__((aligned(0x4000)));

void init_paging() {
  int i;
  for(i = 0; i < 2048; i++) {
    page_dir[i] = (i << 20) | 0x402;
  }
  for(i = 2048; i < 4096; i++) {
    page_dir[i] = 0;
  }

  asm volatile("ldr r0, =page_dir\n"
               "mcr p15, 0, r0, c2, c0, 0\n"
               "mov r0, #0x1\n"
               "mcr p15, 0, r0, cr3, cr0, 0" : : : "r0");
  asm volatile("mrc p15, 0, r0, cr1, cr0, 0; orr r0, #1; mcr p15, 0, r0, cr1, cr0, 0" : : : "r0");
}
