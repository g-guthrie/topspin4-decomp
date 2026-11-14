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

extern char ts4_fn_888A09C0[];
extern char fn_888A0C10[];
extern char ts4_if_get_u32_off10_888A0DD8[];
extern char fn_888A0F08[];
extern char fn_888A1178[];
extern char fn_888A1200[];
extern char ts4_if_get_u32_off10_888A15C0[];
extern char ts4_prolog_element_content_spec_888A1858[];
extern char fn_888A19F0[];
extern char fn_888A1AF8[];
extern char fn_888A1C68[];
extern char fn_888A1DB0[];
extern char ts4_prolog_entity_external_or_value_888A1EF0[];
extern char fn_888A2068[];
extern char ts4_prolog_entity_external_or_value_888A2210[];
extern char fn_888A2458[];
extern char ts4_if_get_u32_off10_888A2700[];
extern char fn_888A27C0[];
extern char ts4_token_classify_888A2AC8[];
extern char g_ts4_script_constants[];
extern char lbl_880C9748[];
extern char lbl_880CF7F8[];
extern char lbl_880D0830[];
extern char lbl_880D0934[];
extern char lbl_880D0938[];
extern char lbl_880D19F0[];
extern char lbl_880D1CE0[];
extern char lbl_880D49CC[];
extern char lbl_880D6B70[];
extern char lbl_880D7074[];
extern char lbl_880D75C4[];
extern char lbl_880D75FC[];
extern char lbl_880D7604[];
extern char lbl_880D7608[];
extern char lbl_880D91F4[];
extern char lbl_880D9874[];
extern char lbl_880D9888[];
extern char lbl_880D98A4[];
extern char lbl_880D98B8[];
extern char lbl_880D9AA4[];
extern char lbl_880D9AB8[];
extern char lbl_880D9B50[];
extern char lbl_880DA718[];
extern char lbl_880DB200[];
extern char lbl_880DB228[];
extern char lbl_880DB2A4[];
extern char lbl_880DB2C8[];
extern char lbl_880DB2D8[];
extern char lbl_880DB350[];
extern char lbl_880DB370[];
extern char lbl_880DB3C0[];
extern char lbl_880DB408[];
extern char lbl_880DB490[];
extern char lbl_880DB530[];
extern char lbl_880DB580[];
extern char lbl_880DB5F8[];
extern char lbl_880DB744[];
extern char lbl_880DB794[];
extern char lbl_880DB7E4[];
extern char lbl_880DB80C[];
extern char lbl_880DB8DC[];
extern char lbl_880DBC30[];
extern char lbl_880DBCDC[];
extern char lbl_880DBD58[];
extern char lbl_880DBD80[];
extern char lbl_880DBEB8[];
extern char lbl_880DC550[];
extern char lbl_880DC5DC[];
extern char lbl_880DC614[];
extern char lbl_880DC6B8[];
extern char lbl_880DC810[];
extern char lbl_880DCE3C[];
extern char lbl_880DF260[];
extern char lbl_880DFC6C[];
extern char lbl_880E0728[];
extern char lbl_880E1048[];
extern char lbl_880E2FBC[];
extern char lbl_880E2FD4[];
extern char lbl_880E3004[];
extern char lbl_880E3018[];
extern char lbl_880E3638[];
extern char lbl_880E3644[];
extern char lbl_880E3E74[];
extern char lbl_880F7F38[];
extern char lbl_8814B440[];
extern char lbl_88C46F6A[];
extern char lbl_88C6ADAC[];
extern char lbl_88C6ADC8[];
extern char lbl_88C6B8F4[];
extern char lbl_88C6B90C[];
extern char lbl_88C6B918[];
extern char lbl_88C6B924[];
extern char lbl_88C6BE68[];
extern char lbl_88D45908[];
extern char lbl_88D4591C[];
extern char lbl_88D45948[];
extern char lbl_88D45954[];
extern char lbl_88D459B8[];
extern char lbl_88D459C8[];
extern char lbl_88D459D4[];
extern char lbl_88D459DC[];
extern char lbl_88D45A04[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_881609C8();
ts4_word fn_881640A8();
ts4_word fn_8816CAA0();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_88178AA8();
ts4_word ts4_call_seq_u32_off0_8817B998();
ts4_word fn_8817DF90();
ts4_word fn_8817E150();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word fn_8817EA90();
ts4_word fn_8817EE38();
ts4_word ts4_loop_call_seq_u32_off40_881815A8();
ts4_word ts4_loop_call_seq_u32_0x4_88181670();
ts4_word fn_88187AB8();
ts4_word fn_8819AE68();
ts4_word ts4_if_call_seq_u32_off0_8819C190();
ts4_word fn_881A6A00();
ts4_word fn_881A7A20();
ts4_word fn_881A9BE8();
ts4_word fn_881AB108();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882908C0();
ts4_word fn_88290C68();
ts4_word fn_882C7288();
ts4_word ts4_forward_to_fn_8841B5E0();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_88564F40();
ts4_word fn_885651F8();
ts4_word ts4_crt_nh_malloc_88565258();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_tailcall_XamEnumerate_8857A1C8();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_tailcall_XamContentDelete_8857B2D0();
ts4_word ts4_tailcall_XamContentClose_8857B2D8();
ts4_word ts4_tailcall_XamContentCreateEnumerator_8857B2F0();
ts4_word fn_8857B388();
ts4_word fn_8857B4C8();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word ts4_tailcall_fn_88582660_8857B840();
ts4_word fn_8857C1F8();
ts4_word fn_88581AF0();
ts4_word fn_88581B70();
ts4_word fn_8860BBD8();
ts4_word fn_88613350();
ts4_word fn_88614938();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88619E50();
ts4_word fn_8861AB88();
ts4_word fn_88622E88();
ts4_word fn_8862A1F0();
ts4_word fn_8862C0E8();
ts4_word fn_88631048();
ts4_word fn_88636CF0();
ts4_word fn_887D9C90();
ts4_word ts4_if_call_seq_u32_offc_887E6550();
ts4_word fn_887EB4A0();
ts4_word ts4_if_call_seq_lbl_880E3E3C_887FC130();
ts4_word ts4_call_seq_fn_88832F70_88806570();
ts4_word lua2_next_88814BB8();
ts4_word ts4_if_call_seq_u32_off10_88815520();
ts4_word lua2_luaK_exp2anyreg_888216D0();
ts4_word lua2_luaK_exp2RK_88821878();
ts4_word ts4_call_seq_u32_off0_88832F70();
ts4_word fn_888368B0();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_88864E48();
ts4_word fn_88865AB0();
ts4_word fn_88866980();
ts4_word fn_88866DA0();
ts4_word fn_88867E68();
ts4_word ts4_hash_lookup_null_888689A8();
ts4_word fn_88868B48();
ts4_word fn_888690F0();
ts4_word fn_88869530();
ts4_word fn_8886B1B0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B1C_8886B520();
ts4_word fn_8886B5C0();
ts4_word fn_8886F9A0();
ts4_word ts4_if_call_seq_u32_off48_88871778();
ts4_word fn_888719E0();
ts4_word ts4_crc32_big_88878408();
ts4_word ts4_adler32_88878A90();
ts4_word fn_88882868();
ts4_word fn_88884FD0();
ts4_word fn_888860A0();
ts4_word fn_8888A4E8();
ts4_word fn_88891310();
ts4_word fn_888A10A0();
ts4_word ts4_xml_pool_grow_888A2F00();
ts4_word ts4_if_get_u8_offec_888A8610();
ts4_word fn_888AA228();
ts4_word fn_888AA328();
ts4_word ts4_if_get_u32_lbl_88D45B1C_888C0198();
ts4_word fn_888C3768();
ts4_word fn_888C7718();
ts4_word fn_888C93E8();
ts4_word fn_888C9A68();
ts4_word fn_888CCFF0();
ts4_word fn_888CD190();
ts4_word fn_888CD2B8();
ts4_word fn_888CE8D0();
ts4_word fn_888CF650();
ts4_word fn_888D3648();
ts4_word fn_888D7920();
ts4_word fn_888D84B8();
ts4_word ts4_if_call_seq_fn_8817EA90_888D85B0();
ts4_word fn_888DD008();
ts4_word fn_888E7720();
ts4_word fn_888EC548();
ts4_word fn_888F1170();
ts4_word fn_888F1B30();
ts4_word ts4_call_seq_u32_off1c_888F5D50();
ts4_word fn_888F69A0();
ts4_word fn_888F7160();
ts4_word fn_889006D8();
ts4_word fn_88901010();
ts4_word fn_88907570();
ts4_word fn_88908B38();
ts4_word ts4_net_update_slots_88908B80();
ts4_word fn_8890A1F0();
ts4_word fn_8890CB18();
ts4_word fn_8890F370();
ts4_word fn_8890F428();
ts4_word fn_88914A70();
ts4_word fn_88929E70();
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80();
ts4_word ts4_call_seq_fn_88617D88_8892AFF0();
ts4_word ts4_if_get_u32_off0_8892FE20();
ts4_word fn_88B08168();
ts4_word fn_88B083F8();
ts4_word fn_88B085A8();
ts4_word fn_88B09368();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_profile_internal_activate();

/* Swing_DLL.xex 0x887E65E8: call_seq fn_887D9C90, ts4_if_call_seq_u32_offc_887E6550 */
ts4_word ts4_call_seq_fn_887D9C90_887E65E8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_887D9C90((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t2 = ts4_if_call_seq_u32_offc_887E6550((ts4_word)(a0 + 88), (ts4_word)a1, (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x887FC8A0: if_call_seq lbl_880E3E74, u32@0x0, u32@0x68, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880E3E3C_887FC130 */
ts4_word ts4_if_call_seq_lbl_880E3E74_887FC8A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3E74;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880E3E3C_887FC130((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88806650: if_call_seq lbl_880E2FD4, ts4_call_seq_u32_off0_88832F70, lbl_880E3018, fn_888368B0, fn_888368B0, lbl_880E3638 */
ts4_word ts4_if_call_seq_lbl_880E2FD4_88806650(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    int t2;
    ts4_word t9;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2FD4);
    t2 = loc60[2];
    if ((int)t2 != 0) {
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3018, (ts4_word)(ts4_word)&loc50[0]);
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3018, (ts4_word)(ts4_word)&loc50[0]);
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3638, (ts4_word)(ts4_word)&loc50[0]);
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3644, (ts4_word)(ts4_word)&loc50[0]);
        ts4_call_seq_fn_88832F70_88806570((ts4_word)(ts4_word)lbl_880E2FD4, (ts4_word)a0);
    }
    t9 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t9;
}

/* Swing_DLL.xex 0x88806718: if_call_seq lbl_880E2FBC, ts4_call_seq_u32_off0_88832F70, lbl_880E3004, fn_888368B0, ts4_call_seq_fn_88832F70_88806570, fn_881B19A0 */
ts4_word ts4_if_call_seq_lbl_880E2FBC_88806718(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    int t2;
    ts4_word t6;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2FBC);
    t2 = loc60[2];
    if ((int)t2 != 0) {
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3004, (ts4_word)(ts4_word)&loc50[0]);
        ts4_call_seq_fn_88832F70_88806570((ts4_word)(ts4_word)lbl_880E2FBC, (ts4_word)a0);
    }
    t6 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t6;
}

