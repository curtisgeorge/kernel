#include <arch.h>
#include "video.h"
#include "gdt.h"
#include "idt.h"
#include "irq.h"

void init_arch() {
  init_video();
  init_gdt();
  remap_irqs();
  init_idt();
  asm volatile("sti");
}
