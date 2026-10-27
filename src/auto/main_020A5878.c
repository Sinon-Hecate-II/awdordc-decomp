/* 23 functions from 0x020A5878 to 0x020A67FC (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 owner:2; u8 x,y,unk3; u16 flags; u16 hp:7; u16 ammo:4; u16 unk6:5; u16 a:6; u16 b:6; u16 c:2; u16 d:2; u8 fuel:7; u8 flag:1; u8 e:4; u8 f:1; u8 g:1; u8 h:1; u8 i:1; u8 j,k; } Unit5B;
extern u8 data_ov000_021b5c0a[], data_ov000_021b5c05[];
extern s8 *data_ov000_021b5c58[];
extern u8 data_ov000_021b5c0f[];
extern s16 data_ov000_021aeef4[];typedef struct { u8 unk0[12]; s32 money; u8 unk10[0x7c]; } UnkStruct_020A6328;

void func_020a5ac8(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02120608;
    func_01ffa3dc(&data_02120608, 7);
}

s32 func_020a5ae0(u32 arg0) {
    s32 var_r1;

    var_r1 = 0;
    switch (arg0) {
    default:
        break;
    case 4:
        var_r1 = 0x1E;
        break;
    case 6:
    case 7:
        var_r1 = 0x1F;
        break;
    case 1:
        var_r1 = 0x1D;
        break;
    }
    return var_r1;
}

s32 func_020a5b2c(Unit5B *p) {
extern s32 *gCurrentMap;
s32 func_020a7d38(Unit5B *);
u8 *base=(u8 *)*gCurrentMap;
s32 kind=p->kind;
s32 cost=M2C_FIELD((char *)data_ov000_021b5c58+kind*112,s8 **,0)[M2C_FIELD(base+(p->x+M2C_FIELD(base+p->y*2,u16 *,0x3758)),u8 *,0x1420)&31];
if(!func_020a5c40((u8 *)p))return 0;
if(func_020a7d38(p) && (p->kind)==22)cost=5;
if(cost<0)cost=0;
if(cost>=p->fuel)p->fuel=0;
else p->fuel-=cost;
if(!p->fuel && (data_ov000_021b5c0f[(p->kind)*112]&48))return 1;
return 0;
}

s32 func_020a5c40(u8 *p){
extern s32 *gCurrentMap;
extern u8 data_ov000_021b5c67[];
s32 func_020d273c(u16,s32);
u8 *base=(u8 *)*gCurrentMap;
u16 flags=M2C_FIELD(p,u16 *,4);
u8 tile=M2C_FIELD(base+(p[1]+M2C_FIELD(base+p[2]*2,u16 *,0x3758)),u8 *,0x1420);
if(flags&8)return 0;
if(func_020d273c(M2C_FIELD(base,u16 *,0x52a4),(tile&0xe0)>>5)){
switch(tile&31){
case 18:case 20:
if(data_ov000_021b5c67[((u32)(p[0]<<26)>>26)*0x70]==18)return 0;
break;
case 19:case 21:
if(data_ov000_021b5c67[((u32)(p[0]<<26)>>26)*0x70]==19)return 0;
break;
}
}
return 1;
}

u8 func_020a5d2c(s32 a,s32 b){extern s32 *gCurrentMap;u8 *p=(u8 *)*gCurrentMap;s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x508);if(!v)return 0;return (M2C_FIELD(p+((v>>6)+1)*0x8c,u8 *,0x67c3)&2)?1:0;}

s32 func_020a5d8c(s32 arg0, u8 arg1, u8 arg2) {
    extern s32 *gCurrentMap;
    s32 func_020a7d38(Unit5B *);
    u8 func_020a5d2c(s32, s32);
    s32 r4 = 0;
    s32 r6 = arg1;
    s32 r5 = arg2;
    s32 r7;

    if (arg0 == 0) {
        r7 = r4;
        return 1;
    }
    r7 = (arg0 - (*(s32 *)*gCurrentMap + 0x59a4)) / 14;
    r7 = (u16)r7;

    if (arg0 == 0) {
        return 1;
    }
    if (!func_020a7d38((Unit5B *)arg0)) {
        return 1;
    }
    if (*((u8 *)*(s32 *)*gCurrentMap + ((r7 >> 6) + 1) * 0x8c + 0x67c3) & 0x2) {
        return 1;
    }
    {
        s32 row = *(u16 *)((u8 *)*(s32 *)*gCurrentMap + r5 * 2 + 0x3758);
        u8 tile = *((u8 *)*(s32 *)*gCurrentMap + r6 + row + 0x1420);
        s32 k = (tile & 0xe0) >> 5;
        if (*((u8 *)*(s32 *)*gCurrentMap + k * 0x8c + 0x67c3) & 0x2) {
            return 1;
        }
    }

    if (r6 > 0) {
        r4 = (u16)(r4 + func_020a5d2c((s16)(r6 - 1), r5));
    }
    if (r5 > 0) {
        r4 = (u16)(r4 + func_020a5d2c(r6, (s16)(r5 - 1)));
    }
    {
        s32 maxw = *(u16 *)((u8 *)*(s32 *)*gCurrentMap + 0x5144);
        if (r6 < maxw - 1) {
            r4 = (u16)(r4 + func_020a5d2c((s16)(r6 + 1), r5));
        }
    }
    {
        s32 maxh = *(u16 *)((u8 *)*(s32 *)*gCurrentMap + 0x5146);
        if (r5 < maxh - 1) {
            r4 = (u16)(r4 + func_020a5d2c(r6, (s16)(r5 + 1)));
        }
    }

    if (r4 != 0) {
        return 1;
    }
    return 0;
}

void func_020a5f4c(s32 arg0) {
    M2C_UNK func_020a5d8c(s32, u8, u8);
    extern s32 *gCurrentMap;
    s32 temp_r0;

    temp_r0 = (0xE * arg0) + (*gCurrentMap + 0x59A4);
    func_020a5d8c(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2));
}

s32 func_020a5f80(s32 a,s32 b){extern s32 *gCurrentMap;s32 func_020d27c0(s32);u8 *p=(u8 *)*gCurrentMap;register u32 i=a+M2C_FIELD(p+b*2,u16 *,0x3758);u8 v=M2C_FIELD(p+i,u8 *,0x508);if(!v||!(u8)(M2C_FIELD(p+(i>>3),u8 *,0x5160)&(1<<(i&7))))return 0;if(!M2C_FIELD(p,u8 *,i)&&!(M2C_FIELD(p+v*14,u16 *,0x59a8)&4))return 0;return func_020d27c0(v);}

s32 func_020a600c(s32 arg0) {
    extern s32 *gCurrentMap;
    extern s16 data_ov000_021aeef4[];
    s32 func_020a7d38(Unit5B *);
    s32 func_020d27c0(s32);
    s32 func_020d27ec(s32, s32);
    s32 func_020a5f80(s32, s32);

    u32 basePtr = *(u32 *)*gCurrentMap;
    Unit5B *unit = (Unit5B *)(basePtr + 0x59a4 + arg0 * 14);
    u16 acc = 0;
    u8 x, y;

    if (unit == 0) {
        return 1;
    }
    if (!func_020a7d38(unit)) {
        return 1;
    }
    if (unit->flags & 0x40) {
        return 1;
    }

    x = unit->x;
    y = unit->y;

    if (unit != 0) {
        u32 bp = *(u32 *)*gCurrentMap;
        s32 idx = (s32)((u8 *)unit - (u8 *)(bp + 0x59a4)) / 14;
        if (func_020d27c0(idx)) {
            return 1;
        }
    }

    {
        u32 bp = *(u32 *)*gCurrentMap;
        u16 rowOff = *(u16 *)((u8 *)bp + y * 2 + 0x3758);
        u16 w = *(u16 *)((u8 *)bp + 0x52a4);
        u8 tile = *(u8 *)((u8 *)bp + x + rowOff + 0x1420);
        s16 val = data_ov000_021aeef4[w];
        if (func_020d27ec(val, tile)) {
            return 1;
        }
    }

    if (x > 0) {
        acc = (u16)(acc + func_020a5f80((s16)(x - 1), y));
    }
    if (y > 0) {
        acc = (u16)(acc + func_020a5f80(x, (s16)(y - 1)));
    }
    {
        u32 bp = *(u32 *)*gCurrentMap;
        s32 maxw = *(u16 *)((u8 *)bp + 0x5144);
        if (x < maxw - 1) {
            acc = (u16)(acc + func_020a5f80((s16)(x + 1), y));
        }
    }
    {
        u32 bp = *(u32 *)*gCurrentMap;
        s32 maxh = *(u16 *)((u8 *)bp + 0x5146);
        if (y < maxh - 1) {
            acc = (u16)(acc + func_020a5f80(x, (s16)(y + 1)));
        }
    }

    if (acc != 0) {
        return 1;
    }
    return 0;
}

s32 func_020a61e8(void *arg0) {
    s32 func_020a5d8c(s32, u8, u8);
    extern s32 *gCurrentMap;
    u8 *p;
    u16 w;
    u8 b2;
    u8 b1;
    u8 *base;
    u16 u;
    u32 idx;
    u8 byte;
    s32 r;
    u16 r2;
    u8 val;

    p = (u8 *)arg0;
    w = *(u16 *)(p + 4);
    if (w & 0x4) {
        return 0;
    }
    b2 = p[2];
    base = (u8 *)*gCurrentMap;
    base = (u8 *)*(s32 *)base;
    b1 = p[1];
    u = *(u16 *)(base + b2 * 2 + 0x3758);
    idx = b1 + u;
    byte = *(u8 *)(base + (idx >> 3) + 0x5201);
    if (byte & (1u << (idx & 7))) {
        r = func_020a5d8c((s32)p, b1, b2);
        if (r != 0) {
            goto ret1;
        }
    }
    w = *(u16 *)(p + 4);
    if (w & 0x80) {
        return 1;
    }
    base = (u8 *)*gCurrentMap;
    base = (u8 *)*(s32 *)base;
    r2 = *(u16 *)(base + 0x52a4);
    val = *(u8 *)(base + r2 * 0x8c + 0x67c3);
    if (val == 3) {
        if (w & 0x40) {
            return 1;
        }
    }
    return 0;
ret1:
    return 1;
}

s32 func_020a62ac(s32 a,s32 b){extern s32 *gCurrentMap;s32 func_020a61e8(void *);u8 *p;u8 v;if(a<0||b<0)goto fail;p=(u8 *)*gCurrentMap;if(a>=M2C_FIELD(p,u16 *,0x5144)||b>=M2C_FIELD(p,u16 *,0x5146))goto fail;goto valid;fail:return 0;valid:v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x508);if(!v)return 0;return func_020a61e8(p+0x59a4+v*14);}

/* Adds `amount`-scaled income to the funds of the player/commander that owns terrain entry `entry`, capped at 999999999, and notifies the funds display if applicable. */
s32 func_020a6328(u8 *entry, s32 amount) {
extern s32 *gCurrentMap;
s32 func_020d2d18(s32,u32);
s32 func_020d19b4(s32);
s32 func_020cd728(void);
s32 id, income;
if(entry){if(!entry)id=0;else id=((s32)entry-(s32)((u8 *)*gCurrentMap+0x59a4))/14;id=(id>>6)+1;}else id=0;
income=amount*func_020d2d18(id,(u32)(entry[0]<<26)>>26);
((UnkStruct_020A6328 *)((u8 *)*gCurrentMap+0x67a4))[id].money+=income;
if(((UnkStruct_020A6328 *)((u8 *)*gCurrentMap+0x67a4))[id].money>999999999)((UnkStruct_020A6328 *)((u8 *)*gCurrentMap+0x67a4))[id].money=999999999;
if(func_020d19b4(id)&&!func_020cd728())func_02091c54(12,income);
}

