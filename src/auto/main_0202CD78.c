/* 32 functions from 0x0202CD78 to 0x0202DBAC (main), found by ds-decomp. */
#include "common.h"

s32 func_0202cd78(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 func_0202c444();
    M2C_UNK func_0202c46c(M2C_UNK, s32);
    s32 func_0202cc6c(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d01c;
    s32 var_r2;
    s32 var_r4;

    var_r4 = func_0202c444();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = func_0202c02c();
        }
        var_r4 = func_0202cc6c(arg0, &func_0202d01c, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            func_0202c46c(arg0, var_r4);
        }
    }
    return var_r4;
}

s32 func_0202cde4(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 func_0202c444();
    M2C_UNK func_0202c46c(M2C_UNK, s32);
    s32 func_0202cc6c(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d044;
    s32 var_r2;
    s32 var_r4;

    var_r4 = func_0202c444();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = func_0202c02c();
        }
        var_r4 = func_0202cc6c(arg0, &func_0202d044, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            func_0202c46c(arg0, var_r4);
        }
    }
    return var_r4;
}

s32 func_0202ce50(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 func_0202c444();
    M2C_UNK func_0202c46c(M2C_UNK, s32);
    s32 func_0202cc6c(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32);
    extern M2C_UNK func_0202d074;
    s32 var_r2;
    s32 var_r4;

    var_r4 = func_0202c444();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = func_0202c02c();
        }
        var_r4 = func_0202cc6c(arg0, &func_0202d074, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            func_0202c46c(arg0, var_r4);
        }
    }
    return var_r4;
}

s32 func_0202cfc4(s32 arg0,s32 arg1,s32 arg2) {
s32 func_0200751c();
s32 func_0202c014(s32);
s32 func_0202c444(s32);
s32 func_0202c46c(s32,s32);
void func_02007530(s32);
s32 handle;
s32 saved;
if(!arg1)return;
saved=func_0200751c();
handle=func_0202c014(arg1);
if(arg0==func_0202c444(arg2))func_0202c46c(arg2,0);
func_0202c014(handle);
func_02007530(saved);
}

void func_0202d01c(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02008e90(s32, s32);
    M2C_UNK func_0202cfc4(s32, M2C_UNK, M2C_UNK);
    func_0202cfc4(arg0, arg2, arg3);
    func_02008e90(arg0, arg0 + arg1);
}

void func_0202d044(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02008eb0(s32, s32);
    M2C_UNK func_02009a0c(s32);
    func_0202cfc4(arg0, arg2, arg3);
    func_02008eb0(arg0, arg0 + arg1);
    func_02009a0c(arg0);
}

void func_0202d074(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02008ed0(s32, s32);
    M2C_UNK func_02009aa4(s32);
    func_0202cfc4(arg0, arg2, arg3);
    func_02008ed0(arg0, arg0 + arg1);
    func_02009aa4(arg0);
}

void func_0202d0a4(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
s32 func_02009aa4(s32);
func_0202cfc4(arg0,arg2,arg3);
func_02009aa4(arg0);
}

