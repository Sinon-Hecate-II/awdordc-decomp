/* 26 functions from 0x0217BD88 to 0x0217CCE8 (ov001), found by ds-decomp. */
#include "common.h"

typedef struct { void (*handlers[5])(void *); } CodeHandlers;
extern const CodeHandlers data_ov001_0218f874;
extern const CodeHandlers data_ov001_0218f860;
extern const u16 data_ov001_0218f848[];
extern void *data_ov001_02193da4;
extern u32 data_ov001_02190770;

/* Decides whether the name just entered on the ov001 name-entry screen is
 * acceptable: entry mode 0 accepts any non-empty name; otherwise only certain
 * lengths pass, and the 10, 26 and 32-character forms (a code) must be all
 * hexadecimal.  A rejected attempt plays the error sound. */
s32 IsNameEntryValid(void) {
    s32 mode, variant, length, i;
    u8 *text;
    extern void *gNameEntryState;

    func_ov001_02175db4(&mode, &variant);
    if (variant == 1) func_ov001_02171c24(0x35, -1, 0);
    func_ov001_02175db4(&mode, &variant);
    if (mode == 0) return M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_TEXT) != 0;
    if (variant == 1 && M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_TEXT) == 0) return 0;
    length = StringLengthUpTo((u8 *)gNameEntryState + NAME_ENTRY_TEXT, NAME_ENTRY_MAX_LENGTH);
    switch (length) {
    case 0:
    case 5:
    case 13:
    case 16:
        return 1;
    case 10:
    case 26:
    case 32:
        for (i = 0; i < length; i++) {
            u8 ch;
            text = (u8 *)gNameEntryState;
            ch = text[i + NAME_ENTRY_TEXT];
            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) continue;
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_ov001_0217bf14(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_0217bf40;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_0217bf40);
}

void func_ov001_0217bf40(void) {
    s32 func_ov001_0218665c();
    extern void *gNameEntryState;
    extern M2C_UNK func_ov001_0217b688;
    s32 *temp_r3;

    if (func_ov001_0218665c() != 0) {
        return;
    }
    temp_r3 = M2C_FIELD(gNameEntryState, s32 **, 4);
    *temp_r3 &= 0xC1FFFCFF;
    Ov001_SetStepCallback(&func_ov001_0217b688);
}

void func_ov001_0217bf84(void) {
void *func_ov001_0218b6f8(s32,s32);s32 func_ov001_02175db4(s32*,s32);
void *CreateTextPanel(s32,s32);void *func_ov001_0218a5f0(s32,s32);
void func_ov001_0217c0f8(void);void func_ov001_0217c8ac(void);void func_ov001_0217c1b4(void);
CodeHandlers handlers=data_ov001_0218f860;
u8 choices[5]={((u8*)data_ov001_0218f848)[8],((u8*)data_ov001_0218f848)[9],((u8*)data_ov001_0218f848)[10],((u8*)data_ov001_0218f848)[11],((u8*)data_ov001_0218f848)[12]};
s32 a;void *p;
data_ov001_02193da4=func_ov001_0218b6f8(24,4);
func_ov001_02175db4(&a,0);
handlers.handlers[a](data_ov001_02193da4+8);
p=data_ov001_02193da4;
if(ByteCompareN(p+8,&data_ov001_02190770,3)) M2C_FIELD(p,u8*,20)=3;
else {MI_CpuFill8(p+8,0,12);M2C_FIELD(data_ov001_02193da4,u8*,20)=0;}
func_ov001_0217c0f8();func_ov001_02172250(a+11);func_ov001_02171c24(choices[a],-1,0);func_ov001_02171dd0(2);
M2C_FIELD(data_ov001_02193da4,void**,0)=CreateTextPanel(0,0);
M2C_FIELD(data_ov001_02193da4,void**,4)=func_ov001_0218a5f0(0,63);
M2C_FIELD(M2C_FIELD(data_ov001_02193da4,void**,4),u16*,4)=(M2C_FIELD(M2C_FIELD(data_ov001_02193da4,void**,4),u16*,4)&~0xc00)|0xc00;
func_ov001_0217c8ac();func_ov001_0217c7e8();Ov001_SetStepCallback((s32*)func_ov001_0217c1b4);
}
void func_ov001_0217c0f8(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190774;
    extern M2C_UNK data_ov001_02190788;
    extern M2C_UNK data_ov001_021907a0;
    extern M2C_UNK data_ov001_021907b8;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK func_02004160;
    extern M2C_UNK func_0200448c;
    extern M2C_UNK func_020046cc;
    Ov001_LoadAsset(&data_ov001_02190774, &func_02004160);
    Ov001_LoadAsset(&data_ov001_02190788, &func_020046cc);
    Ov001_LoadAsset(&data_ov001_021907a0, &GX_LoadBGPltt);
    Ov001_LoadAsset(&data_ov001_021907b8, &func_0200448c);
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
    Ov001_SetStepCallback(&func_ov001_0217c208);
}

