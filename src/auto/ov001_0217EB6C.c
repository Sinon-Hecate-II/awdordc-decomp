/* 37 functions from 0x0217EB6C to 0x0217FB68 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[4]; } FourBytes;
typedef struct { u8 bytes[14]; } FourteenBytes;
typedef struct { u16 a,b,c,d; } FourShorts;

s32 func_ov001_0217ede0(s32 arg0) {
    s32 func_02002088(u16, s32);
    extern M2C_UNK data_ov001_02193dac;
    s32 value;
    s32 i;
    value = func_02002088(M2C_FIELD(&data_ov001_02193dac, u16 *, 4), 0x1D);
    for (i = 0; i < 4; i++, value++) {
        if (value == arg0) return i;
    }
    return -1;
}

s32 func_ov001_0217ee24(s32 arg0) {
    s32 func_02002088(u16, s32);
    extern M2C_UNK data_ov001_02193dac;
    s32 result;
    result = func_02002088(M2C_FIELD(&data_ov001_02193dac, u16 *, 4), 0x1D);
    result += arg0;
    return result;
}

void func_ov001_0217ee48(s32 arg0) {
s32 func_020020c4(u16,s32);
extern M2C_UNK data_ov001_02193dac;
s32 delta, remainder;
func_ov001_02183a08();
func_ov001_02172184();
if ((u32)M2C_FIELD(&data_ov001_02193dac,u16 *,4)>6U)
M2C_FIELD(&data_ov001_02193dac,u16 *,4)=M2C_FIELD(&data_ov001_02193dac,u16 *,4)-6;
else M2C_FIELD(&data_ov001_02193dac,u16 *,4)=0;
remainder=func_020020c4(M2C_FIELD(&data_ov001_02193dac,u16 *,4),29);
if(remainder==23){func_ov001_0217e238();return;}
if(remainder>23){
delta=29-remainder;
M2C_FIELD(&data_ov001_02193dac,u16 *,4)=M2C_FIELD(&data_ov001_02193dac,u16 *,4)+(29-remainder);
remainder=0;
}
func_ov001_0217e95c();
if(remainder!=0)return;
func_ov001_021839e4((M2C_FIELD(&data_ov001_02193dac,u16 *,4)*55)/145);
func_ov001_021839f0();
func_ov001_0217f110();
M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),s32 *,0x38)=0;
func_ov001_0218c92c(0,arg0);
}

void func_ov001_0217ef10(s32 arg0) {
    s32 func_020020c4(u16, s32);
    M2C_UNK func_ov001_02183a08();
    M2C_UNK func_ov001_02172184();
    M2C_UNK func_ov001_0217e95c();
    M2C_UNK func_ov001_0217e238();
    M2C_UNK func_ov001_021839e4(s32);
    M2C_UNK func_ov001_021839f0();
    M2C_UNK func_ov001_0217f110();
    M2C_UNK func_ov001_0218c92c(s32, s32);
    extern M2C_UNK data_ov001_02193dac;
    s32 result;
    func_ov001_02183a08();
    func_ov001_02172184();
    M2C_FIELD(&data_ov001_02193dac, u16 *, 4) = M2C_FIELD(&data_ov001_02193dac, u16 *, 4) + 6;
    result = func_020020c4(M2C_FIELD(&data_ov001_02193dac, u16 *, 4), 0x1D);
    if (result >= 6) {
        func_ov001_0217e95c();
        return;
    }
    M2C_FIELD(&data_ov001_02193dac, u16 *, 4) = M2C_FIELD(&data_ov001_02193dac, u16 *, 4) - result;
    func_ov001_0217e238();
    func_ov001_021839e4((M2C_FIELD(&data_ov001_02193dac, u16 *, 4) * 55) / 145);
    func_ov001_021839f0();
    func_ov001_0217f110();
    M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x38) = 0;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_0217efb4(void){s32 func_02002088(u16,s32);s32 func_020020c4(u16,s32);extern M2C_UNK data_ov001_02193dac;extern volatile u8 data_ov001_0218f9b0[];s32 i,x;u32 y; if(!M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),u8 *,0x44))return;i=func_02002088(M2C_FIELD(&data_ov001_02193dac,u16 *,4),29);x=func_020020c4(M2C_FIELD(&data_ov001_02193dac,u16 *,4),29)-51;y=data_ov001_0218f9b0[i];*(volatile u32 *)0x04000010=(x<<16)&0x1ff0000;*(volatile u32 *)0x04000018=((x+y)<<16)&0x1ff0000;M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),u8 *,0x44)=0;}

/* Selects a map-layout entry from the state index and applies it via func_ov001_02171fd8. */
void func_ov001_0217f038(void) {
    extern FourteenBytes data_ov001_0218f8e0;
    extern M2C_UNK data_ov001_02193dac;
    extern u16 data_ov001_0218f96a[], data_ov001_0218f96e[], data_ov001_0218f96c[];
    void func_ov001_02171fd8(s32, u16, u16, u16);
    FourteenBytes layout = data_ov001_0218f8e0;
    FourShorts entry;
    s32 i = layout.bytes[M2C_FIELD(&data_ov001_02193dac, u8 *, 0)];
    if (i >= 3) {
        func_ov001_02171fd8(3, data_ov001_0218f96a[i * 4], data_ov001_0218f96e[i * 4], data_ov001_0218f96c[i * 4]);
        return;
    }
    entry = ((FourShorts *)data_ov001_0218f96a)[i];
    entry.b += M2C_FIELD(&data_ov001_02193dac, u8 *, 2) * 29;
    func_ov001_02171fd8(1, entry.a, entry.c, entry.b);
}

