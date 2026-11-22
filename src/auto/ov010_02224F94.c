/* 29 functions from 0x02224F94 to 0x02225F60 (ov010), found by ds-decomp. */
#include "common.h"
extern s16 data_ov010_0222c03c[];
extern s16 data_ov010_0222ddb4[];
extern s32 data_ov010_0222d95c[];
extern s32 data_ov010_0222d944[];
extern s32 data_ov010_0222d920[4];
extern s32 data_ov010_0222d914;

#pragma opt_strength_reduction off
s32 func_ov010_02224f94(s32 a, u32 b, u8 *c) {
 extern s32 data_ov010_0222c02c;
 volatile u16 *ctl=(volatile u16 *)0x40002b0;
 volatile u32 *result=(volatile u32 *)0x40002b4;
 volatile u32 *in=(volatile u32 *)0x40002b8;
 u32 sum,h; s32 cur,i,next; u32 j; s32 ret; s32 k;
 M2C_FIELD(&data_ov010_0222c02c,s32 *,4)=b>>8;
 if(c) *c=b>>8;
 if(M2C_FIELD(&data_ov010_0222c02c,s32 *,0)==0) {
 sum=0; for(i=0;i<4;i++) sum+=M2C_FIELD(&data_ov010_0222d920,u32 *,i*4);
 *ctl=0; *in=sum>>2; while(*ctl&0x8000){}
 h=*result;
 if(b!=0 && b>=h*2) {
 sum=0; for(j=0;j<4;j++) sum+=M2C_FIELD(&data_ov010_0222d920,u32 *,j*4);
 *ctl=0; *in=sum>>2; while(*ctl&0x8000){}
 h=*result;
 M2C_FIELD(&data_ov010_0222d914,s32 *,0)=h*3/2;
 M2C_FIELD(&data_ov010_0222d914,s32 *,4)=0;
 ret=1; M2C_FIELD(&data_ov010_0222c02c,s32 *,0)=ret;
 } else ret=0;
 cur=M2C_FIELD(&data_ov010_0222d914,s32 *,4);
 next=(cur+1)&3;
 M2C_FIELD(&data_ov010_0222d920,s32 *,cur*4)=a;
 M2C_FIELD(&data_ov010_0222d914,s32 *,4)=next;
 } else {
 sum=0; i=0;
 cur=M2C_FIELD(&data_ov010_0222d914,s32 *,4);
 next=(cur+1)&3;
 M2C_FIELD(&data_ov010_0222d920,s32 *,cur*4)=a;
 M2C_FIELD(&data_ov010_0222d914,s32 *,4)=next;
 for(k=0;k<4;k++) sum+=M2C_FIELD(&data_ov010_0222d920,u32 *,k*4);
 *ctl=0; *in=sum>>2; while(*ctl&0x8000){}
 h=*result;
 if(h<=(u32)M2C_FIELD(&data_ov010_0222d914,s32 *,0)) {
 M2C_FIELD(&data_ov010_0222d914,s32 *,8)++;
 if(M2C_FIELD(&data_ov010_0222d914,s32 *,8)>M2C_FIELD(&data_ov010_0222c02c,s32 *,8)){
 M2C_FIELD(&data_ov010_0222c02c,s32 *,0)=0;
 M2C_FIELD(&data_ov010_0222d914,s32 *,8)=0;
 M2C_FIELD(&data_ov010_0222d914,s32 *,4)=0;
 return 3;
 }
 } else M2C_FIELD(&data_ov010_0222d914,s32 *,8)=0;
 ret=2;
 }
 return ret;
}
#pragma opt_strength_reduction reset
void func_ov010_02225174(void) {
 void func_ov010_02224f28(void);
 extern s32 data_ov010_0222c02c;
 s16 n;
 M2C_FIELD(&data_ov010_0222c02c,s32 *,8)=15;
 n=M2C_FIELD(&data_ov010_0222c02c,s32 *,8);
 M2C_FIELD(&data_ov010_0222c02c,s32 *,12)=n*(s16)0x44;
 func_ov010_02224f28();
}

