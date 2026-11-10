/* 12 functions from 0x022131F8 to 0x022141CC (ov005), found by ds-decomp. */
#include "common.h"
typedef struct {u16 a,b,c,d,e,f;} MenuInit;
extern u8 data_ov005_022203dc[];
extern u8 data_ov005_022203ec[];
extern u8 data_ov005_022203fc[];
extern u8 data_ov005_02220408[];
extern u8 data_ov005_02220418[];
extern u8 data_ov005_02220424[];
extern u8 data_ov005_02220434[];
extern u8 data_ov005_02220444[];
extern u8 data_ov005_02220454[];
extern u8 data_ov005_02220464[];
extern u8 data_ov005_02220474[];
extern void *gHistoryMenu;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineMain;
extern void *g3DSpriteEngineSub;
extern const u16 data_ov005_02220018[];
extern u8 data_ov005_02220348[];
extern u8 data_ov005_02220358[];
extern u8 data_ov005_02220368[];
extern u8 data_ov005_02220374[];
extern u8 data_ov005_02220388[];
extern u8 data_ov005_02220394[];
extern u8 data_ov005_022203a4[];
extern u8 data_ov005_022203b8[];
extern u8 data_ov005_022203cc[];

typedef struct {
u8 pad00[0x40];
u32 low:18, frame:8, high:6;
u8 pad44[0x15];
u8 base:4, repeat:1, flags:3;
u8 phase;
u8 pad5b[9];
void *input;
} MenuAnimSprite;
static inline u8 MenuSpritePressed(MenuAnimSprite *obj) {if(M2C_FIELD(obj->input,s8 *,11)==1)return 1;if(obj->repeat && M2C_FIELD(obj->input,s8 *,12)==1)return 1;return 0;}
static inline u16 GetMenuAnimBase(MenuAnimSprite *obj) {return obj->base;}
static inline void SetMenuAnimFrame(MenuAnimSprite *obj,u32 frame) {
obj->frame=(u16)frame;obj->phase=0;
}

void func_ov005_022131f8(u8 *a){
extern void *gHistoryMenu;extern u16 *gKeyState;
void *HistoryTabAt(s32);s32 HistoryScrollUp(void);s32 HistoryScrollDown(void);s32 func_ov005_02212160(void);s32 func_ov005_022121f8(void);
s32 func_020b20e0(s32);void func_020b1c60(s32);M2C_UNK PlaySoundEffect(s32);M2C_UNK func_ov005_02211a8c();
s32 n=*a;void *p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));s32 max=M2C_FIELD(p,s16 *,8)-7; s32 pos=M2C_FIELD(p,s16 *,2);s32 delta;
if(max<0)max=0;
if(pos==0&&n==0){if(gKeyState[0]&64){M2C_FIELD(p,s16 *,2)=max;n=6;goto done;}}
else if(gKeyState[1]&64){if(n>=2)n--;else if(!HistoryScrollUp()&&n!=0)n--;goto done;}
if(pos==max&&n==6){if(gKeyState[0]&128){n=0;M2C_FIELD(p,s16 *,2)=n;goto done;}}
else if(gKeyState[1]&128){if(n<5){if(func_020b20e0(n+1))n++;}else if(!HistoryScrollDown()){if(func_020b20e0(n+1))n++;}goto done;}
if(gKeyState[1]&32){delta=func_ov005_02212160();n-=delta+7;if(n<0)n=0;if(delta&&n==*a)PlaySoundEffect(0x10019);}
else if(gKeyState[1]&16){delta=func_ov005_022121f8();n+=7-delta;if(n>=7)n=6;if(delta&&n==*a)PlaySoundEffect(0x10019);}
else return;
done:if(n!=*a)func_020b1c60(n);M2C_FIELD(gHistoryMenu,u8 *,2)=n;func_ov005_02211a8c();
}

