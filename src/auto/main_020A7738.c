/* 71 functions from 0x020A7738 to 0x020A86F8 (main), found by ds-decomp. */
#include "common.h"
static inline s32 A8240InBounds(s32 x, s32 y) {
extern void **gCurrentMap;
if (x>=0 && y>=0 && x<M2C_FIELD(*gCurrentMap,u16 *,0x5144) && y<M2C_FIELD(*gCurrentMap,u16 *,0x5146)) return 1;
return 0;
}
typedef struct { u8 values[27]; } UnkA866cTable;
extern const UnkA866cTable data_020f3c04;

s32 func_020a7738(s32 arg0,s32 a,s32 b,u8 mode) {
M2C_UNK func_020a7310(); u8 func_020a7b0c(s32); s32 func_020a26f8(void *,u8,u8);
extern void **gCurrentMap;
register u8 *p=(u8 *)arg0;
s32 first,base,result,n;
func_020a7310();
first=func_020a7b0c((u32)(p[0]<<26)>>26);
base=func_020a26f8(p, M2C_FIELD(arg0,u8 *,1), M2C_FIELD(arg0,u8 *,2));
result=func_020a7848(p,a,b);
result+=first+base;
if(p){if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
if (((u32)(M2C_FIELD((u8 *)*gCurrentMap+n*0x8c,s32 *,0x6810)<<24)>>24)!=10 && mode==2) result=base+1;
if(result<1)result=1;
return result;
}

void func_020a7824(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020a7738(M2C_UNK, M2C_UNK, M2C_UNK, u8);
    extern void **gCurrentMap;
    func_020a7738(arg0, arg1, arg2, M2C_FIELD(*gCurrentMap, u8 *, 0x5158));
}

s32 func_020a7848(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 func_020d04ec(M2C_UNK, M2C_UNK, M2C_UNK);
 s32 var_r4;
 u32 temp_r0;
 var_r4 = 0;
 if (func_020d04ec(arg1, arg2, 4) != 0) {
  temp_r0 = (u32)(*arg0 << 26) >> 26;
  switch (temp_r0) {
  case 1:
  case 2: var_r4 += 3; break;
  }
 }
 return var_r4;
}

u32 func_020a788c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
}

u32 func_020a789c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C;
}

void func_020a78ac(u8 *arg0) {
    M2C_UNK func_020a7c68(u32);
    func_020a7c68((u32) (*arg0 << 0x1A) >> 0x1A);
}

u32 func_020a78c4(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19;
}

void func_020a78d4(u8 *arg0) {
    M2C_UNK func_020a7c50(u32);
    func_020a7c50((u32) (*arg0 << 0x1A) >> 0x1A);
}

u32 func_020a78ec(u8 *arg0) {
    return (u32) (*arg0 << 0x18) >> 0x1E;
}

s32 func_020a78fc(void *arg0) {
    s32 func_020a2728(void *, u8, u8);
    return func_020a2728(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2)) + 0xA;
}

s32 func_020a7914(void *arg0) {
 s32 func_020a2758(void *, u8, u8);
 s32 result = 0;
 result += func_020a2758(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
 return result;
}

s32 func_020a792c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
 s32 func_020a72fc(s32, s32);
 extern u8 data_ov000_021b5c13[];
 s32 var_r1;
 var_r1 = arg1;
 if (arg3 != 0) var_r1 = func_020a72fc(var_r1, (u8)arg3);
 return *(var_r1 + (data_ov000_021b5c13 + arg0 * 0x70 + (arg2 << 5)));
}

u8 func_020a796c(s32 arg0, s32 arg1, s32 arg2) {
 s32 func_020a5ae0(s32);
 extern u8 data_ov000_021b5c13[];
 return *(func_020a5ae0(arg1) + (data_ov000_021b5c13 + arg0 * 0x70 + (arg2 << 5)));
}

s32 func_020a799c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_020a792c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r4;

    var_r4 = func_020a792c(arg0, arg1, 0, arg2);
    temp_r0 = func_020a792c(arg0, arg1, 1, arg2);
    if (var_r4 <= temp_r0) {
        var_r4 = temp_r0;
    }
    return var_r4;
}

