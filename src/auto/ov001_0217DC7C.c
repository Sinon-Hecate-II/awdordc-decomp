/* 12 functions from 0x0217DC7C to 0x0217EB6C (ov001), found by ds-decomp. */
#include "common.h"
static inline void GetSpriteXY(u32 *p,s32 *y,s32 *x){u32 v=*p;*y=v&255;*x=(v&0x1ff0000)>>16;}
static inline void SetSpriteXY(u32 *p,s32 y,s32 x){*p=(*p&0xfe00ff00)|(u8)y|((u32)(x<<23)>>7);}

/* Applies the map-list menu's current state: snaps the scroll position, plays
 * the move/bump sound, redraws the list, and schedules the scroll-snap callbacks
 * that finish the movement. */
void MapListHandleState(void) {
 extern M2C_UNK gMapListState;
 extern M2C_UNK func_ov001_0217ee48,func_ov001_0217ef10;
 s32 GetMenuState(void);
 s32 GetMenuRow(void);
 s32 func_020020c4(u16,s32);
 void func_ov001_02172184(void);
 void func_ov001_0217e238(void);
 void func_ov001_0217f110(void);
 M2C_UNK Ov001_PlaySound(s32);
 s32 func_ov001_0218c884(s32,s32,s32,s32);
 s32 remainder;
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56))return;
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65))--M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65);
 switch(GetMenuState()){
 case 1:M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,69)=1;return;
 case 2:
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65))return;
 func_ov001_02172184();
 M2C_FIELD(&gMapListState,u16 *,4)=GetMenuRow()*145/55;
 func_ov001_0217e238();M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65)=4;return;
 case 3:
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,69)=0;
 M2C_FIELD(&gMapListState,u16 *,4)=GetMenuRow()*145/55;
 Ov001_PlaySound(19);func_ov001_0217e238();
 remainder=func_020020c4(M2C_FIELD(&gMapListState,u16 *,4),29);
 if(remainder==0){func_ov001_0217f110();return;}
 if(remainder<16){M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=func_ov001_0218c884(0,(s32)&func_ov001_0217ee48,0,120);return;}
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=func_ov001_0218c884(0,(s32)&func_ov001_0217ef10,0,120);return;
 case 4:
 if(M2C_FIELD(&gMapListState,u16 *,4)==0){
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70))return;
 Ov001_PlaySound(9);M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70)=1;return;}
 Ov001_PlaySound(19);
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=func_ov001_0218c884(0,(s32)&func_ov001_0217ee48,0,120);return;
 case 6:
 if(M2C_FIELD(&gMapListState,u16 *,4)==145){
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70))return;
 Ov001_PlaySound(9);M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70)=1;return;}
 Ov001_PlaySound(19);
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=func_ov001_0218c884(0,(s32)&func_ov001_0217ef10,0,120);return;
 case 5:case 7:M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70)=0;return;
 default:return;
 }
}

void func_ov001_0217ded8(void) {
    M2C_UNK func_ov001_02183a08();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217def8;
    func_ov001_02183a08();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217def8);
}

void func_ov001_0217def8(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217df44;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x1D, 8);
    Ov001_SetStepCallback(&func_ov001_0217df44);
}

