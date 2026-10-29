/* 48 functions from 0x020D2470 to 0x020D3464 (main), found by ds-decomp. */
#include "common.h"

void func_020d2470(void) { }

u8 func_020d273c(s32 a, s32 b) {
    extern s32 *gCurrentMap;
    s32 base;
    s32 work;
    u8 *p1;
    u8 *p2;
    base = *gCurrentMap + 0x3A4;
    work = base + 0x6400;
    p1 = (u8 *)(work + a * 0x8C);
    p2 = (u8 *)(work + b * 0x8C);
    return p1[0x26] == p2[0x26];
}

u8 func_020d277c(s32 arg0, s32 arg1) {
    u8 func_020d273c(s32, s32);
    s32 func_020a7310(s32);
    s32 temp_r4;

    temp_r4 = func_020a7310(arg0);
    return func_020d273c(temp_r4, func_020a7310(arg1));
}

void func_020d27a4(s32 arg0, s32 arg1) {
    u8 func_020d273c(s32, s32);
    func_020d273c((arg0 >> 6) + 1, (arg1 >> 6) + 1);
}

u8 func_020d27c0(s32 arg0) {
    extern s32 *gCurrentMap;
    u8 func_020d273c(s32, s32);
    return func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), (arg0 >> 6) + 1);
}

s32 func_020d27ec(s32 arg0, s32 arg1) {
    s32 temp = arg0 >> 6;
    if ((arg1 >> 5) == 0) {
        return 0;
    }
    return func_020d273c(temp + 1, arg1 >> 5);
}

s32 func_020d280c(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *gCurrentMap;
    u8 func_020d273c(s32, s32);
    s32 p;
    u16 val;
    u8 byte;
    s32 pos;

    p = *gCurrentMap;
    val = *(u16 *)(p + arg2 * 2 + 0x3758);
    pos = arg1 + val;
    byte = *(u8 *)(p + pos + 0x1420);
    if ((byte >> 5) == 0) {
        return 0;
    }
    return func_020d273c(arg0, byte >> 5);
}

s32 func_020d2850(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *data_027e0058;
    extern u8 data_ov000_021b5c5c[];
    s32 result = 0;

    if (M2C_FIELD(*data_027e0058, u8 *, 0x5156) == 0 &&
        M2C_FIELD(*data_027e0058, u8 *, 0x5158) == 2 &&
        (M2C_FIELD(*data_027e0058, u8 *, arg2 * 0x8C + 0x67C3) & 2) == 0) {
        result = (data_ov000_021b5c5c[arg0 * 0x70] != 0);
    }
    return result;
}

void func_020d28bc(void) {
 extern s32 *gCurrentMap; s32 func_020d1938(s32);
 s32 i,ioff,j,joff; unsigned char *base,*other,*self;
 i=1;ioff=0x8c;
 do {
 if(func_020d1938(i)) {
 j=1;joff=0x8c;
 do {
 if(j!=i) {
 base=(unsigned char *)*gCurrentMap;other=base+joff;
 if(other[0x67c2]) {
 self=base+ioff;
 if(other[0x67ca]==self[0x67ca])*(u16 *)(other+0x67be)=0;
 }
 }
 j++;joff+=0x8c;
 }while(j<5);
 }
 i++;ioff+=0x8c;
 }while(i<5);
}

void func_020d2958(void) {
    extern s32 *gCurrentMap;
    s32 func_020d1980(s32);
    s32 i = 1;
    s32 off = 0x8C;

    do {
        if (func_020d1980(i) != 0) {
            M2C_FIELD(*gCurrentMap + off, u16 *, 0x67BE) = 0;
        }
        i++;
        off += 0x8C;
    } while (i < 5);
}

s32 func_020d29a8(M2C_UNK arg0) {
 s32 func_020d2a00(M2C_UNK); s32 func_020d2a6c(M2C_UNK); s32 func_020d303c(M2C_UNK);
 if (!func_020d1938()) return 1;
 if (func_020d2a00(arg0)) {
 if (func_020d303c(arg0)) return 1;
 if (func_020d2a6c(arg0)) return 1;
 }
 return 0;
}

