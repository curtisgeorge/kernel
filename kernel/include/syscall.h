#pragma once

#include <sys/syscall.h>

static inline int syscall_exit(int status) {
  return syscall1(1, status);
}

static inline int syscall_fork() {
  return syscall0(2);
}

static inline int syscall_getchar() {
  return syscall0(3);
}

static inline int syscall_print(const char* s) {
  return syscall1(4, (unsigned int) s);
}

static inline int syscall_execve(const char* filename, char *const argv[], char *const envp[]) {
  return syscall3(11, (unsigned int) filename, (unsigned int) argv, (unsigned int) envp);
}
