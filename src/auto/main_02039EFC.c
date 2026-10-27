/* 24 functions from 0x02039EFC to 0x0203AEB4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 words[3]; } Record3A;
typedef struct { u32 words[8]; } Record39;

void func_02039efc(M2C_UNK a,Record39 *b){
extern M2C_UNK data_0213d380,data_020fc8a8; void func_0203a4bc(s32,void *);
s32 func_0203af50(s32,s32,void *);s32 func_02039e88(void);s32 func_02038f88(void);s32 func_0203c28c(s32);
void func_02039db4(s32,s32);M2C_UNK func_0204ddd4(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32);
void *p;
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,48)=0;
if(b->words[0]==0){
p=M2C_FIELD(&data_0213d380,void **,4);
M2C_FIELD(p,Record39 *,0x260)=*b;
if(M2C_FIELD(p,s32 *,4)==2){
if(M2C_FIELD(M2C_FIELD(p,void **,28),u32 *,28)==b->words[1]){
M2C_FIELD(p,s32 *,4)=5;
func_0203af50(1,(s32)&data_020fc8a8,0);
if(func_02039e88())return;
p=M2C_FIELD(&data_0213d380,void **,4);
M2C_FIELD(p,void (**)(s32,u32,s32),20)(0,b->words[1],M2C_FIELD(p,s32 *,24));
if(func_02038f88())return;
if(func_0203c28c(b->words[1]))return;
}else func_02039db4(6,-60000);
}else if(M2C_FIELD(p,s32 *,4)==3){
func_0204ddd4(a,b->words[1],0,0,(M2C_UNK *)func_0203a4bc,0);
if(func_02039e88())return;
}
}else func_02039e88();
}

void func_0203a034(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0203a04c(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
    void func_02039efc(M2C_UNK, Record39 *);
    func_0203a04c(arg0, arg1, (M2C_UNK *)&func_02039efc, 2);
}

void func_0203a04c(M2C_UNK a,M2C_UNK b,M2C_UNK *c,M2C_UNK d) {
extern M2C_UNK data_0213d380;
void func_02068c50(void *,M2C_UNK);
u64 func_02007004(void);
void func_0204dbd4(s32,void *,void *,s32,s32,M2C_UNK *,s32);
s32 func_02039e88(void);
void *p;
func_02068c50((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x48,a);
func_02068c50((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x148,b);
p=M2C_FIELD(&data_0213d380,void **,4);
M2C_FIELD(p,u64 *,0x34)=func_02007004();
M2C_FIELD(p,s32 *,0x30)=1;
p=M2C_FIELD(&data_0213d380,void **,4);
func_0204dbd4(M2C_FIELD(p,s32 *,0),(u8 *)p+0x48,(u8 *)p+0x148,1,0,c,0);
if(func_02039e88()) return; M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,4)=d;
}

void func_0203a0e8(void *a,s32 b){
extern M2C_UNK data_0213d380;
u64 func_02007004(void); s32 func_02032370(void *); s32 func_02032358(void *); s32 func_020322ec(void *); void func_02032228(void *); void func_0203211c(void *,s32,void *); void func_02031dfc(void *,u32); s32 func_02038020(s32); void func_02008048(s32,void *,s32);void func_02068c50(void *,M2C_UNK); s32 func_020376a4(s32,s32,s32); void func_02037694(void);void func_020376d8(void);void func_020328ac(void *,s32);void func_02007f8c(void *,s32,s32);
u8 buf[72];void *p; s32 n;
func_02007f8c(buf,0,72);M2C_FIELD(&data_0213d380,void **,8)=a;M2C_FIELD(&data_0213d380,s32 *,0)=b;
if(func_02032370(M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),void **,28))){
p=M2C_FIELD(&data_0213d380,void **,4);func_0203211c(M2C_FIELD(p,u8 **,28)+16,M2C_FIELD(M2C_FIELD(p,void **,28),s32 *,36),(u8 *)p+0x248);
}else{
if(!func_02032358((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x3c)){
if(func_020322ec(M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),u8 **,28)+4)){
p=M2C_FIELD(&data_0213d380,void **,4);M2C_FIELD(p,Record3A *,0x3c)=M2C_FIELD(M2C_FIELD(p,void **,28),Record3A *,4);
}else func_02032228((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x3c);
}else{
u64 t=func_02007004();func_02031dfc((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x3c,(u32)((t*0x5d588b656c078965ULL+0x269ec3)>>32));
}
p=M2C_FIELD(&data_0213d380,void **,4);func_0203211c((u8 *)p+0x3c,M2C_FIELD(p,s32 *,12),(u8 *)p+0x248);
}
n=func_02038020(M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,16));
func_02008048(M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,16),buf,n*2+2);
func_02068c50(buf+0x34,(s32)((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x251));
M2C_FIELD(buf,u32 *,64)=(u32)func_02037694;M2C_FIELD(buf,u32 *,68)=(u32)func_020376d8;n=func_020376a4(0,0x1c14,4);
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,36)=n;
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),u64 *,40)=func_02007004();
func_020328ac(buf,n);
}

void func_0203a4bc(s32 a,void *b) {
extern M2C_UNK data_0213d380;
void func_0203211c(void *,s32,void *); M2C_UNK func_0204ddd4(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32); void func_0204deb0(s32,s32,void *); s32 func_02039e88(void); void func_0204dcd8(s32); void func_0203a0e8(void *,s32); s32 func_02068d98(s32,M2C_UNK *); void func_0203248c(void *,void *,s32);
u8 buf1[21],buf2[21],buf3[21]; void *p;
if(M2C_FIELD(b,s32 *,0))return;
p=M2C_FIELD(&data_0213d380,void **,4);
if(M2C_FIELD(p,s32 *,4)==3){
if(M2C_FIELD(b,s8 *,0x8e)==0){
func_0203211c(M2C_FIELD(p,u8 **,28)+4,M2C_FIELD(p,s32 *,12),buf1);
func_0204deb0(a,0x705,buf1);if(func_02039e88())return;
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,4)=4;
func_0204ddd4(a,M2C_FIELD(b,s32 *,4),0,0,(M2C_UNK *)func_0203a4bc,0);if(func_02039e88())return;
}else{
func_0204dcd8(a);func_0203a0e8((void *)func_0203a034,0);
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,4)=1;
}
}else if(M2C_FIELD(p,s32 *,4)==4){
func_0203211c(M2C_FIELD(p,u8 **,28)+4,M2C_FIELD(p,s32 *,12),buf2);
if(func_02068d98((s32)((u8 *)b+0x8e),(M2C_UNK *)buf2)==0){
p=M2C_FIELD(&data_0213d380,void **,4);func_0203211c((u8 *)p+0x3c,M2C_FIELD(p,s32 *,12),buf3);
p=M2C_FIELD(&data_0213d380,void **,4);func_0203248c(M2C_FIELD(p,void **,28),(u8 *)p+0x3c,M2C_FIELD(b,s32 *,4));
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,4)=2;
((void (*)(s32,Record39 *,s32))func_02039efc)(a,(Record39 *)((u8 *)M2C_FIELD(&data_0213d380,void **,4)+0x260),0);
}else{func_0204ddd4(a,M2C_FIELD(b,s32 *,4),0,0,(M2C_UNK *)func_0203a4bc,0);if(func_02039e88())return;}
}
}

s32 func_0203a660(void) {
    extern M2C_UNK data_0213d380;
    if ((M2C_FIELD(&data_0213d380, void **, 4) != NULL) && (M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 4) == 5)) {
        return 1;
    }
    return 0;
}

void func_0203a68c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0203a6a4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_0203a6a4(arg0, 0, 0, arg1);
}

s32 func_0203a6a4(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d) {
extern u8 data_020fc8ac[],data_020fc8b0[];
s32 func_0203b63c(M2C_UNK,void *);
s32 func_02037df0(void *,void *,void *,s32);
s32 func_0206abd8(void *,void *,s32);
void func_02068c50(void *,M2C_UNK);
u32 buf[132];u32 temp;
if(func_0203b63c(a,buf)){
if(buf[1]==6){
if(b){if(func_02037df0(data_020fc8ac,&temp,buf+2,47)<=0)*(u8 *)b=0;else *(u8 *)b=func_0206abd8(&temp,0,10);}
if(c){if(func_02037df0(data_020fc8b0,&temp,buf+2,47)<=0)*(u8 *)c=0;else *(u8 *)c=func_0206abd8(&temp,0,10);}
}else{if(b)*(u8 *)b=0;if(c)*(u8 *)c=0;}
if(d)func_02068c50((void *)d,(M2C_UNK)(buf+66));
return (u8)buf[1];
}
if(b)*(u8 *)b=0;if(c)*(u8 *)c=0;return 0;
}

s32 func_0203a7c0(M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 d,s32 *e) {
s32 func_0203a6a4(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_02068c34(void *);
s32 func_0203739c(void *,s32,s32,s32);
u8 buf[256];s32 n,v;
n=func_0203a6a4(a,b,c,(s32)buf);
if(!n){*e=-1;return n;}
*e=func_0203739c(buf,func_02068c34(buf),0,0);
if(!d || (v=*e)==-1)return n;func_0203739c(buf,func_02068c34(buf),d,v);
return n;
}

s32 func_0203a850(s32 a,s32 b) {
extern M2C_UNK data_0213d38c;
s32 func_02037214(s32,s32,void *,s32);
s32 func_0203af50(s32,s32,void *);
u8 buf[256];s32 n;
if(!M2C_FIELD(&data_0213d38c,void **,8)||!func_0203a660())return 0;
n=func_02037214(a,b,buf,255);
if(n==-1)return 0;
buf[n]=0;
return func_0203af50(-1,0,buf)==0;
}

s32 func_0203a8dc(void) {
extern M2C_UNK data_0213d38c;
void *p=M2C_FIELD(&data_0213d38c,void **,8);
if(p && (u8)(M2C_FIELD(p,u8 *,0x1e)+255)<=1)return 0;
return 1;
}

void func_0203a910(void *a) {
extern M2C_UNK data_0213d38c;
s32 func_02039d98(void);s32 func_02032580(s32,void *);
s32 func_0204e364(s32,s32);void func_0204e3b0(s32,s32);void func_02007f8c(void *,s32,s32);
s32 n;
if(!M2C_FIELD(&data_0213d38c,void **,8)||!func_0203a660()||!func_02039d98())goto clear;
n=func_02032580(func_02039d98(),a);
if(!n || n==-1)goto clear;
if(func_0204e364(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,4),n))
func_0204e3b0(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,4),n);
clear: func_02007f8c(a,0,12);
}

s32 func_0203a9a4(s32 a,s32 b) {
extern M2C_UNK data_0213d38c;
if(!M2C_FIELD(&data_0213d38c,void **,8))return 0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x44)=a;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x48)=b;
return 1;
}

void func_0203a9d0(void) {
    M2C_UNK func_0203739c();
    func_0203739c();
}

void func_0203a9dc(void *a,s32 b,s32 c,s32 d,s32 e) {
 extern M2C_UNK data_0213d38c;
 void *p;
 M2C_FIELD(&data_0213d38c,void**,8)=a;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,0)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,4)=b;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,8)=0;
 p=M2C_FIELD(&data_0213d38c,void**,8);
 M2C_FIELD(p,s32*,12)=0;M2C_FIELD(p,s32*,16)=0;M2C_FIELD(p,s32*,20)=e;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,24)=d;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),u8*,28)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),u8*,29)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),u8*,30)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),u8*,31)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,32)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,36)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,40)=c;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,44)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,48)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,52)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,56)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,60)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,64)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,68)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,72)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,76)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,80)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,84)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void**,8),s32*,88)=0;
}

/* Advance the registered communication session by one step. */
void func_0203aabc(void) {
extern M2C_UNK data_0213d38c;
s32 func_0203761c(void *); s32 func_0203b09c(void); s32 func_0203bcf8(s32); s32 func_02058c84(void);
void func_02058ca4(void); void func_02058c14(void); void func_0203b158(s32,s32); void func_0203b3c4(void);
void *ctx,*child; u32 status;
ctx=M2C_FIELD(&data_0213d38c,void **,8);
if(!ctx)return;
if(func_0203761c(ctx))return;
ctx=M2C_FIELD(&data_0213d38c,void **,8);
if(!M2C_FIELD(ctx,s32 *,0x18)){
child=M2C_FIELD(ctx,void **,4);
if(child && M2C_FIELD(child,s32 *,0))func_0203b09c();
return;
}
if(func_0203bcf8(M2C_FIELD(ctx,s32 *,0x18)) || func_02058c84()){
M2C_FIELD(&data_0213d38c,s32 *,0)=1;
M2C_FIELD(&data_0213d38c,s32 *,12)=0;
func_02058ca4();
M2C_FIELD(&data_0213d38c,s32 *,0)=0;
if(M2C_FIELD(&data_0213d38c,s32 *,12)==1){
M2C_FIELD(&data_0213d38c,s32 *,12)=0;func_02058c14();
}}
ctx=M2C_FIELD(&data_0213d38c,void **,8);
child=M2C_FIELD(ctx,void **,4);
if(child && M2C_FIELD(child,s32 *,0)){
if(func_0203b09c())return;
ctx=M2C_FIELD(&data_0213d38c,void **,8);
if(!M2C_FIELD(ctx,s32 *,0))return;
if(M2C_FIELD(ctx,s32 *,0x18) && (status=M2C_FIELD(ctx,u8 *,0x1e))!=3){
if(M2C_FIELD(ctx,u32 *,8)>7){
if(status<=1)func_0203b158(M2C_FIELD(ctx,s32 *,0x18),M2C_FIELD(ctx,s32 *,0x14));
ctx=M2C_FIELD(&data_0213d38c,void **,8);
if(M2C_FIELD(ctx,u8 *,0x1c)>=M2C_FIELD(ctx,s32 *,0x14)){
M2C_FIELD(ctx,u8 *,0x1e)=3;
ctx=M2C_FIELD(&data_0213d38c,void **,8);
M2C_FIELD(ctx,u8 *,0x1f)++;
}
}}}
ctx=M2C_FIELD(&data_0213d38c,void **,8);
if(M2C_FIELD(ctx,u8 *,0x1f)<2)return;
M2C_FIELD(ctx,u8 *,0x1f)=0;
func_0203b3c4();
}

