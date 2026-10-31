/* 24 functions from 0x021743F0 to 0x02175310 (ov000), found by ds-decomp. */
#include "common.h"

typedef struct { s32 fields[8]; } Ov000MenuState;
typedef struct { u16 pad[3]; u16 low:15, flag:1; } Ov000Flags;

void func_ov000_021743f0(void *arg0) {
    int func_020d4ea8(void);
    func_020d4ea8();
}

void func_ov000_021749b4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x13) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x14) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xC) = 1;
}

void func_ov000_021749d8(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x13) != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xC) = 0;
}

void func_ov000_021749fc(void *arg0, s32 arg1, s32 arg2) {
    void func_ov000_02174a84(void *, s32);
    M2C_UNK func_ov000_02175310(s32);
    extern Ov000Flags data_0215d9b8;
    extern Ov000MenuState *data_ov000_021df5fc;
    if (arg1 == 0) {
        func_ov000_02174a84(data_ov000_021df5fc, arg2);
        return;
    }
    if (((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 16) >> 31) == 1) {
        func_ov000_02174a84(data_ov000_021df5fc, arg2);
        return;
    }
    func_ov000_02175310(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0xC) = 4;
}

void func_ov000_02174a68(void *arg0) {
    M2C_UNK func_ov000_021755b4(s32);
    func_ov000_021755b4(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0xC) = 4;
}

void func_ov000_02174a84(void *arg0, s32 arg1) {
    M2C_UNK func_ov000_0217272c(s32);
    if (arg1 == -1) {
        M2C_FIELD(arg0, s32 *, 0xC) = 3;
        return;
    }
    func_ov000_0217272c(M2C_FIELD(arg0, s32 *, 4));
    M2C_FIELD(arg0, s32 *, 0xC) = 2;
}

