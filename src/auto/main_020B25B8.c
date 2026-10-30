/* 24 functions from 0x020B25B8 to 0x020B34F8 (main), found by ds-decomp. */
#include "common.h"

void func_020b25b8(void){
u8 func_020b2714(void);void func_020b2d5c(void*);
extern u16 **gCur3DSpriteEngine;extern void *data_027e00c8,*data_027e00c4,*data_02128690;extern u8 data_0215c45c[];
void *old,*p;u8 mode;s32 j,i;u8 *q;
if(func_020b2714())return;
old=gCur3DSpriteEngine;
i=0;do{
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
mode=M2C_FIELD(data_02128690,u8*,0x24);
if((mode!=0||p==data_027e00c8)&&(mode!=1||p==data_027e00c4)&&(mode!=3||p==old)){
j=0;q=data_0215c45c;
do{if(q[1])func_020b2d5c(q);j++;q+=60;}while(j<85);
func_020b1d84();
}
i++;}while(i<2);
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

s32 func_020b288c(void *arg0) {
extern void *data_02101e88;
s32 func_020946d0(void);s32 func_020b1b1c(void *,M2C_UNK);
void func_020b1b2c(void *,M2C_UNK);void func_020b1c90(void *);
s32 func_020b1b34(void *);s32 func_020b2754(void *,s32,s32);
s32 x=M2C_FIELD(data_02101e88,u16 *,0),y=M2C_FIELD(data_02101e88,u16 *,2);
s32 w=M2C_FIELD(data_02101e88,u16 *,4),h=M2C_FIELD(data_02101e88,u16 *,6);
s32 d;void (*cb)(void *);
switch(func_020b1b34(arg0)){
case 2:
if(!func_020b2754(arg0,x,y)){func_020b1b2c(arg0,0);break;}
if(M2C_FIELD(data_02101e88,u8 *,0x16))func_020b1b2c(arg0,0);
break;
case 0:
if(M2C_FIELD(data_02101e88,u8 *,0x14)&&func_020b2754(arg0,x,y)==1)func_020b1b2c(arg0,1);
break;
case 1:
if(!func_020b2754(arg0,x,y)){func_020b1b2c(arg0,0);break;}
if(M2C_FIELD(data_02101e88,u8 *,0x16)){
func_020b1b2c(arg0,0);
if(func_020b1b1c(arg0,0x400))return 0;
if(func_020946d0())return 0;
if(func_020b1b1c(arg0,1))func_020b1c90(arg0);
if((d=x-w,d<0?-d:d)>0x10||(d=y-h,d<0?-d:d)>0x10)return 0;
cb=M2C_FIELD(arg0,void (**)(void *),0x2c);
if(cb)cb(arg0);
return 1;
}
if(M2C_FIELD(data_02101e88,u8 *,0x12)&&M2C_FIELD(data_02101e88,u8 *,0x10)==0x14)func_020b1b2c(arg0,2);
break;
}
return 0;
}

void func_020b2a50(void *arg0) {
    s16 func_0207ca38(M2C_UNK, s16, s16, s32, s32);
    M2C_UNK (*temp_r1_2)(void *);
    s16 temp_r0_2;
    s16 temp_r0_3;
    u16 temp_ip;
    u16 temp_ip_2;
    u16 temp_ip_3;
    u16 temp_ip_4;
    u8 temp_r0;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 4);
    switch (temp_r1) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        M2C_FIELD(arg0, u8 *, 4) = 1U;
        M2C_FIELD(arg0, u16 *, 0xE) = 0U;
        if (func_020b1b1c(arg0, 4) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 6) = (s16) (0 - M2C_FIELD(arg0, s16 *, 0x18));
        }
        if (func_020b1b1c(arg0, 8) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 6) = 0x100;
        }
        if (func_020b1b1c(arg0, 0x10) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 8) = (s16) (0 - M2C_FIELD(arg0, s16 *, 0x1A));
        }
        if (func_020b1b1c(arg0, 0x20) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 8) = 0xC0;
        }
        if ((s16) M2C_FIELD(arg0, u16 *, 0xE) == 0) {
            return;
        }
    default:                                        /* switch 1 */
