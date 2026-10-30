/* 17 functions from 0x0209F990 to 0x020A0964 (main), found by ds-decomp. */
#include "common.h"
typedef struct PathPlayerId { u32 id:8; u32 rest:24; } PathPlayerId;
extern u16 data_02168f14;
extern u8 data_021261d0[];
extern u8 data_ov000_021b5c0e[];

#pragma opt_strength_reduction off
s32 func_0209f990(void) {
    void func_0209f8c0(void);
    s32 func_0209f8d4(void);
    void func_0209f8f8(s32, s32, s32, s32);
    s32 func_020a4828(s32, s32);
    void *func_020a45f8(s32, s32);
    u8 func_020d27a4(s32, s32);
    void func_020d166c(s32, s32, void *);
    u8 func_020d273c(s32, s32);
    s32 func_020d0a88(u8 *, M2C_UNK);
    void func_020d1690(s32, s32, void *);
    extern s32 *gCurrentMap;

    M2C_UNK *obj;
    s32 y;
    s32 x;
    s32 id;
    s32 visible;
    void *dim;
    s32 bits;

    func_0209f8c0();
    obj = (M2C_UNK *)*gCurrentMap;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) <= 0) {
        return func_0209f8d4();
    }
    y = 0;
    do {
        obj = (M2C_UNK *)*gCurrentMap;
        x = 0;
        if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
            do {
                obj = (M2C_UNK *)*gCurrentMap;
                if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0) {
                    id = M2C_FIELD(obj, u8 *, x + M2C_FIELD((u8 *)obj + y * 2, u16 *, 0x3758));
                    visible = func_020a4828(x, y);
                    if (id != 0) {
                        if (func_020d27a4(M2C_FIELD(obj, u8 *, 0x52d4), id) == 0) {
                            func_020d166c(M2C_FIELD(obj, u8 *, 0x52d4), id, (void *)((u8 *)obj + 0x52dc));
                            obj = (M2C_UNK *)*gCurrentMap;
                            if (M2C_FIELD(obj, s16 *, 0x6ed6) != 0) {
                                func_0209f8f8(x, y, id, 0);
                            }
                        }
                    } else {
                        if (visible != 0) {
                            dim = func_020a45f8(x, y);
                            if (dim != (void *)0) {
                                bits = (s32)(M2C_FIELD(dim, u8 *, 5) & 7);
                                if (bits != 0) {
                                    if (func_020d273c((M2C_FIELD(obj, u8 *, 0x52d4) >> 6) + 1, bits) != 0) {
                                        goto next_cell;
                                    }
                                }
                            }
                            func_020d1690(M2C_FIELD(obj, u8 *, 0x52d4), visible, (void *)((u8 *)obj + 0x52dc));
                            obj = (M2C_UNK *)*gCurrentMap;
                            if (M2C_FIELD(obj, s16 *, 0x6ed6) != 0) {
                                func_0209f8f8(x, y, 0, (s32)(u16)visible);
                            }
                        }
                    }
                }
            next_cell:
                x++;
                obj = (M2C_UNK *)*gCurrentMap;
            } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
        }
        y++;
    } while (y < (s32)M2C_FIELD((M2C_UNK *)*gCurrentMap, u16 *, 0x5146));
    return func_0209f8d4();
}
s32 func_0209fb70(void) {
    void func_0209f8c0(void);
    s32 func_0209f8d4(void);
    void func_0209f8f8(s32, s32, s32, s32);
    s32 func_020a4828(s32, s32);
    void *func_020a45f8(s32, s32);
    u8 func_020d27a4(s32, s32);
    s32 func_020d0a08(M2C_UNK, void *);
    s32 func_020d0a88(u8 *, M2C_UNK);
    u8 func_020d273c(s32, s32);
    extern s32 *gCurrentMap;

    M2C_UNK *obj;
    s32 x;
    s32 y;
    s32 id;
    s32 visible;
    void *dim;
    s32 bits;

    func_0209f8c0();
    obj = (M2C_UNK *)*gCurrentMap;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) <= 0) {
        return func_0209f8d4();
    }
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
    }
    do {
        obj = (M2C_UNK *)*gCurrentMap;
        x = 0;
        if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
            do {
                obj = (M2C_UNK *)*gCurrentMap;
                if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0) {
                    id = M2C_FIELD(obj, u8 *, x + M2C_FIELD((u8 *)obj + y * 2, u16 *, 0x3758));
                    visible = func_020a4828(x, y);
                    if (id != 0) {
                        if (func_020d27a4(M2C_FIELD(obj, u8 *, 0x52d4), id) == 0) {
                            if (func_020d0a08(M2C_FIELD(obj, M2C_UNK *, 0x52d0), (u8 *)obj + 0x59a4 + id * 14) != 0) {
                                func_0209f8f8(x, y, id, 0);
                            }
                        }
                    } else {
                        if (visible != 0) {
                            dim = func_020a45f8(x, y);
                            if (dim != 0) {
                                bits = (s32)(M2C_FIELD(dim, u8 *, 5) & 7);
                                if (bits != 0) {
                                    if (func_020d273c((M2C_FIELD(obj, u8 *, 0x52d4) >> 6) + 1, bits) != 0) {
                                        goto next_cell;
                                    }
                                }
                            }
                            if (func_020d0a88((u8 *)M2C_FIELD(obj, M2C_UNK *, 0x52d0), visible) != 0) {
                                func_0209f8f8(x, y, 0, (s32)(u16)visible);
                            }
                        }
                    }
                }
next_cell:
                x++;
                obj = (M2C_UNK *)*gCurrentMap;
            } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
        }
        y++;
    } while (y < (s32)M2C_FIELD((M2C_UNK *)*gCurrentMap, u16 *, 0x5146));
    return func_0209f8d4();
}

