/* 30 functions from 0x0202F37C to 0x02030348 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct SelectionEntryFlag { u8 low:4; u8 high:4; } SelectionEntryFlag;
typedef struct SelectionFlagBlock { u8 pad[0xc00]; u8 low:6; u8 mode:2; } SelectionFlagBlock;

void func_0202f37c(void) {
 void *func_0202f48c(s32);
 void *p=func_0202f48c(1); void *q;
 if(M2C_FIELD(p,u8 *,8)&16) { q=func_0202f48c(16); M2C_FIELD(p,u8 *,8)&=~16; M2C_FIELD(p,void (**)(s32,void *,s32),4)(16,q,3352); }
 if(M2C_FIELD(p,u8 *,8)&8) { q=func_0202f48c(8); M2C_FIELD(p,u8 *,8)&=~8; M2C_FIELD(p,void (**)(s32,void *,s32),4)(8,q,12); }
 if(M2C_FIELD(p,u8 *,8)&4) { q=func_0202f48c(4); M2C_FIELD(p,u8 *,8)&=~4; M2C_FIELD(p,void (**)(s32,void *,s32),4)(4,q,88); }
 if(M2C_FIELD(p,u8 *,8)&2) { q=func_0202f48c(2); M2C_FIELD(p,u8 *,8)&=~2; M2C_FIELD(p,void (**)(s32,void *,s32),4)(2,q,8960); }
 if(M2C_FIELD(p,u8 *,8)&1) { M2C_FIELD(p,u8 *,8)&=~1; M2C_FIELD(p,void (**)(s32,void *,s32),4)(1,p,24); }
}

void *func_0202f48c(s32 arg0) {
 extern M2C_UNK gWfcManager;
 if (arg0 & 1) return M2C_FIELD(&gWfcManager, void **, 0x10);
 if (arg0 & 2) return M2C_FIELD(&gWfcManager, void **, 4);
 if (arg0 & 4) return M2C_FIELD(&gWfcManager, void **, 8);
 if (arg0 & 8) return M2C_FIELD(&gWfcManager, void **, 0xC);
 if (arg0 & 0x10) return M2C_FIELD(&gWfcManager, void **, 0);
 return 0;
}

void *func_0202f48c(s32);
u32 func_0202f5ac(u32);
void func_0202f4e4(u8 arg0) {
 void *a = func_0202f48c(1);
 void *b = func_0202f48c(0x10);
 M2C_FIELD(a,u8 *,9) = arg0;
 if (arg0 < 0x10) {
  if (arg0 > M2C_FIELD(a,u8 *,0x16)) {
   M2C_FIELD(a,u8 *,0x16) = arg0;
   if (arg0 > 7) {
    M2C_FIELD(a,u8 *,0x15) = func_0202f5ac(M2C_FIELD(b,u8 *,0xD0D));
    M2C_FIELD(a,u8 *,0x14) = M2C_FIELD((u8 *)b + M2C_FIELD(b,u8 *,0xD13)*4,u8 *,0x444);
   }
  }
 }
}

u8 Wfc_GetSessionState(void) {
    extern M2C_UNK gWfcManager;
    return M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), u8 *, 9);
}

void func_0202f558(s32 arg0) {
    void *func_0202f48c(M2C_UNK);
    void *temp_r0;

    temp_r0 = func_0202f48c(1);
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg0;
    M2C_FIELD(temp_r0, s8 *, 0xA) = Wfc_GetSessionState();
}

s32 func_0202f57c(void) {
 extern M2C_UNK gWfcManager;
 return M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), s32 *, 0xC);
}

void func_0202f590(u32 arg0) {
 extern M2C_UNK gWfcManager;
 M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), u8 *, 0x17) = func_0202f5ac(arg0);
}

u32 func_0202f5ac(u32 arg0) {
 if (arg0 > 2) arg0 = (u8)(arg0 - 3);
 return arg0;
}

void func_0202f5bc(void) {
 void func_0202f334(s32, void *, s32);
 extern M2C_UNK gWfcManager;
 func_0202f334(8, M2C_FIELD(&gWfcManager, void **, 0xC), 0xC);
 func_0202f334(0x10, M2C_FIELD(&gWfcManager, void **, 0), 0xD18);
}

s32 func_0202f5f4(void) {
 s32 StringCompareN(void *, void *, s32);
 extern M2C_UNK gWfcManager;
 s32 offset;
 void *base;
 u8 i;
 u8 selected;
 void *p;
 u8 count;
 p = M2C_FIELD(&gWfcManager, void **, 0);
 selected = M2C_FIELD(p,u8 *,0xD13);
 base = p + 0x474;
 offset = (s16)selected * (s16)0xC0;
 if (M2C_FIELD(p,u8 *,0xD0D) >= 6) return 1;
 count = M2C_FIELD(p,u8 *,0xD12);
 for (i=0;i<count;i++) {
  if (i != selected && M2C_FIELD(p + i*4,u8 *,0x445)<6) {
   s32 off = i*0xC0;
   if (StringCompareN(base+offset,base+off,M2C_FIELD(p+off,u16 *,0x47A))==0) return 2;
  }
 }
 return 1;
}

/* Applies an incoming friend message to the WFC friend roster: depending on the
   session state it either marks the friend id straight away (empty code) or
   matches the code against the friend rows (state 3), the friend records (state 4)
   or a single row (state 5), then updates and re-sorts the roster. */
