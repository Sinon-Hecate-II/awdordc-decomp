/* 7 functions from 0x0216FB7C to 0x02170830 (ov001), found by ds-decomp. */
#include "common.h"
#pragma thumb on

#pragma push
#pragma opt_expr_simplify off
/* AES key schedule: expand a 128/192/256-bit key into the round-key words and
   return the number of rounds (10/12/14), or 0 for an unsupported key size. */
s32 AES_KeyExpansion(u32 *w, const u8 *key, s32 keyBits) {
extern s32 gAesRcon; extern M2C_UNK gAesSbox;
s32 round=0; u32 t; s32 *rcon;
w[0]=(key[0]<<24)^(key[1]<<16)^(key[2]<<8)^key[3];
w[1]=(key[4]<<24)^(key[5]<<16)^(key[6]<<8)^key[7];
w[2]=(key[8]<<24)^(key[9]<<16)^(key[10]<<8)^key[11];
w[3]=(key[12]<<24)^(key[13]<<16)^(key[14]<<8)^key[15];
if(keyBits==128){rcon=&gAesRcon;for(;;){t=w[3];
w[4]=w[0]^(M2C_FIELD(&gAesSbox,u32 *,((t>>16)&255)*4)&0xff000000)^(M2C_FIELD(&gAesSbox,u32 *,((t>>8)&255)*4)&0xff0000)^(M2C_FIELD(&gAesSbox,u32 *,(t&255)*4)&0xff00)^(u8)M2C_FIELD(&gAesSbox,u32 *,(t>>24)*4)^rcon[round];
w[5]=w[4]^w[1];
w[6]=w[5]^w[2];
w[7]=w[6]^w[3];
if(++round==10)return 10;
w+=4;}}
w[4]=(key[16]<<24)^(key[17]<<16)^(key[18]<<8)^key[19];
w[5]=(key[20]<<24)^(key[21]<<16)^(key[22]<<8)^key[23];
if(keyBits==192){rcon=&gAesRcon;for(;;){t=w[5];
w[6]=w[0]^(M2C_FIELD(&gAesSbox,u32 *,((t>>16)&255)*4)&0xff000000)^(M2C_FIELD(&gAesSbox,u32 *,((t>>8)&255)*4)&0xff0000)^(M2C_FIELD(&gAesSbox,u32 *,(t&255)*4)&0xff00)^(u8)M2C_FIELD(&gAesSbox,u32 *,(t>>24)*4)^rcon[round];
w[7]=w[6]^w[1];
w[8]=w[7]^w[2];
w[9]=w[8]^w[3];
if(++round==8)return 12;
w[10]=w[4]^w[9];w[11]=w[5]^w[10];
w+=6;}}
w[6]=(key[24]<<24)^(key[25]<<16)^(key[26]<<8)^key[27];
w[7]=(key[28]<<24)^(key[29]<<16)^(key[30]<<8)^key[31];
if(keyBits==256){rcon=&gAesRcon;for(;;){t=w[7];
w[8]=w[0]^(M2C_FIELD(&gAesSbox,u32 *,((t>>16)&255)*4)&0xff000000)^(M2C_FIELD(&gAesSbox,u32 *,((t>>8)&255)*4)&0xff0000)^(M2C_FIELD(&gAesSbox,u32 *,(t&255)*4)&0xff00)^(u8)M2C_FIELD(&gAesSbox,u32 *,(t>>24)*4)^rcon[round];
w[9]=w[8]^w[1];
w[10]=w[9]^w[2];
w[11]=w[10]^w[3];
if(++round==7)return 14;
t=w[11];w[12]=w[4]^(M2C_FIELD(&gAesSbox,u32 *,(t>>24)*4)&0xff000000)^(M2C_FIELD(&gAesSbox,u32 *,((t>>16)&255)*4)&0xff0000)^(M2C_FIELD(&gAesSbox,u32 *,((t>>8)&255)*4)&0xff00)^(u8)M2C_FIELD(&gAesSbox,u32 *,(t&255)*4);w[13]=w[5]^w[12];w[14]=w[6]^w[13];w[15]=w[7]^w[14];
w+=8;}}
return 0;
}
#pragma opt_common_subs off
/* Forward AES encryption of one 16-byte block (128/192/256-bit): initial
 * AddRoundKey, `rounds - 1` rounds through the four T-tables (two rounds per
 * 32-byte key-schedule chunk), then the final round with the S-box only. */
