/* 18 functions from 0x02024260 to 0x020251B8 (main), found by ds-decomp. */
#include "common.h"

extern void *(*gAlloc)(s32);
extern void (*gFree[])(void *);

s32 func_02024260(void *arg0) {
    u32 func_02022070(void);
    void GenerateRandomBytes(void *, s32);
    M2C_UNK MI_CpuCopy8(s32, void *, u32);
    void func_02023c74(void *, void *, s32);
    M2C_UNK func_0201d844(s8 *, s32, s32, s32, void *);
    extern void *(*gAlloc)(s32);
    extern void (*gFree[])(void *);
    extern s32 data_02138cc0[2];

    register void *q, *buf;
    register u8 *cur;
    register void *node;
    register s32 nodeSize;
    register void *r9;
    u32 rnd;
    s32 h;
    u32 r3;
    s32 t2, t1;
    s32 total, payload;

    r9 = arg0;
    q = M2C_FIELD(r9, void **, 0xC);
    node = M2C_FIELD(q, void **, 0x820);
    nodeSize = node ? M2C_FIELD(node, s32 *, 0x0) : 0;

    rnd = func_02022070();
    M2C_FIELD(q, u8 *, 0x54) = (u8)(rnd >> 24);
    M2C_FIELD(q, u8 *, 0x55) = (u8)(rnd >> 16);
    M2C_FIELD(q, u8 *, 0x56) = (u8)(rnd >> 8);
    M2C_FIELD(q, u8 *, 0x57) = (u8)rnd;

    GenerateRandomBytes((u8 *)q + 0x58, 0x1C);

    buf = gAlloc(nodeSize + 0x9D);
    if (buf == 0) {
        M2C_FIELD(q, u8 *, 0x455) = 9;
        return 1;
    }

    M2C_FIELD(buf, u8 *, 5) = 2;
    M2C_FIELD(buf, u8 *, 6) = 0;
    M2C_FIELD(buf, u8 *, 7) = 0;
    M2C_FIELD(buf, u8 *, 8) = 0x46;
    M2C_FIELD(buf, u8 *, 9) = 3;
    M2C_FIELD(buf, u8 *, 0xA) = 0;
    MI_CpuCopy8((s32)((u8 *)q + 0x54), (void *)((u8 *)buf + 0xB), 0x20);
    M2C_FIELD(buf, u8 *, 0x2B) = 0x20;

    if (M2C_FIELD(q, u8 *, 0x30) != 0) {
        MI_CpuCopy8((s32)((u8 *)q + 0x74), (void *)((u8 *)buf + 0x2C), 0x20);
        M2C_FIELD(q, u8 *, 0x31) = 1;
        cur = (u8 *)buf + 0x4C;
    } else {
        GenerateRandomBytes((u8 *)buf + 0x2C, 0x1C);
        cur = (u8 *)buf + 0x4C;
        r3 = data_02138cc0[1];
        M2C_FIELD(buf, u8 *, 0x48) = (u8)(r3 >> 24);
        M2C_FIELD(buf, u8 *, 0x49) = (u8)(r3 >> 16);
        M2C_FIELD(buf, u8 *, 0x4A) = (u8)(r3 >> 8);
        M2C_FIELD(buf, u8 *, 0x4B) = (u8)r3;
        MI_CpuCopy8((s32)(cur - 0x20), (void *)((u8 *)q + 0x74), 0x20);
        t2 = data_02138cc0[1];
        M2C_FIELD(q, u8 *, 0x31) = 0;
        data_02138cc0[1] = t2 + 1;
    }

    h = M2C_FIELD(q, u16 *, 0x32);
    M2C_FIELD(cur, u8 *, 0) = (u8)(h >> 8);
    h = M2C_FIELD(q, u16 *, 0x32);
    M2C_FIELD(cur, u8 *, 1) = (u8)h;
    M2C_FIELD(cur, u8 *, 2) = 0;

    cur += 3;
    if (M2C_FIELD(q, u8 *, 0x31) == 0) {
        if (nodeSize != 0) {
            t2 = nodeSize + 6;
            M2C_FIELD(cur, u8 *, 0) = 0x0B;
            t1 = nodeSize + 3;
            M2C_FIELD(cur, u8 *, 1) = (u8)(t2 >> 16);
            M2C_FIELD(cur, u8 *, 2) = (u8)(t2 >> 8);
            M2C_FIELD(cur, u8 *, 3) = (u8)t2;
            M2C_FIELD(cur, u8 *, 4) = (u8)(t1 >> 16);
            M2C_FIELD(cur, u8 *, 5) = (u8)(t1 >> 8);
            M2C_FIELD(cur, u8 *, 6) = (u8)t1;
            M2C_FIELD(cur, u8 *, 7) = (u8)(nodeSize >> 16);
            M2C_FIELD(cur, u8 *, 8) = (u8)(nodeSize >> 8);
            M2C_FIELD(cur, u8 *, 9) = (u8)nodeSize;
            cur += 10;
            MI_CpuCopy8((s32)M2C_FIELD(node, void **, 4), (void *)cur, (u32)nodeSize);
            cur += nodeSize;
        }
        M2C_FIELD(cur, u8 *, 0) = 0x0E;
        M2C_FIELD(cur, u8 *, 1) = 0;
        M2C_FIELD(cur, u8 *, 2) = 0;
        M2C_FIELD(cur, u8 *, 3) = 0;
        cur += 4;
    }

    total = (s32)((u8 *)cur - (u8 *)buf);
    payload = total - 5;
    M2C_FIELD(buf, u8 *, 0) = 0x16;
    M2C_FIELD(buf, u8 *, 1) = 3;
    M2C_FIELD(buf, u8 *, 2) = 0;
    M2C_FIELD(buf, u8 *, 3) = (u8)(payload >> 8);
    M2C_FIELD(buf, u8 *, 4) = (u8)payload;
    func_02023c74(q, (void *)((u8 *)buf + 5), payload);
    func_0201d844((s8 *)buf, payload + 5, 0, 0, arg0);
    gFree[0](buf);

    return M2C_FIELD(q, u8 *, 0x31);
}

