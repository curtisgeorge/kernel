#pragma once

#include <sys/types.h>

#define SIGHUP  1
#define SIGINT  2
#define SIGQUIT 3
#define SIGABRT 6
#define	SIGFPE  8
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15
#define SIGCHLD 17
#define SIGCONT 18
#define SIGTSTP 20
#define SIGTTIN 21
#define SIGTTOU 22

#define NSIG 65

#define SIG_SETMASK 2

#define SIG_ERR	((void (*)(int)) -1)
#define SIG_DFL	((void (*)(int)) 0)
#define SIG_IGN	((void (*)(int)) 1)

typedef int sigset_t;
typedef int sig_atomic_t;

union sigval {
  int sival_int;
  void* sival_ptr;
};

typedef struct {
  int si_signo;
  int si_code;
  int si_errno;
  pid_t si_pid;
  uid_t si_uid;
  void* si_addr;
  int si_status;
  long si_band;
  union sigval si_value;
} siginfo_t;

struct sigaction {
  void (*sa_handler)(int);
  sigset_t sa_mask;
  int sa_flags;
  void (*sa_sigaction)(int, siginfo_t*, void*);
};

extern const char *const sys_siglist[];

int  kill(pid_t, int);
int  raise(int);
int  sigemptyset(sigset_t*);
int  sigprocmask(int, const sigset_t*, sigset_t*);
void (*signal(int, void (*)(int)))(int);
