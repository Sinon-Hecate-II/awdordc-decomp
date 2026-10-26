/* 31 functions from 0x021A860C to 0x021A947C (ov000), found by ds-decomp. */
#include "common.h"
extern s8 *data_ov000_021b5c54[];

#include "ov000_unit_entry.h"
typedef struct { u8 pad[10]; u8 value:7; u8 flag:1; } UnkValue_021a89a4;

s32 func_ov000_021a86dc(void) {
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
s32 i;

void *base = *data_027e0058;
u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*data_027e0058, u16 *, 0x52A4)] + 0x33; i++) {
UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4))[i];
u32 type = entry->unk0;
if (type != 0 && type == 0xE && entry->unk6 >= 0x32U) { return 1; }
}
return 0;
}

s32 func_ov000_021a8784(s32 arg0) {
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
s32 count = 0;
s32 i;
void *base = *data_027e0058;
u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*data_027e0058, u16 *, 0x52A4)] + 0x33; i++) {
UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4))[i];
u32 type = entry->unk0;
if (type != 0 && type == arg0) { count += 1; }
}
return count;
}

s32 func_ov000_021a881c(s32 arg0, s32 arg1) {
extern void **data_027e0058;
extern u16 data_ov000_021aeef4[];
s32 count = 0;
s32 i;
void *base = *data_027e0058;
u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*data_027e0058, u16 *, 0x52A4)] + 0x33; i++) {
UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4))[i];
u32 type = entry->unk0;
if (type != 0 && type == arg0 && entry->unkB != arg1) { count += 1; }
}
return count;
}

s32 func_ov000_021a88c8(s32 arg0) {
extern void **data_027e0058;extern u16 data_ov000_021aeef4[];u8 func_ov000_021a8984(s32);
s32 count=0,i;void *base=*data_027e0058;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52a4)]+0x33;i++){
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*data_027e0058+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0&&type==arg0&&func_ov000_021a8984(entry->unkB)==0)count++;
}
return count;
}

