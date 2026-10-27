/* 16 functions from 0x0201BDE0 to 0x0201CB4C (main), found by ds-decomp. */
#include "common.h"

void *func_0201bde0(s32 a,s32 b) {
 s32 func_0201bd2c(s32,s32,void *);
 extern M2C_UNK data_0212dca4;
 void *q;
 void *p=M2C_FIELD(&data_0212dca4,void **,8);
 while(p) {
 q=M2C_FIELD(p,void **,0xa4);
 if(q && M2C_FIELD(q,s32 *,0) && func_0201bd2c(a,b,q))return q;
 p=M2C_FIELD(p,void **,0x68);
 }
 return NULL;
}

void func_0201be44(void *a,void *b) {
 s32 n,t;
 u8 *p;
 M2C_FIELD(b,u16 *,46)=536;
 p=(u8 *)a+20;
 t=M2C_FIELD(a,u8 *,12)&240;
 n=((s32)(t+((u32)(t>>1)>>30))>>2)-20;
 while(n--) {
 u8 c=*p++;
 if(c==0)return;
 if(c==1)continue;
 if(c==2) {u8 h=p[1],l=p[2];p+=3;n-=3;M2C_FIELD(b,u16 *,46)=l|(h<<8);}
 else {t=p[0]-1;n-=t;p+=t;}
 }
}

s32 func_0201bec8(s32 arg0) {
    s32 func_0201a704();
    s32 func_0201abd0();
    if (func_0201a704() == 0) {
        return 1;
    }
    return func_0201abd0();
}

M2C_UNK func_0201bee4(M2C_UNK a,M2C_UNK b,M2C_UNK c) {
 extern M2C_UNK data_0212dca4,data_021374f8;
 if(func_0201bec8(M2C_FIELD(a,s32 *,28)) || M2C_FIELD(&data_0212dca4,void **,4)!=&data_021374f8) {
 func_0201b524(0,0,a,b,c);return;
 }
 func_0201aca0(func_0201a704(M2C_FIELD(a,s32 *,28)));
}

void func_0201bf58(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0201bee4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0201bee4(arg0, 0x10, arg1);
}

void func_0201bf6c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0201bee4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0201bee4(arg0, 0x11, arg1);
}

M2C_UNK func_0201bf80(M2C_UNK a,M2C_UNK b,s32 c,M2C_UNK d){
extern M2C_UNK data_021373d4,data_02137390,data_02137290;
void func_02007f8c(void *,s32,s32);
u16 e,f,g,h,i,j,k,l; s32 n;void *p=&data_021373d4;
func_02007f8c(p,0,100);
e=M2C_FIELD(b,u16 *,2);M2C_FIELD(&data_02137390,u16 *,78)=((s32)e>>8)|(e<<8);
f=M2C_FIELD(b,u16 *,0);M2C_FIELD(&data_02137390,u16 *,92)=((s32)f>>8)|(f<<8);
g=M2C_FIELD(a,u16 *,14);h=M2C_FIELD(a,u16 *,12);
M2C_FIELD(&data_02137290,u32 *,352)=((u16)(((s32)h>>8)|(h<<8))<<16)|(u16)(((s32)g>>8)|(g<<8));
if(M2C_FIELD(b,u8 *,13)&16){
i=M2C_FIELD(b,u16 *,10);j=M2C_FIELD(b,u16 *,8);
M2C_FIELD(p,u32 *,40)=((u16)(((s32)j>>8)|(j<<8))<<16)|(u16)(((s32)i>>8)|(i<<8));
func_0201bee4((s32)p,4,d);return;
}
M2C_FIELD(p,s32 *,40)=0;
k=M2C_FIELD(b,u16 *,6);l=M2C_FIELD(b,u16 *,4);
n=c+(((u16)(((s32)l>>8)|(l<<8))<<16)|(u16)(((s32)k>>8)|(k<<8)));
M2C_FIELD(p,s32 *,36)=n;
if(M2C_FIELD(b,u8 *,13)&3)M2C_FIELD(p,s32 *,36)=n+1;
func_0201bee4((s32)p,20,d);
}