#pragma opt_instruction_scheduling off
s32 func_ov010_0222519c(s16 *a,u32 bytes){
extern s32 data_ov010_0222d930;
s32 input,value,prev,square;u32 n,i;s64 sum;
input=a[0]*(s16)0xe9f;
value=(input+M2C_FIELD(&data_ov010_0222d930,s32 *,4)+M2C_FIELD(&data_ov010_0222d930,s32 *,16)*0xd3e)>>12;
square=value*value;n=bytes>>1;
M2C_FIELD(&data_ov010_0222d930,s32 *,16)=value;
prev=-input;M2C_FIELD(&data_ov010_0222d930,s32 *,4)=prev;
sum=square;
for(i=1;i<n;i++){
input=a[i]*(s16)0xe9f;
prev=input+prev+value*0xd3e;
a[i-1]=value;
value=prev>>12;
square=value*value;sum+=square;prev=-input;
}
M2C_FIELD(&data_ov010_0222d930,s32 *,4)=prev;
M2C_FIELD(&data_ov010_0222d930,s32 *,16)=value;
*(s16 *)((char *)a+n*2-2)=value;
*(volatile u16 *)0x4000280=1;
*(volatile s64 *)0x4000290=sum;
*(volatile u64 *)0x4000298=n;
while(*(volatile u16 *)0x4000280&0x8000){}
return *(volatile s32 *)0x40002a0;
}
#pragma opt_instruction_scheduling reset
/* Reset the voice codec's filter state: clear the sample history buffer, rewind
 * the two history indices (read at 0x19D, write at 0) and load the initial tap
 * coefficients into the two tap registers. */
void VoiceCodec_ResetState(void) {
    extern s32 data_ov010_0222d930;
    s16 *defaultTaps = data_ov010_0222c03c;
    s32 i, tap;
    M2C_FIELD(&data_ov010_0222d930, s32 *, 12) = 0;
    M2C_FIELD(&data_ov010_0222d930, s32 *, 8) = 0x19D;
    for (i = 0; i < 0x800; i++) data_ov010_0222ddb4[i] = 0;
    for (tap = 0; tap < 6; tap++) {
        data_ov010_0222d95c[tap] = 0;
        data_ov010_0222d944[tap] = defaultTaps[tap];
    }
}

void func_ov010_02225304(M2C_UNK arg0, M2C_UNK arg1) {
M2C_UNK MI_CpuCopy32(M2C_UNK,M2C_UNK *,M2C_UNK);
extern M2C_UNK data_ov010_0222d974;
MI_CpuCopy32(arg0,&data_ov010_0222d974,arg1);
}

