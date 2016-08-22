#include <stdlib.h>

int abs(int n) {
  return n < 0 ? -n : n;
}

long labs(long n) __attribute__((alias("abs")));

long long llabs(long long n) __attribute__((alias("abs")));
