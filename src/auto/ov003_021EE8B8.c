/* 3 functions from 0x021EE8B8 to 0x021EF758 (ov003), found by ds-decomp. */
#include "common.h"
static inline u32 Ov003PanelFlag(void *p) { return (u32)(M2C_FIELD(p,u8 *,0x39)<<31)>>31; }
static inline s8 Ov003PanelCount(void *p) { return M2C_FIELD(p,s8 *,4); }
static inline void Ov003PanelUpdate(void *p) { M2C_FIELD(M2C_FIELD(p,void **,0),void (**)(void *),0x1c)(p); }
static inline int Ov003PlayersReady(void) {
    int IsLinkSessionActive(void);
    u32 GetReadyPlayerMask(void);
    void *func_02084e24(int);
    u32 mask;
    s8 i;
    void *p;
    if (!IsLinkSessionActive()) return 0;
    mask=GetReadyPlayerMask();
    for(i=0;i<4;i++) {
        if(mask & (1<<i)) {
            p=func_02084e24(i);
            if(!p) return 0;
            if(!M2C_FIELD(p,s32 *,0x18)) return 0;
        }
    }
    return 1;
}
extern void ***gCur3DSpriteEngine;
extern u8 data_ov003_0220f89e[],data_027e00b4[];
void AddSprite(u16,u16,u16,void *,int);
void func_02098dc0(s16,int,u16,int);
void func_02088e84(void *,s16,s32,s16,s32);
void func_02087d84(void *,int,s16,s16,u16,u16);
u32 func_020aae10(void *);u32 func_020aae44(void *);
int IsLinkSessionActive(void);
s16 func_ov003_022004a8(u8);
int func_ov003_022008b8(u8);
int func_ov003_021e6cc4(s16,int,int,int);
int func_ov003_021e6e5c(void);


