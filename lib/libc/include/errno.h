#pragma once

#define EINTR   4
#define E2BIG   7
#define ENOEXEC 8
#define ECHILD  10
#define EAGAIN  11
#define ENOMEM  12
#define ENOENT  22
#define ESPIPE  29
#define ERANGE  34

#define errno __errno

extern int __errno;
