/* 34 functions from 0x0200ED40 to 0x0200FC58 (main), found by ds-decomp. */
#include "common.h"

extern volatile s32 data_0212fd38;

typedef union RTCStatus {
    u16 value;
    struct {
        u16 mode : 4;
        u16 reserved : 2;
        u16 enabled : 1;
        u16 unused : 9;
    } bits;
} RTCStatus;

void func_0200ed40(void **arg0, void *arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg1, void **, 8) = (void *) *arg0;
        *arg0 = arg1;
    }
}

#pragma scheduling off
/* Append callback node `node` at the tail of the singly linked list `list`
 * (a node's next pointer sits at +0x08), or make it the head when the list is
 * empty. */
void CallbackList_Append(M2C_UNK *list, M2C_UNK node) {
    M2C_UNK *tail, *next;
    if (list == NULL) {
        return;
    }
    tail = (M2C_UNK *)*list;
    if (tail == NULL) {
        M2C_FIELD(node, M2C_UNK *, 8) = 0;
        *list = node;
        return;
    }
    next = M2C_FIELD(tail, M2C_UNK *, 8);
    if (next != NULL) {
        do {
            tail = next;
            next = M2C_FIELD(next, M2C_UNK *, 8);
        } while (next != NULL);
    }
    M2C_FIELD(node, M2C_UNK *, 8) = (M2C_UNK)next;
    M2C_FIELD(tail, M2C_UNK *, 8) = node;
}
/* Remove callback node `node` from the singly linked list `list` when it is in
 * it (a node's next pointer sits at +0x08). */
void CallbackList_Remove(M2C_UNK *list, M2C_UNK node) {
    M2C_UNK current;
    M2C_UNK previous;

    if (list != NULL) {
        current = *list;
        previous = current;
        if (current != 0) {
            do {
                if (current == node) {
                    if (current == previous) *list = M2C_FIELD(current, M2C_UNK *, 8);
                    else M2C_FIELD(previous, M2C_UNK *, 8) = M2C_FIELD(current, M2C_UNK *, 8);
                    return;
                }
                previous = current;
                current = M2C_FIELD(current, M2C_UNK *, 8);
            } while (current != 0);
        }
    }
}

void func_0200ede8(void *arg0) {
    void *var_r4;

    var_r4 = arg0;
    if (var_r4 == NULL) {
        return;
    }
    do {
        M2C_FIELD(var_r4, M2C_UNK (**)(s32), 0)(M2C_FIELD(var_r4, s32 *, 4));
        var_r4 = M2C_FIELD(var_r4, void **, 8);
    } while (var_r4 != NULL);
}

void PM_AddPreSleepCallback(void *arg0) { extern M2C_UNK data_0212fcd8; void (*f)(void **,void *)=func_0200ed40; f((void **)&data_0212fcd8,arg0); }

void PM_AddPostSleepCallback(M2C_UNK arg0) {
    void CallbackList_Append(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212fce0;
    CallbackList_Append(&data_0212fce0, arg0);
}
#pragma scheduling reset
/* Unlinks a node from the global list rooted at data_0212fcd8. */
void PM_DeletePreSleepCallback(M2C_UNK node) {
    extern M2C_UNK data_0212fcd8;
    void (*unlinkNode)(M2C_UNK *, M2C_UNK) = CallbackList_Remove;
    unlinkNode(&data_0212fcd8, node);
}
#pragma peephole reset
#pragma scheduling reset
void PM_DeletePostSleepCallback(M2C_UNK arg0) {
    void CallbackList_Remove(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212fce0;
    CallbackList_Remove(&data_0212fce0, arg0);
}
/* Bring the RTC service up once: mark the state initialised, clear the pending
 * request, then install the reply handler on the RTC command FIFO. */
void RTC_Init(void) {
    M2C_UNK PXI_Init();
    M2C_UNK SetFifoMessageHandler(M2C_UNK, M2C_UNK *);
    s32 IsFifoMessageReady(M2C_UNK, M2C_UNK);
    extern M2C_UNK gRtcState;
    extern M2C_UNK func_0200f0e4;
    if (M2C_FIELD(&gRtcState, u16 *, RTC_STATE_READY) != 0) {
        return;
    }
    M2C_FIELD(&gRtcState, u16 *, RTC_STATE_READY) = 1;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_HANDLER) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_OUT0) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_OUT1) = 0;
    PXI_Init();
    do {
    } while (IsFifoMessageReady(RTC_FIFO_TAG, 1) == 0);
    SetFifoMessageHandler(RTC_FIFO_TAG, &func_0200f0e4);
}

