/* 36 functions from 0x021E4448 to 0x021E5118 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e4448(void *arg0) {
    M2C_UNK func_ov003_021f2860(void *);
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f2780(M2C_UNK, M2C_UNK *);
    M2C_UNK func_ov006_0221734c(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020c85c4(s32, s32);
    extern M2C_UNK data_ov003_0220f47c;
    struct { void *data; u16 buf0[5]; u16 buf1[5]; } local;
    u32 count;
    u8 i;
    void *base;
    local.data = (void *)&data_ov003_0220f47c;
    for (i = 0; i < 5; i++) {
        local.buf1[i] = 0xFFFF;
        local.buf0[i] = local.buf1[i];
    }
    func_ov003_021f2860(&local);
    func_ov003_021f140c(1);
    for (i = 0; i < 5; i++) {
        count = func_ov003_021f2780((M2C_UNK)&local, local.buf0);
        base = M2C_FIELD(arg0, void **, 0x68);
        if (i >= count) {
            M2C_FIELD((s32)base + (s32)i * 0x6F8, u8 *, 0x27) = 0;
        } else {
            func_020c85c4(local.buf0[i], base + (s32)i * 0x6F8);
        }
    }
    func_ov006_0221734c(arg0, M2C_FIELD(arg0, void **, 0x68), M2C_FIELD(arg0, void **, 0x6C));
}

void func_ov003_021e450c(void) {

}

void func_ov003_021e4510(void *arg0) {
s32 func_020c8cbc(void *);void func_ov003_021f2588(void);void *func_020e34bc(s32);void func_02007ef4(void *,void *,u32);void func_020e35cc(void *);
u8 changed=0;u8 *p;u8 k;u8 *copy;u8 i,j;u8 *dest;u32 off;
for(k=0;k<5;k++){p=M2C_FIELD(arg0,u8 **,0x6c)+k*0x6f8;if((u16)func_020c8cbc(p)){p[0x27]=0;func_ov003_021f2588();changed=1;}}
if(!changed)return;
copy=func_020e34bc(0x22d8);func_02007ef4(M2C_FIELD(arg0,void **,0x6c),copy,0x22d8);
for(j=0,i=0;i<5;i++){p=copy+i*0x6f8;off=j*0x6f8;dest=M2C_FIELD(arg0,u8 **,0x6c);if(p[0x27]){func_02007ef4(p,dest+off,0x6f8);j++;}}
while(j<5){M2C_FIELD(M2C_FIELD(arg0,u8 **,0x6c)+j*0x6f8,u8 *,0x27)=0;j++;}
func_020e35cc(copy);
}

void func_ov003_021e4610(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021e4624(void) {
    M2C_UNK func_ov003_021e2518();
    func_ov003_021e2518();
}

void func_ov003_021e4630(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021e4644(void *arg0) {
    M2C_UNK func_02088d94(s32);
    M2C_UNK func_02088f1c(s32);
    void *temp_ip;
    void *temp_r1;
    void *temp_r5;

    temp_ip = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_ip, s16 *, 0xE) = 0x100;
    M2C_FIELD(temp_ip, s16 *, 0x10) = 0;
    M2C_FIELD(temp_ip, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_ip, u16 *, 2) = (u16) M2C_FIELD(temp_ip, u16 *, 4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r1, s16 *, 0xE) = -0x20;
    M2C_FIELD(temp_r1, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r1, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r1, u16 *, 2) = (u16) M2C_FIELD(temp_r1, u16 *, 4);
    func_02088d94(M2C_FIELD(arg0, s32 *, 0x4C));
    func_02088f1c(M2C_FIELD(arg0, s32 *, 0x58));
    temp_r5 = M2C_FIELD(arg0, void **, 0x44);
    func_02088f1c(M2C_FIELD(temp_r5, s32 *, 0));
    func_02088f1c(M2C_FIELD(temp_r5, s32 *, 4));
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov003_021e46bc(void) {
    M2C_UNK func_ov003_021e2628();
    func_ov003_021e2628();
}

void func_ov003_021e46c8(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

u32 func_ov003_021e46dc(void *arg0) {
    u32 func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    u32 temp_r0;
    void *temp_r4;
    void *temp_r5;
    void *temp_r5_2;

    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x60) << 0x18) >> 0x1F;
    if (temp_r0 == 0) {
        return temp_r0;
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_r5, s16 *, 0xE) = func_020a8ff4(temp_r5);
    M2C_FIELD(temp_r5, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r5, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r5, u16 *, 2) = (u16) M2C_FIELD(temp_r5, u16 *, 4);
    temp_r5_2 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r5_2, s16 *, 0xE) = func_020a8ff4(temp_r5_2);
    M2C_FIELD(temp_r5_2, s16 *, 0x10) = -0x20;
    M2C_FIELD(temp_r5_2, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r5_2, u16 *, 2) = (u16) M2C_FIELD(temp_r5_2, u16 *, 4);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    temp_r4 = M2C_FIELD(arg0, void **, 0x44);
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0));
    return func_02088ff4(M2C_FIELD(temp_r4, s32 *, 4));
}

void func_ov003_021e4764(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021e4778(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x3C);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e47a4(void) {
    void func_ov003_021e4448();
    func_ov003_021e4448();
}

void func_ov003_021e47b0(void) {
    void func_ov003_021e4510();
    func_ov003_021e4510();
}

u32 func_ov003_021e47bc(void *arg0) {
    extern M2C_UNK data_ov003_0220f47c;
    struct { void *data; u16 buf0[5]; u16 buf1[5]; } local;
    u8 count;
    u8 i;
    void *base;
    M2C_FIELD(arg0, u8 *, 0x60) = (u8)(M2C_FIELD(arg0, u8 *, 0x60) & ~0x80);
    local.data = (void *)&data_ov003_0220f47c;
    for (i = 0; i < 5; i++) {
        local.buf1[i] = 0xFFFF;
        local.buf0[i] = local.buf1[i];
    }
    func_ov003_021f2860(&local);
    count = 0;
    base = M2C_FIELD(arg0, void **, 0x6C);
    for (i = 0; i < 5; i++) {
        base = M2C_FIELD(arg0, void **, 0x6C);
        if (M2C_FIELD((s32)base + (s32)i * 0x6F8, u8 *, 0x27) != 0) {
            count = (u8)(count + 1);
        }
    }
    if (count == 0 && func_ov003_021f2780((s32)&local, local.buf0) == 0) {
        M2C_FIELD(arg0, u8 *, 0x60) = (u8)(M2C_FIELD(arg0, u8 *, 0x60) | 0x80);
    }
    count = 0;
    for (i = 0; i < 5; i++) {
        base = M2C_FIELD(arg0, void **, 0x68);
        if (M2C_FIELD((s32)base + (s32)i * 0x6F8, u8 *, 0x27) != 0) {
            count = (u8)(count + 1);
        }
    }
    if (count == 0 && func_ov003_021f2780((s32)&local, local.buf1) == 0) {
        M2C_FIELD(arg0, u8 *, 0x60) = (u8)(M2C_FIELD(arg0, u8 *, 0x60) | 0x80);
    }
    return (u32)((u32)M2C_FIELD(arg0, u8 *, 0x60) << 24) >> 31;
}

void func_ov003_021e48dc(void) {
    M2C_UNK func_ov003_021f14a0();
    func_ov003_021f14a0();
}

void func_ov003_021e48e8(void *arg0) {
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    func_ov003_021f1bd4();
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
}

void func_ov003_021e4908(void *arg0) {
    void func_ov003_021f13ec(M2C_UNK *);
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK *);
    void *func_02082028(s32);
    M2C_UNK func_020a92bc(M2C_UNK *);
    void *func_020e34bc(s32);
    void func_02091c20(s32, s32);

    extern M2C_UNK data_02102174;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220f4b4;
    extern M2C_UNK data_ov003_0220f4e0;
    extern M2C_UNK data_ov003_0220f46c;
    extern M2C_UNK data_ov003_0220f45c;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_02129870;

    void *r4;
    unsigned char *bp;
    void *p;
    s32 i;

    r4 = func_01ffa3dc(&data_02102174, arg0);
    if (r4 == 0) {
        return;
    }
    func_ov003_021f13ec(&data_02102174);

    *(void **)r4 = &data_ov003_0220f48c;
    *(void **)((char *)r4 + 0x34) = &data_ov003_0220f4b4;

    bp = (unsigned char *)r4;
    bp[0x38] = 0;
    bp[0x39] = 0;
    bp[0x3a] = 0;
    *(s32 *)(bp + 0x3c) = 0;
    *(s32 *)(bp + 0x40) = 0;
    *(s32 *)(bp + 0x44) = 0;
    *(s32 *)(bp + 0x48) = 0;
    *(s32 *)(bp + 0x4c) = 0;
    *(s32 *)(bp + 0x50) = 0;
    *(s32 *)(bp + 0x54) = 0;
    *(s32 *)(bp + 0x58) = 0;

    bp[0x60] = (unsigned char)(bp[0x60] & ~0x3);
    bp[0x60] = (unsigned char)(bp[0x60] & ~0xc);
    bp[0x60] = (unsigned char)(bp[0x60] & ~0x30);
    bp[0x60] = (unsigned char)(bp[0x60] & ~0x40);
    bp[0x60] = (unsigned char)(bp[0x60] & ~0x80);
    *(s32 *)(bp + 0x68) = 0;
    *(s32 *)(bp + 0x6c) = 0;

    p = func_02082028(0x58);
    if (p) {
        *(void **)p = &data_ov003_0220f4e0;
        *(void **)((char *)p + 4) = &data_ov003_0220f46c;
        for (i = 0; i < 5; i++) {
            *(u16 *)((char *)p + i * 2 + 0x12) = 0xFFFF;
            *(u16 *)((char *)p + i * 2 + 0x8) = 0xFFFF;
        }
        *(void **)(bp + 0x5c) = p;
    } else {
        *(void **)(bp + 0x5c) = 0;
    }

    p = func_02082028(0x12);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        q[0] = 4;
        q[1] = 0;
        *(u16 *)(q + 2) = 0;
        *(u16 *)(q + 4) = 0;
        *(u16 *)(q + 6) = 1;
        *(u16 *)(q + 8) = 0;
        *(u16 *)(q + 0xA) = 1;
        *(u16 *)(q + 0xC) = 1;
        *(u16 *)(q + 0xE) = 0;
        *(u16 *)(q + 0x10) = 0;
        *(u16 *)(q + 2) = *(u16 *)(q + 4);
        *(void **)(bp + 0x3c) = p;
    } else {
        *(void **)(bp + 0x3c) = 0;
    }

    p = func_02082028(0x12);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        q[0] = 4;
        q[1] = 0;
        *(u16 *)(q + 2) = 0;
        *(u16 *)(q + 4) = 0;
        *(u16 *)(q + 6) = 1;
        *(u16 *)(q + 8) = 0;
        *(u16 *)(q + 0xA) = 1;
        *(u16 *)(q + 0xC) = 1;
        *(u16 *)(q + 0xE) = 0;
        *(u16 *)(q + 0x10) = 0;
        *(u16 *)(q + 2) = *(u16 *)(q + 4);
        *(void **)(bp + 0x40) = p;
    } else {
        *(void **)(bp + 0x40) = 0;
    }

    p = func_02082028(0x8);
    if (p) {
        *(s32 *)p = 0;
        *(s32 *)((char *)p + 4) = 0;
    }
    *(void **)(bp + 0x44) = p;

    p = func_02082028(0x3C);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        *(void **)q = &data_ov003_0220f45c;
        q[4] = 0xFF;
        q[5] = 0xFF;
        q[6] = 0xFF;
        q[7] = 0;
        q[8] = 0;
        q[9] = 0;
        q[10] = 0;
        q[11] = 0;
        *(s32 *)(q + 0x38) = 0;
        for (i = 0; i < 11; i++) {
            *(s32 *)(q + 0xC + i * 4) = 0;
        }
        *(void **)(bp + 0x48) = p;
    } else {
        *(void **)(bp + 0x48) = 0;
    }

    p = func_02082028(0x2C);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        *(void **)q = &data_ov003_0220f47c;
        q[4] = 0;
        *(u16 *)(q + 0x12) = 0;
        q[0x14] = 8;
        q[0x15] = 8;
        q[0x16] = 1;
        q[0x17] = 8;
        q[0x18] = 8;
        q[0x20] = (unsigned char)((q[0x20] & ~0xE0) | 0x40);
        q[0x21] = 0;
        *(s32 *)(q + 0x24) = 0;
        q[0x28] = (unsigned char)(q[0x28] & ~0xE0);
        q[0x29] = 0;
        *(void **)(bp + 0x50) = p;
    } else {
        *(void **)(bp + 0x50) = 0;
    }
    p = *(void **)(bp + 0x50);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        q[0x16] = 2;
        q[0x14] = 8;
        q[0x17] = 8;
        func_020a92bc(q);
        q[0x20] = (unsigned char)((q[0x20] & ~0xE0) | 0x40);
        q[0x28] = (unsigned char)((q[0x28] & ~0xE0) | 0x20);
    }

    p = func_02082028(0x2C);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        *(void **)q = &data_ov003_0220f47c;
        q[4] = 0;
        *(u16 *)(q + 0x12) = 0;
        q[0x14] = 8;
        q[0x15] = 8;
        q[0x16] = 1;
        q[0x17] = 8;
        q[0x18] = 8;
        q[0x20] = (unsigned char)((q[0x20] & ~0xE0) | 0x40);
        q[0x21] = 0;
        *(s32 *)(q + 0x24) = 0;
        q[0x28] = (unsigned char)(q[0x28] & ~0xE0);
        q[0x29] = 0;
        *(void **)(bp + 0x54) = p;
    } else {
        *(void **)(bp + 0x54) = 0;
    }
    p = *(void **)(bp + 0x54);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        q[0x16] = 2;
        q[0x14] = 8;
        q[0x17] = 8;
        func_020a92bc(q);
        q[0x20] = (unsigned char)((q[0x20] & ~0xE0) | 0x40);
        q[0x28] = (unsigned char)(q[0x28] & ~0xE0);
        *(u16 *)(q + 0x12) = 0x270;
        q[0x21] = 0x9;
    }

    *(void **)(bp + 0x68) = func_020e34bc((s32)&data_02129870);
    *(void **)(bp + 0x6c) = func_020e34bc((s32)&data_02129870);
    func_02091c20(0x22, 0x1);
}

void *func_ov003_021e4d2c(void *arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_02082040();
    M2C_UNK func_020c127c();
    M2C_UNK func_020c8e40();
    void func_020e35cc(void *);
    extern M2C_UNK data_ov003_0220f4b4;
    extern M2C_UNK data_ov003_0220f4e0;
    M2C_UNK func_ov003_021f140c(s32);
    void **temp_r0;
    void **temp_r0_2;
    void **temp_r0_3;
    void **temp_r0_4;
    void *temp_r5;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_0220f4b4;
    M2C_FIELD(arg0, M2C_UNK **, 0x34) = &data_ov003_0220f4e0;
    func_020c8e40();
    temp_r0 = M2C_FIELD(arg0, void ***, 0x5C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_02082040();
    }
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
        func_02082040();
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r5 != NULL) {
        if (M2C_FIELD(temp_r5, s32 *, 0) != 0) {
            func_01ffa574();
        }
        if (M2C_FIELD(temp_r5, s32 *, 4) != 0) {
            func_01ffa574();
        }
        func_02082040(temp_r5);
    }
    temp_r0_2 = M2C_FIELD(arg0, void ***, 0x48);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, void (**)(void *), 4)(temp_r0_2);
    }
    temp_r0_3 = M2C_FIELD(arg0, void ***, 0x50);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(*temp_r0_3, void (**)(void *), 4)(temp_r0_3);
    }
    temp_r0_4 = M2C_FIELD(arg0, void ***, 0x54);
    if (temp_r0_4 != NULL) {
        M2C_FIELD(*temp_r0_4, void (**)(void *), 4)(temp_r0_4);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4C) != 0) {
        func_01ffa574();
    }
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_01ffa574();
    }
    func_ov003_021f140c(4);
    func_020c127c();
    if (M2C_FIELD(arg0, s32 *, 0x68) != 0) {
        func_020e35cc(M2C_FIELD(arg0, s32 *, 0x68));
    }
    if (M2C_FIELD(arg0, s32 *, 0x6C) != 0) {
        func_020e35cc(M2C_FIELD(arg0, s32 *, 0x6C));
    }
    return arg0;
}

s32 func_ov003_021e4e58(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

M2C_UNK **func_ov003_021e4e6c(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_02082040();
    extern M2C_UNK data_ov003_0220f45c;
    u8 var_r4;

    *arg0 = &data_ov003_0220f45c;
    var_r4 = 0;
    do {
        if (M2C_FIELD(((s32)arg0 + (var_r4 * 4)), s32 *, 0xC) != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while ((u32) var_r4 < 0xBU);
    func_02082040(arg0);
    return arg0;
}

void *func_ov003_021e4eb8(void *arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_02082040();
    M2C_UNK func_020c127c();
    M2C_UNK func_020c8e40();
    void func_020e35cc(void *);
    extern M2C_UNK data_ov003_0220f4b4;
    extern M2C_UNK data_ov003_0220f4e0;
    M2C_UNK func_ov003_021f140c(s32);
    void **temp_r0;
    void **temp_r0_2;
    void **temp_r0_3;
    void **temp_r0_4;
    void *temp_r5;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_0220f4b4;
    M2C_FIELD(arg0, M2C_UNK **, 0x34) = &data_ov003_0220f4e0;
    func_020c8e40();
    temp_r0 = M2C_FIELD(arg0, void ***, 0x5C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_02082040();
    }
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
        func_02082040();
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r5 != NULL) {
        if (M2C_FIELD(temp_r5, s32 *, 0) != 0) {
            func_01ffa574();
        }
        if (M2C_FIELD(temp_r5, s32 *, 4) != 0) {
            func_01ffa574();
        }
        func_02082040(temp_r5);
    }
    temp_r0_2 = M2C_FIELD(arg0, void ***, 0x48);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, void (**)(void *), 4)(temp_r0_2);
    }
    temp_r0_3 = M2C_FIELD(arg0, void ***, 0x50);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(*temp_r0_3, void (**)(void *), 4)(temp_r0_3);
    }
    temp_r0_4 = M2C_FIELD(arg0, void ***, 0x54);
    if (temp_r0_4 != NULL) {
        M2C_FIELD(*temp_r0_4, void (**)(void *), 4)(temp_r0_4);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4C) != 0) {
        func_01ffa574();
    }
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_01ffa574();
    }
    func_ov003_021f140c(4);
    func_020c127c();
    if (M2C_FIELD(arg0, s32 *, 0x68) != 0) {
        func_020e35cc(M2C_FIELD(arg0, s32 *, 0x68));
    }
    if (M2C_FIELD(arg0, s32 *, 0x6C) != 0) {
        func_020e35cc(M2C_FIELD(arg0, s32 *, 0x6C));
    }
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_021e4fec(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    extern M2C_UNK data_ov003_0220f45c;
    u8 var_r4;

    *arg0 = &data_ov003_0220f45c;
    var_r4 = 0;
    do {
        if (M2C_FIELD(((s32)arg0 + (var_r4 * 4)), s32 *, 0xC) != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while ((u32) var_r4 < 0xBU);
    return arg0;
}

void func_ov003_021e5030(void) {

}

s32 func_ov003_021e5034(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_021e5048(void) {

}

s32 func_ov003_021e504c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

#pragma peephole off
#pragma interworking off
void func_ov003_021e5060(s32 arg0) {
    void *func_ov003_021e4eb8(void *);
    func_ov003_021e4eb8(arg0 + 0xFFFFFFCC);
}
#pragma interworking reset
#pragma peephole reset
s32 func_ov003_021e50e0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

