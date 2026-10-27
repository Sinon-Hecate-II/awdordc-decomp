/* 27 functions from 0x0209EAF4 to 0x0209F990 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s16 a,b,c,d; } Unk09Position;
typedef struct { s32 unk; Unk09Position *p; s32 count; } Unk09List;

void func_0209eaf4(s32 x,s32 y,s32 a){
extern void **gCurrentMap;extern M2C_UNK data_02156e50;extern M2C_UNK data_0211f87c;
s32 func_0207c2e0(s32,s32,s32);void func_020d1690(u8,s32,void *);void *func_01ffa3dc(void *,s32);
u8 *base;void *p;s32 v,n;u32 b;
M2C_FIELD(&data_02156e50,s32 *,8)=func_0207c2e0(x,y,a);
base=*gCurrentMap;
func_020d1690(base[0x52d4],1,base+0x52dc);
base=*gCurrentMap;
b=base[x+M2C_FIELD(base+y*2,u16 *,0x3758)+0x539c];
n=M2C_FIELD(base,s16 *,0x6ed4);
v=b&127;
if(v<n)v=0;else v-=n;
base[x+M2C_FIELD(base+y*2,u16 *,0x3758)+0x539c]=v|(b&128);
p=func_01ffa3dc(&data_0211f87c,7);
M2C_FIELD(p,s32 *,0x5c)=M2C_FIELD(*gCurrentMap,s32 *,0x52d0);
M2C_FIELD(p,s32 *,0x60)=a;M2C_FIELD(p,s32 *,0x34)=0;M2C_FIELD(p,s32 *,0x38)=x;M2C_FIELD(p,s32 *,0x3c)=y;
}

void func_0209ebe0(void *p){extern M2C_UNK data_02168f0c;extern void **gCurrentMap;u32 v;if(M2C_FIELD(&data_02168f0c,u8 *,0)){if(M2C_FIELD(&data_02168f0c,u8 *,0))v=M2C_FIELD(*gCurrentMap,u16 *,0x52b0)!=19;else v=0;if(!(v&255))return;}func_0207b764(M2C_FIELD(p,s32 *,0x38),M2C_FIELD(p,s32 *,0x3c));}

void func_0209ec44(void *p){extern void **gCurrentMap;void *q=M2C_FIELD(p,void **,0x34);u32 v;u8 *base;u32 off;u8 *row;if(q){func_020b689c(q,p);v=M2C_FIELD(q,u8 *,4);}else{func_020b68f0(M2C_FIELD(p,s32 *,0x38),M2C_FIELD(p,s32 *,0x3c),p);base=*gCurrentMap;off=M2C_FIELD(base+M2C_FIELD(p,s32 *,0x3c)*2,u16 *,0x3758);row=M2C_FIELD(p,s32 *,0x38)+base;v=M2C_FIELD(row+off,u8 *,0x539c)&127;}if(v==0&&q==0){if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))func_02091c20(31,1);}}

s32 func_0209f0a0(u8 *a,u8 *b){
extern void **gCurrentMap;s32 i,j;u8 *p,*q,*base;
if(a[1]>b[1])return 1;
if(a[1]==b[1]){
if(b)i=(b-((u8 *)*gCurrentMap+0x59a4))/14;else i=0;
base=*gCurrentMap;
q=base+0x67a4+((i>>6)+1)*140;
if(a)j=(a-(base+0x59a4))/14;else j=0;
p=base+0x67a4+((j>>6)+1)*140;
if((p[0x2b]&127)>(q[0x2b]&127))return 1;
}
return 0;
}

void func_0209f184(void *p){extern void **gCurrentMap;void *q=M2C_FIELD(p,void **,0x34);u8 *base;if(!func_0209f0a0(M2C_FIELD(*gCurrentMap,s32 *,0x52d0),q)){base=*gCurrentMap;func_ov002_021e85b0(M2C_FIELD(base,s32 *,0x52d0),q,base+0x6eb8,base+0x6ed8);}else{base=*gCurrentMap;func_ov002_021e85b0(q,M2C_FIELD(base,s32 *,0x52d0),base+0x6ed8,base+0x6eb8);}func_ov002_021e15f4(p);}

void func_0209f220(void) {
    extern void *data_027e00c0;
    M2C_FIELD(data_027e00c0, s8 *, 0x50) = 0;
}

void func_0209f238(void){extern void **gCurrentMap;void func_ov000_0216a97c(s32,s32);u8 *p=(u8 *)*gCurrentMap+0x6000;func_ov000_0216a97c(M2C_FIELD(p,s32 *,0xeb8),M2C_FIELD(p,s32 *,0xed8));}

void func_0209f260(void) {
    M2C_UNK func_0208f8c4();
    func_0208f8c4();
}

void func_0209f26c(void) {
    M2C_UNK func_0208f8d8();
    func_0208f8d8();
}

void func_0209f278(void){extern void **gCurrentMap;void (*cb)(void)=M2C_FIELD(gCurrentMap[1],void (**)(void),0x50);if(cb)cb();func_020d4b30();Reset3DSpriteEngineState();}

void func_0209f2a8(void) {
    M2C_UNK func_020d468c();
    M2C_UNK func_020cfd28();
    func_020cfd28();
    func_020d468c();
}

void func_0209f2b8(void *p){void *func_0209f8e4(s32);extern s32 data_0215be0c;extern void **gCurrentMap;void func_ov000_02199f50(s32,u8,s32,s32);u16 *q;func_020c5b24();func_020bac24();func_020c5b5c();if(!M2C_FIELD(p,s32 *,0x60))return;q=func_0209f8e4(data_0215be0c);func_ov000_02199f50(4,M2C_FIELD(*gCurrentMap,u8 *,0x52d4),q[0],0);}

void func_0209f314(void *p){extern void **gCurrentMap;void func_ov000_02199f50(s32,u8,s32,s32);func_020c5b24();func_020bac24();func_020c5b5c();if(!M2C_FIELD(p,s32 *,0x60))return;func_ov000_02199f50(5,M2C_FIELD(*gCurrentMap,u8 *,0x52d4),M2C_FIELD(p,s32 *,0x38),M2C_FIELD(p,s32 *,0x3c));}

void func_0209f360(void) {
    M2C_UNK func_ov000_0216a9bc(s32);
    extern void **gCurrentMap;
    func_ov000_0216a9bc(M2C_FIELD(*gCurrentMap, s32 *, 0x52D0));
}

void func_0209f384(void) {

}

void func_0209f388(void) {

}

void func_0209f38c(void) {

}

void func_0209f858(void) {
    extern M2C_UNK data_02168f0c;
    M2C_FIELD(&data_02168f0c, s8 *, 0) = 0;
    M2C_FIELD(&data_02168f0c, s8 *, 1) = 0;
    M2C_FIELD(&data_02168f0c, s8 *, 2) = 0;
    M2C_FIELD(&data_02168f0c, s8 *, 3) = 1;
}

void func_0209f87c(void){extern u16 data_02168f14;extern void **gCurrentMap;data_02168f14=(data_02168f14&~7)|1;M2C_FIELD(*gCurrentMap,u16 *,0x5142)=1;func_0209f5dc();func_0209f858();}

void func_0209f8c0(void) {
    extern M2C_UNK data_0215be00;
    M2C_FIELD(&data_0215be00, s32 *, 8) = 0;
}

s32 func_0209f8d4(void) {
    extern M2C_UNK data_0215be00;
    return M2C_FIELD(&data_0215be00, s32 *, 8);
}

void *func_0209f8e4(s32 n){extern M2C_UNK data_0215be00;return M2C_FIELD(&data_0215be00,u8 **,4)+n*8;}

void func_0209f8f8(s32 a,s32 b,s32 c,s32 d){extern M2C_UNK data_0215be00;Unk09List *s=(Unk09List *)&data_0215be00;Unk09Position *p=s->p;p[s->count].c=a;p[s->count].d=b;p[s->count].a=c;p[s->count].b=d;s->count++;}

s32 func_0209f944(s32 a,s32 b){extern M2C_UNK data_0215be00;Unk09List *s=(Unk09List *)&data_0215be00;Unk09Position *p=s->p;s32 i;s32 n=s->count;for(i=0;i<n;i++,p++){if(a==p->c&&b==p->d)return 1;}return 0;}

