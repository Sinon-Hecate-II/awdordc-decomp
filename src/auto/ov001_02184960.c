/* 28 functions from 0x02184960 to 0x021858A4 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_menu.h"
typedef struct { u8 bytes[240]; } UnkOv001SaveBlock;
typedef struct { u8 pad[0xe6]; u8 mode:2; u8 flags:6; u8 active; } SaveFlags84;

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

void func_ov001_02184b50(u8 *src){
extern s32 gSaveData;
M2C_UNK MI_CpuFill8(void*,s32,s32);M2C_UNK MI_CpuCopy8(void*,void*,s32);
u8 flags; u8 *p=(u8*)gSaveData+0x400;
MI_CpuFill8(p,0,0xef);
MI_CpuCopy8(src+0,p+209,5);
MI_CpuCopy8(src+6,p+214,5);
MI_CpuCopy8(src+12,p+219,5);
MI_CpuCopy8(src+18,p+224,5);
MI_CpuCopy8(src+24,p+96,32);
MI_CpuCopy8(src+57,p+128,13);
MI_CpuCopy8(src+71,p+144,13);
MI_CpuCopy8(src+85,p+160,13);
MI_CpuCopy8(src+99,p+176,13);
MI_CpuCopy8(src+113,p+64,32);
flags=p[0xe6];
p[0xe7]=1;
p[0xe6]=(flags&~3)|2;
p[0xe6]&=~0xfc;
MI_CpuFill8(p+0xf0,0,4);
p[0xf5]=1;p[0xf6]=1;
CommitSaveSlot();
}

s32 func_ov001_02184c60(void) {
    extern s32 gSaveData;
    return gSaveData;
}

void func_ov001_02184c70(s32 a) {void UpdateSaveChecksums(s32);M2C_UNK MI_CpuFill8(void *,s32,s32);extern s32 gSaveData;u8 *p=(u8 *)(gSaveData+(a<<8));MI_CpuFill8(p,0,0xef);p[0xe7]=255;UpdateSaveChecksums(a);}

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

#pragma push
#pragma opt_propagation off
#pragma opt_strength_reduction off
void UpdateSaveChecksums(s32 a) {
 M2C_UNK MI_CpuFill8(void *, s32, s32);
 u16 func_02076838(void *, void *, s32);
 s32 func_02045ee0(s32, s32 *, s32);
 s32 Ov001_Alloc(s32, s32);
 M2C_UNK Ov001_FreeAlloc(void *);
 extern s32 gSaveData;
 s32 arr[4], ptr, one=1, value, flag=0, idx, off, v;
 value=((u8 *)gSaveData+(a<<8))[0xe7];
 MI_CpuFill8(arr,0,16);
 v=one & 1; arr[a]=v;
 if(a<=2){
 if(((u8 *)gSaveData)[0xef] & (one<<a)) flag=v;
 if(value==255 && flag){
 ((u8 *)gSaveData)[0xef]&=~(one<<a);
 ((u8 *)gSaveData)[0x1ef]&=~(one<<a);
 arr[1]=1; arr[0]=1;
 }else if(value!=255 && !flag){
 ((u8 *)gSaveData)[0xef]|=one<<a;
 ((u8 *)gSaveData)[0x1ef]|=one<<a;
 arr[1]=1; arr[0]=1;
 }}
 idx=0; off=0; do {
 if(arr[idx]){
 u16 res=func_02076838((u8 *)gSaveData+0x4f8,(u8 *)gSaveData+off,254);
 *(u16 *)((u8 *)gSaveData+(idx<<8)+254)=res;
 } idx++; off+=256; }while(idx<4);
 ptr=Ov001_Alloc(256,32);
 func_02045ee0(gSaveData,arr,ptr);
 Ov001_FreeAlloc(&ptr);
}
#pragma pop
void func_ov001_02184ec4(u8 *a,u8 *b) {
M2C_UNK MI_CpuFill8(void *,s32,s32); M2C_UNK MI_CpuCopy8(void *,void *,s32); s32 ParseInt(void *);
u8 buf[4]; s32 i,j,offset; u8 *p;
MI_CpuFill8(buf,0,4);
for(i=0,offset=0;i<4;i++,offset+=3) {
MI_CpuCopy8(a+offset,buf,3);
for(j=0,p=buf;j<3;j++) { if(*p) break; *p++=32; }
b[i]=ParseInt(buf);
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

void func_ov001_02184f68(void){void func_ov001_021850ac(void);extern s32 data_ov001_02193e08;extern M2C_UNK data_ov001_02190b68;s32 Ov001_Alloc(s32,s32);s32 Ov001_LoadFile(void *,void *,s32);void func_0202a968(void);M2C_UNK InitSoundArchive(s32,s32);M2C_UNK func_0202d294(s32);M2C_UNK func_0202acb0(s32);s32 Ov001_AddTask(s32,void (*)(void),s32,s32);s32 local;
data_ov001_02193e08=Ov001_Alloc(0x9c,4);
M2C_FIELD(data_ov001_02193e08,s32 *,0x94)=Ov001_LoadFile(&data_ov001_02190b68,&local,32);
func_0202a968();InitSoundArchive(data_ov001_02193e08,M2C_FIELD(data_ov001_02193e08,s32 *,0x94));func_0202d294(0);func_0202acb0(data_ov001_02193e08+0x90);M2C_FIELD(data_ov001_02193e08,s32 *,0x98)=Ov001_AddTask(0,func_ov001_021850ac,0,200);}

void func_ov001_02184ff8(void){extern s32 data_ov001_02193e08;M2C_UNK Ov001_PostTaskMessage(s32,s32);M2C_UNK Ov001_FreeAlloc(void *);Ov001_PostTaskMessage(0,M2C_FIELD(data_ov001_02193e08,s32 *,0x98));Ov001_FreeAlloc((void *)0x02193e08);}

void Ov001_PlaySound(s32 a){extern s32 data_ov001_02193e08;M2C_UNK func_0202d3e8(s32,s32,s32);func_0202d3e8(data_ov001_02193e08+0x90,0,a);}

void func_ov001_02185048(M2C_UNK arg0) {
    M2C_UNK func_0202acdc(s32, M2C_UNK);
    extern s32 data_ov001_02193e08;
    func_0202acdc(data_ov001_02193e08 + 0x90, arg0);
}

void func_ov001_02185068(s32 a,s32 b){extern s32 data_ov001_02193e08;M2C_UNK func_0202ad70(s32,s32,s32);func_0202ad70(data_ov001_02193e08+0x90,a,b);}

void Ov001_StopSound(void) {M2C_UNK func_0202ac60(s32,s32);extern s32 data_ov001_02193e08;func_0202ac60(data_ov001_02193e08+0x90,0);}

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
void func_ov001_0218560c(void){ s32 Ov001_AddTask(s32,void (*)(),s32,s32); void Ov001_SlideMenuCloseStep0(s32); extern M2C_UNK gOv001MenuLayout; s32 result; M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,4),s8 *,24)=1; result=Ov001_AddTask(0,Ov001_SlideMenuCloseStep0,0,120); M2C_FIELD(M2C_FIELD(&gOv001MenuLayout,void **,4),s32 *,20)=result; }

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

