/* 21 functions from 0x02009EB0 to 0x0200AE9C (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
static inline u32 LowerChar(u32 c) { c-=0x41; if(c<=25) return c+0x61;return c+0x41; }
typedef struct { u32 a,b,c; } UnkA3Block;
typedef struct { UnkA3Block block; u32 kind, length; u8 name[128]; } PathEntry;
typedef struct { u32 a:5; u32 c:1; u32 b:26; } FifoWord;

s32 func_02009eb0(u32 a,u32 b,u32 c) { s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);FifoWord v; s32 key;v.a=a;v.c=c;v.b=b;if(*(volatile u16 *)0x04000184&0x4000){*(volatile u16 *)0x04000184|=0xc000;return -1;}key=OS_DisableInterrupts();if(*(volatile u16 *)0x04000184&2){OS_RestoreInterrupts(key);return -2;}*(volatile u32 *)0x04000188=*(u32 *)&v;OS_RestoreInterrupts(key);return 0;}

void func_02009f38(void){
s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);
extern void (*data_0212fb68[])(u32,u32,u32);
FifoWord v;s32 result,key;u32 tag;void (*cb)(u32,u32,u32);
for(;;){
if(*(volatile u16*)0x04000184&0x4000){*(volatile u16*)0x04000184|=0xc000;result=-3;}
else{
key=OS_DisableInterrupts();
if(*(volatile u16*)0x04000184&0x100){OS_RestoreInterrupts(key);result=-4;}
else{*(u32*)&v=*(volatile u32*)0x04100000;OS_RestoreInterrupts(key);result=0;}
}
if(result==-4)return;
if(result==-3)continue;
tag=v.a;if(!tag)continue;
cb=data_0212fb68[tag];
if(cb)cb(tag,v.b,v.c);
else if(!v.c){
v.c=1;
if(*(volatile u16*)0x04000184&0x4000){*(volatile u16*)0x04000184|=0xc000;continue;}
key=OS_DisableInterrupts();
if(*(volatile u16*)0x04000184&2){OS_RestoreInterrupts(key);continue;}
*(volatile u32*)0x04000188=*(u32*)&v;
OS_RestoreInterrupts(key);
}
}
}

void CompleteFileRequest(void *p,s32 a) {s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);s32 OS_WakeupThread(void *);s32 k;void *prev,*next;k=OS_DisableInterrupts();prev=M2C_FIELD(p,void **,0);next=M2C_FIELD(p,void **,4);if(prev)M2C_FIELD(prev,void **,4)=next;if(next)M2C_FIELD(next,void **,0)=prev;M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;M2C_FIELD(p,u32 *,12)&=~0x4f;M2C_FIELD(p,s32 *,20)=a;OS_WakeupThread((u8 *)p+24);OS_RestoreInterrupts(k);}

s32 ExecuteFileCommand(void *a, s32 b) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    M2C_UNK OS_SleepThread(void *);
    extern s32 (*gFileCommandHandlers[])(void *);
    void CompleteFileRequest(void *, s32);

    s32 e;
    void *c = M2C_FIELD(a, void **, 0x8);
    u32 d = (u32)1 << b;
    s32 flag = 1;
    s32 has200;
    s32 outer;
    s32 zero = 0;
    s32 one = 1;

    if (!(M2C_FIELD(a, s32 *, 0xc) & 0x4)) {
        flag = 0;
    }
    if (flag) {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) | 0x200;
    } else {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) | 0x100;
    }
    if (M2C_FIELD(c, u32 *, 0x58) & d) {
        s32 (*cb)(void *, s32) = M2C_FIELD(c, s32 (**)(void *, s32), 0x54);
        e = cb(a, b);
        switch (e) {
        case 0:
        case 1:
        case 4:
            M2C_FIELD(a, s32 *, 0x14) = e;
            break;
        case 8:
            M2C_FIELD(c, u32 *, 0x58) = M2C_FIELD(c, u32 *, 0x58) & ~d;
            e = 7;
            break;
        }
    } else {
        e = 7;
    }
    if (e == 7) {
        e = gFileCommandHandlers[b](a);
    }
    if (e == 6) {
        outer = (M2C_FIELD(a, s32 *, 0xc) & 0x4) ? 1 : 0;
        if (outer != 0) {
            b = OS_DisableInterrupts();
            has200 = (M2C_FIELD(c, s32 *, 0x1c) & 0x200) ? 1 : 0;
            if (has200 != 0) {
                do {
                    OS_SleepThread((u8 *)c + 0xc);
                    if (M2C_FIELD(c, s32 *, 0x1c) & 0x200) {
                        has200 = one;
                    } else {
                        has200 = zero;
                    }
                } while (has200 != 0);
                e = M2C_FIELD(a, s32 *, 0x14);
                OS_RestoreInterrupts(b);
                goto done;
            }
        } else {
            goto done;
        }
    }
    outer = (M2C_FIELD(a, s32 *, 0xc) & 0x4) ? 1 : 0;
    if (outer == 0) {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) & ~0x100;
        CompleteFileRequest(a, e);
    } else {
        M2C_FIELD(c, s32 *, 0x1c) = M2C_FIELD(c, s32 *, 0x1c) & ~0x200;
        M2C_FIELD(a, s32 *, 0x14) = e;
    }
done:
    return e;
}

s32 CompareNamesNoCase(u8 *a,u8 *b,u32 n) {u32 i,x,y;for(i=0;i<n;i++){x=a[i]-0x41;y=b[i]-0x41;if(x<=25)x+=32;if(y<=25)y+=32;if(x!=y)return x-y;}return 0;}

s32 func_0200a28c(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_SleepThread(void *);
    M2C_UNK OS_RestoreInterrupts(s32);
    void *temp_r4;
    s32 var_r0;
    u32 var_r0_2;
    unsigned long var_r0_3;
    s32 temp_r5;

    temp_r4 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r4, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x1C) | 0x200);
    var_r0 = M2C_FIELD(temp_r4, s32 (**)(void *, M2C_UNK, s32, s32), 0x50)(temp_r4, arg1, M2C_FIELD(arg0, s32 *, 4), arg2);
    switch (var_r0) {                               /* irregular */
    case 0:
    case 1:
        M2C_FIELD(temp_r4, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x1C) & ~0x200);
        break;
    case 6:
        temp_r5 = OS_DisableInterrupts();
        if (M2C_FIELD(temp_r4, s32 *, 0x1C) & 0x200) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 != 0) {
            do {
                OS_SleepThread(temp_r4 + 0xC);
                if (M2C_FIELD(temp_r4, s32 *, 0x1C) & 0x200) {
                    var_r0_3 = 1;
                } else {
                    var_r0_3 = 0;
                }
            } while (var_r0_3 != 0);
        }
        OS_RestoreInterrupts(temp_r5);
        var_r0 = M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x14);
        break;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + arg2);
    return var_r0;
}

