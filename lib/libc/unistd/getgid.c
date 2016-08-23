#include <unistd.h>
#include <syscall.h>

gid_t getgid() {
  return syscall_getgid();
}