#pragma opt_common_subs off
void func_ov003_021ee8b8(void *arg0) {
#pragma opt_common_subs off

    s32 IsLinkSessionActive();
    s32 func_02084d3c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02084d88(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088f1c(s32);
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_0208b758(s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    s16 GetSpriteAnimValue(void *);
    
    s32 InRange(u8, M2C_UNK, M2C_UNK);
    s32 func_ov003_021e6cfc();
    s32 func_ov003_021e6d28();
    M2C_UNK func_ov003_021e74ac(void *, M2C_UNK);

    s32 sp0[9];
    s32 temp_r3_2;
    s16 temp_r5_3;
    s32 spriteFlags;
    u32 rawFlags;
    void *temp_r4_7;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 flag;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r1;
    s32 var_r1_2;
    u8 temp_r0_3;
    u32 temp_r0;
    u32 temp_r0_4;
    void *temp_r4;
    u32 var_r6;
    u8 temp_r1;
    u8 temp_r7;
    u8 var_r4;
    void *temp_r0_2;
    void *temp_r1_2;
    register void *temp_r3;
    void *temp_r3_3;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;
    s32 temp_r4_8;
    void *temp_r6;
    void *temp_r6_2;

    void *func_02084e64(void);
    void *func_02084e24(int);
    int func_020848c4(void);
    u32 GetReadyPlayerMask(void);
    void *packet;
    int local, enabled, ready, offset;
    void *range;
    u8 i, j, n, id;
    u8 playerCount;
    int player;
    s8 k, oldValue, newValue;
    int func_020a22fc(int);
    int func_ov003_02200808(u8);
    u32 mask;
    void *p, *q;
    int count;
    if (!IsLinkSessionActive()) return;
    if (!func_02084d3c(sp0, 0x24)) return;
    packet=func_02084e64();
    if (!packet) return;
    local=func_020848c4();
    p=M2C_FIELD(arg0,void **,0x6c);
    count=M2C_FIELD(p,s8 *,4);
    enabled=(u32)(M2C_FIELD(arg0,u8 *,0x3a)<<31)>>31;
    i=0;
    if(count>0) do {
        id=M2C_FIELD(p+i,u8 *,0x74);
        if ((u8)(id==255)) id=M2C_FIELD(p,u8 *,0x74);
        q=func_02084e24(id);
        if (!q) break;
        p=M2C_FIELD(arg0,void **,0x68)+i;
        n=M2C_FIELD(q,u32 *,0x18);
        if(M2C_FIELD(p,u8 *,0x7c)){
            if(!n){if(enabled)PlaySoundEffect(0x1000f);M2C_FIELD(p,u8 *,0x7c)=0;}
        } else if(n){if(enabled)PlaySoundEffect(0x1000d);M2C_FIELD(p,u8 *,0x7c)=1;}
        p=M2C_FIELD(arg0,void **,0x6c);i=(u8)(i+1);
    }while(i<M2C_FIELD(p,s8 *,4));
    if((u8)((((u32)M2C_FIELD(arg0,u8 *,0x39)<<28)>>30)==0)){
        p=M2C_FIELD(arg0,void **,0x6c);
        player=func_020848c4();
        playerCount=M2C_FIELD(p,u8 *,4);
        for(j=0;j<playerCount;j++)if(player==M2C_FIELD(p+j,u8 *,0x74)){player=(s8)j;goto foundPlayer;}
        player=-1;
foundPlayer:
        M2C_FIELD(sp0,u8 *,0xd)=M2C_FIELD(M2C_FIELD(arg0,void **,0x6c)+(u8)player,u8 *,0xa);
        if(func_ov003_021e6cfc()){
            for(i=0;i<count;i=(u8)(i+1)){p=M2C_FIELD(arg0,void **,0x6c)+i;if((u8)(M2C_FIELD(p,u8 *,0x74)==255))M2C_FIELD((u8 *)sp0+i,u8 *,0x12)=M2C_FIELD(p,u8 *,0xa);}
            ready=Ov003PlayersReady();
            if(ready){
                flag=Ov003PanelFlag(arg0)==1?1:0;
                if(flag&255){Ov003PanelUpdate(arg0);return;}
                M2C_FIELD(sp0,u8 *,8)=1;
            }
        }
    }
    if((u8)((((u32)M2C_FIELD(arg0,u8 *,0x39)<<28)>>30)==1)){
        if(func_ov003_021e6cfc()){
            p=M2C_FIELD(arg0,void **,0x58);if(!M2C_FIELD(p,u8 *,0x59))M2C_FIELD(p,u8 *,0x59)=1;
            for(i=0;i<count;i++)M2C_FIELD((u8 *)(u8 *)sp0+i,u8 *,0xe)=M2C_FIELD(M2C_FIELD(arg0,void **,0x6c)+i*0x18,s32 *,0x18);
        }
        if(!M2C_FIELD(packet,u8 *,8)){
            PlaySoundEffect(0x1000f);
            rawFlags=M2C_FIELD(arg0,u8 *,0x39)&~12;
            if((((u32)(u8)rawFlags<<28)>>30)==0)var_r0_4=1;else var_r0_4=0;
            M2C_FIELD(arg0,u8 *,0x39)=rawFlags;
            if((var_r0_4&255)&&func_ov003_021e6d28()){func_02088d94(M2C_FIELD(arg0,void **,0x58));func_02088f1c(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s32 *,0));}
            temp_r4 = M2C_FIELD(arg0, void **, 0x64);
            temp_r7 = (u8) Ov003PanelCount(M2C_FIELD(arg0,void **,0x6c));
            if (IsLinkSessionActive() == 0) {
                var_r6 = 0;
                do {
                    if (var_r6 < (u32) temp_r7) {
                        func_02088d94(M2C_FIELD((temp_r4 + (var_r6 * 4)), void **, 8));
                        func_02088d94(M2C_FIELD((temp_r4 + (var_r6 * 4)), void **, 0x18));
                    }
                    var_r6 = (u32) (u8) (var_r6 + 1);
                } while (var_r6 < 4U);
            }
            temp_r4_2 = M2C_FIELD(arg0, void **, 0x48);
            M2C_FIELD(temp_r4_2, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_2);
            M2C_FIELD(temp_r4_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r4_2, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_2, u16 *, 2) = (u16) M2C_FIELD(temp_r4_2, u16 *, 4);
            temp_r4_3 = M2C_FIELD(arg0, void **, 0x50);
            M2C_FIELD(temp_r4_3, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_3);
            M2C_FIELD(temp_r4_3, s16 *, 0x10) = 0x100;
            M2C_FIELD(temp_r4_3, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_3, u16 *, 2) = (u16) M2C_FIELD(temp_r4_3, u16 *, 4);
            temp_r4_4 = M2C_FIELD(arg0, void **, 0x4C);
            M2C_FIELD(temp_r4_4, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_4);
            M2C_FIELD(temp_r4_4, s16 *, 0x10) = 0xC0;
            M2C_FIELD(temp_r4_4, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_4, u16 *, 2) = (u16) M2C_FIELD(temp_r4_4, u16 *, 4);
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 1) {
                var_r0_5 = 1;
            } else {
                var_r0_5 = 0;
            }
            if (var_r0_5 & 0xFF) {
                if (func_ov003_021e6d28() != 0) {
                    func_02088da8(M2C_FIELD(arg0, void **, 0x58));
                    func_02088ff4(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s32 *, 0));
                }
                temp_r6 = M2C_FIELD(arg0, void **, 0x64);
                var_r4 = 0;
                do {
                    func_02088da8(M2C_FIELD((temp_r6 + (var_r4 * 4)), void **, 8));
                    func_02088da8(M2C_FIELD((temp_r6 + (var_r4 * 4)), void **, 0x18));
                    var_r4 += 1;
                } while ((u32) var_r4 < 4U);
                temp_r4_5 = M2C_FIELD(arg0, void **, 0x48);
                M2C_FIELD(temp_r4_5, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_5);
                M2C_FIELD(temp_r4_5, s16 *, 0x10) = -0x100;
                M2C_FIELD(temp_r4_5, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_5, u16 *, 2) = (u16) M2C_FIELD(temp_r4_5, u16 *, 4);
                temp_r4_6 = M2C_FIELD(arg0, void **, 0x50);
                M2C_FIELD(temp_r4_6, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_6);
                M2C_FIELD(temp_r4_6, s16 *, 0x10) = 0;
                M2C_FIELD(temp_r4_6, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_6, u16 *, 2) = (u16) M2C_FIELD(temp_r4_6, u16 *, 4);
                temp_r4_7 = M2C_FIELD(arg0, void **, 0x4C);
                M2C_FIELD(temp_r4_7, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_7);
                M2C_FIELD(temp_r4_7, s16 *, 0x10) = 0x5E;
                M2C_FIELD(temp_r4_7, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_7, u16 *, 2) = (u16) M2C_FIELD(temp_r4_7, u16 *, 4);
            }
            func_ov003_021e74ac(M2C_FIELD(arg0, void **, 0x6C), 0);
            temp_r6_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0);
            temp_r4_8 = func_020aae44(temp_r6_2);
            temp_r3_2 = func_020aae10(temp_r6_2);
            temp_r5_3 = M2C_FIELD(temp_r6_2,s16 *,0x36);
            temp_r4_7 = (void *)(s32)M2C_FIELD(temp_r6_2,s16 *,0x34);
            temp_r3_2 = temp_r3_2 & 0x1ff;
            temp_r1_2 = M2C_FIELD(arg0, void **, 0x58);
            M2C_FIELD(temp_r1_2, s16 *, 0x34) = (s16)(s32)temp_r4_7;
            M2C_FIELD(temp_r1_2, s16 *, 0x36) = temp_r5_3;
            spriteFlags = M2C_FIELD(temp_r1_2,u32 *,0x40) & ~0x1ff;
            spriteFlags |= temp_r3_2;
            spriteFlags &= 0xfffc01ff;
            M2C_FIELD(temp_r1_2,u32 *,0x40) = spriteFlags | ((u32)(temp_r4_8 << 23)>>14);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
                temp_r0_3 = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
                if (InRange((u8) temp_r0_3, 0, 3) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
                } else if (InRange((u8) temp_r0_3, 4, 7) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000012);
                } else if (InRange((u8) temp_r0_3, 8, 0x14) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
                } else if (InRange((u8) temp_r0_3, 0x15, 0x18) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000010);
                } else if ((u8) temp_r0_3 == 0x19) {
                    temp_r0_4 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E;
                    if (temp_r0_4 == 0) {
                        var_r1_2 = 1;
                    } else {
                        var_r1_2 = 0;
                    }
                    if (var_r1_2 & 0xFF) {
                        func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000016);
                    } else {
                        if (temp_r0_4 == 1) {
                            var_r0_6 = 1;
                        } else {
                            var_r0_6 = 0;
                        }
                        if (var_r0_6 & 0xFF) {
                            func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000017);
                        }
                    }
                }
            }
            func_02088f1c(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s32 *,4));
            M2C_FIELD(M2C_FIELD(arg0,void **,0x58),u8 *,0x59)=1;
            if(func_ov003_021e6d28())func_02088d94(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
            func_02084d88(sp0,0x24);return;
        }
    }
    func_02084d88(sp0,0x24);
    for(i=0;i<count;i++){
        if(func_ov003_021e6d28()){
            offset=i*0x18;p=M2C_FIELD(arg0,void **,0x6c)+offset;n=M2C_FIELD((u8 *)packet+i,u8 *,0xe);
            if((u8)M2C_FIELD(p,s32 *,0x18)!=n){
                PlaySoundEffect(0x10011);
                q=M2C_FIELD(arg0,void **,0x6c);p=q+i*0x18;M2C_FIELD(p,s32 *,0x18)=n;
                if(M2C_FIELD(p,u8 *,0x28)){
                    if(M2C_FIELD(p,s32 *,0x18)>M2C_FIELD(p,s32 *,0x1c))do {range=q+offset;ready=M2C_FIELD(range,s32 *,0x18)-(M2C_FIELD(range,s32 *,0x1c)-M2C_FIELD(range,s32 *,0x20)+1);M2C_FIELD(range,s32 *,0x18)=ready;}while(ready>M2C_FIELD(range,s32 *,0x1c));
                    if(M2C_FIELD(p,s32 *,0x18)<M2C_FIELD(p,s32 *,0x20))do {range=q+offset;ready=M2C_FIELD(range,s32 *,0x18)+(M2C_FIELD(range,s32 *,0x1c)-M2C_FIELD(range,s32 *,0x20)+1);M2C_FIELD(range,s32 *,0x18)=ready;}while(ready<M2C_FIELD(range,s32 *,0x20));
                }else{
                    if(M2C_FIELD(p,s32 *,0x18)>M2C_FIELD(p,s32 *,0x1c))ready=M2C_FIELD(p,s32 *,0x1c);
                    else if(M2C_FIELD(p,s32 *,0x18)<M2C_FIELD(p,s32 *,0x20))ready=M2C_FIELD(p,s32 *,0x20);
                    else ready=M2C_FIELD(p,s32 *,0x18);
                    M2C_FIELD(p,s32 *,0x18)=ready;
                }
            }
        }
        p=M2C_FIELD(arg0,void **,0x6c);
        if(local==M2C_FIELD(p+i,u8 *,0x74))continue;
        if(func_ov003_021e6cfc()){
            p=M2C_FIELD(arg0,void **,0x6c);
            if((u8)(M2C_FIELD(p+i,u8 *,0x74)==255))continue;
        }
        p=M2C_FIELD(arg0,void **,0x6c)+i;
        id=M2C_FIELD(p,u8 *,0x74);
        oldValue=M2C_FIELD(p,s8 *,0xa);
        if(!(u8)(id==255)){
            q=func_02084e24(id);
            if(q)newValue=M2C_FIELD(q,s8 *,0xd);
            else newValue=func_ov003_02200808((u8)func_020a22fc(i+1));
        }else{
            q=func_02084e64();
            if(q)newValue=M2C_FIELD(q+i,s8 *,0x12);
            else newValue=func_ov003_02200808((u8)func_020a22fc(i+1));
        }
        if(oldValue!=newValue){
            PlaySoundEffect(0x10011);
            p=M2C_FIELD(arg0,void **,0x6c)+i;
            M2C_FIELD(p,u8 *,0xa)=(u8)newValue;
            M2C_FIELD(arg0,u8 *,0x3a)|=8;
            if(i==M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),u8 *,7)){
                p=M2C_FIELD(arg0,void **,0x40);
                M2C_FIELD(p,u8 *,0x10)=i;
                M2C_FIELD(p,u8 *,0x11)=(u8)newValue;
            }
        }
    }