/* Swing_DLL.xex 0x888114E0: loop_get u8@0xd, u32@0x10, u32@0x18, u32@0x0, u32@0x8, u32@0x20 */
ts4_word ts4_loop_get_u8_offd_888114E0(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p8;
    unsigned char t1;
    ts4_word t2;
    int t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    lv4 = (ts4_word)((((((1 << t1) + -1) & t2) + ((((1 << t1) + -1) & t2) << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((int)t5 == 4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 8)) == (ts4_word)a1) {
            return (lv4 + 16);
        }
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 32));
        lv4 = p8;
    } while ((ts4_word)p8 != 0);
    return (ts4_word)lbl_880C9748;
}

/* Swing_DLL.xex 0x888164B0: call_seq u32@0x30, lua2_luaK_exp2anyreg_888216D0, lua2_next_88814BB8, ts4_if_call_seq_u32_off10_88815520, lua2_luaK_exp2RK_88821878, u32@0x8 */
ts4_word ts4_call_seq_u32_off30_888164B0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[8];
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    lua2_luaK_exp2anyreg_888216D0((ts4_word)t1, (ts4_word)a1);
    lua2_next_88814BB8((ts4_word)a0);
    ts4_if_call_seq_u32_off10_88815520((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t5 = lua2_luaK_exp2RK_88821878((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)8;
    return t5;
}

/* Swing_DLL.xex 0x88853670: call_seq lbl_880E1048, fn_88867E68, fn_8816CAA0 */
ts4_word ts4_call_seq_lbl_880E1048_88853670(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[128];
    ts4_word t2;

    fn_88867E68((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880E1048);
    t2 = fn_8816CAA0((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x88866278: if_call_seq lbl_880E0728, u32@0x0, u32@0x24, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880E0728_88866278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E0728;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888670B0: if_call_seq u32@lbl_88D459DC, fn_88865AB0, u8@0x0, u32@lbl_88D459DC, fn_88866DA0 */
ts4_word ts4_if_call_seq_u32_lbl_88D459DC_888670B0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    t2 = fn_88865AB0((ts4_word)(*(ts4_word *)lbl_88D459DC), (ts4_word)1, (ts4_word)a0, (ts4_word)a1);
    p6 = (ts4_word)t2;
    if ((ts4_word)(t2 & 0xff) != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 0)) == 0) {
        t5 = fn_88866DA0((ts4_word)(*(ts4_word *)lbl_88D459DC), (ts4_word)a0, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88867768: call_seq ts4_if_call_seq_u32_off0_8819C190, ts4_memset, u32@0x0, fn_88864E48, fn_8819AE68 */
ts4_word ts4_call_seq_fn_8819C190_88867768(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[26];
    ts4_word t5;

    ts4_if_call_seq_u32_off0_8819C190((ts4_word)a1, (ts4_word)a0);
    ts4_memset((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)100);
    fn_88864E48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
    t5 = fn_8819AE68((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88867E10: call_seq fn_88866980, ts4_if_call_seq_u32_lbl_88D459E4_8883F238, fn_88619E50 */
ts4_word ts4_call_seq_fn_88866980_88867E10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[130];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88866980((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512);
    t2 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238((ts4_word)t1);
    t3 = fn_88619E50((ts4_word)t2, (ts4_word)a2, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x88868490: call_seq fn_88866980, ts4_if_call_seq_u32_lbl_88D459E4_8883F238, fn_8862A1F0 */
ts4_word ts4_call_seq_fn_88866980_88868490(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[130];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88866980((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512);
    t2 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238((ts4_word)t1);
    t3 = fn_8862A1F0((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x88868E78: call_seq ts4_assign_formatted_text, lbl_880DFC6C, fn_881640A8, ts4_if_call_seq_u32_off0_8816D140, ts4_destroy_owned_object, ts4_destroy_owned_object */
ts4_word ts4_call_seq_ts4_assign_formatted_text_88868E78(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 25));
    t2 = fn_881640A8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880DFC6C, (ts4_word)(ts4_word)&loc50[0]);
    ts4_if_call_seq_u32_off0_8816D140((ts4_word)a0, (ts4_word)t2);
    t4 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t4);
    t6 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t6);
    return a0;
}

/* Swing_DLL.xex 0x88869740: if_call_seq fn_88868B48, u8@0x7e, u8@0x7d, u8@0x7c */
ts4_word ts4_if_call_seq_fn_88868B48_88869740(ts4_word a0, int a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_88868B48((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        if ((int)a1 == 1) {
            *(unsigned char *)((char *)(ts4_word)(t1) + 124) = (unsigned char)a2;
        } else {
            if ((int)a1 == 2) {
                *(unsigned char *)((char *)(ts4_word)(t1) + 125) = (unsigned char)a2;
            } else {
                if ((int)a1 == 3) {
                    *(unsigned char *)((char *)(ts4_word)(t1) + 126) = (unsigned char)a2;
                }
            }
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x8886B4D0: call_seq lbl_880D91F4, fn_8886B1B0, fn_8816CAA0 */
ts4_word ts4_call_seq_lbl_880D91F4_8886B4D0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[128];
    ts4_word t2;

    fn_8886B1B0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880D91F4, (ts4_word)1);
    t2 = fn_8816CAA0((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8886B788: loop_call_seq u32@0x5c, u32@0x60, fn_8886B5C0, u32@0x60, u32@0x0, fn_8886B5C0 */
ts4_word ts4_loop_call_seq_u32_off5c_8886B788(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word lv11;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t10;
    ts4_word t13;
    ts4_word t24;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    p7 = (ts4_word)t2;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            fn_8886B5C0((ts4_word)a0, (ts4_word)lv3, (ts4_word)0);
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
            p6 = (ts4_word)(lv3 + 92);
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t5);
        p7 = (ts4_word)t5;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)((a0 + 92)) + 0);
    if ((ts4_word)t10 != (ts4_word)p7) {
        lv11 = (ts4_word)t10;
        do {
            fn_8886B5C0((ts4_word)a0, (ts4_word)lv11, (ts4_word)1);
            t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
            p14 = (ts4_word)(lv11 + 92);
            lv11 = p14;
        } while ((ts4_word)p14 != (ts4_word)t13);
    }
    fn_881AB108((ts4_word)(a0 + 92));
    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(a0 + 68));
    ts4_object_finalize((ts4_word)(a0 + 68));
    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(a0 + 80));
    t24 = ts4_object_finalize((ts4_word)(a0 + 80));
    return t24;
}

/* Swing_DLL.xex 0x8886BCB8: if_get u32@lbl_88D459C8, ts4_if_call_seq_u32_lbl_88D45B1C_8886B520 */
ts4_word ts4_if_get_u32_lbl_88D459C8_8886BCB8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D459C8;
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ts4_if_call_seq_u32_lbl_88D45B1C_8886B520((ts4_word)t1, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8886FC20: if_call_seq u32@lbl_88D459D4, fn_8886F9A0, u32@0x1c, u32@0x1c, fn_88869530, fn_888690F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D459D4_8886FC20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t5;

    t2 = fn_8886F9A0((ts4_word)(*(ts4_word *)lbl_88D459D4), (ts4_word)a1, (ts4_word)a3, (ts4_word)a2);
    if ((ts4_word)(t2 & 0xff) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t4 == (ts4_word)((253886464) | 43686)) {
            t8 = ts4_hash_lookup_null_888689A8((ts4_word)t2);
            fn_888690F0((ts4_word)t8, (ts4_word)a2, (ts4_word)a3, (ts4_word)1, (ts4_word)1, (ts4_word)1, (ts4_word)0);
        } else {
            t5 = fn_88869530((ts4_word)a1);
            if ((ts4_word)t5 != 0) {
                fn_888690F0((ts4_word)t5, (ts4_word)a2, (ts4_word)a3, (ts4_word)1, (ts4_word)1, (ts4_word)1, (ts4_word)0);
            }
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8886FD98: get u32@0x88, u32@0x84 */
ts4_word ts4_get_u32_off88_8886FD98(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 132))) / (int)132);
}

/* Swing_DLL.xex 0x88870748: loop_get u32@0x0, u32@0x4, vcall, u32@0xc, u32@0x10, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_88870748(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p19;
    ts4_word t4;
    ts4_word t5;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)a0, (ts4_word)12);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t4 != (ts4_word)t5) {
        lv6 = (ts4_word)t4;
        do {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)lv6, (ts4_word)12);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(lv6 + 12), (ts4_word)12);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(lv6 + 24), (ts4_word)12);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(lv6 + 36), (ts4_word)4);
            p19 = (ts4_word)(lv6 + 40);
            lv6 = p19;
        } while ((ts4_word)p19 != (ts4_word)t5);
    }
    return 1;
}

/* Swing_DLL.xex 0x88870810: loop_get u32@0x0, u32@0x10, vcall, u32@0xc, u32@0x10, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_88870810(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p19;
    ts4_word t4;
    ts4_word t5;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)a0, (ts4_word)12);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t4 != (ts4_word)t5) {
        lv6 = (ts4_word)t4;
        do {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)lv6, (ts4_word)12);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)(lv6 + 12), (ts4_word)12);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)(lv6 + 24), (ts4_word)12);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)(lv6 + 36), (ts4_word)4);
            p19 = (ts4_word)(lv6 + 40);
            lv6 = p19;
        } while ((ts4_word)p19 != (ts4_word)t5);
    }
    return 1;
}

/* Swing_DLL.xex 0x88871108: if_call_seq u32@0x4, u32@0x0, fn_881A9BE8, u32@0x4, u32@0x84, u32@0x88 */
ts4_word ts4_if_call_seq_u32_off4_88871108(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t3 = fn_881A9BE8((ts4_word)t1, (ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)t3;
    if ((ts4_word)a1 == 0) {
        fn_881A7A20((ts4_word)a2, (ts4_word)(a0 + 28));
    } else {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
        if ((ts4_word)(a1 + -1) < (ts4_word)((int)(t7 - t6) / (int)132)) {
            fn_881A7A20((ts4_word)a2, (ts4_word)((((int)(a1 + -1) * 132) + t6) + 28));
        }
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    return ((int)(t12 - (*(ts4_word *)((char *)(ts4_word)(a2) + 0))) / (int)48);
}

/* Swing_DLL.xex 0x88871810: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_88871810(ts4_word a0)
{
    float t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 116) = t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x88871BD8: loop_call_seq u32@0x88, u32@0x84, ts4_if_call_seq_u32_off48_88871778, u32@0x84, ts4_destroy_owned_object, ts4_if_call_seq_u32_off48_88871778 */
ts4_word ts4_loop_call_seq_u32_off88_88871BD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            ts4_if_call_seq_u32_off48_88871778((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 132);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    t11 = ts4_if_call_seq_u32_off48_88871778((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x88871CE8: tailcall fn_885651F8 */
ts4_word ts4_tailcall_fn_885651F8_88871CE8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_885651F8((ts4_word)a1);
}

/* Swing_DLL.xex 0x88871CF0: tailcall ts4_crt_nh_malloc_88565258 */
ts4_word ts4_tailcall_fn_88565258_88871CF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return ts4_crt_nh_malloc_88565258((ts4_word)((int)a1 * (int)a2));
}

/* Swing_DLL.xex 0x88876668: if_call_seq u32@0x4, u32@0x1c, u32@0x4, u32@0x18, u32@0x0, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off4_88876668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    int t4;
    ts4_word t12;
    ts4_word t14;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t18;
    ts4_word t19;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p2 = (ts4_word)t1;
    if ((ts4_word)t1 > (ts4_word)a2) {
        p2 = (ts4_word)a2;
    }
    if ((ts4_word)p2 == 0) {
        return 0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 - p2);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 24);
    if ((int)t4 == 1) {
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t14 = ts4_adler32_88878A90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)t12, (ts4_word)p2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t14;
    } else {
        if ((int)t4 == 2) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
            if ((ts4_word)t7 == 0) {
                p10 = (ts4_word)0;
            } else {
                t9 = ts4_crc32_big_88878408((ts4_word)t8, (ts4_word)t7, (ts4_word)p2);
                p10 = (ts4_word)t9;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)p10;
        }
    }
    memcpy((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)p2);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t18 + p2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t19 + p2);
    return p2;
}

/* Swing_DLL.xex 0x88883B40: if_call_seq u32@0x1c, ts4_find_service, u32@0x1c, fn_88882868 */
ts4_word ts4_if_call_seq_u32_off1c_88883B40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 == 0) {
        t2 = ts4_find_service((ts4_word)((3523674112) | 52023));
        if ((ts4_word)t2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t2;
        }
    }
    t4 = fn_88882868((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88883C68: if_fn  */
ts4_word ts4_if_fn_88883C68(ts4_word a0)
{
    ts4_word p1;

    p1 = (ts4_word)0;
    if ((int)(a0 & 0x1) != 0) {
        p1 = (ts4_word)(2147483648);
    }
    if ((int)(a0 & 0x2) != 0) {
        return (p1 | 1073741824);
    }
    return p1;
}

/* Swing_DLL.xex 0x888841A0: tailcall memcpy */
ts4_word ts4_tailcall_memcpy_888841A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return memcpy((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x888841D8: call_seq fn_88581AF0 */
ts4_word ts4_call_seq_fn_88581AF0_888841D8(void)
{
    ts4_word loc50[10];
    ts4_word t2;

    fn_88581AF0((ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[3];
    return t2;
}

/* Swing_DLL.xex 0x888844B8: set u32@0x0, u32@0x4, u32@0x8, u8@0xc, u8@0x14 */
void ts4_set_u32_off0_888844B8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888844D8: if_fn  */
ts4_word ts4_if_fn_888844D8(ts4_word a0)
{
    ts4_word p1;

    p1 = (ts4_word)0;
    if ((int)(a0 & 0x1) != 0) {
        p1 = (ts4_word)(2147483648);
    }
    if ((int)(a0 & 0x2) != 0) {
        return (p1 | 1073741824);
    }
    return p1;
}

/* Swing_DLL.xex 0x888845F0: addr lbl_880D6B70, u8@0x1c, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_addr_lbl_880D6B70_888845F0(ts4_word a0)
{
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888846D8: if_call_seq u32@lbl_88D45B38, u32@lbl_88D459B8, u32@0x2c, u32@lbl_88D459B8, u32@0x2c, fn_88581B70 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_888846D8(ts4_word a0)
{
    ts4_word loc50[8];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)lbl_88D45B38;
    t2 = *(ts4_word *)lbl_88D459B8;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
    *(ts4_word *)lbl_88D459B8 = (ts4_word)(t2 + a0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)(t3 + a0);
    t4 = fn_88581B70();
    if ((ts4_word)t4 == 0) {
        fn_88581AF0((ts4_word)(ts4_word)&loc50[0]);
    }
    return t4;
}

/* Swing_DLL.xex 0x88884D68: if_get u32@0x0, u32@0x4, u32@0x24, ts4_tailcall_XamContentClose_8857B2D8, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88884D68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p10;
    int t1;
    ts4_word t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p10 = (ts4_word)a0;
    if ((int)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)) == (ts4_word)a0) {
        ts4_tailcall_XamContentClose_8857B2D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        p9 = (ts4_word)t5;
        if ((ts4_word)t5 != 0) {
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
            p9 = (ts4_word)t8;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88884E50: if_get u32@0x0, u32@lbl_88D45B1C, u32@0x2cc, u32@lbl_88D45B1C, u32@0x2cc, lbl_88C6BE68 */
ts4_word ts4_if_get_u32_off0_88884E50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word p14;
    ts4_word p15;
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p15 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 716);
        if ((int)t5 == 0) {
            p6 = (ts4_word)(ts4_word)lbl_88C6BE68;
        } else {
            p6 = (ts4_word)(t5 + 10992);
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(p6) + 40);
        ((ts4_word (*)(ts4_word))(t7))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 584)));
        t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        p14 = (ts4_word)t10;
        if ((ts4_word)t10 != 0) {
            t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 0))))((ts4_word)t10, (ts4_word)1);
            p14 = (ts4_word)t13;
        }
        p15 = (ts4_word)p14;
    }
    return p15;
}

/* Swing_DLL.xex 0x88884ED8: if_addr lbl_88C6BE68, u32@lbl_88D45B1C, u32@0x2cc, u32@0x10, vcall, u32@lbl_88D45B1C */
ts4_word ts4_if_addr_lbl_88C6BE68_88884ED8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p10;
    int t2;
    ts4_word t5;
    int t9;

    (void)a0;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)lbl_88D45B1C)) + 716);
    if ((int)t2 == 0) {
        p3 = (ts4_word)(ts4_word)lbl_88C6BE68;
    } else {
        p3 = (ts4_word)(t2 + 10992);
    }
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(p3) + 16))))((ts4_word)a1, (ts4_word)(2147483648), (ts4_word)1, (ts4_word)0, (ts4_word)3, (ts4_word)(536870912), (ts4_word)0);
    if ((ts4_word)(((t5 + 1) != 0) & 0xff) != 0) {
        t9 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)lbl_88D45B1C)) + 716);
        if ((int)t9 == 0) {
            p10 = (ts4_word)(ts4_word)lbl_88C6BE68;
        } else {
            p10 = (ts4_word)(t9 + 10992);
        }
        ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(p10) + 40))))((ts4_word)t5);
    }
    return ((t5 + 1) != 0);
}

