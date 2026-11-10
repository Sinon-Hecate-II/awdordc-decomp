/* 12 functions from 0x020411DC to 0x020420A0 (main), found by ds-decomp. */
#include "common.h"
void *GetConnection();
void func_02041e44(void);

void func_020411dc(s32 arg0){
extern s32 data_020fc904;extern u8 gConnectionMgr[];
s32 SetConnectionState(s32);void func_0205ea70(s32);void SendConnectionPacket(s8,s32);u64 func_02007004(void);void TryConnectToPeer(s32,s32,s32);u32 GetConnectedPlayerMask(s32);void func_02041ce0(void);s32 func_0203f058();s32 func_0204084c(void);void func_02042ad0(void);void func_0203af50(s32,void *,s32);s32 func_0203aeb4(s32);void func_0203e9b0(void);void func_020614b0(s32);void func_0203bd0c(void);void func_0203e410(void);s32 func_02042f94(void);void func_02061738(s32);
s32 n=3,update=0; s32 values[5];s32 b,c;u8 *a,*d,*e,*f,*g,*h;s32 i;
switch(arg0){
case 0:
a=GetConnection();if(M2C_FIELD(a,u8*,420)<M2C_FIELD(GetConnection(),u8*,13)-1){
SetConnectionState(13);
a=GetConnection();values[0]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1)*4,s32*,244);
values[1]=M2C_FIELD(GetConnection(),u8*,420)+1;
a=GetConnection();values[2]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1),u8*,720);
a=GetConnection();values[3]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1)*4,s32*,36);
a=GetConnection();values[4]=M2C_FIELD(a+(M2C_FIELD(GetConnection(),u8*,420)+1)*2,u16*,164);n=5;
}else{
M2C_FIELD(GetConnection(),u8*,23)=0;M2C_FIELD(GetConnection(),s32*,32)=0;func_0205ea70(M2C_FIELD(GetConnection(),s32*,16));
if(M2C_FIELD(GetConnection(),u8*,21)==0)SetConnectionState(n);else if(M2C_FIELD(GetConnection(),u8*,21)==1)SetConnectionState(4);else SetConnectionState(10);
M2C_FIELD(GetConnection(),u8*,420)=0;
a=0;if(M2C_FIELD(GetConnection(),u8*,21)==2)goto complete;
a=GetConnection();if(M2C_FIELD(a,u8*,13)==M2C_FIELD(GetConnection(),u8*,22)){
complete:
if(M2C_FIELD(GetConnection(),u8*,21)==2){a=GetConnection();d=GetConnection();M2C_FIELD(a,s32*,524)=M2C_FIELD(d+M2C_FIELD(GetConnection(),u8*,13)*4,s32*,244);}else{M2C_FIELD(GetConnection(),s32*,524)=0;a=GetConnection();M2C_FIELD(a,s32*,244)=M2C_FIELD(GetConnection(),s32*,512);}
SetConnectionState(16);M2C_FIELD(GetConnection(),s32*,468)=0;for(i=1;i<=M2C_FIELD(GetConnection(),u8*,13);i++)((void (*)(u32,s32))SendConnectionPacket)(M2C_FIELD((u8 *)GetConnection()+i,u8*,720),2);
}else{
values[0]=0;values[1]=M2C_FIELD(GetConnection(),u8*,13);a=GetConnection();values[2]=M2C_FIELD(a+M2C_FIELD(GetConnection(),u8*,13),u8*,720);
if(M2C_FIELD(GetConnection(),u8*,21)==0){M2C_FIELD(GetConnection(),s32*,232)=2;a=GetConnection();M2C_FIELD(a,u64*,236)=func_02007004();}
else if(M2C_FIELD(GetConnection(),u8*,21)==1){TryConnectToPeer(1,0,0);if(M2C_FIELD(GetConnection(),u8*,422)==0&&M2C_FIELD(GetConnection(),u8*,13)>=2){a=GetConnection();b=GetConnectedPlayerMask(0);d=GetConnection();if(M2C_FIELD(a,u32*,476)!=(b&~(1<<M2C_FIELD(d+M2C_FIELD(GetConnection(),u8*,13),u8*,720)))){func_02041ce0();break;}}}
}
if(M2C_FIELD(GetConnection(),u8*,21)!=2)update=1;
}
if(M2C_FIELD(GetConnection(),s32*,416)!=16){a=GetConnection();d=GetConnection();e=GetConnection();f=GetConnection();g=GetConnection();h=GetConnection();
func_0203f058(8,M2C_FIELD(a+M2C_FIELD(d,u8*,13)*4,s32*,244),M2C_FIELD(e+M2C_FIELD(f,u8*,13)*4,s32*,36),M2C_FIELD(g+M2C_FIELD(h,u8*,13)*2,u16*,164),values,n);
if(func_0204084c())return;M2C_FIELD(GetConnection(),u8*,973)=0;}break;
case 1:SetConnectionState(1);if(M2C_FIELD(GetConnection(),u8*,21)==3){a=GetConnection();d=GetConnection();M2C_FIELD(a,s32*,524)=M2C_FIELD(d+M2C_FIELD(GetConnection(),u8*,13)*4,s32*,244);}update=1;break;
case 2:SetConnectionState(1);if(M2C_FIELD(GetConnection(),u8*,21)==0||M2C_FIELD(GetConnection(),u8*,21)==1){M2C_FIELD(GetConnection(),u8*,23)=1;a=GetConnection();M2C_FIELD(a,s32*,32)=M2C_FIELD(GetConnection(),s32*,512);}
func_02042ad0();if(M2C_FIELD(GetConnection(),u8*,13)>1){a=GetConnection();d=GetConnection();e=GetConnection();f=GetConnection();g=GetConnection();func_0203f058(9,M2C_FIELD(a,s32*,244),M2C_FIELD(d,s32*,36),M2C_FIELD(e,u16*,164),f+244+(M2C_FIELD(g,u8*,13)-1)*4,1);if(func_0204084c())return;}break;
case 3:SetConnectionState(1);func_02042ad0();M2C_FIELD(GetConnection(),s32*,524)=0;update=1;break;
case 4:if(M2C_FIELD(GetConnection(),u8*,21)!=2)func_0203af50(2,&data_020fc904,0);
b=M2C_FIELD(GetConnection(),s32*,524)==0;a=GetConnection();c=func_0203aeb4(M2C_FIELD(GetConnection(),s32*,524));d=GetConnection();
((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(a,void **,1124))(0,0,b,0,c,M2C_FIELD(d,s32*,1128));
if(M2C_FIELD(GetConnection(),u8*,21)==0||M2C_FIELD(GetConnection(),u8*,21)==1){func_0203e9b0();}else{
if(M2C_FIELD(GetConnection(),s32*,228)!=0){func_020614b0(M2C_FIELD(GetConnection(),s32*,228));M2C_FIELD(GetConnection(),s32*,228)=0;}
func_0203bd0c();if(M2C_FIELD(GetConnection(),u8*,21)==2){func_0203e410();if(func_02042f94())return;if(gConnectionMgr[28]==1)gConnectionMgr[29]=1;SetConnectionState(10);}else SetConnectionState(1);M2C_FIELD(GetConnection(),s32*,524)=0;
}M2C_FIELD(GetConnection(),u8*,425)=0;break;
}
if(update&&M2C_FIELD(GetConnection(),u8*,21)!=3)func_02061738(M2C_FIELD(GetConnection(),s32*,228));
}

