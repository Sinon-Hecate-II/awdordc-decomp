/* 6 functions from 0x02200EE4 to 0x02201E88 (ov003), found by ds-decomp. */
#include "common.h"
s32 func_ov003_021f1b38();
s32 func_ov003_021f1b7c();
void *func_0208bc24();
s32 func_ov003_021e9810();
s32 func_ov003_021e9818();
s32 func_020aeebc();
s32 func_01ff9b38();
s32 func_ov003_021ea2ac();
s32 func_ov003_021e9830();
s32 func_ov003_02201e88();
void *func_020896f0();
s32 func_020893f4();
s32 func_ov003_021e97bc();
s32 func_02089438();
s32 func_ov003_021e97fc();
s32 func_ov003_022020e0();
s32 func_ov003_022021e8();
s32 func_ov003_02202254();
s32 func_ov003_02202380();
s32 func_ov003_02202388();
s32 func_ov003_02202390();
s32 func_ov003_02202398();
s32 func_ov003_022023a0();
s32 func_020a92bc();
s32 func_ov003_022023a8();
s32 func_ov003_022023c4();
s32 func_ov003_022023cc();
s32 func_0200bc5c();
s32 func_01ff9ce8();
void *func_02080e30();
void *func_020e3218();
s32 func_0207c780();
s32 func_020e35cc();
s32 func_0208116c();
s32 func_020808dc();
s32 func_ov003_021ea134();
s32 func_02080cfc();
s32 func_ov003_022023e4();
s32 func_ov003_021ea294();
s32 func_ov003_022005e4();
s32 func_ov003_022023fc();
s32 func_01ff9dd8();
s32 func_0207c928();
s32 func_ov003_02202408();
s32 func_ov003_022004f0();
s32 func_020a22fc();
s32 func_020809c0();
s32 func_020985b0();
s32 func_02098844();
s32 func_02098a34();
s32 func_ov003_021ea27c();
u8 func_ov003_02201500(void *);
u8 func_ov003_0220151c(void *);
void func_ov003_0220153c(s32,s32,s32,s32,u8);
void func_ov003_02201620(void *,s32);
void func_ov003_02201c78(void *,s32);
void func_02088da8(void *);
extern u8 data_ov003_02210456[];
extern u8 data_ov003_02210454[];
extern u8 data_ov003_02210458[];
extern u8 data_ov003_0221045a[];
extern u8 data_ov003_0221045c[];
extern u8 data_ov003_02210472[];
extern u8 data_ov003_02210900[];
extern u8 data_ov003_02210908[];
extern u8 data_ov003_02210918[];
extern u8 data_ov003_0221092c[];
extern u8 data_ov003_02210934[];
extern u8 data_ov003_02210948[];
extern u8 data_ov003_02210958[];
extern u8 data_ov003_02210970[];
extern u8 data_ov003_02210980[];
extern u8 data_ov003_02210990[];
extern u8 data_ov003_022109a4[];
extern u8 data_ov003_022109ac[];
extern u8 data_ov003_022109b4[];
extern u16 *g3DSpriteEngineSub,*g3DSpriteEngineMain;
extern u16 **gCur3DSpriteEngine;

