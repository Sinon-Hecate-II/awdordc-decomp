/* 62 functions from 0x02081400 to 0x02082340 (main), found by ds-decomp. */
#include "common.h"

void func_02081400(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0207da60(s32, M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02080e30(arg0, 0);
    func_020067e0(temp_r0, arg2);
    func_0207da60(temp_r0, arg1, arg2);
    func_020e35cc(temp_r0);
}

void func_0208143c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020067e0(s32, M2C_UNK);
    M2C_UNK func_0207c55c(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02080e30(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02080e30(arg0, 0);
    func_020067e0(temp_r0, arg2);
    func_0207c55c(temp_r0, arg1, arg2, 1);
}

void func_02081474(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_020807e4(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02080e30(arg0, 0);
    func_020807e4(temp_r0, arg1, arg2, arg3);
    func_020e35cc(temp_r0);
}

void func_020814ac(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_r0;

    temp_r0 = func_02081070(arg0, 0);
    func_020807e4(temp_r0, arg1, arg2, arg3);
    func_020e35cc(temp_r0);
}

u8 func_020814e4(M2C_UNK arg0) {
    s32 func_0202a7f8(M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_02101e78;
    extern s32 data_0214c0e0;
    extern M2C_UNK data_0214c0e4;
    u8 var_r0;
    data_0214c0e0 = func_02080e30(arg0, 0);
    if (func_0202a7f8(&data_0214c0e4, &data_02101e78, data_0214c0e0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02081528(void) {
    M2C_UNK func_0202a940(M2C_UNK *);
    extern s32 data_0214c0e0;
    extern M2C_UNK data_0214c0e4;
    if (data_0214c0e0 == 0) {
        return;
    }
    func_0202a940(&data_0214c0e4);
    func_020e35cc(data_0214c0e0);
    data_0214c0e0 = 0;
}

void func_02081568(void) {
    M2C_UNK func_02080c00();
    M2C_UNK func_020816f4();
    func_020816f4();
    func_02080c00();
}

s32 func_02081578(void *arg0, void *arg1) {
    return func_02080c50(func_020816f4(arg0), arg1);
}

s32 func_02081590(void *arg0, void *arg1) {
    return func_02080cfc(func_020816f4(arg0), arg1);
}

void func_020815a8(void) {
    M2C_UNK func_02081070(s32, M2C_UNK);
    func_02081070(func_020816f4(), 1);
}

s32 func_020815bc(void *arg0, void *arg1) {
    return func_02081128(func_020816f4(arg0), arg1);
}

void func_020815d4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 func_020816f4(M2C_UNK);
 void func_02081080(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_02081080(func_020816f4(arg0), arg1, arg2, arg3);
}

void func_020815fc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_020816f4(M2C_UNK);
    M2C_UNK func_0208116c(s32, M2C_UNK, M2C_UNK);
    func_0208116c(func_020816f4(arg0), arg1, arg2);
}

void func_0208161c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 func_020816f4(M2C_UNK);
 void func_020811b8(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_020811b8(func_020816f4(arg0), arg1, arg2, arg3);
}

void func_02081644(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 func_020816f4(M2C_UNK);
 void func_02081254(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_02081254(func_020816f4(arg0), arg1, arg2, arg3);
}

void func_0208166c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 func_020816f4(M2C_UNK);
 void func_02081400(M2C_UNK, M2C_UNK, M2C_UNK);
 func_02081400(func_020816f4(arg0),arg1,arg2);
}

s32 func_0208168c(void *arg0, void *arg1) {
    return func_02081384(func_020816f4(arg0), arg1);
}

void func_020816a4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 func_020816f4(M2C_UNK);
 void func_02081474(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_02081474(func_020816f4(arg0), arg1, arg2, arg3);
}

void func_020816cc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 func_020816f4(M2C_UNK);
 void func_020814ac(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_020814ac(func_020816f4(arg0), arg1, arg2, arg3);
}

s32 func_020816f4(M2C_UNK arg0) {
    M2C_UNK func_02068c50(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02101e7c;
    extern M2C_UNK data_0214c14c;
    func_02068c50(&data_0214c14c, &data_02101e7c);
    func_02068d68(&data_0214c14c, arg0);
    return (s32)&data_0214c14c;
}

void func_02081724(void) {
 extern M2C_UNK data_02101e84;
 extern M2C_UNK data_0214c18c;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,8) = 0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,6) = 0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,0) = 0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,2) = 0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,4) = 0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,10) = 780;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u8 *,12) = 16;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u8 *,13) = 10;
