#pragma once

#define WNOHANG   1
#define WUNTRACED 2

#define WIFEXITED(status)    0
#define WEXITSTATUS(status)  0
#define WIFSIGNALED(status)  0
#define WTERMSIG(status)     0
#define WIFSTOPPED(status)   0
#define WSTOPSIG(status)     0
#define WIFCONTINUED(status) 0
