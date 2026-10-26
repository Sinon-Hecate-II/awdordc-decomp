/* 19 functions from 0x0204D5C0 to 0x0204E408 (main), found by ds-decomp. */
#include "common.h"

void func_0204da30(void *p){
s32 func_02037794(s32);void func_020377c4(s32);s32 func_02049208();s32 func_0204a740(void*,s32,s32*);s32 func_0204d39c(void*,s32,s32);
s32 size,buffer,status,n,start;u32 elapsed;
start=func_02049208();elapsed=0;buffer=func_02037794(0x2000);
if(!buffer){M2C_FIELD(p,s32*,0xfc)=1;M2C_FIELD(p,s32*,0x38)=1;return;}
while(!M2C_FIELD(p,s32*,0xfc) && elapsed<M2C_FIELD(p,u32*,0x158)){
size=0x2000;status=func_0204a740(p,buffer,&size);
if(status==3 || status==1)break;
if(status==2){
M2C_FIELD(p,s32*,0xfc)=1;n=M2C_FIELD(p,s32*,0x104);
if(n>0 && M2C_FIELD(p,s32*,0x100)<n)M2C_FIELD(p,s32*,0x38)=15;
break;
}
if(!func_0204d39c(p,buffer,size))break;
elapsed=func_02049208()-start;
}
func_020377c4(buffer);
}

s32 func_0204db04(s32 arg0,s32 arg1,s32 arg2) {
 extern s32 data_0213db84;
 s32 func_0204e6a8(s32,s32,s32);
 if(data_0213db84!=1) return 2;
 if(arg0==0) return 2;
 return func_0204e6a8(arg0,arg1,arg2);
}

void func_0204db34(s32 *arg0) {
 void func_0204e7f0(s32 *);
 if (arg0==0 || *arg0==0) return;
 func_0204e7f0(arg0);
}

s32 func_0204db50(void **arg0) {
 s32 func_0204ec8c(void **,s32);
 if(arg0==0 || *arg0==0) return 2;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) return 0;
 return func_0204ec8c(arg0,0);
}

s32 func_0204db84(void **arg0,s32 arg1,s32 arg2,s32 arg3) {
 void func_02058644(void **,void *);
 extern s32 data_020fda24;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(arg1<0 || arg1>=6) {func_02058644(arg0,&data_020fda24); return 2;}
 p=(char *)p+arg1*8;
 M2C_FIELD(p,s32 *,0x1a4)=arg2;
 M2C_FIELD(p,s32 *,0x1a8)=arg3;
 return 0;
}

void func_0204dcd8(void **arg0) {
    M2C_UNK func_0204e84c(void **);
    M2C_UNK func_02052038(void **, M2C_UNK);
    void *temp_r1;

    if (arg0 != NULL) {
        temp_r1 = *arg0;
        if (temp_r1 != NULL) {
            if (M2C_FIELD(temp_r1, s32 *, 0x108) != 0) {
                return;
            }
            func_02052038(arg0, 1);
            func_0204e84c(arg0);
        }
    }
}

s32 func_0204dd0c(void **p,s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,void (*cb)(void **,s32 *,s32),s32 h){
 s32 func_020560e4(void **,s32,s32,s32,s32,s32,s32,s32,s32,void (*)(void **,s32 *,s32),s32);
 void func_02058644(void **,void *);extern M2C_UNK data_020fda34;
 s32 buf[4];s32 *result;void *q;
 if(!p || !(q=*p))return 2;
 if(!cb){func_02058644(p,&data_020fda34);return 2;}
 if(M2C_FIELD(q,s32 *,0x108)){
 result=buf;
 *(volatile s32 *)(result+2)=0;result[0]=0;result[1]=0;result[3]=0;*(volatile s32 *)(result+2)=0x601;cb(p,result,h);return 0;
 }
 return func_020560e4(p,a,b,c,d,e,f,0,g,cb,h);
}

s32 func_0204ddd4(void **p,s32 a,s32 b,s32 c,void (*cb)(void **,s32 *,s32),s32 d){
s32 func_02053c9c(void **,s32,s32,s32,void (*)(void **,s32 *,s32),s32);
extern M2C_UNK data_020fda34;extern s32 data_020fda48;
void *q;
if(!p || !(q=*p) || !a)return 2;
if(!cb){func_02058644(p,&data_020fda34);return 2;}
if(M2C_FIELD(q,s32 *,0x108)){s32 buf[129]={0};cb(p,buf,d);return 0;}
if(M2C_FIELD(q,s32 *,0x1d8)==4){func_02058644(p,&data_020fda48);return 2;}
return func_02053c9c(p,a,b,c,cb,d);
}

s32 func_0204deb0(void **arg0,s32 arg1,s32 arg2) {
 s32 func_0205342c(void **,s32,s32);
 extern s32 data_020fda48;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {func_02058644(arg0,&data_020fda48);return 2;}
 return func_0205342c(arg0,arg1,arg2);
}

s32 func_0204e074(void **arg0,s32 arg1) {
 s32 func_0204fa60(void **,s32);
 extern s32 data_020fda48;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {func_02058644(arg0,&data_020fda48);return 2;}
 return func_0204fa60(arg0,arg1);
}

s32 func_0204e0c4(void **arg0,s32 arg1) {
 void func_020377c4(s32);
 s32 func_02055b84(void **,s32,void **);
 void func_02055bf4(void **,void *);
 s32 func_02055d6c(void *);
 extern s32 data_020fda48;
 void *sp0;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {func_02058644(arg0,&data_020fda48);return 2;}
 if(func_02055b84(arg0,arg1,&sp0)==0) return 0;
 M2C_FIELD(sp0,s32 *,0x14)--;
 if(M2C_FIELD(p,s32 *,0x100)==0 && M2C_FIELD(sp0,s32 *,0x14)<=0) {
 func_020377c4(M2C_FIELD(sp0,s32 *,0x10));
 M2C_FIELD(sp0,s32 *,0x10)=0;
 if(func_02055d6c(sp0)!=0) func_02055bf4(arg0,sp0);
 }
 return 0;
}

s32 func_0204e184(void **arg0,volatile s32 *arg1) {
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) {*arg1=0; return 0;}
 *arg1=M2C_FIELD(p,s32 *,0x430);
 return 0;
}

s32 func_0204e2f4(void **arg0,s32 arg1,s32 *arg2) {
 s32 func_02055b84(void **,s32,void **);
 void *sp0; s32 *q;
 if(arg0==0 || *arg0==0) return 2;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) {*arg2=0; return 0;}
 if(func_02055b84(arg0,arg1,&sp0)!=0 && (q=M2C_FIELD(sp0,s32 **,8))!=0) *arg2=*q;
 else *arg2=-1;
 return 0;
}

s32 func_0204e364(void **arg0,s32 arg1) {
 s32 func_02055b84(void **,s32,void **);
 void *sp0;
 if(arg0==0 || *arg0==0) return 0;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) return 0;
 if(func_02055b84(arg0,arg1,&sp0)!=0 && M2C_FIELD(sp0,s32 *,8)!=0) return 1;
 return 0;
}

s32 func_0204e3b0(void **arg0,s32 arg1) {
 s32 func_0204fb50(void **,s32);
 extern s32 data_020fda48;
 void *p; s32 result;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {func_02058644(arg0,&data_020fda48);return 2;}
 result=func_0204fb50(arg0,arg1);
 if(result==0) return 0;
 return result;
}