void func_ov005_0221339c(u8 *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_ov005_02211a8c();
    extern void *gHistoryMenu;
    M2C_FIELD(gHistoryMenu, u8 *, 2) = (u8) *arg0;
    func_ov005_02211a8c();
    PlaySoundEffect(0x10019);
}

#pragma opt_strength_reduction on
#pragma opt_common_subs on
#pragma opt_instruction_scheduling on
void func_ov005_022133c8(void *arg0) {
void func_ov005_02212ef0(void);void func_02091cd0(void);void *func_0208931c(void *);void *func_0208bc24(void *);s32 func_020aaf74(void *);void *func_020e34bc(s32);void *HistoryTabAt(s32);void *func_020e3218(void *);void *func_020a7278(void);void *func_020a72e8(s32);s32 func_020a7290(void);s32 func_020ae22c(s32);
MenuInit a={0,1,0x1c0,0x9d0,0x11e5,0x19f6};
MenuInit b={0,1,1,0x813,0x1024,0x1836};
void *dst; s32 n; s32 i,j;void *p,*save;
gHistoryMenu=func_020e34bc(100);
func_02082c84();GX_SetBankForBG(1);func_02002968(2);func_02003124(4);func_020031cc(8);
M2C_FIELD(gHistoryMenu,u8 *,0)=0;M2C_FIELD(gHistoryMenu,u8 *,1)=0;M2C_FIELD(gHistoryMenu,u8 *,2)=0;
for(i=0;i<3;i++){p=HistoryTabAt(i);M2C_FIELD(p,s16 *,2)=0;M2C_FIELD(p,s16 *,0)=M2C_FIELD(p,s16 *,2);M2C_FIELD(p,s16 *,4)=0;}
for(j=0;j<3;j++)func_ov005_02211c24(j);
func_ov005_02211b4c();func_ov000_0216a4e0((u8 *)gHistoryMenu+0x2e,(u8 *)gHistoryMenu+0x30);
func_ov005_02211c94();UpdateMedalFlags();
save=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020822b8(&a);
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q & ~16;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 32;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 64;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 128;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 256;}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,6)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,6)&~3)|0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,8)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,8)&~3)|1;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,10)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,10)&~3)|2;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,12)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,12)&~3)|3;
{u16 *volatile q=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*q=*q&~0xc0;}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,81)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,82)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,83)=0;
func_02099450(1,0,0);

func_0200bc5c(&data_ov005_02220348);
func_020814e4(func_020e3218(&data_ov005_02220358));
func_02081590(func_020e3218(&data_ov005_02220368),M2C_FIELD(g3DSpriteEngineMain,void **,0x14));
func_020816cc(func_020e3218(&data_ov005_02220374),M2C_FIELD(g3DSpriteEngineMain,void **,0x28),0,0);
func_02081528();func_0208116c(&data_ov005_02220388,0,0x20);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
func_0208ca2c(0x1000,1,func_020ae22c(9),2);
n=func_020a7290()<<5;dst=M2C_FIELD(g3DSpriteEngineMain,void **,0x10);p=func_020a7278();func_02007ef4(p,(u8 *)dst+0x1980,n);
func_01ff9e44(func_020a72e8(1),0x60,0x80);
func_020814e4(&data_ov005_02220394);
func_02081590(&data_ov005_022203a4,(u8 *)M2C_FIELD(g3DSpriteEngineMain,void **,0x10)+0x1880);
func_02081590(&data_ov005_022203b8,(u8 *)M2C_FIELD(g3DSpriteEngineMain,void **,0x10)+0x1900);
func_020815fc(&data_ov005_022203cc,0x40,0x20);func_02081528();func_02091d4c(1);
func_0208ca2c(0x2800,6,func_020ae22c(12),2);func_020aeebc(3,15,6);
func_020e3058((u8 *)gHistoryMenu+0x50,0xe0,0,15,0x180,3,0x100,arg0,1);
func_020e3058((u8 *)gHistoryMenu+0x54,0xa0,0,14,0x188,3,0x200,arg0,0);
func_020e3058((u8 *)gHistoryMenu+0x58,0x5e,0x9b,10,0x190,3,-1,arg0,0);
func_020e3058((u8 *)gHistoryMenu+0x5c,0x82,0x9b,11,0x198,3,-1,arg0,0);
func_020e3058((u8 *)gHistoryMenu+0x60,0xe0,0xa0,2,0x1a0,3,2,arg0,0);
p=M2C_FIELD(gHistoryMenu,void **,0x58);SetMenuAnimFrame(p,((MenuAnimSprite *)p)->base+2);
gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(&b);
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 16;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 32;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 64;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 128;}
{u16 *volatile q=(u16 *)*(void **)gCur3DSpriteEngine;*q=*q | 256;}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,6)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,6)&~3)|1;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,8)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,8)&~3)|0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,10)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,10)&~3)|2;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,12)=(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,12)&~3)|3;
{u16 *volatile q=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*q=*q&~0xc0;}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,81)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,82)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,83)=0;
func_02099450(1,0,0);

