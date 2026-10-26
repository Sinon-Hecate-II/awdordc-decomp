/* 10 functions from 0x021A2FE8 to 0x021A3DAC (ov000), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 pad[8];
    u16 low : 14;
    u16 state : 2;
    u8 tail[4];
} UnkState_021a36e4;
#include "ov000_unit_entry.h"

u8 func_ov000_021a3484(s32 a) {
extern M2C_UNK data_ov000_021b5bfc;
extern M2C_UNK data_0212616c;
u8 result;
u32 row = M2C_FIELD(&data_ov000_021b5bfc,u8 *,0xa92);
s8 *table = M2C_FIELD(&data_0212616c, s8 **, 0x64) + row*32;
if (table[a&31] > 0) result=1; else result=0;
return result;
}

s32 func_ov000_021a3644(s32 arg0) {
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
s32 count=0;
s32 i;
void *base=*data_027e0058;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)base+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && type==arg0 && entry->unkC[0]==0) count++;
}
return count;
}

s32 func_ov000_021a36e4(void) {
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
s32 func_ov000_021a98c8(s32);
s32 count=0;
s32 i;
void *base=*data_027e0058;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*data_027e0058+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && func_ov000_021a98c8(type)!=0 && ((UnkState_021a36e4 *)entry)->state==2) count++;
}
return count;
}

s32 func_ov000_021a379c(void) {
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
s32 func_ov000_021a98c8(s32);
s32 count=0;
s32 i;
void *base=*data_027e0058;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*data_027e0058+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && func_ov000_021a98c8(type)==0 && ((UnkState_021a36e4 *)entry)->state==2) count++;
}
return count;
}