s32 func_0209fd2c(void) {
    /* Walk the map grid; for every cell whose stored value is >= 0 and
       whose passability test succeeds, append (x, y, value) to the output
       list. Terminate the list with a -1 sentinel and return the count. */
    s32 func_020ba924(s32, s32);
    extern void *data_0215be00;
    extern s32 *gCurrentMap;
    s32 count;
    u8 *out;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    u32 type;

    out = data_0215be00;
    obj = (M2C_UNK *)*gCurrentMap;
    count = 0;
    type = (u32)(M2C_FIELD(M2C_FIELD(obj, u8 **, 0x52D0), u8 *, 0) << 26) >> 26;
    if (type != 1 && type != 2 && type != 3) return 0;
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
                do {
                    if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0 && func_020ba924(x, y) == 1) {
                        M2C_FIELD(out, u8 *, 0) = (u8)x;
                        M2C_FIELD(out, u8 *, 1) = (u8)y;
                        count++;
                        M2C_FIELD(out, s16 *, 2) = M2C_FIELD(M2C_FIELD((u8 *)(void *)*gCurrentMap + y * 4, s8 **, 0x52E8), s8 *, x);
                        out = (u8 *)out + 4;
                    }
                    x++;
                    obj = (M2C_UNK *)*gCurrentMap;
                } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
            }
            y++;
        } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
    }
    M2C_FIELD(out, s16 *, 2) = -1;
    return count;
}

s32 func_0209fe44(void) {
    s32 func_020ba510(s32, s32);
    extern void *data_0215be00;
    extern M2C_UNK *gCurrentMap;

    u16 *out;
    s32 y;
    s32 x;

    out = (u16 *)data_0215be00 + 2;
    y = 0;

    if (M2C_FIELD(gCurrentMap, u16 *, 0x5146) == 0) goto done;

    do {
        x = 0;

        if (M2C_FIELD(gCurrentMap, u16 *, 0x5144) == 0) goto next_row;

        do {
            if (M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52E8), s8 *, x) < 0) goto next_cell;
            if (func_020ba510(x, y) == 0) goto next_cell;

            *out = *(u8 *)((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, 0x3758 + y * 2) + x);
            out += 4;

next_cell:
            x++;
        } while (x < M2C_FIELD(gCurrentMap, u16 *, 0x5144));

next_row:
        y++;
    } while (y < M2C_FIELD(gCurrentMap, u16 *, 0x5146));

done:
    *out = 0;
    return (out - ((u16 *)data_0215be00 + 2)) / 16;
}

