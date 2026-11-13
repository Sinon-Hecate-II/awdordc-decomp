/* 13 functions from 0x022121F8 to 0x022131F8 (ov005), found by ds-decomp. */
#include "common.h"
static inline void MarkSpriteEngine(void *engine, u32 mask) {
    M2C_FIELD(engine, u8 *, 0x46) |= mask;
}

s16 HistoryPageDown(void) {
 s16 *HistoryTabAt(s8);
 extern void *gHistoryMenu;
 s16 old;
 s32 limit;
 void *p;
 p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));
 old=M2C_FIELD(p,s16 *,2);
 M2C_FIELD(p,s16 *,2)=old+7;
 limit=M2C_FIELD(p,s16 *,8)-7;
 if(M2C_FIELD(p,s16 *,2)>limit) M2C_FIELD(p,s16 *,2)=limit;
 return M2C_FIELD(p,s16 *,2)-old;
}

#pragma opt_strength_reduction off
void func_ov005_02212244(s32 arg0,s32 arg1) {
 M2C_UNK func_02080860(s32,s32,s32,u16,s32);
 extern void *g3DSpriteEngineMain;
 extern void *gCur3DSpriteEngine;
 void *saved;
 s32 i, x;
 s32 tile;
 saved=gCur3DSpriteEngine;
 gCur3DSpriteEngine=g3DSpriteEngineMain;
 i=0;
 x=0x18;
 do {
 if(i<arg1) tile=0xC4; else tile=0xC8;
 func_02080860(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24)+x*2+((arg0<<5)*2),2,2,(u16)tile,2);
 i++;
 x+=2;
 }while(i<3);
 gCur3DSpriteEngine=saved;
}
#pragma opt_strength_reduction reset
M2C_UNK func_ov005_022122e0(s32 arg0, s32 arg1) {
    void *GetRecordDefinition(M2C_UNK);
    u32 GetRecordValue(M2C_UNK, M2C_UNK);
    s32 GetRecordTier(M2C_UNK, M2C_UNK);
    s32 func_ov005_02211a54(M2C_UNK, M2C_UNK);
    M2C_UNK func_0209b26c(M2C_UNK, s16, M2C_UNK, s32, s32, s32);
    M2C_UNK func_0209b2dc(M2C_UNK, s16, M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK func_0209b3e8(M2C_UNK, s16, M2C_UNK, u32, s32, s32);
    M2C_UNK DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov005_02212244(s32, s32);
    void StringFormat(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern void *data_ov005_02220274;
    extern M2C_UNK data_ov005_02220278[];
    extern M2C_UNK data_ov005_02220280[];
    extern M2C_UNK data_ov005_02220284[];
    void *p;
    u32 money;
    s32 status;
    s32 y;
    void *saved;
    M2C_UNK buf[4];
    M2C_UNK lo[4];

    p = GetRecordDefinition(0);
    money = GetRecordValue(0, arg1);
    status = GetRecordTier(0, arg1);
    y = (arg0 + 1) * 0x2E + 0x144;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    if (func_ov005_02211a54(0, arg1) == 0) {
        func_0209b26c(2, (s16)(arg0 + 5), 1, M2C_FIELD(p, s32 *, 0), 0x1000, (u16)y);
        if (M2C_FIELD(p, u16 *, 0x4) == 0) {
            func_0209b3e8(0x10, (s16)(arg0 + 5), 1, M2C_FIELD(data_ov005_02220274, s32 *, 0x4), 0x1000, (u16)(y + 0x1E));
            DrawTextLine(0x11, (s16)(arg0 + 5), 1, (M2C_UNK)data_ov005_02220278, 0x1000, (u16)(y + 0x24));
            StringFormat((M2C_UNK)buf, (M2C_UNK)data_ov005_02220284, M2C_FIELD(data_ov005_02220274, s32 *, 0xC));
            lo[0] = buf[0];
            lo[1] = buf[1];
            lo[2] = 0;
            lo[3] = 0;
            DrawTextLine(0x12, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[2], 0x1000, (u16)(y + 0x26));
            DrawTextLine(0x13, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[0], 0x1000, (u16)(y + 0x28));
            DrawTextLine(0x14, (s16)(arg0 + 5), 1, (M2C_UNK)data_ov005_02220280, 0x1000, (u16)(y + 0x2A));
            StringFormat((M2C_UNK)buf, (M2C_UNK)data_ov005_02220284, M2C_FIELD(data_ov005_02220274, s32 *, 0xC));
            DrawTextLine(0x15, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[2], 0x1000, (u16)(y + 0x2C));
            DrawTextLine(0x16, (s16)(arg0 + 5), 1, (M2C_UNK)&lo[0], 0x1000, (u16)(y + 0x2E));
        } else {
            if (money > 0x5F5E0FFU) money = 0x5F5E0FF;
            func_0209b3e8(0x16, (s16)(arg0 + 5), 1, money, 0x1000, (u16)(y + 0x1E));
        }
    } else {
        if (money > 0x5F5E0FFU) money = 0x5F5E0FF;
        func_0209b3e8(0x16, (s16)(arg0 + 5), 1, money, 0x1000, (u16)(y + 0x1E));
    }
    func_ov005_02212244(arg0 + 5, status);
    gCur3DSpriteEngine = saved;
    return 0;
}

void func_ov005_02212624(s32 arg0,M2C_UNK arg1) {
M2C_UNK func_02080860(s32,s32,s32,u16,s32);
M2C_UNK func_0209b26c(M2C_UNK,s16,M2C_UNK,s32,s32,s32);
M2C_UNK func_0209b2dc(M2C_UNK,s16,M2C_UNK,M2C_UNK,s32,s32,s32);
M2C_UNK func_0209b3e8(M2C_UNK,s16,M2C_UNK,u32,s32,s32);
s32 func_020a7298(u16,M2C_UNK);
void *GetRecordDefinition(M2C_UNK);
u32 GetRecordValue(M2C_UNK,M2C_UNK);
s32 GetRecordTier(M2C_UNK,M2C_UNK);
s32 func_ov005_02211a54(M2C_UNK,M2C_UNK);
extern void *g3DSpriteEngineMain,*gCur3DSpriteEngine;
void *p;u32 money;s32 t,last;u32 saved;
p=GetRecordDefinition(1);money=GetRecordValue(1,arg1);t=GetRecordTier(1,arg1);
last=arg1;arg1=(arg0+1)*46+0x144;saved=(u32)gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
if(func_ov005_02211a54(1,last)==0){
func_02080860(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24)+4+((arg0+5)<<6),2,2,(u16)(func_020a7298(M2C_FIELD(p,u16 *,4),0)*4+0xcc),3);
func_0209b26c(4,(s16)(arg0+5),1,M2C_FIELD(p,s32 *,0),0x1000,(u16)arg1);
if(money>0x5f5e0ffU)money=0x5f5e0ff;
func_0209b3e8(22,(s16)(arg0+5),1,money,0x1000,(u16)(arg1+30));
}else func_0209b2dc(2,(s16)(arg0+5),1,0x45000000,0x1000,3,(u16)arg1);
func_ov005_02212244(arg0+5,t);gCur3DSpriteEngine=(void *)saved;
}

#pragma opt_common_subs on
void func_ov005_022127b4(s32 arg0,s32 arg1){
M2C_UNK func_02080860(s32,s32,s32,u16,s32);
M2C_UNK func_0209b26c(s32,s16,s32,s32,s32,s32);
M2C_UNK func_0209b2dc(s32,s16,s32,s32,s32,s32,s32);
M2C_UNK func_0209b3e8(s32,s16,s32,u32,s32,s32);
s32 func_020a7298(u16,s32);
void *GetRecordDefinition(s32);
u32 GetRecordValue(s32,s32);s32 GetRecordTier(s32,s32);s32 func_ov005_02211a54(s32,s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
void *p;u32 value;register s32 status,position;void *saved;
p=GetRecordDefinition(2);value=GetRecordValue(2,arg1);status=GetRecordTier(2,arg1);
{ s32 index=arg1;
position=(arg0+1)*46+0x144;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
if(!func_ov005_02211a54(2,index)){
func_02080860(M2C_FIELD(gCur3DSpriteEngine,s32 *,36)+4+((arg0+5)<<6),2,2,(u16)(func_020a7298(M2C_FIELD(p,u16 *,4),1)*4+0xcc),6);
func_0209b26c(4,(s16)(arg0+5),1,M2C_FIELD(p,s32 *,0),4096,(u16)position);
if(value>99999999U)value=99999999;
func_0209b3e8(22,(s16)(arg0+5),1,value,4096,(u16)(position+30));
}else func_0209b2dc(2,(s16)(arg0+5),1,0x45000000,4096,3,(u16)position);
func_ov005_02212244(arg0+5,status);gCur3DSpriteEngine=saved;
}}
void func_ov005_02212944(s32 arg0,s32 arg1) {
 M2C_UNK func_ov005_022122e0(s32,s32);
 void func_ov005_02212624(s32,s32);
 void func_ov005_022127b4(s32,s32);
 extern void *gHistoryMenu;
 switch(M2C_FIELD(gHistoryMenu,s8 *,1)) {
 case 0: func_ov005_022122e0(arg0,arg1); return;
 case 1: func_ov005_02212624(arg0,arg1); return;
 case 2: func_ov005_022127b4(arg0,arg1); return;
 }
}

#pragma optimization_level 2
void func_ov005_0221298c(s16 arg0) {
s16 *HistoryTabAt(s8);
void func_ov005_02212944(s32,s32);
void ClearTileRect(void *,s32,s32);
void func_0209c048(s32,s16,void *,s32,s32,s32);
void func_0209c024(s32,s16,void *,s32,s32,s32);
s32 func_020a8b78(void);
extern void *gHistoryMenu;
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
s16 *p;
void *saved;
s32 a,f,b,e,c,d;
s32 value;
p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
ClearTileRect((u8 *)M2C_FIELD(g3DSpriteEngineMain,void **,0x24)+0x140,0x20,0xe);
if(arg0&1){
a=0;
b=arg0>>1;
c=-1;
do{func_ov005_02212944(c,b);a++;b++;c+=2;}while(a<8);
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x100,0x20,1);
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x4c0,0x20,1);
}else{
d=0;
e=0;
f=arg0>>1;
do{func_ov005_02212944(e,f);d++;f++;e+=2;}while(d<7);
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0xf4,6,2);
}
func_0209c048(0x1b,3,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),M2C_FIELD(p,s16 *,6),0x1000,0);
value=func_020a8b78();
func_0209c024(0x1c,3,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),value,0x1000,0);
func_0209c048(0x1e,3,M2C_FIELD(gCur3DSpriteEngine,void **,0x24),M2C_FIELD(p,s16 *,8),0x1000,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_dead_code off
void func_ov005_02212b40(void){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*gHistoryMenu;
extern u8 data_ov005_0222028c[],data_ov005_0222029c[];
void *HeapAllocBlock(s32);
void *saved,*buffer;
s32 i,j;
void *tile;
s32 offset,row;
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineSub;
buffer=HeapAllocBlock(512);
func_01ff9d88(0);
OpenNarcArchive(data_ov005_0222028c);
LoadNarcFileToBuffer(data_ov005_0222029c,buffer,0,0);
CloseNarcArchive();
i=0;offset=0;
do{
if(M2C_FIELD((u8 *)gHistoryMenu+i,u8 *,0x40)){
tile=(u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0x20)+offset*2+0x340;
func_02080a14(tile,4,8,(u8 *)buffer+offset*2);
j=0;row=0;
do{
AddToU16Array((u8 *)tile+row*2,8,1);
row+=32;j++;
}while(j<8);
func_020808dc(tile,4,8,(u16)(i+1));
}
i++;offset+=4;
}while(i<8);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
HeapFreeBlock(buffer);
func_01ff9d88(1);
func_0209c048(26,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24),M2C_FIELD(gHistoryMenu,u16 *,0x2e),0x9000,0);
func_0209c024(27,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24),func_020a8b78(),0x9000,0);
func_0209c048(30,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24),M2C_FIELD(gHistoryMenu,u16 *,0x30),0x9000,0);
func_0209b59c((u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0x1c)+0x1480,0x60);
func_0209b5c4((u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0x1c)+0x1480,M2C_FIELD(gHistoryMenu,s32 *,0x34));
func_0209b59c((u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0x1c)+0x1780,0x60);
func_0209b5c4((u8 *)M2C_FIELD(g3DSpriteEngineSub,void **,0x1c)+0x1780,M2C_FIELD(gHistoryMenu,s32 *,0x38));
func_ov000_0216a30c(M2C_FIELD(gHistoryMenu,s8 *,0x32),0x1a80,9);
M2C_FIELD(g3DSpriteEngineSub,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
}
#pragma pop
void func_ov005_02212db8(void) {
 M2C_UNK SetFileDirectory(M2C_UNK *);
 M2C_UNK OpenNarcArchive();
 M2C_UNK CloseNarcArchive();
 M2C_UNK LoadNarcFileToBuffer(s32,s32,s32,s32);
 s32 GetLocalizedFileName(M2C_UNK *);
 extern void *g3DSpriteEngineMain;
 extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_ov005_022202ac, data_ov005_022202bc, data_ov005_022202cc;
 SetFileDirectory(&data_ov005_022202ac);
 GetLocalizedFileName(&data_ov005_022202bc);
 OpenNarcArchive();
 LoadNarcFileToBuffer(GetLocalizedFileName(&data_ov005_022202cc),M2C_FIELD(g3DSpriteEngineMain,s32 *,0x28),0,0);
 CloseNarcArchive();
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 4;
}

