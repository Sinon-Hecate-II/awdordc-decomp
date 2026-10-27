/* 24 functions from 0x02015AA0 to 0x02016934 (main), found by ds-decomp. */
#include "common.h"
typedef struct RangePair { u32 address; u32 size; } RangePair;
typedef struct MemoryDescriptor {u32 dest;u32 source;u32 size;u32 flags;} MemoryDescriptor;
typedef struct PacketBits { u8 low:2; u8 high:6; } PacketBits;

/* Builds a MemoryDescriptor describing a resource chunk: validates that src lies in a valid memory range, then either describes it in place (case 0) or copies it into the pool (case 1); case 2 is a fixed loader region. */
void func_02015aa0(void *srcInfo, s32 *kind, MemoryDescriptor *out, u32 *pool) {
    s32 func_02007958(void);
    s32 bad, copy;
    s32 start;
    u32 size, end;
    switch (*kind) {
    case 0:
        start = M2C_FIELD(srcInfo, u32 *, 0x28);
        if ((u32)start >= 0x2000000 && (u32)start < 0x22c0000) {
            size = M2C_FIELD(srcInfo, u32 *, 0x2c);
            if (start + size <= 0x22c0000) {
                M2C_FIELD(out, u32 *, 8) = size;
                start = M2C_FIELD(srcInfo, u32 *, 0x28);
                M2C_FIELD(out, u32 *, 4) = start;
                M2C_FIELD(out, u32 *, 0) = start;
                M2C_FIELD(out, u32 *, 12) &= ~1;
                return;
            }
        }
        func_02007958();
        return;
    case 1:
        start = M2C_FIELD(srcInfo, u32 *, 0x38);
        size = M2C_FIELD(srcInfo, u32 *, 0x3c);
        bad = 0;
        copy = 0;
        end = start + size;
        if ((u32)start >= 0x2000000 && (u32)start < 0x23fe800) {
            if (end > 0x2300000) {
                if (end < 0x23fe800 && size <= 0x40000) copy = 1;
                else bad = 1;
            }
        } else if ((u32)start >= 0x37f8000 && (u32)start < 0x380f000) {
            if (end <= 0x380f000) copy = 1;
            else bad = 1;
        } else bad = 1;
        if (bad == 1) func_02007958();
        M2C_FIELD(out, u32 *, 8) = M2C_FIELD(srcInfo, u32 *, 0x3c);
        M2C_FIELD(out, u32 *, 4) = M2C_FIELD(srcInfo, u32 *, 0x38);
        if (copy == 0) M2C_FIELD(out, u32 *, 0) = M2C_FIELD(out, u32 *, 4);
        else {
            M2C_FIELD(out, u32 *, 0) = *pool;
            *pool += M2C_FIELD(out, u32 *, 8);
        }
        M2C_FIELD(out, u32 *, 12) = (M2C_FIELD(out, u32 *, 12) & ~1) | 1;
        return;
    case 2:
        start = 0x27ffe00;
        size = 0x160;
        out->size = size;
        out->source = start;
        out->dest = start;
        M2C_FIELD(out, u32 *, 12) &= ~1;
        return;
    }
}

s32 func_02015c18(void *a,void *b) {
extern void *data_02136c4c;
u32 func_020722fc(u32,u32);
s32 func_02015e44(u32,u32,u32);
void *entries;u16 *counts=a+12;u32 sum=0;u8 i;
if(!b)return 0;
for(i=0;i<3;i++){((u32 *)a)[i]=sum;sum+=M2C_FIELD(b+i*16,u32 *,0x14);}
counts[0]=0;entries=b+12;
for(i=0;i<3;i++){void *e=entries+i*16;u32 block=M2C_FIELD(data_02136c4c,u32 *,0x1318);u32 n=M2C_FIELD(e,u32 *,8);u16 end=counts[i]+(u16)func_020722fc(n+block-1,block);
if(!func_02015e44(i,M2C_FIELD(e,u32 *,4),n))return 0;
if(i<2)counts[i+1]=end;else M2C_FIELD(a,u16 *,0x12)=end;
}return 1;
}