void func_ov001_0217c208(void) {
    s32 func_ov001_0217c5d4(s32);
    extern M2C_UNK func_ov001_0217c294;
    extern void *data_ov001_02193da4;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_0217416c();
    Ov001_PlaySound(0x14);
    if (M2C_FIELD(data_ov001_02193da4, u8 *, 0x14) == 0) {
        func_ov001_021744f0(0);
        func_ov001_02174518(0);
    } else {
        if (func_ov001_0217c5d4(0x1A) != 0) func_ov001_02174504(0);
        func_ov001_02174518(0);
    }
    Ov001_SetStepCallback(&func_ov001_0217c294);
}

void func_ov001_0217c294(void) {
    s32 func_ov001_021744dc();
    extern M2C_UNK func_ov001_0217c2b4;
    if (func_ov001_021744dc() == 0x1F) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0217c2b4);
}

void func_ov001_0217c2b4(void) {
    M2C_UNK func_ov001_0217c2c4();
    void func_ov001_0217c668(void);
    func_ov001_0217c2c4();
    func_ov001_0217c668();
}

s32 func_ov001_0217c2c4(void){
void func_ov001_0217c8ac(void);
void func_ov001_0217ca10(void);
s32 func_ov001_021744dc(void);
s32 func_ov001_0217c5d4(s32);
void func_ov001_0217c66c(void);
s32 code=func_ov001_021744dc();u8 *p; s32 i,a,b;
if(code==0)return;
switch(code){
case 16:
if(M2C_FIELD(data_ov001_02193da4,u8 *,20)==0 && M2C_FIELD(data_ov001_02193da4,u8 *,10)==0)break;
Ov001_PlaySound(3);
p=data_ov001_02193da4;i=p[20];
if(!p[8+i*3+2])p[20]=i-1;
MI_CpuFill8((u8 *)data_ov001_02193da4+8+M2C_FIELD(data_ov001_02193da4,u8 *,20)*3,0,3);
if(M2C_FIELD(data_ov001_02193da4,u8 *,20)==0 && M2C_FIELD(data_ov001_02193da4,u8 *,10)==0)func_ov001_021744f0(0);
func_ov001_02174504(1);func_ov001_02174518(0);break;
case 17:
p=data_ov001_02193da4;
if(p[20]<3 && p[8+p[20]*3+2]){
Ov001_PlaySound(1);M2C_FIELD(data_ov001_02193da4,u8 *,20)++;func_ov001_02174518(0);
}break;
case 18:
M2C_FIELD(data_ov001_02193da4,u8 *,21)=0;
Ov001_PlaySound(7);Ov001_SetStepCallback((s32 *)&func_ov001_0217c66c);return;
case 19:
if(func_ov001_0217ca88()){
Ov001_PlaySound(6);M2C_FIELD(data_ov001_02193da4,u8 *,21)=1;
}else{
M2C_FIELD(data_ov001_02193da4,u8 *,21)=2;Ov001_PlaySound(9);
}
M2C_FIELD(data_ov001_02193da4,u8 *,20)=3;
p=M2C_FIELD(data_ov001_02193da4,u8 **,4);
*(u32 *)p=(*(u32 *)p&0xc1fffcff)|512;
func_ov001_0217c8ac();func_ov001_0217ca10();Ov001_SetStepCallback((s32 *)&func_ov001_0217c66c);return;
default:
if(M2C_FIELD(data_ov001_02193da4,u8 *,20)==3 && func_ov001_0217c5d4(26))break;
Ov001_PlaySound(1);
p=(u8 *)data_ov001_02193da4+8;i=M2C_FIELD(data_ov001_02193da4,u8 *,20)*3;
a=p[i+2];
if(!a)p[i+2]=code;
else if(!(b=p[i+1])){
p[i+1]=a;p[i+2]=code;
if(func_ov001_0217c5d4(26) && M2C_FIELD(data_ov001_02193da4,u8 *,20)<3)M2C_FIELD(data_ov001_02193da4,u8 *,20)++;
}else{
p[i]=b;p[i+1]=p[i+2];p[i+2]=code;
if(M2C_FIELD(data_ov001_02193da4,u8 *,20)<3)M2C_FIELD(data_ov001_02193da4,u8 *,20)++;
}
func_ov001_021744f0(1);
if(M2C_FIELD(data_ov001_02193da4,u8 *,20)<3)func_ov001_02174518(1);else func_ov001_02174518(0);
if(M2C_FIELD(data_ov001_02193da4,u8 *,20)==3 && func_ov001_0217c5d4(26))func_ov001_02174504(0);
break;
}
func_ov001_0217c7e8();func_ov001_0217c8ac();
}

