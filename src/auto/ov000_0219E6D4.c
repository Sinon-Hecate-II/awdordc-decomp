/* 14 functions from 0x0219E6D4 to 0x0219F6D0 (ov000), found by ds-decomp. */
#include "common.h"

#pragma inline_depth(0)
static inline s32 E6D4Offset(s16 index) { return index * (s16)14; }
static inline s32 E6D4Call(u8 *p,s16 index) { s32 func_0207b764(u8,u8); u8 *q=p+0x59a4+E6D4Offset(index);return func_0207b764(q[1],q[2]); }
static inline s32 E6D4Check(u8 *p, s16 index) { u8 *q=p+0x59a4+E6D4Offset(index); s32 yes=M2C_FIELD(p+M2C_FIELD(p,u16*,0x52a4)*0x8c,u8*,0x67c3); s32 y=q[2]; u32 x=q[1],bit; if(yes&2)yes=1;else{bit=x+M2C_FIELD(p+y*2,u16*,0x3758);yes=1;if((u8)(M2C_FIELD(p+(bit>>3),u8*,0x5201)&(1<<(bit&7)))==0)yes=0;} return yes; }

void func_ov000_0219e6d4(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_02183874;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_02183874;
 *data_ov000_021df580 = 2;
}

void func_ov000_0219e72c(void) {
    /* Variant collecting type-5 map entries, installing func_ov000_02181b8c. */
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02181b8c;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    data_ov000_021df658 = &data_ov000_021df824;
    obj = *gCurrentMap;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && type == 5) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_02181b8c;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219e830(void) {
    extern s8 *data_ov000_021df580;
    *data_ov000_021df580 = 4;
}

void func_ov000_0219e848(void) {
    extern void (*data_ov000_021df42c[])(void);
    extern void (*data_ov000_021df4b8[])(void);
    extern s8 *data_ov000_021df580;
    extern void **gCurrentMap;
    void *temp_r0;
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) == 0 && M2C_FIELD(temp_r0, u8 *, 0x5158) != 2) {
        data_ov000_021df42c[M2C_FIELD(data_ov000_021df580, u8 *, 2)]();
    } else {
        data_ov000_021df4b8[M2C_FIELD(data_ov000_021df580, u8 *, 2)]();
    }
    M2C_FIELD(data_ov000_021df580, u8 *, 2)++;
}

s32 func_ov000_0219e8d0(void) {
    s32 func_0208485c();
    extern u8 data_02168f0c;
    extern u16 data_02156e4c;
    extern void **gCurrentMap;
    void *temp_r3;
    if (data_02168f0c == 0) {
        return 0;
    }
    if (func_0208485c() != 0) {
        temp_r3 = *gCurrentMap;
        if (M2C_FIELD((u8 *) temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67C2) == 2) {
            return 0;
        }
    }
    if (data_02156e4c != 1) {
        return 0;
    }
    return 1;
}

s32 func_ov000_0219e948(void) {
    s32 func_ov000_0219e9f4();
    s32 func_ov000_0219efa4();
    s32 func_ov000_0219f0d8();
    s32 func_ov000_0219f728();
    s32 func_ov000_0219f918();
    s32 func_ov000_0219f968();
    s32 func_ov000_0219f9c0();
    s32 func_ov000_0219fa0c();
    s32 func_ov000_0219fa30();
    s32 func_ov000_0219fa98();
    extern s8 *data_ov000_021df580;
    s32 var_r5;
    var_r5 = 0;
    do {
        switch (M2C_FIELD(data_ov000_021df580, u8 *, 1)) {
        case 0:
            var_r5 = func_ov000_0219e9f4();
            break;
        case 1:
            var_r5 = func_ov000_0219efa4();
            break;
        case 2:
            var_r5 = func_ov000_0219f0d8();
            break;
        case 3:
            var_r5 = func_ov000_0219f918();
            break;
        case 4:
            var_r5 = func_ov000_0219f968();
            break;
        case 5:
            var_r5 = func_ov000_0219fa0c();
            break;
        case 6:
            var_r5 = func_ov000_0219f9c0();
            break;
        case 7:
            var_r5 = func_ov000_0219f728();
            break;
        case 8:
            var_r5 = func_ov000_0219fa30();
            break;
        case 9:
            var_r5 = func_ov000_0219fa98();
            break;
        default:
            var_r5 = 0;
            break;
        }
    } while (var_r5 != 0);
    return var_r5;
}

s32 func_ov000_0219e9f4() {
    return 0;
}

