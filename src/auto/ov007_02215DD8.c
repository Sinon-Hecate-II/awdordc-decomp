/* 8 functions from 0x02215DD8 to 0x02216C94 (ov007), found by ds-decomp. */
#include "common.h"

s32 func_ov007_02215dd8(s32 *x,s32 *y,s32 value){
s32 RandomIntRange(s32,s32);s32 func_ov007_022156a4(s32,s32);extern void **gCurrentMap;
s32 n=0; s32 a=0,b=0;
do{
if(++n>100)return 0;
*x=RandomIntRange(a,M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1);
*y=RandomIntRange(b,M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1);
}while(value!=M2C_FIELD((*gCurrentMap+((*x+M2C_FIELD((*gCurrentMap+(*y*2)),u16 *,0x3758))*2)),u16 *,0xA10) || !func_ov007_022156a4(*x,*y));
return 1;
}

s32 func_ov007_02215e94(s32 *x, s32 *y, s32 value, void *arg3, s32 radius) {
    s32 RandomIntRange(s32, s32);
    s32 ManhattanDistance(s16, s16, s16, s16);
    extern void **gCurrentMap;
    s32 n = 0;
    s32 a = 0, b = 0;
    do {
        if (++n > 100) return 0;
        *x = RandomIntRange(a, M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1);
        *y = RandomIntRange(b, M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1);
    } while (value != M2C_FIELD((*gCurrentMap + ((*x + M2C_FIELD((*gCurrentMap + (*y * 2)), u16 *, 0x3758)) * 2)), u16 *, 0xA10)
            || ManhattanDistance(M2C_FIELD(arg3, s16 *, 0), M2C_FIELD(arg3, s16 *, 2), (s16)*x, (s16)*y) > radius);
    return 1;
}

s32 func_ov007_02215f6c(s32 *arg0, s32 *arg1, s32 arg2, s16 *arg3, s16 *arg4, s32 arg5) {
    s32 RandomIntRange(s32, s32);
    s32 ManhattanDistance(s16, s16, s16, s16);
    extern void **gCurrentMap;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r1_2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r5_3;
    s32 temp_r6;
    s32 var_r1;
    s32 var_r4;
    void *temp_r1;

    sp0 = arg2;
    var_r4 = 0;
loop_1:
    var_r4 += 1;
    if (var_r4 > 0x64) {
        return 0;
    }
    *arg0 = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1);
    temp_r0 = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1);
    *arg1 = temp_r0;
    temp_r1 = *gCurrentMap;
    temp_r6 = *arg0;
    if (sp0 == M2C_FIELD((temp_r1 + ((temp_r6 + M2C_FIELD((temp_r1 + (temp_r0 * 2)), u16 *, 0x3758)) * 2)), u16 *, 0xA10)) {
        temp_r5 = ManhattanDistance(M2C_FIELD(arg3, s16 *, 0), M2C_FIELD(arg3, s16 *, 2), (s16) temp_r6, (s16) temp_r0);
        temp_r1_2 = *arg0;
        temp_r0_2 = *arg1;
        if ((s32) (temp_r5 - ManhattanDistance(M2C_FIELD(arg4, s16 *, 0), M2C_FIELD(arg4, s16 *, 2), (s16) temp_r6, (s16) temp_r0)) < 0) {
            temp_r5_2 = ManhattanDistance(M2C_FIELD(arg3, s16 *, 0), M2C_FIELD(arg3, s16 *, 2), (s16) temp_r1_2, (s16) temp_r0_2);
            var_r1 = 0 - (temp_r5_2 - ManhattanDistance(M2C_FIELD(arg4, s16 *, 0), M2C_FIELD(arg4, s16 *, 2), (s16) *arg0, (s16) *arg1));
        } else {
            temp_r5_3 = ManhattanDistance(M2C_FIELD(arg3, s16 *, 0), M2C_FIELD(arg3, s16 *, 2), (s16) temp_r1_2, (s16) temp_r0_2);
            var_r1 = temp_r5_3 - ManhattanDistance(M2C_FIELD(arg4, s16 *, 0), M2C_FIELD(arg4, s16 *, 2), (s16) *arg0, (s16) *arg1);
        }
        if (var_r1 <= arg5) {
            return 1;
        }
        goto loop_1;
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

s32 func_ov007_02216234() {
    return 0;
}

void func_ov007_022167b8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    return;
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
s32 func_ov007_02214e24(void);s32 func_ov007_02214d88(s32,s32);s32 func_ov007_02215bc4(s32 *,s32 *,s32);s32 func_ov007_02215254(s32,s32,s32);s32 Map_MarkUnitsMoved(void);void func_ov007_02216118(s32,s32);
extern u8 data_ov007_02221a84[];
s32 x,y,i,n;
func_ov007_02214e24();n=func_ov007_02214d88(8,12);
i=0;
if(n>0){do{
if(!func_ov007_02215bc4(&x,&y,1))break;
func_ov007_02215254(x,y,32);
*(data_ov007_02221a84+y*30+x)=2;
i++;
}while(i<n);}
Map_MarkUnitsMoved();func_ov007_02216118(32,1);
}

