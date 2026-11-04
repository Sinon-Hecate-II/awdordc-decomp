/* 17 functions from 0x02028038 to 0x02028EF4 (main), found by ds-decomp. */
#include "common.h"
typedef struct CallbackArgs_0202810c { s16 a,b; s32 c,d,e; } CallbackArgs_0202810c;
typedef struct State_02028038 { u8 pad[0x260]; s32 state; u32 bits; u8 pad268[0x14]; void (*callback)(CallbackArgs_0202810c *); } State_02028038;

#pragma opt_common_subs off
u16 func_02028038(s32 a){
extern void *data_02138e4c;
s32 i,b,bits,rem;void *p=data_02138e4c;
i=0;b=a;bits=M2C_FIELD(p,u32*,0x2264);do{rem=b%13;if(bits&(1<<(rem+1)))break;i++;b++;}while(i<13);
rem=(a+i)%13;return rem+1;
}
#pragma opt_common_subs on
void func_020280c8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    void func_0202810c(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern void *data_02138e4c;
    s16 temp_r0;

    temp_r0 = M2C_FIELD(data_02138e4c, s16 *, 0x2280);
    M2C_FIELD(data_02138e4c, s16 *, 0x2280) = 0;
    func_0202810c(temp_r0, arg0, arg1, arg2, arg3);
}

void func_0202810c(s16 a,s32 b,s32 c,s32 d,s32 e){
 extern void *data_02138e4c;
 CallbackArgs_0202810c args;
 State_02028038 *base=(State_02028038 *)((char *)data_02138e4c+0x2000);
 if(!base->callback)return;
 args.a=a;args.b=b;args.c=c;args.d=d;args.e=e;
 base->callback(&args);
}

#pragma opt_common_subs off
void func_02028160(s32 a){void func_0202826c(void);s32 func_0200751c(void);void func_02007530(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);extern void *data_02138e4c;s32 old=func_0200751c();if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==9&&a!=9)func_02007338((u8 *)data_02138e4c+0x22cc);if(M2C_FIELD(data_02138e4c,s32 *,0x2260)!=11)M2C_FIELD(data_02138e4c,s32 *,0x2260)=a;if(a==9)func_020072cc((u8 *)data_02138e4c+0x22cc,0x22f5341,0,func_0202826c,0);func_02007530(old);}
#pragma opt_common_subs on
M2C_UNK func_020281f8(void){void func_0202826c(void);extern void *data_02138e4c;s32 func_0200751c(void);void func_02007530(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);s32 old=func_0200751c();func_02007338((u8 *)data_02138e4c+0x22cc);if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==9)func_020072cc((u8 *)data_02138e4c+0x22cc,0x22f5341,0,func_0202826c,0);func_02007530(old);}

void func_0202826c(void) {
    M2C_UNK func_020281f8();
    M2C_UNK func_02029714();
    func_02029714();
    func_020281f8();
}

u32 func_0202827c(u32 a){s32 __cntlzw(u32);u32 n=0;s32 bit;for(;;){bit=31-__cntlzw(a);if(bit<0)return n;a&=~(1U<<bit);n++;}}

s32 func_020282a8(u32 arg0) {
    return __builtin_clz(arg0);
}

#pragma optimization_level 2
void func_020282b0(void){
 extern void *data_02138e4c;
 void func_02028ef4(void);
 s32 func_02012274(void (*)(void));
 u8 *p=(u8 *)data_02138e4c;
 p += 0x2000;
 if(p[0x26b])return;
 p[0x26b]=1;
 if(func_02012274(func_02028ef4)==2)return;
 func_02028160(11);
 func_020280c8(7,0,0,0x610);
}
#pragma optimization_level reset
void func_0202830c(u16 *p){extern void *data_02138e4c;if(p[1]!=8||p[2]!=22||p[3]!=37)return;switch(M2C_FIELD(data_02138e4c,s32 *,0x2260)){case 8:func_02028160(12);return;case 9:case 12:func_020282b0();return;case 10:func_02028160(12);return;}}

