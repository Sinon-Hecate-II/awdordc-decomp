/* 12 functions from 0x02189A08 to 0x0218A9AC (ov000), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6[8];
} UnkStruct_ov000_02189A08;

void func_ov000_02189a08(void) {
}

void func_ov000_02189df4(void) {
    M2C_UNK func_ov000_02188d64();
    M2C_UNK func_ov000_021895bc();
    extern void **gCurrentMap;
    if (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xC) != 0) {
        func_ov000_02188d64();
        return;
    }
    func_ov000_021895bc();
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_02189e2c(void){
extern void **gCurrentMap;extern s8 data_ov000_021b54c0[];s32 func_020d27ec(u8,u8);
s32 n=0,x,y;void *base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(base+(y<<2),s8 **,0x52e8),s8 *,x)>=0){
if(data_ov000_021b54c0[M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420)&31]!=0){
if(func_020d27ec(M2C_FIELD(base,u8 *,0x52d4),M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420))==0){
if((M2C_FIELD(M2C_FIELD(*gCurrentMap+(y<<1),u16 *,0x3758)+(*gCurrentMap+x),u8 *,0x1420)&31)==15)n+=30;else n++;
}}}
base=*gCurrentMap;
}}
return n;
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_02189f3c(void){
extern void **gCurrentMap;extern s8 data_ov000_021b54c0[];s32 func_020d27ec(u8,u8);
s32 n=0,x,y;void *base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(base+(y<<2),s8 **,0x52e8),s8 *,x)>=0){
if(data_ov000_021b54c0[M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420)&31]!=0){
if(func_020d27ec(M2C_FIELD(base,u8 *,0x52d4),M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420))==0){
void *b=*gCurrentMap;
void *cell=(b+x)+M2C_FIELD(b+(y<<1),u16 *,0x3758);
if(M2C_FIELD(b+M2C_FIELD(cell,s8 *,0x1928)*6,u8 *,0x6c63)==0 || (M2C_FIELD(cell,u8 *,0x1420)&31)==15){
if((M2C_FIELD(cell,u8 *,0x1420)&31)==15)n+=30;else n++;
}
}}}
base=*gCurrentMap;
}}
return n;
}
#pragma pop

#pragma pop
s32 func_ov000_0218a080(u8 arg0) {
    s32 func_ov000_021a98a8(u32);
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 count = 0;
    s32 i;
    u16 start = data_ov000_021aeef4[arg0];

    for (i = start + 1; i < data_ov000_021aeef4[arg0] + 0x33; i++) {
        UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap + 0x59A4))[i];
        u32 type = entry->unk0;
        if (type != 0 && !(entry->unk4 & 8) && func_ov000_021a98a8(type) != 0 && ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[entry->unk2][entry->unk1] != -1) {
            count += 1;
        }
    }
    return count;
}

/* Counts units of an enemy player whose map position is visible (-1 would mark blocked) and whose unit info has nonzero field at +0xC and bit0-2 of +0x13. */
s32 func_ov000_0218a140(u8 arg0) {
    s32 func_ov000_021a98a8(u32);
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    s32 count = 0;
    s32 i;
    u16 start = data_ov000_021aeef4[arg0];

    for (i = start + 1; i < data_ov000_021aeef4[arg0] + 0x33; i++) {
        UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap + 0x59A4))[i];
        u32 type = entry->unk0;
        if (type != 0 && !(entry->unk4 & 8) && func_ov000_021a98a8(type) == 0) {
            u8 *info = data_ov000_021b5bfc + entry->unk0 * 0x70;
            if ((info[0x13] & 7) && info[0xc] != 0 && ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[entry->unk2][entry->unk1] != -1) {
                count++;
            }
        }
    }
    return count;
}