/* Start an RTC read of the current date (request kind 0): refuses while another
 * request is in flight, marks the state busy, then stores the date result record,
 * the completion callback and its argument and queues the RTC's read-date command.
 * Returns 1 when busy, 0 once queued and 3 when it cannot be sent. */
s32 StartRtcDateRead(s32 dateOut, s32 callback, s32 callbackArg) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gRtcState;
    s32 interruptState;

    interruptState = OS_DisableInterrupts();
    if (M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) != 0) {
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) = 1;
    OS_RestoreInterrupts(interruptState);
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_KIND) = RTC_KIND_DATE;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_STEP) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_OUT0) = dateOut;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK) = callback;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK_ARG) = callbackArg;
    if (SendRtcReadDateCommand() != 0) return 0;
    return 3;
}

s32 GetRtcDate(s32 arg0) {
    s32 StartRtcDateRead(s32, s32, s32);
    void func_0200f6a4(s32);
    s32 func_0200f6b4(void);
    extern M2C_UNK gRtcState;
    s32 result;
    result = StartRtcDateRead(arg0, (s32)func_0200f6a4, 0);
    M2C_FIELD(&gRtcState, s32 *, 0x24) = result;
    if (result == 0) func_0200f6b4();
    return M2C_FIELD(&gRtcState, s32 *, 0x24);
}

/* Starts an RTC read of the current time (request kind 1): refuses while another
 * request is in flight, marks the state busy, then stores the time result record,
 * the completion callback and its argument and queues the RTC's read-time
 * command. Returns 1 when busy, 0 once queued and 3 when it cannot be sent. */
s32 StartRtcTimeRead(s32 timeOut, s32 callback, s32 callbackArg) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gRtcState;
    s32 interruptState;

    interruptState = OS_DisableInterrupts();
    if (M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) != 0) {
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) = 1;
    OS_RestoreInterrupts(interruptState);
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_KIND) = RTC_KIND_TIME;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_STEP) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_OUT0) = timeOut;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK) = callback;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK_ARG) = callbackArg;
    if (SendRtcReadTimeCommand() != 0) return 0;
    return 3;
}
#pragma opt_common_subs reset
s32 GetRtcTime(s32 arg0) {
    s32 StartRtcTimeRead(s32, s32, s32);
    void func_0200f6a4(s32);
    s32 func_0200f6b4(void);
    extern M2C_UNK gRtcState;
    s32 result;
    result = StartRtcTimeRead(arg0, (s32)func_0200f6a4, 0);
    M2C_FIELD(&gRtcState, s32 *, 0x24) = result;
    if (result == 0) func_0200f6b4();
    return M2C_FIELD(&gRtcState, s32 *, 0x24);
}

/* Start an RTC read of the current date and time.  The reply fills dateOut and
 * timeOut and then calls callback(result, callbackArg).  Returns 1 when another
 * request is already in flight, 0 once the command is sent, 3 when sending the
 * command failed. */
s32 GetRtcDateTime(s32 dateOut, s32 timeOut, s32 callback, s32 callbackArg) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gRtcState;
    s32 interruptState;
    interruptState = OS_DisableInterrupts();
    if (M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) != 0) {
        OS_RestoreInterrupts(interruptState);
        return 1;
    }
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_BUSY) = 1;
    OS_RestoreInterrupts(interruptState);
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_KIND) = 2;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_STEP) = 0;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_OUT0) = dateOut;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_OUT1) = timeOut;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK) = callback;
    M2C_FIELD(&gRtcState, s32 *, RTC_STATE_CALLBACK_ARG) = callbackArg;
    if (SendRtcReadDateTimeCommand() != 0) return 0;
    return 3;
}
#pragma opt_common_subs reset
s32 GetLocalTime(s32 arg0, s32 arg1) {
void func_0200f6a4(s32); s32 func_0200f6b4(void); extern M2C_UNK gRtcState;
s32 result = GetRtcDateTime(arg0,arg1,(s32)func_0200f6a4,0);
M2C_FIELD(&gRtcState,s32 *,0x24)=result;
if(result==0) func_0200f6b4();
return M2C_FIELD(&gRtcState,s32 *,0x24);
}

