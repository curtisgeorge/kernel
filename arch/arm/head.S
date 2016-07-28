.globl _start
_start:
  LDR sp, =stack_top
  BL kmain
  B .
