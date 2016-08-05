#ifndef _SYS_SYSCALL_H_
#define _SYS_SYSCALL_H_

static inline int syscall1(int syscall_no, unsigned int arg1) {
  asm volatile ("mov %0, %%eax; mov %1, %%ebx; int $0x80" : : "r"(syscall_no), "r"(arg1) : "%eax", "%ebx");
}

#endif
