/* 18 functions from 0x020DE264 to 0x020DF1D0 (main), found by ds-decomp. */
#include "common.h"
typedef struct SetupSprite {
 u8 pad[0x40];
 unsigned field0:18;
 unsigned frame:8;
 unsigned field26:6;
 u8 pad44[0x15];
 u8 baseFrame:4;
 u8 alternate:1;
 u8 otherFlags:3;
} SetupSprite;
static inline u8 SetupIsActive(void *p) { return ((SetupSprite*)p)->baseFrame + 2 != (u16)((SetupSprite*)p)->frame; }
static inline void SetupSetFrame(void *p,u16 frame,s8 timer) { ((SetupSprite*)p)->frame=frame; M2C_FIELD(p,s8 *,0x5a)=timer; }
static inline s32 GetSetupCode(void *p) {
    s32 result=-1;
    switch(M2C_FIELD(p,s32 *,0x34)) {
    case 0:
        switch(M2C_FIELD(p,s32 *,0x38)) {case 1: result=2; break; default: result=4; break;}
        break;
    case 1: case 2: result=2; break;
    }
    return result;
}

#pragma opt_strength_reduction off
/* Sets up a scene/screen object: switches in the main sprite engine, loads the
 * palette and background chosen by GetSetupCode, sets the setup sprite's frame,
 * then registers the scene's per-variant update callback with overlay 10. */
M2C_UNK SetupScene(M2C_UNK setup, M2C_UNK mode) {
    void func_01ff9ce8(u8);
    void SetFileDirectory(void *);
    void *GetLocalizedFileName(void *);
    void func_020814e4(void *);
    void func_02081590(void *, void *);
    void func_02081528(void);
    void func_02080944(void *, s32, s32, s32);
    void func_0208e7ec(s32, s32);
    void func_02088f1c(void *);
    void func_02088da8(void *);
    void func_0208b758(void *, u32);
    s32 GetSpriteAnimValue(void *);
    void func_ov010_02228d48(s32, s32, s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK data_0212d428;
    extern M2C_UNK data_0212d430;
    extern M2C_UNK data_0212d440;
    extern M2C_UNK data_0212d450;
    s32 func_020de50c(s32, void *);
    s32 func_020de5b0(M2C_UNK);
    void func_020de610(void);

    void *savedEngine = gCur3DSpriteEngine;
    s32 setupCode;
    s32 setupCode2;
    void *ptr;
    u8 unusedLow;
    u32 unusedVal;
    s32 animValue;
    s32 variant;
    s32 unusedV34;
    s32 unusedV38;
    s32 updateFn;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    SetFileDirectory(&data_0212d428);
    func_020814e4(GetLocalizedFileName(&data_0212d430));

    setupCode=GetSetupCode((void*)setup);
    switch(setupCode) {
    case 4:func_02081590(GetLocalizedFileName(&data_0212d440),M2C_FIELD(gCur3DSpriteEngine,void **,0x20));break;
    case 2:func_02081590(GetLocalizedFileName(&data_0212d450),M2C_FIELD(gCur3DSpriteEngine,void **,0x20));break;
    }
    func_02081528();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_0208e7ec(0x3c00, 0x7);

    gCur3DSpriteEngine = savedEngine;

    M2C_FIELD((void *)setup, u16 *, 0x48) |= 0x20;

    ptr = M2C_FIELD((void *)setup, void **, 0x54);
    SetupSetFrame(ptr,(u16)(((SetupSprite*)ptr)->baseFrame+2),0);

    func_02088f1c(M2C_FIELD((void *)setup, void **, 0x58));
    func_02088da8(M2C_FIELD((void *)setup, void **, 0x60));
    func_0208b758(M2C_FIELD((void *)setup, void **, 0x64), 0x44000011U);
    func_02088f1c(M2C_FIELD((void *)setup, void **, 0x64));

    if (GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68)) != 0) {
        animValue = GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68));ptr=M2C_FIELD(setup,void **,0x68);
        M2C_FIELD(ptr, u16 *, 0xe) = (u16)animValue;
        M2C_FIELD(ptr, u16 *, 0x10) = 0;
        M2C_FIELD(ptr, u16 *, 0xc) = 0xc;
        M2C_FIELD(ptr, u16 *, 0x2) = M2C_FIELD(ptr, u16 *, 0x4);
    }
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x100;
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x200;

    updateFn=0;
    switch(M2C_FIELD(setup,s32 *,0x3c)) {
    case 0: M2C_FIELD(setup,u16 *,0x4a)=10;updateFn=(s32)func_020de50c;break;
    case 1: M2C_FIELD(setup,u16 *,0x4a)=10;updateFn=(s32)func_020de5b0;break;
    }

    M2C_FIELD((void *)setup, u8 *, 0x41) = 0;
    M2C_FIELD((void *)setup, u16 *, 0x4c) = 0x708;

    setupCode2=GetSetupCode((void*)setup);
    variant = M2C_FIELD((void *)setup, s32 *, 0x3c);
    func_ov010_02228d48((s32)mode, setupCode2, (s32)func_020de610, (s32)setup, updateFn, (s32)setup, variant);
}

