/* 28 functions from 0x020C3D34 to 0x020C4D28 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[6]; u16 half[6]; } SetupColors;
typedef struct { u32 names[15]; } SetupNames;
typedef struct { s32 v[4]; } SaveDate;
typedef struct { s32 v[3]; } SaveTime;
extern const SaveDate data_020f4e48;
static inline void SaveTime_Clear(SaveTime *p) { M2C_FIELD((u32)p,s32 *,0)=0; M2C_FIELD((u32)p,s32 *,4)=0; M2C_FIELD((u32)p,s32 *,8)=0; }
static inline s32 SaveTime_Get1(SaveTime *p) { return p->v[1]; }
static inline s32 SaveTime_Get2(SaveTime *p) { return p->v[2]; }

#pragma opt_strength_reduction off
void func_020c3d34(void) {
extern void **gCurrentMap;
extern void *data_02164094;
extern u16 **gCur3DSpriteEngine;
extern u16 **g3DSpriteEngineSub;
extern const SetupColors data_020f4df4;
extern const SetupNames data_020f4e08;
extern u8 data_0212a464[],data_0212a46c[],data_0212a478[],data_0212a484[],data_0212a490[],data_0212a49c[];
extern u8 data_0212a4a8[],data_0212a4b4[],data_0212a4c0[],data_0212a4cc[],data_0212a4d8[],data_0212a4f0[];
s32 GetLocalizedFileName(void *);
void *HeapAllocBlock(s32);
char buf[96]; SetupNames names; SetupColors colors;
void *map=*gCurrentMap;
void *unit=(u8*)map+0x67a4+M2C_FIELD(map,u16*,0x52a4)*140;
u32 kindWord=M2C_FIELD(unit,u32*,0x6c); u8 kind;
u8 b3=data_020f4df4.bytes[3],b4=data_020f4df4.bytes[4],b5=data_020f4df4.bytes[5];
u16 **old; u8 alpha; s32 color; s16 x0,y0,x1,y1;
names=data_020f4e08;
colors.bytes[0]=data_020f4df4.bytes[0];colors.bytes[1]=data_020f4df4.bytes[1];colors.bytes[2]=data_020f4df4.bytes[2];colors.bytes[3]=b3;colors.bytes[4]=b4;colors.bytes[5]=b5;kind=kindWord;
colors.half[0]=data_020f4df4.half[0];colors.half[1]=data_020f4df4.half[1];colors.half[2]=data_020f4df4.half[2];colors.half[3]=data_020f4df4.half[3];colors.half[4]=data_020f4df4.half[4];colors.half[5]=data_020f4df4.half[5];

data_02164094=HeapAllocBlock(40);
M2C_FIELD(data_02164094,s32*,0)=0;
M2C_FIELD(data_02164094,u32*,0x10)=0xc3200000;
M2C_FIELD(data_02164094,s16*,0x14)=0;
M2C_FIELD(data_02164094,s16*,0x16)=0;
M2C_FIELD(data_02164094,s16*,0x18)=255;
M2C_FIELD(data_02164094,s16*,0x1a)=0;
M2C_FIELD(data_02164094,s16*,8)=kind;
M2C_FIELD(data_02164094,s16*,0x24)=16;
M2C_FIELD(data_02164094,s16*,0x1e)=22;
M2C_FIELD(data_02164094,s16*,0x22)=138;
SetFileDirectory(data_0212a464);
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
func_020822b8(colors.half);
{u16 * volatile p0=*gCur3DSpriteEngine+0;*p0=(*p0&~0)|16;}
{u16 * volatile p1=*gCur3DSpriteEngine+0;*p1=(*p1&~0)|32;}
{u16 * volatile p2=*gCur3DSpriteEngine+0;*p2=(*p2&~0)|64;}
{u16 * volatile p3=*gCur3DSpriteEngine+0;*p3=(*p3&~0)|128;}
{u16 * volatile p4=*gCur3DSpriteEngine+0;*p4=(*p4&~0)|256;}
M2C_FIELD(*gCur3DSpriteEngine,u16*,6)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,6)&~3)|2;
M2C_FIELD(*gCur3DSpriteEngine,u16*,8)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,8)&~3)|3;
M2C_FIELD(*gCur3DSpriteEngine,u16*,10)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,10)&~3)|1;
M2C_FIELD(*gCur3DSpriteEngine,u16*,12)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,12)&~3)|0;
{u16 * volatile p5=*gCur3DSpriteEngine+0;*p5=(*p5&~0)|512;}
{u16 * volatile p6=*gCur3DSpriteEngine+0;*p6=(*p6&~1024)|0;}
{u16 * volatile p7=*gCur3DSpriteEngine+0;*p7=(*p7&~2048)|0;}
{u16 * volatile p8=*gCur3DSpriteEngine+7;*p8=(*p8&~1)|1;}
{u16 * volatile p9=*gCur3DSpriteEngine+7;*p9=(*p9&~0)|2;}
{u16 * volatile p10=*gCur3DSpriteEngine+7;*p10=(*p10&~0)|4;}
{u16 * volatile p11=*gCur3DSpriteEngine+7;*p11=(*p11&~0)|8;}
{u16 * volatile p12=*gCur3DSpriteEngine+7;*p12=(*p12&~0)|16;}
{u16 * volatile p13=*gCur3DSpriteEngine+8;*p13=(*p13&~1)|1;}
{u16 * volatile p14=*gCur3DSpriteEngine+8;*p14=(*p14&~0)|2;}
{u16 * volatile p15=*gCur3DSpriteEngine+8;*p15=(*p15&~0)|4;}
{u16 * volatile p16=*gCur3DSpriteEngine+8;*p16=(*p16&~0)|8;}
{u16 * volatile p17=*gCur3DSpriteEngine+8;*p17=(*p17&~0)|16;}
{u16 * volatile p18=*gCur3DSpriteEngine+7;*p18=(*p18&~0)|32;}
{u16 * volatile p19=*gCur3DSpriteEngine+8;*p19=(*p19&~0)|32;}
x0=M2C_FIELD(data_02164094,s16*,20);y0=M2C_FIELD(data_02164094,s16*,22);x1=M2C_FIELD(data_02164094,s16*,24);y1=M2C_FIELD(data_02164094,s16*,26);
M2C_FIELD(*gCur3DSpriteEngine,u8*,72)=x0;
M2C_FIELD(*gCur3DSpriteEngine,u8*,74)=y0;
M2C_FIELD(*gCur3DSpriteEngine,u8*,73)=x1;
M2C_FIELD(*gCur3DSpriteEngine,u8*,75)=y1;
{u16 * volatile p20=*gCur3DSpriteEngine+9;*p20=(*p20&~1)|1;}
{u16 * volatile p21=*gCur3DSpriteEngine+9;*p21=(*p21&~2)|0;}
{u16 * volatile p22=*gCur3DSpriteEngine+9;*p22=(*p22&~4)|0;}
{u16 * volatile p23=*gCur3DSpriteEngine+9;*p23=(*p23&~8)|0;}
{u16 * volatile p24=*gCur3DSpriteEngine+9;*p24=(*p24&~16)|0;}
{u16 * volatile p25=*gCur3DSpriteEngine+9;*p25=(*p25&~256)|0;}
{u16 * volatile p26=*gCur3DSpriteEngine+9;*p26=(*p26&~0)|512;}
{u16 * volatile p27=*gCur3DSpriteEngine+9;*p27=(*p27&~1024)|0;}
{u16 * volatile p28=*gCur3DSpriteEngine+9;*p28=(*p28&~2048)|0;}
{u16 * volatile p29=*gCur3DSpriteEngine+9;*p29=(*p29&~4096)|0;}
{u16 * volatile p30=*gCur3DSpriteEngine+9;*p30=(*p30&~192)|64;}
alpha=M2C_FIELD(data_02164094,s16*,36);
M2C_FIELD(*gCur3DSpriteEngine,u8*,81)=alpha;
M2C_FIELD(*gCur3DSpriteEngine,u8*,82)=alpha;
color=((u8*)&colors)[M2C_FIELD(unit,u8*,29)];
LoadFileToSpriteBuffer(data_0212a46c,0,128);
LoadDecompressedFileTo(data_0212a478,M2C_FIELD(gCur3DSpriteEngine,void**,12));
LoadDecompressedFileTo(data_0212a484,M2C_FIELD(gCur3DSpriteEngine,void**,16));
func_020814ac(data_0212a490,M2C_FIELD(gCur3DSpriteEngine,void**,32),0,color);
func_020814ac(data_0212a49c,M2C_FIELD(gCur3DSpriteEngine,void**,36),0,color);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=1;
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;
LoadDecompressedFileTo(data_0212a4a8,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,20)+32);
func_020814ac(data_0212a4b4,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,40)+448,0,(u16)color);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;
color=names.names[kind];
StringFormat(buf,data_0212a4c0,color);
LoadFileToSpriteBuffer(buf,704,32);
StringFormat(buf,data_0212a4cc,color);
OpenNarcArchive(GetLocalizedFileName(data_0212a4d8));
LoadNarcFileDecompressed(GetLocalizedFileName(buf),(u8*)M2C_FIELD(g3DSpriteEngineSub,void**,28)+2048);
CloseNarcArchive();
MI_CpuFill32(0,M2C_FIELD(gCur3DSpriteEngine,void**,24),64);
func_020985b0(M2C_FIELD(data_02164094,s16*,8),8,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,24)+64);
func_02098a34(M2C_FIELD(data_02164094,s16*,8),8,3,0,0);
func_020985b0(M2C_FIELD(data_02164094,s16*,8),11,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,24)+0x7840);
func_02098a34(M2C_FIELD(data_02164094,s16*,8),11,3,1,0);
SetFileDirectory(data_0212a4f0);
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction reset
void func_020c4604(M2C_UNK arg0){extern u16 *gKeyState;extern void *data_02164094;
M2C_FIELD(data_02164094,s32*,0)++;
if((M2C_FIELD(data_02164094,s32*,0)<250)&&!(*gKeyState&1))return;
M2C_FIELD(data_02164094,s32*,4)=0;func_01ffa6fc(arg0);}

void func_020c4658(M2C_UNK arg0){extern void *data_02164094;
M2C_FIELD(data_02164094,s32*,0)++;M2C_FIELD(data_02164094,s32*,4)++;
if(M2C_FIELD(data_02164094,s32*,0)>=250)M2C_FIELD(data_02164094,s32*,0)=250;
if(M2C_FIELD(data_02164094,s32*,4)<64)return;func_01ffa6fc(arg0);}

void func_020c46b4(void) {
 M2C_UNK HeapFreeBlock(void *);
 extern void *data_02164094;
 extern u16 **gCur3DSpriteEngine;
 extern u16 **g3DSpriteEngineSub;
 u16 **old;
 u16 * volatile sp8;
 u16 * volatile sp4;
 u16 * volatile sp0;
 if (data_02164094 != 0) {
  HeapFreeBlock(data_02164094);
  data_02164094 = 0;
 }
 old = gCur3DSpriteEngine;
 gCur3DSpriteEngine = g3DSpriteEngineSub;
 sp8 = *gCur3DSpriteEngine;
 *sp8 = (*sp8 & ~0x200);
 sp4 = *gCur3DSpriteEngine;
 *sp4 = (*sp4 & ~0x400);
 sp0 = *gCur3DSpriteEngine;
 *sp0 = (*sp0 & ~0x800);
 gCur3DSpriteEngine = old;
}

void func_020c4764(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212a3cc;
    CreateSpriteObject(&data_0212a3cc, arg0);
}

s32 func_020c477c(s32 arg0) {
 M2C_UNK *func_020c4acc(void);
 s32 GetPlayerRecordId(void *,s32);
 return GetPlayerRecordId((u8 *)func_020c4acc()+4,arg0);
}

s32 func_020c4798(void) {
 M2C_UNK *func_020c4b60(void);
 s32 func_02032380(s32);
 s32 temp_r0;
 s32 var_r4;
 s32 var_r5;
 s32 var_r6;
 var_r4=-1;
 temp_r0=(s32)func_020c4b60();
 if(temp_r0==0)return var_r4;
 var_r6=temp_r0+4;
 var_r5=0;
 do {
 if(func_02032380(var_r6)==0){var_r4=var_r5;break;}
 var_r5+=1;var_r6+=12;
 }while(var_r5<60);
 return var_r4;
}

void func_020c47e4(s32 *arg0) {
 s32 GetActiveOverlay(void);
 s32 GetServerTime(s32 *,s32 *);
 s32 a[4];s32 b[3];
 if(GetActiveOverlay()!=2)return;
 if(!GetServerTime(a,b))return;
 arg0[0]=a[0];arg0[1]=a[1];arg0[2]=a[2];arg0[3]=a[3];
 arg0[4]=b[0];arg0[5]=b[1];arg0[6]=b[2];
}

long long GetElapsedSeconds(s32 arg0,s32 arg1,s32 arg2) {
 long long MakeTime(s32,s32);
 long long t=MakeTime(arg0,arg0+16);
 return MakeTime(arg1,arg2)-t;
}

void func_020c488c(void *arg0) {
    M2C_UNK func_020c4d64(s32, void *);
    func_020c4c70(M2C_FIELD(arg0, s32 *, 0x34), arg0);
    func_020c4d64(M2C_FIELD(arg0, s32 *, 0x38), arg0);
}

void func_020c48b0(void *arg0) {
 if(func_020c4b6c(M2C_FIELD(arg0,s32*,0x34))==0) {
 func_020c4954(M2C_FIELD(arg0,s32*,0x34));
 func_020c4ad8(M2C_FIELD(arg0,s32 **,0x38));
 return;
 }
 SetSpriteAnimation(arg0,1);
}

void func_020c48ec(void *arg0) {
    M2C_UNK func_020c5030(s32, void *);
    M2C_UNK func_020c526c(s32, void *);
    func_020c5030(M2C_FIELD(arg0, s32 *, 0x34), arg0);
    func_020c526c(M2C_FIELD(arg0, s32 *, 0x38), arg0);
}

void func_020c4910(void) {
 void *func_01ffa3dc(M2C_UNK *,s32);
 extern M2C_UNK data_0212a5cc;
 extern M2C_UNK data_0212a514;
 extern M2C_UNK data_02164098;
 extern M2C_UNK data_02164128;
 void *p=func_01ffa3dc(&data_0212a5cc,7);
 if(p==0)return;
 M2C_FIELD(p,M2C_UNK **,0)=&data_0212a514;
 M2C_FIELD(p,M2C_UNK **,0x34)=&data_02164098;
 M2C_FIELD(p,M2C_UNK **,0x38)=&data_02164128;
}

s32 func_020c4954(s32 arg0) {
void func_020323a4(void *,u32);
void func_0203287c(void *);
SaveDate initial;
SaveTime b;
SaveDate a;
SaveTime d;
SaveDate c;
M2C_FIELD(arg0,s32 *,0)=0x07090600;
MI_CpuFill8(arg0+4,0,0x40);
M2C_FIELD(arg0,s32 *,0x44)=0;
M2C_FIELD(arg0,s32 *,0x48)=0;
M2C_FIELD(arg0,s32 *,0x4c)=0;
M2C_FIELD(arg0,s32 *,0x50)=0x5dc000;
M2C_FIELD(arg0,s32 *,0x54)=0x5dc000;
initial=data_020f4e48;
a=initial;
M2C_FIELD(arg0,s32 *,0x58)=a.v[0];
M2C_FIELD(arg0,s32 *,0x5c)=a.v[1];
M2C_FIELD(arg0,s32 *,0x60)=a.v[2];
M2C_FIELD(arg0,s32 *,0x64)=a.v[3];
SaveTime_Clear(&b);
M2C_FIELD(arg0,s32 *,0x68)=0;
M2C_FIELD(arg0,s32 *,0x6c)=b.v[1];
M2C_FIELD(arg0,s32 *,0x70)=b.v[2];
c=initial;
M2C_FIELD(arg0,s32 *,0x74)=c.v[0];
M2C_FIELD(arg0,s32 *,0x78)=c.v[1];
M2C_FIELD(arg0,s32 *,0x7c)=c.v[2];
M2C_FIELD(arg0,s32 *,0x80)=c.v[3];
SaveTime_Clear(&d);
M2C_FIELD(arg0,s32 *,0x84)=0;
M2C_FIELD(arg0,s32 *,0x88)=d.v[1];
M2C_FIELD(arg0,s32 *,0x8c)=d.v[2];
func_020323a4((void *)(arg0+4),0x5957324a);
func_0203287c((void *)(arg0+4));
return 1;
}

s32 func_020c4a74(void *arg0) {
 M2C_UNK *func_020c4acc(void);
 void func_020323a4(void *,u32);
 s32 func_020c52ec(s32);
 void func_02031ee4(void);
 void func_0203287c(void *);
 s32 i;
 if(arg0==0)arg0=func_020c4acc();
 func_020323a4((u8*)arg0+4,0x5957324a);
 i=0;
 do {
 if(func_020c52ec(i)!=0)func_02031ee4();
 i++;
 }while(i<60);
 func_0203287c((u8*)arg0+4);
 return 1;
}

M2C_UNK *func_020c4acc(void) {
    extern M2C_UNK data_02164098;
    return &data_02164098;
}

s32 func_020c4ad8(s32 *arg0) {
    M2C_UNK FillU16(M2C_UNK, void *, M2C_UNK);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    register s32 var_r8;
    register void *var_r9;
    register s32 *var_r10;

    var_r10 = arg0;
    *var_r10 = 0x07090600;
    MI_CpuFill8((s32)((u8*)var_r10 + 4), 0, 0x2D0);
    var_r8 = 0;
    var_r9 = (u8*)var_r10 + 0x2D4;
    do {
        FillU16(0, var_r9, 0x1A);
        M2C_FIELD(var_r10, s16 *, 0x2EE) = 0;
        M2C_FIELD(var_r10, s16 *, 0x2F0) = 0;
        M2C_FIELD(var_r10, s16 *, 0x2F2) = 0;
        M2C_FIELD(var_r10, s8 *, 0x2F4) = -1;
        M2C_FIELD(var_r10, s8 *, 0x2F5) = -2;
        var_r8 += 1;
        M2C_FIELD(var_r10, s8 *, 0x2F6) = -2;
        var_r9 = (u8*)var_r9 + 0x28;
        var_r10 = (s32*)((u8*)var_r10 + 0x28);
    } while (var_r8 < 0x3C);
    return 1;
}

M2C_UNK *func_020c4b60(void) {
    extern M2C_UNK data_02164128;
    return &data_02164128;
}

s32 func_020c4b6c(s32 arg0) {
    M2C_UNK func_020323b0(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_020323b0(var_r0 + 4);
}

void func_020c4b88(s32 arg0) {
    M2C_UNK func_02032424(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_02032424(var_r0 + 4);
}

void func_020c4ba4(s32 arg0) {
    M2C_UNK func_020323f4(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_020323f4(var_r0 + 4);
}

void func_020c4bc0(s32 arg0) {
    M2C_UNK func_020324e4(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_020324e4(var_r0 + 4);
}

void func_020c4bdc(s32 arg0) {
    M2C_UNK func_02032508(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_02032508(var_r0 + 4);
}

void func_020c4bf8(void *arg0) {
    extern M2C_UNK data_0212a6a4;
    func_020c4bdc(M2C_FIELD(arg0, s32 *, 0x34));
    PruneSaveRecords(2, 1);
    func_02075fd8(M2C_FIELD(arg0, s32 *, 0x34), &data_0212a6a4, 0x90, 2);
    func_02076198();
}

void func_020c4c34(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_020761f8();
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK GetLocalizedText(s32);
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        GetLocalizedText(0xC000034C);
        func_02076244();
    }
    func_01ffa6fc(arg0);
}

M2C_UNK func_020c4c70(s32 arg0,s32 arg1) {
void *func_01ffa3dc(M2C_UNK *,M2C_UNK);
M2C_UNK CreateSpriteObject(M2C_UNK *,s32);
extern M2C_UNK data_0212a614,data_0212a550;
s32 var_r5; void *temp_r0; void *temp_r0_2;
var_r5=arg0;
if(var_r5==0)var_r5=(s32)func_020c4acc();
if(arg1!=0){temp_r0=(void *)CreateSpriteObject(&data_0212a614,arg1);if(temp_r0==NULL)return;
M2C_FIELD(temp_r0,M2C_UNK **,0)=&data_0212a550;M2C_FIELD(temp_r0,s32*,0x34)=var_r5;return;}
temp_r0_2=func_01ffa3dc(&data_0212a614,3);if(temp_r0_2!=NULL){M2C_FIELD(temp_r0_2,M2C_UNK **,0)=&data_0212a550;M2C_FIELD(temp_r0_2,s32*,0x34)=var_r5;}
}

void func_020c4cdc(M2C_UNK arg0) {
    M2C_UNK func_020c4c70(M2C_UNK, M2C_UNK);
    func_020c4c70(0, arg0);
}

void func_020c4cf0(void *arg0) {
    M2C_UNK func_02075fd8(s32, M2C_UNK *, s32, M2C_UNK);
    M2C_UNK PruneSaveRecords(M2C_UNK, M2C_UNK);
    M2C_UNK func_02076198();
    extern M2C_UNK data_0212a6b4;
    PruneSaveRecords(3, 1);
    func_02075fd8(M2C_FIELD(arg0, s32 *, 0x34), &data_0212a6b4, 0xC34, 3);
    func_02076198();
}

