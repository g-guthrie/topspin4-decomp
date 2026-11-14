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
ts4_word ts4_handle_forward_88610A48();
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
ts4_word ts4_if_call_seq_u32_off10_889293A0();
ts4_word fn_88929420();
ts4_word fn_889298D8();
ts4_word fn_8892EB28();
ts4_word fn_8892F508();
ts4_word fn_889310A0();
ts4_word fn_88931388();
ts4_word fn_889313E8();
ts4_word fn_88931950();
ts4_word ts4_get_fn_8857B830_88932F38();
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

/* Swing_DLL.xex 0x88929630: if_call_seq u32@0x24, lbl_880D6218, u32@0x0, fn_88922B28, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off24_88929630(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6218;
    if ((ts4_word)t1 != 0) {
        fn_88922B28((ts4_word)t1);
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((ts4_word)t3 != 0) {
            ts4_destroy_owned_object((ts4_word)t3);
        }
        ts4_tsu_cleanup_end((ts4_word)t1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    ts4_if_call_seq_u32_off10_889293A0((ts4_word)(a0 + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(ts4_word)lbl_880D6B70;
    t9 = fn_88617D28((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88933178: tailcall ts4_get_fn_8857B830_88932F38 */
ts4_word ts4_tailcall_fn_88932F38_88933178(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ts4_get_fn_8857B830_88932F38((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