#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov003_02200ee4(void *p) {
u16 **saved,**saved2;
void *res;
u8 i;
s32 side,side2,offset,slot;
s8 character;
func_ov003_021f1b38(3,data_ov003_02210456);
if(func_ov003_02201500(p)){
func_ov003_021f1b7c(0,data_ov003_02210454);
func_ov003_021f1b7c(1,data_ov003_02210458);
func_ov003_021f1b7c(3,data_ov003_0221045a);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(u16 **)g3DSpriteEngineSub;
M2C_FIELD(p,void**,0x58)=func_0208bc24(p);
func_ov003_021e9810(M2C_FIELD(p,void**,0x58),0x210);
func_ov003_021e9818(M2C_FIELD(p,void**,0x58),8);
gCur3DSpriteEngine=saved;
}else if(func_ov003_0220151c(p)){
func_ov003_021f1b38(2,data_ov003_0221045c);
func_020aeebc(2,15,6);
func_ov003_0220153c(0,0,1,1,1);
}
func_01ff9b38();func_ov003_021ea2ac();
func_ov003_021e9830(M2C_FIELD(p,void**,0x48),-32);
func_ov003_02201620(M2C_FIELD(p,void**,0x44),p);
func_ov003_02201c78(M2C_FIELD(p,void**,0x40),p);
if(func_ov003_02201500(p))func_ov003_02201e88(M2C_FIELD(p,void**,0x50),p);
M2C_FIELD(p,void**,0x4c)=func_020896f0(p);
func_020893f4(M2C_FIELD(p,void**,0x4c),0x2d80,1);
func_ov003_021e97bc(M2C_FIELD(p,void**,0x4c),112,164,58,58);
func_02089438(M2C_FIELD(p,void**,0x4c));
func_ov003_021e97fc(M2C_FIELD(p,void**,0x4c),1);
func_02088da8(M2C_FIELD(p,void**,0x4c));
func_ov003_022020e0(p,0);func_ov003_022021e8(p);
func_02089438(M2C_FIELD(p,void**,0x4c));func_ov003_02202254(p);
func_ov003_02202380(M2C_FIELD(p,void**,0x54),0x18c);
func_ov003_02202388(M2C_FIELD(p,void**,0x54),4);
func_ov003_02202390(M2C_FIELD(p,void**,0x54),16);
func_ov003_02202398(M2C_FIELD(p,void**,0x54),6);
func_ov003_022023a0(M2C_FIELD(p,void**,0x54),10);
func_020a92bc(M2C_FIELD(p,void**,0x54),0);
func_ov003_022023a8(M2C_FIELD(p,void**,0x54),1);
func_ov003_022023c4(M2C_FIELD(p,void**,0x54),data_ov003_02210472);
func_ov003_022023cc(M2C_FIELD(p,void**,0x54),1);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(u16 **)g3DSpriteEngineMain;
func_0200bc5c(data_ov003_02210900);func_01ff9ce8(3);
res=func_02080e30(func_020e3218(data_ov003_02210908),1);
func_0207c780(res,M2C_FIELD(gCur3DSpriteEngine,void**,0x18));
func_0207c780((u8 *)res+0x3cc,M2C_FIELD(gCur3DSpriteEngine,void**,0x2c));
func_020e35cc(res);
func_0208116c(data_ov003_02210918,0,64);
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void**,0x2c),32,32,0);
func_ov003_021ea134(3);
func_0200bc5c(data_ov003_0221092c);
res=func_02080e30(func_020e3218(data_ov003_02210934),1);
func_0207c780(res,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3800);
func_020e35cc(res);
func_02080cfc(data_ov003_02210948,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3c00);
func_0208116c(data_ov003_02210958,0x2e0,32);
func_02080cfc(func_020e3218(data_ov003_02210970),(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x4000);
func_0208116c(data_ov003_02210980,0x300,32);
func_ov003_022023e4(1,3,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3180);
func_ov003_021ea294(1,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x30)+0x2c0);
res=func_02080e30(func_020e3218(data_ov003_02210990),1);
func_0207c780((u8 *)res+0x92c,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x6400);
func_020e35cc(res);gCur3DSpriteEngine=saved;
if(func_ov003_0220151c(p))return;
saved2=gCur3DSpriteEngine;gCur3DSpriteEngine=(u16 **)g3DSpriteEngineSub;
func_0200bc5c(data_ov003_022109a4);func_01ff9ce8(3);
func_ov003_022005e4(3,2,func_ov003_022023fc(p));
func_ov003_021ea134(3);
func_01ff9dd8(0);func_01ff9dd8(1);func_01ff9ce8(0);func_01ff9ce8(1);
for(i=0;i<(u32)func_ov003_022023fc(p);i++){
if(func_0207c928(i,2)==0)side=0;else side=1;
side2=(u8)side;
if(i<2)offset=0;else offset=func_ov003_02202408((u16)func_ov003_022004f0(2));
character=func_020a22fc(i+1);
if(character==0){
func_020809c0((u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine+side*4,void**,0x20)+(offset+1)*2,7,7);
}else{
slot=(i<<7)+2;
func_020985b0(character,1,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,12)+(slot<<5));
func_02098844(1,offset,0,(u8 *)M2C_FIELD((u8 *)gCur3DSpriteEngine+side*4,void**,0x20)+2,(u16)((u32)slot>>1),i,0);
func_02098a34(character,1,side2,i,0);
}
}
func_ov003_021ea134(0);func_ov003_021ea134(1);
func_0200bc5c(data_ov003_022109ac);
res=func_02080e30(func_020e3218(data_ov003_022109b4),1);
func_0207c780((u8 *)res+0x67c,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x2800);
func_020e35cc(res);
func_ov003_021ea27c(4,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x3000);
func_ov003_021ea294(5,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void**,0x30)+0x2c0);
func_ov003_021ea2ac();gCur3DSpriteEngine=saved2;
}
u8 func_ov003_02201500(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_0220151c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Set bits 4-8 of the word pointed to by *gCur3DSpriteEngine from five boolean flags. */
void func_ov003_0220153c(s32 flag0, s32 flag1, s32 flag2, s32 flag3, u8 flag4) {
u16 * volatile reg0;
u16 * volatile reg1;
u16 * volatile reg2;
u16 * volatile reg3;
u16 * volatile reg4;
reg0 = *gCur3DSpriteEngine; *reg0 = (*reg0 & ~16) | ((u32)(flag0 << 31) >> 27);
reg1 = *gCur3DSpriteEngine; *reg1 = (*reg1 & ~32) | ((u32)(flag1 << 31) >> 26);
reg2 = *gCur3DSpriteEngine; *reg2 = (*reg2 & ~64) | ((u32)(flag2 << 31) >> 25);
reg3 = *gCur3DSpriteEngine; *reg3 = (*reg3 & ~128) | ((u32)(flag3 << 31) >> 24);
reg4 = *gCur3DSpriteEngine; *reg4 = (*reg4 & ~256) | ((u32)(flag4 << 31) >> 23);
}

void func_ov003_02201620(void *arg0, s32 arg1) {
    void *func_02082028(s32);
    s32 func_0207c928(s32, s32);
    s32 func_0207c8ec(s32, s32);
    void *func_020ab1c4(s32);
    void func_020aab24(void *, s32, s32, s32, s32);
    void func_02088e84(void *, s32, s32, s32, s32);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    void *func_02087d84(void *, s32, s16, s16, s32, s32);
    void func_ov003_02200dc8(void *, s32);
    extern u32 data_ov003_022107c4[];
    extern u32 data_ov003_02210774[];
    extern u32 data_ov003_0221088c[];
    extern u32 data_ov003_02210864[];
    extern u32 data_ov003_0221083c[];
    extern u32 data_ov003_02210814[];
    extern u32 data_ov003_022107ec[];
    extern u32 data_ov003_0221079c[];
    extern u16 data_ov003_022104fa[];
    s32 tmp1, tmp2;
    s32 r6, r5, r11, r10;
    u8 *cell;
    void *obj;
    void *vt;
    u8 i;

    i = 0;
    do {
        if (i < 8) {
            switch (i) {
            case 0:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_022107c4;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 1:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_02210774;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 2:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_0221088c;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 3:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_02210864;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 4:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_0221083c;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 5:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_02210814;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 6:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_022107ec;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            case 7:
                obj = func_02082028(4);
                if (obj != 0) M2C_FIELD(obj, void **, 0) = data_ov003_0221079c;
                M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8) = obj;
                break;
            }
            obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(obj, void **, 0);
            tmp1 = ((s32 (*)(void *)) ((void **) vt)[3])(obj);
            obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(obj, void **, 0);
            tmp2 = ((s32 (*)(void *)) ((void **) vt)[2])(obj);
            cell = (u8 *)arg0 + i * 0x18;
            M2C_FIELD(cell, s32 *, 0x10) = tmp1;
            if (M2C_FIELD(cell, u8 *, 0x1c) != 0) {
                while (M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10))
                    M2C_FIELD(cell, s32 *, 0xc) -= M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
                while (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14))
                    M2C_FIELD(cell, s32 *, 0xc) += M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
            } else {
                M2C_FIELD(cell, s32 *, 0xc) = M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10) ? M2C_FIELD(cell, s32 *, 0x10) : (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14) ? M2C_FIELD(cell, s32 *, 0x14) : M2C_FIELD(cell, s32 *, 0xc));
            }
            M2C_FIELD(cell, s32 *, 0x14) = tmp2;
            if (M2C_FIELD(cell, u8 *, 0x1c) != 0) {
                while (M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10))
                    M2C_FIELD(cell, s32 *, 0xc) -= M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
                while (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14))
                    M2C_FIELD(cell, s32 *, 0xc) += M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
            } else {
                M2C_FIELD(cell, s32 *, 0xc) = M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10) ? M2C_FIELD(cell, s32 *, 0x10) : (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14) ? M2C_FIELD(cell, s32 *, 0x14) : M2C_FIELD(cell, s32 *, 0xc));
            }
            obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(obj, void **, 0);
            if (((s32 (*)(void *)) ((void **) vt)[5])(obj) != 0) M2C_FIELD(cell, u8 *, 0x1c) = 1;
            obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(obj, void **, 0);
            M2C_FIELD(cell, s32 *, 0x18) = ((s32 (*)(void *)) ((void **) vt)[4])(obj);
            obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xc8);
            vt = M2C_FIELD(obj, void **, 0);
            M2C_FIELD(cell, s32 *, 0xc) = ((s32 (*)(void *)) ((void **) vt)[6])(obj);
            if (M2C_FIELD(cell, u8 *, 0x1c) != 0) {
                while (M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10))
                    M2C_FIELD(cell, s32 *, 0xc) -= M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
                while (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14))
                    M2C_FIELD(cell, s32 *, 0xc) += M2C_FIELD(cell, s32 *, 0x10) - M2C_FIELD(cell, s32 *, 0x14) + 1;
            } else {
                M2C_FIELD(cell, s32 *, 0xc) = M2C_FIELD(cell, s32 *, 0xc) > M2C_FIELD(cell, s32 *, 0x10) ? M2C_FIELD(cell, s32 *, 0x10) : (M2C_FIELD(cell, s32 *, 0xc) < M2C_FIELD(cell, s32 *, 0x14) ? M2C_FIELD(cell, s32 *, 0x14) : M2C_FIELD(cell, s32 *, 0xc));
            }
            r6 = (s16)(func_0207c928(i, 4) * 64 + 4);
            r5 = (s16)(func_0207c8ec(i, 4) * 0x48 + 0x38);
            r11 = 0x38;
            r10 = 0x10;
        } else {
            r6 = 0x70;
            r5 = 0xa4;
            r11 = 0x20;
            r10 = 0x18;
        }
        obj = func_020ab1c4(arg1);
        M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8) = obj;
        M2C_FIELD(obj, u16 *, 0x2e) = i;
        func_020aab24(M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8), 0x47, 0x16c, 0, 0);
        obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8);
        func_02088e84(obj, r6, r5, r6, r5);
        {
            u8 b1;
            s16 a1, c1;
            u16 e1;
            s32 d1;
            if (M2C_FIELD(M2C_FIELD(obj, void **, 0x64), u8 *, 0x12) != 0) b1 = 1; else b1 = 0;
            if (b1 & 0xFF) {
                a1 = M2C_FIELD(obj, s16 *, 0x52);
                c1 = M2C_FIELD(obj, s16 *, 0x50);
                e1 = func_020aae10(obj);
                d1 = func_020aae44(obj);
                func_02087d84(M2C_FIELD(obj, void **, 0x64), 1, c1, a1, (s32)((u32)e1 << 16 >> 16), (s32)((u32)d1 << 16 >> 16));
            }
        }
        M2C_FIELD(obj, s16 *, 0x34) = (s16)r6;
        M2C_FIELD(obj, s16 *, 0x36) = (s16)r5;
        {
            u8 b2;
            s16 a2, c2;
            u16 e2;
            s32 d2;
            if (M2C_FIELD(M2C_FIELD(obj, void **, 0x64), u8 *, 0x12) != 0) b2 = 1; else b2 = 0;
            if (b2 & 0xFF) {
                a2 = M2C_FIELD(obj, s16 *, 0x52);
                c2 = M2C_FIELD(obj, s16 *, 0x50);
                e2 = func_020aae10(obj);
                d2 = func_020aae44(obj);
                func_02087d84(M2C_FIELD(obj, void **, 0x64), 1, c2, a2, (s32)((u32)e2 << 16 >> 16), (s32)((u32)d2 << 16 >> 16));
            }
        }
        M2C_FIELD(obj, u32 *, 0x40) = (M2C_FIELD(obj, u32 *, 0x40) & 0xFFFFFE00) | (r11 & 0x1FF);
        M2C_FIELD(obj, u32 *, 0x40) = (M2C_FIELD(obj, u32 *, 0x40) & 0xFFFC01FF) | (r10 << 9);
        {
            u8 b3;
            s16 a3, c3;
            u16 e3;
            s32 d3;
            if (M2C_FIELD(M2C_FIELD(obj, void **, 0x64), u8 *, 0x12) != 0) b3 = 1; else b3 = 0;
            if (b3 & 0xFF) {
                a3 = M2C_FIELD(obj, s16 *, 0x52);
                c3 = M2C_FIELD(obj, s16 *, 0x50);
                e3 = func_020aae10(obj);
                d3 = func_020aae44(obj);
                func_02087d84(M2C_FIELD(obj, void **, 0x64), 1, c3, a3, (s32)((u32)e3 << 16 >> 16), (s32)((u32)d3 << 16 >> 16));
            }
        }
        obj = M2C_FIELD((u8 *)arg0 + i * 4, void **, 0xe8);
        M2C_FIELD(obj, s16 *, 0x68) = data_ov003_022104fa[i * 4 + 0];
        M2C_FIELD(obj, s16 *, 0x6a) = data_ov003_022104fa[i * 4 + 1];
        M2C_FIELD(obj, s16 *, 0x6c) = data_ov003_022104fa[i * 4 + 2];
        M2C_FIELD(obj, s16 *, 0x6e) = data_ov003_022104fa[i * 4 + 3];
        i++;
    } while (i < 9);
    func_ov003_02200dc8(arg0, 8);
}

