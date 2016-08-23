#undef assert

#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else
#define assert(__e) ((__e) ? ((void) 0) : __assert(#__e, __FILE__, __LINE__, __ASSERT_FUNCTION))
#endif

#ifndef __ASSERT_H
#define __ASSERT_H

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#define __ASSERT_FUNCTION __func__
#else
#define __ASSERT_FUNCTION  ((const char*) 0)
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && !defined(__cplusplus)
#define static_assert _Static_assert
#endif

void __assert(const char*, const char*, int, const char*) __attribute__((noreturn));

#endif
