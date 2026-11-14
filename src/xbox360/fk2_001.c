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

extern char ts4_jpeg_process_data_simple_main_882F5840[];
extern char ts4_jpeg_process_data_context_main_882F58E8[];
extern char ts4_jpeg_post_process_1pass_882F8F08[];
extern char lbl_88001A20[];
extern char lbl_880260C0[];
extern char lbl_880C1320[];
extern char lbl_880D3A48[];
extern char lbl_880D4ABC[];
extern char lbl_880D4C88[];
extern char lbl_880D4CF8[];
extern char lbl_880DCFA0[];
extern char lbl_880DD1D4[];
extern char lbl_880E10D0[];
extern char lbl_880E8C58[];
extern char lbl_880E9420[];
extern char lbl_880E9F50[];
extern char lbl_880EA0BC[];
extern char lbl_880EA218[];
extern char lbl_880EF6F0[];
extern char lbl_880EF7C4[];
extern char lbl_880EFCDC[];
extern char lbl_880EFD04[];
extern char lbl_880EFE30[];
extern char lbl_880F3388[];
extern char lbl_880F3540[];
extern char lbl_880F37A4[];
extern char lbl_880F4340[];
extern char lbl_880F4420[];
extern char lbl_880F44EC[];
extern char lbl_880F4854[];
extern char lbl_880F5460[];
extern char lbl_880F54B0[];
extern char lbl_880F5588[];
extern char lbl_880F55B8[];
extern char lbl_880F560C[];
extern char lbl_880F5728[];
extern char lbl_880F8394[];
extern char lbl_880F8928[];
extern char lbl_880F8B3C[];
extern char lbl_880F8BF4[];
extern char lbl_880F8D28[];
extern char lbl_8814B440[];
extern char lbl_88B3302C[];
extern char lbl_88C6C6AC[];
extern char lbl_88D3E378[];
extern char lbl_88D3E37C[];
extern char lbl_88D41FC4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D49310[];
extern char lbl_88D49350[];
ts4_word KeGetCurrentProcessType();
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_88150600();
ts4_word fn_881519D0();
ts4_word fn_8815E358();
ts4_word ts4_call_seq_u32_off0_8815E810();
ts4_word ts4_if_call_seq_lbl_880D4C18_8815F140();
ts4_word fn_88164000();
ts4_word ts4_copy_vec3_range_8816B0F8();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_8816D1A8();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8817F480();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_8818A530();
ts4_word fn_8818EB10();
ts4_word fn_8818F320();
ts4_word fn_881928F8();
ts4_word ts4_get_u32_off0_88197750();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word ts4_call_seq_u32_off0_8819AD80();
ts4_word fn_8819B0C8();
ts4_word ts4_call_seq_u32_off0_881A2570();
ts4_word fn_881ADCD0();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word ts4_counted_ptr_assign_881C38D0();
ts4_word fn_881C8958();
ts4_word fn_881CB1A0();
ts4_word fn_881CCEE0();
ts4_word ts4_call_seq_u32_off1c_881E13E8();
ts4_word fn_881EB370();
ts4_word ts4_call_seq_fn_881EF198_881EE2C8();
ts4_word fn_881EFE08();
ts4_word fn_881F0008();
ts4_word fn_881F0388();
ts4_word fn_881F26C0();
ts4_word fn_881F4108();
ts4_word ts4_call_seq_lbl_880E9660_881F41E8();
ts4_word ts4_loop_get_u32_off14_881F4C00();
ts4_word ts4_loop_get_fn_881F5E78_881F58F0();
ts4_word ts4_loop_get_u32_off0_881F59C8();
ts4_word fn_881F5E78();
ts4_word ts4_if_get_u32_off14_881F8AD0();
ts4_word fn_881FB940();
ts4_word fn_881FBB40();
ts4_word ts4_if_call_seq_u32_off4_881FBE68();
ts4_word fn_881FFA10();
ts4_word fn_881FFE38();
ts4_word fn_88200580();
ts4_word fn_88202900();
ts4_word fn_88203888();
ts4_word fn_88203A00();
ts4_word fn_882098E0();
ts4_word ts4_if_call_seq_lbl_880E9E8C_882099C8();
ts4_word fn_8820FD80();
ts4_word ts4_call_seq_u32_off0_882125E0();
ts4_word fn_88226670();
ts4_word fn_88226CF8();
ts4_word fn_88229E78();
ts4_word fn_8822DC58();
ts4_word ts4_loop_call_seq_u32_offc_88233530();
ts4_word ts4_loop_call_seq_u32_off20_88233618();
ts4_word fn_88233678();
ts4_word fn_88233820();
ts4_word ts4_loop_get_u32_off0_88233C08();
ts4_word ts4_loop_get_u32_off0_88233CC0();
ts4_word ts4_loop_get_u32_off0_88233F80();
ts4_word fn_88233FE0();
ts4_word ts4_loop_call_seq_lbl_880F3428_882343C0();
ts4_word fn_8823ED00();
ts4_word ts4_if_call_seq_u32_off0_882594A0();
ts4_word ts4_loop_get_u32_off0_8825BF80();
ts4_word fn_8825C6C0();
ts4_word fn_8825D070();
ts4_word ts4_if_call_seq_u32_off10_8825D1A8();
ts4_word fn_8825D270();
ts4_word fn_8825DA28();
ts4_word ts4_loop_get_u32_off0_8825E428();
ts4_word ts4_if_call_seq_u32_off8_8825E668();
ts4_word fn_8825EBD0();
ts4_word fn_8825F798();
ts4_word fn_8825FC18();
ts4_word fn_8825FD78();
ts4_word ts4_loop_get_u32_off0_88260460();
ts4_word ts4_loop_get_u32_off0_88260968();
ts4_word ts4_if_call_seq_u32_off8_88261A30();
ts4_word ts4_loop_get_u32_off0_88261B50();
ts4_word fn_88261CA8();
ts4_word fn_8826C6C0();
ts4_word ts4_loop_get_u32_off0_8826DFB8();
ts4_word ts4_call_seq_fn_88617D88_88278308();
ts4_word fn_8827BD88();
ts4_word ts4_if_call_seq_u32_off8_88280958();
ts4_word fn_88286558();
ts4_word fn_882882A0();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_8828A478();
ts4_word fn_8828E1B0();
ts4_word fn_8828E500();
ts4_word fn_88292A78();
ts4_word fn_882A13A8();
ts4_word fn_882AA3C8();
ts4_word fn_882B70E0();
ts4_word fn_882C7918();
ts4_word ts4_if_call_seq_fn_882C8520_882C85B0();
ts4_word ts4_if_call_seq_u32_off4_882CDAB0();
ts4_word fn_882D22B0();
ts4_word png2_png_format_buffer_882E25D8();
ts4_word png2_png_calculate_crc_882E2900();
ts4_word ts4_state_step_882E2D10();
ts4_word ts4_if_get_u32_off54c_882E71A0();
ts4_word ts4_if_get_u32_off4_882EDD90();
ts4_word fn_882EE920();
ts4_word ex8_emit_jfif_app0_882EF568();
ts4_word ex8_emit_adobe_app14_882EF680();
ts4_word png2_png_write_chunk_start_882EFE60();
ts4_word ts4_call_seq_u32_off600_882EFEE8();
ts4_word ts4_jpeg_make_funny_pointers_882F5538();
ts4_word fn_88309DB8();
ts4_word fn_8830F8C0();
ts4_word fn_88315C60();
ts4_word fn_883164D8();
ts4_word ts4_if_call_seq_lbl_88028EA4_8831AC38();
ts4_word fn_8831F6E8();
ts4_word fn_88321048();
ts4_word fn_883210A8();
ts4_word fn_88321108();
ts4_word fn_883211E0();
ts4_word fn_88322410();
ts4_word ts4_if_set_u32_off0_8832BFC0();
ts4_word ts4_if_call_seq_u32_off0_8832CBA8();
ts4_word fn_8837C608();
ts4_word fn_885651F8();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250();
ts4_word fn_886131F0();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88618998();
ts4_word fn_88636DC8();
ts4_word ts4_msg_pool_service_get_8864DFF0();
ts4_word fn_88660D10();
ts4_word fn_886ECC38();
ts4_word fn_886F79F8();
ts4_word fn_88708E28();
ts4_word ts4_call_seq_fn_88255AA0_88714730();
ts4_word fn_887606D8();
ts4_word fn_88760C90();
ts4_word fn_88837D48();
ts4_word fn_88837FB0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_888860A0();
ts4_word fn_8899F760();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8815E908: call_seq fn_8816D1A8, u32@0x10, u32@0x28, u32@0x2c, u32@0x30, u32@0x34 */
ts4_word ts4_call_seq_fn_8816D1A8_8815E908(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[6];
    ts4_word t3;
    ts4_word t6;

    fn_8816D1A8((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    ts4_call_seq_u32_off0_8815E810((ts4_word)a0);
    t3 = fn_88608590((ts4_word)0, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a5;
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a6);
    fn_88150600((ts4_word)(a0 + 4), (ts4_word)(ts4_word)&loc50[0]);
    t6 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t6);
    return a0;
}

/* Swing_DLL.xex 0x8815F330: call_seq lbl_880D4CF8, u32@0x0, u32@0xe8, ts4_destroy_owned_object, u32@0xdc, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880D4CF8_8815F330(ts4_word a0)
{
    ts4_word t17;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4CF8;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 232)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 220)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 208)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 196)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 176)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 164)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 152)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 140)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4C88;
    t17 = ts4_if_call_seq_lbl_880D4C18_8815F140((ts4_word)a0);
    return t17;
}

/* Swing_DLL.xex 0x8818AB48: call_seq fn_881928F8, lbl_880DCFA0, u32@0x0, u32@0x34, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_881928F8_8818AB48(ts4_word a0)
{
    fn_881928F8((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCFA0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 56));
    return a0;
}

/* Swing_DLL.xex 0x881A7108: loop_call_seq u32@0x4, u32@0x0, ts4_copy_vec3_range_8816B0F8, u32@0x4, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off4_881A7108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p12;
    ts4_word p13;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p13 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 56);
        do {
            t2 = *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 4);
            t4 = ts4_copy_vec3_range_8816B0F8((ts4_word)t2, (ts4_word)t2, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 4) = (ts4_word)t4;
            t5 = *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 0);
            if ((ts4_word)t5 != 0) {
                ts4_destroy_owned_object((ts4_word)t5);
            }
            ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv1) + -44)));
            t11 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv1) + -56)));
            p12 = (ts4_word)(lv1 + 72);
            lv1 = p12;
        } while ((ts4_word)(p12 + -56) != (ts4_word)a1);
        p13 = (ts4_word)t11;
    }
    return p13;
}

/* Swing_DLL.xex 0x881B68A8: loop_call_seq u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off0_881B68A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p4;
    ts4_word p5;
    ts4_word p6;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        p4 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t3 = ts4_destroy_owned_object((ts4_word)t2);
            p4 = (ts4_word)t3;
        }
        p5 = (ts4_word)(lv1 + 12);
        lv1 = p5;
        p6 = (ts4_word)p4;
    }
    return p6;
}

/* Swing_DLL.xex 0x881E1480: if_call_seq u8@0x7d, u32@0x5c, ts4_call_seq_u32_off1c_881E13E8, fn_88837FB0, fn_881B19A0 */
ts4_word ts4_if_call_seq_u8_off7d_881E1480(ts4_word a0)
{
    ts4_word p7;
    ts4_word loc50[7];
    unsigned char t1;
    int t4;
    ts4_word t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 125);
    if ((ts4_word)(t1 & 0x20) != 0) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)0;
        loc50[6] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        loc50[4] = (ts4_word)0;
        ts4_call_seq_u32_off1c_881E13E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        t4 = loc50[2];
        p7 = (ts4_word)0;
        if ((int)t4 == 5) {
            t5 = fn_88837FB0((ts4_word)(ts4_word)&loc50[0]);
            p7 = (ts4_word)t5;
        }
        fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
        return p7;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 92));
}

