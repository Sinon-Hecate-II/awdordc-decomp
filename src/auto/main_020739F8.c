/* 43 functions from 0x020739F8 to 0x02074920 (main), found by ds-decomp. */
#include "common.h"
#pragma cplusplus on
extern "C" {
void func_020742f8(void);
M2C_UNK func_020742e0(void);
void *func_02072bac(void *, s32 *);
void *func_02072b20(void *, s32 *);
s32 func_02073b4c(M2C_UNK,void *);
void func_020746a4(void);
void func_0207465c(void *,void *,void *);
void func_02073c78(void);
extern u8 data_021009a4[],data_02100998[],data_021009bc[];
}
#pragma cplusplus off

typedef struct { s32 v[21]; } CtxTail_020739f8;
typedef struct { s32 f0, f1, f2, f3, f4, f5, f6; CtxTail_020739f8 tail; } CtxState_020739f8;
typedef struct { s32 t0, t1, t2, t3, t4, t5; } CtxToken_020739f8;
typedef struct { CtxToken_020739f8 token; CtxState_020739f8 state; } Ctx_020739f8;
typedef struct { s32 a,b,c,d; } CtxOperands_020739f8;

s32 func_020739f8(void *arg0, void *arg1) {
    u8 func_02072da4(CtxToken_020739f8 *);
    void *func_02072b20(void *, s32 *);
    s32 func_02072dc0(Ctx_020739f8 *);
    s32 out;
    Ctx_020739f8 ctx;
    CtxState_020739f8 *st;
    s32 *tk;
    u8 *p;

    tk = (s32 *)arg1;
    st = (CtxState_020739f8 *)arg0;
    ctx.token.t0 = tk[0];
    ctx.token.t1 = tk[1];
    ctx.token.t2 = tk[2];
    ctx.token.t3 = tk[3];
    ctx.token.t4 = tk[4];
    ctx.token.t5 = tk[5];
    ctx.state.f0 = st->f0;
    ctx.state.f1 = st->f1;
    ctx.state.f2 = st->f2;
    ctx.state.f3 = st->f3;
    ctx.state.f4 = st->f4;
    ctx.state.f5 = st->f5;
    ctx.state.f6 = st->f6;
    ctx.state.tail = st->tail;

    for (;;) {
        u8 cmd = func_02072da4((CtxToken_020739f8 *)(&ctx + 0));
        switch (cmd) {
        default:
        case 1:
        case 14:
            return 0;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 15:
        case 16:
        case 17:
        case 18:
            func_02072dc0((Ctx_020739f8 *)(&ctx + 0));
            break;
        case 13:
            func_02072b20((u8 *)ctx.token.t2 + 1, &out);
            p = (u8 *)ctx.state.f6 + out;
            ((s32 *)arg0)[0] = *(s32 *)(p + 4);
            ((s32 *)arg0)[1] = *(s32 *)p;
            ((s32 *)arg0)[2] = 0;
            ((s32 *)arg0)[3] = (s32)p;
            return (s32)p;
        }
    }
}

s32 func_02073b4c(M2C_UNK arg0, void *arg1) {
    s32 func_02074330(M2C_UNK, s32, M2C_UNK *);
    s32 values[2];
    u8 *p;
    u32 i;
    p = M2C_FIELD(arg1, u8 **, 0xC);
    for (i = 0; i < M2C_FIELD(arg1, u32 *, 0); i++, p += 4) {
        values[1] = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
        if (func_02074330(arg0, values[1], values) != 0) return 1;
    }
    return 0;
}

#pragma cplusplus on
#pragma exceptions on
extern "C" void func_02073bd0(void *arg0){
u8 *p=M2C_FIELD(arg0,u8 **,20);s32 values[4];
try{func_020742f8();}catch(...){
void *q=func_02072bac(p+1,&values[0]);
q=func_02072bac(q,&values[1]);
values[3]=(s32)func_02072b20(q,&values[2]);
if(func_02073b4c(M2C_FIELD(arg0,s32 *,8),values))func_020746a4();
if(func_02073b4c((s32)data_021009a4,values)){void *exception=data_02100998;func_0207465c(data_021009bc,&exception,(void *)func_02073c78);}
}
func_020742e0();
}
#pragma exceptions off
#pragma cplusplus off

