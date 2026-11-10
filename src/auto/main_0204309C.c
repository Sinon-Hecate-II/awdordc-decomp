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
default:SetNetError(code,off+0xfffe90d0);break;
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
    void *GetConnection(void);
    s32 func_02061794();
    s32 func_02061784();
    void func_020616d8();
    s32 func_0204292c();
    s32 func_02060c44();
    s32 func_02060c4c();
    s32 SetConnectionState();
    void func_020436d8();
    s32 func_020436dc();
    s32 func_020438b4();
    s32 func_02060b68();
    u64 GetSystemTick(void);
    void func_020410f8();
    s32 func_0204084c();
    void func_02040878();
    void func_02040dc8();
    void TryConnectToPeer();
    s32 func_0203ecb0();
    void SendMatchmakingParameter();
    void func_02043008();
    s32 func_02043184();

    extern M2C_UNK gConnectionMgr;
    extern char sDwcKeyPid[];

    void *ctx;
    s32 i;
    s32 count;
    s32 status;
    void *unit;
    s32 kind1;
    s32 kind2;
    s32 key;

    M2C_FIELD(&gConnectionMgr, s32 *, 0x18)++;

    switch (arg1) {
    case 0:
        func_020436d8(arg2);
        ctx = GetConnection();
        M2C_FIELD(ctx, u64 *, 0x174) = GetSystemTick() + 0xefb5f7;
        break;
    case 4:
        ctx = GetConnection();
        i = 0;
        M2C_FIELD(ctx, s32 *, 0x174) = 0;
        M2C_FIELD(ctx, s32 *, 0x178) = 0;

        count = func_02061794(arg0);
        while (i < count) {
            unit = (void *)func_02061784(arg0, i);
            if (func_0204292c() == 0) {
                func_020616d8(arg0, unit);
                i--;
            }
            i++;
            count = func_02061794(arg0);
        }

        ctx = GetConnection();
        status = M2C_FIELD(ctx, s32 *, 0x1a0);

        switch (status) {
        case 2:
            i = 0;
            count = func_02061794(arg0);
            while (i < count) {
                unit = (void *)func_02061784(arg0, i);
                if (M2C_FIELD(GetConnection(), s32 *, 0x1c) != 0) {
                    if (M2C_FIELD(GetConnection(), s32 *, 0x1c) == func_02060c44(unit)) {
                        if (M2C_FIELD(GetConnection(), u16 *, 0x1a) != 0) {
                            if (M2C_FIELD(GetConnection(), u16 *, 0x1a) == func_02060c4c(unit)) {
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
            if (i < count) {
                SetConnectionState(3);
                ctx = GetConnection();
                M2C_FIELD(ctx, s32 *, 0x204) = 0;
                ctx = GetConnection();
                SendMatchmakingParameter(M2C_FIELD(ctx, u32 *, 0x204));
                func_02043008();
            } else {
                ctx = GetConnection();
                M2C_FIELD(ctx, s32 *, 0xe8) = 2;
                ctx = GetConnection();
                M2C_FIELD(ctx, u64 *, 0xec) = GetSystemTick();
            }
            break;
        case 3:
            ctx = GetConnection();
            M2C_FIELD(ctx, s32 *, 0xe8) = 2;
            ctx = GetConnection();
            M2C_FIELD(ctx, u64 *, 0xec) = GetSystemTick();
            break;
        case 5:
            func_020436dc(1);
            func_020438b4();

            while (1) {
                count = func_02061794(arg0);
                if (count == 0) break;
                unit = (void *)func_02061784(arg0, 0);
                kind1 = func_02060c44(unit);
                ctx = GetConnection();
                if (kind1 != M2C_FIELD(ctx, s32 *, 0x1b8)) {
                    func_020616d8(arg0, unit);
                    continue;
                }
                kind2 = func_02060c4c(unit);
                ctx = GetConnection();
                if (kind2 == (s32)M2C_FIELD(ctx, u16 *, 0x1b4)) {
                    break;
                }
                func_020616d8(arg0, unit);
            }

            count = func_02061794(arg0);
            if (count == 0) {
                ctx = GetConnection();
                M2C_FIELD(ctx, s32 *, 0xe8) = 2;
                ctx = GetConnection();
                M2C_FIELD(ctx, u64 *, 0xec) = GetSystemTick();
            } else {
                unit = (void *)func_02061784(arg0, 0);
                key = func_02060b68(unit, sDwcKeyPid, 0);
                if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 1 && key == M2C_FIELD(GetConnection(), s32 *, 0xf4)) {
                    if (func_020436dc(0) != 0) {
                        ctx = GetConnection();
                        if (M2C_FIELD(ctx, u8 *, 0x0d) != 0) {
                            func_020410f8();
                            if (func_0204084c() != 0) goto cleanup;
                        }
                    } else {
                        ctx = GetConnection();
                        func_02040dc8((void *)M2C_FIELD(ctx, s32 *, 0xf4));
                        if (func_0204084c() != 0) goto cleanup;
                        SetConnectionState(4);
                        ctx = GetConnection();
                        TryConnectToPeer(0, 0, M2C_FIELD(ctx, s32 *, 0xf4));
                        if (func_0204084c() != 0) goto cleanup;
                        goto cleanup;
                    }
                }
                SetConnectionState(6);
                unit = (void *)func_02061784(arg0, 0);
                func_0203ecb0(0, 0, (s32)unit);
                func_02043184(0, 0, 0);
                goto cleanup;
            }
            break;
        default:
            ctx = GetConnection();
            M2C_FIELD(ctx, u64 *, 0x174) = GetSystemTick() + 0xefb5f7;
            break;
        }
        break;
    case 5:
        break;
    }

cleanup:
    M2C_FIELD(&gConnectionMgr, s32 *, 0x18)--;
    return;
}

void func_020436d8(void) {

}

#pragma opt_strength_reduction off
s32 func_020436dc(s32 sort) {
 void *GetConnection(void);s32 func_02061794(s32);s32 func_02061784(s32,s32);s32 func_02060b68(void *,void *,s32);s32 gpiPlayerSetInt(void *,void *,s32);s32 func_020617a4(s32,s32,void *,s32);s32 func_02037eec(s32);void func_020616d8(s32,void *);
 extern char sDwcKeyPid[],sDwcKeyEval[];
 s32 removed=0; s32 found,weight;void *ctx; s32 key; s32 i=0; s32 j;void *item;
 for(;i<func_02061794(M2C_FIELD(GetConnection(),s32 *,0xe4));i++) {
 item=(void *)func_02061784(M2C_FIELD(GetConnection(),s32 *,0xe4),i);
 if(M2C_FIELD(GetConnection(),u8 *,0x15)==0) {
 key=func_02060b68(item,sDwcKeyPid,0);found=0;
 for(j=1;j<=M2C_FIELD(GetConnection(),u8 *,0xd);j++) {
 if(key==M2C_FIELD((u8 *)GetConnection()+j*4,s32 *,0xf4)) {
 func_020616d8(M2C_FIELD(GetConnection(),s32 *,0xe4),item);i--;found=1;break;
 }}
 if(found)continue;
 }
 if(M2C_FIELD(GetConnection(),s32 *,0x474)) {
 ctx=GetConnection();
 weight=M2C_FIELD(ctx,s32 (**)(s32,s32),0x474)(i,M2C_FIELD(GetConnection(),s32 *,0x478));
 if(weight>0) {if(weight>0x7fffff)weight=0x7fffff;gpiPlayerSetInt(item,sDwcKeyEval,func_02037eec(256)|(weight<<8));}
 else {func_020616d8(M2C_FIELD(GetConnection(),s32 *,0xe4),item);i--;removed=1;}
 }else gpiPlayerSetInt(item,sDwcKeyEval,func_02037eec(128));
 }
 if(sort && func_02061794(M2C_FIELD(GetConnection(),s32 *,0xe4))!=0)func_020617a4(M2C_FIELD(GetConnection(),s32 *,0xe4),0,sDwcKeyEval,0);
 if(removed && func_02061794(M2C_FIELD(GetConnection(),s32 *,0xe4))==0)return 0;
 return 1;
}
s32 func_020438b4(void) {
    void *GetConnection(void);
    s32 func_02061794(s32);
    s32 func_02061784(s32, s32);
    s32 func_02060b68(void *, void *, s32);
    s32 gpiPlayerSetInt(void *, void *, s32);
    s32 func_020617a4(s32, s32, void *, s32);
    s32 func_02037eec(s32);
    s32 func_020720f0(s32, s32);
    extern s32 data_020ea928[];
    extern char sDwcKeyEval[];
    u32 rnd;
    s32 best = 0;
    s32 total = 0;
    s32 n;
    s32 i;
    s32 stack[6];
    s32 prev;
    s32 v;
    s32 tmp;

    n = func_02061794(*(s32 *)((u8 *)GetConnection() + 0xE4));
    if (n <= 1) return n;
    i = 0;
    while (i < func_02061794(*(s32 *)((u8 *)GetConnection() + 0xE4))) {
        v = func_02060b68((void *)func_02061784(*(s32 *)((u8 *)GetConnection() + 0xE4), i), sDwcKeyEval, -1);
        if (v > best) best = v;
        total += data_020ea928[i];
        i++;
    }
    rnd = func_02037eec(100);
    i = 0;
    while (i < func_02061794(*(s32 *)((u8 *)GetConnection() + 0xE4))) {
        if (i == func_02061794(*(s32 *)((u8 *)GetConnection() + 0xE4)) - 1) break;
        prev = (i > 0) ? stack[i - 1] : 0;
        tmp = func_020720f0(data_020ea928[i] * 100, total);
        stack[i] = tmp + prev;
        if (rnd < (u32)stack[i]) break;
        i++;
    }
    if (best < 0x7FFFFFFF) best++;
    gpiPlayerSetInt((void *)func_02061784(*(s32 *)((u8 *)GetConnection() + 0xE4), i), sDwcKeyEval, best);
    return func_020617a4(*(s32 *)((u8 *)GetConnection() + 0xE4), 0, sDwcKeyEval, 0);
}

void func_02043a24(s32 a, void *b) {
    void *GetConnection(void);
    void Qr2AppendInt(void *, s32);
    void Qr2AppendString(void *, void *);
    extern u8 gSessionPlayers[];
    extern u8 data_0213d3bd[];
    extern void *data_0213d3c4[];
    void *p;
    s32 t;
    s32 i;
    s32 idx;

    switch(a) {
case 8: p=GetConnection(); Qr2AppendInt(b,((u8 *)p)[0x14]); return;
case 10: p=GetConnection(); Qr2AppendInt(b,((u8 *)p)[0x16]); return;
case 50: p=GetConnection(); Qr2AppendInt(b,*(s32 *)((char *)p+0x200)); return;
case 51: p=GetConnection(); Qr2AppendInt(b,((u8 *)p)[0x15]); return;
case 52: p=GetConnection(); Qr2AppendInt(b,*(s32 *)((char *)p+0x20)); return;
case 53:  Qr2AppendInt(b,3); return;
case 54:  Qr2AppendInt(b,1); return;
    }
    i = a - 100;
    if (i < 0) return;
    if (i >= 154) return;
    idx = i * 12;
    if (gSessionPlayers[idx] == 0) return;
    if (data_0213d3bd[idx] != 0) {
        Qr2AppendString(b, *(void **)((char *)data_0213d3c4 + idx));
    } else {
        Qr2AppendInt(b, **(s32 **)((char *)data_0213d3c4 + idx));
    }
}

void func_02043b6c(void) {

}

void func_02043b70(void) {

}

void func_02043b74(s32 a,s32 b) {
extern u8 gSessionPlayers[];
s32 i;u8 *p;
switch(a){case 0:break;case 1:case 2:default:return;}
func_0205eb50(b,8);
func_0205eb50(b,10);
func_0205eb50(b,50);
func_0205eb50(b,51);
func_0205eb50(b,52);
func_0205eb50(b,53);
func_0205eb50(b,54);
p=gSessionPlayers;
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
    void *GetConnection();
    M2C_FIELD(GetConnection(), s32 *, 0x1C) = arg0;
    M2C_FIELD(GetConnection(), s16 *, 0x1A) = arg1;
}

void func_02043c4c(s32 arg0){
void *GetConnection();M2C_UNK SetConnectionState(M2C_UNK);s32 func_02043184();s32 func_0203ecb0();
void *p; s32 zero;
p=GetConnection();
if(M2C_FIELD(p,s32 *,0x1a0)==1)SetConnectionState(6);else{p=GetConnection();if(M2C_FIELD(p,s32 *,0x1a0)!=6){p=GetConnection();if(M2C_FIELD(p,s32 *,0x1a0)!=11)return;}}
p=GetConnection();if(arg0==M2C_FIELD(p,s32 *,0x180)){p=GetConnection();M2C_FIELD(p,u8 *,0x17c)=(u8)(M2C_FIELD(p,u8 *,0x17c)+1);}else{p=GetConnection();M2C_FIELD(p,s8 *,0x17c)=0;p=GetConnection();M2C_FIELD(p,s32 *,0x180)=arg0;}
p=GetConnection();zero=0;
M2C_FIELD(p,s32 *,0x184)=zero;M2C_FIELD(p,s32 *,0x188)=zero;
func_0203ecb0(1,arg0,zero);
if(func_02043184()!=0)return;p=GetConnection();M2C_FIELD(p,u8 *,0x3cc)=255;
}

void func_02043d00(s32 arg0, u32 arg1) {
    s32 func_02038f6c(void);
    void *GetConnection(void);
    void MI_CpuCopy8(void *, void *, s32);
    s32 StringCompareN(void *, void *, s32);
    s32 func_0203f45c(s32, u32, u32, u32, void *, s32);
    extern u8 data_020fca00[];
    u8 record[20];
    u8 buf[128];
    u32 acc = 0;

    if (func_02038f6c() != 5) {
        if (func_02038f6c() != 6) return;
        if (((u8 *)GetConnection())[0x15] != 2) {
            if (((u8 *)GetConnection())[0x15] != 3) return;
        }
    }
    if (arg1 < 0x14) return;

    for (;;) {
        MI_CpuCopy8((void *)arg0, record, 0x14);
        if (StringCompareN(record, data_020fca00, 4) != 0) return;
        if (*(u32 *)(record + 4) != 3) return;
        MI_CpuCopy8((void *)(arg0 + 0x14), buf, record[9]);
        if (func_0203f45c(record[8], *(u32 *)(record + 16), *(u32 *)(record + 12), *(u16 *)(record + 10), buf, record[9] >> 2) == 0) return;
        acc += record[9] + 0x14;
        if (acc + 0x14 > arg1) return;
    }
}

void func_02043e0c(void) {

}

