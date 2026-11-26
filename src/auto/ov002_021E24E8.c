/* 29 functions from 0x021E24E8 to 0x021E3210 (ov002), found by ds-decomp. */
#include "common.h"
#include "ov002_panel.h"
#include "gx.h"

typedef struct SlotEntry { s16 value; u8 index:3; u8 rest:5; u8 pad; } SlotEntry;
static inline void SetSlotIndex(SlotEntry *p, u8 index) { p->index=index; }
extern M2C_UNK data_ov002_021ea704;
static inline void *init_021e2848(void *p) {
M2C_FIELD(p,M2C_UNK **,0)=&data_ov002_021ea704;
M2C_FIELD(p,s32 *,8)=0;
M2C_FIELD(p,s32 *,12)=0;
return p;
}



/* Recursively tear down a node's right/child subtree, freeing every child pointer. */
void FreeModelList1(void *, void *);
/* Recursively tear down a node's right/child subtree, freeing every child pointer. */
void FreeModelNode(void *node) {
    void HeapFreeBlock(void *);
    void *right = M2C_FIELD(node, void **, 12);
    void *rightRight;
    if (right != NULL) {
        rightRight = M2C_FIELD(right, void **, 4);
        if (rightRight != NULL) {
            if (M2C_FIELD(rightRight, void **, 4) != NULL) FreeModelList1((u8 *)node + 8, M2C_FIELD(rightRight, void **, 4));
            if (M2C_FIELD(rightRight, void **, 0) != NULL) FreeModelNode(M2C_FIELD(rightRight, void **, 0));
            if (M2C_FIELD(rightRight, void **, 0) != NULL) { HeapFreeBlock(M2C_FIELD(rightRight, void **, 0)); M2C_FIELD(rightRight, void **, 0) = NULL; }
            if (M2C_FIELD(rightRight, void **, 4) != NULL) { HeapFreeBlock(M2C_FIELD(rightRight, void **, 4)); M2C_FIELD(rightRight, void **, 4) = NULL; }
        }
        if (M2C_FIELD(right, void **, 0) != NULL) FreeModelNode(M2C_FIELD(right, void **, 0));
        if (M2C_FIELD(right, void **, 0) != NULL) { HeapFreeBlock(M2C_FIELD(right, void **, 0)); M2C_FIELD(right, void **, 0) = NULL; }
        if (M2C_FIELD(right, void **, 4) != NULL) { HeapFreeBlock(M2C_FIELD(right, void **, 4)); M2C_FIELD(right, void **, 4) = NULL; }
    }
    if (M2C_FIELD(node, void **, 8) != NULL) FreeModelNode(M2C_FIELD(node, void **, 8));
    if (M2C_FIELD(node, void **, 8) != NULL) { HeapFreeBlock(M2C_FIELD(node, void **, 8)); M2C_FIELD(node, void **, 8) = NULL; }
    if (M2C_FIELD(node, void **, 12) != NULL) { HeapFreeBlock(M2C_FIELD(node, void **, 12)); M2C_FIELD(node, void **, 12) = NULL; }
}

