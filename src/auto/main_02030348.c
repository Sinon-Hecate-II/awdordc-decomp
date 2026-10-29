/* 27 functions from 0x02030348 to 0x02031290 (main), found by ds-decomp. */
#include "common.h"

s32 func_02030348(void){void *func_0202f48c(s32);s32 func_0202f57c(void);s32 func_02030400(void *);void *p; s32 r;p=func_0202f48c(1);r=func_0202f57c();if(r<4)return func_02030398(r);else if(r<5)return func_020303dc();else if(r==5)return func_020303e4(p);else return func_02030400(p);}

s32 func_02030398(u32 a){switch(a){case 1:return -9;case 0:return -10;case 2:return -8;case 3:return -7;default:return 0;}}

s32 func_020303dc(void) {
    return -6;
}

s32 func_020303e4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xB) == 0) {
        return 0xFFFF3C4D;
    }
    return 0xFFFF3865;
}

s32 func_02030400(void *a){s32 r;u8 t=M2C_FIELD(a,u8 *,0x16);if(t<10){t=M2C_FIELD(a,u8 *,0x14);if(t==3)r=0xffff3864-M2C_FIELD(a,u8 *,0x15);else if(t==4)r=-0xc800-M2C_FIELD(a,u8 *,0x15);else r=0xffff379c-M2C_FIELD(a,u8 *,0x15);}else if(t<13)r=0xffff34e0-M2C_FIELD(a,u8 *,0x15);else {r=M2C_FIELD(a,s32 *,0x10);if(r==0)r=0xffff3cb0-M2C_FIELD(a,u8 *,0x15);else if(r==-1)r=0xffff347c-M2C_FIELD(a,u8 *,0x15);else if(r==-2)r=0xffff3418-M2C_FIELD(a,u8 *,0x15);else if(r==-3)r=0xffff33b4-M2C_FIELD(a,u8 *,0x15);else if(r==-4)r=0xffff30f8-M2C_FIELD(a,u8 *,0x15);else if(r==-5)r=0xffff3094-M2C_FIELD(a,u8 *,0x15);else if(r==-6){u32 code=0xffff3030;r=code-M2C_FIELD(a,u8 *,0x15);}}return r;}

s32 func_02030554(s32 a){void *func_0202f48c(s32);void func_02007e54(s32,void *,s32);s32 func_02030634(void *);s32 func_02030888();s32 func_02030918(void *);s32 func_02030694(void *);u8 *p=func_0202f48c(16);switch(a){case 0:func_02007e54(0,p+0x300,0x144);p[0xd10]=func_02030634(p);break;case 1:p[0xd10]=func_02030888();p[0xd0f]=func_02030918(p);break;case 2:func_02007e54(0,p+0x300,0x144);p[0xd0f]=0;p[0xd10]=func_02030694(p);break;}return p[0xd10];}

s32 func_020305e8(u8 *a){void *func_0202f48c(s32);s32 func_02068eac(void *,void *,s32);extern M2C_UNK data_020ea84c;u32 v=(u32)(M2C_FIELD(func_0202f48c(16),u8 *,0xd0c)<<28)>>28;if(v==0||v==6){if(!func_02068eac(a+12,&data_020ea84c,8))return 8;}return 0;}

s32 func_02030634(void *a){u8 func_02030780(void *);void func_02008048(void *,void *,s32);extern M2C_UNK data_020ea84c;u8 *p=(u8 *)a+0x300;u8 n=func_02030780(a);u32 v;p+=n*36;v=(u32)(M2C_FIELD(a,u8 *,0xd0c)<<28)>>28;if(v==0||v==6){func_02008048(&data_020ea84c,p+4,8);p[3]=8;p[1]=8;n++;}return n;}

s32 func_02030694(void *a){
u8 func_02030780(void *);void func_02008048(void *,void *,s32);
extern M2C_UNK data_020fb224,data_020ea844,data_020ea854;
u8 n;u8 *p;u32 v;
p=(u8*)a+0x300;n=func_02030780(a);
p+=n*36;
v=(u32)(M2C_FIELD(a,u8 *,0xd0c)<<28)>>28;
if(v==0||v==4){func_02008048(&data_020fb224,p+4,8);p[3]=8;p[1]=6;n++;p+=36;}
v=(u32)(M2C_FIELD(a,u8 *,0xd0c)<<28)>>28;
if(v==0||v==7){func_02008048(&data_020ea844,p+4,8);p[3]=8;p[1]=9;n++;p+=36;}
v=(u32)(M2C_FIELD(a,u8 *,0xd0c)<<28)>>28;
if(v==0||v==8){func_02008048(&data_020ea854,p+4,11);p[3]=11;p[1]=10;n++;}
return n;
}

