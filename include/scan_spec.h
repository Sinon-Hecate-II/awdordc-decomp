#ifndef SCAN_SPEC_H
#define SCAN_SPEC_H
#include "common.h"
typedef struct ScanSpec677b8 { u8 suppress, hasWidth, length, conversion; s32 width; u8 set[32]; } ScanSpec677b8;

/* State of the C-string reader the scanf-family parsers drive
 * (ScanFloatStreamRead): the next character to hand out and a flag set once the
 * terminating NUL has been reached. */
typedef struct ScanStream {
    s8 *ptr; /* +0x00 next character of the string */
    s32 eof; /* +0x04 set once ptr has run past the terminating NUL */
} ScanStream;

/* Operations a ScanStream reader understands: READ returns and consumes the next
 * character (-1 at the end), PUSH_BACK puts one back, IS_END reports the flag. */
enum {
    SCAN_STREAM_READ      = 0,
    SCAN_STREAM_PUSH_BACK = 1,
    SCAN_STREAM_IS_END    = 2
};
#endif