void FreeModelList1(void *owner, void *node) {
void FreeModelNode(void *);
void HeapFreeBlock(void *);
void *right;
void *rightRight;
right = M2C_FIELD(node, void **, 4);
if (right != NULL) {
rightRight = M2C_FIELD(right, void **, 4);
if (rightRight != NULL) {
if (M2C_FIELD(rightRight, void **, 4) != NULL) FreeModelList1(owner, M2C_FIELD(rightRight, void **, 4));
if (M2C_FIELD(rightRight, void **, 0) != NULL) FreeModelNode(M2C_FIELD(rightRight, void **, 0));
if (M2C_FIELD(rightRight, void **, 0) != NULL) { HeapFreeBlock(M2C_FIELD(rightRight, void **, 0)); M2C_FIELD(rightRight, void **, 0) = NULL; }
if (M2C_FIELD(rightRight, void **, 4) != NULL) { HeapFreeBlock(M2C_FIELD(rightRight, void **, 4)); M2C_FIELD(rightRight, void **, 4) = NULL; }
}
if (M2C_FIELD(right, void **, 0) != NULL) FreeModelNode(M2C_FIELD(right, void **, 0));
if (M2C_FIELD(right, void **, 0) != NULL) { HeapFreeBlock(M2C_FIELD(right, void **, 0)); M2C_FIELD(right, void **, 0) = NULL; }
if (M2C_FIELD(right, void **, 4) != NULL) { HeapFreeBlock(M2C_FIELD(right, void **, 4)); M2C_FIELD(right, void **, 4) = NULL; }
}
if (M2C_FIELD(node, void **, 0) != NULL) FreeModelNode(M2C_FIELD(node, void **, 0));
if (M2C_FIELD(node, void **, 0) != NULL) { HeapFreeBlock(M2C_FIELD(node, void **, 0)); M2C_FIELD(node, void **, 0) = NULL; }
if (M2C_FIELD(node, void **, 4) != NULL) { HeapFreeBlock(M2C_FIELD(node, void **, 4)); M2C_FIELD(node, void **, 4) = NULL; }
}

/* Set the active flag on an effect node and on every node below it, so the whole
 * subtree is stepped again (effect script command 27). */
void Ov002_EnableEffectNodes(void *node) {
    void **link = 0;
    M2C_FIELD(node, s8 *, FX_NODE_ACTIVE) = 1;
    while ((link = link ? M2C_FIELD(link, void ***, FX_LINK_NEXT)
                        : (M2C_FIELD(node, s32 *, FX_NODE_CHILD) == 0 ? 0 : (void **)((u8 *)node + FX_NODE_CHILD))) != 0) {
        Ov002_EnableEffectNodes(*link);
    }
}

/* Clear the active flag on an effect node and on every node below it, so the
 * whole subtree stops being stepped (the counterpart of Ov002_EnableEffectNodes). */
void Ov002_DisableEffectNodes(void *node) {
    void **link = 0;
    M2C_FIELD(node, s8 *, FX_NODE_ACTIVE) = 0;
    while ((link = link ? M2C_FIELD(link, void ***, FX_LINK_NEXT)
                        : (M2C_FIELD(node, s32 *, FX_NODE_CHILD) == 0 ? 0 : (void **)((u8 *)node + FX_NODE_CHILD))) != 0) {
        Ov002_DisableEffectNodes(*link);
    }
}

/* Set a value on the effect node's FX_NODE_FLAG_51 byte and on every node below
 * it in its child chain. */
void Ov002_SetEffectNodesFlag51(void *node, s8 value) {
 void **link = 0;
 M2C_FIELD(node, s8 *, FX_NODE_FLAG_51) = value;
 while ((link = link ? M2C_FIELD(link, void ***, FX_LINK_NEXT)
                    : (M2C_FIELD(node, s32 *, FX_NODE_CHILD) == 0 ? 0 : (void **)((u8 *)node + FX_NODE_CHILD))) != 0) {
  Ov002_SetEffectNodesFlag51(*link, value);
 }
}

/* Total length in frames of an effect node's selected script: the sum of its
 * commands' frame counts.  A command that stops or finishes the script ends the
 * sum; one that loops or jumps may run forever, so the whole script is 0 frames. */
s32 Ov002_GetEffectScriptDuration(void *node) {
    s32 total = 0;
    u8 *cmd;
    if (!M2C_FIELD(node, s32 *, FX_NODE_ID)) return total;
    cmd = M2C_FIELD(node, u8 **, FX_NODE_SCRIPT_START);
    while (cmd[FX_SCRIPT_CMD_OPCODE] != FX_SCRIPT_CMD_END) {
        if (!cmd[FX_SCRIPT_CMD_FRAMES]) {
            switch (cmd[FX_SCRIPT_CMD_OPCODE]) {
            case FX_SCRIPT_OP_STOP:
            case FX_SCRIPT_OP_FINISH:
                return total;
            case FX_SCRIPT_OP_LOOP:
            case FX_SCRIPT_OP_JUMP:
                return 0;
            case 3:
            case 4:
            case 5:
            default:
                break;
            }
        } else {
            total += cmd[FX_SCRIPT_CMD_FRAMES];
        }
        cmd += FX_SCRIPT_COMMAND_SIZE;
    }
    return total;
}

