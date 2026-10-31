/* 3 functions from 0x0220ED80 to 0x0220F0B8 (ov003), found by ds-decomp. */
#include "common.h"

void func_02082040(void *arg0);
void func_0208204c(void *arg0);
void func_020e35cc(void *arg0);
void func_01ffa574(void *arg0);
void func_020af71c(void);
typedef void (*VFn)(void *);
static inline void RestoreByte(void *p,u8 v) { M2C_FIELD(p,u8 *,15)=v; }
static inline void RestoreBits12(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0x3000)|((x&3)<<12); }
static inline void RestoreBits10(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0xc00)|((x&3)<<10); }
static inline void RestoreBit14(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0x4000)|((x&1)<<14); }
void *func_ov003_0220ed80(void *arg0) {
    extern M2C_UNK data_ov003_02211060;
    extern u8 data_0215d9b8[8];
    void *r6 = arg0;
    u32 h;
    u8 cond;
    s32 i;
    void *p;

    M2C_FIELD(r6, M2C_UNK **, 0) = &data_ov003_02211060;

    h = (((u32)M2C_FIELD(r6, u8 *, 0x36) << 24) >> 28);
    cond = (h == 1);
    if (cond) {
        void *s = M2C_FIELD(r6, void **, 0x40);
RestoreBits12(M2C_FIELD(s,u32 *,4)); RestoreBits10(M2C_FIELD(s,u32 *,0x1c)); RestoreBit14(M2C_FIELD(s,u32 *,0x34));
    }

    h = (((u32)M2C_FIELD(r6, u8 *, 0x36) << 24) >> 28);
    cond = (h == 1);
    if (cond || (u8)(h == 2)) {
            void *s = M2C_FIELD(r6, void **, 0x3C);
            u8 v;
            M2C_FIELD(M2C_FIELD(r6,void **,0x3c),u8 *,15)=M2C_FIELD(r6,u8 *,0x39);
            s = M2C_FIELD(r6, void **, 0x3C);
            v = M2C_FIELD(s, u8 *, 0xF);
            M2C_FIELD(s, u8 *, v) = M2C_FIELD(r6, u8 *, 0x3A);
    }

{void *q=M2C_FIELD(M2C_FIELD(r6,void **,0x4c),void **,0x18); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
{void *q=M2C_FIELD(M2C_FIELD(r6,void **,0x4c),void **,0x1c); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
p=M2C_FIELD(r6,void **,0x4c); if(p) func_02082040(p);
for(i=0;i<6;i++) {
{void *q=M2C_FIELD((u8 *)M2C_FIELD(r6,void **,0x48)+i*0x24,void **,24); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
{void *q=M2C_FIELD((u8 *)M2C_FIELD(r6,void **,0x48)+i*0x24,void **,28); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
{void *q=M2C_FIELD((u8 *)M2C_FIELD(r6,void **,0x48)+i*0x24,void **,32); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
} func_0208204c(M2C_FIELD(r6,void **,0x48));
    p = M2C_FIELD(r6, void **, 0x50);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x54);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x58);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x5C);
    if (p != NULL) {
        void *q = M2C_FIELD(p, void **, 0x14);
        func_020e35cc(q);
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x60);
    if (p != NULL) {
        VFn *vt = M2C_FIELD(p, VFn **, 0);
        vt[1](p);
    }

    p = M2C_FIELD(r6, void **, 0x64);
    if (p != NULL) {
        VFn *vt = M2C_FIELD(p, VFn **, 0);
        vt[1](p);
    }

    p = M2C_FIELD(r6, void **, 0x68);
    if (p != NULL) {
{void *q=M2C_FIELD(p,void **,0);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,4);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,8);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,12);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,16);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,20);if(q)func_01ffa574(q);}
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x40);
    if (p != NULL) func_02082040(p);

    func_020af71c();
    return r6;
}

void *func_ov003_0220f080(void *arg0) {
    extern M2C_UNK data_ov003_02211028;
    void **temp_r0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_02211028;
    temp_r0 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    return arg0;
}

void func_ov003_0220f0b4(void) {

}
