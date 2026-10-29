/* 20 functions from 0x0207A3B0 to 0x0207B2F0 (main), found by ds-decomp. */
#include "common.h"

int func_0207a3b0(int a, int b, unsigned short c, unsigned char d, int e, int f, int g, int h, int i, int j, int k) {
    (void)a;(void)b;(void)c;(void)d;(void)e;(void)f;(void)g;(void)h;(void)i;(void)j;(void)k;
    return 0;
}

void func_0207a61c(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, u16 arg4, u8 arg5, u8 arg6) {
    M2C_UNK func_0207a3b0(s32, M2C_UNK, u16, u8, s32, s32, s32, s32, s32, s32, s32);
    func_0207a3b0(arg0 + (arg1 * 2) + (arg2 << 6), arg3, arg4, arg5, (s32) arg6, 0, 0, 0, 0, 0, 0);
}

void func_0207a668(void) {

}

void func_0207a66c(s32 arg0, s32 arg1) {
 extern void *gCurrentMap;
 extern void *gCur3DSpriteEngine;
 void *temp_r2;
 void *temp_r4;
 temp_r4 = M2C_FIELD(gCurrentMap,void **,0);
 temp_r2 = (u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + (((u32)((arg0 - M2C_FIELD(temp_r4,u16 *,0x5150)) << 28) >> 27) * 2) + (((u32)((arg1 - M2C_FIELD(temp_r4,u16 *,0x5152)) << 28) >> 22) * 2);
 if (M2C_FIELD(M2C_FIELD((u8 *)temp_r4 + arg1*4,s8 **,0x52e8),s8 *,arg0) < 0) {
 M2C_FIELD(temp_r2,u16 *,0)=0;
 M2C_FIELD(temp_r2,u16 *,2)=0;
 M2C_FIELD(temp_r2,u16 *,0x40)=0;
 M2C_FIELD(temp_r2,u16 *,0x42)=0;
 return;
 }
 M2C_FIELD(temp_r2,u16 *,0)=0x124;
 M2C_FIELD(temp_r2,u16 *,2)=0x125;
 M2C_FIELD(temp_r2,u16 *,0x40)=0x126;
 M2C_FIELD(temp_r2,u16 *,0x42)=0x127;
}

void func_0207a710(void *arg0) {
    extern void *gCurrentMap;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), s32 *, 0x5C);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(func_01ffa3dc(temp_r0, arg0), s16 *, 0x6C) = (s16) M2C_FIELD(arg0, s16 *, 0x6C);
}

void func_0207a748(s16 arg0) {
    extern M2C_UNK data_02100bb0;
    M2C_FIELD(func_01ffa3dc(&data_02100bb0, 7), s16 *, 0x6C) = arg0;
}

void func_0207a768(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02100bb0;
    func_01ffa9e4(&data_02100bb0);
}

void func_0207a77c(s32 arg0) {
 extern void *gCurrentMap;
 void (*temp_r1)(s32);
 temp_r1 = M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(s32),0x2c);
 if (temp_r1 == 0) return;
 temp_r1(arg0);
}

