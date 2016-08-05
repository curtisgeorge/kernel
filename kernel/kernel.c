#include <arch.h>
#include <printk.h>
#include <syscall.h>

void kmain() {
  init_arch();
  printk("Hello world");
  const char* s = "Test";
  syscall(s);
}
