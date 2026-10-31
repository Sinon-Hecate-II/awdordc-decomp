/* 14 functions from 0x022221B8 to 0x02223114 (ov010), found by ds-decomp. */
#include "common.h"

typedef struct UnkOv010Header { s16 unk0; u8 unk2; u8 unk3; } UnkOv010Header;

void func_ov010_022221b8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    extern M2C_UNK data_ov010_0222bd5c;
    extern M2C_UNK data_ov010_0222bd78;
    u32 sp0;
    s16 temp_r10;
    s16 temp_r10_2;
    s16 temp_r10_3;
    s16 temp_r2_2;
    s16 temp_r6;
    s16 var_r2_2;
    s16 var_r2_3;
    s16 var_r2_4;
    s16 var_r8;
    s32 var_r7;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r8_5;
    s32 var_r8_6;
    s32 var_r8_7;
    s32 var_r8_8;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_4;
    s8 *var_r0;
    u32 temp_lr;
    u32 temp_r2;
    u32 var_r11;
    u8 temp_r7;
    u8 var_r2;
    u8 var_r7_2;
    u8 var_r7_3;
    u8 var_r7_4;
    void *var_r1;

    var_r0 = (s8 *)arg0;
    var_r1 = (void *)arg1;
    temp_r2 = (u32)arg2 >> 2;
    var_r11 = 0;
    sp0 = temp_r2;
    if (temp_r2 == 0) {
        return;
    }
    temp_lr = -0x8000U >> 0x11;
    do {
        temp_r7 = M2C_FIELD(arg3, u8 *, 2);
        temp_r6 = M2C_FIELD(arg3, s16 *, 0);
        var_r8 = *(&data_ov010_0222bd78 + (temp_r7 * 2));
        var_r9 = M2C_FIELD(var_r1, s16 *, 0) - temp_r6;
        if (var_r9 < 0) {
            var_r2 = 2;
            var_r9 = 0 - var_r9;
        } else {
            var_r2 = 0;
        }
        if (var_r9 >= (s32) var_r8) {
            var_r2 |= 1;
        }
        if (!(var_r2 & 1)) {
            var_r8 = 0;
        }
        if (var_r2 & 2) {
            var_r8 = 0 - var_r8;
        }
        var_r8_2 = temp_r6 + var_r8;
        if (var_r8_2 < -0x8000) {
            var_r8_2 = -0x8000;
        }
        if (var_r8_2 > (s32) (-0x8000U >> 0x11)) {
            var_r8_2 = (s32) temp_lr;
        }
        var_r7 = temp_r7 + *(&data_ov010_0222bd5c + var_r2);
        if (var_r7 < 0) {
            var_r7 = 0;
        } else if (var_r7 > 0x58) {
            var_r7 = 0x58;
        }
        M2C_FIELD(arg3, s16 *, 0) = (s16) var_r8_2;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r7;
        temp_r10 = M2C_FIELD(arg3, s16 *, 0);
        var_r8_3 = M2C_FIELD(var_r1, s16 *, 2) - temp_r10;
        var_r2_2 = *(&data_ov010_0222bd78 + ((u8) var_r7 * 2));
        if (var_r8_3 < 0) {
            var_r7_2 = 2;
            var_r8_3 = 0 - var_r8_3;
        } else {
            var_r7_2 = 0;
        }
        if (var_r8_3 >= (s32) var_r2_2) {
            var_r7_2 |= 1;
        }
        if (!(var_r7_2 & 1)) {
            var_r2_2 = 0;
        }
        if (var_r7_2 & 2) {
            var_r2_2 = 0 - var_r2_2;
        }
        var_r8_4 = temp_r10 + var_r2_2;
        if (var_r8_4 < -0x8000) {
            var_r8_4 = -0x8000;
        }
        if (var_r8_4 > (s32) (-0x8000U >> 0x11)) {
            var_r8_4 = (s32) temp_lr;
        }
        var_r9_2 = (u8) var_r7 + *(&data_ov010_0222bd5c + var_r7_2);
        if (var_r9_2 < 0) {
            var_r9_2 = 0;
        } else if (var_r9_2 > 0x58) {
            var_r9_2 = 0x58;
        }
        M2C_FIELD(arg3, s16 *, 0) = (s16) var_r8_4;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r9_2;
        temp_r10_2 = M2C_FIELD(arg3, s16 *, 0);
        var_r8_5 = M2C_FIELD(var_r1, s16 *, 4) - temp_r10_2;
        var_r2_3 = *(&data_ov010_0222bd78 + ((u8) var_r9_2 * 2));
        if (var_r8_5 < 0) {
            var_r7_3 = 2;
            var_r8_5 = 0 - var_r8_5;
        } else {
            var_r7_3 = 0;
        }
        if (var_r8_5 >= (s32) var_r2_3) {
            var_r7_3 |= 1;
        }
        if (!(var_r7_3 & 1)) {
            var_r2_3 = 0;
        }
        if (var_r7_3 & 2) {
            var_r2_3 = 0 - var_r2_3;
        }
        var_r8_6 = temp_r10_2 + var_r2_3;
        if (var_r8_6 < -0x8000) {
            var_r8_6 = -0x8000;
        }
        if (var_r8_6 > (s32) (-0x8000U >> 0x11)) {
            var_r8_6 = (s32) temp_lr;
        }
        var_r9_3 = (u8) var_r9_2 + *(&data_ov010_0222bd5c + var_r7_3);
        if (var_r9_3 < 0) {
            var_r9_3 = 0;
        } else if (var_r9_3 > 0x58) {
            var_r9_3 = 0x58;
        }
        M2C_FIELD(arg3, s16 *, 0) = (s16) var_r8_6;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r9_3;
        temp_r2_2 = M2C_FIELD(var_r1, s16 *, 6);
        temp_r10_3 = M2C_FIELD(arg3, s16 *, 0);
        var_r1 += 8;
        var_r8_7 = temp_r2_2 - temp_r10_3;
        var_r2_4 = *(&data_ov010_0222bd78 + ((u8) var_r9_3 * 2));
        if (var_r8_7 < 0) {
            var_r7_4 = 2;
            var_r8_7 = 0 - var_r8_7;
        } else {
            var_r7_4 = 0;
        }
        if (var_r8_7 >= (s32) var_r2_4) {
            var_r7_4 |= 1;
        }
        if (!(var_r7_4 & 1)) {
            var_r2_4 = 0;
        }
        if (var_r7_4 & 2) {
            var_r2_4 = 0 - var_r2_4;
        }
        var_r8_8 = temp_r10_3 + var_r2_4;
        if (var_r8_8 < -0x8000) {
            var_r8_8 = -0x8000;
        }
        if (var_r8_8 > (s32) (-0x8000U >> 0x11)) {
            var_r8_8 = (s32) temp_lr;
        }
        var_r9_4 = (u8) var_r9_3 + *(&data_ov010_0222bd5c + var_r7_4);
        if (var_r9_4 < 0) {
            var_r9_4 = 0;
        } else if (var_r9_4 > 0x58) {
            var_r9_4 = 0x58;
        }
        M2C_FIELD(arg3, s16 *, 0) = (s16) var_r8_8;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r9_4;
        *var_r0 = (u8) ((u8) (var_r2 | (var_r7_2 * 4)) | (var_r7_3 * 0x10)) | (var_r7_4 << 6);
        var_r0 += 1;
        var_r11 += 1;
    } while (var_r11 < sp0);
}

