/* 30 functions from 0x020C7CD0 to 0x020C8CBC (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[6]; u16 value; u32 year:8,month:6,day:6,hour:6,minute:6; u32 second:6,code:12,rest:14; u32 tail; } CompareRecord;
typedef struct { u8 low:6, state:2; u8 pad[7]; u16 x:6,y:6,rest:4; u8 unkA; u8 kind:4, high:4; } RestoredUnit;
static inline void RestoreKind(RestoredUnit *p,u8 v) {p->kind=v;}
static inline void RestoreX(RestoredUnit *p,u16 v) {p->x=v;}
static inline void RestoreY(RestoredUnit *p,u16 v) {p->y=v;}
static inline void RestoreState(RestoredUnit *p,u8 v) {p->state=v;}
typedef struct { u8 pad0[0xa10]; u16 tiles[0x508]; u8 cells[0x2338]; u16 rows[0xcf6]; u16 width,height; } Map8484;
typedef union {u32 word; struct {u32 low:10;u32 kind:5;u32 gap:3;u32 mode:4;u32 high:10;} bits;} PackedEntry;

void func_020c7cd0(void *arg0, void *arg1) {
    void *func_020e34bc(s32);
    void func_02007ef4(void *, void *, s32);
    void func_02007e98(s32, s32, s32);
    void func_020e35cc(void *);
    struct W4 { s32 a[4]; };

    register void *r6 asm("r6");
    register void *r5 asm("r5");
    register void *r4 asm("r4");
    register u8 *r7 asm("r7");
    register u8 *r3 asm("r3");
    register struct W4 *r8 asm("r8");
    register s32 r2 asm("r2");
    register s32 r12v asm("r12");
    register void *lr asm("lr");

    r6 = arg0;
    r5 = arg1;
    r4 = r6;
    if (r6 == r5) {
        r4 = func_020e34bc(0x2AC);
        func_02007ef4(r6, r4, 0x2AC);
    }
    func_02007e98(0, (s32)r5, 0x6F8);
    *(s32 *)r5 = *(s32 *)r4;
    r7 = (u8 *)r4 + 6;
    r3 = (u8 *)r5 + 6;
    ((u8 *)r5)[4] = ((u8 *)r4)[4];
    ((u8 *)r5)[5] = ((u8 *)r4)[5];
    r2 = 16;
    do {
        u8 t0 = r7[0];
        u8 t1 = r7[1];
        r7 = r7 + 2;
        r2 = r2 - 1;
        r3[0] = t0;
        r3[1] = t1;
        r3 = r3 + 2;
    } while (r2 != 0);
    r3[0] = r7[0];
    r8 = (struct W4 *)((u8 *)r5 + 0x30);
    r7 = (u8 *)r4 + 0x40;
    lr = (u8 *)r5 + 0x40;
    ((u8 *)r5)[0x27] = ((u8 *)r4)[0x27];
    ((u8 *)r5)[0x28] = ((u8 *)r4)[0x28];
    ((u8 *)r5)[0x29] = ((u8 *)r4)[0x29];
    ((u8 *)r5)[0x2A] = ((u8 *)r4)[0x2A];
    ((u8 *)r5)[0x2B] = ((u8 *)r4)[0x2B];
    ((u8 *)r5)[0x2C] = ((u8 *)r4)[0x2C];
    ((u8 *)r5)[0x2D] = ((u8 *)r4)[0x2D];
    ((u8 *)r5)[0x2E] = ((u8 *)r4)[0x2E];
    ((u8 *)r5)[0x2F] = ((u8 *)r4)[0x2F];
    *r8 = *(struct W4 *)((u8 *)r4 + 0x30);
    *(struct W4 *)lr = *(struct W4 *)r7;
    r7 = (u8 *)r7 + 16;
    lr = (u8 *)lr + 16;
    *(s32 *)lr = *(s32 *)r7;
    r12v = 0;
    if ((s32)(((u8 *)r4)[4] * ((u8 *)r4)[5]) > 0) {
        do {
            r7 = (u8 *)r4 + r12v;
            r3 = (u8 *)r5 + r12v; /* avoid? r3 gets overwritten; but target r0/r? let's instead direct */
        } while (0);
    }
    /* The above placeholder wrong. Do loops directly: */
    r12v = 0;
    if ((s32)(((u8 *)r4)[4] * ((u8 *)r4)[5]) > 0) {
        do {
            ((u8 *)r5)[0x54 + r12v] = ((u8 *)r4)[0x54 + r12v];
            r12v = r12v + 1;
        } while (r12v < (s32)(((u8 *)r4)[4] * ((u8 *)r4)[5]));
    }
    r2 = 0;
    if ((s32)((u8 *)r4)[0x2F] > 0) {
        do {
            *(s32 *)((u8 *)r5 + r2 * 4 + 0x3D8) = *(s32 *)((u8 *)r4 + r2 * 4 + 0x1E4);
            r2 = r2 + 1;
        } while (r2 < (s32)((u8 *)r4)[0x2F]);
    }
    if (r6 != r5) {
        return;
    }
    func_020e35cc(r4);
}

