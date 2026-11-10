/* 7 functions from 0x0216E178 to 0x0216ECC8 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct MenuDisplayConfig { u16 fields[6]; } MenuDisplayConfig;

#pragma opt_strength_reduction off
#pragma opt_lifetimes off
void func_ov000_0216e178(void *arg0) {
extern s32 data_ov000_021df5e0; extern void **gCurrentMap; extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineMain; extern void *g3DSpriteEngineSub; extern u16 data_ov000_021adcfc[];
s32 func_020e34bc(s32); s32 func_020cfb94(void); s32 func_020a8c10(s32);
void func_ov000_0216e054(void);void func_ov000_0216dd0c(void);void func_ov000_0216e09c(s32); void *func_020e3218(void *); void *func_ov000_0216ce10(s32);void *func_ov000_0216ce84(s32);s32 func_020a7290(void);void *func_020a7278(void);void *func_020a72e8(s32);s32 func_020ae22c(s32);
extern u8 data_ov000_021b88e8[];extern u8 data_ov000_021b88fc[];extern u8 data_ov000_021b890c[];extern u8 data_ov000_021b8924[];extern u8 data_ov000_021b8934[];extern u8 data_ov000_021b8948[];extern u8 data_ov000_021b8958[];extern u8 data_ov000_021b896c[];extern u8 data_ov000_021b897c[];extern u8 data_ov000_021b898c[];extern u8 data_ov000_021b89a0[];s32 i,n,t; void *p,*dest,*old; volatile MenuDisplayConfig a,b;
a=*(MenuDisplayConfig*)&data_ov000_021adcfc[9];b=*(MenuDisplayConfig*)&data_ov000_021adcfc[3];data_ov000_021df5e0=func_020e34bc(36);func_02082c84();func_020026d8(1);func_02002968(2);func_02003124(4);func_020031cc(8);func_02002ab8(16);func_02002bb8(32);func_0200323c(128);func_020032bc(256);
M2C_FIELD(data_ov000_021df5e0,u8*,16)=0;M2C_FIELD(data_ov000_021df5e0,u8*,17)=0;M2C_FIELD(data_ov000_021df5e0,u16*,18)=12;M2C_FIELD(data_ov000_021df5e0,u16*,20)=0;M2C_FIELD(data_ov000_021df5e0,u8*,12)=0;
n=0;for(i=0;i<func_020cfb94();i++){p=(u8*)*gCurrentMap+0x67a4+(i+1)*140;if(M2C_FIELD(p,u8*,30)&&!M2C_FIELD(p,u8*,25)){M2C_FIELD(data_ov000_021df5e0,u8*,n)=i+1;M2C_FIELD(data_ov000_021df5e0,u8*,n+8)=M2C_FIELD(*gCurrentMap,u8*,0x67c1+(i+1)*140);M2C_FIELD(data_ov000_021df5e0,u8*,n+4)=func_020a8c10(i+1);n++;M2C_FIELD(data_ov000_021df5e0,u8*,12)++;}}
for(i=0;i<M2C_FIELD(data_ov000_021df5e0,u8*,12);i++)if(M2C_FIELD(arg0,s16*,108)==M2C_FIELD(data_ov000_021df5e0,u8*,i))func_ov000_0216e09c(i);
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020822b8(&a);
{u16 *volatile q00; q00=*(u16**)gCur3DSpriteEngine;*q00=*q00|16;}
{u16 *volatile q01; q01=*(u16**)gCur3DSpriteEngine;*q01=*q01|32;}
{u16 *volatile q02; q02=*(u16**)gCur3DSpriteEngine;*q02=*q02|64;}
{u16 *volatile q03; q03=*(u16**)gCur3DSpriteEngine;*q03=*q03|128;}
{u16 *volatile q04; q04=*(u16**)gCur3DSpriteEngine;*q04=*q04|256;}
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,6)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,6)&~3)|0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,8)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,8)&~3)|1;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,10)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,10)&~3)|2;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,12)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,12)&~3)|3;
{u16 *volatile q05; q05=(u16*)((u8*)*(void**)gCur3DSpriteEngine+18);*q05=*q05&~192;}M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,81)=0;M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,82)=0;M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,83)=0;func_02099450(1,0,0);func_ov000_0216cee8();func_020814e4(func_020e3218(&data_ov000_021b88e8));func_02081590(func_020e3218(&data_ov000_021b88fc),M2C_FIELD(g3DSpriteEngineMain,void**,20));func_02081590(func_020e3218(&data_ov000_021b890c),M2C_FIELD(g3DSpriteEngineMain,void**,40));func_02081528();func_0208116c(&data_ov000_021b8924,0,32);M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=1;M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;func_02080cfc(&data_ov000_021b8934,(u8*)M2C_FIELD(g3DSpriteEngineMain,void**,28)+0x2e00);func_0208116c(&data_ov000_021b8948,0x2c0,32);
for(i=0,t=0x160;i<M2C_FIELD(data_ov000_021df5e0,u8*,12);i++,t+=4){p=(u8*)*gCurrentMap+0x67a4+M2C_FIELD(data_ov000_021df5e0,u8*,i)*140;dest=(u8*)M2C_FIELD(g3DSpriteEngineMain,void**,28)+(t<<5);func_02007ef4(func_ov000_0216ce10(M2C_FIELD(p,u8*,39)),dest,128);func_01ff9e44(func_ov000_0216ce84(M2C_FIELD(p,u8*,29)),(i+23)<<5,32);}
func_020e3058(data_ov000_021df5e0+24,220,0,15,320,3,256,arg0,1);func_020e3058(data_ov000_021df5e0+28,160,0,14,328,3,512,arg0,0);func_020e3058(data_ov000_021df5e0+24,224,160,2,336,3,2,arg0,0);
t=func_020a7290()<<5;dest=(u8*)M2C_FIELD(g3DSpriteEngineMain,void**,28)+0x36a0;func_02007ef4(func_020a7278(),dest,t);func_01ff9e44(func_020a72e8(1),0x360,128);func_02091d4c(1);func_0208ca2c(4096,1,func_020ae22c(9),2);func_020aeebc(3,15,3);
gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(&b);{u16 *volatile q10; q10=*(u16**)gCur3DSpriteEngine;*q10=*q10|16;}
{u16 *volatile q11; q11=*(u16**)gCur3DSpriteEngine;*q11=*q11|32;}
{u16 *volatile q12; q12=*(u16**)gCur3DSpriteEngine;*q12=*q12|64;}
{u16 *volatile q13; q13=*(u16**)gCur3DSpriteEngine;*q13=*q13|128;}
{u16 *volatile q14; q14=*(u16**)gCur3DSpriteEngine;*q14=*q14|256;}
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,6)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,6)&~3)|0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,8)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,8)&~3)|1;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,10)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,10)&~3)|2;
M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,12)=(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,12)&~3)|3;
{u16 *volatile q15; q15=(u16*)((u8*)*(void**)gCur3DSpriteEngine+18);*q15=*q15&~192;}M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,81)=0;M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,82)=0;M2C_FIELD(*(void**)gCur3DSpriteEngine,u8*,83)=0;func_02099450(1,0,0);func_ov000_0216cee8();func_020814e4(func_020e3218(&data_ov000_021b8958));func_02081590(func_020e3218(&data_ov000_021b896c),M2C_FIELD(g3DSpriteEngineSub,void**,20));func_02081528();func_0208116c(&data_ov000_021b897c,0,32);M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=1;M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;func_02080cfc(&data_ov000_021b898c,(u8*)M2C_FIELD(g3DSpriteEngineSub,void**,28)+0x3480);func_0208116c(&data_ov000_021b89a0,0x2e0,32);func_020e3004();func_020e304c();func_0208116c(&data_ov000_021b8948,0x2c0,32);func_ov000_0216cee8();func_02091d4c(1);func_02091d4c(18);func_ov000_0216d020();M2C_FIELD(data_ov000_021df5e0,u8*,17)=1;func_ov000_0216d130();func_ov000_0216d1c8();func_ov000_0216d23c();func_020aef7c(3,15,3);gCur3DSpriteEngine=old;func_020b1b3c();func_ov000_0216cee8();func_ov000_0216e054();func_ov000_0216dd0c();M2C_FIELD(data_ov000_021df5e0,u16*,20)=0;
}
#pragma opt_strength_reduction reset
#pragma opt_instruction_scheduling reset
void func_ov000_0216ea10(void) {
    M2C_UNK func_ov000_0216e110();
    func_ov000_0216e110();
}

/* Handles up/down/LR input while a unit list menu is open. */
void func_ov000_0216ea1c(void) {
    extern u16 *gKeyState;
    extern s32 data_ov000_021df5e0;
    M2C_UNK PlaySoundEffect(s32);
    void func_ov000_0216e09c(s32);
    void func_ov000_0216e054(void);
    void func_ov000_0216dd0c(void);
    void func_ov000_0216ebac(void);
    u16 keys = gKeyState[0];
    if (keys & 2) { func_ov000_0216ebac(); return; }
    if (gKeyState[1] & 0x10) {
        if (M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) == M2C_FIELD(data_ov000_021df5e0, u8 *, 0xc) - 1) {
            if (keys & 0x10) { PlaySoundEffect(0x10019); func_ov000_0216e09c(0); func_ov000_0216e054(); }
        } else { PlaySoundEffect(0x10019); func_ov000_0216e09c(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) + 1); func_ov000_0216e054(); }
    }
    if (gKeyState[1] & 0x20) {
        if (M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) == 0) {
            if (gKeyState[0] & 0x20) { PlaySoundEffect(0x10019); func_ov000_0216e09c(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xc) - 1); func_ov000_0216e054(); }
        } else { PlaySoundEffect(0x10019); func_ov000_0216e09c(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) - 1); func_ov000_0216e054(); }
    }
    if ((gKeyState[0] & 0x100) || (gKeyState[0] & 0x200)) {
        PlaySoundEffect(0x10020);
        M2C_FIELD(data_ov000_021df5e0, u8 *, 0x10)++;
        M2C_FIELD(data_ov000_021df5e0, u8 *, 0x10) &= 1;
        func_ov000_0216dd0c();
    }
}

