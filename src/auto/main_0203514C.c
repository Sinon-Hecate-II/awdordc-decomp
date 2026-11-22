/* 5 functions from 0x0203514C to 0x0203538C (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

#pragma scheduling on
void Wfc_ReleaseNetwork(void){extern void *gWfcNet;extern M2C_UNK data_020fb800,data_020fb810,data_020fb82c,data_020fb84c;void (*cb)(void*,void*,s32); void *base=*(void *volatile *)&gWfcNet;void *condition=*(void *volatile *)((char *)&gWfcNet+20);cb=M2C_FIELD(base,void (**)(void*,void*,s32),0x110c);if(condition){HttpClientCleanup();cb(&data_020fb800,M2C_FIELD(&gWfcNet,void**,20),0);M2C_FIELD(&gWfcNet,void**,20)=0;}FreeNasConnection();if(!gWfcNet)return;if(M2C_FIELD(gWfcNet,void**,0x1114)){cb(&data_020fb810,M2C_FIELD(gWfcNet,void**,0x1114),0);M2C_FIELD(gWfcNet,void**,0x1114)=0;}if(M2C_FIELD(gWfcNet,void**,0x1118)){cb(&data_020fb82c,M2C_FIELD(gWfcNet,void**,0x1118),0);M2C_FIELD(gWfcNet,void**,0x1118)=0;}cb(&data_020fb84c,gWfcNet,0);gWfcNet=0;}
/* Abort the network check: stop the HTTP client and the NAS login, join the
 * check's worker thread when one was started, and record the abort result. */
void Wfc_AbortNetworkSession(void) {
    M2C_UNK OS_JoinThread(void *);
    M2C_UNK NasAbort(void);
    M2C_UNK HttpClientAbort(void);
    extern void *gWfcNet;
    if (gWfcNet == NULL) return;
    if (M2C_FIELD(&gWfcNet, s32 *, WFC_NET_HTTP_CLIENT) != 0) {
        HttpClientAbort();
    }
    NasAbort();
    if (M2C_FIELD(gWfcNet, s32 *, WFC_NET_CHECK_TASK_ID) != 0) {
        OS_JoinThread(gWfcNet + WFC_NET_CHECK_TASK);
    }
    M2C_FIELD(gWfcNet, s32 *, WFC_NET_CHECK_RESULT) = WFC_NET_CHECK_ABORTED;
}

s32 Wfc_GetNetCheckState(void) {
    M2C_UNK LockMutex(void *);
    M2C_UNK UnlockMutex(void *);
    extern void *gWfcNet;
    s32 result;
    LockMutex(gWfcNet + 0x11DC);
    result = M2C_FIELD(gWfcNet, s32 *, 0x1000);
    UnlockMutex(gWfcNet + 0x11DC);
    return result;
}

s32 Wfc_GetNetResultCode(void) {
    extern void *gWfcNet;
    return M2C_FIELD(gWfcNet, s32 *, 0x1004);
}

/* Create and wake the HTTP network-check worker unless its existing thread is still running. */
void Wfc_StartNetCheckTask(void) {
    M2C_UNK TaskCreate(void *, void (*)(void), void *, void *, s32, s32);
    s32 TaskIsFinished(void *);
    M2C_UNK TaskWake(void *);
    void Wfc_NetCheckTask(void);
    extern void *gWfcNet;

    if (M2C_FIELD(gWfcNet, s32 *, WFC_NET_CHECK_TASK_ID) != 0 && TaskIsFinished(gWfcNet + WFC_NET_CHECK_TASK) == 0) {
        return;
    }
    TaskCreate(gWfcNet + WFC_NET_CHECK_TASK, Wfc_NetCheckTask, gWfcNet, gWfcNet + WFC_NET_CHECK_STACK,
               WFC_NET_CHECK_STACK_SIZE, WFC_NET_CHECK_TASK_PRIORITY);
    TaskWake(gWfcNet + WFC_NET_CHECK_TASK);
}

