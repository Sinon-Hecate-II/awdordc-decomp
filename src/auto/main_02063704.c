/* 22 functions from 0x02063704 to 0x02064684 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 b[2]; } Bytes2;
typedef struct { u8 b[4]; } Bytes4;
static inline void Copy2(void *d,const void *s) { *(Bytes2 *)d=*(const Bytes2 *)s; }
static inline void Copy4(void *d,const void *s) { *(Bytes4 *)d=*(const Bytes4 *)s; }

typedef struct M2C_S_02063BD0 {
    u32 field_0;
} M2C_S_02063BD0;

/* Add (or update) an entry parsed from the input buffer. */
s32 func_02063704(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_02061090(void *, s32, u16);
    s32 func_02061168();
    M2C_UNK func_02061a38(void *, s32);
    s32 func_02061ac8(void *, s32, u16);
    s32 func_02061bc8(void *, s32);
    M2C_UNK func_020629bc(void *, M2C_UNK, s32, s32 *, u16 *);
    s32 func_02062a2c(void *, s32, M2C_UNK, s32, s32);
    s32 entry;
    u16 kind;
    s32 found;
    s32 count;

    if (arg2 < 5) {
        return 4;
    }
    func_020629bc(arg0, arg1, arg2, &count, &kind);
    found = func_02061ac8(arg0, count, kind);
    if (found == -1) {
        entry = func_02061090(arg0, count, kind);
        if (func_02061168() != 0) {
            return 5;
        }
        goto apply;
    }
    entry = func_02061bc8(arg0, found);
apply:
    if (func_02062a2c(arg0, entry, arg1, arg2, 0) < 0) {
        return 4;
    }
    if (found == -1) {
        func_02061a38(arg0, entry);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK, s32, s32), 0x488)(arg0, 1, entry, M2C_FIELD(arg0, s32 *, 0x494));
    return 0;
}

