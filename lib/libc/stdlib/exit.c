#include <stdlib.h>
#include <unistd.h>

void exit(int status) {
  //TODO: Add cleanup code
  _exit(status);
}
