/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
extern M2C_UNK gWhWork;
extern M2C_UNK data_ov001_0219169c;
extern M2C_UNK data_ov001_0219166c, data_ov001_02191684, data_ov001_021916cc;

/* Result of the child scan for one channel: log the channel and the ratio it
   reported, keep in the connection only the channels that reached the best
   (lowest) ratio so far, and then have the scan move on to the next channel.
   A failed report ends the parent start; no further channel ends the scan. */
void HandleChildScanResult(void *report) {
 s32 ScanNextChild(u16);
 u16 channel,ratio,best; s32 result;
 if(M2C_FIELD(report,u16 *,WH_CHANNEL_STATUS)){SetWhError();SetWhStatus(WH_STATUS_PARENT_START);return;}
 if(M2C_FIELD(&gWhWork,void (**)(int,void *,int,int),0))
 M2C_FIELD(&gWhWork,void (**)(int,void *,int,int),0)(0x8000000,&data_ov001_0219169c,M2C_FIELD(report,u16 *,WH_CHANNEL_INDEX),M2C_FIELD(report,u16 *,WH_CHANNEL_RATIO));
 ratio=M2C_FIELD(report,u16 *,WH_CHANNEL_RATIO);channel=M2C_FIELD(report,u16 *,WH_CHANNEL_INDEX);
 best=M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,WH_CHILD_RATIO);
 if(best>ratio) {
 M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,WH_CHILD_RATIO)=ratio;
 M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,WH_CHILD_BITS)=1<<(channel-1);
 }else if(best==ratio) M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,WH_CHILD_BITS)|=1<<(channel-1);
 result=ScanNextChild((u16)(channel+1));
 if(result==24){SetWhStatus(WH_STATUS_MEASURECHAN);return;}
 if(result==2)return;
 SetWhStatus(WH_STATUS_PARENT_START);
}

void func_ov001_021885f4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02013dac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02013dac(arg0, 3, 0x11, arg1, 0x1E);
}

s32 WhChooseChild(void) {
extern M2C_UNK gWhWork;
extern M2C_UNK data_ov001_021916b4;
s32 WhPickChild(u16);
if(M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),s32 *,0x40)!=7) SystemHalt();
SetWhStatus(1);
M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,0x5C)=WhPickChild(M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,0x60));
if(M2C_FIELD(&gWhWork,void (**)(s32,void *,s32),0))
M2C_FIELD(&gWhWork,void (**)(s32,void *,s32),0)(0x8000000,&data_ov001_021916b4,M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,0x5C));
return M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,0x5C);
}

/* Pick a wanted child of the wireless connection: its one-based index from the
 * wanted-child bitmap (the only one set, or 0 when none), or, when several are
 * wanted, a pseudo-random one, advancing the connection's LCG seed. */
s32 WhPickChild(u16 bits) {
 s16 last=0; u16 count=0; s16 i=0; u16 pick;
 for(;i<16;i++) if(bits&(1<<i)){last=i+1;count++;}
 if(count<=1)return last;
 M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u32 *,WH_RANDOM_SEED)=M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u32 *,WH_RANDOM_SEED)*WH_RANDOM_MUL+WH_RANDOM_ADD;
 pick=(count*(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u32 *,WH_RANDOM_SEED)&255))>>8;
 for(i=0;i<16;bits>>=1,i++)if(bits&1){if(pick==0)return (s16)(i+1);pick--;}
 return 0;
}

#pragma peephole off

#pragma peephole reset

/* Initialize the active map state pointed to by the global from the allocated buffer p and the config a. */

