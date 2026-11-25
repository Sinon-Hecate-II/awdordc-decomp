/* 38 functions from 0x02088044 to 0x02088FF4 (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
#include "ds3dsprite.h"
typedef struct { u32 words[2]; } Unk0200FilePair;

void func_02088044(void *arg0) {
    void *SpriteCellListFindCell();
    M2C_UNK SpriteCellListSelectCell(void *, void *);
    s32 WidgetRectContainsPoint(void *, void *, u16, u16);
    s32 SpriteCellListBackgroundHit(void *, u16, u16);
    extern void *gTouchState;
    void *temp_r1_3;
    s8 temp_r1_2;
    u16 temp_r0;
    u16 temp_r1;
    u16 temp_r2;
    u32 var_r0;
    u32 var_r0_2;
    u8 temp_r0_5;
    void *temp_r0_2;
    void *temp_r0_3;
    void *var_r4;
    s32 var_r5;
    void *temp_r0_4;

    M2C_FIELD(arg0, s8 *, 0xA) = -1;
    M2C_FIELD(arg0, s8 *, 9) = -1;
    M2C_FIELD(arg0, s8 *, 0xB) = -1;
    var_r5 = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, s8 *, 0xC) = -1;
    if (M2C_FIELD(gTouchState, u8 *, 0x12) != 0) {
        var_r4 = M2C_FIELD(arg0, void **, 0x14);
        if ((s32) M2C_FIELD(arg0, u16 *, 0x10) > 0) {
loop_2:
            if ((M2C_FIELD(var_r4, u16 *, 0xA) != 0) && (WidgetRectContainsPoint(arg0, var_r4, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0)) {
                if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
                    M2C_FIELD(arg0, s8 *, 8) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                    temp_r0 = M2C_FIELD(var_r4, u16 *, 0xA);
                    if (temp_r0 & 1) {
                        if (temp_r0 & 0x20) {
                            temp_r0_2 = M2C_FIELD(arg0, void **, 0);
                            if ((temp_r0_2 != NULL) && (temp_r1 = M2C_FIELD(var_r4, u16 *, 8), (temp_r1 == M2C_FIELD(temp_r0_2, u16 *, 8)))) {
                                M2C_FIELD(arg0, s8 *, 0xB) = (s8) temp_r1;
                            } else {
                                SpriteCellListSelectCell(arg0, var_r4);
                            }
                        } else {
                            M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                            SpriteCellListSelectCell(arg0, var_r4);
                        }
                    } else if (temp_r0 & 0xC) {
                        SpriteCellListSelectCell(arg0, var_r4);
                    }
                } else {
                    temp_r2 = M2C_FIELD(var_r4, u16 *, 8);
                    if (temp_r2 == M2C_FIELD(arg0, s8 *, 8)) {
                        if ((M2C_FIELD(gTouchState, u8 *, 0x13) != 0) && (M2C_FIELD(var_r4, u16 *, 0xA) & 0x10)) {
                            M2C_FIELD(arg0, s8 *, 0xB) = (s8) temp_r2;
                            M2C_FIELD(arg0, u8 *, 0xE) = 1U;
                        }
                    } else {
                        M2C_FIELD(arg0, s8 *, 8) = -1;
                        if (M2C_FIELD(gTouchState, u8 *, 0x13) != 0) {
                            M2C_FIELD(arg0, u8 *, 0xE) = 1U;
                            if (M2C_FIELD(var_r4, u16 *, 0xA) & 0x10) {
                                M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                            }
                        } else {
                            M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                        }
                        if (M2C_FIELD(var_r4, u16 *, 0xA) & 8) {
                            SpriteCellListSelectCell(arg0, var_r4);
                        }
                    }
                }
                M2C_FIELD(arg0, s8 *, 0xC) = (s8) M2C_FIELD(var_r4, u16 *, 8);
            } else {
                var_r5 += 1;
                var_r4 += 0xC;
                if (var_r5 < (s32) M2C_FIELD(arg0, u16 *, 0x10)) {
                    goto loop_2;
                }
            }
        }
        if (var_r5 == M2C_FIELD(arg0, u16 *, 0x10)) {
            if ((M2C_FIELD(arg0, u16 *, 0x22) != 0) && (SpriteCellListBackgroundHit(arg0, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0)) {
                if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
                    M2C_FIELD(arg0, s8 *, 8) = -2;
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                    if (M2C_FIELD(arg0, u16 *, 0x22) & 1) {
                        M2C_FIELD(arg0, s8 *, 0xD) = 1;
                    }
                } else if (M2C_FIELD(arg0, s8 *, 8) == -2) {
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                } else {
                    M2C_FIELD(arg0, s8 *, 8) = -1;
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                }
            } else {
                M2C_FIELD(arg0, s8 *, 8) = -1;
                M2C_FIELD(arg0, u8 *, 0xE) = 0U;
            }
        }
    } else if (M2C_FIELD(gTouchState, u8 *, 0x16) != 0) {
        temp_r1_2 = M2C_FIELD(arg0, s8 *, 8);
        if ((temp_r1_2 != -1) && ((u32) M2C_FIELD(gTouchState, u8 *, 0x10) < 0x1EU)) {
            if (temp_r1_2 != -2) {
                temp_r0_3 = SpriteCellListFindCell();
                if ((WidgetRectContainsPoint(arg0, temp_r0_3, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0) && (M2C_FIELD(temp_r0_3, u16 *, 0xA) & 2)) {
                    if (M2C_FIELD(arg0, u8 *, 0xE) == 0) {
                        M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(arg0, s8 *, 8);
                    }
                }
            } else if ((SpriteCellListBackgroundHit(arg0, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0) && (M2C_FIELD(arg0, u16 *, 0x22) & 2)) {
                M2C_FIELD(arg0, s8 *, 0xD) = 1;
            }
        }
        M2C_FIELD(arg0, s8 *, 8) = -1;
        M2C_FIELD(arg0, u8 *, 0xE) = 0U;
    } else {
        M2C_FIELD(arg0, s8 *, 8) = -1;
        M2C_FIELD(arg0, u8 *, 0xE) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 0xF) == 0) {
        temp_r1_3 = M2C_FIELD(arg0, void **, 4);
        if (temp_r1_3 != M2C_FIELD(arg0, void **, 0)) {
            if (temp_r1_3 != NULL) {
                var_r0 = M2C_FIELD(temp_r1_3, u16 *, 8);
            } else {
                var_r0 = -1U;
            }
            M2C_FIELD(arg0, s8 *, 0xA) = (s8) var_r0;
            temp_r0_4 = M2C_FIELD(arg0, void **, 0);
            if (temp_r0_4 != NULL) {
                var_r0_2 = M2C_FIELD(temp_r0_4, u16 *, 8);
            } else {
                var_r0_2 = -1U;
            }
            M2C_FIELD(arg0, s8 *, 9) = (s8) var_r0_2;
        }
    }
    temp_r0_5 = M2C_FIELD(arg0, u8 *, 0xF);
    if ((u32) temp_r0_5 < 0xFFU) {
        M2C_FIELD(arg0, u8 *, 0xF) = (u8) (temp_r0_5 + 1);
    }
}

/* Reset the resource manager at boot: clear every slot's loaded flag, then load
 * the two resources the game starts with (slots 0 and 4). */
