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

extern char g_ts4_session_context[];
extern char g_ts4_session_state[];
extern char lbl_880C1320[];
extern char lbl_880CFC4E[];
extern char lbl_880CFC4F[];
extern char lbl_880CFF36[];
extern char lbl_880D19F0[];
extern char lbl_880D5A64[];
extern char lbl_880D5A78[];
extern char lbl_880D5B34[];
extern char lbl_880D5BAC[];
extern char lbl_880D5EF0[];
extern char lbl_880D6218[];
extern char lbl_880D6330[];
extern char lbl_880D63EC[];
extern char lbl_880D6418[];
extern char lbl_880D6538[];
extern char lbl_880D6658[];
extern char lbl_880D6778[];
extern char lbl_880D6AC4[];
extern char lbl_880D6AF4[];
extern char lbl_880D6B70[];
extern char lbl_88C6B4AC[];
extern char lbl_88D3CD50[];
extern char lbl_88D458E0[];
extern char lbl_88D458F0[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B38[];
ts4_word RtlLeaveCriticalSection();
ts4_word fn_8816D220();
ts4_word fn_881717A0();
ts4_word fn_881898E8();
ts4_word fn_881B9148();
ts4_word ts4_tailcall_NetDll_listen_884F02D0();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word fn_8860AB58();
ts4_word fn_8860DCF8();
ts4_word fn_88610A48();
ts4_word fn_88613268();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88628098();
ts4_word fn_888860A0();
ts4_word fn_88918EA8();
ts4_word fn_88919348();
ts4_word fn_88919780();
ts4_word fn_8891AE70();
ts4_word fn_8891FA30();
ts4_word fn_88921740();
ts4_word fn_88922B28();
ts4_word fn_88923380();
ts4_word fn_88929308();
ts4_word fn_88929420();
ts4_word fn_889298D8();
ts4_word fn_8892EB28();
ts4_word fn_8892F508();
ts4_word fn_889310A0();
ts4_word fn_88931388();
ts4_word fn_889313E8();
ts4_word fn_88931950();
ts4_word fn_88933198();
ts4_word fn_889333F0();
ts4_word fn_88933EF8();
ts4_word fn_889340B0();
ts4_word fn_88934990();
ts4_word fn_88936AF0();
ts4_word fn_889393C0();
ts4_word fn_889396A8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_create_container_factory();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_memset();
ts4_word ts4_span28_append();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8891F788: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8891F788(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    return t7;
}

/* Swing_DLL.xex 0x8891F830: get u32@0x42c, fn_88919780 */
ts4_word ts4_get_u32_off42c_8891F830(ts4_word a0, ts4_word a1)
{
    return fn_88919780((ts4_word)a0, (ts4_word)1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1068)));
}

