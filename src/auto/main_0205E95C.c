/* 22 functions from 0x0205E95C to 0x0205F83C (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 v[4]; } ByteQuad;
extern s32 data_0213e358;
extern u8 data_0213e35c[5][4];
extern u8 data_020ffa44[16];
extern u8 data_020eac30[8];

void func_0205e95c(void *arg0) {
    /* Check connection timeouts and retry/reset state as needed. */
    M2C_UNK func_0205fb50(void *);
    extern M2C_UNK data_020ffa08;
    s32 retryCount;
    u32 lastActivity;
    u32 now;

    now = func_02049208();
    if (M2C_FIELD(arg0, s32 *, 0) == -1) {
        return;
    }
    retryCount = M2C_FIELD(arg0, s32 *, 0xB8);
    if ((retryCount > 0) && ((u32) (now - M2C_FIELD(arg0, u32 *, 0xAC)) > 0x2710U)) {
        if (retryCount >= 4) {
            M2C_FIELD(arg0, s32 *, 0xB8) = 0;
            M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK *, s32), 0x9C)(5, &data_020ffa08, M2C_FIELD(arg0, s32 *, 0x10C));
            return;
        }
        func_0205fbb0(arg0, 3);
        M2C_FIELD(arg0, s32 *, 0xB8) = (s32) (M2C_FIELD(arg0, s32 *, 0xB8) + 1);
        goto block_14;
    }
    if ((M2C_FIELD(arg0, s32 *, 0xB4) != 0) && ((u32) (now - M2C_FIELD(arg0, u32 *, 0xAC)) > 0x2710U)) {
        func_0205fbb0(arg0, 1);
    } else {
        lastActivity = M2C_FIELD(arg0, u32 *, 0xAC);
        if (((u32) (now - lastActivity) > 0xEA60U) || (lastActivity == 0) || (now < lastActivity)) {
            func_0205fbb0(arg0, 0);
        }
    }
block_14:
    if ((u32) (now - M2C_FIELD(arg0, s32 *, 0xB0)) <= 0x4E20U) {
        return;
    }
    func_0205fb50(arg0);
}

void func_0205ea70(void *arg0) {
    s32 func_02049208();
    M2C_UNK func_0205fbb0(void *, M2C_UNK);
    extern void *data_020ff8d4;
    void *var_r4;

    var_r4 = arg0;
    if (var_r4 == NULL) {
        var_r4 = data_020ff8d4;
    }
    if (M2C_FIELD(var_r4, s32 *, 0xBC) == 0) {
        return;
    }
    if ((u32) (func_02049208() - M2C_FIELD(var_r4, s32 *, 0xAC)) < 0x2710U) {
        M2C_FIELD(var_r4, s32 *, 0xB4) = 1;
        return;
    }
    func_0205fbb0(var_r4, 1);
    M2C_FIELD(var_r4, s32 *, 0xB4) = 0;
}

void func_0205eacc(void *p){extern void *data_020ff8d4;extern M2C_UNK data_020ff8d8;void func_020496b8(s32,s32);void func_02049270(s32);void func_020377c4(void *);if(!p)p=data_020ff8d4;if(M2C_FIELD(p,s32 *,0xbc))func_0205fbb0(p,2);if(M2C_FIELD(p,s32 *,0)!=-1 && M2C_FIELD(p,s32 *,0xc4)){func_020496b8(M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,0xc4));}M2C_FIELD(p,s32 *,0)=-1;M2C_FIELD(p,s32 *,0xac)=0;if(M2C_FIELD(p,s32 *,0xc4))func_02049270(M2C_FIELD(p,s32 *,0xc4));if(p==&data_020ff8d8)return;func_020377c4(p);}

void func_0205eb50(u8 *p,s32 a){s32 n=M2C_FIELD(p,s32 *,0x100);if(n>=254)goto end;if(a<1)goto end;if(a>254)goto end;M2C_FIELD(p,s32 *,0x100)=n+1;p[n]=a;end:return;}

void func_0205eb7c(void *a,M2C_UNK b){M2C_UNK func_0205ebb0(void *,M2C_UNK *);void func_020675e4(void *,void *,M2C_UNK,...);extern M2C_UNK data_020ffa40;u8 buf[20];func_020675e4(buf,&data_020ffa40,b);func_0205ebb0(a,(M2C_UNK *)buf);}

M2C_UNK func_0205ebb0(void *a,M2C_UNK *b){s32 func_02068c34(void *);void func_020651a4(void *,void *,s32);s32 n=func_02068c34(b)+1;s32 used=M2C_FIELD(a,s32 *,0x800);if(n>0x800-used)n=0x800-used;if(!n)return;func_020651a4((u8 *)a+used,b,n);M2C_FIELD(a,s32 *,0x800)+=n;((u8 *)a)[M2C_FIELD(a,s32 *,0x800)-1]=0;}

