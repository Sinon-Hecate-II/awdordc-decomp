#ifndef TOUCH_PANEL_H
#define TOUCH_PANEL_H

#include "common.h"

enum {
    PXI_FIFO_TAG_TOUCHPANEL = 6,
    PXI_PROC_ARM7 = 1
};

typedef struct {
    u16 initialized;                      /* +0x00 */
    u16 pad02;                     /* +0x02 */
    void (*callback)(s32,s32,s32); /* +0x04 */
    u16 sample[4];                 /* +0x08 */
    u16 sampleIndex;                     /* +0x10 */
    u16 sampleInterval;            /* +0x12 */
    void *sampleBuffer;                 /* +0x14 */
    u16 capacity;                  /* +0x18 */
    u16 pad1A;                     /* +0x1A */
    s32 calXOffset;                /* +0x1C calibration x offset */
    s32 calXRange;                 /* +0x20 calibration x range */
    s32 calXScale;                 /* +0x24 1<<28 divided by the x range */
    s32 calYOffset;                /* +0x28 calibration y offset */
    s32 calYRange;                 /* +0x2C calibration y range */
    s32 calYScale;                 /* +0x30 1<<28 divided by the y range */
    u16 calibrated;                /* +0x34 nonzero once calibration is set */
    u16 samplingMode;                     /* +0x36 */
    u16 flags38;                   /* +0x38 bit per touch command that failed */
    u16 flags3a;                   /* +0x3A bit per touch command in flight */
} TouchState;

#endif