/* Swing_DLL.xex 0x881E1F10: if_call_seq fn_88199068, fn_8820FD80, u8@0x48, lbl_880E8C58, u32@0x0, u32@0x4c */
ts4_word ts4_if_call_seq_fn_88199068_881E1F10(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)92, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_8820FD80((ts4_word)t1);
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 72) = (unsigned char)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E8C58;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 76) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 80) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 84) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 88) = (ts4_word)0;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x881E49E8: loop_call_seq u32@0x4, u32@0x0, ts4_call_seq_u32_off0_881A2570, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off4_881E49E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            ts4_call_seq_u32_off0_881A2570((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 4);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p10 = (ts4_word)t8;
    if ((ts4_word)t8 != 0) {
        t9 = ts4_destroy_owned_object((ts4_word)t8);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x881EFF80: if_call_seq ts4_if_call_seq_u32_off4_881FBE68, u32@0x0, u32@0x0, u32@0x0, u32@0x18, u32@0x30 */
ts4_word ts4_if_call_seq_fn_881FBE68_881EFF80(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = ts4_if_call_seq_u32_off4_881FBE68((ts4_word)a1);
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t3 + -1);
    p8 = (ts4_word)t1;
    if ((ts4_word)(t3 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t6 = fn_881F0388((ts4_word)a0, (ts4_word)(t3 + -1));
        t7 = fn_881EFE08((ts4_word)a0, (ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x881F0180: if_call_seq ts4_if_call_seq_u32_off4_881FBE68, u32@0x0, u32@0x0, u32@0x0, u32@0x18, u32@0x30 */
ts4_word ts4_if_call_seq_fn_881FBE68_881F0180(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = ts4_if_call_seq_u32_off4_881FBE68((ts4_word)a1);
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t3 + -1);
    p8 = (ts4_word)t1;
    if ((ts4_word)(t3 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t6 = fn_881F0388((ts4_word)a0, (ts4_word)(t3 + -1));
        t7 = fn_881F0008((ts4_word)a0, (ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x881F1060: addr fn_881F4108, lbl_880E9420, u32@0x0, u32@0x24, fn_881519D0, u32@0x0 */
ts4_word ts4_addr_fn_881F4108_881F1060(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_881F4108((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9420;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t2 = fn_881519D0((ts4_word)t1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(t5 + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)2;
    return a0;
}

/* Swing_DLL.xex 0x881F2498: if_call_seq u32@0x0, u32@0x4, u32@0x4, u32@0x8, fn_881F26C0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_881F2498(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p11 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t3 != 0) {
            fn_881F26C0((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 8)));
            t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
            if ((ts4_word)t6 != 0) {
                fn_881992A8((ts4_word)0, (ts4_word)t6);
            }
        }
        t10 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        p11 = (ts4_word)t10;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p11;
}

/* Swing_DLL.xex 0x881F3510: get u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off0_881F3510(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 76))))((ts4_word)a1);
}

/* Swing_DLL.xex 0x881F5958: loop_get u16@0x20, u32@0x14, u16@0x20, u32@0x0, u32@0x40, vcall */
ts4_word ts4_loop_get_u16_off20_881F5958(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    unsigned short t1;
    ts4_word t2;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(unsigned short *)((char *)(ts4_word)(a0) + 32) = (unsigned short)((((a1 << 1) | (a1 >> 31)) & 0x7fe) | (t1 & 0xfffff801));
    p9 = (ts4_word)a0;
    if ((ts4_word)t2 != 0) {
        lv3 = (ts4_word)t2;
        do {
            t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 64))))((ts4_word)lv3, (ts4_word)a1);
            p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 24));
            lv3 = p8;
        } while ((ts4_word)p8 != 0);
        p9 = (ts4_word)t6;
    }
    return p9;
}

/* Swing_DLL.xex 0x881FB860: call_seq fn_881FBB40, u32@0xe4, fn_8818A530, u32@0xe4, u32@0xe0, fn_8818A530 */
ts4_word ts4_call_seq_fn_881FBB40_881FB860(ts4_word a0)
{
    ts4_word t17;

    fn_881FBB40((ts4_word)(a0 + 224));
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 228)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    fn_881FB940((ts4_word)(a0 + 168));
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    ts4_call_seq_fn_881EF198_881EE2C8((ts4_word)(a0 + 112));
    fn_881FB940((ts4_word)(a0 + 56));
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    fn_881FB940((ts4_word)a0);
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t17 = fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return t17;
}

/* Swing_DLL.xex 0x881FD0E0: if_call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x50, u32@0x54, fn_8819B0C8 */
ts4_word ts4_if_call_seq_fn_8819B0C8_881FD0E0(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word t8;
    ts4_word t9;

    fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(volatile float *)((char *)(ts4_word)(a0) + 68) = (*(float *)((char *)(ts4_word)(a1) + 68));
    *(volatile float *)((char *)(ts4_word)(a0) + 72) = (*(float *)((char *)(ts4_word)(a1) + 72));
    *(volatile float *)((char *)(ts4_word)(a0) + 76) = (*(float *)((char *)(ts4_word)(a1) + 76));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    fn_8819B0C8((ts4_word)(a0 + 88), (ts4_word)(a1 + 88));
    fn_8819B0C8((ts4_word)(a0 + 92), (ts4_word)(a1 + 92));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    p10 = (ts4_word)t8;
    if ((ts4_word)t8 != 0) {
        t9 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
        p10 = (ts4_word)t9;
    }
    *(volatile float *)((char *)(ts4_word)(a0) + 64) = (*(float *)((char *)(ts4_word)(a1) + 64));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 100) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 100));
    return p10;
}

/* Swing_DLL.xex 0x881FD4B8: tailcall fn_88200580 */
ts4_word ts4_tailcall_fn_88200580_881FD4B8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88200580((ts4_word)a1);
}

/* Swing_DLL.xex 0x881FFDC0: if_call_seq u32@0x0, u32@-0xc, fn_881FFA10, fn_881FFE38 */
ts4_word ts4_if_call_seq_u32_off0_881FFDC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word loc50[1];
    int t2;
    ts4_word t3;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + -12);
    if ((int)t2 == 0) {
        loc50[0] = (ts4_word)0;
        p5 = (ts4_word)(ts4_word)&loc50[0];
    } else {
        t3 = fn_881FFA10((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)1);
        p5 = (ts4_word)t3;
    }
    t6 = fn_881FFE38((ts4_word)a0, (ts4_word)p5, (ts4_word)a2);
    return t6;
}

/* Swing_DLL.xex 0x882014E0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_set_u32_off0_882014E0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t1 = fn_881519D0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(t4 + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)-1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88203810: loop_call_seq u32@0x14, u32@0x0, u32@0x8, fn_881CB1A0, u32@0x0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off14_88203810(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p11;
    ts4_word p12;
    ts4_word p13;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    p14 = (ts4_word)a0;
    lv3 = (ts4_word)t2;
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t5 = fn_881CB1A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 8)), (ts4_word)(a1 + 8));
        if ((ts4_word)(t5 & 0xff) != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
            *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)t7;
            *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)t8;
            ts4_call_seq_u32_off0_881A2570((ts4_word)(lv3 + 8));
            t10 = ts4_destroy_owned_object((ts4_word)lv3);
            p11 = (ts4_word)t10;
            p12 = (ts4_word)t7;
        } else {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            p11 = (ts4_word)t5;
            p12 = (ts4_word)t6;
        }
        p13 = (ts4_word)p12;
        lv3 = p13;
        p14 = (ts4_word)p11;
    }
    return p14;
}

/* Swing_DLL.xex 0x88203970: if_tailcall fn_88203888 */
ts4_word ts4_if_tailcall_fn_88203888_88203970(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_88203888((ts4_word)a1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88203988: if_call_seq fn_88203888, u32@0x10, u32@0x1c, u32@0x14, u8@0xd, fn_88203A00 */
ts4_word ts4_if_call_seq_fn_88203888_88203988(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        fn_88203888((ts4_word)a1);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 28);
    if ((ts4_word)t4 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 20))) + 13)) != 0) {
        t8 = fn_88202900((ts4_word)a0);
        p9 = (ts4_word)t8;
    } else {
        t7 = fn_88203A00((ts4_word)a0);
        p9 = (ts4_word)t7;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 26) = (unsigned char)0;
    return p9;
}

