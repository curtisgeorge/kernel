#include <unistd.h>
#include <syscall.h>

uid_t getuid() {
  return (uid_t) syscall_getuid();
}
