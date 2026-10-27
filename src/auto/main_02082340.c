/* 19 functions from 0x02082340 to 0x02083320 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 entries[0x1800];u8 count; } Lists020830;

void func_020824cc(void) {
    void func_02082a8c(void *, void *);
    extern void **gCur3DSpriteEngine;
    extern u8 data_02101fc0[];
    u16 *base;
    u16 * volatile sp4;
    u16 * volatile sp0;

    base = *gCur3DSpriteEngine;
    base[0] = 0;
    base[3] = 0;
    base[4] = 0;
    base[5] = 0;
    base[6] = 0;

    sp4 = base + 1;
    *sp4 = *sp4 & ~7;

    sp0 = base + 1;
    *sp0 = *sp0 & ~0x38;

    func_02082a8c(data_02101fc0, (u8 *)*gCur3DSpriteEngine + 0x14);
    func_02082a8c(data_02101fc0, (u8 *)*gCur3DSpriteEngine + 0x24);
}

void func_0208259c(void){
void func_02082a8c(void *,void *);extern void **gCur3DSpriteEngine;extern u8 data_02101fc0[];
u16 *volatile a;u16 *volatile b;u16 *volatile c;u16 *volatile d;u16 *volatile e;u16 *volatile f;u16 *volatile g;
a=*gCur3DSpriteEngine;*a=*a&~0x10;
b=*gCur3DSpriteEngine;*b=*b&~0x20;
c=*gCur3DSpriteEngine;*c=*c&~0x40;
d=*gCur3DSpriteEngine;*d=*d&~0x80;
e=*gCur3DSpriteEngine;*e=*e&~0x100;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,6)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,8)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,10)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,12)=0;
f=(u16 *)*gCur3DSpriteEngine+1;*f=*f&~7;
g=(u16 *)*gCur3DSpriteEngine+1;*g=*g&~0x38;
func_02082a8c(data_02101fc0,(u8 *)*gCur3DSpriteEngine+0x14);
func_02082a8c(data_02101fc0,(u8 *)*gCur3DSpriteEngine+0x24);
}

void func_02082700(void) {
    extern void **gCur3DSpriteEngine;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x38) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3A) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3C) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x44) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3E) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x46) = 0;
}

/* Resets the current 3D sprite engine's sprite queues and status flags. */
void Reset3DSpriteEngineState(void) {
    extern void **gCur3DSpriteEngine;
    u16 *volatile a;
    u16 *volatile b;
    u16 *volatile c;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0xE) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x10) = 0;
    a = *gCur3DSpriteEngine;
    *a = *a & ~0x200;
    b = *gCur3DSpriteEngine;
    *b = *b & ~0x400;
    c = *gCur3DSpriteEngine;
    *c = *c & ~0x800;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x48) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4A) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x49) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4B) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4C) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4E) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4D) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4F) = 0;
}

void func_02082a8c(void *arg0, void *arg1) {
s32 func_0207c8ec(s32,s16);
extern s16 data_020e5b30[];
void *out=arg1; void *in=arg0;
s32 x,y,dx,dy,index,sine,cosine,a,b;
index=((s32)(u16)(M2C_FIELD(in,u16 *,0x10)<<8)>>4)*2;
cosine=*(s16 *)((u8 *)data_020e5b30 + ((index+1)*2))<<8;
x=M2C_FIELD(in,s32 *,0); y=M2C_FIELD(in,s32 *,4);
dx=x-M2C_FIELD(in,s16 *,8);dy=y-M2C_FIELD(in,s16 *,10);
M2C_FIELD(out,s16 *,0)=func_0207c8ec(cosine,M2C_FIELD(in,s16 *,12))>>4;
sine=data_020e5b30[index]<<8;
M2C_FIELD(out,s16 *,2)=func_0207c8ec(sine,M2C_FIELD(in,s16 *,12))>>4;
M2C_FIELD(out,s16 *,4)=(-func_0207c8ec(sine,M2C_FIELD(in,s16 *,14)))>>4;
M2C_FIELD(out,s16 *,6)=func_0207c8ec(cosine,M2C_FIELD(in,s16 *,14))>>4;
b=dy-y;a=dx-x;
M2C_FIELD(out,s32 *,8)=M2C_FIELD(out,s16 *,0)*a+M2C_FIELD(out,s16 *,2)*b+(x<<8);
M2C_FIELD(out,s32 *,12)=M2C_FIELD(out,s16 *,4)*a+M2C_FIELD(out,s16 *,6)*b+(y<<8);
}

void func_02082b78(void){
extern void *data_027e00bc;extern void *data_027e00c0;
extern void **gCur3DSpriteEngine;extern void **data_027e00c4;extern void **data_027e00c8;
u16 *volatile a;u16 *volatile b;void **old;s32 i;
M2C_FIELD(data_027e00bc,s32*,0x34)=1;M2C_FIELD(data_027e00c0,s32*,0x34)=1;
M2C_FIELD(data_027e00bc,u16*,4)=(M2C_FIELD(data_027e00bc,u16*,4)&~1)|1;
M2C_FIELD(data_027e00bc,u16*,4)&=~2;
M2C_FIELD(data_027e00bc,u16*,4)&=~4;
a=*gCur3DSpriteEngine;*a=*a&~0x1000;
b=*gCur3DSpriteEngine;*b=*b&~0x6000;
old=gCur3DSpriteEngine;
for(i=0;i<2;i++){
gCur3DSpriteEngine=i==0?data_027e00c8:data_027e00c4;
func_020824cc();func_02082700();func_02082770();Reset3DSpriteEngineState();
M2C_FIELD(*gCur3DSpriteEngine,u8*,0x50)=0;
}
gCur3DSpriteEngine=old;
}

