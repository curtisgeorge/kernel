#include <ctype.h>

int toupper(int c) {
  if ((unsigned int) (c - 'a') < 26) {
    c &= ~0x20;
  }
  return c;
}
