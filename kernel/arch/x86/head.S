.section .multiboot
.align 4
.long 0x1BADB002
.long 0x00
.long -(0x1BADB002 + 0x00)

.text
.globl _start
_start:
  cli
  mov $stack_top, %esp
  call kmain
loop:
  hlt
  jmp loop

.bss
stack_bottom:
.skip 8192
stack_top:
