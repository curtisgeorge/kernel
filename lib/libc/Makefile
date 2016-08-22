ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=i386-elf-gcc
AR=i386-elf-ar
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar
endif
CFLAGS=-O2 -Wall -Iinclude -I../../kernel/include -I../../kernel/$(ARCHDIR)/include
SRCS := $(wildcard assert/*.c ctype/*.c dirent/*.c errno/*.c fcntl/*.c setjmp/*.c signal/*.c stdio/*.c stdlib/*.c string/*.c time/*.c sys/stat/*.c sys/times/*.c unistd/*.c)
OBJS := $(SRCS:%.c=%.o)

all: crt0.o libc.a

libc.a: $(OBJS)
	$(AR) r libc.a $(OBJS)

clean:
	rm -rf crt0.o libc.a $(OBJS)
