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

extern char __imp_VdGlobalDevice[];
extern char ts4_jpeg_consume_markers_882EC918[];
extern char fn_882EF810[];
extern char ex8_write_frame_header_882EF888[];
extern char ex8_write_scan_header_882EF9D8[];
extern char ex8_write_tables_only_882EFB30[];
extern char ts4_jpeg_read_backing_store_882F5260[];
extern char ts4_jpeg_write_backing_store_882F52F8[];
extern char ts4_forward_field12_of_second_arg_882F5390[];
extern char lbl_8800927C[];
extern char lbl_880097E8[];
extern char lbl_88009B0C[];
extern char lbl_880C1320[];
extern char lbl_880F8748[];
extern char lbl_880F8C74[];
extern char lbl_880F8D50[];
extern char lbl_880F8FF0[];
extern char lbl_880F9574[];
extern char lbl_88D429E3[];
extern char lbl_88D452E4[];
extern char lbl_88D45B38[];
extern char ts4_forward_882EF808[];
ts4_word ExRegisterTitleTerminateNotification();
ts4_word VdShutdownEngines();
ts4_word fn_882869C0();
ts4_word fn_88286BB8();
ts4_word fn_88289118();
ts4_word fn_8828A478();
ts4_word fn_8828A508();
ts4_word fn_8828DE38();
ts4_word fn_88290718();
ts4_word fn_88290778();
ts4_word fn_882907D8();
ts4_word fn_88290830();
ts4_word fn_88292598();
ts4_word fn_88295990();
ts4_word fn_88295A38();
ts4_word fn_882A0048();
ts4_word fn_882A27E0();
ts4_word fn_882AB878();
ts4_word fn_882ABB68();
ts4_word fn_882ABE00();
ts4_word fn_882ACDE0();
ts4_word fn_882AF630();
ts4_word fn_882C4A28();
ts4_word fn_882C60F8();
ts4_word fn_882C7918();
ts4_word ts4_set_u32_off4_882CDA08();
ts4_word fn_882E0E78();
ts4_word png2_png_error_882E26E8();
ts4_word png2_png_calculate_crc_882E2900();
ts4_word ts4_get_u32_off554_882E2970();
ts4_word png2_zlib_crc32_882EC228();
ts4_word ts4_jpeg_per_scan_setup_882EC5E0();
ts4_word ts4_jpeg_latch_quant_tables_882EC7D0();
ts4_word ts4_jpeg_alloc_small_882ECB68();
ts4_word ts4_if_get_u32_off4_882EDDF8();
ts4_word ts4_jpeg_jcopy_sample_rows_882EE8A0();
ts4_word fn_882EE920();
ts4_word ts4_jpeg_start_iMCU_row_882F5C70();
ts4_word ex8_emit_bits_882FD0D8();
ts4_word ex8_emit_eobrun_882FD3C8();
ts4_word fn_883089E0();
ts4_word fn_88309DB8();
ts4_word ts4_get_unit_and_chunks_8830B140();
ts4_word fn_8830B4C8();
ts4_word fn_8830B570();
ts4_word fn_8830B840();
ts4_word ts4_if_get_8830B908();
ts4_word fn_8830BA90();
ts4_word fn_8830BB18();
ts4_word fn_8830BD50();
ts4_word ts4_if_get_u32_off5198_8830C108();
ts4_word fn_8830C130();
ts4_word fn_8830C1C8();
ts4_word fn_8830DA40();
ts4_word fn_8830DEC0();
ts4_word fn_8830E120();
ts4_word fn_8830E948();
ts4_word fn_8830FBC8();
ts4_word fn_88310418();
ts4_word fn_88310500();
ts4_word fn_883105A8();
ts4_word ts4_tailcall_fn_8830F378_88310728();
ts4_word fn_883142A8();
ts4_word fn_88314478();
ts4_word ts4_tailcall_fn_88314478_88314958();
ts4_word fn_88314960();
ts4_word fn_88316C80();
ts4_word fn_88316D00();
ts4_word fn_88317860();
ts4_word fn_88569D30();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word fn_8856C130();
ts4_word fn_8857A1E0();
ts4_word ts4_call_seq_RtlInitAnsiString_88582148();
ts4_word ts4_msg_view_dtor_886047F8();
ts4_word fn_886121A0();
ts4_word fn_88613268();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_886197F0();
ts4_word ts4_service_ctor_handle_8861D130();
ts4_word ts4_call_seq_fn_88617D88_8861DBF0();
ts4_word ts4_singleton_service_ctor_8861DD58();
ts4_word fn_8861E530();
ts4_word fn_8861F9B8();
ts4_word ts4_call_seq_fn_886197F0_8861FE98();
ts4_word ts4_call_seq_fn_886197F0_88620190();
ts4_word ts4_call_seq_fn_886197F0_88620480();
ts4_word ts4_call_seq_fn_886197F0_88621028();
ts4_word ts4_service_ctor_handle_886256D0();
ts4_word fn_88625738();
ts4_word ts4_service_ctor_vec_886258A0();
ts4_word fn_88625DA0();
ts4_word fn_88626140();
ts4_word fn_886285F8();
ts4_word ts4_call_seq_fn_88617D88_88629DC0();
ts4_word fn_8862C390();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_88888668();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_copy_bytes();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_dtor_wrapper_8827FA20();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88284BB8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_88621028 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284BB8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)404, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_88621028((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284C10: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_88621028 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284C10(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)404, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_88621028((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285008: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_88620480 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285008(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)400, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_88620480((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285060: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_88620480 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285060(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)400, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_88620480((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882850B8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_88620190 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882850B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)392, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_88620190((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285110: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_88620190 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285110(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)392, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_88620190((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285168: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_8861FE98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285168(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)400, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_8861FE98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882851C0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_886197F0_8861FE98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882851C0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)400, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_886197F0_8861FE98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285218: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8861F9B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285218(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)484, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8861F9B8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285270: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8861F9B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285270(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)484, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8861F9B8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882852C8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886197F0, lbl_880F8748, u32@0x64, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882852C8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)376, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_886197F0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)16;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8748;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285348: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886197F0, lbl_880F8748, u32@0x64, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285348(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)376, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_886197F0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)16;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8748;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882855D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886285F8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882855D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886285F8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285630: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886285F8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285630(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886285F8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285738: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88626140 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285738(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1796, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88626140((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285790: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88626140 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285790(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1796, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88626140((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285878: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88629DC0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285878(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88629DC0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882858D0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88629DC0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882858D0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88629DC0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882859D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88625DA0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882859D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88625DA0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285A30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88625DA0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285A30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88625DA0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285A88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8861E530 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285A88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8861E530((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285AE0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8861E530 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285AE0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8861E530((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285B38: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_vec_886258A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285B38(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_vec_886258A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285B90: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_vec_886258A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285B90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_vec_886258A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285BE8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_singleton_service_ctor_8861DD58 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285BE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_singleton_service_ctor_8861DD58((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285C40: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_singleton_service_ctor_8861DD58 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285C40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_singleton_service_ctor_8861DD58((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285C98: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_8861DBF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285C98(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_8861DBF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285CF0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_8861DBF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285CF0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_8861DBF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285D48: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8D50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285D48(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8D50;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285DC0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8D50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285DC0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8D50;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285E38: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_handle_8861D130 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285E38(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_handle_8861D130((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285E90: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_handle_8861D130 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285E90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_handle_8861D130((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285EE8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88625738 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285EE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88625738((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285F40: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88625738 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285F40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88625738((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285F98: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_handle_886256D0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285F98(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_handle_886256D0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285FF0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_handle_886256D0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285FF0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_handle_886256D0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88286048: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8862C390 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88286048(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8862C390((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882860A0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8862C390 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882860A0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8862C390((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882863D0: if_call_seq u32@0x0, ts4_assign_formatted_text, u32@0xc, u32@0xc, u32@0x10, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_882863D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t2 = ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
        p6 = (ts4_word)t2;
    }
    return p6;
}

/* Swing_DLL.xex 0x88286490: if_addr lbl_880F8C74, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_if_addr_lbl_880F8C74_88286490(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8C74;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 32));
    return;
}

/* Swing_DLL.xex 0x882865B8: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_882869C0, fn_88286BB8 */
ts4_word ts4_call_seq_u32_off0_882865B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    fn_882869C0((ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
    fn_88286BB8((ts4_word)(a0 + 20), (ts4_word)(a1 + 20));
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 32));
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 33));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(unsigned char *)((char *)(ts4_word)(a0) + 35) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 35));
    return a0;
}

/* Swing_DLL.xex 0x88286E18: tailcall fn_886121A0 */
ts4_word ts4_tailcall_fn_886121A0_88286E18(ts4_word a0)
{
    return fn_886121A0((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x88286E30: tailcall ts4_dtor_wrapper_8827FA20 */
ts4_word ts4_tailcall_ts4_dtor_wrapper_8827FA20_88286E30(ts4_word a0)
{
    return ts4_dtor_wrapper_8827FA20((ts4_word)(a0 + -4));
}

/* Swing_DLL.xex 0x88286EC0: if_call_seq lbl_880F8FF0, u32@0x0, ts4_object_finalize, u32@0x1c, ts4_destroy_owned_object, fn_88617D28 */
ts4_word ts4_if_call_seq_lbl_880F8FF0_88286EC0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8FF0;
    ts4_object_finalize((ts4_word)(a0 + 28));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88287020: get u32@0x4, u32@0x4, u32@0x2c, u32@0x8, u32@0x0 */
void ts4_get_u32_off4_88287020(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) + (t2 << 4))) + 8));
    return;
}

/* Swing_DLL.xex 0x88287228: if_call_seq lbl_880F9574, u32@0x0, ts4_msg_view_dtor_886047F8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F9574_88287228(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F9574;
    ts4_msg_view_dtor_886047F8((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8828AD80: get u32@0x24 */
ts4_word ts4_get_u32_off24_8828AD80(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) >> 26) + 1);
}

/* Swing_DLL.xex 0x8828AE70: tailcall fn_8828A478 */
ts4_word ts4_tailcall_fn_8828A478_8828AE70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8828A478((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x8828B278: get u32@0x1c, u32@0x18, fn_8828A508 */
ts4_word ts4_get_u32_off1c_8828B278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return fn_8828A508((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)((t1) >> 28), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x8828BB48: get u32@0x2948 */
ts4_word ts4_get_u32_off2948_8828BB48(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10568)) & 0x7);
}

/* Swing_DLL.xex 0x8828BC40: get u32@0x2efc */
ts4_word ts4_get_u32_off2efc_8828BC40(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12028))) >> 31);
}

/* Swing_DLL.xex 0x8828BD60: get u32@0x2ef8 */
ts4_word ts4_get_u32_off2ef8_8828BD60(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 12024)) & 0x1f);
}

/* Swing_DLL.xex 0x8828BED0: get u16@0x2ef8 */
ts4_word ts4_get_u16_off2ef8_8828BED0(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 12024)) & 0x1f);
}

/* Swing_DLL.xex 0x8828BF40: get u8@0x2ef8 */
ts4_word ts4_get_u8_off2ef8_8828BF40(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 12024)) & 0x1f);
}

/* Swing_DLL.xex 0x8828C070: get u32@0x293c */
ts4_word ts4_get_u32_off293c_8828C070(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10556)) & 0x7);
}

/* Swing_DLL.xex 0x8828C260: get u32@0x5e88 */
ts4_word ts4_get_u32_off5e88_8828C260(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 24200)) & 0x1);
}

/* Swing_DLL.xex 0x8828C2A8: get u32@0x2f14 */
ts4_word ts4_get_u32_off2f14_8828C2A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12052));
}

/* Swing_DLL.xex 0x8828C350: get u32@0x2f18 */
ts4_word ts4_get_u32_off2f18_8828C350(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12056));
}

/* Swing_DLL.xex 0x8828C4F0: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_8828C4F0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548))) >> 29);
}

/* Swing_DLL.xex 0x8828C548: get u8@0x2903 */
ts4_word ts4_get_u8_off2903_8828C548(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10499));
}

/* Swing_DLL.xex 0x8828C568: get u8@0x2902 */
ts4_word ts4_get_u8_off2902_8828C568(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10498));
}

/* Swing_DLL.xex 0x8828C588: get u8@0x2901 */
ts4_word ts4_get_u8_off2901_8828C588(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10497));
}

