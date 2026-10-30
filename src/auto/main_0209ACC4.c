/* 22 functions from 0x0209ACC4 to 0x0209BC58 (main), found by ds-decomp. */
#include "common.h"
#pragma opt_propagation off
static inline void EmitSprite(u16 x, u16 y, u32 tile, u16 *desc) {
    void func_01ff90e4(u16, u16, u32, u16 *);
    func_01ff90e4(x,y,tile,desc);
}
static inline void DrawSpritePair(u16 x, s32 y, s32 tile, u16 *desc) {
    void func_01ff90e4(u16, u16, u32, u16 *);
    extern s32 gCur3DSpriteEngine;
    func_01ff90e4(x,(u16)y,(u16)tile,desc);
    func_01ff90e4(x,(u16)((y & 0xff00)|((y+8)&255)),(u16)(tile+(0x3ff & (4 >> (((u32)**(u16 **)gCur3DSpriteEngine <<17)>>30)))),desc);
}
#pragma opt_propagation reset

typedef struct { s32 digits[10]; } DigitTable;
extern const DigitTable data_020f399c;

s32 func_0209acc4(void *arg0) {
    s32 func_0208fe30(void *);
    s32 func_02099818(u8, s32, u8, u16);
    M2C_UNK func_02099854(void *, s32, u8, u16);
    s32 func_020999b8(void *);
    s32 func_020999e8(void *);
    M2C_UNK func_02099a30(void *);
    s32 func_02099ae8(void *);
    s32 func_02099b00(void *);
    u32 func_02099e6c(void *, s32);
    M2C_UNK func_0209ac6c(void *, s32);
    s32 func_0209c168(void *, s32);
    M2C_UNK func_0209c418(void *);
    s32 var_r6;
    s32 temp_r7;
    s32 temp_r8;
    void *notify;

main_loop:
    {
        u32 sw = func_02099e6c(arg0, func_020999e8(arg0));
        switch (sw) {
        case 0:
            return 0;
        case 3:
            if ((s8) M2C_FIELD(arg0, s8 *, 0x54) < 0) goto end_block;
            return 1;
        case 2:
            if (func_020999b8(arg0) != 0) goto end_block;
            return 1;
        default:
        case 1:
            temp_r7 = func_02099ae8(M2C_FIELD(arg0, void **, 0x34));
            temp_r8 = func_02099b00(M2C_FIELD(arg0, void **, 0x34));
            if (func_020999b8(arg0) == 0) {
                if (M2C_FIELD(arg0, u8 *, 0x5C) & 0x2) {
                    func_02099a30(arg0);
                    M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) & ~0x2);
                    return 1;
                }
                if (!(M2C_FIELD(arg0, u8 *, 0x4A) == M2C_FIELD(arg0, u8 *, 0x48) && M2C_FIELD(arg0, u8 *, 0x56) == 0)) {
                    func_0209c168(arg0, 1);
                }
                if (temp_r7 != 0) {
                    func_02099854(M2C_FIELD(arg0, void **, 0x34), M2C_FIELD(arg0, s32 *, 0x3C) + (M2C_FIELD(arg0, u16 *, 0x4C) << 5), M2C_FIELD(arg0, u8 *, 0x56), M2C_FIELD(arg0, u16 *, 0x46));
                    var_r6 = 7;
                } else {
                    s32 pixels;
                    void *p = M2C_FIELD(arg0, void **, 0x34);

                    if (temp_r8 != 0) {
                        u16 t1 = M2C_FIELD(arg0, u16 *, 0x4C);
                        pixels = M2C_FIELD(arg0,volatile s32 *,0x3c);
                        var_r6 = func_02099818(M2C_FIELD(p, u8 *, 1), pixels + (t1 << 5), M2C_FIELD(arg0, u8 *, 0x56), M2C_FIELD(arg0, u16 *, 0x46));
                    } else {
                        u16 t1 = M2C_FIELD(arg0, u16 *, 0x4C);
                        pixels = M2C_FIELD(arg0,volatile s32 *,0x3c);
                        var_r6 = func_02099818(M2C_FIELD(p, u8 *, 0), pixels + (t1 << 5), M2C_FIELD(arg0, u8 *, 0x56), M2C_FIELD(arg0, u16 *, 0x46));
                    }
                }
                if ((u8) M2C_FIELD(arg0, u8 *, 0x56) <= 1U) {
                    func_0209ac6c(arg0, func_020999e8(arg0));
                }
                if (func_0209c168(arg0, var_r6) != 0) {
                    func_0209ac6c(arg0, func_020999e8(arg0));
                }
                if ((notify=M2C_FIELD(arg0, void **, 0x60)) != 0 && (s8) M2C_FIELD(arg0, s8 *, 0x55) != 0) {
                    func_0208fe30(notify);
                }
            }
            if (!(temp_r7 == 0 && temp_r8 == 0)) {
                func_0209c418(arg0);
            }
            func_0209c418(arg0);
end_block:
            if ((s8) M2C_FIELD(arg0, s8 *, 0x54) < 0) {
                goto main_loop;
            }
            return 1;
        }
    }
}