s32 func_0204183c(s32 *p,u32 n) {
 s32 IsConnectionMember();
 u32 i;
 if(M2C_FIELD(GetConnection(),u8*,0x1a6)!=0 && M2C_FIELD(GetConnection(),s32*,0x1a0)==4)return 1;
 for(i=0;i<n;i++) {
 if(!IsConnectionMember(p[i]))return 0;
 if(M2C_FIELD(GetConnection(),u8*,0x1a6)!=0 && M2C_FIELD(GetConnection(),s32*,0x1a0)==1)return 1;
 }return 1;
}

void func_020418c4(void) {
    void *GetConnection(void);
    void func_02041a4c(void);
    s32 func_02041b0c(void);
    M2C_UNK func_0205afec(s32);
    void func_0205df50(s32);
    s32 func_02040dc8(M2C_UNK);
    s32 func_0204084c(void);

    M2C_FIELD(GetConnection(), s32 *, 0x20c) = 0;
    if (M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 2) {
        func_02041a4c();
        return;
    }
    M2C_FIELD(GetConnection(), u8 *, 0x1a9) = 1;
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 3) {
        M2C_FIELD(GetConnection(), u8 *, 0x1a9) = 1;
        if (M2C_FIELD(GetConnection(), u8 *, 0xd) != 0) {
            func_0205afec(*M2C_FIELD(GetConnection(), s32 **, 0x4));
        } else {
            func_02040dc8(M2C_FIELD(GetConnection(), s32 *, 0xf4));
            if (((s32 (*)())func_0204084c)() != 0) return;
        }
        func_02041a4c();
        return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 4 ||
        M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 5 ||
        M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 6 ||
        M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 7 ||
        M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 0xb ||
        M2C_FIELD(GetConnection(), s32 *, 0x1a0) == 0xc) {
        if (M2C_FIELD(GetConnection(), s32 *, 0x204) != 0) {
            func_02040dc8(M2C_FIELD(GetConnection(), s32 *, 0xf4));
            if (((s32 (*)())func_0204084c)() != 0) return;
        }
        func_02041b0c();
        if (((s32 (*)())func_0204084c)() != 0) return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, 0x19c) != 0) {
        func_0205df50(M2C_FIELD(GetConnection(), s32 *, 0x19c));
        M2C_FIELD(GetConnection(), s32 *, 0x19c) = 0;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0xd) != 0) {
        M2C_FIELD(GetConnection(), u8 *, 0x1a9) = 1;
        func_0205afec(*M2C_FIELD(GetConnection(), s32 **, 0x4));
    }
    func_02041a4c();
}

