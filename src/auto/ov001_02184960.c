/* 28 functions from 0x02184960 to 0x021858A4 (ov001), found by ds-decomp. */
#include "common.h"

s32 func_ov001_02184c60(void) {
    extern s32 data_ov001_02193e04;
    return data_ov001_02193e04;
}

void func_ov001_02184c70(s32 a) {void func_ov001_02184d5c(s32);M2C_UNK func_02007f8c(void *,s32,s32);extern s32 data_ov001_02193e04;u8 *p=(u8 *)(data_ov001_02193e04+(a<<8));func_02007f8c(p,0,0xef);p[0xe7]=255;func_ov001_02184d5c(a);}

void func_ov001_02184cac(void) {void func_02007df8(s32,s32,s32);void func_02046ebc(void *);void *func_020467b8(void *);M2C_UNK func_02008048(void *,void *,s32);void func_ov001_02184d5c(s32);extern s32 data_ov001_02193e04;
u8 buf[20];s32 i;void *p;s32 offset;register u32 fill;register u8 *q;func_02007df8(0,data_ov001_02193e04,1024);
i=0;fill=255;do{q=(u8 *)(data_ov001_02193e04+((u32)i<<8));i++;M2C_FIELD(q,u8 *,0xe7)=fill;}while(i<3);
func_02046ebc(buf);p=func_020467b8(buf);
for(i=0,offset=0;i<2;i++,offset+=256)func_02008048(p,(void *)(data_ov001_02193e04+offset+0xf0),14);
for(i=0;i<4;i++)func_ov001_02184d5c(i);
}

void func_ov001_02184ec4(u8 *a,u8 *b) {M2C_UNK func_02007f8c(void *,s32,s32);M2C_UNK func_02008048(void *,void *,s32);s32 func_0206ad38(void *);u8 buf[4];s32 i,j,offset;
func_02007f8c(buf,0,4);
for(i=0,offset=0;i<4;i++,offset+=3){func_02008048(a+offset,buf,3);for(j=0;j<3;j++){if(buf[j])break;buf[j]=32;}b[i]=func_0206ad38(buf);}
}

s32 func_ov001_02184f4c(u32 arg0) {
    if (arg0 <= 0x39U) {
        return arg0 - 0x30;
    }
    if (arg0 <= 0x46U) {
        return arg0 - 0x37;
    }
    return arg0 - 0x57;
}

void func_ov001_02184f68(void){void func_ov001_021850ac(void);extern s32 data_ov001_02193e08;extern M2C_UNK data_ov001_02190b68;s32 func_ov001_0218b6f8(s32,s32);s32 func_ov001_02189dc8(void *,void *,s32);void func_0202a968(void);M2C_UNK func_0202bf54(s32,s32);M2C_UNK func_0202d294(s32);M2C_UNK func_0202acb0(s32);s32 func_ov001_0218c884(s32,void (*)(void),s32,s32);s32 local;
data_ov001_02193e08=func_ov001_0218b6f8(0x9c,4);
M2C_FIELD(data_ov001_02193e08,s32 *,0x94)=func_ov001_02189dc8(&data_ov001_02190b68,&local,32);
func_0202a968();func_0202bf54(data_ov001_02193e08,M2C_FIELD(data_ov001_02193e08,s32 *,0x94));func_0202d294(0);func_0202acb0(data_ov001_02193e08+0x90);M2C_FIELD(data_ov001_02193e08,s32 *,0x98)=func_ov001_0218c884(0,func_ov001_021850ac,0,200);}

void func_ov001_02184ff8(void){extern s32 data_ov001_02193e08;M2C_UNK func_ov001_0218c92c(s32,s32);M2C_UNK func_ov001_0218b71c(void *);func_ov001_0218c92c(0,M2C_FIELD(data_ov001_02193e08,s32 *,0x98));func_ov001_0218b71c((void *)0x02193e08);}

void func_ov001_02185024(s32 a){extern s32 data_ov001_02193e08;M2C_UNK func_0202d3e8(s32,s32,s32);func_0202d3e8(data_ov001_02193e08+0x90,0,a);}

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

void func_ov001_02185544(s32 a){
void func_ov001_0218a4d4();void func_ov001_0218a384();void func_ov001_0218c924();void func_ov001_021855e4(s32);extern M2C_UNK data_ov001_02193e0c;s32 pos[2];void *p;
func_ov001_0218a4d4(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),0,&pos[1],&pos[0]);pos[1]+=8;
if(pos[1]<176 || pos[1]>256){func_ov001_0218a384(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),-1,pos[1],33);return;}
p=M2C_FIELD(&data_ov001_02193e0c,void **,4);pos[1]=176;func_ov001_0218a384(M2C_FIELD(p,s32 *,16),-1,pos[1],33);func_ov001_0218c924(a,func_ov001_021855e4);
}

void func_ov001_021855e4(s32 a){
s32 func_ov001_0218c92c(s32,s32);extern M2C_UNK data_ov001_02193e0c;func_ov001_0218c92c(0,a);M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,20)=0;
}

void func_ov001_0218560c(void){
s32 func_ov001_0218c884();void func_ov001_02185734(s32);extern M2C_UNK data_ov001_02193e0c;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),u8 *,24)=1;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,20)=func_ov001_0218c884(0,func_ov001_02185734,0,120);
}

s32 func_ov001_02185714(void) {
    extern M2C_UNK data_ov001_02193e0c;
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c, void **, 4), s32 *, 0x14) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02185734(s32 a){
void func_ov001_0218a4d4();void func_ov001_0218a384();void func_ov001_0218c924();void func_ov001_021857c8();extern M2C_UNK data_ov001_02193e0c;s32 pos[2];void *p;
func_ov001_0218a4d4(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),0,&pos[1],&pos[0]);pos[1]-=8;
if(pos[1]>152){func_ov001_0218a384(M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c,void **,4),s32 *,16),-1,pos[1],33);return;}
p=M2C_FIELD(&data_ov001_02193e0c,void **,4);pos[1]=152;func_ov001_0218a384(M2C_FIELD(p,s32 *,16),-1,pos[1],33);func_ov001_0218c924(a,func_ov001_021857c8);
}

