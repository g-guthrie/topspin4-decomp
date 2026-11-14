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

extern char fn_888A0C10[];
extern char ts4_if_addr_fn_888A0DD8_888A0D60[];
extern char ts4_if_get_u32_off10_888A0DD8[];
extern char fn_888A0F08[];
extern char fn_888A10A0[];
extern char fn_888A1178[];
extern char fn_888A1200[];
extern char ts4_if_addr_fn_888A15C0_888A1540[];
extern char ts4_if_get_u32_off10_888A15C0[];
extern char fn_888A19F0[];
extern char fn_888A1AF8[];
extern char fn_888A1C68[];
extern char fn_888A1DB0[];
extern char ts4_if_get_u32_off10_888A1E30[];
extern char fn_888A2068[];
extern char ts4_if_get_u32_off10_888A2150[];
extern char ts4_if_get_u32_off10_888A2320[];
extern char fn_888A2458[];
extern char ts4_if_addr_fn_888A1178_888A2680[];
extern char ts4_if_get_u32_off10_888A2700[];
extern char fn_888A27C0[];
extern char ts4_tailcall_fn_88916F10_88916F20[];
extern char ts4_call_88916EE8_88916F28[];
extern char ts4_tailcall_fn_88916EB8_88916F38[];
extern char ts4_tailcall_fn_88916ED0_88916F40[];
extern char ts4_call_889183F0_88918408[];
extern char fn_8891A6B0[];
extern char fn_8891A7E0[];
extern char fn_8891A8B0[];
extern char fn_8891A998[];
extern char fn_8891AAC8[];
extern char fn_8891ABF8[];
extern char fn_8893C328[];
extern char ts4_call_8893C170_8893C400[];
extern char fn_8893C410[];
extern char g_ts4_script_constants[];
extern char g_ts4_session_context[];
extern char lbl_880CF7F8[];
extern char lbl_880D0830[];
extern char lbl_880D0934[];
extern char lbl_880D0938[];
extern char lbl_880D19F0[];
extern char lbl_880D1CE0[];
extern char lbl_880D49CC[];
extern char lbl_880D547C[];
extern char lbl_880D54E8[];
extern char lbl_880D5A64[];
extern char lbl_880D5A78[];
extern char lbl_880D5B58[];
extern char lbl_880D5DB8[];
extern char lbl_880D62D8[];
extern char lbl_880D6330[];
extern char lbl_880D6968[];
extern char lbl_880D6A28[];
extern char lbl_880D6A78[];
extern char lbl_880D6B70[];
extern char lbl_880D7074[];
extern char lbl_880D75C4[];
extern char lbl_880D7604[];
extern char lbl_880D7608[];
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
extern char lbl_880E3DAC[];
extern char lbl_8814B440[];
extern char lbl_88C6B468[];
extern char lbl_88C6B484[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B8F4[];
extern char lbl_88C6B90C[];
extern char lbl_88C6B924[];
extern char lbl_88D45888[];
extern char lbl_88D458C0[];
extern char lbl_88D45908[];
extern char lbl_88D4591C[];
extern char lbl_88D45948[];
extern char lbl_88D45954[];
extern char lbl_88D45A60[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
extern char ts4_fn_888A09C0[];
extern char ts4_prolog_element_content_spec_888A1858[];
extern char ts4_prolog_entity_external_or_value_888A1EF0[];
extern char ts4_prolog_entity_external_or_value_888A2210[];
extern char ts4_session_field_getter_vcall8_8891A780[];
extern char ts4_session_field_getter_vcall8_8891AA68[];
extern char ts4_session_field_getter_vcall8_8891AB98[];
extern char ts4_session_field_getter_vcall8_8891ACC8[];
extern char ts4_session_field_getter_vcall8_88938CC8[];
extern char ts4_session_field_getter_vcall8_88938D28[];
extern char ts4_tailcall_fn_8893C210_8893C4F0[];
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_881506A0();
ts4_word fn_881609C8();
ts4_word fn_88161620();
ts4_word ts4_init_range_and_run_service_opt_88164F60();
ts4_word fn_8816D220();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8();
ts4_word fn_88178AA8();
ts4_word fn_8817E150();
ts4_word fn_8817EA90();
ts4_word fn_8817EE38();
ts4_word ts4_loop_call_seq_u32_off40_881815A8();
ts4_word ts4_loop_call_seq_u32_0x4_88181670();
ts4_word fn_88187900();
ts4_word fn_88187AB8();
ts4_word fn_881898E8();
ts4_word fn_881A6A00();
ts4_word fn_881B9148();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882908C0();
ts4_word fn_88290C68();
ts4_word fn_882C7288();
ts4_word fn_88564F40();
ts4_word fn_885651F8();
ts4_word ts4_crt_nh_malloc_88565258();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word fn_8857B388();
ts4_word ts4_if_call_seq_NtSuspendThread_8857B4C8();
ts4_word ts4_if_call_seq_NtSetEvent_8857C1F8();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860DCF8();
ts4_word ts4_handle_forward0_886107F8();
ts4_word fn_886131F0();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88622E88();
ts4_word fn_886263E8();
ts4_word fn_8862C0E8();
ts4_word fn_88636CF0();
ts4_word fn_8886B1B0();
ts4_word ts4_registry_dispatch_888860A0();
ts4_word fn_8888A4E8();
ts4_word fn_888AA228();
ts4_word fn_888AA328();
ts4_word ts4_bm_ball_cache_arc_constants_888AAEA8();
ts4_word fn_888AB7B0();
ts4_word fn_888AB8D0();
ts4_word fn_888ABF10();
ts4_word fn_888AC100();
ts4_word fn_888AC2B8();
ts4_word fn_888AC4A0();
ts4_word fn_888AC748();
ts4_word fn_888ACA68();
ts4_word fn_888ACDA8();
ts4_word fn_888AD568();
ts4_word fn_888C0970();
ts4_word fn_888C3768();
ts4_word fn_888C93E8();
ts4_word fn_888C9A68();
ts4_word fn_888C9DD8();
ts4_word fn_888CA3E0();
ts4_word fn_888CCFF0();
ts4_word fn_888CD190();
ts4_word fn_888CD2B8();
ts4_word fn_888CF650();
ts4_word fn_888D7920();
ts4_word fn_888D84B8();
ts4_word ts4_if_call_seq_fn_8817EA90_888D85B0();
ts4_word fn_888DD008();
ts4_word fn_888EC548();
ts4_word fn_888F1170();
ts4_word fn_888F1B30();
ts4_word fn_888F69A0();
ts4_word fn_888F7160();
ts4_word fn_88901010();
ts4_word fn_88907570();
ts4_word fn_88908B38();
ts4_word fn_8890CB18();
ts4_word fn_8890F370();
ts4_word fn_8890F428();
ts4_word fn_88914A70();
ts4_word fn_88918FA0();
ts4_word fn_88923380();
ts4_word fn_88923790();
ts4_word fn_88925640();
ts4_word fn_88927110();
ts4_word fn_88929E70();
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80();
ts4_word ts4_call_seq_fn_88617D88_8892AFF0();
ts4_word fn_8892F508();
ts4_word ts4_if_get_u32_off0_8892FE20();
ts4_word fn_889316F8();
ts4_word fn_88933EF8();
ts4_word ts4_if_call_seq_u32_off0_889367A8();
ts4_word fn_88936AF0();
ts4_word fn_88936BB0();
ts4_word fn_88937148();
ts4_word fn_88938E98();
ts4_word fn_88939288();
ts4_word fn_889393C0();
ts4_word fn_889395D8();
ts4_word fn_88939738();
ts4_word fn_8893C6A8();
ts4_word fn_88B08168();
ts4_word fn_88B083F8();
ts4_word fn_88B09368();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_u32_off0_8817B998();
ts4_word ts4_call_seq_u32_off1c_888F5D50();
ts4_word ts4_call_seq_u32_off8_889343E8();
ts4_word ts4_create_zeroed_triplet();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_forward_to_fn_8841B5E0();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word ts4_if_call_seq_u32_off24_88929630();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word ts4_if_get_u32_lbl_88D45B1C_888C0198();
ts4_word ts4_if_get_u8_offec_888A8610();
ts4_word ts4_net_update_slots_88908B80();
ts4_word ts4_object_finalize();
ts4_word ts4_profile_internal_activate();
ts4_word ts4_tailcall_NetDll_recv_884F0318();
ts4_word ts4_tailcall_XamContentCreateEnumerator_8857B2F0();
ts4_word ts4_tailcall_XamEnumerate_8857A1C8();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word ts4_xml_pool_grow_888A2F00();

/* Swing_DLL.xex 0x888A3BC8: if_get u32@0x0, vcall, u32@0x64, u32@0x50, u32@0x54, u32@0x60 */
ts4_word ts4_if_get_u32_off0_888A3BC8(ts4_word a0)
{
    ts4_word t2;

    t2 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 0))))((ts4_word)188);
    if ((ts4_word)t2 == 0) {
        return t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 116) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 124) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 56) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 76) = (ts4_word)a0;
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 131) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 144) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 140) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 132) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 148) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 152) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 156) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 160) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 184) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 164) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 180) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 172) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 176) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 168) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 128) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 129) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 130) = (unsigned char)0;
    return t2;
}

