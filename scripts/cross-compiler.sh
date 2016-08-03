#!/bin/bash
export PREFIX="$HOME/usr/local"
# TARGET should be one of i386-elf, i686-elf, x86_64-elf, arm-none-eabi, arm-elf
export TARGET=arm-none-eabi
export PATH="$PREFIX/bin:$PATH"

tar xzvf binutils-2.25.tar.gz
cd binutils-2.25
mkdir build
cd build
../configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

cd ../..
tar xzvf gcc-5.3.0.tar.gz
cd gcc-5.3.0
mkdir build
cd build
../configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
#make all-gcc
#make all-target-libgcc
#make install-gcc
#make install-target-libgcc
make all-host
make install-host
