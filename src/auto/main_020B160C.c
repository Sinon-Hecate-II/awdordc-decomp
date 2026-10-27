/* 44 functions from 0x020B160C to 0x020B25B8 (main), found by ds-decomp. */
#include "common.h"

void func_020b160c(void){
s32 func_020a7290(void);void *func_020a7278(void);void *func_020a7284(void);
M2C_UNK func_02007ef4(M2C_UNK *,s32,M2C_UNK);void func_01ff9e44(void *,s32,s32);void func_020c09c0(s32);
extern void *gCur3DSpriteEngine;extern void *gCurrentMap;extern u8 data_02120a20[];
s32 n;void *p;
n=func_020a7290()<<5;p=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0x10);
func_02007ef4(func_020a7278(),p+0x25c0,n);
p=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0x10)+0x4e0;
func_02007ef4(func_020a7284(),p+0x3000,0x3c0);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,26701)-1)*32,384,32);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,26841)-1)*32,416,32);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,26981)-1)*32,448,32);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,27121)-1)*32,480,32);
func_020c09c0(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4));}

void func_020b172c(void) {
    M2C_UNK func_02091d20();
    M2C_UNK func_020d672c();
    M2C_UNK func_ov000_02169368();
    extern void *gCurrentMap;
    M2C_UNK (*temp_r2)(u8, u8);
    void *temp_r0;

    func_ov000_02169368();
    func_02091d20();
    func_020d672c();
    temp_r2 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(u8, u8), 0x58);
    if (temp_r2 == NULL) {
        return;
    }
    temp_r0 = M2C_FIELD(gCurrentMap, void **, 0);
    temp_r2(M2C_FIELD(temp_r0, u8 *, 0x5158), M2C_FIELD(temp_r0, u8 *, 0x5157));
}

void func_020b1770(void) {
    M2C_UNK func_02007ef4(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_020f3ca0;
    extern void *gCur3DSpriteEngine;
    func_02007ef4(&data_020f3ca0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC) + 0x2480, 0xA0);
}

void func_020b179c(void) {
    M2C_UNK func_02007ef4(M2C_UNK *,s32,M2C_UNK);
    M2C_UNK func_020c0a88();
    extern void *gCur3DSpriteEngine;
    func_02007ef4((M2C_UNK *)M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x10),0x800);
    func_02007ef4((M2C_UNK *)M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x14),0x800);
    func_020c0a88();
}

void func_020b17dc(void) {
    M2C_UNK func_0207a768();
    M2C_UNK func_020cfd28();
    func_020cfd28();
    func_0207a768();
}

void func_020b17ec(void) {
    void func_020b1800(void);
    M2C_UNK func_02002bb8(M2C_UNK);
    func_020b1800();
    func_02002bb8(0x40);
}

void func_020b1800(void) {
    M2C_UNK func_02003584();
    M2C_UNK func_02003560();
    func_02003560();
    func_02003584();
}

void func_020b1810(void) {
    M2C_UNK func_020026d8(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002bb8(M2C_UNK);
    M2C_UNK func_02002c64(M2C_UNK);
    M2C_UNK func_02002e3c(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_02082c84();
    func_02082c84();
    func_02002c64(3);
    func_020026d8(8);
    func_02002968(0x10);
    func_02002e3c(0x20);
    func_02002bb8(0x40);
    func_02003124(4);
    func_020031cc(0x100);
    func_0200323c(0x80);
}

void func_020b185c(void) {
    extern void *gCurrentMap, *gCur3DSpriteEngine, *data_027e00c8;
    void *saved;
    void (*callback)(void);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_020aca8c(3);
    func_0207b84c();
    func_02077a7c();
    func_02082700();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x1c);
    if (callback != NULL) callback();
    func_02091cd0();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);
    if (callback != NULL) callback();
    func_020b172c();
    func_020b179c();
    func_020b17dc();
    func_01ff9e00();
    gCur3DSpriteEngine = saved;
}

void func_020b18ec(void) {
    extern void *gCurrentMap, *gCur3DSpriteEngine;
    u16 *sp4;
    u16 *sp0;
    void (*callback)(void);
    func_020aca8c(3);
    func_0207b940();
    sp4 = M2C_FIELD(gCur3DSpriteEngine,u16 **,0);
    *sp4 = *sp4 | 0x1000;
    sp0 = M2C_FIELD(gCur3DSpriteEngine,u16 **,0);
    *sp0 = *sp0 & ~0x6000;
    func_02082700();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x1c);
    if (callback != NULL) callback();
    func_01ff9b38();
    func_02091cd0();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);
    if (callback != NULL) callback();
    func_020b1770();
    func_020b172c();
    func_020b179c();
    func_020b17dc();
}

