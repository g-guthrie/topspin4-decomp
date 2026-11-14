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
ts4_word fn_8819B0C8();
ts4_word fn_881B1A98();
ts4_word fn_881B1B68();
ts4_word fn_881B1BF8();
ts4_word fn_881B4740();
ts4_word fn_881B47A8();
ts4_word fn_881B9148();
ts4_word ts4_null_handle_set_881BBE70();
ts4_word ts4_null_handle_set_ex_881BBED0();
ts4_word ts4_null_handle_set_881BBF38();
ts4_word ts4_null_handle_set_881BBF98();
ts4_word fn_881C38D0();
ts4_word fn_881E68A0();
ts4_word fn_881F1060();
ts4_word fn_881F1130();
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
ts4_word fn_88782188();
ts4_word fn_88790750();
ts4_word fn_88793A78();
ts4_word fn_88793F90();
ts4_word fn_887961A0();
ts4_word fn_88796240();
ts4_word fn_88798080();
ts4_word fn_887A00B0();
ts4_word fn_887A1880();
ts4_word fn_887A23F8();
ts4_word fn_887AE1A0();
ts4_word fn_887AE3D0();
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
ts4_word fn_887C83B8();
ts4_word fn_887C9618();
ts4_word fn_887CF290();
ts4_word fn_887D02A8();
ts4_word fn_887D2960();
ts4_word fn_887D38F0();
ts4_word fn_887D3BB0();
ts4_word fn_887D3C88();
ts4_word fn_887D4460();
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
ts4_word fn_887E7EF0();
ts4_word fn_887E8F28();
ts4_word fn_887E9580();
ts4_word fn_887EB4A0();
ts4_word fn_887F20D0();
ts4_word fn_887F72B8();
ts4_word fn_887F9168();
ts4_word ts4_name_keys_register_887FB3B0();
ts4_word fn_887FFDB0();
ts4_word fn_887FFFB8();
ts4_word fn_88800080();
ts4_word fn_88800BF8();
ts4_word fn_88800D40();
ts4_word fn_88800E40();
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
ts4_word fn_88868008();
ts4_word fn_88883F38();
ts4_word fn_88884DE0();
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

/* Swing_DLL.xex 0x88786420: call_seq u32@lbl_88D45954, fn_888C8CA0 */
ts4_word ts4_call_seq_u32_lbl_88D45954_88786420(void)
{
    fn_888C8CA0((ts4_word)(*(ts4_word *)lbl_88D45954));
    return 0;
}

/* Swing_DLL.xex 0x887875C8: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_887875C8(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    t6 = ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    t8 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 28);
    if ((ts4_word)t8 != 0) {
        fn_889A4AE0((ts4_word)t8, (ts4_word)t6);
    }
    return 0;
}

/* Swing_DLL.xex 0x887897F8: call_seq ts4_find_service, fn_888D3780 */
ts4_word ts4_call_seq_ts4_find_service_887897F8(void)
{
    ts4_word t1;

    t1 = ts4_find_service((ts4_word)((1482358784) | 7434));
    fn_888D3780((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x88789BF8: call_seq u32@lbl_88D459DC, u32@lbl_88D45A04, fn_887EB4A0, ts4_object_finalize, u32@lbl_88D45A04, fn_887EB4A0 */
ts4_word ts4_call_seq_u32_lbl_88D459DC_88789BF8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D459DC;
    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(t1 + 68));
    ts4_object_finalize((ts4_word)(t1 + 68));
    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(t1 + 80));
    ts4_object_finalize((ts4_word)(t1 + 80));
    return 0;
}

/* Swing_DLL.xex 0x88789D88: call_seq u32@g_ts4_tsu_notification_object, fn_887D73C0 */
ts4_word ts4_call_seq_u32_g_ts4_tsu_notification_object_88789D88(void)
{
    fn_887D73C0((ts4_word)(*(ts4_word *)g_ts4_tsu_notification_object));
    return 0;
}

/* Swing_DLL.xex 0x88789DB8: call_seq ts4_find_service, fn_888CF860 */
ts4_word ts4_call_seq_ts4_find_service_88789DB8(void)
{
    ts4_word t1;

    t1 = ts4_find_service((ts4_word)((3816161280) | 31446));
    fn_888CF860((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x8878A240: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_8878A240(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8878A730: call_seq fn_88868008 */
ts4_word ts4_call_seq_fn_88868008_8878A730(void)
{
    fn_88868008();
    return 0;
}

/* Swing_DLL.xex 0x8878C9A0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8878C9A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8878EC10: if_call_seq u32@0x0, u32@0x4, fn_8862C0E8, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off0_8878EC10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        t3 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
        t4 = loc50[0];
        t5 = loc50[1];
        t6 = loc50[2];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t6;
        p9 = (ts4_word)t3;
    }
    return p9;
}

/* Swing_DLL.xex 0x887908A0: set u32@0x18, fn_88790750 */
ts4_word ts4_set_u32_off18_887908A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    return fn_88790750((ts4_word)a0);
}

/* Swing_DLL.xex 0x88790E78: addr fn_88883F38, lbl_880ED684, fn_8862BE08, u32@0x0, u32@0x28, vcall */
ts4_word ts4_addr_fn_88883F38_88790E78(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t1 = fn_88883F38();
    fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880ED684);
    t3 = loc50[0];
    t4 = loc50[1];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 40))))((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t4, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x88791950: if_call_seq ts4_find_service, fn_8864A1E0 */
ts4_word ts4_if_call_seq_ts4_find_service_88791950(void)
{
    ts4_word t1;

    t1 = ts4_find_service((ts4_word)((34340864) | 45033));
    if ((ts4_word)t1 != 0) {
        fn_8864A1E0((ts4_word)t1, (ts4_word)1, (ts4_word)((2298413056) | 49197), (ts4_word)((3933929472) | 44807));
    }
    return 0;
}

/* Swing_DLL.xex 0x88794048: if_call_seq u32@0x18, fn_88793F90, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_88794048(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    t1 = fn_88793F90();
    if ((ts4_word)(t1 & 0xff) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((2619080704) | 37749);
    }
    return t1;
}

/* Swing_DLL.xex 0x88794B28: if_call_seq u32@lbl_88D45894, fn_8895DA48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45894_88794B28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45894;
    if ((ts4_word)t1 != 0) {
        fn_8895DA48();
    }
    return 0;
}

/* Swing_DLL.xex 0x88795718: call_seq fn_88616A70, u32@0x20, u32@0x1c, fn_88214378, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_fn_88616A70_88795718(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    fn_88616A70((ts4_word)(a0 + 44));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    fn_88214378((ts4_word)(a0 + 28), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t5 = fn_881B9148((ts4_word)(a0 + 16));
    return t5;
}

/* Swing_DLL.xex 0x88795768: if_call_seq u32@0x110, u32@lbl_88D45A60, u32@0x1e4, fn_88793A78, u32@0x110, u32@0x110 */
ts4_word ts4_if_call_seq_u32_off110_88795768(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 272);
    if ((ts4_word)t1 == 0) {
        t4 = fn_88793A78((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 484)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)(t4 + 448);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 272));
}