/* Swing_DLL.xex 0x888AC688: if_call_seq u32@0x24, u32@0x14, fn_888ABF10, fn_888AC2B8, fn_888AB7B0, fn_888AC100 */
ts4_word ts4_if_call_seq_u32_off24_888AC688(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;
    ts4_word t14;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 20);
    if ((ts4_word)t2 <= (ts4_word)((1569718272) | 26459)) {
        if ((ts4_word)t2 != (ts4_word)((1569718272) | 26459)) {
            if ((ts4_word)t2 != (ts4_word)((766705664) | 60271)) {
                if ((ts4_word)t2 == (ts4_word)((1354235904) | 37970)) {
                    fn_888AC4A0();
                }
            } else {
                fn_888AC100((ts4_word)a0, (ts4_word)a1);
            }
        } else {
            fn_888AB7B0((ts4_word)a0);
        }
    } else {
        if ((ts4_word)t2 != (ts4_word)((2275082240) | 43104)) {
            if ((ts4_word)t2 == (ts4_word)((3247833088) | 24156)) {
                fn_888AC2B8((ts4_word)a0);
            }
        } else {
            fn_888ABF10((ts4_word)a0);
        }
    }
    t14 = ts4_bm_ball_cache_arc_constants_888AAEA8((ts4_word)a0);
    return t14;
}

