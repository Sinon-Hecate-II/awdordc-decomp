/* 58 functions from 0x02029E98 to 0x0202AE00 (main), found by ds-decomp. */
#include "common.h"
typedef struct HeapRange { u8 *start; u8 *end; } HeapRange;

M2C_UNK func_02029e98(void *arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_02029c30(void *, s32);
    M2C_UNK func_02029c74(M2C_UNK, void *);
    M2C_UNK func_02029e70(void *);
    extern s32 data_02138e90;
    extern u8 data_02138e94[];
    struct Flags { u32 value:8; u32 rest:24; };
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x18) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1C) = arg3;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, struct Flags *, 0x20).value = *(u16 *)&arg4;
    func_02029c30(arg0 + 0xC, 4);
    if (data_02138e90 == 0) {
        func_02029c30(data_02138e94, 4);
        data_02138e90 = 1;
    }
    func_02029c74(func_02029e70(arg0), arg0);
}

M2C_UNK func_02029f14(void *arg0) {
    M2C_UNK func_02029e70(void *);
    M2C_UNK func_02029d7c(M2C_UNK, void *);
    func_02029d7c(func_02029e70(arg0), arg0);
}

void func_02029f2c(void *arg0, void *arg1) {
    s32 temp_r3 = (s32)(arg1 + 0x10);
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg1 - (u16) (((s32) M2C_FIELD(arg1, u16 *, 2) >> 8) & 0x7F));
    M2C_FIELD(arg0, s32 *, 4) = M2C_FIELD(arg1, s32 *, 4) + temp_r3;
}

void *func_02029f58(void *arg0, void *arg1) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 8);
    temp_r1 = M2C_FIELD(arg1, void **, 0xC);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 0xC) = temp_r1;
    } else {
        M2C_FIELD(arg0, void **, 0) = temp_r1;
    }
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, void **, 8) = temp_r2;
    } else {
        M2C_FIELD(arg0, void **, 4) = temp_r2;
    }
    return temp_r2;
}

void *func_02029f80(void *arg0, void *arg1, void *arg2) {
    void *var_r3;

    M2C_FIELD(arg1, void **, 8) = arg2;
    if (arg2 != NULL) {
        var_r3 = M2C_FIELD(arg2, void **, 0xC);
        M2C_FIELD(arg2, void **, 0xC) = arg1;
    } else {
        var_r3 = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(arg0, void **, 0) = arg1;
    }
    M2C_FIELD(arg1, void **, 0xC) = var_r3;
    if (var_r3 != NULL) {
        M2C_FIELD(var_r3, void **, 8) = arg1;
    } else {
        M2C_FIELD(arg0, void **, 4) = arg1;
    }
    return arg1;
}

void *func_02029fb0(void *arg0, s16 arg1) {
    void *p = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(p, s16 *, 0) = arg1;
    M2C_FIELD(p, s16 *, 2) = 0;
    M2C_FIELD(p, s32 *, 4) = M2C_FIELD(arg0, s32 *, 4) - (s32)(p + 16);
    M2C_FIELD(p, s32 *, 8) = 0;
    M2C_FIELD(p, s32 *, 12) = 0;
    return p;
}

void *func_02029fdc(void *arg0, M2C_UNK arg1, s32 arg2) {
    void *func_02029fb0(void *, s16);
    struct Flags { u16 flag:1; u16 rest:15; };
    s32 range[2];
    void *p;
    func_02029e98(arg0, 0x45585048, (s32)(arg0 + 0x38), arg1, arg2);
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, u16 *, 0x36) = 0;
    M2C_FIELD(arg0, struct Flags *, 0x36).flag = 0;
    range[0] = M2C_FIELD(arg0, s32 *, 0x18);
    range[1] = M2C_FIELD(arg0, s32 *, 0x1c);
    p = func_02029fb0(range, 0x4652);
    M2C_FIELD(arg0, void **, 0x24) = p;
    M2C_FIELD(arg0, void **, 0x28) = p;
    M2C_FIELD(arg0, s32 *, 0x2c) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    return arg0;
}

