/* 12 functions from 0x020411DC to 0x020420A0 (main), found by ds-decomp. */
#include "common.h"
void *func_02044268();
void func_02041e44(void);

s32 func_0204183c(s32 *p,u32 n) {
 s32 func_020428bc();
 u32 i;
 if(M2C_FIELD(func_02044268(),u8*,0x1a6)!=0 && M2C_FIELD(func_02044268(),s32*,0x1a0)==4)return 1;
 for(i=0;i<n;i++) {
 if(!func_020428bc(p[i]))return 0;
 if(M2C_FIELD(func_02044268(),u8*,0x1a6)!=0 && M2C_FIELD(func_02044268(),s32*,0x1a0)==1)return 1;
 }return 1;
}

void func_02041a4c(void) {
 extern s32 data_020fc904;
 s32 func_02042f94(); s32 func_0203aeb4();
 s32 a,b,c; void *p;
 func_0203af50(1,&data_020fc904,0);
 if(func_02042f94())return;
 func_0203e9b0();
 if(M2C_FIELD(func_02044268(),s32*,0x20c)!=0)a=1; else a=M2C_FIELD(func_02044268(),u8*,0x15)==2;
 b=M2C_FIELD(func_02044268(),s32*,0x20c)==0;
 p=func_02044268();
 c=func_0203aeb4(M2C_FIELD(func_02044268(),s32*,0x20c));
 ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void**,0x464))(0,1,b,a,c,M2C_FIELD(func_02044268(),s32*,0x468));
 M2C_FIELD(func_02044268(),u8*,0x1a9)=0;
}

s32 func_02041b0c(void) {
s32 func_0203f058();
s32 r=0;
s32 local=0;
void *a,*b,*c,*d;
if(M2C_FIELD(func_02044268(),u8*,0x17)!=0 && M2C_FIELD(func_02044268(),s32*,0x20)!=0) {
a=func_02044268();
if(M2C_FIELD(a,s32*,0x20)!=M2C_FIELD(func_02044268(),s32*,0x200)) {
a=func_02044268();
b=func_02044268();
c=func_02044268();
d=func_02044268();
r=func_0203f058(12,M2C_FIELD(a,s32*,0x20),M2C_FIELD((u8*)b+4*(M2C_FIELD(c,u8*,0xd)+1),s32*,0x24),M2C_FIELD((u8*)d+2*(M2C_FIELD(func_02044268(),u8*,0xd)+1),u16*,0xa4),&local,1);
M2C_FIELD(func_02044268(),u8*,0x17)=0;
M2C_FIELD(func_02044268(),s32*,0x20)=0;
}
}
return r;
}

/* Handle a connection state refresh: if the active mode is 2/3, invoke the mode callback; if mode 0, run the next connection step; if mode 1 with refresh requested, start a contextual action. */
void func_02041be0(s32 refresh) {
    s32 func_0203aeb4(); s32 func_02043008();
    s32 b,c; void *p;
    if(refresh==0){func_02041a4c();return;}
    func_0203e570();
    if(M2C_FIELD(func_02044268(),u8*,0x15)==2 || M2C_FIELD(func_02044268(),u8*,0x15)==3) {
        b=M2C_FIELD(func_02044268(),s32*,0x20c)==0;
        p=func_02044268();
        c=func_0203aeb4(M2C_FIELD(func_02044268(),s32*,0x20c));
        ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void**,0x464))(0,1,b,0,c,M2C_FIELD(func_02044268(),s32*,0x468));
    } else if(M2C_FIELD(func_02044268(),u8*,0x15)==0) {
        if(refresh==1){func_0203ea4c(0);if(func_02043008())return;}
    } else if(M2C_FIELD(func_02044268(),u8*,0x15)==1 && refresh==1)func_02040a28(0,0,0);
}

void func_02041ce0(void) {
 if(M2C_FIELD(func_02044268(),u8*,0x15)==2)return;
 if(M2C_FIELD(func_02044268(),u8*,0x15)==3)return;
 func_02041e44();func_02041be0(1);
}

