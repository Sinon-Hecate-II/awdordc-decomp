/* 23 functions from 0x021E1500 to 0x021E24E8 (ov002), found by ds-decomp. */
#include "common.h"

void func_ov002_021e1500(void) {
    M2C_UNK func_020026d8(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002c64(M2C_UNK);
    M2C_UNK func_02002e3c(M2C_UNK);
    M2C_UNK func_02082c84();
    func_02082c84();
    func_02002c64(3);
    func_020026d8(0x10);
    func_02002968(0x40);
    func_02002e3c(0x20);
}

void func_ov002_021e152c(void) {
    void func_020822b8(void *);
    void func_ov002_021e7c84(void *);
    void func_ov002_021e6db4(void *);
    void func_ov002_021e3c98(void *);
    extern M2C_UNK data_ov002_021ea680,gPlayerSettings,data_ov002_021f30e4,data_ov002_021f3014;
    extern u8 data_ov002_021f2f40;
    func_ov002_021e1500();
    func_020822b8(&data_ov002_021ea680);
    if(data_ov002_021f2f40) func_ov002_021e7c84(&gPlayerSettings);
    func_ov002_021e6db4(&data_ov002_021f30e4);
    func_ov002_021e3c98(&data_ov002_021f3014);
}

void func_ov002_021e157c(void) {
 M2C_UNK func_ov002_021e6ff0(void *);
 M2C_UNK func_ov002_021e78e4(void *);
 extern M2C_UNK data_ov002_021f30e4;
 func_ov002_021e6ff0(&data_ov002_021f30e4);
 func_ov002_021e78e4(&data_ov002_021f30e4);
}

void func_ov002_021e1598(void) {
    extern M2C_UNK data_ov002_021f30e4;
    M2C_FIELD(&data_ov002_021f30e4, s8 *, 9) = 1;
}

void func_ov002_021e15ac(void) {
    void func_ov002_021e3dd4(void *);
    void func_ov002_021e7970(void *);
    extern M2C_UNK data_ov002_021f3014,data_ov002_021f30e4;
    func_ov002_021e3dd4(&data_ov002_021f3014);
    func_ov002_021e7970(&data_ov002_021f30e4);
    *(volatile u16 *)0x4000304 &= ~0x8000;
}

void func_ov002_021e15e0(void) {
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    extern M2C_UNK data_ov002_021ea68c;
    func_01ffa9bc(&data_ov002_021ea68c);
}

void func_ov002_021e15f4(s32 a) {
    void func_ov002_021e152c(void);
    void func_01ffa42c(void *,s32);
    extern u8 data_ov002_021f2f40;
    extern M2C_UNK data_ov002_021ea68c;
    data_ov002_021f2f40=0;
    func_ov002_021e152c();
    func_01ffa42c(&data_ov002_021ea68c,a);
}

void func_ov002_021e1624(void) {
    M2C_UNK func_ov002_021e3e00(M2C_UNK *);
    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e3e00(&data_ov002_021f3014);
}

s32 func_ov002_021e1638(void *a) {
    M2C_FIELD(a,s32 *,4)=0;
    M2C_FIELD(a,s32 *,16)=0;
    M2C_FIELD(a,s32 *,24)=0;
    M2C_FIELD(a,s32 *,28)=0;
    M2C_FIELD(a,s32 *,32)=0;
    M2C_FIELD(a,s32 *,36)=0;
    M2C_FIELD(a,s32 *,40)=0;
    M2C_FIELD(a,s32 *,44)=0;
    M2C_FIELD(a,s32 *,48)=0;
    M2C_FIELD(a,s32 *,52)=0;
    M2C_FIELD(a,s32 *,20)=0;
    M2C_FIELD(a,u16 *,56)=0;
    M2C_FIELD(a,u8 *,58)=0;
    M2C_FIELD(a,u8 *,59)=0;
    M2C_FIELD(a,u16 *,60)=0;
    M2C_FIELD(a,u16 *,62)=0;
    M2C_FIELD(a,u16 *,64)=0;
    M2C_FIELD(a,u8 *,70)=0;
    M2C_FIELD(a,u16 *,66)=256;
    M2C_FIELD(a,u8 *,68)=0;
    M2C_FIELD(a,u8 *,69)=0;
    M2C_FIELD(a,u8 *,72)=0;
    M2C_FIELD(a,u8 *,73)=0;
    M2C_FIELD(a,u8 *,74)=0;
    M2C_FIELD(a,u8 *,77)=0;
    M2C_FIELD(a,u8 *,78)=31;
    M2C_FIELD(a,u8 *,79)=0;
    M2C_FIELD(a,u8 *,80)=0;
    M2C_FIELD(a,u8 *,81)=0;
}

void func_ov002_021e16bc(void *arg0, s8 arg1, s8 arg2) {
    M2C_UNK func_ov002_021e1638();
    func_ov002_021e1638();
    M2C_FIELD(arg0, s8 *, 0x53) = arg1;
    M2C_FIELD(arg0, s8 *, 0x47) = arg2;
}

void func_ov002_021e16dc(void *a,s32 b,s16 c,s8 d,u8 e) {
    s32 p;
    M2C_FIELD(a,s32 *,4)=b;
    M2C_FIELD(a,s16 *,0x38)=c;
    M2C_FIELD(a,s8 *,0x3a)=d;
    M2C_FIELD(a,s32 *,0x10)=b+M2C_FIELD(M2C_FIELD(a,s32 *,4),s32 *,0);
    p=b+M2C_FIELD(M2C_FIELD(a,s32 *,4)+e*4,s32 *,4);
    M2C_FIELD(a,s32 *,0x18)=p;
    M2C_FIELD(a,s32 *,0x1c)=p;
    M2C_FIELD(a,u8 *,0x46)=e;
    M2C_FIELD(a,s32 *,0x30)=0;
    M2C_FIELD(a,s32 *,0x34)=0;
    M2C_FIELD(a,u8 *,0x4d)=0;
    M2C_FIELD(a,s32 *,0x14)=0;
    M2C_FIELD(a,u8 *,0x4f)=0;
    M2C_FIELD(a,u8 *,0x51)=0;
    M2C_FIELD(a,u8 *,0x52)=0;
}

void func_ov002_021e173c(void *arg0, s8 arg1) {
    s32 temp_ip;
    s32 temp_r3;

    temp_ip = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_ip != 0) && (arg1 != 0xFF)) {
        temp_r3 = temp_ip + M2C_FIELD((temp_ip + (arg1 * 4)), s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x18) = temp_r3;
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_r3;
        M2C_FIELD(arg0, s8 *, 0x46) = arg1;
        M2C_FIELD(arg0, s32 *, 0x30) = 0;
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x4D) = 0;
        M2C_FIELD(arg0, s8 *, 0x4F) = 0;
        M2C_FIELD(arg0, s8 *, 0x51) = 0;
    }
}