/* Swing_DLL.xex 0x8891FDE0: call_seq fn_8891FA30, fn_8891AE70 */
ts4_word ts4_call_seq_fn_8891FA30_8891FDE0(ts4_word a0)
{
    ts4_word t2;

    fn_8891FA30();
    t2 = fn_8891AE70((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8891FE18: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_88919348, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_8891FE18(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1080, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_88919348((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x8891FF58: call_seq lbl_880CFC4E, fn_88918EA8, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880CFC4E_8891FF58(ts4_word a0)
{
    ts4_word t2;

    fn_88918EA8((ts4_word)(ts4_word)lbl_880CFC4E);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88921B80: tailcall fn_88921740 */
ts4_word ts4_tailcall_fn_88921740_88921B80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88921740((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889222C8: set u32@0x0 */
void ts4_set_u32_off0_889222C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x889222E0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_889222E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88922308: fn  */
ts4_word ts4_fn_88922308(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return (a2 + -1);
}

/* Swing_DLL.xex 0x88922310: fn  */
ts4_word ts4_fn_88922310(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return (a2 + 1);
}

/* Swing_DLL.xex 0x88922318: fn  */
ts4_word ts4_fn_88922318(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922328: fn  */
ts4_word ts4_fn_88922328(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922350: fn  */
ts4_word ts4_fn_88922350(void)
{
    return -1;
}

/* Swing_DLL.xex 0x889224C8: fn  */
ts4_word ts4_fn_889224C8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x889224F8: fn  */
ts4_word ts4_fn_889224F8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922500: fn  */
ts4_word ts4_fn_88922500(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922510: fn  */
ts4_word ts4_fn_88922510(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922518: fn  */
ts4_word ts4_fn_88922518(void)
{
    return ((983040) | 65535);
}

/* Swing_DLL.xex 0x88922540: fn  */
ts4_word ts4_fn_88922540(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922548: fn  */
ts4_word ts4_fn_88922548(void)
{
    return 2;
}

/* Swing_DLL.xex 0x88922558: fn  */
ts4_word ts4_fn_88922558(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922568: fn  */
ts4_word ts4_fn_88922568(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922570: fn  */
ts4_word ts4_fn_88922570(void)
{
    return 2;
}

/* Swing_DLL.xex 0x88922588: fn  */
ts4_word ts4_fn_88922588(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922590: fn  */
ts4_word ts4_fn_88922590(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922598: fn  */
ts4_word ts4_fn_88922598(void)
{
    return 0;
}

/* Swing_DLL.xex 0x889225A0: fn  */
ts4_word ts4_fn_889225A0(void)
{
    return 3;
}

/* Swing_DLL.xex 0x88922658: get u32@0xc */
ts4_word ts4_get_u32_offc_88922658(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) != 0);
}

/* Swing_DLL.xex 0x88922680: get u32@0x4c, u32@0x24 */
ts4_word ts4_get_u32_off4c_88922680(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return (((*(ts4_word *)((char *)(ts4_word)(t1) + (a1 << 2))) + t2) + -20);
}

/* Swing_DLL.xex 0x889226A0: get u32@0x0, u32@0x48, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_889226A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 72))))((ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    return a0;
}

/* Swing_DLL.xex 0x88922840: fn  */
ts4_word ts4_fn_88922840(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88922858: fn  */
ts4_word ts4_fn_88922858(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88922860: get u32@0x8, u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off8_88922860(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    return t4;
}

/* Swing_DLL.xex 0x889228B8: get u32@0x74 */
ts4_word ts4_get_u32_off74_889228B8(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x889228C8: get u32@0x78, u32@0x74 */
ts4_word ts4_get_u32_off78_889228C8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 116))) >> 2);
}

/* Swing_DLL.xex 0x88922920: if_get u32@0x20, u32@0x10 */
ts4_word ts4_if_get_u32_off20_88922920(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 16));
    }
    return 0;
}

/* Swing_DLL.xex 0x88922940: get u32@0x0, u32@0x4c, vcall, u32@0x8 */
ts4_word ts4_get_u32_off0_88922940(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 76))))((ts4_word)a1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return t3;
}

/* Swing_DLL.xex 0x88922988: get u32@0x8, u32@0x0 */
ts4_word ts4_get_u32_off8_88922988(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (((a1 << 3) + (*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + t1);
}

/* Swing_DLL.xex 0x889229A0: addr lbl_880D63EC, u32@0x8, u32@0x0, u32@0x4 */
void ts4_addr_lbl_880D63EC_889229A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D63EC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88922A20: get u32@0x8, u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off8_88922A20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    (void)a0;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
    *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    return t4;
}

/* Swing_DLL.xex 0x88922A78: get u32@0x8 */
ts4_word ts4_get_u32_off8_88922A78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88922A80: get u32@0x8, u32@0x0, u32@0x48, vcall, memcpy */
ts4_word ts4_get_u32_off8_88922A80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)a2);
    t5 = memcpy((ts4_word)t4, (ts4_word)a3, (ts4_word)a4);
    return t5;
}

/* Swing_DLL.xex 0x88922BB0: fn  */
ts4_word ts4_fn_88922BB0(void)
{
    return 16;
}

/* Swing_DLL.xex 0x88922CE0: set u32@0xc, u32@0x14, u32@0x10, u8@0x18 */
void ts4_set_u32_offc_88922CE0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((983040) | 65535);
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)3;
    return;
}

/* Swing_DLL.xex 0x889232C0: get u32@0x0 */
ts4_word ts4_get_u32_off0_889232C0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0);
}

/* Swing_DLL.xex 0x889233E0: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_889233E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    return;
}

/* Swing_DLL.xex 0x88923740: get u32@0x0, u32@0x58, vcall, u32@0x34, u8@0x38 */
ts4_word ts4_get_u32_off0_88923740(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)a2;
    return t3;
}

/* Swing_DLL.xex 0x88923890: get u32@0x0, u32@0x20, u32@0x60, vcall, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_88923890(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 96))))((ts4_word)a1, (ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88923990: set u32@0x0, u32@0x4, u32@0xc, u32@0x8 */
void ts4_set_u32_off0_88923990(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x889239B0: fn  */
ts4_word ts4_fn_889239B0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x889239B8: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_889239B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x889239D8: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_889239D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x88923C48: get u32@0x8, u32@0x3c */
ts4_word ts4_get_u32_off8_88923C48(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 60));
}

