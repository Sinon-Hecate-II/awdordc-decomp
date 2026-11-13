/* 47 functions from 0x02090E0C to 0x02091E04 (main), found by ds-decomp. */
#include "common.h"
#include "sprite.h"

extern u8 data_020f362c[];
static inline s32 spriteValid02091110(void *p) { if (p != 0 && *(s32 *)p != 0) return 1; return 0; }
typedef struct SpriteLevels02091110 { u8 v[22]; } SpriteLevels02091110;

void func_02091110(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
    void func_02091230(void);
    void func_02091248(s32);
    s32 Modulo(s32, s32);
    s32 func_0207d0f0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u8);
    void func_0209177c(M2C_UNK);
    void *obj;
    M2C_UNK r6;
    M2C_UNK r5;
    M2C_UNK r4;
    u8 b22;
    u8 b21;
    u8 and8;

    r6 = arg1;
    r5 = arg2;
    r4 = arg3;
    obj = arg0;
    if (!spriteValid02091110(obj)) {
        return;
    }
    b22 = M2C_FIELD(obj, u8 *, 0x22);
    if (b22 & 0x40) {
        M2C_FIELD(obj, u8 *, 0x22) = (u8)(b22 & ~0x40);
    } else {
        if (b22 & 0x10) {
            b21 = M2C_FIELD(obj, u8 *, 0x21);
            ((void (*)(s32))func_02091230)(b21);
        } else if (b22 & 0x20) {
            SpriteLevels02091110 buf = *(const SpriteLevels02091110 *)data_020f362c;
            {
                s32 idx = (s32)(M2C_FIELD(obj, s16 *, 0x18) >> 2);
                idx = Modulo(idx, 0x16);
                func_02091248(buf.v[idx]);
            }
        } else {
            b21 = M2C_FIELD(obj, u8 *, 0x21);
            func_02091248(b21);
        }
        b21 = M2C_FIELD(obj, u8 *, 0x21);
        if (b21 != 0) {
            and8 = (u8)(M2C_FIELD(obj, u8 *, 0x22) & 0x8);
            func_0207d0f0(M2C_FIELD(obj, M2C_UNK *, 0x10), r6, M2C_FIELD(obj, M2C_UNK *, 0x28), M2C_FIELD(obj, M2C_UNK *, 0x2c), r5, r4, and8);
        }
    }
    if (M2C_FIELD(obj, s32 *, 0x30) == 0) {
        return;
    }
    if (!(M2C_FIELD(obj, u8 *, 0x22) & 0x1)) {
        return;
    }
    func_0209177c((M2C_UNK)obj);
}
M2C_UNK func_02090e0c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, s32 arg5, s32 arg6, s32 arg7) {
    extern M2C_UNK data_021029d8;
    extern M2C_UNK data_021029cc;
    M2C_UNK func_01ffa3dc(M2C_UNK, M2C_UNK);
    M2C_UNK MemAlloc(M2C_UNK);
    void func_020906a8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *r4;
    M2C_UNK alloc;

    if (arg7 == 0) {
        arg7 = 9;
    }
    r4 = (void *)func_01ffa3dc((M2C_UNK)&data_021029d8, arg7);
    if (r4 != 0) {
        *(M2C_UNK *)r4 = (M2C_UNK)&data_021029cc;
        M2C_FIELD(r4, M2C_UNK *, 0x40) = arg0;
        M2C_FIELD(r4, M2C_UNK *, 0x38) = 0;
        M2C_FIELD(r4, M2C_UNK *, 0x3C) = 0;
        M2C_FIELD(r4, M2C_UNK *, 0x34) = 0;
        M2C_FIELD(r4, u8 *, 0x44) = *((u8 *)&arg6);
        alloc = MemAlloc(0x30);
        if (alloc != 0) {
            func_020906a8(alloc, (M2C_UNK)r4, arg0, arg1, arg2, arg3, arg4, arg5);
        }
    }
    return (M2C_UNK)r4;
}

