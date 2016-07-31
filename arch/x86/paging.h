#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>

struct page_dir_entry_t {
  uint16_t flags  : 12;
  uint32_t offset : 20;
} __attribute__((packed));

void init_paging();

#endif
