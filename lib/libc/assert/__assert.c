#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void __assert(const char* expression, const char* file, int line, const char* func) {
  if(func == NULL) {
    fprintf(stderr, "Assertion failed: %s, file %s, line %d.\n", expression, file, line);
  }
  else {
    fprintf(stderr, "Assertion failed: %s, function %s, file %s, line %d.\n", expression, func, file, line);
  }
  abort();
}