/* Swing_DLL.xex 0x88884F80: call_seq u32@0x4, ts4_tailcall_fn_88582F30_8857A128, u8@0xc */
ts4_word ts4_call_seq_u32_off4_88884F80(ts4_word a0)
{
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)-1);
    return (*(volatile unsigned char *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88884FB8: get u32@0x4, u8@0xc, fn_8857C1F8 */
ts4_word ts4_get_u32_off4_88884FB8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
    return fn_8857C1F8((ts4_word)t1);
}

/* Swing_DLL.xex 0x88886160: if_get u32@lbl_88D45B38, fn_88613350, ts4_crt_nh_malloc_88565258 */
ts4_word ts4_if_get_u32_lbl_88D45B38_88886160(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 == 0) {
        return ts4_crt_nh_malloc_88565258((ts4_word)a0);
    }
    return fn_88613350((ts4_word)t1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x88886180: if_get u32@lbl_88D45B38, fn_88613350, ts4_crt_nh_malloc_88565258 */
ts4_word ts4_if_get_u32_lbl_88D45B38_88886180(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 == 0) {
        return ts4_crt_nh_malloc_88565258((ts4_word)a0);
    }
    return fn_88613350((ts4_word)t1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x888865E8: addr lbl_880D6B70, lbl_880F7F38, u32@0x20, u32@0x0, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880D6B70_888865E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7F38;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x888869A8: if_call_seq u32@lbl_88D45B38, fn_88613350, ts4_crt_nh_malloc_88565258, u32@0x40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_888869A8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 == 0) {
        t3 = ts4_crt_nh_malloc_88565258((ts4_word)28);
        p4 = (ts4_word)t3;
    } else {
        t2 = fn_88613350((ts4_word)t1, (ts4_word)28);
        p4 = (ts4_word)t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)p4;
    return p4;
}

/* Swing_DLL.xex 0x88886B20: loop_call_seq fn_88884FD0, fn_8861AB88 */
ts4_word ts4_loop_call_seq_fn_88884FD0_88886B20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p3;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)(a0 + 5364) != (ts4_word)(a0 + 5340)) {
        lv1 = (ts4_word)(a0 + 5340);
        do {
            fn_88884FD0((ts4_word)lv1);
            p3 = (ts4_word)(lv1 + 24);
            lv1 = p3;
        } while ((ts4_word)p3 != (ts4_word)(a0 + 5364));
    }
    t6 = fn_8861AB88((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88886CB8: if_call_seq u32@0x0, u32@lbl_88D45B1C, u32@0x1c, u32@0x234, fn_88614938, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_88886CB8(ts4_word a0)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)lbl_88D45B1C;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t5 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 564)), (ts4_word)t3);
    if ((ts4_word)t5 != 0) {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 16));
    } else {
        p7 = (ts4_word)-1;
    }
    t9 = ts4_tailcall_XamContentDelete_8857B2D0((ts4_word)p7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)0);
    ts4_tailcall_fn_88582660_8857B840((ts4_word)t9);
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 8) = (unsigned char)1;
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88887060: if_call_seq u32@0x8, ts4_tailcall_XamContentClose_8857B2D8, u32@0x0, u32@0x4, u32@0x250, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off8_88887060(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = ts4_tailcall_XamContentClose_8857B2D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 592))) + 0) = (ts4_word)((2619080704) | 37749);
        if ((ts4_word)t4 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)1;
        }
    }
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 8) = (unsigned char)1;
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x888873E8: if_call_seq u32@0x10, u32@0x8, u32@0x4, u32@0x8, u32@0x14, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off10_888873E8(ts4_word a0)
{
    ts4_word p6;
    ts4_word p13;
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t21;
    ts4_word t22;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4) = (ts4_word)t1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p6 = (ts4_word)(ts4_word)&loc54[0];
    if ((ts4_word)t5 != 0) {
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t8 = *(ts4_word *)lbl_88D45B1C;
    t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 28);
    t11 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t8) + 564)), (ts4_word)t9);
    if ((ts4_word)t11 != 0) {
        p13 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 16));
    } else {
        p13 = (ts4_word)-1;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t16 = fn_8857B388((ts4_word)p13, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)t14, (ts4_word)3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)p6, (ts4_word)0);
    if ((ts4_word)t16 != 0) {
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t17) + 592))) + 0) = (ts4_word)((2619080704) | 37749);
        if ((ts4_word)t18 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t18) + 0) = (ts4_word)1;
        }
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0) = (ts4_word)t16;
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t22 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(t21) + 4) = (ts4_word)t22;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 8) = (unsigned char)1;
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88889220: addr lbl_880DF260, lbl_880D19F0, u32@0x0, u32@0x14f4, fn_88631048 */
ts4_word ts4_addr_lbl_880DF260_88889220(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF260;
    *(ts4_word *)((char *)(ts4_word)(a0) + 5364) = (ts4_word)(ts4_word)lbl_880D19F0;
    return fn_88631048((ts4_word)a0);
}