/* Handles RTC command callbacks and state machine updates */
void func_0200f0e4(s32 arg0, u32 arg1, s32 arg2) {
 extern M2C_UNK gRtcState;
 s32 func_0200fa50(void *);
 s32 func_0200f6fc(void);
 u8 command;
 u8 status;
 s32 result;
 s32 *out;
 void (*callback)(s32, s32);
 if (arg2) {
  if (M2C_FIELD(&gRtcState, s32 *, 0x1c)) M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0;
  if (M2C_FIELD(&gRtcState, s32 *, 4)) M2C_FIELD(&gRtcState, s32 *, 4) = 0;
  callback = M2C_FIELD(&gRtcState, void (**)(s32, s32), 8);
  if (callback) { M2C_FIELD(&gRtcState, s32 *, 8) = 0; callback(6, M2C_FIELD(&gRtcState, s32 *, 0x14)); }
  return;
 }
 command = (u8)((arg1 & 0x7f00) >> 8);
 status = (u8)arg1;
 if (command == 0x30) {
  if (M2C_FIELD(&gRtcState, void (**)(void), 0x20)) M2C_FIELD(&gRtcState, void (**)(void), 0x20)();
  return;
 }
 if (status == 0) {
  result = 0;
  switch (M2C_FIELD(&gRtcState, u32 *, 0x18)) {
   case 0:
    out = M2C_FIELD(&gRtcState, s32 **, 0xc);
    out[0] = RtcBcdToInt((*(volatile u32 *)0x27ffde8 << 24) >> 24);
    out[1] = RtcBcdToInt((*(volatile u32 *)0x27ffde8 << 19) >> 27);
    out[2] = RtcBcdToInt((*(volatile u32 *)0x27ffde8 << 10) >> 26);
    out[3] = func_0200fa50(out);
    break;
   case 1:
    out = M2C_FIELD(&gRtcState, s32 **, 0xc);
    out[0] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 26) >> 26);
    out[1] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 17) >> 25);
    out[2] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 9) >> 25);
    break;
   case 2:
    out = M2C_FIELD(&gRtcState, s32 **, 0xc);
    out[0] = RtcBcdToInt(*(volatile u32 *)0x27ffde8 & 255);
    out[1] = RtcBcdToInt((*(volatile u32 *)0x27ffde8 << 19) >> 27);
    out[2] = RtcBcdToInt((*(volatile u32 *)0x27ffde8 << 10) >> 26);
    out[3] = func_0200fa50(out);
    out = M2C_FIELD(&gRtcState, s32 **, 0x10);
    out[0] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 26) >> 26);
    out[1] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 17) >> 25);
    out[2] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 9) >> 25);
    break;
   case 6:
    out = M2C_FIELD(&gRtcState, s32 **, 0xc);
    switch (((RTCStatus *)0x27ffdea)->bits.mode) {
     case 4: out[0] = 1; break;
     default: out[0] = 0; break;
    }
    break;
   case 7:
    out = M2C_FIELD(&gRtcState, s32 **, 0xc);
    if (((u32)*(u16 *)0x27ffdea << 25) >> 31) out[0] = 1; else out[0] = 0;
    break;
   case 8:
    out = M2C_FIELD(&gRtcState, s32 **, 0xc);
    out[0] = (*(volatile u32 *)0x27ffdec << 29) >> 29;
    out[1] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 18) >> 26);
    out[2] = RtcBcdToInt((*(volatile u32 *)0x27ffdec << 9) >> 25);
    out[3] = 0;
    if ((*(volatile u32 *)0x27ffdec << 24) >> 31) out[3] += 1;
    if ((*(volatile u32 *)0x27ffdec << 16) >> 31) out[3] += 2;
    if ((*(volatile u32 *)0x27ffdec << 8) >> 31) out[3] += 4;
    break;
   case 9:
    if (M2C_FIELD(&gRtcState, s32 *, 0x1c) == 0) {
     if (*M2C_FIELD(&gRtcState, s32 **, 0xc) == 1) {
      if ((((RTCStatus *)0x27ffdea)->bits.mode) != 4) {
       M2C_FIELD(&gRtcState, s32 *, 0x1c)++;
       *(u16 *)0x27ffdea = (*(u16 *)0x27ffdea & ~15) | 4;
       if (!func_0200f6fc()) { M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0; result = 3; }
      }
     } else if ((((RTCStatus *)0x27ffdea)->bits.mode) != 0) {
      M2C_FIELD(&gRtcState, s32 *, 0x1c)++;
      *(u16 *)0x27ffdea = *(u16 *)0x27ffdea & ~15;
      if (!func_0200f6fc()) { M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0; result = 3; }
     }
    } else M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0;
    break;
   case 10:
    if (M2C_FIELD(&gRtcState, s32 *, 0x1c) == 0) {
     if (*M2C_FIELD(&gRtcState, s32 **, 0xc) == 1) {
      if ((((u32)*(u16 *)0x27ffdea << 25) >> 31) == 0) {
       M2C_FIELD(&gRtcState, s32 *, 0x1c)++;
       *(u16 *)0x27ffdea = *(u16 *)0x27ffdea | 64;
       if (!func_0200f6fc()) { M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0; result = 3; }
      }
     } else if (((u32)*(u16 *)0x27ffdea << 25) >> 31) {
      M2C_FIELD(&gRtcState, s32 *, 0x1c)++;
      *(u16 *)0x27ffdea = *(u16 *)0x27ffdea & ~64;
      if (!func_0200f6fc()) { M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0; result = 3; }
     }
    } else M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0;
    break;
   case 3: case 4: case 5: case 11: case 12: case 13: case 14: case 15: break;
   default: M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0; result = 4; break;
  }
 } else {
  M2C_FIELD(&gRtcState, s32 *, 0x1c) = 0;
  switch (status) {
   case 1: result = 4; break;
   case 2: result = 5; break;
   case 3: result = 1; break;
   case 0: case 4: default: result = 6; break;
  }
 }
 if (M2C_FIELD(&gRtcState, s32 *, 0x1c) == 0) {
  if (M2C_FIELD(&gRtcState, s32 *, 4)) M2C_FIELD(&gRtcState, s32 *, 4) = 0;
  callback = M2C_FIELD(&gRtcState, void (**)(s32, s32), 8);
  if (callback) { M2C_FIELD(&gRtcState, s32 *, 8) = 0; callback(result, M2C_FIELD(&gRtcState, s32 *, 0x14)); }
 }
}

