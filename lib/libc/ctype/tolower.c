#include <ctype.h>

int tolower(int c) {
  if ((unsigned int) (c - 'A') < 26) {
    c |= 0x20;
  }
  return c;
}
