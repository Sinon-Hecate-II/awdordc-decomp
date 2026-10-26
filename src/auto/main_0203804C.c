/* 18 functions from 0x0203804C to 0x02038F88 (main), found by ds-decomp. */
#include "common.h"

s32 func_02038790(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g){s32 func_0203761c(void);void func_02039204(s32);void func_0203ac20(void *,void *,void *,s32,s32,s32,s32,s32);extern M2C_UNK func_020394d8;extern void *data_0213d1f8;s32 state;if(func_0203761c() || (state=M2C_FIELD(data_0213d1f8,s32 *,36))<3 || state==4)return 0;M2C_FIELD(data_0213d1f8,s32 *,120)=b;M2C_FIELD(data_0213d1f8,s32 *,124)=c;func_02039204(4);func_0203ac20(data_0213d1f8+224,data_0213d1f8+480,&func_020394d8,0,d,e,f,g);return 1;}

s32 func_02038838(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f){s32 func_0203761c(void);void func_02039100(void);void func_02039204(s32);void func_0203c428(s32,s32,void *,s32,s32,s32);extern M2C_UNK func_02039520;extern void *data_0213d1f8;if(func_0203761c() || M2C_FIELD(data_0213d1f8,s32 *,36)!=3)return 0;func_02039100();M2C_FIELD(data_0213d1f8,s32 *,128)=c;M2C_FIELD(data_0213d1f8,s32 *,132)=d;func_02039204(5);func_0203c428((u8)(a-1),b,&func_02039520,0,e,f);return 1;}

s32 func_02038a84(s32 a,s32 b,s32 c,s32 d,s32 e){s32 func_0203761c(void);void func_02039100(void);void func_02039204(s32);void func_0203c878(s32,void *,s32,s32,s32);extern M2C_UNK func_02039520;extern void *data_0213d1f8;if(func_0203761c() || M2C_FIELD(data_0213d1f8,s32 *,36)!=3)return 0;func_02039100();M2C_FIELD(data_0213d1f8,s32 *,136)=b;M2C_FIELD(data_0213d1f8,s32 *,140)=c;M2C_FIELD(data_0213d1f8,u8 *,44)=0;func_02039204(5);func_0203c878((u8)(a-1),&func_02039520,0,d,e);return 1;}

s32 func_02038d14(s32 a,s32 b){extern void *data_0213d1f8;if(!data_0213d1f8)return 0;M2C_FIELD(data_0213d1f8,s32 *,144)=a;M2C_FIELD(data_0213d1f8,s32 *,148)=b;return 1;}

s32 func_02038d40(void){extern void *data_0213d1f8;extern M2C_UNK data_020fc898;s32 func_0203761c(void);void func_0203af50(s32,void *,s32);void func_0203bd0c(void);void func_02039204(s32);void func_0205afec(void *);s32 state;if(!data_0213d1f8 || func_0203761c() || ((state=M2C_FIELD(data_0213d1f8,s32 *,0x24))!=5 && state!=6))return -1;if(!M2C_FIELD(data_0213d1f8,u8 *,0x381)){func_0203af50(1,&data_020fc898,0);func_0203bd0c();func_02039204(3);return 1;}M2C_FIELD(data_0213d1f8,u8 *,0x2d)=1;func_0205afec(M2C_FIELD(data_0213d1f8,void **,0));M2C_FIELD(data_0213d1f8,u8 *,0x2d)=0;return 0;}

s32 func_02038de4(s32 a){extern void *data_0213d1f8;s32 func_0203761c(void);void *func_02039050(s32);void func_0205afcc(void *);s32 state;void *p;if(!data_0213d1f8 || func_0203761c() || ((state=M2C_FIELD(data_0213d1f8,s32 *,0x24))!=5 && state!=6))return -1;p=func_02039050(a);if(!p)return -2;func_0205afcc(p);return 0;}

s32 func_02038e4c(void){extern void *data_0213d1f8;s32 func_0203e2c4(void);s32 func_0203e2a4(void);if(!data_0213d1f8)return 0;if(M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==2 || M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==3)return func_0203e2c4()+1;return func_0203e2a4()+1;}

u8 func_02038e94(void) {
    extern void *data_0213d1f8;
    if (data_0213d1f8 != NULL) {
        return M2C_FIELD(data_0213d1f8, u8 *, 0x2C);
    }
    return 0U;
}

s32 func_02038eb0(s32 *a){extern void *data_0213d1f8;s32 func_0203e36c(s32 *);s32 func_0203e338(s32 *);if(!data_0213d1f8)return 0;*a=(s32)(data_0213d1f8+0x644);if(M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==2 || M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==3)return func_0203e36c(a);return func_0203e338(a);}

s32 func_02038f00(void){extern void *data_0213d1f8;s32 func_02038eb0(s32 *);s32 func_02039284(s32,s32);s32 a,b;if(!data_0213d1f8)return 0;b=func_02038eb0(&a);return func_02039284(a,b);}

s32 func_02038f34(s32 a){extern void *data_0213d1f8;s32 func_020391b8(s32);if(!data_0213d1f8)return 0;if(!(M2C_FIELD(data_0213d1f8,u32 *,0x664)&(1<<a)))return 0;return func_020391b8(a);}

s32 func_02038f6c(void) {
    extern void *data_0213d1f8;
    if (data_0213d1f8 != NULL) {
        return M2C_FIELD(data_0213d1f8, s32 *, 0x24);
    }
    return 0;
}

