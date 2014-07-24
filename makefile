#Copyright 2013-2014 by Exploerer Developer.
#made by цвсм<2@GhostBirdOS.org> BeatMicrosoft<BeatMicrosoft@GhostBirdOS.org>
#Explorer 0.01 makefile
#version:Alpha
#7/22/2014 8:17 AM

all:
	cd Boot && make 
	cd Kernel && make 
	sudo mount -o loop os.img /mnt
	sudo cp KERNEL  /mnt
	sudo umount /mnt
	

run:
	qemu-system-i386 -fda os.img