void InitResourceSystem(void) {
    M2C_UNK LoadResource(M2C_UNK);
    extern M2C_UNK gResourceLoaded;
    s32 slot;
    u8 *flag;
    slot = 0;
    flag = (u8 *)&gResourceLoaded;
    do {
        *flag++ = 0;
        slot++;
    } while (slot < RESOURCE_SLOT_COUNT);
    LoadResource(0);
    LoadResource(4);
}

/* Load resource file `index` of the game's data archive into memory unless it
 * is already loaded: read its file header, open its range, clear the BSS after
 * the data, copy the data in 0x2800-byte chunks and run the file's initializers. */
M2C_UNK LoadResource(M2C_UNK index) {
    extern M2C_UNK gResourceLoaded, gResourceFileIds;
    s32 LoadFileHeader(void *, s32, s32);
    void InitFileRequest(void *);
    void BuildFileRange(void *, void *);
    s32 OpenFileRange(void *, Unk0200FilePair);
    void ClearFileBss(void *);
    s32 FileRead(void *, void *, s32);
    void CloseFileRequest(void *);
    void CompleteFileLoad(void *);
    M2C_UNK func_020e349c(void);

    Unk0200FilePair range;
    FSFileHeader header;
    u32 request[18];
    s32 size;
    u8 *dest;
    s32 offset, chunk;
    u32 loaded;

    loaded = ((u8 *) &gResourceLoaded)[index];
    if (loaded == 1) return loaded;
    if (!LoadFileHeader(&header, 0, ((s32 *) &gResourceFileIds)[index])) return;
    InitFileRequest(request);
    BuildFileRange(&range, &header);
    if (!OpenFileRange(request, range)) return;
    ClearFileBss(&header);
    size = request[10] - request[9];
    dest = (u8 *) header.data;
    for (offset = 0; offset < size; offset += 0x2800) {
        chunk = size - offset;
        if (chunk >= 0x2800) chunk = 0x2800;
        if (chunk != FileRead(request, dest + offset, chunk)) {
            CloseFileRequest(request);
            return;
        }
    }
    CloseFileRequest(request);
    CompleteFileLoad(&header);
    ((u8 *) &gResourceLoaded)[index] = 1;
    func_020e349c();
}

