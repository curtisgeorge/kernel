#include "video.h"

static const unsigned short VIDEO_NUM_COLUMS = 80; 
static const unsigned short VIDEO_NUM_ROWS = 25; 
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