/* Swing_DLL.xex 0x888AD4A0: set u32@0x80, u32@0x84, u32@0x88, u32@0x90, u32@0x94, u32@0x98 */
void ts4_set_u32_off80_888AD4A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888ADAE8: if_get u32@0x8, u32@0x0 */
void ts4_if_get_u32_off8_888ADAE8(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t2;
    float t3;
    float t4;
    float t5;
    float t6;
    float t7;
    float t8;
    float t9;
    float t10;
    float t11;
    float t12;
    float t13;
    float t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 == 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(float *)((char *)(ts4_word)(a1) + 0);
    t4 = *(float *)((char *)(ts4_word)((t2 + t1)) + 200);
    if (!(t3 == t4)) {
        *(float *)((char *)(ts4_word)((t2 + t1)) + 200) = t3;
    }
    t5 = *(float *)((char *)(ts4_word)(a1) + 4);
    t6 = *(float *)((char *)(ts4_word)((t2 + t1)) + 204);
    if (!(t5 == t6)) {
        *(float *)((char *)(ts4_word)((t2 + t1)) + 204) = t5;
    }
    t7 = *(float *)((char *)(ts4_word)(a1) + 8);
    t8 = *(float *)((char *)(ts4_word)((t2 + t1)) + 208);
    if (!(t7 == t8)) {
        *(float *)((char *)(ts4_word)((t2 + t1)) + 208) = t7;
    }
    t9 = *(float *)((char *)(ts4_word)(a1) + 12);
    t10 = *(float *)((char *)(ts4_word)((t2 + t1)) + 212);
    if (!(t9 == t10)) {
        *(float *)((char *)(ts4_word)((t2 + t1)) + 212) = t9;
    }
    t11 = *(float *)((char *)(ts4_word)(a1) + 16);
    t12 = *(float *)((char *)(ts4_word)((t2 + t1)) + 216);
    if (!(t11 == t12)) {
        *(float *)((char *)(ts4_word)((t2 + t1)) + 216) = t11;
    }
    t13 = *(float *)((char *)(ts4_word)(a1) + 20);
    t14 = *(float *)((char *)(ts4_word)((t2 + t1)) + 220);
    if (t13 == t14) {
        return;
    }
    *(float *)((char *)(ts4_word)((t2 + t1)) + 220) = t13;
    return;
}