u8 func_ov000_021a8984(s32 arg0) {
    u8 var_r0;

    if (arg0 == 6) {
        return 1U;
    }
    if (arg0 == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a89a4(UnkValue_021a89a4 *a) {
extern void **data_027e0058;
s32 func_020a86f0(s32);s32 func_0207c8ec(s32,s32);s32 func_020a75b8(void *);
s32 n=func_0207c8ec(a->value,func_020a86f0(M2C_FIELD(*data_027e0058,u16 *,0x52a4)));
if(func_020a75b8(a)<=n)n=func_020a75b8(a);
return n;
}

s32 func_ov000_021a8a04(s32 a,s32 b,s32 c,s32 d) {
s32 total=0;
if(a-c>0)total+=a-c;else total+=c-a;
if(b-d>0)total+=b-d;else total+=d-b;
return total;
}

s32 func_ov000_021a8a38(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_ip;
    s32 var_r0;
    s32 var_r2;

    var_ip = arg0 - arg2;
    if (var_ip <= 0) {
        var_ip = arg2 - arg0;
    }
    var_r2 = arg1 - arg3;
    if (var_r2 <= 0) {
        var_r2 = arg3 - arg1;
    }
    var_r0 = var_ip - var_r2;
    if (var_r0 <= 0) {
        var_r0 = var_r2 - var_ip;
    }
    return var_r0;
}

s32 func_ov000_021a8a60(void *arg0) {
    M2C_UNK func_020a7568(void *, u8, u8);
    func_020a7568(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

s32 func_ov000_021a8a74(void *arg0) {
    M2C_UNK func_020a7568(void *, u8, u8);
    func_020a7568(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

u8 func_ov000_021a8a88(void *a){u8 r;if(!((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27))return 0;if(func_ov000_021a8a74(a)+(s32)((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27)>=20)r=1;else r=0;return r;}

s32 func_ov000_021a8ac8(void *a){extern void **data_027e0058;s32 n;if(a){if(!a)n=0;else n=((s32)a-(s32)((u8 *)*data_027e0058+0x59a4))/14;n=(n>>6)+1;}else n=0;if(M2C_FIELD(*data_027e0058,u16 *,0x52a8)!=n){if(!((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27))return 0;}return func_ov000_021a8a60(a)+(s32)((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27)>=20;}

s32 func_ov000_021a8b78(void *a){s32 func_0207c8ec(s32,s32);u32 v;s32 n,i,x;v=(u32)(M2C_FIELD(a,u16 *,6)<<25)>>25;if(!v)n=0;else n=func_0207c8ec(v-1,10)+1;i=0;x=(u32)(M2C_FIELD(a,u16 *,6)<<16)>>27;if(n<=0)return 20;n=func_ov000_021a8a60(a);while(x<20){x+=n;i++;}return i;}

u8 func_ov000_021a8fc0(s32 arg0) {
    extern void **data_027e0058;
    u8 var_r0;

    if ((arg0 & 0xC0) == M2C_FIELD(*data_027e0058, u16 *, 0x52A8)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a8ff0(s32 arg0) {
    extern s8 data_ov000_021b54c0[];
    u8 var_r0;
    if (data_ov000_021b54c0[arg0 & 0x1F] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a9014(s32 a) {
extern s8 data_ov000_021b54c0[];
s32 i=a&31;u8 v;
if(i==24)return 0;
if(data_ov000_021b54c0[i])v=1;else v=0;
return v;
}

u8 func_ov000_021a9044(s32 a,s32 b){
extern u8 data_ov000_021b5c0e[];
extern M2C_UNK data_0212616c;
u32 row=data_ov000_021b5c0e[a*0x70];
s8 *table=M2C_FIELD(&data_0212616c,s8 **,0x64)+row*32;
u8 r;if(table[b&31]>0)r=1;else r=0;return r;
}

u8 func_ov000_021a9084(s32 arg0) {
    extern s8 data_ov000_021b54a0[];
    u8 var_r0;
    if (data_ov000_021b54a0[arg0 & 0x1F] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a90a8(s32 a,s32 b,s32 c){
extern void **data_027e0058;u8 *p=*data_027e0058;
u8 v=M2C_FIELD(p+(b+M2C_FIELD(p+c*2,u16 *,0x3758)),u8 *,0x1420)>>5;
u8 r;if(!v)return 0;
if(M2C_FIELD(p+((a>>6)+1)*0x8c,u8 *,0x67ca)!=M2C_FIELD(p+v*0x8c,u8 *,0x67ca))r=1;else r=0;return r;}

u8 func_ov000_021a911c(s32 a,s32 b,s32 c){
extern void **data_027e0058;u8 *p=*data_027e0058;s32 n=(a>>6)+1;u8 r;
if(n==(M2C_FIELD(p+(b+M2C_FIELD(p+c*2,u16 *,0x3758)),u8 *,0x1420)>>5))r=1;else r=0;return r;}

u8 func_ov000_021a9164(s32 a,s32 b,s32 c){
extern void **data_027e0058;u8 *p=*data_027e0058;
s32 v=M2C_FIELD(p+(b+M2C_FIELD(p+c*2,u16 *,0x3758)),u8 *,0x508);u8 r;if(!v)return 0;
if(M2C_FIELD(p+a*0x8c,u8 *,0x67ca)==M2C_FIELD(p+((v>>6)+1)*0x8c,u8 *,0x67ca))r=1;else r=0;return r;}

s32 func_ov000_021a91d0(s32 a){switch(a&31){case 15:case 17:case 18:case 19:case 22:return 1;default:return 0;}}

u8 func_ov000_021a9318(s32 a,s32 b,s32 c){extern void **data_027e0058;s32 func_020d280c(s32);void *p;if(!func_020d280c(M2C_FIELD(*data_027e0058,u16 *,0x52a4)))return 0;p=*data_027e0058;return M2C_FIELD(data_ov000_021b5c54,s8 **,a*112)[M2C_FIELD((u8 *)p+(b+M2C_FIELD((u8 *)p+c*2,u16 *,0x3758)),u8 *,0x1420)&31]!=0;}

s32 func_ov000_021a93a8(void) {
    return 0;
}

s32 func_ov000_021a93b0(s32 a,s32 b,s32 c){extern void **data_027e0058;s32 func_020ce0ec(u8,u8);void *p=*data_027e0058;return func_020ce0ec(a,M2C_FIELD((u8 *)p+(b+M2C_FIELD((u8 *)p+c*2,u16 *,0x3758)),u8 *,0x1420));}

s32 func_ov000_021a93ec(s32 a,s32 b){extern void **data_027e0058;s32 func_020a600c(u16);void *p=*data_027e0058;u32 n;u32 id=M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758)),u8 *,0);if(id&&!func_020a600c((u16)id))return 0;p=*data_027e0058;n=a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758);return (u8)(M2C_FIELD((u8 *)p+(n>>3),u8 *,0x5160)&(1<<(n&7)))!=0;}

