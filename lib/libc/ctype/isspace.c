#include <ctype.h>

int isspace(int c) {
  return (unsigned int) c - '\t' < 5 || c == ' ';
}