void func_ov002_021e1780(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

void func_ov002_021e1790(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = arg2;
}

void func_ov002_021e179c(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x3C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = arg2;
    M2C_FIELD(arg0, s16 *, 0x40) = arg3;
}

void func_ov002_021e17ac(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x42) = arg1;
}

void func_ov002_021e17b4(void *a,s32 b,s8 c) {
    void *node;
    void *p;
    if(M2C_FIELD(a,u8 *,0x48)) {
        if(!M2C_FIELD(a,u8 *,0x49)) M2C_FIELD(a,u8 *,0x49)=2;
    }
    M2C_FIELD(a,u8 *,0x48)=b-M2C_FIELD(a,u8 *,0x49);
    M2C_FIELD(a,s8 *,0x3b)=c;
    node=NULL;
    goto next;
    do {
        p=M2C_FIELD(node,void **,0);
        if(M2C_FIELD(p,u8 *,0x52)) func_ov002_021e17b4(p,b,c);
next:
        if(!node) {
            if(!M2C_FIELD(a,void **,8)) node=NULL;
            else node=(u8 *)a+8;
        } else node=M2C_FIELD(node,void **,4);
    } while(node);
}

void func_ov002_021e1844(void *arg0) {
    if (M2C_FIELD(arg0, void **, 4) == NULL) return;
    M2C_FIELD(arg0, s16 *, 0x3c) += M2C_FIELD(arg0, s8 *, 0x44);
    M2C_FIELD(arg0, s16 *, 0x3e) += M2C_FIELD(arg0, s8 *, 0x45);
}

