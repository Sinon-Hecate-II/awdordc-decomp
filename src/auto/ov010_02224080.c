/* 30 functions from 0x02224080 to 0x02224F94 (ov010), found by ds-decomp. */
#include "common.h"
typedef struct PoolEntry0222415c { u8 data[20]; struct PoolEntry0222415c *next; } PoolEntry0222415c;
extern s32 data_ov010_0222d920[4];
extern s32 data_ov010_0222d914[3];
extern u8 data_ov010_0222be4c[8];
extern u8 data_ov010_0222be54[8];

s32 func_ov010_02224080(void *arg0, s32 arg1, void *arg2, u32 arg3) {
    M2C_UNK func_ov010_02224700(void *, void *, u8);
    s32 func_ov010_02224820(void *);
    s32 func_ov010_0222486c(void *, void *);
    extern M2C_UNK data_ov010_0222edc0;

    if (arg0 == NULL) {
        return -1;
    }
    if (arg3 < 0x10) {
        return -1;
    }
    if ((arg1 < 0) || (arg1 >= 6)) {
        return -3;
    }
    M2C_FIELD(arg2, u8 *, 4) = 0;
    func_ov010_02224700(arg0, arg2, (u8) arg1);
    if (arg1 == 0) {
        if ((M2C_FIELD(&data_ov010_0222edc0, s32 *, 0x10) == 1) && (M2C_FIELD(arg0, s32 *, 0xC) == 4)) {
            if (func_ov010_02224820(arg0) == 0) {
                return -3;
            }
        }
        M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(arg0, u8 *, 4) ? (1 << M2C_FIELD(arg0, u8 *, 4)) : 1;
    }
    if (func_ov010_0222486c(arg0, arg2) == 0) {
        return -3;
    }
    return 0;
}

s32 func_ov010_02224138(s32 arg0, s32 arg1) {
    s32 func_ov010_02224460(void *, s32);
    extern M2C_UNK data_ov010_0222edc0;
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0x10) == 2) return -3;
    return func_ov010_02224460(arg0, arg1);
}

#pragma opt_strength_reduction off
s32 func_ov010_0222415c(void *p){
extern M2C_UNK data_ov010_0222d8b4,data_ov010_0222d8f0,data_ov010_0222d8d8,data_ov010_0222edc0;
void func_02007f8c(void*,s32,u32);u64 func_02007004(void);
u32 i,offset;void *pool=M2C_FIELD(p,void**,0);
if(!pool||!M2C_FIELD(p,u32*,4)||M2C_FIELD(p,u32*,4)>8)return 0;
M2C_FIELD(&data_ov010_0222d8b4,void**,16)=M2C_FIELD(p,void**,0);
func_02007f8c(pool,0,M2C_FIELD(p,u32*,4)*24);
func_02007f8c(&data_ov010_0222d8f0,0,24);
func_02007f8c(&data_ov010_0222d8d8,0,24);
i=0;
if(M2C_FIELD(p,u32*,4)-1){offset=0;do{
M2C_FIELD(M2C_FIELD(&data_ov010_0222d8b4,u8**,16)+offset,void**,20)=M2C_FIELD(&data_ov010_0222d8b4,u8**,16)+ (++i)*24;
offset+=24;
}while(i<M2C_FIELD(p,u32*,4)-1);}
M2C_FIELD(M2C_FIELD(&data_ov010_0222d8b4,u8**,16)+M2C_FIELD(p,u32*,4)*24,s32*,-4)=0;
M2C_FIELD(&data_ov010_0222d8b4,s32*,20)=0;
M2C_FIELD(&data_ov010_0222d8b4,s32*,4)=0;
M2C_FIELD(&data_ov010_0222d8b4,s32*,0)=0;
M2C_FIELD(&data_ov010_0222edc0,s32*,20)=0;
M2C_FIELD(&data_ov010_0222d8b4,u64(**)(void),24)=func_02007004;
M2C_FIELD(&data_ov010_0222d8b4,u32*,28)=0x5d588b65;
M2C_FIELD(&data_ov010_0222d8b4,u32*,32)=0x269ec3;
return 1;
}
#pragma opt_strength_reduction reset
void func_ov010_02224270(void) {
    extern M2C_UNK data_ov010_0222d8b4;
    M2C_FIELD(&data_ov010_0222d8b4, s32 *, 0x14) = 0;
    M2C_FIELD(&data_ov010_0222d8b4, s32 *, 0x10) = 0;
}

