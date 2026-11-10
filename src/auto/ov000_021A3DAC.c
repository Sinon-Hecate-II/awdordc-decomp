/* 17 functions from 0x021A3DAC to 0x021A4A98 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
static inline void *GetCandidateMapState(void) { extern void **gCurrentMap; return *gCurrentMap; }

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 func_ov000_021a3dac(void) {
 s32 func_ov000_021a6264(s32);void ResetAiTargetCandidates(void);
 void FloodFillUnitRange(u8,u8,s32,s32,s32);s32 GetUnitMoveRange(u16,s32);void func_ov000_021a34bc(u8);
 s32 GetTerrainPropertyFlagsAt(s32,s32);s32 IsUnitOnCurrentTeam(s32);s32 IsFootUnitKind(s32);s32 IsCaptureKind(s32);
 s32 IsCurrentPlayerUnit(s16);s32 func_ov000_021a8984(s32);void CommitAiAction(s32);
 extern void **gCurrentMap;extern u8 gAiTargetCandidates[];extern u8 data_ov000_021b5bfc[];extern M2C_UNK gAiCommand;
 s32 other,armed,transport,flag,index,i;
 u8 *candidate;
 u8 *unit;
 s32 id,capture,y,x,combat,carrier,tile;
 s32 required;
 void *map;
 void **holder;
 for(;;){
 index=func_ov000_021a6264(3);
 if(index==-1){ResetAiTargetCandidates();return 0;}
 candidate=gAiTargetCandidates+index*12;
 FloodFillUnitRange(candidate[0],candidate[1],2,110,0);
 for(i=0;i<GetUnitMoveRange(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),24);i++)func_ov000_021a34bc((u8)(i+111));
 combat=0;capture=0;carrier=0;armed=0;y=0;other=0;transport=0;flag=0;map=GetCandidateMapState();
 for(;y<M2C_FIELD(map,u16 *,0x5146);y++){
 for(x=0;x<M2C_FIELD(map,u16 *,0x5144);){
 tile=M2C_FIELD(M2C_FIELD((u8 *)map+y*4,s8 **,0x52e8),s8 *,x);
 if(tile<0)goto nextCell;
 if(tile<=110){
 if(GetTerrainPropertyFlagsAt(x,y)==1)goto foundFlag;
 {
 map=*gCurrentMap;
 {u8 terrain=M2C_FIELD((u8 *)map+x+M2C_FIELD((u8 *)map+y*2+0x3700,u16 *,0x58),u8 *,0x1420);
 if((terrain&31)!=18||M2C_FIELD(map,u16 *,0x52a6)!=(terrain&0xe0))goto checkedFlag;}
 foundFlag:flag=1;
 checkedFlag:;
 }
 }
 map=*gCurrentMap;
 id=M2C_FIELD((u8 *)map+x+M2C_FIELD((u8 *)map+y*2+0x3700,u16 *,0x58),u8 *,0);
 if(!id)goto nextCell;
 unit=(u8 *)map+0x59a4+id*14;
 if(!IsUnitOnCurrentTeam(id)){
 if(!IsFootUnitKind(((UnkStruct_ov000_021A860C *)unit)->unk0))goto nextCell;
 if(!(M2C_FIELD(data_ov000_021b5bfc+((UnkStruct_ov000_021A860C *)unit)->unk0*112,u8 *,0x13)&7))goto nextCell;
 goto discard;
 }
 if(IsCurrentPlayerUnit((s16)id)!=1)goto nextCell;
 if(M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x)<=110) {
 if(((u32)(M2C_FIELD(unit,u16 *,8)<<16)>>30)==2){
 if(IsCaptureKind(((UnkStruct_ov000_021A860C *)unit)->unk0))capture=(s8)(capture+1);else combat=(s8)(combat+1);
 } else {
 if(IsCaptureKind(((UnkStruct_ov000_021A860C *)unit)->unk0))other=(s8)(other+1);
 else if(M2C_FIELD(data_ov000_021b5bfc+((UnkStruct_ov000_021A860C *)unit)->unk0*112,u8 *,0x13)&7)armed=(s8)(armed+1);
 }
 }
 if((((UnkStruct_ov000_021A860C *)unit)->unk0)==24&&!unit[12]&&!func_ov000_021a8984(((UnkStruct_ov000_021A860C *)unit)->unkB))transport=(s8)(transport+1);
 if((((UnkStruct_ov000_021A860C *)unit)->unk0)==25&&!unit[12]&&!func_ov000_021a8984(((UnkStruct_ov000_021A860C *)unit)->unkB))carrier=(s8)(carrier+1);
 nextCell:x++;map=*gCurrentMap;
 }
 }
 if(!flag)capture=(s8)(capture+other);
 capture=(s8)(capture-carrier*2);if(capture<0)capture=0;
 if(!(combat+armed)&&capture<=1)goto discard;
 required=transport+1;
 if(required*4>combat+capture)goto discard;
 M2C_FIELD(&gAiCommand,u8 *,6)=24;CommitAiAction(index);ResetAiTargetCandidates();return 1;
 discard: candidate[3]=253;
 }
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_ov000_021a41f8(void){
s32 func_020d2d18(u16,s32);u8 func_ov000_021a43a0(s32);s32 func_ov000_021a3dac(void);
s32 func_ov000_021a6264(s32);s32 func_ov000_021a5ffc(s32);u8 func_ov000_021a88c8(s32);
s32 func_ov000_021a379c(void);s32 func_ov000_021a36e4(void);s32 func_ov000_021a3644(s32);
void CommitAiAction(s32);
extern void **gCurrentMap;extern M2C_UNK gAiCommand;
void *p;u16 id;s32 a,r,n,x,y,z;
if(!func_ov000_021a43a0(2))return 0;
p=*gCurrentMap;id=M2C_FIELD(p,u16 *,0x52a4);
if(func_020d2d18(id,24)*10>M2C_FIELD((u8 *)p+id*140,s32 *,0x67a4))return 0;
if(func_ov000_021a3dac()==1)return 1;
r=func_ov000_021a6264(3);if(r==-1){r=func_ov000_021a5ffc(3);if(r==-1)return 0;}
a=func_ov000_021a88c8(24);n=func_ov000_021a379c();
if(!n){if(func_ov000_021a36e4()<=1)return 0;}
if(a){y=func_ov000_021a3644(24)+1;x=func_ov000_021a3644(25);z=func_ov000_021a36e4()-x*2;if(z<0)z=0;if(n+z<y*4)return 0;}
M2C_FIELD(&gAiCommand,u8 *,6)=24;CommitAiAction(r);return 1;
}

u8 func_ov000_021a4320(void) {
    s32 func_ov000_021a3210();
    s32 func_ov000_021a3364();
    s32 func_ov000_021a3c84();
    s32 func_ov000_021a41f8();
    u8 func_ov000_021a88c8(s32);
    extern void *gAiState;
    u8 var_r0;
    u8 temp;

    M2C_FIELD(gAiState, u8 *, 8) = func_ov000_021a88c8(1);
    temp = func_ov000_021a88c8(2);
    M2C_FIELD(gAiState, u8 *, 8) += temp;
    if (func_ov000_021a3210() == 1) {
        return 1U;
    }
    if (func_ov000_021a41f8() == 1) {
        return 1U;
    }
    if (func_ov000_021a3c84() == 1) {
        return 1U;
    }
    if (func_ov000_021a3364() == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a43a0(s32 arg0) {
    extern void *data_ov000_021df57c;
    u8 var_r0;

    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11) & arg0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a43c4(void) {
    extern void *data_ov000_021df57c;
    u8 var_r0;

    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11) & 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a43e8(s32 arg0) {
    s32 IsFootUnitKind();
    if ((IsFootUnitKind() != 0) || (arg0 == 4)) {
        return 1;
    }
    return 0;
}

s32 func_ov000_021a4414(void) {
s32 func_ov000_021a43e8(s32);s32 GetUnitAttackClass(s32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 data_ov000_021b5bfc[];
u8 *entries;s32 count7=0,count8=0,i,idx;void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16*,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(base,u16*,0x52a4)]+0x33;i++){
entries=(u8 *)base+0x59a4;
idx=i*14;
if((u32)(entries[idx]<<26)>>26){
if(!func_ov000_021a43e8((u32)(entries[idx]<<26)>>26)){
if(data_ov000_021b5bfc[((u32)(entries[idx]<<26)>>26)*112+19]&7){
if(GetUnitAttackClass((u32)(entries[idx]<<26)>>26)==0)count7++;
if(GetUnitAttackClass((u32)(entries[idx]<<26)>>26)==1)count8++;
}}}
base=*gCurrentMap;
}
if(count7>count8*3)return 0;
return 1;
}

s32 func_ov000_021a4510(void) {
s32 func_ov000_021a43e8(s32);s32 GetUnitAttackClass(s32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 data_ov000_021b5bfc[];
s32 a=0,b=0,i;
void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++){
u8 *entry=(u8 *)*gCurrentMap+0x59a4+i*14;
if(((u32)(entry[0]<<26)>>26)!=0 && !func_ov000_021a43e8((u32)(entry[0]<<26)>>26)){
if(data_ov000_021b5bfc[((u32)(entry[0]<<26)>>26)*112+19]&7){
if(GetUnitAttackClass((u32)(entry[0]<<26)>>26)==0)a++;
if(GetUnitAttackClass((u32)(entry[0]<<26)>>26)==1)b++;
}}
}
if(a>b)return 0;return 1;
}

s32 func_ov000_021a4608(void) {
s32 func_ov000_021a43e8(s32);s32 GetUnitAttackClass(s32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 data_ov000_021b5bfc[];
s32 a=0,b=0,i;
void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++){
u8 *entry=(u8 *)*gCurrentMap+0x59a4+i*14;
if(((u32)(entry[0]<<26)>>26)!=0 && !func_ov000_021a43e8((u32)(entry[0]<<26)>>26)){
if(data_ov000_021b5bfc[((u32)(entry[0]<<26)>>26)*112+19]&7 && ((u32)(entry[0]<<26)>>26)!=26){
if(GetUnitAttackClass((u32)(entry[0]<<26)>>26)==0)a++;
if(GetUnitAttackClass((u32)(entry[0]<<26)>>26)==1)b++;
}}
}
if(a>(b<<1))return 0;return 1;
}

s32 func_ov000_021a4704(void) {
    s32 func_ov000_021a43e8(s32);
    s32 GetUnitAttackClass(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 data_ov000_021b5bfc[];
    u8 *entries;
    s32 count5 = 0;
    s32 count6 = 0;
    s32 count11 = 0;
    s32 count7 = 0;
    s32 count8 = 0;
    s32 i;
    s32 idx;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];

    i = start + 1;
    if (i < (s32)(start + 0x33)) {
        idx = i * 0xE;
        entries = (u8 *)base + 0x59A4;
        do {
            if (((u32)((entries[idx]) << 0x1A) >> 0x1A) != 0) {
                if (func_ov000_021a43e8(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                    if (data_ov000_021b5bfc[((u32)((entries[idx]) << 0x1A) >> 0x1A) * 0x70 + 0x13] & 7) {
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) == 0x1A) {
                            count11 += 1;
                        } else {
                            if (GetUnitAttackClass(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                                count5 += 1;
                            }
                            if (GetUnitAttackClass(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 1) {
                                count6 += 1;
                            }
                        }
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) == 6) {
                            count7 += 1;
                        }
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) == 0xC) {
                            count8 += 1;
                        }
                    }
                }
            }
            i += 1;
            idx += 0xE;
        } while (i < (s32)(gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33));
    }
    if (count7 <= (count8 << 1)) {
        return 1;
    }
    if (count6 != 0) {
        count6 += count11 >> 1;
    }
    if (count5 > (count6 << 1)) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a484c(s32 arg0, s32 arg1) {
    s32 func_ov000_021a4414();
    s32 func_ov000_021a4510();
    s32 func_ov000_021a4608();
    s32 func_ov000_021a4704();

    switch (arg1) {
    case 10:
        return func_ov000_021a4414();
    case 26:
        return func_ov000_021a4510();
    case 11:
        return func_ov000_021a4608();
    case 12:
        return func_ov000_021a4704();
    }
    return 1;
}

u8 func_ov000_021a48ac(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    u8 var_r0;

    if (data_ov000_021dfd98[arg0 * 8] <= data_ov000_021dfd99[arg0 * 8] * 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a48dc(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    s32 temp_r0;
    s32 temp_r2;
    u8 var_r0;

    temp_r2 = data_ov000_021dfd98[arg0 * 8];
    temp_r0 = data_ov000_021dfd99[arg0 * 8];
    if (temp_r2 <= temp_r0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a4908(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    extern u8 data_ov000_021dfd9a[];
    u8 *p98;
    s32 var_r3;
    s32 temp_r1;

    var_r3 = data_ov000_021dfd99[arg0 * 8];
    temp_r1 = var_r3 - data_ov000_021dfd9a[arg0 * 8];
    p98 = data_ov000_021dfd98;
    if (temp_r1 != 0) {
        var_r3 = temp_r1;
    }
    if (p98[arg0 * 8] > (var_r3 << 1)) {
        return 0;
    }
    return 1;
}

#pragma opt_propagation off
s32 func_ov000_021a4944(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    extern u8 data_ov000_021dfd9a[];
    u32 temp_r1;
    s32 temp_r2;
    s32 var_ip;
    s32 temp_r3;

    var_ip = data_ov000_021dfd99[arg0 * 8];
    temp_r1 = data_ov000_021dfd9a[arg0 * 8];
    temp_r2 = var_ip - temp_r1;
    temp_r3 = data_ov000_021dfd98[arg0 * 8];
    if (temp_r2 != 0) {
        var_ip = temp_r2 + ((s32)temp_r1 >> 1);
    }
    if (temp_r3 > (var_ip << 1)) {
        return 0;
    }
    return 1;
}
#pragma opt_propagation reset
s32 func_ov000_021a4980(s32 arg0, s32 arg1) {
    u8 func_ov000_021a48ac(s32);
    u8 func_ov000_021a48dc(s32);
    s32 func_ov000_021a4908(s32);
    s32 func_ov000_021a4944(s32);

    switch (arg1) {
    case 10:
        return func_ov000_021a48ac(arg0);
    case 26:
        return func_ov000_021a48dc(arg0);
    case 11:
        return func_ov000_021a4908(arg0);
    case 12:
        return func_ov000_021a4944(arg0);
    }
    return 1;
}

u8 func_ov000_021a49e0(s32 arg0) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 func_020a886c(u16, M2C_UNK);
    extern void **gCurrentMap;
    extern void *gAiState;
    s32 temp_r2;
    s32 temp_r4;
    s32 temp_r5;
    u16 temp_r0;
    u8 var_r0;
    void *temp_r1;

    if (M2C_FIELD(gAiState, s32 *, 0x14) != 0) {
        return 0U;
    }
    temp_r4 = M2C_FIELD(gAiState, s32 *, 0x10);
    temp_r1 = *gCurrentMap;
    temp_r0 = M2C_FIELD(temp_r1, u16 *, 0x52A4);
    temp_r5 = (temp_r0 * 0x8C) + (s32) (temp_r1 + 0x67A4);
    temp_r2 = M2C_FIELD(temp_r5, s32 *, 8);
    if (arg0 <= (s32) (temp_r2 - temp_r4)) {
        return 0U;
    }
    if (arg0 > (s32) ((temp_r2 * 2) - temp_r4)) {
        return 0U;
    }
    if ((s32) (arg0 + func_0207c8ec((func_020a886c(temp_r0, 0) + 0x64) * 0x7D0, 0x64)) < (s32) ((M2C_FIELD(temp_r5, s32 *, 0) + M2C_FIELD(temp_r5, s32 *, 8)) - temp_r4)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

