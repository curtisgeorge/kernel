#include <unistd.h>
#include <syscall.h>

int fork() {
  return syscall_fork();
}
