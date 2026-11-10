/* 16 functions from 0x020D5430 to 0x020D6398 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

void func_020d5430(void) {
 extern void *gCurrentMap;
 func_020cf850(0x1001a);func_0207a7a4(1,4);func_020cf5ec(1);
 if(!func_020bcac0())return;
 if(!func_020bd650())return;
 func_020bd104();func_ov000_021696d4();func_020cfd28();func_0207a768();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

void func_020d549c(void) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020cc62c();
    PlaySoundEffect(0x10017);
    func_020cc62c();
}

void func_020d54b4(void) {

}

void func_020d54b8(void) {
 extern void *gCurrentMap;
 func_020cf80c();func_0207a7a4(1,8);
 if(!func_020d4dd0())return;
 if(!func_020bcc04())return;
 if(!func_020bdcd0())return;
 func_02082770();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

void func_020d5514(void) {
    extern void *gCurrentMap;
    M2C_UNK (*temp_r0)();

    temp_r0 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(), 0x44);
    if (temp_r0 != NULL) {
        temp_r0();
    }
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52B4) = 0xA;
}

void func_020d5554(s32 arg0, s32 arg1) {
}

void func_020d5868(void) {
 void *func_0209f8e4(s32);
 extern void *gCurrentMap;
 s32 i=0;
 for(;i<func_0209f8d4();i++) {
 void *p=func_0209f8e4(i);
 void *base=M2C_FIELD(gCurrentMap,void **,0);
 u8 **rows=(u8 **)((u8 *)base+0x52e8);
 rows[M2C_FIELD(p,s16 *,6)][M2C_FIELD(p,s16 *,4)]=111;
 }
}

s32 func_020d58c4(s32 x,s32 y) {
void *func_020a45f8(s32,s32);
extern void *gCurrentMap;
void *unit; s32 a,b; M2C_UNK (*cb)();
unit=func_020a45f8(x,y);
if(unit){
SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
FillMapLayer(-1);
if(func_020a5364(unit,64,1)){
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),52);if(cb)cb();
goto finish;
}
}
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,0x3758));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0)=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4+M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)*14;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d6)=0;
if(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,0x3758))==0){func_020d5514();return 1;}
a=func_020ba3b4(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
b=func_020ba414(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
if(a==0 && b==0){PlaySoundEffect(0x1001d);return 0;}
SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
func_ov000_0216939c(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),52);if(cb)cb();
func_020cfd28();
func_020d5554(x,y);
finish:
func_0207a748(1);
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b4)=8;
PlaySoundEffect(0x1001c);return 1;
}

s32 func_020d5aa0(u8 x,u8 y,s32 check,s32 allow,u8 mode){
extern void *gCurrentMap; extern M2C_UNK data_0211fbc4; extern u16 data_02168f14;
s32 slot; M2C_UNK (*cb)(); void *unit;
func_020c93cc();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,0x3758));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0)=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4+M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)*14;

M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d6)=0;
if(func_020cf878(x,y)) { if(check)func_020b97c4(x,y); return 1; }
if (M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,0x3758)) == 0 || func_020a7cb0(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0)) != 0 || ((u32)(data_02168f14<<22)>>31)) { if(!allow)return 0; func_020c752c();return 1; }
func_ov000_0216a8dc(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
func_ov000_0216939c(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),56);if(cb)cb();
func_020cfd28();
func_020d5554(x,y);
func_0209fb70();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b6)=(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)>>6)+1;
SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
func_01ffc2e8(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b6)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4);
func_020d5868();
func_0207a748(0);func_0207b028(7);
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b4)=2;
func_020a06a0(mode);
func_01ffa3dc(&data_0211fbc4,6);
PlaySoundEffect(0x1001c);
func_020d6778(2);
if(IsPlayerHuman(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4)))func_02091c20(21,1);
return 1;
}

void func_020d5d0c(u8 *p,s32 index,s32 arg2){
extern void *gCurrentMap; extern M2C_UNK data_0211fbc4;
s32 slot; M2C_UNK (*cb)(); void *unit;
func_020c93cc();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)=(p+index)[12];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0)=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4+M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)*14;
slot=p?((s32)p-(s32)((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4))/14:0;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d6)=slot;
M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0),u16 *,4)&=~8;
func_ov000_0216a8dc(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
func_ov000_0216939c(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),56);if(cb)cb();
func_020cfd28();
unit=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0);
func_020d5554(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2));
func_0209fb70();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b6)=(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)>>6)+1;
SelectMapLayer((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
func_01ffc2e8(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b6)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4);
func_020d5868();
func_0207a748(0);func_0207b028(7);
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b4)=2;
func_020a06a0(arg2);
func_01ffa3dc(&data_0211fbc4,6);
PlaySoundEffect(0x1001c);
}

/* Move the battle-map cursor to tile (x,y): reject the move if the tile is out of
   range or unreachable, otherwise set the path start, the destination and the
   cursor state (4 = move, 5 = onto a unit), then redraw. */
