/* 10 functions from 0x0203E908 to 0x0203F45C (main), found by ds-decomp. */
#include "common.h"
void *func_02044268(void);
typedef struct PacketTag5 { u8 a, b, c, d, e; } PacketTag5;
typedef struct SendPacket { u8 tag[4]; s32 kind; s8 command; u8 length; u16 id; s32 value; s32 state; u32 payload[32]; } SendPacket;
typedef M2C_UNK (*fmt_fn_t)(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, M2C_UNK);


void func_0203e908(u8 arg0, u8 arg1, s32 arg2, s32 arg3) {
    void func_0203e570(s32);
    void *func_02044268(void);
    void func_0205fdbc(s32, s8 *);
    extern M2C_UNK data_020fc958;
    extern M2C_UNK data_020fc960;
    extern M2C_UNK data_020fc96c;
    extern M2C_UNK data_020fc978;
    extern M2C_UNK data_020fc984;
    func_0203e570(0);
    M2C_FIELD(func_02044268(), u8 *, 0x15) = arg0;
    M2C_FIELD(func_02044268(), u8 *, 0x16) = arg1;
    M2C_FIELD(func_02044268(), s32 *, 0x464) = arg2;
    M2C_FIELD(func_02044268(), s32 *, 0x468) = arg3;
    M2C_FIELD(func_02044268(), u8 *, 0x17D) = 0;
    M2C_FIELD(func_02044268(), u8 *, 0x2D0) = 0;
    func_0205fdbc(0x32, (s8 *)&data_020fc958);
    func_0205fdbc(0x33, (s8 *)&data_020fc960);
    func_0205fdbc(0x34, (s8 *)&data_020fc96c);
    func_0205fdbc(0x35, (s8 *)&data_020fc978);
    func_0205fdbc(0x36, (s8 *)&data_020fc984);
}

