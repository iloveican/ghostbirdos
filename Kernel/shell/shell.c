/*
 *Copyright 2013-2014 by Explorer Developer.
 *made by 迷彩红星<1@GhostBirdOS.org>
 *Explorer 原始调试界面
 *ExplorerOS\Kernel\shell\shell.c
 *version:Alpha
 *7/5/2014 7:08 PM
 */
 
#include "../include/shell.h"
#include "../include/macro.h"

struct shell{
	u32 x;
	u32 y;
	u32 width;
	u32 height;
	u32 cursor;
	u32 size;
	u32 color;
}shell;
void init_shell(void)
{
	shell.width = 80;
	shell.height = 25;
	shell.x = (xsize - (shell.width * 8))/2;
	shell.y = (ysize - (shell.height * 16))/2;
	shell.cursor = 0;
	shell.size = shell.width * shell.height;
	shell.color = 0xffffff;
	color(0xffff00);
	printk("Explorer 0.01\n");
	color(0xff0000);
	printk("Copyright 2013-2014 by Explorer Developer. All rights reserved.\n");
	color(0xffffff);
}
void debug(u32 *address, u32 size)
{
	printk("debug:from 0x%X to 0x%X is:\n", address, address+size);
	for (; size > 0; size -= 4)
	{
		printk("%X ",*address);
		address ++;
	}
}
/*设置颜色*/
void color(u32 color)
{
	shell.color = color;
}

/*输出字*/
void put_font(u8 ascii)
{
	if (shell.cursor >= shell.size) {
	return;
	}
	if (ascii == 0x0a | ascii == 0x0d)/*换行键\回车键的判断*/
	{
		shell.cursor -= (shell.cursor % shell.width);
		shell.cursor += shell.width;
		return;
	}else{
	/*由模拟文本模式参数到实际图形模式的转换*/
	u32 x, y;
	x = shell.x + (shell.cursor % shell.width) * 8;
	y = shell.y + (shell.cursor / shell.width) * 16;
	/*调用显示函数*/
	draw_font(x, y, shell.color, ascii);
	/*模拟光标指向下一个单位*/
	shell.cursor ++;
	}
}
/*显示字*/
void draw_font(u32 x, u32 y, u32 color, u32 ascii)
{
	u32 p, i, font_offset;/*字库偏移量*/
	u8 d;
	font_offset = ascii * 16;
	for (i = 0; i < 16; i++)
	{
		d = font[font_offset + i];
		if ((d & 0x80) != 0) { put_pix_24(x + 0, y + i, color); }
		if ((d & 0x40) != 0) { put_pix_24(x + 1, y + i, color); }
		if ((d & 0x20) != 0) { put_pix_24(x + 2, y + i, color); }
		if ((d & 0x10) != 0) { put_pix_24(x + 3, y + i, color); }
		if ((d & 0x08) != 0) { put_pix_24(x + 4, y + i, color); }
		if ((d & 0x04) != 0) { put_pix_24(x + 5, y + i, color); }
		if ((d & 0x02) != 0) { put_pix_24(x + 6, y + i, color); }
		if ((d & 0x01) != 0) { put_pix_24(x + 7, y + i, color); }
	}
}
