/* 18 functions from 0x0204309C to 0x02043E10 (main), found by ds-decomp. */
#include "common.h"

s32 func_0204309c(u32 ret){
s32 func_02038f6c(void);
u32 off,code;
if(ret==0)return 0;
switch(ret){
case 1:code=6;off=code-56;break;
case 2:code=6;off=code-66;break;
case 3:code=6;off=code-36;break;
case 4:code=6;off=code-86;break;
case 5:code=6;off=code-26;break;
}
switch(func_02038f6c()){
case 2:func_02039db4(code,off-0xfa00);break;
case 4:func_0203accc(code,off+0xfffedef0);break;
case 5:func_0203dc38(code,off+0xfffeb7e0);break;
default:func_02037638(code,off+0xfffe90d0);break;
}
return ret;
}

s32 func_02043184(s32 a,s32 unused,s32 off) {
s32 code=a;
if(a==0)return 0;
switch(a){
case 1:code=9;off=code-10;break;
case 2:code=6;off=code-56;break;
case 3:code=6;off=code-36;break;
}
func_0203dc38(code,off+0xfffeb010);
return a;
}

#pragma opt_propagation off
s32 func_020431e0(s32 a) {
s32 code;
if(a==0)return 0;
switch(a){
case 1:return 1;
case 2:return 2;
default:code=6;break;
}
if(code)func_0203dc38(code,0xfffeb007);
return a;
}
#pragma opt_propagation reset
u32 func_02043230(u32 a,u32 unused,u32 off) {
u32 ret=a;
u32 code;
code=ret;
if(ret==0)return 0;
switch(ret){
case 1:code=9;off=code-10;break;
case 2:case 5:code=0;off=code;ret=code;break;
case 3:code=6;off=code-16;break;
case 4:code=6;off=code-36;break;
case 6:code=6;off=code-76;break;
case 7:code=6;off=code-86;break;
}
if(code)func_0203dc38(code,off+0xfffeac28);
return ret;
}

