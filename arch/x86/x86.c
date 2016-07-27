#include <arch.h>
#include "video.h"
#include "gdt.h"

void init_arch() {
  init_video();
  init_gdt();
}