/* Swing_DLL.xex 0x88209480: if_get u32@0x7c, u32@0x24, u32@0x0, u32@0x28, vcall, u8@0x61 */
ts4_word ts4_if_get_u32_off7c_88209480(ts4_word a0)
{
    ts4_word p14;
    ts4_word p16;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    unsigned char t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t17;
    ts4_word t18;
    ts4_word t20;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2);
    p16 = (ts4_word)(t1 + 1);
    if ((ts4_word)(t1 + 1) > (ts4_word)(t5 + -1)) {
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 97);
        if ((ts4_word)t7 != 0) {
            p14 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 180));
        } else {
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
            t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 40))))((ts4_word)t8);
            p14 = (ts4_word)(t11 + -1);
        }
        p16 = (ts4_word)p14;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    t20 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t17) + 120))))((ts4_word)a0, (ts4_word)t18, (ts4_word)p16);
    return t20;
}

/* Swing_DLL.xex 0x882095A0: if_get u32@0x80, u32@0x24, u32@0x0, u32@0x2c, vcall, u8@0x61 */
ts4_word ts4_if_get_u32_off80_882095A0(ts4_word a0)
{
    ts4_word p14;
    ts4_word p16;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    unsigned char t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t17;
    ts4_word t18;
    ts4_word t20;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 44))))((ts4_word)t2);
    p16 = (ts4_word)(t1 + 1);
    if ((ts4_word)(t1 + 1) > (ts4_word)(t5 + -1)) {
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 97);
        if ((ts4_word)t7 != 0) {
            p14 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 176));
        } else {
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
            t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 44))))((ts4_word)t8);
            p14 = (ts4_word)(t11 + -1);
        }
        p16 = (ts4_word)p14;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    t20 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t17) + 120))))((ts4_word)a0, (ts4_word)p16, (ts4_word)t18);
    return t20;
}

/* Swing_DLL.xex 0x88209EF8: get fn_882098E0, u32@0x0, u32@0x14, vcall, ts4_if_call_seq_lbl_880E9E8C_882099C8 */
ts4_word ts4_get_fn_882098E0_88209EF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[12];
    ts4_word t4;

    fn_882098E0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    ts4_if_call_seq_lbl_880E9E8C_882099C8((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x8820BE78: if_call_seq fn_88199068, fn_881F4108, u32@0x24, lbl_880E9F50, u32@0x0, u32@0x28 */
ts4_word ts4_if_call_seq_fn_88199068_8820BE78(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)60, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E9F50;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 56) = (ts4_word)0;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x8820F8A8: if_call_seq fn_881CCEE0, lbl_880C1320, lbl_880EA0BC, fn_88837D48, ts4_assign_text_from_c_string, u32@lbl_88D41FC4 */
ts4_word ts4_if_call_seq_fn_881CCEE0_8820F8A8(ts4_word a0, ts4_word a1)
{
    ts4_word p14;
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word loc5c[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    t1 = fn_881CCEE0((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) == 0) {
        p14 = (ts4_word)0;
    } else {
        t2 = fn_88837D48((ts4_word)a1, (ts4_word)(ts4_word)lbl_880EA0BC, (ts4_word)(ts4_word)lbl_880C1320);
        ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc54[0], (ts4_word)t2);
        t4 = *(ts4_word *)lbl_88D41FC4;
        t5 = ts4_get_u32_off0_88197750((ts4_word)(ts4_word)&loc58[0], (ts4_word)(t4 + 20), (ts4_word)(ts4_word)&loc54[0]);
        t6 = fn_8818EB10((ts4_word)(ts4_word)&loc5c[0], (ts4_word)t5);
        t7 = fn_881EB370((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4, (ts4_word)t6);
        ts4_counted_ptr_assign_881C38D0((ts4_word)(a0 + 52), (ts4_word)t7);
        t9 = loc50[0];
        if ((ts4_word)t9 != 0) {
            ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t9);
            loc50[0] = (ts4_word)0;
        }
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc58[0]);
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc54[0]);
        p14 = (ts4_word)1;
    }
    return p14;
}

/* Swing_DLL.xex 0x88211158: if_call_seq fn_88199068, fn_881F4108, lbl_880EA218, u32@0x0, u32@0x24 */
ts4_word ts4_if_call_seq_fn_88199068_88211158(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)40, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880EA218;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x882111D0: if_call_seq fn_881F4108, lbl_880EA218, u32@0x0, u32@0x24 */
ts4_word ts4_if_call_seq_fn_881F4108_882111D0(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA218;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211248: if_call_seq lbl_880EA218, u32@0x0, u32@0x24, ts4_if_atomic_interlocked_dec_881876D0, u32@0x24, ts4_call_seq_lbl_880E9660_881F41E8 */
ts4_word ts4_if_call_seq_lbl_880EA218_88211248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA218;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882117C0: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882117C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 308), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88212420: call_seq u32@0xc, u32@0x10, u32@0x14, fn_8816D1A8, u32@0x28, u32@0x30 */
ts4_word ts4_call_seq_u32_offc_88212420(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 24));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(a0 + 64));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 76) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 77) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88212570: call_seq u32@0xc, u32@0x10, u32@0x14, fn_8816D1A8, u32@0x28, u32@0x30 */
ts4_word ts4_call_seq_u32_offc_88212570(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 24));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(a0 + 64));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    ts4_call_seq_u32_off0_882125E0((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88212798: if_addr lbl_88C6C6AC, u32@0x4, u32@0x4, u32@0x0, u32@lbl_88D45B1C, u32@0x58 */
ts4_word ts4_if_addr_lbl_88C6C6AC_88212798(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p20;
    ts4_word loc50[6];
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t12;
    int t15;
    int t18;
    ts4_word t19;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 4);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        t4 = *(ts4_word *)lbl_88D45B1C;
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 88);
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 548);
        ((ts4_word (*)(ts4_word, ts4_word))(t5))((ts4_word)t2, (ts4_word)((ts4_word)lbl_88C6C6AC + 4));
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E10D0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 60))))((ts4_word)t6, (ts4_word)(ts4_word)&loc50[0]);
        t12 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t12);
    }
    t15 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 36);
    if ((int)t15 != 0) {
        fn_888860A0((ts4_word)t15);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 36) = (ts4_word)0;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 564);
    p20 = (ts4_word)t18;
    if ((int)t18 != 0) {
        t19 = fn_888860A0((ts4_word)t18);
        p20 = (ts4_word)t19;
    }
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C6AC) + 564) = (ts4_word)0;
    return p20;
}

