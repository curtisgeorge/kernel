#pragma once

static inline int syscall0(int syscall_no) {
  register int r0 asm("r0") = syscall_no;
  asm volatile ("svc #0x80" : "=r"(r0) : "r"(r0));
  return r0;
}

static inline int syscall1(int syscall_no, unsigned int arg1) {
  register int r0 asm("r0") = syscall_no;
  register unsigned int r1 asm("r1") = arg1;
  asm volatile ("svc #0x80" : "=r"(r0) : "r"(r0), "r"(r1));
  return r0;
}

static inline int syscall3(int syscall_no, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
  register int r0 asm("r0") = syscall_no;
  register unsigned int r1 asm("r1") = arg1;
  register unsigned int r2 asm("r2") = arg2;
  register unsigned int r3 asm("r3") = arg3;
  asm volatile ("svc #0x80" : "=r"(r0) : "r"(r0), "r"(r1), "r"(r2), "r"(r3));
  return r0;
}
