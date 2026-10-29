/* 28 functions from 0x0217AE38 to 0x0217BD88 (ov001), found by ds-decomp. */
#include "common.h"
void func_ov001_0217b578(void);
void func_ov001_0217bc14(void);
void func_ov001_0217bb20(void);

void func_ov001_0217b130(void);

void func_ov001_0217ae38(s32 arg0, s32 arg1) {
    extern M2C_UNK data_ov001_02193d98;
    s32 offset;
    void *first, *second;
    if (arg0 >= M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51)) return;
    offset = arg0 * 0x2A;
    first = M2C_FIELD((u8 *)M2C_FIELD(&data_ov001_02193d98, void **, 4) + arg1 * 4, void **, 0x10);
    M2C_FIELD(first, u16 *, 4) = (M2C_FIELD(first, u16 *, 4) & ~0x3FF) | M2C_FIELD((u8 *)M2C_FIELD(&data_ov001_02193d98, void **, 4) + 2 * M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), void **, 0) + offset, u8 *, 0x28), u16 *, 0x42);
    second = M2C_FIELD((u8 *)M2C_FIELD(&data_ov001_02193d98, void **, 4) + arg1 * 4, void **, 0x24);
    M2C_FIELD(second, u16 *, 4) = (M2C_FIELD(second, u16 *, 4) & ~0x3FF) | M2C_FIELD((u8 *)M2C_FIELD(&data_ov001_02193d98, void **, 4) + 2 * M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), void **, 0) + offset, u16 *, 0x26), u16 *, 0x48);
}

void func_ov001_0217aec4(void) {
    s32 func_020020c4(u16, s32);
    extern M2C_UNK data_ov001_02193d98;
    s32 *first, *second;
    s32 position, i;
    u8 count;
    position = 0x36 - func_020020c4(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1C);
    i = 0;
    count = M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51);
    if ((s32)count > 5) count = 5;
    if ((s32)count > 0) {
        do {
            first = ((s32 **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[i + 4];
            *first = (*first & 0xFE00FF00) | (u8)(position - 2) | 0xB30000;
            second = ((s32 **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[i + 9];
            i++;
            *second = (*second & 0xFE00FF00) | (u8)(position + 1) | 0xD20000;
            position += 0x1C;
        } while (i < (s32)count);
    }
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x56) = 1;
}

void func_ov001_0217af80(s32 arg0) {
    s32 func_020020c4(u16, s32);
    extern M2C_UNK data_ov001_02193d98;
    s32 delta, remainder;
    u32 position;
    func_ov001_02183a08();
    func_ov001_02172184();
    if ((u32)M2C_FIELD(&data_ov001_02193d98, u16 *, 2) > 4U) M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = M2C_FIELD(&data_ov001_02193d98, u16 *, 2) - 4;
    else M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = 0;
    remainder = func_020020c4(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1C);
    if (remainder == 0x18) {
        func_ov001_0217ac18();
        return;
    }
    if (remainder > 0x18) {
        delta = 0x1C - remainder;
        M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = M2C_FIELD(&data_ov001_02193d98, u16 *, 2) + (0x1C - remainder);
        remainder = 0;
    }
    func_ov001_0217aec4();
    if (remainder != 0) return;
    func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2) * M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40));
    func_ov001_021839e4();
    func_ov001_021839f0();
    func_ov001_0217b130();
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0x38) = 0;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_0217b03c(s32 arg0) {
    s32 func_020020c4(u16, s32);
    extern M2C_UNK data_ov001_02193d98;
    s32 result;
    func_ov001_02183a08();
    func_ov001_02172184();
    M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = M2C_FIELD(&data_ov001_02193d98, u16 *, 2) + 4;
    result = func_020020c4(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1C);
    if (result >= 4) {
        func_ov001_0217aec4();
        return;
    }
    M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = M2C_FIELD(&data_ov001_02193d98, u16 *, 2) - result;
    func_ov001_0217ac18();
    func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2) * M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40));
    func_ov001_021839e4();
    func_ov001_021839f0();
    func_ov001_0217b130();
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0x38) = 0;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_0217b0d4(void) {
    s32 func_020020c4(u16, M2C_UNK);
    extern M2C_UNK data_ov001_02193d98;
    s32 temp_r1;

    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x56) == 0) {
        return;
    }
    temp_r1 = 0x01FF0000 & ((func_020020c4(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1C) - 0x32) << 0x10);
    M2C_FIELD((void *)0x04000010, s32 *, 0) = temp_r1;
    M2C_FIELD((void *)0x04000010, s32 *, 8) = temp_r1;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x56) = 0U;
}

