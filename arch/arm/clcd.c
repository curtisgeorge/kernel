#include "clcd.h"

static const unsigned int H_SIZE = 320;
static const unsigned int V_SIZE = 240;
static const unsigned int CLCD_TIME0_REG_ADDR = 0x10120000;
static const unsigned int CLCD_TIME1_REG_ADDR = 0x10120004;
static const unsigned int CLCD_TIME2_REG_ADDR = 0x10120008;

static const unsigned int CLCD_VGA_TIME0_VAL = 0x9F7FBF4C;
static const unsigned int CLCD_VGA_TIME1_VAL = 0x818360EF;
static const unsigned int CLCD_VGA_TIME2_VAL = 0x053F1800;

static unsigned int* fb_ptr = (unsigned int*) 0x100000;

void init_clcd() {
  *(volatile unsigned int *)(0x1000001C) = 0x2C77; /* VGA Timing */
  *(volatile unsigned int *)(CLCD_TIME0_REG_ADDR) = CLCD_VGA_TIME0_VAL;
  *(volatile unsigned int *)(CLCD_TIME1_REG_ADDR) = CLCD_VGA_TIME1_VAL;
  *(volatile unsigned int *)(CLCD_TIME2_REG_ADDR) = CLCD_VGA_TIME2_VAL;
  *(volatile unsigned int *)(0x10120010) = 0x100000; /* base addr of frame buffer */
  *(volatile unsigned int *)(0x10120018) = 0x82B; /* control bits */
}

void set_pixel(unsigned char x, unsigned char y, unsigned int val) {
  fb_ptr[x + (H_SIZE * y)] = val;
}
