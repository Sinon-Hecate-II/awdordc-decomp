/* 40 functions from 0x0218B368 to 0x0218C228 (ov001), found by ds-decomp. */
#include "common.h"
void OS_EnableIrqMask(s32);
extern s32 gOv001TilePools;

typedef struct ListLink { struct ListLink *prev; struct ListLink *next; } ListLink;
extern s32 gOv001SavedVBlankIrq[2];


typedef struct InputXY { u16 x,y; } InputXY;
typedef struct TouchFlags {
    u8 active : 1;
    u8 pressed : 1;
    u8 released : 1;
    u8 lifted : 1;
    u8 unused : 4;
} TouchFlags;

typedef struct TouchSample { u16 x,y,active,status; } TouchSample;
typedef struct InputState {
    TouchSample samples[5];
    u16 field_0x28;
    u16 field_0x2a;
    volatile u16 field_0x2c;
    volatile u16 field_0x2e;
    u16 pressed;
    u16 newPressed;
    u16 repeat;
    u16 released;
    TouchFlags flags;
} InputState;

static inline s32 TouchSampleValid(TouchSample *s) { return s->active==1 && s->status==0; }
typedef struct InputGlobal {
    s32 field0;
    InputState *state;
} InputGlobal;

void Ov001_DisableVisiblePlanes(s32 a,s32 b){
if(a==1){volatile u32 *p=(volatile u32 *)0x04001000;u32 t=*p&0x1f00;*p=(*p&~0x1f00)|((~b&(t>>8))<<8);return;}
{volatile u32 *p=(volatile u32 *)0x04000000;u32 t=*p&0x1f00;*p=(*p&~0x1f00)|((~b&(t>>8))<<8);}
}

/* Write a clip window rect into the selected display engine's window range
 * registers: rect[0],rect[2] is one packed range and rect[1],rect[3] the other.
 * `engine` picks the main (0) or sub (1) engine, `vertical` the horizontal (0)
 * or vertical (1) range register pair. */
void SetWindowRect(s32 engine, s32 vertical, u16 *rect) {
    if (engine == 1) {
        if (vertical == 0) {
            u32 left = rect[0], top = rect[1], right = rect[2], bottom = rect[3];
            *(volatile u16 *)GX_WIN0H_SUB = ((left << 8) & 0xff00) | (right & 255);
            *(volatile u16 *)(GX_WIN0H_SUB + 4) = ((top << 8) & 0xff00) | (bottom & 255);
        } else {
            u32 left = rect[0], top = rect[1], right = rect[2], bottom = rect[3];
            *(volatile u16 *)GX_WIN0V_SUB = ((left << 8) & 0xff00) | (right & 255);
            *(volatile u16 *)(GX_WIN0V_SUB + 4) = ((top << 8) & 0xff00) | (bottom & 255);
        }
    } else {
        if (vertical == 0) {
            u32 left = rect[0], top = rect[1], right = rect[2], bottom = rect[3];
            *(volatile u16 *)GX_WIN0H_MAIN = ((left << 8) & 0xff00) | (right & 255);
            *(volatile u16 *)(GX_WIN0H_MAIN + 4) = ((top << 8) & 0xff00) | (bottom & 255);
        } else {
            u32 left = rect[0], top = rect[1], right = rect[2], bottom = rect[3];
            *(volatile u16 *)GX_WIN0V_MAIN = ((left << 8) & 0xff00) | (right & 255);
            *(volatile u16 *)(GX_WIN0V_MAIN + 4) = ((top << 8) & 0xff00) | (bottom & 255);
        }
    }
}

