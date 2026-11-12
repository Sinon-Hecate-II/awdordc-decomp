/* 19 functions from 0x022048C0 to 0x022056BC (ov003), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[28]; u32 a:12,b:1,c:3,d:1,e:4,f:7,g:4; u32 h:17,i:14,j:1; } Input048c0;
static inline void Invoke048c0(void *self,s32 offset){ M2C_FIELD(M2C_FIELD(self,void **,0),void (**)(void *),offset)(self); }

typedef struct {
    u8 pad[0x12c];
    u32 a:12, b:1, c:3, d:1, e:4, f:7, g:4;
    u32 h:17, i:14, j:1;
} UnkOv003Packed;

/* Packs state flags from an object's sub-fields into the packed state at obj+0x44 and initializes its trailing 0x24-byte block. */
M2C_UNK func_02084e64();
M2C_UNK PlaySoundEffect(s32);
#pragma opt_strength_reduction off
void func_ov003_022048c0(s32 obj){void *input;void *p;s32 old[8];u8 i;input=(void *)func_02084e64();if(!input)return;p=M2C_FIELD((void *)obj,void **,68);for(i=0;i<8;i++)old[i]=M2C_FIELD((u8 *)p+i*24,s32*,12);p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,12)=((u32)M2C_FIELD(input,u32*,28)<<19)>>31;if(M2C_FIELD(p,u8*,28)){while(M2C_FIELD(p,s32*,12)>M2C_FIELD(p,s32*,16))M2C_FIELD(p,s32*,12)=M2C_FIELD(p,s32*,12)-(M2C_FIELD(p,s32*,16)-M2C_FIELD(p,s32*,20)+1);while(M2C_FIELD(p,s32*,12)<M2C_FIELD(p,s32*,20))M2C_FIELD(p,s32*,12)=M2C_FIELD(p,s32*,12)+(M2C_FIELD(p,s32*,16)-M2C_FIELD(p,s32*,20)+1);}else{M2C_FIELD(p,s32*,12)=M2C_FIELD(p,s32*,12)>M2C_FIELD(p,s32*,16)?M2C_FIELD(p,s32*,16):(M2C_FIELD(p,s32*,12)<M2C_FIELD(p,s32*,20)?M2C_FIELD(p,s32*,20):M2C_FIELD(p,s32*,12));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,36)=((u32)M2C_FIELD(input,u32*,28)<<16)>>29;if(M2C_FIELD(p,u8*,52)){while(M2C_FIELD(p,s32*,36)>M2C_FIELD(p,s32*,40))M2C_FIELD(p,s32*,36)=M2C_FIELD(p,s32*,36)-(M2C_FIELD(p,s32*,40)-M2C_FIELD(p,s32*,44)+1);while(M2C_FIELD(p,s32*,36)<M2C_FIELD(p,s32*,44))M2C_FIELD(p,s32*,36)=M2C_FIELD(p,s32*,36)+(M2C_FIELD(p,s32*,40)-M2C_FIELD(p,s32*,44)+1);}else{M2C_FIELD(p,s32*,36)=M2C_FIELD(p,s32*,36)>M2C_FIELD(p,s32*,40)?M2C_FIELD(p,s32*,40):(M2C_FIELD(p,s32*,36)<M2C_FIELD(p,s32*,44)?M2C_FIELD(p,s32*,44):M2C_FIELD(p,s32*,36));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,60)=((u32)M2C_FIELD(input,u32*,28)<<11)>>28;if(M2C_FIELD(p,u8*,76)){while(M2C_FIELD(p,s32*,60)>M2C_FIELD(p,s32*,64))M2C_FIELD(p,s32*,60)=M2C_FIELD(p,s32*,60)-(M2C_FIELD(p,s32*,64)-M2C_FIELD(p,s32*,68)+1);while(M2C_FIELD(p,s32*,60)<M2C_FIELD(p,s32*,68))M2C_FIELD(p,s32*,60)=M2C_FIELD(p,s32*,60)+(M2C_FIELD(p,s32*,64)-M2C_FIELD(p,s32*,68)+1);}else{M2C_FIELD(p,s32*,60)=M2C_FIELD(p,s32*,60)>M2C_FIELD(p,s32*,64)?M2C_FIELD(p,s32*,64):(M2C_FIELD(p,s32*,60)<M2C_FIELD(p,s32*,68)?M2C_FIELD(p,s32*,68):M2C_FIELD(p,s32*,60));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,84)=((u32)M2C_FIELD(input,u32*,28)<<4)>>25;if(M2C_FIELD(p,u8*,100)){while(M2C_FIELD(p,s32*,84)>M2C_FIELD(p,s32*,88))M2C_FIELD(p,s32*,84)=M2C_FIELD(p,s32*,84)-(M2C_FIELD(p,s32*,88)-M2C_FIELD(p,s32*,92)+1);while(M2C_FIELD(p,s32*,84)<M2C_FIELD(p,s32*,92))M2C_FIELD(p,s32*,84)=M2C_FIELD(p,s32*,84)+(M2C_FIELD(p,s32*,88)-M2C_FIELD(p,s32*,92)+1);}else{M2C_FIELD(p,s32*,84)=M2C_FIELD(p,s32*,84)>M2C_FIELD(p,s32*,88)?M2C_FIELD(p,s32*,88):(M2C_FIELD(p,s32*,84)<M2C_FIELD(p,s32*,92)?M2C_FIELD(p,s32*,92):M2C_FIELD(p,s32*,84));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,156)=((u32)M2C_FIELD(input,u32*,28))>>28;if(M2C_FIELD(p,u8*,172)){while(M2C_FIELD(p,s32*,156)>M2C_FIELD(p,s32*,160))M2C_FIELD(p,s32*,156)=M2C_FIELD(p,s32*,156)-(M2C_FIELD(p,s32*,160)-M2C_FIELD(p,s32*,164)+1);while(M2C_FIELD(p,s32*,156)<M2C_FIELD(p,s32*,164))M2C_FIELD(p,s32*,156)=M2C_FIELD(p,s32*,156)+(M2C_FIELD(p,s32*,160)-M2C_FIELD(p,s32*,164)+1);}else{M2C_FIELD(p,s32*,156)=M2C_FIELD(p,s32*,156)>M2C_FIELD(p,s32*,160)?M2C_FIELD(p,s32*,160):(M2C_FIELD(p,s32*,156)<M2C_FIELD(p,s32*,164)?M2C_FIELD(p,s32*,164):M2C_FIELD(p,s32*,156));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,108)=((Input048c0 *)input)->h;if(M2C_FIELD(p,u8*,124)){while(M2C_FIELD(p,s32*,108)>M2C_FIELD(p,s32*,112))M2C_FIELD(p,s32*,108)=M2C_FIELD(p,s32*,108)-(M2C_FIELD(p,s32*,112)-M2C_FIELD(p,s32*,116)+1);while(M2C_FIELD(p,s32*,108)<M2C_FIELD(p,s32*,116))M2C_FIELD(p,s32*,108)=M2C_FIELD(p,s32*,108)+(M2C_FIELD(p,s32*,112)-M2C_FIELD(p,s32*,116)+1);}else{M2C_FIELD(p,s32*,108)=M2C_FIELD(p,s32*,108)>M2C_FIELD(p,s32*,112)?M2C_FIELD(p,s32*,112):(M2C_FIELD(p,s32*,108)<M2C_FIELD(p,s32*,116)?M2C_FIELD(p,s32*,116):M2C_FIELD(p,s32*,108));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,132)=((u32)M2C_FIELD(input,u32*,32)<<1)>>18;if(M2C_FIELD(p,u8*,148)){while(M2C_FIELD(p,s32*,132)>M2C_FIELD(p,s32*,136))M2C_FIELD(p,s32*,132)=M2C_FIELD(p,s32*,132)-(M2C_FIELD(p,s32*,136)-M2C_FIELD(p,s32*,140)+1);while(M2C_FIELD(p,s32*,132)<M2C_FIELD(p,s32*,140))M2C_FIELD(p,s32*,132)=M2C_FIELD(p,s32*,132)+(M2C_FIELD(p,s32*,136)-M2C_FIELD(p,s32*,140)+1);}else{M2C_FIELD(p,s32*,132)=M2C_FIELD(p,s32*,132)>M2C_FIELD(p,s32*,136)?M2C_FIELD(p,s32*,136):(M2C_FIELD(p,s32*,132)<M2C_FIELD(p,s32*,140)?M2C_FIELD(p,s32*,140):M2C_FIELD(p,s32*,132));}p=M2C_FIELD((void *)obj,void **,68);M2C_FIELD(p,s32*,180)=((u32)M2C_FIELD(input,u32*,32))>>31;if(M2C_FIELD(p,u8*,196)){while(M2C_FIELD(p,s32*,180)>M2C_FIELD(p,s32*,184))M2C_FIELD(p,s32*,180)=M2C_FIELD(p,s32*,180)-(M2C_FIELD(p,s32*,184)-M2C_FIELD(p,s32*,188)+1);while(M2C_FIELD(p,s32*,180)<M2C_FIELD(p,s32*,188))M2C_FIELD(p,s32*,180)=M2C_FIELD(p,s32*,180)+(M2C_FIELD(p,s32*,184)-M2C_FIELD(p,s32*,188)+1);}else{M2C_FIELD(p,s32*,180)=M2C_FIELD(p,s32*,180)>M2C_FIELD(p,s32*,184)?M2C_FIELD(p,s32*,184):(M2C_FIELD(p,s32*,180)<M2C_FIELD(p,s32*,188)?M2C_FIELD(p,s32*,188):M2C_FIELD(p,s32*,180));}for(i=0;i<8;i++){if(old[i]!=M2C_FIELD((u8 *)M2C_FIELD((void *)obj,void **,68)+i*24,s32*,12))PlaySoundEffect(0x10011);}if(M2C_FIELD(input,s32*,0))M2C_FIELD(M2C_FIELD((void*)obj,void**,0),void (**)(void*),28)((void*)obj);if(M2C_FIELD(input,s32*,4))M2C_FIELD(M2C_FIELD((void*)obj,void**,0),void (**)(void*),32)((void*)obj);}
#pragma opt_strength_reduction reset
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

