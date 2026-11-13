/* 12 functions from 0x02017158 to 0x020180C8 (main), found by ds-decomp. */
#include "common.h"
/* Multiboot (DS Download Play) library state. */
typedef struct MbState {
    u16 field00;  /* +0x00 */
    u32 stackTop; /* +0x04 top of the task stack area */
    void *ctx;    /* +0x08 multiboot context */
    u8 *work;     /* +0x0c multiboot work area */
} MbState;
/* Front of the multiboot context: session sizes, the task entry and its callback. */
typedef struct MbContext {
    u8 pad00[0x32];
    u16 reason;   /* +0x32 start reason written by the caller */
    u16 field34;  /* +0x34 */
    u16 field36;  /* +0x36 */
    u8 pad38[0x500 - 0x38];
    u16 bufSize;  /* +0x500 parent buffer size */
    u16 field502; /* +0x502 */
    u8 pad504[0x508 - 0x504];
    s32 handler;   /* +0x508 task entry function */
    u8 pad50c[0x518 - 0x50C];
    u16 field518;  /* +0x518 */
    u16 field51A;  /* +0x51A */
    s32 callback;  /* +0x51C message callback */
    u8 pad520[0x524 - 0x520];
    u16 field524;  /* +0x524 */
} MbContext;
extern MbState gMbState;
extern M2C_UNK gMbParam;
extern M2C_UNK data_02136c60;
typedef struct DispatchBlock171 { u32 words[32]; } DispatchBlock171;
typedef struct DispatchRecord171 { u8 pad[0xca]; u8 id[6]; u8 padD0[0x26]; u16 value; DispatchBlock171 block; u8 end[8]; } DispatchRecord171;