void func_02082c84(void) {
    M2C_UNK func_02003538();
    M2C_UNK func_0200354c();
    M2C_UNK func_02003560();
    M2C_UNK func_02003584();
    M2C_UNK func_020035a8();
    M2C_UNK func_020035bc();
    M2C_UNK func_0200360c();
    M2C_UNK func_02003620();
    M2C_UNK func_02003634();
    M2C_UNK func_0200365c();
    func_02003538();
    func_0200354c();
    func_02003560();
    func_02003584();
    func_020035a8();
    func_020035bc();
    func_0200360c();
    func_02003620();
    func_02003634();
    func_0200365c();
}

void func_02082cb4(void) {
    M2C_UNK func_020026d8(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002ab8(M2C_UNK);
    M2C_UNK func_02002c64(M2C_UNK);
    M2C_UNK func_02002e3c(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_020032bc(M2C_UNK);
    func_02082c84();
    func_02002c64(1);
    func_020026d8(2);
    func_02003124(4);
    func_020031cc(8);
    func_02002968(0x10);
    func_02002e3c(0x20);
    func_02002ab8(0x40);
    func_0200323c(0x80);
    func_020032bc(0x100);
}

void func_02082eb4(s32 a,s32 b,s32 c,s32 d){extern void **gCur3DSpriteEngine;extern void **data_027e00c8; s32 v; func_020067e0(a,d); if(gCur3DSpriteEngine==data_027e00c8)v=1;else v=0; if(v&255){func_0200478c();func_0200482c(a,c+(b<<13),d);func_0200489c();}else{func_020049dc();func_020049f4(a,c+(b<<13),d);func_02004a58();}}

s32 func_02082f34(s32 arg0) {
    s32 func_020846a4();
    s32 func_02084a0c();
    s32 func_020c7ef4(s32);
    s32 func_020cfbb0(u16);
    s32 temp_r4;

    if (func_020846a4() == 0) {
        if ((arg0 >= 0xE1) && (arg0 < 0x1A9) && (arg0 >= 0x113)) {
            return 0;
        }
        goto block_7;
    }
    temp_r4 = func_020cfbb0((u16) arg0);
    if (temp_r4 < func_02084a0c()) {
        return 0;
    }
block_7:
    if ((arg0 >= 0xE1) && (arg0 < 0x1A9) && (func_020c7ef4(arg0) == 0)) {
        return 0;
    }
    return 1;
}

s32 func_02082fc4(u32 x){switch(x){case 0:return 1;case 2:return 3;case 1:return 2;case 3:return 4;case 4:return 5;case 5:return 6;case 6:return 7;default:return 0;}}

s32 func_0208302c(u32 x){switch(x){case 2:return 1;case 4:return 3;case 1:return 0;case 5:return 4;case 6:return 5;case 3:return 2;case 7:case 8:case 9:case 10:case 11:return 6;default:return 0;}}

u8 func_020830a8(u16 x){ s32 func_020a8958(void); s32 func_020c7ef4(s32); s32 func_020cfbb0(u16); u8 y=func_02082fc4(func_020a8958()); if(y!=7)return y; if(!func_020c7ef4(x))return 7; return func_020cfbb0(x)+7; }

#pragma opt_common_subs off
void func_020830ec(u32 mode,Lists020830 *p,s32 arg){
s32 func_020846a4(void);void func_020831f8(void*,s32,s32);
s32 i;u8 n=0;
p->count=0;
switch(mode){
case 0:case 8:
for(i=2;i<12;i++){
if(!func_020846a4()){if(i<8||i>11)goto process;goto next;}else if(i==7)goto next;
process:
if(mode==8&&i==7)continue;
func_020831f8((void*)p+(p->count<<9),(u8)i,arg);
if(M2C_FIELD((void*)p+(p->count<<9),u8*,0x1ff))p->count++;
next:;
}
break;
case 6:case 7:case 9:
p->count=1;
for(i=0xe1;i<0x113;i++){M2C_FIELD(p,u16*,n*2)=i;n++;}
M2C_FIELD(p,u8*,0x1ff)=n;M2C_FIELD(p,u8*,0x1fe)=7;
break;
case 1:case 2:case 3:case 4:case 5:break;
}
}
#pragma opt_common_subs reset
void func_020831f8(void *p,s32 b,s32 c){
s32 func_020846a4(void);s32 func_02083320(s32,s32);
s32 count=0; s32 i; s32 limit; u8 type;
M2C_FIELD(p,u8 *,0x1fe)=b;
type=func_0208302c(b);
if(func_020846a4())limit=0x1a9;else limit=0x113;
i=0;while(i<limit){if(func_020832a0(i,type,c)){if(i<0xe1 || i>=0x1a9 || func_02083320(i,b)){((u16 *)p)[count]=i;count++;}}i++;}
M2C_FIELD(p,u8 *,0x1ff)=count;
}

s32 func_020832a0(s32 a,s32 b,s32 c){
s32 func_020a8958(void);s32 func_020846a4(void);s32 func_02086940(s32);s32 func_020cfbb0(u16);
if(b!=func_020a8958())return 0;
if(!func_02082f34(a))return 0;
if(c && c!=func_020cfbb0((u16)a))return 0;
if(!func_020846a4() && b==2){if(!func_02086940(a))return 0;}
return 1;
}

