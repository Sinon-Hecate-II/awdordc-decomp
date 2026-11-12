/* 44 functions from 0x020B160C to 0x020B25B8 (main), found by ds-decomp. */
#include "common.h"
#include "sprite_slot.h"

void func_020b160c(void){
s32 func_020a7290(void);void *func_020a7278(void);void *func_020a7284(void);
M2C_UNK MI_CpuCopy32(M2C_UNK *,s32,M2C_UNK);void func_01ff9e44(void *,s32,s32);void func_020c09c0(s32);
extern void *gCur3DSpriteEngine;extern void *gCurrentMap;extern u8 data_02120a20[];
s32 n;void *p;
n=func_020a7290()<<5;p=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0x10);
MI_CpuCopy32(func_020a7278(),p+0x25c0,n);
p=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0x10)+0x4e0;
MI_CpuCopy32(func_020a7284(),p+0x3000,0x3c0);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,26701)-1)*32,384,32);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,26841)-1)*32,416,32);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,26981)-1)*32,448,32);
func_01ff9e44(data_02120a20+(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,27121)-1)*32,480,32);
func_020c09c0(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4));}

void func_020b172c(void) {
    M2C_UNK func_02091d20();
    M2C_UNK func_020d672c();
    M2C_UNK func_ov000_02169368();
    extern void *gCurrentMap;
    M2C_UNK (*temp_r2)(u8, u8);
    void *temp_r0;

    func_ov000_02169368();
    func_02091d20();
    func_020d672c();
    temp_r2 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(u8, u8), 0x58);
    if (temp_r2 == NULL) {
        return;
    }
    temp_r0 = M2C_FIELD(gCurrentMap, void **, 0);
    temp_r2(M2C_FIELD(temp_r0, u8 *, 0x5158), M2C_FIELD(temp_r0, u8 *, 0x5157));
}

void func_020b1770(void) {
    M2C_UNK MI_CpuCopy32(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_020f3ca0;
    extern void *gCur3DSpriteEngine;
    MI_CpuCopy32(&data_020f3ca0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC) + 0x2480, 0xA0);
}

void func_020b179c(void) {
 M2C_UNK MI_CpuCopy32(M2C_UNK *,s32,M2C_UNK);
 M2C_UNK func_020c0a88();
 extern void *gCur3DSpriteEngine;
 void *p; s32 src; M2C_UNK *dst;
 p=gCur3DSpriteEngine; src=M2C_FIELD(p,volatile s32 *,0x10); dst=M2C_FIELD(p,M2C_UNK * volatile *,0x24);
 MI_CpuCopy32(dst,src,0x800);
 p=gCur3DSpriteEngine; src=M2C_FIELD(p,volatile s32 *,0x14); dst=M2C_FIELD(p,M2C_UNK * volatile *,0x28);
 MI_CpuCopy32(dst,src,0x800); func_020c0a88();
}

void func_020b17dc(void) {
    M2C_UNK func_0207a768();
    M2C_UNK RefreshMapView();
    RefreshMapView();
    func_0207a768();
}

void func_020b17ec(void) {
    void func_020b1800(void);
    M2C_UNK func_02002bb8(M2C_UNK);
    func_020b1800();
    func_02002bb8(0x40);
}

void func_020b1800(void) {
    M2C_UNK func_02003584();
    M2C_UNK func_02003560();
    func_02003560();
    func_02003584();
}

void func_020b1810(void) {
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002bb8(M2C_UNK);
    M2C_UNK GX_SetBankForTex(M2C_UNK);
    M2C_UNK func_02002e3c(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_02082c84();
    func_02082c84();
    GX_SetBankForTex(3);
    GX_SetBankForBG(8);
    func_02002968(0x10);
    func_02002e3c(0x20);
    func_02002bb8(0x40);
    func_02003124(4);
    func_020031cc(0x100);
    func_0200323c(0x80);
}

void func_020b185c(void) {
    extern void *gCurrentMap, *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    void *saved;
    void (*callback)(void);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_020aca8c(3);
    func_0207b84c();
    func_02077a7c();
    func_02082700();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x1c);
    if (callback != NULL) callback();
    func_02091cd0();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);
    if (callback != NULL) callback();
    func_020b172c();
    func_020b179c();
    func_020b17dc();
    func_01ff9e00();
    gCur3DSpriteEngine = saved;
}