func_0200bc5c(&data_ov005_022203dc);
func_020814e4(func_020e3218(&data_ov005_022203ec));
func_02081590(func_020e3218(&data_ov005_022203fc),M2C_FIELD(g3DSpriteEngineSub,void **,0x14));
func_02081590(func_020e3218(&data_ov005_02220408),M2C_FIELD(g3DSpriteEngineSub,void **,0x28));
func_02081528();func_0208116c(&data_ov005_02220418,0,0x20);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;func_02091d4c(9);
func_020814e4(&data_ov005_02220424);
func_02081590(&data_ov005_02220434,(u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0x1c)+0x1400);
func_020815fc(&data_ov005_02220444,0x300,0x20);func_02081528();
func_02007e98(0,M2C_FIELD(gCur3DSpriteEngine,void **,0xc),0x20);
func_020814e4(&data_ov005_02220454);
func_02081590(&data_ov005_02220464,(u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0xc)+0x20);
func_020815fc(&data_ov005_02220474,0x20,0x100);func_02081528();
func_ov005_02212b40();
M2C_FIELD(gHistoryMenu,void **,0x4c)=func_0208931c(arg0);
p=M2C_FIELD(gHistoryMenu,void **,0x4c);
M2C_FIELD(p,u8 *,0x58)=10;
dst=(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2780;func_020a9a30(2,0,10,dst);
func_020a9a30(2,2,10,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+0x2c0);
M2C_FIELD(p,s32 *,0x44)=func_020aaf74(p);
M2C_FIELD(p,u16 *,0x3e)=0x13c;
((MenuAnimSprite *)p)->frame=22;
M2C_FIELD(p,u16 *,0x3c)=0xc00;
M2C_FIELD(gHistoryMenu,void **,0x48)=func_0208bc24(arg0);
M2C_FIELD(M2C_FIELD(gHistoryMenu,void **,0x48),u16 *,0x3e)=0xdc;
((MenuAnimSprite *)M2C_FIELD(gHistoryMenu,void **,0x48))->frame=7;
func_02088f1c(M2C_FIELD(gHistoryMenu,void **,0x48));
func_020aef7c(3,15,6);gCur3DSpriteEngine=save;func_02091cd0();func_ov005_02212ef0();
}
#pragma opt_instruction_scheduling reset
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
void func_ov005_02213cf4(void) {
    M2C_UNK func_020b2224();
    M2C_UNK func_020b1bf4(s32, s32, s32, s32);
    M2C_UNK func_020b1c78(s32);
    M2C_UNK func_020b22a4(s32, s32, M2C_UNK *, s32);
    void *HistoryTabAt(s32);
    extern M2C_UNK data_ov005_022201e0;
    s32 var_r4;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    func_020b2224();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    var_r4 = 0;
    do {
        if (M2C_FIELD(HistoryTabAt(var_r4), s16 *, 8) > var_r6) {
            var_r6 = M2C_FIELD(HistoryTabAt(var_r4), s16 *, 8);
        }
        var_r4++;
    } while (var_r4 < 3);
    var_r8 = 0;
    if (var_r6 > 0) {
        var_r7 = 0x28;
loop:
        if (var_r8 != 7) {
            func_020b22a4(4, var_r7, &data_ov005_022201e0, var_r8);
            var_r8++;
            var_r7 += 0x10;
            if (var_r8 < var_r6) goto loop;
        }
    }
    func_020b1c78(0);
}

