/* 23 functions from 0x02064684 to 0x0206536C (main), found by ds-decomp. */
#include "common.h"
extern u8 data_021001cc[], data_02100218[], data_02100264[], data_0213e61c[];
extern s32 data_0213e5d4[], data_0213e5f8[];
extern M2C_UNK data_0212dca4;
typedef struct ThreadGlobal { s32 unused; void *current; } ThreadGlobal;

s32 func_02064934(void *arg0) {
 s32 func_020649a8(void *);
 s32 temp_r0, temp_r4, var_r2;
 if (arg0 == NULL) return -1;
 if (((u32)(M2C_FIELD(arg0,s32 *,4)<<0x16)>>0x1d)==0) return 0;
 temp_r4=func_020649a8(arg0);
 temp_r0=M2C_FIELD(arg0,s32 (**)(s32),0x44)(M2C_FIELD(arg0,s32 *,0));
 var_r2=0;
 M2C_FIELD(arg0,s32 *,4)&=~0x380;
 M2C_FIELD(arg0,s32 *,0)=0;
 if (((u32)(M2C_FIELD(arg0,s32 *,8)<<0x1c)>>0x1f)!=0) return -1;
 if (temp_r4!=0 || temp_r0!=0) var_r2=1;
 return -var_r2;
}

s32 func_020649a8(void *arg0) {
    s32 func_02064034();
    s32 func_020641a8(void *, M2C_UNK);
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    if (arg0 == NULL) {
        return func_02064034();
    }
    if ((M2C_FIELD(arg0, u8 *, 0xD) != 0) || (temp_r0 = M2C_FIELD(arg0, s32 *, 4), (((u32) (temp_r0 << 0x16) >> 0x1D) == 0))) {
        return -1;
    }
    if (((u32) (temp_r0 << 0x1B) >> 0x1D) == 1) {
        return 0;
    }
    temp_r0_2 = M2C_FIELD(arg0, s32 *, 8);
    if ((u32) ((u32) (temp_r0_2 << 0x1D) >> 0x1D) >= 3U) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) ((temp_r0_2 & ~7) | 2);
    }
    if (((u32) (M2C_FIELD(arg0, s32 *, 8) << 0x1D) >> 0x1D) == 2) {
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
    }
    temp_r0_3 = M2C_FIELD(arg0, s32 *, 8);
    if (((u32) (temp_r0_3 << 0x1D) >> 0x1D) != 1) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r0_3 & ~7);
        return 0;
    }
    if (func_020641a8(arg0, 0) != 0) {
        M2C_FIELD(arg0, u8 *, 0xD) = 1U;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        return -1;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~7);
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    return 0;
}

char *func_02064a90(char *s) {
 s32 func_02068c34(char *);
 s32 i=0;
 s32 j=func_02068c34(s)-1;
 while(i<j) { char temp=s[i]; s[i]=s[j]; s[j]=temp; i++; j--; }
 return s;
}

char *func_02064ad4(s32 value,char *buffer,s32 radix) {
 s32 negative=0, i=0;
 if(value<0) {value=-value; negative=1;}
 do {
 s32 rem=value%radix;
 if(rem>9) buffer[i]=rem+0x37; else buffer[i]=rem+0x30;
 i++;
 value=value/radix;
 } while(value!=0);
 if(negative) buffer[i++]='-';
 buffer[i]=0;
 func_02064a90(buffer);
 return buffer;
}

s32 func_02064b50(void *arg0) {
    extern s32 data_0213e9f4;
    s32 var_r0;
    u32 temp_ip;

    if (((u32) (u8) ((u8) ((u32) (M2C_FIELD(arg0, s32 *, 4) << 0x16) >> 0x1D) + 0xFF) > 1U) || (M2C_FIELD(arg0, u8 *, 0xD) != 0)) {
        data_0213e9f4 = 0x28;
        return -1;
    }
    temp_ip = (u32) (M2C_FIELD(arg0, s32 *, 8) << 0x1D) >> 0x1D;
    if (temp_ip == 0) {
        return M2C_FIELD(arg0, s32 *, 0x18);
    }
    var_r0 = M2C_FIELD(arg0, s32 *, 0x34) + (M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s32 *, 0x1C));
    if (temp_ip >= 3U) {
        var_r0 -= temp_ip - 2;
    }
    return var_r0;
}

