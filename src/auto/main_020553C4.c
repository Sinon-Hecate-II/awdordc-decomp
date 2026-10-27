/* 24 functions from 0x020553C4 to 0x020562D0 (main), found by ds-decomp. */
#include "common.h"
static inline s32 *Init55550(s32 *p) {s32 addr=(s32)p;M2C_FIELD(addr,s32 *,16)=0;M2C_FIELD(addr,s32 *,0)=0;M2C_FIELD(addr,s32 *,4)=0;M2C_FIELD(addr,s32 *,8)=0;M2C_FIELD(addr,s32 *,12)=0;M2C_FIELD(addr,s32 *,20)=0;return p;}
typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;
typedef struct Unk020553C4 { u8 pad[0x428]; s32 handle, unk42c, unk430; } Unk020553C4;
typedef struct { u8 bytes[8]; } UnkSocketAddress;
static inline void InitSocketAddress(s32 *p) { s32 addr=(s32)p; M2C_FIELD(addr,s32 *,0)=0; M2C_FIELD(addr,s32 *,4)=0; }

s32 func_020553c4(M2C_UNK arg0, void *arg1) {
    s32 func_020492ec(s32, M2C_UNK);
    s32 func_020496a4(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02049740(s32, UnkSocketAddress *, u8);
    s32 func_02049900(s32);
    void func_02050744(void *, s32, s32);
    M2C_UNK func_02055124(s32);
    void func_02058620(void **, s32, M2C_UNK);
    s32 func_02058644(M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_020feb6c;
    extern M2C_UNK data_020fecb0;
    extern M2C_UNK data_020fecd8;
    extern M2C_UNK data_020fed0c;
    s32 stack[3];
    s32 *qp;

    if (func_02055b84(arg0, M2C_FIELD(arg1, s32 *, 0xc), stack) == 0) {
        func_02058644(arg0, &data_020feb6c);
        return 3;
    }
    M2C_FIELD(arg1, s32 *, 0x8) = func_020496a4(2, 1, 0);
    if (M2C_FIELD(arg1, s32 *, 0x8) == -1) {
        func_02058620(arg0, 5, &data_020fecb0);
        func_02050744(arg0, 3, 0);
        return 3;
    }
    if (func_020492ec(M2C_FIELD(arg1, s32 *, 0x8), 0) == 0) {
        func_02058620(arg0, 5, &data_020fecd8);
        func_02050744(arg0, 3, 0);
        return 3;
    }
    func_02055124(M2C_FIELD(arg1, s32 *, 0x8));
    stack[1] = 0;
    stack[2] = 0;
    *((u8 *)stack + 5) = 2;
    qp = (s32 *) ((s32 *) stack[0])[2];
    stack[2] = qp[4];
    *((s16 *)stack + 3) = (s16) qp[5];
    if (func_02049740(M2C_FIELD(arg1, s32 *, 0x8), (UnkSocketAddress *)&stack[1], 8) == -1) {
        s32 r = func_02049900(M2C_FIELD(arg1, s32 *, 0x8));
        if ((r != -6) && (r != -0x1a) && (r != -0x4c)) {
            func_02058620(arg0, 5, &data_020fed0c);
            func_02050744(arg0, 3, 1);
            return 3;
        }
    }
    M2C_FIELD(arg1, s32 *, 0x0) = 0x67;
    return 0;
}

#pragma opt_dead_code off
s32 func_02055550(s32 ctx,void *p,s32 a,s32 str) {
s32 func_02068c34(s32 *);s32 func_0204fea0();s32 func_0204fed0();s32 gpiAppendStringToBufferLen();s32 func_0204fcfc();s32 func_02049910(s32);
extern s32 data_020fec7c,data_020fec0c,data_020fead4,data_020fed34,data_020fed44,data_020fed48,data_020fed50;
s32 buf[6];s32 len,r;
if(!p)func_020640a8(&data_020fec7c,&data_020fec0c,&data_020fead4,0x340);
if(!str)func_020640a8(&data_020fed34,&data_020fec0c,&data_020fead4,0x341);
len=func_02068c34((s32 *)str);
Init55550(buf);buf[4]=a;
r=func_0204fea0(ctx,buf,&data_020fed44);if(r)return r;
r=func_0204fed0(ctx,buf,a);if(r)return r;
r=func_0204fea0(ctx,buf,&data_020fed48);if(r)return r;
r=func_0204fed0(ctx,buf,len);if(r)return r;
r=func_0204fea0(ctx,buf,&data_020fed50);if(r)return r;
buf[5]=buf[2];
r=gpiAppendStringToBufferLen(ctx,buf,str,len);if(r)return r;
r=func_0204fcfc(ctx,buf,0);if(r)return r;
func_020486f8(M2C_FIELD(p,s32 *,0x38),buf);
M2C_FIELD(p,s32 *,16)=func_02049910(0)+300;
return 0;
}
void func_020556e0(s32 arg0,s32 arg1,s32 arg2,s32 *arg3) {
M2C_UNK func_020501d8(s32,s32,void *);
M2C_UNK func_020640a8(void *,void *,void *,s32);
M2C_UNK func_020675e4(void *,void *,...);
extern M2C_UNK data_020fed58,data_020fec0c,data_020feae8,data_020fed64;
u8 buf[64];s32 b,a,c;
a=arg3[0];b=arg3[1];c=arg3[2];
if(!arg3)func_020640a8(&data_020fed58,&data_020fec0c,&data_020feae8,0x376);
func_020675e4(buf,&data_020fed64,arg2,a,b,c);
func_020501d8(arg0,arg1,buf);
}

s32 func_0205575c(M2C_UNK arg0, void *arg1, M2C_UNK *arg2, s32 arg3) {
s32 func_02049910(M2C_UNK);
s32 func_0204fff8(M2C_UNK,void *,M2C_UNK);
s32 gpiSendOrBufferStringLen(M2C_UNK,void *,M2C_UNK *,s32);
s32 func_020501d8(s32,s32,void *);
M2C_UNK func_020640a8(void *,void *,void *,s32);
M2C_UNK func_020675e4(void *,void *,...);
s32 func_02068c34(M2C_UNK *);
extern M2C_UNK data_020feb04,data_020fec0c,data_020fec7c,data_020fed78,data_020fed7c;
M2C_UNK buffer[8];s32 result;
if(!arg1)func_020640a8(&data_020fec7c,&data_020fec0c,&data_020feb04,0x389);
if(!arg2)arg2=&data_020fed78;
if(arg3==-1)arg3=func_02068c34(arg2);
func_020675e4(buffer,&data_020fed7c,arg3);
result=func_020501d8(arg0,arg1,buffer);if(result)return result;
result=gpiSendOrBufferStringLen(arg0,arg1,arg2,arg3);if(result)return result;
result=func_0204fff8(arg0,arg1,0);if(result)return result;
M2C_FIELD(arg1,s32 *,0x10)=func_02049910(0)+0x12c;
return 0;
}

s32 func_02055848(s32 *arg0) {
unsigned long long func_020720f0(s32);
return (s32)(func_020720f0(*arg0)>>32);
}

s32 func_0205585c(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

void func_0205586c(void *arg0) {
    M2C_UNK func_020377c4(void *);
    M2C_UNK func_02053f18(void *);
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 8);
    if (temp_r0 != NULL) {
        func_020377c4(M2C_FIELD(temp_r0, void **, 8));
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 8) = NULL;
        func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0xC));
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0xC) = NULL;
        func_020377c4(M2C_FIELD(arg0, void **, 8));
        M2C_FIELD(arg0, void **, 8) = NULL;
    }
    func_02053f18(arg0);
    func_020377c4(M2C_FIELD(arg0, void **, 0x10));
    M2C_FIELD(arg0, void **, 0x10) = NULL;
    func_020377c4(M2C_FIELD(arg0, void **, 0x18));
    M2C_FIELD(arg0, void **, 0x18) = NULL;
}

