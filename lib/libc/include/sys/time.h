#pragma once

#include <sys/types.h>

struct timeval {
  time_t      tv_sec;
  suseconds_t tv_usec;
};