s32 func_ov000_0218a230(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    s32 func_ov000_0218a080(u8);
    extern void **gCurrentMap;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) != 0 && func_020d1938(i) != 0) {
            count += func_ov000_0218a080(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

s32 func_ov000_0218a294(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    s32 func_ov000_0218a140(u8);
    extern void **gCurrentMap;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) != 0 && func_020d1938(i) != 0) {
            count += func_ov000_0218a140(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

s32 func_ov000_0218a2f8(void){
s32 func_020d1938(s32);s32 func_020d273c(u16,s32);
extern void **gCurrentMap;extern u16 data_ov000_021aeef4[];extern u8 data_ov000_021b5bfc[];
s32 count=0,p,end,i;
for(p=1;p<5;p++){
if(func_020d1938(p)!=0 && func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)!=1){
u16 start=data_ov000_021aeef4[p];
i=start+1;end=start+0x33;
for(;i<end;i++){
UnkStruct_ov000_02189A08 *entry=&((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && !(entry->unk4&8) && (data_ov000_021b5bfc[type*0x70+0x13]&7) && ((s8 **)((u8 *)*gCurrentMap+0x52e8))[entry->unk2][entry->unk1]!=-1)count++;
}}}return count;}

s32 func_ov000_0218a3fc(void){
s32 func_020d1938(s32);s32 func_020d273c(u16,s32);s32 func_ov000_021a98a8(u32);
extern void **gCurrentMap;extern u16 data_ov000_021aeef4[];extern u8 data_ov000_021b5bfc[];
s32 p,i;
for(p=1;p<5;p++){
if(func_020d1938(p)!=0){
for(i=data_ov000_021aeef4[p]+1;i<data_ov000_021aeef4[p]+0x33;i++){
UnkStruct_ov000_02189A08 *entry=&((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0&&(data_ov000_021b5bfc[type*112+0x13]&7)&&((s8 **)((u8 *)*gCurrentMap+0x52e8))[entry->unk2][entry->unk1]!=-1){
if(func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)==0){
if(func_ov000_021a98a8(entry->unk0)==0)goto success;
goto next;
}else{
if(func_ov000_021a98a8(entry->unk0)==0)goto next;
}
success:return 1;
}
next:;
}
}}
return 0;
}

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_0218a520(s32 x, s32 y) {
    s32 func_ov000_021a98e4(s32);
    s32 func_020a7cfc(void *);
    s32 func_ov000_02178e84(s32, s32);
    s32 func_ov000_021a9904(s32);
    s32 func_ov000_021a90a8(s32, s32, s32);
    s32 func_ov000_02178778(s32, s32);
    s32 func_ov000_021a9084(s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern u8 data_ov000_021df9bc[];
    extern u8 data_ov000_021dfc4c[];
    extern u8 *data_ov000_021df644;

    u8 unitKind = ((u8 *)*(void **)((u8 *)*gCurrentMap + 0x52D0))[0] & 0x3F;
    if (func_ov000_021a98e4(unitKind) != 0) {
        return 0;
    }
    if (func_020a7cfc(*(void **)((u8 *)*gCurrentMap + 0x52D0)) != 0) {
        return 0;
    }
    {
        u8 attr = data_ov000_021b5c0f[unitKind * 0x70];
        if (attr & 0x7) {
            u16 width = *(u16 *)((u8 *)*gCurrentMap + 0x5144);
            s32 idx = y * width + x;
            if (data_ov000_021df9bc[idx >> 3] & (1 << (idx & 7))) {
                return 1;
            }
            if (attr & 0x10) {
                s32 idx2 = y * width + x;
                if (data_ov000_021dfc4c[idx2 >> 3] & (1 << (idx2 & 7))) {
                    return 1;
                }
            }
            return 0;
        }
    }
    {
        u8 *ptr = data_ov000_021df644;
        u16 rowOffset = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
        u8 *cell = (u8 *)*gCurrentMap + x + rowOffset + 0x2000;
        if (cell[0x840] >= ptr[1]) {
            return 0;
        }
        if (cell[0xD48] >= ptr[2]) {
            return 0;
        }
    }
    if (!func_ov000_02178e84(x, y)) {
        return 0;
    }
    {
        u8 unitKind2 = ((u8 *)*(void **)((u8 *)*gCurrentMap + 0x52D0))[0] & 0x3F;
        u8 attr2 = data_ov000_021b5c0f[unitKind2 * 0x70];
        if (attr2 == 0x20) {
            return 0;
        }
        if (func_ov000_021a9904(unitKind2) == 2) {
            return 0;
        }
    }
    {
        u16 rowOffset = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
        u8 terrain = ((u8 *)*gCurrentMap + x + rowOffset + 0x1000)[0x420] & 0x1F;
        if (terrain != 0x13 && terrain != 0x15) {
            return 0;
        }
    }
    {
        u8 selByte = ((u8 *)*gCurrentMap)[0x52D4];
        if (!func_ov000_021a90a8(selByte, x, y)) {
            return 0;
        }
    }
    if (func_ov000_02178778(x, y) == 1) {
        return 0;
    }
    {
        u16 rowOffset = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
        u8 finalByte = ((u8 *)*gCurrentMap + x + rowOffset + 0x1000)[0x420];
        if (func_ov000_021a9084(finalByte) != 0) {
            return 0;
        }
    }
    return 1;
}
#pragma pop
s32 func_ov000_0218a798(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_021a8a38(s32, s32, s32, s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    void *map;
    void *selected;
    s32 savedAttr;
    s32 bestVisible = 0x7FFFFFFF;
    s32 bestOther = 0x7FFFFFFF;
    s32 i;
    s32 end;
    s32 x;
    s32 y;
    UnkStruct_ov000_02189A08 *entry;
    u32 type;
    s32 d1;
    s32 val;

    map = *gCurrentMap;
    selected = M2C_FIELD(map, void **, 0x52D0);
    savedAttr = data_ov000_021b5c0f[((UnkStruct_ov000_02189A08 *)selected)->unk0 * 0x70];
    if (savedAttr & 0x7) { savedAttr = 0x7; }

    map = *gCurrentMap;
    i = data_ov000_021aeef4[M2C_FIELD(map, u16 *, 0x52A4)] + 1;
    end = data_ov000_021aeef4[M2C_FIELD(map, u16 *, 0x52A4)] + 0x33;
    if (i < end) {
        x = (s16)arg0;
        y = (s16)arg1;
        do {
            entry = &((UnkStruct_ov000_02189A08 *)((u8 *)map + 0x59A4))[i];
            type = entry->unk0;
            if (type != 0 && entry != (UnkStruct_ov000_02189A08 *)M2C_FIELD(map, void **, 0x52D0) && !(entry->unk4 & 0x8)) {
                u8 *info = data_ov000_021b5bfc + type * 0x70;
                u8 attr = info[0x13];
                if ((savedAttr & attr) && !(entry->unk4 & 0x1)) {
                    d1 = ManhattanDistance(x, y, entry->unk1, entry->unk2);
                    val = func_ov000_021a8a38(x, y, entry->unk1, entry->unk2) + (d1 << 8);
                    if (bestVisible >= val) { bestVisible = val; }
                } else {
                    d1 = ManhattanDistance(x, y, entry->unk1, entry->unk2);
                    val = func_ov000_021a8a38(x, y, entry->unk1, entry->unk2) + (d1 << 8);
                    if (bestOther >= val) { bestOther = val; }
                }
            }
            i += 1;
            map = *gCurrentMap;
            end = data_ov000_021aeef4[M2C_FIELD(map, u16 *, 0x52A4)] + 0x33;
        } while (i < end);
    }

    if (bestVisible != 0x7FFFFFFF) {
        return bestVisible;
    }
    if (bestOther != 0x7FFFFFFF) {
        return bestOther;
    }
    return func_ov000_021a8a38((s16)arg0, (s16)arg1, (s16)arg2, (s16)arg3);
}

