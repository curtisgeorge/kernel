#pragma once

#include <stdint.h>

enum SYSCALLS { SYSCALL_PRINT = 0x4 };

void syscall_handler(uint32_t, uint32_t, uint32_t, uint32_t);
