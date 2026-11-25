/* 28 functions from 0x02184960 to 0x021858A4 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_menu.h"
typedef struct { u8 bytes[240]; } UnkOv001SaveBlock;
typedef struct { u8 pad[0xe6]; u8 mode:2; u8 flags:6; u8 active; } SaveFlags84;

/* Fields of the ov001 sound block (gOv001SoundState, 0x9C bytes): the loaded
 * sound archive at its start, then the sound player and the per-frame update task. */
#define OV001_SOUND_PLAYER 0x90 /* s32 sound player handle the sound calls work on */
#define OV001_SOUND_FILE   0x94 /* void *base of the loaded sound archive file */
#define OV001_SOUND_TASK   0x98 /* s32 id of the sound update task */

/* Commits the working save slot into its physical slot: copies the slot image,
 * keeps, blanks or recomputes the optional player-code fields and the code's
 * set-bit count according to the "extra empty" flags, then refreshes the save
 * checksums. */
void CommitSaveSlot(void) {
M2C_UNK MI_CpuFill8(void *,s32,s32); M2C_UNK MI_CpuCopy8(void *,void *,s32);
s32 CountSetBits(void *);void UpdateSaveChecksums(s32);extern s32 gSaveData;
u8 *src,*dst;
src=(u8 *)gSaveData+SAVE_WORK_SLOT;
dst=(u8 *)(gSaveData+(src[SAVE_SLOT_INDEX_REL]<<8));
*(UnkOv001SaveBlock *)dst=*(UnkOv001SaveBlock *)src;
if(src[SAVE_SLOT_EMPTY_A]){
MI_CpuFill8(dst+SAVE_SLOT_PLAYER_CODES,0,4);MI_CpuFill8(dst+SAVE_SLOT_PLAYER_CODES+4,0,4);dst[SAVE_SLOT_CODE_BITS]=0;
}else{
MI_CpuCopy8(src+SAVE_SLOT_PLAYER_CODES,dst+SAVE_SLOT_PLAYER_CODES,4);MI_CpuCopy8(src+SAVE_SLOT_PLAYER_CODES+4,dst+SAVE_SLOT_PLAYER_CODES+4,4);dst[SAVE_SLOT_CODE_BITS]=CountSetBits(src+SAVE_SLOT_CODE);
}
if(src[SAVE_SLOT_EMPTY_B])MI_CpuFill8(dst+SAVE_SLOT_PLAYER_CODES+8,0,8);else MI_CpuCopy8(src+SAVE_SLOT_PLAYER_CODES+8,dst+SAVE_SLOT_PLAYER_CODES+8,8);
UpdateSaveChecksums(src[SAVE_SLOT_INDEX_REL]);
}

/* Store a received link-match setup - the map name, the shared name-length
 * class and four player names - into the working save slot and commit it. */
