/* 4 functions from 0x0206CD20 to 0x0206CE00 (main), found by ds-decomp. */
#include "common.h"

s32 StringFormatWideToBuffer(u16 *buffer, u32 bufferCapacity, M2C_UNK format, M2C_UNK arguments) {
    s32 StringFormatWideWrite(WideFormatBuffer *, const u16 *, s32);
    s32 func_0206c3c8(s32 (*)(WideFormatBuffer *, const u16 *, s32), void *, M2C_UNK, M2C_UNK);
    WideFormatBuffer output;
    s32 result;

    /* Format into a bounded UTF-16 buffer, always terminate it, and report truncation as -1. */
    output.buffer = buffer;
    output.size = bufferCapacity;
    output.count = 0;
    result = func_0206c3c8(StringFormatWideWrite, &output, format, arguments);
    if (result < 0) return result;
    if ((u32)result < bufferCapacity) {
        buffer[result] = 0;
        return result;
    }
    (buffer + bufferCapacity)[-1] = 0;
    return -1;
}

s32 StringLengthWide(u16 *arg0) {
    s32 var_r2;
    u16 *var_r0;
    u16 temp_r1;
    var_r0 = arg0;
    var_r2 = -1;
    do {
        temp_r1 = *var_r0++;
        var_r2 += 1;
    } while (temp_r1 != 0);
    return var_r2;
}

u16 *StringCopyWide(u16 *arg0, u16 *arg1) {
    u16 *dest = arg0;
    while ((*dest++ = *arg1++) != 0) {}
    return arg0;
}

/* Find the first occurrence of wide character `ch` in the UTF-16 string `s` and
 * return a pointer to it (or to the terminator when `ch` is 0); NULL when `ch` is
 * not found. */
u16 *StringFindCharWide(u16 *s, s32 ch) {
    u16 c;
    while ((c = *s++) != 0) {
        if (c == ch) return s - 1;
    }
    if (ch != 0) return 0;
    return s - 1;
}

