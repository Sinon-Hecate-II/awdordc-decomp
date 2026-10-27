/* 19 functions from 0x0204AA34 to 0x0204B9B8 (main), found by ds-decomp. */
#include "common.h"

s32 func_0204aa34(void) {
extern M2C_UNK data_0213dcac,data_020fd068,data_020fd090,data_020fd014;
s32 i, newCount, oldCount; void *p;
for(i=0;i<M2C_FIELD(&data_0213dcac,s32 *,12);i++) {
if(M2C_FIELD(M2C_FIELD(&data_0213dcac,void ***,4)[i],s32 *,0)==0)return i;
}
if(M2C_FIELD(&data_0213dcac,s32 *,0)!=M2C_FIELD(&data_0213dcac,s32 *,12))
func_020640a8(&data_020fd068,&data_020fd090,&data_020fd014,0x33);
oldCount=M2C_FIELD(&data_0213dcac,s32 *,12);
newCount=oldCount+4;
p=func_020377a8(M2C_FIELD(&data_0213dcac,void **,4),newCount*4);
if(p==NULL)return -1;
M2C_FIELD(&data_0213dcac,void **,4)=p;
for(i=oldCount;i<newCount;i++){
M2C_FIELD(&data_0213dcac,void ***,4)[i]=func_02037794(0x184);
p=M2C_FIELD(&data_0213dcac,void ***,4)[i];
if(p==NULL){
for(--i;i>=oldCount;--i)func_020377c4(M2C_FIELD(&data_0213dcac,void ***,4)[i]);
return -1;
}
M2C_FIELD(p,s32 *,0)=0;
}
M2C_FIELD(&data_0213dcac,s32 *,12)=newCount;
return oldCount;
}

void *func_0204ab50(void) {
extern M2C_UNK data_0213dcac;
M2C_UNK func_0204a610(); M2C_UNK func_0204a614();
s32 func_02049c7c(void *,void *,s32,s32);
s32 func_0204ace8(void *);
s32 i; void *p;
func_0204a610(); i=func_0204aa34();
if(i==-1){func_0204a614();return NULL;}
p=M2C_FIELD(&data_0213dcac,void ***,4)[i];
func_02065210(p,0,0x184);
M2C_FIELD(p,volatile s32 *,0)=1;
M2C_FIELD(p,volatile s32 *,4)=i;
M2C_FIELD(p,s32 *,8)=M2C_FIELD(&data_0213dcac,s32 *,8)++;
M2C_FIELD(p,s32 *,12)=0;
M2C_FIELD(p,s32 *,16)=0;
M2C_FIELD(p,s32 *,20)=0;
M2C_FIELD(p,s32 *,24)=0;
M2C_FIELD(p,s32 *,28)=0;
M2C_FIELD(p,s16 *,0x20)=0;
M2C_FIELD(p,s32 *,36)=0;
M2C_FIELD(p,s32 *,40)=0;
M2C_FIELD(p,s32 *,44)=0;
M2C_FIELD(p,s32 *,48)=0;
M2C_FIELD(p,s32 *,52)=0;
M2C_FIELD(p,s32 *,56)=0;
M2C_FIELD(p,s32 *,60)=0;
M2C_FIELD(p,s32 *,64)=0;
M2C_FIELD(p,s32 *,68)=0;
M2C_FIELD(p,s32 *,0x48)=-1;
M2C_FIELD(p,s32 *,76)=0;
M2C_FIELD(p,s32 *,224)=0;
M2C_FIELD(p,s32 *,228)=0;
M2C_FIELD(p,s32 *,232)=0;
M2C_FIELD(p,s32 *,236)=0;
M2C_FIELD(p,s32 *,240)=0;
M2C_FIELD(p,s32 *,244)=0;
M2C_FIELD(p,s32 *,248)=0;
M2C_FIELD(p,s32 *,252)=0;
M2C_FIELD(p,s32 *,256)=0;
M2C_FIELD(p,s32 *,0x104)=-1;
M2C_FIELD(p,s32 *,264)=0;
M2C_FIELD(p,s32 *,268)=0;
M2C_FIELD(p,s32 *,272)=0;
M2C_FIELD(p,s32 *,300)=0;
M2C_FIELD(p,s32 *,308)=0;
M2C_FIELD(p,s32 *,312)=0;
M2C_FIELD(p,s32 *,316)=0;
M2C_FIELD(p,s32 *,0x158)=500;
M2C_FIELD(p,s16 *,0x160)=80;
M2C_FIELD(p,s32 *,0x15c)=0;
M2C_FIELD(p,s32 *,0x164)=0;
if(!func_02049c7c(p,p+0x50,0x800,0x1000) ||
!func_02049c7c(p,p+0x74,0x800,0x800) ||
!func_02049c7c(p,p+0x98,0x800,0x400)){
((void (*)(void *))&func_0204ace8)(p);func_0204a614();return NULL;
}
M2C_FIELD(&data_0213dcac,s32 *,0)++;
func_0204a614();return p;
}

