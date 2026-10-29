/* 50 functions from 0x020A28F4 to 0x020A38F4 (main), found by ds-decomp. */
#include "common.h"

s32 func_020a28f4(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *gCurrentMap;
    extern M2C_UNK data_0211fbfd;
    extern s16 data_0211fbf6;
    s32 func_020a27b8(s32, s32);
    s32 index;

    index = func_020a27b8(((u32)(M2C_FIELD(*gCurrentMap + arg1 * 0x8C, s32 *, 0x6810) << 24) >> 24), arg2);
    if (index == -1) {
        return 0;
    }
    index *= 0x48;
    if (!*(s8 *)(arg0 + ((s32)&data_0211fbfd + index))) {
        return 0;
    }
    return M2C_FIELD(&data_0211fbf6, s16 *, index);
}

s32 func_020a296c(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *gCurrentMap;
    extern M2C_UNK data_0211fbfd;
    extern s8 data_0211fbee;
    s32 func_020a27b8(s32, s32);
    s32 index;

    index = func_020a27b8(((u32)(M2C_FIELD(*gCurrentMap + arg1 * 0x8C, s32 *, 0x6810) << 24) >> 24), arg2);
    if (index == -1) {
        return 0;
    }
    index *= 0x48;
    if (!*(s8 *)(arg0 + ((s32)&data_0211fbfd + index))) {
        return 0;
    }
    return M2C_FIELD(&data_0211fbee, s8 *, index);
}

s32 func_020a29e4(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *gCurrentMap;
    extern M2C_UNK data_0211fbfd;
    extern s8 data_0211fbf2;
    s32 func_020a27b8(s32, s32);
    s32 func_020a7bd4(s32);
    s32 index;

    index = func_020a27b8(((u32)(M2C_FIELD(*gCurrentMap + arg1 * 0x8C, s32 *, 0x6810) << 24) >> 24), arg2);
    if (index == -1) {
        return 0;
    }
    index *= 0x48;
    if (!*(s8 *)(arg0 + ((s32)&data_0211fbfd + index))) {
        return 0;
    }
    if (func_020a7bd4(arg0) < 2) {
        return 0;
    }
    return M2C_FIELD(&data_0211fbf2, s8 *, index);
}

s32 func_020a2a70(s32 a){
extern s32 *gCurrentMap;
switch((u32)(M2C_FIELD(*gCurrentMap+a*0x8c,s32 *,0x6810)<<24)>>24){
case 1:case 2:case 3:case 4:case 5:case 6:case 7:return 0x10002;
case 8:case 9:case 10:case 11:case 12:case 13:case 14:return 0x10003;
default:return 0x10003;
}
}

s32 func_020a2b00(u8 a){
extern s32 *gCurrentMap;
extern s32 data_02126180;
s32 r;
if(func_020a33c4(a))return func_020a2a70(a);
r=func_020a8ac4(M2C_FIELD(*gCurrentMap,u16 *,0x5142),a);
if(r)return r;
return M2C_FIELD(&data_02126180,s32 *,((u32)(M2C_FIELD(*gCurrentMap+a*0x8c,s32 *,0x6810)<<24)>>24)*0x9c);
}

void func_020a2b84(s32 arg0) {
    M2C_UNK func_0208f7d0();
    M2C_UNK func_020a2b00(u8);
    func_020a2b00((u8)(arg0 & 0xFF));
    func_0208f7d0();
}

void func_020a2b98(s32 a,s32 b){
s32 func_020a334c(s32);
extern u16 data_02168f14;
if(((u32)(data_02168f14<<19)>>31)==0)return;
if(func_020a334c(a)!=0)return;
func_020a3684(a,b);
}

s32 func_020a2bd8(void) {
    return 0xA;
}

u8 func_020a2be0(s32 a){
extern u16 data_02168f14;
s32 func_020a334c(s32);
s32 func_020a3518(s32);
s32 func_020a3594(s32,s32);
s32 t;u8 r;
if(((u32)(data_02168f14<<19)>>31)==0)return 0;
if(func_020a334c(a))return 0;
if(!func_020a3594(a,2))return 0;
t=func_020a3518(a);
if(t>=func_020a3594(a,2))r=1;else r=0;
return r;
}