M2C_UNK func_0201c0bc(void *arg0,void *arg1,void *arg2){u64 func_02007004(void);u16 a,b,c,d,e,f,g;u64 t;
M2C_FIELD(arg2,u8 *,8)=3;t=func_02007004();M2C_FIELD(arg2,u32 *,16)=t>>16;
a=M2C_FIELD(arg0,u16 *,18);b=M2C_FIELD(arg0,u16 *,16);
M2C_FIELD(arg2,u32 *,20)=((u16)(((s32)b>>8)|(b<<8))<<16)|(u16)(((s32)a>>8)|(a<<8));
c=M2C_FIELD(arg1,u16 *,0);M2C_FIELD(arg2,u16 *,24)=((s32)c>>8)|(c<<8);
d=M2C_FIELD(arg0,u16 *,14);e=M2C_FIELD(arg0,u16 *,12);
M2C_FIELD(arg2,u32 *,28)=((u16)(((s32)e>>8)|(e<<8))<<16)|(u16)(((s32)d>>8)|(d<<8));
f=M2C_FIELD(arg1,u16 *,6);g=M2C_FIELD(arg1,u16 *,4);
M2C_FIELD(arg2,u32 *,36)=(((u16)(((s32)g>>8)|(g<<8))<<16)|(u16)(((s32)f>>8)|(f<<8)))+1;
func_0201be44(arg1,arg2);func_0201bee4((s32)arg2,18,0);
}

s32 func_0201c1a8(s32 a,s32 b,s32 c) {
 void *p=func_0201bde0(a,b);
 u8 v;
 if(p) {
 v=M2C_FIELD(p,u8 *,8);
 if(v==1)func_0201c0bc(a,b,p);
 else if((u8)(v+253)<=1) {M2C_FIELD(p,s32 *,40)--;func_0201c0bc(a,b,p);}
 else func_0201bf80(a,b,c,0);
 return 1;
 }
 return 0;
}

void func_0201c230(void *arg0, void *arg1, s32 arg2) {
    s32 func_0201bb68(s32, s32);
    s32 func_0201c1a8(s32, s32, s32);
    void *func_0201bc58();
    M2C_UNK func_0201c0bc();
    M2C_UNK func_02005ec8();
    u16 t0, t1, t2, t3;
    u32 p0, p1;
    void *r;

    t0 = M2C_FIELD(arg0, u16 *, 0x12);
    t1 = M2C_FIELD(arg0, u16 *, 0x10);
    t2 = M2C_FIELD(arg0, u16 *, 0xe);
    t3 = M2C_FIELD(arg0, u16 *, 0xc);
    p0 = ((t2 << 8) | (t2 >> 8)) | (((u32)((t3 << 8) | (t3 >> 8))) << 16);
    p1 = ((t0 << 8) | (t0 >> 8)) | (((u32)((t1 << 8) | (t1 >> 8))) << 16);

    if (!func_0201bb68((s32)p0, (s32)p1)) {
        return;
    }
    if (func_0201c1a8((s32)arg0, (s32)arg1, arg2)) {
        return;
    }
    r = func_0201bc58(arg0, arg1);
    if (r != NULL) {
        func_0201c0bc(arg0, arg1, r);
        return;
    }
    func_02005ec8();
    r = func_0201bc58(arg0, arg1);
    if (r != NULL) {
        func_0201c0bc(arg0, arg1, r);
    }
}

