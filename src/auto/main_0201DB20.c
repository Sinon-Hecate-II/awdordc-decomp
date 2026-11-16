/* 14 functions from 0x0201DB20 to 0x0201E944 (main), found by ds-decomp. */
#include "common.h"
#include "dhcp.h"
#include "tcp_socket.h"
static inline u32 NextPacketRandom(void) {
 extern M2C_UNK gNetStack;
 M2C_FIELD(&gNetStack,u64*,0x68)=M2C_FIELD(&gNetStack,u64*,0x70)*M2C_FIELD(&gNetStack,u64*,0x68)+M2C_FIELD(&gNetStack,u64*,0x78);
 return M2C_FIELD(&gNetStack,u64*,0x68)>>32;
}
static inline u16 PacketSwap(u16 x) { return (x>>8)|(x<<8); }
static inline u32 PacketRead32(const u8 *p) {
    u16 hi = (p[0] << 8) | p[1];
    u16 lo = (p[2] << 8) | p[3];
    return ((u32)hi << 16) | lo;
}
static inline s32 PacketTransactionMatches(const u16 *p, const u32 *expected) {
    u16 lo = p[1];
    u16 hi = p[0];
    u32 actual = ((u32)PacketSwap(hi) << 16) | PacketSwap(lo);
    return actual == *expected;
}
static inline void PacketPut32(u8 *p,u32 x) { *(u16*)p=PacketSwap(x>>16); *(u16*)(p+2)=PacketSwap(x); }
static inline void PacketAddress(u8 *p) { extern M2C_UNK gLocalMacAddress; void MI_CpuCopy8(s32,u8*,s32); MI_CpuCopy8((s32)&gLocalMacAddress,p,6); }

u32 func_0201db20(s32 a, s32 b) {
    extern M2C_UNK gSocketManager;
    M2C_UNK MemMove(s32, s32, u32);
    void *p;
    u32 n, used;
    p = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (p) {
        n = M2C_FIELD(p, u32 *, 0x60);
        if (n) {
            used = func_0201da4c(M2C_FIELD(p, s32 *, 0x5C), n, a, b);
            n = M2C_FIELD(p, u32 *, 0x60);
            if (used < n) {
                MemMove(M2C_FIELD(p, s32 *, 0x5C), M2C_FIELD(p, s32 *, 0x5C) + used, n - used);
                M2C_FIELD(p, u32 *, 0x60) -= used;
                return 0;
            }
            M2C_FIELD(p, u32 *, 0x60) = 0;
            return used - n;
        }
        return func_0201da4c(a, b, 0, 0);
    }
    return 0;
}

s32 func_0201dbb8(void) {
    extern M2C_UNK gSocketManager;
    s32 func_02024f20(void *);
    void *p;
    s32 n;
    p = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (p) {
        if (M2C_FIELD(p, u8 *, 9)) return func_02024f20(p);
        n = M2C_FIELD(p, s32 *, 0x44);
        if (n != 0) goto done;
        {
            u8 c = M2C_FIELD(p, u8 *, 8);
            if (c == 4) goto done;
            if ((u8)(c + 246) > 1) goto fail;
        }
    done:
        return n;
    fail:
        return -1;
    }
    return 0;
}

