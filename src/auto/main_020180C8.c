/* 37 functions from 0x020180C8 to 0x02018FF0 (main), found by ds-decomp. */
#include "common.h"

#pragma optimization_level 2
void func_020180c8(s32 arg0) {
extern M2C_UNK gMbState;
void func_02016934(void *);
void func_02018960(s32);
M2C_UNK MI_CpuFill8(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_0201280c(void (*)(void *),s32);
s32 i,temp,off;u16 v1,v2;u8 *q;
func_0201280c(func_02016934,arg0);
if(arg0==0||(u32)arg0>=16)return;
i=arg0-1;
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*2+0x1400,u16*,0x8a)=0;
MI_CpuFill8((u8*)M2C_FIELD(&gMbState,void**,12)+0xa8+0x1400+i*4,0,4);
MI_CpuFill8((u8*)M2C_FIELD(&gMbState,void**,12)+0x1340+i*22,0,22);
func_02018960(arg0);
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*2+0x1700,u16*,0x54)=0;
temp=M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i+0x1500,s8*,0x26);
if(temp!=-1){
off=(u8)temp*0x5d4;
q=(u8*)M2C_FIELD(&gMbState,void**,12)+off+0x1d00;
v1=M2C_FIELD(q,u16*,0x4e);M2C_FIELD(q,u16*,0x4e)=v1&~(1<<arg0);
q=(u8*)M2C_FIELD(&gMbState,void**,12)+off+0x1d00;
v2=M2C_FIELD(q,u16*,0x50);M2C_FIELD(q,u16*,0x50)=v2|(1<<arg0);
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i+0x1000,s8*,0x526)=-1;
q=(u8*)M2C_FIELD(&gMbState,void**,12)+off+0x1d00;
M2C_FIELD(q,u16*,0x4c)&=~(1<<arg0);
}
if(M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+0x1500,u16*,0x36)&(1<<arg0)){
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+0x1000,u8*,0x535)--;
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+0x1500,u16*,0x36)&=~(1<<arg0);
}
M2C_FIELD((u8*)M2C_FIELD(&gMbState,void**,12)+i*4+0x1000,u32*,0x4e8)=0;
}
#pragma optimization_level reset
void func_02018254(s16 arg0) {
    extern M2C_UNK gMbState;
    M2C_FIELD(&gMbState, s16 *, 0x26) = arg0;
}

s32 func_02018264(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4) {
    s32 WFC_SendChannelData(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    void func_02018438(M2C_UNK, s32);
    s32 temp_r0;

    temp_r0 = WFC_SendChannelData(arg0, 0, arg1, arg2, (s32) arg4, 1, 3);
    func_02018438(0xF, temp_r0);
    return temp_r0;
}

s32 func_020182b0(s32 arg0, s32 arg1, s32 arg2) {
extern M2C_UNK gMbState;
void func_02017158(void);
void *p;
s32 result;
u16 a = arg1;
u16 b = arg2;
p = M2C_FIELD(&gMbState, void **, 8);
if (M2C_FIELD(p,u16 *,0x528) == 0 || M2C_FIELD(p,u16 *,0x526) == 1) return 1;
switch (M2C_FIELD(p,u16 *,0x524)) {
case 1:
result = func_02018264(M2C_FIELD(p,s32 *,0x508),arg0,a,(u16)(M2C_FIELD(p,u16 *,0x52c) == 0 ? 1000 : 0),b);
if (result == 2) M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50c)=1;
if (result == 2) return 0;
return result;
case 2:
result = func_02018264((s32)func_02017158,arg0,a,0,b);
if (result == 2) M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50c)=1;
if (result == 2) return 0;
return result;
}
return 1;
}

s32 func_02018390(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), s32 *, 8);
}

u16 func_020183a4(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u16 *, 0xC);
}

u8 func_020183b8(void) {
    extern M2C_UNK gMbState;
    void *p = M2C_FIELD(&gMbState, void **, 8);
    u32 r2 = M2C_FIELD(p, u16 *, 0x12) != 0 ? 2 : 0;
    u32 r3 = M2C_FIELD(p, u16 *, 0xE) != 0 ? 1 : 0;
    u32 r12 = M2C_FIELD(p, u16 *, 0x14) != 0 ? 4 : 0;
    u32 r1 = M2C_FIELD(p, u16 *, 0x16) != 0 ? 8 : 0;
    return (u8)(((r3 | r2) | r12) | r1);
}

