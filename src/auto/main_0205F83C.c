/* 24 functions from 0x0205F83C to 0x0206080C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 v[4]; } PacketBytes4;
typedef struct { u8 header[3]; PacketBytes4 id; u8 rest[249]; } Packet256;
typedef struct { u8 v[13]; } PacketBytes13;
typedef struct { u8 v[8]; } PacketBytes8;
extern PacketBytes13 data_02100014;
extern PacketBytes8 data_02100024;

void func_0205f83c(void *a, void *b, s32 c, void *d) {
}

void func_0205fb50(void *arg0){
 s32 func_02049208(void);
 M2C_UNK func_02049824(s32,void *,s32,s32,void *,s32);
 M2C_UNK func_0205ef8c(void *,s32,void *);
 u8 sp8[0x804];
 *(s32 *)(sp8+0x800)=0;
 func_0205ef8c(sp8,8,(u8 *)arg0+0x84);
 func_02049824(M2C_FIELD(arg0,s32 *,0),sp8,*(s32 *)(sp8+0x800),0,(u8 *)arg0+0xcc,8);
 M2C_FIELD(arg0,s32 *,0xb0)=func_02049208();
}

void func_0205fbb0(void *arg0, s32 arg1) {
    s32 func_02021c10(s32);
    s32 func_02049208(void);
    M2C_UNK func_02049824(s32, void *, s32, s32, void *, s32);
    M2C_UNK func_0205eb7c(void *, s32);
    M2C_UNK func_0205ebb0(void *, void *);
    M2C_UNK func_0205ef8c(void *, s32, void *);
    M2C_UNK func_0205f364(void *, void *, s32, s32, s32, s32, s32, s32);
    M2C_UNK func_020675e4(void *, void *, s32, ...);
    extern s32 data_0213e358;
    extern s32 data_0213e35c[];
    extern M2C_UNK data_020ffa88;
    extern M2C_UNK data_020ffa94;
    extern M2C_UNK data_020ffaa0;
    extern M2C_UNK data_020ffaa8;
    extern M2C_UNK data_020ffaac;
    extern M2C_UNK data_020ffab0;
    extern M2C_UNK data_020ffac0;
    extern M2C_UNK data_020ffacc;
    extern M2C_UNK data_020ffad8;
    char sp10[0x14];
    char sp24[0x804];
    M2C_UNK *var_r1;
    s32 temp_r0;
    s32 temp_r2;
    s32 var_r8;

    *(s32 *)(sp24 + 0x800) = 0;
    func_0205ef8c(sp24, 3, (char *)arg0 + 0x84);
    var_r8 = 0;
    if (data_0213e358 > 0) {
        do {
            func_020675e4(sp10, &data_020ffa88, var_r8);
            func_0205ebb0(sp24, sp10);
            func_0205ebb0(sp24, (M2C_UNK *)func_02021c10(data_0213e35c[var_r8]));
            var_r8 += 1;
        } while (var_r8 < data_0213e358);
    }
    func_0205ebb0(sp24, &data_020ffa94);
    func_0205eb7c(sp24, *(s32 *)((char *)arg0 + 0xC0));
    func_0205ebb0(sp24, &data_020ffaa0);
    if (*(s32 *)((char *)arg0 + 0xC8) != 0) {
        var_r1 = &data_020ffaa8;
    } else {
        var_r1 = &data_020ffaac;
    }
    func_0205ebb0(sp24, var_r1);
    if (arg1 != 0) {
        func_0205ebb0(sp24, &data_020ffab0);
        func_0205eb7c(sp24, arg1);
    }
    func_0205ebb0(sp24, &data_020ffac0);
    func_0205ebb0(sp24, (char *)arg0 + 4);
    if (*(s32 *)((char *)arg0 + 0xA8) != 0) {
        func_0205ebb0(sp24, &data_020ffacc);
        func_0205eb7c(sp24, *(s32 *)((char *)arg0 + 0x104));
        func_0205ebb0(sp24, &data_020ffad8);
        func_0205eb7c(sp24, (s32)*(u16 *)((char *)arg0 + 0x108));
    }
    if (arg1 != 2) {
        func_0205f364(arg0, sp24, 0xFF, 0, 0xFF, 0, 0xFF, 0);
    } else {
        temp_r2 = *(s32 *)(sp24 + 0x800);
        if ((0x800 - temp_r2) >= 1) {
            *(s32 *)(sp24 + 0x800) = temp_r2 + 1;
            sp24[temp_r2] = 0;
        }
    }
    func_02049824(*(s32 *)arg0, sp24, *(s32 *)(sp24 + 0x800), 0, (char *)arg0 + 0xCC, 8);
    temp_r0 = func_02049208();
    *(s32 *)((char *)arg0 + 0xAC) = temp_r0;
    *(s32 *)((char *)arg0 + 0xB0) = temp_r0;
    if (arg1 != 0) {
        *(s32 *)((char *)arg0 + 0xB4) = 0;
    }
}

void func_0205fdbc(s32 arg0,s32 arg1) {
extern s32 data_020ffc1c[];
if(arg0<50) goto done;
if(arg0>254) goto done;
data_020ffc1c[arg0]=arg1;
done: return;
}

u8 func_0205fddc(u8 *arg0,u32 arg1,u8 *arg2,u32 arg3,u8 *arg4,u32 *arg5){
 u32 count;u32 mask;u32 result;
 if(arg1==0)return 0;
 count=0;mask=1;
 while(mask<arg1)mask=mask*2+1;
 do {
 u32 pos=(*arg5)++;
 *arg4=arg0[*arg4]+arg2[pos];
 if(*arg5>=arg3){*arg5=0;*arg4+=arg3;}
 count++;
 result=mask & *arg4;
 if(count>11)result%=arg1;
 }while(result>arg1);
 return result;
}

void func_0205fe90(u8 *arg0){
 s32 i,j;
 arg0[0x100]=1;arg0[0x101]=3;arg0[0x102]=5;arg0[0x103]=7;arg0[0x104]=11;
 for(i=0,j=255;i<256;i++,j--)arg0[i]=j;
}

void func_0205fed8(u8 *arg0,u8 *arg1,u32 arg2) {
s32 i; u32 pos; u8 value; u8 j; u8 temp;
if(arg2<1) {func_0205fe90(arg0); return;}
for(i=0;i<256;i++) arg0[i]=i;
pos=0;value=0;
for(i=255;i>=0;i--) {
j=func_0205fddc(arg0,i,arg1,arg2,&value,&pos);
temp=arg0[i];arg0[i]=arg0[j];arg0[j]=temp;
}
arg0[256]=arg0[1];arg0[257]=arg0[3];arg0[258]=arg0[5];arg0[259]=arg0[7];arg0[260]=arg0[value];
value=0;pos=0;
}

u8 func_0205ffa0(void *arg0,u8 arg1) {
u8 *p=arg0; u8 temp; u8 old;
old=p[256]++;
p[257]+=p[old];
temp=p[p[260]];
p[p[260]]=p[p[257]];
p[p[257]]=p[p[259]];
p[p[259]]=p[p[256]];
p[p[256]]=temp;
p[258]+=p[temp];
p[259]=arg1 ^ p[(u8)(p[p[258]]+p[p[256]])] ^ p[p[(u8)(p[p[259]]+p[p[260]]+p[p[257]])]];
p[260]=arg1;
return p[259];
}

void func_0206006c(void *a,u8 *b,s32 n){u8 func_0205ffa0(void *,u8);s32 i;for(i=0;i<n;i++)b[i]=func_0205ffa0(a,b[i]);}

void func_020600a8(void *arg0, void *arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 0x20) = arg1;
    }
    M2C_FIELD(arg0, void **, 4) = arg1;
    M2C_FIELD(arg1, s32 *, 0x20) = 0;
    if (M2C_FIELD(arg0, void **, 0) == NULL) {
        M2C_FIELD(arg0, void **, 0) = arg1;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
}

void func_020600dc(void *arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 0x20) = (void *) M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(arg0, void **, 0) = arg1;
    if (M2C_FIELD(arg0, void **, 4) == NULL) {
        M2C_FIELD(arg0, void **, 4) = arg1;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
}

void *func_02060104(void *arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if (temp_r2 != NULL) {
        temp_r1 = M2C_FIELD(temp_r2, void **, 0x20);
        M2C_FIELD(arg0, void **, 0) = temp_r1;
        if (temp_r1 == NULL) {
            M2C_FIELD(arg0, s32 *, 4) = 0;
        }
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) - 1);
    }
    return temp_r2;
}

s32 func_02060138(void *a,void *b){void *p=M2C_FIELD(a,void **,0),*prev=0;while(p){if(p==b){if(prev)M2C_FIELD(prev,void **,32)=M2C_FIELD(p,void **,32);if(M2C_FIELD(a,void **,0)==p)M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,32);if(M2C_FIELD(a,void **,4)==p)M2C_FIELD(a,void **,4)=prev;M2C_FIELD(a,s32 *,8)--;return 1;}prev=p;p=M2C_FIELD(p,void **,32);}return 0;}

void func_020601a4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_020601b8(void *a,void *b,s32 unused){
s32 func_02049208(void);
M2C_UNK func_02049824(s32,void *,s32,s32,void *,s32);
u8 buf[256]; u8 addr[8]; s32 n,i;
func_020600a8(a+8,b); M2C_FIELD(b,s32 *,28)=func_02049208();
addr[1]=2;
if(M2C_FIELD(b,u8 *,20)&32)return;
if(M2C_FIELD(a,s32 *,0)==1){
i=0;buf[0]=254;buf[1]=253;buf[2]=i;
*(PacketBytes4 *)(buf+3)=*(PacketBytes4 *)(b+28);
if(M2C_FIELD(b,u8 *,20)&4){
buf[7]=M2C_FIELD(a,s32 *,64);
for(;i<M2C_FIELD(a,s32 *,64);i++)buf[8+i]=M2C_FIELD(a+i,u8 *,44);
buf[M2C_FIELD(a,s32 *,64)+8]=0;buf[M2C_FIELD(a,s32 *,64)+9]=0;
n=M2C_FIELD(a,s32 *,64)+10;
}else{buf[7]=255;buf[8]=255;buf[9]=255;n=10;}
}else if(M2C_FIELD(b,u8 *,20)&4){*(PacketBytes13 *)buf=data_02100014;n=13;}
else{*(PacketBytes8 *)buf=data_02100024;n=8;}
if(M2C_FIELD(b,s32 *,0)==M2C_FIELD(a,s32 *,40)&&(M2C_FIELD(b,u8 *,21)&2)){
*(s32 *)(addr+4)=M2C_FIELD(b,s32 *,8);*(u16 *)(addr+2)=M2C_FIELD(b,u16 *,12);
}else{*(s32 *)(addr+4)=M2C_FIELD(b,s32 *,0);*(u16 *)(addr+2)=M2C_FIELD(b,u16 *,4);}
func_02049824(M2C_FIELD(a,s32 *,32),buf,n,0,addr,8);
}

void func_02060398(void *arg0,s32 arg1,s32 arg2,s32 d,s32 e,s32 f){
 void *a=arg0;
 s32 b=arg1;
 s32 c=arg2;
 M2C_UNK func_0204926c();
 s32 func_020496a4(s32,s32);
 extern s32 gDnsQueryState;
 if(!d && gDnsQueryState!=1)return;
 func_0204926c();
 M2C_FIELD(a,s32 *,0)=c;
 M2C_FIELD(a,s32 *,4)=b;
 M2C_FIELD(a,s32 *,64)=0;
 M2C_FIELD(a,s32 *,68)=e;
 M2C_FIELD(a,s32 *,72)=f;
 M2C_FIELD(a,s32 *,40)=0;
 M2C_FIELD(a,s32 *,32)=func_020496a4(2,2);
 func_020601a4(a+20);
 func_020601a4(a+8);
}

void func_0206040c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x28) = arg1;
}

void func_02060414(s32 arg0) {
    func_020601a4(arg0 + 0x14);
    func_020601a4(arg0 + 8);
}

void func_02060430(void *arg0) {
    M2C_UNK func_020496b8(s32);
    func_020496b8(M2C_FIELD(arg0, s32 *, 0x20));
    M2C_FIELD(arg0, s32 *, 0x20) = -1;
    func_020601a4(arg0 + 0x14);
    func_020601a4(arg0 + 8);
}

void func_0206045c(void *a,void *b,s32 c,s32 d){void func_020601b8(void *,void *,s32);M2C_FIELD(b,u8 *,20)&=0xc3;if(d==0)M2C_FIELD(b,u8 *,20)|=4;else if(d==1)M2C_FIELD(b,u8 *,20)|=8;else if(d==2)return;if(M2C_FIELD(a,s32 *,16)<M2C_FIELD(a,s32 *,4))func_020601b8(a,b,c);else if(c)func_020600dc(a+20,b);else func_020600a8(a+20,b);}

/* Dispatch each chunk of a typed message to its handlers found via a table, or fall back to a direct handler. */
void func_020604d8(void *owner, void *entry, s8 *payload, s32 length) {
    s32 func_02049208(void);
    void func_02060a84(void *, s32, void *);
    void func_02060e10(void *, void *, s32);
    s32 func_02061da0(void *, s32);
    extern s32 data_020ffc1c[];
    s32 chunkLen;
    s32 index;

    if (*payload != 0) {
        return;
    }
    payload += 5;
    length -= 5;
    if (M2C_FIELD(entry, u8 *, 0x14) & 4) {
        index = 0;
        while (index < M2C_FIELD(owner, s32 *, 0x40)) {
            chunkLen = func_02061da0(payload, length);
            if (chunkLen < 0) {
                break;
            }
            func_02060a84(entry, data_020ffc1c[M2C_FIELD(owner + index, u8 *, 0x2C)], payload);
            index++;
            payload += chunkLen;
            length -= chunkLen;
        }
        M2C_FIELD(entry, u8 *, 0x14) |= 0x41;
    } else {
        func_02060e10(entry, payload, length);
        M2C_FIELD(entry, u8 *, 0x14) |= 0x43;
    }
    M2C_FIELD(entry, u8 *, 0x14) &= 0xF3;
    M2C_FIELD(entry, s32 *, 0x1C) = func_02049208() - M2C_FIELD(entry, s32 *, 0x1C);
    func_02060138((u8 *)owner + 8, entry);
    M2C_FIELD(owner, void (**)(void *, s32, void *, s32), 0x44)(owner, 0, entry, M2C_FIELD(owner, s32 *, 0x48));
}

