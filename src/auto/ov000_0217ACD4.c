/* 8 functions from 0x0217ACD4 to 0x0217BCD4 (ov000), found by ds-decomp. */
#include "common.h"

#pragma scheduling off
s32 func_ov000_0217acd4(s32 dir) {
extern void *data_027e0a90,*data_027e00cc,*data_027e0a98;extern s32 data_027e0a94;extern void **gCurrentMap;extern s32 (*data_ov000_021df650)();
u8 *p;void *map;s32 x,y,w,h,c,limit;
M2C_FIELD(data_027e00cc,u8 *,36)=M2C_FIELD(data_027e0a90,u8 *,0);
M2C_FIELD(data_027e00cc,u8 *,37)=M2C_FIELD(data_027e0a90,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(data_027e00cc,u8 *,37)--;break;case 3:M2C_FIELD(data_027e00cc,u8 *,37)++;break;case 4:M2C_FIELD(data_027e00cc,u8 *,36)--;break;case 5:M2C_FIELD(data_027e00cc,u8 *,36)++;break;default:break;}
if(data_027e0a94>=349)return 0;
map=*gCurrentMap;p=data_027e00cc;
x=p[36];w=M2C_FIELD(map,u16 *,0x5144);if(x<w){y=p[37];h=M2C_FIELD(map,u16 *,0x5146);if(y<h)goto valid;}return 0;valid:;
limit=M2C_FIELD(p,s16 *,32);c=M2C_FIELD(data_027e0a90,u8 *,3)+p[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,0x3758)),u8 *,0x1420)&31];
if(c>limit)return 0;
if(data_ov000_021df650(x,y,p[38])==1)return 1;
M2C_FIELD(data_027e0a98,u8 *,0)=M2C_FIELD(data_027e00cc,u8 *,36);
M2C_FIELD(data_027e0a98,u8 *,1)=M2C_FIELD(data_027e00cc,u8 *,37);
M2C_FIELD(data_027e0a98,u8 *,2)=dir;
M2C_FIELD(data_027e0a98,u8 *,3)=c;
data_027e0a98+=4;data_027e0a94++;return 0;
}

s32 func_ov000_0217ae9c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_01ffb454(s32);
    s32 func_ov000_0217acd4(s32);
    s32 func_ov000_021a97e0(u16, s32);
    extern void **gCurrentMap;
    extern void *data_027e00cc;
    extern void *data_027e0a98;
    extern void *data_027e0a90;
    extern s32 data_027e0a94;
    extern s8 data_027e0a8c;
    u8 state;
    void *p;
    data_027e0a94 = 0;
    data_027e0a98 = data_027e00cc + 0x28;
    data_027e0a8c = 0;
    data_027e0a90 = data_027e00cc + 0x5A0;
    M2C_FIELD(data_027e00cc, s16 *, 0x20) = arg3;
    M2C_FIELD(data_027e00cc, s16 *, 0x22) = func_ov000_021a97e0(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), arg2);
    M2C_FIELD(data_027e00cc, s8 *, 0x26) = arg2;
    func_01ffb454(arg2);
    M2C_FIELD(data_027e0a98, s8 *, 0) = arg0;
    M2C_FIELD(data_027e0a98, s8 *, 1) = arg1;
    M2C_FIELD(data_027e0a98, s8 *, 2) = 1;
    M2C_FIELD(data_027e0a98, s8 *, 3) = 0;
    p = data_027e0a98 + 4;
    data_027e0a98 = p;
    M2C_FIELD(p, s8 *, 2) = 0;
    for (;;) {
        if (data_027e0a8c == 0) {
            data_027e0a98 = data_027e00cc + 0x5A0;
            data_027e0a90 = data_027e00cc + 0x28;
            data_027e0a8c = 1;
        } else {
            data_027e0a98 = data_027e00cc + 0x28;
            data_027e0a90 = data_027e00cc + 0x5A0;
            data_027e0a8c = 0;
            data_027e0a94 = 0;
        }
        state = M2C_FIELD(data_027e0a90, u8 *, 2);
        if (state == 0) {
            M2C_FIELD(data_027e00cc, s8 *, 0x24) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
            M2C_FIELD(data_027e00cc, s8 *, 0x25) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
            return 0;
        }
        while (state != 0) {
            switch (state) {
            case 1:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            case 2:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            case 3:
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            case 4:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(4) == 1) goto found;
                break;
            case 5:
                if (func_ov000_0217acd4(2) == 1) goto found;
                if (func_ov000_0217acd4(3) == 1) goto found;
                if (func_ov000_0217acd4(5) == 1) goto found;
                break;
            }
            M2C_FIELD(data_027e0a98, s8 *, 2) = 0;
            p = data_027e0a90 + 4;
            data_027e0a90 = p;
            state = M2C_FIELD(p, u8 *, 2);
        }
    }