/* Swing_DLL.xex 0x888ADE80: if_get u32@0x8, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x0, u32@0xd0 */
void ts4_if_get_u32_off8_888ADE80(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 0)) + t1)) + 208));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x888ADEB8: if_get u32@0x8, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x0, u32@0xc8 */
void ts4_if_get_u32_off8_888ADEB8(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 0)) + t1)) + 200));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x888ADEF0: if_get u32@0x8, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x0, u32@0xcc */
void ts4_if_get_u32_off8_888ADEF0(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 0)) + t1)) + 204));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x888ADF88: if_get u32@0x8, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x0, u32@0xb0 */
void ts4_if_get_u32_off8_888ADF88(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 0)) + t1)) + 176));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x888AE0F8: if_get  */
void ts4_if_get_888AE0F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;
    float t6;
    float t7;
    float t8;
    float t9;
    float t10;
    float t11;
    float t12;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 0);
    if (t2 < t1) {
        *(float *)((char *)(ts4_word)(a0) + 0) = t1;
    }
    t3 = *(float *)((char *)(ts4_word)(a1) + 4);
    t4 = *(float *)((char *)(ts4_word)(a0) + 4);
    if (t4 < t3) {
        *(float *)((char *)(ts4_word)(a0) + 4) = t3;
    }
    t5 = *(float *)((char *)(ts4_word)(a1) + 8);
    t6 = *(float *)((char *)(ts4_word)(a0) + 8);
    if (t6 < t5) {
        *(float *)((char *)(ts4_word)(a0) + 8) = t5;
    }
    t7 = *(float *)((char *)(ts4_word)(a2) + 0);
    t8 = *(float *)((char *)(ts4_word)(a0) + 0);
    if (t8 > t7) {
        *(float *)((char *)(ts4_word)(a0) + 0) = t7;
    }
    t9 = *(float *)((char *)(ts4_word)(a2) + 4);
    t10 = *(float *)((char *)(ts4_word)(a0) + 4);
    if (t10 > t9) {
        *(float *)((char *)(ts4_word)(a0) + 4) = t9;
    }
    t11 = *(float *)((char *)(ts4_word)(a2) + 8);
    t12 = *(float *)((char *)(ts4_word)(a0) + 8);
    if (!(t12 > t11)) {
        return;
    }
    *(float *)((char *)(ts4_word)(a0) + 8) = t11;
    return;
}

/* Swing_DLL.xex 0x888AE3B0: if_get u32@0x10, fn_888AD568, u32@0x0, u32@0x84, vcall */
ts4_word ts4_if_get_u32_off10_888AE3B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)a1;
        t2 = fn_888AD568((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 132))))((ts4_word)t2, (ts4_word)a2);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Swing_DLL.xex 0x888AE410: if_get u32@0x10, fn_888AD568, u32@0x0, u32@0x80, vcall */
ts4_word ts4_if_get_u32_off10_888AE410(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)a1;
        t2 = fn_888AD568((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 128))))((ts4_word)t2, (ts4_word)a2);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Swing_DLL.xex 0x888AE668: if_get u32@0x10, fn_888AD568, u32@0x0, u32@0x64, vcall */
ts4_word ts4_if_get_u32_off10_888AE668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)a1;
        t2 = fn_888AD568((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 100))))((ts4_word)t2, (ts4_word)a2);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Swing_DLL.xex 0x888AE728: if_get u32@0x10, fn_888AD568, u32@0x0, u32@0x5c, vcall */
ts4_word ts4_if_get_u32_off10_888AE728(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)a1;
        t2 = fn_888AD568((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 92))))((ts4_word)t2, (ts4_word)a2);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Swing_DLL.xex 0x888D3648: loop_set u8@0x88, u32@0x90, u8@0x89, ts4_find_service, fn_888C0970, u32@0x48 */
