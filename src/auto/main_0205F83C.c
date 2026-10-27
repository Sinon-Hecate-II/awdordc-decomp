/* 24 functions from 0x0205F83C to 0x0206080C (main), found by ds-decomp. */
#include "common.h"

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

void func_0205fdbc(s32 arg0,s32 arg1){
 extern s32 data_020ffc1c[];
 if(arg0<50)goto done;
 if(arg0>254)goto done;
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

void func_02060398(void *arg0,s32 arg1,s32 arg2,s32 d,s32 e,s32 f){void *a;s32 b;s32 c;M2C_UNK func_0204926c();s32 func_020496a4(s32,s32);extern s32 gDnsQueryState;a=arg0;b=arg1;c=arg2;if(!d && gDnsQueryState!=1)return;func_0204926c();M2C_FIELD(a,s32 *,4)=b;M2C_FIELD(a,s32 *,0)=c;M2C_FIELD(a,s32 *,64)=0;M2C_FIELD(a,s32 *,68)=e;M2C_FIELD(a,s32 *,72)=f;M2C_FIELD(a,s32 *,40)=0;M2C_FIELD(a,s32 *,32)=func_020496a4(2,2);func_020601a4(a+20);func_020601a4(a+8);}

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

void func_020605d8(void *arg0, void *arg1, M2C_UNK arg2) {
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

s32 func_02060670(void) {
    return 1;
}