/* Swing_DLL.xex 0x8828C5A8: get u8@0x28ff */
ts4_word ts4_get_u8_off28ff_8828C5A8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10495));
}

/* Swing_DLL.xex 0x8828C5C8: get u8@0x28fe */
ts4_word ts4_get_u8_off28fe_8828C5C8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10494));
}

/* Swing_DLL.xex 0x8828C5E8: get u8@0x28fd */
ts4_word ts4_get_u8_off28fd_8828C5E8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10493));
}

/* Swing_DLL.xex 0x8828C638: get u32@0x2944 */
ts4_word ts4_get_u32_off2944_8828C638(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10564)) & 0x3f);
}

/* Swing_DLL.xex 0x8828C648: set u32@0x2f00, fn_8828DE38 */
ts4_word ts4_set_u32_off2f00_8828C648(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12032) = (ts4_word)a1;
    return fn_8828DE38((ts4_word)a0, (ts4_word)(a0 + 12852));
}

/* Swing_DLL.xex 0x8828C658: get u32@0x2f00 */
ts4_word ts4_get_u32_off2f00_8828C658(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12032));
}

/* Swing_DLL.xex 0x8828C818: get u32@0x2a00 */
ts4_word ts4_get_u32_off2a00_8828C818(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10752));
}

/* Swing_DLL.xex 0x8828C858: get u32@0x2f04 */
ts4_word ts4_get_u32_off2f04_8828C858(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12036));
}

