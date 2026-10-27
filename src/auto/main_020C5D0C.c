/* 54 functions from 0x020C5D0C to 0x020C6CF8 (main), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1[5];
    u16 unk6 : 7;
    u16 unk6_7 : 4;
    u16 unk6_11 : 5;
    u8 unk8[3];
    u8 unkB : 4;
    u8 unkB_4 : 4;
    u8 unkC[2];
} UnkStruct_020C5D0C;

s32 func_020c5d0c(void) {
    s32 func_020cd6d4();
    extern u8 data_02168f0c;
    if ((data_02168f0c == 0) && (func_020cd6d4() != 0)) {
        return 0;
    }
    return 2;
}

s32 func_020c5d3c(void) {
    s32 func_020cd6fc();
    extern u8 data_02168f0c;
    if ((data_02168f0c == 0) && (func_020cd6fc() != 0)) {
        return 0;
    }
    return 2;
}

u8 func_020c5d6c(void) {
    s32 func_020bee64();
    M2C_UNK func_020befd8();
    extern u8 data_02168f0c;
    u8 var_r0;

    if (data_02168f0c != 0) {
        return 2;
    }
    func_020befd8();
    if (func_020bee64() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020c5da4(void) {
    M2C_UNK func_ov000_0216aaf4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_0216aaf4();
}

void func_020c5db4(void) {
    M2C_UNK func_ov000_02171214();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_02171214();
}

void func_020c5dc4(void) {
    M2C_UNK func_020b9140(M2C_UNK);
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_020b9140(0);
}

void func_020c5de0(void) {
    extern void **gCurrentMap;
    func_020c0784();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B4) = 3;
}

s32 func_020c5e08(void) {
    s32 func_020cd6d4();
    s32 func_ov000_0216b104();
    if ((func_020cd6d4() != 0) && (func_ov000_0216b104() != 0)) {
        return 0;
    }
    return 2;
}

s32 func_020c5e30(void) {
    s32 func_020a8afc(u16);
    extern void **gCurrentMap;

    if (func_020a8afc(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c5e60(void) {
    struct bits8 {
        u32 value : 8;
    };
    s32 func_020a88e8(u16);
    s32 func_020d1980(s32);
    extern u8 data_02168f0c;
    extern void **gCurrentMap;
    s32 var_r4;
    s32 var_r5;
    u32 temp_r0;

    if (func_020a88e8(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) != 0) {
        return 2;
    }
    if (data_02168f0c != 0) {
        return 2;
    }
    var_r4 = 1;
    var_r5 = 0x8C;
    do {
        if (func_020d1980(var_r4) != 0) {
            temp_r0 = ((struct bits8 *) ((s8 *) *gCurrentMap + var_r5 + 0x6810))->value;
            if (temp_r0 != 0) {
                return 0;
            }
        }
        var_r4 += 1;
        var_r5 += 0x8C;
    } while (var_r4 < 5);
    return 2;
}

s32 func_020c5efc(void) {
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 count = 0;
    s32 i;
    void *base = *gCurrentMap;
    u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
    for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33; i++) {
        UnkStruct_020C5D0C *entry = &((UnkStruct_020C5D0C *)((u8 *)base + 0x59A4))[i];
        if (entry->unk0 != 0) { count += 1; }
    }
    if (count == 0) { return 1; }
    return 0;
}

s32 func_020c5f94(void) {
    s32 func_020c5cd4();
    s32 func_020c5efc();
    if (func_020c5cd4() == 2) {
        return 2;
    }
    return func_020c5efc();
}

s32 func_020c5fb0(void) {
    s32 func_020a8910(u16);
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s32 count = 0;
    s32 i;
    void *base;
    u16 start;

    if (func_020a8910(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) != 0) {
        return 2;
    }
    base = *gCurrentMap;
    start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
    for (i = start + 1; i < data_ov000_021aeef4[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33; i++) {
        UnkStruct_020C5D0C *entry = &((UnkStruct_020C5D0C *)((u8 *)base + 0x59A4))[i];
        if (entry->unk0 != 0) { count += 1; }
    }
    if (count == 0) { return 1; }
    return 0;
}

s32 func_020c606c(void) {
    s32 func_020c5fb0();
    if (func_020c5cd4() == 2) {
        return 2;
    }
    return func_020c5fb0();
}

s32 func_020c6088(void) {
    extern void **gCurrentMap;
    void *base = *gCurrentMap;
    s16 a = M2C_FIELD(base, s16 *, 0x52DE);
    s16 b = M2C_FIELD(base, s16 *, 0x52DC);
    u16 c = M2C_FIELD((u8 *)base + a * 2, u16 *, 0x3758);
    if (M2C_FIELD(base, u8 *, b + c) == 0) { return 0; }
    return 2;
}

s32 func_020c60c8(void) {
    s32 func_020a7074(s32, s32);
    extern void **gCurrentMap;
    void *base = *gCurrentMap;
    s16 a = M2C_FIELD(base, s16 *, 0x52DE);
    s16 b = M2C_FIELD(base, s16 *, 0x52DC);
    u16 c = M2C_FIELD((u8 *)base + a * 2, u16 *, 0x3758);
    u8 d = M2C_FIELD(base, u8 *, b + c);

    if (d == 0) {
        return 2;
    }
    if (func_020a7074(M2C_FIELD(base, s32 *, 0x52D0), (s8 *)base + 0x59A4 + d * 0xE) == 0) {
        return 2;
    }
    return 0;
}

s32 func_020c6350(void) {
    s32 func_020ba790(s16, s16);
    extern void **gCurrentMap;
    void *base = *gCurrentMap;
    s16 a = M2C_FIELD(base, s16 *, 0x52DC);
    s16 b = M2C_FIELD(base, s16 *, 0x52DE);

    if (func_020ba790(a, b) == 1) {
        return 0;
    }
    return 2;
}

s32 func_020c6384(void) {
 s32 func_020c9430(s32); s32 func_020a85dc(s32); s32 func_020ba770(void *,s32,s32);
 extern void **gCurrentMap;
 void *base;
 if(func_020c9430(0)!=0)return 2;
 if(func_020c6350()==0)return 2;
 if(func_020a85dc(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->unk0)!=0)return 2;
 base=*gCurrentMap;
 if(func_020ba770(M2C_FIELD(base,void **,0x52D0),M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE))!=0)return 0;
 return 2;
}

s32 func_020c6414(void) {
 s32 func_020c9430(s32); s32 func_020a85dc(s32); s32 func_020ba780(void *,s32,s32);
 extern void **gCurrentMap;
 void *base;
 if(func_020c9430(1)!=0)return 2;
 if(func_020c6350()==0)return 2;
 if(func_020a85dc(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->unk0)!=0)return 2;
 base=*gCurrentMap;
 if(func_020ba780(M2C_FIELD(base,void **,0x52D0),M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE))!=0)return 0;
 return 2;
}

s32 func_020c64a4(void) {
 s32 func_020a85dc(s32);
 extern void **gCurrentMap;
 void *base; u32 index;
 if(func_020c6350()==0)return 2;
 if(func_020a85dc(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->unk0)==0)return 2;
 base=*gCurrentMap;
 index=M2C_FIELD(M2C_FIELD(base,void **,0x52D0),u8 *,12);
 if(index==0)return 2;
 if(M2C_FIELD((u8 *)base+index*14,u16 *,0x59A8)&1)return 2;
 if(M2C_FIELD(base,s16 *,0x52DC)!=M2C_FIELD(base,s16 *,0x52D8)||M2C_FIELD(base,s16 *,0x52DE)!=M2C_FIELD(base,s16 *,0x52DA))return 2;
 return 0;
}

s32 func_020c6554(void) {
 s32 func_020a85dc(s32);
 extern void **gCurrentMap;
 void *base; u32 index;
 if(func_020c6350()==0)return 2;
 if(func_020a85dc(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->unk0)==0)return 2;
 base=*gCurrentMap;
 index=M2C_FIELD(M2C_FIELD(base,void **,0x52D0),u8 *,13);
 if(index==0)return 2;
 if(M2C_FIELD((u8 *)base+index*14,u16 *,0x59A8)&1)return 2;
 if(M2C_FIELD(base,s16 *,0x52DC)!=M2C_FIELD(base,s16 *,0x52D8)||M2C_FIELD(base,s16 *,0x52DE)!=M2C_FIELD(base,s16 *,0x52DA))return 2;
 return 0;
}

s32 func_020c6604(void){
extern void **gCurrentMap;
extern u8 data_ov000_021b5c05[];
void *base; UnkStruct_020C5D0C *p; u16 idx;
if(func_020a85f0(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->unk0)==0)return 2;
base=*gCurrentMap;
p=M2C_FIELD(base,UnkStruct_020C5D0C **,0x52d0);
if(M2C_FIELD(p,u8 *,13))return 2;
if(M2C_FIELD(base,s16 *,0x52dc)!=M2C_FIELD(base,s16 *,0x52d8)||M2C_FIELD(base,s16 *,0x52de)!=M2C_FIELD(base,s16 *,0x52da))return 2;
if(data_ov000_021b5c05[p->unk0*0x70] && p->unk6_7==0)return 2;
idx=M2C_FIELD(base,u16 *,0x52a4);
if(func_020d2d38(idx,17)>M2C_FIELD(base+idx*0x8c,s32 *,0x67a4))return 2;
if(func_020d2dcc(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==0)return 2;
return 0;
}

s32 func_020c6718(void) {
 extern void **gCurrentMap;
 s32 func_020a7e08(void *); s32 func_01ffb3d0(s32); s32 func_01ffc3e8(s32,s32); s32 func_0209fe44(s32);
 void *base;
 if(M2C_FIELD(*gCurrentMap,u16 *,0x52B4)==7)return 2;
 if(func_020c60c8()==0)return 2;
 if(func_020c6350()==0)return 2;
 if(func_020a7e08(M2C_FIELD(*gCurrentMap,void **,0x52D0))==0)return 2;
 func_01ffb3d0(-1);
 base=*gCurrentMap;
 if(func_0209fe44(func_01ffc3e8(M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE)))!=0)return 0;
 return 2;
}

s32 func_020c67bc(void) {
 extern void **gCurrentMap;
 if(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u16 *,4)&0x20)return 2;
 if(func_020c60c8()==0)return 2;
 if(func_020c6350()==0)return 2;
 return 0;
}

s32 func_020c6134(void) {
    s32 func_020c60c8();
    s32 func_020c6350();
    M2C_UNK func_01ffb3d0(s32);
    s32 func_0209fd2c();
    extern void **gCurrentMap;
    void *base;
    s16 a;
    s16 b;

    if (func_020c60c8() == 0) {
        return 2;
    }
    if (func_020c6350() == 0) {
        return 2;
    }
    func_01ffb3d0(-1);
    base = *gCurrentMap;
    a = M2C_FIELD(base, s16 *, 0x52DE);
    b = M2C_FIELD(base, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD((s8 *)base + a * 4, u8 **, 0x52E8), u8 *, b) = 0;
    if (func_0209fd2c() != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c61a4(void) {
    s32 func_020c60c8();
    s32 func_020c6350();
    M2C_UNK func_01ffb3d0(s32);
    s32 func_0209ff34();
    extern void **gCurrentMap;
    void *base;
    s16 a;
    s16 b;

    if (func_020c60c8() == 0) {
        return 2;
    }
    if (func_020c6350() == 0) {
        return 2;
    }
    func_01ffb3d0(-1);
    base = *gCurrentMap;
    a = M2C_FIELD(base, s16 *, 0x52DE);
    b = M2C_FIELD(base, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD((s8 *)base + a * 4, u8 **, 0x52E8), u8 *, b) = 0;
    if (func_0209ff34() != 0) {
        return 0;
    }
    return 2;
}

/* Returns 0 on success, 2 if the attempted move/attack is blocked. */
s32 func_020c6214(void) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c09[], data_ov000_021b5c08[];
    s32 func_020c9430(s32);
    s32 func_020a85c8(s32);
    s32 func_0209f990(void);
    s32 func_01ffb3d0(s32);
    void func_01ffc368(s32, s32, void *);
    void *base;
    s32 x, y;

    if (func_020c9430(0) != 0 || func_020c9430(1) != 0) {
        return 2;
    }
    base = *gCurrentMap;
    y = M2C_FIELD(base, s16 *, 0x52DE);
    x = M2C_FIELD(base, s16 *, 0x52DC);
    if (M2C_FIELD(base, u8 *, x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)) != 0) {
        return 2;
    }
    if (x != M2C_FIELD(base, s16 *, 0x52D8) || y != M2C_FIELD(base, s16 *, 0x52DA)) {
        s32 id = ((UnkStruct_020C5D0C *)M2C_FIELD(base, void **, 0x52D0))->unk0;
        if (data_ov000_021b5c09[id * 0x70] != 1 && func_020a85c8(id) == 0) {
            return 2;
        }
    }
    if (data_ov000_021b5c08[((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap, void **, 0x52D0))->unk0 * 0x70] == 0) {
        return 2;
    }
    func_01ffb3d0(-1);
    base = *gCurrentMap;
    func_01ffc368(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), M2C_FIELD(base, void **, 0x52D0));
    if (func_0209f990() != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c680c(void) {
    s32 func_020c67bc();
    extern void **gCurrentMap;

    switch (((UnkStruct_020C5D0C *) M2C_FIELD(*gCurrentMap, u8 **, 0x52D0))->unk0) {
    case 0x16:
        return func_020c67bc();
    }
    return 2;
}

s32 func_020c684c(void) {
 s32 func_020c6350(); extern void **gCurrentMap;
 if (!func_020c60c8()) return 2;
 if (!func_020c6350()) return 2;
 if (M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u16 *,4)&0x20) return 0;
 return 2;
}

