/* 21 functions from 0x02009EB0 to 0x0200AE9C (main), found by ds-decomp. */
#include "common.h"
static inline u32 LowerChar(u32 c) { c-=0x41; if(c<=25) return c+0x61;return c+0x41; }
typedef struct { u32 a,b,c; } UnkA3Block;
typedef struct { u32 a:5; u32 c:1; u32 b:26; } FifoWord;

s32 func_02009eb0(u32 a,u32 b,u32 c) { s32 func_0200751c(void);s32 func_02007530(s32);FifoWord v; s32 key;v.a=a;v.c=c;v.b=b;if(*(volatile u16 *)0x04000184&0x4000){*(volatile u16 *)0x04000184|=0xc000;return -1;}key=func_0200751c();if(*(volatile u16 *)0x04000184&2){func_02007530(key);return -2;}*(volatile u32 *)0x04000188=*(u32 *)&v;func_02007530(key);return 0;}

void func_02009f38(void){
s32 func_0200751c(void);s32 func_02007530(s32);
extern void (*data_0212fb68[])(u32,u32,u32);
FifoWord v;s32 result,key;u32 tag;void (*cb)(u32,u32,u32);
for(;;){
if(*(volatile u16*)0x04000184&0x4000){*(volatile u16*)0x04000184|=0xc000;result=-3;}
else{
key=func_0200751c();
if(*(volatile u16*)0x04000184&0x100){func_02007530(key);result=-4;}
else{*(u32*)&v=*(volatile u32*)0x04100000;func_02007530(key);result=0;}
}
if(result==-4)return;
if(result==-3)continue;
tag=v.a;if(!tag)continue;
cb=data_0212fb68[tag];
if(cb)cb(tag,v.b,v.c);
else if(!v.c){
v.c=1;
if(*(volatile u16*)0x04000184&0x4000){*(volatile u16*)0x04000184|=0xc000;continue;}
key=func_0200751c();
if(*(volatile u16*)0x04000184&2){func_02007530(key);continue;}
*(volatile u32*)0x04000188=*(u32*)&v;
func_02007530(key);
}
}
}

void func_0200a050(void *p,s32 a) {s32 func_0200751c(void);s32 func_02007530(s32);s32 func_02005df4(void *);s32 k;void *prev,*next;k=func_0200751c();prev=M2C_FIELD(p,void **,0);next=M2C_FIELD(p,void **,4);if(prev)M2C_FIELD(prev,void **,4)=next;if(next)M2C_FIELD(next,void **,0)=prev;M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;M2C_FIELD(p,u32 *,12)&=~0x4f;M2C_FIELD(p,s32 *,20)=a;func_02005df4((u8 *)p+24);func_02007530(k);}

s32 func_0200a0ac(void *a, s32 b) {
    s32 func_0200751c(void);
    s32 func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    extern s32 (*data_020ea674[])(void *);
    void func_0200a050(void *, s32);

    void *c = M2C_FIELD(a, void **, 0x8);
    s32 flag = 1;
    u32 d = (u32)1 << b;
    s32 e;
    s32 k;
    s32 has200;
    s32 outer;
    s32 zero = 0;
    s32 one = 1;

    if (!(M2C_FIELD(a, s32 *, 0xc) & 0x4)) {
        flag = 0;
    }
    if (flag) {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) | 0x200;
    } else {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) | 0x100;
    }
    if (M2C_FIELD(c, u32 *, 0x58) & d) {
        s32 (*cb)(void *, s32) = M2C_FIELD(c, s32 (**)(void *, s32), 0x54);
        e = cb(a, b);
        switch (e) {
        case 0:
        case 1:
        case 4:
            M2C_FIELD(a, s32 *, 0x14) = e;
            break;
        case 8:
            M2C_FIELD(c, u32 *, 0x58) = M2C_FIELD(c, u32 *, 0x58) & ~d;
            e = 7;
            break;
        default:
            e = 7;
            break;
        }
    } else {
        e = 7;
    }
    if (e == 7) {
        e = data_020ea674[b](a);
        if (e == 6) {
            outer = (M2C_FIELD(a, s32 *, 0xc) & 0x4) ? 1 : 0;
            if (outer != 0) {
                k = func_0200751c();
                has200 = (M2C_FIELD(c, s32 *, 0x1c) & 0x200) ? 1 : 0;
                if (has200 != 0) {
                    do {
                        func_02005da4((u8 *)c + 0xc);
                        if (M2C_FIELD(c, s32 *, 0x1c) & 0x200) {
                            has200 = one;
                        } else {
                            has200 = zero;
                        }
                    } while (has200 != 0);
                    func_02007530(k);
                    e = M2C_FIELD(a, s32 *, 0x14);
                } else {
                    outer = (M2C_FIELD(a, s32 *, 0xc) & 0x4) ? 1 : 0;
                    if (outer != 0) {
                        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) & ~0x200;
                        M2C_FIELD(a, s32 *, 0x14) = 6;
                    } else {
                        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) & ~0x100;
                        func_0200a050(a, 6);
                    }
                }
            }
        }
    }
    if (e != 7) {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) & ~0x200;
        M2C_FIELD(a, s32 *, 0x14) = e;
    }
    return e;
}