/* Swing_DLL.xex 0x8828C898: get u32@0x2f08 */
ts4_word ts4_get_u32_off2f08_8828C898(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12040));
}

/* Swing_DLL.xex 0x8828C8D8: get u32@0x2f0c */
ts4_word ts4_get_u32_off2f0c_8828C8D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12044));
}

/* Swing_DLL.xex 0x8828C918: get u32@0x2f10 */
ts4_word ts4_get_u32_off2f10_8828C918(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12048));
}

/* Swing_DLL.xex 0x8828C920: set u32@0x2f1c */
void ts4_set_u32_off2f1c_8828C920(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12060) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8828C928: get u32@0x2f1c */
ts4_word ts4_get_u32_off2f1c_8828C928(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12060));
}

/* Swing_DLL.xex 0x8828CC98: get u32@0x292c */
ts4_word ts4_get_u32_off292c_8828CC98(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) & 0xf);
}

/* Swing_DLL.xex 0x8828CCD8: get u16@0x292c */
ts4_word ts4_get_u16_off292c_8828CCD8(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 10540)) & 0xf);
}

/* Swing_DLL.xex 0x8828CCF8: get u8@0x292c */
ts4_word ts4_get_u8_off292c_8828CCF8(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 10540)) & 0xf);
}

/* Swing_DLL.xex 0x8828CD08: get u32@0x292c */
ts4_word ts4_get_u32_off292c_8828CD08(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540))) >> 28);
}

/* Swing_DLL.xex 0x8828CD18: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_8828CD18(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) & 0xf);
}

/* Swing_DLL.xex 0x8828CD58: get u16@0x2930 */
ts4_word ts4_get_u16_off2930_8828CD58(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 10544)) & 0xf);
}

/* Swing_DLL.xex 0x8828CD78: get u8@0x2930 */
ts4_word ts4_get_u8_off2930_8828CD78(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 10544)) & 0xf);
}

/* Swing_DLL.xex 0x8828CD88: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_8828CD88(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544))) >> 28);
}

/* Swing_DLL.xex 0x8828CDD8: get u32@0x294c */
ts4_word ts4_get_u32_off294c_8828CDD8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10572)) & 0x1);
}

