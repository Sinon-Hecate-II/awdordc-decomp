/* 39 functions from 0x020A1944 to 0x020A28F4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 id:8; u16 index:4; u16 mode:4; } SaveInitEntry;

s32 func_020a1944(s32 arg0) {
    if (arg0 < 0xC8) {
        return 1;
    }
    if (arg0 < 0xFA) {
        return 2;
    }
    if (arg0 < 0x12C) {
        return 3;
    }
    return 4;
}

void func_020a196c(void) {
 s32 func_020cd2f8(void); s32 func_020a1da0(s32); s32 func_020a1e44(s32); s32 func_020a1f88(s32);
 s32 func_020a1d74(s32); void func_020a1a0c(void); void func_020a1adc(void);
 extern M2C_UNK gSpriteAnimConfig;
 s32 i, bits, mask;
 s32 value;
 M2C_FIELD(&gSpriteAnimConfig,u8 *,0x14) = func_020cd2f8();
 M2C_FIELD(&gSpriteAnimConfig,u8 *,0x10) = func_020a1da0(M2C_FIELD(&gSpriteAnimConfig,u8 *,0x14));
 M2C_FIELD(&gSpriteAnimConfig,u8 *,0x11) = func_020a1e44(M2C_FIELD(&gSpriteAnimConfig,u8 *,0x14));
 M2C_FIELD(&gSpriteAnimConfig,u8 *,0x12) = func_020a1f88(M2C_FIELD(&gSpriteAnimConfig,u8 *,0x14));
 M2C_FIELD(&gSpriteAnimConfig,u16 *,0x16) = func_020a1d74(M2C_FIELD(&gSpriteAnimConfig,u8 *,0x14));
 M2C_FIELD(&gSpriteAnimConfig,u8 *,0x13) = func_020a1944(M2C_FIELD(&gSpriteAnimConfig,u16 *,0x16));
 func_020a1a0c(); func_020a1adc();
 i=0; bits=M2C_FIELD(&gSpriteAnimConfig,s32 *,0x18);
 do {mask = -1 ^ (1 << i); i++; bits &= mask;} while(i<15);
 M2C_FIELD(&gSpriteAnimConfig,s32 *,0x18)=bits;
}

#pragma peephole off
void func_020a1a0c(void) {
    extern M2C_UNK gSpriteAnimConfig;
    u8 *ctr;
    u8 *arr;
    s32 j;
    s32 i;
    u8 *p;

    p = (u8 *)&gSpriteAnimConfig;
    for (i = 0; i < 4; i++, p++) {
        p[0] = 0;
        p[4] = 0;
        p[8] = 0;
    }
    ctr = (u8 *)&gSpriteAnimConfig;
    arr = (u8 *)&gSpriteAnimConfig;
    ctr[12] = 0;
    ctr[13] = 0;
    ctr[14] = 0;
    for (j = 1; j < 5; j++) {
        if (!IsPlayerPresent(j)) continue;
        switch (func_020cce64(j)) {
        case 1: {
            u8 idx = ctr[12];
            ctr[12] = idx + 1;
            arr[idx] = j;
            break;
        }
        case 2: {
            u8 idx = ctr[13];
            ctr[13] = idx + 1;
            arr[idx + 4] = j;
            break;
        }
        case 3: {
            u8 idx = ctr[14];
            ctr[14] = idx + 1;
            arr[idx + 8] = j;
            break;
        }
        default:
            break;
        }
    }
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_020a1adc(void){
extern s32 *gCurrentMap;extern u8 data_0215c340[],data_0215c334[];
s32 i,j,offset;register s32 y=0;u8 *out;u8 *base;s32 x;void **map2;u8 *rec,*attr; s32 cell,terrain;void **map;
out=data_0215c340;map=(void **)gCurrentMap;
for(j=1,offset=0x8c;j<5;j++,offset+=0x8c,out+=12){
M2C_FIELD(out,u16 *,12)=(u32)(M2C_FIELD((u8 *)*map+offset,s32 *,0x6810)<<24)>>24;
out[23]=M2C_FIELD((u8 *)*map+offset,u8 *,0x67c1);
for(i=0;i<8;i++)out[14+i]=0;
out[22]=0;
}
{map2=(void **)gCurrentMap;
for(y=0;y<M2C_FIELD(*map2,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD((base=*map2),u16 *,0x5144);x++){
cell=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)+0x508];
if(cell){
rec=data_0215c334+(cell>>6)*12;
rec[34]++;
attr=(u8 *)*map2+0x59a4+cell*14;
if(attr[12])rec[34]++;
if(attr[13])rec[34]++;
}
base=*map2;
terrain=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)+0x1420];
switch(terrain&31){case 16:{u8 *p=data_0215c334+(terrain>>5)*12;p[14]++;break;}
case 17:{u8 *p=data_0215c334+(terrain>>5)*12;p[15]++;break;}
case 18:{u8 *p=data_0215c334+(terrain>>5)*12;p[16]++;break;}
case 19:{u8 *p=data_0215c334+(terrain>>5)*12;p[17]++;break;}
case 20:{u8 *p=data_0215c334+(terrain>>5)*12;p[20]++;break;}
case 21:{u8 *p=data_0215c334+(terrain>>5)*12;p[21]++;break;}
case 22:{u8 *p=data_0215c334+(terrain>>5)*12;p[18]++;break;}
case 23:{u8 *p=data_0215c334+(terrain>>5)*12;p[19]++;break;}}
}
}}
}
#pragma pop
s32 func_020a1d74(s32 arg0) {
    extern M2C_UNK gSpriteAnimConfig;
    s32 var_r0;

    var_r0 = M2C_FIELD(&gSpriteAnimConfig, u8 *, 0x12) + (M2C_FIELD(&gSpriteAnimConfig, u8 *, 0x10) + M2C_FIELD(&gSpriteAnimConfig, u8 *, 0x11));
    if (var_r0 >= 0x3E8) {
        var_r0 = 0x3E7;
    }
    return var_r0;
}

s32 func_020a1da0(s32 arg0) {
 s32 func_020a8984(u16); s32 IsPlayerActive(s32); s32 func_0207c8ec(s32,s32);
 extern s32 *gCurrentMap;
 s32 base, result, difference;
 u16 current;
 base = func_020a8984(M2C_FIELD(*gCurrentMap, u16 *, 0x5142));
 if (IsPlayerActive(arg0) == 0) return 0;
 if (base == 0) return 0;
 current = M2C_FIELD(*gCurrentMap, u16 *, 0x52A2);
 difference = base - current;
 if (difference < 0) difference = -difference;
 if (current <= base) result = func_0207c8ec(difference * 100, base) + 100;
 else result = 100 - func_0207c8ec(difference * 100, base * 3);
 if (result < 0) result = 0;
 if (result > 150) result = 150;
 return result;
}

s32 func_020a1e44(s32 player) {
extern s32 *gCurrentMap;extern u16 data_02168f14;
s32 IsPlayerActive(s32);s32 func_0207c9c8(s32,s32);
s32 a,b,c,i,result;void *p,*q;
if(!IsPlayerActive(player))return 0;
if((u32)(data_02168f14<<29)>>29==0){
a=0;b=0;c=0;
for(i=1,p=(u8 *)*gCurrentMap+140;i<5;p=(u8 *)p+140,i++){
if(!M2C_FIELD(p,u8 *,0x67c2))continue;
q=(u8 *)*gCurrentMap+i*140;
{u32 team=M2C_FIELD((u8 *)*gCurrentMap+player*140,u8 *,0x67ca);if(team!=M2C_FIELD(q,u8 *,0x67ca))continue;}
if(a+M2C_FIELD(q,s32 *,0x6818)>=0xfffffff||b+M2C_FIELD(q,s32 *,0x681c)>=0xfffffff)continue;
a+=M2C_FIELD(q,s32 *,0x6818);b+=M2C_FIELD(q,s32 *,0x681c);c+=M2C_FIELD(q,s32 *,0x6824);
}
}else{
p=(u8 *)*gCurrentMap+0x67a4+player*140;
a=M2C_FIELD(p,s32 *,0x74);b=M2C_FIELD(p,s32 *,0x78);c=M2C_FIELD(p,s32 *,0x80);
}
if(!b)return 0;
result=func_0207c9c8((c*100+a)*2,b)-100;
if(result>=100)result=((result-100)>>1)+100;
if(result<0)result=0;if(result>150)result=150;
return result;
}

s32 func_020a1f88(s32 player) {
    extern s32 *gCurrentMap;
    extern s8 data_ov000_021b5580[];
    s32 IsPlayerActive(s32); u32 func_020d303c(s32);u32 func_020d30a8(s32);
    s32 func_0207c8ec(s32,s32);
    u32 own,enemy,other,buildings,extra,delta;
    s32 i,offset,playerOffset,clear,x,y,result;
    void *q; register void *base;
    if(!IsPlayerActive(player))return 0;
    playerOffset=player*140;
    own=0;enemy=0;extra=0;other=0;buildings=0;
    for(i=1,offset=140;i<5;i++,offset+=140) {
        base=(void *)*gCurrentMap;q=(u8 *)base+offset;
        if(M2C_FIELD(q,u8 *,0x67c2)) {
            if(M2C_FIELD((u8 *)(playerOffset+(u32)base),u8 *,0x67ca)==M2C_FIELD(q,u8 *,0x67ca)) {
                own+=func_020d303c(i);
                extra+=func_020d30a8(i);
                q=(u8 *)*gCurrentMap+offset;
                buildings+=M2C_FIELD(q,u16 *,0x67c6);
                other+=M2C_FIELD(q,u16 *,0x67c4);
            } else enemy+=func_020d303c(i);
        }
    }
    base=(void *)*gCurrentMap;
    clear=1;
    for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
        register u8 *row;
        for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
            row=(u8 *)base+M2C_FIELD(base,u16 *,0x3758+y*2)+x;
            if(data_ov000_021b5580[M2C_FIELD(row,u8 *,0x1420)&31]!=0)clear=0;
        }
    }
    delta=clear;
    if(clear){if(own>enemy)delta=own-enemy;else delta=0;}
    if(own+extra==0)return 0;
    other=enemy-(other+buildings);
    other=enemy-other;
    result=func_0207c8ec(((other+delta)*500)>>2,own+extra);
    if(result>=100)result=((result-100)>>1)+100;
    if(result<0)result=0;
    if(result>150)result=150;
    return result;
}

void func_020a2148(u16 *arg0) {
 s32 func_020846a4(void); s32 func_020cd6d4(void);
 u16 *func_020bfa74(void); void func_020bfa80(u16 *); void func_020bfebc(u16 *);
 s32 func_020a22fc(s32); s32 func_020a2370(s32); s32 func_020a23b4(s32);
 s32 i; u16 *p; u16 value;
 p=arg0;
 if(p==0) p=func_020bfa74();
 if(func_020846a4()!=0) return;
 if(func_020cd6d4()!=0) return;
 func_020bfa80(p); func_020bfebc(p);
 i=0;
 do {
 *p=(*p & ~0xff) | (u8)(u16)func_020a22fc(i+1);
 *p=(*p & ~0xf00) | ((u32)((u16)func_020a2370(i+1)<<28)>>20);
 value=func_020a23b4(i+1); i++;
 *p=(*p & ~0xf000) | ((u32)(value<<28)>>16);
 p++;
 }while(i<4);
}

void func_020a2204(u16 *arg0) {
u16 *func_020bfa74(void);
s32 func_020cd6d4(void);
void func_020c002c(u16 *);
s32 func_020846a4(void);
u32 func_020bf894(s32);
void func_020a230c(s32,s32);
void func_020a232c(s32,s32);
void func_020a23a4(s32,s32);
extern M2C_UNK data_0211faf4;
u16 *p;
s32 i;
u16 val;
s32 low;
s32 r6;
s32 r7;
s32 r8;
s32 idx;
s32 r9;
if(arg0==0){
p=func_020bfa74(); arg0=p;
}
p=arg0;
if(func_020cd6d4()!=0) return;
func_020c002c(p);
for(idx=1;idx<5;idx++){
func_020a230c(idx,0);
func_020a232c(idx,idx);
func_020a23a4(idx,0);
}
p=arg0; i=0;
do {
val=*p; r6=0; r9=i+1;
low=((SaveInitEntry *)p)->id;
r7=((SaveInitEntry *)p)->index;
r8=((SaveInitEntry *)p)->mode;
if(func_020bf894(low)) r6=((SaveInitEntry *)p)->id;
if(func_020846a4()){
r6=M2C_FIELD(&data_0211faf4,u8 *,r9); r7=r9; r8=0;
}
func_020a230c(r9,r6);
func_020a232c(r9,r7);
func_020a23a4(r9,r8);
i++;p++;
}while(i<4);
}

s32 func_020a22fc(s32 arg0) {
    extern M2C_UNK data_0215c386;
    return M2C_FIELD(&data_0215c386, u8 *, arg0);
}

void func_020a230c(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0215c386;
    M2C_FIELD(&data_0215c386, s8 *, arg0) = arg1;
}

void func_020a231c(s32 arg0, s8 arg1) {
    extern M2C_UNK data_0215c381;
    M2C_FIELD(&data_0215c381, s8 *, arg0) = arg1;
}

void func_020a232c(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0215c38b;
    M2C_FIELD(&data_0215c38b, s8 *, arg0) = arg1;
}

void func_020a233c(s32 arg0, s8 arg1) {
    extern M2C_UNK data_0215c390;
    M2C_FIELD(&data_0215c390, s8 *, arg0) = arg1;
}

void func_020a234c(s32 arg0, s16 arg1) {
 extern M2C_UNK data_0215c396;
 M2C_FIELD(&data_0215c396, s16 *, arg0 * 2) = arg1;
}

u8 func_020a2360(s32 arg0) {
    extern M2C_UNK data_0215c381;
    return M2C_FIELD(&data_0215c381, u8 *, arg0);
}

s32 func_020a2370(s32 arg0) {
    extern M2C_UNK data_0215c38b;
    return M2C_FIELD(&data_0215c38b, u8 *, arg0);
}

u8 func_020a2380(s32 arg0) {
    extern M2C_UNK data_0215c390;
    return M2C_FIELD(&data_0215c390, u8 *, arg0);
}

u16 func_020a2390(s32 arg0) {
 extern M2C_UNK data_0215c396;
 return M2C_FIELD(&data_0215c396, u16 *, arg0 * 2);
}

void func_020a23a4(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0215c37c;
    M2C_FIELD(&data_0215c37c, s8 *, arg0) = arg1;
}

s32 func_020a23b4(s32 arg0) {
    extern M2C_UNK data_0215c37c;
    return M2C_FIELD(&data_0215c37c, u8 *, arg0);
}

void func_020a23c4(void) {
    s32 IsPlayerActive(s32);
    M2C_UNK func_020d2470();
    extern s32 *gCurrentMap;
    s32 var_r5;
    s32 var_r6;

    var_r5 = 1;
    var_r6 = 0x8C;
    do {
        if (IsPlayerActive(var_r5) != 0) {
            M2C_FIELD((*gCurrentMap + var_r6), s8 *, 0x67C9) = 0;
            M2C_FIELD((*gCurrentMap + var_r6), s8 *, 0x67C8) = 0;
        }
        var_r5 += 1;
        var_r6 += 0x8C;
    } while (var_r5 < 5);
    func_020d2470();
}

#pragma opt_propagation off
s32 func_020a242c(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 GetUnitOwner(void *);
    u8 *GetPlayerSelectedUnit(s32);
    s32 GetPlayerCommanderId(s32);
    s32 func_020d0468(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020a7bd4(s32);
    extern u8 data_0211fbec[];
    s32 idx;
    u32 kind;
    s32 ret;

    M2C_FIELD(arg0, s8 *, 0x0) = 0;
    M2C_FIELD(arg0, s8 *, 0x1) = 0;
    M2C_FIELD(arg0, s8 *, 0x2) = 0;
    M2C_FIELD(arg0, s8 *, 0x3) = 0;
    M2C_FIELD(arg0, s8 *, 0x4) = 0;
    M2C_FIELD(arg0, s8 *, 0x5) = 0;
    M2C_FIELD(arg0, s8 *, 0x6) = 0;
    M2C_FIELD(arg0, s16 *, 0x8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;

    if (arg2 < 0 || arg3 < 0) { return 0; }

    idx = GetUnitOwner(arg1);
    if (GetPlayerSelectedUnit(idx) == (u8 *)arg1) {
        ret = GetPlayerCommanderId(idx);
    } else {
        ret = func_020d0468(idx, arg2, arg3);
    }

    kind = M2C_FIELD(arg1, u8 *, 0x0) << 26;
kind = kind >> 26;
    if (ret != -1) {

    M2C_FIELD(arg0, s16 *, 0x8) = M2C_FIELD(arg0, s16 *, 0x8) + 10;
    M2C_FIELD(arg0, s16 *, 0xA) = M2C_FIELD(arg0, s16 *, 0xA) + 10;

    {
        s8 *base = (s8 *)data_0211fbec + ret * 0x48;
        s8 *probe = base + kind;
        if (probe[0x11] != 0) {
            M2C_FIELD(arg0, s8 *, 0x0) = M2C_FIELD(arg0, s8 *, 0x0) + base[0x0];
            M2C_FIELD(arg0, s8 *, 0x1) = M2C_FIELD(arg0, s8 *, 0x1) + base[0x1];
            M2C_FIELD(arg0, s8 *, 0x2) = M2C_FIELD(arg0, s8 *, 0x2) + base[0x2];
            M2C_FIELD(arg0, s8 *, 0x3) = M2C_FIELD(arg0, s8 *, 0x3) + base[0x3];
            M2C_FIELD(arg0, s8 *, 0x4) = M2C_FIELD(arg0, s8 *, 0x4) + base[0x4];
            M2C_FIELD(arg0, s8 *, 0x5) = M2C_FIELD(arg0, s8 *, 0x5) + base[0x5];
            M2C_FIELD(arg0, s8 *, 0x6) = M2C_FIELD(arg0, s8 *, 0x6) + base[0x6];
            M2C_FIELD(arg0, s16 *, 0x8) = M2C_FIELD(arg0, s16 *, 0x8) + M2C_FIELD(base, s16 *, 0x8);
            M2C_FIELD(arg0, s16 *, 0xA) = M2C_FIELD(arg0, s16 *, 0xA) + M2C_FIELD(base, s16 *, 0xA);
        }
    }

    if (func_020a7bd4(kind) == 0) {
        M2C_FIELD(arg0, s16 *, 0x8) = 0;
    }
    if (func_020a7bd4(kind) < 2) {
        M2C_FIELD(arg0, s8 *, 0x6) = 0;
    }
    }
    return 1;
}
#pragma opt_propagation reset
s32 func_020a25bc(s32 arg0, s32 arg1) {
 extern M2C_UNK data_0211fbf8;
 return arg1 + M2C_FIELD(&data_0211fbf8, s8 *, arg0 * 0x48);
}

s32 func_020a25d8(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s16 *, 8);
}

s32 func_020a2608(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s16 *, 10);
}

s32 func_020a2638(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 3);
}

s32 func_020a2668(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 4);
}

s32 func_020a2698(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 2);
}

s32 func_020a26c8(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 6);
}

s32 func_020a26f8(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 5);
}

s32 func_020a2728(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 0);
}

s32 func_020a2758(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a242c(void *, void *, s32, s32);
 u32 data[3];
 func_020a242c(data, (void*)arg0, arg1, arg2);
 return M2C_FIELD(data, s8 *, 1);
}

s8 func_020a2788(s32 arg0, s32 arg1) {
 extern M2C_UNK data_0211fc18;
 return *(s8 *)(arg1 + (arg0 * 0x48 + (s32)&data_0211fc18));
}

s8 func_020a27a0(s32 arg0, s32 arg1) {
 extern M2C_UNK data_0211fbfd;
 return *(s8 *)(arg1 + (arg0 * 0x48 + (s32)&data_0211fbfd));
}

s32 func_020a27b8(s32 arg0, s32 arg1) {
    extern u16 data_02168f14;
    s32 var_r1;

    if (((u32) (data_02168f14 << 0x12) >> 0x1F) == 0) {
        return -1;
    }
    if (arg0 == 0) {
        return -1;
    }
    if (arg1 != 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    return var_r1 + ((arg0 - 1) * 2);
}

u8 func_020a27f8(s32 arg0,s32 arg1) {
extern s32 *gCurrentMap;
extern M2C_UNK data_0211fbfd;
s32 index;
u8 result;
index=func_020a27b8(((u32)(M2C_FIELD(*gCurrentMap+arg1*0x8C,s32 *,0x6810)<<24)>>24),0);
if(index==-1)return 0;
if(*(s8 *)(arg0+(index*0x48+(s32)&data_0211fbfd)))result=1;
else result=0;
return result;
}

s32 func_020a2868(s32 arg0,s32 arg1,s32 arg2) {
extern s32 *gCurrentMap;
extern M2C_UNK data_0211fbfd;
extern s16 data_0211fbf4;
s32 func_020a7bd4(s32);
s32 index;
s32 result;
index=func_020a27b8(((u32)(M2C_FIELD(*gCurrentMap+arg1*0x8C,s32 *,0x6810)<<24)>>24),arg2);
if(index==-1)return 0;
index*=0x48;
if(!*(s8 *)(arg0+((s32)&data_0211fbfd+index)))return 0;
if(func_020a7bd4(arg0) == 0) result = 0;
else result = M2C_FIELD(&data_0211fbf4,s16 *,index);
return result;
}