s32 func_020d2a00(s32 arg0) {
    extern u16 data_ov000_021aeef4[];
    extern s32 *gCurrentMap;
    s32 end;
    s32 i;

    i = data_ov000_021aeef4[arg0] + 1;
    end = data_ov000_021aeef4[arg0] + 0x33;
    if (i < end) {
        u8 *p = (u8 *)*gCurrentMap + 0x59A4 + i * 14;
        do {
            if (((u32)(*p << 26) >> 26) != 0) {
                return 0;
            }
            i++;
            p += 14;
        } while (i < end);
    }
    return 1;
}

s32 func_020d2a6c(s32 arg0) {
    extern s32 *gCurrentMap;
    extern s8 data_ov000_021b5580[];
    u8 *base;
    u16 ycount;
    u16 xcount;
    s32 y;
    s32 x;
    u8 byte;
    s8 chk;
    u8 *p;
    u16 val;

    base = (u8 *)*gCurrentMap;
    ycount = M2C_FIELD(base, u16 *, 0x5146);
    if ((s32)ycount <= 0) {
        return 1;
    }
    xcount = M2C_FIELD(base, u16 *, 0x5144);
    for (y = 0; y < (s32)ycount; y++) {
        if ((s32)xcount <= 0) {
            continue;
        }
        val = M2C_FIELD(base + y * 2, u16 *, 0x3758);
        p = base + val;
        for (x = 0; x < (s32)xcount; x++) {
            byte = M2C_FIELD(p, u8 *, 0x1420);
            if (((byte & 0xE0) >> 5) == (u8)arg0) {
                chk = data_ov000_021b5580[byte & 0x1F];
                if (chk != 0) {
                    return 0;
                }
            }
            p++;
        }
    }
    return 1;
}

void func_020d2b10(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 func_020d19b4(s32);
    void func_02091c54(s32, s32);

    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c54(0xB, arg1);
        *((s32 *)((u8 *)*gCurrentMap + 0x67A4 + arg0 * 0x8C)) -= arg1;
        *((s32 *)((u8 *)*gCurrentMap + 0x67A4 + arg0 * 0x8C) + 1) += arg1;
        if (*((s32 *)((u8 *)*gCurrentMap + 0x67A4 + arg0 * 0x8C) + 1) > 0x3B9AC9FF) {
            *((s32 *)((u8 *)*gCurrentMap + 0x67A4 + arg0 * 0x8C) + 1) = 0x3B9AC9FF;
        }
    }
}

void func_020d2bc0(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 off;
    s32 *base;
    s32 *p;

    off = arg0 * 0x8C;
    base = *gCurrentMap;
    p = (s32 *)((u8 *)base + 0x67A4 + off);
    *p += arg1;
    base = *gCurrentMap;
    p = (s32 *)((u8 *)base + 0x67A4 + off);
    if (*p > 0xF423F) {
        *p = 0xF423F;
    }
}

#pragma opt_strength_reduction off
s32 func_020d2c18(s32 arg0) {
    extern s32 *gCurrentMap;
    s32 func_020a27b8(s32, s32);
    u32 val;
    s32 base;

    base = *gCurrentMap;
    val = M2C_FIELD(base + 0x3A4 + 0x6400 + arg0 * 0x8C, u32 *, 0x6C);
    return func_020a27b8((s32)(val << 24 >> 24), (s32)(val << 20 >> 30));
}
#pragma opt_strength_reduction on
s32 func_020d2c58(s32 arg0) {
 extern M2C_UNK data_02168f08;
 s32 func_020a334c(s32);s32 func_020a3594(s32,s32);s32 func_020a3518(s32);
 s32 r5; s32 count=0;
 if((((u32)M2C_FIELD(&data_02168f08,u16 *,12)<<19)>>31)==0)return 0;
 if(func_020a334c(arg0))return 0;
 if(!func_020a3594(arg0,2))return 0;
 r5=func_020a3518(arg0);if(r5>=func_020a3594(arg0,1))count++;
 r5=func_020a3518(arg0);if(r5>=func_020a3594(arg0,2))count++;
 return count;
}