void func_020605d8(void *arg0, void *arg1, void *arg2, s32 unused) {
    s32 func_02049208();
    M2C_UNK func_02060138(void *, void *);
    M2C_UNK func_02060d90(void *, M2C_UNK);
    s32 func_02068fdc(M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_02100030;
    s32 var_r6;
    u8 temp_r0;

    if (func_02068fdc(arg2, &data_02100030) != 0) {
        var_r6 = 1;
    } else {
        var_r6 = 0;
    }
    func_02060d90(arg1, arg2);
    if (var_r6 == 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg1, u8 *, 0x14);
    if (temp_r0 & 4) {
        M2C_FIELD(arg1, u8 *, 0x14) = temp_r0 | 0x41;
    } else {
        M2C_FIELD(arg1, u8 *, 0x14) = temp_r0 | 0x42;
    }
    M2C_FIELD(arg1, u8 *, 0x14) = (u8)(M2C_FIELD(arg1, u8 *, 0x14) & 0xF3);
    M2C_FIELD(arg1, s32 *, 0x1C) = (s32) (func_02049208() - M2C_FIELD(arg1, s32 *, 0x1C));
    func_02060138(arg0 + 8, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK, void *, s32), 0x44)(arg0, 0, arg1, M2C_FIELD(arg0, s32 *, 0x48));
}

