/* 53 functions from 0x02048B74 to 0x02049AB8 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 bytes[8]; } UnkSocketAddress;

/* GameSpy hashtable.c TableNew2: allocates a table of nBuckets bucket vectors
   (each an empty vector of elemSize-byte elements) and stores the caller's hash
   and comparison callbacks.  Table layout: +0x00 buckets, +0x04 count,
   +0x08 userData, +0x0C hashFn, +0x10 compFn. */

#pragma push
#pragma optimization_level 2
#pragma opt_if_conversion off

#pragma pop

/* Polls a single fd for readability/priority/error; sets output flags accordingly. */

#pragma opt_propagation off
s8 *StringToLower(s8 *p) {
    extern M2C_UNK data_020eac40;
    s8 *start = p;
    s32 c = *p;
    if (c) {
        do {
            if (c >= 0 && c < 128)
                c = ((const u8 *)&data_020eac40)[c];
            *p = c;
            c = *++p;
        } while (c);
    }
    return start;
}
#pragma opt_propagation reset
