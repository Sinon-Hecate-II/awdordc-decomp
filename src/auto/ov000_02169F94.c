/* 33 functions from 0x02169F94 to 0x0216ABA8 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { s32 values[3]; } A77cTable;
typedef struct { u32 value, threshold; } A564Entry;
extern const A77cTable data_ov000_021aabb0;

void func_ov000_02169f94(void *p) {
s32 func_020a7298(u8,u8);
void func_ov000_0216a1ac(void *);
void func_0208fb0c(s32,s32,s32);
extern s32 *gCurrentMap;extern M2C_UNK data_ov000_021aec98;
s32 idx,mode,x,y;
idx=func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8c,u8 *,0x67cd));
x=M2C_FIELD(p,s16 *,0x4c)+8;
y=M2C_FIELD(p,s16 *,0x4e)+8;
mode=*(s32 *)((u8 *)&data_ov000_021aec98+idx*20);
x=(s32)(x+((u32)(x>>3)>>28))>>4;y=(s32)(y+((u32)(y>>3)>>28))>>4;
switch(mode){case 0:return;case 0x8000:func_ov000_0216a1ac(p);return;case 0x4000:func_02090034(0);return;default:func_0208fb0c(mode,x,y);return;}
}

void func_ov000_0216a2b8(void *);
void func_ov000_0216a040(void *p) {
s32 func_020a7298(u8,u8);
void func_ov000_0216a1ac(void *);
extern s32 *gCurrentMap;extern M2C_UNK data_ov000_021aec98;
s32 idx=func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8c,u8 *,0x67cd));
if(*(s32 *)((u8 *)&data_ov000_021aec98+idx*20)==0x8000){func_ov000_0216a1ac(p);return;}
((void (*)(void *))func_ov000_0216a2b8)(p);
}

s32 func_ov000_0216a0a4(s32 unused,s32 x,s32 y){
extern s32 *gCurrentMap;void *base=(void *)*gCurrentMap;
switch(M2C_FIELD((u8*)base+(x+M2C_FIELD((u8*)base+y*2,u16 *,0x3758)),u8 *,0x1420)&31){
case 4:return 0x42;
case 3:return 0x3f;
case 9:return 0x46;
case 2:return 0x44;
case 1:switch(M2C_FIELD(base,u8 *,0x5157)){case 1:return 0x41;case 2:return 0x46;case 3:return 0x45;default:return 0x40;}
case 13:case 14:case 15:case 16:case 17:case 18:case 19:return 0x40;
case 7:case 8:case 12:return 0x43;
default:return 0;
}
}

void func_ov000_0216a1ac(void *p){
s32 func_020a7298(u8,u8);void func_0208fb0c(s32,s32,s32);void func_0208fae8(s32);
extern s32 *gCurrentMap;extern s32 data_ov000_021aec94;
s32 index,x,y;u16 effect;
index=func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8c,u8 *,0x67cd));
x=M2C_FIELD(p,s16 *,0x4c)+8;y=M2C_FIELD(p,s16 *,0x4e)+8;x/=16;y/=16;
switch(M2C_FIELD(p,u8 *,0x42)){
case 1:case 2:
if(!*(s32 *)((u8 *)&data_ov000_021aec94+index*20))return;
effect=func_ov000_0216a0a4((s32)p,x,y);if(!effect)return;
func_0208fb0c(effect,x,y);return;
case 22:
if(M2C_FIELD(p,void **,0x3c)&& (M2C_FIELD(M2C_FIELD(p,void **,0x3c),u16 *,4)&32)){func_0208fae8(0x5d);break;}
default:
effect=0;
if(*(s32 *)((u8 *)&data_ov000_021aec94+index*20))func_0208fae8(*(s32 *)((u8 *)&data_ov000_021aec94+index*20));break;
}
func_ov000_0216a2b8(p);
}

void func_ov000_0216a2b8(void *p) {
s32 func_0208fa78(s32,s32);
s32 func_02090084(s32);
s32 x,y;
if(!func_02090084(0))return;
x=M2C_FIELD(p,s16 *,0x4c)+8;y=M2C_FIELD(p,s16 *,0x4e)+8;
func_02090100(0,func_0208fa78(x/16,y/16));
}

void func_ov000_0216a30c(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02007ef4(s32, s32, M2C_UNK);
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208116c(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_020e35cc(s32);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021b7e5c;
    extern M2C_UNK data_ov000_021b7e6c;
    s32 temp_r0;

    temp_r0 = func_02081070(&data_ov000_021b7e5c, 0);
    func_02007ef4(temp_r0 + (arg0 << 8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg1, 0x100);
    func_020e35cc(temp_r0);
    func_0208116c(&data_ov000_021b7e6c, (arg2 + 0x10) << 5, 0x20);
}

void func_ov000_0216a374(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_01ffaacc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK data_027e005c;
    func_01ffaacc(arg0, arg1, arg2, &data_027e005c, arg3);
}

s32 func_ov000_0216a38c(s32 arg0, s32 arg1) {
    extern M2C_UNK data_ov000_021b686c;
    return (arg1 * 0x30) + ((arg0 * 0x750) + (s32) &data_ov000_021b686c);
}

u32 func_ov000_0216a3a8(s32 a,s32 b) {
extern u32 data_0215da2c[];
s32 p=func_ov000_0216a38c(a,b);
switch(a){case 0:return data_0215da2c[M2C_FIELD(p,u16 *,4)];case 1:return data_0215da2c[M2C_FIELD(p,u16 *,4)+0x28];case 2:return data_0215da2c[M2C_FIELD(p,u16 *,4)+0x43];default:return 0;}
}

u16 func_ov000_0216a414(s32 a,s32 b) {
s32 p=func_ov000_0216a38c(a,b);u32 n=func_ov000_0216a3a8(a,b);u16 r;
if(n>=M2C_FIELD(p,u32 *,16))return 3;if(n>=M2C_FIELD(p,u32 *,12))return 2;
if(n>=M2C_FIELD(p,u32 *,8)) r=1;else r=0;return r;
}

u16 func_ov000_0216a470(void) {
s32 i,j; s32 p;u16 result=0;
i=0;do {p=func_ov000_0216a38c(i,0);j=0;if(M2C_FIELD(p,s32 *,0)) {do {result+=func_ov000_0216a414(i,j);p+=0x30;j++;}while(M2C_FIELD(p,s32 *,0));}i++;}while(i<3);return result;
}

void func_ov000_0216a4e0(u16 *a,u16 *b) {
s32 i,j,p,r;i=0;*a=0;*b=0;
do {p=func_ov000_0216a38c(i,0);j=0;if(M2C_FIELD(p,s32 *,0)){do {r=func_ov000_0216a414(i,j);j++;*a+=r;*b+=3;p+=0x30;}while(M2C_FIELD(p,s32 *,0));}i++;}while(i<3);
}

s8 func_ov000_0216a564(u32 a) { extern M2C_UNK data_ov000_021b67cc; s32 i=0; do {if(a>=((A564Entry *)&data_ov000_021b67cc)[i].threshold)return (s8)i;i++;}while(i<20);return 19; }

s32 func_ov000_0216a59c(s32 i) {
extern M2C_UNK data_ov000_021b67cc;
return *(s32 *)((u8 *)&data_ov000_021b67cc+i*8);
}

s32 func_ov000_0216a5ac(s32 arg0) {
    s32 func_ov000_0216a38c(s32, s32);
    u32 func_ov000_0216a3a8(s32, s32);

    s32 *p;
    s32 i;
    u32 flag;
    unsigned long long total0;
    unsigned long long total1;
    unsigned long long total2;
    unsigned long long best;
    u32 n;
    u8 byte;
    s16 mode;
    s8 bestIndex;

    p = (s32 *)0;
    i = 0;
    flag = 1;
    total0 = 0;
    total1 = 0;
    total2 = 0;
    best = 0;
    bestIndex = 0;

    p = (s32 *)func_ov000_0216a38c(1, 0);
    while (*p != 0) {
        n = func_ov000_0216a3a8(1, i);
        if (n != 0) {
            flag = 0;
        }
        byte = *(u8 *)((u8 *)func_ov000_0216a38c(1, i) + 0x18);
        n = n * byte;
        mode = *(s16 *)((u8 *)func_ov000_0216a38c(1, i) + 6);
        switch (mode) {
            case 0:
                total0 = total0 + n;
                break;
            case 1:
                total1 = total1 + n;
                break;
            case 2:
                total2 = total2 + n;
                break;
        }
        if ((unsigned long long)n > best) {
            best = n;
            bestIndex = (s8)i;
        }
        i = i + 1;
        p = (s32 *)((u8 *)p + 0x30);
    }

    if (arg0 != 0) {
        if (flag != 0) {
            return -1;
        }
        return bestIndex;
    }
    if (flag != 0) {
        return -1;
    }
    if (total0 < total1) {
        if (total1 < total2) {
            return 2;
        }
        return 1;
    } else {
        if (total0 < total2) {
            return 2;
        }
        return 0;
    }
}

void func_ov000_0216a76c(void) {
    M2C_UNK func_ov000_0216a5ac(M2C_UNK);
    func_ov000_0216a5ac(0);
}

s32 func_ov000_0216a77c(s32 a) {
A77cTable table;
if(a==-1)return 0xc0000021;
table=data_ov000_021aabb0;return table.values[a];
}

void func_ov000_0216a7c4(void) {
    func_ov000_0216a5ac(1);
}

s32 func_ov000_0216a7d4(s32 a) {
if(a==-1)return 0xc0000025;
return M2C_FIELD(func_ov000_0216a38c(1,a),s32 *,0x14);
}

s32 func_ov000_0216a7fc(void) {
    s32 func_ov000_0216aba8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 *func_ov000_0216b0c8();
    s32 *temp_r0_2;
    s32 temp_r0;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = *temp_r0_2;
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a834(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 4);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a86c(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 8);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a8a4(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0xC);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

u8 func_ov000_0216a8dc(s32 a) {
extern s32 *gCurrentMap;
s32 p= (s32)func_ov000_0216b0c8();s32 index;
if(a==0)index=0;else index=(a-(*gCurrentMap+0x59a4))/14;
if((index&0xc0)>>6)return 0;
if(p && M2C_FIELD(p,s32 *,16))return func_ov000_0216aba8(M2C_FIELD(p,s32 *,16),a,0,0,1);return 0;
}

s32 func_ov000_0216a97c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x14);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, arg0, arg1, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a9bc(M2C_UNK arg0) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x18);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, arg0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aa04(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x18);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, arg0, 0, arg1, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aa44(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x1C);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, arg1, 0, arg0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aa84(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x20);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aabc(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x24);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aaf4(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x28);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216ab2c(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x2C);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216ab64(s32 arg0) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = func_ov000_0216b0c8();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x30);
        if (temp_r0 != 0) {
            return func_ov000_0216aba8(temp_r0, 0, 0, 0, arg0);
        }
    }
    return 0;
}