#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_02017158(void *arg0) {
    void func_020170e8(void *);
    s32 func_02017ff8(void);
    s32 func_02013d4c(void *, u16, u16, u16, u16);
    s32 func_020124c4(void *, void *);
    s32 func_02012740(void *, s32, s32, s32, s32);
    s32 func_020122ac(void *);
    s32 func_02012a64(void *, s32, u16, void *, u16, u16, u16, s32, s32, s32, s32);
    s32 func_02018438(s32, s32);
    s32 func_02011a20(s32, void *, s32);
    s32 func_020167d0(void *);
    s32 func_02016840(void);
    void func_020168f0(void *);
    void DC_InvalidateRange(void *, s32);
    void func_02007a74(u16, void *, void *, s32);
    void func_02007e20(void *, void *, s32);
    u8 *base;
    s32 i;
    void *event;
    u8 *records;
    event=arg0;
    base=M2C_FIELD(&gMbState, u8 **, 8);
    switch ((s32)M2C_FIELD(event, u16 *, 0)) {
    case 0:
        if (M2C_FIELD(event,u16 *,2)) { M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event); return; }
        M2C_FIELD(base,void (**)(s32,void *),0x51c)(21,event);
        func_02018438(29,func_02013d4c(func_02017158,M2C_FIELD(&gMbParam,u16 *,6),M2C_FIELD(&gMbParam,u16 *,2),M2C_FIELD(&gMbParam,u16 *,0),M2C_FIELD(&gMbParam,u16 *,4)));
        return;
    case 29:
        if (M2C_FIELD(event,u16 *,2)) { M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event); return; }
        M2C_FIELD(&gMbState,void **,0x20)=base+0x440;
        if (!M2C_FIELD(&gMbState,u16 *,0x24)) M2C_FIELD(&gMbState,u16 *,0x24)=1;
        if (!M2C_FIELD(&gMbState,u16 *,0x26)) M2C_FIELD(&gMbState,u16 *,0x26)=200;
        M2C_FIELD(&gMbState,u8 *,0x28)=255;
        M2C_FIELD(&gMbState,u8 *,0x29)=255;
        M2C_FIELD(&gMbState,u8 *,0x2a)=255;
        M2C_FIELD(&gMbState,u8 *,0x2b)=255;
        M2C_FIELD(&gMbState,u8 *,0x2c)=255;
        M2C_FIELD(&gMbState,u8 *,0x2d)=255;
        M2C_FIELD(base,s32 *,0x5e4)=1;
        M2C_FIELD(base,s32 *,0x5e8)=1;
        func_02018438(10,func_020124c4(func_02017158,&data_02136c60)); return;
    case 10:
        if (M2C_FIELD(event,u16 *,2)) { M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event); return; }
        switch((s32)M2C_FIELD(event,u16 *,8)) {
        case 3: return;
        case 5:
            records=base+0x600;
            for(i=0;i<M2C_FIELD(base+0x500,u16 *,0xe0);i++){
                s32 e,d,c,b,a;
                e=0; a=e; d=e; c=e; b=e;
                if(M2C_FIELD(event,u8 *,10)==M2C_FIELD(records+i*0x180,u8 *,202) && M2C_FIELD(event,u8 *,11)==M2C_FIELD(records+i*0x180,u8 *,203))a=1;
                if(a && M2C_FIELD(event,u8 *,12)==M2C_FIELD(records+i*0x180,u8 *,204))b=1;
                if(b && M2C_FIELD(event,u8 *,13)==M2C_FIELD(records+i*0x180,u8 *,205))c=1;
                if(c && M2C_FIELD(event,u8 *,14)==M2C_FIELD(records+i*0x180,u8 *,206))d=1;
                if(d && M2C_FIELD(event,u8 *,15)==M2C_FIELD(records+i*0x180,u8 *,207))e=1;
                if(e) {
                    M2C_FIELD(records+i*0x180,u16 *,0xf6)=M2C_FIELD(event,u16 *,0x36);
                    M2C_FIELD(records+i*0x180,DispatchBlock171 *,0xf8)=M2C_FIELD(event,DispatchBlock171 *,0x38);
                    DC_InvalidateRange(base+0x600+i*0x180,0xc0);
                    func_02007a74(M2C_FIELD(&gMbState,u16 *,0),base+0x440,base+0x600+i*0x180,0xc0);
                    M2C_FIELD(base,s32 *,0x5ec)=i;
                    goto found;
                }
            }
            if(i<16) {
                M2C_FIELD(base+0x500,u16 *,0xe0)=i+1;
                func_02007e20(event,records+i*0x180+0xc0,0xb8);
                DC_InvalidateRange(base+0x600+i*0x180,0xc0);
                func_02007a74(M2C_FIELD(&gMbState,u16 *,0),base+0x440,base+0x600+i*0x180,0xc0);
                M2C_FIELD(base,s32 *,0x5ec)=i;
            }
found:
            M2C_FIELD(base,void (**)(s32,void *),0x51c)(4,event);
            if(!M2C_FIELD(base,s32 *,0x5e4))return;
            if(M2C_FIELD(base,s32 *,0x5e8) && !func_020167d0(&data_02136c60))func_02017ff8();
            func_02018438(10,func_020124c4(func_02017158,&data_02136c60)); return;
        case 4:
            M2C_FIELD(base,void (**)(s32,void *),0x51c)(5,event);
            if(!M2C_FIELD(base,s32 *,0x5e4))return;
            if(M2C_FIELD(base,s32 *,0x5e8) && !func_020167d0(&data_02136c60))func_02017ff8();
            func_02018438(10,func_020124c4(func_02017158,&data_02136c60)); return;
        default: M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event);return;
        }
    case 11:
        if (M2C_FIELD(event,u16 *,2)) { M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event); return; }
        func_02018438(12,func_02012740(func_02017158,M2C_FIELD(base,s32 *,0x520),0,1,0)); return;
    case 12:
        if (M2C_FIELD(event,u16 *,2)) { M2C_FIELD(base+0x500,u16 *,0xe0)=0; M2C_FIELD(base,void (**)(s32,void *),0x51c)(11,event); return; }
        switch((s32)M2C_FIELD(event,u16 *,8)){
        case 6: M2C_FIELD(base+0x500,u16 *,0x2a)=0;M2C_FIELD(base+0x500,u16 *,0x28)=1;return;
        case 7:
            M2C_FIELD(base+0x500,u16 *,0xe2)=M2C_FIELD(event,u16 *,10);
            M2C_FIELD(base,void (**)(s32,void *),0x51c)(6,event);
            M2C_FIELD(base+0x500,u16 *,0x2a)=1;
            if(func_02011a20(1,func_020170e8,0))return;
            {u32 flag;
            if(M2C_FIELD(base+0x500,u16 *,0x2c))flag=0;else flag=1;
            func_02018438(14,func_02012a64(func_02017158,M2C_FIELD(base,s32 *,0x504),M2C_FIELD(base+0x500,u16 *,0x1a),base+0x40,M2C_FIELD(base+0x500,u16 *,0x18),(u16)flag,0,0,0,1,1));}return;
        case 9: M2C_FIELD(base,void (**)(s32,void *),0x51c)(10,event); M2C_FIELD(base+0x500,u16 *,0x2a)=0;M2C_FIELD(base+0x500,u16 *,0x28)=0;return;
        case 26:return;
        default:M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event);return;
        }
    case 14:
        switch((s32)M2C_FIELD(event,u16 *,4)){
        case 10: M2C_FIELD(base+0x500,u16 *,0x28)=1;if(func_02016840())M2C_FIELD(base,void (**)(s32,void *),0x51c)(25,0);return;
        case 12:break;case 13:break;
        default:M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event);return;
        }
        return;
    case 15:
        M2C_FIELD(base,u8 *,0x50c)=0;
        if(M2C_FIELD(event,u16 *,2)==0) M2C_FIELD(base,void (**)(s32,void *),0x51c)(8,event);
        else if(M2C_FIELD(event,u16 *,2)==9)M2C_FIELD(base,void (**)(s32,void *),0x51c)(41,event);
        else M2C_FIELD(base,void (**)(s32,void *),0x51c)(18,event);
        if(!M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526))M2C_FIELD(base,void (**)(s32,void *),0x51c)(25,0);return;
    case 1:
        if(M2C_FIELD(event,u16 *,2)){M2C_FIELD(base+0x500,u16 *,0x26)=0;M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event);return;}
        M2C_FIELD(base+0x500,u16 *,0x2a)=0;
        M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x528)=0;
        func_02018438(2,func_020122ac(func_02017158));return;
    case 2:
        if(M2C_FIELD(event,u16 *,2)){M2C_FIELD(base+0x500,u16 *,0x26)=0;M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event);return;}func_020168f0(event);return;
    case 21: if(func_02016840())M2C_FIELD(base,void (**)(s32,void *),0x51c)(25,0);return;
    case 128: switch((s32)M2C_FIELD(event,u16 *,4)){case 22:func_02007958();return;case 23:return;}return;
    default: M2C_FIELD(base,void (**)(s32,void *),0x51c)(0x100,event);return;
    }
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
u32 func_02017984(void){u8 buf[6];s32 i;u32 sum;u8 *p;GetMacAddress(buf);i=0;p=&buf[i];sum=0;do{sum+=*p++;i++;}while(i<6);return ((sum+*(u32 *)0x27ffc3c)*7)%20;}