s32 func_020558e8(void **arg0) {
s32 func_02048c5c(s32,s32,...);
Unk020553C4 *p=*arg0;s32 v; register void (*destroy)(void *);
p->unk430=0;p->unk42c=0;
destroy=func_0205586c;
v=func_02048c5c(28,4,func_02055848,func_0205585c,destroy);
p->handle=v;
return v!=0;
}

s32 func_02055940(void **a,void *b,s32 c) {
s32 func_0205817c(void **,s32,s32);void func_02058620(void **,s32,s32);s32 func_02058644(s32,s32 *);
s32 func_02068eac(s32,void *,s32);void func_02050744(void *,s32,s32);void *func_02037794(s32);s32 func_02050838(void *,Unk02050838Pair,s32 *,void *,s32);void func_02054484(void **,void *);
s32 func_02058254(s32,void *,void *,s32);s32 func_0206ad38(void *);
extern M2C_UNK data_020feda0,data_020feda8,data_020fedd8,data_020fede4;
char buffer[16];Unk02050838Pair pair;s32 *p;s32 r;s32 value;
if(func_0205817c(a,c,1))return 4;
if(func_02068eac(c,&data_020feda0,5)){func_02058620(a,1,(s32)&data_020feda8);func_02050744(a,3,1);return 3;}
if(!func_02058254(c,&data_020fedd8,buffer,16)){func_02058620(a,1,(s32)&data_020feda8);func_02050744(a,3,1);return 3;}
value=func_0206ad38(buffer);
pair=*(Unk02050838Pair *)((u8 *)b+12);
if(pair.unk_0){p=func_02037794(8);if(!p){func_02058644((s32)a,(s32 *)&data_020fede4);return 1;}p[1]=value;p[0]=0;r=func_02050838(a,pair,p,b,0);if(r)return r;}
func_02054484(a,b);return 0;
}

