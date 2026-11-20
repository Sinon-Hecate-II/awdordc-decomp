/* 23 functions from 0x021E1500 to 0x021E24E8 (ov002), found by ds-decomp. */
#include "common.h"
#include "ov002_panel.h"

void func_ov002_021e1500(void) {
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK GX_SetBankForOBJ(M2C_UNK);
    M2C_UNK GX_SetBankForTex(M2C_UNK);
    M2C_UNK GX_SetBankForOBJExtPltt(M2C_UNK);
    M2C_UNK func_02082c84();
    func_02082c84();
    GX_SetBankForTex(3);
    GX_SetBankForBG(0x10);
    GX_SetBankForOBJ(0x40);
    GX_SetBankForOBJExtPltt(0x20);
}

void func_ov002_021e152c(void) {
    void func_020822b8(void *);
    void SetDemoBattleDefaults(void *);
    void InitBattleScene(void *);
    void InitBattleSpriteScene(void *);
    extern M2C_UNK data_ov002_021ea680,gPlayerSettings,data_ov002_021f30e4,data_ov002_021f3014;
    extern u8 data_ov002_021f2f40;
    func_ov002_021e1500();
    func_020822b8(&data_ov002_021ea680);
    if(data_ov002_021f2f40) SetDemoBattleDefaults(&gPlayerSettings);
    InitBattleScene(&data_ov002_021f30e4);
    InitBattleSpriteScene(&data_ov002_021f3014);
}

void func_ov002_021e157c(void) {
 M2C_UNK UpdateBattleScene(void *);
 M2C_UNK func_ov002_021e78e4(void *);
 extern M2C_UNK data_ov002_021f30e4;
 UpdateBattleScene(&data_ov002_021f30e4);
 func_ov002_021e78e4(&data_ov002_021f30e4);
}

void func_ov002_021e1598(void) {
    extern M2C_UNK data_ov002_021f30e4;
    M2C_FIELD(&data_ov002_021f30e4, s8 *, 9) = 1;
}

void func_ov002_021e15ac(void) {
    void func_ov002_021e3dd4(void *);
    void func_ov002_021e7970(void *);
    extern M2C_UNK data_ov002_021f3014,data_ov002_021f30e4;
    func_ov002_021e3dd4(&data_ov002_021f3014);
    func_ov002_021e7970(&data_ov002_021f30e4);
    *(volatile u16 *)0x4000304 &= ~0x8000;
}

void func_ov002_021e15e0(void) {
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    extern M2C_UNK data_ov002_021ea68c;
    func_01ffa9bc(&data_ov002_021ea68c);
}

void CreateBattleSceneSprite(s32 a) {
    void func_ov002_021e152c(void);
    void CreateSpriteObject(void *,s32);
    extern u8 data_ov002_021f2f40;
    extern M2C_UNK data_ov002_021ea68c;
    data_ov002_021f2f40=0;
    func_ov002_021e152c();
    CreateSpriteObject(&data_ov002_021ea68c,a);
}

void func_ov002_021e1624(void) {
    M2C_UNK func_ov002_021e3e00(M2C_UNK *);
    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e3e00(&data_ov002_021f3014);
}

s32 func_ov002_021e1638(void *a) {
    M2C_FIELD(a,s32 *,4)=0;
    M2C_FIELD(a,s32 *,16)=0;
    M2C_FIELD(a,s32 *,24)=0;
    M2C_FIELD(a,s32 *,28)=0;
    M2C_FIELD(a,s32 *,32)=0;
    M2C_FIELD(a,s32 *,36)=0;
    M2C_FIELD(a,s32 *,40)=0;
    M2C_FIELD(a,s32 *,44)=0;
    M2C_FIELD(a,s32 *,48)=0;
    M2C_FIELD(a,s32 *,52)=0;
    M2C_FIELD(a,s32 *,20)=0;
    M2C_FIELD(a,u16 *,56)=0;
    M2C_FIELD(a,u8 *,58)=0;
    M2C_FIELD(a,u8 *,59)=0;
    M2C_FIELD(a,u16 *,60)=0;
    M2C_FIELD(a,u16 *,62)=0;
    M2C_FIELD(a,u16 *,64)=0;
    M2C_FIELD(a,u8 *,70)=0;
    M2C_FIELD(a,u16 *,66)=256;
    M2C_FIELD(a,u8 *,68)=0;
    M2C_FIELD(a,u8 *,69)=0;
    M2C_FIELD(a,u8 *,72)=0;
    M2C_FIELD(a,u8 *,73)=0;
    M2C_FIELD(a,u8 *,74)=0;
    M2C_FIELD(a,u8 *,77)=0;
    M2C_FIELD(a,u8 *,78)=31;
    M2C_FIELD(a,u8 *,79)=0;
    M2C_FIELD(a,u8 *,80)=0;
    M2C_FIELD(a,u8 *,81)=0;
}