void func_ov001_0217b130(void) {
    void func_ov001_02171fd8(s32, u16, u16, u16);
    extern u16 data_ov001_0218f7ec[], data_ov001_0218f7ee[], data_ov001_0218f7f0[];
    extern M2C_UNK data_ov001_02193d98;
    u32 index = M2C_FIELD(&data_ov001_02193d98, u8 *, 0);
    func_ov001_02171fd8(index < 4 ? 2 : 3, data_ov001_0218f7ec[index * 4], data_ov001_0218f7f0[index * 4], data_ov001_0218f7ee[index * 4]);
}

void func_ov001_0217b17c(s32 a) {
void func_ov001_0217b33c(void);
extern M2C_UNK data_ov001_02193d98;
s32 func_ov001_0218c884(s32,void (*)(s32),s32,s32);
s32 ok=1;s32 n=M2C_FIELD(&data_ov001_02193d98,u8 *,0);
switch(n) {
case 0: if(a==1) {if(!M2C_FIELD(&data_ov001_02193d98,u16 *,2)) M2C_FIELD(&data_ov001_02193d98,u8 *,0)=4;else {
func_ov001_02185024(19);
M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),s32 *,56)=func_ov001_0218c884(0,func_ov001_0217af80,0,120);return;
}} else {if(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),u8 *,81)>1)M2C_FIELD(&data_ov001_02193d98,u8 *,0)=n+1;else ok=0;}break;
case 1:case 2: if(a==1)M2C_FIELD(&data_ov001_02193d98,u8 *,0)=n-1;else {if(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),u8 *,81)>(n+1))M2C_FIELD(&data_ov001_02193d98,u8 *,0)=n+1;else ok=0;}break;
case 3:if(a==1)M2C_FIELD(&data_ov001_02193d98,u8 *,0)=n-1;else {func_ov001_0217b33c();return;}break;
case 4:if(a==1)ok=0;else {M2C_FIELD(&data_ov001_02193d98,u16 *,2)=0;M2C_FIELD(&data_ov001_02193d98,u8 *,0)=0;func_ov001_0217ac18();func_ov001_021839e4(0);}break;
}
if(!ok){if(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),u8 *,89))return;func_ov001_02185024(9);M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),u8 *,89)=1;return;}
func_ov001_02185024(8);func_ov001_0217b130();
}

void func_ov001_0217b2c8(void) {
    M2C_UNK func_ov001_02185024(s32);
    s32 func_ov001_0218c884(s32, void (*)(s32), s32, s32);
    extern M2C_UNK data_ov001_02193d98;
    if (M2C_FIELD(&data_ov001_02193d98, u16 *, 2) == 0) {
        if (M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x59) != 0) return;
        func_ov001_02185024(9);
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x59) = 1;
        return;
    }
    func_ov001_02185024(0x13);
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0x38) = func_ov001_0218c884(0, func_ov001_0217af80, 0, 0x78);
}

void func_ov001_0217b33c(void) {
    M2C_UNK func_ov001_02185024(s32);
    s32 func_ov001_0218c884(s32, void (*)(s32), s32, s32);
    extern M2C_UNK data_ov001_02193d98;
    if (M2C_FIELD(&data_ov001_02193d98, u16 *, 2) == M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40) || M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51) <= 4) {
        if (M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x59) != 0) return;
        func_ov001_02185024(9);
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x59) = 1;
        return;
    }
    func_ov001_02185024(0x13);
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0x38) = func_ov001_0218c884(0, func_ov001_0217b03c, 0, 0x78);
}

void func_ov001_0217b3c0(void) {
    M2C_UNK func_ov001_021837e4(s32, u8, u8);
    struct Table { u8 values[1]; };
    extern struct Table data_ov001_0218f794;
    extern M2C_UNK data_ov001_02193d98;
    struct Table table = data_ov001_0218f794;
    u8 value = table.values[0];
    func_ov001_021837e4(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 8), value, value);
}

void func_ov001_0217b3f0(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_0217b41c;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_0217b41c);
}

void func_ov001_0217b41c(void) {
    M2C_UNK func_ov001_02171738();
    M2C_UNK func_ov001_021839f0();
    s32 func_ov001_0218665c();
    extern M2C_UNK func_ov001_0217a3a8;
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02171738();
    func_ov001_021839f0();
    func_ov001_02175d54(&func_ov001_0217a3a8);
}