s32 func_0209ff34(void) {
    /* Same as func_0209fd2c but using the secondary passability test
       (func_020baa1c). */
    s32 func_020baa1c(s32, s32);
    extern void *data_0215be00;
    extern s32 *gCurrentMap;
    s32 count;
    u8 *out;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    u32 type;

    out = data_0215be00;
    obj = (M2C_UNK *)*gCurrentMap;
    count = 0;
    type = (u32)(M2C_FIELD(M2C_FIELD(obj, u8 **, 0x52D0), u8 *, 0) << 26) >> 26;
    if (type != 1 && type != 2 && type != 3) return 0;
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
                do {
                    if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0 && func_020baa1c(x, y) == 1) {
                        M2C_FIELD(out, u8 *, 0) = (u8)x;
                        M2C_FIELD(out, u8 *, 1) = (u8)y;
                        count++;
                        M2C_FIELD(out, s16 *, 2) = M2C_FIELD(M2C_FIELD((u8 *)(void *)*gCurrentMap + y * 4, s8 **, 0x52E8), s8 *, x);
                        out = (u8 *)out + 4;
                    }
                    x++;
                    obj = (M2C_UNK *)*gCurrentMap;
                } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
            }
            y++;
        } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
    }
    M2C_FIELD(out, s16 *, 2) = -1;
    return count;
}

void func_020a004c(u16 arg0, u16 arg1) {
    extern void *data_0211fb5c;
    M2C_FIELD(data_0211fb5c, s8 *, 0x34) = arg0;
    M2C_FIELD(data_0211fb5c, s8 *, 0x35) = arg1;
}

M2C_UNK func_020a0068(s32 arg0) {
extern void *data_0211fb5c;extern s32 *gCurrentMap;
void *map,*player,*path; s8 i;u32 id; s32 weather,kind,terrain; s8 *cost;
if(M2C_FIELD(data_0211fb5c,s8 *,0x5b)<arg0)return;
M2C_FIELD(data_0211fb5c,s8 *,0x5b)=arg0-1;
M2C_FIELD(data_0211fb5c+M2C_FIELD(data_0211fb5c,s8 *,0x5b),s8 *,0x4e)=M2C_FIELD(data_0211fb5c,s8 *,0x5a);
for(i=1;i<=M2C_FIELD(data_0211fb5c,s8 *,0x5b);i++){
map=(void *)*gCurrentMap;
player=map+0x67a4+((M2C_FIELD(map,u8 *,0x52d4)>>6)+1)*140;
id=((u32)(data_02168f14<<18)>>31)?(u8)M2C_FIELD(player,u32 *,0x6c):0;
path=data_0211fb5c+i;
weather=func_020a33c4();
cost=M2C_FIELD(data_021261d0+id*156+weather*40,s8 **,M2C_FIELD(player,u8 *,0x25)*4);
kind=(u32)(M2C_FIELD(M2C_FIELD((void *)*gCurrentMap,u8 **,0x52d0),u8 *,0)<<26)>>26;
terrain=M2C_FIELD(map+M2C_FIELD(path,s8 *,0x36)+M2C_FIELD(map+M2C_FIELD(path,s8 *,0x42)*2,u16 *,0x3758),u8 *,0x1420)&31;
M2C_FIELD(path,s8 *,0x4e)=M2C_FIELD(path,s8 *,0x4d)-cost[data_ov000_021b5c0e[kind*112]*32+terrain];
}
}

void func_020a01c0(s32 x,s32 y){
extern void *data_0211fb5c;extern s32 *gCurrentMap;
void *map; void *player;void *path;s32 i;s32 id;s32 weather;s32 kind;s32 terrain;s8 *cost;
M2C_FIELD(data_0211fb5c,s8 *,0x5b)++;
M2C_FIELD(data_0211fb5c+M2C_FIELD(data_0211fb5c,s8 *,0x5b),s8 *,0x36)=x;
M2C_FIELD(data_0211fb5c+M2C_FIELD(data_0211fb5c,s8 *,0x5b),s8 *,0x42)=y;
map=(void *)*gCurrentMap;
player=map+0x67a4+((M2C_FIELD(map,u8 *,0x52d4)>>6)+1)*140;
if((u32)(data_02168f14<<18)>>31)id=((PathPlayerId *)(player+0x6c))->id;else id=0;
path=data_0211fb5c;i=M2C_FIELD(path,s8 *,0x5b);
weather=func_020a33c4();
kind=(u32)(M2C_FIELD(M2C_FIELD((void *)*gCurrentMap,u8 **,0x52d0),u8 *,0)<<26)>>26;
terrain=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)&31;
cost=M2C_FIELD(data_021261d0+id*156+weather*40,s8 **,M2C_FIELD(player,u8 *,0x25)*4);
M2C_FIELD(path+i,s8 *,0x4e)=M2C_FIELD(path+i-1,s8 *,0x4e)-cost[data_ov000_021b5c0e[kind*112]*32+terrain];
}

