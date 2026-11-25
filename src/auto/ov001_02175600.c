/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
typedef Ov001DeviceNameRecord MenuRecord;
extern struct { u8 state; u8 pad[3]; void *ptr; } gOv001WirelessSetup;

typedef struct { s32 x; u32 y; } Position;

void Ov001_KeypadCloseDone(int arg0) {
extern void *gOv001Keypad;
int i; unsigned int *ptr;
Ov001_PostTaskMessage(0,arg0);
for(i=0;i<4;i++){ptr=(unsigned int *)gOv001Keypad;Ov001_DestroySprite(((void **)ptr)[i+0x12]);ptr=(unsigned int *)gOv001Keypad;Ov001_ReleaseTextPanel(((void **)ptr)[i]);}
for(i=0;i<2;i++){ptr=(unsigned int *)gOv001Keypad;Ov001_DestroySprite(((void **)ptr)[i+0x10]);}
for(i=0;i<2;i++){ptr=(unsigned int *)gOv001Keypad;Ov001_ReleaseSprite(((void **)ptr)[i+0xe]);}
for(i=0;i<10;i++){ptr=(unsigned int *)gOv001Keypad;Ov001_ReleaseSprite(((void **)ptr)[i+4]);}
Ov001_FreeAlloc((void *)0x02193D20);
}

/* Prepare the default wireless setup request and start its worker. */
void Ov001_InitWirelessSetup(void) {
    void *Ov001_Alloc(s32, s32);
    extern char gOv001DefaultDeviceName[];
    void Ov001_AllocWirelessWork(void); void Ov001_FreeWirelessWork(void);
    Ov001DeviceNameRecord deviceName;
    gOv001WirelessSetup.ptr = Ov001_Alloc(0x26C, 4);
    gOv001WirelessSetup.state = 0;
    FillU16(0, &deviceName, 0x104);
    deviceName.kind = OV001_DEVICE_NAME_KIND; deviceName.size = 12;
    MI_CpuCopy8(gOv001DefaultDeviceName, deviceName.text);
    M2C_FIELD(gOv001WirelessSetup.ptr, s16 *, OV001_SETUP_MODE) = 3;
    M2C_FIELD(gOv001WirelessSetup.ptr, Ov001DeviceNameRecord *, OV001_SETUP_NAME) = deviceName;
    M2C_FIELD(gOv001WirelessSetup.ptr, s16 *, OV001_SETUP_OPTION0) = 1;
    M2C_FIELD(gOv001WirelessSetup.ptr, s16 *, OV001_SETUP_OPTION1) = -1;
    M2C_FIELD(gOv001WirelessSetup.ptr, s16 *, OV001_SETUP_OPTION2) = 1;
    M2C_FIELD(gOv001WirelessSetup.ptr, s16 *, OV001_SETUP_OPTION3) = -1;
    M2C_FIELD(gOv001WirelessSetup.ptr, s16 *, OV001_SETUP_OPTION4) = -1;
    GetMacAddress((char *)gOv001WirelessSetup.ptr + OV001_SETUP_MAC);
    if (Ov001_StartWirelessWorker(Ov001_AllocWirelessWork, Ov001_FreeWirelessWork)) SystemHalt();
}