void func_0203ac20(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h) {
extern M2C_UNK data_0213d38c;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,44)=c;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,48)=d;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,52)=e;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,56)=f;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,60)=g;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,64)=h;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,29)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,30)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,31)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,28)=0;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=1;
{void *p=M2C_FIELD(&data_0213d38c,void **,8);if(!M2C_FIELD(p,s32 *,24))M2C_FIELD(p,u8 *,31)++;}
{void *p=M2C_FIELD(&data_0213d38c,void **,8);M2C_FIELD(p,u8 *,31)++;}
}

void func_0203accc(s32 a,s32 b) {
extern M2C_UNK data_0213d38c;void func_02037638(s32,s32);void func_0203b128(void);
void *p;
if(!M2C_FIELD(&data_0213d38c,void **,8)||!a)return;
func_02037638(a,b);
p=M2C_FIELD(&data_0213d38c,void **,8);
if(M2C_FIELD(p,s32 *,0)!=0 && M2C_FIELD(p,s32 *,0)!=2) M2C_FIELD(p,void (**)(s32,u8,s32),44)(a,M2C_FIELD(p,u8 *,29),M2C_FIELD(p,s32 *,48));
func_0203b128();
}

void func_0203ad24(M2C_UNK a,void *b) {
extern M2C_UNK data_0213d38c;
extern M2C_UNK func_0203b9a8;
M2C_UNK func_0204ddd4(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32);
if(!M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,0x18))return;
func_0204ddd4(a,M2C_FIELD(b,s32 *,0),0,0,&func_0203b9a8,0);
}