/* Swing_DLL.xex 0x8828CE78: get u32@0x2fac */
ts4_word ts4_get_u32_off2fac_8828CE78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12204));
}

/* Swing_DLL.xex 0x8828CF10: get u32@0x2fb0 */
ts4_word ts4_get_u32_off2fb0_8828CF10(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12208));
}

/* Swing_DLL.xex 0x8828CFA8: get u32@0x2fb4 */
ts4_word ts4_get_u32_off2fb4_8828CFA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12212));
}

/* Swing_DLL.xex 0x8828D040: get u32@0x2fb8 */
ts4_word ts4_get_u32_off2fb8_8828D040(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12216));
}

/* Swing_DLL.xex 0x8828D0E0: get u32@0x2978 */
ts4_word ts4_get_u32_off2978_8828D0E0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10616)) & 0x3);
}

/* Swing_DLL.xex 0x8828D118: get u32@0x29c0 */
ts4_word ts4_get_u32_off29c0_8828D118(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10688)) & 0x1);
}

/* Swing_DLL.xex 0x8828D178: get u32@0x28d8 */
ts4_word ts4_get_u32_off28d8_8828D178(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10456));
}

/* Swing_DLL.xex 0x8828D1D0: get u8@0x293c */
ts4_word ts4_get_u8_off293c_8828D1D0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10556));
}

/* Swing_DLL.xex 0x8828D200: get u32@0x29cc */
ts4_word ts4_get_u32_off29cc_8828D200(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10700));
}

/* Swing_DLL.xex 0x8828D230: get u32@0x29c4 */
ts4_word ts4_get_u32_off29c4_8828D230(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10692));
}

/* Swing_DLL.xex 0x8828D258: get u32@0x29d0 */
ts4_word ts4_get_u32_off29d0_8828D258(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10704));
}

/* Swing_DLL.xex 0x8828D288: get u32@0x29c8 */
ts4_word ts4_get_u32_off29c8_8828D288(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10696));
}

/* Swing_DLL.xex 0x8828D3D0: get u8@0x2942 */
ts4_word ts4_get_u8_off2942_8828D3D0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10562));
}

/* Swing_DLL.xex 0x8828D3D8: set u32@0x35f0 */
void ts4_set_u32_off35f0_8828D3D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 13808) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8828D3E0: get u32@0x35f0 */
ts4_word ts4_get_u32_off35f0_8828D3E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 13808));
}

/* Swing_DLL.xex 0x8828D8B8: get u8@0x2f44 */
ts4_word ts4_get_u8_off2f44_8828D8B8(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12100));
}

/* Swing_DLL.xex 0x8828DA88: get u8@0x2f5e */
ts4_word ts4_get_u8_off2f5e_8828DA88(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12126));
}

/* Swing_DLL.xex 0x8828DB08: get u8@0x2f78 */
ts4_word ts4_get_u8_off2f78_8828DB08(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12152));
}

/* Swing_DLL.xex 0x882A0348: set u8@lbl_88D429E3 */
ts4_word ts4_set_u8_lbl_88D429E3_882A0348(void)
{
    *(unsigned char *)lbl_88D429E3 = (unsigned char)0;
    return 1;
}

/* Swing_DLL.xex 0x882A03F0: call_seq lbl_88D452E4, ts4_copy_bytes, u8@lbl_88D452E4 */
ts4_word ts4_call_seq_lbl_88D452E4_882A03F0(ts4_word a0)
{
    ts4_copy_bytes((ts4_word)((ts4_word)lbl_88D452E4 + 4), (ts4_word)a0, (ts4_word)260);
    *(unsigned char *)lbl_88D452E4 = (unsigned char)1;
    return 1;
}

