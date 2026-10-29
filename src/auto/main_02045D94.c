/* 23 functions from 0x02045D94 to 0x02046D38 (main), found by ds-decomp. */
#include "common.h"

s32 func_02045d94(void *arg0,u8 *a) { void *func_020467b8(void *); void func_02076710(void *,s32); u16 func_02076838(void *,void *,s32); void func_02046654(s32,s32,s32); void func_02007958(void); M2C_UNK func_02008048(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK data_0213db28,data_0213db34; register s32 b=M2C_FIELD(&data_0213db28,s32 *,8); register s32 i;func_020467b8(arg0);func_02076710(a+512,0xa001);i=0;do {if(!func_020465c4(b,256,(s32)a)){func_02007958();return 0;}func_02008048((s32)&data_0213db34,(M2C_UNK *)(a+240),14);*(u16 *)(a+254)=func_02076838(a+512,a,254);do{func_02046654(b,256,(s32)a);}while(!func_020466d0((s32)a,b,256,(s32)(a+256)));i++;b+=256;}while(i<2);return func_0204671c()!=0; }

s32 func_02045e70(u16 *a) { s32 func_020465c4(s32,s32,M2C_UNK); extern M2C_UNK data_0213db28; if(!func_020465c4(32,32,(s32)a))return 0; M2C_FIELD(&data_0213db28,s32 *,8)=(*a<<3)-1024;return 1; }

s32 func_02045eb4(M2C_UNK arg0) {
    s32 func_020465c4(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213db28;
    if (func_020465c4(M2C_FIELD(&data_0213db28, s32 *, 8), 0x400, arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_02045ee0(s32 arg0,s32 *arg1,s32 arg2) { void func_02046654(s32,s32,s32); extern M2C_UNK data_0213db28; register s32 a=arg0; register s32 i=0; register s32 b=M2C_FIELD(&data_0213db28,s32 *,8); do {if(arg1[i]) {do {func_02046654(b,256,a);}while(!func_020466d0(a,b,256,arg2));} i++;a+=256;b+=256;}while(i<4);return func_0204671c()!=0; }

#pragma opt_strength_reduction off
s32 func_02045f68(u8 *arg0) {
u16 func_02076838(void *,void *,s32); void func_02046654(s32,s32,s32); extern M2C_UNK data_0213db28;
register u8 *a=arg0; register s32 i=0; register s32 b=M2C_FIELD(&data_0213db28,s32 *,8);
do { *(u16 *)(arg0+(i<<8)+254)=func_02076838(arg0+0x500,a,254);
do {func_02046654(b,256,(s32)a);}while(!func_020466d0((s32)a,b,256,(s32)(arg0+0x400)));
i++;a+=256;b+=256;}while(i<4); return func_0204671c()!=0;
}
#pragma opt_strength_reduction reset
void func_02045ffc(M2C_UNK a) { M2C_UNK func_02008048(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK data_0213db34; func_02008048(a,&data_0213db34,14); }

u8 func_02046014(u8 *a) { s32 c,i,j,x; i=0; c=0; do {x=a[i];j=i-i;do{if((x>>j)&1)c++;j++;}while(j<8);i++;}while(i<4);return c; }

#pragma opt_common_subs off
M2C_UNK func_02046058(u8 arg0, M2C_UNK *arg1) { u8 *dst=(u8*)arg1; u32 bits=~0U; s32 i=0; s32 shift=0; bits ^= bits >> arg0; do { dst[i]=bits>>(24-shift); ++i; shift+=8; } while(i<4); }
#pragma opt_common_subs reset
s32 func_02046088(void *a) { u8 *p=a; s32 i=0;do {if(p[i])return 1;i++;}while(i<32);return 0; }

s32 func_020460b0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008048(M2C_UNK, s32 *, M2C_UNK);
    s32 sp4;
    s32 sp0;

    if (func_0204612c() == 0) {
        return 0;
    }
    func_02008048(arg0, &sp4, 4);
    func_02008048(arg1, &sp0, 4);
    if ((sp4 | sp0) == -2) {
        return 0;
    }
    if (sp4 & ~sp0) {
        return 1;
    }
    return 0;
}

s32 func_0204612c(u8 *arg0) {
    u8 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 == 0x7F) {
        return 0;
    }
    if ((u32) temp_r0 < 1U) {
        return 0;
    }
    if ((u32) temp_r0 <= 0xDFU) {
        return 1;
    }
    return 0;
}

s32 func_020465c4(s32 arg0,s32 arg1,M2C_UNK arg2) { M2C_UNK func_020067a8(M2C_UNK,...); s32 func_02009e8c(s32,s32); M2C_UNK func_02009e40(s32,M2C_UNK *); s32 func_02046158(s32,s32,s32,s32); M2C_UNK WaitByLoop(s32); extern M2C_UNK func_02046788; register u16 len; register s32 one; func_020067a8(arg2); do {}while(!func_02009e8c(4,1));func_02009e40(4,&func_02046788); len=arg1;one=1; loop: if(func_02046158(one,arg0,len,arg2)!=1) {WaitByLoop(0x40000);goto loop;}func_020067a8(arg2,arg1);return 1; }

void func_02046654(s32 a,s32 b,s32 c) { s32 func_02009e8c(s32,s32); M2C_UNK func_02009e40(s32,M2C_UNK *); M2C_UNK func_020067c4(s32,s32); s32 func_02046158(s32,s32,s32,s32); M2C_UNK WaitByLoop(s32); extern M2C_UNK func_02046788; do {}while(!func_02009e8c(4,1));func_02009e40(4,(M2C_UNK *)&func_02046788);func_020067c4(c,b);loop: if(func_02046158(2,a,b,c)!=1){WaitByLoop(0x40000);goto loop;} }

s32 func_020466d0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 func_0206527c(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_020465c4(arg1, arg2, arg3) == 0) {
        return 0;
    }
    if (func_0206527c(arg0, arg3, arg2) == 0) {
        return 1;
    }
    return 0;
}

s32 func_0204671c(void) {
    M2C_UNK WaitByLoop(M2C_UNK);
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK, M2C_UNK);
    s32 func_02046158(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_02046788;
    do {

    } while (func_02009e8c(4, 1) == 0);
    func_02009e40(4, &func_02046788);
loop_3:
    if (func_02046158(7, 0, 0, 0) != 1) {
        WaitByLoop(0x40000);
        goto loop_3;
    }
    return 1;
}

s32 func_02046788(s32 a,s32 b,s32 c) { extern M2C_UNK data_0213db28; M2C_FIELD(&data_0213db28,u16 *,0)=(u8)b;M2C_FIELD(&data_0213db28,s32 *,4)=1;if(c)M2C_FIELD(&data_0213db28,u16 *,0)=255;return M2C_FIELD(&data_0213db28,u16 *,0); }

void *func_020467b8(void *a) { M2C_UNK func_02008048(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK data_0213db34,data_0213db3a,data_0213db40; u32 low,lo,hi,z; u64 x,y; lo=M2C_FIELD(a,u32 *,8);hi=M2C_FIELD(a,u32 *,12);((u32 *)&x)[1]=hi;((u32 *)&x)[0]=lo;func_02008048((s32)a,&data_0213db34,5);low=(u32)x;hi=(u32)(x>>32);y=x>>5;z=(M2C_FIELD(a,u32 *,4)>>8)&7; M2C_FIELD(&data_0213db34,u8 *,5)=z|((u32)(x&31)<<3);x=y;func_02008048((s32)&x,&data_0213db3a,4);M2C_FIELD(&data_0213db34,u8 *,10)=((x>>32)&63)|((M2C_FIELD(a,u16 *,16)&3)<<6);M2C_FIELD(&data_0213db34,u8 *,11)=M2C_FIELD(a,u16 *,16)>>2;func_02008048((s32)a+18,&data_0213db40,2);return &data_0213db34; }

M2C_UNK *func_02046878(void) {
    extern M2C_UNK data_0213db34;
    return &data_0213db34;
}

s32 func_02046884(void *arg0) {
    void func_02046d0c(s32, s32);
    void func_02007df8(s32, s32, s32);
    s32 func_02008048(M2C_UNK, M2C_UNK *, M2C_UNK);

    s32 stk[4];
    void *r8 = arg0;
    u8 *r6;
    u8 *r7;
    s32 r5;
    s32 r4 = 0;
    s32 r10 = 1;
    s32 tmp;

    func_02007f8c(r8, 0, 0x700);
    if (func_02045e70(r8) == 0) {
        return 0xffffd8ef;
    }
    func_02076710((u8 *)r8 + 0x500, 0xA001);
    if (func_02045eb4(r8) == 0) {
        return 0xffffd8ef;
    }

    func_02007f8c(stk, 0, 16);

    r6 = (u8 *)r8;
    r7 = (u8 *)r8;
    r5 = 0;
    while (r5 < 3) {
        tmp = func_02076838((u8 *)r8 + 0x500, r6, 0xFE);
        {
            s32 v = *(u16 *)((u8 *)r8 + (r5 << 8) + 0xFE);
            if (tmp == v) {
                if (func_02046b8c(r7) != 0) {
                    stk[r5] = r10;
                }
            }
        }
        r5++;
        if (r5 >= 3) break;
        r6 += 0x100;
        r7 += 0x100;
    }

    tmp = func_02076838((u8 *)r8 + 0x500, (u8 *)r8 + 0x300, 0xFE);
    {
        s32 v = *(u16 *)((u8 *)r8 + 0x300 + 0xFE);
        if (tmp == v) {
            stk[3] = 1;
        }
    }

    if (stk[0] && stk[1] && stk[2] && stk[3]) {
        func_02045ffc((u8 *)r8 + 0xF0);
        return 0;
    }

    if (stk[0] == 0 && stk[1] == 0 && stk[2] == 0 && stk[3] == 0) {
        func_02046c8c((s32)r8);
        if (func_02045f68((u8 *)r8) == 0) {
            return 0xffffd8f0;
        }
        return 0;
    }

    if (!(stk[0] == 0 && stk[1] == 0)) {
        goto Lc98;
    }
    if (stk[2] == 0 && stk[3] == 0) {
        func_02046c8c((s32)r8);
        if (func_02045f68((u8 *)r8) == 0) {
            return 0xffffd8f0;
        }
        return 0;
    }

 Lc98:
    if (stk[0] == 0 && stk[1] == 0) {
        func_02046c8c((s32)r8);
        if (func_02045f68((u8 *)r8) != 0) {
            return 0xffffd8ed;
        }
        return 0xffffd8f0;
    }

    if (stk[0] == 0) {
        func_02046d0c((s32)r8, 0);
        func_02008048((u8 *)r8 + 0x1F0, (u8 *)r8 + 0xF0, 0xE);
        {
            u8 b = *((u8 *)r8 + 0x1EF);
            *((u8 *)r8 + 0xEF) = b;
        }
    } else {
        if (stk[1] == 0) {
            func_02046d0c((s32)r8, 1);
            func_02008048((u8 *)r8 + 0xF0, (u8 *)r8 + 0x1F0, 0xE);
            {
                u8 b = *((u8 *)r8 + 0xEF);
                *((u8 *)r8 + 0x1EF) = b;
            }
        }
    }
    func_02045ffc((u8 *)r8 + 0xF0);
    if (stk[2] == 0) {
        func_02046d0c((s32)r8, 2);
    }
    if (stk[3] == 0) {
        func_02007df8((s32)((u8 *)r8 + 0x300), 0, 0x100);
    }

    {
        s32 r5b = 0;
        while (r5b < 3) {
            if (stk[r5b] == 0) {
                u8 b = *((u8 *)r8 + 0xEF);
                if ((b & (1 << r5b)) != 0) {
                    u8 nb = (u8)(b & ~(1 << r5b));
                    *((u8 *)r8 + 0xEF) = nb;
                    *((u8 *)r8 + 0x1EF) = (u8)(nb & 0xFF);
                    r4 = 1;
                }
            }
            r5b++;
        }
    }

    if (func_02045f68((u8 *)r8) == 0) {
        return 0xffffd8f0;
    }
    if (r4 != 0) {
        return 0xffffd8ee;
    }
    return 0;
}

/* Validate an object's slots and resource references; returns 0 on failure. */
s32 func_02046b8c(void *obj) {
    M2C_UNK func_02046058(u8, M2C_UNK *);
    s32 func_02046088(void *);
    extern M2C_UNK data_020ea940;
    M2C_UNK sp0;
    u8 slot;
    u8 temp_r0_2;

    slot = M2C_FIELD(obj, u8 *, 0xE7);
    if (slot == 0xFF) {
        return 1;
    }
    if ((u32) slot > 2U) {
        return 0;
    }
    if (func_02046088(obj + 0x40) == 0) {
        return 0;
    }
    if (func_0206527c(obj + 0xC0, &data_020ea940, 4) != 0) {
        if (func_0204612c(obj + 0xC4) == 0) {
            return 0;
        }
        temp_r0_2 = M2C_FIELD(obj, u8 *, 0xD0);
        if ((u32) temp_r0_2 > 0x20U) {
            return 0;
        }
        func_02046058(temp_r0_2, &sp0);
        if (func_020460b0(obj + 0xC0, &sp0) == 0) {
            return 0;
        }
        goto block_13;
    }
block_13:
    if ((func_0206527c(obj + 0xC8, &data_020ea940, 4) != 0) && (func_0204612c(obj + 0xC8) == 0) && (func_0204612c(obj + 0xCC) == 0)) {
        return 0;
    }
    return 1;
}

s32 func_02046c8c(s32 a) { void func_02007df8(s32,s32,s32); void func_02046ebc(void *); M2C_UNK func_02008048(M2C_UNK,M2C_UNK *,M2C_UNK); u8 sp0[20];s32 i;void *p;register u8 *q;register u32 fill=255;func_02007df8(0,a,1024);i=0;do{q=(u8 *)(a+((u32)i<<8));M2C_FIELD(q,u8 *,0xe7)=fill;i++;}while(i<3);func_02046ebc(sp0);p=func_020467b8(sp0);i=0;do{func_02008048((s32)p,(M2C_UNK *)(a+240),14);i++;a+=256;}while(i<2);return 0;}

#pragma opt_common_subs off
void func_02046d0c(s32 a,s32 b) { void func_02007df8(s32,s32,s32); func_02007df8(0,a+(b<<8),256); M2C_FIELD(a+(b<<8),u8 *,0xe7)=255; }
#pragma opt_common_subs reset