s32 func_0203ad70(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_0204ddd4(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    s32 func_02068d98(s32, M2C_UNK *);
    extern M2C_UNK data_020fc8b4;
    extern M2C_UNK func_0203bb58;
    if (func_02068d98(M2C_FIELD(arg1, s32 *, 8), &data_020fc8b4) != 0) {
        return 0;
    }
    func_0204ddd4(arg0, M2C_FIELD(arg1, s32 *, 0), 0, 0, &func_0203bb58, 0);
    return 1;
}

void func_0203adcc(s32 a,void *b) {
extern M2C_UNK data_0213d38c;
s32 func_0203aeb4(s32);
void func_0204e1b4(s32,s32,void *);
u32 out[66]; u32 buf[66];s32 n;void *p;
if(!M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,0x34))return;
n=func_0203aeb4(M2C_FIELD(b,s32 *,0));
if(n==-1)return;
func_0204e1b4(a,M2C_FIELD(b,s32 *,8),buf);
p=M2C_FIELD(&data_0213d38c,void **,8);
M2C_FIELD(p,void (**)(s32,u32,void *,s32),0x34)(n,buf[1]&255,out,M2C_FIELD(p,s32 *,0x38));
}

s32 func_0203ae50(void) {
    extern M2C_UNK data_0213d38c;
    if (M2C_FIELD(&data_0213d38c, void **, 8) != NULL) {
        return M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), s32 *, 0x14);
    }
    return 0;
}

s32 func_0203ae6c(s32 a) {
extern M2C_UNK data_0213d38c;
s32 func_02039d98(void);
s32 func_02032580(s32,void *);
void *p,*v;
p=M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,0x18);
if(!p)return 0;
v=(void *)func_02032580(func_02039d98(),(u8 *)p+a*12);
if(v==0||v==(void *)-1)return 0;
return (s32)v;
}

