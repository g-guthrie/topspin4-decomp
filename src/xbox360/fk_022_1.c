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

extern char g_ts4_default_script_value[];
extern char g_ts4_session_context[];
extern char g_ts4_true_string[];
extern char g_ts4_tsu_notification_object[];
extern char lbl_880C95B6[];
extern char lbl_880C963A[];
extern char lbl_880C963B[];
extern char lbl_880D19F0[];
extern char lbl_880E3738[];
extern char lbl_880E3770[];
extern char lbl_880E39C8[];
extern char lbl_880E3A40[];
extern char lbl_880E3E14[];
extern char lbl_880E4A08[];
extern char lbl_880E4A18[];
extern char lbl_880E4A24[];
extern char lbl_880E4A34[];
extern char lbl_880E4A40[];
extern char lbl_880E4A50[];
extern char lbl_880E4B78[];
extern char lbl_880E4BA0[];
extern char lbl_880E4BF8[];
extern char lbl_880E4C8C[];
extern char lbl_880E4D04[];
extern char lbl_880E731C[];
extern char lbl_880EA35C[];
extern char lbl_880EA3C8[];
extern char lbl_880EA420[];
extern char lbl_880EA42C[];
extern char lbl_880EA4F0[];
extern char lbl_880EA510[];
extern char lbl_880EA52C[];
extern char lbl_880EA560[];
extern char lbl_880EA570[];
extern char lbl_880EA57C[];
extern char lbl_880EA60C[];
extern char lbl_880EA6C0[];
extern char lbl_880ED684[];
extern char lbl_880EF410[];
extern char lbl_880EF880[];
extern char lbl_880F799C[];
extern char lbl_88C6CBE8[];
extern char lbl_88D41F80[];
extern char lbl_88D45894[];
extern char lbl_88D45944[];
extern char lbl_88D45954[];
extern char lbl_88D459DC[];
extern char lbl_88D459E8[];
extern char lbl_88D459F8[];
extern char lbl_88D45A04[];
extern char lbl_88D45A08[];
extern char lbl_88D45A0C[];
extern char lbl_88D45A14[];
extern char lbl_88D45A24[];
extern char lbl_88D45A28[];
extern char lbl_88D45A4C[];
extern char lbl_88D45A60[];
extern char lbl_88D45A68[];
extern char lbl_88D45AD4[];
extern char lbl_88D45AF0[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B34[];
extern char lbl_88D45B38[];
ts4_word XNotifyPositionUI();
ts4_word fn_88150600();
ts4_word fn_8816D1A8();
ts4_word fn_881705B0();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_881878A0();
ts4_word ts4_if_call_seq_u32_off0_8819B0C8();
ts4_word ts4_call_seq_u32_off0_881B1A98();
ts4_word ts4_loop_call_seq_u32_off0_881B1B68();
ts4_word fn_881B1BF8();
ts4_word fn_881B4740();
ts4_word fn_881B47A8();
ts4_word fn_881B9148();
ts4_word ts4_null_handle_set_881BBE70();
ts4_word ts4_null_handle_set_ex_881BBED0();
ts4_word ts4_null_handle_set_881BBF38();
ts4_word ts4_null_handle_set_881BBF98();
ts4_word ts4_counted_ptr_assign_881C38D0();
ts4_word fn_881E68A0();
ts4_word fn_881F1060();
ts4_word ts4_if_call_seq_u32_off44_881F1130();
ts4_word fn_881F1990();
ts4_word fn_881F4D38();
ts4_word fn_88214378();
ts4_word fn_882196D8();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_88296528();
ts4_word ts4_if_atomic_interlocked_dec_88296E30();
ts4_word fn_883C6420();
ts4_word fn_8857A1E0();
ts4_word fn_8857A2A0();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word fn_8857BBB0();
ts4_word fn_8857BD30();
ts4_word fn_8857C8C8();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88616A70();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_8864A1E0();
ts4_word fn_886D7970();
ts4_word fn_886D7C28();
ts4_word ts4_loop_get_u32_off2c_88782188();
ts4_word fn_88790750();
ts4_word ts4_if_call_seq_u32_off50_88793A78();
ts4_word fn_88793F90();
ts4_word ts4_if_call_seq_u32_off70_887961A0();
ts4_word fn_88796240();
ts4_word ts4_if_call_seq_fn_88150600_88798080();
ts4_word fn_887A00B0();
ts4_word fn_887A1880();
ts4_word fn_887A23F8();
ts4_word fn_887AE1A0();
ts4_word fn_887AE3D0();
ts4_word ts4_if_get_u8_off1c1_887AE430();
ts4_word fn_887AF010();
ts4_word fn_887AF6A0();
ts4_word fn_887AF990();
ts4_word fn_887B1468();
ts4_word fn_887B37A8();
ts4_word fn_887B3BB0();
ts4_word fn_887B41E8();
ts4_word fn_887B43C0();
ts4_word fn_887B4598();
ts4_word fn_887B51D8();
ts4_word fn_887B6CB8();
ts4_word fn_887BBD10();
ts4_word fn_887BFBA0();
ts4_word fn_887C0AF0();
ts4_word fn_887C2798();
ts4_word fn_887C76D8();
ts4_word ts4_if_call_seq_u32_off0_887C7E70();
ts4_word fn_887C83B8();
ts4_word fn_887C9618();
ts4_word fn_887CF290();
ts4_word fn_887D02A8();
ts4_word fn_887D2960();
ts4_word fn_887D38F0();
ts4_word fn_887D3BB0();
ts4_word fn_887D3C88();
ts4_word fn_887D4460();
ts4_word ts4_if_call_seq_u32_off2d4_887D4D18();
ts4_word fn_887D6528();
ts4_word fn_887D73C0();
ts4_word fn_887D8170();
ts4_word fn_887D87C0();
ts4_word fn_887D9C90();
ts4_word fn_887DA038();
ts4_word fn_887DAC00();
ts4_word fn_887DACE0();
ts4_word fn_887DC1F0();
ts4_word fn_887DC2D0();
ts4_word fn_887DC338();
ts4_word fn_887DD098();
ts4_word fn_887DE6C0();
ts4_word fn_887E0540();
ts4_word fn_887E5700();
ts4_word fn_887E5D98();
ts4_word fn_887E6380();
ts4_word fn_887E6A50();
ts4_word fn_887E72E0();
ts4_word ts4_if_call_seq_u32_offa8_887E7EF0();
ts4_word fn_887E8F28();
ts4_word fn_887E9580();
ts4_word fn_887EB4A0();
ts4_word fn_887F20D0();
ts4_word fn_887F72B8();
ts4_word fn_887F9168();
ts4_word ts4_name_keys_register_887FB3B0();
ts4_word fn_887FFDB0();
ts4_word fn_887FFFB8();
ts4_word ts4_reltbl_index_of_e10_88800080();
ts4_word fn_88800BF8();
ts4_word fn_88800D40();
ts4_word ts4_reltbl_index_of_e10_88800E40();
ts4_word fn_88801428();
ts4_word fn_88837880();
ts4_word fn_8883F508();
ts4_word fn_88846890();
ts4_word fn_88847B38();
ts4_word fn_88847D88();
ts4_word fn_8884F638();
ts4_word fn_88850028();
ts4_word fn_888502F8();
ts4_word fn_888514B0();
ts4_word fn_88858208();
ts4_word fn_88863138();
ts4_word ts4_loop_get_u32_lbl_88D45B1C_88868008();
ts4_word fn_88883F38();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_888860A0();
ts4_word fn_88888668();
ts4_word fn_888C8CA0();
ts4_word fn_888CF860();
ts4_word fn_888D3780();
ts4_word fn_888EE0E8();
ts4_word fn_888F5BE8();
ts4_word fn_888F67B8();
ts4_word fn_8892AF80();
ts4_word fn_8892AFF0();
ts4_word fn_8895DA48();
ts4_word fn_8896BE28();
ts4_word fn_889A4AE0();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_clone_byte_with_object_context();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_keyed_item_list_add_unique_887C7F48();
ts4_word ts4_keyed_item_list_add_unique_887C81B8();
ts4_word ts4_keyed_item_list_add_unique_887CBC70();
ts4_word ts4_keyed_item_list_add_unique_887CBD90();
ts4_word ts4_keyed_item_list_add_unique_887CBEE0();
ts4_word ts4_keyed_item_list_add_unique_887EBA48();
ts4_word ts4_keyed_item_list_add_unique_887EBFC0();
ts4_word ts4_keyed_item_list_add_unique_887EC6F0();
ts4_word ts4_lookup_then_forward_88309210();
ts4_word ts4_object_finalize();
ts4_word ts4_script_string_equals();

/* Swing_DLL.xex 0x887AE498: if_call_seq u32@0x1b0, fn_881E68A0, u8@0x1f9, ts4_if_get_u8_off1c1_887AE430 */
ts4_word ts4_if_call_seq_u32_off1b0_887AE498(ts4_word a0)
{
    ts4_word p5;
    ts4_word t2;
    unsigned char t3;
    ts4_word t4;

    t2 = fn_881E68A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 432)));
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 505);
    p5 = (ts4_word)t2;
    if ((ts4_word)t3 == 0) {
        t4 = ts4_if_get_u8_off1c1_887AE430((ts4_word)a0);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x887C8490: call_seq fn_887C83B8, ts4_if_call_seq_u32_off0_887C7E70 */
ts4_word ts4_call_seq_fn_887C83B8_887C8490(ts4_word a0)
{
    ts4_word t2;

    fn_887C83B8((ts4_word)a0);
    t2 = ts4_if_call_seq_u32_off0_887C7E70((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x887C8578: call_seq lbl_880EA6C0, u32@0x0, fn_887C83B8, ts4_if_call_seq_u32_off0_887C7E70, lbl_880EA60C, u32@0x0 */
ts4_word ts4_call_seq_lbl_880EA6C0_887C8578(ts4_word a0)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA6C0;
    fn_887C83B8((ts4_word)(a0 + 28));
    ts4_if_call_seq_u32_off0_887C7E70((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA60C;
    t3 = fn_88617D28((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x887E7C80: if_call_seq u32@0x68, fn_887E72E0, u32@0x68, ts4_if_call_seq_u32_off2d4_887D4D18 */
ts4_word ts4_if_call_seq_u32_off68_887E7C80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((int)t1 != 7) {
        fn_887E72E0((ts4_word)a0, (ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)7;
    }
    t4 = ts4_if_call_seq_u32_off2d4_887D4D18((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887E7FC0: if_call_seq u32@0x1c, u32@0x54, u32@0x1c, u32@0x68, fn_887E72E0, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off1c_887E7FC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 104);
    if ((int)t3 != 7) {
        fn_887E72E0((ts4_word)t2, (ts4_word)t3, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)7;
    }
    t7 = ts4_if_call_seq_u32_off2d4_887D4D18((ts4_word)t2);
    return t7;
}

/* Swing_DLL.xex 0x887E8020: if_call_seq u32@0x1c, u32@0x54, u32@0x1c, u32@0x68, fn_887E72E0, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off1c_887E8020(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 104);
    if ((int)t3 != 7) {
        fn_887E72E0((ts4_word)t2, (ts4_word)t3, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)7;
    }
    t7 = ts4_if_call_seq_u32_off2d4_887D4D18((ts4_word)t2);
    return t7;
}

/* Swing_DLL.xex 0x887E8080: if_call_seq u32@0x1c, u32@0x54, u32@0x1c, u32@0x68, fn_887E72E0, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off1c_887E8080(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 104);
    if ((int)t3 != 7) {
        fn_887E72E0((ts4_word)t2, (ts4_word)t3, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)7;
    }
    t7 = ts4_if_call_seq_u32_off2d4_887D4D18((ts4_word)t2);
    return t7;
}

/* Swing_DLL.xex 0x887E8180: if_call_seq u32@0x1c, u32@0x54, u32@0x1c, u32@0x68, fn_887E72E0, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off1c_887E8180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 104);
    if ((int)t3 != 7) {
        fn_887E72E0((ts4_word)t2, (ts4_word)t3, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)7;
    }
    t7 = ts4_if_call_seq_u32_off2d4_887D4D18((ts4_word)t2);
    return t7;
}

