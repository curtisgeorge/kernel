#pragma once

int isalnum(int);
int isalpha(int);
#if __STDC_VERSION__ >= 199901L
/**
 * C99 added isblank
 */
int isblank(int);
#endif
int iscntrl(int);
int isdigit(int);
int isgraph(int);
int islower(int);
int isprint(int);
int ispunct(int);
int isspace(int);
int isupper(int);
int isxdigit(int);
int tolower(int);
int toupper(int);
