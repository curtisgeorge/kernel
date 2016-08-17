#pragma once

#include <sys/time.h>

struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;
};

int getrusage(int, struct rusage*);
