/* 29 functions from 0x02224F94 to 0x02225F60 (ov010), found by ds-decomp. */
#include "common.h"
extern s16 data_ov010_0222c03c[];
extern s16 data_ov010_0222ddb4[];
extern s32 data_ov010_0222d95c[];
extern s32 data_ov010_0222d944[];
extern s32 data_ov010_0222d920[4];
extern s32 data_ov010_0222d914;

#pragma opt_strength_reduction off
s32 func_ov010_02224f94(s32 a, u32 b, u8 *c) {
    extern s32 data_ov010_0222c02c;
    volatile u16 *ctl = (volatile u16 *)0x40002b0;
    volatile s32 *result = (volatile s32 *)0x40002b4;
    volatile s32 *in = (volatile s32 *)0x40002b8;
    u32 sum;
    u32 h;
    s32 cur;
    u32 i;

    M2C_FIELD(&data_ov010_0222c02c, s32 *, 4) = b >> 8;
    if (c) {
        *c = (u8)(b >> 8);
    }

    if (M2C_FIELD(&data_ov010_0222c02c, s32 *, 0) == 0) {
        sum = 0;
        for (i = 0; i < 4; i++) {
            sum += (u32)M2C_FIELD(&data_ov010_0222d920, s32 *, i * 4);
        }
        *ctl = 0;
        *in = (s32)(sum >> 2);
        while (*ctl & 0x8000) {
        }
        h = (u32)*result;
        if (b != 0 && b >= (h << 1)) {
            sum = 0;
            for (i = 0; i < 4; i++) {
                sum += (u32)M2C_FIELD(&data_ov010_0222d920, s32 *, i * 4);
            }
            *ctl = 0;
            *in = (s32)(sum >> 2);
            while (*ctl & 0x8000) {
            }
            h = (u32)*result;
            M2C_FIELD(&data_ov010_0222d914, s32 *, 0) = (s32)(h * 3 / 2);
            M2C_FIELD(&data_ov010_0222d914, s32 *, 4) = 0;
            M2C_FIELD(&data_ov010_0222c02c, s32 *, 0) = 1;
        }
        cur = M2C_FIELD(&data_ov010_0222d914, s32 *, 4);
        M2C_FIELD(&data_ov010_0222d920, s32 *, cur * 4) = a;
        M2C_FIELD(&data_ov010_0222d914, s32 *, 4) = (cur + 1) & 3;
        M2C_FIELD(&data_ov010_0222d914, s32 *, 8) = 0;
        return 2;
    }

    cur = M2C_FIELD(&data_ov010_0222d914, s32 *, 4);
    M2C_FIELD(&data_ov010_0222d920, s32 *, cur * 4) = a;
    M2C_FIELD(&data_ov010_0222d914, s32 *, 4) = (cur + 1) & 3;

    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += (u32)M2C_FIELD(&data_ov010_0222d920, s32 *, i * 4);
    }
    *ctl = 0;
    *in = (s32)(sum >> 2);
    while (*ctl & 0x8000) {
    }
    h = (u32)*result;

    if (h > (u32)M2C_FIELD(&data_ov010_0222d914, s32 *, 0)) {
        M2C_FIELD(&data_ov010_0222d914, s32 *, 8) = 0;
        return 2;
    }

    M2C_FIELD(&data_ov010_0222d914, s32 *, 8) =
        M2C_FIELD(&data_ov010_0222d914, s32 *, 8) + 1;
    if (M2C_FIELD(&data_ov010_0222d914, s32 *, 8) > M2C_FIELD(&data_ov010_0222c02c, s32 *, 8)) {
        M2C_FIELD(&data_ov010_0222c02c, s32 *, 0) = 0;
        M2C_FIELD(&data_ov010_0222d914, s32 *, 8) = 0;
        M2C_FIELD(&data_ov010_0222d914, s32 *, 4) = 0;
        return 3;
    } else {
        M2C_FIELD(&data_ov010_0222d914, s32 *, 8) = 0;
        return 2;
    }
}
#pragma opt_strength_reduction on
void func_ov010_02225174(void) {
 void func_ov010_02224f28(void);
 extern s32 data_ov010_0222c02c;
 s16 n;
 M2C_FIELD(&data_ov010_0222c02c,s32 *,8)=15;
 n=M2C_FIELD(&data_ov010_0222c02c,s32 *,8);
 M2C_FIELD(&data_ov010_0222c02c,s32 *,12)=n*(s16)0x44;
 func_ov010_02224f28();
}

