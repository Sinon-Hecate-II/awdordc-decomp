/* 32 functions from 0x0216BD08 to 0x0216CCE0 (ov001), found by ds-decomp. */
#pragma ipa off
#include "common.h"
extern unsigned char data_ov001_0218fd40[];
extern unsigned char data_ov001_0218fdb0[];
typedef struct PacketWork { signed char a; short b,c; unsigned short pad; unsigned char type,zero; short len; int value; } PacketWork;
extern unsigned char data_ov001_02191ec0[];
extern unsigned char data_ov001_02191840[];
typedef struct CipherState { unsigned int i, j; unsigned char *s; unsigned int n; } CipherState;
extern unsigned char data_ov001_02191800[];
extern signed char data_ov001_02191820[];
extern short data_ov001_02192568;
extern unsigned char data_ov001_0219256a[118];

#pragma thumb on
int func_ov001_0216bde4(int a,unsigned char *p,int *n,unsigned char *q) {
 int func_ov001_0216c098(); int func_ov001_0216cef0(unsigned short); int func_ov001_0216cec8(int);
 void func_ov001_0216b918(int); void func_ov001_0216cde4(); int func_ov001_0216c400();
 unsigned char *r,*t;
 if(a!=1) {++*n;return a;}
 r=p+12;t=p+36;
 if(func_ov001_0216c098(q+8,r+16)<0) {++*n;return a;}
 if(func_ov001_0216cef0(*(unsigned short *)(t+2))==0) {++*n;return a;}
 if(*t==7) {
 if(func_ov001_0216cec8(*(int *)(t+4))==-2) func_ov001_0216b918(20);
 else if(func_ov001_0216cec8(*(int *)(t+4))==-3) func_ov001_0216b918(21);
 else func_ov001_0216b918(24);
 return -1;
 }
 func_ov001_0216cde4(data_ov001_02191ec0,0,0x6a0);
 if(func_ov001_0216c400(0,t,func_ov001_0216cef0(*(unsigned short *)(r+10)),data_ov001_02191ec0,data_ov001_02191840)<0) {++*n;return a;}
 if(!(*(int *)(data_ov001_02191800+48)&*(int *)(data_ov001_02191800+44))) return a;
 *n=0;return 2;
}

#pragma thumb on
int func_ov001_0216bebc(int a,unsigned char *p,int *n,unsigned char *q) {
 int func_ov001_0216c098(); int func_ov001_0216cef0(unsigned short); int func_ov001_0216cec8(int); void func_ov001_0216b918(int);
 unsigned char *r,*t;
 if(a!=2) {++*n;return a;}
 r=p+12;t=p+36;
 if(func_ov001_0216c098(q+16,(int)r+16)<0) {++*n;return a;}
 if(*t!=7) {++*n;return a;}
 if(func_ov001_0216cef0(*(unsigned short *)(t+2))==0) {++*n;return a;}
 if(func_ov001_0216cec8(*(int *)(t+4))==0) return 100;
 if(func_ov001_0216cec8(*(int *)(t+4))==-2) {func_ov001_0216b918(20);return -1;}
 if(func_ov001_0216cec8(*(int *)(t+4))==-3) {func_ov001_0216b918(21);return -1;}
 func_ov001_0216b918(24);return -1;
}

s32 func_ov001_0216c0e4(M2C_UNK arg0, M2C_UNK arg1) {
    void func_ov001_0216cde4();
    int func_ov001_0216cef0(u16);
    void func_ov001_0216cdd4();
    int func_ov001_0216c1a0();
    int func_ov001_0216cec8();
    extern unsigned char data_ov001_02191800[];

    M2C_UNK r4;
    M2C_UNK r5;
    M2C_UNK r6;
    M2C_UNK r7;
    s32 r2;
    u8 t;
    u16 f;
    s32 v;

    r5 = arg1;
    r6 = arg0;
    func_ov001_0216cde4(r5, 0, 0x104);
    r7 = r5 + 0x80;
    r4 = r6;
    r2 = func_ov001_0216cef0(*(u16 *)((u8 *)r4 + 2));
    if (r2 <= 0) {
        return -1;
    }
    for (;;) {
        t = *(u8 *)r4;
        if (t > 6) {
            return -1;
        }
        switch (t) {
        case 0:
            func_ov001_0216cdd4(r5, (M2C_UNK)((u8 *)r4 + 6));
            break;
        case 1:
            func_ov001_0216cdd4(r7, (M2C_UNK)((u8 *)r4 + 6));
            break;
        case 2:
            func_ov001_0216cdd4(r5 + 0x100, (M2C_UNK)((u8 *)r4 + 6));
            break;
        case 3:
            if (func_ov001_0216cef0(*(u8 *)((u8 *)r4 + 6)) <= 0) {
                return -1;
            }
            break;
        case 4:
            v = func_ov001_0216c1a0((M2C_UNK)((u8 *)r4 + 6), r2);
            v = func_ov001_0216cec8(v);
            *(s32 *)(data_ov001_02191800 + 0x34) = v;
            break;
        case 5:
            v = func_ov001_0216c1a0((M2C_UNK)((u8 *)r4 + 6), r2);
            v = func_ov001_0216cec8(v);
            *(s32 *)(data_ov001_02191800 + 0x38) = v;
            break;
        case 6:
        default:
            return -1;
        }
        f = *(u16 *)((u8 *)r4 + 4);
        if (f == 0) {
            return 0;
        }
        r4 = (M2C_UNK)((u8 *)r6 + func_ov001_0216cef0(f));
    }
}

