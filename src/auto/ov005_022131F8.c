/* 12 functions from 0x022131F8 to 0x022141CC (ov005), found by ds-decomp. */
#include "common.h"
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
extern void *data_ov005_02221300;extern u16 *data_02101e84;
void *func_ov005_02211a38(s32);s32 func_ov005_02212118(void);s32 func_ov005_022121a8(void);s32 func_ov005_02212160(void);s32 func_ov005_022121f8(void);
s32 func_020b20e0(s32);void func_020b1c60(s32);M2C_UNK func_0208fe30(s32);M2C_UNK func_ov005_02211a8c();
s32 n=*a;void *p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));s32 max=M2C_FIELD(p,s16 *,8)-7; s32 pos=M2C_FIELD(p,s16 *,2);s32 delta;
if(max<0)max=0;
if(pos==0&&n==0){if(data_02101e84[0]&64){M2C_FIELD(p,s16 *,2)=max;n=6;goto done;}}
else if(data_02101e84[1]&64){if(n>=2)n--;else if(!func_ov005_02212118()&&n!=0)n--;goto done;}
if(pos==max&&n==6){if(data_02101e84[0]&128){n=0;M2C_FIELD(p,s16 *,2)=n;goto done;}}
else if(data_02101e84[1]&128){if(n<5){if(func_020b20e0(n+1))n++;}else if(!func_ov005_022121a8()){if(func_020b20e0(n+1))n++;}goto done;}
if(data_02101e84[1]&32){delta=func_ov005_02212160();n-=delta+7;if(n<0)n=0;if(delta&&n==*a)func_0208fe30(0x10019);}
else if(data_02101e84[1]&16){delta=func_ov005_022121f8();n+=7-delta;if(n>=7)n=6;if(delta&&n==*a)func_0208fe30(0x10019);}
else return;
done:if(n!=*a)func_020b1c60(n);M2C_FIELD(data_ov005_02221300,u8 *,2)=n;func_ov005_02211a8c();
}

void func_ov005_0221339c(u8 *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_ov005_02211a8c();
    extern void *data_ov005_02221300;
    M2C_FIELD(data_ov005_02221300, u8 *, 2) = (u8) *arg0;
    func_ov005_02211a8c();
    func_0208fe30(0x10019);
}

void func_ov005_022133c8(void *arg0) { }

