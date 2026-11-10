/* 4 functions from 0x02192D88 to 0x02193D6C (ov000), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
#pragma opt_if-conversion off
int func_ov000_02192d88(void){
extern void **gCurrentMap;
extern u16 *data_ov000_021df580;
extern s8 data_ov000_021b55a0[32];
void func_01ffc328(void); void func_01ffb9c4(s32);
s32 func_ov000_021a9d8c(s16,s16); u8 func_ov000_021a8ff0(s32);
s32 func_ov000_021a9860(s32,s32); s32 func_ov000_02178518(s32,s32,s16 *);
s32 func_ov000_0217bdb4(s32,s32);s32 func_ov000_0217bd44(s32,s32,s32,s32);
s32 SetMapCursor(s16,s16,s32,s32,s32);
s32 func_ov000_0217c08c(s32,s32,s32,s16 *);s32 func_020d27ec(s32,s32);
s32 x,y,bx,by,px,py,tx,ty,best,tie,score,value,id,kind;
s32 sx,sy,ux,uy;
s16 dest[2],pos[2];
u8 *unit;
id=M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,12);
unit=(u8 *)*gCurrentMap+0x59a4+id*14;
bx=-1;by=bx;px=bx;py=bx;tx=bx;ty=bx;best=bx;tie=0x7fff;
if(!id)return;
func_01ffc328();func_01ffb9c4(0x6f);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x)<0)continue;
if(func_ov000_021a9d8c((s16)x,(s16)y))continue;
if(func_ov000_021a8ff0(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)) && M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x508))continue;
if(!func_ov000_021a9860(x,y))continue;
if(!func_ov000_02178518(x,y,pos))continue;
if(M2C_FIELD(*gCurrentMap,u8 *,0x6c63+M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),s8 *,0x1928)*6) && !(data_ov000_021df580[4]&0x20)){
if(func_ov000_0217bdb4(x,y)==1)continue;
}
score=M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x);
value=M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2840)+M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2d48);
switch(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)&31){case 15:score+=100;break;case 17:score+=80;break;case 24:score+=60;break;case 18:score+=40;break;case 19:score+=20;break;case 22:score+=20;break;}
if(best>score)continue;
if(best==score && tie<value)continue;
best=score;tie=value;bx=x;by=y;px=pos[0];py=pos[1];
}}
if(best!=-1){M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|((u16)bx&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|(((u32)(u16)by<<26)>>20);
{u8 *rec=(u8 *)*gCurrentMap+0x6c60+M2C_FIELD(*gCurrentMap+(bx+M2C_FIELD(*gCurrentMap+by*2,u16 *,0x3758)),s8 *,0x1928)*6;rec[3]++;}
value=func_ov000_0217bd44(px,py,bx,by);
SetMapCursor((s16)px,(s16)py,8,(u8)value,0);}
sy=-1;sx=sy;uy=sy;ux=sy;best=sy;tie=best+0x8000;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x)<0)continue;
if(func_ov000_021a9d8c((s16)x,(s16)y))continue;
if(func_ov000_021a8ff0(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)) && M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x508))continue;
if(!func_ov000_02178518(x,y,pos))continue;
kind=(u32)(unit[0]<<26)>>26;
switch(kind){
case 1:if(!(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x3250)&0x80))continue;
if(!(data_ov000_021df580[4]&0x20)){if(!func_ov000_0217c08c(x,y,3,dest))continue;}
else{if(!func_ov000_021a9860(x,y))continue;dest[0]=x;dest[1]=(s16)y;}break;
case 2:if(!(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x3250)&0x40))continue;
if(!(data_ov000_021df580[4]&0x20)){if(!func_ov000_0217c08c(x,y,2,dest))continue;}
else{if(!func_ov000_021a9860(x,y))continue;dest[0]=x;dest[1]=(s16)y;}break;
default:continue;}
if(data_ov000_021b55a0[M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)&31] && func_020d27ec(M2C_FIELD(*gCurrentMap,u8 *,0x52d4),M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)))score=0;
else score=M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x);
value=M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2840)+M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2d48);
switch(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)&31){case 15:score+=100;break;case 17:score+=80;break;case 24:score+=60;break;case 18:score+=40;break;case 19:score+=20;break;case 22:score+=20;break;}
if(best>score)continue;
if(best==score && tie<value)continue;
best=score;tie=value;sx=x;sy=y;ux=pos[0];uy=pos[1];tx=dest[0];ty=dest[1];
}}
if(best==-1)return;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|((u16)tx&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|(((u32)(u16)ty<<26)>>20);
{u8 *rec=(u8 *)*gCurrentMap+0x6c60+M2C_FIELD(*gCurrentMap+(tx+M2C_FIELD(*gCurrentMap+ty*2,u16 *,0x3758)),s8 *,0x1928)*6;rec[3]++;}
value=func_ov000_0217bd44(ux,uy,sx,sy);
SetMapCursor((s16)ux,(s16)uy,8,(u8)value,0);
}
#pragma opt_if-conversion reset
#pragma opt_strength_reduction reset
void func_ov000_021935c4(void *arg0) { (void)arg0; }

u32 func_ov000_02193998(void) {
extern void **data_027e0058;
u16 flags;
u32 x;
u8 *p;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
x=(u32)(p[0]<<26)>>26; if(x!=13)return x;
flags=*(u16 *)(p+6);
x=(u32)(flags<<21)>>28;
if(x==0)return flags;
x=(u32)(flags<<16)>>27;
if(x==0)return x;
x=func_020cccdc(); if(!x)return x;
{s32 v=func_ov000_021a8b78(M2C_FIELD(*data_027e0058,void **,0x52d0));if(v>=3)return v;}
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
return SetMapCursor(p[1],p[2],24,0,0);
}

s32 func_ov000_02193a40(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_020d1938(s32);
    s32 func_020d273c(s32, s32);
    u8 func_ov000_021a8ff0(s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    u8 func_ov000_021786a8(s16 *);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s16 x, y;
    s32 i, best = 0x7fff;
    u8 *base, *rec, *rec7;
    u16 start;
    s16 coords[2];
    x = (s16)arg0;
    y = (s16)arg1;
    base = (u8 *)*gCurrentMap;
    start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52a4)];
    for (i = start + 1; i < start + 0x33; i++) {
        rec = base + 0x59a4 + i * 14;
        {
            u8 kind = rec[0] & 0x3f;
            u16 flags;
            u8 t;
            u16 row;
            if (kind == 0) continue;
            if (kind != 0xd) continue;
            flags = M2C_FIELD(rec, u16 *, 6);
            if (!((flags >> 11) & 0x1f)) continue;
            row = M2C_FIELD(base + arg1 * 2, u16 *, 0x3758);
            t = M2C_FIELD(base, u8 *, 0x1420 + arg0 + row) & 0x1f;
            if (t == 1) {
                if (arg2 == 0) continue;
            } else if (t == 9) {
                if (arg2 != 0) continue;
            }
            {
                s32 d = ManhattanDistance(x, y, rec[1], rec[2]);
                if (d < best) best = d;
            }
        }
    }
    rec = base + 0x6c60;
    rec7 = rec;
    while (rec[0] != 0xff) {
        u8 kind = rec[0];
        u8 rx = rec[1];
        u8 ry = rec[2];
        u16 row;
        u8 t;
        row = M2C_FIELD(base + ry * 2, u16 *, 0x3758);
        t = M2C_FIELD(base, u8 *, 0x1420 + rx + row) & 0x1f;
        (void)t;
        if (!func_ov000_021a8ff0(M2C_FIELD(base, u8 *, 0x1420 + rx + row))) {
            s32 d;
            if (arg2 != 0) {
                if (kind != 0x12 && kind != 0x14) {
                    rec += 6;
                    continue;
                }
            } else {
                if (kind != 0x13 && kind != 0x15) {
                    rec += 6;
                    continue;
                }
            }
            d = ManhattanDistance(x, y, rx, ry);
            if (d < best) best = d;
        }
        rec += 6;
    }
    rec7 = rec;
    if (best != 0x7fff) {
        goto done_func;
    }
    {
        s16 c0, c1;
        if (func_ov000_021786a8(coords)) {
            best = 0x7fff - ManhattanDistance(x, y, coords[0], coords[1]);
        } else {
            s32 player;
            for (player = 1; player < 5; player++) {
                if (!func_020d1938(player)) continue;
                if (func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), player) != 0) continue;
                {
                    u16 start2 = gPlayerUnitIdBase[player];
                    s32 i2;
                    for (i2 = start2 + 1; i2 < start2 + 0x33; i2++) {
                        u8 *rec2 = base + 0x59a4 + i2 * 14;
                        u8 kind2 = rec2[0] & 0x3f;
                        if (kind2 == 0) continue;
                        {
                            s32 d = ManhattanDistance(x, y, rec2[1], rec2[2]);
                            if (d < best) best = d;
                        }
                    }
                }
            }
        }
    }
done_func:
    return best;
}