/* Decodes a packed BCD value (8 nibbles, least significant digit first) into an
 * integer; returns 0 when any nibble is not a decimal digit. */
s32 RtcBcdToInt(u32 bcd) {
    s32 value;
    s32 place;
    s32 digit;
    s32 shift;
    s32 decShift;
    s32 i;

    value = 0;
    digit = 0;
    shift = 0;
loop_1:
    if ((u32) ((bcd >> shift) & 0xF) >= 0xAU) {
        return 0;
    }
    digit += 1;
    shift += 4;
    if (digit >= 8) {
        i = 0;
        decShift = 0;
        place = 1;
        do {
            value += place * ((bcd >> decShift) & 0xF);
            i += 1;
            place *= 0xA;
            decShift += 4;
        } while (i < 8);
        return value;
    }
    goto loop_1;
}

void func_0200f6a4(s32 arg0) {
    extern M2C_UNK gRtcState;
    M2C_FIELD(&gRtcState, s32 *, 0x24) = arg0;
}

#pragma opt_common_subs off
s32 func_0200f6b4(void) {
volatile s32 *p = &data_0212fd38;
s32 v;
while ((v = *p) == 1) {}
return v;
}
#pragma opt_common_subs reset
s32 SendRtcReadDateTimeCommand(void) {
    s32 func_0200f70c(s32);
    return func_0200f70c(0x10);
}

s32 SendRtcReadDateCommand(void) {
    return func_0200f70c(0x11);
}

s32 SendRtcReadTimeCommand(void) {
    return func_0200f70c(0x12);
}

s32 func_0200f6fc(void) {
    return func_0200f70c(0x27);
}

s32 func_0200f70c(s32 arg0) {
    s32 SendFifoMessage(M2C_UNK, s32, M2C_UNK);
    if (SendFifoMessage(5, (arg0 << 8) & 0x7F00, 0) < 0) {
        return 0;
    }
    return 1;
}

