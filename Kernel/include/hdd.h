#ifndef HDD_H_
#define HDD_H_

#include "macro.h"

unsigned int LBA_start;
void inti_hdd(void);
void read_disk(u32 LBA, u16 *buffer, u32 number);
void hdd_wait(void);

#endif