void func_ov002_021e16bc(void *arg0, s8 arg1, s8 arg2) {
    M2C_UNK func_ov002_021e1638();
    func_ov002_021e1638();
    M2C_FIELD(arg0, s8 *, 0x53) = arg1;
    M2C_FIELD(arg0, s8 *, 0x47) = arg2;
}

void func_ov002_021e16dc(void *a,s32 b,s16 c,s8 d,u8 e) {
    s32 p;
    M2C_FIELD(a,s32 *,4)=b;
    M2C_FIELD(a,s16 *,0x38)=c;
    M2C_FIELD(a,s8 *,0x3a)=d;
    M2C_FIELD(a,s32 *,0x10)=b+M2C_FIELD(M2C_FIELD(a,s32 *,4),s32 *,0);
    p=b+M2C_FIELD(M2C_FIELD(a,s32 *,4)+e*4,s32 *,4);
    M2C_FIELD(a,s32 *,0x18)=p;
    M2C_FIELD(a,s32 *,0x1c)=p;
    M2C_FIELD(a,u8 *,0x46)=e;
    M2C_FIELD(a,s32 *,0x30)=0;
    M2C_FIELD(a,s32 *,0x34)=0;
    M2C_FIELD(a,u8 *,0x4d)=0;
    M2C_FIELD(a,s32 *,0x14)=0;
    M2C_FIELD(a,u8 *,0x4f)=0;
    M2C_FIELD(a,u8 *,0x51)=0;
    M2C_FIELD(a,u8 *,0x52)=0;
}

void func_ov002_021e173c(void *arg0, s8 arg1) {
    s32 temp_ip;
    s32 temp_r3;

    temp_ip = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_ip != 0) && (arg1 != 0xFF)) {
        temp_r3 = temp_ip + M2C_FIELD((temp_ip + (arg1 * 4)), s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x18) = temp_r3;
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_r3;
        M2C_FIELD(arg0, s8 *, 0x46) = arg1;
        M2C_FIELD(arg0, s32 *, 0x30) = 0;
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x4D) = 0;
        M2C_FIELD(arg0, s8 *, 0x4F) = 0;
        M2C_FIELD(arg0, s8 *, 0x51) = 0;
    }
}

void func_ov002_021e1780(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

void func_ov002_021e1790(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = arg2;
}

void SetEffectNodeTranslation(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x3C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = arg2;
    M2C_FIELD(arg0, s16 *, 0x40) = arg3;
}

void SetEffectScale(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x42) = arg1;
}

/* Start an effect node's palette flash and pass it on: the node blinks for
 * `frames` ticks (counting the phase it is already in) drawing `palette` as its
 * alternate palette, and so does every child marked FX_NODE_FLASH_CHILD. */
void SetEffectNodeFlash(void *effect, s32 frames, s8 palette) {
    void *link;
    void *child;
    if(M2C_FIELD(effect,u8 *,FX_NODE_FLASH_FRAMES)) {
        if(!M2C_FIELD(effect,u8 *,FX_NODE_FLASH_PHASE)) M2C_FIELD(effect,u8 *,FX_NODE_FLASH_PHASE)=2;
    }
    M2C_FIELD(effect,u8 *,FX_NODE_FLASH_FRAMES)=frames-M2C_FIELD(effect,u8 *,FX_NODE_FLASH_PHASE);
    M2C_FIELD(effect,s8 *,FX_NODE_PALETTE_ALT)=palette;
    link=NULL;
    goto next;
    do {
        child=M2C_FIELD(link,void **,FX_LINK_NODE);
        if(M2C_FIELD(child,u8 *,FX_NODE_FLASH_CHILD)) SetEffectNodeFlash(child,frames,palette);
next:
        if(!link) {
            if(!M2C_FIELD(effect,void **,FX_NODE_CHILD)) link=NULL;
            else link=(u8 *)effect+FX_NODE_CHILD;
        } else link=M2C_FIELD(link,void **,FX_LINK_NEXT);
    } while(link);
}

