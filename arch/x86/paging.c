#include <stdint.h>
#include "paging.h"
#include "asm.h"

uint32_t page_dir[1024] __attribute__((aligned(4096)));
uint32_t page_table[1024] __attribute__((aligned(4096)));

void init_paging() {
  uint32_t i;
  page_dir[0] = (((uint32_t) page_table) & 0xFFFFF000) | 3;
  for(i = 1; i < 1024; i++) {
    page_dir[i] = 0;
  }
  for(i = 0; i < 512; i++) {
    page_table[i] = ((i * 4096) & 0xFFFFF000) | 3;
  }
  page_table[256] = 0x00100001;
  for(i = 512; i < 1024; i++) {
    page_table[i] = 0;
  }

  load_page_dir((uint32_t) page_dir);
  enable_wp();
  //enable_pse();
  enable_paging();
}
