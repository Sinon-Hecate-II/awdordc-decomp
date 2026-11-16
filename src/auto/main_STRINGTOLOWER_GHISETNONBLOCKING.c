/* 53 functions from 0x02048B74 to 0x02049AB8 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 bytes[8]; } UnkSocketAddress;

/* GameSpy hashtable.c TableNew2: allocates a table of nBuckets bucket vectors
   (each an empty vector of elemSize-byte elements) and stores the caller's hash
   and comparison callbacks.  Table layout: +0x00 buckets, +0x04 count,
   +0x08 userData, +0x0C hashFn, +0x10 compFn. */

#pragma push
#pragma optimization_level 2
#pragma opt_if_conversion off

#pragma pop

/* Polls a single fd for readability/priority/error; sets output flags accordingly. */

s32 ghiSetNonBlocking(M2C_UNK arg0, s32 arg1) {
    s32 func_020219e8(M2C_UNK, M2C_UNK, s32);
    s32 temp_r0;
    s32 var_r2;

    temp_r0 = func_020219e8(arg0, 3, 0);
    if (arg1 != 0) {
        var_r2 = temp_r0 & ~4;
    } else {
        var_r2 = temp_r0 | 4;
    }
    if (func_020219e8(arg0, 4, var_r2) == 0) {
        return 1;
    }
    return 0;
}

s32 ghiSetRecvBufferSize(s32 a,s32 b,...) {
void func_020498a4(void);
void *ap = &b;
return ((s32 (*)(s32,s32,s32,void *,s32))func_020498a4)(a,65535,4098,ap,4)!=-1;
}

s32 func_02049370(s32 a,s32 b,...) {
void func_020498a4(void);
void *ap = &b;
return ((s32 (*)(s32,s32,s32,void *,s32))func_020498a4)(a,65535,4097,ap,4)!=-1;
}

s32 func_020493b0(int a){s32 func_0204987c(int,int,int,int,s32 *);s32 value; s32 size=4;if(func_0204987c(a,0xffff,0x1002,(int)&value,&size)==-1)return -1;return value;}

s32 func_020493f8(int a){s32 func_0204987c(int,int,int,int,s32 *);s32 value; s32 size=4;if(func_0204987c(a,0xffff,0x1001,(int)&value,&size)==-1)return -1;return value;}

s32 PollOneFd(s32 fd, s32 *readable, s32 pri, s32 err) {
    s32 func_02021d34(void *, u32, s64);
    PollFd p;
    s32 r;

    p.events = 0;
    p.fd = fd;
    if (readable) p.events |= 1;
    if (pri) p.events |= 8;
    p.revents = 0;
    r = func_02021d34(&p, 1, 0);
    if (r < 0) return -1;
    if (readable) {
        if (r > 0 && (p.revents & 0x41)) *readable = 1;
        else *readable = 0;
    }
    if (pri) {
        if (r > 0 && (p.revents & 8)) *(s32 *)pri = 1;
        else *(s32 *)pri = 0;
    }
    if (err) {
        if (r > 0 && (p.revents & 0x20)) *(s32 *)err = 1;
        else *(s32 *)err = 0;
    }
    return r;
}

s32 func_02049534(M2C_UNK arg0) {
    s32 PollOneFd(M2C_UNK, s32 *, M2C_UNK, M2C_UNK);
    s32 sp0;

    sp0 = 0;
    if (PollOneFd(arg0, &sp0, 0, 0) == 1) {
        return sp0;
    }
    return 0;
}

s32 func_0204955c(M2C_UNK arg0) {
    s32 sp0;

    sp0 = 0;
    if (PollOneFd(arg0, 0, &sp0, 0) == 1) {
        return sp0;
    }
    return 0;
}

void *func_02049584(void){extern M2C_UNK data_0213dc60;extern M2C_UNK data_020fce1c,data_0213dc8c,data_0213dc78,data_0213dc68;
M2C_FIELD(&data_0213dc60,void **,8)=&data_020fce1c;
M2C_FIELD(&data_0213dc60,void **,12)=(void *)0x0213dc60;
M2C_FIELD(&data_0213dc60,u16 *,16)=2;
M2C_FIELD(&data_0213dc60,u16 *,18)=0;
M2C_FIELD(&data_0213dc60,void **,20)=&data_0213dc8c;
M2C_FIELD(&data_0213dc60,s32 *,24)=0;
func_02021d14(func_02021264(&data_0213dc60),&data_0213dc78);
if(!M2C_FIELD(&data_0213dc60,s32 *,24))return 0;
M2C_FIELD(&data_0213dc60,void **,44)=&data_0213dc78;
M2C_FIELD(&data_0213dc60,u16 *,18)=4;
M2C_FIELD(&data_0213dc60,s32 *,48)=0;
return &data_0213dc68;}

s32 func_02049610(u32 *a){u32 x=*a;u32 y=((x<<24)&0xff000000)|(((x<<8)&0xff0000)|(((x>>24)&0xff)|((x>>8)&0xff00)));int first=(y>>24)&255;int second=(y>>16)&255;if(first==10)return 1;if(first==172 && second>=16 && second<=31)return 1;if(first==192 && second==168)return 1;return 0;}

s32 func_0204968c(s32 a, s32 b) { extern M2C_UNK data_0213dc60; if(a<0){M2C_FIELD(&data_0213dc60,s32 *,4)=a;a=b;} return a; }

