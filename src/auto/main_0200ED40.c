/* 34 functions from 0x0200ED40 to 0x0200FC58 (main), found by ds-decomp. */
#include "common.h"

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
void func_0200ed54(M2C_UNK *arg0,M2C_UNK arg1) {
M2C_UNK p,n;
if(!arg0)return;
p=*arg0;
if(!p){M2C_FIELD(arg1,M2C_UNK *,8)=0; *arg0=arg1;return;}
n=M2C_FIELD(p,M2C_UNK *,8);
if(n)do{p=n;n=M2C_FIELD(n,M2C_UNK *,8);}while(n);
M2C_FIELD(arg1,M2C_UNK *,8)=n; M2C_FIELD(p,M2C_UNK *,8)=arg1;
}
void func_0200eda0(M2C_UNK *arg0, M2C_UNK arg1) {
    M2C_UNK var_r2;
    M2C_UNK var_r3;
    if (arg0 != NULL) {
        var_r2 = *arg0;
        var_r3 = var_r2;
        if (var_r2 != 0) {
            do {
                if (var_r2 == arg1) {
                    if (var_r2 == var_r3) *arg0 = M2C_FIELD(var_r2, M2C_UNK *, 8);
                    else M2C_FIELD(var_r3, M2C_UNK *, 8) = M2C_FIELD(var_r2, M2C_UNK *, 8);
                    return;
                }
                var_r3 = var_r2;
                var_r2 = M2C_FIELD(var_r2, M2C_UNK *, 8);
            } while (var_r2 != 0);
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

void func_0200ee10(void *arg0) { extern M2C_UNK data_0212fcd8; void (*f)(void **,void *)=func_0200ed40; f((void **)&data_0212fcd8,arg0); }

void func_0200ee28(M2C_UNK arg0) { extern M2C_UNK data_0212fce0; void (*f)(M2C_UNK *,M2C_UNK)=func_0200ed54; f(&data_0212fce0,arg0); }
#pragma scheduling reset
void func_0200ee40(M2C_UNK arg0) { extern M2C_UNK data_0212fcd8; void (*f)(M2C_UNK *,M2C_UNK)=func_0200eda0; f(&data_0212fcd8,arg0); }
#pragma peephole reset
#pragma scheduling reset
void func_0200ee58(M2C_UNK arg0) {
    void func_0200eda0(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212fce0;
    func_0200eda0(&data_0212fce0, arg0);
}
void func_0200ee70(void) {
    M2C_UNK func_02009d34();
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fd34;
    extern M2C_UNK func_0200f0e4;
    if (M2C_FIELD(&data_0212fd34, u16 *, 0) != 0) return;
    M2C_FIELD(&data_0212fd34, u16 *, 0) = 1;
    M2C_FIELD(&data_0212fd34, s32 *, 4) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 8) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0x20) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0xC) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0x10) = 0;
    func_02009d34();
    do {} while (func_02009e8c(5, 1) == 0);
    func_02009e40(5, &func_0200f0e4);
}

s32 func_0200eedc(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212fd34;
    s32 state;
    state = func_0200751c();
    if (M2C_FIELD(&data_0212fd34, s32 *, 4) != 0) {
        func_02007530(state);
        return 1;
    }
    M2C_FIELD(&data_0212fd34, s32 *, 4) = 1;
    func_02007530(state);
    M2C_FIELD(&data_0212fd34, s32 *, 0x18) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0xC) = arg0;
    M2C_FIELD(&data_0212fd34, s32 *, 8) = arg1;
    M2C_FIELD(&data_0212fd34, s32 *, 0x14) = arg2;
    if (func_0200f6dc() != 0) return 0;
    return 3;
}

s32 func_0200ef4c(s32 arg0) {
    s32 func_0200eedc(s32, s32, s32);
    void func_0200f6a4(s32);
    s32 func_0200f6b4(void);
    extern M2C_UNK data_0212fd34;
    s32 result;
    result = func_0200eedc(arg0, (s32)func_0200f6a4, 0);
    M2C_FIELD(&data_0212fd34, s32 *, 0x24) = result;
    if (result == 0) func_0200f6b4();
    return M2C_FIELD(&data_0212fd34, s32 *, 0x24);
}

