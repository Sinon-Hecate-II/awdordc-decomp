/* 53 functions from 0x02048B74 to 0x02049AB8 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 bytes[8]; } UnkSocketAddress;

void func_02048b74(M2C_UNK arg0) {
    s32 func_02048688();
    M2C_UNK func_0204890c(M2C_UNK, s32);
    s32 var_r4;

    var_r4 = func_02048688() - 1;
    if (var_r4 < 0) {
        return;
    }
    do {
        func_0204890c(arg0, var_r4);
        var_r4 -= 1;
    } while (var_r4 >= 0);
}

s32 func_02048ba0(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 (*arg4)(M2C_UNK, s32)) {
    s32 var_r4;
    s32 var_r5;

    var_r4 = 0;
    if (arg2 > 0) {
        var_r5 = 0;
        do {
            if (arg4(arg0, arg1 + var_r5) == 0) {
                return arg3 * var_r4 + arg1;
            }
            var_r4 += 1;
            var_r5 += arg3;
        } while (var_r4 < arg2);
    }
    return 0;
}

s32 func_02048bf8(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 (*arg4)(s32, M2C_UNK), s32 *arg5) {
    s32 var_r4;
    s32 var_r5;
    s32 temp_r6;
    s32 temp_r0;

    var_r4 = 0;
    *arg5 = 0;
    var_r5 = arg2 - 1;
    if (var_r5 >= 0) {
        do {
            temp_r6 = (s32) (var_r4 + var_r5) >> 1;
            temp_r0 = arg4(temp_r6 * arg3 + arg1, arg0);
            if (temp_r0 == 0) {
                *arg5 = 1;
            }
            if (temp_r0 < 0) {
                var_r4 = temp_r6 + 1;
            } else {
                var_r5 = temp_r6 - 1;
            }
        } while (var_r4 <= var_r5);
    }
    return var_r4 * arg3 + arg1;
}

void func_02048c5c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_02048c84(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_02048c84(arg0, arg1, 4, arg2, arg3, arg4);
}

M2C_UNK func_02048c84(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, M2C_UNK arg5) {
    extern M2C_UNK data_020fcd7c, data_020fcd84, data_020fcd14, data_020fcd90, data_020fcd98, data_020fcda4, data_020fcdb0, data_020fcdb8;
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK func_02037794(s32);
    M2C_UNK func_02048558(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK var_r4;
    s32 i;
    if (arg3 == 0) func_020640a8(&data_020fcd7c, &data_020fcd84, &data_020fcd14, 0x38);
    if (arg4 == 0) func_020640a8(&data_020fcd90, &data_020fcd84, &data_020fcd14, 0x39);
    if (arg0 == 0) func_020640a8(&data_020fcd98, &data_020fcd84, &data_020fcd14, 0x3a);
    if (arg1 == 0) func_020640a8(&data_020fcda4, &data_020fcd84, &data_020fcd14, 0x3b);
    var_r4 = func_02037794(0x14);
    if (var_r4 == 0) func_020640a8(&data_020fcdb0, &data_020fcd84, &data_020fcd14, 0x3e);
    M2C_FIELD(var_r4, M2C_UNK **, 0) = (M2C_UNK *)func_02037794((s32)arg1 * 4);
    if (M2C_FIELD(var_r4, M2C_UNK **, 0) == 0) func_020640a8(&data_020fcdb8, &data_020fcd84, &data_020fcd14, 0x41);
    i = 0;
    if ((s32)arg1 <= 0) goto done;
    do {
        M2C_FIELD(var_r4, M2C_UNK **, 0)[i] = func_02048558(arg0, arg2, arg5);
        i++;
    } while (i < (s32)arg1);
done:
    M2C_FIELD(var_r4, s32 *, 4) = (s32)arg1;
    M2C_FIELD(var_r4, M2C_UNK *, 8) = arg5;
    M2C_FIELD(var_r4, M2C_UNK *, 0x10) = arg4;
    M2C_FIELD(var_r4, M2C_UNK *, 0xc) = arg3;
    return var_r4;
}

void func_02048dc4(s32 **arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK func_0204861c(s32);
    M2C_UNK func_020377c4(M2C_UNK);
    extern M2C_UNK data_020fcd20;
    extern M2C_UNK data_020fcd84;
    extern M2C_UNK data_020fcdb0;
    s32 var_r4;

    if (arg0 == NULL) {
        func_020640a8(&data_020fcdb0, &data_020fcd84, &data_020fcd20, 0x51);
    }
    if (arg0 == NULL) {
        return;
    }
    var_r4 = 0;
    if (M2C_FIELD(arg0, s32 *, 4) > 0) {
        do {
            func_0204861c(M2C_FIELD(arg0, s32 **, 0)[var_r4]);
            var_r4 += 1;
        } while (var_r4 < M2C_FIELD(arg0, s32 *, 4));
    }
    func_020377c4(M2C_FIELD(arg0, s32 **, 0));
    func_020377c4(arg0);
}

s32 func_02048e38(void *p) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd38;
s32 func_02048688(s32);
s32 i, sum=0;
if(!p)func_020640a8(&data_020fcdb0,&data_020fcd84,&data_020fcd38,0x61);
if(!p)return 0;
for(i=0;i<M2C_FIELD(p,s32 *,4);i++)sum+=func_02048688(M2C_FIELD(p,s32 **,0)[i]);
return sum;
}

void func_02048eac(void *p,s32 a) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd2c;
s32 func_020489e4(s32,s32,s32,s32,s32);
M2C_UNK func_020486f8(s32,s32);
M2C_UNK func_02048964(s32,s32,s32);
s32 i,n;
if(!p)func_020640a8(&data_020fcdb0,&data_020fcd84,&data_020fcd2c,0x71);
if(!p)return;
i=M2C_FIELD(p,s32 (**)(s32,s32),12)(a,M2C_FIELD(p,s32 *,4));
n=func_020489e4(M2C_FIELD(p,s32 **,0)[i],a,M2C_FIELD(p,s32 *,16),0,0);
if(n==-1)func_020486f8(M2C_FIELD(p,s32 **,0)[i],a);
else func_02048964(M2C_FIELD(p,s32 **,0)[i],a,n);
}

s32 func_02048f54(void *p,s32 a) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd44;
s32 func_020489e4(s32,s32,s32,s32,s32);
s32 i,n;
if(!p)func_020640a8(&data_020fcdb0,&data_020fcd84,&data_020fcd44,0x82);
if(!p)return 0;
i=M2C_FIELD(p,s32 (**)(s32,s32),12)(a,M2C_FIELD(p,s32 *,4));
n=func_020489e4(M2C_FIELD(p,s32 **,0)[i],a,M2C_FIELD(p,s32 *,16),0,0);
if(n==-1)return 0;
func_0204890c(M2C_FIELD(p,s32 **,0)[i],n);
return 1;
}

s32 func_02048ff8(void *p,s32 a) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd50;
s32 func_02048690(s32,s32);
s32 i,n;
if(!p)func_020640a8(&data_020fcdb0,&data_020fcd84,&data_020fcd50,0x94);
if(!p)return 0;
i=M2C_FIELD(p,s32 (**)(s32,s32),12)(a,M2C_FIELD(p,s32 *,4));
n=func_020489e4(M2C_FIELD(p,s32 **,0)[i],a,M2C_FIELD(p,s32 *,16),0,0);
if(n==-1)return 0;
return func_02048690(M2C_FIELD(p,s32 **,0)[i],n);
}

void func_02049098(void *p,s32 a,s32 b) {
extern M2C_UNK data_020fcdc8,data_020fcd84,data_020fcd5c;
void func_02048a9c(s32,s32,s32);
s32 i;
if(!a)func_020640a8(&data_020fcdc8,&data_020fcd84,&data_020fcd5c,0xb6);
for(i=0;i<M2C_FIELD(p,s32 *,4);i++)func_02048a9c(M2C_FIELD(p,s32 **,0)[i],a,b);
}

s32 func_02049104(void *p,s32 a,s32 b) {
extern M2C_UNK data_020fcdc8,data_020fcd84,data_020fcd6c;
s32 func_02048afc(s32,s32,s32);
s32 i,n;
if(!a)func_020640a8(&data_020fcdc8,&data_020fcd84,&data_020fcd6c,0xd3);
for(i=0;i<M2C_FIELD(p,s32 *,4);i++){n=func_02048afc(M2C_FIELD(p,s32 **,0)[i],a,b);if(n)return n;}
return 0;
}

void func_0204917c(u8 *a,char *b){extern char data_020fcdcc[];unsigned int i=0;int off=0;do {func_020675e4(b+off,data_020fcdcc,a[i]);i++;off+=2;}while(i<16);}

void func_020491bc(int a,int b,char *c){u8 ctx[88];u8 digest[16];func_02027090(ctx);func_0202709c(ctx,a,b);func_020270a8(digest,ctx);func_0204917c(digest,c);}

unsigned long long func_02049208(void){int func_02006f8c(void);unsigned long long func_02007004(void);extern char data_020fcdf0[],data_020fce10[],data_020fcde0[];if(func_02006f8c()!=1)func_020640a8(data_020fcdf0,data_020fce10,data_020fcde0,0x109);return (func_02007004()<<6)/0x82ea;}

void func_02049260(void) {
    M2C_UNK func_02006030();
    func_02006030();
}

void func_0204926c(void) {

}

void func_02049270(void) {

}

s32 func_02049274(s32 arg0) {
    s32 func_02037794(s32);
    s32 func_02068c34();
    M2C_UNK func_02068c50(s32, s32);
    s32 temp_r0;

    if (arg0 == 0) {
        return 0;
    }
    temp_r0 = func_02037794(func_02068c34() + 1);
    if (temp_r0 != 0) {
        func_02068c50(temp_r0, arg0);
    }
    return temp_r0;
}

#pragma opt_cond_exec off
s8 *func_020492a8(s8 *p) {
extern M2C_UNK data_020eac40;
s8 *q=p; s32 c=*p;
if(c){do{if(c>=0 && c<128){c=((u8 *)&data_020eac40)[c];} *p=c;c=*++p;}while(c);}
return q;
}
#pragma opt_cond_exec reset
s32 func_020492ec(M2C_UNK arg0, s32 arg1) {
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

s32 func_0204932c(s32 a,s32 b,...) {
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

/* Polls a single fd for readability/priority/error; sets output flags accordingly. */
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

