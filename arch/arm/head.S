.globl _start
_start:
  // Set the stack pointer
  LDR sp, =stack_top
  // Call the kernel
  BL kmain
  // If we return from kmain pause the CPU
  MOV R0, #0
  MCR p15, 0, r0, c7, c0, 4
  // Infinite loop
  B .
