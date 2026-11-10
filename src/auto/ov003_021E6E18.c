/* 15 functions from 0x021E6E18 to 0x021E771C (ov003), found by ds-decomp. */
#include "common.h"
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6d28(void);
s32 func_020848c4(void);
s32 func_ov003_021e6eb8(s32);
static inline u8 SlotOwner(void *p, s32 i) {return M2C_FIELD(p+i,u8 *,0x74);}
static inline u8 SlotEmpty(void *p,s32 i) {u8 result;if(SlotOwner(p,i)==255)result=1;else result=0;return result;}
static inline void SetSlotValue(void *p,u8 v) {
u8 owner;
if(func_ov003_021e6cfc()) {owner=SlotOwner(p,M2C_FIELD(p,u8 *,7));if(owner!=func_020848c4() && !SlotEmpty(p,M2C_FIELD(p,u8 *,7)))goto store;}
if(func_ov003_021e6d28()) {owner=SlotOwner(p,M2C_FIELD(p,u8 *,7));if(owner!=func_020848c4())goto store;}
if(!func_ov003_021e6eb8(v))return;
store:
M2C_FIELD(p+M2C_FIELD(p,u8 *,7),u8 *,10)=v;M2C_FIELD(p,u8 *,8)=v;
}
static inline void SelectSlot(void *p,u8 i) {M2C_FIELD(p,u8 *,7)=i;SetSlotValue(p,M2C_FIELD(p+i,u8 *,10));}

u8 func_ov003_021e6e18(void) {
    void *func_ov003_021e6d6c();
    return M2C_FIELD(func_ov003_021e6d6c(), u8 *, 1);
}

u8 func_ov003_021e6e28(s32 arg0) {
    s32 func_ov003_021e6e08();
    return (u8) (arg0 - func_ov003_021e6e08());
}

u8 func_ov003_021e6e40(void) {
    s32 func_ov003_021f1490();
    u8 var_r0;

    if (func_ov003_021f1490() == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov003_021e6e5c(void) {
    if ((func_ov003_021f1490() == 3) || (func_ov003_021f1490() == 1) || (func_ov003_021f1490() == 5)) {
        return 1;
    }
    return 0;
}

s32 func_ov003_021e6e94(s32 arg0) {
    M2C_UNK func_ov003_021e6cac(s32, M2C_UNK, M2C_UNK);
    extern s32 data_ov003_0220f0c8[][2];
    func_ov003_021e6cac(arg0, 0, 0xD);
    return data_ov003_0220f0c8[arg0][0];
}

s32 func_ov003_021e6eb8(s32 arg0) {
    s32 func_020bf894();
    M2C_UNK func_ov003_022008b8(s32);
    if (arg0 == 0xC) {
        return 1;
    }
    if ((func_ov003_021e6e40() != 0) && (arg0 == 0xB)) {
        return 0;
    }
    func_ov003_022008b8(arg0);
    return func_020bf894();
}

/* Handle one input action on the waypoint/segment cursor menu: move the cursor
 * over the slot groups (previous/next), place the currently held unit into a
 * slot, or scroll the map view. The selected action is then passed to the
 * display refresh (func_01ffa810) and stored as the list's current handle. */
void func_ov003_021e6ef4(void *arg0,int action){
s32 func_ov003_021e6cfc(void);s32 func_ov003_021e6d28(void);s32 func_020848c4(void);s32 func_020846a4(void);
s32 func_01ffa810(s32);
u8 *list=arg0;
switch((u32)action){
case 0:case 1:case 2:case 3:SelectSlot(list,action);break;
case 27:action=list[7];break;
case 4:case 5:case 6:case 7:SelectSlot(list,action-4);break;
case 28:action=(u16)(list[7]+4);break;
case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:
if(func_020846a4()){
s32 canUseSlot;u8 slot=list[7];
if(!func_020846a4())canUseSlot=0;
else {u8 *owners=list+0x74;u8 owner=owners[slot];if(owner==func_020848c4())canUseSlot=1;else if(func_ov003_021e6cfc() && ((u8)(owners[slot]==255)))canUseSlot=1;else canUseSlot=0;}
if(!canUseSlot){
s32 playerId=func_020848c4();u8 i; s32 foundSlot;
for(i=0;i<list[4];i++){if(playerId==M2C_FIELD(list+i,u8 *,0x74)){foundSlot=(s8)i;goto found_slot;}}
foundSlot=-1;
found_slot:SelectSlot(list,foundSlot);
}}
SetSlotValue(list,action-8);
break;
case 29:action=(u16)(list[8]+8);break;
case 21:case 22:case 23:case 24:SelectSlot(list,action-21);break;
case 30:action=(u16)(list[7]+21);break;
case 25:M2C_FIELD(M2C_FIELD(list,void **,0xdc),u16 *,0x68)=list[0xe4]+list[7];M2C_FIELD(M2C_FIELD(list,void **,0xdc),u16 *,0x6a)=list[0xe5]+list[7];break;
}
M2C_FIELD(list,s32 *,0xe0)=func_01ffa810(action);
}

u8 func_ov003_021e73bc(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 0x74);
}

u8 func_ov003_021e73c8(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD((arg0 + arg1), u8 *, 0x74) == 0xFF) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021e73e4(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 7);
}