void func_020244c0(void *arg0) {
    void func_02023c74(void *, void *, s32);
    void *temp_r5;
    void *temp_r4;

    temp_r5 = M2C_FIELD(arg0, void **, 0xC);
    temp_r4 = gAlloc(0x83);
    if (temp_r4 == NULL) {
        M2C_FIELD(temp_r5, u8 *, 0x455) = 9;
        return;
    }
    M2C_FIELD(temp_r4, u8 *, 0) = 0x14;
    M2C_FIELD(temp_r4, u8 *, 1) = 3;
    M2C_FIELD(temp_r4, u8 *, 2) = 0;
    M2C_FIELD(temp_r4, u8 *, 3) = 0;
    M2C_FIELD(temp_r4, u8 *, 4) = 1;
    M2C_FIELD(temp_r4, u8 *, 5) = 1;
    func_02007f8c(temp_r5 + 0x1CC, 0, 8);
    M2C_FIELD(temp_r4, u8 *, 6) = 0x16;
    M2C_FIELD(temp_r4, u8 *, 7) = 3;
    M2C_FIELD(temp_r4, u8 *, 8) = 0;
    M2C_FIELD(temp_r4, u8 *, 9) = 0;
    M2C_FIELD(temp_r4, u8 *, 0xA) = 0x28;
    M2C_FIELD(temp_r4, u8 *, 0xB) = 0x14;
    M2C_FIELD(temp_r4, u8 *, 0xC) = 0;
    M2C_FIELD(temp_r4, u8 *, 0xD) = 0;
    M2C_FIELD(temp_r4, u8 *, 0xE) = 0x24;
    MI_CpuCopy8(temp_r5 + 0x3A4, temp_r5 + 0x3FC, 0x58);
    func_02023520(temp_r5, temp_r4 + 0xF, 0);
    MI_CpuCopy8(temp_r5 + 0x3FC, temp_r5 + 0x3A4, 0x58);
    MI_CpuCopy8(temp_r5 + 0x2EC, temp_r5 + 0x348, 0x5C);
    func_020235fc(temp_r5, temp_r4 + 0x1F, 0);
    MI_CpuCopy8(temp_r5 + 0x348, temp_r5 + 0x2EC, 0x5C);
    func_02023c74(temp_r5, temp_r4 + 0xB, 0x28);
    func_0201d844(temp_r4, func_02023a04(temp_r5, temp_r4 + 0x6) + 6, 0, 0, arg0);
    gFree[0](temp_r4);
}