/* Swing_DLL.xex 0x887963F0: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x24, u32@0x24, fn_88150600 */
ts4_word ts4_call_seq_fn_8819B0C8_887963F0(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    t4 = fn_88150600((ts4_word)(a0 + 40), (ts4_word)(a1 + 40));
    return t4;
}

/* Swing_DLL.xex 0x88796450: if_call_seq fn_88150600, fn_88150600, fn_881C38D0, u8@0x3c, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88150600_88796450(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p10;
    ts4_word t8;
    ts4_word t9;

    fn_88150600((ts4_word)(a0 + 20), (ts4_word)a1);
    fn_88150600((ts4_word)(a0 + 32), (ts4_word)a2);
    fn_881C38D0((ts4_word)(a0 + 44), (ts4_word)a3);
    *(unsigned char *)((char *)(ts4_word)(a0) + 60) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    t8 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    p10 = (ts4_word)t8;
    if ((ts4_word)t8 != 0) {
        t9 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x887975D8: set u8@0x82, u32@0x70, fn_887961A0 */
ts4_word ts4_set_u8_off82_887975D8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 130) = (unsigned char)a1;
    return fn_887961A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 112)), (ts4_word)1);
}

/* Swing_DLL.xex 0x88798288: call_seq u32@0x0, ts4_assign_formatted_text, fn_88798080, ts4_destroy_owned_object */
ts4_word ts4_call_seq_u32_off0_88798288(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    fn_88798080((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[0];
    t5 = ts4_destroy_owned_object((ts4_word)t4);
    return t5;
}

/* Swing_DLL.xex 0x8879A2B0: if_call_seq u32@0x18, ts4_find_service, fn_888F5BE8, u32@0x20, u32@lbl_88D45B34, fn_888F67B8 */
ts4_word ts4_if_call_seq_u32_off18_8879A2B0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    t1 = ts4_find_service((ts4_word)((279773184) | 64090));
    fn_888F5BE8((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t5 = fn_888F67B8((ts4_word)t3, (ts4_word)(*(ts4_word *)lbl_88D45B34));
    if ((ts4_word)(t5 & 0xff) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((2619080704) | 37749);
    }
    return t5;
}

/* Swing_DLL.xex 0x8879B418: if_call_seq u32@lbl_88D45894, u32@lbl_88D45B1C, u32@lbl_88D45944, u32@0x27c, fn_888EE0E8, u32@lbl_88D45894 */
ts4_word ts4_if_call_seq_u32_lbl_88D45894_8879B418(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45894;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)lbl_88D45B1C;
        t3 = *(ts4_word *)lbl_88D45944;
        fn_888EE0E8((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 636)));
        fn_8896BE28((ts4_word)(*(ts4_word *)lbl_88D45894));
    }
    return 0;
}

/* Swing_DLL.xex 0x8879C198: if_call_seq lbl_880EF880, u32@0x0, fn_88616A70, u32@0x40, u32@lbl_88D45A68, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880EF880_8879C198(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF880;
    fn_88616A70((ts4_word)(a0 + 44));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    *(ts4_word *)lbl_88D45A68 = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    fn_882196D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t5);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    t11 = fn_88617D28((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x887A1950: call_seq fn_881F1990, fn_88796240, fn_887A1880, fn_88150600, fn_88150600, u32@0x70 */
ts4_word ts4_call_seq_fn_881F1990_887A1950(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    fn_881F1990();
    fn_88796240((ts4_word)a0);
    fn_887A1880((ts4_word)a0);
    fn_88150600((ts4_word)(a0 + 88), (ts4_word)(a1 + 88));
    t5 = fn_88150600((ts4_word)(a0 + 100), (ts4_word)(a1 + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    *(unsigned char *)((char *)(ts4_word)(a0) + 128) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 128));
    *(unsigned char *)((char *)(ts4_word)(a0) + 129) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 129));
    *(unsigned char *)((char *)(ts4_word)(a0) + 130) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 130));
    *(unsigned char *)((char *)(ts4_word)(a0) + 131) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 131));
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 132));
    return t5;
}

/* Swing_DLL.xex 0x887A2C80: if_call_seq u32@0x18, fn_88782188, fn_887A23F8 */
ts4_word ts4_if_call_seq_u32_off18_887A2C80(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    t1 = fn_88782188((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((ts4_word)(t1 & 0xff) == 1) {
        t2 = fn_887A23F8((ts4_word)a0);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x887A5E08: call_seq ts4_get_u32__imp_KeTimeStampBundle_8857B830, fn_881B1A98 */
ts4_word ts4_call_seq_fn_8857B830_887A5E08(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;

    t1 = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    fn_881B1A98((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)t1);
    return 1;
}

/* Swing_DLL.xex 0x887AACA8: call_seq u32@lbl_88D45A60, u32@0x94, fn_881B1BF8 */
ts4_word ts4_call_seq_u32_lbl_88D45A60_887AACA8(ts4_word a0)
{
    ts4_word loc50[1];

    fn_881B1BF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 148)));
    return 1;
}

/* Swing_DLL.xex 0x887AAF88: call_seq u32@lbl_88D45A60, u32@0x90, fn_881B1B68 */
ts4_word ts4_call_seq_u32_lbl_88D45A60_887AAF88(ts4_word a0)
{
    ts4_word loc50[1];

    fn_881B1B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 144)));
    return 1;
}

/* Swing_DLL.xex 0x887AAFC0: call_seq u32@lbl_88D45A60, u32@0x88, fn_881B1B68 */
ts4_word ts4_call_seq_u32_lbl_88D45A60_887AAFC0(ts4_word a0)
{
    ts4_word loc50[1];

    fn_881B1B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 136)));
    return 1;
}

/* Swing_DLL.xex 0x887AAFF8: call_seq u32@lbl_88D45A60, u32@0x8c, fn_881B1B68 */
ts4_word ts4_call_seq_u32_lbl_88D45A60_887AAFF8(ts4_word a0)
{
    ts4_word loc50[1];

    fn_881B1B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 140)));
    return 1;
}

/* Swing_DLL.xex 0x887AB030: call_seq u32@lbl_88D45A60, u32@0x84, fn_881B1B68 */
ts4_word ts4_call_seq_u32_lbl_88D45A60_887AB030(ts4_word a0)
{
    ts4_word loc50[1];

    fn_881B1B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 132)));
    return 1;
}

/* Swing_DLL.xex 0x887ABB18: call_seq fn_88837880 */
ts4_word ts4_call_seq_fn_88837880_887ABB18(ts4_word a0, ts4_word a1)
{
    fn_88837880((ts4_word)a0, (ts4_word)(a1 + 112));
    return a0;
}