void func_020432d4(s32 arg0, s32 arg1, s32 arg2) {
    void *func_02044268(void);
    s32 func_02061794();
    s32 func_02061784();
    void func_020616d8();
    s32 func_0204292c();
    s32 func_02060c44();
    s32 func_02060c4c();
    s32 func_02044278();
    void func_020436d8();
    s32 func_020436dc();
    s32 func_020438b4();
    s32 func_02060b68();
    u64 func_02007004(void);
    void func_020410f8();
    s32 func_0204084c();
    void func_02040878();
    void func_02040dc8();
    void func_02040a28();
    s32 func_0203ecb0();
    void func_0203ea4c();
    void func_02043008();
    s32 func_02043184();

    extern M2C_UNK data_0213d39c;
    extern char data_020fc958[];

    void *ctx;
    s32 i;
    s32 count;
    s32 status;
    void *unit;
    s32 kind1;
    s32 kind2;
    s32 key;

    M2C_FIELD(&data_0213d39c, s32 *, 0x18)++;

    if (arg1 == 0) {
        func_020436d8(arg2);
        ctx = func_02044268();
        {
            u64 ts = func_02007004();
            ts = ts + 0xefb5f7ULL;
            M2C_FIELD(ctx, s32 *, 0x174) = (s32)ts;
            M2C_FIELD(ctx, s32 *, 0x178) = (s32)(ts >> 32);
        }
    } else if (arg1 == 4) {
        ctx = func_02044268();
        M2C_FIELD(ctx, s32 *, 0x174) = 0;
        M2C_FIELD(ctx, s32 *, 0x178) = 0;

        count = func_02061794(arg0);
        i = 0;
        while (i < count) {
            unit = (void *)func_02061784(arg0, i);
            if (func_0204292c() == 0) {
                func_020616d8(arg0, unit);
                i--;
            }
            i++;
            count = func_02061794(arg0);
        }

        ctx = func_02044268();
        status = M2C_FIELD(ctx, s32 *, 0x1a0);

        if (status == 2) {
            i = 0;
            count = func_02061794(arg0);
            while (i < count) {
                unit = (void *)func_02061784(arg0, i);
                ctx = func_02044268();
                if (M2C_FIELD(ctx, s32 *, 0x1c) != 0) {
                    if (func_02060c44(unit) == M2C_FIELD(ctx, s32 *, 0x1c)) {
                        ctx = func_02044268();
                        if (M2C_FIELD(ctx, u16 *, 0x1a) != 0) {
                            ctx = func_02044268();
                            if (M2C_FIELD(ctx, u16 *, 0x1a) == (u16)func_02060c4c(unit)) {
                                goto status2_done;
                            }
                        }
                    }
                }
                i++;
                count = func_02061794(arg0);
            }
status2_done:
            count = func_02061794(arg0);
            if (i >= count) {
                ctx = func_02044268();
                M2C_FIELD(ctx, s32 *, 0xe8) = 2;
                ctx = func_02044268();
                {
                    u64 ts = func_02007004();
                    M2C_FIELD(ctx, s32 *, 0xec) = (s32)ts;
                    M2C_FIELD(ctx, s32 *, 0xf0) = (s32)(ts >> 32);
                }
            } else {
                func_02044278(3);
                ctx = func_02044268();
                M2C_FIELD(ctx, s32 *, 0x204) = 0;
                ctx = func_02044268();
                func_0203ea4c(M2C_FIELD(ctx, u32 *, 0x204));
                func_02043008();
            }
        } else if (status == 3) {
            ctx = func_02044268();
            M2C_FIELD(ctx, s32 *, 0xe8) = 2;
            ctx = func_02044268();
            {
                u64 ts = func_02007004();
                M2C_FIELD(ctx, s32 *, 0xec) = (s32)ts;
                M2C_FIELD(ctx, s32 *, 0xf0) = (s32)(ts >> 32);
            }
        } else if (status == 5) {
            func_020436dc(1);
            func_020438b4();

            while (1) {
                count = func_02061794(arg0);
                if (count == 0) break;
                unit = (void *)func_02061784(arg0, 0);
                kind1 = func_02060c44(unit);
                ctx = func_02044268();
                if (kind1 != M2C_FIELD(ctx, s32 *, 0x1b8)) {
                    func_020616d8(arg0, unit);
                    continue;
                }
                kind2 = func_02060c4c(unit);
                ctx = func_02044268();
                if (kind2 == (s32)M2C_FIELD(ctx, u16 *, 0x1b4)) {
                    break;
                }
                func_020616d8(arg0, unit);
            }

            count = func_02061794(arg0);
            if (count == 0) {
                ctx = func_02044268();
                M2C_FIELD(ctx, s32 *, 0xe8) = 2;
                ctx = func_02044268();
                {
                    u64 ts = func_02007004();
                    M2C_FIELD(ctx, s32 *, 0xec) = (s32)ts;
                    M2C_FIELD(ctx, s32 *, 0xf0) = (s32)(ts >> 32);
                }
            } else {
                unit = (void *)func_02061784(arg0, 0);
                key = func_02060b68(unit, data_020fc958, 0);
                ctx = func_02044268();
                if (M2C_FIELD(ctx, u8 *, 0x15) == 1 && M2C_FIELD(ctx, s32 *, 0xf4) == key) {
                    if (func_020436dc(0) != 0) {
                        ctx = func_02044268();
                        if (M2C_FIELD(ctx, u8 *, 0x0d) != 0) {
                            func_020410f8();
                            if (func_0204084c() != 0) goto cleanup;
                        }
                    } else {
                        ctx = func_02044268();
                        func_02040dc8((void *)M2C_FIELD(ctx, s32 *, 0xf4));
                        if (func_0204084c() != 0) goto cleanup;
                        func_02044278(4);
                        ctx = func_02044268();
                        func_02040a28(0, 0, M2C_FIELD(ctx, s32 *, 0xf4));
                        if (func_0204084c() != 0) goto cleanup;
                        goto cleanup;
                    }
                }
                func_02044278(6);
                unit = (void *)func_02061784(arg0, 0);
                func_0203ecb0(0, 0, (s32)unit);
                func_02043184(0, 0, 0);
                goto cleanup;
            }
        } else {
            ctx = func_02044268();
            M2C_FIELD(ctx, s32 *, 0xe8) = 2;
            ctx = func_02044268();
            {
                u64 ts = func_02007004();
                M2C_FIELD(ctx, s32 *, 0xec) = (s32)ts;
                M2C_FIELD(ctx, s32 *, 0xf0) = (s32)(ts >> 32);
            }
        }
    }

cleanup:
    M2C_FIELD(&data_0213d39c, s32 *, 0x18)--;
    return;
}

void func_020436d8(void) {

}