/* Set the window IN/OUT control register fields for the selected display engine. */
void func_ov001_0218b4dc(s32 engine, u32 target, u32 value, s32 blend) {
    switch (target) {
    case 0:
        if (engine == 1) {
            u32 v = (*(volatile u16 *)0x04001048 & ~0x3f) | value;
            if (blend) v |= 0x20;
            *(volatile u16 *)0x04001048 = v;
            return;
        } else {
            u32 v = (*(volatile u16 *)0x04000048 & ~0x3f) | value;
            if (blend) v |= 0x20;
            *(volatile u16 *)0x04000048 = v;
            return;
        }
    case 1:
        if (engine == 1) {
            u32 v = (*(volatile u16 *)0x04001048 & ~0x3f00) | (value << 8);
            if (blend) v |= 0x2000;
            *(volatile u16 *)0x04001048 = v;
            return;
        } else {
            u32 v = (*(volatile u16 *)0x04000048 & ~0x3f00) | (value << 8);
            if (blend) v |= 0x2000;
            *(volatile u16 *)0x04000048 = v;
            return;
        }
    case 2:
        if (engine == 1) {
            u32 v = (*(volatile u16 *)0x0400104a & ~0x3f00) | (value << 8);
            if (blend) v |= 0x2000;
            *(volatile u16 *)0x0400104a = v;
            return;
        } else {
            u32 v = (*(volatile u16 *)0x0400004a & ~0x3f00) | (value << 8);
            if (blend) v |= 0x2000;
            *(volatile u16 *)0x0400004a = v;
            return;
        }
    case 3:
        if (engine == 1) {
            u32 v = (*(volatile u16 *)0x0400104a & ~0x3f) | value;
            if (blend) v |= 0x20;
            *(volatile u16 *)0x0400104a = v;
            return;
        } else {
            u32 v = (*(volatile u16 *)0x0400004a & ~0x3f) | value;
            if (blend) v |= 0x20;
            *(volatile u16 *)0x0400004a = v;
            return;
        }
    }
}

void func_ov001_0218b648(s32 a){
M2C_UNK MI_CpuFill8(s32,M2C_UNK,M2C_UNK);
s32 func_0202a424(s32,s32,s32);void SystemHalt(void);extern s32 data_ov001_02193e44;
MI_CpuFill8(a,0,0x40000);data_ov001_02193e44=func_0202a424(a,0x40000,0);
if(data_ov001_02193e44==0)SystemHalt();
}

void func_ov001_0218b688(void) {
    M2C_UNK func_0202a45c(s32);
    extern s32 data_ov001_02193e44;
    func_0202a45c(data_ov001_02193e44);
    data_ov001_02193e44 = 0;
}

s32 func_ov001_0218b6ac(s32 a,s32 b){
s32 OS_DisableIrqMask(s32);void OS_EnableIrqMask(s32);s32 func_0202a468(s32,s32,s32);void SystemHalt(void);extern s32 data_ov001_02193e44;s32 result,saved;
saved=OS_DisableIrqMask(1);result=func_0202a468(data_ov001_02193e44,a,b);
if(!result)SystemHalt();OS_EnableIrqMask(saved);return result;
}

s32 Ov001_Alloc(M2C_UNK arg0) {
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    s32 func_ov001_0218b6ac();
    s32 temp_r0;

    temp_r0 = func_ov001_0218b6ac();
    MI_CpuFill8(temp_r0, 0, arg0);
    return temp_r0;
}

s32 Ov001_FreeAlloc(s32 *p) {
s32 OS_DisableIrqMask(s32);
extern s32 data_ov001_02193e44;
s32 saved=OS_DisableIrqMask(1);
if(*p==0)return saved;
func_0202a498(data_ov001_02193e44,*p);
OS_EnableIrqMask(saved);
*p=0;
return 0;
}

void func_ov001_0218b760(s32 a) {
s32 OS_DisableIrqMask(s32);
extern s32 data_ov001_02193e44;
s32 saved=OS_DisableIrqMask(1);
if(a==0)return;
func_0202a498(data_ov001_02193e44,a);
OS_EnableIrqMask(saved);
}