void func_02041a4c(void) {
 extern s32 data_020fc904;
 s32 func_02042f94(); s32 func_0203aeb4();
 s32 a,b,c; void *p;
 func_0203af50(1,&data_020fc904,0);
 if(func_02042f94())return;
 func_0203e9b0();
 if(M2C_FIELD(GetConnection(),s32*,0x20c)!=0)a=1; else a=M2C_FIELD(GetConnection(),u8*,0x15)==2;
 b=M2C_FIELD(GetConnection(),s32*,0x20c)==0;
 p=GetConnection();
 c=func_0203aeb4(M2C_FIELD(GetConnection(),s32*,0x20c));
 ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void**,0x464))(0,1,b,a,c,M2C_FIELD(GetConnection(),s32*,0x468));
 M2C_FIELD(GetConnection(),u8*,0x1a9)=0;
}

s32 func_02041b0c(void) {
s32 func_0203f058();
s32 r=0;
s32 local=0;
void *a,*b,*c,*d;
if(M2C_FIELD(GetConnection(),u8*,0x17)!=0 && M2C_FIELD(GetConnection(),s32*,0x20)!=0) {
a=GetConnection();
if(M2C_FIELD(a,s32*,0x20)!=M2C_FIELD(GetConnection(),s32*,0x200)) {
a=GetConnection();
b=GetConnection();
c=GetConnection();
d=GetConnection();
r=func_0203f058(12,M2C_FIELD(a,s32*,0x20),M2C_FIELD((u8*)b+4*(M2C_FIELD(c,u8*,0xd)+1),s32*,0x24),M2C_FIELD((u8*)d+2*(M2C_FIELD(GetConnection(),u8*,0xd)+1),u16*,0xa4),&local,1);
M2C_FIELD(GetConnection(),u8*,0x17)=0;
M2C_FIELD(GetConnection(),s32*,0x20)=0;
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
    if(M2C_FIELD(GetConnection(),u8*,0x15)==2 || M2C_FIELD(GetConnection(),u8*,0x15)==3) {
        b=M2C_FIELD(GetConnection(),s32*,0x20c)==0;
        p=GetConnection();
        c=func_0203aeb4(M2C_FIELD(GetConnection(),s32*,0x20c));
        ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void**,0x464))(0,1,b,0,c,M2C_FIELD(GetConnection(),s32*,0x468));
    } else if(M2C_FIELD(GetConnection(),u8*,0x15)==0) {
        if(refresh==1){func_0203ea4c(0);if(func_02043008())return;}
    } else if(M2C_FIELD(GetConnection(),u8*,0x15)==1 && refresh==1)TryConnectToPeer(0,0,0);
}

void func_02041ce0(void) {
 if(M2C_FIELD(GetConnection(),u8*,0x15)==2)return;
 if(M2C_FIELD(GetConnection(),u8*,0x15)==3)return;
 func_02041e44();func_02041be0(1);
}

