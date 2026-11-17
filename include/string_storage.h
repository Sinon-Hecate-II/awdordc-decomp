#ifndef STRING_STORAGE_H
#define STRING_STORAGE_H
#include "common.h"
typedef union { struct { u32 flag:1; u32 capacity:31; u32 length; u8 *data; } large; struct { u8 flag:1; u8 length:7; u8 data[11]; } small; } StringStorage;
#endif
