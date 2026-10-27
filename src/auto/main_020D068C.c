/* 17 functions from 0x020D068C to 0x020D166C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[14]; } D068CUnit;
extern s32 *gCurrentMap;
static inline s32 D068CIndex(void *p) { s32 n; if(p) n=((s32)p-(*gCurrentMap+0x59a4))/14; else n=0; return n; }
static inline s32 D068COwner(void *p) { if(p) return (D068CIndex(p)>>6)+1; return 0; }
typedef struct { unsigned char value:6; } D068CBits;
void func_020d0bf8(M2C_UNK);
static inline u32 D068CLow(void *p) { return M2C_FIELD(p,D068CBits*,0).value; }
static inline u32 D068CFlag(void *p) { return M2C_FIELD(p,u16*,4)&32; }
s32 func_020a86f8();
static inline s32 D068CCall(M2C_UNK a,void *p,s32 c) {
 u32 low,flag;
 flag=D068CFlag(p); low=D068CLow(p);
 return func_020a86f8(a,low,c,flag);
}
static inline void D068CApply(void *p) {
 if(M2C_FIELD(p,s16*,0x14)==0)return;
 M2C_FIELD(p,s16*,0x14)+=((s32 (*)(M2C_UNK))func_020d0bf8)(M2C_FIELD(p,M2C_UNK*,0));
}
void func_020d0bf8(M2C_UNK);
void func_020d0bac(void *,s32);

void func_020d068c(void *p,s16 index) {
s32 func_020d05f4(); s32 func_020a3518();
void *q,*m; s16 stride=14;
q=(void *)*gCurrentMap+0x59a4+index*stride;
M2C_FIELD(p,void **,0)=q;
m=(void *)*gCurrentMap;
M2C_FIELD(p,s16 *,4)=M2C_FIELD(m+(M2C_FIELD(q,u8 *,1)+M2C_FIELD(m+M2C_FIELD(q,u8 *,2)*2,u16 *,0x3758)),u8 *,0x1420)&31;
M2C_FIELD(p,s16 *,6)=func_020d05f4(D068COwner(M2C_FIELD(p,void **,0)),D068CLow(M2C_FIELD(p,void **,0)),M2C_FIELD(p,s16 *,4));
M2C_FIELD(p,s16 *,8)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<25)>>25;
M2C_FIELD(p,s16 *,10)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<21)>>28;
M2C_FIELD(p,s16 *,12)=func_020a3518(D068COwner(M2C_FIELD(p,void **,0)));
M2C_FIELD(p,s16 *,14)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<25)>>25;
M2C_FIELD(p,s16 *,16)=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0),u16 *,6)<<21)>>28;
M2C_FIELD(p,s16 *,18)=func_020a3518(D068COwner(M2C_FIELD(p,void **,0)));
M2C_FIELD(p,s16 *,30)=0;M2C_FIELD(p,s16 *,24)=0;M2C_FIELD(p,s16 *,26)=0;
}

void func_020d0868(void *a,void **b,s32 c,s32 d) {
s32 func_020a76d4(void *); s32 func_020a792c(); s32 func_020a875c();
extern u8 data_ov000_021b5bfc[];
register u32 x; register u32 y; s16 z; u8 *p=data_ov000_021b5bfc+D068CLow(M2C_FIELD(a,void **,0))*112;
x=0; y=0; z=0;
M2C_FIELD(a,s16 *,22)=func_020a875c(M2C_FIELD(a,void **,0));
if(c==1) {
void *q=*b; u32 flag=D068CFlag(q);
z=func_020a792c(D068CLow(M2C_FIELD(a,void **,0)),D068CLow(q),1,flag);
if(z) {void *q=*b; u32 flag=D068CFlag(q); y=M2C_FIELD(q,u8 *,0)<<26; y=(u16)func_020a86f8(M2C_FIELD(a,void **,0),(u32)y>>26,1,flag);}
if(p[12]==1) {void *q=M2C_FIELD(a,void **,0);if((u32)(M2C_FIELD(q,u16 *,6)<<21)>>28){void *r=*b; u32 flag=D068CFlag(r);x=M2C_FIELD(r,u8 *,0)<<26; x=(u16)func_020a86f8(q,(u32)x>>26,0,flag);}}
} else if(p[12]<=c && c<=func_020a76d4(M2C_FIELD(a,void **,0))) {
void *q=M2C_FIELD(a,void **,0);
if(((u32)(M2C_FIELD(q,u16 *,6)<<21)>>28) && d==1){void *r=*b; u32 flag=D068CFlag(r);x=M2C_FIELD(r,u8 *,0)<<26; x=(u16)func_020a86f8(q,(u32)x>>26,0,flag);}
}
if((u32)x<=(u32)y){if(!z)return;M2C_FIELD(a,s16 *,30)=2;M2C_FIELD(a,u16 *,24)=y;return;}
M2C_FIELD(a,s16 *,30)=1;M2C_FIELD(a,u16 *,24)=x;M2C_FIELD(a,s16 *,16)-=1;
}

s32 func_020d0a08(M2C_UNK arg0,void *arg1) {
 s32 func_020a8204();
 s32 func_020a86f8();
 u16 temp_r0,var_r6;
 var_r6=0;
 if(func_020a8204()!=0)var_r6=D068CCall(arg0,arg1,0);
 temp_r0=D068CCall(arg0,arg1,1);
 return var_r6!=0 || temp_r0!=0;
}

s32 func_020d0a88(u8 *arg0,M2C_UNK arg1) {
 s32 func_020a5ae0();
 s32 func_020a796c();
 s32 func_020a8204();
 s32 func_020a86f8();
 u16 temp_r0,var_r4;
 var_r4=0;
 if(func_020a8204()!=0)var_r4=func_020a86f8(arg0,func_020a5ae0(arg1),0,0);
 temp_r0=func_020a796c((u32)(*arg0<<26)>>26,arg1,1);
 return var_r4!=0 || temp_r0!=0;
}

void func_020d0afc(void *arg0,s32 arg1,M2C_UNK arg2) {
 s32 func_020d18e8(void *);
 s32 var_r0,var_r4;u32 temp_r0;
 var_r4=100;
 temp_r0=(u32)(M2C_FIELD(M2C_FIELD(arg0,void**,0),u16*,6)<<25)>>25;
 if(temp_r0==0)var_r0=0;else var_r0=func_0207c8ec(temp_r0-1,10)+1;
 M2C_FIELD(arg0,s16*,0x16)=M2C_FIELD(arg0,s16*,0x16)+func_0207c8ec(M2C_FIELD(arg0,s16*,6)*var_r0,10);
 M2C_FIELD(arg0,s16*,0x14)=M2C_FIELD(arg0,s16*,0x18);
 if(arg1==1)var_r4+=func_020d18e8(arg0);
 M2C_FIELD(arg0,s16*,0x14)=func_0207c8ec(M2C_FIELD(arg0,s16*,0x14)*var_r4,100);
 M2C_FIELD(arg0,s16*,0x1c)=M2C_FIELD(arg0,s16*,0x14);
 func_020d0bac(arg0,arg2);
 if(M2C_FIELD(arg0,s16*,0x14)<0)M2C_FIELD(arg0,s16*,0x14)=0;
}

void func_020d0bac(void *p,s32 a) {
 extern u8 data_02168f08[];
 if(((u32)M2C_FIELD(data_02168f08,u16*,12)<<20)>>31)return;
 if(a!=0) {
 if(M2C_FIELD(p,s16*,0x14)!=0) {
 s32 t=((s32 (*)(M2C_UNK))func_020d0bf8)(M2C_FIELD(p,M2C_UNK*,0));
 M2C_FIELD(p,s16*,0x14)=M2C_FIELD(p,s16*,0x14)+t;
 }
 }
}

void func_020d0bf8(M2C_UNK arg0) {
    M2C_UNK RandomIntRange(s32, s32);
    s32 func_020a78fc();
    s32 func_020a7914(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_020a78fc();
    RandomIntRange(func_020a7914(arg0), temp_r4);
}

void func_020d0c1c(void *a,void *b) {
u32 n=(u32)(M2C_FIELD(M2C_FIELD(b,void **,0),u16 *,6)<<25)>>25;
s32 x;
if(n==0)x=0;else x=func_0207c8ec(n-1,10)+1;
M2C_FIELD(b,s16 *,0x1c)=func_0207c8ec(M2C_FIELD(b,s16 *,0x1c)*x,10);
if(M2C_FIELD(a,s16 *,0x16)==0)x=999;
else x=func_0207c8ec(M2C_FIELD(b,s16 *,0x1c)*100,M2C_FIELD(a,s16 *,0x16));
M2C_FIELD(b,s16 *,0x1c)=x;
if(M2C_FIELD(b,s16 *,0x1c)>=999)M2C_FIELD(b,s16 *,0x1c)=999;
if(M2C_FIELD(a,s16 *,0x16)==0)x=999;
else x=func_0207c8ec(M2C_FIELD(b,s16 *,0x14)*100,M2C_FIELD(a,s16 *,0x16));
M2C_FIELD(a,s16 *,0x1a)=x;
M2C_FIELD(a,s16 *,0xe)=((u32)(M2C_FIELD(M2C_FIELD(a,void **,0),u16 *,6)<<25)>>25)-M2C_FIELD(a,s16 *,0x1a);
}

void func_020d0cdc(void *arg0, void *arg1) {
    
    s16 var_r0_2;
    s32 var_r0;
    s32 var_r0_3;
    u32 temp_r0;

    temp_r0 = (u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 6) << 0x19) >> 0x19;
    if (temp_r0 == 0) {
        var_r0 = 0;
    } else {
        var_r0 = func_0207c8ec(temp_r0 - 1, 0xA) + 1;
    }
    M2C_FIELD(arg0, s16 *, 0x14) = func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x14) * var_r0, 0xA);
    func_020d0c1c(arg1, arg0);
    var_r0_2 = M2C_FIELD(arg1, s16 *, 0xE);
    if ((s32) var_r0_2 < 0) {
        var_r0_2 = 0;
    }
    if (var_r0_2 == 0) {
        var_r0_3 = 0;
    } else {
        var_r0_3 = func_0207c8ec(var_r0_2 - 1, 0xA) + 1;
    }
    M2C_FIELD(arg1, s16 *, 0x14) = func_0207c8ec(M2C_FIELD(arg1, s16 *, 0x14) * var_r0_3, 0xA);
    func_020d0c1c(arg0, arg1);
}

void func_020d0d7c(void *arg0, void *arg1) {
    s16 temp_r2;
    s16 temp_r3;

    temp_r3 = M2C_FIELD(arg0, s16 *, 0xE);
    if ((s32) temp_r3 <= 0) {
        temp_r2 = M2C_FIELD(arg1, s16 *, 0xE);
        if ((s32) temp_r2 <= 0) {
            if ((s32) temp_r3 < (s32) temp_r2) {
                M2C_FIELD(arg1, s16 *, 0xE) = 1;
                M2C_FIELD(arg0, s16 *, 0xE) = 0;
                return;
            }
            M2C_FIELD(arg0, s16 *, 0xE) = 1;
            M2C_FIELD(arg1, s16 *, 0xE) = 0;
            return;
        }
    }
    if ((s32) temp_r3 < 0) {
        M2C_FIELD(arg0, s16 *, 0xE) = 0;
    }
    if ((s32) M2C_FIELD(arg1, s16 *, 0xE) < 0) {
        M2C_FIELD(arg1, s16 *, 0xE) = 0;
    }
}

s32 func_020d0ddc(void) {
    return 0;
}

void func_020d1034(void *arg0) {
    s32 func_0207c8ec(s32, M2C_UNK);
    M2C_UNK func_020a6328(void *, s32);
    s16 temp_r0;
    s32 var_r1;
    s32 var_r5;
    u32 temp_r0_2;

    temp_r0 = M2C_FIELD(arg0, s16 *, 0xE);
    if (temp_r0 == 0) {
        var_r5 = 0;
    } else {
        var_r5 = func_0207c8ec(temp_r0 - 1, 0xA) + 1;
    }
    temp_r0_2 = (u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 6) << 0x19) >> 0x19;
    if (temp_r0_2 == 0) {
        var_r1 = 0;
    } else {
        var_r1 = func_0207c8ec(temp_r0_2 - 1, 0xA) + 1;
    }
    func_020a6328(M2C_FIELD(arg0, void **, 0), var_r1 - var_r5);
}

void func_020d1094(s32 a,s32 b){
void func_020b576c(void *);s32 func_020cd614(void);s32 func_020cd5d8(void);void func_020b5594(s32,s32,s32,s32);
void *p=M2C_FIELD(a,void **,0);s32 k;
M2C_FIELD(p,u16 *,6)=(M2C_FIELD(p,u16 *,6)&~127)|(M2C_FIELD(a,u16 *,14)&127);
M2C_FIELD(p,u16 *,6)=(M2C_FIELD(p,u16 *,6)&~0x780)|((u32)(M2C_FIELD(a,u16 *,16)<<28)>>21);
if(M2C_FIELD(a,s16 *,14)<=0){func_020b576c(p);return;}
if(!b)return;if(func_020cd614())return;if(M2C_FIELD(a,s16 *,8)-M2C_FIELD(a,s16 *,14)==0)return;
if(M2C_FIELD(b,s16 *,14)<=0)return;if(!func_020cd5d8())return;
k=D068CLow(M2C_FIELD(b,void **,0));
if(k==1)goto special;if(k==2)goto special;if(k==3)goto special;goto normal;special:func_020b5594(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),7,7);
return;normal:func_020b5594(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),6,7);
}

void func_020d1174(u8 *a) {
extern s32 *gCurrentMap;
func_02091c20(((u32)(a[0]<<26)>>26)+0x43,1);
if(a[12])func_020d1174((u8 *)(*gCurrentMap+0x59a4)+a[12]*14);
if(a[13])func_020d1174((u8 *)(*gCurrentMap+0x59a4)+a[13]*14);
}

void func_020d1644(void) {

    extern s32 *gCurrentMap;
    func_020d1094(*gCurrentMap + 0x6EB8, 0);
}