s32 func_02015ce4(void *out,void *a,u32 index,void *b) {
 extern void *data_02136c4c;
 s8 i;u32 offset;void *entry;
 if(index>=M2C_FIELD(a,u16 *,0x12))return 0;
 i=2;
loop:
 if(index>=((u16 *)(a+0xC))[i])goto found;
 i--;
 if(i>=0)goto loop;
found:
 if(i<0)return 0;
 offset=index-((u16 *)(a+0xC))[i];
 offset=offset*M2C_FIELD(data_02136c4c,u32 *,0x1318);
 entry=b+0xC+i*16;
 M2C_FIELD(out,u32 *,4)=M2C_FIELD(entry,u32 *,8)-offset;
 if(M2C_FIELD(out,u32 *,4)>M2C_FIELD(data_02136c4c,u32 *,0x1318))M2C_FIELD(out,u32 *,4)=M2C_FIELD(data_02136c4c,u32 *,0x1318);
 M2C_FIELD(out,u32 *,8)=offset+M2C_FIELD(a+i*4,u32 *,0);
 M2C_FIELD(out,u32 *,0)=offset+M2C_FIELD(entry,u32 *,0);
 M2C_FIELD(out,u8 *,0xC)=i;return 1;
}

s32 func_02015d98(s32 a,u32 p,u32 n) {
 extern const u32 data_020ea72c[];
 switch(data_020ea72c[a]){
 case 2:if(p>=0x027FFE00 && p+n<=0x027FFF60)return 1;break;
 case 0:if(p>=0x02000000 && p+n<=0x022C0000)return 1;break;
 case 1:if(p>=0x022C0000 && p+n<=0x02300000)return 1;
 if(p>=0x02000000 && p+n<=0x02300000)return 1;break;
 default:return 0;
 }return 0;
}

s32 func_02015e44(u32 a, u32 p, u32 n) {
 extern const u32 data_020ea72c[];
 u32 end;
 switch(data_020ea72c[a]) {
 case 0:
 case 2: return func_02015d98(a,p,n);
 case 1:
 if(p>=0x02000000 && p<0x023FE800) {
 end=p+n;
 if(p<0x02300000 && end>0x02300000)return 0;
 if(end<=0x02300000)return 1;
 if(end<0x023FE800 && n<=0x40000)return 1;
 return 0;
 }
 if(p>=0x037F8000 && p<0x0380F000) {
 return p+n<=0x0380F000 ? 1:0;
 }
 break;
 default:return 0;
 }
 return 0;
}

void func_02015f10(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020067e0(M2C_UNK, s32);
    M2C_UNK func_02006804();
    M2C_UNK func_020182b0(M2C_UNK, s32, M2C_UNK);
    func_020067e0(arg2, (arg0 + 0x1F) & ~0x1F);
    func_02006804();
    func_020182b0(arg2, arg0, arg1);
}

u16 func_02015f48(u16 *p,s32 bytes) {
 u32 sum=0;s32 n=bytes>>1;u32 x;
 if(n>0)do{u16 v=*p++;n--;sum+=v;}while(n>0);
 x=(sum>>16)+(u16)sum;
 return (x+(x>>16))^0xFFFF;
}

