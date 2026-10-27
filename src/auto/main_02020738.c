/* 39 functions from 0x02020738 to 0x020216CC (main), found by ds-decomp. */
#include "common.h"


s32 func_020210b8(void);

s32 func_02020738(void *connection, s32 buffer, s32 byteCount, s32 startPos, u16 tag, s32 fallback, s32 mode) {
    /* Queue a (possibly wrapped) send from connection's circular buffer and remember how much was taken. */
    u16 func_0201d04c();
    s32 func_020208ac(void *);
    s32 func_0201f1d0(void *, s32, s32);
    s32 func_0201f328(s32, s32);
    s32 func_02008048(s32, s32, s32);
    void *ctx;
    void *entry;
    s32 curBuffer;
    s32 end;
    s32 other;
    s32 size;
    s32 start;
    curBuffer = buffer;
    ctx = M2C_FIELD(connection, void **, 0x68);

    entry = (void *)func_0201f1d0(func_020208ac, M2C_FIELD(ctx, s32 *, 0x10c), mode);
    if (!entry) return -33;

    if ((mode & 1) && M2C_FIELD(connection, s8 *, 0x73) != 1)
        M2C_FIELD(entry, s8 *, 13) = 3;
    else
        M2C_FIELD(entry, s8 *, 13) = 0;
    start = M2C_FIELD(ctx, s32 *, 0xfc);
    size = M2C_FIELD(ctx, s32 *, 0xf8);
    if (startPos + byteCount < size) {
        M2C_FIELD(entry, s32 *, 16) = start + startPos;
        M2C_FIELD(entry, s32 *, 20) = byteCount;
        M2C_FIELD(entry, s32 *, 24) = 0;
        startPos += byteCount;
        M2C_FIELD(entry, s32 *, 28) = 0;
    } else {
        M2C_FIELD(entry, s32 *, 16) = start + startPos;
        M2C_FIELD(entry, s32 *, 20) = size - startPos;
        M2C_FIELD(entry, s32 *, 24) = start;
        startPos = byteCount - M2C_FIELD(entry, s32 *, 20);
        M2C_FIELD(entry, s32 *, 28) = startPos;
        func_02008048(curBuffer + M2C_FIELD(entry, s32 *, 20), M2C_FIELD(entry, s32 *, 24), startPos);
    }
    func_02008048(curBuffer, M2C_FIELD(entry, s32 *, 16), M2C_FIELD(entry, s32 *, 20));
    curBuffer = M2C_FIELD(ctx, u16 *, 0x100);
    M2C_FIELD(entry, u16 *, 32) = startPos;
    M2C_FIELD(ctx, u16 *, 0x100) = M2C_FIELD(entry, u16 *, 32);
    if (M2C_FIELD(connection, s8 *, 0x73) == 1) {
        if (!M2C_FIELD(connection, u16 *, 0x74)) {
            M2C_FIELD(connection, u16 *, 0x74) = func_0201d04c();
            M2C_FIELD(connection, u16 *, 10) = M2C_FIELD(connection, u16 *, 0x74);
        }
        M2C_FIELD(entry, u16 *, 36) = M2C_FIELD(connection, u16 *, 0x74);
        other = M2C_FIELD(connection, s32 *, 0x78);
        if (!other || fallback) {
            M2C_FIELD(entry, s32 *, 40) = fallback;
            M2C_FIELD(entry, u16 *, 38) = tag;
        } else {
            M2C_FIELD(entry, s32 *, 40) = other;
            M2C_FIELD(entry, u16 *, 38) = M2C_FIELD(connection, u16 *, 0x76);
        }
    } else
        M2C_FIELD(entry, s32 *, 40) = 0;
    if (func_0201f328(M2C_FIELD(ctx, s32 *, 0x10c), (s32)entry)) {
        byteCount = 0;
        M2C_FIELD(ctx, u16 *, 0x100) = curBuffer;
    }
    return byteCount;
}