s32 func_020a79e0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6) {
 s32 func_0207c8ec(s32, s32);
 s32 func_020a7a74(s32, s32, s32, s32, u8);
 register s32 temp_r0;
 s32 var_r0;
 s32 base;
 s32 var_r5;
 var_r5 = func_020a792c(arg0, arg1, 0, arg2);
 temp_r0 = func_020a792c(arg0, arg1, 1, arg2);
 base = 100;
 if (var_r5 <= temp_r0) var_r5 = temp_r0;
 if ((int)var_r5 == 0) return 0;
 temp_r0 = func_020a7a74(arg0, arg3, arg4, arg5, arg6);
 base += temp_r0;
 var_r0 = func_0207c8ec(var_r5 * base, 100);
 if (var_r0 <= 1) var_r0 = 1;
 return var_r0;
}
s32 func_020a7a74(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
 u8 func_020a8560(void);
 s32 func_020a881c(s32);
 s32 func_020a2868(s32, s32, s32);
 extern void **gCurrentMap;
 s32 var_r4 = 0;
 if (func_020a8560() != 0) return var_r4;
 var_r4 += func_020a881c(arg2);
 if (((u32)(M2C_FIELD((u8 *)*gCurrentMap + arg2 * 0x8c, s32 *, 0x6810) << 24) >> 24) != 10 && arg1 == 3) var_r4 -= 30;
 if (arg4 != 0 || arg3 != 0) var_r4 += func_020a2868(arg0, arg2, arg3);
 return var_r4;
}

u8 func_020a7b0c(s32 arg0) {
 extern u8 data_ov000_021b5c06[];
 return data_ov000_021b5c06[arg0 * 0x70];
}

u8 func_020a7b24(s32 arg0) {
 extern u8 data_ov000_021b5c04[];
 return data_ov000_021b5c04[arg0 * 0x70];
}

s32 func_020a7b3c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
 s32 func_020a296c(s32, s32, s32);
 extern u8 data_ov000_021b5c04[];
 extern void **gCurrentMap;
 s32 var_r4;
 var_r4 = data_ov000_021b5c04[arg0 * 0x70];
 if (arg3 != 0 || arg4 != 0) var_r4 += func_020a296c(arg0, arg2, arg3);
 if ((u32)(M2C_FIELD((u8 *)*gCurrentMap + arg2 * 0x8c, s32 *, 0x6810) << 24) >> 24 != 10 && arg1 == 1) var_r4--;
 return var_r4;
}

u16 func_020a7bbc(s32 arg0) {
 extern u8 data_ov000_021b5c00[];
 return *(u16 *)(data_ov000_021b5c00 + arg0 * 0x70);
}

u8 func_020a7bd4(s32 arg0) {
 extern u8 data_ov000_021b5c09[];
 return data_ov000_021b5c09[arg0 * 0x70];
}

void func_020a7bec(void) {
    u8 func_020a7bd4();
    func_020a7bd4();
}

u8 func_020a7bf8(s32 arg0) {
 extern u8 data_ov000_021b5c08[];
 return data_ov000_021b5c08[arg0 * 0x70];
}

s32 func_020a7c10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
 s32 func_020a29e4(s32, s32, s32);
 extern u8 data_ov000_021b5c09[];
 s32 var_r4;
 var_r4 = data_ov000_021b5c09[arg0 * 0x70];
 if (arg3 != 0 || arg4 != 0) var_r4 += func_020a29e4(arg0, arg2, arg3);
 return var_r4;
}

s32 func_020a7c50(u32 arg0) {
 extern u8 data_ov000_021b5c0a[];
 return data_ov000_021b5c0a[arg0 * 0x70];
}

s32 func_020a7c68(u32 arg0) {
 extern u8 data_ov000_021b5c05[];
 return data_ov000_021b5c05[arg0 * 0x70];
}

s32 func_020a7c80(arg0)
s32 arg0;
{
 extern u8 data_ov000_021b5c0c[];
 return data_ov000_021b5c0c[arg0 * 0x70];
}

u8 func_020a7c98(s32 arg0) {
 extern u8 data_ov000_021b5c0e[];
 return data_ov000_021b5c0e[arg0 * 0x70];
}

