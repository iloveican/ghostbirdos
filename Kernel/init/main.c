/*
 *Copyright 2013-2014 by Explorer Developer.
 *made by √‘≤ ∫Ï–«<1@GhostBirdOS.org>
 *Explorer ÷˜∫Ø ˝
 *ExplorerOS\Kernel\init\main.c
 *version:Alpha
 *--
 */

#include "../include/fat32.h"

void main(void)
{
	init_arch();
	init_memory();
	init_graph();
	init_shell();
	init_hdd();
	init_FAT32();
	/*≤‚ ‘C++∫Ø ˝*/
	test_C_plus_plus();
	/*º”‘ÿÕº∆¨≤‚ ‘*/
	/* ‘º”‘ÿBACKDROP.PIC*/
	file_info BACKDROP_PIC;
	BACKDROP_PIC = get_file_info("BACKDROP.PIC");
	printk("BACKDROP.PIC size:0x%X,start:0x%X\n", BACKDROP_PIC.size, BACKDROP_PIC.start);
	u32 BACKDROP_PIC_point = kmalloc(BACKDROP_PIC.size);
	load_data(0xe0000000, BACKDROP_PIC.start);
	//file_open("TESTDROP.PIC", 0xe0000000);//BACKDROP_PIC_point
	//printk("load file success.\n");
	debug((0xe0000000), 512);
	//extern vram;
	//kmemcpy(BACKDROP_PIC_point, 0xe0000000, BACKDROP_PIC.size);
}
