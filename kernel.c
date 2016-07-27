#include <arch.h>
#include <printk.h>

void kmain() {
  init_arch();
  printk("Hello world");
}