s32 func_ov001_0217c5d4(s32 arg0) {
    M2C_UNK MI_CpuCopy8(void *, u8 *, s32);
    s32 ParseInt(u8 *);
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
    MI_CpuCopy8(base + offset, buf, 3);
    i = 0;
    p = buf;
    buf[3] = 0;
    do {
        if (*p != 0) break;
        i++;
        *p++ = 0x20;
    } while (i < 3);
    return ParseInt(buf) >= arg0;
}

void func_ov001_0217c668(void) {

}

void func_ov001_0217c66c(void) {
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217c688;
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217c688);
}

void func_ov001_0217c688(void) {
    M2C_UNK func_ov001_021744a8();
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217c6b8;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_021744a8();
    Ov001_PlaySound(0x15);
    Ov001_SetStepCallback(&func_ov001_0217c6b8);
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
        Ov001_SetStepCallback(&func_ov001_0217c744);
        return;
    }
    if (state == 2) {
        func_ov001_021862d8(6, 3, 1, -1, 0);
        Ov001_SetStepCallback(&func_ov001_0217cbdc);
        return;
    }
    func_ov001_021862d8(0x47, 2, 1, -1, 0);
    Ov001_SetStepCallback(&func_ov001_0217c900);
}

#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov001_0217c744(void) {
M2C_UNK Ov001_LoadAsset(M2C_UNK *,M2C_UNK *);
extern void *data_ov001_02193da4;
extern M2C_UNK data_ov001_021907d0,func_02004160,InitMapListScreen;
s32 sp0;void *state;
func_ov001_02171cf8();
state=data_ov001_02193da4;func_ov001_0218c104(M2C_FIELD(state,s32 *,4));
func_ov001_0218af70(0);Ov001_LoadAsset(&data_ov001_021907d0,&func_02004160);
func_ov001_0218b368(1,1);func_ov001_0218b368(0,0x15);
func_ov001_02175db4(&sp0,0);if(sp0>=3)sp0++;
func_ov001_02175d64(2,1);func_ov001_02175da0(0,sp0+3);
Ov001_SetStepCallback(&InitMapListScreen);
func_ov001_0218b71c((u8*)&data_ov001_02193da4);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
M2C_UNK func_ov001_0217c7e8(void){
 extern void *data_ov001_02193da4; extern const u16 data_ov001_0218f848[]; extern M2C_UNK data_ov001_0218f888;
 void func_ov001_0218b1ec(s32,s32);void DrawPanelText(s32,s32,s32,s32,s32,s32,s32,void *);void CloseTextPanel(s32);
 u16 buf[6];s32 i,a,handle;const u8 *p;
 handle=M2C_FIELD(data_ov001_02193da4,s32 *,0);
 buf[2]=data_ov001_0218f848[7];buf[3]=data_ov001_0218f848[8];buf[4]=11;buf[5]=16;
 func_ov001_0218b1ec(handle,0);
 buf[1]=0;
 p=(const u8 *)&data_ov001_0218f888;
 for(i=0;i<12;i++){
 buf[0]=M2C_FIELD((u8 *)data_ov001_02193da4+i,u8 *,0x8);
 a=*p++;buf[2]=a;
 DrawPanelText(M2C_FIELD(data_ov001_02193da4,s32 *,0),a,buf[3],buf[4],buf[5],2,0x480,buf);
 }
 CloseTextPanel(M2C_FIELD(data_ov001_02193da4,s32 *,0));
}
#pragma opt_store reset
void func_ov001_0217c8ac(void) {
extern void *data_ov001_02193da4; extern M2C_UNK data_ov001_0218f888;
void *obj=data_ov001_02193da4;
s32 index=M2C_FIELD(obj,u8*,0x14);
u32 *p=M2C_FIELD(obj,u32**,4);
if(index<=3) {} else index=3;
*p=(*p&0xFE00FF00)|0x28|(((u32)M2C_FIELD(&data_ov001_0218f888,u8*,index*3+2)<<23)>>7);
}
#pragma scheduling on
void func_ov001_0217c900(void) {
    extern void *data_ov001_02193da4;
    extern M2C_UNK func_ov001_0217c95c;
    M2C_FIELD(data_ov001_02193da4, u8 *, 0x15) = func_ov001_02186648();
    switch (M2C_FIELD(data_ov001_02193da4, u8 *, 0x15)) {
    case 0: Ov001_PlaySound(7); break;
    case 1: Ov001_PlaySound(0xE); break;
    default: return;
    }
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_0217c95c);
}