s32 func_0202a050(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void func_02029f2c(void *, void *);
    void *func_02029fb0(void *, s16);
    void *func_02029f58(void *, void *);
    void *func_02029f80(void *, void *, void *);
    M2C_UNK func_02007e54(M2C_UNK, u32, s32);
    s32 sp[7];
    s32 temp_r3;
    s32 temp_r5;
    s32 var_r4;
    void *temp_r0;

    func_02029f2c(sp, arg1);
    temp_r3 = sp[1];
    temp_r5 = arg2 - 0x10;
    sp[1] = temp_r5;
    sp[2] = temp_r3;
    sp[3] = arg3 + arg2;
    var_r4 = func_02029f58(arg0, arg1);
    if ((u32)(sp[1] - sp[0]) < 0x14U) {
        sp[1] = sp[0];
    } else {
        var_r4 = func_02029f80(arg0, func_02029fb0(sp, 0x4652), var_r4);
    }
    if ((u32)(sp[2] - sp[3]) < 0x14U) {
        sp[3] = sp[2];
    } else {
        func_02029f80(arg0, func_02029fb0(&sp[3], 0x4652), var_r4);
    }
    if ((u8)M2C_FIELD(arg0, s32 *, -4) & 1) {
        func_02007e54(0, sp[1], sp[3] - sp[1]);
    }
    sp[4] = temp_r5;
    sp[5] = sp[3];
    temp_r0 = func_02029fb0(&sp[4], 0x5544);
    M2C_FIELD(temp_r0, u16 *, 2) = (u16)(M2C_FIELD(temp_r0, u16 *, 2) & ~0x8000);
    M2C_FIELD(temp_r0, u16 *, 2) = (u16)(M2C_FIELD(temp_r0, u16 *, 2) | (u16)(arg4 << 15));
    M2C_FIELD(temp_r0, u16 *, 2) = (u16)(M2C_FIELD(temp_r0, u16 *, 2) & ~0x7F00);
    M2C_FIELD(temp_r0, u16 *, 2) = (u16)(M2C_FIELD(temp_r0, u16 *, 2) | (u16)(((u32)temp_r0 - sp[1]) << (8+1)));
    M2C_FIELD(temp_r0, u16 *, 2) = (u16)(M2C_FIELD(temp_r0, u16 *, 2) & ~0xFF);
    M2C_FIELD(temp_r0, u16 *, 2) = (u16)(M2C_FIELD(temp_r0, u16 *, 2) | (u8)M2C_FIELD(arg0, u16 *, 0x10));
    func_02029f80((void *)((char *)arg0 + 8), temp_r0, M2C_FIELD(arg0, s32 *, 0xC));
    return arg2;
}

s32 func_0202a1d0(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0202a050(void *, void *, s32, s32, s32);
    s32 base, aligned;
    s32 first;
    u32 size, best;
    void *node;
    void *chosen;
    s32 address;
    node = M2C_FIELD(arg0, void **, 0x24);
    chosen = NULL;
    if ((u16)(M2C_FIELD(arg0, u16 *, 0x36) & 1) == 0) first = 1;
    else first = 0;
    address = 0;
    best = -1U;
    while (node != NULL) {
        base = (s32)(node + 16);
        aligned = ~(arg2 - 1) & (arg2 - 1 + base);
        size = M2C_FIELD(node, u32 *, 4);
        if (size >= (u32)(arg1 + (aligned - base)) && best > size) {
            chosen = node;
            best = size;
            address = aligned;
            if (first || size == arg1) break;
        }
        node = M2C_FIELD(node, void **, 12);
    }
    if (chosen == NULL) return 0;
    return func_0202a050(arg0 + 0x24, chosen, address, arg1, 0);
}

