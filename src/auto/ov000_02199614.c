/* 14 functions from 0x02199614 to 0x0219A584 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u16 value:7; } Field7;

void func_ov000_02199614(u8 player) {
    typedef struct Unit98 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 health:7; u16 rest:9; u8 tail[6]; } Unit98;
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    s32 func_ov000_021973f8(s32);
    s32 func_ov000_02197434(s32,s32);
    s32 func_ov000_02197470(s32,s32,s32);
    s32 func_ov000_021974bc(s32,s32,void*);
    s32 func_ov000_0219763c(s32,void*,s32);
    void func_ov000_02197a8c(void*,s32,s32,s32,s32,s32,s32);
    s32 func_020a85dc(s32);
    s32 i, value; Unit98 *unit; s32 kind;
    if (!func_ov000_021973f8(0x15)) return;
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = player;
    for (i = data_ov000_021aeef4[player] + 1; i < data_ov000_021aeef4[player] + 0x33; i++) {
        unit = (Unit98 *)(*gCurrentMap + 0x59A4 + i * 14);
        kind = unit->kind;
        if (!kind) continue;
        if (M2C_FIELD(unit, u16 *, 4) & 8) {
            s32 map = *gCurrentMap;
            s32 x = unit->x;
            s32 y = unit->y;
            s32 idx = M2C_FIELD(map + M2C_FIELD(map, u16 *, 0x3758 + y * 2) + x, u8 *, 0x508);
            if (!func_020a85dc(((Unit98 *)(map + idx * 14 + 0x59A4))->kind)) continue;
        }
        kind = unit->kind;
        if (data_ov000_021b5bfc[kind * 112 + 19] & 0x10) continue;
        value = func_ov000_02197434(kind, 0x15);
        if (value < 0x19) continue;
        value = func_ov000_02197470(value, 0, unit->owner);
        value = func_ov000_021974bc(value, 0, unit);
        value = func_ov000_0219763c(value, unit, unit->health);
        if (!func_ov000_021a98e4(kind)) {
            // tail omitted (visibility bitmap updates)
        }
        func_ov000_02197a8c(unit, value, 0x15, 0x64, 0, 1, 0);
    }
}

void func_ov000_021998f0(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02199614(u8);
    extern s32 *gCurrentMap;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*gCurrentMap, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0) {
            func_ov000_02199614(i);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

void func_ov000_0219997c(void) {
    s32 func_0207c2f0(void);
    s32 func_0207c928(s32, s32);
    s32 func_02072b04(void *);
    s32 func_ov000_021a89a4(void *);
    extern s32 *gCurrentMap;
    extern u8 *data_ov000_021df658;
    extern u8 *data_ov000_021df580;
    extern u8 *data_ov000_021df57c;
    extern u8 *data_ov000_021df644;
    extern u8 data_ov000_021df7d0[];
    extern M2C_UNK data_ov000_021df604;
    extern void (*data_ov000_021df654)(void);

    u8 state;
    u8 *cont;
    u8 *base;
    u8 *up;
    u8 kind;
    u8 tile;
    u8 s;
    u8 ux, uy;
    s16 x, y;
    u16 row;
    s32 tmp;

    state = *data_ov000_021df658;
    if (state == 0) {
        data_ov000_021df580[0] = 1;
        return;
    }
    if (state == 0x40) {
        data_ov000_021df7d0[0x13] = 0;
    } else {
        cont = (u8 *)*gCurrentMap;
        base = *(u8 **)cont;
        base[0x52d4] = state;
        up = base + 0x59a4 + base[0x52d4] * 14;
        *(u8 **)(base + 0x52d0) = up;
        data_ov000_021df644 = data_ov000_021df57c + 0x14 + 0xc * (((u8)up[0] & 0x3f) - 1);
        base[0x52d6] = 0;

        if (!(*(u16 *)(up + 4) & 0x1)) {
            kind = (u8)(up[0] & 0x3f);
            if (kind == 0) {
                data_ov000_021df658++;
                return;
            }
        }
        up = *(u8 **)(base + 0x52d0);
        if (*(u16 *)(up + 4) & 0x8) {
            *(u16 *)(up + 4) &= ~0x8;
            uy = up[2];
            ux = up[1];
            row = *(u16 *)(base + uy * 2 + 0x3758);
            tile = base[ux + row];
            base[0x52d6] = tile;
        }

        up = *(u8 **)(base + 0x52d0);
        x = up[1];
        *(s16 *)(base + 0x52e0) = x;
        *(s16 *)(base + 0x52d8) = x;
        y = up[2];
        *(s16 *)(base + 0x52e2) = y;
        *(s16 *)(base + 0x52da) = y;
        data_ov000_021df580[7] = (u8)(data_ov000_021df580[7] & ~1);
        data_ov000_021df580[7] = (u8)(data_ov000_021df580[7] & ~2);
        *(u16 *)(data_ov000_021df580 + 8) = 0;
        data_ov000_021df7d0[0] = 0;
        data_ov000_021df7d0[0x13] = 0;
        data_ov000_021df7d0[6] = 0;
        {
            u8 *up2 = *(u8 **)(base + 0x52d0);
            u8 uuy = up2[2];
            u8 uux = up2[1];
            u16 rrow = *(u16 *)(base + uuy * 2 + 0x3758);
            base[uux + rrow] = 0;
        }
        tmp = func_0207c2f0();
        tmp = func_0207c928(tmp, 0x64);
        data_ov000_021df580[3] = (u8)tmp;
        up = *(u8 **)(base + 0x52d0);
        data_ov000_021df580[5] = (u8)func_ov000_021a89a4(up);
    }

    if (func_02072b04(&data_ov000_021df604) == 0) {
        data_ov000_021df654();
    }
    if (data_ov000_021df7d0[0x13] != 0) {
        data_ov000_021df658++;
        data_ov000_021df580[0] = 3;
        return;
    }
    cont = (u8 *)*gCurrentMap;
    base = *(u8 **)cont;
    state = *data_ov000_021df658;
    if (state != 0x40) {
        if (base[0x52d6] != 0) {
            up = *(u8 **)(base + 0x52d0);
            *(u16 *)(up + 4) |= 0x8;
            base[0x52d6] = 0;
        } else {
            up = *(u8 **)(base + 0x52d0);
            s = base[0x52d4];
            uy = up[2];
            ux = up[1];
            row = *(u16 *)(base + uy * 2 + 0x3758);
            base[ux + row] = s;
        }
    }
    data_ov000_021df658++;
    return;
}

void func_ov000_02199ce0(void) {
void func_02085348(void *,s32);
extern u8 data_ov000_021df7d0[];
extern u8 data_02156e50[];
s32 i;
u8 *s;
u8 *d;
u8 t;
s=data_ov000_021df7d0;
d=data_02156e50;
d[0]=s[0]; t=s[2]; d[2]=t; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[1]=s[1];
*(s32 *)(d+8)=*(s32 *)(s+8);
d[6]=s[6]; d[7]=s[7]; d[0x12]=s[0x12];
i=0;
do { i++; d[12]=s[12]; s++; d++; } while(i<6);
func_02085348(data_02156e50,0x14);
}

void func_ov000_02199d74(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    void func_ov000_0217e798(M2C_UNK, M2C_UNK, u8 *, u8 *, u8 *);
    void func_ov000_0217d3b8(s32);
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    void func_01ffc328(void *);
    void func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    s32 func_02084464(void *, void *);
    s32 func_0207c2e0(void);
    s32 func_020a641c(s32, s32);
    void func_ov000_02199ce0(void);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_ov000_021df604;
    extern u8 data_ov000_021df7dc[];
    extern u8 data_ov000_021df7d0[];
    extern u8 data_02168f0c[];

    u8 *unit;

    func_ov000_0217e798(arg0, arg1, &arg2, &arg3, &arg4);

    func_ov000_0217d3b8(arg2);

    unit = *(u8 **)((u8 *)*gCurrentMap + 0x52D0);

    if (unit[1] == arg0 && unit[2] == arg1 &&
        (arg2 == 2 || ((u8 *)*gCurrentMap)[0x52D6] != 0)) {

        unit[0xA] |= 0x80;
        func_02072b10(&data_ov000_021df604, 1);
        func_01ffc328(unit);
        func_01ffc4b8(arg0, arg1, (s32)(((u8 *)*gCurrentMap) + 0x5388));
        func_02084464(((u8 *)*gCurrentMap) + 0x5388, data_ov000_021df7dc);

        data_ov000_021df7d0[1] = ((u8 *)*gCurrentMap)[0x52D4];

        *(s32 *)(data_ov000_021df7d0 + 8) = func_0207c2e0();

        data_ov000_021df7d0[4] = (u8)*((s16 *)(((u8 *)*gCurrentMap) + 0x52D8));
        data_ov000_021df7d0[5] = (u8)*((s16 *)(((u8 *)*gCurrentMap) + 0x52DA));
        data_ov000_021df7d0[2] = (u8)arg0;
        data_ov000_021df7d0[3] = (u8)arg1;
        data_ov000_021df7d0[0] = arg2;
        data_ov000_021df7d0[6] = arg3;
        data_ov000_021df7d0[7] = arg4;

        data_ov000_021df7d0[0x12] = (u8)((((u32)unit[0xA] << 25) >> 25) -
                                          func_020a641c((s32)unit,
                                                        (s32)(((u8 *)*gCurrentMap)[0x52D5])));
        data_ov000_021df7d0[0x13] = 1;
    }

    if (data_02168f0c[0] != 0) {
        func_ov000_02199ce0();
        func_02072b10(&data_ov000_021df604, 1);
    }
}

void func_ov000_02199f38(void) {
    M2C_UNK func_02072b10(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021df604;
    func_02072b10(&data_ov000_021df604, 1);
}

void func_ov000_02199f50(s32 a, s32 b, s32 c, s32 d) {
    s32 func_02084464(void *, void *);
    s32 func_0207c2e0(void);
    s32 func_020a641c(s32, s32);
    void func_02084568(s32, s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 data_ov000_021df7dc[];
    extern u8 data_ov000_021df7d0[];
    extern u8 data_02168f0c[];
    func_02084464((u8 *)*gCurrentMap + 0x5388, data_ov000_021df7dc);
    data_ov000_021df7d0[1] = (u8)b;
    *(s32 *)(data_ov000_021df7d0 + 8) = func_0207c2e0();
    data_ov000_021df7d0[0] = (u8)a;
    data_ov000_021df7d0[2] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52dc);
    data_ov000_021df7d0[3] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52de);
    data_ov000_021df7d0[4] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52d8);
    data_ov000_021df7d0[5] = (u8)*(s16 *)((u8 *)*gCurrentMap + 0x52da);
    data_ov000_021df7d0[6] = (u8)c;
    data_ov000_021df7d0[7] = (u8)d;
    if (*(s32 *)((u8 *)*gCurrentMap + 0x52d0) != 0) {
        s32 _r = func_020a641c(*(s32 *)((u8 *)*gCurrentMap + 0x52d0),
                                (u8)*((u8 *)*gCurrentMap + 0x52d5));
        volatile u8 *_u = (volatile u8 *)*(s32 *)((u8 *)*gCurrentMap + 0x52d0);
        data_ov000_021df7d0[0x12] = (((u32)_u[0xa] << 25) >> 25) - _r;
    }
    if (data_02168f0c[0] != 0) {
        func_02084568(a, b, c, d);
    }
}

void func_ov000_0219a064(void) {
extern s32 *gCurrentMap;
extern u8 data_ov000_021df7d0[];
u8 *p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);

if(!p || !((Field7 *)(p+6))->value) return;

if(data_ov000_021df7d0[0]==4) p[11]|=0x40;
else if(data_ov000_021df7d0[2]!=data_ov000_021df7d0[4] || data_ov000_021df7d0[3]!=data_ov000_021df7d0[5]) p[11]&=~0x40;
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_0219a0e0(void) {
extern s32 *gCurrentMap;
s32 func_ov000_021a9164(s32,s16,s16);
s32 x,y;u32 idx;u8 *base=(u8 *)*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
idx=x+M2C_FIELD(base+y*2,u16 *,0x3758);
if((u8)(M2C_FIELD(base+(idx>>3),u8 *,0x5160)&(1<<(idx&7)))&&
M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+(base+x),u8 *,0)!=0){
if(func_ov000_021a9164((u8)M2C_FIELD(base,u16 *,0x52a4),x,y)==0){
base=(u8 *)*gCurrentMap;
M2C_FIELD(base+0x59a4+M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+(base+x),u8 *,0)*14,u8 *,0xb)|=0x40;
}
}
base=(u8 *)*gCurrentMap;
}
}
}
void func_ov000_0219a1f4(void) {
    void func_020c93cc(void);
    void func_ov000_0219b1ac(u16);
    void func_ov000_0219a9b0(void);
    void func_ov000_0219a370(void);
    void func_ov000_0219a418(void);
    void func_ov000_0219a618(void);
    void func_ov000_0219a6c8(void);
    void func_ov000_0219a584(void);
    void func_ov000_0219c444(void);
    void func_ov000_02181c88(void);
    void func_ov000_0219a350(void);
    void func_ov000_0219a8c4(void);
    s32 func_ov000_021a9b84(void);
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 *data_ov000_021df580;

    {
        u8 *map = *(u8 **)gCurrentMap;
        u16 val = *(u16 *)(map + 0x52a4);
        map[0x52d4] = (u8)data_ov000_021aeef4[val];
    }
    {
        u8 *map = *(u8 **)gCurrentMap;
        *(u8 **)(map + 0x52d0) = map + 0x59a4 + map[0x52d4] * 0xe;
    }
    func_020c93cc();
    data_ov000_021df580[0xc] = (*(u8 **)gCurrentMap)[0x5158];
    if ((*(u8 **)gCurrentMap)[0x5159] == 1) {
        data_ov000_021df580[0xd] = 0;
    } else {
        data_ov000_021df580[0xd] = (*(u8 **)gCurrentMap)[0x5158];
    }
    func_ov000_0219b1ac(*(u16 *)(*(u8 **)gCurrentMap + 0x52a4));
    func_ov000_0219a9b0();
    func_ov000_0219a370();
    func_ov000_0219a418();
    func_ov000_0219a618();
    func_ov000_0219a6c8();
    func_ov000_0219a584();
    func_ov000_0219c444();
    func_ov000_02181c88();
    func_ov000_0219a350();
    func_ov000_0219a8c4();
    if (func_ov000_021a9b84() == 1) {
        data_ov000_021df580[0x7] |= 0x04;
    } else {
        data_ov000_021df580[0x7] &= ~0x04;
    }
    data_ov000_021df580[0x7] |= 0x08;
    data_ov000_021df580[0x2] = 0;
    data_ov000_021df580[0x1] = 0;
    data_ov000_021df580[0x0] = 1;
}

#pragma pop
void func_ov000_0219a350(void) {
    extern void *data_ov000_021df578;
    M2C_FIELD(data_ov000_021df578, s8 *, 2) = 0;
    M2C_FIELD(data_ov000_021df578, s8 *, 3) = 0;
}

void func_ov000_0219a370(void) {
    extern s32 *gCurrentMap;
    s32 var_r1;
    void *var_r2;

    var_r1 = 0;
    var_r2 = *gCurrentMap + 0x6C60;
    do {
        M2C_FIELD(var_r2, s8 *, 3) = 0;
        M2C_FIELD(var_r2, s8 *, 4) = 0;
        var_r1 += 1;
        M2C_FIELD(var_r2, s8 *, 5) = 0;
        var_r2 += 6;
    } while (var_r1 < 0x63);
}

s32 func_ov000_0219a3b0(s32 n) {
extern s32 *gCurrentMap;
u8 *p=(u8 *)*gCurrentMap+0x67a4+n*0x8c;
s32 sum=0;
sum+=p[0x11]; sum+=p[0x10]; sum+=p[0x12]; sum+=p[0x13]; sum+=p[0x14]; sum+=p[0x15]; sum+=p[0x16]; sum+=p[0x17];
return sum+1;
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_0219a418(void) {
void func_01ffb554(s32);
void func_01ffb3d0(s32);
M2C_UNK func_01ffada0(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern s32 *gCurrentMap;
extern u8 *data_ov000_021df580;
s32 count=0;
u8 *p;
s32 x,y;
u8 *base;
func_01ffb554((s32)*gCurrentMap+0x2338);
func_01ffb3d0(count);
func_01ffb554((s32)*gCurrentMap+0x1e30);
base=(u8 *)*gCurrentMap;
for(p=base+0x6c60;*p!=0xff;p+=6){
if(M2C_FIELD(base+M2C_FIELD(p,u8 *,1)+M2C_FIELD(base+M2C_FIELD(p,u8 *,2)*2,u16 *,0x3758),s8 *,0x2338)==0){
func_01ffada0(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),1,0x6e,0);
base=(u8 *)*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(M2C_FIELD(base+y*4,s8 **,0x52e8)[x]>=0){
M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16 *,0x3758),u8 *,0x2338)=1;
}
base=(u8 *)*gCurrentMap;
}
}
count++;
}
}
M2C_FIELD(data_ov000_021df580,u8 *,6)=count;
}
#pragma pop
