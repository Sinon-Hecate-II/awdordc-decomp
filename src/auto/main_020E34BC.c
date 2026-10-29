/* 37 functions from 0x020E34BC to 0x020E4490 (main), found by ds-decomp. */
#include "common.h"

static inline void irq_save(s32 *state) {
    *state = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
}

static inline void irq_restore(s32 *state) {
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = *state;
}

typedef struct {
    s32 ime;
} IntrState;

static inline BOOL check_val(void *arg0, s32 *sp) {
    s32 val;
    s32 *arr;
    s32 j;
    s32 count;

    count = M2C_FIELD(arg0, s32 *, 0x38);
    val = sp[1];
    for (j = 0; (u32)j < (u32)count; j++) {
        arr = M2C_FIELD(arg0, s32 **, 0x44);
        if (arr[j] == val) {
            return TRUE;
        }
    }
    return FALSE;
}


s32 func_020e352c(s32, s32);
void func_020e34bc(s32 arg0) {
    volatile u32 saved;
    u16 old;
    u32 s;

    old = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    saved = old;
    func_020e352c(arg0, 8);
    s = saved;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = s;
}

s32 func_020e352c(s32 arg0, s32 arg1) {
 M2C_UNK func_0202a468(s32, s32, s32);
 extern s32 data_02168fe4;
 s32 saved;
 saved = *(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208 = 0;
 func_0202a468(data_02168fe4, arg0, arg1);
 (void)*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208 = saved;
}

void func_020e3580(s32 arg0,s32 arg1) {
 extern s32 data_02168fe4; volatile u32 saved; u32 temp=*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=0; saved=temp;
 func_0202a468(data_02168fe4,arg0,-arg1);
 {register volatile u16 *reg=(volatile u16*)0x04000208; u32 restore=saved; temp=*reg; *reg=restore;}
}

void func_020e35cc(s32 arg0) {
 void func_0202a498(s32, s32);
 extern s32 data_02168fe4;
 volatile u32 saved;
 u32 temp;
 u16 restore;
 temp = *(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208 = 0;
 saved = temp;
 func_0202a498(data_02168fe4, arg0);
 restore = saved;
 (void)*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208 = restore;
}

void func_020e3610(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_0208471c();
    s32 func_0208477c();
    s32 func_ov010_02226364();
    if ((func_0208471c() != 0) || (func_0208477c() != 0)) {
        func_01ffa6fc(arg0);
        return;
    }
    if (func_ov010_02226364() == 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020e3654(M2C_UNK arg0) {
    s32 func_ov010_02226560();
    if ((func_0208471c() != 0) || (func_0208477c() != 0)) {
        func_01ffa6fc(arg0);
        return;
    }
    if (func_ov010_02226560() == 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020e3698(M2C_UNK arg0) {
    s32 func_ov010_022266ec();
    if ((func_0208471c() != 0) || (func_0208477c() != 0)) {
        func_01ffa6fc(arg0);
        return;
    }
    if (func_ov010_022266ec() == 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020e36dc(void) {
 void func_020e4304(void);
 s32 func_ov010_0222613c(void);
 if (func_ov010_0222613c() == 0) return;
 func_020e4304();
}

void func_020e36f4(void) {
 s32 func_ov010_02226888(void);
 void func_020e4304(void);
 if (func_ov010_02226888() == 0) return;
 func_020e4304();
}

void func_020e370c(void *arg0) {
 M2C_UNK func_01ffa8c4(void *, s32);
 s32 func_ov010_02226738(void);
 if (func_ov010_02226738() == 5) {
  *M2C_FIELD(arg0, s32 **, 0x40) = 1;
  return;
 }
 func_01ffa8c4(arg0, 1);
}

void func_020e3738(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    s32 func_ov010_02226334(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, void *);
    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    if (func_ov010_02226334(0, 2, 0, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), arg0) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_020e3788(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
 void *func_01ffa444(void *, s32);
 extern s32 data_0212d950;
 extern s32 data_0212da10;
 void *temp_r0;
 temp_r0 = func_01ffa444(&data_0212d950, arg3);
 if (temp_r0 == NULL) return;
 M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
 M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
 M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
 M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
 M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
 M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
 M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
}

void func_020e37dc(void *arg0) {
    s32 func_ov010_02226738(void);
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 func_ov010_022267b0(s32, s32 *);
    void func_02008048(s32, void *, s32);
    s32 sp[7];
    void *temp_r4;

    if (func_ov010_02226738() != 5) {
        func_01ffa8c4(arg0, 1);
        return;
    }

    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    if (func_ov010_022267b0(0, sp) == 0) {
        return;
    }

    M2C_FIELD(temp_r4, s32 *, 0) = sp[0];
    M2C_FIELD(temp_r4, s32 *, 0x4) = sp[1];
    M2C_FIELD(temp_r4, s32 *, 0x8) = sp[2];
    M2C_FIELD(temp_r4, s32 *, 0xc) = sp[3];
    M2C_FIELD(temp_r4, s32 *, 0x30c) = sp[5];

    func_02008048(sp[6], (u8 *)temp_r4 + 0x10, sp[5]);

    *M2C_FIELD(arg0, s32 **, 0x40) = 1;
}

void func_020e3870(void *arg0) {
    void func_02007e70(s32, void *, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 sp[68];
    s32 val;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    val = M2C_FIELD(arg0, s32 *, 0x38) + 1;
    sp[0] = 0x10C;
    sp[2] = val;
    sp[3] = 0;
    sp[1] = 1;
    func_02007e70(M2C_FIELD(arg0, s32 *, 0x44), &sp[4], 0x100);
    if (func_ov010_02226538(3, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void *func_020e38f0(void *arg0, s32 arg1, s32 arg2) {
    void *func_01ffa444(void *, s32);
    s32 func_020e34f4(s32);
    s32 func_02084cf8(void);
    void func_02007e70(s32, void *, s32);
    void func_02007e54(s32, s32, s32);
    extern s32 data_0212d870;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 sp0;
    s32 temp_r2;
    u8 *ptr;

    temp_r0 = func_01ffa444(&data_0212d870, arg2);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = (s32)arg0;
        M2C_FIELD(temp_r0, s32 *, 0x38) = 1;
        M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x40) = arg1;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
        sp0 = func_02084cf8();
        func_02007e70((s32)&sp0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        func_02007e54(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
        for (ptr = (u8 *)arg0; (u32)ptr < (u32)arg0 + M2C_FIELD(temp_r0, s32 *, 0x38) * 0x310; ptr += 0x310) {
            M2C_FIELD(ptr, s32 *, 0x4) = -1;
            M2C_FIELD(ptr, s32 *, 0x8) = 0;
            M2C_FIELD(ptr, s32 *, 0x30c) = 0;
        }
    }
    return temp_r0;
}

/* Populates the list's node array from the ov010 source (mode 5 only), skipping entries whose id matches a sentinel value. */
void func_020e39d8(void *list) {
    s32 func_ov010_02226738(void);
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 func_ov010_0222681c(void);
    s32 func_ov010_02226744(void);
    s32 func_ov010_022267b0(s32, s32 *);
    s32 func_02084cf8(void);
    void func_02008048(s32, void *, s32);
    extern s32 data_0212d744;
    s32 entry[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node;

    if (func_ov010_02226738() != 5) {
        func_01ffa8c4(list, 1);
        return;
    }

    data_0212d744 = func_ov010_0222681c();
    total = func_ov010_02226744();
    count = 0;
    node = M2C_FIELD(list, u8 **, 0x34);

    for (i = 0; i < total; i++) {
        if (func_ov010_022267b0(i, entry) != 0 && entry[1] != func_02084cf8()) {
            M2C_FIELD(node, s32 *, 0) = entry[0];
            M2C_FIELD(node, s32 *, 0x4) = entry[1];
            M2C_FIELD(node, s32 *, 0x8) = entry[2];
            M2C_FIELD(node, s32 *, 0xc) = entry[3];
            M2C_FIELD(node, s32 *, 0x30c) = entry[5];

            func_02008048(entry[6], node + 0x10, entry[5]);
            node += 0x310;
            count++;
        }
    }

    *M2C_FIELD(list, s32 **, 0x40) = count;
}

void func_020e3ab4(void *arg0) {
    s32 RandomIntRange(s32, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK func_01ffa8c4(void *, s32);
    extern s32 data_0212d744;
    s32 sp[68];
    u32 r1;
    u32 r5;
    s32 temp;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    r1 = M2C_FIELD(arg0, u32 *, 0x3C);
    r5 = M2C_FIELD(arg0, u32 *, 0x38);
    if (r1 >= (u32)data_0212d744) {
        r1 = data_0212d744;
    }
    if (r1 < r5) {
        r5 = r1;
    }
    temp = RandomIntRange(0, r1 - r5) + 1;
    sp[0] = 0x10;
    sp[1] = 1;
    sp[2] = r5;
    sp[3] = 0;
    sp[4] = temp;
    if (func_ov010_02226538(6, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_020e3b54(void *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    void *func_01ffa444(void *, s32);
    extern s32 data_0212d988;
    extern s32 data_0212da10;
    void *temp_r0;
    u8 *ptr;
    u8 *base;

    temp_r0 = func_01ffa444(&data_0212d988, arg3);
    if (temp_r0 == NULL) {
        return;
    }
    base = (u8 *)arg0;
    M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32)base;
    M2C_FIELD(temp_r0, s32 *, 0x38) = *arg2;
    M2C_FIELD(temp_r0, s32 *, 0x3c) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = (s32)arg2;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;

    for (ptr = base; (u32)ptr < (u32)base + M2C_FIELD(temp_r0, s32 *, 0x38) * 0x310; ptr += 0x310) {
        M2C_FIELD(ptr, s32 *, 0x4) = -1;
        M2C_FIELD(ptr, s32 *, 0x8) = 0;
        M2C_FIELD(ptr, s32 *, 0x30c) = 0;
    }
}

/* Builds the filtered list of entries from the overlay's state, skipping the excluded one. */
void func_020e3bf0(void *list) {
    s32 func_ov010_02226738(void);
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 func_ov010_0222681c(void);
    s32 func_ov010_02226744(void);
    s32 func_ov010_022267b0(s32, s32 *);
    s32 func_02084cf8(void);
    void func_02008048(s32, void *, s32);
    extern s32 data_0212d744;
    s32 entry[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node;

    if (func_ov010_02226738() != 5) {
        func_01ffa8c4(list, 1);
        return;
    }

    data_0212d744 = func_ov010_0222681c();
    total = func_ov010_02226744();
    count = 0;
    node = M2C_FIELD(list, u8 **, 0x34);

    for (i = 0; i < total; i++) {
        if (func_ov010_022267b0(i, entry) != 0 && entry[1] != func_02084cf8()) {
            M2C_FIELD(node, s32 *, 0) = entry[0];
            M2C_FIELD(node, s32 *, 0x4) = entry[1];
            M2C_FIELD(node, s32 *, 0x8) = entry[2];
            M2C_FIELD(node, s32 *, 0xc) = entry[3];
            M2C_FIELD(node, s32 *, 0x30c) = entry[5];

            func_02008048(entry[6], node + 0x10, entry[5]);
            node += 0x310;
            count++;
        }
    }

    *M2C_FIELD(list, s32 **, 0x40) = count;
}

void func_020e3ccc(void *arg0) {
    s32 func_0207c2f0(void);
    s32 RandomIntRange(s32, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK func_01ffa8c4(void *, s32);
    extern s32 data_0212d744;
    s32 sp[68];
    s32 temp5;
    u32 r6;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    r6 = M2C_FIELD(arg0, u32 *, 0x38);
    if ((u32)data_0212d744 < r6) {
        r6 = data_0212d744;
    }
    temp5 = RandomIntRange(0, data_0212d744 - r6) + 1;
    sp[0] = 0x10;
    sp[1] = (func_0207c2f0() & 1) == 0;
    sp[2] = r6;
    sp[3] = 0;
    sp[4] = temp5;
    if (func_ov010_02226538(6, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_020e3d6c(void *arg0, s32 *arg1, s32 arg2) {
    void *func_01ffa444(void *, s32);
    extern s32 data_0212d9c8;
    extern s32 data_0212da10;
    void *temp_r0;
    u8 *ptr;

    temp_r0 = func_01ffa444(&data_0212d9c8, arg2);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32)arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = *arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = (s32)arg1;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;

    for (ptr = (u8 *)arg0; (u32)ptr < (u32)arg0 + M2C_FIELD(temp_r0, s32 *, 0x38) * 0x310; ptr += 0x310) {
        M2C_FIELD(ptr, s32 *, 0x4) = -1;
        M2C_FIELD(ptr, s32 *, 0x8) = 0;
        M2C_FIELD(ptr, s32 *, 0x30c) = 0;
    }
}

void func_020e3e04(void *arg0) {
    s32 func_ov010_02226738(void);
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 func_ov010_02226744(void);
    s32 func_ov010_022267b0(s32, s32 *);
    void func_02008048(s32, void *, s32);
    s32 sp[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node_ptr;

    if (func_ov010_02226738() != 5) {
        func_01ffa8c4(arg0, 1);
        return;
    }

    total = func_ov010_02226744();
    count = 0;
    node_ptr = M2C_FIELD(arg0, u8 **, 0x34);

    for (i = 0; i < total; i++) {
        if (func_ov010_022267b0(i, sp) != 0 && check_val(arg0, sp)) {
            M2C_FIELD(node_ptr, s32 *, 0) = sp[0];
            M2C_FIELD(node_ptr, s32 *, 0x4) = sp[1];
            M2C_FIELD(node_ptr, s32 *, 0x8) = sp[2];
            M2C_FIELD(node_ptr, s32 *, 0xc) = sp[3];
            M2C_FIELD(node_ptr, s32 *, 0x30c) = sp[5];

            func_02008048(sp[6], node_ptr + 0x10, sp[5]);
            node_ptr += 0x310;
            count++;
        }
    }

    *M2C_FIELD(arg0, s32 **, 0x40) = count;
}

void func_020e3f08(void *arg0) {
    void func_02007e70(s32, void *, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 sp[68];
    s32 val;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    val = M2C_FIELD(arg0, s32 *, 0x38) + 1;
    sp[0] = 0x10C;
    sp[2] = val;
    sp[3] = 0;
    sp[1] = 1;
    func_02007e70(M2C_FIELD(arg0, s32 *, 0x44), &sp[4], 0x100);
    if (func_ov010_02226538(3, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void *func_020e3f88(s32 arg0, void *arg1, s32 *arg2, s32 arg3) {
    void *func_01ffa444(void *, s32);
    s32 func_020e34f4(s32);
    void func_02007e70(s32, void *, s32);
    void func_02007e54(s32, s32, s32);
    extern s32 data_0212d838;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 temp_r2;
    register u8 *ptr;

    temp_r0 = func_01ffa444(&data_0212d838, arg3);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = (s32)arg1;
        M2C_FIELD(temp_r0, s32 *, 0x38) = *arg2;
        M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32)arg2;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
        func_02007e70(arg0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        func_02007e54(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
        for (ptr = (u8 *)arg1; (u32)ptr < (u32)arg1 + M2C_FIELD(temp_r0, s32 *, 0x38) * 0x310; ptr += 0x310) {
            M2C_FIELD(ptr, s32 *, 0x4) = -1;
            M2C_FIELD(ptr, s32 *, 0x8) = 0;
            M2C_FIELD(ptr, s32 *, 0x30c) = 0;
        }
    }
    return temp_r0;
}

void func_020e4064(void *arg0) {
 M2C_UNK func_01ffa8c4(void *, s32);
 s32 func_ov010_02226738(void);
 if (func_ov010_02226738() == 5) {
  *M2C_FIELD(arg0, s32 **, 0x40) = 1;
  return;
 }
 func_01ffa8c4(arg0, 1);
}

void func_020e4090(void *arg0) {
    s32 func_ov010_022266c4(M2C_UNK, s32, M2C_UNK, s32, void *);
    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    if (func_ov010_022266c4(8, *M2C_FIELD(arg0, s32 **, 0x44), 0, M2C_FIELD(arg0, s32 *, 0x48), arg0) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void *func_020e40e0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_01ffa444(void *, s32);
    s32 func_020e34f4(s32);
    void func_02007e70(s32, void *, s32);
    void func_02007e54(s32, s32, s32);
    extern s32 data_0212d8a8;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 sp0;
    s32 temp_r2;

    temp_r0 = func_01ffa444(&data_0212d8a8, arg3);
    if (temp_r0 != NULL) {
        sp0 = arg0;
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x38) = 1;
        M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = arg1;
        func_02007e70((s32)&sp0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        func_02007e54(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
    }
    return temp_r0;
}

void *func_020e4174(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_01ffa444(void *, s32);
    s32 func_020e34f4(s32);
    void func_02007e70(s32, void *, s32);
    void func_02007e54(s32, s32, s32);
    extern s32 data_0212d7d8;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 sp0;
    s32 temp_r2;

    temp_r0 = func_01ffa444(&data_0212d7d8, arg3);
    if (temp_r0 != NULL) {
        sp0 = arg0;
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x38) = 1;
        M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = arg1;
        func_02007e70((s32)&sp0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        func_02007e54(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
    }
    return temp_r0;
}

void func_020e4208(void *arg0) {
    s32 func_ov010_02226738(void);
    s32 func_ov010_0222681c(void);
    M2C_UNK func_01ffa8c4(void *, s32);
    extern s32 data_0212d744;

    if (func_ov010_02226738() != 5) {
        func_01ffa8c4(arg0, 1);
        return;
    }
    data_0212d744 = func_ov010_0222681c();
}

void func_020e4240(void *arg0) {
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK func_01ffa8c4(void *, s32);
    extern s32 data_0212d744;
    s32 sp[68];

    if (data_0212d744 >= 0) {
        func_01ffa8c4(arg0, 1);
        return;
    }

    sp[0] = 0xC;
    sp[1] = 1;
    sp[2] = 1;
    sp[3] = 0;

    if (func_ov010_02226538(1, 0, 0xFF, sp, arg0) != 0) {
        return;
    }

    func_01ffa8c4(arg0, 1);
}

void func_020e42bc(s32 arg0) {
    void *func_01ffa444(void *, s32);
    extern s32 data_0212d748;
    extern s32 data_0212da10;
    void *temp_r0;

    temp_r0 = func_01ffa444(&data_0212d748, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
    M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
}

void func_020e4304(void) {
    extern s32 data_0212d744;
    data_0212d744 = -1;
}

void *func_020e4318(void *arg0) {
    void func_020e35cc();
    void func_02082040(void *);
    extern M2C_UNK data_0212da10;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0212da10;
    if (M2C_FIELD(arg0, s32 *, 0x44) != 0) {
        func_020e35cc();
    }
    func_02082040(arg0);
    return arg0;
}

void *func_020e434c(void *arg0) {
    void func_020e35cc();
    extern M2C_UNK data_0212da10;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0212da10;
    if (M2C_FIELD(arg0, s32 *, 0x44) != 0) {
        func_020e35cc();
    }
    return arg0;
}

/* Initialize graphics: clear VRAM, OAM and palettes, then enable the caches. */
void func_020e4378(void) {
    M2C_UNK func_020022d8();
    M2C_UNK func_020022dc();
    M2C_UNK func_02002490();
    M2C_UNK func_02003104(s32);
    M2C_UNK func_020035f8();
    M2C_UNK func_02006858();
    M2C_UNK func_02006c58();
    M2C_UNK func_02006c6c();
    M2C_UNK func_02006c7c();
    M2C_UNK func_02006f14();
    M2C_UNK func_02007140();
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_0200e2f8();
    extern s32 data_020f5204;
    func_02006c58();
    func_02006858();
    func_02006f14();
    func_02007140();
    func_020022d8();
    data_020f5204 = -1;
    func_020022dc();
    func_02002490();
    *(s32 *)0x04001000 &= ~0x10000;
    func_0200e2f8();
    func_02003104(0x1FF);
    func_02007e98(0, 0x06800000, 0xA4000);
    func_020035f8();
    func_02007e98(0xC0, 0x07000000, 0x400);
    func_02007e98(0, 0x05000000, 0x400);
    func_02007e98(0xC0, 0x07000400, 0x400);
    func_02007e98(0, 0x05000400, 0x400);
    M2C_FIELD((void *)0x04000204, u16 *, 0) = (u16) (M2C_FIELD((void *)0x04000204, u16 *, 0) | 0x8000);
    M2C_FIELD((void *)0x04000204, u16 *, 0x100) = (u16) (M2C_FIELD((void *)0x04000204, u16 *, 0x100) & ~0x8000);
    func_02006c6c();
    func_02006c7c();
}

void func_020e4458(void) {
    M2C_UNK func_0200245c(M2C_UNK, u16);
    M2C_UNK func_02004ff8(M2C_UNK, M2C_UNK *);
    M2C_UNK func_020051c8(M2C_UNK);
    extern M2C_UNK func_020e4688;
    u16 temp_r1;

    func_02004ff8(1, &func_020e4688);
    func_020051c8(1);
    temp_r1 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 1;
    func_0200245c(1, temp_r1);
}