s32 func_020c689c(void) {
    s32 func_020c684c();
    extern void **gCurrentMap;

    switch (((UnkStruct_020C5D0C *) M2C_FIELD(*gCurrentMap, u8 **, 0x52D0))->unk0) {
    case 0x16:
        return func_020c684c();
    }
    return 2;
}

s32 func_020c68dc(void) {
 extern void **gCurrentMap;
 void *base=*gCurrentMap;
 UnkStruct_020C5D0C *p;
 if (M2C_FIELD(base,u8 *,0x5156)==0 && M2C_FIELD(base,u8 *,0x5158)!=2) return 2;
 p=M2C_FIELD(base,UnkStruct_020C5D0C **,0x52D0);
 if(p->unk0!=5) return 2;
 if(M2C_FIELD(base,s16 *,0x52DC)!=M2C_FIELD(base,s16 *,0x52D8) || M2C_FIELD(base,s16 *,0x52DE)!=M2C_FIELD(base,s16 *,0x52DA)) return 2;
 if (p->unk6_7) return 0;
 return 2;
}

void func_020c6968(void) {
    M2C_UNK func_020c0adc();
    M2C_UNK func_020c757c();
    M2C_UNK func_020c0784();
    func_020c0adc();
    func_020c0784();
    func_020c757c();
}