void func_020496a4(void) {
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

s32 func_02049740(int a,UnkSocketAddress *b,u8 c){s32 func_02021558(int,UnkSocketAddress *);UnkSocketAddress addr=*b;addr.bytes[0]=c;return func_0204968c(func_02021558(a,&addr),-1);}

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

void func_020497cc(void) {
    s32 func_020215d4();
    func_0204968c(func_020215d4(), -1);
}

void func_020497e0(int a,int b,int c,int d,u8 *e,s32 *f){s32 func_020215f8(int,int,int,int,u8 *);s32 r;*e=*f;r=func_020215f8(a,b,c,d,e);*f=*e;func_0204968c(r,-1);}

void func_02049810(void) {
    s32 func_020216a8();
    M2C_UNK func_0204968c(s32, M2C_UNK);
    func_0204968c(func_020216a8(), -1);
}

s32 func_02049824(int a,int b,int c,int d,UnkSocketAddress *e,int f){
s32 func_020216cc(int,int,int,int,UnkSocketAddress *);
s32 func_0204968c(s32,s32);
UnkSocketAddress addr;
UnkSocketAddress *v=&addr;
UnkSocketAddress *u=e;
*v=*u;
addr.bytes[0]=(u8)f;
return func_0204968c(func_020216cc(a,b,c,d,&addr),-1);
}

s32 func_0204987c(s32 a,s32 b,s32 c,s32 d,s32 *e) {
M2C_UNK func_02007f8c(s32,s32,s32);
func_02007f8c(d,0,*e);return func_0204968c(0,-1);
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

s32 func_02049900(void) {
    extern M2C_UNK data_0213dc60;
    return M2C_FIELD(&data_0213dc60, s32 *, 4);
}

void func_02049910(int *out) {
int func_02006f8c(void); unsigned long long func_02007004(void);
unsigned long long func_02072088(unsigned long long, unsigned long long);
extern char data_020fcdf0[],data_020fce10[],data_020fcdd8[];
unsigned int v;
if(func_02006f8c()!=1)func_020640a8(data_020fcdf0,data_020fce10,data_020fcdd8,0x667);
v=func_02072088(func_02007004()<<6,0x1ff6210);
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

void func_020499e0(s32 arg0) {
    extern s32 data_020fcdd4;
    s32 var_r1;

    if (arg0 != 0) {
        var_r1 = arg0 & ~0x80000000;
    } else {
        var_r1 = 1;
    }
    data_020fcdd4 = var_r1;
}

s32 func_020499fc(s32 a,s32 b){s32 n=b-a;s32 result;if(n==0)return a;result=func_020499c0();result%=n;return result+a;}

void func_02049a20(signed char *src,unsigned char *dst,int n) {
unsigned char b[3]; int i;
for(i=0;i<n;i++)b[i]=src[i];
for(;i<3;i++)b[i]=0;
dst[0]=b[0]>>2;
dst[1]=((b[0]&3)<<4)|(b[1]>>4);
dst[2]=((b[1]&15)<<2)|(b[2]>>6);
dst[3]=b[2]&63;
}

