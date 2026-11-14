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

extern char lbl_88001A20[];
extern char lbl_88002378[];
extern char lbl_8800394C[];
extern char lbl_88004210[];
extern char lbl_88004DBC[];
extern char lbl_88007D18[];
extern char lbl_8800967C[];
extern char lbl_88009804[];
extern char lbl_8800983C[];
extern char lbl_88009B28[];
extern char lbl_88009B60[];
extern char lbl_88025AF0[];
extern char lbl_88026570[];
extern char lbl_8802658C[];
extern char lbl_880267C8[];
extern char lbl_88028900[];
extern char lbl_880390E4[];
extern char lbl_8803913C[];
extern char lbl_8803943C[];
extern char lbl_880395AC[];
extern char lbl_8803964C[];
extern char lbl_880396B0[];
extern char lbl_88039714[];
extern char lbl_88039734[];
extern char lbl_88039750[];
extern char lbl_8803977C[];
extern char lbl_8803978C[];
extern char lbl_88039850[];
extern char lbl_88039864[];
extern char lbl_88039874[];
extern char lbl_8803988C[];
extern char lbl_880398A0[];
extern char lbl_88039A20[];
extern char lbl_88039B00[];
extern char lbl_88039BC8[];
extern char lbl_88039BEC[];
extern char lbl_88B310D0[];
extern char lbl_88B3302C[];
extern char lbl_88B3B4B8[];
extern char lbl_88C6E210[];
extern char lbl_88CAC988[];
extern char lbl_88CAC994[];
extern char lbl_88CAC9A8[];
extern char lbl_88D3E3A8[];
extern char lbl_88D459B4[];
ts4_word KeSetEvent();
ts4_word fn_88159180();
ts4_word ts4_if_call_seq_u32_off0_88159A58();
ts4_word fn_8818A0F8();
ts4_word fn_88195368();
ts4_word fn_88195FD0();
ts4_word fn_881960A8();
ts4_word fn_88196188();
ts4_word fn_88196268();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_88289D38();
ts4_word fn_88289E38();
ts4_word ts4_get_u32_off2c_8828AB18();
ts4_word fn_88292598();
ts4_word fn_88295990();
ts4_word fn_8829C5C8();
ts4_word fn_882B7420();
ts4_word fn_882C1728();
ts4_word fn_882C28B0();
ts4_word fn_882C2B78();
ts4_word ts4_two_step_report_failure_882C35D0();
ts4_word fn_882C7918();
ts4_word ts4_if_call_seq_u32_off4_882C8520();
ts4_word fn_882D2220();
ts4_word fn_882D25F0();
ts4_word fn_882DBBA0();
ts4_word ts4_if_call_seq_lbl_88004430_882DC5E8();
ts4_word fn_882DDC70();
ts4_word fn_882E1A68();
ts4_word png2_png_error_882E26E8();
ts4_word ts4_if_get_u32_off544_882E2720();
ts4_word png2_png_chunk_error_882E2738();
ts4_word ex6_png_read_transform_info_882E84A8();
ts4_word fn_882EB390();
ts4_word fn_882EB450();
ts4_word png2_png_create_struct_882EC0E0();
ts4_word ts4_call_seq_lbl_880260D8_882F0808();
ts4_word ex8_png_check_chunk_name_882F37C8();
ts4_word ex8_png_read_start_row_882F4028();
ts4_word ex7_png_crc_finish_882F42A8();
ts4_word png2_zlib_inflate_blocks_reset_883040C8();
ts4_word ts4_if_call_seq_fn_88309DB8_88308D58();
ts4_word ts4_if_call_seq_fn_88309DB8_88309160();
ts4_word ts4_if_call_seq_fn_88309DB8_883092F0();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word ts4_if_call_seq_fn_88322CA8_88316F78();
ts4_word ts4_if_call_seq_fn_88322CA8_88317910();
ts4_word ts4_if_call_seq_fn_8832F930_88317A28();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word fn_883228E0();
ts4_word fn_8832E208();
ts4_word fn_8832EDB0();
ts4_word fn_8832F538();
ts4_word ts4_call_seq_ts4_memset_8832F8F0();
ts4_word fn_8836CD70();
ts4_word fn_883CB130();
ts4_word fn_883CBF10();
ts4_word fn_883CC388();
ts4_word fn_883CD3B0();
ts4_word fn_883D0668();
ts4_word fn_883D0B68();
ts4_word fn_883D38C8();
ts4_word fn_883D7F20();
ts4_word fn_883DA438();
ts4_word fn_883DCA00();
ts4_word fn_883DCC58();
ts4_word fn_883E2C28();
ts4_word fn_883E40F8();
ts4_word ts4_if_call_seq_u32_off8_883E5158();
ts4_word ts4_if_get_u32_lbl_88CAC9A8_883E63D8();
ts4_word fn_883E9A50();
ts4_word ts4_addr_lbl_88039DD8_883F3238();
ts4_word ts4_addr_lbl_88039EC0_883F61E0();
ts4_word fn_883F9F68();
ts4_word ts4_tailcall_fn_88564B00_88564770();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word fn_88883CD0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_88888668();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_lookup_then_forward_88308D10();
ts4_word ts4_lookup_then_forward_88309078();
ts4_word ts4_lookup_then_forward_883090C0();
ts4_word ts4_memset();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8815D328: if_call_seq fn_88159180, ts4_if_call_seq_u32_off0_88159A58, ts4_if_call_seq_u32_off0_88159A58, u8@0x2c, u8@0x2c */
ts4_word ts4_if_call_seq_fn_88159180_8815D328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        fn_88159180();
        ts4_if_call_seq_u32_off0_88159A58((ts4_word)(a0 + 20), (ts4_word)(a1 + 20));
        t3 = ts4_if_call_seq_u32_off0_88159A58((ts4_word)(a0 + 32), (ts4_word)(a1 + 32));
        *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 44));
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x8818AFC0: if_call_seq u32@lbl_88D3E3A8, fn_88195368, fn_88195FD0 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A8_8818AFC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_88195FD0((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3);
    return a0;
}

/* Swing_DLL.xex 0x8818B010: if_call_seq u32@lbl_88D3E3A8, fn_88195368, fn_881960A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A8_8818B010(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_881960A8((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return a0;
}

/* Swing_DLL.xex 0x8818B068: if_call_seq u32@lbl_88D3E3A8, fn_88195368, fn_88196188 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A8_8818B068(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_88196188((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return a0;
}

/* Swing_DLL.xex 0x8818B0C0: if_call_seq u32@lbl_88D3E3A8, fn_88195368, fn_88196268 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A8_8818B0C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_88196268((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return a0;
}

/* Swing_DLL.xex 0x8818B590: if_call_seq u32@0x20, u32@0x10, u32@0x14, u32@0x18, u32@0x1c, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off20_8818B590(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)) != 0) {
        t3 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x8818C588: if_call_seq u32@0x0, u32@lbl_88D459B4, fn_88883CD0, u32@0x0, fn_8818A0F8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8818C588(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t11;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        t3 = fn_88883CD0((ts4_word)(*(ts4_word *)lbl_88D459B4));
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
        p6 = (ts4_word)t4;
        if ((int)t4 == -1 || (ts4_word)t4 == 0) {
            t5 = fn_8818A0F8((ts4_word)t3);
            p6 = (ts4_word)t5;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p6;
    }
    t11 = fn_88198CE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t12 = fn_88199068((ts4_word)0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    fn_88198CE0((ts4_word)t11);
    return t12;
}

/* Swing_DLL.xex 0x88233590: if_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off0_88233590(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t10;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p11 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
        t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t4;
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t5;
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t6;
        ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)a2, (ts4_word)t6, (ts4_word)t5, (ts4_word)t4, (ts4_word)t3, (ts4_word)t2);
        t10 = ts4_assign_formatted_text((ts4_word)(a0 + 36), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36)));
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x88282E68: loop_call_seq u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_offc_88282E68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p7;
    ts4_word p8;
    ts4_word p9;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 8);
        do {
            t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 12);
            if ((ts4_word)t2 != 0) {
                ts4_destroy_owned_object((ts4_word)t2);
            }
            t5 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
            p7 = (ts4_word)t5;
            if ((ts4_word)t5 != 0) {
                t6 = ts4_destroy_owned_object((ts4_word)t5);
                p7 = (ts4_word)t6;
            }
            p8 = (ts4_word)(lv1 + 36);
            lv1 = p8;
        } while ((ts4_word)(p8 + -8) != (ts4_word)a1);
        p9 = (ts4_word)p7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88289118: if_set u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_set_u32_off0_88289118(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p1;
    ts4_word p2;
    ts4_word p3;
    ts4_word p4;

    if ((ts4_word)a0 <= 44) {
        if ((ts4_word)a0 != 44) {
            if ((ts4_word)a0 >= 11) {
                if ((ts4_word)a0 > 12) {
                    if ((ts4_word)a0 > 17) {
                        if ((ts4_word)a0 > 20) {
                            if ((ts4_word)a0 != 39) {
                                if ((ts4_word)a0 == 40) {
                                    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)2;
                                    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
                                    return;
                                }
                                *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
                                *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
                                return;
                            }
                            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)4;
                            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
                            return;
                        }
                        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)4;
                        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)4;
                        return;
                    }
                    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
                    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
                    return;
                }
                *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)2;
                *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)4;
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)1;
        return;
    }
    if ((ts4_word)a0 != 49) {
        if ((ts4_word)a0 > 50) {
            if ((ts4_word)a0 > 53) {
                if ((ts4_word)a0 <= 57 || (ts4_word)a0 > 61) {
                    p1 = (ts4_word)1;
                } else {
                    p1 = (ts4_word)4;
                }
                p2 = (ts4_word)p1;
            } else {
                p2 = (ts4_word)4;
            }
            p3 = (ts4_word)p2;
        } else {
            p3 = (ts4_word)1;
        }
        p4 = (ts4_word)p3;
    } else {
        p4 = (ts4_word)4;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)p4;
    return;
}

/* Swing_DLL.xex 0x8828B128: if_call_seq u32@0x0, u32@0x28, u32@0x8, u32@0xc, u32@0x14, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8828B128(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)(t1 & 0x40000000) != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t8 = fn_88289D38((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)((t6) >> 28), (ts4_word)a1);
        p9 = (ts4_word)t8;
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) >> 18) + 1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) >> 3) & 0x7fff) + 1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 24)) & 0x3);
        p9 = (ts4_word)a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)4;
    return p9;
}

/* Swing_DLL.xex 0x8828B230: call_seq u32@0x1c, u32@0x18, fn_88289E38, u32@0x4 */
ts4_word ts4_call_seq_u32_off1c_8828B230(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = fn_88289E38((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)((t1) >> 28), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)16;
    return t3;
}