/* Swing_DLL.xex 0x88213300: if_call_seq lbl_880EF6F0, u32@0x0, u32@0x28, ts4_destroy_owned_object, ts4_call_seq_lbl_880E9660_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880EF6F0_88213300(ts4_word a0, ts4_word a1)
{

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF6F0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)));
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882147E8: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882147E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 56), (ts4_word)8, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x882148A8: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882148A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 92), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88217518: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880EF7C4, u32@0x0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217518(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF7C4;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217598: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880EF7C4, u32@0x0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217598(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF7C4;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88218090: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880DD1D4, u32@0x0, u32@lbl_88D3E378, fn_88198CE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88218090(void)
{
    ts4_word p7;
    ts4_word p9;
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DD1D4;
        t4 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E378));
        loc50[0] = (ts4_word)1000;
        loc50[1] = (ts4_word)0;
        t5 = fn_88199068((ts4_word)0, (ts4_word)240, (ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)t5 != 0) {
            t6 = fn_8818F320((ts4_word)t5);
            p7 = (ts4_word)t6;
        } else {
            p7 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)p7;
        *(ts4_word *)lbl_88D3E37C = (ts4_word)t2;
        fn_88198CE0((ts4_word)t4);
        p9 = (ts4_word)t2;
    } else {
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x88219918: if_call_seq lbl_880EFCDC, u32@0x0, u32@0x8, ts4_destroy_owned_object, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880EFCDC_88219918(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88219B68: if_call_seq lbl_880EFE30, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880EFE30_88219B68(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFE30;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88219C70: if_call_seq lbl_880EFD04, u32@0x0, u32@0x4, ts4_destroy_owned_object, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880EFD04_88219C70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFD04;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88219E68: loop_call_seq u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_offc_88219E68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p6;
    ts4_word p7;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
        t5 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
        p6 = (ts4_word)(lv1 + 28);
        lv1 = p6;
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x88219EC0: if_call_seq u32@0x0, ts4_assign_formatted_text, u32@0xc, ts4_assign_formatted_text, u8@0x18, u8@0x18 */
ts4_word ts4_if_call_seq_u32_off0_88219EC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        t4 = ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12)));
        *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 24));
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x8821D338: if_call_seq lbl_880D3A48, fn_88164000, ts4_if_call_seq_u32_off0_8816D140, lbl_880D4ABC, fn_88164000, ts4_if_call_seq_u32_off0_8816D140 */
ts4_word ts4_if_call_seq_lbl_880D3A48_8821D338(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word p7;
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t6;
    ts4_word t1;
    ts4_word t3;

    if ((int)a2 == 0) {
        t4 = fn_88164000((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880D4ABC);
        ts4_if_call_seq_u32_off0_8816D140((ts4_word)a0, (ts4_word)t4);
        t6 = loc50[0];
        p7 = (ts4_word)t6;
    } else {
        t1 = fn_88164000((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880D3A48);
        ts4_if_call_seq_u32_off0_8816D140((ts4_word)a0, (ts4_word)t1);
        t3 = loc60[0];
        p7 = (ts4_word)t3;
    }
    ts4_destroy_owned_object((ts4_word)p7);
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x8821FD70: if_call_seq u32@0x8, u32@0x4, u32@0x4, fn_8825C6C0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_8821FD70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t13;
    ts4_word t15;
    ts4_word t18;
    ts4_word t16;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_8825C6C0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t13 != 0) {
        t15 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t15 != 0) {
            t18 = fn_886131F0((ts4_word)t15, (ts4_word)t13, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
            return t18;
        }
        t16 = fn_885651F8((ts4_word)t13, (ts4_word)t13);
        return t16;
    }
    return p10;
}

/* Swing_DLL.xex 0x88220B80: if_call_seq fn_887606D8, u32@0x0, u32@0x4, fn_88229E78, fn_8823ED00, u32@0x4 */
ts4_word ts4_if_call_seq_fn_887606D8_88220B80(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[38];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t10;

    t1 = fn_887606D8((ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)a1 < (ts4_word)((int)(t3 - t2) / (int)140)) {
        t5 = fn_8823ED00((ts4_word)t3, (ts4_word)t3, (ts4_word)(((int)a1 * 140) + t2), (ts4_word)t1);
        ts4_loop_get_u32_off0_88261B50((ts4_word)t5, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t5;
    } else {
        fn_88229E78((ts4_word)a0, (ts4_word)t3, (ts4_word)(a1 - ((int)(t3 - t2) / (int)140)), (ts4_word)t1);
    }
    t10 = fn_88760C90((ts4_word)(ts4_word)&loc50[0]);
    return t10;
}

/* Swing_DLL.xex 0x88222590: if_get u32@0xc, u32@0x4, fn_88226CF8, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_offc_88222590(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
            *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
            *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 12);
        return a0;
    }
    return fn_88226CF8((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x882225E0: if_call_seq ts4_call_seq_fn_88255AA0_88714730, u32@0x0, u32@0x4, u32@0x4, fn_8822DC58, fn_88226670 */
ts4_word ts4_if_call_seq_fn_88714730_882225E0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;

    t1 = ts4_call_seq_fn_88255AA0_88714730((ts4_word)(ts4_word)&loc50[0]);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)a1 < (ts4_word)((int)(t3 - t2) / (int)20)) {
        fn_88226670((ts4_word)a0, (ts4_word)(((a1 + (a1 << 2)) << 2) + t2), (ts4_word)t3, (ts4_word)t1);
    } else {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
        fn_8822DC58((ts4_word)a0, (ts4_word)t4, (ts4_word)(a1 - ((int)(t4 - t2) / (int)20)), (ts4_word)t1);
    }
    t8 = fn_886F79F8((ts4_word)(ts4_word)&loc50[0]);
    return t8;
}

/* Swing_DLL.xex 0x88224070: if_call_seq u32@0x0, u32@0x4, ts4_loop_call_seq_u32_offc_88233530, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88224070(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_call_seq_u32_offc_88233530((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x882240E8: if_call_seq u32@0x0, u32@0x4, ts4_loop_call_seq_u32_off20_88233618, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_882240E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_call_seq_u32_off20_88233618((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88224160: if_call_seq u32@0x0, u32@0x4, fn_88233678, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88224160(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = fn_88233678((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x882246C8: if_call_seq fn_886ECC38, u32@0x48, u32@0x84, u32@0x80, u32@0x80, fn_88233820 */
ts4_word ts4_if_call_seq_fn_886ECC38_882246C8(ts4_word a0)
{
    ts4_word p6;
    int t2;
    ts4_word t3;
    ts4_word t8;

    fn_886ECC38((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p6 = (ts4_word)0;
    if ((int)t2 != -1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        p6 = (ts4_word)((int)(t3 - (*(ts4_word *)((char *)(ts4_word)(a0) + 128))) / (int)104);
    }
    t8 = fn_88233820((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)), (ts4_word)p6);
    return t8;
}

/* Swing_DLL.xex 0x88224AD8: if_call_seq fn_88708E28, u32@0x48, u32@0x84, u32@0x80, u32@0x80, fn_88233820 */
ts4_word ts4_if_call_seq_fn_88708E28_88224AD8(ts4_word a0)
{
    ts4_word p6;
    int t2;
    ts4_word t3;
    ts4_word t8;

    fn_88708E28();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p6 = (ts4_word)0;
    if ((int)t2 != -1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        p6 = (ts4_word)((int)(t3 - (*(ts4_word *)((char *)(ts4_word)(a0) + 128))) / (int)104);
    }
    t8 = fn_88233820((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)), (ts4_word)p6);
    return t8;
}

/* Swing_DLL.xex 0x88225D70: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_88233C08, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88225D70(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_88233C08((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88226C80: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_88233CC0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88226C80(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_88233CC0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88227D00: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_88233F80, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88227D00(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_88233F80((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88227E60: if_call_seq u32@0x0, u32@0x4, fn_88233FE0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88227E60(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = fn_88233FE0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88228578: loop_call_seq u32@0x4, u32@0x0, u32@0x8, ts4_destroy_owned_object, u32@0x0, u32@lbl_88D45B38 */
ts4_word ts4_loop_call_seq_u32_off4_88228578(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t9;
    ts4_word t11;
    ts4_word t14;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p7 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t5 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 8)));
            p6 = (ts4_word)(lv3 + 32);
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t1);
        p7 = (ts4_word)t5;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t9 != 0) {
        t11 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t11 != 0) {
            t14 = fn_886131F0((ts4_word)t11, (ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t14;
        }
        t12 = fn_885651F8((ts4_word)t9, (ts4_word)t9);
        return t12;
    }
    return p7;
}

