/* 42 functions from 0x020C6CF8 to 0x020C7CD0 (main), found by ds-decomp. */
#include "common.h"

void func_020c6cf8(void) {
    M2C_UNK func_020d468c();
    M2C_UNK func_020c0784();
    M2C_UNK func_ov000_02199f50(s32, u8, s32, s32);
    extern void **data_027e0058;
    func_020d468c();
    func_020c0784();
    func_ov000_02199f50(0xA, M2C_FIELD(*data_027e0058, u8 *, 0x52D4), 0, 0);
}

void func_020c6d30(void) {
    M2C_UNK func_020d468c();
    M2C_UNK func_020c0784();
    M2C_UNK func_ov000_02199f50(s32, u8, s32, s32);
    extern void **data_027e0058;
    func_020d468c();
    func_020c0784();
    func_ov000_02199f50(0xB, M2C_FIELD(*data_027e0058, u8 *, 0x52D4), 0, 0);
}

void func_020c6d68(void) {
    M2C_UNK func_01ffb3d0(s32);
    M2C_UNK func_020cdeac(s16, s16, s32);
    M2C_UNK func_020cc7e0();
    M2C_UNK func_020c0784();
    extern void **data_027e0058;
    void *temp;
    void (*callback)(void);
    func_01ffb3d0(-1);
    temp = *data_027e0058;
    M2C_FIELD((u8 *)temp + M2C_FIELD(temp, s16 *, 0x52DE) * 4, u8 **, 0x52E8)[M2C_FIELD(temp, s16 *, 0x52DC)] = 1;
    temp = *data_027e0058;
    func_020cdeac(M2C_FIELD(temp, s16 *, 0x52DC), M2C_FIELD(temp, s16 *, 0x52DE), M2C_FIELD(temp, s32 *, 0x52D0));
    func_020cc7e0();
    func_020c0784();
    callback = M2C_FIELD(data_027e0058[1], void (**)(void), 0x3C);
    if (callback == NULL) return;
    callback();
}

void func_020c6dec(void) {
    M2C_UNK func_020c0784();
    M2C_UNK func_020bbd8c();
    func_020bbd8c();
    func_020c0784();
}

void func_020c6ffc(void) {
    M2C_UNK func_020d468c();
    M2C_UNK func_020c0784();
    M2C_UNK func_ov000_02199f50(s32, u8, s32, s32);
    extern void **data_027e0058;
    func_020d468c();
    func_020c0784();
    func_ov000_02199f50(0x16, M2C_FIELD(*data_027e0058, u8 *, 0x52D4), 0, 0);
}

s32 func_020c7034(void) {
    s32 func_020a2be0(u16);
    s32 func_020a32f4();
    M2C_UNK func_020a7310(s32);
    extern void **data_027e0058;
    void *temp_r4;
    temp_r4 = *data_027e0058;
    if (((u8 *)temp_r4)[M2C_FIELD(temp_r4, s16 *, 0x52DC) + M2C_FIELD((u8 *)temp_r4 + M2C_FIELD(temp_r4, s16 *, 0x52DE) * 2, u16 *, 0x3758)] != 0) {
        return 2;
    }
    func_020a7310(M2C_FIELD(temp_r4, s32 *, 0x52D0));
    if ((M2C_FIELD(temp_r4, s32 *, 0x52D0) == func_020a32f4()) && (func_020a2be0(M2C_FIELD(temp_r4, u16 *, 0x52A4)) != 0)) {
        return 0;
    }
    return 2;
}

void func_020c70b4(void) {
    M2C_UNK func_020d468c();
    M2C_UNK func_020c0784();
    M2C_UNK func_ov000_02199f50(s32, u8, s32, s32);
    extern void **data_027e0058;
    func_020d468c();
    func_020c0784();
    func_ov000_02199f50(0xE, M2C_FIELD(*data_027e0058, u8 *, 0x52D4), 0, 0);
}

s32 func_020c70ec(void){
 extern void **data_027e0058;s32 func_020c60c8(void);s32 func_020c6350(void);s32 func_020cccdc(void);
 u8 *p;
 if(((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058,void **,0x52d0),u8 *,0)<<26)>>26)!=13)return 2;
 if(!func_020c60c8())return 2;
 if(!func_020c6350())return 2;
 p=*data_027e0058;
 if((M2C_FIELD(p+(M2C_FIELD(p,s16 *,0x52dc)+M2C_FIELD(p+M2C_FIELD(p,s16 *,0x52de)*2,u16 *,0x3758)),u8 *,0x1420)&31)!=1)return 2;
 if(((u32)(M2C_FIELD(M2C_FIELD(p,void **,0x52d0),u16 *,6)<<21)>>28)==0)return 2;
 if(func_020cccdc())return 0;return 2;
}