void func_ov000_0216eb7c(void) {
    M2C_UNK func_0209bfa8();
    M2C_UNK func_020e35cc();
    extern s32 data_ov000_021df5e0;
    if (data_ov000_021df5e0 != 0) {
        func_020e35cc();
        data_ov000_021df5e0 = 0;
    }
    func_0209bfa8();
}

void func_ov000_0216ebac(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020b21e0();
    M2C_UNK func_020b2268();
    extern M2C_UNK data_ov000_021b87b8;
    PlaySoundEffect(0x10018);
    func_020b21e0();
    func_020b2268();
    func_01ffa3dc(&data_ov000_021b87b8, 7);
}

void func_ov000_0216ebd8(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b87f0;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov000_021b87f0, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, u16 *, 0x6C) = (u16) M2C_FIELD(*gCurrentMap, u16 *, 0x52A4);
    M2C_FIELD(temp_r0, s16 *, 0x6E) = 0;
}

#pragma opt_lifetimes off
s32 func_ov000_0216ec1c(void){extern u8 *data_ov000_021df5e4[2];extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];s32 i,n;void *base;u8 (*entries)[14];u16 start;for(i=0;i<64;i++)data_ov000_021df5e4[1][i]=0;base=*gCurrentMap;start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51;i++){entries=base+0x59a4;if((u32)(entries[i][0]<<26)>>26)n++;}return n;}
#pragma opt_lifetimes reset
