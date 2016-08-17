#pragma once

#define E2BIG  7
#define ENOEXEC 8
#define ENOMEM 12
#define ENOENT 22
#define ESPIPE 29
#define ERANGE 34

extern int errno;
extern int sys_nerr;
extern char* sys_errlist[1];
