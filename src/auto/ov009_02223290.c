/* 52 functions from 0x02223290 to 0x02224284 (ov009), found by ds-decomp. */
#include "common.h"

s32 func_ov009_02223290(void) {
    s32 func_02012740(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, s32);
    M2C_UNK func_ov009_02224164(s32);
    M2C_UNK func_ov009_02225480();
    extern M2C_UNK data_ov009_02226a80, data_ov009_02226fe0, func_ov009_02223304;
    s32 state = func_ov009_02224194();
    switch (state) {
    case 4:
    case 5: return 1;
    default:
        func_ov009_02221320(3);
        if (func_02012740(&func_ov009_02223304, &data_ov009_02226a80, &data_ov009_02226fe0, 1, 0) != 2) {
            func_ov009_022227d4();
            return 0;
        }
        func_ov009_02224164(1);
        func_ov009_02225480();
        return 1;
    }
}

void func_ov009_02223304(void *arg0) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_ov009_02222910(M2C_UNK);
    s32 func_ov009_022234d4();
    void func_ov009_02223a30(s32,s32,s32,s32,s32);
    M2C_UNK func_ov009_02224164(M2C_UNK);
    extern M2C_UNK data_ov009_022264b8;
    s32 var_r0;
    u16 temp_r0;
    u16 temp_r0_2;
    void *temp_r0_3;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        temp_r0 = M2C_FIELD(arg0, u16 *, 2);
        switch (temp_r0) {                          /* switch 1; irregular */
        case 12:                                    /* switch 1 */
            func_ov009_02221320(7);
            return;
        case 11:                                    /* switch 1 */
            func_ov009_02221320(7);
            return;
        case 1:                                     /* switch 1 */
            func_ov009_02221320(7);
            return;
        default:                                    /* switch 1 */
            func_ov009_02221320(8);
            return;
        }
    } else {
        temp_r0_2 = M2C_FIELD(arg0, u16 *, 8);
        switch ((s32) temp_r0_2) {                  /* switch 2; irregular */
        case 8:                                     /* switch 2 */
            temp_r0_3 = func_01ffa770(&data_ov009_022264b8);
            if (temp_r0_3 == NULL) {
                var_r0 = 0;
            } else {
                M2C_FIELD(temp_r0_3, s16 *, 0x34) = (s16) (M2C_FIELD(temp_r0_3, s16 *, 0x34) + 1);
                var_r0 = M2C_FIELD(temp_r0_3, s16 *, 0x34);
            }
            if ((s32) var_r0 < 5) {
                return;
            }
            func_ov009_02222910(0x15);
            func_ov009_02224164(0);
            func_ov009_02223a30(M2C_FIELD(arg0, u16 *, 2), 0, 1, 0U, 0);
            func_ov009_02221320(7);
            return;
        case 7:                                     /* switch 2 */
            func_ov009_02221320(4);
            if (func_ov009_022234d4() != 0) {
                return;
            }
            func_ov009_02221320(8);
            return;
        case 9:                                     /* switch 2 */
            func_ov009_02222910(0x15);
            func_ov009_02224164(0);
            func_ov009_02223a30(M2C_FIELD(arg0, u16 *, 2), 0, 1, (u8) M2C_FIELD(arg0, u16 *, 0xA), 0);
            func_ov009_02221320(7);
            return;
        case 26:                                    /* switch 2 */
            func_ov009_02224164(0);
            func_ov009_02223a30(M2C_FIELD(arg0, u16 *, 2), 1, 0, (u8) M2C_FIELD(arg0, u16 *, 0xA), 0);
            return;
        default:                                    /* switch 2 */
            func_ov009_02221320(8);
            /* fallthrough */
        case 6:
            return;
        }
    }
}

s32 func_ov009_022234d4(void) {
void func_ov009_02223ac8(void *); void func_ov009_0222359c(void *);
s32 func_02011a20(s32,void (*)(void *),s32);
s32 func_02012b08(void (*)(void *),M2C_UNK *,u16,M2C_UNK *,u16,s32);
extern M2C_UNK data_ov009_022268e0,data_ov009_022270e0,data_ov009_02227000;
if(func_02011a20(4,func_ov009_02223ac8,0)!=0) {func_ov009_022227d4();return 0;}
if(func_02011a20(12,func_ov009_02223ac8,0)!=0) {func_ov009_022227d4();return 0;}
M2C_FIELD(&data_ov009_022268e0,u8 *,0)=0;
if(func_02012b08(func_ov009_0222359c,&data_ov009_022270e0,(u16)M2C_FIELD(&data_ov009_022268e0,u32 *,0x34),&data_ov009_02227000,(u16)M2C_FIELD(&data_ov009_022268e0,u32 *,0x14),1)==2)return 1;
func_ov009_022227d4();return 0;
}

