/* 7 functions from 0x0221D008 to 0x0221E004 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221dbb0(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *data_02101e84;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(data_02101e84,u16 *,0);
current=old;
held=M2C_FIELD(data_02101e84,u16 *,2);
if(pressed&1){func_ov007_0221d008(arg0);return;}
if(held&0x40){
switch(old){
case 103:if(held==pressed)current=64;break;
case 104:if(held==pressed)current=66;break;
}
if(current>=103U){ if(current>104U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 103:if(held==pressed)current=4;break;
case 104:if(held==pressed)current=6;break;
}
if(current>=103U && current<=104U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 104:current=103;break;
case 103:current=102;break;
}
if(current>=103U && current<=104U)goto done;
}else if(held&0x10){
switch(current){
case 104:current=105;break;
case 103:current=104;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
}

void func_ov007_0221dcc0(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221dcd4(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221ded4(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *data_02101e84;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(data_02101e84,u16 *,0);
current=old;
held=M2C_FIELD(data_02101e84,u16 *,2);
if(pressed&1){func_ov007_0221dce0(arg0);return;}
if(held&0x40){
switch(old){
case 105:if(held==pressed)current=69;break;
case 106:if(held==pressed)current=72;break;
}
if(current>=105U){ if(current>106U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 105:if(held==pressed)current=9;break;
case 106:if(held==pressed)current=12;break;
}
if(current>=105U && current<=106U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 106:current=105;break;
case 105:current=104;break;
}
if(current>=105U && current<=106U)goto done;
}else if(held&0x10){
switch(current){
case 105:current=106;break;
case 106:if(held==pressed)current=100;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
}

void func_ov007_0221dff0(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

