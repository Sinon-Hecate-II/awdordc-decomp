#include "common.h"


s32 func_02051ed0(void **arg0) {
M2C_UNK func_02050744(void **,s32,s32);
s32 func_0205835c(void **,s32,s32 *);
M2C_UNK func_02058620(void **,s32,M2C_UNK *);
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK data_020fe200,data_020fe3c4,data_020fe628,data_020fe650;
s32 state,result;void *p=*arg0;
result=func_0205835c(arg0,M2C_FIELD(p,s32 *,0x1d4),&state);
if(result)return result;
if(state==4){
func_02058620(arg0,0x107,&data_020fe628);
func_02050744(arg0,4,1);return 4;
}
if(state==0)return 0;
if(state!=3)func_020640a8(&data_020fe650,&data_020fe3c4,&data_020fe200,0x2ef);
M2C_FIELD(p,s32 *,0x1d8)=2;
return 0;
}

s32 func_02051f74(void **a,void *b){M2C_UNK func_020377c4(void *);M2C_UNK func_02055bf4(void **,void *);void *p=M2C_FIELD(b,void **,8);void *q=*a;
if(p&&M2C_FIELD(q,s32 *,260)==0){
func_020377c4(M2C_FIELD(p,void **,8));M2C_FIELD(M2C_FIELD(b,void **,8),void **,8)=0;
func_020377c4(M2C_FIELD(M2C_FIELD(b,void **,8),void **,12));M2C_FIELD(M2C_FIELD(b,void **,8),void **,12)=0;
func_020377c4(M2C_FIELD(b,void **,8));M2C_FIELD(b,void **,8)=0;
}
func_020377c4(M2C_FIELD(b,void **,16));M2C_FIELD(b,void **,16)=0;
func_020377c4(M2C_FIELD(b,void **,24));M2C_FIELD(b,void **,24)=0;M2C_FIELD(b,s32 *,20)=0;
if(!M2C_FIELD(b,s32 *,12)||(M2C_FIELD(q,s32 *,260)==1&&!M2C_FIELD(b,void **,8))){func_02055bf4(a,b);return 0;}
return 1;
}

s32 func_02052360(M2C_UNK arg0,s32 arg1,s32 *arg2,s32 *arg3,s32 *arg4){
s32 func_02052200(s32,s32,s32);
M2C_UNK func_02058644(M2C_UNK,M2C_UNK *);
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK data_020fe680,data_020fe6a4,data_020fe6b0,data_020fe6c0;
s32 hi=(u8)(arg1>>24),mid=(u8)(arg1>>16);
s32 low=(u16)arg1;
if(!func_02052200(hi,mid,low))func_020640a8(&data_020fe6c0,&data_020fe6a4,&data_020fe680,0xb7);
if(!func_02052200(hi,mid,low)){func_02058644(arg0,&data_020fe6b0);return 2;}
*arg2=hi;*arg3=mid;*arg4=low;
return 0;
}