void func_ov001_0217c95c(void) {
 s32 func_ov001_0218665c(); M2C_UNK func_ov001_02175db4(s32 *,s32);
 extern void *data_ov001_02193da4; 
 CodeHandlers table=data_ov001_0218f874; s32 index; s32 *p;
 if(func_ov001_0218665c()) return;
 if(M2C_FIELD(data_ov001_02193da4,u8 *,0x15)==0) {
 p=M2C_FIELD(data_ov001_02193da4,s32 **,4); *p &=0xc1fffcff;
 Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217c208); return;
 }
 func_ov001_02175db4(&index,0);
 table.handlers[index]((u8 *)data_ov001_02193da4+8);
 Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217c744);
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
u8 limit[4]="255"; s32 mode; u8 buf[4]; u8 *p; s32 j,i,zero; u8 *base;
const u8 *src=(const u8 *)data_ov001_0218f848;

for(i=0;i<4;i++){
p=(u8 *)data_ov001_02193da4+8+i*3;
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
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_0217cc08);
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
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217c208);
}

void func_ov001_0217cc4c(void) {
    void func_ov001_0217cc68(void);
    M2C_UNK func_ov001_0217cce8();
    extern M2C_UNK func_ov001_0217d044;
    func_ov001_0217cc68();
    func_ov001_0217cce8();
    Ov001_SetStepCallback(&func_ov001_0217d044);
}

void func_ov001_0217cc68(void) {
M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
extern M2C_UNK data_ov001_021907e8, func_0200448c;
Ov001_LoadAsset(&data_ov001_021907e8, &func_0200448c);
M2C_FIELD((void *)0x04001008,u16 *,0) = (M2C_FIELD((void *)0x04001008,u16 *,0)&~3)|3;
M2C_FIELD((void *)0x04001008,u16 *,2) = (M2C_FIELD((void *)0x04001008,u16 *,2)&~3)|3;
*(u16 *)0x04000008 = (*(u16 *)0x04000008&~3)|3;
M2C_FIELD((void *)0x0400000A,u16 *,0) = (M2C_FIELD((void *)0x0400000A,u16 *,0)&~3)|3;
M2C_FIELD((void *)0x0400000A,u16 *,2) = (M2C_FIELD((void *)0x0400000A,u16 *,2)&~3)|3;
}

