/* 11 functions from 0x02066BA8 to 0x020677B8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a,b,c,d,e,f,g,h; s32 width,precision; } HexFormat;
typedef struct { char *q; u32 lo,hi; char space,pad; } FormatterScratch;
static inline void heapSwap(s8 *a,s8 *b,u32 n) { s8 t; if(n) do { t=*a; *a++=*b; *b++=t; } while(--n); }

char *func_020658fc(s32,char *,HexFormat);
char *func_02065b48(u64,char *,HexFormat);
char *func_02066444(double,char *,HexFormat);
char *func_02065e44(double,char *,HexFormat);
extern u8 data_0210054c[],data_02100550[];
#pragma opt_strength_reduction off
u32 func_02066ba8(s32 (*writer)(void *,const char *,s32), void *state, char *p, char *args) {
    char buffer[512];
    HexFormat f;
    char pad=' ', space;
    char *q;
    s32 total=0;
    s32 len;
    char *text;
    s32 width;
    s32 value;
    u64 wide;
    double real;
    while (*p) {
        char *mark=(char *)func_02068ee0(p,37);
        q=mark;
        if (!mark) {
            len=func_02068c34(p); total+=len;
            if(len && !writer(state,p,len)) return -1;
            break;
        }
        len=mark-p;total+=len;
        if(len && !writer(state,p,len)) return -1;
        p=(char *)func_0206536c(q,&args,&f);
        switch(f.f) {
        case 'd': case 'i':
            if(f.e==3) {args+=4;value=*(long *)(args-4);}
            else if(f.e==4) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==6) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==7) {args+=4;value=*(unsigned long *)(args-4);}
            else if(f.e==8) {args+=4;value=(s32)*(char **)(args-4);}
            else {args+=4;value=*(s32 *)(args-4);}
            if(f.e==2)value=(s16)value;
            if(f.e==1)value=(s8)value;
            if(f.e==4 || f.e==6){text=func_02065b48(wide,buffer+512,f);if(!text)goto invalid;}
            else {text=func_020658fc(value,buffer+512,f);if(!text)goto invalid;}
            len=buffer+511-text;break;
        case 'o': case 'u': case 'x': case 'X':
            if(f.e==3) {args+=4;value=*(long *)(args-4);}
            else if(f.e==4) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==6) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==7) {args+=4;value=*(unsigned long *)(args-4);}
            else if(f.e==8) {args+=4;value=(s32)*(char **)(args-4);}
            else {args+=4;value=*(s32 *)(args-4);}
            if(f.e==2)value=(u16)value;
            if(f.e==1)value=(u8)value;
            if(f.e==4 || f.e==6){text=func_02065b48(wide,buffer+512,f);if(!text)goto invalid;}
            else {text=func_020658fc(value,buffer+512,f);if(!text)goto invalid;}
            len=buffer+511-text;break;
        case 'e':case 'E':case 'f':case 'F':case 'g':case 'G':
            if(f.e==9){args+=8;real=*(double *)(args-8);}
            else {args+=8;real=*(long double *)(args-8);}
            text=func_02066444(real,buffer+512,f);
            if(!text)goto invalid;
            len=buffer+511-text;break;
        case 'a':case 'A':
            if(f.e==9){args+=8;real=*(double *)(args-8);}
            else {args+=8;real=*(long double *)(args-8);}
            text=func_02065e44(real,buffer+512,f);
            if(!text)goto invalid;
            len=buffer+511-text;break;
        case 's':
            if(f.e==5){
                u16 *str;
                args+=4;str=*(u16 **)(args-4);
                if(!str)str=(u16 *)data_0210054c;
                if((s32)func_0206512c(buffer,str,512)<0)goto invalid;
                text=buffer;
            } else {args+=4;text=*(char **)(args-4);}
            if(!text)text=(char *)data_02100550;
            if(f.d){
                len=(u8)*text++;
                if(f.c && len>f.precision)len=f.precision;
            }else if(f.c){
                char *end;
                len=f.precision;
                end=(char *)func_02065224(text,0,len);
                if(end)len=end-text;
            }else len=func_02068c34(text);
            break;
        case 'n':{
            void *ptr;
            args+=4;ptr=*(void **)(args-4);
            switch(f.e){
            case 0:*(s32 *)ptr=total;break;
            case 2:*(s16 *)ptr=total;break;
            case 3:*(s32 *)ptr=total;break;
            case 6:*(s64 *)ptr=total;break;
            case 7:*(s32 *)ptr=total;break;
            case 8:*(s32 *)ptr=total;break;
            case 4:*(s64 *)ptr=total;break;
            }
            continue;
        }
        case 'c':args+=4;buffer[0]=*(s32 *)(args-4);text=buffer;len=1;break;
        case '%':buffer[0]='%';text=buffer;len=1;break;
        case 255:
        default:
        invalid:
            len=func_02068c34(q);
            if(len && !writer(state,q,len))return -1;
            return total+len;
        }
        width=len;
        if(f.a){
            pad=f.a==2?'0':' ';
            if((*text=='+' || *text=='-' || *text==' ') && pad=='0'){
                if(!writer(state,text,1))return -1;
                text++;len--;
            }
            while(width<f.width){
                if(!writer(state,&pad,1))return -1;
                width++;
            }
        }
        if(len && !writer(state,text,len))return -1;
        if(f.a==0){
            while(width<f.width){
                space=' ';
                if(!writer(state,&space,1))return -1;
                width++;
            }
        }
        total+=width;
    }
    return total;
}
#pragma opt_strength_reduction reset
s32 func_020673cc(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_02064684(M2C_UNK, M2C_UNK, s32, s32);
    s32 var_r5;

    var_r5 = arg0;
    if (arg2 != func_02064684(arg1, 1, arg2, var_r5)) {
        var_r5 = 0;
    }
    return var_r5;
}

s32 func_020673f8(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020651a4(s32, M2C_UNK, s32);
    s32 temp_r3;
    s32 var_r5;
    u32 temp_r2;

    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    var_r5 = arg2;
    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if ((u32) (temp_r3 + var_r5) > temp_r2) {
        var_r5 = temp_r2 - temp_r3;
    }
    func_020651a4(M2C_FIELD(arg0, s32 *, 0) + temp_r3, arg1, var_r5);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + var_r5);
    return 1;
}

s32 func_0206743c(s32 format, ...) {
extern u8 data_02100218[],data_0213e664[],data_0213e5d4[],data_0213e5f8[],data_0212dca4[];
s32 func_0206ad4c(void *,s32);s32 func_02006680(void *);u32 func_02066ba8();
s32 result;char *args;
if(func_0206ad4c(data_02100218,-1)>=0)return -1;
if(!func_02006680(data_0213e664)){
M2C_FIELD(data_0213e5d4,s32 *,12)=M2C_FIELD(M2C_FIELD(data_0212dca4,void **,4),s32 *,0x6c);
M2C_FIELD(data_0213e5f8,s32 *,12)=1;
}else if(M2C_FIELD(data_0213e5d4,s32 *,12)==M2C_FIELD(M2C_FIELD(data_0212dca4,void **,4),s32 *,0x6c)){
M2C_FIELD(data_0213e5f8,s32 *,12)=M2C_FIELD(data_0213e5f8,s32 *,12)+1;
}else{
func_02006564(data_0213e664);
M2C_FIELD(data_0213e5d4,s32 *,12)=M2C_FIELD(M2C_FIELD(data_0212dca4,void **,4),s32 *,0x6c);
M2C_FIELD(data_0213e5f8,s32 *,12)=1;
}
args=(char *)(((u32)&format&~3U)+4);
result=func_02066ba8(func_020673cc,data_02100218,format,args);
if(--M2C_FIELD(data_0213e5f8,s32 *,12)==0)func_020065e8(data_0213e664);
return result;
}

u32 func_02067554(char *arg0, u32 arg1, s32 arg2, void *arg3) {
    u32 func_02066ba8();
    struct { char *buffer; u32 size; u32 position; } state;
    u32 result;
    state.buffer = arg0;
    state.size = arg1;
    state.position = 0;
    result = func_02066ba8(func_020673f8, &state, arg2, arg3);
    if (arg0 == 0) return result;
    if (result < arg1) {
        arg0[result] = 0;
        return result;
    }
    if (arg1 != 0) (arg0 + arg1)[-1] = 0;
    return result;
}

void func_020675bc(s32 arg0, s32 arg1, s32 arg2, ...) {
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_02067554(arg0, arg1, arg2, args);

}

void func_020675e4(s32 arg0, s32 arg1, ...) {
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02067554((char *)arg0, -1, arg1, args);
}

void func_02067610(s8 *base,u32 count,u32 size,s32 (*compare)(const void*,const void*)) {
u32 root,child,k; s8 *start,*end,*parent,*q,*p; s8 byte; u32 offset,neg;
if(count<2)return;
root=(count>>1)+1;
start=base+size*(root-1);end=base+size*(count-1);offset=root*size;neg=size*-1;
for(;;){
if(root>1){--root;offset-=size;start-=size;}
else {
heapSwap(start,end,size);
if(--count==1)return;
end-=size;
}
child=root;p=base+(offset+neg);
while(count>=child*2){
child*=2;parent=p;p=base+size*(child-1);
if(count>child && compare(p,p+size)<0){child++;p+=size;}
if(compare(parent,p)>=0)break;
heapSwap(parent,p,size);
}
}
}

s32 func_02067774(void) {
    extern s32 data_02100554;
    u32 value;
    value = (data_02100554 * 0x41C64E6D) + 0x3039;
    data_02100554 = value;
    return 0x7FFF & (value >> 16);
}

void func_020677a8(s32 arg0) {
    extern s32 data_02100554;
    data_02100554 = arg0;
}