void func_0201dc28(void) {
    M2C_UNK func_0201da4c(s32, s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK gSocketManager;
    s32 temp_r1;
    void *temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (temp_r4 != NULL) {
        temp_r1 = M2C_FIELD(temp_r4, s32 *, 0x60);
        if (temp_r1 != 0) {
            func_0201da4c(M2C_FIELD(temp_r4, s32 *, 0x5C), temp_r1, 0, 0);
            M2C_FIELD(temp_r4, s32 *, 0x60) = 0;
        }
    }
}

void func_0201dc68(void) {
    extern M2C_UNK gNetStack;
    void func_0201aca0(s32);
    void func_02006030(s32);
    u64 GetSystemTick(void);
    void func_0201a134(s32);
    s32 start;
    M2C_FIELD(&gNetStack, void (**)(void), 0x18)();
    if (!M2C_FIELD(&gNetStack, s32 *, 0x50)) return;
    func_0201aca0(M2C_FIELD(&gNetStack, s32 *, 0x50));
    func_02006030(100);
    func_0201aca0(M2C_FIELD(&gNetStack, s32 *, 0x50));
    start = (u32)(GetSystemTick() >> 16);
    goto check;
    loop:
    {
        if (M2C_FIELD(&gNetStack, u8 *, 1)) {
            func_0201a134(4);
            return;
        }
        func_02006030(100);
    }
    check:
    if (!M2C_FIELD(&gNetStack, s32 (**)(void), 0x48)()) return;
    if ((s32)((u32)(GetSystemTick() >> 16) - start) < 23) goto loop;
}

void func_0201dd08(void) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK gSocketManager;
    extern u8 data_02137370[];
    extern u8 data_021375b8[];
    extern u8 data_0213793c[];
    extern u8 data_021377bc[];
    extern u8 gArpCache[];
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    u64 GetSystemTick(void);
    void func_02006030(s32);
    void func_0201dc68(void);
    s32 func_0201e754(void);
    s32 func_0201e7ac(u32 *, s32);
    void func_0201a134(s32);
    void func_0201d138(void *);
    void func_0201d14c(void);
    void func_0201aca0(s32);
    void func_020251b8(u32);
    void func_0201e8a8(void);
    void TaskWake(void *);

    s32 state;
    u32 wait;
    register s32 flag;
    register s32 count;
    u32 tick;

    M2C_FIELD(&gNetStack, u32 *, 0x44) = 0;
    MI_CpuFill8((s32)data_02137370, 0, 0x64);
    M2C_FIELD(&gNetStack, s32 *, 0x11c) = 0x180;
    M2C_FIELD(&gNetStack, void **, 0x120) = data_0213793c;
    M2C_FIELD(&gNetStack, s32 *, 0x128) = 0x180;
    M2C_FIELD(&gNetStack, void **, 0x12c) = data_021377bc;
    func_0201d138(data_02137370);
    count = 1;
    flag = 1;
    wait = M2C_FIELD(&gNetStack, s32 *, 0xc) = 1;
    state = 0;
    for (;;) {
        func_02006030(0x3e8);
        if (M2C_FIELD(&gNetStack, u32 *, 0x44) != 0) break;
        tick = (u32)(GetSystemTick() >> 16);
        if (M2C_FIELD(&gNetStack, s32 (**)(void), 0x48)() != 0) {
            if (--wait == 0) {
                if (M2C_FIELD(&gNetStack, u32 *, 0x10) & 1) {
                    if (state == 0) {
                        func_0201dc68();
                        state = 1;
                    }
                } else {
                    switch (state) {
                    case 0:
                        if (flag) {
                            M2C_FIELD(&gNetStack, s32 *, 0xc) = 2;
                            flag = 0;
                        }
                        if (func_0201e754()) {
                            if (func_0201e7ac(&wait, 0)) goto connected;
                        }
                        func_0201dc68();
                        state = 3;
                        break;
                    connected:
                        state = 1;
                        break;
                    case 1:
                        if (!func_0201e7ac(&wait, 1)) {
                            if (wait < 0x3c) state = 2;
                        }
                        break;
                    case 2:
                        if (func_0201e7ac(&wait, 2)) {
                            state = 1;
                        } else if (wait < 0x3c) {
                            func_0201a134(3);
                            count = 1;
                            wait = 1;
                            state = 0;
                        }
                        break;
                    case 3:
                        break;
                    }
                }
            }
        } else {
            func_0201a134(1);
            count = 1;
            wait = 1;
            state = 0;
        }
        {
            s32 i;
            u8 *e = gArpCache;
            for (i = 0; i < 8; i++, e += 0xc) {
                if (M2C_FIELD(e, u32 *, 0) != 0) {
                    if ((s16)(tick - M2C_FIELD(e, u16 *, 0xa)) > 0x3bd) {
                        M2C_FIELD(e, u32 *, 0) = 0;
                    }
                }
            }
        }
        { s32 address = M2C_FIELD(&gNetStack, s32 *, 0x2c);
        if (address != 0) {
            if (--count == 0) {
                func_0201aca0(address);
                count = 0x69;
            }
        }
        }
        {
            void *node = M2C_FIELD(&gSocketManager, void **, 8);
            while (node) {
                u8 *obj = M2C_FIELD(node, u8 **, 0xa4);
                if (obj && M2C_FIELD(obj, u32 *, 0)) {
                    s32 kind = M2C_FIELD(obj, u8 *, 8);
                    if (kind == 3 && (s32)(tick - M2C_FIELD(obj, u32 *, 0x10)) > 0x27) {
                            M2C_FIELD(obj, u8 *, 8) = 1;
                            M2C_FIELD(obj, u16 *, 0x18) = M2C_FIELD(obj, u16 *, 0x1a);
                            M2C_FIELD(obj, u32 *, 0x1c) = M2C_FIELD(obj, u32 *, 0x20);
                    } else if (kind == 2 && (s32)(tick - M2C_FIELD(obj, u32 *, 0x10)) > 0x27) {
                            if (M2C_FIELD(obj, u32 *, 4) == 1) {
                                M2C_FIELD(obj, u8 *, 8) = 0;
                                M2C_FIELD(obj, u32 *, 4) = 0;
                                TaskWake(M2C_FIELD(obj, void **, 0));
                            }
                    } else if (kind != 4 && M2C_FIELD(obj, u32 *, 4) == 2) {
                        M2C_FIELD(obj, u32 *, 4) = 0;
                        TaskWake(M2C_FIELD(obj, void **, 0));
                    }
                }
                node = M2C_FIELD(node, void **, 0x68);
            }
        }
        {
            u8 *e;
            s32 i;
            e = data_021375b8;
            for (i = 0; i < 8; i++, e += 0x38) {
                if (M2C_FIELD(e, u16 *, 4) != 0) {
                    if ((s32)(tick - M2C_FIELD(e, u32 *, 0x2c)) > 0xef) {
                        ((void (*)(u32))M2C_FIELD(&gNetStack, u32 *, 0x40))(M2C_FIELD(e, u32 *, 0x34));
                        M2C_FIELD(e, u16 *, 4) = 0;
                    }
                }
            }
        }
        func_020251b8(tick);
        if (M2C_FIELD(&gNetStack, u32 *, 0x3c) != 0) {
            ((void (*)(void))M2C_FIELD(&gNetStack, u32 *, 0x3c))();
        }
    }
    if (!(M2C_FIELD(&gNetStack, u32 *, 0x10) & 1) && state != 3) func_0201e8a8();
    func_0201d14c();
}