s32 func_020c7e58(s32 arg0) {
    extern M2C_UNK data_02164d64;
    return (0x54 * arg0) + (s32) &data_02164d64;
}

s32 func_020c7e6c(a)
s32 a;
{
 extern M2C_UNK data_02164d64;
 return (s32)&data_02164d64+0x54*func_020c8018(a);
}

s32 func_020c7e88(a)
s32 a; {
    s32 func_020c7e6c();
    return func_020c7e6c() + 0x40;
}

s32 func_020c7e98(void) {
    return func_020c7e6c() + 0x30;
}

s32 func_020c7ea8(a)
s32 a; {
    return func_020c8018() + 9;
}

u8 func_020c7eb8(s32 arg0) {
    u8 var_r0;

    if ((arg0 < 0xE1) || (arg0 >= 0x1A9)) {
        return 0U;
    }
    if (func_020c8020() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020c7ef4(s32 a) {
 s32 x;
 if(a<0xE1||a>=0x1A9)return 0;
 x=func_020c8020(a);
 if(x==0||x==255)return 0;
 return 1;
}

u8 func_020c7f30(s32 a) {
 s32 func_020c80a4(s32); s32 func_02086960(s32);
 s32 p;
 if(a<0xE1||a>=0x1A9)return 0;
 if(!func_020c7eb8(a))return 0;
 if(!func_020c7ef4(a))return 0;
 if(!func_020c80a4(a))return 0;
 if(!func_02086960(a))return 0;
 p=func_020c7e6c(a);
 if(M2C_FIELD(p,u8 *,4)>10)return 0;
 if(M2C_FIELD(p,u8 *,5)>10)return 0;
 return M2C_FIELD(p,u8 *,0x2F)<=50;
}

s32 func_020c7fe4(M2C_UNK arg0) {
    s32 func_02086680(s32);
    s32 func_020c8020(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_020c7e6c();
    if (func_020c8020(arg0) != 0) {
        return temp_r4 + 6;
    }
    return func_02086680(0xC00002EC);
}

s32 func_020c8018(s32 arg0) {
    return arg0 - 0xE1;
}

s32 func_020c8020(s32 a) {
 s32 p=func_020c7e6c(a); s32 r;
 if(M2C_FIELD(p,u32 *,0)!=0x20070731)return 0;
 if(M2C_FIELD(p,u8 *,6)==0)r=0;
 else r=M2C_FIELD(p,u8 *,0x27);
 return r;
}

s32 func_020c8054(s32 arg0) {
    s32 func_020bee64(M2C_UNK);
    u16 *func_020bfa60(M2C_UNK);
    u16 *temp_r0;

    if (func_020bee64(8) != 0) {
        temp_r0 = func_020bfa60(8);
        if ((arg0 >= 0xE1) && (arg0 < 0x1A9) && (arg0 == *temp_r0)) {
            return 1;
        }
    }
    return 0;
}

s32 func_020c80a4(s32 a) {
 s32 func_020c8c6c(s32);
 if(a<0xe1||a>=0x1a9)return 0;
 if(!func_020c7eb8(a))return 0;
 return func_020c8c6c(func_020c7e88(a));
}

u8 func_020c80ec(s32 a) {
 s32 func_02086980(s32);
 s32 p,q; u8 r;
 if(a>=0xe1&&a<0x1a9) {
 p=func_020c7e88(a);q=func_020c8018(a);
 if(!func_020c7eb8(a))return 0;
 if(func_020c80a4(a))return 0;
 if(func_02086980(q))return 0;
 if(M2C_FIELD(p,u32 *,0xc)>>29)return 0;
 if(M2C_FIELD(p,s32 *,0x10))r=1;else r=0;
 return r;
 }return 0;
}

s32 func_020c818c(s32 a,s32 b) {
 s32 func_020c79ec(); s32 func_020c7a14(); s32 func_020c85c4(s32,s32); void func_020868ac(s32,s32);
 s32 q,p,t;
 if(a<0xe1||a>=0x1a9)return 0;
 q=func_020c8018(a);p=func_020c79ec();t=func_020c7a14();
 if(!func_020c85c4(a,p))return 0;
 M2C_FIELD(t,u32 *,0xc)=(M2C_FIELD(t,u32 *,0xc)&~0xe0000000)|(b<<29);
 func_020868ac(q,1);
 return func_020c8624(a,p);
}

s32 func_020c8214(void *p){extern M2C_UNK data_ov000_021b5bfc;s32 i;PackedEntry *q;for(i=0;i<M2C_FIELD(p,u8 *,0x2f);i++){q=(PackedEntry *)((u8 *)p+0x3d8)+i;if(M2C_FIELD((u8 *)&data_ov000_021b5bfc+q->bits.kind*112,u8 *,108)){switch(q->bits.mode){case 0:case 1:q->bits.mode=0;break;case 6:q->bits.mode=6;break;case 8:q->bits.mode=8;break;}}}}

void func_020c82cc(s32 a) {
void func_020a68d4(void);
void *func_020a660c(s32,s32,s32,s32);
void func_020a3184(s32,void *);
extern void **gCurrentMap;
s32 i,x,y,player,kind,state,z;
u32 *src;
RestoredUnit *unit;
func_020a68d4();
i=0;
if(i>=M2C_FIELD(a,u8 *,0x2f))return;
src=(u32 *)(a+0x3d8);
do {
s32 v=*src;
x=(u32)(v<<27)>>27;
y=(u32)(v<<22)>>27;
z=(u32)(v<<17)>>27;
player=(u32)(v<<14)>>29;
kind=(u32)(v<<10)>>28;
state=(u32)(v<<8)>>30;
unit=func_020a660c(x,y,z,player);
if(unit) {
RestoreKind(unit,kind);
RestoreX(unit,x);
RestoreY(unit,y);
RestoreState(unit,state);
if(state==3) {
s32 v2=M2C_FIELD(*gCurrentMap+player*0x8c,s32 *,0x6810);
if((u32)(v2<<24)>>24)func_020a3184(player,unit);
}
}
i++;src++;
}while(i<M2C_FIELD(a,u8 *,0x2f));
}

void func_020c83f4(u8 *p){extern void **gCurrentMap;void func_02068c50(void *,void *);void func_020a231c(s32,s32);s32 i;u8 *base;func_02068c50((u8 *)*gCurrentMap+0x5120,p+6);M2C_FIELD(*gCurrentMap,u8 *,0x5141)=p[0x27];for(i=0;i<5;i++)func_020a231c(i,p[0x28+i]);base=(u8 *)*gCurrentMap;M2C_FIELD(base,u16 *,0x5144)=p[4];base=(u8 *)*gCurrentMap;M2C_FIELD(base,u16 *,0x5146)=p[5];}

s32 func_020c8484(s32 arg) {
extern void **gCurrentMap;
void func_020ceffc(void); u16 func_0207f460(u32);
s32 x,y; Map8484 *base; u8 *a=(u8 *)arg;
func_020ceffc();
base=*gCurrentMap;
for(y=0;y<base->height;y++) {
for(x=0;x<base->width;x++) {
u8 v;
base->cells[base->rows[y]+x]=(v=*a++);
base=*gCurrentMap;
base->tiles[x+base->rows[y]]=func_0207f460(v);
base=*gCurrentMap;
}
}
return (s32)base;
}

void func_020c854c(s32 arg0) {
    void func_020c83f4();
    M2C_UNK func_020c8484(s32);
    func_020c83f4();
    func_020c8484(arg0 + 0x54);
}

void func_020c8564(M2C_UNK arg0) {
    M2C_UNK func_020c8214();

    func_020c8214();
    func_020c82cc(arg0);
}

s32 func_020c857c(M2C_UNK arg0) {
    s32 func_020c79ec();
    s32 func_020c85c4(M2C_UNK, s32);
    M2C_UNK func_020cf2c8();
    M2C_UNK func_020cfd28();
    s32 temp_r0;

    temp_r0 = func_020c79ec();
    if (func_020c85c4(arg0, temp_r0) == 0) {
        return 0;
    }
    func_020c854c(temp_r0);
    func_020c82cc(temp_r0);
    func_020cf2c8();
    func_020cfd28();
    return 1;
}

s32 func_020c85c4(s32 a,s32 b){u8 func_020c8664(s32,s32);void func_02007e98(s32,s32,s32);s32 func_020be324(s32,s32);s32 p=func_020c7ea8(a);u8 r;func_02007e98(0,b,0x6f8);if(!func_020be324(p,b))return 0;if(func_020c8664(a,b))r=1;else r=0;return r;}

s32 func_020c8624(s32 a,s32 b) {
 s32 func_020c7a3c(s32); void func_020be438(s32,s32,s32);
 s32 p=func_020c7ea8(a);
 if(!func_020c7a3c(b))return 0;
 func_020be438(p,b,0x6f8);return 1;
}

u8 func_020c8664(s32 a,s32 b){s32 func_020c7a3c(s32);u8 func_020c8b0c(u8 *,u8 *);s32 p=func_020c7e6c(a);u8 r;if(!func_020c7a3c(b))return 0;if(func_020c8b0c(b,p))r=1;else r=0;return r;}

/* Pack the current system date/time and a CRC of the record data into its header. */
void func_020c86a8(void *p) {
    s32 func_020c7a24(); s32 func_0200f0ac(); void func_02007724(void *);
    extern u32 data_027e15bc;
    s32 date[4], time[3];
    s32 v = func_020c7a24(p);
    func_0200f0ac(date, time);
    func_02007724((u8 *)p + 64);
    M2C_FIELD(p, u32 *, 76) = (M2C_FIELD(p, u32 *, 76) & 0xfffc003f) | ((data_027e15bc << 20) >> 14);
    M2C_FIELD(p, u16 *, 70) = v;
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0xff) | (u8)date[0];
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0x3f00) | ((u32)(date[1] << 26) >> 18);
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0xfc000) | ((u32)(date[2] << 26) >> 12);
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0x3f00000) | ((u32)(time[0] << 26) >> 6);
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0xfc000000) | (time[1] << 26);
    M2C_FIELD(p, u32 *, 76) = (M2C_FIELD(p, u32 *, 76) & ~0x3f) | (time[2] & 0x3f);
    M2C_FIELD(p, u32 *, 76) &= 0xf003ffff;
    M2C_FIELD(p, u32 *, 76) &= ~0x10000000;
    M2C_FIELD(p, u32 *, 76) &= ~0xe0000000;
    M2C_FIELD(p, u32 *, 80) = 0;
}