void func_02073c78(void) {

}

#pragma scheduling on
#pragma peephole off
void func_02073c7c(s32 *arg0, s32 *arg1, void *arg2, s32 arg3) {
 M2C_UNK func_02073148(void *, s32 *, s32);
 M2C_UNK func_0207462c(void *, s32 *, s32);
 void *base; s32 offset; void *entry;
 register s32 value=arg3;
 func_02073148(arg0,arg1,value);
 base=M2C_FIELD(arg0,void **,0x18); offset=M2C_FIELD(arg2,s32 *,8); entry=(u8*)base+offset;
 M2C_FIELD(entry,s32 *,0)=M2C_FIELD(arg0,s32 *,4);
 M2C_FIELD(entry,s32 *,4)=M2C_FIELD(arg0,s32 *,0);
 M2C_FIELD(entry,s32 *,8)=M2C_FIELD(arg0,s32 *,8);
 M2C_FIELD(entry,s32 *,0x14)=value;
 func_0207462c(arg0,arg1,*arg1+M2C_FIELD(arg2,s32 *,4));
}
#pragma peephole reset
#pragma scheduling reset
u8 *func_02073cdc(void *arg0, void *arg1, s32 *arg2) {
    u8 func_02072da4(CtxToken_020739f8 *);
    s32 func_02072dc0(Ctx_020739f8 *);
    void *func_02072bac(void *, M2C_UNK *);
    void *func_02072b20(void *, s32 *);
    M2C_UNK func_020742e0(void);
    s32 func_02074330(M2C_UNK, s32, M2C_UNK *);
    s32 func_02073b4c(M2C_UNK, void *);
    void func_02073c7c(s32 *, s32 *, void *, s32);
    s32 code;
    Ctx_020739f8 ctx;
    s32 values[3];
    CtxOperands_020739f8 operands;

    ctx.token.t0 = ((s32 *)arg1)[0];
    ctx.token.t1 = ((s32 *)arg1)[1];
    ctx.token.t2 = ((s32 *)arg1)[2];
    ctx.token.t3 = ((s32 *)arg1)[3];
    ctx.token.t4 = ((s32 *)arg1)[4];
    ctx.token.t5 = ((s32 *)arg1)[5];
    ctx.state.f0 = ((CtxState_020739f8 *)arg0)->f0;
    ctx.state.f1 = ((CtxState_020739f8 *)arg0)->f1;
    ctx.state.f2 = ((CtxState_020739f8 *)arg0)->f2;
    ctx.state.f3 = ((CtxState_020739f8 *)arg0)->f3;
    ctx.state.f4 = ((CtxState_020739f8 *)arg0)->f4;
    ctx.state.f5 = ((CtxState_020739f8 *)arg0)->f5;
    ctx.state.f6 = ((CtxState_020739f8 *)arg0)->f6;
    ctx.state.tail = ((CtxState_020739f8 *)arg0)->tail;

    code = func_02072da4((CtxToken_020739f8 *)(&ctx + 0));
    for (;;) {
        switch (code) {
        case 12: {
            u8 *node = (u8 *)ctx.token.t2;
            values[0] = node[1] | (node[2] << 8) | (node[3] << 16) | (node[4] << 24);
            {
                u8 *r = (u8 *)func_02072bac(node + 5, &values[1]);
                func_02072b20(r, &values[2]);
            }
            if (func_02074330(((CtxState_020739f8 *)arg0)->f0, values[0], arg2) != 0) {
                goto done;
            }
            break;
        }
        case 15: {
            u8 *node = (u8 *)ctx.token.t2;
            u8 *r;
            r = (u8 *)func_02072bac(node + 1, &operands.a);
            r = (u8 *)func_02072bac(r, &operands.b);
            r = (u8 *)func_02072b20(r, &operands.c);
            operands.d = (s32)r;
            if (func_02073b4c(((CtxState_020739f8 *)arg0)->f0, &operands.a) != 0) {
                    break;
            }
            func_02073c7c((s32 *)arg0, (s32 *)arg1, (void *)&operands.a, (s32)node);
            break;
        }
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
        case 1:
        case 14:
        default:
            func_020742e0();
            goto done;
        }
        func_02072dc0(&ctx);
        code = func_02072da4((CtxToken_020739f8 *)(&ctx + 0));
    }
done:
    return (u8 *)ctx.token.t2;
}
#pragma opt_common_subs reset
void func_02073eb8(void *arg0, s32 arg1, s32 arg2) {
    void *entry;
    entry = (u8 *)M2C_FIELD(arg0, void **, 0x18) + arg1;
    M2C_FIELD(entry, s32 *, 0) = M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(entry, s32 *, 4) = M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(entry, s32 *, 8) = M2C_FIELD(arg0, s32 *, 8);
    if (*M2C_FIELD(arg0, u8 **, 0) == 0x2A) {
        M2C_FIELD(entry, void **, 0xC) = (u8 *)entry + 0x10;
        M2C_FIELD(entry, s32 *, 0x10) = *M2C_FIELD(arg0, s32 **, 4) + arg2;
    } else {
        M2C_FIELD(entry, s32 *, 0xC) = M2C_FIELD(arg0, s32 *, 4) + arg2;
    }
}

