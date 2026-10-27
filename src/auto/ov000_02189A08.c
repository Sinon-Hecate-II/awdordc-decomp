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