void func_02090eb8(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,u16 e,s32 f,s32 g) {s32 func_02081070(M2C_UNK,M2C_UNK);M2C_UNK func_02090e0c(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,u16,s32,s32,s32);s32 r=func_02081070(a,1);func_02090e0c(r,b,c,d,e,f,1,g);}

void *func_02090f0c(void *arg0) {
    M2C_UNK func_02090894();
    M2C_UNK Sprite_DestroyAuxList();
    M2C_UNK HeapFreeBlock(s32);
    M2C_UNK MemFree();
    extern M2C_UNK data_021029cc;
    M2C_UNK (*temp_r1)(void *);

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021029cc;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_02090894();
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        Sprite_DestroyAuxList();
    }
    temp_r1 = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x34);
    if (temp_r1 != NULL) {
        temp_r1(arg0);
    }
    if (M2C_FIELD(arg0, u8 *, 0x44) != 0) {
        HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x40));
    }
    MemFree(arg0);
    return arg0;
}

void *func_02090f78(void *a) {M2C_UNK func_02090894();M2C_UNK Sprite_DestroyAuxList();M2C_UNK HeapFreeBlock(s32);extern M2C_UNK data_021029cc;M2C_UNK (*cb)(void *);M2C_FIELD(a,M2C_UNK **,0)=&data_021029cc;if(M2C_FIELD(a,s32 *,0x38))func_02090894();if(M2C_FIELD(a,s32 *,0x3c))Sprite_DestroyAuxList();cb=M2C_FIELD(a,M2C_UNK (**)(void *),0x34);if(cb)cb(a);if(M2C_FIELD(a,u8 *,0x44))HeapFreeBlock(M2C_FIELD(a,s32 *,0x40));return a;}

#pragma opt_propagation off
void func_02090fdc(void *arg0) {
M2C_UNK DrawSprite3D(void *); M2C_UNK DeleteSpriteObject(void *);
s32 pos[3]; s32 *p; s32 valid,invalid;
pos[0]=M2C_FIELD(arg0,s32 *,0x5c)*48;
pos[1]=M2C_FIELD(arg0,s32 *,0x60)*48;
pos[2]=M2C_FIELD(arg0,s32 *,0x64);
if(((s32 (*)(void *,s32 *,s32,s32))DrawSprite3D)(M2C_FIELD(arg0,void **,0x58),pos,0x30000,0)) return;
p=M2C_FIELD(arg0,s32 **,0x58);invalid=1;
if(p && *p) invalid=0;
valid=invalid==0;
if(valid) return;
DeleteSpriteObject(arg0);
}
#pragma opt_propagation reset
void func_0209106c(void *a) {void Sprite_ClearHandle(s32 *);void (*fp)(s32 *)=Sprite_ClearHandle;fp(M2C_FIELD(a,s32 **,0x58));}
s32 func_0209107c(void *a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,u8 i) {
s32 func_02091af8(void *,s32,s32);s32 func_0207d0f0(s32,s32,s32,s32,s32,s32,u8);
s32 r=func_02091af8(a,b,c);if(r) {func_0207d0f0(r,d,e,f,g,h,i);return 1;}return 0;
}
#pragma optimization_level reset
M2C_UNK DrawSprite3D(void *arg0) {
void func_02091110(); void Sprite_TickTimer(void *); M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);
s32 ok=(arg0!=0 && *(s32 *)arg0!=0);
if(ok==0) return 0;
((void (*)())func_02091110)(arg0); Sprite_TickTimer(arg0); return Sprite_UpdateAnimationScript((M2C_UNK)arg0);
}

extern void func_02091110();

void func_02091230(void) {
    *(s32 *)0x040004A4 = 0x081E4080;
}