u8 func_02030780(void *arg0) {
    s32 var_r4;
    s32 var_r4_2;
    s8 var_r1;
    u32 temp_r5;
    u8 temp_lr;
    u8 temp_r5_3;
    u8 var_r2;
    u8 var_r6;
    u8 var_r6_2;
    void *temp_r4;
    void *temp_r5_2;
    void *var_ip;
    void *var_r3;

    var_r2 = 0;
    var_r3 = arg0;
    var_r1 = 0;
    var_ip = arg0 + 0x300;
    do {
        temp_r5 = (u32) (M2C_FIELD(arg0, u8 *, 0xD0C) << 0x1C) >> 0x1C;
        if ((temp_r5 != 0) && (temp_r5 != (var_r1 + 1))) {

        } else if (M2C_FIELD(var_r3, u8 *, 0xE7) != 0xFF) {
            var_r6 = 0;
loop_6:
            temp_lr = M2C_FIELD((var_r3 + var_r6), u8 *, 0x40);
            if (temp_lr != 0) {
                temp_r5_2 = var_ip + var_r6;
                var_r6 += 1;
                M2C_FIELD(temp_r5_2, u8 *, 4) = temp_lr;
                if ((u32) var_r6 < 0x20U) {
                    goto loop_6;
                }
            }
            if (var_r6 == 0) {
                var_r4 = 0;
            } else {
                M2C_FIELD(var_ip, u8 *, 3) = var_r6;
                M2C_FIELD(var_ip, s8 *, 1) = var_r1;
                var_r4 = 1;
            }
            if (var_r4 != 0) {
                var_r2 += 1;
                var_ip += 0x24;
            }
            if (M2C_FIELD(var_r3, u8 *, 0xE7) == 1) {
                var_r6_2 = 0;
loop_15:
                temp_r5_3 = M2C_FIELD((var_r3 + var_r6_2), u8 *, 0x60);
                if (temp_r5_3 != 0) {
                    temp_r4 = var_ip + var_r6_2;
                    var_r6_2 += 1;
                    M2C_FIELD(temp_r4, u8 *, 4) = temp_r5_3;
                    if ((u32) var_r6_2 < 0x20U) {
                        goto loop_15;
                    }
                }
                if (var_r6_2 == 0) {
                    var_r4_2 = 0;
                } else {
                    M2C_FIELD(var_ip, u8 *, 3) = var_r6_2;
                    M2C_FIELD(var_ip, s8 *, 1) = (s8) (var_r1 + 3);
                    var_r4_2 = 1;
                }
                if (var_r4_2 != 0) {
                    var_r2 += 1;
                    var_ip += 0x24;
                }
            }
        }
        var_r1 += 1;
        var_r3 += 0x100;
    } while ((s32) var_r1 < 3);
    return var_r2;
}

s32 func_02030888(void *a) {
    u8 n;
    s32 i;
    u8 *p;
    void *q;

    n = 0;
    i = 0;
    if ((s32) M2C_FIELD(a, u8 *, 0xD12) > 0) {
        q = a;
        p = (u8 *) a + 0x447;
        do {
            if ((M2C_FIELD(a + i * 4, u8 *, 0x444) == 0) && ((M2C_FIELD(q, u16 *, 0x4A6) - 1) != ((u32) (*p << 0x19) >> 0x19))) {
                *p &= ~0x80;
                n++;
            } else {
                *p |= 0x80;
            }
            i++;
            p += 4;
            q = (u8 *) q + 0xC0;
        } while (i < (s32) M2C_FIELD(a, u8 *, 0xD12));
    }
    return n;
}

s32 func_02030918(void *a) {
 u8 n;u8 i;u8 r;
 n=M2C_FIELD(a,u8 *,0xd12);r=0;i=0;
 if((u32)n>(u32)i) {
loop:
 if(((u32)(M2C_FIELD(a+i*4,u8 *,0x447)<<24)>>31)==0) r=i;
 else {i++;if((u32)i<n)goto loop;}
 }
 return r;
}