void func_ov010_02224288(void) {
    u64 func_02007004(void);
    M2C_UNK func_ov010_0222458c(s32);
    extern M2C_UNK data_ov010_0222edc0;
    extern M2C_UNK data_ov010_0222d8b4;
    extern M2C_UNK data_ov010_0222c024;
    extern M2C_UNK data_ov010_0222d8f0;
    u64 now;
    u64 last;

    now = func_02007004();
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0x10) != 2) {
        return;
    }
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0xC) == 0) {
        return;
    }
    last = M2C_FIELD(&data_ov010_0222d8b4, u64 *, 8);
    if (last == 0) {
        return;
    }
    if (now - last <= M2C_FIELD(&data_ov010_0222c024, u64 *, 0)) {
        return;
    }
    M2C_FIELD(&data_ov010_0222d8b4, s32 *, 8) = 0;
    M2C_FIELD(&data_ov010_0222d8b4, s32 *, 0xC) = 0;
    M2C_FIELD(&data_ov010_0222d8b4, s32 *, 0x3C) = 0;
    M2C_FIELD(&data_ov010_0222d8b4, s32 *, 0x48) = 0;
    func_ov010_0222458c(0);
    M2C_FIELD(&data_ov010_0222edc0, M2C_UNK (**)(u8, s32, M2C_UNK *, M2C_UNK), 4)(
        M2C_FIELD(&data_ov010_0222d8b4, u8 *, 0x40), 9, &data_ov010_0222d8f0,
        M2C_FIELD(&data_ov010_0222edc0, M2C_UNK *, 8));
}

s32 func_ov010_02224334(s32 arg0, void *arg1, s32 arg2, M2C_UNK arg3) {
    s32 func_ov010_02224974(void *, M2C_UNK);
    s32 func_ov010_02224ab0(void *, M2C_UNK);
    s32 func_ov010_02224c40(void *, M2C_UNK);
    extern M2C_UNK data_ov010_0222edc0;

    if (arg2 != 0x10) {
        return 0;
    }
    if ((M2C_FIELD(arg1, u8 *, 8) != arg0) || (M2C_FIELD(arg1, u8 *, 9) != M2C_FIELD(&data_ov010_0222edc0, u8 *, 0))) {
        return 0;
    }
    if (M2C_FIELD(arg1, u8 *, 5) != 0x10) {
        return func_ov010_02224c40(arg1, arg3);
    }
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0xC) == 0) {
        return func_ov010_02224974(arg1, arg3);
    }
    return func_ov010_02224ab0(arg1, arg3);
}

void *func_ov010_022243b0(u32 arg0) {
    void func_ov010_022245cc();
    extern M2C_UNK data_ov010_0222edc0;
    extern M2C_UNK data_ov010_0222d8b4;
    void *temp_r4;

    if (arg0 >= 0x20) {
        return NULL;
    }
    if (arg0 == M2C_FIELD(&data_ov010_0222edc0, u8 *, 0)) {
        return NULL;
    }
    temp_r4 = M2C_FIELD(&data_ov010_0222d8b4, void **, 0x10);
    if (temp_r4 == NULL) {
        return NULL;
    }
    M2C_FIELD(&data_ov010_0222d8b4, void **, 0x10) = M2C_FIELD(temp_r4, void **, 0x14);
    func_ov010_022245cc(temp_r4);
    M2C_FIELD(temp_r4, void **, 0x14) = M2C_FIELD(&data_ov010_0222d8b4, void **, 0x14);
    M2C_FIELD(&data_ov010_0222d8b4, void **, 0x14) = temp_r4;
    return temp_r4;
}