void func_ov001_0216ffc4(void *schedule, s32 rounds, void *input, void *outBlock) {
    extern M2C_UNK gAesTe0;
    extern M2C_UNK gAesTe1;
    extern M2C_UNK gAesTe2;
    extern M2C_UNK gAesTe3;
    extern M2C_UNK gAesSbox;
    s32 te2Val1;
    u32 t1;
    s32 te2Val0;
    s32 rk2Hold;
    s32 sbHi1Hold;
    s32 sbLo1;
    s32 rk1Hold;
    s32 sbHi0Hold;
    s32 sbLo0;
    s32 rk0;
    s32 te2Val3;
    s32 te2Val2;
    u32 t0;
    u32 s0;
    u32 s1;
    s32 roundPairs;
    void *out;
    s32 te2Tmp0;
    s32 te2Tmp1;
    s32 te2Tmp2;
    s32 te2Tmp3;
    s32 sbHi0;
    s32 rk1;
    s32 sbHi1;
    s32 rk2;
    s32 rk3;
    u32 t3;
    u32 t2;
    u32 s2;
    u32 s3;
    u32 o3;
    u8 sb0;
    u32 o0;
    u8 sb1;
    u32 o1;
    u32 o2;
    void *roundKeys;

    roundKeys = schedule;
    out = outBlock;
    s0 = (M2C_FIELD(input, u8 *, 0) << 0x18) ^ (M2C_FIELD(input, u8 *, 1) << 0x10) ^ (M2C_FIELD(input, u8 *, 2) << 8) ^ M2C_FIELD(input, u8 *, 3) ^ M2C_FIELD(roundKeys, s32 *, 0);
    s1 = (M2C_FIELD(input, u8 *, 4) << 0x18) ^ (M2C_FIELD(input, u8 *, 5) << 0x10) ^ (M2C_FIELD(input, u8 *, 6) << 8) ^ M2C_FIELD(input, u8 *, 7) ^ M2C_FIELD(roundKeys, s32 *, 4);
    s2 = M2C_FIELD(roundKeys, s32 *, 8) ^ ((M2C_FIELD(input, u8 *, 8) << 0x18) ^ (M2C_FIELD(input, u8 *, 9) << 0x10) ^ (M2C_FIELD(input, u8 *, 0xA) << 8) ^ M2C_FIELD(input, u8 *, 0xB));
    s3 = M2C_FIELD(roundKeys, s32 *, 0xC) ^ ((M2C_FIELD(input, u8 *, 0xC) << 0x18) ^ (M2C_FIELD(input, u8 *, 0xD) << 0x10) ^ (M2C_FIELD(input, u8 *, 0xE) << 8) ^ M2C_FIELD(input, u8 *, 0xF));
    roundPairs = rounds >> 1;
next_rounds:
    te2Tmp0 = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((s2 >> 8) << 0x18) >> 0x16));
    te2Val0 = te2Tmp0;
    t0 = te2Tmp0 ^ (M2C_FIELD(&gAesTe0, u32 *, ((s0 >> 0x18) * 4)) ^ M2C_FIELD(&gAesTe1, u32 *, ((u32) ((s1 >> 0x10) << 0x18) >> 0x16))) ^ M2C_FIELD(&gAesTe3, u32 *, ((u32) (s3 << 0x18) >> 0x16)) ^ M2C_FIELD(roundKeys, s32 *, 0x10);
    te2Tmp1 = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((s3 >> 8) << 0x18) >> 0x16));
    te2Val1 = te2Tmp1;
    t1 = te2Tmp1 ^ (M2C_FIELD(&gAesTe0, u32 *, ((s1 >> 0x18) * 4)) ^ M2C_FIELD(&gAesTe1, u32 *, ((u32) ((s2 >> 0x10) << 0x18) >> 0x16))) ^ M2C_FIELD(&gAesTe3, u32 *, ((u32) (s0 << 0x18) >> 0x16)) ^ M2C_FIELD(roundKeys, s32 *, 0x14);
    te2Tmp2 = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((s0 >> 8) << 0x18) >> 0x16));
    te2Val2 = te2Tmp2;
    t2 = M2C_FIELD(roundKeys, s32 *, 0x18) ^ (te2Tmp2 ^ (M2C_FIELD(&gAesTe0, u32 *, ((s2 >> 0x18) * 4)) ^ M2C_FIELD(&gAesTe1, u32 *, ((u32) ((s3 >> 0x10) << 0x18) >> 0x16))) ^ M2C_FIELD(&gAesTe3, u32 *, ((u32) (s1 << 0x18) >> 0x16)));
    rk3 = M2C_FIELD(roundKeys, s32 *, 0x1C);
    {
        u32 te3a = M2C_FIELD(&gAesTe3, u32 *, ((u32) (s2 << 24) >> 22));
        u32 te2a = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((s1 >> 8) << 24) >> 22));
        u32 te1a = M2C_FIELD(&gAesTe1, u32 *, ((u32) ((s0 >> 16) << 24) >> 22));
        u32 te0a = M2C_FIELD(&gAesTe0, u32 *, ((s3 >> 24) * 4));
        t3 = (te0a ^ te1a) ^ te2a ^ te3a ^ rk3;
    }
    roundKeys += 0x20;
    if (--roundPairs != 0) {
        {
            u32 te3b = M2C_FIELD(&gAesTe3, u32 *, ((u32) (t3 << 24) >> 22));
            u32 te2b = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((t2 >> 8) << 24) >> 22));
            u32 te0b = M2C_FIELD(&gAesTe0, u32 *, ((t0 >> 24) * 4));
            u32 te1b = M2C_FIELD(&gAesTe1, u32 *, ((u32) ((t1 >> 16) << 24) >> 22));
            s0 = te3b ^ ((te0b ^ te1b) ^ te2b) ^ M2C_FIELD(roundKeys, u32 *, 0);
        }
        {
            u32 te3c = M2C_FIELD(&gAesTe3, u32 *, ((u32) (t0 << 24) >> 22));
            u32 te2c = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((t3 >> 8) << 24) >> 22));
            u32 te0c = M2C_FIELD(&gAesTe0, u32 *, ((t1 >> 24) * 4));
            u32 te1c = M2C_FIELD(&gAesTe1, u32 *, ((u32) ((t2 >> 16) << 24) >> 22));
            s1 = te3c ^ ((te0c ^ te1c) ^ te2c) ^ M2C_FIELD(roundKeys, u32 *, 4);
        }
        te2Tmp3 = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((t0 >> 8) << 0x18) >> 0x16));
        te2Val3 = te2Tmp3;
        s2 = M2C_FIELD(roundKeys, s32 *, 8) ^ (te2Tmp3 ^ (M2C_FIELD(&gAesTe0, u32 *, ((t2 >> 0x18) * 4)) ^ M2C_FIELD(&gAesTe1, u32 *, ((u32) ((t3 >> 0x10) << 0x18) >> 0x16))) ^ M2C_FIELD(&gAesTe3, u32 *, ((u32) (t1 << 0x18) >> 0x16)));
        {
            u32 te3d = M2C_FIELD(&gAesTe3, u32 *, ((u32) (t2 << 24) >> 22));
            u32 te2d = M2C_FIELD(&gAesTe2, u32 *, ((u32) ((t1 >> 8) << 24) >> 22));
            u32 te1d = M2C_FIELD(&gAesTe1, u32 *, ((u32) ((t0 >> 16) << 24) >> 22));
            u32 te0d = M2C_FIELD(&gAesTe0, u32 *, ((t3 >> 24) * 4));
            s3 = M2C_FIELD(roundKeys, u32 *, 12) ^ ((te0d ^ te1d) ^ te2d ^ te3d);
        }
        goto next_rounds;
    }
    rk0 = M2C_FIELD(roundKeys, s32 *, 0);
    sb0 = (u8) M2C_FIELD(&gAesSbox, u32 *, ((u32) (t3 << 0x18) >> 0x16));
    sbLo0 = (s32) sb0;
    sbHi0 = 0xFF00 & M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t2 >> 8) << 0x18) >> 0x16));
    sbHi0Hold = sbHi0;
    o0 = rk0 ^ ((M2C_FIELD(&gAesSbox, u32 *, ((t0 >> 0x18) * 4)) & 0xFF000000) ^ (M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t1 >> 0x10) << 0x18) >> 0x16)) & 0xFF0000) ^ sbHi0Hold ^ sb0);
    M2C_FIELD(out, s8 *, 0) = (s8) (o0 >> 0x18);
    M2C_FIELD(out, s8 *, 1) = (s8) (o0 >> 0x10);
    M2C_FIELD(out, s8 *, 2) = (s8) (o0 >> 8);
    M2C_FIELD(out, u8 *, 3) = o0;
    rk1 = M2C_FIELD(roundKeys, s32 *, 4);
    rk1Hold = rk1;
    sb1 = (u8) M2C_FIELD(&gAesSbox, u32 *, ((u32) (t0 << 0x18) >> 0x16));
    sbLo1 = (s32) sb1;
    sbHi1 = 0xFF00 & M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t3 >> 8) << 0x18) >> 0x16));
    sbHi1Hold = sbHi1;
    o1 = rk1Hold ^ ((M2C_FIELD(&gAesSbox, u32 *, ((t1 >> 0x18) * 4)) & 0xFF000000) ^ (M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t2 >> 0x10) << 0x18) >> 0x16)) & 0xFF0000) ^ sbHi1Hold ^ sb1);
    M2C_FIELD(out, s8 *, 4) = (s8) (o1 >> 0x18);
    M2C_FIELD(out, s8 *, 5) = (s8) (o1 >> 0x10);
    M2C_FIELD(out, s8 *, 6) = (s8) (o1 >> 8);
    M2C_FIELD(out, u8 *, 7) = o1;
    rk2 = M2C_FIELD(roundKeys, s32 *, 8);
    rk2Hold = rk2;
    o2 = rk2Hold ^ ((0xFF00 & M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t0 >> 8) << 0x18) >> 0x16))) ^ ((M2C_FIELD(&gAesSbox, u32 *, ((t2 >> 0x18) * 4)) & 0xFF000000) ^ (0xFF0000 & M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t3 >> 0x10) << 0x18) >> 0x16)))) ^ (u8) M2C_FIELD(&gAesSbox, u32 *, ((u32) (t1 << 0x18) >> 0x16)));
    M2C_FIELD(out, s8 *, 8) = (s8) (o2 >> 0x18);
    M2C_FIELD(out, s8 *, 9) = (s8) (o2 >> 0x10);
    M2C_FIELD(out, s8 *, 0xA) = (s8) (o2 >> 8);
    M2C_FIELD(out, u8 *, 0xB) = o2;
    o3 = (0xFF000000 & M2C_FIELD(&gAesSbox, u32 *, ((t3 >> 0x18) * 4))) ^ (0xFF0000 & M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t0 >> 0x10) << 0x18) >> 0x16))) ^ (M2C_FIELD(&gAesSbox, u32 *, ((u32) ((t1 >> 8) << 0x18) >> 0x16)) & 0xFF00) ^ (u8) M2C_FIELD(&gAesSbox, u32 *, ((u32) (t2 << 0x18) >> 0x16)) ^ M2C_FIELD(roundKeys, s32 *, 0xC);
    M2C_FIELD(out, s8 *, 0xC) = (s8) (o3 >> 0x18);
    M2C_FIELD(out, s8 *, 0xD) = (s8) (o3 >> 0x10);
    M2C_FIELD(out, s8 *, 0xE) = (s8) (o3 >> 8);
    M2C_FIELD(out, u8 *, 0xF) = o3;
}
#pragma opt_common_subs reset
void func_ov001_0217073c(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)(arg0) = 0x67452301;
    *(s32 *)((u8 *)arg0 + 0x4) = 0xEFCDAB89;
    *(s32 *)((u8 *)arg0 + 0x8) = 0x98BADCFE;
    *(s32 *)((u8 *)arg0 + 0xC) = 0x10325476;
}

