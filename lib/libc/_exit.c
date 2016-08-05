#include <unistd.h>
#include <syscall.h>

void _exit(int status) {
  syscall_exit(status & 0xFF);
  while(1) {}
}
