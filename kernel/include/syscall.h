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

static inline int syscall_close(unsigned int fd) {
  return syscall1(6, fd);
}

static inline int syscall_creat(const char* path, int mode) {
  return syscall2(8, (unsigned int) path, (unsigned int) mode);
}

static inline int syscall_link(const char* path1, const char* path2) {
  return syscall2(9, (unsigned int) path1, (unsigned int) path2);
}

static inline int syscall_unlink(const char* path) {
  return syscall1(10, (unsigned int) path);
}

static inline int syscall_execve(const char* filename, char *const argv[], char *const envp[]) {
  return syscall3(11, (unsigned int) filename, (unsigned int) argv, (unsigned int) envp);
}

static inline int syscall_getpid() {
  return syscall0(20);
}

static inline int syscall_alarm(unsigned int seconds) {
  return syscall1(27, seconds);
}

static inline int syscall_kill(int pid, int sig) {
  return syscall2(37, pid, sig);
}

static inline int syscall_getuid() {
  return syscall0(199);
}

static inline int syscall_getgid() {
  return syscall0(200);
}