#pragma opt_strength_reduction off
s32 func_ov010_0222519c(s16 *a,u32 bytes){
extern s32 data_ov010_0222d930;
s32 value,input,prev,square,st4,st16;u32 n,i;s64 sum;
input=a[0]*(s16)0xe9f;
st4=M2C_FIELD(&data_ov010_0222d930,s32 *,4);
st16=M2C_FIELD(&data_ov010_0222d930,s32 *,16);
value=(input+st4+st16*0xd3e)>>12;
square=value*value;n=bytes>>1;
M2C_FIELD(&data_ov010_0222d930,s32 *,16)=value;
prev=-input;M2C_FIELD(&data_ov010_0222d930,s32 *,4)=prev;
sum=square;
for(i=1;i<n;i++){
input=a[i]*(s16)0xe9f;
prev=input+prev+value*0xd3e;
a[i-1]=value;
value=prev>>12;
square=value*value;sum+=square;prev=-input;
}
M2C_FIELD(&data_ov010_0222d930,s32 *,4)=prev;
M2C_FIELD(&data_ov010_0222d930,s32 *,16)=value;
*(s16 *)((char *)a+n*2-2)=value;
*(volatile u16 *)0x4000280=1;
*(volatile s64 *)0x4000290=sum;
*(volatile u64 *)0x4000298=n;
while(*(volatile u16 *)0x4000280&0x8000){}
return *(volatile s32 *)0x40002a0;
}
#pragma opt_strength_reduction on
void func_ov010_02225288(void) {
 extern s32 data_ov010_0222d930;
 s16 *src=data_ov010_0222c03c;
 s32 i,j;
 M2C_FIELD(&data_ov010_0222d930,s32 *,12)=0;
 M2C_FIELD(&data_ov010_0222d930,s32 *,8)=0x19D;
 for(i=0;i<0x800;i++) data_ov010_0222ddb4[i]=0;
 for(j=0;j<6;j++) {
 data_ov010_0222d95c[j]=0;
 data_ov010_0222d944[j]=src[j];
 }
}

