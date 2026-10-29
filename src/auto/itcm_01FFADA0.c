/* 12 functions from 0x01FFADA0 to 0x01FFBD90 (itcm), found by ds-decomp. */
#include "common.h"

typedef struct UnkB454Bits { u32 value : 8; u32 rest : 24; } UnkB454Bits;

M2C_UNK func_01ffada0(M2C_UNK a0, M2C_UNK a1, M2C_UNK a2, M2C_UNK a3, M2C_UNK a4) { (void)a0;(void)a1;(void)a2;(void)a3;(void)a4; return 0; }

void func_01ffb114(s32 arg0, s32 arg1, s32 arg2) {
    extern void *data_027e0a90;
    extern s8 *data_027e00cc;
    extern void **gCurrentMap;
    extern u8 data_ov000_021b55c0[];
    extern s32 data_027e0a94;
    extern void *data_027e0a98;
    s32 func_020d280c(s32, s32, s32);

    u8 *q = (u8 *)data_027e0a90;
    s8 *terrain = data_027e00cc;
    u8 q0 = q[0];
    u8 q1 = q[1];
    u8 r5 = (u8)(arg1 + q0);
    u8 r4 = (u8)(arg2 + q1);
    s16 score;
    u8 terrainType;
    void *m;
    u16 row;
    s8 costVal;
    u8 terrainAttr;
    void **tablePtr;
    s8 *signedTable;
    s16 field22;
    u8 *cursor;

    if (r5 >= (u8)terrain[0x24]) return;
    if (r4 >= (u8)terrain[0x25]) return;

    m = *gCurrentMap;
    field22 = *(s16 *)(terrain + 0x22);
    row = *(u16 *)((u8 *)m + r4 * 2 + 0x3758);
    tablePtr = (void **)((u8 *)m + q1 * 4 + 0x52e8);
    signedTable = (s8 *)tablePtr[0];
    costVal = signedTable[q0];
    terrainType = ((u8 *)m)[r5 + row + 0x1000 + 0x420] & 0x1f;
    terrainAttr = (u8)terrain[terrainType];
    score = (s16)(costVal + terrainAttr);

    if (field22 & 0x10) {
        if (data_ov000_021b55c0[terrainType] != 0) {
            s32 mapField = *(u16 *)((u8 *)m + 0x52b6);
            if (func_020d280c(mapField, r5, r4) == 0) {
                score = 0x00ff;
            }
            m = *gCurrentMap;
            tablePtr = (void **)((u8 *)m + r4 * 4 + 0x52e8);
            if (score >= (s16)((u8 *)tablePtr[0])[r5]) {
                return;
            }
        }
    }

    if (field22 & 0x0d) {
        s8 cellType = ((s8 *)m)[r5 + row];
        if (cellType == 0) {
            goto enqueue;
        }
    }

enqueue:
    if (score > *(s16 *)(terrain + 0x20)) return;
    if (data_027e0a94 >= 0x15d) return;
    data_027e0a94++;
    cursor = (u8 *)data_027e0a98;
    cursor[0] = r5;
    cursor[1] = r4;
    cursor[2] = (u8)arg0;
    cursor[3] = (u8)score;
    data_027e0a98 = cursor + 4;
    m = *gCurrentMap;
    tablePtr = (void **)((u8 *)m + r4 * 4 + 0x52e8);
    ((u8 *)tablePtr[0])[r5] = (u8)score;
}

void func_01ffb3d0(s8 arg0) {
extern void **gCurrentMap;
s32 y=0,x; void *base=*gCurrentMap;
for(;y<M2C_FIELD(base,u16 *,0x5146);y++) {
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++) {
((s8 **)base)[y+0x14ba][x]=arg0;
base=*gCurrentMap;
}
}
}

void func_01ffb454(s32 arg0) {
extern u8 data_ov000_021b5bfc[]; extern u8 data_0212616c[]; extern s8 *data_027e00cc; extern void **gCurrentMap; extern u8 data_02168f08[];
s32 func_020a33c4(s32);
s32 i; u8 *unit=data_ov000_021b5bfc+arg0*0x70;
for(i=0;i<32;i++) {
void *base=*gCurrentMap;
s32 index=M2C_FIELD(base,u16 *,0x52b6);
u8 *entry=(u8 *)base+0x67a4+index*0x8c;
u32 variant;
s32 type;
s8 *table;
variant=(u32)(M2C_FIELD(data_02168f08,u16 *,12)<<18)>>31; if(variant) variant=((UnkB454Bits *)(entry+0x6c))->value;
type=func_020a33c4(index);
table=M2C_FIELD(data_0212616c+variant*0x9c+type*0x28+entry[0x25]*4,s8 **,0x64);
data_027e00cc[i]=(table+unit[0x12]*32)[i];
}
}

#pragma opt_peephole off
void func_01ffb50c(void) {
extern s8 data_ov000_021b54e0[]; extern s8 *data_027e00cc;
s32 i; s8 *p=data_ov000_021b54e0;
for(i=0;i<32;i++) { s32 value=*p++; if(value) data_027e00cc[i]=1; else ((u8 *)data_027e00cc)[i]=255; }
}
#pragma opt_peephole reset
void func_01ffb554(s32 arg0) {
extern void **gCurrentMap; extern s8 *data_027e00cc;
s32 i=0; void *base=*gCurrentMap;
for(;i<M2C_FIELD(base,u16 *,0x5146);i++) {
((s32 *)base)[i+0x14ba]=arg0+((u16 *)base)[i+0x1bac];
base=*gCurrentMap;
}
data_027e00cc[0x24]=M2C_FIELD(base,u16 *,0x5144);
data_027e00cc[0x25]=M2C_FIELD(*gCurrentMap,u16 *,0x5146);
}