#pragma opt_strength_reduction off
s32 func_020436dc(s32 sort) {
 void *func_02044268(void);s32 func_02061794(s32);s32 func_02061784(s32,s32);s32 func_02060b68(void *,void *,s32);s32 func_02060ac4(void *,void *,s32);s32 func_020617a4(s32,s32,void *,s32);s32 func_02037eec(s32);void func_020616d8(s32,void *);
 extern char data_020fc958[],data_020fc984[];
 s32 removed=0; s32 found,weight;void *ctx; s32 key; s32 i=0; s32 j;void *item;
 for(;i<func_02061794(M2C_FIELD(func_02044268(),s32 *,0xe4));i++) {
 item=(void *)func_02061784(M2C_FIELD(func_02044268(),s32 *,0xe4),i);
 if(M2C_FIELD(func_02044268(),u8 *,0x15)==0) {
 key=func_02060b68(item,data_020fc958,0);found=0;
 for(j=1;j<=M2C_FIELD(func_02044268(),u8 *,0xd);j++) {
 if(key==M2C_FIELD((u8 *)func_02044268()+j*4,s32 *,0xf4)) {
 func_020616d8(M2C_FIELD(func_02044268(),s32 *,0xe4),item);i--;found=1;break;
 }}
 if(found)continue;
 }
 if(M2C_FIELD(func_02044268(),s32 *,0x474)) {
 ctx=func_02044268();
 weight=M2C_FIELD(ctx,s32 (**)(s32,s32),0x474)(i,M2C_FIELD(func_02044268(),s32 *,0x478));
 if(weight>0) {if(weight>0x7fffff)weight=0x7fffff;func_02060ac4(item,data_020fc984,func_02037eec(256)|(weight<<8));}
 else {func_020616d8(M2C_FIELD(func_02044268(),s32 *,0xe4),item);i--;removed=1;}
 }else func_02060ac4(item,data_020fc984,func_02037eec(128));
 }
 if(sort && func_02061794(M2C_FIELD(func_02044268(),s32 *,0xe4))!=0)func_020617a4(M2C_FIELD(func_02044268(),s32 *,0xe4),0,data_020fc984,0);
 if(removed && func_02061794(M2C_FIELD(func_02044268(),s32 *,0xe4))==0)return 0;
 return 1;
}
s32 func_020438b4(void) {
    void *func_02044268(void);
    s32 func_02061794(s32);
    s32 func_02061784(s32, s32);
    s32 func_02060b68(void *, void *, s32);
    s32 func_02060ac4(void *, void *, s32);
    s32 func_020617a4(s32, s32, void *, s32);
    s32 func_02037eec(s32);
    s32 func_020720f0(s32, s32);
    extern s32 data_020ea928[];
    extern char data_020fc984[];
    u32 rnd;
    s32 best = 0;
    s32 total = 0;
    s32 n;
    s32 i;
    s32 stack[6];
    s32 prev;
    s32 v;
    s32 tmp;

    n = func_02061794(*(s32 *)((u8 *)func_02044268() + 0xE4));
    if (n <= 1) return n;
    i = 0;
    while (i < func_02061794(*(s32 *)((u8 *)func_02044268() + 0xE4))) {
        v = func_02060b68((void *)func_02061784(*(s32 *)((u8 *)func_02044268() + 0xE4), i), data_020fc984, -1);
        if (v > best) best = v;
        total += data_020ea928[i];
        i++;
    }
    rnd = func_02037eec(100);
    i = 0;
    while (i < func_02061794(*(s32 *)((u8 *)func_02044268() + 0xE4))) {
        if (i == func_02061794(*(s32 *)((u8 *)func_02044268() + 0xE4)) - 1) break;
        prev = (i > 0) ? stack[i - 1] : 0;
        tmp = func_020720f0(data_020ea928[i] * 100, total);
        stack[i] = tmp + prev;
        if (rnd < (u32)stack[i]) break;
        i++;
    }
    if (best < 0x7FFFFFFF) best++;
    func_02060ac4((void *)func_02061784(*(s32 *)((u8 *)func_02044268() + 0xE4), i), data_020fc984, best);
    return func_020617a4(*(s32 *)((u8 *)func_02044268() + 0xE4), 0, data_020fc984, 0);
}

