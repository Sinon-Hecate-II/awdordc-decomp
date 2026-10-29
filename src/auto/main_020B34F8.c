/* 12 functions from 0x020B34F8 to 0x020B4264 (main), found by ds-decomp. */
#include "common.h"

u8 func_020b34f8(void *arg0) {
s32 func_0207c8ec();
M2C_UNK func_0208fe30(s32);
s32 active,i,factor,delta; s16 old,n; u8 step,result; s32 limit;
if(M2C_FIELD(arg0,s16 *,18)!=0)active=1;else active=0;
if(active&255)return 0;
step=M2C_FIELD(arg0,u8 *,5);
limit=M2C_FIELD(arg0,u8 *,4);
n=func_0207c8ec(M2C_FIELD(arg0,s16 *,10)+step-1,step);
n=limit>=n?n:limit;
old=M2C_FIELD(arg0,s16 *,12);
for(i=0;i<n;i++){
if(M2C_FIELD(arg0,s16 *,12)!=0)M2C_FIELD(arg0,s16 *,12)-=1;
if(M2C_FIELD(arg0,s16 *,8)-step>=0)M2C_FIELD(arg0,s16 *,8)-=step;
}
if(old!=M2C_FIELD(arg0,s16 *,12))func_0208fe30(0x10019);
delta=M2C_FIELD(arg0,s16 *,12);factor=M2C_FIELD(arg0,u8 *,7);delta-=old;
M2C_FIELD(arg0,s16 *,18)=delta*factor;
if(M2C_FIELD(arg0,s16 *,18)!=0)result=1;else result=0;
return result;
}

M2C_UNK func_020b35d4(M2C_UNK arg0) {
    return 0;
}

M2C_UNK func_020b38d0(M2C_UNK arg0) {
    M2C_UNK func_020b3038(M2C_UNK);
    M2C_UNK func_0208fe30(M2C_UNK);
    u8 var_r2;
    u8 var_r0;
    s8 var_r1;
    s16 var_r4;
    s16 var_r5;
    s16 prod;
    s16 newval;

    if (M2C_FIELD(arg0, s16 *, 0x12) != 0)
        return 1;
    var_r2 = M2C_FIELD(arg0, u8 *, 0x5);
    var_r0 = M2C_FIELD(arg0, u8 *, 0x4);
    var_r1 = M2C_FIELD(arg0, s8 *, 0x24);
    var_r4 = M2C_FIELD(arg0, s16 *, 0xc);
    prod = (s16)(var_r0 * var_r2);
    var_r5 = M2C_FIELD(arg0, s16 *, 0x8);
    if (var_r1 < 0)
        return prod;
    if (prod <= var_r1)
        return prod;
    newval = (s16)(var_r2 * var_r4 + var_r1);
    if (newval == var_r5)
        return newval;
    func_020b3038(arg0);
    if (var_r4 == M2C_FIELD(arg0, s16 *, 0xc) && var_r5 == M2C_FIELD(arg0, s16 *, 0x8))
        return M2C_FIELD(arg0, s16 *, 0x8);
    return func_0208fe30(0x10019);
}

/* Returns whether tile column x is currently visible in the camera viewport. */
u8 func_020b3960(void *camera, int x) {
int func_0207c8ec(int,int);
u8 visibleTiles, tileSize; s16 total, scroll, tile; int tileCount;
visibleTiles=M2C_FIELD(camera,u8*,4); tileSize=M2C_FIELD(camera,u8*,5); total=M2C_FIELD(camera,s16*,10);
tileCount=(s16)func_0207c8ec(total+tileSize-1,tileSize);
if(x<0 || total<=x)return 0;
scroll=M2C_FIELD(camera,s16*,12);
tile=func_0207c8ec(x,tileSize);
if(tileCount>visibleTiles)tileCount=visibleTiles;
total=tileCount;
if(M2C_FIELD(camera,s16*,18)>0) {scroll-= (s16)func_0207c8ec(M2C_FIELD(camera,s16*,18)+(M2C_FIELD(camera,u8*,7)-1),M2C_FIELD(camera,u8*,7)); total++;}
else if(M2C_FIELD(camera,s16*,18)<0) {scroll-=(s16)func_0207c8ec(M2C_FIELD(camera,s16*,18),M2C_FIELD(camera,u8*,7)); total++;}
return scroll<=tile && tile<scroll+total;
}