s32 func_020208ac(void *arg0) {
 void func_02005df4(s32);
 M2C_UNK func_0201d190(u16,u16,s32);
 s32 func_0201db20(s32,s32);
 s32 func_0201d4c0();
 s32 sent,base,yes,length,valid,valid2;void *object; void *context;u32 total;s32 header;
 s8 type,type2,type3;
 object=M2C_FIELD(arg0,void **,4);
 total=0;
 type=M2C_FIELD(object,s8 *,0x73);valid=1;
 context=M2C_FIELD(object,void **,0x68);
 if(type && type!=4)valid=0;
 if(!valid || (M2C_FIELD(object,s16 *,0x70)&4)) {
 s32 flag=M2C_FIELD(arg0,s32 *,0x28);
 if(flag)func_0201d190(M2C_FIELD(arg0,u16 *,0x24),M2C_FIELD(arg0,u16 *,0x26),flag);
 type2=M2C_FIELD(object,s8 *,0x73);yes=1;
 base=M2C_FIELD(object,s32 *,0x4c);
 if(type2 && type2!=4)yes=0;
 if(yes)header=54;else header=42;
 if(type2 && type2!=4)length=M2C_FIELD(object,s32 *,0x48)-header;
 else length=func_020209dc(M2C_FIELD(object,s32 *,0x48)-header);
 loop:
 valid2=func_02020a80(base+header,length,arg0);
 if(valid2>0) {
 sent=func_0201db20(base+header,valid2);
 if(sent<=0) {
 type3=M2C_FIELD(object,s8 *,0x73);valid=1;
 if(type3 && type3!=4)valid=0;
 if(valid){
 M2C_FIELD(object,s16 *,0x70)&=~14;
 M2C_FIELD(object,s16 *,0x70)|=128;
 func_0201d4c0();
 }
 total=-76;
 }else{total+=sent;goto loop;}
 }
 }else total=-76;
 M2C_FIELD(context,u16 *,0x102)=M2C_FIELD(arg0,u16 *,0x20);
 func_02005df4((s32)context+0x104);
 return total;
}

s32 func_020209dc(s32 arg0) {
    s32 func_020720f0(s32, s32);
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02138ad0;
    s32 temp_r0;
    s32 lock;
    s32 var_r5;
    s32 max;
    s32 temp_r2;
    s32 var_r3;
    void *temp_r5;
    temp_r5 = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
    lock = func_0200751c();
    if (temp_r5 != NULL) {
        var_r3 = M2C_FIELD(temp_r5, u16 *, 0x2E);
        if ((var_r3 != 0) && (temp_r2 = M2C_FIELD(temp_r5, u16 *, 0x2C), temp_r2 != 0)) {
            max = M2C_FIELD(&data_02138ad0, s32 *, 0x24);
            if (var_r3 > temp_r2) var_r3 = temp_r2;
            if (var_r3 > max) var_r3 = max;
            var_r5 = var_r3 * 2;
        } else {
            var_r5 = M2C_FIELD(&data_02138ad0, s32 *, 0x24) * 2;
        }
    } else {
        var_r5 = M2C_FIELD(&data_02138ad0, s32 *, 0x24) * 2;
    }
    func_02007530(lock);
    if (var_r5 > 0) {
        temp_r0 = func_020720f0(arg0, var_r5);
        if (temp_r0 > 0) return var_r5 * temp_r0;
    }
    return arg0;
}

s32 func_02020a80(s32 arg0, s32 arg1, void *arg2) {
    M2C_UNK func_02008048(s32, s32, s32);
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;

    var_r4 = M2C_FIELD(arg2, s32 *, 0x14);
    var_r5 = M2C_FIELD(arg2, s32 *, 0x1C);
    if (var_r4 > arg1) {
        var_r4 = arg1;
        var_r5 = 0;
    } else {
        temp_r0 = arg1 - var_r4;
        if (var_r5 > temp_r0) {
            var_r5 = temp_r0;
        }
    }
    if (var_r4 > 0) {
        func_02008048(M2C_FIELD(arg2, s32 *, 0x10), arg0, var_r4);
        M2C_FIELD(arg2, s32 *, 0x10) = (s32) (M2C_FIELD(arg2, s32 *, 0x10) + var_r4);
        M2C_FIELD(arg2, s32 *, 0x14) = (s32) (M2C_FIELD(arg2, s32 *, 0x14) - var_r4);
    }
    if (var_r5 > 0) {
        func_02008048(M2C_FIELD(arg2, s32 *, 0x18), arg0 + var_r4, var_r5);
        M2C_FIELD(arg2, s32 *, 0x18) = (s32) (M2C_FIELD(arg2, s32 *, 0x18) + var_r5);
        M2C_FIELD(arg2, s32 *, 0x1C) = (s32) (M2C_FIELD(arg2, s32 *, 0x1C) - var_r5);
    }
    return var_r4 + var_r5;
}

