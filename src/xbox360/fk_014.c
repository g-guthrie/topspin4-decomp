/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char __imp_KeTimeStampBundle[];
extern char fn_88542398[];
extern char fn_8856F840[];
extern char lbl_8803A308[];
extern char lbl_8808E5D0[];
extern char lbl_8808E8B4[];
extern char lbl_8808EABC[];
extern char lbl_8808EADC[];
extern char lbl_88C30DA8[];
extern char lbl_88C311F0[];
extern char lbl_88C311F4[];
extern char lbl_88C313A0[];
extern char lbl_88C31878[];
extern char lbl_88C31898[];
extern char lbl_88C3189C[];
extern char lbl_88C318A0[];
extern char lbl_88C31928[];
extern char lbl_88CACF08[];
extern char lbl_88D2E598[];
extern char lbl_88D2E5A4[];
extern char lbl_88D2E5AC[];
extern char lbl_88D2E738[];
extern char lbl_88D2E73C[];
extern char lbl_88D2EE08[];
extern char lbl_88D2F130[];
extern char lbl_88D4DFE0[];
extern char lbl_88D4E118[];
extern char lbl_88D4E11C[];
extern char lbl_88D4E12C[];
ts4_word IoCompleteRequest();
ts4_word KeBugCheck();
ts4_word KeSetEvent();
ts4_word KeTlsFree();
ts4_word KeTlsGetValue();
ts4_word KeTlsSetValue();
ts4_word KeWaitForSingleObject();
ts4_word MmFreePhysicalMemory();
ts4_word MmQueryAddressProtect();
ts4_word MmQueryAllocationSize();
ts4_word ObDereferenceObject();
ts4_word RtlEnterCriticalSection();
ts4_word RtlInitAnsiString();
ts4_word RtlLeaveCriticalSection();
ts4_word RtlTryEnterCriticalSection();
ts4_word XamContentClose();
ts4_word XamContentCreateEnumerator();
ts4_word XamContentDelete();
ts4_word XamContentFlush();
ts4_word XamContentGetCreator();
ts4_word XamContentGetDeviceData();
ts4_word XamContentGetDeviceState();
ts4_word XamEnumerate();
ts4_word XamInputGetState();
ts4_word XamNotifyCreateListener();
ts4_word XamShowAchievementsUI();
ts4_word XamShowDeviceSelectorUI();
ts4_word XamShowFriendRequestUI();
ts4_word XamShowFriendsUI();
ts4_word XamShowGamerCardUIForXUID();
ts4_word XamShowKeyboardUI();
ts4_word XamShowMarketplaceUI();
ts4_word XamShowPlayerReviewUI();
ts4_word XamShowSigninUI();
ts4_word XamUserAreUsersFriends();
ts4_word XamUserGetName();
ts4_word XamUserGetSigninState();
ts4_word fn_882A8E28();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_88472530();
ts4_word fn_88472858();
ts4_word fn_88484538();
ts4_word fn_88485588();
ts4_word fn_88541340();
ts4_word fn_885414F8();
ts4_word fn_88541FB0();
ts4_word fn_8854AE50();
ts4_word fn_8854C410();
ts4_word fn_88559990();
ts4_word fn_88562C58();
ts4_word fn_88564208();
ts4_word fn_88564400();
ts4_word fn_88564630();
ts4_word fn_885647D0();
ts4_word fn_88564828();
ts4_word ts4_tailcall_fn_88564828_88564B00();
ts4_word fn_88565410();
ts4_word fn_885654E8();
ts4_word fn_885655E8();
ts4_word fn_885659E8();
ts4_word fn_88565BA8();
ts4_word fn_88566C60();
ts4_word fn_885674A0();
ts4_word fn_88567748();
ts4_word fn_88567A38();
ts4_word fn_88569A10();
ts4_word fn_8856A048();
ts4_word fn_8856A3F8();
ts4_word fn_8856A530();
ts4_word fn_8856ACF0();
ts4_word fn_8856B710();
ts4_word fn_8856C948();
ts4_word fn_8856CE60();
ts4_word ts4_set_u32_lbl_88D2E598_8856D2B0();
ts4_word ts4_set_u32_lbl_88D2E5AC_8856D8E0();
ts4_word fn_8856F440();
ts4_word fn_8856F4E8();
ts4_word fn_8856F558();
ts4_word fn_8856F7D8();
ts4_word ts4_addr_fn_8856F840_8856F898();
ts4_word ts4_set_u32_lbl_88D2E73C_8856F8B0();
ts4_word fn_88570320();
ts4_word ts4_tailcall_fn_88570320_885705E0();
ts4_word fn_88574230();
ts4_word fn_88575408();
ts4_word fn_88575668();
ts4_word ts4_tailcall_fn_88575668_885758E8();
ts4_word fn_885766F8();
ts4_word fn_88576798();
ts4_word fn_88576868();
ts4_word fn_88577760();
ts4_word fn_8857A2A0();
ts4_word fn_8857A338();
ts4_word fn_8857C078();
ts4_word fn_8857F1A0();
ts4_word fn_88582660();
ts4_word fn_885827E0();
ts4_word fn_88582F30();
ts4_word fn_88584548();
ts4_word fn_88586238();
ts4_word fn_885872A8();
ts4_word fn_8858C1A0();
ts4_word fn_8858C9E8();
ts4_word ts4_set_u32_off2eb8_8858CA60();
ts4_word fn_8858CCD8();
ts4_word fn_8858E5C8();
ts4_word fn_8858E758();
ts4_word ts4_set_u32_off2ec0_8858E8F0();
ts4_word fn_8858EF48();
ts4_word fn_88593C30();
ts4_word fn_88593F30();
ts4_word fn_88595FD8();
ts4_word ts4_tailcall_fn_885949C0_88596010();
ts4_word fn_88596578();
ts4_word fn_88598CF8();
ts4_word fn_88598EF0();
ts4_word fn_88598F70();
ts4_word fn_88599028();
ts4_word fn_8859A158();
ts4_word fn_8859B520();
ts4_word fn_8859CC38();
ts4_word fn_8859D608();
ts4_word fn_8859E1B0();
ts4_word fn_8859EA70();
ts4_word fn_8859EBA0();
ts4_word ts4_tailcall_fn_885AAA30_8859FFE8();
ts4_word ts4_tailcall_fn_885AAC90_8859FFF0();
ts4_word fn_885A0098();
ts4_word ts4_tailcall_fn_885AA820_885A0290();
ts4_word ts4_tailcall_fn_885AC3C8_885A0298();
ts4_word ts4_tailcall_fn_885AB0D0_885A02A0();
ts4_word ts4_tailcall_fn_885AA928_885A02A8();
ts4_word ts4_tailcall_fn_885ABB98_885A02B8();
ts4_word ts4_tailcall_fn_885AAF98_885A02C8();
ts4_word fn_885A0348();
ts4_word fn_885AA820();
ts4_word fn_885AA928();
ts4_word fn_885AA9A8();
ts4_word fn_885AAA30();
ts4_word fn_885AAAA8();
ts4_word fn_885AAB10();
ts4_word fn_885AAB80();
ts4_word fn_885AAC10();
ts4_word fn_885AAC90();
ts4_word fn_885AAF98();
ts4_word fn_885AB0D0();
ts4_word fn_885AB138();
ts4_word fn_885AB1A0();
ts4_word fn_885AB200();
ts4_word fn_885AB280();
ts4_word fn_885AB3A8();
ts4_word fn_885AB8D0();
ts4_word fn_885ABB98();
ts4_word fn_885AC3C8();
ts4_word fn_885B5CD0();
ts4_word fn_88884DE0();