/* Unload resource slot `index` when it is loaded: drop its archive file from the
 * module loader, clear the loaded flag if the drop succeeded, then commit. */
void UnloadResource(u8 index) {
 s32 UnloadFileModule(M2C_UNK, s32);
 M2C_UNK func_020e349c();
 extern M2C_UNK gResourceFileIds, gResourceLoaded;
 if (M2C_FIELD(&gResourceLoaded, u8 *, index) == 0) return;
 if (UnloadFileModule(0, ((s32 *)&gResourceFileIds)[index]) == 1) M2C_FIELD(&gResourceLoaded, u8 *, index) = 0;
 func_020e349c();
}

/* Unload every loaded resource that shares a memory group with slot `index`
 * (their gResourceDependencyMasks entries intersect), so that `index` can be
 * loaded into the freed memory. */
void UnloadConflictingResources(s32 index) {
    extern M2C_UNK gResourceDependencyMasks;
    s32 i;
    u8 *p;
    p = (u8 *)&gResourceDependencyMasks;
    i = 0;
    do {
        if ((*p & ((u8 *)&gResourceDependencyMasks)[index]) && IsResourceLoaded((u8)i) != 0) UnloadResource(i);
        i++;
        p++;
    } while (i < RESOURCE_SLOT_COUNT);
}

s32 IsResourceLoaded(s32 arg0) {
    extern M2C_UNK gResourceLoaded;
    return M2C_FIELD(&gResourceLoaded, u8 *, arg0);
}

void func_0208859c(void){if(IsResourceLoaded(0)!=0)return;UnloadConflictingResources(0);LoadResource(0);}

void func_020885c4(void){if(IsResourceLoaded(2)!=0)return;UnloadConflictingResources(2);LoadResource(2);}

void func_020885ec(void) {
    UnloadResource(2);
}

void func_020885fc(void) {
    if (IsResourceLoaded(3) != 0) {
        return;
    }
    UnloadConflictingResources(3);
    LoadResource(3);
}

void func_02088624(void) {
    UnloadResource(3);
}

void func_02088634(void) {
    if (IsResourceLoaded(4) != 0) {
        return;
    }
    UnloadConflictingResources(4);
    LoadResource(4);
}

void func_0208865c(void) {
    if (IsResourceLoaded(5) != 0) {
        return;
    }
    UnloadConflictingResources(5);
    LoadResource(5);
}

void func_02088684(void) {
    if (IsResourceLoaded(6) != 0) {
        return;
    }
    UnloadConflictingResources(6);
    LoadResource(6);
}

void func_020886ac(void) {
    if (IsResourceLoaded(7) != 0) {
        return;
    }
    UnloadConflictingResources(7);
    LoadResource(7);
}

void func_020886d4(void) {
    if (IsResourceLoaded(9) != 0) {
        return;
    }
    UnloadConflictingResources(9);
    LoadResource(9);
}

