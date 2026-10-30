/* 29 functions from 0x02180738 to 0x021816C4 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[0x8c]; } PlayerRecord02180738;
static inline u8 PlayerMode02180738(PlayerRecord02180738 *players, s32 index) { return players[index].bytes[0x2a]; }

void func_ov000_02180738(void) {
M2C_UNK func_ov000_02198c08();
M2C_UNK func_ov000_0218cfec();
M2C_UNK func_ov000_02199d74(u8, u8, s32, s32, s32);
extern void **gCurrentMap;
void *temp_r1;
func_ov000_02198c08();
func_ov000_0218cfec();
temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
func_ov000_02199d74(M2C_FIELD(temp_r1, u8 *, 1), M2C_FIELD(temp_r1, u8 *, 2), 2, 0, 0);
}

void func_ov000_02180778(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219619c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_0219619c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_021807d8(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_021962f8();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_021962f8();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180838(void) {
M2C_UNK func_ov000_02198c08();
M2C_UNK func_ov000_0218eea8();
M2C_UNK func_ov000_0218ca94();
M2C_UNK func_ov000_0219619c();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_0218ae58();
M2C_UNK func_ov000_021967fc();
M2C_UNK func_ov000_0218b02c();
M2C_UNK func_ov000_02186a18();
extern void **gCurrentMap;
void *temp_r3;
func_ov000_02198c08();
func_ov000_0218eea8();
func_ov000_0218ca94();
temp_r3 = *gCurrentMap;
if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) { func_ov000_02186a18(); }
func_ov000_0219619c();
func_ov000_02194370();
func_ov000_0218ae58();
func_ov000_021967fc();
func_ov000_0218b02c();
}

void func_ov000_02180894(void) {
M2C_UNK func_ov000_02198c60();
M2C_UNK func_ov000_0218edd8();
M2C_UNK func_ov000_0218ca94();
M2C_UNK func_ov000_0218d4b4();
M2C_UNK func_ov000_021963f8();
M2C_UNK func_ov000_021954a4();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_0218ae58();
M2C_UNK func_ov000_021965dc();
M2C_UNK func_ov000_0219553c();
M2C_UNK func_ov000_021967fc();
M2C_UNK func_ov000_0218b02c();
M2C_UNK func_ov000_02186a18();
extern void **gCurrentMap;
void *temp_r3;
func_ov000_02198c60();
func_ov000_0218edd8();
func_ov000_0218ca94();
func_ov000_0218d4b4();
temp_r3 = *gCurrentMap;
if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) { func_ov000_02186a18(); }
func_ov000_021963f8();
func_ov000_021954a4();
func_ov000_02194370();
func_ov000_0218ae58();
func_ov000_021965dc();
func_ov000_0219553c();
func_ov000_021967fc();
func_ov000_0218b02c();
}

void func_ov000_02180900(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218edd8();
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
}

void func_ov000_02180914(void) {
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_02198c08();
    func_ov000_02198c08();
    func_ov000_0218ca94();
}

void func_ov000_02180924(void) {
    M2C_UNK func_ov000_0218cfec();
    M2C_UNK func_ov000_02198c08();
    func_ov000_02198c08();
    func_ov000_0218cfec();
}

void func_ov000_02180934(void) {
M2C_UNK func_ov000_02198c60();
M2C_UNK func_ov000_0218edd8();
M2C_UNK func_ov000_0218d4b4();
M2C_UNK func_ov000_021954a4();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_0218ae58();
M2C_UNK func_ov000_021965dc();
M2C_UNK func_ov000_0219553c();
M2C_UNK func_ov000_021967fc();
M2C_UNK func_ov000_0218b02c();
M2C_UNK func_ov000_0218ca94();
s32 func_020a85c8(u32);
extern void **gCurrentMap;
void *temp_r3;
func_ov000_02198c60();
func_ov000_0218edd8();
temp_r3 = *gCurrentMap;
if (M2C_FIELD(temp_r3, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r3, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) { func_ov000_0218ca94(); }
func_ov000_0218d4b4();
func_ov000_021954a4();
func_ov000_02194370();
func_ov000_0218ae58();
func_ov000_021965dc();
func_ov000_0219553c();
func_ov000_021967fc();
func_ov000_0218b02c();
}

void func_ov000_021809b0(void) {
    M2C_UNK func_ov000_02198c08();
    M2C_UNK func_ov000_0218eea8();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_0218ca94();
    s32 func_020a85c8(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    func_ov000_02198c08();
    func_ov000_0218eea8();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r0, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) {
        func_ov000_0218ca94();
    }
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_0219553c();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180a28(void) {
M2C_UNK func_ov000_02198c60();
M2C_UNK func_ov000_0218edd8();
M2C_UNK func_ov000_0218d4b4();
M2C_UNK func_ov000_0219553c();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_0218ae58();
M2C_UNK func_ov000_021965dc();
M2C_UNK func_ov000_021954a4();
M2C_UNK func_ov000_021967fc();
M2C_UNK func_ov000_0218b02c();
M2C_UNK func_ov000_0218ca94();
s32 func_020a85c8(u32);
extern void **gCurrentMap;
void *temp_r3;
func_ov000_02198c60();
func_ov000_0218edd8();
temp_r3 = *gCurrentMap;
if (M2C_FIELD(temp_r3, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r3, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) { func_ov000_0218ca94(); }
func_ov000_0218d4b4();
func_ov000_0219553c();
func_ov000_02194370();
func_ov000_0218ae58();
func_ov000_021965dc();
func_ov000_021954a4();
func_ov000_021967fc();
func_ov000_0218b02c();
}

void func_ov000_02180aa4(void) {
M2C_UNK func_ov000_02198c60();
M2C_UNK func_ov000_0218edd8();
M2C_UNK func_ov000_0218d4b4();
M2C_UNK func_ov000_02195750();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_0218ae58();
M2C_UNK func_ov000_021965dc();
M2C_UNK func_ov000_021954a4();
M2C_UNK func_ov000_021967fc();
M2C_UNK func_ov000_0218b02c();
M2C_UNK func_ov000_0218ca94();
s32 func_020a85c8(u32);
extern void **gCurrentMap;
void *temp_r3;
func_ov000_02198c60();
func_ov000_0218edd8();
temp_r3 = *gCurrentMap;
if (M2C_FIELD(temp_r3, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r3, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) { func_ov000_0218ca94(); }
func_ov000_0218d4b4();
func_ov000_02195750();
func_ov000_02194370();
func_ov000_0218ae58();
func_ov000_021965dc();
func_ov000_021954a4();
func_ov000_021967fc();
func_ov000_0218b02c();
}

void func_ov000_02180b20(void) {
M2C_UNK func_ov000_02198c60();
M2C_UNK func_ov000_0218edd8();
M2C_UNK func_ov000_0218d4b4();
M2C_UNK func_ov000_02195ea4();
M2C_UNK func_ov000_0218ae58();
M2C_UNK func_ov000_021954a4();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_021965dc();
M2C_UNK func_ov000_021967fc();
M2C_UNK func_ov000_0218b02c();
M2C_UNK func_ov000_0218ca94();
s32 func_020a85c8(u32);
extern void **gCurrentMap;
void *temp_r3;
func_ov000_02198c60();
func_ov000_0218edd8();
temp_r3 = *gCurrentMap;
if (M2C_FIELD(temp_r3, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r3, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) { func_ov000_0218ca94(); }
func_ov000_0218d4b4();
func_ov000_02195ea4();
func_ov000_0218ae58();
func_ov000_021954a4();
func_ov000_02194370();
func_ov000_021965dc();
func_ov000_021967fc();
func_ov000_0218b02c();
}

void func_ov000_02180b9c(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219604c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_0218ca94();
    s32 func_020a85c8(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r0, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) {
        func_ov000_0218ca94();
    }
    func_ov000_0218d4b4();
    func_ov000_0219604c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180c10(void) {
    M2C_UNK func_ov000_0218cfec();
    M2C_UNK func_ov000_02199d74(u8, u8, s32, s32, s32);
    extern void **gCurrentMap;
    void *temp_r0;
    void *temp_r1;
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r0, u8 *, 0x5158) == 2) {
        func_ov000_0218cfec();
    }
    temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    func_ov000_02199d74(M2C_FIELD(temp_r1, u8 *, 1), M2C_FIELD(temp_r1, u8 *, 2), 2, 0, 0);
}

void func_ov000_02180c74(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219619c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_0218ca94();
    s32 func_020a85c8(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r0, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) {
        func_ov000_0218ca94();
    }
    func_ov000_0218d4b4();
    func_ov000_0219619c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180ce8(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_021962f8();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_0218ca94();
    s32 func_020a85c8(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r0, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) {
        func_ov000_0218ca94();
    }
    func_ov000_0218d4b4();
    func_ov000_021962f8();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180d5c(void) {
    M2C_UNK func_ov000_02198c08();
    M2C_UNK func_ov000_0218eea8();
    M2C_UNK func_ov000_0219619c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_0218ca94();
    s32 func_020a85c8(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    func_ov000_02198c08();
    func_ov000_0218eea8();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, 0x5156) != 0 || M2C_FIELD(temp_r0, u8 *, 0x5158) == 2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x52D0), u8 *, 0) << 26) >> 26) != 0) {
        func_ov000_0218ca94();
    }
    func_ov000_0219619c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180dcc(void) {
 M2C_UNK func_ov000_02198c60(); M2C_UNK func_ov000_0218edd8(); M2C_UNK func_ov000_0218ca94(); M2C_UNK func_ov000_0218d4b4(); M2C_UNK func_ov000_021963f8(); M2C_UNK func_ov000_021954a4(); M2C_UNK func_ov000_02194370(); M2C_UNK func_ov000_0218ae58(); M2C_UNK func_ov000_021965dc(); M2C_UNK func_ov000_0219553c(); M2C_UNK func_ov000_021967fc(); M2C_UNK func_ov000_0218b02c();
 s32 func_020a85c8(u32); extern void **gCurrentMap; void *p;
 func_ov000_02198c60(); func_ov000_0218edd8(); p=*gCurrentMap;
 if(M2C_FIELD(p,u8 *,0x5156)!=0 || M2C_FIELD(p,u8 *,0x5158)==2 || func_020a85c8((u32)(M2C_FIELD(M2C_FIELD(p,void **,0x52d0),u8 *,0)<<26)>>26)!=0) func_ov000_0218ca94();
 func_ov000_0218d4b4(); func_ov000_021963f8(); func_ov000_021954a4(); func_ov000_02194370(); func_ov000_0218ae58(); func_ov000_021965dc(); func_ov000_0219553c(); func_ov000_021967fc(); func_ov000_0218b02c();
}

void func_ov000_02180e4c(void) {
 s32 func_ov000_02180410(); M2C_UNK func_ov000_02198c60(); M2C_UNK func_ov000_0218f0ec(); M2C_UNK func_ov000_0218f37c();
 extern void **gCurrentMap; u32 x; void *p;
 if(func_ov000_02180410()) return;
 x=(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28;
 if(x==6 || x==8) return;
 func_ov000_02198c60();
 p=*gCurrentMap;
 if(M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67ce)!=3) func_ov000_0218f0ec();
 func_ov000_0218f37c();
}

void func_ov000_02180ec8(void) {
    M2C_UNK func_ov000_0218f468();
    extern void **gCurrentMap;
    u32 temp_r0;

    if (func_ov000_02180410() != 0) {
        return;
    }
    temp_r0 = (u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 0x1C) >> 0x1C;
    if ((temp_r0 != 6) && (temp_r0 != 8)) {
        func_ov000_02198c60();
        func_ov000_0218f468();
    }
}

void func_ov000_02180f14(void) {
extern void **gCurrentMap;
void *p; u32 type;
if(func_ov000_02180410()) return;
type=(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28;
if(type==6 || type==8)return;
func_ov000_02198c60();
p=*gCurrentMap;
if(M2C_FIELD(p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67ce)!=3) {
func_ov000_0218f0ec();
func_ov000_0219137c();
}
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)<=60)func_ov000_02190f74();
func_ov000_0218edd8(); func_ov000_0218f37c(); func_ov000_0218fbd4();
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)>60)func_ov000_02190f74();
}

#pragma opt_strength_reduction off
void func_ov000_02180ff4(void) {
M2C_UNK func_ov000_02198c60();
M2C_UNK func_ov000_0218046c();
M2C_UNK func_ov000_0218cfec();
M2C_UNK func_ov000_0218f0ec();
M2C_UNK func_ov000_0219137c();
M2C_UNK func_ov000_0218ca94();
M2C_UNK func_ov000_021962f8();
M2C_UNK func_ov000_02190f74();
M2C_UNK func_ov000_0218edd8();
M2C_UNK func_ov000_0218f37c();
M2C_UNK func_ov000_0218fbd4();
M2C_UNK func_ov000_02186a18();
M2C_UNK func_ov000_021911bc();
M2C_UNK func_ov000_0218d908();
M2C_UNK func_ov000_02190094();
M2C_UNK func_ov000_02194370();
M2C_UNK func_ov000_021954a4();
M2C_UNK func_ov000_0218b02c();
s32 func_ov000_02180410();
extern void **gCurrentMap; extern void *data_ov000_021df580;
void *p; PlayerRecord02180738 *players; u32 type; s32 done;
if(func_ov000_02180410()) {func_ov000_0218046c();return;}
func_ov000_02198c60();p=*gCurrentMap;
type=(u32)(M2C_FIELD(M2C_FIELD(p,void **,0x52d0),u8 *,11)<<28)>>28;
if(type==6){func_ov000_0218cfec();return;}
if(type==8){func_ov000_0218f0ec();func_ov000_0219137c();func_ov000_0218ca94();func_ov000_021962f8();return;}
if(M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67ce)!=3){func_ov000_0218f0ec();func_ov000_0219137c();}
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)<=60)func_ov000_02190f74();
func_ov000_0218edd8();func_ov000_0218f37c();func_ov000_0218fbd4();
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)>60)func_ov000_02190f74();
p=*gCurrentMap;done=0;
players=(PlayerRecord02180738 *)((u8 *)p+0x67a4);
type=players[M2C_FIELD(p,u16 *,0x52a4)].bytes[0x2a];
if(type==3 || (type==2 && ((u32)(M2C_FIELD(M2C_FIELD(p,void **,0x52d0),u8 *,0)<<26)>>26)!=2)){func_ov000_02186a18();done=1;}
func_ov000_0218ca94();func_ov000_021911bc();
if(!done){p=*gCurrentMap;if(M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67ce)!=0)func_ov000_02186a18();}
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)<=60)func_ov000_0218d908();
func_ov000_02190094();func_ov000_02194370();
M2C_FIELD(data_ov000_021df580,u16 *,8)|=0x20;
func_ov000_02190094();func_ov000_021954a4();func_ov000_0218b02c();
}
#pragma opt_strength_reduction reset
void func_ov000_021811e8(void) {
 s32 func_ov000_02180410(); M2C_UNK func_ov000_0218049c(); M2C_UNK func_ov000_021804b0(); M2C_UNK func_ov000_021804c4();
 extern void **gCurrentMap; extern void *data_ov000_021df580;
 if(func_ov000_02180410()) return;
 if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,8)<<18)>>30)==2)
 M2C_FIELD(data_ov000_021df580,u16 *,8)|=128;
 switch((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28) {
 case 0: case 2: case 3: case 4: case 5: case 7: case 8: func_ov000_0218049c(); return;
 case 1: case 9: func_ov000_021804b0(); return;
 case 6: func_ov000_021804c4(); return;
 }
}

/* Dispatches on the low nibble of byte at p+0x52db; runs various step handlers. */
void func_ov000_021812a8(void) {
extern void **gCurrentMap;
void *state;
if(func_ov000_02180410()) {func_ov000_0218046c(); return;}
state=*gCurrentMap;
switch((u32)(M2C_FIELD(M2C_FIELD(state,void **,0x52d0),u8 *,11)<<28)>>28) {
case 0: func_ov000_021804d4(); return;
case 1: func_ov000_0218053c(); return;
case 2: if(func_ov000_021a9c28()==1)func_ov000_021805a0(); else func_ov000_021804d4(); return;
case 3: func_ov000_02180608(); return;
case 4: func_ov000_02180670(); return;
case 5: if(func_020d243c(M2C_FIELD(state,u16 *,0x52a4))==1)func_ov000_021806d8(); else func_ov000_02180670(); return;
case 7: func_ov000_02180778(); return;
case 8: func_ov000_021807d8(); return;
case 9: func_ov000_02180838(); return;
case 6: func_ov000_02180738(); return;
case 10: func_ov000_02180894(); return;
}
}