/* Swing_DLL.xex 0x8888A568: loop_call_seq fn_88622E88, fn_8888A4E8 */
ts4_word ts4_loop_call_seq_fn_88622E88_8888A568(ts4_word a0)
{
    ts4_word lv2;
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_88622E88();
    p5 = (ts4_word)t1;
    if ((ts4_word)(a0 + 5364) != (ts4_word)(a0 + 5340)) {
        lv2 = (ts4_word)(a0 + 5340);
        do {
            t3 = fn_8888A4E8((ts4_word)lv2);
            p4 = (ts4_word)(lv2 + 24);
            lv2 = p4;
        } while ((ts4_word)p4 != (ts4_word)(a0 + 5364));
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x888903B0: addr lbl_880DCE3C, u16@0x6, u32@0x0, u32@0x8, u8@0xc, u32@0x8 */
void ts4_addr_lbl_880DCE3C_888903B0(ts4_word a0, ts4_word a1)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCE3C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88890B80: tailcall fn_888860A0 */
ts4_word ts4_tailcall_fn_888860A0_88890B80(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_888860A0((ts4_word)a1);
}

/* Swing_DLL.xex 0x88890E00: if_tailcall fn_888860A0 */
ts4_word ts4_if_tailcall_fn_888860A0_88890E00(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_888860A0((ts4_word)a1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88891878: if_addr lbl_880CF7F8 */
ts4_word ts4_if_addr_lbl_880CF7F8_88891878(ts4_word a0)
{
    unsigned char t1;

    if ((int)((int)a0 >> 8) <= 223) {
        if ((int)((int)a0 >> 8) < 216) {
            if ((int)((int)a0 >> 8) != 0) {
                return a0;
            }
            t1 = *(unsigned char *)((char *)(ts4_word)(((ts4_word)lbl_880CF7F8 + 76)) + a0);
            if ((ts4_word)t1 != 0) {
                return a0;
            }
            return -1;
        }
        return -1;
    }
    if ((int)((int)a0 >> 8) != 255) {
        return a0;
    }
    if ((ts4_word)a0 != 65534) {
        if ((ts4_word)a0 != 65535) {
            return a0;
        }
        return -1;
    }
    return -1;
}

/* Swing_DLL.xex 0x88894B30: addr lbl_88C6ADC8, fn_88891310 */
ts4_word ts4_addr_lbl_88C6ADC8_88894B30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_88891310((ts4_word)(ts4_word)lbl_88C6ADC8, (ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88894B80: addr lbl_88C6ADAC, fn_88891310 */
ts4_word ts4_addr_lbl_88C6ADAC_88894B80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_88891310((ts4_word)(ts4_word)lbl_88C6ADAC, (ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x888A09C8: if_get u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A09C8(ts4_word a0, int a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 == 0 && (int)a1 == 28) {
        return 59;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
    return -1;
}

/* Swing_DLL.xex 0x888A0A00: if_get u32@0x10, fn_888A10A0, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A0A00(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 25) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A10A0;
        return 58;
    }
    return 0;
}

/* Swing_DLL.xex 0x888A0A60: if_get u32@0x10, u32@0xc, fn_888A10A0, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_if_get_u32_off10_888A0A60(ts4_word a0, int a1)
{
    int t3;
    ts4_word t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 25) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t3 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A10A0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t2 + 1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x888A0BB0: if_get u32@0x10, fn_888A19F0, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A0BB0(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A19F0;
        return 38;
    }
    return 33;
}

/* Swing_DLL.xex 0x888A0D60: if_addr ts4_if_get_u32_off10_888A0DD8, u32@0x0, u32@0x10, fn_888A0C10, u32@0x0, u32@0x10 */
ts4_word ts4_if_addr_fn_888A0DD8_888A0D60(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 21) {
            if ((int)a1 != 24) {
                t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                if ((int)t2 == 0 && (int)a1 == 28) {
                    return 59;
                }
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
                return -1;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A0C10;
            return 33;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A0DD8;
        return 33;
    }
    return 33;
}

/* Swing_DLL.xex 0x888A0E38: if_get u32@0x10, ts4_if_get_u32_off10_888A0DD8, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A0E38(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 23) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A0DD8;
        return 33;
    }
    return 33;
}

/* Swing_DLL.xex 0x888A0E90: if_addr fn_888A0F08, u32@0x0, u32@0x10, fn_888A0C10, u32@0x0, u32@0x10 */
ts4_word ts4_if_addr_fn_888A0F08_888A0E90(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 21) {
            if ((int)a1 != 24) {
                t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                if ((int)t2 == 0 && (int)a1 == 28) {
                    return 59;
                }
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
                return -1;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A0C10;
            return 33;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A0F08;
        return 33;
    }
    return 33;
}

/* Swing_DLL.xex 0x888A1158: if_addr fn_888A10A0, u32@0x0, fn_888A10A0 */
ts4_word ts4_if_addr_fn_888A10A0_888A1158(ts4_word a0, int a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A10A0;
    if ((int)a1 == 12) {
        return 57;
    }
    return fn_888A10A0((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x888A1540: if_addr ts4_if_get_u32_off10_888A15C0, u32@0x0, u32@0x10, fn_888A1200, u32@0x8, u32@0x0 */
ts4_word ts4_if_addr_fn_888A15C0_888A1540(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 21) {
            if ((int)a1 != 36) {
                t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                if ((int)t2 == 0 && (int)a1 == 28) {
                    return 59;
                }
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
                return -1;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)39;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1200;
            return 46;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A15C0;
        return 39;
    }
    return 39;
}

/* Swing_DLL.xex 0x888A1988: if_get u32@0x10, ts4_prolog_element_content_spec_888A1858, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A1988(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18 && (int)a1 != 41) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_prolog_element_content_spec_888A1858;
        return 40;
    }
    return 39;
}

/* Swing_DLL.xex 0x888A1A90: if_get u32@0x10, fn_888A19F0, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A1A90(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18 && (int)a1 != 41) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A19F0;
        return 34;
    }
    return 33;
}

/* Swing_DLL.xex 0x888A1BA0: if_get u32@0x10, fn_888A1200, u32@0x8, u32@0x0, u32@0x10, ts4_fn_888A09C0 */
ts4_word ts4_if_get_u32_off10_888A1BA0(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)17;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1200;
        return 19;
    }
    return 17;
}

/* Swing_DLL.xex 0x888A1C08: if_get u32@0x10, fn_888A1AF8, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A1C08(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1AF8;
        return 21;
    }
    return 17;
}

/* Swing_DLL.xex 0x888A1D50: if_get u32@0x10, fn_888A1C68, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A1D50(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1C68;
        return 18;
    }
    return 17;
}

/* Swing_DLL.xex 0x888A1E30: if_get u32@0x10, fn_888A1DB0, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A1E30(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1DB0;
        return 13;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A2000: if_get u32@0x10, fn_888A1200, u32@0x8, u32@0x0, u32@0x10, ts4_fn_888A09C0 */
ts4_word ts4_if_get_u32_off10_888A2000(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)11;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1200;
        return 16;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A2150: if_get u32@0x10, fn_888A2068, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A2150(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A2068;
        return 13;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A2320: if_get u32@0x10, ts4_prolog_entity_external_or_value_888A1EF0, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A2320(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_prolog_entity_external_or_value_888A1EF0;
        return 10;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A23F8: if_get u32@0x10, fn_888A1178, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A23F8(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 17) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1178;
        return 8;
    }
    return 3;
}

/* Swing_DLL.xex 0x888A2680: if_addr fn_888A1178, u32@0x0, u32@0x10, fn_888A2458, u32@0x0, u32@0x10 */
ts4_word ts4_if_addr_fn_888A1178_888A2680(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 17) {
            if ((int)a1 != 25) {
                t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                if ((int)t2 == 0 && (int)a1 == 28) {
                    return 59;
                }
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
                return -1;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A2458;
            return 7;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A1178;
        return 8;
    }
    return 3;
}

/* Swing_DLL.xex 0x888A2760: if_get u32@0x10, ts4_if_get_u32_off10_888A2700, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A2760(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A2700;
        return 6;
    }
    return 3;
}

/* Swing_DLL.xex 0x888A2928: if_get u32@0x10, fn_888A27C0, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A2928(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18 && (int)a1 != 41) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_888A27C0;
        return 4;
    }
    return 3;
}

/* Swing_DLL.xex 0x888A2C30: addr ts4_token_classify_888A2AC8, u32@0xc, u32@0x10, u32@0x0, u32@0x14 */
void ts4_addr_fn_888A2AC8_888A2C30(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_token_classify_888A2AC8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888A3840: loop_get u32@0x0, u32@0x14, u32@0x0, u32@0x8, vcall, u32@0x4 */
ts4_word ts4_loop_get_u32_off0_888A3840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p7;
    ts4_word lv10;
    ts4_word p15;
    ts4_word p16;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
            t4 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 8))))((ts4_word)lv2);
            p7 = (ts4_word)t4;
            lv2 = p7;
        } while ((ts4_word)p7 != 0);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p16 = (ts4_word)t9;
    if ((ts4_word)t9 != 0) {
        lv10 = (ts4_word)t9;
        do {
            t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
            t12 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t11) + 8))))((ts4_word)lv10);
            p15 = (ts4_word)t12;
            lv10 = p15;
        } while ((ts4_word)p15 != 0);
        p16 = (ts4_word)lv10;
    }
    return p16;
}

/* Swing_DLL.xex 0x888A4FE0: if_call_seq u32@0x8, u32@0xc, u32@0xc, u8@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off8_888A4FE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t4;
    ts4_word t5;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t2 == (ts4_word)t1) {
        t6 = ts4_xml_pool_grow_888A2F00();
        if ((ts4_word)(t6 & 0xff) == 0) {
            return 0;
        }
        *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12))) + 0) = (unsigned char)0;
        t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
        t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t8 + 1);
        return t9;
    }
    *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12))) + 0) = (unsigned char)0;
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t4 + 1);
    return t5;
}

/* Swing_DLL.xex 0x888AA490: if_call_seq ts4_if_get_u8_offec_888A8610, u32@0x160, u8@0x83, u32@0x114, fn_888AA228, u32@0x118 */
ts4_word ts4_if_call_seq_fn_888A8610_888AA490(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    int t1;
    int t3;
    ts4_word t5;
    ts4_word t4;

    t1 = ts4_if_get_u8_offec_888A8610();
    if ((int)t1 == 0) {
        *(volatile unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 352))) + 131) = (unsigned char)1;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
        if ((int)t3 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)fn_888AA328;
            t5 = fn_888AA328((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
            return t5;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)fn_888AA228;
        t4 = fn_888AA228((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        return t4;
    }
    return t1;
}

/* Swing_DLL.xex 0x888B0C50: if_call_seq lbl_880DC810, u32@0x0, u32@0x80, ts4_destroy_owned_object, lbl_880DC550, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880DC810_888B0C50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC810;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC550;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888B1CB8: if_call_seq lbl_880DC614, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880DC614_888B1CB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC614;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888B1D08: call_seq fn_88617D88, lbl_880DC614, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888B1D08(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC614;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888B82A8: if_call_seq lbl_880DC614, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880DC614_888B82A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC614;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888B8F10: call_seq lbl_880DC5DC, u32@0x0, u32@0x48, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_call_seq_lbl_880DC5DC_888B8F10(ts4_word a0)
{
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC5DC;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 72)));
    t3 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x888B93A8: if_call_seq lbl_880DC6B8, u32@0x0, u32@0x3c, ts4_destroy_owned_object, lbl_880DC614, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880DC6B8_888B93A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC6B8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC614;
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x888BFBC8: if_get  */
ts4_word ts4_if_get_888BFBC8(float f1)
{
    float t1;
    float t2;

    t1 = *(float *)lbl_880D0934;
    if (!(f1 > t1)) {
        return 1;
    }
    t2 = *(float *)lbl_880D0938;
    if (!(f1 < t2)) {
        return 3;
    }
    return 2;
}

/* Swing_DLL.xex 0x888BFC80: loop_call_seq u32@0x0, u32@0x4, fn_8857B4C8 */
ts4_word ts4_loop_call_seq_u32_off0_888BFC80(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word p7;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)(a0 + 13000)) {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        p5 = (ts4_word)t2;
        if ((ts4_word)t2 != 0 && (int)a1 != (int)(*(ts4_word *)((char *)(ts4_word)(lv1) + 4))) {
            t4 = fn_8857B4C8((ts4_word)t2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)(lv1 + 520);
        lv1 = p6;
        p7 = (ts4_word)p5;
    }
    return p7;
}