void Wfc_HandleFriendMessage(s32 arg0) {
 void *msg=(void *)arg0;
 void *func_0202f48c(s32); u8 Wfc_GetSessionState(void);
 void Wfc_MarkFriendId(u16); s32 func_0202f894(void *,s32,void *); s32 func_0202f910(void *,void *);
 s32 func_0202f9a0(s32,void *,M2C_UNK,void *); void Wfc_SortFriendRoster(s32,s32);
 s32 result=-1; u8 friendId; void *wfc=func_0202f48c(16);
 M2C_FIELD(func_0202f48c(1),u8 *,11)=1;
 switch(Wfc_GetSessionState()) {
 case 3:
 friendId=M2C_FIELD(wfc,u8 *,WFC_STATE_FRIEND_ID);
 if(M2C_FIELD(msg,u16 *,10)==0 || M2C_FIELD(msg,u8 *,12)==0) {Wfc_MarkFriendId(M2C_FIELD(msg,u16 *,0x36));}
 else if(M2C_FIELD(msg,u16 *,10)==1 || M2C_FIELD(msg,u8 *,12)==WFC_CODE_LEN_FRIEND) {
 Wfc_MarkFriendId(M2C_FIELD(msg,u16 *,0x36));
 result=func_0202f894(msg,M2C_FIELD(wfc,u8 *,WFC_STATE_ENTRY_COUNT),wfc+WFC_STATE_ENTRIES);
 }else result=func_0202f894(msg,M2C_FIELD(wfc,u8 *,WFC_STATE_ENTRY_COUNT),wfc+WFC_STATE_ENTRIES);
 break;
 case 4:
 friendId=M2C_FIELD(wfc+M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*WFC_RECORD_STRIDE,u16 *,0x4A6)-1;
 result=func_0202f910(msg,wfc);
 if(result>=0) M2C_FIELD(wfc+0x447+M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*4,u8 *,0)|=0x80;
 break;
 case 5:
 friendId=M2C_FIELD(wfc,u8 *,WFC_STATE_FRIEND_ID);
 result=func_0202f894(msg,1,wfc+WFC_STATE_ENTRIES+M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*WFC_ENTRY_STRIDE);
 if(result>=0) {
 s32 i=(s16)M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*(s16)WFC_ENTRY_STRIDE; void *q=wfc+WFC_STATE_ENTRIES;
 M2C_FIELD(q+i,u8 *,0)=(M2C_FIELD(q+i,u8 *,0)&~15)|1;
 } break;
 default:return;
 }
 if(result>=0) Wfc_SortFriendRoster(func_0202f9a0(result,msg,friendId,wfc),(s32)wfc);
}

