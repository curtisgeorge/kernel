#include <syscall.h>

void syscall(const char* s) {
  asm volatile("mov r0, #0x4; mov r1, %0" : : "r"(s) : "r0", "r1");
  asm volatile("swi #0x80");
}