void Ov001_UpdateInput(void);
/* Start the shell's input: allocate the input block, take the touch screen's
 * factory calibration from the firmware, hand the block to the touch driver as a
 * five-sample buffer and start the ARM7's touch sampling.  The system halts when
 * the firmware has no usable calibration or the ARM7 does not start sampling,
 * and the input is then read once to prime the key and touch state. */
void Ov001_StartInput(void) {
    extern M2C_UNK gOv001Input;
    s32 calibration[2];
    M2C_FIELD(&gOv001Input, s32 *, 4) = ((s32 (*)())Ov001_Alloc)(0x3a, 4);
    if (TP_GetFirmwareCalibration(calibration) == 0) SystemHalt();
    SetTouchCalibration(calibration);
    TP_RequestAutoSamplingStartAsync(0, 4, M2C_FIELD(&gOv001Input, s32 *, 4), 5);
    TP_WaitBusy(2);
    if (TP_CheckBusy(2) != 0) SystemHalt();
    Ov001_UpdateInput();
}

void Ov001_StopInput(void) {
    M2C_UNK TP_StopSampling();
    M2C_UNK TP_WaitBusy(M2C_UNK);
    s32 TP_CheckBusy(M2C_UNK);
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK data_ov001_02193e4c;
    do {
        TP_StopSampling();
        TP_WaitBusy(4);
    } while (TP_CheckBusy(4) != 0);
    Ov001_FreeAlloc(&data_ov001_02193e4c);
}

void Ov001_UpdateInput(void) {
    void func_ov001_0218b860(void);
    void func_ov001_0218b964(void);
    func_ov001_0218b860();
    func_ov001_0218b964();
}

void func_ov001_0218b860(void) {
    extern M2C_UNK gOv001Input;
    extern u8 data_ov001_02193e50[];
    u16 keyin = *(volatile u16 *)0x4000130;
    u16 gval = *(volatile u16 *)0x27fffa8;
    u16 pressed = (u16)(((keyin | gval) ^ 0x2fff) & 0x2fff);
    void *input = M2C_FIELD(&gOv001Input, void **, 4);
    u16 previous;
    M2C_FIELD(input, u16 *, 0x32) =
        (M2C_FIELD(input, u16 *, 0x30) ^ pressed) & pressed;
    previous = M2C_FIELD(input, u16 *, 0x30);
    input = M2C_FIELD(&gOv001Input, void **, 4);
    M2C_FIELD(input, u16 *, 0x36) =
        previous & (previous ^ pressed);
    M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x30) = pressed;
    M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x34) =
        M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x32);
    {
        int i = 0;
        while (i < 14) {
            u16 bit = (u16)(1 << i);
            if (!(pressed & bit)) {
                data_ov001_02193e50[i] = 0;
            } else {
                u8 cnt = ++data_ov001_02193e50[i];
                if (cnt == 0x28) {
                    M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x34) |= bit;
                } else if (cnt == 0x2f) {
                    M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x34) |= bit;
                    data_ov001_02193e50[i] = 0x28;
                }
            }
            i++;
        }
    }
}

