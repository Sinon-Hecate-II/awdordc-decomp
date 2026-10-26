/* 24 functions from 0x020B25B8 to 0x020B34F8 (main), found by ds-decomp. */
#include "common.h"

void func_020b25b8(void){
u8 func_020b2714(void);void func_020b2d5c(void*);
extern u16 **gCur3DSpriteEngine;extern void *data_027e00c8,*data_027e00c4,*data_02128690;extern u8 data_0215c45c[];
void *old,*p;u8 mode;s32 j,i;u8 *q;
if(func_020b2714())return;
old=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
mode=M2C_FIELD(data_02128690,u8*,0x24);
if((mode!=0||p==data_027e00c8)&&(mode!=1||p==data_027e00c4)&&(mode!=3||p==old)){
q=data_0215c45c;
for(j=0;j<85;j++,q+=60){if(q[1])func_020b2d5c(q);}
func_020b1d84();
}
}
gCur3DSpriteEngine=old;
}

void func_020b269c(void) {
    extern void *data_02128690;
    M2C_FIELD(data_02128690, u8 *, 0x26) = (u8) (M2C_FIELD(data_02128690, u8 *, 0x26) + 1);
}

u8 func_020b26b8(void) {
extern void *data_02128690;
return M2C_FIELD(data_02128690,u8 *,0x26)!=0;
}

void func_020b26dc(void) {
extern void *data_02128690;
M2C_FIELD(data_02128690,u8 *,0x26)-=1;
}

void func_020b26f8(void) {
extern void *data_02128690;
M2C_FIELD(data_02128690,u8 *,0x27)+=1;
}

u8 func_020b2714(void) {
extern void *data_02128690;
return M2C_FIELD(data_02128690,u8 *,0x27)!=0;
}

void func_020b2738(void) {
extern void *data_02128690;
M2C_FIELD(data_02128690,u8 *,0x27)-=1;
}

s32 func_020b2754(void *arg0, s32 arg1, s32 arg2) {
    s32 func_020b1b1c(void *, M2C_UNK);
    s16 temp_r1;
    s16 temp_r1_2;

    if (func_020b1b1c(arg0, 0x1000) != 0) {
        return 1;
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x14);
    if ((arg1 < (s32) temp_r1) || ((s32) ((temp_r1 + M2C_FIELD(arg0, s16 *, 0x18)) - 1) < arg1)) {
        return 0;
    }
    temp_r1_2 = M2C_FIELD(arg0, s16 *, 0x16);
    if ((arg2 < (s32) temp_r1_2) || ((s32) ((temp_r1_2 + M2C_FIELD(arg0, s16 *, 0x1A)) - 1) < arg2)) {
        return 0;
    }
    return 1;
}

s32 func_020b27d0(void *p) {
extern void *data_02101e88,*data_02128690;
s32 func_020946d0(void);s32 func_020b1b1c(void *,M2C_UNK);
void func_020b1c90(void *);
u16 x=M2C_FIELD(data_02101e88,u16 *,0);
u16 y=M2C_FIELD(data_02101e88,u16 *,2);
if(func_020946d0())return 0;
if(!M2C_FIELD(data_02101e88,u8 *,0x12))return 0;
if(!func_020b1b1c(p,1))return 0;
if(!func_020b2754(p,x,y))return 0;
if(M2C_FIELD(data_02128690,void **,0xc)==p)return 0;
if(func_020b1b1c(p,0x400))return 0;
func_020b1c90(p);
return 1;
}