/* Create the effect node for a template: chain the template's previous node as a
 * sibling, allocate and initialise a new node, and copy the template's resource,
 * translation and display fields into it.  `variant` picks the resource variant
 * (the template's command byte minus 0x41 or 0x51); side is -1 or 1, the node's
 * initial translation offset. */
void Ov002_CreateEffectNode(void *tmpl, s32 variant, s32 side) {
void *MemAlloc(M2C_UNK);
M2C_UNK SetEffectNodeResourceCore(void *,s32,s16,s8,u8);
register void *node;
void *link;
if(M2C_FIELD(tmpl,void **,FX_TEMPLATE_CHILD)) {
link=MemAlloc(8);
if(link) {M2C_FIELD(link,void **,0)=0;M2C_FIELD(link,void **,4)=0;}
M2C_FIELD(link,void **,0)=M2C_FIELD(tmpl,void **,FX_TEMPLATE_CHILD);
M2C_FIELD(link,void **,4)=M2C_FIELD(tmpl,void **,FX_TEMPLATE_NEXT);
M2C_FIELD(tmpl,void **,FX_TEMPLATE_NEXT)=link;
}
M2C_FIELD(tmpl,void **,FX_TEMPLATE_CHILD)=((node=MemAlloc(0x54)) ? init_021e2848(node) : node);
node=M2C_FIELD(tmpl,void **,FX_TEMPLATE_CHILD);
InitEffectNodeAppearance(node,M2C_FIELD(tmpl,u8 *,FX_TEMPLATE_PALETTE),M2C_FIELD(tmpl,u8 *,FX_TEMPLATE_TABLE_INDEX));
SetEffectNodeTranslation(node,0,0,(s16)side);
((M2C_UNK (*)(void *,s32,u16,u8,s32))SetEffectNodeResourceCore)(node,M2C_FIELD(tmpl,s32 *,FX_TEMPLATE_SOURCE_ID),M2C_FIELD(tmpl,u16 *,FX_TEMPLATE_SHAPE),M2C_FIELD(tmpl,u8 *,FX_TEMPLATE_KIND),variant);
M2C_FIELD(node,s32 *,FX_NODE_GRAPHIC_X)=M2C_FIELD(tmpl,s32 *,FX_TEMPLATE_X);
M2C_FIELD(node,s32 *,FX_NODE_GRAPHIC_Y)=M2C_FIELD(tmpl,s32 *,FX_TEMPLATE_Y);
M2C_FIELD(node,u8 *,FX_NODE_COLOUR)=M2C_FIELD(tmpl,u8 *,FX_TEMPLATE_COLOUR_BLEND);
M2C_FIELD(node,u8 *,FX_NODE_ACTIVE)=M2C_FIELD(tmpl,u8 *,FX_TEMPLATE_ACTIVE);
M2C_FIELD(node,u8 *,FX_NODE_FLAG_51)=M2C_FIELD(tmpl,u8 *,FX_TEMPLATE_FLAG_51);
}

/* Clear every effect node below `node` whose selected script is `scriptIndex`:
 * detach its resource and current frame so it stops drawing. */
void Ov002_ClearEffectNodesWithScript(void *node, s32 scriptIndex) {
    void ClearEffectNode(void *);
    void **link = 0;
    while ((link = link ? M2C_FIELD(link, void ***, FX_LINK_NEXT)
                       : (M2C_FIELD(node, s32 *, FX_NODE_CHILD) == 0 ? 0 : (void **)((u8 *)node + FX_NODE_CHILD))) != 0) {
        Ov002_ClearEffectNodesWithScript(*link, scriptIndex);
        if (scriptIndex == M2C_FIELD(*link, u8 *, FX_NODE_SCRIPT_INDEX)) ClearEffectNode(*link);
    }
}

void func_ov002_021e298c(void) {

}

void func_ov002_021e2990(void) {

}

s32 func_ov002_021e2994(void) {
    return 0;
}

