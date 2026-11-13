/* 24 functions from 0x020756A4 to 0x02076698 (main), found by ds-decomp. */
#include "common.h"
static inline void SetState756(void *a,s32 index,s32 value) { u8 *p=(u8 *)a+0xc0c; s32 shift=(index&3)*2; p[index>>2]=(u8)(p[index>>2]&(-1^(3<<shift)))|(value<<shift); }

typedef struct { u8 pad[0x2050]; u8 active, unk2051, state, unk2053; u8 queue[0x500]; u32 count; } Queue02075;

#pragma push
#pragma opt_common_subs off
void func_020756a4(void *a) {
void *HeapAllocBlock(s32);void HeapFreeBlock(void *);s32 func_02074920(void *);void MI_CpuCopy32(void *,void *,s32);s32 func_020746fc(void *,void *);s32 func_0200558c(void);void MI_CpuCopy8(void *,void *);
s32 i,state;u8 *p; s32 shift;u8 byte;u32 mask;u8 *out;u16 id;u8 ok;u32 seq;
if(!M2C_FIELD(a,u8 *,0x2050)||M2C_FIELD(a,u8 *,0x2052)==1)return;
for(i=0;i<256;i++){
p=(u8 *)a+(i>>2);shift=(i&3)*2;byte=M2C_FIELD(p,u8 *,0xc0c);state=(byte>>shift)&3;
switch(state){case 2:mask=-1^(3<<shift);byte&=mask;state=(u8)byte;M2C_FIELD(p,u8 *,0xc0c)=(1<<shift)|state;break;case 1:M2C_FIELD(p,u8 *,0xc0c)=byte&(-1^(3<<shift));break;}
}
out=HeapAllocBlock(256);i=M2C_FIELD(a,s32 *,0xc00);
if(i!=-1){p=(u8 *)a+0xc0c;shift=(i&3)*2;p[i>>2]=(u8)(p[i>>2]&(-1^(3<<shift)))|(1<<shift);}
seq=++M2C_FIELD(a,u32 *,0xc08);if(seq==0)++M2C_FIELD(a,u32 *,0xc08);
M2C_FIELD(a,s32 *,0xc00)=func_02074920(a);M2C_FIELD(a,s32 *,0xc04)=0;
i=M2C_FIELD(a,s32 *,0xc00);p=(u8 *)a+0xc0c;shift=(i&3)*2;p[i>>2]=(u8)(p[i>>2]&(-1^(3<<shift)))|(3<<shift);
M2C_FIELD(out,u32 *,0)=0x32777364;
if(M2C_FIELD(a,s32 *,0xc04)==0)M2C_FIELD(out,u32 *,8)=M2C_FIELD((u8 *)a+M2C_FIELD(a,s32 *,0xc00)*12,u32 *,0)+1;
M2C_FIELD(out,u16 *,12)=0x54;MI_CpuCopy32((u8 *)a+0xc0c,out+20,64);
out[14]=1;out[15]=1;seq=M2C_FIELD(a,u32 *,0xc08);M2C_FIELD(out,u16 *,16)=seq;M2C_FIELD(out,u16 *,18)=seq>>16;
M2C_FIELD(out,s32 *,4)=func_020746fc(a,out);
id=func_0200558c();func_0200fe5c(id);
func_0201033c(out,(M2C_FIELD(a,s32 *,0xc00)<<10)+(M2C_FIELD(a,s32 *,0xc04)<<8),M2C_FIELD(out,u16 *,12),0,0,1,7,10,2);
ok=func_02010584()!=0;func_0200fe6c(id);func_020055f4(id);
if(!ok){M2C_FIELD(a,u8 *,0x2052)=1;HeapFreeBlock(out);return;}
if(M2C_FIELD(a,s32 *,0xc04)==0)MI_CpuCopy8(out+8,(u8 *)a+M2C_FIELD(a,s32 *,0xc00)*12);
HeapFreeBlock(out);M2C_FIELD(a,u8 *,0x2051)=0;
}
#pragma pop
void func_02075938(void *arg0,s32 arg1) {
M2C_UNK func_02074aec(void *);
s32 var_r4,var_r5; u32 temp_r8; void *temp_r7; u8 *byte;
var_r5=arg1;
if(M2C_FIELD(arg0,volatile u8 *,0x2050)==0 || M2C_FIELD(arg0,volatile u8 *,0x2052)==1)return;
if((((s32)M2C_FIELD(arg0+(var_r5>>2),u8 *,0xc0c)>>((u32)(var_r5<<30)>>29))&3)!=3)return;
var_r4=var_r5*12+(s32)arg0;
if(M2C_FIELD(var_r4,u8 *,6)==1)return;
func_02074aec(arg0+0xc4c);
loop:
temp_r8=(u32)(var_r5<<30)>>29;
temp_r7=arg0+(var_r5>>2);
byte=(u8 *)temp_r7+0xc0c;
*byte &= -1 ^ (3<<temp_r8);
*byte |= 2<<temp_r8;
var_r5=M2C_FIELD(var_r4,u16 *,10);
if(var_r5!=0xffff){var_r4=var_r5*12+(s32)arg0;goto loop;}
}