#pragma scheduling off
s32 func_020637fc(void *arg0) {
    s32 func_02049810(s32, void *, s32, s32);
    M2C_UNK func_02061efc(void *);
    s32 func_0206325c(void *, u8 *, s32);
    s32 func_02063338(void *, u8 *, s32);
    s32 func_020634f4(void *, u8 *, s32);
    s32 func_02063678(M2C_UNK, u8 *, s32);
    void func_020640a8(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void func_020651c4(void *, void *, s32);
    extern u8 data_021001b4[], data_0210012c[], data_021000d8[];
    s32 result = 0;
    s32 zero = 0;
    u16 size;
    u8 *hdr;
    u8 *buf;

    hdr = (u8 *) &size;
    while (M2C_FIELD(arg0, s32 *, 0x80) >= 3) {
        Copy2(hdr, M2C_FIELD(arg0, void **, 0x7C));
        size = (u8) (size >> 8) | ((size << 8) & 0xff00);
        if (size > 0x1000) {
            result = 4;
            break;
        }
        if (M2C_FIELD(arg0, s32 *, 0x80) < size) {
            return 0;
        }
        buf = M2C_FIELD(arg0, u8 **, 0x7C);
        switch (((s8 *) buf)[2]) {
        case 1:
            result = func_0206325c(arg0, buf + 3, size - 3);
            break;
        case 2:
            result = func_02063704(arg0, buf + 3, size - 3);
            break;
        case 3:
            if (func_02049810(M2C_FIELD(arg0, s32 *, 0x4B0), buf, size, zero) <= 0) {
                return 3;
            }
            break;
        case 4:
            result = func_02063678(arg0, buf + 3, size - 3);
            break;
        case 5:
            result = func_020634f4(arg0, buf + 3, size - 3);
            break;
        case 6:
            result = func_02063338(arg0, buf + 3, size - 3);
            break;
        }
        if ((M2C_FIELD(arg0, s32 *, 0x80) -= size) < 0) {
            func_020640a8((M2C_UNK) data_021001b4, (M2C_UNK) data_0210012c, (M2C_UNK) data_021000d8, 0x5B4);
        }
        if (M2C_FIELD(arg0, s32 *, 0x80) != 0 && M2C_FIELD(arg0, u8 **, 0x7C) != NULL) {
            func_020651c4(M2C_FIELD(arg0, u8 **, 0x7C), M2C_FIELD(arg0, u8 **, 0x7C) + size,
                          M2C_FIELD(arg0, s32 *, 0x80));
        }
        if (result != 0) {
            break;
        }
    }
    if (result != 0) {
        func_02061efc(arg0);
    }
    return result;
}
#pragma scheduling reset
s32 func_020639c0(void *arg0) {
    s32 func_02049534(s32);
    s32 func_020497cc(s32, s32, s32, M2C_UNK);
    M2C_UNK func_0206006c(void *, s32, s32);
    M2C_UNK func_02061efc(void *);
    s32 func_02062e30(void *);
    s32 func_020637fc(void *);
    s32 temp_r0;
    s32 var_r4;
    s32 temp_r5;

    if (func_02049534(M2C_FIELD(arg0, s32 *, 0x4B0)) == 0) {
        return 0;
    }
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x80);
    temp_r0 = func_020497cc(M2C_FIELD(arg0, s32 *, 0x4B0), M2C_FIELD(arg0, s32 *, 0x7C) + temp_r5, 0x1000 - temp_r5, 0);
    if ((u32) (temp_r0 + 1) <= 1U) {
        func_02061efc(arg0);
        return 3;
    }
    var_r4 = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = M2C_FIELD(arg0, s32 *, 0x80) + temp_r0;
    if (M2C_FIELD(arg0, s32 *, 0) == 2) goto skip_block;
    if (M2C_FIELD(arg0, s32 *, 0x5C8) <= 0) goto skip_block;
    func_0206006c((u8 *)arg0 + 0x4BC, M2C_FIELD(arg0, s32 *, 0x7C) + temp_r5, M2C_FIELD(arg0, s32 *, 0x80) - temp_r5);
skip_block:
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        var_r4 = func_02062e30(arg0);
    }
    if (var_r4 != 0) {
        return var_r4;
    }
    if (M2C_FIELD(arg0, s32 *, 0) == 2 && M2C_FIELD(arg0, s32 *, 0x80) > 0) {
        return func_020637fc(arg0);
    }
    return 0;
}

#pragma scheduling off
s32 func_02063aa8(void *arg0,u32 arg1,u32 arg2,void *arg3,s32 arg4) {
s32 func_02049810(s32,void *,s32,s32);s32 func_02062324(void *,void *,s32);s32 func_020623bc(void *,s32,s32,s32,s32);
u8 packet[16]; u16 size; u16 temp; s32 result;
if(M2C_FIELD(arg0,s32 *,0)==1) {
func_020623bc(arg0,0,0,2,0);
}
if(M2C_FIELD(arg0,s32 *,0)==1)return 3;
temp=arg4+9;size=(u8)(temp>>8)|((temp<<8)&0xff00);
packet[0]=((u8 *)&size)[0]; packet[1]=((u8 *)&size)[1];
packet[3]=((u8 *)&arg1)[0];packet[4]=((u8 *)&arg1)[1];packet[5]=((u8 *)&arg1)[2];packet[6]=((u8 *)&arg1)[3];packet[7]=((u8 *)&arg2)[0];packet[8]=((u8 *)&arg2)[1];
packet[2]=2;
result=func_02062324(arg0,packet,9);if(result)return result;
return func_02049810(M2C_FIELD(arg0,s32 *,0x4b0),arg3,arg4,0)<0?3:0;
}