/* Swing_DLL.xex 0x887AE430: if_get u8@0x1c1, fn_887A00B0, u32@lbl_88D41F80, u32@0x0, u32@0xf8, vcall */
ts4_word ts4_if_get_u8_off1c1_887AE430(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    unsigned char t1;
    ts4_word t4;
    ts4_word t7;
    unsigned char t8;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 449);
    if ((ts4_word)t1 == 1) {
        fn_887A00B0((ts4_word)a0);
    }
    t4 = *(ts4_word *)lbl_88D41F80;
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 248))))((ts4_word)t4);
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 449);
    p10 = (ts4_word)t7;
    if ((ts4_word)t8 == 1) {
        t9 = fn_887AE3D0((ts4_word)a0);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x887B53B0: call_seq fn_881F4D38 */
ts4_word ts4_call_seq_fn_881F4D38_887B53B0(void)
{
    fn_881F4D38();
    return 1;
}

/* Swing_DLL.xex 0x887B5C98: call_seq lbl_880EF410, u32@0x0, fn_88796240, fn_887A1880, u32@0x88, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880EF410_887B5C98(ts4_word a0)
{
    ts4_word t9;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF410;
    fn_88796240((ts4_word)a0);
    fn_887A1880((ts4_word)a0);
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 136)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)));
    t9 = fn_881F1130((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x887B5CF8: call_seq fn_881F1060, lbl_880EF410, u32@0x48, u32@0x0, u32@0x4c, u32@0x54 */
ts4_word ts4_call_seq_fn_881F1060_887B5CF8(ts4_word a0)
{
    ts4_word t4;

    fn_881F1060((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF410;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(a0 + 88));
    fn_8816D1A8((ts4_word)(a0 + 100));
    t4 = *(ts4_word *)lbl_88C6CBE8;
    *(unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)t4;
    *(unsigned char *)((char *)(ts4_word)(a0) + 128) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 129) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 130) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 131) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 133) = (unsigned char)0;
    fn_8816D1A8((ts4_word)(a0 + 136));
    *(unsigned char *)((char *)(ts4_word)(a0) + 148) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x887B5DB0: call_seq fn_881F4D38 */
ts4_word ts4_call_seq_fn_881F4D38_887B5DB0(void)
{
    fn_881F4D38();
    return 1;
}

/* Swing_DLL.xex 0x887B5EB0: if_call_seq lbl_88D459E8, u32@0x10, u32@lbl_88D459E8, fn_88858208, u32@0x0, fn_88846890 */
ts4_word ts4_if_call_seq_lbl_88D459E8_887B5EB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t12;
    ts4_word t23;
    ts4_word t24;

    if ((ts4_word)(a1 & 0xff) != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        fn_88858208((ts4_word)(*(ts4_word *)lbl_88D459E8), (ts4_word)t1, (ts4_word)0, (ts4_word)0);
        fn_88846890((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0)));
    } else {
        fn_8883F508((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 52)), (ts4_word)((3498704896) | 54255), (ts4_word)0);
    }
    fn_88847B38((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0)));
    t12 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0);
    fn_88863138((ts4_word)t12, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    fn_8884F638((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0)));
    fn_888502F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0)));
    fn_88847D88((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0)));
    fn_88850028((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D459E8) + 0)), (ts4_word)0);
    t23 = fn_887AE1A0((ts4_word)a0);
    t24 = fn_888514B0((ts4_word)t23);
    return t24;
}

/* Swing_DLL.xex 0x887C3F10: call_seq fn_887C2798, fn_887C0AF0, fn_887BFBA0, fn_887B1468, fn_887B4598, fn_887AF990 */
ts4_word ts4_call_seq_fn_887C2798_887C3F10(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;

    t1 = fn_887C2798();
    t2 = fn_887C0AF0((ts4_word)t1);
    t3 = fn_887BFBA0((ts4_word)t2);
    t4 = fn_887B1468((ts4_word)t3);
    t5 = fn_887B4598((ts4_word)t4);
    t6 = fn_887AF990((ts4_word)t5);
    t7 = fn_887B43C0((ts4_word)t6);
    t8 = fn_887BBD10((ts4_word)t7);
    t9 = fn_887AF010((ts4_word)t8);
    t10 = fn_887B6CB8((ts4_word)t9);
    t11 = fn_887AF6A0((ts4_word)t10);
    t12 = fn_887B41E8((ts4_word)t11);
    t13 = fn_887B51D8((ts4_word)t12);
    t14 = fn_887B37A8((ts4_word)t13);
    t15 = fn_887B3BB0((ts4_word)t14);
    return t15;
}

/* Swing_DLL.xex 0x887C7660: fn  */
ts4_word ts4_fn_887C7660(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887C7770: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_887C7770(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887C78B0: get u32@0x3b8, vcall, u32@0x0 */
ts4_word ts4_get_u32_off3b8_887C78B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 952))))((ts4_word)a0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x887C7928: if_call_seq u8@0x70, u8@0x71, XNotifyPositionUI */
ts4_word ts4_if_call_seq_u8_off70_887C7928(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 113) = (unsigned char)1;
    XNotifyPositionUI((ts4_word)6);
    return 1;
}

/* Swing_DLL.xex 0x887C7980: call_seq u8@0x71, XNotifyPositionUI */
ts4_word ts4_call_seq_u8_off71_887C7980(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 113) = (unsigned char)0;
    XNotifyPositionUI((ts4_word)2);
    return 1;
}

/* Swing_DLL.xex 0x887C7AB8: tailcall fn_88884DE0 */
ts4_word ts4_tailcall_fn_88884DE0_887C7AB8(ts4_word a0)
{
    return fn_88884DE0((ts4_word)a0, (ts4_word)(2155872256));
}

/* Swing_DLL.xex 0x887C7E70: if_call_seq u32@0x0, fn_888860A0, u32@0x8, u32@0x0, u32@0x4, fn_88884DE0 */
ts4_word ts4_if_call_seq_u32_off0_887C7E70(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_88884DE0((ts4_word)t3, (ts4_word)(2155872256));
        p5 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return p5;
}

/* Swing_DLL.xex 0x887C8268: call_seq lbl_880EA4F0, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_887C7F48, lbl_880EA510, fn_88608590 */
ts4_word ts4_call_seq_lbl_880EA4F0_887C8268(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t18;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EA4F0);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_887C7F48((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EA510);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_887C7F48((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EA52C);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_887C7F48((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EA560);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_887C81B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EA570);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_887C81B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EA57C);
    loc50[0] = (ts4_word)t16;
    t18 = ts4_keyed_item_list_add_unique_887C81B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t18;
}

/* Swing_DLL.xex 0x887C8518: get u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall, u8@0xc8, fn_887C83B8 */
ts4_word ts4_get_u32_lbl_88D45A4C_887C8518(ts4_word a0)
{
    ts4_word t1;
    ts4_word t8;

    t1 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 4))))((ts4_word)(t1 + 340));
    *(unsigned char *)((char *)(ts4_word)(a0) + 200) = (unsigned char)0;
    fn_887C83B8((ts4_word)(a0 + 28));
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 8))))((ts4_word)(t1 + 340));
    return t8;
}

