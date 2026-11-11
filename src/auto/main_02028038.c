/* 17 functions from 0x02028038 to 0x02028EF4 (main), found by ds-decomp. */
#include "common.h"
typedef struct CallbackArgs_0202810c { s16 a,b; s32 c,d,e; } CallbackArgs_0202810c;
typedef struct State_02028038 { u8 pad[0x260]; s32 state; u32 bits; u8 pad268[0x14]; void (*callback)(CallbackArgs_0202810c *); } State_02028038;

#pragma opt_common_subs off
u16 func_02028038(s32 a){
extern void *gSession;
s32 i,b,bits,rem;void *p=gSession;
i=0;b=a;bits=M2C_FIELD(p,u32*,0x2264);do{rem=b%13;if(bits&(1<<(rem+1)))break;i++;b++;}while(i<13);
rem=(a+i)%13;return rem+1;
}
#pragma opt_common_subs on
void WFC_DispatchEvent(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    void WFC_CallEventHandler(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern void *gSession;
    s16 temp_r0;

    temp_r0 = M2C_FIELD(gSession, s16 *, 0x2280);
    M2C_FIELD(gSession, s16 *, 0x2280) = 0;
    WFC_CallEventHandler(temp_r0, arg0, arg1, arg2, arg3);
}

void WFC_CallEventHandler(s16 a,s32 b,s32 c,s32 d,s32 e){
extern void *gSession;
CallbackArgs_0202810c args;
State_02028038 *p=(State_02028038 *)((u8 *)gSession+0x2000);
if(!p->callback)return;
args.a=a;args.c=c;args.d=d;args.e=e;args.b=b;
M2C_FIELD(p,void (**)(CallbackArgs_0202810c *),0x27c)(&args);
}

#pragma opt_common_subs off
void WFC_SetState(s32 a){void func_0202826c(void);s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);extern void *gSession;s32 old=OS_DisableInterrupts();if(M2C_FIELD(gSession,s32 *,0x2260)==9&&a!=9)func_02007338((u8 *)gSession+0x22cc);if(M2C_FIELD(gSession,s32 *,0x2260)!=11)M2C_FIELD(gSession,s32 *,0x2260)=a;if(a==9)func_020072cc((u8 *)gSession+0x22cc,0x22f5341,0,func_0202826c,0);OS_RestoreInterrupts(old);}
#pragma opt_common_subs on
M2C_UNK func_020281f8(void){void func_0202826c(void);extern void *gSession;s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void func_02007338(void *);void func_020072cc(void *,s32,s32,void (*)(void),s32);s32 old=OS_DisableInterrupts();func_02007338((u8 *)gSession+0x22cc);if(M2C_FIELD(gSession,s32 *,0x2260)==9)func_020072cc((u8 *)gSession+0x22cc,0x22f5341,0,func_0202826c,0);OS_RestoreInterrupts(old);}

void func_0202826c(void) {
    M2C_UNK func_020281f8();
    M2C_UNK func_02029714();
    func_02029714();
    func_020281f8();
}

u32 func_0202827c(u32 a){s32 __cntlzw(u32);u32 n=0;s32 bit;for(;;){bit=31-__cntlzw(a);if(bit<0)return n;a&=~(1U<<bit);n++;}}

s32 func_020282a8(u32 arg0) {
    return __builtin_clz(arg0);
}

#pragma optimization_level 2
void WFC_Finish(void){
 extern void *gSession;
 void func_02028ef4(void);
 s32 func_02012274(void (*)(void));
 u8 *p=(u8 *)gSession;
 p += 0x2000;
 if(p[0x26b])return;
 p[0x26b]=1;
 if(func_02012274(func_02028ef4)==2)return;
 WFC_SetState(11);
 WFC_DispatchEvent(7,0,0,0x610);
}
#pragma optimization_level reset
void func_0202830c(u16 *p){extern void *gSession;if(p[1]!=8||p[2]!=22||p[3]!=37)return;switch(M2C_FIELD(gSession,s32 *,0x2260)){case 8:WFC_SetState(12);return;case 9:case 12:WFC_Finish();return;case 10:WFC_SetState(12);return;}}

#pragma opt_propagation off
/* Completion callback for the WFC connection operations: dispatches on the
 * result kind and the operation id, runs the matching continuation, then
 * advances the session state machine and reports the outcome. */