void func_02073f14(void *a){
void func_02072c9c(s32,void *); M2C_UNK func_020742e0(void); s32 func_020739f8(void *,void *); u8 *func_02073cdc(void *,void *,s32 *); void *func_02072bac(void *,M2C_UNK *); void *func_02072b20(void *,s32 *); M2C_UNK func_02073148(); M2C_UNK func_0207462c(void *,s32 *,s32); void func_0207453c(void *,void *);
s32 t[6]; s32 vals[4]; u8 *p;
func_02072c9c(M2C_FIELD(a,s32 *,16),t);
if(!t[1])func_020742e0();
func_0207453c(a,t);
if(M2C_FIELD(a,s32 *,0))M2C_FIELD(a,s32 *,12)=0;
else {M2C_FIELD(a,s32 *,12)=func_020739f8(a,t);if(!M2C_FIELD(a,s32 *,12))func_020742e0();}
p=func_02073cdc(a,t,&vals[0]);
vals[1]=p[1]|(p[2]<<8)|(p[3]<<16)|(p[4]<<24);
func_02072b20(func_02072bac(p+5,&vals[2]),&vals[3]);
func_02073148(a,t,p);
func_02073eb8(a,vals[3],vals[0]);
func_0207462c(a,t,t[0]+vals[2]);
}

void func_02074000(void *arg0) {
    M2C_UNK (*temp_r2)(s32, M2C_UNK);
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r1 != 0) {
        temp_r2 = M2C_FIELD(arg0, M2C_UNK (**)(s32, M2C_UNK), 8);
        if (temp_r2 != NULL) {
            temp_r2(temp_r1, -1);
        }
    }
}