#pragma push
#pragma opt_strength_reduction off
void func_ov001_0217df44(void) {
extern M2C_UNK gMapListState, data_ov001_0219085c, data_ov001_02193db4;
extern M2C_UNK func_02004160,func_ov001_0217b444,func_ov001_0217bf84,func_ov001_0218223c,func_ov001_0217f73c,func_ov001_02180d44,func_ov001_02181a84;
s32 func_ov001_0218a800(s32);
void *func_ov001_0218445c(void);
s32 func_02046014(void *);
s32 i,n; u8 *p;
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
func_ov001_0218c94c(0,M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,0));
func_ov001_0218c94c(1,M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,60));
for(i=0;i<7;i++)func_ov001_0218c104(M2C_FIELD((u8 *)M2C_FIELD(&gMapListState,void **,8)+i*4,s32 *,24));
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,52))func_ov001_0218c104(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,52));
func_ov001_02183980();func_ov001_0218af70(0);func_ov001_02172184();
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)!=12)func_ov001_02171cf8();
func_ov001_021836f4();
func_ov001_02189ebc(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,8));
for(i=0;i<2;i++)func_ov001_02189ebc(M2C_FIELD((u8 *)M2C_FIELD(&gMapListState,void **,8)+i*4,s32 *,12));
func_ov001_02171d90(&data_ov001_0219085c,&func_02004160);
func_ov001_0218b368(1,1);func_ov001_0218b368(0,29);
*(volatile u32*)0x04000010=0;*(volatile u32*)0x04000018=0;
*(volatile u16*)0x0400000c=(*(volatile u16*)0x0400000c&0x43)|0xe10;
switch((u32)M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)){
case 0:case 1:func_ov001_02175da0();func_ov001_02175d64(2,0);Ov001_SetStepCallback(&func_ov001_0217b444);break;
case 4:case 5:case 6:case 9:case 10:
n=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)-4;
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)>=9)n-=2;
func_ov001_02175d64(2,0);func_ov001_02175da0(n,0);Ov001_SetStepCallback(&func_ov001_0217bf84);break;
case 11:p=func_ov001_0218445c();p[0xd0]=func_02046014(p+0xf0);
if(p[0xf5]){MI_CpuFill8(p+0xc0,0,4);MI_CpuFill8(p+0xc4,0,4);MI_CpuFill8(p+0xf0,0,4);p[0xd0]=0;}
if(p[0xf6])MI_CpuFill8(p+0xc8,0,8);
func_ov001_02175d64(2,0);func_ov001_02175da0(0,0);Ov001_SetStepCallback(&func_ov001_0218223c);break;
case 12:func_ov001_02175d64(0,0);Ov001_SetStepCallback(&func_ov001_0217f73c);break;
case 13:if(M2C_FIELD(&gMapListState,u8 *,1)==0){func_ov001_02175d64(2,1);Ov001_SetStepCallback(&func_ov001_02180d44);}
else{p=func_ov001_0218445c();func_ov001_02184880(p[0xf4]);func_ov001_02175d64(0,1);Ov001_SetStepCallback(&func_ov001_02181a84);}break;
}
func_ov001_0218b71c(&data_ov001_02193db4);
}
#pragma pop
void func_ov001_0217e238(void) {
    s32 func_02002088(u16, s32);
    void func_ov001_0217e2f8(s32, s32);
    void func_ov001_0217e494(s32, s32);
    void func_ov001_0217e95c(void);
    M2C_UNK func_ov001_02183720();
    M2C_UNK func_ov001_02183738(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b1ec(s32, M2C_UNK);
    M2C_UNK func_ov001_0218b298(s32);
    extern u16 data_ov001_0218f8fe[];
    extern M2C_UNK gMapListState;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = func_02002088(M2C_FIELD(&gMapListState, u16 *, 4), 0x1D);
    func_ov001_0218b1ec(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 0x14), 0);
    var_r5 = var_r4;
    var_r6 = 0;
    do {
        func_ov001_0217e2f8(var_r5, var_r6);
        var_r6 += 1;
        var_r5 += 1;
    } while (var_r6 < 5);
    func_ov001_02183738(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 8) + (data_ov001_0218f8fe[var_r4] * 2), 0, 0x1E, 0x13);
    var_r5 = 0;
    do {
        func_ov001_0217e494(var_r4, var_r5);
        var_r5 += 1;
        var_r4 += 1;
    } while (var_r5 < 5);
    func_ov001_02183720();
    func_ov001_0218b298(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 0x14));
    func_ov001_0217e95c();
}

#pragma opt_common_subs off
void func_ov001_0217e2f8(s32 arg0,s32 arg1){
void *func_ov001_0218445c(void);
void func_ov001_0217e780(u8*,s32);void func_ov001_0217e8d4(void*,s32);
u8 *p=func_ov001_0218445c();s32 n;u8 text[33];
switch((u32)arg0){
case 0:func_ov001_0217e780(p+0x40,arg1);break;
case 1:
switch((u32)(p[0xe6]<<30)>>30){case 0:return;case 1:n=10;break;case 2:n=26;break;case 3:n=32;break;}
if(((u32)(p[0xe6]<<24)>>26)==1)n/=2;
MI_CpuFill8(text,0,33);func_02065210(text,42,n);func_ov001_0217e780(text,arg1);break;
case 3:if(p[0xf5])return;func_ov001_0217e8d4(p+0xc0,arg1);break;
case 4:if(p[0xf5])return;func_ov001_0217e8d4(p+0xf0,arg1);break;
case 5:if(p[0xf5])return;func_ov001_0217e8d4(p+0xc4,arg1);break;
case 7:if(p[0xf6])return;func_ov001_0217e8d4(p+0xc8,arg1);break;
case 8:if(p[0xf6])return;func_ov001_0217e8d4(p+0xcc,arg1);break;
}
}

