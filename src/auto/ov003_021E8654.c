/* 9 functions from 0x021E8654 to 0x021E9638 (ov003), found by ds-decomp. */
#include "common.h"

extern u16 data_ov003_0220f890;
extern u16 data_ov003_0220f892;
extern u16 data_ov003_0220f88e;
extern u16 data_ov003_0220f88c;
extern u16 data_ov003_0220f894;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineSub;
extern void *g3DSpriteEngineMain;
extern u8 data_ov003_0220fb84[];
extern u8 data_ov003_0220fb8c[];
extern u8 data_ov003_0220fb94[];
extern u8 data_ov003_0220fbac[];
extern u8 data_ov003_0220fbc0[];
extern u8 data_ov003_0220fbd0[];
extern u8 data_ov003_0220fbe4[];
extern u8 data_ov003_0220fbec[];
extern u8 data_ov003_0220fc00[];
extern u8 data_ov003_0220fc1c[];
extern u8 data_ov003_0220fc30[];
extern u8 data_ov003_0220fc38[];
extern u8 data_ov003_0220fc50[];
extern u8 data_ov003_0220fc60[];

void StepCounter(void *p,s32 delta,s32 force){
s32 InRange(s16,s16,s16);
s32 next=delta+M2C_FIELD(p,s32*,4);
if(InRange((s16)next,(s16)M2C_FIELD(p,s32*,12),(s16)M2C_FIELD(p,s32*,8))||force){
M2C_FIELD(p,s32*,4)=next;
if(M2C_FIELD(p,u8*,20)){
while(M2C_FIELD(p,s32*,4)>M2C_FIELD(p,s32*,8))
M2C_FIELD(p,s32*,4)-=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
while(M2C_FIELD(p,s32*,4)<M2C_FIELD(p,s32*,12))
M2C_FIELD(p,s32*,4)+=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
}else{
s32 x=M2C_FIELD(p,s32*,4),hi=M2C_FIELD(p,s32*,8);
if(x<=hi){hi=M2C_FIELD(p,s32*,12);if(x>=hi)hi=x;}
M2C_FIELD(p,s32*,4)=hi;
}
}else{
s32 x=M2C_FIELD(p,s32*,8);
if(next<=x){x=M2C_FIELD(p,s32*,12);if(next>=x)x=next;}
M2C_FIELD(p,s32*,4)=x;
if(M2C_FIELD(p,u8*,20)){
while(M2C_FIELD(p,s32*,4)>M2C_FIELD(p,s32*,8))
M2C_FIELD(p,s32*,4)-=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
while(M2C_FIELD(p,s32*,4)<M2C_FIELD(p,s32*,12))
M2C_FIELD(p,s32*,4)+=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
}else{
s32 x=M2C_FIELD(p,s32*,4),hi=M2C_FIELD(p,s32*,8);
if(x<=hi){hi=M2C_FIELD(p,s32*,12);if(x>=hi)hi=x;}
M2C_FIELD(p,s32*,4)=hi;
}
}
}

void func_ov003_021e87d0(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x34) = arg1;
    M2C_FIELD(arg0, s16 *, 0x36) = arg2;
}