/* Swing_DLL.xex 0x882287D8: if_call_seq u32@0x4, u32@0x0, fn_88233678, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_882287D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_88233678((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88228BC8: if_call_seq u32@0x4, u32@0x0, fn_8825D270, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88228BC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_8825D270((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88229348: if_call_seq u32@0x4, u32@0x0, ts4_loop_call_seq_lbl_880F3428_882343C0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88229348(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_call_seq_lbl_880F3428_882343C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x882296A8: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_88233F80, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_882296A8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_88233F80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88229720: if_call_seq u32@0x4, u32@0x0, fn_88233FE0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88229720(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_88233FE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88229A78: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_88260968, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88229A78(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_88260968((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88229AF0: loop_call_seq u32@0x4, u32@0x0, fn_8825DA28, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_loop_call_seq_u32_off4_88229AF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t10;
    ts4_word t13;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = fn_8825DA28((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 4);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
        p6 = (ts4_word)t4;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t8 != 0) {
        t10 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t10 != 0) {
            t13 = fn_886131F0((ts4_word)t10, (ts4_word)t8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t13;
        }
        t11 = fn_885651F8((ts4_word)t8, (ts4_word)t8);
        return t11;
    }
    return p6;
}

/* Swing_DLL.xex 0x88229B60: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_88260460, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88229B60(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_88260460((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88233460: loop_get u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_88233460(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 0))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 44);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88234BD0: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_88233C08, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88234BD0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_88233C08((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88234F00: loop_call_seq u32@0x4, u32@0x0, ts4_if_call_seq_u32_off0_882594A0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_loop_call_seq_u32_off4_88234F00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t10;
    ts4_word t13;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = ts4_if_call_seq_u32_off0_882594A0((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 16);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
        p6 = (ts4_word)t4;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t8 != 0) {
        t10 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t10 != 0) {
            t13 = fn_886131F0((ts4_word)t10, (ts4_word)t8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t13;
        }
        t11 = fn_885651F8((ts4_word)t8, (ts4_word)t8);
        return t11;
    }
    return p6;
}

/* Swing_DLL.xex 0x88255AA0: if_call_seq u32@lbl_88D45B38, fn_88618998, u32@lbl_88D45B38, u32@0x0, u32@0x0, ts4_if_call_seq_fn_88883CD0_8860D250 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    p4 = (ts4_word)t1;
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88618998((ts4_word)t1, (ts4_word)((4143382528) | 43071));
        t3 = *(ts4_word *)lbl_88D45B38;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
        p4 = (ts4_word)t3;
        p5 = (ts4_word)t2;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p9 = (ts4_word)p5;
    if ((ts4_word)t6 == 0) {
        if ((ts4_word)p4 != 0) {
            t7 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)p4);
            p8 = (ts4_word)t7;
        } else {
            p8 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p8;
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Swing_DLL.xex 0x8825AE40: get u32@0x14, u32@0x18, u32@0x1c, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off14_8825AE40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 28);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x8825B330: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_8825E428, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_8825B330(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_8825E428((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825BA10: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_8825BF80, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_8825BA10(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_8825BF80((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825BEF8: if_call_seq lbl_880F3388, u32@0x0, u32@0x24, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880F3388_8825BEF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3388;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            fn_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8825BFE0: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_8825BF80, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_8825BFE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_8825BF80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825C0D0: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_8825E428, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_8825C0D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_8825E428((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825C148: loop_call_seq u32@0x4, u32@0x0, fn_886F79F8, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_loop_call_seq_u32_off4_8825C148(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t10;
    ts4_word t13;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = fn_886F79F8((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 20);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
        p6 = (ts4_word)t4;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t8 != 0) {
        t10 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t10 != 0) {
            t13 = fn_886131F0((ts4_word)t10, (ts4_word)t8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t13;
        }
        t11 = fn_885651F8((ts4_word)t8, (ts4_word)t8);
        return t11;
    }
    return p6;
}

/* Swing_DLL.xex 0x8825D208: if_call_seq ts4_if_call_seq_u32_off10_8825D1A8, u32@0xc, u32@0x0, u32@0x8, u32@0x0, u32@-0x4 */
ts4_word ts4_if_call_seq_fn_8825D1A8_8825D208(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;

    ts4_if_call_seq_u32_off10_8825D1A8();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        *(ts4_word *)((char *)(ts4_word)(t4) + -4) = (ts4_word)((int)(t2 - (*(ts4_word *)((char *)(ts4_word)(t3) + 0))) / (int)20);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 4);
    }
    t8 = fn_8825D070((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x8825D318: if_call_seq u32@0x0, u32@0x4, fn_8825D270, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_8825D318(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = fn_8825D270((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825E6C8: if_call_seq ts4_if_call_seq_u32_off8_8825E668, u32@0x4, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8825E668_8825E6C8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    t1 = ts4_if_call_seq_u32_off8_8825E668();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t7 = fn_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
            return t7;
        }
        t5 = fn_885651F8((ts4_word)t2, (ts4_word)t2);
        return t5;
    }
    return t1;
}

/* Swing_DLL.xex 0x8825E738: if_call_seq u32@0x4, u32@0x0, ts4_loop_call_seq_u32_off0_88150378, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_8825E738(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825F130: if_call_seq u32@0x4, u32@0x0, fn_8825FC18, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_8825F130(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_8825FC18((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825F830: call_seq fn_8825EBD0, fn_8825F798, fn_8825F798, fn_8825FD78 */
ts4_word ts4_call_seq_fn_8825EBD0_8825F830(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[34];
    ts4_word t4;

    fn_8825EBD0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 32));
    fn_8825F798((ts4_word)(a1 + 32), (ts4_word)(a0 + 32));
    fn_8825F798((ts4_word)(a0 + 32), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_8825FD78((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x8825F898: if_call_seq u32@0x0, u32@0x4, fn_8825FC18, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_8825F898(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = fn_8825FC18((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x8825FEC8: if_call_seq u32@0x0, u32@0x4, ts4_loop_call_seq_u32_off0_88150378, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_8825FEC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_call_seq_u32_off0_88150378((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88260010: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_88260460, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88260010(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_88260460((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88260600: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_88260968, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88260600(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_88260968((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88260BE0: if_call_seq u32@0x4, u32@0x0, ts4_loop_get_u32_off0_88261B50, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_88260BE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_loop_get_u32_off0_88261B50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88261A90: if_call_seq ts4_if_call_seq_u32_off8_88261A30, u32@0x4, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88261A30_88261A90(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    t1 = ts4_if_call_seq_u32_off8_88261A30();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t7 = fn_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
            return t7;
        }
        t5 = fn_885651F8((ts4_word)t2, (ts4_word)t2);
        return t5;
    }
    return t1;
}

/* Swing_DLL.xex 0x88261BB0: if_call_seq u32@0x0, u32@0x4, ts4_loop_get_u32_off0_88261B50, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88261BB0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = ts4_loop_get_u32_off0_88261B50((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88261D00: if_call_seq u32@0x0, u32@0x4, fn_88261CA8, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off0_88261D00(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = fn_88261CA8((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t6 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t6 != 0) {
            t9 = fn_886131F0((ts4_word)t6, (ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t9;
        }
        t7 = fn_885651F8((ts4_word)t4, (ts4_word)t4);
        return t7;
    }
    return t3;
}

/* Swing_DLL.xex 0x88261D78: if_call_seq lbl_880F3540, u32@0x0, u32@0x20, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3540_88261D78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3540;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88262A98: if_call_seq lbl_880F37A4, u32@0x0, u32@0xc, ts4_destroy_owned_object, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F37A4_88262A98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F37A4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88262DF0: if_get u32@0x0, u32@0x4, u32@0x14, u32@0x10, u32@0x14, u32@0x10 */
ts4_word ts4_if_get_u32_off0_88262DF0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(t3 + 1);
    if ((ts4_word)t4 == (ts4_word)((int)(t2 - t1) / (int)132)) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
        return t1;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(t4 + 1);
    return (((int)t4 * 132) + t1);
}

/* Swing_DLL.xex 0x88266680: loop_get u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_88266680(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 0))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 16);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x882666E0: loop_get u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_882666E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 0))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 132);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88269EE0: tailcall fn_88660D10 */
ts4_word ts4_tailcall_fn_88660D10_88269EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return fn_88660D10((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Swing_DLL.xex 0x8826A098: if_call_seq lbl_880F4854, u32@0x0, u32@0x8, ts4_destroy_owned_object, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F4854_8826A098(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4854;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A260: set u32@0x1c, u8@0x8, fn_881B9148 */
ts4_word ts4_set_u32_off1c_8826A260(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x8826A338: if_call_seq lbl_880F4340, u32@0x0, u32@0x1c, ts4_destroy_owned_object, u32@0x4, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F4340_8826A338(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4340;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826AA78: if_call_seq lbl_880F4420, u32@0x0, u32@0xc, u32@0x8, ts4_loop_get_u32_off0_8826DFB8, u32@0x8 */
ts4_word ts4_if_call_seq_lbl_880F4420_8826AA78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4420;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_loop_get_u32_off0_8826DFB8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826AAF0: if_call_seq lbl_880F44EC, u32@0x0, u32@0x3c, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F44EC_8826AAF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F44EC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826B478: if_call_seq u32@0x4, u32@0x0, u32@0x4, fn_8826C6C0, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off4_8826B478(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p15;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t12;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_8826C6C0((ts4_word)a0, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4)));
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4) = (ts4_word)0;
        t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(volatile ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p9 = (ts4_word)t4;
    }
    t12 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    p15 = (ts4_word)p9;
    if ((ts4_word)t12 != 0) {
        t13 = fn_8815E358((ts4_word)p9);
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D49310) + 8));
        *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D49310) + 8) = (ts4_word)t12;
        *(volatile ts4_word *)lbl_88D49350 = (ts4_word)0;
        p15 = (ts4_word)t13;
    }
    return p15;
}

/* Swing_DLL.xex 0x8826C568: loop_get u32@0x4, u32@0x0, u32@0xc, u32@0x4, u8@0x0, u8@0x0 */
ts4_word ts4_loop_get_u32_off4_8826C568(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p11 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 12);
            p9 = (ts4_word)t4;
            if (((ts4_word)t4 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(lv3) + 4)) > 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(lv3) + 0)) == 0) {
                *(unsigned char *)((char *)(ts4_word)(lv3) + 0) = (unsigned char)1;
                t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a1) + 0))))((ts4_word)t4);
                p9 = (ts4_word)t8;
            }
            p10 = (ts4_word)(lv3 + 16);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t1);
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x8826DF58: loop_get u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_8826DF58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 0))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 8);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x882744D8: get  */
void ts4_get_882744D8(ts4_word a0)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 64);
    *(float *)((char *)(ts4_word)(a0) + 60) = (t1 + (*(float *)((char *)(ts4_word)(a0) + 56)));
    return;
}

/* Swing_DLL.xex 0x88275A48: set u32@0x4c, u32@0x50, u8@0x8, fn_881B9148 */
ts4_word ts4_set_u32_off4c_88275A48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88275F58: if_call_seq lbl_880F5588, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F5588_88275F58(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5588;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88275FC0: if_call_seq lbl_880F5728, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F5728_88275FC0(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5728;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88276500: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88278308, lbl_880F560C, u32@0x0, u32@0x38 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276500(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_fn_88617D88_88278308((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F560C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 56) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276588: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88278308, lbl_880F560C, u32@0x0, u32@0x38 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276588(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_fn_88617D88_88278308((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F560C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 56) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88277250: if_call_seq lbl_880F55B8, u32@0x0, u32@0x58, ts4_destroy_owned_object, lbl_880F54B0, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880F55B8_88277250(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F55B8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F54B0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t6 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x882779A0: if_call_seq lbl_880F560C, u32@0x0, u32@0x38, ts4_destroy_owned_object, lbl_880F54B0, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880F560C_882779A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F560C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F54B0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t6 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88277A00: loop_get u32@0x3c, u32@0x38, u32@0x0, u32@0x0, u32@0x8, vcall */
ts4_word ts4_loop_get_u32_off3c_88277A00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    p9 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 8))))((ts4_word)t4);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88278240: if_call_seq lbl_880F54B0, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F54B0_88278240(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F54B0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882782A8: call_seq ts4_call_seq_fn_88617D88_88278308, lbl_880F5460, u32@0x44, u32@0x0 */
ts4_word ts4_call_seq_fn_88278308_882782A8(ts4_word a0)
{
    float t2;

    ts4_call_seq_fn_88617D88_88278308();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    t2 = *(float *)lbl_8814B440;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5460;
    *(volatile float *)((char *)(ts4_word)(a0) + 64) = t2;
    *(volatile float *)((char *)(ts4_word)(a0) + 60) = t2;
    *(volatile float *)((char *)(ts4_word)(a0) + 56) = t2;
    *(volatile float *)((char *)(ts4_word)(a0) + 72) = t2;
    return a0;
}

/* Swing_DLL.xex 0x88278450: if_call_seq ts4_msg_pool_service_get_8864DFF0, fn_8899F760, u32@0x0, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_fn_8864DFF0_88278450(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t5;

    ts4_msg_pool_service_get_8864DFF0();
    t2 = fn_8899F760((ts4_word)12);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0));
        p4 = (ts4_word)t2;
    } else {
        p4 = (ts4_word)0;
    }
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t5 == 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p4;
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(p4) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8));
        *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4) = (ts4_word)p4;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1);
    return t2;
}

/* Swing_DLL.xex 0x88278A68: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88278A68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 28), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8827A370: if_get u32@0x8, u32@0x4, fn_881ADCD0, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off8_8827A370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
            *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
            *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
            *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 16);
        return a0;
    }
    return fn_881ADCD0((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x8827BF00: if_call_seq ts4_if_call_seq_u32_off4_881FBE68, u32@0x0, u32@0x0, u32@0x0, u32@0x18, u32@0x30 */
ts4_word ts4_if_call_seq_fn_881FBE68_8827BF00(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = ts4_if_call_seq_u32_off4_881FBE68((ts4_word)a1);
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t3 + -1);
    p8 = (ts4_word)t1;
    if ((ts4_word)(t3 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t6 = fn_881F0388((ts4_word)a0, (ts4_word)(t3 + -1));
        t7 = fn_8827BD88((ts4_word)a0, (ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x8827C288: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8827C288(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 276), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8827C828: if_get u32@0xc, u32@0x0, u32@0x14, vcall, u32@0xc, u32@0x0 */
ts4_word ts4_if_get_u32_offc_8827C828(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t5;
    int t11;
    ts4_word t15;
    ts4_word t22;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t5 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
        }
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t11 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 20))))((ts4_word)t11);
        t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((ts4_word)t15 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 0))))((ts4_word)t15, (ts4_word)1);
        }
    }
    t22 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t22;
}

