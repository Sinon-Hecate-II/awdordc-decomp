/* 23 functions from 0x02049AB8 to 0x0204AA34 (main), found by ds-decomp. */
#include "common.h"

void func_02049ab8(u8 *src,s8 *dst,s32 len,s32 mode){
void func_02049a20(u8 *,s8 *,s32);
extern const s8 data_020ea970[],data_020ea974[],data_020ea978[];
const s8 *table; s8 *start=dst,*pad; s32 left=len,rem;
switch(mode){case 1:table=data_020ea970;break;case 2:table=data_020ea974;break;default:table=data_020ea978;break;}
while(left>0){func_02049a20(src,dst,left<3?left:3);left-=3;dst+=4;src+=3;}
rem=len%3;pad=dst;
if(rem==1)pad=dst-2;else if(rem==2)pad=dst-1;
*dst=0;
while(dst>start){
--dst;
if(dst>=pad)*dst=table[2];
else if(*dst<=25)*dst+=65;
else if(*dst<=51)*dst+=71;
else if(*dst<=61)*dst-=4;
else if(*dst==62)*dst=table[0];
else if(*dst==63)*dst=table[1];
}
}

s32 func_02049bf0(s32 *p,s32 n) {
s32 func_020377a8(s32,s32);
extern M2C_UNK data_020fcec4,data_020fcecc,data_020fce58,data_020fcedc;
s32 v,total;
if(!p)func_020640a8(&data_020fcec4,&data_020fcecc,&data_020fce58,0x20);
if(n<=0)func_020640a8(&data_020fcedc,&data_020fcecc,&data_020fce58,0x21);
if(!p)return 0;
if(n<=0)return 0;
total=p[2];total+=n;
v=func_020377a8(p[1],total);
if(!v)return 0;
p[1]=v;p[2]=total;return 1;
}

s32 func_02049c7c(void *connection,s32 *buffer,s32 size,s32 grow) {
extern M2C_UNK data_020fcef0,data_020fcecc,data_020fce38,data_020fcec4,data_020fcefc,data_020fcedc;
if(!connection)func_020640a8(&data_020fcef0,&data_020fcecc,&data_020fce38,0x43);
if(!buffer)func_020640a8(&data_020fcec4,&data_020fcecc,&data_020fce38,0x44);
if(size<=0)func_020640a8(&data_020fcefc,&data_020fcecc,&data_020fce38,0x45);
if(grow<=0)func_020640a8(&data_020fcedc,&data_020fcecc,&data_020fce38,0x46);
if(!connection)return 0;
if(!buffer)return 0;
if(size<=0)return 0;
if(grow<=0)return 0;
buffer[0]=(s32)connection;
buffer[1]=0;buffer[2]=0;buffer[3]=0;buffer[4]=0;buffer[5]=grow;buffer[6]=0;buffer[7]=0;buffer[8]=0;
if(!func_02049bf0(buffer,size))return 0;
*(u8*)buffer[1]=0;return 1;
}

/* Initialize a fixed-size buffer wrapper with a connection, user storage and capacity. */
s32 ghiInitFixedBuffer(void *connection, s32 *buffer, void *userBuffer, s32 size) {
    extern M2C_UNK data_020fcef0, data_020fcecc, data_020fce68, data_020fcec4, data_020fcf0c, data_020fcf18;
    if (!connection) func_020640a8(&data_020fcef0, &data_020fcecc, &data_020fce68, 0x74);
    if (!buffer) func_020640a8(&data_020fcec4, &data_020fcecc, &data_020fce68, 0x75);
    if (!userBuffer) func_020640a8(&data_020fcf0c, &data_020fcecc, &data_020fce68, 0x76);
    if (size <= 0) func_020640a8(&data_020fcf18, &data_020fcecc, &data_020fce68, 0x77);
    if (!connection) return 0;
    if (!buffer) return 0;
    if (!userBuffer) return 0;
    if (size <= 0) return 0;
    buffer[0] = (s32)connection;
    buffer[1] = (s32)userBuffer;
    buffer[2] = size;
    buffer[3] = 0;
    buffer[5] = 0;
    buffer[6] = 1;
    buffer[7] = 1;
    buffer[8] = 0;
    *(u8 *)buffer[1] = 0;
    return 1;
}

