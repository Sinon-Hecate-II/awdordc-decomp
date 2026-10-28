/* 12 functions from 0x021A686C to 0x021A7610 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_021a686c(void) {
 extern s32 *gCurrentMap;
 extern u8 *data_ov000_021df578;
 extern M2C_UNK data_ov000_021e00ac;
 u8 *p; s32 i,rank,best,result;
 rank=0;i=0;best=32767;result=-1;p=(u8 *)&data_ov000_021e00ac;
 for(;i<*data_ov000_021df578;i++,p+=12) {
 if(p[3]<252 && p[2]==2) {
 s32 base=*gCurrentMap;
 s32 off=base+p[0];
 off+=M2C_FIELD(base+p[1]*2,u16 *,0x3758);
 if(M2C_FIELD(off,u8 *,0x2840)<40 && M2C_FIELD(off,u8 *,0x2d48)<40) {
 u8 r=p[6];
 if(rank<=r && (rank!=r || best>=p[7])) {best=p[7];rank=r;result=i;}
 }
 }
 }
 return result;
}

s32 func_ov000_021a6940(void) {
 s32 func_ov000_021a4e08(u8,u8,s32);
 extern s32 *gCurrentMap;
 extern u8 *data_ov000_021df578;
 extern M2C_UNK data_ov000_021e00ac;
 M2C_UNK *p;
 s32 base;
 s32 result;
 s32 i;
 s32 best;
 s8 v;
 u8 x;
 u8 y;
 best=0;result=-1;p=&data_ov000_021e00ac;
 func_ov000_021a581c();
 i=0;
 if((s32)*data_ov000_021df578>0) do {
 if(M2C_FIELD(p,u8 *,3)<252 && M2C_FIELD(p,u8 *,2)==3) {
 y=M2C_FIELD(p,u8 *,1);base=*gCurrentMap;x=M2C_FIELD(p,u8 *,0);
 v=M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+(base+x),s8 *,0x2338);
 if(best < (s32)v && func_ov000_021a4e08(x,y,23)<60){best=(s32)v;result=i;}
 }
 i++;p+=3;
 }while(i<*data_ov000_021df578);
 return result;
}

s32 func_ov000_021a6a00(void) {
 s32 func_ov000_021a4e08(u8,u8,s32);
 extern s32 *gCurrentMap;
 extern u8 *data_ov000_021df578;
 extern M2C_UNK data_ov000_021e00ac;
 u8 *p;
 s32 i;
 s32 base;
 s32 best;
 s32 result;
 s8 v;
 u8 x;
 u8 y;
 best=126;result=-1;p=(u8 *)&data_ov000_021e00ac;
 func_ov000_021a5b28();
 i=0;
 if((s32)*data_ov000_021df578>0) do {
 if(p[3]<252 && p[2]==3) {
 y=p[1];base=*gCurrentMap;x=p[0];
 v=M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+(base+x),s8 *,0x2338);
 if(best >= v && func_ov000_021a4e08(x,y,23)<40){best=v;result=i;}
 }
 i++;p+=12;
 }while(i<*data_ov000_021df578);
 return result;
}

#pragma opt_strength_reduction off
s32 func_ov000_021a6ac0(void) {
  void func_01ffada0(s32,s32,s32,s32,s32);
  void func_ov000_021a5f50(void);
  s32 func_020d27c0(s32);
  extern s32 *gCurrentMap;
  extern u8 *data_ov000_021df578;
  extern M2C_UNK data_ov000_021e00ac;
  extern u8 data_ov000_021b5bfc[];
  u8 *p;
  s32 base;
  u8 *unit;
  s32 i;
  s32 v;
  s32 best;
  s32 result;
  s32 id;
  s32 y;
  s32 x;
  best=126;
  result=-1;
  p=(u8 *)&data_ov000_021e00ac;
  func_ov000_021a5f50();
  i=0;
  if((s32)*data_ov000_021df578>0) do {
  if(p[3]<252 && p[2]==3) {
  y=p[0];base=*gCurrentMap;x=p[1];
  v=M2C_FIELD(M2C_FIELD(base+x*2,u16 *,0x3758)+(base+y),s8 *,0x2338);
  if(best>=v) {
  func_01ffada0(y,x,23,data_ov000_021b5bfc[0xa18]+1,0x20);
  base=*gCurrentMap;
  for(x=0;x<M2C_FIELD(base,u16 *,0x5146);x++) {
  for(y=0;y<M2C_FIELD(base,u16 *,0x5144);y++,base=*gCurrentMap) {
  if(M2C_FIELD(base+x*4,s8 **,0x52e8)[y]<0)continue;
  id=M2C_FIELD(M2C_FIELD(base+x*2,u16 *,0x3758)+(base+y),u8 *,0);
  unit=(u8 *)(base+0x59a4)+id*14;
  if(((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)!=23)continue;
  if(func_020d27c0(id)!=0)continue;
  if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)>=50)goto next;
  }
  }
  result=i;best=v;
  }
  }
  next: i++;p+=12;
  } while(i<*data_ov000_021df578);
  return result;
}
#pragma opt_strength_reduction on
s32 func_ov000_021a6c8c(void) {
 extern s32 *gCurrentMap;
 extern u8 *data_ov000_021df578;
 extern M2C_UNK data_ov000_021e00ac;
 u8 *p;
 s32 best,result,i;
 best=32767; result=-1; p=(u8 *)&data_ov000_021e00ac;
 func_ov000_021998f0();
 for(i=0;i<*data_ov000_021df578;i++,p+=12) {
 if(p[3]<252 && p[2]==3 && best>=p[7]) {
 s32 base=*gCurrentMap;
 s32 off=base+p[0];
 off+=M2C_FIELD(base+p[1]*2,u16 *,0x3758);
 if(M2C_FIELD(off,u8 *,0x2840)+M2C_FIELD(off,u8 *,0x2d48)<40) {best=p[7];result=i;}
 }
 }
 return result;
}

extern unsigned char *data_ov000_021df578;
extern int data_ov000_021e00ac;
extern int *gCurrentMap;
int func_ov000_021a6d4c(void)
{
    int min = 0x7fff;
    int result = -1;
    int i;
    unsigned char *entry = (unsigned char *)&data_ov000_021e00ac;

    for (i = 0; i < data_ov000_021df578[0]; i++) {
        if (entry[3] < 0xfc) {
            if (func_ov000_021a4e08(entry[0], entry[1], 7) < 60) {
                if (entry[2] == 1) {
                    signed char *values =
                        *(signed char **)((unsigned char *)gCurrentMap[0] +
                            0x5000 + entry[1] * 4 + 0x2e8);

                    int value = values[entry[0]];

                    if (min > value) {
                        min = value;
                        result = i;
                    }
                }
            }
        }

        entry += 12;
    }

    return result;
}

s32 func_ov000_021a6e08(s32 a) {
 extern u8 *data_ov000_021df578;
 extern M2C_UNK data_ov000_021e00ac;
 u8 *p=(u8 *)&data_ov000_021e00ac;
 s32 i;
 for(i=0;i<*data_ov000_021df578;i++,p+=12) {if(a==4 || p[2]==a)return 1;}
 return 0;
}

s32 func_ov000_021a6e5c(u32 arg0) {
 switch(arg0) {
 case 1:case 2:case 3:return 0;
 case 4:case 10:case 11:case 12:case 13:return 1;
 case 6:case 7:case 9:case 26:return 2;
 case 14:case 15:case 16:case 17:return 3;
 case 18:case 19:return 4;
 case 20:case 21:return 5;
 case 23:return 6;
 case 24:case 25:return 7;
 case 22:return 8;
 default:return 10;
 }
}

s32 func_ov000_021a6f24(s32 value,s32 kind,s32 arg2) {
 s32 func_020a7b3c(s32,u8,u16,s32,s32);
 s32 func_020a7c10(s32,u8,u16,s32,s32);
 s32 func_020a85c8(s32);
 s32 func_ov000_021a98e4(u8);
 extern s32 *gCurrentMap;
 extern u8 data_ov000_021b5c08[];
 extern void *data_ov000_021df580;
 if(kind==5 && M2C_FIELD(*gCurrentMap,u8 *,0x5156)==0 && M2C_FIELD(data_ov000_021df580,u8 *,13)!=2) return 0;
 if(func_ov000_021a98e4((u8)kind)==1) {
 if(func_020a85c8(kind))value<<=1;
 value=(value*(func_020a7c10(kind,M2C_FIELD(data_ov000_021df580,u8 *,13),M2C_FIELD(*gCurrentMap,u16 *,0x52a4),arg2,1)+4-data_ov000_021b5c08[kind*112]))>>3;
 if(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<23)>>29)==1 && kind==11)value=(value*3)>>1;
 } else {
 if((u32)(kind-8)<=1)kind=7;
 value=(value*func_020a7b3c(kind,M2C_FIELD(data_ov000_021df580,u8 *,13),M2C_FIELD(*gCurrentMap,u16 *,0x52a4),arg2,1))>>3;
 }
 if(kind==4)value>>=1;
 if(kind==3)value>>=1;
 return value;
}

s32 func_ov000_021a7084(void *a, void *b) { return 0; }

u8 func_ov000_021a72c0(u32 arg0) {
    s32 func_020b9e20(u16);
    extern s8 data_ov000_021aab78[];
    extern void *data_ov000_021df57c;
    extern int *gCurrentMap;

    if (arg0 >= 0x1BU) {
        return 0U;
    }
    if (data_ov000_021aab78[arg0] == -1) {
        return 0U;
    }
    if (((unsigned char *)data_ov000_021df57c + (arg0 - 1) * 0xC)[0x14] == 0U) {
        return 0U;
    }
    if (func_020b9e20(*(u16 *)((unsigned char *)*gCurrentMap + 0x5200 + 0xA4)) != 0) {
        return 1U;
    }
    return 0U;
}

s32 func_ov000_021a7348(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(s32);
    s32 func_ov000_021a911c(s32);
    extern s32 *gCurrentMap;
    extern void *data_ov000_021df580;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern u8 data_0212616c[];

    s32 r5 = 0;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 player;
    void *mapBase;
    u16 start;
    s32 idx;
    u8 *unit;
    u32 kind;
    u8 attr;
    u16 hp;
    u8 owner;
    u8 *map;
    u16 row;
    u8 terrain;
    u8 kindAttr;
    u8 x, y;
    u8 ownerAttr;
    s8 *costBase;
    s8 *costTable;
    u8 t2;
    s8 cost;
    u8 attr2;
    s32 doCost;
    u16 tmpMode;
    u32 modeVal;
    u16 tmpUnit;

    tmpMode = *(u16 *)((u8 *)data_ov000_021df580 + 10);
    modeVal = tmpMode << 26;
    modeVal = modeVal >> 29;
    if (!(modeVal & 4)) {
        return 0;
    }

    for (player = 1; player < 5; player++) {
        if (func_020d1938(player) == 0) {
            continue;
        }
        mapBase = (void *)*gCurrentMap;
        tmpUnit = *(u16 *)((u8 *)mapBase + 0x52a4);
        if (func_020d273c(tmpUnit) == 1) {
            start = data_ov000_021aeef4[player];
            for (idx = start + 1; idx < start + 0x33; idx++) {
                unit = (u8 *)mapBase + 0x59a4 + idx * 14;
                kind = unit[0] & 0x3f;
                if (kind == 0) {
                    continue;
                }
                if (kind == 6) {
                    owner = unit[11] & 0x0f;
                    if (owner != 5) {
                        r5--;
                    }
                }
                attr = data_ov000_021b5bfc[kind * 0x70 + 0x15];
                if (kind == 0x17) {
                    r6--;
                }
                if (attr & 1) {
                    hp = *(u16 *)(unit + 6);
                    r7 -= (hp & 0x7f);
                }
            }
        } else {
            start = data_ov000_021aeef4[player];
            for (idx = start + 1; idx < start + 0x33; idx++) {
                unit = (u8 *)mapBase + 0x59a4 + idx * 14;
                kind = unit[0] & 0x3f;
                if (kind == 0) {
                    continue;
                }
                kindAttr = data_ov000_021b5bfc[kind * 0x70 + 0x13];
                if (!(kindAttr & 0x10)) {
                    continue;
                }
                x = unit[1];
                y = unit[2];
                map = (u8 *)*gCurrentMap;
                row = *(u16 *)(map + y * 2 + 0x3758);
                terrain = *(u8 *)(map + x + row + 0x1000 + 0x420) & 0x1f;
                doCost = 1;
                if (terrain == 0x12) {
                    if (func_ov000_021a911c(idx) == 1) {
                        doCost = 0;
                    }
                }
                if (doCost) {
                    ownerAttr = data_ov000_021b5bfc[0xa22];
                    costBase = *(s8 **)(data_0212616c + 0x64);
                    costTable = costBase + ownerAttr * 32;
                    t2 = *(u8 *)(map + x + row + 0x1000 + 0x420) & 0x1f;
                    cost = costTable[t2];
                    if (cost > 0) {
                        r6++;
                    } else {
                        r5++;
                    }
                    kind = unit[0] & 0x3f;
                    if (kind != 0x13) {
                        attr2 = data_ov000_021b5bfc[kind * 0x70 + 0x16];
                        if (attr2 & 3) {
                            hp = *(u16 *)(unit + 6);
                            r7 += (hp & 0x7f);
                        }
                    }
                }
            }
        }
    }

    if (r5 < 0 && r6 < 0) {
        return 0;
    }
    if (r5 > r6) {
        if (r7 > 0) return 3; else return 1;
    } else if (r5 < r6) {
        if (r7 > 0) return 4; else return 2;
    }
    return 0;
}

