/* 9 functions from 0x02187188 to 0x02187F7C (ov000), found by ds-decomp. */
#include "common.h"
extern void (*data_ov000_021df648)(void);
void func_ov000_02188338(void);
extern void **gCurrentMap;
extern u32 data_027e15bc;

s32 func_ov000_02187188(s32 x, s32 y, u8 *unit) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0e[];
    extern s8 data_ov000_021b55a0[];
    extern M2C_UNK data_0212616c;
    s32 func_ov000_021a9d8c(s16, s16);
    s32 func_020d27ec(s32, s32);
    s32 func_020d0654(s32, s32, s32);
    s32 func_0207c8ec(s32, s32);
    s32 func_ov000_021a9214(void *, s32, s32);
    s32 func_ov000_021a93a8(void *, s32, s32);
    s32 result = 0;
    s32 w;
    void *base;
    s32 tile, kind;

    if (x < 0 || y < 0 || x >= M2C_FIELD(*gCurrentMap, u16 *, 0x5144) || y >= M2C_FIELD(*gCurrentMap, u16 *, 0x5146)) {
        return -1;
    }
    if (func_ov000_021a9d8c((s16)x, (s16)y)) {
        return -1;
    }
    base = *gCurrentMap;
    kind = (u32)(unit[0] << 26) >> 26;
    tile = M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), u8 *, 0x1420) & 0x1f;
    if (M2C_FIELD((s8 *)M2C_FIELD(&data_0212616c, void **, 0x64) + data_ov000_021b5c0e[kind * 0x70] * 32, s8 *, tile) < 0) {
        return -1;
    }
    w = M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), u8 *, 0x2d48);
    if (data_ov000_021b55a0[tile] == 0 || func_020d27ec(M2C_FIELD(base, u8 *, 0x52d4), M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), u8 *, 0x1420)) == 0) {
        base = *gCurrentMap;
        result += (func_0207c8ec(func_020d0654(M2C_FIELD(base, u16 *, 0x52a4), 1, tile), 10) + 1) << 4;
    }
    result += (0x100 - w) << 8;
    if (data_ov000_021b55a0[tile] == 0) {
        if (func_ov000_021a9214(unit, x, y) == 1) {
            result += 0x10000;
        }
    }
    if (func_ov000_021a93a8(M2C_FIELD(*gCurrentMap, void **, 0x52d0), x, y) == 1) {
        result += 0x20000;
    }
    return result;
}