#pragma optimization_level 3
void func_ov002_021e1844(void *arg0) {
    void func_ov002_021e1780(void *);
    M2C_UNK func_ov002_021e299c(void *, M2C_UNK);
    M2C_UNK func_ov002_021e29d8(void *);
    M2C_UNK func_ov002_021e29f8(void *, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov002_021e26d4(void *);
    M2C_UNK func_ov002_021e2724(void *);
    M2C_UNK func_ov002_021e2770(void *, M2C_UNK);
    void Ov002_CreateEffectNode(void *, s32, s32);
    M2C_UNK func_ov002_021e2928(void *, M2C_UNK);
    M2C_UNK PlaySlotVolumeSound(M2C_UNK);
    M2C_UNK PlaySlotVariantSound(M2C_UNK);
    M2C_UNK func_020afb34(M2C_UNK);
    M2C_UNK func_020afb94(M2C_UNK);
    if (M2C_FIELD(arg0, void **, 4) == NULL) goto recurse;
    M2C_FIELD(arg0, s16 *, 0x3c) = (s16)(M2C_FIELD(arg0, s16 *, 0x3c) + M2C_FIELD(arg0, s8 *, 0x44));
    M2C_FIELD(arg0, s16 *, 0x3e) = (s16)(M2C_FIELD(arg0, s16 *, 0x3e) + M2C_FIELD(arg0, s8 *, 0x45));
    {
        u8 t = M2C_FIELD(arg0, u8 *, 0x49);
        if (t != 0) {
            M2C_FIELD(arg0, u8 *, 0x49) = t - 1;
        } else {
            t = M2C_FIELD(arg0, u8 *, 0x48);
            if (t != 0) M2C_FIELD(arg0, u8 *, 0x48) = t - 1;
            t = M2C_FIELD(arg0, u8 *, 0x48);
            if (t == 0) M2C_FIELD(arg0, u8 *, 0x49) = 2;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        void *current;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        current = M2C_FIELD(arg0, void **, 0x1c);
        if (M2C_FIELD(current, u8 *, 0) == 0) do {
        switch (M2C_FIELD(current, u8 *, 1)) {
        case 0:
            goto recurse;
        case 1:
            M2C_FIELD(arg0, void **, 0x1c) = M2C_FIELD(arg0, void **, 0x18);
            goto nextCommand;
        case 2: {
            void **vt = *(void ***)arg0;
            (*(void (*)(void *))vt[0])(arg0);
            func_ov002_021e1780(arg0);
            goto recurse;
        }
        case 3: {
            void **vt = *(void ***)arg0;
            (*(void (*)(void *))vt[1])(arg0);
            break;
        }
        case 4: {
            void **vt = *(void ***)arg0;
            if (((s32 (*)(void *))vt[2])(arg0) != 1) break;
            goto recurse;
        }
        case 6: {
            void *r2 = (void *)M2C_FIELD(arg0, void **, 0x18);
            if (M2C_FIELD(r2, u8 *, 1) != 0xff) do {
                u8 o = M2C_FIELD(r2, u8 *, 1);
                if (o == 0x05) {
                    s16 a = M2C_FIELD(current, s16 *, 0x8);
                    s16 b = M2C_FIELD(r2, s16 *, 0x8);
                    if (a == b) {
                        M2C_FIELD(arg0, void **, 0x1c) = (void **)r2;
                        break;
                    }
                }
                r2 = (void *)((char *)r2 + 0xc);
            } while (M2C_FIELD(r2, u8 *, 1) != 0xff);
            break;
        }
        case 16:
            func_ov002_021e299c(arg0, 4);
            break;
        case 17:
            func_ov002_021e299c(arg0, 6);
            break;
        case 18:
            func_ov002_021e29d8(arg0);
            break;
        case 19:
            M2C_FIELD(arg0, u8 *, 0x4a) = 1;
            break;
        case 20:
            M2C_FIELD(arg0, u8 *, 0x4a) = 0;
            break;
        case 21:
            M2C_FIELD(arg0, u8 *, 0x4d) = (u8)M2C_FIELD(current, s16 *, 0x8);
            M2C_FIELD(arg0, u8 *, 0x4e) = (u8)M2C_FIELD((void *)M2C_FIELD(arg0, void **, 0x1c), s16 *, 0xa);
            break;
        case 22:
            M2C_FIELD(arg0, u8 *, 0x4f) = (u8)M2C_FIELD(current, s16 *, 0x8);
            break;
        case 23:
        case 24:
        case 25:
            M2C_FIELD(arg0, void **, 0x24) = (void **)current;
            M2C_FIELD(arg0, u8 *, 0x4b) = (u8)M2C_FIELD((void *)M2C_FIELD(arg0, void **, 0x1c), u8 *, 1);
            break;
        case 26:
            func_ov002_021e29f8(arg0, (M2C_UNK)M2C_FIELD(current, s16 *, 0x8), (M2C_UNK)M2C_FIELD(current, s16 *, 0xa));
            break;
        case 27:
            func_ov002_021e26d4(arg0);
            break;
        case 28:
            func_ov002_021e2724(arg0);
            break;
        case 29:
            func_ov002_021e2770(arg0, (M2C_UNK)M2C_FIELD(current, s16 *, 0x8));
            break;
        case 30:
            M2C_FIELD(arg0, u8 *, 0x52) = 1;
            break;
        case 31:
            func_ov002_021e2928(arg0, (M2C_UNK)((s32)M2C_FIELD(current, s16 *, 0x8) & 0xff));
            break;
        case 32:
            PlaySlotVolumeSound(M2C_FIELD(arg0, u8 *, 0x53));
            break;
        case 33:
            PlaySlotVariantSound(M2C_FIELD(arg0, u8 *, 0x53));
            break;
        case 35:
            func_020afb34(M2C_FIELD(arg0, u8 *, 0x53));
            break;
        case 36:
            func_020afb94(M2C_FIELD(arg0, u8 *, 0x53));
            break;
        }
        {
            u8 op = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1c), u8 *, 1);
            if (op >= 0x41 && op <= 0x4f) {
                Ov002_CreateEffectNode(arg0, (u8)(op - 0x41), -1);
                M2C_FIELD(arg0, void **, 0x24) = NULL;
            }
            op = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1c), u8 *, 1);
            if (op >= 0x51 && op <= 0x5f) {
                Ov002_CreateEffectNode(arg0, (u8)(op - 0x51), 1);
                M2C_FIELD(arg0, void **, 0x24) = NULL;
            }
            current = M2C_FIELD(arg0, void **, 0x1c);
            if (M2C_FIELD(current, u8 *, 1) == 0xff) {
                func_ov002_021e1780(arg0);
                goto recurse;
            }
            M2C_FIELD(arg0, void **, 0x1c) = (u8 *)current + 0xc;
        }
    nextCommand:
        current = M2C_FIELD(arg0, void **, 0x1c);
        } while (M2C_FIELD(current, u8 *, 0) == 0);
        M2C_FIELD(arg0, s32 *, 0x30) = M2C_FIELD(current, u8 *, 0);
        M2C_FIELD(arg0, void **, 0x14) = (u8 *)M2C_FIELD(arg0, void **, 4) +
            M2C_FIELD(arg0, s32 **, 0x10)[M2C_FIELD(M2C_FIELD(arg0, void **, 0x1c), u8 *, 1)];
        M2C_FIELD(arg0, void **, 0x20) = M2C_FIELD(arg0, void **, 0x1c);
        M2C_FIELD(arg0, void **, 0x1c) = (u8 *)M2C_FIELD(arg0, void **, 0x1c) + 0xc;
    }
    M2C_FIELD(arg0, s32 *, 0x30)--;
    M2C_FIELD(arg0, s32 *, 0x34)++;