/* Chooses the next result code based on the current mode of the shared state. */
u8 func_0203095c(void) {
    M2C_UNK func_020276b0();
    M2C_UNK func_02027958();
    M2C_UNK func_02027a74();
    u32 func_02027c84();
    void *func_0202f48c(M2C_UNK);
    M2C_UNK func_0202f558(M2C_UNK);
    M2C_UNK func_02030b98(u8);
    u32 mode;
    u8 result;
    void *state;

    state = func_0202f48c(0x10);
    result = 9;
    mode = func_02027c84();
    switch (mode) {
    default:
        break;
    case 3:
        result = M2C_FIELD(state, u8 *, 0xD0E);
        if (((u32) (M2C_FIELD(state, u8 *, 0xD0C) << 0x18) >> 0x1E) == 1) {
            result = 7;
            M2C_FIELD((state + (M2C_FIELD(state, u8 *, 0xD13) * 4)), s8 *, 0x444) = 0;
        } else if (((u32) result >= 3U) && ((u32) result <= 5U)) {
            func_02030b98(result);
        }
        break;
    case 6:
        func_020276b0();
        break;
    case 9:
        func_02027958();
        break;
    case 12:
        func_02027a74();
        func_0202f558(4);
        result = 0x11;
        break;
    case 11:
        func_0202f558(0);
        result = 0x11;
        break;
    }
    return result;
}

s32 func_02030a38(void) {
    void *func_0202f48c(s32);
    s32 func_0202f544(void);
    u32 func_02027c84(void);
    s32 func_02030c78(void *);
    s32 func_02030cc8(void *);
    s32 func_02030db4(void *);
    s32 func_02030edc(void *);
    s32 func_020310c0(void *, s32);
    void *ctx;
    s32 state;
    u32 val;

    ctx = func_0202f48c(0x10);
    state = func_0202f544();
    val = func_02027c84();
    if (state == 2 && val == 3) {
        state = func_02030c78(ctx);
    } else if (state == 6) {
        state = func_020310c0(ctx, state);
    } else if (val == 3 || val == 6) {
        state = func_020310c0(ctx, state);
        if (state != 7) {
            if (state == 3) {
                state = func_02030cc8(ctx);
            } else if (state == 4) {
                state = func_02030db4(ctx);
            } else if (state == 5) {
                state = func_02030edc(ctx);
            }
        }
    }
    return state;
}

void func_02030afc(u32 a){void *func_0202f48c(s32);u8 *p=func_0202f48c(16);u32 v;p+=0xd00;if(a>13)a=13;v=M2C_FIELD(p,u16 *,22);a--;M2C_FIELD(p,u16 *,22)=v|(1<<a);}

s8 func_02030b30(s32 a) {
 void *func_0202f48c(s32);
 u16 mask=M2C_FIELD(func_0202f48c(16),u16 *,0xd16);
 u8 i,n;
 if(!mask)return -1;
 i=0;n=0;
 do {if(mask&(1<<i)){if(n==a)return (s8)i;n++;}i++;}while((u32)i<13U);
 return -1;
}

s32 func_02030b98(u8 mode){
void *func_0202f48c(s32);u64 func_02007004(void);void func_020311e4(s32,s32,s32,s32);
extern u8 data_020ea758[],data_020ea760[];
void *p=func_0202f48c(16);s32 n;
switch(mode){
case 3:M2C_FIELD(p,u64 *,0xcb0)=func_02007004();func_020311e4((s32)data_020ea758,(s32)data_020ea760,M2C_FIELD(p,s8 *,0xd11),0x200000);break;
case 4:M2C_FIELD(p,u64 *,0xcb0)=func_02007004();n=(s16)M2C_FIELD(p,u8 *,0xd0f)*(s16)192;func_020311e4((s32)((u8*)p+0x474+n),(s32)((u8*)p+0x47c+n),M2C_FIELD((u8*)p+n,u16 *,0x4a6)-1,0x300000);break;
case 5:M2C_FIELD(p,u64 *,0xcb0)=func_02007004();func_020311e4((s32)data_020ea758,(s32)((u8*)p+0x304+M2C_FIELD(p,u8 *,0xd0f)*36),M2C_FIELD(p,s8 *,0xd11),0x300000);break;
}
}

s32 func_02030c78(void *a) {
 u64 func_02007004(void);
 void func_020311e4(s32,s32,s32,s32);
 extern u8 data_020ea758[],data_020ea760[];
 M2C_FIELD(a,u64 *,0xcb0)=func_02007004();
 M2C_FIELD(a,s8 *,0xd11)=0;
 M2C_FIELD(a,u64 *,0xcb0)=func_02007004();
 func_020311e4((s32)data_020ea758,(s32)data_020ea760,M2C_FIELD(a,s8 *,0xd11),0x200000);
 return 3;
}