void func_0202d0c4(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02009cc4(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02009cf8(M2C_UNK, M2C_UNK);
    if (arg0 == func_02009cf8(arg2, arg3)) {
        func_02009cc4(arg2, arg3, 0);
    }
    func_02008ed0(arg0, arg0 + arg1);
}

s32 func_0202d10c(s32 arg0, u16 arg1, s32 arg2, s32 arg3) {
    s32 func_02009cf8(M2C_UNK, M2C_UNK);
    s32 func_02009cbc(M2C_UNK);
    void *func_0202c5f0(s32 *, s32, s32, s32, s32);
    s32 func_0202c3ac(s32, void *, s32, s32);
    M2C_UNK func_020067c4(M2C_UNK, M2C_UNK);
    M2C_UNK func_02009cc4(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_0202d0c4(s32, s32, M2C_UNK, M2C_UNK);
    s32 t;
    s32 n;
    s32 off;
    s32 field;

    if (func_02009cf8((M2C_UNK)arg0, arg1) != 0) {
        return 1;
    }
    t = func_02009cbc((M2C_UNK)arg0);
    field = M2C_FIELD(arg0, s32 *, 0x38);
    {
        void *ptr;
        s32 base;
        s32 valm1 = t - 1;
        ptr = (void *)(arg0 + (field + arg1) * 4);
        off = M2C_FIELD(ptr, s32 *, 0x3C);
        if ((u32)arg1 < (u32)valm1) {
            base = M2C_FIELD(ptr, s32 *, 0x40);
        } else {
            base = M2C_FIELD(arg0, s32 *, 0x8);
        }
        n = base - off;
    }
    if (arg3 == 0) {
        return 0;
    }
    {
        void *p;
        p = func_0202c5f0((s32 *)arg3, n + 32, (s32)func_0202d0c4, arg0, arg1);
        if (p == 0) {
            return 0;
        }
        if (n != func_0202c3ac(arg2, p, n, off)) {
            return 0;
        }
        func_020067c4((M2C_UNK)p, n);
        func_02009cc4((M2C_UNK)arg0, arg1, (M2C_UNK)p);
    }
    return 1;
}

s32 func_0202d1d4(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
void func_02009aec(void *);
s32 func_02009b0c(s32,void *,void *);
s32 func_0202d10c(s32,u16,s32,s32);
u8 entry[12];
u32 iter[2];
u32 initial[2];
void *cursor;
func_02009aec(initial);
iter[0]=initial[0];iter[1]=initial[1];
cursor=iter;
if(!arg1)return 0;
if(func_02009b0c(arg1,entry,cursor)) do {
if(entry[0]==1 && arg2==*(u16 *)(entry+4)) {
if(!func_0202d10c(arg0,*(u16 *)(entry+2),arg3,arg4))return 0;
}
} while(func_02009b0c(arg1,entry,iter));
return 1;
}

s32 func_0202d294(s32 arg0) {
void *func_0202c230(s32);
void func_0202ab94(s32,u8);
void func_0202abb4(s32,u16);
s32 func_0202abcc(s32,s32,s32);
s32 i; void *p; s32 j; s32 saved=arg0;
func_0202c02c();
for(i=0;i<32;i++) {
p=func_0202c230(i);
if(p) {
func_0202ab94(i,M2C_FIELD(p,u8 *,0));
func_0202abb4(i,M2C_FIELD(p,u16 *,2));
if(M2C_FIELD(p,s32 *,4) && saved)
for(j=0;j<M2C_FIELD(p,u8 *,0);j++)
if(!func_0202abcc(i,saved,M2C_FIELD(p,s32 *,4)))return 0;
}
}
return 1;
}

s32 func_0202d330(M2C_UNK arg0, s32 arg1) {
    void *func_0202c03c(s32);
    s32 func_0202d514(M2C_UNK, s32, s32, s32, void *, s32);
    void *temp_r0;

    temp_r0 = func_0202c03c(arg1);
    if (temp_r0 == NULL) {
        return 0;
    }
    return func_0202d514(arg0, M2C_FIELD(temp_r0, u8 *, 9), M2C_FIELD(temp_r0, u16 *, 4), M2C_FIELD(temp_r0, u8 *, 8), temp_r0, arg1);
}

s32 func_0202d378(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
void *func_0202c03c(s32);
s32 func_0202d514(s32,s32,s32,s32,void *,s32);
void *p=func_0202c03c(arg4);
if(!p)return 0;
if(arg3<0)arg3=M2C_FIELD(p,u8 *,8);
if(arg2<0)arg2=M2C_FIELD(p,u16 *,4);
if(arg1<0)arg1=M2C_FIELD(p,u8 *,9);
return func_0202d514(arg0,arg1,arg2,arg3,p,arg4);
}

s32 func_0202d3e8(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 *func_0202c0a0(s32);
    s32 func_0202d610(M2C_UNK, s32, s32, s32, void *, s32, s32, s32);
    void *func_0202ee80(s32, s32);
    s32 *temp_r0_3;
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0_3 = func_0202c0a0(arg1);
    if (temp_r0_3 == NULL) {
        return 0;
    }
    temp_r0_2 = func_0202c444(*temp_r0_3);
    if (temp_r0_2 == 0) {
        return 0;
    }
    temp_r0 = func_0202ee80(temp_r0_2, arg2);
    if (temp_r0 == NULL) {
        return 0;
    }
    return func_0202d610(arg0, M2C_FIELD(temp_r0, u8 *, 9), M2C_FIELD(temp_r0, u16 *, 4), M2C_FIELD(temp_r0, u8 *, 8), temp_r0, temp_r0_2, arg1, arg2);
}

s32 func_0202d468(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5) {
s32 *func_0202c0a0(s32);
void *func_0202ee80(s32,s32);
s32 func_0202d610(s32,s32,s32,s32,void *,s32,s32,s32);
s32 *q; s32 h; void *p;
q=func_0202c0a0(arg4);
if(!q)return 0;
h=func_0202c444(*q);
if(!h)return 0;
p=func_0202ee80(h,arg5);
if(!p)return 0;
if(arg3<0)arg3=M2C_FIELD(p,u8 *,8);
if(arg2<0)arg2=M2C_FIELD(p,u16 *,4);
if(arg1<0)arg1=M2C_FIELD(p,u8 *,9);
return func_0202d610(arg0,arg1,arg2,arg3,p,h,arg4,arg5);
}

s32 func_0202d514(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5) {
    void *func_0202b018(void *, s32, s32);
    void *func_0202b158(s32, void *);
    s32 func_0202caa0(void *, s32, s32, s32, s32 *);
    s32 func_0202c9bc(s32, s32, s32, s32, s32 *);
    void func_0202b0b0(void *);
    void func_0202b0bc(void *, void *, s32);
    void func_0202acf0(void *, s8);
    void func_0202ad30(void *, s32);
    void func_0202adb0(void **, s16);

    void *handle;
    void *p;
    s32 tmp4;
    s32 tmp8;

    handle = func_0202b018((void *)arg0, arg1, arg3);
    if (handle == 0) {
        return 0;
    }
    p = func_0202b158(arg1, handle);
    tmp4 = 0;
    tmp8 = 0;
    if (func_0202caa0((void *)arg2, 6, (s32)p, 0, &tmp4) != 0) {
        func_0202b0b0(handle);
        return 0;
    }
    if (func_0202c9bc(arg5, 1, (s32)p, 0, &tmp8) != 0) {
        func_0202b0b0(handle);
        return 0;
    }
    func_0202b0bc(handle, (void *)((u8 *)tmp8 + *(s32 *)((u8 *)tmp8 + 0x18)), 0);
    func_0202acf0((void *)arg0, (s8)((u8 *)arg4)[6]);
    func_0202ad30((void *)arg0, (s32)((u8 *)arg4)[7]);
    func_0202adb0((void **)arg0, (s16)arg5);
    return 1;
}

s32 func_0202d610(s32 a,s32 b,s32 c,s32 d,void *e,s32 f,s32 g,s32 h){
void *func_0202b018(void*,s32,s32);void *func_0202b158(s32,void*);s32 func_0202caa0();void func_0202b0b0();void func_0202b0bc();void func_0202add4();
void func_0202acf0(void*,s8);void func_0202ad30(void*,s32);register u8 *entry=e;s32 local; void *v=func_0202b018((void*)a,b,d);void *t;
if(!v)return 0;
t=func_0202b158(b,v);
if(func_0202caa0(c,6,t,0,&local)){func_0202b0b0(v);return 0;}
func_0202b0bc(v,f+M2C_FIELD(f,s32*,0x18),M2C_FIELD(entry,s32*,0),local);
((void(*)(void*,s32))func_0202acf0)((void*)a,M2C_FIELD(entry,u8*,6));func_0202ad30((void*)a,M2C_FIELD(entry,u8*,7));func_0202add4(a,g,h);return 1;
}

void func_0202d6d4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0200654c(M2C_UNK *);
    M2C_UNK func_0200b774(s32);
    M2C_UNK func_02029c30(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02029c74(M2C_UNK *, s32);
    M2C_UNK func_0202b46c(s32);
    M2C_UNK func_0202d7d8(M2C_UNK);
    M2C_UNK func_0202dfcc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0213c290;
    extern M2C_UNK data_0213c29c;
    extern M2C_UNK data_0213c2a8;
    extern M2C_UNK data_0213c2c0;
    extern M2C_UNK data_0213c440;
    extern u8 data_0213c92c[];
    extern M2C_UNK data_0213cf00;
    s32 temp_r6;
    s32 var_r5;
    s32 var_r9;

    if (M2C_FIELD(&data_0213c290, s32 *, 0) != 0) {
        func_0202d7d8(arg1);
        return;
    }
    M2C_FIELD(&data_0213c290, s32 *, 0) = 1;
    func_02029c30(&data_0213c29c, 0);
    var_r9 = 0;
loop_4:
    if (var_r9 < 8) {
        func_02029c74(&data_0213c29c, (var_r9 * 0x30) + (s32) &data_0213c2c0);
        var_r9 += 1;
        goto loop_4;
    }
    func_0200654c(&data_0213c2a8);
    var_r5 = 0;
    M2C_FIELD(&data_0213c290, M2C_UNK **, 8) = &data_0213cf00;
loop_7:
    if (var_r5 < 4) {
        temp_r6 = (var_r5 * 0x174) + (s32) data_0213c92c;
        M2C_FIELD(temp_r6, s32 *, 0x110) = (s32) (M2C_FIELD(temp_r6, s32 *, 0x110) & ~1);
        func_0200b774(temp_r6 + 0x5C);
        func_0202b46c(temp_r6);
        M2C_FIELD(temp_r6, s32 *, 0x148) = var_r5;
        M2C_FIELD(temp_r6, s8 *, 0x124) = 0;
        M2C_FIELD(temp_r6, s32 *, 0x12C) = 0;
        M2C_FIELD(temp_r6, s32 *, 0x130) = 0;
        M2C_FIELD(temp_r6, s32 *, 0x120) = 0;
        var_r5 += 1;
        goto loop_7;
    }
    func_0202d7d8(arg1);
    func_0202dfcc(&data_0213c440, arg0);
}

s32 func_0202d7d8(s32 a){
u8 *func_0202c294(s32);void *func_0202c5f0(s32*,s32,s32,s32,s32);void func_0202de74();extern u8 data_0213c92c[];extern M2C_UNK func_0202e158;
s32 j,i,size,handle;u8 *p,*q;s32 callback=(s32)&func_0202e158;
i=0;p=data_0213c92c;
do {q=func_0202c294(i);if(q){j=0;p[0x124]=q[0];if((s32)q[0]>0){do{u8 v=q[j+1];u8 *dst=p+j;j++;dst[0x126]=v;}while(j<q[0]);}
if(a){size=p[0x124]<<11;handle=(s32)func_0202c5f0((s32*)a,size,callback,(s32)p,0);if(!handle)return 0;func_0202de74(p);M2C_FIELD(p,s32*,0x12c)=handle;M2C_FIELD(p,s32*,0x130)=size;}}
i++;p+=0x174;}while(i<4);return 1;
}

s32 func_0202d8a0(s32 a,s32 b,s32 c){void *func_0202c1cc(s32);s32 func_0202dbac(s32,void *,s32,s32,s32,s32,s32,s32,s32,s32);void *p=func_0202c1cc(b);if(!p)return 0;return func_0202dbac(a,p,M2C_FIELD(p,u8 *,6),M2C_FIELD(p,u8 *,5),b,c,0,0,0,0);}

s32 func_0202d8fc(s32 arg) {
void * volatile *arg0=(void * volatile *)arg;
void *p;
if (*arg0 == 0) return;
p=*arg0;
return M2C_FIELD(p,s32 *,0x110)|=4;
}

s32 func_0202d91c(M2C_UNK arg0) {
    s32 func_0202d8a0();
    M2C_UNK func_0202d8fc(M2C_UNK);
    if (func_0202d8a0() == 0) {
        return 0;
    }
    func_0202d8fc(arg0);
    return 1;
}

void func_0202d944(volatile s32 *arg0,s32 arg1) {
void func_0202de1c(s32,s32);
if(*arg0==0)return;
func_0202de1c(*arg0,arg1);
}

void func_0202d960(void *volatile *a,s32 b){void func_0202eed8(void *,s32);void *p;if(!*a)return;p=*a;if(((s32)(M2C_FIELD(p,u32 *,0x110)<<28)>>31)!=0)return;func_0202eed8(p+0xe8,b<<8);}

void func_0202d994(volatile s32 *a,s32 b,s32 c){extern s16 data_020e9ca0[];void func_0202b7e8(s32,s32,s16);if(!*a)return;func_0202b7e8(*a,b,data_020e9ca0[c]);}

void func_0202d9c0(s32 *arg0) {
    *arg0 = 0;
}

void func_0202d9cc(void **arg0) {
    void *temp_r2;

    temp_r2 = *arg0;
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, s32 *, 0x14C) = 0;
        *arg0 = NULL;
    }
}