s32 Wfc_MatchFriendCode(void *arg0) {
 s32 func_0203174c(void *);
 s32 func_020317f8(void *);
 void *p = func_0202f48c(0x10);
 u32 a = (u32)(M2C_FIELD(p,u8 *,0xD0C)<<28)>>28;
 if ((a==0 || a==4) && (((s32)M2C_FIELD(arg0,u16 *,0x2C)>>4)&1)==1 && func_020317f8(arg0+0xC)==1) return 6;
 a = (u32)(M2C_FIELD(p,u8 *,0xD0C)<<28)>>28;
 if ((a==0 || a==5) && (((s32)M2C_FIELD(arg0,u16 *,0x2C)>>4)&1)==1 && func_0203174c(arg0+0xC)==1) return 7;
 return -1;
}

s32 func_0202f894(void *arg0, s32 arg1, void *arg2) {
 s32 StringCompareN(void *,void *,s32);
 s32 t; u8 k; s32 i; u32 n; void *p=arg2;
 if(M2C_FIELD(arg0,u16 *,0xA)==0x20) { t=Wfc_MatchFriendCode(arg0); if(t>0)return t; }
 i=0;
 if(arg1>0) {
 n=M2C_FIELD(arg0,u16 *,0xA); k=n;
 do {
 if(k==M2C_FIELD(p,u8 *,3) && StringCompareN(arg0+0xC,p+4,n)==0)return M2C_FIELD(p,u8 *,1);
 i++; p+=0x24;
 }while(i<arg1);
 }
 return -1;
}

s32 func_0202f910(void *arg0,void *arg1) {
 s32 StringCompareN(void *,void *,s32);
 s32 t,i; void *p,*q; s32 len,n;
 if(M2C_FIELD(arg0,u16 *,0xA)==0x20) {t=Wfc_MatchFriendCode(arg0); if(t>0)return t;}
 n=M2C_FIELD(arg1,u8 *,0xD12); i=0;
 if(n>0) {
 len=M2C_FIELD(arg0,u16 *,0xA); p=arg1; q=arg1+0x47C;
 do{
 if(len==M2C_FIELD(p,u16 *,0x47A) && StringCompareN(arg0+0xC,q,len)==0) return M2C_FIELD(arg1+i*4,u8 *,0x445);
 i++; p+=0xC0; q+=0xC0;
 }while(i<n);
 }
 return -1;
}

s32 func_0202f9a0(s32 arg0, void *arg1, M2C_UNK arg2, void *arg3) {
    void func_0202fa68(u8, void *, s32, s32);
    void func_0202fab4(s32, void *, s32, void *);
    s32 var_r3;
    s32 var_r4;
    u8 temp_r0;
    u8 temp_r5;
    void *var_ip;

    temp_r5 = M2C_FIELD(arg3, u8 *, 0xD12);
    var_r4 = -1;
    var_r3 = 0;
    if ((s32) temp_r5 > 0) {
        var_ip = arg3 + 0x474;
loop_2:
        if ((M2C_FIELD(arg1, u8 *, 4) == M2C_FIELD(var_ip, u8 *, 0)) && (M2C_FIELD(arg1, u8 *, 5) == M2C_FIELD(var_ip, u8 *, 1)) && (M2C_FIELD(arg1, u8 *, 6) == M2C_FIELD(var_ip, u8 *, 2)) && (M2C_FIELD(arg1, u8 *, 7) == M2C_FIELD(var_ip, u8 *, 3)) && (M2C_FIELD(arg1, u8 *, 8) == M2C_FIELD(var_ip, u8 *, 4)) && (M2C_FIELD(arg1, u8 *, 9) == M2C_FIELD(var_ip, u8 *, 5))) {
            var_r4 = var_r3;
        } else {
            var_r3 += 1;
            var_ip += 0xC0;
            if (var_r3 < (s32) temp_r5) {
                goto loop_2;
            }
        }
    }
    if (var_r4 == -1) {
        func_0202fa68(arg0, arg1, arg2, (s32)arg3);
        temp_r0 = M2C_FIELD(arg3, u8 *, 0xD12);
        var_r4 = 0xA;
        if ((u32) temp_r0 < 0xAU) {
            M2C_FIELD(arg3, u8 *, 0xD12) = (u8) (temp_r0 + 1);
        }
    } else {
        func_0202fab4(var_r4, arg1, arg2, arg3);
    }
    return var_r4;
}