s32 func_020a0300(s32 x,s32 y) {
 extern void *data_0211fb5c;
 s8 i; void *p=data_0211fb5c; char *q;
 i=0; if(i<=M2C_FIELD(p,volatile s8 *,0x5b)) { q=p; do {
 if(x==M2C_FIELD(q,s8 *,0x36)&&y==M2C_FIELD(q,s8 *,0x42)) return i;
 q++; i++; } while(i<=M2C_FIELD(p,volatile s8 *,0x5b)); }
 return -1;
}

M2C_UNK func_020a0360(void) {
    void func_020a01c0(s32, s32);
    extern s32 *gCurrentMap;
    extern void *data_0211fb5c;

    M2C_UNK *map;
    u8 *stream;
    s8 cmd;
    u8 *base;

    map = (M2C_UNK *)*gCurrentMap;
    stream = (u8 *)*((s32 *)map) + 0x388 + 0x5000;
    cmd = *stream++;
    base = (u8 *)data_0211fb5c;

    switch (cmd + 1) {
        case 1:
        case 6: {
            u8 *q = base + (s8)base[0x5b];
            func_020a01c0((s8)(q[0x36] - 1), (s8)q[0x42]);
            break;
        }
        case 2: {
            u8 *q = base + (s8)base[0x5b];
            func_020a01c0((s8)(q[0x36] + 1), (s8)q[0x42]);
            break;
        }
        case 3: {
            u8 *q = base + (s8)base[0x5b];
            func_020a01c0((s8)q[0x36], (s8)(q[0x42] - 1));
            break;
        }
        case 4: {
            u8 *q = base + (s8)base[0x5b];
            func_020a01c0((s8)q[0x36], (s8)(q[0x42] + 1));
            break;
        }
        default:
            break;
    }
}

s32 func_020a046c(void) {
    extern void *data_0211fb5c;
    extern s32 *gCurrentMap;

    s8 i;
    u8 *r;
    u8 *dest;

    i = 1;
    if (((s8 *)((u8 *)data_0211fb5c))[0x5b] < 1) {
        return 0;
    }
    do {
        r = (u8 *)data_0211fb5c + i;
        if ((s8)r[0x36] < (s8)r[0x35]) {
            *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = 0;
        } else if ((s8)r[0x36] > (s8)r[0x35]) {
            *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = (u8)i;
        } else {
            if ((s8)r[0x42] < (s8)r[0x41]) {
                *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = 3;
            } else {
                *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = 2;
            }
        }
        i++;
    } while (i <= (s8)((u8 *)data_0211fb5c)[0x5b]);

    *((u8 *)((u8 *)*gCurrentMap + (i - 1) + 0x5388)) = 4;
    return 0;
}

M2C_UNK func_020a0560(void) {
    extern void *data_0211fb5c; extern s32 *gCurrentMap;
    void func_01ffc294(u16, s32, s32, u32, s32, s32);
    s8 *p;
    s8 *q;
    u8 *map;

    p = data_0211fb5c;
    q = p + p[0x5b];
    map = (u8 *)*gCurrentMap;
    func_01ffc294((u16)((map[0x52d4] >> 6) + 1), q[0x36], q[0x42], (u32)(M2C_FIELD(M2C_FIELD(map, u8 **, 0x52d0), u8 *, 0) << 26) >> 26, q[0x4e], 1);
}

void func_020a05d8(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020a0068(M2C_UNK);
    M2C_UNK func_020a0560();
extern s32 *gCurrentMap;
    func_020a0068(1);
    func_020a0560();
    func_01ffc4b8(arg0, arg1, *gCurrentMap + 0x5388);
    func_020a0360();
}

