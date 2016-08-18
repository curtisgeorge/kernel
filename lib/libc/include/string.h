#pragma once

#define __need_size_t
#define __need_NULL
#include <stddef.h>

void*  memcpy(void*, const void*, size_t);
void*  memmove(void*, const void*, size_t);
char*  strchr(const char*, int);
char*  strcpy(char*, const char*);
int    strcmp(const char*, const char*);
char*  strerror(int);
size_t strlen(const char*);
char*  strrchr(const char*, int);
int    strncmp(const char*, const char*, size_t);
char * strncpy(char*, const char*, size_t);
char*  strstr(const char*, const char*);