s32 func_02055b84(void **arg0,s32 arg1,s32 *arg2) {
s32 func_02048ff8(s32,void *);
s32 key[7];s32 v;void *p=*arg0;
key[0]=arg1;
v=func_02048ff8(M2C_FIELD(p,s32 *,0x428),key);
if(arg2)*arg2=v;
return v!=0;
}

void func_02055bc0(void **arg0, M2C_UNK arg1) {
    s32 func_02055b84(void **, M2C_UNK, s32 *);
    s32 sp0;
    void *temp_r4;

    temp_r4 = *arg0;
    if (func_02055b84(arg0, arg1, &sp0) == 0) {
        return;
    }
    func_02048f54(M2C_FIELD(temp_r4, s32 *, 0x428), sp0);
}

void func_02055bf4(void **arg0) {
    M2C_UNK func_02048f54(s32);
    func_02048f54(M2C_FIELD(*arg0, s32 *, 0x428));
}

s32 func_02055c08(s32 arg0,void *arg1,void *arg2) {
s32 func_02068d98(s32,s32);
void *p=M2C_FIELD(arg1,void **,12);
if(p && func_02068d98(M2C_FIELD(arg2,s32 *,0),M2C_FIELD(p,s32 *,0))==0 && func_02068d98(M2C_FIELD(arg2,s32 *,4),M2C_FIELD(p,s32 *,8))==0){
*M2C_FIELD(arg2,void ***,8)=arg1;M2C_FIELD(arg2,s32 *,12)=1;return 0;
}
return 1;
}

s32 func_02055c68(void **arg0,s32 arg1,s32 arg2,s32 *arg3) {
s32 func_02055cd0(void **,s32 (*)(s32,void *,void *),void *);
s32 data[4];
data[0]=arg1;data[1]=arg2;data[3]=0;data[2]=(s32)arg3;
func_02055cd0(arg0,func_02055c08,data);
if(!data[3])*arg3=0;
return 0;
}

