/* The CodeWarrior C++ exception tables.
 *
 * __exception_table_start__ .. __exception_table_end__ hold 12-byte entries,
 * one per function that has a handler or cleanup, sorted by start address.
 * An entry's data block begins with two variable-length values followed by the
 * per-address ranges: each variable-length value stores 2 bits of length in
 * its first byte and the remaining bits compactly.
 */
#ifndef CPP_EXCEPTION_H
#define CPP_EXCEPTION_H

/* One 12-byte entry of the exception table. */
typedef struct CppExceptionEntry {
    s32 start; /* +0x00 start address of the covered function */
    u32 range; /* +0x04 length of the covered range; bit 0 = data stored inline at +0x08 */
    u32 data;  /* +0x08 handler-data address, or the inline data when bit 0 of range is set */
} CppExceptionEntry;

/* CppExceptionEntry.range bit: the handler data is inline in the entry, at +0x08. */
#define CPP_EXCEPTION_INLINE_DATA 0x01

/* What FindExceptionTableHandler leaves in the caller's lookup state. */
typedef struct CppExceptionState {
    s32  start;      /* +0x00 start address of the matching table entry */
    void *data;      /* +0x04 handler data of the matching entry, or 0 */
    void *handler;   /* +0x08 handler address inside that data, or 0 */
    u32  *tableStart;/* +0x0C first exception table entry */
    u32  *tableEnd;  /* +0x10 past the last exception table entry */
} CppExceptionState; /* 0x14 bytes */

#endif
