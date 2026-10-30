/* 13 functions from 0x0220BCAC to 0x0220C6C8 (ov003), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 mode : 4;
    u8 unk_4 : 4;
} Ov003ModeByte;

void func_ov003_0220c414(void *, s32);
void func_ov003_0220bcac(void *arg0) {
    extern s32 func_0207c8ec(s32, s32);
    extern void func_020a979c(void *, s16, s16);
    extern void func_ov003_0220c0e8(void *);

    void *sub;
    void *p;
    s16 f12, f14, f16, f08, f14p, f12p, diff;
    s16 r6;
    s32 val, q, sum;

    sub = M2C_FIELD(arg0, void **, 0x60);
    M2C_FIELD(sub, s16 *, 0x12) = 0x5F;
    f14 = M2C_FIELD(sub, s16 *, 0x14);
    if (M2C_FIELD(sub, s16 *, 0x16) >= 0x5F) {
        if (0x5F >= f14)
            M2C_FIELD(sub, s16 *, 0x12) = 0x5F;
        else
            M2C_FIELD(sub, s16 *, 0x12) = f14;
    }
    p = M2C_FIELD(sub, void **, 0x1C);
    f12 = M2C_FIELD(sub, s16 *, 0x12);
    f14p = M2C_FIELD(p, s16 *, 0x14);
    f12p = M2C_FIELD(p, s16 *, 0x12);
    f16 = M2C_FIELD(sub, s16 *, 0x16);
    f14 = M2C_FIELD(sub, s16 *, 0x14);
    r6 = M2C_FIELD(sub, s16 *, 0x8);
    diff = f14p - f12p;
    val = f12 * diff;
    q = func_0207c8ec(val, f16 - f14);
    sum = r6 + q;
    func_020a979c(p, (s16)sum, M2C_FIELD(p, s16 *, 0xA));

    sub = M2C_FIELD(arg0, void **, 0x64);
    M2C_FIELD(sub, s16 *, 0x12) = 0x5F;
    f14 = M2C_FIELD(sub, s16 *, 0x14);
    if (M2C_FIELD(sub, s16 *, 0x16) >= 0x5F) {
        if (0x5F >= f14)
            M2C_FIELD(sub, s16 *, 0x12) = 0x5F;
        else
            M2C_FIELD(sub, s16 *, 0x12) = f14;
    }
    p = M2C_FIELD(sub, void **, 0x1C);
    f12 = M2C_FIELD(sub, s16 *, 0x12);
    f14p = M2C_FIELD(p, s16 *, 0x14);
    f12p = M2C_FIELD(p, s16 *, 0x12);
    f16 = M2C_FIELD(sub, s16 *, 0x16);
    f14 = M2C_FIELD(sub, s16 *, 0x14);
    r6 = M2C_FIELD(sub, s16 *, 0x8);
    diff = f14p - f12p;
    val = f12 * diff;
    q = func_0207c8ec(val, f16 - f14);
    sum = r6 + q;
    func_020a979c(p, (s16)sum, M2C_FIELD(p, s16 *, 0xA));

    func_ov003_0220c0e8(arg0);

    p = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(p, s32 *, 0x4) = 0;
    if (*(u8 *)((u8 *)p + 0x14)) {
        while (M2C_FIELD(p, s32 *, 0x4) > M2C_FIELD(p, s32 *, 0x8))
            M2C_FIELD(p, s32 *, 0x4) -= M2C_FIELD(p, s32 *, 0x8) - M2C_FIELD(p, s32 *, 0xC) + 1;
        while (M2C_FIELD(p, s32 *, 0x4) < M2C_FIELD(p, s32 *, 0xC))
            M2C_FIELD(p, s32 *, 0x4) += M2C_FIELD(p, s32 *, 0x8) - M2C_FIELD(p, s32 *, 0xC) + 1;
    }
    M2C_FIELD(p, s32 *, 0x1C) = 0;
    if (*(u8 *)((u8 *)p + 0x2C)) {
        while (M2C_FIELD(p, s32 *, 0x1C) > M2C_FIELD(p, s32 *, 0x20))
            M2C_FIELD(p, s32 *, 0x1C) -= M2C_FIELD(p, s32 *, 0x20) - M2C_FIELD(p, s32 *, 0x24) + 1;
        while (M2C_FIELD(p, s32 *, 0x1C) < M2C_FIELD(p, s32 *, 0x24))
            M2C_FIELD(p, s32 *, 0x1C) += M2C_FIELD(p, s32 *, 0x20) - M2C_FIELD(p, s32 *, 0x24) + 1;
    }
    M2C_FIELD(p, s32 *, 0x34) = 0;
    if (*(u8 *)((u8 *)p + 0x44)) {
        while (M2C_FIELD(p, s32 *, 0x34) > M2C_FIELD(p, s32 *, 0x38))
            M2C_FIELD(p, s32 *, 0x34) -= M2C_FIELD(p, s32 *, 0x38) - M2C_FIELD(p, s32 *, 0x3C) + 1;
        while (M2C_FIELD(p, s32 *, 0x34) < M2C_FIELD(p, s32 *, 0x3C))
            M2C_FIELD(p, s32 *, 0x34) += M2C_FIELD(p, s32 *, 0x38) - M2C_FIELD(p, s32 *, 0x3C) + 1;
    }
}

s8 func_ov003_0220bf68(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0xB);
}

void func_ov003_0220bf70(void) {
    M2C_UNK func_01ff9d88(M2C_UNK);
    extern void *data_027e00c4;
    func_01ff9d88(1);
    M2C_FIELD(data_027e00c4, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e00c4, u8 *, 0x46) | 2);
}

void func_ov003_0220bf98(void *a) {
M2C_UNK func_020a8f8c(s32);M2C_UNK func_ov003_022084f0(void *);
s32 offset,flag,i;
func_020a8f8c(M2C_FIELD(a,s32 *,0x54));
flag=M2C_FIELD(a,u8 *,0x34)!=0;
if((u8)flag){func_ov003_022084f0(a);return;}
func_020a8f8c(M2C_FIELD(a,s32 *,0x50));
i=0;if((s32)*M2C_FIELD(a,u8 **,0x44)<=0)return;
offset=0;do {
void *p=(u8 *)M2C_FIELD(a,void **,0x48)+offset;
u32 x,y;
s32 value,limit,delta,v;
x=M2C_FIELD(p,u8 *,0x11);y=M2C_FIELD(p,u8 *,0x12);
if(x==y){
 value=M2C_FIELD(p,s8 *,0x13);delta=M2C_FIELD(p,s8 *,0x15);
 limit=M2C_FIELD(p,s8 *,0x14);v=value+delta;
 if(v<=limit){if(v<0)v=0;limit=v;}
 M2C_FIELD(p,s8 *,0x13)=limit;
}else{
 value=M2C_FIELD(p,s8 *,0x13);delta=M2C_FIELD(p,s8 *,0x15);
 limit=M2C_FIELD(p,s8 *,0x14);v=value-delta;
 if(v<=limit){if(v<0)v=0;limit=v;}
 M2C_FIELD(p,s8 *,0x13)=limit;
}
y=M2C_FIELD(p,u8 *,0x12);
if(M2C_FIELD(p,u8 *,0x11)!=y&&M2C_FIELD(p,s8 *,0x13)==0)M2C_FIELD(p,u8 *,0x11)=y;
limit=M2C_FIELD(p,u16 *,14);x=M2C_FIELD(p,u16 *,12);delta=M2C_FIELD(p,u8 *,16);
if(x<(u32)limit){
 v=x+delta;if(v<=limit){if(v<205)v=205;limit=v;}
 M2C_FIELD(p,u16 *,12)=limit;
}else{
 v=x-delta;if(v>256)limit=256;else if(v>=limit)limit=v;
 M2C_FIELD(p,u16 *,12)=limit;
}
i++;offset+=36;
}while(i<(s32)*M2C_FIELD(a,u8 **,0x44));
}

void func_ov003_0220c0e8(void *arg0) {
    M2C_UNK func_020bf9f0(s16);
    M2C_UNK func_020bfa30(s16);
    func_020bf9f0(M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s16 *, 0x12));
    func_020bfa30(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s16 *, 0x12));
}

void func_ov003_0220c10c(void *arg0) {
    void func_ov003_0220c0e8(void *);
    u8 idx;
    s32 v;
    u8 k;
    void **p;
    void *q;

    p = *(void ***) ((u8 *) arg0 + 0x5c);
    q = *p;
    if (q != 0) {
        v = *(u16 *) ((u8 *) q + 8);
    } else {
        v = -1;
    }
    k = *(u8 *) (*(void **) ((u8 *) arg0 + 0x3c) + 0xf);
    idx = (u8)(v - 0xb);
    if (k == 8) {
        if (idx == 0 || idx == 1) {
            func_ov003_0220c0e8(arg0);
        }
    } else {
        if (idx != 0) {
            func_ov003_0220c0e8(arg0);
        }
    }
}

void func_ov003_0220c190(void *arg,s32 index){
extern void *data_027e00c4;
s32 func_020bee64(s32);
u8 *p=arg,*q,*entry; s32 type,value,flag;void *ptr;u32 n;
p[0x38]|=2;
entry=*(u8**)((u8*)M2C_FIELD(p,void**,0x48)+index*36);
q=M2C_FIELD(p,u8**,0x3c);
type=entry[1];value=entry[2];q[q[15]]=index;
q=M2C_FIELD(p,u8**,0x3c);flag=q[15]==1;
if((u8)flag){
ptr=*M2C_FIELD(p,void***,0x5c);
n=ptr?M2C_FIELD(ptr,u16*,8):-1;
if((u8)(n-11)==1 && !func_020bee64(8)){type=2;value=5;}
}
switch(type){
case 1:p[0x34]=49;func_ov003_0220a698(p,value);func_ov003_0220828c(p,0,(u8)index);func_01ff9d88(1);M2C_FIELD(data_027e00c4,u8*,0x46)|=2;func_0208fe30(0x1000d);break;
case 2:func_020d47d0();func_020d885c(value);func_ov003_0220828c(p,0,(u8)index);func_01ffa6fc(p);func_0208fe30(0x1000e);break;
case 3:switch(entry[2]){case 0:case 1:case 2:func_0208fe30(0x1000d);func_ov003_0220c414(p,1);func_020b4db0(value,p);break;case 3:func_0208fe30(0x1000d);func_ov003_0220c414(p,3);func_020b4e10(p);break;}break;
}
}

void func_ov003_0220c328(void *arg0, int arg1) {
 extern void *data_027e00c4;
 u8 *p=arg0; u8 *q; int v; u8 a,b;
 p[0x38]&=~2;
 q=*(u8 **)(p+0x3c); v=q[0x10];
 func_0208fe30(0x1000f);
 if((u8)((((unsigned int)p[0x36]<<24)>>28)==1) || (u8)((((unsigned int)p[0x36]<<24)>>28)==2)){p[0x35]=1;func_020d47f0();func_01ffa6fc(p);}
 p[0x38]&=~8;
 q=*(u8 **)(p+0x3c);q[q[0xf]]=arg1;
 if(v!=16){p[0x34]=30;func_ov003_0220a698(p,v);func_ov003_0220828c(p,5,255);func_01ff9d88(1);M2C_FIELD(data_027e00c4,u8 *,0x46)|=2;}
 else {func_020d47f0();func_01ffa6fc(p);}
}

void func_ov003_0220c414(void *arg0, s32 arg1) {
u8 mode=arg1;
M2C_FIELD(arg0,u8 *,0x38) |= 0x10;
((Ov003ModeByte *)((u8 *)arg0+0x36))->mode=mode;
}

void func_ov003_0220c43c(void *arg0) {
    s32 func_020d4810(void);
    void func_ov003_02207e80(void *);
    void func_ov003_0220c328(void *, s32);
    void func_02083464(void);
    extern void **gCur3DSpriteEngine;

    u8 *obj = (u8 *)arg0;
    u32 r1 = obj[0x38];

    if (!(((u32)r1 << 27) >> 31)) {
        return;
    }
    obj[0x38] &= ~0x10;

    {
        u16 * volatile sp2c;
        sp2c = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp2c = (u16)((*sp2c & ~0x1) | 0x1);
    }
    {
        u16 * volatile sp28;
        sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp28 = (u16)(*sp28 & ~0x2);
    }
    {
        u16 * volatile sp24;
        sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp24 = (u16)(*sp24 & ~0x4);
    }
    {
        u16 * volatile sp20;
        sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp20 = (u16)(*sp20 & ~0x8);
    }
    {
        u16 * volatile sp1c;
        sp1c = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp1c = (u16)(*sp1c & ~0x10);
    }
    {
        u16 * volatile sp18;
        sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp18 = (u16)(*sp18 & ~0x20);
    }
    {
        u16 * volatile sp14;
        sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp14 = (u16)(*sp14 & ~0x100);
    }
    {
        u16 * volatile sp10;
        sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp10 = (u16)(*sp10 & ~0x200);
    }
    {
        u16 * volatile spC;
        spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *spC = (u16)(*spC & ~0x400);
    }
    {
        u16 * volatile sp8;
        sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp8 = (u16)(*sp8 | 0x800);
    }
    {
        u16 * volatile sp4;
        sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp4 = (u16)(*sp4 & ~0x1000);
    }
    {
        u16 * volatile sp0;
        sp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp0 = (u16)(*sp0 | 0x2000);
    }

    {
        u32 val = ((Ov003ModeByte *)(obj + 0x36))->mode;

        switch (val) {
        case 0:
            break;
        case 1: {
            s32 r0 = func_020d4810();
            if (r0 == 0) {
                return;
            }
            func_ov003_02207e80(obj);
            {
                u16 **pp = (u16 **)(obj + 0x5c);
                u16 *unit = **(u16 ***)(obj + 0x5c);
                s32 r1v;
                if (unit != 0) {
                    r1v = (s32)unit[4];
                } else {
                    r1v = -1;
                }
                r1v = r1v - 0xb;
                func_ov003_0220c328(obj, (s32)(u8)r1v);
            }
            return;
        }
        case 2: {
            func_ov003_02207e80(obj);
            return;
        }
        case 3: {
            func_02083464();
            return;
        }
        }
    }
    return;
}

void func_ov003_0220c6a4(void) {
    M2C_UNK func_ov003_022066d8();
    func_ov003_022066d8();
}

void func_ov003_0220c6b0(void) {
    M2C_UNK func_ov003_02209310();
    func_ov003_02209310();
}

void func_ov003_0220c6bc(void) {
    M2C_UNK func_ov003_02209cdc();
    func_ov003_02209cdc();
}

