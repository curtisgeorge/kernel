.globl _start
_start:
  // Set the stack pointer
  LDR sp, =stack_top
  // Call the kernel
  BL kmain
  // If we return from kmain pause the CPU
loop:
  MOV R0, #0
  MCR p15, 0, r0, c7, c0, 4
  // Infinite loop
  B loop

.globl interrupt_table_start
.globl interrupt_table_end
interrupt_table_start:
	b .
	b .
	ldr pc, swi_entry_address
	ldr pc, abort_entry_address
	ldr pc, abort_entry_address
	b .
	ldr pc, irq_entry_address
        b .
        
	swi_entry_address: .word swi_entry
        abort_entry_address: .word abort_entry
	irq_entry_address: .word irq_entry
interrupt_table_end:

swi_entry:
	b swi_handler

abort_entry:
        b handle_abort

irq_entry:
        sub r14, r14, #4
        push {r0-r12, lr}
        mov r0, sp
	bl dispatch_interrupts
        pop {r0-r12, lr}
        movs pc, lr