#pragma push
#pragma opt_propagation on
void func_ov003_02201c78(void *arg0, s32 arg1) {
    void *func_02087d84(void *, s32, s16, s16, s32, s32);
    void func_02088da8(void *);
    void func_02088e84(void *, s32, s32, s32, s32);
    void func_020aab24(void *, s32, s32, s32, s32);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    void *func_020ab1c4(s32);
    void *temp_r4;
    s16 temp_r5;
    s16 temp_r6;
    u16 temp_r7;
    s32 temp_r0;
    s32 var_r0;
    void *temp_r4_2;
    s16 temp_r5_2;
    s16 temp_r6_2;
    u16 temp_r7_2;
    s32 temp_r0_2;
    s32 var_r0_2;
    s32 zero4;
    s32 three;
    s32 val15c;
    s32 eight;
    s32 zero7;
    u8 var_r8;
    void *temp_r1;
    void *temp_r0ptr;

    M2C_FIELD(arg0, void **, 0) = func_020ab1c4(arg1);
    func_020aab24(M2C_FIELD(arg0, void **, 0), 2, 0x14C, 3, 1);
    temp_r4 = M2C_FIELD(arg0, void **, 0);
    func_02088e84(temp_r4, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r5 = M2C_FIELD(temp_r4, s16 *, 0x52);
        temp_r6 = M2C_FIELD(temp_r4, s16 *, 0x50);
        temp_r7 = func_020aae10(temp_r4);
        temp_r0 = func_020aae44(temp_r4);
        func_02087d84(M2C_FIELD(temp_r4, void **, 0x64), 1, temp_r6, temp_r5,
                      (s32)((u32)temp_r7 << 16 >> 16), (s32)((u32)temp_r0 << 16 >> 16));
    }
    func_02088da8(M2C_FIELD(arg0, void **, 0));
    M2C_FIELD(arg0, void **, 4) = func_020ab1c4(arg1);
    func_020aab24(M2C_FIELD(arg0, void **, 4), 0x20, 0x140, 3, 0);
    temp_r4_2 = M2C_FIELD(arg0, void **, 4);
    func_02088e84(temp_r4_2, 0x70, 0xA4, 0x70, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r5_2 = M2C_FIELD(temp_r4_2, s16 *, 0x52);
        temp_r6_2 = M2C_FIELD(temp_r4_2, s16 *, 0x50);
        temp_r7_2 = func_020aae10(temp_r4_2);
        temp_r0_2 = func_020aae44(temp_r4_2);
        func_02087d84(M2C_FIELD(temp_r4_2, void **, 0x64), 1, temp_r6_2, temp_r5_2,
                      (s32)((u32)temp_r7_2 << 16 >> 16), (s32)((u32)temp_r0_2 << 16 >> 16));
    }
    func_02088da8(M2C_FIELD(arg0, void **, 4));

    var_r8 = 0;
    zero7 = var_r8;
    eight = 8;
    val15c = 0x15C;
    three = 3;
    zero4 = var_r8;
    do {
        temp_r0ptr = func_020ab1c4(arg1);
        temp_r1 = (void *)((u8 *)arg0 + (var_r8 * 4));
        M2C_FIELD((u8 *)arg0 + var_r8 * 4, void **, 8) = temp_r0ptr;
        func_020aab24(M2C_FIELD((u8 *)arg0 + var_r8 * 4, void **, 8), eight, val15c, three, zero7);
        func_02088da8(M2C_FIELD((u8 *)arg0 + var_r8 * 4, void **, 8));
        temp_r0ptr = func_020ab1c4(arg1);
        M2C_FIELD((u8 *)arg0 + var_r8 * 4, void **, 0x28) = temp_r0ptr;
        func_020aab24(M2C_FIELD((u8 *)arg0 + var_r8 * 4, void **, 0x28), 9, 0x164, 3, zero4);
        func_02088da8(M2C_FIELD((u8 *)arg0 + var_r8 * 4, void **, 0x28));
        var_r8 += 1;
    } while ((u32)var_r8 < 8U);
}
#pragma pop
