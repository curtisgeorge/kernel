#include <ctype.h>

/**
 * Note: only works with ascii chars
 */
int iscntrl(int c) {
  return (unsigned int) c < 0x20 || c == 0x7F;
}