void func_020d2cf0(M2C_UNK arg0) {
    M2C_UNK func_020a25bc(s32, s32);
    s32 func_020d2c18();
    s32 func_020d2c58(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_020d2c18();
    func_020a25bc(temp_r4, func_020d2c58(arg0));
}

s32 func_020d2d18(arg0, arg1)
    u16 arg0;
    s32 arg1;
{
    s32 func_020a7bbc(s32);
    s32 func_0207c8ec(s32, s32);
    s32 t;

    t = func_020a7bbc(arg1);
    return func_0207c8ec(t * 0x64, 0x64);
}

s32 func_020d2d38(void) {
    return func_020d2d18() * 0xA;
}

s32 func_020d2d50(void) {
    s32 func_020d2d18();
    return func_020d2d18() * 5;
}

void func_020d2d60(M2C_UNK arg0) {
    s32 func_020a32a8();
    M2C_UNK func_020a3100(M2C_UNK);
    if (func_020a32a8() != 0) {
        return;
    }
    func_020a3100(arg0);
}

void func_020d2d80(M2C_UNK arg0) {
    M2C_UNK func_020a33f0(M2C_UNK, M2C_UNK);
    func_020a33f0(arg0, 0);
}

void func_020d2d90(s32 arg0) {
    extern s32 *gCurrentMap;
    void func_020d2bc0(s32, s32);
    s32 base = *gCurrentMap;
    s32 v = M2C_FIELD(base, u16 *, 0x52A2);

    if (v <= 0) {
        return;
    }
    func_020d2bc0(arg0, M2C_FIELD(base + arg0 * 0x8C, s32 *, 0x6000 + 0x7AC));
}

s32 func_020d2dcc(s32 arg0) {
    extern u16 data_ov000_021aeef4[];
    extern s32 *gCurrentMap;
    s32 val;
    s32 end;
    s32 i;
    u8 *base;
    u8 *p;

    val = data_ov000_021aeef4[arg0];
    i = val + 1;
    end = val + 0x33;
    if (i < end) {
        base = (u8 *)*gCurrentMap + 0x59A4;
        p = base + i * 14;
        do {
            if (((u32)(*p << 26) >> 26) == 0) {
                return (s32)(base + i * 14);
            }
            i++;
            p += 14;
        } while (i < end);
    }
    return 0;
}

void *func_020d2e3c(u16 arg0) {
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 *mp;
    u8 *base;
    u16 *curP;
    s16 cur;
    u16 T;
    u16 x;
    u16 start;

    mp = *gCurrentMap;
    base = (u8 *)mp;
    T = data_ov000_021aeef4[arg0];
    cur = *(s16 *)(base + 0x52c0);
    curP = (u16 *)(base + 0x52c0);
    start = (u16)(cur + 1);

    if (start < 0x33) {
        for (x = start; x < 0x33; x++) {
            u8 kind = base[0x59a4 + (x + T) * 14];
            if ((kind & 0x3f) != 0) {
                u16 field = *(u16 *)(base + 0x59a8 + (x + T) * 14);
                if ((field & 1) == 0) {
                    *curP = x;
                    {
                        u8 *base2 = (u8 *)*gCurrentMap;
                        s16 cur2 = *(s16 *)(base2 + 0x52c0);
                        if (cur2 >= 0x32) {
                            *(s16 *)(base2 + 0x52c0) = 0;
                        }
                        return (void *)(base2 + 0x59a4 + (x + T) * 14);
                    }
                }
            }
        }
    }

    if (cur + 1 <= 1) {
        return 0;
    }

    for (x = 1; x <= cur; x++) {
        u8 kind = base[0x59a4 + (x + T) * 14];
        if ((kind & 0x3f) != 0) {
            u16 field = *(u16 *)(base + 0x59a8 + (x + T) * 14);
            if ((field & 1) == 0) {
                *curP = x;
                {
                    u8 *base2 = (u8 *)*gCurrentMap;
                    s16 cur2 = *(s16 *)(base2 + 0x52c0);
                    if (cur2 >= 0x32) {
                        *(s16 *)(base2 + 0x52c0) = 0;
                    }
                    return (void *)(base2 + 0x59a4 + (x + T) * 14);
                }
            }
        }
    }

    return 0;
}

u8 func_020d2ff0(s32 arg0) {
    extern s32 *gCurrentMap;
    return M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), u8 *, 0x67D5);
}

u8 func_020d3014(s32 a, s32 b) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)(a*0x8c+*gCurrentMap);
p+=b;
return p[0x67d7];
}

