/* 23 functions from 0x02045D94 to 0x02046D38 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

s32 func_02045d94(void *arg0,u8 *a) { void *func_020467b8(void *); void func_02076710(void *,s32); u16 func_02076838(void *,void *,s32); void func_02046654(s32,s32,s32); void func_02007958(void); M2C_UNK func_02008048(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK data_0213db28,data_0213db34; register s32 b=M2C_FIELD(&data_0213db28,s32 *,8); register s32 i;func_020467b8(arg0);func_02076710(a+512,0xa001);i=0;do {if(!FifoReadBlock(b,256,(s32)a)){func_02007958();return 0;}func_02008048((s32)&data_0213db34,(M2C_UNK *)(a+240),14);*(u16 *)(a+254)=func_02076838(a+512,a,254);do{func_02046654(b,256,(s32)a);}while(!func_020466d0((s32)a,b,256,(s32)(a+256)));i++;b+=256;}while(i<2);return func_0204671c()!=0; }

s32 func_02045e70(u16 *a) {  extern M2C_UNK gFifoBlockTransfer; if(!FifoReadBlock(32,32,(s32)a))return 0; M2C_FIELD(&gFifoBlockTransfer,s32 *,8)=(*a<<3)-1024;return 1; }

s32 func_02045eb4(M2C_UNK arg0) {

    extern M2C_UNK gFifoBlockTransfer;
    if (FifoReadBlock(M2C_FIELD(&gFifoBlockTransfer, s32 *, 8), 0x400, arg0) != 0) {
        return 1;
    }
    return 0;
}

/* Upload the 0x100-byte blocks of `data` selected by `blocks` (one entry per
 * block), one after the other: copy each block to the ARM7 transfer address and
 * read it back into `readback` until it verifies, then advance to the next
 * block.  Returns whether the transfer could be finished. */
s32 FifoUploadSelectedBlocks(s32 data,s32 *blocks,s32 readback) { void FifoWriteBlock(s32,s32,s32); extern M2C_UNK gFifoBlockTransfer; register s32 block=data; register s32 i=0; register s32 address=M2C_FIELD(&gFifoBlockTransfer,s32 *,FIFO_XFER_ADDRESS); do {if(blocks[i]) {do {FifoWriteBlock(address,FIFO_BLOCK_SIZE,block);}while(!FifoVerifyBlock(block,address,FIFO_BLOCK_SIZE,readback));} i++;block+=FIFO_BLOCK_SIZE;address+=FIFO_BLOCK_SIZE;}while(i<FIFO_BLOCK_COUNT);return FifoFinishTransfer()!=0; }

#pragma opt_strength_reduction off
/* Upload the four 256-byte blocks of `data` over the FIFO, one after the other:
 * checksum each block into its last two bytes, copy it to the transfer address
 * and read it back until it verifies, then advance to the next block. Returns
 * whether the transfer could be finished. */
s32 FifoUploadVerifiedBlocks(u8 *data) {
    u16 Crc16Block(void *,void *,s32); void FifoWriteBlock(s32,s32,s32); extern M2C_UNK gFifoBlockTransfer;
    register u8 *block = data;
    register s32 i = 0;
    register s32 address = M2C_FIELD(&gFifoBlockTransfer, s32 *, FIFO_XFER_ADDRESS);

    do {
        *(u16 *)(data + (i << 8) + 254) = Crc16Block(data + 0x500, block, 254);
        do {
            FifoWriteBlock(address, 256, (s32)block);
        } while (!FifoVerifyBlock((s32)block, address, 256, (s32)(data + 0x400)));
        i++;
        block += 256;
        address += 256;
    } while (i < 4);
    return FifoFinishTransfer() != 0;
}
#pragma opt_strength_reduction reset
void func_02045ffc(M2C_UNK a) { M2C_UNK MI_CpuCopy8(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK gWfcProfileCode; MI_CpuCopy8(a,&gWfcProfileCode,14); }

u8 CountSetBits(u8 *a) { s32 c,i,j,x; i=0; c=0; do {x=a[i];j=i-i;do{if((x>>j)&1)c++;j++;}while(j<8);i++;}while(i<4);return c; }

#pragma opt_common_subs off
void func_02046058(u8 arg0, M2C_UNK *arg1) {
    u8 *dst = (u8 *)arg1;
    u32 bits;
    s32 i, shift;
    bits = ~0U ^ (~0U >> arg0);
    for (i = 0, shift = 0; i < 4; i++, shift += 8) {
        dst[i] = (u8)(bits >> (24 - shift));
    }
}
#pragma opt_common_subs reset
s32 func_02046088(void *a) { u8 *p=a; s32 i=0;do {if(p[i])return 1;i++;}while(i<32);return 0; }

/* Whether a saved slot's 4-byte player code word is consistent with the slot's
 * stored code word: the player code's first byte must be a valid text character,
 * the pair must not be the empty sentinel 0xFFFFFFFE, and the player code must
 * have a set bit the stored word does not. */
s32 IsSavedPlayerCodeValid(M2C_UNK playerCode, M2C_UNK slotCode) {
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32 *, M2C_UNK);
    s32 IsValidTextChar(u8 *);
    s32 playerWord;
    s32 codeWord;

    if (IsValidTextChar((u8 *)playerCode) == 0) {
        return 0;
    }
    MI_CpuCopy8(playerCode, &playerWord, 4);
    MI_CpuCopy8(slotCode, &codeWord, 4);
    if ((playerWord | codeWord) == -2) {
        return 0;
    }
    if (playerWord & ~codeWord) {
        return 1;
    }
    return 0;
}

