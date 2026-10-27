/* 30 functions from 0x0202F37C to 0x02030348 (main), found by ds-decomp. */
#include "common.h"

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
 extern M2C_UNK data_0213d100;
 if (arg0 & 1) return M2C_FIELD(&data_0213d100, void **, 0x10);
 if (arg0 & 2) return M2C_FIELD(&data_0213d100, void **, 4);
 if (arg0 & 4) return M2C_FIELD(&data_0213d100, void **, 8);
 if (arg0 & 8) return M2C_FIELD(&data_0213d100, void **, 0xC);
 if (arg0 & 0x10) return M2C_FIELD(&data_0213d100, void **, 0);
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

u8 func_0202f544(void) {
    extern M2C_UNK data_0213d100;
    return M2C_FIELD(M2C_FIELD(&data_0213d100, void **, 0x10), u8 *, 9);
}

void func_0202f558(s32 arg0) {
    void *func_0202f48c(M2C_UNK);
    void *temp_r0;

    temp_r0 = func_0202f48c(1);
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg0;
    M2C_FIELD(temp_r0, s8 *, 0xA) = func_0202f544();
}

s32 func_0202f57c(void) {
 extern M2C_UNK data_0213d100;
 return M2C_FIELD(M2C_FIELD(&data_0213d100, void **, 0x10), s32 *, 0xC);
}

void func_0202f590(u32 arg0) {
 extern M2C_UNK data_0213d100;
 M2C_FIELD(M2C_FIELD(&data_0213d100, void **, 0x10), u8 *, 0x17) = func_0202f5ac(arg0);
}

u32 func_0202f5ac(u32 arg0) {
 if (arg0 > 2) arg0 = (u8)(arg0 - 3);
 return arg0;
}

void func_0202f5bc(void) {
 void func_0202f334(s32, void *, s32);
 extern M2C_UNK data_0213d100;
 func_0202f334(8, M2C_FIELD(&data_0213d100, void **, 0xC), 0xC);
 func_0202f334(0x10, M2C_FIELD(&data_0213d100, void **, 0), 0xD18);
}

s32 func_0202f5f4(void) {
 s32 func_02068eac(void *, void *, s32);
 extern M2C_UNK data_0213d100;
 s32 offset;
 void *base;
 u8 i;
 u8 selected;
 void *p;
 u8 count;
 p = M2C_FIELD(&data_0213d100, void **, 0);
 selected = M2C_FIELD(p,u8 *,0xD13);
 base = p + 0x474;
 offset = (s16)selected * (s16)0xC0;
 if (M2C_FIELD(p,u8 *,0xD0D) >= 6) return 1;
 count = M2C_FIELD(p,u8 *,0xD12);
 for (i=0;i<count;i++) {
  if (i != selected && M2C_FIELD(p + i*4,u8 *,0x445)<6) {
   s32 off = i*0xC0;
   if (func_02068eac(base+offset,base+off,M2C_FIELD(p+off,u16 *,0x47A))==0) return 2;
  }
 }
 return 1;
}

void func_0202f694(s32 arg0) {
 void *a=(void *)arg0;
 void *func_0202f48c(s32); u8 func_0202f544(void);
 void func_02030afc(u16); s32 func_0202f894(void *,s32,void *); s32 func_0202f910(void *,void *);
 s32 func_0202f9a0(s32,void *,M2C_UNK,void *); void func_0202fb20(s32,s32);
 s32 result=-1; u8 v; void *p=func_0202f48c(16);
 M2C_FIELD(func_0202f48c(1),u8 *,11)=1;
 switch(func_0202f544()) {
 case 3:
 v=M2C_FIELD(p,u8 *,0xD11);
 if(M2C_FIELD(a,u16 *,10)==0 || M2C_FIELD(a,u8 *,12)==0) {func_02030afc(M2C_FIELD(a,u16 *,0x36));}
 else if(M2C_FIELD(a,u16 *,10)==1 || M2C_FIELD(a,u8 *,12)==32) {
 func_02030afc(M2C_FIELD(a,u16 *,0x36));
 result=func_0202f894(a,M2C_FIELD(p,u8 *,0xD10),p+0x300);
 }else result=func_0202f894(a,M2C_FIELD(p,u8 *,0xD10),p+0x300);
 break;
 case 4:
 v=M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD0F)*0xC0,u16 *,0x4A6)-1;
 result=func_0202f910(a,p);
 if(result>=0) M2C_FIELD(p+0x447+M2C_FIELD(p,u8 *,0xD0F)*4,u8 *,0)|=0x80;
 break;
 case 5:
 v=M2C_FIELD(p,u8 *,0xD11);
 result=func_0202f894(a,1,p+0x300+M2C_FIELD(p,u8 *,0xD0F)*0x24);
 if(result>=0) {
 s32 i=(s16)M2C_FIELD(p,u8 *,0xD0F)*(s16)0x24; void *q=p+0x300;
 M2C_FIELD(q+i,u8 *,0)=(M2C_FIELD(q+i,u8 *,0)&~15)|1;
 } break;
 default:return;
 }
 if(result>=0) func_0202fb20(func_0202f9a0(result,a,v,p),(s32)p);
}