void func_ov003_021e87dc(void *arg0) {
    M2C_UNK MenuSpriteUpdate(s32);
    s32 var_r0;
    s32 var_r0_2;
    u8 var_r8;
    void *temp_r0;
    void *temp_r2;
    void *temp_r3;

    M2C_FIELD(arg0, s8 *, 5) = -1;
    M2C_FIELD(arg0, s8 *, 6) = -1;
    var_r8 = 0;
    do {
        MenuSpriteUpdate(M2C_FIELD((void *)((u8 *) arg0 + (var_r8 * 4)), s32 *, 0x78));
        temp_r3 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x78);
        var_r0 = 1;
        temp_r2 = M2C_FIELD(temp_r3, void **, 0x64);
        if ((M2C_FIELD(temp_r2, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(temp_r3, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(temp_r2, s8 *, 0xC) != 1))) {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            M2C_FIELD(arg0, u8 *, 5) = var_r8;
        }
        temp_r0 = M2C_FIELD(&((u8 *) arg0)[var_r8 * 4], void **, 0x78);
        if ((((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) == (u16) ((u32) (M2C_FIELD(temp_r0, s32 *, 0x40) << 6) >> 0x18)) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            M2C_FIELD(arg0, u8 *, 6) = var_r8;
        }
        var_r8 += 1;
    } while ((u32) var_r8 < 0x1AU);
}

u8 func_ov003_021e88a4(void *arg0) {
s32 result=1;
void *p=M2C_FIELD(arg0,void **,0x64);
if(M2C_FIELD(p,s8 *,0xb)!=1 && ((((u32)(M2C_FIELD(arg0,u8 *,0x59)<<27)>>31)==0) || M2C_FIELD(p,s8 *,0xc)!=1))result=0;
return result;
}

void func_ov003_021e88e0(void) {
s32 func_02084d3c(s32 *,M2C_UNK);
M2C_UNK func_02084d88(s32 *,M2C_UNK);
s32 buffer[9];
if(func_02084d3c(buffer,0x24)==0)return;
buffer[0]=1;
func_02084d88(buffer,0x24);
}

void func_ov003_021e891c(void) {
s32 func_02084d3c(s32 *,M2C_UNK);
M2C_UNK func_02084d88(s32 *,M2C_UNK);
s32 buffer[9];
if(func_02084d3c(buffer,0x24)==0)return;
buffer[1]=1;
func_02084d88(buffer,0x24);
}

void func_ov003_021e8958(void *arg0) {
    void func_ov003_021e8f80(void *, s32);
    void func_ov003_021e8f98(void *, s32);
    s32 func_020cfb94(void *);
    void func_ov003_021f1b38(s32, void *);
    void func_ov003_021f1b7c(s32, void *);
    void func_01ff9b38(void);
    void func_ov003_021e771c(void *, void *);
    void func_ov003_021e9638(void *, void *);
    void *func_020896f0(void *);
    void func_020893f4(void *, s32, s32);
    void func_ov003_021e97bc(void *, s32, s32, s32, s32);
    void func_02089438(void *);
    void func_ov003_021e97fc(void *, s32);
    void func_ov003_021e9804(void *);
    s32 func_02088da8(void *);
    void *func_0208bc24(void *);
    void func_ov003_021e9810(void *, s32);
    void func_ov003_021e9818(void *, s32);
    s32 func_ov003_021e6e40(void);
    void *func_0208ed64(void *);
    void func_0208eb30(void *, s32, s32);
    void func_0208eb60(void *, s32);
    s32 func_ov003_021f153c(void);
    void func_ov003_021e9830(void *, s32);
    s32 IsLinkSessionActive(void);
    void *func_02084e64(void);
    void func_ov003_021e984c(void *, s32);
    s32 func_ov003_021e9ce0(void *);
    void SetWaypointPanelState(void *, s32);
    void func_ov003_021e9c50(void *);
    s32 GetWaypointSlotIndex(void *);
    s32 func_ov003_021e7450(void *);
    void func_ov003_021e9e78(void *, s32, s32);
    void func_ov003_021e9eb4(void *);
    void func_ov003_021ea154(void *);
    void SetFileDirectory(void *);
    void Clear3DSpriteLayer(s32);
    s32 func_ov003_021e9c24(void *);
    void func_ov003_022005e4(s32, s32, s32);
    void func_ov003_021ea134(s32);
    void func_020985b0(s32, s32, s32);
    void func_02098d78(s32, s32, s32);
    void func_ov003_021ea27c(s32, s32, s32);
    void func_ov003_021ea294(s32, s32, s32);
    void *GetLocalizedFileName(void *);
    void *func_02080e30(void *, s32);
    void func_0207c780(void *, s32);
    void func_020e35cc(void *);
    void LoadDecompressedFileTo(void *, s32);
    void LoadFileToSpriteBuffer(void *, s32, s32);
    void func_ov003_021ea2ac(void);
    void func_020808dc(s32, s32, s32, s32);
    void func_02091d4c(s32);
    s32 t1;
    s32 t2;
    s32 v;
    s32 t3;
    void *p;
    u8 i;
    u8 *h;

    if (func_020cfb94(arg0) == 2) func_ov003_021e8f80(arg0, 1);
    func_ov003_021f1b38(3, &data_ov003_0220f890);
    func_ov003_021f1b38(0, &data_ov003_0220f892);
    func_ov003_021f1b38(1, &data_ov003_0220f88e);
    func_ov003_021f1b7c(0, &data_ov003_0220f88c);
    func_ov003_021f1b7c(3, &data_ov003_0220f894);
    func_01ff9b38();
    func_ov003_021e771c(M2C_FIELD(arg0, void **, 0x6c), arg0);
    func_ov003_021e8f98(M2C_FIELD(arg0, void **, 0x64), arg0);
    func_ov003_021e9638(M2C_FIELD(arg0, void **, 0x68), arg0);
    M2C_FIELD(arg0, void **, 0x58) = func_020896f0(arg0);
    func_020893f4(M2C_FIELD(arg0, void **, 0x58), 0xb000, 0xa);
    func_ov003_021e97bc(M2C_FIELD(arg0, void **, 0x58), 0xa, 0x10, 0x38, 0x38);
    func_02089438(M2C_FIELD(arg0, void **, 0x58));
    func_ov003_021e97fc(M2C_FIELD(arg0, void **, 0x58), 1);
    func_02088da8(M2C_FIELD(arg0, void **, 0x58));
    M2C_FIELD(arg0, void **, 0x5c) = func_020896f0(arg0);
    func_020893f4(M2C_FIELD(arg0, void **, 0x5c), 0xb400, 0xa);
    func_ov003_021e97bc(M2C_FIELD(arg0, void **, 0x5c), 0x38, 0x10, 0x38, 0x38);
    func_02089438(M2C_FIELD(arg0, void **, 0x5c));
    func_ov003_021e97fc(M2C_FIELD(arg0, void **, 0x5c), 1);
    func_ov003_021e9804(M2C_FIELD(arg0, void **, 0x5c));
    func_02088da8(M2C_FIELD(arg0, void **, 0x5c));
    t1 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    M2C_FIELD(arg0, void **, 0x54) = func_0208bc24(arg0);
    func_ov003_021e9810(M2C_FIELD(arg0, void **, 0x54), 0x180);
    func_ov003_021e9818(M2C_FIELD(arg0, void **, 0x54), 7);
    func_02088da8(M2C_FIELD(arg0, void **, 0x54));
    gCur3DSpriteEngine = t1;
    if (func_ov003_021e6e40()) {
        t2 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        M2C_FIELD(arg0, void **, 0x60) = func_0208ed64(arg0);
        func_0208eb30(M2C_FIELD(arg0, void **, 0x60), 0xd400, 0xb);
        func_0208eb60(M2C_FIELD(arg0, void **, 0x60), 0x708);
        func_ov003_021e87d0(M2C_FIELD(arg0, void **, 0x60), 0, 0xb6);
        gCur3DSpriteEngine = t2;
    }
    v = func_ov003_021f153c();
    func_ov003_021e9830(M2C_FIELD(arg0, s32 *, 0x48), v);
    func_ov003_021e9830(M2C_FIELD(arg0, s32 *, 0x50), v);
    func_ov003_021e9830(M2C_FIELD(arg0, s32 *, 0x4c), 0xc0);
    if (IsLinkSessionActive()) {
        p = func_02084e64();
        if (p == 0) return;
        func_ov003_021e984c(arg0, M2C_FIELD(p, u8 *, 8));
    } else if (func_ov003_021e9ce0(arg0) && v == (s32) 0xFFFFFF00) {
        func_ov003_021e984c(arg0, 1);
    } else {
        func_ov003_021e984c(arg0, 0);
    }
    SetWaypointPanelState(arg0, 0);
    func_ov003_021e9c50(arg0);
    func_02089438(M2C_FIELD(arg0, void **, 0x58));
    func_02089438(M2C_FIELD(arg0, void **, 0x5c));
    {
        s32 a = GetWaypointSlotIndex(M2C_FIELD(arg0, void **, 0x6c));
        s32 b = func_ov003_021e7450(M2C_FIELD(arg0, void **, 0x6c));
        func_ov003_021e9e78(M2C_FIELD(arg0, s32 *, 0x40), a, b);
    }
    func_ov003_021e9eb4(arg0);
    func_ov003_021ea154(arg0);
    t3 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    SetFileDirectory(data_ov003_0220fb84);
    Clear3DSpriteLayer(3);
    func_ov003_022005e4(3, 0, func_ov003_021e9c24(arg0) & 0xff);
    func_ov003_021ea134(3);
    for (i = 0; i < 12; i++) func_020985b0(i + 1, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xc) + (((i << 7) + 2) << 5));
    for (i = 0; i < 13; i++) func_02098d78(i, ((i << 4) + 0x1f0) << 5, 7);
    func_ov003_021ea27c(4, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0x3400);
    func_ov003_021ea294(5, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2c0);
    SetFileDirectory(data_ov003_0220fb8c);
    h = func_02080e30(GetLocalizedFileName(data_ov003_0220fb94), 1);
    func_0207c780(h + 0x254, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xa400);
    func_0207c780(h + 0x460, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xa800);
    func_0207c780(h + 0x568, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xac00);
    func_0207c780(h + 0x164, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xb800);
    func_0207c780(h + 0x92c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xc000);
    func_0207c780(h + 0x67c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xc400);
    func_0207c780(h + 0x9c8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xd000);
    func_020e35cc(h);
    h = func_02080e30(GetLocalizedFileName(data_ov003_0220fbac), 1);
    func_0207c780(h + 0x92c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xcc00);
    func_020e35cc(h);
    LoadDecompressedFileTo(data_ov003_0220fbc0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xbc00);
    LoadFileToSpriteBuffer(data_ov003_0220fbd0, 0x300, 0x40);
    func_ov003_021ea2ac();
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    SetFileDirectory(data_ov003_0220fbe4);
    Clear3DSpriteLayer(0);
    LoadDecompressedFileTo(GetLocalizedFileName(data_ov003_0220fbec), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xc));
    LoadDecompressedFileTo(GetLocalizedFileName(data_ov003_0220fc00), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
    LoadFileToSpriteBuffer(data_ov003_0220fc1c, 0, 0x20);
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 0x20, 0x20, 0);
    func_ov003_021ea134(0);
    func_02091d4c(2);
    SetFileDirectory(data_ov003_0220fc30);
    h = func_02080e30(GetLocalizedFileName(data_ov003_0220fc38), 1);
    func_0207c780(h, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0x2800);
    func_020e35cc(h);
    LoadDecompressedFileTo(data_ov003_0220fc50, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0x2c00);
    LoadFileToSpriteBuffer(data_ov003_0220fc60, 0x2c0, 0x20);
    func_ov003_021ea2ac();
    gCur3DSpriteEngine = t3;
}

