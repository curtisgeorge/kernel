ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=i386-elf-g++
QEMU=qemu-system-i386 -enable-kvm -m 2 -kernel kernel
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-g++
CFLAGS=-mcpu=arm1176jzf-s
QEMU=qemu-system-arm -M versatilepb -cpu arm926 -m 2 -nographic -kernel kernel
endif
CXX=$(CC)
CFLAGS+=-ffreestanding -nostdlib -Wall -Iinclude
CXXFLAGS=$(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS) -Wl,--build-id=none -T $(ARCHDIR)/linker.ld -lgcc
OBJS=kernel.o

all: kernel

include $(ARCHDIR)/makefile.conf

kernel: $(OBJS)

qemu: kernel
	$(QEMU)

clean:
	rm -f kernel $(OBJS)