void func_ov000_02174ab4(void *arg0) {
extern void **gCurrentMap;
extern Ov000Flags data_0215d9b8;
extern Ov000MenuState *data_ov000_021df5fc;
s32 func_ov000_0216ca8c(s32,s32);
void *unit;
void *base=*gCurrentMap;
s32 x=M2C_FIELD(base,s16 *,0x52c2);
s32 y=M2C_FIELD(base,s16 *,0x52c4);
u32 index=x+((u16 *)((u8 *)base+0x3758))[y];
unit=(u8 *)base+0x59a4+((u8 *)base)[index]*14;
if(!(u8)(M2C_FIELD((u8 *)base+(index>>3),u8 *,0x5201)&(1<<(index&7)))) unit=0;
else {
if(unit==0 || ((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0){
void *other=M2C_FIELD(base,void **,0x52d0);
if(other!=0 && M2C_FIELD(other,u8 *,1)==x && M2C_FIELD(other,u8 *,2)==y)unit=other;
}
if(unit && ((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0)unit=0;
}
index=func_ov000_0216ca8c(x,y);
switch(M2C_FIELD(arg0,s32 *,8)){
case 2: case 3: {
u16 flags=M2C_FIELD(&data_0215d9b8,u16 *,6);
void *state=data_ov000_021df5fc;
M2C_FIELD(&data_0215d9b8,u16 *,6)=flags & ~0x8000;
func_ov000_021749fc(state,(s32)unit,index);
break; }
case 4: {
u16 flags=M2C_FIELD(&data_0215d9b8,u16 *,6);
void *state=data_ov000_021df5fc;
M2C_FIELD(&data_0215d9b8,u16 *,6)=flags | 0x8000;
func_ov000_02174a84(state,index);
break; }
}
}

void func_ov000_02174be8(void) {
    M2C_UNK func_ov000_02173f78(void *);
    extern Ov000MenuState *data_ov000_021df5fc;
    func_ov000_02173f78(data_ov000_021df5fc);
}

void func_ov000_02174c00(void) {
    M2C_UNK func_020af1e4();
    func_020af1e4();
}

u8 func_ov000_02174c0c(void) {
    extern Ov000MenuState *data_ov000_021df5fc;
    u8 var_r0;
    if (data_ov000_021df5fc != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov000_02174c2c(void) {
    s32 *func_02082028(M2C_UNK);
    void *func_ov000_02173ea8(void *);
    M2C_UNK func_01ffa3dc(void *, s32);
    extern M2C_UNK data_ov000_021b8e5c;
    extern Ov000MenuState *data_ov000_021df5fc;
    void *var_r0;
    var_r0 = func_02082028(0x20);
    if (var_r0 != 0) {
        var_r0 = func_ov000_02173ea8(var_r0);
    }
    data_ov000_021df5fc = var_r0;
    func_01ffa3dc(&data_ov000_021b8e5c, 8);
}

void func_ov000_02174c64(void) {
    void func_ov000_021743f0(void *);
    extern Ov000MenuState *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return;
    func_ov000_021743f0(data_ov000_021df5fc);
}

void func_ov000_02174c88(void) {
    void func_ov000_021743ec(void *);
    void func_ov000_02173f30(void *);
    M2C_UNK func_02082040(s32);
    void func_01ffa9e4(void *);
    void func_020c127c(void);
    extern Ov000MenuState *data_ov000_021df5fc;
    extern M2C_UNK data_ov000_021b8e5c;
    void *temp;
    if (func_ov000_02174c0c() == 0) return;
    func_ov000_021743ec(data_ov000_021df5fc);
    temp = data_ov000_021df5fc;
    if (temp != 0) {
        func_ov000_02173f30(temp);
        func_02082040((s32)temp);
    }
    data_ov000_021df5fc = 0;
    func_01ffa9e4(&data_ov000_021b8e5c);
    func_020c127c();
}

void func_ov000_02174ce8(void) {
    extern Ov000MenuState *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return;
    M2C_FIELD(data_ov000_021df5fc, u8 *, 0x11) = 1;
}

void func_ov000_02174d10(s32 arg0, s32 arg1) {
    extern Ov000MenuState *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return;
    M2C_FIELD(data_ov000_021df5fc, u8 *, 0x11) = 1;
    ((void (*)())func_ov000_02174a68)(data_ov000_021df5fc, arg0, arg1);
}

s32 func_ov000_02174d50(void) {
    extern Ov000MenuState *data_ov000_021df5fc;
    s32 result;
    if (func_ov000_02174c0c() != 0) {
        result = M2C_FIELD(data_ov000_021df5fc, u8 *, 0x13);
    } else {
        result = 0;
    }
    return result;
}

s32 func_ov000_02174d78(void) {
    void func_ov000_02174ab4(void *);
    extern Ov000MenuState *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return 0;
    func_ov000_02174ab4(data_ov000_021df5fc);
    return 1;
}

void func_ov000_02174da4(s32 arg0, s32 arg1) {
extern u16 data_02168f14[];
extern void **gCurrentMap; extern void *gCur3DSpriteEngine; extern void *data_027e00c4; extern u32 data_027e007c[]; extern u32 data_027e0084[];
s32 func_0207c8ec(s32,s32); void func_01ffaacc(u16,u16,u16,void *,s32);
s32 total, minutes, fraction, palette, separator; void *map; void *saved;
total=data_02168f14[2]; if(total==0)return;
map=*gCurrentMap;
{void *player=(u8 *)map+M2C_FIELD(map,u16 *,0x52a4)*140;
s32 elapsed=M2C_FIELD(player,s32 *,0x682c);
if(!elapsed)return; total-=elapsed;}
if(total<0)total=0;
minutes=func_0207c8ec(total,60);fraction=func_0207c8ec((total%60)*100,60);
palette=8;separator=180;if(total<600){palette=10;separator=181;}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
func_01ffaacc(arg0,arg1,((182>>((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)|0x6000,data_027e007c,1);
func_01ffaacc(arg0+72,arg1,((fraction%10+140)&1023)|((palette&15)<<12),data_027e0084,1);
fraction=func_0207c8ec(fraction,10);
func_01ffaacc(arg0+64,arg1,((fraction%10+140)&1023)|((palette&15)<<12),data_027e0084,1);
func_01ffaacc(arg0+56,arg1,((separator>>((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)|0x6000,data_027e0084,1);
arg0+=48;
do{
func_01ffaacc(arg0,arg1,((minutes%10+140)&1023)|((palette&15)<<12),data_027e0084,1);
minutes=func_0207c8ec(minutes,10);arg0-=8;
}while(minutes);
gCur3DSpriteEngine=saved;
}

s32 func_ov000_02175074(void) {
    extern Ov000MenuState *data_ov000_021df5fc;
    return M2C_FIELD(data_ov000_021df5fc, s32 *, 0x1C);
}

/* Initialize the 0x14-byte sub-object stored at entry+0x10 (allocating it
 * and its 0x104-byte descriptor) and clear the leading fields of entry. */
void *func_ov000_02175088(void *entry) {
    s32 *func_02082028(M2C_UNK);
    s32 *alloc;

    M2C_FIELD(entry, s32 *, 0) = 0;
    M2C_FIELD(entry, s32 *, 4) = 0;
    M2C_FIELD(entry, s32 *, 8) = 0;
    M2C_FIELD(entry, s8 *, 0xC) = 0;
    alloc = func_02082028(0x104);
    M2C_FIELD(entry, s32 **, 0x10) = alloc;
    *alloc = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x18) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x1C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x20) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x24) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x28) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x34) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x30) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x44) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xC) = -1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 4) = 1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x58) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x5C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x48) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x49) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x50) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x4C) = 0x63;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x54) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x60) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xFC) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x100) = 0;
    return entry;
}

void *func_ov000_0217519c(void *arg0) {
    M2C_UNK func_02082040(s32);
    func_02082040(M2C_FIELD(arg0, s32 *, 0x10));
    return arg0;
}

void func_ov000_021751b4(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    func_01ff9ce8(0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02175230(void) {

}

void func_ov000_02175234(void *arg0){
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    void *saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 16), s32 *, 8) <= 0) {
        return;
    }

    switch (M2C_FIELD(arg0, s32 *, 4)) {
        case 1:
            func_020809c0(M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), 32, 32);
            func_ov000_021769dc(arg0);
            func_ov000_02176a0c(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 2:
            func_ov000_021769dc(arg0);
            func_ov000_02176a0c(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 0:
            M2C_FIELD(arg0, s32 *, 8)++;
            if (M2C_FIELD(arg0, s32 *, 8) >= 80) {
                M2C_FIELD(arg0, s32 *, 8) = 0;
            }
            if (M2C_FIELD(arg0, s32 *, 8) == 0 || M2C_FIELD(arg0, s32 *, 8) == 40) {
                func_ov000_02176a9c(arg0);
            }
            break;
    }

    func_ov000_02175fb0(arg0);
    gCur3DSpriteEngine = saved;
}

