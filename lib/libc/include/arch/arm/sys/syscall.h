#pragma once

static inline int syscall1(int syscall_no, unsigned int arg1) {
  asm volatile ("mov r0, %0; mov r1, %1; svc #0x80" : : "r"(syscall_no), "r"(arg1) : "r0", "r1");
}