/* Swing_DLL.xex 0x8827EB48: if_call_seq lbl_880F8394, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F8394_8827EB48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8394;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8827ED28: if_get u32@0x4, u32@0x70, u32@0x1c, u32@0x1c, u32@0x2c, u32@0x0 */
ts4_word ts4_if_get_u32_off4_8827ED28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    int t2;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 112);
    if ((int)t2 == 2) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 32))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return t3;
}

/* Swing_DLL.xex 0x8827FB18: if_call_seq lbl_880F8BF4, u32@0x0, u32@0x20, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F8BF4_8827FB18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8BF4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8827FE38: if_call_seq lbl_880F8D28, u32@0x0, u32@0x34, ts4_destroy_owned_object, u32@0x28, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F8D28_8827FE38(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8D28;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 52)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882803B8: if_call_seq ts4_if_call_seq_u32_off8_88280958, u32@0x4, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88280958_882803B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    t1 = ts4_if_call_seq_u32_off8_88280958();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t7 = fn_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
            return t7;
        }
        t5 = fn_885651F8((ts4_word)t2, (ts4_word)t2);
        return t5;
    }
    return t1;
}

/* Swing_DLL.xex 0x882829A0: if_call_seq u32@0x1000, u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off1000_882829A0(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4096);
    if ((ts4_word)(t1 + 32) <= (ts4_word)(a0 + 4096)) {
        if ((ts4_word)t1 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
            *(volatile unsigned char *)((char *)(ts4_word)(t1) + 28) = (unsigned char)0;
            p5 = (ts4_word)t1;
        } else {
            p5 = (ts4_word)0;
        }
        t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4100);
        t7 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4096)) + 0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4100) = (ts4_word)(t6 + 1);
        *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4096)) + 0) = (ts4_word)(t7 + 32);
        return p5;
    }
    t3 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2, (ts4_word)a0, (ts4_word)(a0 + 4096), (ts4_word)t1);
    if ((ts4_word)t3 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t3) + 28) = (unsigned char)0;
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88282ED8: loop_get u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_88282ED8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 0))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 36);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88282F38: if_call_seq u32@0x0, u32@0x4, u32@0x0, u32@0x4, u32@0x8, ts4_if_call_seq_u32_lbl_88D45B38_8817F480 */
ts4_word ts4_if_call_seq_u32_off0_88282F38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    p5 = (ts4_word)0;
    if ((int)((int)(t2 - t1) / (int)20) != 0) {
        t3 = ts4_if_call_seq_u32_lbl_88D45B38_8817F480((ts4_word)(a0 + 8), (ts4_word)((int)(t2 - t1) / (int)20), (ts4_word)0, (ts4_word)a3, (ts4_word)a4, (ts4_word)(t2 - t1), (ts4_word)t2, (ts4_word)20);
        p5 = (ts4_word)t3;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p5;
    *(volatile ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0) = (ts4_word)(((((int)(t2 - t1) / (int)20) + (((int)(t2 - t1) / (int)20) << 2)) << 2) + p5);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t8 = fn_88286558((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)t6, (ts4_word)p5);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return a0;
}

/* Swing_DLL.xex 0x882846D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8394, u32@0x0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882846D8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8394;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284760: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8394, u32@0x0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284760(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8394;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284D18: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8928, u32@0x0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284D18(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8928;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284DA0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8928, u32@0x0, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284DA0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8928;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882854D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88636DC8, lbl_880F8B3C, u32@0x0, u32@0x2c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882854D8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88636DC8((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8B3C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285558: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88636DC8, lbl_880F8B3C, u32@0x0, u32@0x2c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285558(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88636DC8((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8B3C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8828AB18: get u32@0x2c */
ts4_word ts4_get_u32_off2c_8828AB18(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) >> 6) & 0xf) + 1);
}

/* Swing_DLL.xex 0x8828AE88: get u32@0x30, u32@0x20, fn_882882A0 */
ts4_word ts4_get_u32_off30_8828AE88(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_882882A0((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Swing_DLL.xex 0x8828B1C0: get u32@0x1c, u32@0x18, fn_8828A478 */
ts4_word ts4_get_u32_off1c_8828B1C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return fn_8828A478((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)((t1 >> 22) & 0x3f), (ts4_word)((t1) >> 28), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x8828B1E0: get u32@0x18, u32@0x30, u32@0x20, fn_882882A0 */
ts4_word ts4_get_u32_off18_8828B1E0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    return fn_882882A0((ts4_word)t1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 32)) & 0xfffff000), (ts4_word)(t2 & 0xfffff000));
}

/* Swing_DLL.xex 0x8828D3E8: get u32@0x2efc, u32@0x2efc */
void ts4_get_u32_off2efc_8828D3E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12028) = (ts4_word)((((a1 << 23) | (a1 >> 9)) & 0x3f800000) | ((*(ts4_word *)((char *)(ts4_word)(a0) + 12028)) & 0xc07fffff));
    return;
}

/* Swing_DLL.xex 0x88290888: set u64@0x0, u64@0x8, u64@0x10, u64@0x18, u64@0x20, u32@0x0 */
void ts4_set_u64_off0_88290888(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)7;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(4294901760);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x882A26D8: loop_call_seq KeGetCurrentProcessType, fn_882A13A8, u32@0x30, fn_8828E500, fn_8828E1B0, fn_88292A78 */
ts4_word ts4_loop_call_seq_KeGetCurrentProcessType_882A26D8(ts4_word a0)
{
    ts4_word lv6;
    ts4_word p8;
    ts4_word p19;
    int t1;
    ts4_word t4;
    ts4_word t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t18;

    t1 = KeGetCurrentProcessType();
    if ((int)t1 != 2) {
        fn_882A13A8((ts4_word)a0);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t4 != 0) {
        fn_8828E500((ts4_word)a0, (ts4_word)0);
        lv6 = (ts4_word)0;
        do {
            fn_8828E1B0((ts4_word)a0, (ts4_word)lv6, (ts4_word)0);
            p8 = (ts4_word)(lv6 + 1);
            lv6 = p8;
        } while ((ts4_word)p8 < 4);
        fn_88292A78((ts4_word)a0);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 15040);
    if ((ts4_word)t11 != 0) {
        ts4_if_atomic_interlocked_dec_88288530((ts4_word)t11);
        *(ts4_word *)((char *)(ts4_word)(a0) + 15040) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 15044);
    if ((ts4_word)t14 != 0) {
        ts4_if_atomic_interlocked_dec_88288530((ts4_word)t14);
        *(ts4_word *)((char *)(ts4_word)(a0) + 15044) = (ts4_word)0;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 15036);
    p19 = (ts4_word)t17;
    if ((ts4_word)t17 != 0) {
        t18 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)t17);
        *(ts4_word *)((char *)(ts4_word)(a0) + 15036) = (ts4_word)0;
        p19 = (ts4_word)t18;
    }
    return p19;
}

/* Swing_DLL.xex 0x882AA580: call_seq fn_882AA3C8 */
ts4_word ts4_call_seq_fn_882AA3C8_882AA580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[6];
    ts4_word t1;

    t1 = fn_882AA3C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x882BD470: if_call_seq u32@0x10, fn_882B70E0, u32@0x60, u32@0x64, u32@0x68, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off10_882BD470(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    int t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p4 = (ts4_word)a3;
    if ((int)t1 != 0) {
        t2 = fn_882B70E0();
        p4 = (ts4_word)t2;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t9 = memcpy((ts4_word)((((int)t5 * (int)a1) + ((int)t6 * (int)a2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32))), (ts4_word)p4, (ts4_word)(t7 << 4));
    return t9;
}

/* Swing_DLL.xex 0x882C7CF0: if_call_seq u32@0x18, u32@0x4, u32@0x18, u32@0x14, fn_882C7918 */
ts4_word ts4_if_call_seq_u32_off18_882C7CF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    p6 = (ts4_word)a0;
    if ((ts4_word)(4096 - t2) != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
        t5 = fn_882C7918((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 20)), (ts4_word)t3, (ts4_word)(4096 - t2), (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x882C8520: if_call_seq u32@0x4, u32@0x38, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x8, u32@0x3c, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_u32_off4_882C8520(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p14;
    ts4_word t1;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t1, (ts4_word)(612433920));
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t5 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t5, (ts4_word)(612433920));
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t9 != 0) {
        ts4_if_call_seq_fn_882C8520_882C85B0((ts4_word)t9, (ts4_word)1);
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    p14 = (ts4_word)t12;
    if ((ts4_word)t12 != 0) {
        t13 = ts4_if_call_seq_fn_882C8520_882C85B0((ts4_word)t12, (ts4_word)1);
        p14 = (ts4_word)t13;
    }
    return p14;
}

/* Swing_DLL.xex 0x882CDB18: if_get u32@0x0, ts4_if_call_seq_u32_off4_882CDAB0 */
ts4_word ts4_if_get_u32_off0_882CDB18(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 == -1) {
        return a0;
    }
    return ts4_if_call_seq_u32_off4_882CDAB0((ts4_word)a0);
}