s32 func_0202a284(void *arg0, s32 arg1, s32 arg2) {
 s32 func_0202a050(void *, void *, s32, s32, s32);
 s32 base, aligned;
 s32 first;
 u32 size, best;
 void *node;
 void *chosen;
 s32 address;
 node = M2C_FIELD(arg0, void **, 0x28);
 chosen = NULL;
 if ((u16)(M2C_FIELD(arg0, u16 *, 0x36) & 1) == 0) first = 1;
 else first = 0;
 address = 0;
 best = -1U;
 if (node != NULL) {
loop:

 size = M2C_FIELD(node, u32 *, 4);
 base = (s32)(node + 16);
 aligned = ~(arg2 - 1) & ((size + base) - arg1);
 if ((aligned - base) >= 0 && best > size) {
 chosen = node; best = size; address = aligned;
 if (first || size == arg1) goto done;
 }
 node = M2C_FIELD(node, void **, 8);
 if (node != NULL) goto loop;
 }
done:
 if (chosen == NULL) return 0;
 return func_0202a050(arg0 + 0x24, chosen, address, arg1, 1);
}

s32 func_0202a334(void *arg0, HeapRange *arg1) {
HeapRange range; void *prev; u8 *p; u32 size;
range=*arg1;
prev=0;
for(p=M2C_FIELD(arg0,u8 **,0);p!=0;p=M2C_FIELD(p,u8 **,12)) {
if(p<arg1->start) prev=p;
else {
if(p==arg1->end) {
size=M2C_FIELD(p,u32 *,4);
range.end=(u8 *)(size+(u32)(p+16));
func_02029f58(arg0,p);
}
break;
}
}
if(prev!=0 && (u8 *)(M2C_FIELD(prev,u32 *,4)+(u32)((u8 *)prev+16))==arg1->start){
range.start=prev;prev=func_02029f58(arg0,prev);
}
if((u32)(range.end-range.start)<16) return 0;
func_02029f80(arg0,func_02029fb0(&range,0x4652),prev);
return 1;
}

void *func_0202a424(u32 arg0, u32 arg1, s32 arg2) {
    u32 end = (arg1 + arg0) & ~3;
    u32 start = (arg0 + 3) & ~3;
    if (start > end || end - start < 0x4C) return NULL;
    return func_02029fdc((void *)start, end, arg2);
}

void func_0202a45c(void) {
    M2C_UNK func_02029f14();
    func_02029f14();
}

s32 func_0202a468(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) arg1 = 1;
    arg1 = (arg1 + 3) & ~3;
    if (arg2 >= 0) return func_0202a1d0(arg0, arg1, arg2);
    return func_0202a284(arg0, arg1, -arg2);
}

void func_0202a498(s32 arg0, s32 arg1) {
    void func_02029f2c(void *, void *);
    void *func_02029f58(void *, void *);
    s32 func_0202a334(void *, HeapRange *);
    s32 temp_r4;
    s32 sp0[2];

    temp_r4 = arg1 - 0x10;
    func_02029f2c(sp0, (void *)temp_r4);
    func_02029f58((void *)(arg0 + 0x2C), (void *)temp_r4);
    func_0202a334((void *)(arg0 + 0x24), (HeapRange *)sp0);
}

s32 func_0202a4d4(void *arg0, s32 arg1) {
    u16 temp_r3;
    u16 bit;

    temp_r3 = M2C_FIELD(arg0, u16 *, 0x36);
    bit = (u16)(temp_r3 & 1);
    M2C_FIELD(arg0, u16 *, 0x36) = (u16)(temp_r3 & ~1);
    M2C_FIELD(arg0, u16 *, 0x36) = (u16)(M2C_FIELD(arg0, u16 *, 0x36) | (arg1 & 1));
    return bit;
}

void *func_0202a4fc(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_02029e98();
    func_02029e98(arg0, 0x46524D48, arg0 + 0x30, arg1, arg2);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    return arg0;
}