void func_ov010_0222531c(M2C_UNK arg0, M2C_UNK *arg1, M2C_UNK arg2, M2C_UNK arg3) {
    extern M2C_UNK data_ov010_0222d930;
    volatile u16 *hw0 = (volatile u16 *) 0x4000280;
    volatile u32 *hw1 = (volatile u32 *) 0x40002a0;
    volatile u32 *hw2 = (volatile u32 *) 0x40002b4;
    M2C_UNK *g;
    M2C_UNK *g2 = arg1;
    s16 *buf = (s16 *) arg0;
    s16 *tab = (s16 *) data_ov010_0222ddb4;
    u32 count = (u32) arg2 >> 1;
    s64 sum = 0;
    u32 idx = 0;
    s32 lr = 0x3fff8000;

    #pragma opt_loop_invariants off
if (count == 0) goto tail1;

    do {
        s32 r4, a,b,c,d,e,r9,r10,r5v; volatile s32 old; u32 r7,sp0;
        s16 r6;

        g = (M2C_UNK *)&data_ov010_0222d930;
        r4 = idx << 1;
        r7 = M2C_FIELD(g, volatile s32 *, 0xc);
        r6 = ((s16 *) g2)[idx];
        tab[r7] = r6;
        r4 = M2C_FIELD(g, volatile s32 *, 0x8);
        sp0 = r4;
        r6 = tab[r4];
        M2C_FIELD(g, volatile s32 *, 0x2c) = r6;

        r9 = M2C_FIELD(g, volatile s32 *, 0x3c);
        r10 = M2C_FIELD(g, volatile s32 *, 0x24);
        r5v = M2C_FIELD(g, volatile s32 *, 0x40);
        r10 = r10 * r9;
        a = M2C_FIELD(g, volatile s32 *, 0x28);
        old = r9; a = r5v * a + r10;
        M2C_FIELD(g, volatile s32 *, 0x40) = old;
        r9 = M2C_FIELD(g, volatile s32 *, 0x38);
        b = M2C_FIELD(g, volatile s32 *, 0x20);
        b = r9 * b + a;
        M2C_FIELD(g, volatile s32 *, 0x3c) = r9;
        r9 = M2C_FIELD(g, volatile s32 *, 0x34);
        c = M2C_FIELD(g, volatile s32 *, 0x1c);
        b = r9 * c + b;
        M2C_FIELD(g, volatile s32 *, 0x38) = r9;
        r9 = M2C_FIELD(g, volatile s32 *, 0x30);
        d = M2C_FIELD(g, volatile s32 *, 0x18);
        b = r9 * d + b;
        M2C_FIELD(g, volatile s32 *, 0x34) = r9;
        e = M2C_FIELD(g, volatile s32 *, 0x14);
        r4 = r6 * e + b;
M2C_FIELD(g,s32 *,0x30)=r6;
        if (r4 > lr) r4 = lr;
        else if (r4 < (s32)0xc0000000) r4 = 0xc0000000u;
        r7 = r7 + 1;
        r7 = r7 & ((u32)lr >> 19);
        M2C_FIELD(g, volatile s32 *, 0xc) = r7;
        sp0 = sp0 + 1;
        sp0 = sp0 & ((u32)lr >> 19);
        M2C_FIELD(g, volatile s32 *, 0x8) = sp0;
        r4 = r4 >> 15;
        ((s16 *) g2)[idx] = (s16) r4;
        {
            s16 q = ((s16 *)g2)[idx];
            ((s16 *)g2)[idx]=buf[idx];
            sum += q*q;
        }
        idx++;
    } while (idx < count);

tail1:
#pragma opt_common_subs off

    hw0[0] = 1;
    *(volatile u32 *) ((char *) hw0 + 0x10) = (u32)sum;
    *(volatile u32 *) ((char *) hw0 + 0x14) = (u32)(sum>>32);
    *(volatile u32 *) ((char *) hw0 + 0x18) = count;
    *(volatile u32 *) ((char *) hw0 + 0x1c) = 0;
    {
        u32 t;
        do {
            t = hw0[0];
        } while (t & 0x8000);
    }
    {
        u32 t0 = hw1[0];
        ((volatile u16 *) hw1)[0x10 >> 1] = 0;
        hw1[0x18 >> 2] = t0;
        {
            u32 t;
            do {
                t = ((volatile u16 *) hw1)[0x10 >> 1];
            } while (t & 0x8000);
        }
    }
    {
        u32 r4v = hw2[0];
        u32 r1v = r4v + (r4v << 1);
        u32 thr = (u32) arg3 << 1;
        if (r1v < thr) {
            *(volatile u16 *) ((M2C_UNK *)&data_ov010_0222d930) = 0;
            return;
        }
        if ((u32) arg3 < r4v) {
            *(volatile u16 *) ((M2C_UNK *)&data_ov010_0222d930) = 4;
        }
        {
            s32 t = *(volatile s16 *) ((M2C_UNK *)&data_ov010_0222d930);
            if (t < 4) {
                t++;
                *(volatile s16 *) ((M2C_UNK *)&data_ov010_0222d930) = (s16) t;
            }
        }
        if (count > 0) {
            u32 r5v = 0;
            do {
                s32 r4b = (s32) *(volatile s16 *) ((M2C_UNK *)&data_ov010_0222d930);
                s32 v = buf[r5v];
                v = v >> r4b;
                buf[r5v] = (s16) v;
                r5v++;
            } while (r5v < count);
        }
    }
#pragma opt_common_subs reset
}

void func_ov010_02225538(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2) {
 void func_ov010_0222531c(M2C_UNK,M2C_UNK *,M2C_UNK,M2C_UNK);
 extern M2C_UNK data_ov010_0222d974;
 func_ov010_0222531c(arg0,&data_ov010_0222d974,arg1,arg2);
}

/* Add two signed 16-bit sample buffers into `out`, four samples a turn, clamping
 * every sum to the 16-bit range; `size` is the buffer size in bytes. */
void func_ov010_02225558(s16 *a,s16 *b,s16 *out,u32 size){
u32 i; s32 v;
for(i=0;i<(size>>1);i+=4){
v=a[i+0]+b[i+0];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+0]=v;
v=a[i+1]+b[i+1];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+1]=v;
v=a[i+2]+b[i+2];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+2]=v;
v=a[i+3]+b[i+3];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+3]=v;
}
}

