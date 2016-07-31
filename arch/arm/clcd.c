#include "clcd.h"

static const uint32_t H_SIZE = 320;
static const uint32_t V_SIZE = 240;
static const uint32_t CLCD_TIME0_REG_ADDR = 0x10120000;
static const uint32_t CLCD_TIME1_REG_ADDR = 0x10120004;
static const uint32_t CLCD_TIME2_REG_ADDR = 0x10120008;

static const uint32_t CLCD_VGA_TIME0_VAL = 0x9F7FBF4C;
static const uint32_t CLCD_VGA_TIME1_VAL = 0x818360EF;
static const uint32_t CLCD_VGA_TIME2_VAL = 0x053F1800;

static uint32_t* fb_ptr = (uint32_t*) 0x100000;

void init_clcd() {
  *(volatile uint32_t *)(0x1000001C) = 0x2C77; /* VGA Timing */
  *(volatile uint32_t *)(CLCD_TIME0_REG_ADDR) = CLCD_VGA_TIME0_VAL;
  *(volatile uint32_t *)(CLCD_TIME1_REG_ADDR) = CLCD_VGA_TIME1_VAL;
  *(volatile uint32_t *)(CLCD_TIME2_REG_ADDR) = CLCD_VGA_TIME2_VAL;
  *(volatile uint32_t *)(0x10120010) = 0x100000; /* base addr of frame buffer */
  *(volatile uint32_t *)(0x10120018) = 0x82B; /* control bits */
}

void set_pixel(uint8_t x, uint8_t y, uint32_t val) {
  fb_ptr[x + (H_SIZE * y)] = val;
}