void func_02063bd0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02063aa8(void *, u32, u32, void *, s32);
    u32 sp44;
    M2C_UNK spA;
    s8 sp9;
    s8 sp8;
    s8 sp7;
    s8 sp6;
    s8 sp5;
    s8 sp4;

    sp7 = 0x66;
    sp44 = ((sp44 << 0x18) & 0xFF000000) | (((sp44 << 8) & 0xFF0000) | ((u8) (sp44 >> 0x18) | ((sp44 >> 8) & 0xFF00)));
    sp4 = 0xFD;
    sp5 = 0xFC;
    sp6 = 0x1E;
    sp8 = 0x6A;
    sp9 = 0xB2;
    M2C_FIELD(&spA, u8 *, 0) = (u8) M2C_FIELD(&sp44, u8 *, 0);
    M2C_FIELD(&spA, u8 *, 1) = (u8) M2C_FIELD(&sp44, u8 *, 1);
    M2C_FIELD(&spA, u8 *, 2) = (u8) M2C_FIELD(&sp44, u8 *, 2);
    M2C_FIELD(&spA, u8 *, 3) = (u8) M2C_FIELD(&sp44, u8 *, 3);
    func_02063aa8((void *)arg0, (u32)arg1, (u32)arg2, (void *)&sp4, 0xA);
}

#pragma scheduling reset
extern s32 data_0213e4b4[];
s32 func_02063c88(void *arg0) {
s32 func_02049534(s32); s32 func_020497e0(s32,void *,s32,s32,void *,s32 *);
s32 func_02061ac8(void *,s32,u16); s32 func_02061090(void *,s32,u16); s32 func_02061168(void);
void func_0206113c(s32,s32); s32 func_02061a38(void *,s32); u32 func_02049208(void); void func_020496b8(s32);
u8 buf[0x5dc]; u16 addr[4]; s32 len=8; s32 entry;
while(func_02049534(M2C_FIELD(arg0,s32 *,0x4b0))) {
if(func_020497e0(M2C_FIELD(arg0,s32 *,0x4b0),buf,0x5db,0,addr,&len)!=-1 &&
func_02061ac8(arg0,*(s32 *)(addr+2),addr[1])==-1) {
entry=func_02061090(arg0,*(s32 *)(addr+2),addr[1]); if(func_02061168())return 5;
func_0206113c(entry,17);func_02061a38(arg0,entry);
}}
if(func_02049208()-M2C_FIELD(arg0,u32 *,0x4b4)>2000) {
func_020496b8(M2C_FIELD(arg0,s32 *,0x4b0));M2C_FIELD(arg0,s32 *,0x4b0)=-1;M2C_FIELD(arg0,s32 *,0)=1;
M2C_FIELD(arg0,void (**)(void *,s32,s32,s32),0x488)(arg0,3,data_0213e4b4[0],M2C_FIELD(arg0,s32 *,0x494));
}return 0; }

s32 func_02063dac(void *arg0) {
    void func_02061bdc(void *);
    s32 func_020639c0(void *);
    s32 func_02063c88(void *);
    s32 temp_r0;

    func_02061bdc(arg0);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_r0) {
    case 2:
    case 3:
        return func_020639c0(arg0);
    case 0:
        return func_02063c88(arg0);
    case 1:
    default:
        return 0;
    }
}

M2C_UNK func_02063df8(void) {
    M2C_UNK func_02068b04(M2C_UNK);
    void func_02063e1c(M2C_UNK);
    extern M2C_UNK data_0213e4c4;
    func_02068b04(1);
    M2C_FIELD(&data_0213e4c4, s32 *, 0xC) = 1;
    func_02063e1c(1);
}

void func_02063e1c(M2C_UNK arg0) {
    M2C_UNK func_02063e68(M2C_UNK);
    M2C_UNK func_02074074();
    extern M2C_UNK data_0213e4c4;
    if (M2C_FIELD(&data_0213e4c4, s32 *, 0xC) == 0) {
        func_02074074();
        if (M2C_FIELD(&data_0213e4c4, M2C_UNK (**)(), 4) != NULL) {
            M2C_FIELD(&data_0213e4c4, M2C_UNK (**)(), 4)();
            M2C_FIELD(&data_0213e4c4, M2C_UNK (**)(), 4) = NULL;
        }
    }
    func_02063e68(arg0);
}

