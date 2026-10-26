/* 17 functions from 0x020871A8 to 0x02088044 (main), found by ds-decomp. */
#include "common.h"

void func_020871a8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    s32 x, y, z;
    s16 b = (s16) arg1, a = (s16) arg0, e = (s16) (arg1 + arg4), c = (s16) arg2, d = (s16) (arg0 + arg3);

    *(volatile u32 *) 0x4000500 = 1;
    *(volatile u32 *) 0x4000480 = arg5;
    x = (u32) (u16) a | ((u32) (u16) b << 0x10);
    *(volatile u32 *) 0x400048C = x;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    y = (u32) (u16) a | ((u32) (u16) e << 0x10);
    *(volatile u32 *) 0x400048C = y;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    z = (u32) (u16) d | ((u32) (u16) e << 0x10);
    *(volatile u32 *) 0x400048C = z;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    x = (u32) (u16) d | ((u32) (u16) b << 0x10);
    *(volatile u32 *) 0x400048C = x;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    *(volatile u32 *) 0x4000504 = 0;
    *(volatile u32 *) 0x4000480 = 0x7FFF;
}

void func_0208726c(s32 *x,s32 *y,s32 angle,s32 dist) {
 extern s16 data_020e5b30[];
 s32 i=(angle>>4)*2; s32 a,b,d=-dist;
 a=data_020e5b30[i]; b=data_020e5b30[i+1];
 a=-(d*a); b=d*b;
 *x=((a>>11)&1)+(a>>12); *y=((b>>11)&1)+(b>>12);
}

void func_020878c4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
void func_02087b94(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    if (arg9 != 0 && arg10 != 0) {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg7 - 1, arg8 - 1, arg5 - 1, arg6 - 1);
    } else if (arg9 != 0) {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg7 - 1, arg6, arg5 - 1, arg8);
    } else if (arg10 != 0) {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg5, arg8 - 1, arg7, arg6 - 1);
    } else {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    }
}

void func_02087c6c(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,u16 f) {
 s32 x,y,z; s16 b=(s16)arg1,a=(s16)arg0,d=(s16)arg3,e=(s16)arg4,c=(s16)arg2;
 
 *(volatile u32 *)0x4000500=0;
 *(volatile u32 *)0x4000480=f;
 x=(u16)a|((u32)(u16)b<<16); z=(u16)e;
 *(volatile u32 *)0x400048c=x;
 *(volatile u32 *)0x400048c=z;
 y=(u16)c|((u32)(u16)d<<16);
 *(volatile u32 *)0x400048c=y;
 *(volatile u32 *)0x400048c=z;
 *(volatile u32 *)0x400048c=x;
 *(volatile u32 *)0x400048c=z;
 *(volatile u32 *)0x4000504=0;
 *(volatile u32 *)0x4000480=0x7fff;
}

void func_02087d18(void *p,s32 a,s32 b,s32 c,u16 d,u16 e,u16 f) {
 s32 n=M2C_FIELD(p,u16 *,0x10); s32 i; u16 *q=M2C_FIELD(p,u16 **,0x14);
 for(i=0;i<n;i++,q+=6) {
 if(q[5]==0) {
 q[0]=a; q[1]=b; q[2]=c; q[3]=d; q[4]=e; q[5]=f;
 M2C_FIELD(p,u8 *,0x12)++; return;
 }
 }
}

void func_02087d84(void *a,s32 b,s32 c,s32 d,u16 e,u16 f) {void *func_02087e68(void *,s32);u16 *p=func_02087e68(a,(s16)b);p[0]=c;p[1]=d;p[2]=e;p[3]=f;}

void func_02087db8(void *arg0, s32 arg1) {
    s32 var_r2;
    u16 temp_r3;
    void *temp_r0;
    void *var_r0;

    temp_r3 = M2C_FIELD(arg0, u16 *, 0x10);
    var_r0 = M2C_FIELD(arg0, void **, 0x14);
    var_r2 = 0;
    if ((s32) temp_r3 > 0) {
loop_1:
        if (M2C_FIELD(var_r0, u16 *, 8) == arg1) {
            func_02007f8c(var_r0, 0, 0xC);
            M2C_FIELD(arg0, u8 *, 0x12) = (u8) (M2C_FIELD(arg0, u8 *, 0x12) - 1);
        } else {
            var_r2 += 1;
            var_r0 += 0xC;
            if (var_r2 < (s32) temp_r3) {
                goto loop_1;
            }
        }
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0);
    if (temp_r0 == NULL) {
        return;
    }
    if (arg1 == M2C_FIELD(temp_r0, u16 *, 8)) {
        M2C_FIELD(arg0, void **, 0) = NULL;
        M2C_FIELD(arg0, s32 *, 4) = 0;
    }
}

