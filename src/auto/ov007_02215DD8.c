/* 8 functions from 0x02215DD8 to 0x02216C94 (ov007), found by ds-decomp. */
#include "common.h"

s32 func_ov007_02215dd8(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 RandomIntRange(s32, s32);
    s32 func_ov007_022156a4();
    extern void **gCurrentMap;
    s32 temp_r0;
    s32 var_r6;
    void *temp_r2;

    var_r6 = 0;
loop_1:
    var_r6 += 1;
    if (var_r6 > 0x64) {
        return 0;
    }
    *arg0 = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1);
    temp_r0 = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1);
    *arg1 = temp_r0;
    temp_r2 = *gCurrentMap;
    if ((arg2 == M2C_FIELD((temp_r2 + ((*arg0 + M2C_FIELD((temp_r2 + (temp_r0 * 2)), u16 *, 0x3758)) * 2)), u16 *, 0xA10)) && (func_ov007_022156a4() != 0)) {
        return 1;
    }
    goto loop_1;
}

s32 func_ov007_02215e94(s32 *arg0, s32 *arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 RandomIntRange(s32, s32);
    s32 ManhattanDistance(s16, s16, s16, s16);
    extern void **gCurrentMap;
    s32 temp_r0;
    s32 temp_r1;
    s32 var_r5;

    var_r5 = 0;
loop_1:
    var_r5 += 1;
    if (var_r5 > 0x64) {
        return 0;
    }
    *arg0 = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1);
    *arg1 = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1);
    temp_r1 = *arg0;
    if ((arg2 == M2C_FIELD((*gCurrentMap + ((temp_r1 + M2C_FIELD((*gCurrentMap + (*arg1 * 2)), u16 *, 0x3758)) * 2)), u16 *, 0xA10)) && (ManhattanDistance(M2C_FIELD(arg3, s16 *, 0), M2C_FIELD(arg3, s16 *, 2), (s16) temp_r1, (s16) *arg1) <= arg4)) {
        return 1;
    }
    goto loop_1;
}

void func_ov007_02216118(s32 arg0, s32 arg1) {
    s32 func_ov007_02214ff8(s32, s32, s32);
    s32 func_ov007_02215128(s32, s32);
    s32 func_ov007_02215254(s32, s32, s32);
    s32 Map_MarkUnitsMoved(void);
    extern void **gCurrentMap;
    extern u8 data_ov007_02221a84[];

    s32 sp0 = 0;
    s8 *row;
    s32 r6;
    s32 r7;
    void *r0;

loop_outer:
    r7 = 0;
    r0 = *gCurrentMap;
    if (M2C_FIELD(r0, u16 *, 0x5146) > 0) {
        row = (s8*)data_ov007_02221a84;
        do {
            r6 = 0;
            if (M2C_FIELD(r0, u16 *, 0x5144) > 0) {
                do {
                    if (row[r6] == 0 && arg1 == M2C_FIELD((r0 + ((r6 + M2C_FIELD((r0 + r7 * 2), u16 *, 0x3758)) * 2)), u16 *, 0xA10)) {
                        s32 cnt = func_ov007_02214ff8(r6, r7, arg0);
                        if (func_ov007_02215128(cnt, arg0) != 1) {
                            row[r6] = 1;
                        } else {
                            func_ov007_02215254(r6, r7, arg0);
                            row[r6] = 2;
                        }
                    }
                    r6 += 1;
                    r0 = *gCurrentMap;
                } while (r6 < M2C_FIELD(r0, u16 *, 0x5144));
            }
            r7 += 1;
            row += 0x1E;
        } while (r7 < M2C_FIELD(r0, u16 *, 0x5146));
    }
    if (Map_MarkUnitsMoved() == 0) {
        return;
    }
    sp0 += 1;
    if (sp0 > 0x64) {
        return;
    }
    goto loop_outer;
}

void func_ov007_02216a74(void) {
s32 func_ov007_02214e24(void);
s32 func_ov007_02214d88(s32,s32);
s32 func_ov007_02215bc4(s32*,s32*,s32);
s32 func_ov007_02215254(s32,s32,s32);
s32 Map_MarkUnitsMoved(void);
extern void **gCurrentMap;
extern u8 data_ov007_02221a84[];
s32 x,y,i,n;
func_ov007_02214e24();
n=func_ov007_02214d88(2,8);
for(i=0;i<n;i++){
if(!func_ov007_02215bc4(&x,&y,1)) break;
func_ov007_02215254(x,y,3);
(data_ov007_02221a84 + y*30)[x]=2;
if(x-1>=0){func_ov007_02215254(x-1,y,3);(data_ov007_02221a84 + y*30)[x-1]=2;}
if(y-1>=0){func_ov007_02215254(x,y-1,3);(data_ov007_02221a84 + y*30)[x-30]=2;}
if(x+1<M2C_FIELD(*gCurrentMap,u16*,0x5144)){func_ov007_02215254(x+1,y,3);(data_ov007_02221a84 + y*30)[x+1]=2;}
if(y+1<M2C_FIELD(*gCurrentMap,u16*,0x5146)){func_ov007_02215254(x,y+1,3);(data_ov007_02221a84 + y*30)[x+30]=2;}
}
Map_MarkUnitsMoved();func_ov007_02216118(3,1);
}

void func_ov007_02216bf4(void) {
    s32 func_ov007_02214e24(void);
    s32 func_ov007_02214d88(s32, s32);
    s32 func_ov007_02215bc4(s32 *, s32 *, s32);
    s32 func_ov007_02215254(s32, s32, s32);
    s32 Map_MarkUnitsMoved(void);
    void func_ov007_02216118(s32, s32);
    extern u8 data_ov007_02221a84[];

    s32 sp4;
    s32 sp0;
    s32 r10;
    s32 r9 = 0;
    s32 r6 = 2;
    s32 r11 = 1;
    s32 r4 = 0x1E;
    u8 *r5 = data_ov007_02221a84;

    func_ov007_02214e24();
    r10 = func_ov007_02214d88(8, 0xC);
    if (r10 <= 0) {
        goto end;
    }
    do {
        if (func_ov007_02215bc4(&sp4, &sp0, r11) == 0) {
            return;
        }
        func_ov007_02215254(sp4, sp0, 0x20);
        *(r5 + sp0 * r4 + sp4) = r6;
        r9++;
    } while (r9 < r10);
end:
    Map_MarkUnitsMoved();
    func_ov007_02216118(0x20, 1);
}

