/* 18 functions from 0x0200CD68 to 0x0200DD40 (main), found by ds-decomp. */
#include "common.h"
#include "hw_div.h"
typedef struct { u16 x,y; } TouchPair;
/* The factory touch calibration kept in the firmware's user-settings block at
 * 0x027FFC80: two sampled raw touch points, each with the screen position it was
 * taken at. */
typedef struct { u8 pad[0x58]; u16 rawX1,rawY1; u8 screenX1,screenY1; u16 rawX2,rawY2; u8 screenX2,screenY2; } TouchCalibrationPoints;
#include "touch_panel.h"
extern HashDescriptor gSha1HashDescriptor;
extern M2C_UNK gTouchDriverState;
void Sha1Init(void *);
void Sha1Update(void *, const void *, s32);
void SHA1_Finalize(void *, void *);
void TP_OnFifoReceive(u32,u32,u32);
typedef struct { u32 x:12; u32 y:12; u32 touch:1; u32 valid:2; u32 unused:5; } TouchPacket;
typedef union { TouchPair pair; TouchPacket bits; } TouchSample;
typedef struct { u16 x,y,touch,valid; } TouchResult;
/* Touch calibration block starting at gTouchDriverState.calXOffset (+0x1C):
 * the per-axis raw offset, range and scale (1<<28 / range). */
typedef struct {
    s32 xOffset; /* +0x00 */
    s32 xRange;  /* +0x04 */
    s32 xScale;  /* +0x08 */
    s32 yOffset; /* +0x0C */
    s32 yRange;  /* +0x10 */
    s32 yScale;  /* +0x14 */
} TouchCalibration;

/* Computes the HMAC-SHA1 (RFC 2104) of `message` under `key` into the 20-byte
 * `digest`, using a private hash descriptor that points the SHA1 state and the
 * inner digest at this function's buffers.  The caller has already copied the
 * key into its own work buffer. */
void HmacSha1(u32 digest,u32 message,u32 messageLength,u32 key,u32 keyLength) {
void Hmac(u8 *,u8 *,s32,u8 *,s32,HashDescriptor *);
u8 sha1Context[0x68]; u8 innerDigest[0x14]; HashDescriptor descriptor = gSha1HashDescriptor;
descriptor.context=sha1Context; descriptor.digest=innerDigest;
descriptor.init=Sha1Init; descriptor.update=Sha1Update; descriptor.final=SHA1_Finalize;
Hmac(digest,message,messageLength,key,keyLength,&descriptor);
}

#pragma scheduling off
/* Keyed-hash message authentication (HMAC): when the key is longer than one
 * block it is hashed first, then the inner (0x36) and outer (0x5c) padded keys
 * are built and fed through the descriptor's hash callbacks with the message
 * and the inner digest. */