void func_02055cb4(M2C_UNK arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK (**)(s32, M2C_UNK, s32), 4)(M2C_FIELD(arg1, s32 *, 0), arg0, M2C_FIELD(arg1, s32 *, 8));
}

s32 func_02055cd0(void **arg0,s32 (*arg1)(s32,void *,void *),void *arg2) {
s32 func_02049104(s32,void (*)(s32,void *),void *);
s32 data[3];void *p=*arg0;
data[1]=(s32)arg1;data[2]=(s32)arg2;data[0]=(s32)arg0;
return func_02049104(M2C_FIELD(p,s32 *,0x428),func_02055cb4,data)==0;
}

s32 func_02055d10(s32 arg0,void *arg1,void *arg2) {
s32 *p=M2C_FIELD(arg1,s32 **,8);
if(p && M2C_FIELD(arg2,s32 *,0)==*p){M2C_FIELD(arg2,void **,4)=arg1;return 0;}
return 1;
}

s32 func_02055d3c(void **arg0, s32 arg1) {
s32 data[2]; data[0]=arg1;data[1]=0;
func_02055cd0(arg0,func_02055d10,data);return data[1];
}

s32 func_02055d6c(void *arg0) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 *, 0xC) == 0) && (M2C_FIELD(arg0, s32 *, 8) == 0) && (M2C_FIELD(arg0, s32 *, 0x18) == 0) && (M2C_FIELD(arg0, s32 *, 0x10) == 0)) {
        return 1;
    }
    return 0;
}

s32 func_02055da4(void **ctx,void *entry){
void *func_02037794(s32);s32 func_020496a4(s32,s32,s32);s32 func_020492ec(s32,s32);void *func_02021768(void *);
s32 func_02049740(s32,UnkSocketAddress *,u8);s32 func_02049900(s32);
s32 func_02058644(M2C_UNK,M2C_UNK *);void func_02058620(void **,s32,M2C_UNK);void func_02050744(void *,s32,s32);
M2C_UNK func_020640a8(void *,void *,void *,s32);
extern M2C_UNK data_020fee8c,data_020fee9c,data_020feec4,data_020fee4c,data_020feef8,data_020fef28,data_020fef48,data_020fee34,data_020fef54;
void *p=M2C_FIELD(entry,void **,4),*host;s32 addr[2];s32 r;
M2C_FIELD(p,s32 *,12)=4096;M2C_FIELD(p,void **,8)=func_02037794(4097);
if(!M2C_FIELD(p,void **,8)){func_02058644(ctx,&data_020fee8c);return 1;}
M2C_FIELD(p,s32 *,4)=func_020496a4(2,1,0);
if(M2C_FIELD(p,s32 *,4)==-1){func_02058620(ctx,5,&data_020fee9c);func_02050744(ctx,3,1);return 3;}
if(!func_020492ec(M2C_FIELD(p,s32 *,4),0)){func_02058620(ctx,5,&data_020feec4);func_02050744(ctx,3,1);return 3;}
host=func_02021768(&data_020fee4c);
if(!host){func_02058620(ctx,5,&data_020feef8);func_02050744(ctx,3,1);return 3;}
InitSocketAddress(addr);((u8 *)addr)[1]=2;
addr[1]=**M2C_FIELD(host,s32 ***,12);
if(!addr[1])func_020640a8(&data_020fef28,&data_020fef48,&data_020fee34,89);
((u16 *)addr)[1]=0xcd74;
if(func_02049740(M2C_FIELD(p,s32 *,4),(UnkSocketAddress *)addr,8)==-1){
r=func_02049900(M2C_FIELD(p,s32 *,4));
if(r!=-6&&r!=-26&&r!=-76){func_02058620(ctx,5,&data_020fef54);func_02050744(ctx,3,1);return 3;}}
M2C_FIELD(entry,s32 *,20)=1;return 0;
}

