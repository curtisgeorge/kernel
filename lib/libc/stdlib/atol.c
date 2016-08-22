#include <stdlib.h>

long int atol(const char* str) {
  return strtol(str, (char**) NULL, 10);
}
