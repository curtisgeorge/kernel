#include <stdio.h>
#include <unistd.h>

int fclose(FILE* f) {
  return close(f->_file);
}