void func_01ffb5ec(s32 cx,s32 cy,s32 radius,s8 value){
extern void **gCurrentMap;
s32 y,x,end,d,w;void *base;
d=radius;
for(y=cy;y<=cy+radius;y++,d--){
base=*gCurrentMap;if(y>=M2C_FIELD(base,u16 *,0x5146))break;
w=d*2+1;x=cx-d;if(x<0){w+=x;x=0;}
end=x+w;if(end>M2C_FIELD(base,u16 *,0x5144))end=M2C_FIELD(base,u16 *,0x5144);
for(;x<end;x++)((s8 **)*gCurrentMap)[y+0x14ba][x]=value;
}
d=radius-1;
for(y=cy-1;y>=cy-radius;y--,d--){
if(y<0)break;
base=*gCurrentMap;w=d*2+1;x=cx-d;if(x<0){w+=x;x=0;}
w=x+w;if(w>M2C_FIELD(base,u16 *,0x5144))w=M2C_FIELD(base,u16 *,0x5144);
for(;x<w;x++)((s8 **)*gCurrentMap)[y+0x14ba][x]=value;
}
}

void func_01ffb734(int cx,int cy,int radius,s8 value) {
 extern void **gCurrentMap;
 int x,d,right,bottom,left,top; void *base=*gCurrentMap;
 left=cx-radius;if(left<0)left=0;top=cy-radius;if(top<0)top=0;
 right=M2C_FIELD(base,u16 *,0x5144)-1;if(cx+radius<right)right=cx+radius;
 bottom=M2C_FIELD(base,u16 *,0x5146)-1;if(cy+radius<bottom)bottom=cy+radius;
 for(;top<=bottom;top++)for(x=left;x<=right;x++){
 d=0;
 if(cx-x>0)d+=cx-x;else d+=x-cx;
 if(cy-top>0)d+=cy-top;else d+=top-cy;
 if(d>=0 && d<=radius)((s8 **)*gCurrentMap)[top+0x14ba][x]=value;
 }
}

void func_01ffb80c(s32 x, s32 y, s32 dir, s8 value) {
    extern void **gCurrentMap;
    switch (dir) {
    case 0: {
        void *base;
        s8 *row;
        --x;
        ++y;
        base = *gCurrentMap;
        if (!(y < M2C_FIELD(base, u16 *, 0x5146))) return;
        for (;;) {
            row = ((s8 **)base)[y + 0x14ba];
            ++y;
            row[x] = value;
            if (--x < 0) return;
            base = *gCurrentMap;
            if (!(y < M2C_FIELD(base, u16 *, 0x5146))) return;
        }
    }
    case 1:
    case 3: {
        void *base;
        s8 *row;
        ++y;
        base = *gCurrentMap;
        if (!(y < M2C_FIELD(base, u16 *, 0x5146))) return;
        for (;;) {
            row = ((s8 **)base)[y + 0x14ba];
            ++y;
            row[x] = value;
            base = *gCurrentMap;
            if (!(y < M2C_FIELD(base, u16 *, 0x5146))) return;
        }
    }
    case 2: {
        void *base;
        s8 *row;
        ++x;
        ++y;
        for (;;) {
            base = *gCurrentMap;
            if (!(x < M2C_FIELD(base, u16 *, 0x5144))) return;
            if (!(y < M2C_FIELD(base, u16 *, 0x5146))) return;
            row = ((s8 **)base)[y + 0x14ba];
            ++y;
            row[x] = value;
            ++x;
        }
    }
    default:
        return;
    }
}

void func_01ffb918(s32 arg0,s32 arg1,s32 arg2,s8 arg3,u8 arg4) {
extern void **gCurrentMap;
s32 radius=1,left,y,x; void *base;
if(arg4) radius+=2;
left=arg0-radius; arg2=arg0+radius;
if(left<0) left=0;
base=*gCurrentMap;
if(arg2>M2C_FIELD(base,u16 *,0x5144)-1) arg2=M2C_FIELD(base,u16 *,0x5144)-1;
for(arg0=0;arg0<M2C_FIELD(base,u16 *,0x5146);arg0++) {
for(x=left;x<=arg2;x++) {
((s8 **)*gCurrentMap)[arg0+0x14ba][x]=arg3;
}
base=*gCurrentMap;
}
}

void func_01ffb9c4(s8 arg0){
extern void **gCurrentMap;
s32 y,x;void *base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16*,0x5144);x++){
s8 *cell=((s8**)base)[y+0x14ba]+x;
if(*cell>=0 && arg0!=*cell){
if(x!=0 && cell[-1]<0)cell[-1]=arg0;
base=*gCurrentMap;
if(x!=M2C_FIELD(base,u16*,0x5144)-1){
cell=((s8**)base)[y+0x14ba]+x;
if(cell[1]<0)cell[1]=arg0;
}
if(y!=0){cell=((s8**)*gCurrentMap)[y+0x14b9];if(cell[x]<0)cell[x]=arg0;}
base=*gCurrentMap;
if(y!=M2C_FIELD(base,u16*,0x5146)-1){cell=((s8**)base)[y+0x14bb];if(cell[x]<0)cell[x]=arg0;}
}
base=*gCurrentMap;
}
}
}

void func_01ffbb04(void) {
}