s32 func_02018418(void) {
    extern M2C_UNK gMbState;
    return M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), u8 *, 0x50d) == 1;
}

void func_02018438(s32 arg0, s32 arg1) {
 extern M2C_UNK gMbState;
 u16 buf[2];
 void *p;
 if (arg1 == 2 || arg1 == 0) return;
 buf[0]=arg0;
 p=M2C_FIELD(&gMbState,void **,8);
 buf[1]=arg1;
 M2C_FIELD(p,void (**)(u8,void *),0x51c)((u8)(arg0 | 255),buf);
}

void func_02018470(M2C_UNK arg0) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0x70);
}

void func_02018484(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4){
s32 OS_DisableInterrupts();void OS_RestoreInterrupts(s32);void SystemHalt();
u32 end; s32 saved; u32 p;
saved=OS_DisableInterrupts();p=arg0+0x30;end=arg0+0x70;
for(;;){
if(p>=end)SystemHalt();
if(M2C_FIELD(p,s32 *,12)==0){
M2C_FIELD(p,s32 *,0)=arg1;M2C_FIELD(p,s32 *,4)=arg2;M2C_FIELD(p,s32 *,8)=arg3;M2C_FIELD(p,s32 *,12)=arg4;break;
}
p+=16;
}
OS_RestoreInterrupts(saved);
}

s32 func_020184ec(s32 *arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    s32 OS_DisableInterrupts(void);
    void MI_CpuCopy8(s32, M2C_UNK, s32);
    void OS_RestoreInterrupts(s32);
    u8 *end;
    s32 result;
    u8 *p;
    s32 temp_r0;
    s32 saved;
    result = 0;
    saved = OS_DisableInterrupts();
    p = (u8 *)arg0 + 0x30;
    end = (u8 *)arg0 + 0x70;
    for (; p < end; p += 0x10) {
        if (M2C_FIELD(p, u32 *, 0xC) >= 2U) {
            temp_r0 = arg1 - M2C_FIELD(p, s32 *, 0);
            if (0 <= temp_r0) {
                if ((u32)(temp_r0 + arg3) <= (u32)M2C_FIELD(p, u32 *, 4)) {
                    MI_CpuCopy8(M2C_FIELD(p, s32 *, 8) + temp_r0, arg2, arg3);
                    result = 1;
                    *arg0 = 0;
                    break;
                }
            }
        }
    }
    OS_RestoreInterrupts(saved);
    return result;
}

void func_02018584(void *r7) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void func_02005f80(void *, s32);
    void OS_SleepThread(s32);
    s32 func_02006028(void *);
    void func_02005bbc(void);

    s32 saved;
    void *r4;
    void (*r6)(void *);

    while (1) {
        saved = OS_DisableInterrupts();
        if (*(void **)((u8 *)r7 + 0xc0) == (void *)0) {
            do {
                r6 = (void (*)(void *))0;
                r4 = (void *)0;
                func_02005f80(r7, 0);
                OS_SleepThread(0);
            } while (*(void **)((u8 *)r7 + 0xc0) == (void *)0);
        }
        r4 = *(void **)((u8 *)r7 + 0xc0);
        *(void **)((u8 *)r7 + 0xc0) = *(void **)((u8 *)r4 + 0x0);
        func_02005f80(r7, (s32)(*(unsigned int *)((u8 *)r4 + 0x4) >> 1));
        OS_RestoreInterrupts(saved);
        if (*(void **)((u8 *)r4 + 0x8) != (void *)0) {
            ((void (*)(void *))(*(void **)((u8 *)r4 + 0x8)))(r4);
        }
        saved = OS_DisableInterrupts();
        r6 = (void (*)(void *))(*(void **)((u8 *)r4 + 0xc));
        {
            s32 val = func_02006028(r7);
            s32 adj;
            void *p = *(void **)((u8 *)r7 + 0xc0);
            if (p == (void *)0) {
                adj = 0;
            } else {
                unsigned int half = *(unsigned int *)((u8 *)p + 0x4) >> 1;
                if ((unsigned int)val < half) {
                    adj = (s32)half;
                } else {
                    adj = val;
                }
            }
            if (adj != val) {
                func_02005f80(r7, adj);
            }
        }
        *(void **)((u8 *)r4 + 0x0) = (void *)0;
        *(unsigned int *)((u8 *)r4 + 0x4) = *(unsigned int *)((u8 *)r4 + 0x4) & ~1u;
        if (r6 != (void (*)(void *))0) {
            r6(r4);
        }
        if (r4 != (void *)((u8 *)r7 + 0xc4)) {
            OS_RestoreInterrupts(saved);
            continue;
        }
        func_02005bbc();
        return;
    }
}