void func_020b19a8(s32 arg0, s32 arg1) {
    M2C_UNK func_01ff9e78(void *, s32, M2C_UNK);
    extern u8 data_020f3c20[];
    func_01ff9e78(data_020f3c20 + arg1 * 2, ((arg0 + 0xB) << 5) + 0x1E, 2);
}

void func_020b19d0(s32 arg0, s32 arg1) {
    M2C_UNK func_0207c55c(void *, s32, M2C_UNK, M2C_UNK);
    s32 func_020d1a74(void);
    extern u8 data_020f3c20[];
    extern void *gCurrentMap;
    s32 offset;
    s32 first;
    s32 second;
    if (func_020d1a74() != 0) {
        first = 0;
        second = 8;
    } else {
        first = 8;
        second = 0;
    }
    offset = arg0 * 0x8C;
    func_0207c55c(data_020f3c20 + arg1 * 2, ((first + (M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + offset, u8 *, 0x67C1) - 1)) << 5) + 0x121E, 2, 0);
    func_0207c55c(data_020f3c20, ((second + (M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + offset, u8 *, 0x67C1) - 1)) << 5) + 0x121E, 2, 0);
}

void func_020b1a84(void) {

}

void func_020b1a88(void) {

}

void func_020b1a8c(s32 arg0) {
    M2C_UNK func_0207c55c(void *, s32, M2C_UNK, M2C_UNK);
    extern u8 data_021206e0[];
    func_0207c55c(data_021206e0 + ((u32)((arg0 >> 2) << 28) >> 27), 0x1448, 2, 0);
}

void func_020b1abc(void) {
    M2C_UNK func_0207a77c(s32);
    M2C_UNK func_0207ad30(s32);
    extern s32 data_027e15bc;
    func_0207a77c(data_027e15bc);
    func_0207ad30(data_027e15bc);
}

void func_020b1ae0(void) {
extern void *gCur3DSpriteEngine, *data_027e00c8, *gCurrentMap;
extern u8 data_02128000[];
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
M2C_FIELD(gCurrentMap,void **,4)=data_02128000;
gCur3DSpriteEngine=saved;
}

u8 func_020b1b1c(void *arg0, s32 arg1) {
    return (u8) (M2C_FIELD(arg0, u16 *, 0x1C) & arg1);
}

void func_020b1b2c(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 3) = arg1;
}

u8 func_020b1b34(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 3);
}

void func_020b1b3c(void) {
extern u8 data_0215c45c[];
extern void *data_02128690;
s32 i;
u8 *p=data_0215c45c;
for(i=0;i<85;i++,p+=60) p[1]=0;
M2C_FIELD(data_02128690,s32 *,0)=8;
M2C_FIELD(data_02128690,s32 *,4)=0;
M2C_FIELD(data_02128690,s32 *,12)=0;
M2C_FIELD(data_02128690,u8 *,8)=0;
M2C_FIELD(data_02128690,u8 *,0x24)=0;
M2C_FIELD(data_02128690,u8 *,0x25)=0;
M2C_FIELD(data_02128690,u8 *,0x26)=0;
M2C_FIELD(data_02128690,u8 *,0x27)=0;
}

s32 func_020b1bb0(void) {
extern void *data_02128690;
void *p=M2C_FIELD(data_02128690,void **,12);
if(!p || !M2C_FIELD(p,u8 *,1) || (u8)(M2C_FIELD(p,u8 *,4)+253)<=1) return 0;
return 1;
}

void func_020b1bf4(s16 a,s16 b,s16 c,s16 d) {
extern void *data_02128690;
M2C_FIELD(data_02128690,s16 *,0x10)=a;
M2C_FIELD(data_02128690,s16 *,0x12)=b;
M2C_FIELD(data_02128690,s16 *,0x14)=c;
M2C_FIELD(data_02128690,s16 *,0x16)=b;
M2C_FIELD(data_02128690,s16 *,0x18)=a;
M2C_FIELD(data_02128690,s16 *,0x1a)=d;
M2C_FIELD(data_02128690,s16 *,0x1c)=c;
M2C_FIELD(data_02128690,s16 *,0x1e)=d;
}