#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_common_subs off
void func_0202fa68(u8 arg0, void *arg1, s32 arg2, s32 arg3) {
 M2C_UNK func_02007e70(void *,s32,M2C_UNK);
 s32 value; u16 code; void *p;
 p=(void *)(arg3+0x6c);
 M2C_FIELD(p,u8 *,0x401)=arg0;
 code=M2C_FIELD(arg1,u16 *,2);
 value=(s32)code>>2;
 if(!(code&2))value+=25;
 M2C_FIELD(p,u8 *,0x402)=(u8)value;
 M2C_FIELD(p,u8 *,0x403)=(M2C_FIELD(p,u8 *,0x403)&~127)|(arg2&127);
 func_02007e70(arg1,arg3+0xbf0,0xc0);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma optimization_level 2
void func_0202fab4(s32 arg0, void *arg1, s32 arg2, void *arg3) {
 M2C_UNK func_02007e70(void *, s32, M2C_UNK);
 s32 n; void *base; s32 offset; void *p; u16 v;
 v=M2C_FIELD(arg1,u16 *,2);
 base=(u8 *)arg3+0x444;
 offset=arg0*0xC0;
 arg0=(s32)((u8 *)base+arg0*4);
 p=(void *)arg0;
 n=(s32)v>>2;
 n += (v & 2) ? 0 : 25;
 n=(u8)n;
 arg3=(u8 *)arg3+0x470;
 if((u32)(u8)n>M2C_FIELD(p,u8 *,2)) {
 M2C_FIELD(p,u8 *,2)=n;
 M2C_FIELD(p,u8 *,3)=(M2C_FIELD(p,u8 *,3)&~0x7F)|(arg2&0x7F);
 }
 func_02007e70(arg1,(s32)arg3+offset,0xC0);
}
#pragma opt_common_subs off
void Wfc_SortFriendRoster(s32 arg0, s32 arg1) {
    M2C_UNK CpuFill(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02007e70(void *, s32, s32);
    u8 sp4[0xc0];
    M2C_UNK sp0;
    s32 var_r4; M2C_UNK *temp_r5; s32 var_r6,temp_r7,temp_r8; s32 var_r9; s32 var_r10,temp_r5_2;

    var_r4 = arg0;
    temp_r7 = arg1 + 0x444;
    temp_r8 = arg1 + 0x470;
    var_r6 = var_r4 - 1;
    if (var_r6 >= 0) {
        var_r10 = (var_r6 * 0xC0) + temp_r8;
        var_r9 = temp_r7 + var_r6*4;
loop_2:
        if ((u32) M2C_FIELD((temp_r7 + (var_r4 * 4)), u8 *, 2) >= (u32) M2C_FIELD((temp_r7 + (var_r6 * 4)), u8 *, 2)) {
            func_02007e70((void *)var_r9, (s32)&sp0, 4);
            temp_r5 = (M2C_UNK *) (temp_r7 + (var_r4 * 4));
            func_02007e70(temp_r5, (s32)var_r9, 4);
            func_02007e70(&sp0, (s32)temp_r5, 4);
            func_02007e70((M2C_UNK *) var_r10, (s32)sp4, 0xC0);
            temp_r5_2 = var_r4 * 0xC0;
            func_02007e70((void *)(temp_r8 + temp_r5_2), var_r10, 0xC0);
            func_02007e70(&sp4, temp_r8 + temp_r5_2, 0xC0);
            var_r4 = var_r6;
            var_r9=var_r9-4;
            var_r10 -= 0xC0;
            --var_r6;
            if (var_r6 >= 0) {
                goto loop_2;
            }
        }
    }
    CpuFill(0, temp_r7 + 0x28, 4);
    CpuFill(0, temp_r8 + 0x780, 0xC0);
}
#pragma opt_common_subs reset
void func_0202fc10(void *arg0) {
 void Wfc_HandleFriendMessage(s32);
 void *p=func_0202f48c(0x10);
 s16 type=M2C_FIELD(arg0,s16 *,0);
 if(type==5) {
 if(M2C_FIELD(arg0,s16 *,2)==0) return;
 switch(M2C_FIELD(arg0,s32 *,8)) {
 case 13: M2C_FIELD(p,u8 *,0xD14)=1; return;
 case 15: M2C_FIELD(p,u8 *,0xD14)=2; return;
 case 17: M2C_FIELD(p,u8 *,0xD14)=3; return;
 default: M2C_FIELD(p,u8 *,0xD14)=4; return;
 }
 } else if(type==7) Wfc_HandleFriendMessage(M2C_FIELD(arg0,s32 *,4));
}

s32 func_0202fc9c(void) {
    s32 func_0202fce0();
    s32 Wfc_UpdateFriendConnection();
    s32 var_r4;

    var_r4 = Wfc_GetSessionState();
    func_0202f48c(0x10);
    switch (var_r4) {                               /* irregular */
    case 7:
        var_r4 = func_0202fce0();
        break;
    case 8:
        var_r4 = Wfc_UpdateFriendConnection();
        break;
    }
    return var_r4;
}

/* Polls/refreshes the current entry for state 'p': clears the D0D slot, zeroes a temp buffer,
   calls func_020300e8 to (re)validate, then updates the D0B flags and reports 9 or 8. */
s32 func_0202fce0(void *p) {
void MI_CpuFill8(void *,s32,s32); u8 Wfc_ResolveFriendSelection(void *);
void *q=p+0x470+M2C_FIELD(p,u8 *,0xD13)*0xC0;
s32 ok;
M2C_FIELD(p,u8 *,0xD0D)=Wfc_ResolveFriendSelection(p);
MI_CpuFill8(p+0xCB8,0,0x52);
ok=func_020300e8(p,M2C_FIELD(p,u8 *,0xD0D),p+0xCB8);
if(ok) {
M2C_FIELD(p,u8 *,0xD0B)=(M2C_FIELD(p,u8 *,0xD0B)&~12)|4;
if(!(((s32)M2C_FIELD(q,u16 *,0x2C)>>4)&1)) {M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD13)*4,u8 *,0x444)=3;return 9;}
if(M2C_FIELD(p,u8 *,0xD0D)==6 && M2C_FIELD(q,u8 *,0x15)==0) {M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD13)*4,u8 *,0x444)=3;return 9;}
} else {
M2C_FIELD(p,u8 *,0xD0B)=M2C_FIELD(p,u8 *,0xD0B)&~12;
if((((s32)M2C_FIELD(q,u16 *,0x2C)>>4)&1)==1) {M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD13)*4,u8 *,0x444)=3;return 9;}
}
M2C_FIELD(p,u8 *,0xD15)=0;M2C_FIELD(p,u8 *,0xD14)=0;return 8;
}

