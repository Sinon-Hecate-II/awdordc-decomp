/* 47 functions from 0x01FF9ED0 to 0x01FFADA0 (itcm), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
void func_01ff9ed0(void){
s32 func_01ff9c34(u8,s32);void func_02007ef4(void*,s32,s32);void func_01ff9eac(void*,s32,s32,s32);
extern s32 gCur3DSpriteEngine;extern s32 data_027e00c8,data_027e00c4;extern u16 *data_027e00bc;
s32 saved=gCur3DSpriteEngine,i=0,j,base,size,dest;void *p;u8 same; s32 flag;
do{
p=(void*)(i==0?data_027e00c8:data_027e00c4);
same=(s32)p==data_027e00c8;gCur3DSpriteEngine=(s32)p;
if(same==1)base=0x6000000;else base=0x6200000;
for(j=0;j<4;j++){
p=(void*)gCur3DSpriteEngine;
if((M2C_FIELD(p,u8*,0x46)&(1<<j)) && !(M2C_FIELD(p,u8*,0x47)&(1<<j))){
flag=(s32)p==data_027e00c8;
size=func_01ff9c34((u8)((u32)(*M2C_FIELD(p,u16**,0)<<29)>>29),(u8)j);
if((u8)flag)dest=((u32)(data_027e00bc[1]<<29)>>29)<<16;else dest=0;
p=(void*)gCur3DSpriteEngine;
func_02007ef4(M2C_FIELD((u8*)p+j*4,void**,0x20),base+dest+(((u32)(M2C_FIELD(*M2C_FIELD(p,u8**,0)+j*2,u16*,6)<<19)>>27)<<11),size);
}}
p=(void*)gCur3DSpriteEngine;
if((M2C_FIELD(p,u8*,0x46)&16) && !(M2C_FIELD(p,u8*,0x47)&16)){
*M2C_FIELD(p,u16**,0x30)=M2C_FIELD(p,u16*,0x44);
func_01ff9eac(M2C_FIELD((void*)gCur3DSpriteEngine,void**,0x30),(u8)i,0,1024);
}
M2C_FIELD((void*)gCur3DSpriteEngine,u8*,0x47)=0;
p=(void*)gCur3DSpriteEngine;
M2C_FIELD(p,u8*,0x46)=M2C_FIELD(p,u8*,0x47);
i++;
}while(i<2);gCur3DSpriteEngine=saved;
}
#pragma opt_common_subs reset
s32 func_01ffa13c(s32 arg0) {
    extern s32 data_021581ac[];
    return data_021581ac[arg0];
}

u8 func_01ffa14c(u32 arg0) {
    u8 var_r0;

    if (arg0 < 0xBU) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_01ffa160(void *arg0) {
    extern s32 data_01ffa068[];
    s16 *temp_r2;

    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x31) != 0) {
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        return;
    }
    temp_r2 = M2C_FIELD(arg0, s16 **, 8);
    if (((s32 (*)(void *)) data_01ffa068[*temp_r2])(arg0) == 0) {
        return;
    }
    for (;;) {
        if (M2C_FIELD(arg0, s32 *, 4) == 0) {
            return;
        }
        if (M2C_FIELD(arg0, u8 *, 0x31) == 0 && M2C_FIELD(arg0, s32 *, 0x10) == 0) {
            temp_r2 = M2C_FIELD(arg0, s16 **, 8);
            if (((s32 (*)(void *)) data_01ffa068[*temp_r2])(arg0) != 0) {
                continue;
            }
        }
        return;
    }
}

void *func_01ffa1ec(void) {
    extern void **data_021581a8;
    void **var_r3;
    void *temp_r2;
    void *var_r0;

    var_r0 = *data_021581a8;
    if (M2C_FIELD(var_r0, u8 *, 0x30) & 0x20) {
        var_r3 = data_021581a8;
        do {
            var_r3 += 1;
            temp_r2 = *var_r3;
        } while (M2C_FIELD(temp_r2, u8 *, 0x30) & 0x20);
        *data_021581a8 = temp_r2;
        *var_r3 = var_r0;
        var_r0 = *data_021581a8;
    }
    data_021581a8 += 1;
    return var_r0;
}

void func_01ffa244(s32 arg0) {
    extern void **data_021581a8;
    void **var_r2;
    s32 temp_r3;

    data_021581a8 -= 1;
    var_r2 = data_021581a8;
    temp_r3 = (s32) *var_r2;
    if (temp_r3 == arg0) {
        return;
    }
    do {
        var_r2 -= 1;
    } while ((s32) *var_r2 != arg0);
    *var_r2 = (void *) temp_r3;
    *data_021581a8 = (void *) arg0;
}

void func_01ffa284(void *arg0, u32 arg1) {
 extern s32 data_021581ac[];
 void **table=(void **)data_021581ac;
 void *prev=table[arg1];
 if(prev!=NULL) {
 M2C_FIELD(prev,void **,0x20)=arg0;
 M2C_FIELD(arg0,void **,0x24)=table[arg1];
 }
 M2C_FIELD(arg0,u32 *,0x18)=arg1;
 table[arg1]=arg0;
}

void func_01ffa2ac(void *arg0, void *arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x1C);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 0x20) = arg0;
        M2C_FIELD(arg0, void **, 0x24) = (void *) M2C_FIELD(arg1, void **, 0x1C);
    }
    M2C_FIELD(arg1, void **, 0x1C) = arg0;
    M2C_FIELD(arg0, void **, 0x18) = arg1;
}

void func_01ffa2cc(void *p) {
 extern s32 data_021581ac[];
 void *n=M2C_FIELD(p,void **,0x20);
 u32 parent;
 if(n)M2C_FIELD(n,void **,0x24)=M2C_FIELD(p,void **,0x24);
 n=M2C_FIELD(p,void **,0x24);
 if(n)M2C_FIELD(n,void **,0x20)=M2C_FIELD(p,void **,0x20);
 parent=M2C_FIELD(p,u32 *,0x18);
 if(parent>12) {
 if(M2C_FIELD(parent,void **,0x1C)==p)M2C_FIELD(parent,void **,0x1C)=M2C_FIELD(p,void **,0x24);
 } else {
 if(M2C_FIELD(data_021581ac,void **,parent*4)==p)data_021581ac[parent]=M2C_FIELD(p,s32 *,0x24);
 }
 M2C_FIELD(p,s32 *,0x20)=0;
 M2C_FIELD(p,s32 *,0x24)=0;
}

s32 func_01ffa334(s32 a,s32 b,s32 c) {
 void func_01ffa284(void *,u32);
 extern s32 gCur3DSpriteEngine;
 void *p=func_01ffa1ec();
 s32 old;
 M2C_FIELD(p,s32 *,4)=a;
 M2C_FIELD(p,s32 *,8)=a;
 M2C_FIELD(p,s32 *,0xC)=0;
 M2C_FIELD(p,s32 *,0x10)=0;
 M2C_FIELD(p,s32 *,0x14)=0;
 M2C_FIELD(p,s32 *,0x18)=0;
 M2C_FIELD(p,s32 *,0x1C)=0;
 M2C_FIELD(p,s32 *,0x20)=0;
 M2C_FIELD(p,s32 *,0x24)=0;
 M2C_FIELD(p,s32 *,0x28)=c;
 M2C_FIELD(p,u16 *,0x2C)=0;
 M2C_FIELD(p,u16 *,0x2E)=0xFF00;
 M2C_FIELD(p,u8 *,0x31)=0;
 M2C_FIELD(p,u8 *,0x30)=0x18;
 if((u32)b<12)func_01ffa284(p,b);else func_01ffa2ac(p,(void *)b);
 old=gCur3DSpriteEngine;gCur3DSpriteEngine=c;
 func_01ffa160(p);
 gCur3DSpriteEngine=old;
 M2C_FIELD(p,u8 *,0x30)&=~8;
 return (s32)p;
}

void func_01ffa3dc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffa334(M2C_UNK, M2C_UNK, s32);
    extern s32 gCur3DSpriteEngine;
    func_01ffa334(arg0, arg1, gCur3DSpriteEngine);
}

s32 func_01ffa3f4(s32 a,s32 b,s32 c) {
 void *p=(void *)func_01ffa334(a,b,c);
 void *parent;
 if(M2C_FIELD(p,s32 *,4)==0)return 0;
 M2C_FIELD(p,u8 *,0x30)|=4;
 parent=M2C_FIELD(p,void **,0x18);
 M2C_FIELD(parent,u8 *,0x31)++;
 return (s32)p;
}

void func_01ffa42c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffa3f4(M2C_UNK, M2C_UNK, s32);
    extern s32 gCur3DSpriteEngine;
    func_01ffa3f4(arg0, arg1, gCur3DSpriteEngine);
}

void func_01ffa444(s32 a,s32 b) {
 if(b==0)b=7;
 if(b<12)func_01ffa3dc(a,b);else func_01ffa42c(a,b);
}

void func_01ffa468(void *p) {
 void *q=M2C_FIELD(p,void **,0x24);
 if(q)func_01ffa468(q);
 q=M2C_FIELD(p,void **,0x1C);
 if(q)func_01ffa468(q);
 M2C_FIELD(p,u8 *,0x30)|=2;
}

void func_01ffa4a0(void *p) {
 void *q=M2C_FIELD(p,void **,0x24);
 if(q)func_01ffa4a0(q);
 q=M2C_FIELD(p,void **,0x1C);
 if(q)func_01ffa4a0(q);
 if(M2C_FIELD(p,u8 *,0x30)&1)return;
 M2C_FIELD(p,u8 *,0x30)|=1;
 func_01ffa244((s32)p);
}

void func_01ffa4e8(void *p) {
 void *q=M2C_FIELD(p,void **,0x24);
 void (*cb)(void *);
 if(q)func_01ffa4e8(q);
 q=M2C_FIELD(p,void **,0x1C);
 if(q)func_01ffa4e8(q);
 cb=M2C_FIELD(p,void (**)(void *),0xC);
 if(cb)cb(p);
 q=M2C_FIELD(p,void **,0);
 if(q)M2C_FIELD(q,void (**)(void *),0)(p);
 M2C_FIELD(p,s32 *,0)=0;
 M2C_FIELD(p,s32 *,4)=0;
 M2C_FIELD(p,s32 *,8)=0;
 M2C_FIELD(p,s32 *,0x10)=0;
 M2C_FIELD(p,s32 *,0x14)=0;
 if(M2C_FIELD(p,u8 *,0x30)&4) {
 q=M2C_FIELD(p,void **,0x18);
 M2C_FIELD(q,u8 *,0x31)--;
 }
}

#pragma optimization_level 1
void func_01ffa574(void *arg0) { void *p; if((p=arg0)==0)return; if(M2C_FIELD(p,s32 *,4)==0)return; if(M2C_FIELD(p,u8 *,0x30)&2)return; func_01ffa2cc(p);func_01ffa468(p);func_01ffa4e8(p);func_01ffa4a0(p); }
#pragma optimization_level reset
void func_01ffa5b8(void *p) {
    extern u8 data_027e15b8, data_027e15b4;
    extern s32 gCur3DSpriteEngine;
    s32 old;
    void *next;
    if (!p) return;
    M2C_FIELD(p, u8 *, 0x30) |= 0x20;
    next = M2C_FIELD(p, void **, 0x24);
    if (next) func_01ffa5b8(next);
    M2C_FIELD(p, u8 *, 0x30) &= ~0x20;
    if (M2C_FIELD(p, u8 *, 0x31) == 0 && !(M2C_FIELD(p, u8 *, 0x30) & 8)) {
        if (M2C_FIELD(p, u8 *, 0x30) & 16) {
            if (data_027e15b8 && data_027e15b4) goto skip;
            M2C_FIELD(p, u8 *, 0x30) &= ~16;
        }
        old = gCur3DSpriteEngine; gCur3DSpriteEngine = M2C_FIELD(p, s32 *, 0x28);
        M2C_FIELD(p, u8 *, 0x30) &= ~64;
        do {
            if (!M2C_FIELD(p, s32 *, 0x10)) func_01ffa160(p);
            if (M2C_FIELD(p, s32 *, 0x10)) ((void(*)(void *))M2C_FIELD(p, s32 *, 0x10))(p);
        } while (M2C_FIELD(p, u8 *, 0x30) & 64);
        M2C_FIELD(p, u8 *, 0x30) &= ~64;
        gCur3DSpriteEngine = old;
    }
skip:
    if (M2C_FIELD(p, u8 *, 0x30) & 1) return;
    if (M2C_FIELD(p, s32 *, 0x14)) {
        old = gCur3DSpriteEngine; gCur3DSpriteEngine = M2C_FIELD(p, s32 *, 0x28);
        ((void(*)(void *))M2C_FIELD(p, s32 *, 0x14))(p);
        gCur3DSpriteEngine = old;
    }
    if (M2C_FIELD(p, u8 *, 0x30) & 1) return;
    next = M2C_FIELD(p, void **, 0x1c); if (next) func_01ffa5b8(next);
}
#pragma scheduling reset
void func_01ffa6fc(void *arg0) {
    s16 *temp_r2;

    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        return;
    }
    temp_r2 = M2C_FIELD(arg0, s16 **, 8);
    if (temp_r2 == NULL) {
        return;
    }
    if (*temp_r2 == 2) {
        M2C_FIELD(arg0, s16 **, 8) = (s16 *) ((s32) temp_r2 + 8);
    }
}

void func_01ffa730(void *arg0) {
    register s16 *temp_r2;

    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    } else {
        temp_r2 = M2C_FIELD(arg0, s16 **, 8);
        if ((temp_r2 != NULL) && (*temp_r2 == 2)) {
            M2C_FIELD(arg0, s16 **, 8) = (s16 *) ((s32)temp_r2 + 8);
        }
    }
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (M2C_FIELD(arg0, u8 *, 0x30) | 0x40);
}

void *func_01ffa770(s32 arg0) {
 extern void **data_021581a8;
 extern void *data_021581dc[];
 void **p=data_021581dc;
 void *q;
 for(;p<data_021581a8;p++) {
 q=*p;
 if(M2C_FIELD(q,s32 *,4)==arg0)return q;
 }
 return 0;
}

void *func_01ffa7b4(s32 arg0) {
 extern void **data_021581a8;
 extern void *data_021581dc[];
 extern s32 gCur3DSpriteEngine;
 void **p=data_021581dc;
 void *q;
 for(;p<data_021581a8;p++) {
 q=*p;
 if(M2C_FIELD(q,s32 *,0x28)==gCur3DSpriteEngine && M2C_FIELD(q,s32 *,4)==arg0)return q;
 }
 return 0;
}

void *func_01ffa810(s32 a) {
 extern void **data_021581a8;
 extern void *data_021581dc[];
 void **q;void *p;
 if(a==0xFF00)return 0;
 for(q=data_021581dc;q<data_021581a8;q++){
 p=*q;if(M2C_FIELD(p,u16 *,0x2E)==a)return p;
 }
 return 0;
}

void *func_01ffa860(s32 a,s32 b) {
 extern void **data_021581a8;
 extern void *data_021581dc[];
 void **q;void *p;
 if(b==0xFF00)return 0;
 for(q=data_021581dc;q<data_021581a8;q++){
 p=*q;if(M2C_FIELD(p,s32 *,4)==a && M2C_FIELD(p,u16 *,0x2E)==b)return p;
 }
 return 0;
}

void func_01ffa8bc(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x2E) = arg1;
}

void func_01ffa8c4(void *p,s32 value) {
 s16 *q=M2C_FIELD(p,s16 **,4);
 s16 v=*q;
 if(v==0)return;
 do {
 if(v==20 && q[1]==value) {
 M2C_FIELD(p,s16 **,8)=q;M2C_FIELD(p,s32 *,0x10)=0;return;
 }
 q+=4;v=*q;
 }while(v!=0);
}

void func_01ffa904(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}

void func_01ffa918(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
}

void func_01ffa920(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
}

void func_01ffa928(M2C_UNK arg0, M2C_UNK *arg1) {
    extern u8 data_021583e0[];
    u8 *p = data_021583e0;
    s32 i;

    i = 0;
    do {
        if (M2C_FIELD(p, s32 *, 4) == arg0) {
            ((void (*)(void *)) arg1)(p);
        }
        i++;
        p += 0x74;
    } while (i < 0x80);
}

void func_01ffa968(M2C_UNK arg0, M2C_UNK *arg1) {
    extern u8 data_021583e0[];
    extern s32 gCur3DSpriteEngine;
    u8 *p = data_021583e0;
    s32 i;

    i = 0;
    do {
        if (M2C_FIELD(p, s32 *, 4) == arg0 && M2C_FIELD(p, s32 *, 0x28) == gCur3DSpriteEngine) {
            ((void (*)(void *)) arg1)(p);
        }
        i++;
        p += 0x74;
    } while (i < 0x80);
}

void func_01ffa9bc(M2C_UNK arg0) {
    void func_01ffa6fc(void *);
    func_01ffa928(arg0, (M2C_UNK *) &func_01ffa6fc);
}

void func_01ffa9d0(M2C_UNK arg0) {
    void func_01ffa6fc(void *);
    func_01ffa968(arg0, (M2C_UNK *)&func_01ffa6fc);
}

void func_01ffa9e4(M2C_UNK arg0) {
    void func_01ffa574(void *);
    func_01ffa928(arg0, (M2C_UNK *) &func_01ffa574);
}

void func_01ffa9f8(M2C_UNK arg0) {
    void func_01ffa574(void *);
    func_01ffa968(arg0, (M2C_UNK *)&func_01ffa574);
}

void func_01ffaa0c(s32 arg0) {
    extern u8 data_021583e0[];
    u8 *p = data_021583e0;
    s32 i;

    if (arg0 == 0xFF00) {
        return;
    }
    i = 0;
    do {
        if (M2C_FIELD(p, s32 *, 4) != 0 && M2C_FIELD(p, u16 *, 0x2E) == arg0) {
            func_01ffa574(p);
        }
        i++;
        p += 0x74;
    } while (i < 0x80);
}

void func_01ffaa5c(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x31) = (u8) (M2C_FIELD(arg0, u8 *, 0x31) + 1);
}

void func_01ffaa6c(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x31) = (u8) (M2C_FIELD(arg0, u8 *, 0x31) - 1);
}

u32 func_01ffaa7c(void *arg0) {
    u32 var_r0;

    var_r0 = M2C_FIELD(arg0, u32 *, 0x18);
    if (var_r0 <= 0xCU) {
        var_r0 = 0;
    }
    return var_r0;
}

void func_01ffaa8c(void *arg0) {
    u8 temp_r0;
    void *temp_r1;

    if (func_01ffa14c(M2C_FIELD(arg0, void **, 0x18)) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x30);
    if (!(temp_r0 & 4)) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (temp_r0 & ~4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(temp_r1, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x31) - 1);
}

void func_01ffaacc(s32 a,s32 b,s32 c,s32 d,s32 priority){extern s32 gCur3DSpriteEngine;void *p,*q,*next;u8 *base;u32 index;
if(M2C_FIELD(gCur3DSpriteEngine,u8 *,0x49)>=128)return;
base=M2C_FIELD(gCur3DSpriteEngine,u8 *volatile *,4);index=M2C_FIELD(gCur3DSpriteEngine,volatile u8 *,0x49);p=base+index*20;
M2C_FIELD(p,s16 *,8)=0;M2C_FIELD(p,s16 *,10)=0;M2C_FIELD(p,s16 *,12)=a;M2C_FIELD(p,s16 *,14)=b;M2C_FIELD(p,s16 *,16)=c;M2C_FIELD(p,s32 *,4)=d;M2C_FIELD(p,s8 *,19)=priority;
M2C_FIELD(p,u8 *,18)&=~15;M2C_FIELD(p,u8 *,18)&=~240;
if(M2C_FIELD(gCur3DSpriteEngine,void **,8)==0){M2C_FIELD(gCur3DSpriteEngine,void **,8)=p;M2C_FIELD(p,void **,0)=0;}
else{q=M2C_FIELD(gCur3DSpriteEngine,void *volatile *,8);if(M2C_FIELD(q,s8 *,19)>priority){M2C_FIELD(p,void **,0)=q;M2C_FIELD(gCur3DSpriteEngine,void **,8)=p;}else{for(;;){next=M2C_FIELD(q,void **,0);if(!next || M2C_FIELD(next,s8 *,19)>priority){M2C_FIELD(p,void **,0)=next;M2C_FIELD(q,void **,0)=p;break;}q=next;}}}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x49)++;
}

/* Allocates a paired-sprite entry in gCur3DSpriteEngine's array, fills in fields, and inserts it into the priority-ordered list. Returns silently if the 128-entry array is full. */
void func_01ffabac(s32 a, s32 b, s32 c, s32 d, u16 e, s32 f, s32 priority) {
    extern s32 gCur3DSpriteEngine;
    void *p, *q, *next;
    u8 *base;
    u32 index;

    if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49) >= 128) return;

    base = M2C_FIELD(gCur3DSpriteEngine, u8 *volatile *, 4);
    index = M2C_FIELD(gCur3DSpriteEngine, volatile u8 *, 0x49);
    p = base + index * 20;

    M2C_FIELD(p, s16 *, 8) = a;
    M2C_FIELD(p, s16 *, 10) = b;
    M2C_FIELD(p, s16 *, 12) = c;
    M2C_FIELD(p, s16 *, 14) = d;
    M2C_FIELD(p, s16 *, 16) = e;
    M2C_FIELD(p, s32 *, 4) = f;
    M2C_FIELD(p, s8 *, 19) = priority;

    M2C_FIELD(p, u8 *, 18) &= ~15;
    M2C_FIELD(p, u8 *, 18) = (M2C_FIELD(p, u8 *, 18) & ~240) | 16;

    if (M2C_FIELD(gCur3DSpriteEngine, void **, 8) == 0) {
        M2C_FIELD(gCur3DSpriteEngine, void **, 8) = p;
        M2C_FIELD(p, void **, 0) = 0;
    } else {
        q = M2C_FIELD(gCur3DSpriteEngine, void *volatile *, 8);
        if (M2C_FIELD(q, s8 *, 19) > priority) {
            M2C_FIELD(p, void **, 0) = q;
            M2C_FIELD(gCur3DSpriteEngine, void **, 8) = p;
        } else {
            for (;;) {
                next = M2C_FIELD(q, void **, 0);
                if (!next || M2C_FIELD(next, s8 *, 19) > priority) {
                    M2C_FIELD(p, void **, 0) = next;
                    M2C_FIELD(q, void **, 0) = p;
                    break;
                }
                q = next;
            }
        }
    }

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49)++;
}

