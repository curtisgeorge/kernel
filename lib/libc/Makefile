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
SRCS := $(wildcard ctype/*.c errno/*.c stdio/*.c stdlib/*.c unistd/*.c)
OBJS := $(SRCS:%.c=%.o)

all: libc.a

libc.a: $(OBJS)
	$(AR) r libc.a $(OBJS)

clean:
	rm -rf libc.a $(OBJS)