void MoveCursorTo(s32 x, s32 y) {
    M2C_UNK PlaySoundEffect();
    M2C_UNK func_020d6398(s32, s32);
    M2C_UNK func_0207a768();
    M2C_UNK func_020a0964();
    M2C_UNK func_020d468c();
    M2C_UNK func_020a0d18();
    M2C_UNK func_020d46ac();
    M2C_UNK func_020a046c();
    M2C_UNK func_01ffb3d0();
    M2C_UNK func_020cc7e0();
    extern void *gCurrentMap;
    extern u8 data_02168f24;
    s32 occupied;

    occupied = 0;
    {
        u8 unitId = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_UNIT_ID);
        u16 owner = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_CURSOR_OWNER);
        if (owner != (unitId & 0xc0)) {
            PlaySoundEffect(0x1001d);
            return;
        }
    }
    {
        u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
        s8 cell = (s8)grid[y][x];
        if (cell > 0x6e) {
            occupied = 1;
        } else {
            if (func_020d6398(x, y) == 0) {
                PlaySoundEffect(0x1001d);
                return;
            }
        }
    }
    func_0207a768();
    {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_PATH_X) = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT), u8 *, 1);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_X) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_PATH_X);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, MAP_PATH_Y) = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, MAP_CURSOR_UNIT), u8 *, 2);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_Y) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_PATH_Y);
    }
    if (occupied != 0) {
        func_020a0964(x, y, (u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_CURSOR_X);
        func_020d468c();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_X) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_Y) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y);
        func_020a0d18();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_X) = (s16)x;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_TARGET_Y) = (s16)y;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = 5;
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X) = (s16)x;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y) = (s16)y;
        func_020d46ac();
        func_020a0d18();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_MODE) = 4;
    }
    if (M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_X) != M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X) ||
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_OLD_Y) != M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y)) {
        func_020a046c();
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, MAP_CURSOR_PATH) = 4;
    }
    if (occupied != 0) {
        func_01ffb3d0(-1);
        {
            u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
            s16 cy = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y);
            s16 cx = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X);
            grid[cy][cx] = 1;
        }
        {
            u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
            grid[y][x] = 1;
        }
        func_020cc7e0();
        {
            void (*fp)() = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(), 0x3c);
            if (fp != NULL) {
                fp();
            }
        }
    } else {
        func_01ffb3d0(-1);
        {
            u8 **grid = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + MAP_GRID);
            s16 cy = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_Y);
            s16 cx = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, MAP_CURSOR_X);
            grid[cy][cx] = 1;
        }
    }
    data_02168f24 = 0;
    return;
}

void func_020d61ac(void) {
 extern void *gCurrentMap;
 void *p=M2C_FIELD(gCurrentMap,void **,0);
 func_020cf498(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de));
 func_020c75cc();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=5;
}

void func_020d61f0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    M2C_UNK func_ov000_021696d4();
    extern M2C_UNK data_0211fbc4;
    func_01ffa9e4(&data_0211fbc4);
    func_ov000_021696d4();
}

void func_020d6310(void);
void func_020d6208(void) {
    extern void *data_027e0058;
    extern u8 data_02168f24;

    if (func_020d46cc() == 0) {
        if (func_020c9550() != 0) {
            func_020c95e4();
            func_020d61ac();
            return;
        }
        func_020d61f0();
        func_020cfd28();
        if (data_02168f24 != 0) {
            func_ov000_021696d4();
            M2C_FIELD(M2C_FIELD(data_027e0058, void **, 0), s16 *, 0x52b4) = 0;
            return;
        }
        {
            void *base = M2C_FIELD(data_027e0058, void **, 0);
            u8 idx;
            u8 *region;
            region = (u8 *)base + 0x5000;
            idx = region[0x2d6];
            if (idx != 0) {
                void *elem = (u8 *)base + 0x59a4 + idx * 14;
                u8 a = region[0x2d4];
                u8 b = ((u8 *)elem)[0x0c];
                u8 flag = (a != b) ? 1 : 0;
                func_020d5d0c(elem, flag, 1);
                return;
            }
            {
                void *p2 = *(void **)(region + 0x2d0);
                func_020d5aa0(((u8 *)p2)[1], ((u8 *)p2)[2], 1, 1, 1);
                return;
            }
        }
    } else {
        M2C_FIELD(M2C_FIELD(data_027e0058, void **, 0), s16 *, 0x52b4) = 6;
        func_ov000_0219c7c4(3);
        func_ov000_0219c7d8(0);
        func_020d6310();
        return;
    }
}

void func_020d6310(void) {
 extern void *gCurrentMap;
 if(!func_020d4dd0())return;
 func_ov000_0219e948();
 if(func_ov000_0219c7b0()!=2)return;
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

void func_020d6350(void) {
 extern void *gCurrentMap;
 void *p=M2C_FIELD(gCurrentMap,void **,0);
 func_020cf498(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de));
 func_020d468c();BattleUpdateUnitCursor();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