#pragma opt_common_subs off
/* Reads the save-block chain whose head is table entry `head` into `dest`: each
   12-byte table entry names one 1KB archive block, whose payload (everything
   past the 0x14- or 0x38-byte block header) is copied out before following the
   entry's next index.  Returns the bytes copied, or 0 when a read failed. */
s32 ReadSaveBlockChain(M2C_UNK *manager,s32 head,s32 dest) {
s32 func_0200558c(void);
void *entry; s32 start=dest; u8 ok=1; u16 handle;
if(M2C_FIELD(manager,u8*,0x2050)==0)return 0;
if(M2C_FIELD(manager,u8*,0x2052)==1)return 0;
handle=func_0200558c();
while(head!=0xffff){
entry=(void*)manager+head*12;
func_0200fe5c(handle);
if(M2C_FIELD(entry,u16*,8)==0xffff)
func_0201033c((head<<10)+0x38,dest,M2C_FIELD(entry,u16*,4)-0x38,0,0,1,6,1,0);
else
func_0201033c((head<<10)+0x14,dest,M2C_FIELD(entry,u16*,4)-0x14,0,0,1,6,1,0);
ok=func_02010584()!=0;
func_0200fe6c(handle);
if(!ok){M2C_FIELD(manager,u8*,0x2052)=1;break;}
head=M2C_FIELD(entry,u16*,10);
if(M2C_FIELD(entry,u16*,8)==0xffff)dest+=M2C_FIELD(entry,u16*,4)-0x38;
else dest+=M2C_FIELD(entry,u16*,4)-0x14;
}
func_020055f4(handle);
return ok?dest-start:0;
}
#pragma opt_common_subs reset
s32 func_02075b58(M2C_UNK *arg0, s32 arg1) {
    void *temp_ip;
    s32 var_lr;
    var_lr = 0;
    if (M2C_FIELD(arg0,u8 *,0x2050)==0) return 0;
    if (M2C_FIELD(arg0,u8 *,0x2052)==1) return 0;
    while (arg1 != 0xFFFF) {
        temp_ip = (void *)arg0 + arg1 * 12;
        if (M2C_FIELD(temp_ip,u16 *,8) == 0xFFFF) {
            arg1 = M2C_FIELD(temp_ip,u16 *,4) - 0x38;
        } else {
            arg1 = M2C_FIELD(temp_ip,u16 *,4) - 0x14;
        }
        var_lr += arg1;
        arg1 = M2C_FIELD(temp_ip,u16 *,10);
    }
    return var_lr;
}

void func_02075bc8(M2C_UNK *p) {
u8 *q;u32 i;
if(((Queue02075*)p)->active!=0 && ((Queue02075*)p)->state!=1){
if(!func_02074d44(p)){((Queue02075*)p)->state=1;return;}
func_02074a48((void*)p+0xc4c);
q=(void*)p+0x2054;i=0;
if(((Queue02075*)p)->count>i){
if(i<((Queue02075*)p)->count){
do {
switch(q[15]){
case 1:func_020753f8(p,*(s32*)q,*(s32*)(q+4),*(s32*)(q+8),q[14],*(s32*)(q+16));break;
case 2:func_02075938(p,*(u16*)(q+12));break;
}
i++;q+=20;
}while(i<((Queue02075*)p)->count);
}
}
func_020756a4(p);
((Queue02075*)p)->count=0;
func_02074b84((void*)p+0xc4c);
}
}

