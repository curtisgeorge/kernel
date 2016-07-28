ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=gcc
CFLAGS=-m32 -fno-asynchronous-unwind-tables
QEMU=qemu-system-i386 -enable-kvm -m 2 -kernel kernel
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=arm1176jzf-s
QEMU=qemu-system-arm -M versatilepb -cpu arm1176 -m 2 -nographic -kernel kernel
endif
CFLAGS+=-O2 -ffreestanding -nostdlib -nostdinc -Wall -Iinclude
ASFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS) -Wl,--build-id=none -T $(ARCHDIR)/linker.ld
OBJS=kernel.o

all: kernel

include $(ARCHDIR)/makefile.conf

kernel: $(OBJS)

qemu:
	$(QEMU)

clean:
	rm -f kernel $(OBJS)
