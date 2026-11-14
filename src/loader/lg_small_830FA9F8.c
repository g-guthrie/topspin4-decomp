/* Loader_DLL.xex 0x830FA9F8-0x830FFDC8, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_83000AE8[];
extern char lbl_83000B00[];
extern char lbl_83000B10[];
extern char lbl_83000B24[];
extern char lbl_83000B58[];
extern char lbl_83000B6C[];
extern char lbl_83000B80[];
extern char lbl_83000BA8[];
extern char lbl_83000BC4[];
extern char lbl_83000BE0[];
extern char lbl_83000BF8[];
extern char lbl_83000C18[];
extern char lbl_83000C34[];
extern char lbl_83000C58[];
extern char lbl_83000C6C[];
extern char lbl_83000C80[];
extern char lbl_83000C9C[];
extern char lbl_83000CB4[];
extern char lbl_83000CD0[];
extern char lbl_83000CEC[];
extern char lbl_83000CFC[];
extern char lbl_83000D18[];
extern char lbl_83000D30[];
extern char lbl_83000D50[];
extern char lbl_83000D70[];
extern char lbl_83000D8C[];
extern char lbl_83000D9C[];
extern char lbl_83000DB0[];
extern char lbl_83000DCC[];
extern char lbl_83000DF0[];
extern char lbl_83000E04[];
extern char lbl_83000E1C[];
extern char lbl_83000E34[];
extern char lbl_83000E48[];
extern char lbl_83000E6C[];
extern char lbl_83000E94[];
extern char lbl_83000EB8[];
extern char lbl_83000EE0[];
extern char lbl_83000EFC[];
extern char lbl_83000F1C[];
extern char lbl_83000F3C[];
extern char lbl_83085F70[];
extern char lbl_83085F84[];
extern char lbl_8352F848[];
extern char lbl_8352F8C8[];
extern char lbl_8352F8CC[];
ts4_word ExGetXConfigSetting();
ts4_word NetDll_WSACleanup();
ts4_word NetDll_XnpCapture();
ts4_word NetDll_XnpConfig();
ts4_word NetDll_XnpConfigUPnP();
ts4_word NetDll_XnpEthernetInterceptRecv();
ts4_word NetDll_XnpEthernetInterceptSetCallbacks();
ts4_word NetDll_XnpEthernetInterceptXmit();
ts4_word NetDll_XnpGetActiveSocketList();
ts4_word NetDll_XnpGetConfigStatus();
ts4_word NetDll_XnpGetVlanXboxName();
ts4_word NetDll_XnpLoadConfigParams();
ts4_word NetDll_XnpLoadMachineAccount();
ts4_word NetDll_XnpLogonClearQEvent();
ts4_word NetDll_XnpLogonGetQFlags();
ts4_word NetDll_XnpLogonGetQVals();
ts4_word NetDll_XnpLogonGetStatus();
ts4_word NetDll_XnpLogonSetPState();
ts4_word NetDll_XnpLogonSetQEvent();
ts4_word NetDll_XnpLogonSetQFlags();
ts4_word NetDll_XnpLogonSetQVals();
ts4_word NetDll_XnpNoteSystemTime();
ts4_word NetDll_XnpRegisterKeyForCallerType();
ts4_word NetDll_XnpSaveConfigParams();
ts4_word NetDll_XnpSaveMachineAccount();
ts4_word NetDll_XnpSetVlanXboxName();
ts4_word NetDll_XnpUnregisterKeyForCallerType();
ts4_word fn_830FA758();
ts4_word fn_830FB148();
ts4_word fn_830FC338();
ts4_word fn_830FC610();
ts4_word fn_830FC660();
ts4_word fn_830FC738();
ts4_word fn_830FFC68();
ts4_word fn_83112858();
ts4_word fn_83112998();
ts4_word fn_83112A88();
ts4_word fn_8311BC38();
ts4_word fn_8311DA08();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_831221D0();
ts4_word fn_8313EBD8();
ts4_word fn_8314E0B8();
ts4_word fn_83156690();
ts4_word fn_8315C668();
ts4_word fn_8315C880();

/* Loader_DLL.xex 0x830FA9F8: tailcall NetDll_WSACleanup */
ts4_word ts4_tailcall_NetDll_WSACleanup_830FA9F8(void)
{
    return NetDll_WSACleanup((ts4_word)1);
}

/* Loader_DLL.xex 0x830FAF40: fn  */
void ts4_fn_830FAF40(void)
{
    return;
}

/* Loader_DLL.xex 0x830FAF48: set u32@0x14 */
void ts4_set_u32_off14_830FAF48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FAF58: get u32@0x14, fn_830FA758 */
ts4_word ts4_get_u32_off14_830FAF58(ts4_word a0, ts4_word a1)
{
    return fn_830FA758((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FAF70: get u32@0x200 */
ts4_word ts4_get_u32_off200_830FAF70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 512));
}