s32 func_02074028(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

M2C_UNK *func_0207403c(void) {
    extern M2C_UNK data_0210096c;
    return &data_0210096c;
}

void func_02074048(void) {
    extern void (*ARM9_CTOR_START[])(void);
    void (**p)(void) = ARM9_CTOR_START;
    while (p != NULL && *p != NULL) {
        (*p)();
        p++;
    }
}

void func_02074074(void) {
    extern void *data_0213ea14;
    void *entry;
    entry = data_0213ea14;
    if (entry == NULL) return;
    do {
        data_0213ea14 = M2C_FIELD(entry, void **, 0);
        M2C_FIELD(entry, void (**)(s32, s32), 4)(M2C_FIELD(entry, s32 *, 8), -1);
        entry = data_0213ea14;
    } while (entry != NULL);
}

#pragma cplusplus on
#pragma exceptions on
extern "C" void func_020740b8(u32 arg0,u32 arg1,s32 arg2,M2C_UNK (*arg3)(u32)) { try { while(arg1>arg0) { arg1-=arg2; arg3(arg1); } } catch (...) { for (;;) {} } }
extern "C" void func_020740b8(u32, u32, s32, M2C_UNK (*)(u32));
extern "C" void func_02074114(s32 arg0, s32 arg1, s32 arg2, M2C_UNK (*arg3)(s32), s32 arg4) {
    s32 current;
    if (arg3 == 0) return;
    if (arg4 != 0) {
        current = arg0;
        try {
            while (arg1 != 0) { arg3(current); current += arg2; --arg1; }
        } catch (...) {
            func_020740b8(arg0, current, arg2, (M2C_UNK (*)(u32))arg4);
            throw;
        }
    } else {
        while (arg1 != 0) { arg3(arg0); arg0 += arg2; --arg1; }
    }
}
#pragma cplusplus on
#pragma exceptions on
extern "C" void func_020741c4(s32 arg0, s32 arg1, s32 arg2, M2C_UNK (*arg3)(s32)) {
    s32 current;
    if (arg3 != 0) {
        current = arg1 * arg2 + arg0;
        try {
            while (arg1 != 0) { current -= arg2; arg3(current); --arg1; }
        } catch (...) {}
    }
}
#pragma exceptions off
#pragma cplusplus off
void func_02074220(void) {

}

s32 func_02074224(void *arg0, void *arg1) {
    s32 func_02068d98(s32, s32);
    if ((arg0 == arg1) || (func_02068d98(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg1, s32 *, 4)) == 0)) {
        return 1;
    }
    return 0;
}

s32 func_02074254(s32 arg0) {
    func_02074220();
    return arg0;
}

s32 func_02074268(s32 arg0) {
    func_02074220();
    func_02082040(arg0);
    return arg0;
}

s32 func_02074284(s32 arg0) {
    func_02074220();
    return arg0;
}

s32 func_02074298(s32 arg0) {
    M2C_UNK func_02074284();
    func_02074284();
    return arg0;
}

s32 func_020742ac(s32 arg0) {
    M2C_UNK func_02074284();
    func_02074284();
    func_02082040(arg0);
    return arg0;
}

void func_020742c8(void) {
    M2C_UNK func_02063df8();
    func_02063df8();
}

void func_020742d4(void) {
    M2C_UNK func_020742e0();
    func_020742e0();
}

M2C_UNK func_020742e0(void) {
    extern M2C_UNK data_02100a80;
    return M2C_FIELD(&data_02100a80, M2C_UNK (**)(), 0)();
}

void func_020742f8(void) {
    extern M2C_UNK data_02100a80;
    M2C_FIELD(&data_02100a80, M2C_UNK (**)(), 4)();
}

void func_02074310(s32 arg0, s32 arg1, void *arg2) {
    extern void *data_0213ea14;
    M2C_FIELD(arg2, void **, 0) = (void *) data_0213ea14;
    M2C_FIELD(arg2, s32 *, 4) = arg1;
    M2C_FIELD(arg2, s32 *, 8) = arg0;
    data_0213ea14 = arg2;
}