void func_ov002_021e1c34(void *a,s32 b) {
    s32 x,y,z;
    u16 scale;
    s32 value;
    if(!b) {
        z=M2C_FIELD(a,s16 *,0x40);
        y=M2C_FIELD(a,s16 *,0x3e);
        x=M2C_FIELD(a,s16 *,0x3c);
        *(volatile s32 *)0x4000470=x;
        *(volatile s32 *)0x4000470=y;
        *(volatile s32 *)0x4000470=z;
    } else {
        x=M2C_FIELD(a,s16 *,0x3c);
        z=M2C_FIELD(a,s16 *,0x40);
        y=M2C_FIELD(a,s16 *,0x3e);
        *(volatile s32 *)0x4000470=-x;
        *(volatile s32 *)0x4000470=y;
        *(volatile s32 *)0x4000470=z;
    }
    scale=M2C_FIELD(a,u16 *,0x42);
    if(scale==0x100) return;
    value=(s32)(scale<<12)>>8;
    *(volatile s32 *)0x400046c=value;
    *(volatile s32 *)0x400046c=value;
    *(volatile s32 *)0x400046c=0x1000;
}

M2C_UNK func_ov002_021e1cac(void *obj, s32 flip, s32 orient, void *ptr, void *ptr2, s32 kind, s32 diff, s32 temp) {
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    M2C_UNK func_02004078(s16, s16);
    extern M2C_UNK data_020e5b30;
    s16 var_r4;
    s16 var_r5;
    u16 var_r6;
    u16 var_r8;
    u16 var_r1;
    s32 var_r7;

    if (ptr == NULL) {
        return;
    }
    if ((ptr2 != NULL) && (temp != 0)) {
        switch (kind) {
        default:
        case 23:
            var_r7 = 0;
            break;
        case 24:
            var_r7 = 1;
            break;
        case 25:
            var_r7 = 4;
            break;
        }
        var_r4 = (s16) func_0207ca38(var_r7, M2C_FIELD(ptr, s16 *, 8), M2C_FIELD(ptr, s16 *, 8) + M2C_FIELD(ptr2, s16 *, 8), diff, temp);
        var_r5 = (s16) func_0207ca38(var_r7, M2C_FIELD(ptr, s16 *, 0xA), M2C_FIELD(ptr, s16 *, 0xA) + M2C_FIELD(ptr2, s16 *, 0xA), diff, temp);
        var_r6 = (u16) func_0207ca38(var_r7, (s32) M2C_FIELD(ptr, u16 *, 4), (s32) (M2C_FIELD(ptr, u16 *, 4) * M2C_FIELD(ptr2, u16 *, 4)) >> 8, diff, temp);
        var_r8 = (u16) func_0207ca38(var_r7, (s32) M2C_FIELD(ptr, u16 *, 6), (s32) (M2C_FIELD(ptr, u16 *, 6) * M2C_FIELD(ptr2, u16 *, 6)) >> 8, diff, temp);
        var_r1 = (u16) func_0207ca38(var_r7, (s32) M2C_FIELD(ptr, u16 *, 2), M2C_FIELD(ptr, u16 *, 2) + M2C_FIELD(ptr2, u16 *, 2), diff, temp);
    } else {
        var_r4 = M2C_FIELD(ptr, s16 *, 8);
        var_r5 = M2C_FIELD(ptr, s16 *, 0xA);
        var_r6 = M2C_FIELD(ptr, u16 *, 4);
        var_r8 = M2C_FIELD(ptr, u16 *, 6);
        var_r1 = M2C_FIELD(ptr, u16 *, 2);
    }
    if (flip != 0) {
        var_r4 = -var_r4;
        var_r1 = (u16)(0 - var_r1);
    }
    if (orient != 0) {
        s32 idx = ((s32) (u16) (var_r1 << 8) >> 4) * 2;
        M2C_FIELD((void *) 0x0400046C, s32 *, 0) = (s32) ((s32) (var_r6 << 0xC) >> 8);
        M2C_FIELD((void *) 0x0400046C, s32 *, 0) = (s32) ((s32) (var_r8 << 0xC) >> 8);
        M2C_FIELD((void *) 0x0400046C, s32 *, 0) = 0x1000;
        func_02004078(*(&data_020e5b30 + (idx * 2)), *(&data_020e5b30 + ((idx + 1) * 2)));
        M2C_FIELD((void *) 0x0400046C, s32 *, 4) = (s32) var_r4;
        M2C_FIELD((void *) 0x0400046C, s32 *, 4) = (s32) var_r5;
        M2C_FIELD((void *) 0x0400046C, s32 *, 4) = 0;
    } else {
        *(s32 *) 0x04000470 = (s32) var_r4;
        {
            s32 idx = ((s32) (u16) (var_r1 << 8) >> 4) * 2;
            *(s32 *) 0x04000470 = (s32) var_r5;
            *(s32 *) 0x04000470 = 0;
            M2C_FIELD((void *) 0x0400046C, s32 *, 0) = (s32) ((s32) (var_r6 << 0xC) >> 8);
            M2C_FIELD((void *) 0x0400046C, s32 *, 0) = (s32) ((s32) (var_r8 << 0xC) >> 8);
            M2C_FIELD((void *) 0x0400046C, s32 *, 0) = 0x1000;
            func_02004078(*(&data_020e5b30 + (idx * 2)), *(&data_020e5b30 + ((idx + 1) * 2)));
        }
    }
}