/* Effect-script action (opcodes 16/17): flash the node's effect.  The node's
 * palette/effect bank and its row in the CO's effect tables select both the
 * effect node to flash (first table) and the palette to flash it with (second);
 * the selected node flashes for `frames` ticks. */
void SetEffectNodePaletteFlash(void *node, s32 frames) {
    void SetEffectNodeFlash(s32, s32, s32);
    extern M2C_UNK gUnitViewSlots;
    extern u8 data_ov002_021f3046;
    s32 bank = M2C_FIELD(node, u8 *, FX_NODE_PALETTE);
    s32 row = M2C_FIELD(node, u8 *, FX_NODE_TABLE_INDEX);
    SetEffectNodeFlash(M2C_FIELD((u8 *)&gUnitViewSlots + bank * 44, s32 *, row * 4), frames, (&data_ov002_021f3046 + bank * 100)[row * 8]);
}

/* Effect-script command 18: stop the screenshake of the unit view the effect
 * node's palette/effect bank selects. */
void Ov002_ClearEffectNodeUnitViewShake(void *node) {
    void StopUnitViewShake(void *);
    extern M2C_UNK gUnitViews;
    StopUnitViewShake((void *)((M2C_FIELD(node, u8 *, FX_NODE_PALETTE) * UNIT_VIEW_SIZE) + (s32) &gUnitViews));
}

/* Effect-script action (opcode 26): create the effect disc of the unit model
 * standing in the node's side's model slot of the battle unit views: the node's
 * FX_NODE_PALETTE picks the side and FX_NODE_TABLE_INDEX the model slot, and the
 * disc sits (x, y) pixels from the model's default position. */
void Ov002_CreateSlotEffectDisc(void *node, s32 x, s32 y) {
    void func_ov002_021ea4bc(void *, s32, s32);
    extern M2C_UNK gUnitViewSlots;
    s32 side = M2C_FIELD(node, u8 *, FX_NODE_PALETTE);
    s32 slot = M2C_FIELD(node, u8 *, FX_NODE_TABLE_INDEX);
    func_ov002_021ea4bc(M2C_FIELD((u8 *)&gUnitViewSlots + side * UNIT_VIEW_SIZE, void **, slot * 4), x, y);
}

/* Reset an effect node's script selection and clear its motion, scale ramp and
 * screen-drift state. */
void InitEffectNode(void *node) {
    M2C_UNK InitEffectNodeAppearance();
    InitEffectNodeAppearance();
    M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_VX) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_VY) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_AX) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_AY) = 0;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE) = 0x100;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE_FROM) = 0x100;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE_TO) = 0x100;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE_STEP) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) = -1;
    M2C_FIELD(node, s32 *, FX_NODE_DURATION) = 0;
    M2C_FIELD(node, s32 *, FX_NODE_TARGET) = 0;
    M2C_FIELD(node, s16 *, FX_NODE_SCREEN_X) = 0;
    M2C_FIELD(node, s16 *, FX_NODE_SCREEN_Y) = 0;
    M2C_FIELD(node, s16 *, FX_NODE_SCREEN_S) = 0x100;
    M2C_FIELD(node, s16 *, FX_NODE_MODE_86) = 0;
}

/* Give an effect node its resource, shape, kind and starting script, then start
 * its lifetime counter at 0 so the node is stepped from the next frame on (a
 * lifetime of -1 leaves it finished). */
void SetEffectNodeResource(void *node, s32 resource, s16 shape, s8 kind, u8 script) {
    M2C_UNK SetEffectNodeResourceCore(void *, s32, s16, s8, u8);

    SetEffectNodeResourceCore(node, resource, shape, kind, script);
    M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) = 0;
}

/* Per-frame update of an effect node.  While it is alive, advance its lifetime
 * and integrate its motion (position += velocity, velocity += acceleration, scale
 * += scale step).  A node that moves while scaling (FX_NODE_MODE_86) finishes
 * after FX_NODE_DURATION ticks, otherwise once it leaves the screen; before that
 * its scale eases from FX_NODE_SCALE_FROM to FX_NODE_SCALE_TO.  The node's script
 * and children are updated last. */