#pragma dont_inline on
s32 Wfc_GetConnectFlags(void *);
/* One step of the WFC friend-connection phase (state 8): while the link is up it
 * hands the selected friend record and the outgoing command buffer to
 * WFC_StartConnection, retrying up to three times; a reported outcome (event
 * 1/2/3) either clears the pending connection flags or stores the record's
 * result and finishes the step; when the link has dropped (state 9) it stamps
 * the start time and advances. */
s32 Wfc_UpdateFriendConnection(u8 *wfc) {
u32 Wfc_GetLinkState(); s32 Wfc_GetConnectFlags(void *); s32 Wfc_GetConnectModeFlags(void *);
void WFC_StartConnection(void *,void *,s32); unsigned long long GetSystemTick(void);
s32 state=Wfc_GetLinkState(wfc); s32 off; u8 *base; s32 flags; base=wfc+WFC_STATE_RECORDS; off=(s16)wfc[WFC_STATE_RECORD_INDEX]*(s16)WFC_RECORD_STRIDE;
if(state==3) {
{ s32 (*getFlags)(void *)=Wfc_GetConnectFlags; flags=getFlags(wfc); }
wfc[WFC_STATE_CONN_RETRY]++;
if(wfc[WFC_STATE_CONN_RETRY]>3){wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc+wfc[WFC_STATE_RECORD_INDEX]*4,u8 *,WFC_STATE_RECORD_RESULT)=1;return 9;}
if(wfc[WFC_STATE_CONN_RETRY]!=1) {
if(wfc[WFC_STATE_CONN_EVENT]==1)wfc[WFC_STATE_CONN_FLAGS]&=~12;
else if(wfc[WFC_STATE_CONN_EVENT]==2){wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc+wfc[WFC_STATE_RECORD_INDEX]*4,u8 *,WFC_STATE_RECORD_RESULT)=3;return 9;}
else if(wfc[WFC_STATE_CONN_EVENT]==3){wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc+wfc[WFC_STATE_RECORD_INDEX]*4,u8 *,WFC_STATE_RECORD_RESULT)=4;return 9;}
else if(wfc[WFC_STATE_CONN_RETRY]==3)wfc[WFC_STATE_CONN_FLAGS]&=~12;
}
WFC_StartConnection(base+off,wfc+WFC_STATE_CMD_BUFFER,flags|Wfc_GetConnectModeFlags(wfc));
} else if(state==9) {wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc,unsigned long long *,WFC_STATE_TIMER)=GetSystemTick();return 10;}
return 8;
}

