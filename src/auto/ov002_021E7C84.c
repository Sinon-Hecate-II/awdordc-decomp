/* 18 functions from 0x021E7C84 to 0x021E8984 (ov002), found by ds-decomp. */
#include "common.h"
typedef struct { s32 pad[2]; s32 slots[5]; } ObjectSlots;

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

void func_ov002_021e8470(u8 *p,u8 *a,u8 *b,s32 c,s32 d){
extern void **gCurrentMap;
void func_ov002_021e80c8(void*,s32,void*,s32);
s32 func_020a7d38(void*);
void func_ov002_021e7d34(void*,s32,u32,u32,s32);
p[0]=!(a==M2C_FIELD(*gCurrentMap,u8**,0x52d0));
p[1]=!p[0];
switch(M2C_FIELD(*gCurrentMap,u8*,0x5157)){
case 3: case 4: case 6:p[3]=1;break;
case 1:p[3]=2;break;
case 2:p[3]=3;break;
default:p[3]=0;break;
}
func_ov002_021e80c8(p,0,a,c);
func_ov002_021e80c8(p,1,b,d);
func_ov002_021e7d34(p,0,(u32)(a[0]<<26)>>26,(u32)(b[0]<<26)>>26,func_020a7d38(a));
func_ov002_021e7d34(p,1,(u32)(b[0]<<26)>>26,(u32)(a[0]<<26)>>26,func_020a7d38(b));
}

void func_ov002_021e85b0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    void func_ov002_021e8470(u8 *, u8 *, u8 *, s32, s32);
    extern M2C_UNK gPlayerSettings;
    func_ov002_021e8470(&gPlayerSettings, arg0, arg1, arg2, arg3);
}

void func_ov002_021e85e8(void *p) {
M2C_UNK func_ov002_021e3f2c(void *,u8);
extern M2C_UNK data_ov002_021f3124;
extern u8 data_ov002_021f2fa9[],data_ov002_021f30fd[];
extern u8 *data_ov002_021f30f4[];
s32 i;
u32 flag;
flag = p != &data_ov002_021f3124;
M2C_FIELD(p,u8 *,0x27)=flag;
for(i=0;i<5;i++) ((ObjectSlots *)p)->slots[i]=0;
M2C_FIELD(p,u8 *,0x2a)=data_ov002_021f2fa9[(s16)M2C_FIELD(p,u8 *,0x27)*(s16)104];
M2C_FIELD(p,u8 *,0x2b)=(((data_ov002_021f30fd[(s16)M2C_FIELD(p,u8 *,0x27)*(s16)24]+9)/10+1)&~1U)>>1;
if(M2C_FIELD(p,u8 *,0x2a)&&M2C_FIELD(p,u8 *,0x2b)) M2C_FIELD(p,u8 *,0x2b)=1;
M2C_FIELD(p,u16 *,0x1c)=256;
M2C_FIELD(p,u16 *,0x1e)=0;M2C_FIELD(p,u16 *,0x20)=0;M2C_FIELD(p,u16 *,0x22)=0;M2C_FIELD(p,u16 *,0x24)=0;
M2C_FIELD(p,s8 *,0x26)=-1;
if(M2C_FIELD(*(u8 **)((u8 *)data_ov002_021f30f4+(s16)M2C_FIELD(p,u8 *,0x27)*(s16)24),u8 *,0x3d)!=2) M2C_FIELD(p,u8 *,0x28)=0; else M2C_FIELD(p,u8 *,0x28)=1;
M2C_FIELD(p,u8 *,0x29)=0;
func_ov002_021e3f2c(p,M2C_FIELD(p,u8 *,0x27));
}

s32 func_ov002_021e86f8(s32 arg0,s32 arg1) { s32 result=20; s32 i=0; do { if(i!=arg1) { if((u32)M2C_FIELD(arg0+(u16)i*8,u16 *,6)>(u32)M2C_FIELD(arg0+arg1*8,u16 *,6)) result+=20; } i++; }while(i<5); return result; }

void func_ov002_021e8738(void *p) {
    M2C_UNK func_02082028(s32);
    void func_ov002_021e8d0c(void *, s8, s8);
    void func_ov002_021e997c(void *);
    s32 func_ov002_021e86f8(s32, s32);
    void func_ov002_021e8ff0(void *, s16, s16, s16);
    void func_ov002_021e9000(void *, s16);
    void func_020af860(s32, s32);
    extern u8 data_ov002_021f2f44[];
    extern u8 data_ov002_021ea704[];
    extern u8 data_ov002_021f2f1c[];
    extern u8 *data_ov002_021f30f4[];
    u8 *tableBase;
    void *alloc;
    s32 owner;
    s32 flag;
    s32 idx;

    flag = M2C_FIELD(p, u8 *, 0x2A);
    owner = M2C_FIELD(p, u8 *, 0x27);
    idx = 0;
loop:
    if (flag == 0) {
        if (M2C_FIELD(data_ov002_021f2f44 + owner * 0x68, u8 *, idx * 2 + 8) == 0) goto tail2;
    }
    alloc = func_02082028(0x90);
    if (alloc != 0) {
        M2C_FIELD(alloc, void **, 0x00) = (void *)data_ov002_021ea704;
        M2C_FIELD(alloc, s32 *, 0x08) = 0;
        M2C_FIELD(alloc, s32 *, 0x0C) = 0;
        M2C_FIELD(alloc, void **, 0x00) = (void *)data_ov002_021f2f1c;
        M2C_FIELD(alloc, s32 *, 0x54) = 0;
        M2C_FIELD(alloc, s32 *, 0x58) = 0;
        M2C_FIELD(alloc, s32 *, 0x5C) = 0;
        M2C_FIELD(alloc, s32 *, 0x60) = 0;
        M2C_FIELD(alloc, s32 *, 0x64) = 0;
        M2C_FIELD(alloc, s32 *, 0x68) = 0;
        M2C_FIELD(p, void **, 0x08 + idx * 4) = alloc;
        func_ov002_021e8d0c(alloc, (s8)owner, (s8)idx);
        func_ov002_021e997c(alloc);
        tableBase = M2C_FIELD(M2C_FIELD((void *)((u8 *)data_ov002_021f30f4 + owner * 0x18), void **, 0x04), void **, 0x28);
        func_ov002_021e8ff0(M2C_FIELD(p, void **, 0x08 + idx * 4),
            (s16)(M2C_FIELD(tableBase, s16 *, idx * 8 + 0) - 0x80),
            M2C_FIELD(tableBase, s16 *, idx * 8 + 2),
            (s16)(M2C_FIELD(tableBase, s16 *, idx * 8 + 4) + (flag != 0 ? 0x14 : func_ov002_021e86f8((s32)tableBase, idx))));
        func_ov002_021e9000(M2C_FIELD(p, void **, 0x08 + idx * 4), M2C_FIELD(tableBase, u16 *, idx * 8 + 6));
    }
    if (flag != 0) goto tail;
    idx++;
    if (idx < 5) goto loop;
tail:
    func_020af860(owner, M2C_FIELD(p, u8 *, 0x2B));
    return;
tail2:
    if (flag != 0) goto tail;
    idx++;
    if (idx < 5) goto loop;
    goto tail;
}

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