void UpdateEffectNode(void *node) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void ClearEffectNode(void *);
    void SetEffectNodeXY(void *, s32, s32);
    void func_ov002_021e1844(void *);
    void SetEffectNodePaletteFlash(void *, s32);
    s32 IsEffectNodeOffScreen(void *);
    s32 scale;
    if (M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) >= 0) {
        M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) = M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) + 1;
        if (M2C_FIELD(node, u16 *, FX_NODE_MODE_86) == 0) {
            if (M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) > M2C_FIELD(node, s32 *, FX_NODE_DURATION)) {
                M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) = M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) + M2C_FIELD(node, s32 *, FX_NODE_VX);
                M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) = M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) + M2C_FIELD(node, s32 *, FX_NODE_VY);
                M2C_FIELD(node, s32 *, FX_NODE_VX) = M2C_FIELD(node, s32 *, FX_NODE_VX) + M2C_FIELD(node, s32 *, FX_NODE_AX);
                M2C_FIELD(node, s32 *, FX_NODE_VY) = M2C_FIELD(node, s32 *, FX_NODE_VY) + M2C_FIELD(node, s32 *, FX_NODE_AY);
                {
                s16 step = M2C_FIELD(node, volatile s16 *, FX_NODE_SCALE_STEP);
                scale = M2C_FIELD(node, volatile u16 *, FX_NODE_SCALE) + step;
                }
                if (scale < 0) scale = 0;
                M2C_FIELD(node, u16 *, FX_NODE_SCALE) = (u16)scale;
                SetEffectNodeXY(node, (s32)(M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) << 8) >> 16, (s32)(M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) << 8) >> 16);
                if (IsEffectNodeOffScreen(node) != 0) {
                    ClearEffectNode(node);
                    M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) = -1;
                }
            } else {
                M2C_FIELD(node, u16 *, FX_NODE_SCALE) = (u16)EaseInterpolate(0, M2C_FIELD(node, s16 *, FX_NODE_SCALE_FROM), M2C_FIELD(node, s16 *, FX_NODE_SCALE_TO), M2C_FIELD(node, s32 *, FX_NODE_LIFETIME), M2C_FIELD(node, s32 *, FX_NODE_DURATION));
            }
        } else {
            M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) = M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) + M2C_FIELD(node, s32 *, FX_NODE_VX);
            M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) = M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) + M2C_FIELD(node, s32 *, FX_NODE_VY);
            M2C_FIELD(node, s32 *, FX_NODE_VX) = M2C_FIELD(node, s32 *, FX_NODE_VX) + M2C_FIELD(node, s32 *, FX_NODE_AX);
            M2C_FIELD(node, s32 *, FX_NODE_VY) = M2C_FIELD(node, s32 *, FX_NODE_VY) + M2C_FIELD(node, s32 *, FX_NODE_AY);
            {
                s16 step = M2C_FIELD(node, volatile s16 *, FX_NODE_SCALE_STEP);
                scale = M2C_FIELD(node, volatile u16 *, FX_NODE_SCALE) + step;
                }
            if (scale < 0) scale = 0;
            M2C_FIELD(node, u16 *, FX_NODE_SCALE) = (u16)scale;
            SetEffectNodeXY(node, (s32)(M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) << 8) >> 16, (s32)(M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) << 8) >> 16);
            if (M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) >= M2C_FIELD(node, s32 *, FX_NODE_DURATION)) {
                SetEffectNodePaletteFlash(node, 6);
                ClearEffectNode(node);
                M2C_FIELD(node, s32 *, FX_NODE_LIFETIME) = -1;
            }
        }
    }
    func_ov002_021e1844(node);
}

/* Effect-node class transform callback (vtable +0x0C), run by DrawEffectNode just
 * before the node's vertices: queue the node's translation into the geometry
 * engine's matrix (x negated on the flipped side; the node's mode-86 flag inverts
 * `flip`), then, unless the scale (current scale * speed / 256) is exactly 1.0,
 * a uniform scale of it in the GX's 20.12 fixed point. */