/* Swing_DLL.xex 0x888BFCE0: set u8@lbl_88C46F6A */
void ts4_set_u8_lbl_88C46F6A_888BFCE0(void)
{
    *(volatile unsigned char *)lbl_88C46F6A = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888BFD88: call_seq u32@0x0, u32@0x4, fn_882C7288, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_u32_off0_888BFD88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc90[8];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = fn_882C7288((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)t1, (ts4_word)-2, (ts4_word)-2, (ts4_word)0, (ts4_word)0, (ts4_word)-1, (ts4_word)0, (ts4_word)3, (ts4_word)3, (ts4_word)0, (ts4_word)(ts4_word)&loc90[0], (ts4_word)0, (ts4_word)(a2 + 8));
    t4 = loc90[0];
    t5 = loc90[1];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)t5;
    return t3;
}

/* Swing_DLL.xex 0x888C00F0: get u32@0x80 */
void ts4_get_u32_off80_888C00F0(ts4_word a0, float f1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    *(volatile float *)((char *)(ts4_word)(t1) + 128) = ((*(float *)((char *)(ts4_word)(t1) + 128)) + f1);
    return;
}

/* Swing_DLL.xex 0x888C03D8: get u32@0x1c, u32@0x88, u32@0x84 */
ts4_word ts4_get_u32_off1c_888C03D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 136);
    return ((int)(t2 - (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 132))) / (int)132);
}

/* Swing_DLL.xex 0x888C07B0: set u32@0x1c, u32@0x20, ts4_object_finalize */
ts4_word ts4_set_u32_off1c_888C07B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return ts4_object_finalize((ts4_word)(a0 + 52));
}

/* Swing_DLL.xex 0x888C0930: if_get u32@0x20, u8@0x0, u8@0x0, u32@0x2c, u32@0x2c, u32@0x2c */
void ts4_if_get_u32_off20_888C0930(ts4_word a0)
{
    int t1;
    unsigned char t3;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t1 == 0) {
        return;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t3 != 1) {
        return;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t5 != 0) {
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x888C0E18: if_get u32@lbl_88D45B1C, u32@0x27c, u32@0x4, u32@0x44, u32@0x10, u8@0x44 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_888C0E18(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
    p3 = (ts4_word)0;
    if (((ts4_word)a1 != (ts4_word)t2 && (ts4_word)a1 != (ts4_word)((2187984896) | 26323)) && (ts4_word)a1 == (ts4_word)((1186791424) | 6071)) {
        p3 = (ts4_word)1;
    }
    if ((ts4_word)(p3 & 0xff) != 1) {
        return p3;
    }
    *(volatile unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 68))) + 16))) + 68) = (unsigned char)1;
    return p3;
}

/* Swing_DLL.xex 0x888C0FA0: if_call_seq fn_8817E150, u32@0x0, u32@0x4, u32@0x0, fn_8817E150, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8817E150_888C0FA0(ts4_word a0, ts4_word a1)
{
    ts4_word p15;
    ts4_word p20;
    ts4_word loc50[1];
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

    t1 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 108), (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)(t3 & t4) != 0) {
        t5 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 128), (ts4_word)a1);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        if ((ts4_word)(t7 & t8) == 0) {
            t9 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 128), (ts4_word)a1);
            t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
            t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
            *(volatile ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)(t11 | (*(ts4_word *)((char *)(ts4_word)(t10) + 0)));
            p15 = (ts4_word)1;
        } else {
            p15 = (ts4_word)0;
        }
        p20 = (ts4_word)p15;
    } else {
        p20 = (ts4_word)0;
    }
    return p20;
}

/* Swing_DLL.xex 0x888C1140: if_call_seq fn_8817E150, u32@0x0, u32@0x4, u32@0x0, fn_8817E150, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8817E150_888C1140(ts4_word a0, ts4_word a1)
{
    ts4_word p15;
    ts4_word p20;
    ts4_word loc50[1];
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

    t1 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 68), (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)(t3 & t4) != 0) {
        t5 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 88), (ts4_word)a1);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        if ((ts4_word)(t7 & t8) == 0) {
            t9 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 88), (ts4_word)a1);
            t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
            t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
            *(volatile ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)(t11 | (*(ts4_word *)((char *)(ts4_word)(t10) + 0)));
            p15 = (ts4_word)1;
        } else {
            p15 = (ts4_word)0;
        }
        p20 = (ts4_word)p15;
    } else {
        p20 = (ts4_word)0;
    }
    return p20;
}

/* Swing_DLL.xex 0x888C1200: if_call_seq fn_8817E150, u32@0x0, u32@0x4, u32@0x0, fn_8817E150, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8817E150_888C1200(ts4_word a0, ts4_word a1)
{
    ts4_word p15;
    ts4_word p20;
    ts4_word loc50[1];
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

    t1 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 28), (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)(t3 & t4) != 0) {
        t5 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 48), (ts4_word)a1);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        if ((ts4_word)(t7 & t8) == 0) {
            t9 = fn_8817E150((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 48), (ts4_word)a1);
            t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
            t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
            *(volatile ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)(t11 | (*(ts4_word *)((char *)(ts4_word)(t10) + 0)));
            p15 = (ts4_word)1;
        } else {
            p15 = (ts4_word)0;
        }
        p20 = (ts4_word)p15;
    } else {
        p20 = (ts4_word)0;
    }
    return p20;
}

/* Swing_DLL.xex 0x888C1758: if_get u32@0x0, u32@0x0, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_888C1758(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 <= (ts4_word)((1255145472) | 53041)) {
        if ((ts4_word)t1 != (ts4_word)((1255145472) | 53041)) {
            if ((ts4_word)t1 != 0 && (ts4_word)t1 == (ts4_word)((942997504) | 47862)) {
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2567110656) | 30629);
                return;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
            return;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3657039872) | 6967);
        return;
    }
    if ((ts4_word)t1 != (ts4_word)((3081895936) | 13899)) {
        if ((ts4_word)t1 != (ts4_word)((3554213888) | 40587)) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
            return;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((4118282240) | 1402);
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((4235132928) | 22433);
    return;
}

/* Swing_DLL.xex 0x888C1800: if_get g_ts4_script_constants */
ts4_word ts4_if_get_g_ts4_script_constants_888C1800(ts4_word a0)
{
    float t1;
    float t2;
    double t3;
    double t4;

    t1 = *(float *)((char *)(ts4_word)(a0) + 100);
    t2 = *(float *)lbl_880D0934;
    if (!(t1 > t2)) {
        return 0;
    }
    t3 = *(double *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 792);
    if (t1 > t3) {
        t4 = *(double *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 800);
        if (!(t1 > t4)) {
            return 1;
        }
        return 2;
    }
    return 2;
}

/* Swing_DLL.xex 0x888C2458: get u32@0x28, u32@0x0 */
ts4_word ts4_get_u32_off28_888C2458(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    return ((((int)a1 * 100) + (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + t1);
}

/* Swing_DLL.xex 0x888C2470: get u32@0x1c, u32@0x0 */
ts4_word ts4_get_u32_off1c_888C2470(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    return ((((int)a1 * 176) + (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + t1);
}

/* Swing_DLL.xex 0x888C32E8: if_call_seq ts4_find_service, u32@0x0, u32@0x0, u32@0x24, u32@0x20, ts4_forward_to_fn_8841B5E0 */
ts4_word ts4_if_call_seq_ts4_find_service_888C32E8(ts4_word a0)
{
    ts4_word p6;
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    t1 = ts4_find_service((ts4_word)((1680605184) | 34887));
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t3 == (ts4_word)((4020830208) | 36533)) {
            p6 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 32));
        } else {
            p6 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 36));
        }
        t7 = ts4_forward_to_fn_8841B5E0((ts4_word)p6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x888C3430: get u32@lbl_88D45908, u32@0x54, u32@0x0, u16@0x42 */
ts4_word ts4_get_u32_lbl_88D45908_888C3430(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45908)) + 84);
    return (*(unsigned short *)((char *)(ts4_word)(((((int)a0 * 68) + (*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + t2)) + 66));
}

/* Swing_DLL.xex 0x888C3458: get u32@lbl_88D45908, u32@0x54, u32@0x0, u16@0x40 */
ts4_word ts4_get_u32_lbl_88D45908_888C3458(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45908)) + 84);
    return (*(unsigned short *)((char *)(ts4_word)(((((int)a0 * 68) + (*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + t2)) + 64));
}

/* Swing_DLL.xex 0x888C3480: get u32@lbl_88D45908, u32@0x54, u32@0x0, u32@0x3c, u32@0x0 */
void ts4_get_u32_lbl_88D45908_888C3480(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45908)) + 84);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((((int)a1 * 68) + (*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + t2)) + 60));
    return;
}

/* Swing_DLL.xex 0x888C38E0: tailcall fn_888C3768 */
ts4_word ts4_tailcall_fn_888C3768_888C38E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_888C3768((ts4_word)((((int)a1 * 84) + a0) + 4), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Swing_DLL.xex 0x888C3AC8: get u32@0x54, u32@0x50, u32@0x0 */
void ts4_get_u32_off54_888C3AC8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 0) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x888C43D0: addr lbl_880D6B70, u32@0x0, u32@0x8, u32@0xc, ts4_find_service, u32@0x0 */
ts4_word ts4_addr_lbl_880D6B70_888C43D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    t1 = ts4_find_service((ts4_word)((1670447104) | 60230));
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t4;
    *(volatile ts4_word *)((char *)(ts4_word)(t4) + 32) = (ts4_word)(*(ts4_word *)lbl_88C6B8F4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(t6) + 36) = (ts4_word)(*(ts4_word *)lbl_88C6B90C);
    return a0;
}

/* Swing_DLL.xex 0x888C4638: loop_get u32@0x1c, u32@0x18, u32@0x0, u32@0x4, u32@0x0, u32@0x28 */
ts4_word ts4_loop_get_u32_off1c_888C4638(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
            t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)t4, (ts4_word)lv3, (ts4_word)t5, (ts4_word)4);
            *(volatile ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)a1;
            p9 = (ts4_word)(lv3 + 12);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t1);
        p10 = (ts4_word)t8;
    }
    return p10;
}

/* Swing_DLL.xex 0x888C7178: set u32@0x14, u32@0x18, u32@0x1c, u32@0x20, u32@0x24, u32@0x28 */
void ts4_set_u32_off14_888C7178(ts4_word a0)
{
    float t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 44) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C77D8: tailcall fn_888C7718 */
ts4_word ts4_tailcall_fn_888C7718_888C77D8(ts4_word a0, ts4_word a1)
{
    return fn_888C7718((ts4_word)((((int)a1 * 84) + a0) + 4), (ts4_word)a1);
}