s32 func_ov010_02225640(void *arg) {
    void func_02000b9c(s32);
    s32 VoiceLink_InitPacketPool(void *, u32);
    M2C_UNK func_ov010_02224ea0();
    s32 VoiceLink_Init(void *);
    s32 func_ov010_022224b4(void);
    M2C_UNK func_ov010_02224270();
    void MI_CpuFill8(void *, u32, u32);
    extern M2C_UNK data_ov010_0222edb4;
    extern M2C_UNK gLinkConfig;
    s32 kind;
    u8 b;
    s32 t;
    func_02000b9c(0x2000c6c);
    if (!arg) return 0;
    if (M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) != 0) return 1;
    kind = M2C_FIELD(arg, s32 *, 8);
    if (kind != 1 && kind != 2 && kind != 3) return 0;
    if (!M2C_FIELD(arg, s32 *, 0x18)) return 0;
    t = M2C_FIELD(arg, s32 *, 0x10);
    if (!t || !M2C_FIELD(arg, s32 *, 0x14)) return 0;
    if (t % 32 != 0) return 0;
    MI_CpuFill8(&gLinkConfig, 0, 0x18);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x10) = M2C_FIELD(arg, s32 *, 0x18);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x14) = M2C_FIELD(arg, s32 *, 0x1C);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x1C) = M2C_FIELD(arg, s32 *, 8);
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x18) = 0;
    b = (u8)M2C_FIELD(arg, u8 *, 0xC);
    if ((u32)b >= 0x20) return 0;
    M2C_FIELD(&data_ov010_0222edb4, u8 *, 0xC) = b;
    {
        s32 r = VoiceLink_InitPacketPool(M2C_FIELD(arg, void **, 0x10), M2C_FIELD(arg, u32 *, 0x14));
        if (!r) { func_ov010_02224ea0(); return 0; }
    }
    {
        s32 r = VoiceLink_Init(arg);
        if (!r) { func_ov010_02224ea0(); return 0; }
    }
    {
        s32 r = func_ov010_022224b4();
        if (r) {
            M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) = 1;
            return 1;
        }
    }
    func_ov010_02224270();
    func_ov010_02224ea0();
    return 0;
}

void func_ov010_02225778(void) {
    M2C_UNK func_ov010_022225b0();
    M2C_UNK func_ov010_02224270();
    M2C_UNK func_ov010_02224ea0();
    extern M2C_UNK data_ov010_0222edb4;
    func_ov010_022225b0();
    func_ov010_02224270();
    func_ov010_02224ea0();
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) = 0;
}

void func_ov010_022257a0(void) {
extern s32 data_ov010_0222edb4;
void VoiceLink_CheckTimeout(void);
s32 func_ov010_022231d4(void);
void func_ov010_02223114(void);
if(!M2C_FIELD(&data_ov010_0222edb4,s32 *,8))return;
if(!(++data_ov010_0222edb4 & 15))VoiceLink_CheckTimeout();
if(func_ov010_022231d4())func_ov010_02223114();
}

/* Feed one incoming voice-chat packet to the dispatcher; when it carried audio
 * (dispatcher result 1) hand the decoded left/right samples to the registered
 * stream callback.  Returns 0 for a packet with the wrong magic, 1 otherwise. */
s32 VoiceChat_ReceivePacket(s32 peer, s32 packet, s32 length) {
    s32 VoiceChat_DispatchPacket(s32, s32, s32, s32 *);
    extern s32 data_ov010_0222edb4;
    s32 samples[2];
    s32 result = VoiceChat_DispatchPacket(peer, packet, length, samples);

    switch (result) {
    case 0:
        break;
    case 1:
        ((void (*)(s32, s32, s32, s32))M2C_FIELD(&data_ov010_0222edb4, s32 *, 16))(peer, samples[0], samples[1], M2C_FIELD(&data_ov010_0222edb4, s32 *, 20));
        return 1;
    case 2:
        return 0;
    }
    return 1;
}

