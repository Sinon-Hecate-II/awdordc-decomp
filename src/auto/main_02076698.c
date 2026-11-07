/* 17 functions from 0x02076698 to 0x02077624 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 values[128]; } ColorTable;
extern const ColorTable data_020eb2e0, data_020eb360, data_020eb3e0, data_020eb460;

void func_02076698(u8 *table,u32 poly){u32 v,i,j;
for(i=0;i<256;i++){v=i;for(j=0;j<8;j++){if(v&128)v=(v<<1)^poly;else v<<=1;}table[i]=v;}
}

s32 func_020766d8(s32 table,u8 *crc,s32 data,s32 size){u32 v,i;u8 *p=(u8*)data;v=*crc;
for(i=0;i<(u32)size;i++)v=((u8*)table)[(u8)(v^*p++)];*crc=v;
}

void func_02076710(u16 *table,u32 poly){u32 v,j,i;
for(i=0;i<256;i++){v=i;for(j=0;j<8;j++){if(v&1)v=(v>>1)^poly;else v>>=1;}table[i]=v;}
}

s32 func_02076754(s32 table,u16 *state,s32 data,s32 size) {
 u32 crc=*state; u32 i; u8 *p=(u8 *)data;
 for(i=0;i<(u32)size;i++) crc=M2C_FIELD(table,u16 *, ((crc ^ *p++) << 24) >> 23) ^ (crc >> 8);
 *state=crc;
}

void func_02076794(u32 *table,u32 poly) {
 u32 crc; u32 i; u32 j; u32 zero;
 i=0; zero=0;
 do { crc=i; j=zero;
 do { if(crc&1) crc=poly^(crc>>1); else crc>>=1; j++; }while(j<8);
 table[i]=crc; i++;
 }while(i<256);
}

s32 func_020767d4(s32 table,s32 *state,s32 data,s32 size) {
 u32 crc=*state; u32 i; u8 *p=(u8 *)data;
 for(i=0;i<(u32)size;i++) crc=((u32 *)table)[(u8)(crc ^ *p++)] ^ (crc >> 8);
 *state=crc;
}

u8 func_02076810(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020766d8(M2C_UNK, u8 *, M2C_UNK, M2C_UNK);
    u8 sp0;

    sp0 = 0;
    func_020766d8(arg0, &sp0, arg1, arg2);
    return sp0;
}

u16 func_02076838(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02076754(M2C_UNK, u16 *, M2C_UNK, M2C_UNK);
    u16 sp0;

    sp0 = 0;
    func_02076754(arg0, &sp0, arg1, arg2);
    return sp0;
}

s32 func_02076860(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020767d4(M2C_UNK, s32 *, M2C_UNK, M2C_UNK);
    s32 sp0;

    sp0 = -1;
    func_020767d4(arg0, &sp0, arg1, arg2);
    return ~sp0;
}

void func_0207688c(void) {
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK data_02141008;
    extern M2C_UNK data_02141788;
    extern M2C_UNK data_02141f08;
    extern M2C_UNK data_02142688;
    extern M2C_UNK data_02142ebc;
    extern M2C_UNK data_02143dbc;
    func_02007e98(0, &data_02142688, 0x834);
    func_02007e98(0, &data_02141f08, 0x900);
    func_02007e98(0, &data_02141788, 0x900);
    func_02007e98(0, &data_02141008, 0x900);
    func_02007e98(0, &data_02142ebc, 0x1200);
    func_02007e98(0, &data_02143dbc, 0x1200);
}

#pragma opt_propagation off
void func_02076910(s32 x,s32 y) {
 extern void *gCurrentMap;
 extern M2C_UNK data_02142688;
 void *p;
 s32 a,b;
 s32 v;
 if(x<0 || y<0) return;
 p=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x5120;
 if(x>=M2C_FIELD(p,u16 *,0x24) || y>=M2C_FIELD(p,u16 *,0x26)) return;
 v=7;
 a=(s32)&data_02142688+x*42;
 b=(s32)&data_02142688+(x+1)*42;
 M2C_FIELD(y+0,u8 *,a)=v;
 M2C_FIELD(y+0,u8 *,b)=v;
 M2C_FIELD(y+1,u8 *,a)=v;
 M2C_FIELD(y+1,u8 *,b)=v;
}
#pragma opt_strength_reduction off
#pragma opt_propagation off
void func_02076980(s32 x0, s32 y0, s32 x1, s32 y1) {
    extern void *gCurrentMap;
    extern M2C_UNK data_02142688;
    u8 *p = (u8 *)M2C_FIELD(gCurrentMap, void **, 0) + 0x5120;
    u8 **mapPtr;
    s32 x, y, width, height, row, terrain, code;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    width = M2C_FIELD(p, u16 *, 0x24);
    height = M2C_FIELD(p, u16 *, 0x26);
    if (x1 > width - 1) x1 = width - 1;
    if (y1 > height - 1) y1 = height - 1;
    mapPtr = (u8 **)gCurrentMap;
    for (y = y0; y <= y1 + 1; y++) {
        for (x = x0; x <= x1 + 1; x++) {
            u8 *map;
            if (M2C_FIELD(y, u8 *, (s32)&data_02142688 + x * 42) == 7) continue;
            code = 0;
            if (x - 1 >= 0 && y - 1 >= 0 && x - 1 < width && y - 1 < height) {
                map = *mapPtr;
                row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                terrain = M2C_FIELD(map, u8 *, 0x1420 + row + x - 1);
                if (terrain == 4) {
                    if (x < width && y - 1 < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 4) code = 3;
                    }
                    if (code == 0 && x - 1 < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) != 4) code = 3;
                    }
                    if (code == 0 && x < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 4) code = 3;
                    }
                    if (code == 0) code = 1;
                } else if (terrain == 29) {
                    if (x < width && y - 1 < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 29) code = 3;
                    }
                    if (code == 0 && x - 1 < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) != 29) code = 3;
                    }
                    if (code == 0 && x < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 29) code = 3;
                    }
                    if (code == 0) code = 1;
                } else if (terrain == 3) {
                    if (x < width && y - 1 < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 8) code = 4;
                    }
                    if (code == 0 && x - 1 < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 8) code = 4;
                    }
                    if (code == 0 && x < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 8) code = 4;
                    }
                    if (code == 0) code = 2;
                } else if (terrain == 8) {
                    if (x < width && y - 1 < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 3) code = 4;
                    }
                    if (code == 0 && x - 1 < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 3) code = 4;
                    }
                    if (code == 0 && x < width && y < height) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 3) code = 4;
                    }
                    if (code == 0) code = 2;
                }
                if (x < width && y > 0) {
                    map = *mapPtr;
                    row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                    terrain = M2C_FIELD(map, u8 *, 0x1420 + row + x);
                    if (terrain == 3) {
                        if (x > 0 && y < height) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 8) code = 2;
                        }
                        if (x < width && y < height) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 8) code = 2;
                        }
                    } else if (terrain == 8) {
                        if (x > 0 && y < height) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 3) code = 4;
                        }
                        if (x < width && y < height) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 3) code = 4;
                        }
                    }
                }
                if (code == 0 && x > 0 && y < height) {
                    map = *mapPtr;
                    row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                    terrain = M2C_FIELD(map, u8 *, 0x1420 + row + x - 1);
                    if (terrain == 3) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) != 8) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 8) {
                                map = *mapPtr;
                                row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                                if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 8) code = 2;
                            }
                        }
                    }
                }
                if (code == 0 && x < width && y < height) {
                    map = *mapPtr;
                    row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                    terrain = M2C_FIELD(map, u8 *, 0x1420 + row + x);
                    if (terrain == 3) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) != 8) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x) != 8) {
                                map = *mapPtr;
                                row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                                if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) != 8) code = 2;
                            }
                        }
                    }
                }
                if (code == 0 && x > 0 && y < height) {
                    map = *mapPtr;
                    row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                    terrain = M2C_FIELD(map, u8 *, 0x1420 + row + x - 1);
                    if (terrain == 8) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 3) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 3) {
                                map = *mapPtr;
                                row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                                if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 3) code = 4;
                            }
                        }
                    }
                }
                if (code == 0 && x < width && y < height) {
                    map = *mapPtr;
                    row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                    terrain = M2C_FIELD(map, u8 *, 0x1420 + row + x);
                    if (terrain == 8) {
                        map = *mapPtr;
                        row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                        if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 3) {
                            map = *mapPtr;
                            row = M2C_FIELD(map, u16 *, 0x3758 + (y - 1) * 2);
                            if (M2C_FIELD(map, u8 *, 0x1420 + row + x) == 3) {
                                map = *mapPtr;
                                row = M2C_FIELD(map, u16 *, 0x3758 + y * 2);
                                if (M2C_FIELD(map, u8 *, 0x1420 + row + x - 1) == 3) code = 4;
                            }
                        }
                    }
                }
            }
            M2C_FIELD(y, u8 *, (s32)&data_02142688 + x * 42) = code;
        }
    }
}
#pragma opt_propagation on
#pragma opt_strength_reduction on
void func_02077480(void){extern M2C_UNK data_02140f70;
if(M2C_FIELD(&data_02140f70,s32*,12)==0)M2C_FIELD(&data_02140f70,s32*,12)=1;
}

void func_0207749c(void) {
    extern M2C_UNK data_02140f70;
    M2C_FIELD(&data_02140f70, s32 *, 0xC) = 0;
}

void func_020774b0(void) {
 extern M2C_UNK data_02140f70;
 s32 n=M2C_FIELD(&data_02140f70,s32 *,12);
 if(n<8) M2C_FIELD(&data_02140f70,s32 *,12)=n+1;
}

s32 func_020774cc(void) {
 extern void *gCurrentMap;
 extern M2C_UNK data_02140f70;
 if(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),s32 *,0x60)) return M2C_FIELD(&data_02140f70,s32 *,12)!=0;
 return 0;
}

void func_0207750c(void) {
 extern s32 data_027e15bc;
 extern M2C_UNK data_02140f70;
 ColorTable a=data_020eb2e0;
 ColorTable b=data_020eb360;
 ColorTable c=data_020eb3e0;
 ColorTable d=data_020eb460;
 s32 i=data_027e15bc & 127;
 s32 x=((volatile u8 *)a.values)[i>>1], y=((volatile u8 *)b.values)[i>>1], z=((volatile u8 *)c.values)[i>>1];
 M2C_FIELD(&data_02140f70,u16 *,16)=x;
 M2C_FIELD(&data_02140f70,u16 *,18)=y;
 M2C_FIELD(&data_02140f70,u16 *,20)=c.values[i>>1];
 M2C_FIELD(&data_02140f70,u16 *,22)=d.values[i>>1];
}