s32 func_ov003_021e73ec(s32 arg0, s32 arg1) {
    s32 func_020846a4();
    s32 func_020848c4();
    s32 func_ov003_021e6cfc();
    u8 *temp_r4;
    u8 temp_r5;
    s32 var_r0;
    if (func_020846a4() == 0) return 0;
    temp_r4 = (u8 *)(arg0 + 0x74);
    temp_r5 = temp_r4[arg1];
    if (temp_r5 == func_020848c4()) return 1;
    if (func_ov003_021e6cfc() != 0) {
        if (temp_r4[arg1] == 0xFF) var_r0 = 1;
        else var_r0 = 0;
        if (var_r0 & 0xFF) return 1;
    }
    return 0;
}

u8 func_ov003_021e7450(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 8);
}

void func_ov003_021e7458(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02087db8(void *, M2C_UNK);
    M2C_UNK func_020aad18(void *);
    s32 var_r1;
    s32 count;
    void *temp_r0;
    count = M2C_FIELD(arg0, s8 *, 4);
    temp_r0 = M2C_FIELD(arg0 + arg1 * 4, void **, 0x78);
    if (arg1 < arg2 + count) {
        func_020aad18(temp_r0);
        return;
    }
    temp_r0 = M2C_FIELD(temp_r0, void **, 0x64);
    if (M2C_FIELD(temp_r0, u8 *, 0x12) != 0) var_r1 = 1;
    else var_r1 = 0;
    if (!(var_r1 & 0xFF)) return;
    func_02087db8(temp_r0, 1);
}

s8 func_ov003_021e74a4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 4);
}

/* Re-initialize a 26-slot waypoint/segment list. Each slot (p+i*4, +0x78) is a
 * segment; seg+0x64 is its sub-object whose +0x12 entry count tells whether it
 * is active. In mode 0 (path), slots 0-20 are (re)built for the current path
 * state (func_ov003_021e7458) or cleared (func_020aad18), and slots 21-25 are
 * released if active; in mode 1 (grid), slots 0-20 are released and 21-25 built.
 * The list's head/tail next-pointers are re-linked to the active range, then the
 * display is refreshed (func_ov003_021e6ef4). */
void func_ov003_021e74ac(void *list, s32 mode) {
    s32 func_020846a4(void);
    M2C_UNK func_02087db8(void *, M2C_UNK);
    M2C_UNK func_020aad18(void *);
    s32 func_ov003_021e6cac(s32, s32, s32);
    void func_ov003_021e6ef4(void *, s32);
    u32 i;
    u32 j;
    s32 active;
    void *sub;

    switch (mode) {
    case 0:
        if (func_020846a4() != 0) M2C_FIELD(list, s8 *, 0xe4) = 0;
        else M2C_FIELD(list, s8 *, 0xe4) = 4;
        M2C_FIELD(list, s8 *, 0xe5) = 0;
        i = 0;
        do {
            if (!func_ov003_021e6cac(i, 21, 24)) {
                if (func_ov003_021e6cac(i, 0, 3)) func_ov003_021e7458(list, i, 0);
                else if (func_ov003_021e6cac(i, 4, 7)) func_ov003_021e7458(list, i, 4);
                else func_020aad18(M2C_FIELD(list + i * 4, void **, 0x78));
            } else {
                sub = M2C_FIELD(M2C_FIELD(list + i * 4, void **, 0x78), void **, 0x64);
                if (M2C_FIELD(sub, u8 *, 0x12)) active = 1;
                else active = 0;
                if (active & 255) func_02087db8(sub, 1);
            }
            i = (u8)(i + 1);
        } while (i < 26);
        M2C_FIELD(M2C_FIELD(list, void **, 0x78), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) - 1;
        M2C_FIELD(M2C_FIELD(list + (M2C_FIELD(list, s8 *, 4) - 1) * 4, void **, 0x78), s16 *, 0x6e) = 0;
        M2C_FIELD(M2C_FIELD(list, void **, 0x88), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) + 3;
        M2C_FIELD(M2C_FIELD(list + (M2C_FIELD(list, s8 *, 4) + 3) * 4, void **, 0x78), s16 *, 0x6e) = 4;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) - 1;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6e) = 0;
        break;
    case 1:
        M2C_FIELD(list, s8 *, 0xe5) = 21;
        j = 0;
        M2C_FIELD(list, s8 *, 0xe4) = 21;
        do {
            if (j >= 21) {
                if (func_ov003_021e6cac(j, 21, 24)) func_ov003_021e7458(list, j, 21);
                else func_020aad18(M2C_FIELD(list + j * 4, void **, 0x78));
            } else {
                sub = M2C_FIELD(M2C_FIELD(list + j * 4, void **, 0x78), void **, 0x64);
                if (M2C_FIELD(sub, u8 *, 0x12)) active = 1;
                else active = 0;
                if (active & 255) func_02087db8(sub, 1);
            }
            j = (u8)(j + 1);
        } while (j < 26);
        M2C_FIELD(M2C_FIELD(list, void **, 0xcc), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) + 20;
        M2C_FIELD(M2C_FIELD(list + (M2C_FIELD(list, s8 *, 4) + 20) * 4, void **, 0x78), s16 *, 0x6e) = 21;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) + 20;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6e) = 21;
        break;
    }
    func_ov003_021e6ef4(list, 25);
}