void func_02049e94(s32 *p) {
void func_020377c4(s32);
extern M2C_UNK data_020fcec4,data_020fcecc,data_020fce28;
if(!p)func_020640a8(&data_020fcec4,&data_020fcecc,&data_020fce28,0x9b);
if(!p || !p[1])return;
if(!p[7])func_020377c4(p[1]);
func_02065210(p,0,0x24);
}

s32 func_02049ef4(s32 arg0, s32 *arg1, s32 n, ...) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    s32 func_02068c34(s32);
    s32 func_02049bf0(s32 *, s32);
    void func_020651a4(void *, void *, s32);
    extern M2C_UNK data_020fcec4;
    extern M2C_UNK data_020fcecc;
    extern M2C_UNK data_020fce94;
    extern M2C_UNK data_020fcf24;
    extern M2C_UNK data_020fcf2c;
    extern M2C_UNK data_020fcf3c;
    void *r9 = (void *)arg0;
    void *r8 = (void *)arg1;
    void *r6 = M2C_FIELD(r9, void **, 0);
    typedef s32 (*Cb)(void *, void *, void *, s32 *, s32, s32 *);

    if (r9 == 0) func_020640a8(&data_020fcec4, &data_020fcecc, &data_020fce94, 0xb7);
    if (r8 == 0) func_020640a8(&data_020fcf24, &data_020fcecc, &data_020fce94, 0xb8);
    if (n < 0) func_020640a8(&data_020fcf2c, &data_020fcecc, &data_020fce94, 0xb9);
    if (r9 == 0) return 0;
    if (r8 == 0) return 0;
    if (n < 0) return 0;

    if (n == 0) {
        n = func_02068c34((s32)r8);
    }

    if (M2C_FIELD(r9, s32 *, 0x20) == 1) {
        s32 r7;
        s32 diff;
        if (M2C_FIELD(r6, s32 *, 0x168) == 0) {
            func_020640a8(&data_020fcf3c, &data_020fcecc, &data_020fce94, 0xce);
        }
        do {
            s32 local0;
            diff = M2C_FIELD(r9, s32 *, 0x8) - M2C_FIELD(r9, s32 *, 0xc);
            local0 = M2C_FIELD(r9, s32 *, 0x4) + M2C_FIELD(r9, s32 *, 0xc);
            {
                Cb cb = *(Cb *)((char *)r6 + 0x17c);
                r7 = cb(r6, (char *)r6 + 0x164, r8, &n, local0, &diff);
            }
            if (r7 == 2) {
            if (M2C_FIELD(r9, s32 *, 0x18) != 0) {
                M2C_FIELD(M2C_FIELD(r9, void **, 0), s32 *, 0xfc) = 1;
                M2C_FIELD(M2C_FIELD(r9, void **, 0), s32 *, 0x38) = 2;
                return 0;
            }
            if (func_02049bf0((s32 *)r9, M2C_FIELD(r9, s32 *, 0x14)) != 0) {
                M2C_FIELD(M2C_FIELD(r9,void **,0), s32 *, 0xfc) = 1;
                M2C_FIELD(M2C_FIELD(r9,void **,0), s32 *, 0x38) = 1;
                return 0;
            }
            continue;
            }
            M2C_FIELD(r9, s32 *, 0xc) += diff;
        } while (r7==2);
    } else

    {
        s32 r4 = M2C_FIELD(r9, s32 *, 0xc) + n;
        s32 limit = M2C_FIELD(r9, s32 *, 0x8);
        while (r4 >= M2C_FIELD(r9,s32 *,8)) {
        if (M2C_FIELD(r9, s32 *, 0x18) != 0) {
            M2C_FIELD(M2C_FIELD(r9, void **, 0), s32 *, 0xfc) = 1;
            M2C_FIELD(M2C_FIELD(r9, void **, 0), s32 *, 0x38) = 2;
            return 0;
        }
        if (func_02049bf0((s32 *)r9, M2C_FIELD(r9, s32 *, 0x14)) == 0) {
            M2C_FIELD(M2C_FIELD(r9, void **, 0), s32 *, 0xfc) = 1;
            M2C_FIELD(M2C_FIELD(r9, void **, 0), s32 *, 0x38) = 1;
            return 0;
        }
        }
        func_020651a4((void *)((char *)M2C_FIELD(r9, void **, 0x4) + M2C_FIELD(r9, s32 *, 0xc)), r8, n);
        M2C_FIELD(r9, s32 *, 0xc) = r4;
        ((s8 *)M2C_FIELD(r9, void **, 0x4))[r4] = 0;
    }
    return 1;
}