/* Swing_DLL.xex 0x888C94D8: set u32@0x90, u32@0x98, u32@0x94, u32@0x9c, u32@0xa4, u32@0xa0 */
ts4_word ts4_set_u32_off90_888C94D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)((983040) | 65535);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x888C9618: call_seq fn_88617D88, lbl_880DB80C, u8@0x1e, u8@0x1d, u32@0x0, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_888C9618(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB80C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888CA8B0: call_seq fn_88617D88, lbl_880DB228, u32@0x0, u32@0x22c, u32@0x230 */
ts4_word ts4_call_seq_fn_88617D88_888CA8B0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB228;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 560) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888CA9A0: call_seq fn_88617D88, lbl_880DB200, u32@0x0, u32@0x2c, u32@0x30, u32@0x34 */
ts4_word ts4_call_seq_fn_88617D88_888CA9A0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB200;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 72) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D45948 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x888CB568: if_call_seq u32@0x2c, u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off2c_888CB568(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word loc60[772];
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t4 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t1);
    if ((ts4_word)t4 != 0) {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 16));
    } else {
        p6 = (ts4_word)-1;
    }
    ts4_tailcall_XamContentCreateEnumerator_8857B2F0((ts4_word)p6, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)1, (ts4_word)0, (ts4_word)10, (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    t9 = loc50[0];
    ts4_tailcall_XamEnumerate_8857A1C8((ts4_word)t9, (ts4_word)(ts4_word)&loc60[0], (ts4_word)3080, (ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t11 = loc50[0];
    t12 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t11);
    return t12;
}

/* Swing_DLL.xex 0x888CB810: if_call_seq lbl_880DBCDC, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880DBCDC_888CB810(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBCDC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888CB860: call_seq fn_88617D88, lbl_880DBCDC, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888CB860(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBCDC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888CB8F0: if_get u32@0x1c, u32@0x20, fn_8817DF90 */
ts4_word ts4_if_get_u32_off1c_888CB8F0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_8817DF90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x888CBD18: set u32@0x208, u8@0x1fc, u32@0x204, u32@0x200, u8@0x8, fn_881B9148 */
ts4_word ts4_set_u32_off208_888CBD18(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 520) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 508) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 516) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 512) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x888CBD50: call_seq fn_88617D88, lbl_880DB5F8, u32@0x200, u8@0x1fc, u32@0x0, u32@0x204 */
ts4_word ts4_call_seq_fn_88617D88_888CBD50(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 512) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 508) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB5F8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 516) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 520) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888CCF48: if_call_seq lbl_880DB370, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880DB370_888CCF48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB370;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888CE890: addr lbl_88D45CC0, u32@lbl_88D45B1C, u32@0x270, u32@0x150, u32@0x158, u32@0x8 */
ts4_word ts4_addr_lbl_88D45CC0_888CE890(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 624);
    *(ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t2 + 60);
    *(unsigned char *)((char *)(ts4_word)(a0) + 408) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)0;
    return fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1668)));
}

/* Swing_DLL.xex 0x888D2968: if_call_seq lbl_880DB2C8, u32@0x0, u32@0xc, ts4_destroy_owned_object, lbl_880DB2A4, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880DB2C8_888D2968(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2C8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_destroy_owned_object((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2A4;
    return p3;
}

/* Swing_DLL.xex 0x888D29B8: set u32@0x4, g_ts4_script_constants, lbl_880DB2C8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_set_u32_off4_888D29B8(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2C8;
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 304));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888D3780: loop_call_seq u32@0x50, fn_888C9A68, u32@0x30, u32@0x20, u32@0x1c, u32@0xec */
ts4_word ts4_loop_call_seq_u32_off50_888D3780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv7;
    ts4_word p9;
    int t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 != 0) {
        fn_888C9A68((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 32);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 28);
    if ((ts4_word)t5 != (ts4_word)t6) {
        lv7 = (ts4_word)t6;
        do {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 236);
            if ((ts4_word)t8 == (ts4_word)((737083392) | 35038)) {
                *(unsigned char *)((char *)(ts4_word)(lv7) + 154) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv7) + 155) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv7) + 240) = (unsigned char)1;
            }
            p9 = (ts4_word)(lv7 + 244);
            lv7 = p9;
        } while ((ts4_word)p9 != (ts4_word)t5);
    }
    t11 = fn_888D3648((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x888D8168: addr lbl_88D45CC0, fn_888CE8D0 */
ts4_word ts4_addr_lbl_88D45CC0_888D8168(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_888CE8D0((ts4_word)(((int)a0 * 412) + ((ts4_word)lbl_88D45CC0 + 12)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((int)a0 * 412));
}

/* Swing_DLL.xex 0x888D8558: call_seq ts4_call_seq_u32_off0_8817B998, fn_8817EA90, fn_888D84B8, ts4_if_call_seq_u32_off4_8817E430 */
ts4_word ts4_call_seq_fn_8817B998_888D8558(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t4;

    ts4_call_seq_u32_off0_8817B998((ts4_word)(ts4_word)&loc50[0]);
    fn_8817EA90((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_888D84B8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)&loc60[0]);
    t4 = ts4_if_call_seq_u32_off4_8817E430((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x888D8630: call_seq ts4_call_seq_u32_off0_8817B998, fn_8817EA90, ts4_if_call_seq_fn_8817EA90_888D85B0, ts4_if_call_seq_u32_off4_8817E430 */
ts4_word ts4_call_seq_fn_8817B998_888D8630(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t4;

    ts4_call_seq_u32_off0_8817B998((ts4_word)(ts4_word)&loc50[0]);
    fn_8817EA90((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    ts4_if_call_seq_fn_8817EA90_888D85B0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc60[0]);
    t4 = ts4_if_call_seq_u32_off4_8817E430((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x888D8AC8: if_call_seq lbl_880DBD58, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880DBD58_888D8AC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBD58;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888D8B18: call_seq fn_88617D88, lbl_880DBD58, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888D8B18(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBD58;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888DAF90: loop_get fn_888D7920, u32@0x26c, u32@0x268, u32@0x0, fn_888CCFF0, u32@0x0 */
ts4_word ts4_loop_get_fn_888D7920_888DAF90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p2;
    ts4_word lv5;
    ts4_word p12;
    ts4_word p13;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    p2 = (ts4_word)a0;
    if ((ts4_word)a2 == (ts4_word)((1089536000) | 26408)) {
        t1 = fn_888D7920();
        p2 = (ts4_word)t1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 620);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 616);
    p13 = (ts4_word)p2;
    if ((ts4_word)t3 != (ts4_word)t4) {
        lv5 = (ts4_word)t4;
        do {
            fn_888CCFF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0)));
            t8 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 16))))((ts4_word)t8);
            p12 = (ts4_word)(lv5 + 4);
            lv5 = p12;
        } while ((ts4_word)p12 != (ts4_word)t3);
        p13 = (ts4_word)t11;
    }
    return p13;
}

/* Swing_DLL.xex 0x888DC460: call_seq lbl_880DB8DC, u32@0x0, u32@0x68, ts4_destroy_owned_object, u32@0x5c, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880DB8DC_888DC460(ts4_word a0)
{
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB8DC;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 104)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 92)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 72)));
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x888DC4F8: call_seq lbl_880DB7E4, u32@0x0, u32@0xe8, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_call_seq_lbl_880DB7E4_888DC4F8(ts4_word a0)
{
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB7E4;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 232)));
    t3 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x888DC900: call_seq lbl_880DB794, u32@0x0, u32@0x58, ts4_destroy_owned_object, u32@0x4c, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880DB794_888DC900(ts4_word a0)
{
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB794;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 88)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 76)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 64)));
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x888DC958: call_seq lbl_880DB580, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_call_seq_lbl_880DB580_888DC958(ts4_word a0)
{
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB580;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t3 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x888DDA80: loop_call_seq u32@0x18, u32@0x14, u32@0x8, ts4_if_atomic_interlocked_dec_88288530 */
ts4_word ts4_loop_call_seq_u32_off18_888DDA80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p8 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 8);
            p6 = (ts4_word)t4;
            if ((ts4_word)t4 != 0) {
                t5 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)t4);
                p6 = (ts4_word)t5;
            }
            p7 = (ts4_word)(lv3 + 12);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t1);
        p8 = (ts4_word)p6;
    }
    return p8;
}

/* Swing_DLL.xex 0x888DDB70: if_call_seq lbl_880DB408, u32@0x0, u32@0x6c, ts4_destroy_owned_object, lbl_880DB3C0, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880DB408_888DDB70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB408;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB3C0;
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888DDBC8: call_seq fn_88617D88, lbl_880DB408, u32@0x0, u32@0x1c, u32@0x24, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_888DDBC8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB408;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D4591C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x888DDCE0: if_call_seq lbl_880DBEB8, u32@0x0, u32@0x28, ts4_destroy_owned_object, u32@0x1c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DBEB8_888DDCE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBEB8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t8 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return t8;
}

/* Swing_DLL.xex 0x888DE0B8: if_call_seq lbl_880DB2D8, u32@0x0, u32@0xc0, u32@0xbc, ts4_loop_call_seq_u32_off0_88150378, u32@0xbc */
ts4_word ts4_if_call_seq_lbl_880DB2D8_888DE0B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t8;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2D8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 192);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 188)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 188);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    fn_881A6A00((ts4_word)(a0 + 88));
    t8 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x888DE368: if_call_seq u8@0x8, fn_881B9148, lbl_880D9AA4, ts4_assign_formatted_text, lbl_880D9AB8, ts4_assign_formatted_text */
ts4_word ts4_if_call_seq_u8_off8_888DE368(ts4_word a0)
{
    ts4_word loc70[6];
    ts4_word loc60[4];
    ts4_word loc50[4];
    unsigned char t5;
    unsigned char t8;
    ts4_word t12;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)lbl_880D9AA4);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880D9AB8);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D9B50);
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t5 != 0) {
        ts4_if_get_u32_lbl_88D45B1C_888C0198((ts4_word)(ts4_word)&loc70[0]);
    }
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 61);
    if ((ts4_word)t8 != 0) {
        ts4_if_get_u32_lbl_88D45B1C_888C0198((ts4_word)(ts4_word)&loc60[0]);
    }
    ts4_if_get_u32_lbl_88D45B1C_888C0198((ts4_word)(ts4_word)&loc50[0]);
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 57) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 58) = (unsigned char)0;
    t12 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t12);
    t14 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t14);
    t16 = loc70[0];
    t17 = ts4_destroy_owned_object((ts4_word)t16);
    return t17;
}

/* Swing_DLL.xex 0x888DED18: if_call_seq lbl_880DB530, u32@0x0, u32@0x68, u32@0x64, ts4_loop_call_seq_u32_off0_88150378, u32@0x64 */
ts4_word ts4_if_call_seq_lbl_880DB530_888DED18(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB530;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 100)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x888DEF98: if_call_seq u32@0x1c, u32@0x60, u32@0x26c, u8@0x13d, fn_888DD008, u8@0x13c */
ts4_word ts4_if_call_seq_u32_off1c_888DEF98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 620)) == (ts4_word)((966918144) | 43504)) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 317) = (unsigned char)0;
        t4 = fn_888DD008((ts4_word)a0, (ts4_word)0, (ts4_word)(a0 + 352));
        if ((ts4_word)t4 != 0) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 316) = (unsigned char)1;
        }
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x888DF330: if_call_seq lbl_880DB350, u32@0x0, u32@0x268, ts4_destroy_owned_object, ts4_loop_call_seq_lbl_880D6268_8892AF80, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880DB350_888DF330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB350;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 616);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(a0 + 8));
    t5 = fn_8860BBD8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x888DF960: loop_call_seq lbl_880DB744, u32@0x0, u32@0x30, u32@0x2c, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_lbl_880DB744_888DF960(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t9;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB744;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0)));
            p6 = (ts4_word)(lv3 + 92);
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t1);
    }
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t9 != 0) {
        ts4_destroy_owned_object((ts4_word)t9);
    }
    t12 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t12;
}