ts4_word ts4_loop_set_u8_off88_888D3648(ts4_word a0)
{
    ts4_word lv10;
    ts4_word p12;
    ts4_word lv29;
    ts4_word p31;
    ts4_word p37;
    ts4_word t1;
    int t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t14;
    ts4_word t16;
    ts4_word t20;
    ts4_word t26;
    ts4_word t27;
    ts4_word t28;
    ts4_word t30;
    int t33;
    ts4_word t36;

    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 137) = (unsigned char)0;
    t1 = ts4_find_service((ts4_word)((4102225920) | 24426));
    if ((ts4_word)t1 != 0) {
        fn_888C0970((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t4 != 0) {
        fn_888CA3E0((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 32);
    t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 28);
    if ((ts4_word)t8 != (ts4_word)t9) {
        lv10 = (ts4_word)t9;
        do {
            t11 = *(ts4_word *)((char *)(ts4_word)(lv10) + 236);
            if ((ts4_word)t11 == (ts4_word)((737083392) | 35038)) {
                *(unsigned char *)((char *)(ts4_word)(lv10) + 154) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv10) + 155) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv10) + 240) = (unsigned char)1;
            }
            p12 = (ts4_word)(lv10 + 244);
            lv10 = p12;
        } while ((ts4_word)p12 != (ts4_word)t8);
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t14 != 0) {
        fn_888C9DD8((ts4_word)t14);
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 12))))((ts4_word)t16);
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
        if ((ts4_word)t20 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 0))) + 0))))((ts4_word)t20, (ts4_word)1);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    }
    t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t27 = *(ts4_word *)((char *)(ts4_word)(t26) + 32);
    t28 = *(ts4_word *)((char *)(ts4_word)(t26) + 28);
    if ((ts4_word)t27 != (ts4_word)t28) {
        lv29 = (ts4_word)t28;
        do {
            t30 = *(ts4_word *)((char *)(ts4_word)(lv29) + 236);
            if ((ts4_word)t30 == (ts4_word)((737083392) | 35038)) {
                *(unsigned char *)((char *)(ts4_word)(lv29) + 154) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv29) + 155) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv29) + 240) = (unsigned char)1;
            }
            p31 = (ts4_word)(lv29 + 244);
            lv29 = p31;
        } while ((ts4_word)p31 != (ts4_word)t27);
    }
    t33 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    p37 = (ts4_word)t33;
    if ((int)t33 != 0) {
        t36 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t33) + 0))) + 12))))((ts4_word)t33);
        p37 = (ts4_word)t36;
    }
    return p37;
}

/* Swing_DLL.xex 0x888F2D70: if_addr ts4_if_call_seq_u32_lbl_88D459E4_8883F238, lbl_880D1CE0, u32@lbl_88D45A60, u32@0x314, fn_8886B1B0, u32@0x0 */
ts4_word ts4_if_addr_ts4_if_call_seq_u32_lbl_88D459E4_8883F238_888F2D70(void)
{
    ts4_word p28;
    ts4_word locc0[128];
    ts4_word loc50[4];
    ts4_word loc60[24];
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;
    ts4_word t19;
    ts4_word t22;
    ts4_word t23;
    ts4_word t27;

    t1 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    fn_8886B1B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 788)), (ts4_word)(ts4_word)&locc0[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880D1CE0, (ts4_word)1);
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(ts4_word)&locc0[0], (ts4_word)3072, (ts4_word)0);
    t8 = loc50[0];
    p28 = (ts4_word)t7;
    if ((ts4_word)t8 != 0) {
        ts4_call_seq_fn_88617D88_8892AFF0((ts4_word)(ts4_word)&loc60[0]);
        t10 = loc50[0];
        ts4_if_get_u32_off0_8892FE20((ts4_word)(ts4_word)&loc60[0], (ts4_word)t10, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        t12 = loc60[0];
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t12) + 76))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
        t15 = loc50[0];
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 28))))((ts4_word)t15, (ts4_word)0, (ts4_word)2);
        t19 = loc50[0];
        fn_88925640((ts4_word)(ts4_word)&loc60[0], (ts4_word)t19);
        fn_88929E70((ts4_word)(ts4_word)&loc60[0]);
        t22 = loc50[0];
        t23 = *(ts4_word *)((char *)(ts4_word)(t22) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 88))))((ts4_word)t23, (ts4_word)(ts4_word)&loc50[0]);
        t27 = ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(ts4_word)&loc60[0]);
        p28 = (ts4_word)t27;
    }
    return p28;
}