/* Swing_DLL.xex 0x882D86B0: if_call_seq u32@0x10, fn_882D22B0, u32@0x60, u32@0x64, u32@0x68, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off10_882D86B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    int t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p4 = (ts4_word)a3;
    if ((int)t1 != 0) {
        t2 = fn_882D22B0();
        p4 = (ts4_word)t2;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t9 = memcpy((ts4_word)((((int)t5 * (int)a1) + ((int)t6 * (int)a2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32))), (ts4_word)p4, (ts4_word)(t7 << 4));
    return t9;
}

/* Swing_DLL.xex 0x882DDE28: if_get u16@0x8, u16@0xa */
ts4_word ts4_if_get_u16_off8_882DDE28(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    (void)a0;
    t1 = *(unsigned short *)((char *)(ts4_word)((~(a1 | a1))) + 8);
    if ((ts4_word)t1 != 3) {
        return -1;
    }
    return (*(unsigned short *)((char *)(ts4_word)((~(a1 | a1))) + 10));
}

/* Swing_DLL.xex 0x882E2720: if_get u32@0x544 */
ts4_word ts4_if_get_u32_off544_882E2720(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1348);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
}

/* Swing_DLL.xex 0x882E2780: if_get png2_png_format_buffer_882E25D8, u32@0x544, vcall */
ts4_word ts4_if_get_fn_882E25D8_882E2780(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[20];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = png2_png_format_buffer_882E25D8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 1348);
    p4 = (ts4_word)t1;
    if ((ts4_word)t2 != 0) {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))(t2))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x882E2FA8: if_get u32@0x14, u32@0x0, u32@0x14, u32@0x0, u32@0x14, u32@0x18 */
ts4_word ts4_if_get_u32_off14_882E2FA8(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p16;
    ts4_word p17;
    int t1;
    ts4_word t3;
    int t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 != 200 && (int)t1 != 201) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)20;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    t9 = ts4_state_step_882E2D10((ts4_word)a0);
    if ((int)t9 != 1) {
        p16 = (ts4_word)t9;
        if ((int)t9 == 2) {
            if ((int)a1 != 0) {
                *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)51;
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
            }
            ts4_if_get_u32_off4_882EDD90((ts4_word)a0);
            p16 = (ts4_word)2;
        }
        p17 = (ts4_word)p16;
    } else {
        p17 = (ts4_word)1;
    }
    return p17;
}

/* Swing_DLL.xex 0x882E3070: loop_get u32@0x14, u32@0x1a8, u32@0x0, vcall, u32@0x8c, u32@0x14 */
ts4_word ts4_loop_get_u32_off14_882E3070(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    int t9;
    int t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 != 204) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 424))) + 0))))((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)204;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 424))) + 8);
    if ((int)t9 != 0) {
        do {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)48;
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
            t15 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 424))) + 8);
        } while ((int)t15 != 0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 68)) == 0) ^ 1) + 205);
    return 1;
}

/* Swing_DLL.xex 0x882E3128: if_get u32@0x14, u32@0x0, u32@0x14, u32@0x0, u32@0x14, u32@0x18 */
ts4_word ts4_if_get_u32_off14_882E3128(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t19;
    ts4_word t22;
    ts4_word t23;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 != 205) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)20;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t9 >= (ts4_word)t10) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)123;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)-1);
        return 0;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t12 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)t9;
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        *(ts4_word *)((char *)(ts4_word)(t13) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116));
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 0))))((ts4_word)a0);
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 428);
    loc50[0] = (ts4_word)0;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t19) + 4))))((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    t23 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(t23 + t22);
    return t23;
}

/* Swing_DLL.xex 0x882E5470: get u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off0_882E5470(ts4_word a0)
{
    ts4_word loc50[50];
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x882E54A0: if_get u32@0x0, u32@0x6c, u32@0x68, u32@0x68, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off0_882E54A0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p12;
    ts4_word t1;
    int t8;
    ts4_word t11;
    int t4;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)a1 < 0) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t1) + 108);
        p12 = (ts4_word)a0;
        if ((int)t8 == 0 || (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 104)) >= 3) {
            t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 8))))((ts4_word)a0);
            p12 = (ts4_word)t11;
        }
        *(ts4_word *)((char *)(ts4_word)(t1) + 108) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 108)) + 1);
        return p12;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 104);
    p7 = (ts4_word)a0;
    if ((int)t4 >= (int)a1) {
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 8))))((ts4_word)a0);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x882E71C0: if_get u32@0x620 */
ts4_word ts4_if_get_u32_off620_882E71C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1568);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
}

/* Swing_DLL.xex 0x882E8028: if_get u32@0x8 */
ts4_word ts4_if_get_u32_off8_882E8028(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return ((*(ts4_word *)((char *)(ts4_word)(a1) + 8)) & a2);
    }
    return 0;
}

/* Swing_DLL.xex 0x882E8050: if_get u32@0xc */
ts4_word ts4_if_get_u32_offc_882E8050(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    }
    return 0;
}

/* Swing_DLL.xex 0x882E8070: if_get u8@0x1d */
ts4_word ts4_if_get_u8_off1d_882E8070(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return (*(unsigned char *)((char *)(ts4_word)(a1) + 29));
    }
    return 0;
}

/* Swing_DLL.xex 0x882EE788: if_get u32@0x54, u32@0x1a8, u32@0x1d0, u32@0x8, vcall, u32@0xc */
ts4_word ts4_if_get_u32_off54_882EE788(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    int t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 424);
    p6 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 464))) + 8))))((ts4_word)a0);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 12)) + 1);
    return p6;
}

/* Swing_DLL.xex 0x882EF810: if_call_seq u32@0x164, fn_882EE920, fn_882EE920, u32@0x1c, u32@0xd0, ex8_emit_jfif_app0_882EF568 */
ts4_word ts4_if_call_seq_u32_off164_882EF810(ts4_word a0)
{
    ts4_word p6;
    ts4_word p9;
    ts4_word t1;
    ts4_word t3;
    int t4;
    ts4_word t5;
    int t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 356);
    fn_882EE920((ts4_word)a0, (ts4_word)255);
    t3 = fn_882EE920((ts4_word)a0, (ts4_word)216);
    *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    p6 = (ts4_word)t3;
    if ((int)t4 != 0) {
        t5 = ex8_emit_jfif_app0_882EF568((ts4_word)a0);
        p6 = (ts4_word)t5;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 220);
    p9 = (ts4_word)p6;
    if ((int)t7 != 0) {
        t8 = ex8_emit_adobe_app14_882EF680((ts4_word)a0);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x882EFF30: get u8@0x61c, lbl_880260C0, ts4_if_get_u32_off54c_882E71A0 */
ts4_word ts4_get_u8_off61c_882EFF30(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1564);
    return ts4_if_get_u32_off54c_882E71A0((ts4_word)a0, (ts4_word)(t1 + (ts4_word)lbl_880260C0), (ts4_word)(8 - t1));
}

/* Swing_DLL.xex 0x882F0400: if_call_seq png2_png_write_chunk_start_882EFE60, png2_png_calculate_crc_882E2900, ts4_if_get_u32_off54c_882E71A0, ts4_call_seq_u32_off600_882EFEE8 */
ts4_word ts4_if_call_seq_fn_882EFE60_882F0400(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t5;

    png2_png_write_chunk_start_882EFE60((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
    if ((ts4_word)a2 != 0 && (ts4_word)a3 != 0) {
        png2_png_calculate_crc_882E2900((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
        ts4_if_get_u32_off54c_882E71A0((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    }
    t5 = ts4_call_seq_u32_off600_882EFEE8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x882F5230: if_get u8@-0x1, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_get_u8_0x1_882F5230(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)(a1 - (*(unsigned char *)((char *)(ts4_word)(a1) + -1))), (ts4_word)(612433920));
}

/* Swing_DLL.xex 0x882F5A90: if_get u32@0x1ac, u32@0x1c8, u32@0x8, u32@0x1c8, u32@0x8, ts4_jpeg_process_data_simple_main_882F5840 */
ts4_word ts4_if_get_u32_off1ac_882F5A90(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word p12;
    ts4_word t1;
    ts4_word t11;
    int t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 428);
    if ((int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)4;
        t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
        p12 = (ts4_word)t11;
    } else {
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 456))) + 8);
        if ((int)t5 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(ts4_word)ts4_jpeg_process_data_context_main_882F58E8;
            t6 = ts4_jpeg_make_funny_pointers_882F5538();
            *(ts4_word *)((char *)(ts4_word)(t1) + 64) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t1) + 68) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t1) + 76) = (ts4_word)0;
            p7 = (ts4_word)t6;
        } else {
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(ts4_word)ts4_jpeg_process_data_simple_main_882F5840;
            p7 = (ts4_word)a0;
        }
        *(ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)0;
        p12 = (ts4_word)p7;
    }
    return p12;
}

