#include <stdint.h>
#include "clcd.h"
#include "font.h"

static const uint16_t H_SIZE = 320;
static const uint16_t V_SIZE = 240;
static const uint16_t NUM_COLS = 40;
static const uint16_t NUM_ROWS = 30;
static const uint32_t CLCD_TIME0_REG_ADDR = 0x10120000;
static const uint32_t CLCD_TIME1_REG_ADDR = 0x10120004;
static const uint32_t CLCD_TIME2_REG_ADDR = 0x10120008;

static const uint32_t CLCD_VGA_TIME0_VAL = 0x9F7FBF4C;
static const uint32_t CLCD_VGA_TIME1_VAL = 0x818360EF;
static const uint32_t CLCD_VGA_TIME2_VAL = 0x053F1800;

static uint32_t* fb_ptr = (uint32_t*) 0x100000;

uint16_t col = 0;
uint16_t row = 0;

void init_clcd() {
  *(volatile uint32_t *)(0x1000001C) = 0x2C77; /* VGA Timing */
  *(volatile uint32_t *)(CLCD_TIME0_REG_ADDR) = CLCD_VGA_TIME0_VAL;
  *(volatile uint32_t *)(CLCD_TIME1_REG_ADDR) = CLCD_VGA_TIME1_VAL;
  *(volatile uint32_t *)(CLCD_TIME2_REG_ADDR) = CLCD_VGA_TIME2_VAL;
  *(volatile uint32_t *)(0x10120010) = 0x100000; /* base addr of frame buffer */
  *(volatile uint32_t *)(0x10120018) = 0x82B; /* control bits */
}

void set_pixel(uint16_t x, uint16_t y, uint32_t val) {
  fb_ptr[x + (H_SIZE * y)] = val;
}

void clcd_putchar(const char c) {
  uint64_t pixmap = font_map[(uint8_t) c];
  int i;
  uint16_t x = 0;
  uint16_t y = 0;
  for(i = 0; i < 64; i++) {
    uint32_t val;
    if(pixmap & 1) {
      val = 0x00FFFFFF;
    }
    else {
      val = 0x00000000;
    }
    set_pixel((8 * col) + x, (8 * row) + y, val);
    x++;
    if(x == 8) {
      y++;
      x = 0;
    }
    pixmap >>= 1;
  }
  col++;
  if(col == NUM_COLS) {
    row++;
    col = 0;
    if(row == NUM_ROWS) {
      row = 0;
    }
  }
}

void clcd_puts(const char* s) {
  while(*s != '\0') {
    clcd_putchar(*s);
    s++;
  }
}