/* Swing_DLL.xex 0x8828C240: if_get u32@0x5e88, u32@0x5e88 */
void ts4_if_get_u32_off5e88_8828C240(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24200);
    if ((ts4_word)a1 != 0) {
        p2 = (ts4_word)(t1 | 1);
    } else {
        p2 = (ts4_word)(t1 & 0xfffffffe);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24200) = (ts4_word)p2;
    return;
}

/* Swing_DLL.xex 0x8828D5A0: get u8@0x2f92 */
ts4_word ts4_get_u8_off2f92_8828D5A0(ts4_word a0, ts4_word a1)
{
    return (((*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12178)) >> 1) & 0x1);
}

/* Swing_DLL.xex 0x8828D740: get u8@0x2f92 */
ts4_word ts4_get_u8_off2f92_8828D740(ts4_word a0, ts4_word a1)
{
    return ((*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12178)) & 0x1);
}

/* Swing_DLL.xex 0x8828D790: get u32@0x48c */
ts4_word ts4_get_u32_off48c_8828D790(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1164)) >> 23) & 0x3);
}

/* Swing_DLL.xex 0x8828D840: get u8@0x2f92 */
ts4_word ts4_get_u8_off2f92_8828D840(ts4_word a0, ts4_word a1)
{
    return (((*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12178)) >> 2) & 0x1);
}

/* Swing_DLL.xex 0x8828DBC0: get  */
ts4_word ts4_get_8828DBC0(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(((int)(a1 + 48) * 24)) + a0)) >> 10) & 0x7);
}

/* Swing_DLL.xex 0x8828DC10: get  */
ts4_word ts4_get_8828DC10(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(((int)(a1 + 48) * 24)) + a0)) >> 13) & 0x7);
}

/* Swing_DLL.xex 0x8828DC60: get  */
ts4_word ts4_get_8828DC60(ts4_word a0, ts4_word a1)
{
    return ((*(unsigned short *)((char *)(ts4_word)(((int)(a1 + 48) * 24)) + a0)) & 0x7);
}

/* Swing_DLL.xex 0x8828DCB8: get u32@0x494 */
ts4_word ts4_get_u32_off494_8828DCB8(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1172)) >> 3) & 0x3);
}

/* Swing_DLL.xex 0x8828DD10: get u32@0x490 */
ts4_word ts4_get_u32_off490_8828DD10(ts4_word a0, ts4_word a1)
{
    return ((int)((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1168)) << 5) >> 27);
}

/* Swing_DLL.xex 0x8828DD68: get u32@0x490 */
ts4_word ts4_get_u32_off490_8828DD68(ts4_word a0, ts4_word a1)
{
    return ((int)(*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1168)) >> 27);
}

/* Swing_DLL.xex 0x8828DDC0: get u32@0x494 */
ts4_word ts4_get_u32_off494_8828DDC0(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1172)) >> 2) & 0x1);
}

/* Swing_DLL.xex 0x8828DE20: get u32@0x484 */
ts4_word ts4_get_u32_off484_8828DE20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1156);
    return (((~(t1 | t1)) >> 11) & 0x1);
}

/* Swing_DLL.xex 0x88299FA0: get u32@0x54, u32@0x54, u32@0x54, KeSetEvent */
ts4_word ts4_get_u32_off54_88299FA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(((((*(ts4_word *)((char *)(ts4_word)(a1) + 84)) & 0x3) + 23) << 2)) + a1) = (ts4_word)a2;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 84);
    *(ts4_word *)((char *)(ts4_word)(a1) + 84) = (ts4_word)(t2 + 1);
    return KeSetEvent((ts4_word)(a1 + 60), (ts4_word)1, (ts4_word)0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a2, (ts4_word)(t2 + 1));
}

/* Swing_DLL.xex 0x882A0360: call_seq ts4_tailcall_fn_88564B00_88564770 */
ts4_word ts4_call_seq_fn_88564770_882A0360(void)
{
    ts4_word t1;

    t1 = ts4_tailcall_fn_88564B00_88564770();
    return ((((65536) | 1) - t1) == 0);
}

/* Swing_DLL.xex 0x882A3088: if_call_seq memset, memset, u32@0x5588, memset, u32@0x5c08, fn_8829C5C8 */
ts4_word ts4_if_call_seq_fn_8856ABA0_882A3088(ts4_word a0)
{
    int t3;

    memset((ts4_word)(a0 + 21968), (ts4_word)0, (ts4_word)56);
    memset((ts4_word)(a0 + 22024), (ts4_word)0, (ts4_word)1536);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 21896);
    if ((int)t3 != (int)((673710080) | 262)) {
        memset((ts4_word)(a0 + 22024), (ts4_word)0, (ts4_word)1536);
        *(ts4_word *)((char *)(ts4_word)(a0) + 23560) = (ts4_word)1;
        fn_8829C5C8((ts4_word)a0, (ts4_word)(a0 + 22024));
        fn_88295990((ts4_word)a0, (ts4_word)((673710080) | 262));
        fn_88292598((ts4_word)a0);
    }
    return 0;
}

/* Swing_DLL.xex 0x882A4F40: get u8@0x2abf, u8@0x2abf */
void ts4_get_u8_off2abf_882A4F40(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 10943) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 10943)) | 4);
    return;
}

/* Swing_DLL.xex 0x882A6780: get u32@0x0 */
ts4_word ts4_get_u32_off0_882A6780(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(((a0 + 535953408) << 2)) + 0));
}

/* Swing_DLL.xex 0x882A9868: if_call_seq u32@0x20, u32@0x20, ts4_get_u32_off2c_8828AB18, u32@0x30, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off20_882A9868(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((t1 & 0xfff) | (((t1 & 0xfffff000) + a1) & 0xfffff000));
    t2 = ts4_get_u32_off2c_8828AB18((ts4_word)a0);
    if ((ts4_word)t2 > 1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)((t3 & 0xfff) | (((t3 & 0xfffff000) + a2) & 0xfffff000));
    }
    return t2;
}

/* Swing_DLL.xex 0x882B0ED8: if_get u32@0x4, u32@0x0, u32@0x0, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off4_882B0ED8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p10 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 0))))((ts4_word)t6, (ts4_word)1);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x882B4520: call_seq u32@0x38, lbl_88002378, u32@0x0, ts4_tsu_cleanup_end, u32@0x58, ts4_tsu_cleanup_end */
ts4_word ts4_call_seq_u32_off38_882B4520(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88002378;
    ts4_tsu_cleanup_end((ts4_word)t1);
    ts4_tsu_cleanup_end((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)));
    t6 = ts4_tsu_cleanup_end((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)));
    return t6;
}

/* Swing_DLL.xex 0x882BF448: if_call_seq u32@0x60, u32@0x64, u32@0x68, u32@0x20, memcpy, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off60_882BF448(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    int t6;
    ts4_word t7;
    int t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t5 = memcpy((ts4_word)a3, (ts4_word)((((int)t1 * (int)a1) + ((int)t2 * (int)a2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32))), (ts4_word)(t3 << 4));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p8 = (ts4_word)t5;
    if ((int)t6 != 0) {
        t7 = fn_882D2220((ts4_word)a0, (ts4_word)a3);
        p8 = (ts4_word)t7;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p11 = (ts4_word)p8;
    if ((int)t9 != 0) {
        t10 = fn_882B7420((ts4_word)a0, (ts4_word)a3);
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x882C3680: if_call_seq fn_882C28B0, fn_882C2B78, fn_882C1728 */
ts4_word ts4_if_call_seq_fn_882C28B0_882C3680(ts4_word a0)
{
    ts4_word p3;
    ts4_word p5;
    int t1;
    ts4_word t2;
    ts4_word t4;

    t1 = fn_882C28B0();
    p3 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t2 = fn_882C2B78((ts4_word)a0);
        p3 = (ts4_word)(((int)t2 >> 31) & t2);
    }
    p5 = (ts4_word)p3;
    if ((int)p3 >= 0) {
        t4 = fn_882C1728((ts4_word)a0);
        p5 = (ts4_word)(((int)t4 >> 31) & t4);
    }
    return p5;
}

