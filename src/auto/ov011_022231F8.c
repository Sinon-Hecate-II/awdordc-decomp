/* 3 functions from 0x022231F8 to 0x02223CB8 (ov011), found by ds-decomp. */
#include "common.h"
extern u16 data_ov011_02227fa0[];
extern u16 data_ov011_02227f50[];
extern u8 data_02101f5c[],data_02101f0c[];
typedef struct { s32 words[5]; } ContextTemplate;
extern ContextTemplate data_ov011_02227f28;
extern void *gCur3DSpriteEngine, *data_027e00c8, *data_027e00c4;

s32 func_ov011_022231f8(u8 *p,u8 count,s32 duration,u16 position,u8 *offsets){
s32 func_0207ca38(s32,s32,s32,u16,s32);void func_01ffac9c(s32,u16,u16,void *,s32);s32 func_020e31e0(void);
extern u16 data_ov011_02228ce0[];
u16 flags[5]={0,0,0,0,0};
u16 *volatile v0;
u16 *volatile v1;
u16 *volatile v2;
u16 *volatile v3;
u16 *volatile v4;
u16 *volatile v5;
u16 *volatile v6;
u16 *volatile v7;
u16 *volatile v8;
u16 *volatile v9;
u16 *volatile v10;
u16 *volatile v11;
u16 *volatile v12;
u8 j;s32 tile; s32 base;u8 i; s16 blend;void *saved;u16 limit;u8 n;
if(duration==0){data_ov011_02228ce0[3]=0;data_ov011_02227fa0[0]=1;if(count==0)data_ov011_02228ce0[5]=0;return 0;}
if(duration==32767 && (count&128)){data_ov011_02227fa0[0]=count-128;}
else{
if(duration==2047)blend=16;else if(duration==32767)blend=0;else if(duration>=0)blend=func_0207ca38(0,16,0,data_ov011_02228ce0[3],duration);else blend=func_0207ca38(0,0,16,data_ov011_02228ce0[3],-duration);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
v0=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v0=(*v0&~1);
v1=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v1=(*v1&~2);
v2=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v2=(*v2&~4);
v3=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v3=(*v3&~8);
v4=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v4=(*v4&~16);
v5=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v5=(*v5&~32);
v6=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v6=(*v6|256);
v7=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v7=(*v7|512);
v8=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v8=(*v8|1024);
v9=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v9=(*v9|2048);
v10=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v10=(*v10|4096);
v11=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v11=(*v11|8192);
v12=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v12=(*v12&~192)|64;

M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,81)=16-blend;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,82)=blend;
gCur3DSpriteEngine=saved;
if(count&128){data_ov011_02227fa0[0]=count-128;limit=data_ov011_02227fa0[0];for(i=0;i<limit;i++)flags[i]=1024;}
else flags[data_ov011_02227fa0[0]-1]=1024;
}
if(position&32768)position-=32768;
else{n=p[57];if(n%2)n--;limit=data_ov011_02227f50[n];position=func_0207ca38(0,position,48,data_ov011_02228ce0[5],limit);if(data_ov011_02228ce0[5]<limit)data_ov011_02228ce0[5]++;}
for(j=0;j<data_ov011_02227fa0[0];j++){
base=position+j*18;tile=j*64;
func_01ffac9c(0,flags[j]|((base+offsets[j])&255),(tile)&1023,data_02101f5c,0);
func_01ffac9c(128,flags[j]|((base+offsets[j])&255),(tile+32)&1023,data_02101f5c,0);
if(func_020e31e0()==4 && p[57]>=8)func_01ffac9c(0,flags[0]|74,128,data_02101f0c,0);
}
data_ov011_02228ce0[3]++;
if(data_ov011_02228ce0[3]>(duration&32767)){
i=0;data_ov011_02228ce0[3]=i;data_ov011_02227fa0[0]++;
if(data_ov011_02227fa0[0]>count){data_ov011_02227fa0[0]=count;if(duration>0)data_ov011_02228ce0[3]=duration;else data_ov011_02228ce0[3]=i;}
}
return 0;
}