void func_020b1c44(s16 a,s16 b) {
extern void *data_02128690;
M2C_FIELD(data_02128690,s16 *,0x20)=a;
M2C_FIELD(data_02128690,s16 *,0x22)=b;
}

s32 func_020b1c60(s32 arg0) {
    s32 func_020b20e0(void);
    M2C_UNK func_020b1ca0(u8 *, s32);
    func_020b1ca0((u8 *)func_020b20e0(), arg0);
}

s32 func_020b1c78(void) {
    s32 func_020b1c60();
    void func_020b204c();
    s32 temp_r4;

    temp_r4 = func_020b1c60();
    func_020b204c();
    return temp_r4;
}

void func_020b1c90(u8 *arg0) {
    M2C_UNK func_020b1ca0(u8 *, s32);
    func_020b1ca0(arg0, *arg0);
}

M2C_UNK func_020b1ca0(u8 *arg0,s32 arg1) {
extern void *data_02128690;
void func_020b2e60(void *);
s32 changed;
if(func_020b1bb0() && arg0 && M2C_FIELD(data_02128690,void **,12)!=arg0) changed=1;
else changed=0;
M2C_FIELD(data_02128690,void **,12)=arg0;
M2C_FIELD(data_02128690,u8 *,8)=arg1;
if(changed) func_020b2e60(M2C_FIELD(data_02128690,void **,12));
return (M2C_UNK)M2C_FIELD(data_02128690,void **,12);
}

void func_020b1d14(void){extern void *data_02128690,*data_02101e84,*data_02101e88;void *p;void (*f)(void *);if(!func_020b1bb0())return;p=M2C_FIELD(data_02128690,void **,12);if(M2C_FIELD(p,u8 *,4)!=2)return;if(!M2C_FIELD(data_02101e84,u16 *,2))return;if(M2C_FIELD(data_02101e88,u8 *,18))return;f=M2C_FIELD(p,void (**)(void *),40);if(!f)return;f(p);}

void func_020b204c(void){extern void *data_02128690;void *p; s32 d,c,b,a,sum;p=M2C_FIELD(data_02128690,void **,12);if(!p)return;a=M2C_FIELD(p,s16 *,20);b=M2C_FIELD(p,s16 *,22);c=M2C_FIELD(p,s16 *,24);d=M2C_FIELD(p,s16 *,26);M2C_FIELD(data_02128690,s16 *,16)=(s16)a;M2C_FIELD(data_02128690,s16 *,18)=(s16)b;M2C_FIELD(data_02128690,s16 *,20)=(s16)(a+c);sum=b+d;M2C_FIELD(data_02128690,s16 *,22)=(s16)b;M2C_FIELD(data_02128690,s16 *,24)=(s16)a;M2C_FIELD(data_02128690,s16 *,26)=(s16)sum;M2C_FIELD(data_02128690,s16 *,28)=(s16)(a+c);M2C_FIELD(data_02128690,s16 *,30)=(s16)sum;}

s32 func_020b20e0(a) s32 a; {extern u8 data_0215c45c[];s32 i=0;u8 *p=data_0215c45c;do{if(p[1]&&a==p[0])return (s32)data_0215c45c+60*i;i++;p+=60;}while(i<85);return 0;}

u8 func_020b212c(void) {
    extern void *data_02128690;
    return M2C_FIELD(data_02128690, u8 *, 8);
}

void func_020b2140(void) {
extern void *data_02128690;
M2C_FIELD(data_02128690,u8 *,0x25)=0;
}

void func_020b2158(s8 arg0) {
extern void *data_02128690;
M2C_FIELD(data_02128690,s8 *,0x25)=arg0;
}

void func_020b216c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 1) = 0;
}

void func_020b2178(void){extern u8 data_0215c45c[];s32 i=0;u8 *p=data_0215c45c;u8 zero=i;do{i++;p[1]=zero;p+=60;}while(i<85);}

void func_020b21a0(void) {
extern u8 data_0215c45c[];
s32 i=0; u8 *p=data_0215c45c;
do { if(func_020b1b1c(p,1)!=0) p[1]=0; i++;p+=0x3c; } while(i<0x55);
}

void func_020b21e0(void) {
extern u8 data_0215c45c[];
s32 i; u8 *p;
p=data_0215c45c; i=0;
do { if(func_020b1b1c(p,1)!=1) M2C_FIELD(p,u16 *,0x1c)|=0x400; i++;p+=0x3c; } while(i<0x55);
}

