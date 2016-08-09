ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=i386-elf-gcc
AR=i386-elf-ar
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar
endif
CFLAGS=-O2 -Wall -I../../include -I../../kernel/include -I../../kernel/$(ARCHDIR)/include
OBJS=_exit.o execve.o fork.o getchar.o gets.o printf.o

all: libc.a

libc.a: $(OBJS)
	$(AR) r libc.a $(OBJS)

clean:
	rm -rf libc.a $(OBJS)