#pragma opt_propagation off
void func_02028384(void *arg0) {
s32 func_02011244(void);s32 func_02012158(void *);s32 func_02012198(void *);s32 func_02013cfc(void *,s32);s32 func_02013bc8(void *,s32,s32,void *);s32 func_02012740(void *,void *,s32,s32,u16);void func_0202899c(const u16 *);extern void *data_02138e4c;
s32 result=20;
switch(((u16 *)arg0)[1]){
case 0:
switch(((u16 *)arg0)[0]){
case 3:result=func_02012198(func_02028384);break;
case 4: {s32 n=func_02011244();switch(n){case 0: {func_02028160(1);func_020280c8(0,0,0,0x663);return;}case 4:default:func_02028160(11);func_020280c8(7,0,0,0x66c);return;}}
case 5:func_02028160(3);func_020280c8(0,0,0,0x673);return;
case 6:result=func_02012158(func_02028384);break;
case 29:result=func_02013cfc(func_02028384,0);break;
case 25:{u8 *p=data_02138e4c;result=func_02013bc8(func_02028384,p[0x2250],p[0x2251],p+0x2200);break;}
case 39:{u8 *p=data_02138e4c;u32 bits=M2C_FIELD(p,u32 *,0x2264);u16 flag=(bits&0xc0000)==0xc0000;result=func_02012740(func_0202899c,p+0x2140,0,(bits&0x30000)!=0x30000,flag);break;}
}
switch(result){case 2:return;case 3:break;case 8:func_02028160(12);{u8 *p=data_02138e4c;func_020280c8(1,M2C_FIELD(p,s16 *,0x2280)==5?p+0x2140:0,0,0x6af);}return;}
func_02028160(11);{u8 *p=data_02138e4c;func_020280c8(7,M2C_FIELD(p,s16 *,0x2280)==5?p+0x2140:0,0,0x6b8);}return;
case 1:func_02028160(12);{u8 *p=data_02138e4c;func_020280c8(1,M2C_FIELD(p,s16 *,0x2280)==5?p+0x2140:0,0,0x6de);}return;
case 2:case 3:case 4:default:func_02028160(11);{u8 *p=data_02138e4c;func_020280c8(7,M2C_FIELD(p,s16 *,0x2280)==5?p+0x2140:0,0,0x6e8);}return;
}}
#pragma opt_propagation on
void func_02028640(u16 *p){
extern void *data_02138e4c;
void func_020067a8(s32,s32); void func_020293a0(s32,u16); u64 func_020722fc(s32,s32); s32 func_020125b0(void *,void *);s32 func_02012700(void *);void func_02028924(u16 *);
s32 result=20,i,n;u32 bits;
switch(p[1]){
case 0:
if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==5){func_02028160(6);func_020280c8(0,0,0,0x704);}
switch(M2C_FIELD(data_02138e4c,s32 *,0x2260)){
case 6:
M2C_FIELD(data_02138e4c,u16 *,0x2280)=7;
if(p[4]==5){func_020067a8(M2C_FIELD(data_02138e4c,s32 *,0x2288),M2C_FIELD(data_02138e4c,u16 *,0x228c));
for(i=0;i<p[7];i++){func_020293a0(((s32 *)p)[i+4],p[i+40]);func_0202810c(7,0,((s32 *)p)[i+4],(s32)p,0x71a);}}
bits=M2C_FIELD(data_02138e4c,u32 *,0x2264);
if((bits&0xc00000)==0xc00000){n=func_0202827c(bits&0x3ffe);if(n){s32 v=M2C_FIELD(data_02138e4c,s32 *,0x2284);if((u32)(func_020722fc(v,n)>>32)==0)func_0202810c(8,0,v,0,0x728);}}
M2C_FIELD(data_02138e4c,u16 *,0x228e)=(1<<func_02028038((u16)(32-func_020282a8(p[5]))))>>1;
func_020067a8(M2C_FIELD(data_02138e4c,s32 *,0x2288),M2C_FIELD(data_02138e4c,u16 *,0x228c));
M2C_FIELD(data_02138e4c,s32 *,0x2284)++;
result=func_020125b0(func_02028640,(u8 *)data_02138e4c+0x2288);break;
case 7:result=func_02012700(func_02028924);break;
case 13:func_020282b0();return;
}
if(result==2)return;
if(result!=3&&result==8){func_02028160(12);func_020280c8(1,0,0,0x753);return;}
func_02028160(11);func_020280c8(7,0,0,0x75c);return;
case 1:func_020282b0();return;
case 2:case 3:case 4:default:func_02028160(11);func_020280c8(7,0,0,0x76d);return;
}}

void func_02028924(u16 *p){switch(p[1]){case 0:func_02028160(3);func_020280c8(0,0,0,0x783);return;case 1:func_020282b0();return;case 2:case 3:case 4:default:func_02028160(11);func_020280c8(7,0,0,0x793);return;}}