void StartDirectoryRead(void *arg0, s32 arg1) {
    M2C_UNK ExecuteFileCommand(void *, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) | 4);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = arg1;
    ExecuteFileCommand(arg0, 2);
}

void func_0200a380(void *p){
s32 a,b,c;void *q;
a=M2C_FIELD(p,s32 *,0x2c);b=M2C_FIELD(p,s32 *,0x38);
q=M2C_FIELD(p,void **,8);c=M2C_FIELD(p,s32 *,0x30);
M2C_FIELD(p,s32 *,0x2c)=a+b;
M2C_FIELD(q,void (**)(void *,s32,s32,s32),0x48)(q,c,a,b);
}

void func_0200a3ac(void *p){
s32 a,b,c;void *q;
a=M2C_FIELD(p,s32 *,0x2c);b=M2C_FIELD(p,s32 *,0x38);
q=M2C_FIELD(p,void **,8);c=M2C_FIELD(p,s32 *,0x30);
M2C_FIELD(p,s32 *,0x2c)=a+b;
M2C_FIELD(q,void (**)(void *,s32,s32,s32),0x4c)(q,c,a,b);
}

s32 func_0200a3d8(void *p) {
void *q=M2C_FIELD(p,void **,8);
u32 out[2], in[2]; s32 r; u32 *v=(u32 *)((u8 *)p+0x30);
in[0]=(u32)q;
in[1]=M2C_FIELD(q,u32 *,0x34)+(M2C_FIELD(v,u16 *,4)<<3);
r=func_0200a28c(in,(M2C_UNK)out,8);
if(!r){
*(UnkA3Block *)((u8 *)p+0x20)=*(UnkA3Block *)v;
if(!M2C_FIELD(v,u16 *,6)&&!v[2]){
M2C_FIELD(p,u16 *,0x26)=M2C_FIELD(out,u16 *,4);
M2C_FIELD(p,u32 *,0x28)=M2C_FIELD(q,u32 *,0x34)+out[0];
}
M2C_FIELD(p,u32 *,0x2c)=M2C_FIELD(out,u16 *,6)&0xfff;
}
return r;
}

