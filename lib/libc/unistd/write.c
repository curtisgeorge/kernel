#include <unistd.h>
#include <syscall.h>

ssize_t write(int fildes, const void* buf, size_t nbyte) {
  return syscall_write(fildes, (const char*) buf, nbyte);
}
