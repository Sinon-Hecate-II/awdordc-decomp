/* 58 functions from 0x02084304 to 0x020852F4 (main), found by ds-decomp. */
#include "common.h"

typedef struct {u8 pad[0x1e];u8 value;u8 rest[0x6d];} PlayerEntry;
typedef struct {u8 pad[0x67a4];PlayerEntry entries[5];} PlayerTable;
extern void **gCurrentMap;
extern u16 data_02156e4c;
extern u8 data_ov000_021df7d0[];
extern u8 data_02156e50[];
extern u8 data_02156e5c[];

void func_02084304(void) {
    void func_0208435c();
    void func_020843e8();
    extern u16 data_02156e4c;
    switch (data_02156e4c) {                        /* irregular */
    case 0:
        func_0208435c();
        return;
    case 1:
        func_020843e8();
        return;
    }
}

s32 func_02084338(u8 *arg0) {
    u8 temp_r0;

    temp_r0 = *arg0;
    if ((temp_r0 == 0) || ((u32) temp_r0 >= 0x19U)) {
        return 0;
    }
    return 1;
}

void func_0208435c(void){void func_0208441c(void);s32 func_02085370(u8,u8 *);s32 func_ov000_0219c7c4(s32);void func_ov000_0219c7d8(s32);u8 v;void *base;func_0208441c();base=*gCurrentMap;v=M2C_FIELD((u8 *)base+0x67a4+M2C_FIELD(base,u16 *,0x52a4)*0x8c,u8 *,0x1e);if(v==2)v=0;else v-=3;if(func_02085370(v,data_ov000_021df7d0)!=1)return;if(func_02084338(data_ov000_021df7d0)!=1)return;func_ov000_0219c7c4(3);func_ov000_0219c7d8(0);data_02156e4c=1;}

void func_020843e8(void){void func_0208441c(void);s32 func_020d4dd0(void);s32 func_ov000_0219e948(void);s32 func_ov000_0219c7b0(void);func_0208441c();if(!func_020d4dd0())return;func_ov000_0219e948();if(func_ov000_0219c7b0()==2)data_02156e4c=0;}