void func_0202d9e4(void) {
void func_0202b70c(void *); void func_0202b77c(void *,s32); void func_0202de74(void *);
s32 func_0202ef00(void *); void func_0202ef34(void *); s32 func_0202ef4c(void *);
extern u8 data_0213c92c[]; extern s16 data_020e9ca0[];
s32 i; s16 a; s32 b; u8 *p; p=data_0213c92c; i=0;
do {
s32 flags=M2C_FIELD(p,s32 *,0x110);
if((flags<<31)>>31) {
if(!M2C_FIELD(p,s32 *,0x114))func_0202de74(p);
else {
if(((flags<<29)>>31) && M2C_FIELD(p,s32 *,0x118)) {
func_0202b70c(p);
M2C_FIELD(p,s32 *,0x110)=(M2C_FIELD(p,s32 *,0x110)|2)&~4;
}
if((M2C_FIELD(p,s32 *,0x110)<<30)>>31) {
func_0202ef34(p+0xe8);
a=data_020e9ca0[M2C_FIELD(p,s32 *,0x154)];
b=data_020e9ca0[M2C_FIELD(p,s32 *,0x158)]+(data_020e9ca0[func_0202ef00(p+0xe8)>>8]+a);
if(b!=M2C_FIELD(p,s32 *,0x15c)){func_0202b77c(p,b); M2C_FIELD(p,s32 *,0x15c)=b;}
if(((M2C_FIELD(p,s32 *,0x110)<<28)>>31) && func_0202ef4c(p+0xe8))func_0202de74(p);
}
}
}
i++;p+=0x174;
}while(i<4);
}

void *func_0202daf4(void **a,s32 b,s32 c){extern u8 data_0213c92c[];void func_0202d9cc(void **);void func_0202de74(void *);void *p;if(*a)func_0202d9cc(a);p=data_0213c92c+b*0x174;if(!M2C_FIELD(p,s32 *,0x12c))return 0;if(((s32)(M2C_FIELD(p,u32 *,0x110)<<31)>>31)!=0){if(c<M2C_FIELD(p,s32 *,0x150))return 0;func_0202de74(p);}M2C_FIELD(p,s32 *,0x150)=c;M2C_FIELD(p,u32 *,0x110)=(M2C_FIELD(p,u32 *,0x110)&~1)|1;M2C_FIELD(p,void ***,0x14c)=a;*a=p;return p;}

void func_0202db80(void *arg0) {
s32 *p=M2C_FIELD(arg0,s32 **,0x14c);
if(p){*p=0;M2C_FIELD(arg0,s32 **,0x14c)=0;}
M2C_FIELD(arg0,u32 *,0x110)&=~1;
M2C_FIELD(arg0,u32 *,0x110)&=~4;
M2C_FIELD(arg0,u32 *,0x110)&=~2;
}

