/* 3 functions from 0x0203CB38 to 0x0203D910 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a, b; u16 c; s32 d; } UnkPacket;
extern u8 data_020ff88c[8];
void func_02007e54(int, void *, int);
void *func_02044268(void);
void func_0205e510(void *, int, void *);
void func_0205f83c(int, void *, int, void *);
int func_0206527c(void *, void *, int);

s32 func_0203d5d4(s32 unused, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    UnkPacket packet;
    u8 c;
    if (!arg4 || !arg3) return 0;
    func_02007e54(0,&packet,8);
    packet.b=2;
    packet.c=(u8)(arg2>>8)|((arg2<<8)&0xff00);
    packet.d=arg1;
    c=arg3[0];
    if ((c==0xfe && arg3[1]==0xfd)||c==0x5c) {
        if (M2C_FIELD(func_02044268(),s32 *,0x10))
            func_0205f83c(M2C_FIELD(func_02044268(),s32 *,0x10),arg3,arg4,&packet);
    } else if (!func_0206527c(arg3,data_020ff88c,6)) {
        func_0205e510(arg3,arg4,&packet);
    } else {
        switch(c) { case 0xfe: break; }
        return 0;
    }
    return 1;
}
