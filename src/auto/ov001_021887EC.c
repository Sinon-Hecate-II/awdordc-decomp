/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_0219169c;
extern M2C_UNK data_ov001_0219166c, data_ov001_02191684, data_ov001_021916cc;

#pragma peephole off

#pragma peephole reset

/* Initialize the active map state pointed to by the global from the allocated buffer p and the config a. */

void func_ov001_021887ec(void *arg0) {
    M2C_UNK SystemHalt();
    if (M2C_FIELD(arg0, u16 *, 2) != 8) {
        return;
    }
    func_ov001_02187b14(9);
    SystemHalt();
}

s32 func_ov001_0218880c(void) {
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK func_ov001_02188858;
s32 func_02012218(void *,void *,s32);
func_ov001_02187b14(3);
if(func_02012218((u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 4)+0x80,&func_ov001_02188858,2)==2) return 1;
func_ov001_02187b90();
func_ov001_02187b14(10);
return 0;
}

void func_ov001_02188858(void *arg0){
s32 func_020119dc(void *);
if(M2C_FIELD(arg0,u16 *,2)){func_ov001_02187b90();func_ov001_02187b14(10);return;}
if(func_020119dc((void *)func_ov001_021887ec)){func_ov001_02187b90();func_ov001_02187b14(10);return;}
func_ov001_02187b14(1);
}

s32 func_ov001_021888a8(s32 a,s32 b,s32 c){
s32 func_ov001_02187bb0();
do{
if(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,64)!=1){
SystemHalt();
}
}while(0);
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,4772)=384;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,4768)=224;
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0)(0x8000000,&data_ov001_0219166c,M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,4772));
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0)(0x8000000,&data_ov001_02191684,M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,4768));
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,68)=a;func_ov001_02187b14(3);
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,12)=b;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,50)=c;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,24)=func_02011e08();
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,52)=208;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,54)=68;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,16)=2;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,22)=0;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,18)=0;M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,14)=1;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,20)=a==2;
if(a==0||a==2||a==4)return func_ov001_02187bb0();
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0)(0x8000000,&data_ov001_021916cc,a);
return 0;
}

void func_ov001_02188a20(s32 arg0) {
    extern M2C_UNK data_ov001_02193e20;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x4C) = arg0;
}

void func_ov001_02188a34(s32 arg0) {
extern M2C_UNK data_ov001_02193e20;
void func_02013aa8(void *, void *, s32);
func_02013aa8((u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 4)+0x13E0,(u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 4)+0x1C00,arg0);
}

s32 func_ov001_02188a5c(void *arg0){
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_021916e8;
extern M2C_UNK data_ov001_02191718;
s32 func_02013248(void *,void *,void *);
s32 result=func_02013248((u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x13e0,arg0,(u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x1c00);
if(result==7){
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0)(0x8000000,&data_ov001_021916e8);
return 0;}
if(result==5){
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0)(0x8000000,&data_ov001_02191718);
func_ov001_02187b90(result);return 0;}
if(result==0)return 1;
func_ov001_02187b90();return 0;
}

void func_ov001_02188b04(void) {
    M2C_UNK func_ov001_02187b14(M2C_UNK);
    s32 func_ov001_021882e0();
    if (func_ov001_021882e0() != 0) {
        return;
    }
    func_ov001_02187b14(0xA);
}

void func_ov001_02188b20(void) {
extern M2C_UNK data_ov001_0219174c;
extern M2C_UNK data_ov001_02191770;
s32 func_ov001_021881d0(void); s32 func_ov001_02188220(void); s32 func_ov001_021880d0(void); s32 func_ov001_02188100(void);
s32 state=M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40);
if(state==1) {
void (*cb1)(s32,void *)=M2C_FIELD(&data_ov001_02193e20,void (* volatile *)(s32,void *),0); if(cb1) cb1(0x8000000,&data_ov001_0219174c);
} else {
void (*cb2)(s32,void *)=M2C_FIELD(&data_ov001_02193e20,void (* volatile *)(s32,void *),0); if(cb2) cb2(0x8000000,&data_ov001_02191770);
state=M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40);
if(state!=6 && state!=5 && state!=4){func_ov001_02187b14(3);func_ov001_02188b04();return;}
func_ov001_02187b14(3);
switch(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u32 *,0x44)){
case 3: if(!func_ov001_021881d0())func_ov001_02188b04();break;
case 1:case 5: if(!func_ov001_02188220())func_ov001_02188b04();break;
case 2: if(!func_ov001_021880d0())func_ov001_02188b04();break;
case 0:case 4: if(!func_ov001_02188100())func_ov001_02188b04();break;
}
}
}

s32 func_ov001_02188c28(void){
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK func_ov001_02188344;
s32 func_020122ac(void *);
if(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40)!=1)SystemHalt();
func_ov001_02187b14(3);
if(func_020122ac(&func_ov001_02188344)==2)return 1;
func_ov001_02187b14(9);return 0;
}