recurse:
    {
        void **node = NULL;
        while ((node = node ? M2C_FIELD(node, void ***, 4) :
                (M2C_FIELD(arg0, void **, 8) == NULL ? NULL : (void **)((u8 *)arg0 + 8))) != NULL) {
            func_ov002_021e1844(*node);
        }
    }
}
#pragma optimization_level reset
void func_ov002_021e1c34(void *a,s32 b) {
    s32 x,y,z;
    u16 scale;
    s32 value;
    if(!b) {
        z=M2C_FIELD(a,s16 *,0x40);
        y=M2C_FIELD(a,s16 *,0x3e);
        x=M2C_FIELD(a,s16 *,0x3c);
        *(volatile s32 *)0x4000470=x;
        *(volatile s32 *)0x4000470=y;
        *(volatile s32 *)0x4000470=z;
    } else {
        x=M2C_FIELD(a,s16 *,0x3c);
        z=M2C_FIELD(a,s16 *,0x40);
        y=M2C_FIELD(a,s16 *,0x3e);
        *(volatile s32 *)0x4000470=-x;
        *(volatile s32 *)0x4000470=y;
        *(volatile s32 *)0x4000470=z;
    }
    scale=M2C_FIELD(a,u16 *,0x42);
    if(scale==0x100) return;
    value=(s32)(scale<<12)>>8;
    *(volatile s32 *)0x400046c=value;
    *(volatile s32 *)0x400046c=value;
    *(volatile s32 *)0x400046c=0x1000;
}