s32 IsValidTextChar(u8 *arg0) {
    u8 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 == 0x7F) {
        return 0;
    }
    if ((u32) temp_r0 < 1U) {
        return 0;
    }
    if ((u32) temp_r0 <= 0xDFU) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
s32 FifoTransferCommand(s32 arg0,s32 arg1,s32 arg2,s32 arg3){
M2C_UNK DC_InvalidateRange(M2C_UNK,...);
u64 GetSystemTick(void);
u64 U64Divide(u64,u64);
s32 SendFifoMessage(s32,u32,s32);
extern M2C_UNK gFifoBlockTransfer;
extern u8 data_0213db60[];
volatile u32 a6;
u32 c2,c1,c0,b3,b2,b1,b0,a5,a4,a3,a2,a1,a0;
u64 start;
u32 elapsedLo,elapsedHi;
s32 state;
u64 elapsed,scale;
u32 shared = (u32)data_0213db60;
u32 top1 = (u32)arg1 >> 16;
u32 shifted = shared << 8;
u32 top3 = (u32)arg3 >> 16;
u32 statusBase = 0x1020000;
u32 packetBase = 0x2002200;
u32 endBase = 0x3002100;
c2=(shifted&0xff00)|0x20000;
a1=0x10000|(u16)arg1;
a5=(statusBase+0x30000)|(u16)arg3;
b3=0x1040000|(u16)arg3;
c0=packetBase|(shared>>24);
c2|=0x1000000;
a0=(packetBase+0x100)|(top1&255);
b1=0x20000|arg2;
b2=0x30000|top3;
a4=0x40000|top3;
state=0;
a6=endBase-0x100;
a2=0x20000|((u32)arg2>>16);
c1=0x10000|(shifted>>16);
b0=(packetBase+0x300)|(top1&255);
a3=0x30000|(u16)arg2;
for(;;){
if(state==0){
M2C_FIELD(&gFifoBlockTransfer,s32*,4)=0;
switch(arg0){
case 1:
if(SendFifoMessage(4,a0,0)<0){state=0;break;}
if(SendFifoMessage(4,a1,0)<0){state=0;break;}
if(SendFifoMessage(4,a2,0)<0){state=0;break;}
if(SendFifoMessage(4,a3,0)<0){state=0;break;}
if(SendFifoMessage(4,a4,0)<0){state=0;break;}
if(SendFifoMessage(4,a5,0)<0)state=0;else state=1;break;
case 2:if(SendFifoMessage(4,a6,0)<0)state=0;else state=1;break;
case 3:
if(SendFifoMessage(4,b0,0)<0){state=0;goto timer;}
if(SendFifoMessage(4,a1,0)<0){state=0;goto timer;}
if(SendFifoMessage(4,b1,0)<0){state=0;goto timer;}
if(SendFifoMessage(4,b2,0)<0){state=0;goto timer;}
if(SendFifoMessage(4,b3,0)<0)state=0;else state=1;
timer:start=GetSystemTick();break;
case 4:case 5:
if(SendFifoMessage(4,c0,0)<0){state=0;break;}
if(SendFifoMessage(4,c1,0)<0){state=0;break;}
if(SendFifoMessage(4,c2,0)<0)state=0;else state=1;break;
case 6:if(SendFifoMessage(4,endBase+0xc00,0)<0)state=0;else state=1;break;
case 7:if(SendFifoMessage(4,endBase,0)<0)state=0;else state=1;break;
}
}else if(M2C_FIELD(&gFifoBlockTransfer,s32*,4)==1){
state=0;
if(M2C_FIELD(&gFifoBlockTransfer,u16*,0))goto fail;
switch(arg0){
case 1:return 1;
case 2:arg0=4;break;
case 3:arg0=5;break;
case 4:case 5:
DC_InvalidateRange((s32)data_0213db60,1);
if(arg0==4){
if(data_0213db60[0]&2)arg0=3;else return state;
}else{
if(!(data_0213db60[0]&1))return 1;
if(data_0213db60[0]&32)goto delay;
elapsed=GetSystemTick()-start;
scale=(u64)(u32)64;
if(U64Divide(elapsed*scale,0x82ea)>4000) arg0=6;
continue;
delay:WaitByLoop(0x4000);
}
break;
case 6:return state;
case 7:return 1;
}
}
}
fail:return state;
}
#pragma opt_propagation reset
s32 FifoReadBlock(s32 arg0,s32 arg1,M2C_UNK arg2) {
M2C_UNK DC_InvalidateRange(M2C_UNK,...); s32 IsFifoMessageReady(s32,s32); M2C_UNK SetFifoMessageHandler(s32,M2C_UNK *); s32 FifoTransferCommand(s32,s32,s32,s32); M2C_UNK WaitByLoop(s32); extern M2C_UNK HandleFifoMessage;
register u16 len;
DC_InvalidateRange(arg2); do {}while(!IsFifoMessageReady(4,1));SetFifoMessageHandler(4,&HandleFifoMessage);
len=(u16)arg1;
loop: if(FifoTransferCommand(1,arg0,len,arg2)!=1) {WaitByLoop(0x40000);goto loop;}DC_InvalidateRange(arg2,arg1);return 1; }

