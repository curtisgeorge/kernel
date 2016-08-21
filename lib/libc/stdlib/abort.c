#include <stdlib.h>
#include <signal.h>

void abort() {
  exit(SIGABRT);
}