/* Resolves which friend-list row the selected friend record corresponds to.  In
 * collect mode (selection mode 0) it returns the id of the first row whose code
 * matches the record and marks the duplicate rows; in commit mode it clears the
 * mark of the single selected row, returns its id and resets the mode. */
u8 Wfc_ResolveFriendSelection(void *arg0) {
    s32 Wfc_MatchFriendCode(void *);
    s32 Wfc_MatchFreespotCode(s32);
    s32 StringCompareN(void *, void *, s32);
    s32 friendId;
    s32 result;
    s32 match;
    s32 record;
    u8 *entryFlags2;
    void *entryBase;
    s32 matchCount2;
    s32 i;
    s32 i2;
    s32 matchCount;
    u16 codeLen;
    u8 entryFlag;
    void *modeBlock;
    void *entry;
    void *entryCode;
    u8 *entryFlags;

    record = (M2C_FIELD(arg0, u8 *, WFC_STATE_RECORD_INDEX) * WFC_RECORD_STRIDE) + (s32) (arg0 + WFC_STATE_RECORDS);
    friendId = 0;
    if (((u32) (M2C_FIELD(arg0, u8 *, WFC_STATE_FLAGS) << 0x18) >> 0x1E) == 0) {
        codeLen = M2C_FIELD(record, u16 *, WFC_RECORD_CODE_LEN);
        matchCount = friendId;
        if (codeLen == WFC_CODE_LEN_FRIEND) {
            result = Wfc_MatchFriendCode((void*)record);
            friendId = result;
            if (result > 0) { matchCount += 1; } else { friendId = 0; }
        } else if (codeLen == WFC_CODE_LEN_FREESPOT) {
            match = Wfc_MatchFreespotCode(record);
            friendId = match;
            if (match != 0) { matchCount += 1; } else { friendId = 0; }
        }
        i = 0;
        if ((s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT) > 0) {
            entry = arg0;
            entryCode = arg0 + WFC_STATE_ENTRIES + WFC_ENTRY_CODE;
            entryFlags = arg0 + WFC_STATE_ENTRIES;
            modeBlock = arg0 + 0x10C;
            do {
                if ((M2C_FIELD(record, u16 *, WFC_RECORD_CODE_LEN) == M2C_FIELD(entry, u8 *, WFC_STATE_ENTRIES + WFC_ENTRY_CODE_LEN)) && (StringCompareN((void*)(record + WFC_RECORD_CODE), entryCode, M2C_FIELD(record,u16*,WFC_RECORD_CODE_LEN)) == 0)) {
                    if (matchCount == 0) {
                        friendId = (s32) M2C_FIELD(entry, u8 *, WFC_STATE_ENTRIES + WFC_ENTRY_ID);
                    } else {
                        *entryFlags = (*entryFlags & ~0xF0) | WFC_ENTRY_MARK;
                        ((SelectionFlagBlock*)modeBlock)->mode=1;
                    }
                    matchCount += 1;
                }
                i += 1;
                entry += WFC_ENTRY_STRIDE;
                entryCode += WFC_ENTRY_STRIDE;
                entryFlags += WFC_ENTRY_STRIDE;
            } while (i < (s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT));
        }
    } else {
        i2 = friendId;
        matchCount2 = i2;
        if ((s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT) > 0) {
            entryBase = arg0;
            entryFlags2 = arg0 + WFC_STATE_ENTRIES;
            do {
                entryFlag = *entryFlags2;
                if (((SelectionEntryFlag*)entryFlags2)->high == 1) {
                    if (matchCount2 == 0) {
                        ((SelectionEntryFlag*)entryFlags2)->high=0;
                        friendId = (s32) M2C_FIELD(entryBase, u8 *, WFC_STATE_ENTRIES + WFC_ENTRY_ID);
                    }
                    matchCount2 += 1;
                }
                i2 += 1;
                entryFlags2 += WFC_ENTRY_STRIDE;
                entryBase += WFC_ENTRY_STRIDE;
            } while (i2 < (s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT));
        }
        if (matchCount2 == 1) {
            M2C_FIELD(arg0, u8 *, WFC_STATE_FLAGS) = (u8) (M2C_FIELD(arg0, u8 *, WFC_STATE_FLAGS) & ~WFC_STATE_SELECT_MODE);
        }
    }
    return (u8) friendId;
}

