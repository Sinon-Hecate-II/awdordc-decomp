/* 26 functions from 0x0217BD88 to 0x0217CCE8 (ov001), found by ds-decomp. */
#include "common.h"

typedef struct { void (*handlers[5])(void *); } CodeHandlers;
extern const CodeHandlers data_ov001_0218f874;
extern const CodeHandlers data_ov001_0218f860;
extern const u16 data_ov001_0218f848[];
extern void *data_ov001_02193da4;
extern u32 data_ov001_02190770;

s32 func_ov001_0217bd88(void) {
    s32 a, b;
    register u8 *p asm("r3") = 0;
    s32 len;
    s32 i;
    extern void *data_ov001_02193da0;

    func_ov001_02175db4(&a, &b);
    if (b == 1) {
        func_ov001_02171c24(0x35, -1, 0);
        func_ov001_02175db4(&a, &b);
        if (a == 0) {
            p = (u8 *)*(void **)data_ov001_02193da0;
            return p[8] != 0;
        }
    }
    if (b != 1) {
        return 0;
    }
    p = (u8 *)*(void **)data_ov001_02193da0;
    if (p[8] == 0) {
        return 0;
    }
    p = p + 8;
    len = func_ov001_0218c3e0(p, 0x20);
    switch (len) {
        case 10: case 26: case 32: return 1;
        case 0: case 5: case 13: case 16: return 0;
    }
    if (len <= 0) return 0;
    for (i = 0; i < len; i++) {
        u8 c = p[i];
        if (!((c >= '0' && c <= '9') ||
              (c >= 'A' && c <= 'F') ||
              (c >= 'a' && c <= 'f'))) {
            return 0;
        }
    }
    return 1;
}

void func_ov001_0217bf14(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_0217bf40;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_0217bf40);
}

void func_ov001_0217bf40(void) {
    s32 func_ov001_0218665c();
    extern void *data_ov001_02193da0;
    extern M2C_UNK func_ov001_0217b688;
    s32 *temp_r3;

    if (func_ov001_0218665c() != 0) {
        return;
    }
    temp_r3 = M2C_FIELD(data_ov001_02193da0, s32 **, 4);
    *temp_r3 &= 0xC1FFFCFF;
    func_ov001_02175d54(&func_ov001_0217b688);
}