void func_020b18ec(void) {
extern void *gCurrentMap,*gCur3DSpriteEngine;
u16 *volatile sp4;u16 *volatile sp0;void (*callback)(void);
func_020aca8c(3);func_0207b940();
sp4=(u16 *)*(void **)gCur3DSpriteEngine;*sp4=*sp4|0x1000;
sp0=(u16 *)*(void **)gCur3DSpriteEngine;*sp0=*sp0&~0x6000;
func_02082700();
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x1c);if(callback)callback();
func_01ff9b38();func_02091cd0();
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x54);if(callback)callback();
func_020b1770();func_020b172c();func_020b179c();func_020b17dc();
}

void func_020b19a8(s32 arg0, s32 arg1) {
    M2C_UNK func_01ff9e78(void *, s32, M2C_UNK);
    extern u8 data_020f3c20[];
    func_01ff9e78(data_020f3c20 + arg1 * 2, ((arg0 + 0xB) << 5) + 0x1E, 2);
}

void func_020b19d0(s32 arg0, s32 arg1) {
    M2C_UNK func_0207c55c(void *, s32, M2C_UNK, M2C_UNK);
    s32 func_020d1a74(void);
    extern u8 data_020f3c20[];
    extern void *gCurrentMap;
    s32 offset;
    s32 first;
    s32 second;
    if (func_020d1a74() != 0) {
        first = 0;
        second = 8;
    } else {
        first = 8;
        second = 0;
    }
    offset = arg0 * 0x8C;
    func_0207c55c(data_020f3c20 + arg1 * 2, ((first + (M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + offset, u8 *, 0x67C1) - 1)) << 5) + 0x121E, 2, 0);
    func_0207c55c(data_020f3c20, ((second + (M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + offset, u8 *, 0x67C1) - 1)) << 5) + 0x121E, 2, 0);
}

void func_020b1a84(void) {

}

void func_020b1a88(void) {

}

void func_020b1a8c(s32 arg0) {
    M2C_UNK func_0207c55c(void *, s32, M2C_UNK, M2C_UNK);
    extern u8 data_021206e0[];
    func_0207c55c(data_021206e0 + ((u32)((arg0 >> 2) << 28) >> 27), 0x1448, 2, 0);
}

void func_020b1abc(void) {
    M2C_UNK func_0207a77c(s32);
    M2C_UNK func_0207ad30(s32);
    extern s32 gFrameCounter;
    func_0207a77c(gFrameCounter);
    func_0207ad30(gFrameCounter);
}

void func_020b1ae0(void) {
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *gCurrentMap;
extern u8 data_02128000[];
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
M2C_FIELD(gCurrentMap,void **,4)=data_02128000;
gCur3DSpriteEngine=saved;
}

u8 SpriteSlotHasFlags(void *arg0, s32 arg1) {
    return (u8) (M2C_FIELD(arg0, u16 *, 0x1C) & arg1);
}

void SetSpriteSlotState(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 3) = arg1;
}

u8 GetSpriteSlotState(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 3);
}

void func_020b1b3c(void) {
extern u8 gSpriteSlots[];
extern void *gSpriteSlotManager;
s32 i;
u8 *p=gSpriteSlots;
for(i=0;i<85;i++,p+=60) p[1]=0;
M2C_FIELD(gSpriteSlotManager,s32 *,0)=8;
M2C_FIELD(gSpriteSlotManager,s32 *,4)=0;
M2C_FIELD(gSpriteSlotManager,s32 *,12)=0;
M2C_FIELD(gSpriteSlotManager,u8 *,8)=0;
M2C_FIELD(gSpriteSlotManager,u8 *,0x24)=0;
M2C_FIELD(gSpriteSlotManager,u8 *,0x25)=0;
M2C_FIELD(gSpriteSlotManager,u8 *,0x26)=0;
M2C_FIELD(gSpriteSlotManager,u8 *,0x27)=0;
}

