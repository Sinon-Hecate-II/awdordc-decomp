/* 50 functions from 0x020C4D28 to 0x020C5D0C (main), found by ds-decomp. */
#include "common.h"
static inline s32 IsNewerValue(u32 b, u32 a) {
register u32 result=a&0xffff0000;
if(result==0xffff0000 && !(b&0xffff0000) && b!=0) result=0;
else if(!result && (b&0xffff0000)==0xffff0000 && a!=0) result=1;
else result=a>b;
return result;
}
extern void *gCur3DSpriteEngine;

void func_020c4d28(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_020761f8();
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK func_02086680(s32);
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        func_02086680(0xC000034C);
        func_02076244();
    }
    func_01ffa6fc(arg0);
}

M2C_UNK func_020c4d64(s32 arg0, s32 arg1) {
void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
void *func_01ffa42c(M2C_UNK *, s32);
extern M2C_UNK data_0212a65c, data_0212a53c;
s32 var_r5;
void *temp_r0;
void *temp_r0_2;
var_r5=arg0;
if(var_r5==0) var_r5=func_020c4b60();
if(arg1!=0) {
temp_r0=func_01ffa42c(&data_0212a65c,arg1);
if(temp_r0==NULL) return;
M2C_FIELD(temp_r0,M2C_UNK **,0)=&data_0212a53c;
M2C_FIELD(temp_r0,s32 *,0x34)=var_r5;
return;
}
temp_r0_2=func_01ffa3dc(&data_0212a65c,3);
if(temp_r0_2!=NULL) {
M2C_FIELD(temp_r0_2,M2C_UNK **,0)=&data_0212a53c;
M2C_FIELD(temp_r0_2,s32 *,0x34)=var_r5;
}
}

void func_020c4dd0(M2C_UNK arg0) {
    M2C_UNK func_020c4d64(M2C_UNK, M2C_UNK);
    func_020c4d64(0, arg0);
}

void func_020c4de4(void *arg0) {
    M2C_UNK func_02007f8c(void *, s32, s32);
    void *func_02076228(void);
    s32 func_02076234(void);
    s32 func_020761e0(u16);
    s32 func_020761c0(u16, void *);
    typedef struct { s32 v[4]; } SaveDate;
    typedef struct { s32 v[3]; } SaveTime;
    extern const SaveDate data_020f4e48;
#define SaveTime_Clear(p) do { M2C_FIELD((u32)(p), s32 *, 0) = 0; M2C_FIELD((u32)(p), s32 *, 4) = 0; M2C_FIELD((u32)(p), s32 *, 8) = 0; } while (0)
    u8 *p, *best;
    s32 n, i, id;
    void *base;
    SaveDate initial;
    SaveTime b;
    SaveDate a;
    SaveTime d;
    SaveDate c;

    p = func_02076228();
    best = 0;
    n = func_02076234();
    i = 0;
    if (n > 0) {
        do {
            if (p[2] == 2) {
                if (best) {
                    if (!IsNewerValue(M2C_FIELD(best, u32 *, 4), M2C_FIELD(p, u32 *, 4))) goto skip_next;
                }
                best = p;
            }
            skip_next:
            i++;
            p += 0x28;
        } while (i < n);
    }
    if (best) id = *(u16 *)best; else id = -1;
    if (id != -1 && func_020761e0((u16)id) == 0x90) {
        func_020761c0((u16)id, M2C_FIELD(arg0, void **, 0x34));
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), s32 *, 0) == 0x07090600) {
            return;
        }
    }
    base = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(base, s32 *, 0) = 0x07090600;
    func_02007f8c((u8 *)base + 4, 0, 0x40);
    M2C_FIELD(base, s32 *, 0x44) = 0;
    M2C_FIELD(base, s32 *, 0x48) = 0;
    M2C_FIELD(base, s32 *, 0x4C) = 0;
    M2C_FIELD(base, s32 *, 0x50) = 0x5dc000;
    M2C_FIELD(base, s32 *, 0x54) = 0x5dc000;
    initial = data_020f4e48;
    a = initial;
    M2C_FIELD(base, s32 *, 0x58) = a.v[0];
    M2C_FIELD(base, s32 *, 0x5C) = a.v[1];
    M2C_FIELD(base, s32 *, 0x60) = a.v[2];
    M2C_FIELD(base, s32 *, 0x64) = a.v[3];
    SaveTime_Clear(&b);
    M2C_FIELD(base, s32 *, 0x68) = 0;
    M2C_FIELD(base, s32 *, 0x6C) = b.v[1];
    M2C_FIELD(base, s32 *, 0x70) = b.v[2];
    c = initial;
    M2C_FIELD(base, s32 *, 0x74) = c.v[0];
    M2C_FIELD(base, s32 *, 0x78) = c.v[1];
    M2C_FIELD(base, s32 *, 0x7C) = c.v[2];
    M2C_FIELD(base, s32 *, 0x80) = c.v[3];
    SaveTime_Clear(&d);
    M2C_FIELD(base, s32 *, 0x84) = 0;
    M2C_FIELD(base, s32 *, 0x88) = d.v[1];
    M2C_FIELD(base, s32 *, 0x8C) = d.v[2];
}