void SetEffectNodeDrawTransform(void *node,u8 flip) {
 s32 x,y,z; u16 scale; s32 value;
 scale=(M2C_FIELD(node,u16 *,FX_NODE_SCALE)*M2C_FIELD(node,u16 *,FX_NODE_SPEED))>>8;
 if(M2C_FIELD(node,u16 *,FX_NODE_MODE_86))flip=!flip;
 if(!flip) {
 z=M2C_FIELD(node,s16 *,FX_NODE_Z);y=M2C_FIELD(node,s16 *,FX_NODE_Y);x=M2C_FIELD(node,s16 *,FX_NODE_X);
 REG_GX_MTX_TRANS=x;REG_GX_MTX_TRANS=y;REG_GX_MTX_TRANS=z;
 }else{
 x=M2C_FIELD(node,s16 *,FX_NODE_X);z=M2C_FIELD(node,s16 *,FX_NODE_Z);y=M2C_FIELD(node,s16 *,FX_NODE_Y);
 REG_GX_MTX_TRANS=-x;REG_GX_MTX_TRANS=y;REG_GX_MTX_TRANS=z;
 }
 if(scale==256)return;
 value=(s32)(scale<<12)>>8;
 REG_GX_MTX_SCALE=value;REG_GX_MTX_SCALE=value;REG_GX_MTX_SCALE=4096;
}

void func_ov002_021e2cf0(void *arg0) {
    M2C_UNK func_ov002_021e1ef8(void *, u8);
    func_ov002_021e1ef8(arg0, (u8) M2C_FIELD(arg0, u16 *, 0x86));
}

/* Set an effect node's position: its whole-pixel translation (SetEffectNodeTranslation
 * reads the same node/x/y registers) and its 8.8 fixed-point position fields. */
void SetEffectNodePosition(void *node, s32 x, s32 y) {
    M2C_UNK SetEffectNodeTranslation();
    SetEffectNodeTranslation();
    M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) = (s32) (x << 8);
    M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) = (s32) (y << 8);
}

/* Fill an effect node's timed motion from an effect record: per-tick velocity
 * and acceleration, the duration and the scale ramp.  The node starts at the
 * ramp's from-scale when the motion runs for a duration, otherwise at its
 * to-scale; clearing the move-while-scaling mode makes it ease first, then move. */
void SetEffectNodeMotion(void *node, s32 velocityX, s32 velocityY, s32 accelX, s32 accelY, s32 duration, s16 scaleFrom, s16 scaleTo, s16 scaleStep) {
    M2C_FIELD(node, s32 *, FX_NODE_VX) = velocityX;
    M2C_FIELD(node, s32 *, FX_NODE_VY) = velocityY;
    M2C_FIELD(node, s32 *, FX_NODE_AX) = accelX;
    M2C_FIELD(node, s32 *, FX_NODE_AY) = accelY;
    M2C_FIELD(node, s32 *, FX_NODE_DURATION) = duration;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE_FROM) = scaleFrom;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE_TO) = scaleTo;
    M2C_FIELD(node, s16 *, FX_NODE_SCALE_STEP) = scaleStep;
    if (duration != 0) {
        M2C_FIELD(node, s16 *, FX_NODE_SCALE) = scaleFrom;
    } else {
        M2C_FIELD(node, s16 *, FX_NODE_SCALE) = scaleTo;
    }
    M2C_FIELD(node, s16 *, FX_NODE_MODE_86) = 0;
}

/* Configure an effect node's timed motion from an effect's transform values:
 * per-tick velocity and acceleration, the duration and the scale ramp, then
 * rewind the node's fixed-point position by the whole path so it settles on
 * (x, y) once the motion finishes. */
