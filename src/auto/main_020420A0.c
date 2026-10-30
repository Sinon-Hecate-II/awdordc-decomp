/* 16 functions from 0x020420A0 to 0x0204309C (main), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
s32 func_020420a0(void) {
 void *func_02044268(void);
 u64 func_02007004(void);
 u64 func_02072088(u64,u64);
 s32 func_02038f6c(void);
 s32 func_02041038(s32);
 void func_02041fb0(s32,s32);
 s32 func_02041e74(s32);
 void func_02041e44(void);
 void func_02041be0(s32);
 void func_020411dc(s32);
 s32 func_02040e1c(s32);
 u64 now,delta;
 s32 i;
 void *p;
 if(M2C_FIELD(func_02044268(),s32 *,0x1a0)==9 ||
 M2C_FIELD(func_02044268(),s32 *,0x1a0)==16 ||
 M2C_FIELD(func_02044268(),s32 *,0x1a0)==17) {
 now=func_02007004();
 delta=func_02072088((now-M2C_FIELD(func_02044268(),u64 *,0x1e0))<<6,0x82eaULL);
 } else return 1;
 switch(M2C_FIELD(func_02044268(),s32 *,0x1a0)){
 case 9:
 if(delta>6000ULL){
 if(func_02038f6c()==5 && M2C_FIELD(func_02044268(),u8 *,0x1ad)>=5){
 if(func_02041038(M2C_FIELD(func_02044268(),s32 *,0xf4))==0) return 0;
 } else {
 M2C_FIELD(func_02044268(),u8 *,0x1ad)++;
 func_02041fb0(M2C_FIELD(func_02044268(),u8 *,0x2d0),3);
 }
 }
 break;
 case 16:
 if(delta>6000ULL){
 M2C_FIELD(func_02044268(),u8 *,0x1ab)++;
 if(M2C_FIELD(func_02044268(),u8 *,0x1ab)>5){
 u8 mode=M2C_FIELD(func_02044268(),u8 *,0x15);
 if(mode==1){
 func_02041e44();
 func_02041be0(1);
 } else {
 if(func_02041e74(M2C_FIELD(func_02044268(),s32 *,0x1d4))==0) return 0;
 if(M2C_FIELD(func_02044268(),u8 *,0xd)!=0){
 M2C_FIELD(func_02044268(),u8 *,0x1ab)=0;
 M2C_FIELD(func_02044268(),u64 *,0x1e0)=func_02007004();
 } else {
 if(func_02040e1c(M2C_FIELD(func_02044268(),s32 *,0x20c))==0) return 0;
 }
 }
 } else {
 for(i=1;i<=M2C_FIELD(func_02044268(),u8 *,0xd);i++){
 p=func_02044268();
 if((M2C_FIELD(p,u32 *,0x1d4)&(1<<M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x2d0)))==0){
 func_02041fb0(M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x2d0),2);
 } else {
 func_020411dc(4);
 return 1;
 }
 }
 }
 }
 break;
 case 17:
 if(delta>(u64)(s32)M2C_FIELD((u8 *)func_02044268()+0x100,u16 *,0xb0)) func_020411dc(4);
 break;
 }
 return 1;
}
#pragma opt_strength_reduction reset
s32 func_02042310(s32 a,s32 b){void *func_02044268(void);u64 func_02007004(void);void func_0203f058(s32,s32,s32,s32,s32 *,s32);s32 func_0204084c(void);s32 v,k;if(b==13){v=M2C_FIELD(func_02044268(),s32 *,0x20c);k=1;}else k=0;func_0203f058(b,a,0,0,&v,k);if(func_0204084c())return 0;{void *p=func_02044268();M2C_FIELD(p,u64 *,0x1e8)=func_02007004();}return 1;}

s32 func_02042390(s32 arg0, s32 arg1, s32 arg2) {
    void *func_02044268(void);
    s32 func_02038f6c(void);
    void func_02044278(s32);
    void func_02041dd4(s32);
    s32 func_02042310(s32, s32);
    u64 func_02007004(void);
    u64 func_02072088(u64, u64);
    u8 func_02042a08(s32, s32);
    s32 func_02042a6c(s32);
    void func_02041be0(s32);

    s32 b = arg1;
    s32 a = arg0;
    s32 c = arg2;

    void *P;
    void *P0;
    void *P2;
    u64 now;
    u64 base;
    u64 delta;
    u64 q;
    u64 half;
    u64 excess;
    u16 thresh;
    u8 idx;
    u8 cnt;
    u8 i;
    u8 bit;
    u32 mask;
    s32 node;

    if (func_02038f6c() != 6) {
        return 1;
    }

    if (b == 0xd) {
        P0 = func_02044268();
        if (M2C_FIELD(P0, s32 *, 0x1a0) != 0x8) {
            func_02044278(8);
            func_02041dd4(c);
            if (func_02042310(a, 0xe) == 0) {
                return 0;
            }
            goto lbl_508;
        }
    } else if (b == 0xf) {
        if (func_02042310(a, 0xf) == 0) {
            return 0;
        }
        goto lbl_508;
    } else if (b != 0xe) {
        goto lbl_508;
    }

    /* L_e */
    P = func_02044268();
    if (M2C_FIELD(P, s32 *, 0x1a0) != 0xe) goto lbl_4d4;

    now = func_02007004();
    base = M2C_FIELD(P, u64 *, 0x1e8);
    delta = now - base;
    q = func_02072088(delta << 6, 0x82eaULL);
    if (q <= 600ULL) goto lbl_434;

    half = q >> 1;
    excess = half - 300ULL;
    thresh = M2C_FIELD((u8 *)P + 0x100, u16 *, 0xb2);
    if (excess <= (u64)thresh) goto lbl_434;

    M2C_FIELD((u8 *)P + 0x100, u16 *, 0xb2) = (u16)excess;
    idx = func_02042a08(a, 0);
    if (idx != 0xff) {
        M2C_FIELD(P, s32 *, 0x1d8) |= (1 << idx);
        if (func_02042a6c(1) != M2C_FIELD(P, s32 *, 0x1d8)) goto lbl_508;
    }