s32 func_020b1bb0(void) {
extern void *gSpriteSlotManager;
void *p=M2C_FIELD(gSpriteSlotManager,void **,12);
if(!p || !M2C_FIELD(p,u8 *,1) || (u8)(M2C_FIELD(p,u8 *,4)+253)<=1) return 0;
return 1;
}

void func_020b1bf4(s16 a,s16 b,s16 c,s16 d) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,s16 *,0x10)=a;
M2C_FIELD(gSpriteSlotManager,s16 *,0x12)=b;
M2C_FIELD(gSpriteSlotManager,s16 *,0x14)=c;
M2C_FIELD(gSpriteSlotManager,s16 *,0x16)=b;
M2C_FIELD(gSpriteSlotManager,s16 *,0x18)=a;
M2C_FIELD(gSpriteSlotManager,s16 *,0x1a)=d;
M2C_FIELD(gSpriteSlotManager,s16 *,0x1c)=c;
M2C_FIELD(gSpriteSlotManager,s16 *,0x1e)=d;
}

void func_020b1c44(s16 a,s16 b) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,s16 *,0x20)=a;
M2C_FIELD(gSpriteSlotManager,s16 *,0x22)=b;
}

s32 FocusSpriteSlotById(s32 arg0) {
    s32 func_020b20e0(void);
    M2C_UNK func_020b1ca0(u8 *, s32);
    func_020b1ca0((u8 *)func_020b20e0(), arg0);
}

s32 func_020b1c78(void) {
    s32 FocusSpriteSlotById();
    void func_020b204c();
    s32 temp_r4;

    temp_r4 = FocusSpriteSlotById();
    func_020b204c();
    return temp_r4;
}

void FocusSpriteSlot(u8 *arg0) {
    M2C_UNK func_020b1ca0(u8 *, s32);
    func_020b1ca0(arg0, *arg0);
}

M2C_UNK func_020b1ca0(u8 *arg0,s32 arg1) {
extern void *gSpriteSlotManager;
void func_020b2e60(void *);
s32 changed;
if(func_020b1bb0() && arg0 && M2C_FIELD(gSpriteSlotManager,void **,12)!=arg0) changed=1;
else changed=0;
M2C_FIELD(gSpriteSlotManager,void **,12)=arg0;
M2C_FIELD(gSpriteSlotManager,u8 *,8)=arg1;
if(changed) func_020b2e60(M2C_FIELD(gSpriteSlotManager,void **,12));
return (M2C_UNK)M2C_FIELD(gSpriteSlotManager,void **,12);
}

void func_020b1d14(void){extern void *gSpriteSlotManager,*gKeyState,*gTouchState;void *p;void (*f)(void *);if(!func_020b1bb0())return;p=M2C_FIELD(gSpriteSlotManager,void **,12);if(M2C_FIELD(p,u8 *,4)!=2)return;if(!M2C_FIELD(gKeyState,u16 *,2))return;if(M2C_FIELD(gTouchState,u8 *,18))return;f=M2C_FIELD(p,void (**)(void *),40);if(!f)return;f(p);}