M2C_FIELD(&data_0214c18c,u8 *,4) = 0;
M2C_FIELD(&data_0214c18c,u8 *,0) = 0;
M2C_FIELD(&data_0214c18c,u8 *,2) = 0;
M2C_FIELD(&data_0214c18c,u8 *,3) = 0;
M2C_FIELD(&data_0214c18c,u8 *,1) = 0;
}

void func_020817a0(void) {
    M2C_UNK func_02002490();
    M2C_UNK func_02006774();
    M2C_UNK func_02006804();
    M2C_UNK func_02007668(s32);
    func_02002490();
    *(s32 *)0x04001000 &= ~0x10000;
    func_02006774();
    func_02006804();
    func_02007668(*(s32 *)0x027FFC20 + 1);
}

void func_020817dc(void) {
 extern M2C_UNK data_02101e84;
 extern M2C_UNK data_0214c18c;
 s32 func_020847f4(void);
 u16 temp = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,6);
 if (temp != 0x30C) return;
 if (temp == M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,10)) return;
 if (!(M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,0) & 0x30C)) return;
 if (M2C_FIELD(&data_0214c18c,s8 *,4) <= 0 && M2C_FIELD(&data_0214c18c,s8 *,0) <= 0) {
 if (M2C_FIELD(&data_0214c18c,u8 *,1) != 0) return;
 if (func_020847f4() == 0) return;
 func_020817a0();
 }
}

void func_0208184c(void) {
    extern M2C_UNK data_02101e84;
    extern M2C_UNK data_0214c18c;
    void func_020817dc(void);

    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 8) =
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);

    if (M2C_FIELD(&data_0214c18c, u8 *, 1) != 0) {
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6) = 0;
    } else {
        u32 tmp = *(u16 *)0x4000130 | *(u16 *)0x027fffa8;
        tmp = (tmp ^ 0x2fff) & 0x2fff;
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6) = (u16)tmp;
    }

    {
        u16 v = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
        if (v & 0x20) {
            if (v & 0x10) {
                M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6) = v & ~0x30;
            }
        }
    }

    {
        u16 v = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
        if (v & 0x40) {
            if (v & 0x80) {
                M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6) = v & ~0xc0;
            }
        }
    }

    {
        u16 a = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
        u16 b = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 8);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 0) = a & (a ^ b);
    }
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 2) =
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 0);
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 4) =
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 0);

    {
        u16 v6 = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
        if (v6 != 0) {
            u16 v8 = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 8);
            if (v6 == v8) {
                M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 12) =
                    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 12) - 1;
                if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 12) == 0) {
                    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 2) =
                        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
                    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 12) = 4;
                    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 13) =
                        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 13) - 1;
                    if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 13) == 0) {
                        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 4) =
                            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
                        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 13) = 4;
                    }
                } else {
                    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 12) = 0x10;
                    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u8 *, 13) = 0x0a;
                    func_020817dc();
                }
            }
        }
    }

    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 10) =
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), u16 *, 6);
}

void func_020819e8(s32 arg0) {
 extern M2C_UNK data_02101e84;
 extern M2C_UNK data_0214c18c;
 if (M2C_FIELD(&data_0214c18c,u8 *,3) != 0) return;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,0) |= arg0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,2) |= arg0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,4) |= arg0;
M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0),u16 *,6) |= arg0;
}

void func_02081a48(void){
extern M2C_UNK data_02101e84;
struct {u16 x,y,z,w;} a;func_0200d544();if(!func_0200d5bc(&a)){a.x=0x390;a.y=0x55f;a.z=0xd52;a.w=0x113a;func_0200d650(&a);}
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x12)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x13)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x14)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x15)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x16)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x10)=0;
M2C_FIELD(M2C_FIELD(&data_02101e84,u8 **,4),u8 *,0x11)=16;}