void StoreLinkMatchSetup(u8 *setup) {
    M2C_UNK MI_CpuFill8(void *, s32, s32);
    M2C_UNK MI_CpuCopy8(void *, void *, s32);
    void CommitSaveSlot(void);
    extern s32 gSaveData;
    volatile u8 *base = (volatile u8 *)gSaveData;
    s32 nameSize;
    s32 i;
    u8 *dst;
    u8 *src;

    MI_CpuFill8((void *)(base + SAVE_WORK_SLOT), 0, 0xef);
    MI_CpuCopy8(setup, (void *)(base + SAVE_MAP_NAME), SAVE_NAME_TEXT_MAX);
    switch (*(s32 *)(setup + MATCH_SETUP_NAME_CLASS)) {
        case 1:
            nameSize = 5;
            base[SAVE_NAME_FLAGS] = (base[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK) | 1;
            break;
        case 2:
            nameSize = 13;
            base[SAVE_NAME_FLAGS] = (base[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK) | 2;
            break;
        case 3:
            nameSize = 16;
            base[SAVE_NAME_FLAGS] = (base[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK) | 3;
            break;
        default:
            nameSize = 0;
            base[SAVE_NAME_FLAGS] = base[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK;
            break;
    }
    {
        u8 flags = base[SAVE_NAME_FLAGS];
        flags &= ~SAVE_NAME_FLAGS_MASK;
        base[SAVE_NAME_FLAGS] = flags;
    }
    src = setup + MATCH_SETUP_NAMES;
    dst = (u8 *)base + SAVE_PLAYER_NAMES;
    i = 0;
    for (; i < 4; i++) {
        MI_CpuCopy8(src, dst, nameSize);
        dst += SAVE_NAME_SIZE;
        src += SAVE_NAME_TEXT_MAX;
    }
    base[SAVE_SLOT_STATUS] = 2;
    MI_CpuFill8((void *)(base + SAVE_CODE), 0, 4);
    base[SAVE_EXTRA_EMPTY_A] = 1;
    base[SAVE_EXTRA_EMPTY_B] = 1;
    CommitSaveSlot();
}

#pragma scheduling on
void Ov001_SaveRoomSetupPacket(u8 *src){
extern s32 data_ov001_02193e04;
M2C_UNK func_02007f8c(void*,s32,s32);M2C_UNK func_02008048(void*,void*,s32);
u8 flags; u8 *p=(u8*)data_ov001_02193e04+0x400;
func_02007f8c(p,0,0xef);
func_02008048(src+0,p+209,5);
func_02008048(src+6,p+214,5);
func_02008048(src+12,p+219,5);
func_02008048(src+18,p+224,5);
func_02008048(src+24,p+96,32);
func_02008048(src+57,p+128,13);
func_02008048(src+71,p+144,13);
func_02008048(src+85,p+160,13);
func_02008048(src+99,p+176,13);
func_02008048(src+113,p+64,32);
flags=p[0xe6];
p[0xe7]=1;
p[0xe6]=(flags&~3)|2;
p[0xe6]&=~0xfc;
func_02007f8c(p+0xf0,0,4);
p[0xf5]=1;p[0xf6]=1;
func_ov001_02184960();
}
#pragma scheduling reset
s32 GetSaveData(void) {
    extern s32 gSaveData;
    return gSaveData;
}

/* Erase the save slot at `slotIndex`: clear its image, mark the slot erased and
 * refresh the save checksums. */
void Ov001_EraseSaveSlot(s32 slotIndex) {
    void UpdateSaveChecksums(s32);
    M2C_UNK MI_CpuFill8(void *,s32,s32);
    extern s32 gSaveData;
    u8 *slot=(u8 *)(gSaveData+(slotIndex<<8));
    MI_CpuFill8(slot,0,SAVE_SLOT_CLEAR_SIZE);
    slot[SAVE_SLOT_STATUS_REL]=SAVE_SLOT_STATUS_ERASED;
    UpdateSaveChecksums(slotIndex);
}

/* Reset the save data: clear the four save slot images, mark the first three
 * erased, store the local Wi-Fi profile code in the first two slots and refresh
 * every slot's checksum. */
void ResetSaveSlotsWithWfcProfile(void) {
void FillU16(s32,s32,s32);void BuildWfcProfile(void *);void *EncodeWfcProfileBlob(void *);M2C_UNK MI_CpuCopy8(void *,void *,s32);void UpdateSaveChecksums(s32);extern s32 gSaveData;
u8 profile[20];register s32 i;void *code;register u8 *q;register u32 fill=255;s32 offset;
FillU16(0,gSaveData,1024);
i=0;do{q=(u8 *)(gSaveData+((u32)i<<8));q[SAVE_SLOT_STATUS_REL]=fill;i++;}while(i<3);
BuildWfcProfile(profile);code=EncodeWfcProfileBlob(profile);
i=0;offset=0;do{MI_CpuCopy8(code,(void *)(gSaveData+offset+SAVE_SLOT_CODE),SAVE_SLOT_PROFILE_CODE_SIZE);i++;offset+=SAVE_SLOT_SIZE;}while(i<2);
for(i=0;i<4;i++)UpdateSaveChecksums(i);
}

#pragma opt_propagation off
#pragma opt_strength_reduction off
/* Recompute and upload the CRC16 of the save slots.  Slot `slotIndex` is always
 * refreshed; for the first three slots, a change between erased and written also
 * updates the bitmap of written slots kept at SAVE_SLOT_FLAGS in the first two
 * slot images and refreshes slots 0 and 1. */
void UpdateSaveChecksums(s32 slotIndex) {
 M2C_UNK MI_CpuFill8(void *, s32, s32);
 u16 Crc16Block(void *, void *, s32);
 s32 FifoUploadSelectedBlocks(s32, s32 *, s32);
 s32 Ov001_Alloc(s32, s32);
 M2C_UNK Ov001_FreeAlloc(void *);
 extern s32 gSaveData;
 s32 blocks[4], readback, one=1, status, inUse=0, i, offset, v;
 status=((u8 *)gSaveData+(slotIndex<<8))[SAVE_SLOT_STATUS_REL];
 MI_CpuFill8(blocks,0,16);
 blocks[slotIndex]=1;
 if(slotIndex<=2){
 if(((u8 *)gSaveData)[SAVE_SLOT_FLAGS] & (one<<slotIndex)) inUse=1;
 if(status==SAVE_SLOT_STATUS_ERASED && inUse){
 ((u8 *)gSaveData)[SAVE_SLOT_FLAGS]&=~(one<<slotIndex);
 ((u8 *)gSaveData)[SAVE_SLOT_SIZE+SAVE_SLOT_FLAGS]&=~(one<<slotIndex);
 blocks[1]=1; blocks[0]=1;
 }else if(status!=SAVE_SLOT_STATUS_ERASED && !inUse){
 ((u8 *)gSaveData)[SAVE_SLOT_FLAGS]|=one<<slotIndex;
 ((u8 *)gSaveData)[SAVE_SLOT_SIZE+SAVE_SLOT_FLAGS]|=one<<slotIndex;
 blocks[1]=1; blocks[0]=1;
 }}
 i=0; offset=0; do {
 if(blocks[i]){
 u16 res=Crc16Block((u8 *)gSaveData+SAVE_CRC_TABLE,(u8 *)gSaveData+offset,SAVE_SLOT_CRC_SIZE);
 *(u16 *)((u8 *)gSaveData+(i<<8)+SAVE_SLOT_CRC)=res;
 } i++; offset+=SAVE_SLOT_SIZE; }while(i<4);
 readback=Ov001_Alloc(SAVE_SLOT_SIZE,32);
 FifoUploadSelectedBlocks(gSaveData,blocks,readback);
 Ov001_FreeAlloc(&readback);
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
/* Parse a 12-character player code into its four 3-character groups (values
 * [0..3]): each group is copied into a buffer whose leading zero bytes are
 * turned into spaces so the number parser stops there, then parsed. */
void ParsePlayerCode(u8 *text,u8 *values) {
M2C_UNK MI_CpuFill8(void *,s32,s32); M2C_UNK MI_CpuCopy8(void *,void *,s32); s32 ParseInt(void *);
u8 digits[4]; s32 i,j,offset; u8 *p;
MI_CpuFill8(digits,0,4);
for(i=0,offset=0;i<4;i++,offset+=3) {
MI_CpuCopy8(text+offset,digits,3);
for(j=0,p=digits;j<3;j++) { if(*p) break; *p++=32; }
values[i]=ParseInt(digits);
}
}

s32 HexCharValue(u32 arg0) {
    if (arg0 <= 0x39U) {
        return arg0 - 0x30;
    }
    if (arg0 <= 0x46U) {
        return arg0 - 0x37;
    }
    return arg0 - 0x57;
}

/* Start the ov001 sound system: load the sound archive file, initialise the
 * archive and its channels, reset the sound player and start the per-frame sound
 * update task. */
void Ov001_InitSound(void) {
    void func_ov001_021850ac(void);
    extern s32 gOv001SoundState;
    extern M2C_UNK sOv001SoundArchivePath;
    s32 Ov001_Alloc(s32, s32);
    s32 Ov001_LoadFile(void *, void *, s32);
    void InitSoundDriver(void);
    M2C_UNK InitSoundArchive(s32, s32);
    M2C_UNK Sound_InitArchiveChannels(s32);
    M2C_UNK func_0202acb0(s32);
    s32 Ov001_AddTask(s32, void (*)(void), s32, s32);
    s32 fileSize;

    gOv001SoundState = Ov001_Alloc(0x9C, 4);
    M2C_FIELD(gOv001SoundState, s32 *, OV001_SOUND_FILE) = Ov001_LoadFile(&sOv001SoundArchivePath, &fileSize, 32);
    InitSoundDriver();
    InitSoundArchive(gOv001SoundState, M2C_FIELD(gOv001SoundState, s32 *, OV001_SOUND_FILE));
    Sound_InitArchiveChannels(0);
    func_0202acb0(gOv001SoundState + OV001_SOUND_PLAYER);
    M2C_FIELD(gOv001SoundState, s32 *, OV001_SOUND_TASK) = Ov001_AddTask(0, func_ov001_021850ac, 0, 200);
}

void func_ov001_02184ff8(void){extern s32 gOv001SoundState;M2C_UNK Ov001_PostTaskMessage(s32,s32);M2C_UNK Ov001_FreeAlloc(void *);Ov001_PostTaskMessage(0,M2C_FIELD(gOv001SoundState,s32 *,0x98));Ov001_FreeAlloc((void *)0x02193e08);}

void Ov001_PlaySound(s32 a){extern s32 gOv001SoundState;M2C_UNK Sound_PlaySequenceArchiveEntry(s32,s32,s32);Sound_PlaySequenceArchiveEntry(gOv001SoundState+0x90,0,a);}

void Ov001_SetScrollDragSoundLevel(M2C_UNK arg0) {
    M2C_UNK func_0202acdc(s32, M2C_UNK);
    extern s32 gOv001SoundState;
    func_0202acdc(gOv001SoundState + 0x90, arg0);
}

void Ov001_SetScrollDragSoundPitch(s32 a,s32 b){extern s32 gOv001SoundState;M2C_UNK func_0202ad70(s32,s32,s32);func_0202ad70(gOv001SoundState+0x90,a,b);}

void Ov001_StopSound(void) {M2C_UNK func_0202ac60(s32,s32);extern s32 gOv001SoundState;func_0202ac60(gOv001SoundState+0x90,0);}

void func_ov001_021850ac(void) {
    M2C_UNK func_0202a9f0();
    func_0202a9f0();
}

/* Builds the five-row ov001 option menu: allocates its handles, creates one
 * sprite per row from the variant's icon and attribute tables, places each row
 * off-screen at its resting y, queues the slide-in task, loads the menu layout
 * resource and plays the menu-open sound. */
void Ov001_OpenMenu(s32 variant) {
extern M2C_UNK gOv001MenuLayout;
extern u8 Ov001MenuIconTiles[];
extern u8 Ov001MenuRowAttrs[];
extern const u16 Ov001MenuRowPositions[];
s32 Ov001_Alloc(s32,s32);
s32 Ov001_CreateSprite();
void Ov001_SetSpritePalette();
void Ov001_MoveSpriteLayout();
void Ov001_SetSpriteAttrs();
void Ov001_SlideMenuStep0();
s32 Ov001_AddTask(s32,void (*)(void),s32,s32);
void Ov001_LoadMenuResource();
u8 *attrs;
s32 i;
u8 *tiles;
M2C_FIELD(&gOv001MenuLayout,s32 *,OV001_MENU_SPRITES)=Ov001_Alloc(OV001_MENU_HANDLES*4,4);
tiles=Ov001MenuIconTiles+variant*OV001_MENU_ROWS;attrs=Ov001MenuRowAttrs+variant*OV001_MENU_ROWS;
for(i=0;i<OV001_MENU_ROWS;i++){
((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[i]=Ov001_CreateSprite(1,*tiles++,1);
Ov001_SetSpritePalette(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[i],-1,0);
Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[i],-1,-42,((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
Ov001_SetSpriteAttrs(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[i],-1,0,*attrs++);
}
((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[OV001_MENU_TASK_SLOT]=Ov001_AddTask(0,Ov001_SlideMenuStep0,0,120);
Ov001_LoadMenuResource(variant);Ov001_PlaySound(13);
}

/* First step of the ov001 option menu slide-in: slides the five option rows
 * right by 8 pixels a frame until the first row rests at x 32, then passes the
 * slide task on to the next step. */
void Ov001_SlideMenuStep0(s32 task) {
extern M2C_UNK gOv001MenuLayout; extern const u16 Ov001MenuRowPositions[];
void Ov001_GetSpritePosition(); void Ov001_MoveSpriteLayout(); void Ov001_SetSlideStep(); void Ov001_SlideMenuStep1();
s32 pos[2]; s32 i;
Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[0],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<32 || pos[1]>256){
for(i=0;i<5;i++){
Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
}
return;
}
pos[1]=32;
for(i=0;i<5;i++){
Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
}
Ov001_SetSlideStep(task,(M2C_UNK)Ov001_SlideMenuStep1);
}

/* Third step of the ov001 option menu slide-in: drops rows 1..4 by 8 pixels a
 * frame until the second row rests at y 80, then passes the slide task on to
 * the next step. */
void Ov001_SlideMenuStep1(s32 task) {
extern M2C_UNK gOv001MenuLayout; extern const u16 Ov001MenuRowPositions[];
void Ov001_GetSpritePosition(); void Ov001_MoveSpriteLayout(); void Ov001_SetSlideStep(); void Ov001_SlideMenuStep2();
s32 pos[2]; s32 i;
Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[1],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<80 || pos[1]>256){for(i=1;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);}return;}
pos[1]=80;
for(i=1;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);}
Ov001_SetSlideStep(task,Ov001_SlideMenuStep2);
}

/* Fourth step of the ov001 option menu slide-in: drops rows 2..4 by 8 pixels a
 * frame until the third row rests at y 104, then passes the slide task on to
 * the next step. */
void Ov001_SlideMenuStep2(s32 task) {
extern M2C_UNK gOv001MenuLayout; extern const u16 Ov001MenuRowPositions[];
void Ov001_GetSpritePosition(); void Ov001_MoveSpriteLayout(); void Ov001_SetSlideStep(); void Ov001_SlideMenuStep3();
s32 pos[2]; s32 i;
Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[2],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<104 || pos[1]>256){for(i=2;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);}return;}
pos[1]=104;
for(i=2;i<5;i++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);}
Ov001_SetSlideStep(task,Ov001_SlideMenuStep3);
}

/* Fourth step of the ov001 option menu slide-in: slides rows 3 and 4 right by 8
 * pixels a frame until they rest at x 152, then passes the slide task on to the
 * last step. */
void Ov001_SlideMenuStep3(s32 task) {
extern M2C_UNK gOv001MenuLayout; extern const u16 Ov001MenuRowPositions[];
void Ov001_GetSpritePosition(); void Ov001_MoveSpriteLayout(); void Ov001_SetSlideStep(); void Ov001_SlideMenuStep4();
s32 pos[2]; s32 i;
Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[3],0,&pos[1],&pos[0]);
pos[1]+=8;
if(pos[1]<152 || pos[1]>256){
for(i=3;i<5;i++){
Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
}
return;
}
pos[1]=152;
for(i=3;i<5;i++){
Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
}
Ov001_SetSlideStep(task,Ov001_SlideMenuStep4);
}

#pragma scheduling off
void Ov001_SlideMenuStep4(s32 a){
void Ov001_GetSpritePosition();void Ov001_MoveSpriteLayout();void Ov001_SetSlideStep();void func_ov001_021855e4(s32);extern M2C_UNK gOv001MenuLayout;s32 pos[2];void *p;s32 handle;
Ov001_GetSpritePosition(M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,4),s32 *,16),0,&pos[1],&pos[0]);pos[1]+=8;
if(pos[1]<176 || pos[1]>256){Ov001_MoveSpriteLayout(M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,4),s32 *,16),-1,pos[1],33);return;}
p=M2C_FIELD(&gOv001MenuLayout,void **,4);pos[1]=176;handle=M2C_FIELD(p,s32 *,16);Ov001_MoveSpriteLayout(handle,~0u,176,33);Ov001_SetSlideStep(a,func_ov001_021855e4);
}
#pragma scheduling reset
void func_ov001_021855e4(s32 a) {
    s32 Ov001_PostTaskMessage(s32, s32);
    extern M2C_UNK gOv001MenuLayout;
    Ov001_PostTaskMessage(0, a);
    *(s32 *)((u8 *)*(void **)((u8 *)&gOv001MenuLayout + 4) + 0x14) = 0;
}
#pragma opt_instruction_scheduling reset
/* Start closing the ov001 option menu: flag it as closing and give the menu a
 * task that slides the rows out (Ov001_SlideMenuCloseStep0). */
