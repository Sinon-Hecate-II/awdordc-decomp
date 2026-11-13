/* 24 functions from 0x02002060 to 0x02003058 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"

void func_02002060(s32 arg0, s32 arg1) {
    M2C_FIELD((void *)0x04000280, s16 *, 0) = 1;
    M2C_FIELD((void *)0x04000280, s32 *, 0x10) = 0;
    M2C_FIELD((void *)0x04000280, s32 *, 0x14) = arg0;
    M2C_FIELD((void *)0x04000280, s32 *, 0x18) = arg1;
    M2C_FIELD((void *)0x04000280, s32 *, 0x1C) = 0;
}

s32 func_02002088(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A0;
}

s32 func_020020c4(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A8;
}

s32 func_02002100(s32 *arg0, s32 *arg1) {
    return ((s64)arg0[0] * arg1[0] + (s64)arg0[1] * arg1[1] + (s64)arg0[2] * arg1[2] + 0x800) >> 12;
}

void func_0200213c(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 x = ((s64)arg0[1] * arg1[2] - (s64)arg0[2] * arg1[1] + 0x800) >> 12;
    s32 y = ((s64)arg0[2] * arg1[0] - (s64)arg0[0] * arg1[2] + 0x800) >> 12;
    s32 z = ((s64)arg0[0] * arg1[1] - (s64)arg0[1] * arg1[0] + 0x800) >> 12;
    arg2[0] = x; arg2[1] = y; arg2[2] = z;
}

typedef volatile unsigned int vu32;
void func_020021c0(s32 *a, s32 *b) {
 s64 sq=(s64)a[1]*a[1]; sq+=(s64)a[0]*(*(volatile s32*)a); sq+=(s64)a[2]*a[2];
 *(volatile u16*)0x4000280=2; *(volatile s32*)0x4000290=0; *(volatile s32*)0x4000294=0x1000000;
 *(volatile u32*)0x4000298=(u32)sq; *(volatile u32*)0x400029c=(u32)(sq>>32);
 *(volatile u16*)0x40002b0=1;
 *(volatile u32*)0x40002b8=(u32)(sq<<2); *(volatile u32*)0x40002bc=(u32)((sq<<2)>>32);
 while(*(volatile u16*)0x40002b0&0x8000){}
 {s32 scale=*(volatile s32*)0x40002b4; s64 D,P; while(*(volatile u16*)0x4000280&0x8000){} D=*(volatile s64*)0x40002a0; P=D*scale;
 b[0]=(s32)((P*a[0]+(1LL<<44))>>45); b[1]=(s32)((P*a[1]+(1LL<<44))>>45); b[2]=(s32)((P*a[2]+(1LL<<44))>>45); }
}

void func_020022d8(void) {

}

/* Initializes the DS display: powers the engines on, resets the VRAM bank
 * allocator, takes a 3D/GX resource id, clears the display control and status,
 * loads the initial main/sub display register blocks (or clears them when none
 * is installed, gGxInitTables+4 == -1) and sets both engines' BG2/BG3 affine
 * matrices to identity (0x100 = 1.0 in 8.8 fixed point). */