void func_0207a7a4(s32 arg0, s32 arg1) {
    extern void *gCurrentMap;
    extern void *data_02101e88;
    extern void *data_02101e84;
    extern u8 data_02144cdc;
    extern u8 data_02100bac;

    M2C_UNK func_0207d0b8(void);
    M2C_UNK func_0207d0d4(void);

    s32 r5 = func_0207d0b8();
    s32 r0v = func_0207d0d4();
    void *r9 = M2C_FIELD(gCurrentMap, void **, 0);
    void *r8p = M2C_FIELD(data_02101e88, void **, 0);
    s32 r12f = 0;
    u32 lr = 0;
    s32 r6f = 0;
    s32 r7f = 0;
    u16 r2v = M2C_FIELD(r8p, u16 *, 0);
    u16 r3v = M2C_FIELD(r8p, u16 *, 2);
    void *base9 = M2C_FIELD(r9, void **, 0);
    void *p5200 = (u8 *)base9 + 0x5200;
    s16 valC2 = M2C_FIELD(p5200, s16 *, 0xc2);
    s32 stack0 = valC2;
    s16 valC4 = M2C_FIELD(p5200, s16 *, 0xc4);

    if (arg0 != 0) {
        u8 b;
        void *base, *q, *base2, *q2, *base3, *q3, *base4, *q4;
        u8 st, st2, st3, st4;
        b = M2C_FIELD(r8p, u8 *, 0x12);
        if (b != 0) {
            data_02144cdc = 1;
        } else {
            void *g = data_02101e84;
            u8 t = data_02100bac;
            u16 h = M2C_FIELD(g, u16 *, 0x6);
            if (h & t) {
                data_02144cdc = 0;
            }
        }
        if (data_02144cdc != 0) {
            u8 v = M2C_FIELD(r8p, u8 *, 0x12);
            if (v != 0) {
                if (r2v < 0xc) r12f = 1;
                if (r3v < 0xc) r6f = 1;
                if (r2v >= 0xf4) lr = 1;
                if (r3v >= 0xb4) r7f = 1;
            }
        } else {
            s16 a4a, a48;
            s32 a, c;
            void *base5 = M2C_FIELD(r9, void **, 0);
            void *q5 = (u8 *)base5 + 0x5100;
            a4a = M2C_FIELD(q5, s16 *, 0x4a);
            a48 = M2C_FIELD(q5, s16 *, 0x48);
            a = valC4 - (a4a >> 4);
            c = stack0 - (a48 >> 4);
            if (c < 1) r12f = 1;
            if (a < 1) r6f = 1;
            if (c > r5 - 2) lr = 1;
            if (a > r0v - 2) r7f = 1;
        }
        base = M2C_FIELD(r9, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if ((st & 0x3) == 0) {
            if (r12f) { st |= 0x2; M2C_FIELD(q, u8 *, 0x154) = st; }
            if (lr) {
                base2 = M2C_FIELD(gCurrentMap, void **, 0);
                base2 = M2C_FIELD(base2, void **, 0);
                q2 = (u8 *)base2 + 0x5000;
                st2 = M2C_FIELD(q2, u8 *, 0x154);
                st2 |= 0x1;
                M2C_FIELD(q2, u8 *, 0x154) = st2;
            }
        }
        base3 = M2C_FIELD(gCurrentMap, void **, 0);
        base3 = M2C_FIELD(base3, void **, 0);
        q3 = (u8 *)base3 + 0x5000;
        st3 = M2C_FIELD(q3, u8 *, 0x154);
        if ((st3 & 0xc) == 0) {
            if (r6f) { st3 |= 0x4; M2C_FIELD(q3, u8 *, 0x154) = st3; }
            if (r7f) {
                base4 = M2C_FIELD(gCurrentMap, void **, 0);
                base4 = M2C_FIELD(base4, void **, 0);
                q4 = (u8 *)base4 + 0x5000;
                st4 = M2C_FIELD(q4, u8 *, 0x154);
                st4 |= 0x8;
                M2C_FIELD(q4, u8 *, 0x154) = st4;
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        u16 a;
        s16 bb, bb2;
        s32 t;
        h = M2C_FIELD(gCurrentMap, void **, 0);
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x1) {
            b = M2C_FIELD(h, void **, 0);
            qp = (u8 *)b + 0x5100;
            a = M2C_FIELD(qp, u16 *, 0x44);
            bb = M2C_FIELD(qp, s16 *, 0x48);
            t = a - (bb >> 4);
            if (t <= r5) {
                st ^= 0x1;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x48) = (s16)(bb + arg1);
            }
            h2 = M2C_FIELD(gCurrentMap, void **, 0);
            base2 = M2C_FIELD(h2, void **, 0);
            qp2 = (u8 *)base2 + 0x5100;
            bb2 = M2C_FIELD(qp2, s16 *, 0x48);
            if ((bb2 & 0xf) == 0) {
                q2 = (u8 *)base2 + 0x5000;
                st2 = M2C_FIELD(q2, u8 *, 0x154);
                st2 ^= 0x1;
                M2C_FIELD(q2, u8 *, 0x154) = st2;
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        s16 bb, bb2;
        h = M2C_FIELD(gCurrentMap, void **, 0);
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x2) {
            b = M2C_FIELD(h, void **, 0);
            qp = (u8 *)b + 0x5100;
            bb = M2C_FIELD(qp, s16 *, 0x48);
            if (bb <= 0) {
                st ^= 0x2;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x48) = (s16)(bb - arg1);
            }
            h2 = M2C_FIELD(gCurrentMap, void **, 0);
            base2 = M2C_FIELD(h2, void **, 0);
            qp2 = (u8 *)base2 + 0x5100;
            bb2 = M2C_FIELD(qp2, s16 *, 0x48);
            if ((bb2 & 0xf) == 0) {
                q2 = (u8 *)base2 + 0x5000;
                st2 = M2C_FIELD(q2, u8 *, 0x154);
                st2 ^= 0x2;
                M2C_FIELD(q2, u8 *, 0x154) = st2;
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        s16 bb, bb2;
        h = M2C_FIELD(gCurrentMap, void **, 0);
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x4) {
            b = M2C_FIELD(h, void **, 0);
            qp = (u8 *)b + 0x5100;
            bb = M2C_FIELD(qp, s16 *, 0x4a);
            if (bb <= 0) {
                st ^= 0x4;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x4a) = (s16)(bb - arg1);
            }
            h2 = M2C_FIELD(gCurrentMap, void **, 0);
            base2 = M2C_FIELD(h2, void **, 0);
            qp2 = (u8 *)base2 + 0x5100;
            bb2 = M2C_FIELD(qp2, s16 *, 0x4a);
            if ((bb2 & 0xf) == 0) {
                q2 = (u8 *)base2 + 0x5000;
                st2 = M2C_FIELD(q2, u8 *, 0x154);
                st2 ^= 0x4;
                M2C_FIELD(q2, u8 *, 0x154) = st2;
            }
        }
    }

    {
        void *h, *base, *q, *b, *qp, *h2, *base2, *qp2, *q2;
        u8 st, st2;
        u16 a;
        s16 bb, bb2;
        s32 t;
        h = M2C_FIELD(gCurrentMap, void **, 0);
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x5000;
        st = M2C_FIELD(q, u8 *, 0x154);
        if (st & 0x8) {
            b = M2C_FIELD(h, void **, 0);
            qp = (u8 *)b + 0x5100;
            a = M2C_FIELD(qp, u16 *, 0x46);
            bb = M2C_FIELD(qp, s16 *, 0x4a);
            t = a - (bb >> 4);
            if (t <= r0v) {
                st ^= 0x8;
                M2C_FIELD(q, u8 *, 0x154) = st;
            } else {
                M2C_FIELD(qp, s16 *, 0x4a) = (s16)(bb + arg1);
            }
            h2 = M2C_FIELD(gCurrentMap, void **, 0);
            base2 = M2C_FIELD(h2, void **, 0);
            qp2 = (u8 *)base2 + 0x5100;
            bb2 = M2C_FIELD(qp2, s16 *, 0x4a);
            if ((bb2 & 0xf) == 0) {
                q2 = (u8 *)base2 + 0x5000;
                st2 = M2C_FIELD(q2, u8 *, 0x154);
                st2 ^= 0x8;
                M2C_FIELD(q2, u8 *, 0x154) = st2;
            }
        }
    }

    {
        void *h, *base, *q;
        void *fp;
        void (*cb)(void);
        h = M2C_FIELD(gCurrentMap, void **, 0);
        base = M2C_FIELD(h, void **, 0);
        q = (u8 *)base + 0x4;
        fp = M2C_FIELD(q, void **, 0);
        cb = (void (*)(void))M2C_FIELD(fp, void (**)(void), 0x1c);
        if (cb != 0) {
            cb();
        }
    }
}

void func_0207ab24(s32 arg0, s32 arg1) {
 M2C_UNK func_0207ab84(s32,s32,u8);
 M2C_UNK func_020cfd28(void);
 M2C_UNK func_020cf2c8(void);
 M2C_UNK func_020d2470(void);
 extern void *gCurrentMap;
 s32 temp_ip;
 s32 temp_r3_2;
 u8 *temp_lr;
 void *temp_r3;
 temp_r3 = M2C_FIELD(gCurrentMap,void **,0);
 temp_lr = (u8 *)temp_r3 + 0x1420;
 temp_ip = arg0 + M2C_FIELD((u8 *)temp_r3 + arg1*2,u16 *,0x3758);
 temp_r3_2 = M2C_FIELD(temp_r3,u16 *,0x52a6) + (temp_lr[temp_ip] & 0x1f);
 temp_lr[temp_ip] = temp_r3_2;
 func_0207ab84(arg0,arg1,(u8)(temp_r3_2 & 0xe0));
 func_020cfd28();
 func_020cf2c8();
 func_020d2470();
}

s32 func_0207ab84(s32 arg0, s32 arg1, u8 arg2) {
extern u16 data_0211fafc[];
extern void *data_027e0058;
s32 i=0;
s32 base;
u16 value;
void *p;
if(data_0211fafc[0] != 0xffff) {
p=M2C_FIELD(data_027e0058,void **,0);
value=M2C_FIELD((u8 *)p+2*(arg0+M2C_FIELD((u8 *)p+arg1*2,u16 *,0x3758)),u16 *,0xa10);
do { if(data_0211fafc[i]==value) break; i++; } while(data_0211fafc[i] != 0xffff);
}
p=M2C_FIELD(data_027e0058,void **,0);
base=(i/5)*5;
M2C_FIELD((u8 *)p+2*(arg0+M2C_FIELD((u8 *)p+arg1*2,u16 *,0x3758)),u16 *,0xa10)=data_0211fafc[base+(arg2>>5)];
return (s16)base;
}

s32 func_0207ac54(s32 arg0,s32 arg1,s32 arg2){
extern u16 data_0211fafc[];
extern void *gCurrentMap;
s32 i=0; s32 base; u16 value; void *p;
if(data_0211fafc[0]!=0xffff){
p=M2C_FIELD(gCurrentMap,void **,0);
value=M2C_FIELD((u8*)p+2*(arg0+M2C_FIELD((u8*)p+arg1*2,u16 *,0x3758)),u16 *,0xa10);
do{if(value==data_0211fafc[i])break;i++;}while(data_0211fafc[i]!=0xffff);
}
base=(i/5)*5;
if(base<5){
p=M2C_FIELD(gCurrentMap,void **,0);
M2C_FIELD((u8*)p+2*(arg0+M2C_FIELD((u8*)p+arg1*2,u16 *,0x3758)),u16 *,0xa10)=data_0211fafc[base+10+(arg2>>5)];
}return (s16)base;
}

/* Update each active entity (1..4) according to the state nibble packed in `value`. */
void func_0207ad30(s32 value) {
    s32 func_020d1980(s32);
    s32 func_020d1a74(s32);
    s32 func_020a2be0(s32);
    extern void *gCurrentMap;

    s32 state = (value >> 2) & 15;
    s32 i;
    void (*callback)(s32, s32);

    for (i = 1; i < 5; i++) {
        if (!func_020d1980(i)) {
            continue;
        }
        if (func_020d1a74(i) && state >= 0) {
            callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
            if (callback) {
                callback(i, state);
            }
        } else if (func_020a2be0(i)) {
            switch (state) {
            case 15: {
                callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
                if (callback) {
                    callback(i, 7);
                }
                break;
            }
            default: {
                callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
                if (callback) {
                    callback(i, 0);
                }
                break;
            }
            }
        } else {
            callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(s32, s32), 0x24);
            if (callback) {
                callback(i, 0);
            }
        }
    }
}

