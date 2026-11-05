/* 10 functions from 0x020C1F58 to 0x020C2E4C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 flag0:1, flag1:1, flags:6; } FlagsC253c;
typedef struct { u16 pad:13, shift:2, last:1; } ModeC253c;
extern void *gCur3DSpriteEngine;
extern u8 data_020e5b30[];
extern u8 data_027e005c[];
extern u8 data_027e00b4[];
extern u8 data_02129780[];
extern u8 data_027e007c[];

M2C_UNK func_020c1f58(u8 *p){
extern u8 data_0212989c[],data_02129778[],data_021298a8[],data_021298bc[],data_021298c8[],data_021298d8[],data_021298e0[],data_021298e4[],data_021298e8[],data_021298ec[],data_021298f8[],data_02129904[],data_02129910[];
extern void *data_027e00c8,*gCurrentMap;
void func_0200bc5c(void *);void func_020a92bc(void *,s32);void *func_020e3218(void *);void *func_02080e30(void *,s32);void func_0207c780(void *,void *);void func_020e35cc(void *);void func_02080cfc(void *,void *);void func_0208116c(void *,s32,s32);M2C_UNK func_01ff9ce8(s32);void *func_020c1e6c(s32);void func_02068c50(void *,void *);void func_02068d68(void *,void *);void func_020814e4(void *);void func_02081590(void *,void *);void func_020815d4(void *,void *,s32,s32);void func_02081528(void);void func_01ff85b8(void *,s32,s32);void func_020815fc(void *,s32,s32);void func_020808dc(void *,s32,s32,s32);void func_0207b764(s32,s32);
u8 buf[64];u8 *resource;void *saved;u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;u16 *volatile v6;u16 *volatile v7;u16 *volatile v8;u16 *volatile v9;u16 *volatile v10;u16 *volatile v11;u16 *volatile v12;u16 *volatile v13;u16 *volatile v14;u16 *volatile v15;
func_0200bc5c(data_0212989c);
M2C_FIELD(*(void **)(p+60),u16*,18)=860;
M2C_FIELD(*(void **)(p+60),u8*,22)=16;
M2C_FIELD(*(void **)(p+60),u8*,20)=32;
M2C_FIELD(*(void **)(p+60),u8*,23)=24;
func_020a92bc(*(void **)(p+60),20);
M2C_FIELD(*(void **)(p+60),u8*,33)=11;
M2C_FIELD(*(void **)(p+60),u8*,32)=(M2C_FIELD(*(void **)(p+60),u8*,32)&~224)|32;
M2C_FIELD(*(void **)(p+60),void **,36)=data_02129778;
M2C_FIELD(*(void **)(p+60),u8*,40)&=~224;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
v0=*(u16 **)gCur3DSpriteEngine;*v0=*v0|16;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|32;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|64;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3&~128;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|256;
*(volatile u16 *)0x4000060=(*(volatile u16 *)0x4000060&~0x3000)|8;
v5=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v5=(*v5&~192)|64;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8*,81)=16;M2C_FIELD(*(void **)gCur3DSpriteEngine,u8*,82)=0;v6=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v6=*v6&~1;v7=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v7=*v7&~2;v8=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v8=*v8&~4;v9=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v9=*v9&~8;v10=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v10=*v10&~16;v11=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v11=*v11|256;v12=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v12=*v12&~512;v13=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v13=*v13&~1024;v14=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v14=*v14&~2048;v15=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v15=*v15&~4096;resource=func_02080e30(func_020e3218(data_021298a8),1);
func_0207c780(resource,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x6b80);
func_0207c780(resource+0x3c0,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x7f80);
if(p[54]==0)func_0207c780(resource+0x478,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8080);else func_0207c780(resource+0x690,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8080);
func_0207c780(resource+0x92c,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8480);
func_020e35cc(resource);
func_02080cfc(data_021298bc,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x9d80);
func_0208116c(data_021298c8,0x360,64);func_01ff9ce8(2);func_02068c50(buf,func_020c1e6c((*(u8 **)(p+64))[1]));func_02068d68(buf,data_021298d8);func_020814e4(buf);func_02068c50(buf,func_020c1e6c((*(u8 **)(p+64))[1]));func_02068d68(buf,data_021298e0);func_02081590(buf,M2C_FIELD(gCur3DSpriteEngine,void **,20));func_02068c50(buf,func_020c1e6c((*(u8 **)(p+64))[1]));func_02068d68(buf,data_021298e4);func_02081590(buf,M2C_FIELD(gCur3DSpriteEngine,void **,40));func_02068c50(buf,func_020c1e6c((*(u8 **)(p+64))[1]));func_02068d68(buf,data_021298e8);func_020815d4(buf,*(void **)(p+76),0,128);func_02081528();func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void **,40),1024,8192);M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;func_01ff9ce8(1);
func_020814e4(data_021298ec);func_02081590(data_021298f8,M2C_FIELD(gCur3DSpriteEngine,void **,16));func_02081590(data_02129904,M2C_FIELD(gCur3DSpriteEngine,void **,36));func_020815fc(data_02129910,32,32);func_02081528();func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void **,36),32,32,1);M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;gCur3DSpriteEngine=saved;p[53]=1;func_0207b764(M2C_FIELD(*(void **)gCurrentMap,s16*,0x52dc),M2C_FIELD(*(void **)gCurrentMap,s16*,0x52de));
}

void func_020c253c(u8 *p){
void func_020a8f8c(void *); s32 func_020a8ff4(void *); void func_01ff9e44(void *,s32,s32);
s32 func_020c1efc(s32); s32 func_020ae354(s32,s32,u8,u8);
void func_020ae548(void *,s32,u8,u8,s32); s32 func_0207c8ec(s32,s32);
void func_01ff8ddc(s32,s16,s16,s16,s16); void func_020a92bc(void *,s32); void func_020a94fc(void *);
void func_01ffaacc(s32,u16,u16,void *,s32); s32 func_020c1e48(s32); s32 func_020c1e9c(s32);
s32 a,b,c,d,x,y,t,u,v,w; u8 i,j; s16 yy;
if(!p[0x35])return;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3c)=0xffb4;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x44)=0xffcb;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0xffb4;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=0xffcb;
func_020a8f8c(*(void **)(p+68)); i=func_020a8ff4(*(void **)(p+68));
func_01ff9e44(*(void **)(p+76),64,128);
a=func_020c1efc((*(u8 **)(p+64))[3]);
if((*(u8 **)(p+64))[2]==0)func_020ae548(M2C_FIELD(gCur3DSpriteEngine,u8 **,48)+64,a,16-i,i,128);
else{t=func_020c1efc((*(u8 **)(p+64))[2]);t=func_020ae354(t,a,16-i*2,i*2);func_020ae548(M2C_FIELD(gCur3DSpriteEngine,u8 **,48)+64,t,11,5,128);}
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=16;
func_020a8f8c(*(void **)(p+72));
a=((func_020a8ff4(*(void **)(p+72))<0?-func_020a8ff4(*(void **)(p+72)):func_020a8ff4(*(void **)(p+72)))>=2?func_020a8ff4(*(void **)(p+72)):(func_020a8ff4(*(void **)(p+72))>2?2:(func_020a8ff4(*(void **)(p+72))<-2?-2:func_020a8ff4(*(void **)(p+72))))); y=((s16 *)data_020e5b30)[1];
b=((func_020a8ff4(*(void **)(p+72))<0?-func_020a8ff4(*(void **)(p+72)):func_020a8ff4(*(void **)(p+72)))>=2?func_020a8ff4(*(void **)(p+72)):(func_020a8ff4(*(void **)(p+72))>2?2:(func_020a8ff4(*(void **)(p+72))<-2?-2:func_020a8ff4(*(void **)(p+72))))); x=((s16 *)data_020e5b30)[0];
c=((func_020a8ff4(*(void **)(p+72))<0?-func_020a8ff4(*(void **)(p+72)):func_020a8ff4(*(void **)(p+72)))>=2?func_020a8ff4(*(void **)(p+72)):(func_020a8ff4(*(void **)(p+72))>2?2:(func_020a8ff4(*(void **)(p+72))<-2?-2:func_020a8ff4(*(void **)(p+72))))); d=((func_020a8ff4(*(void **)(p+72))<0?-func_020a8ff4(*(void **)(p+72)):func_020a8ff4(*(void **)(p+72)))>=2?func_020a8ff4(*(void **)(p+72)):(func_020a8ff4(*(void **)(p+72))>2?2:(func_020a8ff4(*(void **)(p+72))<-2?-2:func_020a8ff4(*(void **)(p+72)))));
t=func_0207c8ec(y<<4,d);u=func_0207c8ec((-x)<<4,c);v=func_0207c8ec(x<<4,b);w=func_0207c8ec(y<<4,a);
func_01ff8ddc(0,t,u,v,w);
if(((FlagsC253c *)(p+80))->flag0){func_020a92bc(*(void **)(p+60),(*(u8 **)(p+64))[5]);{u16 *q=*(u16 **)(p+60);q[3]=102;q[4]=59;}func_020a94fc(*(void **)(p+60));}
if(((FlagsC253c *)(p+80))->flag1)func_01ffaacc(104,857,((0x3fc>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,data_027e005c,11);
if(((FlagsC253c *)(p+80))->flags)func_01ffaacc(54,821,((0x404>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,data_027e00b4,11);
a=func_020c1e48((*(u8 **)(p+64))[1]);
func_01ffaacc(76,117,((a>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,data_02129780,11);
for(j=0;j<20;j++){yy=j*-4+130;
if(j<p[57])a=func_020c1e9c((*(u8 **)(p+64))[3]);else a=func_020c1e9c((*(u8 **)(p+64))[2]);
if(a!=65535)func_01ffaacc(156,(yy&255)|1024,((a>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xc000,data_027e007c,11);
}
}

void func_020c2aa4(u8 *p){
void func_01ffa6fc(void *);
void func_020c32bc(s32,s32);
void func_0208fe30(s32);
u32 func_0207c928(u32,u32);
s32 func_020d19b4(s32);
extern u16 *data_02101e84;
extern u8 *data_02101e88;
u8 *q;
u16 *a;
if(p[0x34]==p[0x38]){func_01ffa6fc(p);return;}
if((*data_02101e84&9)||data_02101e88[20]){
q=*(u8 **)(p+64);
if(q[5]==20 && p[0x34]<p[0x37]+7)func_020c32bc(q[0],0);
func_01ffa6fc(p);return;
}
if(p[0x34]==6){
func_0208fe30((p[0x39]+42)|0x10000);p[0x39]++;
}else if(p[0x34]>6 && p[0x39]<(*(u8 **)(p+64))[5] && func_0207c928(p[0x34]-6,3)==0){
func_0208fe30((p[0x39]+42)|0x10000);p[0x39]++;
}
if(p[0x34]==p[0x37]){
if((*(u8 **)(p+64))[5]==20){
p[80]=(p[80]&~0xfc)|4;
a=*(u16 **)(p+68);a[7]=0;a[8]=5;a[6]=8;a[1]=a[2];
}else{
p[80]=(p[80]&~1)|1;p[80]|=2;
}
a=*(u16 **)(p+72);a[7]=0x1c0;a[8]=0x100;a[6]=5;a[1]=a[2];
}
q=*(u8 **)(p+64);
if(q[5]==20){
if(p[0x34]==p[0x37]+8)func_020c32bc(q[0],0);
}else if(p[0x34]==p[0x37]+5){
if(func_020d19b4(q[0]))func_0208fe30(0xe0);else func_0208fe30(0xe2);
}
p[0x34]++;
}

void func_020c2ca0(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(arg0, u8 *, 0x35) = 0;
}

void func_020c2cec(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
v0=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v0=*v0&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|0x10;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|0x20;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3|0x40;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|0x80;
v5=*(u16 **)gCur3DSpriteEngine;*v5=*v5|0x100;
}

void func_020c2e10(void) {
    M2C_UNK func_020c1f58();
    func_020c1f58();
}

void func_020c2e1c(void) {
    void func_020c2cec(void);
    func_020c2cec();
}

void func_020c2e28(void) {
    void func_020c2ca0();
    func_020c2ca0();
}

void func_020c2e34(void) {
    void func_020c253c();
    func_020c253c();
}

void func_020c2e40(void) {
    void func_020c2aa4();
    func_020c2aa4();
}