void func_ov001_0217b444(void) {
extern void *data_ov001_0218f81c; extern void *data_ov001_02193da0;
void *func_ov001_0218b6f8(s32,s32);void func_ov001_02175db4(s32 *,s32);
s32 func_ov001_0218c3e0(void *,s32);void *func_ov001_0218ad0c(s32,s32);void *func_ov001_0218a5f0(s32,s32);
void func_ov001_0217b634(void);
u8 choices[2]={M2C_FIELD(&data_ov001_0218f81c,u8 *,0),M2C_FIELD(&data_ov001_0218f81c,u8 *,1)};s32 a,b;
data_ov001_02193da0=func_ov001_0218b6f8(44,4);
func_ov001_02175db4(&a,(s32)&b);
if(a==0) {func_ov001_021846f8(data_ov001_02193da0+8); M2C_FIELD(data_ov001_02193da0,u8 *,41)=func_ov001_0218c3e0(data_ov001_02193da0+8,32);}
func_ov001_0217b578();func_ov001_02172250(a+9);
if(b==1)func_ov001_02171c24(53,-1,0);else func_ov001_02171c24(choices[a],-1,0);
func_ov001_02171dd0(2);
M2C_FIELD(data_ov001_02193da0,void **,0)=func_ov001_0218ad0c(0,0);
M2C_FIELD(data_ov001_02193da0,void **,4)=func_ov001_0218a5f0(0,62);
M2C_FIELD(M2C_FIELD(data_ov001_02193da0,void **,4),u16 *,4)=(M2C_FIELD(M2C_FIELD(data_ov001_02193da0,void **,4),u16 *,4)&~0xc00)|0xc00;
func_ov001_0217bc14();func_ov001_0217bb20();func_ov001_02175d54((s32 *)func_ov001_0217b634);
}

void func_ov001_0217b578(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190700;
    extern M2C_UNK data_ov001_02190714;
    extern M2C_UNK data_ov001_0219072c;
    extern M2C_UNK data_ov001_02190744;
    extern M2C_UNK func_020040b4;
    extern M2C_UNK func_02004160;
    extern M2C_UNK func_0200448c;
    extern M2C_UNK func_020046cc;
    func_ov001_02171d90(&data_ov001_02190700, &func_02004160);
    func_ov001_02171d90(&data_ov001_02190714, &func_020046cc);
    func_ov001_02171d90(&data_ov001_0219072c, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190744, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_0217b634(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217b688;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217b688);
}

void func_ov001_0217b688(void) {
    s32 func_ov001_0218a800(s32);
    M2C_UNK func_ov001_021724c0(void);
    M2C_UNK func_ov001_02185024(s32);
    M2C_UNK func_ov001_0217286c(s32);
    M2C_UNK func_ov001_02172880(s32);
    void func_ov001_0217b704(void);
    M2C_UNK func_ov001_02175d54();
    extern void *data_ov001_02193da0;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_021724c0();
    func_ov001_02185024(0x14);
    if (M2C_FIELD(data_ov001_02193da0, u8 *, 0x29) == 0) {
        func_ov001_0217286c(0);
    }
    if (M2C_FIELD(data_ov001_02193da0, u8 *, 0x29) == 0x20) {
        func_ov001_02172880(0);
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217b704);
}

void func_ov001_0217b704(void) {
    s32 func_ov001_02172858();
    void func_ov001_0217b724(void);
    if (func_ov001_02172858() == 0xFF) {
        return;
    }
    func_ov001_02175d54(&func_ov001_0217b724);
}

void func_ov001_0217b724(void) {
    void func_ov001_0217b734(void);
    void func_ov001_0217b8f4(void);
    func_ov001_0217b734();
    func_ov001_0217b8f4();
}

void func_ov001_0217b734(void) {
extern void *data_ov001_02193da0;
void func_ov001_0217b8f8(void);
s32 key=func_ov001_02172858(); s32 *obj;
switch(key){
case 0x80:
if(M2C_FIELD(data_ov001_02193da0,u8 *,0x29)){
func_ov001_02185024(3);
M2C_FIELD(data_ov001_02193da0,u8 *,0x29)--;
M2C_FIELD((u8 *)data_ov001_02193da0+M2C_FIELD(data_ov001_02193da0,u8 *,0x29),u8 *,8)=0;
if(!M2C_FIELD(data_ov001_02193da0,u8 *,0x29))func_ov001_0217286c(0);
func_ov001_02172880(1);
}
break;
case 0:break;
case 0x82:
func_ov001_02185024(7);M2C_FIELD(data_ov001_02193da0,u8 *,0x2a)=0;func_ov001_02175d54(func_ov001_0217b8f8);return;
case 0x83:
if(func_ov001_0217bd88()){
func_ov001_02185024(6);M2C_FIELD(data_ov001_02193da0,u8 *,0x2a)=1;
}else{M2C_FIELD(data_ov001_02193da0,u8 *,0x2a)=2;func_ov001_02185024(9);}
obj=M2C_FIELD(data_ov001_02193da0,s32 **,4);*obj=(*obj&0xc1fffcff)|0x200;
func_ov001_02175d54(func_ov001_0217b8f8);return;
case 0xe01d:
default:
if(M2C_FIELD(data_ov001_02193da0,u8 *,0x29)!=32){
func_ov001_02185024(1);
M2C_FIELD((u8 *)data_ov001_02193da0+M2C_FIELD(data_ov001_02193da0,u8 *,0x29),u8 *,8)=key;
M2C_FIELD(data_ov001_02193da0,u8 *,0x29)++;
func_ov001_0217286c(1);
if(M2C_FIELD(data_ov001_02193da0,u8 *,0x29)==32)func_ov001_02172880(0);
}
break;
}
func_ov001_0217bb20();func_ov001_0217bc14();
}

void func_ov001_0217b8f4(void) {

}

void func_ov001_0217b8f8(void) {
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217b914;
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217b914);
}

