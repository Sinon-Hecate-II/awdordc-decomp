/* 15 functions from 0x021959CC to 0x0219694C (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; } UnitKind959;

#pragma opt_propagation off
s32 func_ov000_021959cc(s32 x,s32 y,s32 data,s32 radius){
s32 func_ov000_021a93b0(s32,s32,s32);s32 func_020d27c0(s32);s32 func_ov000_021a96a8(M2C_UNK,M2C_UNK,s32);
extern void **gCurrentMap;
s32 sy;
s32 left;
s32 bottom;
s32 i,dy,top,right,ny;
void *base;
s32 d;
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
base=*gCurrentMap;right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;if(y+radius<bottom)bottom=y+radius;
for(;top<=bottom;top++)for(i=left;i<=right;i++){
dy=y-top;ny=top-y;sy=top;
d=0;if(x-i>0)d+=x-i;else d+=i-x;
if(dy>0)d+=dy;else d+=ny;
if(d>=0&&d<=radius){
base=*gCurrentMap;
if(func_ov000_021a93b0(M2C_FIELD(base,u16 *,0x52a4),(s16)i,(s16)sy)!=0)continue;
base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)top<<1),u16 *,0x3758));
if(!d)continue;
if(func_020d27c0(d)!=0)continue;
base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)top<<1),u16 *,0x3758));
if(func_ov000_021a96a8(data,((UnitKind959 *)((u8 *)base+d*14+0x59a4))->kind,0)>=30)return 1;
}
}
return 0;
}
#pragma opt_propagation reset
s32 func_ov000_02195b80(s16 *a) { return 0; }

void func_ov000_02195ea4(void) {
    s32 func_ov000_021a98e4(u32);
    s32 func_ov000_02195b80(s16 *);
    s32 func_ov000_02195788(s16 *);
    s32 func_ov000_0217e6bc(s16,s16);
    void func_ov000_0218a9ac(s16,s16);
    extern void **gCurrentMap;
    s16 sp0[2];
    if (func_ov000_021a98e4((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26)==1) {
        if (func_ov000_02195b80(sp0)==0) return;
    } else {
        if (func_ov000_02195788(sp0)==0) return;
    }
    if (func_ov000_0217e6bc(sp0[0],sp0[1])==0) return;
    func_ov000_0218a9ac(sp0[0],sp0[1]);
}

s32 func_ov000_02195f1c(s16 *arg0) {
    s32 func_020d243c(u16);
    s32 func_01ffada0(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];

    u8 *map;
    u8 *unit8;
    u16 player;
    u8 *entry;
    s8 *grid;
    s8 cell;

    map = (u8 *)*gCurrentMap;
    unit8 = (u8 *)*(void **)(map + 0x52d0);
    if (data_ov000_021b5c0f[((u32)(unit8[0] << 26) >> 26) * 0x70] & 0x20) {
        return 0;
    }
    if (func_020d243c(*(u16 *)(map + 0x52a4)) == 0) {
        return 0;
    }

    map = (u8 *)*gCurrentMap;
    unit8 = (u8 *)*(void **)(map + 0x52d0);
    func_01ffada0(unit8[1], unit8[2], (u32)(unit8[0] << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    player = *(u16 *)(map + 0x52a4);
    entry = map + 0x67a4 + player * 0x8c;
    grid = *(s8 **)(map + ((u32)(entry[0x2c] << 25) >> 23) + 0x52e8);
    cell = grid[entry[0x2b] & 0x7f];
    if (cell < 0) {
        return 0;
    }
    arg0[0] = (s16)(entry[0x2b] & 0x7f);

    map = (u8 *)*gCurrentMap;
    player = *(u16 *)(map + 0x52a4);
    entry = map + 0x67a4 + player * 0x8c;
    arg0[1] = (s16)(entry[0x2c] & 0x7f);

    return 1;
}

void func_ov000_0219604c(void) {
    s32 func_ov000_02195f1c(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02195f1c(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_02196084(s16 *arg0) {
    void func_ov000_02179be0(void);
    void func_ov000_02179d3c(void);
    s32 func_ov000_02179e48(s16 *);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 f8;
    s8 cell;
    s16 sp0[2];

    func_ov000_02179be0();
    func_ov000_02179d3c();

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    if (((u32)(f8 << 26) >> 26) == 0x3f) {
        u8 v = *(u8 *)((u8 *)unit + 0x01);
        f8 = (f8 & ~0x3f) | (v & 0x3f);
        *(u16 *)((u8 *)unit + 0x08) = f8;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    {
        u8 v = *(u8 *)((u8 *)unit + 0x02);
        f8 = (f8 & ~0xfc0) | (((u32)v << 26) >> 20);
    }
    *(u16 *)((u8 *)unit + 0x08) = f8;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    cell = ((s8 **)(map + 0x52e8))[((u32)(f8 << 20) >> 26)][((u32)(f8 << 26) >> 26)];
    if (cell < 0) {
        return 0;
    }

    sp0[0] = (s16)(((u32)(f8 << 26) >> 26));
    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    sp0[1] = (s16)(((u32)(f8 << 20) >> 26));

    if (func_ov000_02179e48(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_0219619c(void) {
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196084(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_021961d4(s16 *arg0) {
    s32 func_01ffada0(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 f8;
    s8 cell;
    u32 low;
    u32 kind;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    func_01ffada0(*(u8 *)((u8 *)unit + 1), *(u8 *)((u8 *)unit + 2),
                   (u32)(*(u8 *)((u8 *)unit) << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    if (((u32)(f8 << 26) >> 26) == 0x3f) {
        u8 v = *(u8 *)((u8 *)unit + 1);
        f8 = (f8 & ~0x3fu) | (v & 0x3fu);
        *(u16 *)((u8 *)unit + 8) = f8;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    {
        u8 v = *(u8 *)((u8 *)unit + 2);
        f8 = (f8 & ~0xfc0u) | (((u32)v << 26) >> 20);
    }
    *(u16 *)((u8 *)unit + 8) = f8;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    low = ((u32)f8 << 26) >> 26;
    kind = ((u32)f8 << 20) >> 26;
    cell = *(s8 *)((u8 *)*(void **)(map + 0x52e8 + kind * 4) + low);
    if (cell < 0) {
        return 0;
    }

    arg0[0] = (s16)low;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    arg0[1] = (s16)(((u32)f8 << 20) >> 26);

    return 1;
}

void func_ov000_021962f8(void) {
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_021961d4(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_02196330(void) {
    s32 func_020a32f4(s32);
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    extern void **gCurrentMap;
    s32 var_r5;

    var_r5 = 1;
loop_1:
    if ((func_020d1938(var_r5) != 0) && (func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), var_r5) == 0) && (func_020a32f4(var_r5) != 0)) {
        return 1;
    }
    var_r5 += 1;
    if (var_r5 >= 5) {
        return 0;
    }
    goto loop_1;
}

s32 func_ov000_02196398(s16 *arg0) {
    void func_ov000_02179be0();
    void func_ov000_02179d3c();
    s32 func_ov000_021786a8(s16 *);
    s32 func_ov000_02179e48(s16 *);
    s16 sp0[2];

    func_ov000_02179be0();
    func_ov000_02179d3c();
    if (func_ov000_021786a8(sp0) == 0) {
        return 0;
    }
    if (func_ov000_02179e48(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_021963f8(void) {
    s32 func_ov000_02196398(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196398(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
s32 func_ov000_02196430(s16 *arg0) {
    s32 func_ov000_02194ab8(s16 *);
    s32 func_ov000_021a9c28(void);
    s32 func_ov000_021954dc(s16 *);
    s32 func_ov000_02195574(s16 *);
    s32 func_ov000_02195788(s16 *);
    s32 func_020d243c(u16);
    s32 func_ov000_02195f1c(s16 *);
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_02196330(void);
    s32 func_ov000_02196398(s16 *);
    extern void **gCurrentMap;
    struct Nib { unsigned char lo : 4; unsigned char hi : 4; };

    u8 *map;
    u8 *unit;
    u32 key;

    map = (u8 *)*gCurrentMap;
    unit = (u8 *)*(void **)(map + 0x52d0);
    key = ((struct Nib *)(unit + 0x0b))->lo;

    switch (key) {
    case 0:
    case 1:
        if (func_ov000_02194ab8(arg0) == 0) {
            return 0;
        }
        break;
    case 2:
        if (func_ov000_021a9c28() == 1) {
            if (func_ov000_021954dc(arg0) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02194ab8(arg0) == 0) {
                return 0;
            }
        }
        break;
    case 3:
        if (func_ov000_02195574(arg0) == 0) {
            return 0;
        }
        break;
    case 4:
        if (func_ov000_02195788(arg0) == 0) {
            return 0;
        }
        break;
    case 5: {
        u16 player = *(u16 *)(map + 0x52a4);
        if (func_020d243c(player) == 1) {
            if (func_ov000_02195f1c(arg0) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02195788(arg0) == 0) {
                return 0;
            }
        }
        break;
    }
    case 7:
    case 9:
        if (func_ov000_02196084(arg0) == 0) {
            return 0;
        }
        break;
    case 8:
        if (func_ov000_021961d4(arg0) == 0) {
            return 0;
        }
        break;
    case 6:
        arg0[0] = (s16)unit[1];
        arg0[1] = (s16)(((u8 *)*(void **)(((u8 *)*gCurrentMap) + 0x52d0))[2]);
        break;
    case 10:
        if (func_ov000_02196330() == 1) {
            if (func_ov000_02196398(arg0) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02194ab8(arg0) == 0) {
                return 0;
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma opt_strength_reduction off
void func_ov000_021965dc(void) {
extern void **gCurrentMap; extern u8 **data_ov000_021df580;
s32 func_ov000_021a98e4(u32); s32 func_020a76d4(void *);
void func_ov000_02179be0(void); void func_ov000_02179d3c(void);
s32 func_020d27ec(s32,u8); s32 func_ov000_0217d000(u32,s32);
s32 func_ov000_02179e48(s16 *); s32 func_ov000_0217e6bc(s16,s16); void func_ov000_0218a9ac(s16,s16);
s32 limit; s32 flags; s32 best=0x7fff; s32 y,x; s16 cand[2];
if(func_ov000_021a98e4(((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->kind)==1)
limit=func_020a76d4(M2C_FIELD(*gCurrentMap,void **,0x52d0))+M2C_FIELD(data_ov000_021df580,u8 *,5);
else limit=0;
func_ov000_02179be0(); func_ov000_02179d3c();
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8)[x]<0)continue;
flags=M2C_FIELD((u8 *)*gCurrentMap+x+M2C_FIELD((u8 *)*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420);
if(!(flags&0xe0))continue;
if(func_020d27ec(M2C_FIELD(*gCurrentMap,s16 *,0x52a8),(u8)flags)==1)continue;
if(!func_ov000_0217d000(((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->kind,flags))continue;
if(best<=limit){
if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8)[x]>limit)continue;
if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8)[x]>=best)goto accept;
continue;
}else if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8)[x]>best)continue;
accept:
cand[0]=x;cand[1]=y;
best=M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8)[x];
}}
if(best==0x7fff)return;
if(!func_ov000_02179e48(cand))return;
if(!func_ov000_0217e6bc(cand[0],cand[1]))return;
func_ov000_0218a9ac(cand[0],cand[1]);
}
#pragma opt_strength_reduction reset
void func_ov000_021967fc(void) {
s32 func_ov000_021a9934(u32,u32); void func_ov000_02179be0(void);void func_ov000_02179d3c(void);s32 func_ov000_0217e6bc(s16,s16);void func_ov000_0218a9ac(s16,s16);
extern void **gCurrentMap;extern u8 **data_ov000_021df580;
s32 best=0x7fff; s16 sx,sy; s32 cols,t,x,y; s16 row;u8 *base; s8 *grid,*p;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<29)>>29)&4))return;
if(!func_ov000_021a9934(24,((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->kind))return;
func_ov000_02179be0();func_ov000_02179d3c();
base=*gCurrentMap;
y=0; if((s32)M2C_FIELD(base,u16 *,0x5146)>0) do {
cols=M2C_FIELD(base,u16 *,0x5144);
if(cols<=0)goto rowend;
grid=M2C_FIELD(base+y*4,s8 **,0x52e8);p=grid;
row=y;x=0; do {
if(*p<0)goto next;
t=M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+base+x,u8 *,0x1420);
if((t&0xe0)==0 && (t&31)==19) {
best=grid[x];sx=x;sy=row;
}
next: x++;p++;
}while(x<cols); rowend:y++; }while(y<(s32)M2C_FIELD(base,u16 *,0x5146));
if(best==0x7fff)return;
if(!func_ov000_0217e6bc(sx,sy))return;
func_ov000_0218a9ac(sx,sy);
}