s32 func_0200ef84(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212fd34;
    s32 state;
    state = func_0200751c();
    if (M2C_FIELD(&data_0212fd34, s32 *, 4) != 0) {
        func_02007530(state);
        return 1;
    }
    M2C_FIELD(&data_0212fd34, s32 *, 4) = 1;
    func_02007530(state);
    M2C_FIELD(&data_0212fd34, s32 *, 0x18) = 1;
    M2C_FIELD(&data_0212fd34, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0xC) = arg0;
    M2C_FIELD(&data_0212fd34, s32 *, 8) = arg1;
    M2C_FIELD(&data_0212fd34, s32 *, 0x14) = arg2;
    if (func_0200f6ec() != 0) return 0;
    return 3;
}
#pragma opt_common_subs reset
s32 func_0200eff8(s32 arg0) {
    s32 func_0200ef84(s32, s32, s32);
    void func_0200f6a4(s32);
    s32 func_0200f6b4(void);
    extern M2C_UNK data_0212fd34;
    s32 result;
    result = func_0200ef84(arg0, (s32)func_0200f6a4, 0);
    M2C_FIELD(&data_0212fd34, s32 *, 0x24) = result;
    if (result == 0) func_0200f6b4();
    return M2C_FIELD(&data_0212fd34, s32 *, 0x24);
}

s32 func_0200f030(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212fd34;
    s32 state;
    state = func_0200751c();
    if (M2C_FIELD(&data_0212fd34, s32 *, 4) != 0) {
        func_02007530(state);
        return 1;
    }
    M2C_FIELD(&data_0212fd34, s32 *, 4) = 1;
    func_02007530(state);
    M2C_FIELD(&data_0212fd34, s32 *, 0x18) = 2;
    M2C_FIELD(&data_0212fd34, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_0212fd34, s32 *, 0xC) = arg0;
    M2C_FIELD(&data_0212fd34, s32 *, 0x10) = arg1;
    M2C_FIELD(&data_0212fd34, s32 *, 8) = arg2;
    M2C_FIELD(&data_0212fd34, s32 *, 0x14) = arg3;
    if (func_0200f6cc() != 0) return 0;
    return 3;
}
#pragma opt_common_subs reset
s32 func_0200f0ac(s32 arg0, s32 arg1) {
void func_0200f6a4(s32); s32 func_0200f6b4(void); extern M2C_UNK data_0212fd34;
s32 result = func_0200f030(arg0,arg1,(s32)func_0200f6a4,0);
M2C_FIELD(&data_0212fd34,s32 *,0x24)=result;
if(result==0) func_0200f6b4();
return M2C_FIELD(&data_0212fd34,s32 *,0x24);
}

