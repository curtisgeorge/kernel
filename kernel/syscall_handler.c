#include <syscall_handler.h>
#include <stdint.h>
#include <printk.h>

void syscall_handler(uint32_t syscall_no, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
  if(syscall_no == SYSCALL_PRINT) {
    printk((const char*) arg1);
  }
}
