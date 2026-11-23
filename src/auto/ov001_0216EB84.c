/* 16 functions from 0x0216EB84 to 0x0216FB7C (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
extern u8 data_ov001_0218ca48[8];
extern u8 *gWhPacketInfo;
extern u32 gWhState[21];
extern u8 gWhMacAddress[8], gWhPacket[8];

#pragma thumb on
s32 WhPacket_Wrap(void *a,s32 b,void *c,s32 d,s32 e){u8 *base=(u8 *)((s32)a+6);u8 *end;u8 *p; s32 bb=b;u32 sum=0;M2C_FIELD(c,u8 *,0)=0;M2C_FIELD(c,u8 *,1)=0;M2C_FIELD(c,u8 *,2)=0;M2C_FIELD(c,u8 *,3)=0;M2C_FIELD(c,u8 *,4)=0;M2C_FIELD(c,u8 *,5)=0;M2C_FIELD(c,u8 *,6)=0;M2C_FIELD(c,u8 *,7)=0;M2C_FIELD(c,u16 *,0)=((u8)((s32)(u16)(d-8)>>8)|(((u16)(d-8)<<8)&0xff00));if(e){func_ov001_0216f7c4((u8 *)a+6,c,d,e,16);d+=8;}else MemCopy((u8 *)a+6,c,d);M2C_FIELD(a,u8 *,0)=0;M2C_FIELD(a,u8 *,1)=0;M2C_FIELD(a,u8 *,2)=0;M2C_FIELD(a,u8 *,3)=0;M2C_FIELD(a,u8 *,4)=0;M2C_FIELD(a,u8 *,5)=0;M2C_FIELD(a,u16 *,0)=((u8)((s32)(u16)(bb)>>8)|(((u16)(bb)<<8)&0xff00));M2C_FIELD(a,u16 *,2)=((u8)((s32)(u16)(d)>>8)|(((u16)(d)<<8)&0xff00));end=base+d;for(p=(u8*)a;p<end;p++)sum+=*p;M2C_FIELD(end,u16 *,0)=((u8)((s32)(u16)(sum)>>8)|(((u16)(sum)<<8)&0xff00));return (s32)(end+2)- (s32)a;}
/* Append one tagged field to the user-data packet at `field`: a big-endian u16
 * `tag` and byte `length`, then the `length` bytes of `data`, zero-padded to a
 * multiple of 8 bytes.  Returns where the next field starts. */
void *WhPacket_AddField(u8 *field, s32 tag, void *data, s32 length) {
    s32 padBytes;
    u16 value;

    M2C_FIELD(field, u8 *, 0) = 0;
    M2C_FIELD(field, u8 *, 1) = 0;
    M2C_FIELD(field, u8 *, 2) = 0;
    M2C_FIELD(field, u8 *, 3) = 0;
    value = tag;
    M2C_FIELD(field, u16 *, 0) = WH_READ_BE16(value);
    padBytes = ((length + 11) & ~7) - 4;
    value = length;
    M2C_FIELD(field, u16 *, 2) = WH_READ_BE16(value);
    field = (u8 *)((s32)field + 4);
    MemSet(field, 0, padBytes);
    MemCopy(field, data, length);
    return (void *)((s32)field + padBytes);
}

s32 func_ov001_0216eca8(void *a,s32 b,void *c,s32 d){s32 n;M2C_FIELD(a,u8 *,0)=0;M2C_FIELD(a,u8 *,1)=0;M2C_FIELD(a,u8 *,2)=0;M2C_FIELD(a,u8 *,3)=0;M2C_FIELD(a,u8 *,4)=0;M2C_FIELD(a,u8 *,5)=0;M2C_FIELD(a,u8 *,6)=0;M2C_FIELD(a,u8 *,7)=0;n=(u8 *)WhPacket_AddField(a+8,b,c,d)-(u8 *)a;M2C_FIELD(a,u16 *,0)=n-8;return n;}

