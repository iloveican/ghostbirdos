#Copyright 2013-2014 by Exploerer Developer.
#made by цвсм<2@GhostBirdOS.org> BeatMicrosoft<BeatMicrosoft@GhostBirdOS.org>
#Explorer 0.01 Boot makefile
#version:Alpha
#7/22/2014 8:17 AM

all:
	nasm boot.asm -o boot.bin
	cp  boot.bin os.img
	dd if=/dev/zero of=os.img seek=2 count=2879	
	cp os.img ../
