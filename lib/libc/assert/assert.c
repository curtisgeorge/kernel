#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void __assert_func(const char* file, int line, const char* func, const char* expression) {
  fprintf(stderr, "%s:%d: %s: Assertion \"%s\" failed\n", file, line, func, expression);
  abort();
}