s32 func_0204ace8(void *obj) {
extern M2C_UNK data_020fd0a4,data_020fd090,data_020fd024,data_020fd0b0,data_0213dcac,data_020fd0cc,data_020fd0f4;
M2C_UNK func_0204a610(); M2C_UNK func_0204a614(); M2C_UNK func_020496cc(s32,M2C_UNK); M2C_UNK func_020496b8(s32);
void func_02049e94(void *); void func_0204bc64(void *); s32 func_0204b688(void *); void func_0204b690(s32 *);
if(!obj)func_020640a8(&data_020fd0a4,&data_020fd090,&data_020fd024,0xb3);
if(M2C_FIELD(obj,s32 *,4)<0)func_020640a8(&data_020fd0b0,&data_020fd090,&data_020fd024,0xb4);
if(M2C_FIELD(obj,s32 *,4)>=M2C_FIELD(&data_0213dcac,s32 *,12))func_020640a8(&data_020fd0cc,&data_020fd090,&data_020fd024,0xb5);
if(!M2C_FIELD(obj,s32 *,0))func_020640a8(&data_020fd0f4,&data_020fd090,&data_020fd024,0xb6);
if(!obj)return 0; if(!M2C_FIELD(obj,s32 *,0))return 0; if(M2C_FIELD(obj,s32 *,4)<0)return 0; if(M2C_FIELD(obj,s32 *,4)>=M2C_FIELD(&data_0213dcac,s32 *,12))return 0;
func_0204a610();
func_020377c4(M2C_FIELD(obj,s32 *,20));func_020377c4(M2C_FIELD(obj,s32 *,24));func_020377c4(M2C_FIELD(obj,s32 *,36));func_020377c4(M2C_FIELD(obj,s32 *,40));func_020377c4(M2C_FIELD(obj,s32 *,264));func_020377c4(M2C_FIELD(obj,s32 *,348));
if(M2C_FIELD(obj,s32 *,72)!=-1){func_020496cc(M2C_FIELD(obj,s32 *,72),2);func_020496b8(M2C_FIELD(obj,s32 *,72));}
func_02049e94(obj+0x50);func_02049e94(obj+0x74);func_02049e94(obj+0x98);func_02049e94(obj+0xbc);
if(M2C_FIELD(obj,s32 *,0x140))func_0204bc64(obj);
if(M2C_FIELD(obj,void **,0x13c) && func_0204b688(M2C_FIELD(obj,void **,0x13c))){func_0204b690(M2C_FIELD(obj,s32 **,0x13c));M2C_FIELD(obj,s32 *,0x13c)=0;}
if(M2C_FIELD(obj,s32 *,0x16c)){if(M2C_FIELD(obj,void **,0x178)) M2C_FIELD(obj,void (**)(void *,void *),0x178)(obj,obj+0x164);M2C_FIELD(obj,s32 *,0x16c)=0;}
{s32 *counts=&data_0213dcac; M2C_FIELD(obj,s32 *,0)=0; (*counts)--;}func_0204a614();return 1;
}

void *func_0204aecc(s32 arg0) {
 extern M2C_UNK data_020fd108, data_020fd090, data_020fd050, data_020fd118, data_0213dcac;
 M2C_UNK func_0204a610(); M2C_UNK func_0204a614();
 void *p;
 if(arg0<0) func_020640a8(&data_020fd108,&data_020fd090,&data_020fd050,0x101);
 if(arg0>=M2C_FIELD(&data_0213dcac,s32 *,12)) func_020640a8(&data_020fd118,&data_020fd090,&data_020fd050,0x102);
 func_0204a610();
 if(arg0<0 || arg0>=M2C_FIELD(&data_0213dcac,s32 *,12)) {func_0204a614();return NULL;}
 p=M2C_FIELD(&data_0213dcac,void ***,4)[arg0];
 if(M2C_FIELD(p,s32 *,0)==0) p=NULL;
 func_0204a614(); return p;
}