void func_ov002_021e2204(void *arg0) {
    M2C_UNK func_02087064(M2C_UNK, u16, u16, s32, s32);
    M2C_UNK func_02087b94(s16, s16, u32, u16, s32, s32, s32, s32, s32, u32, u32);
    M2C_UNK func_ov002_021e1cac(void *, M2C_UNK, M2C_UNK, void *, void *, M2C_UNK, M2C_UNK, M2C_UNK);
    u8 *p20;
    u8 temp_r5;
    u16 temp_r6_2;
    u16 temp_r7;
    u16 var_r3;
    u32 temp_r8;
    u32 temp_r9;
    u8 temp_r0;
    u8 temp_r6;
    u8 var_r2;
    void *var_r5;

    if (M2C_FIELD(arg0, void **, 0x14) == NULL) {
        return;
    }
    *(s32 *)0x04000444 = 0;
    p20 = M2C_FIELD(arg0, u8 **, 0x20);
    temp_r5 = *p20;
    func_ov002_021e1cac(arg0, 0, 1, (void *) p20, (void *) M2C_FIELD(arg0, s32 *, 0x24), (M2C_UNK) M2C_FIELD(arg0, u8 *, 0x4B), (M2C_UNK) (temp_r5 - M2C_FIELD(arg0, s32 *, 0x30)), (M2C_UNK) temp_r5);
    var_r5 = M2C_FIELD(arg0, void **, 0x14);
    var_r3 = M2C_FIELD(var_r5, u16 *, 4);
    if (var_r3 != 0xFFFF) {
        do {
            temp_r0 = M2C_FIELD(var_r5, u8 *, 6);
            temp_r6 = M2C_FIELD(var_r5, u8 *, 7);
            temp_r6_2 = ((u32) (temp_r0 << 0x1C) >> 0x1C) * 8;
            temp_r7 = ((u32) (temp_r0 << 0x18) >> 0x1C) * 8;
            temp_r8 = (u32) (temp_r6 << 0x1B) >> 0x1F;
            temp_r9 = (u32) (temp_r6 << 0x1A) >> 0x1F;
            if (M2C_FIELD(arg0, u8 *, 0x48) != 0) {
                if (M2C_FIELD(arg0, u8 *, 0x49) == 0) {
                    var_r2 = M2C_FIELD(arg0, u8 *, 0x3B);
                } else {
                    var_r2 = M2C_FIELD(arg0, u8 *, 0x3A);
                }
                func_02087064(3, temp_r6_2, temp_r7, M2C_FIELD(arg0, u16 *, 0x38) + var_r3, M2C_FIELD(arg0, u8 *, 0x51) + (var_r2 + ((u32) (M2C_FIELD(var_r5, u8 *, 7) << 0x1C) >> 0x1C)));
            }
            func_02087b94(M2C_FIELD(var_r5, s16 *, 0), M2C_FIELD(var_r5, s16 *, 2), (u32) (M2C_FIELD(var_r5, u8 *, 7) << 0x18) >> 0x1E, temp_r6_2, (s32) temp_r7, 0, 0, (s32) temp_r6_2, (s32) temp_r7, temp_r8, temp_r9);
            var_r5 = (u8 *) var_r5 + 8;
            var_r3 = M2C_FIELD(var_r5, u16 *, 4);
        } while (var_r3 != 0xFFFF);
    }
    *(s32 *)0x04000448 = 1;
}

