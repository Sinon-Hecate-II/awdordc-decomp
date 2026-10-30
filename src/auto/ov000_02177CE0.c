/* 6 functions from 0x02177CE0 to 0x02178778 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_02177f24(s32 arg0, s32 arg1, s16 *arg2) {
    s32 func_ov000_02177ce0(s32, s32);
    extern void **gCurrentMap;
    extern s32 data_027e15bc;
    register s32 magic asm("r3") = 0x270F;
    register s32 x asm("r10") = arg0;
    s32 sp0 = arg1;
    s16 *sp4 = arg2;
    s32 sp8;
    s32 spC;
    register s32 best asm("r4") = 0;
    register s32 outer asm("r8");
    register s32 innerMax asm("r9");
    register s32 inner asm("r5");
    register s32 d0 asm("r6");
    register s32 d1 asm("r7");
    register s32 outerS16 asm("r11");
    void *base;
    s32 temp;
    s32 adx;
    s32 dist;

    *sp4 = (s16) magic;
    spC = x - 1;
    if (spC < 0) spC = 0;
    outer = sp0 - 1;
    if (outer < 0) outer = 0;
    base = *gCurrentMap;
    innerMax = M2C_FIELD(base, u16 *, 0x5144) - 1;
    if (x + 1 < innerMax) innerMax = x + 1;
    sp8 = M2C_FIELD(base, u16 *, 0x5146) - 1;
    if (sp0 + 1 < sp8) sp8 = sp0 + 1;
    if (outer <= sp8) {
        do {
            inner = spC;
            if (inner <= innerMax) {
                do {
                    d0 = sp0 - outer;
                    d1 = outer - sp0;
                    outerS16 = (s16) outer;
                    adx = x - inner;
                    if (adx <= 0) adx = inner - x;
                    dist = 0;
                    dist = adx + dist;
                    if (d0 > 0) dist = dist + d0;
                    else dist = dist + d1;
                    if (dist == 1) {
                        temp = func_ov000_02177ce0((s32)(s16)inner, (s32)(s16)outer);
                        if (temp >= best && (temp != best || !(data_027e15bc & 1))) {
                            best = temp;
                            sp4[0] = (s16) inner;
                            sp4[1] = (s16) outerS16;
                        }
                    }
                    inner++;
                } while (inner <= innerMax);
            }
            outer++;
        } while (outer <= sp8);
    }
    if (sp4[0] == (s16) magic) return 0;
    return 1;
}

s32 func_ov000_02178080(s32 x,s32 y){
extern void **gCurrentMap;extern void *data_ov000_021df580;extern s8 data_ov000_021b55a0[];
s32 func_ov000_021a9d8c(s16,s16);s32 func_020d27ec(s32,s32,s32);
s32 func_020d0654(s32,s32,s32);s32 func_0207c8ec(s32,s32);
s32 func_020d03ec(s32,s32,s32);s32 func_ov000_021a9214(void *,s32,s32);s32 func_ov000_021a93a8(void *,s32,s32);
void *base,*cell; s32 cost,result,kind,weight;
if(x<0||y<0||x>=M2C_FIELD(*gCurrentMap,u16 *,0x5144)||y>=M2C_FIELD(*gCurrentMap,u16 *,0x5146))return -1;
if(func_ov000_021a9d8c((s16)x,(s16)y))return -1;
base=*gCurrentMap;
cost=M2C_FIELD(M2C_FIELD(base+y*4,s8 **,0x52e8),s8 *,x);
if(cost<0||cost>M2C_FIELD(data_ov000_021df580,u8 *,5))return -1;
cell=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758));
result=15-cost;
kind=M2C_FIELD(cell,u8 *,0x1420)&31;
weight=M2C_FIELD(cell,u8 *,0x2840)+M2C_FIELD(cell,u8 *,0x2d48)*2;
if(result<0)result=0;
if(!data_ov000_021b55a0[kind]||!func_020d27ec(M2C_FIELD(base,u8 *,0x52d4),M2C_FIELD(cell,u8 *,0x1420),data_ov000_021b55a0[kind])){
base=*gCurrentMap;
result+=(func_0207c8ec(func_020d0654(M2C_FIELD(base,u16 *,0x52a4),(u32)(*M2C_FIELD(base,u8 **,0x52d0)<<26)>>26,kind),10)+1)<<5;
}
if(func_020d03ec(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),x,y))result+=0x200;
result+=(0x300-weight)<<10;
if(!data_ov000_021b55a0[kind]&&func_ov000_021a9214(M2C_FIELD(*gCurrentMap,void **,0x52d0),x,y)==1)result+=0x100000;
if(func_ov000_021a93a8(M2C_FIELD(*gCurrentMap,void **,0x52d0),x,y)==1)result+=0x200000;
if(weight<20)result+=0x400000;
return result;
}

s32 func_ov000_02178268(s32 arg0, s32 arg1, void *arg2) {
    (void)arg0; (void)arg1; (void)arg2;
    return 0;
}

s32 func_ov000_02178518(s32 arg0, s32 arg1, s16 *arg2) {
    s32 func_ov000_02177ce0(s32, s32);
 s32 func_ov000_021a9a28(u32,s32,s32);
    extern void **gCurrentMap;
    extern s32 data_027e15bc;
    s32 magic = 0x270F;
    s32 x = arg0;
    s32 sp0 = arg1;
    s16 *sp4 = arg2;
    s32 spC;
    s32 sp8;
    s32 best = 0;
    s32 outer;
    s32 innerMax;
    s32 inner;
    s32 d0;
    s32 d1;
    s32 outerS16;
    void *base;
    s32 temp;
    s32 adx;
    s32 dist;

    *sp4 = (s16) magic;
    spC = x - 1;
    if (spC < 0) spC = 0;
    outer = sp0 - 1;
    if (outer < 0) outer = 0;
    base = *gCurrentMap;
    innerMax = M2C_FIELD(base, u16 *, 0x5144) - 1;
    if (x + 1 < innerMax) innerMax = x + 1;
    sp8 = M2C_FIELD(base, u16 *, 0x5146) - 1;
    if (sp0 + 1 < sp8) sp8 = sp0 + 1;
    if (outer <= sp8) {
        do {
            inner = spC;
            if (inner <= innerMax) {
                do {
                    d0 = sp0 - outer;
                    d1 = outer - sp0;
                    outerS16 = outer;
                    adx = x - inner;
                    if (adx <= 0) adx = inner - x;
                    dist = 0;
                    dist = adx + dist;
                    if (d0 > 0) dist = dist + d0;
                    else dist = dist + d1;
                    if (dist >= 1 && dist <= 1 && func_ov000_021a9a28((u32)(*M2C_FIELD(*gCurrentMap,u8**,0x52d0)<<26)>>26,inner,outer)) {
                        temp = func_ov000_02177ce0(inner, outer);
                        if (temp >= best && (temp != best || !(data_027e15bc & 1))) {
                            best = temp;
                            sp4[0] = (s16) inner;
                            sp4[1] = outerS16;
                        }
                    }
                    inner++;
                } while (inner <= innerMax);
            }
            outer++;
        } while (outer <= sp8);
    }
    if (sp4[0] == magic) return 0;
    return 1;
}

u8 func_ov000_021786a8(s16 *out) {
s32 func_020d1938(s32); s32 func_020d243c(s32); s32 func_020d273c(u16,s32);
extern void **gCurrentMap;
s32 best=0x7fff,i,offset,x,y,v;
void *base,*entry;
for(i=1,offset=0x8c;i<5;i++,offset+=0x8c) {
if(func_020d1938(i) && !func_020d273c(M2C_FIELD(*gCurrentMap,u16*,0x52a4),i) && func_020d243c(i)) {
base=*gCurrentMap;entry=(u8*)base+offset;
x=M2C_FIELD(entry,u8*,0x67cf)&127;
y=M2C_FIELD(entry,u8*,0x67d0)&127;
v=M2C_FIELD(M2C_FIELD((u8*)base+y*4,s8**,0x52e8),s8*,x);
if(v>=0) {
if(v<=best) {
out[0]=x;
best=v;
out[1]=y;
}
}
}
}
return best!=0x7fff;
}