/* Swing_DLL.xex 0x882F8FA0: if_get u32@0x1b4, u32@0x54, u32@0x54, u32@0x1c8, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_off1b4_882F8FA0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word p18;
    ts4_word t1;
    ts4_word t17;
    int t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 436);
    if ((int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)4;
        t17 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
        p18 = (ts4_word)t17;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        if ((int)t3 != 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(ts4_word)ts4_jpeg_post_process_1pass_882F8F08;
            p12 = (ts4_word)a0;
            if ((ts4_word)t6 == 0) {
                t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                t8 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
                t9 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
                t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 28))))((ts4_word)a0, (ts4_word)t9, (ts4_word)0, (ts4_word)t8, (ts4_word)1);
                *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)t11;
                p12 = (ts4_word)t11;
            }
            p13 = (ts4_word)p12;
        } else {
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 456))) + 4));
            p13 = (ts4_word)a0;
        }
        p18 = (ts4_word)p13;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
    return p18;
}

/* Swing_DLL.xex 0x88302100: if_get u32@0x174, u32@0x154, u32@0x8, vcall, u32@0x14, u32@0x14 */
ts4_word ts4_if_get_u32_off174_88302100(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    int t10;
    int t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 340);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 8))))((ts4_word)a0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 20);
    if ((ts4_word)t5 >= 1) {
        if ((ts4_word)t5 != 1) {
            if ((ts4_word)t5 < 3) {
                t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
                if ((int)t10 != 0) {
                    *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)1;
                }
                *(ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 32)) + 1);
            }
        } else {
            *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)2;
        }
    } else {
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)2;
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
        if ((int)t6 == 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 32)) + 1);
        }
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 24)) + 1);
    return t4;
}

/* Swing_DLL.xex 0x883061E0: get u32@0x50, u16@0x0, u32@0x148, u32@0x0, u16@0x0, u8@0x80 */
ts4_word ts4_get_u32_off50_883061E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    unsigned short t2;
    ts4_word t3;
    ts4_word t4;
    unsigned short t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 80);
    t2 = *(unsigned short *)((char *)(ts4_word)(a2) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 328);
    t4 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t5 = *(unsigned short *)((char *)(ts4_word)(t1) + 0);
    *(unsigned char *)((char *)(ts4_word)(t4) + a4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(((((int)(((int)((short)t5) * (int)((short)t2)) + 4) >> 3) & 0x3ff) + t3)) + 128));
    return (((int)((short)t5) * (int)((short)t2)) + 4);
}

/* Swing_DLL.xex 0x88307CC0: get u32@0x24, u32@0x28 */
ts4_word ts4_get_u32_off24_88307CC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)a0);
}

/* Swing_DLL.xex 0x88308D58: if_call_seq fn_88309DB8, u32@0x5630, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308D58(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        if ((ts4_word)a1 == 0) {
            return 37;
        }
        t2 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 22064));
        return 0;
    }
    return t1;
}

/* Swing_DLL.xex 0x8830B0C0: if_tail fn_8831F6E8, fn_8831F6E8, fn_8831F6E8, fn_8831F6E8 */
ts4_word ts4_if_tail_fn_8831F6E8_8830B0C0(ts4_word a0, int a1, ts4_word a2)
{
    if ((int)a1 == 10) {
        return fn_8831F6E8((ts4_word)(a0 + 23448), (ts4_word)a2);
    }
    if ((int)a1 == 9) {
        return fn_8831F6E8((ts4_word)(a0 + 24008), (ts4_word)a2);
    }
    if ((int)a1 == 7) {
        return fn_8831F6E8((ts4_word)(a0 + 23728), (ts4_word)a2);
    }
    if ((int)a1 == 11) {
        return fn_8831F6E8((ts4_word)(a0 + 24288), (ts4_word)a2);
    }
    return 25;
}

/* Swing_DLL.xex 0x8830B4C8: if_get u32@0x5374, fn_88321108, u32@0x5374, fn_88321048, u32@0x5374, fn_883210A8 */
ts4_word ts4_if_get_u32_off5374_8830B4C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 >= 3) {
                return 37;
            }
            return fn_883210A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21364)), (ts4_word)a2, (ts4_word)a3);
        }
        return fn_88321048((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21364)), (ts4_word)a2, (ts4_word)a3);
    }
    return fn_88321108((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21364)), (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x8830B508: if_get  */
ts4_word ts4_if_get_8830B508(ts4_word a0, float f1, float f2, float f3)
{
    float t1;

    t1 = *(float *)lbl_88001A20;
    if (f1 < t1) {
        return 37;
    }
    if (!(f2 > t1)) {
        return 37;
    }
    if (f3 < t1) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a0) + 21356) = f1;
    *(float *)((char *)(ts4_word)(a0) + 21348) = f2;
    *(float *)((char *)(ts4_word)(a0) + 21352) = f3;
    return 0;
}

/* Swing_DLL.xex 0x8830B548: if_set u32@0x5360 */
ts4_word ts4_if_set_u32_off5360_8830B548(ts4_word a0, ts4_word a1)
{
    if ((int)a1 >= 1 && (int)a1 <= 4) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 21344) = (ts4_word)a1;
        return 0;
    }
    return 37;
}

/* Swing_DLL.xex 0x8830BA90: if_call_seq u32@0x5374, u32@0x0, u32@0x5374, fn_883211E0, u32@0x5374, fn_88322410 */
ts4_word ts4_if_call_seq_u32_off5374_8830BA90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word p9;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 21364);
    loc50[0] = (ts4_word)0;
    if ((ts4_word)t1 == 0) {
        p9 = (ts4_word)81;
    } else {
        if ((ts4_word)a2 == 0) {
            p8 = (ts4_word)37;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
            t3 = fn_883211E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21364)), (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
            p7 = (ts4_word)t3;
            if ((int)t3 == 0) {
                t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 21364);
                t5 = loc50[0];
                t6 = fn_88322410((ts4_word)t4, (ts4_word)t5, (ts4_word)a2);
                p7 = (ts4_word)t6;
            }
            p8 = (ts4_word)p7;
        }
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Swing_DLL.xex 0x8830BF10: if_get u32@0x0, u32@0x0, ts4_if_call_seq_u32_off0_8832CBA8 */
ts4_word ts4_if_get_u32_off0_8830BF10(ts4_word a0, ts4_word a1)
{
    int t2;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t2 >= 0 && (int)t2 < 4) {
        return ts4_if_call_seq_u32_off0_8832CBA8((ts4_word)(a0 + 22452), (ts4_word)a1);
    }
    return 73;
}

/* Swing_DLL.xex 0x8830C1C8: if_set u32@0x5628, u32@0x562c */
ts4_word ts4_if_set_u32_off5628_8830C1C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    if ((((ts4_word)a2 != 1 && (ts4_word)a2 != 2) && (ts4_word)a2 != 4) && (ts4_word)a2 != 8) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 22056) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 22060) = (ts4_word)a2;
    return 0;
}

/* Swing_DLL.xex 0x8830C5E8: if_get u32@0x5360, u32@0x0 */
ts4_word ts4_if_get_u32_off5360_8830C5E8(ts4_word a0, int a1, ts4_word a2)
{
    if (((ts4_word)a2 != 0 && (int)a1 >= 0) && (int)a1 < (int)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 21344))) {
        *(volatile ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((((int)a1 * 112) + a0) + 20896);
        return 0;
    }
    return 37;
}

/* Swing_DLL.xex 0x8830FBC8: if_get u32@0x5194, u32@0x5194, fn_8830F8C0, fn_8830F8C0 */
ts4_word ts4_if_get_u32_off5194_8830FBC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    if ((ts4_word)a2 == 0) {
        return 37;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20884);
    if ((ts4_word)t2 != 0) {
        return fn_8830F8C0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1, (ts4_word)1);
    }
    return fn_8830F8C0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)1);
}

/* Swing_DLL.xex 0x88316400: if_call_seq u32@0x4, u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_88316400(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 == 0) {
        t4 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t4;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t6 + 1);
    return t7;
}

/* Swing_DLL.xex 0x883165A8: if_call_seq fn_883164D8, fn_8837C608, u32@0x44, u32@0x14, u32@0x18, u32@0x20 */
ts4_word ts4_if_call_seq_fn_883164D8_883165A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    if ((ts4_word)a1 != 0 && (int)a2 != 0) {
        fn_883164D8((ts4_word)a0);
        t2 = fn_8837C608((ts4_word)((a1 + 255) & 0xffffff00), (ts4_word)(((a1 - ((a1 + 255) & 0xffffff00)) + a2) & ~(a3 + -1)), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
            t3 = ts4_if_call_seq_lbl_88028EA4_8831AC38((ts4_word)(a0 + 72), (ts4_word)1);
            return t3;
        }
        return 44;
    }
    return 44;
}

/* Swing_DLL.xex 0x883168A8: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x28, vcall */
ts4_word ts4_if_get_fn_8832BFC0_883168A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[2];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316920: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316920(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word loc50[2];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p10 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            p9 = (ts4_word)56;
        } else {
            t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 76))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88316A38: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x5c, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316A38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word loc50[2];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p10 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            p9 = (ts4_word)56;
        } else {
            t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 92))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88316AB8: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x60, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316AB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[2];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 96))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316B30: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x64, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316B30(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 100))))((ts4_word)t4, (ts4_word)a1);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316C00: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x84, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316C00(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 132))))((ts4_word)t4, (ts4_word)a1);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316C80: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x88, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316C80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word loc50[2];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p10 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            p9 = (ts4_word)56;
        } else {
            t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 136))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88316D00: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x8c, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316D00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 140))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316D80: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0x9c, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316D80(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 156))))((ts4_word)t4, (ts4_word)a1);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316E00: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0xa0, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316E00(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 160))))((ts4_word)t4, (ts4_word)a1);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316E80: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0xa4, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316E80(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 164))))((ts4_word)t4, (ts4_word)a1);
        return t8;
    }
    return t1;
}