void func_020a2c58(void *arg0) {
    func_020a363c(M2C_FIELD(arg0, s32 *, 0x5C));
}

void func_020a2c68(void *a){
extern s32 *gCurrentMap;extern u8 data_021261c4[];
s32 p=*gCurrentMap+0x67a4+M2C_FIELD(a,s32 *,0x5c)*0x8c;
s32 i=func_020a3460(M2C_FIELD(a,s32 *,0x5c));
u32 v=(u32)(M2C_FIELD(p,s32 *,0x6c)<<24)>>24;
if(M2C_FIELD(data_021261c4+v*0x9c,s32 *,i*0x28)==0){func_01ffa574(a);return;}
M2C_FIELD(a,u16 *,0x70)=1;
M2C_FIELD(a,u16 *,0x6c)=0;
}

void func_020a2f28(void *arg0) {
    func_020a363c(M2C_FIELD(arg0, s32 *, 0x5C));
}

void func_020a2f38(s32 arg0) {
    void *func_01ffa42c(M2C_UNK *);
    extern M2C_UNK data_02120404;
    M2C_FIELD(func_01ffa42c(&data_02120404), s32 *, 0x5C) = arg0;
}

void func_020a2f54(s32 arg0) {
    extern s32 *gCurrentMap;
    s32 RandomIntRange(s32, s32);
    s32 func_020a39c0(s32, s32);
    s32 func_020a363c(s32);
    s32 v = M2C_FIELD(*gCurrentMap, u8 *, 0x5158);

    switch (v) {
    case 0:
        switch (RandomIntRange(0, 2)) {
        case 0:
        default:
            v = 2;
            break;
        case 1:
            v = 1;
            break;
        case 2:
            v = 3;
            break;
        }
        break;
    case 2:
        switch (RandomIntRange(0, 1)) {
        case 0:
        default:
            v = 1;
            break;
        case 1:
            v = 3;
            break;
        }
        break;
    case 1:
        switch (RandomIntRange(0, 1)) {
        case 0:
        default:
            v = 2;
            break;
        case 1:
            v = 3;
            break;
        }
        break;
    case 3:
        switch (RandomIntRange(0, 1)) {
        case 0:
        default:
            v = 2;
            break;
        case 1:
            v = 1;
            break;
        }
        break;
    }
    func_020a39c0(v, 3);
    func_020a363c(arg0);
}

