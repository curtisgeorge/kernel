ENTRY(_start)
SECTIONS
{
  . = 1M;
  .text :
  {
    *(.text)
    *(.rotext)
    . = ALIGN(4K);
  }

  .data :
  {
    *(.data)
    . = ALIGN(4K);
  }

  .bss :
  {
    *(.bss)
    . = ALIGN(4K);
  }
}
