/* 38 functions from 0x02088044 to 0x02088FF4 (main), found by ds-decomp. */
#include "common.h"

void func_020883bc(void) {
    M2C_UNK func_020883f0(M2C_UNK);
    extern M2C_UNK data_021577b4;
    s32 i;
    u8 *p;
    i = 0;
    p = (u8 *)&data_021577b4;
    do {
        *p++ = 0;
        i++;
    } while (i < 12);
    func_020883f0(0);
    func_020883f0(4);
}

void func_020884f8(u8 arg0) {
    s32 func_0200c408(M2C_UNK, s32);
    M2C_UNK func_020e349c();
    extern M2C_UNK data_0210259c;
    extern M2C_UNK data_021577b4;
    if (M2C_FIELD(&data_021577b4, u8 *, arg0) == 0) return;
    if (func_0200c408(0, ((s32 *)&data_0210259c)[arg0]) == 1) M2C_FIELD(&data_021577b4, u8 *, arg0) = 0;
    func_020e349c();
}

void func_0208853c(s32 arg0) {
    extern M2C_UNK data_02102590;
    s32 i;
    u8 *p;
    p = (u8 *)&data_02102590;
    i = 0;
    do {
        if ((*p & ((u8 *)&data_02102590)[arg0]) && func_0208858c((u8)i) != 0) func_020884f8(i);
        i++;
        p++;
    } while (i < 12);
}

s32 func_0208858c(s32 arg0) {
    extern M2C_UNK data_021577b4;
    return M2C_FIELD(&data_021577b4, u8 *, arg0);
}

void func_0208859c(void) {
    M2C_UNK func_020883f0(M2C_UNK);
    void func_0208853c(s32);
    s32 func_0208858c(M2C_UNK);
    if (func_0208858c(0) != 0) {
        return;
    }
    func_0208853c(0);
    func_020883f0(0);
}

void func_020885c4(void) {
    if (func_0208858c(2) != 0) {
        return;
    }
    func_0208853c(2);
    func_020883f0(2);
}

void func_020885ec(void) {
    func_020884f8(2);
}

void func_020885fc(void) {
    if (func_0208858c(3) != 0) {
        return;
    }
    func_0208853c(3);
    func_020883f0(3);
}

void func_02088624(void) {
    func_020884f8(3);
}

void func_02088634(void) {
    if (func_0208858c(4) != 0) {
        return;
    }
    func_0208853c(4);
    func_020883f0(4);
}

void func_0208865c(void) {
    if (func_0208858c(5) != 0) {
        return;
    }
    func_0208853c(5);
    func_020883f0(5);
}

void func_02088684(void) {
    if (func_0208858c(6) != 0) {
        return;
    }
    func_0208853c(6);
    func_020883f0(6);
}

void func_020886ac(void) {
    if (func_0208858c(7) != 0) {
        return;
    }
    func_0208853c(7);
    func_020883f0(7);
}

void func_020886d4(void) {
    if (func_0208858c(9) != 0) {
        return;
    }
    func_0208853c(9);
    func_020883f0(9);
}

void func_020886fc(void) {
    if (func_0208858c(0xA) != 0) {
        return;
    }
    func_0208853c(0xA);
    func_020883f0(0xA);
}

void func_02088724(void) {
    if (func_0208858c(1) != 0) {
        return;
    }
    func_0208853c(1);
    func_020883f0(1);
}

void func_0208874c(void) {
    if (func_0208858c(0xB) != 0) {
        return;
    }
    func_0208853c(0xB);
    func_020883f0(0xB);
}

void func_02088774(s32 a){void func_02007e20(void *,s32,s32);extern u8 data_021577c0[];extern void *gCur3DSpriteEngine;void *p=gCur3DSpriteEngine;u32 base=M2C_FIELD(p,s32 *,0x30);u32 offset=(a<<5)&~1;func_02007e20(data_021577c0,offset+base,32);}

