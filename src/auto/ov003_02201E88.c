/* 24 functions from 0x02201E88 to 0x02202DC8 (ov003), found by ds-decomp. */
#include "common.h"
#include "coordinate_bits.h"
static inline void E1E88Apply(void *p,u8 v) { s32 flag; s8 a; if(v==1)flag=1;else flag=0; M2C_FIELD(p,u8 *,0x39)=v; if(flag&255)a=0;else a=1; M2C_FIELD(M2C_FIELD(p,void **,0x4C),s8 *,0x59)=a; }
static inline void E1E88Virtual(void *p) { M2C_FIELD(M2C_FIELD(p,void **,0),void (**)(void *),32)(p); }
static inline u8 E1E88IsZero(u8 v) { return v == 0; }
static inline u8 E1E88IsOne(u8 v) { return v == 1; }
static inline void E1E88Set(void *p, u8 v) { M2C_FIELD(p,s8*,0x59)=v; }
static inline void E1E88Toggle(void *p, u8 v) { u8 a; if(v)a=0;else a=1; M2C_FIELD(p,s8*,0x59)=a; }

void func_ov003_02201e88(void *arg0, void *arg1) {
    s32 func_020846a4();
    s32 func_020848f8();
    void func_02088da8(void *);
    void *func_0208931c(void *);
    void func_02098e04(void *, s32, s32);
    void func_02098e2c(void *, s32);
    void *func_02099088(void *);
    M2C_UNK func_020a22fc(s32);
    M2C_UNK func_020a2370(s32);
    M2C_UNK func_020a23b4(s32);
    M2C_UNK func_020cfb94();
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    extern u8 data_ov003_02210484[];
    u8 buf[4];
    s32 saved;
    u32 n;
    u8 k;
    u8 m;
    s8 j;
    s32 i;
    u32 flag;
    u8 v11;
    s32 val;
    s32 t;
    void *p;
    u16 v;

    n = (u32) func_020cfb94();
    k = 0;
    do {
        buf[k] = 0xFF;
        k = k + 1;
    } while ((u32) k < 4);
    k = 0;
    t = func_020848f8();
    j = 0;
    do {
        if (t & (1 << j)) {
            buf[k] = (u8) j;
            k = k + 1;
        }
        j = j + 1;
    } while (j < 4);
    for (m = 0; (u32) m < n; m++) {
        u8 c = buf[m];
        if (c != 0xFF && m != c) {
            if ((s32) c <= (s32) (n - 1) && buf[c] == 0xFF) {
                buf[c] = c;
                buf[m] = 0xFF;
            }
        }
    }
    saved = (s32) gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    i = 0;
    do {
        val = (u8) func_020a22fc(i + 1);
        if (func_020a23b4(i + 1) == 2) {
            flag = 2;
        } else {
            flag = 1;
        }
        v11 = (u8) func_020a2370(i + 1);
        p = func_02099088(arg1);
        ((void **) arg0)[i + 1] = p;
        func_02098e04(p, (0x1D0 + (i << 4)) << 5, 7);
        p = ((void **) arg0)[i + 1];
        func_02098e2c(p, val);
        p = ((void **) arg0)[i + 1];
        *(u16 *) ((u8 *) p + 0x3C) = 0x800;
        p = ((void **) arg0)[i + 1];
        func_02088da8(p);
        p = func_0208931c(arg1);
        ((void **) arg0)[i + 5] = p;
        *(void **) ((u8 *) p + 0x44) = data_ov003_02210484;
        if ((u8) flag == 1) {
            if (func_020846a4() != 0) {
                v = (u16) ((buf[i] << 4) + 0x180);
            } else {
                v = (u16) (0x180 + (i << 4));
            }
        } else {
            v = 0x1C0;
        }
        *(u16 *) ((u8 *) ((void **) arg0)[i + 5] + 0x3E) = (u32) (v << 5) >> 5;
        *(u16 *) ((u8 *) ((void **) arg0)[i + 5] + 0x3C) = 0x6800;
        func_02088da8(((void **) arg0)[i + 5]);
        p = func_0208931c(arg1);
        ((void **) arg0)[i + 9] = p;
        *(void **) ((u8 *) p + 0x44) = data_ov003_02210484;
        p = ((void **) arg0)[i + 9];
        *(u16 *) ((u8 *) p + 0x3E) = (u32) ((((v11 - 1) * 0x10) + 0x140) << 5) >> 5;
        p = ((void **) arg0)[i + 9];
        *(u16 *) ((u8 *) p + 0x3C) = 0x6800;
        p = ((void **) arg0)[i + 9];
        func_02088da8(p);
        i++;
    } while (i < 4);
    gCur3DSpriteEngine = (void *) saved;
}

