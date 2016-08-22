ARCH?=x86
ARCHDIR=arch/$(ARCH)

ifeq ($(ARCH),x86)
CC=i386-elf-gcc
else ifeq ($(ARCH),arm)
CC=arm-none-eabi-gcc
endif
OBJS=hello

all: $(OBJS)

clean:
	rm -rf $(OBJS)
