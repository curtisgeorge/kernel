#include <syscall.h>
#include <asm/int.h>

void syscall(const char* s) {
  asm volatile ("movl %0, %%eax; movl %1, %%ebx" : : "r"(0x04), "r"(s) : "%eax", "%ebx");
  interrupt(SYSCALL_INT);
}