void func_0201869c(M2C_UNK arg0, s32 arg1) {
    extern s32 data_02136c80;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void func_02018738(M2C_UNK);
    void func_02005ac0(M2C_UNK, void (*)(void *), M2C_UNK, M2C_UNK, s32, s32);
    void TaskWake(M2C_UNK);
    void func_02018584(void *);
    s32 saved;
    saved = OS_DisableInterrupts();
    if (data_02136c80 == 0) {
        data_02136c80 = arg0;
        func_02018738(arg0 + 0x000000C4);
        M2C_FIELD(arg0, s32 *, 0x000000C0) = 0;
        func_02005ac0(arg0, func_02018584, arg0, arg0 + 0x000000E4 + ((arg1 - 0x000000E4) & ~3), (arg1 - 0x000000E4) & ~3, 0);
        TaskWake(arg0);
    }
    OS_RestoreInterrupts(saved);
}

s32 func_0201871c(void) {
    extern s32 data_02136c80;
    if (data_02136c80 != 0) {
        return 1;
    }
    return 0;
}

void func_02018738(M2C_UNK arg0) {
    MI_CpuFill8(arg0, 0, 0x20);
}

s32 func_0201874c(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, s32 *, 4) << 0x1F) >> 0x1F) != 0) {
        return 1;
    }
    return 0;
}

void func_02018764(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    extern s32 data_02136c80;
    s32 func_0201871c(void);
    s32 func_02006028(void *);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void TaskWake(M2C_UNK);
    s32 saved;
    void *base;
    void *p;
    s32 r6;
    base = (void *)data_02136c80;
    p = (void *)arg0;
    if (!func_0201871c()) {
        return;
    }
    if (((M2C_FIELD(p, u32 *, 4) << 31) >> 31) != 0) {
        return;
    }
    r6 = arg3;
    if ((u32)r6 > 0x1fu) {
        s32 v = func_02006028(base);
        if (r6 == 0x20) {
            r6 = (v != 0) ? v - 1 : 0;
        } else if (r6 == 0x21) {
            r6 = ((u32)v < 0x1fU) ? v + 1 : 0x1f;
        } else if (r6 == 0x22) {
            r6 = v;
        } else {
            r6 = 0x1f;
        }
    }
    saved = OS_DisableInterrupts();
    {
        u32 f4 = M2C_FIELD(p, u32 *, 4);
        u32 low = f4 & 1u;
        f4 = (f4 & ~1u) | 1u;
        M2C_FIELD(p, u32 *, 4) = f4;
        f4 = low | ((u32)r6 << 1);
        M2C_FIELD(p, u32 *, 4) = f4;
        M2C_FIELD(p, void **, 8) = (void *)arg1;
        M2C_FIELD(p, void **, 0xc) = (void *)arg2;
    }
    if (M2C_FIELD(base, void **, 0xc0) == (void *)0) {
        if (p == (void *)((u8 *)base + 0xc4)) {
            data_02136c80 = 0;
        }
        M2C_FIELD(base, void **, 0xc0) = p;
        M2C_FIELD(p, void **, 0) = (void *)0;
        TaskWake((M2C_UNK)base);
    } else {
        if (p == (void *)((u8 *)base + 0xc4)) {
            void **curp = (void **)M2C_FIELD(base, void ***, 0xc0);
            while (M2C_FIELD(curp, void **, 0) != (void *)0) {
                curp = (void **)M2C_FIELD(curp, void **, 0);
            }
            M2C_FIELD(curp, void **, 0) = p;
            data_02136c80 = 0;
        } else {
            void **head = (void **)M2C_FIELD(base, void ***, 0xc0);
            if ((u32)r6 < (M2C_FIELD(head, u32 *, 4) >> 1)) {
                M2C_FIELD(base, void **, 0xc0) = p;
                M2C_FIELD(p, void **, 0) = (void *)head;
            } else {
                void **prev = head;
                void **cur;
                for (;;) {
                    cur = (void **)M2C_FIELD(prev, void **, 0);
                    if (cur == (void *)0) {
                        break;
                    }
                    if ((u32)r6 < (M2C_FIELD(cur, u32 *, 4) >> 1)) {
                        break;
                    }
                    prev = cur;
                }
                if (cur != (void *)0) {
                    M2C_FIELD(p, void **, 0) = (void *)cur;
                } else {
                    M2C_FIELD(p, void **, 0) = (void *)0;
                }
                M2C_FIELD(prev, void **, 0) = p;
            }
        }
    }
    OS_RestoreInterrupts(saved);
}

