#pragma once

#include <sys/types.h>

#define	R_OK 4
#define	W_OK 2
#define	X_OK 1
#define	F_OK 0

extern char* optarg;
extern int optind, opterr, optopt;

void         _exit(int) __attribute__((noreturn));
unsigned int alarm(unsigned int);
int          close(int);
int          execve(const char*, char *const [], char *const []);
int          fork();
char*        getcwd(char*, size_t);
gid_t        getegid();
uid_t        geteuid();
gid_t        getgid();
int          getopt(int, char *const [], const char*);
pid_t        getpid();
uid_t        getuid();
int          isatty(int);
off_t        lseek(int, off_t, int);
int          pipe(int [2]);
ssize_t      read(int, void*, size_t);
int          setegid(gid_t);
int          seteuid(uid_t);
int          setgid(gid_t);
int          setuid(uid_t);
unsigned int sleep(unsigned int);
