/* 18 functions from 0x02024260 to 0x020251B8 (main), found by ds-decomp. */
#include "common.h"

extern void *(*data_021372a4)(s32);
extern void (*data_021372d0[])(void *);

s32 func_02024a6c(void *p){s32 func_02023f20(void *);if(func_02023f20(p)!=7)return 1;return func_02023f20(p)!=6;}

s32 func_02024a9c(void *p){s32 func_02023f20(void *);s32 func_02024260(void *);void func_02023318(void *);void func_020244c0(void *);if(func_02023f20(p)!=1)return 1;if(func_02024260(p)){func_02023318(M2C_FIELD(p,void **,12));func_020244c0(p);if(func_02024a6c(p))return 1;}else{if(func_02023f20(p)!=5)return 1;if(func_02024a6c(p))return 1;func_020244c0(p);}return 0;}

void func_02024b24(void *p) {
    void func_0201d25c(void *);
    void func_0201d434(void *);
    void func_02025fc0(void *);
    void func_02025700(void *);
    void *q = M2C_FIELD(p, void **, 12);
    for (;;) {
        func_0201d25c(p);
        M2C_FIELD(q, u8 *, 0x455) = 0;
        M2C_FIELD(q, s32 *, 0x1d4) = 0;
        M2C_FIELD(q, u8 *, 0x454) = 1;
        func_02025fc0((u8 *)q + 0x2ec);
        func_02025700((u8 *)q + 0x3a4);
        if (!func_02024a9c(p)) {
            M2C_FIELD(q, u8 *, 0x455) = 8;
            return;
        }
        func_0201d434(p);
        M2C_FIELD(p, u16 *, 0x18) = M2C_FIELD(p, u16 *, 0x1a);
        M2C_FIELD(p, s32 *, 0x1c) = M2C_FIELD(p, s32 *, 0x20);
    }
}

s32 func_02024b94(void *arg0) {
 void func_02021f1c(void *,s32,u16); void func_020232b8(void *);void func_02023318(void *);s32 func_02023f20(void *);void func_020244c0(void *);void func_02024618(void *);void func_020247ac(void *);s32 func_02024a6c(void *);
 void *p=M2C_FIELD(arg0,void **,12);s32 state;
 func_02024618(arg0);
 do {
 state=func_02023f20(arg0);
 if(state==9)return 1;
 }while(state!=4 && M2C_FIELD(p,u8 *,0x31)==0);
 if(M2C_FIELD(p,u8 *,0x31)) {
 func_02023318(p);
 if(func_02024a6c(arg0))return 1;
 func_020244c0(arg0);
 } else {
 func_020247ac(arg0);func_020232b8(p);
 if(M2C_FIELD(p,u8 *,0x30))func_02021f1c(p,M2C_FIELD(arg0,s32 *,0x1c),M2C_FIELD(arg0,u16 *,0x18));
 func_02023318(p);func_020244c0(arg0);
 if(func_02024a6c(arg0))return 1;
 }
 M2C_FIELD(p,u8 *,0x455)=8;
 return 0;
}

s32 func_02024c60(void *p){s32 func_0201d2f0(void *);s32 func_02024b94(void *);void func_02025fc0(void *);void func_02025700(void *);void *q=M2C_FIELD(p,void **,12);if(M2C_FIELD(p,u8 *,8)!=4&&func_0201d2f0(p))return 1;M2C_FIELD(q,u8 *,0x455)=0;M2C_FIELD(q,s32 *,0x1d4)=0;M2C_FIELD(q,u8 *,0x454)=0;func_02025fc0((u8 *)q+0x2ec);func_02025700((u8 *)q+0x3a4);return func_02024b94(p);}

