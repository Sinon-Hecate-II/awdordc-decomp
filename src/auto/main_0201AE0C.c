/* 15 functions from 0x0201AE0C to 0x0201BDE0 (main), found by ds-decomp. */
#include "common.h"

void func_0201ae0c(void *a,u32 ip,s32 create){
u64 func_02007004(void);s32 func_0201a6c4(u32);s32 func_0201a764(u32);
M2C_UNK func_02008048(M2C_UNK*,void*,M2C_UNK);
extern M2C_UNK data_02137290,data_02137310,data_0213731a;
u16 now;u32 i,best;u8 *p;s32 age,off;s32 delta;
if(ip==0x7f000001 || ip==M2C_FIELD(&data_02137290,u32*,80))return;
if(!func_0201a6c4(ip))return;
if(func_0201a764(ip))return;
now=func_02007004()>>16;
p=(u8*)&data_02137310;
for(i=0;i<8;i++,p+=12){
if(ip==M2C_FIELD(p,u32*,0)){
off=i*12;M2C_FIELD(&data_0213731a,u16*,off)=now;
func_02008048(a,(u8*)&data_02137310+off+4,6);return;
}}
if(!create)return;
age=0;p=(u8*)&data_02137310;best=0;i=0;
do{
if(!M2C_FIELD(p,u32*,0)){best=i;break;}
delta=now-M2C_FIELD(p,u16*,10);p+=12;
if(age<(s16)delta){best=i;age=(u16)delta;}
i++;
}while(i<8);
off=best*12;M2C_FIELD(&data_02137310,u32*,off)=ip;
func_02008048(a,(u8*)&data_02137310+off+4,6);
M2C_FIELD(&data_0213731a,u16*,off)=now;
}

void func_0201af48(void *arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u32 arg4, u16 arg5) {
    M2C_UNK func_02008048(M2C_UNK *, void *, M2C_UNK);
    s32 func_0201a704(u32);
    s32 func_0201a764(u32);
    M2C_UNK func_0201a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK *func_0201abd0(void);
    M2C_UNK *func_0201ad9c(s32);
    extern M2C_UNK data_02137778;
    M2C_UNK *var_r0;
    s32 temp_r0;
    u32 val;

    val = ((u32) arg5 << 8);
    val = val | (arg5 >> 8);
    M2C_FIELD(arg0, s16 *, -2) = (s16) val;
    if (func_0201a764(arg4) == 0) {
        temp_r0 = func_0201a704(arg4);
        if (temp_r0 == 0) {
            return;
        }
        var_r0 = func_0201abd0();
        if (var_r0 == 0) {
            var_r0 = func_0201ad9c(temp_r0);
            if (var_r0 == 0) {
                return;
            }
        }
        func_02008048(var_r0, arg0 - 0xE, 6);
    } else {
        M2C_FIELD(arg0, u8 *, -0xE) = 1;
        M2C_FIELD(arg0, u8 *, -0xD) = 0;
        M2C_FIELD(arg0, u8 *, -0xC) = 0x5E;
        M2C_FIELD(arg0, u8 *, -0xB) = (u8) ((arg4 >> 0x10) & 0x7F);
        M2C_FIELD(arg0, u8 *, -0xA) = (u8) (arg4 >> 8);
        M2C_FIELD(arg0, u8 *, -9) = (u8) arg4;
        func_02008048(&data_02137778, arg0 - 8, 6);
    }
    func_0201a824(arg0 - 0xE, arg1 + 0xE, arg2, arg3);
}

void func_0201b018(void *a,s32 b,s32 c,s32 d,u32 ip,s32 id){
s32 func_0200751c(void);void func_02007530(s32);
M2C_UNK func_02008048(M2C_UNK*,void*,M2C_UNK);
s32 func_0201a658(u8*,s32);s32 func_0201a764(u32);
M2C_UNK func_0201a880(void*,void*,void*,s32,s32,s32);
extern M2C_UNK data_02137290,data_020faf80,data_02137778;
u16 len,ident;s32 sum,t;
len=b+20+d;ident=id;
M2C_FIELD(a,u16*,-18)=((s32)len>>8)|(len<<8);
M2C_FIELD(a,u16*,-14)=((s32)ident>>8)|(ident<<8);
M2C_FIELD(a,u16*,-10)=0;
sum=func_0201a658(a-20,20);
M2C_FIELD(a,u16*,-10)=(sum>>8)|(sum<<8);
if(ip!=0x7f000001 && ip!=M2C_FIELD(&data_02137290,u32*,80))func_0201af48(a-20,b+20,c,d,ip,0x800);
if(ip!=0x7f000001 && ip!=M2C_FIELD(&data_02137290,u32*,80)){if(!func_0201a764(ip))return;}
func_02008048(&data_020faf80,a-28,8);
t=func_0200751c();
func_0201a880(&data_02137778,&data_02137778,a-28,b+28,c,d);
func_02007530(t);
}

