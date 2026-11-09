/* 3 functions from 0x02222204 to 0x022231F8 (ov011), found by ds-decomp. */
#include "common.h"
#define ROTATE_RIGHT(x,n) (((x)>>(n)) | ((x)<<(32-(n))))

#pragma push
#pragma opt_propagation off
void func_ov011_02222204(M2C_UNK arg0) {
    M2C_UNK func_01ff9e00();
    M2C_UNK func_01ffac9c(M2C_UNK, M2C_UNK, s32, M2C_UNK *, s32);
    M2C_UNK func_ov011_022216d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov011_02222010(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov011_02224e04(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_02101f2c;
    extern M2C_UNK data_02101f5c;
    extern u16 **data_027e00c4;
    extern u16 **data_027e00c8;
    extern u16 **data_027e01d8;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    s32 var_r9;
    u16 **temp_r11;
    u16 **var_r0;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;

    var_r9 = 0;
    temp_r11 = data_027e01d8;
    do {
        if (var_r9 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        data_027e01d8 = var_r0;
        temp_r0 = *var_r0;
        sp18 = temp_r0;
        *sp18 = *sp18 | 0x10;
        temp_r0_2 = *data_027e01d8;
        sp14 = temp_r0_2;
        *sp14 = *sp14 | 0x20;
        temp_r0_3 = *data_027e01d8;
        sp10 = temp_r0_3;
        *sp10 = *sp10 | 0x40;
        temp_r0_4 = *data_027e01d8;
        spC = temp_r0_4;
        *spC = *spC | 0x80;
        temp_r0_5 = *data_027e01d8;
        sp8 = temp_r0_5;
        *sp8 = *sp8 | 0x100;
        temp_r0_6 = *data_027e01d8;
        sp4 = (u16 *)((u8 *)temp_r0_6 + 0x12);
        *sp4 = (s16) (*sp4 & ~0xC0);
        M2C_FIELD(*data_027e01d8, s8 *, 0x51) = 0;
        M2C_FIELD(*data_027e01d8, s8 *, 0x52) = 0;
        M2C_FIELD(*data_027e01d8, s8 *, 0x53) = 0;
        func_01ff9e00();
        M2C_FIELD(*data_027e01d8, s16 *, 0x38) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x40) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x3A) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x42) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x3C) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x44) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x3E) = 0;
        M2C_FIELD(*data_027e01d8, s16 *, 0x46) = 0;
    } while (++var_r9 < 2);
    data_027e01d8 = temp_r11;
    func_ov011_02224e04(arg0, 2, 2, 0x80, 0x60);
    func_ov011_02224e04(arg0, 2, 3, 0x80, 0x60);
    func_ov011_022216d8(arg0, 3, 0, 3);
    func_ov011_022216d8(arg0, 4, 1, 3);
    func_ov011_022216d8(arg0, 0x13, 2, 0);
    func_ov011_02222010(arg0, 0, 0);
    func_ov011_02222010(arg0, 1, 0);
    func_ov011_02222010(arg0, 7, 1);
    func_01ffac9c(0x40, 0x50, 0, &data_02101f2c, 0);
    func_01ffac9c(0, 0xAA, 0x6040, &data_02101f5c, 0);
    func_01ffac9c(0x80, 0xAA, 0x6060, &data_02101f5c, 0);
}
#pragma pop
void func_ov011_02222830(void *arg0,u32 mode,u32 first,u32 second,u32 amount) {
extern u16 **gCur3DSpriteEngine,**data_027e00c4,**data_027e00c8;
u8 b,a;
u16 **saved,**engine;
s32 i;
u16 *volatile p0;
u16 *volatile p1;
u16 *volatile p2;
u16 *volatile p3;
u16 *volatile p4;
u16 *volatile p5;
u16 *volatile p6;
u16 *volatile p7;
u16 *volatile p8;
u16 *volatile p9;
u16 *volatile p10;
u16 *volatile p11;
u16 *volatile p12;
u16 *volatile p13;
u16 *volatile p14;
u16 *volatile p15;
u16 *volatile p16;
u16 *volatile p17;
u16 *volatile p18;
u16 *volatile p19;
u16 *volatile p20;
u16 *volatile p21;
u16 *volatile p22;
u16 *volatile p23;
u16 *volatile p24;
u16 *volatile p25;
u16 *volatile p26;
u16 *volatile p27;
u16 *volatile p28;
u16 *volatile p29;
u16 *volatile p30;
u16 *volatile p31;
u16 *volatile p32;
u16 *volatile p33;
u16 *volatile p34;
u16 *volatile p35;
u16 *volatile p36;
u16 *volatile p37;
u16 *volatile p38;
u16 *volatile p39;
u16 *volatile p40;
u16 *volatile p41;
u16 *volatile p42;
u16 *volatile p43;
u16 *volatile p44;
u16 *volatile p45;
u16 *volatile p46;
u16 *volatile p47;
u16 *volatile p48;
u16 *volatile p49;
u16 *volatile p50;
u16 *volatile p51;
u16 *volatile p52;
u16 *volatile p53;
u16 *volatile p54;
u16 *volatile p55;
u16 *volatile p56;
u16 *volatile p57;
u16 *volatile p58;
u16 *volatile p59;
u16 *volatile p60;
i=0;
if(amount>16)amount=16;
a=16-amount;b=amount;
saved=gCur3DSpriteEngine;
for(;i<2;i++){
engine=i==0?data_027e00c8:data_027e00c4;
gCur3DSpriteEngine=engine;
if(mode==0&&engine!=data_027e00c8)continue;
if(mode==1&&engine!=data_027e00c4)continue;
if(mode==3&&engine!=saved)continue;
switch(first){
case 0:
p0=(u16 *)((u8 *)*engine+0x12);
*p0=(*p0&~1)|1;
p1=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p1=*p1&~2;
p2=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p2=*p2&~4;
p3=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p3=*p3&~8;
p4=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p4=*p4&~16;
break;
case 1:
p5=(u16 *)((u8 *)*engine+0x12);
*p5=*p5&~1;
p6=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p6=*p6|2;
p7=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p7=*p7&~4;
p8=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p8=*p8&~8;
p9=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p9=*p9&~16;
break;
case 2:
p10=(u16 *)((u8 *)*engine+0x12);
*p10=*p10&~1;
p11=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p11=*p11&~2;
p12=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p12=*p12|4;
p13=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p13=*p13&~8;
p14=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p14=*p14&~16;
break;
case 3:
p15=(u16 *)((u8 *)*engine+0x12);
*p15=*p15&~1;
p16=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p16=*p16&~2;
p17=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p17=*p17&~4;
p18=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p18=*p18|8;
p19=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p19=*p19&~16;
break;
case 8:
p20=(u16 *)((u8 *)*engine+0x12);
*p20=*p20&~1;
p21=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p21=*p21&~2;
p22=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p22=*p22&~4;
p23=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p23=*p23&~8;
p24=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p24=*p24|16;
break;
default:
p25=(u16 *)((u8 *)*engine+0x12);
*p25=*p25&~1;
p26=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p26=*p26&~2;
p27=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p27=*p27&~4;
p28=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p28=*p28&~8;
p29=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p29=*p29&~16;
break;
}
switch(second){
case 0:
p30=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p30=*p30|256;
p31=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p31=*p31&~512;
p32=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p32=*p32&~1024;
p33=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p33=*p33&~2048;
p34=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p34=*p34&~4096;
break;
case 1:
p35=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p35=*p35&~256;
p36=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p36=*p36|512;
p37=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p37=*p37&~1024;
p38=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p38=*p38&~2048;
p39=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p39=*p39&~4096;
break;
case 2:
p40=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p40=*p40&~256;
p41=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p41=*p41&~512;
p42=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p42=*p42|1024;
p43=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p43=*p43&~2048;
p44=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p44=*p44&~4096;
break;
case 3:
p45=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p45=*p45&~256;
p46=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p46=*p46&~512;
p47=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p47=*p47&~1024;
p48=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p48=*p48|2048;
p49=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p49=*p49&~4096;
break;
case 8:
p50=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p50=*p50&~256;
p51=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p51=*p51&~512;
p52=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p52=*p52&~1024;
p53=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p53=*p53&~2048;
p54=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p54=*p54|4096;
break;
default:
p55=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p55=*p55&~256;
p56=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p56=*p56&~512;
p57=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p57=*p57&~1024;
p58=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p58=*p58&~2048;
p59=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p59=*p59&~4096;
break;
}
p60=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);
*p60=(*p60&~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=a;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=b;
}
gCur3DSpriteEngine=saved;
}
#pragma opt_common_subs reset

