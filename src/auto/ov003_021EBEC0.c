/* 8 functions from 0x021EBEC0 to 0x021ECCD4 (ov003), found by ds-decomp. */
#include "common.h"
#pragma opt_propagation off
static inline s32 ov003_entries_differ(s32 arg0) {
 s32 count; s32 entry; u8 i;
 i=0; count=M2C_FIELD(arg0,s8*,4)-1;
 for(;i<count;i++){entry=arg0+i*24; if(M2C_FIELD(entry,s32*,0x18)!=M2C_FIELD(entry,s32*,0x30))return 1;}
 return 0;
}

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

void func_ov003_021ec57c(void *arg0, s32 unused_arg1) {
    M2C_UNK func_0208b758(s32, s32);
    void func_0208fe30(u32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    s32 func_ov003_021e6cac(u8, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021e6ef4();
    s16 func_ov003_022004a8(u8);
    s32 temp_r3;
    s32 temp_r4_2;
    s32 var_r0;
    s32 var_r1;
    u16 temp_r0;
    u32 temp_r0_2;
    u8 temp_r4;
    void *temp_r0_3;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r6;

    temp_r4 = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
    func_ov003_021e6ef4();
    if (temp_r4 == (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E)) {
        return;
    }
    func_0208fe30(0x10019);
    temp_r6 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0);
    temp_r4_2 = func_020aae44(temp_r6);
    temp_r3 = func_020aae10(temp_r6) & (-0x200U >> 0x17);
    temp_r1 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_r1, s16 *, 0x34) = (s16) M2C_FIELD(temp_r6, s16 *, 0x34);
    M2C_FIELD(temp_r1, s16 *, 0x36) = (s16) M2C_FIELD(temp_r6, s16 *, 0x36);
    M2C_FIELD(temp_r1, s32 *, 0x40) = (s32) ((((M2C_FIELD(temp_r1, s32 *, 0x40) & ~0x1FF) | temp_r3) & 0xFFFC01FF) | ((u32) (temp_r4_2 << 0x17) >> 0xE));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
        temp_r0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
        if (func_ov003_021e6cac((u8) temp_r0, 0, 3) != 0) {
            func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
        } else if (func_ov003_021e6cac((u8) temp_r0, 4, 7) != 0) {
            func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000012);
        } else if (func_ov003_021e6cac((u8) temp_r0, 8, 0x14) != 0) {
            func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
        } else if (func_ov003_021e6cac((u8) temp_r0, 0x15, 0x18) != 0) {
            func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000010);
        } else if ((u8) temp_r0 == 0x19) {
            temp_r0_2 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E;
            if (temp_r0_2 == 0) {
                var_r1 = 1;
            } else {
                var_r1 = 0;
            }
            if (var_r1 & 0xFF) {
                func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000016);
            } else {
                if (temp_r0_2 == 1) {
                    var_r0 = 1;
                } else {
                    var_r0 = 0;
                }
                if (var_r0 & 0xFF) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000017);
                }
            }
        }
    }
    temp_r0_3 = M2C_FIELD(arg0, void **, 0x6C);
    temp_r1_2 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r1_2, u8 *, 0x10) = (u8) M2C_FIELD(temp_r0_3, u8 *, 7);
    M2C_FIELD(temp_r1_2, u8 *, 0x11) = (u8) M2C_FIELD(temp_r0_3, u8 *, 8);
    M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) | 8);
}

void func_ov003_021ec780(u8 *p,s32 i) {p+=14;p[i]=p[i]==1?2:1;}

s32 func_ov003_021e6cac(u8,s32,s32);
void func_ov003_021e8654(s32,s32,s32);
s32 func_ov003_021e8308(void*);
#pragma inline on
#pragma opt_propagation on
void func_ov003_021ec79c(void *arg0,s32 arg1,s32 arg2){s32 n=M2C_FIELD(arg0+0x18,s32*,arg1*24)-1;
if(((s32 (*)(s16,s16,s16))func_ov003_021e6cac)((s16)n,(s16)M2C_FIELD(arg0+0x20,s32*,arg1*24),(s16)M2C_FIELD(arg0+0x1c,s32*,arg1*24))||arg2){M2C_FIELD(arg0+0x18,s32*,arg1*24)=n;if (((u8 (*)[24])arg0)[arg1][0x28]) {
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)-=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)>M2C_FIELD(p,s32*,0x1c));}
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)+=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)<M2C_FIELD(p,s32*,0x20));}
} else {
M2C_FIELD(arg0+0x18,s32*,arg1*24)=M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)?M2C_FIELD(arg0+0x1c,s32*,arg1*24):(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)?M2C_FIELD(arg0+0x20,s32*,arg1*24):M2C_FIELD(arg0+0x18,s32*,arg1*24));
}}else{
if(n>M2C_FIELD(arg0+0x1c,s32*,arg1*24))n=M2C_FIELD(arg0+0x1c,s32*,arg1*24);else n=n<M2C_FIELD(arg0+0x20,s32*,arg1*24)?M2C_FIELD(arg0+0x20,s32*,arg1*24):n;
M2C_FIELD(arg0+0x18,s32*,arg1*24)=n;if (((u8 (*)[24])arg0)[arg1][0x28]) {
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)-=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)>M2C_FIELD(p,s32*,0x1c));}
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)+=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)<M2C_FIELD(p,s32*,0x20));}
} else {
M2C_FIELD(arg0+0x18,s32*,arg1*24)=M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)?M2C_FIELD(arg0+0x1c,s32*,arg1*24):(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)?M2C_FIELD(arg0+0x20,s32*,arg1*24):M2C_FIELD(arg0+0x18,s32*,arg1*24));
}}
if(ov003_entries_differ(arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,-1,arg2);
if(ov003_entries_differ(arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,-1,arg2);
if(func_ov003_021e8308((void*)arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,-1,arg2);
if(func_ov003_021e8308((void*)arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,-1,arg2);
if(func_ov003_021e8308((void*)arg0))return;func_ov003_021ec79c(arg0,arg1,arg2);}
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