void func_0209aeb4(void *arg0) {
    s32 func_020952a4(void);
    s32 func_020953e8(void);
    s32 func_0209546c(void);
    void func_02095ff8(s8);
    s32 func_02096038(void);
    s32 func_02097964(void);
    s32 func_02097be0(void);
    s32 func_020999b8(void *);
    M2C_UNK func_02099e58(M2C_UNK);
    s32 func_0209acc4(void *);
    u32 func_0209dc9c(void);
    u32 func_0209dde0(void);
    M2C_UNK func_01ffa574(M2C_UNK);
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102eac;
    extern M2C_UNK data_02102e74;
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;

    u32 combined;
    s32 saved;
    s32 i;

    combined = func_0209dc9c();
    combined = combined | func_0209dde0();
    combined = (u16)combined;

    if (M2C_FIELD(arg0, u8 *, 0x5C) & 0x1) {
        if (func_01ffa770(&data_02102eac) != 0) return;
        if (func_01ffa770(&data_02102e74) != 0) return;
        if (func_02097be0() != 0) return;
        if (func_020952a4() != 0) return;
        if (func_020953e8() != 0) return;
        if (func_0209546c() != 0) return;
    }

    if (M2C_FIELD(arg0,s8 *,0x55) >= 1 && func_02096038()) {
        if (combined & 0x400) func_02095ff8(1);
        if ((combined & 0x30) && M2C_FIELD(arg0,u16 *,0x4c) != M2C_FIELD(arg0,u16 *,0x4e))
            func_02099e58((s32)arg0);
    }
    if (func_020999b8(arg0)) func_02099e58((s32)arg0);
    M2C_FIELD(arg0,s8 *,0x54) = M2C_FIELD(arg0,s8 *,0x54)+1;
    {
        s32 t=M2C_FIELD(arg0,s8 *,0x54);
        if (t >= 0 && t < M2C_FIELD(arg0,s8 *,0x55)) return;
        if (t >= 0) M2C_FIELD(arg0,s8 *,0x54)=0;
        ((void (*)(void))M2C_FIELD(arg0,void **,0x50))();
    }
    saved = gCur3DSpriteEngine;
    {
        for (i = 0; i < 2; i++) {
            s32 cur;
            if (i == 0) cur = data_027e00c8; else cur = data_027e00c4;
            gCur3DSpriteEngine = cur;
            {
                u8 mode = M2C_FIELD(arg0, u8 *, 0x5A);
                if (mode == 0) {
                    if (cur != data_027e00c8) goto skip_tail;
                }
                if (mode == 1) {
                    if (cur != data_027e00c4) goto skip_tail;
                }
                if (mode == 3) {
                    if (cur != saved) goto skip_tail;
                }
            }
            if (func_0209acc4(arg0) == 0) {
                if (M2C_FIELD(arg0, u8 *, 0x5C) & 0x1) {
                    func_02097964();
                    func_01ffa6fc(arg0);
                } else {
                    func_01ffa574(arg0);
                }
            }
        skip_tail:
            ;
        }
    }
    gCur3DSpriteEngine = saved;
}