s32 func_020c71b4(void){
s32 func_020c60c8(void); s32 func_020c6350(void); s32 func_020cccdc(void);
extern void **data_027e0058; void *p; s32 x,y;
if(((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058,void **,0x52d0),u8 *,0)<<26)>>26)!=13)return 2;
if(!func_020c60c8())return 2;
if(!func_020c6350())return 2;
p=*data_027e0058;
y=M2C_FIELD(p,s16 *,0x52de);x=M2C_FIELD(p,s16 *,0x52dc);
if((M2C_FIELD((char*)p+(x+M2C_FIELD((char*)p+y*2,u16 *,0x3758)),u8 *,0x1420)&31)!=9)return 2;
if(((u32)(M2C_FIELD(M2C_FIELD(p,void **,0x52d0),u16 *,6)<<21)>>28)==0)return 2;
return func_020cccdc()!=0?0:2;
}

void func_020c727c(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **data_027e0058;
 func_020d468c(); func_020c0784();
 func_ov000_02199f50(0x18,M2C_FIELD(*data_027e0058,u8 *,0x52D4),0,0);
}

void func_020c72b4(void) {
 s32 func_ov000_0216cd78(s32,s32); s32 func_ov000_0216cd90(s32);
 void func_0207c3dc(s32,void *,s32,s32); void func_01ff9e44(s32,s32,s32); void func_0209c720(s32,s32,s32,s32,s32);
 extern void **data_027e0058; extern void *gCur3DSpriteEngine;
 u8 *base; u8 *p; s32 n; s32 a; s32 b;
 base = *data_027e0058;
 n = M2C_FIELD(M2C_FIELD(base,void **,0x52d0),u8 *,0xc);
 if(n == 0) return;
 p = base + 0x67a4 + ((n >> 6)+1)*0x8c;
 a = M2C_FIELD(base + n*14,u8 *,0x59a4);
 b = p[0x1d];
 a = func_ov000_0216cd78((u32)(a << 26) >> 26,p[0x29]);
 func_0207c3dc(a,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x4780,0x80,0);
 func_01ff9e44(func_ov000_0216cd90(b),0x340,0x20);
 func_0209c720(0,0x23c,10,2,2);
}

void func_020c7378(void) {
 s32 func_ov000_0216cd78(s32,s32); s32 func_ov000_0216cd90(s32);
 void func_0207c3dc(s32,void *,s32,s32); void func_01ff9e44(s32,s32,s32); void func_0209c720(s32,s32,s32,s32,s32);
 extern void **data_027e0058; extern void *gCur3DSpriteEngine;
 u8 *base; u8 *p; s32 n; s32 a; s32 b;
 base = *data_027e0058;
 n = M2C_FIELD(M2C_FIELD(base,void **,0x52d0),u8 *,0xd);
 if(n == 0) return;
 p = base + 0x67a4 + ((n >> 6)+1)*0x8c;
 a = M2C_FIELD(base + n*14,u8 *,0x59a4);
 b = p[0x1d];
 a = func_ov000_0216cd78((u32)(a << 26) >> 26,p[0x29]);
 func_0207c3dc(a,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x4800,0x80,0);
 func_01ff9e44(func_ov000_0216cd90(b),0x340,0x20);
 func_0209c720(1,0x240,10,2,2);
}

s32 func_020c7438(s32 arg0) {
    u32 temp_r0;

    temp_r0 = 0x20 - arg0;
    return ((s32) (temp_r0 + (temp_r0 >> 0x1F)) >> 1) * 8;
}

s32 func_020c744c(void) {
    return 0x10;
}

s32 func_020c7454(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r2;

    var_r2 = arg2;
    if (arg0 < arg1) {
        return arg1;
    }
    if (arg0 <= var_r2) {
        var_r2 = arg0;
    }
    return var_r2;
}

void func_020c7470(s32 arg0,s32 arg1,s32 *arg2) {
 s32 func_0207cfb8(void *); void func_02079c6c(s32,s32,s32 *);
 extern void **data_027e0058; extern u8 data_02164d5c[];
 s32 n;
 if(func_0207cfb8((u8 *)*data_027e0058+0x6ef8)<=0) n=16; else n=24;
 func_02079c6c(arg0,arg1,arg2);
 if(data_02164d5c[1]) { arg2[0]-=24; arg2[0]=func_020c7454(arg2[0],0,128); return; }
 if(arg2[0]<160) arg2[0]+=n/2; else arg2[0]-=n/2+48;
 arg2[1]-=n/2;
}

void func_020c752c(void) {
    M2C_UNK func_020c0748(M2C_UNK *, s32, s32, M2C_UNK);
    M2C_UNK func_020c0a88();
    extern M2C_UNK data_0212a8b4;
    s32 temp_r4;

    func_020994e0(0);
    func_020c0a88();
    temp_r4 = func_020c7438(0xC);
    func_020c0748(&data_0212a8b4, temp_r4, func_020c744c(), 0x50);
}

void func_020c7568(void) {
    M2C_UNK func_020994e0(M2C_UNK);
    M2C_UNK func_020c0b40();
    func_020994e0(0);
    func_020c0b40();
}

void func_020c757c(void) {
 M2C_UNK func_020c0634(M2C_UNK *,s32,s32,u16,s32); s32 func_020c0b9c(); extern M2C_UNK data_0212a774;
 s32 x,y;
 func_020994e0(0); func_020c0a88(); x=func_020c7438(8); y=func_020c744c();
 func_020c0634(&data_0212a774,x,y,(u16)func_020c0b9c(),0x50);
}