void func_0207ae2c(void *arg0) {
    void *func_020e34bc(s32);
    extern void *gCurrentMap;

    void *map;
    s32 selX;
    s32 selY;
    void *alloc;
    s32 rows;
    s32 cols;
    s32 i;
    s32 j;
    s32 r7;
    s32 r12;
    s32 r2;

    map = M2C_FIELD(gCurrentMap, void **, 0);
    selX = M2C_FIELD((u8 *)map + 0x52d0, u8 *, 1);
    selY = M2C_FIELD((u8 *)map + 0x52d0, u8 *, 2);

    alloc = func_020e34bc(0x660);
    M2C_FIELD(arg0, void **, 0x54) = alloc;
    M2C_FIELD(arg0, s16 *, 0x6c) = 0;
    M2C_FIELD(arg0, s16 *, 0x6e) = 0;

    rows = M2C_FIELD((u8 *)map + 0x5100, u16 *, 0x46);
    if (rows <= 0) {
        return;
    }
    cols = M2C_FIELD((u8 *)map + 0x5100, u16 *, 0x44);
    if (cols <= 0) {
        return;
    }

    for (i = 0; i < rows; i++) {
        r7 = selX << 4;
        r12 = selY << 4;
        r2 = (i - selY) * 2;

        for (j = 0; j < cols; j++) {
            signed char gridByte = M2C_FIELD(M2C_FIELD((u8 *)map + i * 4 + 0x5000, void **, 0x2e8), s8 *, j);
            if (gridByte < 0) {
                continue;
            }
            if (j == selX && i == selY) {
                continue;
            }
            if (!(gridByte & 0x40)) {
                continue;
            }

            M2C_FIELD(alloc, s16 *, M2C_FIELD(arg0, u16 *, 0x6c) * 8) = (s16)r7;
            M2C_FIELD(alloc, s16 *, M2C_FIELD(arg0, u16 *, 0x6c) * 8 + 2) = (s16)r12;
            M2C_FIELD(alloc, s16 *, M2C_FIELD(arg0, u16 *, 0x6c) * 8 + 4) = (s16)((j - selX) * 2);
            M2C_FIELD(alloc, s16 *, M2C_FIELD(arg0, u16 *, 0x6c) * 8 + 6) = (s16)r2;
            M2C_FIELD(arg0, s16 *, 0x6c) = (s16)(M2C_FIELD(arg0, u16 *, 0x6c) + 1);
        }
    }
}