void func_ov000_021813a4(void) {
 s32 func_ov000_02180410();
 extern void **gCurrentMap; extern void *data_ov000_021df580;
 if(func_ov000_02180410()) return;
 if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,8)<<18)>>30)!=2)
 M2C_FIELD(data_ov000_021df580,u16 *,8)|=128;
 switch((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28) {
 case 0: case 2: case 3: case 4: case 5: case 7: case 8: func_ov000_02180900(); return;
 case 1: case 9: func_ov000_02180914(); return;
 case 6: func_ov000_02180924(); return;
 case 10: func_ov000_02180dcc(); return;
 }
}

/* Dispatches on the low nibble of the unit state's byte at +0x52DB (state step) and runs the matching handler. */
void func_ov000_02181470(void) {
    extern void **gCurrentMap;
    void *state;
    if (func_ov000_02180410()) { func_ov000_0218046c(); return; }
    state = *gCurrentMap;
    switch ((u32)(M2C_FIELD(M2C_FIELD(state, void **, 0x52D0), u8 *, 11) << 28) >> 28) {
    case 0: func_ov000_02180934(); return;
    case 1: func_ov000_021809b0(); return;
    case 2: if (func_ov000_021a9c28() == 1) func_ov000_02180a28(); else func_ov000_02180934(); return;
    case 3: func_ov000_02180aa4(); return;
    case 4: func_ov000_02180b20(); return;
    case 5: if (func_020d243c(M2C_FIELD(state, u16 *, 0x52a4)) == 1) func_ov000_02180b9c(); else func_ov000_02180b20(); return;
    case 6: func_ov000_02180c10(); return;
    case 7: func_ov000_02180c74(); return;
    case 8: func_ov000_02180ce8(); return;
    case 9: func_ov000_02180d5c(); return;
    }
}

