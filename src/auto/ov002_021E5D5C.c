/* 2 functions from 0x021E5D5C to 0x021E6D04 (ov002), found by ds-decomp. */
#include "common.h"
extern u8 data_ov002_021f2dfc[],data_ov002_021f2e14[],data_ov002_021f2e2c[],data_ov002_021f2e34[];
void *LoadDecompressedFile(void *,s32);
extern u8 gDemoBattle[],data_ov002_021f2d94[],data_ov002_021f2da0[],data_ov002_021f2dac[],data_ov002_021f2db8[],gUnitViews[],data_ov002_021f2dc4[],data_ov002_021f2dcc[],data_ov002_021f2dd4[],data_ov002_021f2de8[],gPlayerSettings[];extern s32 gCur3DSpriteEngine;
void *GetLocalizedFileName(void *);u8 *LoadFileToBuffer(void *,s32);void *HeapAllocBlock(s32);


M2C_UNK func_ov002_021e5d5c(M2C_UNK arg0){
s32 side,mode;u8 *dest=(u8 *)arg0,*country,*settings; s32 res,i,j,shade;u8 *palette,*resource,*state;u16 tiles=0;u16 pal=tiles;u32 size;u8 *other;
if(gDemoBattle[0]){LoadDemoBattleGraphics(0x6800000,0x6890000);tiles=(u16)(tiles+96);pal=(u16)(pal+1);}
GX_BeginLoadTex();M2C_FIELD(dest,u16 *,200)=tiles;
size=LoadDecompressedFileTo(data_ov002_021f2d94,0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));
GX_EndLoadTex();GX_BeginLoadTexPltt();M2C_FIELD(dest,u8 *,202)=pal;
ReadFileSection(data_ov002_021f2da0,0x6890000+(pal<<5),128,32);pal=(u16)(pal+1);GX_EndLoadTexPltt();
LoadDecompressedFileTo(GetLocalizedFileName(data_ov002_021f2dac),M2C_FIELD(gCur3DSpriteEngine,s32 *,28)+2048);
palette=LoadFileToBuffer(data_ov002_021f2db8,1);
CopyToObjPaletteShadow(palette+(gPlayerSettings[25]<<5),544,32);CopyToObjPaletteShadow(palette+(gPlayerSettings[49]<<5),576,32);
M2C_FIELD(gUnitViews,u16 *,6)=M2C_FIELD(palette+(gPlayerSettings[25]<<5),u16 *,30);
M2C_FIELD(gUnitViews,u16 *,50)=M2C_FIELD(palette+(gPlayerSettings[49]<<5),u16 *,30);
HeapFreeBlock(palette);
state=gUnitViews;country=dest;settings=gPlayerSettings;side=0;do{
GX_BeginLoadTex();
M2C_FIELD(country,u16 *,24)=tiles;resource=M2C_FIELD(M2C_FIELD(settings,void **,4)+settings[24]*4,void **,0);if(resource){size=LoadDecompressedFileTo(M2C_FIELD(resource,void **,0),0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,26)=tiles;resource=M2C_FIELD(M2C_FIELD(settings,void **,4)+settings[19]*4,void **,8);if(resource){size=LoadDecompressedFileTo(M2C_FIELD(resource,void **,0),0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,28)=tiles;resource=settings[19]==0?M2C_FIELD(M2C_FIELD(settings,void **,4),void **,16):0;if(resource){size=LoadDecompressedFileTo(M2C_FIELD(resource,void **,0),0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,30)=tiles;
resource=M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,4)+M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,u8 *,19)*4,void **,20);if(resource){size=LoadDecompressedFileTo(M2C_FIELD(resource,void **,0),0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,32)=tiles;
resource=M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,4)+M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,u8 *,19)*4,void **,28);if(!resource)resource=M2C_FIELD(M2C_FIELD(settings,void **,4),void **,36);
if(resource){size=LoadDecompressedFileTo(M2C_FIELD(resource,void **,0),0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,34)=tiles;resource=M2C_FIELD(M2C_FIELD(settings,void **,4),void **,36);if(resource){size=LoadDecompressedFileTo(M2C_FIELD(resource,void **,0),0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,36)=tiles;resource=M2C_FIELD(M2C_FIELD(settings,void **,8),void **,16);if(resource){size=LoadDecompressedFileTo(resource,0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));}
M2C_FIELD(country,u16 *,38)=tiles;
if(settings[21]){if(settings[22]!=2)mode=0;else {mode=2;res=ComparePlayerGauges(state);switch(res){case 1:mode=3;break;case 2:mode=4;break;}}size=LoadFaceGraphics(settings[21],mode,0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));SetFileDirectory(data_ov002_021f2dc4);}
M2C_FIELD(country,u16 *,40)=tiles;
if(settings[21]){if(settings[22]!=2)mode=0;else {mode=2;res=CompareUnitViewGauges(state,0);switch(res){case 1:mode=3;break;case 2:mode=4;break;}}size=LoadFaceGraphics(settings[21],mode,0x6800000+(tiles<<5));size=(size+31)&~31;tiles=(u16)(tiles+(size>>5));SetFileDirectory(data_ov002_021f2dcc);}
GX_EndLoadTex();GX_BeginLoadTexPltt();
resource=M2C_FIELD(M2C_FIELD(settings,void **,4)+settings[24]*4,void **,0);palette=HeapAllocBlock(128);
if(resource)ReadFileSection(M2C_FIELD(resource,void **,8),(s32)palette,settings[25]<<7,128);else MI_CpuFill32(0,palette,128);
if(func_ov002_021e8038(gPlayerSettings,side)){
if(func_ov002_021e805c(gPlayerSettings,side)||func_ov002_021e80a4(gPlayerSettings,side))ReadFileSection(data_ov002_021f2dd4,(s32)(palette+64),0,64);
else if(func_ov002_021e8080(gPlayerSettings,side))ReadFileSection(data_ov002_021f2de8,(s32)(palette+64),0,64);
}
if(M2C_FIELD(M2C_FIELD(settings,void **,4),u8 *,61)!=2&&M2C_FIELD(M2C_FIELD(settings,void **,4),u8 *,61)!=3)for(i=0;i<4;i++)M2C_FIELD(palette+i*32,u16 *,30)=M2C_FIELD(country,u16 *,96);
for(i=0;i<5;i++){
MI_CpuCopy32(palette,0x6890000+(pal<<5),128);
for(j=0;j<4;j++)FadePaletteTowardsBlack(0x6890000+((pal+j)<<5),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));
M2C_FIELD(country+(u32)i*8,u8 *,45)=pal;pal=(u16)(pal+4);
}
for(i=0;i<4;i++)func_020ae480(palette+i*32,9,9,9);
MI_CpuCopy32(palette,0x6890000+(pal<<5),128);
for(i=0;i<5;i++){
MI_CpuCopy32(palette,0x6890000+(pal<<5),128);
for(j=0;j<4;j++)FadePaletteTowardsBlack(0x6890000+((pal+j)<<5),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));
M2C_FIELD(country+(u32)i*8,u8 *,46)=pal;pal=(u16)(pal+4);
}HeapFreeBlock(palette);
resource=M2C_FIELD(M2C_FIELD(settings,void **,4)+settings[19]*4,void **,8);if(resource){ReadFileSection(M2C_FIELD(resource,void **,8),(0x6890000+((pal)<<5)),0,32);for(j=1;j<5;j++)MI_CpuCopy32((void *)(0x6890000+((pal)<<5)),(0x6890000+((pal+j)<<5)),32);for(i=0;i<5;i++){FadePaletteTowardsBlack((0x6890000+((pal)<<5)),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));M2C_FIELD(country+(u32)i*8,u8 *,47)=pal;pal=(u16)(pal+1);}}resource=settings[19]==0?M2C_FIELD(M2C_FIELD(settings,void **,4),void **,16):0;if(resource){ReadFileSection(M2C_FIELD(resource,void **,8),(0x6890000+((pal)<<5)),0,32);for(j=1;j<5;j++)MI_CpuCopy32((void *)(0x6890000+((pal)<<5)),(0x6890000+((pal+j)<<5)),32);for(i=0;i<5;i++){FadePaletteTowardsBlack((0x6890000+((pal)<<5)),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));M2C_FIELD(country+(u32)i*8,u8 *,48)=pal;pal=(u16)(pal+1);}ReadFileSection(M2C_FIELD(resource,void **,8),(0x6890000+((pal)<<5)),0,32);for(j=1;j<5;j++)MI_CpuCopy32((void *)(0x6890000+((pal)<<5)),(0x6890000+((pal+j)<<5)),32);for(i=0;i<5;i++){FadePaletteTowardsBlack((0x6890000+((pal)<<5)),M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,8)+i,u8 *,28));M2C_FIELD(dest+(side==0?1:0)*100+i*8,u8 *,50)=pal;pal=(u16)(pal+1);}}resource=M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,4)+M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,u8 *,19)*4,void **,20);if(resource){
ReadFileSection(M2C_FIELD(resource,void **,8),(0x6890000+((pal)<<5)),0,32);
if(func_ov002_021e7fec(gPlayerSettings,side==0?1:0)){
if(func_ov002_021e805c(gPlayerSettings,side)||func_ov002_021e80a4(gPlayerSettings,side))ReadFileSection(data_ov002_021f2dfc,(0x6890000+((pal)<<5)),0,32);
else if(func_ov002_021e8080(gPlayerSettings,side))ReadFileSection(data_ov002_021f2e14,(0x6890000+((pal)<<5)),0,32);
}for(j=1;j<5;j++)MI_CpuCopy32((void *)(0x6890000+((pal)<<5)),(0x6890000+((pal+j)<<5)),32);for(i=0;i<5;i++){FadePaletteTowardsBlack((0x6890000+((pal)<<5)),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));M2C_FIELD(country+(u32)i*8,u8 *,49)=pal;pal=(u16)(pal+1);}}resource=M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,4)+M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,u8 *,19)*4,void **,28);if(!resource)resource=M2C_FIELD(M2C_FIELD(settings,void **,4),void **,36);
if(resource){ReadFileSection(M2C_FIELD(resource,void **,8),(0x6890000+((pal)<<5)),0,32);for(j=1;j<5;j++)MI_CpuCopy32((void *)(0x6890000+((pal)<<5)),(0x6890000+((pal+j)<<5)),32);for(i=0;i<5;i++){FadePaletteTowardsBlack((0x6890000+((pal)<<5)),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));M2C_FIELD(country+(u32)i*8,u8 *,51)=pal;pal=(u16)(pal+1);}}resource=M2C_FIELD(M2C_FIELD(settings,void **,4),void **,36);if(resource){ReadFileSection(M2C_FIELD(resource,void **,8),(0x6890000+((pal)<<5)),0,32);for(j=1;j<5;j++)MI_CpuCopy32((void *)(0x6890000+((pal)<<5)),(0x6890000+((pal+j)<<5)),32);for(i=0;i<5;i++){FadePaletteTowardsBlack((0x6890000+((pal)<<5)),M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));M2C_FIELD(country+(u32)i*8,u8 *,52)=pal;pal=(u16)(pal+1);}}M2C_FIELD(country,u8 *,42)=pal;
ReadFileSection(data_ov002_021f2e2c,(0x6890000+((pal)<<5)),settings[25]<<5,32);pal=(u16)(pal+1);
M2C_FIELD(country,u8 *,43)=pal;
resource=M2C_FIELD(M2C_FIELD(settings,void **,8),void **,20);
if(resource){ReadFileSection(resource,(0x6890000+((pal)<<5)),0,32);pal=(u16)(pal+1);}
M2C_FIELD(country,u8 *,44)=pal;
if(settings[21]){LoadFacePaletteToAddress(settings[21],2,(0x6890000+((pal)<<5)));pal=(u16)(pal+16);SetFileDirectory(data_ov002_021f2e34);}
GX_EndLoadTexPltt();resource=M2C_FIELD(M2C_FIELD(settings,void **,4)+settings[24]*4,void **,0);M2C_FIELD(country,void **,0)=resource?LoadDecompressedFile(M2C_FIELD(resource,void **,4),1):0;resource=M2C_FIELD(M2C_FIELD(settings,void **,4)+settings[19]*4,void **,8);M2C_FIELD(country,void **,4)=resource?LoadDecompressedFile(M2C_FIELD(resource,void **,4),1):0;resource=settings[19]==0?M2C_FIELD(M2C_FIELD(settings,void **,4),void **,16):0;M2C_FIELD(country,void **,8)=resource?LoadDecompressedFile(M2C_FIELD(resource,void **,4),1):0;resource=M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,4)+M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,u8 *,19)*4,void **,20);M2C_FIELD(country,void **,12)=resource?LoadDecompressedFile(M2C_FIELD(resource,void **,4),1):0;resource=M2C_FIELD(M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,void **,4)+M2C_FIELD(gPlayerSettings+(side==0?1:0)*24,u8 *,19)*4,void **,28);if(!resource)resource=M2C_FIELD(M2C_FIELD(settings,void **,4),void **,36);M2C_FIELD(country,void **,16)=resource?LoadDecompressedFile(M2C_FIELD(resource,void **,4),1):0;resource=M2C_FIELD(M2C_FIELD(settings,void **,4),void **,36);M2C_FIELD(country,void **,20)=resource?LoadDecompressedFile(M2C_FIELD(resource,void **,4),1):0;for(i=0;i<5;i++)M2C_FIELD(country+(u32)i*2,u16 *,86)=BlendRgb555_16(0x1fff,M2C_FIELD(M2C_FIELD(settings,void **,8),u16 *,26),(u8)(16-M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28)),M2C_FIELD(M2C_FIELD(settings,void **,8)+i,u8 *,28));
country+=100;settings+=24;state+=44;side++;}while(side<2);
}

void func_ov002_021e6cdc(M2C_UNK arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK SetupCountryGraphics(M2C_UNK);
    M2C_UNK func_ov002_021e5d5c(M2C_UNK);
    extern M2C_UNK data_ov002_021f2e3c;
    SetFileDirectory(&data_ov002_021f2e3c);
    SetupCountryGraphics(arg0);
    func_ov002_021e5d5c(arg0);
}