void func_ov009_0222359c(void *arg0) {
    M2C_UNK func_ov009_02224d9c(s32,s32,s32,s32);
    s8 func_ov009_02225450();
    extern M2C_UNK data_ov009_022268e0;
    u16 state = M2C_FIELD(arg0, u16 *, 2);
    if (state != 0) {
        switch (state) {
        case 9: return;
        case 13: return;
        case 15: return;
        }
        func_ov009_02222748(state);
        func_ov009_02221320(8);
        return;
    }
    switch (M2C_FIELD(arg0, u16 *, 4)) {
    case 10:
        func_ov009_02221320(4);
        func_ov009_02224d9c(5,0,0,1);
        M2C_FIELD(&data_ov009_022268e0, u8 *, 0x156) = M2C_FIELD(&data_ov009_022268e0, u8 *, 0x156) | 1;
        M2C_FIELD(&data_ov009_022268e0, u8 *, 0x157) = func_ov009_02225450();
        func_ov009_02223fbc();
        return;
    case 11: return;
    case 12: return;
    case 13: return;
    default: return;
    }
}

s32 func_ov009_02223640(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_020067e0(M2C_UNK *, s32);
    s32 func_02012c28(M2C_UNK *,s32,s32,s32,s32,s32,s32);
    extern M2C_UNK data_ov009_022268e0, data_ov009_02227000, func_ov009_022236c0;
    s32 result;
    func_020067e0(&data_ov009_02227000, M2C_FIELD(&data_ov009_022268e0,s32 *,0x14));
    result = func_02012c28(&func_ov009_022236c0,arg4,arg2,arg3,arg1,arg0,2);
    if (result != 2) {
        if (result != 7) func_ov009_022227d4();
        return 0;
    }
    return 1;
}

void func_ov009_022236c0(void *arg0) {
    M2C_UNK (*callback)(void *);
    u16 state = M2C_FIELD(arg0, u16 *, 2);
    if (state != 0 && state != 15) {
        func_ov009_02222748(state);
        return;
    }
    callback = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x20);
    if (callback == NULL) return;
    callback(arg0);
}

void func_ov009_022236f4(s32 arg0,u16 arg1,u16 arg2) {
M2C_UNK func_02008048(s32,s32,M2C_UNK);
extern M2C_UNK data_ov009_022268e0;
u8 buffer[12];
func_02008048(arg0,(s32)buffer,12);
if(M2C_FIELD(&data_ov009_022268e0,M2C_UNK (**)(s32,u16,u16),0x60)==NULL)return;
M2C_FIELD(&data_ov009_022268e0,M2C_UNK (**)(s32,u16,u16),0x60)(arg0,arg1,arg2);
}

void func_ov009_02223a24(void) {
    M2C_UNK func_ov009_0222529c();
    func_ov009_0222529c();
}

void func_ov009_02223a30(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
    extern M2C_UNK data_ov009_022268e0, data_ov009_02226b40;
    s8 *entry = (s8 *)&data_ov009_02226b40 + arg3 * 0x60;
    u32 flags;
    u32 mask;
    M2C_UNK (*callback)(s32,s32,s32,s32,s32);
    flags = M2C_FIELD(entry,u8 *,0x16);
    mask = M2C_FIELD(&data_ov009_022268e0,u16 *,8);
    flags &= ~1;
    mask = (1 << arg3) | mask;
    M2C_FIELD(entry,u8 *,0x16) = flags;
    M2C_FIELD(&data_ov009_022268e0,u16 *,8) = mask;
    callback = M2C_FIELD(&data_ov009_022268e0,M2C_UNK (**)(s32,s32,s32,s32,s32),0x1c);
    if (callback == NULL) return;
    callback(arg0,arg1,arg2,arg3,arg4);
}

void func_ov009_02223a90(void *arg0) {
    void func_ov009_022236f4(s32, u16, u16);
    s32 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x14);
    if (temp_r0 == 0) {
        return;
    }
    func_ov009_022236f4(temp_r0, M2C_FIELD(arg0, u16 *, 0x18), M2C_FIELD(arg0, u16 *, 0x10));
}

