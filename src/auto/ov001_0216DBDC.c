/* 27 functions from 0x0216DBDC to 0x0216EB84 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { volatile s32 count; s32 index; } ScanCounters;

#pragma thumb on

s32 func_ov001_0216dee8(void) {
    s32 func_02027518(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 WFC_ProcessLinkStep();
    M2C_UNK WFC_ConnectStep(void *, void (*)(void));
    void func_ov001_0216dbdc(void);
    extern M2C_UNK gWhState;

    switch (M2C_FIELD(&gWhState, u32 *, 0x2C)) {
    case 5:
        if (func_02027518(0, 0, 0) != 3) return 0;
        break;
    case 7:
        if (WFC_ProcessLinkStep() != 3) return 0;
        break;
    case 1:
        if (WFC_ConnectStep(M2C_FIELD(&gWhState, void **, 0x8), func_ov001_0216dbdc) != 3) return 0;
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    default:
        return 0;
    }
    return 1;
}

s32 func_ov001_0216df50(s32 arg0, s32 arg1) {
    M2C_UNK func_02007e70(s32, s32, M2C_UNK);
    s32 func_02029274();
    M2C_UNK func_020292cc(M2C_UNK);
    s32 func_02029348(u16);
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;

    var_r5 = arg0;
    func_020292cc(1);
    temp_r0 = func_02029274();
    if (temp_r0 > 0) {
        var_r4 = 0;
        if (temp_r0 > 0) {
loop_2:
            if (var_r4 < arg1) {
                func_02007e70(func_02029348((u16) var_r4), var_r5, 0xC0);
                var_r4 += 1;
                var_r5 += 0xC0;
                if (var_r4 < temp_r0) {
                    goto loop_2;
                }
            }
        }
    }
    func_020292cc(0);
    return temp_r0;
}

s32 func_ov001_0216e07c(void) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 WFC_ProcessLinkStep();
    extern M2C_UNK gWhState;
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if ((M2C_FIELD(&gWhState, s32 *, 0x2C) == 7) && (WFC_ProcessLinkStep() == 3)) {
        M2C_FIELD(&gWhState, s32 *, 0x2C) = 4;
        OS_RestoreInterrupts(temp_r4);
        return 1;
    }
    OS_RestoreInterrupts(temp_r4);
    return 0;
}

s32 func_ov001_0216e0b4(void) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 func_02027428();
    s32 func_ov001_0216dee8();
    extern M2C_UNK gWhState;
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if (M2C_FIELD(&gWhState, s32 *, 0x2C) == 3) {
        if (func_02027428() != 3) {
            OS_RestoreInterrupts(temp_r4);
            return 0;
        }
        M2C_FIELD(&gWhState, s32 *, 0x2C) = 2;
        OS_RestoreInterrupts(temp_r4);
        return 1;
    }
    if (func_ov001_0216dee8() == 1) {
        M2C_FIELD(&gWhState, s32 *, 0x2C) = 2;
        OS_RestoreInterrupts(temp_r4);
        return 1;
    }
    OS_RestoreInterrupts(temp_r4);
    return 0;
}

s32 WhStartConnection(s32 a,s32 b,s32 c) {
extern M2C_UNK gWhState;
s32 t=OS_DisableInterrupts();
M2C_FIELD(&gWhState,s32 *,0x58)=c;
if(b)MI_CpuCopy8(b,M2C_FIELD(&gWhState,s32 *,0x28),0x60);
else MI_CpuFill8(M2C_FIELD(&gWhState,s32 *,0x28),0,0x60);
func_02007e70(a,M2C_FIELD(&gWhState,s32 *,0x4c),0xc0);
if(func_ov001_0216dee8()==1){M2C_FIELD(&gWhState,s32 *,0x2c)=8;OS_RestoreInterrupts(t);return 1;}
if(M2C_FIELD(&gWhState,s32 *,0x2c)==3 && WFC_StartConnection(M2C_FIELD(&gWhState,s32 *,0x4c),M2C_FIELD(&gWhState,s32 *,0x28),M2C_FIELD(&gWhState,s32 *,0x58))==3){M2C_FIELD(&gWhState,s32 *,0x2c)=8;OS_RestoreInterrupts(t);return 1;}
OS_RestoreInterrupts(t);return 0;
}

/* Start the Nintendo WFC session on the caller's work block: carve the block
 * into the 0x60-byte peer-address area, the connection parameters, the
 * 0x2300-byte WFC session area and the 0xC0-byte aux area, initialise the
 * session once, then run the connection step.  Returns 1 once the connect step
 * has started, 0 while it has to be retried. */