void func_ov001_0217e494(s32 arg0, s32 arg1) {
    void *func_ov001_0218445c(void);
    s32 func_ov001_0217e5e8(u32);
    void func_ov001_0217e67c(s32, s32, s32);
    extern M2C_UNK gMapListState;
    void *p;
    s32 r4 = arg0;
    s32 r5 = 0;
    s32 r1;

    p = func_ov001_0218445c();

    switch (r4) {
        case 0:
        case 1:
            r4 = 0;
            if (func_ov001_0217e5e8(0) == 0) {
                r5 = 2;
            }
            break;
        case 2: {
            u8 f5 = ((u8 *)p)[0xF5];
            void **root = M2C_FIELD(&gMapListState, void **, 8);
            u8 b4 = ((u8 *)root)[4];
            r4 = (f5 != 0) ? 1 : 2;
            if (b4 != 0) {
                r5 = 1;
            }
            r1 = 0;
            if (((u8 *)root)[5] != 0) {
                r1 = 1;
            }
            func_ov001_0217e67c(r4, r1, arg1);
            return;
        }
        case 3:
        case 4:
        case 5:
            r4 = 0;
            if (((u8 *)p)[0xF5] != 0) {
                r5 = 2;
            } else {
                r5 = 0;
            }
            break;
        case 6: {
            u8 f6 = ((u8 *)p)[0xF6];
            r5 = 0;
            if (f6 != 0) {
                r4 = 1;
            } else {
                r4 = 2;
                if (((u8 *)p)[0xF5] == 0) {
                    r5 = 2;
                }
            }
            {
                void **root = M2C_FIELD(&gMapListState, void **, 8);
                if (((u8 *)root)[6] != 0) {
                    r5 = 1;
                }
                r1 = 0;
                if (((u8 *)root)[7] != 0) {
                    r1 = 1;
                }
                func_ov001_0217e67c(r4, r1, arg1);
                return;
            }
        }
        case 7:
        case 8:
            func_ov001_0217e67c(0, 2, arg1);
            return;
        default:
            r4 = 0;
            r5 = 2;
            break;
    }
    func_ov001_0217e67c(r4, r5, arg1);
}

#pragma opt_common_subs reset
s32 func_ov001_0217e5e8(u32 arg0) {
    void *func_ov001_0218445c();
    s32 var_r1;
    void *temp_r0;

    temp_r0 = func_ov001_0218445c();
    var_r1 = 1;
    switch (arg0) {
    default:
        break;
    case 7:
        if (M2C_FIELD(temp_r0, u8 *, 0xF5) == 0) {
            var_r1 = 0;
        }
        break;
    case 0:
    case 1:
        if ((u32) (u8) (M2C_FIELD(temp_r0, u8 *, 0xE7) + 0xFF) <= 1U) {
            var_r1 = 0;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (M2C_FIELD(temp_r0, u8 *, 0xF5) != 0) {
            var_r1 = 0;
        }
        break;
    case 9:
    case 10:
        if (M2C_FIELD(temp_r0, u8 *, 0xF6) != 0) {
            var_r1 = 0;
        }
        break;
    }
    return var_r1;
}

void func_ov001_0217e67c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov001_0217ee24(s32);
    M2C_UNK func_ov001_0218a55c(M2C_UNK);
    extern M2C_UNK data_ov001_0218f8ee;
    extern M2C_UNK gMapListState;
    u16 sp[5];
    void **var_r4;
    s32 *temp_r2;

    sp[0] = 0xCC;
    sp[1] = 0xC0;
    sp[2] = 0xC0;
    sp[3] = 0x8F;
    sp[4] = 0x8F;
    var_r4 = M2C_FIELD(&gMapListState, void **, 8) + 0x18 + (arg2 * 4);
    if ((u32) (arg0 - 1) <= 1U) {
        if (func_ov001_0217ee24(arg2) == 2) {
            var_r4 = M2C_FIELD(&gMapListState, void **, 8) + 0x2C;
        } else {
            var_r4 = M2C_FIELD(&gMapListState, void **, 8) + 0x30;
        }
    }
    temp_r2 = (s32 *) *var_r4;
    if (((u8 *) arg1)[(s32) &data_ov001_0218f8ee + arg0 * 3] != 0) {
        func_ov001_0218a55c(0);
        M2C_FIELD(*var_r4, s32 *, 0) = (s32) (((u32) (sp[arg0] << 0x17) >> 7) | (M2C_FIELD(*var_r4, s32 *, 0) & 0xFE00FF00));
        M2C_FIELD(*var_r4, u16 *, 4) = (u16) ((M2C_FIELD(*var_r4, u16 *, 4) & ~0xC00) | 0xC00);
        return;
    }
    M2C_FIELD(temp_r2, s32 *, 0) = (s32) ((M2C_FIELD(temp_r2, s32 *, 0) & 0xFE00FF00) | 0x01000000);
}