void func_020c75cc(void) {
 extern void **data_027e0058; extern M2C_UNK data_0212ab34;
 M2C_UNK func_020c0748(M2C_UNK *,s32,s32,M2C_UNK);
 s32 xy[3]; void *p;
 func_020994e0(0);
 p=*data_027e0058;
 func_020c7470(M2C_FIELD(p,s16 *,0x52c2),M2C_FIELD(p,s16 *,0x52c4),xy);
 func_020c0748(&data_0212ab34,xy[0],xy[1],0x30);
 func_01ffb3d0(-1);
 p=*data_027e0058;
 M2C_FIELD((u8 *)p+M2C_FIELD(p,s16 *,0x52de)*4,u8 **,0x52e8)[M2C_FIELD(p,s16 *,0x52dc)]=1;
}

void func_020c7654(void) {
    extern void **data_027e0058;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = *data_027e0058;
    M2C_FIELD(temp_r0, s16 *, 0x52C2) = (s16) M2C_FIELD(temp_r0, s16 *, 0x52DC);
    temp_r0_2 = *data_027e0058;
    M2C_FIELD(temp_r0_2, s16 *, 0x52C4) = (s16) M2C_FIELD(temp_r0_2, s16 *, 0x52DE);
}

void func_020c77d4(void *arg0) {
    M2C_UNK func_0207b764(s16, s16);
    func_0207b764(M2C_FIELD(arg0, s16 *, 0x6C), M2C_FIELD(arg0, s16 *, 0x6E));
}

void func_020c77ec(void *arg0) {
    M2C_UNK func_0207b774(s32, s32);
    func_0207b774(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020c7804(void *arg0) {
    M2C_UNK func_020b5f3c(s16, s16, void *);
    M2C_UNK func_020b5f74(s16, s16);
    func_020b5f3c(M2C_FIELD(arg0, s16 *, 0x6C), M2C_FIELD(arg0, s16 *, 0x6E), arg0);
    func_020b5f74(M2C_FIELD(arg0, s16 *, 0x6C), M2C_FIELD(arg0, s16 *, 0x6E));
}

void func_020c782c(void *arg0) {
    M2C_UNK func_020b6330(s32, s32, M2C_UNK, u16, void *);
    func_020b6330(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 2, M2C_FIELD(arg0, u16 *, 0x52), arg0);
}

void func_020c7850(void *arg0) {
    M2C_UNK func_020b63e8(s32, s32, s32, u16, void *);
    func_020b63e8(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x64), M2C_FIELD(arg0, u16 *, 0x52), arg0);
}

void func_020c7874(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212ae54;
    void *temp_r0;
    temp_r0 = func_01ffa444(&data_0212ae54, arg4);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x64) = arg2;
    M2C_FIELD(temp_r0, s16 *, 0x52) = arg3;
}

void func_020c78ac(void *arg0) {
    func_0207b774(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020c78c4(void *arg0) {
    M2C_UNK func_020b638c(s32, s32, s32, u16, void *);
    func_020b638c(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x64), M2C_FIELD(arg0, u16 *, 0x52), arg0);
}

void func_020c78e8(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212aeec;
    void *temp_r0;
    temp_r0 = func_01ffa444(&data_0212aeec, arg4);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x64) = arg2;
    M2C_FIELD(temp_r0, s16 *, 0x52) = arg3;
}

void func_020c7920(void *arg0) {
 void func_020b654c(void *,void *);
 extern void **data_027e0058;
 u8 *p; u8 *q; s32 y; u32 x; s32 yes; u32 bit;
 p=*data_027e0058;
 q=M2C_FIELD(p,u8 **,0x52d0);
 yes=M2C_FIELD(p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67c3);
 y=q[2]; x=q[1];
 if(yes & 2) yes=1;
 else { bit=x+M2C_FIELD(p+y*2,u16 *,0x3758); yes=1; if((u8)(M2C_FIELD(p+(bit>>3),u8 *,0x5201) & (1 << (bit & 7)))==0) yes=0; }
 if(yes==0) return;
 func_020b654c(q,arg0);
}

void func_020c79ac(void *arg0) { void func_020b67e0(s32,s32,void *); func_020b67e0(M2C_FIELD(arg0,s32 *,0x34),M2C_FIELD(arg0,s32 *,0x38),arg0); }

void func_020c79c4(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212ae9c;
    void *temp_r0;

    temp_r0 = func_01ffa444(&data_0212ae9c, arg2);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
}

s32 func_020c79ec(void) {
    s32 func_020be120();
    return func_020be120();
}

s32 func_020c79f8(void) {
    return func_020c79ec() + 0x54;
}

s32 func_020c7a08(void) {
    return func_020c79ec();
}

s32 func_020c7a14(void) {
    return func_020c7a08() + 0x40;
}

void func_020c7a24(s32 arg0) {
    M2C_UNK func_0208f404(s32, s32);
    func_0208f404(arg0 + 0x54, 0x6A4);
}