void func_ov010_022223e8(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
void func_ov010_02221fa0(void *,s32,s32,UnkOv010Header *);
void func_ov010_02221600(void *,s32,s32,UnkOv010Header *);
void func_ov010_02221320(void *,s32,s32,UnkOv010Header *);
UnkOv010Header header;
header.unk0=M2C_FIELD(arg0,s16 *,0);
header.unk2=M2C_FIELD(arg0,u8 *,2);
switch(arg3) {
case 2: func_ov010_02221fa0((u8 *)arg0+4,arg1,arg2-4,&header); return;
case 3: func_ov010_02221600((u8 *)arg0+4,arg1,arg2-4,&header); return;
case 4: func_ov010_02221320((u8 *)arg0+4,arg1,arg2-4,&header); return;
}
}

void func_ov010_02222454(void *arg0,s32 arg1,s32 arg2,void *arg3,s32 arg4) {
void func_ov010_022221b8(void *,s32,s32,void *);
void func_ov010_02221a94(void *,s32,s32,void *);
void func_ov010_02221474(void *,s32,s32,void *);
M2C_FIELD(arg0,s16 *,0)=M2C_FIELD(arg3,s16 *,0);
M2C_FIELD(arg0,u8 *,2)=M2C_FIELD(arg3,u8 *,2);
M2C_FIELD(arg0,u8 *,3)=0;
switch(arg4) {
case 2: func_ov010_022221b8((u8 *)arg0+4,arg1,arg2,arg3); return;
case 3: func_ov010_02221a94((u8 *)arg0+4,arg1,arg2,arg3); return;
case 4: func_ov010_02221474((u8 *)arg0+4,arg1,arg2,arg3); return;
}
}