/* Converts an RTC date record (year at +0, month at +4, day at +8, weekday at
 * +0xC) into the count of days since 2000/01/01, or -1 while a field is out of
 * range.  gMonthDaysBeforeMonth is indexed by the month itself (entry 0 unused),
 * so month 1 reads the zero entry before gMonthDayTable; a leap year adds the
 * extra February day from March on. */
s32 RtcDateToDays(void *date) {
extern M2C_UNK gMonthDaysBeforeMonth;
s32 days; u32 day,month,year;
year=M2C_FIELD(date,u32 *,0);
if(year>=100 || (month=M2C_FIELD(date,u32 *,4))<1 || month>12 || (day=M2C_FIELD(date,u32 *,8))<1 || day>31 || M2C_FIELD(date,s32 *,12)>=7 || month<1 || month>12) return -1;
days=day-1+M2C_FIELD(&gMonthDaysBeforeMonth,s32 *,month*4);
if(month>=3 && !(year&3)) days++;
return year*365+days+((year+3)>>2);
}

s32 RtcTimeToSeconds(void *arg0) {
    return (((M2C_FIELD(arg0, s32 *, 0) * 0x3C) + M2C_FIELD(arg0, s32 *, 4)) * 0x3C) + M2C_FIELD(arg0, s32 *, 8);
}

#pragma opt_propagation off
/* Combine an RTC date record (days since 2000/01/01, via RtcDateToDays) and a
 * time record (seconds within the day, via RtcTimeToSeconds) into the seconds
 * elapsed since 2000/01/01, or -1 when either record is out of range. */
s64 MakeTime(void *date, void *time) {
    s32 RtcTimeToSeconds(void *);
    s32 days = RtcDateToDays(date);
    s32 secondsOfDay;

    if (days == -1) return -1;
    secondsOfDay = RtcTimeToSeconds(time);
    if (secondsOfDay == -1) return -1;
    return (s64)days * RTC_SECONDS_PER_DAY + secondsOfDay;
}
/* Convert a count of days since 2000/01/01 into the RTC date record: year at
 * +0, month at +4, day at +8 and weekday (0 = Sunday) at +0xC.  The count is
 * clamped to 99 years and 365 days; leap years have 366 days. */
void RtcDaysToDate(void *date, s32 days) {
    extern s32 gMonthDayTable[];
    s32 d = days;
    u32 years;
    s32 month;
    s32 r;

    if (d < 0) {
        d = 0;
    }
    if (d > 0x8EAC) {
        d = 0x8EAC;
    }
    M2C_FIELD(date, s32 *, 0xC) = (d + 6) % 7;
    for (years=0;;) {
        s32 saved;
        s32 sub;
        if (!(years & 3)) {
            sub = 0x16E;
        } else {
            sub = 0x16D;
        }
        saved = d;
        d -= sub;
        if (d < 0) {
            d = saved;
            break;
        }
        years++;
        if (years >= 0x63) {
            break;
        }
    }
    M2C_FIELD(date, u32 *, 0) = (u32)years;
    if (d > 0x16D) {
        d = 0x16D;
    }
    if (!(years & 3)) {
        if (d < 0x3C) {
            if (d < 0x1F) {
                month = 1;
            } else {
                d -= 0x1F;
                month = 2;
            }
            M2C_FIELD(date, s32 *, 4) = month;
            M2C_FIELD(date, s32 *, 8) = d + 1;
            return;
        }
        d -= 1;
    }
    r = 0xB;
    while (1) {
        if (d >= gMonthDayTable[r]) {
            M2C_FIELD(date, s32 *, 4) = r + 1;
            d -= *(volatile s32 *)&gMonthDayTable[r];
            M2C_FIELD(date, s32 *, 8) = d + 1;
            return;
        }
        r--;
        if (r < 0) {
            return;
        }
    }
}

/* Split a second count within one day into the RTC time record
 * (hours, minutes, seconds), clamping it to the day's range. */