s32 func_0204a1b0(M2C_UNK arg0, M2C_UNK *arg1, M2C_UNK *arg2) {
    s32 func_02049ef4(M2C_UNK, M2C_UNK *, M2C_UNK,...);
    extern M2C_UNK data_020fcf78;
    extern M2C_UNK data_020fcf7c;
    if (func_02049ef4(arg0, arg1, 0) == 0) {
        return 0;
    }
    if (func_02049ef4(arg0, &data_020fcf78, 2) == 0) {
        return 0;
    }
    if (func_02049ef4(arg0, arg2, 0) == 0) {
        return 0;
    }
    if (func_02049ef4(arg0, &data_020fcf7c, 2) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0204a230(s32 p,s32 c) {
s32 func_02049ef4(s32,s32 *,s32,...);
extern M2C_UNK data_020fcec4,data_020fcecc,data_020fce7c;
u8 v=c;
if(!p)func_020640a8(&data_020fcec4,&data_020fcecc,&data_020fce7c,0x131);
if(!p)return 0;
return func_02049ef4(p,(s32 *)&v,1);
}

void func_0204a290(s32 a,s32 b) {
void func_020675e4(void *,void *,s32);
s32 func_02049ef4(s32,s32 *,s32,...);
extern M2C_UNK data_020fcf80;
s32 buf[4];
func_020675e4(buf,&data_020fcf80,b);
func_02049ef4(a,buf,0);
}

void func_0204a2c8(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fce48;
    extern M2C_UNK data_020fcec4;
    extern M2C_UNK data_020fcecc;
    if (arg0 == NULL) {
        func_020640a8(&data_020fcec4, &data_020fcecc, &data_020fce48, 0x16C);
    }
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    *M2C_FIELD(arg0, s8 **, 4) = 0;
}

s32 func_0204a30c(void *arg0) {
    s32 PollOneFd(s32, M2C_UNK, s32 *, s32 *);
    s32 sp4;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r1;
    s32 temp_r3;

loop_1:
    if ((PollOneFd(M2C_FIELD(arg0, s32 *, 0x48), 0, &sp4, &sp0) == -1) || (sp0 != 0)) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 5;
        M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
        return 0;
    }
    if (sp4 == 0) {
        return 1;
    }
    temp_r3 = M2C_FIELD(arg0, s32 *, 0x60);
    temp_r0 = func_0204a954(arg0, M2C_FIELD(arg0, s32 *, 0x54) + temp_r3, M2C_FIELD(arg0, s32 *, 0x5C) - temp_r3);
    if (temp_r0 == -1) {
        return 0;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x60) + temp_r0;
    M2C_FIELD(arg0, s32 *, 0x60) = temp_r1;
    if (temp_r1 >= (s32) M2C_FIELD(arg0, s32 *, 0x5C)) {
        return 1;
    }
    goto loop_1;
}

s32 func_0204a3dc(s32 *p,u8 *dst,s32 *len) {
extern M2C_UNK data_020fcf84,data_020fcecc,data_020fceac,data_020fcf98;
s32 n,left;
if(!p)func_020640a8(&data_020fcf84,&data_020fcecc,&data_020fceac,0x1b7);
if(!len)func_020640a8(&data_020fcf98,&data_020fcecc,&data_020fceac,0x1b8);
n=*len;
if(!n)return 0;
left=p[3]-p[4];
if(left<=0)return 0;
if(n>=left)n=left;
func_020651a4(dst,(void *)(p[1]+p[4]),n);
dst[n]=0;*len=n;p[4]+=n;return 1;
}

void func_0204a498(void *p) {
extern M2C_UNK data_020fcfec,data_020fcff8,data_020fcfd0;
s32 a,b,r;
if(!p)func_020640a8(&data_020fcfec,&data_020fcff8,&data_020fcfd0,0x1b);
if(!M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32),0x40))return;
if(M2C_FIELD(p,s32 *,12)){a=0;b=0;}else{a=M2C_FIELD(p,s32 *,0xc0);b=M2C_FIELD(p,s32 *,0x100);}
r=M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32),0x40)(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,0x38),a,b,M2C_FIELD(p,s32 *,0x44));
if(a && !r)M2C_FIELD(p,s32 *,0xd8)=1;
}