#pragma opt_propagation off
/* Per-frame update of the ov005 record/history menu: animates the active
 * tab's list, updates its arrow sprites, runs the two list confirm actions,
 * then handles confirm and tab-switch input. */
void HistoryMenu_Update(void *widget) {
  void *HistoryTabAt(s32);
  int func_ov005_0221298c(s16);
  s32 HistoryScrollUp(void);
  s32 HistoryScrollDown(void);
  M2C_UNK MenuSpriteUpdate(M2C_UNK);
  M2C_UNK PlaySoundEffect(s32);
  void func_020b21e0(void);
  void func_020b2268(void);
  M2C_UNK func_01ffa6fc(M2C_UNK);
  void func_ov005_02212ef0(void);
  extern void *gHistoryMenu;
  extern u16 *gKeyState;

  void *tab;
  void *menu;
  void *sprite;
  s16 r2, r1; s32 r3, r0v;
  s32 temp;
  u32 base, value;
  s16 a, b;
  s32 pressed;
  s8 v; s32 nextTab;
  u16 buttons;

  tab = HistoryTabAt(M2C_FIELD(gHistoryMenu, s8 *, 1));
  if (M2C_FIELD(tab, s16 *, 4) == 0) {
    r1 = M2C_FIELD(tab, s16 *, 2);
    r3 = M2C_FIELD(tab, s16 *, 0);
    if (r3 == r1*2) goto animation_done;
    {
      temp = (r1 * 2) - r3;
      if (temp < 0) temp = -temp;
      r2 = (s16)(temp >> 1);
      if (r2 == 0) r2 = 1;
      if (r3 > (r1*2)) M2C_FIELD(tab,s16 *,0)-=r2;
      else M2C_FIELD(tab,s16 *,0)+=r2;
    }
    M2C_FIELD(tab, s16 *, 4) = 1;
    func_ov005_0221298c(M2C_FIELD(tab, s16 *, 0));
  } else {
    M2C_FIELD(tab, s16 *, 4) = 0;
  }

animation_done:
if(M2C_FIELD(tab,s16 *,2)==0) {
sprite=M2C_FIELD(gHistoryMenu,void **,0x58);
SetMenuAnimFrame(sprite,((MenuAnimSprite *)sprite)->base+2);
}else{
sprite=M2C_FIELD(gHistoryMenu,void **,0x58);
SetMenuAnimFrame(sprite,((MenuAnimSprite *)sprite)->base);
}
if(M2C_FIELD(tab,s16 *,2)==M2C_FIELD(tab,s16 *,8)-7){
sprite=M2C_FIELD(gHistoryMenu,void **,0x5c);SetMenuAnimFrame(sprite,((MenuAnimSprite *)sprite)->base+2);
}else{
sprite=M2C_FIELD(gHistoryMenu,void **,0x5c);SetMenuAnimFrame(sprite,((MenuAnimSprite *)sprite)->base);
}

  menu = gHistoryMenu;
  MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x50));
  MenuSpriteUpdate(M2C_FIELD(gHistoryMenu, void **, 0x54));
  MenuSpriteUpdate(M2C_FIELD(gHistoryMenu, void **, 0x58));
  MenuSpriteUpdate(M2C_FIELD(gHistoryMenu, void **, 0x5c));
  MenuSpriteUpdate(M2C_FIELD(gHistoryMenu, void **, 0x60));

  menu = gHistoryMenu;
  sprite = M2C_FIELD(menu, void **, 0x58);
  sprite = M2C_FIELD(sprite, void **, 0x64);
  pressed = 1;
  v = (s8)M2C_FIELD(sprite, s8 *, 0x0b);
  if(v!=1) {if(!((MenuAnimSprite *)M2C_FIELD(menu,void **,0x58))->repeat || M2C_FIELD(sprite,s8 *,12)!=1)pressed=0;}
  if ((u8)pressed) { ((s32(*)(void *))HistoryScrollUp)(menu); return; }

  sprite = M2C_FIELD(menu, void **, 0x5c);
  sprite = M2C_FIELD(sprite, void **, 0x64);
  pressed = 1;
  v = (s8)M2C_FIELD(sprite, s8 *, 0x0b);
  if(v!=1) {if(!((MenuAnimSprite *)M2C_FIELD(menu,void **,0x5c))->repeat || M2C_FIELD(sprite,s8 *,12)!=1)pressed=0;}
  if ((u8)pressed) { ((s32(*)(void *))HistoryScrollDown)(menu); return; }

  buttons = *gKeyState;
  if (buttons & 0x2) {
    PlaySoundEffect(0x1000f);
    func_020b21e0();
    func_020b2268();
    func_01ffa6fc(widget);
    return;
  }
  if (buttons & 0x100) {
    nextTab = M2C_FIELD(menu, s8 *, 1);
    if (nextTab == 2) nextTab = 0; else nextTab = nextTab+1;
    M2C_FIELD(menu, s8 *, 1) = nextTab;
    PlaySoundEffect(0x10020);
    func_ov005_02212ef0();
    return;
  }
  if (buttons & 0x200) {
    nextTab = M2C_FIELD(menu, s8 *, 1);
    if (nextTab == 0) nextTab = 2; else nextTab = nextTab-1;
    M2C_FIELD(menu, s8 *, 1) = nextTab;
    PlaySoundEffect(0x10020);
    func_ov005_02212ef0();
    return;
  }
}
void func_ov005_02214094(void) {
    M2C_UNK func_020af1e4();
    M2C_UNK func_020842d4();
    M2C_UNK func_020b2178();
    M2C_UNK func_020e35cc();
    extern void *gHistoryMenu;
    func_020af1e4();
    func_020842d4();
    func_020b2178();
    if (gHistoryMenu == NULL) return;
    func_020e35cc();
    gHistoryMenu = NULL;
}

