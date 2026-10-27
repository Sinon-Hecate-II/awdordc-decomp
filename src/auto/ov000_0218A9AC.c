/* 3 functions from 0x0218A9AC to 0x0218B0D8 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern void (*data_ov000_021df654)(void);
void func_ov000_0217c3a4(void);
void func_ov000_0218d040(int);
void func_ov000_0218d908(void);
void func_ov000_02198c08(void);
void func_ov000_02199d74(int, int, int, int, int);

void func_ov000_0218b02c(void) {
    u16 flags;
    u8 *p;
    if (*(u8 *)((u8 *)*gCurrentMap + 0x52d6)) return;
    *(u16 *)((u8 *)data_ov000_021df580 + 8) |= 0x10;
    func_ov000_0218d908();
    func_ov000_0218d040(1);
    flags = *(u16 *)((u8 *)data_ov000_021df580 + 8);
    if (!(flags & 0x20)) {
        *(u16 *)((u8 *)data_ov000_021df580 + 8) = flags | 0x20;
        func_ov000_02198c08();
        data_ov000_021df654();
    }
    func_ov000_0217c3a4();
    p = *(u8 **)((u8 *)*gCurrentMap + 0x52d0);
    func_ov000_02199d74(p[1], p[2], 2, 0, 0);
}