/* Swing_DLL.xex 0x88923D40: get u32@0x0, u32@0x8, u32@0x8, u32@0x30, u32@0x30 */
ts4_word ts4_get_u32_off0_88923D40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 48);
    return ((t4 - (*(ts4_word *)((char *)(ts4_word)(t3) + 48))) == 0);
}

/* Swing_DLL.xex 0x88923D68: if_get u32@0x8, u32@0x30, u32@0x0, u32@lbl_88D45B1C, u32@0x27c, u32@0x0 */
void ts4_if_get_u32_off8_88923D68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 48));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x889242C0: if_get u32@0x8, u32@0x4 */
ts4_word ts4_if_get_u32_off8_889242C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 4));
    }
    return 0;
}

/* Swing_DLL.xex 0x889242E0: if_get u32@0x4, u32@0x0, u32@0x14, vcall, u32@0x4, u32@0x0 */
ts4_word ts4_if_get_u32_off4_889242E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        p9 = (ts4_word)t5;
        if ((ts4_word)t5 != 0) {
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
            p9 = (ts4_word)t8;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88924548: get u32@0xc, u32@0x14, u32@0x0 */
void ts4_get_u32_offc_88924548(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 12))) + 20));
    return;
}

/* Swing_DLL.xex 0x88924558: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_88924558(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x889245A0: get u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_get_u32_off10_889245A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 12)) + t5);
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88924638: get u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_get_u32_off10_88924638(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 12)) + t5);
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x889246E0: get u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_get_u32_off10_889246E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 12)) + t5);
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x889248C8: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x48, vcall */
ts4_word ts4_get_u32_off0_889248C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 72))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    return t7;
}

/* Swing_DLL.xex 0x88924C30: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x14, vcall */
ts4_word ts4_get_u32_off0_88924C30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 20))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    return t7;
}

/* Swing_DLL.xex 0x88924C90: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_u32_off0_88924C90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 16))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    return t7;
}

/* Swing_DLL.xex 0x88924CF0: get u32@0x8, u32@0x4, u32@0x0, u32@0x4c, vcall, u32@0x4 */
ts4_word ts4_get_u32_off8_88924CF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 4));
    return a0;
}

/* Swing_DLL.xex 0x88924DB0: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0xb8, vcall */
ts4_word ts4_get_u32_off0_88924DB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 184))))((ts4_word)t4, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x88924E10: get u32@0x8, u32@0x4, u32@0x0, u32@0x4c, vcall, u32@0x34 */
ts4_word ts4_get_u32_off8_88924E10(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)t2);
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 52);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
    t8 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
    t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 56))))((ts4_word)t6, (ts4_word)t8);
    return t10;
}

/* Swing_DLL.xex 0x88924E70: get u32@0x8, u32@0x4, u32@0x0, u32@0x4c, vcall, u32@0x34 */
ts4_word ts4_get_u32_off8_88924E70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)t2);
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 52);
    t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 60))))((ts4_word)t6, (ts4_word)(t5 + 4));
    return t9;
}

/* Swing_DLL.xex 0x88924ED0: set u32@0x0, u32@0x8, u32@0x4 */
ts4_word ts4_set_u32_off0_88924ED0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    (void)a2;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)((983040) | 65535);
    return 0;
}

/* Swing_DLL.xex 0x88924EF0: get u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_get_u32_off10_88924EF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 12)) + t5);
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88925388: get u32@0x0 */
ts4_word ts4_get_u32_off0_88925388(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1) != 0);
}

/* Swing_DLL.xex 0x88925480: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_88925480(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Swing_DLL.xex 0x88926A70: if_get u32@lbl_88D45B20, fn_8816D220, u32@0x0, u32@0x4, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D45B20_88926A70(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t2;
    ts4_word t5;
    ts4_word t10;

    t2 = fn_8816D220((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)((1193148416) | 37738));
    if ((ts4_word)t2 == 0) {
        p7 = (ts4_word)0;
    } else {
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2);
        p7 = (ts4_word)t5;
    }
    t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 64))))((ts4_word)p7, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)(t10 & 0xff) == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 20))))((ts4_word)p7);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 0))))((ts4_word)p7, (ts4_word)1);
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)p7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p7) + 36));
    return 1;
}

/* Swing_DLL.xex 0x88926B40: if_get u32@lbl_88D45B20, fn_8816D220, u32@0x0, u32@0x4, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D45B20_88926B40(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t2;
    ts4_word t5;
    ts4_word t10;

    t2 = fn_8816D220((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)((1193148416) | 37738));
    if ((ts4_word)t2 == 0) {
        p7 = (ts4_word)0;
    } else {
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2);
        p7 = (ts4_word)t5;
    }
    t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 60))))((ts4_word)p7, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)(t10 & 0xff) == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 20))))((ts4_word)p7);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 0))))((ts4_word)p7, (ts4_word)1);
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)p7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p7) + 36));
    return 1;
}

/* Swing_DLL.xex 0x88926DA0: if_get u32@0x8, u32@0x0, lbl_880C1320 */
ts4_word ts4_if_get_u32_off8_88926DA0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((int)t2 != -1) {
            return (t2 + a0);
        }
        return (ts4_word)lbl_880C1320;
    }
    return 0;
}