void func_ov005_02213cf4(void) {
    M2C_UNK func_020b2224();
    M2C_UNK func_020b1bf4(s32, s32, s32, s32);
    M2C_UNK func_020b1c78(s32);
    M2C_UNK func_020b22a4(s32, s32, M2C_UNK *, s32);
    void *func_ov005_02211a38(s32);
    extern M2C_UNK data_ov005_022201e0;
    s32 var_r4;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    func_020b2224();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    var_r4 = 0;
    do {
        if (M2C_FIELD(func_ov005_02211a38(var_r4), s16 *, 8) > var_r6) {
            var_r6 = M2C_FIELD(func_ov005_02211a38(var_r4), s16 *, 8);
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
void func_ov005_02213d94(void *arg0) {
  void *func_ov005_02211a38(s32);
  int func_ov005_0221298c(s16);
  s32 func_ov005_02212118(void);
  s32 func_ov005_022121a8(void);
  M2C_UNK func_020aacf0(M2C_UNK);
  M2C_UNK func_0208fe30(s32);
  void func_020b21e0(void);
  void func_020b2268(void);
  M2C_UNK func_01ffa6fc(M2C_UNK);
  void func_ov005_02212ef0(void);
  extern void *data_ov005_02221300;
  extern u16 *data_02101e84;

  void *p;
  void *main;
  void *obj;
  s16 r2, r1; s32 r3, r0v;
  s32 temp;
  u32 base, value;
  s16 a, b;
  s32 flag;
  s8 v; s32 t;
  u16 flags;

  p = func_ov005_02211a38(M2C_FIELD(data_ov005_02221300, s8 *, 1));
  if (M2C_FIELD(p, s16 *, 4) == 0) {
    r1 = M2C_FIELD(p, s16 *, 2);
    r3 = M2C_FIELD(p, s16 *, 0);
    if (r3 == r1*2) goto animation_done;
    {
      temp = (r1 * 2) - r3;
      if (temp < 0) temp = -temp;
      r2 = (s16)(temp >> 1);
      if (r2 == 0) r2 = 1;
      if (r3 > (r1*2)) M2C_FIELD(p,s16 *,0)-=r2;
      else M2C_FIELD(p,s16 *,0)+=r2;
    }
    M2C_FIELD(p, s16 *, 4) = 1;
    func_ov005_0221298c(M2C_FIELD(p, s16 *, 0));
  } else {
    M2C_FIELD(p, s16 *, 4) = 0;
  }

animation_done:
if(M2C_FIELD(p,s16 *,2)==0) {
obj=M2C_FIELD(data_ov005_02221300,void **,0x58);
SetMenuAnimFrame(obj,((MenuAnimSprite *)obj)->base+2);
}else{
obj=M2C_FIELD(data_ov005_02221300,void **,0x58);
SetMenuAnimFrame(obj,((MenuAnimSprite *)obj)->base);
}
if(M2C_FIELD(p,s16 *,2)==M2C_FIELD(p,s16 *,8)-7){
obj=M2C_FIELD(data_ov005_02221300,void **,0x5c);SetMenuAnimFrame(obj,((MenuAnimSprite *)obj)->base+2);
}else{
obj=M2C_FIELD(data_ov005_02221300,void **,0x5c);SetMenuAnimFrame(obj,((MenuAnimSprite *)obj)->base);
}

  main = data_ov005_02221300;
  func_020aacf0(M2C_FIELD(main, void **, 0x50));
  func_020aacf0(M2C_FIELD(data_ov005_02221300, void **, 0x54));
  func_020aacf0(M2C_FIELD(data_ov005_02221300, void **, 0x58));
  func_020aacf0(M2C_FIELD(data_ov005_02221300, void **, 0x5c));
  func_020aacf0(M2C_FIELD(data_ov005_02221300, void **, 0x60));

  main = data_ov005_02221300;
  obj = M2C_FIELD(main, void **, 0x58);
  obj = M2C_FIELD(obj, void **, 0x64);
  flag = 1;
  v = (s8)M2C_FIELD(obj, s8 *, 0x0b);
  if(v!=1) {if(!((MenuAnimSprite *)M2C_FIELD(main,void **,0x58))->repeat || M2C_FIELD(obj,s8 *,12)!=1)flag=0;}
  if ((u8)flag) { ((s32(*)(void *))func_ov005_02212118)(main); return; }

  obj = M2C_FIELD(main, void **, 0x5c);
  obj = M2C_FIELD(obj, void **, 0x64);
  flag = 1;
  v = (s8)M2C_FIELD(obj, s8 *, 0x0b);
  if(v!=1) {if(!((MenuAnimSprite *)M2C_FIELD(main,void **,0x5c))->repeat || M2C_FIELD(obj,s8 *,12)!=1)flag=0;}
  if ((u8)flag) { ((s32(*)(void *))func_ov005_022121a8)(main); return; }

  flags = *data_02101e84;
  if (flags & 0x2) {
    func_0208fe30(0x1000f);
    func_020b21e0();
    func_020b2268();
    func_01ffa6fc(arg0);
    return;
  }
  if (flags & 0x100) {
    t = M2C_FIELD(main, s8 *, 1);
    if (t == 2) t = 0; else t = t+1;
    M2C_FIELD(main, s8 *, 1) = t;
    func_0208fe30(0x10020);
    func_ov005_02212ef0();
    return;
  }
  if (flags & 0x200) {
    t = M2C_FIELD(main, s8 *, 1);
    if (t == 0) t = 2; else t = t-1;
    M2C_FIELD(main, s8 *, 1) = t;
    func_0208fe30(0x10020);
    func_ov005_02212ef0();
    return;
  }
}
void func_ov005_02214094(void) {
    M2C_UNK func_020af1e4();
    M2C_UNK func_020842d4();
    M2C_UNK func_020b2178();
    M2C_UNK func_020e35cc();
    extern void *data_ov005_02221300;
    func_020af1e4();
    func_020842d4();
    func_020b2178();
    if (data_ov005_02221300 == NULL) return;
    func_020e35cc();
    data_ov005_02221300 = NULL;
}

void func_ov005_022140cc(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220208;
    func_01ffa42c(&data_ov005_02220208, arg0);
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
    func_0208fe30(0x10019);
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