#pragma opt_common_subs on
void func_0202899c(const u16 *p){
extern void *data_02138e4c;
void func_02028cc8(u16 *);s32 func_02012dd4(void (*)(u16 *),void *,s32);
s32 result;
switch(p[1]){
case 0:
switch(p[4]){
case 6:goto done;
case 26:goto done;
case 8:case 9:
switch(M2C_FIELD(data_02138e4c,s32 *,0x2260)){
case 10:M2C_FIELD(data_02138e4c,u16 *,0x2282)=0;
case 8:func_02028160(12);return;
case 9:M2C_FIELD(data_02138e4c,u16 *,0x2282)=0;

case 12:M2C_FIELD(data_02138e4c,u16 *,0x2280)=6;func_020282b0();return;
default:goto done;}
case 7:
if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==12){func_02028160(8);func_020282b0();return;}
if(p[5]>=1&&p[5]<=0x7d7){
M2C_FIELD(data_02138e4c,u16 *,0x2282)=p[5];
result=func_02012dd4(func_02028cc8,(u8 *)data_02138e4c+0x1500,0x620);
switch(result){case 2:return;case 3:break;case 8:func_02028160(12);func_020280c8(1,(s32)((u8 *)data_02138e4c+0x2140),0,0x7ed);return;
}
func_02028160(11);func_020280c8(7,(s32)((u8 *)data_02138e4c+0x2140),0,0x7f6);return;
}
func_020282b0();return;
default:func_02028160(11);func_020280c8(7,(s32)((u8 *)data_02138e4c+0x2140),p[4],0x804);return;
}
case 1:M2C_FIELD(data_02138e4c,u16 *,0x22f8)=p[7];func_02028160(8);func_020282b0();return;
case 6:case 11:case 12:func_020282b0();return;
case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:
default:func_02028160(11);func_020280c8(7,(s32)((u8 *)data_02138e4c+0x2140),0,0x81b);return;
}
done:return;
}
void func_02028c00(u16 *p) {
    extern void *data_02138e4c;
    switch (p[1]) {
    case 0:
        if (M2C_FIELD(data_02138e4c, s32 *, 0x2260) == 0xc) {
            func_02028160(0xa);
            func_020282b0();
            return;
        }
        M2C_FIELD(data_02138e4c, u16 *, 0x2282) = 0;
        func_02028160(3);
        func_020280c8(0, (u8 *)data_02138e4c + 0x2140, 0, 0x83d);
        return;
    case 1:
    case 3:
        func_02028160(0xa);
        func_020282b0();
        return;
    case 2:
    case 4:
    default:
        func_02028160(0xb);
        func_020280c8(7, (u8 *)data_02138e4c + 0x2140, 0, 0x84f);
        return;
    }
}

void func_02028cc8(u16 *p) {
    extern void *data_02138e4c;
    void func_02028160(s32);
    void func_020280c8(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void func_020282b0(void);
    void func_02029bd0(M2C_UNK);
    void func_020067a8(M2C_UNK, M2C_UNK);
    void func_020296e0(M2C_UNK);

    switch (p[1]) {
    case 0:
        switch (p[2]) {
        case 0xe:
            if (M2C_FIELD(data_02138e4c, s32 *, 0x2260) == 0xc) {
                func_02028160(0x8);
                func_020282b0();
                return;
            }
            func_02028160(0x9);
            func_020280c8(0, (u8 *)data_02138e4c + 0x2140, 0, 0x872);
            return;
        case 0xf:
            func_02029bd0((*(u16 *)((u8 *)*(void **)((u8 *)p + 8) + 0xe) >> 8) & 0xff);
            func_020067a8(*(void **)((u8 *)p + 8), 0x620);
            func_020296e0(*(void **)((u8 *)p + 8));
            return;
        default:
            func_02028160(0xb);
            func_020280c8(7, (u8 *)data_02138e4c + 0x2140, p[2], 0x881);
            return;
        }
    case 4:
    default:
        func_02028160(0xb);
        func_020280c8(7, (u8 *)data_02138e4c + 0x2140, p[2], 0x88c);
        return;
    }
}

void func_02028c00(u16 *);
void func_02028dd8(u16 *p) {
extern void *data_02138e4c;
switch(p[1]){
case 0:
if(M2C_FIELD(data_02138e4c,s32 *,0x2260)==12){func_02028160(10);func_020282b0();return;}
switch(func_0201280c(func_02028c00,0)){
case 2:return;
case 8:func_02028160(12);func_020280c8(1,(u8 *)data_02138e4c+0x2140,0,0x8b4);return;
case 3:func_02028160(10);func_020282b0();return;
default:func_02028160(11);func_020280c8(7,(u8 *)data_02138e4c+0x2140,0,0x8c0);return;
}
case 1:case 3:func_02028160(10);func_020282b0();return;
case 2:case 4:default:func_02028160(11);func_020280c8(7,(u8 *)data_02138e4c+0x2140,0,0x8d3);return;
}
}