void func_02081ae4(void) {
    extern M2C_UNK data_02101e84;
    extern M2C_UNK data_0214c18c;
    void func_0200d778(void);
    s32 func_0200d80c(u16 *);
    void func_0200dbf0(u16 *, u16 *);
    u8 buf[0x10];

    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x13) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x15) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x16) = 0;

    if (M2C_FIELD(&data_0214c18c, u8 *, 1) != 0) {
        return;
    }
    func_0200d778();
    if (func_0200d80c((u16 *)(buf + 8)) != 0) {
        *(u16 *)(buf + 6) = 3;
        goto reset_tail;
    }
    func_0200dbf0((u16 *)buf, (u16 *)(buf + 8));
    if (*(u16 *)(buf + 6) != 0) {
        goto reset_tail;
    }

    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x0) = *(u16 *)(buf + 0);
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x2) = *(u16 *)(buf + 2);

    if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x12) == 0) {
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x14) = 1;
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x4) = *(u16 *)(buf + 0);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x6) = *(u16 *)(buf + 2);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xc) = *(u16 *)(buf + 0);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x8) = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xc);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xe) = *(u16 *)(buf + 2);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xa) = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xe);
        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x12) = (u8)1;

        {
            u16 val = *(u16 *)(buf + 0);
            u16 f8 = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x8);
            if (val >= f8) val = f8;
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0x8) = val;
        }
        {
            u16 val = *(u16 *)(buf + 0);
            u16 fc = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xc);
            if (val <= fc) val = fc;
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xc) = val;
        }
        {
            u16 val = *(u16 *)(buf + 2);
            u16 fa = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xa);
            if (val >= fa) val = fa;
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xa) = val;
        }
        {
            u16 val = *(u16 *)(buf + 2);
            u16 fe = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xe);
            if (val <= fe) val = fe;
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u16 *, 0xe) = val;
        }

        if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x10) < 0xff) {
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x10) += 1;
        }

        M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x11) -= 1;
        if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x11) != 0) {
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x13) = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x14);
            return;
        } else {
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x13) = M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x12);
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x11) = 4;
            return;
        }
    } else {
        if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x12) == 1) {
            M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x16) = 1;
            if (M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x10) <= 4) {
                M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x15) = 1;
            }
        }
        goto reset_tail;
    }

reset_tail:
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x12) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), u8 *, 0x11) = 0x10;
    return;
}