void func_ov003_021e8f80(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 0x39) = (u8) ((M2C_FIELD(arg0, u8 *, 0x39) & ~1) | (arg1 & 1));
}

#pragma opt_common_subs off
#pragma opt_propagation on
void func_ov003_021e8f98(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, s32, M2C_UNK, s32, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    u32 func_020aae10(void *);
    u32 func_020aae44(void *);
    void *func_020ab1c4(M2C_UNK);
    s32 func_ov003_022004a8(u8);
u8 i; s32 pos, left; s32 hidden; 
M2C_FIELD(arg0,void**,0)=func_020ab1c4(arg1);func_020aab24(M2C_FIELD(arg0,void**,0),2,344,3,1);{ void *p=M2C_FIELD(arg0,void**,0);func_02088e84(p,224,160,224,192);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_020aad18(M2C_FIELD(arg0,void**,0));func_02088da8(M2C_FIELD(arg0,void**,0)); }M2C_FIELD(arg0,void**,4)=func_020ab1c4(arg1);func_020aab24(M2C_FIELD(arg0,void**,4),31,320,3,0);{ void *p=M2C_FIELD(arg0,void**,4);func_02088e84(p,96,164,96,192);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_020aad18(M2C_FIELD(arg0,void**,4));func_02088da8(M2C_FIELD(arg0,void**,4)); }hidden=-32;i=0;do{pos=func_ov003_022004a8(i);{ void *created=func_020ab1c4(arg1);M2C_FIELD(arg0+i*4,void**,8)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,8),23,360,3,0);{ void *p=M2C_FIELD(arg0+i*4,void**,8);left=(s16)(pos-1);func_02088e84(p,left,72,left,72);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=left;M2C_FIELD(p,s16*,0x36)=72;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,8)); }{ void *created=func_020ab1c4(arg1);M2C_FIELD(arg0+i*4,void**,24)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,24),24,364,3,0);pos=(s16)(pos+40);{ void *p=M2C_FIELD(arg0+i*4,void**,24);func_02088e84(p,pos,72,pos,72);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=pos;M2C_FIELD(p,s16*,0x36)=72;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,24)); }{ void *created=func_020ab1c4(arg1);M2C_FIELD(arg0+i*4,void**,40)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,40),8,368,3,0);{ void *p=M2C_FIELD(arg0+i*4,void**,40);func_02088e84(p,hidden,0,hidden,0);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=hidden;M2C_FIELD(p,s16*,0x36)=0;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,40)); }{ void *created=func_020ab1c4(arg1);M2C_FIELD(arg0+i*4,void**,56)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,56),9,376,3,0);{ void *p=M2C_FIELD(arg0+i*4,void**,56);func_02088e84(p,hidden,0,hidden,0);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=hidden;M2C_FIELD(p,s16*,0x36)=0;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,56)); }i++;}while(i<4);}
#pragma opt_common_subs reset
#pragma opt_propagation reset