#pragma push
#pragma opt_common_subs on
void func_020b1d84(void *arg0, s32 arg1, void *arg2) {
extern void *gSpriteSlotManager, *gTouchState, *gCur3DSpriteEngine;
s32 func_020b20e0();
void func_0208df84(s16,s16,s16,s16,u16,s32);
void *p,*q; s32 x,y,r,b,d,v,n,out; s32 force; u16 flags;
FocusSpriteSlotById(M2C_FIELD(gSpriteSlotManager,u8 *,8));
if (!func_020b1bb0()) return;
p=gSpriteSlotManager; q=M2C_FIELD(p,void **,12);
x=M2C_FIELD(q,s16 *,20);y=M2C_FIELD(q,s16 *,22);
b=y+M2C_FIELD(q,s16 *,26); r=x+M2C_FIELD(q,s16 *,24);
force=M2C_FIELD(gTouchState,u8 *,18); if(force==0){
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,16);d=x-v;n=d<0?-d:d; if(n<=1)v=x; else v=M2C_FIELD(p,s16 *,16)+(d>>1); M2C_FIELD(p,s16 *,16)=v;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,18);d=y-v;n=d<0?-d:d; if(n<=1)out=y; else out=v+(d>>1); M2C_FIELD(p,s16 *,18)=out;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,20);d=r-v;n=d<0?-d:d; if(n<=1)out=r; else out=v+(d>>1); M2C_FIELD(p,s16 *,20)=out;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,22);d=y-v;n=d<0?-d:d; if(n>1)y=v+(d>>1); M2C_FIELD(p,s16 *,22)=y;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,24);d=x-v;n=d<0?-d:d; if(n>1)x=v+(d>>1); M2C_FIELD(p,s16 *,24)=x;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,26);d=b-v;n=d<0?-d:d; if(n<=1)out=b; else out=v+(d>>1); M2C_FIELD(p,s16 *,26)=out;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,28);d=r-v;n=d<0?-d:d; if(n>1)r=v+(d>>1); M2C_FIELD(p,s16 *,28)=r;
p=gSpriteSlotManager; v=M2C_FIELD(p,s16 *,30);d=b-v;n=d<0?-d:d; if(n>1)b=v+(d>>1); M2C_FIELD(p,s16 *,30)=b;
}else{
M2C_FIELD(gSpriteSlotManager,s16 *,16)=(s16)x;
M2C_FIELD(gSpriteSlotManager,s16 *,18)=(s16)y;
M2C_FIELD(gSpriteSlotManager,s16 *,20)=(s16)r;
M2C_FIELD(gSpriteSlotManager,s16 *,22)=(s16)y;
M2C_FIELD(gSpriteSlotManager,s16 *,24)=(s16)x;
M2C_FIELD(gSpriteSlotManager,s16 *,26)=(s16)b;
M2C_FIELD(gSpriteSlotManager,s16 *,28)=(s16)r;
M2C_FIELD(gSpriteSlotManager,s16 *,30)=(s16)b;
}
p=(void*)func_020b20e0(M2C_FIELD(gSpriteSlotManager,u8 *,8));
if(!SpriteSlotHasFlags(p,1))return;
SpriteSlotHasFlags(p,0x800);
q=gSpriteSlotManager;
x=M2C_FIELD(q,s16 *,16);y=M2C_FIELD(q,s16 *,18);
flags=(u16)(((0x80 >> ((u32)(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x1000);
func_0208df84((s16)(x+M2C_FIELD(q,s16 *,32)),(s16)(y+M2C_FIELD(q,s16 *,34)),(s16)(M2C_FIELD(q,s16 *,28)-x),(s16)(M2C_FIELD(q,s16 *,30)-y),flags,0);
}
#pragma pop
void func_020b204c(void){extern void *gSpriteSlotManager;void *p; s32 d,c,b,a,sum;p=M2C_FIELD(gSpriteSlotManager,void **,12);if(!p)return;a=M2C_FIELD(p,s16 *,20);b=M2C_FIELD(p,s16 *,22);c=M2C_FIELD(p,s16 *,24);d=M2C_FIELD(p,s16 *,26);M2C_FIELD(gSpriteSlotManager,s16 *,16)=(s16)a;M2C_FIELD(gSpriteSlotManager,s16 *,18)=(s16)b;M2C_FIELD(gSpriteSlotManager,s16 *,20)=(s16)(a+c);sum=b+d;M2C_FIELD(gSpriteSlotManager,s16 *,22)=(s16)b;M2C_FIELD(gSpriteSlotManager,s16 *,24)=(s16)a;M2C_FIELD(gSpriteSlotManager,s16 *,26)=(s16)sum;M2C_FIELD(gSpriteSlotManager,s16 *,28)=(s16)(a+c);M2C_FIELD(gSpriteSlotManager,s16 *,30)=(s16)sum;}

s32 func_020b20e0(a) s32 a; {extern u8 gSpriteSlots[];s32 i=0;u8 *p=gSpriteSlots;do{if(p[1]&&a==p[0])return (s32)gSpriteSlots+60*i;i++;p+=60;}while(i<85);return 0;}

u8 func_020b212c(void) {
    extern void *gSpriteSlotManager;
    return M2C_FIELD(gSpriteSlotManager, u8 *, 8);
}

void func_020b2140(void) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,u8 *,0x25)=0;
}

void func_020b2158(s8 arg0) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,s8 *,0x25)=arg0;
}