/* Swing_DLL.xex 0x888E1EE0: call_seq fn_88617D88, lbl_880DB490, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888E1EE0(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB490;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D45954 = (ts4_word)a0;
    fn_888C93E8((ts4_word)a0);
    t3 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880DA718);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)t4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)t5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)t6;
    return a0;
}

/* Swing_DLL.xex 0x888E2098: call_seq u32@0x0, u32@0x0, fn_88564F40, fn_8862C0E8, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_888E2098(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc60[64];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t8;
    ts4_word t11;
    ts4_word t15;
    ts4_word t18;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    fn_88564F40((ts4_word)(ts4_word)&loc60[0], (ts4_word)256, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)), (ts4_word)t1);
    t4 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    *(ts4_word *)((char *)(ts4_word)(a5) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
    *(ts4_word *)((char *)(ts4_word)(a5) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    fn_88564F40((ts4_word)(ts4_word)&loc60[0], (ts4_word)256, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0)), (ts4_word)t8);
    t11 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    *(ts4_word *)((char *)(ts4_word)(a6) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 0));
    *(ts4_word *)((char *)(ts4_word)(a6) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 4));
    *(ts4_word *)((char *)(ts4_word)(a6) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 8));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    fn_88564F40((ts4_word)(ts4_word)&loc60[0], (ts4_word)256, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 0)), (ts4_word)t15, (ts4_word)t11);
    t18 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    *(ts4_word *)((char *)(ts4_word)(a7) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t18) + 0));
    *(ts4_word *)((char *)(ts4_word)(a7) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t18) + 4));
    *(ts4_word *)((char *)(ts4_word)(a7) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t18) + 8));
    return t18;
}

/* Swing_DLL.xex 0x888E78B8: tailcall fn_888E7720 */
ts4_word ts4_tailcall_fn_888E7720_888E78B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    (void)a3;
    return fn_888E7720((ts4_word)((((int)a1 * 84) + a0) + 4), (ts4_word)a2, (ts4_word)a4, (ts4_word)a5);
}

/* Swing_DLL.xex 0x888E8980: if_call_seq lbl_880DBD80, u32@0x0, u32@0x20, u32@0x1c, ts4_loop_call_seq_u32_off40_881815A8, u32@0x1c */
ts4_word ts4_if_call_seq_lbl_880DBD80_888E8980(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBD80;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    ts4_loop_call_seq_u32_off40_881815A8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x888F0718: set u32@0x0, u32@0x8, u32@0x4, fn_8817EE38 */
ts4_word ts4_set_u32_off0_888F0718(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    return fn_8817EE38((ts4_word)(a0 + 4), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
}

/* Swing_DLL.xex 0x888F0738: if_call_seq u32@0x0, u32@0x8, u32@0x4, fn_8817EE38, u32@0x8, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_888F0738(ts4_word a0)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    fn_8817EE38((ts4_word)(a0 + 4), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    ts4_loop_call_seq_u32_0x4_88181670((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t4);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = ts4_destroy_owned_object((ts4_word)t7);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x888F0828: loop_call_seq fn_888EC548, u32@0x0, u32@0x0, u32@0x4, u8@0x18 */
ts4_word ts4_loop_call_seq_fn_888EC548_888F0828(void)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word lv7;
    ts4_word p8;
    ts4_word t1;
    int t3;

    t1 = fn_888EC548();
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        p5 = (ts4_word)0;
        if ((int)t3 != -1) {
            p5 = (ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)) * 28) + t3) + t1);
        }
        p6 = (ts4_word)0;
        if ((int)t3 != -1) {
            p6 = (ts4_word)(t3 + t1);
        }
        lv7 = (ts4_word)p6;
        while ((ts4_word)lv7 != (ts4_word)p5) {
            *(unsigned char *)((char *)(ts4_word)(lv7) + 24) = (unsigned char)0;
            p8 = (ts4_word)(lv7 + 28);
            lv7 = p8;
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x888F1988: get u32@0x60, u32@0x268, u32@0x60, u32@0x264, u32@0x1c, fn_888719E0 */
ts4_word ts4_get_u32_off60_888F1988(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 616) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 612) = (ts4_word)a1;
    return fn_888719E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x888F1D50: call_seq u32@0x0, lbl_880D0830, u32@0x0, fn_88290C68, u32@0xc, fn_882908C0 */
ts4_word ts4_call_seq_u32_off0_888F1D50(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    float t7;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    t2 = fn_88290C68((ts4_word)((ts4_word)lbl_880D0830 + -360));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t2;
    t3 = fn_882908C0((ts4_word)(ts4_word)lbl_880D0830);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t3;
    fn_888F1B30((ts4_word)a0);
    fn_888CD2B8((ts4_word)a0, (ts4_word)a1);
    t6 = fn_888CD190((ts4_word)a0);
    t7 = *(float *)((char *)(ts4_word)(a1) + 28);
    *(float *)((char *)(ts4_word)(a0) + 44) = ((*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 1084)) / t7);
    return t6;
}

/* Swing_DLL.xex 0x888F3338: if_addr ts4_if_call_seq_u32_lbl_88D459E4_8883F238, lbl_880D1CE0, fn_8886B1B0, u32@0x0, u32@0x28, vcall */
ts4_word ts4_if_addr_fn_8883F238_888F3338(ts4_word a0, ts4_word a1)
{
    ts4_word p21;
    ts4_word locc0[128];
    ts4_word loc50[4];
    ts4_word loc60[24];
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;
    ts4_word t16;
    ts4_word t20;

    t1 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    fn_8886B1B0((ts4_word)a1, (ts4_word)(ts4_word)&locc0[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880D1CE0, (ts4_word)1);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(ts4_word)&locc0[0], (ts4_word)3072, (ts4_word)0);
    t6 = loc50[0];
    p21 = (ts4_word)t5;
    if ((ts4_word)t6 != 0) {
        ts4_call_seq_fn_88617D88_8892AFF0((ts4_word)(ts4_word)&loc60[0]);
        t8 = loc50[0];
        ts4_if_get_u32_off0_8892FE20((ts4_word)(ts4_word)&loc60[0], (ts4_word)t8, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        t10 = loc60[0];
        t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t10) + 76))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
        fn_888CF650((ts4_word)a0, (ts4_word)(t12 + 128), (ts4_word)0);
        fn_88929E70((ts4_word)(ts4_word)&loc60[0]);
        t15 = loc50[0];
        t16 = *(ts4_word *)((char *)(ts4_word)(t15) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 88))))((ts4_word)t16, (ts4_word)(ts4_word)&loc50[0]);
        *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)1;
        t20 = ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(ts4_word)&loc60[0]);
        p21 = (ts4_word)t20;
    }
    return p21;
}

/* Swing_DLL.xex 0x888F3428: if_call_seq ts4_find_service, u8@0x21, ts4_profile_internal_activate */
ts4_word ts4_if_call_seq_ts4_find_service_888F3428(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = ts4_find_service((ts4_word)((3816161280) | 31446));
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 33)) != 0) {
        t3 = ts4_profile_internal_activate((ts4_word)t1, (ts4_word)a0);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x888F7140: addr lbl_88D45CC0, fn_888F69A0 */
ts4_word ts4_addr_lbl_88D45CC0_888F7140(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    (void)a2;
    return fn_888F69A0((ts4_word)(((int)a0 * 412) + ((ts4_word)lbl_88D45CC0 + 368)), (ts4_word)(a0 & 0xff), (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((int)a0 * 412));
}

/* Swing_DLL.xex 0x888F7AB0: if_call_seq fn_888F7160, lbl_880D49CC, fn_888F7160 */
ts4_word ts4_if_call_seq_fn_888F7160_888F7AB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_888F7160((ts4_word)((((int)a1 * 84) + a0) + 4), (ts4_word)a2, (ts4_word)a3);
    p3 = (ts4_word)t1;
    if ((ts4_word)(t1 & 0xff) == 0) {
        t2 = fn_888F7160((ts4_word)((((int)a1 * 84) + a0) + 4), (ts4_word)a2, (ts4_word)(ts4_word)lbl_880D49CC);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x888FA420: if_call_seq u32@0x2c, u32@0x250, u32@0x48, u32@0x48, fn_888F1170, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off2c_888FA420(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word p14;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    unsigned short t9;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44))) + 592);
    p7 = (ts4_word)a0;
    if ((ts4_word)t2 == (ts4_word)((2622095360) | 5708)) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72);
        p6 = (ts4_word)a0;
        if ((ts4_word)t4 == (ts4_word)((3557425152) | 37427) || (ts4_word)t4 == (ts4_word)((2843541504) | 26230)) {
            t5 = fn_888F1170((ts4_word)a0);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    t9 = *(volatile unsigned short *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 92);
    p14 = (ts4_word)p7;
    if ((ts4_word)(t9 & 0x40) == 64 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 448)) == (ts4_word)((499777536) | 29317)) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)((554106880) | 28964);
        *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 452) = (ts4_word)((2683305984) | 48528);
        t13 = ts4_call_seq_u32_off1c_888F5D50((ts4_word)a0);
        p14 = (ts4_word)t13;
    }
    return p14;
}

/* Swing_DLL.xex 0x888FB7C8: addr lbl_88D45CC0, u32@0x68c, u32@0x0, u32@0x20, vcall, fn_888F69A0 */
ts4_word ts4_addr_lbl_88D45CC0_888FB7C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1676);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(((int)a0 * 412)) + ((ts4_word)lbl_88D45CC0 + 18)) = (unsigned char)a3;
    t5 = fn_888F69A0((ts4_word)(((int)a0 * 412) + ((ts4_word)lbl_88D45CC0 + 368)), (ts4_word)(a0 & 0xff), (ts4_word)a1);
    return t5;
}

/* Swing_DLL.xex 0x88901738: get u32@lbl_88C6B90C, u32@0x8, u32@lbl_88C6B90C, fn_88901010 */
ts4_word ts4_get_u32_lbl_88C6B90C_88901738(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B90C);
    return fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B90C));
}

/* Swing_DLL.xex 0x88901750: if_get u32@0x8, u32@lbl_88C6B918, u32@0xc, fn_889006D8 */
ts4_word ts4_if_get_u32_off8_88901750(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)lbl_88C6B918;
    if ((ts4_word)t1 != (ts4_word)t2) {
        return a0;
    }
    return fn_889006D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x889017B8: if_call_seq lbl_880DBC30, u32@0x0, u32@0x5c, u32@0x58, fn_88187AB8, u32@0x58 */
ts4_word ts4_if_call_seq_lbl_880DBC30_889017B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBC30;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92);
    fn_88187AB8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88901810: call_seq fn_88617D88, lbl_880DBC30, u32@0x0, u32@0x58, u32@0x5c, u32@0x60 */
ts4_word ts4_call_seq_fn_88617D88_88901810(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBC30;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 85) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 100) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 101) = (unsigned char)0;
    t2 = ts4_get_u32__imp_KeTimeStampBundle_8857B830((ts4_word)t1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88903190: loop_call_seq u32@0x50, fn_888C9A68, u32@0x30, u32@0x20, u32@0x1c, u32@0xec */
ts4_word ts4_loop_call_seq_u32_off50_88903190(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv7;
    ts4_word p9;
    int t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 != 0) {
        fn_888C9A68((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 32);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 28);
    if ((ts4_word)t5 != (ts4_word)t6) {
        lv7 = (ts4_word)t6;
        do {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 236);
            if ((ts4_word)t8 == (ts4_word)((737083392) | 35038)) {
                *(unsigned char *)((char *)(ts4_word)(lv7) + 154) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv7) + 155) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv7) + 240) = (unsigned char)1;
            }
            p9 = (ts4_word)(lv7 + 244);
            lv7 = p9;
        } while ((ts4_word)p9 != (ts4_word)t5);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t13 = fn_88901010((ts4_word)t11, (ts4_word)(*(ts4_word *)lbl_88C6B924));
    *(ts4_word *)((char *)(ts4_word)(t11) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B924);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 1772) = (ts4_word)((2188050432) | 12168);
    return t13;
}

