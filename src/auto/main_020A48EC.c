/* 26 functions from 0x020A48EC to 0x020A5878 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 a,b,c,d; } Unk020APosition;
typedef struct { u8 pad[5]; u8 player:3; u8 rest:5; } Unk020APlayer;
typedef struct { u8 x,y; u16 a:3; u16 b:3; u16 type:4; u16 rest:6; u8 value; u8 player:3; u8 enabled:1; u8 mode:4; u8 extra,last; } Unk020ABaseEntry;
typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

Unk020AEntry *func_020a48ec(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u8 g,s32 h) {
 extern s32 *gCurrentMap;
 Unk020ABaseEntry *p=(Unk020ABaseEntry *)(*gCurrentMap+0x58a4);
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
extern s32 *gCurrentMap;
Unk020AEntry *p=(Unk020AEntry *)(*gCurrentMap+0x58a4);s32 n=0;
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

#pragma opt_strength_reduction off
void func_020a4de0(Unk020AEntry *a) {
extern s32 *gCurrentMap;extern u8 data_ov000_021b5bfc[];
void func_01ffb554(s32);void func_01ffb3d0(s32);void func_01ffb734(s32,s32,s32,s8);
s32 func_020d273c(s32,s32);s32 func_ov000_021a947c(s32,s32,s32);s32 func_020a600c(s32);
s32 dx,dy;
u16 bx,by;
u8 *unit;
u32 best;
s32 n,y,x,bestId;
u32 score;
u8 ids[4],*out;
s32 map,i,id;
u16 row;
u8 *scan,*cell;
func_01ffb554(*gCurrentMap+0x1e30);func_01ffb3d0(-1);
dx=func_020a4dd0();dy=func_020a4dd8();
func_01ffb734(M2C_FIELD(a,u8 *,0)+dx,M2C_FIELD(a,u8 *,1)+dy,5,0);
n=0;out=ids;
do{
bestId=0;best=0;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(M2C_FIELD(M2C_FIELD(map+y*4,s8 **,0x52e8),s8 *,x)<0)continue;
row=M2C_FIELD(map+y*2,u16 *,0x3758);
id=M2C_FIELD(row+(map+x),u8 *,0);
if(!id)continue;
if(func_020d273c(M2C_FIELD(map,u16 *,0x52a4),(id>>6)+1)==1)continue;
if(!func_ov000_021a947c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),x,y))continue;
i=0;
if(n>0){map=*gCurrentMap;row=M2C_FIELD(map+y*2,u16 *,0x3758);id=M2C_FIELD(row+(map+x),u8 *,0);scan=ids;
do{if(*scan==id)break;scan++;i++;}while(i<n);}
if(i!=n)continue;
map=*gCurrentMap;
id=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
unit=(u8 *)(map+0x59a4+id*14);
if(M2C_FIELD(unit,u16 *,4)&32)continue;
if(!func_020a600c(id))continue;
score=M2C_FIELD(data_ov000_021b5bfc+((u32)(unit[0]<<26)>>26)*112,u16 *,4)*((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25);
if(best>score)continue;
bx=(u16)x;by=(u16)y;best=score;
map=*gCurrentMap;
row=M2C_FIELD(map+y*2,u16 *,0x3758);
bestId=M2C_FIELD(row+(map+x),u8 *,0);
}}
if(!bestId)break;
*out++=bestId;
func_020a4d78(bx,by,bestId,M2C_FIELD(a,s8 *,7));
n++;
}while(n<4);
if(n)return;
func_020a4d64();
}
#pragma opt_strength_reduction reset
void func_020a5080(Unk020ABaseEntry *a){
extern s32 *gCurrentMap;void func_01ffb554(s32);void func_01ffb3d0(s32);void func_01ffb80c(s32,s32,s32,s32);
s32 found=0,x,y,p;u8 id;
func_01ffb554(*gCurrentMap+0x1e30);func_01ffb3d0(-1);func_01ffb80c(a->x,a->y,(u32)(M2C_FIELD(a,u16 *,2)<<16)>>30,0);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
p=*gCurrentMap;
if(M2C_FIELD(((s8 **)(p+0x52e8))[y],s8 *,x)>=0){
id=M2C_FIELD(((u16 *)(p+0x3758))[y]+(p+x),u8 *,0x508);
if(id){func_020a4d78((u16)x,(u16)y,id,M2C_FIELD(a,s8 *,7));found=1;}
}
}}
if(!found)func_020a4d64();
}

void func_020a51a4(Unk020ABaseEntry *p) {
extern s32 *gCurrentMap; void func_01ffb554(s32);void func_01ffb3d0(s32);void func_01ffb918(s32,s32,s32,s8,u8);s32 func_ov000_021aab4c(void *,s32,s32,s32,s32,s32);void func_020a4d64(void);
s16 pos[2];s32 map;register s32 left;register s32 right;register s32 xx;register s32 yy;register s32 bottom;register s32 top;register s32 dist;
func_01ffb554(*gCurrentMap+0x1e30);func_01ffb3d0(-1);
func_01ffb918(p->x,p->y,(u32)(M2C_FIELD(p,u16 *,2)<<16)>>30,0,0);
if(!func_ov000_021aab4c(pos,p->player,0,6,2,M2C_FIELD(p,s8 *,7))){func_020a4d64();return;}
func_020a4d78((u16)pos[0],(u16)pos[1],0,0);
left=pos[0]-2;if(left<0)left=0;
top=pos[1]-2;if(top<0)top=0;
right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(pos[0]+2<right)right=pos[0]+2;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(pos[1]+2<bottom)bottom=pos[1]+2;
for(yy=top;yy<=bottom;yy++){for(xx=left;xx<=right;xx++){
dist=0;if(pos[0]-xx>0)dist+=pos[0]-xx;else dist+=xx-pos[0];
if(pos[1]-yy>0)dist+=pos[1]-yy;else dist+=yy-pos[1];
if(dist>=0 && dist<=2){u8 c;s32 mm=*gCurrentMap;c=M2C_FIELD(((u16 *)mm)[yy+0x1bac]+(mm+xx),u8 *,0x508);if(c)func_020a4d78((u16)xx,(u16)yy,c,M2C_FIELD(p,s8 *,7));}
}}
}

s32 func_020a5364(Unk020AEntry *p, s32 color, s32 arg2) {
    void func_01ffb734(s32, s32, s32, s8);
    void func_01ffb80c(s32, s32, s32, s32);
    void func_01ffb918(s32, s32, s32, s8, u8);
    s32 func_020a4dd0(void);
    s32 func_020a4dd8(void);
    extern s32 *gCurrentMap;
    Unk020ABaseEntry *bp = (Unk020ABaseEntry *)p;
    if (!func_020a4c7c(p)) return 0;
    {
        u16 hdr = M2C_FIELD(p, u16 *, 2);
        u32 mode = ((u32)hdr << 22) >> 28;
        switch (mode) {
        case 4: {
            s32 dx = func_020a4dd0();
            s32 dy = func_020a4dd8();
            func_01ffb734(bp->x + dx, bp->y + dy, 5, color);
            return 1;
        }
        case 5: {
            u32 m = ((u32)hdr >> 14) & 3;
            func_01ffb80c(bp->x, bp->y, m, color);
            return 1;
        }
        case 6: {
            u32 m = ((u32)hdr >> 14) & 3;
            s32 *context = (s32 *)*gCurrentMap;
            s32 *inner = (s32 *)*context;
            u8 extra = M2C_FIELD(p, u8 *, 5);
            u16 thr = M2C_FIELD(inner, u16 *, 0x52a4);
            if (thr < (extra & 7)) {
                func_01ffb918(bp->x, bp->y, m, color, arg2);
            } else {
                s32 r = ((s32)m + 1) % 3;
                func_01ffb80c(bp->x, bp->y, r, color);
            }
            return 1;
        }
        case 7: {
            u32 m = ((u32)hdr >> 14) & 3;
            func_01ffb918(bp->x, bp->y, m, color, arg2);
            return 1;
        }
        default:
            return 0;
        }
    }
}

void func_020a54c4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

void func_020a54d0(void *a) {void func_01ffa574();extern s32 data_0215be08;if(M2C_FIELD(a,s16 *,84)!=data_0215be08)return;func_01ffa574(a);}

void func_020a54f4(void *a){
M2C_UNK func_01ffa8c4(void *,s32);void *func_020a45f8(s16,s16);
M2C_UNK func_020b6f98(s16,s16,s32,void *);M2C_UNK func_020b7138(s16,s16,s16,s16,s32,void *);M2C_UNK func_020b7294(s16,s16,u32,s32,void *);
extern Unk020APosition *data_0215be04;
Unk020APosition *base=data_0215be04,*p,*q; s32 i=0,offset;s16 n,m;void *entry;
while(base[i].a==0)i++;
n=M2C_FIELD(a,s16 *,0x54);offset=n*8;if(M2C_FIELD((u8 *)base+offset,u16 *,0))return;p=(Unk020APosition *)((u8 *)base+i);
switch(p->b){
default:break;
case 4:func_020b6f98((s16)p->c,(s16)p->d,n+1,a);break;
case 6:case 7:
entry=func_020a45f8((s16)p->c,(s16)p->d);
m=M2C_FIELD(a,s16 *,0x54);q=&base[m];
func_020b7294((s16)q->c,(s16)q->d,(u32)(M2C_FIELD(entry,u16 *,2)<<16)>>30,m+1,a);break;
case 5:q=&base[n+1];func_020b7138((s16)p->c,(s16)p->d,(s16)q->c,(s16)q->d,n+2,a);
M2C_FIELD(a,s16 *,0x54)++;break;
}
M2C_FIELD(a,s16 *,0x54)++;func_01ffa8c4(a,0);
}

void func_020a561c(void *arg0) {
    extern s32 *gCurrentMap;
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (*gCurrentMap + 0x58A4);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x44) = 0;
}

void func_020a5648(void) {
extern s32 *gCurrentMap;
Unk020AEntry *p=(Unk020AEntry *)(*gCurrentMap+0x58a4);
while(p->type){if(func_020a4c7c(p)&& ((Unk020APlayer *)p)->player==M2C_FIELD(*gCurrentMap,u16 *,0x52a4)){
switch(p->type){case 4:case 5:case 6:case 7: M2C_FIELD(p,s8 *,6)-=1;break;}
}p++;}
}

void func_020a5700(void *arg0) {
    extern s32 *gCurrentMap;
    void func_020a4d64(void);
    u8 func_020a4c7c(Unk020AEntry *);
    void func_020a4d78(s32, s32, s32, s32);
    void func_020a4de0(Unk020AEntry *);
    void func_020a5080(Unk020ABaseEntry *);
    void func_020a51a4(Unk020ABaseEntry *);
    s32 func_01ffa8c4(void *, s32);
    Unk020AEntry *entry;
    s32 type;
    func_020a4d64();
    entry = (Unk020AEntry *)M2C_FIELD(arg0, s32 *, 0x34);
    type = entry->type;
    if (type == 0) {
        func_01ffa8c4(arg0, 1);
        return;
    }
eval:
    if (func_020a4c7c(entry) == 0) goto advance;
    {
        s32 *context = (s32 *)*gCurrentMap;
        s32 *inner = (s32 *)*context;
        u16 thr = M2C_FIELD(inner, u16 *, 0x52a4);
        Unk020ABaseEntry *bp = (Unk020ABaseEntry *)entry;
        if (thr != bp->player) goto advance;
        if ((s8)M2C_FIELD(entry, u8 *, 6) != 0) goto advance;
        switch (type) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        default:
            goto advance;
        case 5: {
            u8 x = M2C_FIELD(entry, u8 *, 0);
            u8 y = M2C_FIELD(entry, u8 *, 1);
            func_020a4d78(x, y, 0, type);
            func_020a4de0(entry);
            M2C_FIELD(entry, u8 *, 6) = (u8)entry->kind;
            M2C_FIELD(arg0, s32 *, 0x34) = (s32)entry + 8;
            return;
        }
        case 6: {
            u8 x = M2C_FIELD(entry, u8 *, 0);
            u8 y = M2C_FIELD(entry, u8 *, 1);
            func_020a4d78(x, y, 0, type);
            func_020a5080((Unk020ABaseEntry *)entry);
            M2C_FIELD(entry, u8 *, 6) = (u8)entry->kind;
            M2C_FIELD(arg0, s32 *, 0x34) = (s32)entry + 8;
            return;
        }
        case 7: {
            u8 x = M2C_FIELD(entry, u8 *, 0);
            u8 y = M2C_FIELD(entry, u8 *, 1);
            func_020a4d78(x, y, 0, type);
            func_020a51a4((Unk020ABaseEntry *)entry);
            M2C_FIELD(entry, u8 *, 6) = (u8)entry->kind;
            M2C_FIELD(arg0, s32 *, 0x34) = (s32)entry + 8;
            return;
        }
        }
    }
advance:
    entry = (Unk020AEntry *)M2C_FIELD(arg0, s32 *, 0x34);
    entry = (Unk020AEntry *)((u8 *)entry + 8);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32)entry;
    type = entry->type;
    if (type != 0) goto eval;
    func_01ffa8c4(arg0, 1);
    return;
}

