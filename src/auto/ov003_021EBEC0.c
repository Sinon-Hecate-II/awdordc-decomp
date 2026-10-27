/* 8 functions from 0x021EBEC0 to 0x021ECCD4 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021ec4e4(u8 *);
#pragma inline off
void func_ov003_021ebec0(void *p,u32 state){
void func_0208fe30(u32);void func_ov003_021ebfcc(void *);s32 func_ov003_021ebc38(void *);void func_ov003_021e9cfc(void *,s32);void func_ov003_021ec4e4(u8 *);void func_ov003_021ec57c(void *,s32);
func_0208fe30(0x1000f);
switch(state){
case 25:case 3:case 2:case 1:case 0:func_ov003_021ebfcc(p);break;
case 4:case 5:case 6:case 7:
if(func_ov003_021ebc38(p))func_ov003_021ebfcc(p);else func_ov003_021e9cfc(p,0);break;
case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:
func_ov003_021ec4e4(M2C_FIELD(p,u8 **,0x6c));func_ov003_021e9cfc(p,0);func_ov003_021ec57c(p,27);break;
case 21:case 22:case 23:case 24:
if(func_ov003_021ebc38(p))func_ov003_021ebfcc(p);else func_ov003_021e9cfc(p,0);break;
}
}
void func_ov003_021ec4e4(u8 *p) {
s32 func_020848c4(void);
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6d28(void);
s32 func_ov003_021e6eb8(u8);
u8 v=p[9];
u8 t;
if(func_ov003_021e6cfc()!=0) {
t=(p+p[7])[0x74];
if(t!=func_020848c4()) {
if((u8)((p+p[7])[0x74]==255)==0)goto update;
}
}
if(func_ov003_021e6d28()!=0) {
t=(p+p[7])[0x74];
if(t!=func_020848c4())goto update;
}
if(func_ov003_021e6eb8(v)==0)return;
update:
(p+p[7])[10]=v;
p[8]=v;
}

void func_ov003_021ec780(u8 *p,s32 i) {p+=14;p[i]=p[i]==1?2:1;}

void func_ov003_021eca9c(void *arg0, u32 arg1) {
    s32 func_020846a4();
    void func_0208fe30(u32);
    s32 func_ov003_021e6eb8(u8);
    s32 func_ov003_021e73e4(s32);
    s32 func_ov003_021e73ec(s32, s32);
    void func_ov003_021e9cfc(void *,s32);
    s32 func_ov003_021ebc38(void *);
    void func_ov003_021ec57c(void *,s32);
    s32 func_ov003_021ecc68(M2C_UNK,M2C_UNK);
    M2C_UNK func_ov003_021eccd4(void *);
    if (func_ov003_021ecc68((s32)arg0,arg1) == 0) {
        return;
    }
    switch (arg1) {
    case 0:
    case 1:
    case 2:
    case 3:
        if ((func_020846a4() != 0) && (func_ov003_021e73ec(M2C_FIELD(arg0, s32 *, 0x6C), func_ov003_021e73e4(M2C_FIELD(arg0, s32 *, 0x6C))) == 0)) {
            func_0208fe30(0x1001D);
            return;
        }
        if (func_ov003_021ebc38(arg0) != 0) {
            func_ov003_021e9cfc(arg0, 2);
            func_ov003_021ec57c(arg0, 0x1DU);
        } else {
            func_ov003_021ec57c(arg0, arg1);
            func_ov003_021e9cfc(arg0, 0);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        func_ov003_021ec57c(arg0, arg1);
        if (func_ov003_021ebc38(arg0) != 0) {
            func_ov003_021e9cfc(arg0, 1);
        } else {
            func_ov003_021e9cfc(arg0, 0);
        }
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        if (func_ov003_021e6eb8((u8) (arg1 - 8)) == 0) {
            func_0208fe30(0x1001D);
            return;
        }
        func_ov003_021e9cfc(arg0, 0);
        func_ov003_021ec57c(arg0, 0x1BU);
        break;
    case 21:
    case 22:
    case 23:
    case 24:
        func_ov003_021ec57c(arg0, arg1);
        if (func_ov003_021ebc38(arg0) != 0) {
            func_ov003_021e9cfc(arg0, 3);
        } else {
            func_ov003_021e9cfc(arg0, 0);
        }
        break;
    case 25:
        func_ov003_021eccd4(arg0);
        break;
    default:break;
    }
    func_0208fe30(0x1000D);
}

s32 func_ov003_021ecc68(M2C_UNK a,M2C_UNK b) {
s32 func_020846a4(void);
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6e08(M2C_UNK);
M2C_UNK func_ov003_021e6e18(M2C_UNK);
s32 t;
if(func_020846a4()==0)return 1;
t=func_ov003_021e6e08(b);
func_ov003_021e6e18(b);
if(t==0||t==25||t==8)return 1;
if(t==4)return 0;
if(func_ov003_021e6cfc()!=0 && t==21)return 1;
return 0;
}

