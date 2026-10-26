/* 4 functions from 0x021E1500 to 0x021E16EC (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_021e1500(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

void func_ov003_021e1518(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x4D4C5342, arg0);
}

/* Sets up one slot of the table pointed at by state: allocates/recycles an entry via
   func_01ffa810 for the normal case, or updates a sub-object when id == 10. */
void func_ov003_021e1530(void *state, s32 id) {
    u8 count;
    s16 value;
    s16 id16;
    s32 freeCount;
    void *entry;
    M2C_FIELD(state, s32 *, 0x38) = func_01ffa810(id);
    if (id != 10) {
        M2C_FIELD(state, u8 *, 7) = func_0207c928(id, 5);
        M2C_FIELD(state, u8 *, 8) = func_0207c8ec(id, 5);
        id16 = id;
        M2C_FIELD(state, u8 *, 6) = id;
        if (func_ov003_021e1500(id16, 0, 4)) M2C_FIELD(state, u8 *, 9) = id;
        if (func_ov003_021e1500(id16, 5, 9)) M2C_FIELD(state, u8 *, 10) = id - 5;
        return;
    }
    if (id != 10) return;
    freeCount = func_ov003_021f2560();
    count = M2C_FIELD(state, u8 *, 11);
    if (freeCount && M2C_FIELD(state, u8 *, 8) == 0) {
        count = freeCount - 1;
        value = 0;
    } else {
        if (!count) return;
        if (M2C_FIELD(state, u8 *, 8) != 1) return;
        count += 4;
        value = 5;
    }
    entry = state + id * 4;
    M2C_FIELD(M2C_FIELD(entry, void **, 12), s16 *, 0x68) = count;
    M2C_FIELD(M2C_FIELD(entry, void **, 12), s16 *, 0x6A) = value;
}

void func_ov003_021e161c(void *arg0) {
void func_020aacf0(void *);
s32 a,b; u8 i; void *p,*q,*r;
i=0;
M2C_FIELD(arg0,u8 *,4)=-1;
M2C_FIELD(arg0,u8 *,5)=-1;
do{
p=M2C_FIELD(arg0+i*4,void **,0xc);
if(p){
func_020aacf0(p);
r=M2C_FIELD((u32)arg0+i*4,void **,0xc);
a=1;
q=M2C_FIELD(r,void **,0x64);
if(M2C_FIELD(q,s8 *,0xb)!=1 && (((u32)(M2C_FIELD(r,u8 *,0x59)<<27)>>31)==0 || M2C_FIELD(q,s8 *,0xc)!=1))a=0;
if(a&255)M2C_FIELD(arg0,u8 *,4)=i;
p=M2C_FIELD((u32)arg0+(i<<2),void **,0xc);
if((((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+1)==(u16)((u32)(M2C_FIELD(p,u32 *,0x40)<<6)>>24))b=1;else b=0;
if(b&255)M2C_FIELD(arg0,u8 *,5)=i;
}
i++;
}while(i<11);
}