void func_ov001_0217b914(void) {
    M2C_UNK func_ov001_02172824();
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217b944;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02172824();
    func_ov001_02185024(0x15);
    func_ov001_02175d54(&func_ov001_0217b944);
}

void func_ov001_0217b944(void) {
    s32 func_ov001_02172894();
    void func_ov001_02175db4(s32 *, s32);
    M2C_UNK func_ov001_021862d8(s32, s32, s32, s32, s32);
    extern void *data_ov001_0218f81c;
    extern void *data_ov001_02193da0;
    extern M2C_UNK func_ov001_0217ba1c;
    extern M2C_UNK func_ov001_0217bc7c;
    extern M2C_UNK func_ov001_0217bf14;
    s32 sp8[2];
    s32 sp4;
    u8 temp_r0;

    sp8[0] = M2C_FIELD(&data_ov001_0218f81c, s32 *, 8);
    sp8[1] = M2C_FIELD(&data_ov001_0218f81c, s32 *, 0xC);
    if (func_ov001_02172894() != 0) return;
    temp_r0 = M2C_FIELD(data_ov001_02193da0, u8 *, 0x2A);
    if (temp_r0 == 0) {
        func_ov001_02175d54(&func_ov001_0217ba1c);
        return;
    }
    if (temp_r0 == 2) {
        func_ov001_021862d8(6, 3, 1, -1, 0);
        func_ov001_02175d54(&func_ov001_0217bf14);
        return;
    }
    func_ov001_02175db4(0, &sp4);
    func_ov001_021862d8(sp8[sp4], 2, 1, -1, 0);
    func_ov001_02175d54(&func_ov001_0217bc7c);
}