/* Swing_DLL.xex 0x888F5A98: if_get u32@0x0, u32@0x6c, vcall, ts4_if_call_seq_u32_lbl_88D459E4_8883F238, lbl_880D1CE0, fn_8886B1B0 */
ts4_word ts4_if_get_u32_off0_888F5A98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p18;
    ts4_word p34;
    ts4_word p35;
    ts4_word locc0[130];
    ts4_word loc50[4];
    ts4_word loc60[24];
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;
    ts4_word t15;
    ts4_word t16;
    ts4_word t20;
    ts4_word t27;
    ts4_word t28;
    ts4_word t32;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108))))((ts4_word)a0);
    p35 = (ts4_word)t3;
    if ((ts4_word)(t3 & 0xff) != 0) {
        t4 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238((ts4_word)t3);
        fn_8886B1B0((ts4_word)a1, (ts4_word)(ts4_word)&locc0[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880D1CE0, (ts4_word)1);
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4, (ts4_word)(ts4_word)&locc0[0], (ts4_word)3072, (ts4_word)0);
        t9 = loc50[0];
        p34 = (ts4_word)t8;
        if ((ts4_word)t9 != 0) {
            ts4_call_seq_fn_88617D88_8892AFF0((ts4_word)(ts4_word)&loc60[0]);
            t11 = loc50[0];
            ts4_if_get_u32_off0_8892FE20((ts4_word)(ts4_word)&loc60[0], (ts4_word)t11, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
            t13 = loc60[0];
            t15 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t13) + 76))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
            p18 = (ts4_word)0;
            if ((ts4_word)a1 < 7) {
                t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
                p18 = (ts4_word)((((int)a1 * 100) + (*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + t16);
            }
            fn_88187900((ts4_word)p18, (ts4_word)t15);
            if ((ts4_word)(a2 & 0xff) != 0) {
                t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
                fn_88187900((ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t20) + 0)) + t20) + 400), (ts4_word)p18);
                *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 12) = (ts4_word)a1;
            }
            fn_88929E70((ts4_word)(ts4_word)&loc60[0]);
            t27 = loc50[0];
            t28 = *(ts4_word *)((char *)(ts4_word)(t27) + 4);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t28) + 0))) + 88))))((ts4_word)t28, (ts4_word)(ts4_word)&loc50[0]);
            t32 = ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(ts4_word)&loc60[0]);
            p34 = (ts4_word)t32;
        }
        p35 = (ts4_word)p34;
    }
    return p35;
}

/* Swing_DLL.xex 0x88916488: get u32@0xa0, u32@0x430, u32@0x44, u32@0x484, u32@0x48, u32@0x488 */
float ts4_get_u32_offa0_88916488(ts4_word a0, ts4_word a1)
{
    float t15;

    *(ts4_word *)((char *)(ts4_word)(a0) + 1072) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 160));
    *(float *)((char *)(ts4_word)(a0) + 1076) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 1080) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 1084) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 1088) = (*(float *)((char *)(ts4_word)(a1) + 16));
    *(float *)((char *)(ts4_word)(a0) + 1092) = (*(float *)((char *)(ts4_word)(a1) + 20));
    *(float *)((char *)(ts4_word)(a0) + 1096) = (*(float *)((char *)(ts4_word)(a1) + 24));
    *(float *)((char *)(ts4_word)(a0) + 1100) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(float *)((char *)(ts4_word)(a0) + 1104) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(float *)((char *)(ts4_word)(a0) + 1108) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 1112) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 1116) = (*(float *)((char *)(ts4_word)(a1) + 56));
    *(float *)((char *)(ts4_word)(a0) + 1120) = (*(float *)((char *)(ts4_word)(a1) + 60));
    *(float *)((char *)(ts4_word)(a0) + 1124) = (*(float *)((char *)(ts4_word)(a1) + 52));
    t15 = *(float *)((char *)(ts4_word)(a1) + 96);
    *(float *)((char *)(ts4_word)(a0) + 1128) = t15;
    *(float *)((char *)(ts4_word)(a0) + 1132) = (*(float *)((char *)(ts4_word)(a1) + 100));
    *(float *)((char *)(ts4_word)(a0) + 1136) = (*(float *)((char *)(ts4_word)(a1) + 104));
    *(float *)((char *)(ts4_word)(a0) + 1140) = (*(float *)((char *)(ts4_word)(a1) + 112));
    *(float *)((char *)(ts4_word)(a0) + 1144) = (*(float *)((char *)(ts4_word)(a1) + 116));
    *(float *)((char *)(ts4_word)(a0) + 1148) = (*(float *)((char *)(ts4_word)(a1) + 120));
    *(float *)((char *)(ts4_word)(a0) + 1152) = (*(float *)((char *)(ts4_word)(a1) + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1156) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1160) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    *(float *)((char *)(ts4_word)(a0) + 1176) = (*(float *)((char *)(ts4_word)(a1) + 76));
    *(float *)((char *)(ts4_word)(a0) + 1180) = (*(float *)((char *)(ts4_word)(a1) + 80));
    *(float *)((char *)(ts4_word)(a0) + 1184) = (*(float *)((char *)(ts4_word)(a1) + 84));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1188) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 88));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1192) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1196) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 132));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1200) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 136));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1204) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 140));
    *(float *)((char *)(ts4_word)(a0) + 1208) = (*(float *)((char *)(ts4_word)(a1) + 144));
    *(float *)((char *)(ts4_word)(a0) + 1212) = (*(float *)((char *)(ts4_word)(a1) + 148));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1216) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 152));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1217) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 153));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1218) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 154));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1219) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 155));
    return t15;
}

