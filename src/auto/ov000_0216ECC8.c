/* 12 functions from 0x0216ECC8 to 0x0216FC60 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
typedef struct {u16 hp:7;u16 ammo:4;u16 flags:5;} DisplayHealth;
typedef struct {u8 fuel:7;u8 flag:1;} DisplayFuel;
extern void **gCurrentMap;
extern void *gCur3DSpriteEngine,*data_027e00c8;
extern s32 data_ov000_021df5e4;
extern u32 data_ov000_021b5bfc[];
extern u8 data_ov000_021b5c0a[],data_ov000_021b5c05[],data_ov000_021b5c0b[];
int func_020a8b9c(void);int func_020a8b90(void);int func_020a8bb4(void);int func_020a8ba8(void);int func_020a8b78(void);int func_020a8b84(void);
void func_0209c048(s16,s16,void *,int,int,int);
void func_0209c024(s16,s16,void *,int,int,int);
void func_0207a61c(void *,u16,u16,int,u16,u8,u8);
void func_0209b2dc(s16,s16,int,u32,int,int,u16);
int func_0207c8ec(int,int);int func_02086680(u32);int func_0209c268(int);
void func_0209bfdc(s16,s16,void *,u32,int,int);

/* Switch gCur3DSpriteEngine to data_027e00c8 and rebuild its display lists; bit 0 of mode selects one of two layouts. */
void func_ov000_0216ecc8(s32 mode,s32 reverse){
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern s8 data_ov000_021aab79[];
extern M2C_UNK data_ov000_021df5e4;
extern u32 data_ov000_021b5bfc[];
void *func_020e34bc(s32);void func_020e35cc(void *);
void func_02008048(void *,void *,s32);s32 func_0207c8ec(s32,s32);
s32 n=0,i,j,k,l,out,t,v,h,idx,z;
u8 *tmp=func_020e34bc(64),*p,*q,*map,*attr;
s8 *order=data_ov000_021aab79;
for(t=1;t<27;t++,order++){
for(i=data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51;i++){
map=*gCurrentMap;p=map+0x59a4+i*14;
v=(u32)(p[0]<<26)>>26;
if(v && v==*order)((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[n++]=i-M2C_FIELD(map,u16 *,0x52a8);
}}
((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[n]=0;
out=0;
switch(mode){
case 0:func_02008048(M2C_FIELD(&data_ov000_021df5e4,u8 **,4),tmp,64);break;
case 1:
for(h=10;h>0;h--)for(i=0;i<n;i++){
map=*gCurrentMap;idx=((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[i]+M2C_FIELD(map,u16 *,0x52a8);
v=(u32)(M2C_FIELD(map+idx*14,u16 *,0x59aa)<<25)>>25;
if(v==0)v=0;else v=func_0207c8ec(v-1,10)+1;
if(h==v)tmp[out++]=((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[i];
}break;
case 2:
for(h=99;h>=0;h--)for(i=0;i<n;i++){
map=*gCurrentMap;z=((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[i];idx=M2C_FIELD(map,u16 *,0x52a8)+z;
if(h==((u32)(map[0x59ae + idx*14]<<25)>>25))tmp[out++]=z;
}break;
case 3:
for(h=10;h>=-1;h--)for(i=0;i<n;i++){
map=*gCurrentMap;z=((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[i];idx=M2C_FIELD(map,u16 *,0x52a8)+z;p=map+0x59a4+idx*14;
attr=(u8 *)data_ov000_021b5bfc+((u32)(p[0]<<26)>>26)*112;
if(attr[9])v=(u32)(M2C_FIELD(p,u16 *,6)<<21)>>28;
else {v=-1;if(attr[15])v=10;}
if(v==h)tmp[out++]=z;
}break;
}
if(reverse){
for(i=0;i<n;i++)((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[i]=tmp[n-1-i];
func_02008048(M2C_FIELD(&data_ov000_021df5e4,u8 **,4),tmp,64);
}
out=0;
for(i=0;i<n;i++){
z=tmp[i];
if(z){
map=*gCurrentMap;p=map+0x59a4+(M2C_FIELD(map,u16 *,0x52a8)+z)*14;
if(!(M2C_FIELD(p,u16 *,4)&8)){
((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[out++]=z;tmp[i]=0;
if(M2C_FIELD(p,u16 *,4)&16){
for(j=0;j<2;j++){
z=p[12+j];
if(z){
map=*gCurrentMap;idx=z-M2C_FIELD(map,u16 *,0x52a8);
for(k=0;k<n;k++){
if(idx==tmp[k]){
z=M2C_FIELD(map,u16 *,0x52a8)+idx;q=map+0x59a4+z*14;
((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[out++]=tmp[k];tmp[k]=0;
if(M2C_FIELD(q,u16 *,4)&16){
for(l=0;l<2;l++){
z=q[12+l];
if(z){
idx=z-M2C_FIELD(*gCurrentMap,u16 *,0x52a8);
for(v=0;v<n;v++){
if(idx==tmp[v]){((u8 *)M2C_FIELD(&data_ov000_021df5e4,u8 **,4))[out++]=tmp[v];tmp[v]=0;break;}
}
}
}}
break;
}
}
}
}
}
}
}
}
func_020e35cc(tmp);
}

s32 func_ov000_0216f1b4(s32 arg0) {
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 stride = 14;
    void *base;
    u8 *arr;
    u8 *fc;
    u16 a8;
    s32 a4;
    s32 T;
    s32 upper;
    s32 T2;
    s32 upper2;
    s32 idx;
    s32 j;
    s32 r0v;
    u8 *cell;
    u8 *c2;

    base = *gCurrentMap;
    arr = (u8 *)base + 0x59A4;
    a8 = *(u16 *)((u8 *)base + 0x52A8);
    fc = arr + (arg0 + a8) * stride;
    if (!(*(u16 *)(fc + 4) & 0x8)) {
        return 0;
    }

    a4 = *(u16 *)((u8 *)base + 0x52A4);
    T = data_ov000_021aeef4[a4];
    upper = T + 0x33;

    cell = arr + (T + 1) * stride;
    for (idx = T + 1; idx < upper; idx++, cell += stride) {
        if ((cell[0] & 0x3F) == 0) {
            goto outer_continue;
        }
        a8 = *(u16 *)((u8 *)base + 0x52A8);
        if (arg0 != (s32)(cell[0x0C] - a8)) {
            if (arg0 != (s32)(cell[0x0D] - a8)) {
                goto outer_continue;
            }
            if (!(*(u16 *)(cell + 4) & 0x8)) {
                return 2;
            }
            a4 = *(u16 *)((u8 *)base + 0x52A4);
            T2 = data_ov000_021aeef4[a4];
            upper2 = T2 + 0x33;
            r0v = idx - a8;
            c2 = arr + (T2 + 1) * stride;
            for (j = T2 + 1; j < upper2; j++, c2 += stride) {
                if ((c2[0] & 0x3F) == 0) {
                    continue;
                }
                if (r0v == (s32)(c2[0x0D] - a8)) {
                    return 6;
                }
                if (r0v == (s32)(c2[0x0C] - a8)) {
                    if (c2[0x0D] == 0) {
                        return 6;
                    } else {
                        return 4;
                    }
                }
            }
        } else {
            if (cell[0x0D] != 0) {
                if (!(*(u16 *)(cell + 4) & 0x8)) {
                    return 1;
                }
                a4 = *(u16 *)((u8 *)base + 0x52A4);
                T2 = data_ov000_021aeef4[a4];
                upper2 = T2 + 0x33;
                r0v = idx - a8;
                c2 = arr + (T2 + 1) * stride;
                for (j = T2 + 1; j < upper2; j++, c2 += stride) {
                    if ((c2[0] & 0x3F) == 0) {
                        continue;
                    }
                    if (r0v == (s32)(c2[0x0D] - a8)) {
                        return 5;
                    }
                    if (r0v == (s32)(c2[0x0C] - a8)) {
                        if (c2[0x0D] == 0) {
                            return 5;
                        } else {
                            return 3;
                        }
                    }
                }
            } else {
                a4 = *(u16 *)((u8 *)base + 0x52A4);
                T2 = data_ov000_021aeef4[a4];
                upper2 = T2 + 0x33;
                r0v = idx - a8;
                c2 = arr + (T2 + 1) * stride;
                for (j = T2 + 1; j < upper2; j++, c2 += stride) {
                    if ((c2[0] & 0x3F) == 0) {
                        continue;
                    }
                    if (r0v == (s32)(c2[0x0D] - a8)) {
                        return 6;
                    }
                    if (r0v == (s32)(c2[0x0C] - a8)) {
                        if (c2[0x0D] == 0) {
                            return 6;
                        } else {
                            return 4;
                        }
                    }
                }
            }
        }

outer_continue:
        a4 = *(u16 *)((u8 *)base + 0x52A4);
        T = data_ov000_021aeef4[a4];
        upper = T + 0x33;
    }

    return 0;
}

#pragma opt_strength_reduction off
void func_ov000_0216f3d0(s32 row,s32 index){
 UnkStruct_ov000_021A860C *u;
 void *saved;
 int base;
 int shift;
 u8 *m;
 int id,offset,icon,health;
 data_ov000_021df5e4=0x1c4+(row+1)*24;
 id=((u8 *)((u32 *)&data_ov000_021df5e4)[1])[index];if(id==0)return;
 saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
 m=*gCurrentMap;base=*(u16 *)(m+0x52a8);
 u=(void *)(m+0x59a4+(base+id)*14);
 if(*(u16 *)((u8 *)u+4)&8)base=256;
 else if(*(u16 *)((u8 *)u+4)&1)base=256;
 shift=0;
 switch(func_ov000_0216f1b4(id)){
 case 1:icon=func_020a8b9c();offset=1;break;
 case 2:icon=func_020a8b90();offset=1;break;
 case 3:icon=func_020a8bb4();offset=2;break;
 case 4:icon=func_020a8ba8();offset=2;break;
 case 5:icon=func_020a8b9c();offset=2;shift=1;break;
 case 6:icon=func_020a8b90();offset=2;shift=1;break;
 default:icon=0;offset=0;break;
 }
 func_0209c048(3,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),index+1,0,0);
 if(icon)func_0209c024((s16)(shift+5),(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),icon,0,0);
 func_0207a61c(M2C_FIELD(gCur3DSpriteEngine,void **,0x24),(u16)(offset+5),(u16)(row+5),u->unk0,(u16)base,u->unkC[0],(u8)((DisplayHealth *)((u8 *)u+6))->flags);
 func_0209b2dc(9,(s16)(row+5),1,*(u32 *)((u8 *)data_ov000_021b5bfc+u->unk0*112),0,0,(u16)data_ov000_021df5e4);
 health=u->unk6;if(health==0)health=0;else health=func_0207c8ec(health-1,10)+1;
 func_0209c048(18,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),health,0,0);
 func_0209c048(21,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),((DisplayFuel *)((u8 *)u+10))->fuel,0,0);
 func_0209c024(22,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0,0);
 func_0209c048(24,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),data_ov000_021b5c0a[u->unk0*112],0,0);
 if(!data_ov000_021b5c05[u->unk0*112]){
 if(data_ov000_021b5c0b[u->unk0*112])func_0209c024(27,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b84(),0,0);
 else func_0209bfdc((s16)(28-(func_0209c268(func_02086680(0xc000007f))>>4)),(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),0xc000007f,0,0);
 }else{
 func_0209c048(27,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),((DisplayHealth *)((u8 *)u+6))->ammo,0,0);
 func_0209c024(28,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0,0);
 func_0209c048(29,(s16)(row+5),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),data_ov000_021b5c05[u->unk0*112],0,0);
 }
 gCur3DSpriteEngine=saved;
}
void func_ov000_0216f8c4(s32 mode) {
    M2C_UNK func_020809c0(s32, M2C_UNK, M2C_UNK);
    void func_ov000_0216f3d0(s32, s32);
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    void *savedPtr;

    savedPtr = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_020809c0(M2C_FIELD(data_027e00c8, s32 *, 0x24) + 0x140, 0x20, 0xC);
    if (mode & 1) {
        var_r6 = 0;
        var_r5 = mode >> 1;
        var_r7 = -1;
        do {
            func_ov000_0216f3d0(var_r7, var_r5);
            var_r6 += 1;
            var_r5 += 1;
            var_r7 += 2;
        } while (var_r6 < 7);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x100, 0x20, 1);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x440, 0x20, 1);
    } else {
        var_r7_2 = 0;
        var_r6_2 = 0;
        var_r5_2 = mode >> 1;
        do {
            func_ov000_0216f3d0(var_r6_2, var_r5_2);
            var_r7_2 += 1;
            var_r5_2 += 1;
            var_r6_2 += 2;
        } while (var_r7_2 < 6);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = savedPtr;
}

void func_ov000_0216f9b4(void *p){
extern void *gCur3DSpriteEngine;extern void *data_027e00c8;
extern M2C_UNK data_ov000_021b8ac0,data_ov000_021b8ad0,data_ov000_021b8ae0,data_ov000_021b8af4,data_ov000_021b8b04,data_ov000_021b8b18;
s32 func_020e3218(void *);void func_02081590(s32,s32);void func_02080944(s32,s32,s32,s32);
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
func_0200bc5c(&data_ov000_021b8ac0);
func_020e3218(&data_ov000_021b8ad0);func_020814e4();
switch(M2C_FIELD(p,s16 *,0x34)){
case 0:func_02081590(func_020e3218(&data_ov000_021b8ae0),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));break;
case 1:func_02081590(func_020e3218(&data_ov000_021b8af4),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));break;
case 2:func_02081590(func_020e3218(&data_ov000_021b8b04),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));break;
case 3:func_02081590(func_020e3218(&data_ov000_021b8b18),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));break;
}
func_02081528();func_02080944(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28),32,24,6);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
gCur3DSpriteEngine=saved;
}

s32 func_ov000_0216facc(void *arg0) {
    s16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x3A);
    if (temp_r1 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s16 *, 0x3A) = (s16) (temp_r1 - 1);
    func_0208fe30(0x10019);
    return 1;
}

s16 func_ov000_0216fafc(void *a) {
s16 old=M2C_FIELD(a,s16 *,0x3a);
M2C_FIELD(a,s16 *,0x3a)=old-6;
if(M2C_FIELD(a,s16 *,0x3a)<0) M2C_FIELD(a,s16 *,0x3a)=0;
return M2C_FIELD(a,s16 *,0x3a)-old;
}

s32 func_ov000_0216fb2c(void *arg0) {
s16 n=M2C_FIELD(arg0,s16 *,0x3a);
s32 next=n+6;
if(next>=M2C_FIELD(arg0,s16 *,0x3c))return 0;
M2C_FIELD(arg0,s16 *,0x3a)++;
func_0208fe30(0x10019);
return 1;
}

s16 func_ov000_0216fb64(void *a) {
s16 old=M2C_FIELD(a,s16 *,0x3a);
s32 max;
M2C_FIELD(a,s16 *,0x3a)=old+6;
max=M2C_FIELD(a,s16 *,0x3c)-6;
if(M2C_FIELD(a,s16 *,0x3a)>max) M2C_FIELD(a,s16 *,0x3a)=max;
return M2C_FIELD(a,s16 *,0x3a)-old;
}

void func_ov000_0216fb98(void *arg0) {
    M2C_UNK func_0207b764(u8, u8);
    extern void **gCurrentMap;
    s16 temp_ip;
    s32 temp_r1;
    void *temp_r3;

    temp_ip = M2C_FIELD(arg0, s16 *, 0x40);
    if (temp_ip == 0) {
        return;
    }
    temp_r3 = *gCurrentMap;
    temp_r1 = ((M2C_FIELD(temp_r3, u16 *, 0x52A8) + temp_ip) * 0xE) + (s32) (temp_r3 + 0x59A4);
    func_0207b764(M2C_FIELD(temp_r1, u8 *, 1), M2C_FIELD(temp_r1, u8 *, 2));
}

void func_ov000_0216fbe4(u8 *a) {
extern M2C_UNK data_ov000_021df5e4;
s32 p=func_ov000_021700fc();
M2C_FIELD(p,s16 *,0x40)=M2C_FIELD(&data_ov000_021df5e4,u8 **,4)[M2C_FIELD(p,s16 *,0x3a)+*a];
func_0208fe30(0x10016);
func_01ffa6fc(p);
func_020b21a0();
func_020b2268();
}

void func_ov000_0216fc34(void) {
    M2C_UNK func_01ffa6fc(s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b21a0();
    M2C_UNK func_020b2268();
    s32 func_ov000_021700fc();
    s32 temp_r4;

    temp_r4 = func_ov000_021700fc();
    func_0208fe30(0x10018);
    func_01ffa6fc(temp_r4);
    func_020b21a0();
    func_020b2268();
}