s32 WhStartSession(s32 eventCallback, s32 workBlock, s32 extraLength) {
    extern M2C_UNK gWhState;
    extern s32 gWhEventCallback;
    void func_ov001_0216dbdc(void);
    s32 savedInterrupts, connectParams, session, aux;

    savedInterrupts = OS_DisableInterrupts();
    connectParams = (workBlock + 0x63) & ~3;
    M2C_FIELD(&gWhState, s32 *, 0x28) = workBlock;
    M2C_FIELD(&gWhState, s32 *, 8) = connectParams;
    session = (connectParams + 0x2f) & ~31;
    M2C_FIELD(&gWhState, s32 *, 0x3c) = session;
    aux = (session + 0x231f) & ~31;
    M2C_FIELD(&gWhState, s32 *, 0x4c) = aux;
    M2C_FIELD(connectParams, s32 *, 4) = (aux + 0xdf) & ~31;
    M2C_FIELD(M2C_FIELD(&gWhState, s32 *, 8), s32 *, 8) = workBlock + extraLength - M2C_FIELD(M2C_FIELD(&gWhState, s32 *, 8), s32 *, 4);
    M2C_FIELD(M2C_FIELD(&gWhState, s32 *, 8), s32 *, 12) = 0;
    M2C_FIELD(M2C_FIELD(&gWhState, s32 *, 8), s32 *, 0) = 3;
    gWhEventCallback = eventCallback;
    if (M2C_FIELD(&gWhState, s32 *, 0x2c) == 0) {
        if (WFC_InitSession(M2C_FIELD(&gWhState, s32 *, 0x3c), 0x2300)) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        M2C_FIELD(&gWhState, s32 *, 0x2c) = 1;
    }
    if (M2C_FIELD(&gWhState, s32 *, 0x2c) == 1) {
        if (WFC_ConnectStep(M2C_FIELD(&gWhState, void **, 8), func_ov001_0216dbdc) != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        M2C_FIELD(&gWhState, s32 *, 0x2c) = 4;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

void func_ov001_0216e288(s32 a,s32 b,s32 c) {
extern M2C_UNK data_ov001_02192824,gWhState;
if(b && c>0){
LockMutex(&data_ov001_02192824);
M2C_FIELD(&gWhState,void (**)(s32),12)(b);
UnlockMutex(&data_ov001_02192824);
}
}

void func_ov001_0216e2b0(void) {
extern M2C_UNK gWhState; extern s32 data_ov001_02192814;
s32 t; s32 *p; s32 i;
t=OS_DisableInterrupts();i=0;
M2C_FIELD(&gWhState,s32 *,0x68)=0;
M2C_FIELD(&gWhState,s32 *,0x6c)=0;
p=&data_ov001_02192814;
do {i++;*p++=0;}while(i<4);OS_RestoreInterrupts(t);
}

void WhPushEvent(s32 a,s32 unused) {
extern M2C_UNK gWhState; extern s32 data_ov001_02192814;
s32 old,next,tail;
old=M2C_FIELD(&gWhState,s32 *,0x68); tail=M2C_FIELD(&gWhState,s32 *,0x6c); next=old+1;
if(next!=tail && old!=tail+3) {
(&data_ov001_02192814)[old]=a;
M2C_FIELD(&gWhState,s32 *,0x68)=next;
if(next>=4) M2C_FIELD(&gWhState,s32 *,0x68)=(a=0);
}
}

void WhEventTimerCallback(M2C_UNK arg0) {
    void WhPushEvent(M2C_UNK, M2C_UNK);
    WhPushEvent(arg0, 0);
}

#pragma opt_propagation off
s32 func_ov001_0216e34c(s32 a) {
extern M2C_UNK gWhState;
s32 WhPopEvent(void);
s32 active=1; s32 result; s32 x,y,r; s32 v=31;
M2C_FIELD(&gWhState,s32 *,0x70)=a;func_ov001_0216e2b0();
x=a*0xd0;
r=M2C_FIELD(&gWhState,s32 (**)(s32),4)(x+0x24d0+a*0xc0);
M2C_FIELD(&gWhState,s32 *,0x54)=r;
if(!r)return -1;
y=(r+v)&(v-0x3f);M2C_FIELD(&gWhState,s32 *,0x40)=y;
M2C_FIELD(&gWhState,s32 *,0x5c)=(y+x+0x2490+v)&(v-0x3f);
if(!WhStartSession((s32)WhPushEvent,y,0))return -2;
do {SleepMilliseconds(10);r=WhPopEvent();
while(r) { if(r==4 || r==5) {} else if(r==6) {active=0;result=1;} else {active=0;result=-2;} r=WhPopEvent(); }
}while(active);return result;
}
#pragma opt_propagation on
s32 func_ov001_0216e3f0(void) {
extern M2C_UNK gWhState;
s32 r,again=1;
if(func_ov001_0216e0b4()){
do{SleepMilliseconds(10);r=WhPopEvent();
while(r){switch(r){case 4:case 5:break;case 20:again=0;break;default:again=0;break;}r=WhPopEvent();}
}while(again);
}
if(M2C_FIELD(&gWhState,s32 *,0x54)){
M2C_FIELD(&gWhState,void (**)(s32),12)(M2C_FIELD(&gWhState,s32 *,0x54));
M2C_FIELD(&gWhState,s32 *,0x54)=0;
}
return 1;
}

#pragma thumb on
/* Join the host selected by the last WH scan: connect to it, then pump the WH
 * event queue until the join completes, is aborted or reaches the configured
 * deadline; on success initialise the network config and mark the join ready. */
s32 WhJoinSelectedHost(void) {
    M2C_UNK SleepMilliseconds(s32);
    M2C_UNK InitTimer(void *);
    M2C_UNK ScheduleTimer(void *, s32, s32, void *, s32);
    M2C_UNK func_02007338(void *);
    s32 func_02021a90(void *);
    u32 WhGetTime();
    extern M2C_UNK gWhState, gWhPacketInfo, data_ov001_0218fdfc;
    u8 alarm[44];
    s32 running = 1;
    s32 result = -2;
    s32 candidate;
    s32 event;

    candidate = M2C_FIELD(&gWhState, s32 *, 0x5C)
              + M2C_FIELD(&gWhState, s32 *, 0x18) * 192;
    if (!candidate) return 0;
    if (!WhStartConnection(candidate, 0, 0x30000)) return -2;
    InitTimer(alarm);
    ScheduleTimer(alarm, 0x3fec42, 0, WhEventTimerCallback, 18);
    do {
        if (WhGetTime() >= M2C_FIELD(&gWhPacketInfo, u32 *, 12)) {
            result = -3;
            break;
        }
        if (M2C_FIELD(&gWhState, s32 *, 16)) {
            result = -8;
            break;
        }
        SleepMilliseconds(10);
        while ((event = WhPopEvent()) != 0) {
            switch (event) {
            case 12:
                running = 0;
                result = 1;
                break;
            case 13:
                if (M2C_FIELD(&gWhState, s32 *, 16)) {
                    running = 0;
                    result = -8;
                } else if (!WhStartConnection(candidate, 0, 0x30000)) {
                    return result;
                }
                break;
            case 4:
            case 5:
            case 18:
            case 19:
                break;
            default:
                running = 0;
                break;
            }
        }
    } while (running);
    func_02007338(alarm);
    while (WhPopEvent()) {}
    if (result > 0) {
        M2C_FIELD(&gWhState, s32 *, 32) = 1;
        if (func_02021a90(&data_ov001_0218fdfc) < 0) result = -2;
        else M2C_FIELD(&gWhState, s32 *, 36) = 1;
    }
    return result;
}

#pragma opt_propagation off
#pragma opt_common_subs on
s32 func_ov001_0216e79c(void) {
    M2C_UNK SleepMilliseconds(s32);
    M2C_UNK InitTimer(void *);
    M2C_UNK ScheduleTimer(void *, s32, s32, void *, s32);
    M2C_UNK func_02007338(void *);
    M2C_UNK MemCopy(void *, void *, s32);
    M2C_UNK StringCopy(void *, void *);
    s32 func_ov001_0216df50(s32, s32);
    s32 func_ov001_0216df94(s32, s32, s32, s32);
    s32 WhPopEvent(void);
    s32 func_ov001_0216e5d0(void *, void *, s32 *);
    u32 WhGetTime();
    void *func_ov001_02171144(s32, s32);
    M2C_UNK func_ov001_02171168(void *);
    M2C_UNK func_ov001_021711ac(u8 *, u8 *);
    M2C_UNK func_ov001_021713a8(void);
    extern M2C_UNK gWhState, gWhPacketInfo, data_ov001_02192ca0, data_ov001_02192c40;
    u32 str[8];
    u8 timer[44];
    s32 sel; volatile s32 n; ScanCounters counters; s32 size;
    u8 *buf1; u8 *buf2; u8 *q;
    u8 *p; u8 *r; u8 *units; void *state;
    s32 result; s32 event; s32 again; s32 m;

    buf2 = NULL;
    sel = 0;
    size = 0x30 * M2C_FIELD(&gWhState, s32 *, 0x70);
    size += 0x34;
    result = -1;
    buf1 = func_ov001_02171144(1, size);
    if (buf1 == NULL) goto ret;
    buf2 = func_ov001_02171144(1, size);
    if (buf2 == NULL) goto ret;
    for (n = 0; n < 30 && M2C_FIELD(&gWhState, s32 *, 0x10) == 0; n++) {
        if (WhGetTime() >= (u32) M2C_FIELD(&gWhPacketInfo, s32 *, 0xc)) goto process;
        if (func_ov001_0216df94(0, 0, 0, 0x30bffe) == 0) {
            result = -2;
            goto ret;
        }
        InitTimer(timer);
        ScheduleTimer(timer, 0xffb10, 0, WhEventTimerCallback, 0x13);
        again = 1;
        result = 0;
        do {
            SleepMilliseconds(10);
            if (WhGetTime() >= (u32) M2C_FIELD(&gWhPacketInfo, s32 *, 0xc)) break;
            if (M2C_FIELD(&gWhState, s32 *, 0x10)) break;
            event = WhPopEvent();
            while (event != 0) {
                switch (event) {
                case 19:
                    again = 0;
                    break;
                case 5:
                    m = func_ov001_0216df50(M2C_FIELD(&gWhState, s32 *, 0x5c), M2C_FIELD(&gWhState, s32 *, 0x70));
                    if (m > result) { result = m;
                    func_02007338(timer);
                    ScheduleTimer(timer, 0xffb10, 0, WhEventTimerCallback, 0x13); }
                    break;
                case 10:
                    again = 0;
                    break;
                case 4:
                case 8:
                case 18:
                    break;
                case 0:
                case 1:
                case 2:
                case 3:
                default:
                    again = 0;
                    break;
                }
                event = WhPopEvent();
            }
        } while (again);
        func_02007338(timer);
        while (WhPopEvent() != 0) {}
        state=&gWhState;
        if (M2C_FIELD(state, s32 *, 0x10)) break;
process:
        state=&gWhState;
        counters.count = 0;
        if (result >= M2C_FIELD(state, s32 *, 0x70)) {
            result = counters.count - 6;
            goto ret;
        }
        units = M2C_FIELD(state, u8 **, 0x5c);
        counters.index = counters.count;
        if (result > 0) {
            if(result > 0) {
            q = buf1;
            q += 8;
            p = buf1;
            r = p;
            r += 0x2c;
            do {
                MemCopy(q, units + 0xc, 0x20);
                M2C_FIELD(p, s32 *, 4) = M2C_FIELD(units, u16 *, 0xa);
                p[8+M2C_FIELD(units, u16 *, 0xa)] = 0;
                M2C_FIELD(p, u16 *, 0x32) = (M2C_FIELD(units, u16 *, 0x2c) & 0x10) ? 1 : 0;
                r[0] = M2C_FIELD(units, u8 *, 4);
                r[1] = M2C_FIELD(units, u8 *, 5);
                r[2] = M2C_FIELD(units, u8 *, 6);
                r[3] = M2C_FIELD(units, u8 *, 7);
                r[4] = M2C_FIELD(units, u8 *, 8);
                r[5] = M2C_FIELD(units, u8 *, 9);
                units += 0xc0;
                p += 0x30;
                q += 0x30;
                r += 0x30;
                counters.count++;
                counters.index++;
            } while(counters.index<result);
            }
        }
        M2C_FIELD(buf1, s32 *, 0) = result;
        if (M2C_FIELD(&gWhState, s32 *, 0x38) != 1 && func_ov001_0216e5d0(buf1, buf2, &sel) != 0) {
            p = buf1 + 4 + sel * 0x30;
            M2C_FIELD(&gWhState, s32 *, 0x18) = sel;
            StringCopy(&data_ov001_02192ca0, p + 4);
            q = p + 0x28;
            M2C_FIELD(&data_ov001_02192c40, u8 *, 0) = q[0];
            M2C_FIELD(&data_ov001_02192c40, u8 *, 1) = q[1];
            M2C_FIELD(&data_ov001_02192c40, u8 *, 2) = q[2];
            M2C_FIELD(&data_ov001_02192c40, u8 *, 3) = q[3];
            M2C_FIELD(&data_ov001_02192c40, u8 *, 4) = q[4];
            M2C_FIELD(&data_ov001_02192c40, u8 *, 5) = q[5];
            func_ov001_021711ac((u8 *)str, &data_ov001_02192c40);
            break;
        }
        MemCopy(buf2, buf1, size);
        M2C_FIELD(&gWhState, s32 *, 0x38) = 2;
        func_ov001_021713a8();
    }
    if (n >= 30 || WhGetTime() > (u32) M2C_FIELD(&gWhPacketInfo, s32 *, 0xc)) result = -3;
    else if (M2C_FIELD(&gWhState, s32 *, 0x10)) result = -8;
    else result = 1;
ret:
    if (buf1 != NULL) func_ov001_02171168(buf1);
    if (buf2 != NULL) func_ov001_02171168(buf2);
    return result;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset

#pragma thumb on
s32 func_ov001_0216ea30(s32 a,s32 b,s32 unused,s32 c,s32 d) {
s32 func_020216cc(s32,s32,s32,s32,s32);
s32 r=func_020216cc(a,c,d,0,b);if(r<0)r=-4;return r;
}

#pragma thumb on
void func_ov001_0216ea48(s32 a,s32 b,s32 c) {
s32 func_02021264(void);
void func_02021d14(s32,void *);
s32 func_ov001_0216ea30(s32,s32,s32,s32,s32);
u8 buf[12];
buf[4]=8;buf[5]=2;*(s32 *)(buf+8)=-1;*(u16 *)(buf+6)=0x1e6;
func_02021d14(func_02021264(),buf);
func_ov001_0216ea30(a,(s32)(buf+4),(s32)buf,b,c);
}

#pragma thumb on
void func_ov001_0216ea84(s32 a,s32 unused,s32 b,s32 c) {
void func_ov001_0216ea48(s32,s32,s32);
func_ov001_0216ea48(a,b,c);
}

void *func_ov001_0216ea90(u8 *p,s32 *a,s32 *b) {
u16 v=*(u16 *)p;
u32 sum=0;u16 n,w;u8 *q,*end;
*a=(u16)((u8)((s32)v>>8)|(0xff00&(v<<8)));
v=*(u16 *)(p+2);
n=(u16)((u8)((s32)v>>8)|(0xff00&(v<<8)));
*b=n;
end=p+6+n;q=p;
while(q<end){sum+=*q++;}
w=*(u16 *)end;
if((u16)sum!=(u16)((u8)((s32)w>>8)|(0xff00&(w<<8))))return 0;
return p+6;
}

#pragma thumb on
s32 func_ov001_0216eb00(s32 *pp,s32 end,s32 a,s32 b) {
u8 *p=(u8 *)*pp;
u16 v,n;
if((u32)p>=(u32)end)return 0;
v=*(u16 *)p;
*(s32 *)a=(u16)((u8)((s32)v>>8)|(0xff00&(v<<8)));
v=*(u16 *)(p+2);p+=4;
n=(u16)((u8)((s32)v>>8)|(0xff00&(v<<8)));
*(s32 *)b=n;
*pp=(s32)(p+(((n+11)&~7)-4));
return (s32)p;
}

#pragma thumb on
void func_ov001_0216eb50(u16 *arg0,s32 arg1,s32 arg2) {
s32 func_ov001_0216eb00(s32 *,s32,s32,s32);
s32 temp_r5; s32 sp0;u16 temp_r2;
temp_r5=(s32)arg0+8;sp0=temp_r5;temp_r2=*arg0;
func_ov001_0216eb00(&sp0,temp_r5+(u16)((u8)((s32)temp_r2>>8)|(0xff00&(temp_r2<<8))),arg1,arg2);
}