/* Send `size` bytes of `data` from the ARM9 to the ARM7 address `address` over
 * the FIFO: wait for the channel, hand it the reply handler, clean the cache for
 * the data, then run the write transfer until the ARM7 acknowledges the block. */
void FifoWriteBlock(s32 address, s32 size, s32 data) {
    s32 IsFifoMessageReady(s32, s32);
    M2C_UNK SetFifoMessageHandler(s32, M2C_UNK *);
    M2C_UNK DC_CleanRange(s32, s32);
    s32 FifoTransferCommand(s32, s32, s32, s32);
    M2C_UNK WaitByLoop(s32);
    extern M2C_UNK HandleFifoMessage;

    do {
    } while (!IsFifoMessageReady(4, 1));
    SetFifoMessageHandler(4, (M2C_UNK *)&HandleFifoMessage);
    DC_CleanRange(data, size);
 loop:
    if (FifoTransferCommand(2, address, size, data) != 1) {
        WaitByLoop(0x40000);
        goto loop;
    }
}

s32 FifoVerifyBlock(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 ByteCompareN(M2C_UNK, M2C_UNK, M2C_UNK);
    if (FifoReadBlock(arg1, arg2, arg3) == 0) {
        return 0;
    }
    if (ByteCompareN(arg0, arg3, arg2) == 0) {
        return 1;
    }
    return 0;
}

/* Finish the save/profile block transfer: wait for the block-transfer FIFO
 * channel, install the shared reply handler, then keep sending the finish command
 * until the ARM7 acknowledges it. */