void func_ov010_02225304(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007ef4(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov010_0222d974;
    func_02007ef4(arg0, &data_ov010_0222d974, arg1);
}

void func_ov010_0222531c(M2C_UNK arg0, M2C_UNK *arg1, M2C_UNK arg2, M2C_UNK arg3) {
    extern M2C_UNK data_ov010_0222d930;
    volatile u16 *hw0 = (volatile u16 *) 0x4000280;
    volatile u32 *hw1 = (volatile u32 *) 0x40002a0;
    volatile u32 *hw2 = (volatile u32 *) 0x40002b4;
    M2C_UNK *g = (M2C_UNK *) &data_ov010_0222d930;
    M2C_UNK *g2 = arg1;
    s16 *buf = (s16 *) arg0;
    s16 *tab = (s16 *) data_ov010_0222ddb4;
    u32 count = (u32) arg2 >> 1;
    u32 low = 0, high = 0;
    u32 idx = 0;
    u32 lr = 0x3fff8000;

    if (count == 0) goto tail1;

    do {
        u32 r4, r7, sp0, a, b, c, d, e, r9, r10, r5v;
        s16 r6;

        r4 = idx << 1;
        r7 = M2C_FIELD(g, u32 *, 0xc);
        r6 = ((s16 *) g2)[idx];
        tab[r7] = r6;
        r4 = M2C_FIELD(g, u32 *, 0x8);
        sp0 = r4;
        r4 = tab[r4];
        M2C_FIELD(g, s32 *, 0x2c) = (s32) r4;

        r9 = M2C_FIELD(g, u32 *, 0x3c);
        r10 = M2C_FIELD(g, u32 *, 0x24);
        r5v = M2C_FIELD(g, u32 *, 0x40);
        r10 = r9 * r10;
        a = M2C_FIELD(g, u32 *, 0x28);
        a = r5v * a + r10;
        M2C_FIELD(g, u32 *, 0x40) = r9;
        r9 = M2C_FIELD(g, u32 *, 0x38);
        b = M2C_FIELD(g, u32 *, 0x20);
        b = r9 * b + a;
        M2C_FIELD(g, u32 *, 0x3c) = r9;
        r9 = M2C_FIELD(g, u32 *, 0x34);
        c = M2C_FIELD(g, u32 *, 0x1c);
        b = r9 * c + b;
        M2C_FIELD(g, u32 *, 0x38) = r9;
        r9 = M2C_FIELD(g, u32 *, 0x30);
        d = M2C_FIELD(g, u32 *, 0x18);
        b = r9 * d + b;
        M2C_FIELD(g, u32 *, 0x34) = r9;
        e = M2C_FIELD(g, u32 *, 0x14);
        r4 = (u32) r6 * e + b;
        if (r4 > lr) r4 = lr;
        if (r4 < 0xc0000000u) r4 = 0xc0000000u;
        r7 = r7 + 1;
        r7 = r7 & (lr >> 13);
        M2C_FIELD(g, u32 *, 0xc) = r7;
        sp0 = sp0 + 1;
        sp0 = sp0 & (lr >> 13);
        M2C_FIELD(g, u32 *, 0x8) = sp0;
        r4 = r4 >> 15;
        ((s16 *) g2)[idx] = (s16) r4;
        {
            s32 q = r6 * r6;
            low += (u32) q;
            high += (u32) ((s32) q >> 31);
        }
        idx++;
    } while (idx < count);

tail1:
    hw0[0] = 1;
    *(volatile u32 *) ((char *) hw0 + 0x10) = low;
    *(volatile u32 *) ((char *) hw0 + 0x14) = high;
    *(volatile u32 *) ((char *) hw0 + 0x18) = count;
    *(volatile u32 *) ((char *) hw0 + 0x1c) = 0;
    {
        u32 t;
        do {
            t = hw0[0];
        } while (t & 0x8000);
    }
    {
        u32 t0 = hw1[0];
        ((volatile u16 *) hw1)[0x10 >> 1] = 0;
        hw1[0x18 >> 2] = t0;
        {
            u32 t;
            do {
                t = ((volatile u16 *) hw1)[0x10 >> 1];
            } while (t & 0x8000);
        }
    }
    {
        u32 r4v = hw2[0];
        u32 r1v = r4v + (r4v << 1);
        u32 thr = (u32) arg3 << 1;
        if (r1v < thr) {
            *(volatile u16 *) g = 0;
            return;
        }
        if ((u32) arg3 < r4v) {
            *(volatile u16 *) g = 4;
        }
        {
            s32 t = *(volatile s16 *) g;
            if (t < 4) {
                t++;
                *(volatile s16 *) g = (s16) t;
            }
        }
        if (count > 0) {
            u32 r5v = 0;
            do {
                s32 r4b = (s32) *(volatile s16 *) g;
                s32 v = buf[r5v];
                r5v++;
                v = v >> r4b;
                buf[r5v - 1] = (s16) v;
            } while (r5v < count);
        }
    }
}

void func_ov010_02225538(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2) {
 void func_ov010_0222531c(M2C_UNK,M2C_UNK *,M2C_UNK,M2C_UNK);
 extern M2C_UNK data_ov010_0222d974;
 func_ov010_0222531c(arg0,&data_ov010_0222d974,arg1,arg2);
}

void func_ov010_02225558(s16 *a,s16 *b,s16 *out,u32 size){
u32 i; s32 v;
for(i=0;i<(size>>1);i+=4){
v=a[i+0]+b[i+0];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+0]=v;
v=a[i+1]+b[i+1];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+1]=v;
v=a[i+2]+b[i+2];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+2]=v;
v=a[i+3]+b[i+3];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+3]=v;
}
}

s32 func_ov010_02225640(void *arg) {
    void func_02000b9c(s32);
    s32 func_ov010_02224dd8(void *, u32);
    M2C_UNK func_ov010_02224ea0();
    s32 func_ov010_0222415c(void *);
    s32 func_ov010_022224b4(void);
    M2C_UNK func_ov010_02224270();
    void func_02007f8c(void *, u32, u32);
    extern M2C_UNK data_ov010_0222edb4;
    extern M2C_UNK data_ov010_0222edc0;
    s32 kind;
    s32 t;
    u8 b;
    func_02000b9c(0x2000c6c);
    if (arg == 0) return 0;
    if (M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) != 0) return 1;
    kind = M2C_FIELD(arg, s32 *, 8);
    if (kind != 1 && kind != 2 && kind != 3) return 0;
    if (M2C_FIELD(arg, s32 *, 0x18) == 0) return 0;
    t = M2C_FIELD(arg, s32 *, 0x10);
    if (t == 0 || M2C_FIELD(arg, s32 *, 0x14) == 0) return 0;
    if (t % (s32)32 != 0) return 0;
    func_02007f8c(&data_ov010_0222edc0, 0, 0x18);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x10) = M2C_FIELD(arg, s32 *, 0x18);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x14) = M2C_FIELD(arg, s32 *, 0x1C);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x1C) = M2C_FIELD(arg, s32 *, 8);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x18) = 0;
    b = (u8)M2C_FIELD(arg, u8 *, 0xC);
    if ((u32)b >= 0x20) return 0;
    M2C_FIELD(&data_ov010_0222edb4, u8 *, 0xC) = b;
    { s32 r = func_ov010_02224dd8(M2C_FIELD(arg, void **, 0x10), M2C_FIELD(arg, u32 *, 0x14)); if (!r) { func_ov010_02224ea0(); return 0; } }
    { s32 r = func_ov010_0222415c(arg); if (!r) { func_ov010_02224ea0(); return 0; } }
    { s32 r = func_ov010_022224b4(); if (r) { M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) = 1; return 1; } }
    func_ov010_02224270();
    func_ov010_02224ea0();
    return 0;
}