s32 func_ov010_0222441c(void *arg0, M2C_UNK arg1) {
    s32 func_ov010_02223fac(void *, M2C_UNK, void *, u32);
    s32 func_ov010_02224614(void *, void *);
    u8 sp0[0x10];
    s32 temp_r0;

    temp_r0 = func_ov010_02223fac(arg0, arg1, sp0, 0x10);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (func_ov010_02224614(arg0, sp0) != 0) {
        return 0;
    }
    return -4;
}

s32 func_ov010_02224460(void *arg0,s32 arg1) {
 u8 sp0[0x10]; s32 result;
 s32 func_ov010_02224614(void *,void *);
 result=func_ov010_02224080(arg0,arg1,sp0,0x10);
 if(result!=0) return result;
 if(func_ov010_02224614(arg0,sp0)!=0) return 0;
 return -4;
}

void func_ov010_022244a4(void *arg0, void *arg1) {
    extern M2C_UNK data_ov010_0222d8b4;

    if (M2C_FIELD(arg1, u8 *, 0xa) != 1) {
        return;
    }
    M2C_FIELD(arg1, u8 *, 0xb) = M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg1, s32 *, 0xc) = M2C_FIELD(&data_ov010_0222d8b4, s32 *, 4);
}

s32 func_ov010_022244cc(void *arg0, void *arg1) {
    s32 func_0204431c(u8, void *, u32);
    void func_ov010_022244a4(void *, void *);
    extern M2C_UNK data_ov010_0222edc0;
    extern M2C_UNK data_ov010_0222d8b4;
    M2C_UNK sp0;
    s32 var_r1;
    s32 var_r8;
    u8 var_r9;
    u8 temp_r0;

    sp0 = (M2C_UNK) arg0;
    var_r8 = 0;
    func_ov010_022244a4(arg0, arg1);
    var_r9 = 0;
    do {
        if (var_r9 != 0) {
            var_r1 = 1 << var_r9;
        } else {
            var_r1 = 1;
        }
        if ((M2C_FIELD(&data_ov010_0222d8b4, u32 *, 4) & var_r1) &&
            (var_r9 != M2C_FIELD(&data_ov010_0222edc0, u8 *, 0))) {
            M2C_FIELD(arg1, u8 *, 9) = var_r9;
            if (func_0204431c(var_r9, arg1, 0x10) != 0) {
                var_r8 += 1;
            }
        }
        var_r9 += 1;
    } while (var_r9 < 0x20);
    temp_r0 = M2C_FIELD(arg1, u8 *, 0xa);
    if (temp_r0 == 1) {
        M2C_FIELD((void *) sp0, s32 *, 8) = M2C_FIELD(&data_ov010_0222d8b4, s32 *, 4);
    } else if (temp_r0 == 0) {
        M2C_FIELD((void *) sp0, s32 *, 8) = 0;
    }
    if (var_r8 == 0) {
        return -4;
    }
    return 0;
}

M2C_UNK func_ov010_0222458c(s32 arg0) {
 extern M2C_UNK data_ov010_0222d8f0;
 M2C_UNK func_ov010_02224700(void *,void *,u8);
 u8 sp0[0x10];
 sp0[4]=0xff;
 func_ov010_02224700(&data_ov010_0222d8f0,sp0,4);
 sp0[0xa]=arg0;
 func_ov010_022244cc(&data_ov010_0222d8f0,sp0);
}