s32 FifoFinishTransfer(void) {
    M2C_UNK WaitByLoop(M2C_UNK);
    M2C_UNK SetFifoMessageHandler(M2C_UNK, M2C_UNK *);
    s32 IsFifoMessageReady(M2C_UNK, M2C_UNK);
    s32 FifoTransferCommand(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK HandleFifoMessage;
    do {

    } while (IsFifoMessageReady(FIFO_BLOCK_TAG, 1) == 0);
    SetFifoMessageHandler(FIFO_BLOCK_TAG, &HandleFifoMessage);
loop_3:
    if (FifoTransferCommand(7, 0, 0, 0) != 1) {
        WaitByLoop(0x40000);
        goto loop_3;
    }
    return 1;
}

s32 HandleFifoMessage(s32 a,s32 b,s32 c) { extern M2C_UNK gFifoBlockTransfer; M2C_FIELD(&gFifoBlockTransfer,u16 *,0)=(u8)b;M2C_FIELD(&gFifoBlockTransfer,s32 *,4)=1;if(c)M2C_FIELD(&gFifoBlockTransfer,u16 *,0)=255;return M2C_FIELD(&gFifoBlockTransfer,u16 *,0); }

void *EncodeWfcProfileBlob(void *a) { M2C_UNK MI_CpuCopy8(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK gWfcProfileCode,data_0213db3a,data_0213db40; u32 lo,hi,z; u64 x,y; hi=M2C_FIELD(a,u32 *,12);lo=M2C_FIELD(a,u32 *,8);((u32 *)&x)[1]=hi;((u32 *)&x)[0]=lo;MI_CpuCopy8((s32)a,&gWfcProfileCode,5);z=((M2C_FIELD(a,u64 *,0)>>40)&7ULL) | ((u32)(x&31)<<3);y=x>>5;x=y; M2C_FIELD(&gWfcProfileCode,u8 *,5)=z; MI_CpuCopy8((s32)&x,&data_0213db3a,4);M2C_FIELD(&gWfcProfileCode,u8 *,10)=((x>>32)&63)|((M2C_FIELD(a,u16 *,16)&3)<<6);M2C_FIELD(&gWfcProfileCode,u8 *,11)=M2C_FIELD(a,u16 *,16)>>2;MI_CpuCopy8((s32)a+18,&data_0213db40,2);return &gWfcProfileCode; }

M2C_UNK *GetWfcProfileCode(void) {
    extern M2C_UNK gWfcProfileCode;
    return &gWfcProfileCode;
}

s32 VerifySaveBlock(void *arg0) {
    void func_02046d0c(s32, s32);
    void FillU16(s32, s32, s32);
    s32 MI_CpuCopy8(M2C_UNK, M2C_UNK *, M2C_UNK);

    s32 stk[4];
    void *r8 = arg0;
    u8 *r6;
    u8 *r7;
    s32 r5;
    s32 r4 = 0;
    s32 r10 = 1;
    s32 tmp;

    MI_CpuFill8(r8, 0, 0x700);
    if (func_02045e70(r8) == 0) {
        return 0xffffd8ef;
    }
    func_02076710((u8 *)r8 + 0x500, 0xA001);
    if (func_02045eb4(r8) == 0) {
        return 0xffffd8ef;
    }

    MI_CpuFill8(stk, 0, 16);

    r6 = (u8 *)r8;
    r7 = (u8 *)r8;
    r5 = 0;
    while (r5 < 3) {
        tmp = Crc16Block((u8 *)r8 + 0x500, r6, 0xFE);
        {
            s32 v = *(u16 *)((u8 *)r8 + (r5 << 8) + 0xFE);
            if (tmp == v) {
                if (func_02046b8c(r7) != 0) {
                    stk[r5] = r10;
                }
            }
        }
        r5++;
        r6 += 0x100;
        r7 += 0x100;
    }

    tmp = Crc16Block((u8 *)r8 + 0x500, (u8 *)r8 + 0x300, 0xFE);
    {
        s32 v = *(u16 *)((u8 *)r8 + 0x300 + 0xFE);
        if (tmp == v) {
            stk[3] = 1;
        }
    }

    if (stk[0] && stk[1] && stk[2] && stk[3]) {
        func_02045ffc((u8 *)r8 + 0xF0);
        return 0;
    }

    if (stk[0] == 0 && stk[1] == 0 && stk[2] == 0 && stk[3] == 0) {
        InitSaveSlotsWithWfcProfile((s32)r8);
        if (FifoUploadVerifiedBlocks((u8 *)r8) == 0) {
            return 0xffffd8f0;
        }
        return 0;
    }

    if (!(stk[0] == 0 && stk[1] == 0)) {
        goto Lc98;
    }
    if (stk[2] == 0 && stk[3] == 0) {
        InitSaveSlotsWithWfcProfile((s32)r8);
        if (FifoUploadVerifiedBlocks((u8 *)r8) == 0) {
            return 0xffffd8f0;
        }
        return 0;
    }

 Lc98:
    if (stk[0] == 0 && stk[1] == 0) {
        InitSaveSlotsWithWfcProfile((s32)r8);
        if (FifoUploadVerifiedBlocks((u8 *)r8) != 0) {
            return 0xffffd8ed;
        }
        return 0xffffd8f0;
    }

    if (stk[0] == 0) {
        func_02046d0c((s32)r8, 0);
        MI_CpuCopy8((u8 *)r8 + 0x1F0, (u8 *)r8 + 0xF0, 0xE);
        {
            u8 b = *((u8 *)r8 + 0x1EF);
            *((u8 *)r8 + 0xEF) = b;
        }
    } else {
        if (stk[1] == 0) {
            func_02046d0c((s32)r8, 1);
            MI_CpuCopy8((u8 *)r8 + 0xF0, (u8 *)r8 + 0x1F0, 0xE);
            {
                u8 b = *((u8 *)r8 + 0xEF);
                *((u8 *)r8 + 0x1EF) = b;
            }
        }
    }
    func_02045ffc((u8 *)r8 + 0xF0);
    if (stk[2] == 0) {
        func_02046d0c((s32)r8, 2);
    }
    if (stk[3] == 0) {
        FillU16((s32)((u8 *)r8 + 0x300), 0, 0x100);
    }

    {
        s32 r5b = 0;
        while (r5b < 3) {
            if (stk[r5b] == 0) {
                u8 b = *((u8 *)r8 + 0xEF);
                if ((b & (1 << r5b)) != 0) {
                    u8 nb = (u8)(b & ~(1 << r5b));
                    *((u8 *)r8 + 0xEF) = nb;
                    *((u8 *)r8 + 0x1EF) = (u8)(nb & 0xFF);
                    r4 = 1;
                }
            }
            r5b++;
        }
    }

    if (FifoUploadVerifiedBlocks((u8 *)r8) == 0) {
        return 0xffffd8f0;
    }
    if (r4 != 0) {
        return 0xffffd8ee;
    }
    return 0;
}

/* Validate an object's slots and resource references; returns 0 on failure. */
s32 func_02046b8c(void *obj) {
    s32 func_02046088(void *);
    extern M2C_UNK data_020ea940;
    M2C_UNK sp0;
    u8 slot;
    u8 temp_r0_2;

    slot = M2C_FIELD(obj, u8 *, 0xE7);
    if (slot == 0xFF) {
        return 1;
    }
    if ((u32) slot > 2U) {
        return 0;
    }
    if (func_02046088(obj + 0x40) == 0) {
        return 0;
    }
    if (ByteCompareN(obj + 0xC0, &data_020ea940, 4) != 0) {
        if (IsValidTextChar(obj + 0xC4) == 0) {
            return 0;
        }
        temp_r0_2 = M2C_FIELD(obj, u8 *, 0xD0);
        if ((u32) temp_r0_2 > 0x20U) {
            return 0;
        }
        func_02046058(temp_r0_2, &sp0);
        if (IsSavedPlayerCodeValid(obj + 0xC0, &sp0) == 0) {
            return 0;
        }
        goto block_13;
    }
block_13:
    if ((ByteCompareN(obj + 0xC8, &data_020ea940, 4) != 0) && (IsValidTextChar(obj + 0xC8) == 0) && (IsValidTextChar(obj + 0xCC) == 0)) {
        return 0;
    }
    return 1;
}

/* Reset the four 0x100-byte save slots at `saveData`: mark the first three
 * erased, generate a local WFC profile and store its packed code in the first
 * two slots. The caller refreshes the slot checksums. */
s32 InitSaveSlotsWithWfcProfile(s32 saveData) { void FillU16(s32,s32,s32); void BuildWfcProfile(void *); M2C_UNK MI_CpuCopy8(M2C_UNK,M2C_UNK *,M2C_UNK); u8 profile[WFC_PROFILE_SIZE];s32 i;void *code;register u8 *slot;register u32 erased=255;FillU16(0,saveData,1024);i=0;do{slot=(u8 *)(saveData+((u32)i<<8));M2C_FIELD(slot,u8 *,SAVE_SLOT_STATUS_REL)=erased;i++;}while(i<3);BuildWfcProfile(profile);code=EncodeWfcProfileBlob(profile);i=0;do{MI_CpuCopy8((s32)code,(M2C_UNK *)(saveData+SAVE_SLOT_CODE),SAVE_SLOT_PROFILE_CODE_SIZE);i++;saveData+=SAVE_SLOT_SIZE;}while(i<2);return 0;}

#pragma opt_common_subs off
void func_02046d0c(s32 a,s32 b) { void FillU16(s32,s32,s32); FillU16(0,a+(b<<8),256); M2C_FIELD(a+(b<<8),u8 *,0xe7)=255; }
#pragma opt_common_subs reset
