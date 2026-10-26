/* 47 functions from 0x02229D0C to 0x0222A9DC (ov010), found by ds-decomp. */
#include "common.h"
typedef struct { u8 value; } UnkA750Flag;
typedef struct { u32 flag:1; u32 rest:31; } UnkA750Bits;

void func_ov010_02229d0c(s32 arg0) {
extern M2C_UNK data_ov010_0222eee0;
M2C_FIELD(&data_ov010_0222eee0, void **, 0x18) = NULL;
}

void func_ov010_02229d20(void *arg0) {
    M2C_UNK func_ov010_02229c0c(void *, s32);
    func_ov010_02229c0c(arg0 + 0x38, M2C_FIELD(arg0, s32 *, 0x34));
}

void func_ov010_02229d34(s32 arg0) {
    M2C_UNK func_ov010_02229c74(s32);
    func_ov010_02229c74(arg0 + 0x38);
}

void func_ov010_02229d44(s32 arg0) {
    void func_ov010_02229d0c(s32);
    func_ov010_02229d0c(arg0 + 0x38);
}

M2C_UNK **func_ov010_02229d54(s32 arg0, M2C_UNK arg1) {
M2C_UNK **func_01ffa42c(M2C_UNK *, M2C_UNK);
s32 func_ov010_022282b4(M2C_UNK);
extern M2C_UNK data_ov010_0222c250;
extern M2C_UNK data_ov010_0222c394;
M2C_UNK **temp_r0;
if (func_ov010_022282b4(3) == 0) return NULL;
temp_r0 = func_01ffa42c(&data_ov010_0222c250, arg1);
if (temp_r0 != NULL) {
*temp_r0 = &data_ov010_0222c394;
M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
}
return temp_r0;
}

M2C_UNK func_ov010_02229d9c(s32 arg0) {
    s32 func_ov010_02229a08();
    s8 func_ov010_02229a94();
    extern M2C_UNK data_ov010_0222eee0;
    if (func_ov010_022282b4(3) == 0) return;
    M2C_FIELD(arg0, u16 *, 2) = 1 << func_ov010_02229a08();
    M2C_FIELD(arg0, u8 *, 0) = func_ov010_02229a94();
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x24) = arg0;
}

s32 func_ov010_02229ddc(s32 arg0){s32 func_ov010_02229a24();s32 func_ov010_022282f8();extern M2C_UNK data_ov010_0222eee0;s32 v,b,t;
if(M2C_FIELD(&data_ov010_0222eee0,void * volatile *,0x24)){v=func_ov010_02229a24();t=func_ov010_02229a24();if(v!=(M2C_FIELD(M2C_FIELD(&data_ov010_0222eee0,void **,0x24),u16 *,2)&t)){v=1;goto ready;}}v=0;ready:;
if(!M2C_FIELD(M2C_FIELD(&data_ov010_0222eee0,void **,0x24),u8 *,0))v=0;
if(!func_ov010_022282b4(3))v=0;
if(func_ov010_022282f8())b=1;else b=0;if(b)v=0;if(!v)func_ov010_02229bdc();return v;}

void func_ov010_02229e70(s32 arg0) {
extern M2C_UNK data_ov010_0222eee0;
M2C_FIELD(&data_ov010_0222eee0, void **, 0x24) = NULL;
}

void func_ov010_02229e84(s32 arg0) {
    M2C_UNK func_ov010_02229d9c(s32);
    func_ov010_02229d9c(arg0 + 0x34);
}

void func_ov010_02229e94(s32 arg0) {
    M2C_UNK func_ov010_02229ddc(s32);
    func_ov010_02229ddc(arg0 + 0x34);
}

void func_ov010_02229ea4(s32 arg0) {
    void func_ov010_02229e70(s32);
    func_ov010_02229e70(arg0 + 0x34);
}

M2C_UNK **func_ov010_02229eb4(M2C_UNK arg0) {
    M2C_UNK **func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_ov010_022282b4(M2C_UNK);
    extern M2C_UNK data_ov010_0222c288;
    extern M2C_UNK data_ov010_0222c380;
    M2C_UNK **temp_r0;

    if (func_ov010_022282b4(3) == 0) {
        return NULL;
    }
    temp_r0 = func_01ffa42c(&data_ov010_0222c288, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov010_0222c380;
    }
    return temp_r0;
}