void func_ov011_02223764(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, u16, s32);
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *data_027e01d8;
    extern u16 data_ov011_02228ce0[];
    u16 *sp44 = 0;
    u16 *sp40 = 0;
    u16 *sp3C = 0;
    u16 *sp38 = 0;
    u16 *sp34 = 0;
    u16 *sp30 = 0;
    u16 *sp2C = 0;
    u16 *sp28 = 0;
    u16 *sp24 = 0;
    u16 *sp20 = 0;
    u16 *sp1C = 0;
    u16 *sp18 = 0;
    u16 *sp14 = 0;
    u16 *sp10 = 0;
    u16 *spC = 0;
    u16 *sp8 = 0;
    u16 *sp4 = 0;
    s32 temp_z = 0;
    s32 temp_z_2 = 0;
    s32 var_r1 = 0;
    s32 var_r2 = 0;
    s32 var_r2_2 = 0;
    void *temp_r0 = 0;
    void *temp_r1 = 0;
    void *temp_r1_2 = 0;
    void **var_r6 = 0;
    void **var_r7 = 0;
    void **var_r8 = 0;
    u16 *temp_r6 = 0;
    u16 *temp_r7 = 0;
    u16 *temp_r7_2 = 0;
    u16 *temp_r7_3 = 0;
    u16 *temp_r7_4 = 0;
    u16 *temp_r7_5 = 0;
    u16 *temp_r8 = 0;
    u16 *temp_r8_10 = 0;
    u16 *temp_r8_11 = 0;
    u16 *temp_r8_2 = 0;
    u16 *temp_r8_3 = 0;
    u16 *temp_r8_4 = 0;
    u16 *temp_r8_5 = 0;
    u16 *temp_r8_6 = 0;
    u16 *temp_r8_7 = 0;
    u16 *temp_r8_8 = 0;
    u16 *temp_r8_9 = 0;
    u8 var_r0 = 0;

    if (arg1 == 0) {
        var_r2 = 0;
        temp_r1 = data_027e01d8;
        do {
            temp_z = var_r2 == 0;
            var_r2 += 1;
            if (temp_z) {
                var_r6 = (void**)data_027e00c8;
            } else {
                var_r6 = (void**)data_027e00c4;
            }
            data_027e01d8 = var_r6;
            temp_r6 = *var_r6;
            sp44 = temp_r6 + 0x12;
            M2C_FIELD(temp_r6, s16 *, 0x12) = (s16) (*sp44 & ~0xC0);
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x51) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x52) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x53) = 0;
        } while (var_r2 < 2);
        data_027e01d8 = temp_r1;
        M2C_FIELD(&data_ov011_02228ce0, u16 *, 4) = 0U;
        return;
    }
    if (arg1 > 0) {
        var_r0 = func_0207ca38(0, 0x10, 0, M2C_FIELD(&data_ov011_02228ce0, u16 *, 4), arg1);
    } else {
        var_r0 = func_0207ca38(0, 0, 0x10, M2C_FIELD(&data_ov011_02228ce0, u16 *, 4), 0 - arg1);
    }
    if ((u32) var_r0 < 0x10U) {
        var_r2_2 = 0;
        temp_r1_2 = data_027e01d8;
        do {
            if (var_r2_2 == 0) {
                var_r8 = (void**)data_027e00c8;
            } else {
                var_r8 = (void**)data_027e00c4;
            }
            data_027e01d8 = var_r8;
            temp_r8 = *var_r8;
            sp40 = temp_r8 + 0x12;
            M2C_FIELD(temp_r8, s16 *, 0x12) = (s16) ((*sp40 & ~1) | 1);
            temp_r8_2 = *(void**)data_027e01d8;
            sp3C = temp_r8_2 + 0x12;
            M2C_FIELD(temp_r8_2, s16 *, 0x12) = (s16) (*sp3C | 2);
            temp_r8_3 = *(void**)data_027e01d8;
            sp38 = temp_r8_3 + 0x12;
            M2C_FIELD(temp_r8_3, s16 *, 0x12) = (s16) (*sp38 | 4);
            temp_r8_4 = *(void**)data_027e01d8;
            sp34 = temp_r8_4 + 0x12;
            M2C_FIELD(temp_r8_4, s16 *, 0x12) = (s16) (*sp34 | 8);
            temp_r8_5 = *(void**)data_027e01d8;
            sp30 = temp_r8_5 + 0x12;
            M2C_FIELD(temp_r8_5, s16 *, 0x12) = (s16) (*sp30 & ~0x10);
            temp_r8_6 = *(void**)data_027e01d8;
            sp2C = temp_r8_6 + 0x12;
            M2C_FIELD(temp_r8_6, s16 *, 0x12) = (s16) (*sp2C & ~0x100);
            temp_r8_7 = *(void**)data_027e01d8;
            sp28 = temp_r8_7 + 0x12;
            M2C_FIELD(temp_r8_7, s16 *, 0x12) = (s16) (*sp28 & ~0x200);
            temp_r8_8 = *(void**)data_027e01d8;
            sp24 = temp_r8_8 + 0x12;
            M2C_FIELD(temp_r8_8, s16 *, 0x12) = (s16) (*sp24 & ~0x400);
            temp_r8_9 = *(void**)data_027e01d8;
            sp20 = temp_r8_9 + 0x12;
            M2C_FIELD(temp_r8_9, s16 *, 0x12) = (s16) (*sp20 & ~0x800);
            temp_r8_10 = *(void**)data_027e01d8;
            sp1C = temp_r8_10 + 0x12;
            M2C_FIELD(temp_r8_10, s16 *, 0x12) = (s16) (*sp1C & ~0x1000);
            var_r2_2 += 1;
            temp_r8_11 = *(void**)data_027e01d8;
            sp18 = temp_r8_11 + 0x12;
            M2C_FIELD(temp_r8_11, s16 *, 0x12) = (s16) ((*sp18 & ~0xC0) | 0xC0);
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x51) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x52) = 0;
            M2C_FIELD(*(void**)data_027e01d8, u8 *, 0x53) = var_r0;
        } while (var_r2_2 < 2);
        data_027e01d8 = temp_r1_2;
    } else {
        temp_r0 = data_027e01d8;
        var_r1 = 0;
        do {
            temp_z_2 = var_r1 == 0;
            var_r1 += 1;
            if (temp_z_2) {
                var_r7 = (void**)data_027e00c8;
            } else {
                var_r7 = (void**)data_027e00c4;
            }
            data_027e01d8 = var_r7;
            temp_r7 = *(void**)data_027e01d8;
            sp14 = temp_r7;
            *temp_r7 = *sp14 & ~0x10;
            temp_r7_2 = *(void**)data_027e01d8;
            sp10 = temp_r7_2;
            *temp_r7_2 = *sp10 & ~0x20;
            temp_r7_3 = *(void**)data_027e01d8;
            spC = temp_r7_3;
            *temp_r7_3 = *spC & ~0x40;
            temp_r7_4 = *(void**)data_027e01d8;
            sp8 = temp_r7_4;
            *temp_r7_4 = *sp8 & ~0x80;
            temp_r7_5 = *(void**)data_027e01d8;
            sp4 = temp_r7_5;
            *temp_r7_5 = *sp4 | 0x100;
        } while (var_r1 < 2);
        data_027e01d8 = temp_r0;
    }
    M2C_FIELD(&data_ov011_02228ce0, u16 *, 4) = (u16) (M2C_FIELD(&data_ov011_02228ce0, u16 *, 4) + 1);
    ((M2C_UNK(*)(M2C_UNK,u8,s32,M2C_UNK,s32))func_ov011_022231f8)(arg0, (u8)(arg2 | 0x80), 0x7FFF, 0x80, arg3);
}

void func_ov011_02223b70(s32 unused,s32 value,u32 mode) {
void func_02082a8c(void*,void*);
ContextTemplate temp=data_ov011_02227f28;
void *saved,*p; s32 i;
if(mode<2)return;
i=0;
if(value==0){saved=gCur3DSpriteEngine;
do {
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;return;}
((s16*)&temp)[7]=value;
((s16*)&temp)[6]=((s16*)&temp)[7];
saved=gCur3DSpriteEngine;
do {
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