s32 func_02041d14(void) {
 s32 func_0203ea4c(); s32 func_02043008(); s32 func_02040878(); s32 func_0204084c();
 s32 r;
 M2C_FIELD(func_02044268(),u8*,0x17)=0;
 M2C_FIELD(func_02044268(),s32*,0x20)=0;
 M2C_FIELD(func_02044268(),u8*,0x1a8)=0;
 if(M2C_FIELD(func_02044268(),s32*,0x208)!=0) {
 if(M2C_FIELD(func_02044268(),u8*,0x15)==0) {
 func_02044278(3);r=func_0203ea4c(0);if(func_02043008())return r;
 } else if(M2C_FIELD(func_02044268(),u8*,0x15)==1) {
 func_02044278(4);r=func_02040878(M2C_FIELD(func_02044268(),s32*,0x208),0);if(func_0204084c())return r;
 }
 }else func_02041be0(1);
 return 0;
}

s32 func_02041dd4(s32 arg0) {
 s32 *func_02039140();
 s32 *p;
 M2C_FIELD(func_02044268(),s32*,0x20c)=arg0;
 p=func_02039140(arg0,M2C_FIELD(func_02044268(),u8*,0xd)+1);
 if(p!=0) {
 M2C_FIELD(func_02044268(),u8*,0x1a8)=2;
 func_0205afcc(*p);
 M2C_FIELD(func_02044268(),u8*,0x1a8)=0;
 return 1;
 }
 func_0203e088(arg0,M2C_FIELD(func_02044268(),u8*,0xd)+1);
 return 0;
}

void func_02041e44(void) {
    void *func_02044268();
    M2C_UNK func_0205afec(s32);
    M2C_FIELD(func_02044268(), s8 *, 0x1A8) = 2;
    func_0205afec(*M2C_FIELD(func_02044268(), s32 **, 4));
    M2C_FIELD(func_02044268(), s8 *, 0x1A8) = 0;
}

s32 func_02041e74(u32 mask) {
s32 func_0203f058(); s32 func_0204084c(); s32 func_02042a08();
s32 other[32],selected[32]; s32 n=0,m=0; register s32 i; s32 r;
for(i=1;i<=M2C_FIELD(func_02044268(),u8*,0xd);i++){
if(mask & (1<<M2C_FIELD((u8*)func_02044268()+i,u8*,0x2d0))){
selected[m]=M2C_FIELD((u8*)func_02044268()+((u32)i<<2),s32*,0xf4);m++;
}else {other[n]=M2C_FIELD((u8*)func_02044268()+((u32)i<<2),s32*,0xf4);n++;}
}
for(i=0;i<m;i++){
func_0203f058(16,selected[i],0,0,other,n);
if(func_0204084c())return 0;
}
M2C_FIELD(func_02044268(),u8*,0x1a8)=2;
for(i=0;i<n;i++){r=func_02042a08(other[i],0);if(r!=255)func_02038de4();}
M2C_FIELD(func_02044268(),u8*,0x1a8)=0;
return 1;
}

/* Prepare and send a 4-byte notification packet (type 2 or 3) about a player slot, then timestamp the connection state. */
void func_02041fb0(s8 arg0, s32 arg1) {
    u64 func_02007004(void);
    void func_0204433c(s32, s8, void *, s32);
    u8 buf[4];
    u8 i;
    void *p;
    switch (arg1) {
    case 2:
        p = func_02044268();
        if (arg0 == M2C_FIELD((u8 *)p + M2C_FIELD(func_02044268(), u8 *, 0xd), u8 *, 0x2d0))
            buf[0] = 1;
        else
            buf[0] = 0;
        for (i = 1; i <= M2C_FIELD(func_02044268(), u8 *, 0xd); i++) {
            if (arg0 == M2C_FIELD((u8 *)func_02044268() + i, u8 *, 0x2d0)) {
                buf[1] = i;
                buf[2] = arg0;
                break;
            }
        }
        break;
    case 3:
        buf[0] = M2C_FIELD(func_02044268(), u16 *, 0x1b0);
        buf[1] = (s32)M2C_FIELD(func_02044268(), u16 *, 0x1b0) >> 8;
        break;
    }
    func_0204433c(arg1, arg0, buf, 4);
    p = func_02044268();
    M2C_FIELD(p, u64 *, 0x1e0) = func_02007004();
}