void func_0200f0e4(s32 arg0, u32 arg1, s32 arg2) {
 extern M2C_UNK data_0212fd34;
 s32 func_0200fa50(void *);
 s32 func_0200f6fc(void);
 u8 command;
 u8 status;
 s32 result;
 s32 *out;
 void (*callback)(s32,s32);
 if (arg2) {
  if (M2C_FIELD(&data_0212fd34,s32 *,0x1c)) M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;
  if (M2C_FIELD(&data_0212fd34,s32 *,4)) M2C_FIELD(&data_0212fd34,s32 *,4)=0;
  callback=M2C_FIELD(&data_0212fd34,void (**)(s32,s32),8);
  if(callback) { M2C_FIELD(&data_0212fd34,s32 *,8)=0; callback(6,M2C_FIELD(&data_0212fd34,s32 *,0x14)); }
  return;
 }
 command=(u8)((arg1 & 0x7f00)>>8);
 status=(u8)arg1;
 if (command==0x30) {
  if(M2C_FIELD(&data_0212fd34,void (**)(void),0x20)) M2C_FIELD(&data_0212fd34,void (**)(void),0x20)();
  return;
 }
 if (status==0) {
  result=0;
  switch(M2C_FIELD(&data_0212fd34,u32 *,0x18)) {
   case 0:
    out=M2C_FIELD(&data_0212fd34,s32 **,0xc);
    out[0]=func_0200f634((*(volatile u32 *)0x27ffde8 <<24)>>24);
    out[1]=func_0200f634((*(volatile u32 *)0x27ffde8 <<19)>>27);
    out[2]=func_0200f634((*(volatile u32 *)0x27ffde8 <<10)>>26);
    out[3]=func_0200fa50(out);
    break;
   case 1:
    out=M2C_FIELD(&data_0212fd34,s32 **,0xc);
    out[0]=func_0200f634((*(volatile u32 *)0x27ffdec <<26)>>26);
    out[1]=func_0200f634((*(volatile u32 *)0x27ffdec <<17)>>25);
    out[2]=func_0200f634((*(volatile u32 *)0x27ffdec <<9)>>25);
    break;
   case 2:
    out=M2C_FIELD(&data_0212fd34,s32 **,0xc);
    out[0]=func_0200f634(*(volatile u32 *)0x27ffde8 &255);
    out[1]=func_0200f634((*(volatile u32 *)0x27ffde8 <<19)>>27);
    out[2]=func_0200f634((*(volatile u32 *)0x27ffde8 <<10)>>26);
    out[3]=func_0200fa50(out);
    out=M2C_FIELD(&data_0212fd34,s32 **,0x10);
    out[0]=func_0200f634((*(volatile u32 *)0x27ffdec <<26)>>26);
    out[1]=func_0200f634((*(volatile u32 *)0x27ffdec <<17)>>25);
    out[2]=func_0200f634((*(volatile u32 *)0x27ffdec <<9)>>25);
    break;
   case 6:
    out=M2C_FIELD(&data_0212fd34,s32 **,0xc);
    switch(((RTCStatus *)0x27ffdea)->bits.mode) {
     case 4: out[0]=1; break;
     default: out[0]=0; break;
    }
    break;
   case 7:
    out=M2C_FIELD(&data_0212fd34,s32 **,0xc);
    if(((u32)*(u16 *)0x27ffdea <<25)>>31) out[0]=1; else out[0]=0;
    break;
   case 8:
    out=M2C_FIELD(&data_0212fd34,s32 **,0xc);
    out[0]=(*(volatile u32 *)0x27ffdec <<29)>>29;
    out[1]=func_0200f634((*(volatile u32 *)0x27ffdec <<18)>>26);
    out[2]=func_0200f634((*(volatile u32 *)0x27ffdec <<9)>>25);
    out[3]=0;
    if((*(volatile u32 *)0x27ffdec <<24)>>31) out[3]+=1;
    if((*(volatile u32 *)0x27ffdec <<16)>>31) out[3]+=2;
    if((*(volatile u32 *)0x27ffdec <<8)>>31) out[3]+=4;
    break;
   case 9:
    if(M2C_FIELD(&data_0212fd34,s32 *,0x1c)==0) {
     if(*M2C_FIELD(&data_0212fd34,s32 **,0xc)==1) {
      if((((RTCStatus *)0x27ffdea)->bits.mode)!=4) {
       M2C_FIELD(&data_0212fd34,s32 *,0x1c)++;
       *(u16 *)0x27ffdea=(*(u16 *)0x27ffdea &~15)|4;
       if(!func_0200f6fc()) { M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;result=3; }
      }
     } else if((((RTCStatus *)0x27ffdea)->bits.mode)!=0) {
      M2C_FIELD(&data_0212fd34,s32 *,0x1c)++;
      *(u16 *)0x27ffdea=*(u16 *)0x27ffdea &~15;
      if(!func_0200f6fc()) { M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;result=3; }
     }
    } else M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;
    break;
   case 10:
    if(M2C_FIELD(&data_0212fd34,s32 *,0x1c)==0) {
     if(*M2C_FIELD(&data_0212fd34,s32 **,0xc)==1) {
      if((((u32)*(u16 *)0x27ffdea <<25)>>31)==0) {
       M2C_FIELD(&data_0212fd34,s32 *,0x1c)++;
       *(u16 *)0x27ffdea=*(u16 *)0x27ffdea |64;
       if(!func_0200f6fc()) { M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;result=3; }
      }
     } else if(((u32)*(u16 *)0x27ffdea <<25)>>31) {
      M2C_FIELD(&data_0212fd34,s32 *,0x1c)++;
      *(u16 *)0x27ffdea=*(u16 *)0x27ffdea &~64;
      if(!func_0200f6fc()) { M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;result=3; }
     }
    } else M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;
    break;
   case 3: case 4: case 5: case 11: case 12: case 13: case 14: case 15: break;
   default: M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0; result=4;break;
  }
 } else {
  M2C_FIELD(&data_0212fd34,s32 *,0x1c)=0;
  switch(status) {
   case 1: result=4;break;
   case 2: result=5;break;
   case 3: result=1;break;
   case 0: case 4: default: result=6;break;
  }
 }
 if(M2C_FIELD(&data_0212fd34,s32 *,0x1c)==0) {
  if(M2C_FIELD(&data_0212fd34,s32 *,4)) M2C_FIELD(&data_0212fd34,s32 *,4)=0;
  callback=M2C_FIELD(&data_0212fd34,void (**)(s32,s32),8);
  if(callback) { M2C_FIELD(&data_0212fd34,s32 *,8)=0; callback(result,M2C_FIELD(&data_0212fd34,s32 *,0x14)); }
 }
}

