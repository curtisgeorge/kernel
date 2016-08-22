#pragma once

#define __need_size_t
#define __need_NULL
#include <stddef.h>

void          _Exit(int) __attribute__((noreturn));
int           abs(int);
void          abort() __attribute__((noreturn));
double        atof(const char*);
int           atoi(const char*);
long int      atol(const char*);
void*         bsearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));
void*         calloc(size_t, size_t);
void          exit(int) __attribute__((noreturn));
void          free(void*);
char*         getenv(const char*);
long          labs(long);
long long     llabs(long long);
void*         malloc(size_t);
void          qsort(void*, size_t, size_t, int (*)(const void*, const void*));
void*         realloc(void*, size_t);
double        strtod(const char*, char**);
long int      strtol(const char*, char**, int);
long long int strtoll(const char*, char**, int);
unsigned long long int strtoull(const char*, char**, int);