void func_02043a24(s32 a, void *b) {
    void *func_02044268(void);
    void func_0205eb7c(void *, s32);
    void func_0205ebb0(void *, void *);
    extern u8 data_0213d3bc[];
    extern u8 data_0213d3bd[];
    extern void *data_0213d3c4[];
    void *p;
    s32 t;
    s32 i;
    s32 idx;

    switch(a) {
case 8: p=func_02044268(); func_0205eb7c(b,((u8 *)p)[0x14]); return;
case 10: p=func_02044268(); func_0205eb7c(b,((u8 *)p)[0x16]); return;
case 50: p=func_02044268(); func_0205eb7c(b,*(s32 *)((char *)p+0x200)); return;
case 51: p=func_02044268(); func_0205eb7c(b,((u8 *)p)[0x15]); return;
case 52: p=func_02044268(); func_0205eb7c(b,*(s32 *)((char *)p+0x20)); return;
case 53:  func_0205eb7c(b,3); return;
case 54:  func_0205eb7c(b,1); return;
    }
    i = a - 100;
    if (i < 0) return;
    if (i >= 154) return;
    idx = i * 12;
    if (data_0213d3bc[idx] == 0) return;
    if (data_0213d3bd[idx] != 0) {
        func_0205ebb0(b, *(void **)((char *)data_0213d3c4 + idx));
    } else {
        func_0205eb7c(b, **(s32 **)((char *)data_0213d3c4 + idx));
    }
}

void func_02043b6c(void) {

}

void func_02043b70(void) {

}

void func_02043b74(s32 a,s32 b) {
extern u8 data_0213d3bc[];
s32 i;u8 *p;
switch(a){case 0:break;case 1:case 2:default:return;}
func_0205eb50(b,8);
func_0205eb50(b,10);
func_0205eb50(b,50);
func_0205eb50(b,51);
func_0205eb50(b,52);
func_0205eb50(b,53);
func_0205eb50(b,54);
p=data_0213d3bc;
for(i=0;i<154;i++,p+=12)if(*p)func_0205eb50(b,*p);
}

s32 func_02043c18(void) {
    return 0;
}

void func_02043c20(void) {
    M2C_UNK func_0204309c();
    func_0204309c();
}

void func_02043c2c(s32 arg0, s16 arg1) {
    void *func_02044268();
    M2C_FIELD(func_02044268(), s32 *, 0x1C) = arg0;
    M2C_FIELD(func_02044268(), s16 *, 0x1A) = arg1;
}

void func_02043c4c(s32 arg0) {
    void *func_02044268();
    M2C_UNK func_02044278(M2C_UNK);
    s32 func_02043184();
    M2C_UNK func_0203ecb0(M2C_UNK, s32);
    void *p;

    p = func_02044268();
    if (M2C_FIELD(p, s32 *, 0x1A0) == 1) {
        func_02044278(6);
    } else {
        p = func_02044268();
        if (M2C_FIELD(p, s32 *, 0x1A0) != 6) {
            p = func_02044268();
            if (M2C_FIELD(p, s32 *, 0x1A0) != 0xB) {
                return;
            }
        }
    }
    p = func_02044268();
    if (arg0 == M2C_FIELD(p, s32 *, 0x180)) {
        p = func_02044268();
        M2C_FIELD(p, u8 *, 0x17C) = (u8)(M2C_FIELD(p, u8 *, 0x17C) + 1);
    } else {
        p = func_02044268();
        M2C_FIELD(p, s8 *, 0x17C) = 0;
        p = func_02044268();
        M2C_FIELD(p, s32 *, 0x180) = arg0;
    }
    p = func_02044268();
    M2C_FIELD(p, s32 *, 0x184) = 0;
    M2C_FIELD(p, s32 *, 0x188) = 0;
    func_0203ecb0(1, arg0);
    if (func_02043184() != 0) {
        return;
    }
    p = func_02044268();
    M2C_FIELD(p, u8 *, 0x3CC) = 0xFF;
}

void func_02043d00(s32 arg0, u32 arg1) {
    s32 func_02038f6c(void);
    void *func_02044268(void);
    void func_02008048(void *, void *, s32);
    s32 func_02068eac(void *, void *, s32);
    s32 func_0203f45c(s32, u32, u32, u32, void *, s32);
    extern u8 data_020fca00[];
    u8 record[20];
    u8 buf[128];
    u32 acc = 0;

    if (func_02038f6c() != 5) {
        if (func_02038f6c() != 6) return;
        if (((u8 *)func_02044268())[0x15] != 2) {
            if (((u8 *)func_02044268())[0x15] != 3) return;
        }
    }
    if (arg1 < 0x14) return;

    for (;;) {
        func_02008048((void *)arg0, record, 0x14);
        if (func_02068eac(record, data_020fca00, 4) != 0) return;
        if (*(u32 *)(record + 4) != 3) return;
        func_02008048((void *)(arg0 + 0x14), buf, record[9]);
        if (func_0203f45c(record[8], *(u32 *)(record + 16), *(u32 *)(record + 12), *(u16 *)(record + 10), buf, record[9] >> 2) == 0) return;
        acc += record[9] + 0x14;
        if (acc + 0x14 > arg1) return;
    }
}

void func_02043e0c(void) {

}

