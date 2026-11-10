/* 5 functions from 0x02089D30 to 0x0208ABC4 (main), found by ds-decomp. */
#include "common.h"
static inline void SetPanelRefresh(void *p) { s32 value=M2C_FIELD(p,s32*,0x58); if(((u32)(value<<18)>>31)&255) M2C_FIELD(p,s32*,0x58)=(value&~0x1fc00000)|0x1000000; }
static inline u32 PanelWidth(void *p) { return (u32)(M2C_FIELD(p,s32 *,0x40)<<23)>>23; }
static inline u32 PanelHeight(void *p) { return (u32)(M2C_FIELD(p,s32 *,0x40)<<14)>>23; }

#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_02089d30(void *arg0) {
    void func_02089cec(void *);
    void *func_0209c658(void *);
    void *func_0209c5dc(void *,s32);
    s32 func_0209b5e4(s32,void *);
    s32 func_0209c690(void *);
    void *func_020ab1c4(s32);
    void func_020aab24(void *,s32,s32,s32,s32);
    void func_02088e84(void *,s16,s32,s16,s32);
    void func_02087d84(void *,s32,s16,s16,u16,u16);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    void func_020ab150(void *,s32);
    void func_020aad18(void *);
    void func_020a9a30(s32,s32,s32,s32);
    extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
    s32 previousEngine,engineIndex;
    s32 maxLength,offset,index,length,rows,width,height,state,mode;
    u32 flags,packed;
    s32 measuredKind;
    void func_0208ae88(void *,s32);
    void func_0208989c(void *);
    void func_0208ad48(void *);
    void func_02089784(void *);
    void func_0208aebc(void *);
    void *end,*entry;
    s32 w1,w2,w3,w4,w5,w6,w7,w8;
    void *sprite4,*sprite1;
    s16 x1,y1;
    s16 sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4,sx5,sy5,sx6,sy6,sx7,sy7,sx8,sy8;
    s32 boolean1,boolean2,boolean3,boolean4,boolean5,boolean6,boolean7,boolean8;
    func_02089cec(arg0);
    previousEngine=gCur3DSpriteEngine;
    for(engineIndex=0;engineIndex<2;engineIndex++){
        gCur3DSpriteEngine=engineIndex==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
        mode=(u32)(M2C_FIELD(arg0,u8 *,0x48)<<28)>>29;
        if(mode==0&&gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;
        if(mode==1&&gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;
        if(mode==3&&gCur3DSpriteEngine!=previousEngine)continue;
        maxLength=0;offset=M2C_FIELD(arg0,u16 *,0x3e)<<5;
        end=func_0209c658(M2C_FIELD(arg0,void **,0x70));
        M2C_FIELD(arg0,u32 *,0x58)&=~0x3c0000;
        index=0;
        do{
            entry=func_0209c5dc(M2C_FIELD(arg0,void **,0x70),index);
            if(!entry||entry==end||index==8)break;
            length=func_0209b5e4(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+offset,entry);
            measuredKind=func_0209c690(entry);
            M2C_FIELD(arg0,u8 **,0x68)[index]=length;
            M2C_FIELD(arg0,u8 **,0x6c)[index]=measuredKind;
            rows=(length+7)>>3;
            if(maxLength<length)maxLength=length;
            flags=M2C_FIELD(arg0,u32 *,0x58);
            M2C_FIELD(arg0,u32 *,0x58)=(flags&~0x3c0000)|((u32)((((flags<<10)>>28)+1)<<28)>>10);
            offset+=((rows+3)>>2)<<8;
            index++;
        }while(index<=8);
        flags=M2C_FIELD(arg0,u32 *,0x58);
        width=(maxLength+7)>>3;
        height=(((flags<<10)>>28)+1)<<4;
        state=(u32)((s32)flags<<29)>>29;
        if(state)height+=32;
        width=(width+2)<<3;
        if(state==3){if(width<128)width=128;}else if(width<64)width=64;
        width=(width+15)&~15;height=(height+15)&~15;
        if(width>128&&width<192)width=(width+31)&~31;
        if(width>256)width=256;
        if(height>192)height=192;
        packed=M2C_FIELD(arg0,u32 *,0x40)&~0x1ff;
        packed|=width&0x1ff;packed&=0xfffc01ff;
        M2C_FIELD(arg0,u32 *,0x40)=packed|((u32)(height<<23)>>14);
        switch((u8)((M2C_FIELD(arg0,u32 *,0x58)<<22)>>30)){
        case 0:
            M2C_FIELD(arg0,s16 *,0x34)=(256-(s32)PanelWidth(arg0))/2;
            M2C_FIELD(arg0,s16 *,0x36)=(192-(s32)PanelHeight(arg0))/2-4;break;
        case 1:
            M2C_FIELD(arg0,s16 *,0x34)=(256-(s32)PanelWidth(arg0))/2;
            M2C_FIELD(arg0,s16 *,0x36)=4;break;
        case 2:
            M2C_FIELD(arg0,s16 *,0x34)=(256-(s32)PanelWidth(arg0))/2;
            M2C_FIELD(arg0,s16 *,0x36)=188-PanelHeight(arg0);break;
        }
        sprite4=0;sprite1=0;
        func_020a9a30(0,2,0x47,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+0x260);
        flags=M2C_FIELD(arg0,u32 *,0x58);
        switch((u32)((s32)flags<<29)>>29){
case 1:
            sprite1=func_020ab1c4(6);
            func_020aab24(sprite1,31,256,3,0);
            y1=M2C_FIELD(arg0,s16 *,0x36)+PanelHeight(arg0)-32;
            x1=M2C_FIELD(arg0,s16 *,0x34)+((s32)PanelWidth(arg0)-64)/2+0;
            func_02088e84(sprite1,x1,y1,x1,y1);
            if(M2C_FIELD(M2C_FIELD(sprite1,void **,0x64),u8 *,0x12))boolean1=1;else boolean1=0;
            if(boolean1&255){
                sy1=M2C_FIELD(sprite1,s16 *,0x52);sx1=M2C_FIELD(sprite1,s16 *,0x50);
                w1=func_020aae10(sprite1);
                func_02087d84(M2C_FIELD(sprite1,void **,0x64),1,sx1,sy1,(u16)w1,(u16)func_020aae44(sprite1));
            }
            M2C_FIELD(sprite1,s16 *,0x34)=x1;M2C_FIELD(sprite1,s16 *,0x36)=y1;
            if(M2C_FIELD(M2C_FIELD(sprite1,void **,0x64),u8 *,0x12))boolean2=1;else boolean2=0;
            if(boolean2&255){
                sy2=M2C_FIELD(sprite1,s16 *,0x52);sx2=M2C_FIELD(sprite1,s16 *,0x50);
                w2=func_020aae10(sprite1);
                func_02087d84(M2C_FIELD(sprite1,void **,0x64),1,sx2,sy2,(u16)w2,(u16)func_020aae44(sprite1));
            }
            func_020ab150(sprite1,3);
            M2C_FIELD(sprite1,s8 *,0x49)=-100;
            
            func_020aad18(sprite1);
M2C_FIELD(arg0,u32 *,0x58)=(M2C_FIELD(arg0,u32 *,0x58)&~0x38000)|0x8000;break;
case 2:
            sprite1=func_020ab1c4(6);
            func_020aab24(sprite1,32,256,3,0);
            y1=M2C_FIELD(arg0,s16 *,0x36)+PanelHeight(arg0)-32;
            x1=M2C_FIELD(arg0,s16 *,0x34)+((s32)PanelWidth(arg0)-32)/2+0;
            func_02088e84(sprite1,x1,y1,x1,y1);
            if(M2C_FIELD(M2C_FIELD(sprite1,void **,0x64),u8 *,0x12))boolean3=1;else boolean3=0;
            if(boolean3&255){
                sy3=M2C_FIELD(sprite1,s16 *,0x52);sx3=M2C_FIELD(sprite1,s16 *,0x50);
                w3=func_020aae10(sprite1);
                func_02087d84(M2C_FIELD(sprite1,void **,0x64),1,sx3,sy3,(u16)w3,(u16)func_020aae44(sprite1));
            }
            M2C_FIELD(sprite1,s16 *,0x34)=x1;M2C_FIELD(sprite1,s16 *,0x36)=y1;
            if(M2C_FIELD(M2C_FIELD(sprite1,void **,0x64),u8 *,0x12))boolean4=1;else boolean4=0;
            if(boolean4&255){
                sy4=M2C_FIELD(sprite1,s16 *,0x52);sx4=M2C_FIELD(sprite1,s16 *,0x50);
                w4=func_020aae10(sprite1);
                func_02087d84(M2C_FIELD(sprite1,void **,0x64),1,sx4,sy4,(u16)w4,(u16)func_020aae44(sprite1));
            }
            func_020ab150(sprite1,3);
            M2C_FIELD(sprite1,s8 *,0x49)=-100;
            
            func_020aad18(sprite1);
M2C_FIELD(arg0,u32 *,0x58)=(M2C_FIELD(arg0,u32 *,0x58)&~0x38000)|0x8000;break;
case 3:
            sprite1=func_020ab1c4(6);
            func_020aab24(sprite1,33,256,3,0);
            y1=M2C_FIELD(arg0,s16 *,0x36)+PanelHeight(arg0)-32;
            x1=M2C_FIELD(arg0,s16 *,0x34)+((s32)PanelWidth(arg0)-32)/2+-32;
            func_02088e84(sprite1,x1,y1,x1,y1);
            if(M2C_FIELD(M2C_FIELD(sprite1,void **,0x64),u8 *,0x12))boolean5=1;else boolean5=0;
            if(boolean5&255){
                sy5=M2C_FIELD(sprite1,s16 *,0x52);sx5=M2C_FIELD(sprite1,s16 *,0x50);
                w5=func_020aae10(sprite1);
                func_02087d84(M2C_FIELD(sprite1,void **,0x64),1,sx5,sy5,(u16)w5,(u16)func_020aae44(sprite1));
            }
            M2C_FIELD(sprite1,s16 *,0x34)=x1;M2C_FIELD(sprite1,s16 *,0x36)=y1;
            if(M2C_FIELD(M2C_FIELD(sprite1,void **,0x64),u8 *,0x12))boolean6=1;else boolean6=0;
            if(boolean6&255){
                sy6=M2C_FIELD(sprite1,s16 *,0x52);sx6=M2C_FIELD(sprite1,s16 *,0x50);
                w6=func_020aae10(sprite1);
                func_02087d84(M2C_FIELD(sprite1,void **,0x64),1,sx6,sy6,(u16)w6,(u16)func_020aae44(sprite1));
            }
            func_020ab150(sprite1,1);
            M2C_FIELD(sprite1,s8 *,0x49)=-100;
            M2C_FIELD(sprite1,s8 *,0x5a)=0;
            func_020aad18(sprite1);

            sprite4=func_020ab1c4(6);
            func_020aab24(sprite4,34,268,3,0);
            y1=M2C_FIELD(arg0,s16 *,0x36)+PanelHeight(arg0)-32;
            x1=M2C_FIELD(arg0,s16 *,0x34)+((s32)PanelWidth(arg0)-32)/2+32;
            func_02088e84(sprite4,x1,y1,x1,y1);
            if(M2C_FIELD(M2C_FIELD(sprite4,void **,0x64),u8 *,0x12))boolean7=1;else boolean7=0;
            if(boolean7&255){
                sy7=M2C_FIELD(sprite4,s16 *,0x52);sx7=M2C_FIELD(sprite4,s16 *,0x50);
                w7=func_020aae10(sprite4);
                func_02087d84(M2C_FIELD(sprite4,void **,0x64),1,sx7,sy7,(u16)w7,(u16)func_020aae44(sprite4));
            }
            M2C_FIELD(sprite4,s16 *,0x34)=x1;M2C_FIELD(sprite4,s16 *,0x36)=y1;
            if(M2C_FIELD(M2C_FIELD(sprite4,void **,0x64),u8 *,0x12))boolean8=1;else boolean8=0;
            if(boolean8&255){
                sy8=M2C_FIELD(sprite4,s16 *,0x52);sx8=M2C_FIELD(sprite4,s16 *,0x50);
                w8=func_020aae10(sprite4);
                func_02087d84(M2C_FIELD(sprite4,void **,0x64),1,sx8,sy8,(u16)w8,(u16)func_020aae44(sprite4));
            }
            M2C_FIELD(sprite4,s8 *,0x49)=-100;
            func_020ab150(sprite4,2);
            M2C_FIELD(sprite4,s8 *,0x5a)=-1;
            
            func_020aad18(sprite4);
flags=(M2C_FIELD(arg0,u32 *,0x58)&~0x38000)|0x10000;
M2C_FIELD(arg0,u32 *,0x58)=flags;
if((s32)(flags<<24)>>30 < 0)func_0208ae88(arg0,1);

break;
case 0:M2C_FIELD(arg0,u32 *,0x58)=flags&~0x38000;break;
}
M2C_FIELD(arg0,void **,0x5c)=sprite1;
M2C_FIELD(arg0,void **,0x60)=sprite4;
}
gCur3DSpriteEngine=previousEngine;
if((u8)((M2C_FIELD(arg0,u32 *,0x58)<<20)>>31))func_0208989c(arg0);
func_0208ad48(arg0);func_02089784(arg0);func_0208aebc(arg0);
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
u32 func_0208a6b0(void *arg0) {
    u32 func_020846a4(void);
    u32 func_0208fe30(M2C_UNK);
    u32 func_0208ff4c(M2C_UNK);
    M2C_UNK func_0208ffe4(M2C_UNK, M2C_UNK, s32);
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;

    if (func_0208ff4c(4) == 0) {
        func_0208fe30(0x125);
    }
    temp_r0_3 = (u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x1D) >> 0x1D;
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_2 = func_020846a4();
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    func_0208ffe4(0, -1, 0x10013);
    temp_r0 = M2C_FIELD(arg0, u32 *, 0x58) | 0x4000;
    M2C_FIELD(arg0, u32 *, 0x58) = temp_r0;
    return temp_r0;
}

u32 func_0208a714(void *arg0) {
    u32 func_0208fe30(M2C_UNK);
    u32 func_0208ff4c(M2C_UNK);
    M2C_UNK func_02090034(M2C_UNK, M2C_UNK);
    u32 temp_r0;
    u32 temp_r0_2;

    temp_r0_2 = (u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x11) >> 0x1F;
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    func_02090034(0, 0);
    temp_r0 = func_0208ff4c(4);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    return func_0208fe30(0x124);
}

#pragma push
#pragma scheduling off
void func_0208a750(void *arg0) {
    s32 func_020abe90(u32);
    s32 func_020ad3f0();
    M2C_UNK func_020b269c();
    M2C_UNK func_020d4704();
    extern s32 gCur3DSpriteEngine;
    u16 * volatile sp60;
    u16 * volatile sp5C;
    u16 * volatile sp58;
    u16 * volatile sp54;
    u16 * volatile sp50;
    u16 * volatile sp4C;
    u16 * volatile sp48;
    u16 * volatile sp44;
    u16 * volatile sp40;
    u16 * volatile sp3C;
    u16 * volatile sp38;
    u16 * volatile sp34;
    u16 * volatile sp30;
    u16 * volatile sp2C;
    u16 * volatile sp28;
    u16 * volatile sp24;
    u16 * volatile sp20;
    u16 * volatile sp1C;
    u16 * volatile sp18;
    u16 * volatile sp14;
    u16 * volatile sp10;
    u16 * volatile spC;
    u16 * volatile sp8;
    u16 * volatile sp4;
    u16 * volatile sp0;
    s32 temp_r0_3;u32 bit;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r1;
    u16 *temp_r1_10;
    u16 *temp_r1_11;
    u16 *temp_r1_12;
    u16 *temp_r1_13;
    u16 *temp_r1_14;
    u16 *temp_r1_15;
    u16 *temp_r1_16;
    u16 *temp_r1_17;
    u16 *temp_r1_18;
    u16 *temp_r1_19;
    u16 *temp_r1_20;
    u16 *temp_r1_21;
    u16 *temp_r1_22;
    u16 *temp_r1_23;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r1_8;
    u16 *temp_r1_9;

    if ((func_020ad3f0() != 0) || (func_020abe90((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1C) >> 0x1D) == 1)) {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) & ~0x400);
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x13) >> 0x1F) & 0xFF) {
        func_020d4704();
        func_020b269c();
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x15) >> 0x1F) & 0xFF) {
        Reset3DSpriteEngineState();
        temp_r1 = *(u16 **)gCur3DSpriteEngine;
        sp60 = (u16 *)((u8 *)temp_r1 + 0xE);
        *sp60 = (s16) (*sp60 & ~0x20);
        temp_r1_2 = *(u16 **)gCur3DSpriteEngine;
        sp5C = (u16 *)((u8 *)temp_r1_2 + 0x10);
        *sp5C = (s16) (*sp5C | 0x20);
        temp_r1_3 = *(u16 **)gCur3DSpriteEngine;
        sp58 = temp_r1_3;
        *sp58 = *sp58 | 0x200;
        temp_r1_4 = *(u16 **)gCur3DSpriteEngine;
        sp54 = temp_r1_4;
        *sp54 = *sp54 & ~0x400;
        temp_r1_5 = *(u16 **)gCur3DSpriteEngine;
        sp50 = temp_r1_5;
        *sp50 = *sp50 & ~0x800;
        temp_r1_6 = *(u16 **)gCur3DSpriteEngine;
        sp4C = (u16 *)((u8 *)temp_r1_6 + 0xE);
        *sp4C = (s16) ((*sp4C & ~1) | 1);
        temp_r1_7 = *(u16 **)gCur3DSpriteEngine;
        sp48 = (u16 *)((u8 *)temp_r1_7 + 0xE);
        *sp48 = (s16) (*sp48 | 2);
        temp_r1_8 = *(u16 **)gCur3DSpriteEngine;
        sp44 = (u16 *)((u8 *)temp_r1_8 + 0xE);
        *sp44 = (s16) (*sp44 | 4);
        temp_r1_9 = *(u16 **)gCur3DSpriteEngine;
        sp40 = (u16 *)((u8 *)temp_r1_9 + 0xE);
        *sp40 = (s16) (*sp40 | 8);
        temp_r1_10 = *(u16 **)gCur3DSpriteEngine;
        sp3C = (u16 *)((u8 *)temp_r1_10 + 0xE);
        *sp3C = (s16) (*sp3C | 0x10);
        temp_r1_11 = *(u16 **)gCur3DSpriteEngine;
        sp38 = (u16 *)((u8 *)temp_r1_11 + 0x10);
        *sp38 = (s16) ((*sp38 & ~1) | 1);
        temp_r1_12 = *(u16 **)gCur3DSpriteEngine;
        sp34 = (u16 *)((u8 *)temp_r1_12 + 0x10);
        *sp34 = (s16) (*sp34 | 2);
        temp_r1_13 = *(u16 **)gCur3DSpriteEngine;
        sp30 = (u16 *)((u8 *)temp_r1_13 + 0x10);
        *sp30 = (s16) (*sp30 | 4);
        temp_r1_14 = *(u16 **)gCur3DSpriteEngine;
        sp2C = (u16 *)((u8 *)temp_r1_14 + 0x10);
        *sp2C = (s16) (*sp2C | 8);
        temp_r0 = *(u16 **)gCur3DSpriteEngine;
        sp28 = (u16 *)((u8 *)temp_r0 + 0x10);
        *sp28 = (s16) (*sp28 | 0x10);
        func_02082770();
        temp_r1_15 = *(u16 **)gCur3DSpriteEngine;
        sp24 = (u16 *)((u8 *)temp_r1_15 + 0x12);
        *sp24 = (s16) ((*sp24 & ~1) | 1);
        temp_r1_16 = *(u16 **)gCur3DSpriteEngine;
        sp20 = (u16 *)((u8 *)temp_r1_16 + 0x12);
        *sp20 = (s16) (*sp20 | 2);
        temp_r1_17 = *(u16 **)gCur3DSpriteEngine;
        sp1C = (u16 *)((u8 *)temp_r1_17 + 0x12);
        *sp1C = (s16) (*sp1C | 4);
        temp_r1_18 = *(u16 **)gCur3DSpriteEngine;
        sp18 = (u16 *)((u8 *)temp_r1_18 + 0x12);
        *sp18 = (s16) (*sp18 | 8);
        temp_r1_19 = *(u16 **)gCur3DSpriteEngine;
        sp14 = (u16 *)((u8 *)temp_r1_19 + 0x12);
        *sp14 = (s16) (*sp14 | 0x10);
        temp_r1_20 = *(u16 **)gCur3DSpriteEngine;
        sp10 = (u16 *)((u8 *)temp_r1_20 + 0x12);
        *sp10 = (s16) (*sp10 & ~0x100);
        temp_r1_21 = *(u16 **)gCur3DSpriteEngine;
        spC = (u16 *)((u8 *)temp_r1_21 + 0x12);
        *spC = (s16) (*spC & ~0x200);
        temp_r1_22 = *(u16 **)gCur3DSpriteEngine;
        sp8 = (u16 *)((u8 *)temp_r1_22 + 0x12);
        *sp8 = (s16) (*sp8 & ~0x400);
        temp_r1_23 = *(u16 **)gCur3DSpriteEngine;
        sp4 = (u16 *)((u8 *)temp_r1_23 + 0x12);
        *sp4 = (s16) (*sp4 & ~0x800);
        temp_r0_2 = *(u16 **)gCur3DSpriteEngine;
        sp0 = (u16 *)((u8 *)temp_r0_2 + 0x12);
        *sp0 = (s16) (*sp0 & ~0x1000);
    }
    temp_r0_3 = M2C_FIELD(arg0, s32 *, 0x58);
    bit=(u32)(temp_r0_3<<18)>>31;
    if(bit&255) {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((temp_r0_3 & ~0x1FC00000) | 0x01000000);
    }
}
#pragma pop
void func_0208ab78(void *arg0) {
    M2C_UNK func_02082770();
    M2C_UNK Reset3DSpriteEngineState();
    M2C_UNK func_020b26dc();
    M2C_UNK func_020d472c();
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x15) >> 0x1F) & 0xFF) {
        Reset3DSpriteEngineState();
        func_02082770();
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 0x58) << 0x13) >> 0x1F) & 0xFF) {
        func_020d472c();
        func_020b26dc();
    }
    func_0208a714(arg0);
}

