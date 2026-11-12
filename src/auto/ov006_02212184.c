/* 1 function from 0x02212184 to 0x02212DFC (ov006), found by ds-decomp. */
#include "common.h"
extern u8 *gCur3DSpriteEngine;
static inline void Unk02212184Scroll(int x,int y) { M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=-x; M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=-y; }
static inline void Unk02212184Origin(int x,int y) { M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x38)=-x; M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x40)=-y; }
static inline u8 Unk02212184Visible(u8 *p) { return M2C_FIELD(M2C_FIELD(p,u8 **,0x64),u8 *,0x12)!=0; }


void func_020b3a80(void *);
int GetSpriteAnimValue(void *);
int Modulo(int,int);
void Clear3DSpriteLayer(int);
int func_020b3960(void *,s16);
void SetTextSpriteValue(void *,int);
void DrawTextSprite(void *);
void *func_020c52ec(int);
u16 *func_020c53ac(int);
u64 func_020c5430(void *);
void func_020c5498(char *,u64);
void FillU16(int,void *,int);
void func_02007e20(void *,void *,int);
void MI_CpuCopy8(void *,void *,int);
void func_02019e64(void *,int,void *,int,int);
void func_020e4cd8(void *,void *,void *,int,int,int,int);
extern u8 *gCur3DSpriteEngine;
extern u8 *g3DSpriteEngineMain;
extern u32 g3DSpriteEngineSub;
extern u8 data_ov006_022186b4[],data_ov006_022186d0[];
extern u16 data_ov006_022183e0[];
int func_02001fb4(int,int);
void DrawFrameBorder(int,int,int,int,int,int,int);
void func_0208df84(int,int,int,int,int,int);
void func_02088e84(void *,int,int,int,int);
int func_020aae10(void *);
int func_020aae44(void *);
void func_02087d84(void *,int,int,int,int,int);
void func_ov000_0216a374(int,int,int,int);
void *func_020c5328(int);
int func_020c5464(int);
void ClearTileRect(void *,int,int);
void func_ov000_0216a30c(int,int,int);
void DrawTextLine(int,int,int,void *,int,int);
void func_0209b3e8(int,int,int,int,int,int);
u64 func_020c53e4(int);
extern u8 data_ov006_022186ec[],data_ov006_022186f8[],data_ov006_02218704[],data_ov006_02218710[],data_ov006_02218718[],data_ov006_02218720[];
void func_ov006_02212184(void *arg0) {
u8 *p=arg0,*save,*engine,*item;
int x,y,offset,tile,i,j,col,row,ty,xx,yy;int top;
int h,g,f,e,d,c,b,a; int art=0x212; int ytop,chartop,left,right; u32 width,height;
u8 *widget,*record; s64 product; s16 pos;
char name[13];u16 text[13];char digits[13];u64 id;
func_020b3a80(M2C_FIELD(p,void **,0x4c));
x=GetSpriteAnimValue(M2C_FIELD(p,void **,0x48));
y=(s16)Modulo(M2C_FIELD(M2C_FIELD(p,void **,0x4c),s16 *,0x12),M2C_FIELD(M2C_FIELD(p,void **,0x4c),u8 *,7));
offset=y>0?-M2C_FIELD(M2C_FIELD(p,void **,0x4c),u8 *,7):0;
save=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=-x;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=-y;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x38)=-x;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x40)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3e)=-x;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x46)=-y;
Clear3DSpriteLayer(1);Clear3DSpriteLayer(3);
offset=(s16)offset;
tile=((*(u32 *)0x027ffc3c)&1)*0x180+2;
top=24; ytop=y+24; chartop=offset+24;left=x+22;right=x+30;
for(i=0;i<60;i++) {
if(func_020b3960(M2C_FIELD(p,void **,0x4c),(s16)i)) {
if(i+1<10) {
engine=M2C_FIELD(p,u8 **,0x40);
M2C_FIELD(engine,s16 *,6)=left; M2C_FIELD(engine,s16 *,8)=offset+ytop+6;
SetTextSpriteValue(M2C_FIELD(p,void **,0x40),0);
engine=M2C_FIELD(p,u8 **,0x40);engine[40]=(engine[40]&~0xe0)|0x40;
DrawTextSprite(M2C_FIELD(p,void **,0x40));
}
engine=M2C_FIELD(p,u8 **,0x40);M2C_FIELD(engine,s16 *,6)=right;M2C_FIELD(engine,s16 *,8)=offset+ytop+6;
SetTextSpriteValue(M2C_FIELD(p,void **,0x40),i+1);
engine=M2C_FIELD(p,u8 **,0x40);engine[40]=(engine[40]&~0xe0)|0x40;DrawTextSprite(M2C_FIELD(p,void **,0x40));
ty=((s16)chartop)>>3;
item=func_020c52ec(i);
FillU16(0,text,26);
if(item) {
u16 *custom=func_020c53ac(i);
if(custom[0]) func_02007e20(custom,text,26);
else {
id=func_020c5430(item);
if(id) {func_020c5498(name,id);func_02019e64(text,0,name,0,0);}
else MI_CpuCopy8(data_ov006_022186b4,text,26);
}
} else MI_CpuCopy8(data_ov006_022186d0,text,26);
func_020e4cd8(text,M2C_FIELD(gCur3DSpriteEngine,void **,16),M2C_FIELD(gCur3DSpriteEngine,void **,36),6,5,(u16)ty,tile);
tile+=48;row=0;col=0;
j=0;do {if(j==32) {row++;col=0;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,u8 **,44)+col*2,u16 *,(ty+row)<<6)=(data_ov006_022183e0[j]&0x3ff)|0x7000;
j++;col++;
}while(j<64);
top=(s16)(top+16);ytop+=16;chartop+=16;
}
}
if(y<=0) {for(j=0;j<32;j++) M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,u8 **,44)+((top>>3)<<6),u16 *,j*2)=(data_ov006_022183e0[j]&0x3ff)|0x7000;}
gCur3DSpriteEngine[70]|=2;gCur3DSpriteEngine[70]|=8;
record=M2C_FIELD(p,u8 **,0x4c);
i=M2C_FIELD(record,s16 *,8)+1;
engine=M2C_FIELD(p,u8 **,0x40);engine[40]&=~0xe0;
if((u32)i<10) {
engine=M2C_FIELD(p,u8 **,0x40);M2C_FIELD(engine,s16 *,6)=x+214;M2C_FIELD(engine,s16 *,8)=12;
SetTextSpriteValue(M2C_FIELD(p,void **,0x40),0);DrawTextSprite(M2C_FIELD(p,void **,0x40));
}
engine=M2C_FIELD(p,u8 **,0x40);M2C_FIELD(engine,s16 *,6)=x+222;M2C_FIELD(engine,s16 *,8)=12;
SetTextSpriteValue(M2C_FIELD(p,void **,0x40),i);DrawTextSprite(M2C_FIELD(p,void **,0x40));
engine=M2C_FIELD(p,u8 **,0x40);M2C_FIELD(engine,s16 *,6)=x+248;M2C_FIELD(engine,s16 *,8)=12;
SetTextSpriteValue(M2C_FIELD(p,void **,0x40),60);DrawTextSprite(M2C_FIELD(p,void **,0x40));
record=M2C_FIELD(p,u8 **,0x4c);
a=M2C_FIELD(record,s16 *,10)<<12;b=record[4];c=M2C_FIELD(record,s16 *,18);d=record[7];
e=func_02001fb4(0x72000,a);
f=(int)(((s64)e*(b<<12)+0x800)>>12);
g=func_02001fb4(0x72000-f,a-(b<<12));
h=M2C_FIELD(M2C_FIELD(p,void **,0x4c),s16 *,12);
e=func_02001fb4(c<<12,d<<12);
yy=(g*h-(int)(((s64)g*e+0x800)>>12))>>12;
i=f>>12;
if(i>114) i=114;else if(i<1)i=1;
a=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
DrawFrameBorder((s16)(x+248),(s16)(yy+25),2,(s16)i,(u16)(((art>>a)&0x3ff)|0x1000),4,2);
record=M2C_FIELD(p,u8 **,0x4c);
a=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_0208df84((s16)(x+M2C_FIELD(record,s16 *,14)),M2C_FIELD(record,s16 *,16),record[6],record[7],(u16)((((art-32)>>a)&0x3ff)|0x1000),0);
pos=(s16)(x+94);
widget=M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4);
func_02088e84(widget,pos,142,pos,142);
if(Unk02212184Visible(widget)) {
yy=M2C_FIELD(widget,s16 *,0x52);xx=M2C_FIELD(widget,s16 *,0x50);
width=func_020aae10(widget);height=func_020aae44(widget);
func_02087d84(M2C_FIELD(widget,void **,0x64),1,xx,yy,(u16)width,(u16)height);
}
M2C_FIELD(widget,s16 *,0x34)=pos;M2C_FIELD(widget,s16 *,0x36)=142;
if(Unk02212184Visible(widget)) {
yy=M2C_FIELD(widget,s16 *,0x52);xx=M2C_FIELD(widget,s16 *,0x50);
width=func_020aae10(widget);height=func_020aae44(widget);
func_02087d84(M2C_FIELD(widget,void **,0x64),1,xx,yy,(u16)width,(u16)height);
}
pos=(s16)(x+130);
widget=M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8);
func_02088e84(widget,pos,142,pos,142);
if(Unk02212184Visible(widget)) {
yy=M2C_FIELD(widget,s16 *,0x52);xx=M2C_FIELD(widget,s16 *,0x50);
width=func_020aae10(widget);height=func_020aae44(widget);
func_02087d84(M2C_FIELD(widget,void **,0x64),1,xx,yy,(u16)width,(u16)height);
}
M2C_FIELD(widget,s16 *,0x34)=pos;M2C_FIELD(widget,s16 *,0x36)=142;
if(Unk02212184Visible(widget)) {
yy=M2C_FIELD(widget,s16 *,0x52);xx=M2C_FIELD(widget,s16 *,0x50);
width=func_020aae10(widget);height=func_020aae44(widget);
func_02087d84(M2C_FIELD(widget,void **,0x64),1,xx,yy,(u16)width,(u16)height);
}
gCur3DSpriteEngine=(u8 *)g3DSpriteEngineSub;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=-x;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x38)=-x;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x40)=0;
a=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_ov000_0216a374(48,56,(u16)(((0x214>>a)&0x3ff)|0x8000),11);
item=func_020c5328(M2C_FIELD(M2C_FIELD(p,void **,0x4c),s16 *,8));
tile=(((*(u32 *)0x027ffc3c)&1)<<6)+256;
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u8 **,36)+0x550,4,2);
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u8 **,36)+0x55a,4,2);
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u8 **,36)+0x564,4,2);
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u8 **,36)+0x572,4,2);
if(item && func_020c5464(M2C_FIELD(M2C_FIELD(p,void **,0x4c),s16 *,8))==3) {
if(M2C_FIELD(item,s8 *,32)!=-1) {
i=(u16)((((*(u32 *)0x027ffc3c)&1)<<3)+0x21c);
func_ov000_0216a30c(M2C_FIELD(item,s8 *,32),i<<5,8);
a=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_ov000_0216a374(64,168,(u16)(((i>>a)&0x3ff)|0x8000),11);
DrawTextLine(8,21,1,data_ov006_022186ec,0x7000,(u16)tile);
} else DrawTextLine(8,21,1,data_ov006_022186f8,0x7000,(u16)tile);
i=M2C_FIELD(item,u16 *,26);if((u32)i>9999)i=9999;
func_0209b3e8(16,21,1,i,0x7000,(u16)(tile+8));
i=M2C_FIELD(item,u16 *,28);if((u32)i>9999)i=9999;
func_0209b3e8(22,21,1,i,0x7000,(u16)(tile+16));
i=M2C_FIELD(item,u16 *,30);if((u32)i>9999)i=9999;
func_0209b3e8(28,21,1,i,0x7000,(u16)(tile+24));
} else {
DrawTextLine(8,21,1,data_ov006_02218704,0x7000,(u16)(tile+0));
DrawTextLine(14,21,1,data_ov006_02218710,0x7000,(u16)(tile+8));
DrawTextLine(20,21,1,data_ov006_02218718,0x7000,(u16)(tile+16));
DrawTextLine(26,21,1,data_ov006_02218720,0x7000,(u16)(tile+24));
}
gCur3DSpriteEngine[70]|=2;
id=func_020c53e4(0);
if(id) {
func_020c5498(digits,id);
engine=M2C_FIELD(p,u8 **,0x44);engine[40]&=~0xe0;
xx=60;yy=108;
for(i=0;digits[i];i++) {
if(i==6){xx=60;yy+=24;}
engine=M2C_FIELD(p,u8 **,0x44);M2C_FIELD(engine,s16 *,6)=x+xx;M2C_FIELD(engine,s16 *,8)=yy;
SetTextSpriteValue(M2C_FIELD(p,void **,0x44),(s8)digits[i]-48);
DrawTextSprite(M2C_FIELD(p,void **,0x44));xx+=24;
}
}
gCur3DSpriteEngine=save;
}
