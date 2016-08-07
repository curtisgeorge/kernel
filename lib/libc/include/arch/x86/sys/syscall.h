#pragma once

static inline int syscall1(int syscall_no, unsigned int arg1) {
  asm volatile ("int $0x80" : : "a"(syscall_no), "b"(arg1));
}