void func_02091248(s32 a) {s32 v=a==31?0:63;*(s32 *)0x040004a4=(v<<24)|0x80|(a<<16);}
#pragma optimization_level reset
s32 func_02091270(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
            void func_02091954(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020919b4(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_020919b4(0);
    func_02091954(temp_r0, arg0, arg1, arg2);
    return temp_r0;
}

void Sprite_ClearHandle(s32 *arg0) {
    if (arg0 != NULL && *arg0 != 0) {
        *arg0 = 0;
    }
}

s32 DrawSprite2D(s32 *arg0, s32 arg1, s32 arg2) {
    void func_020912ec(M2C_UNK, M2C_UNK, M2C_UNK);
    void Sprite_TickTimer(void *);
    M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);

    if (arg0 != (void *)0 && *arg0 != 0) {
        func_020912ec((M2C_UNK)arg0, (M2C_UNK)arg1, (M2C_UNK)arg2);
        Sprite_TickTimer((void *)arg0);
        return Sprite_UpdateAnimationScript((M2C_UNK)arg0);
    }
    return 0;
}

void func_020912ec(M2C_UNK a, M2C_UNK x, M2C_UNK y) {
void func_02091570(M2C_UNK);
void func_0209177c(M2C_UNK);
void AddSprite(u16,u16,u16,s32,s32);
extern void *gCur3DSpriteEngine;
void *p=(void *)a;
u32 flags=0, v;
if (!p || !*(s32 *)p) return;
if (M2C_FIELD(p,s32 *,0x14)) {
func_02091570(a);
flags=(M2C_FIELD(p,u8 *,0x23)&31)<<9;
}
v=M2C_FIELD(p,u32 *,0x28);
AddSprite((u16)(x|flags),(u16)y,(u16)((v&0xfc00)|(((v&0x3ff)>>((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))&0x3ff)),M2C_FIELD(p,s32 *,0x10),M2C_FIELD(p,s8 *,0x20));
if (M2C_FIELD(p,s32 *,0x30) && (M2C_FIELD(p,u8 *,0x22)&1)) func_0209177c(a);
}

void Sprite_TickTimer(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18) = (s16) (M2C_FIELD(arg0, s16 *, 0x18) + 1);
}

#pragma opt_if-conversion on
/* Runs one step of a sprite animation script: waits out the current frame
 * delay, then either executes a script command (loop, stop or set command),
 * skips the word, or resolves the frame index into a frame pointer and starts
 * its loop.  Returns SPRITE_ANIM_* and marks the frame as selected. */
M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK spriteHandle) {
    void Sprite_ClearHandle(s32 *);
    void *sprite = (void *)spriteHandle;
    M2C_UNK *cursor;
    u16 value;
    u16 command;
    void *dataBase;
    void *frame;
    u16 header;
    u32 offset;

    if (sprite == (void *)0 || *(s32 *)sprite == 0) {
        return SPRITE_ANIM_STOPPED;
    }
    if (M2C_FIELD(sprite, u16 *, SPRITE_SPEED) == 0) {
        return SPRITE_ANIM_RUNNING;
    }

    if (M2C_FIELD(sprite, s16 *, SPRITE_DELAY) != 0) {
        M2C_FIELD(sprite, s16 *, SPRITE_DELAY) = (s16)(M2C_FIELD(sprite, s16 *, SPRITE_DELAY) - 1);
        if (M2C_FIELD(sprite, s16 *, SPRITE_DELAY) > 0) {
            return SPRITE_ANIM_RUNNING;
        }
        M2C_FIELD(sprite, s16 *, SPRITE_DELAY) = 0;
        M2C_FIELD(sprite, M2C_UNK **, SPRITE_SCRIPT) = M2C_FIELD(sprite, M2C_UNK **, SPRITE_SCRIPT) + 1;

    }

        cursor = M2C_FIELD(sprite, M2C_UNK *, SPRITE_SCRIPT);
        value = *(u16 *)cursor;
        if (value == 0) {
            command = *((u16 *)cursor + 1);
            switch (command) {
            case SPRITE_CMD_LOOP:
                M2C_FIELD(sprite, M2C_UNK **, SPRITE_SCRIPT) = M2C_FIELD(sprite, M2C_UNK **, SPRITE_LOOP_PTR);
                return Sprite_UpdateAnimationScript(spriteHandle);
            case SPRITE_CMD_STOP:
                Sprite_ClearHandle((s32 *)sprite);
                return SPRITE_ANIM_STOPPED;
            case SPRITE_CMD_END:
                return SPRITE_ANIM_DONE;
            default:
                M2C_FIELD(sprite, u16 *, SPRITE_COMMAND) = command;
                M2C_FIELD(sprite, M2C_UNK **, SPRITE_SCRIPT) = M2C_FIELD(sprite, M2C_UNK **, SPRITE_SCRIPT) + 1;
                return Sprite_UpdateAnimationScript(spriteHandle);
            }
        }

        {
            u16 speed = M2C_FIELD(sprite, u16 *, SPRITE_SPEED);
            M2C_FIELD(sprite, u16 *, SPRITE_FRACTION) = (u16)(value * speed + M2C_FIELD(sprite, u16 *, SPRITE_FRACTION));
            if (M2C_FIELD(sprite, u16 *, SPRITE_FRACTION) >= 0x100) {
                M2C_FIELD(sprite, s16 *, SPRITE_DELAY) = (s16)(M2C_FIELD(sprite, u16 *, SPRITE_FRACTION) >> 8);
                M2C_FIELD(sprite, u16 *, SPRITE_FRACTION) = (u16)(M2C_FIELD(sprite, u16 *, SPRITE_FRACTION) & 0xFF);
            } else {
                M2C_FIELD(sprite, s16 *, SPRITE_DELAY) = 1;
                return Sprite_UpdateAnimationScript(spriteHandle);
            }
        }

    if (M2C_FIELD(sprite, u8 *, SPRITE_FLAGS) & SPRITE_FLAG_OFFSET_TABLE) {
        dataBase = M2C_FIELD(sprite, void **, SPRITE_DATA_BASE);
        offset = *(u16 *)((u8 *)dataBase + *((u16 *)M2C_FIELD(sprite, M2C_UNK *, SPRITE_SCRIPT) + 1) * 2) & ~1U;
        M2C_FIELD(sprite, void **, SPRITE_FRAME) = (void *)((u8 *)dataBase + offset);
    } else {
        M2C_FIELD(sprite, void **, SPRITE_FRAME) = (void *)(((void **)M2C_FIELD(sprite, void **, SPRITE_DATA_BASE))[*((u16 *)M2C_FIELD(sprite, M2C_UNK *, SPRITE_SCRIPT) + 1)]);
    }

    frame = M2C_FIELD(sprite, void **, SPRITE_FRAME);
    header = *(u16 *)frame;
    if (!(header & 0x8000)) {
        M2C_FIELD(sprite, void **, SPRITE_LOOP_FRAME) = (void *)0;
    } else {
        M2C_FIELD(sprite, void **, SPRITE_LOOP_FRAME) = frame;
        offset = *(u16 *)M2C_FIELD(sprite,void **,SPRITE_LOOP_FRAME) & 0x7FFF;
        M2C_FIELD(sprite, void **, SPRITE_FRAME) = (void *)((u8 *)M2C_FIELD(sprite,void **,SPRITE_FRAME) + (offset * 3 + 1) * 2);
    }
    M2C_FIELD(sprite, u8 *, SPRITE_FLAGS) |= SPRITE_FLAG_FRAME_SET;
    return SPRITE_ANIM_RUNNING;
}
#pragma opt_if-conversion reset
void func_02091570(M2C_UNK a) {
    s32 Divide(s32, s32);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    extern s16 gSinCosTable[];
    void *arg0 = (void *)a;
    s32 *sp4 = (s32 *)arg0;

    s32 r11;
    s32 r10;
    s32 res3;
    s16 r9s;
    u16 *r8p;
    s32 r7;
    s32 r6;
    s32 res1;
    s32 r5;
    s32 res2;
    s32 r4;
    s16 r3s,res4;
    s32 r1,count,r9i,r3i;

    r6 = -2;

    if (arg0 == (void *)0) return;
    if (*sp4 == 0) return;
    {
        u8 *base = *(u8 **)((char *)arg0 + 0x14);
        if (base == (u8 *)0) return;
        r8p = (u16 *)(base + 2);
        count = *(u16 *)base & 0x7FFF;
    }
    r7 = 0;
    if (count <= 0) return;

    do {
        r5 = r8p[2];
        if (r5 >= 2) {
            r10 = r5;
        } else if ((u32)r5 > 2U) {
            r10 = 2;
        } else if (r5 < -2) {
            r10 = -2;
        } else {
            r10 = r5;
        }

        r1 = r8p[1];

        r3i = ((s32)r8p[0]) >> 4;
        r3s = gSinCosTable[r3i * 2 + 1];

        if (r1 >= 2) {
            r4 = r1;
        } else if ((u32)r1 > 2U) {
            r4 = 2;
        } else if (r1 < -2) {
            r4 = -2;
        } else {
            r4 = r1;
        }

        r9i = ((s32)r8p[0]) >> 4;
        r9s = gSinCosTable[r9i * 2];

        if (r5 < 2) {
            if ((u32)r5 > 2U) r5 = 2;
            else if (r5 < -2) r5 = -2;
        }

        if (r1 < 2) {
            if ((u32)r1 > 2U) r1 = 2;
            else if (r1 < -2) r1 = -2;
        }

        r11 = (s32)r3s << 4;
        res1 = Divide(r11, r1);
        res2 = Divide((-(s32)r9s) << 4, r5);
        res3 = Divide((s32)r9s << 4, r4);
        res4 = (s16)Divide(r11, r10);

        SetSpriteQuad((((s32)*(u8 *)((char *)arg0 + 0x23)) + r7) & 0xFF,
                     res1, res2, res3, res4);
        r7 += 1;
        r8p += 3;
    } while (r7 < count);
}