M2C_UNK func_02075cbc(M2C_UNK *p,M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 type){
M2C_UNK *GetSaveRecordList(void);s32 GetSaveRecordCount(void);
u8 *q=(u8 *)p+0x2054; u32 seq=0,i,n; s32 found=0;u8 *best,*entry;s32 j,cmp;u32 x,y;
if(!((Queue02075 *)p)->active||((Queue02075 *)p)->state==1)return;
if(type){
n=((Queue02075 *)p)->count;
for(i=0;i<n;i++,q+=20){
if(q[15]==1 && q[14]==type){seq=M2C_FIELD(q,u32 *,16)+1;if(!seq)seq++;found=1;}
}
if(!found){
entry=(u8 *)GetSaveRecordList();best=0;n=GetSaveRecordCount();
for(j=0;j<(s32)n;j++,entry+=40){
if(type==entry[2]){
if(best){
x=M2C_FIELD(best,u32 *,4);y=M2C_FIELD(entry,u32 *,4);
if((y&0xffff0000)==0xffff0000 && !(x&0xffff0000) && x!=0)cmp=0;
else if(!(y&0xffff0000) && (x&0xffff0000)==0xffff0000 && y!=0)cmp=1;
else cmp=y>x;
if(!cmp)continue;
}
best=entry;
}
}
if(best){seq=M2C_FIELD(best,u32 *,4)+1;if(!seq)seq++;}
}
}
q=(u8 *)p+0x2054+((Queue02075 *)p)->count*20;
q[15]=1;M2C_FIELD(q,s32 *,0)=a;M2C_FIELD(q,s32 *,4)=b;M2C_FIELD(q,s32 *,8)=c;q[14]=type;M2C_FIELD(q,u32 *,16)=seq;
((Queue02075 *)p)->count++;
}

void func_02075e84(M2C_UNK *arg0, s32 arg1) {
 s32 temp_ip;
 if ((M2C_FIELD(arg0,u8 *,0x2050)!=0)&&(M2C_FIELD(arg0,u8 *,0x2052)!=1)) {
 temp_ip=M2C_FIELD(arg0,s32 *,0x2554)*0x14+(s32)((void *)arg0+0x2054);
 M2C_FIELD(temp_ip,u8 *,0xF)=2;
 M2C_FIELD(temp_ip,s16 *,0xC)=arg1;
 M2C_FIELD(arg0,s32 *,0x2554)=M2C_FIELD(arg0,s32 *,0x2554)+1;
 }
}

void func_02075ecc(void) {
 M2C_UNK func_02074c58(void *);
 M2C_UNK func_02074dec(void *);
 extern M2C_UNK data_0213ea18;
 func_02074c58(&data_0213ea18);
 func_02074dec(&data_0213ea18);
}

void func_02075ee8(void) {

    extern M2C_UNK data_0213ea18;
    func_02075bc8(&data_0213ea18);
}

void func_02075efc(void) {
s32 func_0200558c(void); s32 func_02010424(void); s32 func_0201044c(s32);
s32 sp14;u16 a,b;u8 c;
if(func_0200fe08()){
a=func_0200558c();func_0200fe5c(a);
c=func_0201044c(0x1202);func_0200fe6c(a);func_020055f4(a);
if(c && (u8)func_02010424()==2){
b=func_0200558c();func_0200fe5c(b);
func_0201033c(0,&sp14,4,0,0,0,6,1,0);
func_0200fe6c(b);func_020055f4(b);
}}
func_0209e044(func_02075ecc,1,0x400,0x11,0);
}

void func_02075fd8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_02075cbc(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_0213ea18;
    func_02075cbc(&data_0213ea18, arg0, arg1, arg2, arg3);
}

/* Deletes the oldest save-directory records of `type` so that at most `maxKeep`
   of them remain: the records of that type are collected, and whenever one more
   arrives than fits, the oldest (by timestamp, with the wraparound rule the save
   manager uses elsewhere) is deleted and dropped from the array. */