void func_ov005_022140cc(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220208;
    CreateSpriteObject(&data_ov005_02220208, arg0);
}

void func_ov005_022140e4(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    extern M2C_UNK data_ov005_02220644;
    func_0200bc5c(&data_ov005_02220644);
}

s32 func_ov005_022140f8(s32 arg0) {
    s32 func_020ad658(s32);
    extern M2C_UNK data_ov005_02221304;
    if (*M2C_FIELD(&data_ov005_02221304, u16 **, 8) & 2) return 1;
    return func_020ad658(arg0);
}

s32 func_ov005_02214120(s32 arg0) {
    s32 func_020ad61c(s32);
    extern M2C_UNK data_ov005_02221304;
    if (*M2C_FIELD(&data_ov005_02221304, u16 **, 8) & 2) return 1;
    return func_020ad61c(arg0);
}

s32 func_ov005_02214148(void) {
    extern M2C_UNK data_ov005_02221304;
    s16 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98);
    if (temp_r1 == 0) {
        return 0;
    }
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16) (temp_r1 - 1);
    PlaySoundEffect(0x10019);
    return 1;
}

s16 func_ov005_02214184(void) {
    extern M2C_UNK data_ov005_02221304;
    s16 temp_r3;
    temp_r3 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16)(temp_r3 - 6);
    if (M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) < 0) {
        M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = 0;
    }
    return (s16)(M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) - temp_r3);
}