/* Swing_DLL.xex 0x882C3818: if_call_seq u32@lbl_88C6E210, ts4_two_step_report_failure_882C35D0, ts4_two_step_report_failure_882C35D0, fn_882C1728 */
ts4_word ts4_if_call_seq_u32_lbl_88C6E210_882C3818(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word p6;
    int t1;
    int t3;
    ts4_word t4;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88C6E210;
    if ((int)t1 != 0) {
        t3 = ts4_two_step_report_failure_882C35D0((ts4_word)a0, (ts4_word)a1);
        p5 = (ts4_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_882C1728((ts4_word)a0);
            p5 = (ts4_word)(((int)t4 >> 31) & t4);
        }
        p6 = (ts4_word)p5;
    } else {
        t2 = ts4_two_step_report_failure_882C35D0((ts4_word)a0, (ts4_word)a1);
        p6 = (ts4_word)t2;
    }
    return p6;
}

/* Swing_DLL.xex 0x882C7C30: get u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off0_882C7C30(ts4_word a0)
{
    ts4_word loc50[50];
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x882C7C80: get u32@0x18, u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
void ts4_get_u32_off18_882C7C80(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(t2 + a1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(t3 - a1);
    return;
}

/* Swing_DLL.xex 0x882C7CA0: call_seq u32@0x18, u32@0x18, u32@0x14, fn_882C7918, u32@0x4, u32@0x18 */
ts4_word ts4_call_seq_u32_off18_882C7CA0(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    fn_882C7918((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 20)), (ts4_word)t2, (ts4_word)4096, (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)4096;
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24));
    return 1;
}

/* Swing_DLL.xex 0x882C7D30: if_call_seq u32@0x554, u32@0x4, lbl_8800394C, png2_png_error_882E26E8, u32@0x0, memcpy */
ts4_word ts4_if_call_seq_u32_off554_882C7D30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1364);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)a2 > (ts4_word)t2) {
        png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_8800394C);
    }
    t6 = memcpy((ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)a2);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0)) + a2);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 4)) - a2);
    return t6;
}

/* Swing_DLL.xex 0x882C85B0: if_call_seq ts4_if_call_seq_u32_off4_882C8520, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_fn_882C8520_882C85B0(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_u32_off4_882C8520((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return a0;
}

/* Swing_DLL.xex 0x882D1E30: call_seq u32@0x38, lbl_88004210, u32@0x0, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x58, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_call_seq_u32_off38_882D1E30(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88004210;
    ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t1, (ts4_word)(612433920));
    ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)(612433920));
    t6 = ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)), (ts4_word)(612433920));
    return t6;
}

/* Swing_DLL.xex 0x882D1E88: if_call_seq u32@0x8, u32@0x8, u32@0x54, u32@0x54, u32@0x10, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off8_882D1E88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    int t7;
    int t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((ts4_word)t1 != (ts4_word)t2 && (ts4_word)t1 != 4) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)t2;
    }
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t3 != 0 || (int)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)) != 0) {
        t6 = fn_88888668((ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 104)) << 4), (ts4_word)(612433920));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)t6;
        if ((ts4_word)t6 == 0) {
            p9 = (ts4_word)((2147942400) | 14);
        } else {
            t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t7 != 0 && (int)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 16)) != 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)1;
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
            }
            p9 = (ts4_word)0;
        }
        p12 = (ts4_word)p9;
    } else {
        t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((int)t10 != 0 && (int)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 16)) != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)1;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
        }
        p12 = (ts4_word)0;
    }
    return p12;
}

/* Swing_DLL.xex 0x882DAD88: if_call_seq u32@0x60, u32@0x64, u32@0x68, u32@0x20, memcpy, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off60_882DAD88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    int t6;
    ts4_word t7;
    int t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t5 = memcpy((ts4_word)a3, (ts4_word)((((int)t1 * (int)a1) + ((int)t2 * (int)a2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32))), (ts4_word)(t3 << 4));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p8 = (ts4_word)t5;
    if ((int)t6 != 0) {
        t7 = fn_882D2220((ts4_word)a0, (ts4_word)a3);
        p8 = (ts4_word)t7;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p11 = (ts4_word)p8;
    if ((int)t9 != 0) {
        t10 = fn_882D25F0((ts4_word)a0, (ts4_word)a3);
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x882DC640: if_call_seq fn_882DBBA0, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_fn_882DBBA0_882DC640(ts4_word a0, ts4_word a1)
{

    fn_882DBBA0();
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return a0;
}

/* Swing_DLL.xex 0x882DD168: if_call_seq ts4_if_call_seq_lbl_88004430_882DC5E8, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_fn_882DC5E8_882DD168(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_lbl_88004430_882DC5E8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return a0;
}

/* Swing_DLL.xex 0x882DD3B0: if_get u32@0x4, u32@0x4, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_u32_off4_882DD3B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)1);
    }
    return (t1 + -1);
}

/* Swing_DLL.xex 0x882DD400: if_call_seq fn_88888668, u32@0xc, u32@0x8 */
ts4_word ts4_if_call_seq_fn_88888668_882DD400(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_88888668((ts4_word)a1, (ts4_word)(612433920));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)((2147942400) | 14);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
        p2 = (ts4_word)0;
    }
    return p2;
}

/* Swing_DLL.xex 0x882DD588: if_call_seq u32@0xc, lbl_88004DBC, u32@0x0, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_u32_offc_882DD588(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88004DBC;
    ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t1, (ts4_word)(612433920));
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return a0;
}

/* Swing_DLL.xex 0x882DD920: if_set u32@0x0, u32@0x4, u32@0x8, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_set_u32_off0_882DD920(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p28;
    ts4_word t1;
    ts4_word t21;
    ts4_word t22;
    ts4_word t24;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8)) + t1);
    } else {
        p5 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p5;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 10));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0));
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 2));
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 4));
    *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 6));
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 10));
    t21 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    t22 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(((int)((int)t21 * (int)t22) * (int)(*(ts4_word *)((char *)(ts4_word)(a1) + 28))) << 2);
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t24 != 0) {
        p28 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8)) + t24);
    } else {
        p28 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)p28;
    return 0;
}

/* Swing_DLL.xex 0x882E0E28: if_call_seq fn_882DDC70, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
ts4_word ts4_if_call_seq_fn_882DDC70_882E0E28(ts4_word a0, ts4_word a1)
{

    fn_882DDC70();
    if ((int)(a1 & 0x1) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)(612433920));
    }
    return a0;
}

/* Swing_DLL.xex 0x882E1C98: addr lbl_88007D18, u32@0x8, u32@0x4, u32@0x0, u32@0xc, u32@0x14 */
void ts4_addr_lbl_88007D18_882E1C98(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88007D18;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x882E1F50: if_call_seq fn_882E1A68 */
ts4_word ts4_if_call_seq_fn_882E1A68_882E1F50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    ts4_word t1;

    (void)a0;
    t1 = fn_882E1A68((ts4_word)(~(a1 | a1)), (ts4_word)a2);
    p2 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        p2 = (ts4_word)(~(t1 | t1));
    }
    return p2;
}

/* Swing_DLL.xex 0x882E2978: if_call_seq png2_png_create_struct_882EC0E0, memset */
ts4_word ts4_if_call_seq_fn_882EC0E0_882E2978(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t1 = png2_png_create_struct_882EC0E0((ts4_word)2);
        if ((int)t1 != 0) {
            memset((ts4_word)t1, (ts4_word)0, (ts4_word)64);
        }
        p4 = (ts4_word)t1;
    }
    return p4;
}

/* Swing_DLL.xex 0x882E68C0: if_call_seq u32@0x558, lbl_8800967C, png2_png_error_882E26E8, u32@0x558, u32@0x558, ts4_call_seq_lbl_880260D8_882F0808 */
ts4_word ts4_if_call_seq_u32_off558_882E68C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1368);
    if ((int)(t1 & 0x4) == 0) {
        png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_8800967C);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1368)) | 8);
    t5 = ts4_call_seq_lbl_880260D8_882F0808((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x882E71D8: if_call_seq u32@0x550, u32@0x554, u32@0x54c, u32@0x620, u32@0x550, lbl_8800983C */
ts4_word ts4_if_call_seq_u32_off550_882E71D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1360);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1364) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1356) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1568) = (ts4_word)a3;
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1360) = (ts4_word)0;
        ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_8800983C);
        t3 = ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_88009804);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x882E7388: if_get u32@0x8, u32@0x10, u16@0x14, u32@0x8 */
void ts4_if_get_u32_off8_882E7388(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    if ((ts4_word)a0 == 0) {
        return;
    }
    if ((ts4_word)a1 == 0) {
        return;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)a2;
    *(unsigned short *)((char *)(ts4_word)(a1) + 20) = (unsigned short)a3;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t1 | 8);
    return;
}

