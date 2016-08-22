#pragma once

#define __need_size_t
#define __need_NULL
#include <stddef.h>
#include <stdarg.h>

#define BUFSIZ 1024

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define EOF -1

typedef struct {
  short _file;
} FILE;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

void   clearerr(FILE*);
int    fclose(FILE*);
int    feof(FILE*);
int    fflush(FILE*);
char*  fgets(char*, int, FILE*);
FILE*  fopen(const char*, const char*);
int    fprintf(FILE*, const char*, ...);
int    fputc(int, FILE*);
int    fputs(const char*, FILE*);
int    fscanf(FILE*, const char*, ...);
size_t fwrite(const void*, size_t, size_t, FILE*);
int    getc(FILE*);
int    getchar();
char*  gets(char*);
int    printf(const char*, ...);
int    putc(int, FILE*);
int    sprintf(char*, const char*, ...);
int    ungetc(int, FILE*);
int    vfprintf(FILE*, const char*, va_list);
int    vprintf(const char*, va_list);

int    fileno(FILE*);