void func_020b2224(void) {
extern u8 data_0215c45c[];
s32 i; u8 *p;
p=data_0215c45c; i=0;
do { if(func_020b1b1c(p,1)!=1) M2C_FIELD(p,u16 *,0x1c)&=~0x400; i++;p+=0x3c; } while(i<0x55);
}

void func_020b2268(void) {
    extern u8 data_0215c45c[];
    s32 i;
    u8 *p;

    p = data_0215c45c;
    i = 0;
    do {
        if ((p[1] != 0) && (p[4] < 3U)) {
            p[4] = 3U;
        }
        i += 1;
        p += 0x3C;
    } while (i < 0x55);
}

s32 func_020b22a4(s32 a,s32 b,void *c,s32 d) {
s32 func_020b2304(s32,s32,void *,void *,s32);
extern u8 data_0215c45c[];
u8 *p=data_0215c45c; s32 i=0;
do { if(p[1]==0) return func_020b2304(a,b,data_0215c45c+i*0x3c,c,d); i++;p+=0x3c; } while(i<0x54);
return 0;
}

/* Initialize a 0x3C-byte sprite slot (arg2) at board position (x + arg3->dx,
   y + arg3->dy) from the spawn descriptor arg3 (size at +4/+6, rectangles and
   palette at +8..+0xE, six extra dwords at +0x10..+0x24); arg4 is the slot's id.
   The slot is marked visible (byte 1) and data_02128690 records which screen it
   was created on.  Returns the slot. */
s32 func_020b2304(s32 x, s32 y, void *slot, void *desc, s32 id) {
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_02128690;
    s16 t;
    u8 onUpperScreen;

    t = *(s16 *)((s8 *)desc + 0);
    *(s16 *)((s8 *)slot + 0x14) = (s16)(x + t);

    t = *(s16 *)((s8 *)desc + 2);
    *(s16 *)((s8 *)slot + 0x16) = (s16)(y + t);

    *(s16 *)((s8 *)slot + 0x18) = *(s16 *)((s8 *)desc + 4);
    *(s16 *)((s8 *)slot + 0x1a) = *(s16 *)((s8 *)desc + 6);
    *(u16 *)((s8 *)slot + 0x1c) = *(u16 *)((s8 *)desc + 8);
    *(u16 *)((s8 *)slot + 0x1e) = *(u16 *)((s8 *)desc + 0xa);
    *(u16 *)((s8 *)slot + 0x20) = *(u16 *)((s8 *)desc + 0xc);
    *(u16 *)((s8 *)slot + 0x22) = *(u16 *)((s8 *)desc + 0xe);
    *(s32 *)((s8 *)slot + 0x24) = *(s32 *)((s8 *)desc + 0x10);
    *(s32 *)((s8 *)slot + 0x28) = *(s32 *)((s8 *)desc + 0x14);
    *(s32 *)((s8 *)slot + 0x2c) = *(s32 *)((s8 *)desc + 0x18);
    *(s32 *)((s8 *)slot + 0x30) = *(s32 *)((s8 *)desc + 0x1c);
    *(s32 *)((s8 *)slot + 0x34) = *(s32 *)((s8 *)desc + 0x20);
    *(s32 *)((s8 *)slot + 0x38) = *(s32 *)((s8 *)desc + 0x24);

    *(u8 *)((s8 *)slot + 0) = (u8)id;
    *(u8 *)((s8 *)slot + 3) = 0;
    *(u8 *)((s8 *)slot + 4) = 0;

    t = *(s16 *)((s8 *)slot + 0x14);
    *(s16 *)((s8 *)slot + 0xa) = t;
    *(s16 *)((s8 *)slot + 0x6) = t;

    t = *(s16 *)((s8 *)slot + 0x16);
    *(s16 *)((s8 *)slot + 0xc) = t;
    *(s16 *)((s8 *)slot + 0x8) = t;

    *(s16 *)((s8 *)slot + 0xe) = 0;
    *(u8 *)((s8 *)slot + 1) = 1;

    onUpperScreen = (u8)(gCur3DSpriteEngine == data_027e00c8);
    if (onUpperScreen) {
        M2C_FIELD(data_02128690, u8 *, 0x24) = 0;
    } else {
        M2C_FIELD(data_02128690, u8 *, 0x24) = 1;
    }

    return (s32)slot;
}