u8 func_02081d18(void) {
    s32 func_0200ec24(M2C_UNK);
    u8 var_r0;

    if (func_0200ec24(1) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02081d38(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02101e8c;
    func_01ffa3dc(&data_02101e8c, 7);
}

void func_02081d50(void){extern M2C_UNK data_02101e8c;M2C_UNK func_01ffa9e4(M2C_UNK *);M2C_UNK func_0200ec24(s32);func_01ffa9e4(&data_02101e8c);func_0200ec24(0);}

void func_02081d6c(void){extern M2C_UNK data_0214c18c;func_02002490();*(volatile u32 *)0x4001000 &=~0x10000;func_02081d50();M2C_FIELD(&data_0214c18c,u8 *,1)=1;}

void func_02081da0(void) {
extern M2C_UNK data_0214c18c;
func_02081d38(); func_020024cc();
*(s32 *)0x04001000 |= 0x10000;
func_020863f0();
M2C_FIELD(&data_0214c18c,u8 *,1) = 0;
}

u8 func_02081dd8(void) {
extern M2C_UNK data_0214c18c;
u8 var_r0;
if (M2C_FIELD(&data_0214c18c,s8 *,0) > 0) return 0;
if (((s32)(*(u16 *)0x027FFFA8 & 0x8000) >> 15) != 0) var_r0 = 1; else var_r0 = 0;
return var_r0;
}

u8 func_02081e14(void) {
    u8 var_r0;

    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02081e38(void *arg0) {
extern M2C_UNK data_0214c18c;
M2C_FIELD(arg0,u16 *,0x56) = 0;
if (func_02084824() == 0) {
M2C_FIELD(arg0,u16 *,0x56) = 1;
func_02081d6c();
}
if (M2C_FIELD(&data_0214c18c,u8 *,2) != 0) {
M2C_FIELD(arg0,u16 *,0x56) = 1;
func_02081d6c();
}
}

void func_02081e84(void *arg0) {
    M2C_UNK func_01ffa730(void *);
    M2C_UNK func_0200e920(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_02081e14() == 0) {
        func_01ffa730(arg0);
    }
    if (M2C_FIELD(arg0, s16 *, 0x56) != 0) {
        return;
    }
    func_0200e920(0xC, 0, 0);
    func_01ffa730(arg0);
}

void func_02081ec8(void *arg0) {
    void func_02081da0(void);
    M2C_UNK func_020e5740();
    if (M2C_FIELD(arg0, s16 *, 0x56) != 0) {
        func_02081da0();
    }
    func_020e5740();
}

void func_02081ee4(void) {
    u8 func_02081dd8(void);
    extern M2C_UNK data_02101eac;
    if (func_02081dd8() == 0) {
        return;
    }
    func_01ffa3dc(&data_02101eac, 3);
}

s8 *func_02081f08(void) { extern M2C_UNK data_0214c18c; volatile s8 *p=(s8 *)&data_0214c18c; p[4]++; return (s8 *)p; }

s8 *func_02081f20(void) { extern M2C_UNK data_0214c18c; volatile s8 *p=(s8 *)&data_0214c18c; p[0]++; return (s8 *)p; }

void func_02081f38(void){extern M2C_UNK data_0214c18c;M2C_FIELD(&data_0214c18c,s8 *,0)=M2C_FIELD(&data_0214c18c,s8 *,0)-1;}

void func_02081f50(void) {
    extern M2C_UNK data_0214c18c;
    M2C_FIELD(&data_0214c18c, s8 *, 3) = 1;
}

void func_02081f64(void) {
extern M2C_UNK data_0214c18c;
M2C_FIELD(&data_0214c18c,u8 *,3) = 0;
}

void func_02081f78(void) {
    extern M2C_UNK data_02101e84;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), s16 *, 0) = 2;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), s16 *, 2) = 2;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), s16 *, 4) = 2;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 0), s16 *, 6) = 2;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), s8 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), s8 *, 0x13) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), s8 *, 0x12) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), s8 *, 0x15) = 0;
    M2C_FIELD(M2C_FIELD(&data_02101e84, void **, 4), s8 *, 0x16) = 0;
}

void func_02081fd4(void){extern M2C_UNK data_02101edc;M2C_UNK func_01ffa3dc(M2C_UNK *,s32);func_01ffa3dc(&data_02101edc,3);}

void func_02081fec(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02101edc;
    func_01ffa9e4(&data_02101edc);
}

void func_02082000(void){extern M2C_UNK data_0214c18c;M2C_FIELD(&data_0214c18c,u8 *,2)=1;}

void func_02082014(void){extern M2C_UNK data_0214c18c;M2C_FIELD(&data_0214c18c,u8 *,2)=0;}

void func_02082028(void) {
    M2C_UNK func_020e34bc();
    func_020e34bc();
}

void func_02082034(void) {
    func_020e34bc();
}

void func_02082040(void) {
    M2C_UNK func_020e35cc();
    func_020e35cc();
}

void func_0208204c(void) {
    func_020e35cc();
}

void func_02082058(void) {
    M2C_UNK func_02007740(u8 *);
    extern u8 data_0214c1b8;
    func_02007740(&data_0214c1b8);
}

M2C_UNK *func_0208206c(void) {
    extern M2C_UNK data_0214c1bc;
    return &data_0214c1bc;
}

u8 func_02082078(void) {
    extern u8 data_0214c1b8;
    return data_0214c1b8;
}

u16 func_02082088(void){extern u8 data_0214c1b8;return M2C_FIELD(&data_0214c1b8,u16 *,0x1a);}

