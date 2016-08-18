#pragma once

#include <sys/types.h>

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

struct timespec {
  time_t tv_sec;
  time_t tv_nsec;
};

size_t     strftime(char*, size_t, const char*, const struct tm*);
clock_t    clock();
time_t     time(time_t*);
struct tm* localtime(const time_t*);