#pragma opt_common_subs off
s32 func_020179ec(u32 arg0, u8 *arg1, s32 arg2, u32 arg3, u32 arg4) {
    void CpuFill(s32, void *, s32);
    void FillU16(s32, void *, s32);
    void MI_CpuCopy8(void *, void *, s32);
    u16 func_02012084(void);
    s32 OS_DisableInterrupts(void);
    u32 func_02017984(void);
    u32 a, b, id;
    u16 *d, *p, *s, *e;
    void *g;
    u16 v;
    s32 t, i, j;
    s32 n;

    if (M2C_FIELD(&gMbState, void **, 0xc) != NULL &&
        M2C_FIELD(M2C_FIELD(&gMbState, void **, 0xc), u16 *, 0x1316) != 0)
        return 2;
    a = (arg0 + 0x1f) & ~0x1f;
    b = (a + 0x1e1f) & ~0x1f;
    id = arg3;
    if (arg3 == 0x10000)
        id = func_02012084();
    t = OS_DisableInterrupts();
    M2C_FIELD(&gMbParam, u16 *, 6) = 0xffff;
    M2C_FIELD(&gMbParam, u16 *, 0) = 5;
    M2C_FIELD(&gMbParam, u16 *, 2) = 0x28;
    M2C_FIELD(&gMbParam, u16 *, 4) = 0x28;
    M2C_FIELD(&gMbParam, s32 *, 0xc) = 1;
    M2C_FIELD(&gMbState, u16 *, 0) = arg4;
    M2C_FIELD(&gMbState, u32 *, 8) = a;
    M2C_FIELD(&gMbState, u32 *, 0xc) = b;
    CpuFill(0, (void *)a, 0x1e00);
    FillU16(0, (void *)b, 0x1340);
    i = 0;
    d = (u16 *)(a + 0x530);
    if ((n = arg1[1]) > i) {
        do {
            *d++ = M2C_FIELD(arg1 + 2, u16 *, i * 2);
            i++;
        } while ((n = arg1[1]) > i);
    }
    e = (u16 *)(a + 0x538);
    g = &gMbParam;
    i = 0;
    do {
        v = *M2C_FIELD(g, u16 **, 8);
        if (v == 0)
            break;
        i++;
        M2C_FIELD(g, u16 **, 8)++;
        *e++ = v;
    } while (i < 16);
    MI_CpuCopy8(arg1, (void *)(b + 0x1300), 0x16);
    if (arg1[1] < 10)
        M2C_FIELD((u8 *)b + 0x1302, u16 *, arg1[1] * 2) = 0;
    s = (u16 *)(a + 0x500);
    s[0] = 0x100;
    s[1] = 8;
    s[0xc] = 0;
    s[0xd] = 0;
    s[0x16] = 1;
    M2C_FIELD(a, u32 *, 0x504) = b + 0x400;
    M2C_FIELD(a, u16 *, 0xe) = 0;
    M2C_FIELD(a, u16 *, 0x12) = 0;
    M2C_FIELD(a, u16 *, 0x16) = 1;
    M2C_FIELD(a, u16 *, 0x14) = 0;
    M2C_FIELD(a, s32 *, 8) = arg2;
    M2C_FIELD(a, u16 *, 0xc) = id;
    M2C_FIELD(a, u16 *, 0x18) = func_02017984() + 0xc8;
    M2C_FIELD(a, u16 *, 0x10) = 0xf;
    M2C_FIELD(a, u8 *, 0x50c) = 0;
    M2C_FIELD(a, u8 *, 0x50d) = 0;
    M2C_FIELD(b, u16 *, 0x1316) = 1;
    M2C_FIELD(b, s32 *, 0x131c) = 0;
    OS_RestoreInterrupts(t);
    return 0;
}
#pragma opt_common_subs reset
s32 func_02017bd0(u32 arg0, u32 arg1, s32 arg2) {
    if ((arg0 > 0x1FEU) || (arg0 < 0xE4U)) {
        return 0;
    }
    if ((arg1 > 0x10U) || (arg1 < 8U)) {
        return 0;
    }
    if ((s32) ((arg2 * (((arg1 + 0x20) * 4) + 0x70)) + (((arg0 + 0x26) * 4) + 0x14A)) < 0x15E0) {
        return 1;
    }
    return 0;
}

