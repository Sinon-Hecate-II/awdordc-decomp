/* 22 functions from 0x0201F89C to 0x02020738 (main), found by ds-decomp. */
#include "common.h"

s32 func_0201f96c(void *arg0) {
    M2C_UNK func_02006564(s32);
    M2C_UNK func_020065e8(void *);
    M2C_UNK func_0201d190(u16, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d2b8();
    s32 func_0201d3e4(u16 *, M2C_UNK *);
    M2C_UNK sp4;
    u16 sp0;
    s32 temp_r0;
    void *temp_r4;
    void *temp_r5;

    temp_r4 = M2C_FIELD(arg0, void **, 4);
    temp_r5 = M2C_FIELD(temp_r4, void **, 0x64);
    func_02006564(temp_r5 + 0xE0);
    func_0201d190(M2C_FIELD(arg0, u16 *, 0x10), 0, 0);
    func_0201d2b8();
    M2C_FIELD(temp_r5, s32 *, 0xF8) = 0;
    temp_r0 = func_0201d3e4(&sp0, &sp4);
    *M2C_FIELD(arg0, u16 **, 0x14) = sp0;
    *M2C_FIELD(arg0, s32 **, 0x18) = temp_r0;
    M2C_FIELD(temp_r4, s16 *, 0x70) = (s16) (M2C_FIELD(temp_r4, s16 *, 0x70) | 4);
    func_020065e8(temp_r5 + 0xE0);
    return 0;
}

s32 func_0201f9e4(void *arg0,s32 arg1) {
s32 func_020214a8(); s32 func_0201fb3c(void *);s32 a;
if(func_020214a8()!=0)return -28;
a=0;if(arg0)a=(M2C_FIELD(arg0,volatile s16 *,0x70)&1)!=0;
if(!a)return -39;
if(M2C_FIELD(arg0,s16 *,0x70)&2)return -7;
M2C_FIELD(arg0,s16 *,0x74)=arg1;
if(M2C_FIELD(arg0,s8 *,0x73)!=1)return 0;
return func_0201fb3c(arg0);
}

s32 func_0201fb3c(void *arg0) {
s32 func_0201fb94(void *);
void *func_0201f1d0(s32 (*)(void *),void *,s8);
s32 func_0201f318(void *,void *);
void *p=func_0201f1d0(func_0201fb94,arg0,M2C_FIELD(arg0,s8 *,0x72));
if(!p)return -33;
M2C_FIELD(p,u16 *,0x10)=M2C_FIELD(arg0,u16 *,0x74);
M2C_FIELD(p,u16 *,0x12)=M2C_FIELD(arg0,u16 *,0x76);
M2C_FIELD(p,s32 *,0x14)=M2C_FIELD(arg0,s32 *,0x78);
M2C_FIELD(arg0,s16 *,0x70)|=2;
return func_0201f318(arg0,p);
}

s32 func_0201fb94(void *arg0) {
s32 func_0201d3a4(); void *p,*q;s32 v;s8 t;
p=M2C_FIELD(arg0,void **,4);v=0;q=M2C_FIELD(p,void **,0x64);
func_02006564(q+0xe0);
func_0201d190(M2C_FIELD(arg0,u16 *,0x10),M2C_FIELD(arg0,u16 *,0x12),M2C_FIELD(arg0,s32 *,0x14));
M2C_FIELD(q,s32 *,0xf8)=v;t=M2C_FIELD(arg0,s8 *,12);
if(t==0 || t==4)v=func_0201d3a4();
func_020065e8(q+0xe0);
if(v){M2C_FIELD(p,volatile s16 *,0x70)|=0x40;return -76;}
M2C_FIELD(p,volatile s16 *,0x70)|=4;return 0;
}

s32 func_0201fd60(void *p,s32 b,s32 c,s32 d,s32 e,s32 f,s32 flags) {
 s32 func_02020220(void *,s32,s32,s32,s32,s32);
 s32 func_0201fdfc(void *,s32,s32,s32,s32,s32);
 s32 func_02020188(void *);
 void *q=M2C_FIELD(p,void **,0x64);
 s32 enabled=(flags&2)!=0 && q!=0;
 s8 old;s32 result;
 if(enabled){old=M2C_FIELD(q,s8 *,0xFE);M2C_FIELD(q,s8 *,0xFE)=1;}
 if(M2C_FIELD(p,s8 *,0x73)==1)result=func_02020220(p,b,c,d,e,f);
 else{result=func_0201fdfc(p,b,c,d,e,f);if(result>=0)func_02020188(p);}
 if(enabled)M2C_FIELD(q,s8 *,0xFE)=old;
 return result;
}

s32 func_0201fdfc(void *p,s32 b,s32 c,s32 d,s32 e,s32 flags) {
 s32 func_0201ffec(void *,s32,s32,s32,s32);
 s32 func_0201fe70(void *,s32,s32,s32,s32);
 s32 result;
 if(M2C_FIELD(p,s8 *,0x73)==4)return func_0201ffec(p,b,c,d,e);
 result=func_0201fe70(p,b,c,d,e);
 if(result!=-6)return result;
 if(!(flags&1))return result;
 return func_0201ffec(p,b,c,d,e);
}

s32 func_0201ff78(void *p,s32 *remaining,u16 *a,u16 *b,s32 *c) {
 void *q=M2C_FIELD(p,void **,0x64);
 void *entry=M2C_FIELD(q,void **,0xC4);
 s32 offset=M2C_FIELD(q,s32 *,0xF8);
 s32 n=M2C_FIELD(entry,s32 *,0x44)-offset;
 if(n>=0){
 *a=M2C_FIELD(entry,u16 *,0xA);*b=M2C_FIELD(entry,u16 *,0x18);
 *c=M2C_FIELD(entry,s32 *,0x1C);*remaining=n;
 if(n==0 && M2C_FIELD(entry,u8 *,8)!=4)return 0;
 }else{*remaining=-1;return 0;}
 return M2C_FIELD(entry,s32 *,0x40)+offset;
}

s32 func_0201ffec(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
s32 func_02020038(void *);
void *p=func_0201f1d0(func_02020038,arg0,1);
M2C_FIELD(p,s32 *,0x10)=arg1;
M2C_FIELD(p,s32 *,0x14)=arg2;
M2C_FIELD(p,s32 *,0x18)=arg3;
M2C_FIELD(p,s32 *,0x1c)=arg4;
func_0201f318(arg0,p);
}

s32 func_02020188(void *arg0) {
void func_020201d4(void *);
void *q=M2C_FIELD(arg0,void **,0x64),*p;
if(M2C_FIELD(q,s32 *,0xf8)<M2C_FIELD(q,u16 *,0xfc))return 0;
p=func_0201f1d0((s32 (*)(void *))func_020201d4,arg0,0);
if(!p)return -33;
return func_0201f318(arg0,p);
}

void func_020201d4(void *arg0) {
    M2C_UNK func_020201e4(s32);
    func_020201e4(M2C_FIELD(arg0, s32 *, 4));
}

#pragma dont_inline on
s32 func_020201e4(s32 p) {
 s32 func_0200751c(void);s32 func_02007530(s32);void func_0201d70c(s32);
 void *q=M2C_FIELD(p,void **,0x64);
 s32 irq=func_0200751c();s32 value=M2C_FIELD(q,s32 *,0xF8);
 if(value){M2C_FIELD(q,s32 *,0xF8)=0;func_0201d70c(value);}
 func_02007530(irq);return value;
}
#pragma dont_inline reset

s32 func_02020690(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    M2C_UNK func_02005da4(void *);
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_02020714(void *);
    s32 temp_r11;
    void *temp_r4;
    s32 var_r8;
    s32 var_r5;

    var_r8 = arg2;
    temp_r4 = M2C_FIELD(arg0, void **, 0x68);
    if (var_r8 > arg1) {
        var_r8 = arg1;
    }
    temp_r11 = func_0200751c();
loop_3:
    var_r5 = func_02020714(arg0);
    if (var_r5 >= var_r8) {
        if (var_r5 >= arg1) {
            var_r5 = arg1;
        }
        *arg3 = (s32) M2C_FIELD(temp_r4, u16 *, 0x100);
    } else if (!(arg4 & 1)) {
        var_r5 = 0;
    } else {
        func_02005da4(temp_r4 + 0x104);
        goto loop_3;
    }
    func_02007530(temp_r11);
    return var_r5;
}

s32 func_02020714(void *arg0) {
void *p=M2C_FIELD(arg0,void **,0x68); volatile u16 *q=p+0x100;
s32 a=q[0],b=q[1],c=M2C_FIELD(p,s32 *,0xf8);
b=b-a-1;if(b<0)b+=c;return b;
}

