#include "clcd.h"

unsigned int* fb_ptr = (unsigned int*) 0x100000;

void set_pixel(unsigned char x, unsigned char y, unsigned int val);

void init_clcd() {
  *(volatile unsigned int *)(0x1000001C) = 0x2C77; /* VGA Timing */
  *(volatile unsigned int *)(0x10120000) = 0x9F7FBF4C;
  *(volatile unsigned int *)(0x10120004) = 0x818360eF;
  *(volatile unsigned int *)(0x10120008) = 0x053F1800;
  *(volatile unsigned int *)(0x10120010) = 0x100000; /* base addr of frame buffer */
  *(volatile unsigned int *)(0x10120018) = 0x82b; /* control bits */
}

void set_pixel(unsigned char x, unsigned char y, unsigned int val) {
  fb_ptr[x + (320 * y)] = val;
}
