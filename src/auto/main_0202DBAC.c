/* 14 functions from 0x0202DBAC to 0x0202E470 (main), found by ds-decomp. */
#include "common.h"
void func_0202de74(void *);
void Sound_ReleaseChannel(void *);
void func_0202e12c(M2C_UNK);
void func_0202e02c(M2C_UNK,void *);

/* Set up and start one sound/music player slot from a sample descriptor:
 * pick the slot, install its callbacks, derive its sample rate and channel
 * count, acquire the channel, then start the voice on the hardware. */
s32 Sound_StartPlayer(void **handle, void *sample, s32 slotIndex, s32 priority, s32 startPos, s32 lengthMs, s32 loopStart, s32 loopEnd, s32 streamCallback, s32 streamArg) {
    void *Sound_AcquirePlayer(void **, s32, s32);
    M2C_UNK Sound_SetPlayerCallbacks(void *, s32);
    void Sound_ReleasePlayer(void *);
    u64 func_02072088(u64, u64);
    void func_0202eec0(void *);
    void func_0202eed8(void *, s32, s32);
    s32 Sound_AcquireChannel(void *, s32, s32);
    u32 func_020722fc(u32, u32);
    s32 Sound_StartVoice(void *, s32, s32, s32, s32, s32, s32, s32);
    void Sound_ReleaseChannel(void *);
    void Sound_SetChannelVolume(void *, s32, M2C_UNK);
    void func_0202e1f4(M2C_UNK, s32, M2C_UNK *, M2C_UNK, void *);

    void *player;
    void *pb;
    s32 playMode;
    s32 channels;
    s32 playType;

    player = Sound_AcquirePlayer(handle, slotIndex, priority);
    pb = sample;
    if (player == 0) {
        return 0;
    }
    Sound_SetPlayerCallbacks(player, *(s32 *)pb);
    if (M2C_FIELD(player, s32 (**)(void *, s32), 0x164)(player, *(s32 *)pb) == 0) {
        Sound_ReleasePlayer(player);
        return 0;
    }

    M2C_FIELD(player, s32 *, 0x160) = (s32)func_02072088((u64)(u32)M2C_FIELD(player, u16 *, 0xC4) * (u32)lengthMs, 0x3E8ULL);
    if (M2C_FIELD(player, s32 *, 0x160) != 0 && M2C_FIELD(player, u8 *, 0xC0) == 2) {
        M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) | 0x10;
    } else {
        M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x10;
    }

    M2C_FIELD(player, s32 *, 0x114) = 4;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x20;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x2;
    M2C_FIELD(player, s32 *, 0x118) = 0;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x4;
    M2C_FIELD(player, s32 *, 0x110) = M2C_FIELD(player, s32 *, 0x110) & ~0x8;
    M2C_FIELD(player, s32 *, 0x11C) = 0;
    M2C_FIELD(player, s32 *, 0x134) = loopStart;
    M2C_FIELD(player, s32 *, 0x138) = loopEnd;
    M2C_FIELD(player, s32 *, 0x13C) = streamCallback;
    M2C_FIELD(player, s32 *, 0x140) = streamArg;
    M2C_FIELD(player, s32 *, 0x144) = startPos;
    M2C_FIELD(player, s32 *, 0x15C) = 0;
    M2C_FIELD(player, s32 *, 0x154) = *(u8 *)((u8 *)pb + 4);
    M2C_FIELD(player, s32 *, 0x158) = 0x7F;
    func_0202eec0((u8 *)player + 0xE8);
    func_0202eed8((u8 *)player + 0xE8, 0x7F00, 1);

    playType = M2C_FIELD(player, u8 *, 0xC0);
    switch (playType) { case 0: playMode = 0; break; case 1: case 2: playMode = 1; break; }

    channels = M2C_FIELD(player, u8 *, 0xC2);
    if (*(u8 *)((u8 *)pb + 7) & 0x1) {
        channels = 2;
    }
    if (channels > M2C_FIELD(player, u8 *, 0x124)) {
        channels = M2C_FIELD(player, u8 *, 0x124);
    }
    M2C_FIELD(player, u32 *, 0x110) = (M2C_FIELD(player, u32 *, 0x110) & ~0x40) | ((u32)((channels == 1) << 31) >> 25);

    if (Sound_AcquireChannel(player, channels, (s32)((u8 *)player + 0x126)) == 0) {
        M2C_FIELD(player, void (**)(void *), 0x168)(player);
        Sound_ReleasePlayer(player);
        return 0;
    }

    {
        s32 scaledSize = M2C_FIELD(player, s32 *, 0x130) * channels;
        s32 channelBytes = (s32)func_020722fc((u32)scaledSize, (u32)M2C_FIELD(player, u8 *, 0x124));
        if (Sound_StartVoice(player, playMode, M2C_FIELD(player, s32 *, 0x12C), channelBytes, M2C_FIELD(player, u16 *, 0xC6), 4, (M2C_UNK)func_0202e1f4, (M2C_UNK)player) == 0) {
            Sound_ReleaseChannel(player);
            M2C_FIELD(player, void (**)(void *), 0x168)(player);
            Sound_ReleasePlayer(player);
            return 0;
        }
    }

    if (channels == 2) {
        Sound_SetChannelVolume(player, 0, (M2C_UNK)0);
        Sound_SetChannelVolume(player, 1, (M2C_UNK)0x7F);
    }

    return 1;
}