s32 func_02064bcc(void *p){
extern u8 data_021001cc[],data_02100218[],data_02100264[],data_0213e61c[];
extern s32 data_0213e5d4[],data_0213e5f8[];
extern M2C_UNK data_0212dca4;
s32 func_02006680(void *);s32 func_02064b50(void *);
u32 n; s32 result;
if(p==data_021001cc)n=2;else if(p==data_02100218)n=3;else if(p==data_02100264)n=4;else n=5;
if(!func_02006680(data_0213e61c+24*n)){
data_0213e5d4[n]=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,0x6c);data_0213e5f8[n]=1;
}else if((u32)data_0213e5d4[n]==(u32)M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,0x6c)){data_0213e5f8[n]++;}
else{func_02006564(data_0213e61c+24*n);data_0213e5d4[n]=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,0x6c);data_0213e5f8[n]=1;}
result=func_02064b50(p);
if(--data_0213e5f8[n]==0)func_020065e8(data_0213e61c+24*n);
return result;
}

/* Sets/updates the transfer position, adjusting buffered stream state, and reports progress through the object's callback. */
s32 func_02064ce8(void *stream, u32 position, s32 mode, ...) {
s32 func_020641a8(void *, s32);
s32 func_02064b50(void *);
extern s32 data_0213e9f4;
if ((u8)((M2C_FIELD(stream,u32 *,4)<<22)>>29)!=1 || M2C_FIELD(stream,u8 *,13)!=0) { data_0213e9f4=40; return -1; }
if (((u32)(M2C_FIELD(stream,s32 *,8)<<29)>>29) ==1 && func_020641a8(stream,0)!=0) { M2C_FIELD(stream,u8 *,13)=1; M2C_FIELD(stream,u32 *,40)=0; data_0213e9f4=40; return -1; }
if(mode==1){mode=0;position+=func_02064b50(stream);}
if(mode!=2 && (M2C_FIELD(stream,u32 *,4)<<27)>>29 !=3 && (((u32)(M2C_FIELD(stream,s32 *,8)<<29)>>29))-2<=1) {
u32 current=position; u32 base;
if(current>=M2C_FIELD(stream,u32 *,24)) goto clear;
base=M2C_FIELD(stream,u32 *,52); if(current<base) { clear: M2C_FIELD(stream,u32 *,8)&=~7; goto done; }
update: {
M2C_FIELD(stream,u32 *,36)=M2C_FIELD(stream,u32 *,28)+(current-base);
M2C_FIELD(stream,u32 *,40)=M2C_FIELD(stream,u32 *,24)-position;
M2C_FIELD(stream,u32 *,8)=(M2C_FIELD(stream,u32 *,8)&~7)|2;
}
}else M2C_FIELD(stream,u32 *,8)&=~7;
done:
if(((u32)(M2C_FIELD(stream,s32 *,8)<<29)>>29) ==0){
s32 (*callback)(s32,u32 *,s32,s32)=M2C_FIELD(stream,s32 (**)(s32,u32 *,s32,s32),56);
if(callback && callback(M2C_FIELD(stream,s32 *,0),&position,mode,M2C_FIELD(stream,s32 *,72))!=0){
M2C_FIELD(stream,u8 *,13)=1; M2C_FIELD(stream,u32 *,40)=0; data_0213e9f4=40;return -1;
}
M2C_FIELD(stream,u8 *,12)=0;M2C_FIELD(stream,u32 *,24)=position;M2C_FIELD(stream,u32 *,40)=0;
}
return 0;
}

s32 func_02064ed0(void *p, s32 pos, s32 mode) {
s32 func_02006680(void *); M2C_UNK func_02006564(); M2C_UNK func_020065e8();
s32 n, result, owner; void *thread;
if(p==data_021001cc)n=2;else if(p==data_02100218)n=3;else if(p==data_02100264)n=4;else n=5;
if(func_02006680(data_0213e61c+n*24)==0) {
data_0213e5d4[n]=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,108);
data_0213e5f8[n]=1;
}else if((thread=M2C_FIELD(&data_0212dca4,void **,4),owner=data_0213e5d4[n],owner==M2C_FIELD(thread,s32 *,108))) {data_0213e5f8[n]++;}
else{func_02006564(data_0213e61c+n*24);
data_0213e5d4[n]=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,108);
data_0213e5f8[n]=1;
}
result=func_02064ce8(p,pos,mode);
if(--data_0213e5f8[n]==0)func_020065e8(data_0213e61c+n*24);
return result;
}

