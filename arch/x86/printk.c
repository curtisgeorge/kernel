#include <printk.h>
#include "video.h"

void printk(const char* str) {
  int i = 0;
  while(str[i] != '\0') {
    video_putchar(str[i]);
    i++;
  }
}