void func_0202de1c(void *arg0, s32 arg1) {
 void func_0202de74(void *);
 void func_0202eed8(void *, s32, s32);
 s32 flags = M2C_FIELD(arg0, s32 *, 0x110);
 s32 saved = arg1;
 if (((flags << 30) >> 31) == 0) {
  func_0202de74(arg0);
  return;
 }
 if (arg1 == 0) {
  func_0202de74(arg0);
  return;
 }
 func_0202eed8((u8 *)arg0 + 0xe8, 0, arg1);
 M2C_FIELD(arg0, s32 *, 0x110) |= 8;
 M2C_FIELD(arg0, s32 *, 0x150) = 0;
}

void func_0202de74(void *arg0) {
    M2C_UNK func_02006564(M2C_UNK *);
    M2C_UNK func_020065e8(M2C_UNK *);
    M2C_UNK func_0202b760(void *);
    M2C_UNK func_0202df0c(void *);
    extern M2C_UNK data_0213c290;
    extern M2C_UNK data_0213c908;
    func_02006564(&data_0213c908);
    if (M2C_FIELD(&data_0213c290, s32 *, 4) != 0) {
        func_02006564(M2C_FIELD(&data_0213c290, s32 *, 4) + 0x4C8);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1E) >> 0x1F) != 0) {
        func_0202b760(arg0);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1F) >> 0x1F) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x170)(arg0);
    }
    func_0202df0c(arg0);
    func_020065e8(&data_0213c908);
    if (M2C_FIELD(&data_0213c290, s32 *, 4) == 0) {
        return;
    }
    func_020065e8(M2C_FIELD(&data_0213c290, s32 *, 4) + 0x4C8);
}

M2C_UNK func_0202df0c(void *arg0) {
void func_0202e02c(M2C_UNK,void *); void Sound_ReleasePlayer(void *);
extern M2C_UNK data_0213c920; extern M2C_UNK data_0213c290;
if((M2C_FIELD(arg0,s32 *,0x110)<<31)>>31==0) return;
Sound_ReleaseChannel(arg0);
M2C_FIELD(arg0,void (**)(void *),0x168)(arg0);
func_0202e02c((M2C_UNK)&data_0213c920,arg0);
if(M2C_FIELD(&data_0213c290,void **,4)) func_0202e02c((M2C_UNK)((u8 *)M2C_FIELD(&data_0213c290,void **,4)+0x4e0),arg0);
Sound_ReleasePlayer(arg0);
}

s32 Sound_AcquireChannel(void *arg0,s32 arg1,s32 arg2) {
s32 func_0202b4e4(void *,s32,s32);
if(M2C_FIELD(arg0,s32 *,0x120)==0 && func_0202b4e4(arg0,arg1,arg2)==0) return 0;
M2C_FIELD(arg0,s32 *,0x120)++; return 1;
}

void Sound_ReleaseChannel(void *arg0) {
    M2C_UNK func_0202b544();
    s32 temp_r1;
    s32 temp_r1_2;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x120);
    if (temp_r1 == 0) {
        return;
    }
    temp_r1_2 = temp_r1 - 1;
    M2C_FIELD(arg0, s32 *, 0x120) = temp_r1_2;
    if (temp_r1_2 != 0) {
        return;
    }
    func_0202b544();
}

void func_0202dfcc(void *arg0, s32 arg1) {
    M2C_UNK func_02005ac0(void *, M2C_UNK *, void *, s32, s32, s32);
    M2C_UNK TaskWake(void *);
    M2C_UNK func_0200654c(void *);
    M2C_UNK func_02029c30(void *, M2C_UNK);
    extern M2C_UNK func_0202ee30;
    func_02005ac0(arg0, &func_0202ee30, arg0, arg0 + 0x4C0, 0x400, arg1);
    func_02029c30(arg0 + 0x4E0, 0);
    func_0200654c(arg0 + 0x4C8);
    M2C_FIELD(arg0, s32 *, 0x4C4) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C0) = 0;
    TaskWake(arg0);
}

