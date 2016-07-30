#ifndef ASM_H
#define ASM_H

static inline void copy_interrupt_table() {
  asm("mov r0, #0x0\n \
       ldr r1, =interrupt_table_start\n \
       ldr r3, =interrupt_table_end\n \
       copy_loop_start:\n \
       ldr r2, [r1, #0x0]\n \
       str r2, [r0, #0x0]\n \
       add r0, r0, #0x4\n \
       add r1, r1, #0x4\n \
       cmp r1, r3\n \
       bne copy_loop_start");
}

#endif
