/* 18 functions from 0x021E7C84 to 0x021E8984 (ov002), found by ds-decomp. */
#include "common.h"

void func_ov002_021e7c84(u8 *p) { extern s32 gPlayerSettings; p[0]=0;p[1]=0;((u8 *)&gPlayerSettings)[12]=8;((u8 *)&gPlayerSettings)[36]=12;((u8 *)&gPlayerSettings)[16]=0;((u8 *)&gPlayerSettings)[40]=1;((u8 *)&gPlayerSettings)[17]=3;((u8 *)&gPlayerSettings)[41]=3;((u8 *)&gPlayerSettings)[18]=0;((u8 *)&gPlayerSettings)[42]=0;((u8 *)&gPlayerSettings)[3]=0;p[13]=100;p[37]=100;p[14]=80;p[38]=20;p[15]=3;p[39]=3;p[21]=1;p[45]=2;p[22]=2;p[46]=2;p[23]=1;p[47]=1;((u8 *)&gPlayerSettings)[20]=1;((u8 *)&gPlayerSettings)[44]=1;((u8 *)&gPlayerSettings)[19]=0;((u8 *)&gPlayerSettings)[43]=0;((u8 *)&gPlayerSettings)[24]=0;((u8 *)&gPlayerSettings)[48]=1;((u8 *)&gPlayerSettings)[25]=0;((u8 *)&gPlayerSettings)[49]=1;}

s32 func_ov002_021e7fec(s32 arg0,s32 arg1) { switch(M2C_FIELD(arg0+arg1*24,u8 *,12)) {case 0x25: case 0x26:return 1; default:return 0;} }

u8 func_ov002_021e8014(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x22) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e8038(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x22) == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e805c(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x21) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e8080(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x21) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e80a4(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x21) == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov002_021e85b0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_ov002_021e8470(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK gPlayerSettings;
    func_ov002_021e8470(&gPlayerSettings, arg0, arg1, arg2, arg3);
}

s32 func_ov002_021e86f8(s32 arg0,s32 arg1) { s32 result=20; s32 i=0; do { if(i!=arg1) { if((u32)M2C_FIELD(arg0+(u16)i*8,u16 *,6)>(u32)M2C_FIELD(arg0+arg1*8,u16 *,6)) result+=20; } i++; }while(i<5); return result; }

void func_ov002_021e8898(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x1E) = arg1;
}

void func_ov002_021e88a0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x26) = 0;
}

void func_ov002_021e88ac(void *p) { extern s8 data_ov002_021f2ef0[]; s32 i; if(M2C_FIELD(p,s8 *,0x26)==-1)return;
 M2C_FIELD(p,s16 *,0x22)=data_ov002_021f2ef0[M2C_FIELD(p,s8 *,0x26)&~1];
 M2C_FIELD(p,s16 *,0x24)=data_ov002_021f2ef0[(M2C_FIELD(p,s8 *,0x26)&~1)+1];
 i=M2C_FIELD(p,s8 *,0x26)&~1;
 if(data_ov002_021f2ef0[i]==0 && data_ov002_021f2ef0[i+1]==0) M2C_FIELD(p,s8 *,0x26)=-1;
 else M2C_FIELD(p,s8 *,0x26)++;
}

void func_ov002_021e8914(void *arg0) {
    void func_ov002_021e42c4(void *);
    s32 func_ov002_021e79ac(void *);
    void func_ov002_021e8e8c(void *);
    extern u8 data_ov002_021f30e4[];
    register s32 i;
    if (func_ov002_021e79ac(data_ov002_021f30e4)==0) M2C_FIELD(arg0,u8 *,0x29)++;
    i=0;
    do {
        if (((void **)arg0)[i+2]!=0) func_ov002_021e8e8c(((void **)arg0)[i+2]);
        i++;
    } while(i<5);
    func_ov002_021e88ac(arg0);
    if(M2C_FIELD(arg0,u8 *,0x28)!=0) M2C_FIELD(arg0,s16 *,0x20)--;
    func_ov002_021e42c4(arg0);
}

