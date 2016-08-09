#include <stdint.h>
#include <paging.h>
#include <asm/cr0.h>
#include <asm/cr3.h>

// The page directory and page tables are 1024 * 4 bytes large,
// and must be 4K aligned.  So, each one takes up its own 4K block.
uint32_t page_dir[1024] __attribute__((aligned(4096)));
uint32_t page_table[1024] __attribute__((aligned(4096)));

static inline void load_page_dir() {
  set_cr3((uint32_t) page_dir);
}

static inline void enable_paging() {
  set_cr0_flags(WP | PG);
}

void init_paging() {
  // Setup the page directory and an initial page table
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

  // Tell the cpu where the page dir is
  load_page_dir();
  // Now let's enable paging
  enable_paging();
}