void func_02091700(void *arg0,s32 arg1) {
void func_02091928(void *);
void *root;
u8 *base;
void *tail;
u32 off;
if(arg0==NULL)return;
root=*(void **)arg0;
if(root==NULL)return;
if(M2C_FIELD(arg0,u8 *,0x22)&2) {
base=(u8 *)root;
off=*(u16 *)(base+2)&~1u;
base+=off;
tail=base+(*(u16 *)(base+arg1*2)&~1u);
M2C_FIELD(arg0,void **,8)=tail;
base=*(u8 **)arg0;
off=*(u16 *)(base+2)&~1u;
base+=off;
tail=base+(*(u16 *)(base+arg1*2)&~1u);
} else {
u32 idx=arg1+1;
M2C_FIELD(arg0,void **,8)=((void **)root)[idx];
tail=((void **)root)[idx];
}
M2C_FIELD(arg0,void **,12)=tail;
func_02091928(arg0);
}

void func_0209177c(M2C_UNK a) {
    void func_0207c3dc(s32, s32, s32, s32);
    void func_0207c464(s32, s32, s32, s32);
    extern u8 data_02102a10[];
    extern void *gCur3DSpriteEngine;

    M2C_UNK arg0 = a;
    void **r4;
    u8 *r5;
    s32 r6;
    u16 *r7;
    u16 *r8;
    s32 r9;
    s32 r11;

    if (arg0 == 0) {
        return;
    }
    if (*(s32 *)arg0 == 0) {
        return;
    }

    r6 = 0;


    {
        u8 *base = (u8 *)M2C_FIELD(arg0, void **, 0x10);
        u16 count = *(u16 *)base;
        r7 = (u16 *)(base + 2);
        r8 = r7 + (count * 3);
        r9 = (s32)count - 1;
        if ((s32)count <= 0) {
            goto cleanup;
        }
    }

r5=data_02102a10;r4=(void **)&gCur3DSpriteEngine;r11=0;
loop:
    {
        void *engine = *r4;

        if (((u32)(*(u16 *)*(void **)engine <<19)>>31) !=0) {
            u8 byte22 = *(u8 *)((char *)arg0 + 0x22);
            s32 second = r7[1];
            s32 first = r7[0];
            s32 idx = ((first & 0xC000) >> 12) + ((second & 0xC000) >> 14);
            u8 m1 = r5[idx * 2];
            u8 m2 = r5[idx * 2 + 1];
            s32 product = ((s32)m1 * (s32)m2)<<5;
            s32 offsetVal = *(s32 *)((char *)arg0 + 0x30) + (r8[0] << 5);
            

            if (byte22 & 0x04) {
                func_0207c464(offsetVal, *(s32 *)((char *)arg0+0x28) + r6, product, r11);
            } else {
                s32 spiritShifted = ((u32)*(s32 *)((char *)arg0+0x28) << 22) >> 17;
                s32 secondArg = (*(s32 *)((char *)engine + 0x1C) + spiritShifted);secondArg+=r6;
                func_0207c3dc(offsetVal, secondArg, product, 0);
            }
        

    {
        s32 second = r7[1];
        s32 first = r7[0];
        s32 idx = ((first & 0xC000) >> 12) + ((second & 0xC000) >> 14);
        u8 m1 = r5[idx * 2];
        u8 m2 = r5[idx * 2 + 1];
        s32 product = ((s32)m1 * (s32)m2)<<5;
        r6 += product;
    }
}
}

r7+=3;r8++;if(r9-- >0)goto loop;

cleanup:
    {
        u8 b = *(u8 *)((char *)arg0 + 0x22);
        b = (s32)b & ~1;
        *(u8 *)((char *)arg0 + 0x22) = b;
    }
}

