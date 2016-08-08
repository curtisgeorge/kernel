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
	ldr pc, syscall_entry_address
	ldr pc, abort_entry_address
	ldr pc, abort_entry_address
	b .
	ldr pc, irq_entry_address
        b .
        
	syscall_entry_address: .word syscall_entry
        abort_entry_address: .word abort_entry
	irq_entry_address: .word irq_entry
interrupt_table_end:

syscall_entry:
	b handle_syscall

abort_entry:
        b handle_abort

irq_entry:
	b dispatch_interrupts