void func_ov001_0217e780(u8 *arg0,s32 arg1){
extern M2C_UNK gMapListState;
s32 func_ov001_0218c3e0(u8 *,s32);
M2C_UNK MI_CpuFill8(void *,s32,s32);
M2C_UNK func_ov001_0218b080(s32,s32,s32,s32,s32,M2C_UNK *,s32);
u16 buf[17];s32 len,n,i,y;
MI_CpuFill8(buf,0,0x22);
len=func_ov001_0218c3e0(arg0,32);
n=len<=16?len:16;
for(i=0;i<n;i++){if(arg0[i]==32)buf[i]=0xe01d;else buf[i]=arg0[i];}
y=arg1*29+2;
if(len<=16)y+=5;
func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,0x14),72,y,2,8,(M2C_UNK *)buf,1);
if(len<=16)return;
MI_CpuFill8(buf,0,0x22);
len-=16;
for(i=0;i<len;i++){if(arg0[i+16]==32)buf[i]=0xe01d;else buf[i]=arg0[i+16];}
func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,0x14),72,y+12,2,8,(M2C_UNK *)buf,1);
}

void func_ov001_0217e8d4(void *arg0, s32 arg1) {
    M2C_UNK func_0206ccf8(M2C_UNK *, M2C_UNK, M2C_UNK *, u8, s32, s32, s32);
    M2C_UNK func_ov001_0218b080(s32, M2C_UNK, s32, M2C_UNK, s32, M2C_UNK *, s32);
    extern M2C_UNK data_ov001_02190874;
    extern M2C_UNK gMapListState;
    u8 spC[0x20];

    func_0206ccf8(spC, 0x10, &data_ov001_02190874, M2C_FIELD(arg0, u8 *, 0), (s32) M2C_FIELD(arg0, u8 *, 1), (s32) M2C_FIELD(arg0, u8 *, 2), (s32) M2C_FIELD(arg0, u8 *, 3));
    func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), s32 *, 0x14), 0x5F, (arg1 * 0x1D) + 8, 2, 7, spC, 1);
}

#pragma push
#pragma opt_strength_reduction off
void func_ov001_0217e95c(void){
s32 func_02002088(u16,s32);s32 func_020020c4(u16,s32);extern M2C_UNK gMapListState;
s32 row,y,i,v;u32 *p;u32 xy[2];
row=func_02002088(M2C_FIELD(&gMapListState,u16 *,4),29);
y=52-func_020020c4(M2C_FIELD(&gMapListState,u16 *,4),29);
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x34)){
p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x34);
if(row==0)xy[1]=38;else xy[1]=256;
*p=((xy[1]<<23)>>7)|((*p&0xfe00ff00)|(u8)y);}
v=y;i=0;do{
u32 old,x; p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8)+i*4,u32 **,0x18);i++;
old=*p;x=(old&0x1ff0000)>>16;*p=(old&0xfe00ff00)|(u8)v|((x<<23)>>7);
xy[0]=old&255;xy[1]=x;v+=29;
}while(i<5);
*(volatile u32 *)&xy[0]=xy[0];*(volatile u32 *)&xy[1]=xy[1];
if(row<=2){u32 old,x,z;p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x2c);old=*p;z=old&255;x=(old&0x1ff0000)>>16;xy[0]=z;xy[1]=x;*p=(old&0xfe00ff00)|(u8)((2-row)*29+y)|((x<<23)>>7);}else{p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x2c);*p=(*p&0xfe00ff00)|0x1000000;}
if(row>=2&&row<=6){u32 old,x,z;p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x30);old=*p;z=old&255;x=(old&0x1ff0000)>>16;xy[0]=z;xy[1]=x;*p=(old&0xfe00ff00)|(u8)((6-row)*29+y)|((x<<23)>>7);}else{p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x30);*p=(*p&0xfe00ff00)|0x1000000;}
M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,0x44)=1;}
#pragma pop