M2C_UNK func_ov001_0217f110(void){void *func_ov001_0218445c(void);s32 func_02002088(u16,s32);void func_ov001_0217f038(void);extern M2C_UNK data_ov001_02193dac;extern u8 data_ov001_0218f9a4[];void *p;s32 i,j;if((u8)(M2C_FIELD(&data_ov001_02193dac,u8 *,0)+245)<=2){func_ov001_0217f038();return;}p=func_ov001_0218445c();i=func_02002088(M2C_FIELD(&data_ov001_02193dac,u16 *,4),29);j=M2C_FIELD(&data_ov001_02193dac,u8 *,2);j+=i;switch(j){case 2:if(M2C_FIELD(p,u8 *,0xf5))M2C_FIELD(&data_ov001_02193dac,u8 *,0)=2;else M2C_FIELD(&data_ov001_02193dac,u8 *,0)=3;break;case 6:if(M2C_FIELD(p,u8 *,0xf6))M2C_FIELD(&data_ov001_02193dac,u8 *,0)=7;else M2C_FIELD(&data_ov001_02193dac,u8 *,0)=8;break;default:M2C_FIELD(&data_ov001_02193dac,u8 *,0)=data_ov001_0218f9a4[j];break;}func_ov001_0217f038();}

void func_ov001_0217f1c0(u32 a){void func_ov001_0217f038(void);extern M2C_UNK data_ov001_02193dac;extern u8 data_ov001_0218f9bc[];M2C_FIELD(&data_ov001_02193dac,u8 *,0)=a;M2C_FIELD(&data_ov001_02193dac,u8 *,2)=func_ov001_0217ede0(data_ov001_0218f9bc[a]);func_ov001_0217f038();}

void func_ov001_0217f4e0(void){void func_ov001_021837e4(s32,u8,u8);extern M2C_UNK data_ov001_02193dac;extern u8 data_ov001_0218f8c0[];u8 v=data_ov001_0218f8c0[M2C_FIELD(&data_ov001_02193dac,u8 *,0)-11];func_ov001_021837e4(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),s32 *,16),v,v);}

void func_ov001_0217f514(void){extern M2C_UNK data_ov001_02193dac;M2C_UNK func_ov001_0217e238();s32 i=0;do{u8 *p=(u8 *)M2C_FIELD(&data_ov001_02193dac,void **,8)+i;if(p[4]){p[4]--;if(!M2C_FIELD((u8 *)M2C_FIELD(&data_ov001_02193dac,void **,8)+i,u8 *,4))func_ov001_0217e238();}i++;}while(i<4);}

void func_ov001_0217f568(void) {
extern M2C_UNK data_ov001_02193dac;
extern FourBytes data_ov001_0218f8c4;
FourBytes values=data_ov001_0218f8c4; s32 i;
for(i=0;i<4;i++) {
if(M2C_FIELD(&data_ov001_02193dac,u8 *,0)==values.bytes[i]){
M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8)+i,u8 *,4)=20;
if(i&1) { M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8)+(i-1),u8 *,4)=0; return; }
else M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8)+(i+1),u8 *,4)=0;
return;
}
}
}

s32 func_ov001_0217f62c(void){void *func_ov001_0218445c(void);s32 func_0204612c(void *);s32 func_020460b0(void *,void *);u8 *p=func_ov001_0218445c();if(!p[0x40])return 0;if(!p[0xf6]&&!func_0204612c(p+0xc8)&&!func_0204612c(p+0xcc))return 0;if(!p[0xf5]){if(!func_0204612c(p+0xc0))return 0;if(!func_0204612c(p+0xc4))return 0;if(!func_020460b0(p+0xc0,p+0xf0))return 0;}return 1;}

void func_ov001_0217f6cc(void){s32 func_ov001_02186648(void);M2C_UNK func_ov001_02185024(s32);M2C_UNK func_ov001_02186604();M2C_UNK func_ov001_0218384c(s32);extern M2C_UNK data_ov001_02193dac;extern M2C_UNK func_ov001_0217f70c;if(func_ov001_02186648())return;func_ov001_02185024(6);func_ov001_02186604();func_ov001_0218384c(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),s32 *,12));func_ov001_02175d54(&func_ov001_0217f70c);}