/* Swing_DLL.xex 0x882E73B0: if_get u32@0x8, u8@0x2c, u32@0x8 */
void ts4_if_get_u32_off8_882E73B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a0 == 0) {
        return;
    }
    if ((ts4_word)a1 == 0) {
        return;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(unsigned char *)((char *)(ts4_word)(a1) + 44) = (unsigned char)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t1 | 2048);
    return;
}

/* Swing_DLL.xex 0x882E78F0: if_call_seq u32@0x55c, ex8_png_read_start_row_882F4028, ex6_png_read_transform_info_882E84A8 */
ts4_word ts4_if_call_seq_u32_off55c_882E78F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1372);
    if ((int)(t1 & 0x40) == 0) {
        ex8_png_read_start_row_882F4028((ts4_word)a0);
    }
    t4 = ex6_png_read_transform_info_882E84A8((ts4_word)a0, (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x882E8090: if_get u32@0x8 */
ts4_word ts4_if_get_u32_off8_882E8090(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((int)(t1 & 0x1) != 0 && (ts4_word)a2 != 0) {
            *(double *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a1) + 40));
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x882E80D0: if_get u32@0x8, u8@0x2c, u32@0x0 */
ts4_word ts4_if_get_u32_off8_882E80D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((int)(t1 & 0x800) != 0 && (ts4_word)a2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 44));
            return 2048;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x882E8220: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_882E8220(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 1);
    return;
}

/* Swing_DLL.xex 0x882E8230: if_get u8@0x617, u32@0x560, u32@0x560 */
void ts4_if_get_u8_off617_882E8230(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1559);
    if ((ts4_word)t1 != 16) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 16);
    return;
}

/* Swing_DLL.xex 0x882E8250: if_get u8@0x617, u32@0x560, u8@0x618, u32@0x560 */
void ts4_if_get_u8_off617_882E8250(ts4_word a0)
{
    unsigned char t1;
    ts4_word t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1559);
    if ((ts4_word)t1 >= 8) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 1376);
    *(unsigned char *)((char *)(ts4_word)(a0) + 1560) = (unsigned char)8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)(t2 | 4);
    return;
}

/* Swing_DLL.xex 0x882E8278: if_get u8@0x613, u32@0x560, u32@0x560 */
ts4_word ts4_if_get_u8_off613_882E8278(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1555);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 2);
        return 7;
    }
    return 1;
}

/* Swing_DLL.xex 0x882E82A8: if_get u32@0x560, u16@0x61e, u32@0x560, u32@0x55c, u32@0x55c, u8@0x616 */
void ts4_if_get_u32_off560_882E82A8(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    unsigned char t4;
    unsigned char t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1376);
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 1566) = (unsigned short)(a1 & 0xff);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)(t1 | 32768);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1372);
    if ((int)a2 == 1) {
        p3 = (ts4_word)(t2 | 128);
    } else {
        p3 = (ts4_word)(t2 & 0xffffff7f);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1372) = (ts4_word)p3;
    t4 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1558);
    if ((ts4_word)t4 == 2) {
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1563) = (unsigned char)4;
    }
    if ((ts4_word)t4 != 0) {
        return;
    }
    t7 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1559);
    if ((ts4_word)t7 < 8) {
        return;
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1563) = (unsigned char)2;
    return;
}

/* Swing_DLL.xex 0x882E8498: get u32@0x560, u32@0x560 */
void ts4_get_u32_off560_882E8498(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1376) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1376)) | 4096);
    return;
}

/* Swing_DLL.xex 0x882EA0C0: if_call_seq u32@0x54c, u32@0x554, u32@0x550, u32@0x54c, lbl_88009B60, ts4_if_get_u32_off544_882E2720 */
ts4_word ts4_if_call_seq_u32_off54c_882EA0C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1356);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1364) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1360) = (ts4_word)a2;
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1356) = (ts4_word)0;
        ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_88009B60);
        t3 = ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_88009B28);
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 1568) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x882EBFF0: if_call_seq u32@lbl_88B310D0, fn_882EB390, fn_882EB390, fn_882C1728 */
ts4_word ts4_if_call_seq_u32_lbl_88B310D0_882EBFF0(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word p6;
    int t1;
    int t3;
    ts4_word t4;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B310D0;
    if ((int)t1 != 0) {
        t3 = fn_882EB390((ts4_word)a0, (ts4_word)a1);
        p5 = (ts4_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_882C1728((ts4_word)a0);
            p5 = (ts4_word)(((int)t4 >> 31) & t4);
        }
        p6 = (ts4_word)p5;
    } else {
        t2 = fn_882EB390((ts4_word)a0, (ts4_word)a1);
        p6 = (ts4_word)t2;
    }
    return p6;
}

/* Swing_DLL.xex 0x882EC050: if_call_seq u32@lbl_88B310D0, fn_882EB450, fn_882EB450, fn_882C1728 */
ts4_word ts4_if_call_seq_u32_lbl_88B310D0_882EC050(ts4_word a0)
{
    ts4_word p5;
    ts4_word p6;
    int t1;
    int t3;
    ts4_word t4;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B310D0;
    if ((int)t1 != 0) {
        t3 = fn_882EB450();
        p5 = (ts4_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_882C1728((ts4_word)a0);
            p5 = (ts4_word)(((int)t4 >> 31) & t4);
        }
        p6 = (ts4_word)p5;
    } else {
        t2 = fn_882EB450();
        p6 = (ts4_word)t2;
    }
    return p6;
}

/* Swing_DLL.xex 0x882EC170: if_call_seq fn_88888668, lbl_88025AF0, png2_png_error_882E26E8 */
ts4_word ts4_if_call_seq_fn_88888668_882EC170(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        t1 = fn_88888668((ts4_word)a1, (ts4_word)(612433920));
        if ((int)t1 == 0) {
            png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_88025AF0);
        }
        p4 = (ts4_word)t1;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x882F4820: if_call_seq u32@0x558, lbl_8802658C, png2_png_error_882E26E8, u32@0x558, u32@0x558, lbl_88026570 */
ts4_word ts4_if_call_seq_u32_off558_882F4820(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word p17;
    ts4_word p18;
    ts4_word p19;
    ts4_word t1;
    ts4_word t12;
    ts4_word t16;
    ts4_word t11;
    ts4_word t2;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368);
    if ((int)(t1 & 0x1) != 0) {
        if ((int)(t1 & 0x4) == 0) {
            t12 = png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_8802658C);
            p17 = (ts4_word)t12;
            if ((ts4_word)a1 != 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368)) | 24);
                if ((ts4_word)a2 != 0) {
                    ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_88026570);
                }
                t16 = ex7_png_crc_finish_882F42A8((ts4_word)a0, (ts4_word)a2);
                p17 = (ts4_word)t16;
            }
            p18 = (ts4_word)p17;
        } else {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368)) | 24);
            if ((ts4_word)a2 != 0) {
                ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_88026570);
            }
            t11 = ex7_png_crc_finish_882F42A8((ts4_word)a0, (ts4_word)a2);
            p18 = (ts4_word)t11;
        }
        p19 = (ts4_word)p18;
    } else {
        t2 = png2_png_error_882E26E8((ts4_word)a0, (ts4_word)(ts4_word)lbl_8802658C);
        p7 = (ts4_word)t2;
        if ((ts4_word)a1 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1368)) | 24);
            if ((ts4_word)a2 != 0) {
                ts4_if_get_u32_off544_882E2720((ts4_word)a0, (ts4_word)(ts4_word)lbl_88026570);
            }
            t6 = ex7_png_crc_finish_882F42A8((ts4_word)a0, (ts4_word)a2);
            p7 = (ts4_word)t6;
        }
        p19 = (ts4_word)p7;
    }
    return p19;
}

/* Swing_DLL.xex 0x882F4DE8: if_call_seq ex8_png_check_chunk_name_882F37C8, u8@0x60c, u32@0x558, u32@0x558, ex7_png_crc_finish_882F42A8, lbl_880267C8 */
ts4_word ts4_if_call_seq_fn_882F37C8_882F4DE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p10;
    ts4_word p11;
    unsigned char t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t3;
    ts4_word t5;

    ex8_png_check_chunk_name_882F37C8((ts4_word)a0, (ts4_word)(a0 + 1548));
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 1548);
    if ((int)(t2 & 0x20) == 0) {
        t6 = png2_png_chunk_error_882E2738((ts4_word)a0, (ts4_word)(ts4_word)lbl_880267C8);
        p10 = (ts4_word)t6;
        if ((ts4_word)a1 != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 1368);
            if ((int)(t7 & 0x4) != 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)(t7 | 8);
            }
            t9 = ex7_png_crc_finish_882F42A8((ts4_word)a0, (ts4_word)a2);
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 1368);
        if ((int)(t3 & 0x4) != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 1368) = (ts4_word)(t3 | 8);
        }
        t5 = ex7_png_crc_finish_882F42A8((ts4_word)a0, (ts4_word)a2);
        p11 = (ts4_word)t5;
    }
    return p11;
}