void func_02064ffc(void *arg0) {
    M2C_UNK func_02064ed0(void *, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    func_02064ed0(arg0, 0, 0);
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
}

M2C_UNK func_02065020(M2C_UNK a,M2C_UNK b,M2C_UNK c) {
 extern u32 data_0210040c[];
 return (*(M2C_UNK (**)(M2C_UNK,M2C_UNK,M2C_UNK))data_0210040c[2])(a,b,c);
}

s32 func_0206503c(s16 *arg0, u8 *arg1, s32 arg2) {
    if (arg1 == NULL) {
        return 0;
    }
    if (arg2 == 0) {
        return -1;
    }
    if (arg0 != NULL) {
        *arg0 = (s16) *arg1;
    }
    if ((s8) *arg1 == 0) {
        return 0;
    }
    return 1;
}

s32 func_02065074(s8 *arg0, s8 arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    *arg0 = arg1;
    return 1;
}

s32 func_02065088(s8 *a,u16 b) {
extern u32 data_0210040c[];
return (*(s32 (**)(s8 *,u16))(data_0210040c[2]+4))(a,b);
}

u32 func_020650a4(s16 *out,char *in,u32 n) {
s32 func_02068c34(char *);
u32 i; s32 left;
left=func_02068c34(in); i=0;
if(out) {
for(;i<n;i++) {
if(*in) {
s32 len=func_02065020(out,in,left);
out++;
if(len>0) {in+=len;left-=len;} else return -1;
} else {*out=0;break;}
}
}
return i;
}

u32 func_0206512c(s8 *out,u16 *in,u32 n) {
void func_02068d18(void *,void *,u32);
s8 buf[4];
u32 used=0;
if(!out || !in) return 0;
do {
u32 len;
if(!*in) {out[used]=0;break;}
len=func_02065088(buf,*in++);
if(used+len>n) break;
func_02068d18(out+used,buf,len);
used+=len;
} while(used<=n);
return used;
}

s8 *func_020651a4(s8 *out,s8 *in,s32 n) {
s8 *p=out;
if(n) do {s8 c=*in++;--n;*p++=c;} while(n);
return out;
}

void *func_020651c4(char *dst,char *src,u32 n) {
 if(src>=dst) {
 char *p=dst;
 if(n) { do { *p++=*src++; } while(--n); }
 } else {
 char *s=src+n; char *p=dst+n;
 if(n) { do { *--p=*--s; } while(--n); }
 }
 return dst;
}

s32 func_02065210(s32 arg0) {
    M2C_UNK func_020652bc();
    func_020652bc();
    return arg0;
}

u8 *func_02065224(u8 *p,s32 value,u32 n) {
 u32 c=(u8)value;
 if(n) { do { if(*p++==c) return p-1; } while(--n); }
 return NULL;
}

u8 *func_02065250(u8 *p,s32 value,u32 n) {
 u32 c=(u8)value;
 p+=n;
 if(n) { do { if(*--p==c) return p; } while(--n); }
 return NULL;
}

s32 func_0206527c(u8 *a,u8 *b,u32 n) {
 if(n) { do {
 u32 x=*a++; u32 y=*b++;
 if(x!=y) return a[-1]<b[-1]?-1:1;
 } while(--n); }
 return 0;
}

M2C_UNK func_020652bc(u8 *p,s32 value,u32 n) {
u32 v=(u8)value; u32 k;
if(n>=32) {
k=(-(u32)p)&3;
if(k) {n-=k;do {*p++=(u8)v;}while(--k);}
if(v) v |= ((v<<24)|(v<<16))|(v<<8);
k=n>>5;
if(k) do {
((u32 *)p)[0]=v;((u32 *)p)[1]=v;((u32 *)p)[2]=v;((u32 *)p)[3]=v;
((u32 *)p)[4]=v;((u32 *)p)[5]=v;((u32 *)p)[6]=v;((u32 *)p)[7]=v;
p+=32;
}while(--k);
k=(n&31)>>2;
if(k) do {*(u32 *)p=v;p+=4;}while(--k);
n&=3;
}
if(n) do {*p++=(u8)v;}while(--n);
return (s32)p;
}