lbl_434:
    P = func_02044268();
    cnt = M2C_FIELD(P, u8 *, 0xd);
    if (cnt >= 1) {
        for (i = 1; i <= cnt; i++) {
            P2 = func_02044268();
            node = M2C_FIELD((u8 *)P2 + i * 4, s32 *, 0xf4);
            bit = M2C_FIELD((u8 *)P2 + i, u8 *, 0x2d0);
            mask = M2C_FIELD(func_02044268(), u32 *, 0x1d8);
            if ((mask & (1U << bit)) == 0) {
                if (func_02042310(node, 13) == 0) {
                    return 0;
                }
            }
        }
        func_02044278(0xf);
        goto lbl_508;
    }

lbl_4c8:
    if (func_02042310(a, 0xf) == 0) {
        return 0;
    }
    goto lbl_508;

lbl_4d4:
    P = func_02044268();
    if (M2C_FIELD(P, s32 *, 0x1a0) == 0x8) {
        func_02041be0(2);
        return 1;
    }
    goto lbl_508;

lbl_508:
    return 1;
}

#pragma opt_strength_reduction off
s32 func_020425b4(void) {
 void *func_02044268(void);
 u64 func_02007004(void);
 u64 func_02072088(u64,u64);
 s32 func_02042310(s32,s32);
 s32 func_02041e74(s32);
 void func_02041be0(s32);
 u64 now,delta;
 s32 i;
 void *p;
 if(M2C_FIELD(func_02044268(),s32 *,0x1a0)==8 ||
 M2C_FIELD(func_02044268(),s32 *,0x1a0)==14 ||
 M2C_FIELD(func_02044268(),s32 *,0x1a0)==15) {
 now=func_02007004();
 delta=func_02072088((now-M2C_FIELD(func_02044268(),u64 *,0x1e8))<<6,0x82eaULL);
 } else return 1;
 switch(M2C_FIELD(func_02044268(),s32 *,0x1a0)){
 case 8:
 if(delta>6000 && func_02042310(M2C_FIELD(func_02044268(),s32 *,0xf4),14)==0) return 0;
 break;
 case 14:
 if(delta>6000){
 M2C_FIELD(func_02044268(),u8 *,0x1ac)++;
 if(M2C_FIELD(func_02044268(),u8 *,0x1ac)>5){
 if(func_02041e74(M2C_FIELD(func_02044268(),s32 *,0x1d8))==0) return 0;
 if(M2C_FIELD(func_02044268(),u8 *,0xd)!=0){
 M2C_FIELD(func_02044268(),u8 *,0x1ac)=0;
 M2C_FIELD(func_02044268(),u64 *,0x1e8)=func_02007004();
 } else func_02041be0(2);
 } else {
 for(i=1;i<=M2C_FIELD(func_02044268(),u8 *,0xd);i++){
 p=func_02044268();
 if((M2C_FIELD(p,u32 *,0x1d8)&(1<<M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x2d0)))==0){
 if(func_02042310(M2C_FIELD((u8 *)func_02044268()+i*4,s32 *,0xf4),13)==0) return 0;
 }
 }
 }
 }
 break;
 case 15:
 if(delta>(u64)(s32)M2C_FIELD((u8 *)func_02044268()+0x100,u16 *,0xb2)) func_02041be0(2);
 break;
 }
 return 1;
}
#pragma opt_strength_reduction reset
u8 func_020427b4(void){extern u8 data_0213d3bc[];u8 i=0;do{if(data_0213d3bc[i*12]==0)return i+100;i++;}while(i<154);return 0;}