void func_0208441c(void) {
    M2C_UNK func_0207a7a4(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cf80c();
    void *temp_r3;
    extern void **gCurrentMap;

    temp_r3 = *gCurrentMap;
    if (M2C_FIELD(((M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C) + temp_r3), u8 *, 0x67C2) == 2) {
        return;
    }
    func_020cf80c();
    func_0207a7a4(1, 4);
}

void func_02084464(u8 *a,u8 *b){s32 i=0,j=0;do{b[i]=((u32)(a[j]<<28)>>24)|(a[j+1]&15);j+=2;i++;}while(i<6);}

void func_020844a0(u8 *a,u8 *b){s32 i=0,j=0,v;do{v=(a[i]>>4)&15;if(v==15)b[j]=255;else b[j]=v;v=a[i]&15;if(v==15)b[j+1]=255;else b[j+1]=v;i++;j+=2;}while(i<6);}

void func_020844f8(void){
void func_02085348(void *,s32);
void **p;u32 i;
M2C_FIELD(&data_02156e4c,u8 *,4)=12;
p=gCurrentMap;
M2C_FIELD(&data_02156e4c,u8 *,10)=M2C_FIELD(*p,u8 *,0x515a);
i=0;
do{data_02156e50[i+12]=M2C_FIELD((u8 *)*p+i,u8 *,0x515c);i++;}while((s32)i<4);
func_02085348(data_02156e50,20);
}

void func_02084568(s32 a,s32 b,s32 c,s32 d){void func_02085348(void *,s32);s32 x;s32 v;void **p=gCurrentMap;M2C_FIELD(&data_02156e4c,u8 *,4)=a;x=M2C_FIELD(*p,s16 *,0x52dc);v=M2C_FIELD(data_ov000_021df7d0,s32 *,8);M2C_FIELD(&data_02156e4c,u8 *,6)=x;M2C_FIELD(&data_02156e4c,u8 *,7)=M2C_FIELD(*p,s16 *,0x52de);M2C_FIELD(&data_02156e4c,u8 *,8)=M2C_FIELD(*p,s16 *,0x52d8);M2C_FIELD(&data_02156e4c,u8 *,9)=M2C_FIELD(*p,s16 *,0x52da);M2C_FIELD(&data_02156e4c,u8 *,5)=b;M2C_FIELD(&data_02156e4c,s32 *,12)=v;M2C_FIELD(&data_02156e4c,u8 *,10)=c;M2C_FIELD(&data_02156e4c,u8 *,11)=d;M2C_FIELD(&data_02156e4c,u8 *,22)=data_ov000_021df7d0[18];func_02084464((u8 *)*p+0x5388,data_02156e5c);func_02085348(data_02156e50,20);}

s32 func_02084614(void) {
    s32 func_0208858c(M2C_UNK);
    if (func_0208858c(9) != 0) {
        return 1;
    }
    if (func_0208858c(0xA) != 0) {
        return 2;
    }
    return 0;
}

s32 func_02084644(void){s32 func_0208858c(s32);s32 func_ov009_02224194(void);s32 func_ov010_022282b4(s32);s32 b;if(func_0208858c(9)){if(func_ov009_02224194())b=1;else b=0;if(b)return 1;}else if(func_0208858c(10)&&func_ov010_022282b4(0))return 2;return 0;}

s32 func_020846a4(void) {
    s32 func_ov009_02224194();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        if (func_ov009_02224194() != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    case 2:
        return func_ov010_022282b4(0);
    default:
        return 0;
    }
}

s32 func_020846e8(void) {
    s32 func_ov009_02224158();
    s32 func_ov010_02228cc8();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224158();
    case 2:
        return func_ov010_02228cc8();
    default:
        return 0;
    }
}

s32 func_0208471c(void) {
    s32 func_ov010_022282f8();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        if ((func_ov009_02224194() == 8) || (func_ov009_02224194() == 9)) {
            return 1;
        }
        return 0;
    case 2:
        if (func_ov010_022282f8() != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    default:
        return 0;
    }
}

s32 func_0208477c(void) {
    s32 func_ov009_02224508(M2C_UNK);
    s32 func_ov010_022282b4(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224508(1);
    case 2:
        return func_ov010_022282b4(6);
    default:
        return 0;
    }
}

#pragma opt_common_subs off
s32 func_020847b8(void) {
    s32 func_02011af8(u16 *);
    extern u16 data_02156e64;
    s32 var_r0;

    if (func_02011af8(&data_02156e64) == 0) {
        if (data_02156e64 != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}
#pragma opt_common_subs reset
s32 func_020847f4(void){s32 a=func_02084644();switch(a){case 1:case 2:return func_020847b8()==0;default:return 1;}}

void func_02084824(void) {
    M2C_UNK func_020847f4();
    func_020847f4();
}

s32 func_02084830(void){void *func_ov010_02229b00(void);if(func_02084644()==2 && M2C_FIELD(func_ov010_02229b00(),s8 *,0x27)==0)return 1;return 0;}

s32 func_0208485c(void) {
    s32 func_ov009_022254a4();
    s32 func_ov010_02229bdc();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022254a4();
    case 2:
        return func_ov010_02229bdc();
    default:
        return 0;
    }
}

s32 func_02084890(void) {
    s32 func_ov009_022254d8();
    s32 func_ov010_02229bf4();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022254d8();
    case 2:
        return func_ov010_02229bf4();
    default:
        return 0;
    }
}

s32 func_020848c4(void) {
    s32 func_ov009_02225450();
    s32 func_ov010_02229a08();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02225450();
    case 2:
        return func_ov010_02229a08();
    default:
        return 0;
    }
}

