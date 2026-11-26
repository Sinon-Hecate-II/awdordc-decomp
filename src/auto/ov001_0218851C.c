/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
#include "wfc.h"
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

/* Queue the channel-occupancy measurement of one child channel; the report goes
 * to `callback` (HandleChildScanResult). */
void RequestChildChannelScan(M2C_UNK callback, M2C_UNK channel) {
    M2C_UNK WFC_MeasureChannel(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    WFC_MeasureChannel(callback, WFC_SCAN_CCA_MODE, WFC_SCAN_ED_THRESHOLD, channel, WFC_SCAN_MEASURE_TIME);
}

/* Pick the child of the wireless connection to connect to: allowed only once
 * the parent has measured every child channel, then the chosen child is logged
 * and returned. */
s32 WhChooseChild(void) {
extern M2C_UNK gWhWork;
extern M2C_UNK gWhDecidedChannelFormat;
s32 WhPickChild(u16);
if(M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),s32 *,WH_LINK_STATUS)!=WH_STATUS_MEASURECHAN) SystemHalt();
SetWhStatus(WH_STATUS_IDLE);
M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,WH_CHILD_PICKED)=WhPickChild(M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,WH_CHILD_BITS));
if(M2C_FIELD(&gWhWork,void (**)(s32,void *,s32),WH_WORK_LOG))
M2C_FIELD(&gWhWork,void (**)(s32,void *,s32),WH_WORK_LOG)(WH_LOG_STATUS,&gWhDecidedChannelFormat,M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,WH_CHILD_PICKED));
return M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4),u16 *,WH_CHILD_PICKED);
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