void *func_0202a544(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02007e54(M2C_UNK, u32, s32);
    u32 f0;
    u32 r5;
    u32 r6;
    u32 diff;

    f0 = M2C_FIELD(arg0, u32 *, 0);
    r5 = (u32)(~(arg2 - 1)) & ((u32)(arg2 - 1) + f0);
    r6 = (u32)arg1 + r5;
    if (r6 > M2C_FIELD(arg0, u32 *, 4)) {
        return (void *)0;
    }
    diff = r6 - f0;
    if (((u8)M2C_FIELD(arg0, s32 *, -4) & 0x1) != 0) {
        func_02007e54(0, f0, (s32)diff);
    }
    M2C_FIELD(arg0, u32 *, 0) = r6;
    return (void *)r5;
}

u32 func_0202a5a0(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02007e54(M2C_UNK, u32, s32);
    u32 temp_r3;
    u32 temp_r5;
    u32 diff;

    temp_r3 = M2C_FIELD(arg0, u32 *, 4);
    temp_r5 = (u32)(~(arg2 - 1)) & (temp_r3 - arg1);
    if (temp_r5 < (u32)M2C_FIELD(arg0, u32 *, 0)) {
        return 0U;
    }
    diff = temp_r3 - temp_r5;
    if ((u8)M2C_FIELD(arg0, s32 *, -4) & 1) {
        func_02007e54(0, temp_r5, diff);
    }
    M2C_FIELD(arg0, u32 *, 4) = temp_r5;
    return temp_r5;
}

void func_0202a5f8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
}

void func_0202a60c(void *arg0) {
    void *var_r2;

    var_r2 = M2C_FIELD(arg0, void **, 0x2C);
    if (var_r2 != NULL) {
        do {
            M2C_FIELD(var_r2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
            var_r2 = M2C_FIELD(var_r2, void **, 0xC);
        } while (var_r2 != NULL);
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
}

void *func_0202a638(u32 arg0, u32 arg1, s32 arg2) {
    void *func_0202a4fc(void *, M2C_UNK, s32);
    u32 end = (arg1 + arg0) & ~3;
    u32 start = (arg0 + 3) & ~3;
    if (start > end || end - start < 0x30) return NULL;
    return func_0202a4fc((void *)start, (M2C_UNK)end, arg2);
}

void func_0202a670(void) {
    M2C_UNK func_02029f14();
    func_02029f14();
}

void func_0202a67c(void *arg0, s32 arg1, s32 arg2) {
    void *func_0202a544(void *, M2C_UNK, M2C_UNK);
    u32 func_0202a5a0(void *, s32, s32);
    if (arg1 == 0) {
        arg1 = 1;
    }
    arg1 = (arg1 + 3) & ~3;
    arg0 = (s8 *)arg0 + 0x24;
    if (arg2 >= 0) {
        func_0202a544(arg0, (M2C_UNK)arg1, (M2C_UNK)arg2);
    } else {
        func_0202a5a0(arg0, arg1, -arg2);
    }
}

void func_0202a6b0(void *arg0, s32 arg1) {
    void func_0202a5f8(void *);
    void func_0202a60c(void *);
    if (arg1 & 1) {
        func_0202a5f8(arg0);
    }
    if (arg1 & 2) {
        func_0202a60c(arg0);
    }
}

s32 func_0202a6dc(void *arg0, M2C_UNK arg1) {
    s32 func_0206409c(M2C_UNK);
    s32 temp_r1_2;
    u32 temp_r0;
    u32 temp_r1;

    temp_r1_2 = func_0206409c(arg1) - 1;
    temp_r1 = M2C_FIELD(arg0, u32 *, 0x28);
    temp_r0 = ~temp_r1_2 & (temp_r1_2 + M2C_FIELD(arg0, s32 *, 0x24));
    if (temp_r0 > temp_r1) {
        return 0;
    }
    return temp_r1 - temp_r0;
}

s32 func_0202a714(void *arg0, s32 arg1) {
    void *func_0202a544(void *, M2C_UNK, M2C_UNK);
    s32 temp_r4;
    void *temp_r0;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x24);
    temp_r0 = func_0202a544(arg0 + 0x24, 0x10, 4);
    if (temp_r0 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_r0, s32 *, 0) = arg1;
    M2C_FIELD(temp_r0, s32 *, 4) = temp_r4;
    M2C_FIELD(temp_r0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(temp_r0, void **, 0xC) = (void *) M2C_FIELD(arg0, void **, 0x2C);
    M2C_FIELD(arg0, void **, 0x2C) = temp_r0;
    return 1;
}

s32 func_0202a764(void *arg0, s32 arg1) {
    void *var_r3;

    var_r3 = M2C_FIELD(arg0, void **, 0x2C);
    if ((arg1 != 0) && (var_r3 != NULL)) {
loop_4:
        if (M2C_FIELD(var_r3, s32 *, 0) != arg1) {
            var_r3 = M2C_FIELD(var_r3, void **, 0xC);
            if (var_r3 != NULL) {
                goto loop_4;
            }
        }
    }
    if (var_r3 == NULL) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(var_r3, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(var_r3, s32 *, 8);
    M2C_FIELD(arg0, void **, 0x2C) = (void *) M2C_FIELD(var_r3, void **, 0xC);
    return 1;
}

s32 func_0202a7b4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) != 0x4352414E) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16 *, 4) != 0xFFFE) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16 *, 6) == 0x100) {
        return 1;
    }
    return 0;
}