s32 func_02017c40(u32 a,u32 b){
s32 t;
t=OS_DisableInterrupts();
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50d)){OS_RestoreInterrupts(t);return 0;}
if(!func_02017bd0(a,8,b)){OS_RestoreInterrupts(t);return 0;}
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,16)=b;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x500)=a;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x502)=8;
OS_RestoreInterrupts(t);
return 1;
}

#pragma push
#pragma peephole off
s32 func_02017cd8(void) {
s32 v; void *p;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x528)=0;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52a)=0;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)=0;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x548)=0;
func_02018254(10); p=&gMbState;
if(!M2C_FIELD(M2C_FIELD(p,void **,12),s32 *,0x1320)) {
do { v=func_02012218(M2C_FIELD(&gMbState,s32 *,4),M2C_FIELD(M2C_FIELD(&gMbState,void **,8),s32 *,0x508),M2C_FIELD(&gMbState,u16 *,0)); } while(v==4);
if(v!=2)return 8;
func_020119dc(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),s32 *,0x508));
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50d)=1;
return 0;
}
func_020119dc(M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,0x508));
M2C_FIELD(M2C_FIELD(p,void **,8),u8 *,0x50d)=1;
func_020168a0(); return 0;
}
#pragma pop
/* Resets the multiboot (DS Download Play) parent state: lays out its work buffers, sizes and
 * callbacks, clears the child slots, then runs the multiboot task until it finishes. */
