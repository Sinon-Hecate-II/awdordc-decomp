/* 1 function from 0x020677B8 to 0x02067CB0 (main), found by ds-decomp. */
#include "common.h"
#include "scan_spec.h"
extern const ScanSpec677b8 data_020eae40;
extern const u16 data_020ead40[];
static inline s32 ScanDigit677b8(s32 c) { return (c<0 || c>=128)?0:data_020ead40[c]&8; }

char *func_020677b8(char *input,ScanSpec677b8 *out){
ScanSpec677b8 spec=data_020eae40;
char *p=input+1;
s32 c=*p;
s32 length;
s32 invert,ch,end,n;
u8 *set;
if(c=='%'){spec.conversion=c;*out=spec;return p+1;}
if(c=='*'){spec.suppress=1;c=*++p;}
if(ScanDigit677b8(c)){
spec.width=0;
do{spec.width=spec.width*10+(c-'0');c=*++p;}while(ScanDigit677b8(c));
if(spec.width==0){spec.conversion=255;*out=spec;return p+1;}
spec.hasWidth=1;
}
length=1;
switch(c){
case 'h':spec.length=2;if(p[1]=='h'){spec.length=1;c=*++p;}break;
case 'l':spec.length=3;if(p[1]=='l'){spec.length=7;c=*++p;}break;
case 'L':spec.length=9;break;
case 'j':spec.length=4;break;
case 'z':spec.length=5;break;
case 't':spec.length=6;break;
default:length=0;break;
}
if(length)c=*++p;
spec.conversion=c;
switch(c){
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
set=spec.set;n=32;do{*set++=255;n--;}while(n>0);
spec.set[1]=0xc1;spec.set[4]=0xfe;break;
case '[':
if(spec.length==3)spec.length=10;else if(spec.length!=0)spec.conversion=255;
ch=*++p;invert=0;
if(ch=='^'){ch=*++p;invert=1;}
if(ch==']'){spec.set[11]|=32;ch=*++p;}
while(ch && ch!=']'){
spec.set[(u8)ch>>3]|=1<<(ch&7);
if(p[1]=='-' && p[2] && p[2]!=']'){
end=p[2];
ch++;
while(ch<=end){spec.set[(u8)ch>>3]|=1<<(ch&7);ch++;}
ch=*(p+=3);
}else ch=*++p;
}
if(ch==0){spec.conversion=255;break;}
if(invert){s32 remaining=32;u8 *cursor=spec.set;do{*cursor=(u8)~*cursor;cursor++;remaining--;}while(remaining>0);}
break;
case 'n':break;
default:spec.conversion=255;break;
}
*out=spec;
return p+1;
}
