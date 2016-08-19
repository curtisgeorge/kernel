#pragma once

#include <sys/types.h>

#define O_RDONLY   00
#define O_WRONLY   01
#define O_RDWR     02
#define O_CREAT    0100
#define O_EXCL     0200
#define O_TRUNC    01000
#define O_APPEND   02000
#define O_NONBLOCK 00004000

#define FD_CLOEXEC 1

#define F_DUPFD 0
#define F_GETFD 1
#define F_SETFD 2
#define F_GETFL 3
#define F_SETFL 4

int creat(const char*, mode_t);
int fcntl(int, int, ...);
int open(const char*, int, ...);
int openat(int, const char*, int, ...);
int posix_fadvise(int, off_t, off_t, int);
int posix_fallocate(int , off_t, off_t);