s32 func_0200f634(u32 arg0) {
    s32 var_ip;
    s32 var_lr;
    s32 var_r2;
    s32 var_r3;
    s32 var_r4;
    s32 var_r5;

    var_ip = 0;
    var_r2 = 0;
    var_r3 = 0;
loop_1:
    if ((u32) ((arg0 >> var_r3) & 0xF) >= 0xAU) {
        return 0;
    }
    var_r2 += 1;
    var_r3 += 4;
    if (var_r2 >= 8) {
        var_r5 = 0;
        var_r4 = 0;
        var_lr = 1;
        do {
            var_ip += var_lr * ((arg0 >> var_r4) & 0xF);
            var_r5 += 1;
            var_lr *= 0xA;
            var_r4 += 4;
        } while (var_r5 < 8);
        return var_ip;
    }
    goto loop_1;
}

void func_0200f6a4(s32 arg0) {
    extern M2C_UNK data_0212fd34;
    M2C_FIELD(&data_0212fd34, s32 *, 0x24) = arg0;
}

s32 func_0200f6b4(void) {
extern s32 data_0212fd38;
s32 state;
do {state=data_0212fd38;} while(state==1);
return state;
}

s32 func_0200f6cc(void) {
    s32 func_0200f70c(s32);
    return func_0200f70c(0x10);
}

s32 func_0200f6dc(void) {
    return func_0200f70c(0x11);
}

s32 func_0200f6ec(void) {
    return func_0200f70c(0x12);
}

s32 func_0200f6fc(void) {
    return func_0200f70c(0x27);
}

s32 func_0200f70c(s32 arg0) {
    s32 func_02009eb0(M2C_UNK, s32, M2C_UNK);
    if (func_02009eb0(5, (arg0 << 8) & 0x7F00, 0) >= 0) {
        return 1;
    }
    return 0;
}

s32 func_0200f734(void *arg0) {
extern M2C_UNK data_020f5508;
s32 days; u32 day,month,year;
year=M2C_FIELD(arg0,u32 *,0);
if(year>=100 || (month=M2C_FIELD(arg0,u32 *,4))<1 || month>12 || (day=M2C_FIELD(arg0,u32 *,8))<1 || day>31 || M2C_FIELD(arg0,s32 *,12)>=7 || month<1 || month>12) return -1;
days=day-1+M2C_FIELD(&data_020f5508,s32 *,month*4);
if(month>=3 && !(year&3)) days++;
return year*365+days+((year+3)>>2);
}

s32 func_0200f7c8(void *arg0) {
    return (((M2C_FIELD(arg0, s32 *, 0) * 0x3C) + M2C_FIELD(arg0, s32 *, 4)) * 0x3C) + M2C_FIELD(arg0, s32 *, 8);
}