#pragma opt_common_subs off
#pragma scheduling off
void func_ov001_0217bf84(void) {
void *func_ov001_0218b6f8(s32,s32);s32 func_ov001_02175db4(s32*,s32);
void *func_ov001_0218ad0c(s32,s32);void *func_ov001_0218a5f0(s32,s32);
void func_ov001_0217c0f8(void);void func_ov001_0217c8ac(void);void func_ov001_0217c1b4(void);
CodeHandlers handlers=data_ov001_0218f860;
u8 choices[5]={((u8*)data_ov001_0218f848)[8],((u8*)data_ov001_0218f848)[9],((u8*)data_ov001_0218f848)[10],((u8*)data_ov001_0218f848)[11],((u8*)data_ov001_0218f848)[12]};
s32 a;void *p;
data_ov001_02193da4=func_ov001_0218b6f8(24,4);
func_ov001_02175db4(&a,0);
handlers.handlers[a](data_ov001_02193da4+8);
p=data_ov001_02193da4;
if(func_0206527c(p+8,&data_ov001_02190770,3)) M2C_FIELD(p,u8*,20)=3;
else {func_02007f8c(p+8,0,12);M2C_FIELD(data_ov001_02193da4,u8*,20)=0;}
func_ov001_0217c0f8();func_ov001_02172250(a+11);func_ov001_02171c24(choices[a],-1,0);func_ov001_02171dd0(2);
M2C_FIELD(data_ov001_02193da4,void**,0)=func_ov001_0218ad0c(0,0);
M2C_FIELD(data_ov001_02193da4,void**,4)=func_ov001_0218a5f0(0,63);
M2C_FIELD(M2C_FIELD(data_ov001_02193da4,void**,4),u16*,4)=(M2C_FIELD(M2C_FIELD(data_ov001_02193da4,void**,4),u16*,4)&~0xc00)|0xc00;
func_ov001_0217c8ac();func_ov001_0217c7e8();func_ov001_02175d54((s32*)func_ov001_0217c1b4);
}
#pragma scheduling reset
#pragma opt_common_subs reset
void func_ov001_0217c0f8(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190774;
    extern M2C_UNK data_ov001_02190788;
    extern M2C_UNK data_ov001_021907a0;
    extern M2C_UNK data_ov001_021907b8;
    extern M2C_UNK func_020040b4;
    extern M2C_UNK func_02004160;
    extern M2C_UNK func_0200448c;
    extern M2C_UNK func_020046cc;
    func_ov001_02171d90(&data_ov001_02190774, &func_02004160);
    func_ov001_02171d90(&data_ov001_02190788, &func_020046cc);
    func_ov001_02171d90(&data_ov001_021907a0, &func_020040b4);
    func_ov001_02171d90(&data_ov001_021907b8, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_0217c1b4(void) {
    extern M2C_UNK func_ov001_0217c208;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217c208);
}

void func_ov001_0217c208(void) {
    s32 func_ov001_0217c5d4(s32);
    extern M2C_UNK func_ov001_0217c294;
    extern void *data_ov001_02193da4;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_0217416c();
    func_ov001_02185024(0x14);
    if (M2C_FIELD(data_ov001_02193da4, u8 *, 0x14) == 0) {
        func_ov001_021744f0(0);
        func_ov001_02174518(0);
    } else {
        if (func_ov001_0217c5d4(0x1A) != 0) func_ov001_02174504(0);
        func_ov001_02174518(0);
    }
    func_ov001_02175d54(&func_ov001_0217c294);
}

void func_ov001_0217c294(void) {
    s32 func_ov001_021744dc();
    extern M2C_UNK func_ov001_0217c2b4;
    if (func_ov001_021744dc() == 0x1F) {
        return;
    }
    func_ov001_02175d54(&func_ov001_0217c2b4);
}

void func_ov001_0217c2b4(void) {
    M2C_UNK func_ov001_0217c2c4();
    void func_ov001_0217c668(void);
    func_ov001_0217c2c4();
    func_ov001_0217c668();
}

s32 func_ov001_0217c2c4(void) {
    return 0;
}

s32 func_ov001_0217c5d4(s32 arg0) {
    M2C_UNK func_02008048(void *, u8 *, s32);
    s32 func_0206ad38(u8 *);
    extern void *data_ov001_02193da4;
    u8 buf[4];
    s32 offset;
    s32 i;
    u8 *p;
    u8 c;
    u8 *base;
    base = (u8 *)data_ov001_02193da4 + 8;
    offset = M2C_FIELD(data_ov001_02193da4, u8 *, 0x14) * 3;
    c = base[offset];
    if (c != 0 && c != 0x20) return 1;
    func_02008048(base + offset, buf, 3);
    i = 0;
    p = buf;
    buf[3] = 0;
    do {
        if (*p != 0) break;
        i++;
        *p++ = 0x20;
    } while (i < 3);
    return func_0206ad38(buf) >= arg0;
}

void func_ov001_0217c668(void) {

}

void func_ov001_0217c66c(void) {
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217c688;
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217c688);
}

void func_ov001_0217c688(void) {
    M2C_UNK func_ov001_021744a8();
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217c6b8;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_021744a8();
    func_ov001_02185024(0x15);
    func_ov001_02175d54(&func_ov001_0217c6b8);
}