void ghiSocket(void) {
    s32 func_02021500();
    M2C_UNK func_0204968c(s32, M2C_UNK);
    func_0204968c(func_02021500(), -1);
}

void func_020496b8(void) {
    s32 func_0202175c();
    func_0204968c(func_0202175c(), -1);
}

void func_020496cc(void) {
    s32 func_02021750();
    func_0204968c(func_02021750(), -1);
}

s32 func_020496e0(int a,UnkSocketAddress *b,u8 c){s32 func_0202152c(int,UnkSocketAddress *);UnkSocketAddress addr;if(*(u16 *)(b->bytes+2)==0)return 0;addr=*b;addr.bytes[0]=c;return func_0204968c(func_0202152c(a,&addr),-1);}

s32 ghiConnect(int a,UnkSocketAddress *b,u8 c){s32 func_02021558(int,UnkSocketAddress *);UnkSocketAddress addr=*b;addr.bytes[0]=c;return func_0204968c(func_02021558(a,&addr),-1);}

void func_0204978c(void) {
    s32 func_02021960();
    func_0204968c(func_02021960(), -1);
}

void func_020497a0(M2C_UNK arg0, u8 *arg1, s32 *arg2) {
    s32 func_0202196c(M2C_UNK);
    M2C_UNK func_0204968c(s32, M2C_UNK);
    s32 temp_r0;

    *arg1 = (u8) *arg2;
    temp_r0 = func_0202196c(arg0);
    *arg2 = (s32) *arg1;
    func_0204968c(temp_r0, -1);
}

void ghiRecv(void) {
    s32 func_020215d4();
    func_0204968c(func_020215d4(), -1);
}

void func_020497e0(int a,int b,int c,int d,u8 *e,s32 *f){s32 func_020215f8(int,int,int,int,u8 *);s32 r;*e=*f;r=func_020215f8(a,b,c,d,e);*f=*e;func_0204968c(r,-1);}

void func_02049810(void) {
    s32 func_020216a8();
    M2C_UNK func_0204968c(s32, M2C_UNK);
    func_0204968c(func_020216a8(), -1);
}

s32 func_02049824(int a,int b,int c,int d,UnkSocketAddress *e,int f) {
s32 func_020216cc(int,int,int,int,UnkSocketAddress *);
UnkSocketAddress addr; addr=*(UnkSocketAddress const *)e;
addr.bytes[0]=f;
return func_0204968c(func_020216cc(a,b,c,d,&addr),-1);
}

s32 func_0204987c(s32 a,s32 b,s32 c,s32 d,s32 *e) {
M2C_UNK MI_CpuFill8(s32,s32,s32);
MI_CpuFill8(d,0,*e);return func_0204968c(0,-1);
}

void func_020498a4(void) {
    func_0204968c(0, -1);
}

void func_020498b8(M2C_UNK arg0, u8 *arg1, s32 *arg2) {
    s32 func_02021828(M2C_UNK);
    M2C_UNK func_0204968c(s32, M2C_UNK);
    s32 temp_r0;

    *arg1 = (u8) *arg2;
    temp_r0 = func_02021828(arg0);
    *arg2 = (s32) *arg1;
    func_0204968c(temp_r0, -1);
}

s32 func_020498e4(M2C_UNK arg0) {
    s32 func_02021c40(M2C_UNK, s32 *);
    s32 sp0;

    if (func_02021c40(arg0, &sp0) == 0) {
        return -1;
    }
    return sp0;
}

s32 ghiGetLastSocketError(void) {
    extern M2C_UNK data_0213dc60;
    return M2C_FIELD(&data_0213dc60, s32 *, 4);
}

void gpiGetTime(int *out) {
int func_02006f8c(void); unsigned long long GetSystemTick(void);
unsigned long long func_02072088(unsigned long long, unsigned long long);
extern char data_020fcdf0[],data_020fce10[],data_020fcdd8[];
unsigned int v;
if(func_02006f8c()!=1)AssertFailed(data_020fcdf0,data_020fce10,data_020fcdd8,0x667);
v=func_02072088(GetSystemTick()<<6,0x1ff6210);
if(out)*out=v;
}

s32 func_02049974(s32 x) {
u32 lo=(u32)x<<16;
u32 hi=(u32)x>>16;
u32 a=hi*16807;
u32 v=(lo>>16)*16807+((a<<17)>>1);
if(v>0x7fffffffU)v=(v&0x7fffffffU)+1;
v+=a>>15;
if(v>0x7fffffffU)v=(v&0x7fffffffU)+1;
return v;
}

s32 func_020499c0(void) { extern s32 data_020fcdd4; s32 func_02049974(s32); return data_020fcdd4=func_02049974(data_020fcdd4); }

void SeedRandom(s32 arg0) {
    extern s32 data_020fcdd4;

    data_020fcdd4 = arg0 ? (arg0 & ~0x80000000) : 1;
}

s32 RandomRange(s32 a,s32 b){s32 n=b-a;s32 result;if(n==0)return a;result=func_020499c0();result%=n;return result+a;}

void Base64PackGroup(signed char *src,unsigned char *dst,int n) {
unsigned char b[3]; int i;
for(i=0;i<n;i++)b[i]=src[i];
for(;i<3;i++)b[i]=0;
dst[0]=b[0]>>2;
dst[1]=((b[0]&3)<<4)|(b[1]>>4);
dst[2]=((b[1]&15)<<2)|(b[2]>>6);
dst[3]=b[2]&63;
}