void func_020918a4(M2C_UNK arg0, M2C_UNK arg1) {
    char *r0 = (char *)arg0;
    char *base;
    char *r3;
    u32 off0;
    u32 off2;
    u32 b;
    u32 nested;
    *(M2C_UNK *)r0 = arg1;
    if (((unsigned char *)r0)[0x22] & 0x2) {
        base = (char *)*(M2C_UNK *)r0;
        off0 = *(unsigned short *)base;
        off0 = off0 & ~1;
        *(M2C_UNK *)(r0 + 4) = (M2C_UNK)(base + off0);
        r3 = (char *)*(M2C_UNK *)r0;
        off2 = *(unsigned short *)(r3 + 2);
        b = off2 & ~1;
        nested = *(unsigned short *)(r3 + b);
        nested = nested & ~1;
        *(M2C_UNK *)(r0 + 8) = (M2C_UNK)(r3 + b + nested);
        r3 = (char *)*(M2C_UNK *)r0;
        off2 = *(unsigned short *)(r3 + 2);
        b = off2 & ~1;
        nested = *(unsigned short *)(r3 + b);
        nested = nested & ~1;
        *(M2C_UNK *)(r0 + 0xC) = (M2C_UNK)(r3 + b + nested);
    } else {
        base = (char *)*(M2C_UNK *)r0;
        *(M2C_UNK *)(r0 + 4) = *(M2C_UNK *)base;
        *(M2C_UNK *)(r0 + 8) = *(M2C_UNK *)(base + 4);
        *(M2C_UNK *)(r0 + 0xC) = *(M2C_UNK *)(base + 4);
    }
}