void func_0205ec0c(void){void *func_02049584(void);void *p=func_02049584();s32 i;u8 *s;u8 x,y;if(!p)return;data_0213e358=0;for(i=0;i<5;){s=M2C_FIELD(p,u8 ***,12)[i];if(!s)return;y=s[1];x=s[0];data_0213e35c[i][0]=x;data_0213e35c[i][1]=y;y=s[3];x=s[2];data_0213e35c[i][2]=x;data_0213e35c[i][3]=y;data_0213e358=++i;}}

s32 func_0205ec80(s32 a,s32 b,void *c,void **d){s32 func_020498e4(s32);s32 func_02068d98(s32,void *);void *func_02021768(s32);u16 v=b;void *p=0;M2C_FIELD(c,u8 *,1)=2;M2C_FIELD(c,u16 *,2)=((u8)(v>>8))|((v<<8)&0xff00);if(!a)M2C_FIELD(c,s32 *,4)=0;else M2C_FIELD(c,s32 *,4)=func_020498e4(a);if(M2C_FIELD(c,s32 *,4)==-1&&func_02068d98(a,data_020ffa44)){p=func_02021768(a);if(!p)return 0;M2C_FIELD(c,s32 *,4)=**M2C_FIELD(p,s32 ***,12);}if(d)*d=p;return 1;}

void func_0205ed28(u8 *arg0, u8 *arg1) {
    u8 temp_r3;

    temp_r3 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_r3;
}

u8 func_0205ed3c(u32 a){if(a<26)return a+65;if(a<52)return a+71;if(a<62)return a-4;if(a==62)return 43;if(a==63)return 47;return 0;}

void func_0205ed84(void *src_void, s32 count, void *dst_void) {
    u8 *src = (u8 *) src_void;
    u8 *dst = (u8 *) dst_void;
    u8 buf[3];
    u8 out[4];
    s32 i;
    i = 0;
    if (count <= 0) goto end;
    for (;;) {
        s32 j;
        for (j = 0; j < 3; j++) {
            if (i < count) {
                buf[j] = *src++;
            } else {
                buf[j] = (u8) j;
            }
            i++;
        }
        out[0] = (u8) (buf[0] >> 2);
        out[1] = (u8) (((buf[0] & 3) << 4) | (buf[1] >> 4));
        out[2] = (u8) (((buf[1] & 0x0f) << 2) | (buf[2] >> 6));
        out[3] = (u8) (buf[2] & 0x3f);
        for (j = 0; j < 4; j++) {
            *dst++ = func_0205ed3c(out[j]);
        }
        if (i >= count) break;
    }
end:
    *dst = 0;
}

void func_0205ee48(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    unsigned long long func_020720f0(s32, s32);
    u8 S[256];
    u8 *key;
    u8 *data;
    s32 keyLen;
    s32 dataLen;
    s16 i;
    u8 j;
    u8 idx;
    u8 k;
    u8 t;
    u8 *p;

    key = (u8 *)arg0;
    data = (u8 *)arg2;
    keyLen = arg1;
    dataLen = arg3;

    for (i = 0; i < 256; i++) {
        S[i] = (u8)i;
    }

    idx = 0;
    j = 0;
    p = S;
    for (i = 0; i < 256; i++) {
        j = (u8)((j + *p + key[idx]) % 256);
        idx = (u8)(func_020720f0(idx + 1, keyLen) >> 32);
        func_0205ed28(p, S + j);
        p++;
    }

    if (dataLen <= 0) {
        return;
    }
    j = 0;
    k = 0;
    for (i = 0; i < dataLen; ) {
        j = (u8)((j + data[i] + 1) % 256);
        k = (u8)((k + S[j]) % 256);
        func_0205ed28(S + j, S + k);
        t = (u8)((S[j] + S[k]) % 256);
        data[i] = (u8)(data[i] ^ S[t]);
        i++;
    }
}

void func_0205ef8c(u8 *a,s8 b,ByteQuad *c){a[0]=b;*(ByteQuad *)(a+1)=*c;M2C_FIELD(a,s32 *,0x800)=5;}

void func_0205efbc(void *a,void *b,s8 *p,s32 n) {
 void func_02068c50(void *,void *);
 s32 func_02068c34(void *);
 void func_0205ee48(void *,s32,void *,s32);
 void func_0205ed84(void *,s32,void *);
 s8 buf[65];
 if(n<1)return;
 if(n>65)return;
 if(p[n-1])return;
 func_02068c50(buf,p);
 func_0205ee48((u8 *)a+68,func_02068c34((u8 *)a+68),buf,n-1);
 func_0205ed84(buf,n-1,(u8 *)b+M2C_FIELD(b,s32 *,0x800));
 M2C_FIELD(b,s32 *,0x800)+=func_02068c34((u8 *)b+M2C_FIELD(b,s32 *,0x800))+1;
}