s32 func_02024a6c(void *p){s32 func_02023f20(void *);if(func_02023f20(p)!=7)return 1;return func_02023f20(p)!=6;}

s32 func_02024a9c(void *p){s32 func_02023f20(void *);s32 func_02024260(void *);void func_02023318(void *);void func_020244c0(void *);if(func_02023f20(p)!=1)return 1;if(func_02024260(p)){func_02023318(M2C_FIELD(p,void **,12));func_020244c0(p);if(func_02024a6c(p))return 1;}else{if(func_02023f20(p)!=5)return 1;if(func_02024a6c(p))return 1;func_020244c0(p);}return 0;}

#pragma scheduling off
void func_02024b24(void *p) {
void func_0201d25c(void *); void func_0201d434(void *); void func_02025fc0(void *); void func_02025700(void *);
void *q = M2C_FIELD(p, void **, 12);
while (1) {
func_0201d25c(p);
M2C_FIELD(q,u8 *,0x455)=0; M2C_FIELD(q,s32 *,0x1d4)=0; M2C_FIELD(q,u8 *,0x454)=1;
func_02025fc0((u8 *)q+0x2ec);func_02025700((u8 *)q+0x3a4);
if (!func_02024a9c(p)) {M2C_FIELD(q,u8 *,0x455)=8; return;}
func_0201d434(p); M2C_FIELD(p,u16 *,0x18)=M2C_FIELD(p,u16 *,0x1a); M2C_FIELD(p,s32 *,0x1c)=M2C_FIELD(p,s32 *,0x20);
}
}
#pragma scheduling reset
s32 func_02024b94(void *arg0) {
 void func_02021f1c(void *,s32,u16); void func_020232b8(void *);void func_02023318(void *);s32 func_02023f20(void *);void func_020244c0(void *);void TlsSendHandshake(void *);s32 func_02024a6c(void *);
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
 TlsSendHandshake(arg0);func_020232b8(p);
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
    extern void (*gFree[])(void *);
    void *r4;
    void *ip;

    r4 = M2C_FIELD(arg1, void **, 0xC);
    ip = M2C_FIELD(r4, void **, 0x824);
    if (ip != 0 && M2C_FIELD(r4, u8 *, 0x456) == 0) {
        s32 r3 = M2C_FIELD(r4, s32 *, 0x82C);
        if (func_02023c08((s32)ip + r3, (u32)(M2C_FIELD(r4, s32 *, 0x828) - r3), arg1) != 0) {
            gFree[0](M2C_FIELD(r4, void **, 0x824));
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

void func_02024d8c(u32 arg0, void *arg1) {
    extern void (*gFree[])(void *);
    u8 *p = M2C_FIELD(arg1, u8 **, 12);
    u32 rem = M2C_FIELD(p, u32 *, 0x828) - M2C_FIELD(p, u32 *, 0x82c);
    if (arg0 >= rem) {
        void *q = M2C_FIELD(p, void **, 0x824);
        if (q) gFree[0](q);
        M2C_FIELD(p, void **, 0x824) = 0;
        return;
    }
    M2C_FIELD(p, u32 *, 0x82c) += arg0;
}

void func_02024ddc(void *arg0) {
    s32 func_0201d59c(u32 *, M2C_UNK);
    M2C_UNK func_0201d67c(u32, M2C_UNK);
    M2C_UNK MI_CpuCopy8(s32, void *, u32);
    void func_02023ca0(void *, void *);
    extern void *(*gAlloc)(s32);
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
        M2C_FIELD(r4, void **, 0x824) = (void *)gAlloc((s32)sp0);
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
    MI_CpuCopy8((s32)temp_r0,
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
    M2C_UNK MI_CpuCopy8(s32, void *, u32);
    M2C_UNK func_0201d844(s8 *, s32, M2C_UNK, M2C_UNK, void *);
    s32 func_02023a04(void *, s8 *);
    extern void *(*gAlloc)(s32);
    extern void (*gFree[])(void *);
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
    temp_r0 = gAlloc(var_r6 + 0x19);
    if (temp_r0 != 0) {
        if (var_r9 >= (u32) var_r6) {
            var_r7 = var_r6;
        } else {
            var_r7 = (s32) var_r9;
        }
        temp_r11 = var_r6 - var_r7;
        MI_CpuCopy8(var_r10, (s8 *)temp_r0 + 5, (u32) var_r7);
        var_r10 += var_r7;
        var_r9 -= var_r7;
        MI_CpuCopy8(var_r8, (s8 *)temp_r0 + 5 + var_r7, temp_r11);
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
        gFree[0](temp_r0);
        var_r5 -= var_r6;
        sp4 += var_r6;
        if ((var_r5 != 0) && (var_r6 != 0)) {
            goto loop_1;
        }
    }
    return sp4;
}

void func_020250d0(void *arg0) { M2C_UNK func_0201d844(s8 *,s32,s32,s32,void *); s32 func_02023a04(void *,s8 *); s8 a[28]; void *p=M2C_FIELD(arg0,void **,12); if(M2C_FIELD(p,u8 *,0x455)==8) { a[0]=21;a[1]=3;a[2]=0;a[3]=0;a[4]=2;a[5]=1;a[6]=0; func_0201d844(a,func_02023a04(p,a),0,0,arg0); } M2C_FIELD(p,u8 *,0x455)=0; }

void func_02025150(void *arg0) { extern void (*gFree[])(void *); void *p=M2C_FIELD(arg0,void **,12); void *q; M2C_FIELD(p,u8 *,0x455)=0; q=M2C_FIELD(p,void **,0x824); if(q)gFree[0](q); M2C_FIELD(p,void **,0x824)=0; }

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
#include "common.h"
#pragma opt_common_subs off
s32 func_02024618(void *p){

u32 func_02022070(void);
void GenerateRandomBytes(void *,s32);
M2C_UNK MI_CpuCopy8(s32,void *,u32);
void func_02021e7c(void *,s32,u16);
M2C_UNK func_0201d844(s8 *,s32,s32,s32,void *);
void func_02023c74(void *,void *,s32);
extern u16 data_020faffc[];

u8 *q=M2C_FIELD(p,u8 **,12),*buf,*cursor;
u32 rnd,i;
s32 len,n;

buf=gAlloc(152);
if(!buf){q[0x455]=9;
return 9;
}
buf[9]=3;
buf[10]=0;
rnd=func_02022070();
q[0x34]=rnd>>24;
q[0x35]=rnd>>16;
q[0x36]=rnd>>8;
q[0x37]=rnd;

GenerateRandomBytes(q+0x38,28);
MI_CpuCopy8((s32)(q+0x34),buf+11,32);
func_02021e7c(q,M2C_FIELD(p,s32 *,0x1c),M2C_FIELD(p,u16 *,0x18));

if(q[0x30]){buf[0x2b]=32;MI_CpuCopy8((s32)(q+0x74),buf+0x2c,32);cursor=buf+0x4c;}
else{buf[0x2b]=0;cursor=buf+0x2c;}
cursor[0]=0;
cursor[1]=4;
cursor+=2;

for(i=0;
i<2;
i++){cursor[0]=data_020faffc[i]>>8;
cursor[1]=data_020faffc[i];
cursor+=2;
}
cursor[0]=1;
cursor[1]=0;
cursor+=2;
len=cursor-buf-5;
n=len-4;

buf[0]=22;
buf[1]=3;
buf[2]=0;
buf[3]=len>>8;
buf[4]=len;
buf[5]=1;
buf[6]=n>>16;
buf[7]=n>>8;
buf[8]=n;

func_0201d844(buf,len+5,0,0,p);
func_02023c74(q,buf+5,len);
gFree[0](buf);

}

#pragma push
#pragma opt_strength_reduction off
/* Builds and sends a TLS handshake record: a fresh random challenge plus the
 * connection's key material run through the big-number transform, framed with the
 * 0x16 handshake header. Frees its temporary buffers. */
void TlsSendHandshake(void *arg0) {
    s32 MI_CpuCopy8(s32, void *, u32);
    M2C_UNK func_0201d844(s8 *, s32, s32, s32, void *);
    s32 func_020220b8();
    M2C_UNK func_02022104(s32);
    void func_02023c74(void *, void *, s32);
    void GenerateRandomBytes(void *, s32);
    M2C_UNK func_020269dc(M2C_UNK *, void *, void *, s32, void *);
    M2C_UNK func_02026ff0(void *, M2C_UNK *, s32, s32);
    extern M2C_UNK data_020ea750;
    extern void *(*gAlloc)(s32);
    void *conn;
    u8 *work;
    void *chunkC;
    s32 wordCount;
    u8 *buf;
    s32 byteLen;
    void *chunkB;
    void *savedChunkA;
    u8 *out;
    s32 resource;
    s32 wordIndex;
    s32 wordOffset;
    u16 word;
    u32 doubleLen;
    void *chunkA;
    void *p;

    conn = M2C_FIELD(arg0, void **, 0xC);
    if (M2C_FIELD(conn, u8 *, 0x5AC) != 0) {
        func_0201d844((s8 *)&data_020ea750, 7, 0, 0, arg0);
    }
    M2C_FIELD(conn, s8 *, 0) = 3;
    M2C_FIELD(conn, s8 *, 1) = 0;
    GenerateRandomBytes(conn + 2, 0x2E);
    byteLen = M2C_FIELD(conn, s32 *, 0x594);
    doubleLen = byteLen * 2;
    wordCount = ((s32)doubleLen)/2;
    buf = gAlloc(byteLen);
    if (buf == NULL) {
        M2C_FIELD(conn, s8 *, 0x455) = 9;
        return;
    }
    M2C_FIELD(buf, s8 *, 0) = 0;
    M2C_FIELD(buf, s8 *, 1) = 2;
    GenerateRandomBytes(buf + 2, byteLen - 0x33);
    *(buf + (byteLen - 0x31)) = 0;
    MI_CpuCopy8(conn, (buf + byteLen) - 0x30, 0x30);
    work = gAlloc(wordCount * 8);
    if (work == NULL) {
        gFree[0](buf);
        M2C_FIELD(conn, s8 *, 0x455) = 9;
        return;
    }
    chunkA = work + (wordCount * 2);
    chunkB = chunkA + (wordCount * 2);
    savedChunkA = chunkA;
    chunkC = chunkB + (wordCount * 2);
    func_02026ff0(chunkA, buf, byteLen, wordCount);
    func_02026ff0(chunkB, conn + 0x598, M2C_FIELD(conn, s32 *, 0x5A0), wordCount);
    func_02026ff0(chunkC, conn + 0x494, byteLen, wordCount);
    resource = func_020220b8();
    func_020269dc(work, savedChunkA, chunkB, wordCount, chunkC);
    func_02022104(resource);
    out = gAlloc(byteLen + 0x49);
    if (out == NULL) {
        gFree[0](buf);
        gFree[0](work);
        M2C_FIELD(conn, s8 *, 0x455) = 9;
        return;
    }
    M2C_FIELD(out, s8 *, 0) = 0x16;
    M2C_FIELD(out, s8 *, 1) = 3;
    M2C_FIELD(out, s8 *, 2) = 0;
    M2C_FIELD(out, s8 *, 3) = (s8) ((byteLen+4) >> 8);
    M2C_FIELD(out, s8 *, 4) = byteLen+4;
    M2C_FIELD(out, s8 *, 5) = 0x10;
    M2C_FIELD(out, s8 *, 6) = (s8) (byteLen >> 0x10);
    M2C_FIELD(out, s8 *, 7) = (s8) (byteLen >> 8);
    M2C_FIELD(out, s8 *, 8) = (s8) byteLen;
    p = out + 9;
    if (byteLen & 1) {
        p = out + 0xA;
        M2C_FIELD(out, s8 *, 9) = (s8)((u16*)work)[byteLen/2];
    }
    wordIndex = ((s32) (byteLen + ((u32) byteLen >> 0x1F)) >> 1) - 1;
    if (wordIndex >= 0) {
        do {
            wordOffset = wordIndex * 2;
            word = M2C_FIELD(work,u16 *,wordOffset);
            wordIndex -= 1;
            M2C_FIELD(p, s8 *, 0) = (s8) ((s32) word >> 8);
            M2C_FIELD(p, s8 *, 1) = (s8) M2C_FIELD(work,u16 *,wordOffset);
            p += 2;
        } while (wordIndex >= 0);
    }
    func_0201d844((s8 *)out, byteLen + 9, 0, 0, arg0);
    func_02023c74(conn, out + 5, byteLen + 4);
    gFree[0](out);
    gFree[0](work);
    gFree[0](buf);
}
#pragma pop
