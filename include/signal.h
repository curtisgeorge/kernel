#pragma once

#include <sys/types.h>

#define SIGINT  2
#define	SIGFPE  8
#define SIGALRM 14

typedef int sigset_t;
typedef int sig_atomic_t;

int  kill(pid_t, int);
void (*signal(int sig, void (*)(int)))(int);