/* Initialize an entry's 0x4C0-byte work buffer from a source descriptor: zero it, load two optional resources, and copy fixed fields. */
void func_02015f94(void *dest, void *src, s32 extra) {
    M2C_UNK func_02007df8(M2C_UNK, void *, M2C_UNK);
    M2C_UNK func_02007e20(s32, void *, u16);
    M2C_UNK func_02007e98(M2C_UNK, void *, M2C_UNK);
    s32 func_02016084(s32, void *, M2C_UNK);

    s32 hasSecond;
    s32 hasFirst;

    func_02007df8(0, dest, 0x4C0);
    M2C_FIELD(dest, s8 *, 0x4B2) = 0;
    if (func_02016084(M2C_FIELD(src, s32 *, 0xC), dest, 1) == 0) {
        hasFirst = 1;
    } else {
        hasFirst = 0;
    }
    if (func_02016084(M2C_FIELD(src, s32 *, 0x10), dest, 0) == 0) {
        hasSecond = 1;
    } else {
        hasSecond = 0;
    }
    if ((hasFirst | hasSecond) != 0) {
        M2C_FIELD(dest, s8 *, 0x4B2) = 1;
        func_02007e98(0, dest, 0x220);
    }
    M2C_FIELD(dest, s32 *, 0x4B8) = (s32) M2C_FIELD(src, s32 *, 0x14);
    if (extra != 0) {
        func_02007e20(extra, dest + 0x220, 0x16U);
    }
    M2C_FIELD(dest, u8 *, 0x236) = (u8) M2C_FIELD(src, u8 *, 0x18);
    func_02007e20(M2C_FIELD(src, s32 *, 4), dest + 0x238, (u16) (func_02016194(M2C_FIELD(src, s32 *, 4)) * 2));
    func_02007e20(M2C_FIELD(src, s32 *, 8), dest + 0x298, 0xC0U);
    M2C_FIELD(dest, s8 *, 0x358) = 1;
    M2C_FIELD(dest, s16 *, 0x35A) = 1;
    M2C_FIELD(dest, s16 *, 0x4B0) = 1;
}

s32 func_02016084(s32 arg0,void *arg1,s32 arg2) {
void func_0200b774(void *);s32 func_0200ba54(void *,s32);
void func_0200ba9c(void *);void func_0200bbe0(void *,void *,s32);
u32 file[18];s32 size=arg2?0x200:0x20;
if(arg2)arg1+=0x20;
if(!arg0)return 0;
func_0200b774(file);
if(!func_0200ba54(file,arg0))return 0;
if(size!=file[10]-file[9]) {func_0200ba9c(file);return 0;}
func_0200bbe0(file,arg1,size);func_0200ba9c(file);return 1;
}

void func_02016124(void *arg0,s32 arg1,s32 arg2,s16 arg3) {
s32 i;u8 n=1;
func_02007e20(arg1,arg0+0x35e,0x14a);
for(i=0;i<15;i++)if(arg2&(2<<i))n++;
M2C_FIELD(arg0,u8 *,0x358)=n;
M2C_FIELD(arg0,s16 *,0x35a)=arg2|1;
M2C_FIELD(arg0,s16 *,0x35c)=arg3;
M2C_FIELD(arg0,u8 *,0x4b4)++;
}

#pragma dont_inline on
s32 func_02016194(s32 a) {
 s32 n=0;u16 c;
 c=M2C_FIELD(a,u16 *,0);a+=2;
 if(c)do{c=M2C_FIELD(a,u16 *,0);a+=2;n++;}while(c);
 return n;
}
#pragma dont_inline reset

void func_020161bc(void *arg0) {
extern M2C_UNK data_021311a0;
void *p=M2C_FIELD(&data_021311a0,void **,0x18);void *next;
if(!p)M2C_FIELD(&data_021311a0,void **,0x18)=arg0;
else {while((next=M2C_FIELD(p,void **,0x4bc))!=0)p=next;M2C_FIELD(p,void **,0x4bc)=arg0;}
M2C_FIELD(arg0,void **,0x4bc)=0;
}

void func_02016200(void) {
void func_0201622c(void);
extern M2C_UNK data_021311a0;
M2C_FIELD(&data_021311a0,s32 *,0x18)=0;
M2C_FIELD(&data_021311a0,s32 *,0x1c)=0;
M2C_FIELD(&data_021311a0,u8 *,0x24)=1;
M2C_FIELD(&data_021311a0,s32 *,0x14)=0;
func_0201622c();
}

void func_0201622c(void) {
    extern M2C_UNK data_021311a0;
    M2C_FIELD(&data_021311a0, s8 *, 0x25) = 0;
    M2C_FIELD(&data_021311a0, s8 *, 0x26) = 0;
    M2C_FIELD(&data_021311a0, s8 *, 0x27) = 0;
    M2C_FIELD(&data_021311a0, s8 *, 0x28) = 0;
    M2C_FIELD(&data_021311a0, s8 *, 0x29) = 0;
}