s32 func_0200a23c(u8 *a,u8 *b,u32 n) {u32 i,x,y;for(i=0;i<n;i++){x=a[i]-0x41;y=b[i]-0x41;if(x<=25)x+=32;if(y<=25)y+=32;if(x!=y)return x-y;}return 0;}

s32 func_0200a28c(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0200751c();
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02007530(s32);
    void *temp_r4;
    s32 var_r0;
    u32 var_r0_2;
    unsigned long var_r0_3;
    s32 temp_r5;

    temp_r4 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r4, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x1C) | 0x200);
    var_r0 = M2C_FIELD(temp_r4, s32 (**)(void *, M2C_UNK, s32, s32), 0x50)(temp_r4, arg1, M2C_FIELD(arg0, s32 *, 4), arg2);
    switch (var_r0) {                               /* irregular */
    case 0:
    case 1:
        M2C_FIELD(temp_r4, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x1C) & ~0x200);
        break;
    case 6:
        temp_r5 = func_0200751c();
        if (M2C_FIELD(temp_r4, s32 *, 0x1C) & 0x200) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 != 0) {
            do {
                func_02005da4(temp_r4 + 0xC);
                if (M2C_FIELD(temp_r4, s32 *, 0x1C) & 0x200) {
                    var_r0_3 = 1;
                } else {
                    var_r0_3 = 0;
                }
            } while (var_r0_3 != 0);
        }
        func_02007530(temp_r5);
        var_r0 = M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x14);
        break;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + arg2);
    return var_r0;
}

void func_0200a34c(void *arg0, s16 arg1) {
    M2C_UNK func_0200a0ac(void *, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) | 4);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = arg1;
    func_0200a0ac(arg0, 2);
}

void func_0200a380(void *p) {
s32 a=M2C_FIELD(p,s32 *,0x2c), b=M2C_FIELD(p,s32 *,0x38);
void *q=M2C_FIELD(p,void **,8);
s32 c=M2C_FIELD(p,s32 *,0x30);
M2C_FIELD(p,s32 *,0x2c)=a+b;
M2C_FIELD(q,void (**)(void *,s32),0x48)(q,c);
}

void func_0200a3ac(void *p) {
s32 a=M2C_FIELD(p,s32 *,0x2c), b=M2C_FIELD(p,s32 *,0x38);
void *q=M2C_FIELD(p,void **,8);
s32 c=M2C_FIELD(p,s32 *,0x30);
M2C_FIELD(p,s32 *,0x2c)=a+b;
M2C_FIELD(q,void (**)(void *,s32),0x4c)(q,c);
}

