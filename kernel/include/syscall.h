#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>

void syscall(const char*);
static const uint8_t SYSCALL_INT = 0x80;

#endif
