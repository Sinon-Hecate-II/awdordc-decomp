/* 5 functions from 0x021E771C to 0x021E8654 (ov003), found by ds-decomp. */
#include "common.h"

static inline s32 ov003_entries_differ(void *arg0) {
 s32 count; s32 entry; u8 i;
 count=M2C_FIELD(arg0,s8*,4)-1; i=0;
 for(;i<count;i++){entry=arg0+i*24; if(M2C_FIELD(entry,s32*,0x18)!=M2C_FIELD(entry,s32*,0x30))return 1;}
 return 0;
}

void func_ov003_021e771c(void *arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
}

void func_ov003_021e82f0(s32 arg0, s32 arg1, s8 arg2) {
    M2C_FIELD((arg0 + arg1), s8 *, 0xA) = arg2;
}

u8 func_ov003_021e82fc(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 0xA);
}

s32 func_ov003_021e8308(void *arg0) {
    u8 i;
    s32 entry;
    s32 count;
    i = 0;
    count = M2C_FIELD(arg0, s8 *, 4) - 1;
    for (; i < count; i++) {
        entry = (s32)arg0 + i * 0x18;
        if (M2C_FIELD(entry, s32 *, 0x18) != M2C_FIELD(entry, s32 *, 0x30)) return 1;
    }
    return 0;
}

s32 func_ov003_021e6cac(s16,s16,s16);
void func_ov003_021e8654(s32,s32,s32);
#pragma opt_propagation off
void func_ov003_021e8354(s32 arg0,s32 arg1,s32 arg2){s32 n=M2C_FIELD(arg0+0x18,s32*,arg1*24)+1;
if(func_ov003_021e6cac((s16)n,(s16)M2C_FIELD(arg0+0x20,s32*,arg1*24),(s16)M2C_FIELD(arg0+0x1c,s32*,arg1*24))||arg2){M2C_FIELD(arg0+0x18,s32*,arg1*24)=n;if (((u8 (*)[24])arg0)[arg1][0x28]) {
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
if(ov003_entries_differ(arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,1,arg2);
if(ov003_entries_differ(arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,1,arg2);
if(func_ov003_021e8308((void*)arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,1,arg2);
if(func_ov003_021e8308((void*)arg0))return;func_ov003_021e8654(arg0+0x14+arg1*24,1,arg2);
if(func_ov003_021e8308((void*)arg0))return;func_ov003_021e8354(arg0,arg1,arg2);}
