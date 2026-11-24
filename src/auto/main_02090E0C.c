/* 47 functions from 0x02090E0C to 0x02091E04 (main), found by ds-decomp. */
#include "common.h"
#include "sprite.h"
#include "battle_map.h"
#include "sprite_script.h"

extern u8 gSpritePaletteCycle[];
static inline s32 spriteValid02091110(void *p) { if (p != 0 && *(s32 *)p != 0) return 1; return 0; }
typedef struct SpriteLevels02091110 { u8 v[22]; } SpriteLevels02091110;

/* Apply the sprite's palette mode and submit its current 3D frame geometry,
 * then draw the frame's parts once the animation has selected a frame. */
void DrawSprite3DFrame(void *obj,s32 *pos,s32 attr,s32 extra) {
    void SetSpritePaletteBase(void);
    void SetSpritePaletteIndex(s32);
    s32 Modulo(s32, s32);
    s32 DrawSprite3DGeometry(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u8);
    void DrawSprite3DParts(M2C_UNK);
    M2C_UNK posArg;
    M2C_UNK attrArg;
    M2C_UNK extraArg;
    u8 flags;
    u8 palette;
    u8 geometryParam;

    posArg = (M2C_UNK)pos;
    attrArg = attr;
    extraArg = extra;
    if (!spriteValid02091110(obj)) {
        return;
    }
    flags = M2C_FIELD(obj, u8 *, SPRITE_FLAGS);
    if (flags & SPRITE_FLAG_DEFER) {
        M2C_FIELD(obj, u8 *, SPRITE_FLAGS) = (u8)(flags & ~SPRITE_FLAG_DEFER);
    } else {
        if (flags & SPRITE_FLAG_PALETTE_FIXED) {
            palette = M2C_FIELD(obj, u8 *, SPRITE_PALETTE);
            ((void (*)(s32))SetSpritePaletteBase)(palette);
        } else if (flags & SPRITE_FLAG_PALETTE_CYCLE) {
            SpriteLevels02091110 buf = *(const SpriteLevels02091110 *)gSpritePaletteCycle;
            {
                s32 idx = (s32)(M2C_FIELD(obj, s16 *, SPRITE_TIMER) >> 2);
                idx = Modulo(idx, SPRITE_PALETTE_CYCLE_LEN);
                SetSpritePaletteIndex(buf.v[idx]);
            }
        } else {
            palette = M2C_FIELD(obj, u8 *, SPRITE_PALETTE);
            SetSpritePaletteIndex(palette);
        }
        palette = M2C_FIELD(obj, u8 *, SPRITE_PALETTE);
        if (palette != 0) {
            geometryParam = (u8)(M2C_FIELD(obj, u8 *, SPRITE_FLAGS) & SPRITE_FLAG_GEOMETRY_PARAM);
            DrawSprite3DGeometry(M2C_FIELD(obj, M2C_UNK *, SPRITE_FRAME), posArg, M2C_FIELD(obj, M2C_UNK *, 0x28), M2C_FIELD(obj, M2C_UNK *, 0x2c), attrArg, extraArg, geometryParam);
        }
    }
    if (M2C_FIELD(obj, s32 *, 0x30) == 0) {
        return;
    }
    if (!(M2C_FIELD(obj, u8 *, SPRITE_FLAGS) & SPRITE_FLAG_FRAME_SET)) {
        return;
    }
    DrawSprite3DParts((M2C_UNK)obj);
}
/* Create a sprite driven by an animation script: allocate the scripted sprite
 * object and install its vtable, remember the script, then allocate and start
 * its first script player at (x, y).  ownsScript makes the script buffer be
 * freed together with the object; a mode of 0 selects the default mode 9. */