s32 func_02024cb4(s32 *arg0, void *arg1) {
    s32 func_02023c08(s32, u32, M2C_UNK);
          void func_02023ca0(void *, void *);
    s32 func_02023f20(void *);
    extern void (*data_021372d0[])(void *);
    void *r4;
    void *ip;

    r4 = M2C_FIELD(arg1, void **, 0xC);
    ip = M2C_FIELD(r4, void **, 0x824);
    if (ip != 0 && M2C_FIELD(r4, u8 *, 0x456) == 0) {
        s32 r3 = M2C_FIELD(r4, s32 *, 0x82C);
        if (func_02023c08((s32)ip + r3, (u32)(M2C_FIELD(r4, s32 *, 0x828) - r3), arg1) != 0) {
            data_021372d0[0](M2C_FIELD(r4, void **, 0x824));
            M2C_FIELD(r4, void **, 0x824) = 0;
            *arg0 = 0;
            return 0;
        }
        func_02023ca0(r4, M2C_FIELD(r4, void **, 0x824));
        if (M2C_FIELD(r4, u8 *, 0x456) == 0) {
            M2C_FIELD(r4, void **, 0x824) = 0;
        }
    }
    if (M2C_FIELD(r4, void **, 0x824) == 0) {
        for (;;) {
            if (func_02023f20(arg1) == 9) {
                *arg0 = 0;
                return 0;
            }
            if (M2C_FIELD(r4, void **, 0x824) != 0) {
                break;
            }
        }
    }
    *arg0 = M2C_FIELD(r4, s32 *, 0x828) - M2C_FIELD(r4, s32 *, 0x82C);
    return (s32)M2C_FIELD(r4, void **, 0x824) + M2C_FIELD(r4, s32 *, 0x82C);
}

void func_02024d8c(u32 arg0,void *arg1) { extern void (*data_021372d0[])(void *); void *p=M2C_FIELD(arg1,void **,12); s32 t=M2C_FIELD(p,s32 *,0x82c); if(arg0>=(u32)(M2C_FIELD(p,s32 *,0x828)-t)) { void *q=M2C_FIELD(p,void **,0x824); if(q)data_021372d0[0](q); M2C_FIELD(p,void **,0x824)=0; return;} M2C_FIELD(p,s32 *,0x82c)=t+arg0; }

void func_02024ddc(void *arg0) {
    s32 func_0201d59c(u32 *, M2C_UNK);
    M2C_UNK func_0201d67c(u32, M2C_UNK);
    M2C_UNK func_02008048(s32, void *, u32);
    void func_02023ca0(void *, void *);
    extern void *(*data_021372a4)(s32);
    void *r4;
    u32 sp0;
    u8 *temp_r0;
    s32 r6;

    r4 = M2C_FIELD(arg0, void **, 0xC);
    if (M2C_FIELD(r4, void **, 0x824) == 0) {
        if (M2C_FIELD(arg0, u32 *, 0x44) < 5) {
            return;
        }
        temp_r0 = (u8 *)func_0201d59c(&sp0, (M2C_UNK)arg0);
        sp0 = (u32)((u32)temp_r0[3] << 8) + temp_r0[4] + 5;
        if (sp0 > 0x4805) {
            M2C_FIELD(r4, u8 *, 0x455) = 9;
            return;
        }
        M2C_FIELD(r4, void **, 0x824) = (void *)data_021372a4((s32)sp0);
        if (M2C_FIELD(r4, void **, 0x824) == 0) {
            M2C_FIELD(r4, u8 *, 0x455) = 9;
            return;
        }
        M2C_FIELD(r4, s32 *, 0x828) = (s32)sp0;
        M2C_FIELD(r4, s32 *, 0x82C) = 0;
        M2C_FIELD(r4, u8 *, 0x456) = 0;
    } else {
        if (M2C_FIELD(arg0, s32 *, 0x44) == 0) {
            return;
        }
    }
    temp_r0 = (u8 *)func_0201d59c(&sp0, (M2C_UNK)arg0);
    {
        u32 remaining = (u32)(M2C_FIELD(r4, s32 *, 0x828) - M2C_FIELD(r4, s32 *, 0x82C));
        if (sp0 >= remaining) {
            sp0 = remaining;
            r6 = 1;
        } else {
            r6 = 0;
        }
    }
    func_02008048((s32)temp_r0,
                   (void *)((u8 *)M2C_FIELD(r4, void **, 0x824) + M2C_FIELD(r4, s32 *, 0x82C)),
                   (u32)sp0);
    func_0201d67c(sp0, (M2C_UNK)arg0);
    if (r6 != 0) {
        func_02023ca0(r4, M2C_FIELD(r4, void **, 0x824));
        if (M2C_FIELD(r4, u8 *, 0x456) == 0) {
            M2C_FIELD(r4, void **, 0x824) = 0;
        }
    } else {
        M2C_FIELD(r4, s32 *, 0x82C) += (s32)sp0;
    }
}