u8 func_020a7cb0(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7cc8(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x10) >> 0x1B) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7ce4(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7cfc(s32 arg0) {
    s32 func_020a32f4();
    M2C_UNK func_020a7310();
    u8 var_r0;

    func_020a7310();
    if (arg0 == func_020a32f4()) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d20(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d38(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x20) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d50(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x100) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d68(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x80) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d80(void *arg0) {
 s32 temp_r0;
 s32 var_r0;
 temp_r0 = func_020a7c50((u32)(M2C_FIELD(arg0, u8 *, 0) << 26) >> 26);
 if (temp_r0 > 0 && (temp_r0 >> 1) >= (s32)((u32)(M2C_FIELD(arg0, u8 *, 10) << 25) >> 25)) var_r0 = 1;
 else var_r0 = 0;
 return var_r0;
}

u8 func_020a7dc4(void *arg0) {
 s32 temp_r0;
 s32 var_r0;
 temp_r0 = func_020a7c68((u32)(M2C_FIELD(arg0, u8 *, 0) << 26) >> 26);
 if (temp_r0 > 0 && (temp_r0 >> 1) >= (s32)((u32)(M2C_FIELD(arg0, u16 *, 6) << 21) >> 28)) var_r0 = 1;
 else var_r0 = 0;
 return var_r0;
}

u8 func_020a7e08(u8 *p){extern u8 data_ov000_021b5c65[];u8 r;if(data_ov000_021b5c65[((u32)(*p<<26)>>26)*0x70])r=1;else r=0;return r;}

void func_020a7e3c(s32 arg0, s32 arg1) {
    s32 func_020a3550(s32, s32);
    void func_020a3128(s32);
    s32 func_020d19b4(s32);
    void func_02091c20(s32, s32);
    extern void **gCurrentMap;
    s32 idx;
    u8 *base;
    u8 *arr;
    u8 *entry;
    s32 result;

    if (arg0 == 0) return;
    base = (u8 *)*gCurrentMap;
    idx = ((s32)arg0 - (s32)(base + 0x59a4)) / 7;
    idx = (idx >> 6) + 1;
    arr = (u8 *)*(void **)base;
    entry = arr + 0x67a4 + idx * 0x8c;
    if (!(entry[0x6c] & 0xff)) return;
    if (arg0 != (s32)(arr + 0x59a4 + (entry[0x70] & 0xff) * 0xE)) return;
    entry[0x70] = 0;
    if (arg1 == 0) return;
    func_020a3550(idx, 0);
    func_020a3128(idx);
    result = func_020d19b4(idx);
    if (result != 0) {
        func_02091c20(0x1c, 1);
    }
}

void func_020a7f18(void *p,u32 a){u16 v=M2C_FIELD(p,u16 *,6); a=(u16)a; M2C_FIELD(p,u16 *,6)=(v&~0xf800)|((a<<27)>>16);}

u32 func_020a7f38(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x10) >> 0x1B;
}

void func_020a7f48(void *unit,s32 x,s32 y,s32 mode) {
extern void **gCurrentMap;
void func_020d0288(void *,s32,s32,s32,s32,s32);s32 func_020d02b4(void *);
u8 func_020a8478(s32,s32);u8 func_020a80fc(s32,s32);u8 func_020a8164(s32,s32);void func_020a7f18(void *,u32);
s32 iter[8];void *map;void *base; s32 idx;
map=*gCurrentMap;
func_020d0288(iter,mode,x,y,M2C_FIELD(map,u16 *,0x5144),M2C_FIELD(map,u16 *,0x5146));
for(;;){
if(!func_020d02b4(iter))return;
if(func_020a8478(iter[4],iter[5])){
map=*gCurrentMap;
idx=M2C_FIELD(M2C_FIELD(map+2*iter[5],u16 *,0x3758)+(map+iter[4]),u8 *,0x508);
base=map+0x59a4;
if(!func_020a80fc((s32)unit,(s32)(base+idx*14)))break;
func_020a7f18(base+idx*14,1);
if(func_020a8164((s32)unit,(s32)(base+idx*14)))func_020a7f18(unit,1);
}
}
}

void func_020a8050(void *p,s16 *xy,s32 unused,s8 *dir){void func_020a7f48(void *,s32,s32,s32);s32 x=xy[0],y=xy[1];func_020a7f48(p,x,y,1);for(;;){switch(*dir++){case 0:x--;break;case 1:x++;break;case 3:y--;break;case 2:y++;break;case -1:case 4:case 10:return;}func_020a7f48(p,x,y,1);}}

u8 func_020a80fc(s32 arg0, s32 arg1) {
    s32 temp_r4;
    u8 var_r0;

    if ((arg1 == 0) || (func_020a81c8(arg1) == 0)) {
        return 0U;
    }
    if (arg0 == 0) {
        return 1U;
    }
    temp_r4 = func_020a7310(arg0);
    if (func_020d273c(temp_r4, func_020a7310(arg1)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a8164(s32 arg0, s32 arg1) {
    s32 func_020d273c(s32, s32);
    s32 temp_r4;
    u8 var_r0;

    if ((arg0 == 0) || (func_020a81c8() == 0)) {
        return 0U;
    }
    if (arg1 == 0) {
        return 0U;
    }
    temp_r4 = func_020a7310(arg0);
    if (func_020d273c(temp_r4, func_020a7310(arg1)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a81c8(void) {
    return 0;
}

u8 func_020a81d0(M2C_UNK arg0) {
    u8 var_r0;

    if (func_020a81c8() == 0) {
        return 0U;
    }
    if (func_020a7f38(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a8204(void *arg0) {
    s32 func_020a8630(u32);
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) == 0) {
        return 0U;
    }
    if (func_020a8630((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020a8240(u8 *unit, s32 dx, s32 dy, u8 *out) {
extern void **gCurrentMap;
s32 x=unit[1], y=unit[2]; s32 n; s32 step; s32 n2;
n=dx<0?-dx:dx; step=dx>0?1:-(dx<0);
for(;n>0;n--){
x+=step;
if(!A8240InBounds(x,y))break;
if(M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap+y*2,u16 *,0x3758)+((u8 *)*gCurrentMap+x),u8 *,0x508)!=0)break;
if(step>0)*out++=1; if(step<0)*out++=0;
}
n2=dy<0?-dy:dy; dy=dy>0?1:-(dy<0);
for(;n2>0;n2--){
y+=dy;
if(!A8240InBounds(x,y))break;
if(M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap+y*2,u16 *,0x3758)+((u8 *)*gCurrentMap+x),u8 *,0x508)!=0)break;
if(dy>0)*out++=2; if(dy<0)*out++=3;
}
*out=255;
}

void func_020a83e4(u8 *p,s8 *dir){do{switch(*dir++){case 9:dir++;continue;case -1:case 4:return;case 0:p[1]--;continue;case 1:p[1]++;continue;case 3:p[2]--;continue;case 2:p[2]++;continue;case 10:default:continue;}}while(1);}

void func_020a8474(void) {

}

u8 func_020a8478(s32 a,s32 b){extern void **gCurrentMap;void *p=*gCurrentMap;return M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758)),u8 *,0x508)!=0;}

u8 func_020a84b4(s32 a,s32 b){extern void **gCurrentMap;void *p=*gCurrentMap;return M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758)),u8 *,0x508)==0;}

u8 func_020a84f0(void) {
    s32 func_020a7c80();
    u8 var_r0;

    if (func_020a7c80() == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a850c(void) {
    u8 var_r0;

    if (func_020a7c80() == 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a8528(void *a){u8 func_020a84f0();u8 func_020a850c();s32 v;if(func_020a84f0(a)||func_020a850c(a))v=1;else v=0;return (u8)v;}

u8 func_020a8560(void) {
    u8 var_r0;

    if (func_020a7c80() == 6) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a857c(void *p){s32 func_020a8528(void *);u8 func_020a8560();if(!p)return 0;if(func_020a8528(p)||func_020a8560(p))return 1;return 0;}

s32 func_020a85b8(void) {
    return 0;
}

s32 func_020a85c0(void) {
    return 0;
}

u8 func_020a85c8(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x14) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a85dc(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x15) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a85f0(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x15) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020a8604(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 13:
        return 1;
    case 21:
        return 1;
    default:
        return 0;
    }
}

s32 func_020a8630(u32 a){switch(a){case 5:return 1;case 13:return 1;case 21:return 1;default:return 0;}}

u8 func_020a866c(u32 a){UnkA866cTable t=data_020f3c04;return t.values[a];}

s32 func_020a86bc(void) {
    return 0;
}

s32 func_020a86c4(s32 a,s32 b){extern s8 data_ov000_021b5520[];extern u8 data_02168f14[];s32 v=0;if(data_ov000_021b5520[b&31])v+=M2C_FIELD(data_02168f14,u16 *,6);return v;}

s32 func_020a86f0(void) {
    return 1;
}