void PruneSaveRecords(s32 type,s32 maxKeep){
void DeleteSaveRecord(M2C_UNK);
M2C_UNK *GetSaveRecordList(void);s32 GetSaveRecordCount(void);
void *HeapAllocBlock(s32);void HeapFreeBlock(void *);
s32 kept;u8 **keptRecords;s32 oldest,n,i,scanCount,j,bestIsNewer;u8 *p;u32 newTime,bestTime;
p=(u8 *)GetSaveRecordList();n=GetSaveRecordCount();
kept=0;keptRecords=HeapAllocBlock((maxKeep+1)*4);
for(i=0;i<n;i++,p+=SAVE_RECORD_STRIDE){
if(type==p[SAVE_RECORD_TYPE]){
if(kept<maxKeep){keptRecords[kept]=p;kept=kept+1;continue;}
keptRecords[kept]=p;
oldest=0;
scanCount=kept+1;
for(j=1;j<scanCount;j++){
newTime=M2C_FIELD(keptRecords[j],u32 *,SAVE_RECORD_TIME);bestTime=M2C_FIELD(keptRecords[oldest],u32 *,SAVE_RECORD_TIME);
if((bestTime&0xffff0000)==0xffff0000 && !(newTime&0xffff0000) && newTime!=0)bestIsNewer=0;
else if(!(bestTime&0xffff0000) && (newTime&0xffff0000)==0xffff0000 && bestTime!=0)bestIsNewer=1;
else bestIsNewer=bestTime>newTime;
if(bestIsNewer)oldest=j;
}
DeleteSaveRecord(M2C_FIELD(keptRecords[oldest],u16 *,SAVE_RECORD_ID));
for(;oldest<kept;oldest++)keptRecords[oldest]=keptRecords[oldest+1];
}
}
if(keptRecords)HeapFreeBlock(keptRecords);
}

void DeleteSaveRecord(M2C_UNK arg0) {
    extern M2C_UNK data_0213ea18;
    func_02075e84(&data_0213ea18, arg0);
}

void func_02076198(void){func_0209e044(func_02075ee8,1,0x400,0x11,0);}

