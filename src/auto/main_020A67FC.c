/* 34 functions from 0x020A67FC to 0x020A7738 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 value:8; u32 rest:24; } Bits020a8c10;
#include "ov000_unit_entry.h"
static inline s32 unitHealth7074(UnkStruct_ov000_021A860C *p) { s32 func_0207c8ec(s32,s32);s32 h=p->unk6;if(h==0)return 0;return func_0207c8ec(h-1,10)+1; }
extern u8 data_ov000_021b5c6a[], data_ov000_021b5c5e[],data_ov000_021b5c5c[],data_ov000_021b5c5d[];
extern void **gCurrentMap;

s32 func_020a67fc(s32 a,s32 b,s32 c){s32 func_020d2d18(u16,s32);s32 func_020a6658(s32,s32,s32);void func_020d2b10(u16,s32);s32 func_020d19b4(u16);void func_02091c20(s32,s32);void func_020cfd28(void);s32 r,cost;register s32 id;register void *p;cost=func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),c)*10;p=*gCurrentMap;id=M2C_FIELD(p,u16 *,0x52a4);if(M2C_FIELD((u8 *)p+(u32)id*140,s32 *,0x67a4)<cost)return 0;r=func_020a6658(a,b,c);if(!r)return 0;func_020d2b10(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),cost);if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))func_02091c20(c+40,1);func_020cfd28();return r;}

void func_020a68d4(void) {
    extern void **gCurrentMap;
    s32 i;
    s32 offset;
    void *p;
    i = 0;
    offset = 0;
    do {
        i++;
        p = (u8 *)*gCurrentMap + 0x59A4;
        M2C_FIELD(p, u8 *, offset) &= ~0x3F;
        offset += 14;
    } while (i < 256);
    M2C_FIELD(*gCurrentMap, u16 *, 0x52C0) = 0;
    M2C_FIELD(*gCurrentMap, u8 *, 0x52D4) = 0;
    M2C_FIELD(*gCurrentMap, s32 *, 0x52D0) = 0;
}

void func_020a694c(void) {

}

void func_020a6950(s32 arg0, s32 arg1) {
    extern void **gCurrentMap;
    void *base;
    void *p;
    if (arg0 >= 0 && arg1 >= 0) {
        base = *gCurrentMap;
        if (arg0 < M2C_FIELD(base, u16 *, 0x5144) && arg1 < M2C_FIELD(base, u16 *, 0x5146)) {
            p = (u8 *)base + 0x59A4 + M2C_FIELD(base, u8 *, arg0 + M2C_FIELD((u8 *)base + arg1 * 2, u16 *, 0x3758)) * 14;
            if (p != 0) M2C_FIELD(p, u16 *, 4) |= 0x8000;
        }
    }
}

void func_020a6b50(void *arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(temp_r2, u8 *, 1);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(temp_r2, u8 *, 2);
}

void func_020a6b68(void *arg0) {
    M2C_UNK func_020a7f48(M2C_UNK, s32, s32, M2C_UNK);
    M2C_UNK func_020b576c(s32);
    func_020b576c(M2C_FIELD(arg0, s32 *, 0x54));
    func_020a7f48(0, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 2);
}

void func_020a6b90(void *arg0) {
    extern void **gCurrentMap;
    s32 func_020b5258(void);
    void func_01ffa6fc(void *);
    void (*callback)(s32, s32, s32);
    callback = (void (*)(s32, s32, s32))M2C_FIELD(gCurrentMap[1], void **, 8);
    if (callback != 0) callback(M2C_FIELD(arg0, s32 *, 0x34) * 16, M2C_FIELD(arg0, s32 *, 0x38) * 16, 10);
    if (func_020b5258() != 0) return;
    func_01ffa6fc(arg0);
}

void func_020a6be4(s32 arg0) {
    void *func_01ffa42c(M2C_UNK *);
    extern M2C_UNK data_02120670;
    M2C_FIELD(func_01ffa42c(&data_02120670), s32 *, 0x54) = arg0;
}

void func_020a6c00(void *p){u8 *func_020e34bc(s32);u8 *bits;s32 x; s32 y; s32 base; u32 pos;M2C_FIELD(p,s32 *,0x5c)=1;M2C_FIELD(p,s32 *,0x60)=1;bits=func_020e34bc(0xa1);M2C_FIELD(p,u8 **,0x54)=bits;base=*gCurrentMap;for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){pos=x+M2C_FIELD((base+((u32)y<<1)),u16 *,0x3758);bits[pos>>3]&=((1<<(pos&7)) ^ -1);base=*gCurrentMap;}}}

void func_020a6cbc(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x54));
}

void func_020a6eb0(void){
extern u16 data_ov000_021aeef4[];s32 func_020a85dc(u32);
s32 i;UnkStruct_ov000_021A860C *p;u8 n;
for(i=data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++){
p=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
if(p->unk0 && !(M2C_FIELD(p,u16 *,4)&8)){
M2C_FIELD(p,u16 *,4)&=~0x81;
if(func_020a85dc(p->unk0)){
n=p->unkC[0];
if(n)M2C_FIELD(&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[n],u16 *,4)&=~1;
n=p->unkC[1];
if(n)M2C_FIELD(&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[n],u16 *,4)&=~1;
}
}
}}

void func_020a6fcc(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021206a0;
    func_01ffa3dc(&data_021206a0, 7);
}

s32 func_020a6fe4(u8 *p,s32 n){s32 type,index,enabled;index=((u32)(p[0]<<26)>>26)*0x70;type=data_ov000_021b5c5c[index];enabled=((u8 *)((s32)data_ov000_021b5c5e+n*0x70))[data_ov000_021b5c5d[index]];if(!type)return 0;if(!enabled)return 0;if(type==2&&p[13])return 0;if(type==1&&p[12])return 0;return 1;}

s32 func_020a7074(UnkStruct_ov000_021A860C *a,UnkStruct_ov000_021A860C *b){
s32 func_0207c8ec(s32,s32);s32 func_020a7cfc(void *);
s32 x,y,h;
if(a->unk0!=b->unk0)return 0;
if(b)x=((u8 *)b-((u8 *)*gCurrentMap+0x59a4))/14;else x=0;
if(a)y=((u8 *)a-((u8 *)*gCurrentMap+0x59a4))/14;else y=0;
if((y&0xc0)!=(x&0xc0))return 0;
if(a->unkC[0]||b->unkC[0])return 0;
h=unitHealth7074(b);
if(h==10)return 0;
if(func_020a7cfc(a)&&func_020a7cfc(b))return 0;
return 1;
}

void func_020a71a0(s32 x,s32 y,s32 amount) {
s32 func_020a8560(u32);
void *base;
u8 *p;
u32 type; s16 n;
if(x<0 || y<0)return;
base=*gCurrentMap;
if(x>=M2C_FIELD(base,u16 *,0x5144) || y>=M2C_FIELD(base,u16 *,0x5146))return;
p=(u8 *)base+0x59a4+(s16)M2C_FIELD((u8 *)base+(x+M2C_FIELD((u8 *)base+y*2,u16 *,0x3758)),u8 *,0x508)*(s16)14;
type=(u32)(p[0]<<26)>>26;
if(!type)return;
if(M2C_FIELD(p,u16 *,4)&8)return;
if(func_020a8560(type))return;
n=((UnkStruct_ov000_021A860C *)p)->unk6;
if(amount+1>n) ((UnkStruct_ov000_021A860C *)p)->unk6=1;
else ((UnkStruct_ov000_021A860C *)p)->unk6=(u16)(n-amount);
}

M2C_UNK *func_020a7278(void) {
    extern M2C_UNK data_02121e08;
    return &data_02121e08;
}

M2C_UNK *func_020a7284(void) {
    extern M2C_UNK data_02121020;
    return &data_02121020;
}

s32 func_020a7290(void) {
    return 0x78;
}

s32 func_020a7298(s32 a,u8 b){return ((u8 *)b)[(s32)data_ov000_021b5c6a+a*0x70];}

s32 func_020a72b0(s32 arg0, M2C_UNK arg1) {
    s32 func_020a7298(M2C_UNK, u8);
    extern void **gCurrentMap;
    return func_020a7298(arg1, M2C_FIELD(((arg0 * 0x8C) + (s32)*gCurrentMap), u8 *, 0x67CD)) * 4;
}

void *func_020a72e8(s32 arg0) {
    extern M2C_UNK data_02120a20;
    return (u8 *)&data_02120a20 + ((arg0 - 1) << 5);
}

s32 func_020a72fc(s32 arg0, s32 arg1) {
    s32 var_r0;

    var_r0 = arg0;
    if (arg1 == 0) {
        return var_r0;
    }
    if (var_r0 == 0x16) {
        var_r0 = 0x1B;
    }
    return var_r0;
}

s32 func_020a7310(p) void *p;{s32 n;if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;return (n>>6)+1;}

u32 func_020a735c(u8 *arg0) {
    return (u32) (*arg0 << 0x1A) >> 0x1A;
}

s32 func_020a736c(u8 *p,s32 x,s32 y){
s32 func_020a8560(u32);s32 func_020a881c(s32);s32 func_020a87ec(void *);s32 func_020a25d8(void *,s32,s32);
s32 sum=0,n;
if(func_020a8560((u32)(p[0]<<26)>>26))return sum;
if(p){if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
sum+=func_020a881c(n);
if(p){if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
if(((Bits020a8c10 *)((u8 *)*gCurrentMap+n*140+0x6810))->value!=10){
if(M2C_FIELD(*gCurrentMap,u8 *,0x5158)==3)sum-=30;
}
sum+=func_020a87ec(p);
return sum+func_020a25d8(p,x,y);
}

s32 func_020a74a8(u8 *p,s32 a,s32 b){s32 func_020a8560(u32);s32 func_020a8844(s32);s32 func_020a8804(void *);s32 func_020a2608(void *,s32,s32);s32 result=0,n;if(func_020a8560((u32)(p[0]<<26)>>26))return result;if(p){if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;result+=func_020a8844(n);result+=func_020a8804(p);return result+func_020a2608(p,a,b);}

s32 func_020a7558(void) {
    M2C_UNK func_020a7310();
    func_020a7310();
    return 2;
}

s32 func_020a7568(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 func_020a2638(void *, M2C_UNK, M2C_UNK);
    s32 var_r4;
    u32 temp_r0;

    func_020a7310();
    temp_r0 = (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
    if (temp_r0 == 0) {
        var_r4 = 0;
    } else {
        var_r4 = func_0207c8ec(temp_r0 - 1, 0xA) + 1;
    }
    return var_r4 + func_020a2638(arg0, arg1, arg2);
}

s32 func_020a75b8(void *arg0) {
s32 func_020a7b24(u32);
s32 func_020a2698(void *,u8,u8);
u8 *p=arg0;
s32 cap,bonus,n,penalty;
func_020a7310(p);
cap=func_020a7b24((u32)(p[0]<<26)>>26);
bonus=func_020a2698(p,p[1],p[2]);
penalty=0;
if(p) {
if(!p)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;
n=(n>>6)+1;
}else n=0;
if(((Bits020a8c10 *)((u8 *)*gCurrentMap+n*140+0x6810))->value!=10)
penalty=-(M2C_FIELD(*gCurrentMap,u8 *,0x5158)==1);
return penalty+(cap+bonus);
}

s32 func_020a7694(void *p){s32 func_020a75b8(void *);s32 func_020a86f0(s32);s32 func_0207c8ec(s32,s32);s32 cap,v;u32 n;n=(u32)(M2C_FIELD(p,u8 *,10)<<25)>>25;cap=func_020a75b8(p);v=func_0207c8ec(n,func_020a86f0(func_020a7310(p)));if(v>=cap)v=cap;return v;}

s32 func_020a76d4(u8 *p){s32 func_020a7bd4(s32);s32 func_020a26c8(void *,u8,u8);s32 cap,v;func_020a7310(p);cap=func_020a7bd4((u32)(p[0]<<26)>>26);v=func_020a26c8(p,p[1],p[2]);if(cap>=2)cap+=v;return cap;}

s32 func_020a7714(void *arg0) {
    s32 func_020a26c8(void *, u8, u8);
    func_020a7310();
    return func_020a26c8(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2)) + 5;
}

