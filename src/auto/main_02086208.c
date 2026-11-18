/* 57 functions from 0x02086208 to 0x020871A8 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct { s32 x,y,z; } Vec02086dfc;
extern const Vec02086dfc data_020f3578, data_020f3584;
extern void (*data_02168fe8)(void);
extern u8 data_02157718[4];

/* Push-to-talk voice-chat widget (same fields as the definition in main_020852F4). */
typedef struct VoiceChatWidget {
    u8  filler_00[0x34];
    s16 x;               /* +0x34 */
    s16 y;               /* +0x36 */
    s32 enabled;         /* +0x38 nonzero while the widget is shown */
    s32 initialized;     /* +0x3C set on the first update */
    s32 lastVoice;       /* +0x40 last voice-data-ready value seen */
    u8  filler_44[4];
    s32 talkHeld;        /* +0x48 Y button was held last update */
    u8  filler_4c[2];
    s16 refreshTimer;    /* +0x4E cooldown before the fade may be re-targeted */
    SpriteTween *anim;   /* +0x50 volume fade */
} VoiceChatWidget;

/* Create the push-to-talk voice-chat widget on the sub engine while the ov010
 * overlay is active: place it, enable it from the local player's status and set
 * up its volume fade in the neutral (127) position. */
void CreateVoiceChatWidget(s32 mode){
void *FindObjectByClass(M2C_UNK *);s16 Divide(s32,s32);s32 CreateSpriteFromClass(M2C_UNK *,s32);void *GetLocalPlayerStatus(void);void *MemAlloc(s32);
extern M2C_UNK gVoiceChatWidgetClass,gVoiceChatWidgetVtbl;extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub;
s32 saved;VoiceChatWidget *p;SpriteTween *q;
if(GetActiveOverlay()!=2)return;
if(FindObjectByClass(&gVoiceChatWidgetClass))return;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
p=(VoiceChatWidget *)CreateSpriteFromClass(&gVoiceChatWidgetClass,mode);
if(p){
M2C_FIELD(p,void **,0)=&gVoiceChatWidgetVtbl;
p->x=0xde;p->y=1;
p->enabled=M2C_FIELD(GetLocalPlayerStatus(),u8 *,0x1a)&4;
p->initialized=0;p->lastVoice=0;M2C_FIELD(p,s32 *,0x44)=0;p->talkHeld=0;
M2C_FIELD(p,u8 *,0x4c)=0;M2C_FIELD(p,u8 *,0x4d)=0;
p->refreshTimer=Divide(0x2bf20,1000);
q=(SpriteTween *)MemAlloc(18);
if(q){
q->mode=1;q->done=0;
q->current=0;q->start=0;q->step=1;q->base=0;q->amplitude=1;q->duration=1;q->from=0;q->to=0;
M2C_FIELD(q,u16 *,2)=M2C_FIELD(q,volatile u16 *,4);
}
p->anim=q;
q->from=127;q->to=127;q->duration=0;q->current=q->start;
}
gCur3DSpriteEngine=saved;
}

void func_02086330(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    DeleteSpriteObjectsOfClass(&gVoiceChatWidgetClass);
}

void func_02086344(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0xEF;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 0x12;
}

void func_02086370(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0xDE;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 1;
}

void func_0208639c(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK func_02091cd0(void *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(temp_r0, u8 *, 0x4C) = 1;
    M2C_FIELD(temp_r0, u8 *, 0x4D) = 0;
    func_02091cd0(temp_r0);
}

void func_020863cc(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s8 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x4D) = 0;
    }
}

void func_020863f0(void) {
    void *FindObjectByClass(M2C_UNK *);
    s16 Divide(s32, s32);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x4E) = Divide(0x2BF20, 0x3E8);
}

