#pragma once

#define NULL 0
#define EOF -1

typedef struct { int unused; } FILE;
typedef unsigned int size_t;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

int    fclose(FILE*);
FILE*  fopen(const char*, const char*);
int    fprintf(FILE*, const char*, ...);
int    fputc(int, FILE*);
int    fputs(const char*, FILE*);
size_t fwrite(const void*, size_t, size_t, FILE*);
int    getchar();
char*  gets(char*);
int    printf(const char*, ...);
int    putc(int, FILE*);