/* Swing_DLL.xex 0x88927068: if_call_seq u32@0x4, u32@0x0, fn_881717A0, ts4_span28_append */
ts4_word ts4_if_call_seq_u32_off4_88927068(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_881717A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1, (ts4_word)a1);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 == (ts4_word)t1) {
        t4 = ts4_span28_append((ts4_word)a0, (ts4_word)a1);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x889270C0: call_seq fn_88617D88, lbl_880D6AF4, u32@0x0, u32@0x1c, u32@lbl_88D458F0 */
ts4_word ts4_call_seq_fn_88617D88_889270C0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6AF4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)lbl_88D458F0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88928368: if_get u32@0x1c, u32@0x20, u32@0x0, u32@0x14, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_88928368(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    fn_88922B28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t11 = fn_881B9148((ts4_word)(a0 + 16));
    return t11;
}

/* Swing_DLL.xex 0x889285A0: call_seq fn_88617D88, lbl_880D6AC4, u32@lbl_88D45B1C, u32@0x238, u32@0x0, u32@0x1c */
ts4_word ts4_call_seq_fn_88617D88_889285A0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 568) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6AC4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88928638: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_88928638(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x889292F0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_889292F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x889293A0: if_call_seq u32@0x10, lbl_880D6330, u32@0x0, fn_88922B28, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off10_889293A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6330;
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_88922B28((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D6330);
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((ts4_word)t3 != 0) {
            ts4_destroy_owned_object((ts4_word)t3);
        }
        t6 = ts4_tsu_cleanup_end((ts4_word)t1);
        p7 = (ts4_word)t6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    return p7;
}

/* Swing_DLL.xex 0x88929BD8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D6538, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88929BD8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D6538;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)p3;
    *(ts4_word *)((char *)(ts4_word)(p3) + 4) = (ts4_word)t4;
    t5 = fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88929C78: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D6778, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88929C78(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D6778;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)p3;
    *(ts4_word *)((char *)(ts4_word)(p3) + 4) = (ts4_word)t4;
    t5 = fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88929D18: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D6658, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88929D18(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D6658;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)p3;
    *(ts4_word *)((char *)(ts4_word)(p3) + 4) = (ts4_word)t4;
    t5 = fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88929DB8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D6418, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88929DB8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D6418;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)p3;
    *(ts4_word *)((char *)(ts4_word)(p3) + 4) = (ts4_word)t4;
    t5 = fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88929F50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88929420, u32@0x0, u32@0x4, fn_881898E8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88929F50(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88929420((ts4_word)t2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)p4;
    *(ts4_word *)((char *)(ts4_word)(p4) + 4) = (ts4_word)t6;
    t7 = fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x88929FD0: call_seq fn_88929308 */
ts4_word ts4_call_seq_fn_88929308_88929FD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[3];
    ts4_word t1;

    (void)a0;
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    loc50[1] = (ts4_word)((983040) | 65535);
    t1 = fn_88929308((ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    return t1;
}

/* Swing_DLL.xex 0x8892A018: call_seq fn_88929308 */
ts4_word ts4_call_seq_fn_88929308_8892A018(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[3];
    ts4_word t1;

    (void)a0;
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    loc50[1] = (ts4_word)((983040) | 65535);
    t1 = fn_88929308((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x8892A150: addr lbl_880CFF36, fn_889298D8 */
ts4_word ts4_addr_lbl_880CFF36_8892A150(void)
{
    return fn_889298D8((ts4_word)(ts4_word)lbl_880CFF36);
}

/* Swing_DLL.xex 0x8892A160: addr lbl_880CFC4F, fn_889298D8 */
ts4_word ts4_addr_lbl_880CFC4F_8892A160(void)
{
    return fn_889298D8((ts4_word)(ts4_word)lbl_880CFC4F);
}

/* Swing_DLL.xex 0x8892A910: get fn_88628098, u32@0x1c, ts4_find_service, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_get_fn_88628098_8892A910(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t6;

    fn_88628098();
    t3 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28)));
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 76))))((ts4_word)t3, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t6;
    return t6;
}

/* Swing_DLL.xex 0x8892B608: call_seq lbl_880CFF36, fn_889298D8, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880CFF36_8892B608(ts4_word a0)
{
    ts4_word t2;

    fn_889298D8((ts4_word)(ts4_word)lbl_880CFF36);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x8892B688: addr lbl_880CFC4F, fn_889298D8 */
ts4_word ts4_addr_lbl_880CFC4F_8892B688(void)
{
    return fn_889298D8((ts4_word)(ts4_word)lbl_880CFC4F);
}

/* Swing_DLL.xex 0x8892ED88: if_call_seq u32@0x8, fn_8892EB28, u32@0x0, lbl_880C1320 */
ts4_word ts4_if_call_seq_u32_off8_8892ED88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        fn_8892EB28();
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t4 != -1) {
        return (t4 + a0);
    }
    return (ts4_word)lbl_880C1320;
}

/* Swing_DLL.xex 0x8892EDF0: if_set ts4_create_container_factory, u32@0x4, u32@0x0, u32@0x40, vcall, u32@0x0 */
ts4_word ts4_if_set_ts4_create_container_factory_8892EDF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = ts4_create_container_factory();
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 64))))((ts4_word)t1, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)(t4 & 0xff) != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 32))))((ts4_word)a0, (ts4_word)t6);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8892FC28: if_call_seq fn_8892F508, u32@0x14, fn_88923380, fn_8860AB58 */
ts4_word ts4_if_call_seq_fn_8892F508_8892FC28(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8892F508((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) != 0) {
        t3 = fn_88923380((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
        t4 = fn_8860AB58((ts4_word)t3);
        return t4;
    }
    return 0;
}

/* Swing_DLL.xex 0x88930A20: set u16@0x0 */
void ts4_set_u16_off0_88930A20(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x88930A30: fn  */
ts4_word ts4_fn_88930A30(void)
{
    return 2;
}

/* Swing_DLL.xex 0x88930A38: fn  */
ts4_word ts4_fn_88930A38(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930AD0: fn  */
ts4_word ts4_fn_88930AD0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88930AD8: get u32@0x60, u32@0x60 */
ts4_word ts4_get_u32_off60_88930AD8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(t1 + 1);
    return (t1 + 1);
}

/* Swing_DLL.xex 0x88930B08: fn  */
ts4_word ts4_fn_88930B08(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930B20: fn  */
ts4_word ts4_fn_88930B20(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930B38: fn  */
ts4_word ts4_fn_88930B38(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930B50: fn  */
ts4_word ts4_fn_88930B50(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930B68: fn  */
ts4_word ts4_fn_88930B68(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930B80: fn  */
ts4_word ts4_fn_88930B80(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930B98: fn  */
ts4_word ts4_fn_88930B98(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930BB0: fn  */
ts4_word ts4_fn_88930BB0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930BC8: fn  */
ts4_word ts4_fn_88930BC8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930BE0: fn  */
ts4_word ts4_fn_88930BE0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930BF8: fn  */
ts4_word ts4_fn_88930BF8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930C10: fn  */
ts4_word ts4_fn_88930C10(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930C28: fn  */
ts4_word ts4_fn_88930C28(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930C40: fn  */
ts4_word ts4_fn_88930C40(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930C58: fn  */
ts4_word ts4_fn_88930C58(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930DC0: fn  */
ts4_word ts4_fn_88930DC0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930DD8: fn  */
ts4_word ts4_fn_88930DD8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930DF0: fn  */
ts4_word ts4_fn_88930DF0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E08: fn  */
ts4_word ts4_fn_88930E08(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E20: fn  */
ts4_word ts4_fn_88930E20(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E28: fn  */
ts4_word ts4_fn_88930E28(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E38: fn  */
ts4_word ts4_fn_88930E38(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E50: fn  */
ts4_word ts4_fn_88930E50(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E68: fn  */
ts4_word ts4_fn_88930E68(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930E80: fn  */
ts4_word ts4_fn_88930E80(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88930E88: fn  */
ts4_word ts4_fn_88930E88(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88930EA8: fn  */
ts4_word ts4_fn_88930EA8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88930ED8: if_get u32@0x8, u32@0x4, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_if_get_u32_off8_88930ED8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88930F08: fn  */
ts4_word ts4_fn_88930F08(void)
{
    return 3072;
}

/* Swing_DLL.xex 0x88930F10: addr lbl_88D3CD50 */
ts4_word ts4_addr_lbl_88D3CD50_88930F10(void)
{
    return (ts4_word)lbl_88D3CD50;
}

/* Swing_DLL.xex 0x88930F50: addr lbl_880D5B34, u8@0x48, u32@0x0 */
void ts4_addr_lbl_880D5B34_88930F50(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 72) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5B34;
    return;
}

/* Swing_DLL.xex 0x88930F78: fn  */
ts4_word ts4_fn_88930F78(void)
{
    return 20;
}

/* Swing_DLL.xex 0x88930F80: fn  */
ts4_word ts4_fn_88930F80(void)
{
    return 16;
}

/* Swing_DLL.xex 0x88930F90: get u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off0_88930F90(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
    return ((t3 & 0xff) == 0);
}

/* Swing_DLL.xex 0x88931158: get u16@0x0, u16@0x0 */
ts4_word ts4_get_u16_off0_88931158(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return (((*(unsigned short *)((char *)(ts4_word)(a1) + 0)) - t1) == 0);
}

/* Swing_DLL.xex 0x88931170: get u16@0x0, u16@0x0 */
ts4_word ts4_get_u16_off0_88931170(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return ((t1 - (*(unsigned short *)((char *)(ts4_word)(a1) + 0))) & 0xffff);
}

/* Swing_DLL.xex 0x88931198: get u16@0x0, u16@0x0 */
void ts4_get_u16_off0_88931198(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(a0) + 0)) + a1);
    return;
}

/* Swing_DLL.xex 0x889311E8: get u32@0x4c0, u32@g_ts4_session_context, u32@0x0, u32@0x3c, vcall, lbl_880D5A64 */
ts4_word ts4_get_u32_off4c0_889311E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1216);
    t2 = *(ts4_word *)g_ts4_session_context;
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 60))))((ts4_word)t2, (ts4_word)t1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A64;
    return t5;
}

/* Swing_DLL.xex 0x88931240: get u32@0x4c4, u32@g_ts4_session_context, u32@0x0, u32@0x3c, vcall, lbl_880D5A64 */
ts4_word ts4_get_u32_off4c4_88931240(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1220);
    t2 = *(ts4_word *)g_ts4_session_context;
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 60))))((ts4_word)t2, (ts4_word)t1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    return t5;
}

/* Swing_DLL.xex 0x88931318: get u32@0x1c, u32@0x18 */
ts4_word ts4_get_u32_off1c_88931318(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 24))) >> 2);
}

/* Swing_DLL.xex 0x88931330: get u32@0x18, u32@0x18, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off18_88931330(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)t2);
    return ((t5 & 0xff) == 0);
}

/* Swing_DLL.xex 0x88931370: get u32@0x18, u32@0x18, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off18_88931370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x889314A0: get u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off4_889314A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4))))((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x889314F0: if_get u32@0x8, u32@0x4, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_if_get_u32_off8_889314F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 0) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 4) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 8) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t2)) + 12) = (ts4_word)a5;
    return;
}

/* Swing_DLL.xex 0x889315A0: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_889315A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88931688: if_get u32@0x42c, lbl_880D5BAC, u32@0x0, u32@g_ts4_session_context, u32@0x0, u32@0x60 */
ts4_word ts4_if_get_u32_off42c_88931688(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5BAC;
    p6 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)g_ts4_session_context;
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 96))))((ts4_word)t2, (ts4_word)t1);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return p6;
}