void func_020887a8(void *p,s32 a,s32 b,s32 c,s32 d){void func_020887ec(void *);s32 x=M2C_FIELD(p,s16 *,0x34),y=M2C_FIELD(p,s16 *,0x36),z=M2C_FIELD(p,s8 *,0x49),w=M2C_FIELD(p,s32 *,0x44);M2C_FIELD(p,s16 *,0x34)=a;M2C_FIELD(p,s16 *,0x36)=b;M2C_FIELD(p,s8 *,0x49)=c;M2C_FIELD(p,s32 *,0x44)=d;func_020887ec(p);M2C_FIELD(p,s16 *,0x34)=x;M2C_FIELD(p,s16 *,0x36)=y;M2C_FIELD(p,s8 *,0x49)=z;M2C_FIELD(p,s32 *,0x44)=w;}

void func_02088d94(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~1) | 1);
}

void func_02088da8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) (M2C_FIELD(arg0, u8 *, 0x48) & ~1);
}

void func_02088db8(void *p,s32 a){void func_02088d94(void *);if(!a){func_02088d94(p);M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0xfc000000)|0x40000000;M2C_FIELD(p,u8 *,0x48)&=~0x30;return;}M2C_FIELD(p,u8 *,0x4b)=0;M2C_FIELD(p,u8 *,0x4a)=a;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0x30)|0x10;}

void func_02088e0c(void *p,s32 a){void func_02088da8(void *);if(!a){func_02088da8(p);M2C_FIELD(p,u32 *,0x40)&=~0xfc000000;M2C_FIELD(p,u8 *,0x48)&=~0x30;return;}M2C_FIELD(p,u8 *,0x4b)=0;M2C_FIELD(p,u8 *,0x4a)=a;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0x30)|0x20;}

void func_02088e5c(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x50) = arg1;
    M2C_FIELD(arg0, s16 *, 0x52) = arg2;
}

void func_02088e68(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4E) = arg1;
}

void func_02088e70(void *arg0, s16 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
    M2C_FIELD(arg0, s16 *, 0x56) = arg2;
}

void func_02088e7c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4F) = arg1;
}

void func_02088e84(void *p,s16 a,s16 b,s16 c,s32 d){func_02088e5c(p,a,b);func_02088e70(p,c,d);}

void func_02088ea8(void *p,s16 a,s32 b,s32 c,s32 d,s32 e){void func_02088f1c(void *);func_02088e5c(p,c,d);func_02088e70(p,a,b);func_02088e68(p,e);func_02088f1c(p);}

void func_02088eec(void *p,s8 a){void func_02088f1c(void *);func_02088e5c(p,M2C_FIELD(p,s16 *,0x50),M2C_FIELD(p,s16 *,0x52));func_02088e68(p,a);func_02088f1c(p);}

void func_02088f1c(void *p){if(!M2C_FIELD(p,u8 *,0x4e)){M2C_FIELD(p,s16 *,0x34)=M2C_FIELD(p,s16 *,0x50);M2C_FIELD(p,s16 *,0x36)=M2C_FIELD(p,s16 *,0x52);M2C_FIELD(p,s8 *,0x4d)=0;M2C_FIELD(p,u8 *,0x48)&=~0xc0;func_02088d94(p);return;}if(((u32)(M2C_FIELD(p,u8 *,0x48)<<24)>>30)==2)return;M2C_FIELD(p,s8 *,0x4c)=0;M2C_FIELD(p,s8 *,0x4d)=0;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0xc0)|0x80;}

void func_02088f8c(void *p,s32 a,s32 b,s16 c,s32 d,s32 e){void func_02088ff4(void *);func_02088e5c(p,a,b);func_02088e70(p,c,d);func_02088e7c(p,e);func_02088ff4(p);}

void func_02088fc4(void *p,s8 a){void func_02088ff4(void *);func_02088e70(p,M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x56));func_02088e7c(p,a);func_02088ff4(p);}