void func_020b2d5c(void *arg0) {
M2C_UNK func_01ff883c(u16,u16,u16,s32);
s32 func_01ff8e44(s16,s16);
extern u16 **gCur3DSpriteEngine;
u32 a,b; s16 x,y; s32 flag;
a=M2C_FIELD(arg0,u16 *,0x20); b=M2C_FIELD(arg0,u16 *,0x22);
x=M2C_FIELD(arg0,s16 *,0x18); y=M2C_FIELD(arg0,s16 *,0x1a); flag=0;
if(!func_020b1b1c(arg0,2))return;
if(func_020b1b1c(arg0,0x800))flag=0x400;
func_01ff883c((u16)(M2C_FIELD(arg0,s16 *,0x14)&0x1ff),(u16)((M2C_FIELD(arg0,s16 *,0x16)&0xff)|flag),(u16)((0x3ff&(a>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|((b<<28)>>16)),func_01ff8e44(x,y));
}

void func_020b2e14(void *p) {
void (*cb)(void *)=M2C_FIELD(p,void (**)(void *),0x2c);
if(!cb)return;cb(p);
}

void func_020b2e2c(void) {
s32 func_020b1bb0(void);
extern void *data_02128690;
void *p; void (*cb)(void *);
if(!func_020b1bb0())return;
p=M2C_FIELD(data_02128690,void **,0xc);
cb=M2C_FIELD(p,void (**)(void *),0x30);
if(!cb)return; cb(p);
}

void func_020b2e60(void *p) {
void (*cb)(void *)=M2C_FIELD(p,void (**)(void *),0x34);
if(!cb)return;cb(p);
}

s32 func_020b2e78(s32 x,s32 y,void *p) {
s16 a=M2C_FIELD(p,s16 *,0),b;
if(a<=x && (b=M2C_FIELD(p,s16 *,2))<=y) {
if(a+M2C_FIELD(p,s16 *,4)>=x && b+M2C_FIELD(p,s16 *,6)>=y)return 1;
}
return 0;
}

s16 func_020b316c(void *arg0) {
    s16 temp_r2;
    u8 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u8 *, 7);
    temp_r2 = M2C_FIELD(arg0, s16 *, 0x12);
    if ((s32) temp_r2 < (s32) (0 - temp_r3)) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 + temp_r3);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) > 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    } else if ((s32) temp_r2 < 0) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 + ((s32) temp_r3 >> 2));
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) > 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    } else if ((s32) temp_r2 > (s32) temp_r3) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 - temp_r3);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) < 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    } else if ((s32) temp_r2 > 0) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 - ((s32) temp_r3 >> 2));
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) < 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    }
    return M2C_FIELD(arg0, s16 *, 0x12);
}

u8 func_020b320c(void *p) {
s32 func_0207c8ec(s32);
s32 a=M2C_FIELD(p,u8 *,4);
s16 b=func_0207c8ec(M2C_FIELD(p,u8 *,5)+M2C_FIELD(p,s16 *,0xa)-1);
if(a>=b)a=b;
return M2C_FIELD(p,s16 *,0xc)+(s16)a<b;
}

u8 func_020b325c(void *arg0) {
M2C_UNK func_0207c8ec();
u8 value; s32 step=M2C_FIELD(arg0,volatile u8 *,5);
func_0207c8ec(M2C_FIELD(arg0,s16 *,0xa)+step-1);
if(M2C_FIELD(arg0,s16 *,0xc)>0)value=1;else value=0;
return value;
}

