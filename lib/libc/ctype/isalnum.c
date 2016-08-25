#include <ctype.h>

/**
 * Note: only works with ascii chars
 */
int isalnum(int c) {
  return isalpha(c) || isdigit(c);
}
