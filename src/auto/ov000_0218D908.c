/* 4 functions from 0x0218D908 to 0x0218E584 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct {u8 pad[0x58];u16 row;} ScanRow;
static inline u16 ScanHeight(void *p){return M2C_FIELD(p,u16 *,0x5146);}

void func_ov000_0218dda4(void) {
    M2C_UNK func_01ffc328(s32);
    M2C_UNK func_ov000_02199d74(s16, s16, M2C_UNK, u8, s32);
    s32 func_ov000_021aa820(s16 *, u16, M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    s16 pos[2];
    s32 var_r3;
    s32 var_r2;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s8 *temp_r8;
    s8 *var_lr;
    s8 temp_r0_2;
    u16 temp_ip;
    void **owner;
void *temp_r7;
void *temp_r0;

    var_r5 = -1;
    var_r4 = -1;
    var_r6 = -1;
    func_01ffc328(M2C_FIELD(*gCurrentMap, s32 *, 0x52D0));
    var_r3 = 0;
    owner=gCurrentMap;
    temp_r7 = *owner;
    if ((s32) M2C_FIELD(temp_r7, u16 *, 0x5146) > 0) {
        temp_ip = M2C_FIELD(temp_r7, u16 *, 0x5144);
        do {
            var_r2 = 0;
            if ((s32) temp_ip > 0) {
                temp_r8 = M2C_FIELD((temp_r7 + ((u32)var_r3 << 2)), s8 **, 0x52E8);
                var_lr = temp_r8;
                do {
                    if ((s32) *var_lr >= 0) {
                        temp_r0 = temp_r7 + ((ScanRow *)(temp_r7 + ((u32)var_r3 << 1) + 0x3700))->row + var_r2;
                        if (((M2C_FIELD(temp_r0, u8 *, 0x1420) & 0x1F) == 0x18) && (M2C_FIELD(temp_r0, u8 *, 0) == 0)) {
                            temp_r0_2 = *(temp_r8 + var_r2);
                            if ((s32) temp_r0_2 > var_r6) {
                                var_r4 = var_r2;
                                var_r5 = var_r3;
                                var_r6 = (s32) temp_r0_2;
                            }
                        }
                    }
                    var_r2 += 1;
                    var_lr += 1;
                } while (var_r2 < (s32) temp_ip);
            }
            var_r3 += 1;
        } while (var_r3 < (s32) ScanHeight(temp_r7));
    }
    if (var_r6 == -1) {
        return;
    }
    pos[0] = (s16) var_r4;
    pos[1] = (s16) var_r5;
    if (func_ov000_021aa820(pos, M2C_FIELD(*owner, u16 *, 0x52A4), 1, 0) != 1) {
        return;
    }
    func_ov000_02199d74((s16) var_r4, (s16) var_r5, 0x13, (u8) pos[0], (s32) (u8) pos[1]);
}