s32 func_ov001_0216ecd0(void *a,s32 *out){s32 kind,len,tag,size; s32 cursor; volatile s32 b; s32 n,base; u16 x,y,t; u16 *p; base=WhPacket_Unwrap(a,&kind,&len);x=0;y=0;cursor=base;b=0;if(!base)return 0;if(kind!=1)return 0;n=len;cursor=base+8; p=(u16 *)func_ov001_0216eb00(&cursor,n+base,&tag,&size);while(p){switch(tag){case 1:t=*p;x=(u8)((s32)t>>8)|((t<<8)&0xff00);break;case 2:t=*p;b=(u16)((u8)((s32)t>>8)|(0xff00&(t<<8)));break;case 5:t=*p;y=(u8)((s32)t>>8)|((t<<8)&0xff00);break;}p=(u16 *)func_ov001_0216eb00(&cursor,n+base,&tag,&size);}if(x!=1||b!=1)return 0;if((s32)y>=1)*out=1;else *out=0;return 1;}

/* Copy the payload of the packet `packet` to `out` once its type is `type`:
 * decrypt the payload with `key` and drop its trailing 8-byte tag when a key is
 * given, otherwise copy it as is.  Returns the payload length, 0 on failure. */
s32 WhPacket_ExtractPayload(void *packet, s32 type, void *out, void *key) {
    s32 packetType, length;
    void *payload;
    payload = (void *)WhPacket_Unwrap(packet, &packetType, &length);
    if (!payload) return 0;
    if (packetType != type) return 0;
    if (key) {
        WhDecryptPayload(out, payload, length, key, 16);
        length -= 8;
    } else {
        MemCopy(out, payload, length);
    }
    return length;
}

/* Build the WH user-data packet into out: put a u16 1 followed by the 7-byte
 * constant block into a value buffer, write the tagged fields into gWhPacket -
 * fields 1 and 2 with that value, field 5 when the session flag is set, field 3
 * with the constant block, field 4 with the console MAC address when the flag
 * is set - then wrap the packet as type 2. */
void WhBuildUserPacket(void *out) {
    u16 info[5];
    u32 remaining;
    u8 *dst, *src;
    u8 *cursor;
    dst = (u8 *)info;
    info[0] = 0x100;
    src = data_ov001_0218ca48;
    dst += 2;
    remaining = 7;
    do {
        u8 byte = *src;
        src++;
        *dst = byte;
        dst++;
        remaining--;
    } while (remaining != 0);
    cursor = WhPacket_AddField(gWhPacketInfo, 1, info, 2);
    cursor = WhPacket_AddField(cursor, 2, info, 2);
    if (gWhState[20]) cursor = WhPacket_AddField(cursor, 5, info, 2);
    cursor = WhPacket_AddField(cursor, 3, (u8 *)info + 2, 7);
    if (gWhState[20]) cursor = WhPacket_AddField(cursor, 4, gWhMacAddress, 6);
    WhPacket_Wrap(out, 2, gWhPacket, cursor - gWhPacketInfo + WH_PACKET_FIELDS, 0);
}

s32 func_ov001_0216ee90(void){GetMacAddress();return 1;}

/* Decode `length` hex digits from `hex` into bytes in `out`, two digits per byte
 * (high nibble first).  Returns 0 on the first character that is not a hex digit. */
s32 HexToBytes(u8 *out,s8 *hex,s32 length){s32 ch,value,index;value=0;index=value;for(;index<length;index++){ch=hex[index];switch(ch){case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':value+=ch-48;break;case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':value+=ch-87;break;case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':value+=ch-55;break;default:return 0;}if(index%2==0)value<<=4;else{out[index/2]=value;value=0;}}return 1;}

void func_ov001_0216fb34(u8 *a,u8 *b,u8 *c){c[0]=a[0]^b[0];c[1]=a[1]^b[1];c[2]=a[2]^b[2];c[3]=a[3]^b[3];c[4]=a[4]^b[4];c[5]=a[5]^b[5];c[6]=a[6]^b[6];c[7]=a[7]^b[7];}