void func_0204af74(M2C_UNK *arg0) {
 extern M2C_UNK data_0213dcac;
 M2C_UNK func_0204a610(); M2C_UNK func_0204a614();
 s32 i; void *p;
 if(M2C_FIELD(&data_0213dcac,s32 *,0)<=0) return;
 func_0204a610();
 for(i=0;i<M2C_FIELD(&data_0213dcac,s32 *,12);i++) {
 p=M2C_FIELD(&data_0213dcac,void ***,4)[i];
 if(M2C_FIELD(p,s32 *,0)!=0) ((void (*)(void *))arg0)(p);
 }
 func_0204a614();
}

/* Reset and release an object's resources and counters, logging if null/empty. */
void func_0204afd8(void *obj) {
    M2C_UNK func_020496b8(s32);
    M2C_UNK func_020496cc(s32, M2C_UNK);
    M2C_UNK func_0204a2c8(void *);
    extern M2C_UNK data_020fd038;
    extern M2C_UNK data_020fd090;
    extern M2C_UNK data_020fd0a4;
    extern M2C_UNK data_020fd134;
    if (obj == NULL) {
        func_020640a8(&data_020fd0a4, &data_020fd090, &data_020fd038, 0x132);
    }
    if (M2C_FIELD(obj, s32 *, 0x108) == 0) {
        func_020640a8(&data_020fd134, &data_020fd090, &data_020fd038, 0x133);
    }
    M2C_FIELD(obj, s32 *, 0x10) = 0;
    func_020377c4(M2C_FIELD(obj, s32 *, 0x14));
    M2C_FIELD(obj, s32 *, 0x14) = (s32) M2C_FIELD(obj, s32 *, 0x108);
    M2C_FIELD(obj, s32 *, 0x108) = 0;
    func_020377c4(M2C_FIELD(obj, s32 *, 0x18));
    M2C_FIELD(obj, s32 *, 0x18) = 0;
    M2C_FIELD(obj, s32 *, 0x1C) = 0;
    M2C_FIELD(obj, s16 *, 0x20) = 0;
    func_020377c4(M2C_FIELD(obj, s32 *, 0x24));
    M2C_FIELD(obj, s32 *, 0x24) = 0;
    func_020496cc(M2C_FIELD(obj, s32 *, 0x48), 2);
    func_020496b8(M2C_FIELD(obj, s32 *, 0x48));
    M2C_FIELD(obj, s32 *, 0x48) = -1;
    func_0204a2c8(obj + 0x50);
    func_0204a2c8(obj + 0x74);
    func_0204a2c8(obj + 0x98);
    M2C_FIELD(obj, s32 *, 0xE4) = 0;
    M2C_FIELD(obj, s32 *, 0xE8) = 0;
    M2C_FIELD(obj, s32 *, 0xEC) = 0;
    M2C_FIELD(obj, s32 *, 0xF0) = 0;
    M2C_FIELD(obj, s32 *, 0xF4) = 0;
    M2C_FIELD(obj, s32 *, 0xF8) = 0;
    M2C_FIELD(obj, s32 *, 0x130) = 0;
    M2C_FIELD(obj, s32 *, 0x10C) = (s32) (M2C_FIELD(obj, s32 *, 0x10C) + 1);
}

void func_0204b0dc(void) {
 extern M2C_UNK data_0213dcac; s32 func_0204ace8(void *);
 void func_0204af74(M2C_UNK *);
 s32 i;
 if(M2C_FIELD(&data_0213dcac,void **,4)==NULL)return;
 func_0204af74((M2C_UNK *)func_0204ace8);
 for(i=0;i<M2C_FIELD(&data_0213dcac,s32 *,12);i++) func_020377c4(M2C_FIELD(&data_0213dcac,void ***,4)[i]);
 func_020377c4(M2C_FIELD(&data_0213dcac,void **,4));
 M2C_FIELD(&data_0213dcac,void **,4)=NULL;
 M2C_FIELD(&data_0213dcac,s32 *,12)=0;
 M2C_FIELD(&data_0213dcac,s32 *,0)=0;
}