s32 func_ov001_0216c1a0(s32 arg0, s32 arg1) {
    s32 var_r3;
    s32 var_r4;
    u8 *var_r5;
    u8 temp_r0;

    var_r3 = 0;
    var_r5 = arg0 + (arg1 - 1);
    var_r4 = 0;
    if (arg1 > 0) {
        do {
            temp_r0 = *var_r5;
            var_r4 += 1;
            var_r5 -= 1;
            var_r3 = temp_r0 + (var_r3 << 8);
        } while (var_r4 < arg1);
    }
    return var_r3;
}
#pragma thumb off

#pragma thumb on
s32 func_ov001_0216c1c4(void *arg0,s32 arg1) {
s32 func_ov001_0216cef0(u16);
void func_ov001_0216cdd4();
u8 *p=(u8 *)arg0+6;
u8 *out=(u8 *)arg1;
u8 *base,*e,*d,*c,*b,*a;
u32 n;
e=out;e=out+8;d=out;d=out+240;c=out;c=out+176;b=out;b=out+112;a=out+48;base=p;
do {
n=func_ov001_0216cef0(*(u16 *)(p+2));
switch(*p){
case 0x10:case 0x11:case 0x12:case 0x13:if(n>5)return -1;break;
case 0x20:case 0x21:case 0x22:case 0x23:if(n>13)return -1;break;
case 0x15:case 0x25:if(n>33)return -1;break;
}
switch(*p){
case 0x10:case 0x20:func_ov001_0216cdd4(a,p+6,n);*(u32 *)(out+4)=n;break;
case 0x11:case 0x21:func_ov001_0216cdd4(b,p+6,n);*(u32 *)(out+4)=n;break;
case 0x12:case 0x22:func_ov001_0216cdd4(c,p+6,n);*(u32 *)(out+4)=n;break;
case 0x13:case 0x23:func_ov001_0216cdd4(d,p+6,n);*(u32 *)(out+4)=n;break;
case 0x15:case 0x25:if(n && p[n+5])return -1;func_ov001_0216cdd4(e,p+6,n);break;
default:return -1;
}
if(*(u16 *)(p+4)==0)break;
p=base+func_ov001_0216cef0(*(u16 *)(p+4));
}while(1);
return 0;
}

#pragma thumb on
int func_ov001_0216c318(void *p,int out) {
 int func_ov001_0216cef0(unsigned short); void func_ov001_0216cdd4();
 unsigned char *base=(unsigned char *)p+6,*r=base,*text=(unsigned char *)out+8; unsigned char *data=(unsigned char *)(out+48); unsigned int n; int kind;
 for(;;) {
 n=func_ov001_0216cef0(*(unsigned short *)(r+2)); kind=*r;
 switch(kind) {case 0x30:case 0x40:if(n>64)return -1;break;case 0x35:case 0x45:if(n>33)return -1;break;}
 switch(kind) {
 case 0x30:case 0x40:func_ov001_0216cdd4(data,r+6,n);*(int *)(out+4)=n;break;
 case 0x35:case 0x45:if(n && r[n+5]) return -1;func_ov001_0216cdd4(text,r+6,n);break;
 default:return -1;
 }
 if(!*(unsigned short *)(r+4))break;
 r=base+func_ov001_0216cef0(*(unsigned short *)(r+4));
 }
 return 0;
}
int func_ov001_0216c3d0(unsigned char *p, void *out) {
 int func_ov001_0216cef0(unsigned short);
 void func_ov001_0216cdd4();
 unsigned char *q = p + 6;
 int n = func_ov001_0216cef0(*(unsigned short *)(q+2));
 if (n <= 0) return -1;
 if (*q != 0x70) return -1;
 func_ov001_0216cdd4(out,q+6,n);
 return 0;
}