void func_ov001_0218b964(void) {
extern M2C_UNK gOv001Input;
s32 HardwareDivideRemainder(s32,s32); s32 func_0200d9f4(void);void CalibrateTouchSample(void *);void func_ov001_0218b2bc(u16,u16,void *);
register s32 i,active,old,delta; register s32 index; u16 xy[4]; InputState *p; InputGlobal *g; u8 *sp;
old=((InputGlobal *)&gOv001Input)->state->flags.active?1:0;
active=0;index=func_0200d9f4();
p=((InputGlobal *)&gOv001Input)->state;
*(InputXY *)((u8 *)p+0x2c)=*(InputXY *)((u8 *)p+0x28);
for(i=active;i<4;) {
sp=(u8 *)((InputGlobal *)&gOv001Input)->state->samples;
sp+= (index << 3);
if(M2C_FIELD(sp,u16 *,4)==1 && !M2C_FIELD(sp,u16 *,6)) {
active=1;CalibrateTouchSample(xy);func_ov001_0218b2bc(xy[0],xy[1],&((InputGlobal *)&gOv001Input)->state->field_0x28);break;
}
i++;index=HardwareDivideRemainder(index+4,5);
}
g=(InputGlobal *)&gOv001Input;delta=active^old;
g->state->flags.pressed=(u8)(active&delta);
g->state->flags.lifted=(u8)(old&delta);
M2C_FIELD(g->state,u8 *,0x38)=(M2C_FIELD(g->state,u8 *,0x38)&~1)|(active&1);
g->state->flags.released=g->state->flags.pressed;
if(!active) { M2C_FIELD(g,u8 *,1)=0;return; }
{
if(++M2C_FIELD(g,u8 *,1)==40) g->state->flags.released=1;
else if(M2C_FIELD(g,u8 *,1)==47){g->state->flags.released=1;M2C_FIELD(g,u8 *,1)=40;}
}
}

#pragma opt_peephole off
s32 KeyPressed(s32 arg0) {
    extern M2C_UNK gOv001Input;
    if (arg0 == (arg0 & M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x32))) {
        return 1;
    }
    return 0;
}
#pragma opt_peephole reset
s32 KeyHeld(s32 a) {
    extern M2C_UNK gOv001Input;
    s32 t;
    t = a & M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x34);
    return a == t;
}

s32 KeyReleased(s32 a) {
    extern M2C_UNK gOv001Input;
    s32 t;
    t = a & M2C_FIELD(M2C_FIELD(&gOv001Input, void **, 4), u16 *, 0x36);
    return a == t;
}

/* Touch hit test: return 1 when the current touch point is inside rectangle
 * `rect` (left, top, right, bottom) and the input state's active flag is set,
 * i.e. the screen is being touched.  The four TouchRect* predicates share the
 * rectangle check and differ only in which touch flag they read. */
s32 TouchRectReleased(u16 *rect) {
    extern M2C_UNK gOv001Input;
    void *state = M2C_FIELD(&gOv001Input, void **, 4);
    if (M2C_FIELD(state, TouchFlags *, 0x38).active == 0) return 0;
    if (rect[0] > M2C_FIELD(state, u16 *, 0x28)) return 0;
    if (rect[2] < M2C_FIELD(state, u16 *, 0x28)) return 0;
    if (rect[1] > M2C_FIELD(state, u16 *, 0x2a)) return 0;
    return rect[3] >= M2C_FIELD(state, u16 *, 0x2a);
}

/* True while the current touch point lies inside rect (left, top, right, bottom)
 * and the touch was just pressed. */
s32 TouchRectPressed(u16 *rect){
extern M2C_UNK gOv001Input;
InputState *input=M2C_FIELD(&gOv001Input,InputState **,4);
if(!input->flags.pressed)return 0;
if(rect[0]>M2C_FIELD(input,u16 *,0x28))return 0;
if(rect[2]<M2C_FIELD(input,u16 *,0x28))return 0;
if(rect[1]>M2C_FIELD(input,u16 *,0x2a))return 0;
return rect[3]>=M2C_FIELD(input,u16 *,0x2a);
}

/* True while the current touch point lies inside rect (left, top, right, bottom)
 * and the touch is pressed or auto-repeating (repeat bit of the touch flags). */
s32 TouchRectPressOrRepeat(u16 *rect){
extern M2C_UNK gOv001Input;
InputState *input=M2C_FIELD(&gOv001Input,InputState **,4);
if(!input->flags.released)return 0;
if(rect[0]>M2C_FIELD(input,u16 *,0x28))return 0;
if(rect[2]<M2C_FIELD(input,u16 *,0x28))return 0;
if(rect[1]>M2C_FIELD(input,u16 *,0x2a))return 0;
return rect[3]>=M2C_FIELD(input,u16 *,0x2a);
}

