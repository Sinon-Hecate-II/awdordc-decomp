/* 3 functions from 0x0220ED80 to 0x0220F0B8 (ov003), found by ds-decomp. */
#include "common.h"

void MemFree(void *arg0);
void MemFreeArray(void *arg0);
void HeapFreeBlock(void *arg0);
void DeleteSpriteObject(void *arg0);
void func_020af71c(void);
typedef void (*VFn)(void *);
static inline void RestoreByte(void *p,u8 v) { M2C_FIELD(p,u8 *,15)=v; }
static inline void RestoreBits12(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0x3000)|((x&3)<<12); }
static inline void RestoreBits10(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0xc00)|((x&3)<<10); }
static inline void RestoreBit14(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0x4000)|((x&1)<<14); }
/* Non-deleting destructor of the ov003 map-select screen: restores the
 * palette entries it patched and releases every widget, animation and buffer
 * it owns, leaving the screen object itself to the caller. */
void *MapSelectScreen_Destroy(void *arg0) {
    extern M2C_UNK gMapSelectVTable;
    extern u8 data_0215d9b8[8];
    void *self = arg0;
    u32 mode;
    u8 isMode1;
    s32 i;
    void *obj;

    M2C_FIELD(self, M2C_UNK **, 0) = &gMapSelectVTable;

    mode = (((u32)M2C_FIELD(self, u8 *, 0x36) << 24) >> 28);
    isMode1 = (mode == 1);
    if (isMode1) {
        void *bounds = M2C_FIELD(self, void **, 0x40);
RestoreBits12(M2C_FIELD(bounds,u32 *,4)); RestoreBits10(M2C_FIELD(bounds,u32 *,0x1c)); RestoreBit14(M2C_FIELD(bounds,u32 *,0x34));
    }

    mode = (((u32)M2C_FIELD(self, u8 *, 0x36) << 24) >> 28);
    isMode1 = (mode == 1);
    if (isMode1 || (u8)(mode == 2)) {
            void *palette = M2C_FIELD(self, void **, 0x3C);
            u8 index;
            M2C_FIELD(M2C_FIELD(self,void **,0x3c),u8 *,15)=M2C_FIELD(self,u8 *,0x39);
            palette = M2C_FIELD(self, void **, 0x3C);
            index = M2C_FIELD(palette, u8 *, 0xF);
            M2C_FIELD(palette, u8 *, index) = M2C_FIELD(self, u8 *, 0x3A);
    }

{void *child=M2C_FIELD(M2C_FIELD(self,void **,0x4c),void **,0x18); if(child) { if(M2C_FIELD(child,void **,0)) MemFree(M2C_FIELD(child,void **,0)); MemFree(child); } }
{void *child=M2C_FIELD(M2C_FIELD(self,void **,0x4c),void **,0x1c); if(child) { if(M2C_FIELD(child,void **,0)) MemFree(M2C_FIELD(child,void **,0)); MemFree(child); } }
obj=M2C_FIELD(self,void **,0x4c); if(obj) MemFree(obj);
for(i=0;i<6;i++) {
{void *child=M2C_FIELD((u8 *)M2C_FIELD(self,void **,0x48)+i*0x24,void **,24); if(child) { if(M2C_FIELD(child,void **,0)) MemFree(M2C_FIELD(child,void **,0)); MemFree(child); } }
{void *child=M2C_FIELD((u8 *)M2C_FIELD(self,void **,0x48)+i*0x24,void **,28); if(child) { if(M2C_FIELD(child,void **,0)) MemFree(M2C_FIELD(child,void **,0)); MemFree(child); } }
{void *child=M2C_FIELD((u8 *)M2C_FIELD(self,void **,0x48)+i*0x24,void **,32); if(child) { if(M2C_FIELD(child,void **,0)) MemFree(M2C_FIELD(child,void **,0)); MemFree(child); } }
} MemFreeArray(M2C_FIELD(self,void **,0x48));
    obj = M2C_FIELD(self, void **, 0x50);
    if (obj != NULL) MemFree(obj);

    obj = M2C_FIELD(self, void **, 0x54);
    if (obj != NULL) MemFree(obj);

    obj = M2C_FIELD(self, void **, 0x58);
    if (obj != NULL) MemFree(obj);

    obj = M2C_FIELD(self, void **, 0x5C);
    if (obj != NULL) {
        void *buffer = M2C_FIELD(obj, void **, 0x14);
        HeapFreeBlock(buffer);
        MemFree(obj);
    }

    obj = M2C_FIELD(self, void **, 0x60);
    if (obj != NULL) {
        VFn *vt = M2C_FIELD(obj, VFn **, 0);
        vt[1](obj);
    }

    obj = M2C_FIELD(self, void **, 0x64);
    if (obj != NULL) {
        VFn *vt = M2C_FIELD(obj, VFn **, 0);
        vt[1](obj);
    }

    obj = M2C_FIELD(self, void **, 0x68);
    if (obj != NULL) {
{void *child=M2C_FIELD(obj,void **,0);if(child)DeleteSpriteObject(child);}
{void *child=M2C_FIELD(obj,void **,4);if(child)DeleteSpriteObject(child);}
{void *child=M2C_FIELD(obj,void **,8);if(child)DeleteSpriteObject(child);}
{void *child=M2C_FIELD(obj,void **,12);if(child)DeleteSpriteObject(child);}
{void *child=M2C_FIELD(obj,void **,16);if(child)DeleteSpriteObject(child);}
{void *child=M2C_FIELD(obj,void **,20);if(child)DeleteSpriteObject(child);}
        MemFree(obj);
    }

    obj = M2C_FIELD(self, void **, 0x40);
    if (obj != NULL) MemFree(obj);

    func_020af71c();
    return self;
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
