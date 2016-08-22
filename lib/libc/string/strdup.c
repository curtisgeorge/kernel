#include <string.h>
#include <stdlib.h>

char* strdup(const char* s1) {
  char* s;
  size_t l = strlen(s1) + 1;
  if((s = malloc(l)) != NULL) {
    memcpy(s, s1, l);
  }
  return s;
}
