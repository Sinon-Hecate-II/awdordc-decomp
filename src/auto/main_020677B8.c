/* 1 function from 0x020677B8 to 0x02067CB0 (main), found by ds-decomp. */
#include "common.h"
#include "scan_spec.h"
extern const ScanSpec677b8 data_020eae40;
extern const u16 data_020ead40[];
static inline s32 ScanDigit677b8(s32 c) { return (c<0 || c>=128)?0:data_020ead40[c]&8; }

/* Parse one scanf conversion specification (just past a '%') from input into
 * specOut and return the pointer just after the specification. */
char *func_020677b8(char *input,ScanSpec677b8 *specOut){
ScanSpec677b8 spec=data_020eae40;
char *cursor=input+1;
s32 ch=*cursor;
s32 hasLengthModifier;
s32 inverted,setCh,rangeEnd,remaining;
u8 *setPtr;
if(ch=='%'){spec.conversion=ch;*specOut=spec;return cursor+1;}
if(ch=='*'){spec.suppress=1;ch=*++cursor;}
if(ScanDigit677b8(ch)){
spec.width=0;
do{spec.width=spec.width*10+(ch-'0');ch=*++cursor;}while(ScanDigit677b8(ch));
if(spec.width==0){spec.conversion=255;*specOut=spec;return cursor+1;}
spec.hasWidth=1;
}
hasLengthModifier=1;
switch(ch){
case 'h':spec.length=2;if(cursor[1]=='h'){spec.length=1;ch=*++cursor;}break;
case 'l':spec.length=3;if(cursor[1]=='l'){spec.length=7;ch=*++cursor;}break;
case 'L':spec.length=9;break;
case 'j':spec.length=4;break;
case 'z':spec.length=5;break;
case 't':spec.length=6;break;
default:hasLengthModifier=0;break;
}
if(hasLengthModifier)ch=*++cursor;
spec.conversion=ch;
switch(ch){
case 'd':case 'i':case 'o':case 'u':case 'x':case 'X':
if(spec.length==9)spec.conversion=255;break;
case 'a':case 'A':case 'e':case 'E':case 'f':case 'F':case 'g':case 'G':
if(spec.length==1 || spec.length==2 || (u8)(spec.length+252)<=3)spec.conversion=255;
else if(spec.length==3)spec.length=8;
break;
case 'p':spec.length=3;spec.conversion='x';break;
case 'c':
if(spec.length==3)spec.length=10;else if(spec.length!=0)spec.conversion=255;break;
case 's':
if(spec.length==3)spec.length=10;else if(spec.length!=0)spec.conversion=255;
setPtr=spec.set;remaining=32;do{*setPtr++=255;remaining--;}while(remaining>0);
spec.set[1]=0xc1;spec.set[4]=0xfe;break;
case '[':
if(spec.length==3)spec.length=10;else if(spec.length!=0)spec.conversion=255;
setCh=*++cursor;inverted=0;
if(setCh=='^'){setCh=*++cursor;inverted=1;}
if(setCh==']'){spec.set[11]|=32;setCh=*++cursor;}
while(setCh && setCh!=']'){
spec.set[(u8)setCh>>3]|=1<<(setCh&7);
if(cursor[1]=='-' && cursor[2] && cursor[2]!=']'){
rangeEnd=cursor[2];
setCh++;
while(setCh<=rangeEnd){spec.set[(u8)setCh>>3]|=1<<(setCh&7);setCh++;}
setCh=*(cursor+=3);
}else setCh=*++cursor;
}
if(setCh==0){spec.conversion=255;break;}
if(inverted){s32 left=32;u8 *scan=spec.set;do{*scan=(u8)~*scan;scan++;left--;}while(left>0);}
break;
case 'n':break;
default:spec.conversion=255;break;
}
*specOut=spec;
return cursor+1;
}
