#Copyright 2013-2014 by Exploerer Developer.
#made by ����<2@GhostBirdOS.org> BeatMicrosoft<BeatMicrosoft@GhostBirdOS.org>
#Explorer 0.01 Kernel makefile
#version:Alpha
#7/22/2014 8:16 AM

CFLAGS=-m32
LFLAGS=-m elf_i386
all:
	nasm loader/LOADER.asm -o tmp/loader.bin 
	nasm -f elf init/_start.asm -o tmp/_start.o 
	nasm -f elf shell/font.asm -o tmp/font.o
	nasm -f elf shell/shell_asm.asm -o tmp/shell_asm.o
	nasm -f elf HAL/x86/fun_asm.asm -o tmp/fun_asm.o
	gcc -c init/main.c -o tmp/main.o $(CFLAGS)
	gcc -c shell/shell.c -o tmp/shell.o $(CFLAGS)
	gcc -c memory/memory.c -o tmp/memory.o $(CFLAGS)
	gcc -c drivers/hdd.c -o tmp/hdd.o $(CFLAGS)
	gcc -c drivers/vedio.c -o tmp/vedio.o $(CFLAGS)
	gcc -c HAL/x86/fun_c.c -o tmp/fun_c.o $(CFLAGS)
	gcc -c fs/fat32/fat32.c -o tmp/fat32.o $(CFLAGS)
	g++ -c C++/test.cpp -o tmp/test.o   $(CFLAGS)

	ld  $(LFLAGS) -s -o tmp/kernel.o	-Ttext 0x11000 \
	tmp/_start.o tmp/main.o \
	tmp/shell.o tmp/font.o tmp/shell_asm.o \
	tmp/hdd.o tmp/vedio.o \
	tmp/memory.o tmp/fat32.o \
	tmp/fun_asm.o tmp/fun_c.o \
	tmp/test.o
	objcopy -R .note -R .comment -S -O binary tmp/kernel.o tmp/kernel.bin
	cat tmp/loader.bin >> tmp/kernel.bin 
	cp  tmp/kernel.bin ../KERNEL

clean:
	cd tmp && rm  -f *.o