/* Swing_DLL.xex 0x88931780: get u32@0x10 */
ts4_word ts4_get_u32_off10_88931780(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88931788: get u32@0x10 */
ts4_word ts4_get_u32_off10_88931788(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x889317A0: get u32@0x14 */
ts4_word ts4_get_u32_off14_889317A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x889317A8: get u32@0x14 */
ts4_word ts4_get_u32_off14_889317A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x889317C8: get u32@0xc, u32@0xc */
ts4_word ts4_get_u32_offc_889317C8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x889317E0: fn  */
ts4_word ts4_fn_889317E0(ts4_word a0)
{
    return (a0 + 8);
}

/* Swing_DLL.xex 0x889317E8: fn  */
ts4_word ts4_fn_889317E8(ts4_word a0)
{
    return (a0 + 4);
}

/* Swing_DLL.xex 0x88931840: set u16@0x6 */
void ts4_set_u16_off6_88931840(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)a1;
    return;
}

/* Swing_DLL.xex 0x88931870: set u32@0x8, u16@0x6 */
void ts4_set_u32_off8_88931870(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x88931928: if_set u32@0x4 */
void ts4_if_set_u32_off4_88931928(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88931938: get u32@0x42c, u32@0x8 */
ts4_word ts4_get_u32_off42c_88931938(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1068))) + 8))))((ts4_word)(a0 + 1068), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88931B20: get u32@0x208, u32@0x0, u32@0x204, u32@0x10, vcall, u32@0x204 */
ts4_word ts4_get_u32_off208_88931B20(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 520);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 516);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 16))))((ts4_word)t1, (ts4_word)(a0 + 4), (ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 516) = (ts4_word)0;
    return t5;
}

