#pragma once

#define setjmp(env) _setjmp(env)

struct __jmp_buf_tag {
};

typedef struct __jmp_buf_tag jmp_buf[1];
typedef struct __jmp_buf_tag sigjmp_buf[1];

void longjmp(jmp_buf, int);

int  _setjmp(jmp_buf);
