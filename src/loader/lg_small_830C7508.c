/* Loader_DLL.xex 0x830C7508-0x830FAF78, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char __imp_KeCertMonitorData[];
extern char __imp_KeDebugMonitorData[];
extern char __imp_VdGlobalDevice[];
extern char lbl_83081C18[];
extern char lbl_83089050[];
extern char lbl_83526CC4[];
extern char lbl_8352E934[];
extern char lbl_83544968[];
extern char lbl_83544969[];
extern char lbl_8354496A[];
ts4_word ExGetXConfigSetting();
ts4_word ExRegisterTitleTerminateNotification();
ts4_word KeBugCheck();
ts4_word MmFreePhysicalMemory();
ts4_word NetDll_WSACancelOverlappedIO();
ts4_word NetDll_WSACloseEvent();
ts4_word NetDll_WSACreateEvent();
ts4_word NetDll_WSAEventSelect();
ts4_word NetDll_WSAGetLastError();
ts4_word NetDll_WSAGetOverlappedResult();
ts4_word NetDll_WSARecv();
ts4_word NetDll_WSAResetEvent();
ts4_word NetDll_WSASend();
ts4_word NetDll_WSASetEvent();
ts4_word NetDll_WSASetLastError();
ts4_word NetDll_WSAWaitForMultipleEvents();
ts4_word NetDll_XNetCleanup();
ts4_word NetDll_XNetConnect();
ts4_word NetDll_XNetCreateKey();
ts4_word NetDll_XNetDnsLookup();
ts4_word NetDll_XNetDnsRelease();
ts4_word NetDll_XNetGetBroadcastVersionStatus();
ts4_word NetDll_XNetGetConnectStatus();
ts4_word NetDll_XNetGetDebugXnAddr();
ts4_word NetDll_XNetGetEthernetLinkStatus();
ts4_word NetDll_XNetGetOpt();
ts4_word NetDll_XNetGetTitleXnAddr();
ts4_word NetDll_XNetInAddrToServer();
ts4_word NetDll_XNetInAddrToString();
ts4_word NetDll_XNetInAddrToXnAddr();
ts4_word NetDll_XNetQosGetListenStats();
ts4_word NetDll_XNetQosListen();
ts4_word NetDll_XNetQosRelease();
ts4_word NetDll_XNetQosServiceLookup();
ts4_word NetDll_XNetRandom();
ts4_word NetDll_XNetRegisterKey();
ts4_word NetDll_XNetServerToInAddr();
ts4_word NetDll_XNetSetOpt();
ts4_word NetDll_XNetTsAddrToInAddr();
ts4_word NetDll_XNetUnregisterInAddr();
ts4_word NetDll_XNetUnregisterKey();
ts4_word NetDll_XNetXnAddrToInAddr();
ts4_word NetDll_XNetXnAddrToMachineId();
ts4_word NetDll___WSAFDIsSet();
ts4_word NetDll_accept();
ts4_word NetDll_bind();
ts4_word NetDll_closesocket();
ts4_word NetDll_connect();
ts4_word NetDll_getpeername();
ts4_word NetDll_getsockname();
ts4_word NetDll_getsockopt();
ts4_word NetDll_inet_addr();
ts4_word NetDll_ioctlsocket();
ts4_word NetDll_listen();
ts4_word NetDll_recv();
ts4_word NetDll_recvfrom();
ts4_word NetDll_select();
ts4_word NetDll_send();
ts4_word NetDll_sendto();
ts4_word NetDll_setsockopt();
ts4_word NetDll_shutdown();
ts4_word NetDll_socket();
ts4_word VdQuerySystemCommandBuffer();
ts4_word VdShutdownEngines();
ts4_word fn_830A9FA8();
ts4_word fn_830B0710();
ts4_word fn_830BB150();
ts4_word fn_830BBA98();
ts4_word fn_830BBC00();
ts4_word fn_830C0788();
ts4_word fn_830C2800();
ts4_word fn_830C46E8();
ts4_word fn_830C4748();
ts4_word fn_830C47B0();
ts4_word fn_830C48B0();
ts4_word fn_830C4998();
ts4_word fn_830C4B18();
ts4_word fn_830C4C08();
ts4_word fn_830C4CA8();
ts4_word fn_830C4D80();
ts4_word fn_830C4E40();
ts4_word fn_830C60B8();
ts4_word fn_830C7040();
ts4_word fn_830C7758();
ts4_word fn_830C7A68();
ts4_word fn_830C7B40();
ts4_word fn_830C7C18();
ts4_word fn_830C83D8();
ts4_word fn_830C86C0();
ts4_word fn_830C8E38();
ts4_word fn_830C9E70();
ts4_word fn_830C9F00();
ts4_word fn_830C9F90();
ts4_word fn_830CA020();
ts4_word fn_830CA0B0();
ts4_word fn_830CA140();
ts4_word fn_830CA1D0();
ts4_word fn_830CABE0();
ts4_word fn_830CF980();
ts4_word fn_830D9018();
ts4_word fn_830DA0E0();
ts4_word fn_830DA1B8();
ts4_word fn_830DA400();
ts4_word fn_830DC818();
ts4_word fn_830DE8E8();
ts4_word fn_830E1020();
ts4_word fn_830F7188();
ts4_word fn_830F7530();
ts4_word fn_830F7960();
ts4_word fn_830FA930();
ts4_word fn_830FA9F8();
ts4_word fn_830FC338();
ts4_word fn_830FC3C8();
ts4_word fn_830FCCD0();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();
ts4_word fn_8340C4F8();
ts4_word fn_8340D710();
ts4_word fn_8340D830();

/* Loader_DLL.xex 0x830C7508: get u32@0x0, fn_830C46E8 */
ts4_word ts4_get_u32_off0_830C7508(ts4_word a0, ts4_word a1)
{
    return fn_830C46E8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C7520: get u32@0x0, fn_830C4748 */
ts4_word ts4_get_u32_off0_830C7520(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C4748((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830C7538: get u32@0x0, fn_830C47B0 */
ts4_word ts4_get_u32_off0_830C7538(ts4_word a0)
{
    return fn_830C47B0((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C7550: get u32@0x0, fn_830C48B0 */
ts4_word ts4_get_u32_off0_830C7550(ts4_word a0, ts4_word a1)
{
    return fn_830C48B0((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C7568: get u32@0x0, fn_830C4998 */
ts4_word ts4_get_u32_off0_830C7568(ts4_word a0)
{
    return fn_830C4998((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C7580: tailcall fn_830C7A68 */
ts4_word ts4_tailcall_fn_830C7A68_830C7580(ts4_word a0)
{
    return fn_830C7A68((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C7588: get u32@0x0, fn_830C4B18 */
ts4_word ts4_get_u32_off0_830C7588(ts4_word a0)
{
    return fn_830C4B18((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C75A0: get u32@0x0, fn_830C4C08 */
ts4_word ts4_get_u32_off0_830C75A0(ts4_word a0, ts4_word a1)
{
    return fn_830C4C08((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C7600: get u32@0x0, fn_830C4CA8 */
ts4_word ts4_get_u32_off0_830C7600(ts4_word a0)
{
    return fn_830C4CA8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C7630: call_seq u32@0x0, fn_830C60B8, u32@0x80 */
ts4_word ts4_call_seq_u32_off0_830C7630(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    fn_830C60B8((ts4_word)((((int)t1 * 9936) + a0) + 16));
    return ((*(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 128)) + -1);
}

/* Loader_DLL.xex 0x830C7688: if_get u32@0x0, u32@0x60, u32@0x7c */
ts4_word ts4_if_get_u32_off0_830C7688(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 96);
    if ((int)t2 < 0) {
        return 0;
    }
    return ((*(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 124)) + (a1 << 3));
}

/* Loader_DLL.xex 0x830C76B8: get u32@0x0, fn_830C4D80 */
ts4_word ts4_get_u32_off0_830C76B8(ts4_word a0)
{
    return fn_830C4D80((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C76D0: get u32@0x0, fn_830C4E40 */
ts4_word ts4_get_u32_off0_830C76D0(ts4_word a0)
{
    return fn_830C4E40((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C76E8: tailcall fn_830C7040 */
ts4_word ts4_tailcall_fn_830C7040_830C76E8(ts4_word a0)
{
    return fn_830C7040((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C76F0: tailcall fn_830C7B40 */
ts4_word ts4_tailcall_fn_830C7B40_830C76F0(ts4_word a0)
{
    return fn_830C7B40((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C76F8: tailcall fn_830C7C18 */
ts4_word ts4_tailcall_fn_830C7C18_830C76F8(ts4_word a0)
{
    return fn_830C7C18((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C78A8: call_seq fn_830C7758 */
ts4_word ts4_call_seq_fn_830C7758_830C78A8(ts4_word a0)
{
    fn_830C7758((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x830C8618: get u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4_get_u32_off4_830C8618(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)0;
    return fn_830C83D8((ts4_word)(t1 + a0), (ts4_word)t2, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C8698: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C8698(ts4_word a0, ts4_word a1)
{
    return fn_8340C4F8((ts4_word)a1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830C86A8: set u32@0x0, u32@0x14, u32@0x10 */
void ts4_set_u32_off0_830C86A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C8E00: call_seq fn_830C86C0 */
ts4_word ts4_call_seq_fn_830C86C0_830C8E00(ts4_word a0)
{
    ts4_word loc50[10];
    ts4_word t1;

    loc50[0] = (ts4_word)a0;
    loc50[5] = (ts4_word)32;
    loc50[4] = (ts4_word)0;
    t1 = fn_830C86C0((ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830C90B0: tailcall fn_830C8E38 */
ts4_word ts4_tailcall_fn_830C8E38_830C90B0(ts4_word a0)
{
    return fn_830C8E38((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9438: call_seq fn_830C86C0 */
ts4_word ts4_call_seq_fn_830C86C0_830C9438(ts4_word a0)
{
    ts4_word loc50[10];
    ts4_word t1;

    loc50[0] = (ts4_word)a0;
    loc50[5] = (ts4_word)64;
    loc50[4] = (ts4_word)0;
    t1 = fn_830C86C0((ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830C94D8: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_830C94D8(ts4_word a0)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)64);
}

/* Loader_DLL.xex 0x830C9530: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_830C9530(ts4_word a0)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)288);
}

/* Loader_DLL.xex 0x830C9588: fn  */
void ts4_fn_830C9588(void)
{
    return;
}

/* Loader_DLL.xex 0x830C9590: call_seq fn_833E3AD0 */
ts4_word ts4_call_seq_fn_833E3AD0_830C9590(ts4_word a0, ts4_word a1)
{
    fn_833E3AD0((ts4_word)a0, (ts4_word)a1, (ts4_word)32);
    return a0;
}

/* Loader_DLL.xex 0x830C95C8: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_830C95C8(ts4_word a0)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)32);
}

/* Loader_DLL.xex 0x830C96C8: if_get u32@0x8, u32@0x4, fn_830C9E70 */
ts4_word ts4_if_get_u32_off8_830C96C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    if ((ts4_word)t1 >= 100) {
        return a0;
    }
    return fn_830C9E70((ts4_word)a0, (ts4_word)100, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C9768: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C9768(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C9770: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9770(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C97A0: if_get u32@0x8, u32@0x4, fn_830C9F00 */
ts4_word ts4_if_get_u32_off8_830C97A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    if ((ts4_word)t1 >= 50) {
        return a0;
    }
    return fn_830C9F00((ts4_word)a0, (ts4_word)50, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C9838: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C9838(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C9840: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830C9840(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830C9858: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9858(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C9878: if_get u32@0x8, u32@0x4, fn_830C9F90 */
ts4_word ts4_if_get_u32_off8_830C9878(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    if ((ts4_word)t1 >= 16) {
        return a0;
    }
    return fn_830C9F90((ts4_word)a0, (ts4_word)16, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C9908: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C9908(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C9910: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830C9910(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830C9928: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9928(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C9930: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9930(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 2);
}

/* Loader_DLL.xex 0x830C9958: if_get u32@0x8, u32@0x4, fn_830CA020 */
ts4_word ts4_if_get_u32_off8_830C9958(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    if ((ts4_word)t1 >= 2) {
        return a0;
    }
    return fn_830CA020((ts4_word)a0, (ts4_word)2, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C99E8: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C99E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C99F0: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C99F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C99F8: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C99F8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 2);
}

/* Loader_DLL.xex 0x830C9A20: if_get u32@0x8, u32@0x4, fn_830CA0B0 */
ts4_word ts4_if_get_u32_off8_830C9A20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    if ((ts4_word)t1 >= 16) {
        return a0;
    }
    return fn_830CA0B0((ts4_word)a0, (ts4_word)16, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C9AB0: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C9AB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C9AB8: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830C9AB8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830C9AD0: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9AD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C9AD8: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9AD8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 2);
}

/* Loader_DLL.xex 0x830C9B00: if_get u32@0x8, u32@0x4, fn_830CA140 */
ts4_word ts4_if_get_u32_off8_830C9B00(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    if ((ts4_word)t1 >= 16) {
        return a0;
    }
    return fn_830CA140((ts4_word)a0, (ts4_word)16, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C9B90: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C9B90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C9B98: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830C9B98(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830C9BB0: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9BB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C9BB8: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9BB8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 2);
}

/* Loader_DLL.xex 0x830C9C68: set u32@0x4 */
void ts4_set_u32_off4_830C9C68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9C78: set u32@0x4 */
void ts4_set_u32_off4_830C9C78(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9CD0: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C9CD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830C9CD8: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9CD8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 2);
}

/* Loader_DLL.xex 0x830C9D68: set u32@0x4 */
void ts4_set_u32_off4_830C9D68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9D78: if_get u32@0x8, fn_830C9E70 */
ts4_word ts4_if_get_u32_off8_830C9D78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830C9E70((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9D90: set u32@0x4 */
void ts4_set_u32_off4_830C9D90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9DA0: if_get u32@0x8, fn_830C9F00 */
ts4_word ts4_if_get_u32_off8_830C9DA0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830C9F00((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9DB8: set u32@0x4 */
void ts4_set_u32_off4_830C9DB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9DC8: if_get u32@0x8, fn_830C9F90 */
ts4_word ts4_if_get_u32_off8_830C9DC8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830C9F90((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9DE0: set u32@0x4 */
void ts4_set_u32_off4_830C9DE0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9DF0: if_get u32@0x8, fn_830CA020 */
ts4_word ts4_if_get_u32_off8_830C9DF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830CA020((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9E08: set u32@0x4 */
void ts4_set_u32_off4_830C9E08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9E18: if_get u32@0x8, fn_830CA0B0 */
ts4_word ts4_if_get_u32_off8_830C9E18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830CA0B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9E30: set u32@0x4 */
void ts4_set_u32_off4_830C9E30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C9E40: if_get u32@0x8, fn_830CA140 */
ts4_word ts4_if_get_u32_off8_830C9E40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830CA140((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C9E58: if_get u32@0x8, fn_830CA1D0 */
ts4_word ts4_if_get_u32_off8_830C9E58(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830CA1D0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830CA260: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_830CA260(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t2) + 32));
    }
    return 0;
}

/* Loader_DLL.xex 0x830CA288: fn  */
ts4_word ts4_fn_830CA288(void)
{
    return 3;
}

/* Loader_DLL.xex 0x830CA5B0: call_seq ExGetXConfigSetting */
ts4_word ts4_call_seq_ExGetXConfigSetting_830CA5B0(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    t1 = ExGetXConfigSetting((ts4_word)3, (ts4_word)10, (ts4_word)a0, (ts4_word)4, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830CAD80: if_call_seq ExRegisterTitleTerminateNotification, u32@__imp_VdGlobalDevice, u32@0x0, fn_830CABE0 */
ts4_word ts4_if_call_seq_ExRegisterTitleTerminateNotification_830CAD80(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    ExRegisterTitleTerminateNotification((ts4_word)a0, (ts4_word)0);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_VdGlobalDevice)) + 0);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_830CABE0((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x830CADC0: call_seq ExRegisterTitleTerminateNotification, VdShutdownEngines */
ts4_word ts4_call_seq_ExRegisterTitleTerminateNotification_830CADC0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ExRegisterTitleTerminateNotification((ts4_word)a0, (ts4_word)0);
    t2 = VdShutdownEngines((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830CB3F8: fn  */
void ts4_fn_830CB3F8(void)
{
    return;
}

/* Loader_DLL.xex 0x830CB400: get u32@0x0 */
ts4_word ts4_get_u32_off0_830CB400(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830CB408: get u32@0x74 */
ts4_word ts4_get_u32_off74_830CB408(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 116));
}

/* Loader_DLL.xex 0x830CB438: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830CB438(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x830CBE60: set u32@0x3548 */
void ts4_set_u32_off3548_830CBE60(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 13640) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830CBE68: fn  */
void ts4_fn_830CBE68(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBE70: fn  */
ts4_word ts4_fn_830CBE70(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830CBEB8: fn  */
void ts4_fn_830CBEB8(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBEC0: fn  */
void ts4_fn_830CBEC0(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBEC8: fn  */
ts4_word ts4_fn_830CBEC8(void)
{
    return 4;
}

/* Loader_DLL.xex 0x830CBF38: get u32@0x0 */
ts4_word ts4_get_u32_off0_830CBF38(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) << 2);
}

/* Loader_DLL.xex 0x830CBF48: get u32@0x0 */
ts4_word ts4_get_u32_off0_830CBF48(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830CBF50: fn  */
void ts4_fn_830CBF50(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBF58: fn  */
void ts4_fn_830CBF58(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBF60: fn  */
void ts4_fn_830CBF60(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBF68: fn  */
ts4_word ts4_fn_830CBF68(void)
{
    return 1;
}

/* Loader_DLL.xex 0x830CBF70: fn  */
void ts4_fn_830CBF70(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBF78: fn  */
void ts4_fn_830CBF78(void)
{
    return;
}

/* Loader_DLL.xex 0x830CBF80: fn  */
ts4_word ts4_fn_830CBF80(void)
{
    return 1;
}

/* Loader_DLL.xex 0x830CBF88: get u32@0x68 */
ts4_word ts4_get_u32_off68_830CBF88(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 104)) + a0);
}

/* Loader_DLL.xex 0x830CBFD0: get u32@0x70 */
ts4_word ts4_get_u32_off70_830CBFD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 112));
}

/* Loader_DLL.xex 0x830CBFD8: get u32@0x88 */
ts4_word ts4_get_u32_off88_830CBFD8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 136));
}

/* Loader_DLL.xex 0x830CBFE0: get u32@0x8c */
ts4_word ts4_get_u32_off8c_830CBFE0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 140));
}

/* Loader_DLL.xex 0x830CBFE8: get u32@0x90 */
ts4_word ts4_get_u32_off90_830CBFE8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 144));
}

/* Loader_DLL.xex 0x830CBFF0: get u32@0x94 */
ts4_word ts4_get_u32_off94_830CBFF0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 148));
}

/* Loader_DLL.xex 0x830CBFF8: get u32@0x98 */
ts4_word ts4_get_u32_off98_830CBFF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 152));
}

/* Loader_DLL.xex 0x830CC000: get u32@0xac */
ts4_word ts4_get_u32_offac_830CC000(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 172));
}

/* Loader_DLL.xex 0x830CC008: get u32@0xb0 */
ts4_word ts4_get_u32_offb0_830CC008(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 176));
}

/* Loader_DLL.xex 0x830CC010: get u32@0xb4 */
ts4_word ts4_get_u32_offb4_830CC010(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 180));
}

/* Loader_DLL.xex 0x830CC018: fn  */
void ts4_fn_830CC018(void)
{
    return;
}

/* Loader_DLL.xex 0x830CC020: call_seq fn_833E3A30, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_fn_833E3A30_830CC020(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((a2 << 2) + a1);
    return a0;
}

/* Loader_DLL.xex 0x830CC080: fn  */
void ts4_fn_830CC080(void)
{
    return;
}

/* Loader_DLL.xex 0x830CC198: call_seq fn_833E3A30, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_fn_833E3A30_830CC198(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((a2 << 2) + a1);
    return t1;
}

/* Loader_DLL.xex 0x830CDA10: set u32@0x98, u32@0x9c */
void ts4_set_u32_off98_830CDA10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x830CE8E8: tailcall VdQuerySystemCommandBuffer */
ts4_word ts4_tailcall_VdQuerySystemCommandBuffer_830CE8E8(void)
{
    return VdQuerySystemCommandBuffer((ts4_word)0);
}

/* Loader_DLL.xex 0x830CF368: get u32@0x6c, u32@0x7c, u32@0x6c, u32@0x80, u32@0x84 */
void ts4_get_u32_off6c_830CF368(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)((3 & 0xf) | (t1 & 0xfffffff0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830CFAE0: tailcall fn_830CF980 */
ts4_word ts4_tailcall_fn_830CF980_830CFAE0(ts4_word a0)
{
    return fn_830CF980((ts4_word)a0);
}

/* Loader_DLL.xex 0x830D0B20: set u32@0x0 */
void ts4_set_u32_off0_830D0B20(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830D0B28: if_get u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_830D0B28(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t2;

    if ((ts4_word)a1 == 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 == 0) {
        return a1;
    }
    p3 = (ts4_word)t2;
    if ((int)(t2 - a1) <= 0) {
        p3 = (ts4_word)a1;
    }
    return p3;
}

/* Loader_DLL.xex 0x830D25C8: fn  */
void ts4_fn_830D25C8(void)
{
    return;
}

/* Loader_DLL.xex 0x830D25D0: fn  */
void ts4_fn_830D25D0(void)
{
    return;
}

/* Loader_DLL.xex 0x830D25D8: fn  */
void ts4_fn_830D25D8(void)
{
    return;
}

/* Loader_DLL.xex 0x830D25E0: fn  */
void ts4_fn_830D25E0(void)
{
    return;
}

/* Loader_DLL.xex 0x830D25E8: fn  */
void ts4_fn_830D25E8(void)
{
    return;
}

/* Loader_DLL.xex 0x830D25F0: fn  */
void ts4_fn_830D25F0(void)
{
    return;
}

/* Loader_DLL.xex 0x830D25F8: fn  */
ts4_word ts4_fn_830D25F8(ts4_word a0, ts4_word a1)
{
    return (a0 & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830D2668: fn  */
ts4_word ts4_fn_830D2668(ts4_word a0)
{
    return (a0 & 0xffffffe0);
}

/* Loader_DLL.xex 0x830D3328: fn  */
ts4_word ts4_fn_830D3328(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830D3390: fn  */
void ts4_fn_830D3390(void)
{
    return;
}

/* Loader_DLL.xex 0x830D3398: fn  */
ts4_word ts4_fn_830D3398(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830D3438: get u32@0x40 */
ts4_word ts4_get_u32_off40_830D3438(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 64)) + a0) + 40);
}

/* Loader_DLL.xex 0x830D3448: get u32@0x40, u32@0x18, u32@0x28 */
ts4_word ts4_get_u32_off40_830D3448(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    return ((*(ts4_word *)((char *)(ts4_word)((t1 + a0)) + 40)) + t2);
}

/* Loader_DLL.xex 0x830D3460: get u32@0x40, u32@0x2c */
ts4_word ts4_get_u32_off40_830D3460(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 64)) + a0)) + 44));
}

/* Loader_DLL.xex 0x830D3470: get u32@0x28 */
ts4_word ts4_get_u32_off28_830D3470(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x830D3498: get u32@0x368 */
ts4_word ts4_get_u32_off368_830D3498(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 872)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x830D3598: get u32@0x30 */
ts4_word ts4_get_u32_off30_830D3598(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x830D3718: fn  */
void ts4_fn_830D3718(void)
{
    return;
}

/* Loader_DLL.xex 0x830D3720: fn  */
void ts4_fn_830D3720(void)
{
    return;
}

/* Loader_DLL.xex 0x830D4258: get u32@0x0 */
ts4_word ts4_get_u32_off0_830D4258(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((((((t1 << 25) | (t1 >> 7)) & 0xc0000) | (t1 & 0xfff3ffff)) >> 18) & 0x7f);
}

/* Loader_DLL.xex 0x830D5260: tailcall KeBugCheck */
ts4_word ts4_tailcall_KeBugCheck_830D5260(void)
{
    return KeBugCheck((ts4_word)245);
}

/* Loader_DLL.xex 0x830D7850: fn  */
void ts4_fn_830D7850(void)
{
    return;
}

/* Loader_DLL.xex 0x830D7CC0: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_830D7CC0(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)27, (ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x830D7CF0: fn  */
ts4_word ts4_fn_830D7CF0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830D7D80: fn  */
ts4_word ts4_fn_830D7D80(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830D7E20: call_seq u32@0x2a9c, u32@0x2ab0, fn_830BB150 */
ts4_word ts4_call_seq_u32_off2a9c_830D7E20(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 10908);
    *(ts4_word *)((char *)(ts4_word)(a0) + 10928) = (ts4_word)t1;
    fn_830BB150((ts4_word)a0);
    return t1;
}

/* Loader_DLL.xex 0x830D7E58: call_seq fn_830C2800 */
ts4_word ts4_call_seq_fn_830C2800_830D7E58(void)
{
    fn_830C2800();
    return 0;
}

/* Loader_DLL.xex 0x830D7EE0: set u8@lbl_8354496A */
ts4_word ts4_set_u8_lbl_8354496A_830D7EE0(void)
{
    *(unsigned char *)lbl_8354496A = (unsigned char)1;
    return 1;
}

/* Loader_DLL.xex 0x830D7EF8: set u8@lbl_8354496A */
ts4_word ts4_set_u8_lbl_8354496A_830D7EF8(void)
{
    *(unsigned char *)lbl_8354496A = (unsigned char)0;
    return 1;
}

/* Loader_DLL.xex 0x830D7FE8: set u8@lbl_83544969 */
ts4_word ts4_set_u8_lbl_83544969_830D7FE8(void)
{
    *(unsigned char *)lbl_83544969 = (unsigned char)1;
    return 1;
}

/* Loader_DLL.xex 0x830D8000: set u8@lbl_83544968 */
ts4_word ts4_set_u8_lbl_83544968_830D8000(void)
{
    *(unsigned char *)lbl_83544968 = (unsigned char)1;
    return 1;
}

/* Loader_DLL.xex 0x830D8040: call_seq fn_830D9018, u8@lbl_8354496A */
ts4_word ts4_call_seq_fn_830D9018_830D8040(void)
{
    ts4_word t1;

    t1 = fn_830D9018();
    *(unsigned char *)lbl_8354496A = (unsigned char)0;
    return t1;
}

/* Loader_DLL.xex 0x830D83A8: if_tail MmFreePhysicalMemory, fn_8340D830 */
ts4_word ts4_if_tail_MmFreePhysicalMemory_830D83A8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            return a0;
        }
        return fn_8340D830((ts4_word)a0, (ts4_word)(2977955840));
    }
    return MmFreePhysicalMemory((ts4_word)2, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830D9DD0: fn  */
ts4_word ts4_fn_830D9DD0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830D9E50: if_get u32@0x359c */
ts4_word ts4_if_get_u32_off359c_830D9E50(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 13724);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
}

/* Loader_DLL.xex 0x830D9E68: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_830D9E68(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t2) + 32));
    }
    return 0;
}

/* Loader_DLL.xex 0x830D9E90: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_830D9E90(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x830D9EB8: fn  */
ts4_word ts4_fn_830D9EB8(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830D9F00: fn  */
void ts4_fn_830D9F00(void)
{
    return;
}

/* Loader_DLL.xex 0x830D9F08: fn  */
void ts4_fn_830D9F08(void)
{
    return;
}

/* Loader_DLL.xex 0x830D9F10: fn  */
ts4_word ts4_fn_830D9F10(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830D9F98: if_get u32@0xc, fn_830BBC00 */
ts4_word ts4_if_get_u32_offc_830D9F98(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        return t1;
    }
    return fn_830BBC00((ts4_word)t1);
}

/* Loader_DLL.xex 0x830D9FB0: tailcall fn_830A9FA8 */
ts4_word ts4_tailcall_fn_830A9FA8_830D9FB0(ts4_word a0)
{
    return fn_830A9FA8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830DA038: if_get u32@__imp_KeCertMonitorData, u32@0x0, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32__imp_KeCertMonitorData_830DA038(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeCertMonitorData)) + 0);
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t4))((ts4_word)0);
}

/* Loader_DLL.xex 0x830DA068: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_830DA068(ts4_word a0, ts4_word a1)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830DA078: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_830DA078(ts4_word a0, ts4_word a1)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)(a1 << 2));
}

/* Loader_DLL.xex 0x830DA158: tailcall fn_830DA0E0 */
ts4_word ts4_tailcall_fn_830DA0E0_830DA158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830DA0E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x830DA160: tailcall fn_830DA0E0 */
ts4_word ts4_tailcall_fn_830DA0E0_830DA160(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830DA0E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x830DA290: tailcall fn_830DA1B8 */
ts4_word ts4_tailcall_fn_830DA1B8_830DA290(ts4_word a0)
{
    return fn_830DA1B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830DA298: addr lbl_83081C18, fn_830DA1B8 */
ts4_word ts4_addr_lbl_83081C18_830DA298(ts4_word a0)
{
    return fn_830DA1B8((ts4_word)a0, (ts4_word)500, (ts4_word)(ts4_word)lbl_83081C18, (ts4_word)12);
}

/* Loader_DLL.xex 0x830DA458: tailcall fn_830DA400 */
ts4_word ts4_tailcall_fn_830DA400_830DA458(ts4_word a0, ts4_word a1)
{
    return fn_830DA400((ts4_word)a0, (ts4_word)1, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830DA468: tailcall fn_830DA400 */
ts4_word ts4_tailcall_fn_830DA400_830DA468(ts4_word a0)
{
    return fn_830DA400((ts4_word)a0, (ts4_word)8, (ts4_word)3);
}

/* Loader_DLL.xex 0x830DC2B8: fn  */
void ts4_fn_830DC2B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830DCE78: tailcall fn_830BBA98 */
ts4_word ts4_tailcall_fn_830BBA98_830DCE78(ts4_word a0)
{
    return fn_830BBA98((ts4_word)a0);
}

/* Loader_DLL.xex 0x830DD4A0: fn  */
void ts4_fn_830DD4A0(void)
{
    return;
}

/* Loader_DLL.xex 0x830DD940: tailcall fn_830DC818 */
ts4_word ts4_tailcall_fn_830DC818_830DD940(ts4_word a0, ts4_word a1)
{
    return fn_830DC818((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830DDBA8: tailcall fn_830DA1B8 */
ts4_word ts4_tailcall_fn_830DA1B8_830DDBA8(ts4_word a0, ts4_word a1)
{
    return fn_830DA1B8((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)4);
}

/* Loader_DLL.xex 0x830DDBB8: tailcall fn_830DA1B8 */
ts4_word ts4_tailcall_fn_830DA1B8_830DDBB8(ts4_word a0, ts4_word a1)
{
    return fn_830DA1B8((ts4_word)a0, (ts4_word)256, (ts4_word)a1, (ts4_word)20);
}

/* Loader_DLL.xex 0x830DDBC8: tailcall fn_830DA1B8 */
ts4_word ts4_tailcall_fn_830DA1B8_830DDBC8(ts4_word a0)
{
    return fn_830DA1B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830DDC18: fn  */
ts4_word ts4_fn_830DDC18(ts4_word a0)
{
    return ((a0 + 3) & 0xfffffffc);
}

/* Loader_DLL.xex 0x830DDC28: fn  */
ts4_word ts4_fn_830DDC28(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830DDC40: fn  */
ts4_word ts4_fn_830DDC40(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830DE668: set u32@lbl_8352E934 */
void ts4_set_u32_lbl_8352E934_830DE668(ts4_word a0)
{
    *(ts4_word *)lbl_8352E934 = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x830DE9D0: call_seq fn_830DE8E8, fn_830B0710 */
ts4_word ts4_call_seq_fn_830DE8E8_830DE9D0(ts4_word a0)
{
    ts4_word t2;

    fn_830DE8E8((ts4_word)a0, (ts4_word)2, (ts4_word)0);
    t2 = fn_830B0710((ts4_word)a0, (ts4_word)0);
    return t2;
}

/* Loader_DLL.xex 0x830DEA10: fn  */
ts4_word ts4_fn_830DEA10(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830DEA50: fn  */
ts4_word ts4_fn_830DEA50(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830DED88: fn  */
void ts4_fn_830DED88(void)
{
    return;
}

/* Loader_DLL.xex 0x830DFC20: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_830DFC20(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x830DFCE8: fn  */
void ts4_fn_830DFCE8(void)
{
    return;
}

/* Loader_DLL.xex 0x830DFDB8: tailcall fn_830C0788 */
ts4_word ts4_tailcall_fn_830C0788_830DFDB8(ts4_word a0, ts4_word a1)
{
    return fn_830C0788((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830DFE28: loop_addr lbl_83089050, u32@0x0, u32@0x4, u32@0x8, u32@0x0 */
void ts4_loop_addr_lbl_83089050_830DFE28(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83089050;
    lv2 = (ts4_word)(a0 + 12);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 12)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 12);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x830DFE58: loop_set u32@0x4, u32@0x8, u32@0x0 */
void ts4_loop_set_u32_off4_830DFE58(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)64;
    lv2 = (ts4_word)(a0 + -4);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 12)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 12);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x830DFEE0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830DFEE0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(1686110208));
}

/* Loader_DLL.xex 0x830DFEE8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_830DFEE8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830E0BE0: fn  */
void ts4_fn_830E0BE0(void)
{
    return;
}

/* Loader_DLL.xex 0x830E0CF0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830E0CF0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830E0CF8: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_830E0CF8(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830E0F30: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830E0F30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830E0F60: set u32@0x4 */
void ts4_set_u32_off4_830E0F60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830E0FD8: if_get u32@0x8, fn_830E1020 */
ts4_word ts4_if_get_u32_off8_830E0FD8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return a0;
    }
    return fn_830E1020((ts4_word)a0);
}

/* Loader_DLL.xex 0x830E0FF0: get u32@0x0 */
ts4_word ts4_get_u32_off0_830E0FF0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830E0FF8: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830E0FF8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830E1010: get u32@0x4 */
ts4_word ts4_get_u32_off4_830E1010(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830E1018: get u32@0x8 */
ts4_word ts4_get_u32_off8_830E1018(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x830E10B0: fn  */
ts4_word ts4_fn_830E10B0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830E10C8: fn  */
void ts4_fn_830E10C8(void)
{
    return;
}

/* Loader_DLL.xex 0x830E10D0: fn  */
ts4_word ts4_fn_830E10D0(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830E1130: fn  */
void ts4_fn_830E1130(void)
{
    return;
}

/* Loader_DLL.xex 0x830E1138: fn  */
void ts4_fn_830E1138(void)
{
    return;
}

/* Loader_DLL.xex 0x830E1600: get u32@0x3554, u32@0x30 */
void ts4_get_u32_off3554_830E1600(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13652));
    return;
}

/* Loader_DLL.xex 0x830E1B98: get u32@0x3554, u32@0x30 */
void ts4_get_u32_off3554_830E1B98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13652));
    return;
}

/* Loader_DLL.xex 0x830E3078: tailcall fn_830F7188 */
ts4_word ts4_tailcall_fn_830F7188_830E3078(ts4_word a0)
{
    return fn_830F7188((ts4_word)a0);
}

/* Loader_DLL.xex 0x830E30A8: fn  */
void ts4_fn_830E30A8(void)
{
    return;
}

/* Loader_DLL.xex 0x830E8668: fn  */
void ts4_fn_830E8668(void)
{
    return;
}

/* Loader_DLL.xex 0x830F6AD0: fn  */
void ts4_fn_830F6AD0(void)
{
    return;
}

/* Loader_DLL.xex 0x830F75F0: tailcall fn_830F7530 */
ts4_word ts4_tailcall_fn_830F7530_830F75F0(ts4_word a0)
{
    return fn_830F7530((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7600: tailcall NetDll_XNetCleanup */
ts4_word ts4_tailcall_NetDll_XNetCleanup_830F7600(void)
{
    return NetDll_XNetCleanup((ts4_word)1);
}

/* Loader_DLL.xex 0x830F7608: tailcall NetDll_XNetRandom */
ts4_word ts4_tailcall_NetDll_XNetRandom_830F7608(ts4_word a0, ts4_word a1)
{
    return NetDll_XNetRandom((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830F7618: tailcall NetDll_XNetCreateKey */
ts4_word ts4_tailcall_NetDll_XNetCreateKey_830F7618(ts4_word a0, ts4_word a1)
{
    return NetDll_XNetCreateKey((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830F7628: tailcall NetDll_XNetRegisterKey */
ts4_word ts4_tailcall_NetDll_XNetRegisterKey_830F7628(ts4_word a0, ts4_word a1)
{
    return NetDll_XNetRegisterKey((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830F7638: tailcall NetDll_XNetUnregisterKey */
ts4_word ts4_tailcall_NetDll_XNetUnregisterKey_830F7638(ts4_word a0)
{
    return NetDll_XNetUnregisterKey((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7648: tailcall NetDll_XNetXnAddrToInAddr */
ts4_word ts4_tailcall_NetDll_XNetXnAddrToInAddr_830F7648(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetXnAddrToInAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F7660: tailcall NetDll_XNetServerToInAddr */
ts4_word ts4_tailcall_NetDll_XNetServerToInAddr_830F7660(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetServerToInAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F7678: tailcall NetDll_XNetTsAddrToInAddr */
ts4_word ts4_tailcall_NetDll_XNetTsAddrToInAddr_830F7678(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return NetDll_XNetTsAddrToInAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830F7690: tailcall NetDll_XNetInAddrToXnAddr */
ts4_word ts4_tailcall_NetDll_XNetInAddrToXnAddr_830F7690(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetInAddrToXnAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F76A8: tailcall NetDll_XNetInAddrToServer */
ts4_word ts4_tailcall_NetDll_XNetInAddrToServer_830F76A8(ts4_word a0, ts4_word a1)
{
    return NetDll_XNetInAddrToServer((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830F76B8: tailcall NetDll_XNetInAddrToString */
ts4_word ts4_tailcall_NetDll_XNetInAddrToString_830F76B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetInAddrToString((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F76D0: tailcall NetDll_XNetUnregisterInAddr */
ts4_word ts4_tailcall_NetDll_XNetUnregisterInAddr_830F76D0(ts4_word a0)
{
    return NetDll_XNetUnregisterInAddr((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F76E0: tailcall NetDll_XNetXnAddrToMachineId */
ts4_word ts4_tailcall_NetDll_XNetXnAddrToMachineId_830F76E0(ts4_word a0, ts4_word a1)
{
    return NetDll_XNetXnAddrToMachineId((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830F76F0: tailcall NetDll_XNetConnect */
ts4_word ts4_tailcall_NetDll_XNetConnect_830F76F0(ts4_word a0)
{
    return NetDll_XNetConnect((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7700: tailcall NetDll_XNetGetConnectStatus */
ts4_word ts4_tailcall_NetDll_XNetGetConnectStatus_830F7700(ts4_word a0)
{
    return NetDll_XNetGetConnectStatus((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7710: tailcall NetDll_XNetDnsLookup */
ts4_word ts4_tailcall_NetDll_XNetDnsLookup_830F7710(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetDnsLookup((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F7728: tailcall NetDll_XNetDnsRelease */
ts4_word ts4_tailcall_NetDll_XNetDnsRelease_830F7728(ts4_word a0)
{
    return NetDll_XNetDnsRelease((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7738: tailcall NetDll_XNetQosListen */
ts4_word ts4_tailcall_NetDll_XNetQosListen_830F7738(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_XNetQosListen((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830F77B8: tailcall NetDll_XNetQosServiceLookup */
ts4_word ts4_tailcall_NetDll_XNetQosServiceLookup_830F77B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetQosServiceLookup((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F77D0: tailcall NetDll_XNetQosRelease */
ts4_word ts4_tailcall_NetDll_XNetQosRelease_830F77D0(ts4_word a0)
{
    return NetDll_XNetQosRelease((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F77E0: tailcall NetDll_XNetGetTitleXnAddr */
ts4_word ts4_tailcall_NetDll_XNetGetTitleXnAddr_830F77E0(ts4_word a0)
{
    return NetDll_XNetGetTitleXnAddr((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F77F0: tailcall NetDll_XNetGetDebugXnAddr */
ts4_word ts4_tailcall_NetDll_XNetGetDebugXnAddr_830F77F0(ts4_word a0)
{
    return NetDll_XNetGetDebugXnAddr((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7800: tailcall NetDll_XNetGetEthernetLinkStatus */
ts4_word ts4_tailcall_NetDll_XNetGetEthernetLinkStatus_830F7800(void)
{
    return NetDll_XNetGetEthernetLinkStatus((ts4_word)1);
}

/* Loader_DLL.xex 0x830F7808: tailcall NetDll_XNetGetBroadcastVersionStatus */
ts4_word ts4_tailcall_NetDll_XNetGetBroadcastVersionStatus_830F7808(ts4_word a0)
{
    return NetDll_XNetGetBroadcastVersionStatus((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830F7818: tailcall NetDll_XNetQosGetListenStats */
ts4_word ts4_tailcall_NetDll_XNetQosGetListenStats_830F7818(ts4_word a0, ts4_word a1)
{
    return NetDll_XNetQosGetListenStats((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830F7828: tailcall NetDll_XNetGetOpt */
ts4_word ts4_tailcall_NetDll_XNetGetOpt_830F7828(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetGetOpt((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F7840: tailcall NetDll_XNetSetOpt */
ts4_word ts4_tailcall_NetDll_XNetSetOpt_830F7840(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetSetOpt((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830F78A0: get u32@0xc */
ts4_word ts4_get_u32_offc_830F78A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x830F78F0: get u16@0x28 */
ts4_word ts4_get_u16_off28_830F78F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 40));
}

/* Loader_DLL.xex 0x830F78F8: get u32@0x2c */
ts4_word ts4_get_u32_off2c_830F78F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x830F7900: get u32@0x14 */
ts4_word ts4_get_u32_off14_830F7900(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Loader_DLL.xex 0x830F7950: get u16@0x0, u16@0x0 */
ts4_word ts4_get_u16_off0_830F7950(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return (t1 - (*(unsigned short *)((char *)(ts4_word)(a1) + 0)));
}

/* Loader_DLL.xex 0x830F79E8: addr lbl_83526CC4, fn_830F7960 */
ts4_word ts4_addr_lbl_83526CC4_830F79E8(void)
{
    return fn_830F7960((ts4_word)(ts4_word)lbl_83526CC4);
}

/* Loader_DLL.xex 0x830F79F8: addr lbl_83526CC4 */
ts4_word ts4_addr_lbl_83526CC4_830F79F8(void)
{
    return (ts4_word)lbl_83526CC4;
}

/* Loader_DLL.xex 0x830F7A08: call_seq fn_830FA9F8 */
ts4_word ts4_call_seq_fn_830FA9F8_830F7A08(void)
{
    fn_830FA9F8();
    return 0;
}

/* Loader_DLL.xex 0x830F7E88: set u32@0x0, u64@0x8 */
void ts4_set_u32_off0_830F7E88(ts4_word a0, ts4_word a1, ts4_u64 a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)a2;
    return;
}

/* Loader_DLL.xex 0x830F7E98: set u32@0x200 */
void ts4_set_u32_off200_830F7E98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 512) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830F7ED8: set u32@0x1c */
void ts4_set_u32_off1c_830F7ED8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830F7EE0: set u32@0x200 */
void ts4_set_u32_off200_830F7EE0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 512) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FA0F0: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FA0F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FA0F8: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FA0F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FA100: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FA100(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FA108: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FA108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FA240: tailcall fn_830FC3C8 */
ts4_word ts4_tailcall_fn_830FC3C8_830FA240(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC3C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)1);
}

/* Loader_DLL.xex 0x830FA248: call_seq fn_830FCCD0 */
ts4_word ts4_call_seq_fn_830FCCD0_830FA248(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1;
    t1 = fn_830FCCD0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FA278: call_seq fn_830FCCD0 */
ts4_word ts4_call_seq_fn_830FCCD0_830FA278(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1;
    t1 = fn_830FCCD0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FA300: call_seq fn_830FCCD0 */
ts4_word ts4_call_seq_fn_830FCCD0_830FA300(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)2;
    t1 = fn_830FCCD0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FA9E0: fn  */
ts4_word ts4_fn_830FA9E0(void)
{
    return 10013;
}

/* Loader_DLL.xex 0x830FA9E8: tailcall fn_830FA930 */
ts4_word ts4_tailcall_fn_830FA930_830FA9E8(ts4_word a0, ts4_word a1)
{
    return fn_830FA930((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FAA00: tailcall NetDll_socket */
ts4_word ts4_tailcall_NetDll_socket_830FAA00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_socket((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAA18: tailcall NetDll_closesocket */
ts4_word ts4_tailcall_NetDll_closesocket_830FAA18(ts4_word a0)
{
    return NetDll_closesocket((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAA28: tailcall NetDll_shutdown */
ts4_word ts4_tailcall_NetDll_shutdown_830FAA28(ts4_word a0, ts4_word a1)
{
    return NetDll_shutdown((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FAA38: tailcall NetDll_ioctlsocket */
ts4_word ts4_tailcall_NetDll_ioctlsocket_830FAA38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_ioctlsocket((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAA50: tailcall NetDll_setsockopt */
ts4_word ts4_tailcall_NetDll_setsockopt_830FAA50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_setsockopt((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830FAA70: tailcall NetDll_getsockopt */
ts4_word ts4_tailcall_NetDll_getsockopt_830FAA70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_getsockopt((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830FAA90: tailcall NetDll_getsockname */
ts4_word ts4_tailcall_NetDll_getsockname_830FAA90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_getsockname((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAAA8: tailcall NetDll_getpeername */
ts4_word ts4_tailcall_NetDll_getpeername_830FAAA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_getpeername((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAAC0: tailcall NetDll_bind */
ts4_word ts4_tailcall_NetDll_bind_830FAAC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_bind((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAAD8: tailcall NetDll_connect */
ts4_word ts4_tailcall_NetDll_connect_830FAAD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_connect((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAAF0: tailcall NetDll_listen */
ts4_word ts4_tailcall_NetDll_listen_830FAAF0(ts4_word a0, ts4_word a1)
{
    return NetDll_listen((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FAB00: tailcall NetDll_accept */
ts4_word ts4_tailcall_NetDll_accept_830FAB00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_accept((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FAB18: tailcall NetDll_select */
ts4_word ts4_tailcall_NetDll_select_830FAB18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_select((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830FAB38: tailcall NetDll_WSAGetOverlappedResult */
ts4_word ts4_tailcall_NetDll_WSAGetOverlappedResult_830FAB38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_WSAGetOverlappedResult((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830FAB58: tailcall NetDll_WSACancelOverlappedIO */
ts4_word ts4_tailcall_NetDll_WSACancelOverlappedIO_830FAB58(ts4_word a0)
{
    return NetDll_WSACancelOverlappedIO((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAB68: tailcall NetDll_recv */
ts4_word ts4_tailcall_NetDll_recv_830FAB68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return NetDll_recv((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FAB80: tailcall NetDll_WSARecv */
ts4_word ts4_tailcall_NetDll_WSARecv_830FAB80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return NetDll_WSARecv((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x830FABA8: tailcall NetDll_recvfrom */
ts4_word ts4_tailcall_NetDll_recvfrom_830FABA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return NetDll_recvfrom((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x830FAC20: tailcall NetDll_send */
ts4_word ts4_tailcall_NetDll_send_830FAC20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return NetDll_send((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FAC38: tailcall NetDll_WSASend */
ts4_word ts4_tailcall_NetDll_WSASend_830FAC38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return NetDll_WSASend((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x830FAC60: tailcall NetDll_sendto */
ts4_word ts4_tailcall_NetDll_sendto_830FAC60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return NetDll_sendto((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x830FACD8: tailcall NetDll_WSAEventSelect */
ts4_word ts4_tailcall_NetDll_WSAEventSelect_830FACD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_WSAEventSelect((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FACF0: fn  */
ts4_word ts4_fn_830FACF0(void)
{
    return 10013;
}

/* Loader_DLL.xex 0x830FACF8: tailcall NetDll_inet_addr */
ts4_word ts4_tailcall_NetDll_inet_addr_830FACF8(ts4_word a0)
{
    return NetDll_inet_addr((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD00: tailcall NetDll_WSAGetLastError */
ts4_word ts4_tailcall_NetDll_WSAGetLastError_830FAD00(ts4_word a0)
{
    return NetDll_WSAGetLastError((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD08: tailcall NetDll_WSASetLastError */
ts4_word ts4_tailcall_NetDll_WSASetLastError_830FAD08(ts4_word a0)
{
    return NetDll_WSASetLastError((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD10: tailcall NetDll_WSACreateEvent */
ts4_word ts4_tailcall_NetDll_WSACreateEvent_830FAD10(ts4_word a0)
{
    return NetDll_WSACreateEvent((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD18: tailcall NetDll_WSACloseEvent */
ts4_word ts4_tailcall_NetDll_WSACloseEvent_830FAD18(ts4_word a0)
{
    return NetDll_WSACloseEvent((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD20: tailcall NetDll_WSASetEvent */
ts4_word ts4_tailcall_NetDll_WSASetEvent_830FAD20(ts4_word a0)
{
    return NetDll_WSASetEvent((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD28: tailcall NetDll_WSAResetEvent */
ts4_word ts4_tailcall_NetDll_WSAResetEvent_830FAD28(ts4_word a0)
{
    return NetDll_WSAResetEvent((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD30: tailcall NetDll_WSAWaitForMultipleEvents */
ts4_word ts4_tailcall_NetDll_WSAWaitForMultipleEvents_830FAD30(ts4_word a0)
{
    return NetDll_WSAWaitForMultipleEvents((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD38: tailcall NetDll___WSAFDIsSet */
ts4_word ts4_tailcall_NetDll__WSAFDIsSet_830FAD38(ts4_word a0)
{
    return NetDll___WSAFDIsSet((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FAD40: get u32@0x48, u32@0x0 */
void ts4_get_u32_off48_830FAD40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 72))) + 0) = (ts4_word)997;
    return;
}

/* Loader_DLL.xex 0x830FAEE8: fn  */
void ts4_fn_830FAEE8(void)
{
    return;
}

/* Loader_DLL.xex 0x830FAEF0: fn  */
void ts4_fn_830FAEF0(void)
{
    return;
}

/* Loader_DLL.xex 0x830FAEF8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_830FAEF8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FAF10: get u32@0x0 */
ts4_word ts4_get_u32_off0_830FAF10(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830FAF18: get u32@0xc, u32@0x0 */
ts4_word ts4_get_u32_offc_830FAF18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830FAF28: get u32@0x8, u32@0xc */
ts4_word ts4_get_u32_off8_830FAF28(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Loader_DLL.xex 0x830FAF38: fn  */
void ts4_fn_830FAF38(void)
{
    return;
}