void func_0205f05c(void *arg0,M2C_UNK arg1) {
 M2C_UNK func_02068adc(M2C_UNK,M2C_UNK *,u32 *,s32 *);
 extern M2C_UNK data_020ffa54;
 u32 sp4; s32 sp0; u16 port; u32 address;
 func_02068adc(arg1,&data_020ffa54,&sp4,&sp0);
 port=sp0;
 address=((sp4<<24)&0xff000000)|(((sp4<<8)&0xff0000)|((u8)(sp4>>24)|((sp4>>8)&0xff00)));
 sp4=address;
 if(address && port) {
 if(M2C_FIELD(arg0,u32 *,0x104)==address && M2C_FIELD(arg0,u16 *,0x108)==port)return;
 M2C_FIELD(arg0,u32 *,0x104)=address;
 M2C_FIELD(arg0,u16 *,0x108)=port;
 M2C_FIELD(arg0,M2C_UNK (**)(u32,u16,s32),0xa8)(sp4,port,M2C_FIELD(arg0,s32 *,0x10c));
 }
}

M2C_UNK func_0205f10c(M2C_UNK a0, M2C_UNK a1, M2C_UNK a2, s32 a3, s32 a4) { (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; return 0; }

void func_0205f364(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    M2C_UNK func_0205f10c(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_0205f10c(arg0, arg1, 0, arg2, arg3);
    func_0205f10c(arg0, arg1, 1, arg4, arg5);
    func_0205f10c(arg0, arg1, 2, arg6, arg7);
}

void func_0205f3bc(M2C_UNK a,M2C_UNK b,u8 *p,s32 n) {
 s32 x,y,z; s32 q=0,r=0,s=0;
 if(n<3)return;
 x=*p++;n--;
 if(x && x!=255){q=(s32)p;n-=x;p+=x;}
 if(n<2)return;
 y=*p++;n--;
 if(y && y!=255){r=(s32)p;n-=y;p+=y;}
 if(n<1)return;
 z=*p;n--;
 if(z && z!=255){n-=z;s=(s32)(p+1);}
 if(n<0)return;
 func_0205f364(a,b,x,q,y,r,z,s);
}

void func_0205f474(M2C_UNK arg0, void *arg1, M2C_UNK arg2) {
    u8 x = data_020eac30[4];
    (void)x;
    (void)arg0; (void)arg1; (void)arg2;
    return;
}

void func_0205f64c(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_0205ebb0(void *, M2C_UNK *);
                      void func_0205f474(M2C_UNK, void *, M2C_UNK);
    extern M2C_UNK data_020ffa74;
    M2C_FIELD(arg1, s32 *, 0x800) = 1;
    M2C_FIELD(arg1, s8 *, 0) = 0x5C;
    func_0205f474(arg0, arg1, 0);
    func_0205f474(arg0, arg1, 1);
    func_0205f474(arg0, arg1, 2);
    func_0205ebb0(arg1, &data_020ffa74);
    M2C_FIELD(arg1, s32 *, 0x800) = (s32) (M2C_FIELD(arg1, s32 *, 0x800) - 1);
}

void func_0205f6b0(void *arg0, void *arg1, s32 arg2) {
    u8 buf[4];
    u8 key[6];
    s32 i;
    s32 match;
    u32 val;
    u32 tmp;
    M2C_UNK (*cb0)(M2C_UNK, M2C_UNK);
    M2C_UNK (*cb4)(M2C_UNK, M2C_UNK, M2C_UNK);

    key[0] = data_020eac30[0];
    key[1] = data_020eac30[1];
    key[2] = data_020eac30[2];
    key[3] = data_020eac30[3];
    key[4] = data_020eac30[4];
    key[5] = data_020eac30[5];

    match = 1;
    if (arg2 < 10) {
        match = 0;
    } else {
        for (i = 0; i < 6; i++) {
            if (key[i] != ((u8 *)arg1)[i]) {
                match = 0;
                break;
            }
        }
    }

    if (!match) goto no_match;

    buf[0] = ((u8 *)arg1)[6];
    buf[1] = ((u8 *)arg1)[7];
    buf[2] = ((u8 *)arg1)[8];
    buf[3] = ((u8 *)arg1)[9];

    tmp = *(u32 *)buf;
    val = ((tmp >> 24) & 0xFFU) |
          ((tmp >> 8) & 0xFF00U) |
          ((tmp << 8) & 0xFF0000U) |
          ((tmp << 24) & 0xFF000000U);

    cb0 = M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK), 0xa0);
    if (cb0 != NULL) {
        cb0(val, M2C_FIELD(arg0, M2C_UNK *, 0x10c));
    }
    return;

no_match:
    cb4 = M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK), 0xa4);
    if (cb4 != NULL) {
        cb4(arg1, arg2, M2C_FIELD(arg0, M2C_UNK *, 0x10c));
    }
}

s32 func_0205f7d8(void *a,s32 b) {
 s32 i=0;
loop:
 if(M2C_FIELD((u8 *)a+((u32)i<<2),s32 *,0xd8)==b)return 1;
 i++;
 if(i<10)goto loop;
 M2C_FIELD(a,s32 *,0x100)=(M2C_FIELD(a,s32 *,0x100)+1)%10;
 i=M2C_FIELD(a,s32 *,0x100);
 M2C_FIELD(a,s32 *,0x100)=i;
 M2C_FIELD((u8 *)a+((u32)i<<2),s32 *,0xd8)=b;
 return 0;
}