s32 func_020848f8(void) {
    s32 func_ov009_02224174();
    s32 func_ov010_02229a24();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224174();
    case 2:
        return func_ov010_02229a24();
    default:
        return 0;
    }
}

s32 func_0208492c(void){s32 func_ov009_02225460(void);s32 func_ov010_02229a14(void);switch(func_02084644()){case 1:return (s8)func_ov009_02225460();case 2:return (s8)func_ov010_02229a14();default:return 0;}}

u16 func_02084970(void) {
    s32 bit;
    u16 var_r5;
    u8 var_r6;
    u8 var_r6_2;
    void *temp_r0_2;
    void *temp_r0_3;

    bit = 0;
    var_r5 = 0;
    switch (func_02084644()) {
    case 1:
        var_r6 = 0;
        bit = 1;
        do {
            temp_r0_2 = func_ov009_02224070(var_r6);
            if (temp_r0_2 != NULL) {
                var_r5 = (u16)(var_r5 | ((u32) bit << M2C_FIELD(temp_r0_2, s8 *, 0x17)));
            }
            var_r6 += 1;
        } while ((u32) var_r6 < 4U);
        break;
    case 2:
        var_r6_2 = 0;
        bit = 1;
        do {
            temp_r0_3 = func_ov010_02229b0c(var_r6_2);
            if (temp_r0_3 != NULL) {
                var_r5 = (u16)(var_r5 | ((u32) bit << M2C_FIELD(temp_r0_3, s8 *, 0x1B)));
            }
            var_r6_2 += 1;
        } while ((u32) var_r6_2 < 4U);
        break;
    }
    return var_r5;
}

s32 func_02084a0c(void) {
    s32 func_ov009_02225470();
    s32 func_ov010_02229a40();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02225470();
    case 2:
        return func_ov010_02229a40();
    default:
        return 0;
    }
}

void func_02084a40(void) {
    M2C_UNK func_ov009_02225480();
    M2C_UNK func_ov010_02229a50();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02225480();
        return;
    case 2:
        func_ov010_02229a50();
        return;
    }
}

s32 func_02084a6c(void) {
    s32 func_ov009_02225494();
    s32 func_ov010_02229a64();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02225494();
    case 2:
        return func_ov010_02229a64();
    default:
        return 0;
    }
}

s32 func_02084aa0(s32 a){s32 v,r;v=func_02084a6c();r=1;if(!(v&(1<<a)))r=0;return r;}

s32 func_02084ac0(M2C_UNK arg0) {
    s32 func_ov009_02224070(M2C_UNK);
    s32 func_ov010_02229b0c(M2C_UNK);
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    temp_r0_3 = func_02084644();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = func_ov009_02224070(arg0);
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
    case 2:
        temp_r0 = func_ov010_02229b0c(arg0);
        if (temp_r0 != 0) {
            return temp_r0;
        }
    default:
        return 0;
    }
}

s8 func_02084b08(M2C_UNK arg0) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_3 = func_02084644();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = func_ov009_02224070(arg0);
        if (temp_r0_2 != NULL) {
            return M2C_FIELD(temp_r0_2, s8 *, 0x18);
        }
    case 2:
        temp_r0 = func_ov010_02229b0c(arg0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, s8 *, 0x24);
        }
    default:
        return -1;
    }
}

s8 func_02084b58(M2C_UNK arg0) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_3 = func_02084644();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = func_ov009_02224070(arg0);
        if (temp_r0_2 != NULL) {
            return M2C_FIELD(temp_r0_2, s8 *, 0x19);
        }
    case 2:
        temp_r0 = func_ov010_02229b0c(arg0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, s8 *, 0x25);
        }
    default:
        return -2;
    }
}