void func_ov009_02223ac8(void *arg0) {
 M2C_UNK func_ov009_02223744(u16,u8,s32,u16);
 u16 temp_r0;
 if(M2C_FIELD(arg0,u16 *,2)!=0) { func_ov009_02222748(); return; }
 temp_r0=M2C_FIELD(arg0,u16 *,4);
 switch((s32)temp_r0) {
 case 7: return; case 25: case 26: return;
 case 21: func_ov009_02223744(temp_r0,(u8)M2C_FIELD(arg0,u16 *,0x12),M2C_FIELD(arg0,s32 *,0xc),M2C_FIELD(arg0,u16 *,0x10)); return;
 case 9: func_ov009_02223744(temp_r0,(u8)M2C_FIELD(arg0,u16 *,0x12),0,0); return;
 }
}

s32 func_ov009_02223b5c(void) {
    s32 func_02012d64(M2C_UNK *);
    extern M2C_UNK func_ov009_02223b8c;
    func_ov009_02221320(3);
    if (func_02012d64(&func_ov009_02223b8c) == 2) {
        return 1;
    }
    func_ov009_022227d4();
    return 0;
}

void func_ov009_02223b8c(void *arg0) {
    s32 func_ov009_02223bbc();
    M2C_UNK func_ov009_0222525c();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        func_ov009_0222525c();
        return;
    }
    if (func_ov009_02223bbc() != 0) {
        return;
    }
    func_ov009_0222525c();
}

s32 func_ov009_02223bbc(void) {
    s32 func_02012484(void (*)(void *));
    void func_ov009_02223be4(void *);
    if (func_02012484(func_ov009_02223be4) == 2) return 1;
    func_ov009_022227d4();
    return 0;
}

void func_ov009_02223be4(void *arg0) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    M2C_UNK func_ov009_02222748();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        return;
    }
    func_ov009_02221320(1);
}

s32 func_ov009_02223c08(void) {
    s32 func_02012d64(M2C_UNK *);
    extern M2C_UNK func_ov009_02223c38;
    func_ov009_02221320(3);
    if (func_02012d64(&func_ov009_02223c38) == 2) {
        return 1;
    }
    func_ov009_022227d4();
    return 0;
}

void func_ov009_02223c38(void *arg0) {
 s32 func_ov009_02223c60(void); M2C_UNK func_ov009_0222529c();
 if(M2C_FIELD(arg0,u16 *,2)!=0) {func_ov009_02222748();func_ov009_0222529c();return;}
 if(func_ov009_02223c60()!=0) return;
}

s32 func_ov009_02223c60(void) {
    s32 func_0201280c(void (*)(void *), s32);
    void func_ov009_02223c98(void *);
    M2C_UNK func_ov009_0222525c();
    func_ov009_02221320(3);
    if (func_0201280c(func_ov009_02223c98, 0) == 2) return 1;
    func_ov009_022227d4();
    func_ov009_0222525c();
    return 0;
}

void func_ov009_02223c98(void *arg0) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    M2C_UNK func_ov009_02222748();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        return;
    }
    func_ov009_02221320(1);
}

void func_ov009_02223cbc(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02221320(9);
        return;
    }
    func_ov009_02221320(0);
}

s32 func_ov009_02223ce4(void) {
    s32 func_02012274(M2C_UNK *);
    extern M2C_UNK func_ov009_02223d14;
    func_ov009_02221320(3);
    if (func_02012274(&func_ov009_02223d14) == 2) {
        return 1;
    }
    func_ov009_022227d4();
    return 0;
}

void func_ov009_02223d14(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        func_ov009_02221320(8);
        return;
    }
    func_ov009_02221320(1);
}

#pragma opt_common_subs off
s32 func_ov009_02223d40(s32 a) { extern M2C_UNK data_ov009_022268e0,func_ov009_02223da0; s32 func_02013e24(M2C_UNK *,s32); s32 result; u8 flags; if(a) {flags=M2C_FIELD(&data_ov009_022268e0,u8 *,0x156);flags|=2; M2C_FIELD(&data_ov009_022268e0,u8 *,0x156)=flags;} else {flags=M2C_FIELD(&data_ov009_022268e0,u8 *,0x156);flags&=~2; M2C_FIELD(&data_ov009_022268e0,u8 *,0x156)=flags;} result=func_02013e24(&func_ov009_02223da0,M2C_FIELD(&data_ov009_022268e0,u8 *,0x156)&2); switch(result){case 2:case 3:break;default:func_ov009_022227d4();return 0;}return 1;}
#pragma opt_common_subs reset
void func_ov009_02223da0(void *arg0) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    M2C_UNK func_ov009_02222748();
    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        return;
    }
    func_ov009_02222748();
    func_ov009_02221320(8);
}