s32 func_ov000_02187320(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    s32 func_ov000_02187188(s32, s32, u8 *);
    extern void **data_027e0058;
    extern u32 data_027e15bc;
    s32 sp2C;
    s32 sp28;
    void *sp24;
    s32 sp20;
    s32 sp1C;
    void *sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *sp4;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 temp_r1_5;
    s32 temp_r1_6;
    s32 temp_r5;
    s32 temp_r6;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r8;
    s32 var_r8_2;
    u8 temp_r1;
    u8 temp_r1_4;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r3;
    void *temp_r4;

    sp0 = arg1;
    temp_r4 = *data_027e0058;
    sp4 = arg3;
    temp_r1 = M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x52D0), u8 *, 0xC);
    if (temp_r1 == 0) {
        return 0;
    }
    sp1C = temp_r1 * 0xE;
    sp18 = temp_r4 + 0x59A4;
    temp_r0 = arg0 - 1;
    sp14 = temp_r0;
    var_r4 = 0;
    M2C_FIELD(arg2, s16 *, 0) = 0x270F;
    if (temp_r0 < 0) {
        sp14 = 0;
    }
    var_r7 = sp0 - 1;
    temp_r1_2 = arg0 + 1;
    if (var_r7 < 0) {
        var_r7 = 0;
    }
    temp_r2 = *data_027e0058;
    var_r8 = M2C_FIELD(temp_r2, u16 *, 0x5144) - 1;
    if (temp_r1_2 < var_r8) {
        var_r8 = temp_r1_2;
    }
    temp_r1_3 = sp0 + 1;
    temp_r0_2 = M2C_FIELD(temp_r2, u16 *, 0x5146) - 1;
    sp10 = temp_r0_2;
    if (temp_r1_3 < temp_r0_2) {
        sp10 = temp_r1_3;
    }
    if (var_r7 <= sp10) {
        do {
            var_r5 = sp14;
            if (var_r5 <= var_r8) {
                temp_r6 = sp0 - var_r7;
                sp20 = (s32) (s16) var_r7;
                do {
                    var_r1 = arg0 - var_r5;
                    if (var_r1 <= 0) {
                        var_r1 = var_r5 - arg0;
                    }
                    if (temp_r6 > 0) {
                        var_r0 = var_r1 + temp_r6;
                    } else {
                        var_r0 = var_r1 + (var_r7 - sp0);
                    }
                    if ((var_r0 >= 1) && (var_r0 <= 1)) {
                        temp_r0_3 = func_ov000_02187188((s32) var_r5, (s32) var_r7, (u8 *)(sp18 + sp1C));
                        if ((temp_r0_3 >= var_r4) && ((temp_r0_3 != var_r4) || !(data_027e15bc & 1))) {
                            var_r4 = temp_r0_3;
                            M2C_FIELD(arg2, s16 *, 0) = (s16) var_r5;
                            M2C_FIELD(arg2, s16 *, 2) = (s16) sp20;
                        }
                    }
                    var_r5 += 1;
                } while (var_r5 <= var_r8);
            }
            var_r7 += 1;
        } while (var_r7 <= sp10);
    }
    if (M2C_FIELD(arg2, s16 *, 0) == 0x270F) {
        return 0;
    }
    temp_r3 = *data_027e0058;
    temp_r1_4 = M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0xD);
    if (temp_r1_4 == 0) {
        return 1;
    }
    sp28 = temp_r1_4 * 0xE;
    M2C_FIELD(sp4, s16 *, 0) = 0x270F;
    sp24 = temp_r3 + 0x59A4;
    temp_r0_4 = arg0 - 1;
    spC = temp_r0_4;
    var_r6 = 0;
    if (temp_r0_4 < 0) {
        spC = 0;
    }
    var_r7_2 = sp0 - 1;
    temp_r1_5 = arg0 + 1;
    if (var_r7_2 < 0) {
        var_r7_2 = 0;
    }
    temp_r2_2 = *data_027e0058;
    var_r8_2 = M2C_FIELD(temp_r2_2, u16 *, 0x5144) - 1;
    if (temp_r1_5 < var_r8_2) {
        var_r8_2 = temp_r1_5;
    }
    temp_r1_6 = sp0 + 1;
    temp_r0_5 = M2C_FIELD(temp_r2_2, u16 *, 0x5146) - 1;
    sp8 = temp_r0_5;
    if (temp_r1_6 < temp_r0_5) {
        sp8 = temp_r1_6;
    }
    if (var_r7_2 <= sp8) {
        do {
            var_r4_2 = spC;
            if (var_r4_2 <= var_r8_2) {
                temp_r5 = sp0 - var_r7_2;
                sp2C = (s32) (s16) var_r7_2;
                do {
                    var_r1_2 = arg0 - var_r4_2;
                    if (var_r1_2 <= 0) {
                        var_r1_2 = var_r4_2 - arg0;
                    }
                    if (temp_r5 > 0) {
                        var_r0_2 = var_r1_2 + temp_r5;
                    } else {
                        var_r0_2 = var_r1_2 + (var_r7_2 - sp0);
                    }
                    if ((var_r0_2 >= 1) && (var_r0_2 <= 1)) {
                        if ((var_r4_2 == M2C_FIELD(arg2, s16 *, 0)) && (var_r7_2 == M2C_FIELD(arg2, s16 *, 2))) {
                        } else {
                            temp_r0_6 = func_ov000_02187188((s32) var_r4_2, (s32) var_r7_2, (u8 *)(sp24 + sp28));
                            if ((temp_r0_6 >= var_r6) && ((temp_r0_6 != var_r6) || !(data_027e15bc & 1))) {
                                var_r6 = temp_r0_6;
                                M2C_FIELD(sp4, s16 *, 0) = (s16) var_r4_2;
                                M2C_FIELD(sp4, s16 *, 2) = (s16) sp2C;
                            }
                        }
                    }
                    var_r4_2 += 1;
                } while (var_r4_2 <= var_r8_2);
            }
            var_r7_2 += 1;
        } while (var_r7_2 <= sp8);
    }
    if (M2C_FIELD(sp4, s16 *, 0) == 0x270F) {
        return 1;
    }
    return 2;
}