void func_0202e02c(M2C_UNK arg0,void *arg1) {
s32 OS_DisableInterrupts(void); M2C_UNK OS_RestoreInterrupts(s32);
void *func_02029ddc(M2C_UNK,M2C_UNK); M2C_UNK func_02029d7c(M2C_UNK,void *);
s32 saved; void *node,*next;
saved=OS_DisableInterrupts();
node=func_02029ddc(arg0,0);
while(node) {
next=func_02029ddc(arg0,(M2C_UNK)node);
if(M2C_FIELD(node,void **,8)==arg1) {func_02029d7c(arg0,node);func_0202e12c((M2C_UNK)node);}
node=next;
}
OS_RestoreInterrupts(saved);
}

void *func_0202e09c(M2C_UNK arg0) {
    M2C_UNK func_02029d7c(M2C_UNK, void *);
    void *func_02029ddc(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    void *temp_r0;
    void *temp_r1;

    temp_r4 = OS_DisableInterrupts();
    temp_r0 = func_02029ddc(arg0, 0);
    if (temp_r0 != NULL) {
        func_02029d7c(arg0, temp_r0);
        temp_r1 = M2C_FIELD(temp_r0, void **, 8);
        M2C_FIELD(temp_r1, s32 *, 0x11C) = (s32) (M2C_FIELD(temp_r1, s32 *, 0x11C) - 1);
    }
    OS_RestoreInterrupts(temp_r4);
    return temp_r0;
}

#pragma opt_common_subs off
M2C_UNK func_0202e0ec(void) {
extern M2C_UNK data_0213c29c[];
s32 saved; M2C_UNK node;
saved=OS_DisableInterrupts();
node=(M2C_UNK)func_02029ddc((M2C_UNK)data_0213c29c,0);
if(node!=0) func_02029d7c((M2C_UNK)&data_0213c29c,(void *)node);
OS_RestoreInterrupts(saved);
return node;
}
#pragma opt_common_subs reset
void func_0202e12c(M2C_UNK arg0) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK func_02029c74(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0213c29c[];
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    func_02029c74(data_0213c29c, arg0);
    OS_RestoreInterrupts(temp_r4);
}

void func_0202e158(s32 arg0,s32 arg1,void *arg2) {
M2C_UNK func_02006564(M2C_UNK *); M2C_UNK func_020065e8(M2C_UNK *); M2C_UNK func_0202b544();
extern M2C_UNK data_0213c290; extern M2C_UNK data_0213c908;
if(arg0!=M2C_FIELD(arg2,s32 *,0x12c)) return;
func_02006564(&data_0213c908);
if(M2C_FIELD(&data_0213c290,s32 *,4)) func_02006564(M2C_FIELD(&data_0213c290,s32 *,4)+0x4c8);
func_0202de74(arg2);
M2C_FIELD(arg2,s32 *,0x12c)=0; M2C_FIELD(arg2,s32 *,0x130)=0; M2C_FIELD(arg2,u8 *,0x124)=0;
if(M2C_FIELD(arg2,s32 *,0x120)>0) {
func_0202b544(arg2); M2C_FIELD(arg2,s32 *,0x120)=0;
}
func_020065e8(&data_0213c908);
if(!M2C_FIELD(&data_0213c290,s32 *,4)) return;
func_020065e8(M2C_FIELD(&data_0213c290,s32 *,4)+0x4c8);
}

void func_0202e1f4(M2C_UNK arg0, s32 arg1, M2C_UNK *arg2, M2C_UNK arg3, void *arg4) {
    M2C_UNK func_02029ddc(M2C_UNK, M2C_UNK);
    M2C_UNK func_02029d7c(M2C_UNK, void *);
    void func_0202e12c(M2C_UNK);
    M2C_UNK func_0202e0ec(void);
    M2C_UNK func_02029c74(M2C_UNK *, M2C_UNK);
    void func_02005df4(void *);
    void func_02007f8c(void *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213c920;
    extern M2C_UNK data_0213c440;
    extern M2C_UNK data_0213c290;

    M2C_UNK node;
    void *base;
    s32 i;
    s32 n;

    if (M2C_FIELD(arg4, s32 *, 0x11c) >= 2) {
        node = func_02029ddc((M2C_UNK)&data_0213c920, 0);
        if (node != 0 && *(void **)((u8 *)node + 8) != arg4) {
            do {
                node = func_02029ddc((M2C_UNK)&data_0213c920, node);
            } while (node != 0 && *(void **)((u8 *)node + 8) != arg4);
        }
        if (node != 0) {
            n = *(s32 *)((u8 *)node + 0x10);
            if (n > 0) {
                i = 0;
                while (i < n) {
                    func_02007f8c(*(void **)((u8 *)node + 0x14 + i * 4), (M2C_UNK)i, *(M2C_UNK *)((u8 *)node + 0x2c));
                    i++;
                }
            }
        }
        func_02029d7c((M2C_UNK)&data_0213c920, (void *)node);
        *(s32 *)((u8 *)arg4 + 0x11c) = *(s32 *)((u8 *)arg4 + 0x11c) - 1;
        func_0202e12c(node);
    }

    node = func_0202e0ec();
    *(void **)((u8 *)node + 8) = arg4;
    *(M2C_UNK *)((u8 *)node + 0xc) = arg0;
    *(s32 *)((u8 *)node + 0x10) = arg1;
    if (arg1 > 0) {
        i = 0;
        while (i < arg1) {
            *(M2C_UNK *)((u8 *)node + 0x14 + i * 4) = arg2[i];
            i++;
        }
    }
    *(M2C_UNK *)((u8 *)node + 0x2c) = arg3;

    if (arg0 == 0) {
        void *t = *(void **)((u8 *)&data_0213c290 + 4);
        if (t != 0) {
            base = t;
        } else {
            base = (void *)&data_0213c440;
        }
    } else {
        base = (void *)&data_0213c440;
    }
    *(s32 *)((u8 *)arg4 + 0x11c) = *(s32 *)((u8 *)arg4 + 0x11c) + 1;
    func_02029c74((M2C_UNK *)((u8 *)base + 0x4e0), node);
    func_02005df4((void *)((u8 *)base + 0x4c0));
}

void func_0202e32c(void *arg0) {
    void *self = arg0;
    s32 *func_0202c1cc(s32);
    M2C_UNK Sound_SetPlayerCallbacks(void *, s32);
    u64 func_02072088(u64, u64);
    s32 *temp;
    u8 temp_r6;
    u16 temp_r7;
    s32 sp[4];

    sp[2] = M2C_FIELD(self, s32 *, 0x148);
    sp[3] = M2C_FIELD(self, s32 *, 0x144);
    sp[0] = M2C_FIELD(self, s32 *, 0x144);
    sp[1] = 0;
    if (M2C_FIELD(self, s32 (**)(M2C_UNK, s32 *, s32 *, s32), 0x13C)(0, &sp[2], &sp[0], M2C_FIELD(self, s32 *, 0x140)) == 0) {
        return;
    }
    temp = func_0202c1cc(sp[0]);
    if (temp == 0) {
        return;
    }
    temp_r6 = M2C_FIELD(self, u8 *, 0xC0);
    temp_r7 = M2C_FIELD(self, u16 *, 0xC4);
    M2C_FIELD(self, M2C_UNK (**)(void *), 0x168)(self);
    Sound_SetPlayerCallbacks(self, *temp);
    if (M2C_FIELD(self, s32 (**)(void *, s32), 0x164)(self, *temp) == 0) {
        return;
    }
    if (temp_r7 != M2C_FIELD(self, u16 *, 0xC4)) {
        return;
    }
    if (temp_r6 == 0 && M2C_FIELD(self, u8 *, 0xC0) != 0) {
        return;
    }
    if (temp_r6 != 0 && M2C_FIELD(self, u8 *, 0xC0) == 0) {
        return;
    }
    M2C_FIELD(self, s32 *, 0x144) = sp[0];
    M2C_FIELD(self, s32 *, 0x160) = (s32)func_02072088((u64)(u32)M2C_FIELD(self, u16 *, 0xC4) * (u32)sp[1], 0x3E8ULL);
    if (M2C_FIELD(self, s32 *, 0x160) != 0 && M2C_FIELD(self, u8 *, 0xC0) == 2) {
        M2C_FIELD(self, s32 *, 0x110) = (M2C_FIELD(self, s32 *, 0x110) | 0x10);
    } else {
        M2C_FIELD(self, s32 *, 0x110) = (M2C_FIELD(self, s32 *, 0x110) & ~0x10);
    }
    M2C_FIELD(self, s32 *, 0x110) = (M2C_FIELD(self, s32 *, 0x110) & ~0x20);
}