found:
    M2C_FIELD(data_027e00cc, s8 *, 0x24) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
    M2C_FIELD(data_027e00cc, s8 *, 0x25) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
    return 1;
}

s32 func_ov000_0217b1e8(s32 dir) {
extern void *data_027e0a90,*data_027e00cc,*data_027e0a98;extern s32 data_027e0a94;extern void **gCurrentMap;extern s32 (*data_ov000_021df650)();
u8 *p;void *map;s32 x,y,w,h,c,limit;
if(M2C_FIELD(data_027e0a90,u8 *,3)>M2C_FIELD(data_027e00cc,s16 *,32))return 0;
M2C_FIELD(data_027e00cc,u8 *,36)=M2C_FIELD(data_027e0a90,u8 *,0);
M2C_FIELD(data_027e00cc,u8 *,37)=M2C_FIELD(data_027e0a90,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(data_027e00cc,u8 *,37)--;break;case 3:M2C_FIELD(data_027e00cc,u8 *,37)++;break;case 4:M2C_FIELD(data_027e00cc,u8 *,36)--;break;case 5:M2C_FIELD(data_027e00cc,u8 *,36)++;break;default:break;}
if(data_027e0a94>=349)return 0;
map=*gCurrentMap;p=data_027e00cc;
x=p[36];w=M2C_FIELD(map,u16 *,0x5144);if(x<w){y=p[37];h=M2C_FIELD(map,u16 *,0x5146);if(y<h)goto valid;}return 0;valid:;
c=M2C_FIELD(data_027e0a90,u8 *,3)+p[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,0x3758)),u8 *,0x1420)&31];
if(c>255)c=255;
if(data_ov000_021df650(x,y,p[38])==1)return 1;
M2C_FIELD(data_027e0a98,u8 *,0)=M2C_FIELD(data_027e00cc,u8 *,36);
M2C_FIELD(data_027e0a98,u8 *,1)=M2C_FIELD(data_027e00cc,u8 *,37);
M2C_FIELD(data_027e0a98,u8 *,2)=dir;
M2C_FIELD(data_027e0a98,u8 *,3)=c;
data_027e0a98+=4;data_027e0a94++;return 0;
}

s32 func_ov000_0217b3bc(s8 arg0, s8 arg1, s8 arg2, s16 arg3) {
    void func_01ffb454(s32);
    s32 func_ov000_0217b1e8(M2C_UNK);
    s32 func_ov000_021a97e0(u16, s32);
    extern void **data_027e0058;
    extern void *data_027e00cc;
    extern s8 data_027e0a8c;
    extern void *data_027e0a90;
    extern s32 data_027e0a94;
    extern void *data_027e0a98;
    u8 var_r0;
    void *temp_r0;
    void *temp_r1;

    data_027e0a90 = data_027e00cc + 0x5A0;
    data_027e0a8c = 0;
    data_027e0a98 = data_027e00cc + 0x28;
    data_027e0a94 = 0;
    M2C_FIELD(data_027e00cc, s16 *, 0x20) = arg3;
    M2C_FIELD(data_027e00cc, s16 *, 0x22) = func_ov000_021a97e0(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), arg2);
    M2C_FIELD(data_027e00cc, s8 *, 0x26) = arg2;
    func_01ffb454(arg2);
    M2C_FIELD(data_027e0a98, s8 *, 0) = arg0;
    M2C_FIELD(data_027e0a98, s8 *, 1) = arg1;
    M2C_FIELD(data_027e0a98, s8 *, 2) = 1;
    M2C_FIELD(data_027e0a98, s8 *, 3) = 0;
    temp_r1 = data_027e0a98 + 4;
    data_027e0a98 = temp_r1;
    M2C_FIELD(temp_r1, s8 *, 2) = 0;