void SetEffectNodeTransform(void *node, s32 x, s32 y, s32 accelX, s32 accelY, s32 frames, s16 endScale, s16 scaleStep) {
 s32 moveY=y; s32 i; s32 moveX;
 M2C_FIELD(node,s32 *,FX_NODE_VX)=accelX*frames-x;
 M2C_FIELD(node,s32 *,FX_NODE_VY)=moveY-accelY*frames;
 M2C_FIELD(node,s32 *,FX_NODE_AX)=-accelX;
 M2C_FIELD(node,s32 *,FX_NODE_AY)=accelY;
 M2C_FIELD(node,s32 *,FX_NODE_DURATION)=frames;
 M2C_FIELD(node,s32 *,FX_NODE_TARGET)=frames;
 M2C_FIELD(node,s16 *,FX_NODE_SCALE_TO)=endScale-scaleStep*frames;
 M2C_FIELD(node,s16 *,FX_NODE_SCALE_STEP)=scaleStep;
 moveX=-x;
 M2C_FIELD(node,s16 *,FX_NODE_SCALE)=M2C_FIELD(node,s16 *,FX_NODE_SCALE_TO);
 i=0;
 if(frames>0)do {
 moveX+=accelX;
 M2C_FIELD(node,s32 *,FX_NODE_X_FIXED)-=moveX;
 moveY-=accelY;
 M2C_FIELD(node,s32 *,FX_NODE_Y_FIXED)-=moveY;
 i++;
 }while(i<frames);
 M2C_FIELD(node,s16 *,FX_NODE_MODE_86)=1;
}

void SetEffectNodeScreenPosition(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x80) = arg1;
    M2C_FIELD(arg0, s16 *, 0x82) = arg2;
    M2C_FIELD(arg0, s16 *, 0x84) = arg3;
}

/* Whether an effect node has left the screen in the direction it is
 * accelerating towards: its drifted position (whole pixels, scaled by
 * FX_NODE_SCREEN_S) is past that edge, so its handler can finish and free it. */
s32 IsEffectNodeOffScreen(void *node) {
    s32 screenY;
    s32 accelY;
    s32 screenX;
    s32 accelX;
    u16 screenScale;

    screenScale = M2C_FIELD(node, u16 *, FX_NODE_SCREEN_S);
    accelX = M2C_FIELD(node, s32 *, FX_NODE_AX);
    screenX = M2C_FIELD(node, s16 *, FX_NODE_SCREEN_X) + ((s32) (((s32) M2C_FIELD(node, s32 *, FX_NODE_X_FIXED) >> 8) * screenScale) >> 8);
    screenY = M2C_FIELD(node, s16 *, FX_NODE_SCREEN_Y) + ((s32) (((s32) M2C_FIELD(node, s32 *, FX_NODE_Y_FIXED) >> 8) * screenScale) >> 8);
    accelY = M2C_FIELD(node, s32 *, FX_NODE_AY);
    if ((accelX < 0) && (screenX < FX_CULL_LEFT)) {
        return 1;
    }
    if ((accelY < 0) && (screenY < FX_CULL_TOP)) {
        return 1;
    }
    if ((accelX > 0) && (screenX >= FX_CULL_RIGHT)) {
        return 1;
    }
    if ((accelY > 0) && (screenY >= FX_CULL_BOTTOM)) {
        return 1;
    }
    return 0;
}

/* Shuffle the five auto-attack slot indices for a panel: take a fixed order from the caller when given, otherwise randomize-then-anchor specific slots, then build a descending priority index table. */
void func_ov002_021e2eb8(void *panel, void *slotTable, void *orderSeq) {
void MI_CpuCopy8(void *, void *, s32);
s32 RandomIntRange(s32, s32);
void func_ov002_021e3030(u8 *, u8 *);
s32 j, best; void *entry; s32 k, mask, which, i;
M2C_FIELD(panel, void **, 4) = slotTable;
if (orderSeq) MI_CpuCopy8(orderSeq, panel + 0x12, 5);
else {
for (i = 0; i < 5; i++) M2C_FIELD(panel + i, u8 *, 0x12) = i;
for (i = 0; i < 5; i++) func_ov002_021e3030(panel + 0x12 + i, panel + 0x12 + RandomIntRange(0, 4));
which = -1;
if (!M2C_FIELD(panel, u8 *, 0x12)) which = 0;
if (!M2C_FIELD(panel, u8 *, 0x16)) which = 4;
if (which != -1) func_ov002_021e3030(panel + 0x12 + which, panel + 0x12 + RandomIntRange(1, 3));
}
for (i = 0; i < 5; i++) M2C_FIELD(panel + i, u8 *, 0x17) = i;
for (i = 0; i < 5; i++) func_ov002_021e3030(panel + 0x17 + i, panel + 0x17 + RandomIntRange(0, 4));
mask = 0;
for (k = 0; k < 5; k++) {
entry = panel + k;
M2C_FIELD(entry, u8 *, 0x1c) = 0;
best = -1;
for (j = 0; j < 5; j++) {
if (!(mask & (1 << j)) && best < M2C_FIELD(panel + j, u8 *, 0x12)) {
M2C_FIELD(entry, u8 *, 0x1c) = j;
best = M2C_FIELD(panel + j, u8 *, 0x12);
}
}
mask |= 1 << M2C_FIELD(entry, u8 *, 0x1c);
}
}