void func_0209b084(void *entity) {
    s32 func_02095fe8(void);
    void func_02095ff8(s8);
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    void func_01ff9ce8(u8);
    void func_02095fc0(void);
    void func_02097768(void);
    extern s32 gCur3DSpriteEngine, data_027e00c4, data_027e00c8;
    extern M2C_UNK data_02102eac, data_02102e74;

    s32 saved;
    s32 i;

    if (func_02095fe8() == 3) {
        func_02095ff8(0);
        if (func_02095fe8() == 2) {
            func_02095ff8(0);
        }
    }
    func_01ffa9e4(&data_02102eac);
    func_01ffa9e4(&data_02102e74);

    if (!(M2C_FIELD(entity, u8 *, 0x5c) & 0x4)) {
        saved = gCur3DSpriteEngine;
        for (i = 0; i < 2; i++) {
            gCur3DSpriteEngine = (i == 0) ? data_027e00c8 : data_027e00c4;
            {
                u8 mode = M2C_FIELD(entity, u8 *, 0x5a);
                if (mode == 0 && gCur3DSpriteEngine != data_027e00c8) continue;
                if (mode == 1 && gCur3DSpriteEngine != data_027e00c4) continue;
                if (mode == 3 && gCur3DSpriteEngine != saved) continue;
            }
            func_01ff9ce8(M2C_FIELD(entity, u8 *, 0x57));
            {
                u8 *p = (u8 *)gCur3DSpriteEngine;
                s8 idx = M2C_FIELD(entity, s8 *, 0x57);
                p[0x46] = (u8)(p[0x46] | (1 << idx));
            }
        }
        gCur3DSpriteEngine = saved;
    }

    if (!(M2C_FIELD(entity, u8 *, 0x5c) & 0x8)) goto skip8;
    func_02095fc0();
    func_02097768();
skip8:;
}

void func_0209b190(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_02097be0();
    if (func_02097be0() != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_0209b1b0(void *arg0) {
    extern s32 gCur3DSpriteEngine;
    void *src = M2C_FIELD(gCur3DSpriteEngine, void **, 0x54);

    M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(src, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x38) = M2C_FIELD(src, s32 *, 0x38);
    M2C_FIELD(arg0, s8 *, 0x57) = M2C_FIELD(src, s8 *, 0x57);
    M2C_FIELD(arg0, s32 *, 0x3C) = M2C_FIELD(src, s32 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x40) = M2C_FIELD(src, s32 *, 0x40);
    M2C_FIELD(arg0, u16 *, 0x44) = M2C_FIELD(src, u16 *, 0x44);
    M2C_FIELD(arg0, u16 *, 0x46) = M2C_FIELD(src, u16 *, 0x46);
    M2C_FIELD(arg0, u16 *, 0x4E) = M2C_FIELD(src, u16 *, 0x4C);
    M2C_FIELD(arg0, u16 *, 0x4C) = M2C_FIELD(src, u16 *, 0x4C);
    M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(src, s32 *, 0x60);
    M2C_FIELD(arg0, u8 *, 0x48) = M2C_FIELD(src, u8 *, 0x48);
    M2C_FIELD(arg0, u8 *, 0x49) = M2C_FIELD(src, u8 *, 0x49);
    M2C_FIELD(arg0, u8 *, 0x4A) = M2C_FIELD(src, u8 *, 0x4A);
    M2C_FIELD(arg0, u8 *, 0x4B) = M2C_FIELD(src, u8 *, 0x4B);
    M2C_FIELD(arg0, s8 *, 0x54) = M2C_FIELD(src, s8 *, 0x54);
    M2C_FIELD(arg0, s8 *, 0x55) = M2C_FIELD(src, s8 *, 0x55);
    M2C_FIELD(arg0, s32 *, 0x50) = M2C_FIELD(src, s32 *, 0x50);
    M2C_FIELD(arg0, u8 *, 0x56) = M2C_FIELD(src, u8 *, 0x56);
    M2C_FIELD(arg0, u8 *, 0x58) = M2C_FIELD(src, u8 *, 0x58);
    M2C_FIELD(arg0, u8 *, 0x59) = M2C_FIELD(src, u8 *, 0x59);
    M2C_FIELD(arg0, u8 *, 0x5C) = M2C_FIELD(src, u8 *, 0x5C);
}

void func_0209b26c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209b2b4(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    func_0209b2b4(arg0, arg1, arg2, func_02086680(arg3), arg4, arg5);
}

void func_0209b2b4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209b32c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);

    func_0209b32c(arg0, arg1, arg2, arg3, arg4, 0, arg5);
}

void func_0209b2dc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5, u16 arg6) {
    void func_0209b32c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);
    func_0209b32c(arg0, arg1, arg2, func_02086680(arg3), arg4, arg5, arg6);
}

void func_0209b32c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5, u16 arg6) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *temp_r6;

    temp_r6 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209b370(arg0, arg1, arg2, M2C_FIELD(temp_r6, s32 *, 0xC), M2C_FIELD(temp_r6, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5, (s32) arg6);
}

