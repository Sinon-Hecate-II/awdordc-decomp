/* 23 functions from 0x0203AEB4 to 0x0203BE54 (main), found by ds-decomp. */
#include "common.h"

s32 func_0203aeb4(s32 a) {
 extern M2C_UNK data_0213d38c; s32 func_0203ae6c(s32);
 s32 i;
 if(!M2C_FIELD(&data_0213d38c,void **,8)||!a)return -1;
 for(i=0;i<M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x14);i++) {
 if(a==func_0203ae6c(i))return i;
 }return -1;
}

void func_0203af18(void) {
 extern M2C_UNK data_0213d38c; u64 func_02007004(void);
 u64 t; void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!p)return;
 M2C_FIELD(p,s32 *,8)=0;
 t=func_02007004();
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u64 *,0xC)=t;
}

s32 func_0203af50(s32 a,void *b,void *c) {
 extern M2C_UNK data_0213d38c;
 s32 func_0203a660(void); s32 func_0204e408(void *,s32,void *,void *);
 if(!M2C_FIELD(&data_0213d38c,void **,8)||!func_0203a660())return 0;
 if(a==-1)a=M2C_FIELD(*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4),s32 *,0x214);
 if(!b)b=(u8 *)*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4)+0x218;
 if(!c)c=(u8 *)*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4)+0x318;
 return func_0204e408(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,b,c);
}

void func_0203b000(s32 a) {
 extern M2C_UNK data_0213d38c; s32 func_0203a68c(void *,void *);
 u32 out[132]; void *p=M2C_FIELD(&data_0213d38c,void **,8); s32 n;
 if(M2C_FIELD(p,void **,0x44)&&M2C_FIELD(p,s32 *,0)!=1)
 M2C_FIELD(p,void (**)(s32,s32),0x44)(a,M2C_FIELD(p,s32 *,0x48));
 p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!M2C_FIELD(p,void **,0x34))return;
 n=func_0203a68c((u8 *)M2C_FIELD(p,void **,0x18)+a*12,out+66);
 p=M2C_FIELD(&data_0213d38c,void **,8);
 M2C_FIELD(p,void (**)(s32,s32,void *,s32),0x34)(a,n,out+66,M2C_FIELD(p,s32 *,0x38));
}

void func_0203b088(void) {
    extern M2C_UNK data_0213d38c;
    M2C_FIELD(&data_0213d38c, s32 *, 8) = 0;
}

s32 func_0203b09c(void) {
 extern M2C_UNK data_0213d38c; u64 func_02007004(void);
 u64 func_02072088(u64,u64);
 s32 func_0204db50(void *);
 s32 r=0; void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(func_02072088((func_02007004()-M2C_FIELD(p,u64 *,0xC))<<6,0x82EA) >=300) {
 M2C_FIELD(p,s32 *,8)++;
 r=func_0204db50(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4));
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u64 *,0xC)=func_02007004();
 }
 return r;
}

void func_0203b128(void) {
 extern M2C_UNK data_0213d38c;
 if(!M2C_FIELD(&data_0213d38c,void **,8))return;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1E)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1F)=0;
}

void func_0203b3c4(void) {
 extern M2C_UNK data_0213d38c;
 void *p=M2C_FIELD(&data_0213d38c,void **,8);
 M2C_FIELD(p,void (**)(s32,u8,s32),0x2C)(0,M2C_FIELD(p,u8 *,0x1D),M2C_FIELD(p,s32 *,0x30));
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=2;
}

void func_0203b3fc(u8 *a,u32 arg1,u32 arg2) {
 extern M2C_UNK data_0213d38c; void func_02007f8c(void *,s32);
 u32 c=arg2; u32 b=arg1;
 void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!p)return;
 func_02007f8c(a+b*12,0);
 p=M2C_FIELD(&data_0213d38c,void **,8);
 if(M2C_FIELD(p,void (**)(s32,s32,s32),0x3C))
 M2C_FIELD(p,void (**)(s32,s32,s32),0x3C)(b,c,M2C_FIELD(p,s32 *,0x40));
}

