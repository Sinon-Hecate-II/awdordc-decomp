/* 24 functions from 0x020756A4 to 0x02076698 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 pad[0x2050]; u8 active, unk2051, state, unk2053; u8 queue[0x500]; u32 count; } Queue02075;

void func_02075938(void *arg0, s32 arg1) {
    M2C_UNK func_02074aec(void *);
    s32 var_r4;
    s32 var_r5;
    u32 temp_r8;
    void *temp_r7;
    var_r5 = arg1;
    if ((M2C_FIELD(arg0, u8 *, 0x2050) != 0) && (M2C_FIELD(arg0, u8 *, 0x2052) != 1)) {
        if ((((s32) M2C_FIELD((arg0 + (var_r5 >> 2)), u8 *, 0xC0C) >> ((u32) (var_r5 << 0x1E) >> 0x1D)) & 3) != 3) return;
        var_r4 = (var_r5 * 0xC) + (s32) arg0;
        if (M2C_FIELD(var_r4, u8 *, 6) == 1) return;
        func_02074aec(arg0 + 0xC4C);
loop_9:
        temp_r8 = (u32) (var_r5 << 0x1E) >> 0x1D;
        temp_r7 = arg0 + (var_r5 >> 2);
        var_r5 = (u8) (M2C_FIELD(temp_r7, u8 *, 0xC0C) & (-1 ^ (3 << temp_r8)));
        M2C_FIELD(temp_r7, u8 *, 0xC0C) = var_r5 | (2 << temp_r8);
        var_r5 = (s32) M2C_FIELD(var_r4, u16 *, 0xA);
        if (var_r5 != 0xFFFF) {
            register var_r4 = (var_r5 * 0xC) + (s32) arg0;
            goto loop_9;
        }
    }
}

#pragma opt_common_subs off
s32 func_020759e8(M2C_UNK *p,s32 index,s32 dest) {
s32 func_0200558c(void);
void *entry; s32 start=dest; u8 ok=1; u16 id;
if(M2C_FIELD(p,u8*,0x2050)==0)return 0;
if(M2C_FIELD(p,u8*,0x2052)==1)return 0;
id=func_0200558c();
while(index!=0xffff){
entry=(void*)p+index*12;
func_0200fe5c(id);
if(M2C_FIELD(entry,u16*,8)==0xffff)
func_0201033c((index<<10)+0x38,dest,M2C_FIELD(entry,u16*,4)-0x38,0,0,1,6,1,0);
else
func_0201033c((index<<10)+0x14,dest,M2C_FIELD(entry,u16*,4)-0x14,0,0,1,6,1,0);
ok=func_02010584()!=0;
func_0200fe6c(id);
if(!ok){M2C_FIELD(p,u8*,0x2052)=1;break;}
index=M2C_FIELD(entry,u16*,10);
if(M2C_FIELD(entry,u16*,8)==0xffff)dest+=M2C_FIELD(entry,u16*,4)-0x38;
else dest+=M2C_FIELD(entry,u16*,4)-0x14;
}
func_020055f4(id);
return ok?dest-start:0;
}
#pragma opt_common_subs reset
s32 func_02075b58(M2C_UNK *arg0, s32 arg1) {
    void *temp_ip;
    s32 var_lr;
    var_lr = 0;
    if (M2C_FIELD(arg0,u8 *,0x2050)==0) return 0;
    if (M2C_FIELD(arg0,u8 *,0x2052)==1) return 0;
    while (arg1 != 0xFFFF) {
        temp_ip = (void *)arg0 + arg1 * 12;
        if (M2C_FIELD(temp_ip,u16 *,8) == 0xFFFF) {
            arg1 = M2C_FIELD(temp_ip,u16 *,4) - 0x38;
        } else {
            arg1 = M2C_FIELD(temp_ip,u16 *,4) - 0x14;
        }
        var_lr += arg1;
        arg1 = M2C_FIELD(temp_ip,u16 *,10);
    }
    return var_lr;
}

M2C_UNK func_02075bc8(M2C_UNK *p) {
u8 *q;u32 i;
if(((Queue02075*)p)->active!=0 && ((Queue02075*)p)->state!=1){
if(!func_02074d44(p)){M2C_FIELD(p,u8*,0x2052)=1;return;}
func_02074a48((void*)p+0xc4c);
q=(void*)p+0x2054;i=0;
if((s32)((Queue02075*)p)->count>0){
for(;i<((Queue02075*)p)->count;i++,q+=20){

switch(q[15]){
case 1:func_020753f8(p,*(s32*)q,*(s32*)(q+4),*(s32*)(q+8),q[14],*(s32*)(q+16));break;
case 2:func_02075938(p,*(u16*)(q+12));break;
}
}

}
func_020756a4(p);
((Queue02075*)p)->count=0;
func_02074b84((void*)p+0xc4c);
}
}

void func_02075e84(M2C_UNK *arg0, s32 arg1) {
 s32 temp_ip;
 if ((M2C_FIELD(arg0,u8 *,0x2050)!=0)&&(M2C_FIELD(arg0,u8 *,0x2052)!=1)) {
 temp_ip=M2C_FIELD(arg0,s32 *,0x2554)*0x14+(s32)((void *)arg0+0x2054);
 M2C_FIELD(temp_ip,u8 *,0xF)=2;
 M2C_FIELD(temp_ip,s16 *,0xC)=arg1;
 M2C_FIELD(arg0,s32 *,0x2554)=M2C_FIELD(arg0,s32 *,0x2554)+1;
 }
}

void func_02075ecc(void) {
 M2C_UNK func_02074c58(void *);
 M2C_UNK func_02074dec(void *);
 extern M2C_UNK data_0213ea18;
 func_02074c58(&data_0213ea18);
 func_02074dec(&data_0213ea18);
}

void func_02075ee8(void) {
    M2C_UNK func_02075bc8(M2C_UNK *);
    extern M2C_UNK data_0213ea18;
    func_02075bc8(&data_0213ea18);
}

void func_02075efc(void) {
s32 func_0200558c(void); s32 func_02010424(void); s32 func_0201044c(s32);
s32 sp14;u16 a,b;u8 c;
if(func_0200fe08()){
a=func_0200558c();func_0200fe5c(a);
c=func_0201044c(0x1202);func_0200fe6c(a);func_020055f4(a);
if(c && (u8)func_02010424()==2){
b=func_0200558c();func_0200fe5c(b);
func_0201033c(0,&sp14,4,0,0,0,6,1,0);
func_0200fe6c(b);func_020055f4(b);
}}
func_0209e044(func_02075ecc,1,0x400,0x11,0);
}

void func_02075fd8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_02075cbc(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_0213ea18;
    func_02075cbc(&data_0213ea18, arg0, arg1, arg2, arg3);
}

void func_02076010(s32 type,s32 max){
void func_02076180(M2C_UNK);
M2C_UNK *func_02076228(void);s32 func_02076234(void);
void *func_020e34bc(s32);void func_020e35cc(void *);
s32 count;u8 **items;s32 best,n,i,k,j,cmp;u8 *p;u32 b,a;
p=(u8 *)func_02076228();n=func_02076234();
count=0;items=func_020e34bc((max+1)*4);
for(i=0;i<n;i++,p+=40){
if(type==p[2]){
if(count<max){items[count]=p;count=count+1;continue;}
items[count]=p;
best=0;
k=count+1;
for(j=1;j<k;j++){
b=M2C_FIELD(items[j],u32 *,4);a=M2C_FIELD(items[best],u32 *,4);
if((a&0xffff0000)==0xffff0000 && !(b&0xffff0000) && b!=0)cmp=0;
else if(!(a&0xffff0000) && (b&0xffff0000)==0xffff0000 && a!=0)cmp=1;
else cmp=a>b;
if(cmp)best=j;
}
func_02076180(M2C_FIELD(items[best],u16 *,0));
for(;best<count;best++)items[best]=items[best+1];
}
}
if(items)func_020e35cc(items);
}

void func_02076180(M2C_UNK arg0) {
    extern M2C_UNK data_0213ea18;
    func_02075e84(&data_0213ea18, arg0);
}

void func_02076198(void){func_0209e044(func_02075ee8,1,0x400,0x11,0);}

void func_020761c0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020759e8(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213ea18;
    func_020759e8(&data_0213ea18, arg0, arg1);
}

void func_020761e0(M2C_UNK arg0) {
    extern M2C_UNK data_0213ea18;
    func_02075b58(&data_0213ea18, arg0);
}

void func_020761f8(void) {
    func_0209e0dc(1);
}

u8 func_02076208(void) {
    extern M2C_UNK data_02140a18;
    return M2C_FIELD(&data_02140a18, u8 *, 0x52);
}

u8 func_02076218(void){extern M2C_UNK data_02140a18;return M2C_FIELD(&data_02140a18,u8*,0x53);}

M2C_UNK *func_02076228(void) {
    extern M2C_UNK data_0213f664;
    return &data_0213f664;
}

s32 func_02076234(void){extern M2C_UNK data_02140a18;return M2C_FIELD(&data_02140a18,s32*,0x4c);}

u8 func_02076614(u32 arg0) {
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r1;

    temp_r0_2 = arg0 - (0x55555555 & (arg0 >> 1));
    temp_r1 = (temp_r0_2 & 0x33333333) + (0x33333333 & (temp_r0_2 >> 2));
    temp_r0_3 = (temp_r1 + (temp_r1 >> 4)) & 0x0F0F0F0F;
    temp_r0 = temp_r0_3 + (temp_r0_3 >> 8);
    return (u8) (temp_r0 + (temp_r0 >> 0x10));
}

void func_02076658(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2){
M2C_UNK sp0[26];
func_0200c9c8(sp0);func_0200ca18(sp0,arg1,arg2);func_0200cb6c(sp0,arg0);
}

