/* 46 functions from 0x020852F4 to 0x02086208 (main), found by ds-decomp. */
#include "common.h"
static inline u16 StatusX(void *p) { return M2C_FIELD(p,s16 *,0x34)&511; }
static inline u8 StatusY(void *p) { return M2C_FIELD(p,s16 *,0x36); }
static inline u16 StatusTile(u16 state) {
 extern u16 **gCur3DSpriteEngine;
 return 1023&((s32)(state*4+32)>>((u32)(**gCur3DSpriteEngine<<17)>>30));
}
static inline u8 IsSpriteReady(void *p) { return M2C_FIELD(p,s16 *,0x4e)==0; }
static inline void DrawStatusIcon(s16 x,s16 y,u16 state) {
 extern u16 **gCur3DSpriteEngine; extern M2C_UNK data_027e0064;
 M2C_UNK func_01ff883c(u16,u8,u16,M2C_UNK *);
 func_01ff883c((u16)(x&511),(u8)y,(u16)(1023&((s32)(state*4+32)>>((u32)(**gCur3DSpriteEngine<<17)>>30))),&data_027e0064);
}

void func_020852f4(void){
 void *func_01ffa770(M2C_UNK *); M2C_UNK func_02091cd0(void *); extern M2C_UNK data_02102088;
 void *p=func_01ffa770(&data_02102088);
 if(!p)return;
 M2C_FIELD(p,u8 *,0x40)=1; M2C_FIELD(p,u8 *,0x41)=0;func_02091cd0(p);
}

void func_02085324(void){
 void *func_01ffa770(M2C_UNK *); extern M2C_UNK data_02102088;
 void *p=func_01ffa770(&data_02102088);
 if(p){M2C_FIELD(p,s8 *,0x40)=0;M2C_FIELD(p,s8 *,0x41)=0;}
}

void func_02085348(M2C_UNK arg0,M2C_UNK arg1){
 s32 func_0208492c();
 func_02084bf8((u8)(func_0208492c()+0x81),arg0,arg1);
}

