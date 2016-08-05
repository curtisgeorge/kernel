#include <stdio.h>
#include <syscall.h>

int printf(const char* s, ...) {
  return syscall_print(s);
}