s32 func_02020b18(void *arg0) {
    s32 func_02020bc4(void *);
    s32 func_0201f1d0(void *, s32, s32);
    s32 func_0201f328(s32, s32);
    s32 func_020214a8();
    void *temp_r5;
    s32 var_r1;
    s32 temp_r1;
    if (func_020214a8() != 0) return -0x1C;
    var_r1 = 0;
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s16 *, 0x70) & 1)) var_r1 = 1;
    if (var_r1 == 0) return -0x27;
    if (!(M2C_FIELD(arg0, s16 *, 0x70) & 4) || (M2C_FIELD(arg0, s16 *, 0x70) & 8)) return -0x38;
    M2C_FIELD(arg0, s16 *, 0x70) |= 8;
    temp_r5 = M2C_FIELD(arg0, void **, 0x68);
    if (temp_r5 != NULL) {
        temp_r1 = M2C_FIELD(temp_r5, s32 *, 0x10C);
        if (temp_r1 != 0) {
            temp_r1 = func_0201f1d0(func_02020bc4, temp_r1, M2C_FIELD(arg0, s8 *, 0x72));
            if (temp_r1 == 0) return -0x21;
            return func_0201f328(M2C_FIELD(temp_r5, s32 *, 0x10C), temp_r1);
        }
    }
    return 0;
}

s32 func_02020bc4(void *arg0) {
    M2C_UNK func_0201d484();
    s32 var_r1;
    s8 temp_r0;

    var_r1 = 1;
    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x73);
    if ((temp_r0 != 0) && (temp_r0 != 4)) {
        var_r1 = 0;
    }
    if (var_r1 != 0) {
        func_0201d484();
    }
    return 0;
}

s32 func_02020bf4(s32 arg0) {
    s32 func_020214a8();
    s32 func_020214dc(s32);
    if ((arg0 >= 0) && (func_020214a8() != 0) && (func_020214dc(arg0) == 0)) {
        return 1;
    }
    return 0;
}

s32 func_02020c28(s32 arg0) {
M2C_UNK func_0201f244(s32, M2C_UNK); M2C_UNK func_0201f290();

s32 func_02020cf8(void *);
void *t;
s32 a,b; s8 v;
if(arg0<=0)return -28;
if(func_020214dc()!=0)return -26;
if(func_020214a8(arg0)!=0)return 0;
a=0;
if(arg0!=0)a=(M2C_FIELD(arg0,volatile s16*,0x70)&1)!=0;
if(!a)return -39;
if(M2C_FIELD(arg0,s16*,0x70)&16)return -26;
b=1;
M2C_FIELD(arg0,volatile s16*,0x70)=M2C_FIELD(arg0,volatile s16*,0x70)|24;
v=M2C_FIELD(arg0,s8*,0x73);
if(v!=0 && v!=4)b=0;
if(b)func_0201f244(M2C_FIELD(arg0,s32*,0x68),0);
t=(void*)func_0201f1d0(&func_02020cf8,arg0,1);
M2C_FIELD(t,volatile s32*,8)=0;
func_0201f290(arg0,t);
return 0;
}