void func_ov010_022245cc(void *arg0,s32 arg1) {
 u32 i;
 u8 *ptr;
 extern M2C_UNK data_ov010_0222edc0;
 ptr=arg0;
 i=6;
 do { ptr[0]=0; ptr[1]=0; ptr[2]=0; ptr[3]=0; ptr+=4; } while(--i);
 M2C_FIELD(arg0,s32 *,0)=M2C_FIELD(&data_ov010_0222edc0,s32 *,0x10);
 M2C_FIELD(arg0,s32 *,0xc)=0;
 M2C_FIELD(arg0,s8 *,4)=arg1;
}

s32 func_ov010_02224614(void *arg0,void *arg1) {
 s32 func_0204431c(u8,void *,u32);
 if(M2C_FIELD(arg1,u8 *,4)==0xff && M2C_FIELD(arg1,u8 *,6)==4) {
 func_ov010_022244cc(arg0,arg1);
 } else {
 if(func_0204431c(M2C_FIELD(arg0,u8 *,4),arg1,0x10)==0) return 0;
 }
 return 1;
}

u8 func_ov010_02224654(u8 *a,u8 *b){s32 n,v;b[5]=a[11];if(a[4]==255){if(a[6]==0){M2C_FIELD(b,s32 *,8)=b[4]?(1<<b[4]):1;}return data_ov010_0222be4c[a[6]];}if(a[4]==0){if(a[6]==0){n=M2C_FIELD(b,s32 *,12);if(n==1){M2C_FIELD(b,s32 *,8)=b[4]?(1<<b[4]):1;return 7;}if(n==5)return 9;return 12;}return data_ov010_0222be54[a[6]];}return 12;}

M2C_UNK func_ov010_02224700(void *a,void *b,u8 c){extern M2C_UNK data_ov010_0222edc0;M2C_FIELD(b,s32 *,0)=0x5f564354;M2C_FIELD(b,u8 *,5)=16;M2C_FIELD(b,u8 *,6)=c;M2C_FIELD(b,u8 *,8)=M2C_FIELD(&data_ov010_0222edc0,u8 *,0);M2C_FIELD(b,u8 *,9)=M2C_FIELD(a,u8 *,4);M2C_FIELD(b,u8 *,10)=0;M2C_FIELD(b,u8 *,11)=M2C_FIELD(&data_ov010_0222edc0,u8 *,0);M2C_FIELD(b,s32 *,12)=0;return 0;}

s32 func_ov010_02224748(void *a, void *b) {
    extern M2C_UNK data_ov010_0222edc0;
    extern s8 data_ov010_0222bf22[];
    extern s8 data_ov010_0222be5c[];
    s32 func_ov010_02224460(void *, s32);
    s32 i = M2C_FIELD(b, u8 *, 6);
    s8 *t;
    s8 v;

    if (M2C_FIELD(b, u8 *, 4) == 0) i += 5;
    if (i < 0 || i >= 11) i = -1;
    if (i < 0) return -1;
    t = M2C_FIELD(&data_ov010_0222edc0, s32 *, 16) == 1 ? data_ov010_0222bf22 : data_ov010_0222be5c;
    v = *(i + (t + M2C_FIELD(a, s32 *, 12) * 11));
    switch (v) {
    case -2:
        func_ov010_02224460(a, 1);
        M2C_FIELD(a, s32 *, 12) = 0;
        M2C_FIELD(a, s32 *, 0) = 0;
        return v;
    case -3:
        func_ov010_02224460(a, 3);
        M2C_FIELD(a, s32 *, 12) = 0;
        M2C_FIELD(a, s32 *, 0) = 0;
        return v;
    case -1:
        return v;
    }
    return v;
}

s32 func_ov010_02224820(void *a){extern M2C_UNK data_ov010_0222d8b4;void *p=M2C_FIELD(&data_ov010_0222d8b4,void **,20);while(p){if(M2C_FIELD(p,s32 *,0)&&M2C_FIELD(p,s32 *,12)==2&&a!=p)return 0;p=M2C_FIELD(p,void **,20);}return 1;}

