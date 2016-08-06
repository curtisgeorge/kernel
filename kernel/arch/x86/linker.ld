ENTRY(_start)
SECTIONS
{
  . = 1M;
  .text :
  {
    *(.multiboot)
    *(.text)
    *(.rodata*)
    . = ALIGN(4K);
  }

  .data :
  {
    *(.data)
    . = ALIGN(4K);
  }

  .bss :
  {
    *(.stack)
    *(.bss)
    . = ALIGN(4K);
  }
}
