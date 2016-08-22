#pragma once

#include <sys/syscall.h>

static inline int syscall_exit(int status) {
  return syscall1(1, status);
}

static inline int syscall_fork() {
  return syscall0(2);
}

static inline int syscall_read(unsigned int fd, char* buf, size_t count) {
  return syscall3(3, fd, (unsigned int) buf, (unsigned int) count);
}

static inline int syscall_write(unsigned int fd, const char* s, size_t count) {
  return syscall3(4, fd, (unsigned int) s, (unsigned int) count);
}

static inline int syscall_open(const char* filename, int flags, int mode) {
  return syscall3(5, (unsigned int) filename, (unsigned int) flags, (unsigned int) mode);
}

static inline int syscall_execve(const char* filename, char *const argv[], char *const envp[]) {
  return syscall3(11, (unsigned int) filename, (unsigned int) argv, (unsigned int) envp);
}

static inline int syscall_kill(int pid, int sig) {
  return syscall2(37, pid, sig);
}