void LoadSaveRecord(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK ReadSaveBlockChain(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213ea18;
    ReadSaveBlockChain(&data_0213ea18, arg0, arg1);
}

void GetSaveRecordSize(M2C_UNK arg0) {
    extern M2C_UNK data_0213ea18;
    func_02075b58(&data_0213ea18, arg0);
}

void func_020761f8(void) {
    func_0209e0dc(1);
}

u8 func_02076208(void) {
    extern M2C_UNK data_02140a18;
    return M2C_FIELD(&data_02140a18, u8 *, 0x52);
}

u8 func_02076218(void){extern M2C_UNK data_02140a18;return M2C_FIELD(&data_02140a18,u8*,0x53);}

M2C_UNK *GetSaveRecordList(void) {
    extern M2C_UNK data_0213f664;
    return &data_0213f664;
}

s32 GetSaveRecordCount(void){extern M2C_UNK data_02140a18;return M2C_FIELD(&data_02140a18,s32*,0x4c);}

void func_02076244(M2C_UNK arg0) {
    M2C_UNK func_01ff9b38();
    M2C_UNK Update3DSpriteVram();
    M2C_UNK GX_TurnOnDisplay();
    M2C_UNK func_02008ef0(M2C_UNK);
    M2C_UNK func_020092d0(M2C_UNK);
    M2C_UNK func_02081f08();
    M2C_UNK func_0208232c();
    M2C_UNK func_02082cb4();
    M2C_UNK func_02090248(M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_0209c454(M2C_UNK, M2C_UNK);
    s32 func_0209c550(M2C_UNK);
    extern void *g3DSpriteBankMain;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *data_027e01d8;
    u16 *sp3C;
    u16 *sp38;
    u16 *sp34;
    u16 *sp30;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    s32 temp_r1_2;
    s32 temp_r4;
    s32 var_r6;
    u16 *temp_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_14;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    u32 temp_r0_15;
    u32 temp_r1;
    void *temp_r5;
    void *var_r0;

    func_02090248(0);
    func_02008ef0(0);
    func_020092d0(0);
    func_02081f08();
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~1);
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~2);
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (u16) (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~4);
    func_01ff9b38();
    func_02082cb4();
    *(u16 *)0x04000304 &= ~0x8000;
    GX_TurnOnDisplay();
    var_r6 = 0;
    *(s32 *)0x04001000 |= 0x10000;
    temp_r5 = data_027e01d8;
    do {
        if (var_r6 == 0) {
            var_r0 = g3DSpriteEngineMain;
        } else {
            var_r0 = g3DSpriteEngineSub;
        }
        data_027e01d8 = var_r0;
        func_0208232c();
        temp_r0 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp3C = temp_r0;
        *temp_r0 = *sp3C & ~0x10;
        temp_r0_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp38 = temp_r0_2;
        *temp_r0_2 = *sp38 & ~0x20;
        temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp34 = temp_r0_3;
        *temp_r0_3 = *sp34 & ~0x40;
        temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp30 = temp_r0_4;
        *temp_r0_4 = *sp30 & ~0x80;
        temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp2C = temp_r0_5;
        *temp_r0_5 = *sp2C & ~0x100;
        temp_r0_6 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp28 = temp_r0_6;
        *temp_r0_6 = *sp28 & ~0x200;
        temp_r0_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp24 = temp_r0_7;
        *temp_r0_7 = *sp24 & ~0x400;
        temp_r0_8 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp20 = temp_r0_8;
        *temp_r0_8 = *sp20 & ~0x800;
        temp_r0_9 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp1C = temp_r0_9 + 0x12;
        M2C_FIELD(temp_r0_9, s16 *, 0x12) = (s16) (*sp1C & ~0xC0);
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x51) = 0;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = 0;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x53) = 0;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x50) = 0;
        M2C_FIELD(data_027e01d8, s16 *, 0x44) = 0;
        var_r6 += 1;
        M2C_FIELD(data_027e01d8, s8 *, 0x47) = 0;
        temp_r0_10 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp18 = temp_r0_10;
        *temp_r0_10 = *sp18 & ~0x10;
        temp_r0_11 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp14 = temp_r0_11;
        *temp_r0_11 = *sp14 | 0x20;
        temp_r0_12 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp10 = temp_r0_12;
        *temp_r0_12 = *sp10 & ~0x40;
        temp_r0_13 = M2C_FIELD(data_027e01d8, u16 **, 0);
        spC = temp_r0_13;
        *temp_r0_13 = *spC & ~0x80;
        temp_r0_14 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp8 = temp_r0_14;
        *temp_r0_14 = *sp8 & ~0x100;
    } while (var_r6 < 2);
    data_027e01d8 = g3DSpriteEngineMain;
    temp_r4 = func_0209c454(arg0, 1);
    temp_r1 = 0xC0 - func_0209c550(arg0);
    temp_r0_15 = 0x100 - temp_r4;
    temp_r1_2 = (s32) (temp_r1 + (temp_r1 >> 0x1F)) >> 1;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3A) = (s16) (0 - ((s32) (temp_r0_15 + (temp_r0_15 >> 0x1F)) >> 1));
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x42) = (s16) (0 - temp_r1_2);
    func_02091d4c(0);
    DrawTextLine(0, 0, 1, arg0, 0, 1);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    data_027e01d8 = temp_r5;
    M2C_FIELD(g3DSpriteEngineMain, u8 *, 0x46) = (u8) (M2C_FIELD(g3DSpriteEngineMain, u8 *, 0x46) | 1);
    M2C_FIELD(g3DSpriteEngineSub, u8 *, 0x46) = (u8) (M2C_FIELD(g3DSpriteEngineSub, u8 *, 0x46) | 1);
    func_01ff9b38();
    Update3DSpriteVram();
loop_6:
    if ((s32) *(u16 *)0x04000006 < 0xC0) {
        goto loop_6;
    }
    do {

    } while ((s32) *(u16 *)0x04000006 >= 0xC0);
    goto loop_6;
}

u8 CountBits(u32 arg0) {
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r1;

    temp_r0_2 = arg0 - (0x55555555 & (arg0 >> 1));
    temp_r1 = (temp_r0_2 & 0x33333333) + (0x33333333 & (temp_r0_2 >> 2));
    temp_r0_3 = (temp_r1 + (temp_r1 >> 4)) & 0x0F0F0F0F;
    temp_r0 = temp_r0_3 + (temp_r0_3 >> 8);
    return (u8) (temp_r0 + (temp_r0 >> 0x10));
}

void func_02076658(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2){
M2C_UNK sp0[26];
Sha1Init(sp0);Sha1Update(sp0,arg1,arg2);SHA1_Finalize(sp0,arg0);
}

