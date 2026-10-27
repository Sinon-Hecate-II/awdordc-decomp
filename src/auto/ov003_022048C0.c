/* 19 functions from 0x022048C0 to 0x022056BC (ov003), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 pad[0x12c];
    u32 a:12, b:1, c:3, d:1, e:4, f:7, g:4;
    u32 h:17, i:14, j:1;
} UnkOv003Packed;

/* Packs state flags from an object's sub-fields into the packed state at obj+0x44 and initializes its trailing 0x24-byte block. */
void func_ov003_02204ec4(void *obj) {
    UnkOv003Packed *packed = M2C_FIELD(obj, UnkOv003Packed **, 0x44);

    packed->b = M2C_FIELD(packed, u32 *, 0xC);
    packed->c = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0x24);
    packed->e = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0x3C);
    packed->f = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0x54);
    packed->g = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0x9C);
    packed->h = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0x6C);
    packed->i = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0x84);
    packed->j = M2C_FIELD(M2C_FIELD(obj, void **, 0x44), u32 *, 0xB4);

    func_02084d88((u8 *)packed + 0x110, 0x24);
}

void func_ov003_02204fac(void *arg0) {
    M2C_UNK func_02084d88(void *, M2C_UNK);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s32 *, 0x110) = 1;
    func_02084d88(M2C_FIELD(arg0, void **, 0x44) + 0x110, 0x24);
}

void func_ov003_02204fd0(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s32 *, 0x114) = 1;
    func_02084d88(M2C_FIELD(arg0, void **, 0x44) + 0x110, 0x24);
}

void func_ov003_02204ff4(void *arg0) {
    void func_01ffa6fc(void *);
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0xC) {
        func_01ffa6fc(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x38)++;
}

void func_ov003_02205400(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_02205414(void) {
    M2C_UNK func_ov003_022024a8();
    func_ov003_022024a8();
}

void func_ov003_02205420(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_02205434(void *arg0) {
M2C_UNK func_02088d94(s32);
M2C_UNK func_02088f1c(s32);
s16 func_ov003_021f153c();
s32 func_ov003_02200ca8();
s16 value;
void *group;
s32 i;
void *items;
u8 j;
void *first;
void *second;
value=func_ov003_021f153c();
if((u8)(((u32)(M2C_FIELD(arg0,u8 *,0x3a)<<26)>>26)==1)) value=0;
else {
group=M2C_FIELD(arg0,void **,0x50);
for(i=0;i<4;i++){
func_02088d94(((s32 *)group)[i+1]);
func_02088d94(((s32 *)group)[i+5]);
func_02088d94(((s32 *)group)[i+9]);
}
}
first=M2C_FIELD(arg0,void **,0x3c);
M2C_FIELD(first,s16 *,0xe)=value;
M2C_FIELD(first,s16 *,0x10)=0;
M2C_FIELD(first,s16 *,0xc)=12;
M2C_FIELD(first,u16 *,2)=M2C_FIELD(first,u16 *,4);
second=M2C_FIELD(arg0,void **,0x48);
M2C_FIELD(second,s16 *,0xe)=-32;
M2C_FIELD(second,s16 *,0x10)=0;
M2C_FIELD(second,s16 *,0xc)=12;
M2C_FIELD(second,u16 *,2)=M2C_FIELD(second,u16 *,4);
M2C_FIELD(arg0,u8 *,0x3a)|=0x40;
if(func_ov003_02200ca8())return;
func_02088d94(M2C_FIELD(arg0,s32 *,0x4c));
items=M2C_FIELD(arg0,void **,0x40);
func_02088f1c(((s32 *)items)[0]);
func_02088f1c(((s32 *)items)[1]);
for(j=0;j<8U;j++){
func_02088f1c(((s32 *)items)[j+2]);
func_02088f1c(((s32 *)items)[j+10]);
}
if((u8)(((u32)(M2C_FIELD(arg0,u8 *,0x3a)<<26)>>26)==0))
func_02088f1c(M2C_FIELD(arg0,s32 *,0x58));
}

void func_ov003_02205564(void) {
    M2C_UNK func_ov003_0220277c();
    func_ov003_0220277c();
}

void func_ov003_02205570(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

void func_ov003_02205584(void *arg0) {
    M2C_UNK func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    s32 func_ov003_021f15d4();
    s16 func_ov003_021f1608();
    s16 value;
    u8 i;
    void *second;
    void *first;
    value = func_ov003_021f1608();
    first = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(first, s16 *, 0xE) = func_020a8ff4(first);
    M2C_FIELD(first, s16 *, 0x10) = value;
    M2C_FIELD(first, s16 *, 0xC) = 12;
    M2C_FIELD(first, u16 *, 2) = M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(arg0, void **, 0x48);
    M2C_FIELD(second, s16 *, 0xE) = func_020a8ff4(second);
    M2C_FIELD(second, s16 *, 0x10) = -32;
    M2C_FIELD(second, s16 *, 0xC) = 12;
    M2C_FIELD(second, u16 *, 2) = M2C_FIELD(second, u16 *, 4);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    if (!func_ov003_021f15d4()) return;
    arg0 = M2C_FIELD(arg0, void **, 0x40);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 4));
    i = 0;
    do {
        func_02088ff4(((s32 *)arg0)[i + 2]);
        func_02088ff4(((s32 *)arg0)[i + 10]);
        i++;
    } while (i < 8U);
}

void func_ov003_02205638(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_0220564c(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x3C);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02205678(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_02205698(void) {
    M2C_UNK func_ov003_02202414();
    func_ov003_02202414();
}

void func_ov003_022056a4(void) {
    M2C_UNK func_ov003_02202454();
    func_ov003_02202454();
}

void func_ov003_022056b0(void) {
    M2C_UNK func_ov003_022048c0();
    func_ov003_022048c0();
}