s32 func_ov010_02229ef4(s32 a,s32 b,s32 c,s32 d,s32 e){s32 func_02036ec0(s32,s32,s32,s32,s32,s32,s32);if(!func_ov010_022282b4(1))return 0;func_02007f8c(d,0,b);M2C_FIELD(e,s32 *,0)=0;return func_02036ec0(a,b,0,c,d,e,255);}

s32 func_ov010_02229f64(void) {
    u32 func_02036f14();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 0;
    temp_r0 = func_02036f14();
    switch (temp_r0) {
    case 0:
    case 2:
    case 3:
        break;
    default:
        break;
    case 1:
        var_r4 = 1;
        break;
    }
    return var_r4;
}

void func_ov010_02229f98(void *arg0) {
    M2C_UNK func_ov010_02229ef4(s32, s32, s32, s32, s32);
    func_ov010_02229ef4(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_ov010_02229fc0(void) {
    M2C_UNK func_ov010_02229f64();
    func_ov010_02229f64();
}

void func_ov010_02229fcc(void) {

}

void *func_ov010_02229fd0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    extern M2C_UNK data_ov010_0222c2c0;
    extern M2C_UNK data_ov010_0222c3e4;
    void *temp_r0;

    if (func_ov010_022282b4(1) == 0) {
        return NULL;
    }
    temp_r0 = func_01ffa42c(&data_ov010_0222c2c0, arg5);
    if (temp_r0 == NULL) {
        return temp_r0;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov010_0222c3e4;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg4;
    return temp_r0;
}

void func_ov010_0222a038(void) {

}

s32 func_ov010_0222a03c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void *func_ov010_0222a050(void *arg0) {
    M2C_UNK func_ov010_02229580();
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_ov010_02229580();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    return arg0;
}

void *func_ov010_0222a078(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_ov010_02229580();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    func_02082040(arg0);
    return arg0;
}

s32 func_ov010_0222a0a8(s32 arg0) {
    M2C_UNK func_020741c4(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov010_02228a48;
    func_020741c4(arg0 + 0x34, 4, 8, &func_ov010_02228a48);
    return arg0;
}

s32 func_ov010_0222a0d0(s32 arg0) {
    M2C_UNK func_020741c4(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov010_02228a48;
    func_020741c4(arg0 + 0x34, 4, 8, &func_ov010_02228a48);
    func_02082040(arg0);
    return arg0;
}

void func_ov010_0222a100(void) {

}

s32 func_ov010_0222a104(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_0222a118(void) {

}

s32 func_ov010_0222a11c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_0222a130(void) {

}

s32 func_ov010_0222a134(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_0222a148(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_ov010_0222a15c(void *arg0){s32 func_ov010_022282f8();s32 func_ov010_02228314(s32 *,u32 *);s32 sp4;u32 sp0;void (*fn)(s32,s32,u32,s32);s32 v,b;
if(func_ov010_022282f8())b=1;else b=0;if(!b)return;v=func_ov010_02228314(&sp4,&sp0);if(func_ov010_022282b4(6))return;
switch(sp0){case 0:break;case 1:case 2:case 3:case 4:case 5:case 6:case 7:func_ov010_02228298(6);fn=M2C_FIELD(arg0,void (**)(s32,s32,u32,s32),0x34);if(!fn)return;fn(v,sp4,sp0,M2C_FIELD(arg0,s32 *,0x18));break;default:break;}}

void func_ov010_0222a20c(s32 arg0) {
    void *func_01ffa3dc(void *);
    extern M2C_UNK data_ov010_0222c544, data_ov010_0222c900;
    void *temp_r0;
    temp_r0 = func_01ffa3dc(&data_ov010_0222c544);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, void **, 0) = &data_ov010_0222c900;
        M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    }
}

void func_ov010_0222a238(void) {
    M2C_UNK func_01ffaa5c();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (func_01ffa770(&data_ov010_0222c544) == 0) {
        return;
    }
    func_01ffaa5c();
}

void func_ov010_0222a258(void) {
    M2C_UNK func_01ffaa6c();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (func_01ffa770(&data_ov010_0222c544) == 0) {
        return;
    }
    func_01ffaa6c();
}

void func_ov010_0222a278(void) {
    M2C_UNK func_01ffa574();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (func_01ffa770(&data_ov010_0222c544) == 0) {
        return;
    }
    func_01ffa574();
}

u8 func_ov010_0222a298(void) {
    s32 func_020ad3f0();
    u8 var_r0;

    if (func_020ad3f0() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov010_0222a2b4(void *arg0) {
    s32 func_020abe90(M2C_UNK);
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 1) && (func_020abe90(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 2)) {
        return;
    }
    if (func_020abe90(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

void func_ov010_0222a694(void *arg0){u32 v;if(!M2C_FIELD(arg0,s32 *,0x38))return;v=M2C_FIELD(arg0,u32 *,0x40);switch(v){case 0:case 1:case 2:func_ov010_0222a258();return;default:func_ov010_0222a258();return;case 3:case 4:case 5:case 6:case 7:return;}}

void func_ov010_0222a6e4(void *arg0) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (func_020abe90(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
    }
    if (func_020abe90(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
}

void func_ov010_0222a750(void *a,void *b,void *c){s32 func_02068c34(void *);void *func_0206fc18(void *,s32,s32,void *,void *,UnkA750Flag);u32 i,n; void *p; s32 len;UnkA750Flag flags[2];void *r;
for(i=0;i<3;i++)((u32 *)a)[i]=0;len=func_02068c34(c);if(((UnkA750Bits *)b)->flag){p=M2C_FIELD(b,void **,8);n=M2C_FIELD(b,u32 *,4);}else{p=b+1;n=(u32)(M2C_FIELD(b,u8 *,0)<<24)>>25;}
func_0206fa3c(a,n+len);r=func_0206fc18(a,0,0,p,p+n,flags[1]);func_0206fc18(r,n,0,c,c+len,flags[0]);}

M2C_UNK func_ov010_0222a808(s8 a,u16 b,s32 c,s32 d,u32 e,void *f){extern M2C_UNK data_ov010_0222c58c,data_ov010_0222c914;u32 i;u32 *out;void *p;if(!c)return;p=func_01ffa444(&data_ov010_0222c58c,f);if(!p)return;M2C_FIELD(p,void **,0)=&data_ov010_0222c914;M2C_FIELD(p,u8 *,0x34)=0;M2C_FIELD(p,s8 *,0x35)=a;M2C_FIELD(p,u16 *,0x36)=b;M2C_FIELD(p,s32 *,0x38)=c;M2C_FIELD(p,s32 *,0x3c)=d;M2C_FIELD(p,u32 *,0x40)=e;out=p+0x44;for(i=0;i<3;i++)out[i]=0;}

void func_ov010_0222a880(void *arg0) {
    s32 func_020abe90(M2C_UNK);
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 1) && (func_020abe90(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 2)) {
        return;
    }
    if (func_020abe90(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

void func_ov010_0222a8ec(void *a){M2C_UNK func_ov010_0222ba94(s32,u16,void *);if(!M2C_FIELD(a,volatile s32 *,0x38))return;func_ov010_0222a808(M2C_FIELD(a,s8 *,0x35),M2C_FIELD(a,u16 *,0x36),M2C_FIELD(a,s32 *,0x38),M2C_FIELD(a,s32 *,0x3c),M2C_FIELD(a,u32 *,0x40),a);
switch(M2C_FIELD(a,u32 *,0x40)){case 0:case 1:case 2:break;case 3:case 4:case 5:case 6:case 7:func_ov010_0222ba94(-1,M2C_FIELD(a,u16 *,0x36),a);break;default:break;}}

void func_ov010_0222a96c(void) {

}

void func_ov010_0222a970(void *arg0) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (func_020abe90(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
    }
    if (func_020abe90(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
}