/* Swing_DLL.xex 0x88931FC0: set u32@0x20, u32@0x24 */
ts4_word ts4_set_u32_off20_88931FC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)3;
    return 0;
}

/* Swing_DLL.xex 0x88932180: get u32@0x414, u32@0x414 */
void ts4_get_u32_off414_88932180(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1044) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1044)) + 1);
    return;
}

/* Swing_DLL.xex 0x88932190: if_get u32@0x1c, u32@0x0, u32@0x8, vcall, u32@0x0, u32@0x1c */
ts4_word ts4_if_get_u32_off1c_88932190(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p9 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 48))))((ts4_word)a0, (ts4_word)t6);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x88932280: get u32@0x28 */
ts4_word ts4_get_u32_off28_88932280(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) == 0);
}

/* Swing_DLL.xex 0x88932360: get u32@0x14 */
ts4_word ts4_get_u32_off14_88932360(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x88932368: get u32@0x18 */
ts4_word ts4_get_u32_off18_88932368(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x88932370: get u16@0x6 */
ts4_word ts4_get_u16_off6_88932370(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 6));
}

/* Swing_DLL.xex 0x88932378: fn  */
ts4_word ts4_fn_88932378(ts4_word a0)
{
    return (a0 + 4);
}

/* Swing_DLL.xex 0x88932380: fn  */
ts4_word ts4_fn_88932380(ts4_word a0)
{
    return (a0 + 4);
}