s32 func_02030cc8(void *a) {
 u64 func_02007004(void);
 void func_020311e4(s32,s32,s32,s32);
 s32 func_02030ffc(void *,s32);
 u64 func_02072088(u64,u64);
 extern u8 data_020ea758[],data_020ea760[];
 if(func_02072088((func_02007004()-M2C_FIELD(a,u64 *,0xcb0))<<6,0x82eaULL)>=300ULL){
 M2C_FIELD(a,s8 *,0xd11)+=2;
 if(M2C_FIELD(a,s8 *,0xd11)>=13)return func_02030ffc(a,3);
 M2C_FIELD(a,u64 *,0xcb0)=func_02007004();
 func_020311e4((s32)data_020ea758,(s32)data_020ea760,M2C_FIELD(a,s8 *,0xd11),0x200000);
 }
 return 3;
}

s32 func_02030d6c(void *a) {
 u8 t;
 M2C_FIELD(a,u8 *,0xd15)=0;
 t=M2C_FIELD(a,u8 *,0xd0b);
 M2C_FIELD(a,u8 *,0xd0b)=(t&~0xf0)|((u32)((u8)(((u32)(t<<24)>>28)+1)<<28)>>24);
 func_02030554(0);
 M2C_FIELD(a,s8 *,0xd11)=1;
 return 3;
}

s32 func_02030db4(void *a){
void func_020311e4(s32,s32,s32,s32);u64 func_02007004(void);u64 func_02072088(u64,u64);s32 off;
if(func_02072088((func_02007004()-M2C_FIELD(a,u64 *,0xcb0))<<6,0x82eaULL)>=150ULL || (u32)(M2C_FIELD(a+M2C_FIELD(a,u8 *,0xd0f)*4,u8 *,0x447)<<24)>>31 ==1){
M2C_FIELD(a+0x447,u8 *,M2C_FIELD(a,u8 *,0xd0f)*4)|=128;
while(M2C_FIELD(a,u8 *,0xd0f)<M2C_FIELD(a,u8 *,0xd12)){
if(!((u32)(M2C_FIELD(a+M2C_FIELD(a,u8 *,0xd0f)*4,u8 *,0x447)<<24)>>31))break;
M2C_FIELD(a,u8 *,0xd0f)++;
}
if(M2C_FIELD(a,u8 *,0xd12)<=M2C_FIELD(a,u8 *,0xd0f)){M2C_FIELD(a,u8 *,0xd0f)=0;return func_02030ffc(a,4);}
M2C_FIELD(a,u64 *,0xcb0)=func_02007004();
off=(s16)M2C_FIELD(a,u8 *,0xd0f)*(s16)192;
func_020311e4((s32)(a+0x474+off),(s32)(a+0x47c+off),M2C_FIELD(a+off,u16 *,0x4a6)-1,0x300000);
}return 4;}

s32 func_02030edc(void *a){
void func_020311e4(s32,s32,s32,s32);u64 func_02007004(void);u64 func_02072088(u64,u64);extern u8 data_020ea758[];
if(func_02072088((func_02007004()-M2C_FIELD(a,u64 *,0xcb0))<<6,0x82eaULL)>=150ULL || (u32)(M2C_FIELD(a+M2C_FIELD(a,u8 *,0xd0f)*36,u8 *,0x300)<<28)>>28 ==1){
M2C_FIELD(a+0x300,u8 *,(s16)M2C_FIELD(a,u8 *,0xd0f)*(s16)36)&=~15;
M2C_FIELD(a,u8 *,0xd0f)++;
if(M2C_FIELD(a,u8 *,0xd10)<=M2C_FIELD(a,u8 *,0xd0f)){
M2C_FIELD(a,u8 *,0xd15)++;M2C_FIELD(a,u8 *,0xd0f)=0;
M2C_FIELD(a,s8 *,0xd11)=func_02030b30(M2C_FIELD(a,u8 *,0xd15));
}
if(M2C_FIELD(a,s8 *,0xd11)<0){M2C_FIELD(a,u8 *,0xd15)=0;return func_02030ffc(a,5);}
M2C_FIELD(a,u64 *,0xcb0)=func_02007004();
func_020311e4((s32)data_020ea758,(s32)(a+0x304+M2C_FIELD(a,u8 *,0xd0f)*36),M2C_FIELD(a,s8 *,0xd11),0x300000);
}return 5;}