s32 func_0203b454(u8 *a,s32 b,s32 c) {
 extern M2C_UNK data_0213d38c; s32 func_0203ae6c(s32); s32 func_02031e38(void *);
 s32 i,x;
 for(i=0;i<b;i++) {
 x=func_0203ae6c(i);
 if(x&&x==c) {
 if(func_02031e38(a+b*12)&&!func_02031e38(a+i*12))func_0203b3fc(a,i,b);
 else func_0203b3fc(a,b,i);
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1D)=1;return 1;
 }
 }return 0;
}

s32 func_0203b608(s32 a) {
 extern M2C_UNK data_0213d38c; extern M2C_UNK data_020fc8ec;
 s32 func_0204df00(void *,s32,void *); u32 func_0203b6f8();
 s32 r=func_0204df00(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,&data_020fc8ec);
 func_0203b6f8(r); return r;
}

s32 func_0203b63c(s32 arg0,s32 arg1) {
 extern M2C_UNK data_0213d38c;
 s32 func_0203a660(void); s32 func_02039d98(void); s32 func_02032580(s32,s32);
 s32 func_0204e2f4(void *,s32,s32 *); s32 func_0204e1b4(void *,s32,s32);
 void *p=M2C_FIELD(&data_0213d38c,void **,8);
 s32 b=arg1; s32 a=arg0; s32 out=0;
 if(!p||!func_0203a660())return 0;
 a=func_02032580(func_02039d98(),a);
 if(a>0)if(func_0204e2f4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,&out))return 0;
 if(a<=0||out==-1)return 0;
 a=func_0204e1b4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),out,b);
 return a ? 0 : 1;
}

u32 func_0203b6f8(u32 a,u32 unused,u32 off){void func_0203accc(u32,u32);u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=9;off=code-10;break;case 2:code=9;off=code-11;break;case 3:code=6;off=code-16;break;case 4:code=6;off=code-26;break;}func_0203accc(code,off+0xfffeeaa8);return ret;}

s32 func_0203bcf8(void) {
 extern M2C_UNK data_0213d38c;
 return M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x20);
}

void func_0203bd0c(void) {
    M2C_UNK func_0205d8f4();
    extern M2C_UNK data_0213d39c;
    if (M2C_FIELD(&data_0213d39c, s32 *, 0x10) != 0) {
        M2C_FIELD(&data_0213d39c, s32 *, 0xC) = 1;
        return;
    }
    func_0205d8f4();
}

s32 func_0203bd34(void) {
    s32 func_0203bd54();
    M2C_UNK func_020418c4();
    if (func_0203bd54() == 0) {
        return 0;
    }
    func_020418c4();
    return 1;
}

s32 func_0203bd54(void) {
    s32 func_0203761c();
    s32 func_02038f6c();
    void *func_02044268();
    if (func_0203761c() != 0) {
        return 0;
    }
    if ((func_02044268() == NULL) || (func_02038f6c() != 5) || (M2C_FIELD(func_02044268(), u8 *, 0x1A9) != 0)) {
        return 0;
    }
    return 1;
}

s32 func_0203bda0(void (*callback)(s32),s32 arg) {
s32 func_0203761c(void);void *func_02044268(void);s32 func_02038f6c(void);void func_0203e410(void);
void *p;
if(func_0203761c()!=0||!func_02044268()||M2C_FIELD(func_02044268(),u8 *,0x15)!=2||(func_02038f6c()!=5&&func_02038f6c()!=6))return 0;
if(M2C_FIELD(func_02044268(),s32 *,0x1a0)==10){
p=func_02044268();M2C_FIELD(p,u8 *,0x16)=M2C_FIELD(func_02044268(),u8 *,0xd);
func_0203e410();if(callback)callback(arg);
}else{
M2C_FIELD(func_02044268(),void (**)(s32),0x47c)=callback;
M2C_FIELD(func_02044268(),s32 *,0x480)=arg;
M2C_FIELD(func_02044268(),u8 *,0x1ae)=1;
}return 1;
}