M2C_UNK CreateScriptedSprite(M2C_UNK script, M2C_UNK slot, M2C_UNK x, M2C_UNK y, u16 tile, s32 priority, s32 ownsScript, s32 mode) {
    extern M2C_UNK gScriptedSpriteClass;
    extern M2C_UNK gScriptedSpriteVtbl;
    M2C_UNK CreateSpriteFromClass(M2C_UNK, M2C_UNK);
    M2C_UNK MemAlloc(M2C_UNK);
    void SpritePlayer_Init(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *object;
    M2C_UNK player;

    if (mode == 0) {
        mode = 9;
    }
    object = (void *)CreateSpriteFromClass((M2C_UNK)&gScriptedSpriteClass, mode);
    if (object != 0) {
        *(M2C_UNK *)object = (M2C_UNK)&gScriptedSpriteVtbl;
        M2C_FIELD(object, M2C_UNK *, 0x40) = script;
        M2C_FIELD(object, M2C_UNK *, 0x38) = 0;
        M2C_FIELD(object, M2C_UNK *, 0x3C) = 0;
        M2C_FIELD(object, M2C_UNK *, 0x34) = 0;
        M2C_FIELD(object, u8 *, 0x44) = *((u8 *)&ownsScript);
        player = MemAlloc(0x30);
        if (player != 0) {
            SpritePlayer_Init(player, (M2C_UNK)object, script, slot, x, y, tile, priority);
        }
    }
    return (M2C_UNK)object;
}

/* Load an animation script from a file and create the scripted sprite that plays
 * it: the decompressed script buffer is owned by the sprite and freed with it. */
void CreateScriptedSpriteFromFile(M2C_UNK file, M2C_UNK slot, M2C_UNK x, M2C_UNK y, u16 tile, s32 priority, s32 mode) {
    s32 LoadDecompressedFile(M2C_UNK, M2C_UNK);
    M2C_UNK CreateScriptedSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, s32, s32, s32);
    s32 script = LoadDecompressedFile(file, 1);
    CreateScriptedSprite(script, slot, x, y, tile, priority, 1, mode);
}

/* Delete a scripted sprite: reset its vtable, tear down its player list and its
 * auxiliary sprite list, run its optional dispose callback, then free the
 * animation script (when the object owns it) and the object itself. */
void *DeleteScriptedSprite(void *sprite) {
    M2C_UNK SpritePlayer_FreeList();
    M2C_UNK Sprite_DestroyAuxList();
    M2C_UNK HeapFreeBlock(s32);
    M2C_UNK MemFree();
    extern M2C_UNK gScriptedSpriteVtbl;
    M2C_UNK (*dispose)(void *);

    M2C_FIELD(sprite, M2C_UNK **, 0) = &gScriptedSpriteVtbl;
    if (M2C_FIELD(sprite, s32 *, SPRITE_OWNER_PLAYER_LIST) != 0) {
        SpritePlayer_FreeList();
    }
    if (M2C_FIELD(sprite, s32 *, SPRITE_OWNER_AUX_LIST) != 0) {
        Sprite_DestroyAuxList();
    }
    dispose = M2C_FIELD(sprite, M2C_UNK (**)(void *), SPRITE_OWNER_DISPOSE);
    if (dispose != NULL) {
        dispose(sprite);
    }
    if (M2C_FIELD(sprite, u8 *, SPRITE_OWNER_OWNS_SCRIPT) != 0) {
        HeapFreeBlock(M2C_FIELD(sprite, s32 *, SPRITE_OWNER_SCRIPT));
    }
    MemFree(sprite);
    return sprite;
}

/* Tear down a scripted sprite (its out-of-line destructor): reset its vtable,
   destroy its script-player and auxiliary lists and run its dispose callback,
   then free the animation script it owns.  The object itself stays allocated
   (DeleteScriptedSprite releases it). */
void *DestroyScriptedSprite(void *sprite) {
    M2C_UNK SpritePlayer_FreeList();
    M2C_UNK Sprite_DestroyAuxList();
    M2C_UNK HeapFreeBlock(s32);
    extern M2C_UNK gScriptedSpriteVtbl;
    M2C_UNK (*dispose)(void *);

    M2C_FIELD(sprite, M2C_UNK **, 0) = &gScriptedSpriteVtbl;
    if (M2C_FIELD(sprite, s32 *, SPRITE_OWNER_PLAYER_LIST) != 0) {
        SpritePlayer_FreeList();
    }
    if (M2C_FIELD(sprite, s32 *, SPRITE_OWNER_AUX_LIST) != 0) {
        Sprite_DestroyAuxList();
    }
    dispose = M2C_FIELD(sprite, M2C_UNK (**)(void *), SPRITE_OWNER_DISPOSE);
    if (dispose) {
        dispose(sprite);
    }
    if (M2C_FIELD(sprite, u8 *, SPRITE_OWNER_OWNS_SCRIPT) != 0) {
        HeapFreeBlock(M2C_FIELD(sprite, s32 *, SPRITE_OWNER_SCRIPT));
    }
    return sprite;
}