void Ov001_CloseMenu(void) {
    s32 Ov001_AddTask(s32,void (*)(),s32,s32);
    void Ov001_SlideMenuCloseStep0(s32);
    extern M2C_UNK gOv001MenuLayout;
    s32 task;
    M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES),s8 *,OV001_MENU_CLOSING)=1;
    task=Ov001_AddTask(0,Ov001_SlideMenuCloseStep0,0,OV001_MENU_TASK_FRAMES);
    M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES),s32 *,OV001_MENU_TASK)=task;
}

/* Load the ov001 option menu's row sprites for one variant, reusing the sprite
 * objects the rows already have: for every second row (0, 2, 4) it loads the
 * row's icon into that row's sprite object, then sets the sprite's palette, its
 * position from the variant's row table and its attributes; it finishes by
 * loading the menu layout resource. */
void Ov001_LoadMenuRows(s32 variant) {
extern u8 Ov001MenuIconTiles[],Ov001MenuRowAttrs[];extern const u16 Ov001MenuRowPositions[];extern M2C_UNK gOv001MenuLayout;
s32 Ov001_GetSpriteObjEntry();void Ov001_LoadSpriteObjLayout();void Ov001_SetSpritePalette();void Ov001_MoveSpriteLayout();void Ov001_SetSpriteAttrs();void Ov001_LoadMenuResource();
s32 i,entry;u8 *icon,*attr;
icon=Ov001MenuIconTiles+variant*OV001_MENU_ROWS;attr=Ov001MenuRowAttrs+variant*OV001_MENU_ROWS;
i=0;do{
entry=Ov001_GetSpriteObjEntry(((s32*)M2C_FIELD(&gOv001MenuLayout,void**,4))[i],0);
Ov001_LoadSpriteObjLayout(1,*icon,entry);icon+=2;
Ov001_SetSpritePalette(((s32*)M2C_FIELD(&gOv001MenuLayout,void**,4))[i],-1,0);
Ov001_MoveSpriteLayout(((s32*)M2C_FIELD(&gOv001MenuLayout,void**,4))[i],-1,((const u16(*)[2])Ov001MenuRowPositions)[i][0],((const u16(*)[2])Ov001MenuRowPositions)[i][1]);
Ov001_SetSpriteAttrs(((s32*)M2C_FIELD(&gOv001MenuLayout,void**,4))[i],-1,0,*attr);attr+=2;
i+=2;}while(i<5);Ov001_LoadMenuResource(variant);
}

