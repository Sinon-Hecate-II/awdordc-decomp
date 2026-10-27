/* 17 functions from 0x0209F990 to 0x020A0964 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
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

s32 func_020a0300(s32 x,s32 y) {
 extern void *data_0211fb5c;
 s8 i; void *p=data_0211fb5c; char *q;
 i=0; if(i<=M2C_FIELD(p,volatile s8 *,0x5b)) { q=p; do {
 if(x==M2C_FIELD(q,s8 *,0x36)&&y==M2C_FIELD(q,s8 *,0x42)) return i;
 q++; i++; } while(i<=M2C_FIELD(p,volatile s8 *,0x5b)); }
 return -1;
}

M2C_UNK func_020a0360(void) {
    M2C_UNK func_020a01c0(s32, s32);
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
    M2C_UNK *obj;
    s32 r12;
    s32 r6_val;
    u8 *p4;
    u8 *p6;

    obj = (M2C_UNK *)*gCurrentMap;
    if ((s8)M2C_FIELD(obj, s8 *, 0x5b) < 1) {
        return 0;
    }
    r12 = 1;
    p4 = *(u8 **)data_0211fb5c;
    do {
        M2C_UNK *r7 = (M2C_UNK *)((u8 *)obj + r12);
        s8 lr_val = M2C_FIELD(r7, s8 *, 0x35);
        s8 r6_val_inner = M2C_FIELD(r7, s8 *, 0x36);
        u8 *dest = *(u8 **)p4 + r12 + 0x5000;
        
        if (r6_val_inner < lr_val) {
            M2C_FIELD(dest, u8 *, 0x387) = 0;
        } else if (r6_val_inner > lr_val) {
            M2C_FIELD(dest, u8 *, 0x387) = r12; // wait, r2 was r12 in assembly: mov r2, r12
        } else {
            s8 lr_val2 = M2C_FIELD(r7, s8 *, 0x42);
            s8 r6_val2 = M2C_FIELD(r7, s8 *, 0x41);
            if (lr_val2 < r6_val2) {
                M2C_FIELD(dest, u8 *, 0x387) = 3;
            } else {
                M2C_FIELD(dest, u8 *, 0x387) = 2;
            }
        }
        obj = (M2C_UNK *)*gCurrentMap;
        r12++;
    } while (r12 < (s8)M2C_FIELD(obj, s8 *, 0x5b));

    p6 = *(u8 **)data_0211fb5c;
    M2C_FIELD(*(u8 **)p6 + 0x5000, u8 *, r12 + 0x388 - 1) = 2; // wait, let's look at the offset
    return 0;
}

M2C_UNK func_020a0560(void) {
 extern void *data_0211fb5c; extern s32 *gCurrentMap;
 M2C_UNK func_01ffc294(u16,s32,s32,u32,s32,s32);
 void *r; void *p; void *q; q=(void *)*gCurrentMap; p=data_0211fb5c; r=p+M2C_FIELD(p,s8 *,0x5b);
 func_01ffc294((u16)((M2C_FIELD(q,u8 *,0x52d4)>>6)+1),M2C_FIELD(r,s8 *,0x36),M2C_FIELD(r,s8 *,0x42),(u32)(M2C_FIELD(M2C_FIELD(q,u8 **,0x52d0),u8 *,0)<<26)>>26,M2C_FIELD(r,s8 *,0x4e),1);
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
 s32 func_020a7694(s32); M2C_UNK func_020a0068(s32); M2C_UNK func_020a01c0(s32,s32); M2C_UNK func_020a0360(void); M2C_UNK func_020a0d18(); void func_020a004c(u16,u16);
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