void func_02091928(void *arg0) {
    M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);
    u16 temp_r4;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    temp_r4 = M2C_FIELD(arg0, u16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    M2C_FIELD(arg0, u16 *, 0x1C) = 0x100;
    Sprite_UpdateAnimationScript((M2C_UNK)arg0);
    M2C_FIELD(arg0, u16 *, 0x1C) = temp_r4;
}

void func_02091954(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2,M2C_UNK arg3) {
void func_020918a4(M2C_UNK, M2C_UNK); M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);
void *r5=(void*)arg0; M2C_UNK r4=arg2; M2C_UNK r1;
M2C_FIELD(r5,u8*,0x22)=arg3; func_020918a4(arg0,arg1); r1=0;
M2C_FIELD(r5,s32*,0x30)=r1; M2C_FIELD(r5,s32*,0x28)=r1; M2C_FIELD(r5,s32*,0x2c)=r1;
M2C_FIELD(r5,s16*,0x18)=r1; M2C_FIELD(r5,s16*,0x1a)=r1;
M2C_FIELD(r5,u8*,0x20)=r4; M2C_FIELD(r5,u8*,0x21)=31; M2C_FIELD(r5,s32*,0x14)=r1;
M2C_FIELD(r5,u8*,0x23)=r1; M2C_FIELD(r5,s16*,0x1a)=r1;
M2C_FIELD(r5,s16*,0x1c)=256; M2C_FIELD(r5,s16*,0x1e)=r1; M2C_FIELD(r5,s16*,0x24)=r1;
Sprite_UpdateAnimationScript((M2C_UNK)r5);
}

