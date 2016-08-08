#pragma once

#include <stdint.h>

void syscall(const char*);
static const uint8_t SYSCALL_INT = 0x80;