s32 func_0200a470(void *p){
void *q=M2C_FIELD(p,void **,0x30);
u32 in[2];u8 header;u16 extra;s32 r;
in[0]=M2C_FIELD(p,u32 *,8);in[1]=M2C_FIELD(p,u32 *,0x28);
r=func_0200a28c(in,(M2C_UNK)&header,1);if(r)return r;
M2C_FIELD(q,u32 *,0x10)=header&127;
M2C_FIELD(q,u32 *,12)=(header>>7)&1;
if(!M2C_FIELD(q,u32 *,0x10))return 1;
if(!M2C_FIELD(p,u32 *,0x34)){
r=func_0200a28c(in,(M2C_UNK)((u8*)q+20),M2C_FIELD(q,u32 *,0x10));if(r)return r;
((u8*)q+M2C_FIELD(q,u32 *,0x10))[20]=0;
}else in[1]+=M2C_FIELD(q,u32 *,0x10);
if(M2C_FIELD(q,u32 *,12)){
r=func_0200a28c(in,(M2C_UNK)&extra,2);if(r)return r;
M2C_FIELD(q,u32 *,0)=M2C_FIELD(p,u32 *,8);
M2C_FIELD(q,u16 *,4)=extra&0xfff;
M2C_FIELD(q,u16 *,6)=0;M2C_FIELD(q,u32 *,8)=0;
}else{
M2C_FIELD(q,u32 *,0)=M2C_FIELD(p,u32 *,8);
M2C_FIELD(q,u32 *,4)=M2C_FIELD(p,u16 *,0x26);
M2C_FIELD(p,u16 *,0x26)+=1;
}
M2C_FIELD(p,u32 *,0x28)=in[1];return r;
}

/* Resolves the path at request+0x3c one component at a time (handling "." and
 * "..") against the directory listing and stores the matching file or
 * directory entry at request+0x44; wantDirectory asks for a directory. */
