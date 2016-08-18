#pragma once

#include <sys/types.h>

struct timeval {
  time_t      tv_sec;
  suseconds_t tv_usec;
};

struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};

int gettimer(int, struct itimerval*);
int gettimeofday(struct timeval*, void*);
int setitimer(int, const struct itimerval*, struct itimerval*);