void func_020188c8(M2C_UNK arg0) {
    extern M2C_UNK data_02136c80;
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 func_0201871c(void);
    void func_02018764(M2C_UNK, s32, M2C_UNK, s32);
    s32 saved;
    saved = OS_DisableInterrupts();
    if (func_0201871c() != 0) {
        func_02018764((M2C_UNK)((u8 *)data_02136c80 + 0xC4), 0, arg0, 0);
    }
    OS_RestoreInterrupts(saved);
}

void func_02018910(s32 arg0) {
    extern M2C_UNK data_02136c84;
    s32 func_020720f0(s32, s32);
    M2C_FIELD(&data_02136c84, s32 *, 8) = arg0 - 2;
    M2C_FIELD(&data_02136c84, s32 *, 12) = func_020720f0(0x1E, arg0 - 2);
    M2C_FIELD(&data_02136c84, s32 *, 16) = 0x1E;
}

void func_02018940(s32 arg0) {
    extern M2C_UNK data_02136c84;
    M2C_FIELD(&data_02136c84, s32 *, 4) = arg0;
    MI_CpuFill8(arg0, 0, 0x21C);
}

void func_02018960(s32 arg0) {
    extern M2C_UNK data_02136c84;
    void *base;
    s32 idx;
    
    base = M2C_FIELD(&data_02136c84, void **, 4);
    if (base == NULL) {
        return;
    }
    idx = arg0 - 1;
    MI_CpuFill8((void *)((u8 *)base + idx * 32), 0, 0x1E);
    base = M2C_FIELD(&data_02136c84, void **, 4);
    M2C_FIELD((u8 *)base + idx * 4, u32 *, 0x1E0) = 0;
}

void *SerializeCommand(void *arg0, void *arg1) {
u8 *p=arg1;
*p++=M2C_FIELD(arg0,u8 *,0);
switch(M2C_FIELD(arg0,u8 *,0)) {
case 4:
p[0]=M2C_FIELD(arg0,u16 *,2);
p[1]=(M2C_FIELD(arg0,u16 *,2)&0xff00)>>8;
p[2]=M2C_FIELD(arg0,u16 *,4);
p[3]=(M2C_FIELD(arg0,u16 *,4)&0xff00)>>8;
p+=4; break;
default: case 0: return 0;
case 1: case 2: case 3: case 5: case 6: break;
}
return p;
}

void *func_02018a28(u8 *arg0, u8 *arg1, s32 arg2) {
    extern M2C_UNK data_02136c84;
    s32 func_02018bd0(s32);
    s32 func_02018b44(u8 *, s32);
    void MI_CpuCopy8(M2C_UNK, M2C_UNK, s32);

    s32 r4 = arg2;
    u8 type = arg0[0];

    arg1[0] = type;
    switch (type) {
    case 7:
        if (func_02018bd0(r4) != 0) {
            return (void *)(M2C_FIELD(&data_02136c84, M2C_UNK *, 4) + (r4 - 1) * 32);
        }
        {
            u8 v = arg0[1];
            arg1[2] = v;
            if (v > M2C_FIELD(&data_02136c84, s32 *, 0xC)) {
                return (void *)0;
            }
            MI_CpuCopy8((M2C_UNK)(arg0 + 2), (M2C_UNK)(arg1 + 3), M2C_FIELD(&data_02136c84, s32 *, 8));
            r4 = func_02018b44(arg1, r4);
        }
        break;
    case 8:
        r4 = (s32)(arg0 + 3);
        *(u16 *)(arg1 + 2) = arg0[1];
        *(u16 *)(arg1 + 2) = (u16)(*(u16 *)(arg1 + 2) | ((arg0[2] << 8) & 0xFF00));
        break;
    case 9:
        r4 = (s32)(arg0 + 3);
        *(u16 *)(arg1 + 2) = arg0[1];
        *(u16 *)(arg1 + 2) = (u16)(*(u16 *)(arg1 + 2) | ((arg0[2] << 8) & 0xFF00));
        MI_CpuCopy8((M2C_UNK)r4, (M2C_UNK)(arg1 + 4), M2C_FIELD(&data_02136c84, s32 *, 8));
        r4 = r4 + M2C_FIELD(&data_02136c84, s32 *, 8);
        break;
    default:
        return (void *)0;
    }
    return (void *)r4;
}