u8 func_020a3060(u8 *arg0) {
    s32 func_020a8560(u32);
    u8 var_r0;

    if (func_020a8560((u32) (*arg0 << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020a3088(M2C_UNK arg0) {
    M2C_UNK func_020cb254(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020cb254(arg0, 3, 0);
}

void func_020a309c(M2C_UNK arg0) {
    M2C_UNK func_020cb038(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cb170(M2C_UNK, M2C_UNK);
    func_020cb038(arg0, 0);
    func_020cb170(arg0, 0);
}

void func_020a30bc(void) {

}

s32 func_020a30c0(s32 a){
extern u8 data_02126194[];
s32 func_0207c2f0(void);
return ((s32 *)(data_02126194+a*0x9c))[func_0207c2f0()%3];
}

void func_020a3100(s32 arg0) {
    extern s32 *gCurrentMap;
    M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), s8 *, 0x6815) = 1;
}

void func_020a3128(s32 arg0){
extern s32 *gCurrentMap;
M2C_FIELD(arg0*0x8c+*gCurrentMap,s8 *,0x6815)=0;
}

u8 func_020a3150(s32 a){extern s32 *gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x6815]!=0;}

void func_020a3184(s32 a,u8 *b){extern s32 *gCurrentMap;u8 *func_020a32f4(s32);u8 *old; s32 index;
old=func_020a32f4(a);if(old&&old!=b)*old&=~0xc0;
if(b==0)index=0;else { if(b==0)index=0;else index=((s32)b-(*gCurrentMap+0x59a4))/14; }
M2C_FIELD(*gCurrentMap+a*0x8c,u8 *,0x6814)=index;
if(b)*b=(*b&~0xc0)|0xc0;
}

void func_020a3224(s32 a,s32 b){extern s32 *gCurrentMap;u8 *func_020a32f4(s32);s32 func_020a7310(s32);s32 index;
if(a!=(s32)func_020a32f4(func_020a7310(a)))return;
if(b==0)index=0;else index=(b-(*gCurrentMap+0x59a4))/14;
M2C_FIELD(*gCurrentMap+func_020a7310(a)*0x8c,u8 *,0x6814)=index;
}

u8 func_020a32a8(s32 a){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;u8 r;if(!((u32)(M2C_FIELD(p,s32 *,108)<<24)>>24))return 0;if(M2C_FIELD(p,u8 *,112))r=1;else r=0;return r;}

u8 *func_020a32f4(s32 a){extern s32 *gCurrentMap;s32 base=*gCurrentMap;s32 p=base+0x67a4+140*a;u32 b;if(!((u32)(M2C_FIELD(p,s32 *,108)<<24)>>24))return 0;b=M2C_FIELD(p,u8 *,112);if(!b)return 0;return (u8 *)(base+0x59a4+14*b);}

s32 func_020a334c(s32 a) {
extern s32 *gCurrentMap;
s32 p=*gCurrentMap+0x67a4+140*a;
register s32 v=M2C_FIELD(p,u32 *,108);
register s32 test=(u32)(v<<24)>>24;
if(test==0) return 0;
return (u8)((u32)(v<<20)>>30);
}

void func_020a338c(s32 a,s32 b){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~0xc00)|((u32)(b<<30)>>20);}

s32 func_020a33c4(s32 a){
extern s32 *gCurrentMap;
return (u32)(M2C_FIELD(*gCurrentMap+a*0x8c,s32 *,0x6810)<<20)>>30;
}

void func_020a33f0(s32 a,u32 b){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~0x300)|((b<<30)>>22);}

void func_020a3428(s32 a,u32 b){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~0x3000)|((b<<30)>>18);}

s32 func_020a3460(s32 a){extern s32 *gCurrentMap;return (u32)(M2C_FIELD(*gCurrentMap+140*a,u32 *,0x6810)<<18)>>30;}

void func_020a348c(void) {
    M2C_UNK func_020bcf14();
    func_020bcf14();
}

void func_020a3498(M2C_UNK arg0) {
    void func_020a338c(s32, s32);
    func_020a338c(arg0, 0);
}

#pragma opt_common_subs off
void func_020a34a8(s32 a){extern s32 *gCurrentMap;u32 v,n;u8 *p=(u8 *)*gCurrentMap+0x67a4;p+=140*a;v=*(u32 *)(p+108);n=(v<<14)>>28;if(n>=10)return;*(u32 *)(p+108)=(v&~0x3c000)|(((n+1)<<28)>>14);}
#pragma opt_common_subs reset
void func_020a34f4(M2C_UNK arg0) {
    s32 func_020a3594(M2C_UNK, M2C_UNK);
    M2C_UNK func_020a3684(M2C_UNK, s32);
    func_020a3684(arg0, 0 - func_020a3594(arg0, 2));
}

#pragma opt_common_subs off
s32 func_020a3518(s32 a) {extern s32 *gCurrentMap; s32 v=M2C_FIELD(*gCurrentMap+0x67a4+140*a,s32 *,108); if(((u32)(v<<24)>>24)==0)return 0;return (u32)v>>21;}
#pragma opt_common_subs reset
void func_020a3550(s32 a,s32 b){
 extern s32 *gCurrentMap;
 s32 *p;
 if(b<0)b=0;
 p=(s32 *)(*gCurrentMap+0x67a4+140*a);
 M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&0x1fffff)|((u32)b<<21);
}

s32 func_020a3594(s32 a,s32 b){
 extern s32 *gCurrentMap;
 extern u8 data_02126184[];
 extern u8 data_02126188[];
 s32 func_020a2bd8(void);
 s32 r4;
 s32 idx;
 switch(b){
 case 0: r4=0; break;
 case 1:
   idx=(s32)((u32)(M2C_FIELD(*gCurrentMap+a*0x8c,s32 *,0x6810)<<24)>>24);
   r4=*(s32*)(data_02126184+idx*0x9c);
   break;
 case 2:
   idx=(s32)((u32)(M2C_FIELD(*gCurrentMap+a*0x8c,s32 *,0x6810)<<24)>>24);
   r4=*(s32*)(data_02126188+idx*0x9c);
   break;
 default: r4=0; break;
 }
 return r4*func_020a2bd8();
}