#pragma optimization_level 2
s32 func_020919b4(M2C_UNK a) {extern s32 data_02157918;s32 i=0; s32 *p=&data_02157918;do {if(*p==a)return i*52+(s32)&data_02157918;i++;p=(s32*)((u8*)p+52);}while(i<32);return 0;}
#pragma optimization_level reset
void func_020919f4(void *arg0) {
    M2C_UNK DeleteSpriteObject(void *);
    s32 DrawSprite2D(s32 *, s32, s32);
    s32 *temp_r0;
    s32 var_r1;

    if (DrawSprite2D(M2C_FIELD(arg0, s32 **, 0x58), M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x60)) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 **, 0x58);
    var_r1 = 1;
    if ((temp_r0 != NULL) && (*temp_r0 != 0)) {
        var_r1 = 0;
    }
    if (var_r1 == 0) {
        return;
    }
    DeleteSpriteObject(arg0);
}

#pragma scheduling off
void func_02091a40(void *arg0) {
    Sprite_ClearHandle(M2C_FIELD(arg0, s32 *, 0x58));
}
#pragma scheduling reset
void func_02091a50(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102a28;
    extern M2C_UNK data_021029f0;
    func_01ffa9e4(&data_02102a28);
    func_01ffa9e4(&data_021029f0);
}

u16 func_02091a70(void *arg0) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(arg0, u16 *, 0x24) = 0U;
    return temp_r2;
}

#pragma push
#pragma scheduling off
s32 func_02091a84(void *arg0) {
    u16 *p = M2C_FIELD(arg0, u16 **, 0x8);
    s32 sum = 0;

    for (;;) {
        u16 a = p[0];
        if (a == 0) {
            u16 b = p[1];
            if (b == 0 || b == 1 || b == 0xFF) {
                return sum;
            }
            sum = sum + b;
        } else {
            sum = sum + a;
        }
        p = p + 2;
    }
}
#pragma pop
void func_02091abc(void) {

}

#pragma push
#pragma scheduling off
s32 func_02091ac0(void *arg0) {
    u16 *p = M2C_FIELD(arg0, u16 **, 0x8);
    s32 sum = 0;

    do {
        u16 a = p[0];
        if (a == 0) {
            u16 b = p[1];
            if (b == 0 || b == 1 || b == 0xff) {
                return sum;
            }
        }
        sum = sum + 1;
        p = p + 2;
    } while (1);
}
#pragma pop
void func_02091af4(void) {

}