void func_0207af6c(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x54));
}

void func_0207af7c(void *arg0){
s16 (*p)[4]=M2C_FIELD(arg0,void **,0x54);s16 i;
if(M2C_FIELD(arg0,s16 *,0x6e)==8){func_0207a748(1);func_01ffa574(arg0);return;}
M2C_FIELD(arg0,s16 *,0x6e)++;
if(M2C_FIELD(arg0,s16 *,0x6c)>204)return;
func_02091230();
for(i=0;i<M2C_FIELD(arg0,s16 *,0x6c);i++){
p[i][0]+=p[i][2];
p[i][1]+=p[i][3];
*(volatile u32 *)0x040004a4=0x1f0080;
}
}

void func_0207b028(M2C_UNK arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02100bd0;
    func_01ffa3dc(&data_02100bd0, arg0);
}

void func_0207b040(void) {
 M2C_UNK func_01ffa9e4(M2C_UNK *);
 extern M2C_UNK data_02100bd0;
 func_01ffa9e4(&data_02100bd0);
 func_0207a768();
}

void func_0207b058(void *arg0) {
    s32 func_0206409c(s32);
    extern void *gCurrentMap;
    extern u8 data_02144ce0[];

    u16 rem;
    u16 counter;

    M2C_FIELD(arg0, s16 *, 0x34) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x5148);
    M2C_FIELD(arg0, s16 *, 0x36) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x514a);

    M2C_FIELD(arg0, s16 *, 0x3c) = (s16)(M2C_FIELD(arg0, s16 *, 0x38) - M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x5148));
    M2C_FIELD(arg0, s16 *, 0x3e) = (s16)(M2C_FIELD(arg0, s16 *, 0x3a) - M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x514a));

    if (func_0206409c(M2C_FIELD(arg0, s16 *, 0x3c)) > func_0206409c(M2C_FIELD(arg0, s16 *, 0x3e))) {
        rem = (u16)func_0206409c(M2C_FIELD(arg0, s16 *, 0x3c));
    } else {
        rem = (u16)func_0206409c(M2C_FIELD(arg0, s16 *, 0x3e));
    }

    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    counter = 1;
    for (;;) {
        s32 diff = (s32)rem - (s32)counter;
        if (diff < 0) {
            break;
        }
        rem = (u16)diff;
        data_02144ce0[M2C_FIELD(arg0, u16 *, 0x40)] = (u8)counter;
        if (counter < 8) {
            counter = (u16)(counter + 1);
        }
        M2C_FIELD(arg0, s16 *, 0x40) = (s16)(M2C_FIELD(arg0, u16 *, 0x40) + 1);
    }
    data_02144ce0[M2C_FIELD(arg0, u16 *, 0x40)] = (u8)rem;
    M2C_FIELD(arg0, s16 *, 0x42) = 0;
}