void func_ov001_02188c78(void *p, void *a) {
    extern void *gOv001ProfileState;
    void func_ov001_02186e40(void *);
    void func_02045eb4(void *);
    void *func_ov001_02184c60(void);
    gOv001ProfileState = p;
    func_ov001_02186e40((u8 *)p + 0xb00);
    M2C_FIELD(gOv001ProfileState, u16 *, 1608) = 0;
    M2C_FIELD(gOv001ProfileState, u16 *, 1610) = 0;
    M2C_FIELD(gOv001ProfileState, u8 *, 2704) = 1;
    M2C_FIELD(gOv001ProfileState, u8 *, 2705) = 1;
    M2C_FIELD(gOv001ProfileState, s32 *, 2716) = 0;
    func_ov001_02189828();
    M2C_FIELD(gOv001ProfileState, s32 *, 2740) = M2C_FIELD(a, s32 *, 0);
    M2C_FIELD(gOv001ProfileState, s32 *, 2744) = M2C_FIELD(a, s32 *, 4);
    M2C_FIELD(gOv001ProfileState, s32 *, 2748) = M2C_FIELD(a, s32 *, 8);
    M2C_FIELD(gOv001ProfileState, s32 *, 2752) = M2C_FIELD(a, s32 *, 12);
    M2C_FIELD(gOv001ProfileState, s32 *, 2756) = M2C_FIELD(a, s32 *, 16);
    M2C_FIELD(gOv001ProfileState, s32 *, 2760) = M2C_FIELD(a, s32 *, 20);
    M2C_FIELD(gOv001ProfileState, u8 *, 0xa92) = M2C_FIELD(a, u8 *, 24);
    M2C_FIELD(gOv001ProfileState, u8 *, 0xacc) = 2;
    GetSystemTick();
    func_02045eb4((u8 *)gOv001ProfileState + 0x64c);
    GetSystemTick();
    M2C_FIELD(gOv001ProfileState, void **, 0xaa4) = func_ov001_02184c60();
}

int func_ov001_02188d68(void) {
 extern void *gOv001ProfileState; void func_0201808c(void);
 unsigned int state=M2C_FIELD(gOv001ProfileState,u8 *,0xa90);
 if(state==1||state==20||state==23||state==26||state==29){
 M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=34;
 M2C_FIELD(gOv001ProfileState,u8 *,0xaac)=0;return 1;
 }
 if(state==4||state==5||state==6||state==13){
 if(state==4 && M2C_FIELD(gOv001ProfileState,u32 *,0xa98)<6)return 0;
 func_0201808c();
 M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=16;
 M2C_FIELD(gOv001ProfileState,u8 *,0xaac)=2;return 1;
 }
 if((u8)(state+247)<=1){M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=32;return 1;}
 if(state==12){M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=34;return 1;}
 return 0;
}

void func_ov001_02188e44(void) {
extern void *gOv001ProfileState;
func_ov001_0218836c(M2C_FIELD(gOv001ProfileState,s32 *,0xAC8));
M2C_FIELD(gOv001ProfileState,u8 *,0xA90)=1;
M2C_FIELD(gOv001ProfileState,u16 *,0x648)=func_02012084();
MI_CpuCopy8(M2C_FIELD(gOv001ProfileState,void **,0xAA4),(u8 *)gOv001ProfileState+0xA50,0x40);
M2C_FIELD(gOv001ProfileState,u8 *,0xA93)=0;
M2C_FIELD(gOv001ProfileState,s32 *,0x204)=0;
M2C_FIELD(gOv001ProfileState,u16 *,0x648)++;
}

s32 func_ov001_02188ec4(void) {
extern void *gOv001ProfileState;
u32 state=M2C_FIELD(gOv001ProfileState,u8 *,0xA90);
if(state!=1 && state!=26 && state!=29) return 0;
func_ov001_02188e44();func_ov001_02188774();
M2C_FIELD(gOv001ProfileState,u8 *,0xA90)=2;return 1;
}

s32 func_ov001_02188f0c(void){
extern void *gOv001ProfileState;
if(M2C_FIELD(gOv001ProfileState,u8 *,0xa90)!=5)return 0;
M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=6;
func_ov001_0218730c();return 1;
}

