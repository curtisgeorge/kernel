#pragma once

#define	__need_size_t
#include <stddef.h>

#ifdef __GNUC__
/**
 * This is not a POSIX function, but is used by GNUC
 */
void* alloca(size_t);
#endif