void func_0201b140(void *arg0,u32 arg1,void *arg2,u32 arg3,u32 arg4,u8 arg5){
extern M2C_UNK data_02137290;
u32 temp_r5_2;u16 temp_r5,temp_r7,temp_r8,temp_r8_2,var_r4;s32 temp_r0;u32 var_r7,var_r9;void *var_r5,*var_r8;
M2C_FIELD(arg0,s8 *,-20)=0x45;
var_r4=0;M2C_FIELD(arg0,s8 *,-19)=0;
M2C_FIELD(&data_02137290,u16 *,6)=(u16)(M2C_FIELD(&data_02137290,u16 *,6)+1);
M2C_FIELD(arg0,s16 *,-16)=(s16)(((s32)M2C_FIELD(&data_02137290,u16 *,6)>>8)|(M2C_FIELD(&data_02137290,u16 *,6)<<8));
M2C_FIELD(arg0,u8 *,-12)=0x80;M2C_FIELD(arg0,u8 *,-11)=arg5;
temp_r8_2=(u16)(arg4>>16);temp_r8=(u16)(M2C_FIELD(&data_02137290,u32 *,80)>>16);
M2C_FIELD(arg0,s16 *,-8)=(s16)(((s32)temp_r8>>8)|(temp_r8<<8));
temp_r7=(u16)M2C_FIELD(&data_02137290,u32 *,80);temp_r5=(u16)arg4;
M2C_FIELD(arg0,s16 *,-6)=(s16)(((s32)temp_r7>>8)|(temp_r7<<8));
var_r9=arg1;M2C_FIELD(arg0,s16 *,-4)=(s16)(((s32)temp_r8_2>>8)|(temp_r8_2<<8));
var_r8=arg2;var_r7=arg3;
M2C_FIELD(arg0,s16 *,-2)=(s16)(((s32)temp_r5>>8)|(temp_r5<<8));
if(var_r9>0x5c8U){
var_r5=arg0;
if(var_r9>0x5c8U){do{func_0201b018(arg0,0,var_r5,0x5c8,arg4,var_r4|0x2000);var_r5+=0x5c8;var_r9-=0x5c8;var_r4+=0xb9;}while(var_r9>0x5c8U);}
if(var_r9){if(var_r7)func_0201b018(arg0,0,var_r5,var_r9,arg4,var_r4|0x2000);else func_0201b018(arg0,0,var_r5,var_r9,arg4,var_r4);
var_r4+=var_r9>>3;var_r9=0;}}
if(var_r9+var_r7>0x5c8U){do{temp_r5_2=0x5c8-var_r9;func_0201b018(arg0,var_r9,var_r8,temp_r5_2,arg4,var_r4|0x2000);var_r7-=temp_r5_2;var_r9=0;var_r8+=temp_r5_2;var_r4+=0xb9;}while(var_r7>0x5c8U);}
if(var_r9+var_r7==0)return;
func_0201b018(arg0,var_r9,var_r8,var_r7,arg4,var_r4);
}

void func_0201b338(void *arg0, void *arg1, void *arg2) {
    u32 func_0201a588(void *, u32, u32);
    M2C_UNK func_0201a63c(M2C_UNK);
    void func_0201b140(void *,u32,void *,u32,u32,u8);
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02137290;
    void *var_r4;
    u16 temp_lr;
    u32 temp_val;
    u32 sp_0;
    u32 sp_4;

    var_r4 = (void *) M2C_FIELD(arg2, u32 *, 0x4C);
    M2C_FIELD(var_r4, s16 *, 0x22) = 8;
    M2C_FIELD(var_r4, s16 *, 0x26) = (s16) ((u32)(&data_0212dca4) >> 4); // wait, ldr r2, [pc, #0x88] -> ldr r2, [data_0212dca4 + 4] or something. Let's use extern u32 data_02137290; extern u32 data_0212dca4;
}

