/*made by 迷彩红星<1@ghostbirdos.org>
 *返回指定文件的元数据
 *入口：(路径)文件名，保存元数据的结构体首地址
 *NOTE:目前获取元数据的函数仅仅支持根目录下的大写文件！
 */
void file_open(u8 *name, int addr)
{
	/*处理文件路径：使nasm指向第一个不为"\"或者"/"的字符*/
	if (*name == 92 | *name == 47)/*"\"字符ASCII是92*/
	{
		name += 1;
	}
	/*读取根目录*/
	u32 table_point, offset_point, sector, clu, ret_clu;
	u8 *root_point;
	root_point = (u8 *) kmalloc(PBR1.cluster_size * 512);/*512Byte是一个标准磁盘扇区的大小，乘上每个簇包含扇区的数量得一个簇的大小*/
	for (clu = PBR1.root_start; (clu & 0x0FFFFFF0) != 0x0FFFFFF0;)
	{
		sector = clu_to_sector(clu);
		read_disk(sector, (u16*) root_point, PBR1.cluster_size);
		for (table_point = 0; table_point <= (PBR1.cluster_size * 512); table_point += 32)		/*目录项每项32Byte*/
		{
			for (offset_point = 0; offset_point < 8; offset_point ++)
			{
				if (root_point[table_point + offset_point] != name[offset_point])
				{
					goto next_table;
				}
			}
			/*到这里代表已经匹配完成*/
			printk("found file.");
			kmemcpy((root_point + table_point + 0x14), (&(ret_clu) + 2), 2);
			kmemcpy((root_point + table_point + 0x1a), &(ret_clu), 2);
			printk("ret_clu = 0x%X",ret_clu);
			return;
			next_table:
		}
		clu = get_next_clu(clu);
	}
	printk("Not found file.");
	io_hlt();
}











for (offset_point = 0; root_point[table_point + offset_point] == name[offset_point]; offset_point ++)
			{
				if (offset_point == 7 |  | name[offset_point + 1] = 0)/*如果偏移到了第8个字节或者路径字符串后面个字是"."或者是NUL就代表文件名匹配完成*/
				{
					/*匹配后缀*/
					if (name[offset_point + 1] == 46
				}else if ()
				if (name[offset_point + 1] == 46)
				{
					/*有后缀名*/
					if (root_point[table_point + offset_point + 1] == name[offset_point + 2] &
						root_point[table_point + offset_point + 2] == name[offset_point + 3] &
						root_point[table_point + offset_point + 3] == name[offset_point + 4])
					{
						printk("found file.");
						kmemcpy((root_point + table_point + 0x14), (&(ret_clu) + 2), 2);
						kmemcpy((root_point + table_point + 0x1a), &(ret_clu), 2);
						printk("ret_clu = 0x%X",ret_clu);
						return ret_clu;
					}
				}
				if (name[offset_point + 1] == 46 | )/*如果该字符后面是个"."或者是0x00，就代表已经到文件名的底了
				{
					/*到这里文件名已经识别正确，但是还未识别文件扩展名*/
					if (root_point[table_point +8)
					/*到这里代表已经匹配完成*/
					printk("found file.");
					kmemcpy((root_point + table_point + 0x14), (&(ret_clu) + 2), 2);
					kmemcpy((root_point + table_point + 0x1a), &(ret_clu), 2);
					printk("ret_clu = 0x%X",ret_clu);
					return ret_clu;
				}
			}
			
			
			
			
			
/*文件名字解剖*/
	u32 name_start, name_end, exname_start, exname_end;
	/*exname_end指向最后个字符*/
	for (exname_end = 0; name[exname_end] != 0; exname_end ++)
	{
	}
	/*exname_start指向最后个字符开始往前一直到"."的位置前一个单位*/
	for (exname_start = exname_end; name[exname_start - 1] != 46 && exname_start != 0; exname_start --)
	{
	}
	if (exname_start == 0)/*如果等于0就代表没有后缀*/
	{
		exname_start = exname_end;/*，如果exname_start = exname_end，则没有后缀名*/
		name_end = exname_start;
	}else{/*这里则有后缀*/
	name_end = (exname_start - 2);/*文件名指针指向文件名结尾，在后缀开始处前面的点的前面^.^*/
	}
	name_start = name_end;
	/*由于本来name就指定了文件的首地址，所以name_start = 0*/
	name_start = 0;
			
			
			
			
			
			
			
			
/*8.3短文件名匹配*/
			for (offset_point = 0; root_point[table_point + offset_point] == name[offset_point + name_start] && ((offset_point + name_start) <= name_end); offset_point ++)
			{
			}
			if ((offset_point + name_start) == name_end)
			{
				/*文件名匹配，后缀名还未匹配*/
				printk("found file.");
				kmemcpy((root_point + table_point + 0x14), (&(ret_clu) + 2), 2);
				kmemcpy((root_point + table_point + 0x1a), &(ret_clu), 2);
				printk("ret_clu = 0x%X",ret_clu);
				return ret_clu;
			}
			/*到这里就代表这个表项不是，到下个表项寻找*/	