void func_020b216c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 1) = 0;
}

void func_020b2178(void){extern u8 gSpriteSlots[];s32 i=0;u8 *p=gSpriteSlots;u8 zero=i;do{i++;p[1]=zero;p+=60;}while(i<85);}

void func_020b21a0(void) {
extern u8 gSpriteSlots[];
s32 i=0; u8 *p=gSpriteSlots;
do { if(SpriteSlotHasFlags(p,1)!=0) p[1]=0; i++;p+=0x3c; } while(i<0x55);
}

void func_020b21e0(void) {
extern u8 gSpriteSlots[];
s32 i; u8 *p;
p=gSpriteSlots; i=0;
do { if(SpriteSlotHasFlags(p,1)!=1) M2C_FIELD(p,u16 *,0x1c)|=0x400; i++;p+=0x3c; } while(i<0x55);
}

void func_020b2224(void) {
extern u8 gSpriteSlots[];
s32 i; u8 *p;
p=gSpriteSlots; i=0;
do { if(SpriteSlotHasFlags(p,1)!=1) M2C_FIELD(p,u16 *,0x1c)&=~0x400; i++;p+=0x3c; } while(i<0x55);
}

void func_020b2268(void) {
    extern u8 gSpriteSlots[];
    s32 i;
    u8 *p;

    p = gSpriteSlots;
    i = 0;
    do {
        if ((p[1] != 0) && (p[4] < 3U)) {
            p[4] = 3U;
        }
        i += 1;
        p += 0x3C;
    } while (i < 0x55);
}

s32 func_020b22a4(s32 a,s32 b,void *c,s32 d) {
s32 func_020b2304(s32,s32,void *,void *,s32);
extern u8 gSpriteSlots[];
u8 *p=gSpriteSlots; s32 i=0;
do { if(p[1]==0) return func_020b2304(a,b,gSpriteSlots+i*0x3c,c,d); i++;p+=0x3c; } while(i<0x54);
return 0;
}

/* Initialize a 0x3C-byte sprite slot (arg2) at board position (x + arg3->dx,
   y + arg3->dy) from the spawn descriptor arg3 (size at +4/+6, rectangles and
   palette at +8..+0xE, six extra dwords at +0x10..+0x24); arg4 is the slot's id.
   The slot is marked visible (byte 1) and gSpriteSlotManager records which screen it
   was created on.  Returns the slot. */