s32 func_02086420(M2C_UNK arg0) {
    s32 GetActiveOverlay();
    void *GetOnlinePlayerRecord(M2C_UNK);
    void *temp_r0;
    if (GetActiveOverlay() == 2) {
        temp_r0 = GetOnlinePlayerRecord(arg0);
        if (temp_r0 != NULL && M2C_FIELD(temp_r0, s8 *, 0x27) == 1 && M2C_FIELD(temp_r0, s8 *, 0x28) == 0) {
            if (M2C_FIELD(temp_r0, u8 *, 0x1A) & 4) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

void *func_02086478(void *arg0) {
    M2C_UNK MemFree();
    M2C_UNK func_02090640(M2C_UNK, M2C_UNK);
    M2C_UNK func_0209066c(M2C_UNK, M2C_UNK);
    extern M2C_UNK gVoiceChatWidgetVtbl;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &gVoiceChatWidgetVtbl;
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) {
        MemFree();
    }
    func_02090640(2, 0x7F);
    func_0209066c(2, 0x7F);
    MemFree(arg0);
    return arg0;
}

void *func_020864c4(void *arg0) {
    M2C_UNK MemFree();
    M2C_UNK func_02090640(M2C_UNK, M2C_UNK);
    M2C_UNK func_0209066c(M2C_UNK, M2C_UNK);
    extern M2C_UNK gVoiceChatWidgetVtbl;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &gVoiceChatWidgetVtbl;
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) {
        MemFree();
    }
    func_02090640(2, 0x7F);
    func_0209066c(2, 0x7F);
    return arg0;
}

void Init3DSpriteScene(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102210;
    CreateSpriteFromClass(&data_02102210, 7);
}

s32 func_02086520(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 39:
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
}

void func_02086574(void) {
    void func_020865a0(void);
    extern M2C_UNK gUiGraphicsBanks[];
    s32 i;
    i = 0;
    do {
        gUiGraphicsBanks[i] = 0;
        i = i + 1;
    } while (i < 0x28);
    func_020865a0();
}

void func_020865a0(void) {
    void LoadUiGraphicsBank(u8);
    void FreeUiGraphicsBank(u8);
    extern M2C_UNK gUiGraphicsBanks[];
    s32 var_r4;
    s32 var_r5;
    var_r5 = 0;
    do {
        if ((func_02086520((u8)var_r5) != 0) && (((s32 *)&gUiGraphicsBanks)[var_r5] != 0)) {
            FreeUiGraphicsBank((u8)var_r5);
        }
        var_r5 += 1;
    } while (var_r5 < 0x28);
    var_r4 = 0;
    do {
        if (func_02086520((u8)var_r4) != 0) {
            LoadUiGraphicsBank((u8)var_r4);
        }
        var_r4 += 1;
    } while (var_r4 < 0x28);
}

void LoadUiGraphicsBank(u8 arg0) {
 s32 GetLocalizedFileName(s32);
 void StringFormat(void *, void *, s32);
 s32 func_02081070(void *, s32);
 extern M2C_UNK data_0210244c, data_02102250, gUiGraphicsBanks[];
 u8 sp0[0x20];
 StringFormat(sp0, &data_02102250, GetLocalizedFileName(M2C_FIELD(&data_0210244c, s32 *, arg0 * 8)));
 ((s32 *)&gUiGraphicsBanks)[arg0] = func_02081070(sp0, 1);
}

void FreeUiGraphicsBank(u8 arg0) {
 void HeapFreeBlock(s32);
 extern M2C_UNK gUiGraphicsBanks[];
 HeapFreeBlock(((s32 *)&gUiGraphicsBanks)[arg0]);
 ((s32 *)&gUiGraphicsBanks)[arg0] = 0;
}

s32 GetLocalizedText(u32 arg0) {
 extern u32 data_02102448;
 extern M2C_UNK gUiGraphicsBanks[];
 u32 *p = &data_02102448;
 if (arg0 == -1U) arg0 = GetUiMessageText();
 for (; p[1] != 0; p += 2) {
  if (arg0 >= p[0]) {
   s32 base = ((s32 *)&gUiGraphicsBanks)[((s32)p - (s32)&data_02102448) / 8];
   return base + ((s32 *)base)[arg0 & 0xFFFFFF];
  }
 }
 return 0;
}

s32 func_020866fc(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == -1) {
        var_r0 = GetUiMessageText();
    }
    if (var_r0 == 0) {
        return 0;
    }
    return 1;
}

void SetUiMessageText(s32 arg0) {
    extern s32 gUiMessageText;
    gUiMessageText = arg0;
}

s32 GetUiMessageText(void) {
    extern s32 gUiMessageText;
    return gUiMessageText;
}

void func_02086740(u32 arg0, s32 arg1) {
    extern M2C_UNK data_0215771c;
    s32 shift = arg0 & 7;
    s32 mask = 1 << shift;
    u8 byte = M2C_FIELD(&data_0215771c,u8 *,arg0 >> 3);
    M2C_FIELD(&data_0215771c,u8 *,arg0 >> 3) = (byte & ~mask) | (mask * arg1);
}

