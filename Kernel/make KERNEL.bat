	@title Explorer OS LOADER build

:make
	cls
	@echo Copyright 2013-2014 Explorer OS Developer.All rights reserved. 
	@echo Explorer OS LOADER build.

	::各个文件编译
	@nasm loader\loader.asm -o tmp\loader.bin
	@nasm -f elf init\_start.asm -o tmp\_start.o
	@nasm -f elf shell\font.asm -o tmp\font.o
	@nasm -f elf shell\shell_asm.asm -o tmp\shell_asm.o
	@nasm -f elf HAL\x86\fun_asm.asm -o tmp\fun_asm.o
	@gcc -c init\main.c -o tmp\main.o
	@gcc -c shell\shell.c -o tmp\shell.o
	@gcc -c memory\memory.c -o tmp\memory.o
	@gcc -c drivers\hdd.c -o tmp\hdd.o
	@gcc -c drivers\vedio.c -o tmp\vedio.o
	@gcc -c HAL\x86\fun_c.c -o tmp\fun_c.o
	@gcc -c fs\fat32\fat32.c -o tmp\fat32.o
	@g++ -c C++\test.cpp -o tmp\test.o
	
	::各个文件链接
	@ld -o tmp\kernel.o	-Ttext 0x11000^
	tmp\_start.o tmp\main.o^
	tmp\shell.o tmp\font.o tmp\shell_asm.o^
	tmp\hdd.o tmp\vedio.o^
	tmp\memory.o tmp\fat32.o^
	tmp\fun_asm.o tmp\fun_c.o^
	tmp\test.o
	@objcopy -R .note -R .comment -S -O binary tmp\kernel.o tmp\kernel.bin

	::二进制复制
	@copy /B tmp\loader.bin + tmp\kernel.bin KERNEL
:_p
	@pause
	@goto make