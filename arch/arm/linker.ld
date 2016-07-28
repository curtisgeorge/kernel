ENTRY(_start)
SECTIONS
{
 . = 0x10000;
 .text : { *(.text) }
 .data : { *(.data) }
 .bss : { *(.bss) }
 . = . + 0x1000; /* 4kB of stack memory */
 stack_top = .;
}