s32 func_0202a7f8(void *arg0, M2C_UNK arg1, void *arg2) {
    s32 func_0200b184(void *, M2C_UNK, s32);
    M2C_UNK func_0200b118(void *);
    s32 func_0200b2bc(void *, void *, s32, s32, s32, s32, s32, s32);
    s32 func_02068c34(M2C_UNK);
    s32 temp_r10;
    s32 var_r0;
    void *var_r8;
    void *var_r7;
    void *temp_r4;
    void *var_r1;
    u16 temp_r2;
    void *var_r9;

    var_r7 = NULL;
    var_r8 = NULL;
    var_r9 = NULL;
    if (func_0202a7b4(arg2) == 0) {
        return 0;
    }
    temp_r2 = M2C_FIELD(arg2, u16 *, 0xE);
    var_r0 = 0;
    var_r1 = arg2 + M2C_FIELD(arg2, u16 *, 0xC);
    if ((s32) temp_r2 > 0) {
        do {
            temp_r10 = M2C_FIELD(var_r1, s32 *, 0);
            switch (temp_r10) {                     /* irregular */
            case 0x464E5442:
                var_r8 = var_r1;
                break;
            case 0x46415442:
                var_r7 = var_r1;
                break;
            case 0x46494D47:
                var_r9 = var_r1;
                break;
            }
            var_r0 += 1;
            var_r1 += M2C_FIELD(var_r1, s32 *, 4);
        } while (var_r0 < (s32) temp_r2);
    }
    func_0200b118(arg0);
    M2C_FIELD(arg0, void **, 0x5C) = arg2;
    M2C_FIELD(arg0, void **, 0x60) = var_r7;
    temp_r4 = var_r9 + 8;
    M2C_FIELD(arg0, void **, 0x64) = temp_r4;
    if (func_0200b184(arg0, arg1, func_02068c34(arg1)) == 0) {
        return 0;
    }
    if (func_0200b2bc(arg0, temp_r4, (var_r7 + 0xC) - temp_r4, M2C_FIELD(var_r7, s32 *, 4) - 0xC, (var_r8 + 8) - temp_r4, M2C_FIELD(var_r8, s32 *, 4) - 8, 0, 0) != 0) {
        return 1;
    }
    func_0200b238(arg0);
    return 0;
}

s32 func_0202a940(M2C_UNK arg0) {
    M2C_UNK func_0200b238(M2C_UNK);
    s32 func_0200b32c();
    if (func_0200b32c() == 0) {
        return 0;
    }
    func_0200b238(arg0);
    return 1;
}