block_23:
        temp_r0 = M2C_FIELD(arg0, u8 *, 4);
        switch (temp_r0) {                          /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            temp_r0_2 = (s16) M2C_FIELD(arg0, u16 *, 0xE);
            if ((s32) temp_r0_2 > 0) {
                M2C_FIELD(arg0, u16 *, 0xE) = (u16) (temp_r0_2 - 1);
            } else {
                M2C_FIELD(arg0, u16 *, 0xE) = 0U;
                M2C_FIELD(arg0, u8 *, 4) = 2U;
            }
            temp_ip = M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 0x14) = func_0207ca38(5, M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg0, s16 *, 0xA), temp_ip - (s16) M2C_FIELD(arg0, u16 *, 0xE), (s32) temp_ip);
            temp_ip_2 = M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 0x16) = func_0207ca38(5, M2C_FIELD(arg0, s16 *, 8), M2C_FIELD(arg0, s16 *, 0xC), temp_ip_2 - (s16) M2C_FIELD(arg0, u16 *, 0xE), (s32) temp_ip_2);
            return;
        case 4:                                     /* switch 2 */
            temp_r0_3 = (s16) M2C_FIELD(arg0, u16 *, 0xE);
            if ((s32) temp_r0_3 <= 0) {
                M2C_FIELD(arg0, u16 *, 0xE) = 0U;
                M2C_FIELD(arg0, u8 *, 4) = 5U;
                temp_r1_2 = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x38);
                if (temp_r1_2 != NULL) {
                    temp_r1_2(arg0);
                }
            } else {
                M2C_FIELD(arg0, u16 *, 0xE) = (u16) (temp_r0_3 - 1);
            }
            temp_ip_3 = M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 0x14) = func_0207ca38(2, M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg0, s16 *, 0xA), temp_ip_3 - (s16) M2C_FIELD(arg0, u16 *, 0xE), (s32) temp_ip_3);
            temp_ip_4 = M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 0x16) = func_0207ca38(2, M2C_FIELD(arg0, s16 *, 8), M2C_FIELD(arg0, s16 *, 0xC), temp_ip_4 - (s16) M2C_FIELD(arg0, u16 *, 0xE), (s32) temp_ip_4);
            return;
        }
        break;
    case 3:                                         /* switch 1 */
        M2C_FIELD(arg0, u8 *, 4) = 4U;
        M2C_FIELD(arg0, u16 *, 0xE) = 0U;
        if (func_020b1b1c(arg0, 0x40) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 6) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
            M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
            M2C_FIELD(arg0, s16 *, 0xA) = (s16) (0 - M2C_FIELD(arg0, s16 *, 0x18));
            M2C_FIELD(arg0, s16 *, 0xC) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
        }
        if (func_020b1b1c(arg0, 0x80) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 6) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
            M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
            M2C_FIELD(arg0, s16 *, 0xA) = 0x100;
            M2C_FIELD(arg0, s16 *, 0xC) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
        }
        if (func_020b1b1c(arg0, 0x100) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 6) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
            M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
            M2C_FIELD(arg0, s16 *, 0xA) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
            M2C_FIELD(arg0, s16 *, 0xC) = (s16) (0 - M2C_FIELD(arg0, s16 *, 0x1A));
        }
        if (func_020b1b1c(arg0, 0x200) != 0) {
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
            M2C_FIELD(arg0, s16 *, 6) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
            M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
            M2C_FIELD(arg0, s16 *, 0xA) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
            M2C_FIELD(arg0, s16 *, 0xC) = 0xC0;
        }
        if ((s16) M2C_FIELD(arg0, u16 *, 0xE) == 0) {
            return;
        }
        goto block_23;
    }
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

void *func_020b2eb8(void *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6) {
void func_02007f8c(void *,s32,u32);
void func_02087d18(void *,s16,s16,u32,u32,u32,u32);
void *func_020e34bc(u32);
extern u32 data_021286a4[];
s32 size,n; u8 y; u8 x; u32 a=arg1,b=arg5,c; void *p;
M2C_FIELD(arg0,void **,0)=data_021286a4;
M2C_FIELD(arg0,u8 *,4)=a;
M2C_FIELD(arg0,u8 *,5)=arg2;
M2C_FIELD(arg0,u8 *,6)=arg3;
M2C_FIELD(arg0,u8 *,7)=arg4;
M2C_FIELD(arg0,s16 *,8)=0;
M2C_FIELD(arg0,s16 *,10)=0;
M2C_FIELD(arg0,s16 *,12)=0;
M2C_FIELD(arg0,s16 *,14)=-32768;
M2C_FIELD(arg0,s16 *,16)=-32768;
n=a*arg2;size=n*12;
M2C_FIELD(arg0,s16 *,18)=0;
M2C_FIELD(arg0,s16 *,20)=b;
M2C_FIELD(arg0,s16 *,22)=arg6;
M2C_FIELD(arg0,u16 *,40)=n;
M2C_FIELD(arg0,u8 *,42)=0;
M2C_FIELD(arg0,u32 *,24)=0;
c=arg6;
M2C_FIELD(arg0,u32 *,28)=0;
M2C_FIELD(arg0,s8 *,32)=-1;
M2C_FIELD(arg0,s8 *,33)=-1;
M2C_FIELD(arg0,s8 *,34)=-1;
M2C_FIELD(arg0,s8 *,35)=-1;
M2C_FIELD(arg0,u8 *,37)=255;
M2C_FIELD(arg0,s8 *,36)=-1;
M2C_FIELD(arg0,u8 *,38)=0;
M2C_FIELD(arg0,u8 *,39)=255;
p=func_020e34bc(size);M2C_FIELD(arg0,void **,44)=p;
func_02007f8c(M2C_FIELD(arg0,void **,44),0,size);
for(y=0;y<a;y=(u8)(y+1))for(x=0;x<arg2;x++)func_02087d18((u8*)arg0+24,(s16)(x*arg3+b),(s16)(y*arg4+c),arg3,arg4,(u16)(x+y*arg2),14);
return arg0;
}