/* Return 1 when the touch point is inside rectangle `rect` (left, top, right,
 * bottom) and the touch state's flag bit 3 is set; the four TouchRect*
 * predicates share the rectangle check and differ only in the flag bit. */
s32 TouchRectHeld(u16 *rect) {
    extern M2C_UNK gOv001Input;
    void *state = M2C_FIELD(&gOv001Input, void **, 4);
    u32 flags = M2C_FIELD(state, u8 *, 0x38);
    if ((flags << 28 >> 31) == 0) return 0;
    if (rect[0] > M2C_FIELD(state, u16 *, 0x28)) return 0;
    if (rect[2] < M2C_FIELD(state, u16 *, 0x28)) return 0;
    if (rect[1] > M2C_FIELD(state, u16 *, 0x2a)) return 0;
    return rect[3] >= M2C_FIELD(state, u16 *, 0x2a);
}

s32 func_ov001_0218bd1c(u16 *a){u16 box[4];box[0]=a[0];box[1]=a[1];box[2]=a[0]+a[2];box[3]=a[1]+a[3];return TouchRectPressed(box);}

s32 Ov001_ReadTouchPoint(u16 *a){extern M2C_UNK gOv001Input;void *p=M2C_FIELD(&gOv001Input,void **,4);u16 x,y;
if(!M2C_FIELD(p,TouchFlags *,0x38).active){x=M2C_FIELD(p,volatile u16 *,0x2c);y=M2C_FIELD(p,volatile u16 *,0x2e);a[0]=x;a[1]=y;return 0;}
x=M2C_FIELD(p,volatile u16 *,0x28);y=M2C_FIELD(p,volatile u16 *,0x2a);a[0]=x;a[1]=y;return 1;
}

/* Keep the LCD in step with the shell's lid switch: turn the display off while
 * the lid is closed and bring it back when it opens, latching the state in the
 * input global's +0 byte. */
void Ov001_UpdateLidState(void) {
    s32 SetLcdEnabled(s32);
    extern M2C_UNK gOv001Input;
    if (M2C_FIELD(&gOv001Input, u8 *, 0)) {
        if (((*(volatile u16 *)SHARED_LID_WORD) & SHARED_LID_CLOSED) >> 15) return;
        if (SetLcdEnabled(1)) M2C_FIELD(&gOv001Input, u8 *, 0) = 0;
    } else {
        if (!(((*(volatile u16 *)SHARED_LID_WORD) & SHARED_LID_CLOSED) >> 15)) return;
        if (SetLcdEnabled(0)) M2C_FIELD(&gOv001Input, u8 *, 0) = 1;
    }
}

void Ov001_VBlankHandler(void);
/* Hook the ov001 VBlank handler into the OS IRQ system: save the current IE
 * mask and OS handler, route IRQ 1 (VBlank) to Ov001_VBlankHandler and enable
 * the IRQ lines it relies on, then unmask interrupts. */