/* Swing_DLL.xex 0x88304AC8: get png2_zlib_inflate_blocks_reset_883040C8, u32@0x24, u32@0x28, u32@0x28, vcall, u32@0x24 */
ts4_word ts4_get_fn_883040C8_88304AC8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;

    png2_zlib_inflate_blocks_reset_883040C8((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    ((ts4_word (*)(ts4_word, ts4_word))(t2))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    ((ts4_word (*)(ts4_word, ts4_word))(t6))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)t7);
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    ((ts4_word (*)(ts4_word, ts4_word))(t10))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)a0);
    return 0;
}

/* Swing_DLL.xex 0x88307630: if_get u32@0x20, u32@0x28, vcall, u32@0x14, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off20_88307630(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a4) + 32);
    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 40)), (ts4_word)1, (ts4_word)28);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)a2;
        *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)a3;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t3) + 16) = (unsigned char)a0;
        *(unsigned char *)((char *)(ts4_word)(t3) + 17) = (unsigned char)a1;
    }
    return t3;
}

/* Swing_DLL.xex 0x88308418: addr lbl_88028900, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_addr_lbl_88028900_88308418(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)9;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)5;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((ts4_word)lbl_88028900 + -4096);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(ts4_word)lbl_88028900;
    return 0;
}

/* Swing_DLL.xex 0x8830FBF8: if_call_seq u32@0x4, u32@0x0, u32@0x0, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, fn_883228E0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off4_8830FBF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t3 != 0) {
            ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)t3);
        }
        fn_883228E0((ts4_word)t1);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        p9 = (ts4_word)t7;
        if ((ts4_word)t7 != 0) {
            t8 = ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t7);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x8831D428: if_get u32@0xb4, u32@0x1c */
ts4_word ts4_if_get_u32_offb4_8831D428(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
    if ((ts4_word)t1 == 0) {
        return 82;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a0;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(a0 + 28), (ts4_word)a1, (ts4_word)(a2 & 0xff));
}

/* Swing_DLL.xex 0x8832C248: if_get u32@0x18, u32@0x4c */
ts4_word ts4_if_get_u32_off18_8832C248(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24);
    if ((ts4_word)t1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + t1)) + 76) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x8832E810: loop_call_seq u32@0x160, u32@0x160, u32@0x104, u32@0x104, u8@0x108, fn_8832E208 */
ts4_word ts4_loop_call_seq_u32_off160_8832E810(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 352);
    *(ts4_word *)((char *)(ts4_word)(a0) + 352) = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 260);
            *(ts4_word *)((char *)(ts4_word)(lv2) + 260) = (ts4_word)0;
            *(unsigned char *)((char *)(ts4_word)(lv2) + 264) = (unsigned char)0;
            fn_8832E208((ts4_word)lv2);
            p5 = (ts4_word)t3;
            lv2 = p5;
        } while ((ts4_word)p5 != 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x883BD9D8: if_call_seq u32@0x24, u32@0x20, u32@0x20, fn_8836CD70, u32@0x8, fn_8836CD70 */
ts4_word ts4_if_call_seq_u32_off24_883BD9D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    int t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    p10 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
        if ((ts4_word)t3 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t3);
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((ts4_word)t6 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t6);
        }
        t9 = ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)40);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x883C3E70: if_call_seq u32@0x8, u32@0x8, fn_8836CD70, u32@0xc, fn_8836CD70, ts4_memset */
ts4_word ts4_if_call_seq_u32_off8_883C3E70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((ts4_word)t2 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t2);
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        if ((ts4_word)t5 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t5);
        }
        t8 = ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)20);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x883C4360: if_call_seq ts4_memset, fn_8836CD70 */
ts4_word ts4_if_call_seq_ts4_memset_883C4360(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)3208);
        t2 = fn_8836CD70((ts4_word)a0, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x883C4BB8: if_call_seq ts4_memset, fn_8836CD70 */
ts4_word ts4_if_call_seq_ts4_memset_883C4BB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)1812);
        t2 = fn_8836CD70((ts4_word)a0, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x883C56F8: if_call_seq ts4_memset, fn_8836CD70 */
ts4_word ts4_if_call_seq_ts4_memset_883C56F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)1120);
        t2 = fn_8836CD70((ts4_word)a0, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x883C5750: if_call_seq ts4_memset, fn_8836CD70 */
ts4_word ts4_if_call_seq_ts4_memset_883C5750(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)1052);
        t2 = fn_8836CD70((ts4_word)a0, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x883C63C8: if_get fn_883D0668, u32@0x0, u32@0x50, vcall */
ts4_word ts4_if_get_fn_883D0668_883C63C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6420: if_get fn_883D0668, u32@0x0, u32@0x58, vcall */
ts4_word ts4_if_get_fn_883D0668_883C6420(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 88))))((ts4_word)t2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6460: if_get fn_883D0668, u32@0x0, u32@0x5c, vcall */
ts4_word ts4_if_get_fn_883D0668_883C6460(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 92))))((ts4_word)t2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C64A0: if_get fn_883D0668, u32@0x0, u32@0x60, vcall */
ts4_word ts4_if_get_fn_883D0668_883C64A0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 96))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C64F0: if_get fn_883D0668, u32@0x0, u32@0x70, vcall */
ts4_word ts4_if_get_fn_883D0668_883C64F0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 112))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6540: if_get fn_883D0668, u32@0x0, u32@0x78, vcall */
ts4_word ts4_if_get_fn_883D0668_883C6540(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 120))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6590: if_get fn_883D0668, u32@0x0, u32@0x8c, vcall */
ts4_word ts4_if_get_fn_883D0668_883C6590(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 140))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C65F0: if_get fn_883D0668, u32@0x0, u32@0xb4, vcall */
ts4_word ts4_if_get_fn_883D0668_883C65F0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 180))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6640: if_get fn_883D0668, u32@0x0, u32@0xbc, vcall */
ts4_word ts4_if_get_fn_883D0668_883C6640(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 188))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6690: if_get fn_883D0668, u32@0x0, u32@0xc4, vcall */
ts4_word ts4_if_get_fn_883D0668_883C6690(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883D0668((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 196))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883C6DE8: if_get u32@0xa8, u32@0xac, u32@0xac, u32@0x18, u32@0x138, u32@0x0 */
ts4_word ts4_if_get_u32_offa8_883C6DE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p13;
    ts4_word p16;
    ts4_word p17;
    ts4_word p18;
    ts4_word p19;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    int t9;
    ts4_word t11;
    int t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    if ((ts4_word)t1 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
        if ((ts4_word)t3 != 0) {
            p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 24));
        } else {
            p5 = (ts4_word)0;
        }
        if ((ts4_word)p5 != 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 312);
            t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 32))))((ts4_word)t6);
            p17 = (ts4_word)t9;
            if ((int)t9 == 0) {
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
                if ((ts4_word)t11 != 0) {
                    p13 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 24));
                } else {
                    p13 = (ts4_word)0;
                }
                t14 = ts4_if_call_seq_fn_8832F930_88317A28((ts4_word)p13);
                p16 = (ts4_word)t14;
                if ((int)t14 == 0) {
                    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 172))) + 24) = (ts4_word)0;
                    p16 = (ts4_word)0;
                }
                p17 = (ts4_word)p16;
            }
            p18 = (ts4_word)p17;
        } else {
            p18 = (ts4_word)0;
        }
        p19 = (ts4_word)p18;
    } else {
        p19 = (ts4_word)0;
    }
    return p19;
}

/* Swing_DLL.xex 0x883C6F08: if_get u32@0xa8, u32@0xac, u32@0xac, u32@0x0, u32@0xa8, u32@0x1c */
ts4_word ts4_if_get_u32_offa8_883C6F08(ts4_word a0, int a1)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    if ((ts4_word)t1 != 0) {
        p6 = (ts4_word)a0;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
        if ((ts4_word)t3 != 0) {
            p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
        } else {
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    }
    if ((int)a1 >= 0 && (int)a1 < (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 168))) + 28))) {
        return (((*(ts4_word *)((char *)(ts4_word)(a0) + 104)) & (1 << a1)) != 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x883C7660: if_set u32@0x0, u32@0x138, u32@0x0, u32@0x4c */
ts4_word ts4_if_set_u32_off0_883C7660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    if ((ts4_word)a2 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 312);
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    }
    return 37;
}

/* Swing_DLL.xex 0x883C7698: if_set u32@0x0, u32@0x138, u32@0x0, u32@0x50 */
ts4_word ts4_if_set_u32_off0_883C7698(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    if ((ts4_word)a2 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 312);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 80))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x883C76C8: if_get u32@0x138, u32@0x0, u32@0x58 */
ts4_word ts4_if_get_u32_off138_883C76C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 312);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 88))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x883CA000: if_get u32@0xac, u32@0x0, u32@0x0, u32@0x138, u32@0x0, u32@0x64 */
ts4_word ts4_if_get_u32_offac_883CA000(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word p6;
    ts4_word p12;
    ts4_word t1;
    ts4_word t7;
    int t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    } else {
        p3 = (ts4_word)0;
    }
    if ((ts4_word)p3 != 0) {
        if ((ts4_word)t1 != 0) {
            p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
        } else {
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    } else {
        p6 = (ts4_word)a0;
    }
    if ((ts4_word)a1 == 0) {
        p12 = (ts4_word)37;
    } else {
        t7 = *(ts4_word *)((char *)(ts4_word)(p6) + 312);
        t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 100))))((ts4_word)t7, (ts4_word)a1);
        if ((int)t10 == 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) + 48);
        }
        p12 = (ts4_word)t10;
    }
    return p12;
}