M2C_UNK func_0209b370(M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 d,s32 e,s32 f,u16 g,u16 h,u16 i) {
 M2C_UNK func_0209be10(s32,M2C_UNK,M2C_UNK,M2C_UNK,s32,s32,s32,s32,s32,s32);
 M2C_UNK func_02099e58(s32); void *func_01ffa3dc(M2C_UNK *,s32);
 extern s32 gCur3DSpriteEngine; extern M2C_UNK data_021032d8;
 s32 temp_r5;
 temp_r5 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x54);
 func_0209be10(temp_r5, a, b, c, d, e, f, (s32)g, (s32)h, (s32)i);
 func_02099e58(temp_r5);
 func_01ffa3dc(&data_021032d8, 7);
}

void func_0209b3e8(s16 a,s32 b,s32 c,s32 d,u16 e,u16 f) {
 s32 func_0207c8ec(s32,s32);
 DigitTable table=data_020f399c;
 do {func_0209b2b4(a,b,c,table.digits[d%10],e,f);
 d=func_0207c8ec(d,10); if(!d) return;
 f+=2; a--;
 } while(1);
}

void func_0209b4a8(M2C_UNK arg0,M2C_UNK arg1,u16 arg2){
s32 func_020e34bc(); M2C_UNK func_020e35cc(s32);void func_02007ef4(M2C_UNK,M2C_UNK,u32);
s32 i,count; M2C_UNK buf;u8 *src,*dst;
src=(u8 *)arg0;dst=(u8 *)arg1;
buf=func_020e34bc(256);
count=(((s32)arg2+7)>>3)+3;count>>=2;
i=0;if(count>0)do{
func_02007ef4(src,buf,256);
func_02007ef4(buf,dst,32);
func_02007ef4((u8 *)buf+64,dst+32,32);
func_02007ef4((u8 *)buf+128,dst+64,32);
func_02007ef4((u8 *)buf+192,dst+96,32);
func_02007ef4((u8 *)buf+32,dst+128,32);
func_02007ef4((u8 *)buf+96,dst+160,32);
func_02007ef4((u8 *)buf+160,dst+192,32);
func_02007ef4((u8 *)buf+224,dst+224,32);
src+=256;dst+=256;
i++;}while(i<count);
func_020e35cc((s32)buf);
}

void func_0209b59c(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK, s32);
    func_02007e98(0, arg0, ((s32) (((s32) (arg1 + 7) >> 3) + 3) >> 2) << 8);
}

void func_0209b5c4(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_02086680(M2C_UNK);
    M2C_UNK func_0209b5e4(M2C_UNK, s32);
    func_0209b5e4(arg0, func_02086680(arg1));
}

s32 func_0209b5e4(M2C_UNK a,s32 b) {
 s32 func_0209c454(s32,M2C_UNK); s32 func_020e34bc(); void func_0209b4a8(s32,s32,u16); M2C_UNK func_020e35cc(s32);
 s32 n,p;
 n=func_0209c454(b,0);
 if((((((n+7)>>3)+3)>>2)<<8)>0) {
 p=func_020e34bc(); func_0209b59c(p,n); func_0209b370(0,0,4,p,0,b,0,0,0);
 func_0209b4a8(p,a,(u16)n); func_020e35cc(p);
 }
 return n;
}

void func_0209b67c(u16 a0, s32 a1, u16 a2, u16 a3, s32 a4) {
    void func_01ffaacc(s32, s32, s32, void *, s32);
    extern u8 data_027e005c[];
    extern u8 data_027e00a4[];
    extern u8 data_027e0084[];
    extern s32 gCur3DSpriteEngine;

    s32 y = a1;
    u16 param = a3;
    s32 priority = a4;
    s32 n = ((s32)a2 + 7) >> 3;
    u16 x = a0;

    if (n >= 4) {
        do {
            u32 _eng;
            s32 mode;
            func_01ffaacc((s32)x, (s32)(u16)y, (s32)param, (void *)data_027e005c, priority);
            n -= 4;
            _eng = *(u16 *)(s32)gCur3DSpriteEngine;
            mode = (s32)((_eng << 17) >> 30);
            param = (u16)(param + (0x3ff & (8 >> mode)));
            x = (u16)(((((x & 0x1ff) + 0x20) & 0x1ff) | (x & 0xfe00)));
        } while (n >= 4);
    }

    if (n >= 2) {
        u32 _eng;
        s32 mode;
        s32 y2;
        func_01ffaacc((s32)x, (s32)(u16)y, (s32)param, (void *)data_027e00a4, priority);
        _eng = *(u16 *)(s32)gCur3DSpriteEngine;
        mode = (s32)((_eng << 17) >> 30);
        y2 = (y & 0xff00) | ((y + 8) & 0xff);
        func_01ffaacc((s32)x, y2, (s32)(u16)(param + (0x3ff & (4 >> mode))), (void *)data_027e0084, priority);
        n -= 2;
        _eng = *(u16 *)(s32)gCur3DSpriteEngine;
        mode = (s32)((_eng << 17) >> 30);
        param = (u16)(param + (0x3ff & (2 >> mode)));
        x = (u16)((((((x & 0x1ff) + 0x10) & 0x1ff) | (x & 0xfe00))));
    }

    if (n >= 1) {
        u32 _eng;
        s32 mode;
        s32 y2;
        func_01ffaacc((s32)x, (s32)(u16)y, (s32)param, (void *)data_027e0084, priority);
        _eng = *(u16 *)(s32)gCur3DSpriteEngine;
        mode = (s32)((_eng << 17) >> 30);
        y2 = (y & 0xff00) | ((y + 8) & 0xff);
        func_01ffaacc((s32)x, y2, (s32)(u16)(param + (0x3ff & (4 >> mode))), (void *)data_027e0084, priority);
    }
}