/* Swing_DLL.xex 0x882A28D8: if_call_seq ExRegisterTitleTerminateNotification, u32@__imp_VdGlobalDevice, u32@0x0, fn_882A27E0 */
ts4_word ts4_if_call_seq_ExRegisterTitleTerminateNotification_882A28D8(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    ExRegisterTitleTerminateNotification((ts4_word)a0, (ts4_word)0);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_VdGlobalDevice)) + 0);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_882A27E0((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x882A2918: call_seq ExRegisterTitleTerminateNotification, VdShutdownEngines */
ts4_word ts4_call_seq_ExRegisterTitleTerminateNotification_882A2918(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ExRegisterTitleTerminateNotification((ts4_word)a0, (ts4_word)0);
    t2 = VdShutdownEngines((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x882A3118: call_seq u32@0x5588, fn_88295990, u32@0x5598, u32@0x5590, u32@0x558c, fn_882A0048 */
ts4_word ts4_call_seq_u32_off5588_882A3118(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    fn_88295990((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21896)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 21912);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 21904);
    fn_882A0048((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21900)), (ts4_word)t4, (ts4_word)t3);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 21916);
    fn_88295A38((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21896)), (ts4_word)t7);
    t10 = fn_88292598((ts4_word)a0);
    return t10;
}

/* Swing_DLL.xex 0x882AA5A8: if_call_seq fn_88289118, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88289118_882AA5A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88289118((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0]);
    if ((ts4_word)a1 != 0) {
        t2 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    }
    if ((ts4_word)a2 != 0) {
        t3 = loc54[0];
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    }
    return t1;
}

/* Swing_DLL.xex 0x882ABF58: call_seq fn_882AB878, fn_882ABB68, fn_882ABE00 */
ts4_word ts4_call_seq_fn_882AB878_882ABF58(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_882AB878((ts4_word)(a0 + 8), (ts4_word)a1);
    fn_882ABB68((ts4_word)a0, (ts4_word)a1);
    t3 = fn_882ABE00((ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x882ABFA8: call_seq fn_882AB878, fn_882ABB68 */
ts4_word ts4_call_seq_fn_882AB878_882ABFA8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_882AB878((ts4_word)(a0 + 8), (ts4_word)a1);
    t2 = fn_882ABB68((ts4_word)a0, (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x882ACFA8: call_seq fn_882AB878, fn_882ACDE0, fn_882ABE00 */
ts4_word ts4_call_seq_fn_882AB878_882ACFA8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_882AB878((ts4_word)(a0 + 8), (ts4_word)a1);
    fn_882ACDE0((ts4_word)a0, (ts4_word)a1, (ts4_word)3);
    t3 = fn_882ABE00((ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x882AD000: call_seq fn_882AB878, fn_882ACDE0 */
ts4_word ts4_call_seq_fn_882AB878_882AD000(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_882AB878((ts4_word)(a0 + 8), (ts4_word)a1);
    t2 = fn_882ACDE0((ts4_word)a0, (ts4_word)a1, (ts4_word)3);
    return t2;
}

/* Swing_DLL.xex 0x882AF8B0: call_seq fn_882AF630 */
ts4_word ts4_call_seq_fn_882AF630_882AF8B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = fn_882AF630((ts4_word)a0, (ts4_word)a1, (ts4_word)((int)a1 * (int)a5), (ts4_word)a2, (ts4_word)a3, (ts4_word)((int)a3 * (int)a5), (ts4_word)a4, (ts4_word)a5, (ts4_word)1, (ts4_word)a6, (ts4_word)1);
    return t1;
}

/* Swing_DLL.xex 0x882C4C40: tailcall fn_882C4A28 */
ts4_word ts4_tailcall_fn_882C4A28_882C4C40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_882C4A28((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)2);
}

/* Swing_DLL.xex 0x882C6680: tailcall fn_882C60F8 */
ts4_word ts4_tailcall_fn_882C60F8_882C6680(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_882C60F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)2);
}

/* Swing_DLL.xex 0x882C78D0: call_seq ts4_set_u32_off4_882CDA08, u32@0xc, u32@0x10, u32@0x1c, u32@0x14, u32@0x18 */
ts4_word ts4_call_seq_fn_882CDA08_882C78D0(ts4_word a0)
{
    ts4_set_u32_off4_882CDA08((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x882C7BD0: set u32@0x4, u32@0x0, u32@0x8, u32@0x38, u32@0x3c, u32@0x4c */
void ts4_set_u32_off4_882C7BD0(ts4_word a0)
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

/* Swing_DLL.xex 0x882C7C60: get u32@0x18, u32@0x1c, u32@0x20, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off18_882C7C60(ts4_word a0)
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

/* Swing_DLL.xex 0x882C7D90: tailcall fn_88569D30 */
ts4_word ts4_tailcall_fn_88569D30_882C7D90(ts4_word a0)
{
    return fn_88569D30((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x882C7D98: call_seq ts4_get_u32_off554_882E2970, fn_882C7918 */
ts4_word ts4_call_seq_fn_882E2970_882C7D98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_get_u32_off554_882E2970((ts4_word)a0);
    loc50[0] = (ts4_word)0;
    t2 = fn_882C7918((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x882CA998: call_seq u32@0x18, fn_88888668, u32@0x18, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_u32_off18_882CA998(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = fn_88888668((ts4_word)4096, (ts4_word)(612433920));
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)4096;
    return t2;
}

/* Swing_DLL.xex 0x882CDAB0: if_call_seq u32@0x4, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x4, u32@0x8, u32@0x0, fn_8857A1E0 */
ts4_word ts4_if_call_seq_u32_off4_882CDAB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t1, (ts4_word)(612433920));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t4 != -1) {
        fn_8857A1E0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    }
    return 0;
}

/* Swing_DLL.xex 0x882CE248: if_call_seq u32@0x4, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x0, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_u32_off4_882CE248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t1, (ts4_word)(612433920));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t4, (ts4_word)(612433920));
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x882DDB58: get u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off4_882DDB58(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 + 1);
    return (t1 + 1);
}

/* Swing_DLL.xex 0x882DDB70: get u32@0x8 */
ts4_word ts4_get_u32_off8_882DDB70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x882DDB78: get u32@0xc */
ts4_word ts4_get_u32_offc_882DDB78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x882DDEB0: call_seq fn_88290718 */
ts4_word ts4_call_seq_fn_88290718_882DDEB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a3;
    fn_88290718((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    return 0;
}

/* Swing_DLL.xex 0x882DDF98: call_seq fn_882907D8 */
ts4_word ts4_call_seq_fn_882907D8_882DDF98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a3;
    fn_882907D8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    return 0;
}

/* Swing_DLL.xex 0x882DE1D0: call_seq fn_88290778 */
ts4_word ts4_call_seq_fn_88290778_882DE1D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a3;
    fn_88290778((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    return 0;
}

/* Swing_DLL.xex 0x882DE310: call_seq fn_88290830 */
ts4_word ts4_call_seq_fn_88290830_882DE310(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a3;
    fn_88290830((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    return 0;
}

/* Swing_DLL.xex 0x882E1EF8: if_call_seq u32@0x4, u32@0x4, fn_882E0E78, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_u32_off4_882E1EF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 + -1);
    if ((ts4_word)t1 == 1) {
        fn_882E0E78();
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return (t1 + -1);
}

/* Swing_DLL.xex 0x882E26D8: set u32@0x548, u32@0x540, u32@0x544 */
void ts4_set_u32_off548_882E26D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1352) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1344) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1348) = (ts4_word)a3;
    return;
}

/* Swing_DLL.xex 0x882E28C0: call_seq png2_zlib_crc32_882EC228, u32@0x600 */
ts4_word ts4_call_seq_fn_882EC228_882E28C0(ts4_word a0)
{
    ts4_word t1;

    t1 = png2_zlib_crc32_882EC228((ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1536) = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x882E2960: tailcall memset */
ts4_word ts4_tailcall_fn_8856ABA0_882E2960(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return memset((ts4_word)a1, (ts4_word)0, (ts4_word)64);
}

/* Swing_DLL.xex 0x882E5320: get u32@0x1bc, u32@0xdc, u32@0x94, u32@0x1a4, u32@0xc, u32@0x10 */
void ts4_get_u32_off1bc_882E5320(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 444);
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 420) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 164) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x882E5420: get u32@0x0, u32@0x8, vcall, ts4_if_get_u32_off4_882EDDF8, lbl_8800927C, ts4_call_seq_RtlInitAnsiString_88582148 */
ts4_word ts4_get_u32_off0_882E5420(ts4_word a0)
{
    ts4_word t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    ts4_if_get_u32_off4_882EDDF8((ts4_word)a0);
    t5 = ts4_call_seq_RtlInitAnsiString_88582148((ts4_word)(ts4_word)lbl_8800927C);
    return t5;
}

/* Swing_DLL.xex 0x882E5650: get u32@0x0, u32@0x6c, u32@0x0, u32@0x14 */
void ts4_get_u32_off0_882E5650(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x882E71A0: if_get u32@0x54c, lbl_880097E8, png2_png_error_882E26E8 */
ts4_word ts4_if_get_u32_off54c_882E71A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1356);
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    }
    return png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_880097E8, (ts4_word)a2);
}

/* Swing_DLL.xex 0x882EA0A0: if_get u32@0x550, lbl_88009B0C, png2_png_error_882E26E8 */
ts4_word ts4_if_get_u32_off550_882EA0A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1360);
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    }
    return png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_88009B0C, (ts4_word)a2);
}