/* Swing_DLL.xex 0x887C8680: tailcall fn_88888668 */
ts4_word ts4_tailcall_fn_88888668_887C8680(ts4_word a0)
{
    return fn_88888668((ts4_word)a0, (ts4_word)(3162505216));
}

/* Swing_DLL.xex 0x887C9978: if_call_seq lbl_880EA42C, fn_887C76D8, lbl_880EA420, fn_887C76D8, u32@0xa8, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880EA42C_887C9978(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_887C76D8((ts4_word)a0, (ts4_word)(ts4_word)lbl_880EA42C);
    t2 = fn_887C76D8((ts4_word)a0, (ts4_word)(ts4_word)lbl_880EA420);
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)t1;
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 == 5) {
        t4 = fn_887C9618((ts4_word)a0, (ts4_word)t2);
        p5 = (ts4_word)t4;
    } else {
        p5 = (ts4_word)((2147483648) | 16389);
    }
    return p5;
}

/* Swing_DLL.xex 0x887CAC58: if_call_seq u32@0x10c, ts4_if_atomic_interlocked_dec_88288530, u32@0x10c, u32@0x108, ts4_if_atomic_interlocked_dec_88288530, u32@0x108 */
ts4_word ts4_if_call_seq_u32_off10c_887CAC58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 268);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_88288530((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 10888);
    p10 = (ts4_word)p6;
    if ((ts4_word)t8 != 0) {
        t9 = fn_8857C8C8((ts4_word)p6);
        p10 = (ts4_word)t9;
    }
    t11 = fn_8857C8C8((ts4_word)p10);
    *(ts4_word *)((char *)(ts4_word)(t7) + 10888) = (ts4_word)t11;
    t13 = ts4_if_atomic_interlocked_dec_88296E30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 276)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    return t13;
}

/* Swing_DLL.xex 0x887CAE10: call_seq fn_881878A0, u32@0x114, fn_88296528, fn_881878A0 */
ts4_word ts4_call_seq_fn_881878A0_887CAE10(ts4_word a0)
{
    ts4_word t4;

    fn_881878A0((ts4_word)(a0 + 36));
    fn_88296528((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 276)));
    t4 = fn_881878A0((ts4_word)(a0 + 52));
    return t4;
}

/* Swing_DLL.xex 0x887CB4F8: fn  */
ts4_word ts4_fn_887CB4F8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CB500: fn  */
ts4_word ts4_fn_887CB500(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CB508: fn  */
ts4_word ts4_fn_887CB508(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CB510: if_tailcall fn_8857A2A0 */
ts4_word ts4_if_tailcall_fn_8857A2A0_887CB510(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    if ((ts4_word)a2 > 3) {
        return a2;
    }
    return fn_8857A2A0((ts4_word)a2, (ts4_word)((0) | 32769), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x887CB5E0: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_887CB5E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x887CB5F8: set u32@0x0 */
void ts4_set_u32_off0_887CB5F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887CB608: set u32@0x0 */
void ts4_set_u32_off0_887CB608(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887CB6F0: call_seq u32@0x14, fn_8857BD30 */
ts4_word ts4_call_seq_u32_off14_887CB6F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    loc50[0] = (ts4_word)0;
    fn_8857BD30((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t3 = loc50[0];
    return t3;
}

/* Swing_DLL.xex 0x887CB728: call_seq u32@0x14, fn_8857BBB0 */
ts4_word ts4_call_seq_u32_off14_887CB728(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    loc50[0] = (ts4_word)0;
    fn_8857BBB0((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t3 = loc50[0];
    return t3;
}

/* Swing_DLL.xex 0x887CB760: if_call_seq u32@0x14, lbl_880EA35C, u32@0x0, fn_8857A1E0, lbl_880F799C, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off14_887CB760(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA35C;
    p3 = (ts4_word)t1;
    if ((int)t1 != -1) {
        t2 = fn_8857A1E0((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F799C;
    return p3;
}

/* Swing_DLL.xex 0x887CBD40: call_seq fn_88617D88, lbl_880EA3C8, u32@0x0, u32@0x1c, u32@lbl_88D45A08 */
ts4_word ts4_call_seq_fn_88617D88_887CBD40(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA3C8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)lbl_88D45A08 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x887CD7E8: call_seq u32@0x20, fn_883C6420, u32@0x20, u32@0x1c */
ts4_word ts4_call_seq_u32_off20_887CD7E8(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_883C6420((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x887CD8A8: if_call_seq u32@lbl_88D45A28, u32@0x1c, ts4_lookup_then_forward_88309210 */
ts4_word ts4_if_call_seq_u32_lbl_88D45A28_887CD8A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    loc50[0] = (ts4_word)0;
    t1 = *(ts4_word *)lbl_88D45A28;
    p5 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        ts4_lookup_then_forward_88309210((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 28)), (ts4_word)(ts4_word)&loc50[0]);
        t4 = loc50[0];
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x887CD910: call_seq fn_88617D88, lbl_880E731C, u32@0x20, u32@0x0, u32@0x1c, u32@lbl_88D45A28 */
ts4_word ts4_call_seq_fn_88617D88_887CD910(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E731C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)lbl_88D45A28 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x887CD960: fn  */
ts4_word ts4_fn_887CD960(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CD968: fn  */
ts4_word ts4_fn_887CD968(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CD970: fn  */
ts4_word ts4_fn_887CD970(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CD978: fn  */
ts4_word ts4_fn_887CD978(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CD980: fn  */
ts4_word ts4_fn_887CD980(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CD988: fn  */
ts4_word ts4_fn_887CD988(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887CD9E8: fn  */
ts4_word ts4_fn_887CD9E8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887CDA38: fn  */
ts4_word ts4_fn_887CDA38(ts4_word a0, ts4_word a1)
{
    return (((a1 << 4) + a0) + 4);
}

/* Swing_DLL.xex 0x887CDA50: fn  */
ts4_word ts4_fn_887CDA50(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887CDA58: set u32@0x0 */
void ts4_set_u32_off0_887CDA58(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887CDBA0: set u32@0x48 */
void ts4_set_u32_off48_887CDBA0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x887CDBA8: set u32@0xa0, u32@0xa4 */
void ts4_set_u32_offa0_887CDBA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887CDBF8: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_887CDBF8(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x887CDC00: get u32@0x0 */
ts4_word ts4_get_u32_off0_887CDC00(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x887CDCF8: get u32@0x2c, u32@0x368 */
ts4_word ts4_get_u32_off2c_887CDCF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 872));
}

/* Swing_DLL.xex 0x887CE3E8: get u32@0x38, u32@0x2c */
ts4_word ts4_get_u32_off38_887CE3E8(ts4_word a0)
{
    return ((((4060217344) | 47881) - (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 44))) == 0);
}

/* Swing_DLL.xex 0x887CE458: get u32@0x38, u32@0x2c */
ts4_word ts4_get_u32_off38_887CE458(ts4_word a0)
{
    return ((((4148690944) | 24223) - (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 44))) == 0);
}

/* Swing_DLL.xex 0x887CE688: fn  */
ts4_word ts4_fn_887CE688(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887CE7C8: get u8@0x0, u32@lbl_88D45AD4, u32@0x54, u8@0x34 */
ts4_word ts4_get_u8_off0_887CE7C8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 84))) + 52) = (unsigned char)t1;
    return 1;
}

/* Swing_DLL.xex 0x887CEA00: if_get u8@0x95, u8@0x95, u32@0x2c, u8@0x55, u8@0x55, u8@0x100 */
void ts4_if_get_u8_off95_887CEA00(ts4_word a0, ts4_word a1)
{
    unsigned char t1;
    ts4_word t2;
    unsigned char t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 149);
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(a1) + 149) = (unsigned char)0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 44);
    if ((ts4_word)t2 == 0) {
        return;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 85);
    if ((ts4_word)t3 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(t2) + 85) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t2) + 256) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t2) + 258) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t2) + 90) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t2) + 91) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t2) + 95) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 852) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887CEA50: if_get u8@0x125, u32@0x58, u32@0x11c, u8@0xe6, u8@0x125 */