#pragma opt_strength_reduction off
long long func_0200f7e0(void *arg0, void *arg1) {
 s32 func_0200f7c8(void *);
 s32 days=func_0200f734(arg0); s32 seconds;
 if(days==-1) return -1;
 seconds=func_0200f7c8(arg1);
 if(seconds==-1) return -1;
 return (long long)days*86400LL+seconds;
}
#pragma opt_strength_reduction reset
void func_0200f844(void *arg0, s32 arg1) {
    extern s32 data_020f550c[];
    s32 d = arg1;
    s32 years = 0;
    s32 m;
    s32 r;

    if (d < 0) {
        d = 0;
    }
    if (d > 0x8EAC) {
        d = 0x8EAC;
    }
    M2C_FIELD(arg0, s32 *, 0xC) = (d + 6) % 7;
    for (;;) {
        s32 sub;
        s32 saved;
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
    M2C_FIELD(arg0, u32 *, 0) = (u32)years;
    if (d > 0x16D) {
        d = 0x16D;
    }
    if (!(years & 3)) {
        if (d < 0x3C) {
            if (d < 0x1F) {
                m = 1;
            } else {
                d -= 0x1F;
                m = 2;
            }
            M2C_FIELD(arg0, s32 *, 4) = m;
            M2C_FIELD(arg0, s32 *, 8) = d + 1;
            return;
        }
        d -= 1;
    }
    r = 0xB;
    while (1) {
        if (d >= data_020f550c[r]) {
            M2C_FIELD(arg0, s32 *, 4) = r + 1;
            M2C_FIELD(arg0, s32 *, 8) = d - data_020f550c[r] + 1;
            return;
        }
        r--;
        if (r < 0) {
            return;
        }
    }
}

void func_0200f944(s32 *arg0,s32 arg1) {
    s32 minutes;
    if(arg1<0) arg1=0;
    if(arg1>86399) arg1=86399;
    minutes=arg1/60;
    arg0[2]=arg1%60;
    arg0[1]=minutes%60;
    arg0[0]=minutes/60;
}

void func_0200f9c4(void *arg0,s32 *arg1,long long time) {
void func_0200f844(void *,s32);
if(time<0) time=0;
else if(time>3155759999LL) time=3155759999LL;
func_0200f944(arg1,time%86400);
func_0200f844(arg0,time/86400);
}

s32 func_0200fa50(void *arg0) {
register s32 month=M2C_FIELD(arg0,s32 *,4)-2;
register s32 year=M2C_FIELD(arg0,s32 *,0)+2000;
s32 century,yy,days,day=M2C_FIELD(arg0,s32 *,8);
if(month<1) year--;
century=year/100; yy=year%100;
if(month<1) month+=12;
days=day+(month*26-2)/10; days+=yy; days+=yy/4; days+=century/4; days+=century*5;
return days%7;
}

void func_0200fb0c(s32 arg0) {
void func_02005f80(void *,s32); void func_02005e5c(void *); extern M2C_UNK data_0212fde0;
void *p=&data_0212fde0; s32 flags; void *thread;
func_02005f80((u8 *)p+0x44,M2C_FIELD(p,s32 *,0x108));
flags=M2C_FIELD(p,s32 *,0x114)|8;
thread=(u8 *)p+0x44;
M2C_FIELD(p,s32 *,0x114)=flags;
M2C_FIELD(p,void **,0x104)=thread;
M2C_FIELD(p,s32 *,0x40)=arg0;
func_02005e5c(thread);
}

void func_0200fb48(s32 arg0,s32 arg1) {
void func_02005da4(void *); s32 func_0200751c(void); void func_02007530(s32); void func_02007958(void);
extern M2C_UNK data_0212fde0;
void *p=&data_0212fde0; s32 state=func_0200751c();
if(M2C_FIELD(p,s32 *,8)==arg0) {
if(M2C_FIELD(p,s32 *,0x18)!=arg1) func_02007958();
} else {
goto check;
loop: func_02005da4((u8 *)p+0x10);
check: if(M2C_FIELD(p,s32 *,8)!=-3) {goto loop;}
M2C_FIELD(p,s32 *,8)=arg0; M2C_FIELD(p,s32 *,(unsigned)0x18)=arg1;
}
{ s32 count=M2C_FIELD(p,s32 *,12); s32 *out=M2C_FIELD(p,s32 **,0); M2C_FIELD(p,s32 *,12)=count+1; *out=0; }
func_02007530(state);
}

void func_0200fbcc(s32 arg0, s32 arg1) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02007958(void);
    void func_02005df4(void *);
    extern M2C_UNK data_0212fde0;
    void *p = &data_0212fde0;
    s32 state;
    s32 temp;

    state = func_0200751c();
    if (M2C_FIELD(p, s32 *, 8) == arg0) {
        if (M2C_FIELD(p, s32 *, 12) == 0) {
            func_02007958();
            goto done;
        }
    } else {
        if (M2C_FIELD(p, s32 *, 0x18) != arg1) func_02007958();
    }
    temp = M2C_FIELD(p, s32 *, 12) - 1;
    M2C_FIELD(p, s32 *, 12) = temp;
    if (temp == 0) {
        s32 nv = -3;
        s32 zv = 0;
        u8 *av = (u8 *)p + 0x10;
        M2C_FIELD(p, s32 *, 8) = nv;
        M2C_FIELD(p, s32 *, 0x18) = zv;
        func_02005df4(av);
    }
done:
    *M2C_FIELD(p, s32 **, 0) = 0;
    func_02007530(state);
}

