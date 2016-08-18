#pragma once

#include <sys/types.h>

#define SIGINT  2
#define SIGQUIT 3
#define	SIGFPE  8
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15
#define SIGCHLD 17

typedef void (*__sighandler_t) (int);

#define SIG_ERR	((__sighandler_t) -1)
#define SIG_DFL	((__sighandler_t) 0)
#define SIG_IGN	((__sighandler_t) 1)

typedef int sigset_t;
typedef int sig_atomic_t;

int  kill(pid_t, int);
void (*signal(int sig, void (*)(int)))(int);