#pragma optimization_level 4
#pragma peephole off
void func_ov001_0217ba1c(void) {
    M2C_UNK func_ov001_02171cf8(void);
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov001_0218c104(M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    void func_ov001_0218b368(s32, s32);
    void func_ov001_02175db4(s32 *, s32);
    void func_ov001_02175d64(s32, s32);
    void func_ov001_02175da0(s32, s32);
    s32 func_ov001_02175d54(s32 *);
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern void *data_ov001_02193da0;
    extern void *data_ov001_02190758;
    extern void func_02004160(void);
    extern void func_ov001_0217d270(void);
    extern void func_ov001_02179ea8(void);
    extern void func_ov001_021828ac(void);
    s32 sp4, sp0;
    func_ov001_02171cf8();
    func_ov001_0218c104(M2C_FIELD(data_ov001_02193da0, void **, 4));
    func_ov001_0218af70(0);
    func_ov001_02171d90((M2C_UNK *)&data_ov001_02190758, (M2C_UNK *)&func_02004160);
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175db4(&sp4, &sp0);
    if (sp0 == 0) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175da0(0, sp4);
        func_ov001_02175d54((s32 *)func_ov001_0217d270);
    } else {
        if (M2C_FIELD(data_ov001_02193da0, u8 *, 0x2A) == 0) {
            func_ov001_02175d64(0, 1);
            func_ov001_02175da0(1, 0);
            func_ov001_02175d54((s32 *)func_ov001_02179ea8);
        } else {
            func_ov001_02175d64(0, 0);
            func_ov001_02175da0(0, 1);
            func_ov001_02175d54((s32 *)func_ov001_021828ac);
        }
    }
    func_ov001_0218b71c((M2C_UNK *)&data_ov001_02193da0);
}
#pragma peephole reset
void func_ov001_0217bb20(void) {
    extern void *data_ov001_02193da0;
    extern u8 data_ov001_0218f838[];
    void func_ov001_0218b1ec(s32, s32);
    void func_ov001_0218b12c(s32, s32, s32, s32, s32, s32, s32, void *);
    void func_ov001_0218b298(s32);
    u16 buf[6];
    u16 *p;
    s32 j, i;
    u8 v;

    p = &buf[2];
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[0] = 0;
    buf[3] = 0x20;
    buf[4] = 0xE;
    buf[5] = 0x10;
    func_ov001_0218b1ec(M2C_FIELD(data_ov001_02193da0, s32 *, 0), 0);
    buf[1] = 0;
    j = 0;
    for (i = 0; i < 0x20; i++) {
        if (i == 0x10) {
            j = 0;
            buf[3] = 0x31;
        }
        v = M2C_FIELD((u8 *) data_ov001_02193da0 + i, u8 *, 8);
        if (v == 0x20) buf[0] = 0xE01D;
        else buf[0] = v;
        buf[2] = data_ov001_0218f838[j];
        func_ov001_0218b12c(M2C_FIELD(data_ov001_02193da0, s32 *, 0), buf[2], buf[3], buf[4], buf[5], 2, 0x480, buf);
        j += 1;
    }
    func_ov001_0218b298(M2C_FIELD(data_ov001_02193da0, s32 *, 0));
}

void func_ov001_0217bc14(void) {
    extern void *data_ov001_02193da0;
    extern u8 data_ov001_0218f834[];
    extern u8 data_ov001_0218f838[];
    void *obj;
    s32 *slot;
    u8 value;
    s32 index, high;
    obj = data_ov001_02193da0;
    value = M2C_FIELD(obj, u8 *, 0x29);
    slot = M2C_FIELD(obj, s32 **, 4);
    index = value & 0xF;
    high = value >> 4;
    if (value >= 0x20) {
        high = 1;
        index = 0xF;
    }
    *slot = (*slot & 0xFE00FF00) | data_ov001_0218f834[high] | ((u32)data_ov001_0218f838[index] << 0x17 >> 7);
}

void func_ov001_0217bc7c(void) {
    extern void *data_ov001_02193da0;
    extern M2C_UNK func_ov001_0217bcd8;
    M2C_FIELD(data_ov001_02193da0, u8 *, 0x2A) = func_ov001_02186648();
    switch (M2C_FIELD(data_ov001_02193da0, u8 *, 0x2A)) {
    case 0: func_ov001_02185024(7); break;
    case 1: func_ov001_02185024(0xE); break;
    default: return;
    }
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_0217bcd8);
}

void func_ov001_0217bcd8(void) {
    s32 func_ov001_0218665c(void);
    s32 func_ov001_02175d54(s32 *);
    void func_ov001_02175db4(s32 *, s32);
    void func_ov001_0217b688(void);
    void func_ov001_0217ba1c(void);
    extern void *data_ov001_0218f81c;
    extern void *data_ov001_02193da0;

    void *entries[2];
    s32 index;

    entries[0] = M2C_FIELD(&data_ov001_0218f81c, void **, 0x10);
    entries[1] = M2C_FIELD(&data_ov001_0218f81c, void **, 0x14);

    if (func_ov001_0218665c()) return;
    if (M2C_FIELD(data_ov001_02193da0, u8 *, 0x2a) == 0) {
        s32 *p = M2C_FIELD(data_ov001_02193da0, s32 **, 4);
        *p &= 0xc1fffcff;
        func_ov001_02175d54((s32 *)func_ov001_0217b688);
        return;
    }
    func_ov001_02175db4(&index, 0);
    ((void (*)(void *))entries[index])((u8 *)data_ov001_02193da0 + 8);
    func_ov001_02175d54((s32 *)func_ov001_0217ba1c);
}

