#include <stdio.h>

char* gets(char* s) {
  char c;
  while((c = getchar()) != '\n') {
    *s++ = c;
  }
  *s = '\0';
  return s;
}