void func_0203e9b0(void) {
    M2C_UNK func_020376d8(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_0203bd0c();
    M2C_UNK func_020427f4();
    void *func_02044268();
    M2C_UNK func_02044278(M2C_UNK);
    M2C_UNK func_020614b0(s32);
    extern M2C_UNK data_0213d39c;
    if (func_02044268() == NULL) {
        return;
    }
    if (M2C_FIELD(func_02044268(), s32 *, 0xE4) != 0) {
        if (M2C_FIELD(&data_0213d39c, s32 *, 0x18) != 0) {
            M2C_FIELD(&data_0213d39c, s32 *, 0x14) = 1;
        } else {
            func_020614b0(M2C_FIELD(func_02044268(), s32 *, 0xE4));
            M2C_FIELD(func_02044268(), s32 *, 0xE4) = 0;
        }
    }
    func_0203bd0c();
    func_02044278(0);
    if (M2C_FIELD(&data_0213d39c, s32 *, 8) != 0) {
        func_020376d8(4, M2C_FIELD(&data_0213d39c, s32 *, 8), 0);
        M2C_FIELD(&data_0213d39c, s32 *, 8) = 0;
    }
    func_020427f4();
    M2C_FIELD(func_02044268(), s8 *, 0x18) = 1;
}

s32 func_0203ea4c(s32 value) {
    void func_0203ec48(M2C_UNK,s32,s32,s32);
    M2C_UNK func_0200567c();
    void func_02061738(s32);
    s32 func_02061604(s32,s32,s32,void *,s32,void *,s32);
    u64 func_02007004(void);
    extern M2C_UNK data_0213d3bc,data_0213d39c,data_020fc990,data_020fc99c,data_020fc958;
    char text[256];
    u8 ids[161];
    s32 count=7,i,result;
    u8 *src,*dst;
    void *p,*q,*r;
    s32 a,b,c;
    ids[0]=8;ids[1]=10;ids[2]=50;ids[3]=51;ids[4]=52;ids[5]=53;ids[6]=54;
    if(M2C_FIELD(func_02044268(),u8 *,0x15)==0 || M2C_FIELD(func_02044268(),u8 *,0x15)==1) {
        src=(u8 *)&data_0213d3bc;dst=ids+7;
        for(i=0;i<154;i++,src+=12) {
            u8 v=*src;
            if(v!=0){*dst++=v;count++;}
        }
    }
    switch(M2C_FIELD(func_02044268(),u32 *,0x1a0)) {
    case 3:
        if(M2C_FIELD(func_02044268(),s32 *,0x208)==0){
            p=func_02044268();q=func_02044268();
            r=func_02044268();
            a=M2C_FIELD(p,volatile s32 *,0x200);b=M2C_FIELD(q,volatile u8 *,0x16);c=M2C_FIELD(r,volatile u8 *,0x15);
            func_0203ec48((s32)text,a,b,c);
            value=M2C_FIELD(&data_0213d39c,s32 *,8);
            if(value!=0)func_0200567c(text,256,&data_020fc990,text,value);
            break;
        }
        value=M2C_FIELD(func_02044268(),s32 *,0x208);
    case 2:case 4:case 5:
        func_0200567c(text,256,&data_020fc99c,&data_020fc958,value);
        M2C_FIELD(func_02044268(),s32 *,0x204)=value;
        break;
    default:break;
    }
    func_02061738(M2C_FIELD(func_02044268(),s32 *,0xe4));
    for(i=0;i<5;i++){
        result=func_02061604(M2C_FIELD(func_02044268(),s32 *,0xe4),1,0,ids,count,text,6);
        if(result==0)break;
        if(result!=2)break;
    }
    if(result==0){
        p=func_02044268();
        M2C_FIELD(p,u64 *,0x174)=func_02007004()+0xefb5f7;
    }
    return result;
}

void func_0203ec48(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_0200567c(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, M2C_UNK *, s32, s32, s32, M2C_UNK *, s32, M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_020fc958;
    extern M2C_UNK data_020fc960;
    extern M2C_UNK data_020fc96c;
    extern M2C_UNK data_020fc978;
    extern M2C_UNK data_020fc9a4;
    func_0200567c(arg0, 0x100, &data_020fc9a4, &data_020fc978, 3, &data_020fc958, arg1, arg2, arg2, &data_020fc960, arg3, &data_020fc96c, &data_020fc958);
}

s32 func_0203ecb0(s32 arg0, s32 arg1, s32 arg2) {
    (void)arg0; (void)arg1; (void)arg2;
    return 0;
}

s32 func_0203ef9c(void *arg0) {
    s32 func_02043008();
    s32 func_0205b048(s32);
    s32 func_0205d4d8(s32, M2C_UNK, M2C_UNK);
    s32 func_0205de88(s32, s32, u8, M2C_UNK *, M2C_UNK *, void *);
    M2C_UNK func_02061690(s32, s32, u16, s32);
    extern M2C_UNK func_02043e0c;
    extern M2C_UNK func_02043e10;
    s32 temp_r0;
    s32 var_r6;
    void *temp_r4;

    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        temp_r4 = func_02044268();
        func_02061690(M2C_FIELD(temp_r4, s32 *, 0xE4), func_0205d4d8(M2C_FIELD(arg0, s32 *, 4), 0, 0), M2C_FIELD(arg0, u16 *, 2), M2C_FIELD(arg0, s32 *, 8));
        if (func_02043008() != 0) {
            return 2;
        }
    }
    var_r6 = 0;
loop_4:
    temp_r0 = func_0205de88(func_0205b048(*M2C_FIELD(func_02044268(), s32 **, 4)), M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, u8 *, 0), &func_02043e0c, &func_02043e10, arg0);
    if (temp_r0 == 0) {
        return temp_r0;
    }
    if (temp_r0 != 3) {
        return temp_r0;
    }
    var_r6 += 1;
    if (var_r6 >= 5) {
        return temp_r0;
    }
    goto loop_4;
}

s32 func_0203f058(u8 command, s32 arg1, s32 arg2, u16 arg3, s32 *values, s32 count) {
    void func_0203f31c(M2C_UNK,s32,M2C_UNK,u8 *);
    s32 func_0203f20c(s32,s32,s32,s32,s32);
    void func_02007e70(s32,void *,s32);
    M2C_UNK func_0200567c();
    void func_02008048(u8 *,u8 *,u32);
    u64 func_02007004(void);
    extern M2C_UNK data_020fc908, data_020fc9fc;
    u8 buffer[0x200];
    u8 temp[0x10];
    s32 len=0, i, n, result;
    void *p;
    if (M2C_FIELD(func_02044268(),u8 *,0x15) == 0 ||
        ( (M2C_FIELD(func_02044268(),u8 *,0x15) == 3 ||
        M2C_FIELD(func_02044268(),u8 *,0x1a6) != 0) && command == 6)) {
        result=func_0203f20c(command,arg2,arg3,(s32)values,count);
    } else {
        if (values != 0 && count != 0) {
            len=func_0200567c(buffer,0x200,&data_020fc908,values[0]);
            for(i=1;i<count;i++){
                n=func_0200567c(temp,0x10,&data_020fc9fc,values[i]);
                func_02008048(temp,buffer+len,n);
                len+=n;
            }
        }
        buffer[len]=0;
        result=((s32 (*)())func_0203f31c)(M2C_FIELD(func_02044268(),s32 *,0),command,arg1,buffer);
    }
    if(command==2 || command==6 || (u8)(command+0xf8)<=1) {
        M2C_FIELD(func_02044268(),u8 *,0x3cc)=command;
        M2C_FIELD(func_02044268(),u16 *,0x3ce)=arg3;
        M2C_FIELD(func_02044268(),s32 *,0x3d0)=arg2;
        M2C_FIELD(func_02044268(),s32 *,0x454)=arg1;
        M2C_FIELD(func_02044268(),s32 *,0x458)=count;
        p=func_02044268();
        M2C_FIELD(p,u64 *,0x45c)=func_02007004();
        if(values!=0 && count!=0)func_02007e70((s32)values,(u8 *)func_02044268()+0x3d4,count*4);
    }
    return result;
}

