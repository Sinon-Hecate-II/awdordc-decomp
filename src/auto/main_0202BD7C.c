/* 43 functions from 0x0202BD7C to 0x0202CD78 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 id:24; u32 flags:8; } Unk0202PackedId;

void func_0202bf54(void *arg0,s32 arg1){extern s32 data_0213c250;u32 i; s32 off;void *p;
func_02007e70(arg1,arg0,0x30);
off=M2C_FIELD(arg0,s32 *,0x18);M2C_FIELD(arg0,s32 *,0x8c)=off==0?0:arg1+off;
off=M2C_FIELD(arg0,s32 *,0x20);M2C_FIELD(arg0,s32 *,0x84)=off==0?0:arg1+off;
off=M2C_FIELD(arg0,s32 *,0x10);M2C_FIELD(arg0,s32 *,0x88)=off==0?0:arg1+off;
for(i=0;i<M2C_FIELD(M2C_FIELD(arg0,void **,0x84),u32 *,8);i++){p=M2C_FIELD(arg0,void **,0x84)+12+i*16;off=M2C_FIELD(p,s32 *,0);M2C_FIELD(p,s32 *,8)=off==0?0:arg1+off;}
M2C_FIELD(arg0,s32 *,0x30)=0;data_0213c250=(s32)arg0;}

s32 func_0202c014(s32 arg0){extern s32 data_0213c250;s32 old=data_0213c250;data_0213c250=arg0;return old;}

s32 func_0202c02c(void) {
    extern s32 data_0213c250;
    return data_0213c250;
}

void *func_0202c03c(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,8);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c0a0(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0xc);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c104(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x10);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c168(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x14);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c1cc(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x24);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c230(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x18);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c294(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x20);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

void *func_0202c2f8(s32 arg0){extern s32 data_0213c250;void *root=(void *)data_0213c250;void *base,*p; s32 off;base=M2C_FIELD(root,void **,0x8c);off=M2C_FIELD(base,s32 *,0x1c);p=off==0?0:base+off;if(!p)return 0;if(arg0<0)return 0;if((u32)arg0>=M2C_FIELD(p,u32 *,0))return 0;off=M2C_FIELD(p+arg0*4,s32 *,0x4);base=M2C_FIELD(root,void * volatile *,0x8c);return off==0?0:base+off;}

s32 func_0202c35c(u32 a){extern s32 data_0213c250;void *p=M2C_FIELD(data_0213c250,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,12);}

s32 func_0202c384(u32 a){extern s32 data_0213c250;void *p=M2C_FIELD(data_0213c250,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,16);}

s32 func_0202c3ac(u32 a,void *b,u32 n,u32 off) {
extern s32 data_0213c250;s32 func_0200bbf0(void *,u32,s32);s32 func_0200bbe0(void *,void *,u32);
void *root=(void *)data_0213c250;void *p=M2C_FIELD(root,void **,0x84);
if(a>=M2C_FIELD(p,u32 *,8))return -1;
p=p+12+a*16;
if(n>M2C_FIELD(p,u32 *,4)-off)n=M2C_FIELD(p,u32 *,4)-off;
if(!func_0200bbf0(root+52,M2C_FIELD(p,u32 *,0)+off,0))return -1;
return func_0200bbe0(root+52,b,n);
}

void func_0202c424(volatile u32 *p) {extern s32 data_0213c250;u32 a=M2C_FIELD(data_0213c250,volatile u32 *,0x7c),b=M2C_FIELD(data_0213c250,volatile u32 *,0x80);p[0]=a;p[1]=b;}

s32 func_0202c444(u32 a) {extern s32 data_0213c250;void *p=M2C_FIELD(data_0213c250,void **,0x84);if(a>=M2C_FIELD(p,u32 *,8))return 0;return M2C_FIELD(p+a*16,s32 *,20);}

s32 func_0202c46c(s32 a,s32 b) {extern s32 data_0213c250;void *p=M2C_FIELD(data_0213c250,void **,0x84)+a*16;M2C_FIELD(p,s32 *,20)=b;return (s32)p;}

void func_0202c488(M2C_UNK arg0, M2C_UNK arg1, void *arg2) {
    M2C_FIELD(arg2, s32 *, 0x8C) = 0;
}

void func_0202c494(s32 a,s32 b,void *p) {M2C_FIELD(p,s32 *,0x84)=0;}

void func_0202c4a0(s32 a,s32 b,void *p){M2C_FIELD(p,s32 *,0x88)=0;}

u32 func_0202c4ac(s32 arg0, s32 arg1) {
    s32 func_0202a638(s32, s32, M2C_UNK);
    s32 func_0202c7b8(u32, s32);
    s32 temp_r0_2;
    u32 temp_r0;
    u32 temp_r1;
    u32 temp_r5;

    temp_r0 = arg0 + arg1;
    temp_r5 = (arg0 + 3) & ~3;
    if (temp_r5 > temp_r0) {
        return 0U;
    }
    temp_r1 = temp_r0 - temp_r5;
    if (temp_r1 < 0x10U) {
        return 0U;
    }
    temp_r0_2 = func_0202a638(temp_r5 + 0x10, temp_r1 - 0x10, 0);
    if (temp_r0_2 == 0) {
        return 0U;
    }
    if (func_0202c7b8(temp_r5, temp_r0_2) != 0) {
        return temp_r5;
    }
    func_0202a670(temp_r0_2);
    return 0U;
}

void func_0202c51c(s32 *arg0) {
    M2C_UNK func_0202a670(s32);
    M2C_UNK func_0202c534();
    func_0202c534();
    func_0202a670(*arg0);
}

s32 func_0202c534(void *p){
s32 func_02029df4(void *,M2C_UNK);void func_02029d7c(void *,void *);void func_0202a6b0(s32,s32);void func_0202c828(void);s32 func_0202c7ec(void *);
void *a;s32 changed=0;void *b;
a=(void *)func_02029df4(p+4,0);
while(a){
b=(void *)func_02029df4(a,0);
while(b){
if(M2C_FIELD(b,void (**)(void *,s32,s32,s32),12)){
M2C_FIELD(b,void (**)(void *,s32,s32,s32),12)(b+32,M2C_FIELD(b,s32 *,8),M2C_FIELD(b,s32 *,16),M2C_FIELD(b,s32 *,20));changed=1;
}
b=(void *)func_02029df4(a,(s32)b);
}
func_02029d7c(p+4,a);a=(void *)func_02029df4(p+4,0);
}
func_0202a6b0(M2C_FIELD(p,s32 *,0),3);if(changed)func_0202c828();return func_0202c7ec(p);
}

void *func_0202c5f0(s32 *arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4){
s32 func_02029df4(void *,M2C_UNK);M2C_UNK func_02029c74(s32,void *);void *func_0202a67c(s32,s32,M2C_UNK);register unsigned int temp_r0_2;void *temp_r0;
temp_r0=func_0202a67c(*arg0,((arg1+31)&~31)+32,32);if(!temp_r0)return 0;
temp_r0_2=func_02029df4(arg0+1,0);M2C_FIELD(temp_r0,s32 *,8)=arg1;M2C_FIELD(temp_r0,s32 *,12)=arg2;M2C_FIELD((u32)temp_r0,s32 *,16)=arg3;M2C_FIELD(temp_r0,s32 *,20)=arg4;func_02029c74(temp_r0_2,temp_r0);return temp_r0+32;
}

s32 func_0202c658(void *arg0) {
    s32 func_0202a714(s32, u16);
    M2C_UNK func_0202a764(s32, M2C_UNK);
    s32 func_0202c7ec(void *);
    if (func_0202a714(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 0xC)) == 0) {
        return -1;
    }
    if (func_0202c7ec(arg0) != 0) {
        return M2C_FIELD(arg0, u16 *, 0xC) - 1;
    }
    func_0202a764(M2C_FIELD(arg0, s32 *, 0), 0);
    return -1;
}

void func_0202c6a4(void *p, s32 count) {
    s32 func_02029df4(void *, M2C_UNK);
    void func_02029d7c(void *, void *);
    s32 func_0202a764(s32, s32);
    s32 func_0202a714(s32, u16);
    void func_0202c828(void);
    s32 func_0202c7ec(void *);
    s32 func_0202c534(void *);
    void *a;
    s32 changed;
    void *b;

    b = 0;
    changed = 0;
    if (count == 0) {
        func_0202c534(p);
        return;
    }
    while (count < M2C_FIELD(p, u16 *, 12)) {
        a = (void *)func_02029df4(p + 4, 0);
        b = (void *)func_02029df4(a, (s32)b);
        while (b) {
            if (M2C_FIELD(b, void (**)(void *, s32, s32, s32), 12)) {
                M2C_FIELD(b, void (**)(void *, s32, s32, s32), 12)(b + 32, M2C_FIELD(b, s32 *, 8), M2C_FIELD(b, s32 *, 16), M2C_FIELD(b, s32 *, 20));
                changed = 1;
            }
            b = (void *)func_02029df4(a, (s32)b);
        }
        func_02029d7c(p + 4, a);
    }
    func_0202a764(M2C_FIELD(p, s32 *, 0), count);
    if (changed) {
        func_0202c828();
    }
    func_0202a714(M2C_FIELD(p, s32 *, 0), M2C_FIELD(p, u16 *, 12));
    func_0202c7ec(p);
}

s32 func_0202c778(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 0xC) - 1;
}

s32 func_0202c784(s32 *arg0) {
    u32 func_0202a6dc(s32, M2C_UNK);
    u32 temp_r0;

    temp_r0 = func_0202a6dc(*arg0, 0x20);
    if (temp_r0 < 0x20U) {
        return 0;
    }
    return (temp_r0 - 0x20) & ~0x1F;
}

void func_0202c7a8(M2C_UNK arg0) {
    M2C_UNK func_02029c30(M2C_UNK, M2C_UNK);
    func_02029c30(arg0, 0);
}

s32 func_0202c7b8(u32 p,s32 a){s32 func_0202c7ec(void *);func_02029c30(p+4,12);M2C_FIELD(p,s32 *,0)=a;return func_0202c7ec(p)!=0;}

s32 func_0202c7ec(void *p){
void *func_0202a67c(s32,s32,M2C_UNK);void func_0202c7a8(s32);M2C_UNK func_02029c74(s32,void *);
void *q=func_0202a67c(M2C_FIELD(p,s32 *,0),20,4);if(!q)return 0;func_0202c7a8((s32)q);func_02029c74((s32)(p+4),q);return 1;
}

void func_0202c828(void) {
    M2C_UNK func_020092d0(M2C_UNK);
    M2C_UNK func_0200948c(s32);
    s32 func_020094f8();
    s32 temp_r4;

    temp_r4 = func_020094f8();
    func_020092d0(1);
    func_0200948c(temp_r4);
}

s32 func_0202c848(void) {
    s32 func_0202c8b8();
    if (func_0202c8b8() == 0) {
        return 1;
    }
    return 0;
}

s32 func_0202c860(M2C_UNK arg0,M2C_UNK arg1){s32 func_0202ca40(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);if(func_0202ca40(arg0,255,arg1,1,0)==0)return 1;return 0;}

s32 func_0202c88c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_0202caa0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    if (func_0202caa0(arg0, 0xFF, arg1, 1, 0) == 0) {
        return 1;
    }
    return 0;
}

s32 func_0202c8b8(s32 arg0,s32 arg1) {
void *base=func_0202c2f8(arg0);u32 i;void *p;s32 r;
if(!base)return 1;
i=0;
if(i<M2C_FIELD(base,u32 *,0)){
p=base+4;
do{
switch(M2C_FIELD(p,u8 *,0)){
case 0:r=func_0202c9bc(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,u8 *,1),arg1,1,0);if(r)return r;break;
case 3:r=func_0202ca40(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,u8 *,1),arg1,1,0);if(r)return r;break;
case 1:r=func_0202caa0(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,u8 *,1),arg1,1,0);if(r)return r;break;
case 2:r=func_0202cbe0(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,u8 *,1),arg1,1,0);if(r)return r;break;
}
i++;p+=8;
}while(i<M2C_FIELD(base,u32 *,0));
}
return 0;
}

s32 func_0202c9bc(s32 a,s32 flags,s32 b,s32 c,s32 *out) {
s32 func_0202caa0(s32,s32,s32,s32,s32);
void *p=func_0202c03c(a);s32 r;
if(!p)return 2;
r=func_0202caa0(M2C_FIELD(p,u16 *,4),flags,b,c,0);if(r)return r;
a=M2C_FIELD(p,s32 *,0);
if(flags&1){r=func_0202cd0c(a,b,c);if(!r)return 6;}else r=func_0202c444(a);
if(out)*out=r;return 0;
}

s32 func_0202ca40(s32 a,s32 flags,s32 b,s32 c,s32 out) {
s32 func_0202cd78(s32,s32,s32);
void *p=func_0202c0a0(a);s32 r;
if(!p)return 3;
a=M2C_FIELD(p,s32 *,0);
if(flags&8){r=func_0202cd78(a,b,c);if(!r)return 7;}else r=func_0202c444(a);
if(out)*(s32 *)out=r;return 0;
}

s32 func_0202caa0(s32 a,s32 flags,s32 b,s32 c,s32 out) {
s32 func_0202cde4(s32,s32,s32);s32 func_0202d1d4(s32,s32,s32,s32,s32);
void *p;void *q;s32 object;s32 i;s32 bit;s32 result;s32 child;
p=func_0202c104(a);if(!p)return 4;
if(flags&2){object=func_0202cde4(M2C_FIELD(p,s32 *,0),b,c);if(!object)return 8;}
else object=func_0202c444(M2C_FIELD(p,u32 *,0));
bit=flags&4;
for(i=0;i<4;i++){
if(((u16 *)p)[i+2]==65535)continue;
q=func_0202c168(((u16 *)p)[i+2]);if(!q)return 5;
result=func_0202cbe0(((u16 *)p)[i+2],flags,b,c,&child);if(result)return result;
if(((Unk0202PackedId *)q)->flags&1 && bit){
if(!func_0202d1d4(child,object,i,((Unk0202PackedId *)q)->id,b))return 9;
}
if(object&&child)func_02009940(object,i,child);
}
if(out)*(s32 *)out=object;
return 0;
}

s32 func_0202cbe0(s32 a,s32 flags,s32 b,s32 c,s32 *out) {
s32 func_0202ce50(u32,s32,s32);s32 func_0202cebc(u32,s32,s32);
Unk0202PackedId *p=func_0202c168(a);s32 r;
if(!p)return 5;
if(flags&4){if(p->flags&1)r=func_0202cebc(p->id,b,c);else r=func_0202ce50(p->id,b,c);if(!r)return 9;}else r=func_0202c444(p->id);
if(out)*out=r;return 0;
}

s32 func_0202cc6c(s32 a,M2C_UNK *b,s32 c,s32 d,s32 pool) {
void func_020067c4(void *,s32);
s32 n=func_0202c384(a);void *p;
if(!n)return 0;if(!pool)return 0;
p=func_0202c5f0((s32 *)pool,n+32,(s32)b,c,d);if(!p)return 0;
if(n!=func_0202c3ac(a,p,n,0))return 0;
func_020067c4(p,n);return (s32)p;
}

s32 func_0202cd0c(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 func_0202c444();
    M2C_UNK func_0202c46c(M2C_UNK, s32);
    s32 func_0202cc6c(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d01c;
    s32 var_r2;
    s32 var_r4;

    var_r4 = func_0202c444();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = func_0202c02c();
        }
        var_r4 = func_0202cc6c(arg0, &func_0202d01c, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            func_0202c46c(arg0, var_r4);
        }
    }
    return var_r4;
}