void func_0201b3e8(void *arg0,s32 arg1,void *arg2) {
u32 func_0201a588(void *,u32,u32);s32 func_0201a63c(s32);void func_0201b140(void *,u32,void *,u32,u32,u8);
extern M2C_UNK data_02137290;
void *base=M2C_FIELD(arg2,void **,0x4c);void *p=base+0x22;u16 a,b,c,d,len; s32 sum;
a=M2C_FIELD(&data_02137290,u32 *,0x50)>>16;
M2C_FIELD(p,u16 *,-12)=((s32)a>>8)|(a<<8);
b=M2C_FIELD(&data_02137290,u32 *,0x50);
M2C_FIELD(p,u16 *,-10)=((s32)b>>8)|(b<<8);
c=M2C_FIELD(arg2,u32 *,0x1c)>>16;
M2C_FIELD(p,u16 *,-8)=((s32)c>>8)|(c<<8);
d=M2C_FIELD(arg2,u32 *,0x1c);
M2C_FIELD(p,u16 *,-6)=((s32)d>>8)|(d<<8);
M2C_FIELD(p,u16 *,-4)=0x1100;
len=arg1+8;M2C_FIELD(p,u16 *,4)=((s32)len>>8)|(len<<8);
M2C_FIELD(p,u16 *,-2)=M2C_FIELD(p,u16 *,4);
a=M2C_FIELD(arg2,u16 *,0x18);M2C_FIELD(p,u16 *,2)=((s32)a>>8)|(a<<8);
b=M2C_FIELD(arg2,u16 *,0xa);M2C_FIELD(base,u16 *,0x22)=((s32)b>>8)|(b<<8);
M2C_FIELD(p,u16 *,6)=0;
sum=func_0201a588(p-12,20,0);sum=func_0201a588(arg0,arg1,sum);
sum=func_0201a63c((u16)sum);M2C_FIELD(p,u16 *,6)=(sum>>8)|(sum<<8);
func_0201b140(p,8,arg0,arg1,M2C_FIELD(arg2,u32 *,0x1c),17);
}

s32 func_0201b524(void *a, void *b, void *c, void *d) {
    return 0;
}