#pragma opt_strength_reduction off
s32 func_ov010_022224b4(void){
s32 func_020070a4(void); void func_ov010_02225174(void);void func_ov010_02223654(u32);void func_ov010_0222393c(void *,u32,s32);void func_ov010_022232e0(void);void func_ov010_02225288(void);
extern M2C_UNK data_ov010_0222c960,data_ov010_0222c000,data_ov010_0222edc0;extern u8 data_ov010_0222be2c[];extern void *data_ov010_0222c98c[];extern u8 data_ov010_0222c998[];
s32 i; s32 saved; s32 n; u8 y,x;
saved=func_020070a4();
M2C_FIELD(&data_ov010_0222c960,u16 *,0)=saved; data_ov010_0222c000=1;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x20)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,4)=0;
if(M2C_FIELD(&data_ov010_0222edc0,s32 *,16)==1)M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c)=0;
else M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c)=4;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x24)=0x440;
{ n=M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c);
x=M2C_FIELD(data_ov010_0222be2c+n*2,u8 *,1);y=data_ov010_0222be2c[n*2];
M2C_FIELD(&data_ov010_0222c960,s32 *,12)=x+y*68+12;
}
M2C_FIELD(&data_ov010_0222c960,s32 *,3840)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3844)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3852)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3848)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3856)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3860)=0;
func_ov010_02225174();
i=0;goto test;loop:{data_ov010_0222c98c[i]=0;func_ov010_02223654(i);func_ov010_0222393c(data_ov010_0222c998+i*0x94,i,-1);i++;}test:if((u32)i<3)goto loop;
func_ov010_022232e0();func_ov010_02225288();return 1;
}
#pragma opt_strength_reduction reset
void func_ov010_022225b0(s32 arg0) {
    extern M2C_UNK data_ov010_0222c960;
    M2C_FIELD(&data_ov010_0222c960, void **, 0x20) = NULL;
}

#pragma opt_common_subs off
s32 func_ov010_022225c4(void *p){
void func_ov010_0222393c(void*,u32,s32);
void func_ov010_02223654(u32);
void func_ov010_02224f28(void);
s32 func_020070a4(void);
extern s32 data_ov010_0222c960;
extern void *data_ov010_0222c98c[];
extern u8 data_ov010_0222c998[];
s32 i;
if(!p)return 0;
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x20)==3)return 0;
if(M2C_FIELD(p,s32*,12)!=2&&M2C_FIELD(p,s32*,12)!=3)return 0;
i=0;goto test1;
loop1:if(data_ov010_0222c98c[i]==p)return 1;i++;
test1:if((u32)i<3)goto loop1;
i=0;goto test2;
loop2:if(!data_ov010_0222c98c[i]){data_ov010_0222c98c[i]=p;goto found;}i++;
test2:if((u32)i<3)goto loop2;
found:
M2C_FIELD(&data_ov010_0222c960,s32*,0x20)++;
M2C_FIELD(&data_ov010_0222c960,u32*,4)|=M2C_FIELD(p,u32*,8);
func_ov010_0222393c(data_ov010_0222c998+i*0x94,i,M2C_FIELD(p,u8*,5));
func_ov010_02223654(i);
if(M2C_FIELD(p,s32*,12)!=2)return 1;
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x20)==1){
func_ov010_02224f28();
M2C_FIELD(&data_ov010_0222c960,u16*,0)=func_020070a4();
M2C_FIELD(&data_ov010_0222c960,u16*,0x10)=0;
M2C_FIELD(&data_ov010_0222c960,u8*,0x12)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0x14)=1;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf00)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf04)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf0c)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf08)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf10)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf14)=0;
}
return 1;
}
void func_ov010_022226fc(void *arg0) {
extern void *data_ov010_0222c98c[]; extern u8 data_ov010_0222c998[]; extern M2C_UNK data_ov010_0222c960;
void func_ov010_022239c8(void *); void func_ov010_0222369c(u32); void func_ov010_02223314(u32); void func_ov010_02224f28(void);
u32 i;
for(i=0;i<3;i++) {
if(data_ov010_0222c98c[i]==arg0) {
{s32 count=M2C_FIELD(&data_ov010_0222c960,s32 *,0x20); data_ov010_0222c98c[i]=0; M2C_FIELD(&data_ov010_0222c960,s32 *,0x20)=count-1;}
func_ov010_022239c8(data_ov010_0222c998+i*0x94);
func_ov010_0222369c(i);
func_ov010_02223314(i);
{void *state=&data_ov010_0222c960; u32 mask=M2C_FIELD(arg0,u32 *,8); M2C_FIELD(state,u32 *,4)=M2C_FIELD(state,u32 *,4)&~mask;}
break;
}
}
if(M2C_FIELD(&data_ov010_0222c960,s32 *,0x20)==0) {
M2C_FIELD(&data_ov010_0222c960,s32 *,0x14)=1;
func_ov010_02224f28();
M2C_FIELD(&data_ov010_0222c960,s32 *,4)=0;
}
}