void ts4_if_get_u8_off125_887CEA50(ts4_word a0)
{
    unsigned char t1;
    ts4_word t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 293);
    if ((ts4_word)t1 != 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((int)t2 != 1) {
        if ((int)t2 != 2) {
            return;
        }
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 293) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284))) + 230));
    return;
}

/* Swing_DLL.xex 0x887CEBC0: if_get u32@0xa8, u8@0x24b, u32@0xa4, u32@0x230, u32@0x18 */
ts4_word ts4_if_get_u32_offa8_887CEBC0(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 587);
    if ((ts4_word)t2 != 0) {
        return t2;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 560);
    return ((t4 - (*(ts4_word *)((char *)(ts4_word)(t3) + 24))) == 0);
}

/* Swing_DLL.xex 0x887CEC58: if_get u8@0x31d, u8@0x31e */
ts4_word ts4_if_get_u8_off31d_887CEC58(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 1) {
        return (*(unsigned char *)((char *)(ts4_word)(a0) + 797));
    }
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 798));
}

/* Swing_DLL.xex 0x887CEED8: if_get u32@0x58 */
ts4_word ts4_if_get_u32_off58_887CEED8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((int)t1 != 5) {
        return ((t1 + -4) != 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x887CF180: fn  */
ts4_word ts4_fn_887CF180(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887CF3B0: if_get u32@0x60, u32@0x4, u32@0x4, u32@0x60 */
ts4_word ts4_if_get_u32_off60_887CF3B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 == 0) {
        return 0;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 96);
    t2 = *(ts4_word *)((char *)(ts4_word)(((t1 << 4) + a0)) + 4);
    if ((ts4_word)t2 == 0) {
        *(ts4_word *)((char *)(ts4_word)(((t1 << 4) + a0)) + 4) = (ts4_word)a1;
    }
    return ((((*(ts4_word *)((char *)(ts4_word)(a1) + 96)) << 4) + a0) + 4);
}

/* Swing_DLL.xex 0x887D0450: set u32@0x9c, u32@0x44, u32@0x48, u32@0x3c */
void ts4_set_u32_off9c_887D0450(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887D06C0: fn  */
ts4_word ts4_fn_887D06C0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887D0760: set u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x18 */
void ts4_set_u32_off4_887D0760(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887D2A98: call_seq u32@0x24, fn_887D2960, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_u32_off24_887D2A98(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    fn_887D2960((ts4_word)a0, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x887D3288: if_call_seq u32@lbl_88D45A24, u8@0x1b4, fn_887D2960 */
ts4_word ts4_if_call_seq_u32_lbl_88D45A24_887D3288(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88D45A24;
    if ((ts4_word)t1 != 0) {
        fn_887D2960((ts4_word)t1, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 436)));
    }
    return 1;
}

/* Swing_DLL.xex 0x887D4C08: if_call_seq u32@0x0, ts4_find_service, fn_887FFDB0 */
ts4_word ts4_if_call_seq_u32_off0_887D4C08(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = fn_887FFDB0((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x887D4D18: if_call_seq u32@0x2d4, u32@0x2d0, u32@0x2ec, u32@0x2f0, u32@0x2f4, lbl_880C95B6 */
ts4_word ts4_if_call_seq_u32_off2d4_887D4D18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p13;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 724);
    p13 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 720);
        p7 = (ts4_word)a0;
        if ((ts4_word)t1 == (ts4_word)t2) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 748);
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 752);
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 756);
            loc50[0] = (ts4_word)t3;
            loc50[1] = (ts4_word)t4;
            loc50[2] = (ts4_word)t5;
            t6 = ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C95B6);
            p7 = (ts4_word)t6;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 724);
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 260))) + 452) = (ts4_word)t8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 720) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 724));
        *(ts4_word *)((char *)(ts4_word)(a0) + 724) = (ts4_word)0;
        p13 = (ts4_word)p7;
    }
    return p13;
}

/* Swing_DLL.xex 0x887D50A8: call_seq u32@0x18, u32@0x1c, u32@0x20, fn_887CF290 */
ts4_word ts4_call_seq_u32_off18_887D50A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    fn_887CF290((ts4_word)a0, (ts4_word)0);
    return a0;
}

