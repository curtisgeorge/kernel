#pragma once

void _exit(int status) __attribute__((noreturn));
int execve(const char*, char *const [], char *const []);
int fork();
