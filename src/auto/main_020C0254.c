/* 53 functions from 0x020C0254 to 0x020C1230 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0x34]; void *entries; u8 status[10]; u8 indices[10]; u8 total,count,selection,width; u8 pad50[4]; u16 x,y; } MenuC0634;
typedef struct { u8 pad[0x1420]; u8 tiles[0x2338]; u16 rows[0x40]; u8 pad37d8[0x196c]; u16 width,height; u8 pad5148[0xb9]; u8 visible[0x200]; } MapC10;
extern void *data_02163eec;
extern u8 data_02163ef0[];
typedef struct { s8 x,y,index,flag; s32 value; } CEntry;

u8 func_020c0254(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02129404;
    u8 var_r0;

    if (func_01ffa770(&data_02129404) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* In each graphics bank, clear the low status bits of the first entry and set status bit 0x100. */
void func_020c0278(void) {
    M2C_UNK func_02082cb4();
    M2C_UNK func_0208232c();
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    u16 *volatile ctx0;
    u16 *volatile ctx1;
    u16 *volatile ctx2;
    u16 *volatile ctx3;
    u16 *volatile ctx4;
    s32 savedBank;
    s32 i;

    func_02082cb4();
    savedBank = gCur3DSpriteEngine;
    i = 0;
    do {
        gCur3DSpriteEngine = i == 0 ? data_027e00c8 : data_027e00c4;
        func_0208232c();
        ++i;
        ctx0 = *(u16 **)gCur3DSpriteEngine;
        *ctx0 = *ctx0 & ~0x10;
        ctx1 = *(u16 **)gCur3DSpriteEngine;
        *ctx1 = *ctx1 & ~0x20;
        ctx2 = *(u16 **)gCur3DSpriteEngine;
        *ctx2 = *ctx2 & ~0x40;
        ctx3 = *(u16 **)gCur3DSpriteEngine;
        *ctx3 = *ctx3 & ~0x80;
        ctx4 = *(u16 **)gCur3DSpriteEngine;
        *ctx4 = *ctx4 | 0x100;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
}

void func_020c0374(void) {
    M2C_UNK func_02075fd8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02076198();
    func_02075fd8(0, 0, 0, 0);
    func_02076198();
}

void func_020c0394(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_02076218();
    extern M2C_UNK data_021294c4;
    if (func_02076218() == 0) {
        return;
    }
    func_01ffa42c(&data_021294c4, arg0);
}

s32 func_020c03bc(void *arg0, s32 arg1) {
    return (M2C_FIELD((arg0 + arg1), u8 *, 0x42) * 0x28) + M2C_FIELD(arg0, s32 *, 0x34);
}

s8 func_020c03d4(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), s8 *, 0x38);
}