/* Swing_DLL.xex 0x887D5108: set u32@0x4, u32@0x8, u32@0xc, u32@0x0 */
void ts4_set_u32_off4_887D5108(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887D7F40: if_call_seq fn_887D3BB0, fn_887D38F0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_fn_887D3BB0_887D7F40(ts4_word a0)
{
    ts4_word loc50[3];
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_887D3BB0((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_887D38F0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t3 = loc50[0];
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    return t2;
}

/* Swing_DLL.xex 0x887D94D0: call_seq fn_887D87C0, fn_887D8170 */
ts4_word ts4_call_seq_fn_887D87C0_887D94D0(ts4_word a0)
{
    ts4_word t2;

    fn_887D87C0();
    t2 = fn_887D8170((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x887D9C70: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u8@0x10 */
void ts4_set_u32_off0_887D9C70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x887DA128: call_seq fn_887DA038, u32@0x54 */
ts4_word ts4_call_seq_fn_887DA038_887DA128(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_887DA038();
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x887DA380: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_887DA380(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887DA740: call_seq u32@g_ts4_tsu_notification_object, fn_887D87C0, fn_887D8170 */
ts4_word ts4_call_seq_u32_g_ts4_tsu_notification_object_887DA740(void)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)g_ts4_tsu_notification_object;
    fn_887D87C0((ts4_word)t1);
    t3 = fn_887D8170((ts4_word)t1);
    return t3;
}

/* Swing_DLL.xex 0x887DB670: if_call_seq fn_887DAC00, fn_887DAC00 */
ts4_word ts4_if_call_seq_fn_887DAC00_887DB670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        fn_887DAC00();
        p2 = (ts4_word)a1;
    }
    t3 = fn_887DAC00((ts4_word)p2);
    return t3;
}

/* Swing_DLL.xex 0x887DB6B0: if_call_seq fn_887DACE0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_fn_887DACE0_887DB6B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_887DACE0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t2 = loc50[0];
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    return t1;
}

/* Swing_DLL.xex 0x887DCD78: tailcall ts4_null_handle_set_881BBF98 */
ts4_word ts4_tailcall_fn_881BBF98_887DCD78(ts4_word a0)
{
    return ts4_null_handle_set_881BBF98((ts4_word)a0, (ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x887DCD80: tailcall ts4_null_handle_set_ex_881BBED0 */
ts4_word ts4_tailcall_fn_881BBED0_887DCD80(ts4_word a0)
{
    return ts4_null_handle_set_ex_881BBED0((ts4_word)a0, (ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x887DCD88: tailcall ts4_null_handle_set_881BBE70 */
ts4_word ts4_tailcall_fn_881BBE70_887DCD88(ts4_word a0)
{
    return ts4_null_handle_set_881BBE70((ts4_word)a0, (ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x887DED68: tailcall ts4_null_handle_set_881BBF38 */
ts4_word ts4_tailcall_fn_881BBF38_887DED68(ts4_word a0)
{
    return ts4_null_handle_set_881BBF38((ts4_word)a0, (ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x887DED70: tailcall ts4_null_handle_set_ex_881BBED0 */
ts4_word ts4_tailcall_fn_881BBED0_887DED70(ts4_word a0)
{
    return ts4_null_handle_set_ex_881BBED0((ts4_word)a0, (ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x887DED78: if_call_seq u32@0x0, u32@0xfc, fn_887D6528, fn_887D6528, fn_887DD098 */
ts4_word ts4_if_call_seq_u32_off0_887DED78(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
    if ((ts4_word)t1 == (ts4_word)((799539200) | 34051)) {
        fn_887D6528((ts4_word)t2, (ts4_word)1);
        p6 = (ts4_word)1;
    } else {
        fn_887D6528((ts4_word)t2, (ts4_word)0);
        p6 = (ts4_word)0;
    }
    fn_887DD098((ts4_word)a0, (ts4_word)p6);
    return 1;
}

/* Swing_DLL.xex 0x887E04B0: call_seq fn_887DE6C0, fn_887D3C88, fn_887D02A8 */
ts4_word ts4_call_seq_fn_887DE6C0_887E04B0(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    loc54[0] = (ts4_word)-1;
    loc50[0] = (ts4_word)-1;
    loc58[0] = (ts4_word)-1;
    fn_887DE6C0((ts4_word)a0, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_887D3C88((ts4_word)a0, (ts4_word)(a0 + 256));
    t3 = loc50[0];
    t4 = loc54[0];
    t5 = loc58[0];
    t6 = fn_887D02A8((ts4_word)a0, (ts4_word)t5, (ts4_word)t4, (ts4_word)t3, (ts4_word)t4, (ts4_word)t3);
    return t6;
}

/* Swing_DLL.xex 0x887E2238: if_call_seq u32@0x8, u8@0x4, fn_887E0540, u8@0xc, fn_887DC1F0, fn_887DC338 */
ts4_word ts4_if_call_seq_u32_off8_887E2238(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    unsigned char t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    fn_887E0540((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 4)), (ts4_word)t1);
    t4 = *(unsigned char *)((char *)(ts4_word)(a1) + 12);
    if ((ts4_word)t4 != 0) {
        fn_887DC1F0((ts4_word)a0);
        fn_887DC338((ts4_word)a0);
        fn_887DC2D0((ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 774) = (unsigned char)1;
    }
    return 1;
}

/* Swing_DLL.xex 0x887E6218: if_call_seq u8@0x0, fn_887E5700, u32@lbl_88D45A14, u32@lbl_88D45AF0, u32@0x54, fn_886D7C28 */
ts4_word ts4_if_call_seq_u8_off0_887E6218(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    unsigned char t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    unsigned char t9;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        fn_887E5700((ts4_word)a0);
    }
    t4 = *(ts4_word *)lbl_88D45A14;
    t5 = *(ts4_word *)lbl_88D45AF0;
    fn_886D7C28((ts4_word)t5, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 84)) + 500));
    t8 = *(ts4_word *)lbl_88D45AF0;
    t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 68);
    p11 = (ts4_word)t8;
    if ((ts4_word)t9 != 0) {
        t10 = fn_886D7970((ts4_word)t8);
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x887E6280: call_seq fn_887E5D98 */
ts4_word ts4_call_seq_fn_887E5D98_887E6280(void)
{
    fn_887E5D98();
    return 1;
}

/* Swing_DLL.xex 0x887E6438: call_seq fn_887D9C90, fn_887E6380 */
ts4_word ts4_call_seq_fn_887D9C90_887E6438(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_887D9C90((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t2 = fn_887E6380((ts4_word)(a0 + 88), (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x887E80E0: if_get u32@0x1c, u32@0x54, u32@0x1c, u32@0x50, u32@0x1c, fn_887E6A50 */
ts4_word ts4_if_get_u32_off1c_887E80E0(ts4_word a0)
{
    ts4_word p7;
    ts4_word t5;
    ts4_word t6;
    ts4_word t10;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 80) = (ts4_word)1;
    fn_887E6A50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 88);
    if ((int)t6 != 5) {
        p7 = (ts4_word)((t6 + -4) != 0);
    } else {
        p7 = (ts4_word)0;
    }
    if ((ts4_word)(p7 & 0xff) != 0) {
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 8))))((ts4_word)t5);
        return t10;
    }
    t11 = fn_887E7EF0((ts4_word)t5);
    return t11;
}

/* Swing_DLL.xex 0x887E8FB0: if_call_seq u32@0xa0, u32@0xa4, fn_887E8F28, fn_887D4460 */
ts4_word ts4_if_call_seq_u32_offa0_887E8FB0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 160);
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    t2 = fn_887E8F28((ts4_word)a0, (ts4_word)t1);
    if ((ts4_word)(t2 & 0xff) != 0) {
        fn_887D4460((ts4_word)a0);
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x887E93B8: set u32@0xc, u32@0x4 */
void ts4_set_u32_offc_887E93B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x887E93C8: set u32@0x4 */
void ts4_set_u32_off4_887E93C8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 12) = f1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x887E93D8: set u32@0xc, u32@0x4 */
void ts4_set_u32_offc_887E93D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887E93E8: set u32@0x0, u32@0x4, u32@0xc */
void ts4_set_u32_off0_887E93E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887E9448: fn  */
ts4_word ts4_fn_887E9448(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887E9450: fn  */
ts4_word ts4_fn_887E9450(void)
{
    return 2;
}

/* Swing_DLL.xex 0x887E9458: fn  */
ts4_word ts4_fn_887E9458(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887E9568: get u32@0x2b0, u32@0x30 */
ts4_word ts4_get_u32_off2b0_887E9568(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 688))) + 48))))((ts4_word)(a0 + 688), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x887E9E28: if_get u32@0x2b0, u32@0x30, vcall, ts4_find_service, u32@0x0, u32@0x44 */
ts4_word ts4_if_get_u32_off2b0_887E9E28(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t14;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 688))) + 48))))((ts4_word)(a0 + 688));
    if ((ts4_word)(t3 & 0xff) != 0) {
        t4 = ts4_find_service((ts4_word)((3803054080) | 35129));
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 68))))((ts4_word)t4, (ts4_word)((1957167104) | 52926));
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 572))) + 20))))((ts4_word)(a0 + 572));
    t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 688)) + 0))) + 20))))((ts4_word)(a0 + 688));
    return t14;
}

