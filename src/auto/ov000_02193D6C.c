/* 3 functions from 0x02193D6C to 0x02194AB8 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern u16 data_ov000_021aeef4[];
extern M2C_UNK data_ov000_021b5bfc;
#define MAP (*gCurrentMap)
#define SEL M2C_FIELD(MAP,u8**,0x52d0)
#define KIND(p) ((u32)((p)[0]<<26)>>26)
#define INFO ((u8*)&data_ov000_021b5bfc)
#define ROW(y) M2C_FIELD(MAP+(y)*2,u16*,0x3758)
#define CELL(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),u8*,off)
#define COST(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),s8*,off)
#define PATH(x,y) M2C_FIELD(MAP+(y)*4,s8**,0x52e8)[x]

void func_ov000_02193d6c(void *arg0) {
    (void)arg0;
}

void func_ov000_02194090(void) {
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b5bfc;
    void *map;
    void *base;
    void *unit;
    s32 height, width;
    s32 xx, yy;
    s32 rx = -1, ry = -1, state = 0;

    map = *gCurrentMap;
    base = *(void **)map;
    unit = *(void **)((u8 *)base + 0x5000 + 0x2D0);
    func_01ffc328(unit);

    map = *gCurrentMap;
    base = *(void **)map;
    height = *(u16 *)((u8 *)base + 0x5146);
    if (height > 0) {
        width = *(u16 *)((u8 *)base + 0x5144);
        if (width > 0) {
            for (yy = 0; yy < height; yy++) {
                for (xx = 0; xx < width; xx++) {
                    void *path;
                    signed char pval;
                    u16 rowOff;
                    u8 terrain;
                    void *cell;
                    u8 *attr;
                    u8 owner;
                    u8 low4;
                    u8 tableVal;
                    u8 selOwner;

                    path = *(void **)((u8 *)base + yy * 4 + 0x52E8);
                    pval = *((signed char *)path + xx);
                    if (pval < 0) continue;
                    rowOff = *(u16 *)((u8 *)base + yy * 2 + 0x3758);
                    terrain = *((u8 *)base + xx + rowOff);
                    cell = (u8 *)base + xx + rowOff;
                    if (terrain == 0) continue;
                    if (!func_ov000_021a8fc0(((u8 *)cell)[0x508])) continue;

                    rowOff = *(u16 *)((u8 *)base + yy * 2 + 0x3758);
                    terrain = *((u8 *)base + xx + rowOff);
                    attr = (u8 *)base + 0x59A4 + terrain * 0x0E;
                    owner = attr[0] & 0x3F;
                    low4 = attr[0x0B] & 0x0F;
                    tableVal = ((u8 *)&data_ov000_021b5bfc)[owner * 0x70 + 0x13];
                    if (!(tableVal & 0x20)) continue;
                    if (func_ov000_021a8984(low4)) continue;
                    selOwner = (*((u8 *)unit)) & 0x3F;
                    if (!func_ov000_021a995c(attr, selOwner)) continue;

                    if (state != 0 && state != 0x18) {
                        if (state != 0x19) continue;
                        if (owner == 0x18) continue;
                    }
                    rx = xx;
                    ry = yy;
                    state = owner;
                }
            }
        }
    }

    if (rx == -1) return;

    {
        void **m = *gCurrentMap;
        void *b = *m;
        void *selUnit = *(void **)((u8 *)b + 0x5000 + 0x2D0);
        u16 v;

        v = *(u16 *)((u8 *)selUnit + 0x08);
        v &= ~0xC000;
        *(u16 *)((u8 *)selUnit + 0x08) = v;

        if ((((u8 *)selUnit)[0x0B] & 0x0F) == 2 || ((((u8 *)selUnit)[0x0B] & 0x0F) == 5)) {
            ((u8 *)selUnit)[0x0B] &= 0xF0;
        }

        v = *(u16 *)((u8 *)selUnit + 0x08);
        v = (v & ~0x003F) | 0x003F;
        *(u16 *)((u8 *)selUnit + 0x08) = v;

        v = *(u16 *)((u8 *)selUnit + 0x08);
        v = (v & ~0x0FC0) | 0x0FC0;
        *(u16 *)((u8 *)selUnit + 0x08) = v;
    }

    func_ov000_0217c3a4();
    func_ov000_02199d74(rx, ry, 7, 0);
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_02194370(void){
s32 func_020d19b4(s32);s32 func_ov000_021a98e4(u32);
s32 func_ov000_021a43c4(void);s32 func_ov000_021a88c8(s32);s32 func_ov000_021a9934(u32,u32);
s32 func_ov000_0217d86c(void);void func_ov000_02194090(void);
void func_01ffb554(void*);void func_01ffada0(s32,s32,s32,s32,s32);void func_01ffb3d0(s32);
s32 func_ov000_021a8984(u32);s32 func_ov000_021a995c(u8*,u32);
s32 func_ov000_021a9084(u32);s32 func_ov000_021a911c(s16,s16,s16);
void func_ov000_0218a9ac(s32,s32);
s32 bestX=-1,bestY=-1,best=32767,index,offset,found,distance;
u32 mode;u8 *unit;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16*,10)<<26)>>29)&4))return;
if(!func_020d19b4(M2C_FIELD(MAP,u16*,0x52a4))&&func_ov000_021a98e4(KIND(SEL))==1){
if(KIND(SEL)!=26)return;
if(!func_ov000_021a43c4()&&!func_ov000_021a88c8(24)&&!func_ov000_021a88c8(25))return;
}
if((u32)(SEL[11]<<24)>>31)return;
if(((u32)(M2C_FIELD(SEL,u16*,6)<<25)>>25)<61)return;
if(!func_ov000_021a9934(24,KIND(SEL)))return;
if(func_ov000_0217d86c()==1)return;
func_ov000_02194090();
mode=(u8)(func_ov000_021a98e4(KIND(SEL))==2);
M2C_FIELD(SEL,u16*,8)=(M2C_FIELD(SEL,u16*,8)&~0xc000)|0x8000;
if(!mode){
func_01ffb554(MAP+0x3250);
func_01ffada0(SEL[1],SEL[2],KIND(SEL),110,0);
func_01ffb554(MAP+0x1e30);
}
func_01ffb554(MAP+0x2338);func_01ffb3d0(127);func_01ffb554(MAP+0x1e30);
found=0;
index=data_ov000_021aeef4[M2C_FIELD(MAP,u16*,0x52a4)]+1;
if(index<data_ov000_021aeef4[M2C_FIELD(MAP,u16*,0x52a4)]+51){offset=index*14;
for(;index<data_ov000_021aeef4[M2C_FIELD(MAP,u16*,0x52a4)]+51;index++,offset+=14){
unit=(u8*)(MAP+0x59a4)+offset;
if(!KIND(unit)||!(INFO[KIND(unit)*112+19]&32)||func_ov000_021a8984((u32)(unit[11]<<28)>>28)||!func_ov000_021a995c(unit,KIND(SEL)))continue;
if(unit[12]){
if(mode==1)continue;
if(COST(unit[1],unit[2],0x3250)<0)continue;
}
func_01ffada0(unit[1],unit[2],KIND(unit),110,0);
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||!func_ov000_021a9084(CELL(x,y,0x1420)))continue;
{void *base=MAP;u16 row=M2C_FIELD(base+y*2,u16*,0x3758);u8 *cell=(u8*)base+x+row;
distance=M2C_FIELD(base+y*4,s8**,0x52e8)[x];
if(distance>=M2C_FIELD(cell,s8*,0x2338))continue;
if(!mode&&M2C_FIELD(cell,s8*,0x3250)<0)continue;
M2C_FIELD(cell+0x2000,s8*,0x338)=distance;found=1;}
}}
}
}
func_01ffada0(SEL[1],SEL[2],KIND(SEL),110,0);
if(!found){
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||(CELL(x,y,0x1420)&31)!=19||
!func_ov000_021a911c(M2C_FIELD(MAP,s16*,0x52a8),x,y))continue;
distance=PATH(x,y);if(best>=distance){bestX=x;bestY=y;best=distance;}
}}
if(bestX==-1)return;func_ov000_0218a9ac(bestX,bestY);return;
}
{s32 x,y;for(y=0;y<M2C_FIELD(MAP,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16*,0x5144);x++){
if(PATH(x,y)<0||!func_ov000_021a9084(CELL(x,y,0x1420)))continue;
distance=COST(x,y,0x2338);if(distance==127)continue;
distance=PATH(x,y)+distance;if(best>=distance){bestX=x;bestY=y;best=distance;}
}}
if(bestX==-1)return;func_ov000_0218a9ac(bestX,bestY);
}
#pragma pop
