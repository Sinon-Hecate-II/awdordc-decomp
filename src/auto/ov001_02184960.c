/* 28 functions from 0x02184960 to 0x021858A4 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[240]; } UnkOv001SaveBlock;
typedef struct { u8 pad[0xe6]; u8 mode:2; u8 flags:6; u8 active; } SaveFlags84;

void func_ov001_02184960(void) {
M2C_UNK MI_CpuFill8(void *,s32,s32); M2C_UNK MI_CpuCopy8(void *,void *,s32);
s32 func_02046014(void *);void func_ov001_02184d5c(s32);extern s32 gSaveData;
u8 *src,*dst;
src=(u8 *)gSaveData+0x400;
dst=(u8 *)(gSaveData+(src[244]<<8));
*(UnkOv001SaveBlock *)dst=*(UnkOv001SaveBlock *)src;
if(src[245]){
MI_CpuFill8(dst+192,0,4);MI_CpuFill8(dst+196,0,4);dst[208]=0;
}else{
MI_CpuCopy8(src+192,dst+192,4);MI_CpuCopy8(src+196,dst+196,4);dst[208]=func_02046014(src+240);
}
if(src[246])MI_CpuFill8(dst+200,0,8);else MI_CpuCopy8(src+200,dst+200,8);
func_ov001_02184d5c(src[244]);
}

void func_ov001_02184a3c(void *arg0) {
    M2C_UNK MI_CpuFill8(void *, s32, s32);
    M2C_UNK MI_CpuCopy8(void *, void *, s32);
    void func_ov001_02184960(void);
    extern s32 gSaveData;
    volatile u8 *base = (volatile u8 *)gSaveData;
    s32 size;
    s32 i;
    u8 *dst;
    u8 *src;

    MI_CpuFill8((void *)(base + 0x400), 0, 0xef);
    MI_CpuCopy8(arg0, (void *)(base + 0x440), 0x20);
    switch (*(s32 *)((u8 *)arg0 + 0x20)) {
        case 1:
            size = 5;
            base[0x4e6] = (base[0x4e6] & ~3) | 1;
            break;
        case 2:
            size = 0xd;
            base[0x4e6] = (base[0x4e6] & ~3) | 2;
            break;
        case 3:
            size = 0x10;
            base[0x4e6] = (base[0x4e6] & ~3) | 3;
            break;
        default:
            size = 0;
            base[0x4e6] = base[0x4e6] & ~3;
            break;
    }
    {
        u8 b = base[0x4e6];
        b &= ~0xfc;
        base[0x4e6] = b;
    }
    src = (u8 *)arg0 + 0x28;
    dst = (u8 *)base + 0x480;
    i = 0;
    for (; i < 4; i++) {
        MI_CpuCopy8(src, dst, size);
        dst += 0x10;
        src += 0x20;
    }
    base[0x4e7] = 2;
    MI_CpuFill8((void *)(base + 0x4f0), 0, 4);
    base[0x4f5] = 1;
    base[0x4f6] = 1;
    func_ov001_02184960();
}

void func_ov001_02184b50(u8 *src){
extern s32 gSaveData;
M2C_UNK MI_CpuFill8(void*,s32,s32);M2C_UNK MI_CpuCopy8(void*,void*,s32);
u8 flags; u8 *p=(u8*)gSaveData+0x400;
MI_CpuFill8(p,0,0xef);
MI_CpuCopy8(src+0,p+209,5);
MI_CpuCopy8(src+6,p+214,5);
MI_CpuCopy8(src+12,p+219,5);
MI_CpuCopy8(src+18,p+224,5);
MI_CpuCopy8(src+24,p+96,32);
MI_CpuCopy8(src+57,p+128,13);
MI_CpuCopy8(src+71,p+144,13);
MI_CpuCopy8(src+85,p+160,13);
MI_CpuCopy8(src+99,p+176,13);
MI_CpuCopy8(src+113,p+64,32);
flags=p[0xe6];
p[0xe7]=1;
p[0xe6]=(flags&~3)|2;
p[0xe6]&=~0xfc;
MI_CpuFill8(p+0xf0,0,4);
p[0xf5]=1;p[0xf6]=1;
func_ov001_02184960();
}

s32 func_ov001_02184c60(void) {
    extern s32 gSaveData;
    return gSaveData;
}

void func_ov001_02184c70(s32 a) {void func_ov001_02184d5c(s32);M2C_UNK MI_CpuFill8(void *,s32,s32);extern s32 gSaveData;u8 *p=(u8 *)(gSaveData+(a<<8));MI_CpuFill8(p,0,0xef);p[0xe7]=255;func_ov001_02184d5c(a);}

void func_ov001_02184cac(void) {
void FillU16(s32,s32,s32);void func_02046ebc(void *);void *func_020467b8(void *);M2C_UNK MI_CpuCopy8(void *,void *,s32);void func_ov001_02184d5c(s32);extern s32 gSaveData;
u8 buf[20];register s32 i;void *p;register u8 *q;register u32 fill=255;s32 offset;
FillU16(0,gSaveData,1024);
i=0;do{q=(u8 *)(gSaveData+((u32)i<<8));q[0xe7]=fill;i++;}while(i<3);
func_02046ebc(buf);p=func_020467b8(buf);
i=0;offset=0;do{MI_CpuCopy8(p,(void *)(gSaveData+offset+0xf0),14);i++;offset+=256;}while(i<2);
for(i=0;i<4;i++)func_ov001_02184d5c(i);
}

#pragma push
#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_ov001_02184d5c(s32 a) {
 M2C_UNK MI_CpuFill8(void *, s32, s32);
 u16 func_02076838(void *, void *, s32);
 s32 func_02045ee0(s32, s32 *, s32);
 s32 func_ov001_0218b6f8(s32, s32);
 M2C_UNK func_ov001_0218b71c(void *);
 extern s32 gSaveData;
 s32 arr[4], ptr, one=1, value, flag=0, idx, off, v;
 value=((u8 *)gSaveData+(a<<8))[0xe7];
 MI_CpuFill8(arr,0,16);
 v=one & 1; arr[a]=v;
 if(a<=2){
 if(((u8 *)gSaveData)[0xef] & (one<<a)) flag=v;
 if(value==255 && flag){
 ((u8 *)gSaveData)[0xef]&=~(one<<a);
 ((u8 *)gSaveData)[0x1ef]&=~(one<<a);
 arr[1]=1; arr[0]=1;
 }else if(value!=255 && !flag){
 ((u8 *)gSaveData)[0xef]|=one<<a;
 ((u8 *)gSaveData)[0x1ef]|=one<<a;
 arr[1]=1; arr[0]=1;
 }}
 idx=0; off=0; do {
 if(arr[idx]){
 u16 res=func_02076838((u8 *)gSaveData+0x4f8,(u8 *)gSaveData+off,254);
 *(u16 *)((u8 *)gSaveData+(idx<<8)+254)=res;
 } idx++; off+=256; }while(idx<4);
 ptr=func_ov001_0218b6f8(256,32);
 func_02045ee0(gSaveData,arr,ptr);
 func_ov001_0218b71c(&ptr);
}
#pragma pop
void func_ov001_02184ec4(u8 *a,u8 *b) {
M2C_UNK MI_CpuFill8(void *,s32,s32); M2C_UNK MI_CpuCopy8(void *,void *,s32); s32 ParseInt(void *);
u8 buf[4]; s32 i,j,offset; u8 *p;
MI_CpuFill8(buf,0,4);
for(i=0,offset=0;i<4;i++,offset+=3) {
MI_CpuCopy8(a+offset,buf,3);
for(j=0,p=buf;j<3;j++) { if(*p) break; *p++=32; }
b[i]=ParseInt(buf);
}
}

s32 HexCharValue(u32 arg0) {
    if (arg0 <= 0x39U) {
        return arg0 - 0x30;
    }
    if (arg0 <= 0x46U) {
        return arg0 - 0x37;
    }
    return arg0 - 0x57;
}

void func_ov001_02184f68(void){void func_ov001_021850ac(void);extern s32 data_ov001_02193e08;extern M2C_UNK data_ov001_02190b68;s32 func_ov001_0218b6f8(s32,s32);s32 Ov001_LoadFile(void *,void *,s32);void func_0202a968(void);M2C_UNK func_0202bf54(s32,s32);M2C_UNK func_0202d294(s32);M2C_UNK func_0202acb0(s32);s32 func_ov001_0218c884(s32,void (*)(void),s32,s32);s32 local;
data_ov001_02193e08=func_ov001_0218b6f8(0x9c,4);
M2C_FIELD(data_ov001_02193e08,s32 *,0x94)=Ov001_LoadFile(&data_ov001_02190b68,&local,32);
func_0202a968();func_0202bf54(data_ov001_02193e08,M2C_FIELD(data_ov001_02193e08,s32 *,0x94));func_0202d294(0);func_0202acb0(data_ov001_02193e08+0x90);M2C_FIELD(data_ov001_02193e08,s32 *,0x98)=func_ov001_0218c884(0,func_ov001_021850ac,0,200);}

void func_ov001_02184ff8(void){extern s32 data_ov001_02193e08;M2C_UNK func_ov001_0218c92c(s32,s32);M2C_UNK func_ov001_0218b71c(void *);func_ov001_0218c92c(0,M2C_FIELD(data_ov001_02193e08,s32 *,0x98));func_ov001_0218b71c((void *)0x02193e08);}

void Ov001_PlaySound(s32 a){extern s32 data_ov001_02193e08;M2C_UNK func_0202d3e8(s32,s32,s32);func_0202d3e8(data_ov001_02193e08+0x90,0,a);}

void func_ov001_02185048(M2C_UNK arg0) {
    M2C_UNK func_0202acdc(s32, M2C_UNK);
    extern s32 data_ov001_02193e08;
    func_0202acdc(data_ov001_02193e08 + 0x90, arg0);
}

void func_ov001_02185068(s32 a,s32 b){extern s32 data_ov001_02193e08;M2C_UNK func_0202ad70(s32,s32,s32);func_0202ad70(data_ov001_02193e08+0x90,a,b);}

void func_ov001_0218508c(void) {M2C_UNK func_0202ac60(s32,s32);extern s32 data_ov001_02193e08;func_0202ac60(data_ov001_02193e08+0x90,0);}

void func_ov001_021850ac(void) {
    M2C_UNK func_0202a9f0();
    func_0202a9f0();
}

void func_ov001_021850b8(s32 a){
extern M2C_UNK data_ov001_02193e0c;extern u8 data_ov001_0218fbb4[];extern u8 data_ov001_0218fbc3[];extern const u16 data_ov001_0218fbd2[];
s32 func_ov001_0218b6f8(s32,s32);s32 func_ov001_0218a61c();void Ov001_SetSpritePalette();void Ov001_MoveSpriteLayout();void func_ov001_0218a304();void func_ov001_021851b4();s32 func_ov001_0218c884(s32,void (*)(void),s32,s32);void func_ov001_02185b60();
u8 *q;
s32 i;
u8 *p;
M2C_FIELD(&data_ov001_02193e0c,s32 *,4)=func_ov001_0218b6f8(28,4);
p=data_ov001_0218fbb4+a*5;q=data_ov001_0218fbc3+a*5;
for(i=0;i<5;i++){
((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i]=func_ov001_0218a61c(1,*p++,1);
Ov001_SetSpritePalette(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,0);
Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,-42,((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
func_ov001_0218a304(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,0,*q++);
}
((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[5]=func_ov001_0218c884(0,func_ov001_021851b4,0,120);
func_ov001_02185b60(a);Ov001_PlaySound(13);
}

void func_ov001_021851b4(s32 arg0) {
extern M2C_UNK data_ov001_02193e0c;extern const u16 data_ov001_0218fbd2[];
void func_ov001_0218a4d4();void Ov001_MoveSpriteLayout();void func_ov001_0218c924();void func_ov001_02185298(s32);
s32 pos[2];s32 i;
func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[0],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<32 || pos[1]>256) {
for(i=0;i<5;i++)Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
return;
}
pos[1]=32;
for(i=0;i<5;i++)Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
func_ov001_0218c924(arg0,(M2C_UNK)func_ov001_02185298);
}

void func_ov001_02185298(s32 arg0) {
extern M2C_UNK data_ov001_02193e0c; extern const u16 data_ov001_0218fbd2[];
void func_ov001_0218a4d4(); void Ov001_MoveSpriteLayout(); void func_ov001_0218c924(); void func_ov001_0218537c();
s32 pos[2]; s32 i;
func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[1],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<80 || pos[1]>256){for(i=1;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}return;}
pos[1]=80;
for(i=1;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}
func_ov001_0218c924(arg0,func_ov001_0218537c);
}

void func_ov001_0218537c(s32 arg0) {
extern M2C_UNK data_ov001_02193e0c; extern const u16 data_ov001_0218fbd2[];
void func_ov001_0218a4d4(); void Ov001_MoveSpriteLayout(); void func_ov001_0218c924(); void func_ov001_02185460();
s32 pos[2]; s32 i;
func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[2],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<104 || pos[1]>256){for(i=2;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}return;}
pos[1]=104;
for(i=2;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}
func_ov001_0218c924(arg0,func_ov001_02185460);
}

void func_ov001_02185460(s32 arg0) {
extern M2C_UNK data_ov001_02193e0c; extern const u16 data_ov001_0218fbd2[];
void func_ov001_0218a4d4(); void Ov001_MoveSpriteLayout(); void func_ov001_0218c924(); void func_ov001_02185544();
s32 pos[2]; s32 i;
func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[3],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<152 || pos[1]>256){for(i=3;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}return;}
pos[1]=152;
for(i=3;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}
func_ov001_0218c924(arg0,func_ov001_02185544);
}

#pragma scheduling off
void func_ov001_02185544(s32 a){
void func_ov001_0218a4d4();void Ov001_MoveSpriteLayout();void func_ov001_0218c924();void func_ov001_021855e4(s32);extern M2C_UNK data_ov001_02193e0c;s32 pos[2];void *p;s32 handle;
func_ov001_0218a4d4(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),0,&pos[1],&pos[0]);pos[1]+=8;
if(pos[1]<176 || pos[1]>256){Ov001_MoveSpriteLayout(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),-1,pos[1],33);return;}
p=M2C_FIELD(&data_ov001_02193e0c,void **,4);pos[1]=176;handle=M2C_FIELD(p,s32 *,16);Ov001_MoveSpriteLayout(handle,~0u,176,33);func_ov001_0218c924(a,func_ov001_021855e4);
}
#pragma scheduling reset
void func_ov001_021855e4(s32 a) {
    s32 func_ov001_0218c92c(s32, s32);
    extern M2C_UNK data_ov001_02193e0c;
    func_ov001_0218c92c(0, a);
    *(s32 *)((u8 *)*(void **)((u8 *)&data_ov001_02193e0c + 4) + 0x14) = 0;
}
#pragma opt_instruction_scheduling reset
void func_ov001_0218560c(void){ s32 func_ov001_0218c884(s32,void (*)(),s32,s32); void func_ov001_02185734(s32); extern M2C_UNK data_ov001_02193e0c; s32 result; M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s8 *,24)=1; result=func_ov001_0218c884(0,func_ov001_02185734,0,120); M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,20)=result; }

void func_ov001_0218564c(s32 arg0) {
extern u8 data_ov001_0218fbb4[],data_ov001_0218fbc3[];extern const u16 data_ov001_0218fbd2[];extern M2C_UNK data_ov001_02193e0c;
s32 Ov001_GetSpriteObjEntry();void Ov001_LoadSpriteObjLayout();void Ov001_SetSpritePalette();void Ov001_MoveSpriteLayout();void func_ov001_0218a304();void func_ov001_02185b60();
s32 i,t;u8 *p,*q;
p=data_ov001_0218fbb4+arg0*5;q=data_ov001_0218fbc3+arg0*5;
i=0;do{
t=Ov001_GetSpriteObjEntry(((s32*)M2C_FIELD(&data_ov001_02193e0c,void**,4))[i],0);
Ov001_LoadSpriteObjLayout(1,*p,t);p+=2;
Ov001_SetSpritePalette(((s32*)M2C_FIELD(&data_ov001_02193e0c,void**,4))[i],-1,0);
Ov001_MoveSpriteLayout(((s32*)M2C_FIELD(&data_ov001_02193e0c,void**,4))[i],-1,((const u16(*)[2])data_ov001_0218fbd2)[i][0],((const u16(*)[2])data_ov001_0218fbd2)[i][1]);
func_ov001_0218a304(((s32*)M2C_FIELD(&data_ov001_02193e0c,void**,4))[i],-1,0,*q);q+=2;
i+=2;}while(i<5);func_ov001_02185b60(arg0);
}

s32 func_ov001_02185714(void) {
    extern M2C_UNK data_ov001_02193e0c;
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c, void **, 4), s32 *, 0x14) != 0) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling off
void func_ov001_02185734(s32 a){
void func_ov001_0218a4d4();void Ov001_MoveSpriteLayout();void func_ov001_0218c924();void func_ov001_021857c8();extern M2C_UNK data_ov001_02193e0c;s32 pos[2];void *p; s32 n;
func_ov001_0218a4d4(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),0,&pos[1],&pos[0]);pos[1]-=8;
if(pos[1]>152){Ov001_MoveSpriteLayout(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),-1,pos[1],33);return;}
p=M2C_FIELD(&data_ov001_02193e0c,void **,4);pos[1]=152; n=~(pos[1]-152);Ov001_MoveSpriteLayout(M2C_FIELD(p,s32 *,16),n,pos[1],33);func_ov001_0218c924(a,func_ov001_021857c8);
}
#pragma pop
void func_ov001_021857c8(s32 arg0) {
extern M2C_UNK data_ov001_02193e0c; extern const u16 data_ov001_0218fbd2[];
void func_ov001_0218a4d4(); void Ov001_MoveSpriteLayout(); void func_ov001_0218c924(); void func_ov001_021858a4();
s32 pos[2]; s32 i;
func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[3],0,&pos[1],&pos[0]);
pos[1]-=8;
if(pos[1]>104){for(i=3;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}return;}
pos[1]=104;
for(i=3;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c,void **,4))[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);}
func_ov001_0218c924(arg0,func_ov001_021858a4);
}