#pragma thumb on
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov001_02170764(void *arg0,s32 arg1,u32 arg2){
M2C_UNK func_ov001_02170830(void *,void *);
M2C_UNK func_ov001_021710d0(void *,s32,u32);
u32 offset,old,bits,total,used;
offset=(M2C_FIELD(arg0,u32 *,0x10)>>3)&63;
old=M2C_FIELD(arg0,u32 *,0x10);
bits=arg2<<3;total=old+bits;
M2C_FIELD(arg0,u32 *,0x10)=total;
if(total<bits)M2C_FIELD(arg0,u32 *,0x14)++;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
used=64-offset;
if(arg2>=used){
func_ov001_021710d0(arg0+24+offset,arg1,used);
func_ov001_02170830(arg0,arg0+24);
while(used+63<arg2){func_ov001_02170830(arg0,(void *)(arg1+used));used+=64;}
offset=0;
}else used=0;
func_ov001_021710d0(arg0+24+offset,arg1+used,arg2-used);
}

#pragma thumb on
void func_ov001_021707dc(void *arg0, void *arg1) {
    void func_ov001_02170764(void *, s32, u32);
    void func_ov001_02171078(u8 *, volatile u32 *, u32);
    void func_ov001_021710e8(s8 *, s32, u32);
    extern M2C_UNK data_ov001_0218fe68;
    u8 sp0[8];
    u32 temp_r1;

    func_ov001_02171078(sp0, (volatile u32 *)((u8 *)arg1 + 0x10), 8);
    temp_r1 = (*(u32 *)((u8 *)arg1 + 0x10) >> 3) & 0x3F;
    {
        s32 var_r2;
        if (temp_r1 < 0x38) {
            var_r2 = 0x38 - temp_r1;
        } else {
            var_r2 = 0x78 - temp_r1;
        }
        func_ov001_02170764(arg1, (s32)&data_ov001_0218fe68, (u32)var_r2);
    }
    func_ov001_02170764(arg1, (s32)sp0, 8);
    func_ov001_02171078((u8 *)arg0, (volatile u32 *)arg1, 0x10);
    func_ov001_021710e8((s8 *)arg1, 0, 0x58);
}
#pragma thumb off

#pragma pop
#pragma thumb off

#pragma thumb off