/* Swing_DLL.xex 0x88932498: get u32@0x1c, fn_88931388 */
ts4_word ts4_get_u32_off1c_88932498(ts4_word a0)
{
    return fn_88931388((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x889328E8: tailcall RtlLeaveCriticalSection */
ts4_word ts4_tailcall_RtlLeaveCriticalSection_889328E8(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(a0 + 84));
}

/* Swing_DLL.xex 0x88932900: set u8@0x20, u32@0x1c */
void ts4_set_u8_off20_88932900(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88932AB0: if_get u32@lbl_88D458E0, u32@0x0, u32@0x48 */
ts4_word ts4_if_get_u32_lbl_88D458E0_88932AB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a1;
    t1 = *(ts4_word *)lbl_88D458E0;
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)a0, (ts4_word)a2);
    }
    return 0;
}

/* Swing_DLL.xex 0x88932C58: if_get u32@0x4, ts4_tailcall_NetDll_listen_884F02D0, u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off4_88932C58(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = ts4_tailcall_NetDll_listen_884F02D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1);
    if ((int)t2 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
        return 0;
    }
    return 1;
}

/* Swing_DLL.xex 0x88932D48: if_get u32@0x4, u32@0x0, u32@0x14, vcall, u32@0x4 */
ts4_word ts4_if_get_u32_off4_88932D48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p5 = (ts4_word)a0;
    if ((int)t1 != -1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88932F20: get u32@0x42c, u32@0x28 */
void ts4_get_u32_off42c_88932F20(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068));
    return;
}

/* Swing_DLL.xex 0x88932F38: get ts4_get_u32__imp_KeTimeStampBundle_8857B830, u32@0x0, u32@0x42c, u32@0x3c, vcall */
ts4_word ts4_get_fn_8857B830_88932F38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 1068);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 60))))((ts4_word)a0, (ts4_word)a2, (ts4_word)(t1 - t3));
    return t5;
}

/* Swing_DLL.xex 0x889330A0: get u32@0x14, u8@0x2c */
ts4_word ts4_get_u32_off14_889330A0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 44));
}

/* Swing_DLL.xex 0x889330D8: if_call_seq fn_88931950, u32@0x68, fn_889313E8 */
ts4_word ts4_if_call_seq_fn_88931950_889330D8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    if ((ts4_word)a1 != 0) {
        fn_88931950((ts4_word)(a0 + 72));
        t3 = fn_889313E8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104)), (ts4_word)a1);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88933360: set u8@0x2c */