void func_020c879c(void *arg0) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b56c0[];
    void func_02007e98(s32, s32, s32);
    void func_02068c50(void *, void *);
    s32 func_020a23b4(s32);
    s32 func_020a2360(s32);
    void func_02007ef4(void *, void *, s32);
    void func_020c86a8(void *);
    void *func_020bfa74(void);

    u8 *r4 = (u8 *)arg0;
    u8 *r5;
    s32 r6, r7, width, height, rowOffset;
    u8 sp[8];
    void *map;
    void *base;
    u8 *cursor;

    r5 = r4 + 0x54;
    func_02007e98(0, (s32)r4, 0x6f8);

    *(s32 *)r4 = 0x20070731;
    map = *gCurrentMap;
    base = *(void **)map;
    func_02068c50(r4 + 6, (u8 *)base + 0x5120);
    r4[4] = (u8)*(u16 *)((u8 *)base + 0x5144);
    r4[5] = (u8)*(u16 *)((u8 *)base + 0x5146);

    r7 = 0;
    r6 = 0;
    while (r6 < 5) {
        if (func_020a23b4(r6)) {
            r7 = (r7 + 1) & 0xFFFF;
        }
        r6 = ((r6 + 1) << 16) >> 16;
    }
    if (r7 < 2) {
        r4[0x27] = 0xff;
    } else {
        r4[0x27] = (u8)r7;
    }

    r6 = 0;
    while (r6 < 5) {
        s32 val = func_020a2360(r6);
        r4[r6 + 0x28] = (u8)val;
        r6 = ((r6 + 1) << 16) >> 16;
    }

    for (r6 = 0; r6 < 6; r6++) {
        sp[r6] = 0;
    }

    width = *(s16 *)((u8 *)base + 0x5146);
    if (width > 0) {
        height = *(s16 *)((u8 *)base + 0x5144);
        cursor = r5;
        r7 = 0;
        while (r7 < width) {
            if (height > 0) {
                rowOffset = *(u16 *)((u8 *)base + r7 * 2 + 0x3758);
                r6 = 0;
                while (r6 < height) {
                    u8 v = *(u8 *)((u8 *)base + r6 + rowOffset + 0x1420);
                    *cursor++ = v;
                    if ((s32)(s8)data_ov000_021b56c0[v & 0x1f] != 0) {
                        sp[5]++;
                        sp[v >> 5]++;
                    }
                    r6++;
                }
            }
            r7++;
        }
        r5 = cursor;
    }

    for (r6 = 1; r6 < 0x100; r6++) {
    }
    r4[0x2f] = 255;

    func_020bfa74();
    {
        void *tmp = func_020bfa74();
        func_02007ef4(tmp, r4 + 0x30, 0x10);
    }
    func_020c86a8(r4);
    (void)r5; (void)sp; (void)map;
}

