#include <stdlib.h>

int atoi(const char* str) {
  return strtol(str, (char**) NULL, 10);
}