void ts4_set_u8_off2c_88933360(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88933370: set u8@0x2c */
void ts4_set_u8_off2c_88933370(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88933768: get fn_889333F0, u32@0x0, u32@0x40, vcall */
ts4_word ts4_get_fn_889333F0_88933768(ts4_word a0)
{
    ts4_word t4;

    fn_889333F0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x889337C0: if_get u8@0x420, u32@0x0, u32@0x4, vcall, u8@0x420 */
ts4_word ts4_if_get_u8_off420_889337C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    unsigned char t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1056);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 == 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)(a0 + 4));
        *(unsigned char *)((char *)(ts4_word)(a0) + 1056) = (unsigned char)1;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88933810: call_seq fn_88610A48 */
ts4_word ts4_call_seq_fn_88610A48_88933810(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)((1412104192) | 21116);
    fn_88610A48((ts4_word)a0, (ts4_word)(a1 + 48), (ts4_word)(ts4_word)&loc50[0]);
    return a0;
}

/* Swing_DLL.xex 0x88933F90: get u32@0x4 */
ts4_word ts4_get_u32_off4_88933F90(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 7)) >> 3);
}

/* Swing_DLL.xex 0x88933FD0: set u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off4_88933FD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88934010: get u32@0x1c, fn_88933198 */
ts4_word ts4_get_u32_off1c_88934010(ts4_word a0)
{
    return fn_88933198((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x88934088: if_get u32@0x42c, u32@0x4, u8@0x430, u8@0x6d */
void ts4_if_get_u32_off42c_88934088(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t3 = *(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    if ((ts4_word)t3 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(t3) + 109) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 1072));
    return;
}

/* Swing_DLL.xex 0x889340E8: tailcall fn_889340B0 */
ts4_word ts4_tailcall_fn_889340B0_889340E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889340B0((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889343E8: call_seq u32@0x8, u32@0x4, u32@lbl_88D45B1C, u32@0xc, u32@0x27c, u32@0x64 */
ts4_word ts4_call_seq_u32_off8_889343E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 636));
    fn_889310A0();
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    t4 = ts4_memset((ts4_word)(a0 + 33), (ts4_word)0, (ts4_word)64);
    return t4;
}

/* Swing_DLL.xex 0x88934640: if_get u32@0x4, u32@0x0, u32@0x14, vcall, u32@0x4, u32@0x8 */
ts4_word ts4_if_get_u32_off4_88934640(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p12;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p5 = (ts4_word)a0;
    if ((int)t1 != -1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
        p5 = (ts4_word)t4;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p12 = (ts4_word)p5;
    if ((ts4_word)t7 != 0) {
        t8 = *(ts4_word *)g_ts4_session_context;
        t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 60))))((ts4_word)t8, (ts4_word)t7, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x88934B68: tailcall fn_88934990 */
ts4_word ts4_tailcall_fn_88934990_88934B68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88934990((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88934F58: call_seq fn_88617D88, lbl_880D5EF0, u32@0x1c, u32@0x0, u32@0x20, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_88934F58(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5EF0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    *(ts4_word *)g_ts4_session_state = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88934FB8: if_get u8@0x420, u32@0x0, u32@0x4, vcall, u8@0x420, u32@0x8 */
ts4_word ts4_if_get_u8_off420_88934FB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1056);
    if ((ts4_word)t1 == 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)(a0 + 4));
        *(unsigned char *)((char *)(ts4_word)(a0) + 1056) = (unsigned char)1;
    }
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 7)) >> 3);
}

/* Swing_DLL.xex 0x88936980: if_call_seq u32@0x14, lbl_880D5A78, u32@0x0, fn_888860A0, u32@0x14, lbl_880D5A64 */
ts4_word ts4_if_call_seq_u32_off14_88936980(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A78;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A64;
    return p3;
}

/* Swing_DLL.xex 0x88936C28: if_call_seq fn_88933EF8, fn_88936AF0 */
ts4_word ts4_if_call_seq_fn_88933EF8_88936C28(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88933EF8((ts4_word)a0, (ts4_word)1);
    if ((ts4_word)(t1 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a0, (ts4_word)a1);
    }
    return a0;
}

/* Swing_DLL.xex 0x88936C80: if_get u32@0x0, u32@0x0, u32@0x10, vcall, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_off0_88936C80(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 16))))((ts4_word)a0, (ts4_word)(((t2 + 7)) >> 3));
    if ((ts4_word)(t4 & 0xff) != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    }
    return t4;
}