void func_ov003_022020e0(void *p,u8 v){
s32 func_0207c8ec(u8,s32); s32 func_0207c928(u8,s32); void func_020808dc(s32,s32,s32,s32); extern void *data_027e01d8;
s32 flag; s8 a; u8 id; s32 x;
if((u8)v==1)flag=1;else flag=0;
M2C_FIELD(p,u8*,0x39)=v;
if(flag & 255)a=0;else a=1;
M2C_FIELD(M2C_FIELD(p,void**,0x4c),s8*,0x59)=a;
func_020808dc(M2C_FIELD(data_027e01d8,s32*,0x2c),32,32,0);
flag=E1E88IsOne(M2C_FIELD(p,u8*,0x39));
if(flag){
id=M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0x10c),u16*,0x2e);
x=func_0207c928(id,4);
{ s32 y=func_0207c8ec(id,4); x=(x*8+0x60); func_020808dc(M2C_FIELD(data_027e01d8,s32*,0x2c)+((u32)((y*0x120+x)<<16)>>15),8,8,1); }
}
M2C_FIELD(data_027e01d8,u8*,0x46)|=8;
}

u8 func_ov003_022021c0(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x39) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_022021d8(void *arg0) {
    return (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10C), u16 *, 0x2E);
}

void func_ov003_022021e8(void *arg0) {
s32 func_020aae10(void *);s32 func_020aae44(void *);
s32 a,b;void *q;
q=M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c);
b=func_020aae44(q);a=func_020aae10(q);
E9638Set(M2C_FIELD(arg0,void**,0x4c),M2C_FIELD(q,s16*,0x34),M2C_FIELD(q,s16*,0x36),a,b);
}

void func_ov003_02202254(void *arg0) {
M2C_UNK func_0208b758(s32,s32); s32 func_ov003_02200d80(u8,u8);
s32 value; u8 kind; void *p;
if((u8)(((u32)(M2C_FIELD(arg0,u8 *,0x3a)<<26)>>26)==1)) return;
p=M2C_FIELD(arg0,void **,0x44);
kind=(u8)M2C_FIELD(M2C_FIELD(p,void **,0x10c),u16 *,0x2e);
value=M2C_FIELD((u8 *)p+kind*24,s32 *,12);
switch(kind) {
case 0:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),0x47000000);break;
case 1:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),func_ov003_02200d80(kind,(u8)value));break;
case 2:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),func_ov003_02200d80(kind,(u8)value));break;
case 3:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),0x4700000b);break;
case 4:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),0x47000014);break;
case 5:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),0x4700000a);break;
case 6:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),func_ov003_02200d80(kind,(u8)value));break;
case 7:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),0x47000015);break;
case 8:func_0208b758(M2C_FIELD(arg0,s32 *,0x58),0x47000018);break;
}}

void func_ov003_02202380(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x12) = arg1;
}

void func_ov003_02202388(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x16) = arg1;
}

void func_ov003_02202390(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x14) = arg1;
}

void func_ov003_02202398(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x21) = arg1;
}

void func_ov003_022023a0(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x17) = arg1;
}

void func_ov003_022023a8(void *arg0,s32 arg1){M2C_FIELD(arg0,u8*,0x28)=(M2C_FIELD(arg0,u8*,0x28)&~0xe0)|((u32)((u8)arg1<<29)>>24);}

void func_ov003_022023c4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
}

void func_ov003_022023cc(void *arg0,s32 arg1){M2C_FIELD(arg0,u8*,0x20)=(M2C_FIELD(arg0,u8*,0x20)&~0xe0)|((u32)(arg1<<29)>>24);}

void func_ov003_022023e4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020a9a30(arg0, 0, arg1, arg2);
}