/* Swing_DLL.xex 0x882EC8A8: get ts4_jpeg_per_scan_setup_882EC5E0, ts4_jpeg_latch_quant_tables_882EC7D0, u32@0x1c0, u32@0x0, vcall, u32@0x1b0 */
ts4_word ts4_get_fn_882EC5E0_882EC8A8(ts4_word a0)
{
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    ts4_jpeg_per_scan_setup_882EC5E0();
    ts4_jpeg_latch_quant_tables_882EC7D0((ts4_word)a0);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 448))) + 0))))((ts4_word)a0);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 432))) + 0))))((ts4_word)a0);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 432);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 440);
    *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 4));
    return t8;
}

/* Swing_DLL.xex 0x882ECA48: get u32@0x1b8, ts4_jpeg_consume_markers_882EC918, u32@0x0, u32@0x10, u32@0x14, u32@0x18 */
ts4_word ts4_get_u32_off1b8_882ECA48(ts4_word a0)
{
    ts4_word t1;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 440);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)ts4_jpeg_consume_markers_882EC918;
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)1;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 444))) + 0))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    return t7;
}

/* Swing_DLL.xex 0x882ECAC8: get u32@0x1b8, ts4_jpeg_consume_markers_882EC918, u32@0x0 */
void ts4_get_u32_off1b8_882ECAC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 440))) + 0) = (ts4_word)(ts4_word)ts4_jpeg_consume_markers_882EC918;
    return;
}

/* Swing_DLL.xex 0x882ED028: if_get u32@0x4, u32@0x0, u32@0x14, u32@0x0, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off4_882ED028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t8;

    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)a1 != 1) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)14;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    t8 = ts4_jpeg_alloc_small_882ECB68((ts4_word)a0, (ts4_word)a1, (ts4_word)584);
    *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t8) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(t8) + 12) = (ts4_word)a5;
    *(ts4_word *)((char *)(ts4_word)(t8) + 32) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(t8) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t8) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 68));
    *(ts4_word *)((char *)(ts4_word)(t1) + 68) = (ts4_word)t8;
    return t8;
}

/* Swing_DLL.xex 0x882ED0C0: if_get u32@0x4, u32@0x0, u32@0x14, u32@0x0, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off4_882ED0C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t8;

    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)a1 != 1) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)14;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    t8 = ts4_jpeg_alloc_small_882ECB68((ts4_word)a0, (ts4_word)a1, (ts4_word)584);
    *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t8) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(t8) + 12) = (ts4_word)a5;
    *(ts4_word *)((char *)(ts4_word)(t8) + 32) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(t8) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t8) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 72));
    *(ts4_word *)((char *)(ts4_word)(t1) + 72) = (ts4_word)t8;
    return t8;
}

/* Swing_DLL.xex 0x882EDE48: get u32@0x4, u32@0x0, vcall, u32@0x80 */
ts4_word ts4_get_u32_off4_882EDE48(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))))((ts4_word)a0, (ts4_word)0, (ts4_word)132);
    *(ts4_word *)((char *)(ts4_word)(t3) + 128) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x882EDE88: get u32@0x4, u32@0x0, vcall, u32@0x114 */