s32 func_ov010_0222486c(void *a,void *b){
extern M2C_UNK data_ov010_0222edc0;
extern s8 data_ov010_0222be9e[]; extern s8 data_ov010_0222bee0[];
s32 i=M2C_FIELD(b,u8 *,6); s8 *t; s8 v;
if(M2C_FIELD(b,u8 *,4)==0)i+=5;
if(i<0 || i>=11)i=-1;
if(i<0)return -1;
t=M2C_FIELD(&data_ov010_0222edc0,s32 *,16)==1?data_ov010_0222be9e:data_ov010_0222bee0;
v=*(i+(t+M2C_FIELD(a,s32 *,12)*11));
if(v==-1)return 1;
if(v==-2)return 0;
M2C_FIELD(a,s32 *,12)=v;return 1;
}

s32 *func_ov010_022248f4(u8 a){
extern M2C_UNK data_ov010_0222edc0;extern M2C_UNK data_ov010_0222d8b4;extern M2C_UNK data_ov010_0222d8f0;
void *p=M2C_FIELD(&data_ov010_0222d8b4,void **,20);
if(M2C_FIELD(&data_ov010_0222edc0,s32 *,16)==2){
if(M2C_FIELD(&data_ov010_0222d8b4,s32 *,60)&&M2C_FIELD(&data_ov010_0222d8b4,u8 *,64)==a)return (s32 *)&data_ov010_0222d8f0;
return 0;}
while(p){if(M2C_FIELD(p,s32 *,0)&&M2C_FIELD(p,u8 *,4)==a)return p;p=M2C_FIELD(p,void **,20);}return 0;
}

s32 func_ov010_02224974(void *a, M2C_UNK b) {
void func_ov010_02223ef0(void *);
extern M2C_UNK data_ov010_0222d8d8;
void *p,*q; s32 n,m;
if(M2C_FIELD(a,u8*,4)==255){
if(M2C_FIELD(a,u8*,6)==4)return func_ov010_02224cb8(a,(void*)b);
if(M2C_FIELD(a,u8*,6)==3)return 0;
}
p=func_ov010_022248f4(M2C_FIELD(a,u8*,8));
if(p){
n=func_ov010_02224748(p,a);
if(n!=-2){if(n==-1)return 0;}else{M2C_FIELD(b,s32*,0)=12;M2C_FIELD(p,s32*,0)=0;M2C_FIELD(b,void**,4)=p;return 1;
}
M2C_FIELD(b,s32*,0)=func_ov010_02224654(a,p);
M2C_FIELD(b,void**,4)=p;M2C_FIELD(p,s32*,12)=n;
return M2C_FIELD(b,s32*,0)!=0;
}
q=func_ov010_022243b0(M2C_FIELD(a,u8*,8));
if(!q){func_ov010_022245cc(&data_ov010_0222d8d8,M2C_FIELD(a,u8*,8));func_ov010_02224460(&data_ov010_0222d8d8,3);return 0;}
m=func_ov010_02224748(q,a);
if((u32)(m+2)<=1){func_ov010_02223ef0(q);return 0;}
M2C_FIELD(b,s32*,0)=func_ov010_02224654(a,q);M2C_FIELD(b,void**,4)=q;M2C_FIELD(q,s32*,12)=m;
return M2C_FIELD(b,s32*,0)!=0;
}

