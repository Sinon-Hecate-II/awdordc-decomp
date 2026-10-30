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

s32 gpiSendOrBufferChar(M2C_UNK arg0,s32 arg1,s8 *arg2,M2C_UNK arg3,M2C_UNK *arg4,s32 *arg5,M2C_UNK *arg6) {
s32 func_02049810(M2C_UNK,s8 *,M2C_UNK,M2C_UNK);
s32 func_02049900(M2C_UNK);
void func_02050744(void **,s32,s32);
M2C_UNK func_02058170(M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK func_02058620(M2C_UNK,M2C_UNK,M2C_UNK *);
extern M2C_UNK data_020fdfb4;
extern M2C_UNK data_020fdfdc;
s8 *buf; s32 r; s32 e;
buf=(s8 *)arg6;
r=func_02049810(arg1,arg2,arg3,0);
if(r==-1) {
e=func_02049900(arg1);
if(e!=-6 && e!=-26 && e!=-76) {
if(buf[0]==80 && buf[1]==82) return 3;
func_02058620(arg0,5,&data_020fdfb4);
func_02050744(arg0,3,0);
return 3;
}
*arg5=0; *arg4=0;
} else {
if(r!=0) { *arg5=r; *arg4=0; }
if(r!=0) goto done;
func_02058170(arg0,&data_020fdfdc,(M2C_UNK *)buf);
*arg5=0; *arg4=1;
}
done:
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

s32 func_02050208(M2C_UNK connection, s32 sock, void *inputBuffer, s32 *bytesRead, s32 *connClosed, M2C_UNK arg5) {
    void *func_020377a8(void *, s32);
    s32 func_020497cc(s32, void *, s32, s32);
    s32 func_02049900(s32);
    M2C_UNK func_02058644(M2C_UNK, M2C_UNK *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fdf74;
    extern M2C_UNK data_020fded4;
    extern M2C_UNK data_020fe028;
    extern M2C_UNK data_020fe040;
    extern M2C_UNK data_020fe054;
    extern M2C_UNK data_020fe068;
    extern M2C_UNK data_020fdf80;
    extern M2C_UNK data_020fe07c;
    extern M2C_UNK data_020fe0a8;
    extern M2C_UNK data_020fe0cc;
    s32 *buf;
    void *data;
    s32 end;
    s32 size;
    s32 received;
    s32 total;
    s32 closed;
    s32 err;

    buf = (s32 *)inputBuffer;

    if (sock == -1) {
        func_020640a8(&data_020fe028, &data_020fdf74, &data_020fded4, 0x150);
    }
    if (inputBuffer == 0) {
        func_020640a8(&data_020fe040, &data_020fdf74, &data_020fded4, 0x151);
    }
    if (bytesRead == 0) {
        func_020640a8(&data_020fe054, &data_020fdf74, &data_020fded4, 0x152);
    }
    if (connClosed == 0) {
        func_020640a8(&data_020fe068, &data_020fdf74, &data_020fded4, 0x153);
    }

    end = buf[2];
    data = (void *)buf[0];
    size = buf[1];
    total = 0;
    closed = total;

    for (;;) {
        if (end + 0x800 > size) {
            size = end + 0x800;
            data = func_020377a8(data, size + 1);
            if (data == 0) {
                func_02058644(connection, &data_020fdf80);
                return 1;
            }
        }
        received = func_020497cc(sock, (char *)data + end, size - end, 0);
        if (received == -1) {
            err = func_02049900(sock);
            if (err != -6 && err != -0x1A && err != -0x4C) {
                func_02058644(connection, &data_020fe07c);
                return 3;
            }
        } else if (received == 0) {
            closed = 1;
            func_02058170(connection, &data_020fe0a8, (M2C_UNK *)arg5);
        } else {
            end += received;
            total += received;
        }

        *((char *)data + end) = 0;

        if (received == -1) {
            break;
        }
        if (closed != 0) {
            break;
        }
        if (total < 0x20000) {
            continue;
        }
        break;
    }

    if (total != 0) {
        ((M2C_UNK (*)(M2C_UNK, M2C_UNK *, M2C_UNK, s32))func_02058170)(connection, &data_020fe0cc, (M2C_UNK *)arg5, total);
    }

    buf[0] = (s32)data;
    buf[2] = end;
    buf[1] = size;
    *bytesRead = total;
    *connClosed = closed;
    return 0;
}

s32 func_02050430(s32 arg0,s32 arg1,void *arg2,s32 *arg3,s32 arg4,s32 arg5) {
 s32 func_020640a8(s32 *,s32 *,s32 *,s32);
 s32 func_020651c4(s32,s32,s32);
 extern s32 data_020fdee4,data_020fdf5c,data_020fdf74,data_020fe0e0,data_020fe0ec,data_020fe0f8;
 s32 sp18,sp14;
 s32 done;
 void *buffer;
 s32 result;
 s32 remaining;
 s32 end;
 s32 *out;
 s32 data;
 s32 start;
 buffer=arg2;out=arg3;
 if(!arg2)func_020640a8(&data_020fdf5c,&data_020fdf74,&data_020fdee4,0x1b9);
 done=0;
 end=M2C_FIELD(buffer,s32 *,8);
 start=M2C_FIELD(buffer,s32 *,12);
 data=M2C_FIELD(buffer,s32 *,0);
 remaining=end-start;
 if(!remaining)return 0;
 do {
 result=gpiSendOrBufferChar(arg0,arg1,(s8 *)(data+(start+done)),remaining,&sp18,&sp14,(s32 *)arg5);
 if(result)return result;
 if(sp14){remaining-=sp14;done+=sp14;}
 }while(sp14 && remaining);
 if(arg4) {
 if(done>0){func_020651c4(data,data+done,remaining+1);end-=done;}
 }else start+=done;
 if(end<0)func_020640a8(&data_020fe0e0,&data_020fdf74,&data_020fdee4,0x1de);
 if(start<0)func_020640a8(&data_020fe0ec,&data_020fdf74,&data_020fdee4,0x1df);
 if(start>end)func_020640a8(&data_020fe0f8,&data_020fdf74,&data_020fdee4,0x1e0);
 M2C_FIELD(buffer,s32 *,8)=end;
 M2C_FIELD(buffer,s32 *,12)=start;
 if(out)*out=sp18;
 return 0;
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
    s32 *arg4sp;

    (void)connection;
    *arg2 = NULL;
    arg4sp = arg4;
    if (M2C_FIELD(arg1, s32 *, 8) < 5) {
        return 0;
    }
    temp_r0 = func_02068ee0(M2C_FIELD(arg1, M2C_UNK *, 0), 0xA);
    if (temp_r0 == NULL) {
        return 0;
    }
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
    if (M2C_FIELD(arg1, s32 *, 8) > (temp + 1 + (temp_r0 - (s8 *)M2C_FIELD(arg1, M2C_UNK *, 0)))) {
        if (temp_r0[temp + 1] != 0) {
            return 3;
        }
        *arg2 = temp_r0 + 1;
        *arg4sp = temp;
        M2C_FIELD(arg1, s32 *, 0xC) = (temp + 1) + (temp_r0 - (s8 *)M2C_FIELD(arg1, M2C_UNK *, 0)) + 1;
    } else {
        *temp_r0 = 0xA;
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

void func_02050744(void **arg0, s32 arg1, s32 arg2) {
    void *func_02037794(s32);
    s32 func_02050838(void *, volatile Unk02050838Pair, s32, s32, u32);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fe128;
    extern M2C_UNK data_020fe140;
    extern M2C_UNK data_020fe154;
    extern M2C_UNK data_020fe164;
    extern M2C_UNK data_020fe17c;

    void *conn = *arg0;

    if (conn == NULL) {
        func_020640a8(&data_020fe140, &data_020fe154, &data_020fe128, 0x23);
    }
    if (arg1 == 0) {
        func_020640a8(&data_020fe164, &data_020fe154, &data_020fe128, 0x24);
    }
    if (arg2 != 1 && arg2 != 0) {
        func_020640a8(&data_020fe17c, &data_020fe154, &data_020fe128, 0x25);
    }
    if (arg2 == 1) {
        M2C_FIELD(conn, s32 *, 0x41C) = 1;
    }
    {
        s32 val = M2C_FIELD(conn, s32 *, 0x1A4);
        volatile Unk02050838Pair sp8;
        void *temp_r0;
        sp8.unk_0 = val;
        sp8.unk_4 = M2C_FIELD(conn, s32 *, 0x1A8);
        if (val == 0) {
            return;
        }
        temp_r0 = func_02037794(0x10);
        if (temp_r0 != NULL) {
            M2C_FIELD(temp_r0, s32 *, 0) = arg1;
            M2C_FIELD(temp_r0, s32 *, 0xC) = arg2;
            M2C_FIELD(temp_r0, s32 *, 4) = M2C_FIELD(conn, s32 *, 0x418);
            M2C_FIELD(temp_r0, void **, 8) = conn;
        }
        func_02050838(arg0, sp8, (s32)temp_r0, 0, 1);
    }
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

void func_020508dc(void *obj, void *node) {
    void func_020377c4(void *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fe1bc;
    extern M2C_UNK data_020fe154;
    extern M2C_UNK data_020fe118;
    extern M2C_UNK data_020fe1dc;

    if (!M2C_FIELD(node, void **, 0)) {
        func_020640a8(&data_020fe1bc, &data_020fe154, &data_020fe118, 0x6e);
    }
    if (!M2C_FIELD(node, void **, 8)) {
        func_020640a8(&data_020fe1dc, &data_020fe154, &data_020fe118, 0x6f);
    }

    ((void (*)(void *, void *, void *))M2C_FIELD(node, void **, 0))(obj, M2C_FIELD(node, void **, 8), M2C_FIELD(node, void **, 4));

    {
        s32 code = M2C_FIELD(node, s32 *, 0xc);
        if (code == 2) {
            func_020377c4(M2C_FIELD(M2C_FIELD(node, void **, 8), void **, 8));
            M2C_FIELD(M2C_FIELD(node, void **, 8), void **, 8) = 0;
        } else if (code == 3) {
            void *inner = M2C_FIELD(node, void **, 8);
            s32 i;
            s32 count = M2C_FIELD(inner, s32 *, 0x38);
            for (i = 0; i < count; i++) {
                func_020377c4(((void **)M2C_FIELD(inner, void **, 0x3c))[i]);
                ((void **)M2C_FIELD(inner, void **, 0x3c))[i] = 0;
                func_020377c4(((void **)M2C_FIELD(inner, void **, 0x40))[i]);
                ((void **)M2C_FIELD(inner, void **, 0x40))[i] = 0;
            }
            func_020377c4(M2C_FIELD(inner, void **, 0x3c));
            M2C_FIELD(inner, void **, 0x3c) = 0;
            func_020377c4(M2C_FIELD(inner, void **, 0x40));
            M2C_FIELD(inner, void **, 0x40) = 0;
        } else if (code == 4) {
            void *inner = M2C_FIELD(node, void **, 8);
            func_020377c4(M2C_FIELD(inner, void **, 0xc));
            M2C_FIELD(inner, void **, 0xc) = 0;
        } else if (code == 7) {
            void *inner = M2C_FIELD(node, void **, 8);
            void *x = M2C_FIELD(inner, void **, 0x10);
            if (x) {
                func_020377c4(x);
                M2C_FIELD(inner, void **, 0x10) = 0;
            }
        } else if (code == 8) {
            void *inner = M2C_FIELD(node, void **, 8);
            void *x = M2C_FIELD(inner, void **, 0x8);
            if (x) {
                func_020377c4(x);
                M2C_FIELD(inner, void **, 0x8) = 0;
            }
        } else if (code == 9) {
            void *inner = M2C_FIELD(node, void **, 8);
            s32 count = M2C_FIELD(inner, s32 *, 0x4);
            void **arr = (void **)M2C_FIELD(inner, void **, 0x8);
            s32 i;
            for (i = 0; i < count; i++) {
                func_020377c4(arr[i]);
                arr[i] = 0;
            }
            func_020377c4(arr);
            M2C_FIELD(inner, void **, 0x8) = 0;
            func_020377c4(inner);
            M2C_FIELD(node, void **, 8) = 0;
            func_020377c4(node);
        }
    }
}

s32 func_02050ad4(void **arg0, s32 arg1) {
    void *temp_r4;
    void *var_r5;
    void *var_r6;
    void *var_r7;
    void *temp_r8;
    void *temp_r6b;
    void *var_r1;
    void *saved;

    temp_r4 = *arg0;

    if (arg1 != 0) {
        var_r5 = M2C_FIELD(temp_r4, void **, 0x438);
        var_r6 = M2C_FIELD(temp_r4, void **, 0x43C);
        var_r7 = (void *)0;
        M2C_FIELD(temp_r4, void **, 0x438) = (void *)0;
        var_r1 = var_r5;
        M2C_FIELD(temp_r4, void **, 0x43C) = (void *)0;
        if (var_r5 != (void *)0) {
            do {
                temp_r8 = M2C_FIELD(var_r1, void **, 0x14);
                if ((M2C_FIELD(var_r1, s32 *, 0x10) == arg1) ||
                    (M2C_FIELD(var_r1, s32 *, 0xC) == 1)) {
                    if (var_r7 != (void *)0) {
                        M2C_FIELD(var_r7, void **, 0x14) = temp_r8;
                    } else {
                        var_r5 = temp_r8;
                    }
                    if (var_r6 == var_r1) {
                        var_r6 = var_r7;
                    }
                    func_020508dc(arg0, var_r1);
                } else {
                    var_r7 = var_r1;
                }
                var_r1 = temp_r8;
            } while (temp_r8 != (void *)0);
        }
        if (M2C_FIELD(temp_r4, void **, 0x438) != (void *)0) {
            M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x43C), void **, 0x14) = var_r5;
        } else {
            M2C_FIELD(temp_r4, void **, 0x438) = var_r5;
        }
        M2C_FIELD(temp_r4, void **, 0x43C) = var_r6;
        return 0;
    }

    var_r1 = M2C_FIELD(temp_r4, void **, 0x438);
    if (var_r1 != (void *)0) {
        do {
            var_r5 = (void *)0;
            M2C_FIELD(temp_r4, void **, 0x438) = (void *)0;
            M2C_FIELD(temp_r4, void **, 0x43C) = (void *)0;
            if (var_r1 != (void *)0) {
                do {
                    saved = M2C_FIELD(var_r1, void **, 0x14);
                    func_020508dc(arg0, var_r1);
                    var_r1 = saved;
                } while (saved != (void *)0);
            }
            var_r1 = M2C_FIELD(temp_r4, void **, 0x438);
        } while (var_r1 != (void *)0);
    }
    return 0;
}

void func_02050bbc(s8 *p,s32 n) {
u32 func_02067774(void);extern s8 data_020fe250[];
s32 i=0;
for(;i<n;i++)p[i]=data_020fe250[func_02067774()%62U];
p[i]=0;
}