void GX_InitDisplay(void) {
void GX_ResetBankState(void); s32 func_0200558c(void); void func_02007958(void); void DmaFill(s32,void *,s32,s32); void CpuFill(s32,void *,s32);
extern s16 data_0212dbc0; extern s16 data_020f5200;
s32 resourceId;
*(volatile u16 *)0x4000304 |= 0x8000;                      /* POWCNT1: LCD on */
*(volatile u16 *)0x4000304 = (*(volatile u16 *)0x4000304 & ~0x20e)|0x20e;
*(volatile u16 *)0x4000304 |= 1;
GX_ResetBankState();
while(M2C_FIELD(&data_0212dbc0,u16 *,2)==0) {
resourceId=func_0200558c();
if(resourceId==-3) func_02007958();                        /* no id free: hang */
M2C_FIELD(&data_0212dbc0,u16 *,2)=resourceId;
}
*(volatile u16 *)0x4000004=0;                              /* DISPSTAT */
*(volatile u32 *)0x4000000=0;                              /* DISPCNT */
if(M2C_FIELD(&data_020f5200,s32 *,4)!=-1) {
DmaFill(M2C_FIELD(&data_020f5200,s32 *,4),(void *)0x4000008,0,0x60);   /* main BG/BG2-3 regs */
*(volatile u16 *)0x400006c=0;
DmaFill(M2C_FIELD(&data_020f5200,s32 *,4),(void *)0x4001000,0,0x70);   /* sub engine regs */
} else {
CpuFill(0,(void *)0x4000008,0x60);
*(volatile u16 *)0x400006c=0;
CpuFill(0,(void *)0x4001000,0x70);
}
*(volatile u16 *)0x4000020=0x100;                          /* BG2PA */
*(volatile u16 *)0x4000026=0x100;                          /* BG2PD */
*(volatile u16 *)0x4000030=0x100;                          /* BG3PA */
*(volatile u16 *)0x4000036=0x100;                          /* BG3PD */
*(volatile u16 *)0x4001020=0x100;
*(volatile u16 *)0x4001026=0x100;
*(volatile u16 *)0x4001030=0x100;
*(volatile u16 *)0x4001036=0x100;
}

s32 func_02002428(s32 a) {
s32 v=*(volatile u16 *)0x4000004 & 0x10;
if(a!=0){*(volatile u16 *)0x4000004 |= 0x10;return v;}
*(volatile u16 *)0x4000004 &= ~0x10;
return v;
}

s32 GX_SetVBlankIrq(s32 a) {
s32 v=*(volatile u16 *)0x4000004 & 8;
if(a!=0){*(volatile u16 *)0x4000004 |= 8;return v;}
*(volatile u16 *)0x4000004 &= ~8;
return v;
}

void func_02002490(void) {
    extern s16 data_020f5200;
    extern s16 data_0212dbc0;
    s32 temp_ip;

    temp_ip = *(s32 *)0x04000000;
    data_020f5200 = 0;
    data_0212dbc0 = (s16) ((u32) (temp_ip & 0x30000) >> 0x10);
    *(s32 *)0x04000000 = temp_ip & ~0x30000;
}

void GX_TurnOnDisplay(void) {
 extern s16 data_020f5200, data_0212dbc0;
 u16 v;
 data_020f5200 = 1;
 v = data_0212dbc0;
 if (v != 0) {
  *(volatile u32 *)0x4000000 = (*(volatile u32 *)0x4000000 & ~0x30000) | ((u32)v << 16);
  return;
 }
 *(volatile u32 *)0x4000000 |= 0x10000;
}

void GX_ConfigureDisplay(u32 a,u32 b,u32 c) {
extern s16 data_020f5200,data_0212dbc0;
u32 flag=(u16)data_020f5200;
u32 old=*(volatile u32 *)0x4000000;
data_0212dbc0=a;
if(!flag)a=0;
*(volatile u32 *)0x4000000=(old&0xfff0fff0)|(a<<16)|b|(c<<3);
if(!*(u16 *)&data_0212dbc0)data_020f5200=0;
}

void GX_SetSubBgMode(s32 arg0) {
    *(s32 *)0x04001000 = (*(s32 *)0x04001000 & ~7) | arg0;
}

void GX_SetMasterBrightness(s16 *arg0, s32 arg1) {
    if (arg1 == 0) {
        *arg0 = 0;
        return;
    }
    if (arg1 > 0) {
        *arg0 = arg1 | 0x4000;
        return;
    }
    *arg0 = (0 - arg1) | 0x8000;
}

void GX_ResetBankState(void) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, s16 *, 0) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 2) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 4) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 6) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 8) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0xA) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0xC) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0xE) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0x10) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0x12) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0x14) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0x16) = 0;
    M2C_FIELD(&gVramBankState, s16 *, 0x18) = 0;
    M2C_FIELD((void *)0x04000240, s32 *, 0) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 4) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 5) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 6) = 0;
    M2C_FIELD((void *)0x04000240, s16 *, 8) = 0;
}