/* Swing_DLL.xex 0x885403B0: get u32@0x0, u32@0x4, lbl_8808E5D0, vcall, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_885403B0(ts4_word a0, ts4_word a1)
{
    ts4_word t9;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_8808E5D0, (ts4_word)2, (ts4_word)a0);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t9;
}

/* Swing_DLL.xex 0x88542108: if_call_seq fn_88485588, fn_88541340, u32@0x0, fn_885414F8 */
ts4_word ts4_if_call_seq_fn_88485588_88542108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t2;
    ts4_word t4;

    fn_88485588((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    if ((int)a2 != 1) {
        t2 = fn_88541340((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        return t2;
    }
    t4 = fn_885414F8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return t4;
}

/* Swing_DLL.xex 0x88542CA8: addr fn_88542398, fn_88484538 */
ts4_word ts4_addr_fn_88542398_88542CA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_88484538((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)fn_88542398, (ts4_word)0);
}

/* Swing_DLL.xex 0x88544D68: if_call_seq fn_88541FB0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88541FB0_88544D68(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88541FB0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x88544DF0: fn  */
ts4_word ts4_fn_88544DF0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x885450E8: get u16@0x0 */
ts4_word ts4_get_u16_off0_885450E8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x885459C8: get u32@0xa4 */
ts4_word ts4_get_u32_offa4_885459C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 164)) + -1);
}

/* Swing_DLL.xex 0x885459D8: get u32@0xd0, u32@0xa4 */
ts4_word ts4_get_u32_offd0_885459D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    return ((((t2 - t1) + ((t2 - t1) << 1)) << 3) + 36);
}

/* Swing_DLL.xex 0x8854C3C0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_8854AE50 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8854C3C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)224, (ts4_word)33);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)224;
    t4 = fn_8854AE50((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t4;
}

/* Swing_DLL.xex 0x8854D730: if_call_seq fn_8854C410, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8854C410_8854D730(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8854C410();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)33);
    }
    return a0;
}

/* Swing_DLL.xex 0x8854D7A0: get u32@0x8, u32@0x4, u32@0x0, u32@-0x4 */
ts4_word ts4_get_u32_off8_8854D7A0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return (((*(ts4_word *)((char *)(ts4_word)(((t1 << 2) + t2)) + -4)) + t3) + -128);
}

/* Swing_DLL.xex 0x8854F5B8: get u32@0x10, u64@0x20, RtlLeaveCriticalSection */
ts4_word ts4_get_u32_off10_8854F5B8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_u64 *)((char *)(ts4_word)(t1) + 32) = (ts4_u64)-1;
    return RtlLeaveCriticalSection((ts4_word)t1);
}

/* Swing_DLL.xex 0x8854F5C8: get u32@0x10, fn_88472530 */
ts4_word ts4_get_u32_off10_8854F5C8(ts4_word a0)
{
    return fn_88472530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
}

/* Swing_DLL.xex 0x8854F680: if_call_seq u32@0x10, lbl_8808E8B4, u32@0x0, fn_88472858, u32@0x10, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off10_8854F680(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808E8B4;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88472858((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p3;
}

/* Swing_DLL.xex 0x8854F6E0: if_call_seq u32@0x10, lbl_8808E8B4, u32@0x0, fn_88472858, u32@0x10, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off10_8854F6E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808E8B4;
    if ((ts4_word)t1 != 0) {
        fn_88472858((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t5, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)33);
    }
    return a0;
}

/* Swing_DLL.xex 0x8854F778: tailcall fn_88559990 */
ts4_word ts4_tailcall_fn_88559990_8854F778(ts4_word a0)
{
    return fn_88559990((ts4_word)a0);
}

/* Swing_DLL.xex 0x88554408: get  */
void ts4_get_88554408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, float f1, float f2)
{
    (void)a2;
    (void)a3;
    *(float *)((char *)(ts4_word)(a4) + 0) = (*(float *)((char *)(ts4_word)(((a1 << 3) + a0)) + 0));
    *(float *)((char *)(ts4_word)(a5) + 0) = (*(float *)((char *)(ts4_word)(((a1 << 3) + a0)) + 4));
    *(float *)((char *)(ts4_word)(((a1 << 3) + a0)) + 0) = f1;
    *(float *)((char *)(ts4_word)(((a1 << 3) + a0)) + 4) = f2;
    return;
}

