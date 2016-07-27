#include "video.h"

static const unsigned short VIDEO_NUM_COLUMS = 80; 
static const unsigned short VIDEO_NUM_ROWS = 24; 
static unsigned short video_xpos = 0;
static unsigned short video_ypos = 0;
static volatile unsigned char* video_ptr;

void init_video() {
  video_ptr = (unsigned char*) 0xB8000;
  cls();
}

void cls() {
  int i;
  for(i = 0; i < (VIDEO_NUM_COLUMS * VIDEO_NUM_ROWS * 2); i++) {
    video_ptr[i] = 0;
  }
}

void video_putchar(const char c) {
  video_ptr[video_xpos * 2] = c;
  video_ptr[video_xpos * 2 + 1] = 0x07;
  video_xpos++;
}