#pragma opt_common_subs off
M2C_UNK func_02063e68(M2C_UNK arg0){
s32 func_02006680(void*);M2C_UNK func_02006564();M2C_UNK func_020065e8();
M2C_UNK func_020649a8(s32);M2C_UNK func_020746f0(void);
extern u8 data_0213e61c[];extern M2C_UNK data_0212dca4,data_0213e4c4,data_0213e4d4;
extern s32 data_0213e5d4[],data_0213e5f8[];
s32 n;M2C_UNK (*cb)(void);void *thread;s32 owner;
if(!func_02006680(data_0213e61c)){
data_0213e5d4[0]=M2C_FIELD(M2C_FIELD(&data_0212dca4,void**,4),s32*,108);data_0213e5f8[0]=1;
}else if((thread=M2C_FIELD(&data_0212dca4,void**,4),owner=data_0213e5d4[0],owner==M2C_FIELD(thread,s32*,108))){
data_0213e5f8[0]++;
}else{
func_02006564(data_0213e61c);
data_0213e5d4[0]=M2C_FIELD(M2C_FIELD(&data_0212dca4,void**,4),s32*,108);data_0213e5f8[0]=1;
}
while(M2C_FIELD(&data_0213e4c4,s32*,8)>0){
n=M2C_FIELD(&data_0213e4c4,s32*,8)-1;
cb=((M2C_UNK (**)(void))&data_0213e4d4)[n];
M2C_FIELD(&data_0213e4c4,s32*,8)=n;cb();
}
if(--data_0213e5f8[0]==0)func_020065e8(data_0213e61c);
if(M2C_FIELD(&data_0213e4c4,M2C_UNK (**)(void),0)){
M2C_FIELD(&data_0213e4c4,M2C_UNK (**)(void),0)();M2C_FIELD(&data_0213e4c4,M2C_UNK (**)(void),0)=0;
}
func_020649a8(0);func_020746f0();
}
#pragma opt_common_subs reset
void func_02063f90(void) {
    M2C_UNK func_0207191c(s32);
    extern s32 data_021002ec;
    func_0207191c(data_021002ec);
}

#pragma opt_strength_reduction off
s32 func_02063fa8(void){
s32 func_020649a8(s32);extern u8 data_021001cc[];
u8 *p=data_021001cc;s32 result=0,i=1;u8 *base=p;s32 zero=result;
do{ s32 v;u32 a;v=M2C_FIELD(p,s32*,4);a=(u32)(v<<22)>>29;
if(a && (((u32)(v<<25)>>30)&1)){u32 b=(u32)(M2C_FIELD(p,s32*,8)<<29)>>29;if(b==1 && ((s32 (*)(void*,u32,u32))func_020649a8)(p,b,a))result=-1;}
if(i>=3)p=0;else{ s32 off=i*76;i++;p=(u8*)&data_021001cc+off;}
}while(p);
return result;
}
#pragma opt_strength_reduction on

#pragma opt_strength_reduction off
#pragma peephole off
s32 func_02064034(void) {
s32 func_020649a8(s32);
extern u8 data_021001cc[];
void *p; s32 result; s32 i; s32 offset;
p=data_021001cc; result=0; i=1;
do {
if (((u32)(M2C_FIELD(p,u32 *,4)<<22)>>29)!=0 && func_020649a8((s32)p)) result=-1;
if(i<3) {offset=i*0x4c; i++; p=data_021001cc+offset;} else p=NULL;
}while(p);
return result;
}
#pragma peephole reset
#pragma opt_strength_reduction reset

s32 func_0206409c(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    return var_r0;
}

void func_020640a8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_02063df8();
    M2C_UNK func_0206743c(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_021002b0;
    func_0206743c(&data_021002b0, arg0, arg1, arg2, arg3);
    func_02063df8();
}

