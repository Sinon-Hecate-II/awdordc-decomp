#ifndef COORDINATE_BITS_H
#define COORDINATE_BITS_H
typedef struct { unsigned int x:9; unsigned int y:9; unsigned int rest:14; } E9638Bits;
static inline void E9638Set(void *p,s16 x,s16 y,s32 a,s32 b) {
 M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y;
 M2C_FIELD(p,E9638Bits*,0x40).x=a; M2C_FIELD(p,E9638Bits*,0x40).y=b;
}
#endif