s32 func_02091af8(void *arg,s32 b,s32 c){
u16 *a=arg;
s32 Modulo(s32,s32);
u16 *table,*seq,*p; s32 sum;
table=(u16 *)((u8 *)a+(a[0]&~1));
p=(u16 *)((u8 *)a+(a[1]&~1));
seq=(u16 *)((u8 *)p+(p[b]&~1));
p=seq;sum=0;
while(p[0]){sum+=p[0];p+=2;}
switch(p[1]){
case 255:c=Modulo(c,sum);break;
case 1:if(c>sum)c=sum;break;
case 0:return 0;
}
if(seq[0]){do{c-=*(volatile u16 *)seq;if(c<=0)break;seq+=2;}while(seq[0]);}
return (s32)((u8 *)table+(table[seq[1]]&~1));
}

void func_02091bcc(void) {
    M2C_UNK func_02091c88(s32, s32);
    s32 var_r5;

    var_r5 = 0;
    do {
        func_02091c88(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0x5E);
}

void func_02091bf4(void) {
    M2C_UNK IncrementCounter(s32 *);
    extern M2C_UNK data_0215d9b8;
    s32 sp0;

    sp0 = M2C_FIELD(&data_0215d9b8, s32 *, 0x74);
    IncrementCounter(&sp0);
    func_02091c88(0, sp0);
}

#pragma peephole off
void AddRecordValue(s32 index,s32 value) {
extern u32 gRecordValues[];
if(value+gRecordValues[index]<0xf423fU) { gRecordValues[index]=gRecordValues[index]+value; return; }
gRecordValues[index]=0xf423fU;
}
#pragma peephole off
void func_02091c54(s32 index,s32 value) {
extern u32 gRecordValues[];
if(value+gRecordValues[index]<0x5f5e0ffU) { gRecordValues[index]=gRecordValues[index]+value; return; }
gRecordValues[index]=0x5f5e0ffU;
}
#pragma peephole reset
M2C_UNK func_02091c88(M2C_UNK arg0, M2C_UNK arg1) {
    extern unsigned int gRecordValues[];
    gRecordValues[arg0] = (unsigned int)arg1;
}

void func_02091c98(void) {
extern void *gCur3DSpriteEngine;
extern M2C_UNK data_0211e738;
extern M2C_UNK data_0211e068;
func_0207c780(&data_0211e738,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c));
func_01ff9e44(&data_0211e068,0x200,0x20);
}

void func_02091cd0(void) {
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineSub;
extern void *g3DSpriteEngineMain;
void *save=gCur3DSpriteEngine;
s32 i=0;
do {
gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
func_02091c98();
i++;
}while(i<2);
gCur3DSpriteEngine=save;
}

#pragma scheduling off
void func_02091d20(void) {M2C_UNK func_02007e20(M2C_UNK*,s32,M2C_UNK);extern M2C_UNK data_020f41e0;extern void *gCur3DSpriteEngine;func_02007e20(&data_020f41e0,M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x800,0x800);}
#pragma scheduling reset
void func_02091d4c(s32 arg0) {
    M2C_UNK func_01ff9e44(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_0211e088;
    func_01ff9e44(&data_0211e088, arg0 << 5, 0x20);
}

void func_02091d6c(s32 a,s32 b) {
extern void *gCur3DSpriteEngine;
func_02091d4c(a);
if(b!=0)return;
func_020ae528(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+((a<<5)&~1));
}

M2C_UNK *Get3DSpriteManager(void) {
    extern M2C_UNK g3DSpriteManager;
    return &g3DSpriteManager;
}

u8 Get3DSpriteCount(void) {
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x48);
}

u8 Get3DSpriteScreenMode(s32 arg0) {
    M2C_UNK *Get3DSpriteManager(void);
    M2C_UNK *base = Get3DSpriteManager();
    return M2C_FIELD((char *)base + arg0, u8 *, 0x44);
}

s32 GetOther3DSpriteScreenMode(M2C_UNK arg0) {
    u8 Get3DSpriteScreenMode(M2C_UNK);
    if (Get3DSpriteScreenMode(arg0) == 0x2) {
        return 0x3;
    }
    Get3DSpriteScreenMode(arg0);
    return 0x2;
}