s32 func_02055fa4(M2C_UNK arg0, void **arg1, s32 arg2) {
void *func_02037794(M2C_UNK);
M2C_UNK func_02058644(M2C_UNK, M2C_UNK *);
M2C_UNK func_02065210(void *, M2C_UNK, M2C_UNK);
extern M2C_UNK data_020fee8c;
s32 *p;void *buf;register s32 zero;
p=func_02037794(0x144);
if(!p){func_02058644(arg0,&data_020fee8c);return 1;}
func_02065210(p,0,0x144);
p[0]=arg2;p[1]=-1;zero=0;p[2]=zero;p[4]=zero;p[5]=zero;p[3]=zero;p[8]=zero;p[9]=zero;
p[7]=0x1000;
buf=func_02037794(0x1001);p[6]=(s32)buf;
if(!buf){func_02058644(arg0,&data_020fee8c);return 1;}
p[79]=0;p[80]=0;*arg1=p;return 0;
}

s32 func_02056054(void **arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_0204ec8c(void **, s32);
    s32 func_02054330(void **, M2C_UNK, M2C_UNK, void **, s32, s32, s32);
    s32 func_02055da4(void **, void *);
    void *spC;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    void *temp_r4;

    temp_r4 = *arg0;
    M2C_FIELD(temp_r4, s32 *, 0x210) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x210) + 1);
    temp_r0_3 = func_02054330(arg0, 3, arg1, &spC, arg2, arg3, arg4);
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_2 = func_02055da4(arg0, spC);
    if (temp_r0_2 != 0) {
        return temp_r0_2;
    }
    if (M2C_FIELD(spC, s32 *, 8) != 0) {
        temp_r0 = func_0204ec8c(arg0, M2C_FIELD(spC, s32 *, 0x18));
        if (temp_r0 != 0) {
            return temp_r0;
        }
    }
    return 0;
}

s32 func_020560e4(M2C_UNK arg0,s8 *arg1,s8 *arg2,s8 *arg3,s8 *arg4,s8 *arg5,s32 arg6,s32 arg7,s32 arg8,s32 arg9,s32 argA) {
M2C_UNK func_020492a8(void *);s32 func_02055fa4(M2C_UNK,void **,M2C_UNK);M2C_UNK func_020580fc(void *,s8 *,M2C_UNK);M2C_UNK func_02058644(M2C_UNK,M2C_UNK *);
extern M2C_UNK data_020fef7c;
void *sp4;s32 r;
if(arg1 && *arg1)goto ready;
if(arg3 && *arg3)goto ready;
if(arg4 && *arg4)goto ready;
if(arg5 && *arg5)goto ready;
if(arg6==0){if(arg2 && *arg2)goto ready;func_02058644(arg0,&data_020fef7c);return 2;}
ready:
r=func_02055fa4(arg0,&sp4,1);if(r)return r;
if(!arg1)M2C_FIELD(sp4,s8 *,0x28)=0;else func_020580fc(sp4+0x28,arg1,31);
if(!arg2)M2C_FIELD(sp4,s8 *,0x47)=0;else func_020580fc(sp4+0x47,arg2,21);
if(!arg3)M2C_FIELD(sp4,s8 *,0x5c)=0;else func_020580fc(sp4+0x5c,arg3,51);
func_020492a8(sp4+0x5c);
if(!arg4)M2C_FIELD(sp4,s8 *,0x8f)=0;else func_020580fc(sp4+0x8f,arg4,31);
if(!arg5)M2C_FIELD(sp4,s8 *,0xae)=0;else func_020580fc(sp4+0xae,arg5,31);
M2C_FIELD(sp4,s32 *,0x130)=arg6;
if(arg7<0)arg7=0;
M2C_FIELD(sp4,s32 *,0x134)=arg7;
r=func_02056054(arg0,sp4,arg8,arg9,argA);if(r==0)r=0;return r;
}

