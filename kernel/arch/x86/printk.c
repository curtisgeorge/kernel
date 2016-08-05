#include <printk.h>
#include "video.h"

void printk(const char* str) {
  while(*str != '\0') {
    video_putchar(*str);
    str++;
  }
}
