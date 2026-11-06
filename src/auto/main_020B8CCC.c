/* 21 functions from 0x020B8CCC to 0x020B9C8C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 value; u8 flag; } Unk020BChoice;
typedef struct UiB8ccc {u8 pad[0x40];u32 a:18;u32 tile:8;u32 b:6;u8 pad44[0x15];u8 mode:4;u8 active:1;u8 c:3;u8 reset;u8 pad5b[9];s8 *state;} UiB8ccc;

static inline s32 MulUiB8ccc(s32 a,s32 b){return ((s64)a*b+0x800)>>12;}
static inline u8 IsUiB8ccc(UiB8ccc *p){return p->state[11]==1 || (p->active && p->state[12]==1);}

#pragma optimization_level 2
void func_020b8ccc(void *a){
s32 func_020b846c(s32);void func_020b8594(s32);s32 func_020d8f4c(void);s32 func_020ae0a8(void);s32 func_020ae1a4(void);void func_020ae164(s32);void func_020d8f1c(s32,s32);M2C_UNK func_0208fe30(s32);void func_020b876c(void);void func_020b8778(void);void func_020aacf0(void *);void func_020b8694(void *);void func_020b86e4(void *);s32 func_02001fb4(s32,s32);void func_0208dd7c(s32,s16,s32,s16,u16,s32,s32);
extern u16 *data_02101e84;extern void *gCur3DSpriteEngine,*data_027e00c8;
s16 step; void *old;s32 size,h,pos,v,t,pal;UiB8ccc *p;
if(M2C_FIELD(a,s16*,0x3c)==0){
t=M2C_FIELD(a,s16*,0x40)*2;v=M2C_FIELD(a,s16*,0x3e);
if(v!=t){h=t-v;if(h<0)h=-h;step=h>>1;if(step==0)step=1;if(v>t)M2C_FIELD(a,s16*,0x3e)-=step;else M2C_FIELD(a,s16*,0x3e)+=step;M2C_FIELD(a,s16*,0x3c)=1;func_020b8594(M2C_FIELD(a,s16*,0x3e));}
}else M2C_FIELD(a,s16*,0x3c)=0;
if(M2C_FIELD(a,s16*,0x46)==0){
if(func_020b846c(M2C_FIELD(a,s16*,0x38))){
if(func_020d8f4c()==2){
if(M2C_FIELD(a,s16*,0x38)!=func_020ae0a8() && func_020ae1a4() && func_020b846c(M2C_FIELD(a,s16*,0x38)))func_020ae164(M2C_FIELD(a,s16*,0x38));
}else func_020d8f1c(2,M2C_FIELD(a,s16*,0x38));
}
}else M2C_FIELD(a,s16*,0x46)--;
M2C_FIELD(a,s16*,0x36)=M2C_FIELD(a,s16*,0x38);
M2C_FIELD(a,s16*,0x38)=M2C_FIELD(a,s16*,0x40)+M2C_FIELD(a,s16*,0x3a);
if(M2C_FIELD(a,s16*,0x36)!=M2C_FIELD(a,s16*,0x38)){M2C_FIELD(a,s16*,0x46)=4;func_0208fe30(0x10019);}
p=M2C_FIELD(a,UiB8ccc**,0x48);if(M2C_FIELD(a,s16*,0x40)==0)p->tile=(u16)(p->mode+2);else p->tile=(u16)p->mode;p->reset=0;
p=M2C_FIELD(a,UiB8ccc**,0x4c);if(M2C_FIELD(a,s16*,0x40)==M2C_FIELD(a,s16*,0x42)-6)p->tile=(u16)(p->mode+2);else p->tile=(u16)p->mode;p->reset=0;
if(*data_02101e84&1){func_020b876c();return;}if(*data_02101e84&2){func_020b8778();return;}
func_020aacf0(M2C_FIELD(a,void**,0x48));func_020aacf0(M2C_FIELD(a,void**,0x4c));func_020aacf0(M2C_FIELD(a,void**,0x50));
if(IsUiB8ccc(M2C_FIELD(a,UiB8ccc**,0x48)))func_020b8694(a);
if(IsUiB8ccc(M2C_FIELD(a,UiB8ccc**,0x4c)))func_020b86e4(a);
if(IsUiB8ccc(M2C_FIELD(a,UiB8ccc**,0x50))){func_020b876c();return;}
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
h=M2C_FIELD(a,s16*,0x42)<<12;pos=M2C_FIELD(a,s16*,0x40)<<12;
size=((s64)func_02001fb4(0x62000,h)*0x6000+0x800)>>12;
v=MulUiB8ccc(func_02001fb4(0x62000-size,h-0x6000),pos);
t=size>>12;if(t>98)t=98;else if(t<1)t=1;
pal=0x35c;
func_0208dd7c(248,(v>>12)+40,2,t,((pal+0xa3)&(pal>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30)))|0xb000,0,2);
gCur3DSpriteEngine=old;
}
#pragma optimization_level 4
void func_020b90d8(void) {M2C_UNK func_01ff9ce8(M2C_UNK,s32);void func_020cfd28();void func_020d472c();extern void *gCur3DSpriteEngine;extern void *data_027e00c8;void *old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;((M2C_UNK (*)())func_01ff9ce8)(1);((M2C_UNK (*)())func_01ff9ce8)(2);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;func_020cfd28();func_020d472c();gCur3DSpriteEngine=old;}

void func_020b9140(s32 arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, s32);
    extern M2C_UNK data_021290dc;
    if (arg0 == 0) {
        func_01ffa3dc(&data_021290dc, 7);
        return;
    }
    func_01ffa3dc(&data_021290dc, arg0);
}

#pragma optimization_level 2
#pragma opt_common_subs off
void func_020b916c(s32 x,s32 y,s32 a,s32 b,s32 c){
void func_020809c0(void *,s32,s32);s32 func_0207cb88(s32);void func_0209c048(s32,s32,s32,s32,u16,u16);void func_0209c0bc(s16,s16,void *,s32,s32,u16);extern void *gCur3DSpriteEngine;
s32 pos,base=x; s32 color=0; s32 len;
if(c<0)color=3;
func_020809c0(M2C_FIELD(gCur3DSpriteEngine,u8 **,36)+x*2+y*64,32,2);
pos=x+4;len=func_0207cb88(a)-1;func_0209c048((s16)(pos+len),(s16)y,M2C_FIELD(gCur3DSpriteEngine,s32 *,36),a,0,0);
pos=base+11;if(b<0){func_0209c0bc(pos,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),45,0,0);if(b<0)b=-b;}else{func_0209c0bc(pos,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),43,0,0);}
a=base+14;func_0209c048((s16)(a+(func_0207cb88(b)-1)),(s16)y,M2C_FIELD(gCur3DSpriteEngine,s32 *,36),b,0,0);
func_0209c0bc(base+20,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),61,0,0);
base+=23;
if(c<0){func_0209c0bc(base++,y,M2C_FIELD(gCur3DSpriteEngine,void **,36),45,0,color);if(c<0)c=-c;}
func_0209c048((s16)(base+(func_0207cb88(c)-1)),(s16)y,M2C_FIELD(gCur3DSpriteEngine,s32 *,36),c,0,color);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;
}
#pragma opt_common_subs reset
#pragma optimization_level 4
void func_020b939c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    M2C_UNK func_0208fb0c(s32, s16, s16);
    s32 func_020cd674();
    extern void **gCurrentMap;
    void *temp_r1;

    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 8;
    temp_r1 = *gCurrentMap;
    func_0208fb0c(0x111, M2C_FIELD(temp_r1, s16 *, 0x52C2), M2C_FIELD(temp_r1, s16 *, 0x52C4));
    if (func_020cd674() == 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_020b93f4(void *a) {s32 func_020d2d38(s32,s32);s32 func_0207ca38(s32,s32,s32,s32,s32);void func_020b916c(s32,s32,s32,s32,s32);M2C_UNK func_0208fe30(s32);void func_01ffa6fc(void *);extern void **gCurrentMap;
s32 n,limit,total,base,delta,v,index;void *g;
v=M2C_FIELD(a,s32 *,92);M2C_FIELD(a,s16 *,108)++;g=*gCurrentMap;n=M2C_FIELD(a,s16 *,108);limit=M2C_FIELD(a,s16 *,110);
index=M2C_FIELD(g,u16 *,0x52a4);total=M2C_FIELD((u8 *)g+index*140,s32 *,0x67a4);
base=func_020d2d38(index,v);delta=total-base;
func_020b916c(0,1,func_0207ca38(0,total,delta,n,limit),-base,delta);
if((n&3)==1)func_0208fe30(0x10023);if(n<limit)return;func_01ffa6fc(a);
}

void func_020b94a4(void *a) {s32 func_020a67fc(s32,s32,s32);void func_ov000_02199f50(s32,u8,s32,s32);void func_ov000_0216aa44(s32,s32);extern void **gCurrentMap;s32 v=M2C_FIELD(a,s32 *,92);s32 result;void *g=*gCurrentMap;
result=func_020a67fc(M2C_FIELD(g,s16 *,0x52c2),M2C_FIELD(g,s16 *,0x52c4),v);
M2C_FIELD(*gCurrentMap,s16 *,0x52dc)=M2C_FIELD(*gCurrentMap,s16 *,0x52c2);
M2C_FIELD(*gCurrentMap,s16 *,0x52de)=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
func_ov000_02199f50(1,v,0,0);func_ov000_0216aa44(14,result);M2C_FIELD(*gCurrentMap,s16 *,0x52b4)=0;
}

void func_020b953c(s32 arg0, s32 arg1) {
    void *func_01ffa42c(M2C_UNK *);
    extern M2C_UNK data_02129178;
    M2C_FIELD(func_01ffa42c(&data_02129178), s32 *, 0x5C) = arg0;
}

void func_020b9558(u8 a) {s32 func_020d2d38(s32,s32);void func_020b916c(s32,s32,s32,s32,s32);void func_ov000_02174d10(s32,s32);extern void **gCurrentMap;void *g=*gCurrentMap;s32 idx=M2C_FIELD(g,u16 *,0x52a4);s32 total=M2C_FIELD((u8 *)g+idx*140,s32 *,0x67a4);s32 base=func_020d2d38(idx,a);func_020b916c(0,1,total,-base,total-base);func_ov000_02174d10(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),a);}

void func_020b95cc(u8 *p) {
extern u16 *data_02101e84;
extern s32 data_0215d850;
void func_020b1c60(s32),func_020b2e14(void *),func_020b2e2c(void);
u16 *keys=data_02101e84;
s32 n=*p;
u32 repeat=keys[1];
s32 max;
if(repeat&64) {
if(n==0||n==7) {if(repeat==keys[0]) {n+=6;max=M2C_FIELD(&data_0215d850,s32 *,4)-1;if(n>=max)n=max;}}
else n--;
}
if(repeat&128) {
if(n==6||n==13||n==M2C_FIELD(&data_0215d850,s32 *,4)-1) {if(repeat==keys[0]) {n-=6;if(n<0)n=0;}}
else n++;
}
max=M2C_FIELD(&data_0215d850,s32 *,4);
if(max>7) {
if((repeat&32)&&n>=7)n-=7;
if((repeat&16)&&n<7)n+=7;
max--;if(n>=max)n=max;
}
func_020b1c60(n);
if(data_02101e84[0]&1) {func_020b2e14(p);return;}
if(data_02101e84[0]&2)func_020b2e2c();
}

void func_020b96e0(u8 *a) {
    s32 func_020d2dcc(s32);
    M2C_UNK func_0208fe30(s32);
    void func_02096b6c(u32);
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_020b2178();
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    void func_020b953c(s32, s32);
    extern void **gCurrentMap;
    extern u8 data_0215d859[];
    extern u8 data_0215d858[];
    extern M2C_UNK data_021291b0;
    u8 index = *a;
    if (data_0215d859[index * 2] == 1) {
        func_0208fe30(0x1001d);
        return;
    }
    if (!func_020d2dcc(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4))) {
        func_0208fe30(0x1001d);
        func_02096b6c(0xc0000332);
    } else {
        void *result = func_01ffa770(&data_021291b0);
        func_020b953c(data_0215d858[index * 2], (s32)result);
    }
    func_020b2178();
    func_01ffa9bc(&data_021291b0);
}

void func_020b9778(void) {
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b2178();
    extern M2C_UNK data_021291b0;
    func_0208fe30(0x10018);
    func_020b2178();
    func_01ffa9bc(&data_021291b0);
}

void func_020b979c(u8 *a) {
    void func_020b9558(u8);
    M2C_UNK func_0208fe30(s32);
    extern u8 data_0215d858[];
    func_020b9558(data_0215d858[*a * 2]);
    func_0208fe30(0x10019);
}

void func_020b97c4(s32 a,s32 b) {void func_020b9874(s8);M2C_UNK func_01ffa3dc(M2C_UNK *,s32);extern void **gCurrentMap;extern M2C_UNK data_0215d850;extern M2C_UNK data_021291b0;u8 *g=*gCurrentMap;u32 type=M2C_FIELD(g+(a+M2C_FIELD(g+b*2,u16 *,0x3758)),u8 *,0x1420)&31;switch(type){case 15:case 16:case 17:data_0215d850=7;break;case 18:data_0215d850=16;break;case 19:data_0215d850=32;break;}
func_020b9874((s8)data_0215d850);func_01ffa3dc(&data_021291b0,7);
}

void func_020b9874(s8 mask) {
    s32 func_020b9e20(s32, s32);
    s32 func_020d2d38(s32, s32);
    extern s8 data_ov000_021aab94[];
    extern u8 data_ov000_021b5bfc[];
    extern u8 data_0215d858[];
    extern M2C_UNK data_0215d850;
    extern void **gCurrentMap;

    u8 *buf = data_0215d858;
    s8 *table = data_ov000_021aab94;
    u8 *attrs = data_ov000_021b5bfc;
    u8 count = 0;
    u8 i = 0;
    if (table[0] != -1) {
        do {
            u8 kind = (u8)table[i];
            if (mask & attrs[kind * 0x70 + 0x13]) {
                void **gp = gCurrentMap;
                void *g = *gp;
                u16 idx = *(u16 *)((u8 *)g + 0x52a4);
                if (func_020b9e20((s32)&((u8 *)g)[0x52a4], kind) != 0) {
                    void *g2 = *gp;
                    s32 base = func_020d2d38(idx, kind);
                    s32 total = *(s32 *)((u8 *)g2 + idx * 0x8c + 0x67a4);
                    u8 flag = (total < base) ? 1 : 0;
                    buf[count * 2 + 1] = flag;
                    buf[count * 2] = kind;
                    count++;
                }
            }
            i++;
        } while (table[i] != -1);
    }
    M2C_FIELD(&data_0215d850, s32 *, 4) = count;
    buf[count * 2] = 0;
}

void func_020b9978(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK, s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

#pragma opt_common_subs off
void func_020b99ac(s32 arg0,s32 arg1,s32 arg2) {
M2C_UNK func_0209bfdc(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,u16);
void func_0209c048(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,u16);
M2C_UNK func_0207a61c(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,u8,u8);
M2C_UNK func_020d2d38(M2C_UNK,M2C_UNK);
extern u8 data_0215d858[],data_ov000_021b5bfc[];
extern void *gCur3DSpriteEngine; extern void **gCurrentMap;
s32 left; s32 right;
s32 y=arg1+1;
u8 *ptr=data_0215d858+arg2*2;
u16 mode, color; s32 row; u16 i;

s32 value; u32 kind;
right=(s16)(arg0+14); left=(u16)(arg0+1); arg0=(s16)(arg0+3);
i=0; do {
kind=ptr[i*2]; if(!kind)break;
if(ptr[i*2+1]){mode=3;color=256;}else{mode=0;color=M2C_FIELD(*gCurrentMap,u16*,0x52a8);}
row=y+i*2;
func_0209bfdc(arg0,(s16)row,M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),M2C_FIELD(data_ov000_021b5bfc,s32*,kind*112),0,mode);
value=func_020d2d38(M2C_FIELD(*gCurrentMap,u16*,0x52a4),ptr[i*2]);
func_0209c048(right,(s16)row,M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),value,0,mode);
func_0207a61c(M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),left,(u16)row,ptr[i*2],color,0,0);
i++; } while(i<7);
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x3a)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x42)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x3c)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0x44)=0;
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
}
#pragma opt_instruction_scheduling off
void func_020b9b48(s32 a,s32 b,s32 c) {
M2C_UNK func_020b22a4(s32,s32,M2C_UNK *,s32);
extern u8 data_0215d858[];extern M2C_UNK data_02129150;
s32 i; s32 x,y;
Unk020BChoice *p;
x=(a+1)<<3;
y=(b+1)<<3;
p=(Unk020BChoice *)data_0215d858;
i=0;
do {
if(p[c+i].value==0)return;
func_020b22a4(x,y,&data_02129150,c+i);
i++;y+=16;
}while(i<7);
}
#pragma opt_instruction_scheduling reset
void func_020b9bac(M2C_UNK a,M2C_UNK b,M2C_UNK c){void func_020b99ac(M2C_UNK,M2C_UNK,M2C_UNK);M2C_UNK func_020c08f8(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);func_020c08f8(a,b,16,16,1);func_020b99ac(a,b,c);}

void func_020b9bec(void){void func_020b9b48(s32,s32,s32);void func_020b1c78(s32);extern M2C_UNK data_0215d850;if(M2C_FIELD(&data_0215d850,s32 *,4)<=7)func_020b9b48(8,4,0);else{func_020b9b48(0,4,0);func_020b9b48(16,4,7);}func_020b1c78(0);}

void func_020b9c40(void){extern M2C_UNK data_0215d850;if(M2C_FIELD(&data_0215d850,s32 *,4)<=7){func_020b9bac(8,4,0);return;}func_020b9bac(0,4,0);func_020b9bac(16,4,7);}

