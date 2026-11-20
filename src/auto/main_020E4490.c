/* 22 functions from 0x020E4490 to 0x020E5080 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"

typedef struct {
    u16 unused : 4;
    u16 slot : 3;
} SaveSlotBits;

typedef struct { u32 words[64]; } SaveProgressWords;
typedef struct { u8 bytes[8]; } SaveProgressFlags;

typedef struct { u8 pixels[32]; } Unk020ETile;
typedef struct { u8 count; u8 pad[3]; s32 ptr; } Unk02168Fec;
u16 *func_020e4c10(u16 *,u16 *,u16 *,u32);
extern s32 gMicTestIpc;

#pragma opt_common_subs off
void func_020e4490(void) {
    M2C_UNK func_020e4378();
    M2C_UNK func_02082058();
    M2C_UNK func_02081724();
    M2C_UNK func_02081a48();
    M2C_UNK func_02082d08();
    M2C_UNK func_02082b78();
    M2C_UNK func_02082cb4();
    M2C_UNK func_02082078();
    M2C_UNK func_020e31f0();
    M2C_UNK Reset3DSpriteOam();
    M2C_UNK func_0208232c();
    M2C_UNK func_0209daec();
    M2C_UNK func_020e3448();
    M2C_UNK func_02080bd4();
    M2C_UNK func_020883bc();
    M2C_UNK func_02086574();
    M2C_UNK InitSound();
    M2C_UNK Init3DSpritePool();
    M2C_UNK func_020e4458();
    M2C_UNK func_0200ee70();
    M2C_UNK SeedRandomFromRtc();
    M2C_UNK SaveManager_Start();
    void ResetGameState(void);
    M2C_UNK func_020e349c();
    extern s32 data_027e15bc;
    extern s32 data_027e15c0;
    extern u8 data_027e15b4;
    extern u8 data_027e15b8;
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 temp_r7;
    s32 var_r8;

    data_027e15bc = 0;
    data_027e15c0 = 0;
    data_027e15b4 = 0;
    data_027e15b8 = 0;
    func_020e4378();
    func_02082058();
    func_02081724();
    func_02081a48();
    func_02082d08();
    func_02082b78();
    func_02082cb4();
    func_02082078();
    func_020e31f0();
    temp_r7 = gCur3DSpriteEngine;
    var_r8 = 0;
    do {
        if (var_r8 == 0) {
            gCur3DSpriteEngine = data_027e00c8;
        } else {
            gCur3DSpriteEngine = data_027e00c4;
        }
        Reset3DSpriteOam();
        func_0208232c();
        var_r8 += 1;
    } while (var_r8 < 2);
    gCur3DSpriteEngine = temp_r7;
    func_0209daec();
    func_020e3448();
    func_02080bd4();
    func_020883bc();
    func_02086574();
    InitSound();
    Init3DSpritePool();
    func_020e4458();
    func_0200ee70();
    SeedRandomFromRtc();
    SaveManager_Start();
    ResetGameState();
    func_020e349c();
}
#pragma opt_common_subs reset
void func_020e4570(void) {
    M2C_UNK GX_TurnOnDisplay();
    M2C_UNK func_02007598();
    func_02007598();
    GX_TurnOnDisplay();
    *(s32 *)0x04001000 |= 0x10000;
}

/* NNS/NitroSDK main loop body, run once per frame by main(): wait for the game
 * frame to be ready, run the input, sound and 3D-sprite updates for every
 * sprite layer, then let the pending frame callback (VBlank) run. */
void NitroMain(void) {
extern u8 data_027e15b4;
extern s32 gFrameCounter;
extern void (*data_02168fe8)(void);
void func_0208f4d8(void);
void func_0208184c(void);
void UpdateTouchInput(void);
void func_02090390(void);
void func_02081ee4(void);
void func_02091bf4(void);
void UpdateSpriteSlots(void);
void DrawSpriteSlots(void);
void func_0209db48(void);
void SoundEngineUpdateTimers(void);
void GetSpriteLayerHead(int);
void Update3DSpriteObject(void);
void func_02004e60(int,int);
if (!data_027e15b4) return;
data_02168fe8=0;
func_0208f4d8();
gFrameCounter++;
func_0208184c(); UpdateTouchInput(); func_02090390(); func_02081ee4();
GetSpriteLayerHead(3);Update3DSpriteObject();
GetSpriteLayerHead(4);Update3DSpriteObject();
GetSpriteLayerHead(5);Update3DSpriteObject();
GetSpriteLayerHead(6);Update3DSpriteObject();
GetSpriteLayerHead(7);Update3DSpriteObject();
GetSpriteLayerHead(8);Update3DSpriteObject();
func_02091bf4();UpdateSpriteSlots();DrawSpriteSlots();
GetSpriteLayerHead(9);Update3DSpriteObject();
GetSpriteLayerHead(10);Update3DSpriteObject();
func_0209db48();
if(data_02168fe8) data_02168fe8();
data_027e15b4=0;
SoundEngineUpdateTimers();
func_02004e60(1,1);
}