void func_0209b8c0(void *arg0) {
    void func_0209b4a8(s32, s32, u16);
    M2C_UNK func_020e35cc(s32);
    func_0209b4a8(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), (u16) M2C_FIELD(arg0, s32 *, 0x3C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x34));
}

void func_0209b8ec(s32 arg0, s32 arg1, s32 arg2) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021032b8;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_021032b8, 1);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
}

s32 func_0209b91c(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    s32 func_0209c454(s32, M2C_UNK);
    s32 func_020e34bc();
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = func_0209c454(arg1, 0);
    if ((s32) (((s32) (((s32) (temp_r0 + 7) >> 3) + 3) >> 2) << 8) > 0) {
        temp_r0_2 = func_020e34bc();
        func_0209b59c(temp_r0_2, temp_r0);
        func_0209b370(0, 0, 4, temp_r0_2, 0, arg1, 0, 0, 0);
        func_0209b8ec(temp_r0_2, arg0, temp_r0);
    }
    return temp_r0;
}

#pragma opt_common_subs off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_0209b9a8(s32 a0, s32 a1, s32 a2, u16 a3) {
    void func_01ff90e4(u16, u16, u32, u16 *);
    extern u8 data_027e005c[];
    extern u8 data_027e00a4[];
    extern u8 data_027e0084[];
    extern s32 gCur3DSpriteEngine;

    s32 n = ((s32)a2 + 7) >> 3;
    u32 x = a0;
    u32 y = a1;
    u16 param = a3;

    if (n >= 4) {
        do {
            u32 mode;
            EmitSprite((u16)x, (u16)y, (u32)param, (u16 *)data_027e005c);
            n -= 4;
            mode = (u32)(((u32)(**(u16 **)gCur3DSpriteEngine) << 17) >> 30);
            param = (u16)(param + (0x3ff & (8 >> (s32)mode)));
            x = (u16)(((((x & 0x1ff) + 0x20) & 0x1ff) | (x & 0xfe00)));
        } while (n >= 4);
    }

    if (n >= 2) {
        u32 mode;
        DrawSpritePair((u16)x,y,param,(u16 *)data_027e00a4);
        mode = (u32)(((u32)(**(u16 **)gCur3DSpriteEngine) << 17) >> 30);
        param = (u16)(param + (0x3ff & (2 >> (s32)mode)));
        x = (u16)((((((x & 0x1ff) + 0x10) & 0x1ff) | (x & 0xfe00))));
        n -= 2;
    }

    if (n >= 1) {
        DrawSpritePair((u16)x,(u16)y,(u16)param,(u16 *)data_027e0084);
    }
}
#pragma opt_common_subs reset
void func_0209bbd0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209bc18(M2C_UNK, M2C_UNK, s32, s32, u16, u16);
    M2C_UNK func_02086680(M2C_UNK);

    func_0209bc18(arg0, arg1, arg2, func_02086680(arg3), arg4, arg5);
}

void func_0209bc18(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5) {
    M2C_UNK func_0209bc58(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    void *temp_r5;

    temp_r5 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209bc58(arg0, arg1, arg2, M2C_FIELD(temp_r5, s32 *, 0xC), M2C_FIELD(temp_r5, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5);
}