s32 func_02030ffc(void *arg0, s32 arg1) {
    M2C_UNK func_02030554(M2C_UNK);
    s32 func_02031184(void *);
    s32 func_02030d6c(void *);
    M2C_UNK func_02030b98(u8);
    s32 var_r4 = arg1;
    switch (var_r4) {
    case 3:
        if ((M2C_FIELD(arg0, u8 *, 0xD12) == 0) && (M2C_FIELD(arg0, u16 *, 0xD16) == 0)) {
            if ((u32)((u32)(M2C_FIELD(arg0, u8 *, 0xD0B) << 0x18) >> 0x1C) >= 1U) {
                var_r4 = 6;
            } else {
                var_r4 = func_02030d6c(arg0);
            }
        } else {
            if (func_02030554(1) != 0) {
                var_r4 = 4;
            } else {
                var_r4 = func_02031184(arg0);
            }
        }
        break;
    case 4:
        var_r4 = func_02031184(arg0);
        break;
    case 5:
        if ((u32)((u32)(M2C_FIELD(arg0, u8 *, 0xD0B) << 0x18) >> 0x1C) >= 1U) {
            var_r4 = 6;
        } else {
            var_r4 = func_02030d6c(arg0);
        }
        break;
    }
    func_02030b98(var_r4);
    return var_r4;
}

s32 func_020310c0(void *arg0, s32 arg1) {
    s32 func_020276b0();
    M2C_UNK func_0202f558(M2C_UNK);
    s32 var_r4;
    u8 temp_r2;
    u8 var_r1;

    var_r4 = arg1;
    if (var_r4 == 0x11) {
        return var_r4;
    }
    temp_r2 = M2C_FIELD(arg0, u8 *, 0xD12);
    var_r1 = 0;
    if ((s32) temp_r2 > 0) {
loop_3:
        if (M2C_FIELD((arg0 + (var_r1 * 4)), u8 *, 0x444) != 0) {
            var_r1 += 1;
            if ((u32) var_r1 < (u32) temp_r2) {
                goto loop_3;
            }
        }
    }
    if (var_r4 == 6) {
        if (temp_r2 == var_r1) {
            if (var_r1 == 0) {
                func_0202f558(5);
            } else {
                func_0202f558(6);
            }
            return 0x11;
        }
        goto block_17;
    }
    if (temp_r2 == 0) {
        return var_r4;
    }
    if (temp_r2 == var_r1) {
        return var_r4;
    }
    if ((u32) M2C_FIELD((arg0 + (var_r1 * 4)), u8 *, 0x446) < 0x14U) {
        return var_r4;
    }
block_17:
    M2C_FIELD(arg0, u8 *, 0xD13) = var_r1;
    if (func_020276b0() != 1) {
        M2C_FIELD(arg0, s8 *, 0xD0E) = var_r4;
        var_r4 = 7;
    }
    return var_r4;
}

s32 func_02031184(void *arg0) {
    s32 func_02030554(M2C_UNK);
    s8 func_02030b30(M2C_UNK);
    s32 func_02030d6c(void *);
    if ((M2C_FIELD(arg0, u16 *, 0xD16) != 0) && (func_02030554(2) != 0)) {
        M2C_FIELD(arg0, s8 *, 0xD11) = func_02030b30(0);
        return 5;
    }
    if ((u32) ((u32) (M2C_FIELD(arg0, u8 *, 0xD0B) << 0x18) >> 0x1C) >= 1U) {
        return 6;
    }
    return func_02030d6c(arg0);
}

void func_020311e4(s32 a,s32 b,s32 c,s32 d){void func_02027518(s32,s32,s32);extern M2C_UNK data_020ea860;if(c>12)c=12;func_02027518(a,b,d|M2C_FIELD(&data_020ea860,s32 *,c*4));}

s32 func_02031208(void) {
 u32 func_02027c84(void);
 void *func_0202f48c(s32);
 s32 func_02027224(s32 *,void *);
 s32 func_0202f558(s32);
 extern M2C_UNK func_0202fc10;
 s32 v[4];s32 r=func_02027c84();void *p=func_0202f48c(16);
 if(r==1){
 v[0]=M2C_FIELD(p,u8 *,0xd0a);v[1]=0;v[2]=0;v[3]=0;
 func_02030554(0);
 r=func_02027224(v,&func_0202fc10);
 if(r==1||r>=4){func_0202f558(1);return 17;}
 }else return 1;
 return 2;
}