void func_ov003_022023fc(void) {
    M2C_UNK func_020cfb94();
    func_020cfb94();
}

s32 func_ov003_02202408(s32 arg0) {
    return (s32) (arg0 << 0xD) >> 0x10;
}

void func_ov003_02202414(void *arg0) {
    M2C_UNK func_02084d88(void *, M2C_UNK);
    M2C_UNK func_02084dcc(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02084e74();
    func_02084dcc(0, M2C_FIELD(arg0, void **, 0x44) + 0x110, 0x24);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s32 *, 0x110) = 0;
    func_02084d88(M2C_FIELD(arg0, void **, 0x44) + 0x110, 0x24);
    func_02084e74();
}

void func_ov003_02202454(void *arg0){void *p;u8 i;
p=M2C_FIELD(arg0,void**,0x40);
func_02088da8(M2C_FIELD(p,s32*,0));func_02088da8(M2C_FIELD(p,s32*,4));
for(i=0;(u32)i<8;i++){func_02088da8(((s32*)(p+8))[i]);func_02088da8(((s32*)(p+0x28))[i]);}
func_02088da8(M2C_FIELD(arg0,s32*,0x4c));}

void func_ov003_0220277c(void *arg0) { (void)arg0; }

void func_ov003_02202b68(void *p) {
 M2C_UNK func_020aacf0(s32);
 u8 i;
 func_020aacf0(M2C_FIELD(p,s32 *,0));
 func_020aacf0(M2C_FIELD(p,s32 *,4));
 for(i=0;(u32)i<8;i++) {
 func_020aacf0(((s32 *)(p+8))[i]);
 func_020aacf0(((s32 *)(p+0x28))[i]);
 }
}

void func_ov003_02202bb0(void *p){
 s32 func_0207c8ec(u8,s32); s32 func_0207c928(u8,s32); void func_020808dc(s32,s32,s32,s32); s32 func_0208fe30(s32); extern void *gCur3DSpriteEngine;
 s32 flag; s8 a; u8 id; s32 x; u8 v=0;
 func_0208fe30(0x1000F);
 if(E1E88IsZero(M2C_FIELD(p,u8 *,0x39))) {{void *q=p; ((void (*)(void *, ...))(*(void *** )q)[8])(q);}return;}
 M2C_FIELD(p,u8 *,0x39)=0;
 if(M2C_FIELD(p,u8 *,0x39)==1)flag=1;else flag=0;
 if(flag&255) E1E88Set(M2C_FIELD(p,void **,0x4C),0); else E1E88Set(M2C_FIELD(p,void **,0x4C),1);
 
 func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32*,0x2c),32,32,0);
 flag=E1E88IsOne(M2C_FIELD(p,u8*,0x39));
 if(flag){
 id=M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0x10c),u16*,0x2e);
 x=func_0207c928(id,4);
 { s32 y=func_0207c8ec(id,4); x=(x*8+0x60); func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32*,0x2c)+((u32)((y*0x120+x)<<16)>>15),8,8,1); }
 }
 M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=8;
}

void func_ov003_02202cc4(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020d47f0();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1be8();
    s32 func_ov003_02200c7c();
    M2C_UNK func_ov003_02204fd0(void *);
    extern u16 data_02168f14;
    s32 temp_r6;
    s32 var_r0;
    u8 var_r7;
    void **temp_r0_2;
    void *temp_r0;

    func_0208fe30(0x1000F);
    func_020d47f0();
    temp_r0 = *M2C_FIELD(arg0, void ***, 0x40);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
    }
    func_ov003_021f1be8();
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r6 = M2C_FIELD(arg0, s32 *, 0x44);
        var_r7 = 0;
        do {
            temp_r0_2 = M2C_FIELD((temp_r6 + (var_r7 * 4)), void ***, 0xC8);
            M2C_FIELD(*temp_r0_2, M2C_UNK (**)(void **, s32), 0x1C)(temp_r0_2, M2C_FIELD(((var_r7 * 0x18) + temp_r6), s32 *, 0xC));
            var_r7 += 1;
        } while ((u32) var_r7 < 8U);
        data_02168f14 |= 0x2000;
    }
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x4C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (func_ov003_02200c7c() == 0) {
        return;
    }
    func_ov003_02204fd0(arg0);
}

