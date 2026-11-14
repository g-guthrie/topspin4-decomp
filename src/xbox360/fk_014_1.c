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
ts4_word ts4_strtoxl_88564828();
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
ts4_word fn_8856F440();
ts4_word fn_8856F4E8();
ts4_word ts4_addr_lbl_88C31510_8856F558();
ts4_word fn_8856F7D8();
ts4_word ts4_strtoxq_88570320();
ts4_word fn_88574230();
ts4_word fn_88575408();
ts4_word ts4_wcstoxl_88575668();
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
ts4_word ts4_loop_call_seq_fn_885846A0_88582F30();
ts4_word fn_88584548();
ts4_word fn_88586238();
ts4_word fn_885872A8();
ts4_word fn_8858C1A0();
ts4_word fn_8858C9E8();
ts4_word fn_8858CCD8();
ts4_word fn_8858E5C8();
ts4_word fn_8858E758();
ts4_word fn_8858EF48();
ts4_word fn_88593C30();
ts4_word fn_88593F30();
ts4_word ts4_atomic_interlocked_inc_88595FD8();
ts4_word ts4_tailcall_fn_885949C0_88596010();
ts4_word fn_88596578();
ts4_word ts4_vcall_member_slot0_88598CF8();
ts4_word fn_88598EF0();
ts4_word fn_88598F70();
ts4_word fn_88599028();
ts4_word ts4_tailcall_fn_885AB8D0_88599FA0();
ts4_word ts4_tailcall_fn_885AB138_88599FA8();
ts4_word ts4_tailcall_fn_885AB1A0_88599FB0();
ts4_word ts4_tailcall_fn_885AB280_88599FB8();
ts4_word ts4_tailcall_fn_885AA9A8_88599FC0();
ts4_word ts4_tailcall_fn_885AAB10_88599FC8();
ts4_word ts4_tailcall_fn_885AAC10_88599FD0();
ts4_word ts4_tailcall_fn_885AB3A8_88599FD8();
ts4_word fn_8859A158();
ts4_word fn_8859B520();
ts4_word fn_8859CC38();
ts4_word ts4_pool8_init_8859D608();
ts4_word fn_8859E1B0();
ts4_word fn_8859EA70();
ts4_word fn_8859EBA0();
ts4_word ts4_tailcall_fn_885AB200_8859FFE0();
ts4_word fn_885A0098();
ts4_word ts4_tailcall_fn_885AAAA8_885A02B0();
ts4_word ts4_tailcall_fn_885AAB80_885A02C0();
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