void func_ov003_0220501c(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK AddSprite(u16, u8, u16, M2C_UNK *, s32);
    s32 Divide(u8, M2C_UNK);
    s32 Modulo(u8, M2C_UNK);
    M2C_UNK func_02087d84(void *, M2C_UNK, s32, s32, s32, s32);
    M2C_UNK func_02088e84(void *, s16, s16, s16, s32);
    M2C_UNK SetTextSpriteValue(void *, s32);
    M2C_UNK DrawTextSprite(void *);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    s32 func_ov003_02200c64(u8, M2C_UNK, M2C_UNK);
    s32 func_ov003_02200cec(u8, u8);
    extern u16 **data_027e01d8;
    extern M2C_UNK data_ov003_02210484;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s16 temp_r10;
    s16 temp_r10_2;
    s16 temp_r10_3;
    s16 temp_r10_4;
    s16 temp_r11;
    s16 temp_r11_2;
    s16 temp_r1;
    s16 temp_r5;
    s16 temp_r6;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    u16 temp_r8;
    u16 temp_r8_2;
    u16 temp_r8_3;
    u16 temp_r8_4;
    u8 temp_r1_3;
    u8 var_r4;
    void *temp_r1_2;
    void *temp_r5_2;
    void *temp_r9;
    void *temp_r9_2;

    spC = arg1 + 4;
    sp8 = arg2 + 0x38;
    var_r4 = 0;
    sp24 = 0x3FF;
    do {
        temp_r6 = spC + (Modulo(var_r4, 4) << 6);
        temp_r5 = (Divide(var_r4, 4) * 0x48) + sp8;
        temp_r10 = temp_r5 - 0x10;
        temp_r9 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x40) + (var_r4 * 4)), void **, 8);
        temp_r11 = temp_r6 + 0xC;
        func_02088e84(temp_r9, temp_r11, temp_r10, temp_r11, (s32) temp_r10);
        if (M2C_FIELD(M2C_FIELD(temp_r9, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            sp20 = (s32) M2C_FIELD(temp_r9, s16 *, 0x52);
            sp1C = (s32) M2C_FIELD(temp_r9, s16 *, 0x50);
            temp_r8 = func_020aae10(temp_r9);
            func_02087d84(M2C_FIELD(temp_r9, void **, 0x64), 1, sp1C, sp20, (s32) temp_r8, (s32) func_020aae44(temp_r9));
        }
        M2C_FIELD(temp_r9, s16 *, 0x34) = temp_r11;
        M2C_FIELD(temp_r9, s16 *, 0x36) = temp_r10;
        if (M2C_FIELD(M2C_FIELD(temp_r9, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            temp_r10_2 = M2C_FIELD(temp_r9, s16 *, 0x50);
            sp18 = (s32) M2C_FIELD(temp_r9, s16 *, 0x52);
            temp_r8_2 = func_020aae10(temp_r9);
            func_02087d84(M2C_FIELD(temp_r9, void **, 0x64), 1, (s32) temp_r10_2, sp18, (s32) temp_r8_2, (s32) func_020aae44(temp_r9));
        }
        temp_r10_3 = temp_r5 + 0x10;
        temp_r9_2 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x40) + (var_r4 * 4)), void **, 0x28);
        temp_r1 = temp_r6 + 0xC;
        func_02088e84(temp_r9_2, temp_r1, temp_r10_3, temp_r1, (s32) temp_r10_3);
        if (M2C_FIELD(M2C_FIELD(temp_r9_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            sp14 = (s32) M2C_FIELD(temp_r9_2, s16 *, 0x52);
            sp10 = (s32) M2C_FIELD(temp_r9_2, s16 *, 0x50);
            temp_r8_3 = func_020aae10(temp_r9_2);
            func_02087d84(M2C_FIELD(temp_r9_2, void **, 0x64), 1, sp10, sp14, (s32) temp_r8_3, (s32) func_020aae44(temp_r9_2));
        }
        M2C_FIELD(temp_r9_2, s16 *, 0x34) = temp_r11;
        M2C_FIELD(temp_r9_2, s16 *, 0x36) = temp_r10_3;
        if (M2C_FIELD(M2C_FIELD(temp_r9_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            temp_r11_2 = M2C_FIELD(temp_r9_2, s16 *, 0x52);
            temp_r10_4 = M2C_FIELD(temp_r9_2, s16 *, 0x50);
            temp_r8_4 = func_020aae10(temp_r9_2);
            func_02087d84(M2C_FIELD(temp_r9_2, void **, 0x64), 1, (s32) temp_r10_4, (s32) temp_r11_2, (s32) temp_r8_4, (s32) func_020aae44(temp_r9_2));
        }
        if (func_ov003_02200c64(var_r4, 3, 5) != 0) {
            SetTextSpriteValue(M2C_FIELD(arg0, void **, 0x54), M2C_FIELD(((var_r4 * 0x18) + M2C_FIELD(arg0, s32 *, 0x44)), s32 *, 0xC));
            temp_r1_2 = M2C_FIELD(arg0, void **, 0x54);
            M2C_FIELD(temp_r1_2, s16 *, 6) = (s16) (temp_r6 + 0x1B);
            M2C_FIELD(temp_r1_2, s16 *, 8) = temp_r5;
            if (var_r4 != 3) {
                var_r0_5 = 0;
            } else if (M2C_FIELD(((var_r4 * 0x18) + M2C_FIELD(arg0, s32 *, 0x44)), s32 *, 0xC) != 4) {
                var_r0_5 = 0;
            } else {
                var_r0_5 = 1;
            }
            if (var_r0_5 != 0) {
                temp_r5_2 = M2C_FIELD(arg0, void **, 0x54);
                temp_r1_3 = (M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~1) | 1;
                M2C_FIELD(temp_r5_2, u8 *, 0x20) = temp_r1_3;
                M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((temp_r1_3 & ~0x1E) | 0x14);
                DrawTextSprite(temp_r5_2);
                M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~1);
            } else {
                DrawTextSprite(M2C_FIELD(arg0, void **, 0x54));
            }
        } else {
            AddSprite((u16) ((temp_r6 - 4) & 0x1FF), (u8) temp_r5, (u16) ((sp24 & ((s32) (func_ov003_02200cec(var_r4, (u8) M2C_FIELD(((var_r4 * 0x18) + M2C_FIELD(arg0, s32 *, 0x44)), s32 *, 0xC)) + 0x200) >> ((u32) (**data_027e01d8 << 0x11) >> 0x1E))) | 0x8400), &data_ov003_02210484, 0xB);
        }
        var_r4 += 1;
    } while ((u32) var_r4 < 8U);
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
    s16 GetSpriteAnimValue(void *);
    s32 func_ov003_021f15d4();
    s16 func_ov003_021f1608();
    s16 value;
    u8 i;
    void *second;
    void *first;
    value = func_ov003_021f1608();
    first = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(first, s16 *, 0xE) = GetSpriteAnimValue(first);
    M2C_FIELD(first, s16 *, 0x10) = value;
    M2C_FIELD(first, s16 *, 0xC) = 12;
    M2C_FIELD(first, u16 *, 2) = M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(arg0, void **, 0x48);
    M2C_FIELD(second, s16 *, 0xE) = GetSpriteAnimValue(second);
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
    void func_ov003_022048c0();
    func_ov003_022048c0();
}