void WFC_OperationCallback(u16 *msg) {
s32 func_02011244(void);s32 func_02012158(void *);s32 func_02012198(void *);s32 func_02013cfc(void *,s32);s32 func_02013bc8(void *,s32,s32,void *);s32 func_02012740(void *,void *,s32,s32,u16);void func_0202899c(const u16 *);extern void *gSession;
s32 result=20;
switch(msg[1]){
case 0:
switch(msg[0]){
case 3:result=func_02012198(WFC_OperationCallback);break;
case 4: {s32 n=func_02011244();switch(n){case 0: {WFC_SetState(1);WFC_DispatchEvent(0,0,0,0x663);return;}case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x66c);return;}}
case 5:WFC_SetState(3);WFC_DispatchEvent(0,0,0,0x673);return;
case 6:result=func_02012158(WFC_OperationCallback);break;
case 29:result=func_02013cfc(WFC_OperationCallback,0);break;
case 25:{u8 *session=gSession;result=func_02013bc8(WFC_OperationCallback,session[0x2250],session[0x2251],session+0x2200);break;}
case 39:{u8 *session=gSession;u32 statusBits=M2C_FIELD(session,u32 *,0x2264);u16 bothSet=(statusBits&0xc0000)==0xc0000;result=func_02012740(func_0202899c,session+0x2140,0,(statusBits&0x30000)!=0x30000,bothSet);break;}
}
switch(result){case 2:return;case 3:break;case 8:WFC_SetState(12);{u8 *session=gSession;WFC_DispatchEvent(1,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6af);}return;}
WFC_SetState(11);{u8 *session=gSession;WFC_DispatchEvent(7,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6b8);}return;
case 1:WFC_SetState(12);{u8 *session=gSession;WFC_DispatchEvent(1,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6de);}return;
case 2:case 3:case 4:default:WFC_SetState(11);{u8 *session=gSession;WFC_DispatchEvent(7,M2C_FIELD(session,s16 *,0x2280)==5?session+0x2140:0,0,0x6e8);}return;
}}
#pragma opt_propagation on
/* Handle a message from the WFC socket: advance the connection state machine and report the result. */
void WFC_ProcessCallback(u16 *msg){
extern void *gSession;
void DC_InvalidateRange(s32,s32); void func_020293a0(s32,u16); u64 func_020722fc(s32,s32); s32 func_020125b0(void *,void *);s32 func_02012700(void *);void WFC_ProcessSendCallback(u16 *);
s32 result=20,i,n;u32 bits;
switch(msg[1]){
case 0:
if(M2C_FIELD(gSession,s32 *,0x2260)==5){WFC_SetState(6);WFC_DispatchEvent(0,0,0,0x704);}
switch(M2C_FIELD(gSession,s32 *,0x2260)){
case 6:
M2C_FIELD(gSession,u16 *,0x2280)=7;
if(msg[4]==5){DC_InvalidateRange(M2C_FIELD(gSession,s32 *,0x2288),M2C_FIELD(gSession,u16 *,0x228c));
for(i=0;i<msg[7];i++){func_020293a0(((s32 *)msg)[i+4],msg[i+40]);WFC_CallEventHandler(7,0,((s32 *)msg)[i+4],(s32)msg,0x71a);}}
bits=M2C_FIELD(gSession,u32 *,0x2264);
if((bits&0xc00000)==0xc00000){n=func_0202827c(bits&0x3ffe);if(n){s32 v=M2C_FIELD(gSession,s32 *,0x2284);if((u32)(func_020722fc(v,n)>>32)==0)WFC_CallEventHandler(8,0,v,0,0x728);}}
M2C_FIELD(gSession,u16 *,0x228e)=(1<<func_02028038((u16)(32-func_020282a8(msg[5]))))>>1;
DC_InvalidateRange(M2C_FIELD(gSession,s32 *,0x2288),M2C_FIELD(gSession,u16 *,0x228c));
M2C_FIELD(gSession,s32 *,0x2284)++;
result=func_020125b0(WFC_ProcessCallback,(u8 *)gSession+0x2288);break;
case 7:result=func_02012700(WFC_ProcessSendCallback);break;
case 13:WFC_Finish();return;
}
if(result==2)return;
if(result!=3&&result==8){WFC_SetState(12);WFC_DispatchEvent(1,0,0,0x753);return;}
WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x75c);return;
case 1:WFC_Finish();return;
case 2:case 3:case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x76d);return;
}}

void WFC_ProcessSendCallback(u16 *p){switch(p[1]){case 0:WFC_SetState(3);WFC_DispatchEvent(0,0,0,0x783);return;case 1:WFC_Finish();return;case 2:case 3:case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,0,0,0x793);return;}}