#pragma opt_common_subs reset
}
#pragma opt_common_subs reset
void func_ov003_021ef1e8(void *arg0) {
    void func_01ffa6fc(void *);
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0xC) {
        func_01ffa6fc(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x38)++;
}

#pragma opt_strength_reduction off
void func_ov003_021ef210(void *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    u32 sp8;
    s16 temp_r0;
    s16 temp_r11;
    s16 temp_r11_2;
    s32 temp_r2;
    s16 temp_r4_2;
    s16 temp_r4_4;
    s16 temp_r5_3;
    s16 temp_r6;
    s16 temp_r6_2;
    s16 temp_r9;
    s16 temp_r6_4;
    s16 temp_r7;
    s16 temp_r7_3;
    s16 temp_r6_3;
    s32 temp_r0_2;
    s32 temp_r2_2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    u32 temp_r4;
    u32 temp_r4_3;
    u16 temp_r4_5;
    u32 temp_r7_2;
    u32 temp_r7_4;
    u16 var_r2;
    u8 var_r1;
    register u8 var_r8;
    void *temp_r5;
    void *temp_r5_2;

    sp8 = arg1;
    spC = arg2;
    var_r8 = 0;
    if (sp8 > 0U) {
    temp_r2 = (s16)(arg3 + 0x48);
    if (sp8 > 0U) {
    temp_r0 = (s16)temp_r2;
    sp14 = (s32)(s16)temp_r0;
    sp18 = (s32)(s16)temp_r0;
    sp1C = (s32) (u16) (u8) temp_r2;
    sp20 = (s32) (u16) (u8) (temp_r2 - 0x18);
    sp28 = 0x3FF;
    sp2C = 0x3FF;
    sp30 = 0x3FF;
    sp24 = 0x3FF;
    do {
        temp_r9 = spC + func_ov003_022004a8(var_r8);
        temp_r2_2 = (func_ov003_022008b8(M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0xA)) * 0x10) + 0x1F0;
        temp_r0_2 = temp_r9 - 4;
        sp10 = temp_r0_2;
        func_02098dc0((s16) temp_r0_2, 0, (u16) ((sp24 & (temp_r2_2 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7400), 0xA);
        temp_r5 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 8);
        temp_r7 = temp_r9 - 1;
        func_02088e84(temp_r5, temp_r7, sp14, temp_r7, sp14);
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            temp_r11 = M2C_FIELD(temp_r5, s16 *, 0x52);
            temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4 = func_020aae10(temp_r5);
            func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r6, temp_r11, (u16) temp_r4, (s32) func_020aae44(temp_r5));
        }
        M2C_FIELD(temp_r5, s16 *, 0x34) = temp_r7;
        M2C_FIELD(temp_r5, s16 *, 0x36) = (s16) sp18;
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            temp_r4_2 = M2C_FIELD(temp_r5, s16 *, 0x52);
            temp_r6_2 = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r7_2 = func_020aae10(temp_r5);
            func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r6_2, temp_r4_2, (u16) temp_r7_2, (s32) func_020aae44(temp_r5));
        }
        temp_r5_2 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 0x18);
        temp_r7_3 = temp_r9 + 0x28;
        func_02088e84(temp_r5_2, temp_r7_3, sp14, temp_r7_3, sp14);
        if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            temp_r11_2 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
            temp_r6_3 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
            temp_r4_3 = func_020aae10(temp_r5_2);
            func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r6_3, temp_r11_2, (u16) temp_r4_3, (s32) func_020aae44(temp_r5_2));
        }
        M2C_FIELD(temp_r5_2, s16 *, 0x34) = temp_r7_3;
        M2C_FIELD(temp_r5_2, s16 *, 0x36) = (s16) sp18;
        if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            temp_r4_4 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
            temp_r6_4 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
            temp_r7_4 = func_020aae10(temp_r5_2);
            func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r6_4, temp_r4_4, (u16) temp_r7_4, (s32) func_020aae44(temp_r5_2));
        }
        if (M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0xE) == 2) {
            var_r2 = 0x1E0;
        } else if (func_ov003_021e6e5c() != 0) {
            var_r2 = (M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0x74) * 0x10) + 0x1A0;
        } else {
            var_r2 = (var_r8 * 0x10) + 0x1A0;
        }
        temp_r4_5 = sp10 & 0x1FF;
        AddSprite(temp_r4_5, sp1C, (u16) ((sp28 & ((s32) var_r2 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6400), data_ov003_0220f89e, 0xA);
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 1) {
            var_r0_5 = 1;
        } else {
            var_r0_5 = 0;
        }
        if ((var_r0_5 & 0xFF) && (var_r8 == M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7))) {
            temp_r5_3 = temp_r9 - 2;
            if (func_ov003_021e6cc4(temp_r5_3, 0x48, 0x40, 0x20) != 0) {
                AddSprite((u16) (temp_r5_3 & 0x1FF), 0x48, (u16) ((sp2C & (0x680 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x9800), data_027e00b4, 0xB);
            }
        }
        if (IsLinkSessionActive() != 0) {
            var_r1 = var_r8;
            if (M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0x74) == 0xFF) {
                var_r0_6 = 1;
            } else {
                var_r0_6 = 0;
            }
            if (var_r0_6 & 0xFF) {
                var_r1 = 0;
            }
            if (M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x68) + var_r1), u8 *, 0x7C) != 0) {
                AddSprite(temp_r4_5, sp20, (u16) ((sp30 & (0x520 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x8000), data_027e00b4, 0xB);
            }
        }
        var_r8 += 1;
    } while ((u32) var_r8 < sp8);
}}
}