void func_020e4688(void) {
    void Upload3DSpriteOam(void);
    void func_01ff87e4(void);
    M2C_UNK Apply3DSpriteBanks();
    void Update3DSpriteVram(void);
    void GetSpriteLayerHead(int);
    void Update3DSpriteObject(void);
    void func_0200d248(void *);
    void func_0200d288(void *);
    extern int gOsArea;
    extern unsigned char data_027e15b4;
    extern unsigned char data_027e15b8;
    extern int data_027e15c0;
    int sp0[7];

    volatile int *counter = &data_027e15c0;
    func_0200d248(sp0);
    (*(volatile unsigned char *)&data_027e15b8) = 1;
    ++*counter;
    if ((*(volatile unsigned char *)&data_027e15b4) == 0) {
        GetSpriteLayerHead(0);
        Update3DSpriteObject();
    }
    GetSpriteLayerHead(1);
    Update3DSpriteObject();
    if ((*(volatile unsigned char *)&data_027e15b4) == 0) {
        GetSpriteLayerHead(2);
        Update3DSpriteObject();
        Apply3DSpriteBanks();
        Update3DSpriteVram();
        Upload3DSpriteOam();
        (*(volatile unsigned char *)&data_027e15b4) = 1;
    } else {
        func_01ff87e4();
    }
    (*(volatile unsigned char *)&data_027e15b8) = 0;
    M2C_FIELD(&gOsArea, s32 *, 0x3FF8) = (M2C_FIELD(&gOsArea, s32 *, 0x3FF8) | 1);
    func_0200d288(sp0);
    while (*(volatile unsigned short *)0x04000280 & 0x8000) {
    }
}

/* Resets everything a fresh game session needs before the title screen: the
 * default settings and dialog state, the sprite slot and text tables, the
 * campaign map headers, and both 3D sprite engines (each is put back into
 * graphics display mode and its bank flushed to the hardware).  Afterwards the
 * map's buffers, graphics files and config are set up again. */
void ResetGameState(void) {
    M2C_UNK Apply3DSpriteBanks();
    M2C_UNK func_0207b800();
    M2C_UNK ResetTextLabelSlots();
    M2C_UNK func_020834c4();
    M2C_UNK ResetDialogUI();
    M2C_UNK func_020960b4();
    M2C_UNK func_0209f87c();
    M2C_UNK func_020abf94();
    M2C_UNK ApplyScreenMode(M2C_UNK);
    M2C_UNK ResetSpriteSlots();
    M2C_UNK InitDefaultGameSettings();
    M2C_UNK ClearCampaignMapHeaders();
    M2C_UNK func_020d3cec();
    M2C_UNK func_ov000_02169368();
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;
    s32 engine;
    s32 screen;

    InitDefaultGameSettings();
    ResetDialogUI();
    ResetSpriteSlots();
    func_020834c4();
    ResetTextLabelSlots();
    ClearCampaignMapHeaders();
    func_020abf94();
    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        ApplyScreenMode(DS3D_DISPLAY_GRAPHICS);
        Apply3DSpriteBanks();
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
    func_0207b800();
    func_020d3cec();
    func_0209f87c();
    func_ov000_02169368();
    func_020960b4();
}

void func_020e47f8(void) {
    void func_020e4818(s32);
    s32 var_r4;

    var_r4 = 0;
    do {
        func_020e4818(var_r4);
        var_r4 += 1;
    } while (var_r4 < 3);
}

void func_020e4818(s32 a){
extern u8 data_0215dba4[];
u32 *p=(u32 *)(data_0215dba4+a*0x118);
p[0]&=~15;
p[0]&=~240;
p[1]&=0xffff0000;
p[1]=(u16)p[1];
p[0]&=~0xff00;
p[0]&=~0xff0000;
p[0]&=~0xff000000;

}