#pragma opt_common_subs off
s32 func_02074330(M2C_UNK arg0,s32 arg1,M2C_UNK *arg2){
u8 *p=(u8 *)arg0;u8 *q=(u8 *)arg1;s32 num;u8 t,u;
*(s32 *)arg2=0;if(!arg1)return 1;
if(*(u8 *)arg1=='P'){
if(*++q=='V')q++;
if(*q=='K')q++;
if(*q=='v' && (*p=='P'||*p=='*'))return 1;
}
q=(u8 *)arg1;
t=*p;
if(t=='!'||*p=='*'){
if(*p++!=*q++)return 0;
compare:
t=*p;
if(t==*q++){
p++;
if(t!='!')goto compare;
num=0;
if(*p!='!')do{num=num*10+*p-'0';p++;}while(*p!='!');
*(s32 *)arg2=num;return 1;
}
while(*p++!='!'){}
while(*p++!='!'){}
if(!*p)return 0;
q=(u8 *)arg1+1;goto compare;
}
goto check;
prefix:
u=*++q;p++;
if(u=='K'){
q++;if(*p=='K')p++;
t=*p;if(t=='K')return 0;
}
if(*q=='V'){
if(t=='V')p++;
q++;if(*p=='V')return 0;
}
check:
t=*p;
if(t=='P'||t=='R'){if(t==*q)goto prefix;}
while(t==*q){
if(t==0)return 1;
t=*++p;++q;
}
return 0;
}
#pragma opt_common_subs reset
s32 func_020744e0(void *arg0) {
    s32 temp;
    s32 *p;
    s32 i;

    temp = M2C_FIELD(arg0, s32 *, 0x60);
    p = (s32 *)(M2C_FIELD(arg0, s32 *, 0x18) + temp -
                (M2C_FIELD(arg0, u8 *, 0x6A) != 0 ? 0x10 : 0));
    for (i = 15; i >= 0; i--) {
        if (M2C_FIELD(arg0, u16 *, 0x68) & (1 << i)) {
            p--;
            ((s32 *)arg0)[i + 7] = *p;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x14) = M2C_FIELD(arg0, s32 *, 0x18) + temp;
    return M2C_FIELD(arg0, s32 *, 0x54);
}

void func_0207453c(void *arg0, void *arg1) {
    void *func_02072bac(void *, M2C_UNK *);
    void *temp_r1;
    void *temp_r0_2;
    u8 flags;
    s32 temp_r4;
    s32 temp_r5;
    s8 var_r2;
    s8 var_r2_2;
    s8 var_r0;

    temp_r1 = M2C_FIELD(arg1, void **, 4);
    flags = M2C_FIELD(temp_r1, u8 *, 0);
    temp_r4 = flags & 0x40;
    if (temp_r4 != 0) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    M2C_FIELD(arg0, u8 *, 0x6B) = var_r2;
    if (flags & 0x20) {
        var_r2_2 = 1;
    } else {
        var_r2_2 = 0;
    }
    temp_r5 = flags & 0x80;
    M2C_FIELD(arg0, u8 *, 0x6A) = var_r2_2;
    if (temp_r5 != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    M2C_FIELD(arg0, u8 *, 0x6C) = var_r0;
    M2C_FIELD(arg0, u16 *, 0x68) = (u16) (M2C_FIELD(temp_r1, u8 *, 1) << 4);
    M2C_FIELD(arg0, u16 *, 0x68) = (u16) (M2C_FIELD(arg0, u16 *, 0x68) | 0x4000);
    temp_r0_2 = func_02072bac((u8 *)temp_r1 + 2, (M2C_UNK *)((u8 *)arg0 + 0x60));
    if (temp_r4 != 0) {
        func_02072bac(temp_r0_2, (M2C_UNK *)((u8 *)arg0 + 0x64));
    }
    if (temp_r4 != 0) {
        if (temp_r5 != 0) {
            M2C_FIELD(arg0, s32 *, 0x18) = M2C_FIELD(arg0, s32 *, 0x38);
        } else {
            M2C_FIELD(arg0, s32 *, 0x18) = M2C_FIELD(arg0, s32 *, 0x48);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x18) = M2C_FIELD(arg0, s32 *, 0x14);
    }
}

s32 __FindExceptionTable(void *arg0) {
extern u8 __exception_table_start__,__exception_table_end__;
M2C_FIELD(arg0,void **,12)=&__exception_table_start__;
M2C_FIELD(arg0,void **,16)=&__exception_table_end__;
return 1;
}

void func_020745fc(u8 *arg0) {
    void *func_02072bac(void *, M2C_UNK *);
    M2C_UNK sp0;
    u8 temp_r4;
    void *temp_r0;

    temp_r4 = *arg0;
    temp_r0 = func_02072bac(arg0 + 2, &sp0);
    if (!(temp_r4 & 0x40)) {
        return;
    }
    func_02072bac(temp_r0, &sp0);
}

void func_020746f0(void) {
    M2C_UNK func_02072a68();
    func_02072a68();
}

s32 func_020746fc(s32 unused,u8 *arg1) {
u32 n=M2C_FIELD(arg1,u16 *,12);
s32 sum=0,i;
if(n>0x400)return 0;
arg1+=8;
for(i=8;i<(s32)n;i++)sum+=*arg1++;
return sum;
}

s32 func_02074734(s32 unused,void *arg1) {
u16 a,b; u8 type;
if(M2C_FIELD(arg1,s32 *,0)!=0x32777364)return 0;
if(M2C_FIELD(arg1,u16 *,12)>0x400U)return 0;
type=M2C_FIELD(arg1,u8 *,14);
if(type>=0x3bU)return 0;
if(M2C_FIELD(arg1,u8 *,15)!=1)return 0;
if(type!=1) {
a=M2C_FIELD(arg1,u16 *,16);
if(a>0x100U && a!=0xffff)return 0;
b=M2C_FIELD(arg1,u16 *,18);
if(b>0x100U && b!=0xffff)return 0;
}
return 1;
}

u8 func_020747c8(s32 arg0,void *arg1) {
u8 result;
if(M2C_FIELD(arg1,s32 *,4)==func_020746fc(arg0,arg1))result=1;else result=0;
return result;
}

s32 func_020747ec(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_ip;
    s32 var_r3;
    s32 off;
    s32 quot;
    s32 off2;
    s32 quot2;
    u16 temp_r2;
    u16 temp_r2_2;

    var_ip = (arg1 * 0xC) + arg0;
    var_r3 = var_ip;
loop_1:
    temp_r2 = M2C_FIELD(var_r3, u16 *, 8);
    if (temp_r2 != 0xFFFF) {
        if (temp_r2 == arg1) {
            return 0;
        }
        if ((((s32) M2C_FIELD((arg0 + ((s32) temp_r2 >> 2)), u8 *, 0xC0C) >> ((u32) (temp_r2 << 0x1E) >> 0x1D)) & 3) != 3) {
            return 0;
        }
        off = var_r3 - arg0;
        quot = off / 12;
        var_r3 = (temp_r2 * 0xC) + arg0;
        if (M2C_FIELD(var_r3, u16 *, 0xA) != (u16) quot) {
            return 0;
        }
        if (M2C_FIELD(var_r3, u8 *, 6) != M2C_FIELD(var_ip, u8 *, 6)) {
            return 0;
        }
        goto loop_1;
    }
    temp_r3 = var_ip;
loop_11:
    temp_r2_2 = M2C_FIELD(var_ip, u16 *, 0xA);
    if (temp_r2_2 != 0xFFFF) {
        if (temp_r2_2 == arg1) {
            return 0;
        }
        if ((((s32) M2C_FIELD((arg0 + ((s32) temp_r2_2 >> 2)), u8 *, 0xC0C) >> ((u32) (temp_r2_2 << 0x1E) >> 0x1D)) & 3) != 3) {
            return 0;
        }
        off2 = var_ip - arg0;
        quot2 = off2 / 12;
        var_ip = (temp_r2_2 * 0xC) + arg0;
        if (M2C_FIELD(var_ip, u16 *, 8) != (u16) quot2) {
            return 0;
        }
        if (M2C_FIELD(var_ip, u8 *, 6) != M2C_FIELD(temp_r3, u8 *, 6)) {
            return 0;
        }
        goto loop_11;
    }
    return 1;
}