s32 func_020de50c(s32 arg0, void *arg1) {
s32 func_0203c0b0(s32,s32 *,s32); void *func_ov010_02229b00(void); extern M2C_UNK data_0212c5d8;
s32 saved,a,n,v; register s32 d; s32 t; void *p;
p=func_ov010_02229b00();
if(!(M2C_FIELD(p,u8 *,0x1a)&2)) return -1;
saved=M2C_FIELD(p,s32 *,0x20);
d=(saved>>12)-(func_0203c0b0(arg0,&data_0212c5d8,0x5dc000)>>12);
if(d<0) a=-d; else a=d;
t=M2C_FIELD(arg1,u16 *,0x4a);
if(t<a) {n=t+20; if(n>=50000)n=50000; M2C_FIELD(arg1,u16 *,0x4a)=n;return -1;}
if(d<0)n=-d; else n=d;
v=0x7fffff-n;
if(v>0x7fffff)v=0x7fffff;
else if(v<0)v=0;
return v;
}

s32 func_020de5b0(M2C_UNK arg0) {
    M2C_UNK func_0203c0b0(M2C_UNK, M2C_UNK *, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_0212c5e0;
    extern M2C_UNK data_0212c5d0;
    if (!(M2C_FIELD(func_ov010_02229b00(), u8 *, 0x1A) & 2)) {
        return -1;
    }
    if (func_0203c0b0(arg0, &data_0212c5e0, 1) != 1) {
        return -1;
    }
    func_0203c0b0(arg0, &data_0212c5d0, 0x5DC000);
    return 0x7FFFFF;
}

void func_020de610(void) {

}

/* Prepares the 3D matching scene: switches in the main sprite engine, loads the
 * matching archive and the 2P/4P background chosen by GetSetupCode, resets the
 * menu sprites, then registers the scene's ov010 update callbacks. */
M2C_UNK SetupMatchScene(M2C_UNK setup, M2C_UNK side) {
void func_01ff9ce8(u8); void SetFileDirectory(void *); void *GetLocalizedFileName(void *); void func_020814e4(void *); void func_02081590(void *,void *); void func_02081528(void); void func_02080944(void *,s32,s32,s32);
void func_02088f1c(void *); void func_02088da8(void *); void func_0208b758(void *,u32); s32 GetSpriteAnimValue(void *);
void func_ov010_02228f80(s32,s32,s32,void *,void *,void *,void *,s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK gMatchScenePath,gMatchSceneNarc,gMatchScene4PScreen,gMatchScene2PScreen;
void func_020de868(s32,s32,void *); s32 func_020de884(s32);
void *savedEngine=gCur3DSpriteEngine; void *sprite; s32 layout,animValue;
gCur3DSpriteEngine=g3DSpriteEngineMain;
func_01ff9ce8(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
SetFileDirectory(&gMatchScenePath);
func_020814e4(GetLocalizedFileName(&gMatchSceneNarc));
layout=GetSetupCode((void *)setup);
switch(layout) {
case 4: func_02081590(GetLocalizedFileName(&gMatchScene4PScreen),M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
case 2: func_02081590(GetLocalizedFileName(&gMatchScene2PScreen),M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
}
func_02081528();
func_02080944(M2C_FIELD(gCur3DSpriteEngine,void **,0x20),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=savedEngine;
M2C_FIELD(setup,u16 *,0x48)|=0x20;
sprite=M2C_FIELD(setup,void **,0x54);
SetupSetFrame(sprite,(u16)(((SetupSprite *)sprite)->baseFrame+2),0);
func_02088f1c(M2C_FIELD(setup,void **,0x58));
func_02088da8(M2C_FIELD(setup,void **,0x60));
func_0208b758(M2C_FIELD(setup,void **,0x64),0x44000011);
func_02088f1c(M2C_FIELD(setup,void **,0x64));
if(GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68))) {
animValue=GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68));
sprite=M2C_FIELD(setup,void **,0x68);
M2C_FIELD(sprite,u16 *,0xe)=animValue;
M2C_FIELD(sprite,u16 *,0x10)=0;
M2C_FIELD(sprite,u16 *,0xc)=12;
M2C_FIELD(sprite,u16 *,2)=M2C_FIELD(sprite,u16 *,4);
}
M2C_FIELD(setup,u16 *,0x48)&=~0x100;
M2C_FIELD(setup,u16 *,0x48)&=~0x200;
M2C_FIELD(setup,u8 *,0x41)=0;
layout=GetSetupCode((void *)setup);
func_ov010_02228f80(side,layout,1,(void *)func_020de868,(void *)setup,(void *)func_020de884,(void *)setup,0);
}

void func_020de868(s32 arg0, s32 arg1, void *arg2) {
    if (arg0 != 0) {
        return;
    }
    if (arg1 != 0) {
        M2C_FIELD(arg2, u16 *, 0x48) = (u16) (M2C_FIELD(arg2, u16 *, 0x48) | 0x100);
    }
}

s32 func_020de884(M2C_UNK arg0) {
    M2C_UNK func_0203c0b0(M2C_UNK, M2C_UNK *, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_0212c5c8;
    if (!(M2C_FIELD(func_ov010_02229b00(), u8 *, 0x1A) & 2)) {
        return -1;
    }
    func_0203c0b0(arg0, &data_0212c5c8, 0x5DC000);
    return 0x7FFFFF;
}

#pragma opt_strength_reduction on
/* Set up the 3D matching/unit scene: switch in the main sprite engine, load
 * the matching archive and the background for the player count, reset the
 * menu sprites, then start the ov010 scene either by its screen code or by
 * the unit selected in the menu. */
void SetupMatchingUnitScene(M2C_UNK setup, M2C_UNK side) {
    void func_01ff9ce8(u8);
    void SetFileDirectory(void *);
    void *GetLocalizedFileName(void *);
    void func_020814e4(void *);
    void func_02081590(void *, void *);
    void func_02081528(void);
    void func_02080944(void *, s32, s32, s32);
    void func_02088f1c(void *);
    void func_02088da8(void *);
    void func_0208b758(void *, u32);
    s32 GetSpriteAnimValue(void *);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern M2C_UNK gLinkResourcePath;
    extern M2C_UNK gMatchingNarcPath;
    extern M2C_UNK gMatching4PScreen;
    extern M2C_UNK gMatching2PScreen;

    void func_ov010_02229190(s32,s32,s32,s32,s32,s32);
    void func_ov010_022292e4(s32,s32,s32,s32,s32,s32);
    void MatchingUnitSceneCallback(s32,s32,s32,s32,s32,void *);
    extern s32 gUnitSlotIds[];
    void *savedEngine = gCur3DSpriteEngine;
    s32 layout;
    s32 layout2;
    void *sprite;
    s32 baseFrame;
    u32 spriteWord;
    s32 animValue;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    SetFileDirectory(&gLinkResourcePath);
    func_020814e4(GetLocalizedFileName(&gMatchingNarcPath));

    layout=GetSetupCode((void *)setup);
    switch(layout) {
    case 4: func_02081590(GetLocalizedFileName(&gMatching4PScreen), M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
    case 2: func_02081590(GetLocalizedFileName(&gMatching2PScreen), M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
    }

    func_02081528();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;

    gCur3DSpriteEngine = savedEngine;

    M2C_FIELD((void *)setup, u16 *, 0x48) |= 0x20;

    sprite = M2C_FIELD((void *)setup, void **, 0x54);
    baseFrame = M2C_FIELD(sprite, u8 *, 0x59);
    baseFrame = (s32)((u32)(baseFrame << 28) >> 28);
    spriteWord = M2C_FIELD(sprite, u32 *, 0x40);
    spriteWord &= ~0x03FC0000u;
    spriteWord |= ((u32)(u16)(baseFrame + 2) << 24) >> 6;
    M2C_FIELD(sprite, u32 *, 0x40) = spriteWord;
    M2C_FIELD(sprite, u8 *, 0x5a) = 0;

    func_02088f1c(M2C_FIELD((void *)setup, void **, 0x58));
    func_02088da8(M2C_FIELD((void *)setup, void **, 0x60));
    func_0208b758(M2C_FIELD((void *)setup, void **, 0x64), 0x44000011U);
    func_02088f1c(M2C_FIELD((void *)setup, void **, 0x64));

    if (GetSpriteAnimValue(M2C_FIELD((void *)setup, void **, 0x68)) != 0) {
        animValue = GetSpriteAnimValue(M2C_FIELD((void *)setup, void **, 0x68));
        sprite = M2C_FIELD((void *)setup, void **, 0x68);
        M2C_FIELD(sprite, u16 *, 0xe) = (u16)animValue;
        M2C_FIELD(sprite, u16 *, 0x10) = 0;
        M2C_FIELD(sprite, u16 *, 0xc) = 0xc;
        M2C_FIELD(sprite, u16 *, 0x2) = M2C_FIELD(sprite, u16 *, 0x4);
    }
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x100;
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x200;

    M2C_FIELD((void *)setup, u8 *, 0x41) = 0;
    if(M2C_FIELD((void *)setup,u16 *,0x48)&1) {
    layout2=GetSetupCode((void *)setup);
    func_ov010_02229190(side,layout2,(s32)MatchingUnitSceneCallback,setup,0,0);
    } else {
    func_ov010_022292e4(side,gUnitSlotIds[M2C_FIELD((void *)setup,s8 *,0x43)],(s32)MatchingUnitSceneCallback,setup,0,0);
    }
}
#pragma opt_strength_reduction off
void MatchingUnitSceneCallback(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,void *arg5) { register u16 *p=(u16 *)((u8 *)arg5+0x48); if(arg0!=0)return; if(arg1==0)return; if(arg2!=0)return; if(arg3!=0)*p|=0x100; }

void func_020deb74(M2C_UNK arg0) {
    M2C_UNK SetupUnitPreviewScene(M2C_UNK, M2C_UNK);
    SetupUnitPreviewScene(arg0, 0);
}

void func_020deb84(M2C_UNK arg0) {
    M2C_UNK SetupUnitPreviewScene(M2C_UNK, M2C_UNK);
    SetupUnitPreviewScene(arg0, 1);
}

void func_020deb94(M2C_UNK arg0) {
    M2C_UNK SetupScene(M2C_UNK, M2C_UNK);
    SetupScene(arg0, 0);
}

void func_020deba4(M2C_UNK arg0) {
    M2C_UNK SetupScene(M2C_UNK, M2C_UNK);
    SetupScene(arg0, 1);
}

void func_020debb4(M2C_UNK arg0) {
    M2C_UNK SetupMatchScene(M2C_UNK, M2C_UNK);
    SetupMatchScene(arg0, 0);
}

void func_020debc4(M2C_UNK arg0) {
    M2C_UNK SetupMatchScene(M2C_UNK, M2C_UNK);
    SetupMatchScene(arg0, 1);
}

void func_020debd4(M2C_UNK arg0) {
    void SetupMatchingUnitScene(M2C_UNK, M2C_UNK);
    SetupMatchingUnitScene(arg0, 0);
}

void func_020debe4(M2C_UNK arg0) {
    void SetupMatchingUnitScene(M2C_UNK, M2C_UNK);
    SetupMatchingUnitScene(arg0, 1);
}

#pragma opt_strength_reduction off
void func_020debf4(void *self){void MenuSpriteUpdate(void*);
 int func_0208b5ec(void);
 void func_0208af20(void);
void *func_0208b564(void*);
void func_020899cc(void*,int,int,u32);
void func_020d47f0(void);
void func_01ffa6fc(void*);
void PlaySoundEffect(u32);
u32 GetActivePlayerMask(void);
u32 CountBits(void);
u32 func_ov009_02225470(void);
void func_02088f1c(void*);
void func_02088ff4(void*);
void func_0208b758(void*,u32);
u32 GetReadyPlayerMask(void);
void func_ov009_02224064(void);
void func_ov009_02224c34(int);
void func_ov009_02223fbc(void);
void func_020d47d0(void);
void ResetPlayerMask(void);
int func_020890b8(void*);
int func_02089064(void*);
void *func_ov009_02224070(int);
void func_ov009_022258a8(void*);
extern void *gKeyState;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineSub;
extern void *g3DSpriteEngineMain;

s32 i, i2;
void *old,*p;
u16 keys;u32 v;
u8 can;
u32 frame;

if(M2C_FIELD(self,void * *,0x50))MenuSpriteUpdate(M2C_FIELD(self,void * *,0x50));

if(M2C_FIELD(self,void * *,0x54))MenuSpriteUpdate(M2C_FIELD(self,void * *,0x54));

if(M2C_FIELD(self,void * *,0x58))MenuSpriteUpdate(M2C_FIELD(self,void * *,0x58));

keys=M2C_FIELD(gKeyState,u16 *,0);
M2C_FIELD(self,u16 *,0x48)=M2C_FIELD(self,u16 *,0x48)&~0x20U;

if(!(M2C_FIELD(self,u16 *,0x48)&1)){
if(M2C_FIELD(self,u16 *,0x48)&0x100){if(func_0208b5ec())func_0208af20();
old=gCur3DSpriteEngine;
for(i=0;
i<2;
i++){gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;

if(M2C_FIELD(self,u8 *,0x44)==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;

if(M2C_FIELD(self,u8 *,0x44)==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;

if(M2C_FIELD(self,u8 *,0x44)==3 && gCur3DSpriteEngine!=old)continue;

p=func_0208b564(self);
func_020899cc(p,2,M2C_FIELD(self,u16 *,0x46)<<5,0x44000001);
M2C_FIELD(p,u32 *,0x58)|=0x1000;

}gCur3DSpriteEngine=old;
func_020d47f0();
func_01ffa6fc(self);
return;
}
else if(M2C_FIELD(self,u16 *,0x48)&0x200){if(func_0208b5ec())func_0208af20();
old=gCur3DSpriteEngine;
for(i2=0;
i2<2;
i2++){gCur3DSpriteEngine=i2==0?g3DSpriteEngineMain:g3DSpriteEngineSub;

if(M2C_FIELD(self,u8 *,0x44)==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;

if(M2C_FIELD(self,u8 *,0x44)==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;

if(M2C_FIELD(self,u8 *,0x44)==3 && gCur3DSpriteEngine!=old)continue;

p=func_0208b564(self);
func_020899cc(p,2,M2C_FIELD(self,u16 *,0x46)<<5,0x44000002);
M2C_FIELD(p,u32 *,0x58)|=0x1000;

}gCur3DSpriteEngine=old;
func_020d47f0();
func_01ffa6fc(self);
return;
}}
p=M2C_FIELD(self,void * *,0x58);
frame=((SetupSprite*)p)->baseFrame;

if(SetupIsActive(p)){can=(u8)(M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xb)==1 || ((((SetupSprite*)p)->alternate) && M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xc)==1));
if(can||(keys&2)){
if(M2C_FIELD(p,s8 *,0x5a)>=0){SetupSetFrame(p,frame+1,12);
}
func_020d47f0();
func_01ffa6fc(self);
PlaySoundEffect(0x1000f);
return;
}}
GetActivePlayerMask();
v=CountBits();

if((M2C_FIELD(self,s8 *,0x41)>1||v>1)&&M2C_FIELD(self,s8 *,0x41)!=v)PlaySoundEffect(M2C_FIELD(self,s8 *,0x41)<(s32)v?0x122:0x123);

M2C_FIELD(self,u8 *,0x41)=v;

if(M2C_FIELD(self,u16 *,0x48)&1){
v=func_ov009_02225470();
p=M2C_FIELD(self,void * *,0x54);

if(v>=2){if(!SetupIsActive(p)){SetupSetFrame(p,((SetupSprite*)p)->baseFrame,0);
func_02088f1c(M2C_FIELD(self,void * *,0x54));
func_0208b758(M2C_FIELD(self,void * *,0x64),0x44000012);
}}
else if(SetupIsActive(p)){SetupSetFrame(p,(((SetupSprite*)p)->baseFrame)+2,0);
func_02088ff4(M2C_FIELD(self,void * *,0x54));
func_0208b758(M2C_FIELD(self,void * *,0x64),0x44000011);
}
p=M2C_FIELD(self,void * *,0x54);
if(!SetupIsActive(p))return;

can=(u8)(M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xb)==1 || ((((SetupSprite*)p)->alternate) && M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xc)==1));
if(!can && !(keys&1))return;

v=GetReadyPlayerMask();
if(v!=GetActivePlayerMask())return;

func_ov009_02224064();
p=M2C_FIELD(self,void * *,0x54);

if(M2C_FIELD(p,s8 *,0x5a)>=0){SetupSetFrame(p,(((SetupSprite*)p)->baseFrame)+1,12);
}
func_ov009_02224c34(0);
func_ov009_02223fbc();
func_020d47d0();
ResetPlayerMask();
func_01ffa6fc(self);
PlaySoundEffect(0x1000e);return;

}else{
v=func_ov009_02225470();
p=M2C_FIELD(self,void * *,0x60);

if(v>=2){if(!func_020890b8(p)&&!func_02089064(M2C_FIELD(self,void * *,0x60))){func_02088f1c(M2C_FIELD(self,void * *,0x60));
func_0208b758(M2C_FIELD(self,void * *,0x64),0x44000012);
}}
else if(!func_020890b8(p)&&func_02089064(M2C_FIELD(self,void * *,0x60))){func_02088ff4(M2C_FIELD(self,void * *,0x60));
func_0208b758(M2C_FIELD(self,void * *,0x64),0x44000011);
}
p=func_ov009_02224070(0);
if(!p||(M2C_FIELD(p,u8 *,0x16)&2))return;

v=GetReadyPlayerMask();
if(v!=GetActivePlayerMask())return;

func_ov009_022258a8(self);

}
func_ov009_02223fbc();
func_020d47d0();
ResetPlayerMask();
func_01ffa6fc(self);
PlaySoundEffect(0x1000e);

}
#pragma opt_strength_reduction reset
