#include <arch.h>
#include <printk.h>

extern "C"
void kmain() {
  init_arch();
  printk("Hello world");
}