void func_020c03e0(void *arg0, s32 arg1) {
    void func_0207bc80(u16);
    void func_0207bfb4(void);
    s32 temp_r0;
    void (*temp_r3)(s32, u8, u8);
    temp_r0 = func_020c03bc(arg0, arg1);
    func_0207bc80(M2C_FIELD(temp_r0, u16 *, 0x26));
    func_0207bfb4();
    temp_r3 = M2C_FIELD(temp_r0, void (**)(s32, u8, u8), 0x10);
    if (temp_r3 == 0) return;
    temp_r3(temp_r0, arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c0424(void *arg0, s32 arg1) {
    s32 temp_r0;
    void (*temp_r3)(s32, u8, u8);
    temp_r0 = func_020c03bc(arg0, arg1);
    temp_r3 = M2C_FIELD(temp_r0, void (**)(s32, u8, u8), 8);
    if (temp_r3 == 0) return;
    temp_r3(temp_r0, arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c0454(void *arg0, s32 arg1) {
    s32 temp_r0;
    void (*temp_r3)(s32, u8, u8);
    temp_r0 = func_020c03bc(arg0, arg1);
    temp_r3 = M2C_FIELD(temp_r0, void (**)(s32, u8, u8), 0xC);
    if (temp_r3 == 0) return;
    temp_r3(temp_r0, arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c0484(void *arg0, s32 arg1) {
    void (*callback)(s32, u8, u8);
    s32 entry;
    entry = func_020c03bc(arg0, arg1);
    callback = M2C_FIELD(entry, void (**)(s32, u8, u8), 0x18);
    if (callback == NULL) return;
    callback(entry, (u8)arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c04b4(void *arg0, s32 arg1) {
    void (*callback)(s32, u8, u8);
    s32 entry;
    entry = func_020c03bc(arg0, arg1);
    callback = M2C_FIELD(entry, void (**)(s32, u8, u8), 0x1C);
    if (callback == NULL) return;
    callback(entry, (u8)arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c04e4(void) {
    s32 func_020c05b0(void);
    void func_020c0bb0();
    if (func_020c05b0() == 0) return;
    func_020c0bb0();
}

void func_020c04fc(void *arg0) {
    M2C_UNK func_0209cce4(void (*)(void), M2C_UNK);
    void func_020c03e0(void *, s32);
    void func_020c0424(void *, s32);
    M2C_UNK func_020c0e94(void *);
    M2C_UNK func_020c0f24();
    void *func_020c0fac(void *);

    void func_020c04e4(void);
    s32 var_r4;

    func_020c0f24();
    func_020c0fac(arg0);
    var_r4 = 0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x4D) > 0) {
        do {
            func_020c0424(arg0, var_r4);
            var_r4 += 1;
        } while (var_r4 < (s32) M2C_FIELD(arg0, u8 *, 0x4D));
    }
    func_020c03e0(arg0, M2C_FIELD(arg0, u8 *, 0x4E));
    func_020c0e94(arg0);
    func_0209cce4(&func_020c04e4, 9);
}

void func_020c0564(void *arg0) {
    M2C_UNK func_0209cd00(void (*)(void));
    void func_020c04e4(void);
    void func_020c0f18();
    void func_020c095c(void);
    M2C_UNK func_0207a668();
    M2C_UNK func_020d472c();
    extern void *gCurrentMap;
    void (*callback)(void);
    func_0209cd00(func_020c04e4);
    func_020c0f18(arg0);
    func_020c095c();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), 4);
    if (callback != NULL) callback();
    func_0207a668();
    func_020d472c();
}

s32 func_020c05b0(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02129630;
    return func_01ffa770(&data_02129630);
}

u8 func_020c05c4(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02129630;
    u8 var_r0;

    if (func_01ffa770(&data_02129630) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020c05e8(void) {
    return 0;
}

void func_020c05f0(void) {
    void func_020c0784(void);
    func_020c0784();
}

void func_020c05fc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_020c0634(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void func_020c0a98();
    func_020c0a98();
    func_020c0634(arg0, arg1, arg2, arg3, arg4);
}

s32 func_020c0634(s32 entries,s32 x,s32 y,s32 selection,s32 width) {
void func_020b1b3c(void); s32 func_01ffa3dc(s32 *,s32); void func_020d4704(void);
extern s32 data_02129630;
MenuC0634 *p; u16 height=16; s32 i; s16 n=0; s32 offset;
func_020b1b3c(); p=(MenuC0634 *)func_01ffa3dc(&data_02129630,7); i=0; offset=0;
p->entries=(void *)entries;
for(;;) {
u8 *entry=((u8 *)p->entries)+offset;
u8 *q;
if(entry[0]==255)break;
q=(u8 *)p+n;
p->status[n]=M2C_FIELD(entry,s32 (**)(void),4)();
if(p->status[n]!=2){p->indices[n++]=i;height+=16;}
offset+=40;i++;
}
p->count=n;p->total=i;
if((s32)p->count-1<selection)selection=(u16)(p->count-1);
p->selection=selection;
if(x+16+width>=256)x=256-(width+16);
if(x<0)x=0;
p->width=width;
if(y+height>=192)y=192-height;
if(y<0)y=0;
p->x=x;p->y=y;
func_020d4704();return (s32)p;
}

void func_020c0748(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10017);
    func_020c05fc(arg0, arg1, arg2, 0, arg3);
}

void func_020c0784(void) {
    M2C_UNK func_0209bfa8();
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02129630;
    func_0209bfa8();
    func_01ffa9e4(&data_02129630);
}

void func_020c079c(s32 x,s32 y,s32 w,s32 h,s32 dst,s32 pal,u8 striped){
s32 col,row,t;
for(row=y;row<y+h;row++){
for(col=x;col<x+w;col++){
if(col==x+w-1){if(row==y+h-1)t=0xc01;else if(row==y)t=0x401;else t=0x403;}
else if(col==x){if(row==y+h-1)t=0x801;else if(row==y)t=1;else t=3;}
else if(striped){if(row==y+h-1)t=0x802;else if(row==y)t=6;else if((row-y)&1)t=5;else t=4;}
else {if(row==y+h-1)t=0x802;else if(row==y)t=2;else t=5;}
((u16 *)dst)[row*32+col]=t+((pal&15)<<12);
}
}
}

void func_020c08f8(s32 a,s32 b,s32 c,s32 d,u8 e) {
extern s32 gCur3DSpriteEngine; extern void *gCurrentMap;
void func_020c079c(s32,s32,s32,s32,s32,s32,u8);
void (*cb)(void);
func_020c079c(a,b,c,d,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28),3,e);
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x48);
if(cb)cb();
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
}

void func_020c095c(void) {
extern s32 gCur3DSpriteEngine;extern void *gCurrentMap;
void (*cb)(void);
func_01ff9ce8(2);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
func_01ff9ce8(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);
if(cb)cb();
}

void func_020c09c0(s32 arg0) {
extern M2C_UNK data_02120a20;extern void *gCurrentMap;
func_01ff9e44((u8 *)&data_02120a20+((M2C_FIELD(arg0*0x8c+M2C_FIELD(gCurrentMap,s32 *,0),u8 *,0x67c1)+3)<<5),0x160,0x20);
}

void func_020c0a04(M2C_UNK arg0) {
    M2C_UNK func_0207c780(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0211e0a8;
    func_0207c780(&data_0211e0a8, arg0);
}

void func_020c0a1c(s32 arg0) {
    M2C_UNK func_01ff9e44(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_0211e12c;
    func_01ff9e44(&data_0211e12c, arg0 << 5, 0x20);
}

void func_020c0a3c(s32 arg0) {
    M2C_UNK func_0208ca2c(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    s32 func_020ae22c(M2C_UNK);
    extern s32 gCur3DSpriteEngine;
    func_020c0a04(M2C_FIELD((gCur3DSpriteEngine + (arg0 * 4)), s32 *, 0xC));
    func_020c0a1c(3);
    func_02091d4c(0);
    func_0208ca2c(0x1000, 1, func_020ae22c(9), 2);
}

void func_020c0a88(void) {
    func_020c0a3c(2);
}

void func_020c0a98(void) {
CEntry *p=(CEntry *)data_02163ef0; s32 i;
data_02163eec=p;
for(i=0;i<8;i++){p[i].x=0;p[i].y=0;p[i].index=0;p[i].flag=0;p[i].value=0;}
}

void func_020c0adc(void) {
void *p=(void *)func_020c05b0();
if(!p)return;
M2C_FIELD(data_02163eec,s32 *,4)=M2C_FIELD(p,s32 *,0x34);
M2C_FIELD(data_02163eec,s8 *,2)=M2C_FIELD(p,u8 *,0x4e);
M2C_FIELD(data_02163eec,s8 *,0)=M2C_FIELD(p,s16 *,0x54);
M2C_FIELD(data_02163eec,s8 *,1)=M2C_FIELD(p,s16 *,0x56);
M2C_FIELD(data_02163eec,s8 *,3)=M2C_FIELD(p,u8 *,0x4f);
data_02163eec+=8;
}

#pragma opt_instruction_scheduling off
void func_020c0b40(void) {
M2C_UNK func_020c0634(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);
if(data_02163eec==data_02163ef0)return;
data_02163eec-=8;
func_020c0634(M2C_FIELD(data_02163eec,s32 *,4),M2C_FIELD(data_02163eec,s8 *,0),M2C_FIELD(data_02163eec,s8 *,1),M2C_FIELD(data_02163eec,s8 *,2),M2C_FIELD(data_02163eec,s8 *,3));
}
#pragma opt_instruction_scheduling reset
void func_020c0b88(s8 arg0) {
    extern void *data_02163eec;
    M2C_FIELD(data_02163eec, s8 *, 2) = arg0;
}

s8 func_020c0b9c(void) {extern void *data_02163eec;return M2C_FIELD(data_02163eec,s8 *,2);}

void func_020c0bb0(void *arg0) {
M2C_UNK func_0209c764(u16,u16,u16,M2C_UNK,s32);
M2C_UNK func_020d694c(s32,s32,s32);
s32 func_ov000_0216cd00(s32);
extern void *gCurrentMap;
s32 i=0,x,y,k;s32 j;void *p,*q;u16 t;u8 v;
if((s32)M2C_FIELD(arg0,u8 *,0x4d)<=0)return;
j=0;
do{
p=(void *)func_020c03bc(arg0,i);t=M2C_FIELD(p,u16 *,0x24);
if(t!=0xffff){
x=M2C_FIELD(arg0,s16 *,0x54);y=M2C_FIELD(arg0,s16 *,0x56)+((u32)j<<3);
func_0209c764(t,(u16)(x+2),(u16)y,0,11);
t=M2C_FIELD(p,u16 *,0x24);
if((t!=0)&&(t!=1)){}else{q=*(void **)gCurrentMap;v=M2C_FIELD(M2C_FIELD(q,s32 *,0x52d0)+t,u8 *,12);
if(v){k=func_ov000_0216cd00((s32)q+0x59a4+v*14);if(k!=10)func_020d694c(x+9,y+7,k);}
}}
i++;j+=2;
}while(i<(s32)M2C_FIELD(arg0,u8 *,0x4d));
}

void func_020c0c9c(void *arg0,u8 *arg1) {
extern void *data_02101e84;
s32 old=*arg1; s32 value=old; u16 keys=M2C_FIELD(data_02101e84,u16 *,2);
if(keys&0x40) {if(old==0){if(keys!=M2C_FIELD(data_02101e84,u16 *,0))return;value=M2C_FIELD(arg0,u8 *,0x4d);}value--;}
else if(keys&0x80){if(old==M2C_FIELD(arg0,u8 *,0x4d)-1){if(keys!=M2C_FIELD(data_02101e84,u16 *,0))return;value=-1;}value++;}
if(value!=old){func_020b1c60(value);M2C_FIELD(arg0,u8 *,0x4e)=value;}
else if(M2C_FIELD(data_02101e84,u16 *,0)&1)func_020b2e14(arg1);
else if(M2C_FIELD(data_02101e84,u16 *,0)&2)func_020b2e2c();
}

void func_020c0d50(void *arg0) {
    void func_020c0c9c(void *, u8 *);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x10);
    if (func_020c05c4() == 0) {
        return;
    }
    func_020c0c9c(temp_r4, arg0);
}

s32 func_020c0d78(void *arg0) {
s32 func_ov000_0216aa44(u8,s32);
u8 index=M2C_FIELD(arg0,u8 *,0); void *p=M2C_FIELD(arg0,void **,0x10);
if(!func_020c05c4())return 0;
if(func_ov000_0216aa44(M2C_FIELD(func_020c03bc(p,index),u8 *,0),0))return 0;
if(M2C_FIELD(p+index,u8 *,0x38)==1)func_0208fe30(0x1001d);
else {func_0208fe30(0x10016);func_020c0484(p,index);}
return 1;
}

s32 func_020c0df8(void *arg0) {
u8 index=M2C_FIELD(arg0,u8 *,0); void *p=M2C_FIELD(arg0,void **,0x10);
if(!func_020c05c4())return 0;
func_0209bfa8();func_0208fe30(0x10018);func_020c04b4(p,index);return 1;
}

void func_020c0e38(void *arg0) {
u8 index=M2C_FIELD(arg0,u8 *,0); void *p=M2C_FIELD(arg0,void **,0x10);
if(!func_020c05c4())return;
func_0208fe30(0x10019); func_020c03e0(p,index);
}

void func_020c0e6c(void *arg0) {
u8 index = M2C_FIELD(arg0,u8 *,0);
void *p = M2C_FIELD(arg0,void **,0x10);
if (!func_020c05c4()) return;
func_020c0454(p,index);
}

M2C_UNK func_020c0e94(void *p) {
extern M2C_UNK data_02129608;
void *func_020b22a4(s32,s32,M2C_UNK *,s32);
s32 func_0207c1b4(s32); s32 func_0207c1d8(s32);
M2C_UNK func_020b1c60(); M2C_UNK func_020b204c();
s32 i,y; y=0; i=y;
for(;i<M2C_FIELD(p,u8 *,0x4d);i++) {
void *q=func_020b22a4(M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x56)+y*8,&data_02129608,i);
s32 w=func_0207c1b4(i);
s32 h=func_0207c1d8(i);
M2C_FIELD(q,s16 *,0x18)=w;M2C_FIELD(q,s16 *,0x1a)=h;
M2C_FIELD(q,void **,0x10)=p;y+=h>>3;
}
func_020b1c60(M2C_FIELD(p,u8 *,0x4e));func_020b204c();
}

void func_020c0f18(void) {
    M2C_UNK func_020b2268();
    func_020b2268();
}

M2C_UNK func_020c0f24(void *p) {
extern u8 data_02163f30[];
void func_0207bbc8(void *);void func_0207bbd8(s32,s32,s32,s32);
void func_0207bcc4(u8,u8);void func_0207bdc4(void);void func_0207bf00(s32,s32);
s32 i;u16 v;
func_0207bbc8(data_02163f30);
func_0207bbd8(2,1,0x24,3);
for(i=0;i<M2C_FIELD(p,u8 *,0x4d);i++) {
v=M2C_FIELD(func_020c03bc(p,i),u16 *,0x26);
func_0207bcc4((u8)v,(u8)func_020c03d4((s32)p,i));
}
func_0207bdc4();
func_0207bf00(M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x56));
}

void *func_020c0fac(void *arg0) {
void *func_020ab1c4(s32);
void func_020aab24(void *,s32,s32,s32,s32);
void func_02088e84(void *,s16,s16,s16,s32);
u32 func_020aae10(void *); u32 func_020aae44(void *);
void func_02087d84(void *,s32,s32,s32,u16,u16);
void func_020ab150(void *,s16); void func_020aad18(void *);void func_02088f1c(void *);
void *unit; s16 y; s16 x; u32 a,b; u32 cond;
unit=func_020ab1c4((s32)arg0);
func_020aab24(unit,2,0x120,3,1);
func_02088e84(unit,0xe0,0xa0,0x100,0xa0);
cond=M2C_FIELD(M2C_FIELD(unit,void **,0x64),u8 *,0x12)!=0?1:0;
if(cond & 0xff){
y=M2C_FIELD(unit,s16 *,0x52);x=M2C_FIELD(unit,s16 *,0x50);
a=func_020aae10(unit);b=func_020aae44(unit);
func_02087d84(M2C_FIELD(unit,void **,0x64),1,x,y,(u16)a,(u16)b);
}
func_020ab150(unit,2);func_020aad18(unit);func_02088f1c(unit);return unit;
}

void func_020c1078(void) {
    s8 func_020a2360(s32);
    extern s8 data_0216408c;
    s32 var_r4;
    s8 *var_r5;
    s8 temp_r0;

    var_r5 = &data_0216408c;
    var_r4 = 0;
    do {
        temp_r0 = func_020a2360(var_r4);
        var_r4 += 1;
        *var_r5 = temp_r0;
        var_r5 += 1;
    } while (var_r4 < 5);
}

void *func_020c10a4(s32 x,s32 y,s32 flag){
extern void *data_027e0058;extern u8 data_02163f9c[];extern s8 data_0216408c;extern u16 data_02129728[],data_021296e8[],data_0211e538[];
MapC10 *p;u32 idx; s32 k,n,v;
if(x>=0 && y>=0){
p=*(void**)data_027e0058;
if(x<p->width&&y<p->height)goto valid;
}
return data_02163f9c;
valid:
idx=x+p->rows[y];
{u8 *tiles=p->tiles; v=tiles[idx];}
n=v&31;k=((u8*)&data_0216408c)[v>>5];
if(flag && (u8)(p->visible[(u32)idx>>3]&(1<<(idx&7)))==0){if(n!=15)k=0;}
v=data_02129728[n];
if(n==27 || (u32)n==28)k=0;
return &data_0211e538[data_021296e8[v+k]];
}

void func_020c1184(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
}

void func_020c1190(void) {

}

void func_020c1194(void *arg0) {
    M2C_UNK func_020c1454(s32);
    M2C_UNK func_020c15ec(s32);
    M2C_UNK func_020c1768(s32);
    s16 temp_r2;
    s32 temp_r1;

    temp_r2 = M2C_FIELD(arg0, s16 *, 0x6C);
    M2C_FIELD(arg0, s16 *, 0x6C) = (s16) (temp_r2 + 1);
    temp_r1 = temp_r2 & 0x3F;
    switch (temp_r1) {                              /* irregular */
    case 0:
        func_020c15ec(M2C_FIELD(arg0, s32 *, 0x34));
        return;
    case 1:
        func_020c1768(M2C_FIELD(arg0, s32 *, 0x34));
        return;
    case 22:
        func_020c1454(M2C_FIELD(arg0, s32 *, 0x34));
        return;
    }
}

s32 func_020c11e4(s32 a) {
extern M2C_UNK data_02129690;
s32 func_01ffa770(M2C_UNK *);
M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
void *p;
if(func_01ffa770(&data_02129690))return 0;
p=(void *)func_01ffa3dc(&data_02129690,7);
M2C_FIELD(p,s32 *,0x34)=a;
return 1;
}

void func_020c121c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02129690;
    func_01ffa9e4(&data_02129690);
}

