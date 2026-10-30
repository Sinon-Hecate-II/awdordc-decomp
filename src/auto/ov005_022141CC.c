/* 12 functions from 0x022141CC to 0x02215168 (ov005), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0xe6]; s16 list[1]; } Ov005Shuffle;

s32 func_ov005_022141cc(void) {
extern M2C_UNK data_ov005_02221304;
s16 n=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x98);
s32 next=n+6;
if(next>=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9a))return 0;
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x98)++;
func_0208fe30(0x10019);return 1;
}

s16 func_ov005_02214210(void) {
    extern M2C_UNK data_ov005_02221304;
    s16 temp_r3;
    s32 temp_r1;

    temp_r3 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16) (temp_r3 + 6);
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x9A) - 6;
    if ((s32) M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) > temp_r1) {
        M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16) temp_r1;
    }
    return (s16) (M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) - temp_r3);
}

void func_ov005_0221425c() { return; }

void func_ov005_022147ac(s32 a,s32 b) {
extern void *gCur3DSpriteEngine,*data_027e00c8; extern M2C_UNK data_ov005_02221304;
s32 func_ov005_022140f8(s32); void *func_020ad570(s32);
void func_0209c048(s32,s16,void *,s32,s32,s32);
void func_0209b2dc(s32,s16,s32,u32,s32,s32,u16);
void func_02080860(void *,s32,s32,u16,s32);
s32 mode; u32 color; s32 v; void *saved; u16 tile;
v=(a+1)*50+0x134;saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
if(func_ov005_022140f8(b)) {
color=M2C_FIELD(func_020ad570(b),u32 *,4);
if(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e)==b)mode=9;else mode=0;
} else {color=0x43000000; mode=3;}
func_0209c048(3,(s16)(a+3),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),b+1,0x2000,mode);
func_0209b2dc(5,(s16)(a+3),1,color,0x2000,mode,(u16)v);
tile=M2C_FIELD((u8 *)M2C_FIELD(&data_ov005_02221304,void **,8)+b,u8 *,0xa2)?0x124:0x128;
func_02080860((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x38+(a+3)*64,2,2,tile,0);
gCur3DSpriteEngine=saved;
}

void func_ov005_022148f0(s32 arg0) {
void func_020809c0(void *,s32,s32);void func_0209c048(s32,s16,void *,s32,s32,s32);void func_0209c024(s32,s16,void *,s32,s32,s32);s32 func_020a8b78(void);
extern void *gCur3DSpriteEngine,*data_027e00c8;extern M2C_UNK data_ov005_02221304;
s32 a,f,b,e,c,d;void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
func_020809c0((u8 *)M2C_FIELD(data_027e00c8,void **,0x24)+0xc0,0x20,12);
if(arg0&1){
a=0;b=arg0>>1;c=-1;
do{func_ov005_022147ac(c,b);a++;b++;c+=2;}while(a<7);
func_020809c0((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x80,32,1);
func_020809c0((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x3c0,32,1);
}else{
d=0;e=0;f=arg0>>1;
do{func_ov005_022147ac(e,f);d++;f++;e+=2;}while(d<6);
}
func_0209c048(27,1,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9c),0x2000,0);
func_0209c024(28,1,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),func_020a8b78(),0x2000,0);
func_0209c048(30,1,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9a),0x2000,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
}

void func_ov005_02214a84(s32 a) {
 extern M2C_UNK data_ov005_02221304;
 extern s16 data_ov005_02220572[],data_ov005_02220570[];
 void *p; s32 old,cur; s16 *list;
 if(!a)return;
 p=M2C_FIELD(&data_ov005_02221304,void **,8);
 if(M2C_FIELD(p,s16 *,0x86)!=0 || M2C_FIELD(p,s16 *,0x88)!=0)return;
 if(M2C_FIELD(p,s16 *,4)<=0)return;
 old=M2C_FIELD(p,s16 *,2); list=p+6;
 M2C_FIELD(p,s16 *,2)=old+1;
 p=M2C_FIELD(&data_ov005_02221304,void **,8);
 if(M2C_FIELD(p,s16 *,2)>=M2C_FIELD(p,s16 *,4))M2C_FIELD(p,s16 *,2)=0;
 p=M2C_FIELD(&data_ov005_02221304,void **,8);
 cur=M2C_FIELD(p,s16 *,2);
 if(old==-1) {if(data_ov005_02220572[list[cur]*2]!=-1)M2C_FIELD(p,s16 *,0x86)=16;}
 else if(data_ov005_02220572[list[old]*2]!=data_ov005_02220572[list[cur]*2])M2C_FIELD(p,s16 *,0x86)=16;
 if(data_ov005_02220570[list[old]*2]!=data_ov005_02220570[list[cur]*2]) M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x88)=16;
}

void func_ov005_02214b98(void) {
extern void *gCur3DSpriteEngine,*data_027e00c8;
extern M2C_UNK data_ov005_02221304,data_ov005_02220658,data_ov005_02220670,data_ov005_02220688,data_ov005_022206a0,data_ov005_022206b8;
extern s16 data_ov005_02220572[];
void func_020814e4(void *);void func_02081590(void *,s32);void func_020816a4(void *,s32,s32,s32);void func_0208161c(void *,s32,s32,s32);
void func_02081528(void);void func_0200bc5c(void *);void func_ov005_022140e4(void);
void *func_020ad460(s32);void *func_020ad4a0(s32);void *func_020ad4e0(s32);void *func_020ad520(s32);
void *saved=(unsigned short)gCur3DSpriteEngine; void *engine=*(void *volatile *)&data_027e00c8; void *p=M2C_FIELD(&data_ov005_02221304,void **,8);s32 id;
gCur3DSpriteEngine=engine;
if(M2C_FIELD(p,s16 *,2)==-1 || (id=data_ov005_02220572[M2C_FIELD((u8 *)p+M2C_FIELD(p,s16 *,2)*2,s16 *,6)*2])==-1) {
func_020814e4(&data_ov005_02220658);
func_02081590(&data_ov005_02220670,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x18));
func_020816a4(&data_ov005_02220688,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c),0,0);
func_0208161c(&data_ov005_022206a0,3,0,0x200);func_02081528();
} else {
func_0200bc5c(&data_ov005_022206b8);
func_020814e4(func_020ad460(id));
func_02081590(func_020ad4a0(id),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x18));
func_02081590(func_020ad4e0(id),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c));
func_0208161c(func_020ad520(id),3,0,0x200);func_02081528();
func_ov005_022140e4();
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
gCur3DSpriteEngine=saved;
}

#pragma scheduling off
void func_ov005_02214cdc(void) {
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    extern M2C_UNK data_ov005_02221304, data_ov005_022206c0, data_ov005_022206d8, data_ov005_022206ec, data_ov005_02220700, data_ov005_02220714;
    extern s16 data_ov005_02220570[];
    void func_020814e4(void *);
    void func_02081590(void *, s32);
    void func_020816a4(void *, s32, s32, s32);
    void func_0208161c(void *, s32, s32, s32);
    void func_0200bc5c(void *);
    void *func_020ad460(s32);
    void *func_020ad4a0(s32);
    void *func_020ad4e0(s32);
    void *func_020ad520(s32);
    void *saved = gCur3DSpriteEngine;
    void *engine = *(void *volatile *)&data_027e00c4;
    void *p;
    s16 selected;
    s32 none;
    p = M2C_FIELD(&data_ov005_02221304, void **, 8);
    gCur3DSpriteEngine = engine;
    selected = M2C_FIELD(p, s16 *, 2);
    none = -1;
    if (selected == none) {
        func_020814e4(&data_ov005_022206c0);
        func_02081590(&data_ov005_022206d8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
        func_020816a4(&data_ov005_022206ec, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0, 0);
        func_0208161c(&data_ov005_02220700, 3, 0, 512);
        func_02081528();
    } else {
        s32 id = data_ov005_02220570[M2C_FIELD(p + M2C_FIELD(p, s16 *, 2) * 2, s16 *, 6) * 2];
        func_0200bc5c(&data_ov005_02220714);
        func_020814e4(func_020ad460(id));
        func_02081590(func_020ad4a0(id), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
        func_02081590(func_020ad4e0(id), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
        func_0208161c(func_020ad520(id), 3, 0, 512);
        func_02081528();
        func_ov005_022140e4();
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
    gCur3DSpriteEngine = saved;
}
#pragma scheduling reset
void func_ov005_02214e18(s32 a) {
extern M2C_UNK data_ov005_02221304;
s32 func_ov005_022140f8(s32); s32 RandomIntRange(s32,s32);
s32 i; s16 x,y,t;
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)=0;
for(i=0;i<M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9a);i++){
if(func_ov005_022140f8(i)&&M2C_FIELD((u8 *)M2C_FIELD(&data_ov005_02221304,void **,8)+i,u8 *,0xa2)==1){
M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4),s16 *,0xe6)=i;
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)++;
}}
for(i=0;i<M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)*2;i++){
x=RandomIntRange(0,M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)-1);
y=RandomIntRange(0,M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)-1);
t=M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+x,s16 *,0xe6);
M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+x,s16 *,0xe6)=M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+y,s16 *,0xe6);
M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+y,s16 *,0xe6)=t;
}
if(a!=-1)for(i=0;i<M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4);i++){
s16 v=((Ov005Shuffle *)M2C_FIELD(&data_ov005_02221304,void **,8))->list[i];
if(a==v){void *p=M2C_FIELD(&data_ov005_02221304,void *volatile *,8);t=M2C_FIELD(p,s16 *,0xe6);M2C_FIELD(p,s16 *,0xe6)=v;((Ov005Shuffle *)M2C_FIELD(&data_ov005_02221304,void **,8))->list[i]=t;}
}
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)=0;
}

void func_ov005_02214f80(s32 a) {
void *func_020ad570(s32);
extern M2C_UNK data_ov005_02221304;
func_020901e0(M2C_FIELD(func_020ad570(a),s32 *,0));
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e)=a;
if(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x92)==0)
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xa0)=-1;
else M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xa0)=M2C_FIELD(func_020ad570(a),s32 *,8)+0x258;
func_ov005_022148f0(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x96));
}

void func_ov005_02214fec(s32 a) {
s32 func_ov005_022140f8(s32);
void func_ov005_022172d8(s32,s32);
extern M2C_UNK data_ov005_02221304;
switch(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x92)) {
case 0: case 1:
if(func_ov005_022140f8(a))func_ov005_022172d8(a,1);
break;
case 2:
if(func_ov005_022140f8(a)&&M2C_FIELD((char *)M2C_FIELD(&data_ov005_02221304,void **,8)+a,u8 *,0xa2)==1) {
func_ov005_02214e18(a);
func_ov005_022172d8(M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2),s16 *,0xe6),1);
} else if(func_ov005_022140f8(a)&&M2C_FIELD((char *)M2C_FIELD(&data_ov005_02221304,void **,8)+a,u8 *,0xa2)==0) {
func_ov005_02214e18(-1);
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)=-1;
func_ov005_022172d8(a,1);
}
break;
}
}

void func_ov005_022150d8(s16 a) {
s32 func_ov005_022140f8(s32);
void func_ov005_022172d8(s32,s32);
void func_ov005_02215200(s16);
void func_ov005_022152ec(s16);
extern M2C_UNK data_ov005_02221304;
switch(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x92)){
case 0:
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e)=a;
do {
a--;
if(a==-1){
a=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e);
break;
}
}while(!func_ov005_022140f8(a));
func_ov005_022172d8(a,1);break;
case 1:func_ov005_02215200(a);break;
case 2:func_ov005_022152ec(a);break;
}
}