void func_020886fc(void) {
    if (IsResourceLoaded(0xA) != 0) {
        return;
    }
    UnloadConflictingResources(0xA);
    LoadResource(0xA);
}

void func_02088724(void) {
    if (IsResourceLoaded(1) != 0) {
        return;
    }
    UnloadConflictingResources(1);
    LoadResource(1);
}

void func_0208874c(void) {
    if (IsResourceLoaded(0xB) != 0) {
        return;
    }
    UnloadConflictingResources(0xB);
    LoadResource(0xB);
}

#pragma optimization_level 4
void func_02088774(s32 a){void CopyU16(void *,s32,s32);extern u8 data_021577c0[];extern void *gCur3DSpriteEngine;s32 base=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30);s32 offset=(a<<5)&~1;CopyU16(data_021577c0,offset+base,32);}
#pragma optimization_level reset
/* Draw a 3D sprite actor once at a temporary position and priority with the
 * given quad template, then restore its own position, priority and template. */
void DrawSpriteActorAt(void *p, s32 x, s32 y, s32 priority, s32 template) {
    void DrawSpriteActor(void *);
    s32 savedX = M2C_FIELD(p, s16 *, SPRITE_ACTOR_X),
        savedY = M2C_FIELD(p, s16 *, SPRITE_ACTOR_Y),
        savedPriority = M2C_FIELD(p, s8 *, SPRITE_ACTOR_PRIORITY),
        savedTemplate = M2C_FIELD(p, s32 *, DS3D_SPRITE_TEMPLATE);
    M2C_FIELD(p, s16 *, SPRITE_ACTOR_X) = x;
    M2C_FIELD(p, s16 *, SPRITE_ACTOR_Y) = y;
    M2C_FIELD(p, s8 *, SPRITE_ACTOR_PRIORITY) = priority;
    M2C_FIELD(p, s32 *, DS3D_SPRITE_TEMPLATE) = template;
    DrawSpriteActor(p);
    M2C_FIELD(p, s16 *, SPRITE_ACTOR_X) = savedX;
    M2C_FIELD(p, s16 *, SPRITE_ACTOR_Y) = savedY;
    M2C_FIELD(p, s8 *, SPRITE_ACTOR_PRIORITY) = savedPriority;
    M2C_FIELD(p, s32 *, DS3D_SPRITE_TEMPLATE) = savedTemplate;
}

void DrawSpriteActor(void *p){
s32 func_01ff8f90(s32,s32,s32);void func_01ffaacc(u16,u16,u16,s32,s32);
extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;
void *saved,*bank; s32 i;u32 mode,flags;u16 x,y,attr,pal;u32 shift,tile,part;
if(M2C_FIELD(p,s32 *,0x44)==0)return;
if((M2C_FIELD(p,u32 *,0x40)>>26)==0)return;
if(((u32)(M2C_FIELD(p,u8 *,0x48)<<31)>>31)==0)return;
if(!func_01ff8f90(M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38),M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a),M2C_FIELD(p,s32 *,0x44)))return;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==data_027e00c8)&&(mode!=1||bank==data_027e00c4)&&(mode!=3||bank==saved)){
shift=(u32)(M2C_FIELD(M2C_FIELD(bank,void **,0),u16 *,0)<<17)>>30;
flags=M2C_FIELD(p,u32 *,0x40);
tile=M2C_FIELD(p,u16 *,0x3e);
pal=(u16)((flags<<6)>>24);
part=(tile>>shift)&0x3ff;
part|=(u16)(pal<<12);
attr=(u16)(part|M2C_FIELD(p,u16 *,0x3c));

y=(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255;
if((flags>>26)!=16)y|=0x400;
func_01ffaacc((u16)((M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&0x1ff),y,attr,M2C_FIELD(p,s32 *,0x44),M2C_FIELD(p,s8 *,0x49));
}}gCur3DSpriteEngine=saved;
}

typedef struct SpriteFadeWord {
    u32 other : 26;
    u32 alpha : 6;
} SpriteFadeWord;

static inline void ApplySpriteBlend(s32 alpha, s32 complement) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile flags;
    void *engine;
    flags = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *flags = (*flags & ~0xC0) | 0x40;
    engine = *(void **)gCur3DSpriteEngine;
    M2C_FIELD(engine, u8 *, 0x51) = (u8)alpha;
    engine = *(void **)gCur3DSpriteEngine;
    M2C_FIELD(engine, u8 *, 0x52) = (u8)complement;
}


