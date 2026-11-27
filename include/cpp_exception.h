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

/* The game's C++ exception table, as built by the linker: the default
 * __FindExceptionTable reports it as covering every address. */
extern u8 __exception_table_start__, __exception_table_end__;

/* One 12-byte entry of the exception table. */
typedef struct CppExceptionEntry {
    s32 start; /* +0x00 start address of the covered function */
    u32 range; /* +0x04 length of the covered range; bit 0 = data stored inline at +0x08 */
    u32 data;  /* +0x08 handler-data address, or the inline data when bit 0 of range is set */
} CppExceptionEntry;

/* CppExceptionEntry.range bit: the handler data is inline in the entry, at +0x08. */
#define CPP_EXCEPTION_INLINE_DATA 0x01

/* Length bits of a compact exception-table value, from its first byte: bit 0 set
 * means at least one more byte follows, bit 1 two more, bit 2 three more (a
 * four-byte value). The first byte's remaining high bits are the value's most
 * significant bits and the following bytes follow little-endian. */
#define CPP_EXCEPTION_VALUE_LONG2 0x01 /* one more byte follows */
#define CPP_EXCEPTION_VALUE_LONG3 0x02 /* two more bytes follow */
#define CPP_EXCEPTION_VALUE_LONG4 0x04 /* three more bytes follow */

/* What FindExceptionTableHandler leaves in the caller's lookup state. */
typedef struct CppExceptionState {
    s32  start;      /* +0x00 start address of the matching table entry */
    void *data;      /* +0x04 handler data of the matching entry, or 0 */
    void *handler;   /* +0x08 handler address inside that data, or 0 */
    u32  *tableStart;/* +0x0C first exception table entry */
    u32  *tableEnd;  /* +0x10 past the last exception table entry */
} CppExceptionState; /* 0x14 bytes */

/* The decoded exception context the catch-type matcher walks: the number of
 * thrown type names and, at +0x0C, the addresses of their strings. */
#define CPP_EXCEPTION_TYPE_COUNT 0x00 /* u32: number of thrown type names */
#define CPP_EXCEPTION_TYPE_NAMES 0x0C /* u8 *: packed addresses of the type-name strings */

/* A CodeWarrior C++ type_info object (e.g. gTypeInfoDefaultDeleteCharArray, the one for
 * `std::detail::default_delete<char []>`): its virtual table pointer at +0x00
 * (destructor / deleting destructor) and the mangled type name at +0x04.
 * type_info equality compares the names. */
typedef struct TypeInfo {
    void **vtable; /* +0x00 virtual table */
    char *name;    /* +0x04 mangled type name string */
} TypeInfo;

/* The C++ runtime's global handler table gCppExceptionHandlers: std::terminate
 * dispatches to the first entry and std::unexpected to the second.  The default
 * unexpected handler calls std::terminate; the game's terminate handler flushes
 * the socket events (ForceFlushSocketEvents). */
#define CPP_TERMINATE_HANDLER  0x00 /* void (*)(void) */
#define CPP_UNEXPECTED_HANDLER 0x04 /* void (*)(void) */

#endif