/* Swing_DLL.xex 0x88564B00: tailcall ts4_strtoxl_88564828 */
ts4_word ts4_tailcall_fn_88564828_88564B00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ts4_strtoxl_88564828((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x8856D2B0: set u32@lbl_88D2E598 */
void ts4_set_u32_lbl_88D2E598_8856D2B0(ts4_word a0)
{
    *(ts4_word *)lbl_88D2E598 = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x8856D8E0: set u32@lbl_88D2E5AC */
void ts4_set_u32_lbl_88D2E5AC_8856D8E0(ts4_word a0)
{
    *(ts4_word *)lbl_88D2E5AC = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x8856F898: addr fn_8856F840, u32@lbl_88D2E738 */
void ts4_addr_fn_8856F840_8856F898(void)
{
    *(ts4_word *)lbl_88D2E738 = (ts4_word)(ts4_word)fn_8856F840;
    return;
}

/* Swing_DLL.xex 0x8856F8B0: set u32@lbl_88D2E73C */
void ts4_set_u32_lbl_88D2E73C_8856F8B0(ts4_word a0)
{
    *(ts4_word *)lbl_88D2E73C = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x885705E0: tailcall ts4_strtoxq_88570320 */
ts4_word ts4_tailcall_fn_88570320_885705E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ts4_strtoxq_88570320((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x885758E8: tailcall ts4_wcstoxl_88575668 */
ts4_word ts4_tailcall_fn_88575668_885758E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ts4_wcstoxl_88575668((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x8858CA60: set u32@0x2eb8, u32@0xc, u32@0x10, u32@0x14, u32@0x2b10, u32@0x2ed4 */
void ts4_set_u32_off2eb8_8858CA60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 11960) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11024) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11988) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11980) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11984) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 11958) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 11964) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 11959) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8858E8F0: set u32@0x2ec0 */
void ts4_set_u32_off2ec0_8858E8F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 11968) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8859A080: tailcall ts4_tailcall_fn_885AAC10_88599FD0 */
ts4_word ts4_tailcall_fn_88599FD0_8859A080(ts4_word a0)
{
    return ts4_tailcall_fn_885AAC10_88599FD0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A090: tailcall ts4_tailcall_fn_885AB1A0_88599FB0 */
ts4_word ts4_tailcall_fn_88599FB0_8859A090(ts4_word a0)
{
    return ts4_tailcall_fn_885AB1A0_88599FB0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A098: tailcall ts4_tailcall_fn_885AA9A8_88599FC0 */
ts4_word ts4_tailcall_fn_88599FC0_8859A098(ts4_word a0)
{
    return ts4_tailcall_fn_885AA9A8_88599FC0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0B0: tailcall ts4_tailcall_fn_885AAB10_88599FC8 */
ts4_word ts4_tailcall_fn_88599FC8_8859A0B0(ts4_word a0)
{
    return ts4_tailcall_fn_885AAB10_88599FC8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0C0: tailcall ts4_tailcall_fn_885AB8D0_88599FA0 */
ts4_word ts4_tailcall_fn_88599FA0_8859A0C0(ts4_word a0)
{
    return ts4_tailcall_fn_885AB8D0_88599FA0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0C8: tailcall ts4_tailcall_fn_885AB280_88599FB8 */
ts4_word ts4_tailcall_fn_88599FB8_8859A0C8(ts4_word a0)
{
    return ts4_tailcall_fn_885AB280_88599FB8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859A0D0: tailcall ts4_tailcall_fn_885AB3A8_88599FD8 */
ts4_word ts4_tailcall_fn_88599FD8_8859A0D0(ts4_word a0)
{
    return ts4_tailcall_fn_885AB3A8_88599FD8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x8859FFE8: tailcall fn_885AAA30 */
ts4_word ts4_tailcall_fn_885AAA30_8859FFE8(ts4_word a0)
{
    return fn_885AAA30((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x8859FFF0: tailcall fn_885AAC90 */
ts4_word ts4_tailcall_fn_885AAC90_8859FFF0(ts4_word a0)
{
    return fn_885AAC90((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A0010: tailcall ts4_tailcall_fn_885AB138_88599FA8 */
ts4_word ts4_tailcall_fn_88599FA8_885A0010(ts4_word a0)
{
    return ts4_tailcall_fn_885AB138_88599FA8((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A0290: tailcall fn_885AA820 */
ts4_word ts4_tailcall_fn_885AA820_885A0290(ts4_word a0)
{
    return fn_885AA820((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A0298: tailcall fn_885AC3C8 */
ts4_word ts4_tailcall_fn_885AC3C8_885A0298(ts4_word a0)
{
    return fn_885AC3C8((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02A0: tailcall fn_885AB0D0 */
ts4_word ts4_tailcall_fn_885AB0D0_885A02A0(ts4_word a0)
{
    return fn_885AB0D0((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02A8: tailcall fn_885AA928 */
ts4_word ts4_tailcall_fn_885AA928_885A02A8(ts4_word a0)
{
    return fn_885AA928((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02B8: tailcall fn_885ABB98 */
ts4_word ts4_tailcall_fn_885ABB98_885A02B8(ts4_word a0)
{
    return fn_885ABB98((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02C8: tailcall fn_885AAF98 */
ts4_word ts4_tailcall_fn_885AAF98_885A02C8(ts4_word a0)
{
    return fn_885AAF98((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x885A02E0: tailcall ts4_tailcall_fn_885AAAA8_885A02B0 */
ts4_word ts4_tailcall_fn_885A02B0_885A02E0(ts4_word a0)
{
    return ts4_tailcall_fn_885AAAA8_885A02B0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A02E8: tailcall ts4_tailcall_fn_885AAB80_885A02C0 */
ts4_word ts4_tailcall_fn_885A02C0_885A02E8(ts4_word a0)
{
    return ts4_tailcall_fn_885AAB80_885A02C0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x885A02F0: tailcall ts4_tailcall_fn_885AB200_8859FFE0 */
ts4_word ts4_tailcall_fn_8859FFE0_885A02F0(ts4_word a0)
{
    return ts4_tailcall_fn_885AB200_8859FFE0((ts4_word)(a0 + -4));
}

