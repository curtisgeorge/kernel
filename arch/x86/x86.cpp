#include <arch.h>
#include "asm.h"
#include "video.h"
#include "gdt.h"
#include "idt.h"
#include "irq.h"
#include "isrs.h"

void init_arch() {
  init_video();
  init_gdt();
  init_idt();
  remap_irqs();
  init_isrs();
  sti();
}
