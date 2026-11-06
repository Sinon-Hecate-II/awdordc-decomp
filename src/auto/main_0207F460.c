/* 13 functions from 0x0207F460 to 0x02080414 (main), found by ds-decomp. */
#include "common.h"
static inline void Window7fafc(s32 *dst,s32 start,s32 end) { *dst=(start&511)|((end&511)<<16); }

typedef struct {
    s16 unk0;
    s16 unk2;
} Unk0207F9F4;

s32 func_0207f460(s32 id) {
    switch (id) {                                 /* irregular */
    case 0x1:
        return 1;
    case 0x8:
        return 3;
    case 0x2:
        return 6;
    case 0x5:
        return 2;
    case 0xB:
        return 7;
    case 0xA:
        return 0x27;
    case 0x4:
        return 0x20;
    case 0x3:
        return 0x21;
    case 0x9:
        return 0x22;
    case 0x7:
        return 0x23;
    case 0xD:
        return 0x24;
    case 0xE:
        return 0x25;
    case 0xC:
        return 0x168;
    case 0x1B:
        return 0x142;
    case 0x1C:
        return 0x162;
    case 0x3B:
        return 0x146;
    case 0x3C:
        return 0x166;
    case 0x6:
        return 0x181;
    case 0x1A:
        return 0x1A1;
    case 0x18:
        return 0x180;
    case 0xF:
        return 0x1C0;
    case 0x2F:
        return 0x1C5;
    case 0x4F:
        return 0x1CA;
    case 0x6F:
        return 0x1CF;
    case 0x8F:
        return 0x1D4;
    case 0x11:
        return 0x1C1;
    case 0x31:
        return 0x1C6;
    case 0x51:
        return 0x1CB;
    case 0x71:
        return 0x1D0;
    case 0x91:
        return 0x1D5;
    case 0x10:
        return 0x1C2;
    case 0x30:
        return 0x1C7;
    case 0x50:
        return 0x1CC;
    case 0x70:
        return 0x1D1;
    case 0x90:
        return 0x1D6;
    case 0x12:
        return 0x1C3;
    case 0x32:
        return 0x1C8;
    case 0x52:
        return 0x1CD;
    case 0x72:
        return 0x1D2;
    case 0x92:
        return 0x1D7;
    case 0x13:
        return 0x1C4;
    case 0x33:
        return 0x1C9;
    case 0x53:
        return 0x1CE;
    case 0x73:
        return 0x1D3;
    case 0x93:
        return 0x1D8;
    case 0x16:
        return 0x1B9;
    case 0x36:
        return 0x1BA;
    case 0x56:
        return 0x1BB;
    case 0x76:
        return 0x1BC;
    case 0x96:
        return 0x1BD;
    case 0x17:
        return 0x1D9;
    case 0x37:
        return 0x1DA;
    case 0x57:
        return 0x1DB;
    case 0x77:
        return 0x1DC;
    case 0x97:
        return 0x1DD;
    case 0x14:
        return 0x179;
    case 0x34:
        return 0x17A;
    case 0x54:
        return 0x17B;
    case 0x74:
        return 0x17C;
    case 0x94:
        return 0x17D;
    case 0x15:
        return 0x199;
    case 0x35:
        return 0x19A;
    case 0x55:
        return 0x19B;
    case 0x75:
        return 0x19C;
    case 0x95:
        return 0x19D;
    default:
        return 1;
    }
}

s32 func_0207f974(u8 *arg0) {
    s32 var_r1;
    u8 *var_r0;
    u8 var_r2;

    var_r0 = arg0;
    var_r2 = *var_r0;
    var_r1 = 0;
    if (var_r2 != 0) {
        do {
            var_r1 += var_r2;
            var_r0 += 3;
            var_r2 = *var_r0;
        } while (var_r2 != 0);
    }
    return var_r1;
}

s32 func_0207f99c(u8 *arg0) {
    s64 func_020722fc(s32, s32);
    extern s32 data_027e15bc;
    s32 var_r1;
    s32 var_r4;
    u8 *var_r5;
    u8 var_r0;
    var_r5 = arg0;
    var_r4 = 0;
    var_r1 = func_020722fc(data_027e15bc, func_0207f974(arg0)) >> 32;
    var_r0 = *var_r5;
    while (var_r0 != 0) {
        if (var_r1 <= var_r0) return var_r4;
        var_r1 -= var_r0;
        var_r5 += 3;
        var_r0 = *var_r5;
        var_r4++;
    }
    return 0;
}

#pragma scheduling off
void func_0207f9f4(void) {
    extern u8 *data_0210188c[];
    extern s32 data_0214c0c8[];
    s32 i = 0;
    s32 zero = i;
    u8 *entry;
    u8 *selected;

    for (; i < 6; i++) {
        entry = data_0210188c[i];
        if (entry != 0) {
            selected = entry + func_0207f99c(entry) * 3;
            ((Unk0207F9F4 *)data_0214c0c8)[i].unk0 = (s8)selected[1];
            ((Unk0207F9F4 *)data_0214c0c8)[i].unk2 = (s8)selected[2];
        } else {
            ((Unk0207F9F4 *)data_0214c0c8)[i].unk0 = zero;
            ((Unk0207F9F4 *)data_0214c0c8)[i].unk2 = zero;
        }
    }
}
#pragma scheduling reset
s32 func_0207fa64(s32 arg0) {
    extern s32 data_0214c0c8[];
    return data_0214c0c8[arg0];
}

