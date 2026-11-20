/* Loader_DLL.xex 0x833E1758-0x834402E8, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char __imp_KeDebugMonitorData[];
extern char __imp_KeTimeStampBundle[];
extern char lbl_830719D0[];
extern char lbl_83073BAC[];
extern char lbl_83073C1C[];
extern char lbl_83073C78[];
extern char lbl_83086AC0[];
extern char lbl_8352C928[];
extern char lbl_8352D368[];
extern char lbl_835446B8[];
extern char lbl_8354472C[];
extern char lbl_8354BA9C[];
extern char lbl_8354BAC0[];
ts4_word DbgBreakPoint();
ts4_word KeQuerySystemTime();
ts4_word MmFreePhysicalMemory();
ts4_word MmQueryAddressProtect();
ts4_word MmQueryAllocationSize();
ts4_word MmSetAddressProtect();
ts4_word NtAllocateVirtualMemory();
ts4_word RtlInitAnsiString();
ts4_word XMsgCancelIORequest();
ts4_word XamContentClose();
ts4_word XamContentCreateDeviceEnumerator();
ts4_word XamContentCreateEnumerator();
ts4_word XamContentDelete();
ts4_word XamContentFlush();
ts4_word XamContentGetCreator();
ts4_word XamContentGetDeviceData();
ts4_word XamContentGetDeviceName();
ts4_word XamContentGetDeviceState();
ts4_word XamContentGetLicenseMask();
ts4_word XamContentGetThumbnail();
ts4_word XamContentInstall();
ts4_word XamContentLaunchImage();
ts4_word XamContentSetThumbnail();
ts4_word XamEnumerate();
ts4_word XamInputGetCapabilities();
ts4_word XamInputGetKeystrokeEx();
ts4_word XamInputGetState();
ts4_word XamInputSetState();
ts4_word XamNotifyCreateListener();
ts4_word XamShowAchievementsUI();
ts4_word XamShowDeviceSelectorUI();
ts4_word XamShowFriendRequestUI();
ts4_word XamShowFriendsUI();
ts4_word XamShowGameInviteUI();
ts4_word XamShowGamerCardUIForXUID();
ts4_word XamShowKeyboardUI();
ts4_word XamShowMarketplaceUI();
ts4_word XamShowMessageComposeUI();
ts4_word XamShowMessagesUI();
ts4_word XamShowPlayerReviewUI();
ts4_word XamShowPlayersUI();
ts4_word XamShowQuickChatUI();
ts4_word XamShowSigninUI();
ts4_word XamShowSigninUIp();
ts4_word XamUserAreUsersFriends();
ts4_word XamUserGetName();
ts4_word XamUserGetSigninState();
ts4_word XamWriteGamerTile();
ts4_word XexUnloadImageAndExitThread();
ts4_word fn_830A6B40();
ts4_word fn_830A6F10();
ts4_word fn_830AAAE8();
ts4_word fn_830AD500();
ts4_word fn_830AD6B8();
ts4_word fn_830ADA20();
ts4_word fn_830ADAE0();
ts4_word fn_830ADB08();
ts4_word fn_830ADB20();
ts4_word fn_830ADB30();
ts4_word fn_830ADBF0();
ts4_word fn_830ADC18();
ts4_word fn_830ADC30();
ts4_word fn_830ADD00();
ts4_word fn_830ADD08();
ts4_word fn_830ADD20();
ts4_word fn_830ADDF8();
ts4_word fn_830ADE30();
ts4_word fn_830AE0A0();
ts4_word fn_830AE138();
ts4_word fn_830AE180();
ts4_word fn_830AE1D0();
ts4_word fn_830AE218();
ts4_word fn_830AE238();
ts4_word fn_830AF1B8();
ts4_word fn_830AF238();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();
ts4_word fn_833E74C0();
ts4_word fn_833E8028();
ts4_word fn_833E8F10();
ts4_word fn_833E9D20();
ts4_word fn_833F1488();
ts4_word fn_833F1780();
ts4_word fn_833F9A70();
ts4_word fn_834005F8();
ts4_word fn_83400E00();
ts4_word fn_834024E0();
ts4_word fn_83402F40();
ts4_word fn_83404508();
ts4_word fn_83406A60();
ts4_word fn_8340A360();
ts4_word fn_8340B330();
ts4_word fn_8340B3C8();
ts4_word fn_8340B530();
ts4_word fn_8340C1C8();
ts4_word fn_8340C4F8();
ts4_word fn_8340D540();
ts4_word fn_8340D710();
ts4_word fn_8340D830();
ts4_word fn_8340F070();
ts4_word fn_8340F088();
ts4_word fn_8340F0C0();
ts4_word fn_83413818();
ts4_word fn_834157A0();
ts4_word fn_83415B08();
ts4_word fn_83415ED8();
ts4_word fn_83417B48();
ts4_word fn_834182E8();
ts4_word fn_83418768();
ts4_word fn_8341A740();
ts4_word fn_8341AB10();
ts4_word fn_8341D120();
ts4_word fn_8341DB10();
ts4_word fn_8341DCF0();
ts4_word fn_83421328();
ts4_word fn_83423158();
ts4_word fn_8342B0F0();
ts4_word fn_8342F1D8();
ts4_word fn_8342F2D8();
ts4_word fn_834306C8();
ts4_word fn_8343C240();
ts4_word fn_8343D800();
ts4_word fn_8343F8F8();
ts4_word fn_8343FED0();
ts4_word fn_8344C6B0();
ts4_word fn_8344C708();
ts4_word fn_8344E298();
ts4_word fn_8344E300();
ts4_word fn_8346A510();
#ifndef _MSC_VER
#define vsprintf ts4_host_vsprintf
#endif
ts4_word vsprintf();

/* Loader_DLL.xex 0x833E1758: tailcall fn_833E74C0 */
ts4_word ts4_tailcall_fn_833E74C0_833E1758(ts4_word a0)
{
    return fn_833E74C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x833E86A0: call_seq fn_833E8028, fn_833E9D20, fn_833E8F10, fn_833F9A70 */
ts4_word ts4_call_seq_fn_833E8028_833E86A0(void)
{
    ts4_word t4;

    fn_833E8028((ts4_word)0);
    fn_833E9D20((ts4_word)0);
    fn_833E8F10((ts4_word)0);
    t4 = fn_833F9A70((ts4_word)0);
    return t4;
}

/* Loader_DLL.xex 0x833F1760: tailcall fn_833F1488 */
ts4_word ts4_tailcall_fn_833F1488_833F1760(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1488((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F1768: tailcall fn_833F1488 */
ts4_word ts4_tailcall_fn_833F1488_833F1768(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1488((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F1A40: tailcall fn_833F1780 */
ts4_word ts4_tailcall_fn_833F1780_833F1A40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1780((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x833F1A48: tailcall fn_833F1780 */
ts4_word ts4_tailcall_fn_833F1780_833F1A48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833F1780((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x83400990: get u8@0x4 */
ts4_word ts4_get_u8_off4_83400990(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x83400AB0: get u32@0x8 */
ts4_word ts4_get_u32_off8_83400AB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83400CF0: loop_get u8@0x0 */
void ts4_loop_get_u8_off0_83400CF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;

    if ((ts4_word)a2 == 0) {
        return;
    }
    c1 = (ts4_word)a2;
    lv2 = (ts4_word)a0;
    do {
        *(unsigned char *)((char *)(ts4_word)(lv2) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((a1 - a0)) + lv2));
        p4 = (ts4_word)(lv2 + 1);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x83400ED0: addr lbl_835446B8, fn_834005F8 */
ts4_word ts4_addr_lbl_835446B8_83400ED0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return fn_834005F8((ts4_word)(ts4_word)lbl_835446B8, (ts4_word)a0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83401460: get u32@0x8 */
ts4_word ts4_get_u32_off8_83401460(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x83401468: if_get u32@0x8, u32@0x4, u8@-0x1 */
ts4_word ts4_if_get_u32_off8_83401468(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0) {
        return (*(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + t1)) + -1));
    }
    return 0;
}

/* Loader_DLL.xex 0x83401590: call_seq fn_83400E00 */
ts4_word ts4_call_seq_fn_83400E00_83401590(ts4_word a0)
{
    fn_83400E00((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x83402E98: call_seq fn_834024E0 */
ts4_word ts4_call_seq_fn_834024E0_83402E98(ts4_word a0)
{
    fn_834024E0((ts4_word)a0, (ts4_word)1);
    return a0;
}

/* Loader_DLL.xex 0x83402ED0: call_seq fn_834024E0 */
ts4_word ts4_call_seq_fn_834024E0_83402ED0(ts4_word a0)
{
    fn_834024E0((ts4_word)a0, (ts4_word)0);
    return a0;
}

/* Loader_DLL.xex 0x83402F08: call_seq fn_834024E0 */
ts4_word ts4_call_seq_fn_834024E0_83402F08(ts4_word a0)
{
    fn_834024E0((ts4_word)a0, (ts4_word)0);
    return a0;
}

/* Loader_DLL.xex 0x83403750: call_seq fn_83402F40 */
ts4_word ts4_call_seq_fn_83402F40_83403750(ts4_word a0)
{
    fn_83402F40();
    return a0;
}

/* Loader_DLL.xex 0x83404658: call_seq fn_83404508 */
ts4_word ts4_call_seq_fn_83404508_83404658(ts4_word a0)
{
    fn_83404508();
    return a0;
}

/* Loader_DLL.xex 0x83406BB8: call_seq lbl_830719D0, fn_83406A60 */
ts4_word ts4_call_seq_lbl_830719D0_83406BB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_83406A60((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)lbl_830719D0);
    return a0;
}

/* Loader_DLL.xex 0x83406BF0: call_seq lbl_83086AC0, fn_83406A60 */
ts4_word ts4_call_seq_lbl_83086AC0_83406BF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_83406A60((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)lbl_83086AC0);
    return a0;
}

/* Loader_DLL.xex 0x83406C28: call_seq fn_83406A60 */
ts4_word ts4_call_seq_fn_83406A60_83406C28(ts4_word a0)
{
    fn_83406A60();
    return a0;
}

/* Loader_DLL.xex 0x83407808: fn  */
ts4_word ts4_fn_83407808(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83407810: if_get u32@0x0, u32@0xac */
ts4_word ts4_if_get_u32_off0_83407810(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 1;
    }
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 172));
}

/* Loader_DLL.xex 0x83407830: fn  */
ts4_word ts4_fn_83407830(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83407838: fn  */
ts4_word ts4_fn_83407838(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83407840: addr lbl_8352C928 */
ts4_word ts4_addr_lbl_8352C928_83407840(void)
{
    return ((ts4_word)lbl_8352C928 + 12);
}

/* Loader_DLL.xex 0x8340AA10: tailcall XamContentDelete */
ts4_word ts4_tailcall_XamContentDelete_8340AA10(ts4_word a0)
{
    return XamContentDelete((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA18: tailcall XamContentInstall */
ts4_word ts4_tailcall_XamContentInstall_8340AA18(ts4_word a0)
{
    return XamContentInstall((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA20: tailcall XamContentClose */
ts4_word ts4_tailcall_XamContentClose_8340AA20(ts4_word a0)
{
    return XamContentClose((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA28: tailcall XamContentFlush */
ts4_word ts4_tailcall_XamContentFlush_8340AA28(ts4_word a0)
{
    return XamContentFlush((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA30: tailcall XamContentSetThumbnail */
ts4_word ts4_tailcall_XamContentSetThumbnail_8340AA30(ts4_word a0)
{
    return XamContentSetThumbnail((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA38: tailcall XamContentGetThumbnail */
ts4_word ts4_tailcall_XamContentGetThumbnail_8340AA38(ts4_word a0)
{
    return XamContentGetThumbnail((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA40: tailcall XamContentGetCreator */
ts4_word ts4_tailcall_XamContentGetCreator_8340AA40(ts4_word a0)
{
    return XamContentGetCreator((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA48: tailcall XamContentGetLicenseMask */
ts4_word ts4_tailcall_XamContentGetLicenseMask_8340AA48(ts4_word a0)
{
    return XamContentGetLicenseMask((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA50: tailcall XamContentCreateEnumerator */
ts4_word ts4_tailcall_XamContentCreateEnumerator_8340AA50(ts4_word a0)
{
    return XamContentCreateEnumerator((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA58: tailcall XamContentCreateDeviceEnumerator */
ts4_word ts4_tailcall_XamContentCreateDeviceEnumerator_8340AA58(ts4_word a0)
{
    return XamContentCreateDeviceEnumerator((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA60: tailcall XamContentGetDeviceState */
ts4_word ts4_tailcall_XamContentGetDeviceState_8340AA60(ts4_word a0)
{
    return XamContentGetDeviceState((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA68: get u32@0x0, XamContentGetDeviceState */
ts4_word ts4_get_u32_off0_8340AA68(ts4_word a0)
{
    return XamContentGetDeviceState((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x8340AA70: tailcall XamContentGetDeviceData */
ts4_word ts4_tailcall_XamContentGetDeviceData_8340AA70(ts4_word a0)
{
    return XamContentGetDeviceData((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA78: tailcall XamContentGetDeviceName */
ts4_word ts4_tailcall_XamContentGetDeviceName_8340AA78(ts4_word a0)
{
    return XamContentGetDeviceName((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AA80: tailcall XamContentLaunchImage */
ts4_word ts4_tailcall_XamContentLaunchImage_8340AA80(ts4_word a0)
{
    return XamContentLaunchImage((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340AF50: tailcall XexUnloadImageAndExitThread */
ts4_word ts4_tailcall_XexUnloadImageAndExitThread_8340AF50(ts4_word a0)
{
    return XexUnloadImageAndExitThread((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340B0D0: tailcall XamInputGetCapabilities */
ts4_word ts4_tailcall_XamInputGetCapabilities_8340B0D0(ts4_word a0)
{
    return XamInputGetCapabilities((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340B0D8: tailcall XamInputGetState */
ts4_word ts4_tailcall_XamInputGetState_8340B0D8(ts4_word a0)
{
    return XamInputGetState((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340B0E0: tailcall XamInputGetState */
ts4_word ts4_tailcall_XamInputGetState_8340B0E0(ts4_word a0, ts4_word a1)
{
    return XamInputGetState((ts4_word)a0, (ts4_word)1, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8340B1B8: tailcall XamInputSetState */
ts4_word ts4_tailcall_XamInputSetState_8340B1B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return XamInputSetState((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x8340B1D0: if_get u32@0x0, u32@0x0, XamInputGetKeystrokeEx */
ts4_word ts4_if_get_u32_off0_8340B1D0(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)a1;
    if ((ts4_word)t1 == 255) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)(a1 | 1073741824);
    }
    return XamInputGetKeystrokeEx((ts4_word)a0, (ts4_word)p3);
}

/* Loader_DLL.xex 0x8340B230: tailcall XamNotifyCreateListener */
ts4_word ts4_tailcall_XamNotifyCreateListener_8340B230(ts4_word a0)
{
    return XamNotifyCreateListener((ts4_word)a0, (ts4_word)7);
}

/* Loader_DLL.xex 0x8340B328: fn  */
ts4_word ts4_fn_8340B328(void)
{
    return 1627;
}

/* Loader_DLL.xex 0x8340B3C0: tailcall fn_8340B330 */
ts4_word ts4_tailcall_fn_8340B330_8340B3C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8340B330((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340B480: tailcall fn_8340B3C8 */
ts4_word ts4_tailcall_fn_8340B3C8_8340B480(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8340B3C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340B488: tailcall XamUserGetName */
ts4_word ts4_tailcall_XamUserGetName_8340B488(ts4_word a0)
{
    return XamUserGetName((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340B490: tailcall XamUserGetSigninState */
ts4_word ts4_tailcall_XamUserGetSigninState_8340B490(ts4_word a0)
{
    return XamUserGetSigninState((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340B498: tailcall XamUserAreUsersFriends */
ts4_word ts4_tailcall_XamUserAreUsersFriends_8340B498(ts4_word a0)
{
    return XamUserAreUsersFriends((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340B5B0: tailcall fn_8340B530 */
ts4_word ts4_tailcall_fn_8340B530_8340B5B0(ts4_word a0, ts4_word a1)
{
    return fn_8340B530((ts4_word)-1, (ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8340B978: tailcall XamWriteGamerTile */
ts4_word ts4_tailcall_XamWriteGamerTile_8340B978(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return XamWriteGamerTile((ts4_word)a0, (ts4_word)0, (ts4_word)(a1 | 131072), (ts4_word)(a1 | 65536), (ts4_word)1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8340BB40: tailcall XamShowSigninUI */
ts4_word ts4_tailcall_XamShowSigninUI_8340BB40(ts4_word a0)
{
    return XamShowSigninUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BB48: tailcall XamShowSigninUIp */
ts4_word ts4_tailcall_XamShowSigninUIp_8340BB48(ts4_word a0)
{
    return XamShowSigninUIp((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BB50: tailcall XamShowFriendsUI */
ts4_word ts4_tailcall_XamShowFriendsUI_8340BB50(ts4_word a0)
{
    return XamShowFriendsUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BB58: tailcall XamShowPlayersUI */
ts4_word ts4_tailcall_XamShowPlayersUI_8340BB58(ts4_word a0)
{
    return XamShowPlayersUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BB60: tailcall XamShowMessagesUI */
ts4_word ts4_tailcall_XamShowMessagesUI_8340BB60(ts4_word a0)
{
    return XamShowMessagesUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BB68: tailcall XamShowKeyboardUI */
ts4_word ts4_tailcall_XamShowKeyboardUI_8340BB68(ts4_word a0)
{
    return XamShowKeyboardUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BB70: tailcall XamShowQuickChatUI */
ts4_word ts4_tailcall_XamShowQuickChatUI_8340BB70(ts4_word a0)
{
    return XamShowQuickChatUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BBC0: tailcall XamShowGamerCardUIForXUID */
ts4_word ts4_tailcall_XamShowGamerCardUIForXUID_8340BBC0(ts4_word a0, ts4_word a1)
{
    return XamShowGamerCardUIForXUID((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340BBC8: tailcall XamShowAchievementsUI */
ts4_word ts4_tailcall_XamShowAchievementsUI_8340BBC8(ts4_word a0)
{
    return XamShowAchievementsUI((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340BBD0: tailcall XamShowPlayerReviewUI */
ts4_word ts4_tailcall_XamShowPlayerReviewUI_8340BBD0(ts4_word a0)
{
    return XamShowPlayerReviewUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BBD8: tailcall XamShowMarketplaceUI */
ts4_word ts4_tailcall_XamShowMarketplaceUI_8340BBD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return XamShowMarketplaceUI((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)-1, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340BBE8: tailcall XamShowMarketplaceUI */
ts4_word ts4_tailcall_XamShowMarketplaceUI_8340BBE8(ts4_word a0)
{
    return XamShowMarketplaceUI((ts4_word)a0, (ts4_word)7, (ts4_word)0, (ts4_word)-1, (ts4_word)-1, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340BC00: tailcall XamShowDeviceSelectorUI */
ts4_word ts4_tailcall_XamShowDeviceSelectorUI_8340BC00(ts4_word a0)
{
    return XamShowDeviceSelectorUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BC30: tailcall XamShowMessageComposeUI */
ts4_word ts4_tailcall_XamShowMessageComposeUI_8340BC30(ts4_word a0)
{
    return XamShowMessageComposeUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BC38: tailcall XamShowGameInviteUI */
ts4_word ts4_tailcall_XamShowGameInviteUI_8340BC38(ts4_word a0)
{
    return XamShowGameInviteUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340BC40: tailcall XamShowFriendRequestUI */
ts4_word ts4_tailcall_XamShowFriendRequestUI_8340BC40(ts4_word a0)
{
    return XamShowFriendRequestUI((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340C2F8: tailcall fn_8340C1C8 */
ts4_word ts4_tailcall_fn_8340C1C8_8340C2F8(ts4_word a0)
{
    return fn_8340C1C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340C7F0: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_8340C7F0(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340C7F8: tailcall fn_834157A0 */
ts4_word ts4_tailcall_fn_834157A0_8340C7F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_834157A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)-1, (ts4_word)a5);
}

/* Loader_DLL.xex 0x8340CA88: vcall  */
ts4_word ts4_vcall_8340CA88(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word))(a0))((ts4_word)a1);
}

/* Loader_DLL.xex 0x8340CB58: get u32@lbl_8354BAC0, u32@lbl_8354BAC0 */
ts4_word ts4_get_u32_lbl_8354BAC0_8340CB58(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_8354BAC0;
    *(ts4_word *)lbl_8354BAC0 = (ts4_word)a0;
    return t1;
}

/* Loader_DLL.xex 0x8340CD58: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_8340CD58(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x8340CE50: tailcall fn_83413818 */
ts4_word ts4_tailcall_fn_83413818_8340CE50(ts4_word a0, ts4_word a1)
{
    return fn_83413818((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340CE90: tailcall fn_83415B08 */
ts4_word ts4_tailcall_fn_83415B08_8340CE90(ts4_word a0)
{
    return fn_83415B08((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340CE98: get u32@__imp_KeTimeStampBundle, u32@0x10 */
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8340CE98(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeTimeStampBundle)) + 16));
}

/* Loader_DLL.xex 0x8340D088: tailcall MmQueryAllocationSize */
ts4_word ts4_tailcall_MmQueryAllocationSize_8340D088(ts4_word a0)
{
    return MmQueryAllocationSize((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340D090: if_tailcall MmSetAddressProtect */
ts4_word ts4_if_tailcall_MmSetAddressProtect_8340D090(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return MmSetAddressProtect((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340D0A0: tailcall MmFreePhysicalMemory */
ts4_word ts4_tailcall_MmFreePhysicalMemory_8340D0A0(ts4_word a0)
{
    return MmFreePhysicalMemory((ts4_word)0, (ts4_word)a0);
}

/* Loader_DLL.xex 0x8340D0B0: tailcall MmQueryAddressProtect */
ts4_word ts4_tailcall_MmQueryAddressProtect_8340D0B0(ts4_word a0)
{
    return MmQueryAddressProtect((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340D0B8: set u32@lbl_8354472C */
void ts4_set_u32_lbl_8354472C_8340D0B8(ts4_word a0)
{
    *(ts4_word *)lbl_8354472C = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x8340D0C8: get u32@lbl_8354472C */
ts4_word ts4_get_u32_lbl_8354472C_8340D0C8(void)
{
    return (*(ts4_word *)lbl_8354472C);
}

/* Loader_DLL.xex 0x8340D118: tailcall fn_8340F0C0 */
ts4_word ts4_tailcall_fn_8340F0C0_8340D118(ts4_word a0)
{
    return fn_8340F0C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340D250: call_seq XMsgCancelIORequest */
ts4_word ts4_call_seq_XMsgCancelIORequest_8340D250(ts4_word a0)
{
    XMsgCancelIORequest((ts4_word)a0, (ts4_word)1);
    return 0;
}

/* Loader_DLL.xex 0x8340D278: tailcall XamEnumerate */
ts4_word ts4_tailcall_XamEnumerate_8340D278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return XamEnumerate((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x8340D290: tailcall XamEnumerate */
ts4_word ts4_tailcall_XamEnumerate_8340D290(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return XamEnumerate((ts4_word)a0, (ts4_word)1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x8340D670: tailcall fn_8340D540 */
ts4_word ts4_tailcall_fn_8340D540_8340D670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8340D540((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x8340D678: tailcall fn_8340A360 */
ts4_word ts4_tailcall_fn_8340A360_8340D678(ts4_word a0)
{
    return fn_8340A360((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340D870: tailcall vsprintf */
ts4_word ts4_tailcall_vsprintf_8340D870(ts4_word a0)
{
    return vsprintf((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340DC88: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_8340DC88(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x8340F018: fn  */
ts4_word ts4_fn_8340F018(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8340F020: fn  */
ts4_word ts4_fn_8340F020(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8340F028: fn  */
ts4_word ts4_fn_8340F028(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8340F030: fn  */
ts4_word ts4_fn_8340F030(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8340F038: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_8340F038(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)68, (ts4_word)0);
    }
    return 0;
}

/* Loader_DLL.xex 0x8340F068: tailcall fn_8340F070 */
ts4_word ts4_tailcall_fn_8340F070_8340F068(ts4_word a0)
{
    return fn_8340F070((ts4_word)a0);
}

/* Loader_DLL.xex 0x8340F288: call_seq RtlInitAnsiString, fn_83415ED8 */
ts4_word ts4_call_seq_RtlInitAnsiString_8340F288(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t2;

    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    *(unsigned short *)((char *)loc50 + 2) = (unsigned short)0;
    loc50[1] = (ts4_word)0;
    RtlInitAnsiString((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t2 = fn_83415ED8((ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Loader_DLL.xex 0x8340F2C8: tailcall NtAllocateVirtualMemory */
ts4_word ts4_tailcall_NtAllocateVirtualMemory_8340F2C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NtAllocateVirtualMemory((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 | 536870912));
}

/* Loader_DLL.xex 0x8340F2D0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8340F2D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x83410078: get u16@0x0, u32@-0x8 */
ts4_word ts4_get_u16_off0_83410078(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + -8)) - t1) + -48);
}

/* Loader_DLL.xex 0x83410100: set u32@-0x8 */
void ts4_set_u32_0x8_83410100(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + -8) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83410108: get u32@-0x8 */
ts4_word ts4_get_u32_0x8_83410108(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + -8));
}

/* Loader_DLL.xex 0x83410110: get u32@0x30 */
ts4_word ts4_get_u32_off30_83410110(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 48)) << 4);
}

/* Loader_DLL.xex 0x83413808: get u32@lbl_8354BA9C */
ts4_word ts4_get_u32_lbl_8354BA9C_83413808(void)
{
    return (*(ts4_word *)lbl_8354BA9C);
}

/* Loader_DLL.xex 0x834138F0: tailcall DbgBreakPoint */
ts4_word ts4_tailcall_DbgBreakPoint_834138F0(ts4_word a0)
{
    return DbgBreakPoint((ts4_word)a0);
}

/* Loader_DLL.xex 0x83413E88: if_get u32@__imp_KeDebugMonitorData, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32__imp_KeDebugMonitorData_83413E88(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 24))))((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x83414070: tailcall KeQuerySystemTime */
ts4_word ts4_tailcall_KeQuerySystemTime_83414070(ts4_word a0)
{
    return KeQuerySystemTime((ts4_word)a0);
}

/* Loader_DLL.xex 0x834141B8: tailcall fn_8340F088 */
ts4_word ts4_tailcall_fn_8340F088_834141B8(ts4_word a0)
{
    return fn_8340F088((ts4_word)a0);
}

/* Loader_DLL.xex 0x83416218: fn  */
ts4_word ts4_fn_83416218(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83416220: fn  */
void ts4_fn_83416220(void)
{
    return;
}

/* Loader_DLL.xex 0x83416228: fn  */
void ts4_fn_83416228(void)
{
    return;
}

/* Loader_DLL.xex 0x83416460: fn  */
ts4_word ts4_fn_83416460(ts4_word a0)
{
    return ((a0 >> 8) & 0x1);
}

/* Loader_DLL.xex 0x834177A0: fn  */
ts4_word ts4_fn_834177A0(ts4_word a0, ts4_word a1)
{
    return (a0 & ~(a1 + -1));
}

/* Loader_DLL.xex 0x834177C8: call_seq fn_830ADC30 */
ts4_word ts4_call_seq_fn_830ADC30_834177C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830ADC30((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x834177F0: call_seq fn_830ADA20 */
ts4_word ts4_call_seq_fn_830ADA20_834177F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830ADA20((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x83417818: call_seq fn_830ADB30 */
ts4_word ts4_call_seq_fn_830ADB30_83417818(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830ADB30((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x83417840: call_seq fn_830ADD20 */
ts4_word ts4_call_seq_fn_830ADD20_83417840(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830ADD20((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x83417868: call_seq fn_830AE0A0 */
ts4_word ts4_call_seq_fn_830AE0A0_83417868(ts4_word a0, ts4_word a1)
{
    fn_830AE0A0((ts4_word)a0, (ts4_word)a1);
    return 0;
}

/* Loader_DLL.xex 0x83417890: call_seq fn_830AE1D0 */
ts4_word ts4_call_seq_fn_830AE1D0_83417890(ts4_word a0, ts4_word a1)
{
    fn_830AE1D0((ts4_word)a0, (ts4_word)a1);
    return 0;
}

/* Loader_DLL.xex 0x83417F78: tailcall fn_83417B48 */
ts4_word ts4_tailcall_fn_83417B48_83417F78(ts4_word a0)
{
    return fn_83417B48((ts4_word)a0);
}

/* Loader_DLL.xex 0x83418740: call_seq fn_834182E8 */
ts4_word ts4_call_seq_fn_834182E8_83418740(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[6];
    ts4_word t1;

    t1 = fn_834182E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Loader_DLL.xex 0x834190F0: fn  */
void ts4_fn_834190F0(void)
{
    return;
}

/* Loader_DLL.xex 0x834191E8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_834191E8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612827136));
}

/* Loader_DLL.xex 0x834191F0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_834191F0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612827136));
}

/* Loader_DLL.xex 0x834191F8: fn  */
ts4_word ts4_fn_834191F8(ts4_word a0)
{
    return ((((a0) >> 1) >> ((a0) >> 2)) + ((a0) >> 2));
}

/* Loader_DLL.xex 0x83419210: fn  */
ts4_word ts4_fn_83419210(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return (((a2 << a3) + a0) + a1);
}

/* Loader_DLL.xex 0x83419220: fn  */
ts4_word ts4_fn_83419220(ts4_word a0)
{
    return ((((a0) >> 4) - ((a0) >> 2)) + 3);
}

/* Loader_DLL.xex 0x8341A3A8: fn  */
void ts4_fn_8341A3A8(void)
{
    return;
}

/* Loader_DLL.xex 0x8341AFF0: tailcall fn_8341A740 */
ts4_word ts4_tailcall_fn_8341A740_8341AFF0(ts4_word a0)
{
    return fn_8341A740((ts4_word)a0);
}

/* Loader_DLL.xex 0x8341B250: tailcall fn_8341AB10 */
ts4_word ts4_tailcall_fn_8341AB10_8341B250(ts4_word a0)
{
    return fn_8341AB10((ts4_word)a0);
}

/* Loader_DLL.xex 0x8341B4B8: set u32@lbl_8352D368 */
void ts4_set_u32_lbl_8352D368_8341B4B8(ts4_word a0)
{
    *(ts4_word *)lbl_8352D368 = (ts4_word)(a0 == 0);
    return;
}

/* Loader_DLL.xex 0x8341B748: tailcall fn_83418768 */
ts4_word ts4_tailcall_fn_83418768_8341B748(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83418768((ts4_word)(a0 & 0x3f), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8341B750: fn  */
ts4_word ts4_fn_8341B750(void)
{
    return 1;
}

/* Loader_DLL.xex 0x8341B758: tailcall fn_830A6B40 */
ts4_word ts4_tailcall_fn_830A6B40_8341B758(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_830A6B40((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x8341B760: call_seq fn_830A6F10 */
ts4_word ts4_call_seq_fn_830A6F10_8341B760(ts4_word a0, ts4_word a1)
{
    fn_830A6F10((ts4_word)a0, (ts4_word)a1);
    return 0;
}

/* Loader_DLL.xex 0x8341BB20: call_seq fn_830AF238 */
ts4_word ts4_call_seq_fn_830AF238_8341BB20(ts4_word a0, ts4_word a1)
{
    fn_830AF238((ts4_word)a0, (ts4_word)a1);
    return 0;
}

/* Loader_DLL.xex 0x8341BB48: tailcall fn_830AD500 */
ts4_word ts4_tailcall_fn_830AD500_8341BB48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AD500((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8341BB58: tailcall fn_830AD6B8 */
ts4_word ts4_tailcall_fn_830AD6B8_8341BB58(ts4_word a0)
{
    return fn_830AD6B8((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x8341BBA8: call_seq fn_830AD500 */
ts4_word ts4_call_seq_fn_830AD500_8341BBA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830AD500((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x8341BBD8: call_seq fn_830AD6B8 */
ts4_word ts4_call_seq_fn_830AD6B8_8341BBD8(ts4_word a0)
{
    fn_830AD6B8((ts4_word)a0, (ts4_word)0);
    return 0;
}

/* Loader_DLL.xex 0x8341BC00: if_get u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_8341BC00(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8341BC18: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8341BC18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8341BC58: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8341BC58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8341BC98: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8341BC98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8341BCD8: tailcall fn_830AD500 */
ts4_word ts4_tailcall_fn_830AD500_8341BCD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AD500((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8341BCE8: tailcall fn_830AD6B8 */
ts4_word ts4_tailcall_fn_830AD6B8_8341BCE8(ts4_word a0)
{
    return fn_830AD6B8((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x8341BD38: call_seq fn_830ADD00 */
ts4_word ts4_call_seq_fn_830ADD00_8341BD38(void)
{
    fn_830ADD00();
    return 0;
}

/* Loader_DLL.xex 0x8341BD60: call_seq fn_830ADD08 */
ts4_word ts4_call_seq_fn_830ADD08_8341BD60(ts4_word a0)
{
    fn_830ADD08((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8341BD88: call_seq fn_830AD500 */
ts4_word ts4_call_seq_fn_830AD500_8341BD88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830AD500((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2);
    return 0;
}

/* Loader_DLL.xex 0x8341BDB8: call_seq fn_830AD6B8 */
ts4_word ts4_call_seq_fn_830AD6B8_8341BDB8(ts4_word a0)
{
    fn_830AD6B8((ts4_word)a0, (ts4_word)0);
    return 0;
}

/* Loader_DLL.xex 0x8341BDE0: tailcall fn_830AD500 */
ts4_word ts4_tailcall_fn_830AD500_8341BDE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830AD500((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8341BDE8: tailcall fn_830AD6B8 */
ts4_word ts4_tailcall_fn_830AD6B8_8341BDE8(ts4_word a0)
{
    return fn_830AD6B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8341BE38: call_seq fn_830ADAE0 */
ts4_word ts4_call_seq_fn_830ADAE0_8341BE38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    fn_830ADAE0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return 0;
}

/* Loader_DLL.xex 0x8341BE60: call_seq fn_830ADB08 */
ts4_word ts4_call_seq_fn_830ADB08_8341BE60(ts4_word a0)
{
    fn_830ADB08((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8341BE88: call_seq fn_830AD500 */
ts4_word ts4_call_seq_fn_830AD500_8341BE88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_830AD500((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return 0;
}

/* Loader_DLL.xex 0x8341BEB0: call_seq fn_830AD6B8 */
ts4_word ts4_call_seq_fn_830AD6B8_8341BEB0(ts4_word a0)
{
    fn_830AD6B8((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8341BED8: tailcall fn_830ADB20 */
ts4_word ts4_tailcall_fn_830ADB20_8341BED8(ts4_word a0)
{
    return fn_830ADB20((ts4_word)a0);
}

/* Loader_DLL.xex 0x8341BF28: call_seq fn_830ADBF0 */
ts4_word ts4_call_seq_fn_830ADBF0_8341BF28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    fn_830ADBF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return 0;
}

/* Loader_DLL.xex 0x8341BF50: call_seq fn_830ADC18 */
ts4_word ts4_call_seq_fn_830ADC18_8341BF50(ts4_word a0)
{
    fn_830ADC18((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8341BF78: call_seq fn_830ADDF8 */
ts4_word ts4_call_seq_fn_830ADDF8_8341BF78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    fn_830ADDF8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return 0;
}

/* Loader_DLL.xex 0x8341BFA0: call_seq fn_830ADE30 */
ts4_word ts4_call_seq_fn_830ADE30_8341BFA0(ts4_word a0)
{
    fn_830ADE30((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8341C0F8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8341C0F8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C100: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8341C100(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C108: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8341C108(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C110: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8341C110(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C118: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8341C118(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C120: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8341C120(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C128: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8341C128(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C130: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8341C130(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341C138: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8341C138(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8341D338: tailcall fn_8341D120 */
ts4_word ts4_tailcall_fn_8341D120_8341D338(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341D120((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0);
}

/* Loader_DLL.xex 0x8341D340: tailcall fn_8341D120 */
ts4_word ts4_tailcall_fn_8341D120_8341D340(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341D120((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)1);
}

/* Loader_DLL.xex 0x8341D348: tailcall fn_8341D120 */
ts4_word ts4_tailcall_fn_8341D120_8341D348(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341D120((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)2);
}

/* Loader_DLL.xex 0x8341DCD8: tailcall fn_8341DB10 */
ts4_word ts4_tailcall_fn_8341DB10_8341DCD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341DB10((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0);
}

/* Loader_DLL.xex 0x8341DCE0: tailcall fn_8341DB10 */
ts4_word ts4_tailcall_fn_8341DB10_8341DCE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341DB10((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)1);
}

/* Loader_DLL.xex 0x8341DCE8: tailcall fn_8341DB10 */
ts4_word ts4_tailcall_fn_8341DB10_8341DCE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341DB10((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)2);
}

/* Loader_DLL.xex 0x8341E120: tailcall fn_8341DCF0 */
ts4_word ts4_tailcall_fn_8341DCF0_8341E120(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_8341DCF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)3);
}

/* Loader_DLL.xex 0x8341E138: tailcall fn_8341DCF0 */
ts4_word ts4_tailcall_fn_8341DCF0_8341E138(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8341DCF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a1, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)18);
}

/* Loader_DLL.xex 0x8341E158: tailcall fn_8341DCF0 */
ts4_word ts4_tailcall_fn_8341DCF0_8341E158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_8341DCF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)17);
}

/* Loader_DLL.xex 0x834218B0: tailcall fn_83421328 */
ts4_word ts4_tailcall_fn_83421328_834218B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_83421328((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x834218B8: tailcall fn_83421328 */
ts4_word ts4_tailcall_fn_83421328_834218B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_83421328((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)1);
}

/* Loader_DLL.xex 0x834218C0: tailcall fn_83421328 */
ts4_word ts4_tailcall_fn_83421328_834218C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_83421328((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)2);
}

/* Loader_DLL.xex 0x83423410: set u32@0x4, u32@0x0, u32@0x8, u32@0x38, u32@0x3c, u32@0x4c */
void ts4_set_u32_off4_83423410(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x834234E0: fn  */
void ts4_fn_834234E0(void)
{
    return;
}

/* Loader_DLL.xex 0x83423518: fn  */
void ts4_fn_83423518(void)
{
    return;
}

/* Loader_DLL.xex 0x83423520: get u32@0x18, u32@0x1c, u32@0x20, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off18_83423520(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t3;
    return 1;
}

/* Loader_DLL.xex 0x83423560: fn  */
void ts4_fn_83423560(void)
{
    return;
}

/* Loader_DLL.xex 0x834235B8: if_call_seq u32@0x18, u32@0x4, u32@0x18, u32@0x14, fn_83423158 */
ts4_word ts4_if_call_seq_u32_off18_834235B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    p6 = (ts4_word)a0;
    if ((ts4_word)(4096 - t2) != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
        t5 = fn_83423158((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 20)), (ts4_word)t3, (ts4_word)(4096 - t2), (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x83423658: tailcall fn_8346A510 */
ts4_word ts4_tailcall_fn_8346A510_83423658(ts4_word a0)
{
    return fn_8346A510((ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x83423660: fn  */
void ts4_fn_83423660(void)
{
    return;
}

/* Loader_DLL.xex 0x83423668: tailcall fn_8346A510 */
ts4_word ts4_tailcall_fn_8346A510_83423668(ts4_word a0)
{
    return fn_8346A510((ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x83423670: fn  */
void ts4_fn_83423670(void)
{
    return;
}

/* Loader_DLL.xex 0x834236C8: fn  */
void ts4_fn_834236C8(void)
{
    return;
}

/* Loader_DLL.xex 0x83423720: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83423720(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x83429440: get u32@0x0, fn_833E3AD0 */
ts4_word ts4_get_u32_off0_83429440(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E3AD0((ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)(a0 << 3));
}

/* Loader_DLL.xex 0x8342AE68: fn  */
void ts4_fn_8342AE68(void)
{
    return;
}

/* Loader_DLL.xex 0x8342AF50: set u32@0x4, u32@0x0, u32@0x8 */
void ts4_set_u32_off4_8342AF50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8342B158: if_get u32@0x0, fn_8342B0F0 */
ts4_word ts4_if_get_u32_off0_8342B158(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 == -1) {
        return a0;
    }
    return fn_8342B0F0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8342B170: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8342B170(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8342B180: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_8342B180(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8342B340: fn  */
ts4_word ts4_fn_8342B340(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8342BDE0: fn  */
ts4_word ts4_fn_8342BDE0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8342BDF0: fn  */
ts4_word ts4_fn_8342BDF0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8342BFF0: set  */
void ts4_set_8342BFF0(ts4_word a0, float f1, float f2, float f3, float f4)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4) = f2;
    *(float *)((char *)(ts4_word)(a0) + 8) = f3;
    *(float *)((char *)(ts4_word)(a0) + 12) = f4;
    return;
}

/* Loader_DLL.xex 0x8342C0B0: fn  */
void ts4_fn_8342C0B0(void)
{
    return;
}

/* Loader_DLL.xex 0x8342C0C8: fn  */
void ts4_fn_8342C0C8(void)
{
    return;
}

/* Loader_DLL.xex 0x8342DB30: get u32@0x0, fn_8340D830 */
ts4_word ts4_get_u32_off0_8342DB30(ts4_word a0)
{
    return fn_8340D830((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8342DB40: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8342DB40(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8342DB48: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8342DB48(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8342DB50: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8342DB50(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8342EF90: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_8342EF90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8342EFB0: set u32@0x0 */
void ts4_set_u32_off0_8342EFB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8342EFC0: call_seq fn_830AE138 */
ts4_word ts4_call_seq_fn_830AE138_8342EFC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_830AE138((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return 0;
}

/* Loader_DLL.xex 0x8342EFE8: call_seq fn_830AE180 */
ts4_word ts4_call_seq_fn_830AE180_8342EFE8(ts4_word a0)
{
    fn_830AE180((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8342F010: call_seq fn_830AE218 */
ts4_word ts4_call_seq_fn_830AE218_8342F010(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_830AE218((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return 0;
}

/* Loader_DLL.xex 0x8342F038: call_seq fn_830AE238 */
ts4_word ts4_call_seq_fn_830AE238_8342F038(ts4_word a0)
{
    fn_830AE238((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8342F158: if_call_seq u32@0x0, fn_830AF1B8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8342F158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8342F198: if_call_seq u32@0x0, fn_830AAAE8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8342F198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AAAE8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8342F330: tailcall fn_8342F1D8 */
ts4_word ts4_tailcall_fn_8342F1D8_8342F330(ts4_word a0)
{
    return fn_8342F1D8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8342F858: tailcall fn_8342F2D8 */
ts4_word ts4_tailcall_fn_8342F2D8_8342F858(ts4_word a0)
{
    return fn_8342F2D8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8342FBC0: fn  */
void ts4_fn_8342FBC0(void)
{
    return;
}

/* Loader_DLL.xex 0x8342FBC8: fn  */
void ts4_fn_8342FBC8(void)
{
    return;
}

/* Loader_DLL.xex 0x83430280: fn  */
void ts4_fn_83430280(void)
{
    return;
}

/* Loader_DLL.xex 0x83430368: fn  */
void ts4_fn_83430368(void)
{
    return;
}

/* Loader_DLL.xex 0x83430380: fn  */
void ts4_fn_83430380(void)
{
    return;
}

/* Loader_DLL.xex 0x83430388: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83430388(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x834306C0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_834306C0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8343CCD0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CCD0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CD20: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CD20(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CD70: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CD70(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CDC0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CDC0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CE10: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CE10(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CE60: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CE60(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CEB0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CEB0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CF00: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CF00(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CF50: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CF50(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CFA0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CFA0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343CFF0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343CFF0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D040: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D040(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D090: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D090(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D0E0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D0E0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D130: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D130(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D180: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D180(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D1D0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D1D0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D220: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D220(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D270: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D270(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D2C0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D2C0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D310: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D310(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D360: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D360(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D3B0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D3B0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D400: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D400(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D450: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D450(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D4A0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D4A0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D4F0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D4F0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D540: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D540(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D590: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D590(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D5E0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D5E0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D630: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D630(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D680: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D680(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D6D0: tailcall fn_834306C8 */
ts4_word ts4_tailcall_fn_834306C8_8343D6D0(ts4_word a0)
{
    return fn_834306C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D718: tailcall fn_8343C240 */
ts4_word ts4_tailcall_fn_8343C240_8343D718(ts4_word a0)
{
    return fn_8343C240((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D760: tailcall fn_8343C240 */
ts4_word ts4_tailcall_fn_8343C240_8343D760(ts4_word a0)
{
    return fn_8343C240((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343D7A8: tailcall fn_8343C240 */
ts4_word ts4_tailcall_fn_8343C240_8343D7A8(ts4_word a0)
{
    return fn_8343C240((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343E338: tailcall fn_8343D800 */
ts4_word ts4_tailcall_fn_8343D800_8343E338(ts4_word a0)
{
    return fn_8343D800((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343E380: tailcall fn_8343D800 */
ts4_word ts4_tailcall_fn_8343D800_8343E380(ts4_word a0)
{
    return fn_8343D800((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343E3C8: tailcall fn_8343D800 */
ts4_word ts4_tailcall_fn_8343D800_8343E3C8(ts4_word a0)
{
    return fn_8343D800((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343E410: tailcall fn_8343D800 */
ts4_word ts4_tailcall_fn_8343D800_8343E410(ts4_word a0)
{
    return fn_8343D800((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343F120: fn  */
void ts4_fn_8343F120(void)
{
    return;
}

/* Loader_DLL.xex 0x8343F128: fn  */
void ts4_fn_8343F128(void)
{
    return;
}

/* Loader_DLL.xex 0x8343F150: get u32@0x8, u32@0x4 */
ts4_word ts4_get_u32_off8_8343F150(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x8343F358: get u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off4_8343F358(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 + 1);
    return (t1 + 1);
}

/* Loader_DLL.xex 0x8343F3C0: get u32@0xc */
ts4_word ts4_get_u32_offc_8343F3C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x8343F3C8: get u32@0x8 */
ts4_word ts4_get_u32_off8_8343F3C8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8343F3D0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8343F3D0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8343F3D8: fn  */
void ts4_fn_8343F3D8(void)
{
    return;
}

/* Loader_DLL.xex 0x8343F3E0: get u32@0xc, lbl_83073BAC, u32@0x0, fn_8340D830 */
ts4_word ts4_get_u32_offc_8343F3E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BAC;
    return fn_8340D830((ts4_word)t1, (ts4_word)(612433920), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_83073BAC);
}

/* Loader_DLL.xex 0x8343F400: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8343F400(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x8343FA20: get u32@0xc, lbl_83073BAC, u32@0x0, fn_8340D830 */
ts4_word ts4_get_u32_offc_8343FA20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83073BAC;
    return fn_8340D830((ts4_word)t1, (ts4_word)(612433920), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_83073BAC);
}

/* Loader_DLL.xex 0x8343FB80: tailcall fn_8343F8F8 */
ts4_word ts4_tailcall_fn_8343F8F8_8343FB80(ts4_word a0)
{
    return fn_8343F8F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343FD58: tailcall fn_8346A510 */
ts4_word ts4_tailcall_fn_8346A510_8343FD58(ts4_word a0)
{
    return fn_8346A510((ts4_word)a0, (ts4_word)1);
}

/* Loader_DLL.xex 0x8343FD60: fn  */
void ts4_fn_8343FD60(void)
{
    return;
}

/* Loader_DLL.xex 0x8343FD68: set u32@0x548, u32@0x540, u32@0x544 */
void ts4_set_u32_off548_8343FD68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1352) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1344) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1348) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x8343FD78: get u32@0x548 */
ts4_word ts4_get_u32_off548_8343FD78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 1352));
}

/* Loader_DLL.xex 0x8343FDB8: if_get u32@0x544 */
ts4_word ts4_if_get_u32_off544_8343FDB8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1348);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8343FE68: addr lbl_83073C1C */
ts4_word ts4_addr_lbl_83073C1C_8343FE68(void)
{
    return (ts4_word)lbl_83073C1C;
}

/* Loader_DLL.xex 0x8343FF48: call_seq fn_8343FED0 */
ts4_word ts4_call_seq_fn_8343FED0_8343FF48(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8343FED0((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
    return (t1 == 0);
}

/* Loader_DLL.xex 0x8343FFE8: tailcall fn_8344C6B0 */
ts4_word ts4_tailcall_fn_8344C6B0_8343FFE8(ts4_word a0, ts4_word a1)
{
    return fn_8344C6B0((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8343FFF0: call_seq fn_8344C708, u32@0x600 */
ts4_word ts4_call_seq_fn_8344C708_8343FFF0(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8344C708((ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1536) = (ts4_word)t1;
    return t1;
}

/* Loader_DLL.xex 0x83440090: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_83440090(ts4_word a0)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)64);
}

/* Loader_DLL.xex 0x834400A0: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_834400A0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_833E3A30((ts4_word)a1, (ts4_word)0, (ts4_word)64);
}

/* Loader_DLL.xex 0x834400B0: get u32@0x554 */
ts4_word ts4_get_u32_off554_834400B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 1364));
}

/* Loader_DLL.xex 0x834400B8: addr lbl_83073C78 */
ts4_word ts4_addr_lbl_83073C78_834400B8(void)
{
    return (ts4_word)lbl_83073C78;
}

/* Loader_DLL.xex 0x834400C8: fn  */
void ts4_fn_834400C8(void)
{
    return;
}

/* Loader_DLL.xex 0x834402A0: tailcall fn_8344E300 */
ts4_word ts4_tailcall_fn_8344E300_834402A0(ts4_word a0)
{
    return fn_8344E300((ts4_word)a0);
}

/* Loader_DLL.xex 0x834402A8: tailcall fn_8344E298 */
ts4_word ts4_tailcall_fn_8344E298_834402A8(ts4_word a0)
{
    return fn_8344E298((ts4_word)a0);
}
