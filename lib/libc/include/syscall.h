#ifndef _SYSCALL_H_
#define _SYSCALL_H_

#include <sys/syscall.h>

static inline int syscall_exit(int status) {
  return syscall1(1, status);
}

static inline int syscall_print(const char* s) {
  return syscall1(2, (unsigned int) s);
}

#endif