s32 func_020d303c(s32 arg0) {
    extern s32 *gCurrentMap;
    s32 i;
    s32 acc;
    u8 *p;

    acc = 0;
    i = acc;
    p = (u8 *)*gCurrentMap + arg0 * 0x8C;
    do {
        acc += p[0x67D7];
        p++;
        i++;
    } while (i < 0x1B);
    return acc;
}

u8 func_020d3080(s32 a,s32 b) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)(a*0x8c+*gCurrentMap);
p+=b;
return p[0x67f2];
}

s32 func_020d30a8(s32 a) {
extern s32 *gCurrentMap;
s32 i;
s32 sum;
u8 *p;
sum=0;
p=(u8 *)(a*0x8c+*gCurrentMap);
for(i=0;i<27;i++,p++)sum+=M2C_FIELD(p,u8 *,0x67f2);
return sum;
}

void func_020d30ec(s32 a) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
if((u32)p[0x31]<255)p[0x31]++;
}

s32 func_020d3120(s32 a) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
s32 v=p[0x31];
if(v!=0){v--;p[0x31]=v;}
return v;
}

void func_020d3154(s32 a,s32 b) {
extern s32 *gCurrentMap;
u8 *p;
func_020d30ec(a);
p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
p+=0x33;
if(p[b]!=255)p[b]++;
}

void func_020d319c(s32 a,s32 b) {
extern s32 *gCurrentMap;
u8 *p;
func_020d3120(a);
p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;
p+=0x4e;
if(p[b]!=255)p[b]++;
}

void func_020d31e4(void) {
    M2C_UNK func_020d3120();
    func_020d3120();
}

void func_020d31f0(s32 a, u8 b) {
extern s32 *gCurrentMap;
M2C_FIELD(a*0x8c+*gCurrentMap,u8 *,0x67d3)=b;
}

u8 func_020d3214(s32 a){extern s32 *gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x67d3]!=0;}

u8 func_020d3248(M2C_UNK arg0) {
    u8 var_r0;

    if (func_020d1938() == 0) {
        return 0U;
    }
    if (func_020d3214(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020d327c(s32 a,u8 b) {
extern s32 *gCurrentMap;
M2C_FIELD(a*0x8c+*gCurrentMap,u8 *,0x67d4)=b;
}

u8 func_020d32a0(s32 a){extern s32 *gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x67d4]!=0;}

u8 func_020d32d4(s32 a){
extern s32 *gCurrentMap;u8 result;
if(!(((u8 *)*gCurrentMap)[0x5155]&2))return 1;
if(func_020d1938(a)==0)return 0;
if(func_020d32a0(a)==0)result=1;else result=0;
return result;
}

u8 func_020d332c(s32 a){
extern s32 *gCurrentMap;u8 result;
if(!(((u8 *)*gCurrentMap)[0x5155]&1))return 1;
if(func_020d29a8(a)==0)result=1;else result=0;
return result;
}

u8 func_020d336c(s32 a){
extern s32 *gCurrentMap; s32 func_020d19b4(s32); u8 result;
if(func_020d19b4(a)==0)return 1;
if(!(((u8 *)*gCurrentMap)[0x5155]&16))return 1;
if(func_020d29a8(a)==0)result=1;else result=0;
return result;
}

void func_020d33c4(void) {
    extern M2C_UNK data_02168f08;
    M2C_FIELD(&data_02168f08, s32 *, 8) = 0;
}

void func_020d33d8(void) {
    extern M2C_UNK data_02168f08;
    M2C_FIELD(&data_02168f08, s32 *, 8) = 1;
}

void func_020d33ec(void) {
    extern M2C_UNK data_02168f08;
    M2C_FIELD(&data_02168f08, s32 *, 8) = 0;
}

void func_020d3400(void){
extern M2C_UNK data_02168f08; extern s32 *gCurrentMap;
s32 func_020947c0(void); s32 func_020b5258(void); void func_0209cbe4(void *);
u8 *p; s32 q;
if(M2C_FIELD(&data_02168f08,s32 *,8)==0)return;
if(func_020947c0()!=0)return;
if(func_020b5258()!=0)return;
p=(u8 *)*gCurrentMap;
q=(s32)p+0x67a4+M2C_FIELD(p,u16 *,0x52a4)*0x8c;
func_0209cbe4((u8 *)q+0x84);
}

