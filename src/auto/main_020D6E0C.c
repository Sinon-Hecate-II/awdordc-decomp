/* 4 functions from 0x020D6E0C to 0x020D7BC8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 v[2][2]; } OffsetTable;
extern OffsetTable data_020f4e98;
extern s32 *gCurrentMap;
void func_020d7944(s32, s32, s32, s32);

void func_020d7b04(s32 x, s32 y, s32 kind, void *p) {
OffsetTable offsets = data_020f4e98; s32 n = 0; u32 v;
v = ((u8 *)p)[12];
if (v) { func_020d7944(x + offsets.v[kind][0], y-16, n, *gCurrentMap + 0x59a4 + v*14); n++; }
v = ((u8 *)p)[13];
if (!v) return;
func_020d7944(x + offsets.v[kind][n], y-16, n, *gCurrentMap + 0x59a4 + v*14);
}
