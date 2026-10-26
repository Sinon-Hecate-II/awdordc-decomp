/* 20 functions from 0x0207A3B0 to 0x0207B2F0 (main), found by ds-decomp. */
#include "common.h"

void func_0207a61c(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, u16 arg4, u8 arg5, u8 arg6) {
    M2C_UNK func_0207a3b0(s32, M2C_UNK, u16, u8, s32, s32, s32, s32, s32, s32, s32);
    func_0207a3b0(arg0 + (arg1 * 2) + (arg2 << 6), arg3, arg4, arg5, (s32) arg6, 0, 0, 0, 0, 0, 0);
}

void func_0207a668(void) {

}

void func_0207a66c(s32 arg0, s32 arg1) {
 extern void *data_027e0058;
 extern void *gCur3DSpriteEngine;
 void *temp_r2;
 void *temp_r4;
 temp_r4 = M2C_FIELD(data_027e0058,void **,0);
 temp_r2 = (u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + (((u32)((arg0 - M2C_FIELD(temp_r4,u16 *,0x5150)) << 28) >> 27) * 2) + (((u32)((arg1 - M2C_FIELD(temp_r4,u16 *,0x5152)) << 28) >> 22) * 2);
 if (M2C_FIELD(M2C_FIELD((u8 *)temp_r4 + arg1*4,s8 **,0x52e8),s8 *,arg0) < 0) {
 M2C_FIELD(temp_r2,u16 *,0)=0;
 M2C_FIELD(temp_r2,u16 *,2)=0;
 M2C_FIELD(temp_r2,u16 *,0x40)=0;
 M2C_FIELD(temp_r2,u16 *,0x42)=0;
 return;
 }
 M2C_FIELD(temp_r2,u16 *,0)=0x124;
 M2C_FIELD(temp_r2,u16 *,2)=0x125;
 M2C_FIELD(temp_r2,u16 *,0x40)=0x126;
 M2C_FIELD(temp_r2,u16 *,0x42)=0x127;
}

void func_0207a710(void *arg0) {
    extern void *data_027e0058;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), s32 *, 0x5C);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(func_01ffa3dc(temp_r0, arg0), s16 *, 0x6C) = (s16) M2C_FIELD(arg0, s16 *, 0x6C);
}

void func_0207a748(s16 arg0) {
    extern M2C_UNK data_02100bb0;
    M2C_FIELD(func_01ffa3dc(&data_02100bb0, 7), s16 *, 0x6C) = arg0;
}

void func_0207a768(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02100bb0;
    func_01ffa9e4(&data_02100bb0);
}

void func_0207a77c(s32 arg0) {
 extern void *data_027e0058;
 void (*temp_r1)(s32);
 temp_r1 = M2C_FIELD(M2C_FIELD(data_027e0058,void **,4),void (**)(s32),0x2c);
 if (temp_r1 == 0) return;
 temp_r1(arg0);
}

void func_0207ab24(s32 arg0, s32 arg1) {
 M2C_UNK func_0207ab84(s32,s32,u8);
 M2C_UNK func_020cfd28(void);
 M2C_UNK func_020cf2c8(void);
 M2C_UNK func_020d2470(void);
 extern void *data_027e0058;
 s32 temp_ip;
 s32 temp_r3_2;
 u8 *temp_lr;
 void *temp_r3;
 temp_r3 = M2C_FIELD(data_027e0058,void **,0);
 temp_lr = (u8 *)temp_r3 + 0x1420;
 temp_ip = arg0 + M2C_FIELD((u8 *)temp_r3 + arg1*2,u16 *,0x3758);
 temp_r3_2 = M2C_FIELD(temp_r3,u16 *,0x52a6) + (temp_lr[temp_ip] & 0x1f);
 temp_lr[temp_ip] = temp_r3_2;
 func_0207ab84(arg0,arg1,(u8)(temp_r3_2 & 0xe0));
 func_020cfd28();
 func_020cf2c8();
 func_020d2470();
}

s32 func_0207ab84(s32 arg0, s32 arg1, u8 arg2) {
extern u16 data_0211fafc[];
extern void *data_027e0058;
s32 i=0;
s32 base;
u16 value;
void *p;
if(data_0211fafc[0] != 0xffff) {
p=M2C_FIELD(data_027e0058,void **,0);
value=M2C_FIELD((u8 *)p+2*(arg0+M2C_FIELD((u8 *)p+arg1*2,u16 *,0x3758)),u16 *,0xa10);
do { if(data_0211fafc[i]==value) break; i++; } while(data_0211fafc[i] != 0xffff);
}
p=M2C_FIELD(data_027e0058,void **,0);
base=(i/5)*5;
M2C_FIELD((u8 *)p+2*(arg0+M2C_FIELD((u8 *)p+arg1*2,u16 *,0x3758)),u16 *,0xa10)=data_0211fafc[base+(arg2>>5)];
return (s16)base;
}