void func_0204a518(void *p,s32 a,s32 b) {
extern M2C_UNK data_020fcfec,data_020fcff8,data_020fcfb8;
if(!p)func_020640a8(&data_020fcfec,&data_020fcff8,&data_020fcfb8,0x45);
if(!M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32,s32,s32),0x3c))return;
M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32,s32,s32),0x3c)(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,0x10),a,b,M2C_FIELD(p,s32 *,0x100),M2C_FIELD(p,s32 *,0x104),M2C_FIELD(p,s32 *,0x44));
}

void func_0204a594(void *arg0) {
    s32 func_02048688(s32);
    extern M2C_UNK data_020fcfa4;
    extern M2C_UNK data_020fcfec;
    extern M2C_UNK data_020fcff8;
    if (arg0 == NULL) {
        func_020640a8(&data_020fcfec, &data_020fcff8, &data_020fcfa4, 0x5E);
    }
    if (M2C_FIELD(arg0, M2C_UNK (**)(s32, s32, s32, s32, s32, s32), 0x150) == NULL) {
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(s32, s32, s32, s32, s32, s32), 0x150)(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x14C), M2C_FIELD(arg0, s32 *, 0x144), func_02048688(M2C_FIELD(arg0, s32 *, 0x140)), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_0204a608(void) {

}

void func_0204a60c(void) {

}

void func_0204a610(void) {

}

void func_0204a614(void) {

}

s32 func_0204a618(void *arg0) {
M2C_UNK func_020651c4(s32,s32,s32);
s32 spC; s32 sp8; s32 ip,r3,result,left,used,p,inPtr,outPtr;
spC=0;sp8=0;
loop:
ip=M2C_FIELD(arg0,s32 *,0xa8);
inPtr=M2C_FIELD(arg0,s32 *,0x9c);
spC=M2C_FIELD(arg0,s32 *,0xa4)-ip;
r3=M2C_FIELD(arg0,s32 *,0x80);
outPtr=M2C_FIELD(arg0,s32 *,0x78);
sp8=M2C_FIELD(arg0,s32 *,0x7c)-r3;
result=M2C_FIELD(arg0,s32 (**)(void *,void *,s32,s32 *,s32,s32 *),0x180)(arg0,(u8*)arg0+0x164,inPtr+ip,&spC,outPtr+r3,&sp8);
if(result==2 && !func_02049bf0((s32*)((u8*)arg0+0x74),M2C_FIELD(arg0,s32 *,0x88)))return 0;
if(result==2 && sp8==0)goto loop;
M2C_FIELD(arg0,s32 *,0xa8)+=spC;
M2C_FIELD(arg0,s32 *,0x80)+=sp8;
used=M2C_FIELD(arg0,s32 *,0xa8);
if(used>255){
left=M2C_FIELD(arg0,s32 *,0xa4)-used;
if(!left)func_0204a2c8((u8*)arg0+0x98);
else {
p=M2C_FIELD(arg0,s32 *,0x9c);
func_020651c4(p,p+used,left);
M2C_FIELD(arg0,s32 *,0xa8)=0;
M2C_FIELD(arg0,s32 *,0xa4)=left;
}
}
if(result!=3)return 1;
M2C_FIELD(arg0,s32 *,0xfc)=1;
M2C_FIELD(arg0,s32 *,0x38)=17;
return 0;
}

s32 func_0204a740(void *p,u8 *dst,s32 *len) {
u32 func_02049208(void);
s32 func_02049ef4(s32,s32 *,s32,...);
s32 func_020497cc(s32,u8 *,s32,s32);

extern s32 data_020fd00c[];
s32 out; s32 r; s32 err; s32 got; s32 n; u32 now;
n=*len-1;
if(M2C_FIELD(p,s32 *,0x134)){
now=func_02049208();
if(now<M2C_FIELD(p,u32 *,0x138)+data_020fd00c[0])return 1;
M2C_FIELD(p,u32 *,0x138)=now;
if(n>=data_020fd00c[1])n=data_020fd00c[1];
}
if(M2C_FIELD(p,s32 *,0x84)<M2C_FIELD(p,s32 *,0x80)){
func_0204a3dc(p+0x74,dst,len);
if(M2C_FIELD(p,s32 *,0x84)==M2C_FIELD(p,s32 *,0x80)){
M2C_FIELD(p,s32 *,0x80)=M2C_FIELD(p,s32 *,0xf8);
M2C_FIELD(p,s32 *,0x84)=M2C_FIELD(p,s32 *,0xf8);
}return 0;
}
got=func_020497cc(M2C_FIELD(p,s32 *,0x48),dst,n,0);
r=got;
if(got==-1){
err=func_02049900(M2C_FIELD(p,s32 *,0x48));
if(err==-6||err==-26||err==-76)return 1;
M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=5;
M2C_FIELD(p,s32 *,0x4c)=err;M2C_FIELD(p,s32 *,0x130)=1;return 3;
}
if(got==0){M2C_FIELD(p,s32 *,0x130)=1;return 2;}
if(M2C_FIELD(p,s32 *,0x168)){
if(!((s32 (*)(void *,u8 *))func_02049ef4)(p+0x98,dst))return 3;
if(!func_0204a618(p)){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=17;return 3;}
if(M2C_FIELD(p,s32 *,0x80)-M2C_FIELD(p,s32 *,0x84)<=0){*dst=0;*len=0;return 1;}
r=*len-1;
if(!func_0204a3dc(p+0x74,dst,&r))return 3;
if(M2C_FIELD(p,s32 *,0x84)==M2C_FIELD(p,s32 *,0x80)){
M2C_FIELD(p,s32 *,0x80)=M2C_FIELD(p,s32 *,0xf8);
M2C_FIELD(p,s32 *,0x84)=M2C_FIELD(p,s32 *,0xf8);
}
got=r;if(got<=0)return 1;
}
out=0;dst[got]=0;*len=r;if(r<=0)out=1;return out;
}

s32 func_0204a954(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02049810(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02049900(s32);
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = func_02049810(M2C_FIELD(arg0, s32 *, 0x48), arg1, arg2, 0);
    if (temp_r0 == -1) {
        temp_r0_2 = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
        if ((temp_r0_2 != -6) && (temp_r0_2 != -0x1A) && (temp_r0_2 != -0x4C)) {
            M2C_FIELD(arg0, s32 *, 0xFC) = 1;
            M2C_FIELD(arg0, s32 *, 0x38) = 5;
            M2C_FIELD(arg0, s32 *, 0x4C) = temp_r0_2;
            return -1;
        }
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 4) {
        M2C_FIELD(arg0, s32 *, 0x148) = (s32) (M2C_FIELD(arg0, s32 *, 0x148) + temp_r0);
    }
    return temp_r0;
}

s32 func_0204a9d0(void *p,s32 a,s32 b) {
s32 n=0;
if(M2C_FIELD(p,s32 *,0x5c)==0){
n=func_0204a954(p,a,b);
if(n==-1)return 0;
if(n==b)return 1;
}
if(!func_02049ef4((s32)p+0x50,(s32 *)(a+n),b-n))return 0;
return 2;
}