void func_0202a968(void) {
    M2C_UNK func_02008fcc(M2C_UNK);
    M2C_UNK func_0200ee10(M2C_UNK);
    M2C_UNK func_0200ee28(M2C_UNK);
    void func_0202ab60(void);
    M2C_UNK func_0202ba8c(void);
    M2C_UNK func_0202ae00(void);
    void func_0202aa20(void);
    void func_0202aa58(void);
    extern M2C_UNK data_02138ea0;
    extern M2C_UNK data_02138eb0;
    extern M2C_UNK data_02138ebc;
    if (M2C_FIELD(&data_02138ea0, s32 *, 0xC) != 0) {
        return;
    }
    M2C_FIELD(&data_02138ea0, s32 *, 0xC) = 1;
    func_02008fcc((M2C_UNK)&data_02138ea0);
    M2C_FIELD(&data_02138ea0, void **, 0x10) = (void *)func_0202aa20;
    M2C_FIELD(&data_02138ea0, s32 *, 0x14) = 0;
    M2C_FIELD(&data_02138ea0, void **, 0x1C) = (void *)func_0202aa58;
    M2C_FIELD(&data_02138ea0, s32 *, 0x20) = 0;
    func_0200ee10((M2C_UNK)&data_02138eb0);
    func_0200ee28((M2C_UNK)&data_02138ebc);
    func_0202ab60();
    func_0202ba8c();
    func_0202ae00();
    M2C_FIELD(&data_02138ea0, s8 *, 0) = -1;
    M2C_FIELD(&data_02138ea0, s32 *, 4) = 1;
}

void func_0202a9f0(void) {
    s32 func_02009100(M2C_UNK);
    M2C_UNK func_020092d0(M2C_UNK);
    M2C_UNK func_0202aeb4();
    M2C_UNK func_0202baa4();
    M2C_UNK func_0202d9e4();
    do {

    } while (func_02009100(0) != 0);
    func_0202aeb4();
    func_0202baa4();
    func_0202d9e4();
    func_020092d0(0);
}

void func_0202aa20(void) {
    M2C_UNK func_02008cf0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0200948c(s32);
    s32 func_020094f8();
    M2C_UNK func_0202bc1c();
    s32 temp_r4;

    func_0202bc1c();
    func_02008cf0(0, 0, 0, 0);
    temp_r4 = func_020094f8();
    func_020092d0(1);
    func_0200948c(temp_r4);
}

void func_0202aa58(void) {
    M2C_UNK func_0202bc7c();
    func_0202bc7c();
}