void func_020640e4(M2C_UNK a, M2C_UNK *b) {
}

void func_020640e8(M2C_UNK, M2C_UNK *) {

}

void func_020640ec(void *arg0) {
    s32 temp_r3;

    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    temp_r3 = M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r3;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (temp_r3 - (M2C_FIELD(arg0, s32 *, 0x18) & M2C_FIELD(arg0, s32 *, 0x2C)));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
}

s32 func_0206411c(void *arg0, M2C_UNK *arg1, M2C_UNK arg2) {
    M2C_UNK temp_r0;

    func_020640ec(arg0);
    if (arg2 == 1) {
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x20);
    }
    temp_r0 = M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK), 0x3C)(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 0x1C), &M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x48));
    if (temp_r0 == 2) {
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
    }
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(arg0, s32 *, 0x28);
    }
    if (temp_r0 != 0) {
        return temp_r0;
    }
    M2C_FIELD(arg0, s32 *, 0x18) += M2C_FIELD(arg0, s32 *, 0x28);
    if (((u32) M2C_FIELD(arg0, s32 *, 4) << 0x13) >> 0x1F == 0) {
        func_020640e8(M2C_FIELD(arg0, s32 *, 0x1C), &M2C_FIELD(arg0, s32 *, 0x28));
    }
    return 0;
}

s32 func_020641a8(void *arg0, M2C_UNK *arg1) {
    void func_020640ec(void *);

    s32 temp_r2 = M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s32 *, 0x1C);
    M2C_UNK temp_r0;
    if (temp_r2 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r2;
    if ((((u32)M2C_FIELD(arg0, s32 *, 0x04) << 0x13) >> 0x1F) == 0) {
        func_020640e4(M2C_FIELD(arg0, M2C_UNK *, 0x1C), &M2C_FIELD(arg0, s32 *, 0x28));
    }
    temp_r0 = M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK), 0x40)(M2C_FIELD(arg0, M2C_UNK *, 0x00), M2C_FIELD(arg0, M2C_UNK *, 0x1C), &M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, M2C_UNK *, 0x48));
    if (arg1 != (M2C_UNK *)0) {
        *arg1 = M2C_FIELD(arg0, s32 *, 0x28);
    }
    if (temp_r0 != 0) {
        return temp_r0;
    }
    M2C_FIELD(arg0, s32 *, 0x18) += M2C_FIELD(arg0, s32 *, 0x28);
    func_020640ec(arg0);
    return 0;
}

s32 func_02064230(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, void *arg3) {
    s32 func_02006680(void *);
    M2C_UNK func_02006564();
    M2C_UNK func_020065e8();
    s32 func_0206433c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u8 data_021001cc[];
    extern u8 data_0213e61c[];
    extern M2C_UNK data_0212dca4;
    extern s32 data_0213e5d4[];
    extern s32 data_0213e5f8[];

    u32 n;
    s32 result;
    void *thread;
    s32 owner;

    if (arg3 == (void *)data_021001cc) {
        n = 2;
    } else {
        n = 5;
    }

    if (func_02006680(data_0213e61c + n * 24) == 0) {
        data_0213e5d4[n] = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), s32 *, 0x6C);
        data_0213e5f8[n] = 1;
    } else if ((thread = M2C_FIELD(&data_0212dca4, void **, 4),
               owner = data_0213e5d4[n],
               owner == M2C_FIELD(thread, s32 *, 0x6C))) {
        data_0213e5f8[n]++;
    } else {
        func_02006564(data_0213e61c + n * 24);
        data_0213e5d4[n] = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), s32 *, 0x6C);
        data_0213e5f8[n] = 1;
    }

    result = func_0206433c(arg0, arg1, arg2, arg3);

    if (--data_0213e5f8[n] == 0) {
        func_020065e8(data_0213e61c + n * 24);
    }

    return result;
}

