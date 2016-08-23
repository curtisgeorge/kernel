#include <fcntl.h>
#include <syscall.h>

int creat(const char* path, mode_t mod) {
  return syscall_creat(path, mod);
}