#pragma push
#pragma scheduling off
void func_ov002_021e1cac(void *obj, s32 flip, s32 orient, void *ptr, void *ptr2, u8 kind, volatile s32 diff, volatile s32 temp) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    M2C_UNK func_02004078(s16, s16);
    extern M2C_UNK gSinCosTable;
    s16 var_r4;
    s16 var_r5;
    u16 var_r6;
    u16 var_r8;
    u16 var_r1;
    s32 var_r7;

    if (ptr == NULL) {
        return;
    }
    if ((ptr2 != NULL) && (temp != 0)) {
        switch (kind) {
        default:
        case 23:
            var_r7 = 0;
            break;
        case 24:
            var_r7 = 1;
            break;
        case 25:
            var_r7 = 4;
            break;
        }
        { s32 duration=temp; s32 elapsed=diff;
        var_r4 = (s16) EaseInterpolate(var_r7, M2C_FIELD(ptr, s16 *, 8), M2C_FIELD(ptr, s16 *, 8) + M2C_FIELD(ptr2, s16 *, 8), elapsed, duration);
        var_r5 = (s16) EaseInterpolate(var_r7, M2C_FIELD(ptr, s16 *, 0xA), M2C_FIELD(ptr, s16 *, 0xA) + M2C_FIELD(ptr2, s16 *, 0xA), elapsed, duration);
        var_r6 = (u16) EaseInterpolate(var_r7, (s32) M2C_FIELD(ptr, u16 *, 4), (s32) (M2C_FIELD(ptr, u16 *, 4) * M2C_FIELD(ptr2, u16 *, 4)) >> 8, elapsed, duration);
        var_r8 = (u16) EaseInterpolate(var_r7, (s32) M2C_FIELD(ptr, u16 *, 6), (s32) (M2C_FIELD(ptr, u16 *, 6) * M2C_FIELD(ptr2, u16 *, 6)) >> 8, elapsed, duration);
        var_r1 = (u16) EaseInterpolate(var_r7, (s32) M2C_FIELD(ptr, u16 *, 2), M2C_FIELD(ptr, u16 *, 2) + M2C_FIELD(ptr2, u16 *, 2), elapsed, duration);
        }
    } else {
        var_r4 = M2C_FIELD(ptr, s16 *, 8);
        var_r5 = M2C_FIELD(ptr, s16 *, 0xA);
        var_r6 = M2C_FIELD(ptr, u16 *, 4);
        var_r8 = M2C_FIELD(ptr, u16 *, 6);
        var_r1 = M2C_FIELD(ptr, u16 *, 2);
    }
    if (flip != 0) {
        var_r4 = -var_r4;
        var_r1 = (u16)(0 - var_r1);
    }
    if (orient != 0) {
        s32 idx = ((s32) (u16) (var_r1 << 8) >> 4) * 2;
        s16 sn = ((s16 *)&gSinCosTable)[idx];
        s16 cs = ((s16 *)&gSinCosTable)[idx + 1];
        M2C_FIELD((void *) 0x0400046C, volatile s32 *, 0) = (s32) ((s32) (var_r6 << 0xC) >> 8);
        M2C_FIELD((void *) 0x0400046C, volatile s32 *, 0) = (s32) ((s32) (var_r8 << 0xC) >> 8);
        M2C_FIELD((void *) 0x0400046C, volatile s32 *, 0) = 0x1000;
        func_02004078(sn, cs);
        M2C_FIELD((void *) 0x0400046C, volatile s32 *, 4) = (s32) var_r4;
        M2C_FIELD((void *) 0x0400046C, volatile s32 *, 4) = (s32) var_r5;
        M2C_FIELD((void *) 0x0400046C, volatile s32 *, 4) = 0;
    } else {
        *(volatile s32 *) 0x04000470 = (s32) var_r4;
        {
            s32 idx = ((s32) (u16) (var_r1 << 8) >> 4) * 2;
        s16 sn = ((s16 *)&gSinCosTable)[idx];
        s16 cs = ((s16 *)&gSinCosTable)[idx + 1];
            *(volatile s32 *) 0x04000470 = (s32) var_r5;
            *(volatile s32 *) 0x04000470 = 0;
            M2C_FIELD((void *) 0x0400046C, volatile s32 *, 0) = (s32) ((s32) (var_r6 << 0xC) >> 8);
            M2C_FIELD((void *) 0x0400046C, volatile s32 *, 0) = (s32) ((s32) (var_r8 << 0xC) >> 8);
            M2C_FIELD((void *) 0x0400046C, volatile s32 *, 0) = 0x1000;
            func_02004078(sn, cs);
        }
    }
}
#pragma push
#pragma optimization_level 3
void func_ov002_021e1ef8(void *arg0, s32 arg1) {
    M2C_UNK SetGxPolygonAttr(s32, s32);
    void func_ov002_021e1cac(void *, M2C_UNK, M2C_UNK, void *, void *, u8, M2C_UNK, M2C_UNK);
    void func_ov002_021e2204(void *);
    void func_ov002_021e2364(void *);
    s32 func_ov002_021e27c4(void *);
    M2C_UNK var_r1;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s8 temp_r2_2;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r2;
    void **var_r7;
    s32 sameSide;

    temp_r2 = M2C_FIELD(arg0, u8 *, 0x4D);
    if (temp_r2 != 0) {
        SetGxPolygonAttr((s32) (u8) (temp_r2 + ((M2C_FIELD(arg0, u8 *, 0x47) * 3) + 9)), (s32) M2C_FIELD(arg0, u8 *, 0x4E));
    }
    sameSide = 0;
    M2C_FIELD((void *)0x04000444, volatile s32 *, 0) = 0;
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x53);
    if (arg1 == 0) {
        if (temp_r0 == 0) {
            sameSide = 1;
        }
    } else if (temp_r0 != 0) {
        sameSide = 1;
    }
    if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        var_r0 = 0;
    } else {
        var_r0 = func_ov002_021e27c4(arg0);
    }
    func_ov002_021e1cac(arg0, sameSide, 0, M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), (s32) M2C_FIELD(arg0, u8 *, 0x4C), M2C_FIELD(arg0, s32 *, 0x34), var_r0);
    temp_r2_2 = M2C_FIELD(arg0, s8 *, 0x4F);
    if (temp_r2_2 != 0) {
        *(volatile s32 *)0x04000470 = 0;
        *(volatile s32 *)0x04000470 = 0;
        *(volatile s32 *)0x04000470 = (s32) temp_r2_2;
    }
    temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x53);
    var_r1 = arg1 == 0 ? temp_r0_2 == 0 : temp_r0_2 != 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(void *, M2C_UNK), 0xC)(arg0, var_r1);
    temp_r0_3 = M2C_FIELD(arg0, u8 *, 0x53);
    var_r0_2 = arg1 == 0 ? temp_r0_3 == 0 : temp_r0_3 != 0;
    if (var_r0_2 != 0) {
        func_ov002_021e2364(arg0);
    } else {
        func_ov002_021e2204(arg0);
    }
    if ((M2C_FIELD(arg0, u8 *, 0x50) != 0) && (M2C_FIELD(arg0, u8 *, 0x4D) == 0)) {
        M2C_FIELD((void *)0x04000444, volatile s32 *, 0) = 0;
        if (M2C_FIELD(arg0, u8 *, 0x53) == 0) {
            M2C_FIELD((void *)0x04000444, volatile s32 *, 0x2C) = 1;
            M2C_FIELD((void *)0x04000444, volatile s32 *, 0x2C) = 0;
            M2C_FIELD((void *)0x04000444, volatile s32 *, 0x2C) = -1;
        } else {
            M2C_FIELD((void *)0x04000444, volatile s32 *, 0x2C) = -1;
            M2C_FIELD((void *)0x04000444, volatile s32 *, 0x2C) = 0;
            M2C_FIELD((void *)0x04000444, volatile s32 *, 0x2C) = -1;
        }
        SetGxPolygonAttr(0x1E, 0xB);
        temp_r0_4 = M2C_FIELD(arg0, u8 *, 0x53);
        var_r0_3 = arg1 == 0 ? temp_r0_4 == 0 : temp_r0_4 != 0;
        if (var_r0_3 != 0) {
            func_ov002_021e2364(arg0);
        } else {
            func_ov002_021e2204(arg0);
        }
        M2C_FIELD((void *)0x04000448, volatile s32 *, 0) = 1;
        M2C_FIELD((void *)0x04000448, volatile s32 *, -4) = 0;
        if (M2C_FIELD(arg0, u8 *, 0x53) == 0) {
            M2C_FIELD((void *)0x04000448, volatile s32 *, 0x28) = -1;
            M2C_FIELD((void *)0x04000448, volatile s32 *, 0x28) = 0;
            M2C_FIELD((void *)0x04000448, volatile s32 *, 0x28) = -1;
        } else {
            M2C_FIELD((void *)0x04000448, volatile s32 *, 0x28) = 1;
            M2C_FIELD((void *)0x04000448, volatile s32 *, 0x28) = 0;
            M2C_FIELD((void *)0x04000448, volatile s32 *, 0x28) = -1;
        }
        SetGxPolygonAttr(0x1D, 8);
        temp_r0_5 = M2C_FIELD(arg0, u8 *, 0x53);
        var_r0_4 = arg1 == 0 ? temp_r0_5 == 0 : temp_r0_5 != 0;
        if (var_r0_4 != 0) {
            func_ov002_021e2364(arg0);
        } else {
            func_ov002_021e2204(arg0);
        }
        SetGxPolygonAttr(0, 0x1F);
        M2C_FIELD((void *)0x04000448, volatile s32 *, 0) = 1;
    }
    var_r7 = NULL;
    sameSide = 0;
    goto next_child;
    do {
        func_ov002_021e1ef8(*var_r7, arg1);
next_child:
    if (var_r7 == NULL) {
        if (M2C_FIELD(arg0, s32 *, 8) == 0) {
            var_r7 = (void **)sameSide;
        } else {
            var_r7 = (void **) (arg0 + 8);
        }
    } else {
        var_r7 = M2C_FIELD(var_r7, void ***, 4);
    }
    } while (var_r7 != NULL);
    M2C_FIELD((void *)0x04000448, volatile s32 *, 0) = 1;
    if (M2C_FIELD(arg0, u8 *, 0x4D) == 0) {
        return;
    }
    SetGxPolygonAttr(0, 0x1F);
}
#pragma pop
void func_ov002_021e2204(void *arg0) {
    M2C_UNK SetGxTextureParams(M2C_UNK, u16, u16, s32, s32);
    M2C_UNK DrawTexturedQuadUVFlip(s16, s16, u32, u16, s32, s32, s32, s32, s32, u32, u32);
    void func_ov002_021e1cac(void *, M2C_UNK, M2C_UNK, void *, void *, u8, M2C_UNK, M2C_UNK);
    u8 *p20;
    u8 temp_r5;
    u16 temp_r6_2;
    u16 temp_r7;
    u16 var_r3;
    u32 temp_r8;
    u32 temp_r9;
    u8 temp_r0;
    u8 temp_r6;
    u8 var_r2;
    void *var_r5;

    if (M2C_FIELD(arg0, void **, 0x14) == NULL) {
        return;
    }
    *(s32 *)0x04000444 = 0;
    p20 = M2C_FIELD(arg0, u8 **, 0x20);
    temp_r5 = *p20;
    func_ov002_021e1cac(arg0, 0, 1, (void *) p20, (void *) M2C_FIELD(arg0, s32 *, 0x24), (M2C_UNK) M2C_FIELD(arg0, u8 *, 0x4B), (M2C_UNK) (temp_r5 - M2C_FIELD(arg0, s32 *, 0x30)), (M2C_UNK) temp_r5);
    var_r5 = M2C_FIELD(arg0, void **, 0x14);
    var_r3 = M2C_FIELD(var_r5, u16 *, 4);
    if (var_r3 != 0xFFFF) {
        do {
            temp_r0 = M2C_FIELD(var_r5, u8 *, 6);
            temp_r6 = M2C_FIELD(var_r5, u8 *, 7);
            temp_r6_2 = ((u32) (temp_r0 << 0x1C) >> 0x1C) * 8;
            temp_r7 = ((u32) (temp_r0 << 0x18) >> 0x1C) * 8;
            temp_r8 = (u32) (temp_r6 << 0x1B) >> 0x1F;
            temp_r9 = (u32) (temp_r6 << 0x1A) >> 0x1F;
            if (M2C_FIELD(arg0, u8 *, 0x48) != 0) {
                if (M2C_FIELD(arg0, u8 *, 0x49) == 0) {
                    var_r2 = M2C_FIELD(arg0, u8 *, 0x3B);
                } else {
                    var_r2 = M2C_FIELD(arg0, u8 *, 0x3A);
                }
                SetGxTextureParams(3, temp_r6_2, temp_r7, M2C_FIELD(arg0, u16 *, 0x38) + var_r3, M2C_FIELD(arg0, u8 *, 0x51) + (var_r2 + ((u32) (M2C_FIELD(var_r5, u8 *, 7) << 0x1C) >> 0x1C)));
            }
            DrawTexturedQuadUVFlip(M2C_FIELD(var_r5, s16 *, 0), M2C_FIELD(var_r5, s16 *, 2), (u32) (M2C_FIELD(var_r5, u8 *, 7) << 0x18) >> 0x1E, temp_r6_2, (s32) temp_r7, 0, 0, (s32) temp_r6_2, (s32) temp_r7, temp_r8, temp_r9);
            var_r5 = (u8 *) var_r5 + 8;
            var_r3 = M2C_FIELD(var_r5, u16 *, 4);
        } while (var_r3 != 0xFFFF);
    }
    *(s32 *)0x04000448 = 1;
}

