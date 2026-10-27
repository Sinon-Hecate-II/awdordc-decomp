/* 36 functions from 0x02032228 to 0x02033210 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u32 words[3]; } Unk032Record;
typedef struct { u32 words[18]; } Unk032Callbacks;

void func_02032228(void *arg0) {
void func_02007888(u32 *); void func_020472cc(void *); void func_02031dd4(void *,u32,u32); void func_02031dfc(void *,u32); void func_02031e94(void *,s32);
u32 b[5]; u32 a[8]; u32 i; u64 seed;
func_02007888(a);
for(i=1;i<8;i++)a[i]^=a[i-1];
seed=a[7];
func_020472cc(b);
if(b[4])func_02031dd4(arg0,b[0],b[1]);else func_02031dd4(arg0,b[2],b[3]);
func_02031dfc(arg0,(u32)((seed*0x5d588b656c078965ULL+0x269ec3)>>32));
func_02031e94(arg0,1);
}

s32 func_020322ec(void *a) {
void func_020472cc(void *);
u64 func_02031d90(void *);
u32 s[5];
func_020472cc(s);
if(s[4]) return *(u64 *)&s[0]==func_02031d90(a);
return *(u64 *)&s[2]==func_02031d90(a);
}

s32 func_02032358(s32 a) {
s32 func_02031e28();
return func_02031e28(a)==1;
}

s32 func_02032370(s32 arg0) {
    M2C_UNK func_02032358(s32);
    return func_02032358(arg0 + 0x10);
}

s32 func_02032380(void) {
    s32 func_02031e28();
    if (func_02031e28() != 0) {
        return 1;
    }
    return 0;
}

void func_02032398(void) {
    M2C_UNK func_02032380();
    func_02032380();
}

void func_020323a4(void) {
    M2C_UNK func_020321ac();
    func_020321ac();
}

s32 func_020323b0(void *a) {
void func_02076794(void *,u32);
u32 func_02076860(void *,void *,u32);
u32 table[256]; u32 crc;
func_02076794(table,0xedb88320);
crc=func_02076860(table,a,0x3c);
if(crc==M2C_FIELD(a,u32 *,0x3c)) return 1;
return 0;
}

s32 func_020323f4(void *arg0) {
    if ((func_02032358(arg0 + 0x10) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x1C) > 0)) {
        return 1;
    }
    return 0;
}

s32 func_02032424(void *a) {
s32 func_02031e28(void *);
void func_020472cc(void *);
u64 func_02031d90(void *);
u32 s[5];
if(func_02031e28((u8 *)a+0x10)==0)return 1;
func_020472cc(s);
if(s[4]==0)return 0;
return *(u64 *)&s[0]==func_02031d90((u8 *)a+0x10);
}

void func_0203248c(void *a,Unk032Record *b,s32 c) {
void func_02076794(void *,u32);
u32 func_02076860(void *,void *,u32);
u32 table[256];
*(Unk032Record *)((u8 *)a+0x10)=*b;
M2C_FIELD(a,s32 *,0x1c)=c;
func_02076794(table,0xedb88320);
M2C_FIELD(a,u32 *,0x3c)=func_02076860(table,a,0x3c);
M2C_FIELD(a,u32 *,0x20)|=1;
}

void func_020324e4(void) {
    M2C_UNK func_020324f0();
    func_020324f0();
}

s32 func_020324f0(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x20) & 1) == 1) {
        return 1;
    }
    return 0;
}

void func_02032508(void) {
    M2C_UNK func_02032514();
    func_02032514();
}

s32 func_02032514(void *a) {
void func_02076794(void *,u32);
u32 func_02076860(void *,void *,u32);
u32 table[256];
M2C_FIELD(a,u32 *,0x20)&=~1;
func_02076794(table,0xedb88320);
M2C_FIELD(a,u32 *,0x3c)=func_02076860(table,a,0x3c);
}

u64 func_02032558(void *a) {
u64 func_02031db8(void *);
if(func_02031e28(a)!=2)return 0;
return func_02031db8(a);
}

s32 func_02032580(void *a,void *b) {
u64 func_02031db8(void *);
s32 func_02031dcc(void *);
s32 func_02031f74(u64,s32);
s32 func_02031fe4(u64,s32);
u64 v;
switch(func_02031e28(b)) {
case 2: v=func_02031db8(b);if(!func_02031f74(v,M2C_FIELD(a,s32 *,0x24)))return 0; return func_02031fe4(v,M2C_FIELD(a,s32 *,0x24));
case 3:return func_02031dcc(b);
case 1:return -1;
default:return 0;
}
}

u64 func_02032604(void *a) {
u64 func_02031f14(s32,s32);
s32 x=M2C_FIELD(a,s32 *,0x1c); u64 r=0;
if(x)r=func_02031f14(x,M2C_FIELD(a,s32 *,0x24));
return r;
}

void func_02032634(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02031e04(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0xC);
    func_02031e04(arg0, arg1, arg2);
    func_02031e94(arg0, 2);
}

void func_02032670(void *a,Unk032Record *b) {
M2C_UNK func_02007f8c();
M2C_UNK func_02031e0c(s32,s32);
M2C_UNK func_02031e94();
func_02007f8c(b,0,12);
if(func_02032370((s32)a)!=0) {
func_02031e0c((s32)b,M2C_FIELD(a,s32 *,0x1c));
func_02031e94(b,3);
} else *b=*(Unk032Record *)((u8 *)a+4);
}

void func_020326c4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02031e0c(M2C_UNK, M2C_UNK);
    M2C_UNK func_02031e94(M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0xC);
    func_02031e0c(arg0, arg1);
    func_02031e94(arg0, 3);
}

void func_020326f8(void *a,s32 b,s32 c) {
void func_0203211c(s32,s32,s32);
func_0203211c(b,M2C_FIELD(a,s32 *,0x24),c);
}

s32 func_02032710(void *a,void *b){
s32 func_02031e28(void *); s32 func_02031dcc(void *); u64 func_02031d90(void *); s32 func_02031db0(void *); u64 func_02031db8(void *);
s32 type=func_02031e28(a);
if(type!=func_02031e28(b))return 0;
if(type==3)return func_02031dcc(a)==func_02031dcc(b);
if(type==1){if(func_02031d90(a)==func_02031d90(b) && func_02031db0(a)==func_02031db0(b))return 1;return 0;}
if(type==2)return func_02031db8(a)==func_02031db8(b);
return 0;
}

s32 func_020327f4(s32 a,s32 b) {
void func_02031e38();
u64 func_02031db8(void *);
void func_02032004(void *,u32,u32);
void func_0203211c(s32,s32,s32);
u8 buf[33];u64 v;
if(func_02031e28(b)==3) {func_02031e38(b);return;}
if(func_02031e28(b)==2) {v=func_02031db8((void *)b);func_02032004(buf+21,(u32)v,(u32)(v>>32));return;}
if(func_02031e28(b)==1)func_0203211c(b,M2C_FIELD(a,s32 *,0x24),(s32)buf);
}

void func_0203287c(s32 arg0) {
    M2C_UNK func_020327f4(s32, s32);
    func_020327f4(arg0, arg0 + 4);
    func_020327f4(arg0, arg0 + 0x10);
}

void func_0203289c(s32 arg0) {
    extern s32 data_020fb2f8;
    data_020fb2f8 = arg0;
}

s32 func_020328ac(Unk032Callbacks *arg,s32 value){
M2C_UNK func_02007f8c(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_02032c74(s32);
void func_020329d0(void);
extern M2C_UNK data_0213d114,data_020fb33c;
void *p;
void *(*alloc)(void *,s32);
alloc=M2C_FIELD(arg,void *(**)(void *,s32),0x40);
if(M2C_FIELD(&data_0213d114,void **,8))return 2;
M2C_FIELD(&data_0213d114,void **,8)=alloc(&data_020fb33c,0x13f4);
if(!M2C_FIELD(&data_0213d114,void **,8))return 2;
func_02007f8c((s32)M2C_FIELD(&data_0213d114,void **,8),0,0x13f4);
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1314)=value;
M2C_FIELD(&data_0213d114,s32 *,0)=0;
func_02007f8c((s32)(M2C_FIELD(&data_0213d114,void **,8)+0x1008),0,0x1c4);
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1008)=0x4e84;
p=M2C_FIELD(&data_0213d114,void **,8);
M2C_FIELD(p,Unk032Callbacks *,0x11cc)=*arg;
M2C_FIELD(p,u16 *,0x11fe)=0;
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),u8 *,0x120b)=0;
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1004)=func_02032c74(1);
if(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1004))return M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1004);
M2C_FIELD(&data_0213d114,s32 *,4)=0;
func_020329d0();
return 0;
}

void func_020329d0(void) {
M2C_UNK func_0200654c(void *); M2C_UNK func_02005ac0(void *,void (*)(void),void *,void *,s32,s32);
s32 func_02005d90(void *); M2C_UNK func_02005e5c(void *); void func_02032d84(void);
extern M2C_UNK data_0213d114; extern M2C_UNK data_0213d11c;
func_0200654c(M2C_FIELD(&data_0213d114,void **,8)+0x13d8);
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x13f0)=0;
if(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1384)!=0 && func_02005d90(M2C_FIELD(&data_0213d114,void **,8)+0x1318)==0)return;
func_02005ac0(M2C_FIELD(&data_0213d114,void **,8)+0x1318,func_02032d84,&data_0213d11c,M2C_FIELD(&data_0213d114,void **,8)+0x1000,0x1000,0x10);
func_02005e5c(M2C_FIELD(&data_0213d114,void **,8)+0x1318);
}

void func_02032a84(void) {
M2C_UNK func_02006564(void *); M2C_UNK func_020065e8(void *); M2C_UNK func_02033f3c(s32); M2C_UNK func_02005d60(void *);
extern M2C_UNK data_0213d114;
if(!M2C_FIELD(&data_0213d114,void **,8))return;
func_02006564(M2C_FIELD(&data_0213d114,void **,8)+0x13d8);
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x13f0)=1;
func_020065e8(M2C_FIELD(&data_0213d114,void **,8)+0x13d8);
if(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1314))func_02033f3c(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1314));
if(!M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1384))return;
func_02005d60(M2C_FIELD(&data_0213d114,void **,8)+0x1318);
}

void func_02032b10(void) {
M2C_UNK func_02034480(s32); extern M2C_UNK data_0213d114; extern M2C_UNK data_020fb34c;
void (*callback)(void *,void *,s32);
if(!M2C_FIELD(&data_0213d114,void **,8))return;
callback=M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),void (**)(void *,void *,s32),0x1210);
if(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1314))func_02034480(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1314));
callback(&data_020fb34c,M2C_FIELD(&data_0213d114,void **,8),0);
M2C_FIELD(&data_0213d114,void **,8)=0;
}

void func_02032b68(void) {
    M2C_UNK func_02005d60(void *);
    extern M2C_UNK data_0213d114;
    if (M2C_FIELD(M2C_FIELD(&data_0213d114, void **, 8), s32 *, 0x1384) == 0) {
        return;
    }
    func_02005d60(M2C_FIELD(&data_0213d114, void **, 8) + 0x1318);
}

s32 func_02032b98(void) {
M2C_UNK func_02006564(void *); M2C_UNK func_020065e8(void *);
extern M2C_UNK data_0213d114;
s32 result;
if (!M2C_FIELD(&data_0213d114,void **,8)) return 22;
func_02006564(M2C_FIELD(&data_0213d114,void **,8)+0x13d8);
result=M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1004);
func_020065e8(M2C_FIELD(&data_0213d114,void **,8)+0x13d8);
return result;
}

void func_02032be4(void *arg0) {
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02008048(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213d114;
    void *p;
    void *dst;
    s32 v;

    p = M2C_FIELD(&data_0213d114, void **, 8);
    if (p == 0) {
        func_02007f8c(arg0, 0, 0x1C4);
        p = M2C_FIELD(&data_0213d114, void **, 8);
        dst = (u8 *)p + 8;
        dst = (u8 *)dst + 0x1000;
        func_02008048(dst, arg0, 0x1C4);
    }
    v = M2C_FIELD(arg0, s32 *, 0);
    if (v < 0x4E20 || v >= 0x7530) {
        M2C_FIELD(arg0, s32 *, 0) = 0x5206;
    }
    v = M2C_FIELD(arg0, s32 *, 0);
    if (v >= 0x4E84) {
        M2C_FIELD(arg0, s32 *, 0) = -v;
    }
}

s32 func_02032c74(s32 arg0){
extern M2C_UNK data_020fb2f8,data_020fb35c,data_0213d114,data_0213d120,data_0212dca4;
s32 func_02068d98(void *,void *);s32 func_02033ccc(void *,const void *);void func_02045cbc(void *);s32 func_020334d8(void *,void *,void *);s32 func_02033de8(void *);s32 func_02006028(s32);void func_02033e80(void *,s32);
if(func_02068d98(M2C_FIELD(&data_020fb2f8,void **,0),&data_020fb35c))M2C_FIELD(&data_020fb2f8,s32 *,20)=1;
{ void *p=M2C_FIELD(&data_0213d114,void **,8);
M2C_FIELD(&data_020fb2f8,s32 *,12)=M2C_FIELD(p,s32 *,0x120c);
M2C_FIELD(&data_020fb2f8,s32 *,16)=M2C_FIELD(p,s32 *,0x1210);
if(func_02033ccc(M2C_FIELD(p,void **,0x1314),(const void *)&data_020fb2f8))return 4;
}
if(arg0==1)func_02045cbc(&data_0213d120);
M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1004)=func_020334d8(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),void **,0x1314),(u8 *)M2C_FIELD(&data_0213d114,void **,8)+0x1200,(u8 *)M2C_FIELD(&data_0213d114,void **,8)+0x11cc);
if(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),s32 *,0x1004))return 4;
if(func_02033de8(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),void **,0x1314)))return 4;
func_02033e80(M2C_FIELD(M2C_FIELD(&data_0213d114,void **,8),void **,0x1314),func_02006028(M2C_FIELD(&data_0212dca4,s32 *,4))-1);
return 0;
}