ts4_word ts4_get_u32_off4_882EDE88(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))))((ts4_word)a0, (ts4_word)0, (ts4_word)280);
    *(ts4_word *)((char *)(ts4_word)(t3) + 276) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x882EE8F8: tailcall memcpy */
ts4_word ts4_tailcall_memcpy_882EE8F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return memcpy((ts4_word)a1, (ts4_word)a0, (ts4_word)(a2 << 7));
}

/* Swing_DLL.xex 0x882EE910: tailcall memset */
ts4_word ts4_tailcall_fn_8856ABA0_882EE910(ts4_word a0, ts4_word a1)
{
    return memset((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x882EF788: if_get u32@0x0, u32@0x14, u32@0x0, u32@0x0, vcall, fn_882EE920 */
ts4_word ts4_if_get_u32_off0_882EF788(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t9;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 > 65533) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)11;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    fn_882EE920((ts4_word)a0, (ts4_word)255);
    fn_882EE920((ts4_word)a0, (ts4_word)a1);
    fn_882EE920((ts4_word)a0, (ts4_word)(((int)(a2 + 2) >> 8) & 0xff));
    t9 = fn_882EE920((ts4_word)a0, (ts4_word)((a2 + 2) & 0xff));
    return t9;
}

/* Swing_DLL.xex 0x882EFAF0: call_seq fn_882EE920, fn_882EE920 */
ts4_word ts4_call_seq_fn_882EE920_882EFAF0(ts4_word a0)
{
    ts4_word t2;

    fn_882EE920((ts4_word)a0, (ts4_word)255);
    t2 = fn_882EE920((ts4_word)a0, (ts4_word)217);
    return t2;
}

/* Swing_DLL.xex 0x882F5250: get u32@0x4, u32@0x2c */
ts4_word ts4_get_u32_off4_882F5250(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 44)) - a3);
}

/* Swing_DLL.xex 0x882F5398: if_set fn_8856C130, u32@0xc, u32@0x0, lbl_880C1320, u32@0x14, u32@0x0 */
ts4_word ts4_if_set_fn_8856C130_882F5398(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t7;

    t1 = fn_8856C130();
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)t1;
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)63;
        ts4_copy_bytes((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 24), (ts4_word)(ts4_word)lbl_880C1320, (ts4_word)80);
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
        p8 = (ts4_word)t7;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(ts4_word)ts4_jpeg_read_backing_store_882F5260;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(ts4_word)ts4_jpeg_write_backing_store_882F52F8;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(ts4_word)ts4_forward_field12_of_second_arg_882F5390;
    return p8;
}

/* Swing_DLL.xex 0x882F5438: fn  */
ts4_word ts4_fn_882F5438(void)
{
    return ((983040) | 16960);
}

/* Swing_DLL.xex 0x882F5CE0: set u32@0x98, ts4_jpeg_start_iMCU_row_882F5C70 */
ts4_word ts4_set_u32_off98_882F5CE0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    return ts4_jpeg_start_iMCU_row_882F5C70((ts4_word)a0);
}

/* Swing_DLL.xex 0x882F9118: get u32@0x1c8, u32@0x13c, u32@0x5c, u32@0x74, u32@0x60 */
void ts4_get_u32_off1c8_882F9118(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
    *(ts4_word *)((char *)(ts4_word)(t1) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 316));
    *(ts4_word *)((char *)(ts4_word)(t1) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116));
    return;
}

/* Swing_DLL.xex 0x882F9268: set u32@0x0 */
void ts4_set_u32_off0_882F9268(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x882F9270: set u32@0x0 */
void ts4_set_u32_off0_882F9270(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    (void)a2;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x882F9C20: get u32@0x70, u32@0x0, ts4_jpeg_jcopy_sample_rows_882EE8A0 */
ts4_word ts4_get_u32_off70_882F9C20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    return ts4_jpeg_jcopy_sample_rows_882EE8A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)a4, (ts4_word)t1);
}

/* Swing_DLL.xex 0x882FA8E8: get u32@0x1c8, u32@0x24, u32@0x74, u32@0x2c */
void ts4_get_u32_off1c8_882FA8E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
    *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116));
    return;
}

/* Swing_DLL.xex 0x882FBD18: if_get u32@0x20, u32@0x18, u32@0xc, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off20_882FBD18(ts4_word a0)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 12))))((ts4_word)t1);
    p7 = (ts4_word)t4;
    if ((int)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
        p7 = (ts4_word)1;
    }
    return p7;
}

/* Swing_DLL.xex 0x882FD058: if_get u32@0x20, u32@0x18, u32@0xc, vcall, u32@0x20, u32@0x0 */
ts4_word ts4_if_get_u32_off20_882FD058(ts4_word a0)
{
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 12))))((ts4_word)t1);
    p11 = (ts4_word)t4;
    if ((int)t4 == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 0))) + 20) = (ts4_word)24;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 0))))((ts4_word)t7);
        p11 = (ts4_word)t10;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
    return p11;
}