void func_020b3a58(M2C_UNK arg0) {
    M2C_UNK func_02088044(M2C_UNK);
    M2C_UNK func_020b316c();
    M2C_UNK func_020b35d4(M2C_UNK);
    M2C_UNK func_020b38d0(M2C_UNK);
    func_020b316c();
    func_02088044(arg0 + 0x18);
    func_020b35d4(arg0);
    func_020b38d0(arg0);
}

void func_020b3a80(void *arg0) {
s32 func_0207c8ec();
s32 func_0207c928(s16,u8);
s16 a,b; s16 x,y,c,old; s16 delta; s32 d,e;
a=M2C_FIELD(arg0,u8 *,6); b=M2C_FIELD(arg0,u8 *,7);
x=func_0207c928(M2C_FIELD(arg0,s16 *,8),M2C_FIELD(arg0,u8 *,5));
c=M2C_FIELD(arg0,s16 *,12);
delta=func_0207c8ec(M2C_FIELD(arg0,s16 *,8),M2C_FIELD(arg0,u8 *,5))-c;
x=(s16)(M2C_FIELD(arg0,s16 *,20)+x*a);
y=(s16)(M2C_FIELD(arg0,s16 *,22)+delta*b);
old=M2C_FIELD(arg0,s16 *,14);
if ((old==-32768 && M2C_FIELD(arg0,s16 *,16)==-32768) || (((d=old-x)<0?-d:d)<=1 && ((e=M2C_FIELD(arg0,s16 *,16)-y)<0?-e:e)<=1)) {
M2C_FIELD(arg0,s16 *,14)=x; M2C_FIELD(arg0,s16 *,16)=y;
} else {
M2C_FIELD(arg0,s16 *,14)=(x+old+1)>>1;
M2C_FIELD(arg0,s16 *,16)=(y+M2C_FIELD(arg0,s16 *,16)+1)>>1;
}
}

void *func_020b3b4c(void *arg0) {
    M2C_UNK func_02082040(void *);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x2C));
    func_02082040(arg0);
    return arg0;
}

void *func_020b3b6c(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x2C));
    return arg0;
}

void func_020b3b84(void) {
    M2C_UNK func_02086810(u16, M2C_UNK);
    u16 func_020a8aac(u16, s32);
    M2C_UNK func_020bef44();
    s32 func_020befd8();
    s32 func_020bf084(s32);
    M2C_UNK func_020bf0dc(M2C_UNK, s32);
    M2C_UNK func_020bf798();
    s32 func_020cd6d4();
    M2C_UNK func_020e4870();
    extern void **gCurrentMap;
    s32 temp_r0;
    s32 var_r6;
    u16 temp_r0_2;

    temp_r0 = func_020befd8();
    if (temp_r0 != 0) {
        func_020bef44();
        if (func_020bf084(temp_r0) == 0) {
            func_020bf0dc(0, temp_r0);
            func_020e4870();
        }
    }
    if (func_020cd6d4() != 0) {
        var_r6 = 0;
        do {
            temp_r0_2 = func_020a8aac(M2C_FIELD(*gCurrentMap, u16 *, 0x5142), var_r6);
            if (temp_r0_2 != 0) {
                func_02086810(temp_r0_2, 1);
            }
            var_r6 += 1;
        } while (var_r6 < 4);
        func_02086810(M2C_FIELD(*gCurrentMap, u16 *, 0x5142), 1);
    }
    func_020bf798();
}

void func_020b3c2c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021286ac;
    func_01ffa42c(&data_021286ac, arg0);
}

void func_020b3c44(void) {

}

void func_020b3c48(s32 arg0) { (void)arg0; }

