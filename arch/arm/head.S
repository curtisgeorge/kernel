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

.globl interrupt_table_start
.globl interrupt_table_end
interrupt_table_start:
	nop
	subs pc, lr, #4
	ldr pc, syscall_entry_address
	subs pc, lr, #4
	subs pc, lr, #4
	subs pc, lr, #4
	ldr pc, irq_entry_address
	syscall_entry_address: .word syscall_entry
	irq_entry_address: .word irq_entry
interrupt_table_end:

syscall_entry:
	bl handle_syscall

irq_entry:
	bl dispatch_interrupts
