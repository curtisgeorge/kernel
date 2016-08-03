CC=i386-elf-g++
CXX=$(CC)
CFLAGS=-O2 -ffreestanding -nostdlib -Wall -Iinclude
CXXFLAGS=$(CFLAGS)
ASFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS)
OBJS=kernel.o
QEMU=qemu-system-i386 -m 2 -kernel kernel

ARCH=x86
ARCHDIR=arch/$(ARCH)

LDFLAGS+=-T $(ARCHDIR)/linker.ld

include $(ARCHDIR)/makefile.conf

all: kernel

kernel: $(OBJS)

qemu: kernel
	$(QEMU)

clean:
	rm -f kernel $(OBJS)
