#ifndef DMA_H
#define DMA_H
#include "common.h"

/* DMA controller of the ARM9.  A channel's source, destination and control
 * registers sit 12 bytes apart from 0x040000B0, and the value a fill repeats is
 * four bytes a channel from 0x040000E0. */
#define DMA_CHANNEL_BASE(ch) (0x040000B0 + (ch) * 12) /* s32[3]: source, destination, control */
#define DMA_FILL_REG(ch)     (0x040000E0 + (ch) * 4)  /* u32 value a fill writes out */

/* Control word of a 32-bit fill: the fill-value register is the fixed source, the
 * destination increments, and the word count goes in the low bits. */
#define DMA_FILL_CTRL(size)     (((size) >> 2) | 0x85000000)
/* The same fill with the channel's end-of-transfer interrupt enabled. */
#define DMA_FILL_CTRL_IRQ(size) (((size) >> 2) | 0xC5000000)

#endif