s32 func_020a641c(u8 *p,s32 a){extern s32 *gCurrentMap;s32 func_020a85c0(u32);s32 func_020a86f0(s32);s32 n,v;if(p){if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;if(func_020a85c0((u32)(p[0]<<26)>>26))return 0;v=func_020a86f0(n)*a;n=(u32)(p[10]<<25)>>25;if(v>n)v=n;return v;}

void func_020a64bc(void *p){s32 func_020a641c();s32 n=func_020a641c(p);u8 b=M2C_FIELD(p,u8 *,10);M2C_FIELD(p,u8 *,10)=(b&~127)|((u8)(((u32)(b<<25)>>25)-n)&127);}

void func_020a64ec(void) {
    M2C_UNK func_ov000_02169518();
    func_ov000_02169518();
}

void func_020a64f8(void *arg0,u8 kind) {
Unit5B *p=arg0;
p->kind=kind;
p->owner=0;
p->flags=0;
p->hp=100;
p->fuel=data_ov000_021b5c0a[kind*112];
p->ammo=data_ov000_021b5c05[kind*112];
p->unk6=0;
p->j=0;p->k=0;
p->e=0;
p->a=63;p->b=63;p->f=1;p->c=0;p->d=0;
p->flag=0;p->g=0;p->h=0;p->i=0;
}

void *func_020a660c(s32 a,s32 b,s32 c,s32 d){void *func_020d2dcc(s32);void func_020a64f8(void *,u8);void func_020d3154(s32,s32);void *p=func_020d2dcc(d);if(!p)return 0;func_020a64f8(p,(u8)c);M2C_FIELD(p,u8 *,1)=a;M2C_FIELD(p,u8 *,2)=b;func_020d3154(d,c);return p;}

void *func_020a6658(s32 a,s32 b,s32 c,s32 d){extern s32 *gCurrentMap;void *func_020a660c(s32,s32,s32,s32);u8 *p=func_020a660c((s16)a,(s16)b,(s16)c,d);u8 v;if(!p)return 0;v=M2C_FIELD((u8 *)*gCurrentMap+d*0x8c,u8 *,0x67d6);p[0]=(p[0]&~0xc0)|((u32)(v<<30)>>24);M2C_FIELD(p,u16 *,4)|=1;if(c==22)M2C_FIELD(p,u16 *,4)|=32;return p;}

void *func_020a66e0(s32 a,s32 b,s32 c,s32 d){void *func_020a660c(s32,s32,s32,s32);void func_020cfd28(void *);void *p=func_020a660c((s16)a,(s16)b,(s16)c,d);if(!p)return 0;func_020cfd28(p);return p;}

void func_020a6718(M2C_UNK arg0) {
    void func_020a6738(M2C_UNK, M2C_UNK);
    func_020a6738(arg0, 0);
}

void func_020a6728(M2C_UNK arg0) {
    void func_020a6738(M2C_UNK, M2C_UNK);
    func_020a6738(arg0, 1);
}

void func_020a6738(M2C_UNK a,M2C_UNK b) {
extern s32 *gCurrentMap;
s32 func_0207c8ec(s32,s32);
u8 *p=(u8 *)*gCurrentMap+0x59a4+a*14;
if(b) {
u32 v;
func_020d319c((a>>6)+1,(u32)(p[0]<<26)>>26);
v=(u32)(M2C_FIELD(p,u16 *,6)<<25)>>25;
func_020a6328(p,v==0?0:func_0207c8ec(v-1,10)+1);
}else func_020d3120((a>>6)+1);
if(p[12])func_020a6738(p[12],b);
if(p[13])func_020a6738(p[13],b);
func_020a7e3c(p,1);
p[0]&=~63;
}