#pragma opt_common_subs off
/* Builds a BOOTP/DHCP request packet at `packet`: a fixed header carrying a
 * fresh transaction id (also returned through `xidOut`), the local MAC address
 * as the client hardware address, and the options that follow the magic cookie
 * (message type `msgType`, client identifier, host name and the parameter
 * request list).  Returns the address just past the options. */
u8 *BuildDhcpPacket(u8 *packet, s32 msgType, s32 xidOut) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK gLocalMacAddress;
    extern M2C_UNK gDhcpHostName;
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    void MI_CpuCopy8(s32, u8 *, s32);
    u32 xid;

    MI_CpuFill8((s32)packet, 0, DHCP_OFF_OPTIONS);
    *(u16 *)packet = 0x101;
    packet[DHCP_OFF_HLEN] = 6;
    xid = NextPacketRandom();
    if (xidOut) *(u32 *)xidOut = xid;
    *(u16 *)(packet + DHCP_OFF_XID) = PacketSwap(xid >> 16);
    *(u16 *)(packet + DHCP_OFF_XID + 2) = PacketSwap(xid);
    *(u16 *)(packet + DHCP_OFF_CIADDR) = PacketSwap(M2C_FIELD(&gNetStack, u32 *, NETSTACK_LOCAL_IP) >> 16);
    *(u16 *)(packet + DHCP_OFF_CIADDR + 2) = PacketSwap(M2C_FIELD(&gNetStack, u32 *, NETSTACK_LOCAL_IP));
    MI_CpuCopy8((s32)&gLocalMacAddress, packet + DHCP_OFF_CHADDR, DHCP_HWADDR_LEN);
    *(u16 *)(packet + DHCP_OFF_OPTIONS) = DHCP_MAGIC_W0;
    *(u16 *)(packet + DHCP_OFF_OPTIONS + 2) = DHCP_MAGIC_W1;
    *(u16 *)(packet + DHCP_OFF_OPTIONS + 4) = 0x0135;
    packet[0xf2] = msgType;
    packet[0xf3] = DHCP_OPT_CLIENT_ID;
    packet[0xf4] = 7;
    packet[0xf5] = 1;
    MI_CpuCopy8((s32)&gLocalMacAddress, packet + 0xf6, DHCP_HWADDR_LEN);
    packet[0xfc] = DHCP_OPT_HOSTNAME;
    packet[0xfd] = 10;
    MI_CpuCopy8((s32)&gDhcpHostName, packet + 0xfe, 10);
    packet[0x108] = DHCP_OPT_PARAM_REQ;
    packet[0x109] = 3;
    packet[0x10a] = DHCP_OPT_SUBNET;
    packet[0x10b] = DHCP_OPT_ROUTER;
    packet[0x10c] = DHCP_OPT_DNS;
    return packet + 0x10d;
}
#pragma opt_common_subs reset
s32 func_0201e204(M2C_UNK arg0, u32 arg1, s32 arg2, u32 arg3) {
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    s32 temp_r4;
    s32 var_r5;

    var_r5 = arg2;
    if (arg3 < arg1) {
        temp_r4 = arg1 - arg3;
        MI_CpuFill8(var_r5, arg0, temp_r4);
        var_r5 += temp_r4;
    }
    return var_r5;
}

