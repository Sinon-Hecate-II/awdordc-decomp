/* 14 functions from 0x0204FED0 to 0x02050C24 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;

void func_0204fed0(s32 a,s32 b) {
    void func_020675e4(void *,void *);
    void func_0204fea0(s32,s32,void *);
    extern M2C_UNK data_020fdfb0;
    u8 buf[16];
    func_020675e4(buf,&data_020fdfb0);
    func_0204fea0(a,b,(M2C_UNK *)buf);
}

s32 gpiSendOrBufferChar(M2C_UNK arg0, s32 arg1, s8 *arg2, M2C_UNK arg3, M2C_UNK *arg4, s32 *arg5, M2C_UNK *arg6) {
    s32 func_02049810(M2C_UNK, s8 *, M2C_UNK, M2C_UNK);
    s32 func_02049900(M2C_UNK);
    void func_02050744(void **, s32, s32);
    M2C_UNK func_02058170(M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK func_02058620(M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_020fdfb4;
    extern M2C_UNK data_020fdfdc;
    s8 *buf;
    s32 r;
    s32 e;

    buf = (s8 *)arg6;
    r = func_02049810(arg1, arg2, arg3, 0);
    if (r == -1) {
        e = func_02049900(arg1);
        if (e != -6 && e != -0x1A && e != -0x4C) {
            if (buf[0] == 0x50 && buf[1] == 0x52) {
                return 3;
            }
            func_02058620(arg0, 5, &data_020fdfb4);
            func_02050744(arg0, 3, 0);
            return 3;
        }
        *arg5 = 0;
        *arg4 = 0;
    } else if (r != 0) {
        *arg5 = r;
        *arg4 = 0;
    } else {
        func_02058170(arg0, &data_020fdfdc, (M2C_UNK *)buf);
        *arg5 = 0;
        *arg4 = 1;
    }
    return 0;
}

s32 func_0204fff8(M2C_UNK arg0, void *arg1, s8 arg2, M2C_UNK arg3) {
    s32 func_02048688(s32);
    s32 func_0204fcfc(M2C_UNK, void *, s8);
    s32 gpiSendOrBufferChar(M2C_UNK, s32, s8 *, M2C_UNK, M2C_UNK *, s32 *, M2C_UNK *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fdef8;
    extern M2C_UNK data_020fdf74;
    extern M2C_UNK data_020fe000;
    extern M2C_UNK data_020fe024;
    M2C_UNK sp10;
    s32 spC;

    if (M2C_FIELD(arg1, s32 *, 0x28) == 0) {
        func_020640a8(&data_020fe000, &data_020fdf74, &data_020fdef8, 0xde);
    }
    if (((M2C_FIELD(arg1, s32 *, 0x30) - M2C_FIELD(arg1, s32 *, 0x34)) == 0) &&
        (func_02048688(M2C_FIELD(arg1, s32 *, 0x38)) == 0)) {
        s32 temp_r0 = gpiSendOrBufferChar(arg0, M2C_FIELD(arg1, s32 *, 8), &arg2, 1, &sp10, &spC, &data_020fe024);
        if (temp_r0 != 0) {
            return temp_r0;
        }
        if (spC != 0) {
            return 0;
        }
    }
    return func_0204fcfc(arg0, arg1 + 0x28, arg2);
}

s32 gpiSendOrBufferStringLen(M2C_UNK connection, M2C_UNK peer, M2C_UNK string, s32 stringLen) {
    s32 func_02048688(s32);
    M2C_UNK gpiAppendStringToBufferLen(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 gpiSendOrBufferChar(M2C_UNK, s32, s8 *, M2C_UNK, M2C_UNK *, s32 *, M2C_UNK *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fdf24;
    extern M2C_UNK data_020fdf74;
    extern M2C_UNK data_020fe000;
    extern M2C_UNK data_020fe024;
    M2C_UNK unusedStatus;
    s32 bytesSent;
    s32 offset;
    s32 result;

    /* Send string to peer, buffering the bytes that cannot be sent immediately. */
    if (M2C_FIELD(peer, s32 *, 0x28) == 0) {
        func_020640a8(&data_020fe000, &data_020fdf74, &data_020fdf24, 0xfb);
    }
    offset = 0;
    if (stringLen == 0) {
        return offset;
    }
    if (((M2C_FIELD(peer, s32 *, 0x30) - M2C_FIELD(peer, s32 *, 0x34)) == 0) &&
        (func_02048688(M2C_FIELD(peer, s32 *, 0x38)) == 0)) {
        do {
            result = gpiSendOrBufferChar(connection, M2C_FIELD(peer, s32 *, 8), (s8 *)(string + offset), stringLen, &unusedStatus, &bytesSent, &data_020fe024);
            if (result != 0) {
                return result;
            }
            if (bytesSent != 0) {
                stringLen -= bytesSent;
                offset += bytesSent;
            }
        } while (bytesSent != 0 && stringLen != 0);
    }
    if (stringLen != 0) {
        result = gpiAppendStringToBufferLen(connection, peer + 0x28, string + offset, stringLen);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

void func_020501d8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK gpiSendOrBufferStringLen(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_02068c34(M2C_UNK);
    gpiSendOrBufferStringLen(arg0, arg1, arg2, func_02068c34(arg2));
}

s32 func_020505b0(M2C_UNK connection, void *arg1, s8 **arg2, s32 *arg3, s32 *arg4) {
    s8 *func_02068ee0(M2C_UNK, M2C_UNK);
    s32 func_02068eac(s32, M2C_UNK *, s32);
    s32 func_02058254(M2C_UNK, M2C_UNK *, M2C_UNK *, s32);
    s32 func_0206ad38(M2C_UNK *);
    extern M2C_UNK data_020fe104;
    extern M2C_UNK data_020fe10c;
    extern M2C_UNK data_020fe110;
    M2C_UNK sp0[4];
    s8 *temp_r0;
    s32 temp;
    s32 field8;
    (void)connection;

    *arg2 = NULL;
    field8 = M2C_FIELD(arg1, s32 *, 8);
    if (field8 >= 5) {
        temp_r0 = func_02068ee0(M2C_FIELD(arg1, M2C_UNK *, 0), 0xA);
        if (temp_r0 != NULL) {
            if (func_02068eac((s32)(temp_r0 - 5), &data_020fe104, 5) != 0) {
                return 3;
            }
            *temp_r0 = 0;
            if (func_02058254(M2C_FIELD(arg1, M2C_UNK *, 0), &data_020fe10c, sp0, 0x10) == 0) {
                return 3;
            }
            *arg3 = func_0206ad38(sp0);
            if (func_02058254(M2C_FIELD(arg1, M2C_UNK *, 0), &data_020fe110, sp0, 0x10) == 0) {
                return 3;
            }
            temp = func_0206ad38(sp0);
            if (field8 > (temp + 1 + (temp_r0 - (s8 *)M2C_FIELD(arg1, M2C_UNK *, 0)))) {
                if (temp_r0[temp + 1] != 0) {
                    return 3;
                }
                *arg2 = temp_r0 + 1;
                *arg4 = temp;
                M2C_FIELD(arg1, s32 *, 0xC) = (temp + 1) + (temp_r0 - (s8 *)M2C_FIELD(arg1, M2C_UNK *, 0)) + 1;
            } else {
                *temp_r0 = 0xA;
            }
        }
    }
    return 0;
}

s32 func_020506ec(s32 unused,void *p) {
s32 n;
if(!p || !M2C_FIELD(p,s32 *,0) || !M2C_FIELD(p,s32 *,12))return 0;
n=M2C_FIELD(p,s32 *,8)-M2C_FIELD(p,s32 *,12);
M2C_FIELD(p,s32 *,8)=n;
if(n)func_020651c4(M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,0)+M2C_FIELD(p,s32 *,12),n);
M2C_FIELD(M2C_FIELD(p,s32 *,0)+M2C_FIELD(p,s32 *,8),u8 *,0)=0;
M2C_FIELD(p,s32 *,12)=0;return 0;
}