s32 func_0202aa64(s32 arg0) {
    M2C_UNK func_02008dbc(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213b2a0;
    if (arg0 == 0) {
        return 1;
    }
    if (arg0 & M2C_FIELD(&data_0213b2a0, s32 *, 8)) {
        return 0;
    }
    func_02008dbc(arg0, 0);
    {
        M2C_UNK *p = &data_0213b2a0;
        s32 v = M2C_FIELD(p, s32 *, 8) | arg0;
        M2C_FIELD(p, s32 *, 8) = v;
    }
    return 1;
}

void func_0202aaac(s32 arg0) {
    M2C_UNK func_02008ddc(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213b2a0;
    M2C_UNK *g;
    if (arg0 == 0) {
        return;
    }
    func_02008ddc(arg0, 0);
    g = &data_0213b2a0;
    g[2] = g[2] & ~arg0;
}

void func_0202aadc(s32 arg0) {
    extern s32 data_0213b2a0;
    data_0213b2a0 &= ~arg0;
}

s32 func_0202aaf8(void) {
    extern M2C_UNK data_0213b2a0;
    u32 flags;
    u32 mask;
    s32 i;
    flags = M2C_FIELD(&data_0213b2a0, u32 *, 4);
    mask = 1;
    i = 0;
    if ((flags & mask) != 0) {
        do {
            i = i + 1;
            mask = mask << 1;
            if (i == 8) {
                return -1;
            }
        } while ((flags & mask) != 0);
    }
    M2C_FIELD(&data_0213b2a0, u32 *, 4) = flags | mask;
    return i;
}

void func_0202ab40(s32 arg0) {
    extern M2C_UNK data_0213b2a0;
    M2C_UNK *g = &data_0213b2a0;
    M2C_UNK m = 1;
    g[1] = g[1] & ~(m << arg0);
}

void func_0202ab60(void) {
    extern M2C_UNK data_0213b2a0;
    M2C_FIELD(&data_0213b2a0, u32 *, 8) = 0;
    M2C_FIELD(&data_0213b2a0, u32 *, 0) = 0;
    M2C_FIELD(&data_0213b2a0, u32 *, 4) = 0;
}

void func_0202ab7c(s32 arg0, s8 arg1) {
    extern u8 data_0213b724[];
    data_0213b724[arg0 * 0x24] = (u8)arg1;
}

void func_0202ab94(s32 arg0, s32 arg1) {
    extern u8 data_0213b71c[];
    *(s32 *)(data_0213b71c + arg0 * 0x24) = (s32)(u16)arg1;
}

void func_0202abb4(s32 arg0, s32 arg1) {
    extern u8 data_0213b720[];
    *(s32 *)(data_0213b720 + arg0 * 0x24) = arg1;
}

void func_0202ac60(s32 *arg0) {
    M2C_UNK func_0202b10c(s32);
    func_0202b10c(*arg0);
}

void func_0202ac70(M2C_UNK arg0) {
    extern M2C_UNK data_0213b2c4;
    s32 var_r4;
    u8 *var_r5;

    var_r5 = (u8 *)&data_0213b2c4;
    var_r4 = 0;
    do {
        if (M2C_FIELD(var_r5, u8 *, 0x2C) != 0) {
            func_0202b10c(var_r5, arg0);
        }
        var_r4 += 1;
        var_r5 += 0x44;
    } while (0x10 > var_r4);
}

void func_0202acb0(s32 *arg0) {
    *arg0 = 0;
}

void func_0202acbc(s32 **arg0) {
    if (*arg0 != (s32 *)0) {
        **arg0 = 0;
        *arg0 = (s32 *)0;
    }
}

void func_0202acdc(void **arg0, s8 arg1) {
if (*(void * volatile *)arg0 != NULL) {
M2C_FIELD(*(void * volatile *)arg0,s8 *,0x41)=arg1;
}
}

void func_0202acf0(void **arg0, s8 arg1) {
    if (*(void * volatile *)arg0 != NULL) {
        M2C_FIELD(*(void * volatile *)arg0, s8 *, 0x40) = arg1;
    }
}

#pragma opt_common_subs off
void func_0202ad04(void **arg0, s32 arg1) {
    M2C_UNK func_0202eed8(void *, s32);
    if (*arg0 != 0 && M2C_FIELD(*arg0, u8 *, 0x2C) != 2) {
        func_0202eed8((u8 *)*arg0 + 0x1C, arg1 << 8);
    }
}
#pragma opt_common_subs reset
void func_0202ad30(void **arg0) {
    M2C_UNK func_02008c50(u8);
    void **a = arg0;
    if (*a == 0) {
        return;
    }
    func_02008c50(M2C_FIELD(*a, u8 *, 0x3C));
}

void func_0202ad50(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02008d94(u8, s32, s32);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    func_02008d94(M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x3C), arg1, arg2);
}

void func_0202ad70(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02008c68(u8, s32, s32);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    func_02008c68(M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x3C), arg1, arg2);
}

void func_0202ad90(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02008c84(u8, s32, s32);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    func_02008c84(M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x3C), arg1, arg2);
}

#pragma opt_common_subs off
void func_0202adb0(void **arg0, s16 arg1) {
    void *p = *arg0;
    if (p == NULL) {
        return;
    }
    M2C_FIELD(p, s16 *, 0x34) = 1;
    M2C_FIELD(*arg0, s16 *, 0x38) = arg1;
}
#pragma opt_common_subs reset
void func_0202add4(void **arg0, s16 arg1, s16 arg2) {
    if (*(void * volatile *)arg0 == NULL) {
        return;
    }
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x34) = 2;
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x38) = arg1;
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x3A) = arg2;
}

