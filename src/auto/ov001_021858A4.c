/* 20 functions from 0x021858A4 to 0x021867AC (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct InitBlock68 { u32 words[17]; } InitBlock68;

void func_ov001_02185f38(u16 *);
void func_ov001_02186090(u16 *);

#pragma opt_strength_reduction off
void func_ov001_021858a4(s32 arg0) {
extern s32 data_ov001_02193e0c;
extern const u8 data_ov001_0218fbd2[];
M2C_UNK func_ov001_0218a4d4(M2C_UNK,M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK Ov001_MoveSpriteLayout(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218c924(M2C_UNK,M2C_UNK);
void func_ov001_02185980(s32);
s32 pos[2],i;
func_ov001_0218a4d4(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[2],0,&pos[1],&pos[0]);
pos[1]-=8;
if(pos[1]>80){
for(i=2;i<5;i++)Ov001_MoveSpriteLayout(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
return;
}
pos[1]=80;
for(i=2;i<5;i++)Ov001_MoveSpriteLayout(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
func_ov001_0218c924(arg0,(M2C_UNK)func_ov001_02185980);
}
#pragma opt_strength_reduction reset
void func_ov001_02185980(s32 arg0) {
    extern M2C_UNK data_ov001_02193e0c;
    extern const u8 data_ov001_0218fbd2[];
    M2C_UNK func_ov001_0218a4d4(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK Ov001_MoveSpriteLayout(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c924(M2C_UNK, M2C_UNK);
    void func_ov001_02185a5c(s32);
    s32 pos[2];
    s32 i;

    func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c, void **, 4))[1], 0, &pos[1], &pos[0]);
    pos[1] -= 8;
    if (pos[1] > 32) {
        for (i = 1; i < 5; i++) {
            Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c, void **, 4))[i], -1, pos[1], ((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
        }
        return;
    }
    pos[1] = 32;
    for (i = 1; i < 5; i++) {
        Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&data_ov001_02193e0c, void **, 4))[i], -1, pos[1], ((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
    }
    func_ov001_0218c924(arg0, (M2C_UNK)func_ov001_02185a5c);
}

#pragma opt_strength_reduction off
void func_ov001_02185a5c(s32 arg0) {
extern s32 data_ov001_02193e0c,data_ov001_02193e10;
extern const u8 data_ov001_0218fbd2[];
M2C_UNK func_ov001_0218a4d4(M2C_UNK,M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK Ov001_MoveSpriteLayout(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218c92c(M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218a1cc(M2C_UNK);
M2C_UNK func_ov001_0218b71c(M2C_UNK);
s32 pos[2],i;
func_ov001_0218a4d4(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[0],0,&pos[1],&pos[0]);
pos[1]-=8;
for(i=0;i<5;i++)Ov001_MoveSpriteLayout(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i],-1,pos[1],M2C_FIELD(data_ov001_0218fbd2+i*4,u16 *,2));
if(pos[1]>0x1d6)return;
if(pos[1]<0x100)return;
func_ov001_0218c92c(0,arg0);
for(i=0;i<5;i++)func_ov001_0218a1cc(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i]);
func_ov001_0218b71c(&data_ov001_02193e10);
}
#pragma opt_strength_reduction reset
s32 func_ov001_02185b34(void) {
    extern M2C_UNK data_ov001_02193e0c;
    if (M2C_FIELD(&data_ov001_02193e0c, void **, 4) == NULL) {
        return 1;
    }
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c, void **, 4), u8 *, 0x18) == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02185b60(s32 arg0) {
    s32 Ov001_LocalizePath(s32);
    s32 Ov001_LoadFile(s32, s32, s32);
    void func_ov001_02185ba8(s32);
    extern s32 data_ov001_02190be4[];
    extern s32 data_ov001_02193e0c;
    data_ov001_02193e0c = Ov001_LoadFile(Ov001_LocalizePath(data_ov001_02190be4[arg0]), 0, 4);
    func_ov001_0218c884(1, func_ov001_02185ba8, 0, 0x78);
}

void func_ov001_02185ba8(s32 arg0) {
    extern s32 data_ov001_02193e0c;
    DC_FlushRange(data_ov001_02193e0c, 0x600);
    func_0200442c(data_ov001_02193e0c, 0, 0x600);
    Ov001_FreeFile(data_ov001_02193e0c);
    func_ov001_0218c92c(1, arg0);
}

s32 func_ov001_02185bf4(s32 arg0){
void *func_ov001_0218b6f8(s32,s32);u64 GetSystemTick(void);
s32 func_02012218(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_02011af8(void *);u16 func_02011e98(void);void func_02007740(void *);
void MI_CpuCopy8(void *,void *,s32);s32 func_ov001_02185d78(void);
M2C_UNK func_ov001_0218c884(M2C_UNK,void (*)(void),M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218b71c(M2C_UNK);
void func_ov001_02185ea8();void Ov001_ReportConnectionState();
extern void *gOv001ConnectionState;extern const u8 data_ov001_0218fbfc[],data_ov001_0218fbf0[];
u8 buf[0x54];void *p;u64 ts;void **state;
gOv001ConnectionState=func_ov001_0218b6f8(0x1ba0,0x20);
M2C_FIELD(gOv001ConnectionState,s32 *,0x1370)=arg0;
ts=GetSystemTick();
state=&gOv001ConnectionState;
p=*state;
M2C_FIELD(p,u32 *,0x1b88)=(u32)ts;M2C_FIELD(p,u32 *,0x1b8c)=(u32)(ts>>32);
if(func_02012218((M2C_UNK)*state,(M2C_UNK)func_ov001_02185ea8,3)==2){
do {
func_02011af8((u8 *)*state+0x13b8);
p=*state;
} while(M2C_FIELD(p,u16 *,0x13b8)!=2);
{
*(InitBlock68 *)((u8 *)p+0x1374)=*(const InitBlock68 *)data_ov001_0218fbfc;
{void *base=(u8 *)p+0xf00;p=(u8 *)p+0x1000;M2C_FIELD(p,void **,0x374)=base;}
}
M2C_FIELD(gOv001ConnectionState,u16 *,0x137c)=func_02011e98();
func_02007740(buf);
MI_CpuCopy8((void *)data_ov001_0218fbf0,(u8 *)gOv001ConnectionState+0x1388,8);
M2C_FIELD(gOv001ConnectionState,u8 *,0x1391)=1;
MI_CpuCopy8(buf+4,(u8 *)gOv001ConnectionState+0x1394,M2C_FIELD(buf,u16 *,0x1a)<<1);
if(func_ov001_02185d78()){
M2C_FIELD(gOv001ConnectionState,M2C_UNK *,0x1b90)=func_ov001_0218c884(0,Ov001_ReportConnectionState,0,0x78);
return 1;
}
}
func_ov001_0218b71c((M2C_UNK)&gOv001ConnectionState);return 0;
}

s32 func_ov001_02185d78(void) {
    s32 WFC_SendRequestPacket(void (*)(void), void *);
    void func_ov001_02185ea8();
    extern void *gOv001ConnectionState;
    if (WFC_SendRequestPacket(func_ov001_02185ea8, (s8 *)gOv001ConnectionState + 0x1374) == 2) {
        return 1;
    }
    return 0;
}

s32 func_ov001_02185dac(void) {
    s32 func_02011af8(void *);
    s32 func_02012274(void (*)(void));
    s32 func_020122ac(void (*)(void));
    void func_ov001_02185ea8(u16 *);
    void func_ov001_0218c94c(s32);
    M2C_UNK func_ov001_0218b71c(M2C_UNK);
    extern void *gOv001ConnectionState;

    *(u8 *)((s8 *)gOv001ConnectionState + 0x1b94) = 1;
    func_02011af8((s8 *)gOv001ConnectionState + 0x13b8);
    if (*(u16 *)((s8 *)gOv001ConnectionState + 0x13b8) != 2) {
        if (func_02012274((void (*)(void))func_ov001_02185ea8) != 2) {
            return 0;
        }
        do {
            func_02011af8((s8 *)gOv001ConnectionState + 0x13b8);
        } while (*(u16 *)((s8 *)gOv001ConnectionState + 0x13b8) != 2);
    }
    if (func_020122ac((void (*)(void))func_ov001_02185ea8) != 2) {
        return 0;
    }
    if (*((s32 *)((s8 *)gOv001ConnectionState + 0x1b90)) != 0) {
        func_ov001_0218c94c(0);
    }
    if (*((u8 *)((s8 *)gOv001ConnectionState + 0x1b94)) == 2) {
        func_ov001_0218b71c((M2C_UNK)(void *)(&gOv001ConnectionState));
    }
    return 1;
}

void func_ov001_02185e90(s32 arg0) {
    extern void *gOv001ConnectionState;
    M2C_FIELD(gOv001ConnectionState, s32 *, 0x1370) = arg0;
}

void func_ov001_02185ea8(u16 *p) {
extern void *gOv001ConnectionState;u32 v;void *q;
if(p[1])return;q=gOv001ConnectionState;
v=M2C_FIELD(q,u8 *,0x1b94);
if(v){if(p[0]==2)M2C_FIELD(q,u8 *,0x1b94)=2;return;}
v=p[0];if(v!=38)return;
v=p[4];switch(v){case 5:if(M2C_FIELD(q,u8 *,0x1b96))func_ov001_02186090(p);else func_ov001_02185f38(p);func_ov001_02185d78();break;
case 4:func_ov001_02185d78();break;default:SystemHalt(p);break;}
}

void func_ov001_02185f38(u16 *arg0) {
    void DC_InvalidateRange(void *, s32);
    s32 ByteCompareN(void *, const void *, s32);
    void MI_CpuCopy8(void *, void *, s32);
    extern void *gOv001ConnectionState;
    extern const u8 data_ov001_0218fbf0[];
    extern const u8 gWfcEmptySlotId[];
    u8 *rec;
    s32 k;
    u8 *slot;
    s32 j;
    u8 *base;

    for (j = 0; j < arg0[7]; j++) {
        rec = ((void **)arg0)[4 + j];
        DC_InvalidateRange(rec, 0xC0);
        if (ByteCompareN(rec + 0xC, data_ov001_0218fbf0, 8) != 0) continue;
        base = gOv001ConnectionState;
        slot = base + 0x1300;
        for (k = 0; k < 16; k++) {
            if (ByteCompareN(rec + 4, slot, 6) == 0) {
                if (*(u8 *)(base + k * 7 + 0x1306) != 0) goto next;
                if (!(rec[0x15] & 1)) goto next;
                if (M2C_FIELD(base, void **, 0x1370) != NULL) {
                    ((void (*)(s32))M2C_FIELD(base, void **, 0x1370))(1);
                }
                return;
            }
            slot += 7;
        }
        slot = base + 0x1300;
        for (k = 0; k < 16; k++) {
            if (ByteCompareN(slot, gWfcEmptySlotId, 6) == 0) {
                MI_CpuCopy8(rec + 4, base + 0x1300 + k * 7, 6);
                *(u8 *)((u8 *)gOv001ConnectionState + k * 7 + 0x1306) = (rec[0x15] & 1) ? 1 : 0;
                break;
            }
            slot += 7;
        }
    next:;
    }
}

void func_ov001_02186090(u16 *arg0) {
    void DC_InvalidateRange(void *, s32);
    s32 ByteCompareN(void *, const void *, s32);
    extern void *gOv001ConnectionState;
    extern const u8 data_ov001_0218fbf0[];
    extern M2C_UNK data_ov001_0219174c;

    void *g = gOv001ConnectionState;
    if (*((u8 *)g + 0x1B95) != 0) {
        void (*cb)(s32, void *) = *(void (**)(s32, void *))( (u8 *)g + 0x1370);
        if (cb != 0) {
            cb(0x8000000, &data_ov001_0219174c);
        }
        return;
    }

    DC_InvalidateRange((u8 *)g + 0x0F00, 0x400);

    {
        s32 j;
        u8 *base;
        u8 *rec;
        s32 k;
        u16 count = arg0[7];

        for (j = 0; j < count; j = j + 1) {
            rec = ((void **)arg0)[4 + j];
            if (ByteCompareN(rec + 0x0C, data_ov001_0218fbf0, 8) != 0) {
                continue;
            }
            if (!(rec[0x15] & 1)) {
                continue;
            }
            base = (u8 *)g + 0x1300;
            for (k = 0; k < 16; k = k + 1) {
                if (ByteCompareN(rec + 4, base, 6) == 0) {
                    if (*((u8 *)g + k * 7 + 0x1306) != 0) {
                        break;
                    }
                    {
                        void (*cb)(s32) = *(void (**)(s32))((u8 *)g + 0x1370);
                        if (cb == 0) {
                            *((u8 *)g + 0x1B95) = 1;
                            return;
                        }
                        cb(1);
                        return;
                    }
                }
                base += 7;
            }
        }
    }
}

/* Connection-watch timer callback: once the watch delay after the connection
 * started has passed, scan the 16 player slots and report the final state
 * (none, all online, or mixed) through the status callback, then stop the
 * timer and mark the watch done. */
