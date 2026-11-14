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
extern char lbl_880C1324[];
extern char lbl_880C1334[];
extern char lbl_880C13BC[];
extern char lbl_880CDBB7[];
extern char lbl_880CDC02[];
extern char lbl_880CFC4F[];
extern char lbl_880D052B[];
extern char lbl_880D0532[];
extern char lbl_880D0533[];
extern char lbl_880D19F0[];
extern char lbl_880D1F80[];
extern char lbl_880D1F8C[];
extern char lbl_880D2208[];
extern char lbl_880D23E0[];
extern char lbl_880D24AC[];
extern char lbl_880D24B8[];
extern char lbl_880D24E0[];
extern char lbl_880D2A68[];
extern char lbl_880D2CF8[];
extern char lbl_880D5A64[];
extern char lbl_880D6B70[];
extern char lbl_880D7310[];
extern char lbl_880D7380[];
extern char lbl_880D73C4[];
extern char lbl_880D73FC[];
extern char lbl_880D7570[];
extern char lbl_880E23A0[];
extern char lbl_880E23D8[];
extern char lbl_88C6B4AC[];
extern char lbl_88D3CD50[];
extern char lbl_88D3EB60[];
extern char lbl_88D45834[];
extern char lbl_88D45838[];
extern char lbl_88D45848[];
extern char lbl_88D45910[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
ts4_word fn_881512B8();
ts4_word fn_88151560();
ts4_word ts4_flagged_object_create_extra_88153678();
ts4_word fn_88153A70();
ts4_word ts4_flagged_object_create_88153B30();
ts4_word ts4_flagged_object_create_88153BE0();
ts4_word ts4_flagged_object_create_extra_88153C90();
ts4_word ts4_flagged_object_create_88153D48();
ts4_word ts4_flagged_object_create_88153DF8();
ts4_word fn_88153EA8();
ts4_word ts4_flagged_object_create_extra_88153F60();
ts4_word ts4_flagged_object_create_88154018();
ts4_word ts4_flagged_object_create_88154180();
ts4_word fn_88154230();
ts4_word ts4_flagged_object_create_881544D8();
ts4_word fn_88177110();
ts4_word fn_881ACBA8();
ts4_word fn_881B9148();
ts4_word ts4_tailcall_NetDll_WSACleanup_884F0238();
ts4_word fn_88563F20();
ts4_word ts4_call_seq_fn_88563F20_885640B0();
#ifndef _MSC_VER
#define floor ts4_floor_non_msvc /* avoid gcc builtin floor(double) prototype clash */
#endif
ts4_word floor();
ts4_word fn_88564B10();
ts4_word fn_88564D28();
ts4_word fn_88565040();
ts4_word fn_88565118();
ts4_word fn_88569B08();
ts4_word ts4_tailcall_fn_88569A10_88569BD0();
ts4_word fn_8857A1E0();
ts4_word fn_88608088();
ts4_word fn_88608590();
ts4_word fn_8860DCF8();
ts4_word fn_88616758();
ts4_word fn_88616A70();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8862F0B8();
ts4_word fn_8864B268();
ts4_word fn_8864B468();
ts4_word fn_8864BBB0();
ts4_word ts4_if_call_seq_u32_off0_8864BC08();
ts4_word fn_8864C170();
ts4_word ts4_msg_pool_service_get_8864DFF0();
ts4_word fn_88823320();
ts4_word fn_88823FC0();
ts4_word fn_888240B8();
ts4_word fn_88824188();
ts4_word ts4_lua_opt_number_default_8882EA98();
ts4_word fn_88866B60();
ts4_word fn_88866C30();
ts4_word fn_88883CD0();
ts4_word fn_888860A0();
ts4_word fn_888892A8();
ts4_word fn_888D7FA8();
ts4_word fn_888F70A0();
ts4_word fn_88912090();
ts4_word fn_889122D8();
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0();
ts4_word ts4_call_seq_lbl_880D60F8_889298D8();
ts4_word fn_889333F0();
ts4_word ts4_call_seq_u32_off8_889343E8();
ts4_word fn_88934458();
ts4_word fn_88934B80();
ts4_word fn_88935C70();
ts4_word fn_88935D10();
ts4_word fn_88936BB0();
ts4_word fn_889375D8();
ts4_word fn_88937A00();
ts4_word fn_88937A88();
ts4_word fn_88938660();
ts4_word fn_88938F38();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_889396A8();
ts4_word fn_8893AFB0();
ts4_word ts4_loop_get_u32_off14_8893B080();
ts4_word fn_8893B3E0();
ts4_word fn_8893C990();
ts4_word fn_8893CCE8();
ts4_word fn_8893EA28();
ts4_word fn_8893EFD8();
ts4_word fn_88997D08();
ts4_word fn_889988E0();
ts4_word fn_889989A0();
ts4_word fn_88998B10();
ts4_word ts4_call_seq_lbl_880D2570_8899A0D8();
ts4_word fn_8899A3C0();
ts4_word fn_8899A9B8();
ts4_word ts4_get_u32_off0_8899AD88();
ts4_word fn_8899ADF8();
ts4_word ts4_if_call_seq_fn_8893CD70_8899B2E8();
ts4_word fn_8899B370();
ts4_word fn_8899B710();
ts4_word fn_8899CB48();
ts4_word fn_8899D518();
ts4_word fn_8899D750();
ts4_word fn_8899FA00();
ts4_word fn_8899FAE8();
ts4_word ts4_session_event_post_8899FE40();
ts4_word fn_889A00A8();
ts4_word ts4_get_u32_g_ts4_session_context_889A01E8();
ts4_word fn_889A0208();
ts4_word fn_889A0808();
ts4_word fn_889A1108();
ts4_word fn_889A12E8();
ts4_word fn_889A13B0();
ts4_word fn_889A14B0();
ts4_word fn_889A15A0();
ts4_word fn_889A16A8();
ts4_word fn_889A17C0();
ts4_word ts4_call_seq_fn_889375D8_889A3EF8();
ts4_word fn_889A4A28();
ts4_word fn_889A4E50();
ts4_word fn_889A4FD0();
ts4_word fn_889A7620();
ts4_word fn_889A7818();
ts4_word fn_889A7D38();
ts4_word fn_889ABE30();
ts4_word fn_889AC4B0();
ts4_word fn_889B0AD8();
ts4_word fn_889B11B0();
ts4_word fn_889B4418();
ts4_word fn_889B5A30();
ts4_word fn_889BAC88();
ts4_word fn_889BB7F0();
ts4_word fn_889BBD50();
ts4_word ts4_keyed_item_add_unique_889BCC28();
ts4_word ts4_keyed_item_add_unique_889BCCD8();
ts4_word ts4_if_call_seq_lbl_880C1324_889BCD88();
ts4_word fn_889BD910();
ts4_word fn_889BE668();
ts4_word ts4_if_call_seq_fn_889BD910_889BFAB8();
ts4_word ts4_if_call_seq_fn_889BD910_889BFB60();
ts4_word ts4_if_call_seq_fn_889BD910_889BFBD0();
ts4_word fn_889BFC40();
ts4_word fn_889BFDA8();
ts4_word fn_889C0298();
ts4_word ts4_if_call_seq_fn_889BD910_889C0778();
ts4_word fn_889C0878();
ts4_word ts4_keyed_item_add_or_remove_889C30B8();
ts4_word ts4_keyed_item_add_or_remove_889C5468();
ts4_word ts4_keyed_item_add_or_remove_889C5818();
ts4_word ts4_keyed_item_add_or_remove_889C5BC0();
ts4_word ts4_keyed_item_add_or_remove_889C5F18();
ts4_word fn_889C64C0();
ts4_word fn_889C6888();
ts4_word fn_889C8148();
ts4_word ts4_clear_intrusive_list();
ts4_word ts4_create_lobby_message();
ts4_word ts4_find_service();
ts4_word ts4_initialize_netdb_extended_record();
ts4_word ts4_memset();

/* Swing_DLL.xex 0x889A0458: tailcall ts4_get_u32_g_ts4_session_context_889A01E8 */
ts4_word ts4_tailcall_fn_889A01E8_889A0458(ts4_word a0)
{
    return ts4_get_u32_g_ts4_session_context_889A01E8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889B0A68: if_call_seq u32@0xc, fn_8860DCF8, ts4_call_seq_fn_889375D8_889A3EF8 */
ts4_word ts4_if_call_seq_u32_offc_889B0A68(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)136, (ts4_word)8, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_889375D8_889A3EF8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x889BCE18: call_seq ts4_if_call_seq_lbl_880C1324_889BCD88, fn_888D7FA8 */
ts4_word ts4_call_seq_fn_889BCD88_889BCE18(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_if_call_seq_lbl_880C1324_889BCD88();
    t2 = fn_888D7FA8((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x889C09C8: tailcall ts4_if_call_seq_fn_889BD910_889BFAB8 */
ts4_word ts4_tailcall_fn_889BFAB8_889C09C8(ts4_word a0)
{
    return ts4_if_call_seq_fn_889BD910_889BFAB8((ts4_word)a0);
}

