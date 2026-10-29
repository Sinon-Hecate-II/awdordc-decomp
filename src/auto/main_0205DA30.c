/* 20 functions from 0x0205DA30 to 0x0205E95C (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 bytes[6]; } NetworkAddress6;
typedef struct { u8 bytes[20]; } NetworkPacket20Bytes;
typedef struct { NetworkAddress6 address; u8 type, length; u32 ip, value; u16 port; u8 flag, mode; } NetworkPacket20;
typedef struct { u8 bytes[21]; } NetworkPacket21Bytes;
typedef struct { NetworkAddress6 address; u8 type, length; u32 ip; u8 reserved, value; u8 tail[7]; } NetworkPacket21;
extern NetworkAddress6 data_020ff88c;

#pragma opt_propagation off
void func_0205dc78(void *arg0) {
    void func_0205d944(s32, s32, u16, void *, s32);
    s32 func_02049208(void);
    extern NetworkAddress6 data_020ff88c;
    u8 sp04[0x14];

    register u8 *pr1 asm("r1") = (u8 *)&data_020ff88c;
    register s32 vr2 asm("r2");
    register u8 vr7 asm("r7");
    register u8 vr6 asm("r6");
    register u8 *vr8 asm("r8") = sp04;
    register u8 vr5 asm("r5");
    register u8 vlr asm("lr");
    register u8 vr12 asm("r12");
    register u8 vr3 asm("r3");
    register void *vr4 asm("r4");

    vr7 = pr1[0];
    vr6 = pr1[1];
    vr5 = pr1[2];
    vlr = pr1[3];
    vr12 = pr1[4];
    vr3 = pr1[5];
    vr4 = arg0;

    *vr8 = vr7;
    vr8[1] = vr6;
    vr8[2] = vr5;
    vr8[3] = vlr;
    vr8[4] = vr12;
    vr2 = 2;
    pr1 = (u8 *)7;
    sp04[6] = (u8)vr2;
    sp04[7] = (u8)pr1;
    vr8[5] = vr3;

    {
        u32 ip = M2C_FIELD(vr4, u32 *, 8);
        *(u32 *)(sp04 + 8) =
            ((ip >> 24) & 0xFFU) |
            ((ip >> 8) & 0xFF00U) |
            ((ip << 8) & 0xFF0000U) |
            ((ip << 24) & 0xFF000000U);
    }
    *(u32 *)(sp04 + 12) = M2C_FIELD(vr4, u32 *, 0x2C);
    {
        u16 port = M2C_FIELD(vr4, u16 *, 0x30);
        *(u16 *)(sp04 + 16) = (u16)((((s32)port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    }
    sp04[18] = M2C_FIELD(vr4, u8 *, 0x32);
    sp04[19] = (M2C_FIELD(vr4, s32 *, 0x10) != 2) ? 1 : 0;

    {
        s32 val = M2C_FIELD(vr4, s32 *, 4);
        if (val == -1) {
            val = M2C_FIELD(vr4, s32 *, 0);
        }
        func_0205d944(val, M2C_FIELD(vr4, s32 *, 0x2C), M2C_FIELD(vr4, u16 *, 0x30), sp04, 0x14);
    }
    M2C_FIELD(vr4, s32 *, 0x28) = func_02049208() + 0x2BC;
    M2C_FIELD(vr4, s32 *, 0x24) = 0xC;
    if (M2C_FIELD(vr4, u8 *, 0x32) != 0) {
        M2C_FIELD(vr4, s8 *, 0x33) = 1;
    }
}
#pragma opt_propagation reset
s32 func_0205dd98(M2C_UNK arg0) {
    void *func_02021768(M2C_UNK);
    s32 func_020498e4();
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0_2 = func_020498e4();
    if (temp_r0_2 != -1) {
        return temp_r0_2;
    }
    temp_r0 = func_02021768(arg0);
    if (temp_r0 == NULL) {
        return 0;
    }
    return **M2C_FIELD(temp_r0, s32 ***, 0xC);
}

s32 func_0205ddd0(void *arg0, s32 arg1) {
 M2C_UNK func_020675bc(void *,s32,void *,void *,s32);
 extern M2C_UNK data_020ff894, gServiceNameBuffer;
 u8 buffer[0x80];
 if (arg0 == NULL) {
 func_020675bc(buffer,0x80,&data_020ff894,&gServiceNameBuffer,arg1);
 arg0=buffer;
 }
 return func_0205dd98((M2C_UNK)arg0);
}

s32 func_0205de10(void) {
 extern M2C_UNK data_0213e144, data_020ff89c, data_020ff8b8;
 if (M2C_FIELD(&data_0213e144,s32 *,12)==0)
 M2C_FIELD(&data_0213e144,s32 *,12)=func_0205ddd0(M2C_FIELD(&data_0213e144,void **,4),(s32)&data_020ff89c);
 if (M2C_FIELD(&data_0213e144,s32 *,8)==0)
 M2C_FIELD(&data_0213e144,s32 *,8)=func_0205ddd0(M2C_FIELD(&data_0213e144,void **,0),(s32)&data_020ff8b8);
 if(M2C_FIELD(&data_0213e144,s32 *,12)==0 || M2C_FIELD(&data_0213e144,s32 *,8)==0) return 0;
 return 1;
}

#pragma opt_propagation off
s32 func_0205de88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_020496a4(M2C_UNK, M2C_UNK, M2C_UNK);
    void *func_0205d7f4();
    M2C_UNK func_0205d88c();
    M2C_UNK func_0205da30();
    s32 func_0205de10();
    extern s32 gDnsQueryState;
    void *temp_r0;

    if (gDnsQueryState != 1) {
        return 2;
    }
    if (func_0205de10() == 0) {
        return 3;
    }
    temp_r0 = func_0205d7f4();
    if (temp_r0 == NULL) {
        return 1;
    }
    M2C_FIELD(temp_r0, s32 *, 4) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg2;
    M2C_FIELD(temp_r0, s32 *, 8) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg4;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg5;
    M2C_FIELD(temp_r0, s32 *, 0) = func_020496a4(arg4 - arg4 + 2, arg5 - arg5 + 2, 0);
    M2C_FIELD(temp_r0, s32 *, 0x20) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x32) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x33) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x30) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    if (M2C_FIELD(temp_r0, s32 *, 0) == -1) {
        func_0205d88c();
        return 2;
    }
    func_0205da30();
    return 0;
}
#pragma opt_propagation on
void func_0205df50(void) {
 void *func_0205d75c(void);
 void func_020496b8(s32);
 void *p=func_0205d75c();
 if(p==NULL)return;
 if(M2C_FIELD(p,s32 *,0)!=-1) func_020496b8(M2C_FIELD(p,s32 *,0));
 M2C_FIELD(p,s32 *,0)=-1;
 M2C_FIELD(p,s32 *,16)=4;
}

void func_0205df88(void *p) {
s32 func_0205d88c(); s32 func_02049534(s32); s32 func_020497e0(s32,void *,s32,s32,void *,s32 *); void func_0205e510(u8 *,s32,M2C_UNK); s32 func_02049208(void); s32 func_0205da30(); void func_0205dc78(void *);
extern u8 data_0213e158[];
u8 address[8]; s32 size=8; u8 packet[8]; s32 n;
if(M2C_FIELD(p,s32 *,16)==4){func_0205d88c(p);return;}
if(-1!=M2C_FIELD(p,s32 *,0)){
do {
if(!func_02049534(M2C_FIELD(p,s32 *,0)))break;
n=func_020497e0(M2C_FIELD(p,s32 *,0),data_0213e158,512,0,address,&size);
if(n==-1)break;
func_0205e510(data_0213e158,n,(M2C_UNK)address);
} while(M2C_FIELD(p,s32 *,16)!=4 && M2C_FIELD(p,s32 *,0)!=-1);
}
if((M2C_FIELD(p,s32 *,16)==0 || M2C_FIELD(p,s32 *,16)==2) && (u32)func_02049208()>M2C_FIELD(p,u32 *,40)){
if(M2C_FIELD(p,s32 *,32)>M2C_FIELD(p,s32 *,36)){
M2C_FIELD(p,M2C_UNK (**)(s32,s32,void *,s32),56)(2,-1,0,M2C_FIELD(p,s32 *,60));
((void (*)(s32))func_0205df50)(M2C_FIELD(p,s32 *,8));
}else{
M2C_FIELD(p,s32 *,32)++;
if(M2C_FIELD(p,s32 *,16)==0)((void (*)(void *))func_0205da30)(p);else func_0205dc78(p);
}
}
if(M2C_FIELD(p,s32 *,16)==3 && (u32)func_02049208()>M2C_FIELD(p,u32 *,40)){
if(M2C_FIELD(p,s32 *,4)==-1){
u16 port;
packet[1]=2;
port=M2C_FIELD(p,u16 *,48);
*(u16 *)(packet+2)=((port>>8)&255)|((port<<8)&0xff00);
*(u32 *)(packet+4)=M2C_FIELD(p,u32 *,44);
M2C_FIELD(p,M2C_UNK (**)(s32,s32,void *,s32),56)(0,M2C_FIELD(p,s32 *,0),packet,M2C_FIELD(p,s32 *,60));
M2C_FIELD(p,s32 *,0)=-1;
}
((void (*)(s32))func_0205df50)(M2C_FIELD(p,s32 *,8));
}
if(M2C_FIELD(p,s32 *,16)==1 && (u32)func_02049208()>M2C_FIELD(p,u32 *,40)){
M2C_FIELD(p,M2C_UNK (**)(s32,s32,void *,s32),56)(1,-1,0,M2C_FIELD(p,s32 *,60));
((void (*)(s32))func_0205df50)(M2C_FIELD(p,s32 *,8));
}
}

void func_0205e178(void) {
    s32 func_02048688();
    M2C_UNK func_02048690(s32, s32);
    void func_0205df88();
    extern M2C_UNK data_0213e144;
    s32 var_r5;

    if (M2C_FIELD(&data_0213e144, s32 *, 0x10) == 0) {
        return;
    }
    var_r5 = func_02048688() - 1;
    if (var_r5 < 0) {
        return;
    }
    do {
        func_02048690(M2C_FIELD(&data_0213e144, s32 *, 0x10), var_r5);
        func_0205df88();
        var_r5 -= 1;
    } while (var_r5 >= 0);
}

M2C_UNK func_0205e1bc(void *arg0, M2C_UNK arg1) {
 void func_0205d944(s32,s32,u16,void *,s32);
 NetworkPacket21 packet;
 u16 port;
 u32 ip;
 packet.length=6;
 packet.address=data_020ff88c;
 packet.type=2;
 packet.value=M2C_FIELD(arg0,s32 *,12);
 ip=M2C_FIELD(arg0,u32 *,8);
 packet.ip=((ip<<24)&0xff000000)|(((ip<<8)&0xff0000)|((u8)(ip>>24)|((ip>>8)&0xff00)));
 port=M2C_FIELD(arg1,u16 *,2);
 func_0205d944(M2C_FIELD(arg0,s32 *,0),M2C_FIELD(arg1,s32 *,4),(u16)((u8)((s32)port>>8)|((port<<8)&0xff00)),&packet,21);
}

void func_0205e288(void *arg0, void *arg1, M2C_UNK arg2) {
    void func_0205dc78(void *);
    M2C_UNK func_0205e1bc(void *, M2C_UNK);
    s32 var_r0; u16 temp_r2; u8 temp_r1;
    (void)arg2;
    if (M2C_FIELD(arg1, u8 *, 0x13) == 0) func_0205e1bc(arg0, arg2);
    if (M2C_FIELD(arg0, s32 *, 0x10) >= 2) return;
    temp_r1 = M2C_FIELD(arg1, u8 *, 0x13);
    if (temp_r1) {
        var_r0 = 3; if (temp_r1 == 1) var_r0 = 1; else if (temp_r1 == 2) var_r0 = 2;
        M2C_FIELD(arg0, M2C_UNK (**)(s32, s32, s32, s32), 0x38)(var_r0, -1, 0, M2C_FIELD(arg0, s32 *, 0x3C));
        ((void (*)(s32))func_0205df50)(M2C_FIELD(arg0, s32 *, 8)); return;
    }
    M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg1, s32 *, 0x0C);
    temp_r2 = M2C_FIELD(arg1, u16 *, 0x10);
    M2C_FIELD(arg0, s16 *, 0x30) = (s16)(((u8)(temp_r2 >> 8)) | ((temp_r2 << 8) & 0xFF00));
    M2C_FIELD(arg0, s32 *, 0x10) = 2;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(s32, s32), 0x34)(2, M2C_FIELD(arg0, s32 *, 0x3C));
    func_0205dc78(arg0);
}

void func_0205e344(void *arg0, void *arg1, void *arg2) {
    s32 func_02049208();
    void func_0205dc78(void *);
    s32 temp_r1;
    u16 temp_r3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x10) < 2) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg2, s32 *, 4);
    temp_r3 = M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 0x30) = (s16) ((u8) ((s32) temp_r3 >> 8) | ((temp_r3 << 8) & 0xFF00));
    M2C_FIELD(arg0, s8 *, 0x32) = 1;
    if (M2C_FIELD(arg1, u8 *, 0x12) == 0) {
        func_0205dc78(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 2) {
        if (M2C_FIELD(arg0, u8 *, 0x33) == 0) {
            func_0205dc78(arg0);
        }
        M2C_FIELD(arg0, s32 *, 0x10) = 3;
        M2C_FIELD(arg0, s32 *, 0x28) = (s32) (func_02049208() + 0x1388);
        temp_r1 = M2C_FIELD(arg0, s32 *, 4);
        if (temp_r1 == -1) {
            return;
        }
        M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, s32, void *, s32), 0x38)(0, temp_r1, arg2, M2C_FIELD(arg0, s32 *, 0x3C));
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 0x13) != 0) {
        return;
    }
    func_0205dc78(arg0);
}

void func_0205e40c(void *arg0, void *arg1, void *arg2) {
    M2C_UNK func_02049208(void);
    void func_0205d944(s32, s32, u16, void *, s32);
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg1, u8 *, 7);
    switch (temp_r1) {
        case 1: {
            u8 temp_r0 = M2C_FIELD(arg1, u8 *, 0xC);
            if ((u32)temp_r0 > 2U) {
                break;
            }
            M2C_FIELD((void *)((u8 *)arg0 + (temp_r0 * 4)), s32 *, 0x14) = 1;
            if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
                break;
            }
            if (M2C_FIELD(arg0, s32 *, 0x18) == 0) {
                break;
            }
            if (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
                break;
            }
            if (M2C_FIELD(arg0, s32 *, 4) != -1) {
                if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
                    break;
                }
            }
            M2C_FIELD(arg0, s32 *, 0x10) = 1;
            M2C_FIELD(arg0, s32 *, 0x28) = func_02049208() + 0x2710;
            M2C_FIELD(arg0, void (**)(s32, s32), 0x34)(
                M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x3C));
            break;
        }
        case 2: {
            u16 port;
            u16 swapped;

            M2C_FIELD(arg1, u8 *, 7) = 3;
            port = M2C_FIELD(arg2, u16 *, 2);
            swapped = (u16)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
            func_0205d944(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg2, s32 *, 4),
                          swapped, arg1, 0x15);
            break;
        }
        default:
            break;
    }
}

void func_0205e510(u8 *packet,s32 length,M2C_UNK arg2) {
s32 func_0205d920(M2C_UNK);
void *func_0205d75c(void);
u32 a[5];
u32 b[6];
s32 kind;
u32 ip;
void *p;
if(!func_0205d920((M2C_UNK)packet))return;
kind=packet[7];
if(kind==5||kind==7){
if(length<20)return;
*(NetworkPacket20Bytes *)a=*(NetworkPacket20Bytes *)packet;
ip=*(u32 *)((u8 *)a+8);
p=((void *(*)(u32))func_0205d75c)(((ip>>24)&255)|((ip>>8)&0xff00)|((ip<<8)&0xff0000)|((ip<<24)&0xff000000));
if(!p)return;
if(kind==5)func_0205e288(p,&a,arg2);
else func_0205e344(p,&a,arg2);
}else{
if(length<21)return;
*(NetworkPacket21Bytes *)b=*(NetworkPacket21Bytes *)packet;
ip=*(u32 *)((u8 *)b+8);
p=((void *(*)(u32))func_0205d75c)(((ip>>24)&255)|((ip>>8)&0xff00)|((ip<<8)&0xff0000)|((ip<<24)&0xff000000));
if(!p)return;
func_0205e40c(p,&b,arg2);
}
}

#pragma push
#pragma opt_strength_reduction off
s32 func_0205e670(u8 **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    u8 *func_02037794(M2C_UNK);
    M2C_UNK func_02049208();
    M2C_UNK func_0205ec0c();
    s32 func_0205ec80(s8 *, s32, void *, M2C_UNK);
    M2C_UNK func_020675e4(s8 *, M2C_UNK *, s32);
    s32 func_02067774();
    M2C_UNK func_020677a8();
    M2C_UNK func_02068c50(void *, s32);
    extern M2C_UNK data_020ff8d8;
    extern M2C_UNK data_020ff9e8;
    extern s32 data_0213e358;
    extern s8 data_0213e370;
    s8 sp0[64];
    u8 *temp_r0;
    
    s32 var_r0_2;
    s32 var_r2;
    s32 var_r5;
    u8 *var_r6;
    s8 *var_r0;
    s8 temp_r4;
    s32 temp_r0_2;
    void *temp_r0_3;
    void *temp_r3;

    if (arg0 == NULL) {
        var_r6 = (u8 *)&data_020ff8d8;
    } else {
        var_r6 = *arg0 = func_02037794(0x110);
    }
    func_02049208();
    func_020677a8();
    func_02068c50(var_r6 + 4, arg3);
    func_02068c50(var_r6 + 0x44, arg4);
    M2C_FIELD(var_r6, s32 *, 0xC0) = arg2;
    var_r5 = 0;
    M2C_FIELD(var_r6, s32 *, 0xAC) = 0;
    M2C_FIELD(var_r6, s32 *, 0xB0) = 0;
    M2C_FIELD(var_r6, s32 *, 0) = arg1;
    M2C_FIELD(var_r6, s32 *, 0xB8) = 1;
    M2C_FIELD(var_r6, s32 *, 0x10C) = argD;
    M2C_FIELD(var_r6, s32 *, 0x88) = arg7;
    M2C_FIELD(var_r6, s32 *, 0x8C) = arg8;
    M2C_FIELD(var_r6, s32 *, 0x90) = arg9;
    M2C_FIELD(var_r6, s32 *, 0x94) = argA;
    M2C_FIELD(var_r6, s32 *, 0x98) = argB;
    M2C_FIELD(var_r6, s32 *, 0x9C) = argC;
    M2C_FIELD(var_r6, s32 *, 0xA0) = 0;
    M2C_FIELD(var_r6, s32 *, 0xA4) = 0;
    M2C_FIELD(var_r6, s32 *, 0xD4) = 0;
    M2C_FIELD(var_r6, s32 *, 0xBC) = arg5;
    M2C_FIELD(var_r6, s32 *, 0xC4) = 0;
    M2C_FIELD(var_r6, s32 *, 0xC8) = arg6;
    M2C_FIELD(var_r6, s32 *, 0x104) = 0;
    M2C_FIELD(var_r6, s16 *, 0x108) = 0;
    M2C_FIELD(var_r6, s32 *, 0xA8) = 0;
    M2C_FIELD(var_r6, s32 *, 0xB4) = 0;
    do {
        temp_r0_2 = func_02067774();
        temp_r3 = var_r6 + var_r5;
        var_r5 += 1;
        M2C_FIELD(temp_r3, s8 *, 0x84) = temp_r0_2 % 255;
    } while (var_r5 < 4);
    var_r2 = 0;
    do {
        ((s32 *)var_r6)[var_r2+54] = -1;
        var_r2 += 1;
    } while (var_r2 < 0xA);
    M2C_FIELD(var_r6, s32 *, 0x100) = 0;
    if (data_0213e358 == 0) {
        func_0205ec0c();
    }
    if (arg5 != 0) {
        temp_r4 = data_0213e370;
        if (temp_r4 == 0) {
            func_020675e4(sp0, &data_020ff9e8, arg3);
        }
        if (temp_r4 != 0) {
            var_r0 = &data_0213e370;
        } else {
            var_r0 = sp0;
        }
        var_r0_2 = func_0205ec80(var_r0, 0x6CFC, var_r6 + 0xCC, 0);
    } else {
        var_r0_2 = 1;
    }
    if (var_r0_2 == 0) {
        return 3;
    }
    return 0;
}
#pragma pop
void func_0205e834(void *arg0, s32 arg1) {
    extern void *data_020ff8d4;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = data_020ff8d4;
    }
    M2C_FIELD(var_r0, s32 *, 0xA0) = arg1;
}

void func_0205e84c(void *arg0, s32 arg1) {
    extern void *data_020ff8d4;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = data_020ff8d4;
    }
    M2C_FIELD(var_r0, s32 *, 0xA4) = arg1;
}

void func_0205e864(void *arg0, s32 arg1) {
 extern void *data_020ff8d4;
 if (arg0 == NULL) arg0 = data_020ff8d4;
 M2C_FIELD(arg0,s32 *,0xA8)=arg1;
}

void func_0205e87c(void *p) {
 extern void *data_020ff8d4;
 void func_0205e95c(void *);
 void func_0205e8b0(void *);
 if(p==NULL)p=data_020ff8d4;
 if(M2C_FIELD(p,s32 *,0xbc))func_0205e95c(p);
 func_0205e8b0(p);
}

void func_0205e8b0(void *arg0) {
 s32 func_02049534(s32);
 s32 func_020497e0(s32,void *,s32,s32,void *,s32 *);
 void func_0205f83c(void *,void *,s32,void *);
 extern u8 data_0213e3b0[];
 u8 spC[8]; s32 sp8=8; s32 n;
 if(M2C_FIELD(arg0,s32 *,0xc4)==0)return;
 if(func_02049534(M2C_FIELD(arg0,s32 *,0))==0)return;
 do {
 n=func_020497e0(M2C_FIELD(arg0,s32 *,0),data_0213e3b0,255,0,spC,&sp8);
 if(n!=-1){data_0213e3b0[n]=0;func_0205f83c(arg0,data_0213e3b0,n,spC);}
 }while(func_02049534(M2C_FIELD(arg0,s32 *,0))!=0);
}