void func_020b3038(void *arg0, s32 arg1) {
    M2C_UNK func_0207c8ec();
    s16 val8;
    u8 step;
    s16 orig_a;
    s32 r8;
    s16 orig_c;
    s16 fres;
    s32 r7, r8c, r8const, r9;
    s16 c, f;
    s16 cur;
    s16 diff;

    val8 = M2C_FIELD(arg0, s16 *, 0x8);
    if (arg1 == val8) {
        return;
    }
    step = M2C_FIELD(arg0, u8 *, 0x5);
    orig_a = M2C_FIELD(arg0, s16 *, 0xA);
    r8 = M2C_FIELD(arg0, u8 *, 0x4);
    orig_c = M2C_FIELD(arg0, s16 *, 0xC);
    fres = (s16) func_0207c8ec(orig_a + step - 1, step);
    if (arg1 < 0) {
        return;
    }
    if (orig_a <= arg1) {
        return;
    }
    if (fres <= r8) {
        r8 = fres;
    }
    if (arg1 < val8) {
        do {
            M2C_FIELD(arg0, s16 *, 0x8) = (s16) (M2C_FIELD(arg0, s16 *, 0x8) - 1);
            c = M2C_FIELD(arg0, s16 *, 0xC);
            f = (s16) func_0207c8ec(M2C_FIELD(arg0, s16 *, 0x8), step);
            diff = (s16) (f - c);
            if (diff < 0) {
                if (c > 0) {
                    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (M2C_FIELD(arg0, s16 *, 0xC) - 1);
                }
            }
        } while (arg1 < M2C_FIELD(arg0, s16 *, 0x8));
    } else {
        r7 = orig_a - 1;
        r8c = r8;
        r8const = r8c - 1;
        r9 = fres - r8c;
        do {
            M2C_FIELD(arg0, s16 *, 0x8) = (s16) (M2C_FIELD(arg0, s16 *, 0x8) + 1);
            cur = M2C_FIELD(arg0, s16 *, 0x8);
            if ((s32) cur > r7) {
                cur = (s16) r7;
            }
            M2C_FIELD(arg0, s16 *, 0x8) = cur;
            c = M2C_FIELD(arg0, s16 *, 0xC);
            f = (s16) func_0207c8ec(cur, step);
            diff = (s16) (f - c);
            if (diff > (s16) r8const) {
                if (c < r9) {
                    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (c + 1);
                }
            }
        } while (M2C_FIELD(arg0, s16 *, 0x8) < arg1);
    }
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((M2C_FIELD(arg0, s16 *, 0xC) - orig_c) * M2C_FIELD(arg0, u8 *, 0x7));
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
s32 step=M2C_FIELD(p,volatile u8 *,5);
s32 a=M2C_FIELD(p,u8 *,4);
s16 b=func_0207c8ec(M2C_FIELD(p,s16 *,0xa)+step-1);
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
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 var_r7;
    s16 temp_r0;
    s16 temp_r1;
    s16 temp_r2;
    s32 var_r1;
    s32 temp_r0_2;
    s32 var_r0_2; s32 delta, factor;
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
        var_r7 = temp_r2;
    }
    temp_r5 = M2C_FIELD(arg0, volatile s16 *, 0xC);
    temp_r1 = M2C_FIELD(arg0, volatile s16 *, 0xC);
    if (temp_r2 == (temp_r1 + (s16) var_r7)) {
        return 0U;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (temp_r1 + 1);
    M2C_FIELD(arg0, s16 *, 8) = (s16) (M2C_FIELD(arg0, s16 *, 8) + temp_r4);
    temp_r0_2 = temp_r6 - 1;
    var_r1 = M2C_FIELD(arg0, s16 *, 8);
    if ((s32) var_r1 > temp_r0_2) {
        var_r1 = temp_r0_2;
    }
    M2C_FIELD(arg0, s16 *, 8) = var_r1;
    if (temp_r5 != M2C_FIELD(arg0, s16 *, 0xC)) {
        func_0208fe30(0x10019);
    }
    delta=M2C_FIELD(arg0,s16 *,0xc);factor=M2C_FIELD(arg0,volatile u8 *,7);delta-=temp_r5;
M2C_FIELD(arg0,s16 *,0x12)=delta*factor;
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

u8 func_020b3410(void *arg0){
M2C_UNK func_0207c8ec(); M2C_UNK func_0208fe30(s32);
s32 old,step,total,n,i,active,delta,factor;s16 limit,count;u8 result;
void *p=arg0;
if(M2C_FIELD(p,s16*,0x12)!=0)active=1;else active=0;
if(active&255)return 0;
step=M2C_FIELD(p,u8*,5);total=M2C_FIELD(p,s16*,0xa);n=M2C_FIELD(p,u8*,4);
limit=(s16)func_0207c8ec(total+step-1,step);
if(n>=limit)n=limit;
count=(s16)n;
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