u8 func_020b3290(void *arg0) {
    M2C_UNK func_0207c8ec();
    M2C_UNK func_0208fe30(s32);
    u8 temp_r4;
    s16 temp_r6;
    u8 var_r7;
    s16 temp_r0;
    s16 temp_r1;
    s16 temp_r2;
    s16 temp_r5;
    s16 var_r1;
    s32 temp_r0_2;
    s32 var_r0_2;
    u8 var_r0;

    if (M2C_FIELD(arg0, s16 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        return 0U;
    }
    temp_r4 = M2C_FIELD(arg0, u8 *, 5);
    temp_r6 = M2C_FIELD(arg0, s16 *, 0xA);
    var_r7 = M2C_FIELD(arg0, u8 *, 4);
    temp_r0 = func_0207c8ec((temp_r6 + temp_r4) - 1, temp_r4);
    temp_r2 = temp_r0;
    if ((s32) var_r7 >= (s32) temp_r0) {
        var_r7 = (u8) temp_r2;
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0xC);
    temp_r5 = M2C_FIELD(arg0, s16 *, 0xC);
    if (temp_r2 == (temp_r1 + (s16) var_r7)) {
        return 0U;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (temp_r1 + 1);
    temp_r0_2 = temp_r6 - 1;
    M2C_FIELD(arg0, s16 *, 8) = (s16) (M2C_FIELD(arg0, s16 *, 8) + temp_r4);
    var_r1 = M2C_FIELD(arg0, s16 *, 8);
    if ((s32) var_r1 > temp_r0_2) {
        var_r1 = (s16) temp_r0_2;
    }
    M2C_FIELD(arg0, s16 *, 8) = var_r1;
    if (temp_r5 != M2C_FIELD(arg0, s16 *, 0xC)) {
        func_0208fe30(0x10019);
    }
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((M2C_FIELD(arg0, s16 *, 0xC) - temp_r5) * M2C_FIELD(arg0, u8 *, 7));
    if (M2C_FIELD(arg0, s16 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020b3368(void *arg0) {
M2C_UNK func_0207c8ec();
M2C_UNK func_0208fe30(s32);
s16 current; s32 step; s32 active; s32 old; u8 result; s32 factor, delta;
if(M2C_FIELD(arg0,s16 *,0x12)!=0)active=1;else active=0;
if(active&255)return 0;
step=M2C_FIELD(arg0,u8 *,5);
func_0207c8ec(M2C_FIELD(arg0,s16 *,0xa)+step-1,step);
current=M2C_FIELD(arg0,s16 *,0xc);old=M2C_FIELD(arg0,volatile s16 *,0xc);
if(current==0)return 0;
M2C_FIELD(arg0,s16 *,0xc)=current-1;
M2C_FIELD(arg0,s16 *,8)-=step;
if(old!=M2C_FIELD(arg0,s16 *,0xc))func_0208fe30(0x10019);
delta=M2C_FIELD(arg0,s16 *,0xc); factor=M2C_FIELD(arg0,volatile u8 *,7); delta-=old;
M2C_FIELD(arg0,s16 *,0x12)=delta*factor;
if(M2C_FIELD(arg0,s16 *,0x12)!=0)result=1;else result=0;
return result;
}

u8 func_020b3410(void *p){
M2C_UNK func_0207c8ec(); M2C_UNK func_0208fe30(s32);
s32 step,total,n,i,old,active,delta,factor;s16 limit,count;u8 result;
if(M2C_FIELD(p,s16*,0x12)!=0)active=1;else active=0;
if(active&255)return 0;
step=M2C_FIELD(p,u8*,5);total=M2C_FIELD(p,s16*,0xa);n=M2C_FIELD(p,volatile u8*,4);
limit=(s16)func_0207c8ec(total+step-1,step);
if(n>=limit)n=limit;
count=(s16)n; {
old=M2C_FIELD(p,s16*,0xc);
for(i=0;i<count;i++){
if(limit!=M2C_FIELD(p,volatile s16*,0xc)+count)M2C_FIELD(p,s16*,0xc)=M2C_FIELD(p,volatile s16*,0xc)+1;
if(M2C_FIELD(p,volatile s16*,8)+step<total)M2C_FIELD(p,s16*,8)=M2C_FIELD(p,volatile s16*,8)+step;
}
if(old!=M2C_FIELD(p,s16*,0xc))func_0208fe30(0x10019);
delta=M2C_FIELD(p,s16*,0xc);factor=M2C_FIELD(p,volatile u8*,7);delta-=old;
M2C_FIELD(p,s16*,0x12)=delta*factor;
if(M2C_FIELD(p,s16*,0x12)!=0)result=1;else result=0;
return result;
}
}

