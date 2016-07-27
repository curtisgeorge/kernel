CC=gcc
CFLAGS=-m32 -O3 -ffreestanding -nostdlib -nostdinc -Wall -Iinclude
ASFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS)
OBJS=kernel.o

ARCH=x86
ARCHDIR=arch/$(ARCH)

LDFLAGS+=-T $(ARCHDIR)/linker.ld

include $(ARCHDIR)/makefile.conf

all: kernel

kernel: $(OBJS)

clean:
	rm -f kernel $(OBJS)
