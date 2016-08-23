#include <stdlib.h>

long long int atoll(const char* str) {
  return strtoll(str, (char**) NULL, 10);
}