void func_020c4ff4(M2C_UNK arg0) {
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        func_02086680(0xC000034D);
        func_02076244();
    }
    func_01ffa6fc(arg0);
}

void func_020c5030(s32 arg0, s32 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_01ffa42c(M2C_UNK *, s32);
    extern M2C_UNK data_0212a500;
    extern M2C_UNK data_0212a55c;
    s32 var_r5;
    void *temp_r0;
    void *temp_r0_2;

    var_r5 = arg0;
    if (var_r5 == 0) {
        var_r5 = func_020c4acc();
    }
    if (arg1 != 0) {
        temp_r0 = func_01ffa42c(&data_0212a55c, arg1);
        if (temp_r0 == NULL) {
            return;
        }
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_0212a500;
        M2C_FIELD(temp_r0, s32 *, 0x34) = var_r5;
        return;
    }
    temp_r0_2 = func_01ffa3dc(&data_0212a55c, 3);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_0212a500;
        M2C_FIELD(temp_r0_2, s32 *, 0x34) = var_r5;
    }
}

void func_020c509c(void *arg0){
M2C_UNK func_02007df8(s32,s32,s32);M2C_UNK func_02007f8c(void *,s32,s32);s32 func_020761c0(u16,void *);s32 func_020761e0(u16);
void *func_02076228(void);s32 func_02076234(void);
u8 *p,*best;s32 n,i,id,better;s32 j;void *dest,*base;
p=func_02076228();best=0;n=func_02076234();i=0;
if(n>0)do{if(p[2]==3){if(best){better=IsNewerValue(M2C_FIELD(best,u32 *,4),M2C_FIELD(p,u32 *,4));if(!better)goto next;}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id!=-1 && func_020761e0((u16)id)==0xc34){
func_020761c0((u16)id,M2C_FIELD(arg0,void **,52));
if(M2C_FIELD(M2C_FIELD(arg0,void **,52),s32 *,0)==0x07090600)return;
}
base=M2C_FIELD(arg0,void **,52);*(s32 *)base=0x07090600;func_02007f8c(base+4,0,0x2d0);
j=0;dest=base+0x2d4;
do{func_02007df8(0,dest,26);
M2C_FIELD(base,s16 *,0x2ee)=0;M2C_FIELD(base,s16 *,0x2f0)=0;M2C_FIELD(base,s16 *,0x2f2)=0;
M2C_FIELD(base,s8 *,0x2f4)=-1;M2C_FIELD(base,s8 *,0x2f5)=-2;j++;M2C_FIELD(base,s8 *,0x2f6)=-2;dest+=40;base+=40;
}while(j<60);
}

void func_020c5230(M2C_UNK arg0) {
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        func_02086680(0xC000034D);
        func_02076244();
    }
    func_01ffa6fc(arg0);
}

