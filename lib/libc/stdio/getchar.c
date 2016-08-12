#include <stdio.h>
#include <syscall.h>

int getchar() {
  return syscall_getchar();
}