s32 ResolvePathEntry(void *request) {
    s32 ExecuteFileCommand(void *, s32);
    void StartDirectoryRead(void *, s32);
    s32 CompareNamesNoCase(u8 *, u8 *, u32);
    u8 *path = M2C_FIELD(request, u8 **, 0x3c);
    s32 wantDirectory = M2C_FIELD(request, s32 *, 0x40);
    s32 isNameChar, firstChar, kind, nameLength;
    PathEntry entry;

    ExecuteFileCommand(request, 2);
    firstChar = *path;
    while (firstChar != 0) {
        nameLength = 0;
        {
            s32 one = 1, zero = 0;
            goto scan;
        next:
            nameLength++;
        scan:
            kind = path[nameLength];
            isNameChar = zero;
            if (kind != 0 && kind != 47 && kind != 92) isNameChar = one;
            if (isNameChar) goto next;
        }
        if (kind != 0 || wantDirectory != 0) kind = 1;
        if (nameLength == 0) return 1;
        if (firstChar == 46) {
            if (nameLength == 1) { path++; goto advance; }
            if ((nameLength == 2) & (path[1] == 46)) {
                if (M2C_FIELD(request, u16 *, 0x24) != 0)
                    StartDirectoryRead(request, M2C_FIELD(request, s32 *, 0x2c));
                path += 2; goto advance;
            }
        }
        if (nameLength > 127) return 1;
        M2C_FIELD(request, void **, 0x30) = &entry;
        M2C_FIELD(request, u32 *, 0x34) = 0;
        for (;;) {
            if (ExecuteFileCommand(request, 3) != 0) return 1;
            if (kind == entry.kind && nameLength == entry.length &&
                CompareNamesNoCase(path, entry.name, nameLength) == 0) break;
        }
        if (kind) {
            *(UnkA3Block *)((u8 *)request + 0x30) = entry.block;
            path += nameLength;
            ExecuteFileCommand(request, 2);
        } else {
            u32 *fileIdOut;
            if (wantDirectory) return 1;
            fileIdOut = *(u32 * volatile *)((u8 *)request + 0x44);
            {
                u32 b, a;
                a = *(volatile u32 *)&entry.block.a;
                b = *(volatile u32 *)&entry.block.b;
                *(volatile u32 *)&fileIdOut[0] = a;
                fileIdOut[1] = b;
            }
            return 0;
        }
    advance:
        path += (*path != 0);
        firstChar = *path;
    }
    if (!wantDirectory) return 1;
    *(UnkA3Block *)M2C_FIELD(request, void **, 0x44) =
        *(UnkA3Block *)((u8 *)request + 0x20);
    return 0;
}

void func_0200a780(void *arg0) { (void)arg0; }

s32 func_0200ab2c(void *p) {
void *q=M2C_FIELD(p,void **,8); u32 n=M2C_FIELD(p,u32 *,0x34); u32 off=(n<<3); u32 out[2],in[2]; s32 r;
if(off>=M2C_FIELD(q,u32 *,0x30)) return 1;
in[0]=(u32)q; in[1]=M2C_FIELD(q,u32 *,0x2c)+off;
r=func_0200a28c(in,(M2C_UNK)out,8); if(r)return r;
M2C_FIELD(p,u32 *,0x30)=out[0]; M2C_FIELD(p,u32 *,0x34)=out[1]; M2C_FIELD(p,u32 *,0x38)=n;
return ExecuteFileCommand(p,7);
}

s32 func_0200abac(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    return 0;
}

s32 func_0200abd4(void) {
    return 0;
}

#pragma opt_propagation off
u32 func_0200abdc(u8 *p,s32 n){u32 result=0; s32 i,shift;u32 c;if(n<=3){i=0;if(n>0){shift=0;do{c=p[i];if(!c)break;c=c-0x41;if(c<=25)c+=0x61;else c+=0x41;result|=c<<shift;i++;shift+=8;}while(i<n);}}return result;}
#pragma opt_propagation reset
s32 func_0200ac34(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK MI_CpuCopy8(s32, M2C_UNK, M2C_UNK);
    MI_CpuCopy8(M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg1, arg3);
    return 0;
}

s32 func_0200ac50(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    MI_CpuCopy8(arg1, M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg3);
    return 0;
}

s32 func_0200ac70(s32 a,s32 b,s32 c,s32 d){MI_CpuCopy8(c,b,d);return 0;}

#pragma opt_common_subs off
/* Picks the next pending request of a file after an operation finishes: drops
 * the queue when the file is being cancelled, otherwise arms the idle callback,
 * notifies the caller's callback and returns the request that has to run (or
 * wakes the request that is already waiting and returns NULL). */