#pragma opt_propagation off
/* One frame of a child-sprite wrapper: draw the sprite it holds at the wrapper's
 * map position (x and y in cell units scaled by the map cell size, z from the
 * wrapper) and delete the wrapper once the child sprite has stopped. */
void DrawChildSprite3D(void *wrapper) {
M2C_UNK DrawSprite3D(void *); M2C_UNK DeleteSpriteObject(void *);
s32 pos[3]; s32 *child; s32 alive,gone;
pos[0]=M2C_FIELD(wrapper,s32 *,SPRITE_WRAPPER_X)*MAP_SPRITE_CELL_SIZE;
pos[1]=M2C_FIELD(wrapper,s32 *,SPRITE_WRAPPER_Y)*MAP_SPRITE_CELL_SIZE;
pos[2]=M2C_FIELD(wrapper,s32 *,SPRITE_WRAPPER_Z);
if(((s32 (*)(void *,s32 *,s32,s32))DrawSprite3D)(M2C_FIELD(wrapper,void **,SPRITE_WRAPPER_CHILD),pos,MAP_SPRITE_GFX_SIZE_SMALL,0)) return;
child=M2C_FIELD(wrapper,s32 **,SPRITE_WRAPPER_CHILD);gone=1;
if(child && *child) gone=0;
alive=gone==0;
if(alive) return;
DeleteSpriteObject(wrapper);
}
#pragma opt_propagation reset
void func_0209106c(void *a) {void Sprite_ClearHandle(s32 *);void (*fp)(s32 *)=Sprite_ClearHandle;fp(M2C_FIELD(a,s32 **,0x58));}
/* Draw part `tag` of a sprite animation script at frame `frame`: look up that
 * part's frame quad data and, when it exists, submit its 3D geometry at `pos`
 * with the given graphics parameters.  Returns 1 when the frame was drawn, 0
 * when the script has no such frame. */
s32 DrawSpriteScript(void *scripts,s32 tag,s32 frame,const void *pos,s32 gfxAddr,s32 tileDataSize,s32 gfxSize,s32 extra,u8 geometryParam) {
s32 GetSpriteScriptFrameData(void *,s32,s32);s32 DrawSprite3DGeometry(s32,s32,s32,s32,s32,s32,u8);
s32 frameData=GetSpriteScriptFrameData(scripts,tag,frame);if(frameData) {DrawSprite3DGeometry(frameData,(s32)pos,gfxAddr,tileDataSize,gfxSize,extra,geometryParam);return 1;}return 0;
}
#pragma optimization_level reset
M2C_UNK DrawSprite3D(void *arg0) {
void DrawSprite3DFrame(); void Sprite_TickTimer(void *); M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);
s32 ok=(arg0!=0 && *(s32 *)arg0!=0);
if(ok==0) return 0;
((void (*)())DrawSprite3DFrame)(arg0); Sprite_TickTimer(arg0); return Sprite_UpdateAnimationScript((M2C_UNK)arg0);
}

extern void DrawSprite3DFrame();

void SetSpritePaletteBase(void) {
    *(s32 *)0x040004A4 = 0x081E4080;
}