/* Returns 1 if the two save/checkpoint record blobs compare equal field-by-field. */
u8 func_020c8b0c(u8 *lhs, u8 *rhs) {
    s32 i;
    CompareRecord *p;
    CompareRecord *q;

    if (lhs[0x27] != rhs[0x27]) {
        return 0;
    }
    if (lhs[0x2f] != rhs[0x2f]) {
        return 0;
    }
    if (lhs[4] != rhs[4]) {
        return 0;
    }
    if (lhs[5] != rhs[5]) {
        return 0;
    }
    p = (CompareRecord *)(lhs + 0x40);
    q = (CompareRecord *)(rhs + 0x40);
    for (i = 0; i < 6; i++) {
        if (p->bytes[i] != q->bytes[i]) {
            return 0;
        }
    }
    if (p->code != q->code) {
        return 0;
    }
    if (p->value != q->value) {
        return 0;
    }
    if (p->year != q->year) {
        return 0;
    }
    if (p->month != q->month) {
        return 0;
    }
    if (p->day != q->day) {
        return 0;
    }
    if (p->hour != q->hour) {
        return 0;
    }
    if (p->minute != q->minute) {
        return 0;
    }
    if (p->second != q->second) {
        return 0;
    }
    return (u8)(p->tail == q->tail);
}

s32 func_020c8c6c(s32 a) {
 void func_02007724(void *);
 u8 buf[6]; s32 i;
 func_02007724(buf);
 for(i=0;i<6;i++) {
 if(buf[i]!=*(u8 *)(a+i))return 0;
 }
 return 1;
}

