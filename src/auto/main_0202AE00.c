/* 36 functions from 0x0202AE00 to 0x0202BD7C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 words[2]; } Unk02BDFileRange;
extern s32 data_0213bbd4[];
extern s32 data_0213bb94[16];
void func_0202b8e0(void *);

void func_0202ae00(void){
extern M2C_UNK data_0213b2b8,data_0213b2ac,data_0213b2c4,data_0213b704;void func_02029c30();void func_02029c74();
u8 *q; s32 j; s32 i;u8 *p; s32 zero=0;
func_02029c30(&data_0213b2b8,20);func_02029c30(&data_0213b2ac,20);
for(i=0,p=(u8 *)&data_0213b2c4;i<16;i++,p+=68){p[44]=0;p[60]=i;func_02029c74(&data_0213b2ac,p);}
for(j=0,q=(u8 *)&data_0213b704;j<32;j++,q+=36){func_02029c30(q,12);func_02029c30(q+12,0);q[32]=127;M2C_FIELD(q,s32 *,24)=1;M2C_FIELD(q,s32 *,28)=0;}
}

void func_0202aeb4(void) {
    s32 func_02009800(void);
    void *func_02029ddc(void *, s32);
    s32 func_02009524(void *);
    M2C_UNK func_02008c38(u8, s32);
    void func_02008c18(u8);
    M2C_UNK func_0202b338(void *);
    void func_0202ef34(void *);
    s32 func_0202ef00(void *);
    s32 func_0202ef4c(void *);
    void func_0202b298(void *);
    extern M2C_UNK data_0213b2b8;
    extern s16 data_020e9ca0[];
    s32 r11;
    void *r6;
    void *r7;
    s32 r4;
    r11 = func_02009800();
    r6 = func_02029ddc(&data_0213b2b8, 0);
    if (r6 == 0) {
        return;
    }
    r4 = -0x8000;
    do {
        r7 = func_02029ddc(&data_0213b2b8, r6);
        if (*(u8 *)((u8 *)r6 + 0x2D) == 0) {
            if (func_02009524(*(void **)((u8 *)r6 + 0x30))) {
                *(u8 *)((u8 *)r6 + 0x2D) = 1;
            }
            if (*(u8 *)((u8 *)r6 + 0x2D) == 0) {
                goto tail;
            }
            if (r11 & (1 << *(u8 *)((u8 *)r6 + 0x3C))) {
                goto tail;
            }
            func_0202b338(r6);
            goto next;
        }
        func_0202ef34((u8 *)r6 + 0x1C);
        {
            void *four = *(void **)((u8 *)r6 + 0x04);
            u8 v41 = *(u8 *)((u8 *)r6 + 0x41);
            u8 fi  = *(u8 *)((u8 *)four + 0x20);
            u8 v40 = *(u8 *)((u8 *)r6 + 0x40);
            s32 r8v = data_020e9ca0[v41];
            s32 r10 = data_020e9ca0[fi];
            s32 r9v = data_020e9ca0[v40];
            s32 ef = func_0202ef00((u8 *)r6 + 0x1C);
            s32 r98 = r9v + r8v;
            s32 r10r = r10 + r98;
            s32 pef = data_020e9ca0[ef >> 8];
            s32 r8final = pef + r10r;
            if (r8final < r4) {
                r8final = r4;
            } else if (r8final > 0x7FFF) {
                r8final = 0x7FFF;
            }
            if (r8final != *(s16 *)((u8 *)r6 + 0x3E)) {
                func_02008c38(*(u8 *)((u8 *)r6 + 0x3C), r8final);
                *(s16 *)((u8 *)r6 + 0x3E) = (s16) r8final;
            }
        }
        if (*(u8 *)((u8 *)r6 + 0x2C) == 2) {
            if (func_0202ef4c((u8 *)r6 + 0x1C)) {
                func_0202b298(r6);
            }
        }
    tail:
        if (*(u8 *)((u8 *)r6 + 0x2F)) {
            func_02008c18(*(u8 *)((u8 *)r6 + 0x3C));
            *(u8 *)((u8 *)r6 + 0x2F) = 0;
        }
    next:
        r6 = r7;
    } while (r7 != 0);
}

void *func_0202b018(void *a,s32 b,s32 c){
extern M2C_UNK data_0213b704;void *func_02029ddc();void *func_0202b2d0();void func_0202acbc();
void func_0202b298(void *);M2C_UNK func_0202b1f4(M2C_UNK *,void *);void *old=M2C_FIELD(a,void **,0);void *p=(u8 *)&data_0213b704+b*36;void *q;
if(old)func_0202acbc(a);
if(M2C_FIELD(p,u16 *,8)>=M2C_FIELD(p,u32 *,24)){q=func_02029ddc(p,0);if(!q)return 0;if(c<M2C_FIELD(q,u8 *,61))return 0;func_0202b298(q);}
q=func_0202b2d0(c);if(!q)return 0;func_0202b1f4(p,q);M2C_FIELD(q,void **,0)=a;M2C_FIELD(a,void **,0)=q;return q;
}

void func_0202b0b0(void) {
    M2C_UNK func_0202b338();
    func_0202b338();
}

void func_0202b0bc(void *a){
void func_0202b1ac(void *);void func_02008bf0();void func_02008ca0();s32 func_020094f8();void *p=M2C_FIELD(a,void **,4);
func_02008bf0(M2C_FIELD(a,u8 *,60));if(M2C_FIELD(p,s32 *,28))func_02008ca0(M2C_FIELD(a,u8 *,60),65535,M2C_FIELD(p,s32 *,28));
func_0202b1ac(a);M2C_FIELD(a,s32 *,48)=func_020094f8();M2C_FIELD(a,u8 *,47)=1;M2C_FIELD(a,u8 *,44)=1;
}

void func_0202b10c(void *a,s32 b){void func_0202b298(void *);M2C_UNK func_0202eed8(void *,M2C_UNK,M2C_UNK);void func_0202b40c(void *,s8);if(!a||!M2C_FIELD(a,u8 *,44))return;if(!b){func_0202b298(a);return;}func_0202eed8(a+28,0,b);func_0202b40c(a,0);M2C_FIELD(a,u8 *,44)=2;}

void *func_0202b158(s32 a,void *b){extern M2C_UNK data_0213b704;void *func_02029ddc();M2C_UNK func_02029d7c();M2C_UNK func_0202c534();void *p=(u8 *)&data_0213b704+a*36;void *q=func_02029ddc(p+12,0);if(!q)return 0;func_02029d7c(p+12,q);M2C_FIELD(q,void **,12)=b;M2C_FIELD(b,void **,8)=q;func_0202c534(M2C_FIELD(q,void **,8));return M2C_FIELD(q,void **,8);}

void func_0202b1ac(void *arg0) {
    M2C_UNK func_0202eec0(void *);
    M2C_UNK func_0202eed8(void *, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s8 *, 0x2E) = 0;
    M2C_FIELD(arg0, s8 *, 0x2D) = 0;
    M2C_FIELD(arg0, s8 *, 0x2F) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s8 *, 0x40) = 0x7F;
    M2C_FIELD(arg0, s8 *, 0x41) = 0x7F;
    func_0202eec0(arg0 + 0x1C);
    func_0202eed8(arg0 + 0x1C, 0x7F00, 1);
}

M2C_UNK func_0202b1f4(M2C_UNK *a,void *b){void *func_02029ddc();M2C_UNK func_02029d18();void *p=func_02029ddc(a,0);while(p){if(M2C_FIELD(b,u8 *,61)<M2C_FIELD(p,u8 *,61))break;p=func_02029ddc(a,p);}func_02029d18(a,p,b);M2C_FIELD(b,void **,4)=a;}

M2C_UNK func_0202b244(void *a){extern M2C_UNK data_0213b2b8;void *func_02029ddc();M2C_UNK func_02029d18();void *p=func_02029ddc(&data_0213b2b8,0);while(p){if(M2C_FIELD(a,u8 *,61)<M2C_FIELD(p,u8 *,61))break;p=func_02029ddc(&data_0213b2b8,p);}func_02029d18(&data_0213b2b8,p,a);}

void func_0202b298(void *arg0) {
    M2C_UNK func_02008bd0(u8);
    M2C_UNK func_02008c38(u8, s32);
    if (M2C_FIELD(arg0, u8 *, 0x2C) == 2) {
        func_02008c38(M2C_FIELD(arg0, u8 *, 0x3C), 0xFFFFFD2D);
    }
    func_02008bd0(M2C_FIELD(arg0, u8 *, 0x3C));
    func_0202b338(arg0);
}

void *func_0202b2d0(s32 a){void *func_02029ddc();M2C_UNK func_02029d7c();M2C_UNK func_0202b244(void *);extern M2C_UNK data_0213b2ac,data_0213b2b8;void *p=func_02029ddc(&data_0213b2ac,0);if(!p){p=func_02029ddc(&data_0213b2b8,0);if(a<M2C_FIELD(p,u8 *,61))return 0;func_0202b298(p);}func_02029d7c(&data_0213b2ac,p);M2C_FIELD(p,u8 *,61)=a;func_0202b244(p);return p;}

M2C_UNK func_0202b338(void *a){M2C_UNK func_02029d7c();void func_02029c74();extern M2C_UNK data_0213b2b8,data_0213b2ac;void *p=M2C_FIELD(a,void **,0);void *list;
if(p){M2C_FIELD(p,s32 *,0)=0;M2C_FIELD(a,s32 *,0)=0;}
list=M2C_FIELD(a,void **,4);func_02029d7c(list,a);M2C_FIELD(a,s32 *,4)=0;
if(M2C_FIELD(a,void **,8)){func_02029c74(list+12,M2C_FIELD(a,void **,8));M2C_FIELD(M2C_FIELD(a,void **,8),s32 *,12)=0;M2C_FIELD(a,s32 *,8)=0;}
func_02029d7c(&data_0213b2b8,a);func_02029c74(&data_0213b2ac,a);M2C_FIELD(a,u8 *,44)=0;
}

void func_0202b3bc(void *arg0) {
    M2C_UNK func_0202c51c();
    extern M2C_UNK data_0213b704;
    void *temp_r1;

    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        return;
    }
    func_0202c51c();
    temp_r1 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = 0;
        return;
    }
    func_02029d7c((M2C_FIELD(arg0, s32 *, 0x10) * 0x24) + (s32) &data_0213b704 + 0xC, arg0);
}

void func_0202b40c(void *arg0, s8 arg1) {
    M2C_UNK func_0202b1f4(M2C_UNK *, void *);
    M2C_UNK func_0202b244(void *);
    extern M2C_UNK data_0213b2b8;
    M2C_UNK *temp_r4;

    temp_r4 = M2C_FIELD(arg0, M2C_UNK **, 4);
    if (temp_r4 != NULL) {
        func_02029d7c(temp_r4, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 4) = NULL;
    }
    func_02029d7c(&data_0213b2b8, arg0);
    M2C_FIELD(arg0, s8 *, 0x3D) = arg1;
    if (temp_r4 != NULL) {
        func_0202b1f4(temp_r4, arg0);
    }
    func_0202b244(arg0);
}

void func_0202b46c(void *a){void func_02029c30();void func_0202b9d0(void *);s32 func_0202ba1c(void *);extern M2C_UNK data_0213bb84,data_0213bb88;
if(!data_0213bb84){func_02029c30(&data_0213bb88,0);data_0213bb84=1;}
M2C_FIELD(a,void (**)(void *),8)=func_0202b9d0;M2C_FIELD(a,void **,12)=a;
M2C_FIELD(a,s32 (**)(void *),20)=func_0202ba1c;M2C_FIELD(a,void **,24)=a;
M2C_FIELD(a,s32 *,68)=0;M2C_FIELD(a,s32 *,72)=0;
M2C_FIELD(a,u32 *,36)&=~1;M2C_FIELD(a,u32 *,36)&=~2;
}

s32 func_0202b4e4(void *a,s32 n,u8 *p){s32 func_0202aa64(s32);s32 bits=0; s32 i;for(i=0;i<n;i++){M2C_FIELD(a+i,u8 *,76)=p[i];bits|=1<<p[i];}if(!func_0202aa64(bits))return 0;M2C_FIELD(a,s32 *,72)=n;M2C_FIELD(a,s32 *,68)=bits;return 1;}

void func_0202b544(void *arg0) {
    M2C_UNK func_0202aaac();
    if (M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        return;
    }
    func_0202aaac();
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
}

s32 func_0202b56c(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    extern M2C_UNK data_0213bb88;
    void func_0202b760(void *);
    s32 func_020722fc(s32, s32);
    s32 func_0202aaf8(void);
    void func_02008e44(s32, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    void func_02008d54(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void func_02029c74(M2C_UNK, void *);
    s32 func_0200751c(void);
    M2C_UNK func_0202b920(M2C_UNK, M2C_UNK);
    M2C_UNK func_02007530(s32);
    void func_0202b910(M2C_UNK);

    s32 local;
    s32 idx;
    s32 key;
    s32 r4 = 0;
    s32 *r5;
    s32 r6 = 0;
    s32 r7;

    if ((M2C_FIELD(a, s32 *, 0x24) << 31) >> 31) {
        func_0202b760(a);
        {
            s32 r2 = M2C_FIELD(a, s32 *, 0x48);
            s32 q = func_020722fc(d, r2 * (f << 5));
            M2C_FIELD(a, s32 *, 0x28) = q * f << 5;
            {
                s32 r0 = M2C_FIELD(a, s32 *, 0x28);
                if (b == 1) {
                    r0 = (s32)((u32)r0 >> 1);
                }
                local = func_020722fc(e * r0, f);
            }
        }
        idx = func_0202aaf8();
        M2C_FIELD(a, s32 *, 0x40) = idx;
        if (idx < 0) {
            return 0;
        }
    }

    if (M2C_FIELD(a, s32 *, 0x48) > 0) {
        u8 *cell;
        r5 = data_0213bbd4;
        r7 = e << 5;
        r4 = r6;
        cell = (u8 *)a + 0x4C;
        for (; r6 < M2C_FIELD(a, s32 *, 0x48); r6++) {
            u8 ch = cell[r6];
            s32 val = M2C_FIELD(a, s32 *, 0x28) * r6 + c;
            r5[ch * 2] = val;
            r5[ch * 2 + 1] = r4;
            func_02008e44(ch, b, val, 1, r4, (u32)M2C_FIELD(a, s32 *, 0x28) >> 2, 0x7F, r4, r7, 0x40);
        }
    }

    func_02008d54(M2C_FIELD(a, s32 *, 0x40), local, local, (M2C_UNK)func_0202b910, (s32)a);
    func_02029c74(&data_0213bb88, a);
    M2C_FIELD(a, s32 *, 0x20) = b;
    M2C_FIELD(a, s32 *, 0x2C) = f;
    M2C_FIELD(a, s32 *, 0x30) = g;
    M2C_FIELD(a, s32 *, 0x34) = h;
    M2C_FIELD(a, s32 *, 0x38) = 0;
    M2C_FIELD(a, s32 *, 0x3C) = 0;
    M2C_FIELD(a, u32 *, 0x24) = (M2C_FIELD(a, u32 *, 0x24) & ~1u) | 1u;

    key = func_0200751c();
    M2C_FIELD(a, s32 *, 0x2C) = 1;
    func_0202b920((M2C_UNK)a, 0);
    M2C_FIELD(a, s32 *, 0x2C) = f;
    func_02007530(key);

    return 1;
}

s32 func_0202b70c(void *arg0) {
    M2C_UNK func_02008cc8(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_0200ee10(void *);
    M2C_UNK func_0200ee28(void *);
    s32 temp_r0;
    s32 temp_r0_2;

    func_02008cc8(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
    temp_r0_2 = (s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F;
    if (temp_r0_2 != 0) {
        return temp_r0_2;
    }
    func_0200ee10(arg0 + 8);
    func_0200ee28(arg0 + 0x14);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x24) | 2;
    M2C_FIELD(arg0, s32 *, 0x24) = temp_r0;
    return temp_r0;
}

void func_0202b760(void *a){void func_0202b86c(void *);if(((s32)(M2C_FIELD(a,u32 *,36)<<31)>>31)==0)return;func_0202b86c(a);}

void func_0202b77c(void *a,s32 b){s32 func_020098d0(s32);s32 ch;s32 r,i;M2C_FIELD(a,s32 *,60)=b;i=0;if(M2C_FIELD(a,s32 *,72)<=0)return;do{ch=M2C_FIELD(a+i,u8 *,76);r=func_020098d0(M2C_FIELD(a,s32 *,60)+data_0213bbd4[ch*2+1]);func_02008dfc(1<<ch,r&255,r>>8);i++;}while(i<M2C_FIELD(a,s32 *,72));}

#pragma scheduling off
void func_0202b7e8(void *a,register s32 b,s32 c){M2C_UNK func_02008dfc(s32,s32,s32);s32 func_020098d0(s32);extern M2C_UNK data_0213bbd8;s32 r;if(b>M2C_FIELD(a,s32 *,72)-1)return;b=M2C_FIELD(a+b,u8 *,76);M2C_FIELD(&data_0213bbd8,s32 *,b*8)=c;r=func_020098d0(M2C_FIELD(a,s32 *,60)+c);func_02008dfc(1<<b,r&255,r>>8);}
#pragma scheduling reset
void func_0202b83c(void *arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02008e24(s32, M2C_UNK);
    if (arg1 > (s32) (M2C_FIELD(arg0, s32 *, 0x48) - 1)) {
        return;
    }
    func_02008e24(1 << M2C_FIELD((arg0 + arg1), u8 *, 0x4C), arg2);
}

void func_0202b86c(void *a){M2C_UNK func_02008cf0(s32,M2C_UNK,s32,M2C_UNK);M2C_UNK func_0200ee40(void *);M2C_UNK func_0200ee58(void *);M2C_UNK func_020092d0(M2C_UNK);M2C_UNK func_0200948c(s32);s32 func_020094f8();s32 r;if(((s32)(M2C_FIELD(a,s32 *,36)<<30)>>31)!=0){func_02008cf0(M2C_FIELD(a,s32 *,68),0,1<<M2C_FIELD(a,s32 *,64),0);func_0200ee40(a+8);func_0200ee58(a+20);M2C_FIELD(a,s32 *,36)&=~2;r=func_020094f8();func_020092d0(1);func_0200948c(r);}func_0202b8e0(a);}

void func_0202b8e0(void *arg0) {
    M2C_UNK func_02029d7c(M2C_UNK *, void *);
    M2C_UNK func_0202ab40(s32);
    extern M2C_UNK data_0213bb88;
    func_0202ab40(M2C_FIELD(arg0, s32 *, 0x40));
    func_02029d7c(&data_0213bb88, arg0);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~1);
}

void func_0202b910(M2C_UNK arg0) {
    M2C_UNK func_0202b920(M2C_UNK, M2C_UNK);
    func_0202b920(arg0, 1);
}

M2C_UNK func_0202b920(M2C_UNK arg0,M2C_UNK b){s32 func_020722fc(s32,s32);void *a=(void *)arg0;s32 size,offset,i,n,v;size=func_020722fc(M2C_FIELD(a,s32 *,40),M2C_FIELD(a,s32 *,44));offset=size*M2C_FIELD(a,s32 *,56);for(i=0;i<M2C_FIELD(a,s32 *,72);i++){v=M2C_FIELD(data_0213bbd4,s32 *,M2C_FIELD(a+i,u8 *,76)*8);v+=offset;data_0213bb94[i]=v;}M2C_FIELD(a,void (**)(s32,s32,s32 *,s32,s32,s32),48)(b,M2C_FIELD(a,s32 *,72),data_0213bb94,size,M2C_FIELD(a,s32 *,32),M2C_FIELD(a,s32 *,52));i=M2C_FIELD(a,s32 *,56)+1;M2C_FIELD(a,s32 *,56)=i;n=M2C_FIELD(a,s32 *,44);if(i>=n){n=0;M2C_FIELD(a,s32 *,56)=n;}return n;}

void func_0202b9d0(void *arg0) {
    M2C_UNK func_02008cf0(s32, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020092d0(M2C_UNK);
    M2C_UNK func_0200948c(s32);
    s32 func_020094f8();
    s32 temp_r4;

    if (((s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F) == 0) {
        return;
    }
    func_02008cf0(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
    temp_r4 = func_020094f8();
    func_020092d0(1);
    func_0200948c(temp_r4);
}

s32 func_0202ba1c(void *arg0) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 temp_r0;
    s32 temp_r6;

    temp_r0 = (s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F;
    if (temp_r0 == 0) {
        return temp_r0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        do {
            temp_r6 = func_0200751c();
            func_0202b920(arg0, 1);
            func_02007530(temp_r6);
        } while (M2C_FIELD(arg0, s32 *, 0x38) != 0);
    }
    return func_02008cc8(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
}

void func_0202ba8c(void) {
    extern M2C_UNK data_0213bc54;
    M2C_FIELD(&data_0213bc54, s32 *, 0) = 0;
    M2C_FIELD(&data_0213bc54, s32 *, 0x48) = 0;
}

void func_0202baa4(void){void func_0202ef34(void *);s32 func_0202ef4c(void *);s32 func_0202ef00(void *);void func_0202bb2c(void);M2C_UNK func_02008dfc();extern M2C_UNK data_0213bc54,data_0213bc9c;void *p=&data_0213bc9c;s32 volume;
if(!M2C_FIELD(&data_0213bc54,s32 *,72))return;if(M2C_FIELD(p,s32 *,4))return;func_0202ef34(p+60);
if(M2C_FIELD(p,s32 *,76)&&func_0202ef4c(p+60)){func_0202bb2c();return;}
volume=func_0202ef00(p+60)>>8;if(volume==M2C_FIELD(p,s32 *,80))return;func_02008dfc(M2C_FIELD(p,s32 *,36),volume,0);M2C_FIELD(p,s32 *,80)=volume;
}

void func_0202bb2c(void) {
extern M2C_UNK data_0213bc54,data_0213bc9c,data_0213bc5c;
s32 func_02006390(); M2C_UNK func_0202aadc(); M2C_UNK func_0202aaac(); M2C_UNK func_0202ab40(s32); M2C_UNK func_02008f10();
s32 func_020094f8(); M2C_UNK func_020092d0(M2C_UNK); M2C_UNK func_0200948c(s32);
void *p=&data_0213bc9c; s32 yes,r;
if(!M2C_FIELD(&data_0213bc54,s32 *,72))return;
yes=M2C_FIELD(p,s32 *,44)>=0;
func_02008cf0(M2C_FIELD(p,s32 *,36),M2C_FIELD(p,s32 *,40),yes?1<<M2C_FIELD(p,s32 *,44):0,0);
if(yes){r=func_020094f8();func_020092d0(1);func_0200948c(r);while(func_02006390(&data_0213bc5c,0,0)){}}
if(M2C_FIELD(p,s32 *,40))func_0202aadc(M2C_FIELD(p,s32 *,40));
if(M2C_FIELD(p,s32 *,32))func_0202aaac(M2C_FIELD(p,s32 *,32));
if(yes)func_0202ab40(M2C_FIELD(p,s32 *,44));
if(M2C_FIELD(p,s32 *,4)==1)func_02008f10(0,0,0,0);
M2C_FIELD(p,s32 *,0)=0;
}

void func_0202bc1c(void){M2C_UNK func_02008cf0(s32,s32,s32,s32);s32 func_020094f8();M2C_UNK func_020092d0(s32);M2C_UNK func_0200948c(s32);extern M2C_UNK data_0213bc54,data_0213bc9c;s32 r;void *p=&data_0213bc9c;s32 channel;if(!M2C_FIELD(&data_0213bc54,s32 *,72))return;channel=M2C_FIELD(p,s32 *,44);func_02008cf0(M2C_FIELD(p,s32 *,36),M2C_FIELD(p,s32 *,40),channel>=0?1<<channel:0,0);r=func_020094f8();func_020092d0(1);func_0200948c(r);}

void func_0202bc7c(void){M2C_UNK func_02007e54(s32,s32,s32);void func_020067e0(s32,s32);M2C_UNK func_02008cc8();extern M2C_UNK data_0213bc54,data_0213bc9c;void *p=&data_0213bc9c;s32 channel; s32 dest,size;
if(!M2C_FIELD(&data_0213bc54,s32 *,72))return;
dest=M2C_FIELD(p,s32 *,12);size=M2C_FIELD(p,s32 *,20);M2C_FIELD(p,s32 *,28)=0;func_02007e54(0,dest,size);func_02007e54(0,M2C_FIELD(p,s32 *,16),M2C_FIELD(p,s32 *,20));
func_020067e0(M2C_FIELD(p,s32 *,12),M2C_FIELD(p,s32 *,20));func_020067e0(M2C_FIELD(p,s32 *,16),M2C_FIELD(p,s32 *,20));
channel=M2C_FIELD(p,s32 *,44);func_02008cc8(M2C_FIELD(p,s32 *,36),M2C_FIELD(p,s32 *,40),channel>=0?1<<channel:0,0);
}

void func_0202bd00(void *a,s32 b,s32 c,s32 d){M2C_UNK func_0200b774(void *);s32 func_0200b95c(void *,s32);s32 func_0200b9e4(void *,Unk02BDFileRange);s32 func_0202bd7c(void *,s32,s32);extern void *data_0213c250;
M2C_FIELD(a,s32 *,140)=0;M2C_FIELD(a,s32 *,132)=0;M2C_FIELD(a,s32 *,136)=0;
if(!func_0200b95c(a+124,b))return;func_0200b774(a+52);
if(!func_0200b9e4(a+52,M2C_FIELD(a,Unk02BDFileRange *,124)))return;M2C_FIELD(a,s32 *,48)=1;
if(func_0202bd7c(a,c,d))data_0213c250=a;
}

