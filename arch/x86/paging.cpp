#include "asm.h"

int page_dir[1024] __attribute__((aligned(4096)));

void init_paging() {
  page_dir[0] = 0x00000083;
  int i;
  for(i = 1; i < 1024; i++) {
    page_dir[i] = 0;
  }

  load_page_dir((unsigned int) page_dir);
  enable_pse();
  enable_paging();
}
