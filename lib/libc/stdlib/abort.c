#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void abort() {
  _exit(127);
  while(1) {}
}