void func_ov001_0217c6b8(void) {
    s32 func_ov001_0217452c();
    M2C_UNK func_ov001_021862d8(s32, s32, s32, s32, s32);
    extern void *data_ov001_02193da4;
    extern M2C_UNK func_ov001_0217c744;
    extern M2C_UNK func_ov001_0217c900;
    extern M2C_UNK func_ov001_0217cbdc;
    u8 state;
    if (func_ov001_0217452c() != 0) return;
    state = M2C_FIELD(data_ov001_02193da4, u8 *, 0x15);
    if (state == 0) {
        func_ov001_02175d54(&func_ov001_0217c744);
        return;
    }
    if (state == 2) {
        func_ov001_021862d8(6, 3, 1, -1, 0);
        func_ov001_02175d54(&func_ov001_0217cbdc);
        return;
    }
    func_ov001_021862d8(0x47, 2, 1, -1, 0);
    func_ov001_02175d54(&func_ov001_0217c900);
}

void func_ov001_0217c744(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern void *data_ov001_02193da4;
    extern M2C_UNK data_ov001_021907d0, func_02004160, func_ov001_0217d270;
    s32 sp0;
    func_ov001_02171cf8();
    func_ov001_0218c104(M2C_FIELD(data_ov001_02193da4, s32 *, 4));
    func_ov001_0218af70(0);
    func_ov001_02171d90(&data_ov001_021907d0, &func_02004160);
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175db4(&sp0, 0);
    if (sp0 >= 3) sp0++;
    func_ov001_02175d64(2, 1);
    func_ov001_02175da0(0, sp0 + 3);
    func_ov001_02175d54(&func_ov001_0217d270);
    func_ov001_0218b71c(&data_ov001_02193da4);
}

#pragma opt_store off
M2C_UNK func_ov001_0217c7e8(void){
 extern void *data_ov001_02193da4; extern const u16 data_ov001_0218f848[]; extern M2C_UNK data_ov001_0218f888;
 void func_ov001_0218b1ec(s32,s32);void func_ov001_0218b12c(s32,s32,s32,s32,s32,s32,s32,void *);void func_ov001_0218b298(s32);
 u16 buf[6];s32 i,a,handle;const u8 *p;
 handle=M2C_FIELD(data_ov001_02193da4,s32 *,0);
 buf[2]=data_ov001_0218f848[7];buf[3]=data_ov001_0218f848[8];buf[4]=11;buf[5]=16;
 func_ov001_0218b1ec(handle,0);
 buf[1]=0;
 p=(const u8 *)&data_ov001_0218f888;
 for(i=0;i<12;i++){
 a=*p++;
 buf[0]=M2C_FIELD((u8 *)data_ov001_02193da4+i,u8 *,0x8);
 buf[2]=a;
 func_ov001_0218b12c(M2C_FIELD(data_ov001_02193da4,s32 *,0),a,buf[3],buf[4],buf[5],2,0x480,buf);
 }
 func_ov001_0218b298(M2C_FIELD(data_ov001_02193da4,s32 *,0));
}
#pragma opt_store reset
void func_ov001_0217c8ac(void){extern void *data_ov001_02193da4;extern M2C_UNK data_ov001_0218f888;void *obj;u8 idx;u32 *p;u8 value;u32 old;obj=data_ov001_02193da4;idx=M2C_FIELD(obj,u8*,0x14);p=M2C_FIELD(obj,u32**,4);if((s32)idx>3)idx=3;value=M2C_FIELD(&data_ov001_0218f888,u8*,idx*3+2);old=*p;*p=(old & 0xFE00FF00)|0x28|(((u32)value << 23) >> 7);}
#pragma scheduling on
void func_ov001_0217c900(void) {
    extern void *data_ov001_02193da4;
    extern M2C_UNK func_ov001_0217c95c;
    M2C_FIELD(data_ov001_02193da4, u8 *, 0x15) = func_ov001_02186648();
    switch (M2C_FIELD(data_ov001_02193da4, u8 *, 0x15)) {
    case 0: func_ov001_02185024(7); break;
    case 1: func_ov001_02185024(0xE); break;
    default: return;
    }
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_0217c95c);
}