s32 func_0202f800(void *arg0) {
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
 s32 func_02068eac(void *,void *,s32);
 s32 t; u8 k; s32 i; u32 n; void *p=arg2;
 if(M2C_FIELD(arg0,u16 *,0xA)==0x20) { t=func_0202f800(arg0); if(t>0)return t; }
 i=0;
 if(arg1>0) {
 n=M2C_FIELD(arg0,u16 *,0xA); k=n;
 do {
 if(k==M2C_FIELD(p,u8 *,3) && func_02068eac(arg0+0xC,p+4,n)==0)return M2C_FIELD(p,u8 *,1);
 i++; p+=0x24;
 }while(i<arg1);
 }
 return -1;
}

s32 func_0202f910(void *arg0,void *arg1) {
 s32 func_02068eac(void *,void *,s32);
 s32 t,i; void *p,*q; s32 len,n;
 if(M2C_FIELD(arg0,u16 *,0xA)==0x20) {t=func_0202f800(arg0); if(t>0)return t;}
 n=M2C_FIELD(arg1,u8 *,0xD12); i=0;
 if(n>0) {
 len=M2C_FIELD(arg0,u16 *,0xA); p=arg1; q=arg1+0x47C;
 do{
 if(len==M2C_FIELD(p,u16 *,0x47A) && func_02068eac(arg0+0xC,q,len)==0) return M2C_FIELD(arg1+i*4,u8 *,0x445);
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

void func_0202fa68(u8 arg0, void *arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_02007e70(void *, s32, M2C_UNK);
    s32 var_r0;
    u16 temp_r0;
    void *temp_ip;

    temp_ip = arg3 + 0x6C;
    M2C_FIELD(temp_ip, s8 *, 0x401) = arg0;
    temp_r0 = M2C_FIELD(arg1, u16 *, 2);
    var_r0 = (s32) temp_r0 >> 2;
    if (!(temp_r0 & 2)) {
        var_r0 += 0x19;
    }
    M2C_FIELD(temp_ip, u8 *, 0x402) = (u8) var_r0;
    M2C_FIELD(temp_ip, u8 *, 0x403) = (u8) ((M2C_FIELD(temp_ip, u8 *, 0x403) & ~0x7F) | (arg2 & 0x7F));
    func_02007e70(arg1, arg3 + 0xBF0, 0xC0);
}

void func_0202fab4(s32 arg0, void *arg1, s32 arg2, void *arg3) {
 M2C_UNK func_02007e70(void *, s32, M2C_UNK);
 u16 n;
 void *base;
 s32 offset;
 void *p;
 u16 v;
 v=M2C_FIELD(arg1,u16 *,2);
 base=arg3+0x444;
 offset=arg0*0xC0;
 arg0=(s32)(base+arg0*4);
 p=(void *)arg0;
 if(v&2) n=(s32)v>>2;
 else n=((s32)v>>2)+25;
 
 n=(u8)n;
 n=(u8)n;
 arg3=arg3+0x470;
 if((u32)(u8)n>M2C_FIELD(p,u8 *,2)) {
 M2C_FIELD(p,u8 *,2)=n;
 M2C_FIELD(p,u8 *,3)=(M2C_FIELD(p,u8 *,3)&~0x7F)|(arg2&0x7F);
 }
 func_02007e70(arg1,(s32)arg3+offset,0xC0);
}

void func_0202fb20(s32 arg0, s32 arg1) {
    M2C_UNK func_02007e54(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02007e70(void *, s32, s32);
    u8 sp4[0xc0];
    M2C_UNK sp0;
    M2C_UNK *temp_r5;
    M2C_UNK *var_r9;
    s32 temp_r5_2;
    s32 temp_r7;
    s32 temp_r8;
    s32 var_r10;
    s32 var_r4;
    s32 var_r6;

    var_r4 = arg0;
    temp_r7 = arg1 + 0x444;
    temp_r8 = arg1 + 0x470;
    var_r6 = var_r4 - 1;
    if (var_r6 >= 0) {
        var_r10 = (var_r6 * 0xC0) + temp_r8;
        var_r9 = temp_r7 + (var_r6 * 4);
loop_2:
        if ((u32) M2C_FIELD((temp_r7 + (var_r4 * 4)), u8 *, 2) >= (u32) M2C_FIELD((temp_r7 + (var_r6 * 4)), u8 *, 2)) {
            func_02007e70(var_r9, (s32)&sp0, 4);
            temp_r5 = temp_r7 + (var_r4 * 4);
            func_02007e70(temp_r5, (s32)var_r9, 4);
            func_02007e70(&sp0, (s32)temp_r5, 4);
            func_02007e70((M2C_UNK *) var_r10, (s32)sp4, 0xC0);
            temp_r5_2 = var_r4 * 0xC0;
            func_02007e70((void *)(temp_r8 + temp_r5_2), var_r10, 0xC0);
            func_02007e70(&sp4, temp_r8 + temp_r5_2, 0xC0);
            var_r4 = var_r6;
            var_r9 -= 1;
            var_r10 -= 0xC0;
            var_r6 -= 1;
            if (var_r6 >= 0) {
                goto loop_2;
            }
        }
    }
    func_02007e54(0, temp_r7 + 0x28, 4);
    func_02007e54(0, temp_r8 + 0x780, 0xC0);
}

void func_0202fc10(void *arg0) {
 void func_0202f694(s32);
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
 } else if(type==7) func_0202f694(M2C_FIELD(arg0,s32 *,4));
}

s32 func_0202fc9c(void) {
    s32 func_0202fce0();
    s32 func_0202fdd8();
    s32 var_r4;

    var_r4 = func_0202f544();
    func_0202f48c(0x10);
    switch (var_r4) {                               /* irregular */
    case 7:
        var_r4 = func_0202fce0();
        break;
    case 8:
        var_r4 = func_0202fdd8();
        break;
    }
    return var_r4;
}

/* Polls/refreshes the current entry for state 'p': clears the D0D slot, zeroes a temp buffer,
   calls func_020300e8 to (re)validate, then updates the D0B flags and reports 9 or 8. */
s32 func_0202fce0(void *p) {
void func_02007f8c(void *,s32,s32); u8 func_0202ff14(void *);
void *q=p+0x470+M2C_FIELD(p,u8 *,0xD13)*0xC0;
s32 ok;
M2C_FIELD(p,u8 *,0xD0D)=func_0202ff14(p);
func_02007f8c(p+0xCB8,0,0x52);
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
s32 func_020300b0(void *);
s32 func_0202fdd8(u8 *p) {
u32 func_02027c84(); s32 func_020300b0(void *); s32 func_020300cc(void *);
void func_02027754(void *,void *,s32); unsigned long long func_02007004(void);
s32 state=func_02027c84(p); s32 off; u8 *base; s32 flags; base=p+0x470; off=(s16)p[0xd13]*(s16)192;
if(state==3) {
{ s32 (*getFlags)(void *)=func_020300b0; flags=getFlags(p); }
p[0xd15]++;
if(p[0xd15]>3){p[0xd15]=0;M2C_FIELD(p+p[0xd13]*4,u8 *,0x444)=1;return 9;}
if(p[0xd15]!=1) {
if(p[0xd14]==1)p[0xd0b]&=~12;
else if(p[0xd14]==2){p[0xd15]=0;M2C_FIELD(p+p[0xd13]*4,u8 *,0x444)=3;return 9;}
else if(p[0xd14]==3){p[0xd15]=0;M2C_FIELD(p+p[0xd13]*4,u8 *,0x444)=4;return 9;}
else if(p[0xd15]==3)p[0xd0b]&=~12;
}
func_02027754(base+off,p+0xcb8,flags|func_020300cc(p));
} else if(state==9) {p[0xd15]=0;M2C_FIELD(p,unsigned long long *,0xcb0)=func_02007004();return 10;}
return 8;
}
#pragma dont_inline reset
s32 func_020300b0(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xD0B) << 0x1E) >> 0x1E) == 1) {
        return 0x30000;
    }
    return 0x20000;
}

