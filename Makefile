ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=gcc
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
endif
ifeq ($(ARCH),x86)
CFLAGS=-m32
else ifeq ($(ARCH),arm)
CFLAGS=-mcpu=arm926ej-s
endif
CFLAGS+=-ffreestanding -nostdlib -nostdinc -Wall -Iinclude
ASFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS) -Wl,--build-id=none -T $(ARCHDIR)/linker.ld
OBJS=kernel.o

all: kernel

include $(ARCHDIR)/makefile.conf

kernel: $(OBJS)

clean:
	rm -f kernel $(OBJS)
