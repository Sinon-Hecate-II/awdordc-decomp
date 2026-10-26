/* 152 functions from 0x020D8BB4 to 0x020D9A98 (main), found by ds-decomp. */
#include "common.h"

void func_020d8cc4(void) {

}

void func_020d8cc8(void) {

}

void func_020d8ccc(s16 arg0) {
    extern void **data_027e0058;
    M2C_FIELD(*data_027e0058, s16 *, 0x5142) = arg0;
}

void func_020d8ce8(s32 arg0) {
    extern void *data_0212c36c;
    M2C_FIELD(data_0212c36c, s32 *, 8) = arg0;
}

void func_020d8cfc(void) {

}

u8 func_020d8d00(void) {
    s32 func_01ffa770(void *);
    extern M2C_UNK data_0212c534;
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    u8 var_r0;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (func_01ffa770(&data_0212c534) != 0) var_r0 = 1;
    else var_r0 = 0;
    gCur3DSpriteEngine = temp_r4;
    return var_r0;
}

void func_020d8d48(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffa3dc(void *, s32);
    extern void *data_0212c36c;
    extern M2C_UNK data_0212c534;
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    M2C_FIELD(data_0212c36c, s32 *, 8) = arg1;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    M2C_FIELD(data_0212c36c, s16 *, 0) = 0;
    M2C_FIELD(data_0212c36c, s16 *, 2) = 0;
    M2C_FIELD(data_0212c36c, s16 *, 4) = arg0;
    func_01ffa3dc(&data_0212c534, 8);
    gCur3DSpriteEngine = temp_r4;
}

u8 func_020d8db0(void) {
    s32 func_01ffa770(void *);
    extern void *data_0212c36c;
    extern M2C_UNK data_0212c498;
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    u8 var_r0;
    if (func_020d8d00() == 0) return 0;
    if (M2C_FIELD(data_0212c36c, s16 *, 4) != M2C_FIELD(data_0212c36c, s16 *, 2)) return 1;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (func_01ffa770(&data_0212c498) != 0) var_r0 = 1;
    else var_r0 = 0;
    gCur3DSpriteEngine = temp_r4;
    return var_r0;
}

void func_020d8e28(void){void func_020d932c(void);void func_01ffa9e4(void *);extern void *gCur3DSpriteEngine,*data_027e00c4;extern M2C_UNK data_0212c534;void *p;if(!func_020d8d00())return;p=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;func_020d932c();func_01ffa9e4(&data_0212c534);gCur3DSpriteEngine=p;}

void func_020d8e70(void){s32 func_020d8f1c(s32,s32);extern void *data_0212c36c;extern void *gCur3DSpriteEngine,*data_027e00c4;void *p;if(!func_020d8d00())return;M2C_FIELD(data_0212c36c,s16 *,6)=M2C_FIELD(data_0212c36c,s16 *,2);p=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;func_020d8f1c(3,M2C_FIELD(data_0212c36c,s32 *,8));gCur3DSpriteEngine=p;}

void func_020d8ecc(void){s32 func_020d8f1c(s32,s32);extern void *data_0212c36c;extern void *gCur3DSpriteEngine,*data_027e00c4;void *p;if(!func_020d8d00())return;p=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;func_020d8f1c(M2C_FIELD(data_0212c36c,s16 *,6),M2C_FIELD(data_0212c36c,s32 *,8));gCur3DSpriteEngine=p;}

s32 func_020d8f1c(s32 a,s32 b){extern void *data_0212c36c;if(a==M2C_FIELD(data_0212c36c,s16 *,2))return 0;M2C_FIELD(data_0212c36c,s16 *,4)=a;M2C_FIELD(data_0212c36c,s32 *,8)=b;return 1;}

s32 func_020d8f4c(void){extern void *data_0212c36c;return M2C_FIELD(data_0212c36c,s16 *,2);}

s32 func_020d8f60(void){s32 func_ov000_02174d50(void);s32 func_020adff4(void);extern void *data_0212c36c;switch(M2C_FIELD(data_0212c36c,s16 *,2)){case 1:return func_ov000_02174d50();case 2:return func_020adff4();default:return 0;}}

s32 func_020d8fa0(void){void func_ov000_02174d78(void);void func_020ae068(void);void func_0208fe30(s32);extern void *data_0212c36c;if(!func_020d8f60())return 0;switch(M2C_FIELD(data_0212c36c,s16 *,2)){case 1:func_ov000_02174d78();break;case 2:func_020ae068();break;}func_0208fe30(0x10022);return 1;}