s32 func_02018b44(u8 *arg0, s32 arg1) {
    extern M2C_UNK data_02136c84;
    void MI_CpuCopy8(M2C_UNK, M2C_UNK, s32);
    s32 func_02018bd0(s32);

    s32 r6 = arg1;

    if (M2C_FIELD(&data_02136c84, u32 *, 0x4) == 0) return 0;
    {
        u8 type = arg0[2];
        s32 r4;
        if (type > M2C_FIELD(&data_02136c84, s32 *, 0xC)) return 0;
        r4 = arg1 - 1;
        MI_CpuCopy8((M2C_UNK)(arg0 + 3), (M2C_UNK)(M2C_FIELD(&data_02136c84, u32 *, 0x4) + r4 * 32 + type * M2C_FIELD(&data_02136c84, s32 *, 0x8)), M2C_FIELD(&data_02136c84, s32 *, 0x8));
        *((u32 *)((u8 *)M2C_FIELD(&data_02136c84, u32 *, 0x4) + 0x1E0 + r4 * 4)) |= (1U << type);
        if (!func_02018bd0(r6)) return 0;
        return (s32)(M2C_FIELD(&data_02136c84, M2C_UNK *, 0x4) + r4 * 32);
    }
}

s32 func_02018bd0(s32 arg0) {
extern M2C_UNK data_02136c84;
u16 i;
u32 word;
s32 count;
i=0;
count=M2C_FIELD(&data_02136c84,s32 *,12);
if(count>0) {
word=M2C_FIELD(M2C_FIELD(&data_02136c84,s32 *,4)+(arg0-1)*4,u32 *,0x1e0);
do {
if(!(word&(1u<<i)))return 0;
i++;
}while(count>i);
}
return 1;
}

void func_02018c24(void) {
    M2C_UNK CpuSet(s32 *, M2C_UNK *, s32);
    s16 func_0200558c();
    extern M2C_UNK data_02136c98;
    extern M2C_UNK data_02136c9c;
    s32 sp0;

    sp0 = 0;
    CpuSet(&sp0, &data_02136c9c, 0x05000001);
    M2C_FIELD(&data_02136c98, s16 *, 6) = func_0200558c();
}

s32 func_02018c5c(void) {
    u32 func_02018c84(void);
    s32 func_02018c9c();
    if ((func_02018c9c() != 0) && (func_02018c84() == 0)) {
        return 1;
    }
    return 0;
}

u32 func_02018c84(void) {
    extern M2C_UNK data_027ffc30;
    return (u32) (M2C_FIELD(&data_027ffc30, u8 *, 5) << 0x1F) >> 0x1F;
}

s32 func_02018c9c(void) {
    extern M2C_UNK data_02136c98;
    extern M2C_UNK data_027ffc30;
    void func_02018e24(M2C_UNK, void *);
    void func_02018da8(void *);
    void func_02018df0(void *);
    void func_02018e80(M2C_UNK, void *);
    s32 buf[4];
    s32 r4;
    volatile u8 *base;
    s32 r2;

    r4 = 1;
    base = (volatile u8 *)0x08000000;

    if (M2C_FIELD(&data_027ffc30, u16 *, 0) == (u16)(0x10000 - r4)) {
        return 0;
    }
    if ((((u32)M2C_FIELD(&data_027ffc30, u8 *, 5) << 30) >> 31) == 1) {
        return 0;
    }
    func_02018e24(M2C_FIELD(&data_02136c98, u16 *, 6), (void *)(&buf[2]));
    func_02018da8((void *)buf);

    r2 = base[0xB2];
    if (r2 == 0x96) {
        if (M2C_FIELD(&data_027ffc30, u16 *, 0) != *(volatile u16 *)(base + 0xBE)) {
            goto fail;
        }
    } else {
        if (M2C_FIELD(&data_027ffc30, u16 *, 0) != *(volatile u16 *)0x0801FFFE) {
            goto fail;
        }
    }
    if (M2C_FIELD(&data_027ffc30, u32 *, 8) != *(volatile u32 *)(base + 0xAC)) {
        if (M2C_FIELD(&data_027ffc30, u8 *, 5) & 1) {
            r4 = 0;
            M2C_FIELD(&data_027ffc30, u8 *, 5) |= 2;
            func_02018df0((void *)buf);
            func_02018e80(M2C_FIELD(&data_02136c98, u16 *, 6), (void *)(&buf[2]));
        }
    }
    return r4;

fail:
    return 0;
}