M2C_UNK func_020c526c(s32 arg0, s32 arg1) {
void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
void *func_01ffa42c(M2C_UNK *, s32);
extern M2C_UNK data_0212a594, data_0212a528;
s32 var_r5;
void *temp_r0;
void *temp_r0_2;
var_r5=arg0;
if(var_r5==0) var_r5=func_020c4b60();
if(arg1!=0) {
temp_r0=func_01ffa42c(&data_0212a594,arg1);
if(temp_r0==NULL) return;
M2C_FIELD(temp_r0,M2C_UNK **,0)=&data_0212a528;
M2C_FIELD(temp_r0,s32 *,0x34)=var_r5;
return;
}
temp_r0_2=func_01ffa3dc(&data_0212a594,3);
if(temp_r0_2!=NULL) {
M2C_FIELD(temp_r0_2,M2C_UNK **,0)=&data_0212a528;
M2C_FIELD(temp_r0_2,s32 *,0x34)=var_r5;
}
}

void func_020c52d8(M2C_UNK arg0) {
    M2C_UNK func_020c526c(M2C_UNK, M2C_UNK);
    func_020c526c(0, arg0);
}

s32 func_020c52ec(s32 arg0) {
    s32 func_020c4b60();
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_020c4b60();
    if (temp_r0 == 0) {
        return 0;
    }
    var_r4 = (arg0 * 0xC) + (temp_r0 + 4);
    if (func_02032380(var_r4) == 0) {
        var_r4 = 0;
    }
    return var_r4;
}