void func_0201b798(void *arg0) {
    M2C_UNK func_02008048(M2C_UNK *, void *, M2C_UNK);
    M2C_UNK func_0201a824(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_02137778;
    u16 temp_ip;
    u16 temp_ip_2;

    M2C_FIELD(arg0, s16 *, 6) = 0x200;
    func_02008048(arg0 + 8, arg0 + 0x12, 0xA);
    func_02008048(&data_02137778, arg0 + 8, 6);
    temp_ip = (u16) ((u32) M2C_FIELD(&data_02137290, u32 *, 0x50) >> 0x10);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((temp_ip >> 8) | (temp_ip << 8));
    temp_ip_2 = (u16) M2C_FIELD(&data_02137290, u32 *, 0x50);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((temp_ip_2 >> 8) | (temp_ip_2 << 8));
    func_02008048(arg0 + 0x12, arg0 - 0xE, 6);
    func_02008048(&data_02137778, arg0 - 8, 6);
    func_0201a824(arg0 - 0xE, 0x2A, 0, 0);
}

#pragma optimization_level 2
#pragma opt_common_subs off
void func_0201b840(void *arg0,u32 arg1) {
s32 func_0201a7f8(void *,void *);extern M2C_UNK data_02137290,data_02137778;
u16 op,a,b,c,d,t;u32 src,dst,own;s32 same,local;
if(arg1<28)return;
if(func_0201a7f8(arg0+8,&data_02137778)&&M2C_FIELD(&data_02137290,u32 *,80)) {
if(M2C_FIELD(arg0,u16 *,0)==0x100&&M2C_FIELD(arg0,u16 *,2)==8&&M2C_FIELD(arg0,u16 *,4)==0x406) {
t=M2C_FIELD(arg0,u16 *,6);op=((s32)t>>8)|(t<<8);
if(op!=1&&op!=2)return;
a=M2C_FIELD(arg0,u16 *,16);b=M2C_FIELD(arg0,u16 *,14);
c=M2C_FIELD(arg0,u16 *,26);d=M2C_FIELD(arg0,u16 *,24);
src=((u16)(((s32)b>>8)|(b<<8))<<16)|(u16)(((s32)a>>8)|(a<<8));
own=M2C_FIELD(&data_02137290,u32 *,80);same=src==own;
dst=((u16)(((s32)d>>8)|(d<<8))<<16)|(u16)(((s32)c>>8)|(c<<8));
local=own==dst;
if(!same)func_0201ae0c(arg0+8,src,local);
if(op==1&&local){func_0201b798(arg0);return;}
if(op==2&&local&&same)M2C_FIELD(&data_02137290,u8 *,1)=1;
}
}}
#pragma opt_common_subs reset
#pragma optimization_level 4
M2C_UNK func_0201b984(void *arg0,u8 *arg1,s32 arg2){
s32 func_0201a658(u8 *,s32);s32 func_0201a704(u32);M2C_UNK *func_0201abd0(void);void func_0201aca0(s32);void func_0201b140(void *,u32,void *,u32,u32,u8);
s32 a,b;u16 hi,lo;u32 val;
lo=M2C_FIELD(arg0,u16*,14);hi=M2C_FIELD(arg0,u16*,12);
val=((u16)(((s32)hi>>8)|(hi<<8))<<16)|(u16)(((s32)lo>>8)|(lo<<8));
a=func_0201a704(val);if(!a)return;if(!func_0201abd0()){func_0201aca0(a);return;}
arg1[0]=0;M2C_FIELD(arg1,u16*,2)=0;b=func_0201a658(arg1,arg2);M2C_FIELD(arg1,u16*,2)=(b>>8)|(b<<8);
lo=M2C_FIELD(arg0,u16*,14);hi=M2C_FIELD(arg0,u16*,12);
val=((u16)(((s32)hi>>8)|(hi<<8))<<16)|(u16)(((s32)lo>>8)|(lo<<8));
func_0201b140(arg1,arg2,0,0,val,1);
}
#pragma optimization_level 4
M2C_UNK func_0201ba68(void *arg0,u8 *arg1,M2C_UNK arg2) {
s32 func_0200751c(void); void func_02007530(s32); void func_02005e5c(s32); M2C_UNK func_02008048(M2C_UNK *,void *,M2C_UNK);
extern M2C_UNK data_0212dca4;
void *entry; s32 saved,id; void *node; u16 low,high; u32 max,len;
saved=func_0200751c();
node=M2C_FIELD(&data_0212dca4,void **,8);
while(node){
entry=M2C_FIELD(node,void **,0xa4);
if(entry && (id=M2C_FIELD(entry,s32 *,0))!=0){
if(M2C_FIELD(entry,u8 *,8)==11 && M2C_FIELD(arg1,u16 *,4)==(u16)id && M2C_FIELD(entry,u16 *,10)==M2C_FIELD(arg1,u16 *,6) && M2C_FIELD(entry,u32 *,68)==0){
low=M2C_FIELD(arg0,u16 *,14);high=M2C_FIELD(arg0,u16 *,12);
if(M2C_FIELD(entry,u32 *,28)==(((u16)(((s32)high>>8)|(high<<8))<<16)|(u16)(((s32)low>>8)|(low<<8)))){
max=M2C_FIELD(entry,u32 *,60);len=arg2-8;
if(len>max)M2C_FIELD(entry,u32 *,68)=max;else M2C_FIELD(entry,u32 *,68)=len;
func_02008048((M2C_UNK *)(arg1+8),M2C_FIELD(entry,void **,64),M2C_FIELD(entry,u32 *,68));
if(M2C_FIELD(entry,s32 *,4)==3){M2C_FIELD(entry,s32 *,4)=0;func_02005e5c(M2C_FIELD(entry,s32 *,0));}
break;
}
}
}
node=M2C_FIELD(node,void **,104);
}
func_02007530(saved);
}

s32 func_0201bb68(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 != -1) && (arg1 != 0) && (arg1 != -1)) {
        return 1;
    }
    return 0;
}

