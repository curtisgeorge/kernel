CC=i386-elf-gcc
AR=i386-elf-ar
CFLAGS=-O2 -I../../include -Iinclude -Iinclude/arch/x86
OBJS=_exit.o printf.o

all: libc.a

libc.a: $(OBJS)
	$(AR) r libc.a $(OBJS)

clean:
	rm -rf libc.a $(OBJS)
