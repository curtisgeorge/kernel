#include <unistd.h>
#include <syscall.h>

pid_t getpid() {
  return (pid_t) syscall_getpid();
}