void func_02016250(s32 a,s32 b,s32 c) {
 extern M2C_UNK data_021311a0;
 s32 func_020162dc(void);void func_0201637c(void);
 void func_020163d0(s32,s32,s32);void func_02016534(void);void func_02016564(s32,s32,s32);
 for(;;) switch(M2C_FIELD(&data_021311a0,u8 *,0x24)){
 case 0:case 1:if(func_020162dc()==0)return;break;
 case 2:func_0201637c();break;
 case 3:func_020163d0(a,b,c);return;
 case 4:func_02016534();break;
 case 5:func_02016564(a,b,c);return;
 case 6:default:break;
 }
}

s32 func_020162dc(void) {
 extern M2C_UNK data_021311a0;extern M2C_UNK data_021311e0;
 s32 func_02018390(void);s32 func_020183a4(void);
 void func_02013c44(s32,void *,s32,s32,s32,s32);
 void func_0201622c(void);
 void *p;
 if(M2C_FIELD(&data_021311a0,void **,0x18)==0){
 s32 x=func_02018390();
 func_02013c44(0,&data_021311e0,0x70,x,func_020183a4(),8);return 0;
 }
 p=M2C_FIELD(&data_021311a0,void **,0x1C);
 if(p!=0 && M2C_FIELD(p,void **,0x4BC)!=0)p=M2C_FIELD(p,void **,0x4BC);
 else p=M2C_FIELD(&data_021311a0,void * volatile *,0x18);
 M2C_FIELD(&data_021311a0,void **,0x1C)=p;
 func_0201622c();
 M2C_FIELD(&data_021311a0,u8 *,0x26)=M2C_FIELD(M2C_FIELD(&data_021311a0,void **,0x1C),u8 *,0x4B4);
 M2C_FIELD(&data_021311a0,u8 *,0x24)=2;
 return 1;
}

void func_0201637c(void) {
 extern M2C_UNK data_021311a0;
 void *p;
 if(M2C_FIELD(&data_021311a0,u8 *,0x24)!=2)return;
 p=M2C_FIELD(&data_021311a0,void **,0x1C);
 if(M2C_FIELD(p,u8 *,0x4B2)==0){
 M2C_FIELD(&data_021311a0,u8 *,0x28)=9;
 M2C_FIELD(&data_021311a0,void **,0x20)=p;
 }else{
 M2C_FIELD(&data_021311a0,u8 *,0x28)=4;
 M2C_FIELD(&data_021311a0,void **,0x20)=p+0x220;
 }
 M2C_FIELD(&data_021311a0,u8 *,0x24)=3;
}

void func_020163d0(s32 a,s32 b,s32 c) {
extern M2C_UNK data_021311a0;
extern M2C_UNK data_021311ee;
extern M2C_UNK data_021311e8;
extern M2C_UNK data_021311e0;
s32 func_02007df8(s32,void *,s32);
s32 func_02007e20();
u16 func_02015f48(u16 *,s32);
void func_02013c44(s32,void *,s32,s32,s32,s32);
void *p=M2C_FIELD(&data_021311a0,void **,0x1c);
u32 end=(u32)p+0x358;
u32 src=M2C_FIELD(&data_021311a0,u32 *,0x20);
u32 n;
if(src+0x62<=end)M2C_FIELD(&data_021311a0,u8 *,0x4c)=0x62;
else {n=end-src;M2C_FIELD(&data_021311a0,u8 *,0x4c)=n;func_02007df8(0,(u8 *)&data_021311ee+(u8)n,0x62-(u8)n);}
func_02007e20(M2C_FIELD(&data_021311a0,s32 *,0x20),&data_021311ee,M2C_FIELD(&data_021311a0,u8 *,0x4c));
M2C_FIELD(&data_021311a0,u8 *,0x4a)=M2C_FIELD(&data_021311a0,u8 *,0x27);
M2C_FIELD(&data_021311a0,u8 *,0x4b)=M2C_FIELD(&data_021311a0,u8 *,0x28);
p=M2C_FIELD(&data_021311a0,void **,0x1c);
((PacketBits *)((u8 *)&data_021311a0+0x44))->low=M2C_FIELD(p,u8 *,0x4b2);
M2C_FIELD(&data_021311a0,u8 *,0x45)=M2C_FIELD(p,u8 *,0x4b3);
M2C_FIELD(&data_021311a0,u8 *,0x46)=M2C_FIELD(&data_021311a0,u8 *,0x26);
M2C_FIELD(&data_021311a0,u32 *,0x40)=M2C_FIELD(p,u32 *,0x4b8);
((PacketBits *)((u8 *)&data_021311a0+0x44))->high=M2C_FIELD(p,u8 *,0x4b5);
M2C_FIELD(&data_021311a0,u8 *,0x47)=M2C_FIELD(&data_021311a0,u8 *,0x29)++;
M2C_FIELD(&data_021311a0,u16 *,0x48)=0;
M2C_FIELD(&data_021311a0,u16 *,0x48)=func_02015f48((u16 *)&data_021311e8,0x68);
if(++M2C_FIELD(&data_021311a0,u8 *,0x27)>=M2C_FIELD(&data_021311a0,u8 *,0x28))M2C_FIELD(&data_021311a0,u8 *,0x24)=4;
else M2C_FIELD(&data_021311a0,u32 *,0x20)+=0x62;
func_02013c44(0,&data_021311e0,0x70,a,b,(u8)(c|3));
}