/* Swing_DLL.xex 0x882FDE30: call_seq u32@0x18, u32@0x174, u32@0x0, u32@0x10, u32@0x18, u32@0x4 */
ts4_word ts4_call_seq_u32_off18_882FDE30(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
    *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 4));
    ex8_emit_eobrun_882FD3C8((ts4_word)t2);
    t7 = ex8_emit_bits_882FD0D8((ts4_word)t2, (ts4_word)127, (ts4_word)7);
    t8 = *(ts4_word *)((char *)(ts4_word)(t2) + 16);
    *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0) = (ts4_word)t8;
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 20));
    return t7;
}

/* Swing_DLL.xex 0x882FF670: if_get u32@0x15c, u32@0x0, u32@0x14, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off15c_882FF670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 348);
    p6 = (ts4_word)a0;
    if ((int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)4;
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)t7;
    *(ts4_word *)((char *)(ts4_word)(t1) + 60) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 244)) << 1);
    return p6;
}

/* Swing_DLL.xex 0x883020A8: get u32@0x154, u32@0xc, u32@0x164, u32@0x4, vcall, u32@0x164 */
ts4_word ts4_get_u32_off154_883020A8(ts4_word a0)
{
    ts4_word t7;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 12) = (ts4_word)0;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 356))) + 4))))((ts4_word)a0);
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 356))) + 8))))((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x883040B8: tailcall ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_tailcall_fn_88884DE0_883040B8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a1, (ts4_word)(612433920));
}

/* Swing_DLL.xex 0x88308AE0: if_call_seq fn_88309DB8, fn_883142A8 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308AE0(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_883142A8((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308B60: if_call_seq fn_88309DB8, fn_883089E0 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308B60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_883089E0((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308BC0: if_call_seq fn_88309DB8, ts4_get_unit_and_chunks_8830B140 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308BC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_get_unit_and_chunks_8830B140((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308C18: if_call_seq fn_88309DB8, fn_8830DA40 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308C18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830DA40((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)a7);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308DC0: if_call_seq fn_88309DB8, fn_88310500 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308DC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88310500((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308E18: if_call_seq fn_88309DB8, fn_8830B4C8 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308E18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830B4C8((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308E60: if_call_seq fn_88309DB8, fn_883105A8 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308E60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_883105A8((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308EB8: if_call_seq fn_88309DB8, fn_8830BA90 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308EB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830BA90((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308F10: if_call_seq fn_88309DB8, fn_88314960 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308F10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88314960((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308F58: if_call_seq fn_88309DB8, ts4_tailcall_fn_8830F378_88310728 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308F58(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_tailcall_fn_8830F378_88310728((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88308F90: if_call_seq fn_88309DB8, fn_8830E948 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308F90(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830E948((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309030: if_call_seq fn_88309DB8, ts4_if_get_8830B908 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309030(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_if_get_8830B908((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309108: if_call_seq fn_88309DB8, fn_8830B570 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830B570((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309160: if_call_seq fn_88309DB8, fn_8830B840 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309160(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830B840((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883091B8: if_call_seq fn_88309DB8, fn_8830C1C8 */
ts4_word ts4_if_call_seq_fn_88309DB8_883091B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830C1C8((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309258: if_call_seq fn_88309DB8, fn_88310418 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309258(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88310418((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883092A0: if_call_seq fn_88309DB8, fn_88314478 */
ts4_word ts4_if_call_seq_fn_88309DB8_883092A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88314478((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883092F0: if_call_seq fn_88309DB8, ts4_tailcall_fn_88314478_88314958 */
ts4_word ts4_if_call_seq_fn_88309DB8_883092F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_tailcall_fn_88314478_88314958((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309340: if_call_seq fn_88309DB8, fn_8830DEC0 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309340(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830DEC0((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309398: if_call_seq fn_88309DB8, fn_8830FBC8 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309398(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830FBC8((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309438: if_call_seq fn_88309DB8, fn_8830E120 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309438(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830E120((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309488: if_call_seq fn_88309DB8, fn_8830BB18 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309488(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830BB18((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883094D8: if_call_seq fn_88309DB8, fn_8830BD50 */
ts4_word ts4_if_call_seq_fn_88309DB8_883094D8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830BD50((ts4_word)t2, (ts4_word)a1, (ts4_word)0);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883095F8: if_call_seq fn_88309DB8, ts4_if_get_u32_off5198_8830C108 */
ts4_word ts4_if_call_seq_fn_88309DB8_883095F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_if_get_u32_off5198_8830C108((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88309650: if_call_seq fn_88309DB8, fn_8830C130 */
ts4_word ts4_if_call_seq_fn_88309DB8_88309650(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8830C130((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883096A0: if_get u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_883096A0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == (ts4_word)a0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t2 == (ts4_word)a0) {
            return 1;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x883099E8: if_tailcall fn_88316C80 */
ts4_word ts4_if_tailcall_fn_88316C80_883099E8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    return fn_88316C80((ts4_word)a0);
}

/* Swing_DLL.xex 0x88309A00: if_tailcall fn_88316D00 */
ts4_word ts4_if_tailcall_fn_88316D00_88309A00(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    return fn_88316D00((ts4_word)a0);
}

/* Swing_DLL.xex 0x88309A18: if_tailcall fn_88317860 */
ts4_word ts4_if_tailcall_fn_88317860_88309A18(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    return fn_88317860((ts4_word)a0);
}