s32 func_02024f20(void *arg0) {
    void func_02024ddc(void *);
    s32 temp_r1;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0xC);
    if ((M2C_FIELD(temp_r4, s32 *, 0x824) != 0) && (M2C_FIELD(temp_r4, u8 *, 0x456) != 0)) {

    } else {
        func_02024ddc(arg0);
    }
    temp_r1 = M2C_FIELD(temp_r4, s32 *, 0x824);
    if ((temp_r1 != 0) && (M2C_FIELD(temp_r4, u8 *, 0x456) != 0)) {
        return M2C_FIELD(temp_r4, s32 *, 0x828) - M2C_FIELD(temp_r4, s32 *, 0x82C);
    }
    if ((temp_r1 == 0) && ((M2C_FIELD(arg0, u8 *, 8) != 4) || (M2C_FIELD(temp_r4, u8 *, 0x455) == 9))) {
        return -1;
    }
    return 0;
}

s32 func_02024f9c(s32 arg0, u32 arg1, s32 arg2, s32 arg3, void *arg4) {
    M2C_UNK func_02008048(s32, void *, u32);
    M2C_UNK func_0201d844(s8 *, s32, M2C_UNK, M2C_UNK, void *);
    s32 func_02023a04(void *, s8 *);
    extern void *(*data_021372a4)(s32);
    extern void (*data_021372d0[])(void *);
    void *temp_r0;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    u32 var_r9;
    s32 var_r10;
    u32 temp_r11;
    s32 temp_r0_2;
    void *sp8;
    s32 sp4;

    var_r9 = arg1;
    var_r10 = arg0;
    sp8 = M2C_FIELD(arg4, void **, 0xC);
    var_r8 = arg2;
    var_r5 = var_r9 + arg3;
    sp4 = 0;
loop_1:
    if (var_r5 > 0xB4F) {
        var_r6 = 0xB4F;
    } else {
        var_r6 = var_r5;
    }
    temp_r0 = data_021372a4(var_r6 + 0x19);
    if (temp_r0 != 0) {
        if (var_r9 >= (u32) var_r6) {
            var_r7 = var_r6;
        } else {
            var_r7 = (s32) var_r9;
        }
        temp_r11 = var_r6 - var_r7;
        func_02008048(var_r10, (s8 *)temp_r0 + 5, (u32) var_r7);
        var_r10 += var_r7;
        var_r9 -= var_r7;
        func_02008048(var_r8, (s8 *)temp_r0 + 5 + var_r7, temp_r11);
        M2C_FIELD(temp_r0, s8 *, 0) = 0x17;
        M2C_FIELD(temp_r0, s8 *, 1) = 3;
        M2C_FIELD(temp_r0, s8 *, 2) = 0;
        M2C_FIELD(temp_r0, s8 *, 3) = (s8) (var_r6 >> 8);
        var_r8 += temp_r11;
        M2C_FIELD(temp_r0, s8 *, 4) = (s8) var_r6;
        temp_r0_2 = func_02023a04(sp8, (s8 *)temp_r0);
        if ((u32)func_0201d844((s8 *)temp_r0, temp_r0_2, 0, 0, arg4) < (u32)temp_r0_2) {
            var_r6 = 0;
        }
        data_021372d0[0](temp_r0);
        var_r5 -= var_r6;
        sp4 += var_r6;
        if ((var_r5 != 0) && (var_r6 != 0)) {
            goto loop_1;
        }
    }
    return sp4;
}

void func_020250d0(void *arg0) { M2C_UNK func_0201d844(s8 *,s32,s32,s32,void *); s32 func_02023a04(void *,s8 *); s8 a[28]; void *p=M2C_FIELD(arg0,void **,12); if(M2C_FIELD(p,u8 *,0x455)==8) { a[0]=21;a[1]=3;a[2]=0;a[3]=0;a[4]=2;a[5]=1;a[6]=0; func_0201d844(a,func_02023a04(p,a),0,0,arg0); } M2C_FIELD(p,u8 *,0x455)=0; }

void func_02025150(void *arg0) { extern void (*data_021372d0[])(void *); void *p=M2C_FIELD(arg0,void **,12); void *q; M2C_FIELD(p,u8 *,0x455)=0; q=M2C_FIELD(p,void **,0x824); if(q)data_021372d0[0](q); M2C_FIELD(p,void **,0x824)=0; }

void func_02025188(s8 arg0) {
    M2C_UNK func_02000b9c(s32);
    extern M2C_UNK data_0212dca4;
    void *temp_r0;

    func_02000b9c(0x02000C1C);
    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s8 *, 9) = arg0;
    }
}
