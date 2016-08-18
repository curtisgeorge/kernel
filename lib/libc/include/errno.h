#pragma once

#define EINTR   4
#define E2BIG   7
#define ENOEXEC 8
#define EBADF   9
#define ECHILD  10
#define EAGAIN  11
#define ENOMEM  12
#define EACCES  13
#define EEXIST  17
#define ENOTDIR 20
#define ENOENT  22
#define ESPIPE  29
#define ERANGE  34

#define EWOULDBLOCK EAGAIN

#define errno __errno

extern int __errno;