#pragma peephole off
void func_ov000_02187664(s32 arg0, s32 arg1) {
    extern void **gCurrentMap;
    s32 func_ov000_02187320(s32, s32, void *, void *);
    s32 func_ov000_0217bd44(s32, s32, s32, s32);
    s32 func_ov000_02188b50(s32, s32);
    void func_ov000_02199d74(s32, s32, s32, s32, s32);
    s32 func_ov000_021a98a8(u32);

    s16 pos1[2];
    s16 pos2[2];
    s32 t;
    s32 r;
    u8 *unitC;
    u8 *unitD;

    r = func_ov000_02187320(arg0, arg1, pos1, pos2);
    if (r == 0) return;
    t = func_ov000_0217bd44(arg0, arg1, pos1[0], pos1[1]);
    if (r < 2) return;
    if (func_ov000_02188b50(arg0, arg1) == 1) {
        func_ov000_02199d74((s16)arg0, (s16)arg1, 8, t & 0xff, func_ov000_0217bd44(arg0, arg1, pos2[0], pos2[1]) & 0xff);
        return;
    }
    unitC = (u8 *)*gCurrentMap + 0x59A4 + M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xC) * 0xE;
    if (func_ov000_021a98a8((u32)(unitC[0] << 26) >> 26) != 0) return;
    if (((u32)(unitC[0] << 26) >> 26) == 0x0D) return;
    if (((u32)(unitC[11] << 28) >> 28) >= 6) return;
    unitD = (u8 *)*gCurrentMap + 0x59A4 + M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xD) * 0xE;
    if (func_ov000_021a98a8((u32)(unitD[0] << 26) >> 26) != 0) return;
    if (((u32)(unitD[0] << 26) >> 26) == 0x0D) return;
    if (((u32)(unitD[11] << 28) >> 28) >= 6) return;
    unitD[11] = (unitD[11] & 0xF0) | ((u32)(unitC[11] << 28) >> 28);
    func_ov000_02199d74((s16)arg0, (s16)arg1, 8, t & 0xff, 0);
}
#pragma peephole reset
void func_ov000_02187820(void) {
    extern void **gCurrentMap;
    extern u32 data_027e15bc;
    s32 func_ov000_021a9d8c(s16, s16);
    s32 func_ov000_02186e64(s32, s32);
    void func_01ffc328(void *);
    void *selected;
    s32 bestX = -1;
    s32 bestY = -1;
    s32 bestVal = 0;
    s32 bestSub = 0x7fff;
    s32 x;
    s32 y;
    s32 value;
    s32 extra;
    s32 ret;

    selected = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    func_01ffc328(selected);
    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            if (((s8 **)((u8 *)*gCurrentMap + 0x52E8))[y][x] < 0) {
                continue;
            }
            if (func_ov000_021a9d8c((s16)x, (s16)y) != 0) {
                continue;
            }
            if (M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), s8 *, 0x3250) == 0) {
                continue;
            }
            ret = func_ov000_02186e64(x, y);
            if (ret == 0) {
                continue;
            }
            selected = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
            value = M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x3250);
            if (M2C_FIELD(selected, u8 *, 0xD) != 0 && ret >= 2) {
                value |= 0x100;
            }
            if (bestVal > value) {
                continue;
            }
            extra = M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x2840)
                  + M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x2D48) * 2;
            if (bestVal == value && bestSub < extra) {
                continue;
            }
            if (bestVal == value && bestSub == extra && (data_027e15bc & 1) != 0) {
                continue;
            }
            bestX = x;
            bestY = y;
            bestVal = value;
            bestSub = extra;
        }
    }
    if (bestVal == 0) {
        return;
    }
    func_ov000_02187664(bestX, bestY);
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov000_021879f4(void){
 extern u8 *data_ov000_021df580;
 s32 func_01ffada0();
 s32 func_ov000_02186e64(s32,s32);
 s32 func_0207c8ec(s32,s32);
 s32 func_0207c928(s32,s32);
 void func_ov000_0218a9ac(s32,s32);
 u8 *unit;
 s32 bestX,bestY,bestCost,bestFlag,y,x,flag,cost,mask;
 void *base;
 bestX=-1;bestY=-1;bestCost=32767;bestFlag=0;
 unit=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
 func_01ffada0(unit[1],unit[2],(u32)(unit[0]<<26)>>26,110,1);
 base=*gCurrentMap;
 for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
 for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++,base=*gCurrentMap){
 s32 v=M2C_FIELD(base+y*4,s8 **,0x52e8)[x];
 if(v<0 || v<=data_ov000_021df580[5])continue;
 if(M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16 *,0x3758),s8 *,0x3250)==0)continue;
 if(!func_ov000_02186e64(x,y))continue;
 cost=func_0207c8ec(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x],data_ov000_021df580[5])+1;
 if(func_0207c928(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x],data_ov000_021df580[5])==0)--cost;
 base=*gCurrentMap;
 flag=M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16 *,0x3758),u8 *,0x3250);
 if(bestCost<cost){
 if(bestFlag&128)continue;
 if(!(flag&128))continue;
 if(bestCost+1<cost)continue;
 }
 mask=bestFlag&128;
 if(!mask && (flag&128)){
 if(bestCost+1>=cost)goto accept;
 continue;
 }
 else if(mask && !(flag&128)){
 if(bestCost-1>cost)goto accept;
 continue;
 }
 {
 if(bestCost<cost)continue;
 if(bestCost==cost && bestFlag>flag)continue;
 }
 accept: bestX=x;bestY=y;bestCost=cost;bestFlag=flag;
 }
 }
 if(bestX==-1)return;
 func_ov000_0218a9ac(bestX,bestY);
}
#pragma pop
void func_ov000_02187c3c(void) {
    extern void **gCurrentMap;
    extern u8 *data_ov000_021df580;
    s32 func_01ffada0(s32, s32, s32, s32, s32, s32);
    s32 func_ov000_02186e64(s32, s32);
    s32 func_0207c8ec(s32, s32);
    s32 func_0207c928(s32, s32);
    void func_ov000_0218a9ac(s32, s32);

    s32 bestX = -1;
    s32 bestY = -1;
    s32 bestSub = 0x7fff;
    s32 bestVal = 0;
    s32 y, x, score;

    func_01ffada0(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0x1),
                  M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0x2),
                  ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52d0), u8 *, 0x0) << 26) >> 26),
                  0x6e, 1, -1);

    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            s32 val;
            if (M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x] < 0) continue;
            if (M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x] <= data_ov000_021df580[5]) continue;
            if (M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), s8 *, 0x3250) == 0) continue;
            if (func_ov000_02186e64(x, y) == 0) continue;
            val = func_0207c8ec(M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x], data_ov000_021df580[5]) + 1;
            if (func_0207c928(M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x], data_ov000_021df580[5]) == 0) val--;
            if (bestSub < val) continue;
            score = M2C_FIELD(*gCurrentMap + x + M2C_FIELD(*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x3250);
            if (bestSub != val) goto update;
            if (bestVal > score) continue;
        update:
            bestX = x;
            bestY = y;
            bestSub = val;
            bestVal = score;
        }
    }
    if (bestVal == 0) return;
    func_ov000_0218a9ac(bestX, bestY);
}
#pragma opt_strength_reduction reset
void func_ov000_02187e20(void) {
func_ov000_02187820();
if(data_ov000_021df648==func_ov000_02188338) func_ov000_021879f4();
func_ov000_02187c3c();
}

