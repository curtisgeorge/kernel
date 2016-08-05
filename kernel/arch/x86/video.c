#include <stdint.h>
#include "video.h"

static const uint16_t VIDEO_NUM_COLUMS = 80; 
static const uint16_t VIDEO_NUM_ROWS = 25; 
static uint16_t video_xpos = 0;
static uint16_t video_ypos = 0;
static volatile uint8_t* video_ptr;

void init_video() {
  video_ptr = (uint8_t*) 0xB8000;
  cls();
}

void cls() {
  int i;
  for(i = 0; i < (VIDEO_NUM_COLUMS * VIDEO_NUM_ROWS * 2); i++) {
    video_ptr[i] = 0;
  }
}

void video_putchar(const char c) {
  int video_pos = (video_xpos + (video_ypos * VIDEO_NUM_COLUMS)) * 2;
  video_ptr[video_pos] = c;
  video_ptr[video_pos + 1] = 0x07;
  video_xpos++;
  if(video_xpos == VIDEO_NUM_COLUMS) {
    video_xpos = 0;
    video_ypos++;
    if(video_ypos == VIDEO_NUM_ROWS) {
      video_ypos = 0;
    }
  }
}