#pragma optimize_for_size off
s32 func_020c5328(s32 arg0) {
s32 p=func_020c4b60();
if(p==0) return 0;
if(!func_02032380(arg0*12+(p+4))) { p=0; return p; }
return arg0*40+(p+0x2d4);
}
#pragma optimize_for_size reset
s32 func_020c536c(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02007e20(M2C_UNK, s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r5;

    temp_r0 = func_020c4b60();
    if (temp_r0 == 0) {
        return 0;
    }
    temp_r4 = arg0 * 0x28;
    temp_r5 = temp_r0 + 0x2D4;
    func_02007e20(arg1, temp_r5 + temp_r4, 0x18);
    return temp_r5 + temp_r4;
}

s32 func_020c53ac(s32 arg0) {
s32 p=func_020c4b60();
if(!p)return 0;
p+=0x2d4;
if(M2C_FIELD(p+arg0*0x28,u16 *,0)==0)return 0;
return p+arg0*0x28;
}

void func_020c53e4(s32 arg0) {
    M2C_UNK func_02032604(s32);
    s32 func_020c4acc();
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_02032604(var_r0 + 4);
}

void func_020c5400(M2C_UNK arg0) {
    M2C_UNK func_02032380(M2C_UNK);
    M2C_UNK func_02032670(s32, M2C_UNK);
    func_02032670(func_020c4acc() + 4, arg0);
    func_02032380(arg0);
}

void func_020c5424(void) {
    M2C_UNK func_02032634();
    func_02032634();
}

u64 func_020c5430(s32 arg0) {
u64 func_02032558();
if(arg0==0)return 0;
return func_02032558();
}

s32 func_020c544c(s32 arg0) {
    s32 func_02031e70();
    if (arg0 == 0) {
        return 0;
    }
    return func_02031e70();
}

void func_020c5464(void) {
    M2C_UNK func_020c544c();
    M2C_UNK func_020c52ec();
    func_020c52ec();
    func_020c544c();
}

void func_020c5474(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02031f58(s32, M2C_UNK, M2C_UNK);
    func_02031f58(func_020c4acc() + 4, arg0, arg1);
}

s32 func_020c5498(s32 arg0) {
    M2C_UNK func_02032004();
    func_02032004();
    return arg0;
}

void func_020c54ac(void) {
    M2C_UNK func_02032024();
    func_02032024();
}

s32 func_020c54b8(void) {
    s32 func_0203a8dc();
    s32 func_02084644();
    s32 func_ov010_022282b4(M2C_UNK);
    if (func_02084644() != 2) {
        return 1;
    }
    if (func_ov010_022282b4(2) == 0) {
        return 1;
    }
    return func_0203a8dc();
}

s32 func_020c54e8(s32 arg0) {
s32 func_02032710(s32,s32);
s32 p, result=0, i, id;
p=func_020c4b60();
if(p==0)return result;
i=result;
id=func_020c477c(arg0);
p+=4;
do {
if(func_02032380(p)!=0 && (func_02032710(p,arg0)!=0 || (id>0 && id==func_020c477c(p)))) {result=1;break;}
i++;
p+=12;
}while(i<60);
return result;
}

s32 func_020c5574(s32 arg0, M2C_UNK arg1) {
M2C_UNK func_02007df8(M2C_UNK,s32,M2C_UNK);
M2C_UNK func_02008048(M2C_UNK,s32);
s32 p, offset, base; void *q;
if(func_020c54b8()==0)return -1;
if(func_020c54e8(arg1)!=0)return -1;
p=func_020c4b60();
if(!p)return -1;
base=p+4;
base+=arg0*12;
func_02008048(arg1,base);
offset=arg0*40;
func_02007df8(0,p+0x2d4+offset,26);
q=p+offset;
M2C_FIELD(q,s16 *,0x2ee)=0;
M2C_FIELD(q,s16 *,0x2f0)=0;
M2C_FIELD(q,s16 *,0x2f2)=0;
M2C_FIELD(q,s8 *,0x2f4)=-1;
M2C_FIELD(q,s8 *,0x2f5)=-2;
M2C_FIELD(q,s8 *,0x2f6)=-2;
return arg0;
}

void func_020c5618(s32 arg0) {
u8 sp0[12];
func_02032634(sp0);
func_020c5574(arg0,(s32)sp0);
}

s32 func_020c5640(M2C_UNK arg0) {
    s32 func_020c4798();
    s32 func_020c5574(s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_020c4798();
    if (temp_r0 < 0) {
        return -1;
    }
    return func_020c5574(temp_r0, arg0);
}

s32 func_020c5664(s32 arg0) {
s32 base,p,off,result;
if(!func_020c54b8()) return 0;
result=0;
base=func_020c4b60();
if(!base)return result;
p=func_020c52ec(arg0);
if(p && func_02032380(p)) {
func_0203a910(p);
off=arg0*0x28;
func_02007df8(result,base+0x2d4+off,0x1a);
base+=off; p=base;
M2C_FIELD(p,s16 *,0x2ee)=0;
M2C_FIELD(p,s16 *,0x2f0)=0;
M2C_FIELD(p,s16 *,0x2f2)=0;
M2C_FIELD(p,s8 *,0x2f4)=-1;
M2C_FIELD(p,s8 *,0x2f5)=-2;
M2C_FIELD(p,s8 *,0x2f6)=-2;
result=1;
}
return result;
}

s32 func_020c5708(s32 arg0) {
    s32 func_020c477c(s32);
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = -1;
    if (arg0 < 0) {
        return -1;
    }
    temp_r0 = func_020c4b60();
    if (temp_r0 == 0) {
        return -1;
    }
    var_r6 = temp_r0 + 4;
    var_r5 = 0;
loop_5:
    if ((func_02032380(var_r6) != 0) && (arg0 == func_020c477c(var_r6))) {
        var_r4 = var_r5;
    } else {
        var_r5 += 1;
        var_r6 += 0xC;
        if (var_r5 < 0x3C) {
            goto loop_5;
        }
    }
    return var_r4;
}

void func_020c5770(s32 arg0, void *arg1, void *arg2) {
    s32 func_02001fb4(s32, s32);
    s32 func_020719d4(s32);
    s32 func_02071564(s32, s32);
    double func_0207191c(s32);
    double func_0206e2d8(s32, s32, s32, s32);
    s32 func_0207044c(u32, u32);
    s32 func_02071438(s32, s32);
    s32 func_02071a64(u32, u32);
    s32 func_02071c50(s32, s32);
    s32 func_02070f24(s32, s32);
    u32 func_020719a0(s32);
    s32 func_02001fc4(s32);

    s32 mode = arg0;
    void *p1 = arg1;
    void *p2 = arg2;
    s32 r9 = *(s32 *)p2;
    s32 r8 = *(s32 *)p1;
    s32 r7 = func_02001fb4(r9 - r8, 0x190000);
    r8 = func_02001fb4(r8 - r9, 0x190000);

    /* process r7 */
    {
        s32 t;
        double d, e;
        u32 lo, hi;
        s32 f;

        t = func_020719d4(r7);
        t = func_02071564(t, 0x45800000);
        d = func_0207191c(t);
        lo = ((u32 *)&d)[0];
        hi = ((u32 *)&d)[1];
        e = func_0206e2d8(0, 0x40240000, (s32)lo, (s32)hi);
        f = func_0207044c(((u32 *)&e)[0], ((u32 *)&e)[1]);
        if (func_02071438(f, 0) > 0) {
            t = func_020719d4(r7);
            t = func_02071564(t, 0x45800000);
            d = func_0207191c(t);
            lo = ((u32 *)&d)[0];
            hi = ((u32 *)&d)[1];
            e = func_0206e2d8(0, 0x40240000, (s32)lo, (s32)hi);
            f = func_0207044c(((u32 *)&e)[0], ((u32 *)&e)[1]);
            t = func_02071a64(0x45800000, f);
            r7 = func_02070f24(t, 0x3f000000);
        } else {
            t = func_020719d4(r7);
            t = func_02071564(t, 0x45800000);
            d = func_0207191c(t);
            lo = ((u32 *)&d)[0];
            hi = ((u32 *)&d)[1];
            e = func_0206e2d8(0, 0x40240000, (s32)lo, (s32)hi);
            f = func_0207044c(((u32 *)&e)[0], ((u32 *)&e)[1]);
            t = func_02071a64(0x45800000, f);
            r7 = (s32)func_020719a0(func_02071c50(0x3f000000, t));
        }
    }

    /* process r8 */
    {
        s32 t;
        double d, e;
        u32 lo, hi;
        s32 f;

        t = func_020719d4(r8);
        t = func_02071564(t, 0x45800000);
        d = func_0207191c(t);
        lo = ((u32 *)&d)[0];
        hi = ((u32 *)&d)[1];
        e = func_0206e2d8(0, 0x40240000, (s32)lo, (s32)hi);
        f = func_0207044c(((u32 *)&e)[0], ((u32 *)&e)[1]);
        if (func_02071438(f, 0) > 0) {
            t = func_020719d4(r8);
            t = func_02071564(t, 0x45800000);
            d = func_0207191c(t);
            lo = ((u32 *)&d)[0];
            hi = ((u32 *)&d)[1];
            e = func_0206e2d8(0, 0x40240000, (s32)lo, (s32)hi);
            f = func_0207044c(((u32 *)&e)[0], ((u32 *)&e)[1]);
            t = func_02071a64(0x45800000, f);
            r8 = func_02070f24(t, 0x3f000000);
        } else {
            t = func_020719d4(r8);
            t = func_02071564(t, 0x45800000);
            d = func_0207191c(t);
            lo = ((u32 *)&d)[0];
            hi = ((u32 *)&d)[1];
            e = func_0206e2d8(0, 0x40240000, (s32)lo, (s32)hi);
            f = func_0207044c(((u32 *)&e)[0], ((u32 *)&e)[1]);
            t = func_02071a64(0x45800000, f);
            r8 = (s32)func_020719a0(func_02071c50(0x3f000000, t));
        }
    }

    r7 = func_02001fc4(r7 + 0x1000);
    r8 = func_02001fc4(r8 + 0x1000);

    if (mode == 0) {
        unsigned long long p1 = (unsigned long long)((long long)(0x1000 - r7) * 0x18000LL) + 0x800ULL;
        unsigned long long p2 = (unsigned long long)((long long)(0 - r8) * 0x18000LL) + 0x800ULL;
        *(s32 *)p1 = *(s32 *)p1 + (s32)(p1 >> 12);
        *(s32 *)p2 = *(s32 *)p2 + (s32)(p2 >> 12);
    } else if (mode == 1) {
        unsigned long long p1 = (unsigned long long)((long long)(0 - r7) * 0x18000LL) + 0x800ULL;
        unsigned long long p2 = (unsigned long long)((long long)(0x1000 - r8) * 0x18000LL) + 0x800ULL;
        *(s32 *)p1 = *(s32 *)p1 + (s32)(p1 >> 12);
        *(s32 *)p2 = *(s32 *)p2 + (s32)(p2 >> 12);
    } else if (mode == 2) {
        unsigned long long p1 = (unsigned long long)((long long)(0x800 - r7) * 0x18000LL) + 0x800ULL;
        unsigned long long p2 = (unsigned long long)((long long)(0x800 - r8) * 0x18000LL) + 0x800ULL;
        *(s32 *)p1 = *(s32 *)p1 + (s32)(p1 >> 12);
        *(s32 *)p2 = *(s32 *)p2 + (s32)(p2 >> 12);
    }
}

s32 func_020c5aac(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020c5ac0(void) {

}

void func_020c5ac4(void) {

}

s32 func_020c5ac8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020c5adc(void) {

}

s32 func_020c5ae0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020c5af4(void) {

}

s32 func_020c5af8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020c5b0c(void) {

}

s32 func_020c5b10(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020c5b24(void) {
    extern M2C_UNK data_02164d5c;
    extern void **gCurrentMap;
    M2C_FIELD(&data_02164d5c, s16 *, 2) = (s16) M2C_FIELD(*gCurrentMap, s16 *, 0x52D8);
    M2C_FIELD(&data_02164d5c, s16 *, 4) = (s16) M2C_FIELD(*gCurrentMap, s16 *, 0x52DA);
}

void func_020c5b5c(void) {
extern M2C_UNK data_02164d5c;
extern void **gCurrentMap;
M2C_FIELD(*gCurrentMap,s16 *,0x52d8)=M2C_FIELD(&data_02164d5c,s16 *,2);
M2C_FIELD(*gCurrentMap,s16 *,0x52da)=M2C_FIELD(&data_02164d5c,s16 *,4);
}

M2C_UNK func_020c5b98(s32 a) {
 void func_020c08f8(s32,s32,s32,s32,s32);void func_0209bfa8(void);void func_020809c0(void*,s32,s32);void func_0209b26c(s32,s32,s32,s32,s32,u16);
 extern M2C_UNK data_02164d5c;
 s32 zero;
 s32 tile;
 s16 index;
 func_020c08f8(7,18,18,6,1);
 func_0209bfa8();
 func_020809c0((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x24)+0x48e,18,6);
 zero=0;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x3a)=zero;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x42)=zero;
 M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
 if(a) { index=M2C_FIELD(&data_02164d5c,u8*,0); tile=index*(s16)56+0x124; func_0209b26c(8,19,1,a,zero,tile); }
 M2C_FIELD(&data_02164d5c,u8*,0)=(M2C_FIELD(&data_02164d5c,u8*,0)+1)&1;
}

void func_020c5c78(void *arg0) {
    
    func_020c5b98(M2C_FIELD(arg0, s32 *, 0x20));
}

void func_020c5c88(void) {
    M2C_UNK func_020c0784();
    func_020c0784();
}

void func_020c5c94(M2C_UNK arg0, M2C_UNK arg1) {
M2C_UNK func_020c0b88(M2C_UNK);
M2C_UNK func_020c7568();
func_020c0b88(arg1);
func_020c0784();
func_020c7568();
}

s32 func_020c5cac(void) {
    extern u16 data_02168f14;
    if ((u8) ((u32) (data_02168f14 << 0x1D) >> 0x1D) == 1) {
        return 0;
    }
    return 2;
}

s32 func_020c5cd4(void) {
    extern u8 data_02168f0c;
    if (data_02168f0c != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c5cf0(void) {
extern u8 data_02168f0c;
if(data_02168f0c) return 2;
return 0;
}