s32 func_02041d14(void) {
 s32 func_0203ea4c(); s32 func_02043008(); s32 func_02040878(); s32 func_0204084c();
 s32 r;
 M2C_FIELD(GetConnection(),u8*,0x17)=0;
 M2C_FIELD(GetConnection(),s32*,0x20)=0;
 M2C_FIELD(GetConnection(),u8*,0x1a8)=0;
 if(M2C_FIELD(GetConnection(),s32*,0x208)!=0) {
 if(M2C_FIELD(GetConnection(),u8*,0x15)==0) {
 SetConnectionState(3);r=func_0203ea4c(0);if(func_02043008())return r;
 } else if(M2C_FIELD(GetConnection(),u8*,0x15)==1) {
 SetConnectionState(4);r=func_02040878(M2C_FIELD(GetConnection(),s32*,0x208),0);if(func_0204084c())return r;
 }
 }else func_02041be0(1);
 return 0;
}

s32 func_02041dd4(s32 arg0) {
 s32 *func_02039140();
 s32 *p;
 M2C_FIELD(GetConnection(),s32*,0x20c)=arg0;
 p=func_02039140(arg0,M2C_FIELD(GetConnection(),u8*,0xd)+1);
 if(p!=0) {
 M2C_FIELD(GetConnection(),u8*,0x1a8)=2;
 func_0205afcc(*p);
 M2C_FIELD(GetConnection(),u8*,0x1a8)=0;
 return 1;
 }
 func_0203e088(arg0,M2C_FIELD(GetConnection(),u8*,0xd)+1);
 return 0;
}

void func_02041e44(void) {
    void *GetConnection();
    M2C_UNK func_0205afec(s32);
    M2C_FIELD(GetConnection(), s8 *, 0x1A8) = 2;
    func_0205afec(*M2C_FIELD(GetConnection(), s32 **, 4));
    M2C_FIELD(GetConnection(), s8 *, 0x1A8) = 0;
}

s32 func_02041e74(u32 mask) {
s32 func_0203f058(); s32 func_0204084c(); s32 func_02042a08();
s32 other[32],selected[32]; s32 n=0,m=0; register s32 i; s32 r;
for(i=1;i<=M2C_FIELD(GetConnection(),u8*,0xd);i++){
if(mask & (1<<M2C_FIELD((u8*)GetConnection()+i,u8*,0x2d0))){
selected[m]=M2C_FIELD((u8*)GetConnection()+((u32)i<<2),s32*,0xf4);m++;
}else {other[n]=M2C_FIELD((u8*)GetConnection()+((u32)i<<2),s32*,0xf4);n++;}
}
for(i=0;i<m;i++){
func_0203f058(16,selected[i],0,0,other,n);
if(func_0204084c())return 0;
}
M2C_FIELD(GetConnection(),u8*,0x1a8)=2;
for(i=0;i<n;i++){r=func_02042a08(other[i],0);if(r!=255)func_02038de4();}
M2C_FIELD(GetConnection(),u8*,0x1a8)=0;
return 1;
}

/* Prepare and send a 4-byte notification packet (type 2 or 3) about a player slot, then timestamp the connection state. */
void SendConnectionPacket(s8 arg0, s32 arg1) {
    u64 func_02007004(void);
    void func_0204433c(s32, s8, void *, s32);
    u8 buf[4];
    u8 i;
    void *p;
    switch (arg1) {
    case 2:
        p = GetConnection();
        if (arg0 == M2C_FIELD((u8 *)p + M2C_FIELD(GetConnection(), u8 *, 0xd), u8 *, 0x2d0))
            buf[0] = 1;
        else
            buf[0] = 0;
        for (i = 1; i <= M2C_FIELD(GetConnection(), u8 *, 0xd); i++) {
            if (arg0 == M2C_FIELD((u8 *)GetConnection() + i, u8 *, 0x2d0)) {
                buf[1] = i;
                buf[2] = arg0;
                break;
            }
        }
        break;
    case 3:
        buf[0] = M2C_FIELD(GetConnection(), u16 *, 0x1b0);
        buf[1] = (s32)M2C_FIELD(GetConnection(), u16 *, 0x1b0) >> 8;
        break;
    }
    func_0204433c(arg1, arg0, buf, 4);
    p = GetConnection();
    M2C_FIELD(p, u64 *, 0x1e0) = func_02007004();
}