void func_ov001_0217c95c(void) {
 s32 func_ov001_0218665c(); M2C_UNK func_ov001_02175db4(s32 *,s32);
 extern void *data_ov001_02193da4; 
 CodeHandlers table=data_ov001_0218f874; s32 index; s32 *p;
 if(func_ov001_0218665c()) return;
 if(M2C_FIELD(data_ov001_02193da4,u8 *,0x15)==0) {
 p=M2C_FIELD(data_ov001_02193da4,s32 **,4); *p &=0xc1fffcff;
 func_ov001_02175d54((M2C_UNK *)&func_ov001_0217c208); return;
 }
 func_ov001_02175db4(&index,0);
 table.handlers[index]((u8 *)data_ov001_02193da4+8);
 func_ov001_02175d54((M2C_UNK *)&func_ov001_0217c744);
}

void func_ov001_0217ca10(void) {
 M2C_UNK func_ov001_0217c7e8(); extern void *data_ov001_02193da4;
 u8 *p; s32 i,j; u8 c;
 for(i=0;i<4;i++) {
 p=(u8 *)data_ov001_02193da4+8+i*3;
 for(j=0;j<3;j++) {c=p[j]; if(c!=48 && c!=32 && c!=0) break; p[j]=(j==2)?48:32;}
 }
 func_ov001_0217c7e8();
}

s32 func_ov001_0217ca88(void) {
extern const u16 data_ov001_0218f848[];
extern void *data_ov001_02193da4;
void func_ov001_02184ec4(void *,void *);
s32 func_ov001_02175db4(s32 *,s32);
s32 func_0204612c(void *);
u8 limit[4]="255"; s32 mode; u8 buf[4]; s32 j,i,zero; u8 *base;
const u8 *src=(const u8 *)data_ov001_0218f848;

for(i=0;i<4;i++){
u8 *p=(u8 *)data_ov001_02193da4+8+i*3;
if(*p==32) continue;
for(j=0;j<3;j++){if(p[j]>limit[j])return 0;if(p[j]<limit[j])break;}
}
func_ov001_02184ec4((u8 *)data_ov001_02193da4+8,buf);
func_ov001_02175db4(&mode,0);
if(mode==1){zero=0;for(i=0;i<4;i++){for(j=0;j<8;j++){if(zero){if(buf[i]&(1<<(7-j)))return 0;}else if(!(buf[i]&(1<<(7-j))))zero=1;}}return 1;}
return func_0204612c(buf)!=0;
}

void func_ov001_0217cbdc(void) {
    extern M2C_UNK func_ov001_0217cc08;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_0217cc08);
}

void func_ov001_0217cc08(void) {
    extern void *data_ov001_02193da4;
    void func_ov001_0217c208(void);
    s32 *temp_r3;

    if (func_ov001_0218665c() != 0) {
        return;
    }
    temp_r3 = M2C_FIELD(data_ov001_02193da4, s32 **, 4);
    *temp_r3 &= 0xC1FFFCFF;
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217c208);
}

void func_ov001_0217cc4c(void) {
    void func_ov001_0217cc68(void);
    M2C_UNK func_ov001_0217cce8();
    extern M2C_UNK func_ov001_0217d044;
    func_ov001_0217cc68();
    func_ov001_0217cce8();
    func_ov001_02175d54(&func_ov001_0217d044);
}

void func_ov001_0217cc68(void) {
M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
extern M2C_UNK data_ov001_021907e8, func_0200448c;
func_ov001_02171d90(&data_ov001_021907e8, &func_0200448c);
M2C_FIELD((void *)0x04001008,u16 *,0) = (M2C_FIELD((void *)0x04001008,u16 *,0)&~3)|3;
M2C_FIELD((void *)0x04001008,u16 *,2) = (M2C_FIELD((void *)0x04001008,u16 *,2)&~3)|3;
*(u16 *)0x04000008 = (*(u16 *)0x04000008&~3)|3;
M2C_FIELD((void *)0x0400000A,u16 *,0) = (M2C_FIELD((void *)0x0400000A,u16 *,0)&~3)|3;
M2C_FIELD((void *)0x0400000A,u16 *,2) = (M2C_FIELD((void *)0x0400000A,u16 *,2)&~3)|3;
}