/* Build a response packet from a received request and mark it ready. */
void func_0201c308(s32 a,void *b,s32 c) {
void *p=func_0201bde0(a,(s32)b);u16 d,e,f,g,h;
if(!p || M2C_FIELD(p,u8 *,8)!=2){func_0201bf80(a,b,c,0);return;}
func_02005ec8();
d=M2C_FIELD(b,u16 *,6);e=M2C_FIELD(b,u16 *,4);
M2C_FIELD(p,u32 *,36)=(((u16)(((s32)e>>8)|(e<<8))<<16)|(u16)(((s32)d>>8)|(d<<8)))+1;
f=M2C_FIELD(b,u16 *,10);g=M2C_FIELD(b,u16 *,8);
M2C_FIELD(p,u32 *,48)=((u16)(((s32)g>>8)|(g<<8))<<16)|(u16)(((s32)f>>8)|(f<<8));
h=M2C_FIELD(b,u16 *,14);M2C_FIELD(p,u16 *,44)=((s32)h>>8)|(h<<8);
func_0201be44(b,p);func_0201bf58(p,0);M2C_FIELD(p,u8 *,8)=4;
if(M2C_FIELD(p,s32 *,4)==1){M2C_FIELD(p,s32 *,4)=0;func_02005e5c(M2C_FIELD(p,s32 *,0));}
}

void func_0201c718(s32 arg0, s32 arg1, s32 arg2) {
    void *func_0201bde0(s32, s32);
    void func_0201bf58(M2C_UNK, M2C_UNK);
    void func_0201bf6c(M2C_UNK, M2C_UNK);
    M2C_UNK func_0201bf80(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02005e5c(M2C_UNK);
    void *p;
    u8 v;
    p = func_0201bde0(arg0, arg1);
    if (p == NULL) return;
    v = M2C_FIELD(p, u8 *, 8);
    switch (v) {
    case 4:
        M2C_FIELD(p, s32 *, 0x24)++;
        func_0201bf58(p, 0);
        M2C_FIELD(p, u8 *, 8) = 9;
        break;
    case 7:
        M2C_FIELD(p, s32 *, 0x24)++;
        func_0201bf58(p, 0);
        M2C_FIELD(p, u8 *, 8) = 0;
        if (M2C_FIELD(p, s32 *, 4) == 2) {
            M2C_FIELD(p, s32 *, 4) = 0;
            func_02005e5c(M2C_FIELD(p, M2C_UNK *, 0));
        }
        break;
    case 8:
        M2C_FIELD(p, s32 *, 0x24)++;
        func_0201bf6c(p, 0);
        M2C_FIELD(p, u8 *, 8) = 6;
        break;
    default:
        func_0201bf80(arg0, arg1, arg2, 0);
        break;
    }
}

void func_0201c7e4(s32 a,s32 b) {
    M2C_UNK func_02005e5c(s32);
    M2C_UNK func_02005ec8();
    void *func_0201bde0();
    void *temp_r0;

    temp_r0 = func_0201bde0();
    if (temp_r0 == NULL) {
        return;
    }
    func_02005ec8();
    M2C_FIELD(temp_r0, s8 *, 8) = 0;
    if ((u32) (M2C_FIELD(temp_r0, s32 *, 4) - 1) > 1U) {
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 4) = 0;
    func_02005e5c(M2C_FIELD(temp_r0, s32 *, 0));
}

void func_0201c820(void *a,void *b,s32 c){
s32 func_0201a674(void *,s32,void *,s32);
void func_0201c400(void *,void *,s32);
s32 t,kind;u8 flags;
if(func_0201a674(b,c,a,6))return;
t=M2C_FIELD(b,u8 *,12)&240;
flags=M2C_FIELD(b,u8 *,13);
kind=flags&23;
c-=(t/4);
switch(kind){
case 2:if(flags&40)return;func_0201c230(a,b,c);return;
case 18:if(flags&40)return;func_0201c308(a,b,c);return;
case 17:case 16:func_0201c400(a,b,c);return;
case 1:func_0201c718((s32)a,(s32)b,c);return;
default:if(flags&4){func_0201c7e4((s32)a,(s32)b);return;}func_0201bf80(a,b,c,0);return;
}
}

