/* 11 functions from 0x0204C7FC to 0x0204D5C0 (main), found by ds-decomp. */
#include "common.h"
static inline s32 char_outside(s32 c) { s32 bad=1; if(c>=0) { if(c<128)bad=0; } return bad; }
static inline s32 char_space(s32 c) { extern u16 data_020ead40[]; return char_outside(c) ? 0 : (data_020ead40[c] & 256); }

void func_0204ca4c(void *operation) {
    s32 func_02068eac(void *, void *, s32);
    M2C_UNK func_0204a518(void *, s32, s32);
    s32 func_0204a30c(void *);
    void func_0204a2c8(void *);
    M2C_UNK func_0204a740(void *, void *, s32 *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fd88c, data_020fd8a0, data_020fd864, data_020fd804;
    u8 buffer[1024];
    s32 size;

    if (!M2C_FIELD(operation, s32 *, 0x168)) {
        if (!func_02068eac(M2C_FIELD(operation, void **, 0x14), &data_020fd88c, 8)) {
            M2C_FIELD(operation, s32 *, 0xFC) = 1;
            M2C_FIELD(operation, s32 *, 0x38) = 17;
            return;
        }
        M2C_FIELD(operation, s32 *, 0x10) = 3;
        func_0204a518(operation, 0, 0);
        return;
    }
    if (M2C_FIELD(operation, s32 *, 0x170)) {
        M2C_FIELD(operation, s32 *, 0x10) = 3;
        func_0204a518(operation, 0, 0);
        return;
    }
    if (!M2C_FIELD(operation, s32 *, 0x16C) &&
        M2C_FIELD(operation, s32 (**)(void *, void *), 0x174)(operation, (u8 *)operation + 0x164) == 3) {
        func_020640a8(&data_020fd8a0, &data_020fd864, &data_020fd804, 0x146);
        return;
    }
    if (M2C_FIELD(operation, s32 *, 0x60) < M2C_FIELD(operation, s32 *, 0x5C)) {
        if (!func_0204a30c(operation)) return;
        if (M2C_FIELD(operation, s32 *, 0x60) < M2C_FIELD(operation, s32 *, 0x5C)) return;
        func_0204a2c8((u8 *)operation + 0x50);
    }
    size = 1024;
    func_0204a740(operation, buffer, &size);
}

void func_0204ce20(void *arg0) {
    M2C_UNK func_0204a594(void *);
    M2C_UNK func_0204bc64(void *);
    s32 func_0204c300(void *);
 extern M2C_UNK data_020fd864;
 M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
    extern M2C_UNK data_020fd7d0;
    extern M2C_UNK data_020fd93c;
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, s32 *, 0x148);
    temp_r0 = func_0204c300(arg0);
    if (temp_r0 == 0) {
        if ((M2C_FIELD(arg0, s32 *, 0xFC) != 0) && (M2C_FIELD(arg0, s32 *, 0x38) != 0)) {

        } else {
            func_020640a8(&data_020fd93c, &data_020fd864, &data_020fd7d0, 0x200);
        }
        func_0204bc64(arg0);
        return;
    }
    if (temp_r5 != M2C_FIELD(arg0, s32 *, 0x148)) {
        func_0204a594(arg0);
    }
    if (temp_r0 != 1) {
        return;
    }
    func_0204bc64(arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = 5;
    func_0204a518(arg0, 0, 0);
}

void func_0204ceb8(void *arg0) {
    s32 PollOneFd(s32, s32 *, M2C_UNK, M2C_UNK);
    s32 func_02049900(s32);
    M2C_UNK func_0204a518(void *, M2C_UNK, M2C_UNK);
    s32 sp0;

    if (PollOneFd(M2C_FIELD(arg0, s32 *, 0x48), &sp0, 0, 0) == -1) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 5;
        M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
        return;
    }
    if (sp0 == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = 6;
    func_0204a518(arg0, 0, 0);
}

s32 func_0204cf38(void *a){
extern M2C_UNK data_020fd858,data_020fd864,data_020fd7e0,data_020fd968,data_020fd988;
extern u16 data_020ead40[];
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
s32 func_02068adc(void *,M2C_UNK *,...);
s32 major,minor,status,pos,n,ch;
if(!a)func_020640a8(&data_020fd858,&data_020fd864,&data_020fd7e0,590);
if(M2C_FIELD(a,s32 *,128)<=0)func_020640a8(&data_020fd968,&data_020fd864,&data_020fd7e0,591);
n=func_02068adc(M2C_FIELD(a,void **,120),&data_020fd988,&major,&minor,&status,&pos);
while((ch=M2C_FIELD(M2C_FIELD(a,void **,120),s8 *,pos))!=0 && char_space(ch))pos++;
if(n!=3 || major<1 || status<100 || status>=600){
M2C_FIELD(a,s32 *,252)=1;M2C_FIELD(a,s32 *,56)=7;return 0;
}
M2C_FIELD(a,s32 *,228)=major;M2C_FIELD(a,s32 *,232)=minor;M2C_FIELD(a,s32 *,236)=status;M2C_FIELD(a,s32 *,240)=pos;return 1;
}

void func_0204d084(void *a){
s32 func_0204a740(void *,void *,s32 *);s32 func_02049ef4();s32 func_0204cf38(void *);
s32 func_02049900(s32);u8 *func_02068fdc(s32,M2C_UNK *);
extern M2C_UNK data_020fd8d8;
u8 buf[1024];s32 len=1024; s32 n,off;u8 *p;
n=func_0204a740(a,buf,&len);
if(n==3)return;
if(n==1 && M2C_FIELD(a,s32 *,132)==M2C_FIELD(a,s32 *,128))return;
if(n==0 && !func_02049ef4((u8 *)a+116,buf,len))return;
p=func_02068fdc(M2C_FIELD(a,s32 *,120),&data_020fd8d8);
if(p){
*p=0;off=p-M2C_FIELD(a,u8 **,120);
M2C_FIELD(a,s32 *,248)=off+1;
if(!func_0204cf38(a))return;
M2C_FIELD(a,s32 *,132)=off+2;
M2C_FIELD(a,s32 *,16)=7;
func_0204a518(a,0,0);return;
}
if(n!=2)return;
M2C_FIELD(a,s32 *,252)=1;
M2C_FIELD(a,s32 *,56)=7;
M2C_FIELD(a,s32 *,76)=func_02049900(M2C_FIELD(a,s32 *,72));
}

s32 func_0204d1ac(void *arg0,s32 arg1,s32 arg2) {
 s32 func_02049ef4();
 M2C_UNK func_0204a518(void *,s32,s32);
 s32 a=0,b=0;
 s32 c=M2C_FIELD(arg0,s32 *,0x100)+arg2;
 M2C_FIELD(arg0,s32 *,0x100)=c;
 if(c==M2C_FIELD(arg0,s32 *,0x104)||M2C_FIELD(arg0,s32 *,0x130)) M2C_FIELD(arg0,s32 *,0xFC)=1;
 if(M2C_FIELD(arg0,s32 *,0xC)==0) {
 if(!func_02049ef4(arg0+0xBC)) return 0;
 a=M2C_FIELD(arg0,s32 *,0xC0); b=M2C_FIELD(arg0,s32 *,0xC8);
 } else if(M2C_FIELD(arg0,s32 *,0xC)==1) {
 if(arg2) { M2C_FIELD(arg0,s32 *,0xFC)=1; M2C_FIELD(arg0,s32 *,0x38)=13; return 0; }
 a=arg1;b=arg2;
 } else if(M2C_FIELD(arg0,s32 *,0xC)==2) {a=arg1;b=arg2;}
 func_0204a518(arg0,a,b); return 1;
}

s32 func_0204d26c(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 func_02068adc(void *, M2C_UNK *, ...);
    extern M2C_UNK data_020fd7f0;
    extern M2C_UNK data_020fd864;
    extern M2C_UNK data_020fd998;
    extern M2C_UNK data_020fd99c;
    s32 sp0;

    if (M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        func_020640a8(&data_020fd998, &data_020fd864, &data_020fd7f0, 0x321);
    }
    if (func_02068adc(arg0 + 0x114, &data_020fd99c, &sp0) != 1) {
        return -1;
    }
    return sp0;
}

void func_0204d2d0(void *p,void *src,s32 n) {
extern M2C_UNK data_020fd858,data_020fd864,data_020fd838,data_020fd9a0,data_020fd9a8;
s32 left;
if(!p)func_020640a8(&data_020fd858,&data_020fd864,&data_020fd838,0x333);
if(!src)func_020640a8(&data_020fd9a0,&data_020fd864,&data_020fd838,0x334);
if(n<0)func_020640a8(&data_020fd9a8,&data_020fd864,&data_020fd838,0x335);
if(!n)return;
if(M2C_FIELD(p,s32 *,0x120)>=10)return;
left=10-M2C_FIELD(p,s32 *,0x120);
if(left>=n)left=n;
func_020651a4((u8 *)p+0x114+M2C_FIELD(p,s32 *,0x120),src,left);
M2C_FIELD(p,s32 *,0x120)+=left;
*((u8 *)p+M2C_FIELD(p,s32 *,0x120)+0x114)=0;
}

