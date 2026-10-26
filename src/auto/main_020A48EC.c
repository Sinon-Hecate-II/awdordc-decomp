/* 26 functions from 0x020A48EC to 0x020A5878 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 a,b,c,d; } Unk020APosition;
typedef struct { u8 pad[5]; u8 player:3; u8 rest:5; } Unk020APlayer;
typedef struct { u8 x,y; u16 a:3; u16 b:3; u16 type:4; u16 rest:6; u8 value; u8 player:3; u8 enabled:1; u8 mode:4; u8 extra,last; } Unk020ABaseEntry;
typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

Unk020AEntry *func_020a48ec(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u8 g,s32 h) {
 extern s32 *data_027e0058;
 Unk020ABaseEntry *p=(Unk020ABaseEntry *)(*data_027e0058+0x58a4);
 while(p->type)p++;
 p->x=a;p->y=b;
 p->a=(u16)c;p->b=(u16)d;p->type=(u16)e;
 p->player=(u8)f;p->enabled=g;
 p->value=h;
 return (Unk020AEntry*)p;
}

M2C_UNK func_020a49cc(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u8 g,s32 h,s32 i,s32 j,s32 k,s32 l) {
Unk020AEntry *func_020a48ec(s32,s32,s32,s32,s32,s32,u8,s32);
Unk020AEntry *p=func_020a48ec(a,b,c,d,e,f,g,h);u16 top=(u16)k;u16 kind=(u16)j;u8 last=l;p->mode=(u8)i;p->top=top;p->kind=kind;M2C_FIELD(p,s8 *,6)=i;p->last=last;return (s32)p;}

void func_020a4a68(Unk020AEntry *p) {while(p->type){*p=p[1];p++;}}

s32 func_020a4ab0(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x2000;
    case 1:
        return 0;
    case 2:
        return -0x2000;
    default:
        return 0;
    }
}

void func_020a4af0(s32 arg0, s32 arg1, s32 arg2) {
    func_020a49cc(arg0 - 1, arg1 - 1, 3, 3, 4, arg2, 0, 0x63, 1, 1, 0, 0x32);
}

void func_020a4b48(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_020a49cc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, u8, s32, s32, s32, s32, s32);
    func_020a49cc(arg0, arg1, 1, 1, 5, arg2, 0, 0, arg3, arg4, 0, 0x32);
}

void func_020a4b94(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020a49cc(arg0, arg1, 1, 1, 5, arg2, 0, 0, arg3, arg4, 1, 0x32);
}

void func_020a4be0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020a49cc(arg0, arg1, 1, 1, 6, arg2, 1, 0x63, arg3, arg4, 3, 0x50);
}

void func_020a4c30(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020a49cc(arg0, arg1, 1, 1, 7, arg2, 1, 0x63, arg3, arg4, 1, 0x50);
}

u8 func_020a4c7c(Unk020AEntry *p) {if(!p)return 0;switch(p->type){case 4:case 6:case 7:return p->value!=0;case 0:return 0;default:return 1;}}

s32 func_020a4ce8(s32 a) {
extern s32 *data_027e0058;
Unk020AEntry *p=(Unk020AEntry *)(*data_027e0058+0x58a4);s32 n=0;
while(p->type){if(p->type==a){if(func_020a4c7c(p))n++;}p++;}return n!=0;
}

void func_020a4d58(void) {
    M2C_UNK func_020a4528();
    func_020a4528();
}

void func_020a4d64(void) {
    extern s32 data_0215be08;
    data_0215be08 = 0;
}

void func_020a4d78(s32 a,s32 b,s32 c,s32 d) {
extern Unk020APosition *data_0215be04; extern s32 data_0215be08;
Unk020APosition *p=data_0215be04;
p[data_0215be08].c=a;p[data_0215be08].d=b;p[data_0215be08].a=c;p[data_0215be08].b=d;data_0215be08++;
}

s32 func_020a4dd0(void) {
    return 1;
}

s32 func_020a4dd8(void) {
    return 1;
}

void func_020a54c4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

void func_020a54d0(void *a) {void func_01ffa574();extern s32 data_0215be08;if(M2C_FIELD(a,s16 *,84)!=data_0215be08)return;func_01ffa574(a);}

void func_020a561c(void *arg0) {
    extern s32 *data_027e0058;
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (*data_027e0058 + 0x58A4);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x44) = 0;
}

void func_020a5648(void) {
extern s32 *data_027e0058;
Unk020AEntry *p=(Unk020AEntry *)(*data_027e0058+0x58a4);
while(p->type){if(func_020a4c7c(p)&& ((Unk020APlayer *)p)->player==M2C_FIELD(*data_027e0058,u16 *,0x52a4)){
switch(p->type){case 4:case 5:case 6:case 7: M2C_FIELD(p,s8 *,6)-=1;break;}
}p++;}
}