u8 func_02085370(s32 arg0, M2C_UNK arg1) {
    s32 func_02085df8(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02157644;
    u8 var_r0;

    if (func_02085df8((0xC * arg0) + (s32) &data_02157644, arg1, 0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020853a0(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_02008048();
    M2C_UNK func_02085c78(u8, void *, s32);
    u8 buf[32];
    switch (M2C_FIELD(arg1, u8 *, 4) - 0x81) {
    case 0: case 1: case 2: case 3:
        buf[0] = M2C_FIELD(arg1, u8 *, 4);
        buf[1] = 1;
        func_02008048((u8 *)arg1 + 0xC, buf + 2, M2C_FIELD(arg1, s32 *, 8));
        func_02085c78((u8)(buf[0] - 0x81), buf, M2C_FIELD(arg1, s32 *, 8) + 2);
        break;
    }
    return 1;
}

void func_02085414(void) {
    M2C_UNK func_02084fc0(M2C_UNK *);
    s32 func_020853a0(M2C_UNK, void *);
    func_02084fc0((M2C_UNK *)&func_020853a0);
}

void func_02085428(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x50544453, arg0);
}

void func_02085440(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    func_02084bf8(0x85, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
    func_01ffa6fc(arg0);
}

void func_02085464(M2C_UNK arg0) {
    func_02084ea0(0x50524453, arg0);
}

void func_0208547c(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021020bc;
    extern M2C_UNK data_02102188;
    void *temp_r0;

    temp_r0 = func_01ffa444(&data_021020bc, arg2);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102188;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
}

void func_020854b8(M2C_UNK arg0) {
    func_02084ea0(0x50544453, arg0);
}

void func_020854d0(void *arg0) {
    s32 func_0208471c();
    s32 func_02084a6c();
    if ((func_0208471c() != 0) || (func_02084a6c() != 0)) {
        func_01ffa6fc(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_02085514(M2C_UNK arg0) {
    func_02084ea0(0x50524453, arg0);
}

s32 func_0208552c(M2C_UNK arg0, void *arg1) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_02008048();
    extern M2C_UNK data_021020f4;
    s32 (*temp_r2)(M2C_UNK, void *);
    s32 var_r5;
    void *temp_r0;
    temp_r0 = func_01ffa770(&data_021020f4);
    var_r5 = 1;
    if (temp_r0 != NULL) {
        if (M2C_FIELD(arg1, u8 *, 4) == 0x85) {
            func_02008048((u8 *)arg1 + 0xC, M2C_FIELD(temp_r0, void **, 0x3C), M2C_FIELD(temp_r0, s32 *, 0x40));
            M2C_FIELD(temp_r0, u8 *, 0x38) = 1;
        } else {
            temp_r2 = M2C_FIELD(temp_r0, s32 (**)(M2C_UNK, void *), 0x34);
            if (temp_r2 != NULL) var_r5 = temp_r2(arg0, arg1);
        }
    }
    return var_r5;
}

void func_0208559c(s32 a,s32 b,s32 c) {
    void *func_01ffa444(M2C_UNK *,M2C_UNK);
    extern M2C_UNK data_021020f4, data_021021b0;
    void *p=func_01ffa444(&data_021020f4,c);
    if(!p) return;
    M2C_FIELD(p,void **,0)=&data_021021b0;
    M2C_FIELD(p,s32 *,0x34)=func_02084fc0((M2C_UNK *)&func_0208552c);
    M2C_FIELD(p,u8 *,0x38)=0;
    M2C_FIELD(p,s32 *,0x3c)=a;
    M2C_FIELD(p,s32 *,0x40)=b;
}

void func_020855f0(M2C_UNK arg0) {
    func_02084ea0(0x50544353, arg0);
}

u8 func_02085608(void *a) {
    s32 func_020848f8(void);
    s32 func_0208471c(void);
    s32 first, second;
    s32 result;
    first=func_020848f8();
    second=func_020848f8();
    result=first!=(M2C_FIELD(a,u16 *,0x44)&second);
    if(func_0208471c()) result=0;
    return (u8)result;
}

void func_02085644(void *arg0) {
    M2C_UNK func_02084bf8(M2C_UNK, s32, s32);
    func_02084bf8(0x86, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
}

void func_0208565c(M2C_UNK arg0) {
    func_02084ea0(0x50524353, arg0);
}

s32 func_02085674(u32 a,void *b) {
    void *func_01ffa770(M2C_UNK *);
    void func_02084c5c(s32,s32,s32,u16);
    extern M2C_UNK data_0210212c;
    void *p;
    s32 result;
    s32 (*callback)(u32,void *);
    p=func_01ffa770(&data_0210212c);
    result=1;
    if(p) {
        a=(u32)(M2C_FIELD(b,u8 *,5)<<28)>>28;
        switch(M2C_FIELD(b,u8 *,4)) {
        case 0x86:
            func_02008048((u8 *)b+12,M2C_FIELD(M2C_FIELD(p,void **,0x38),void **,a*4),M2C_FIELD(p,s32 *,0x40));
            func_02084c5c(0x87,0,0,(u16)(result<<a));
            break;
        case 0x87:
            M2C_FIELD(p,u16 *,0x44)|=result<<a;
            break;
        default:
            callback=M2C_FIELD(p,s32 (**)(u32,void *),0x34);
            if(callback) result=callback(a,b);
            break;
        }
    }
    return result;
}

void func_02085724(s32 a,s32 b,s32 c,s32 d) {
    void *func_01ffa444(M2C_UNK *,M2C_UNK);
    s32 func_020848c4(void);
    extern M2C_UNK data_0210212c, data_0210219c;
    void *p=func_01ffa444(&data_0210212c,d);
    if(!p) return;
    M2C_FIELD(p,void **,0)=&data_0210219c;
    M2C_FIELD(p,s32 *,0x34)=func_02084fc0((M2C_UNK *)&func_02085674);
    M2C_FIELD(p,s32 *,0x38)=a;
    M2C_FIELD(p,s32 *,0x3c)=b;
    M2C_FIELD(p,s32 *,0x40)=c;
    M2C_FIELD(p,u16 *,0x44)=1<<func_020848c4();
}

void func_02085788(s32 arg0) {
    M2C_UNK func_02065210(M2C_UNK *, u8, s32);
    s32 func_02084644();
    s32 func_020a2370(s32);
    M2C_UNK func_020c4cdc(s32);
    M2C_UNK func_020c4dd0(s32);
    void *func_020c5328();
    s32 func_020c5708(s32);
    M2C_UNK func_020c5770(M2C_UNK, s32 *, s32 *);
    s32 func_ov010_022282b4(M2C_UNK);
    s8 func_ov010_02229a08();
    s32 func_ov010_02229a24();
    void *func_ov010_02229b00();
    void *func_ov010_02229b0c(u8);
    extern s32 data_021020b8;
    extern M2C_UNK data_02157634;
    extern M2C_UNK data_02157638;
    s32 sp8;
    s32 sp4;
    s32 sp0;
    s32 temp_r0_5;
    s32 temp_r10;
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 var_r2;
    s32 var_r2_2;
    s8 temp_r0_2;
    s8 temp_r8;
    u8 var_r7;
    u8 var_r9;
    void *temp_r0;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_6;
    void *temp_r5;

    sp0 = arg0;
    M2C_FIELD(&data_02157634, s8 *, 0) = 0;
    if (func_02084644() != 2) {
        return;
    }
    temp_r0 = func_ov010_02229b00();
    if (M2C_FIELD(temp_r0, s8 *, 0x28) != 0) {
        return;
    }
    if (func_ov010_022282b4(3) == 0) {
        return;
    }
    temp_r10 = func_ov010_02229a24();
    M2C_FIELD(&data_02157634, s8 *, 1) = func_ov010_02229a08();
    temp_r0_2 = M2C_FIELD(temp_r0, s8 *, 0x27);
    switch (temp_r0_2) {                            /* irregular */
    case 0:
        temp_r5 = func_020c4acc();
        var_r7 = 0;
loop_10:
        if ((var_r7 != func_ov010_02229a08()) && (temp_r10 & (1 << var_r7)) && (temp_r0_3 = func_ov010_02229b0c(var_r7), (temp_r0_3 != NULL))) {
            M2C_FIELD(&data_02157634, u8 *, 4) = var_r7;
            temp_r6 = M2C_FIELD(temp_r0, s32 *, 0x20);
            sp8 = temp_r6;
            temp_r4 = M2C_FIELD(temp_r0_3, s32 *, 0x20);
            sp4 = temp_r4;
            M2C_FIELD(&data_02157634, s32 *, 8) = temp_r6;
            M2C_FIELD(&data_02157634, s32 *, 0xC) = temp_r4;
            func_020c5770(1, &sp8, &sp4);
            var_r2 = sp8;
            if (var_r2 > 0x01388000) {
                var_r2 = 0x01388000;
            } else if (var_r2 < -0x01388000) {
                var_r2 = -0x01388000;
            }
            M2C_FIELD(temp_r5, s32 *, 0x50) = (s32) M2C_FIELD(temp_r5, s32 *, 0x54);
            M2C_FIELD(temp_r5, s32 *, 0x54) = var_r2;
            M2C_FIELD(temp_r5, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r5, s32 *, 0x44) + 1);
            M2C_FIELD(&data_02157634, s8 *, 0) = 1;
        } else {
            var_r7 += 1;
            if ((u32) var_r7 >= 4U) {

            } else {
                goto loop_10;
            }
        }
        break;
    case 1:
        var_r2_2 = 4;
        if (4 < 0) {
            var_r2_2 = 0;
        }
        func_02065210(&data_02157638, (u8) (s8) data_021020b8, var_r2_2);
        temp_r8 = func_ov010_02229a08();
        var_r9 = 0;
        do {
            if ((var_r9 != func_ov010_02229a08()) && (temp_r10 & (1 << var_r9))) {
                temp_r6_2 = func_020a2370(temp_r8 + 1);
                if (temp_r6_2 != func_020a2370(var_r9 + 1)) {
                    temp_r0_4 = func_ov010_02229b0c(var_r9);
                    if (temp_r0_4 != NULL) {
                        temp_r0_5 = func_020c5708(M2C_FIELD(temp_r0_4, s32 *, 0x1C));
                        if (temp_r0_5 >= 0) {
                            M2C_FIELD((&data_02157634 + var_r9), s8 *, 4) = (s8) temp_r0_5;
                            temp_r0_6 = func_020c5328();
                            M2C_FIELD(temp_r0_6, u16 *, 0x1A) = (u16) (M2C_FIELD(temp_r0_6, u16 *, 0x1A) + 1);
                            M2C_FIELD(&data_02157634, s8 *, 0) = 1;
                        }
                    }
                }
            }
            var_r9 += 1;
        } while ((u32) var_r9 < 4U);
        break;
    }
    func_020c4cdc(sp0);
    func_020c4dd0(sp0);
}

void func_020859b4(M2C_UNK arg0) {
    s32 func_02084644();
    M2C_UNK func_020c4cdc(M2C_UNK);
    M2C_UNK func_020c4dd0(M2C_UNK);
    void *func_020c5328();
    M2C_UNK func_020c5770(M2C_UNK, s32 *, s32 *);
    u32 func_020cd164(s32, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_02157634;
    s32 sp4;
    s32 sp0;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s8 temp_r1;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u8 temp_r7;
    u8 var_r8;
    void *temp_r0;
    void *temp_r5;
    void *temp_r6;

    if (func_02084644() != 2) {
        return;
    }
    temp_r0 = func_ov010_02229b00();
    if (M2C_FIELD(temp_r0, s8 *, 0x28) != 0) {
        return;
    }
    if (M2C_FIELD(&data_02157634, u8 *, 0) == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(temp_r0, s8 *, 0x27);
    switch (temp_r1) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        temp_r6 = func_020c4acc();
        sp4 = M2C_FIELD(&data_02157634, s32 *, 8);
        sp0 = M2C_FIELD(&data_02157634, s32 *, 0xC);
        temp_r0_2 = func_020cd164(M2C_FIELD(&data_02157634, u8 *, 1) + 1, M2C_FIELD(&data_02157634, u8 *, 4) + 1);
        switch (temp_r0_2) {                        /* switch 2 */
        case 2:                                     /* switch 2 */
            break;
        default:                                    /* switch 2 */
            break;
        case 0:                                     /* switch 2 */
            var_r2 = sp4;
            if (var_r2 > 0x01388000) {
                var_r2 = 0x01388000;
            } else if (var_r2 < -0x01388000) {
                var_r2 = -0x01388000;
            }
            M2C_FIELD(temp_r6, s32 *, 0x50) = (s32) M2C_FIELD(temp_r6, s32 *, 0x54);
            M2C_FIELD(temp_r6, s32 *, 0x54) = var_r2;
            M2C_FIELD(temp_r6, s32 *, 0x44) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x44) - 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = sp4;
            break;
        case 1:                                     /* switch 2 */
            func_020c5770(0, &sp4, &sp0);
            var_r2_2 = sp4;
            if (var_r2_2 > 0x01388000) {
                var_r2_2 = 0x01388000;
            } else if (var_r2_2 < -0x01388000) {
                var_r2_2 = -0x01388000;
            }
            M2C_FIELD(temp_r6, s32 *, 0x50) = (s32) M2C_FIELD(temp_r6, s32 *, 0x54);
            M2C_FIELD(temp_r6, s32 *, 0x54) = var_r2_2;
            M2C_FIELD(temp_r6, s32 *, 0x48) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x48) + 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = sp4;
            break;
        case 3:                                     /* switch 2 */
            func_020c5770(2, &sp4, &sp0);
            var_r2_3 = sp4;
            if (var_r2_3 > 0x01388000) {
                var_r2_3 = 0x01388000;
            } else if (var_r2_3 < -0x01388000) {
                var_r2_3 = -0x01388000;
            }
            M2C_FIELD(temp_r6, s32 *, 0x50) = (s32) M2C_FIELD(temp_r6, s32 *, 0x54);
            M2C_FIELD(temp_r6, s32 *, 0x54) = var_r2_3;
            M2C_FIELD(temp_r6, s32 *, 0x4C) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x4C) + 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = sp4;
            break;
        }
        break;
    case 1:                                         /* switch 1 */
        // add declaration for func_020c4acc? It was not declared but current best includes call
        temp_r7 = M2C_FIELD(&data_02157634, u8 *, 1);
        var_r8 = 0;
        do {
            if ((s32) M2C_FIELD((&data_02157634 + var_r8), s8 *, 4) >= 0) {
                temp_r5 = func_020c5328();
                temp_r0_3 = func_020cd164(temp_r7 + 1, var_r8 + 1);
                switch (temp_r0_3) {                /* switch 3 */
                case 2:                             /* switch 3 */
                    break;
                default:                            /* switch 3 */
                    break;
                case 0:                             /* switch 3 */
                    M2C_FIELD(temp_r5, u16 *, 0x1A) = (u16) (M2C_FIELD(temp_r5, u16 *, 0x1A) - 1);
                    break;
                case 1:                             /* switch 3 */
                    M2C_FIELD(temp_r5, u16 *, 0x1C) = (u16) (M2C_FIELD(temp_r5, u16 *, 0x1C) + 1);
                    break;
                case 3:                             /* switch 3 */
                    M2C_FIELD(temp_r5, u16 *, 0x1E) = (u16) (M2C_FIELD(temp_r5, u16 *, 0x1E) + 1);
                    break;
                }
            }
            var_r8 += 1;
        } while ((u32) var_r8 < 4U);
        break;
    }
    M2C_FIELD(&data_02157634, u8 *, 0) = 0U;
    func_020c4cdc(arg0);
    func_020c4dd0(arg0);
}

void func_02085c04(void) {
    M2C_UNK func_020c47e4(s32);
    func_020c47e4(func_020c4acc() + 0x58);
}

s32 func_02085c18(void) {
    s32 func_020c4acc();
    return func_020c4acc() + 0x58;
}

void func_02085c28(void) {
    func_020c47e4(func_020c4acc() + 0x74);
}

s32 func_02085c3c(void) {
    return func_020c4acc() + 0x74;
}

void func_02085c4c(void) {
    void func_02085e50(void *);
    extern M2C_UNK data_02157644;
    s32 i;
    u8 *p;
    p=(u8 *)&data_02157644;
    i=0;
    do { func_02085e50(p); ++i; p+=12; } while(i<4);
}

s32 func_02085c78(u8 a,void *b,s32 c) {
    s32 func_02085d90(void *,s32,u16,s16);
    extern M2C_UNK data_02157644;
    func_02085d90((u8 *)&data_02157644+12*a,(s32)((u8 *)b+2),(u16)(c-2),0);
}

void func_02085ca8(void) {

}

void *func_02085cac(void *arg0) {
    M2C_UNK func_02082040(void *);
    extern M2C_UNK data_0210219c;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0210219c;
    func_02084fc0(M2C_FIELD(arg0, s32 *, 0x34));
    func_02082040(arg0);
    return arg0;
}

void *func_02085cd8(void *arg0) {
    extern M2C_UNK data_0210219c;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0210219c;
    func_02084fc0(M2C_FIELD(arg0, s32 *, 0x34));
    return arg0;
}

void *func_02085cfc(void *arg0) {
    M2C_UNK func_02082040(void *);
    extern M2C_UNK data_021021b0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021021b0;
    func_02084fc0(M2C_FIELD(arg0, s32 *, 0x34));
    func_02082040(arg0);
    return arg0;
}

void *func_02085d28(void *arg0) {
    extern M2C_UNK data_021021b0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021021b0;
    func_02084fc0(M2C_FIELD(arg0, s32 *, 0x34));
    return arg0;
}

s32 func_02085d4c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_02085d60(void) {

}

s32 func_02085d64(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_02085d78(void) {

}

void func_02085d7c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

s32 func_02085d90(void *arg0, M2C_UNK arg1, u16 arg2, s16 arg3) {
    M2C_UNK func_02008048();
    void *func_020e34bc(M2C_UNK);
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = func_020e34bc(0x28);
    if (temp_r0 == NULL) {
        return 0;
    }
    func_02008048(arg1, temp_r0, arg2);
    M2C_FIELD(temp_r0, s16 *, 0x20) = arg2;
    M2C_FIELD(temp_r0, s16 *, 0x22) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    temp_r0_2 = M2C_FIELD(arg0, void **, 4);
    if (temp_r0_2 == NULL) {
        M2C_FIELD(arg0, void **, 4) = temp_r0;
        M2C_FIELD(arg0, void **, 0) = temp_r0;
    } else {
        M2C_FIELD(temp_r0_2, void **, 0x24) = temp_r0;
        M2C_FIELD(arg0, void **, 4) = temp_r0;
    }
    return 1;
}

s32 func_02085df8(s32 a,s32 b,s32 c) {
    void func_020e35cc(void *);
    s32 len;
    void *p;
    p=M2C_FIELD(a,void **,0);
    if(!p) return 0;
    len=M2C_FIELD(p,u16 *,0x20);
    if(c) M2C_FIELD(c,u16 *,0)=M2C_FIELD(p,u16 *,0x22);
    func_02008048(p,b,len);
    M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,0x24);
    if(!M2C_FIELD(a,void **,0)) M2C_FIELD(a,s32 *,4)=0;
    func_020e35cc(p);
    return len;
}

void func_02085e50(void *a) {
    void func_020e35cc(void *);
    void *p;
    while((p=M2C_FIELD(a,void **,0))!=NULL) {
        M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,0x24);
        func_020e35cc(p);
    }
    M2C_FIELD(a,s32 *,4)=0;
    M2C_FIELD(a,void **,0)=NULL;
}

void func_02085e8c(void *arg0) {
    M2C_UNK func_ov010_02225f60();
    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        return;
    }
    func_ov010_02225f60();
}

void func_02085ea4(void *arg0) {
    M2C_UNK func_ov010_022260b8();
    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        return;
    }
    func_ov010_022260b8();
}

void func_02085ebc(void *arg0) {
 M2C_UNK func_01ff883c(u16,u8,u16,M2C_UNK *);
 s32 func_020847b8(); s32 func_ov002_021e1624(); s32 func_ov010_02225d8c(); s32 func_ov010_02225d9c();
 extern M2C_UNK data_027e0064; extern u16 **data_027e00c8; extern u16 **gCur3DSpriteEngine;
 s32 flag; u16 **saved; u16 v; u16 state=3;
 if(func_020847b8() && M2C_FIELD(arg0,s32 *,0x38) && M2C_FIELD(arg0,s32 *,0x3c)){
 if(IsSpriteReady(arg0)){
 if(func_ov010_02225d8c()){
 v=func_ov010_02225d9c()?2:1; state=v;
 }else state=0;
 }}
 if(M2C_FIELD(arg0,u8 *,0x4c)){
 if(!func_ov002_021e1624())return;
 saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
 {
 s32 x=M2C_FIELD(arg0,s16 *,0x34)&511;
 s32 tile=1023&((s32)(state*4+32)>>((u32)(**gCur3DSpriteEngine<<17)>>30));
 s32 y=M2C_FIELD(arg0,s16 *,0x36);
 func_01ff883c((u16)x,(u8)y,(u16)tile,&data_027e0064);
 }
 gCur3DSpriteEngine=saved; return;
 }
 {
 s32 x=M2C_FIELD(arg0,s16 *,0x34)&511;
 s32 tile=1023&((s32)(state*4+32)>>((u32)(**gCur3DSpriteEngine<<17)>>30));
 s32 y=M2C_FIELD(arg0,s16 *,0x36);
 func_01ff883c((u16)x,(u8)y,(u16)tile,&data_027e0064);
 }
}

void func_02086014(void *arg0) {
    M2C_UNK func_02090640(M2C_UNK, s32);
    M2C_UNK func_0209066c(M2C_UNK, s32);
    s16 func_02090698(M2C_UNK);
    M2C_UNK func_020a8f8c(void *);
    s32 func_020a8ff4(void *);
    s32 func_ov010_02225cf0();
    M2C_UNK func_ov010_02225d50();
    M2C_UNK func_ov010_02225d64();
    M2C_UNK func_ov010_02226054();
    extern void *data_02101e84;
    s16 t;
    u8 flag;
 void *p;
 s16 value;

    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x3C) = 1;
    }
    t = M2C_FIELD(arg0, s16 *, 0x4E);
    if ((s32) t > 0) {
        M2C_FIELD(arg0, s16 *, 0x4E) = (s16) (t - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x4E) == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    func_ov010_02226054();
    if (func_ov010_02225cf0() != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x48) == 0 && M2C_FIELD(arg0, s32 *, 0x40) != func_ov010_02225cf0()) {
            value=func_02090698(2);p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,0xE)=value;
            M2C_FIELD(p, s16 *, 0x10) = 0x20;
            M2C_FIELD(p, s16 *, 0xC) = 8;
            M2C_FIELD(p, u16 *, 2) = (u16) M2C_FIELD(p, u16 *, 4);
            M2C_FIELD(arg0, s32 *, 0x40) = func_ov010_02225cf0();
        }
    } else if (M2C_FIELD(arg0, s32 *, 0x48) == 0 && M2C_FIELD(arg0, s32 *, 0x40) != func_ov010_02225cf0()) {
        value=func_02090698(2);p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,0xE)=value;
        M2C_FIELD(p, s16 *, 0x10) = 0x7F;
        M2C_FIELD(p, s16 *, 0xC) = 8;
        M2C_FIELD(p, u16 *, 2) = (u16) M2C_FIELD(p, u16 *, 4);
        M2C_FIELD(arg0, s32 *, 0x40) = func_ov010_02225cf0();
    }
    if (flag && M2C_FIELD(arg0, s32 *, 0x48) == 0 && (M2C_FIELD(data_02101e84, u16 *, 6) & 0x800)) {
        if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
            value=func_02090698(2);p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,0xE)=value;
            M2C_FIELD(p, s16 *, 0x10) = 0x20;
            M2C_FIELD(p, s16 *, 0xC) = 8;
            M2C_FIELD(p, u16 *, 2) = (u16) M2C_FIELD(p, u16 *, 4);
        }
        func_ov010_02225d50();
        M2C_FIELD(arg0, s32 *, 0x48) = 1;
    } else if (M2C_FIELD(arg0, s32 *, 0x48) != 0 && !(M2C_FIELD(data_02101e84, u16 *, 6) & 0x800)) {
        if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
            value=func_02090698(2);p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,0xE)=value;
            M2C_FIELD(p, s16 *, 0x10) = 0x7F;
            M2C_FIELD(p, s16 *, 0xC) = 8;
            M2C_FIELD(p, u16 *, 2) = (u16) M2C_FIELD(p, u16 *, 4);
        }
        func_ov010_02225d64();
        M2C_FIELD(arg0, s32 *, 0x48) = 0;
    }
    func_020a8f8c(M2C_FIELD(arg0, void **, 0x50));
    func_02090640(2, func_020a8ff4(M2C_FIELD(arg0, void **, 0x50)));
    func_0209066c(2, func_020a8ff4(M2C_FIELD(arg0, void **, 0x50)));
}

