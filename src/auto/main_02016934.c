/* 2 functions from 0x02016934 to 0x02017158 (main), found by ds-decomp. */
#include "common.h"
typedef struct DispatchCtx169 { u8 pad0[0x40]; u8 buffer[0x4c4]; u32 value; u8 pad508[0x10]; u16 a; u16 b; u8 pad51c[0x10]; u16 flag; } DispatchCtx169;
typedef struct DispatchWork169 { u8 pad[0x131c]; u32 active; u8 pad1320[0x1c8]; u32 entries[15]; } DispatchWork169;
extern M2C_UNK gMbState;
extern M2C_UNK gMbParam;
void func_020168a0(void);
int func_02016840(void);
void func_020168f0(void *);
void *func_020122ec(void *, void *);
void *func_02012418(void *, void *);
void *func_02013cfc(void *, int);
void *func_020122ac(void *);
void *func_02012a64(void *, int, int, void *, int, int, int, int, int, int, int);
void func_02018438(int, void *);
void func_0200758c(int);
void func_02007958(void);
void func_02011a20(int,int,int);
void func_020119dc(int);

#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_02016934(void *arg0) {
u32 i,n; 
switch ((s32)M2C_FIELD(arg0,u16 *,0)) {
case 0: if(M2C_FIELD(arg0,u16 *,2)) {M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);} else func_020168a0(); return;
case 29: if(M2C_FIELD(arg0,u16 *,2)) {M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);} else func_02018438(7,func_020122ec(func_02016934,M2C_FIELD(&gMbState,void **,8))); return;
case 7: M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(21,arg0); func_02018438(25,func_02013cfc(func_02016934,1)); return;
case 25: if(M2C_FIELD(arg0,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);} else func_02018438(8,func_02012418(func_02016934,M2C_FIELD(&gMbParam,void **,12))); return;
case 8:
if(M2C_FIELD(arg0,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);return;}
switch((s32)M2C_FIELD(arg0,u16 *,8)){
case 0: M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52a)=0; M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x528)=0; return;
case 7:
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)==1)return;
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52a)|=1<<M2C_FIELD(arg0,u16 *,16);
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(0,arg0);
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x528)==0 && M2C_FIELD(&gMbState,DispatchWork169 **,12)->active==0){
M2C_FIELD(&gMbState,DispatchWork169 **,12)->active=1;
{u32 flag=(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52c)==0); void *ctx=M2C_FIELD(&gMbState,void * volatile *,8);func_02018438(14,func_02012a64(func_02016934,M2C_FIELD(ctx,u32 *,0x504),M2C_FIELD(ctx,u16 *,0x51a),(char*)ctx+0x40,M2C_FIELD(ctx,u16 *,0x518),(u16)flag,0,0,0,1,1));}return;
}
if(func_02016840()){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(25,0);}return;
case 9: M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52a)&=~(1<<M2C_FIELD(arg0,u16 *,16)); M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(1,arg0);return;
case 2: if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)==1)return; M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(28,arg0);return;
case 26: return;
default: M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);return;
}
case 14:
M2C_FIELD(&gMbState,DispatchWork169 **,12)->active=0;
switch(M2C_FIELD(arg0,u16 *,4)){
case 10:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x528)=1;if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(25,0);}return;
case 11:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(3,M2C_FIELD(arg0,void **,8));return;
default:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);return;
}
case 15:
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,12),u32 *,0x74c8)){
n=0;i=0;do {if(M2C_FIELD(&gMbState,DispatchWork169 **,12)->entries[i]){n++;if(n>=2)break;}i++;}while(i<15);
if(n==1)func_0200758c(0x32c8);
}
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u8 *,0x50c)=0;
if(M2C_FIELD(arg0,u16 *,2)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(2,arg0);if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(25,0);}return;}
if(M2C_FIELD(arg0,u16 *,2)==10){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(42,arg0);return;}
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(19,arg0);if(M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(25,0);}return;
case 1:
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,12),u32 *,0x1320)==0){
if(M2C_FIELD(arg0,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)=0;M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);return;}
M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52a)=0; M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x528)=0;func_02018438(2,func_020122ac(func_02016934));return;
}
func_02011a20(1,0,0);func_020119dc(0);
case 2:if(M2C_FIELD(arg0,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x526)=0;M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);}else func_020168f0(arg0);return;
case 13:if(M2C_FIELD(arg0,u16 *,2)==0)M2C_FIELD(M2C_FIELD(&gMbState,void **,8),u16 *,0x52a)&=~M2C_FIELD(arg0,u16 *,10);return;
case 128:switch(M2C_FIELD(arg0,u16 *,4)){
case 16:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(29,arg0);return;
case 17:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(31,arg0);return;
case 18:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(32,arg0);return;
case 19:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(33,arg0);return;
case 22:func_02007958();return;
case 23:break;
}break;
default:M2C_FIELD(M2C_FIELD(&gMbState,void **,8),void (**)(int,void *),0x51c)(256,arg0);return;
}
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
void func_020170e8(void *arg0) {
    extern M2C_UNK gMbState;
    u16 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 4);
    switch ((s32) temp_r0) {
    case 7:
    case 9:
    case 25:
    case 26:
        break;
    case 21:
        M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), void (**)(s32, void *), 0x51C)(9, arg0);
        break;
    }
}