s32 func_ov009_02223dc0(void) {
 extern M2C_UNK data_ov009_022268e0,data_ov009_022269e0,func_ov009_02223e38;
 s32 func_02013c44(M2C_UNK *,s32,u16,s32,u16,u8);
 s32 result;
 result=func_02013c44(&func_ov009_02223e38,M2C_FIELD(&data_ov009_022268e0,s32 *,0x100),M2C_FIELD(&data_ov009_022269e0,u16 *,4),M2C_FIELD(&data_ov009_022268e0,s32 *,0x108),M2C_FIELD(&data_ov009_022269e0,u16 *,12),(u8)((M2C_FIELD(&data_ov009_022268e0,u8 *,0x156)&2)!=0));
 switch(result) {case 2: case 3: break; default: func_ov009_022227d4();return 0;} return 1;
}

void func_ov009_02223e38(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 2);
    if ((temp_r0 != 0) && (temp_r0 != 1)) {
        func_ov009_02222748();
        func_ov009_02221320(8);
    }
}

s32 func_ov009_02223e5c(void) {
 extern M2C_UNK data_ov009_022268e0,func_ov009_02223ea8;
 s32 func_02012be4(M2C_UNK *,s32);
 u8 old=M2C_FIELD(&data_ov009_022268e0,u8 *,0);
 M2C_FIELD(&data_ov009_022268e0,u8 *,0)=old+1;
 if(old!=0) return 1;
 if(func_02012be4(&func_ov009_02223ea8,0)==2) return 1;
 func_ov009_022227d4();return 0;
}

void func_ov009_02223ea8(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        return;
    }
    func_ov009_02222748();
    func_ov009_02221320(8);
}

s32 func_ov009_02223ec8(void) {
 extern M2C_UNK data_ov009_022268e0,func_ov009_02223f14;
 s32 func_02012be4(M2C_UNK *,s32);
 u8 value=M2C_FIELD(&data_ov009_022268e0,u8 *,0)-1;
 M2C_FIELD(&data_ov009_022268e0,u8 *,0)=value;
 if(M2C_FIELD(&data_ov009_022268e0,u8 *,0)!=0) return 1;
 if(func_02012be4(&func_ov009_02223f14,1)==2) return 1;
 func_ov009_022227d4();return 0;
}

void func_ov009_02223f14(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        return;
    }
    func_ov009_02222748();
    func_ov009_02221320(8);
}

void func_ov009_02223f34(s32 a) { extern M2C_UNK data_ov009_022268e0; M2C_FIELD(&data_ov009_022268e0,s32 *,0x108)=a; }

void func_ov009_02223f44(s32 src,u32 size){
 M2C_UNK func_02008048(s32,s32,M2C_UNK);
 M2C_UNK func_02007f8c(void*,M2C_UNK,s32);
 extern M2C_UNK data_ov009_02226fe0;
 if(size>24)size=24;
 func_02008048(src,(s32)&data_ov009_02226fe0,size);
 func_02007f8c((u8*)&data_ov009_02226fe0+size,0,24-size);
}

void func_ov009_02223f7c(s32 a,s32 b){
 void func_ov009_0222140c(void*,s32,s32);
 extern M2C_UNK data_ov009_02226a20,data_ov009_022268e0,data_ov009_022269e0;
 func_ov009_0222140c(&data_ov009_02226a20,a,b);
 M2C_FIELD(&data_ov009_022268e0,void**,0x100)=&data_ov009_02226a20;
 M2C_FIELD(&data_ov009_022269e0,u16*,4)=0x60;
}

s32 func_ov009_02223fbc(void){
 s32 func_ov009_022254a4(void);
 s32 func_ov009_02224c70(void);
 s32 func_ov009_02224194(void);
 s8 func_ov009_02225450(void);
 void func_ov009_02222278(s32,void*);
 M2C_UNK func_ov009_02224d9c(s32,s32,s32,s32);
 extern M2C_UNK data_ov009_02226a20;
 if(func_ov009_022254a4()){if(!func_ov009_02224c70())return 0;}
 if(func_ov009_02224194()==4 || func_ov009_02224194()==5){
 func_ov009_02222278(func_ov009_02225450(),&data_ov009_02226a20);
 func_ov009_02224d9c(11,(s32)&data_ov009_02226a20,0x60,0xffff);
 }return 1;
}

