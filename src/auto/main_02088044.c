/* 38 functions from 0x02088044 to 0x02088FF4 (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
typedef struct { u32 words[2]; } Unk0200FilePair;

void func_02088044(void *arg0) {
    void *func_02087e68();
    M2C_UNK func_02087ea0(void *, void *);
    s32 func_02087f20(void *, void *, u16, u16);
    s32 func_02087f70(void *, u16, u16);
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
            if ((M2C_FIELD(var_r4, u16 *, 0xA) != 0) && (func_02087f20(arg0, var_r4, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0)) {
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
                                func_02087ea0(arg0, var_r4);
                            }
                        } else {
                            M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                            func_02087ea0(arg0, var_r4);
                        }
                    } else if (temp_r0 & 0xC) {
                        func_02087ea0(arg0, var_r4);
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
                            func_02087ea0(arg0, var_r4);
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
            if ((M2C_FIELD(arg0, u16 *, 0x22) != 0) && (func_02087f70(arg0, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0)) {
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
                temp_r0_3 = func_02087e68();
                if ((func_02087f20(arg0, temp_r0_3, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0) && (M2C_FIELD(temp_r0_3, u16 *, 0xA) & 2)) {
                    if (M2C_FIELD(arg0, u8 *, 0xE) == 0) {
                        M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(arg0, s8 *, 8);
                    }
                }
            } else if ((func_02087f70(arg0, M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2)) != 0) && (M2C_FIELD(arg0, u16 *, 0x22) & 2)) {
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

void func_020883bc(void) {
    M2C_UNK LoadResource(M2C_UNK);
    extern M2C_UNK gResourceLoaded;
    s32 i;
    u8 *p;
    i = 0;
    p = (u8 *)&gResourceLoaded;
    do {
        *p++ = 0;
        i++;
    } while (i < 12);
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

void func_020884f8(u8 a){s32 func_0200c408(M2C_UNK,s32);M2C_UNK func_020e349c();extern M2C_UNK gResourceFileIds,gResourceLoaded;
if(M2C_FIELD(&gResourceLoaded,u8 *,a)==0)return;
if(func_0200c408(0,((s32 *)&gResourceFileIds)[a])==1)M2C_FIELD(&gResourceLoaded,u8 *,a)=0;
func_020e349c();}

void func_0208853c(s32 arg0) {
    extern M2C_UNK gResourceDependencyMasks;
    s32 i;
    u8 *p;
    p = (u8 *)&gResourceDependencyMasks;
    i = 0;
    do {
        if ((*p & ((u8 *)&gResourceDependencyMasks)[arg0]) && func_0208858c((u8)i) != 0) func_020884f8(i);
        i++;
        p++;
    } while (i < 12);
}

s32 func_0208858c(s32 arg0) {
    extern M2C_UNK gResourceLoaded;
    return M2C_FIELD(&gResourceLoaded, u8 *, arg0);
}

void func_0208859c(void){if(func_0208858c(0)!=0)return;func_0208853c(0);LoadResource(0);}

void func_020885c4(void){if(func_0208858c(2)!=0)return;func_0208853c(2);LoadResource(2);}

void func_020885ec(void) {
    func_020884f8(2);
}

void func_020885fc(void) {
    if (func_0208858c(3) != 0) {
        return;
    }
    func_0208853c(3);
    LoadResource(3);
}

void func_02088624(void) {
    func_020884f8(3);
}

void func_02088634(void) {
    if (func_0208858c(4) != 0) {
        return;
    }
    func_0208853c(4);
    LoadResource(4);
}

void func_0208865c(void) {
    if (func_0208858c(5) != 0) {
        return;
    }
    func_0208853c(5);
    LoadResource(5);
}

void func_02088684(void) {
    if (func_0208858c(6) != 0) {
        return;
    }
    func_0208853c(6);
    LoadResource(6);
}

void func_020886ac(void) {
    if (func_0208858c(7) != 0) {
        return;
    }
    func_0208853c(7);
    LoadResource(7);
}

void func_020886d4(void) {
    if (func_0208858c(9) != 0) {
        return;
    }
    func_0208853c(9);
    LoadResource(9);
}

void func_020886fc(void) {
    if (func_0208858c(0xA) != 0) {
        return;
    }
    func_0208853c(0xA);
    LoadResource(0xA);
}

void func_02088724(void) {
    if (func_0208858c(1) != 0) {
        return;
    }
    func_0208853c(1);
    LoadResource(1);
}

void func_0208874c(void) {
    if (func_0208858c(0xB) != 0) {
        return;
    }
    func_0208853c(0xB);
    LoadResource(0xB);
}

#pragma optimization_level 4
void func_02088774(s32 a){void CopyU16(void *,s32,s32);extern u8 data_021577c0[];extern void *gCur3DSpriteEngine;s32 base=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30);s32 offset=(a<<5)&~1;CopyU16(data_021577c0,offset+base,32);}
#pragma optimization_level reset
void func_020887a8(void *p,s32 a,s32 b,s32 c,s32 d){void func_020887ec(void *);s32 x=M2C_FIELD(p,s16 *,0x34),y=M2C_FIELD(p,s16 *,0x36),z=M2C_FIELD(p,s8 *,0x49),w=M2C_FIELD(p,s32 *,0x44);M2C_FIELD(p,s16 *,0x34)=a;M2C_FIELD(p,s16 *,0x36)=b;M2C_FIELD(p,s8 *,0x49)=c;M2C_FIELD(p,s32 *,0x44)=d;func_020887ec(p);M2C_FIELD(p,s16 *,0x34)=x;M2C_FIELD(p,s16 *,0x36)=y;M2C_FIELD(p,s8 *,0x49)=z;M2C_FIELD(p,s32 *,0x44)=w;}

void func_020887ec(void *p){
s32 func_01ff8f90(s32,s32,s32);void AddSprite(u16,u16,u16,s32,s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;
void *saved,*bank; s32 i;u32 mode,flags;u16 x,y,attr,pal;u32 shift,tile,part;
if(M2C_FIELD(p,s32 *,0x44)==0)return;
if((M2C_FIELD(p,u32 *,0x40)>>26)==0)return;
if(((u32)(M2C_FIELD(p,u8 *,0x48)<<31)>>31)==0)return;
if(!func_01ff8f90(M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38),M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a),M2C_FIELD(p,s32 *,0x44)))return;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==g3DSpriteEngineMain)&&(mode!=1||bank==g3DSpriteEngineSub)&&(mode!=3||bank==saved)){
shift=(u32)(M2C_FIELD(M2C_FIELD(bank,void **,0),u16 *,0)<<17)>>30;
flags=M2C_FIELD(p,u32 *,0x40);
tile=M2C_FIELD(p,u16 *,0x3e);
pal=(u16)((flags<<6)>>24);
part=(tile>>shift)&0x3ff;
part|=(u16)(pal<<12);
attr=(u16)(part|M2C_FIELD(p,u16 *,0x3c));

y=(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255;
if((flags>>26)!=16)y|=0x400;
AddSprite((u16)((M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&0x1ff),y,attr,M2C_FIELD(p,s32 *,0x44),M2C_FIELD(p,s8 *,0x49));
}}gCur3DSpriteEngine=saved;
}

void func_02088964(void *arg0) {
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
    u16 *volatile flags10;
    void *previousEngine;
    void *engine;
    void *chosen;
    s32 visibility;
    u32 field40;
    int i;
    s32 top2;
    s32 category;

    top2 = (s32)(((u32)(unsigned char)M2C_FIELD(arg0, u8 *, 0x48) << 26) >> 30);
    if (top2 == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x4b) == 0 && top2 == 1) {
        Show3DSprite(arg0);
        M2C_FIELD(arg0, u8 *, 0x4b) = (u8)(M2C_FIELD(arg0, u8 *, 0x4b) + 1);
        visibility = EaseInterpolate(4, 0, 0x10, M2C_FIELD(arg0, u8 *, 0x4b), M2C_FIELD(arg0, u8 *, 0x4a));
        field40 = M2C_FIELD(arg0, u32 *, 0x40);
        field40 = (field40 & ~0xFC000000U) | ((u32)visibility << 26);
        M2C_FIELD(arg0, u32 *, 0x40) = field40;
        if (top2 == 2) {
            field40 = M2C_FIELD(arg0, u32 *, 0x40);
            field40 = (field40 & ~0xFC000000U) | ((16U - (field40 >> 26)) << 26);
            M2C_FIELD(arg0, u32 *, 0x40) = field40;
        }
    }

    previousEngine = gCur3DSpriteEngine;
    category = (s32)(((u32)(unsigned char)M2C_FIELD(arg0, u8 *, 0x48) << 28) >> 29);

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            chosen = g3DSpriteEngineMain;
        } else {
            chosen = g3DSpriteEngineSub;
        }
        if (category == 0 && chosen != g3DSpriteEngineMain) {
            continue;
        }
        if (category == 1 && chosen != g3DSpriteEngineSub) {
            continue;
        }
        if (category == 3 && chosen != previousEngine) {
            continue;
        }

        gCur3DSpriteEngine = chosen;
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

        engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        flags10 = (u16 *)((u8 *)engine + 0x12);
        *flags10 = (u16)((*flags10 & ~0xC0) | 0x40);

        {
            int top6;
            top6 = (int)(M2C_FIELD(arg0, u32 *, 0x40) >> 26);
            engine = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
            M2C_FIELD(engine, u8 *, 0x51) = (u8)top6;
            M2C_FIELD(engine, u8 *, 0x52) = (u8)(16 - top6);
        }
    }

    gCur3DSpriteEngine = previousEngine;
    if ((u8)M2C_FIELD(arg0, u8 *, 0x4b) < (u8)M2C_FIELD(arg0, u8 *, 0x4a)) {
        return;
    }
    if (top2 == 2) {
        Hide3DSprite(arg0);
        M2C_FIELD(arg0, u8 *, 0x48) = (u8)(M2C_FIELD(arg0, u8 *, 0x48) & ~0x30);
    }
}

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

void func_02088db8(void *p,s32 a){void Show3DSprite(void *);if(!a){Show3DSprite(p);M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0xfc000000)|0x40000000;M2C_FIELD(p,u8 *,0x48)&=~0x30;return;}M2C_FIELD(p,u8 *,0x4b)=0;M2C_FIELD(p,u8 *,0x4a)=a;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0x30)|0x10;}

void func_02088e0c(void *p,s32 a){void Hide3DSprite(void *);if(!a){Hide3DSprite(p);M2C_FIELD(p,u32 *,0x40)&=~0xfc000000;M2C_FIELD(p,u8 *,0x48)&=~0x30;return;}M2C_FIELD(p,u8 *,0x4b)=0;M2C_FIELD(p,u8 *,0x4a)=a;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0x30)|0x20;}

void func_02088e5c(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x50) = arg1;
    M2C_FIELD(arg0, s16 *, 0x52) = arg2;
}

void func_02088e68(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4E) = arg1;
}

void func_02088e70(void *arg0, s16 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
    M2C_FIELD(arg0, s16 *, 0x56) = arg2;
}

void func_02088e7c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4F) = arg1;
}

void func_02088e84(void *p,s16 a,s16 b,s16 c,s32 d){func_02088e5c(p,a,b);func_02088e70(p,c,d);}

void Slide3DSpriteIn(void *p,s16 a,s32 b,s32 c,s32 d,s32 e){void func_02088f1c(void *);func_02088e5c(p,c,d);func_02088e70(p,a,b);func_02088e68(p,e);func_02088f1c(p);}

void func_02088eec(void *p,s8 a){void func_02088f1c(void *);func_02088e5c(p,M2C_FIELD(p,s16 *,0x50),M2C_FIELD(p,s16 *,0x52));func_02088e68(p,a);func_02088f1c(p);}

void func_02088f1c(void *p){if(!M2C_FIELD(p,u8 *,0x4e)){M2C_FIELD(p,s16 *,0x34)=M2C_FIELD(p,s16 *,0x50);M2C_FIELD(p,s16 *,0x36)=M2C_FIELD(p,s16 *,0x52);M2C_FIELD(p,s8 *,0x4d)=0;M2C_FIELD(p,u8 *,0x48)&=~0xc0;Show3DSprite(p);return;}if(((u32)(M2C_FIELD(p,u8 *,0x48)<<24)>>30)==2)return;M2C_FIELD(p,s8 *,0x4c)=0;M2C_FIELD(p,s8 *,0x4d)=0;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0xc0)|0x80;}

void func_02088f8c(void *p,s32 a,s32 b,s16 c,s32 d,s32 e){void Hide3DSpriteSlide(void *);func_02088e5c(p,a,b);func_02088e70(p,c,d);func_02088e7c(p,e);Hide3DSpriteSlide(p);}

void func_02088fc4(void *p,s8 a){void Hide3DSpriteSlide(void *);func_02088e70(p,M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x56));func_02088e7c(p,a);Hide3DSpriteSlide(p);}