#pragma push
#pragma opt_common_subs off
s32 func_ov010_022227b0(void *src,s32 len){
extern M2C_UNK data_ov010_0222c960; extern void *data_ov010_0222c98c[];extern u8 data_ov010_0222cfa0[];
void func_02007ef4(void *,void *,s32);s64 func_02007004(void);s32 func_02072088(s64,s32,s32);
s32 found=0; s32 off;u8 *p;u16 n;s32 mode;u32 magic;
if(len!=M2C_FIELD(&data_ov010_0222c960,s32 *,0x24))return found;
if(!M2C_FIELD(&data_ov010_0222c960,s32 *,0x20))return found;
{s32 i=0;goto test;loop:{if(data_ov010_0222c98c[i] && M2C_FIELD(data_ov010_0222c98c[i],s32 *,12)==2){found=0+1;goto done;}i++;}test:if((u32)i<3)goto loop;done:;}
if(!found)return 0;
if(M2C_FIELD(&data_ov010_0222c960,u32 *,0xf04)&1){off=0;magic=0x5f564354;}else{off=0x460;magic=0x5f564354;}
p=data_ov010_0222cfa0+off;
mode=M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c);
M2C_FIELD(p,u32 *,0)=magic;
if(mode>=2)func_02007ef4(src,p+16,len);else func_02007ef4(src,p+12,len);
n=M2C_FIELD(&data_ov010_0222c960,u16 *,0);
M2C_FIELD(p,u8 *,4)=64;
M2C_FIELD(&data_ov010_0222c960,u16 *,0)=n+1;
M2C_FIELD(p,u16 *,6)=n;
M2C_FIELD(p,s32 *,8)=func_02072088(func_02007004(),64,0);
{u32 count=M2C_FIELD(&data_ov010_0222c960,u32 *,0xf04);M2C_FIELD(&data_ov010_0222c960,s32 *,0xf04)=count+1;}
return 1 ;
}