#pragma peephole off
void func_020e4870(s32 arg0) {
    extern M2C_UNK data_0215d9b8;
    extern M2C_UNK gSaveSlotSummary;
    extern void **gCurrentMap;
    extern u8 data_0215dba4[];
    extern u8 data_0215dbac[];
    extern M2C_UNK data_0215d8a8;
    extern u8 data_0215dcac[];
    extern M2C_UNK gEventFlagsHigh;
    extern u8 data_0215dcb4[];
    extern M2C_UNK gEventValues;

    SaveSlotBits *slot = (SaveSlotBits *)((u8 *)&data_0215d9b8 + 6);
    u32 *summary = (u32 *)&gSaveSlotSummary;
    u16 slotFlags = *(u16 *)slot;
    u32 word = summary[0];
    void ***mapBase = &gCurrentMap;
    void **map;
    u32 location;
    s32 count;
    s32 offset;
    u32 *dest;

    *(u16 *)slot = (((u32)(u16)arg0 << 29) >> 25) | (slotFlags & ~0x70);
    word = (word & ~0xf) | (arg0 & 0xf);
    summary[0] = word;

    map = *mapBase;
    location = summary[1];
    location = (location & 0xffff0000) | (u16)(M2C_FIELD(map[0], u16 *, MAP_ID) - 0xa1);
    summary[1] = location;
    {
        u16 turn = M2C_FIELD(map[0], u16 *, MAP_TURN);
        count = (u32)(word << 16) >> 24;
        summary[1] = ((u32)turn << 16) | (u16)location;
    }

    if (count < 0xff)
        count++;
    word = summary[0];
    word = (word & ~0xff00) | (((u32)count << 24) >> 16);
    summary[0] = word;
    offset = arg0 * 0x118;
    dest = (u32 *)(data_0215dba4 + offset);
    dest[0] = word;
    dest[1] = summary[1];
    *(SaveProgressWords *)(data_0215dbac + offset) = *(SaveProgressWords *)&data_0215d8a8;
    *(SaveProgressFlags *)(data_0215dcac + offset) = *(SaveProgressFlags *)&gEventFlagsHigh;
    *(SaveProgressFlags *)(data_0215dcb4 + offset) = *(SaveProgressFlags *)&gEventValues;
}
#pragma peephole reset
void func_020e49ec(void) {
    M2C_UNK func_02086ae4(s32, M2C_UNK);
    M2C_UNK func_0209c7fc();
    s32 var_r5;

    func_0209c7fc();
    var_r5 = 0x60;
    do {
        func_02086ae4(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0xA0);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
/* Loads save slot `slot` from the newest campaign save record and copies its
 * fields into the live progress globals: the slot summary, the per-map progress
 * records, the high event flags and value bytes, and the three map-slot entries. */
void LoadSaveSlotProgress(s32 slot)
{
  s32 GetSaveRecordBuffer(void);
  s32 LoadNewestSaveRecord(s32, s32);
  extern M2C_UNK gSaveSlotSummary;
  extern M2C_UNK data_0215d8a8;
  extern M2C_UNK gEventFlagsHigh;
  extern M2C_UNK gEventValues;
  extern M2C_UNK data_0215d9b8;
  s32 saveBuffer;
  s32 offset;
  s32 *slotRecord;
  s32 i;
  saveBuffer = GetSaveRecordBuffer();
  if (LoadNewestSaveRecord(4, saveBuffer) == 0)
  {
    return;
  }
  offset = slot * 0x118;
  slotRecord = (s32 *) (saveBuffer + offset);
  {
    u32 word0 = ((volatile u32 *) slotRecord)[0x284 / 4];
    u32 word1 = ((volatile u32 *) slotRecord)[0x288 / 4];
    ((volatile u32 *) (&gSaveSlotSummary))[0] = word0;
    ((volatile u32 *) (&gSaveSlotSummary))[1] = word1;
  }
  *((SaveProgressWords *) (&data_0215d8a8)) = *((SaveProgressWords *) (((u8 *) slotRecord) + 0x28c));
  *((SaveProgressFlags *) (&gEventFlagsHigh)) = *((SaveProgressFlags *) (((u8 *) (saveBuffer + offset)) + 0x38c));
  *((SaveProgressFlags *) (&gEventValues)) = *((SaveProgressFlags *) (((u8 *) (saveBuffer + offset)) + 0x394));
  for (i = 0; i < 3; i++)
  {
    u8 *entry = ((u8 *) saveBuffer) + (i * 8);
    u16 first = *((u16 *) (entry + 0xcc));
    *((u16 *) ((((u8 *) (&data_0215d9b8)) + (i * 8)) + 0x34)) = first;
    *((u16 *) ((((u8 *) (&data_0215d9b8)) + (i * 8)) + 0x36)) = *((u16 *) (entry + 0xce));
    *((s32 *) ((((u8 *) (&data_0215d9b8)) + (i * 8)) + 0x38)) = *((s32 *) (entry + 0xd0));
  }
}
#pragma pop
void func_020e4b24(void) {

}

u8 func_020e4b28(s32 a){extern u8 data_0215dba4[];return ((u32)(M2C_FIELD(data_0215dba4,u32 *,a*0x118)<<16)>>24)!=0;}

s32 func_020e4b54(void) {
    extern u16 gMapConfig;
    extern void **gCurrentMap;
    if (!(((u32) (gMapConfig << 0x1D) >> 0x1D) & 0xFF) && (M2C_FIELD(*gCurrentMap, u16 *, 0x5142) == 0xBA)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
s32 func_020e4b9c(u16 key,...){extern u16 data_0212da1c;extern u16 data_020f4eb4[];volatile u8 a=0;volatile u8 b=0;u16 *p=func_020e4c10(data_020f4eb4,data_020f4eb4+data_0212da1c,&key,*(u32 *)&b);if(*p!=key)return 0;return p-data_020f4eb4;}
#pragma pop
u16 *func_020e4c10(u16 *first,u16 *last,u16 *key,u32 unused){
s32 n=last-first;
while(n>0){
s32 half=n/2;
u16 *p=first+half;
if(*p<*key){
half++;
first=p+1;
n-=half;
}else n=half;
}
return first;
}
#pragma opt_propagation reset
void func_020e4c64(void) {
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212da20;
    extern M2C_UNK data_02168fec;
    u8 temp_r2;

    temp_r2 = M2C_FIELD(&data_02168fec, u8 *, 0);
    M2C_FIELD(&data_02168fec, u8 *, 0) = (u8) (temp_r2 + 1);
    if (temp_r2 != 0) {
        return;
    }
    M2C_FIELD(&data_02168fec, s32 *, 4) = func_02081070(&data_0212da20, 1);
}

void func_020e4ca0(void) {M2C_UNK HeapFreeBlock(s32);extern M2C_UNK data_02168fec;u32 n=M2C_FIELD(&data_02168fec,u8 *,0)-1;M2C_FIELD(&data_02168fec,u8 *,0)=n;if(n&255)return;HeapFreeBlock(M2C_FIELD(&data_02168fec,s32 *,4));M2C_FIELD(&data_02168fec,s32 *,4)=0;}

void DrawGlyphString(u16 *keys,u32 dst,u32 map,u32 pal,u16 x,u16 y,u32 tileArg) {M2C_UNK MI_CpuCopy32();extern M2C_UNK data_02168fec;u16 *p;u32 bits;u32 i;u32 next,next2,cur;u32 source;if(!*keys)return;bits=pal<<28;{u32 offset=y<<5;p=(u16 *)(map+((x+offset)*2));}i=0;do {s32 index=func_020e4b9c(*keys);source=M2C_FIELD(&data_02168fec,u32 *,4)+index*128;MI_CpuCopy32(source,dst+((tileArg&0x7ffffffU)<<5),128);next=(tileArg+1)|(bits>>16);next2=(tileArg+2)|(bits>>16);cur=tileArg|(bits>>16);p[i]=cur;p[i+1]=next;p[i+32]=next2;p[i+33]=(tileArg+3)|(bits>>16);keys++;tileArg+=4;i+=2;}while(*keys);}

void func_020e4d80(void *arg0) {
    void Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK MenuSpriteUpdate(void *);
    extern u16 *gKeyState;

    register u16 var_r3;
    register void *temp_r2;
    register void *temp_r1;
    s8 var_r0;
    u8 var_r12;
    void *temp_r0;

    MenuSpriteUpdate(M2C_FIELD(arg0, void **, 0x38));
    var_r3 = *gKeyState;
    temp_r2 = M2C_FIELD(arg0, void **, 0x38);
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x64);
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xb);
    var_r12 = 1;
    if (var_r0 != 1) {
        if (((u32) (M2C_FIELD(temp_r2, u8 *, 0x59) << 0x1b) >> 0x1f) != 0) {
            var_r0 = M2C_FIELD(temp_r1, s8 *, 0xc);
            if (var_r0 == 1) goto check;
        }
        var_r12 = 0;
    }
check:
    if (!(var_r12 & 0xff) && !(var_r3 & 0x2)) {
        return;
    }
    PlaySoundEffect(0x1000f);
    temp_r0 = M2C_FIELD(arg0, void **, 0x38);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5a) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5a) = 0xc;
    }
    Sprite_ResumeAnimation(arg0);
}