s32 func_02050838(void *arg0,volatile Unk02050838Pair pair,s32 c,s32 arg4,u32 arg5) {
void *func_02037794(s32);
extern M2C_UNK data_020fe1ac;
void *base=M2C_FIELD(arg0,void **,0);
void *p=func_02037794(24);
void *q;
if(!p) {func_02058644(arg0,&data_020fe1ac);return 1;}
M2C_FIELD(p,s32 *,0)=pair.unk_0;M2C_FIELD(p,s32 *,4)=pair.unk_4;M2C_FIELD(p,s32 *,8)=c;
M2C_FIELD(p,void **,16)=arg4?M2C_FIELD(arg4,void **,24):NULL;
M2C_FIELD(p,s32 *,12)=arg5;M2C_FIELD(p,s32 *,20)=0;
if(!M2C_FIELD(base,void **,0x438))M2C_FIELD(base,void **,0x438)=p;
q=M2C_FIELD(base,void **,0x43c);
if(q)M2C_FIELD(q,void **,20)=p;
M2C_FIELD(base,void **,0x43c)=p;return 0;
}

s32 func_02050ad4(void **arg0, s32 arg1) {
    s32 func_020508dc(void **);
    void *temp_r4;
    void *var_r5;
    void *var_r6;
    void *var_r7;
    void *temp_r8;
    void *temp_r6b;
    void *var_r1;

    temp_r4 = *arg0;

    if (arg1 != 0) {
        var_r5 = M2C_FIELD(temp_r4, void **, 0x438);
        var_r6 = M2C_FIELD(temp_r4, void **, 0x43C);
        var_r7 = NULL;
        M2C_FIELD(temp_r4, void **, 0x438) = NULL;
        var_r1 = var_r5;
        M2C_FIELD(temp_r4, void **, 0x43C) = NULL;
        if (var_r5 != NULL) {
            do {
                temp_r8 = M2C_FIELD(var_r1, void **, 0x14);
                if ((M2C_FIELD(var_r1, s32 *, 0x10) == arg1) ||
                    (M2C_FIELD(var_r1, s32 *, 0xC) == 1)) {
                    if (var_r7 != NULL) {
                        M2C_FIELD(var_r7, void **, 0x14) = temp_r8;
                    } else {
                        var_r5 = temp_r8;
                    }
                    if (var_r6 == var_r1) {
                        var_r6 = var_r7;
                    }
                    func_020508dc(arg0);
                } else {
                    var_r7 = var_r1;
                }
                var_r1 = temp_r8;
            } while (temp_r8 != NULL);
        }
        if (M2C_FIELD(temp_r4, void **, 0x438) != NULL) {
            M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x43C), void **, 0x14) = var_r5;
        } else {
            M2C_FIELD(temp_r4, void **, 0x438) = var_r5;
        }
        M2C_FIELD(temp_r4, void **, 0x43C) = var_r6;
        return 0;
    }

    var_r1 = M2C_FIELD(temp_r4, void **, 0x438);
    if (var_r1 != NULL) {
        do {
            var_r5 = NULL;
            M2C_FIELD(temp_r4, void **, 0x438) = NULL;
            M2C_FIELD(temp_r4, void **, 0x43C) = NULL;
            if (var_r1 != NULL) {
                do {
                    temp_r6b = M2C_FIELD(var_r1, void **, 0x14);
                    func_020508dc(arg0);
                    var_r1 = temp_r6b;
                } while (var_r1 != NULL);
            }
            var_r1 = M2C_FIELD(temp_r4, void **, 0x438);
        } while (var_r1 != NULL);
    }
    return 0;
}

void func_02050bbc(s8 *p,s32 n) {
u32 func_02067774(void);extern s8 data_020fe250[];
s32 i=0;
for(;i<n;i++)p[i]=data_020fe250[func_02067774()%62U];
p[i]=0;
}