void func_ov000_02181560(void) {
extern void **gCurrentMap;
s32 func_020d2dcc(u16);
s32 func_020d2d18(u16,s32);
s32 func_ov000_02178e84(u8,u8);
void *base,*unit;
u16 player;
s32 cost;u32 idx;
if(func_ov000_02180410()!=0) return;
if(func_020d2dcc(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==0)return;
base=*gCurrentMap;player=M2C_FIELD(base,u16 *,0x52a4);
cost=func_020d2d18(player,17)*10;
if(cost>M2C_FIELD((u8 *)base+player*0x8c,s32 *,0x67a4)) return;
base=*gCurrentMap;unit=M2C_FIELD(base,void **,0x52d0);
if(((u32)(M2C_FIELD(unit,u16 *,6)<<21)>>28)==0)return;
if(M2C_FIELD(unit,u8 *,13)!=0)return;
idx=M2C_FIELD(unit,u8 *,12);
if(idx!=0 && ((u32)(M2C_FIELD((u8 *)base+idx*14,u8 *,0x59a4)<<26)>>26)==17)return;
if(func_ov000_02178e84(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2))==0)return;
func_ov000_02198c60();
base=*gCurrentMap;unit=M2C_FIELD(base,void **,0x52d0);
idx=M2C_FIELD(unit,u8 *,1)+M2C_FIELD((u8 *)base+M2C_FIELD(unit,u8 *,2)*2,u16 *,0x3758);
if(M2C_FIELD((u8 *)base+idx,u8 *,0x2840)+M2C_FIELD((u8 *)base+idx,u8 *,0x2d48)>=(s32)((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25))return;
func_ov000_02199d74(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2),23,0,0);
}

void func_ov000_021816ac(void) {
    M2C_UNK func_ov000_02193998();
    if (func_ov000_02180410() != 0) {
        return;
    }
    func_ov000_02193998();
}