void RtcSecondsToTime(s32 *clock, s32 secondsOfDay) {
    s32 minutes;

    if (secondsOfDay < 0) secondsOfDay = 0;
    if (secondsOfDay > RTC_SECONDS_PER_DAY - 1) secondsOfDay = RTC_SECONDS_PER_DAY - 1;
    minutes = secondsOfDay / RTC_SECONDS_PER_MINUTE;
    clock[2] = secondsOfDay % RTC_SECONDS_PER_MINUTE;
    clock[1] = minutes % RTC_SECONDS_PER_MINUTE;
    clock[0] = minutes / RTC_SECONDS_PER_MINUTE;
}

/* Split a second count since 2000/01/01 into the RTC date record (year, month, day,
 * weekday) and time record (hours, minutes, seconds), clamping the count to the one
 * century the clock can name. */
void RtcSecondsToDateTime(void *date,s32 *clock,s64 seconds) {
void RtcDaysToDate(void *,s32);
if(seconds<0) seconds=0;
else if(seconds>RTC_SECONDS_LAST) seconds=RTC_SECONDS_LAST;
RtcSecondsToTime(clock,seconds%RTC_SECONDS_PER_DAY);
RtcDaysToDate(date,seconds/RTC_SECONDS_PER_DAY);
}

#pragma opt_instruction_scheduling off
s32 func_0200fa50(void *arg0) {
register s32 month=M2C_FIELD(arg0,s32 *,4)-2;
register s32 year=M2C_FIELD(arg0,s32 *,0)+2000;
s32 century,yy,days,day=M2C_FIELD(arg0,s32 *,8);
if(month<1) year--;
century=year/100; yy=year%100;
if(month<1) month+=12;
days=day+(month*26-2)/10+yy;
days=days+yy/4+century/4+century*5;
return days%7;
}
#pragma opt_instruction_scheduling reset
void func_0200fb0c(s32 arg0) {
void SetThreadPriority(void *,s32); void func_02005e5c(void *); extern M2C_UNK gSaveDeviceState;
void *p=&gSaveDeviceState; s32 flags; void *thread;
SetThreadPriority((u8 *)p+0x44,M2C_FIELD(p,s32 *,0x108));
flags=M2C_FIELD(p,s32 *,0x114)|8;
thread=(u8 *)p+0x44;
M2C_FIELD(p,s32 *,0x114)=flags;
M2C_FIELD(p,void **,0x104)=thread;
M2C_FIELD(p,s32 *,0x40)=arg0;
func_02005e5c(thread);
}

#pragma opt_common_subs off
void func_0200fb48(s32 arg0,s32 arg1) {
void OS_SleepThread(void *); s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void SystemHalt(void);
extern M2C_UNK gSaveDeviceState;
void *p=&gSaveDeviceState; s32 state=OS_DisableInterrupts();
if(M2C_FIELD(p,s32 *,8)==arg0) {
if(M2C_FIELD(p,s32 *,0x18)!=arg1) SystemHalt();
} else {
goto check;
loop: OS_SleepThread((u8 *)p+0x10);
check: if(M2C_FIELD(p,s32 *,8)!=-3) {goto loop;}
M2C_FIELD(p,s32 *,8)=arg0; M2C_FIELD(p,s32 *,0x18)=arg1;
}
{ u32 count=M2C_FIELD(p,u32 *,12); u32 *out=M2C_FIELD(p,u32 **,0); M2C_FIELD(p,s32 *,12)=count+1; *out=0; }
OS_RestoreInterrupts(state);
}
#pragma opt_instruction_scheduling off
void func_0200fbcc(s32 arg0, s32 arg1) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void SystemHalt(void); void OS_WakeupThread(void *);
extern M2C_UNK gSaveDeviceState;
void *p=&gSaveDeviceState; s32 state=OS_DisableInterrupts();
if(M2C_FIELD(p,s32*,8)!=arg0 || M2C_FIELD(p,s32*,12)==0){SystemHalt();goto done;}
if(M2C_FIELD(p,s32*,0x18)!=arg1)SystemHalt();
if(--M2C_FIELD(p,s32*,12)==0){
M2C_FIELD(p,s32*,8)=-3;
M2C_FIELD(p,s32*,0x18)=M2C_FIELD(p,s32*,12);
OS_WakeupThread((u8*)p+0x10);
}
done:
*M2C_FIELD(p,s32**,0)=0;OS_RestoreInterrupts(state);
}
#pragma opt_instruction_scheduling reset