void func_ov002_021e3030(u8 *arg0, u8 *arg1) {
    u8 temp_r3;

    temp_r3 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_r3;
}

#pragma opt_strength_reduction off
void func_ov002_021e3044(u8 *arg0, s32 arg1, s32 arg2) {
s32 i; arg1--; arg2--;
for(i=0;i<5;i++){
u16 x=*(u8*)(arg0+i+18)*2;
if(arg1>x) *(u8*)(arg0+i*2+8)=2;
else if(arg1==x) *(u8*)(arg0+i*2+8)=1;
else *(u8*)(arg0+i*2+8)=0;
x=*(u8*)(arg0+i+18)*2;
if(arg2>x) *(u8*)(arg0+i*2+9)=2;
else if(arg2==x) *(u8*)(arg0+i*2+9)=1;
else *(u8*)(arg0+i*2+9)=0;
}
}
#pragma opt_strength_reduction on
/* Count the stat entries filled in a panel's PanelStat array, stopping at the
 * first unused (-1) entry: at most PANEL_ENTRY_MAX of them. */
s32 CountPanelEntries(s16 *value) {
    s32 count = 0;
    while (*value != -1 && count < PANEL_ENTRY_MAX) {
        count++;
        value += 2; /* the next PanelStat: its s16 value, then its flags word */
    }
    return count;
}

/* Build a versus screen player's status panel: clear its five stat entries, and
 * while the player is in the match copy each selected stat's value from the CO's
 * stat table (the panel's own table for the local player, the opponent's table
 * for the other panel), tagging the entry with the stat's icon index. */
void BuildPanelStatEntries(void *panel){
extern u8 gVersusPlayerStates[];extern volatile u8 gPlayerSettings[];
SlotEntry *slot;s32 clearIndex,n,orderIndex;u32 statIndex;u8 *statTable;void *entry;
clearIndex=0;do{M2C_FIELD(panel+((u32)clearIndex<<2),s16 *,PANEL_ENTRIES)=-1;clearIndex++;}while(clearIndex<5);
if(!gVersusPlayerStates[(s16)M2C_FIELD(panel,u8 *,PANEL_PLAYER)*24])return;
n=0;orderIndex=0;slot=panel+PANEL_ENTRIES;
do{
statIndex=M2C_FIELD(panel+orderIndex,u8 *,PANEL_STAT_ORDER);
if(M2C_FIELD(panel,u8 *,PANEL_PLAYER)==gPlayerSettings[0]){
if(M2C_FIELD(panel+statIndex*2,u8 *,PANEL_STAT_STATE)){
statTable=M2C_FIELD(panel,u8 **,PANEL_STAT_TABLE);
slot->value=statTable[0]+statTable[n+3];n++;
SetSlotIndex(slot,statIndex);slot++;
}
}else if(M2C_FIELD(panel+statIndex*2,u8 *,PANEL_STAT_STATE+1)){
statTable=M2C_FIELD(M2C_FIELD(panel,void **,PANEL_OTHER),u8 **,PANEL_STAT_TABLE);
slot->value=statTable[0]+statTable[n+8];n++;
SetSlotIndex(slot,statIndex);slot++;
}
orderIndex++;
}while(orderIndex<5);
}