/* Swing_DLL.xex 0x889087F0: if_get u8@0x1f, u8@0x61, u8@0x22, u8@0x22, u8@0x62, u8@0x62 */
ts4_word ts4_if_get_u8_off1f_889087F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;
    unsigned char t9;
    ts4_word t10;
    ts4_word t11;
    unsigned char t4;
    unsigned char t6;
    ts4_word t7;
    ts4_word t8;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 31);
    if ((ts4_word)t1 != 0) {
        return a0;
    }
    if ((ts4_word)(a2 & 0xff) == 0) {
        t9 = *(unsigned char *)((char *)(ts4_word)(a1) + 97);
        if ((ts4_word)t9 == 0) {
            return a0;
        }
        t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        t11 = *(ts4_word *)((char *)(ts4_word)(a1) + 120);
        *(unsigned char *)((char *)(ts4_word)(a1) + 97) = (unsigned char)0;
        return fn_88907570((ts4_word)a0, (ts4_word)t11, (ts4_word)(ts4_word)lbl_880D98B8, (ts4_word)t10);
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 34);
    if ((ts4_word)t4 == 0) {
        return a0;
    }
    t6 = *(unsigned char *)((char *)(ts4_word)(a1) + 98);
    if ((ts4_word)t6 == 0) {
        return a0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 124);
    *(unsigned char *)((char *)(ts4_word)(a1) + 98) = (unsigned char)0;
    return fn_88907570((ts4_word)a0, (ts4_word)t8, (ts4_word)(ts4_word)lbl_880D98B8, (ts4_word)t7);
}

/* Swing_DLL.xex 0x88908870: if_get u8@0x1f, u8@0x61, u8@0x22, u8@0x22, u8@0x62, u8@0x62 */
ts4_word ts4_if_get_u8_off1f_88908870(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p11;
    unsigned char t1;
    unsigned char t9;
    unsigned char t10;
    ts4_word t12;
    unsigned char t4;
    unsigned char t6;
    ts4_word t7;
    ts4_word t8;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 31);
    if ((ts4_word)t1 != 0) {
        return a0;
    }
    if ((ts4_word)(a2 & 0xff) == 0) {
        t9 = *(unsigned char *)((char *)(ts4_word)(a1) + 97);
        if ((ts4_word)t9 != 0) {
            return a0;
        }
        *(unsigned char *)((char *)(ts4_word)(a1) + 97) = (unsigned char)1;
        t10 = *(unsigned char *)((char *)(ts4_word)(a0) + 34);
        if ((ts4_word)t10 != 0) {
            p11 = (ts4_word)(ts4_word)lbl_880D9888;
        } else {
            p11 = (ts4_word)(ts4_word)lbl_880D98A4;
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        return fn_88907570((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120)), (ts4_word)p11, (ts4_word)t12);
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 34);
    if ((ts4_word)t4 == 0) {
        return a0;
    }
    t6 = *(unsigned char *)((char *)(ts4_word)(a1) + 98);
    if ((ts4_word)t6 != 0) {
        return a0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 124);
    *(unsigned char *)((char *)(ts4_word)(a1) + 98) = (unsigned char)1;
    return fn_88907570((ts4_word)a0, (ts4_word)t8, (ts4_word)(ts4_word)lbl_880D98A4, (ts4_word)t7);
}

/* Swing_DLL.xex 0x88908908: if_get u8@0x1f, u8@0x60, u8@0x60, u8@0x60, u8@0x22, u32@0x10 */
ts4_word ts4_if_get_u8_off1f_88908908(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    unsigned char t1;
    unsigned char t3;
    unsigned char t4;

    (void)a2;
    (void)a3;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 31);
    if ((ts4_word)t1 != 0) {
        return a0;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(a1) + 96);
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 96) = (unsigned char)0;
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 34);
    if ((ts4_word)t4 != 0) {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    } else {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    }
    return fn_88907570((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116)), (ts4_word)(ts4_word)lbl_880D9874, (ts4_word)p7, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t4);
}

/* Swing_DLL.xex 0x88908D28: if_get u32@0x258, u32@0x238, u8@0x23, fn_88908B38, ts4_net_update_slots_88908B80 */
ts4_word ts4_if_get_u32_off258_88908D28(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 600);
    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)2;
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 35);
    if ((ts4_word)t2 == 0) {
        return ts4_net_update_slots_88908B80((ts4_word)a0, (ts4_word)0, (ts4_word)1);
    }
    return fn_88908B38((ts4_word)a0);
}

/* Swing_DLL.xex 0x88908DF0: if_get u32@0x274, u8@0x2d8, ts4_net_update_slots_88908B80, u8@0x2d8 */
ts4_word ts4_if_get_u32_off274_88908DF0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 628);
    if ((ts4_word)t1 != (ts4_word)((2788622336) | 9383) && (ts4_word)t1 != (ts4_word)((375062528) | 48617)) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 728) = (unsigned char)1;
        return a0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 728) = (unsigned char)0;
    return ts4_net_update_slots_88908B80((ts4_word)a0, (ts4_word)1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88908E38: if_get u32@0x238, u32@0x258, u8@0x22, u8@0x23, ts4_net_update_slots_88908B80 */
ts4_word ts4_if_get_u32_off238_88908E38(ts4_word a0)
{
    int t1;
    ts4_word t2;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 568);
    if ((int)t1 == 1) {
        return a0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 600);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 34);
    return ts4_net_update_slots_88908B80((ts4_word)a0, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t2) + 35)), (ts4_word)t3);
}

/* Swing_DLL.xex 0x8890A930: if_get u32@0x1c, fn_8890A1F0 */
ts4_word ts4_if_get_u32_off1c_8890A930(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 <= 0) {
        return a0;
    }
    return fn_8890A1F0((ts4_word)a0);
}

/* Swing_DLL.xex 0x8890CAC0: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_8890CAC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Swing_DLL.xex 0x8890DD50: loop_get u32@0x18, u32@0x14, u32@0x24, u32@0x0, u32@0x28, u32@0x2c */
void ts4_loop_get_u32_off18_8890DD50(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a1;
    lv3 = (ts4_word)t2;
    while ((ts4_word)lv3 != (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)0;
        p4 = (ts4_word)(lv3 + 4);
        lv3 = p4;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8890ECE0: addr lbl_880D75FC, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_addr_lbl_880D75FC_8890ECE0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D75FC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8890EF88: addr lbl_880D75FC, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880D75FC_8890EF88(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D75FC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8890F158: loop_call_seq u32@0x20, u32@0x24, u32@0x4, fn_881609C8, u32@0x18, u32@0x14 */
ts4_word ts4_loop_call_seq_u32_off20_8890F158(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p7;
    float t1;
    ts4_word t3;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    t1 = *(float *)lbl_8814B440;
    *(volatile float *)((char *)(ts4_word)(a0) + 4) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 16) = t1;
    t3 = fn_881609C8((ts4_word)(a0 + 20), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    lv6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    while ((ts4_word)lv6 != (ts4_word)t4) {
        *(volatile ts4_word *)((char *)(ts4_word)(lv6) + 0) = (ts4_word)0;
        p7 = (ts4_word)(lv6 + 4);
        lv6 = p7;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x8890F5B0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_8890F5B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a4;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8890F818: call_seq u32@0x28, fn_8890F370, g_ts4_script_constants */
ts4_word ts4_call_seq_u32_off28_8890F818(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    float t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    t1 = fn_8890F370((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t2 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t2 * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 388)));
    return t1;
}

/* Swing_DLL.xex 0x8890F878: call_seq u32@0x28, fn_8890F370, g_ts4_script_constants */
ts4_word ts4_call_seq_u32_off28_8890F878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    float t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(a1 + 56);
    t1 = fn_8890F370((ts4_word)(a1 + 56), (ts4_word)a2, (ts4_word)a3);
    t2 = *(float *)((char *)(ts4_word)(a1) + 64);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t2 * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 388)));
    return t1;
}

/* Swing_DLL.xex 0x8890FEB0: call_seq u32@0x30, u32@0x28, u32@0x2c, u32@0x34, u32@0x38, u32@0x20 */
ts4_word ts4_call_seq_u32_off30_8890FEB0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    fn_88178AA8((ts4_word)(a0 + 28), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t4 = fn_881B9148((ts4_word)(a0 + 16));
    return t4;
}

/* Swing_DLL.xex 0x8890FF18: loop_call_seq lbl_880D7608, u32@0x0, u32@0x20, u32@0x1c, fn_8890F428, u32@0x1c */
ts4_word ts4_loop_call_seq_lbl_880D7608_8890FF18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7608;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            fn_8890F428((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 52);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    t11 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x8890FF78: call_seq fn_88617D88, lbl_880D7608, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_8890FF78(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7608;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8890FFF0: addr lbl_880D7604, u32@0x0, u32@0x14, u32@0x18, u32@0x1c, u32@0x24 */
void ts4_addr_lbl_880D7604_8890FFF0(ts4_word a0)
{
    float t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7604;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 4) = t1;
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 16) = t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88911FC0: if_call_seq lbl_880D75C4, u32@0x0, u32@0x30, u32@0x2c, ts4_loop_call_seq_u32_off0_88150378, u32@0x2c */
ts4_word ts4_if_call_seq_lbl_880D75C4_88911FC0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D75C4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = fn_88636CF0((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88913740: call_seq fn_88617D88, lbl_880D7074, u32@0x0, u32@0x1c, u32@0x28, u32@0x2c */
ts4_word ts4_call_seq_fn_88617D88_88913740(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7074;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88913F10: if_get u32@0x48, u32@0x0, u32@0x28 */
ts4_word ts4_if_get_u32_off48_88913F10(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x88914010: if_get u8@0x14, u32@0x108, fn_88B085A8 */
ts4_word ts4_if_get_u8_off14_88914010(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 1) {
        return a0;
    }
    return fn_88B085A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)));
}

/* Swing_DLL.xex 0x88915510: call_seq u32@0x108, fn_88B083F8, u32@0x108, fn_88B08168, fn_8890CB18, fn_88914A70 */
ts4_word ts4_call_seq_u32_off108_88915510(ts4_word a0)
{
    ts4_word t6;

    fn_88B083F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)));
    fn_88B08168((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)));
    fn_8890CB18((ts4_word)(a0 + 76));
    t6 = fn_88914A70((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88915558: if_call_seq u32@0x108, u8@0x104, fn_88B09368, u32@0x108, fn_88B08168, fn_8890CB18 */
ts4_word ts4_if_call_seq_u32_off108_88915558(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    *(unsigned char *)((char *)(ts4_word)(a0) + 260) = (unsigned char)1;
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        fn_88B09368((ts4_word)t1, (ts4_word)1);
        fn_88B08168((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)));
        fn_8890CB18((ts4_word)(a0 + 76));
        t6 = fn_88914A70((ts4_word)a0);
        p7 = (ts4_word)t6;
    }
    return p7;
}
