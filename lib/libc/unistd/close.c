#include <unistd.h>
#include <syscall.h>

int close(int fildes) {
  return syscall_close(fildes);
}
