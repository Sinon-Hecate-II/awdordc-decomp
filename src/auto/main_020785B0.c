/* 10 functions from 0x020785B0 to 0x020793F0 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 x,y,z; } Vec3;
typedef struct { u8 kind:6; u8 side:2; u8 pad[5]; u16 hp:7; u16 rest:9; } RenderUnit;
typedef struct { Vec3 pos; void *unit; s32 kind,frame,variant,side,hp,flags; u8 color; u8 pad[3]; s32 extra; u8 mode; u8 pad2[3]; } UnitRenderContext;
extern u8 data_02141f08[1920], data_02141788[1920];
extern s16 data_020e5b30[2048];
extern u32 data_020edebc[][2];

extern u32 data_027e15bc;
extern u8 data_02140f70[24];

void func_020785b0(void) {
    s32 func_0207cfb8(s32);
    extern s32 *gCurrentMap;
    s32 var_r0;
    if ((s32)(data_027e15bc % 140) < 60) {
        data_02140f70[1] = 0;
    } else {
        data_02140f70[1] = 1;
    }
    if (func_0207cfb8(*gCurrentMap + 0x6EF8) <= 0) {
        var_r0 = 0x10;
    } else {
        var_r0 = 0x18;
    }
    if (var_r0 == 0x10) {
        data_02140f70[1] = 0;
    }
}

void func_0207863c(void) {
    data_02140f70[2] = (data_027e15bc / 12) & 3;
}

#pragma scheduling on
void func_0207866c(void){
void func_02003fc8(s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_02077bb4(s32);
extern s32 *gCurrentMap;
extern u16 data_020eb290[][4];
u32 kind=M2C_FIELD(*gCurrentMap,u8 *,0x5157);
u16 *v=data_020eb290[kind];
*(volatile u32 *)0x4000440=0;
*(volatile u32 *)0x4000454=0;
func_02003fc8(0,192,0,256,-1000,0,4096,1,0);
*(volatile u32 *)0x4000500=1;
*(volatile u32 *)0x4000480=v[0];
*(volatile u32 *)0x400048c=0;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000480=v[1];
*(volatile u32 *)0x400048c=0xc00000;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000480=v[2];
*(volatile u32 *)0x400048c=0xc00100;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000480=v[3];
*(volatile u32 *)0x400048c=0x100;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000504=0;
func_02077bb4(*gCurrentMap+0x6ef8);
*(volatile u32 *)0x4000480=0x7fff;
}

void func_0207877c(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_0207cfb8(s32);
    s32 func_02090158(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020901b0(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern s32 *gCurrentMap;
    s32 temp_r0;
    s32 var_r5;
    s32 var_r6;

    var_r6 = arg2;
    temp_r0 = func_0207cfb8(*gCurrentMap + 0x6EF8);
    var_r5 = 0;
    if (var_r6 != 0) {
        if (var_r6 < 8) {
            var_r6 = 8;
        }
        var_r5 = func_0207ca38(0, 0, 0x7F, var_r6 * temp_r0, 0x1000);
        if (var_r5 > 0x7F) {
            var_r5 = 0x7F;
        } else if (var_r5 < 0) {
            var_r5 = 0;
        }
    }
    if (func_02090158(arg0, var_r5, 0xA) != 0) {
        return;
    }
    if (var_r5 == 0) {
        return;
    }
    func_020901b0(arg0, -1, arg1, var_r5);
}

#pragma scheduling off
void func_02078c60(s32 x,s32 y,s32 angle,s32 kind){
void func_02004078(s32,s32); void func_02079db0(s32,s32,s32,s32,s32,s32);
s32 a,b,c,d,sn,cs; a=(data_02141f08+x*40)[y];b=(data_02141788+x*40)[y];
*(volatile u32 *)0x4000444=0;
if(angle){d=(y<<4)*48+0x180;c=(x<<4)*48+0x180;
cs=data_020e5b30[(angle>>4)*2+1];sn=data_020e5b30[(angle>>4)*2];
*(volatile u32 *)0x4000470=c;*(volatile u32 *)0x4000470=d;*(volatile u32 *)0x4000470=0;
func_02004078(sn,cs);
*(volatile u32 *)0x4000470=-c;*(volatile u32 *)0x4000470=-d;*(volatile u32 *)0x4000470=0;}
*(volatile u32 *)0x4000470=0;*(volatile u32 *)0x4000470=0x300;*(volatile u32 *)0x4000470=0;
func_02079db0(x,y,kind,0,a,b);*(volatile u32 *)0x4000448=1;
}

void func_02078ff4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_020a7d80(void *);
    s32 func_020a7dc4(void *);
    s32 func_020a8604(s32);
    s32 func_020a7d38(void *);
    s32 func_020a7cc8(void *);
    s32 func_020a7ce4(void *);
    s32 func_020d2850(s32, u16, s32);
    s32 func_020a7cb0(void *);
    s32 func_020a7cfc(void *);
    s32 func_020a7d50(void *);
    void func_020791ac(Vec3 *, RenderUnit *, s32, s32, s32, u8);
    extern s32 *gCurrentMap;

    s32 base, flags, kind, vecx, vecy, vecz;
    u16 rowoff;
    u8 val, player;
    u8 *unit;
    Vec3 pos;

    base = *gCurrentMap;
    rowoff = *(u16 *)((u8 *)base + arg1 * 2 + 0x3758);
    val = *(u8 *)((u8 *)base + arg0 + rowoff + 0x508);
    if (val == 0) return;

    flags = 0;
    unit = (u8 *)base + 0x59a4 + (s32)(val * 14);
    player = (u8)((val & 0xc0) >> 6);

    if (func_020a7d80((void *)unit)) flags |= 0x2;
    if (func_020a7dc4((void *)unit)) {
        kind = unit[0] & 0x3f;
        if (func_020a8604(kind)) flags |= 0x8;
        else flags |= 0x4;
    }
    if (func_020a7d38((void *)unit)) flags |= 0x20;
    {
        u8 b = *(u8 *)((u8 *)base + (player + 1) * 0x8c + 0x67c3);
        if (!(b & 0x2)) flags |= 0x1;
    }
    if (func_020a7cc8((void *)unit)) flags |= 0x40;
    if (func_020a7ce4((void *)unit)) flags |= 0x80;
    {
        kind = unit[0] & 0x3f;
        if (func_020d2850(kind, *(u16 *)((u8 *)base + 0x52a4), player + 1)) flags |= 0x100;
    }
    if (func_020a7cb0((void *)unit)) flags |= 0x200;
    if (func_020a7cfc((void *)unit)) flags |= 0x400;
    if (func_020a7d50((void *)unit)) flags |= 0x800;

    vecx = (arg0 * 16 + 8) * 48;
    vecy = (arg1 * 16 + 16) * 48;
    vecz = arg1 * 16 + 1073;

    pos.x = vecx;
    pos.y = vecy;
    pos.z = vecz;
    func_020791ac(&pos, (RenderUnit *)unit, player + 1, flags, arg2, (u8)arg3);
}

#pragma scheduling on
void func_020791ac(Vec3 *arg0,RenderUnit *unit,s32 player,s32 flags,s32 extra,u8 mode){
s32 func_020a7298(s32,u8);s32 func_0207cfb8(s32);s32 func_0207c8ec(s32,s32);
void func_020793f0(UnitRenderContext *);void func_0207971c(Vec3 *,UnitRenderContext *);void func_020796b0(Vec3 *,UnitRenderContext *);
extern s32 *gCurrentMap;
Vec3 pos;UnitRenderContext ctx; s32 variant;
pos=*arg0;
variant=M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67c1)-1;
if(flags&0x200)variant+=4;
if(flags&0x400)variant+=8;
ctx.pos=pos;ctx.unit=unit;
ctx.kind=func_020a7298(unit->kind,M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67cd));
ctx.frame=func_0207cfb8(*gCurrentMap+0x6ef8)<=0?16:24;
ctx.variant=variant;ctx.flags=flags;
ctx.side=unit->side;
ctx.color=M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67cc);
ctx.extra=extra;ctx.mode=mode;
ctx.hp=unit->hp==0?0:func_0207c8ec(unit->hp-1,10)+1;
func_020793f0(&ctx);pos.x-=192;func_0207971c(&pos,&ctx);pos.x+=384;func_020796b0(&pos,&ctx);
}
void func_02079310(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h){
void func_02079db0(s32,s32,s32,s32,s32,s32);s32 func_020cfc0c(s32);
s32 flags; s32 mask,x=0,y=0;
if(f)mask=24;else{x+=16;mask=8;y=x;} flags=data_020edebc[c][0];
if(mask&(u16)flags)x+=func_020cfc0c(e);
if(d){func_02079db0(a,b,c,x,g,h);func_02079db0(a,b,d,y,g,h);return;}
func_02079db0(a,b,c,x,g,h);
}

