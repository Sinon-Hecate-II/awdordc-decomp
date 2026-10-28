/* 53 functions from 0x0200402C to 0x02004FF8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 a,b,c,d,e,f,g,h; } FuncCopy8;

typedef struct { u32 x, y, z; } FuncCopyV3;

void func_0200402c(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2,s32 arg3,M2C_UNK *arg4) {
 M2C_UNK func_0200141c(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK *);
 M2C_UNK func_02003a70(M2C_UNK *);
 M2C_UNK sp0[12]; M2C_UNK *p=arg4;
 if(p==NULL)p=sp0;
 func_0200141c(arg0,arg1,arg2,p);
 if(arg3==0)return;
 *(volatile s32 *)0x04000440=2;
 func_02003a70(p);
}

void func_02004078(s32 arg0,s32 arg1) {
 *(volatile s32 *)0x04000468=arg1;
 *(volatile s32 *)0x04000468=arg0;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=-arg0;
 *(volatile s32 *)0x04000468=arg1;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=0;
 *(volatile s32 *)0x04000468=0x1000;
}

void func_020040b4(M2C_UNK arg0,s32 arg1,u32 arg2) {
 M2C_UNK func_02007a74(s32,M2C_UNK,s32,u32);
 M2C_UNK func_02007e20(M2C_UNK,s32,u32);
 extern s32 data_020f5204;
 if(data_020f5204!=-1&&arg2>0x1CU){func_02007a74(data_020f5204,arg0,arg1+0x05000000,arg2);return;}
 func_02007e20(arg0,arg1+0x05000000,arg2);
}

void func_02004108(M2C_UNK arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1 && arg2 > 0x1CU) {
        func_02007a74(data_020f5204, arg0, arg1 + 0x05000400, arg2);
        return;
    }
    func_02007e20(arg0, arg1 + 0x05000400, arg2);
}

void func_02004160(M2C_UNK arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1 && arg2 > 0x1CU) {
        func_02007a74(data_020f5204, arg0, arg1 + 0x05000200, arg2);
        return;
    }
    func_02007e20(arg0, arg1 + 0x05000200, arg2);
}

void func_020041b8(M2C_UNK arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1 && arg2 > 0x1CU) {
        func_02007a74(data_020f5204, arg0, arg1 + 0x05000600, arg2);
        return;
    }
    func_02007e20(arg0, arg1 + 0x05000600, arg2);
}

void func_02004210(M2C_UNK arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02007a04(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1 && arg2 > 0x30U) {
        func_02007a04(data_020f5204, arg0, arg1 + 0x07000000, arg2);
        return;
    }
    func_02007e70(arg0, arg1 + 0x07000000, arg2);
}

void func_02004264(M2C_UNK arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02007a04(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1 && arg2 > 0x30U) {
        func_02007a04(data_020f5204, arg0, arg1 + 0x07000400, arg2);
        return;
    }
    func_02007e70(arg0, arg1 + 0x07000400, arg2);
}

void func_020042bc(M2C_UNK arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02007a04(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    s32 off = (s32)0x06400000;
    if (data_020f5204 != -1 && arg2 > 0x30U) {
        func_02007a04(data_020f5204, arg0, arg1 + off, arg2);
        return;
    }
    func_02007e70(arg0, arg1 + off, arg2);
}

void func_0200436c(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 func_020036b8();
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    s32 temp_ip;

    temp_ip = func_020036b8();
    if ((data_020f5204 != -1) && (arg2 > 0x1CU)) {
        func_02007a74(data_020f5204, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_02007e20(arg0, temp_ip + arg1, arg2);
}

void func_020043cc(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 func_020036d8();
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    s32 temp_ip;

    temp_ip = func_020036d8();
    if ((data_020f5204 != -1) && (arg2 > 0x1CU)) {
        func_02007a74(data_020f5204, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_02007e20(arg0, temp_ip + arg1, arg2);
}

void func_0200442c(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 func_0200370c();
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    s32 temp_ip;

    temp_ip = func_0200370c();
    if ((data_020f5204 != -1) && (arg2 > 0x1CU)) {
        func_02007a74(data_020f5204, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_02007e20(arg0, temp_ip + arg1, arg2);
}

void func_0200448c(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 func_0200372c();
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    s32 temp_ip;

    temp_ip = func_0200372c();
    if ((data_020f5204 != -1) && (arg2 > 0x1CU)) {
        func_02007a74(data_020f5204, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_02007e20(arg0, temp_ip + arg1, arg2);
}

void func_020044ec(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 func_020037b0();
    M2C_UNK func_02007a74(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e20(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    s32 temp_ip;

    temp_ip = func_020037b0();
    if ((data_020f5204 != -1) && (arg2 > 0x1CU)) {
        func_02007a74(data_020f5204, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_02007e20(arg0, temp_ip + arg1, arg2);
}

void func_0200454c(M2C_UNK arg0,s32 arg1,u32 arg2) {
 s32 func_02003834(); M2C_UNK func_02007a04(s32,M2C_UNK,s32,u32); M2C_UNK func_02007e70(M2C_UNK,s32,u32);
 extern s32 data_020f5204; s32 temp_ip;
 temp_ip=func_02003834();
 if(data_020f5204!=-1 && arg2>0x30U){func_02007a04(data_020f5204,arg0,temp_ip+arg1,arg2);return;}
 func_02007e70(arg0,temp_ip+arg1,arg2);
}

void func_020045ac(M2C_UNK arg0,s32 arg1,u32 arg2) {
 s32 func_02003868(); M2C_UNK func_02007a04(s32,M2C_UNK,s32,u32); M2C_UNK func_02007e70(M2C_UNK,s32,u32);
 extern s32 data_020f5204; s32 temp_ip;
 temp_ip=func_02003868();
 if(data_020f5204!=-1 && arg2>0x30U){func_02007a04(data_020f5204,arg0,temp_ip+arg1,arg2);return;}
 func_02007e70(arg0,temp_ip+arg1,arg2);
}

void func_0200460c(M2C_UNK arg0,s32 arg1,u32 arg2) {
 s32 func_02003888(); M2C_UNK func_02007a04(s32,M2C_UNK,s32,u32); M2C_UNK func_02007e70(M2C_UNK,s32,u32);
 extern s32 data_020f5204; s32 temp_ip;
 temp_ip=func_02003888();
 if(data_020f5204!=-1 && arg2>0x30U){func_02007a04(data_020f5204,arg0,temp_ip+arg1,arg2);return;}
 func_02007e70(arg0,temp_ip+arg1,arg2);
}

void func_0200466c(M2C_UNK arg0,s32 arg1,u32 arg2) {
 s32 func_020038bc(); M2C_UNK func_02007a04(s32,M2C_UNK,s32,u32); M2C_UNK func_02007e70(M2C_UNK,s32,u32);
 extern s32 data_020f5204; s32 temp_ip;
 temp_ip=func_020038bc();
 if(data_020f5204!=-1 && arg2>0x30U){func_02007a04(data_020f5204,arg0,temp_ip+arg1,arg2);return;}
 func_02007e70(arg0,temp_ip+arg1,arg2);
}

void func_020046cc(M2C_UNK arg0,s32 arg1,u32 arg2) {
 s32 func_020038dc(); M2C_UNK func_02007a04(s32,M2C_UNK,s32,u32); M2C_UNK func_02007e70(M2C_UNK,s32,u32);
 extern s32 data_020f5204; s32 temp_ip;
 temp_ip=func_020038dc();
 if(data_020f5204!=-1 && arg2>0x30U){func_02007a04(data_020f5204,arg0,temp_ip+arg1,arg2);return;}
 func_02007e70(arg0,temp_ip+arg1,arg2);
}

void func_0200472c(M2C_UNK arg0,s32 arg1,u32 arg2) {
 s32 func_0200392c(); M2C_UNK func_02007a04(s32,M2C_UNK,s32,u32); M2C_UNK func_02007e70(M2C_UNK,s32,u32);
 extern s32 data_020f5204; s32 temp_ip;
 temp_ip=func_0200392c();
 if(data_020f5204!=-1 && arg2>0x30U){func_02007a04(data_020f5204,arg0,temp_ip+arg1,arg2);return;}
 func_02007e70(arg0,temp_ip+arg1,arg2);
}

void func_0200489c(void) {
    M2C_UNK func_02007c3c(s32);
    M2C_UNK func_02002ab8(M2C_UNK);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbe0;
    if (data_020f5204 != -1) {
        func_02007c3c(data_020f5204);
    }
    func_02002ab8(M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x14));
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x14) = 0;
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x10) = 0;
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0xc) = 0;
}

void func_020048e4(void) {
    s32 func_02003394();
    extern M2C_UNK data_0212dbe0;
    s32 v = func_02003394();
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x8) = (M2C_UNK)v;
    if (v == 0) {
        return;
    }
    if (v == 0x20) {
        goto store_6890;
    }
    if (v == 0x40) {
        M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x4) = (M2C_UNK)0x6894000;
        return;
    }
    return;
store_6890:
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x4) = (M2C_UNK)0x6890000;
    return;
}

void func_0200492c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02007ba4(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbe0;
    if (data_020f5204 != -1) {
        func_02007ba4(data_020f5204, arg0, M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x4) + (s32)arg1, arg2, 0, 0);
        return;
    }
    func_02007e70(arg0, M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x4) + (s32)arg1, (u32)arg2);
}

void func_02004998(void) {
    M2C_UNK func_02007c3c(s32);
    M2C_UNK func_02002bb8(M2C_UNK);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbe0;
    if (data_020f5204 != -1) {
        func_02007c3c(data_020f5204);
    }
    func_02002bb8(M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x8));
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x8) = 0;
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x4) = 0;
}

void func_020049dc(void) {
    s32 func_02003408();
    extern s32 data_0212dbe0;
    data_0212dbe0 = func_02003408();
}

void func_020049f4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02007ba4(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1) {
        func_02007ba4(data_020f5204, arg0, (s32)arg1 + 0x6898000, arg2, 0, 0);
        return;
    }
    func_02007e70(arg0, (s32)arg1 + 0x6898000, (u32)arg2);
}

void func_02004a58(void) {
    M2C_UNK func_02007c3c(s32);
    M2C_UNK func_0200323c(M2C_UNK);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbe0;
    if (data_020f5204 != -1) {
        func_02007c3c(data_020f5204);
    }
    func_0200323c(data_0212dbe0);
    data_0212dbe0 = 0;
}

void func_02004a98(void) {
    s32 func_02003430();
    extern M2C_UNK data_0212dbe0;
    M2C_FIELD(&data_0212dbe0, s32 *, 0x18) = func_02003430();
}

void func_02004ab0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02007ba4(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    if (data_020f5204 != -1) {
        func_02007ba4(data_020f5204, arg0, (s32)arg1 + 0x68a0000, arg2, 0, 0);
        return;
    }
    func_02007e70(arg0, (s32)arg1 + 0x68a0000, (u32)arg2);
}

void func_02004b14(void) {
    M2C_UNK func_02007c3c(s32);
    M2C_UNK func_020032bc(M2C_UNK);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbe0;
    if (data_020f5204 != -1) {
        func_02007c3c(data_020f5204);
    }
    func_020032bc(M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x18));
    M2C_FIELD(&data_0212dbe0, M2C_UNK *, 0x18) = 0;
}

void func_02004b54(void) {
    s32 func_020033b8(void);
    extern u8 data_020e9b40[];
    extern u8 data_020e9b42[];
    extern u8 data_020e9b44[];
    extern M2C_UNK data_0212dbfc;
    s32 six = 6;
    s32 idx;
    s32 off;
    u16 a;
    u16 b;
    u16 c;

    idx = func_020033b8();
    off = idx * six;
    a = *(u16 *)(data_020e9b40 + off);
    b = *(u16 *)(data_020e9b42 + off);
    c = *(u16 *)(data_020e9b44 + off);
    M2C_FIELD(&data_0212dbfc, s32 *, 0x14) = idx;
    M2C_FIELD(&data_0212dbfc, s32 *, 0x4) = (s32)(a << 12);
    M2C_FIELD(&data_0212dbfc, s32 *, 0x18) = (s32)(b << 12);
    M2C_FIELD(&data_0212dbfc, s32 *, 0x1C) = (s32)(c << 12);
}

void func_02004bb0(M2C_UNK arg0, u32 arg1, u32 arg2) {
    M2C_UNK func_02007a04(s32, M2C_UNK, s32, u32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    M2C_UNK func_02007ba4(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbfc;

    M2C_UNK *p = &data_0212dbfc;
    s32 field18 = M2C_FIELD(p, s32 *, 0x18);
    u32 r12 = arg1;
    u32 r6 = arg2;
    M2C_UNK r7 = arg0;
    s32 offset;
    s32 field1c;

    if (field18 == 0) {
        offset = M2C_FIELD(p, s32 *, 0x4) + (s32)r12;
    } else {
        field1c = M2C_FIELD(p, s32 *, 0x1c);
        if (r12 + r6 < (u32)field1c) {
            offset = M2C_FIELD(p, s32 *, 0x4) + (s32)r12;
        } else if (r12 >= (u32)field1c) {
            offset = field18 + (s32)r12 - field1c;
        } else {
            u32 r5 = (u32)field1c - r12;
            s32 base = M2C_FIELD(p, s32 *, 0x4);
            if (data_020f5204 != -1 && r5 > 0x30U) {
                func_02007a04(data_020f5204, r7, base + (s32)r12, r5);
            } else {
                func_02007e70(r7, base + (s32)r12, r5);
            }
            if (data_020f5204 != -1) {
                func_02007ba4(data_020f5204, r7 + (M2C_UNK)r5, field18, r6 - r5, 0, 0);
            } else {
                func_02007e70(r7 + (M2C_UNK)r5, field18, r6 - r5);
            }
            return;
        }
    }

    if (data_020f5204 != -1) {
        func_02007ba4(data_020f5204, r7, offset, r6, 0, 0);
    } else {
        func_02007e70(r7, offset, r6);
    }
}

void func_02004cf0(void) {
    M2C_UNK func_02002c64(s32);
    M2C_UNK func_02007c3c(s32);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbfc;
    if (data_020f5204 != -1) {
        func_02007c3c(data_020f5204);
    }
    func_02002c64(M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0x14));
    M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0x1C) = 0;
    M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0x18) = 0;
    M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0x4) = 0;
    M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0x14) = 0;
}

void func_02004d70(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02007ba4(M2C_UNK, M2C_UNK, s32, s32, void (*)(s32), s32);
    M2C_UNK func_02007e70(M2C_UNK, s32, u32);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbfc;
    s32 v8 = M2C_FIELD(&data_0212dbfc, s32 *, 0x8);
    if (data_020f5204 != -1) {
        func_02007ba4(data_020f5204, arg0, v8 + (s32)arg1, arg2, 0, 0);
        return;
    }
    func_02007e70(arg0, v8 + (s32)arg1, (u32)arg2);
}

void func_02004ddc(void) {
    M2C_UNK func_02007c3c(s32);
    M2C_UNK func_02002e3c(M2C_UNK);
    extern s32 data_020f5204;
    extern M2C_UNK data_0212dbfc;
    if (data_020f5204 != -1) {
        func_02007c3c(data_020f5204);
    }
    func_02002e3c(M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0xc));
    M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0xc) = 0;
    M2C_FIELD(&data_0212dbfc, M2C_UNK *, 0x8) = 0;
}

typedef u32 Block3[3];
void func_02004e20(FuncCopyV3 *src, FuncCopyV3 *dst) {
    *dst = *src++;
    *dst = *src++;
    *dst = *src++;
    *dst = *src++;
}

void func_02004e44(void *arg0, void *arg1) {
    u32 *s = arg0;
    u32 *d = arg1;
    int i = 0;
    while (i < 16) {
        d[i] = s[i];
        i++;
    }
}

void func_02004ed4(void) {

}

void func_02004f60(void) {
    M2C_UNK func_02004ed8(M2C_UNK);
    func_02004ed8(0);
}

void func_02004f70(void) {
    func_02004ed8(1);
}

void func_02004f80(void) {
    func_02004ed8(2);
}

void func_02004f90(void) {
    func_02004ed8(3);
}

void func_02004fa0(void) {
    func_02004ed8(4);
}

void func_02004fb0(void) {
    func_02004ed8(5);
}

void func_02004fc0(void) {
    func_02004ed8(6);
}

void func_02004fd0(void) {
    func_02004ed8(7);
}

void func_02004fe0(void) {
    extern M2C_UNK data_027e00e0;
    M2C_FIELD(&data_027e00e0, s32 *, 4) = 0;
    M2C_FIELD(&data_027e00e0, s32 *, 0) = 0;
}