void func_ov005_02212e20(void) {
 M2C_UNK SetFileDirectory(M2C_UNK *);
 M2C_UNK OpenNarcArchive();
 M2C_UNK CloseNarcArchive();
 M2C_UNK LoadNarcFileToBuffer(s32,s32,s32,s32);
 s32 GetLocalizedFileName(M2C_UNK *);
 extern void *g3DSpriteEngineMain;
 extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_ov005_022202e0, data_ov005_022202f0, data_ov005_02220300;
 SetFileDirectory(&data_ov005_022202e0);
 GetLocalizedFileName(&data_ov005_022202f0);
 OpenNarcArchive();
 LoadNarcFileToBuffer(GetLocalizedFileName(&data_ov005_02220300),M2C_FIELD(g3DSpriteEngineMain,s32 *,0x28),0,0);
 CloseNarcArchive();
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 4;
}

void func_ov005_02212e88(void) {
 M2C_UNK SetFileDirectory(M2C_UNK *);
 M2C_UNK OpenNarcArchive();
 M2C_UNK CloseNarcArchive();
 M2C_UNK LoadNarcFileToBuffer(s32,s32,s32,s32);
 s32 GetLocalizedFileName(M2C_UNK *);
 extern void *g3DSpriteEngineMain;
 extern void *gCur3DSpriteEngine;
 extern M2C_UNK data_ov005_02220314, data_ov005_02220324, data_ov005_02220334;
 SetFileDirectory(&data_ov005_02220314);
 GetLocalizedFileName(&data_ov005_02220324);
 OpenNarcArchive();
 LoadNarcFileToBuffer(GetLocalizedFileName(&data_ov005_02220334),M2C_FIELD(g3DSpriteEngineMain,s32 *,0x28),0,0);
 CloseNarcArchive();
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 4;
}

