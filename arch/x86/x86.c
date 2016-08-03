#include <arch.h>
#include <video.h>
#include <gdt.h>
#include <idt.h>
#include <irq.h>
#include <isrs.h>
#include <paging.h>
#include <asm/sti.h>

void init_arch() {
  init_video();
  init_gdt();
  init_idt();
  remap_irqs();
  init_isrs();
  init_paging();
  sti();
}