void func_0204b154(void *arg0) {
 s32 v=M2C_FIELD(arg0,s32 *,0xec);
 switch(v/100) {
 case 0: break;
 case 1: case 2: case 3: return;
 case 4:
 switch(v) {
 case 401: M2C_FIELD(arg0,s32 *,0x38)=9;return;
 case 403: M2C_FIELD(arg0,s32 *,0x38)=10;return;
 case 404: case 410: M2C_FIELD(arg0,s32 *,0x38)=11;return;
 default: M2C_FIELD(arg0,s32 *,0x38)=8;return;
 } 
 case 5: M2C_FIELD(arg0,s32 *,0x38)=12;return;
 }
}

void func_0204c738(void *);
void func_0204c7fc(void *);
void func_0204ca4c(void *);
void func_0204cbac(void *);
void func_0204ce20(void *);
void func_0204ceb8(void *);
void func_0204d084(void *);
void func_0204d5c0(void *);
void func_0204da30(void *);
/* Run one tick of an async operation/state machine: validate the handle, dispatch by its kind, then settle (signal completion and release the handle) unless it is still busy. */
s32 func_0204b210(void *operation) {
    extern M2C_UNK data_020fd170, data_020fd17c, data_020fd158, data_020fd188;
    void func_0204a498(void *);
    s32 func_0204ace8(void *);
    s32 status;

    if (!operation) func_020640a8(&data_020fd170, &data_020fd17c, &data_020fd158, 0x5B);
    if (func_0204aecc(M2C_FIELD(operation, s32 *, 4)) != operation)
        func_020640a8(&data_020fd188, &data_020fd17c, &data_020fd158, 0x5C);
    if (M2C_FIELD(operation, s32 *, 0x12C)) return 0;
    M2C_FIELD(operation, s32 *, 0x12C) = 1;
    if (M2C_FIELD(operation, s32 *, 0x10) == 0) func_0204c738(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 1) func_0204c7fc(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 2) func_0204ca4c(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 3) func_0204cbac(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 4) func_0204ce20(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 5) func_0204ceb8(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 6) func_0204d084(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 7) func_0204d5c0(operation);
    if (M2C_FIELD(operation, s32 *, 0x10) == 8) func_0204da30(operation);
    if (M2C_FIELD(operation, s32 *, 0x108)) func_0204afd8(operation);
    status = M2C_FIELD(operation, s32 *, 0xFC);
    if (status == 0)
        M2C_FIELD(operation, s32 *, 0x12C) = 0;
    else {
        func_0204b154(operation);
        func_0204a498(operation);
        func_0204ace8(operation);
    }
    return status;
}

void func_0204b378(void) {
 M2C_UNK func_0204a608(); M2C_UNK func_0204a610(); M2C_UNK func_0204a614();
 extern s32 data_020fd00c, data_020fd010, data_0213dcbc;
 func_0204a610();
 if (++data_0213dcbc == 1) { func_0204a608(); data_020fd010=125; data_020fd00c=250; return; }
 func_0204a614();
}

void func_0204b3cc(void) {
    M2C_UNK func_0204a60c();
    M2C_UNK func_0204a610();
    M2C_UNK func_0204a614();
    void func_0204b0dc();
    extern s32 data_0213dca8;
    extern s32 data_0213dcbc;
    s32 temp_r1;

    func_0204a610();
    temp_r1 = data_0213dcbc - 1;
    data_0213dcbc = temp_r1;
    if (temp_r1 == 0) {
        func_0204b0dc();
        if (data_0213dca8 != 0) {
            func_020377c4();
            data_0213dca8 = 0;
        }
        func_0204a614();
        func_0204a60c();
        return;
    }
    func_0204a614();
}

void func_0204b674(void) {
    void func_0204af74(M2C_UNK *);
    s32 func_0204b210(void *);
    func_0204af74((M2C_UNK *)func_0204b210);
}

s32 func_0204b688(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x10);
}

void func_0204b690(s32 *arg0) {
    M2C_UNK func_020377c4(s32 *);
    M2C_UNK func_0204861c(s32);
    func_0204861c(*arg0);
    func_020377c4(arg0);
}

