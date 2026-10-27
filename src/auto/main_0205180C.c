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

extern u32 data_020fe524;
extern u32 data_020fe668;
extern u32 data_020fe67c;
extern s32 func_02051f74(void **, void *);
void func_02052038(void **arg0, s32 arg1) {
    void *temp_r4;
    s32 temp_r2;
    s32 temp_r0;
    s32 temp_r0_2;
    void *var_r6;
    void *temp_r1;
    u32 sp8;

    temp_r4 = *arg0;
    temp_r2 = *(s32 *)((char *)temp_r4 + 0x1D8);
    if (temp_r2 == 4) {
        return;
    }
    if (temp_r2 != 0) {
        if ((arg1 != 0) && (temp_r2 == 3)) {
            func_0204fea0(arg0, (char *)temp_r4 + 0x1F4, &data_020fe668);
            func_0204fed0(arg0, (char *)temp_r4 + 0x1F4, *(s32 *)((char *)temp_r4 + 0x198));
            func_0204fea0(arg0, (char *)temp_r4 + 0x1F4, &data_020fe524);
        }
        func_02050430(arg0, *(s32 *)((char *)temp_r4 + 0x1D4), (char *)temp_r4 + 0x1F4, &sp8, 1, &data_020fe67c);
        temp_r0 = *(s32 *)((char *)temp_r4 + 0x1D4);
        if (temp_r0 != -1) {
            func_020496cc(temp_r0, 2);
            func_020496b8(*(s32 *)((char *)temp_r4 + 0x1D4));
            *(s32 *)((char *)temp_r4 + 0x1D4) = -1;
        }
        temp_r0_2 = *(s32 *)((char *)temp_r4 + 0x204);
        if (temp_r0_2 != -1) {
            func_020496cc(temp_r0_2, 2);
            func_020496b8(*(s32 *)((char *)temp_r4 + 0x204));
            *(s32 *)((char *)temp_r4 + 0x204) = -1;
        }
        *(s32 *)((char *)temp_r4 + 0x1D8) = 4;
        *(s32 *)((char *)temp_r4 + 0x19C) = 0;
        *(s32 *)((char *)temp_r4 + 0x1A0) = 0;
    }
    func_020377c4(*(s32 *)((char *)temp_r4 + 0x1DC));
    *(s32 *)((char *)temp_r4 + 0x1DC) = 0;
    func_020377c4(*(s32 *)((char *)temp_r4 + 0x1EC));
    *(s32 *)((char *)temp_r4 + 0x1EC) = 0;
    func_020377c4(*(s32 *)((char *)temp_r4 + 0x1F4));
    *(s32 *)((char *)temp_r4 + 0x1F4) = 0;
    func_020377c4(*(s32 *)((char *)temp_r4 + 0x440));
    *(s32 *)((char *)temp_r4 + 0x440) = 0;
    func_020377c4(*(s32 *)((char *)temp_r4 + 0x450));
    *(s32 *)((char *)temp_r4 + 0x450) = 0;
    if (*(s32 *)((char *)temp_r4 + 0x424) != 0) {
        do {
            func_02054484(arg0);
        } while (*(s32 *)((char *)temp_r4 + 0x424) != 0);
    }
    *(s32 *)((char *)temp_r4 + 0x424) = 0;
    var_r6 = *(void **)((char *)temp_r4 + 0x434);
    if (var_r6 != NULL) {
        do {
            temp_r1 = var_r6;
            var_r6 = *(void **)((char *)var_r6 + 0x3C);
            func_02054fa8(arg0, temp_r1);
        } while (var_r6 != NULL);
    }
    *(s32 *)((char *)temp_r4 + 0x434) = 0;
    while (func_02055cd0(arg0, func_02051f74, 0) == 0) {
    }
}

/* Returns 1 if (day, month, year) is a valid calendar date (years 1900..2079, leap rules), 0 otherwise; treats 0/0/0 as valid sentinel. */
s32 func_02052200(s32 day,s32 month,s32 year){
 if(day==0 && month==0 && year==0)return 1;
 if(day<0 || month<0 || year<0)return 0;
 switch(month){
 case 0: if(day!=0)return 0;break;
 case 1:case 3:case 5:case 7:case 8:case 10:case 12:if(day>31)return 0;break;
 case 4:case 6:case 9:case 11:if(day>30)return 0;break;
 case 2:
 if((year%4==0 && year%100!=0)||year%400==0){if(day>29)return 0;}
 else if(day>28)return 0;
 break;
 default:return 0;
 }
 if(year<1900)return 0;
 if(year>2079)return 0;
 if(year==2079){
 if(month>6)return 0;
 if(month==6 && day>6)return 0;
 }
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