s32 func_ov001_02185714(void) {
    extern M2C_UNK gOv001MenuLayout;
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuLayout, void **, 4), s32 *, 0x14) != 0) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling off
void Ov001_SlideMenuCloseStep0(s32 a){
void Ov001_GetSpritePosition();void Ov001_MoveSpriteLayout();void Ov001_SetSlideStep();void Ov001_SlideMenuCloseStep1();extern M2C_UNK gOv001MenuLayout;s32 pos[2];void *p; s32 n;
Ov001_GetSpritePosition(M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,4),s32 *,16),0,&pos[1],&pos[0]);pos[1]-=8;
if(pos[1]>152){Ov001_MoveSpriteLayout(M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,4),s32 *,16),-1,pos[1],33);return;}
p=M2C_FIELD(&gOv001MenuLayout,void **,4);pos[1]=152; n=~(pos[1]-152);Ov001_MoveSpriteLayout(M2C_FIELD(p,s32 *,16),n,pos[1],33);Ov001_SetSlideStep(a,Ov001_SlideMenuCloseStep1);
}
#pragma pop
/* Second step of the ov001 option menu slide-out: slides rows 3 and 4 left by 8
 * pixels a frame until the row at index 3 rests at x 104, then passes the slide
 * task on to the next step. */
void Ov001_SlideMenuCloseStep1(s32 task) {
extern M2C_UNK gOv001MenuLayout; extern const u16 Ov001MenuRowPositions[];
void Ov001_GetSpritePosition(); void Ov001_MoveSpriteLayout(); void Ov001_SetSlideStep(); void Ov001_SlideMenuCloseStep2();
s32 pos[2]; s32 row;
Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[3],0,&pos[1],&pos[0]);
pos[1]-=8;
if(pos[1]>104){for(row=3;row<5;row++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[row],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[row][1]);}return;}
pos[1]=104;
for(row=3;row<5;row++){Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,4))[row],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[row][1]);}
Ov001_SetSlideStep(task,Ov001_SlideMenuCloseStep2);
}

