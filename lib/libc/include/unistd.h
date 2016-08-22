#pragma once

#include <sys/types.h>

#define	R_OK 4
#define	W_OK 2
#define	X_OK 1
#define	F_OK 0

extern char* optarg;
extern int optind, opterr, optopt;
extern char** environ;

void         _exit(int) __attribute__((noreturn));
int          access(const char*, int);
unsigned int alarm(unsigned int);
int          chdir(const char*);
int          chown(const char*, uid_t, gid_t);
int          close(int);
size_t       confstr(int, char*, size_t);
char*        crypt(const char*, const char*);
int          dup(int);
int          dup2(int, int);
void         encrypt(char [64], int);
int          execl(const char*, const char*, ...);
int          execle(const char*, const char*, ...);
int          execlp(const char*, const char*, ...);
int          execv(const char*, char *const []);
int          execve(const char*, char *const [], char *const []);
int          execvp(const char*, char *const []);
int          faccessat(int, const char*, int, int);
int          fchdir(int);
int          fchown(int, uid_t, gid_t);
int          fchownat(int, const char*, uid_t, gid_t, int);
int          fdatasync(int);
int          fexecve(int, char *const [], char *const []);
pid_t        fork();
long         fpathconf(int, int);
int          fsync(int);
int          ftruncate(int, off_t);
char*        getcwd(char*, size_t);
gid_t        getegid();
uid_t        geteuid();
gid_t        getgid();
int          getgroups(int, gid_t []);
long         gethostid();
int          gethostname(char*, size_t);
char*        getlogin();
int          getlogin_r(char*, size_t);
int          getopt(int, char *const [], const char*);
pid_t        getpgid(pid_t pid);
pid_t        getpgrp();
pid_t        getpid();
pid_t        getppid();
pid_t        getsid();
uid_t        getuid();
int          isatty(int);
int          lchown(const char*, uid_t, gid_t);
int          link(const char*, const char*);
int          linkat(int, const char*, int, const char*, int);
int          lockf(int, int, off_t);
off_t        lseek(int, off_t, int);
int          nice(int);
long         pathconf(const char*, int);
int          pause();
int          pipe(int [2]);
ssize_t      pread(int, void*, size_t, off_t);
ssize_t      pwrite(int, const void*, size_t, off_t);
ssize_t      read(int, void*, size_t);
ssize_t      readlink(const char*, char*, size_t);
ssize_t      readlinkat(int, const char*, char*, size_t);
int          rmdir(const char*);
int          setegid(gid_t);
int          seteuid(uid_t);
int          setgid(gid_t);
int          setpgid(pid_t, pid_t);
pid_t        setpgrp();
int          setregid(gid_t, gid_t);
int          setreuid(uid_t, uid_t);
pid_t        setsid();
int          setuid(uid_t);
unsigned int sleep(unsigned int);
void         swab(const void*, void*, ssize_t);
int          symlink(const char*, const char*);
int          symlinkat(const char*, int, const char*);
void         sync();
long         sysconf(int);
pid_t        tcgetpgrp(int);
int          tcsetpgrp(int, pid_t);
int          truncate(const char*, off_t);
char*        ttyname(int);
int          ttyname_r(int, char*, off_t);
int          unlink(const char*);
int          unlinkat(int, const char*, int);
ssize_t      write(int, const void*, size_t);