void GX_ReleaseBanks(s32 arg0) {
    if (arg0 & 1) {
        *(volatile u8 *)0x04000240 = 0x80;
    }
    if (arg0 & 2) {
        *(volatile u8 *)0x04000241 = 0x80;
    }
    if (arg0 & 4) {
        *(volatile u8 *)0x04000242 = 0x80;
    }
    if (arg0 & 8) {
        *(volatile u8 *)0x04000243 = 0x80;
    }
    if (arg0 & 0x10) {
        *(volatile u8 *)0x04000244 = 0x80;
    }
    if (arg0 & 0x20) {
        *(volatile u8 *)0x04000245 = 0x80;
    }
    if (arg0 & 0x40) {
        *(volatile u8 *)0x04000246 = 0x80;
    }
    if (arg0 & 0x80) {
        *(volatile u8 *)0x04000248 = 0x80;
    }
    if (arg0 & 0x100) {
        *(volatile u8 *)0x04000249 = 0x80;
    }
}

/* Assigns the requested VRAM banks to the main engine's background, each bank
 * of a run getting the next 32 KiB offset; releases the banks the background
 * no longer uses and records the new assignment. */
void GX_SetBankForBG(s32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_BG)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_BG) = banks;
    switch (banks) {
    case VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_C: REG_VRAM_C_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_B | VRAM_BANK_C: REG_VRAM_C_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_B: REG_VRAM_B_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(3);
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C: REG_VRAM_C_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_A | VRAM_BANK_B: REG_VRAM_B_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_A: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_B_CR = VRAM_CR_MAIN_BG(1); REG_VRAM_D_CR = VRAM_CR_MAIN_BG(2); break;
    case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_A | VRAM_BANK_C: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_C_CR = VRAM_CR_MAIN_BG(1); break;
    case VRAM_BANK_A | VRAM_BANK_D: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_D_CR = VRAM_CR_MAIN_BG(1); break;
    case VRAM_BANK_B | VRAM_BANK_D: REG_VRAM_B_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_D_CR = VRAM_CR_MAIN_BG(1); break;
    case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(3);
    case VRAM_BANK_E | VRAM_BANK_F: REG_VRAM_F_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_E: REG_VRAM_E_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_E | VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(2); REG_VRAM_E_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_F: REG_VRAM_F_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(0); break;
    default: break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Assign the requested banks to the main engine's OBJ (sprite) area: each bank
 * of a run gets the next 32 KiB offset, the banks the sprites no longer use are
 * released and the new assignment is recorded. */
void GX_SetBankForOBJ(s32 banks) {
extern M2C_UNK gVramBankState;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)=(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)|M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ))&~banks;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ)=banks;
switch(banks) {
case VRAM_BANK_A | VRAM_BANK_B: REG_VRAM_B_CR=VRAM_CR_MAIN_OBJ(1);
case VRAM_BANK_A: REG_VRAM_A_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_B: REG_VRAM_B_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(3);
case VRAM_BANK_E | VRAM_BANK_F: REG_VRAM_F_CR=VRAM_CR_MAIN_OBJ(2);
case VRAM_BANK_E: REG_VRAM_E_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_E | VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(2); REG_VRAM_E_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(1);
case VRAM_BANK_F: REG_VRAM_F_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(0);break;
case 0:break;
}
GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING));
}

void func_02002ab8(s32 mode) {
    extern M2C_UNK gVramBankState;
    /* Select a 3D VRAM bank mode and update the display control mirror. */
    M2C_FIELD(&gVramBankState, u16 *, 0) = (M2C_FIELD(&gVramBankState, u16 *, 0) | M2C_FIELD(&gVramBankState, u16 *, 0xe)) & ~mode;
    M2C_FIELD(&gVramBankState, u16 *, 0xe) = mode;
    switch (mode) {
    case 0x10:
        *(volatile u32 *)0x4000000 |= 0x40000000;
        *(volatile u8 *)0x4000244 = 0x84;
        break;
    case 0x40:
        *(volatile u32 *)0x4000000 |= 0x40000000;
        *(volatile u8 *)0x4000246 = 0x8c;
        break;
    case 0x60:
        *(volatile u8 *)0x4000246 = 0x8c;
    case 0x20:
        *(volatile u8 *)0x4000245 = 0x84;
        *(volatile u32 *)0x4000000 |= 0x40000000;
        break;
    case 0x0:
        *(volatile u32 *)0x4000000 &= ~0x40000000;
        break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, 0));
}

