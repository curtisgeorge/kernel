int page_dir[1024] __attribute__((aligned(4096)));

void init_paging() {
  page_dir[0] = 0x00000083;
  int i;
  for(i = 1; i < 1024; i++) {
    page_dir[i] = 0;
  }

  asm volatile ("mov $(page_dir), %ecx\n \
                 mov %ecx, %cr3\n \
                 mov %cr4, %ecx\n \
                 or $0x00000010, %ecx\n \
                 mov %ecx, %cr4\n \
                 mov %cr0, %ecx\n \
                 or $0x80000000, %ecx\n \
                 mov %ecx, %cr0");
}