#pragma opt_strength_reduction off
void func_0202899c(const u16 *p){
extern void *gSession;
void func_02028cc8(u16 *);s32 func_02012dd4(void (*)(u16 *),void *,s32);
s32 result;
switch(p[1]){
case 0:
switch(p[4]){
case 6:goto done;
case 26:goto done;
case 8:case 9: {
void **g=&gSession;
void *base=*g;
switch(M2C_FIELD(base,s32 *,0x2260)){
case 10:M2C_FIELD(base,u16 *,0x2282)=0;
case 8:WFC_SetState(12);return;
case 9:M2C_FIELD(base,u16 *,0x2282)=0;

case 12:M2C_FIELD(*g,u16 *,0x2280)=6;WFC_Finish();return;
default:goto done;}
}
case 7:
if(M2C_FIELD(gSession,s32 *,0x2260)==12){WFC_SetState(8);WFC_Finish();return;}
if(p[5]>=1&&p[5]<=0x7d7){
M2C_FIELD(gSession,u16 *,0x2282)=p[5];
result=func_02012dd4(func_02028cc8,(u8 *)gSession+0x1500,0x620);
switch(result){case 2:return;case 3:break;case 8:WFC_SetState(12);WFC_DispatchEvent(1,(s32)((u8 *)gSession+0x2140),0,0x7ed);return;
}
WFC_SetState(11);WFC_DispatchEvent(7,(s32)((u8 *)gSession+0x2140),0,0x7f6);return;
}
WFC_Finish();return;
default:WFC_SetState(11);WFC_DispatchEvent(7,(s32)((u8 *)gSession+0x2140),p[4],0x804);return;
}
case 1:M2C_FIELD(gSession,u16 *,0x22f8)=p[7];WFC_SetState(8);
case 6:case 11:case 12:WFC_Finish();return;
case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:
default:WFC_SetState(11);WFC_DispatchEvent(7,(s32)((u8 *)gSession+0x2140),0,0x81b);return;
}
done:return;
}
#pragma opt_strength_reduction reset
void func_02028c00(u16 *p) {
    extern void *gSession;
    switch (p[1]) {
    case 0:
        if (M2C_FIELD(gSession, s32 *, 0x2260) == 0xc) {
            WFC_SetState(0xa);
            WFC_Finish();
            return;
        }
        M2C_FIELD(gSession, u16 *, 0x2282) = 0;
        WFC_SetState(3);
        WFC_DispatchEvent(0, (u8 *)gSession + 0x2140, 0, 0x83d);
        return;
    case 1:
    case 3:
        WFC_SetState(0xa);
        WFC_Finish();
        return;
    case 2:
    case 4:
    default:
        WFC_SetState(0xb);
        WFC_DispatchEvent(7, (u8 *)gSession + 0x2140, 0, 0x84f);
        return;
    }
}

void func_02028cc8(u16 *p) {
    extern void *gSession;
    void WFC_SetState(s32);
    void WFC_DispatchEvent(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void WFC_Finish(void);
    void func_02029bd0(M2C_UNK);
    void DC_InvalidateRange(M2C_UNK, M2C_UNK);
    void func_020296e0(M2C_UNK);

    switch (p[1]) {
    case 0:
        switch (p[2]) {
        case 0xe:
            if (M2C_FIELD(gSession, s32 *, 0x2260) == 0xc) {
                WFC_SetState(0x8);
                WFC_Finish();
                return;
            }
            WFC_SetState(0x9);
            WFC_DispatchEvent(0, (u8 *)gSession + 0x2140, 0, 0x872);
            return;
        case 0xf:
            func_02029bd0((*(u16 *)((u8 *)*(void **)((u8 *)p + 8) + 0xe) >> 8) & 0xff);
            DC_InvalidateRange(*(void **)((u8 *)p + 8), 0x620);
            func_020296e0(*(void **)((u8 *)p + 8));
            return;
        default:
            WFC_SetState(0xb);
            WFC_DispatchEvent(7, (u8 *)gSession + 0x2140, p[2], 0x881);
            return;
        }
    case 4:
    default:
        WFC_SetState(0xb);
        WFC_DispatchEvent(7, (u8 *)gSession + 0x2140, p[2], 0x88c);
        return;
    }
}

void func_02028c00(u16 *);
void func_02028dd8(u16 *p) {
extern void *gSession;
switch(p[1]){
case 0:
if(M2C_FIELD(gSession,s32 *,0x2260)==12){WFC_SetState(10);WFC_Finish();return;}
switch(func_0201280c(func_02028c00,0)){
case 2:return;
case 8:WFC_SetState(12);WFC_DispatchEvent(1,(u8 *)gSession+0x2140,0,0x8b4);return;
case 3:WFC_SetState(10);WFC_Finish();return;
default:WFC_SetState(11);WFC_DispatchEvent(7,(u8 *)gSession+0x2140,0,0x8c0);return;
}
case 1:case 3:WFC_SetState(10);WFC_Finish();return;
case 2:case 4:default:WFC_SetState(11);WFC_DispatchEvent(7,(u8 *)gSession+0x2140,0,0x8d3);return;
}
}