s8 func_02084ba8(M2C_UNK arg0) {
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_3 = func_02084644();
    switch (temp_r0_3) {                            /* irregular */
    case 1:
        temp_r0_2 = func_ov009_02224070(arg0);
        if (temp_r0_2 != NULL) {
            return M2C_FIELD(temp_r0_2, s8 *, 0x1A);
        }
    case 2:
        temp_r0 = func_ov010_02229b0c(arg0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, s8 *, 0x26);
        }
    default:
        return -2;
    }
}

s32 func_02084bf8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_ov009_02224d9c(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_ov010_02229608(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224d9c(arg0, arg1, arg2, 0xFFFF);
    case 2:
        return func_ov010_02229608(arg0, arg1, arg2, 0xFFFF);
    default:
        return 0;
    }
}

s32 func_02084c5c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224d9c(arg0, arg1, arg2, arg3);
    case 2:
        return func_ov010_02229608(arg0, arg1, arg2, arg3);
    default:
        return 0;
    }
}

void func_02084cc0(M2C_UNK arg0) {
    M2C_UNK func_ov009_02225348(M2C_UNK);
    M2C_UNK func_ov010_02228c88(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02225348(arg0);
        return;
    case 2:
        func_ov010_02228c88(arg0);
        return;
    }
}

s32 func_02084cf8(void){void *func_ov010_02229b00(void);s32 v=-1;if(func_02084644()==2)v=M2C_FIELD(func_ov010_02229b00(),s32 *,0x1c);return v;}

void func_02084d1c(s32 arg0) {
    s32 func_02084644();
    void *func_ov010_02229b00();
    if (func_02084644() != 2) {
        return;
    }
    M2C_FIELD(func_ov010_02229b00(), s32 *, 0x1C) = arg0;
}

s32 func_02084d3c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_ov009_022240c0(M2C_UNK, M2C_UNK);
    s32 func_ov010_02229b5c(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022240c0(arg0, arg1);
    case 2:
        return func_ov010_02229b5c(arg0, arg1);
    default:
        return 0;
    }
}

void func_02084d88(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_ov009_02223f7c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov010_02229a74(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02223f7c(arg0, arg1);
        return;
    case 2:
        func_ov010_02229a74(arg0, arg1);
        return;
    }
}

s32 func_02084dcc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_ov009_0222410c(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_ov010_02229ba8(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_0222410c(arg0, arg1, arg2);
    case 2:
        return func_ov010_02229ba8(arg0, arg1, arg2);
    default:
        return 0;
    }
}

s32 func_02084e24(M2C_UNK arg0) {
    s32 func_ov009_022240f4(M2C_UNK);
    s32 func_ov010_02229b90(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022240f4(arg0);
    case 2:
        return func_ov010_02229b90(arg0);
    default:
        return 0;
    }
}

void func_02084e64(void) {
    M2C_UNK func_02084e24(M2C_UNK);
    func_02084e24(0);
}

void func_02084e74(void) {
    M2C_UNK func_ov009_02223fbc();
    M2C_UNK func_ov010_02229a94();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02223fbc();
        return;
    case 2:
        func_ov010_02229a94();
        return;
    }
}

s32 func_02084ea0(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_ov009_02225654(M2C_UNK, M2C_UNK);
    s32 func_ov010_02229d54(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02225654(arg0, arg1);
    case 2:
        return func_ov010_02229d54(arg0, arg1);
    default:
        return 0;
    }
}

s32 func_02084eec(M2C_UNK arg0) {
    s32 func_ov009_022257ac(M2C_UNK);
    s32 func_ov010_02229eb4(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_022257ac(arg0);
    case 2:
        return func_ov010_02229eb4(arg0);
    default:
        return 0;
    }
}

s32 func_02084f2c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    s32 func_ov009_02225938(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_ov010_02229fd0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {
    case 1:
        return func_ov009_02225938(arg0, arg1, arg2, arg3, arg4, arg5);
    case 2:
        return func_ov010_02229fd0(arg0, arg1, arg2, arg3, arg4, arg5);
    default:
        return 0;
    }
}

