CC=gcc
CFLAGS=-m32 -ffreestanding -nostdlib -nostdinc -Wall -Iinclude
ASFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS) -Wl,--build-id=none
OBJS=kernel.o

ARCH=x86
ARCHDIR=arch/$(ARCH)

LDFLAGS+=-T $(ARCHDIR)/linker.ld

all: kernel

include $(ARCHDIR)/makefile.conf

kernel: $(OBJS)

clean:
	rm -f kernel $(OBJS)