s32 func_020a061c(void) {
 extern void *data_0211fb5c;
 void *p=data_0211fb5c; char *q; void *r; s8 i,j;
 i=M2C_FIELD(p,s8 *,0x5b); if(i>0) { q=p+i; do {
 for(j=i-1;j>=0;j--) {
 r=p+j; if(M2C_FIELD(q,volatile s8 *,0x36)==M2C_FIELD(r,s8 *,0x36)&&M2C_FIELD(q,s8 *,0x42)==M2C_FIELD(r,s8 *,0x42))return 0;
 }
 i--; q--; } while(i>0); }
 return 1;
}

void func_020a06a0(s32 arg0) {
 extern void *data_0211fb5c; extern s32 *gCurrentMap;
 s32 func_020a7694(s32); M2C_UNK func_020a0068(s32); void func_020a01c0(s32,s32); M2C_UNK func_020a0360(void); M2C_UNK func_020a0d18(); void func_020a004c(u16,u16);
 void *p;
 M2C_FIELD(data_0211fb5c,s8 *,0x5a)=func_020a7694(M2C_FIELD((void *)*gCurrentMap,s32 *,0x52d0));
 M2C_FIELD(data_0211fb5c,s8 *,0x5b)=0;
 func_020a0068(0);
 p=M2C_FIELD((void *)*gCurrentMap,void **,0x52d0);
 func_020a01c0(M2C_FIELD(p,s8 *,1),M2C_FIELD(p,s8 *,2));
 M2C_FIELD(data_0211fb5c,s8 *,0x4e)=M2C_FIELD(data_0211fb5c,s8 *,0x5a);
 if(arg0!=0)func_020a0360();
 M2C_FIELD((void *)*gCurrentMap,u8 *,0x5388)=4;
 func_020a004c(0xffff,0xffff);func_020a0d18();
}

s32 func_020a0750(s32 x,s32 y){
extern s32 *gCurrentMap;
void *p; s32 v; u8 *unit; s32 cell; s32 owner; s32 kind; s32 terrain; s32 result=0;
if(x<0||y<0||x>=M2C_FIELD((void *)*gCurrentMap,u16 *,0x5144)||y>=M2C_FIELD((void *)*gCurrentMap,u16 *,0x5146))return 0;
p=(void *)*gCurrentMap;
v=M2C_FIELD(M2C_FIELD(p+y*4,s8 **,0x52e8),s8 *,x);
if(v<0||v>110)return 0;
if(M2C_FIELD(p,u8 *,x+M2C_FIELD(p+y*2,u16 *,0x3758)))return result;
result+=(110-v)<<8;
result+=func_020d03ec((M2C_FIELD(p,u8 *,0x52d4)>>6)+1,x,y)?64:0;
p=(void *)*gCurrentMap;
cell=x+M2C_FIELD(p+y*2,u16 *,0x3758);
unit=M2C_FIELD(p,u8 **,0x52d0);
owner=(M2C_FIELD(p,u8 *,0x52d4)>>6)+1;
kind=(u32)(unit[0]<<26)>>26;
terrain=M2C_FIELD(p+cell,u8 *,0x1420)&31;
return result+func_020d05f4(owner,kind,terrain);
}

s32 func_020a086c(s16 *arg0, s16 *arg1) {
    s32 func_020a0750(s32, s32);
    s32 func_0207c2f0(void);
    unsigned long long func_020720f0(s32, s32);
    extern s8 data_0211fbbc[];
    s32 xv = *arg0;
    s32 yv = *arg1;
    s32 best = 0;
    s32 tiecount = 0;
    s32 i;
    s32 off = 0;
    s32 scores[4];
    for (i = 0; i < 4; i++) {
        s32 sc = func_020a0750(xv + (s32)data_0211fbbc[off], yv + (s32)data_0211fbbc[off + 1]);
        scores[i] = sc;
        if (sc > best) { best = sc; tiecount = 0; }
        else if (sc == best) { tiecount++; }
        off += 2;
    }
    if (best == 0) return 0;
    {
        unsigned long long q = func_020720f0(func_0207c2f0(), tiecount + 1);
        s32 ticket = (s32)(q >> 32);
        s32 idx = 0;
        for (idx = 0; idx < 4; idx++) {
            if (scores[idx] == best) {
                if (ticket == 0) break;
                ticket--;
            }
        }
        *arg0 = (s16)(xv + (s32)data_0211fbbc[idx * 2]);
        *arg1 = (s16)(yv + (s32)data_0211fbbc[idx * 2 + 1]);
    }
    return 1;
}