s32 func_ov010_02224ab0(void *arg0,M2C_UNK out) {
extern s32 data_ov010_0222d8b4,data_ov010_0222d8f0;
u64 func_02007004(void);
s32 n;u32 mask; u8 *p=arg0;
if(M2C_FIELD(&data_ov010_0222d8b4,s32 *,0x3c)==2){
if(M2C_FIELD(&data_ov010_0222d8b4,u8 *,0x40)==p[8]){
n=func_ov010_02224748(&data_ov010_0222d8f0,p);
switch(n){case -2:M2C_FIELD(out,s32 *,0)=12;M2C_FIELD(out,s32 *,4)=0;return 1;case -3:case -1:return 0;default:break;}
M2C_FIELD(out,s32 *,0)=func_ov010_02224654(p,(u8 *)&data_ov010_0222d8f0);
M2C_FIELD(out,void **,4)=&data_ov010_0222d8f0;
M2C_FIELD(&data_ov010_0222d8f0,s32 *,12)=n;
}else{func_ov010_0222458c(1);return 0;}
}else{
mask=p[8]?(1<<p[8]):1;
if(!(M2C_FIELD(&data_ov010_0222d8b4,u32 *,4)&mask))return 0;
M2C_FIELD(&data_ov010_0222d8b4,u8 *,0x40)=p[8];
M2C_FIELD(&data_ov010_0222d8b4,s32 *,0x3c)=2;
M2C_FIELD(&data_ov010_0222d8b4,s32 *,0x48)=0;
n=func_ov010_02224748(&data_ov010_0222d8f0,p);
switch(n){case -3:case -2:case -1:M2C_FIELD(&data_ov010_0222d8b4,s32 *,0x3c)=0;return 0;default:break;}
M2C_FIELD(out,s32 *,0)=func_ov010_02224654(p,(u8 *)&data_ov010_0222d8f0);
M2C_FIELD(out,void **,4)=&data_ov010_0222d8f0;
M2C_FIELD(&data_ov010_0222d8f0,s32 *,12)=n;
}
if(M2C_FIELD(out,s32 *,0)==10){func_ov010_0222458c(1);M2C_FIELD(&data_ov010_0222d8b4,u64 *,8)=func_02007004();}
else{func_ov010_0222458c(0);M2C_FIELD(&data_ov010_0222d8b4,u64 *,8)=0;}
return 1;
}

s32 func_ov010_02224c40(void *arg0, M2C_UNK arg1) {
void func_ov010_022245cc();extern M2C_UNK data_ov010_0222d8d8;
s32 *p;
if(M2C_FIELD(arg0,u8 *,4)==255 && M2C_FIELD(arg0,u8 *,6)==4)return 0;
p=func_ov010_022248f4(M2C_FIELD(arg0,u8 *,8));
if(p){M2C_FIELD(arg1,s32 *,0)=2;M2C_FIELD(arg1,s32 **,4)=p;*p=0;func_ov010_02224460(p,2);return 1;}
func_ov010_022245cc(&data_ov010_0222d8d8,M2C_FIELD(arg0,u8 *,8));func_ov010_02224460(&data_ov010_0222d8d8,2);return 0;
}

s32 func_ov010_02224cb8(void *p,void *out){
extern M2C_UNK data_ov010_0222edc0,data_ov010_0222d8b4,data_ov010_0222d8f0;
if(M2C_FIELD(&data_ov010_0222edc0,s32*,16)!=2)return 0;
if(M2C_FIELD(&data_ov010_0222edc0,u8*,1)!=M2C_FIELD(p,u8*,8))return 0;
switch(M2C_FIELD(p,u8*,10)){
case 0:
if(!M2C_FIELD(&data_ov010_0222d8b4,s32*,0x3c))return 0;
if(M2C_FIELD(&data_ov010_0222d8b4,s32*,0x48)==5||M2C_FIELD(&data_ov010_0222d8b4,s32*,0x48)==2)M2C_FIELD(out,s32*,0)=9;
else M2C_FIELD(out,s32*,0)=5;
M2C_FIELD(&data_ov010_0222d8b4,s32*,0x3c)=0;
M2C_FIELD(&data_ov010_0222d8b4,s32*,0x48)=0;
M2C_FIELD(out,void**,4)=&data_ov010_0222d8f0;
break;
case 1:
M2C_FIELD(&data_ov010_0222d8b4,s32*,0x3c)=2;
if(M2C_FIELD(p,u8*,11)==M2C_FIELD(&data_ov010_0222edc0,u8*,0)){
M2C_FIELD(&data_ov010_0222d8b4,s32*,0x48)=2;M2C_FIELD(out,s32*,0)=7;
M2C_FIELD(&data_ov010_0222d8b4,u32*,0x44)=M2C_FIELD(p,u32*,12);
}else{
M2C_FIELD(&data_ov010_0222d8b4,s32*,0x48)=3;M2C_FIELD(out,s32*,0)=6;
M2C_FIELD(&data_ov010_0222d8b4,u32*,0x44)=M2C_FIELD(p,u8*,11)?1<<M2C_FIELD(p,u8*,11):1;
}
M2C_FIELD(&data_ov010_0222d8b4,u8*,0x41)=M2C_FIELD(p,u8*,11);
M2C_FIELD(out,void**,4)=&data_ov010_0222d8f0;
break;
default:return 0;
}
return 1;
}

