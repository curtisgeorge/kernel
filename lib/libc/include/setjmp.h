#pragma once

struct __jmp_buf_tag {
};

typedef struct __jmp_buf_tag jmp_buf[1];
typedef struct __jmp_buf_tag sigjmp_buf[1];

int setjmp(jmp_buf);