#pragma scheduling off
void UpdateSpriteFade(void *arg0) {
    void Show3DSprite(void *);
    void Hide3DSprite(void *);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;

    u16 *volatile flags0;
    u16 *volatile flags1;
    u16 *volatile flags2;
    u16 *volatile flags3;
    u16 *volatile flags4;
    u16 *volatile flags5;
    u16 *volatile flags6;
    u16 *volatile flags7;
    u16 *volatile flags8;
    u16 *volatile flags9;
    void *previousEngine;
    void *engine;
    void *chosen;
    s32 visibility;
    int i;
    s32 top2;
    s32 category;

    top2 = (s32)(((u32)(unsigned char)M2C_FIELD(arg0, u8 *, 0x48) << 26) >> 30);
    if (top2 == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x4b) == 0 && top2 == 1) {
        Show3DSprite(arg0);
    }
        M2C_FIELD(arg0, u8 *, 0x4b) = (u8)(M2C_FIELD(arg0, u8 *, 0x4b) + 1);
        visibility = EaseInterpolate(4, 0, 0x10, M2C_FIELD(arg0, u8 *, 0x4b), M2C_FIELD(arg0, u8 *, 0x4a));
        M2C_FIELD(arg0, SpriteFadeWord *, 0x40).alpha = visibility;
        if ((((u32)M2C_FIELD(arg0, u8 *, 0x48) << 26) >> 30) == 2) {
            M2C_FIELD(arg0, SpriteFadeWord *, 0x40).alpha =
                16 - M2C_FIELD(arg0, SpriteFadeWord *, 0x40).alpha;
        }

    previousEngine = gCur3DSpriteEngine;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            chosen = g3DSpriteEngineMain;
        } else {
            chosen = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = chosen;
        category = (s32)(((u32)M2C_FIELD(arg0, u8 *, 0x48) << 28) >> 29);
        if (category == 0 && chosen != g3DSpriteEngineMain) {
            continue;
        }
        if (category == 1 && chosen != g3DSpriteEngineSub) {
            continue;
        }
        if (category == 3 && chosen != previousEngine) {
            continue;
        }

        engine = M2C_FIELD(chosen, void **, 0);
        flags0 = (u16 *)((u8 *)engine + 0x12);
        *flags0 = (u16)(*flags0 & ~0x1);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags1 = (u16 *)((u8 *)engine + 0x12);
        *flags1 = (u16)(*flags1 & ~0x2);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags2 = (u16 *)((u8 *)engine + 0x12);
        *flags2 = (u16)(*flags2 & ~0x4);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags3 = (u16 *)((u8 *)engine + 0x12);
        *flags3 = (u16)(*flags3 & ~0x8);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags4 = (u16 *)((u8 *)engine + 0x12);
        *flags4 = (u16)(*flags4 & ~0x10);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags5 = (u16 *)((u8 *)engine + 0x12);
        *flags5 = (u16)(*flags5 | 0x100);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags6 = (u16 *)((u8 *)engine + 0x12);
        *flags6 = (u16)(*flags6 | 0x200);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags7 = (u16 *)((u8 *)engine + 0x12);
        *flags7 = (u16)(*flags7 | 0x400);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags8 = (u16 *)((u8 *)engine + 0x12);
        *flags8 = (u16)(*flags8 | 0x800);

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags9 = (u16 *)((u8 *)engine + 0x12);
        *flags9 = (u16)(*flags9 & ~0x1000);

        {
            s32 alpha = M2C_FIELD(arg0, SpriteFadeWord *, 0x40).alpha;
            ApplySpriteBlend(alpha, 16 - alpha);
        }
    }

    gCur3DSpriteEngine = previousEngine;
    if ((u8)M2C_FIELD(arg0, u8 *, 0x4b) < (u8)M2C_FIELD(arg0, u8 *, 0x4a)) {
        return;
    }
    if ((((u32)M2C_FIELD(arg0, u8 *, 0x48) << 26) >> 30) == 2) {
        Hide3DSprite(arg0);
    }
        M2C_FIELD(arg0, u8 *, 0x48) = (u8)(M2C_FIELD(arg0, u8 *, 0x48) & ~0x30);
}
#pragma scheduling reset
/* Animate a shown 3D sprite actor's slide: count the frames of the current
 * slide and ease its position from the slide origin to the target with an
 * EASE_OUT_QUAD (4) curve, then finish the slide's show/hide step. */