s32 func_ov000_0219efa4(void) {
    void func_020d61f0(void);
    void *func_ov000_0216939c(void *);
    void func_020cfd28(void);
    void func_020844a0(u8 *, u8 *);
    s32 func_020d6544(s32, s32, s32, void *, s32);
    s32 func_020d1a1c(s32);
    void func_ov000_02199f50(s32, s32, s32, s32);
    void func_020a64ec(void);
    extern void **gCurrentMap;
    extern u8 data_ov000_021df7dc[];
    extern u8 data_ov000_021df7d0[];

    void *map;
    s32 x, y, masked, result;
    func_020d61f0();
    map = *gCurrentMap;
    func_ov000_0216939c(*(void **)((u8 *)map + 0x52d0));
    func_020cfd28();
    func_020844a0(data_ov000_021df7dc, (u8 *)map + 0x5388);
    x = *(s16 *)((u8 *)map + 0x52d8);
    y = *(s16 *)((u8 *)map + 0x52da);
    masked = (s32)(((u32)*(u8 *)*(void **)((u8 *)map + 0x52d0) << 26) >> 26);
    result = func_020d6544(x, y, masked, (u8 *)map + 0x5388, 4);
    if (result != 0) {
        if (func_020d1a1c(*(u16 *)((u8 *)map + 0x52a4)) != 0) {
            func_ov000_02199f50(0xf, *(u8 *)((u8 *)map + 0x52d4), 0, 0);
        }
        data_ov000_021df7dc[0] = 2;
    }
    func_020a64ec();
    data_ov000_021df7d0[1] = 2;
    return (*(s8 *)((u8 *)map + 0x5388) == 4) ? 1 : 0;
}

void func_ov000_0219f3fc(void) {
    void func_0208fb0c(s32, u8, u8);
    void func_020a67fc(u8, u8, u8);
    extern u8 data_ov000_021df7d0[];
    extern s8 *data_ov000_021df580;
    func_020a67fc(data_ov000_021df7d0[2], data_ov000_021df7d0[3], data_ov000_021df7d0[1]);
    func_0208fb0c(0x111, data_ov000_021df7d0[2], data_ov000_021df7d0[3]);
    M2C_FIELD(data_ov000_021df580, s8 *, 1) = 9;
}

void func_ov000_0219f448(void) {
    void func_0208fb0c(s32, u8, u8);
    void func_020a67fc(u8, u8, u8);
    extern u8 data_ov000_021df7d0[];
    extern s8 *data_ov000_021df580;
    func_020a67fc(data_ov000_021df7d0[2], data_ov000_021df7d0[3], data_ov000_021df7d0[1]);
    func_0208fb0c(0x111, data_ov000_021df7d0[2], data_ov000_021df7d0[3]);
    M2C_FIELD(data_ov000_021df580, s8 *, 1) = 9;
}

void func_ov000_0219f494(void) {
extern void **gCurrentMap;
extern s8 *data_ov000_021df580;
extern u8 data_ov000_021df7d0[];
void func_020a6fcc(void);
s32 i;
u8 *p;
M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=1;
func_020a6fcc();
p=data_ov000_021df7d0;
*data_ov000_021df580=0;
M2C_FIELD(*gCurrentMap,u8 *,0x515a)=p[6];
for(i=0;i<4;i++){
M2C_FIELD((u8 *)*gCurrentMap+i,u8 *,0x515c)=p[12];
p++;
}
}

#pragma opt_common_subs off
#pragma opt_propagation off
u8 func_ov000_0219f518(void){
extern void **gCurrentMap;
extern u8 data_ov000_021df7d0[];
extern s8 *data_ov000_021df580;
extern s32 data_ov000_021e1468;
s32 func_0207b764(u8,u8);
u8 result;
s32 value;
u8 *p;
s16 index;
s32 offset;
u8 *q;
s32 yes,y;
u32 x,bit;
p=*gCurrentMap;
index=data_ov000_021df7d0[6];
offset=index*(s16)14;
yes=M2C_FIELD(p+M2C_FIELD(p,u16 *,0x52a4)*140,u8 *,0x67c3);
q=p+0x59a4+offset;
y=q[2];x=q[1];
value=0;
if(yes&2)yes=1;
else{
bit=x+M2C_FIELD(p+y*2,u16 *,0x3758);
yes=1;
if((u8)(M2C_FIELD(p+(bit>>3),u8 *,0x5201)&(1<<(bit&7)))==0)yes=0;
}
if(yes){
q=p+0x59a4+offset;
value=func_0207b764(q[1],q[2]);
}
data_ov000_021e1468=0;
M2C_FIELD(data_ov000_021df580,u8 *,1)=7;
result=value==0;
return result;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
u8 func_ov000_0219f5fc(void){
s32 func_0207b764(u8,u8);extern void **gCurrentMap;extern u8 data_ov000_021df7d0[];extern s8 *data_ov000_021df580;extern s32 data_ov000_021e1468;
void *p=*gCurrentMap;u8 y=data_ov000_021df7d0[7],x=data_ov000_021df7d0[6];s32 r=0;u32 n;u32 flags; s32 ok;
flags=M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*140,u8 *,0x67c3);
if(flags&2)ok=1;
else {
ok=1;
n=x+M2C_FIELD((u8 *)p+y*2,u16 *,0x3758);
if(!(u8)(M2C_FIELD((u8 *)p+(n>>3),u8 *,0x5201)&(1<<(n&7))))ok=0;
}
if(ok){r=func_0207b764(x,y);data_ov000_021e1468=0;data_ov000_021df580[1]=7;}else data_ov000_021df580[1]=3;
return r==0;
}