void func_0207b164(void *arg0) {
    extern u8 data_02144ce0[];
    s32 func_0206409c(s32);
    s32 func_020720f0(s32, s32);
    M2C_UNK func_01ffa574(M2C_UNK);
    extern void *gCurrentMap;

    void (*cb)(void);
    s32 fixedX;
    s32 fixedY;
    s32 accum;
    s32 signMajor;

    if (func_0206409c(M2C_FIELD(arg0, s16 *, 0x3c)) > func_0206409c(M2C_FIELD(arg0, s16 *, 0x3e))) {
        M2C_FIELD(arg0, u16 *, 0x42) = (u16)(M2C_FIELD(arg0, u16 *, 0x42) + data_02144ce0[M2C_FIELD(arg0, u16 *, 0x40)]);
        if (M2C_FIELD(arg0, s16 *, 0x3c) > 0) {
            signMajor = 1;
        } else {
            signMajor = -(M2C_FIELD(arg0, s16 *, 0x3c) < 0);
        }
        accum = (s32)M2C_FIELD(arg0, u16 *, 0x42) * signMajor;
        fixedX = (M2C_FIELD(arg0, s16 *, 0x34) + accum) << 16;
        fixedY = accum * func_020720f0(M2C_FIELD(arg0, s16 *, 0x3e) << 16, M2C_FIELD(arg0, s16 *, 0x3c)) + (M2C_FIELD(arg0, s16 *, 0x36) << 16);
    } else {
        M2C_FIELD(arg0, u16 *, 0x42) = (u16)(M2C_FIELD(arg0, u16 *, 0x42) + data_02144ce0[M2C_FIELD(arg0, u16 *, 0x40)]);
        if (M2C_FIELD(arg0, s16 *, 0x3e) > 0) {
            signMajor = 1;
        } else {
            signMajor = -(M2C_FIELD(arg0, s16 *, 0x3e) < 0);
        }
        accum = (s32)M2C_FIELD(arg0, u16 *, 0x42) * signMajor;
        fixedX = accum * func_020720f0(M2C_FIELD(arg0, s16 *, 0x3c) << 16, M2C_FIELD(arg0, s16 *, 0x3e)) + (M2C_FIELD(arg0, s16 *, 0x34) << 16);
        fixedY = (M2C_FIELD(arg0, s16 *, 0x36) + accum) << 16;
    }

    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x5148) =
        (s16)((s32)(fixedX + (((u32)(fixedX >> 15)) >> 16)) >> 16);

    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x514a) =
        (s16)((s32)(fixedY + (((u32)(fixedY >> 15)) >> 16)) >> 16);

    if (M2C_FIELD(arg0, u16 *, 0x40) != 0) {
        M2C_FIELD(arg0, u16 *, 0x40) = (u16)(M2C_FIELD(arg0, u16 *, 0x40) - 1);
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x5148) = M2C_FIELD(arg0, s16 *, 0x38);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x514a) = M2C_FIELD(arg0, s16 *, 0x3a);
        func_01ffa574(arg0);
        cb = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), 0x1c);
        if (cb != NULL) {
            cb();
        }
    }
}