s32 func_02020cf8(void *arg0) {
    M2C_UNK func_0201d4c0();
    M2C_UNK func_0201d224();
    M2C_UNK func_0201d14c();
    M2C_UNK func_0201f244(s32, s32);
    void func_02021418(void *);
    void func_02021430(M2C_UNK);
    s32 temp_r5;
    s32 var_r0;
    s32 var_r1;
    s8 temp_r0;
    void *temp_r4;
    temp_r4 = M2C_FIELD(arg0, void **, 4);
    var_r1 = 1;
    temp_r0 = M2C_FIELD(temp_r4, s8 *, 0x73);
    if ((temp_r0 != 0) && (temp_r0 != 4)) var_r1 = 0;
    if (var_r1 != 0) {
        func_02005d60(M2C_FIELD(temp_r4, s32 *, 0x68) + 0x20);
        func_0201d484();
        func_0201d4c0();
        func_0201d224();
    }
    func_0201d14c();
    M2C_FIELD(temp_r4, s16 *, 0x70) &= ~6;
    if (M2C_FIELD(temp_r4, s8 *, 0x73) == 2) var_r0 = M2C_FIELD(temp_r4, s32 *, 0x68);
    else var_r0 = M2C_FIELD(temp_r4, s32 *, 0x64);
    func_0201f244(var_r0, 0);
    temp_r5 = func_0200751c();
    func_02021430((M2C_UNK)temp_r4);
    func_02021418(temp_r4);
    func_02007530(temp_r5);
    M2C_FIELD(temp_r4, s16 *, 0x70) |= 0x20;
    return 0;
}

/* Tear down an object: free its children, detach from queues, then free the object itself. */
M2C_UNK func_02020d90(s32 obj) {
extern void *data_020faf98;
void func_02020e90(s32);
void func_02021430(M2C_UNK);
void func_02021490(M2C_UNK);
void func_02005df4(s32);
s32 child,next,lock,active;
s8 state;
if(!obj)return;
M2C_FIELD(obj,s16*,0x70)=0;
state=M2C_FIELD(obj,s8*,0x73);active=1;
if(state!=0 && state!=4)active=0;
if(active){
func_02020e90(M2C_FIELD(obj,s32*,0x68));func_02020e90(M2C_FIELD(obj,s32*,0x64));
}else if(state==1){
child=M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s32*,0x104);
while(child){next=M2C_FIELD(child,s32*,0); M2C_FIELD(data_020faf98,void (**)(s32),0x1c)(child);child=next;}
M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s16*,0x108)=0;
M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s32*,0x100)=0;
M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s32*,0x104)=0;
func_02005df4(M2C_FIELD(obj,s32*,0x64)+0x10c);
func_02020e90(M2C_FIELD(obj,s32*,0x64));
}else if(state==2)func_02020e90(M2C_FIELD(obj,s32*,0x68));
lock=func_0200751c();
func_02021430(obj);func_02021490(obj);
M2C_FIELD(data_020faf98,void (**)(s32),0x1c)(obj);
func_02007530(lock);
}

void func_02020e90(s32 arg0) {
    M2C_UNK func_02005d60(s32);
    M2C_UNK func_02005eac();
    M2C_UNK func_02006130();
    M2C_UNK func_02006164();
    M2C_UNK func_020062fc(s32, M2C_UNK, M2C_UNK);
    s32 func_02006390(s32, void **, M2C_UNK);
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    M2C_UNK func_0201f210(void *);
    void *sp0;
    s32 temp_r0;
    s32 temp_r8;

    if (arg0 == 0) {
        return;
    }
    func_02005d60(arg0 + 0x20);
    temp_r8 = func_0200751c();
    func_02006130();
    if (func_02006390(arg0, &sp0, 0) != 0) {
        do {
            if (sp0 != NULL) {
                temp_r0 = M2C_FIELD(sp0, s32 *, 8);
                if (temp_r0 != 0) {
                    func_020062fc(temp_r0, -0xB, 0);
                }
                func_0201f210(sp0);
            }
        } while (func_02006390(arg0, &sp0, 0) != 0);
    }
    func_02006164();
    func_02005eac();
    func_02007530(temp_r8);
}

M2C_UNK func_02020f30(void) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    M2C_UNK func_02020d90();
    extern M2C_UNK data_02138b30;
    s32 temp_r5 = func_0200751c();
    if (data_02138b30 != 0) {
        do { func_02020d90(); } while (data_02138b30 != 0);
    }
    func_02007530(temp_r5);
}