#pragma scheduling off
s32 func_020e4e44(void *arg0) {
 s16 count=M2C_FIELD(arg0,s16 *,0x3e);
 s32 done;
 if(count>0)M2C_FIELD(arg0,s16 *,0x3e)=count-1;
 if(M2C_FIELD(arg0,s16 *,0x3e)==0)done=1;else done=0;
 if(!(done&255))return 0;
 M2C_FIELD(arg0,u8 *,0x3c) &= ~2;
 M2C_FIELD(arg0,u8 *,0x3c) |= 1;
 return 1;
}
#pragma scheduling reset
void func_020e4e8c(void *arg0) {
    M2C_UNK func_0200dedc(M2C_UNK *);
    extern M2C_UNK data_02168ff8;
    func_0200dedc(&data_02168ff8);
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) (M2C_FIELD(arg0, u8 *, 0x3C) | 2);
}

#pragma scheduling off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_020e4eb0(void *arg0) {
    void DC_InvalidateRange(void *, s32);
    s32 Divide(s32, s32);
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 gMicTestIpc;
    extern u8 gSpriteDesc32x32[];

    u8 cond;
    u8 idx;
    s32 nidx;
    u8 *r3p;
    u8 *r2p;
    s32 saved;
    u8 *arr;
    u8 b;
    u32 i;
    u32 maxv;
    u8 t;
    s32 tier;
    u32 sum;
    u8 *p;
    s32 divres;
    register s32 mask;
    register s32 *enginePtr;
    register s32 kind, scale, r8v, r9v, r10, fullmask;
    u16 a0;
    u16 **eng;
    u16 *base;
    u32 sh;
    u16 arg2;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    cond = (*(volatile s16 *)((char *)arg0 + 0x3e) == 0);
    if (!cond) goto skip_all;

    arr = (u8 *)gMicTestIpc;
    DC_InvalidateRange(arr, 0x20);

    maxv = 0;
    i = 0;
    do {
        b = arr[i];
        if (b >= 0x15 && b <= 0xea) {
            t = b;
            if (b < 0x80) {
                t = (u8)(0x100 - b);
            }
            if (maxv < t) {
                maxv = t;
            }
        }
        i = i + 1;
    } while (i < 0x20);

    if (maxv > 0xd0) tier = 4;
    else if (maxv > 0xbb) tier = 3;
    else if (maxv > 0xa3) tier = 2;
    else if (maxv > 0x8d) tier = 1;
    else tier = 0;

    idx = ((u8 *)arg0)[0x40];
    r3p = (u8 *)arg0 + 0x41;
    r2p = (u8 *)arg0 + 0x4b;
    ((u8 *)arg0 + idx)[0x41] = (u8)tier;

    idx = ((u8 *)arg0)[0x40];
    nidx = idx + 1;
    if ((u8)(((u8 *)arg0)[0x40] = nidx) >= 0x0a) {
        ((u8 *)arg0)[0x40] = 0;
    }

    sum = 0;
    p = r3p;
    if (p != r2p) {
        do {
            sum += *p;
            p++;
        } while (p != r2p);
    }

    divres = Divide(sum, 10);
    r10 = divres;
    if (r10 > 3) {
        r10 = 3;
    } else if (r10 < 0) {
        r10 = 0;
    }

    r8v = 0x50;
    r9v = 0;
    if (r10 > 0) {
        fullmask = 0x3ff;
        enginePtr = &gCur3DSpriteEngine;
        scale = 0x140;
        mask = fullmask - 0x200;
        kind = 0x11;
        do {
            eng = (u16 **)*enginePtr;
            a0 = (u16)(r8v & mask);
            base = eng[0];
            sh = ((u32)base[0] << 17) >> 30;
            arg2 = (u16)((fullmask & (scale >> sh)) | 0x6000);
            AddSprite(a0, 0x28, arg2, (s32)gSpriteDesc32x32, kind);

            r9v = (r9v + 1) & 0xff;
            r8v = (s16)(r8v + 0x20);
        } while (r9v < r10);
    }

skip_all:
    gCur3DSpriteEngine = saved;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma scheduling reset