/* Swing_DLL.xex 0x883CA0A0: if_get u32@0xac, u32@0x0, u32@0x0, u32@0x138, u32@0x0, u32@0x68 */
ts4_word ts4_if_get_u32_offac_883CA0A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    } else {
        p3 = (ts4_word)0;
    }
    p6 = (ts4_word)a0;
    if ((ts4_word)p3 != 0) {
        if ((ts4_word)t1 != 0) {
            p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
        } else {
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    }
    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(p6) + 312);
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 104))))((ts4_word)t7, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    }
    return 37;
}

/* Swing_DLL.xex 0x883CA100: if_get u32@0xac, u32@0x0, u32@0x0, u32@0x70, u32@0x0 */
ts4_word ts4_if_get_u32_offac_883CA100(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    } else {
        p3 = (ts4_word)0;
    }
    if ((ts4_word)p3 != 0) {
        if ((ts4_word)t1 != 0) {
            p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
        } else {
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    } else {
        p6 = (ts4_word)a0;
    }
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p6) + 112));
    return 0;
}

/* Swing_DLL.xex 0x883CA8F0: if_get u32@0x60, u8@0x0 */
ts4_word ts4_if_get_u32_off60_883CA8F0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(((*(ts4_word *)((char *)(ts4_word)(a0) + 96)) >> 13) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883CA9B0: if_get u32@0x60, u8@0x0 */
ts4_word ts4_if_get_u32_off60_883CA9B0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(((*(ts4_word *)((char *)(ts4_word)(a0) + 96)) >> 14) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883CB0C8: if_get u32@0xac, u32@0xac, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_offac_883CB0C8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t2;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 24));
    } else {
        p4 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p4;
    return 0;
}

/* Swing_DLL.xex 0x883CB270: if_get fn_883CB130, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB270(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB2C0: if_get fn_883CB130, u32@0x0, u32@0xc, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB2C0(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 12))))((ts4_word)t2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB300: if_get fn_883CB130, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB300(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB350: if_get fn_883CB130, u32@0x0, u32@0x24, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB350(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 36))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB3A0: if_get fn_883CB130, u32@0x0, u32@0x28, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB3A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB3F0: if_get fn_883CB130, u32@0x0, u32@0x88, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB3F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 136))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB4A0: if_get fn_883CB130, u32@0x0, u32@0x5c, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB4A0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 92))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB4F0: if_get fn_883CB130, u32@0x0, u32@0x6c, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB4F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 108))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB540: if_get fn_883CB130, u32@0x0, u32@0x84, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB540(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 132))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CB590: if_get fn_883CB130, u32@0x0, u32@0x8c, vcall */
ts4_word ts4_if_get_fn_883CB130_883CB590(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_883CB130((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 140))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883CEFA8: if_get u32@0x38, u32@0xac, u32@0x0, u32@0x14 */
ts4_word ts4_if_get_u32_off38_883CEFA8(ts4_word a0, float f1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t5;
    float t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
    } else {
        p4 = (ts4_word)0;
    }
    if ((ts4_word)p4 == 0) {
        return 36;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t6 = *(float *)((char *)(ts4_word)(t5) + 16);
    if (!(t6 == f1)) {
        *(float *)((char *)(ts4_word)(t5) + 16) = f1;
    }
    return 0;
}

/* Swing_DLL.xex 0x883CF018: if_get u32@0x38, u32@0xac, u32@0x0, u32@0x14, u32@0x38, fn_883CC388 */
ts4_word ts4_if_get_u32_off38_883CF018(ts4_word a0, float f1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t5;
    float t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
    } else {
        p4 = (ts4_word)0;
    }
    if ((ts4_word)p4 == 0) {
        return 36;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t6 = *(float *)((char *)(ts4_word)(t5) + 28);
    if (!(t6 == f1)) {
        *(float *)((char *)(ts4_word)(t5) + 28) = f1;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
        if ((ts4_word)t7 != 0) {
            return fn_883CC388((ts4_word)t7);
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883CF0C8: if_get u32@0x38, u32@0xac, u32@0x0, u32@0x24, u32@0x24 */
ts4_word ts4_if_get_u32_off38_883CF0C8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 172);
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
    } else {
        p4 = (ts4_word)0;
    }
    if ((ts4_word)p4 == 0) {
        return 36;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    return 0;
}

/* Swing_DLL.xex 0x883CF298: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x4, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883CF298(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883CF548: if_get u32@0x20, lbl_880390E4, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0xc */
ts4_word ts4_if_get_u32_off20_883CF548(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_880390E4, (ts4_word)1471);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t6 != 0) {
        if ((ts4_word)a1 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1, (ts4_word)t6, (ts4_word)(ts4_word)lbl_880390E4, (ts4_word)1475);
        } else {
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_880390E4, (ts4_word)1475);
        }
    }
    if ((ts4_word)a1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1, (ts4_word)a0, (ts4_word)(ts4_word)lbl_880390E4, (ts4_word)1478);
    } else {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_880390E4, (ts4_word)1478);
    }
    return 0;
}

/* Swing_DLL.xex 0x883CF860: addr lbl_8803913C, u32@0x8, u32@0x0, u32@0xc, u32@0x28, u32@0x2c */
void ts4_addr_lbl_8803913C_883CF860(ts4_word a0)
{
    float t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t1 = *(float *)lbl_88001A20;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803913C;
    *(float *)((char *)(ts4_word)(a0) + 16) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 28) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 20) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 24) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883D05C8: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x4, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883D05C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)1, (ts4_word)a2, (ts4_word)1, (ts4_word)a3, (ts4_word)a4);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        ts4_memset((ts4_word)p7, (ts4_word)0, (ts4_word)a2);
    }
    return p7;
}

/* Swing_DLL.xex 0x883D0C88: loop_get u32@0x0, u32@-0x4, u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_883D0C88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32660)) + 0);
    if ((ts4_word)t1 != (ts4_word)((a0 + 65536) + -32660)) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + -4);
            t4 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 0))))((ts4_word)(lv2 + -4));
            p7 = (ts4_word)t4;
            lv2 = p7;
        } while ((ts4_word)p7 != (ts4_word)((a0 + 65536) + -32660));
    }
    return 0;
}

/* Swing_DLL.xex 0x883D0CF0: call_seq u32@0x0, ts4_if_call_seq_fn_88309DB8_88308D58, u32@0x0, u32@0x4a0, u32@0x8, u32@0x4a4 */
ts4_word ts4_call_seq_u32_off0_883D0CF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    t1 = ts4_if_call_seq_fn_88309DB8_88308D58((ts4_word)a1, (ts4_word)(a0 + 4));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 1184));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 1188));
    return t1;
}

/* Swing_DLL.xex 0x883D0D40: if_call_seq u32@0x0, u32@0x4, ts4_lookup_then_forward_88308D10, u32@0x8, u32@0x0, u32@0x4a0 */
ts4_word ts4_if_call_seq_u32_off0_883D0D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = ts4_lookup_then_forward_88308D10((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t5) + 1184) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t5) + 1188) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
        p8 = (ts4_word)t3;
    }
    return p8;
}

/* Swing_DLL.xex 0x883D15E0: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_883D15E0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)((262144) | 12802);
    return 0;
}

/* Swing_DLL.xex 0x883D2108: if_set  */
void ts4_if_set_883D2108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a2 >= (ts4_word)a1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((a2 + 17) << 2)) + a0) = (ts4_word)a3;
    return;
}

/* Swing_DLL.xex 0x883D2180: if_get  */
ts4_word ts4_if_get_883D2180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    if ((int)(a1 & 0x3) != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32936)) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32936))) & 0xfffffffc);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32936)) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32936))) | (a1 & 0x3));
    return 0;
}

/* Swing_DLL.xex 0x883D24F0: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off0_883D24F0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32612)) + 0);
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    if ((ts4_word)a2 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    if ((int)a1 == -1) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32612)) + 0));
        return 0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32612)) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 8))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x883D2550: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_883D2550(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32928));
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x883D25B8: if_call_seq fn_883D0B68, memcpy */
ts4_word ts4_if_call_seq_fn_883D0B68_883D25B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        t1 = fn_883D0B68((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
        p4 = (ts4_word)t1;
        if ((int)t1 == 0) {
            t2 = loc50[0];
            memcpy((ts4_word)a2, (ts4_word)(t2 + 24), (ts4_word)124);
            p4 = (ts4_word)0;
        }
        p5 = (ts4_word)p4;
    } else {
        p5 = (ts4_word)37;
    }
    return p5;
}

/* Swing_DLL.xex 0x883D2B88: if_get u32@0x40, u32@0x0 */
ts4_word ts4_if_get_u32_off40_883D2B88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32924));
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    return 0;
}