void func_ov010_02225778(void) {
    M2C_UNK func_ov010_022225b0();
    M2C_UNK func_ov010_02224270();
    M2C_UNK func_ov010_02224ea0();
    extern M2C_UNK data_ov010_0222edb4;
    func_ov010_022225b0();
    func_ov010_02224270();
    func_ov010_02224ea0();
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) = 0;
}

void func_ov010_022257a0(void) {
extern s32 data_ov010_0222edb4;
void func_ov010_02224288(void);
s32 func_ov010_022231d4(void);
void func_ov010_02223114(void);
if(!M2C_FIELD(&data_ov010_0222edb4,s32 *,8))return;
if(!(++data_ov010_0222edb4 & 15))func_ov010_02224288();
if(func_ov010_022231d4())func_ov010_02223114();
}

s32 func_ov010_022257e4(s32 a,s32 b,s32 c) {
s32 func_ov010_02225858(s32,s32,s32,s32 *);
extern s32 data_ov010_0222edb4;
s32 out[2];
s32 result = func_ov010_02225858(a,b,c,out);
switch(result){
case 0:break;
case 1:
((void (*)(s32,s32,s32,s32))M2C_FIELD(&data_ov010_0222edb4,s32 *,16))(a,out[0],out[1],M2C_FIELD(&data_ov010_0222edb4,s32 *,20));
return 1;
case 2:return 0;
}
return 1;
}

s32 func_ov010_02225858(s32 a,s32 b,s32 c,s32 *out) {
extern s32 data_ov010_0222edb4;
u64 func_02007004(void);
void func_ov010_02222f28(s32,s32,s32,u64);
s32 func_ov010_02224334(s32,s32,s32,s32 *);
u64 now; u8 kind; s32 *state;
if(!b)return 0;
if(M2C_FIELD(b,u32*,0)!=0x5f564354)return 2;
if(!M2C_FIELD(&data_ov010_0222edb4,s32*,28)||!M2C_FIELD(&data_ov010_0222edb4,s32*,8))return 0;
out[0]=0;out[1]=0;
now=func_02007004();
kind=M2C_FIELD(b,u8*,4);
if((kind & 0xF0) == 0x40) {
state=&data_ov010_0222edb4;
state[1]++;
func_ov010_02222f28(a,b,c,now);
return 0;
}
if(kind == 0 || kind == 0xFF) return func_ov010_02224334(a,b,c,out) != 0;
return 0;
}

void func_ov010_02225934(void) {
 extern s32 data_ov010_0222edd8;
 M2C_FIELD(&data_ov010_0222edd8,s32 *,0x10)=1;
}

void func_ov010_02225948(void) {
void func_ov010_02224f28(void);
extern s32 data_ov010_0222edd8;
func_ov010_02224f28();
M2C_FIELD(&data_ov010_0222edd8,s32 *,16)=0;
}

void func_ov010_02225964(void *a0, s32 count, void **arr, s32 size, s32 arg4) {
    extern s32 data_ov010_0222edd8;
    extern s32 data_ov010_0222edf8;
    void func_ov010_02225934(void);
    void func_02007f8c(void *, u32, u32);
    void func_0200ddb0(void *, void *, u32);
    s32 func_0200dfa8(void);
    void *func_ov010_02222b0c(void *, s32, s32);
    void func_ov010_022227b0(s32, s32);
    void func_020067e0(void *, s32);
    void func_020067a8(s32, s32);

    s32 pos;
    s32 changed;
    s32 i;

    if (a0 == 0) {
        i = 0;
        if (count <= 0) {
            return;
        }
        do {
            func_02007f8c(arr[i], 0, size);
            i++;
        } while (i < count);
        return;
    }

    if (M2C_FIELD(&data_ov010_0222edd8, s32 *, 4) != 0) {
        if (M2C_FIELD(&data_ov010_0222edd8, s32 *, 0x10) == 0) {
            func_0200ddb0(&data_ov010_0222edf8, (void *)func_ov010_02225934, 0);
            M2C_FIELD(&data_ov010_0222edd8, s32 *, 4) = 0;
        }
    }

    pos = arg4;
    changed = 0;
    if ((u32)func_0200dfa8() - (u32)pos < (u32)size) {
        if (M2C_FIELD(&data_ov010_0222edd8, s32 *, 8) != 0) {
            M2C_FIELD(&data_ov010_0222edd8, s32 *, 8) = 0;
            pos += size;
            changed = 1;
        }
    } else {
        if (M2C_FIELD(&data_ov010_0222edd8, s32 *, 8) != 1) {
            changed = 1;
            M2C_FIELD(&data_ov010_0222edd8, s32 *, 8) = 1;
        }
    }

    M2C_FIELD(&data_ov010_0222edd8, s32 *, 0) = (s32)func_ov010_02222b0c(arr[0], size, 0);

    if (changed) {
        func_ov010_022227b0(pos, size);
    }

    if (count > 0) {
        i = 0;
        do {
            func_020067e0(arr[i], size);
            i++;
        } while (i < count);
    }

    if (changed) {
        func_020067a8(pos, size);
    }
}