#pragma optimization_level 2
u8 func_ov000_02187e50(void) {
void *base=*gCurrentMap;
void *unit=M2C_FIELD(base,void **,0x52d0);
u32 v=M2C_FIELD(unit,u16 *,8);
s32 shift=v<<26; u32 x=(u32)shift>>26;
u32 y; u8 result;
if(x==63) return 0;
y=(u32)(v<<20)>>26;
if(((s8 **)((u8 *)base+0x52e8))[y][x]>=0) result=1; else result=0;
return result;
}
#pragma optimization_level reset
u8 func_ov000_021a9084(s32);
s32 func_ov000_02187eac(u16 *arg0) {
    extern void **gCurrentMap;
    void *base;
    s32 height;
    s32 width;
    s32 y = 0;
    s32 x;
    u16 rowoff;
    u8 v;

    base = *gCurrentMap;
    height = *(u16 *)((u8 *)base + 0x5146);
    if (height <= 0) return 0;
outer:
    width = *(u16 *)((u8 *)base + 0x5144);
    x = y;
    if (width > 0) {
        do {
            if (((s8 **)((u8 *)base + 0x52e8))[y][x] >= 0) {
                rowoff = *(u16 *)((u8 *)base + 0x3758 + y * 2);
                v = *(u8 *)((u8 *)base + 0x1420 + rowoff + x);
                if (func_ov000_021a9084(v)) {
                    arg0[0] = (u16)x;
                    arg0[1] = (u16)y;
                    return 1;
                }
            }
            base = *gCurrentMap;
            x = x + 1;
            width = *(u16 *)((u8 *)base + 0x5144);
        } while (x < width);
    }
    height = *(u16 *)((u8 *)base + 0x5146);
    y = y + 1;
    if (y < height) goto outer;
    return 0;
}