s32 func_02020f6c(void) {
    M2C_UNK func_02006030(M2C_UNK);
    M2C_UNK func_0201a4f8(s32);
    M2C_UNK func_0201a508();
    s32 func_0201f160();
    extern void *data_020faf98;
    extern s32 data_021372e0;
    extern s32 data_02138ac4;
    extern M2C_UNK data_02138ad0;
    s32 temp_r4;
    if (data_02138ac4 == 0) { data_02138ac4 = data_021372e0; }
    if (func_020210b8() == -0x1A) {
        do { func_02006030(0x64); } while (func_020210b8() == -0x1A);
    }
    temp_r4 = func_0201f160();
    if (temp_r4 >= 0) {
        func_0201a508();
        func_0201a4f8(0);
        if (M2C_FIELD(data_020faf98, s32 *, 0x28) == 0) {
            M2C_FIELD(data_020faf98, void (**)(s32), 0x1C)(M2C_FIELD(&data_02138ad0, s32 *, 0x1C));
        }
        data_020faf98 = NULL;
    }
    return temp_r4;
}

s32 func_02021010(void) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    M2C_UNK func_02020c28(s32);
    extern s32 data_02138acc;
    extern M2C_UNK data_02138b2c;
    extern M2C_UNK data_02138b30;
    s32 var_r6;
    s32 temp_r0;
loop_1:
    temp_r0 = func_0200751c();
    var_r6 = data_02138b2c;
    while (var_r6 != 0) {
        if (var_r6 != data_02138acc && !(M2C_FIELD(var_r6, s16 *, 0x70) & 0x10)) { break; }
        var_r6 = M2C_FIELD(var_r6, s32 *, 0x7C);
    }
    func_02007530(temp_r0);
    if (var_r6 != 0) { func_02020c28(var_r6); goto loop_1; }
    if ((data_02138b2c == 0 || (data_02138b2c == data_02138acc && M2C_FIELD(data_02138b2c, s32 *, 0x7C) == 0)) && data_02138b30 == 0) { return 0; }
    return -0x1A;
}

s32 func_020210b8(void) {
    s32 func_0201a4a8();
    M2C_UNK func_02020c28(s32);
    M2C_UNK func_02020f30();
    s32 func_02021010();
    M2C_UNK func_02029828(M2C_UNK);
    extern s32 data_02138acc;
    s32 var_r4;

    if (data_02138acc != 0) {
        var_r4 = func_02021010();
        if (var_r4 == 0) {
            func_02020c28(data_02138acc);
            if (func_02020bf4(data_02138acc) != 0) {
                data_02138acc = 0;
            }
            var_r4 = -0x1A;
        }
        func_02020f30();
    } else if (func_0201a4a8() == 0) {
        var_r4 = -0x1A;
    } else {
        func_02029828(0);
        var_r4 = 0;
    }
    return var_r4;
}

s32 func_02021134(s32 arg0) {
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d138(void *);
    M2C_UNK func_0201d14c();
    s32 func_0201ed20(s32);
    extern void *data_020faf98;
    u8 sp0[0x64];
    s32 temp_r4;
    s32 temp_r5;
    if (arg0 == 0) { return 0; }
    temp_r4 = M2C_FIELD(data_020faf98, s32 (**)(M2C_UNK), 0x18)(0xFD0);
    if (temp_r4 == 0) { return 0; }
    func_02007f8c(sp0, 0, 0x64);
    M2C_FIELD(sp0, s32 *, 0x40) = temp_r4;
    M2C_FIELD(sp0, s32 *, 0x3C) = 0xB68;
    M2C_FIELD(sp0, s32 *, 0x4C) = temp_r4 + 0xB68;
    M2C_FIELD(sp0, s32 *, 0x48) = 0x466;
    func_0201d138(sp0);
    temp_r5 = func_0201ed20(arg0);
    func_0201d14c();
    M2C_FIELD(data_020faf98, M2C_UNK (**)(s32), 0x1C)(temp_r4);
    return temp_r5;
}