void Ov001_ReportConnectionState(s32 arg0) {
    u64 GetSystemTick(void);
    s32 ByteCompareN(void *, const void *, s32);
    M2C_UNK func_ov001_0218c92c(M2C_UNK, M2C_UNK);
    extern void *gOv001ConnectionState;
    extern const u8 gWfcEmptySlotId[];
    u64 now;
    s32 i;
    s32 hasOnline;
    s32 hasOffline;
    u8 *slotId;
    u8 *slot;
    u8 *state;

    now = GetSystemTick();
    state = gOv001ConnectionState;
    if (now < M2C_FIELD(state, u64 *, WFC_CONN_WATCH_START) + 0x17F898) {
        return;
    }
    hasOffline = 0;
    hasOnline = 0;
    i = 0;
    slot = state;
    slotId = state + WFC_CONN_SLOTS;
    for (; i < WFC_CONN_SLOT_COUNT; i++) {
        if (ByteCompareN(slotId, gWfcEmptySlotId, 6) != 0) {
            if (M2C_FIELD(slot, u8 *, WFC_CONN_SLOTS + WFC_CONN_SLOT_ONLINE) != 0) {
                hasOnline = 1;
            } else {
                hasOffline = 1;
            }
        }
        slotId += WFC_CONN_SLOT_STRIDE;
        slot += WFC_CONN_SLOT_STRIDE;
    }
    if (hasOnline && hasOffline) {
        if (M2C_FIELD(state, void **, WFC_CONN_STATUS_CB) != NULL) {
            ((void (*)(s32)) M2C_FIELD(state, void **, WFC_CONN_STATUS_CB))(WFC_CONN_STATUS_MIXED);
        }
    } else if (hasOnline) {
        if (M2C_FIELD(state, void **, WFC_CONN_STATUS_CB) != NULL) {
            ((void (*)(s32)) M2C_FIELD(state, void **, WFC_CONN_STATUS_CB))(WFC_CONN_STATUS_ONLINE);
        }
    } else if (!hasOffline) {
        if (M2C_FIELD(state, void **, WFC_CONN_STATUS_CB) != NULL) {
            ((void (*)(s32)) M2C_FIELD(state, void **, WFC_CONN_STATUS_CB))(WFC_CONN_STATUS_NONE);
        }
    }
    M2C_FIELD(gOv001ConnectionState, s32 *, WFC_CONN_WATCH_TIMER) = 0;
    M2C_FIELD(gOv001ConnectionState, u8 *, WFC_CONN_WATCH_DONE) = 1;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_021862d8(void *a, s32 b, void *c, s32 d, s32 e) {
    volatile s32 x = 1;
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)x;
}