void func_ov005_02212ef0(void) {
    s16 *HistoryTabAt(s8);
    M2C_UNK func_ov005_02211a8c();

    void func_ov005_02212db8();
    void func_ov005_02212e20();
    void func_ov005_02212e88();
    extern void *gHistoryMenu;
    s8 temp_r0;

    temp_r0 = M2C_FIELD(gHistoryMenu, s8 *, 1);
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_ov005_02212db8();
        break;
    case 1:
        func_ov005_02212e20();
        break;
    case 2:
        func_ov005_02212e88();
        break;
    }
    func_ov005_0221298c(*HistoryTabAt(M2C_FIELD(gHistoryMenu, s8 *, 1)));
    func_ov005_02211a8c();
}

#pragma opt_common_subs off
void func_ov005_02212f54(void) {
s16 *HistoryTabAt(s8);s32 func_02001fb4(s32,s32);
void DrawFrameBorder(s16,s16,s16,s16,s32,s32,s32);
void AddSprite(u16,u16,u16,void *,s32);
void *GetLocalizedText(s32);s32 MeasureStringWidth(void *);
void DrawTileRow(u16,s16,s32,u16,s32);
void func_ov000_0216a374(u16,u16,u16,s32);
extern void *gHistoryMenu,*gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
extern u8 gSpriteDesc16x16[];
s16 *p;void *saved;s32 total,amount,ratio,left,height,width;u16 attr; s32 text;
p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
total=p[4]<<12;amount=p[1]<<12;
ratio=func_02001fb4(0x73000,total);
left=(s32)(((s64)ratio*(u64)0x7000+0x800)>>12);
height=func_02001fb4(0x73000-left,total-0x7000);
height=(s32)(((s64)height*amount+0x800)>>12);
width=left>>12;if(width>115)width=115;else if(width<1)width=1;
attr=(u16)(((0x140 >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x6000);
DrawFrameBorder(248,(s16)((height>>12)+40),2,(s16)width,attr,0,2);
gCur3DSpriteEngine=g3DSpriteEngineSub;
AddSprite(174,9,(u16)(((0xa0 >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x8000),gSpriteDesc16x16,0);
text=MeasureStringWidth(GetLocalizedText(M2C_FIELD(gHistoryMenu,s32 *,0x34)));
DrawTileRow((u16)((252-text)&511),30,96,(u16)(((0xa4 >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x2000),0);
text=MeasureStringWidth(GetLocalizedText(M2C_FIELD(gHistoryMenu,s32 *,0x38)));
DrawTileRow((u16)((252-text)&511),54,96,(u16)(((0xbc >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x2000),0);
func_ov000_0216a374(220,78,(u16)(((0xd4 >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&0x3ff)|0x9000),0);
gCur3DSpriteEngine=saved;
}
#pragma opt_common_subs reset
