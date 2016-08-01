ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=i386-elf-gcc
CFLAGS=-fno-asynchronous-unwind-tables
QEMU=qemu-system-i386 -enable-kvm -m 2 -kernel kernel
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=arm1176jzf-s
QEMU=qemu-system-arm -M versatilepb -cpu arm1176 -m 2 -serial stdio -kernel kernel
endif
CFLAGS+=-O2 -ffreestanding -Wall -Iinclude
ASFLAGS=$(CFLAGS)
LDFLAGS=-nostdlib -Wl,--build-id=none -T $(ARCHDIR)/linker.ld
OBJS=kernel.o

all: kernel

include $(ARCHDIR)/makefile.conf

kernel: $(OBJS)

qemu: kernel
	$(QEMU)

clean:
	rm -f kernel $(OBJS)