s32 func_0203f20c(s32 command, s32 dest, s32 mode, s32 payload, s32 count) {
    void func_02007e70(s32, void *, s32);
    void *func_02044268(void);
    s32 func_0205d4d8(s32, s32, s32);
    s32 func_02061638(s32, s32, s32, void *, s32);
    extern PacketTag5 data_020fca00;
    SendPacket packet;
    u8 e, d, c, b, a;
    u8 *tag;
    s32 i, result;
    void *context;
    if (payload != 0 && count != 0) {
        func_02007e70(payload, packet.payload, count * 4);
    } else {
        count = 0;
    }
    count *= 4;
    tag = (u8 *)&packet;
    e = data_020fca00.e;
    a = data_020fca00.a;
    b = data_020fca00.b;
    c = data_020fca00.c;
    d = data_020fca00.d;
    tag[4] = e;
    tag[0] = a;
    tag[1] = b;
    tag[2] = c;
    tag[3] = d;
    packet.kind = 3;
    packet.command = command;
    packet.length = count;
    packet.id = M2C_FIELD(func_02044268(), u16 *, 0x1a);
    packet.value = M2C_FIELD(func_02044268(), s32 *, 0x1c);
    packet.state = M2C_FIELD(func_02044268(), s32 *, 0x200);
    for (i = 0; i < 5; i++) {
        context = func_02044268();
        result = func_02061638(M2C_FIELD(context, s32 *, 0xe4), func_0205d4d8(dest, 0, 0), mode, tag, packet.length + 20);
        if (result == 0) {
            return result;
        }
        if (result != 2) {
            return result;
        }
    }
    return result;
}

void func_0203f31c(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, u8 *arg3) {
    M2C_UNK func_0200567c();
    s32 func_02068c34(u8 *);
    void func_02008048(u8 *, u8 *, u32);
    void func_0204e634(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_020fca08;
    extern M2C_UNK data_020fca10;
    extern M2C_UNK data_020fca18;
    char buf[0x200];
    s32 len;
    u8 *tail;
    len = (s32)func_0200567c((M2C_UNK)buf, 0x200, (M2C_UNK)&data_020fca08, (M2C_UNK)&data_020fca10, 3, (M2C_UNK)&data_020fca18);
    buf[len] = (u8)arg1;
    buf[len + 1] = 0;
    tail = (u8 *)buf + len + 1;
    if (arg3 != 0) {
        s32 alen = func_02068c34(arg3);
        func_02008048(arg3, tail, (u32)alen);
        tail[alen] = 0;
    }
    func_0204e634(arg0, arg2, (M2C_UNK)buf);
}

s32 func_0203f3c0(u8 *arg0, u8 *arg1, s32 arg2) {
    s8 *func_02068ee0(s8 *, s32);
    void func_02008048(u8 *, u8 *, u32);
    u8 *p = arg1;
    u8 *end = (u8 *)func_02068ee0((s8 *)arg1, 0);
    s32 count = 0;
    if (arg2 > 0) {
        s8 *f;
        do {
            f = func_02068ee0((s8 *)p, '/');
            if (f == 0) {
                return -1;
            }
            count += 1;
            p = (u8 *)f + 1;
        } while (count < arg2);
    }
    {
        u8 *f2 = (u8 *)func_02068ee0((s8 *)p, '/');
        if (f2 == 0) {
            f2 = end;
        }
        if (p == f2) {
            return -1;
        }
        {
            s32 len = (s32)(f2 - p);
            func_02008048(p, arg0, len);
            arg0[len] = 0;
            return len;
        }
    }
}