s32 func_020300cc(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xD0B) << 0x1C) >> 0x1E) == 1) {
        return 0xC0000;
    }
    return 0x80000;
}

/* Builds an outgoing command/payload at `out` from game state `state` using mode `type` (0..9); returns whether out[0] is nonzero. */
s32 func_020300e8(void *state, u32 type, void *out) {
void func_02008048(void *,void *,s32);
void func_0203181c(s32,void *);
void func_02031784(s32,void *);
switch(type) {
case 2:state+=0x100;
case 1:state+=0x100;
case 0:M2C_FIELD(out,u8 *,0)=(u32)(M2C_FIELD(state,u8 *,0xE6)<<30)>>30;func_02008048(state+0x80,out+2,0x50);break;
case 5:state+=0x100;
case 4:state+=0x100;
case 3:M2C_FIELD(out,u8 *,0)=1;func_02008048(state+0xD1,out+2,0x14);M2C_FIELD(out,u8 *,0x16)=0;break;
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
 void func_02027a74(void);
 u32 func_02027c84(void);
 switch(func_02027c84()) {
 case 0:return 1;
 case 1:func_020271cc();break;
 case 3:func_02027428();break;
 case 6:func_020276b0();break;
 case 9:func_02027958();break;
 case 12:func_02027a74();break;
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
    if (func_020301dc(func_0202f48c(1) + 0xA) == 1) {
        return 0x12;
    }
    return 0x11;
}

