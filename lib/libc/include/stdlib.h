#pragma once

#define __need_size_t
#define __need_wchar_t
#define __need_NULL
#include <stddef.h>

typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long quot;
  long rem;
} ldiv_t;

typedef struct {
  long long quot;
  long long rem;
} lldiv_t;

void          _Exit(int) __attribute__((noreturn));
long          a64l(const char*);
void          abort() __attribute__((noreturn));
int           abs(int);
int           atexit(void (*)(void));
double        atof(const char*);
int           atoi(const char*);
long int      atol(const char*);
long long int atoll(const char*);
void*         bsearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));
void*         calloc(size_t, size_t);
div_t         div(int, int);
double        drand48();
double        erand48(unsigned short [3]);
void          exit(int) __attribute__((noreturn));
void          free(void*);
char*         getenv(const char*);
int           getsubopt(char**, char *const, char**);
int           grantpt(int);
char*         initstate(unsigned int, char*, size_t);
long          jrand48(unsigned short [3]);
char*         l64a(long);
long          labs(long);
void          lcong48(unsigned short [7]);
ldiv_t        ldiv(long, long);
long long int llabs(long long);
lldiv_t       lldiv(long long, long long);
long          lrand48();
void*         malloc(size_t);
int           mblen(const char*, size_t);
size_t        mbstowcs(wchar_t*, const char*, size_t);
int           mbtowc(wchar_t*, const char*, size_t);
char*         mkdtemp(char*);
int           mkstemp(char*);
long          mrand48();
void          qsort(void*, size_t, size_t, int (*)(const void*, const void*));
void*         realloc(void*, size_t);
double        strtod(const char*, char**);
long int      strtol(const char*, char**, int);
long long int strtoll(const char*, char**, int);
unsigned long long int strtoull(const char*, char**, int);