loop_1:
    if (data_027e0a8c == 0) {
        data_027e0a98 = data_027e00cc + 0x5A0;
        data_027e0a90 = data_027e00cc + 0x28;
        data_027e0a8c = 1;
    } else {
        data_027e0a98 = data_027e00cc + 0x28;
        data_027e0a90 = data_027e00cc + 0x5A0;
        data_027e0a8c = 0;
    }
    data_027e0a94 = 0;
    var_r0 = M2C_FIELD(data_027e0a90, u8 *, 2);
    if (var_r0 != 0) {
        if (var_r0 != 0) {
loop_7:
            switch (var_r0) {
            default:
            case 0:
block_36:
                M2C_FIELD(data_027e0a98, s8 *, 2) = 0;
                temp_r0 = data_027e0a90 + 4;
                data_027e0a90 = temp_r0;
                var_r0 = M2C_FIELD(temp_r0, u8 *, 2);
                if (var_r0 == 0) {
                    goto loop_1;
                }
                goto loop_7;
            case 1:
                if ((func_ov000_0217b1e8(2) != 1) && (func_ov000_0217b1e8(3) != 1) && (func_ov000_0217b1e8(4) != 1) && (func_ov000_0217b1e8(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 2:
                if ((func_ov000_0217b1e8(2) != 1) && (func_ov000_0217b1e8(4) != 1) && (func_ov000_0217b1e8(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 3:
                if ((func_ov000_0217b1e8(3) != 1) && (func_ov000_0217b1e8(4) != 1) && (func_ov000_0217b1e8(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 4:
                if ((func_ov000_0217b1e8(2) != 1) && (func_ov000_0217b1e8(3) != 1) && (func_ov000_0217b1e8(4) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 5:
                if ((func_ov000_0217b1e8(2) != 1) && (func_ov000_0217b1e8(3) != 1) && (func_ov000_0217b1e8(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            }
        } else {
            goto loop_1;
        }
    } else {
        M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
        M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
        return 0;
    }
}

s32 func_ov000_0217b708(s32 dir) {
extern void *data_027e0a90,*data_027e00cc,*data_027e0a98;extern s32 data_027e0a94;extern void **gCurrentMap;extern s32 (*data_ov000_021df650)();
u8 *p;void *map;s32 x,y,w,h,c,limit;
M2C_FIELD(data_027e00cc,u8 *,36)=M2C_FIELD(data_027e0a90,u8 *,0);
M2C_FIELD(data_027e00cc,u8 *,37)=M2C_FIELD(data_027e0a90,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(data_027e00cc,u8 *,37)--;break;case 3:M2C_FIELD(data_027e00cc,u8 *,37)++;break;case 4:M2C_FIELD(data_027e00cc,u8 *,36)--;break;case 5:M2C_FIELD(data_027e00cc,u8 *,36)++;break;default:break;}
if(data_027e0a94>=349)return 0;
map=*gCurrentMap;p=data_027e00cc;
x=p[36];w=M2C_FIELD(map,u16 *,0x5144);if(x<w){y=p[37];h=M2C_FIELD(map,u16 *,0x5146);if(y<h)goto valid;}return 0;valid:;
if(!func_ov000_021a9044(2,M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,0x3758)),u8 *,0x1420)&31))return 0;
c=M2C_FIELD(data_027e0a90,u8 *,3)+1;p=data_027e00cc;limit=M2C_FIELD(p,s16 *,32);
if(c>limit)return 0;
if(data_ov000_021df650(p[36],p[37],p[38])==1)return 1;
M2C_FIELD(data_027e0a98,u8 *,0)=M2C_FIELD(data_027e00cc,u8 *,36);
M2C_FIELD(data_027e0a98,u8 *,1)=M2C_FIELD(data_027e00cc,u8 *,37);
M2C_FIELD(data_027e0a98,u8 *,2)=dir;
M2C_FIELD(data_027e0a98,u8 *,3)=c;
data_027e0a98+=4;data_027e0a94++;return 0;
}

s32 func_ov000_0217b8f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_0217b708(s32);
    s32 func_ov000_021a97e0(u16, s32);
    extern void **gCurrentMap;
    extern void *data_027e00cc;
    extern s8 data_027e0a8c;
    extern void *data_027e0a90;
    extern s32 data_027e0a94;
    extern void *data_027e0a98;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;

    data_027e0a90 = (void *)((u8 *)data_027e00cc + 0x5A0);
    data_027e0a8c = 0;
    data_027e0a98 = (void *)((u8 *)data_027e00cc + 0x28);
    data_027e0a94 = 0;
    M2C_FIELD(data_027e00cc, s16 *, 0x20) = arg3;
    M2C_FIELD(data_027e00cc, s16 *, 0x22) = func_ov000_021a97e0(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), arg2);
    M2C_FIELD(data_027e00cc, s8 *, 0x26) = arg2;
    M2C_FIELD(data_027e0a98, s8 *, 0) = arg0;
    M2C_FIELD(data_027e0a98, s8 *, 1) = arg1;
    M2C_FIELD(data_027e0a98, s8 *, 2) = 1;
    M2C_FIELD(data_027e0a98, s8 *, 3) = 0;
    temp_r0 = (void *)((u8 *)data_027e0a98 + 4);
    data_027e0a98 = temp_r0;
    M2C_FIELD(temp_r0, s8 *, 2) = 0;
loop_1:
    if (data_027e0a8c == 0) {
        data_027e0a98 = (void *)((u8 *)data_027e00cc + 0x5A0);
        data_027e0a90 = (void *)((u8 *)data_027e00cc + 0x28);
        data_027e0a8c = 1;
    } else {
        data_027e0a98 = (void *)((u8 *)data_027e00cc + 0x28);
        data_027e0a90 = (void *)((u8 *)data_027e00cc + 0x5A0);
        data_027e0a8c = 0;
    }
    data_027e0a94 = 0;
    var_r0 = M2C_FIELD(data_027e0a90, u8 *, 2);
    if (var_r0 != 0) {
        if (var_r0 != 0) {
loop_7:
            switch (var_r0) {
            default:
            case 0:
block_36:
                M2C_FIELD(data_027e0a98, s8 *, 2) = 0;
                temp_r0_2 = (void *)((u8 *)data_027e0a90 + 4);
                data_027e0a90 = temp_r0_2;
                var_r0 = M2C_FIELD(temp_r0_2, u8 *, 2);
                if (var_r0 == 0) {
                    goto loop_1;
                }
                goto loop_7;
            case 1:
                if ((func_ov000_0217b708(2) != 1) && (func_ov000_0217b708(3) != 1) && (func_ov000_0217b708(4) != 1) && (func_ov000_0217b708(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
                return 1;
            case 2:
                if ((func_ov000_0217b708(2) != 1) && (func_ov000_0217b708(4) != 1) && (func_ov000_0217b708(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
                return 1;
            case 3:
                if ((func_ov000_0217b708(3) != 1) && (func_ov000_0217b708(4) != 1) && (func_ov000_0217b708(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
                return 1;
            case 4:
                if ((func_ov000_0217b708(2) != 1) && (func_ov000_0217b708(3) != 1) && (func_ov000_0217b708(4) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
                return 1;
            case 5:
                if ((func_ov000_0217b708(2) != 1) && (func_ov000_0217b708(3) != 1) && (func_ov000_0217b708(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
                M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
                return 1;
            }
        } else {
            goto loop_1;
        }
    } else {
        M2C_FIELD(data_027e00cc, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
        M2C_FIELD(data_027e00cc, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
        return 0;
    }
}

#pragma scheduling reset
s32 func_ov000_0217bc34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_0217ab10();
    s32 func_ov000_0217ae9c(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)();

    data_ov000_021df650 = func_ov000_0217ab10;
    if (data_ov000_021df650() == 1) {
        return 1;
    }
    return func_ov000_0217ae9c(arg0, arg1, arg2, arg3);
}

s32 func_ov000_0217bc84(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_0217ac78(s32, s32, s32);
    s32 func_ov000_0217b8f0(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)();

    data_ov000_021df650 = func_ov000_0217ac78;
    if (data_ov000_021df650(arg0, arg1, 0) == 1) {
        return 1;
    }
    return func_ov000_0217b8f0(arg0, arg1, 0, arg2);
}