#pragma optimization_level 3
s32 func_ov010_022228c0(void *dst,s32 size,u32 group,s32 *flag){
s32 func_ov010_0222392c(s32);
s64 func_02007004(void);
void *func_ov010_02223878(s32);
s32 func_ov010_022239f4(void *,void *);
void func_02007ef4(void *,void *,s32);
void func_ov010_02224ef8(void *);
extern u8 data_ov010_0222c998[];
s32 count;
void *item;
void *state=data_ov010_0222c998+group*0x94;
s32 first=1;
u64 now;
count=func_ov010_0222392c(group);
while(count!=0){
now=func_02007004();
item=func_ov010_02223878(group);
if(!item)goto empty;
if(M2C_FIELD(item,u64 *,0x46c)>now+0x34){
if(M2C_FIELD(item,s32 *,0x45c)==0 && M2C_FIELD(state,void **,0x3c)!=0){
M2C_FIELD(state,s32 *,0x20)++;
func_02007ef4(M2C_FIELD(M2C_FIELD(state,void **,0x3c),void **,0x474),dst,size);
func_ov010_02224ef8(M2C_FIELD(state,void **,0x3c));
M2C_FIELD(state,void **,0x3c)=0;
if(flag)*flag|=1<<M2C_FIELD(item,u8 *,0x10);
return 1;
}
return 0;
}
if(now>M2C_FIELD(item,u64 *,0x46c)+0x8b4c){
M2C_FIELD(state,u32 *,0x58)=M2C_FIELD(item,u32 *,0x18);
count=func_ov010_022239f4(state,item);
func_ov010_02223878(group);
first=0;
}else{

if(M2C_FIELD(state,u32 *,0x58)+1!=M2C_FIELD(item,u32 *,0x18) && M2C_FIELD(state,u32 *,0x58)!=0 && M2C_FIELD(state,u32 *,0x58)<=M2C_FIELD(item,u32 *,0x18)){
if(M2C_FIELD(item,s32 *,0x45c)==0)M2C_FIELD(state,s32 *,0x14)++;
}
M2C_FIELD(state,u32 *,0x58)=M2C_FIELD(item,u32 *,0x18);
if(first && M2C_FIELD(state,s32 *,0x70)){
count=func_ov010_022239f4(state,item);
func_ov010_02223878(group);
M2C_FIELD(state,s32 *,0x70)--;
}else{
u32 t=(u32)(now-M2C_FIELD(item,u64 *,0x464));
u32 x=M2C_FIELD(state,u32 *,0x28);
u32 z=t-x;
M2C_FIELD(state,u32 *,0x28)=t;
z-=M2C_FIELD(state,u32 *,0x28);
{u32 smooth=t+(z>>4);M2C_FIELD(state,u32 *,0x2c)=smooth;M2C_FIELD(state,u32 *,0)=smooth;}
func_02007ef4(M2C_FIELD(item,void **,0x474),dst,size);
func_ov010_022239f4(state,item);
if(flag)*flag|=1<<M2C_FIELD(item,u8 *,0x10);
return 1;
}
}
continue;
empty:
M2C_FIELD(state,s32 *,8)=count;return 0;
}
if(M2C_FIELD(state,void **,0x3c)){func_ov010_02224ef8(M2C_FIELD(state,void **,0x3c));M2C_FIELD(state,void **,0x3c)=0;}
return 0;
}
#pragma optimization_level reset
s32 func_ov010_02222b0c(void *p,s32 size,s32 *out){
s32 func_ov010_022228c0(void*,s32,u32,s32*);
void func_ov010_02225558(void*,void*,void*,s32);
void func_02007e98(s32,void*,s32);
void func_ov010_02225304(void*,s32);
extern s32 data_ov010_0222c960;
extern u8 data_ov010_0222cb54[];
s32 result;u32 i,j;
if(out)*out=0;
result=0;
if(size==M2C_FIELD(&data_ov010_0222c960,s32*,0x24)&&M2C_FIELD(&data_ov010_0222c960,s32*,0x20)){
for(i=0;i<3;i++){
if(func_ov010_022228c0(p,size,i,out)==1){result=1;break;}
}
if(result){
j=i+1;
if(j==3)result=1;
else for(;j<3;j++){
if(func_ov010_022228c0(data_ov010_0222cb54,size,j,out)==1)
func_ov010_02225558(p,data_ov010_0222cb54,p,size);
}
}else func_02007e98(0,p,size);
}else{func_02007e98(0,p,size);result=0;}
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x18))func_ov010_02225304(p,size);
return result;
}

#pragma pop
s32 func_ov010_02222c28(s32 arg0) {
extern M2C_UNK data_ov010_0222edc0; extern u8 data_ov010_0222be2d[]; extern u8 data_ov010_0222be2c[]; extern M2C_UNK data_ov010_0222c960;
if(arg0>=5) return 0;
if(M2C_FIELD(&data_ov010_0222edc0,s32 *,0x10)!=1 && (u32)arg0<=1) return 0;
M2C_FIELD(&data_ov010_0222c960,s32 *,12)=data_ov010_0222be2d[arg0*2]+data_ov010_0222be2c[arg0*2]*68+12;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c)=arg0;
M2C_FIELD(&data_ov010_0222c960,s16 *,0x10)=0;
M2C_FIELD(&data_ov010_0222c960,u8 *,0x12)=0;
return 1;
}

