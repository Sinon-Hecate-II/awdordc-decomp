/* 13 functions from 0x02062770 to 0x02063704 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_0210019c, data_0210012c;
extern u8 data_021000b4[16];
typedef struct { u8 lo, hi; } PairBytes;

void func_02062770(void *a,s8 *b,s32 n) {
s32 func_02068c34(void *);
void func_0205fed8(void *,void *,s32);
s32 i;
s32 size;
s8 *p;
size=func_02068c34((u8 *)a+0x54);
p=(s8 *)a+0x54;
for(i=0;i<n;i++){
s32 x=p[i%size];
s32 j=(i*x)%8;
s8 value=M2C_FIELD((s8 *)a+i%8,s8 *,0x74)^b[i];
M2C_FIELD((s8 *)a+j,s8 *,0x74)^=value;
}
func_0205fed8((u8 *)a+0x4bc,(u8 *)a+0x74,8);
}

s32 func_02062810(u8 a) {
s32 n=5;
if(a&2)n+=4;
if(a&8)n+=4;
if(a&16)n+=2;
if(a&32)n+=2;
return n;
}

s32 func_0206283c(void *arg,s32 n) {
s8 *p=arg;
s32 func_02061da0(s8 *,s32);
while(n>0 && *p){
s32 k=func_02061da0(p,n);
if(k<0)return 0;
n-=k;p+=k;
k=func_02061da0(p,n);
if(k<0)return 0;
p+=k;n-=k;
}
if(n==0)return 0;
return *p==0;
}

/* Walks a list of opcodes, advancing data/n as commands require; returns 1 on success. */
s32 func_020628c0(M2C_UNK context, void *data, s32 n) {
 s32 func_02048688(s32); void *func_02048690(s32,s32); s32 func_02061da0(s8*,s32); void func_020640a8(void*,void*,void*,s32);
 s32 count, i, k; u8 *p = data;
 count = func_02048688(M2C_FIELD(context, s32 *, 8));
 for (i = 0; i < count; i++) {
 switch (M2C_FIELD(func_02048690(M2C_FIELD(context, s32 *, 8), i), s32 *, 4)) {
 case 1: p++; n--; break;
 case 2: p += 2; n -= 2; break;
 case 0:
 if (n < 1) return 0;
 k = *p++; n--;
 if (k == 255) {
 k = func_02061da0((s8 *) p, n);
 if (k == -1) return 0;
 p += k; n -= k;
 }
 break;
 default: func_020640a8(&data_0210019c, &data_0210012c, data_021000b4, 0x317); return 0;
 }
 if (n < 0) return 0;
 }
 return 1;
}

void func_020629bc(M2C_UNK a,u8 *b,s32 n,s32 *d,u16 *out) {
u8 flag;
if(n<5)return;
flag=b[0];
*(PairBytes *)d=*(PairBytes *)(b+1);
*((PairBytes *)d+1)=*(PairBytes *)(b+3);
if(flag&16){
if(n-5<2)return;
*(PairBytes *)out=*(PairBytes *)(b+5);
}else *out=M2C_FIELD(a,u16 *,0x4a8);
}

/* Validates an encoded data block and, if valid, decodes it. */
s32 func_02062cf8(M2C_UNK context, u8 *data, s32 size) {
    s32 func_02061090(M2C_UNK, s32, u16);
    s32 func_02061168();
    M2C_UNK func_02061a38(M2C_UNK, s32);
    s32 func_02062810(u8);
    s32 func_0206283c(void *, s32);
    s32 func_020628c0(M2C_UNK, void *, s32);

    s32 func_02062a2c(M2C_UNK, s32, u8 *, s32, s32);
    s32 func_0206527c(void *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021001a0;
    s32 sp8;
    u16 sp4;
    s32 headerLen;
    s32 result;
    s32 handle;
    u8 flags;

    if (size < 1) {
        return 0;
    }
    flags = *data;
    headerLen = func_02062810(flags);
    if (size < headerLen) {
        return 0;
    }
    if ((flags & 0x40) && (func_020628c0(context, data + headerLen, size - headerLen) == 0)) {
        return 0;
    }
    if ((flags & 0x80) && (func_0206283c(data + headerLen, size - headerLen) == 0)) {
        return 0;
    }
    if (func_0206527c(data + 1, &data_021001a0, 4) == 0) {
        return -1;
    }
    func_020629bc(context, data, size, &sp8, &sp4);
    handle = func_02061090(context, sp8, sp4);
    if (func_02061168() != 0) {
        return -2;
    }
    result = func_02062a2c(context, handle, data, size, 1);
    func_02061a38(context, handle);
    return result;
}

void func_02062e28(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x4AC) = arg1;
}

s32 func_0206325c(void *a,u8 *p,s32 n) {
 s32 func_02048558(s32,s32,s32); void func_020486f8(s32,s32*); s32 func_02061cb4(void*,void*); s32 func_02061da0(s8*,s32); void func_02062670(void*);
 s32 entry[2]; s32 i,count,len;
 n--;count=*p++;
 if(M2C_FIELD(a,s32*,8))func_02062670(a);
 M2C_FIELD(a,s32*,8)=func_02048558(8,count,0);
 if(!M2C_FIELD(a,s32*,8))return 5;
 for(i=0;i<count;i++){
 if(n<2)return 4;
 len=func_02061da0((s8*)p+1,n-1);
 if(len==-1)return 4;
 entry[1]=*p;entry[0]=func_02061cb4(a,p+1);
 func_020486f8(M2C_FIELD(a,s32*,8),entry);
 p+=len+1;n-=len+1;
 }
 return 0;
}

s32 func_02063678(M2C_UNK arg0, u8 *arg1, s32 arg2) {
    s32 func_02061ac8(M2C_UNK, s32, u16);
    M2C_UNK func_02061b6c(M2C_UNK);
    s32 sp4;
    u16 sp0;

    if (arg2 < 6) {
        return 4;
    }
    *(volatile u8 *)((u8 *)&sp4 + 0) = arg1[0];
    *(volatile u8 *)((u8 *)&sp4 + 1) = arg1[1];
    *(volatile u8 *)((u8 *)&sp4 + 2) = arg1[2];
    *(volatile u8 *)((u8 *)&sp4 + 3) = arg1[3];
    *(volatile u8 *)((u8 *)&sp0 + 0) = arg1[4];
    *(volatile u8 *)((u8 *)&sp0 + 1) = arg1[5];
    if (func_02061ac8(arg0, sp4, sp0) == -1) {
        return 0;
    }
    func_02061b6c(arg0);
    return 0;
}