void func_02018da8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((s32) (*(u16 *)0x04000204 & 0xC) >> 2);
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((s32) (*(u16 *)0x04000204 & 0x10) >> 4);
    *(u16 *)0x04000204 = (*(u16 *)0x04000204 & ~0xC) | 0xC;
    *(u16 *)0x04000204 &= ~0x10;
}

#pragma opt_propagation off
void func_02018df0(void *arg0) {
 u32 a,b;
 a=M2C_FIELD(arg0,u32 *,0);
 b=*(volatile u16 *)0x04000204;
 b &=~0xC;
 b |=a<<2;
 *(volatile u16 *)0x04000204=b;
 a=M2C_FIELD(arg0,u32 *,4);
 b=*(volatile u16 *)0x04000204;
 b &=~0x10;
 b |=a<<4;
 *(volatile u16 *)0x04000204=b;
}
#pragma opt_propagation reset
void func_02018e24(M2C_UNK arg0,void *arg1) {
M2C_UNK OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); M2C_UNK func_02005584(M2C_UNK); M2C_UNK func_020054cc(M2C_UNK); M2C_UNK WaitByLoop(M2C_UNK);
for(;;){
M2C_FIELD(arg1,s32 *,4)=OS_DisableInterrupts();
M2C_FIELD(arg1,s32 *,0)=func_02005584(0x27fffe8)&0x40;
if(M2C_FIELD(arg1,s32 *,0)!=0)return;
if(func_020054cc(arg0)==0)return;
OS_RestoreInterrupts(M2C_FIELD(arg1,s32 *,4));
WaitByLoop(1);
}
}

void func_02018e80(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_020054c0(M2C_UNK);
    void OS_RestoreInterrupts(s32);
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        func_020054c0(arg0);
    }
    OS_RestoreInterrupts(M2C_FIELD(arg1, s32 *, 4));
}

void func_02018ea4(M2C_UNK arg0) {
    M2C_UNK WaitByLoop(M2C_UNK);
    s32 func_02009eb0(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_02009eb0(0xD, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(1);
    } while (func_02009eb0(0xD, arg0, 0) != 0);
}

void func_02018ef4(s32 arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 func_02018c5c(void);
    void func_02006cc0(s32, s32);
    extern M2C_UNK data_02136c98;
    s32 saved;
    saved = OS_DisableInterrupts();
    data_02136c98 = (M2C_UNK)arg0;
    if (func_02018c5c() == 0) {
        s32 r1;
        if (arg0 != 0) {
            r1 = 0x1000;
        } else {
            r1 = 0x5000;
        }
        func_02006cc0(0xf000, r1);
    }
    OS_RestoreInterrupts(saved);
}

void func_02018f3c(void) {
    M2C_UNK func_02009d34();
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK, M2C_UNK);
    void func_02018ef4(M2C_UNK);
    M2C_UNK func_02018ff0();
    M2C_UNK func_02019294(M2C_UNK *);
    extern M2C_UNK data_02136ca0;
    extern M2C_UNK data_02136d80;
    extern M2C_UNK func_020191e4;
    extern M2C_UNK func_02019210;
    extern M2C_UNK func_02019280;
    if (M2C_FIELD(&data_02136ca0, s32 *, 8) != 0) {
        return;
    }
    M2C_FIELD(&data_02136ca0, s32 *, 8) = 1;
    func_02018c24();
    M2C_FIELD(&data_02136ca0, s32 *, 0xC) = 0;
    func_02009d34();
    do {

    } while (func_02009e8c(0xD, 1) == 0);
    func_02009e40(0xD, &func_020191e4);
    func_02018ff0();
    func_02009e40(0xD, NULL);
    func_02009e40(0xD, &func_02019210);
    M2C_FIELD(&data_02136ca0, s32 *, 0x18) = 0;
    func_02019294(&data_02136d80);
    func_02009e40(0x11, &func_02019280);
    func_02018ef4(0);
}