void func_ov001_02186604(void) {
extern void *gOv001RegionMenu;void func_ov001_02186c68();s32 func_ov001_0218c884(s32,void (*)(),s32,s32);
func_ov001_0218c92c(0,M2C_FIELD(gOv001RegionMenu,s32 *,20));
M2C_FIELD(gOv001RegionMenu,s32 *,20)=func_ov001_0218c884(1,func_ov001_02186c68,0,120);
}

s8 func_ov001_02186648(void) {
    extern void *gOv001RegionMenu;
    return M2C_FIELD(gOv001RegionMenu, s8 *, 0x1B);
}

s32 func_ov001_0218665c(void) {
    extern void *gOv001RegionMenu;
    if (gOv001RegionMenu != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02186678(s32 a) {
extern void *gOv001RegionMenu;void func_ov001_021866d8();
M2C_FIELD(gOv001RegionMenu,s8 *,26)--;
func_02003a10(0x4000050,M2C_FIELD(gOv001RegionMenu,s8 *,26));
if(M2C_FIELD(gOv001RegionMenu,s8 *,26)<=-12)func_ov001_0218c924(a,func_ov001_021866d8);
}

void func_ov001_021866d8(s32 arg0) {
    extern void *gOv001RegionMenu;
    extern const u16 data_ov001_0218fc9e[];
    M2C_UNK Ov001_SetRegionMenuY(M2C_UNK);
    void func_ov001_02186908(void);
    void func_ov001_021867ac(void);
    M2C_UNK func_ov001_0218c884(M2C_UNK, void (*)(void), M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c92c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a4d4(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    s32 pos[2];

    func_ov001_0218a4d4(M2C_FIELD(gOv001RegionMenu, s32 *, 0), 0, &pos[1], &pos[0]);
    pos[0] -= 0xc;
    if (pos[0] > data_ov001_0218fc9e[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) << 1]) {
        Ov001_SetRegionMenuY(pos[0]);
        return;
    }
    Ov001_SetRegionMenuY(data_ov001_0218fc9e[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) << 1]);
    if (M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) == 5) {
        M2C_FIELD(gOv001RegionMenu, s32 *, 0x14) =
            (M2C_UNK)func_ov001_0218c884(0, (void (*)(void))func_ov001_02186908, 0, 0x78);
    } else {
        M2C_FIELD(gOv001RegionMenu, s32 *, 0x14) =
            (M2C_UNK)func_ov001_0218c884(0, (void (*)(void))func_ov001_021867ac, 0, 0x78);
    }
    func_ov001_0218c92c(1, arg0);
}