void func_ov002_021e2364(void *arg0) {
    M2C_UNK func_02087064(M2C_UNK, u16, u16, s32, s32);
    M2C_UNK func_02087b94(s16, s16, u32, u16, s32, s32, s32, s32, s32, u32, u32);
    M2C_UNK func_ov002_021e1cac(void *, M2C_UNK, M2C_UNK, void *, void *, M2C_UNK, M2C_UNK, M2C_UNK);
    s16 temp_r5_3;
    u16 temp_r6;
    u16 temp_r9;
    u16 var_r3;
    u32 temp_r0;
    u8 temp_r2;
    u8 temp_r5;
    u8 temp_r5_2;
    u8 var_ip;
    u8 var_r1;
    void *var_r4;

    if (M2C_FIELD(arg0, void **, 0x14) == NULL) {
        return;
    }
    *(s32 *)0x04000444 = 0;
    temp_r5 = *M2C_FIELD(arg0, u8 **, 0x20);
    func_ov002_021e1cac(arg0, 1, 1, M2C_FIELD(arg0, void **, 0x20)? NULL:NULL, NULL, 0, 0, 0);
    var_r4 = M2C_FIELD(arg0, void **, 0x14);
    var_r3 = M2C_FIELD(var_r4, u16 *, 4);
    if (var_r3 != 0xFFFF) {
        do {
            temp_r2 = M2C_FIELD(var_r4, u8 *, 6);
            temp_r5_2 = M2C_FIELD(var_r4, u8 *, 7);
            temp_r0 = (u32) (temp_r2 << 0x1C) >> 0x1C;
            temp_r9 = temp_r0 * 8;
            temp_r6 = ((u32) (temp_r2 << 0x18) >> 0x1C) * 8;
            if (((u32) (temp_r5_2 << 0x1B) >> 0x1F) == 0) {
                var_r1 = 1;
            } else {
                var_r1 = 0;
            }
            temp_r5_3 = 0 - (M2C_FIELD(var_r4, s16 *, 0) + (u16) (temp_r0 * 8));
            if (M2C_FIELD(arg0, u8 *, 0x48) != 0) {
                if (M2C_FIELD(arg0, u8 *, 0x49) == 0) {
                    var_ip = M2C_FIELD(arg0, u8 *, 0x3B);
                } else {
                    var_ip = M2C_FIELD(arg0, u8 *, 0x3A);
                }
                func_02087064(3, temp_r9, temp_r6, M2C_FIELD(arg0, u16 *, 0x38) + var_r3, M2C_FIELD(arg0, u8 *, 0x51) + (var_ip + ((u32) (M2C_FIELD(var_r4, u8 *, 7) << 0x1C) >> 0x1C)));
            }
            func_02087b94(temp_r5_3, M2C_FIELD(var_r4, s16 *, 2), (u32) (M2C_FIELD(var_r4, u8 *, 7) << 0x18) >> 0x1E, temp_r9, (s32) temp_r6, 0, 0, (s32) temp_r9, (s32) temp_r6, (s32) var_r1, (u32) (temp_r5_2 << 0x1A) >> 0x1F);
            var_r4 += 8;
            var_r3 = M2C_FIELD(var_r4, u16 *, 4);
        } while (var_r3 != 0xFFFF);
    }
    *(s32 *)0x04000448 = 1;
}