void Hmac(u8 *digest, u8 *msg, s32 msgLen, u8 *key, s32 keyLen, HashDescriptor *hash) {
    u8 keyHash[64];
    u8 innerPad[64];
    u8 outerPad[64];
    s32 i;
    s32 k;
    u8 *p;
    u8 *p2;
    u8 *q;
    u8 *src;
    s32 j;
    u8 b;
    u8 c;

    k = keyLen;
    src = key;
    if ((digest != NULL) && (msg != NULL) && (msgLen != 0) && (src != NULL) && (k != 0) && (hash != NULL)) {
        if (k > (s32)hash->blockSize) {
            hash->init(hash->context);
            hash->update(hash->context, src, k);
            hash->final(hash->context, keyHash);
            k = hash->digestSize;
            src = keyHash;
        }
        i = 0;
        if (k > 0) {
            p = innerPad;
            do {
                b = src[i];
                i += 1;
                *p = b ^ 0x36;
                p += 1;
            } while (i < k);
        }
        if (i < (s32)hash->blockSize) {
            p = &innerPad[i];
            do {
                *p = 0x36;
                p += 1;
                i += 1;
            } while (i < (s32)hash->blockSize);
        }
        hash->init(hash->context);
        hash->update(hash->context, innerPad, hash->blockSize);
        hash->update(hash->context, msg, msgLen);
        hash->final(hash->context, hash->digest);
        j = 0;
        if (k > 0) {
            p2 = outerPad;
            do {
                c = src[j];
                j += 1;
                *p2 = c ^ 0x5C;
                p2 += 1;
            } while (j < k);
        }
        if (j < (s32)hash->blockSize) {
            q = &outerPad[j];
            do {
                *q = 0x5C;
                q += 1;
                j += 1;
            } while (j < (s32)hash->blockSize);
        }
        hash->init(hash->context);
        hash->update(hash->context, outerPad, hash->blockSize);
        hash->update(hash->context, hash->digest, hash->digestSize);
        hash->final(hash->context, digest);
    }
}
#pragma scheduling reset
void func_0200cfc8(u32 *state,const u8 *data,s32 len){
 u32 a,b,c,d,e,W[32],*p,t,x;
 s32 i;
 a=state[0];b=state[1];c=state[2];d=state[3];e=state[4];
 do{
 p=W;
 for(i=0;i<64;i+=4){
 x=*(const u32 *)data;data+=4;
 x=(((x>>8)|(x<<24))&0xff00ff00)|(((x<<8)|(x>>24))&0xff00ff);
 p[16]=x;*p++=x;
 t=0x5a827999+e+((a<<5)|(a>>27))+x+(((c^d)&b)^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 }
 p=W;
 for(i=0;i<16;i+=4){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0x5a827999+((a<<5)|(a>>27))+(((c^d)&b)^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 }
 for(i=0;i<20;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0x6ed9eba1+((a<<5)|(a>>27))+(b^c^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 if(i==11)p=W;
 }
 for(i=0;i<20;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0x8f1bbcdc+((a<<5)|(a>>27))+(((b|c)&d)|(b&c));
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 if(i==7)p=W;
 }
 for(i=0;i<20;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0xca62c1d6+((a<<5)|(a>>27))+(b^c^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 if(i==3)p=W;
 }
 state[0]+=a;state[1]+=b;state[2]+=c;state[3]+=d;state[4]+=e;
 len-=64;
 }while(len>0);
}

#pragma push
#pragma opt_global_reg off
void TP_OnFifoReceive(u32 unused,u32 value,u32 error){
u16 code=(u16)value;u16 command=(u16)((code&0x7f00)>>8);s32 status;
TouchSample sample1,sample2;TouchResult *out; u8 touch,valid;u16 y,x;
if(error){
value=(u32)&gTouchDriverState;
((TouchState *)(void *)value)->flags38=(u16)(((TouchState *)(void *)value)->flags38 | (1U<<command));
if(((TouchState *)(void *)value)->callback)((TouchState *)(void *)value)->callback(command,4,0);return;
}
if(command==16){
value=(u32)&gTouchDriverState;
M2C_FIELD((void *)value,u16 *,0x10)++;
if(M2C_FIELD((void *)value,u16 *,0x10)>=M2C_FIELD((void *)value,u16 *,0x18))M2C_FIELD((void *)value,u16 *,0x10)=0;
sample1.pair=*(volatile TouchPair *)0x27fffaa;
x=sample1.bits.x;y=sample1.bits.y;touch=sample1.bits.touch;valid=sample1.bits.valid;
out=M2C_FIELD((void *)value,TouchResult **,0x14)+M2C_FIELD(&gTouchDriverState,u16 *,0x10);
out->x=x;out->y=y;out->touch=touch;out->valid=valid;
if(((TouchState *)(void *)value)->callback)((TouchState *)(void *)value)->callback(command,0,(u8)M2C_FIELD((void *)value,u16 *,0x10));return;
}
if(!(value&0x1000000))return;
switch((u8)code){
case 0:
switch(command){case 0:
sample2.pair=*(volatile TouchPair *)0x27fffaa;x=sample2.bits.x;y=sample2.bits.y;touch=sample2.bits.touch;valid=sample2.bits.valid;
M2C_FIELD(&gTouchDriverState,u16 *,8)=x;
M2C_FIELD(&gTouchDriverState,u16 *,10)=y;
M2C_FIELD(&gTouchDriverState,u16 *,12)=touch;
M2C_FIELD(&gTouchDriverState,u16 *,14)=valid;
M2C_FIELD(&gTouchDriverState,u16 *,0x36)=0;
break;
case 1:M2C_FIELD(&gTouchDriverState,u16 *,0x36)=2;break;
case 2:M2C_FIELD(&gTouchDriverState,u16 *,0x36)=0;break;
}
value=(u32)&gTouchDriverState;
((TouchState *)(void *)value)->flags3a=(u16)(~(1<<command)&((TouchState *)(void *)value)->flags3a);
if(((TouchState *)&gTouchDriverState)->callback)((TouchState *)&gTouchDriverState)->callback(command,0,0);return;
case 4:status=3;goto report;
case 2:status=1;goto report;
case 3:status=2;
report:
value=(u32)&gTouchDriverState;
((TouchState *)&gTouchDriverState)->flags38|=1<<command;
((TouchState *)&gTouchDriverState)->flags3a=(u16)(~(1<<command)&((TouchState *)(void *)value)->flags3a);
if(((TouchState *)&gTouchDriverState)->callback)((TouchState *)&gTouchDriverState)->callback(command,(u8)status,0);
return;
default:SystemHalt();return;
}
}
#pragma pop
/* Initialize the touch panel driver and register its ARM7 FIFO callback once. */
void TP_Init(void) {
    void PXI_Init(void);
    s32 IsFifoMessageReady(s32, s32);
    void SetFifoMessageHandler(s32, void *);

    if (((TouchState *)&gTouchDriverState)->initialized) {
        return;
    }
    ((TouchState *)&gTouchDriverState)->initialized = 1;
    PXI_Init();
    ((TouchState *)&gTouchDriverState)->sampleIndex = 0;
    ((TouchState *)&gTouchDriverState)->callback = NULL;
    ((TouchState *)&gTouchDriverState)->sampleBuffer = NULL;
    ((TouchState *)&gTouchDriverState)->samplingMode = 0;
    ((TouchState *)&gTouchDriverState)->calibrated = 0;
    ((TouchState *)&gTouchDriverState)->flags3a = 0;
    ((TouchState *)&gTouchDriverState)->flags38 = 0;
    while (!IsFifoMessageReady(PXI_FIFO_TAG_TOUCHPANEL, PXI_PROC_ARM7)) {
    }
    SetFifoMessageHandler(PXI_FIFO_TAG_TOUCHPANEL, &TP_OnFifoReceive);
}

#pragma opt_propagation off
/* Build the touch screen calibration from the factory points stored in the
 * firmware's user-settings block: the two raw/screen point pairs are handed to
 * TP_CalculateCalibration, and cal is zeroed when the firmware has no usable
 * points or the calculation fails. */
s32 TP_GetFirmwareCalibration(u16 *cal) {
    s32 TP_CalculateCalibration(void *,u16,u16,u16,u16,u16,u16,u16,u16);
    TouchCalibrationPoints *points = (TouchCalibrationPoints *)0x027FFC80;
    u16 rawX1 = points->rawX1;
    u16 rawY1 = points->rawY1;
    u16 rawX2 = points->rawX2;
    u16 rawY2 = points->rawY2;
    u8 screenX1 = points->screenX1;
    u8 screenY1 = points->screenY1;
    u8 screenX2 = points->screenX2;
    u8 screenY2 = points->screenY2;
    if ((!rawX1 && !rawX2 && !rawY1 && !rawY2) ||
        TP_CalculateCalibration(cal, rawX1, rawY1, screenX1, screenY1, rawX2, rawY2, screenX2, screenY2)) {
        cal[0] = 0; cal[1] = 0; cal[2] = 0; cal[3] = 0; return 1;
    }
    return 1;
}
#pragma opt_propagation reset
/* Store the touch screen's calibration offsets and ranges, and use the hardware
 * divider to precompute the per-axis scale factors (1<<28 / range). */
void SetTouchCalibration(s16 *cal){
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);
s32 interrupts,range;
if(!cal){((TouchState *)&gTouchDriverState)->calibrated=0;return;}
interrupts=OS_DisableInterrupts();
if((range=cal[2])!=0){
REG_DIVCNT=0;
REG_DIV_NUMER=0x10000000;
REG_DIV_DENOM=(u32)range;
((TouchState *)&gTouchDriverState)->calXOffset=cal[0];
((TouchState *)&gTouchDriverState)->calXRange=cal[2];
while(REG_DIVCNT&DIVCNT_BUSY){}
((TouchState *)&gTouchDriverState)->calXScale=REG_DIV_RESULT;
}else{((TouchState *)&gTouchDriverState)->calXOffset=0;((TouchState *)&gTouchDriverState)->calXRange=0;((TouchState *)&gTouchDriverState)->calXScale=0;}
if((range=cal[3])!=0){
REG_DIVCNT=0;
REG_DIV_NUMER=0x10000000;
REG_DIV_DENOM=(u32)range;
((TouchState *)&gTouchDriverState)->calYOffset=cal[1];
((TouchState *)&gTouchDriverState)->calYRange=cal[3];
while(REG_DIVCNT&DIVCNT_BUSY){}
((TouchState *)&gTouchDriverState)->calYScale=REG_DIV_RESULT;
}else{((TouchState *)&gTouchDriverState)->calYOffset=0;((TouchState *)&gTouchDriverState)->calYRange=0;((TouchState *)&gTouchDriverState)->calYScale=0;}
OS_RestoreInterrupts(interrupts);((TouchState *)&gTouchDriverState)->calibrated=1;}

#pragma opt_propagation off
void func_0200d778(void) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); s32 SendFifoMessage(s32,u32,s32);
s32 t=OS_DisableInterrupts(); s32 ok=(SendFifoMessage(6,0x3000000,0)>=0); u32 base;
if(!ok) {OS_RestoreInterrupts(t);base=(u32)&gTouchDriverState;
((TouchState *)base)->flags38 = 1 | ((TouchState *)base)->flags38;
if(((TouchState *)base)->callback)((TouchState *)base)->callback(0,4,0);
} else {base=(u32)&gTouchDriverState;((TouchState *)base)->flags3a = 1 | ((TouchState *)base)->flags3a;((TouchState *)base)->flags38&=~1;OS_RestoreInterrupts(t);}
}
#pragma opt_propagation reset
/* Wait for the touch panel controller's sample command to finish, then copy the
 * raw point (x, y, touch, valid) into `sample`.  Returns 1 when the command
 * failed, 0 when the sample was read. */
s32 TP_ReadTouchSample(u16 *sample) {
    void TP_WaitBusy(u32);
    TP_WaitBusy(1);
    if (((TouchState *)&gTouchDriverState)->flags38 & 1) return 1;
    ((TouchPair *)sample)[0] = M2C_FIELD(&gTouchDriverState, TouchPair *, 8);
    ((TouchPair *)sample)[1] = M2C_FIELD(&gTouchDriverState, TouchPair *, 12);
    return 0;
}

#pragma opt_instruction_scheduling off
void TP_RequestAutoSamplingStartAsync(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 SendFifoMessage(s32, u32, s32);
    u32 i;
    s32 t;
    u8 ok;

    M2C_FIELD(&gTouchDriverState, s32 *, 0x14) = arg2;
    M2C_FIELD(&gTouchDriverState, u16 *, 0x10) = 0;
    M2C_FIELD(&gTouchDriverState, u16 *, 0x12) = arg1;
    M2C_FIELD(&gTouchDriverState, u16 *, 0x18) = arg3;
    i = 0;
    while (i < arg3) {
        u32 v = i;
        i++;
        ((u16 *)M2C_FIELD(&gTouchDriverState, s32 *, 0x14))[v * 4 + 2] = (u16)v;
    }
    t = OS_DisableInterrupts();
    if (SendFifoMessage(6, (arg1 & 0xff) | 0x100 | 0x2000000, 0) < 0) {
        goto fail;
    }
    ok = (SendFifoMessage(6, arg0 | 0x10000 | 0x1000000, 0) >= 0);
    if (ok) {
        goto okpath;
    }
fail:
    OS_RestoreInterrupts(t);
    M2C_FIELD(&gTouchDriverState, u16 *, 0x38) |= 2;
    if (M2C_FIELD(&gTouchDriverState, void (**)(s32, s32, s32), 4)) {
        M2C_FIELD(&gTouchDriverState, void (**)(s32, s32, s32), 4)(1, 4, 0);
    }
    return;
okpath:
    M2C_FIELD(&gTouchDriverState, u16 *, 0x3a) |= 2;
    M2C_FIELD(&gTouchDriverState, u16 *, 0x38) &= ~2;
    OS_RestoreInterrupts(t);
    return;
}
#pragma opt_instruction_scheduling reset
/* Stop the touch driver's sampling through the ARM7: send command 2 and record
 * the outcome in the driver's command-failed/completed masks (bit 2).  A failed
 * send is also reported to the driver's state callback as error 4. */
void TP_StopSampling(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 SendFifoMessage(s32, u32, s32);
    s32 irq = OS_DisableInterrupts();
    s32 sent = (SendFifoMessage(6, 0x03000200, 0) >= 0);
    if (sent == 0) {
        OS_RestoreInterrupts(irq);
        M2C_FIELD(&gTouchDriverState, u16 *, 0x38) = 4 | M2C_FIELD(&gTouchDriverState, u16 *, 0x38);
        if (M2C_FIELD(&gTouchDriverState, void (**)(s32, s32, s32), 4))
            M2C_FIELD(&gTouchDriverState, void (**)(s32, s32, s32), 4)(2, 4, 0);
    } else {
        M2C_FIELD(&gTouchDriverState, u16 *, 0x3a) = 4 | M2C_FIELD(&gTouchDriverState, u16 *, 0x3a);
        M2C_FIELD(&gTouchDriverState, u16 *, 0x38) = ~4 & M2C_FIELD(&gTouchDriverState, u16 *, 0x38);
        OS_RestoreInterrupts(irq);
    }
}
#pragma opt_instruction_scheduling reset
u16 func_0200d9f4(void) {
    extern M2C_UNK gTouchDriverState;
    return M2C_FIELD(&gTouchDriverState, u16 *, 0x10);
}

#pragma opt_instruction_scheduling off
s32 TP_CalculateCalibration(void *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    volatile s16 *p = (volatile s16 *)arg0;
    s32 saved;
    s32 c;
    s32 r;
    s32 sy;
    s32 dy;

    if (arg1 >= 0x1000 || arg2 >= 0x1000 || arg5 >= 0x1000 || arg6 >= 0x1000) return 1;
    if (arg3 >= 0x100 || arg7 >= 0x100 || arg4 >= 0xC0 || arg8 >= 0xC0) return 1;
    if (arg3 == arg7 || arg4 == arg8 || arg1 == arg5 || arg2 == arg6) return 1;

    saved = OS_DisableInterrupts();
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = (s32)((arg1 - arg5) << 8);
    *(volatile s64 *)0x04000298 = (u32)(arg3 - arg7);
    dy = (s32)(arg2 - arg6);
    sy = (s32)(arg4 - arg8);
    while (*(volatile u16 *)0x04000280 & 0x8000) {
    }
    r = *(volatile s32 *)0x040002A0;
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = dy << 8;
    *(volatile s64 *)0x04000298 = (u32)sy;
    if (r >= 0x8000 || r < -0x8000) {
        OS_RestoreInterrupts(saved);
        return 1;
    }
    p[2] = (s16)r;
    c = (s32)((arg1 + arg5) << 8) - p[2] * (s32)(arg3 + arg7);
    c = (c << 9) >> 16;
    if (c >= 0x8000 || c < -0x8000) {
        OS_RestoreInterrupts(saved);
        return 1;
    }
    p[0] = (s16)c;
    while (*(volatile u16 *)0x04000280 & 0x8000) {
    }
    r = *(volatile s32 *)0x040002A0;
    OS_RestoreInterrupts(saved);
    if (r >= 0x8000 || r < -0x8000) {
        return 1;
    }
    p[3] = (s16)r;
    c = (s32)((arg2 + arg6) << 8) - p[3] * (s32)(arg4 + arg8);
    c = (c << 9) >> 16;
    if (c >= 0x8000 || c < -0x8000) {
        return 1;
    }
    p[1] = (s16)c;
    return 0;
}
#pragma opt_instruction_scheduling reset
extern TouchCalibration gTouchCalibration;

/* Convert the raw touch sample `raw` to calibrated screen coordinates in `out`:
 * an uncalibrated sample is copied through; otherwise each axis is scaled by
 * (raw*4 - offset) * scale >> 22 and clamped (0..255 x, 0..191 y). */
void CalibrateTouchSample(u16 *out, u16 *raw) {
    TouchCalibration *cal;
    if (!((TouchState *)&gTouchDriverState)->calibrated) {
        ((TouchPair *)out)[0] = ((TouchPair *)raw)[0];
        ((TouchPair *)out)[1] = ((TouchPair *)raw)[1];
        return;
    }
    cal = &gTouchCalibration;
    out[2] = raw[2];
    out[3] = raw[3];
    if (!raw[2]) { out[0] = 0; out[1] = 0; return; }
    out[0] = (((long long)(raw[0] << 2) - cal->xOffset) * cal->xScale) >> 22;
    if ((s16)out[0] < 0) out[0] = 0;
    else if ((s16)out[0] > 255) out[0] = 255;
    out[1] = (((long long)(raw[1] << 2) - cal->yOffset) * cal->yScale) >> 22;
    if ((s16)out[1] < 0) out[1] = 0;
    else if ((s16)out[1] > 191) out[1] = 191;
}

/* Spin until none of the touch commands in `commandMask` is still in flight
 * (TouchState.flags3a, one bit per command). */
void TP_WaitBusy(u32 commandMask) {
    while (((volatile TouchState *)&gTouchDriverState)->flags3a & commandMask) {
    }
}

u32 TP_CheckBusy(u32 arg0) { return M2C_FIELD(&gTouchDriverState, u16 *, 0x38) & arg0; }

