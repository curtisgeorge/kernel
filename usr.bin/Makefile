ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=i386-elf-gcc
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
endif
CFLAGS=-O2 -I../include
LDFLAGS=-L../lib/libc
OBJS=crt0.o hello

all: $(OBJS)

clean:
	rm -rf $(OBJS)
