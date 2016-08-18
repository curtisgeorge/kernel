#pragma once

#include <sys/types.h>

typedef struct __dirstream DIR;

struct dirent {
  ino_t d_ino;
  char  d_name[];
};