s32 func_02060670(void *a,void *b,void *c,s32 d) {
    return 1;
}

#pragma opt_strength_reduction off
void func_02060678(void *p,s32 mode){
s32 func_02049534(s32);s32 func_020497e0(s32,void *,s32,s32,void *,s32 *);

s8 buf[2048];u8 addr[8];s32 alen=8;s32 n;void *q; s32 sock;u32 peer,ip;
sock=mode?M2C_FIELD(p,s32 *,0x24):M2C_FIELD(p,s32 *,0x20);
while(func_02049534(sock)){
n=func_020497e0(sock,buf,2047,0,addr,&alen);if(n==-1)return;buf[n]=0;
for(q=M2C_FIELD(p,void **,8);q;q=M2C_FIELD(q,void **,0x20)){
if(mode&&(M2C_FIELD(q,u8 *,0x15)&8)&&M2C_FIELD(q,u32 *,0x10)==M2C_FIELD(addr,u32 *,4))goto found;
ip=M2C_FIELD(addr,u32 *,4);peer=M2C_FIELD(q,u32 *,0);
if(peer==ip){if(M2C_FIELD(q,u16 *,4)!=M2C_FIELD(addr,u16 *,2))goto fallback;goto found;}
fallback:
if(mode)goto found;
if(peer==M2C_FIELD(p,u32 *,0x28)&&(M2C_FIELD(q,u8 *,0x15)&2)&&M2C_FIELD(q,u32 *,8)==ip&&M2C_FIELD(q,u16 *,12)==M2C_FIELD(addr,u16 *,2))goto found;
continue;
found:
if(mode){if(!func_02060670(p,q,buf,n))continue;break;}
else{if(M2C_FIELD(p,s32 *,0)==1)func_020604d8(p,q,buf,n);else func_020605d8(p,q,buf,n);break;}
}
next_packet:;
}
}
#pragma opt_strength_reduction reset