void func_0201bb88(void *arg0, u8 *arg1, M2C_UNK arg2) {
    s32 func_0201a658(u8 *, M2C_UNK);
    M2C_UNK func_0201b984(void *, u8 *, M2C_UNK);
    M2C_UNK func_0201ba68(void *, u8 *, M2C_UNK);
    u16 w0;
    u16 w1;
    u16 w2;
    u16 w3;
    u32 a;
    u32 b;
    u8 c;

    if (func_0201a658(arg1, arg2) != 0xFFFF) {
        return;
    }
    w0 = M2C_FIELD(arg0, u16 *, 0x12);
    w1 = M2C_FIELD(arg0, u16 *, 0x10);
    w2 = M2C_FIELD(arg0, u16 *, 0xE);
    w3 = M2C_FIELD(arg0, u16 *, 0xC);

    w0 = (u16)((w0 << 8) | (w0 >> 8));
    w1 = (u16)((w1 << 8) | (w1 >> 8));
    w2 = (u16)((w2 << 8) | (w2 >> 8));
    w3 = (u16)((w3 << 8) | (w3 >> 8));

    a = ((u32)w3 << 16) | w2;
    b = ((u32)w1 << 16) | w0;

    if (func_0201bb68(a, b) == 0) {
        return;
    }
    c = *arg1;
    if (c == 0) {
        func_0201ba68(arg0, arg1, arg2);
        return;
    }
    if (c == 8) {
        func_0201b984(arg0, arg1, arg2);
        return;
    }
}

void *func_0201bc58(void *arg0, void *arg1) {
extern M2C_UNK data_0212dca4;
void *entry,*node; u16 a,b,c,d,e;
node=M2C_FIELD(&data_0212dca4,void **,8);
while(node){
entry=M2C_FIELD(node,void **,0xa4);
if(entry && M2C_FIELD(entry,s32 *,0) && M2C_FIELD(entry,u8 *,8)==1){
a=M2C_FIELD(arg1,u16 *,2);
if(M2C_FIELD(entry,u16 *,10)!=(u16)(((s32)a>>8)|(a<<8)))goto next;
b=M2C_FIELD(entry,u16 *,24);
if(b){c=M2C_FIELD(arg1,u16 *,0);if(b!=(u16)(((s32)c>>8)|(c<<8)))goto next;}
if(M2C_FIELD(entry,u32 *,28)){
d=M2C_FIELD(arg0,u16 *,14);e=M2C_FIELD(arg0,u16 *,12);
if(M2C_FIELD(entry,u32 *,28)!=(((u16)(((s32)e>>8)|(e<<8))<<16)|(u16)(((s32)d>>8)|(d<<8))))goto next;
}
return entry;
}
next: node=M2C_FIELD(node,void **,0x68);
}
return 0;
}

s32 func_0201bd2c(void *arg0, void *arg1, void *arg2) {
    s32 var_ip;
    s32 var_r3;
    s32 var_r5;
    s32 var_r6;
    u16 temp_lr;
    u16 temp_lr_2;
    u16 temp_lr_3;
    u16 temp_r4_2;
    u8 temp_r4;

    temp_r4 = M2C_FIELD(arg2, u8 *, 8);
    var_r3 = 0;
    var_r5 = 0;
    if ((temp_r4 != 0xA) && (temp_r4 != 0xB)) {
        var_r5 = 1;
    }
    var_ip = 0;
    var_r6 = 0;
    if (var_r5 != 0) {
        temp_lr = M2C_FIELD(arg1, u16 *, 2);
        if (M2C_FIELD(arg2, u16 *, 0xA) == (u16) ((temp_lr >> 8) | (temp_lr << 8))) {
            var_r6 = 1;
        }
    }
    if (var_r6 != 0) {
        temp_lr_2 = M2C_FIELD(arg1, u16 *, 0);
        if (M2C_FIELD(arg2, u16 *, 0x18) == (u16) ((temp_lr_2 >> 8) | (temp_lr_2 << 8))) {
            var_ip = 1;
        }
    }
    if (var_ip != 0) {
        temp_lr_3 = M2C_FIELD(arg0, u16 *, 0xC);
        temp_r4_2 = M2C_FIELD(arg0, u16 *, 0xE);
        if (M2C_FIELD(arg2, s32 *, 0x1C) == ((u16) ((temp_r4_2 >> 8) | (temp_r4_2 << 8)) | ((u16) ((temp_lr_3 >> 8) | (temp_lr_3 << 8)) << 0x10))) {
            var_r3 = 1;
        }
    }
    return var_r3;
}