s32 func_020211e4(s32 arg0) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_0201ed20(s32);
    extern M2C_UNK data_021372f0;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    temp_r5 = func_0200751c();
    temp_r6 = M2C_FIELD(&data_021372f0, s32 *, 0);
    temp_r7 = M2C_FIELD(&data_021372f0, s32 *, 4);
    M2C_FIELD(&data_021372f0, s32 *, 0) = 0;
    M2C_FIELD(&data_021372f0, s32 *, 4) = 0;
    temp_r4 = func_0201ed20(arg0);
    M2C_FIELD(&data_021372f0, s32 *, 0) = temp_r6;
    M2C_FIELD(&data_021372f0, s32 *, 4) = temp_r7;
    func_02007530(temp_r5);
    return temp_r4;
}

s32 func_02021230(s32 arg0, s32 arg1) {
    s32 func_02021264();
    extern M2C_UNK data_021372f0;
    if (func_02021264() == 0) {
        return -0x27;
    }
    M2C_FIELD(&data_021372f0, s32 *, 0) = arg0;
    M2C_FIELD(&data_021372f0, s32 *, 4) = arg1;
    return 0;
}

s32 func_02021264(void) {
    M2C_UNK func_02006030(M2C_UNK);
    s32 func_02007580();
    extern s32 data_021372e0;
    extern s32 data_02138ac4;
    extern s32 data_02138ac8;
    if (data_021372e0 == 0) {
        if (((data_02138ac8 & 3) == 1) && (func_02007580() != 0x12)) {
            func_02006030(0xA);
        }
    } else if (data_02138ac4 == 0) {
        data_02138ac4 = data_021372e0;
    }
    return data_021372e0;
}

s32 func_020212cc(void *arg0) {
s32 func_02020714(void *); s32 func_0202139c(void *);
s32 lock, flag, result=0; s8 type;
if(func_020214a8()!=0) result|=0x80;
else {
if(M2C_FIELD(arg0,volatile s16 *,0x70)&0x40) result|=0x20;
if(M2C_FIELD(arg0,s8 *,0x73)==1 || (M2C_FIELD(arg0,volatile s16 *,0x70)&4)){
lock=func_0200751c();
if(func_0202139c(arg0)>0) result|=1;
if(func_02020714(arg0)>0) result|=8;
func_02007530(lock);
}
type=M2C_FIELD(arg0,s8 *,0x73);flag=1;
if(type!=0 && type!=4) flag=0;
if(flag){
if((M2C_FIELD(arg0,volatile s16 *,0x70)&4) && M2C_FIELD(arg0,u8 *,8)!=4){
if(!(result&1)) M2C_FIELD(arg0,volatile s16 *,0x70)&=~6;
}
if(!(M2C_FIELD(arg0,volatile s16 *,0x70)&2) && !(M2C_FIELD(arg0,volatile s16 *,0x70)&4)) result|=0x40;
}
} return result;
}

s32 func_0202139c(void *arg0) {
    s8 temp_r1;
    void *temp_r2;
    void *temp_r0;
    s32 var_r3;
    temp_r2 = M2C_FIELD(arg0, void **, 0x64);
    var_r3 = 0;
    if (temp_r2 != NULL) {
        temp_r1 = M2C_FIELD(arg0, s8 *, 0x73);
        if (temp_r1 == 1) {
            temp_r0 = M2C_FIELD(temp_r2, void **, 0x104);
            if (temp_r0 != NULL) { var_r3 = M2C_FIELD(temp_r0, u16 *, 4); }
        } else if (temp_r1 == 0 || temp_r1 == 4) {
            var_r3 = M2C_FIELD(arg0, s32 *, 0x44) - M2C_FIELD(temp_r2, s32 *, 0xF8);
        }
    }
    return var_r3;
}

s32 func_020213e4(s32 arg0) {
    return (arg0 + 3) & ~3;
}

void func_020213f0(void *arg0) {
    void func_02021408(void **, void *);
    extern M2C_UNK data_02138b2c;
    func_02021408((void **)&data_02138b2c, arg0);
}