void func_020d8ff8(void) {
    M2C_UNK func_01ffaa0c(s32);
    func_01ffaa0c(0xFF05);
}

void func_020d900c(void) {

}

void func_020d9010(void *a){void func_01ffa8c4(void *,s32);extern void *data_0212c36c;if(M2C_FIELD(data_0212c36c,s16 *,2)==M2C_FIELD(data_0212c36c,s16 *,4))return;func_01ffa8c4(a,2);}

void func_020d903c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212c4c8;
    func_01ffa42c(&data_0212c4c8, arg0);
}

void func_020d9054(s32 a){M2C_UNK func_01ffa42c(M2C_UNK *,M2C_UNK);extern M2C_UNK data_0212c498;extern void *data_0212c36c;M2C_FIELD(data_0212c36c,s16 *,0)=M2C_FIELD(data_0212c36c,s16 *,2);M2C_FIELD(data_0212c36c,s16 *,2)=M2C_FIELD(data_0212c36c,s16 *,4);func_01ffa42c(&data_0212c498,a);}

void func_020d9244(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(0);
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020d9284(void) {
    M2C_UNK func_ov000_02174c2c();
    func_ov000_02174c2c();
}

void func_020d9290(void) {
    M2C_UNK func_ov000_02174c88();
    func_ov000_02174c88();
}

void func_020d929c(void){void func_020ae1e8(s32);extern void *data_0212c36c;func_020ae1e8(M2C_FIELD(data_0212c36c,s32 *,8));}

void func_020d92b8(void) {
    M2C_UNK func_020ae20c();
    func_020ae20c();
}

void func_020d92c4(s32 arg0) {
    M2C_UNK func_020ad348(s32, s32, s32, s32);
    extern void *data_0212c36c;
    if (M2C_FIELD(data_0212c36c, s16 *, 2) == 3) return;
    func_020ad348(0, 8, 1, arg0);
}

void func_020d92f8(s32 arg0) {
    M2C_UNK func_020ad2a0(s32, s32, s32, s32);
    extern void *data_0212c36c;
    if (M2C_FIELD(data_0212c36c, s16 *, 2) == 3) return;
    func_020ad2a0(0, 8, 1, arg0);
}

void func_020d932c(void){M2C_UNK func_01ffa3dc(void *,s32);extern void *data_0212c36c;extern M2C_UNK data_0212c4fc;func_01ffa3dc(*(void **)((u8 *)&data_0212c4fc+M2C_FIELD(data_0212c36c,s16 *,2)*12),8);}

void func_020d9360(s32 arg0) {
M2C_UNK func_01ffa42c(M2C_UNK *,s32);
extern void *data_0212c36c;extern M2C_UNK data_0212c4f8;
func_01ffa42c(*(M2C_UNK **)((u8*)&data_0212c4f8+M2C_FIELD(data_0212c36c,s16 *,2)*12),arg0);
}

void func_020d9394(void) {
    void func_020d8d48(M2C_UNK, M2C_UNK);
    func_020d8d48(1, 0);
}

void func_020d93a8(void) {
extern void *data_0212c36c;
func_020d8d48(M2C_FIELD(data_0212c36c,s16 *,2),M2C_FIELD(data_0212c36c,s32 *,8));
}

void func_020d93c8(void) {
    M2C_UNK func_020da480();
    func_020da480();
}

void func_020d93d4(void) {
    M2C_UNK func_020da7e8();
    func_020da7e8();
}

/* Processes two current-entity slots, creating/updating linked objects for an entity when conditions allow. */
void func_020d93e0(void *entity) {
    s32 func_020846a4(void);
    s32 func_0208477c(void);
    s32 func_02084a6c(void);
    s32 func_0208b5ec(void);
    void func_0208af20(void);
    void *func_0208b564(void *);
    void func_020899cc(void *, s32, s32, u32);
    extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;

    void *savedEntity;
    s32 i;
    void *created;

    if (!func_020846a4()) return;
    if (func_0208477c()) return;
    if (!func_02084a6c()) return;
    M2C_FIELD(entity, u16 *, 0x48) |= 0x1000;
    if (func_0208b5ec()) func_0208af20();
    savedEntity = gCur3DSpriteEngine;
    for (i = 0; i < 2; i++) {
        gCur3DSpriteEngine = (i == 0) ? data_027e00c8 : data_027e00c4;
        if (M2C_FIELD(entity, u8 *, 0x44) == 0 && gCur3DSpriteEngine != data_027e00c8) continue;
        if (M2C_FIELD(entity, u8 *, 0x44) == 1 && gCur3DSpriteEngine != data_027e00c4) continue;
        if (M2C_FIELD(entity, u8 *, 0x44) == 3 && gCur3DSpriteEngine != savedEntity) continue;
        created = func_0208b564(entity);
        func_020899cc(created, 2, M2C_FIELD(entity, u16 *, 0x46) << 5, 0x44000001);
        M2C_FIELD(created, u32 *, 0x58) |= 0x1000;
    }
    gCur3DSpriteEngine = savedEntity;
}

void func_020d94dc(void *arg0) {
M2C_UNK func_01ffa6fc(void *);
void *p=M2C_FIELD(arg0,void **,0x68);
u8 equal=M2C_FIELD(p,u16 *,2)==M2C_FIELD(p,s16 *,12);
if(!equal)return;
func_01ffa6fc(arg0);
}

void func_020d9508(void) {
    M2C_UNK func_020daa9c();
    func_020daa9c();
}

void func_020d9514(void) {
    M2C_UNK func_020daaa8();
    func_020daaa8();
}

void func_020d9520(void) {
    M2C_UNK func_020daab4();
    func_020daab4();
}

void func_020d952c(void) {
    M2C_UNK func_020daac0();
    func_020daac0();
}

void func_020d9538(void) {
    M2C_UNK func_020db140();
    func_020db140();
}

void func_020d9544(void) {
    M2C_UNK func_020db14c();
    func_020db14c();
}

void func_020d9550(void) {
    M2C_UNK func_020db158();
    func_020db158();
}

void func_020d955c(void) {
    M2C_UNK func_020db164();
    func_020db164();
}

void func_020d9568(void) {
    M2C_UNK func_020db170();
    func_020db170();
}

void func_020d9574(void) {
    M2C_UNK func_020db188();
    func_020db188();
}

void func_020d9580(void) {
    M2C_UNK func_020db17c();
    func_020db17c();
}

void func_020d958c(void) {
    M2C_UNK func_020db194();
    func_020db194();
}

void func_020d9598(void) {
    M2C_UNK func_020dbd00();
    func_020dbd00();
}

void func_020d95a4(void) {
    M2C_UNK func_020dbd0c();
    func_020dbd0c();
}

void func_020d95b0(void) {
    M2C_UNK func_020dbd18();
    func_020dbd18();
}

void func_020d95bc(void) {
    M2C_UNK func_020dbd24();
    func_020dbd24();
}

void func_020d95c8(void) {
    M2C_UNK func_020dbd30();
    func_020dbd30();
}

void func_020d95d4(void) {
    M2C_UNK func_020dbd3c();
    func_020dbd3c();
}

void func_020d95e0(void) {
    M2C_UNK func_020dbd48();
    func_020dbd48();
}

void func_020d95ec(void) {
    M2C_UNK func_020dbd54();
    func_020dbd54();
}

void func_020d95f8(void) {
    M2C_UNK func_020dbe74();
    func_020dbe74();
}

void func_020d9604(void) {
    M2C_UNK func_020dbe80();
    func_020dbe80();
}

void func_020d9610(void) {
    M2C_UNK func_020dbe8c();
    func_020dbe8c();
}

void func_020d961c(void) {
    M2C_UNK func_020dbe98();
    func_020dbe98();
}

void func_020d9628(void) {
    M2C_UNK func_020dbea4();
    func_020dbea4();
}

void func_020d9634(void) {
    M2C_UNK func_020dbeb0();
    func_020dbeb0();
}

void func_020d9640(void *arg0) {
    M2C_UNK func_ov009_022241dc();
    if (!(M2C_FIELD(arg0, u16 *, 0x48) & 1)) {
        return;
    }
    func_ov009_022241dc();
}

void func_020d9658(void *arg0) {
    s32 func_ov009_02224284();
    if ((M2C_FIELD(arg0, u16 *, 0x48) & 1) && (func_ov009_02224284() != 0)) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020d9684(void) {
    M2C_UNK func_020dc5e4();
    func_020dc5e4();
}

void func_020d9690(void) {
    M2C_UNK func_020dc5f0();
    func_020dc5f0();
}

void func_020d969c(void) {
    M2C_UNK func_020dc5fc();
    func_020dc5fc();
}

void func_020d96a8(void) {
    M2C_UNK func_020dc608();
    func_020dc608();
}

void func_020d96b4(void) {
    M2C_UNK func_020dca5c();
    func_020dca5c();
}

void func_020d96c0(void) {
    M2C_UNK func_020dca68();
    func_020dca68();
}

void func_020d96cc(void) {
    M2C_UNK func_020dca74();
    func_020dca74();
}

void func_020d96d8(void) {
    M2C_UNK func_020dca80();
    func_020dca80();
}

void func_020d96e4(void) {
    M2C_UNK func_020dcb44();
    func_020dcb44();
}

void func_020d96f0(void) {
    M2C_UNK func_020dcb50();
    func_020dcb50();
}

void func_020d96fc(void) {
    M2C_UNK func_020dcb5c();
    func_020dcb5c();
}

void func_020d9708(void) {
    M2C_UNK func_020dcb68();
    func_020dcb68();
}

void func_020d9714(void) {
    M2C_UNK func_020dd498();
    func_020dd498();
}

void func_020d9720(void) {
    M2C_UNK func_020dd4a4();
    func_020dd4a4();
}

void func_020d972c(void) {
    M2C_UNK func_020dd4b0();
    func_020dd4b0();
}

void func_020d9738(void) {
    M2C_UNK func_020dd4bc();
    func_020dd4bc();
}

void func_020d9744(void) {
    M2C_UNK func_020dd4c8();
    func_020dd4c8();
}

void func_020d9750(void) {
    M2C_UNK func_020dd4d4();
    func_020dd4d4();
}

void func_020d975c(void) {
    M2C_UNK func_020dd4e0();
    func_020dd4e0();
}

void func_020d9768(void) {
    M2C_UNK func_020dd4ec();
    func_020dd4ec();
}

void func_020d9774(void) {
    M2C_UNK func_020dde3c();
    func_020dde3c();
}

void func_020d9780(void) {
    M2C_UNK func_020dde48();
    func_020dde48();
}

void func_020d978c(void) {
    M2C_UNK func_020dde54();
    func_020dde54();
}

void func_020d9798(void) {
    M2C_UNK func_020dde60();
    func_020dde60();
}

void func_020d97a4(void) {
    M2C_UNK func_020dde6c();
    func_020dde6c();
}

void func_020d97b0(void) {
    M2C_UNK func_020dde78();
    func_020dde78();
}

void func_020d97bc(void) {
    M2C_UNK func_020dde84();
    func_020dde84();
}

void func_020d97c8(void) {
    M2C_UNK func_020dde90();
    func_020dde90();
}

void func_020d97d4(void) {
    M2C_UNK func_020ddf78();
    func_020ddf78();
}

void func_020d97e0(void) {
    M2C_UNK func_020ddf84();
    func_020ddf84();
}

void func_020d97ec(void) {
    M2C_UNK func_020ddf90();
    func_020ddf90();
}

void func_020d97f8(void) {
    M2C_UNK func_020ddf9c();
    func_020ddf9c();
}

void func_020d9804(void) {
    M2C_UNK func_020ddfa8();
    func_020ddfa8();
}

void func_020d9810(void) {
    M2C_UNK func_020ddfb4();
    func_020ddfb4();
}

void func_020d981c(void) {
    M2C_UNK func_020ddfc0();
    func_020ddfc0();
}

void func_020d9828(void) {
    M2C_UNK func_020ddfcc();
    func_020ddfcc();
}

void func_020d9834(void) {
    M2C_UNK func_020deb74();
    func_020deb74();
}

void func_020d9840(void) {
    M2C_UNK func_020deb84();
    func_020deb84();
}

void func_020d984c(void) {
    M2C_UNK func_020deb94();
    func_020deb94();
}

void func_020d9858(void) {
    M2C_UNK func_020deba4();
    func_020deba4();
}

void func_020d9864(void) {
    M2C_UNK func_020debb4();
    func_020debb4();
}

void func_020d9870(void) {
    M2C_UNK func_020debc4();
    func_020debc4();
}

void func_020d987c(void) {
    M2C_UNK func_020debd4();
    func_020debd4();
}

void func_020d9888(void) {
    M2C_UNK func_020debe4();
    func_020debe4();
}

void func_020d9894(void) {
    M2C_UNK func_020e0134();
    func_020e0134();
}

void func_020d98a0(void) {
    M2C_UNK func_020e0140();
    func_020e0140();
}

void func_020d98ac(void) {
    M2C_UNK func_020e014c();
    func_020e014c();
}

void func_020d98b8(void) {
    M2C_UNK func_020e0158();
    func_020e0158();
}

void func_020d98c4(void) {
    M2C_UNK func_020e0164();
    func_020e0164();
}

void func_020d98d0(void) {
    M2C_UNK func_020e0170();
    func_020e0170();
}

void func_020d98dc(void) {
    M2C_UNK func_020e017c();
    func_020e017c();
}

void func_020d98e8(void) {
    M2C_UNK func_020e0188();
    func_020e0188();
}

void func_020d98f4(void) {
    M2C_UNK func_020e035c();
    func_020e035c();
}

void func_020d9900(void) {
    M2C_UNK func_020e0368();
    func_020e0368();
}

void func_020d990c(void) {
    M2C_UNK func_020e0374();
    func_020e0374();
}

void func_020d9918(void) {
    M2C_UNK func_020e03ac();
    func_020e03ac();
}

void func_020d9924(void) {
    M2C_UNK func_020e03b8();
    func_020e03b8();
}

void func_020d9930(void) {
    M2C_UNK func_020e0468();
    func_020e0468();
}

void func_020d993c(void) {
    M2C_UNK func_020e0474();
    func_020e0474();
}

void func_020d9948(void) {
    M2C_UNK func_020e0480();
    func_020e0480();
}

void func_020d9954(void) {
    M2C_UNK func_020e048c();
    func_020e048c();
}

void func_020d9960(void) {
    M2C_UNK func_020e0580();
    func_020e0580();
}

void func_020d996c(void) {
    M2C_UNK func_020e05c4();
    func_020e05c4();
}

void func_020d9978(void) {
    M2C_UNK func_020e0abc();
    func_020e0abc();
}

void func_020d9984(void) {
    M2C_UNK func_020e0ac8();
    func_020e0ac8();
}

void func_020d9990(void) {
    M2C_UNK func_020e0ad4();
    func_020e0ad4();
}

void func_020d999c(void) {
    M2C_UNK func_020e0ae0();
    func_020e0ae0();
}

void func_020d99a8(void) {
    M2C_UNK func_020e0aec();
    func_020e0aec();
}

void func_020d99b4(void) {
    M2C_UNK func_020e0af8();
    func_020e0af8();
}

void func_020d99c0(void) {
    M2C_UNK func_020e0d84();
    func_020e0d84();
}

void func_020d99cc(void) {
    M2C_UNK func_020e0d90();
    func_020e0d90();
}

void func_020d99d8(void) {
    M2C_UNK func_020e0d9c();
    func_020e0d9c();
}

void func_020d99e4(void) {
    M2C_UNK func_020e0da8();
    func_020e0da8();
}

void func_020d99f0(void) {
    M2C_UNK func_020e0db4();
    func_020e0db4();
}

void func_020d99fc(void) {
    M2C_UNK func_020e0dc0();
    func_020e0dc0();
}

void func_020d9a08(void) {
    M2C_UNK func_020e0dcc();
    func_020e0dcc();
}

void func_020d9a14(void) {
    M2C_UNK func_020e0dec();
    func_020e0dec();
}

void func_020d9a20(void) {
    M2C_UNK func_020e0e0c();
    func_020e0e0c();
}

void func_020d9a2c(void) {
    M2C_UNK func_020e0e2c();
    func_020e0e2c();
}

void func_020d9a38(void) {
    M2C_UNK func_020e0e4c();
    func_020e0e4c();
}

void func_020d9a44(void) {
    M2C_UNK func_020e0e6c();
    func_020e0e6c();
}

void func_020d9a50(void) {
    M2C_UNK func_020e0ecc();
    func_020e0ecc();
}

void func_020d9a5c(void) {
    M2C_UNK func_020e0ed8();
    func_020e0ed8();
}

void func_020d9a68(void) {
    M2C_UNK func_020e0ee4();
    func_020e0ee4();
}

void func_020d9a74(void) {
    M2C_UNK func_020e0ef0();
    func_020e0ef0();
}

void func_020d9a80(void) {
    M2C_UNK func_020e0efc();
    func_020e0efc();
}

void func_020d9a8c(void) {
    M2C_UNK func_020e0f08();
    func_020e0f08();
}

