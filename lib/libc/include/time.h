#pragma once

#include <sys/types.h>

struct tm {
};


size_t     strftime(char*, size_t, const char*, const struct tm*);
clock_t    clock();
time_t     time(time_t*);
struct tm* localtime(const time_t*);