s32 func_0207ac54(s32 arg0,s32 arg1,s32 arg2){
extern u16 data_0211fafc[];
extern void *data_027e0058;
s32 i=0; s32 base; u16 value; void *p;
if(data_0211fafc[0]!=0xffff){
p=M2C_FIELD(data_027e0058,void **,0);
value=M2C_FIELD((u8*)p+2*(arg0+M2C_FIELD((u8*)p+arg1*2,u16 *,0x3758)),u16 *,0xa10);
do{if(data_0211fafc[i]==value)break;i++;}while(data_0211fafc[i]!=0xffff);
}
base=(i/5)*5;
if(base<5){
p=M2C_FIELD(data_027e0058,void **,0);
M2C_FIELD((u8*)p+2*(arg0+M2C_FIELD((u8*)p+arg1*2,u16 *,0x3758)),u16 *,0xa10)=data_0211fafc[base+10+(arg2>>5)];
}return (s16)base;
}

/* Update each active entity (1..4) according to the state nibble packed in `value`. */
void func_0207ad30(s32 value) {
    s32 func_020d1980(s32);
    s32 func_020d1a74(s32);
    s32 func_020a2be0(s32);
    extern void *data_027e0058;

    s32 state = (value >> 2) & 15;
    s32 i;
    void (*callback)(s32, s32);

    for (i = 1; i < 5; i++) {
        if (!func_020d1980(i)) {
            continue;
        }
        if (func_020d1a74(i) && state >= 0) {
            callback = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), void (**)(s32, s32), 0x24);
            if (callback) {
                callback(i, state);
            }
        } else if (func_020a2be0(i)) {
            switch (state) {
            case 15: {
                callback = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), void (**)(s32, s32), 0x24);
                if (callback) {
                    callback(i, 7);
                }
                break;
            }
            default: {
                callback = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), void (**)(s32, s32), 0x24);
                if (callback) {
                    callback(i, 0);
                }
                break;
            }
            }
        } else {
            callback = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), void (**)(s32, s32), 0x24);
            if (callback) {
                callback(i, 0);
            }
        }
    }
}

void func_0207af6c(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x54));
}

void func_0207af7c(void *arg0) {
    s32 temp_r0;
    s32 temp_r6;
    s32 temp_r1;
    s32 temp_r2;
    s32 temp_r7;
    s32 temp_lr;
    s32 temp_r3;
    s32 temp_r12;
    void *temp_r4;
    void *temp_r5 = arg0;

    if ((s16) M2C_FIELD(temp_r5, s16 *, 0x6E) != 8) {
        func_0207a748(1);
        func_01ffa574(temp_r5);
        return;
    }
    M2C_FIELD(temp_r5, s16 *, 0x6E) = (s16) ((s16) M2C_FIELD(temp_r5, s16 *, 0x6E) + 1);
    if ((s16) M2C_FIELD(temp_r5, s16 *, 0x6C) > 0xCC) {
        return;
    }
    func_02091230();
    if ((s16) M2C_FIELD(temp_r5, s16 *, 0x6C) <= 0) {
        return;
    }
    temp_r4 = (void *) M2C_FIELD(temp_r5, s32 *, 0x54);
    temp_r1 = 0;
    do {
        temp_r7 = temp_r1 << 3;
        temp_lr = (s16) M2C_FIELD((u8 *)temp_r4 + temp_r7, s16 *, 0);
        temp_r6 = (s16) M2C_FIELD((u8 *)temp_r4 + temp_r7, s16 *, 4);
        temp_r1++;
        temp_r2 = temp_r1 << 16;
        temp_r1 = temp_lr + temp_r6;
        M2C_FIELD((u8 *)temp_r4 + temp_r7, s16 *, 0) = temp_r1;
        temp_r6 = (s16) M2C_FIELD((u8 *)temp_r4 + temp_r7, s16 *, 2);
        temp_lr = (s16) M2C_FIELD((u8 *)temp_r4 + temp_r7, s16 *, 6);
        temp_r1 = temp_r2 >> 16;
        temp_r6 += temp_lr;
        M2C_FIELD((u8 *)temp_r4 + temp_r7, s16 *, 2) = temp_r6;
        {
            volatile u32 *addr = (volatile u32 *)0x040004A4;
            *addr = 0x1F0080;
        }
    } while ((s16) M2C_FIELD(temp_r5, s16 *, 0x6C) > (s16)(temp_r2 >> 16));
}

void func_0207b028(M2C_UNK arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02100bd0;
    func_01ffa3dc(&data_02100bd0, arg0);
}

void func_0207b040(void) {
 M2C_UNK func_01ffa9e4(M2C_UNK *);
 extern M2C_UNK data_02100bd0;
 func_01ffa9e4(&data_02100bd0);
 func_0207a768();
}