void func_02087e34(void *arg0) {
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    func_02007f8c(M2C_FIELD(arg0, s32 *, 0x14), 0, M2C_FIELD(arg0, u16 *, 0x10) * 0xC);
    M2C_FIELD(arg0, s8 *, 0x12) = 0;
}

void *func_02087e68(void *a,s32 b) {s32 i;u16 n;u8 *p;n=M2C_FIELD(a,u16 *,16);p=M2C_FIELD(a,u8 **,20);for(i=0;i<(s32)n;i++,p+=12)if(M2C_FIELD(p,u16 *,8)==b)return p;return 0;}

void func_02087ea0(void *arg0, void *arg1) {
    void *temp_r3;

    if (!(M2C_FIELD(arg1, u16 *, 0xA) & 4)) {
        return;
    }
    temp_r3 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(arg0, void **, 0) = arg1;
    M2C_FIELD(arg0, void **, 4) = temp_r3;
    M2C_FIELD(arg0, s8 *, 0xF) = 0;
}

void func_02087ec0(void *a, s32 b) {void *func_02087e68(void *,s32); if(b==-1){M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,u8 *,15)=255;return;}func_02087ea0(a,func_02087e68(a,b));}

void func_02087f00(void *p, s32 id) { void func_02087ec0(void *, s32); func_02087ec0(p, id); M2C_FIELD(p,s32 *,4)=M2C_FIELD(p,s32 *,0); M2C_FIELD(p,u8 *,15)=255; }

s32 func_02087f20(s32 a,void *b,s32 c,s32 d) {s32 x=M2C_FIELD(b,s16 *,0);s32 y;if(c<x || x+M2C_FIELD(b,u16 *,4)<=c)return 0;y=M2C_FIELD(b,s16 *,2);if(d<y || y+M2C_FIELD(b,u16 *,6)<=d)return 0;return 1;}

s32 func_02087f70(void *arg0, s32 arg1, s32 arg2) {
    s16 temp_r4;
    s16 temp_r4_2;
    s16 temp_r6;
    void *var_ip;
    s32 var_lr;
    u16 temp_r3;
    u16 temp_r4_3;
    s16 temp_r6_2;

    temp_r4 = M2C_FIELD(arg0, s16 *, 0x18);
    if ((arg1 < temp_r4) || ((s32) (temp_r4 + M2C_FIELD(arg0, u16 *, 0x1C)) <= arg1)) {
        return 0;
    }
    temp_r4_2 = M2C_FIELD(arg0, s16 *, 0x1A);
    if ((arg2 < temp_r4_2) || ((s32) (temp_r4_2 + M2C_FIELD(arg0, u16 *, 0x1E)) <= arg2)) {
        return 0;
    }
    temp_r4_3 = M2C_FIELD(arg0, u16 *, 0x10);
    var_ip = M2C_FIELD(arg0, void **, 0x14);
    var_lr = 0;
    if ((s32) temp_r4_3 > 0) {
loop_7:
        if (M2C_FIELD(var_ip, u16 *, 0xA) != 0) {
            temp_r3 = M2C_FIELD(arg0, u16 *, 0x20);
            temp_r6 = M2C_FIELD(var_ip, s16 *, 0);
            if ((arg1 >= (s32) (temp_r6 - temp_r3)) && ((s32) (temp_r3 + (temp_r6 + M2C_FIELD(var_ip, u16 *, 4))) > arg1)) {
                temp_r6_2 = M2C_FIELD(var_ip, s16 *, 2);
                if ((arg2 >= (s32) (temp_r6_2 - temp_r3)) && ((s32) (temp_r3 + (temp_r6_2 + M2C_FIELD(var_ip, u16 *, 6))) > arg2)) {
                    return 0;
                }
            }
        }
        var_lr += 1;
        var_ip = (void *) ((u8 *) var_ip + 0xC);
        if (var_lr < (s32) temp_r4_3) {
            goto loop_7;
        }
    }
    return 1;
}