s32 func_020b2304(s32 x, s32 y, void *slot, void *desc, s32 id) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *gSpriteSlotManager;
    s16 t;
    u8 onUpperScreen;

    t = *(s16 *)((s8 *)desc + 0);
    *(s16 *)((s8 *)slot + 0x14) = (s16)(x + t);

    t = *(s16 *)((s8 *)desc + 2);
    *(s16 *)((s8 *)slot + 0x16) = (s16)(y + t);

    *(s16 *)((s8 *)slot + 0x18) = *(s16 *)((s8 *)desc + 4);
    *(s16 *)((s8 *)slot + 0x1a) = *(s16 *)((s8 *)desc + 6);
    *(u16 *)((s8 *)slot + 0x1c) = *(u16 *)((s8 *)desc + 8);
    *(u16 *)((s8 *)slot + 0x1e) = *(u16 *)((s8 *)desc + 0xa);
    *(u16 *)((s8 *)slot + 0x20) = *(u16 *)((s8 *)desc + 0xc);
    *(u16 *)((s8 *)slot + 0x22) = *(u16 *)((s8 *)desc + 0xe);
    *(s32 *)((s8 *)slot + 0x24) = *(s32 *)((s8 *)desc + 0x10);
    *(s32 *)((s8 *)slot + 0x28) = *(s32 *)((s8 *)desc + 0x14);
    *(s32 *)((s8 *)slot + 0x2c) = *(s32 *)((s8 *)desc + 0x18);
    *(s32 *)((s8 *)slot + 0x30) = *(s32 *)((s8 *)desc + 0x1c);
    *(s32 *)((s8 *)slot + 0x34) = *(s32 *)((s8 *)desc + 0x20);
    *(s32 *)((s8 *)slot + 0x38) = *(s32 *)((s8 *)desc + 0x24);

    *(u8 *)((s8 *)slot + 0) = (u8)id;
    *(u8 *)((s8 *)slot + 3) = 0;
    *(u8 *)((s8 *)slot + 4) = 0;

    t = *(s16 *)((s8 *)slot + 0x14);
    *(s16 *)((s8 *)slot + 0xa) = t;
    *(s16 *)((s8 *)slot + 0x6) = t;

    t = *(s16 *)((s8 *)slot + 0x16);
    *(s16 *)((s8 *)slot + 0xc) = t;
    *(s16 *)((s8 *)slot + 0x8) = t;

    *(s16 *)((s8 *)slot + 0xe) = 0;
    *(u8 *)((s8 *)slot + 1) = 1;

    onUpperScreen = (u8)(gCur3DSpriteEngine == g3DSpriteEngineMain);
    if (onUpperScreen) {
        M2C_FIELD(gSpriteSlotManager, u8 *, 0x24) = 0;
    } else {
        M2C_FIELD(gSpriteSlotManager, u8 *, 0x24) = 1;
    }

    return (s32)slot;
}

/* Runs one frame of the sprite-slot system: for the main and sub screens it focuses
 * the slot under the touch, animates every visible slot, handles touch on the active
 * ones (unless a slot already took focus), then calls each visible slot's per-frame
 * callback and the focused-slot key handler. */
void UpdateSpriteSlots(void) {
s32 func_020b2714(void); s32 func_020b26b8(void); s32 TryFocusSpriteSlot(u8 *);
void AnimateSpriteSlot(u8 *); s32 HandleSpriteSlotTouch(u8 *); void func_020b1d14(void);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub,*gSpriteSlotManager;
extern u8 gSpriteSlots[];
s32 slotFocused=0; void *savedEngine; s32 pass; s32 i; u8 *slot;
if(func_020b2714())return;
if(func_020b26b8())return;
savedEngine=gCur3DSpriteEngine;
for(pass=0;pass<2;pass++){
void *engine=pass==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
u8 slotScreen;
gCur3DSpriteEngine=engine;
slotScreen=M2C_FIELD(gSpriteSlotManager,u8 *,SPRITE_SLOT_MGR_SCREEN);
if(slotScreen==0 && engine!=g3DSpriteEngineMain)continue;
if(slotScreen==1 && engine!=g3DSpriteEngineSub)continue;
if(slotScreen==3 && engine!=savedEngine)continue;
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE){
if(slot[SPRITE_SLOT_VISIBLE] && TryFocusSpriteSlot(slot)){
if(M2C_FIELD(gSpriteSlotManager,u8 *,SPRITE_SLOT_MGR_HAS_FOCUS))slotFocused=1;
break;
}
}
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE)if(slot[SPRITE_SLOT_VISIBLE])AnimateSpriteSlot(slot);
if(slotFocused==0){
s32 touchResult=0;
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE){
if(slot[SPRITE_SLOT_VISIBLE]){
if(slot[SPRITE_SLOT_ANIM]==2)touchResult=HandleSpriteSlotTouch(slot);
if(touchResult)break;
}
}
}
slot=gSpriteSlots;
for(i=0;i<SPRITE_SLOT_COUNT;i++,slot+=SPRITE_SLOT_STRIDE){
if(slot[SPRITE_SLOT_VISIBLE]){
void (*updateCallback)(void *)=*(void (**)(void *))(slot+SPRITE_SLOT_UPDATE_CB);
if(updateCallback)updateCallback(slot);
}
}
func_020b1d14();
}
gCur3DSpriteEngine=savedEngine;
}