#pragma dont_inline reset
s32 Wfc_GetConnectFlags(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xD0B) << 0x1E) >> 0x1E) == 1) {
        return 0x30000;
    }
    return 0x20000;
}

s32 Wfc_GetConnectModeFlags(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xD0B) << 0x1C) >> 0x1E) == 1) {
        return 0xC0000;
    }
    return 0x80000;
}

/* Builds an outgoing command/payload at `out` from game state `state` using mode `type` (0..9); returns whether out[0] is nonzero. */
s32 func_020300e8(void *state, u32 type, void *out) {
void MI_CpuCopy8(void *,void *,s32);
void func_0203181c(s32,void *);
void func_02031784(s32,void *);
switch(type) {
case 2:state+=0x100;
case 1:state+=0x100;
case 0:M2C_FIELD(out,u8 *,0)=(u32)(M2C_FIELD(state,u8 *,0xE6)<<30)>>30;MI_CpuCopy8(state+0x80,out+2,0x50);break;
case 5:state+=0x100;
case 4:state+=0x100;
case 3:M2C_FIELD(out,u8 *,0)=1;MI_CpuCopy8(state+0xD1,out+2,0x14);M2C_FIELD(out,u8 *,0x16)=0;break;
case 6:M2C_FIELD(out,u8 *,0)=2;func_0203181c(M2C_FIELD(state,u8 *,0xD13)*0xC0+(s32)(state+0x47C),out+2);break;
case 7:M2C_FIELD(out,u8 *,0)=2;func_02031784(M2C_FIELD(state,u8 *,0xD13)*0xC0+(s32)(state+0x47C),out+2);break;
case 8:case 9:break;
}return M2C_FIELD(out,u8 *,0)!=0;
}

s32 func_020301dc(s32 arg0) {
 s32 func_02030264(void); void func_02035244(void); void func_0203514c(void);
 u8 *p=(u8 *)arg0;
 u32 v=*p;
 if(v<=10) {
 v=func_02030264();
 if(v==1) {*p=0; return 1;}
 if(v==-1) {*p=18;return 1;}
 } else if(v==14) {
 func_02035244();func_0203514c();*p=12;
 } else if(v<18) {
 v=func_020302f4(); if(v==1) *p=10;
 }
 return 0;
}

s32 func_02030264(void) {
 void func_020271cc(void);
 void func_02027428(void);
 void func_020276b0(void);
 void func_02027958(void);
 void WFC_ProcessLinkState(void);
 u32 Wfc_GetLinkState(void);
 switch(Wfc_GetLinkState()) {
 case 0:return 1;
 case 1:func_020271cc();break;
 case 3:func_02027428();break;
 case 6:func_020276b0();break;
 case 9:func_02027958();break;
 case 12:WFC_ProcessLinkState();break;
 case 11:func_0202f558(0);return -1;
 }
 return 0;
}

s32 func_020302f4(void) {
 s32 func_020210b8(void); s32 func_02021c04(void);
 s32 v;
 if(func_020210b8()!=0) return 0;
 v=func_02021c04();
 return v==0 || v==-39;
}

s32 func_02030324(void) {
    s32 func_020301dc(s32);
    if (func_020301dc((s32)(func_0202f48c(1) + 0xA)) == 1) {
        return 0x12;
    }
    return 0x11;
}