/* Loader_DLL.xex 0x830FAF78: if_get u32@0x200 */
ts4_word ts4_if_get_u32_off200_830FAF78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 512);
    if ((ts4_word)a1 < (ts4_word)t1) {
        return ((a1 << 4) + a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x830FAF98: set u32@0x0, u32@0x4, u64@0x8 */
void ts4_set_u32_off0_830FAF98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)0;
    return;
}

/* Loader_DLL.xex 0x830FAFE8: fn  */
ts4_word ts4_fn_830FAFE8(ts4_word a0, ts4_word a1)
{
    return ((a1 << 4) + a0);
}

/* Loader_DLL.xex 0x830FAFF8: fn  */
void ts4_fn_830FAFF8(void)
{
    return;
}

/* Loader_DLL.xex 0x830FB000: fn  */
void ts4_fn_830FB000(void)
{
    return;
}

/* Loader_DLL.xex 0x830FB938: set u32@0x0, u32@0x4, u64@0x8 */
void ts4_set_u32_off0_830FB938(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)0;
    return;
}

/* Loader_DLL.xex 0x830FB9E8: call_seq fn_830FB148 */
ts4_word ts4_call_seq_fn_830FB148_830FB9E8(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    t1 = fn_830FB148((ts4_word)a0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FBA18: call_seq ExGetXConfigSetting */
ts4_word ts4_call_seq_ExGetXConfigSetting_830FBA18(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    t1 = ExGetXConfigSetting((ts4_word)3, (ts4_word)15, (ts4_word)a0, (ts4_word)1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FBA58: call_seq ExGetXConfigSetting */
ts4_word ts4_call_seq_ExGetXConfigSetting_830FBA58(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    t1 = ExGetXConfigSetting((ts4_word)3, (ts4_word)22, (ts4_word)a0, (ts4_word)4, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FBA98: call_seq ExGetXConfigSetting */
ts4_word ts4_call_seq_ExGetXConfigSetting_830FBA98(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    t1 = ExGetXConfigSetting((ts4_word)3, (ts4_word)25, (ts4_word)a0, (ts4_word)4, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x830FBB78: fn  */
ts4_word ts4_fn_830FBB78(ts4_word a0)
{
    return ((a0 << 3) + 276);
}

/* Loader_DLL.xex 0x830FBB88: if_fn  */
ts4_word ts4_if_fn_830FBB88(int a0)
{
    if ((int)a0 >= 0) {
        return 0;
    }
    if ((int)(a0 & 0x1fff0000) == (int)(458752)) {
        return (a0 & 0xffff);
    }
    return 1627;
}

/* Loader_DLL.xex 0x830FC2A8: fn  */
void ts4_fn_830FC2A8(void)
{
    return;
}

/* Loader_DLL.xex 0x830FC3A8: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FC3A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FC3B0: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FC3B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FC3B8: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FC3B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FC3C0: tailcall fn_830FC338 */
ts4_word ts4_tailcall_fn_830FC338_830FC3C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830FC338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FC3C8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_830FC3C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a4;
    return;
}

/* Loader_DLL.xex 0x830FC5A8: if_get u32@0x8, u32@0xc */
ts4_word ts4_if_get_u32_off8_830FC5A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 > (ts4_word)t1) {
        return ((2149056512) | 8193);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x830FCB28: call_seq u32@0x10, fn_830FC660 */
ts4_word ts4_call_seq_u32_off10_830FCB28(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)2;
    t2 = fn_830FC660((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830FCB58: call_seq u32@0x10, fn_830FC660 */
ts4_word ts4_call_seq_u32_off10_830FCB58(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)4;
    t2 = fn_830FC660((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830FCB88: call_seq u32@0x10, fn_830FC660 */
ts4_word ts4_call_seq_u32_off10_830FCB88(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)8;
    t2 = fn_830FC660((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830FCBB8: call_seq u32@0x10, fn_830FC660 */
ts4_word ts4_call_seq_u32_off10_830FCBB8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)4;
    t2 = fn_830FC660((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830FCBE8: call_seq u32@0x10, fn_830FC660 */
ts4_word ts4_call_seq_u32_off10_830FCBE8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)8;
    t2 = fn_830FC660((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830FCD20: tailcall fn_830FC738 */
ts4_word ts4_tailcall_fn_830FC738_830FCD20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830FC738((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x830FCD28: tailcall fn_830FC738 */
ts4_word ts4_tailcall_fn_830FC738_830FCD28(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830FC738((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Loader_DLL.xex 0x830FCD30: tailcall fn_830FC610 */
ts4_word ts4_tailcall_fn_830FC610_830FCD30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830FC610((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FD128: tailcall NetDll_XnpLoadConfigParams */
ts4_word ts4_tailcall_NetDll_XnpLoadConfigParams_830FD128(ts4_word a0)
{
    return NetDll_XnpLoadConfigParams((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD138: tailcall NetDll_XnpSaveConfigParams */
ts4_word ts4_tailcall_NetDll_XnpSaveConfigParams_830FD138(ts4_word a0)
{
    return NetDll_XnpSaveConfigParams((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD148: tailcall NetDll_XnpConfigUPnP */
ts4_word ts4_tailcall_NetDll_XnpConfigUPnP_830FD148(ts4_word a0)
{
    return NetDll_XnpConfigUPnP((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD158: tailcall NetDll_XnpConfig */
ts4_word ts4_tailcall_NetDll_XnpConfig_830FD158(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpConfig((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD168: tailcall NetDll_XnpGetConfigStatus */
ts4_word ts4_tailcall_NetDll_XnpGetConfigStatus_830FD168(ts4_word a0)
{
    return NetDll_XnpGetConfigStatus((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD178: tailcall NetDll_XnpLoadMachineAccount */
ts4_word ts4_tailcall_NetDll_XnpLoadMachineAccount_830FD178(ts4_word a0)
{
    return NetDll_XnpLoadMachineAccount((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD188: tailcall NetDll_XnpSaveMachineAccount */
ts4_word ts4_tailcall_NetDll_XnpSaveMachineAccount_830FD188(ts4_word a0)
{
    return NetDll_XnpSaveMachineAccount((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD198: tailcall NetDll_XnpCapture */
ts4_word ts4_tailcall_NetDll_XnpCapture_830FD198(ts4_word a0)
{
    return NetDll_XnpCapture((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD1A8: tailcall NetDll_XnpEthernetInterceptSetCallbacks */
ts4_word ts4_tailcall_NetDll_XnpEthernetInterceptSetCallbacks_830FD1A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return NetDll_XnpEthernetInterceptSetCallbacks((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830FD1C0: tailcall NetDll_XnpEthernetInterceptXmit */
ts4_word ts4_tailcall_NetDll_XnpEthernetInterceptXmit_830FD1C0(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpEthernetInterceptXmit((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD1D0: tailcall NetDll_XnpEthernetInterceptRecv */
ts4_word ts4_tailcall_NetDll_XnpEthernetInterceptRecv_830FD1D0(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpEthernetInterceptRecv((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD1E0: tailcall NetDll_XnpLogonGetStatus */
ts4_word ts4_tailcall_NetDll_XnpLogonGetStatus_830FD1E0(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpLogonGetStatus((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD1F0: tailcall NetDll_XnpLogonGetQFlags */
ts4_word ts4_tailcall_NetDll_XnpLogonGetQFlags_830FD1F0(ts4_word a0)
{
    return NetDll_XnpLogonGetQFlags((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD200: tailcall NetDll_XnpLogonSetQFlags */
ts4_word ts4_tailcall_NetDll_XnpLogonSetQFlags_830FD200(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XnpLogonSetQFlags((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FD218: tailcall NetDll_XnpLogonSetQEvent */
ts4_word ts4_tailcall_NetDll_XnpLogonSetQEvent_830FD218(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpLogonSetQEvent((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD228: tailcall NetDll_XnpLogonClearQEvent */
ts4_word ts4_tailcall_NetDll_XnpLogonClearQEvent_830FD228(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpLogonClearQEvent((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD238: tailcall NetDll_XnpLogonGetQVals */
ts4_word ts4_tailcall_NetDll_XnpLogonGetQVals_830FD238(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XnpLogonGetQVals((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FD250: tailcall NetDll_XnpLogonSetQVals */
ts4_word ts4_tailcall_NetDll_XnpLogonSetQVals_830FD250(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XnpLogonSetQVals((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FD268: tailcall NetDll_XnpLogonSetPState */
ts4_word ts4_tailcall_NetDll_XnpLogonSetPState_830FD268(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return NetDll_XnpLogonSetPState((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x830FD290: tailcall NetDll_XnpGetVlanXboxName */
ts4_word ts4_tailcall_NetDll_XnpGetVlanXboxName_830FD290(void)
{
    return NetDll_XnpGetVlanXboxName((ts4_word)1);
}

/* Loader_DLL.xex 0x830FD298: tailcall NetDll_XnpSetVlanXboxName */
ts4_word ts4_tailcall_NetDll_XnpSetVlanXboxName_830FD298(ts4_word a0)
{
    return NetDll_XnpSetVlanXboxName((ts4_word)1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD2A8: tailcall NetDll_XnpGetActiveSocketList */
ts4_word ts4_tailcall_NetDll_XnpGetActiveSocketList_830FD2A8(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpGetActiveSocketList((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD2B8: tailcall NetDll_XnpNoteSystemTime */
ts4_word ts4_tailcall_NetDll_XnpNoteSystemTime_830FD2B8(void)
{
    return NetDll_XnpNoteSystemTime((ts4_word)1);
}

/* Loader_DLL.xex 0x830FD2C0: tailcall NetDll_XnpRegisterKeyForCallerType */
ts4_word ts4_tailcall_NetDll_XnpRegisterKeyForCallerType_830FD2C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XnpRegisterKeyForCallerType((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830FD2D8: tailcall NetDll_XnpUnregisterKeyForCallerType */
ts4_word ts4_tailcall_NetDll_XnpUnregisterKeyForCallerType_830FD2D8(ts4_word a0, ts4_word a1)
{
    return NetDll_XnpUnregisterKeyForCallerType((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830FD2E8: set u32@0x0 */
void ts4_set_u32_off0_830FD2E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FD350: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FD350(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD358: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FD358(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD360: tailcall fn_83112858 */
ts4_word ts4_tailcall_fn_83112858_830FD360(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_83112858((ts4_word)a1, (ts4_word)(a2 + 4));
}

/* Loader_DLL.xex 0x830FD3D0: tailcall fn_83112998 */
ts4_word ts4_tailcall_fn_83112998_830FD3D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_83112998((ts4_word)a1, (ts4_word)(a2 + 4));
}

/* Loader_DLL.xex 0x830FD3E0: tailcall fn_83112A88 */
ts4_word ts4_tailcall_fn_83112A88_830FD3E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_83112A88((ts4_word)a1, (ts4_word)(a2 + 4));
}

/* Loader_DLL.xex 0x830FD4D0: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FD4D0(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD4D8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FD4D8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD4E0: addr lbl_83085F70 */
ts4_word ts4_addr_lbl_83085F70_830FD4E0(void)
{
    return (ts4_word)lbl_83085F70;
}

/* Loader_DLL.xex 0x830FD4F0: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FD4F0(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FD500: call_seq u32@0x4, fn_83120540, u32@0x8, fn_83120540 */
ts4_word ts4_call_seq_u32_off4_830FD500(ts4_word a0)
{
    ts4_word t4;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    return t4;
}

/* Loader_DLL.xex 0x830FD590: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FD590(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD598: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FD598(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD5A0: if_call_seq u32@0xc, fn_83120540, u32@0x10, fn_83156690 */
ts4_word ts4_if_call_seq_u32_offc_830FD5A0(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_83156690((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x830FD750: addr lbl_83000B00 */
ts4_word ts4_addr_lbl_83000B00_830FD750(void)
{
    return (ts4_word)lbl_83000B00;
}

/* Loader_DLL.xex 0x830FD760: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FD760(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FD898: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FD898(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD8A0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FD8A0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FD8A8: addr lbl_83000B10 */
ts4_word ts4_addr_lbl_83000B10_830FD8A8(void)
{
    return (ts4_word)lbl_83000B10;
}

/* Loader_DLL.xex 0x830FD8B8: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FD8B8(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FD8F0: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FD8F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830FDC80: set u32@0x10 */
void ts4_set_u32_off10_830FDC80(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830FDC88: if_get u32@0x4, u32@0x0 */
ts4_word ts4_if_get_u32_off4_830FDC88(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return 0;
}

/* Loader_DLL.xex 0x830FDD70: set u32@0x4 */
void ts4_set_u32_off4_830FDD70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830FDEB0: set u32@0xc */
void ts4_set_u32_offc_830FDEB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830FDEB8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FDEB8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FDEC0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FDEC0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FDEC8: get u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_830FDEC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    return 0;
}

/* Loader_DLL.xex 0x830FDEE0: addr lbl_83000B58 */
ts4_word ts4_addr_lbl_83000B58_830FDEE0(void)
{
    return (ts4_word)lbl_83000B58;
}

/* Loader_DLL.xex 0x830FDEF0: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FDEF0(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FDF00: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FDF00(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FDF08: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FDF08(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FDF88: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FDF88(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FDF98: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FDF98(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FDFA8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FDFA8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FDFB0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FDFB0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FDFB8: get u32@0x4, fn_83120540 */
ts4_word ts4_get_u32_off4_830FDFB8(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x830FDFC0: addr lbl_83000B6C */
ts4_word ts4_addr_lbl_83000B6C_830FDFC0(void)
{
    return (ts4_word)lbl_83000B6C;
}

/* Loader_DLL.xex 0x830FDFD0: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FDFD0(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FDFE0: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FDFE0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830FDFF8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FDFF8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE000: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE000(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE008: addr lbl_83085F84 */
ts4_word ts4_addr_lbl_83085F84_830FE008(void)
{
    return (ts4_word)lbl_83085F84;
}

/* Loader_DLL.xex 0x830FE018: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE018(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE028: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE028(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE030: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE030(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE038: fn  */
void ts4_fn_830FE038(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE040: addr lbl_83000B80 */
ts4_word ts4_addr_lbl_83000B80_830FE040(void)
{
    return (ts4_word)lbl_83000B80;
}

/* Loader_DLL.xex 0x830FE050: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE050(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE0F8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE0F8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE100: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE100(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE108: get u32@0x4, fn_83120540 */
ts4_word ts4_get_u32_off4_830FE108(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x830FE110: addr lbl_83000BA8 */
ts4_word ts4_addr_lbl_83000BA8_830FE110(void)
{
    return (ts4_word)lbl_83000BA8;
}

/* Loader_DLL.xex 0x830FE120: addr lbl_83000B80 */
ts4_word ts4_addr_lbl_83000B80_830FE120(void)
{
    return (ts4_word)lbl_83000B80;
}

/* Loader_DLL.xex 0x830FE130: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE130(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE138: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE138(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE140: addr lbl_83000BC4 */
ts4_word ts4_addr_lbl_83000BC4_830FE140(void)
{
    return (ts4_word)lbl_83000BC4;
}

/* Loader_DLL.xex 0x830FE150: addr lbl_83000B80 */
ts4_word ts4_addr_lbl_83000B80_830FE150(void)
{
    return (ts4_word)lbl_83000B80;
}

/* Loader_DLL.xex 0x830FE160: fn  */
ts4_word ts4_fn_830FE160(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FE168: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FE168(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830FE180: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE180(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE188: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE188(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE190: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_830FE190(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)22592;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FE1A8: addr lbl_83000BE0 */
ts4_word ts4_addr_lbl_83000BE0_830FE1A8(void)
{
    return (ts4_word)lbl_83000BE0;
}

/* Loader_DLL.xex 0x830FE1B8: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE1B8(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE260: addr lbl_83000BF8 */
ts4_word ts4_addr_lbl_83000BF8_830FE260(void)
{
    return (ts4_word)lbl_83000BF8;
}

/* Loader_DLL.xex 0x830FE270: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE270(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE318: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE318(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE320: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE320(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE328: fn  */
void ts4_fn_830FE328(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE330: addr lbl_83000C18 */
ts4_word ts4_addr_lbl_83000C18_830FE330(void)
{
    return (ts4_word)lbl_83000C18;
}

/* Loader_DLL.xex 0x830FE340: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE340(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE350: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FE350(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830FE368: addr lbl_83000C34 */
ts4_word ts4_addr_lbl_83000C34_830FE368(void)
{
    return (ts4_word)lbl_83000C34;
}

/* Loader_DLL.xex 0x830FE378: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE378(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE388: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE388(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE390: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE390(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE398: addr lbl_83000C58 */
ts4_word ts4_addr_lbl_83000C58_830FE398(void)
{
    return (ts4_word)lbl_83000C58;
}

/* Loader_DLL.xex 0x830FE3A8: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE3A8(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE3B8: fn  */
void ts4_fn_830FE3B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE3C0: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FE3C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830FE408: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE408(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE410: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE410(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE418: addr lbl_83000C6C */
ts4_word ts4_addr_lbl_83000C6C_830FE418(void)
{
    return (ts4_word)lbl_83000C6C;
}

/* Loader_DLL.xex 0x830FE428: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE428(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE438: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE438(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE440: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE440(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE448: addr lbl_83000C80 */
ts4_word ts4_addr_lbl_83000C80_830FE448(void)
{
    return (ts4_word)lbl_83000C80;
}

/* Loader_DLL.xex 0x830FE458: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE458(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE468: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FE468(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830FE480: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE480(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE488: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE488(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE490: fn  */
void ts4_fn_830FE490(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE498: addr lbl_83000C9C */
ts4_word ts4_addr_lbl_83000C9C_830FE498(void)
{
    return (ts4_word)lbl_83000C9C;
}

/* Loader_DLL.xex 0x830FE4A8: addr lbl_83000BE0 */
ts4_word ts4_addr_lbl_83000BE0_830FE4A8(void)
{
    return (ts4_word)lbl_83000BE0;
}

/* Loader_DLL.xex 0x830FE4B8: if_set u32@0x4 */
ts4_word ts4_if_set_u32_off4_830FE4B8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 >= 6) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x830FE4D8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE4D8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE4E0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE4E0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE4E8: fn  */
void ts4_fn_830FE4E8(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE4F0: addr lbl_83000CB4 */
ts4_word ts4_addr_lbl_83000CB4_830FE4F0(void)
{
    return (ts4_word)lbl_83000CB4;
}

/* Loader_DLL.xex 0x830FE500: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE500(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE510: if_set u32@0x4 */
ts4_word ts4_if_set_u32_off4_830FE510(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 >= 4) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x830FE530: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE530(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE538: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE538(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE540: fn  */
void ts4_fn_830FE540(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE548: addr lbl_83000CD0 */
ts4_word ts4_addr_lbl_83000CD0_830FE548(void)
{
    return (ts4_word)lbl_83000CD0;
}

/* Loader_DLL.xex 0x830FE558: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE558(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE568: if_set u32@0x4 */
ts4_word ts4_if_set_u32_off4_830FE568(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 >= 2) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x830FE588: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE588(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE590: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE590(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE598: addr lbl_83000CEC */
ts4_word ts4_addr_lbl_83000CEC_830FE598(void)
{
    return (ts4_word)lbl_83000CEC;
}

/* Loader_DLL.xex 0x830FE5A8: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE5A8(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE5B8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE5B8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE5C0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE5C0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE5C8: addr lbl_83000CFC */
ts4_word ts4_addr_lbl_83000CFC_830FE5C8(void)
{
    return (ts4_word)lbl_83000CFC;
}

/* Loader_DLL.xex 0x830FE5D8: addr lbl_83000CEC */
ts4_word ts4_addr_lbl_83000CEC_830FE5D8(void)
{
    return (ts4_word)lbl_83000CEC;
}

/* Loader_DLL.xex 0x830FE5E8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE5E8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE5F0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE5F0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE5F8: addr lbl_83000D18 */
ts4_word ts4_addr_lbl_83000D18_830FE5F8(void)
{
    return (ts4_word)lbl_83000D18;
}

/* Loader_DLL.xex 0x830FE608: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE608(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE618: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE618(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE620: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE620(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE628: addr lbl_83000D30 */
ts4_word ts4_addr_lbl_83000D30_830FE628(void)
{
    return (ts4_word)lbl_83000D30;
}

/* Loader_DLL.xex 0x830FE638: addr lbl_83000CEC */
ts4_word ts4_addr_lbl_83000CEC_830FE638(void)
{
    return (ts4_word)lbl_83000CEC;
}

/* Loader_DLL.xex 0x830FE648: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE648(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE650: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE650(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE658: addr lbl_83000D50 */
ts4_word ts4_addr_lbl_83000D50_830FE658(void)
{
    return (ts4_word)lbl_83000D50;
}

/* Loader_DLL.xex 0x830FE668: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE668(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE678: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE678(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE680: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE680(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE688: addr lbl_83000D70 */
ts4_word ts4_addr_lbl_83000D70_830FE688(void)
{
    return (ts4_word)lbl_83000D70;
}

/* Loader_DLL.xex 0x830FE698: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE698(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE6A8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE6A8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE6B0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE6B0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE6B8: set u32@0x0, u32@0x4, u32@0x8, u8@0xc */
void ts4_set_u32_off0_830FE6B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
    return;
}

/* Loader_DLL.xex 0x830FE720: addr lbl_83000D8C */
ts4_word ts4_addr_lbl_83000D8C_830FE720(void)
{
    return (ts4_word)lbl_83000D8C;
}

/* Loader_DLL.xex 0x830FE730: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE730(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE740: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE740(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE748: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE748(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE750: addr lbl_83000D9C */
ts4_word ts4_addr_lbl_83000D9C_830FE750(void)
{
    return (ts4_word)lbl_83000D9C;
}

/* Loader_DLL.xex 0x830FE760: addr lbl_83000B24 */
ts4_word ts4_addr_lbl_83000B24_830FE760(void)
{
    return (ts4_word)lbl_83000B24;
}

/* Loader_DLL.xex 0x830FE770: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE770(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE778: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE778(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE780: addr lbl_83000DB0 */
ts4_word ts4_addr_lbl_83000DB0_830FE780(void)
{
    return (ts4_word)lbl_83000DB0;
}

/* Loader_DLL.xex 0x830FE790: addr lbl_83085F84 */
ts4_word ts4_addr_lbl_83085F84_830FE790(void)
{
    return (ts4_word)lbl_83085F84;
}

/* Loader_DLL.xex 0x830FE7A0: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE7A0(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE7A8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE7A8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE7B0: set u32@0x0, u32@0x78, u32@0x74, u32@0x84, u32@0x4, u8@0x8 */
void ts4_set_u32_off0_830FE7B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FE7E0: call_seq fn_831221D0, u32@0x0, fn_83120540 */
ts4_word ts4_call_seq_fn_831221D0_830FE7E0(ts4_word a0)
{
    ts4_word t3;

    fn_831221D0((ts4_word)a0);
    t3 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t3;
}

/* Loader_DLL.xex 0x830FE818: set u8@0x8 */
void ts4_set_u8_off8_830FE818(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)1;
    return;
}

/* Loader_DLL.xex 0x830FE828: set u32@0x4, u8@0x8 */
ts4_word ts4_set_u32_off4_830FE828(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)1;
    return 0;
}

/* Loader_DLL.xex 0x830FE840: if_get u32@0x0, u32@0x4, u32@0x80 */
ts4_word ts4_if_get_u32_off0_830FE840(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 3) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return 0;
}

/* Loader_DLL.xex 0x830FE870: addr lbl_83000DCC */
ts4_word ts4_addr_lbl_83000DCC_830FE870(void)
{
    return (ts4_word)lbl_83000DCC;
}

/* Loader_DLL.xex 0x830FE880: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE880(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE890: addr lbl_83000DF0 */
ts4_word ts4_addr_lbl_83000DF0_830FE890(void)
{
    return (ts4_word)lbl_83000DF0;
}

/* Loader_DLL.xex 0x830FE8A0: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE8A0(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE8B0: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE8B0(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE8B8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE8B8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE8C0: fn  */
void ts4_fn_830FE8C0(void)
{
    return;
}

/* Loader_DLL.xex 0x830FE8C8: addr lbl_83000E04 */
ts4_word ts4_addr_lbl_83000E04_830FE8C8(void)
{
    return (ts4_word)lbl_83000E04;
}

/* Loader_DLL.xex 0x830FE8D8: addr lbl_83085F84 */
ts4_word ts4_addr_lbl_83085F84_830FE8D8(void)
{
    return (ts4_word)lbl_83085F84;
}

/* Loader_DLL.xex 0x830FE8E8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE8E8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE8F0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE8F0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE8F8: if_call_seq u32@0x8, fn_83120540, u32@0x1c, fn_8314E0B8 */
ts4_word ts4_if_call_seq_u32_off8_830FE8F8(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_8314E0B8((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x830FE938: addr lbl_83000E1C */
ts4_word ts4_addr_lbl_83000E1C_830FE938(void)
{
    return (ts4_word)lbl_83000E1C;
}

/* Loader_DLL.xex 0x830FE948: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE948(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FE9D0: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FE9D0(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE9D8: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FE9D8(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FE9E0: get u32@0x4, fn_83120540 */
ts4_word ts4_get_u32_off4_830FE9E0(ts4_word a0)
{
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x830FE9E8: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FE9E8(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FE9F8: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_830FE9F8(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x830FEA08: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEA08(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEA10: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEA10(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEA18: if_call_seq u32@0xf8, fn_83120540, fn_8315C880 */
ts4_word ts4_if_call_seq_u32_offf8_830FEA18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 248);
    if ((ts4_word)t1 != 0) {
        fn_83120540((ts4_word)t1);
    }
    t4 = fn_8315C880((ts4_word)(a0 + 4));
    return t4;
}

/* Loader_DLL.xex 0x830FEA58: addr lbl_83000E48 */
ts4_word ts4_addr_lbl_83000E48_830FEA58(void)
{
    return (ts4_word)lbl_83000E48;
}

/* Loader_DLL.xex 0x830FEA68: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEA68(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEA78: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEA78(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEA80: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEA80(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEA88: fn  */
ts4_word ts4_fn_830FEA88(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEA90: addr lbl_83000E6C */
ts4_word ts4_addr_lbl_83000E6C_830FEA90(void)
{
    return (ts4_word)lbl_83000E6C;
}

/* Loader_DLL.xex 0x830FEAA0: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEAA0(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEAB0: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEAB0(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEAB8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEAB8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEAC0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEAC0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEAC8: fn  */
ts4_word ts4_fn_830FEAC8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEAD0: addr lbl_83000E94 */
ts4_word ts4_addr_lbl_83000E94_830FEAD0(void)
{
    return (ts4_word)lbl_83000E94;
}

/* Loader_DLL.xex 0x830FEAE0: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEAE0(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEAF0: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEAF0(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEAF8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEAF8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB00: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEB00(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB08: fn  */
ts4_word ts4_fn_830FEB08(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEB10: addr lbl_83000EB8 */
ts4_word ts4_addr_lbl_83000EB8_830FEB10(void)
{
    return (ts4_word)lbl_83000EB8;
}

/* Loader_DLL.xex 0x830FEB20: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEB20(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEB30: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEB30(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB38: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEB38(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB40: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEB40(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB48: fn  */
ts4_word ts4_fn_830FEB48(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEB50: addr lbl_83000EE0 */
ts4_word ts4_addr_lbl_83000EE0_830FEB50(void)
{
    return (ts4_word)lbl_83000EE0;
}

/* Loader_DLL.xex 0x830FEB60: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEB60(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEB70: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEB70(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB78: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEB78(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB80: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEB80(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEB88: fn  */
ts4_word ts4_fn_830FEB88(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEB90: addr lbl_83000EFC */
ts4_word ts4_addr_lbl_83000EFC_830FEB90(void)
{
    return (ts4_word)lbl_83000EFC;
}

/* Loader_DLL.xex 0x830FEBA0: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEBA0(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEBB0: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEBB0(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEBB8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEBB8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEBC0: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEBC0(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEBC8: fn  */
ts4_word ts4_fn_830FEBC8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEBD0: addr lbl_83000F1C */
ts4_word ts4_addr_lbl_83000F1C_830FEBD0(void)
{
    return (ts4_word)lbl_83000F1C;
}

/* Loader_DLL.xex 0x830FEBE0: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEBE0(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEBF0: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEBF0(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEBF8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FEBF8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEC00: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_830FEC00(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEC08: fn  */
ts4_word ts4_fn_830FEC08(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830FEC10: addr lbl_83000F3C */
ts4_word ts4_addr_lbl_83000F3C_830FEC10(void)
{
    return (ts4_word)lbl_83000F3C;
}

/* Loader_DLL.xex 0x830FEC20: addr lbl_83000E34 */
ts4_word ts4_addr_lbl_83000E34_830FEC20(void)
{
    return (ts4_word)lbl_83000E34;
}

/* Loader_DLL.xex 0x830FEC30: tailcall fn_8315C668 */
ts4_word ts4_tailcall_fn_8315C668_830FEC30(ts4_word a0)
{
    return fn_8315C668((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FEC80: fn  */
void ts4_fn_830FEC80(void)
{
    return;
}

/* Loader_DLL.xex 0x830FEC88: fn  */
ts4_word ts4_fn_830FEC88(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (a1 & 0xffff);
}

/* Loader_DLL.xex 0x830FEC90: fn  */
ts4_word ts4_fn_830FEC90(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ((a1) >> 16);
}

/* Loader_DLL.xex 0x830FECF8: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_830FECF8(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FED00: fn  */
void ts4_fn_830FED00(void)
{
    return;
}

/* Loader_DLL.xex 0x830FEDD0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830FEDD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FEE98: fn  */
void ts4_fn_830FEE98(void)
{
    return;
}

/* Loader_DLL.xex 0x830FEFF8: set u32@0x0 */
ts4_word ts4_set_u32_off0_830FEFF8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    return 0;
}

/* Loader_DLL.xex 0x830FF008: get u32@0x0 */
ts4_word ts4_get_u32_off0_830FF008(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830FF010: fn  */
void ts4_fn_830FF010(void)
{
    return;
}

/* Loader_DLL.xex 0x830FF1B8: fn  */
ts4_word ts4_fn_830FF1B8(void)
{
    return 12;
}

/* Loader_DLL.xex 0x830FF220: if_get u32@0x28, u32@0x0 */
ts4_word ts4_if_get_u32_off28_830FF220(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x830FFB50: get u32@lbl_8352F848, u32@lbl_8352F848 */
ts4_word ts4_get_u32_lbl_8352F848_830FFB50(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_8352F848;
    *(ts4_word *)lbl_8352F848 = (ts4_word)a0;
    return t1;
}

/* Loader_DLL.xex 0x830FFBE0: tailcall fn_8313EBD8 */
ts4_word ts4_tailcall_fn_8313EBD8_830FFBE0(ts4_word a0)
{
    return fn_8313EBD8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830FFCC0: tailcall fn_830FFC68 */
ts4_word ts4_tailcall_fn_830FFC68_830FFCC0(ts4_word a0)
{
    return fn_830FFC68((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x830FFCC8: get u32@lbl_8352F8C8 */
ts4_word ts4_get_u32_lbl_8352F8C8_830FFCC8(void)
{
    return (*(ts4_word *)lbl_8352F8C8);
}

/* Loader_DLL.xex 0x830FFCD8: get u32@lbl_8352F8CC */
ts4_word ts4_get_u32_lbl_8352F8CC_830FFCD8(void)
{
    return (*(ts4_word *)lbl_8352F8CC);
}

/* Loader_DLL.xex 0x830FFCE8: set u32@lbl_8352F8CC */
ts4_word ts4_set_u32_lbl_8352F8CC_830FFCE8(ts4_word a0)
{
    *(ts4_word *)lbl_8352F8CC = (ts4_word)a0;
    return 0;
}

/* Loader_DLL.xex 0x830FFD00: if_call_seq fn_8311BC38, fn_8311DA08 */
ts4_word ts4_if_call_seq_fn_8311BC38_830FFD00(void)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8311BC38();
    t2 = fn_8311DA08((ts4_word)t1);
    p3 = (ts4_word)t2;
    if ((ts4_word)t1 < (ts4_word)t2) {
        p3 = (ts4_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x830FFD40: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830FFD40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FFD58: fn  */
void ts4_fn_830FFD58(void)
{
    return;
}

/* Loader_DLL.xex 0x830FFD60: fn  */
void ts4_fn_830FFD60(void)
{
    return;
}

/* Loader_DLL.xex 0x830FFD68: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830FFD68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830FFD80: fn  */
void ts4_fn_830FFD80(void)
{
    return;
}

/* Loader_DLL.xex 0x830FFD88: fn  */
void ts4_fn_830FFD88(void)
{
    return;
}