#pragma opt_instruction_scheduling off
s32 VoiceChat_DispatchPacket(s32 a,s32 b,s32 c,s32 *out) {
extern s32 data_ov010_0222edb4;
u64 GetSystemTick(void);
void func_ov010_02222f28(s32,s32,s32,u64);
s32 VoiceLink_HandlePacket(s32,s32,s32,s32 *);
u64 now; register u32 kind, family; s32 *state;
if(!b)return 0;
if(M2C_FIELD(b,u32*,0)!=0x5f564354)return 2;
if(!M2C_FIELD(&data_ov010_0222edb4,s32*,28)||!M2C_FIELD(&data_ov010_0222edb4,s32*,8))return 0;
out[0]=0;out[1]=0;
now=GetSystemTick();
kind=M2C_FIELD(b,u8*,4);
family = kind & 0xf0;
if (family == 0x40) {
state=&data_ov010_0222edb4;
state[1]=state[1]+1;
func_ov010_02222f28(a,b,c,now);
return 0;
} else if (kind == 0 || kind == 255) return VoiceLink_HandlePacket(a,b,c,out)!=0;
return 0;
}
#pragma opt_instruction_scheduling reset
void func_ov010_02225934(void) {
 extern s32 gStreamVoiceState;
 M2C_FIELD(&gStreamVoiceState,s32 *,0x10)=1;
}

void func_ov010_02225948(void) {
void func_ov010_02224f28(void);
extern s32 gStreamVoiceState;
func_ov010_02224f28();
M2C_FIELD(&gStreamVoiceState,s32 *,16)=0;
}

/* Segment callback of the streaming voice player (installed by
 * StartStreamedVoice).  On the voice's very first segment it only silences every
 * note's sample buffer.  On each later segment it flips between the two sample
 * buffers of the voice, fills the one being played with the next received link
 * packet, sends the finished buffer back over the link, and flushes the written
 * buffers and invalidates the one it hands to the link.  `altBuffer` is the
 * callback's SOUND_PLAYER_CB_ARG, the voice's alternate sample buffer. */
void RefillStreamedVoiceSegment(s32 mode, s32 noteCount, s32 *noteOffsets, s32 segmentBytes, s32 playMode, s32 altBuffer) {
    extern s32 gStreamVoiceState;
    extern s32 data_ov010_0222edf8;
    void func_ov010_02225934(void);
    void MI_CpuFill8(void *, u32, u32);
    void Arm7TransferStart(void *, void *, u32);
    s32 func_0200dfa8(void);
    void *VoiceStream_ReceiveAudio(void *, s32, s32);
    void VoiceStream_SendAudio(s32, s32);
    void DC_FlushRange(void *, s32);
    void DC_InvalidateRange(s32, s32);

    s32 pos;
    u32 elapsed;
    s32 changed;
    s32 i;
    s32 zero;

    if (mode == 0) {
        i = 0;
        if (noteCount <= 0) {
            return;
        }
        zero = i;
        do {
            MI_CpuFill8((void *)noteOffsets[i], zero, segmentBytes);
            i++;
        } while (i < noteCount);
        return;
    }

    if (M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_ACTIVE) != 0) {
        if (M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_PAUSED) == 0) {
            Arm7TransferStart(&data_ov010_0222edf8, (void *)func_ov010_02225934, 0);
            M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_ACTIVE) = 0;
        }
    }

    pos = *(volatile s32 *)&altBuffer;
    elapsed = (u32)func_0200dfa8() - (u32)pos;
    changed = 0;
    if ((u32)elapsed < (u32)segmentBytes) {
        if (M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_FLIP) != 0) {
            M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_FLIP) = changed;
            pos += segmentBytes;
            changed = 1;
        }
    } else {
        if (M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_FLIP) != 1) {
            changed = 1;
            M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_FLIP) = 1;
        }
    }

    M2C_FIELD(&gStreamVoiceState, s32 *, STREAM_VOICE_DATA_READY) = (s32)VoiceStream_ReceiveAudio((void *)noteOffsets[0], segmentBytes, 0);

    if (changed) {
        VoiceStream_SendAudio(pos, segmentBytes);
    }

    i = 0;
    if (i < noteCount) {
        do {
            DC_FlushRange((void *)noteOffsets[i], segmentBytes);
            i++;
        } while (i < noteCount);
    }

    if (changed) {
        DC_InvalidateRange(pos, segmentBytes);
    }
}