#pragma thumb on
s32 func_ov001_0216c400(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
s32 func_ov001_0216c1c4(void *,s32);
s32 func_ov001_0216c318(void *,s32);
s32 func_ov001_0216cef0(u16);
s32 func_ov001_0216c3d0(u8 *,void *);
s32 sp0=arg0;
u8 *p=arg1;
s32 rem=arg2;
s32 sp4=arg3;
s32 flags=0;
u8 *q;
s32 remaining,base,result,len;
s32 sp8,spC,sp10;
if(rem<=0)return -2;
search:
q=p;
if(q[0]!=data_ov001_0218fd40[sp0]){
len=func_ov001_0216cef0(*(u16 *)(p+2))+4;
rem-=len;p+=len;if(rem<=0)return -4;
goto search;
}
remaining=func_ov001_0216cef0(*(u16 *)(q+2));
base=sp4+0x350*sp0;
sp8=arg4;
spC=(sp0+3)<<7;
sp10=base;
sp10=sp10+8;
do {
switch(q[0]){
case 3:result=func_ov001_0216c1c4(q,sp10);flags|=1;break;
case 4:result=func_ov001_0216c1c4(q,base+0x138);flags|=2;break;
case 5:result=func_ov001_0216c318(q,base+0x268);flags|=4;break;
case 6:result=func_ov001_0216c318(q,base+0x2d8);flags|=8;break;
case 10:result=func_ov001_0216c3d0(q,(void *)(sp8+spC));break;
default:result=-3;break;
}
if(result!=0)return result;
len=func_ov001_0216cef0(*(u16 *)(q+2))+4;remaining-=len;q+=len;
}while(remaining>0);
*(s32 *)(data_ov001_02191800+0x30)|=flags;
return 0;
}
unsigned int func_ov001_0216c510(unsigned int x) { unsigned int result = 0; if (x & 0x10) result = 1; return result; }

int func_ov001_0216c520(int mode, int a, int b, int c) {
 void func_ov001_0216bc3c(int);
 int func_ov001_0216c574(int,int,int);
 int func_ov001_0216c6b8(int,int,int);
 int func_ov001_0216c794(int,int,int);
 switch(mode) {
 case 0: func_ov001_0216bc3c(2); return func_ov001_0216c574(a,b,c);
 case 1: func_ov001_0216bc3c(3); return func_ov001_0216c6b8(a,b,c);
 case 2: func_ov001_0216bc3c(5); return func_ov001_0216c794(a,b,c);
 default: return -1;
 }
}

void func_ov001_0216c88c(int mode, unsigned char *p, int a, short *n, short *out, int b) {
 int func_ov001_0216c9a0();
 void func_ov001_0216cdd4();
 short func_ov001_0216ceb0(unsigned short);
 extern unsigned char data_ov001_02192560[8];
 if(mode == 1) {
 *out = 1;
 func_ov001_0216c9a0(a,p+4,*n,b,p+2,data_ov001_02192560,8);
 *(short *)p = func_ov001_0216ceb0((unsigned short)*n);
 *n += 4;
 return;
 }
 func_ov001_0216cdd4(p,a,*n);
}

void func_ov001_0216c8e0(unsigned short *p,int a,int b,int c,signed char d,signed char e,void *f) {
 short func_ov001_0216ceb0(unsigned short);
 void func_ov001_0216cdd4();
 p[0]=func_ov001_0216ceb0(1); p[1]=0; p[2]=0;
 p[3]=func_ov001_0216ceb0((unsigned short)a); p[4]=0;
 p[5]=func_ov001_0216ceb0((unsigned short)b);
 p[6]=func_ov001_0216ceb0((unsigned short)c);
 ((signed char *)p)[14]=d; ((signed char *)p)[15]=e;
 func_ov001_0216cdd4(p+8,f,8);
}

void func_ov001_0216c938(int a,int b,int c,int d) {
 void func_ov001_0216cde4();
 void func_ov001_0216ce58();
 int func_ov001_0216ce88(int);
 short func_ov001_0216ceb0(unsigned short);
 int packet[2];
 func_ov001_0216cde4(packet,0,8);
 ((char *)packet)[1]=2;
 ((short *)packet)[1]=func_ov001_0216ceb0(0x5790);
 packet[1]=func_ov001_0216ce88(*(int *)(data_ov001_02191800+0x34));
 if(c==255 || data_ov001_02191820[0x1c]==0) packet[1]=-1;
 func_ov001_0216ce58(d,a,b,0,packet,8);
}

