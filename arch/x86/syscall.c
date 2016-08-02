#include <syscall.h>

void syscall(const char* s) {
  asm volatile ("movl %0, %%ebx; int $0x80" : : "r"(s) : "%ebx");
}