void func_02002bb8(u32 a) {
extern M2C_UNK gVramBankState;
M2C_FIELD(&gVramBankState,u16*,0)=(M2C_FIELD(&gVramBankState,u16*,0)|M2C_FIELD(&gVramBankState,u16*,16))&~a;
M2C_FIELD(&gVramBankState,u16*,16)=a;
switch(a){
case 0x20: *(volatile u32*)0x04000000|=0x80000000;*(volatile u8*)0x04000245=0x85;break;
case 0x40: *(volatile u32*)0x04000000|=0x80000000;*(volatile u8*)0x04000246=0x85;break;
case 0: *(volatile u32*)0x04000000&=~0x80000000;break;
}
GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16*,0));
}

/* Assign the requested VRAM banks to the 3D texture area: each bank of a run
   gets the next 32 KiB slot, 3D is switched on, and the banks the textures no
   longer use are released. */
void GX_SetBankForTex(s32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_TEX)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_TEX) = banks;
    if (banks == 0) {
        REG_DISP3DCNT = REG_DISP3DCNT & 0xcffe;
    } else {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 1;
        switch (banks) {
        case VRAM_BANK_A | VRAM_BANK_C:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(1); break;
        case VRAM_BANK_A | VRAM_BANK_D:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(1); break;
        case VRAM_BANK_B | VRAM_BANK_D:
            REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(1); break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(1); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(2); break;
        case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(1); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(2); break;
        case VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(0); break;
        case VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(1);
        case VRAM_BANK_C:
            REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(0); break;
        case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(2);
        case VRAM_BANK_B | VRAM_BANK_C:
            REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(1);
        case VRAM_BANK_B:
            REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(0); break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(3);
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C:
            REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(2);
        case VRAM_BANK_A | VRAM_BANK_B:
            REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(1);
        case VRAM_BANK_A:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); break;
        default: break;
        }
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

void func_02002e3c(s32 a) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState,u16 *,0)=(M2C_FIELD(&gVramBankState,u16 *,0)|M2C_FIELD(&gVramBankState,u16 *,0xa))&~a;
    M2C_FIELD(&gVramBankState,u16 *,0xa)=a;
    switch (a) {
    case 0x60:
        *(volatile u8 *)0x4000246 = 0x8b;
    case 0x20:
        *(volatile u8 *)0x4000245 = 0x83;
        break;
    case 0x40:
        *(volatile u8 *)0x4000246 = 0x83;
        break;
    case 0x70:
        *(volatile u8 *)0x4000246 = 0x9b;
    case 0x30:
        *(volatile u8 *)0x4000245 = 0x93;
    case 0x10:
        *(volatile u8 *)0x4000244 = 0x83;
        break;
    case 0:
        break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,0));
}

void func_02002f24(u32 a) {
extern M2C_UNK gVramBankState;
M2C_FIELD(&gVramBankState,u16 *,0)=(M2C_FIELD(&gVramBankState,u16 *,0)|M2C_FIELD(&gVramBankState,u16 *,12))&~a;
M2C_FIELD(&gVramBankState,u16 *,12)=a;
switch(a) {
case 3: *(volatile u8 *)0x4000240=0x93;
case 2: *(volatile u8 *)0x4000241=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
case 12: *(volatile u8 *)0x4000242=0x93;
case 8: *(volatile u8 *)0x4000243=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
case 0: *(volatile u16 *)0x4000060&=~0x4000;break;
case 1: *(volatile u8 *)0x4000240=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
case 4: *(volatile u8 *)0x4000242=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
}
GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,0));
}