/* Swing_DLL.xex 0x883D2BC8: if_get u32@0x14, ts4_lookup_then_forward_88309078 */
ts4_word ts4_if_get_u32_off14_883D2BC8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32924));
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    return ts4_lookup_then_forward_88309078((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D2BF0: if_get u32@0x14, ts4_lookup_then_forward_883090C0 */
ts4_word ts4_if_get_u32_off14_883D2BF0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32924));
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    return ts4_lookup_then_forward_883090C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D2CE8: if_get u32@0x14, ts4_if_call_seq_fn_88309DB8_88309160 */
ts4_word ts4_if_get_u32_off14_883D2CE8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32924));
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    return ts4_if_call_seq_fn_88309DB8_88309160((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D2D10: set  */
ts4_word ts4_set_883D2D10(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32956)) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883D2D28: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_883D2D28(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32956)));
    return 0;
}

/* Swing_DLL.xex 0x883D3DD8: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883D3DD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883D4378: if_get u32@0x0, u32@0x8, vcall, u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off0_883D4378(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p8;
    int t3;
    ts4_word t6;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 == 0) {
        p8 = (ts4_word)37;
    } else {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)0);
        p7 = (ts4_word)t3;
        if ((int)t3 == 0) {
            t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)a2);
            p7 = (ts4_word)t6;
        }
        p8 = (ts4_word)p7;
    }
    return p8;
}

/* Swing_DLL.xex 0x883D43F8: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883D43F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)320, (ts4_word)3, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)320, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        fn_883CD3B0((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883D4478: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883D4478(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)48, (ts4_word)14, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)48, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        ts4_addr_lbl_88039DD8_883F3238((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883D44F8: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883D44F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)20, (ts4_word)15, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)20, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        ts4_addr_lbl_88039EC0_883F61E0((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883D4578: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883D4578(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)128, (ts4_word)2, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)128, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        fn_883F9F68((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883D4E30: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883D4E30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)36, (ts4_word)13, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)36, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        *(ts4_word *)((char *)(ts4_word)(p7) + 4) = (ts4_word)(p7 + 4);
        *(ts4_word *)((char *)(ts4_word)(p7) + 8) = (ts4_word)(p7 + 4);
        *(ts4_word *)((char *)(ts4_word)(p7) + 12) = (ts4_word)0;
    }
    return p7;
}

/* Swing_DLL.xex 0x883D88E8: loop_get u32@0x28, u32@0x28, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off28_883D88E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word p8;
    ts4_word p11;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p11 = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
        lv5 = (ts4_word)0;
        while ((ts4_word)lv4 != (ts4_word)(t2 + 4)) {
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 0));
            p8 = (ts4_word)(lv5 + 1);
            lv4 = p7;
            lv5 = p8;
        }
        p11 = (ts4_word)lv5;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p11;
    return 0;
}

/* Swing_DLL.xex 0x883D8FF0: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x50, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883D8FF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883DB628: if_call_seq u32@0x0, fn_883D7F20, fn_883DA438, u32@lbl_88CAC988, fn_883D38C8 */
ts4_word ts4_if_call_seq_u32_off0_883DB628(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word p9;
    ts4_word loc54[1];
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0 && (ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
        t1 = fn_883D7F20((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0]);
        p8 = (ts4_word)t1;
        if ((int)t1 == 0) {
            t2 = loc50[0];
            if ((int)(a2 & 0x4) != 0) {
                fn_883D38C8((ts4_word)(*(ts4_word *)lbl_88CAC988), (ts4_word)t2, (ts4_word)a3, (ts4_word)a2, (ts4_word)0);
                p7 = (ts4_word)0;
            } else {
                t3 = loc54[0];
                t4 = fn_883DA438((ts4_word)t3, (ts4_word)t2, (ts4_word)a3, (ts4_word)a2);
                p7 = (ts4_word)t4;
            }
            p8 = (ts4_word)p7;
        }
        p9 = (ts4_word)p8;
    } else {
        p9 = (ts4_word)37;
    }
    return p9;
}

/* Swing_DLL.xex 0x883DB758: addr lbl_8803943C, u32@0x8, u32@0x0, u32@0xc, u32@0x10, u32@0x14 */
void ts4_addr_lbl_8803943C_883DB758(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803943C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883DBAB0: if_call_seq fn_883CBF10, u16@0x64, u16@0x64 */
ts4_word ts4_if_call_seq_fn_883CBF10_883DBAB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;

    (void)a0;
    t1 = fn_883CBF10((ts4_word)a1, (ts4_word)a2);
    if ((int)t1 == 0) {
        *(unsigned short *)((char *)(ts4_word)(a2) + 100) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(a2) + 100)) | 192);
    }
    return t1;
}

/* Swing_DLL.xex 0x883DBB68: if_get u32@0x10, u32@0x10, u32@0x0 */
ts4_word ts4_if_get_u32_off10_883DBB68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    if ((ts4_word)a2 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t2 == 0) {
        return 81;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + t2));
    return 0;
}

/* Swing_DLL.xex 0x883DBC98: if_get u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_lbl_88B3302C_883DBC98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word t6;
    ts4_word t3;

    (void)a1;
    if ((ts4_word)a0 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)144, (ts4_word)5, (ts4_word)a2, (ts4_word)a3);
        p7 = (ts4_word)t6;
    } else {
        t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)144, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)t3;
    }
    if ((ts4_word)p7 != 0) {
        fn_883E2C28((ts4_word)p7);
    }
    return p7;
}

/* Swing_DLL.xex 0x883DC070: get fn_8832EDB0, u32@0x18, u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_fn_8832EDB0_883DC070(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t5;

    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)256, (ts4_word)28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2, (ts4_word)a1);
    return t5;
}

/* Swing_DLL.xex 0x883DC630: get u32@0x18 */
ts4_word ts4_get_u32_off18_883DC630(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) & 0x300) != 0);
}

/* Swing_DLL.xex 0x883DD230: loop_call_seq u32@lbl_88CAC994, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, lbl_88B3B4B8, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_lbl_88CAC994_883DD230(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        t1 = *(ts4_word *)lbl_88CAC994;
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)t1);
        lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3B4B8) + 0));
        lv5 = (ts4_word)0;
        while ((ts4_word)lv4 != (ts4_word)(ts4_word)lbl_88B3B4B8) {
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 0));
            p8 = (ts4_word)(lv5 + 1);
            lv4 = p7;
            lv5 = p8;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)lv5;
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883DD2B0: loop_call_seq u32@lbl_88CAC994, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, lbl_88B3B4B8, u32@lbl_88B3B4B8, u32@0xc, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_lbl_88CAC994_883DD2B0(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p11;
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)lbl_88CAC994;
    ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)t1);
    lv4 = (ts4_word)(*(ts4_word *)lbl_88B3B4B8);
    while ((ts4_word)lv4 != (ts4_word)(ts4_word)lbl_88B3B4B8) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 12);
        t6 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 88);
        if ((ts4_word)t7 == (ts4_word)a0) {
            fn_883DCA00((ts4_word)lv4, (ts4_word)21);
            fn_883DCC58((ts4_word)lv4, (ts4_word)21);
        }
        p11 = (ts4_word)t6;
        lv4 = p11;
    }
    ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x883DF540: loop_get u32@0x48, u32@0x48, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off48_883DF540(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word p8;
    ts4_word p11;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p11 = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
        lv5 = (ts4_word)0;
        while ((ts4_word)lv4 != (ts4_word)(t2 + 4)) {
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 0));
            p8 = (ts4_word)(lv5 + 1);
            lv4 = p7;
            lv5 = p8;
        }
        p11 = (ts4_word)lv5;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p11;
    return 0;
}

/* Swing_DLL.xex 0x883DFAA0: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x58, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883DFAA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883E0798: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_883E0798(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xffffff8f) | (a1 << 4));
    return;
}

/* Swing_DLL.xex 0x883E07B0: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_883E07B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xfffffff7) | (a1 << 3));
    return;
}

/* Swing_DLL.xex 0x883E07C8: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_883E07C8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xfffffffb) | (a1 << 2));
    return;
}

/* Swing_DLL.xex 0x883E07E0: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_883E07E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xfffffffc) | a1);
    return;
}

/* Swing_DLL.xex 0x883E2B30: if_get u32@0x10, lbl_880395AC, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@lbl_88B3302C */
ts4_word ts4_if_get_u32_off10_883E2B30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_880395AC, (ts4_word)1854);
    }
    if ((ts4_word)a1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1, (ts4_word)a0, (ts4_word)(ts4_word)lbl_880395AC, (ts4_word)1857);
    } else {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_880395AC, (ts4_word)1857);
    }
    return 0;
}