#pragma push
#pragma optimization_level 2
/* Allocates the two sample buffers of the streaming voice, configures its sound
 * player and starts the voice, letting the given refill callback feed the
 * buffers; the length is in milliseconds. */
s32 StartStreamedVoice(M2C_UNK *refillCallback, M2C_UNK lengthMs) {
extern s32 gStreamVoiceState;
extern s32 gStreamSoundPlayer;
extern const u8 gStreamChannels[];
void Arm7TransferInit(void);
void Arm7CommandInit(void);
void func_0200e868(s32);
void func_0200e880(s32);
s32 AllocAlignedBuffer(s32,s32);
void FreeBuffer(s32,s32);
void Sound_InitPlayer(void *);
void Sound_AssignPlayerChannels(void *,s32,u8 *);
void Sound_SetPlayerVolume(void *,s32);
void func_0202b7e8(void *,s32,s32);
s32 Sound_StartVoice(void *,s32,s32,s32,s32,s32,void *,s32);
u8 channelList[1];
u8 *channelCursor;
u32 channelIndex;
u32 sampleBytes;
s32 bufferSize;
s32 result;
s32 buffer2;
u8 channel;
Arm7TransferInit();Arm7CommandInit();func_0200e868(1);func_0200e880(3);
sampleBytes=((u32)(lengthMs*8000)*2)/1000;
bufferSize=sampleBytes*2;
M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1_SIZE)=sampleBytes*4;M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2_SIZE)=bufferSize;
if(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1)==0){
M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1)=AllocAlignedBuffer(sampleBytes*4,32);
if(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1)==0){FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1),M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1_SIZE));M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1)=0;FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2),M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2_SIZE));M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2)=0;return 0;}
}
buffer2=M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2);
if(buffer2==0){
buffer2=AllocAlignedBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2_SIZE),32);
M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2)=buffer2;
if(buffer2==0){FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1),M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1_SIZE));M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1)=0;FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2),M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2_SIZE));M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2)=0;return 0;}
}
M2C_FIELD(&gStreamVoiceState,s32 *,0)=0;M2C_FIELD(&gStreamVoiceState,s32 *,0x20)=3;M2C_FIELD(&gStreamVoiceState,s32 *,0x24)=buffer2;M2C_FIELD(&gStreamVoiceState,s32 *,0x28)=M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2_SIZE);M2C_FIELD(&gStreamVoiceState,s32 *,0x2c)=0x1040;M2C_FIELD(&gStreamVoiceState,s32 *,0x30)=1;channel=gStreamChannels[0];M2C_FIELD(&gStreamVoiceState,s32 *,0x34)=0;M2C_FIELD(&gStreamVoiceState,s32 *,0x38)=0;
M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_ACTIVE)=0;M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_PAUSED)=0;
channelList[0]=channel;
Sound_InitPlayer(&gStreamSoundPlayer);
Sound_AssignPlayerChannels(&gStreamSoundPlayer,1,channelList);
Sound_SetPlayerVolume(&gStreamSoundPlayer,127);
channelCursor=channelList;
channelIndex=0;do {func_0202b7e8(&gStreamSoundPlayer,*channelCursor++,0);channelIndex++;}while(channelIndex<1);
result=Sound_StartVoice(&gStreamSoundPlayer,1,M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1),bufferSize,0x41,2,refillCallback,M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2));
if(result==0){FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1),M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1_SIZE));M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER1)=0;FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2),M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2_SIZE));M2C_FIELD(&gStreamVoiceState,s32 *,STREAM_VOICE_BUFFER2)=0;}
return result;
}
#pragma pop
void func_ov010_02225cd8(void) {
    M2C_UNK StartStreamedVoice(M2C_UNK *, M2C_UNK);
    StartStreamedVoice((void *)&RefillStreamedVoiceSegment, 0x44);
}

s32 IsVoiceDataReady(void) {
    extern s32 gStreamVoiceState;
    return gStreamVoiceState;
}

void func_ov010_02225d00(void) {
extern s32 gStreamSoundPlayer;
void func_0202b70c(void *);
void func_0202a9f0(void);
void func_02004e60(s32,s32);
s32 i;
func_0202b70c(&gStreamSoundPlayer);
for(i=0;i<4;i++){func_0202a9f0();func_02004e60(1,1);}
}