M2C_UNK func_ov010_02225aa4(M2C_UNK *arg0, M2C_UNK arg1) {
    (void)arg0; (void)arg1;
    return 0;
}

void func_ov010_02225cd8(void) {
    M2C_UNK func_ov010_02225aa4(M2C_UNK *, M2C_UNK);
    extern void func_ov010_02225964(void *, s32, void **, s32, s32);
    func_ov010_02225aa4((void *)&func_ov010_02225964, 0x44);
}

s32 func_ov010_02225cf0(void) {
    extern s32 data_ov010_0222edd8;
    return data_ov010_0222edd8;
}

void func_ov010_02225d00(void) {
extern s32 data_ov010_0222ee14;
void func_0202b70c(void *);
void func_0202a9f0(void);
void func_02004e60(s32,s32);
s32 i;
func_0202b70c(&data_ov010_0222ee14);
for(i=0;i<4;i++){func_0202a9f0();func_02004e60(1,1);}
}

void func_ov010_02225d38(void) {
    M2C_UNK func_0200df70();
    extern M2C_UNK data_ov010_0222ee14;
    func_0200df70();
    func_0202b760(&data_ov010_0222ee14);
}

void func_ov010_02225d50(void) {
extern s32 data_ov010_0222edd8;
M2C_FIELD(&data_ov010_0222edd8,s32 *,4)=1;
}

void func_ov010_02225d64(void) {
extern s32 data_ov010_0222edd8;
void func_0200df14(void (*)(void),s32);
func_0200df14(func_ov010_02225948,0);
M2C_FIELD(&data_ov010_0222edd8,s32 *,4)=0;
}

s32 func_ov010_02225d8c(void) {
    extern M2C_UNK data_ov010_0222edd8;
    return M2C_FIELD(&data_ov010_0222edd8, s32 *, 0x10);
}

s32 func_ov010_02225d9c(void) {
void func_ov010_02224f74(s32 *);
s32 out[4];func_ov010_02224f74(out);return out[0];
}

void func_ov010_02225db8(void) {
extern s32 data_ov010_0222ee14;
extern s32 data_ov010_0222edd8;
void func_0202b544(void *);
void func_ov010_02226100(s32,s32);
void func_0200e868(s32);
func_0202b760(&data_ov010_0222ee14);
func_0202b544(&data_ov010_0222ee14);
func_ov010_02226100(M2C_FIELD(&data_ov010_0222edd8,s32 *,12),M2C_FIELD(&data_ov010_0222edd8,s32 *,24));
M2C_FIELD(&data_ov010_0222edd8,s32 *,12)=0;
func_ov010_02226100(M2C_FIELD(&data_ov010_0222edd8,s32 *,28),M2C_FIELD(&data_ov010_0222edd8,s32 *,20));
M2C_FIELD(&data_ov010_0222edd8,s32 *,28)=0;
func_0200e868(0);
}

void func_ov010_02225e10(s32 a) {
extern s32 data_ov010_0222ee70;
void func_ov010_022226fc(s32);
void func_ov010_02223ef0(s32);
if(a==M2C_FIELD(&data_ov010_0222ee70,s32 *,4)){
func_ov010_022226fc(a);
func_ov010_02223ef0(a);
M2C_FIELD(&data_ov010_0222ee70,s32 *,4)=0;
}else func_ov010_02223ef0(a);
}

void func_ov010_02225f54(void) {
    M2C_UNK func_ov010_022257e4();
    func_ov010_022257e4();
}