s32 func_0200a3d8(void *p) {
void *q=M2C_FIELD(p,void **,8);
u32 out[2], in[2]; s32 r; u32 *v=(u32 *)((u8 *)p+0x30);
in[0]=(u32)q;
in[1]=M2C_FIELD(q,u32 *,0x34)+(M2C_FIELD(v,u16 *,4)<<3);
r=func_0200a28c(in,(M2C_UNK)out,8);
if(!r){
*(UnkA3Block *)((u8 *)p+0x20)=*(UnkA3Block *)v;
if(!M2C_FIELD(v,u16 *,6)&&!v[2]){
M2C_FIELD(p,u16 *,0x26)=M2C_FIELD(out,u16 *,4);
M2C_FIELD(p,u32 *,0x28)=M2C_FIELD(q,u32 *,0x34)+out[0];
}
M2C_FIELD(p,u32 *,0x2c)=M2C_FIELD(out,u16 *,6)&0xfff;
}
return r;
}

s32 func_0200a470(void *p){
void *q=M2C_FIELD(p,void **,0x30);
u32 in[2];u8 header;u16 extra;s32 r;
in[0]=M2C_FIELD(p,u32 *,8);in[1]=M2C_FIELD(p,u32 *,0x28);
r=func_0200a28c(in,(M2C_UNK)&header,1);if(r)return r;
M2C_FIELD(q,u32 *,0x10)=header&127;
M2C_FIELD(q,u32 *,12)=(header>>7)&1;
if(!M2C_FIELD(q,u32 *,0x10))return 1;
if(!M2C_FIELD(p,u32 *,0x34)){
r=func_0200a28c(in,(M2C_UNK)((u8*)q+20),M2C_FIELD(q,u32 *,0x10));if(r)return r;
((u8*)q+M2C_FIELD(q,u32 *,0x10))[20]=0;
}else in[1]+=M2C_FIELD(q,u32 *,0x10);
if(M2C_FIELD(q,u32 *,12)){
r=func_0200a28c(in,(M2C_UNK)&extra,2);if(r)return r;
M2C_FIELD(q,u32 *,0)=M2C_FIELD(p,u32 *,8);
M2C_FIELD(q,u16 *,4)=extra&0xfff;
M2C_FIELD(q,u16 *,6)=0;M2C_FIELD(q,u32 *,8)=0;
}else{
M2C_FIELD(q,u32 *,0)=M2C_FIELD(p,u32 *,8);
M2C_FIELD(q,u32 *,4)=M2C_FIELD(p,u16 *,0x26);
M2C_FIELD(p,u16 *,0x26)+=1;
}
M2C_FIELD(p,u32 *,0x28)=in[1];return r;
}

s32 func_0200ab2c(void *p) {
void *q=M2C_FIELD(p,void **,8); u32 n=M2C_FIELD(p,u32 *,0x34); u32 off=(n<<3); u32 out[2],in[2]; s32 r;
if(off>=M2C_FIELD(q,u32 *,0x30)) return 1;
in[0]=(u32)q; in[1]=M2C_FIELD(q,u32 *,0x2c)+off;
r=func_0200a28c(in,(M2C_UNK)out,8); if(r)return r;
M2C_FIELD(p,u32 *,0x30)=out[0]; M2C_FIELD(p,u32 *,0x34)=out[1]; M2C_FIELD(p,u32 *,0x38)=n;
return func_0200a0ac(p,7);
}

s32 func_0200abac(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    return 0;
}

s32 func_0200abd4(void) {
    return 0;
}

u32 func_0200abdc(u8 *p,s32 n){u32 result=0; s32 i,shift;u32 c;if(n<=3){i=0;if(n>0){shift=0;do{c=p[i];if(!c)break;c=(u8)(c-0x41);if((u32)c<=25)c+=0x61;else c+=0x41;result|=c<<shift;i++;shift+=8;}while(i<n);}}return result;}

s32 func_0200ac34(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK func_02008048(s32, M2C_UNK, M2C_UNK);
    func_02008048(M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg1, arg3);
    return 0;
}

s32 func_0200ac50(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    func_02008048(arg1, M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg3);
    return 0;
}

s32 func_0200ac70(s32 a,s32 b,s32 c,s32 d){func_02008048(c,b,d);return 0;}