s32 func_02084fc0(M2C_UNK arg0) {
    s32 func_ov009_02224c1c(M2C_UNK);
    s32 func_ov010_022294c8(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        return func_ov009_02224c1c(arg0);
    case 2:
        return func_ov010_022294c8(arg0);
    default:
        return 0;
    }
}

void func_02085000(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02085c4c();
    M2C_UNK func_ov009_0222617c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov010_0222ba10(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;

    func_02085c4c();
    temp_r0 = func_02084614();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_0222617c(arg0, arg1, arg2);
        return;
    case 2:
        func_ov010_0222ba10(arg0, arg1, arg2);
        return;
    }
}

void func_02085054(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_ov009_022261e4(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov010_0222ba94(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_022261e4(arg0, arg1, arg2);
        return;
    case 2:
        func_ov010_0222ba94(arg0, arg1, arg2);
        return;
    }
}

void func_020850a4(M2C_UNK arg0) {
    M2C_UNK func_ov009_02226268(M2C_UNK);
    M2C_UNK func_ov010_0222bb64(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02226268(arg0);
        return;
    case 2:
        func_ov010_0222bb64(arg0);
        return;
    }
}

void func_020850dc(void) {
    M2C_UNK func_ov009_02226290();
    M2C_UNK func_ov010_0222bb8c();
    s32 temp_r0;

    temp_r0 = func_02084644();
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_ov009_02226290();
        return;
    case 2:
        func_ov010_0222bb8c();
        return;
    }
}

void func_02085108(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x40) = 0;
    M2C_FIELD(arg0, s8 *, 0x41) = 0;
}

void func_02085118(void *p){
s32 func_ov002_021e1624(void);
void func_01ff883c(u16,u8,u16,void *);
extern s32 gCur3DSpriteEngine;
extern s32 data_027e00c8;
extern u8 data_027e0064[];
s32 n; s32 saved; s32 tile,shift; u16 c,a; u8 b;
if(!func_020847b8())return;
n=func_020846e8();
if(M2C_FIELD(p,u8 *,0x40)){
if(!func_ov002_021e1624())return;
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
a=M2C_FIELD(p,s32 *,0x34)&511;
b=M2C_FIELD(p,s32 *,0x38);
tile=M2C_FIELD(p,u16 *,0x3c)+(n<<2);
shift=(u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
c=((tile>>shift)&1023)|((u32)(M2C_FIELD(p,u16 *,0x3e)<<28)>>16);
func_01ff883c(a,b,c,data_027e0064);
gCur3DSpriteEngine=saved;
}else{
a=M2C_FIELD(p,s32 *,0x34)&511;
b=M2C_FIELD(p,s32 *,0x38);
tile=M2C_FIELD(p,u16 *,0x3c)+(n<<2);
shift=(u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
c=((tile>>shift)&1023)|((u32)(M2C_FIELD(p,u16 *,0x3e)<<28)>>16);
func_01ff883c(a,b,c,data_027e0064);
}
}

s32 func_02085238(s32 a,s32 b,s32 c,s32 d){void *func_01ffa3dc(void *,s32);extern M2C_UNK data_02102088;s32 r;void *p=func_01ffa3dc(&data_02102088,7);M2C_FIELD(p,s32 *,0x34)=a;M2C_FIELD(p,s32 *,0x38)=b;M2C_FIELD(p,u16 *,0x3c)=c;M2C_FIELD(p,u16 *,0x3e)=d;r=func_02084614();switch(r){case 1:r=M2C_FIELD(p,u16 *,0x3c)+0x10;M2C_FIELD(p,u16 *,0x3c)=r;break;case 2:default:break;}return r;}

void func_02085294(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02085238(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return (void)func_02085238(arg0, arg1, 0, 0);
}

void func_020852a8(void) {
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_02085294(0xEF, 1);
    gCur3DSpriteEngine = temp_r4;
}

void func_020852e0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102088;
    func_01ffa9e4(&data_02102088);
}