s32 func_020a363c(s32 a){
 extern s32 *gCur3DSpriteEngine;
 s32 func_020a3460(s32);
 void func_020a338c(s32,s32);
 void func_020a23c4(void);
 void func_020cfd28(void);
 M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x38)=0;
 M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x40)=0;
 func_020a338c(a,func_020a3460(a));
 func_020a23c4();
 func_020cfd28();
}

s32 func_020a3684(s32 a, s32 b) {
  extern s32 *gCurrentMap;
  s32 func_020a3518(s32);
  s32 func_020a3594(s32, s32);
  void func_020a3550(s32, s32);
  s32 idx = (s32)((u32)(M2C_FIELD(*gCurrentMap + a * 0x8c, s32 *, 0x6810) << 24) >> 24);
  if (idx == 0) {
    return a;
  }
  {
    s32 t = func_020a3518(a);
    s32 x = func_020a3594(a, 2);
    s32 val = t + b;
    if (val < 0) val = 0;
    if (val > x) val = x;
    func_020a3550(a, val);
  }
}

void func_020a36ec(void *a){s16 xy[2];s32 func_ov000_021aa820(s16 *,s32,s32,s32);if(!func_ov000_021aa820(xy,M2C_FIELD(a,s16 *,0x6c),0,1)){func_01ffa8c4(a,0);return;}M2C_FIELD(a,s32 *,0x34)=xy[0];M2C_FIELD(a,s32 *,0x38)=xy[1];}

void func_020a3740(void *arg0) {
    M2C_UNK func_020c7874(s32, s32, M2C_UNK, M2C_UNK, void *);
    func_020c7874(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 2, 0x50, arg0);
}

void func_020a3764(void *arg0) {
    func_020a363c(M2C_FIELD(arg0, s16 *, 0x6C));
}

void func_020a3774(s16 arg0) {
    extern M2C_UNK data_02120444;
    M2C_FIELD(func_01ffa42c(&data_02120444), s16 *, 0x6C) = arg0;
}

s32 func_020a3790(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0xFE) {
        var_r0 = 1;
    }
    return var_r0;
}

void func_020a379c(void *a){extern s32 *gCurrentMap;void (*cb)(u8,u8);M2C_FIELD(*gCurrentMap,u8 *,0x5158)=M2C_FIELD(a,s16 *,0x36);if(M2C_FIELD(a,s16 *,0x38))func_020cd754((u8)M2C_FIELD(*gCurrentMap,u16 *,0x52b8));cb=M2C_FIELD(gCurrentMap[1],void (**)(u8,u8),0x58);if(!cb)return;cb(M2C_FIELD(*gCurrentMap,u8 *,0x5158),M2C_FIELD(*gCurrentMap,u8 *,0x5157));}

void func_020a3810(void *a){switch((u32)M2C_FIELD(a,s16 *,0x36)){case 0:func_0208fe30(0xd4);return;case 1:func_0208fe30(0xd6);return;case 2:func_0208fe30(0xd5);return;case 3:func_0208fe30(0xd7);return;default:return;}}

s32 func_020a3864(void) {
  extern s32 *gCurrentMap;
  s32 func_020d1938(s32);
  u16 idx;
  s32 i;
  u8 *arr;
  arr = (u8 *)(*gCurrentMap + 0x515c);
  idx = M2C_FIELD(*gCurrentMap, u16 *, 0x52a4);
  if (arr[idx - 1] > 0) {
    arr[idx - 1] -= 1;
    if (arr[idx - 1] > 0) {
      return 0;
    }
  }
  for (i = 1; i < 5; i++) {
    if (func_020d1938(i) != 0) {
      if (*((u8 *)(*gCurrentMap + 0x515b + i)) != 0) {
        return 0;
      }
    }
  }
  return 1;
}