void func_020c697c(void) {
    extern M2C_UNK data_0212a6c4;
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_01ffa3dc(&data_0212a6c4, 7);
}

void func_020c69a0(void) {
    M2C_UNK func_020d464c();
    M2C_UNK func_ov000_02171028();
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_ov000_02171028();
}

void func_020c69b8(void) {
    M2C_UNK func_ov000_0217242c();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_0217242c();
}

void func_020c69c8(void) {
    M2C_UNK func_ov000_02171750();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_ov000_02171750();
}

void func_020c69d8(void) {
    M2C_UNK func_020cbfe4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020cbfe4();
}

void func_020c69e8(void) {
    M2C_UNK func_020cc08c();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020cc08c();
}

void func_020c69f8(void) {
    M2C_UNK func_ov000_021707c0();
    func_020c0adc();
    func_020c0784();
    func_020d464c();
    func_ov000_021707c0();
}

void func_020c6a10(void) {
    M2C_UNK func_020844f8();
    M2C_UNK func_020bbb08();
    extern u8 data_02168f0c;
    func_020c0784();
    func_020bbb08();
    if (data_02168f0c == 0) {
        return;
    }
    func_020844f8();
}

void func_020c6a38(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212a714;
    func_020c0784();
    func_01ffa3dc(&data_0212a714, 7);
}

