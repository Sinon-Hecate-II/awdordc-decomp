/* 17 functions from 0x0209F990 to 0x020A0964 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
s32 func_0209fd2c(void) {
    /* Walk the map grid; for every cell whose stored value is >= 0 and
       whose passability test succeeds, append (x, y, value) to the output
       list. Terminate the list with a -1 sentinel and return the count. */
    s32 func_020ba924(s32, s32);
    extern void *data_0215be00;
    extern s32 *data_027e0058;
    s32 count;
    u8 *out;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    u32 type;

    out = data_0215be00;
    obj = (M2C_UNK *)*data_027e0058;
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
                        M2C_FIELD(out, s16 *, 2) = M2C_FIELD(M2C_FIELD((u8 *)(void *)*data_027e0058 + y * 4, s8 **, 0x52E8), s8 *, x);
                        out = (u8 *)out + 4;
                    }
                    x++;
                    obj = (M2C_UNK *)*data_027e0058;
                } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
            }
            y++;
        } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
    }
    M2C_FIELD(out, s16 *, 2) = -1;
    return count;
}

s32 func_0209ff34(void) {
    /* Same as func_0209fd2c but using the secondary passability test
       (func_020baa1c). */
    s32 func_020baa1c(s32, s32);
    extern void *data_0215be00;
    extern s32 *data_027e0058;
    s32 count;
    u8 *out;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    u32 type;

    out = data_0215be00;
    obj = (M2C_UNK *)*data_027e0058;
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
                        M2C_FIELD(out, s16 *, 2) = M2C_FIELD(M2C_FIELD((u8 *)(void *)*data_027e0058 + y * 4, s8 **, 0x52E8), s8 *, x);
                        out = (u8 *)out + 4;
                    }
                    x++;
                    obj = (M2C_UNK *)*data_027e0058;
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

M2C_UNK func_020a0560(void) {
 extern void *data_0211fb5c; extern s32 *data_027e0058;
 M2C_UNK func_01ffc294(u16,s32,s32,u32,s32,s32);
 void *r; void *p; void *q; q=(void *)*data_027e0058; p=data_0211fb5c; r=p+M2C_FIELD(p,s8 *,0x5b);
 func_01ffc294((u16)((M2C_FIELD(q,u8 *,0x52d4)>>6)+1),M2C_FIELD(r,s8 *,0x36),M2C_FIELD(r,s8 *,0x42),(u32)(M2C_FIELD(M2C_FIELD(q,u8 **,0x52d0),u8 *,0)<<26)>>26,M2C_FIELD(r,s8 *,0x4e),1);
}

void func_020a05d8(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020a0068(M2C_UNK);
    M2C_UNK func_020a0360();
    M2C_UNK func_020a0560();
    extern s32 *data_027e0058;
    func_020a0068(1);
    func_020a0560();
    func_01ffc4b8(arg0, arg1, *data_027e0058 + 0x5388);
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
 extern void *data_0211fb5c; extern s32 *data_027e0058;
 s32 func_020a7694(s32); M2C_UNK func_020a0068(s32); M2C_UNK func_020a01c0(s32,s32); M2C_UNK func_020a0360(); M2C_UNK func_020a0d18(); void func_020a004c(u16,u16);
 void *p;
 M2C_FIELD(data_0211fb5c,s8 *,0x5a)=func_020a7694(M2C_FIELD((void *)*data_027e0058,s32 *,0x52d0));
 M2C_FIELD(data_0211fb5c,s8 *,0x5b)=0;
 func_020a0068(0);
 p=M2C_FIELD((void *)*data_027e0058,void **,0x52d0);
 func_020a01c0(M2C_FIELD(p,s8 *,1),M2C_FIELD(p,s8 *,2));
 M2C_FIELD(data_0211fb5c,s8 *,0x4e)=M2C_FIELD(data_0211fb5c,s8 *,0x5a);
 if(arg0!=0)func_020a0360();
 M2C_FIELD((void *)*data_027e0058,u8 *,0x5388)=4;
 func_020a004c(0xffff,0xffff);func_020a0d18();
}