/* Swing_DLL.xex 0x8891AD28: if_get u32@g_ts4_session_context, u32@0x40, u32@0x8, u32@0x4, ts4_session_field_getter_vcall8_8891ACC8, ts4_call_889183F0_88918408 */
void ts4_if_get_u32_g_ts4_session_context_8891AD28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t23;
    ts4_word t24;
    ts4_word t25;
    ts4_word t30;
    ts4_word t31;
    ts4_word t32;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)g_ts4_session_context;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 31) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 496) = (ts4_word)(ts4_word)ts4_session_field_getter_vcall8_8891ACC8;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 500) = (ts4_word)(ts4_word)ts4_call_889183F0_88918408;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 504) = (ts4_word)(ts4_word)fn_8891ABF8;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 508) = (ts4_word)a0;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
    if ((ts4_word)t10 > 32) {
        t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t11) + 512) = (ts4_word)(ts4_word)ts4_session_field_getter_vcall8_8891AB98;
        *(volatile ts4_word *)((char *)(ts4_word)(t11) + 516) = (ts4_word)(ts4_word)ts4_tailcall_fn_88916ED0_88916F40;
        *(volatile ts4_word *)((char *)(ts4_word)(t11) + 520) = (ts4_word)(ts4_word)fn_8891AAC8;
        *(volatile ts4_word *)((char *)(ts4_word)(t11) + 524) = (ts4_word)a0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t17 = *(ts4_word *)((char *)(ts4_word)(t16) + 8);
    if ((ts4_word)t17 > 33) {
        t18 = *(ts4_word *)((char *)(ts4_word)(t16) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t18) + 528) = (ts4_word)(ts4_word)ts4_session_field_getter_vcall8_8891AA68;
        *(volatile ts4_word *)((char *)(ts4_word)(t18) + 532) = (ts4_word)(ts4_word)ts4_tailcall_fn_88916EB8_88916F38;
        *(volatile ts4_word *)((char *)(ts4_word)(t18) + 536) = (ts4_word)(ts4_word)fn_8891A998;
        *(volatile ts4_word *)((char *)(ts4_word)(t18) + 540) = (ts4_word)a0;
    }
    t23 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t24 = *(ts4_word *)((char *)(ts4_word)(t23) + 8);
    if ((ts4_word)t24 > 34) {
        t25 = *(ts4_word *)((char *)(ts4_word)(t23) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t25) + 544) = (ts4_word)(ts4_word)fn_8891A8B0;
        *(volatile ts4_word *)((char *)(ts4_word)(t25) + 548) = (ts4_word)(ts4_word)ts4_call_88916EE8_88916F28;
        *(volatile ts4_word *)((char *)(ts4_word)(t25) + 552) = (ts4_word)(ts4_word)fn_8891A7E0;
        *(volatile ts4_word *)((char *)(ts4_word)(t25) + 556) = (ts4_word)a0;
    }
    t30 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t31 = *(ts4_word *)((char *)(ts4_word)(t30) + 8);
    if ((ts4_word)t31 > 35) {
        t32 = *(ts4_word *)((char *)(ts4_word)(t30) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t32) + 560) = (ts4_word)(ts4_word)ts4_session_field_getter_vcall8_8891A780;
        *(volatile ts4_word *)((char *)(ts4_word)(t32) + 564) = (ts4_word)(ts4_word)ts4_tailcall_fn_88916F10_88916F20;
        *(volatile ts4_word *)((char *)(ts4_word)(t32) + 568) = (ts4_word)(ts4_word)fn_8891A6B0;
        *(volatile ts4_word *)((char *)(ts4_word)(t32) + 572) = (ts4_word)a0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}