/* Swing_DLL.xex 0x887EA110: get u32@0x1c4, ts4_find_service */
ts4_word ts4_get_u32_off1c4_887EA110(ts4_word a0)
{
    return ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 452)));
}

/* Swing_DLL.xex 0x887EA118: if_get u8@0x234, u32@lbl_88D45B1C, u32@0x220, u32@0x1c4, ts4_find_service */
ts4_word ts4_if_get_u8_off234_887EA118(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 564);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 544));
    }
    return ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 452)));
}

/* Swing_DLL.xex 0x887EA1D8: set u8@0x69 */
void ts4_set_u8_off69_887EA1D8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 105) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x887EA558: if_get u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10, u32@0x24, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_887EA558(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    t3 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a1);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16));
    } else {
        p5 = (ts4_word)-1;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 44))))((ts4_word)t6, (ts4_word)p5, (ts4_word)a2);
    return t9;
}

/* Swing_DLL.xex 0x887EAA38: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_887EAA38(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 64));
}

/* Swing_DLL.xex 0x887EAFB8: if_get u8@0xc, u32@0x18 */
ts4_word ts4_if_get_u8_offc_887EAFB8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3394961408) | 52368);
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x887EAFE8: set u32@0x18 */
void ts4_set_u32_off18_887EAFE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    return;
}

/* Swing_DLL.xex 0x887EB218: if_call_seq u32@0x64, lbl_880E4B78, u32@0x0, fn_8857A1E0, u32@0x54, u32@lbl_88D45A0C */
ts4_word ts4_if_call_seq_u32_off64_887EB218(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4B78;
    fn_8857A1E0((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)lbl_88D45A0C = (ts4_word)0;
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t6 != 0) {
        ts4_destroy_owned_object((ts4_word)t6);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(ts4_word)lbl_880D19F0;
    t9 = fn_88617D28((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x887EB398: call_seq fn_88617D88, lbl_880E4C8C, u32@0x0, u32@0x1c, u32@lbl_88D45A08 */
ts4_word ts4_call_seq_fn_88617D88_887EB398(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4C8C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)lbl_88D45A08 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x887EB760: get u32@0x0, u32@0x8, u32@0x0, u32@0x14, u32@0xc, u32@0x4 */
void ts4_get_u32_off0_887EB760(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a1) + 12)) << 3) + t3)) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 48));
    return;
}

/* Swing_DLL.xex 0x887EBF60: if_call_seq lbl_880E4D04, u32@0x0, fn_887E9580, u32@0x20, ts4_destroy_owned_object, lbl_880E4BA0 */
ts4_word ts4_if_call_seq_lbl_880E4D04_887EBF60(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4D04;
    fn_887E9580();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t5 = fn_8860BBD8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x887EC120: call_seq lbl_880E4A34, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_887CBEE0, lbl_880E4A40, fn_88608590 */
ts4_word ts4_call_seq_lbl_880E4A34_887EC120(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4A34);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_887CBEE0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4A40);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_887CBD90((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4A50);
    loc50[0] = (ts4_word)t7;
    t9 = ts4_keyed_item_list_add_unique_887CBC70((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t9;
}

/* Swing_DLL.xex 0x887ECBD0: call_seq lbl_880E4A08, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_887EBFC0, lbl_880E4A18, fn_88608590 */
ts4_word ts4_call_seq_lbl_880E4A08_887ECBD0(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4A08);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_887EBFC0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4A18);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_887EC6F0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4A24);
    loc50[0] = (ts4_word)t7;
    t9 = ts4_keyed_item_list_add_unique_887EBA48((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t9;
}

/* Swing_DLL.xex 0x887EE810: call_seq fn_88617D88, lbl_880E4BF8, u32@0x1c, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_887EE810(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BF8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    fn_881705B0((ts4_word)(a0 + 64), (ts4_word)4);
    return a0;
}

/* Swing_DLL.xex 0x887EFC60: get u32@0x0, u32@0x90 */
ts4_word ts4_get_u32_off0_887EFC60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 144))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x887F04C0: if_get u32@0xe0, u32@0xc, u32@0x0, u32@lbl_88D45B1C, u32@0x27c, u32@0x0 */
void ts4_if_get_u32_offe0_887F04C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 224);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x887F07C8: set u8@0x6 */
void ts4_set_u8_off6_887F07C8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x887F4980: call_seq ts4_object_finalize, fn_887F20D0 */
ts4_word ts4_call_seq_ts4_object_finalize_887F4980(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 232));
    t2 = fn_887F20D0((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x887F7028: fn  */
ts4_word ts4_fn_887F7028(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return (((a2 & 0xff) - (a1 & 0xff)) != 0);
}

/* Swing_DLL.xex 0x887F7040: fn  */
ts4_word ts4_fn_887F7040(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return ((a2 - a1) != 0);
}

/* Swing_DLL.xex 0x887F7100: fn  */
ts4_word ts4_fn_887F7100(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return (((a2 & 0xff) - (a1 & 0xff)) == 0);
}

/* Swing_DLL.xex 0x887F7118: fn  */
ts4_word ts4_fn_887F7118(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return ((a2 - a1) == 0);
}

/* Swing_DLL.xex 0x887F7140: fn  */
ts4_word ts4_fn_887F7140(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887F7148: fn  */
ts4_word ts4_fn_887F7148(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887F7150: fn  */
ts4_word ts4_fn_887F7150(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887F7158: fn  */
ts4_word ts4_fn_887F7158(void)
{
    return 1;
}

/* Swing_DLL.xex 0x887F7160: get u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_887F7160(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x887F7460: get u32@0x1c, u32@0x20, u32@0x0 */
ts4_word ts4_get_u32_off1c_887F7460(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 32);
    return (((*(ts4_word *)((char *)(ts4_word)(t2) + 0)) + t2) + a1);
}

/* Swing_DLL.xex 0x887F9070: if_call_seq lbl_880E3E14, u32@0x0, ts4_object_finalize, u32@0x48, ts4_destroy_owned_object, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880E3E14_887F9070(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3E14;
    ts4_object_finalize((ts4_word)(a0 + 60));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((a0 + 60)) + 0);
    if ((ts4_word)t5 != 0) {
        ts4_destroy_owned_object((ts4_word)t5);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    t11 = fn_88617D28((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x887F9318: set u8@0x42, fn_887F9168, u32@0x2c, u32@0x0, u32@0x14, vcall */
ts4_word ts4_set_u8_off42_887F9318(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(unsigned char *)((char *)(ts4_word)(a0) + 66) = (unsigned char)0;
    fn_887F9168();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 67) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 66) = (unsigned char)1;
    return t5;
}

/* Swing_DLL.xex 0x887F9378: call_seq fn_887F72B8, u32@0x1c, u32@0x24, u32@0x20, u32@0x28, u8@0x8 */
ts4_word ts4_call_seq_fn_887F72B8_887F9378(ts4_word a0)
{
    ts4_word t2;

    fn_887F72B8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x887F9668: if_get u32@0x2c, u32@0x0, u32@0x8, vcall, u32@0x2c, u32@0x20 */
ts4_word ts4_if_get_u32_off2c_887F9668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t6 = ts4_object_finalize((ts4_word)(a0 + 20));
    return t6;
}

/* Swing_DLL.xex 0x887FC280: addr lbl_880C963B, ts4_name_keys_register_887FB3B0 */
ts4_word ts4_addr_lbl_880C963B_887FC280(void)
{
    return ts4_name_keys_register_887FB3B0((ts4_word)(ts4_word)lbl_880C963B);
}

/* Swing_DLL.xex 0x887FC290: addr lbl_880C963A, ts4_name_keys_register_887FB3B0 */
ts4_word ts4_addr_lbl_880C963A_887FC290(void)
{
    return ts4_name_keys_register_887FB3B0((ts4_word)(ts4_word)lbl_880C963A);
}

/* Swing_DLL.xex 0x887FC600: call_seq ts4_object_finalize, ts4_object_finalize, ts4_object_finalize, u32@0x54, u32@0x50, fn_881B4740 */
ts4_word ts4_call_seq_ts4_object_finalize_887FC600(ts4_word a0)
{
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    ts4_object_finalize((ts4_word)(a0 + 56));
    ts4_object_finalize((ts4_word)(a0 + 44));
    ts4_object_finalize((ts4_word)(a0 + 68));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    fn_881B4740((ts4_word)(a0 + 80), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)), (ts4_word)t4);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    fn_881B47A8((ts4_word)(a0 + 92), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)), (ts4_word)t7);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t10 = ts4_object_finalize((ts4_word)(a0 + 20));
    return t10;
}