void func_ov009_02224024(void) {
    s32 func_ov009_02224194();
    M2C_UNK func_ov009_02224d9c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_ov009_022254d8();
    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return;
    }
    if (func_ov009_022254d8() == 0) {
        return;
    }
    func_ov009_02224d9c(5, 0, 0, 1);
}

M2C_UNK *func_ov009_02224064(void) {
    extern M2C_UNK data_ov009_02226a20;
    return &data_ov009_02226a20;
}

s32 func_ov009_02224070(s32 a){
 u16 func_ov009_02224174(void);
 extern M2C_UNK data_ov009_02226b40;
 s32 p;
 if(!(func_ov009_02224174()&(1<<a)))return 0;
 p=(s32)&data_ov009_02226b40+a*0x60;
 if(!(M2C_FIELD(p,u8*,0x16)&1))p=0;
 return p;
}

s32 func_ov009_022240ac(s32 arg0) {
    extern M2C_UNK data_ov009_02226b40;
    return (0x60 * arg0) + (s32) &data_ov009_02226b40;
}

s32 func_ov009_022240c0(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02008048(s32, s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_ov009_02224064();
    if (temp_r0 == 0) {
        return 0;
    }
    func_02008048(temp_r0 + 0x20, arg0, arg1);
    return arg0;
}

s32 func_ov009_022240f4(void) {
    s32 func_ov009_02224070();
    s32 temp_r0;

    temp_r0 = func_ov009_02224070();
    if (temp_r0 != 0) {
        return temp_r0 + 0x20;
    }
    return 0;
}

s32 func_ov009_0222410c(s32 a,s32 b,s32 c){
 s32 p=func_ov009_02224070(a);
 if(!p)return 0;
 func_02008048(p+0x20,b,c);
 return b;
}

s32 func_ov009_02224140(s32 a){
 extern M2C_UNK data_ov009_022268e0;
 s32 old=M2C_FIELD(&data_ov009_022268e0,s32*,0x3c);
 M2C_FIELD(&data_ov009_022268e0,s32*,0x3c)=a;
 return old;
}

void func_ov009_02224158(void) {
    M2C_UNK func_02011d78();
    func_02011d78();
}

M2C_UNK func_ov009_02224164(s32 a) {extern u16 data_ov009_022263e0; data_ov009_022263e0=a;}

u16 func_ov009_02224174(void) {
    extern u16 data_ov009_022263e0;
    return data_ov009_022263e0;
}

void func_ov009_02224184(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x10) = arg0;
}

s32 func_ov009_02224194(void) {
    extern M2C_UNK data_ov009_022268e0;
    return M2C_FIELD(&data_ov009_022268e0, s32 *, 0x10);
}

s32 func_ov009_022241a4(void){extern M2C_UNK data_ov009_022268e0;return M2C_FIELD(&data_ov009_022268e0,s32*,0x38);}

s32 func_ov009_022241b4(void){extern M2C_UNK data_ov009_022268e0;return M2C_FIELD(&data_ov009_022268e0,s32*,12);}

s32 func_ov009_022241c4(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    s32 old = M2C_FIELD(&data_ov009_022268e0, s32 *, 0x2c);
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x2c) = arg0;
    return old;
}

s32 func_ov009_022241dc(void) {
 void func_02007724(void *); void func_ov009_02222430(u32); s32 func_ov009_0222287c(s32);
 extern M2C_UNK data_ov009_022268e0;
 u16 mac[3]; s32 res;
 func_02007724(mac);
 func_ov009_02222430(*(u32 *)0x027FFC3C+mac[0]+mac[1]+mac[2]);
 M2C_FIELD(&data_ov009_022268e0,u16 *,2)=0;
 M2C_FIELD(&data_ov009_022268e0,u16 *,10)=101;
 func_ov009_02221320(3);
 res=func_ov009_0222287c(1);
 if(res==25) {func_ov009_022227d4();func_ov009_02221320(8);return 0;}
 if(res==2) return 1;
 func_ov009_022227d4();func_ov009_02221320(8);return 0;
}