void func_ov001_02188f40(void) {
    s32 func_ov001_02188ec4(void);
    void func_ov001_02189318(void);
    void func_ov001_021893c0(void);
    void Ov001_UpdateLinkState(void);
    void func_ov001_0218959c(void);
    void Ov001_UpdateProfileTask(void);
    void func_ov001_021897a4(void);
    s32 func_ov001_021897bc(void);
    s32 Ov001_GetTaskStep(void);
    s32 func_ov001_02188c28(void);
    void func_ov001_02188b20(void);
    void func_0201808c(void);
    extern void *gOv001ProfileState;
#define G ((u8 *)gOv001ProfileState)
    u8 state = G[0xa90];

    switch (state) {
    case 0:
    case 1:
        return;
    case 2: {
        u8 r2 = G[0xaac];
        if (r2 == 1) {
            G[0xaac] = 0;
            func_ov001_02188ec4();
        } else if (r2 == 2) {
            G[0xaac] = 0;
            G[0xa90] = 0x22;
        }
        return;
    }
    case 3:
        func_ov001_02189318();
        return;
    case 4:
        func_ov001_021893c0();
        G[0xa90] = 4;
        return;
    case 5:
        (*(u32 *)(G + 0xa98))++;
        Ov001_UpdateLinkState();
        return;
    case 6:
    case 7:
        Ov001_UpdateLinkState();
        return;
    case 8:
        func_ov001_0218959c();
        return;
    case 9:
    case 10:
    case 11:
        Ov001_UpdateProfileTask();
        return;
    case 12:
        func_ov001_021897a4();
        return;
    case 13:
    case 14:
    case 15:
    case 16:
        return;
    case 17:
        *(u32 *)(G + 0xa9c) = 0;
        G[0xa90] = 0x11;
        return;
    case 18: {
        u32 old = *(u32 *)(G + 0xa9c);
        (*(u32 *)(G + 0xa9c))++;
        if (old <= 0x1e) return;
        func_ov001_021897bc();
        return;
    }
    case 19:
        func_0201808c();
        *(u32 *)(G + 0xa9c) = 0;
        G[0xa90] = 0x16;
        return;
    case 20: {
        u32 old = *(u32 *)(G + 0xa9c);
        (*(u32 *)(G + 0xa9c))++;
        if (old <= 0x1e) return;
        Ov001_GetTaskStep();
        return;
    }
    case 21:
        return;
    case 22:
        func_ov001_02188b20();
        *(u32 *)(G + 0xa9c) = 0;
        G[0xa90] = 0x16;
        return;
    case 23: {
        u32 old = *(u32 *)(G + 0xa9c);
        (*(u32 *)(G + 0xa9c))++;
        if (old <= 0x1e) return;
        Ov001_GetTaskStep();
        return;
    }
    case 24:
        return;
    case 25:
        func_ov001_02188b20();
        *(u32 *)(G + 0xa9c) = 0;
        G[0xa90] = 0x19;
        return;
    case 26: {
        u32 old = *(u32 *)(G + 0xa9c);
        (*(u32 *)(G + 0xa9c))++;
        if (old <= 0x1e) return;
        Ov001_GetTaskStep();
        return;
    }
    case 27:
        return;
    case 28:
        func_ov001_02188b20();
        *(u32 *)(G + 0xa9c) = 0;
        G[0xa90] = 0x1c;
        return;
    case 29: {
        u32 old = *(u32 *)(G + 0xa9c);
        (*(u32 *)(G + 0xa9c))++;
        if (old <= 0x1e) return;
        if (Ov001_GetTaskStep() == 1) {
            func_ov001_02188c28();
            G[0xa90] = 0x1d;
        } else {
            G[0xa90] = 0x1c;
        }
        return;
    }
    case 30:
        return;
    case 31: {
        u32 x = *(u32 *)(G + 0xa9c);
        u32 rem = x - (x / 18) * 18;
        if (rem != 1) return;
        if (x <= 0x37) return;
        func_ov001_02188b20();
        return;
    }
    case 32:
        return;
    case 33: {
        *(u32 *)(G + 0xa9c) = 0;
        G[0xa90] = 0x21;
        if (Ov001_GetTaskStep() == 1) {
            func_ov001_02188c28();
            G[0xa90] = 0x22;
        }
        return;
    }
    case 34: {
        u32 old = *(u32 *)(G + 0xa9c);
        (*(u32 *)(G + 0xa9c))++;
        if (old <= 0x1e) return;
        Ov001_GetTaskStep();
        return;
    }
    default:
        return;
    }
#undef G
}

void func_ov001_021892c4(u8 *arg0,u8 *arg1) {
extern void *gOv001ProfileState;
*arg0=M2C_FIELD(gOv001ProfileState,u8 *,0xA90);
if(M2C_FIELD(gOv001ProfileState,u8 *,0xA90)!=M2C_FIELD(gOv001ProfileState,u8 *,0xA91)) *arg1=1; else *arg1=0;
M2C_FIELD(gOv001ProfileState,u8 *,0xA91)=M2C_FIELD(gOv001ProfileState,u8 *,0xA90);
}

void func_ov001_02189308(void) {
    func_02013e98(1);
}

void func_ov001_02189318(void) { M2C_UNK SystemHalt(); extern void *gOv001ProfileState; s32 value; switch(Ov001_GetTaskStep()) { case 1: func_ov001_021883a8(); return; case 7: value=func_ov001_02188614(); M2C_FIELD(gOv001ProfileState,u16 *,0x64a)=value; M2C_FIELD(gOv001ProfileState,s32 *,0xa98)=0; M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=3;return; case 0: M2C_FIELD(gOv001ProfileState,s32 *,0xa98)=0; M2C_FIELD(gOv001ProfileState,u8 *,0xa90)=3;return; case 9: func_ov001_02188b04();return; case 3: break; default: SystemHalt();return; } }

void func_ov001_021893c0(void) {
    M2C_UNK func_ov001_02186e80(s32, u16);
    extern void *gOv001ProfileState;
    func_ov001_02186e80(M2C_FIELD(gOv001ProfileState, s32 *, 0xAC8), M2C_FIELD(gOv001ProfileState, u16 *, 0x648));
}
