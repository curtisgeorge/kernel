#pragma once

#include <stdint.h>

typedef struct {
  uint16_t com1_port;
  uint16_t com2_port;
  uint16_t com3_port;
  uint16_t com4_port;
  uint16_t lpt1_port;
  uint16_t lpt2_port;
  uint16_t lpt3_port;
  uint16_t lpt4_port;
  uint16_t equipment_list_flags;
  uint8_t  : 8;
  uint16_t memory_kbytes;
  uint16_t : 16;
  uint16_t keyboard_flags;
  uint8_t  alt_keypad_data;
  uint16_t keyboard_buffer_start;
  uint16_t keyboard_buffer_end;
  uint8_t  keyboard_buffer[32];
  uint8_t  fixme[11];
  uint8_t  active_video_mode;
  //TODO: Fill in the rest of these
} __attribute__((packed)) bios_data_t;

extern bios_data_t* bios_data_ptr;