void func_02086774(u32 arg0, s32 arg1) {
 extern M2C_UNK data_02157724;
 s32 shift = arg0 & 7;
 M2C_FIELD(&data_02157724, u8 *, arg0 >> 3) = (M2C_FIELD(&data_02157724, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void func_020867a8(u32 arg0, s32 arg1) {
 extern M2C_UNK data_02157734;
 s32 shift = arg0 & 7;
 M2C_FIELD(&data_02157734, u8 *, arg0 >> 3) = (M2C_FIELD(&data_02157734, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void SetListRowFlag(u32 arg0, s32 arg1) {
 extern M2C_UNK gListRowFlags;
 s32 shift = arg0 & 7;
 M2C_FIELD(&gListRowFlags, u8 *, arg0 >> 3) = (M2C_FIELD(&gListRowFlags, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void SetMapListFlag(u32 arg0, s32 arg1) {
 extern M2C_UNK data_02157744;
 s32 shift = arg0 & 7;
 M2C_FIELD(&data_02157744, u8 *, arg0 >> 3) = (M2C_FIELD(&data_02157744, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void func_02086844(u32 arg0, s32 arg1) {
 extern M2C_UNK data_02157767;
 s32 shift = arg0 & 7;
 M2C_FIELD(&data_02157767, u8 *, arg0 >> 3) = (M2C_FIELD(&data_02157767, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void func_02086878(u32 arg0, s32 arg1) {
 extern M2C_UNK data_0215778a;
 s32 shift = arg0 & 7;
 M2C_FIELD(&data_0215778a, u8 *, arg0 >> 3) = (M2C_FIELD(&data_0215778a, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void func_020868ac(u32 arg0, s32 arg1) {
 extern M2C_UNK data_021577ad;
 s32 shift = arg0 & 7;
 M2C_FIELD(&data_021577ad, u8 *, arg0 >> 3) = (M2C_FIELD(&data_021577ad, u8 *, arg0 >> 3) & ~(1 << shift)) | ((1 << shift) * arg1);
}

void func_020868e0(u32 arg0, s32 arg1) {
    extern M2C_UNK data_0215d9a8;
    s32 shift;
    s32 mask;
    if (arg1 != 0) {
        shift = arg0 & 7;
        mask = 1 << shift;
        M2C_FIELD(&data_0215d9a8,u8 *,arg0 >> 3) |= mask;
    } else {
        shift = arg0 & 7;
        mask = -1 ^ (1 << shift);
        M2C_FIELD(&data_0215d9a8,u8 *,arg0 >> 3) &= mask;
    }
}

void func_02086930(s32 arg0, s8 arg1) {
    extern M2C_UNK data_0215d9b0;
    M2C_FIELD(&data_0215d9b0, s8 *, arg0) = arg1;
}

u8 func_02086940(u32 arg0) {
    extern M2C_UNK data_02157744;
    return (u8) (M2C_FIELD(&data_02157744, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 IsCampaignMapCleared(u32 arg0) {
    extern M2C_UNK data_0215778a;
    return (u8) (M2C_FIELD(&data_0215778a, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 func_02086980(u32 arg0) {
    extern M2C_UNK data_021577ad;
    return (u8) (M2C_FIELD(&data_021577ad, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

s32 func_020869a0(s32 arg0) {
    extern M2C_UNK data_0215d9a8;
    return (u8)(M2C_FIELD(&data_0215d9a8,u8 *, (u32)arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 func_020869c0(u32 arg0) {
    extern M2C_UNK data_02157724;
    return (u8) (M2C_FIELD(&data_02157724, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 func_020869e0(u32 arg0) {
    extern M2C_UNK data_02157734;
    return (u8) (M2C_FIELD(&data_02157734, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 IsListRowFlagSet(u32 arg0) {
    extern M2C_UNK gListRowFlags;
    return (u8) (M2C_FIELD(&gListRowFlags, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 func_02086a20(s32 arg0) {
    extern M2C_UNK data_0215d9b0;
    return M2C_FIELD(&data_0215d9b0, u8 *, arg0);
}

s32 func_02086a30(s32 arg0) {
    extern M2C_UNK data_0215771c;
    s32 shift = arg0 & 7;
    u8 value = M2C_FIELD(&data_0215771c,u8 *, (u32)arg0 >> 3);
    return (u8)(value & (1 << shift));
}

void func_02086a50(s32 arg0,s32 arg1) {
 s32 shift; s32 mask;
 if(arg1) {shift=arg0&7;mask=1<<shift;data_02157718[arg0>>3]|=mask;}
 else {shift=arg0&7;mask=-1^(1<<shift);data_02157718[arg0>>3]&=mask;}
}

s32 func_02086aa0(s32 arg0) {
 s32 shift=arg0&7;u8 value=data_02157718[arg0>>3];return (u8)(value&(1<<shift));
}

void func_02086ac0(void) {
 s32 i=0;u8 *p=data_02157718;u8 zero=i;
 do{i++;*p++=zero;}while(i<4);
}

M2C_UNK func_02086ae4(s32 arg0,s32 arg1) {
 if(arg0>=0&&arg0<0x20){func_02086a50(arg0,arg1);return;}
 if(arg0>=0x20&&arg0<0x60){func_02086740(arg0-0x20,(u8)arg1);return;}
 if(arg0<0x60)return;
 if(arg0>=0xA0)return;
 func_020868e0(arg0-0x60,(u8)arg1);
}

s32 func_02086b40(s32 arg0) {
    s32 func_020869a0(s32);
    s32 func_02086a30(s32);
    s32 func_02086aa0();
    if ((arg0 >= 0) && (arg0 < 0x20)) {
        return func_02086aa0();
    }
    if ((arg0 >= 0x20) && (arg0 < 0x60)) {
        return func_02086a30(arg0 - 0x20);
    }
    if ((arg0 >= 0x60) && (arg0 < 0xA0)) {
        return func_020869a0(arg0 - 0x60);
    }
    return 0;
}

/* Initializes/clears the bitfield/flag tables used by the main overlay. */
void func_02086b9c(void) {
    M2C_UNK func_02086ae4(s32, M2C_UNK);
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;

    var_r7 = 0;
    do {
        if ((var_r7 >= 0xA1) && (var_r7 < 0xE1)) {
            SetMapListFlag(var_r7, 0);
        } else {
            SetMapListFlag(var_r7, 1);
        }
        var_r7 += 1;
    } while (var_r7 < 0x113);
    var_r6 = 0;
    do {
        func_02086844(var_r6, 0);
        var_r6 += 1;
    } while (var_r6 < 0x113);
    var_r6_2 = 0;
    do {
        func_02086878(var_r6_2, 0);
        var_r6_2 += 1;
    } while (var_r6_2 < 0x113);
    var_r5 = 0;
    do {
        func_020868ac(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0x32);
    var_r5_2 = 0x20;
    do {
        func_02086ae4(var_r5_2, 0);
        var_r5_2 += 1;
    } while (var_r5_2 < 0x60);
    var_r5_3 = 0x60;
    do {
        func_02086ae4(var_r5_3, 0);
        var_r5_3 += 1;
    } while (var_r5_3 < 0xA0);
    var_r5_4 = 0;
    do {
        func_02086774(var_r5_4, 0);
        var_r5_4 += 1;
    } while (var_r5_4 < 0x80);
    var_r5_5 = 0;
    do {
        func_020867a8(var_r5_5, 0);
        var_r5_5 += 1;
    } while (var_r5_5 < 0x40);
    var_r5_6 = 0;
    do {
        SetListRowFlag(var_r5_6, 0);
        var_r5_6 += 1;
    } while (var_r5_6 < 0x40);
    var_r5_7 = 0;
    do {
        func_02086930(var_r5_7, 0);
        var_r5_7 += 1;
    } while (var_r5_7 < 8);
}

/* Prepare the 3D engine for a scene: clear the 3D display control's blend and error
 * status bits, enable the 3D display, use a blue clear colour and a full-screen
 * orthographic projection, then start a new projection matrix. */
void Init3DRendering(void) {
    M2C_UNK GX_SetClearColor(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK GX_SetOrthoProjection(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);

    REG_DISP3DCNT = (u16)(REG_DISP3DCNT & (u16)~(DISP3DCNT_ALPHA_BLEND | DISP3DCNT_ERROR_MASK));
    REG_GX_SWAP_BUFFERS = 1;
    GX_SetClearColor(0x2BEA, 0, GX_CLEAR_DEPTH_MAX, 0x3F, 0);
    *(s32 *)0x04000580 = 0xBFFF0000;
    GX_SetOrthoProjection(0, -0xC0, 0, 0x100, 1, 0x2000, 0x1000, 1, 0);
    REG_GX_MTX_STORE = 0;
    REG_GX_MTX_MODE = 2;
}

void func_02086dc8(void) {
    M2C_FIELD((void *)0x040004C8, s32 *, 0) = 0x1FF00000;
    M2C_FIELD((void *)0x040004C8, s32 *, 4) = 0x7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -8) = 0x7FFFFFFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -4) = 0x7FFF7FFF;
}

void func_02086dfc(void) {
 void func_02003bd0(void);
 void func_0200402c(Vec02086dfc *,Vec02086dfc *,Vec02086dfc *,s32,s32);
 Vec02086dfc a=data_020f3578;
 Vec02086dfc c={0,0,0};
 Vec02086dfc b=data_020f3584;
 func_02003bd0();func_0200402c(&a,&b,&c,1,0);func_02086dc8();
 *(volatile u32 *)0x04000444=0;*(volatile u32 *)0x04000440=3;
 *(volatile u32 *)0x04000454=0;*(volatile u32 *)0x04000440=2;
 *(volatile u32 *)0x04000484=0x20000000;
}

void func_02086e9c(void) {
    M2C_FIELD((void *)0x04000448, s32 *, 0) = 1;
    M2C_FIELD((void *)0x04000448, s32 *, 0xF8) = 1;
}

void func_02086eb4(void) {
    *(s32 *)0x04000540 = 1;
}

void func_02086ec8(void) {
 void func_02086eb4(void);
 *(volatile u32 *)0x04000448=1;data_02168fe8=func_02086eb4;
}

/* Maps a texture's side length in pixels (GX_TEX_SIZE_*) to the code the GX
 * TEXIMAGE_PARAM size field stores (GX_TEX_CODE_*).  Another copy of the same
 * helper as GetGxTextureSizeCode; the display-list writers below put the result
 * in the 3D sprite's texture-image attribute. */
s32 GetGxTextureSizeCode3(s32 size) {
    switch (size) {                                 /* irregular */
    case GX_TEX_SIZE_8:
        return GX_TEX_CODE_8;
    case GX_TEX_SIZE_16:
        return GX_TEX_CODE_16;
    case GX_TEX_SIZE_32:
        return GX_TEX_CODE_32;
    case GX_TEX_SIZE_64:
        return GX_TEX_CODE_64;
    case GX_TEX_SIZE_128:
        return GX_TEX_CODE_128;
    case GX_TEX_SIZE_256:
        return GX_TEX_CODE_256;
    case GX_TEX_SIZE_512:
        return GX_TEX_CODE_512;
    case GX_TEX_SIZE_1024:
        return GX_TEX_CODE_1024;
    default:
        return GX_TEX_CODE_8;
    }
}

/* Maps a square texture's size in pixels (8, 16, ... 1024) to its 3-bit GX
 * texture-size code (0..7); another copy of the helper, used here for the
 * 3D sprite's texture image attributes. */
s32 GetGxTextureSizeCode4(s32 size) {
    switch (size) {                                 /* irregular */
    case GX_TEX_SIZE_8:
        return GX_TEX_CODE_8;
    case GX_TEX_SIZE_16:
        return GX_TEX_CODE_16;
    case GX_TEX_SIZE_32:
        return GX_TEX_CODE_32;
    case GX_TEX_SIZE_64:
        return GX_TEX_CODE_64;
    case GX_TEX_SIZE_128:
        return GX_TEX_CODE_128;
    case GX_TEX_SIZE_256:
        return GX_TEX_CODE_256;
    case GX_TEX_SIZE_512:
        return GX_TEX_CODE_512;
    case GX_TEX_SIZE_1024:
        return GX_TEX_CODE_1024;
    default:
        return GX_TEX_CODE_8;
    }
}

void SetGxPolygonAttr(s32 arg0, s32 arg1) {
    *(s32 *)0x040004A4 = (arg0 << 0x18) | 0x81 | (arg1 << 0x10);
}

void func_02087064(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
 s32 temp_r5; s32 var_r0;
 temp_r5=GetGxTextureSizeCode4(arg2);
 *(volatile u32 *)0x040004A8=((u32)(arg3<<5)>>3)|(arg0<<26)|0x40000000|(GetGxTextureSizeCode3(arg1)<<20)|(temp_r5<<23)|0x20000000;
 var_r0=arg0==2?1:0;
 *(volatile u32 *)0x040004AC=(u32)(arg4<<5)>>(4-var_r0);
}

void func_020870dc(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,u8 arg5,u8 arg6,u8 arg7) {
 s32 temp_r0; s32 temp_r4; s32 var_r0; s32 var_r1; s32 var_r2; s32 var_r3;
 temp_r4=GetGxTextureSizeCode4(arg2);
 temp_r0=GetGxTextureSizeCode3(arg1);
 var_r1=arg5?3:0;var_r2=arg6?3:0;var_r3=arg7?1:0;
 *(volatile u32 *)0x040004A8=(((u32)(arg3<<5)>>3)|(arg0<<26)|0x40000000|(temp_r0<<20)|(temp_r4<<23))|(var_r1<<16)|(var_r2<<18)|(var_r3<<29);
 var_r0=arg0==2?1:0;
 *(volatile u32 *)0x040004AC=(u32)(arg4<<5)>>(4-var_r0);
}

void ResetGxTextureParams(void) {
    M2C_FIELD((void *)0x040004A8, s32 *, 0) = 0x20000000;
    M2C_FIELD((void *)0x040004A8, s32 *, 4) = 0;
}

