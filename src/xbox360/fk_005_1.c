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
extern char ts4_get_fn_882EC5E0_882EC8A8[];
extern char ts4_jpeg_consume_markers_882EC918[];
extern char ts4_get_u32_off1b8_882ECA48[];
extern char ts4_get_u32_off1b8_882ECAC8[];
extern char ts4_if_get_u32_off0_882EF788[];
extern char fn_882EF810[];
extern char ex8_write_frame_header_882EF888[];
extern char ex8_write_scan_header_882EF9D8[];
extern char ts4_call_seq_fn_882EE920_882EFAF0[];
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
ts4_word fn_882E0E78();
ts4_word png2_png_error_882E26E8();
ts4_word png2_png_calculate_crc_882E2900();
ts4_word ts4_if_get_u32_off550_882EA0A0();
ts4_word png2_zlib_crc32_882EC228();
ts4_word ts4_jpeg_per_scan_setup_882EC5E0();
ts4_word ts4_jpeg_latch_quant_tables_882EC7D0();
ts4_word ts4_jpeg_alloc_small_882ECB68();
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
ts4_word ts4_if_call_seq_fn_8832EBE0_8830C130();
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
ts4_word ts4_close_and_free_883142A8();
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
ts4_word ts4_if_call_seq_fn_88617D88_88625DA0();
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

/* Swing_DLL.xex 0x882CDA08: set u32@0x4, u32@0x0, u32@0x8 */
void ts4_set_u32_off4_882CDA08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x882E2970: get u32@0x554 */
ts4_word ts4_get_u32_off554_882E2970(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 1364));
}

/* Swing_DLL.xex 0x882ECAE0: get u32@0x4, u32@0x0, vcall, u32@0x1b8, ts4_jpeg_consume_markers_882EC918, ts4_get_u32_off1b8_882ECA48 */
ts4_word ts4_get_u32_off4_882ECAE0(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))))((ts4_word)a0, (ts4_word)0, (ts4_word)28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 440) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)ts4_jpeg_consume_markers_882EC918;
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(ts4_word)ts4_get_u32_off1b8_882ECA48;
    *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(ts4_word)ts4_get_fn_882EC5E0_882EC8A8;
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(ts4_word)ts4_get_u32_off1b8_882ECAC8;
    *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)1;
    return t3;
}

/* Swing_DLL.xex 0x882EDDF8: if_get u32@0x4, u32@0x28, vcall, u32@0x4, u32@0x14 */
ts4_word ts4_if_get_u32_off4_882EDDF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 40))))((ts4_word)a0);
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x882EFCB0: get u32@0x4, u32@0x0, vcall, u32@0x164, fn_882EF810, ex8_write_frame_header_882EF888 */
ts4_word ts4_get_u32_off4_882EFCB0(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))))((ts4_word)a0, (ts4_word)1, (ts4_word)32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 356) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)fn_882EF810;
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(ts4_word)ex8_write_frame_header_882EF888;
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(ts4_word)ex8_write_scan_header_882EF9D8;
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(ts4_word)ts4_call_seq_fn_882EE920_882EFAF0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)(ts4_word)ex8_write_tables_only_882EFB30;
    *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)(ts4_word)ts4_if_get_u32_off0_882EF788;
    *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(ts4_word)ts4_forward_882EF808;
    *(ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x882F36C8: call_seq ts4_if_get_u32_off550_882EA0A0, png2_png_calculate_crc_882E2900 */
ts4_word ts4_call_seq_fn_882EA0A0_882F36C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    ts4_if_get_u32_off550_882EA0A0((ts4_word)a0);
    t2 = png2_png_calculate_crc_882E2900((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t2;
}