void func_020427f4(void){extern u8 data_0213d3bc[];void func_020376d8(s32,s32,s32);void func_02007e54(s32,void *,s32);s32 i=0;u8 *p=data_0213d3bc;do{if(M2C_FIELD(p,s32 *,4))func_020376d8(4,M2C_FIELD(p,s32 *,4),0);i++;p+=12;}while(i<154);func_02007e54(0,data_0213d3bc,0x738);}

u8 func_0204284c(void){void *func_02044268(void);u8 i=0;s32 j;do{for(j=0;j<=M2C_FIELD(func_02044268(),u8 *,20);j++){if(i==M2C_FIELD((u8 *)func_02044268()+j,u8 *,0x2d0))break;}if(j>M2C_FIELD(func_02044268(),u8 *,20))break;i++;}while(i<32);return i;}

s32 func_020428bc(s32 a){void *func_02044268(void);s32 func_0203ae6c(u8);s32 i,v;if(!M2C_FIELD(func_02044268(),s32 *,0x2fc))return 0;for(i=0;i<M2C_FIELD(func_02044268(),s32 *,0x344);i++){v=func_0203ae6c(M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x304));if(v>0&&v==a)return 1;}return 0;}

s32 func_0204292c(void *arg0) {
    s32 func_02060b68(void *, void *, s32);
    extern u8 data_020fca1c[];
    extern u8 data_020fca28[];
    extern u8 data_020fc960[];
    extern u8 data_020fc96c[];
    extern u8 data_020fc978[];
    extern u8 data_020fc958[];
    s32 r0;

    // Checks several conditions using func_02060b68, returns 0 if any main check fails.
    r0 = func_02060b68(arg0, data_020fca1c, -1);
    if (r0 == -1) return 0;
    r0 = func_02060b68(arg0, data_020fca28, -1);
    if (r0 == -1) return 0;
    r0 = func_02060b68(arg0, data_020fc960, -1);
    if (r0 == -1) return 0;
    r0 = func_02060b68(arg0, data_020fc96c, -1);
    if (r0 == -1) {
        r0 = func_02060b68(arg0, data_020fc96c, 0);
        if (r0 == 0) return 0;
    }
    r0 = func_02060b68(arg0, data_020fc978, -1);
    if (r0 == -1) return 0;
    r0 = func_02060b68(arg0, data_020fc958, 0);
    return r0;
}

u8 func_02042a08(s32 a,s32 b){void *func_02044268(void);s32 i=b==0?1:0;if(i<=M2C_FIELD(func_02044268(),u8 *,13)){do{void *p=func_02044268();if(a==M2C_FIELD((u8 *)p+((u32)i*4),s32 *,0xf4))return M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x2d0);i++;}while(i<=M2C_FIELD(func_02044268(),u8 *,13));}return 255;}

s32 func_02042a6c(s32 arg0) {
    void *func_02044268();
    s32 var_r5;
    s32 var_r6;
    u8 temp_r0;

    var_r5 = 0;
    if (arg0 != 0) {
        return M2C_FIELD(func_02044268(), s32 *, 0x2F0) & ~1;
    }
    var_r6 = 1;
    if ((s32) M2C_FIELD(func_02044268(), u8 *, 0xD) >= 1) {
        do {
            temp_r0 = M2C_FIELD((func_02044268() + var_r6), u8 *, 0x2D0);
            var_r6 += 1;
            var_r5 |= 1 << temp_r0;
        } while (var_r6 <= (s32) M2C_FIELD(func_02044268(), u8 *, 0xD));
    }
    return var_r5;
}

void func_02042ad0(void){void *func_02044268(void);u64 func_02007004(void);void *p;M2C_FIELD(func_02044268(),u8 *,0x1ad)=0;p=func_02044268();M2C_FIELD(p,u64 *,0x1f8)=func_02007004();}

void func_02042af8(s32 a){u64 func_02007004(void);extern void *data_0213d39c;u64 t;if(!data_0213d39c||!M2C_FIELD(data_0213d39c,u8 *,0))return;M2C_FIELD(data_0213d39c,s32 *,8)=0;M2C_FIELD(data_0213d39c,s32 *,12)=0;M2C_FIELD(data_0213d39c,u8 *,2)=0;t=func_02007004();M2C_FIELD(data_0213d39c,u64 *,24)=t;if(a)return;t=func_02007004();M2C_FIELD(data_0213d39c,u64 *,16)=t;}

u32 func_02042f94(u32 a,u32 unused,u32 off){u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=9;off=code-10;break;case 2:code=9;off=code-11;break;case 3:code=6;off=code-16;break;case 4:code=6;off=code-26;break;}func_0203dc38(code,off+0xfffec398);return ret;}

u32 func_02043008(u32 a,u32 unused,u32 off){u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=6;off=code-56;break;case 2:code=6;off=code-36;break;case 3:code=6;off=code-26;break;case 4:code=6;off=code-46;break;case 5:code=9;off=code-10;break;case 6:code=9;off=code-11;break;}func_0203dc38(code,off+0xfffeb3f8);return ret;}