void func_ov010_02222c9c(s32 arg0) {
    extern M2C_UNK data_ov010_0222c960;
    M2C_FIELD(&data_ov010_0222c960, s32 *, 0x18) = arg0;
}

s32 func_ov010_02222cac(void) { return 0; }

s32 func_ov010_02222f28(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *func_ov010_02224eb8(void);
    void func_ov010_0222369c(u32);
    void func_ov010_02223314(u32);
    void func_ov010_022236e4(void);
    void func_ov010_0222335c(void);
    s32 func_ov010_02223b18(void *, void *);
    void func_ov010_022233ac(void *);
    void func_ov010_02224ef8(void *);
    void func_02008048(void *, void *, s32);
    extern M2C_UNK data_ov010_0222c960;
    extern u8 data_ov010_0222c998[];
    extern u8 data_ov010_0222be2d[];
    extern u8 data_ov010_0222be2c[];

    u8 *slot;
    void *item;
    s32 r6;
    s32 i;
    s32 len;
    void *src;

    if (M2C_FIELD(&data_ov010_0222c960, s32 *, 0x20) == 0)
        return 0;

    slot = (u8 *)0;
    i = 0;
    {
        u8 *p = data_ov010_0222c998;
        while (i < 3) {
            if (M2C_FIELD(p, s32 *, 0x38) == arg0) {
                slot = p;
                break;
            }
            i++;
            p += 0x94;
        }
    }
    if (!slot)
        return 0;

    if (M2C_FIELD(arg1, u8 *, 4) == 0x41) {
        M2C_FIELD(slot, s32 *, 0x30) = M2C_FIELD(arg1, u16 *, 6);
        M2C_FIELD(slot, s32 *, 0x4c) = 0;
        M2C_FIELD(slot, s32 *, 0x6c) = 1;
        return 0;
    }
    if (M2C_FIELD(arg1, u8 *, 4) != 0x40)
        return 0;

    r6 = (s32)(M2C_FIELD(arg1, u8 *, 5) & 0x7f);
    if (r6 >= 5)
        return 0;
    M2C_FIELD(slot, s32 *, 0x24) = r6;

    {
        s32 needed = (s32)data_ov010_0222be2d[r6 * 2] + (s32)data_ov010_0222be2c[r6 * 2] * 0x44 + 0xc;
        if (arg2 != needed)
            return 0;
    }

    {
        s32 mask;
        if (arg0 != 0)
            mask = 1 << arg0;
        else
            mask = 1;
        if (!(M2C_FIELD(&data_ov010_0222c960, u32 *, 4) & (u32)mask))
            return 0;
    }

    item = func_ov010_02224eb8();
    if (!item) {
        func_ov010_0222369c((u32)M2C_FIELD(slot, s32 *, 0x34));
        func_ov010_02223314((u32)M2C_FIELD(slot, s32 *, 0x34));
        item = func_ov010_02224eb8();
        if (!item) {
            func_ov010_022236e4();
            func_ov010_0222335c();
            item = func_ov010_02224eb8();
        }
    }
    if (!item)
        return 0;

    len = arg2 - 0xc;
    src = (void *)((u8 *)item + 0x468 - arg2);
    func_02008048((u8 *)arg1 + 0xc, src, len);

    M2C_FIELD(item, u8 *, 0x11) = (u8)M2C_FIELD(slot, s32 *, 0x34);
    M2C_FIELD(item, s32 *, 0xc) = r6;
    M2C_FIELD(item, void **, 0x474) = (void *)src;
    M2C_FIELD(item, s32 *, 0x14) = len;
    M2C_FIELD(item, s32 *, 0x464) = arg3;
    M2C_FIELD(item, s32 *, 0x468) = arg4;
    M2C_FIELD(item, u8 *, 0x10) = (u8)arg0;

    {
        u8 b = (u8)(M2C_FIELD(arg1, u8 *, 5) & 0x80);
        M2C_FIELD(item, u32 *, 0x45c) = (u32)b;
    }
    M2C_FIELD(item, u32 *, 0x460) = M2C_FIELD(arg1, u32 *, 8);
    M2C_FIELD(item, u32 *, 0x18) = M2C_FIELD(arg1, u16 *, 6);

    if (func_ov010_02223b18(slot, item) != 0) {
        func_ov010_022233ac(item);
        return 1;
    }
    func_ov010_02224ef8(item);
    return 0;
}