void UpdateSpriteSlide(void *p) {
void Show3DSprite(void *);void Hide3DSprite(void *);s32 EaseInterpolate(s32,s32,s32,s32,s32);
s32 slideMode,length,frame;
slideMode=(u32)(M2C_FIELD(p,u8 *,SPRITE_ACTOR_STATE)<<24)>>30;
if(!slideMode)return;
length=1;frame=0;
if(M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_DELAY)){M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_DELAY)--;return;}
if(M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_TIMER)==0 && slideMode==SPRITE_SLIDE_SHOW)Show3DSprite(p);
M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_TIMER)++;
switch((u32)(M2C_FIELD(p,u8 *,SPRITE_ACTOR_STATE)<<24)>>30){
case SPRITE_SLIDE_FORWARD:length=M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_LEN);frame=M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_TIMER);break;
case SPRITE_SLIDE_SHOW:length=M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_LEN);frame=M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_TIMER);break;
case SPRITE_SLIDE_REVERSE:length=M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_BACK_LEN);frame=length-M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_TIMER);break;
}
M2C_FIELD(p,s16 *,SPRITE_ACTOR_X)=EaseInterpolate(4,M2C_FIELD(p,s16 *,SPRITE_ACTOR_START_X),M2C_FIELD(p,s16 *,SPRITE_ACTOR_TARGET_X),frame,length);
M2C_FIELD(p,s16 *,SPRITE_ACTOR_Y)=EaseInterpolate(4,M2C_FIELD(p,s16 *,SPRITE_ACTOR_START_Y),M2C_FIELD(p,s16 *,SPRITE_ACTOR_TARGET_Y),frame,length);
if(M2C_FIELD(p,u8 *,SPRITE_ACTOR_SLIDE_TIMER)<length)return;
if(((u32)(M2C_FIELD(p,u8 *,SPRITE_ACTOR_STATE)<<24)>>30)==SPRITE_SLIDE_REVERSE)Hide3DSprite(p);
M2C_FIELD(p,u8 *,SPRITE_ACTOR_STATE)&=~0xc0;
}

void Show3DSprite(void *p){M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~1)|1;}

void Hide3DSprite(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) (M2C_FIELD(arg0, u8 *, 0x48) & ~1);
}

/* Show a 3D sprite actor: with no fade length, show it fully opaque (alpha
 * SPRITE_ACTOR_ALPHA_MAX) and clear any fade; otherwise start fading it in over
 * `frames` frames. */
void Show3DSpriteFade(void *sprite, s32 frames) {
    void Show3DSprite(void *);
    if (!frames) {
        Show3DSprite(sprite);
        M2C_FIELD(sprite, u32 *, SPRITE_ACTOR_SPLIT) = (M2C_FIELD(sprite, u32 *, SPRITE_ACTOR_SPLIT) & ~SPRITE_ACTOR_ALPHA_MASK) | (SPRITE_ACTOR_ALPHA_MAX << 26);
        M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) &= ~SPRITE_ACTOR_FADE_MASK;
        return;
    }
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_FADE_TIMER) = 0;
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_FADE_LEN) = frames;
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) = (M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) & ~SPRITE_ACTOR_FADE_MASK) | (SPRITE_FADE_IN << 4);
}

/* Hide a sprite actor: with `frames` 0 it is hidden at once - fully transparent
 * and with the fade mode cleared - otherwise it starts fading out over `frames`. */
void Hide3DSpriteFade(void *sprite, s32 frames) {
    void Hide3DSprite(void *);
    if (!frames) {
        Hide3DSprite(sprite);
        M2C_FIELD(sprite, u32 *, SPRITE_ACTOR_SPLIT) &= ~SPRITE_ACTOR_ALPHA_MASK;
        M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) &= ~SPRITE_ACTOR_FADE_MASK;
        return;
    }
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_FADE_TIMER) = 0;
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_FADE_LEN) = frames;
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) = (M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) & ~SPRITE_ACTOR_FADE_MASK) | (SPRITE_FADE_OUT << 4);
}