void func_ov002_021e2364(void *arg0) {
    M2C_UNK SetGxTextureParams(M2C_UNK, u16, u16, s32, s32);
    M2C_UNK DrawTexturedQuadUVFlip(s16, s16, u32, u16, s32, s32, s32, s32, s32, u32, u32);
    void func_ov002_021e1cac(void *, M2C_UNK, M2C_UNK, void *, void *, u8, M2C_UNK, M2C_UNK);
    register void *var_r4;
    register s16 temp_r5_3;
    register u16 temp_r6;
    register u8 var_r1;
    register u16 temp_r9;
    u16 var_r3;
    u32 temp_r0;
    u8 temp_r2;
    u8 temp_r5;
    u32 temp_r5_2;
    u8 var_ip;


    if (M2C_FIELD(arg0, void **, 0x14) == NULL) {
        return;
    }
    *(s32 *)0x04000444 = 0;
    temp_r5 = *M2C_FIELD(arg0, u8 **, 0x20);
    func_ov002_021e1cac(arg0, 1, 1, M2C_FIELD(arg0, void **, 0x20), M2C_FIELD(arg0, void **, 0x24), M2C_FIELD(arg0,u8 *,0x4b), temp_r5-M2C_FIELD(arg0,s32 *,0x30), temp_r5);
    var_r4 = M2C_FIELD(arg0, void **, 0x14);
    var_r3 = M2C_FIELD(var_r4, u16 *, 4);
    if (var_r3 != 0xFFFF) {
        do {
            temp_r2 = M2C_FIELD(var_r4, u8 *, 6);
            temp_r5_2 = M2C_FIELD(var_r4, u8 *, 7);
            temp_r0 = (u32) (temp_r2 << 0x1C) >> 0x1C;
            temp_r9 = temp_r0 * 8;
            temp_r5_3 = 0 - (M2C_FIELD(var_r4, s16 *, 0) + temp_r9);
            temp_r6 = (u16)(((u32)temp_r2 << 24 >> 28) << 3);
            if (((u32) (temp_r5_2 << 0x1B) >> 0x1F) == 0) {
                var_r1 = 1;
            } else {
                var_r1 = 0;
            }

            if (M2C_FIELD(arg0, u8 *, 0x48) != 0 && M2C_FIELD(arg0, u8 *, 0x49) == 0) {
                    var_ip = M2C_FIELD(arg0, u8 *, 0x3B);
                } else {
                    var_ip = M2C_FIELD(arg0, u8 *, 0x3A);
                }
                SetGxTextureParams(3, temp_r9, temp_r6, M2C_FIELD(arg0, u16 *, 0x38) + var_r3, M2C_FIELD(arg0, u8 *, 0x51) + (var_ip + ((u32) (M2C_FIELD(var_r4, u8 *, 7) << 0x1C) >> 0x1C)));
            DrawTexturedQuadUVFlip(temp_r5_3, M2C_FIELD(var_r4, s16 *, 2), (u32) (M2C_FIELD(var_r4, u8 *, 7) << 0x18) >> 0x1E, temp_r9, (s32) temp_r6, 0, 0, (s32) temp_r9, (s32) temp_r6, (s32) var_r1, (u32) (temp_r5_2 << 0x1A) >> 0x1F);
            var_r4 += 8;
            var_r3 = M2C_FIELD(var_r4, u16 *, 4);
        } while (var_r3 != 0xFFFF);
    }
    *(s32 *)0x04000448 = 1;
}

