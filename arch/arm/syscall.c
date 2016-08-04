#include <syscall.h>

void syscall(const char* s) {
  asm volatile("mov r1, %0" : : "r"(s));
  asm volatile("swi #0x80");
}