#pragma opt_common_subs off
s32 func_0201e238(void) {
extern M2C_UNK gNetStack; extern u8 data_021377e6[];
u8 *BuildDhcpPacket(u8 *,s32,s32);
u8 *p; s32 result; s32 base=(s32)data_021377e6;
p=BuildDhcpPacket((u8 *)base,1,(s32)&result);
if(M2C_FIELD(&gNetStack,u32 *,0x34)) {
p[0]=0x32; p[1]=4;
p[2]=(u16)(M2C_FIELD(&gNetStack,u32 *,0x34)>>16)>>8;
p[3]=M2C_FIELD(&gNetStack,u32 *,0x34)>>16;
p[4]=(u16)M2C_FIELD(&gNetStack,u32 *,0x34)>>8;
p[5]=M2C_FIELD(&gNetStack,u32 *,0x34);
p+=6;
}
*p++=255;
p=(u8 *)func_0201e204(0,300,(s32)p,(s32)p-base);
func_0201db20(base,(s32)p-base);
return result;
}
#pragma opt_common_subs off
s32 func_0201e2fc(s32 a){
extern M2C_UNK gNetStack;extern u8 data_021377e6[];
u8 *BuildDhcpPacket(u8 *,s32,s32);
u8 *p;u16 hi;s32 result;s32 base=(s32)data_021377e6;
p=BuildDhcpPacket((u8 *)base,3,(s32)&result);
if(a==0){
p[0]=0x32;p[1]=4;
hi=M2C_FIELD(&gNetStack,u32 *,0x34)>>16;p[2]=hi>>8;
p[3]=M2C_FIELD(&gNetStack,u32 *,0x34)>>16;
p[4]=(u16)M2C_FIELD(&gNetStack,u32 *,0x34)>>8;
p[5]=M2C_FIELD(&gNetStack,u32 *,0x34);
p[6]=0x36;p[7]=4;
hi=M2C_FIELD(&gNetStack,u32 *,0x20)>>16;p[8]=hi>>8;
p[9]=M2C_FIELD(&gNetStack,u32 *,0x20)>>16;
p[10]=(u16)M2C_FIELD(&gNetStack,u32 *,0x20)>>8;
p[11]=M2C_FIELD(&gNetStack,u32 *,0x20);
p+=12;
}
*p++=255;
p=(u8 *)func_0201e204(0,300,(s32)p,(s32)p-base);
func_0201db20(base,(s32)p-base);
return result;
}
#pragma opt_common_subs off
s32 func_0201e404(s32 arg0, s32 arg1) {
    u64 GetSystemTick(void);
    s32 func_0201dbb8(void);
    void func_0201a238(void);
    s32 func_0201d618(s32 *);
    s32 MacAddressesDiffer(u16 *, u16 *);
    void func_0201d70c(s32);
    extern M2C_UNK gNetStack;
    extern M2C_UNK gLocalMacAddress;

    s32 slots[2];
    u32 timer;
    s32 result;
    s32 limit;
    s32 len;
    u8 *endb;
    u8 *cur;
    u8 *q;
    u8 tag;
    u32 combo;
    u32 now;
    u8 flen;
    u16 t0, t1;
    u32 xid;

    slots[0] = arg0;
    limit = (arg1 + 1) * 15;
    timer = (u32)(GetSystemTick() >> 16);
    result = 0;
    goto timer_check;

top_loop:
    if (func_0201dbb8() == 0) {
        func_0201a238();
    } else {
        q = (u8 *)func_0201d618(&slots[1]);
        if ((u32)slots[1] <= 0xF0) goto fail;
        if (q[0] != 2) goto fail;
        if (!PacketTransactionMatches((u16 *)(q+4), (u32 *)slots)) goto fail;
        if (MacAddressesDiffer((u16 *)(q + 0x1C), (u16 *)&gLocalMacAddress) != 0) goto fail;

        combo = PacketRead32(q+0x10);
        result = 3;

        cur = q + 0xF0;
        endb = q + slots[1];
        if (q[0xEC] != 0x63 || q[0xED] != 0x82 || q[0xEE] != 0x53) goto fail;
        cur = q + 0xF0;
        if (q[0xEF] != 0x63) goto fail;


        goto option_check;
        while (1) {
            if (tag == 0) goto option_check;
            switch (tag) {
            case 0x01:
                M2C_FIELD(&gNetStack, u32 *, 0x1C) =
                    PacketRead32(cur+1);
                break;
            case 0x03:
                M2C_FIELD(&gNetStack, u32 *, 0x2C) =
                    PacketRead32(cur+1);
                break;
            case 0x06:
                if (cur[0] < 8) {
                    M2C_FIELD(&gNetStack, u32 *, 0x64) = 0;
                } else {
                    M2C_FIELD(&gNetStack, u32 *, 0x64) =
                        PacketRead32(cur+5);
                }
                M2C_FIELD(&gNetStack, u32 *, 0x60) =
                    PacketRead32(cur+1);
                break;
            case 0x33:
                M2C_FIELD(&gNetStack, u32 *, 0x4c) = PacketRead32(cur+1);
                break;
            case 0x35:
                switch (cur[1]) {
                case 2:
                    result = 1;
                    M2C_FIELD(&gNetStack, u32 *, 0x34) = combo;
                    break;
                case 5:
                    result = 2;
                    M2C_FIELD(&gNetStack, u32 *, 0x50) = combo;
                    break;
                }
                break;
            case 0x36:
                M2C_FIELD(&gNetStack, u32 *, 0x20) =
                    PacketRead32(cur+1);
                break;
            default:
                break;
            }

            flen = cur[0];
            cur += flen + 1;
        option_check:
            if (cur >= endb) goto fail;
            tag = *cur++;
            if (tag == 0xFF) goto fail;
        }
        fail:
        func_0201d70c(slots[1]);
    }

timer_check:
    if (M2C_FIELD(&gNetStack, s32 (**)(void), 0x48)() == 0) goto final;
    if (result != 0) goto final;
    now = (u32)(GetSystemTick() >> 16);
    if ((s32)(now - timer) < limit) goto top_loop;

final:
    return result;
}
#pragma opt_common_subs reset
s32 func_0201e754(void) {
    M2C_UNK func_0201d164();
    M2C_UNK func_0201d190(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d1f0();
    M2C_UNK func_0201d224();
    s32 func_0201e238();
    s32 func_0201e404(s32, s32);
    s32 temp_r0;
    s32 var_r5;

    func_0201d1f0();
    func_0201d164();
    func_0201d190(0x44, 0x43, -1);
    var_r5 = 0;
loop_1:
    temp_r0 = func_0201e404(func_0201e238(), var_r5);
    if (temp_r0 != 1) {
        var_r5 += 1;
        if (var_r5 < 4) {
            goto loop_1;
        }
    }
    func_0201d224();
    if (temp_r0 == 1) {
        return 1;
    }
    return 0;
}

/* Attempt up to four times to exchange a data packet with a peer.
 * On a peer-data match (result 2) record the peer's size info and return
 * success; otherwise halve the stored timeout and apply a mode-specific floor. */
s32 func_0201e7ac(u32 *out_size, s32 mode) {
    s32 func_0201e2fc(s32);
    extern M2C_UNK gNetStack;
    s32 result;
    s32 attempt;
    u32 timeout;

    func_0201d1f0();
    func_0201d164();
    if (mode == 1) {
        func_0201d190(0x44, 0x43, M2C_FIELD(&gNetStack, s32 *, 0x20));
    } else {
        func_0201d190(0x44, 0x43, -1);
    }
    attempt = 0;
loop_4:
    result = func_0201e404(func_0201e2fc(mode), attempt);
    if (result == 0) {
        attempt += 1;
        if (attempt < 4) {
            goto loop_4;
        }
    }
    func_0201d224();
    if (result == 2) {
        *out_size = (u32) M2C_FIELD(&gNetStack, u32 *, 0x4C) >> 1;
        M2C_FIELD(&gNetStack, u32 *, 0x38) = (u32) ((u32) (M2C_FIELD(&gNetStack, u32 *, 0x4C) * 3) >> 3);
        return 1;
    }
    timeout = (u32) M2C_FIELD(&gNetStack, u32 *, 0x38) >> 1;
    M2C_FIELD(&gNetStack, u32 *, 0x38) = timeout;
    *out_size = timeout;
    switch (mode) {                                 /* irregular */
    case 1:
        if (timeout < 0x3CU) {
            *out_size = 1;
            M2C_FIELD(&gNetStack, u32 *, 0x38) = (u32) ((u32) M2C_FIELD(&gNetStack, u32 *, 0x4C) >> 3);
        }
        break;
    case 2:
        if (timeout < 0x3CU) {
            *out_size = 1;
        }
        break;
    }
    return 0;
}

void func_0201e8a8(void) {
 extern M2C_UNK gNetStack;
 extern u8 data_021377e6[];
 u8 *BuildDhcpPacket(u8 *,s32,s32);
 s32 p; s32 base;
 func_0201d1f0();
 func_0201d164();
 func_0201d190(0x44,0x43,M2C_FIELD(&gNetStack,s32 *,0x20));
 base=(s32)data_021377e6;
 p=(s32)BuildDhcpPacket((u8 *)base,7,0);
 M2C_FIELD(p,u8 *,0)=0xff; p++;
 p=func_0201e204(0,300,(s32)p,p-base);
 func_0201db20((s32)base,p-base);
 func_0201d224();
}

u8 *func_0201e914(u8 *p) {
    u32 c = *p++;
    while (c) {
        if ((c & 0xC0) == 0xC0) return p + 1;
        p += c;
        c = *p++;
    }
    return p;
}