void func_02021408(void **arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 0x7C) = (void *) *arg0;
    *arg0 = arg1;
}

void func_02021418(void *arg0) {
    extern M2C_UNK data_02138b30;
    func_02021408((void **)&data_02138b30, arg0);
}

void func_02021430(M2C_UNK arg0) {
    M2C_UNK func_02021448(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02138b2c;
    func_02021448(&data_02138b2c, arg0);
}

s32 func_02021448(s32 *arg0, s32 arg1) {
 void *func_02021464(void *, s32);
 void *p = func_02021464(arg0, arg1);
 if(p) M2C_FIELD(p,s32 *,0)=M2C_FIELD(arg1,s32 *,0x7c);
}

void *func_02021464(void *arg0, s32 arg1);
void *func_02021464(void *arg0, s32 arg1) {
 void *p = M2C_FIELD(arg0, void **, 0);
 while (p) {
  if ((s32)p == arg1) return arg0;
  arg0 = (u8 *)p + 0x7c;
  p = M2C_FIELD(p, void **, 0x7c);
 }
 return NULL;
}

void func_02021490(M2C_UNK arg0) {
    extern M2C_UNK data_02138b30;
    func_02021448(&data_02138b30, arg0);
}

s32 func_020214a8(s32 arg0) {
 extern M2C_UNK data_02138b2c;
 if (arg0 <= 0 || func_02021464(&data_02138b2c, arg0) == NULL) return 1;
 return 0;
}

s32 func_020214dc(s32 arg0) {
 extern M2C_UNK data_02138b30;
 return func_02021464(&data_02138b30, arg0) != NULL;
}

void func_02021500(s32 unused, s32 arg1) {
 M2C_UNK func_0201f400(M2C_UNK *);
 extern M2C_UNK data_020fafa0;
 extern M2C_UNK data_020fafb8;
 if(arg1 == 1) {func_0201f400(&data_020fafb8); return;}
 func_0201f400(&data_020fafa0);
}

void func_0202152c(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_0201f9e4(M2C_UNK, u16);
    u16 temp_r1;

    temp_r1 = M2C_FIELD(arg1, u16 *, 2);
    func_0201f9e4(arg0, (u16) ((u8) ((s32) temp_r1 >> 8) | ((temp_r1 << 8) & 0xFF00)));
}

void func_02021558(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_0201fa54(M2C_UNK, u16, s32);
    u16 temp_r2;
    u32 temp_lr;

    temp_r2 = M2C_FIELD(arg1, u16 *, 2);
    temp_lr = M2C_FIELD(arg1, u32 *, 4);
    func_0201fa54(arg0, (u16) ((u8) ((s32) temp_r2 >> 8) | ((temp_r2 << 8) & 0xFF00)), ((temp_lr << 0x18) & 0xFF000000) | (((temp_lr << 8) & 0xFF0000) | ((u8) (temp_lr >> 0x18) | ((temp_lr >> 8) & 0xFF00))));
}

void func_020215b4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0201fc18(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_0201fc18(arg0, arg1, arg2, 0, 0, 0);
}

void func_020215d4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0201fc18(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_0201fc18(arg0, arg1, arg2, 0, 0, arg3);
}

s32 func_020215f8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, void *arg4) {
 u32 spC; u16 sp8;
 s32 result = func_0201fc18(arg0,arg1,arg2,&sp8,&spC,arg3);
 if(result < 0) return result;
 if(arg4 == NULL) return result;
 M2C_FIELD(arg4,u16 *,2)=((sp8 >> 8)&255)|((sp8 << 8)&0xff00);
 M2C_FIELD(arg4,u32 *,4)=((spC >> 24)&255)|((spC >> 8)&0xff00)|((spC << 8)&0xff0000)|((spC << 24)&0xff000000);
 return result;
}

void func_02021688(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02020478(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_02020478(arg0, arg1, arg2, 0, 0, 0);
}

void func_020216a8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_02020478(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_02020478(arg0, arg1, arg2, 0, 0, arg3);
}