/* Swing_DLL.xex 0x883E3878: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x1c, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883E3878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883E4188: if_call_seq fn_883E40F8, lbl_8803964C, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_fn_883E40F8_883E4188(ts4_word a0)
{
    ts4_word p5;
    int t1;

    t1 = fn_883E40F8((ts4_word)a0);
    p5 = (ts4_word)t1;
    if ((int)t1 == 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803964C, (ts4_word)473);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x883E46A8: if_get u32@0x8, ts4_if_get_u32_lbl_88CAC9A8_883E63D8, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_u32_off8_883E46A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        p6 = (ts4_word)95;
    } else {
        t2 = ts4_if_get_u32_lbl_88CAC9A8_883E63D8();
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883E4710: if_get u32@0x8, ts4_if_get_u32_lbl_88CAC9A8_883E63D8, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_u32_off8_883E4710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        p6 = (ts4_word)95;
    } else {
        t2 = ts4_if_get_u32_lbl_88CAC9A8_883E63D8();
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x883E4780: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x60, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883E4780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883E4938: addr lbl_880396B0, u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880396B0_883E4938(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880396B0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883E4E70: if_call_seq u32@0x8, lbl_88039714, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_883E4E70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_88039714, (ts4_word)50);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x883E54C8: if_get u32@0x0, u32@0x8, u32@0x10, vcall, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_off0_883E54C8(ts4_word a0)
{
    ts4_word p9;
    ts4_word p19;
    ts4_word p20;
    ts4_word p24;
    ts4_word p34;
    ts4_word p35;
    ts4_word p36;
    ts4_word p37;
    ts4_word p38;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t6;
    int t21;
    ts4_word t22;
    ts4_word t23;
    int t30;
    ts4_word t7;
    ts4_word t8;
    int t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 16))))((ts4_word)a0, (ts4_word)t2);
    p38 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t6 != 0) {
            t21 = ts4_if_call_seq_u32_off8_883E5158((ts4_word)t6);
            p36 = (ts4_word)t21;
            if ((int)t21 == 0) {
                t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                if ((ts4_word)t22 == 0) {
                    p24 = (ts4_word)0;
                } else {
                    t23 = ts4_if_call_seq_fn_88322CA8_88317910((ts4_word)t22, (ts4_word)(ts4_word)&loc50[0]);
                    p24 = (ts4_word)(t23 == 0);
                }
                if ((int)(p24 & 0xff) != 0) {
                    t30 = ts4_if_call_seq_fn_88322CA8_88316F78((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
                    p34 = (ts4_word)t30;
                    if ((int)t30 == 0) {
                        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)302);
                        p34 = (ts4_word)0;
                    }
                    p35 = (ts4_word)p34;
                } else {
                    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)302);
                    p35 = (ts4_word)0;
                }
                p36 = (ts4_word)p35;
            }
            p37 = (ts4_word)p36;
        } else {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((ts4_word)t7 == 0) {
                p9 = (ts4_word)0;
            } else {
                t8 = ts4_if_call_seq_fn_88322CA8_88317910((ts4_word)t7, (ts4_word)(ts4_word)&loc50[0]);
                p9 = (ts4_word)(t8 == 0);
            }
            if ((int)(p9 & 0xff) != 0) {
                t15 = ts4_if_call_seq_fn_88322CA8_88316F78((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
                p19 = (ts4_word)t15;
                if ((int)t15 == 0) {
                    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)302);
                    p19 = (ts4_word)0;
                }
                p20 = (ts4_word)p19;
            } else {
                fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)302);
                p20 = (ts4_word)0;
            }
            p37 = (ts4_word)p20;
        }
        p38 = (ts4_word)p37;
    }
    return p38;
}

/* Swing_DLL.xex 0x883E5F10: if_get u32@0xc, u8@0x34, u8@0x0 */
ts4_word ts4_if_get_u32_offc_883E5F10(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 52));
    }
    return 0;
}

/* Swing_DLL.xex 0x883E6370: get u32@lbl_88CAC9A8, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_lbl_88CAC9A8_883E6370(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAC9A8;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E6388: get u32@lbl_88CAC9A8, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_lbl_88CAC9A8_883E6388(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAC9A8;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E63A0: get u32@lbl_88CAC9A8, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_lbl_88CAC9A8_883E63A0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAC9A8;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E63C0: get u32@lbl_88CAC9A8, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_lbl_88CAC9A8_883E63C0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAC9A8;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E6400: get u32@lbl_88CAC9A8, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_lbl_88CAC9A8_883E6400(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88CAC9A8;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E7440: if_set u32@0x8, lbl_880398A0, u32@0x0, u32@0x0, u32@0x18, vcall */
ts4_word ts4_if_set_u32_off8_883E7440(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880398A0;
    if ((ts4_word)a1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    }
    return a0;
}

/* Swing_DLL.xex 0x883E7498: if_addr lbl_880398A0, u32@0x0, u32@0x8, u32@0x8, u32@0x0, u32@0x18 */
ts4_word ts4_if_addr_lbl_880398A0_883E7498(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880398A0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1);
    }
    return a0;
}

/* Swing_DLL.xex 0x883E74F0: if_get u32@0x8, u32@0x0, u32@0x1c, vcall, u32@0x8, u32@0x8 */
ts4_word ts4_if_get_u32_off8_883E74F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 24))))((ts4_word)t6);
    }
    return a0;
}

/* Swing_DLL.xex 0x883E7580: if_get u32@0x14, lbl_880398A0, u32@0xc, u32@0x0, u32@0x1c, vcall */
ts4_word ts4_if_get_u32_off14_883E7580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)lbl_880398A0;
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
        p5 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803977C;
    return p5;
}

/* Swing_DLL.xex 0x883E8760: if_get u32@lbl_88CAC988, u32@0x0, u32@0x70, vcall, ts4_memset, u32@lbl_88039734 */
ts4_word ts4_if_get_u32_lbl_88CAC988_883E8760(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p12;
    ts4_word loc50[4];
    ts4_word loc60[34];
    ts4_word t1;
    int t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;

    t1 = *(ts4_word *)lbl_88CAC988;
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 112))))((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    p12 = (ts4_word)t4;
    if ((int)t4 == 0) {
        ts4_memset((ts4_word)(ts4_word)&loc60[0], (ts4_word)0, (ts4_word)124);
        loc60[27] = (ts4_word)a3;
        loc60[0] = (ts4_word)124;
        loc60[28] = (ts4_word)1;
        t6 = loc50[0];
        loc60[18] = (ts4_word)8;
        t7 = *(ts4_word *)lbl_88039734;
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        loc60[7] = (ts4_word)t8;
        loc60[15] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 84));
        t11 = ts4_if_call_seq_fn_88309DB8_883092F0((ts4_word)t6, (ts4_word)a1, (ts4_word)t7, (ts4_word)(ts4_word)&loc60[0], (ts4_word)a2);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x883E8B80: get u32@0x0 */
ts4_word ts4_get_u32_off0_883E8B80(ts4_word a0, ts4_word a1)
{
    return ((a1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) == 0);
}

/* Swing_DLL.xex 0x883E8DF0: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_883E8DF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((t1 - (*(ts4_word *)((char *)(ts4_word)(a1) + 4))) == 0);
}

/* Swing_DLL.xex 0x883E9070: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_883E9070(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((t1 - (*(ts4_word *)((char *)(ts4_word)(a1) + 8))) == 0);
}

/* Swing_DLL.xex 0x883EA5B0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_883EA5B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((t1 - (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) == 0);
}

/* Swing_DLL.xex 0x883EA9F8: if_call_seq lbl_8803978C, lbl_88039850, u32@0x8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8803978C_883EA9F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803978C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039850;
    if ((int)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x883EAA48: if_call_seq lbl_8803978C, lbl_88039864, u32@0x8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8803978C_883EAA48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803978C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039864;
    if ((int)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x883EAA98: if_call_seq lbl_8803978C, lbl_88039874, u32@0x8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8803978C_883EAA98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803978C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039874;
    if ((int)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x883EAAE8: if_call_seq lbl_8803978C, lbl_8803988C, u32@0x8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8803978C_883EAAE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803978C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803988C;
    if ((int)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x883EBC28: if_call_seq fn_883E9A50, u32@0xc, u32@0xc, lbl_88039A20, u32@lbl_88B3302C, u32@0x4 */
ts4_word ts4_if_call_seq_fn_883E9A50_883EBC28(ts4_word a0)
{
    ts4_word p8;
    int t1;
    ts4_word t3;

    t1 = fn_883E9A50((ts4_word)a0, (ts4_word)1);
    p8 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t3 != 0) {
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t3, (ts4_word)(ts4_word)lbl_88039A20, (ts4_word)1760);
        }
        p8 = (ts4_word)0;
    }
    return p8;
}

/* Swing_DLL.xex 0x883ED578: if_get u8@0x20, u8@0x0 */
ts4_word ts4_if_get_u8_off20_883ED578(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(((*(unsigned char *)((char *)(ts4_word)(a0) + 32)) >> 1) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883ED5D0: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x48, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883ED5D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883EDA60: if_get u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_883EDA60(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1);
}

/* Swing_DLL.xex 0x883EDD18: if_get u32@0x2c, u8@0x0 */
ts4_word ts4_if_get_u32_off2c_883EDD18(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883EDDD0: addr lbl_88039B00, u32@0xc, u32@0x4, u32@0x8, u32@0x0, u32@0x14 */
void ts4_addr_lbl_88039B00_883EDDD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039B00;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)128;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883EE418: if_call_seq u32@0x14, lbl_88039BC8, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off14_883EE418(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_88039BC8, (ts4_word)59);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039BC8, (ts4_word)64);
    return 0;
}

/* Swing_DLL.xex 0x883EE670: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x30, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_883EE670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x883EE8E8: addr lbl_88039BEC, u32@0xc, u32@0x4, u32@0x8, u32@0x0, u32@0x9c */
void ts4_addr_lbl_88039BEC_883EE8E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039BEC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
    return;
}