void func_01ffac9c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void func_01ffaacc(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    s32 temp_r5;

    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_01ffaacc(arg0, arg1, arg2, arg3, arg4);
    gCur3DSpriteEngine = temp_r5;
}

void func_01ffacd4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void func_01ffaacc(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    s32 temp_r5;

    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_01ffaacc(arg0, arg1, arg2, arg3, arg4);
    gCur3DSpriteEngine = temp_r5;
}

void func_01ffad0c(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
void func_01ffaacc(s32,s32,s32,s32,s32);
extern s32 gCur3DSpriteEngine;
void *p=(void *)gCur3DSpriteEngine;
u8 *q=(u8 *)M2C_FIELD(p,volatile s32 *,4)+M2C_FIELD(p,volatile u8 *,0x49)*0x14;
func_01ffaacc(arg0,arg1,arg2,arg3,arg4);
q[0x12]=(q[0x12]&~15)|1;
}

void func_01ffad4c(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,s32 arg5,s32 arg6) {
void func_01ffabac(s32,s32,s32,s32,u16,s32,s32);
extern s32 gCur3DSpriteEngine;
void *p=(void *)gCur3DSpriteEngine;
u8 *q=(u8 *)M2C_FIELD(p,volatile s32 *,4)+M2C_FIELD(p,volatile u8 *,0x49)*0x14;
func_01ffabac(arg0,arg1,arg2,arg3,arg4,arg5,arg6);
q[0x12]=(q[0x12]&~15)|1;
}