void func_02082098(u32 arg0,u32 arg1) {
extern void *gCur3DSpriteEngine; extern void *data_027e00c8;
u8 b; u32 base; u32 index; void *engine; u32 bits; u16 *p; u32 old;
if(gCur3DSpriteEngine==data_027e00c8)b=1;else b=0;
if(b==1)base=0x06000000;else base=0x06200000;
M2C_FIELD((u8 *)gCur3DSpriteEngine+arg0*4,u32 *,12)=base+(arg1<<14);
engine=gCur3DSpriteEngine; index=arg0*2;
p=(u16 *)((u8 *)M2C_FIELD(engine,void **,0)+6);
bits=arg1<<28; old=*(u16 *)((u8 *)p+index);
*(u16 *)((u8 *)p+index)=(old&~0x3c)|(bits>>26);
}

void func_02082104(u32 arg0,u32 arg1) {
extern void *gCur3DSpriteEngine;
u32 index=arg0*2;
void *engine=gCur3DSpriteEngine;
u32 bits=arg1<<27;
u16 *p=(u16 *)((u8 *)M2C_FIELD(engine,void **,0)+6);
u32 old=M2C_FIELD(p,u16 *,index);
M2C_FIELD(p,u16 *,index)=(old&~0x1f00)|(bits>>19);
}

void func_02082134(s32 arg0, u32 arg1) {
    extern void *gCur3DSpriteEngine;
    u32 index = arg0 * 2;
    void *engine = gCur3DSpriteEngine;
    u32 bits = arg1 << 30;
    u16 *p = (u16 *)((u8 *)M2C_FIELD(engine, void **, 0) + 6);
    u32 old = M2C_FIELD(p, u16 *, index);
    M2C_FIELD(p, u16 *, index) = (old & ~0xc000) | (bits >> 16);
}

void func_02082164(u8 *arg0) {
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_027e00bc;
    u8 *r4;
    u16 *p;
    u16 *q;
    s32 i;
    void func_0208259c(void);
    void func_02082700(void);
    void func_02082340(s32, void *);

    r4 = arg0;

    func_0208259c();
    func_02082700();

    p = *(u16 **)gCur3DSpriteEngine;
    *p = (*p & ~0x7) | (r4[0] & 0x7);

    p = *(u16 **)gCur3DSpriteEngine;
    {
        u8 b2 = r4[2];
        u16 t = *p;
        u8 low = b2 & 0xF;
        u16 bit = (low & 0x1) << 12;
        *p = (t & ~0x1000) | bit;
    }

    p = *(u16 **)gCur3DSpriteEngine;
    {
        u8 b2b = r4[2];
        u16 t2 = *p;
        u8 high = (b2b >> 4) & 0xF;
        u16 bits = (high & 0x3) << 13;
        *p = (t2 & ~0x6000) | bits;
    }

    if (gCur3DSpriteEngine == data_027e00c8) {
        q = (u16 *)data_027e00bc;
        {
            u8 t1 = r4[1];
            *q = (*q & ~0x8) | ((t1 & 0x1) << 3);
        }
        q = (u16 *)data_027e00bc;
        {
            u8 t3 = r4[3];
            *(q + 1) = (*(q + 1) & ~0x7) | (t3 & 0x7);
        }
        q = (u16 *)data_027e00bc;
        *(q + 1) = *(q + 1) & ~0x38;
    }

    r4 += 4;
    for (i = 0; i < 4; i++) {
        func_02082340(i, r4);
        r4 += 2;
    }
}

M2C_UNK func_020822b8(M2C_UNK *a) {
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern u8 data_02152cdc[];
    extern u8 data_0214ecdc[];
    void func_02082164(u8 *);
    u8 *p;
    u8 r;
    s32 i;

    if (gCur3DSpriteEngine == data_027e00c8) {
        r = 1;
    } else {
        r = 0;
    }
    if (r == 1) {
        p = data_02152cdc;
    } else {
        p = data_0214ecdc;
    }

    for (i = 0; i < 4; i++) {
        ((u8 **)gCur3DSpriteEngine)[8 + i] = p + i * 0x1000;
    }

    func_02082164((u8 *)a);
}

void func_0208232c(void) {
    M2C_UNK func_020822b8(M2C_UNK *);
    extern M2C_UNK data_02101fb4;
    func_020822b8(&data_02101fb4);
}

