#pragma once

extern char* optarg;
extern int optind, opterr, optopt;

void _exit(int status) __attribute__((noreturn));
int  execve(const char*, char *const [], char *const []);
int  fork();
int  getopt(int, char *const [], const char*);