void func_0207fa74(s32 arg0) {
    M2C_UNK func_02004ff8(s32, s32);
    M2C_UNK func_020051c8(s32);
    M2C_UNK func_0209ccb8(M2C_UNK *, M2C_UNK);
    void func_0207fab8(void);
    func_02004ff8(2, arg0);
    func_020051c8(2);
    func_0209ccb8((M2C_UNK *)func_0207fab8, 2);
}

void func_0207faa0(void) {
    M2C_UNK func_0209ccb8(M2C_UNK *, M2C_UNK);
    void func_0207fad4(void);
    func_0209ccb8((M2C_UNK *)func_0207fad4, 2);
}

void func_0207fab8(void) {
    extern void *data_027e00bc;
    M2C_FIELD(data_027e00bc, u16 *, 4) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 4) | 2);
}

void func_0207fad4(void) {
    void func_020051f8(s32);
    extern void *data_027e00bc;
    M2C_FIELD(data_027e00bc, u16 *, 4) &= ~2;
    func_020051f8(2);
}

#pragma push
#pragma opt_dead_code off
void func_0207fafc(void) {
extern void **gCur3DSpriteEngine;
extern s32 data_027e012c;
extern s32 data_027e0128;
extern s32 data_027e0124;
extern s32 data_027e0120;
extern u16 data_027e0108;
extern u16 data_027e010c;
extern u16 data_027e0100;
extern u16 data_027e0114;
extern u16 data_027e0118;
extern u16 data_027e00fc;
extern u16 data_027e0110;
extern u16 data_027e0104;
extern s32 data_027e011c;
s32 func_01ff9b70(u8,s32);
void func_02003984(s32*,s32,s32,s32,s32);void func_020039c8(s32*,s32,s32,s32,s32,s32);
extern void *data_027e00bc; extern u8 data_027e00f8;
void *engine=gCur3DSpriteEngine;
data_027e012c=(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<27)>>31)?1:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<26)>>31)?2:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<25)>>31)?4:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<24)>>31)?8:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<23)>>31)?16:0);
data_027e0128=(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<22)>>31)?1:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<21)>>31)?2:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<20)>>31)?4:0);
data_027e0124=((M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,66)<<16)&(511<<16))|(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,58)&511);
data_027e0120=((M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,68)<<16)&(511<<16))|(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,60)&511);
{u32 a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),c=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),d=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),e=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8); data_027e0108=((u32)(e<<16)>>30<<14)|(*(volatile u16*)0x400000a&64)|((u32)(d<<24)>>31<<7)|((u32)(c<<19)>>27<<8)|((u32)(b<<26)>>28<<2)|((u32)((s32)a<<30)>>30);}
if(func_01ff9b70((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<29)>>29),2)==1){{u32 a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),c=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),d=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),e=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10); data_027e010c=((u32)(e<<16)>>30<<14)|(*(volatile u16*)0x400000c&64)|((u32)(d<<24)>>31<<7)|((u32)(c<<19)>>27<<8)|((u32)(b<<26)>>28<<2)|((u32)((s32)a<<30)>>30);}}
else{data_027e010c=((*(volatile u16*)0x400000a&64)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<16)>>30<<14)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<19)>>27<<8)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<26)>>28<<2)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<18)>>31<<13)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<30)>>30));engine=gCur3DSpriteEngine;
data_027e0100=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,20);
data_027e0114=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,22);
data_027e0118=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,24);
data_027e00fc=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,26);
data_027e0110=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s32 *,28);
data_027e0104=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s32 *,32);
}
switch((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18)<<24)>>30){
default:case 0:data_027e011c=0;break;
case 1:func_02003984(&data_027e011c,(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 31) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 30) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 29) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 28) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 27) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 26) >> 31) ? 32 : 0),(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 23) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 22) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 21) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 20) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 19) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 18) >> 31) ? 32 : 0),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x51),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x52));break;
case 2:func_020039c8(&data_027e011c,(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 31) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 30) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 29) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 28) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 27) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 26) >> 31) ? 32 : 0),(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 23) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 22) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 21) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 20) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 19) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 18) >> 31) ? 32 : 0),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x51),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x52),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x53));break;
case 3:func_020039c8(&data_027e011c,(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 31) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 30) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 29) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 28) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 27) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 26) >> 31) ? 32 : 0),(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 23) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 22) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 21) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 20) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 19) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 18) >> 31) ? 32 : 0),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x51),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x52),-(s32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x53));break;
}
data_027e00f8=(u32)(M2C_FIELD(data_027e00bc,u16 *,2)<<29)>>29;
}
#pragma pop
void func_02080358(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_01ffa42c(M2C_UNK *, s32);
    extern M2C_UNK data_02101d30;
    void *var_r0;

    if (arg3 != 0) {
        var_r0 = func_01ffa42c(&data_02101d30, arg3);
    } else {
        var_r0 = func_01ffa3dc(&data_02101d30, 7);
    }
    M2C_FIELD(var_r0, s16 *, 0x6C) = arg0;
    M2C_FIELD(var_r0, s16 *, 0x6E) = arg1;
    M2C_FIELD(var_r0, s16 *, 0x70) = arg2;
}

void func_020803a0(void *arg0) {
    extern void **gCur3DSpriteEngine;
    if (M2C_FIELD(arg0, s16 *, 0x70) == 0) {
        return;
    }
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x50) = 0;
}

#pragma push
#pragma optimize_ifs off
void func_020803c8(void *arg0) {
    extern void **gCur3DSpriteEngine;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    switch (M2C_FIELD(arg0, s16 *, 0x6C)) {
    case 0:
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x50) = 0x10;
        break;
    default:
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x50) = 0;
        break;
    }
}
#pragma pop
