/* 17 functions from 0x02013B54 to 0x02014B34 (main), found by ds-decomp. */
#include "common.h"

s32 func_02013b54(M2C_UNK arg0, u32 arg1, s32 arg2) {
    M2C_UNK func_020067c4(s32, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg1 > 3U) {
        return 6;
    }
    if (arg1 != 0) {
        if (arg2 == 0) {
            return 6;
        }
        func_020067c4(arg2, 0x50);
        goto block_8;
    }
block_8:
    func_020112b4(0x14, arg0);
    var_r0 = func_02011324(0x14, 2, arg1, arg2);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013bc8(M2C_UNK arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg1 > 3U) {
        return 6;
    }
    if (arg1 != 0) {
        if (arg3 == 0) {
            return 6;
        }
        func_020067c4(arg3, 0x50);
        goto block_8;
    }
block_8:
    func_020112b4(0x27, arg0);
    var_r0 = func_02011324(0x27, 3, arg1, arg3, arg2);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013c44(M2C_UNK arg0, s32 arg1, u32 arg2, s32 arg3, u16 arg4, u8 arg5) {
    M2C_UNK func_02007e20(s32, M2C_UNK *, u32);
    extern M2C_UNK data_02131100;
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(2, 7, 9);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg1 == 0) {
        return 6;
    }
    if (arg2 > 0x70U) {
        return 6;
    }
    func_02007e20(arg1, &data_02131100, arg2);
    func_020067c4(&data_02131100, arg2);
    func_020112b4(0x18, arg0);
    var_r0 = func_02011324(0x18, 5, &data_02131100, arg2, arg3, (s32) arg4, (s32) arg5);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013cfc(M2C_UNK arg0, s32 arg1) {
    s32 func_0201146c();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if ((arg1 != 0) && (arg1 != 1)) {
        return 6;
    }
    func_020112b4(0x19, arg0);
    var_r0 = func_02011324(0x19, 1, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013d4c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, u16 arg4) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(0x1D, arg0);
    var_r0 = func_02011324(0x1D, 4, arg1, arg2, arg3, (s32) arg4);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013dac(s32 arg0,s16 arg1,s16 arg2,s16 arg3,u16 arg4) {
 s32 func_020113d0(s16 *,s32);
 void func_02011440();
 s16 packet[5]; s32 result;
 func_02011440();
 result=func_020114b4(1,2);
 if(result) return result;
 func_020112b4(0x1e,arg0);
 packet[0]=0x1e; packet[1]=arg1; packet[2]=arg2; packet[3]=arg3; packet[4]=arg4;
 result=func_020113d0(packet,10);
 if(!result) result=2;
 return result;
}

s32 func_02013e24(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020112b4(M2C_UNK, M2C_UNK);
    s32 func_02011324(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020114b4(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(2, 7, 9);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(0x21, arg0);
    var_r0 = func_02011324(0x21, 1, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

void func_02013e70(s32 arg0) {
 s32 func_0200751c(); void func_02007530(s32);
 extern s32 data_02136c4c;
 s32 state=func_0200751c();
 M2C_FIELD(data_02136c4c,s32 *,0x14e4)=arg0;
 func_02007530(state);
}

void *func_02013e98(s32 arg0) {
 s32 func_0200751c(); void func_02007530(s32);
 s32 func_02015214(); void func_02008048(void *,void *);
 extern s32 data_02136c4c;
 s32 state=func_0200751c();
 if(data_02136c4c && func_02015214(arg0)) {
 { void *base=(void *)data_02136c4c; void *dest=base+0x1772; void *src=base+0x1340; src+=(arg0-1)*0x16; func_02008048(src,dest); }
 func_02007530(state);
 return (void *)(data_02136c4c+0x1772);
 }
 func_02007530(state); return 0;
}

s32 func_02013f1c(s32 arg0) {
 extern s32 data_02136c4c;
 s32 func_02015214();
 if(data_02136c4c && func_02015214(arg0)) {
 if(M2C_FIELD(data_02136c4c+(arg0-1)*4,s32 *,0x14e8)==7) return 1;
 }
 return 0;
}

s32 func_02013f70(s32 arg0, u32 arg1) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 func_02015214(s32);
    extern s32 data_02136c4c;
    s32 state;
    s32 ret;
    u32 val;
    s32 r5;

    state = func_0200751c();
    switch (arg1) {
        case 0: r5 = 0xa; val = 4; break;
        case 1: r5 = 0xa; val = 3; break;
        case 2: r5 = 0xe; val = 2; break;
        case 3: r5 = 0x7; val = 5; break;
        default:
            func_02007530(state);
            return 0;
    }
    if (data_02136c4c != 0 && func_02015214(arg0) != 0) {
        s32 *base = (s32 *)data_02136c4c;
        s32 idx = arg0 - 1;
        if (r5 == base[idx + 0x14e8 / 4]) {
            *((u16 *)((s8 *)base + idx * 2 + 0x1754)) = (u16)val;
            func_02007530(state);
            return 1;
        }
    }
    func_02007530(state);
    return 0;
}

void func_02014050(s32 arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_0201409c(s32, s32, M2C_UNK);
    s32 func_02015214();
    extern s32 data_02136c4c;
    if (func_02015214() != 0) {
        M2C_FIELD((data_02136c4c + ((arg0 - 1) * 4)), s32 *, 0x14E8) = arg1;
    }
    func_0201409c(arg0, arg1, arg2);
}

M2C_UNK func_0201409c(s32 arg0,s32 arg1,M2C_UNK arg2) {
 extern s32 data_02136c4c;
 void (*callback)(s32,s32,M2C_UNK)=M2C_FIELD(data_02136c4c,void (**)(s32,s32,M2C_UNK),0x14e4);
 if(!callback) return;
 callback(arg0,arg1,arg2);
}

M2C_UNK func_020140c4(s32 a, void *b) {
    (void)a;(void)b;
    return 0;
}

void func_02014564(void *arg0, u16 arg1) {
    void *func_02018a28();
    void func_02008048();
    void func_02014050();
    extern s32 data_02136c4c;
    extern s32 data_02131180;
    s32 func_02015214();

    u16 r6 = arg1;
    u8 stack[0x34];
    u8 type = 0;
    void *r5;
    s32 r4;
    s32 *map;

    if (r6 == 0) return;
    if (r6 > 0x0F) return;

    r5 = func_02018a28((u8 *)arg0 + 10, &type, r6);
    map = (s32 *)data_02136c4c;
    r4 = M2C_FIELD(data_02136c4c + (r6 - 1) * 4, s32 *, 0x14E8);

    switch (type) {
    case 8:
        if (r4 == 2) {
            if (r5 == 0) return;
            func_02008048(r5, stack, 0x1D);
            *(s32 *)((u8 *)map + (r6 - 1) * 4 + 0x14A8) = *(s32 *)stack;
            *(u16 *)((u8 *)map + (r6 - 1) * 2 + 0x148A) = *(u16 *)(stack + 0x1A);
            {
                void *dest = (u8 *)map + 0x1340 + (r6 - 1) * 0x16;
                func_02008048(stack + 4, dest, 0x16);
                *((u8 *)dest) = (u8)((*((u8 *)dest) & 0x0F) | (r6 << 4));
                func_02014050(r6, 0x0A, (M2C_UNK)(stack + 4));
            }
            return;
        }
        break;
    case 9:
    case 10:
    case 11:
    default:
        break;
    }
}

void func_02014a48(s32 arg0) {
 extern s32 data_02136c4c; extern s32 data_02131180;
 void *func_02011c74(s32,u16); void func_02014564(void *,u16);
 u16 i; void *p;
 for(i=0;i<16;i++) {
 p=(void *)(data_02136c4c+i*0x5d4);
 if(M2C_FIELD(p,u8 *,0x1d52)) M2C_FIELD(p,u16 *,0x1d4a)=0;
 }
 data_02131180=0;
 for(i=1;i<=15;i++) {
 p=func_02011c74(arg0,i);
 if(p && M2C_FIELD(p,u16 *,0)!=0xffff && M2C_FIELD(p,u16 *,0)!=0) func_02014564(p,i);
 }
}

void func_02014af4(u8 arg0,s32 arg1) {
 void func_020189a4(u8 *,s32); void func_02015f10(s32,s32,s32);
 extern s32 data_02136c4c;
 u8 packet[8];
 packet[0]=arg0;
 func_020189a4(packet,data_02136c4c);
 func_02015f10(6,arg1,data_02136c4c);
}