/* Swing_DLL.xex 0x887FC748: call_seq lbl_880C963B, ts4_name_keys_register_887FB3B0, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880C963B_887FC748(ts4_word a0)
{
    ts4_word t2;

    ts4_name_keys_register_887FB3B0((ts4_word)(ts4_word)lbl_880C963B);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88800850: call_seq fn_887FFFB8, u32@0x84, u32@0xc */
ts4_word ts4_call_seq_fn_887FFFB8_88800850(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_887FFFB8((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 132))) + 12));
}

/* Swing_DLL.xex 0x88800880: call_seq fn_887FFFB8, u32@0x84, u32@0x10 */
ts4_word ts4_call_seq_fn_887FFFB8_88800880(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_887FFFB8((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 132))) + 16));
}

/* Swing_DLL.xex 0x88800AA0: if_call_seq fn_887FFFB8, u32@0x84, fn_887FFFB8, u32@0x84, fn_88800080, u32@0x0 */
ts4_word ts4_if_call_seq_fn_887FFFB8_88800AA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = fn_887FFFB8((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
    if ((int)a3 == 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 132));
    } else {
        t3 = fn_887FFFB8((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 132));
    }
    t6 = fn_88800080((ts4_word)p5, (ts4_word)a2);
    return ((((t6 + 1) << 6) + (*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + t1);
}

/* Swing_DLL.xex 0x88800C50: if_call_seq u32@0x28, u32@0x8, fn_888860A0, u32@0x10, u32@0x28, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off28_88800C50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p4 = (ts4_word)a0;
    if ((ts4_word)(t1 & 0x1) != 0) {
        t3 = fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x88801070: if_call_seq u32@0xbc, u32@0x1c, u32@0x24, u32@0x44, u32@0x4c, u32@0x6c */
ts4_word ts4_if_call_seq_u32_offbc_88801070(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    p3 = (ts4_word)t1;
    if ((int)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x888011D0: call_seq fn_88800BF8, lbl_880E3A40, u32@0x28, u32@0x0 */
ts4_word ts4_call_seq_fn_88800BF8_888011D0(ts4_word a0)
{
    fn_88800BF8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3A40;
    return a0;
}

/* Swing_DLL.xex 0x888012F8: get u32@0x1c, u32@0x4c, vcall, fn_88800D40 */
ts4_word ts4_get_u32_off1c_888012F8(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 76))))((ts4_word)(a0 + 28), (ts4_word)0);
    t4 = fn_88800D40((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x88801330: get u32@0x1c, u32@0x48, vcall, fn_88800E40 */
ts4_word ts4_get_u32_off1c_88801330(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 72))))((ts4_word)(a0 + 28), (ts4_word)0);
    t4 = fn_88800E40((ts4_word)t3, (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x88801E10: call_seq u32@lbl_88D459F8, fn_88801428, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_u32_lbl_88D459F8_88801E10(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)lbl_88D459F8 = (ts4_word)0;
    fn_88801428((ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88801F98: call_seq lbl_880E39C8, u32@0x0, fn_8892AF80, fn_88617D28 */
ts4_word ts4_call_seq_lbl_880E39C8_88801F98(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E39C8;
    fn_8892AF80((ts4_word)(a0 + 28));
    t2 = fn_88617D28((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x88801FE0: call_seq fn_88617D88, lbl_880E39C8, u32@0x0, fn_8892AFF0 */
ts4_word ts4_call_seq_fn_88617D88_88801FE0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E39C8;
    fn_8892AFF0((ts4_word)(a0 + 28));
    return a0;
}

/* Swing_DLL.xex 0x88802EF0: fn  */
ts4_word ts4_fn_88802EF0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88802F20: fn  */
ts4_word ts4_fn_88802F20(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88802F28: fn  */
ts4_word ts4_fn_88802F28(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88802F30: fn  */
ts4_word ts4_fn_88802F30(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88802F38: fn  */
ts4_word ts4_fn_88802F38(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88802F80: get u32@0x44, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off44_88802F80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88802F98: get u32@0x44, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off44_88802F98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88802FB0: get u32@0x44, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off44_88802FB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88803068: fn  */
ts4_word ts4_fn_88803068(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88803070: set u32@0x8 */
void ts4_set_u32_off8_88803070(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88803088: get u32@0x8 */
ts4_word ts4_get_u32_off8_88803088(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88803150: addr lbl_880E3738, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880E3738_88803150(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3738;
    return;
}

/* Swing_DLL.xex 0x88803178: addr lbl_880E3770, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880E3770_88803178(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3770;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}