s32 MultiBoot_Init(s32 reason) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    void FillU16(s32, void *, s32);
    void func_02013e70(s32);
    void func_02018910(s32);
    void func_02018940(void *);
    void func_02016200(void);
    s32 func_02017cd8(void);
    s32 func_02009e8c(s32, s32);
    void func_020140c4(void);
    void func_02016934(void);
    void MI_CpuFill8(void *, s32, s32);

    s32 state;
    s32 i;
    s32 res;
    u8 *base;

    state = OS_DisableInterrupts();

    ((MbContext *)gMbState.ctx)->reason = reason;

    base = gMbState.work;
    gMbState.stackTop = ((u32)base + 0x1F + 0x7D00) & ~0x1FU;

    {
        s32 r6 = M2C_FIELD(base + 0x1000, s32 *, 0x4E4);
        FillU16(0, base + 0x1340, 0x69C0);
        func_02013e70(r6);
    }

    M2C_FIELD(gMbState.work + 0x1000, s32 *, 0x318) =
        ((MbContext *)gMbState.ctx)->bufSize - 6;

    func_02018910(((MbContext *)gMbState.ctx)->field502);

    func_02018940(gMbState.work + 0x1538);

    i = 0;
    do {
        M2C_FIELD(gMbState.work + i * 4 + 0x1000, s32 *, 0x4E8) = 0;
        M2C_FIELD(gMbState.work + i + 0x1000, s8 *, 0x526) = -1;
        i++;
    } while (i < 15);

    M2C_FIELD(gMbState.work + 0x1000, u8 *, 0x524) = 0;

    FillU16(0, gMbState.work + 0x1788, 0x5D40);

    MI_CpuFill8(gMbState.work + 0x1754, 0, 0x1E);

    ((MbContext *)gMbState.ctx)->field524 = 1;

    ((MbContext *)gMbState.ctx)->callback = (s32 *)func_020140c4;
    ((MbContext *)gMbState.ctx)->handler = (s32 *)func_02016934;

    ((MbContext *)gMbState.ctx)->field34 = ((MbContext *)gMbState.ctx)->bufSize;

    ((MbContext *)gMbState.ctx)->field518 =
        (((MbContext *)gMbState.ctx)->field34 + 0x23) & ~0x1FU;

    ((MbContext *)gMbState.ctx)->field36 = ((MbContext *)gMbState.ctx)->field502;

    ((MbContext *)gMbState.ctx)->field51A =
        (((( ((MbContext *)gMbState.ctx)->field36 + 0xE) * 15) + 0x29) & ~0x1FU) << 1;

    func_02016200();
    res = func_02017cd8();
    OS_RestoreInterrupts(state);

    M2C_FIELD(gMbState.work + 0x7000, u32 *, 0x4C8) = func_02009e8c(0xF, 0x1);

    (void)i;
    return res;
}

void func_02017f90(s32 a){M2C_FIELD(M2C_FIELD(&gMbState,void **,12),s32 *,0x1320)=1;MultiBoot_Init(a);}

s32 func_02017fb4(void) {
    s32 func_02012274(s32);
    M2C_UNK func_02018438(M2C_UNK, s32);
        s32 var_r4;

    var_r4 = func_02012274(M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), s32 *, 0x508));
    func_02018438(1, var_r4);
    if (var_r4 == 2) {
        var_r4 = 0;
    }
    return var_r4;
}

void func_02017fec(void) {
    M2C_UNK func_02017fb4();
    func_02017fb4();
}

s32 func_02017ff8(void){s32 t;u32 v=1;t=OS_DisableInterrupts();if(!M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50d))func_020168f0(0);else if(!M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),s32 *,0x5e4)=0;M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)=v;v=func_0201871c();if(v){func_020188c8(func_02017fec);v=0;}else v=func_02017fb4();}OS_RestoreInterrupts(t);return v;}
#pragma pop
void func_0201808c(void){s32 t=OS_DisableInterrupts();if(!M2C_FIELD(M2C_FIELD(&gMbState,void **,12),s32 *,0x1320))func_02007958();func_02017ff8();OS_RestoreInterrupts(t);}

