#pragma once

static inline int syscall0(int syscall_no) {
  int ret;
  asm volatile ("int $0x80" : "=a"(ret) : "a"(syscall_no));
  return ret;
}

static inline int syscall1(int syscall_no, unsigned int arg1) {
  int ret;
  asm volatile ("int $0x80" : "=a"(ret) : "a"(syscall_no), "b"(arg1));
  return ret;
}

static inline int syscall3(int syscall_no, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
  int ret;
  asm volatile ("int $0x80" : "=a"(ret) : "a"(syscall_no), "b"(arg1), "c"(arg2), "d"(arg3));
  return ret;
}
