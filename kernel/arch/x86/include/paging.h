#pragma once

#include <stdint.h>

typedef struct {
  uint16_t flags  : 12;
  uint32_t offset : 20;
} __attribute__((packed)) page_dir_entry_t;

void init_paging();
