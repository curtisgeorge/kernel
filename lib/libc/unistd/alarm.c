#include <unistd.h>
#include <syscall.h>

unsigned int alarm(unsigned int seconds) {
  return syscall_alarm(seconds);
}