M2C_UNK *func_0204b6ac(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fd264;
    extern M2C_UNK data_020fd334;
    extern M2C_UNK data_020fd384;
    extern M2C_UNK data_020fd38c;
    extern M2C_UNK data_020fd390;
    extern M2C_UNK data_020fd3d4;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x13C);
    if (temp_r4 == NULL) {
        func_020640a8(&data_020fd384, &data_020fd334, &data_020fd264, 0x192);
    }
    if (temp_r4 == NULL) {
        return &data_020fd38c;
    }
    if (M2C_FIELD(temp_r4, s32 *, 0xC) != 0) {
        return &data_020fd390;
    }
    return &data_020fd3d4;
}

s32 func_0204b70c(void *arg0) {
 s32 func_02048688(s32); void *func_02048690(s32,s32); s32 func_02068c34(s32);
 extern M2C_UNK data_020fd3f8,data_020fd334,data_020fd2d0;
 void *p=M2C_FIELD(arg0,void **,0x13c); void *q; s32 i,n,total=0;
 n=func_02048688(M2C_FIELD(p,s32 *,0));
 if(n==0)return total;
 for(i=0;i<n;i++) {
 q=func_02048690(M2C_FIELD(p,s32 *,0),i);
 if(M2C_FIELD(q,s32 *,0)!=0)func_020640a8(&data_020fd3f8,&data_020fd334,&data_020fd2d0,0x1b0);
 total += func_02068c34(M2C_FIELD(q,s32 *,4)); total += M2C_FIELD(q,s32 *,12); total += M2C_FIELD(q,s32 *,20)*2; total++;
 }
 return total+(n-1);
}

s32 func_0204b7b8(void *obj) {
s32 func_02068c34(s32); s32 func_02048688(s32); void *func_02048690(s32,s32);
extern M2C_UNK data_020fd334; extern s32 data_0213dcc0[]; extern u8 data_020fd410[],data_020fd438[],data_020fd310[],data_020fd330[];
void *p=M2C_FIELD(obj,void **,0x13c); void *q; s32 i,count; s32 total=0;
if(!data_0213dcc0[2]){s32 n=func_02068c34((s32)data_020fd410);data_0213dcc0[2]=n;data_0213dcc0[1]=n+47;data_0213dcc0[3]=n+76;data_0213dcc0[0]=n+4;}
count=func_02048688(M2C_FIELD(p,s32 *,0));
for(i=0;i<count;i++){
q=func_02048690(M2C_FIELD(p,s32 *,0),i);
if(M2C_FIELD(q,s32 *,0)==0){
total+=data_0213dcc0[1];total+=func_02068c34(M2C_FIELD(q,s32 *,4));total+=M2C_FIELD(q,s32 *,12);
}else if(M2C_FIELD(q,s32 *,0)==1){
total+=data_0213dcc0[3];total+=func_02068c34(M2C_FIELD(q,s32 *,4));total+=func_02068c34(M2C_FIELD(q,s32 *,12));total+=func_02068c34(M2C_FIELD(q,s32 *,16));
q=func_02048690(M2C_FIELD(obj,s32 *,0x140),i);if(!q)func_020640a8(data_020fd438,&data_020fd334,data_020fd310,0x1ec);total+=M2C_FIELD(q,s32 *,12);
}else if(M2C_FIELD(q,s32 *,0)==2){
total+=data_0213dcc0[3];total+=func_02068c34(M2C_FIELD(q,s32 *,4));total+=func_02068c34(M2C_FIELD(q,s32 *,16));total+=func_02068c34(M2C_FIELD(q,s32 *,20));total+=M2C_FIELD(q,s32 *,12);
}else {func_020640a8(data_020fd330,&data_020fd334,data_020fd310,0x1f9);return 0;}
}
return total+data_0213dcc0[0];
}

s32 func_0204b958(void *arg0) {
 s32 func_0204b7b8(void *); s32 func_0204b70c(void *);
 extern M2C_UNK data_020fd384,data_020fd334,data_020fd27c;
 void *p=M2C_FIELD(arg0,void **,0x13c);
 if(p==NULL)func_020640a8(&data_020fd384,&data_020fd334,&data_020fd27c,0x20c);
 if(p==NULL)return 0;
 if(M2C_FIELD(p,s32 *,12)!=0)return func_0204b7b8(arg0);
 return func_0204b70c(arg0);
}