#pragma thumb on
int func_ov001_0216c9a0(int a,int b,int c,signed char *d,void *e,void *f,int g) {
 int func_ov001_0216ad54(int); void func_ov001_0216ad64(int);
 void func_ov001_0216caa4(); void func_ov001_0216cb08();
 int func_ov001_0216cb74(int,int); short func_ov001_0216cf1c(void); void func_ov001_0216cdd4();
 int handle; int packet[4]; short seed;
 *d=func_ov001_0216cb74(a,c); handle=func_ov001_0216ad54(c); packet[2]=handle;
 if(!handle) return -1;
 seed=func_ov001_0216cf1c(); func_ov001_0216cdd4(e,&seed,2);
 func_ov001_0216cdd4(&data_ov001_02192568,e,2);
 func_ov001_0216cdd4(data_ov001_0219256a,f,g);
 func_ov001_0216caa4(packet,&data_ov001_02192568,g+2,c);
 func_ov001_0216cb08(packet,b,a,c); func_ov001_0216ad64(packet[2]); return 0;
}

#pragma thumb on
int func_ov001_0216ca1c(int a,int b,int c,unsigned int d,void *e,void *f,int g) {
 int func_ov001_0216ad54(int); void func_ov001_0216ad64(int); void func_ov001_0216b918(int);
 void func_ov001_0216caa4(); void func_ov001_0216cb08(); int func_ov001_0216cb74(int,int); void func_ov001_0216cdd4();
 int packet[4]; int h=func_ov001_0216ad54(c); packet[2]=h;
 if(!h) {func_ov001_0216b918(2); return -1;}
 func_ov001_0216cdd4(&data_ov001_02192568,e,2);
 func_ov001_0216cdd4(data_ov001_0219256a,f,g);
 func_ov001_0216caa4(packet,&data_ov001_02192568,g+2,c);
 func_ov001_0216cb08(packet,b,a,c);
 if((int *)func_ov001_0216cb74(b,c)!=(int *)d) {
 func_ov001_0216b918(0x12); func_ov001_0216ad64(packet[2]); return -1;
 }
 func_ov001_0216ad64(packet[2]); return 0;
}
void func_ov001_0216caa4(CipherState *st,unsigned char *key,unsigned int len,unsigned int n) {
 unsigned char *s=st->s; unsigned int i,j,k; unsigned char t,u;
 st->j=0; st->i=0; st->n=n;
 for(i=0;i<n;i++) s[i]=i;
 j=0;k=0;
 for(i=0;i<n;i++) {
 t=s[i]; j=(j+key[k]+t)%st->n;
 u=s[j]; s[j]=t; s[i]=u;
 k++; if(k>=len) k=0;
 }
}

#pragma thumb on
unsigned int func_ov001_0216cb34(CipherState *st) {
 unsigned int n=st->n; unsigned char *s=st->s;
 unsigned char i=(st->i+1)%n;
 unsigned char a=s[i];
 unsigned char j=(a+st->j)%n;
 unsigned char b=s[j];
 st->i=i; st->j=j; s[j]=a; s[i]=b;
 return s[(a+b)%st->n];
}
#pragma thumb off

#pragma thumb on
unsigned int func_ov001_0216cb9c(unsigned int crc,unsigned char *p,int n,int ready,unsigned int *table) {
 void func_ov001_0216cbd4(int,unsigned int *);
 int i;
 if(!ready) func_ov001_0216cbd4(ready,table);
 for(i=0;i<n;i++) crc=(crc>>8)^table[(unsigned char)(p[i]^crc)];
 return crc;
}

int func_ov001_0216cc0c(void *p,int n,void *key,int len) {
 int func_ov001_0216ad54(int);
 void func_ov001_0216ad64(int);
 void func_ov001_0216cce0();
 void func_ov001_0216cc88(int,signed char *,int,signed char *,int);
 void func_ov001_0216ccbc(signed char *,unsigned char *,int);
 int a; int b; int i;
 a=func_ov001_0216ad54(n/2);
 if(!a) return -1;
 b=func_ov001_0216ad54(n);
 if(!b) { func_ov001_0216ad64(a); return -1; }
 for(i=0;i<2;i++) {
 func_ov001_0216cc88(i,(signed char *)a,n,key,len);
 func_ov001_0216ccbc((signed char *)a,p,n);
 func_ov001_0216cce0(p,n,b);
 }
 func_ov001_0216ad64(a); func_ov001_0216ad64(b); return 0;
}

#pragma thumb on
void func_ov001_0216cc88(int a,signed char *out,int n,signed char *key,int len) {
 int half=n/2; int j=a%len; int i;
 for(i=0;i<half;i++) {
 out[i]=i; out[i]^=key[j]; j++;
 if(j>=len) j=0;
 }
}
void func_ov001_0216ccbc(signed char *a,unsigned char *b,int n) {
 int i; int half=n/2;
 for(i=0;i<half;i++) { b[half] ^= a[i]; b++; }
}
#pragma thumb off
#pragma thumb on