/* Swing_DLL.xex 0x885555D8: set u32@0x34, u32@0x38, u32@0x3c, u8@0xb0, u32@0xb4, u8@0xb8 */
void ts4_set_u32_off34_885555D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(2147483648);
    *(unsigned char *)((char *)(ts4_word)(a0) + 176) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 184) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88558CB0: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_88558CB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x88558CC0: set u8@0x0 */
void ts4_set_u8_off0_88558CC0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88558CD0: get u32@0x0, lbl_8808EABC, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_88558CD0(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_8808EABC, (ts4_word)2, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88558D30: fn  */
ts4_word ts4_fn_88558D30(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88558D38: fn  */
ts4_word ts4_fn_88558D38(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88558D40: addr lbl_8808EADC, u16@0x6, u32@0x0, u32@0x8 */
void ts4_addr_lbl_8808EADC_88558D40(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808EADC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(131072);
    return;
}

/* Swing_DLL.xex 0x88558E10: if_get u32@0x18, u32@lbl_88CACF08, KeTlsGetValue, u32@0x28, u32@0x20, u32@0x0 */
ts4_word ts4_if_get_u32_off18_88558E10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 24);
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 40);
    *(ts4_word *)((char *)(ts4_word)(t3) + 32) = (ts4_word)t1;
    p8 = (ts4_word)t3;
    if ((ts4_word)t1 == (ts4_word)t4) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 24))))((ts4_word)t3, (ts4_word)t1);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x88562DB0: tailcall fn_88562C58 */
ts4_word ts4_tailcall_fn_88562C58_88562DB0(ts4_word a0)
{
    return fn_88562C58((ts4_word)a0);
}

/* Swing_DLL.xex 0x88563110: tailcall fn_885827E0 */
ts4_word ts4_tailcall_fn_885827E0_88563110(ts4_word a0)
{
    return fn_885827E0((ts4_word)a0);
}

/* Swing_DLL.xex 0x885640E0: call_seq fn_8856CE60, u32@0x14 */
ts4_word ts4_call_seq_fn_8856CE60_885640E0(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8856CE60();
    *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)a0;
    return t1;
}

/* Swing_DLL.xex 0x88564150: tailcall KeBugCheck */
ts4_word ts4_tailcall_KeBugCheck_88564150(void)
{
    return KeBugCheck((ts4_word)0);
}

/* Swing_DLL.xex 0x88564158: tailcall fn_8856F7D8 */
ts4_word ts4_tailcall_fn_8856F7D8_88564158(void)
{
    return fn_8856F7D8((ts4_word)8);
}

/* Swing_DLL.xex 0x88564160: tailcall fn_8856F558 */
ts4_word ts4_tailcall_fn_8856F558_88564160(void)
{
    return fn_8856F558((ts4_word)8);
}

/* Swing_DLL.xex 0x88564168: call_seq ts4_set_u32_lbl_88D2E73C_8856F8B0, ts4_set_u32_lbl_88D2E598_8856D2B0, ts4_set_u32_lbl_88D2E5AC_8856D8E0, ts4_addr_fn_8856F840_8856F898 */
ts4_word ts4_call_seq_fn_8856F8B0_88564168(void)
{
    ts4_word t4;

    ts4_set_u32_lbl_88D2E73C_8856F8B0((ts4_word)0);
    ts4_set_u32_lbl_88D2E598_8856D2B0((ts4_word)0);
    ts4_set_u32_lbl_88D2E5AC_8856D8E0((ts4_word)0);
    t4 = ts4_addr_fn_8856F840_8856F898((ts4_word)0);
    return t4;
}

