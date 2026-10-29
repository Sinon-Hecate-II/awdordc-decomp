/* 18 functions from 0x0219C7EC to 0x0219D724 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0219c7ec(s32 a){extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;s32 n,i,j;u8 *p,*q;u8 x,y,t;if(a<2)return;n=a-2;i=0;if(n<0)return;do{j=n;if(n>=i){p=(u8 *)&data_ov000_021df868+n;q=&data_ov000_021df824+n;do{y=p[1];x=p[0];if((u32)x<(u32)y){p[0]=y;p[1]=x;t=q[0];q[0]=q[1];q[1]=t;}j--;p--;q--;}while(j>=i);}i++;}while(i<=n);}

void func_ov000_0219c874(s32 a){extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;s32 n,i,j;u8 *p,*q;u8 x,y,t;if(a<2)return;n=a-2;i=0;if(n<0)return;do{j=n;if(n>=i){p=(u8 *)&data_ov000_021df868+n;q=&data_ov000_021df824+n;do{y=p[1];x=p[0];if((u32)x>(u32)y){p[0]=y;p[1]=x;t=q[0];q[0]=q[1];q[1]=t;}j--;p--;q--;}while(j>=i);}i++;}while(i<=n);}

void func_ov000_0219c8fc(void){void func_ov000_0219c7ec(s32);extern s32 *gCurrentMap;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;s32 *base=gCurrentMap;u8 *p=&data_ov000_021df824;s8 *q=&data_ov000_021df868;s32 n=0;u8 x;loop: x=*p;if(x!=0){s32 a=x*14+(*base+0x59a4);p++;*q=(u32)(M2C_FIELD(a,u16 *,6)<<25)>>24;if(((u32)(M2C_FIELD(a,u16 *,8)<<26)>>26)!=63)(*q)++;q++;n++;goto loop;}func_ov000_0219c7ec(n);}
#pragma opt_common_subs reset
void func_ov000_0219c984(void){
void func_ov000_0219c7ec(s32);extern s32 *gCurrentMap;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;
u8 *p; s32 *base; s8 *q; s32 n;u8 x;
base=gCurrentMap;p=&data_ov000_021df824;q=&data_ov000_021df868;n=0;
loop:x=*p;if(x!=0){p++;*q++=(u32)(M2C_FIELD(*base+x*14,u16 *,0x59aa)<<25)>>25;n++;goto loop;}func_ov000_0219c7ec(n);
}

void func_ov000_0219c9e8(s32 arg0) {
    u8 func_020a7b24(s32);
    void func_ov000_0219c874(s32);
    void func_ov000_0219c7ec(s32);
    extern s32 *gCurrentMap;
    extern u8 data_ov000_021df824;
    extern s8 data_ov000_021df868;
    u8 *var_r9;
    s8 *var_r10;
    s32 var_r8;
    u8 var_r1;

    var_r9 = &data_ov000_021df824;
    var_r10 = &data_ov000_021df868;
    var_r8 = 0;
loop:
    var_r1 = *var_r9;
    if (var_r1 == 0) goto done;
    if ((u32)((M2C_FIELD(var_r1 * 14 + *gCurrentMap, u8 *, 0x59A4) << 0x1A) >> 0x1A) == 0x11) {
        *var_r10 = (s8)(func_020a7b24(14) + 1);
    } else if ((u32)((M2C_FIELD(var_r1 * 14 + *gCurrentMap, u8 *, 0x59A4) << 0x1A) >> 0x1A) == 0x0F) {
        *var_r10 = (s8)(func_020a7b24(14) + 2);
    } else {
        *var_r10 = (s8)func_020a7b24((u32)((M2C_FIELD(var_r1 * 14 + *gCurrentMap, u8 *, 0x59A4) << 0x1A) >> 0x1A));
    }
    var_r9++;
    var_r10++;
    var_r8++;
    goto loop;
done:
    if (arg0 == 0) {
        func_ov000_0219c874(var_r8);
    } else {
        func_ov000_0219c7ec(var_r8);
    }
}

void func_ov000_0219caac(void) {
    u8 func_020a7b24(s32);
    void func_ov000_0219c874(s32);
    extern u8 data_ov000_021df824;
    extern s8 data_ov000_021df868;
    extern s32 *gCurrentMap;
    extern u8 data_ov000_021b5bfc[];
    u8 *p;
    u8 *q;
    s32 n;
    u8 unit;
    s32 base;
    u8 *entry;
    u32 code;
    u8 chk;
    u16 v;

    p = &data_ov000_021df824;
    q = (u8 *)&data_ov000_021df868;
    n = 0;
    while (1) {
        unit = *p;
        if (unit == 0) break;
        base = *gCurrentMap;
        entry = (u8 *)(*(s32 *)base + 0x1A4 + 0x5800 + (s32)unit * 14);
        code = ((u32)*entry << 26) >> 26;
        if (code == 0x11) {
            *q = (u8)(func_020a7b24(14) + 1);
        } else if (code == 0x0F) {
            *q = (u8)(func_020a7b24(14) + 2);
        } else {
            *q = (u8)func_020a7b24(code);
        }
        code = ((u32)*entry << 26) >> 26;
        chk = data_ov000_021b5bfc[code * 0x70 + 0x13];
        if (chk & 0x10) {
            v = *(u16 *)(entry + 4);
            if (!(v & 0x8)) {
                *q = (u8)(*q + 0xA);
            }
        }
        ++p;
        ++q;
        ++n;
    }
    func_ov000_0219c874(n);
}

void func_ov000_0219cb98(void) {
    void func_ov000_0219c874(s32);
    s8 func_020a7bd4(u32);
    extern s32 *gCurrentMap;
    extern u8 data_ov000_021df824;
    extern s8 data_ov000_021df868;
    s32 var_r4;
    u8 *var_r5;
    s8 *var_r6;
    u8 temp_r1;

    var_r5 = &data_ov000_021df824;
    var_r6 = &data_ov000_021df868;
    var_r4 = 0;
loop_1:
    temp_r1 = *var_r5;
    if (temp_r1 != 0) {
        *var_r6 = func_020a7bd4((u32) (M2C_FIELD(((temp_r1 * 0xE) + *gCurrentMap), u8 *, 0x59A4) << 0x1A) >> 0x1A);
        var_r6 += 1;
        ++var_r5;
        ++var_r4;
        goto loop_1;
    }
    func_ov000_0219c874(var_r4);
}

void func_ov000_0219cc04(s32 arg0) {
s8 func_020a7824(s32,u8,u8);
extern s32 *gCurrentMap;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&data_ov000_021df824;q=&data_ov000_021df868;n=0;
loop: x=*p;if(x){a=x*14+(*gCurrentMap+0x59a4);*q=func_020a7824(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));q++;p++;n++;goto loop;}
if(arg0==0){func_ov000_0219c874(n);return;}func_ov000_0219c7ec(n);
}

void func_ov000_0219cc84(void) {
s8 func_020a7824(s32,u8,u8);
extern s32 *gCurrentMap;extern u8 data_ov000_021df824;extern s8 data_ov000_021df868;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&data_ov000_021df824;q=&data_ov000_021df868;n=0;
loop: x=*p;if(x){a=x*14+(*gCurrentMap+0x59a4);*q=func_020a7824(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));p++;n++;if(!(M2C_FIELD(a,u16 *,4)&8))*q=*(volatile u8*)q+10;q++;goto loop;}
func_ov000_0219c874(n);
}

void func_ov000_0219cdf4(void) {
    s32 func_020a7cfc(s32);
    extern s32 *gCurrentMap;
    extern u8 data_ov000_021df824;
    unsigned var_r4;
    u8 var_r5;
    register u8 *var_r1;
    u8 temp_r0;
    u8 *var_r6;
    u8 temp_r1;
    long var_r7;

    var_r4 = 0;
    var_r6 = &data_ov000_021df824;
    var_r7 = 0;
    var_r5 = 0;
loop_1:
    temp_r1 = *var_r6;
    if (temp_r1) {
        if (func_020a7cfc((temp_r1 * 0xE) + (*gCurrentMap + 0x59A4)) != 0) {
            var_r7 = var_r4;
            var_r5 = (&data_ov000_021df824)[var_r4];
        } else {
            ++var_r6;
            ++var_r4;
            goto loop_1;
        }
    }
    if (var_r5 == 0) {
        return;
    }
    var_r1 = &(&data_ov000_021df824)[var_r7];
loop_8:
    temp_r0 = M2C_FIELD(var_r1, u8 *, 1);
    if (temp_r0) {
        ++var_r1;
        M2C_FIELD(var_r1, u8 *, 0) = temp_r0;
        ++var_r7;
        goto loop_8;
    }
    (&data_ov000_021df824)[var_r7] = var_r5;
}

void func_ov000_0219ce90(void) {
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern u8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02180e4c;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    obj = *gCurrentMap;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1)
                    && data_ov000_021b5bfc[type * 0x70 + 0x14] == 1
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u16 *, 6) << 0x10) >> 0x1B) != 0
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u8 *, 0xB) << 0x1C) >> 0x1C) == 0) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_02180e4c;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219cfc8(void) {
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern u8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02180ec8;
    void func_ov000_0219c8fc(void);
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    obj = *gCurrentMap;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 1 && ((u32)(M2C_FIELD((u8 *)table + stride, u8 *, 0xB) << 0x1C) >> 0x1C) != 0) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    func_ov000_0219c8fc();
    data_ov000_021df654 = &func_ov000_02180ec8;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219d0f4(void) {
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern u8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02180f14;
    void func_ov000_0219c8fc(void);
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    obj = *gCurrentMap;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 1 && ((u32)(M2C_FIELD((u8 *)table + stride, u8 *, 0xB) << 0x1C) >> 0x1C) == 0) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    func_ov000_0219c8fc();
    data_ov000_021df654 = &func_ov000_02180f14;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219d220(void) {
    extern s32 *gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern u8 data_ov000_021df824;
    u8 func_ov000_021a8984(s32);
    void func_ov000_0219c8fc(void);
    extern M2C_UNK func_ov000_02180ff4;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    u32 nibble;
    void *table;
    void *obj;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    obj = *gCurrentMap;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 1) {
                    nibble = (u32)(M2C_FIELD((u8 *)table + stride, u8 *, 0xB) << 0x1C) >> 0x1C;
                    if (nibble != 0) {
                        if (func_ov000_021a8984((s32)nibble) != 0) {
                            out = data_ov000_021df658;
                            data_ov000_021df658 = out + 1;
                            *out = index;
                        }
                    }
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = (s8 *)&data_ov000_021df824;
    func_ov000_0219c8fc();
    data_ov000_021df654 = &func_ov000_02180ff4;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219d358(void) {
extern s32 *gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5bfc[];
extern s8 *data_ov000_021df580;
extern M2C_UNK *data_ov000_021df654;
extern s8 *data_ov000_021df658;
extern u8 data_ov000_021df824;
extern M2C_UNK func_ov000_021811e8;
void func_ov000_0219c984(void);
void func_ov000_0219cc04(s32);
void func_ov000_0219c9e8(s32);
void func_ov000_0219cdf4(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
data_ov000_021df658 = &data_ov000_021df824;
obj = *gCurrentMap;
baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
index = baseIndex + 1;
if (index < baseIndex + 0x33) {
stride = index * 14;
do {
table = (u8 *)obj + 0x59A4;
type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
if (type != 0) {
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 4) {
out = data_ov000_021df658;
data_ov000_021df658 = out + 1;
*out = index;
}
}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*data_ov000_021df658 = 0;
data_ov000_021df658 = &data_ov000_021df824;
func_ov000_0219c984();
if (M2C_FIELD(*gCurrentMap, u8 *, 0x5156) != 0 || M2C_FIELD(*gCurrentMap, u8 *, 0x5158) == 2) {
    func_ov000_0219cc04(1);
} else {
    func_ov000_0219c9e8(0);
}
func_ov000_0219cdf4();
data_ov000_021df654 = &func_ov000_021811e8;
*data_ov000_021df580 = 2;
}

void func_ov000_0219d4b4(void) {
extern s32 *gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5bfc[];
extern s8 *data_ov000_021df580;
extern M2C_UNK *data_ov000_021df654;
extern s8 *data_ov000_021df658;
extern u8 data_ov000_021df824;
extern M2C_UNK func_ov000_021812a8;
void func_ov000_0219cc84(void);
void func_ov000_0219caac(void);
void func_ov000_0219cdf4(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
data_ov000_021df658 = &data_ov000_021df824;
obj = *gCurrentMap;
baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
index = baseIndex + 1;
if (index < baseIndex + 0x33) {
stride = index * 14;
do {
table = (u8 *)obj + 0x59A4;
type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
if (type != 0) {
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 4) {
out = data_ov000_021df658;
data_ov000_021df658 = out + 1;
*out = index;
}}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*data_ov000_021df658 = 0;
data_ov000_021df658 = &data_ov000_021df824;
if (M2C_FIELD(*gCurrentMap, u8 *, 0x5156) != 0) goto do_caac;
if (M2C_FIELD(*gCurrentMap, u8 *, 0x5158) == 2) {
func_ov000_0219cc84();
}
goto skip;
do_caac:
func_ov000_0219caac();
skip:
func_ov000_0219cdf4();
data_ov000_021df654 = &func_ov000_021812a8;
*data_ov000_021df580 = 2;
}

void func_ov000_0219d604(void) {
extern s32 *gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5bfc[];
extern s8 *data_ov000_021df580;
extern M2C_UNK *data_ov000_021df654;
extern s8 *data_ov000_021df658;
extern u8 data_ov000_021df824;
extern M2C_UNK func_ov000_021813a4;
void func_ov000_0219c984(void);
void func_ov000_0219cb98(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
data_ov000_021df658 = &data_ov000_021df824;
obj = *gCurrentMap;
baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
index = baseIndex + 1;
if (index < baseIndex + 0x33) {
stride = index * 14;
do {
table = (u8 *)obj + 0x59A4;
type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
if (type != 0) {
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 3) {
out = data_ov000_021df658;
data_ov000_021df658 = out + 1;
*out = index;
}}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*data_ov000_021df658 = 0;
data_ov000_021df658 = &data_ov000_021df824;
func_ov000_0219c984();
func_ov000_0219cb98();
data_ov000_021df654 = &func_ov000_021813a4;
*data_ov000_021df580 = 2;
}