void SetSpritePaletteIndex(s32 a) {s32 v=a==31?0:63;*(s32 *)0x040004a4=(v<<24)|0x80|(a<<16);}
#pragma optimization_level reset
s32 CreateSpriteAnim(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
            void Sprite_InitAnimation(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020919b4(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_020919b4(0);
    Sprite_InitAnimation(temp_r0, arg0, arg1, arg2);
    return temp_r0;
}

void Sprite_ClearHandle(s32 *arg0) {
    if (arg0 != NULL && *arg0 != 0) {
        *arg0 = 0;
    }
}

s32 DrawSprite2D(s32 *arg0, s32 arg1, s32 arg2) {
    void DrawSprite2DFrame(M2C_UNK, M2C_UNK, M2C_UNK);
    void Sprite_TickTimer(void *);
    M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);

    if (arg0 != (void *)0 && *arg0 != 0) {
        DrawSprite2DFrame((M2C_UNK)arg0, (M2C_UNK)arg1, (M2C_UNK)arg2);
        Sprite_TickTimer((void *)arg0);
        return Sprite_UpdateAnimationScript((M2C_UNK)arg0);
    }
    return 0;
}

/* Draw the sprite as a plain 2D OBJ: submit its quad with the frame's template
   and priority, adjusting the tile id to the engine's tile numbering, and then
   draw the sprite's extra quad parts when it has any. */
void DrawSprite2DFrame(M2C_UNK sprite, M2C_UNK x, M2C_UNK y) {
void func_02091570(M2C_UNK);
void DrawSprite3DParts(M2C_UNK);
void AddSprite(u16,u16,u16,s32,s32);
extern void *gCur3DSpriteEngine;
void *p=(void *)sprite;
u32 paletteBits=0, v;
if (!p || !*(s32 *)p) return;
if (M2C_FIELD(p,s32 *,SPRITE_LOOP_FRAME)) {
func_02091570(sprite);
paletteBits=(M2C_FIELD(p,u8 *,SPRITE_TILE_BASE)&31)<<9;
}
v=M2C_FIELD(p,u32 *,SPRITE_OAM_ATTR2);
AddSprite((u16)(x|paletteBits),(u16)y,(u16)((v&0xfc00)|(((v&0x3ff)>>((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))&0x3ff)),M2C_FIELD(p,s32 *,SPRITE_FRAME),M2C_FIELD(p,s8 *,SPRITE_PRIORITY));
if (M2C_FIELD(p,s32 *,SPRITE_PARTS) && (M2C_FIELD(p,u8 *,SPRITE_FLAGS)&SPRITE_FLAG_FRAME_SET)) DrawSprite3DParts(sprite);
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

/* Point a sprite at animation frame `frameIndex` and restart its script.  With
 * SPRITE_FLAG_OFFSET_TABLE set, the frame data is a table of byte offsets (its
 * u16 at +2 leads to the frame table); otherwise it is an array of frame
 * pointers whose entry frameIndex+1 is the frame.  Both the loop cursor and the
 * script cursor start at the selected frame. */
void SetSpriteAnimFrame(void *sprite,s32 frameIndex) {
void Sprite_RestartAnimation(void *);
void *data;
u8 *base;
void *frame;
u32 off;
if(sprite==NULL)return;
data=*(void **)sprite;
if(data==NULL)return;
if(M2C_FIELD(sprite,u8 *,SPRITE_FLAGS)&SPRITE_FLAG_OFFSET_TABLE) {
base=(u8 *)data;
off=*(u16 *)(base+2)&~1u;
base+=off;
frame=base+(*(u16 *)(base+frameIndex*2)&~1u);
M2C_FIELD(sprite,void **,SPRITE_LOOP_PTR)=frame;
base=*(u8 **)sprite;
off=*(u16 *)(base+2)&~1u;
base+=off;
frame=base+(*(u16 *)(base+frameIndex*2)&~1u);
} else {
u32 idx=frameIndex+1;
M2C_FIELD(sprite,void **,SPRITE_LOOP_PTR)=((void **)data)[idx];
frame=((void **)data)[idx];
}
M2C_FIELD(sprite,void **,SPRITE_SCRIPT)=frame;
Sprite_RestartAnimation(sprite);
}

void DrawSprite3DParts(M2C_UNK a) {
    void QueueMemoryCopy(s32, s32, s32, s32);
    void QueueTextureBankCopy(s32, s32, s32, s32);
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
                QueueTextureBankCopy(offsetVal, *(s32 *)((char *)arg0+0x28) + r6, product, r11);
            } else {
                s32 spiritShifted = ((u32)*(s32 *)((char *)arg0+0x28) << 22) >> 17;
                s32 secondArg = (*(s32 *)((char *)engine + 0x1C) + spiritShifted);secondArg+=r6;
                QueueMemoryCopy(offsetVal, secondArg, product, 0);
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

/* Install the sprite's animation data from the `script` block: when the sprite's
 * SPRITE_FLAG_OFFSET_TABLE is set the block's first words are byte offsets into
 * it, otherwise they are the data-base, loop and script pointers themselves. */
void Sprite_SetScriptData(M2C_UNK arg0, M2C_UNK arg1) {
    char *obj = (char *)arg0;
    char *base;
    char *r3;
    u32 off0;
    u32 off2;
    u32 b;
    u32 nested;
    *(M2C_UNK *)obj = arg1;
    if (M2C_FIELD(obj, u8 *, SPRITE_FLAGS) & SPRITE_FLAG_OFFSET_TABLE) {
        base = (char *)*(M2C_UNK *)obj;
        off0 = *(unsigned short *)base;
        off0 = off0 & ~1;
        *(M2C_UNK *)(obj + SPRITE_DATA_BASE) = (M2C_UNK)(base + off0);
        r3 = (char *)*(M2C_UNK *)obj;
        off2 = *(unsigned short *)(r3 + 2);
        b = off2 & ~1;
        nested = *(unsigned short *)(r3 + b);
        nested = nested & ~1;
        *(M2C_UNK *)(obj + SPRITE_LOOP_PTR) = (M2C_UNK)(r3 + b + nested);
        r3 = (char *)*(M2C_UNK *)obj;
        off2 = *(unsigned short *)(r3 + 2);
        b = off2 & ~1;
        nested = *(unsigned short *)(r3 + b);
        nested = nested & ~1;
        *(M2C_UNK *)(obj + SPRITE_SCRIPT) = (M2C_UNK)(r3 + b + nested);
    } else {
        base = (char *)*(M2C_UNK *)obj;
        *(M2C_UNK *)(obj + SPRITE_DATA_BASE) = *(M2C_UNK *)base;
        *(M2C_UNK *)(obj + SPRITE_LOOP_PTR) = *(M2C_UNK *)(base + 4);
        *(M2C_UNK *)(obj + SPRITE_SCRIPT) = *(M2C_UNK *)(base + 4);
    }
}

void Sprite_RestartAnimation(void *arg0) {
    M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);
    u16 temp_r4;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    temp_r4 = M2C_FIELD(arg0, u16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    M2C_FIELD(arg0, u16 *, 0x1C) = 0x100;
    Sprite_UpdateAnimationScript((M2C_UNK)arg0);
    M2C_FIELD(arg0, u16 *, 0x1C) = temp_r4;
}

/* Initialise a script-driven sprite: install its animation data, then set its
 * draw priority, flags and palette (the map sprite palette) and start the
 * animation from its first frame at normal speed. */
void Sprite_InitAnimation(M2C_UNK spriteArg, M2C_UNK script, M2C_UNK priority, M2C_UNK flags) {
void Sprite_SetScriptData(M2C_UNK, M2C_UNK); M2C_UNK Sprite_UpdateAnimationScript(M2C_UNK);
void *sprite=(void*)spriteArg; M2C_UNK prio=priority; M2C_UNK zero;
M2C_FIELD(sprite,u8*,SPRITE_FLAGS)=flags; Sprite_SetScriptData(spriteArg,script); zero=0;
M2C_FIELD(sprite,s32*,SPRITE_PARTS)=zero; M2C_FIELD(sprite,s32*,SPRITE_OAM_ATTR2)=zero; M2C_FIELD(sprite,s32*,0x2c)=zero;
M2C_FIELD(sprite,s16*,SPRITE_TIMER)=zero; M2C_FIELD(sprite,s16*,SPRITE_DELAY)=zero;
M2C_FIELD(sprite,u8*,SPRITE_PRIORITY)=prio; M2C_FIELD(sprite,u8*,SPRITE_PALETTE)=MAP_SPRITE_PALETTE; M2C_FIELD(sprite,s32*,SPRITE_LOOP_FRAME)=zero;
M2C_FIELD(sprite,u8*,SPRITE_TILE_BASE)=zero; M2C_FIELD(sprite,s16*,SPRITE_DELAY)=zero;
M2C_FIELD(sprite,s16*,SPRITE_SPEED)=0x100; M2C_FIELD(sprite,s16*,SPRITE_FRACTION)=zero; M2C_FIELD(sprite,s16*,SPRITE_COMMAND)=zero;
Sprite_UpdateAnimationScript((M2C_UNK)sprite);
}

#pragma optimization_level 2
s32 func_020919b4(M2C_UNK a) {extern s32 data_02157918;s32 i=0; s32 *p=&data_02157918;do {if(*p==a)return i*52+(s32)&data_02157918;i++;p=(s32*)((u8*)p+52);}while(i<32);return 0;}
#pragma optimization_level reset
/* One frame of a child-sprite wrapper's 2D draw: draw the child at the wrapper's
 * screen position and delete the wrapper once the child sprite has stopped. */
void DrawChildSprite2D(void *wrapper) {
    M2C_UNK DeleteSpriteObject(void *);
    s32 DrawSprite2D(s32 *, s32, s32);
    s32 *child;
    s32 gone;

    if (DrawSprite2D(M2C_FIELD(wrapper, s32 **, SPRITE_WRAPPER_CHILD), M2C_FIELD(wrapper, s32 *, SPRITE_WRAPPER_X), M2C_FIELD(wrapper, s32 *, SPRITE_WRAPPER_Y)) != 0) {
        return;
    }
    child = M2C_FIELD(wrapper, s32 **, SPRITE_WRAPPER_CHILD);
    gone = 1;
    if ((child != NULL) && (*child != 0)) {
        gone = 0;
    }
    if (gone == 0) {
        return;
    }
    DeleteSpriteObject(wrapper);
}

#pragma scheduling off
void func_02091a40(void *arg0) {
    Sprite_ClearHandle(M2C_FIELD(arg0, s32 *, 0x58));
}
#pragma scheduling reset
void func_02091a50(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02102a28;
    extern M2C_UNK data_021029f0;
    DeleteSpriteObjectsOfClass(&data_02102a28);
    DeleteSpriteObjectsOfClass(&data_021029f0);
}

u16 func_02091a70(void *arg0) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u16 *, 0x24);
    M2C_FIELD(arg0, u16 *, 0x24) = 0U;
    return temp_r2;
}

#pragma push
#pragma scheduling off
s32 GetSpriteScriptDuration(void *arg0) {
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
s32 GetSpriteScriptFrameCount(void *arg0) {
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

/* Resolve the frame data a sprite script (per-tag timed frame entries) draws at
 * a given frame number: a looping script wraps the frame into its total, an
 * ended one clamps it, a stopped one draws nothing. */
s32 GetSpriteScriptFrameData(void *scripts,s32 tag,s32 frame){
u16 *set=scripts;
s32 Modulo(s32,s32);
u16 *dataOffsets,*script,*terminator; s32 total;
dataOffsets=(u16 *)((u8 *)set+(set[0]&~1));
terminator=(u16 *)((u8 *)set+(set[1]&~1));
script=(u16 *)((u8 *)terminator+(terminator[tag]&~1));
terminator=script;total=0;
while(terminator[0]){total+=terminator[0];terminator+=2;}
switch(terminator[1]){
case SPRITE_CMD_LOOP:frame=Modulo(frame,total);break;
case SPRITE_CMD_END:if(frame>total)frame=total;break;
case SPRITE_CMD_STOP:return 0;
}
if(script[0]){do{frame-=*(volatile u16 *)script;if(frame<=0)break;script+=2;}while(script[0]);}
return (s32)((u8 *)dataOffsets+(dataOffsets[script[1]]&~1));
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
void AddRecordFunds(s32 index,s32 value) {
extern u32 gRecordValues[];
if(value+gRecordValues[index]<0x5f5e0ffU) { gRecordValues[index]=gRecordValues[index]+value; return; }
gRecordValues[index]=0x5f5e0ffU;
}
#pragma peephole reset
M2C_UNK func_02091c88(M2C_UNK arg0, M2C_UNK arg1) {
    extern unsigned int gRecordValues[];
    gRecordValues[arg0] = (unsigned int)arg1;
}

void LoadScenePanelGraphics(void) {
extern void *gCur3DSpriteEngine;
extern M2C_UNK gScenePanelGraphics;
extern M2C_UNK gScenePanelPalette;
LoadGraphicsBlock(&gScenePanelGraphics,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c));
CopyToObjPaletteShadow(&gScenePanelPalette,0x200,0x20);
}

/* Load the shared scene-panel graphics and palette for both 3D sprite engines:
 * make each engine current in turn (main screen, then sub screen), upload the
 * panel to it, and restore the previously current engine afterwards. */
void LoadScenePanelGraphicsOnBothEngines(void) {
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    void *savedEngine = gCur3DSpriteEngine;
    s32 screen = 0;

    do {
        gCur3DSpriteEngine = screen == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        LoadScenePanelGraphics();
        screen++;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
}

#pragma scheduling off
void LoadScenePanelIconTiles(void) {M2C_UNK CopyU16(M2C_UNK*,s32,M2C_UNK);extern M2C_UNK gScenePanelIconTiles;extern void *gCur3DSpriteEngine;CopyU16(&gScenePanelIconTiles,M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x800,0x800);}
#pragma scheduling reset
void LoadScenePanelPalette(s32 arg0) {
    M2C_UNK CopyToObjPaletteShadow(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_0211e088;
    CopyToObjPaletteShadow(&data_0211e088, arg0 << 5, 0x20);
}

void func_02091d6c(s32 a,s32 b) {
extern void *gCur3DSpriteEngine;
LoadScenePanelPalette(a);
if(b!=0)return;
DimPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+((a<<5)&~1));
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