/* Swing_DLL.xex 0x885643D0: tailcall fn_88564208 */
ts4_word ts4_tailcall_fn_88564208_885643D0(void)
{
    return fn_88564208((ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x885643E0: tailcall fn_88564208 */
ts4_word ts4_tailcall_fn_88564208_885643E0(void)
{
    return fn_88564208((ts4_word)1, (ts4_word)0);
}

/* Swing_DLL.xex 0x885643F0: tailcall fn_88564208 */
ts4_word ts4_tailcall_fn_88564208_885643F0(void)
{
    return fn_88564208((ts4_word)0, (ts4_word)1);
}

/* Swing_DLL.xex 0x885646F0: tailcall fn_88564630 */
ts4_word ts4_tailcall_fn_88564630_885646F0(ts4_word a0)
{
    return fn_88564630((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88564770: tailcall ts4_tailcall_fn_88564828_88564B00 */
ts4_word ts4_tailcall_fn_88564B00_88564770(ts4_word a0)
{
    return ts4_tailcall_fn_88564828_88564B00((ts4_word)a0, (ts4_word)0, (ts4_word)10);
}

/* Swing_DLL.xex 0x88564780: tailcall ts4_tailcall_fn_88570320_885705E0 */
ts4_word ts4_tailcall_fn_885705E0_88564780(ts4_word a0)
{
    return ts4_tailcall_fn_88570320_885705E0((ts4_word)a0, (ts4_word)0, (ts4_word)10);
}

/* Swing_DLL.xex 0x88564B08: tailcall fn_88564828 */
ts4_word ts4_tailcall_fn_88564828_88564B08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88564828((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Swing_DLL.xex 0x885654D8: tailcall fn_88565410 */
ts4_word ts4_tailcall_fn_88565410_885654D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88565410((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x885655D0: tailcall fn_885654E8 */
ts4_word ts4_tailcall_fn_885654E8_885655D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_885654E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88565748: tailcall fn_885655E8 */
ts4_word ts4_tailcall_fn_885655E8_88565748(ts4_word a0, ts4_word a1)
{
    return fn_885655E8((ts4_word)a0, (ts4_word)a1, (ts4_word)64);
}

/* Swing_DLL.xex 0x88565AF8: tailcall fn_885659E8 */
ts4_word ts4_tailcall_fn_885659E8_88565AF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_885659E8((ts4_word)a0, (ts4_word)-1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88565CD8: tailcall fn_88565BA8 */
ts4_word ts4_tailcall_fn_88565BA8_88565CD8(ts4_word a0)
{
    return fn_88565BA8((ts4_word)a0);
}

/* Swing_DLL.xex 0x88566F38: tailcall fn_88566C60 */
ts4_word ts4_tailcall_fn_88566C60_88566F38(void)
{
    return fn_88566C60((ts4_word)1);
}

/* Swing_DLL.xex 0x88567728: tailcall fn_885674A0 */
ts4_word ts4_tailcall_fn_885674A0_88567728(ts4_word a0)
{
    return fn_885674A0((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x88567798: tailcall fn_88567748 */
ts4_word ts4_tailcall_fn_88567748_88567798(ts4_word a0)
{
    return fn_88567748((ts4_word)a0);
}

/* Swing_DLL.xex 0x88567B98: tailcall fn_88567A38 */
ts4_word ts4_tailcall_fn_88567A38_88567B98(ts4_word a0, ts4_word a1)
{
    return fn_88567A38((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x88567BC8: addr lbl_88C30DA8 */
ts4_word ts4_addr_lbl_88C30DA8_88567BC8(void)
{
    return (ts4_word)lbl_88C30DA8;
}

/* Swing_DLL.xex 0x88567FB8: get u32@lbl_88C311F0 */
ts4_word ts4_get_u32_lbl_88C311F0_88567FB8(void)
{
    return (*(ts4_word *)lbl_88C311F0);
}

/* Swing_DLL.xex 0x88567FC8: get u32@lbl_88C311F4 */
ts4_word ts4_get_u32_lbl_88C311F4_88567FC8(void)
{
    return (*(ts4_word *)lbl_88C311F4);
}

/* Swing_DLL.xex 0x88569350: tailcall ts4_tailcall_fn_88575668_885758E8 */
ts4_word ts4_tailcall_fn_885758E8_88569350(ts4_word a0)
{
    return ts4_tailcall_fn_88575668_885758E8((ts4_word)a0, (ts4_word)0, (ts4_word)10);
}

/* Swing_DLL.xex 0x88569BD0: tailcall fn_88569A10 */
ts4_word ts4_tailcall_fn_88569A10_88569BD0(ts4_word a0)
{
    return fn_88569A10((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x8856A0C0: tailcall fn_8856A048 */
ts4_word ts4_tailcall_fn_8856A048_8856A0C0(ts4_word a0, ts4_word a1)
{
    return fn_8856A048((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x8856A4A8: addr lbl_88C31878, fn_8856A3F8 */
ts4_word ts4_addr_lbl_88C31878_8856A4A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8856A3F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)lbl_88C31878);
}

/* Swing_DLL.xex 0x8856A658: tailcall fn_8856A530 */
ts4_word ts4_tailcall_fn_8856A530_8856A658(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8856A530((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)a3);
}

/* Swing_DLL.xex 0x8856AD88: tailcall fn_8856ACF0 */
ts4_word ts4_tailcall_fn_8856ACF0_8856AD88(ts4_word a0)
{
    return fn_8856ACF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x8856B790: call_seq fn_8856F440, fn_8856B710 */
ts4_word ts4_call_seq_fn_8856F440_8856B790(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8856F440((ts4_word)0, (ts4_word)((4294443008) | 1792));
    t2 = fn_8856B710((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x8856C878: tailcall fn_8856C948 */
ts4_word ts4_tailcall_fn_8856C948_8856C878(ts4_word a0)
{
    return fn_8856C948((ts4_word)a0, (ts4_word)0, (ts4_word)1);
}

/* Swing_DLL.xex 0x8856CD00: tailcall KeTlsGetValue */
ts4_word ts4_tailcall_KeTlsGetValue_8856CD00(ts4_word a0)
{
    return KeTlsGetValue((ts4_word)a0);
}

/* Swing_DLL.xex 0x8856CD08: get u32@lbl_88C313A0 */
ts4_word ts4_get_u32_lbl_88C313A0_8856CD08(void)
{
    return (*(ts4_word *)lbl_88C313A0);
}

/* Swing_DLL.xex 0x8856CD18: tailcall KeTlsSetValue */
ts4_word ts4_tailcall_KeTlsSetValue_8856CD18(ts4_word a0)
{
    return KeTlsSetValue((ts4_word)a0);
}

/* Swing_DLL.xex 0x8856CD20: if_call_seq u32@lbl_88C313A0, KeTlsFree, u32@lbl_88C313A0, fn_8856F4E8 */
ts4_word ts4_if_call_seq_u32_lbl_88C313A0_8856CD20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88C313A0;
    p3 = (ts4_word)t1;
    if ((int)t1 != -1) {
        t2 = KeTlsFree((ts4_word)t1);
        *(ts4_word *)lbl_88C313A0 = (ts4_word)-1;
        p3 = (ts4_word)t2;
    }
    t4 = fn_8856F4E8((ts4_word)p3);
    return t4;
}

/* Swing_DLL.xex 0x8856D3C0: get u32@lbl_88D2E5A4 */
ts4_word ts4_get_u32_lbl_88D2E5A4_8856D3C0(void)
{
    return (*(ts4_word *)lbl_88D2E5A4);
}

/* Swing_DLL.xex 0x88574180: addr lbl_88C3189C */
ts4_word ts4_addr_lbl_88C3189C_88574180(void)
{
    return (ts4_word)lbl_88C3189C;
}

/* Swing_DLL.xex 0x88574190: addr lbl_88C318A0 */
ts4_word ts4_addr_lbl_88C318A0_88574190(void)
{
    return (ts4_word)lbl_88C318A0;
}

/* Swing_DLL.xex 0x885741A0: addr lbl_88C31898 */
ts4_word ts4_addr_lbl_88C31898_885741A0(void)
{
    return (ts4_word)lbl_88C31898;
}

/* Swing_DLL.xex 0x885741B0: addr lbl_88C31928 */
ts4_word ts4_addr_lbl_88C31928_885741B0(void)
{
    return (ts4_word)lbl_88C31928;
}

/* Swing_DLL.xex 0x88574380: tailcall fn_88574230 */
ts4_word ts4_tailcall_fn_88574230_88574380(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_88574230((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Swing_DLL.xex 0x88574520: tailcall fn_885647D0 */
ts4_word ts4_tailcall_fn_885647D0_88574520(ts4_word a0)
{
    return fn_885647D0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88575590: tailcall fn_88575408 */
ts4_word ts4_tailcall_fn_88575408_88575590(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_88575408((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x885768C8: tailcall fn_88576868 */
ts4_word ts4_tailcall_fn_88576868_885768C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88576868((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x885768D0: tailcall fn_885766F8 */
ts4_word ts4_tailcall_fn_885766F8_885768D0(ts4_word a0)
{
    return fn_885766F8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x885768D8: tailcall fn_88576798 */
ts4_word ts4_tailcall_fn_88576798_885768D8(ts4_word a0)
{
    return fn_88576798((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x885776C8: set u32@lbl_88D4DFE0 */
void ts4_set_u32_lbl_88D4DFE0_885776C8(void)
{
    *(ts4_word *)lbl_88D4DFE0 = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88577858: tailcall fn_88577760 */
ts4_word ts4_tailcall_fn_88577760_88577858(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_88577760((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Swing_DLL.xex 0x885793B8: tailcall fn_88564400 */
ts4_word ts4_tailcall_fn_88564400_885793B8(void)
{
    return fn_88564400((ts4_word)2);
}

/* Swing_DLL.xex 0x8857A128: tailcall fn_88582F30 */
ts4_word ts4_tailcall_fn_88582F30_8857A128(ts4_word a0, ts4_word a1)
{
    return fn_88582F30((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857A1C8: tailcall XamEnumerate */
ts4_word ts4_tailcall_XamEnumerate_8857A1C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return XamEnumerate((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x8857A330: tailcall fn_8857A2A0 */
ts4_word ts4_tailcall_fn_8857A2A0_8857A330(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8857A2A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857A3F0: tailcall fn_8857A338 */
ts4_word ts4_tailcall_fn_8857A338_8857A3F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8857A338((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857A3F8: tailcall XamUserGetName */
ts4_word ts4_tailcall_XamUserGetName_8857A3F8(ts4_word a0)
{
    return XamUserGetName((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A400: tailcall XamUserGetSigninState */
ts4_word ts4_tailcall_XamUserGetSigninState_8857A400(ts4_word a0)
{
    return XamUserGetSigninState((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A408: tailcall XamUserAreUsersFriends */
ts4_word ts4_tailcall_XamUserAreUsersFriends_8857A408(ts4_word a0)
{
    return XamUserAreUsersFriends((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A688: tailcall XamShowSigninUI */
ts4_word ts4_tailcall_XamShowSigninUI_8857A688(ts4_word a0)
{
    return XamShowSigninUI((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A690: tailcall XamShowFriendsUI */
ts4_word ts4_tailcall_XamShowFriendsUI_8857A690(ts4_word a0)
{
    return XamShowFriendsUI((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A698: tailcall XamShowKeyboardUI */
ts4_word ts4_tailcall_XamShowKeyboardUI_8857A698(ts4_word a0)
{
    return XamShowKeyboardUI((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A6A0: tailcall XamShowGamerCardUIForXUID */
ts4_word ts4_tailcall_XamShowGamerCardUIForXUID_8857A6A0(ts4_word a0, ts4_word a1)
{
    return XamShowGamerCardUIForXUID((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857A6A8: tailcall XamShowAchievementsUI */
ts4_word ts4_tailcall_XamShowAchievementsUI_8857A6A8(ts4_word a0)
{
    return XamShowAchievementsUI((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857A6B0: tailcall XamShowPlayerReviewUI */
ts4_word ts4_tailcall_XamShowPlayerReviewUI_8857A6B0(ts4_word a0)
{
    return XamShowPlayerReviewUI((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A6B8: tailcall XamShowMarketplaceUI */
ts4_word ts4_tailcall_XamShowMarketplaceUI_8857A6B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return XamShowMarketplaceUI((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)-1, (ts4_word)a3, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857A6C8: tailcall XamShowDeviceSelectorUI */
ts4_word ts4_tailcall_XamShowDeviceSelectorUI_8857A6C8(ts4_word a0)
{
    return XamShowDeviceSelectorUI((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A6F8: tailcall XamShowFriendRequestUI */
ts4_word ts4_tailcall_XamShowFriendRequestUI_8857A6F8(ts4_word a0)
{
    return XamShowFriendRequestUI((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857A988: tailcall XamNotifyCreateListener */
ts4_word ts4_tailcall_XamNotifyCreateListener_8857A988(ts4_word a0)
{
    return XamNotifyCreateListener((ts4_word)a0, (ts4_word)7);
}

/* Swing_DLL.xex 0x8857AFE8: tailcall fn_88584548 */
ts4_word ts4_tailcall_fn_88584548_8857AFE8(ts4_word a0)
{
    return fn_88584548((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x8857B140: tailcall MmQueryAllocationSize */
ts4_word ts4_tailcall_MmQueryAllocationSize_8857B140(ts4_word a0)
{
    return MmQueryAllocationSize((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B158: tailcall MmFreePhysicalMemory */
ts4_word ts4_tailcall_MmFreePhysicalMemory_8857B158(ts4_word a0)
{
    return MmFreePhysicalMemory((ts4_word)0, (ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B168: tailcall MmQueryAddressProtect */
ts4_word ts4_tailcall_MmQueryAddressProtect_8857B168(ts4_word a0)
{
    return MmQueryAddressProtect((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B170: tailcall XamInputGetState */
ts4_word ts4_tailcall_XamInputGetState_8857B170(ts4_word a0, ts4_word a1)
{
    return XamInputGetState((ts4_word)a0, (ts4_word)1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8857B2D0: tailcall XamContentDelete */
ts4_word ts4_tailcall_XamContentDelete_8857B2D0(ts4_word a0)
{
    return XamContentDelete((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B2D8: tailcall XamContentClose */
ts4_word ts4_tailcall_XamContentClose_8857B2D8(ts4_word a0)
{
    return XamContentClose((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B2E0: tailcall XamContentFlush */
ts4_word ts4_tailcall_XamContentFlush_8857B2E0(ts4_word a0)
{
    return XamContentFlush((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B2E8: tailcall XamContentGetCreator */
ts4_word ts4_tailcall_XamContentGetCreator_8857B2E8(ts4_word a0)
{
    return XamContentGetCreator((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B2F0: tailcall XamContentCreateEnumerator */
ts4_word ts4_tailcall_XamContentCreateEnumerator_8857B2F0(ts4_word a0)
{
    return XamContentCreateEnumerator((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B2F8: tailcall XamContentGetDeviceState */
ts4_word ts4_tailcall_XamContentGetDeviceState_8857B2F8(ts4_word a0)
{
    return XamContentGetDeviceState((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B300: tailcall XamContentGetDeviceData */
ts4_word ts4_tailcall_XamContentGetDeviceData_8857B300(ts4_word a0)
{
    return XamContentGetDeviceData((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857B580: get u32@lbl_88D4E12C, u32@lbl_88D4E12C */
ts4_word ts4_get_u32_lbl_88D4E12C_8857B580(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D4E12C;
    *(ts4_word *)lbl_88D4E12C = (ts4_word)a0;
    return t1;
}

/* Swing_DLL.xex 0x8857B830: get u32@__imp_KeTimeStampBundle, u32@0x10 */
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeTimeStampBundle)) + 16));
}

/* Swing_DLL.xex 0x8857B840: tailcall fn_88582660 */
ts4_word ts4_tailcall_fn_88582660_8857B840(ts4_word a0)
{
    return fn_88582660((ts4_word)a0);
}

/* Swing_DLL.xex 0x8857C128: tailcall fn_8857C078 */
ts4_word ts4_tailcall_fn_8857C078_8857C128(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8857C078((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Swing_DLL.xex 0x88581A90: get u32@lbl_88D4E11C */
ts4_word ts4_get_u32_lbl_88D4E11C_88581A90(void)
{
    return (*(ts4_word *)lbl_88D4E11C);
}

/* Swing_DLL.xex 0x88582A90: if_call_seq u32@lbl_88D4E11C, fn_8857F1A0, u32@lbl_88D4E11C, u32@lbl_88D4E118, fn_8857F1A0, u32@lbl_88D4E118 */
ts4_word ts4_if_call_seq_u32_lbl_88D4E11C_88582A90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D4E11C;
    if ((ts4_word)t1 != 0) {
        fn_8857F1A0((ts4_word)t1);
        *(ts4_word *)lbl_88D4E11C = (ts4_word)0;
    }
    t4 = *(ts4_word *)lbl_88D4E118;
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_8857F1A0((ts4_word)t4);
        *(ts4_word *)lbl_88D4E118 = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x885845D8: call_seq RtlInitAnsiString, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_call_seq_RtlInitAnsiString_885845D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    RtlInitAnsiString((ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)128;
    return a0;
}

/* Swing_DLL.xex 0x88585178: call_seq lbl_88D2EE08, u32@0x20, KeSetEvent, u32@lbl_88D2EE08, KeWaitForSingleObject, u32@lbl_88D2EE08 */
ts4_word ts4_call_seq_lbl_88D2EE08_88585178(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE08) + 32) = (ts4_word)1;
    KeSetEvent((ts4_word)((ts4_word)lbl_88D2EE08 + 16), (ts4_word)1, (ts4_word)0);
    KeWaitForSingleObject((ts4_word)(*(ts4_word *)lbl_88D2EE08), (ts4_word)3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
    ObDereferenceObject((ts4_word)(*(ts4_word *)lbl_88D2EE08));
    return 0;
}

/* Swing_DLL.xex 0x88587490: addr lbl_88D2EE08, fn_88586238 */
ts4_word ts4_addr_lbl_88D2EE08_88587490(void)
{
    return fn_88586238((ts4_word)(ts4_word)lbl_88D2EE08, (ts4_word)1);
}

/* Swing_DLL.xex 0x88587690: if_call_seq RtlEnterCriticalSection, u32@0x88, fn_885872A8, RtlLeaveCriticalSection, u32@0x10, IoCompleteRequest */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_88587690(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    RtlEnterCriticalSection();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((int)t2 != 0) {
        p5 = (ts4_word)t2;
    } else {
        t3 = fn_885872A8((ts4_word)a0, (ts4_word)0, (ts4_word)-1);
        p5 = (ts4_word)t3;
    }
    RtlLeaveCriticalSection((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)p5;
    t7 = IoCompleteRequest((ts4_word)a1, (ts4_word)1);
    return t7;
}

/* Swing_DLL.xex 0x8858B248: get u16@0x0, u32@0x4, fn_8858C1A0 */
ts4_word ts4_get_u16_off0_8858B248(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return fn_8858C1A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x8858C698: call_seq fn_8858C9E8, ts4_set_u32_off2eb8_8858CA60, ts4_set_u32_off2ec0_8858E8F0, u32@0x2ec4 */
ts4_word ts4_call_seq_fn_8858C9E8_8858C698(ts4_word a0)
{
    ts4_word t3;

    fn_8858C9E8((ts4_word)a0);
    ts4_set_u32_off2eb8_8858CA60((ts4_word)a0);
    t3 = ts4_set_u32_off2ec0_8858E8F0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 11972) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x8858CE30: call_seq fn_8858E5C8, fn_8858EF48, fn_8858E758 */
ts4_word ts4_call_seq_fn_8858E5C8_8858CE30(ts4_word a0)
{
    ts4_word t2;

    fn_8858E5C8((ts4_word)a0, (ts4_word)0);
    t2 = fn_8858EF48((ts4_word)a0);
    fn_8858E758((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8858CEC8: if_call_seq u8@0x972, u8@0x973, fn_8858CCD8, u32@0x1c, u32@0x2520, u32@0x864 */
ts4_word ts4_if_call_seq_u8_off972_8858CEC8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    *(unsigned char *)((char *)(ts4_word)(a0) + 2418) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 2419) = (unsigned char)1;
    t1 = fn_8858CCD8((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 < 4096) {
        p3 = (ts4_word)4096;
    } else {
        p3 = (ts4_word)(t2 + 4096);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 9504) = (ts4_word)p3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2148) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x8858DB48: set u32@0x98c */
void ts4_set_u32_off98c_8858DB48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 2444) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88593DD8: tailcall RtlEnterCriticalSection */
ts4_word ts4_tailcall_RtlEnterCriticalSection_88593DD8(ts4_word a0)
{
    return RtlEnterCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88593DE0: tailcall RtlTryEnterCriticalSection */
ts4_word ts4_tailcall_RtlTryEnterCriticalSection_88593DE0(ts4_word a0)
{
    return RtlTryEnterCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88593DE8: tailcall RtlLeaveCriticalSection */
ts4_word ts4_tailcall_RtlLeaveCriticalSection_88593DE8(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88594050: get u32@0x3ea0, fn_882A8E28 */
ts4_word ts4_get_u32_off3ea0_88594050(ts4_word a0)
{
    return fn_882A8E28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16032)));
}

/* Swing_DLL.xex 0x88595FD0: tailcall fn_88596578 */
ts4_word ts4_tailcall_fn_88596578_88595FD0(ts4_word a0)
{
    return fn_88596578((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88596000: tailcall fn_88595FD8 */
ts4_word ts4_tailcall_fn_88595FD8_88596000(ts4_word a0)
{
    return fn_88595FD8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88596008: tailcall fn_88593F30 */
ts4_word ts4_tailcall_fn_88593F30_88596008(ts4_word a0)
{
    return fn_88593F30((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88596018: tailcall ts4_tailcall_fn_885949C0_88596010 */
ts4_word ts4_tailcall_fn_88596010_88596018(ts4_word a0)
{
    return ts4_tailcall_fn_885949C0_88596010((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88596808: if_call_seq u32@0xc, fn_88884DE0, u32@0xc */
ts4_word ts4_if_call_seq_u32_offc_88596808(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88884DE0((ts4_word)t1, (ts4_word)(546766848));
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x885968A8: if_call_seq u32@0xc, u32@0x18, fn_88884DE0, u32@0xc, u32@0x8, u32@0x10 */
ts4_word ts4_if_call_seq_u32_offc_885968A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88884DE0((ts4_word)t1, (ts4_word)(546766848));
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    return p3;
}

/* Swing_DLL.xex 0x88597EC0: set u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x18 */
void ts4_set_u32_off4_88597EC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x88599FA0: tailcall fn_885AB8D0 */
ts4_word ts4_tailcall_fn_885AB8D0_88599FA0(ts4_word a0)
{
    return fn_885AB8D0((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FA8: tailcall fn_885AB138 */
ts4_word ts4_tailcall_fn_885AB138_88599FA8(ts4_word a0)
{
    return fn_885AB138((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FB0: tailcall fn_885AB1A0 */
ts4_word ts4_tailcall_fn_885AB1A0_88599FB0(ts4_word a0)
{
    return fn_885AB1A0((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FB8: tailcall fn_885AB280 */
ts4_word ts4_tailcall_fn_885AB280_88599FB8(ts4_word a0)
{
    return fn_885AB280((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FC0: tailcall fn_885AA9A8 */
ts4_word ts4_tailcall_fn_885AA9A8_88599FC0(ts4_word a0)
{
    return fn_885AA9A8((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FC8: tailcall fn_885AAB10 */
ts4_word ts4_tailcall_fn_885AAB10_88599FC8(ts4_word a0)
{
    return fn_885AAB10((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FD0: tailcall fn_885AAC10 */
ts4_word ts4_tailcall_fn_885AAC10_88599FD0(ts4_word a0)
{
    return fn_885AAC10((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FD8: tailcall fn_885AB3A8 */
ts4_word ts4_tailcall_fn_885AB3A8_88599FD8(ts4_word a0)
{
    return fn_885AB3A8((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88599FE0: fn  */
ts4_word ts4_fn_88599FE0(void)
{
    return ((2147483648) | 16389);
}

/* Swing_DLL.xex 0x88599FF0: set u32@0x4 */
void ts4_set_u32_off4_88599FF0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88599FF8: get u32@0x8c */
ts4_word ts4_get_u32_off8c_88599FF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 140));
}

/* Swing_DLL.xex 0x8859A000: get u32@0xcc */
ts4_word ts4_get_u32_offcc_8859A000(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 204));
}

/* Swing_DLL.xex 0x8859A088: tailcall ts4_tailcall_fn_885AAC90_8859FFF0 */
ts4_word ts4_tailcall_fn_8859FFF0_8859A088(ts4_word a0)
{
    return ts4_tailcall_fn_885AAC90_8859FFF0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0A0: tailcall fn_8859A158 */
ts4_word ts4_tailcall_fn_8859A158_8859A0A0(ts4_word a0)
{
    return fn_8859A158((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0A8: tailcall ts4_tailcall_fn_885AAA30_8859FFE8 */
ts4_word ts4_tailcall_fn_8859FFE8_8859A0A8(ts4_word a0)
{
    return ts4_tailcall_fn_885AAA30_8859FFE8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0B8: tailcall ts4_tailcall_fn_885AAF98_885A02C8 */
ts4_word ts4_tailcall_fn_885A02C8_8859A0B8(ts4_word a0)
{
    return ts4_tailcall_fn_885AAF98_885A02C8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0D8: tailcall fn_88598EF0 */
ts4_word ts4_tailcall_fn_88598EF0_8859A0D8(ts4_word a0)
{
    return fn_88598EF0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0E0: tailcall fn_88599028 */
ts4_word ts4_tailcall_fn_88599028_8859A0E0(ts4_word a0)
{
    return fn_88599028((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0E8: tailcall fn_88598F70 */
ts4_word ts4_tailcall_fn_88598F70_8859A0E8(ts4_word a0)
{
    return fn_88598F70((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859BB30: set u32@0x1d0 */
void ts4_set_u32_off1d0_8859BB30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8859BCD0: addr lbl_88D2F130, fn_88593C30 */
ts4_word ts4_addr_lbl_88D2F130_8859BCD0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88593C30((ts4_word)(ts4_word)lbl_88D2F130, (ts4_word)a1, (ts4_word)(546766848), (ts4_word)8);
}

/* Swing_DLL.xex 0x8859CBB0: fn  */
ts4_word ts4_fn_8859CBB0(void)
{
    return 2;
}

/* Swing_DLL.xex 0x8859CBB8: tailcall fn_8859CC38 */
ts4_word ts4_tailcall_fn_8859CC38_8859CBB8(ts4_word a0)
{
    return fn_8859CC38((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859E4D0: call_seq fn_8859D608, fn_8859D608, u32@0xf8, u32@0xfc, u32@0x100, u32@0x104 */
ts4_word ts4_call_seq_fn_8859D608_8859E4D0(ts4_word a0, ts4_word a1)
{
    fn_8859D608((ts4_word)a0);
    fn_8859D608((ts4_word)(a0 + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8859EA00: tailcall fn_8859EA70 */
ts4_word ts4_tailcall_fn_8859EA70_8859EA00(ts4_word a0)
{
    return fn_8859EA70((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859ECB0: if_call_seq fn_88598CF8, fn_8859E1B0, fn_8859EBA0, u32@0x14c, fn_8859B520 */
ts4_word ts4_if_call_seq_fn_88598CF8_8859ECB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t6;

    fn_88598CF8((ts4_word)a0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)a2 != 0) {
        fn_8859E1B0((ts4_word)(a0 + -140), (ts4_word)a1, (ts4_word)a2);
    }
    fn_8859EBA0((ts4_word)(a0 + -140));
    t6 = fn_8859B520((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 332)));
    return t6;
}

/* Swing_DLL.xex 0x8859FFE0: tailcall fn_885AB200 */
ts4_word ts4_tailcall_fn_885AB200_8859FFE0(ts4_word a0)
{
    return fn_885AB200((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x8859FFF8: fn  */
ts4_word ts4_fn_8859FFF8(void)
{
    return 4;
}

/* Swing_DLL.xex 0x885A0000: get u32@0x30, u32@0xb8 */
ts4_word ts4_get_u32_off30_885A0000(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 184));
}

/* Swing_DLL.xex 0x885A0018: tailcall ts4_tailcall_fn_885AC3C8_885A0298 */
ts4_word ts4_tailcall_fn_885A0298_885A0018(ts4_word a0)
{
    return ts4_tailcall_fn_885AC3C8_885A0298((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A0020: tailcall ts4_tailcall_fn_885AB0D0_885A02A0 */
ts4_word ts4_tailcall_fn_885A02A0_885A0020(ts4_word a0)
{
    return ts4_tailcall_fn_885AB0D0_885A02A0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A0028: tailcall fn_885A0098 */
ts4_word ts4_tailcall_fn_885A0098_885A0028(ts4_word a0)
{
    return fn_885A0098((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A0030: tailcall ts4_tailcall_fn_885ABB98_885A02B8 */
ts4_word ts4_tailcall_fn_885A02B8_885A0030(ts4_word a0)
{
    return ts4_tailcall_fn_885ABB98_885A02B8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A0038: tailcall ts4_tailcall_fn_885AA928_885A02A8 */
ts4_word ts4_tailcall_fn_885A02A8_885A0038(ts4_word a0)
{
    return ts4_tailcall_fn_885AA928_885A02A8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A0040: tailcall ts4_tailcall_fn_885AA820_885A0290 */
ts4_word ts4_tailcall_fn_885A0290_885A0040(ts4_word a0)
{
    return ts4_tailcall_fn_885AA820_885A0290((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A02B0: tailcall fn_885AAAA8 */
ts4_word ts4_tailcall_fn_885AAAA8_885A02B0(ts4_word a0)
{
    return fn_885AAAA8((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02C0: tailcall fn_885AAB80 */
ts4_word ts4_tailcall_fn_885AAB80_885A02C0(ts4_word a0)
{
    return fn_885AAB80((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02D0: fn  */
ts4_word ts4_fn_885A02D0(void)
{
    return 3;
}

/* Swing_DLL.xex 0x885A02D8: tailcall fn_885A0348 */
ts4_word ts4_tailcall_fn_885A0348_885A02D8(ts4_word a0)
{
    return fn_885A0348((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A5038: call_seq u32@0x48, fn_885B5CD0 */
ts4_word ts4_call_seq_u32_off48_885A5038(ts4_word a0, ts4_word a1)
{
    fn_885B5CD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)), (ts4_word)a1);
    return 0;
}
