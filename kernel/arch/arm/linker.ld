ENTRY(_start)
SECTIONS
{
 . = 0x10000;
 .text : { 
           *(.text)
           *(.rodata*)
           . = ALIGN(4K);
         }

 .data : {
           *(.data)
           . = ALIGN(4K);
         }

 .bss : {
          *(.bss)
          . = ALIGN(4K);
        }
 . = . + 0x1000; /* 4kB of stack memory */
 stack_top = .;
 . = . + 0x1000; /* 4kB of stack memory */
 irq_stack_top = .;
 . = . + 0x1000; /* 4kB of stack memory */
 abort_stack_top = .;
}
