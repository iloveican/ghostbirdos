#ifndef MEMORY_H
#define MEMORY_H

#include "../include/macro.h"

void inti_memory(void);
unsigned int kmalloc(unsigned int size);
void kfree(unsigned addr, unsigned int size);
unsigned int vremap(unsigned int vir_addr, unsigned int phy_addr, unsigned int size);
void kmemcpy(u8 *source, u8 *object, u32 count);

#endif