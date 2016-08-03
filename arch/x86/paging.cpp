#include "paging.h"
#include "asm.h"

struct page_dir_entry_t page_dir[1024] __attribute__((aligned(4096)));

void init_paging() {
  page_dir[0].offset = 0x00000;
  page_dir[0].flags = 0x083;
  int i;
  for(i = 1; i < 1024; i++) {
    page_dir[i].offset = 0x00000;
    page_dir[i].flags = 0x000;
  }

  load_page_dir((uint32_t) page_dir);
  enable_pse();
  enable_paging();
}