s32 func_ov010_02224dd8(void *p,u32 size) {
extern M2C_UNK data_ov010_0222d908;
void func_02007e98(s32,void *,u32);
u32 n=size/0x478; s32 i;
M2C_FIELD(&data_ov010_0222d908,void **,8)=p;
if(n<4 || n>0x48)return 0;
if(!p)return 0;
if((u32)p&31){M2C_FIELD(&data_ov010_0222d908,void **,8)=0;return 0;}
func_02007e98(0,p,size);
for(i=0;i<n-1;i++) {
void *base=M2C_FIELD(&data_ov010_0222d908,void **,8);
M2C_FIELD(base+i*0x478,void **,0)=base+(s16)(i+1)*0x478;
}
M2C_FIELD(M2C_FIELD(&data_ov010_0222d908,void **,8)+n*0x478,void **,-0x478)=0;
M2C_FIELD(&data_ov010_0222d908,void **,4)=M2C_FIELD(&data_ov010_0222d908,void **,8);
return 1;
}

void func_ov010_02224ea0(void) {
    extern M2C_UNK data_ov010_0222d908;
    M2C_FIELD(&data_ov010_0222d908, s32 *, 4) = 0;
    M2C_FIELD(&data_ov010_0222d908, s32 *, 8) = 0;
}

void *func_ov010_02224eb8(void) {
extern M2C_UNK data_ov010_0222d908;
s32 func_0200751c(void); void func_02007530(s32);
void *r=0; void *p;
M2C_FIELD(&data_ov010_0222d908,s32 *,0)=func_0200751c();
p=M2C_FIELD(&data_ov010_0222d908,void **,4);
if(p){r=p;M2C_FIELD(&data_ov010_0222d908,void **,4)=M2C_FIELD(p,void **,0);}
func_02007530(M2C_FIELD(&data_ov010_0222d908,s32 *,0));return r;
}

void func_ov010_02224ef8(void *p){extern M2C_UNK data_ov010_0222d908;s32 func_0200751c(void);void func_02007530(s32);M2C_FIELD(&data_ov010_0222d908,s32 *,0)=func_0200751c();M2C_FIELD(p,void **,0)=M2C_FIELD(&data_ov010_0222d908,void **,4);M2C_FIELD(&data_ov010_0222d908,void **,4)=p;func_02007530(M2C_FIELD(&data_ov010_0222d908,s32 *,0));}

void func_ov010_02224f28(void){extern M2C_UNK data_ov010_0222c02c;s32 i;for(i=0;i<4;i++)data_ov010_0222d920[i]=0x1000000;((volatile s32 *)data_ov010_0222d914)[1]=0;data_ov010_0222d914[0]=0;M2C_FIELD(&data_ov010_0222c02c,s32 *,0)=0;M2C_FIELD(&data_ov010_0222c02c,s32 *,4)=0;data_ov010_0222d914[2]=0;}

void func_ov010_02224f74(s32 arg0) {
    M2C_UNK func_02008048(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_ov010_0222c02c;
    if (arg0 == 0) {
        return;
    }
    func_02008048(&data_ov010_0222c02c, arg0, 0x10);
}

