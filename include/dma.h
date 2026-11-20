#ifndef DMA_H
#define DMA_H
#include "common.h"

/* DMA controller of the ARM9.  A channel's source, destination and control
 * registers sit 12 bytes apart from 0x040000B0, and the value a fill repeats is
 * four bytes a channel from 0x040000E0. */
#define DMA_CHANNEL_BASE(ch) (0x040000B0 + (ch) * 12) /* s32[3]: source, destination, control */
#define DMA_CHANNEL_CTRL(ch) (0x040000B0 + ((ch) * 3 + 2) * 4) /* s32 control word; written this way to keep the ARM multiply short */
#define DMA_FILL_REG(ch)     (0x040000E0 + (ch) * 4)  /* u32 value a fill writes out */

/* Fields of a channel's control word (DMA_CHANNEL_BASE(ch) + 8).  Bit 31 is the
 * channel-running bit and bits 27..29 are the transfer mode the channel was
 * started in; the conflict check only lets channels run together when their
 * modes are compatible, otherwise the transfer would be corrupted. */
#define DMA_CTRL_ENABLE 0x80000000 /* bit 31: the channel is enabled */
#define DMA_CTRL_MODE   0x38000000 /* bits 27..29: the channel's transfer mode */

/* Control word of a 32-bit fill: the fill-value register is the fixed source, the
 * destination increments, and the word count goes in the low bits. */
#define DMA_FILL_CTRL(size)     (((size) >> 2) | 0x85000000)
/* The same fill with the channel's end-of-transfer interrupt enabled. */
#define DMA_FILL_CTRL_IRQ(size) (((size) >> 2) | 0xC5000000)

/* Control word of a 32-bit memory copy: both addresses increment. */
#define DMA_COPY_CTRL(size)     (((size) >> 2) | 0x84000000)
/* The same copy with the channel's end-of-transfer interrupt enabled. */
#define DMA_COPY_CTRL_IRQ(size) (((size) >> 2) | 0xC4000000)
#endif