void Set3DSpriteSlideTarget(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x50) = arg1;
    M2C_FIELD(arg0, s16 *, 0x52) = arg2;
}

void Set3DSpriteSlideLength(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4E) = arg1;
}

void Set3DSpriteSlideStart(void *arg0, s16 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
    M2C_FIELD(arg0, s16 *, 0x56) = arg2;
}

void Set3DSpriteSlideBackLength(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4F) = arg1;
}

void Set3DSpriteSlideTargetAndStart(void *p,s16 a,s16 b,s16 c,s32 d){Set3DSpriteSlideTarget(p,a,b);Set3DSpriteSlideStart(p,c,d);}

/* Slide a 3D sprite in: set the slide's origin (startX, startY) and target
 * (targetX, targetY), give it a length in frames, then start it (SPRITE_SLIDE_SHOW). */
void Slide3DSpriteIn(void *sprite, s16 startX, s32 startY, s32 targetX, s32 targetY, s32 slideLen) {
    void Show3DSpriteSlide(void *);
    Set3DSpriteSlideTarget(sprite, targetX, targetY);
    Set3DSpriteSlideStart(sprite, startX, startY);
    Set3DSpriteSlideLength(sprite, slideLen);
    Show3DSpriteSlide(sprite);
}

/* Show a 3D sprite actor by sliding it in: keep the actor's current slide target,
 * give the slide `frames` frames and start it (mode SPRITE_SLIDE_SHOW). */
void Start3DSpriteSlideIn(void *sprite, s8 frames) {
    void Show3DSpriteSlide(void *);
    Set3DSpriteSlideTarget(sprite, M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TARGET_X), M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TARGET_Y));
    Set3DSpriteSlideLength(sprite, frames);
    Show3DSpriteSlide(sprite);
}

/* Show a 3D sprite by sliding it in: with no slide length, place it straight at
 * its target and show it; otherwise start the forward slide (mode SPRITE_SLIDE_SHOW). */
void Show3DSpriteSlide(void *sprite) {
    if (!M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_SLIDE_LEN)) {
        M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_X) = M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TARGET_X);
        M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_Y) = M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TARGET_Y);
        M2C_FIELD(sprite, s8 *, SPRITE_ACTOR_SLIDE_DELAY) = 0;
        M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) &= ~SPRITE_ACTOR_SLIDE_MODE_MASK;
        Show3DSprite(sprite);
        return;
    }
    if ((((u32)M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) << 24) >> 30) == SPRITE_SLIDE_SHOW) {
        return;
    }
    M2C_FIELD(sprite, s8 *, SPRITE_ACTOR_SLIDE_TIMER) = 0;
    M2C_FIELD(sprite, s8 *, SPRITE_ACTOR_SLIDE_DELAY) = 0;
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) = (u8)((M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) & ~SPRITE_ACTOR_SLIDE_MODE_MASK) | 0x80);
}

/* Slide a sprite out of view: start from the slide target (where it currently
 * sits) and move back to the slide start over `frames`, then hide it. */
void Slide3DSpriteOut(void *sprite, s32 targetX, s32 targetY, s16 startX, s32 startY, s32 frames) {
void Hide3DSpriteSlide(void *);
Set3DSpriteSlideTarget(sprite, targetX, targetY);
Set3DSpriteSlideStart(sprite, startX, startY);
Set3DSpriteSlideBackLength(sprite, frames);
Hide3DSpriteSlide(sprite);
}

/* Slide a 3D sprite back out: start from the origin it was slid in from, move
 * back over `frames` frames and hide it. */
void Start3DSpriteSlideOut(void *sprite, s8 frames) {
    void Hide3DSpriteSlide(void *);
    Set3DSpriteSlideStart(sprite, M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_START_X), M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_START_Y));
    Set3DSpriteSlideBackLength(sprite, frames);
    Hide3DSpriteSlide(sprite);
}