void func_ov010_02225d38(void) {
    M2C_UNK func_0200df70();
    extern M2C_UNK gStreamSoundPlayer;
    func_0200df70();
    Sound_StopIfPlaying(&gStreamSoundPlayer);
}

void EnableVoiceStream(void) {
extern s32 gStreamVoiceState;
M2C_FIELD(&gStreamVoiceState,s32 *,4)=1;
}

void DisableVoiceStream(void) {
extern s32 gStreamVoiceState;
void Arm7TransferEnd(void (*)(void),s32);
Arm7TransferEnd(func_ov010_02225948,0);
M2C_FIELD(&gStreamVoiceState,s32 *,4)=0;
}

s32 func_ov010_02225d8c(void) {
    extern M2C_UNK gStreamVoiceState;
    return M2C_FIELD(&gStreamVoiceState, s32 *, 0x10);
}

s32 func_ov010_02225d9c(void) {
void func_ov010_02224f74(s32 *);
s32 out[4];func_ov010_02224f74(out);return out[0];
}

void func_ov010_02225db8(void) {
extern s32 gStreamSoundPlayer;
extern s32 gStreamVoiceState;
void Sound_StopVoices(void *);
void FreeBuffer(s32,s32);
void func_0200e868(s32);
Sound_StopIfPlaying(&gStreamSoundPlayer);
Sound_StopVoices(&gStreamSoundPlayer);
FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,12),M2C_FIELD(&gStreamVoiceState,s32 *,24));
M2C_FIELD(&gStreamVoiceState,s32 *,12)=0;
FreeBuffer(M2C_FIELD(&gStreamVoiceState,s32 *,28),M2C_FIELD(&gStreamVoiceState,s32 *,20));
M2C_FIELD(&gStreamVoiceState,s32 *,28)=0;
func_0200e868(0);
}

void VoiceChat_DetachContext(s32 a) {
extern s32 gVoiceChatLink;
void VoiceChat_RemoveChannel(s32);
void VoiceLink_ReleaseContext(s32);
if(a==M2C_FIELD(&gVoiceChatLink,s32 *,4)){
VoiceChat_RemoveChannel(a);
VoiceLink_ReleaseContext(a);
M2C_FIELD(&gVoiceChatLink,s32 *,4)=0;
}else VoiceLink_ReleaseContext(a);
}

/* Voice link event callback: event 1 is a peer asking to open an exchange
 * (start one unless another is already attached), events 7/8 attach the
 * exchange's channel, and the remaining events detach and release its context. */
void VoiceLink_HandleEvent(s32 unused, u32 event, VoiceLinkContext *context) {
    M2C_UNK VoiceChat_AttachContext(s32);
    void VoiceLink_ReleaseContext(s32);
    s32 VoiceLink_TrySendStep(s32, M2C_UNK);
    void VoiceChat_DetachContext(s32);
    extern M2C_UNK gVoiceChatLink;

    switch (event) {
    case 1:
        if (M2C_FIELD(&gVoiceChatLink, VoiceLinkContext **, VOICE_CHAT_LINK_CONTEXT) != NULL) {
            VoiceLink_TrySendStep((s32) context, 3);
            VoiceLink_ReleaseContext((s32) context);
            return;
        }
        if (VoiceLink_TrySendStep((s32) context, 0) != 0) {
            VoiceLink_ReleaseContext((s32) context);
            return;
        }
        M2C_FIELD(&gVoiceChatLink, VoiceLinkContext **, VOICE_CHAT_LINK_CONTEXT) = context;
        VoiceChat_AttachContext((s32) context);
        return;
    case 8:
        VoiceLink_TrySendStep((s32) context, 0);
        VoiceChat_DetachContext((s32) context);
        return;
    case 9:
        VoiceChat_DetachContext((s32) context);
        return;
    case 7:
        VoiceChat_AttachContext((s32) context);
        return;
    case 2:
        VoiceChat_DetachContext((s32) context);
        return;
    case 3:
        VoiceChat_DetachContext((s32) context);
        return;
    case 11:
        VoiceChat_DetachContext((s32) context);
        return;
    case 12:
        VoiceChat_DetachContext((s32) context);
        return;
    default:
        break;
    }
}

void func_ov010_02225f54(void) {
    M2C_UNK VoiceChat_ReceivePacket();
    VoiceChat_ReceivePacket();
}