void func_02016534(void) {
extern M2C_UNK data_021311a0;
M2C_FIELD(M2C_FIELD(&data_021311a0,void **,0x1c),u16 *,0x4b0)=1;
M2C_FIELD(&data_021311a0,u8 *,0x26)=M2C_FIELD(M2C_FIELD(&data_021311a0,void **,0x1c),u8 *,0x4b4);
M2C_FIELD(&data_021311a0,u8 *,0x24)=5;
}

s32 func_020167d0(void *arg0) {
s32 func_02011d58();s32 bits;u16 n,start,candidate;
bits=func_02011d58();if(!bits)return 0;
start=M2C_FIELD(arg0,u16 *,4);n=0;candidate=start;
do {
if((bits&(1<<(candidate-1))) && start!=candidate) {
M2C_FIELD(arg0,u16 *,4)=candidate;break;
}
n++;candidate=candidate==16?1:candidate+1;
}while(n<16);
return 1;
}

s32 func_02016840(void) {
    extern M2C_UNK data_02136c40;
    s32 var_r0;
    s32 var_r2;
    s32 var_r3;

    var_r0 = 0;
    var_r3 = 0;
    var_r2 = 0;
    if ((M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), u16 *, 0x528) == 1) && (M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), u8 *, 0x50C) == 0)) {
        var_r3 = 1;
    }
    if ((var_r3 != 0) && (M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), u16 *, 0x526) == 0)) {
        var_r2 = 1;
    }
    if ((var_r2 != 0) && (M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), u16 *, 0x52A) != 0)) {
        var_r0 = 1;
    }
    return var_r0;
}

void func_020168a0(void) {
    s32 func_020119dc(M2C_UNK *);
    s32 func_02013d4c(M2C_UNK *, u16, u16, u16, s32);
    M2C_UNK func_02018438(M2C_UNK, s32);
    extern M2C_UNK data_020f5550;
    extern M2C_UNK func_02016934;
    func_02018438(0x80, func_020119dc(&func_02016934));
    func_02018438(0x1D, func_02013d4c(&func_02016934, M2C_FIELD(&data_020f5550, u16 *, 6), M2C_FIELD(&data_020f5550, u16 *, 2), M2C_FIELD(&data_020f5550, u16 *, 0), (s32) M2C_FIELD(&data_020f5550, u16 *, 4)));
}

void func_020168f0(s32 arg0) {
extern M2C_UNK data_02136c40;
void (*callback)(s32,s32);
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u8 *,0x50d)=0;
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,12),u16 *,0x1316)=0;
callback=M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),void (**)(s32,s32),0x51c);
if(callback)callback(17,arg0);
}

