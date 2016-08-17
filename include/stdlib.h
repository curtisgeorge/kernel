#pragma once

#define __need_size_t
#define __need_NULL
#include <stddef.h>

void  abort();
int   atoi(const char*);
void* bsearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));
void  exit(int) __attribute__((noreturn));
void  free(void*);
char* getenv(const char*);
void* malloc(size_t);
void  qsort(void*, size_t, size_t, int (*)(const void*, const void*));
void* realloc(void*, size_t);