M2C_UNK *GetNextFileRequest(void *file) {
    M2C_UNK OS_WakeupThread(void *);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    void CompleteFileRequest(void *, s32);
    M2C_UNK InitFileRequest(M2C_UNK *);
    s32 irq;
    s32 irq2;
    M2C_UNK *request;
    M2C_UNK *pending;
    M2C_UNK *next;
    s32 cancelling;
    s32 aborting;
    s32 busy;
    s32 notifyPending;
    s32 completed;
    s32 notifyPending2;
    s32 aborting2;
    s32 queued;
    s32 notifyNow;
    u8 idleRequest[0x48];

    irq = OS_DisableInterrupts();
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_CANCELLING) {
        cancelling = 1;
    } else {
        cancelling = 0;
    }
    if (cancelling != 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_CANCELLING);
        pending = M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS);
        if (pending != NULL) {
            do {
                next = M2C_FIELD(pending, M2C_UNK **, 4);
                if (M2C_FIELD(pending, s32 *, FS_REQ_FLAGS) & FS_REQ_QUEUED) {
                    queued = 1;
                } else {
                    queued = 0;
                }
                if (queued != 0) {
                    if (M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS) == pending) {
                        M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS) = next;
                    }
                    CompleteFileRequest(pending, 3);
                    if (next == NULL) {
                        next = M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS);
                    }
                }
                pending = next;
            } while (next != NULL);
        }
    }
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_ABORTING) {
        aborting = 1;
    } else {
        aborting = 0;
    }
    if (aborting == 0) {
        if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_BUSY) {
            busy = 1;
        } else {
            busy = 0;
        }
        if (busy == 0) {
            request = M2C_FIELD(file, M2C_UNK **, FS_FILE_REQUESTS);
            if (request != NULL) {
                if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_NOTIFY_PENDING) {
                    notifyPending = 1;
                } else {
                    notifyPending = 0;
                }
                if (notifyPending == 0) {
                    notifyNow = 1;
                } else {
                    notifyNow = 0;
                }
                if (notifyNow != 0) {
                    M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) | FS_FILE_NOTIFY_PENDING);
                }
                OS_RestoreInterrupts(irq);
                if ((notifyNow != 0) && (M2C_FIELD(file, s32 *, FS_FILE_EVENTS) & FS_EVENT_REQUEST_MASK)) {
                    M2C_FIELD(file, M2C_UNK (**)(M2C_UNK *, M2C_UNK), FS_FILE_CALLBACK)(request, FS_EVENT_REQUEST);
                }
                irq2 = OS_DisableInterrupts();
                M2C_FIELD(request, s32 *, FS_REQ_FLAGS) = (s32) (M2C_FIELD(request, s32 *, FS_REQ_FLAGS) | FS_REQ_NOTIFIED);
                if (*(volatile s32 *)((s8 *)request + FS_REQ_FLAGS) & FS_REQ_COMPLETED) {
                    completed = 1;
                } else {
                    completed = 0;
                }
                if (completed != 0) {
                    OS_WakeupThread((u8 *)request + FS_REQ_QUEUE);
                    OS_RestoreInterrupts(irq2);
                    return NULL;
                }
                OS_RestoreInterrupts(irq2);
                return request;
            }
        }
        goto block_41;
    }
block_41:
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_NOTIFY_PENDING) {
        notifyPending2 = 1;
    } else {
        notifyPending2 = 0;
    }
    if (notifyPending2 != 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) (M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_NOTIFY_PENDING);
        if (M2C_FIELD(file, s32 *, FS_FILE_EVENTS) & FS_EVENT_IDLE_MASK) {
            InitFileRequest(idleRequest);
            M2C_FIELD(idleRequest, void **, FS_REQ_FILE) = file;
            M2C_FIELD(file, M2C_UNK (**)(M2C_UNK *, M2C_UNK), FS_FILE_CALLBACK)(idleRequest, FS_EVENT_IDLE);
        }
    }
    if (M2C_FIELD(file, s32 *, FS_FILE_STATE) & FS_FILE_ABORTING) {
        aborting2 = 1;
    } else {
        aborting2 = 0;
    }
    if (aborting2 != 0) {
        M2C_FIELD(file, s32 *, FS_FILE_STATE) = (s32) ((M2C_FIELD(file, s32 *, FS_FILE_STATE) & ~FS_FILE_ABORTING) | FS_FILE_BUSY);
        OS_WakeupThread(file + FS_FILE_WAIT_QUEUE);
    }
    OS_RestoreInterrupts(irq);
    return NULL;
}
#pragma opt_common_subs reset