void func_ov001_0217f70c(void) {
    s32 func_ov001_0218665c();
    extern M2C_UNK func_ov001_0217d744;
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_0217d744);
}

void func_ov001_0217f72c(s8 arg0) {
    extern M2C_UNK data_ov001_02193dac;
    M2C_FIELD(&data_ov001_02193dac, s8 *, 1) = arg0;
}

void func_ov001_0217f73c(void) {
    M2C_UNK func_ov001_021722ac();
    void func_ov001_0217f75c();
    M2C_UNK func_ov001_02184960();
    extern M2C_UNK func_ov001_0217f7f0;
    func_ov001_0217f75c();
    func_ov001_021722ac();
    func_ov001_02184960();
    func_ov001_02175d54(&func_ov001_0217f7f0);
}

void func_ov001_0217f75c(void){M2C_UNK func_ov001_02171d90(M2C_UNK *,M2C_UNK *);extern M2C_UNK data_ov001_02190894,data_ov001_021908ac,data_ov001_021908c4;extern M2C_UNK func_020046cc,func_020040b4,func_0200448c;func_ov001_02171d90(&data_ov001_02190894,&func_020046cc);func_ov001_02171d90(&data_ov001_021908ac,&func_020040b4);func_ov001_02171d90(&data_ov001_021908c4,&func_0200448c);M2C_FIELD((void *)0x04001008,u16 *,0)=(M2C_FIELD((void *)0x04001008,u16 *,0)&~3)|3;M2C_FIELD((void *)0x04001008,u16 *,2)=(M2C_FIELD((void *)0x04001008,u16 *,2)&~3)|3;M2C_FIELD((void *)0x0400000a,u16 *,0)=(M2C_FIELD((void *)0x0400000a,u16 *,0)&~3)|3;M2C_FIELD((void *)0x0400000a,u16 *,2)=(M2C_FIELD((void *)0x0400000a,u16 *,2)&~3)|3;}

void func_ov001_0217f7f0(void) {
    extern M2C_UNK func_ov001_0217f844;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    func_ov001_02175d54(&func_ov001_0217f844);
}

void func_ov001_0217f844(void) {
    M2C_UNK func_ov001_021862d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217f894;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_021862d8(0x44, 5, 1, -1, 0);
    func_ov001_02175d54(&func_ov001_0217f894);
}

void func_ov001_0217f894(void){s32 func_ov001_0218665c(void);void func_ov001_0217f8bc(void);void func_ov001_0217f8c0(void);void func_ov001_0217f8c4(void);func_ov001_0217f8bc();func_ov001_0217f8c0();if(func_ov001_0218665c())return;func_ov001_02175d54(func_ov001_0217f8c4);}

void func_ov001_0217f8bc(void) {

}

void func_ov001_0217f8c0(void) {

}

void func_ov001_0217f8c4(void) {
    extern M2C_UNK func_ov001_0217f900;
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x14, 8);
    func_ov001_02175d54(&func_ov001_0217f900);
}

void func_ov001_0217f900(void) {
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02180d44;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x14);
    func_ov001_02175d64(2, 1);
    func_ov001_02175d54(&func_ov001_02180d44);
}

s32 func_ov001_0217f95c(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_0217f97c(void){void func_ov001_0217f9b8(void);void func_ov001_0217fa38(void);M2C_UNK func_ov001_021713c4(M2C_UNK);M2C_UNK func_ov001_02171e58(M2C_UNK);M2C_UNK func_ov001_021722ac(void);extern M2C_UNK data_ov001_02193db8;M2C_FIELD(&data_ov001_02193db8,u8 *,0)=0;func_ov001_0217f9b8();func_ov001_021722ac();func_ov001_02171e58(0x25);func_ov001_021713c4(1);func_ov001_02175d54((M2C_UNK *)&func_ov001_0217fa38);}

void func_ov001_0217f9b8(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_021908d8;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_021908d8, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_0217fa38(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217fa6c;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217fa6c);
}

void func_ov001_0217fa6c(void) {
    void func_ov001_0217fa98(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(1);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217fa98);
}

void func_ov001_0217fa98(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_0217fac0;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_0217fac0);
}

void func_ov001_0217fac0(void) {
    M2C_UNK func_02006030(s32);
    M2C_UNK func_ov001_0217fca4();
    void func_ov001_0217fae0(void);
    void func_ov001_0217fb18(void);
    void func_ov001_0217fb1c(void);
    func_02006030(10);
    func_ov001_0217fca4();
    func_ov001_0217fae0();
    func_ov001_0217fb18();
    func_ov001_0217fb1c();
}

void func_ov001_0217fae0(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_0217f95c() == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_0217fb18(void) {

}

void func_ov001_0217fb1c(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    extern M2C_UNK func_ov001_0217fb48;
    if (func_ov001_021716c4() != 0) {
        return;
    }
    func_ov001_0218508c();
    func_ov001_02185024(7);
    func_ov001_02175d54(&func_ov001_0217fb48);
}

void func_ov001_0217fb48(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217fb68;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217fb68);
}