void func_020c6a54(void) {
    M2C_UNK func_020b4cf4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020b4cf4();
}

void func_020c6a64(void) {
    M2C_UNK func_020b4d24();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020b4d24();
}

void func_020c6a74(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_020a15e4();
 s32 func_020c9430(s32); s32 func_020c9440(s32,s32,s32);
 M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **gCurrentMap;
 void *base; s32 a,b;
 func_020d468c(); func_020c0784();
 if(!func_020c9430(0) && !func_020c9430(1)) {
 func_ov000_02199f50(2,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0); return;
 }
 func_020a15e4();
 base=*gCurrentMap;
 a=func_020c9440(M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE),0);
 b=func_020c9440(M2C_FIELD(base,s16 *,0x52DC),M2C_FIELD(base,s16 *,0x52DE),1);
 func_ov000_02199f50(8,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),(u8)a,(u8)b);
}

void func_020c6b30(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 func_ov000_02199f50(3,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6b68(void) {
    M2C_UNK func_020bbba4();
    M2C_UNK func_020c0784();
    func_020c0784();
    func_020bbba4();
}

void func_020c6b78(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 func_ov000_02199f50(7,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6bb0(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 func_ov000_02199f50(9,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6be8(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 func_ov000_02199f50(6,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

void func_020c6c20(void) {
    M2C_UNK func_020cb018(M2C_UNK);
    M2C_UNK func_020d4704();
    func_020cb018(0);
    func_020c0784();
    func_020d4704();
}

void func_020c6c38(void) {
    func_020cb018(1);
    func_020c0784();
    func_020d4704();
}

void func_020c6c50(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_021696d4(); M2C_UNK func_020d5d0c(void *,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784(); func_ov000_021696d4();
 func_020d5d0c(M2C_FIELD(*gCurrentMap,void **,0x52D0),0,0);
}

void func_020c6c88(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_021696d4(); M2C_UNK func_020d5d0c(void *,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784(); func_ov000_021696d4();
 func_020d5d0c(M2C_FIELD(*gCurrentMap,void **,0x52D0),1,0);
}

void func_020c6cc0(void) {
 M2C_UNK func_020d468c(); M2C_UNK func_020c0784(); M2C_UNK func_ov000_02199f50(s32,u8,s32,s32);
 extern void **gCurrentMap;
 func_020d468c(); func_020c0784();
 func_ov000_02199f50(0x17,M2C_FIELD(*gCurrentMap,u8 *,0x52D4),0,0);
}