void Ov001_InstallVBlankHandler(void) {
    s32 OS_SetIrqEnableMask(s32);
    s32 OS_GetIrqHandler(s32);
    void OS_SetIrqHandler(s32, void (*)(void));
    s32 OS_SetIrqMask(s32);
    void func_02007508(s32, u16);

    gOv001SavedVBlankIrq[1] = *(volatile u32 *)REG_IE;
    OS_SetIrqEnableMask(0x40018);
    OS_EnableIrqMask(IRQ_VBLANK);
    gOv001SavedVBlankIrq[0] = OS_GetIrqHandler(IRQ_VBLANK);
    OS_SetIrqHandler(IRQ_VBLANK, Ov001_VBlankHandler);
    OS_SetIrqMask(IRQ_VBLANK);
    {
        u16 oldIme = *(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = 1;
        func_02007508(1, oldIme);
    }
}

void Ov001_RemoveVBlankHandler(void) {
(void)*(volatile u16 *)0x04000208;
*(volatile u16 *)0x04000208=0;
OS_SetIrqEnableMask(gOv001SavedVBlankIrq[1]);
OS_SetIrqHandler(1,gOv001SavedVBlankIrq[0]);
}

void Ov001_VBlankHandler(void) {
    M2C_UNK func_ov001_0218c7d4(M2C_UNK);
    extern M2C_UNK gOsArea;
    func_ov001_0218c7d4(1);
    M2C_FIELD(&gOsArea, s32 *, 0x3FF8) = (s32) (M2C_FIELD(&gOsArea, s32 *, 0x3FF8) | 1);
}

s32 Ov001_ListCreate(void){s32 p=((s32 (*)(s32,s32))Ov001_Alloc)(16,4);
M2C_FIELD(p,s32 *,0)=0;M2C_FIELD(p,s32 *,4)=p+8;M2C_FIELD(p,s32 *,8)=p;M2C_FIELD(p,s32 *,12)=0;return p;}

void func_ov001_0218bf30(s32 arg0, ...) {
 M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
 Ov001_FreeAlloc(&arg0);
}

void Ov001_ListRemove(ListLink *node){s32 OS_DisableIrqMask(s32);void OS_EnableIrqMask(s32);s32 state=OS_DisableIrqMask(1);node->prev->next=node->next;node->next->prev=node->prev;node->next=0;node->prev=0;OS_EnableIrqMask(state);}

M2C_UNK Ov001_ListInsertBefore(a,b)
s32 a; s32 b;{s32 OS_DisableIrqMask(s32);s32 state=OS_DisableIrqMask(1);ListLink *head=(ListLink *)a,*node=(ListLink *)b;head->prev->next=node;node->prev=head->prev;node->next=head;head->prev=node;OS_EnableIrqMask(state);}

void Ov001_ListPushBack(s32 arg0) {
    Ov001_ListInsertBefore(arg0 + 8);
}

void Ov001_ListPushFront(void *arg0) {
    M2C_UNK Ov001_ListInsertBefore();
    Ov001_ListInsertBefore(M2C_FIELD(arg0, s32 *, 4));
}

/* Set up the ov001 sprite-object arena: allocate both screens' OAM entry
 * areas, fill them with the disabled-entry pattern, create each screen's queue
 * of free 8-byte entries, and start the task that copies the arena to the
 * hardware OAM. */
void Ov001_InitSpriteObjs(void) {
    void Ov001_FlushSpriteObjs(void);
    extern s32 gOv001SpriteArena;
    void MI_CpuFill32(s32, s32, s32);
    s32 Ov001_QueueCreateFromBuffer(s32, s32, s32);
    s32 Ov001_AddTask(s32, void (*)(void), s32, s32);
    s32 i, offset;
    s32 arena = ((s32 (*)(s32, s32))Ov001_Alloc)(OV001_SPRITE_OBJ_ARENA_SIZE, 4);
    gOv001SpriteArena = arena;
    MI_CpuFill32(0x200, arena, OV001_SPRITE_OBJ_BUFFER);
    for (i = 0, offset = 0; i < 2; i++) {
        s32 result = Ov001_QueueCreateFromBuffer(OV001_SPRITE_OBJ_COUNT, gOv001SpriteArena + offset, OV001_SPRITE_OBJ_STRIDE);
        offset += OV001_SPRITE_OBJS_PER_SCREEN;
        ((s32 *)gOv001SpriteArena)[i + OV001_SPRITE_OBJ_FREE_QUEUES / 4] = result;
    }
    M2C_FIELD(gOv001SpriteArena, s32 *, OV001_SPRITE_OBJ_TASK) = Ov001_AddTask(1, Ov001_FlushSpriteObjs, 0, OV001_SPRITE_OBJ_TASK_PERIOD);
}

void Ov001_FlushSpriteObjs(void){
extern s32 gOv001SpriteArena;void DC_FlushRange(s32,s32);void func_02004210(s32,s32,s32);void func_02004264(s32,s32,s32);
DC_FlushRange(gOv001SpriteArena,0x800);func_02004210(gOv001SpriteArena,0,0x400);func_02004264(gOv001SpriteArena+0x400,0,0x400);
}

#pragma pool_constants off
void func_ov001_0218c0b8(void) {
    extern s32 gOv001SpriteArena;
    extern s32 gOv001TilePools;
    func_ov001_0218c94c(1, M2C_FIELD(gOv001SpriteArena, s32 *, 0x808));
    Ov001_FreeAlloc(&gOv001TilePools-1);
}
#pragma pool_constants reset
void func_ov001_0218c0e4(s32 n){
extern s32 gOv001SpriteArena; void Ov001_QueuePop(s32);
Ov001_QueuePop(M2C_FIELD(gOv001SpriteArena+(n<<2),s32 *,0x800));
}

void Ov001_ReleaseSprite(u32 *p){
extern s32 gOv001SpriteArena;
void Ov001_QueuePush(s32,void *);
s32 i=0;
*p=(*p&0xc1fffcff)|0x200;
if((u32)p>=(u32)(gOv001SpriteArena+0x400))i=1;
Ov001_QueuePush(M2C_FIELD(gOv001SpriteArena+(i<<2),s32 *,0x800),p);
}

s32 Ov001_SpriteObjAddr(s32 arg0, s32 arg1) {
    extern s32 gOv001SpriteArena;
    return gOv001SpriteArena + (arg0 << 0xA) + (arg1 * 8);
}

/* Creates the two ov001 tile-range pools (one per tile screen): each gets a list
 * of the ranges in use, a queue of free range nodes and the initial free tile
 * range OV001_TILE_POOL_FREE_START .. OV001_TILE_POOL_FREE_END. */
void Ov001_InitTilePools(void){
s32 i;
gOv001TilePools=((s32 (*)(s32,s32))Ov001_Alloc)(OV001_TILE_POOL_STRIDE*OV001_TILE_POOL_COUNT,4);
for(i=0;i<OV001_TILE_POOL_COUNT;i++){
M2C_FIELD(gOv001TilePools+i*OV001_TILE_POOL_STRIDE,s32 *,OV001_TILE_POOL_FREE_NODES)=Ov001_QueueCreateFromBuffer(OV001_TILE_POOL_NODE_COUNT,gOv001TilePools+i*OV001_TILE_POOL_STRIDE,sizeof(Ov001RangeNode));
M2C_FIELD(gOv001TilePools+i*OV001_TILE_POOL_STRIDE,s32 *,OV001_TILE_POOL_USED_LIST)=Ov001_ListCreate();
M2C_FIELD(gOv001TilePools+i*OV001_TILE_POOL_STRIDE,u16 *,OV001_TILE_POOL_HEAD_START)=OV001_TILE_POOL_FREE_START;
M2C_FIELD(gOv001TilePools+i*OV001_TILE_POOL_STRIDE,u16 *,OV001_TILE_POOL_TAIL_START)=OV001_TILE_POOL_FREE_END;
((void (*)(s32,s32))Ov001_ListPushFront)(M2C_FIELD(gOv001TilePools+i*OV001_TILE_POOL_STRIDE,s32 *,OV001_TILE_POOL_USED_LIST),gOv001TilePools+i*OV001_TILE_POOL_STRIDE+OV001_TILE_POOL_HEAD);
((void (*)(s32,s32))Ov001_ListPushBack)(M2C_FIELD(gOv001TilePools+i*OV001_TILE_POOL_STRIDE,s32 *,OV001_TILE_POOL_USED_LIST),gOv001TilePools+i*OV001_TILE_POOL_STRIDE+OV001_TILE_POOL_TAIL);
}
}

