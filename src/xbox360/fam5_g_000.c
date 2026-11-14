/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, a named pointer
   for a repeated base+offset, ||/&& conditions kept in a bool temporary,
   ...).  In .cpp files a function whose first argument is `this` is a member
   of a one-function struct ts4_obj_<ADDR>: MSVC orders the operands of
   commutative instructions differently for `this` than for a plain argument.
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;

extern char g_ts4_session_context[];
extern char g_ts4_session_state[];
extern char lbl_8803A3B0[];
extern char lbl_8803C3F8[];
extern char lbl_8803C404[];
extern char lbl_8803CB5C[];
extern char lbl_8803D1C8[];
extern char lbl_8803F49C[];
extern char lbl_8803F4AC[];
extern char lbl_8803F948[];
extern char lbl_8814B440[];
extern char lbl_88CACF08[];
extern char lbl_88D459E8[];
extern char lbl_88D45A48[];
ts4_word KeTlsGetValue();
ts4_word fn_88151560();
ts4_word fn_88153120();
ts4_word fn_881542F8();
ts4_word fn_8815A998();
ts4_word fn_88165170();
ts4_word fn_8819B4C8();
ts4_word fn_881BD170();
ts4_word fn_8841A590();
ts4_word fn_884A0420();
ts4_word fn_884A04C8();
ts4_word fn_8860F910();
ts4_word fn_886F0B30(ts4_word, float, float, float, float, ts4_word, ts4_word);
ts4_word fn_886F2298(ts4_word, float, float, float, ts4_word, float);
ts4_word fn_886F34D0(ts4_word, ts4_word, float);
ts4_word fn_8870DAB0();
ts4_word fn_8870DD10();
ts4_word fn_8870DE10();
ts4_word fn_8870DF38();
ts4_word fn_88717218();
ts4_word ts4_loop_get_u32_off0_8883C2B0();
ts4_word fn_8884B120();
ts4_word fn_88921558();
ts4_word fn_8892EE88();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_record_by_key_881AC778();
ts4_word ts4_find_record_by_key_881ACD38();
ts4_word ts4_find_record_by_key_881ACD90();
ts4_word ts4_find_record_by_key_881AD100();
ts4_word ts4_get_u32_off0_88428960();
ts4_word ts4_get_u32_off0_88428988();
ts4_word ts4_get_u32_off0_884289B8();
ts4_word ts4_get_u32_off4_88426130();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_if_call_seq_u32_off0_884288F8();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_index_u16_array_at_field0_884289F8();
ts4_word ts4_index_u64_array_at_field0_88428A88();
ts4_word ts4_init_range_and_run_service_opt_88165D80();

/* Swing_DLL.xex 0x88165000: if_call_seq fn_8892EE88, u8@0x8, u8@0x9, u8@0x9, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_fn_8892EE88_88165000(ts4_word a0, ts4_args3 sp1, ts4_word a3)
{
    ts4_word t3;
    ts4_word t5;

    (void)sp1.w[2];
    fn_8892EE88((ts4_word)a0, sp1, (ts4_word)a3);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 != 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 9);
        if ((ts4_word)t5 != 0) {
            return (a0 - (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        }
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    }
    return 0;
}

/* Swing_DLL.xex 0x8817F5E0: if_call_seq fn_8892EE88, u8@0x8, u8@0x9, u8@0x9, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_fn_8892EE88_8817F5E0(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    ts4_word t5;

    (void)sp1.w[2];
    fn_8892EE88((ts4_word)a0, sp1, (ts4_word)0);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 != 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 9);
        if ((ts4_word)t5 != 0) {
            return (a0 - (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        }
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    }
    return 0;
}

/* Swing_DLL.xex 0x881977B0: loop_get u32@0x0, u32@-0x10, u32@0x0, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_881977B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv6;
    ts4_word p8;
    ts4_word p9;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + -16);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t5 + 16);
    if ((ts4_word)a2 != 0) {
        lv6 = (ts4_word)a2;
        do {
            t7 = *(unsigned char *)((char *)(ts4_word)(lv6) + 0);
            p8 = (ts4_word)(lv6 + 1);
            lv6 = p8;
        } while ((ts4_word)t7 != 0);
        p9 = (ts4_word)((lv6 - a2) + -1);
    } else {
        p9 = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    fn_8819B4C8((ts4_word)a0, (ts4_word)t10, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t10) + -12)), (ts4_word)a2, (ts4_word)p9, (ts4_word)(t5 + 16));
    return a0;
}

/* Swing_DLL.xex 0x881AB670: if_call_seq fn_8892EE88, u8@0x8, u8@0x9, u8@0x9, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_fn_8892EE88_881AB670(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    ts4_word t5;

    (void)sp1.w[2];
    fn_8892EE88((ts4_word)a0, sp1, (ts4_word)1);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 != 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 9);
        if ((ts4_word)t5 != 0) {
            return (a0 - (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        }
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    }
    return 0;
}

/* Swing_DLL.xex 0x881BD0F0: call_seq u8@0x0, u8@0x0, u8@0x1, u8@0x1, u8@0x2, u8@0x2 */
ts4_word ts4_call_seq_u8_off0_881BD0F0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 1));
    t3 = *(unsigned char *)((char *)(ts4_word)(a1) + 2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t4;
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t6;
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t7;
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t8;
    fn_881BD170((ts4_word)(a0 + 24), (ts4_word)(a1 + 24), (ts4_word)t6, (ts4_word)t5, (ts4_word)t4, (ts4_word)t3, (ts4_word)t8, (ts4_word)t7);
    return a0;
}

/* Swing_DLL.xex 0x881C2190: loop_get u32@0x0, u32@-0x10, u32@0x0, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_881C2190(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv8;
    ts4_word p10;
    ts4_word p11;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + -16);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t5 + 16);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + -12);
    if ((ts4_word)a1 != 0) {
        lv8 = (ts4_word)a1;
        do {
            t9 = *(unsigned char *)((char *)(ts4_word)(lv8) + 0);
            p10 = (ts4_word)(lv8 + 1);
            lv8 = p10;
        } while ((ts4_word)t9 != 0);
        p11 = (ts4_word)((lv8 - a1) + -1);
    } else {
        p11 = (ts4_word)0;
    }
    fn_8819B4C8((ts4_word)a0, (ts4_word)a1, (ts4_word)p11, (ts4_word)t6, (ts4_word)t7, (ts4_word)(t5 + 16));
    return a0;
}

/* Swing_DLL.xex 0x883652A8: if_get u8@0x279, u32@0x0, u32@0x1d4, u32@0x1d4, u8@0x279, u32@0x1d4 */
ts4_word ts4_if_get_u8_off279_883652A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    int t11;
    int t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 633);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)(t1 & 0xf) == 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 468) = (ts4_word)(((t1) >> 4) + (*(ts4_word *)((char *)(ts4_word)(t2) + 468)));
    }
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 633);
    if ((ts4_word)(t6 & 0xfffffff0) == 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 468) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 468)) - (t6 & 0xf));
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(t2) + 468);
    if ((int)t11 > 64) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 468) = (ts4_word)64;
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(t2) + 468);
    if ((int)t13 < 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 468) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(t2) + 460) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(t2) + 460)) | 2);
    return 0;
}

/* Swing_DLL.xex 0x88421AB8: loop_get u32@0x4, u8@0x0, u32@0x0, u8@0x0, u32@0x4 */
void ts4_loop_get_u32_off4_88421AB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, int a4)
{
    ts4_word lv2;
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    if ((int)(t1 + -1) <= 0) {
        return;
    }
    lv2 = (ts4_word)0;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t4 = *(unsigned char *)((char *)(ts4_word)(t3) + lv2);
        if ((int)((signed char)t4) == (int)((signed char)a2)) {
            *(unsigned char *)((char *)(ts4_word)(t3) + lv2) = (unsigned char)a3;
            *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
            if ((int)a4 == 0) {
                return;
            }
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        p6 = (ts4_word)(lv2 + 1);
        lv2 = p6;
    } while ((int)p6 < (int)(t5 + -1));
    return;
}

/* Swing_DLL.xex 0x88429820: if_call_seq lbl_8803F49C, ts4_if_call_seq_u32_off4_88428890, lbl_8803C404, ts4_if_call_seq_u32_off4_88428890, lbl_8803C3F8, ts4_if_call_seq_u32_off4_88428890 */
void ts4_if_call_seq_lbl_8803F49C_88429820(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word loc50[2];
    ts4_word loc70[2];
    ts4_word loc78[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t16;
    ts4_word t17;
    ts4_word t20;
    ts4_word t21;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F49C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803C404);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803C3F8);
    t4 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
    if ((ts4_word)t5 != 0) {
        t6 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        t7 = *(unsigned char *)((char *)(ts4_word)(t6) + 0);
        if ((ts4_word)t7 != 0) {
            t8 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc68[0]);
            t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
            if ((ts4_word)t9 != 0) {
                t10 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc58[0]);
                t11 = ts4_get_u32_off4_88426130((ts4_word)t10);
                ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&loc70[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8803C404);
                ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&loc78[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8803C3F8);
                t16 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
                t17 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc70[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t16) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t17) + 0));
                *(ts4_word *)((char *)(ts4_word)(t16) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t17) + 4));
                t20 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
                t21 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc78[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t20) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t21) + 0));
                *(ts4_word *)((char *)(ts4_word)(t20) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t21) + 4));
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x88429960: if_call_seq u32@0x4, u32@0x0, lbl_8803F4AC, ts4_if_call_seq_u32_off0_884288F8, ts4_get_u32_off0_88428960, u8@0x0 */
void ts4_if_call_seq_u32_off4_88429960(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8803F4AC);
    t4 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
    if ((ts4_word)t5 != 0) {
        t6 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        *(float *)((char *)(ts4_word)(t6) + 0) = (*(float *)lbl_8803A3B0);
    }
    return;
}

/* Swing_DLL.xex 0x8842A3F0: if_call_seq ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428988, u32@0x0 */
void ts4_if_call_seq_ts4_if_call_seq_u32_off4_88428890_8842A3F0(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)a1);
    t2 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        t4 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x8842A448: if_call_seq lbl_8803D1C8, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428988, u32@0x0 */
void ts4_if_call_seq_lbl_8803D1C8_8842A448(ts4_word a0)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803D1C8);
    t2 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        t4 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x8842A4A8: if_call_seq lbl_8803D1C8, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428988, u32@0x0 */
void ts4_if_call_seq_lbl_8803D1C8_8842A4A8(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803D1C8);
    t2 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        t4 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x8842A500: if_call_seq lbl_8803F948, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428988, u32@0x0 */
void ts4_if_call_seq_lbl_8803F948_8842A500(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803F948);
    t2 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    if ((ts4_word)t3 != 0) {
        t4 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x88431788: call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_index_u16_array_at_field0_884289F8, u16@0x0, ts4_index_u16_array_at_field0_884289F8 */
void ts4_call_seq_lbl_8803CB5C_88431788(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB5C);
    t3 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = *(unsigned short *)((char *)(ts4_word)(t3) + 0);
    t5 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t5) + 0) = (unsigned short)((t4 >> 4) & 0x1);
    return;
}

/* Swing_DLL.xex 0x8848B038: if_get u32@0x3c, u16@0x10, u16@0x4, u16@0xc, u16@0x10 */
ts4_word ts4_if_get_u32_off3c_8848B038(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(unsigned short *)((char *)(ts4_word)(a0) + 16);
    t3 = *(unsigned short *)((char *)(ts4_word)(t1) + 4);
    t4 = *(unsigned short *)((char *)(ts4_word)(t1) + 12);
    if ((int)((t3 + t2) + a1) > (int)(t4 + -2)) {
        return 1;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)((t2 + a1) & 0xff);
    return 0;
}

/* Swing_DLL.xex 0x884A0690: if_call_seq u16@0x4, u16@0x6, u16@0xc, u8@0x9, u8@0x8, fn_884A0420 */
ts4_word ts4_if_call_seq_u16_off4_884A0690(ts4_word a0, ts4_word a1)
{
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 4);
    t2 = *(unsigned short *)((char *)(ts4_word)(a0) + 6);
    if ((int)((t1 + a1) << 1) <= (int)t2) {
        t3 = *(unsigned short *)((char *)(ts4_word)(a0) + 12);
        t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 9);
        t6 = fn_884A0420((ts4_word)((t2) >> 1), (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t4, (ts4_word)t3);
        fn_884A04C8((ts4_word)t6, (ts4_word)a0);
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t9, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 2)), (ts4_word)4);
        p12 = (ts4_word)t6;
    } else {
        p12 = (ts4_word)a0;
    }
    return p12;
}

/* Swing_DLL.xex 0x886101C0: call_seq u32@0x4, u32@0x4, fn_8860F910 */
ts4_word ts4_call_seq_u32_off4_886101C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = fn_8860F910((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)&a2, (ts4_word)t1);
    return t3;
}

/* Swing_DLL.xex 0x88614E98: call_seq u32@0x2c4, u32@0x2c0, fn_88165170 */
ts4_word ts4_call_seq_u32_off2c4_88614E98(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 708);
    t3 = fn_88165170((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 704)), (ts4_word)t1, (ts4_word)(ts4_word)&a1);
    return ((t3 - t1) != 0);
}

/* Swing_DLL.xex 0x88615990: get ts4_init_range_and_run_service_opt_88165D80, u32@0x0, u32@0x4, u32@0x0, u32@0x2c, vcall */
ts4_word ts4_get_ts4_init_range_and_run_service_opt_88165D80_88615990(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t2;
    ts4_word t3;

    ts4_init_range_and_run_service_opt_88165D80((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&a2, (ts4_word)a4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 44))))((ts4_word)t2, (ts4_word)a0, (ts4_word)t3, (ts4_word)a3, (ts4_word)a4);
    return a0;
}

/* Swing_DLL.xex 0x8863A130: if_get u8@0x49d, u8@0x49d */
void ts4_if_get_u8_off49d_8863A130(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    float t2;
    float t3;
    float t4;
    float t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1181);
    if ((ts4_word)t1 == 0) {
        t2 = *(float *)((char *)(ts4_word)(a1) + 0);
        t3 = *(float *)((char *)(ts4_word)(a0) + 1116);
        if (t2 == t3) {
            t4 = *(float *)((char *)(ts4_word)(a1) + 4);
            t5 = *(float *)((char *)(ts4_word)(a0) + 1120);
            p6 = (ts4_word)t1;
            if (!(t4 == t5)) {
                p6 = (ts4_word)1;
            }
            p9 = (ts4_word)p6;
        } else {
            p9 = (ts4_word)1;
        }
        p10 = (ts4_word)p9;
    } else {
        p10 = (ts4_word)1;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 1181) = (unsigned char)p10;
    *(float *)((char *)(ts4_word)(a0) + 1116) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 1120) = (*(float *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Swing_DLL.xex 0x8863A5E8: if_get u32@0x4, u8@0x49d, u8@0x49d */
void ts4_if_get_u32_off4_8863A5E8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    float t3;
    float t4;
    float t5;
    float t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 1181);
    if ((ts4_word)t2 == 0) {
        t3 = *(float *)((char *)(ts4_word)(a1) + 0);
        t4 = *(float *)((char *)(ts4_word)(t1) + 1116);
        if (t3 == t4) {
            t5 = *(float *)((char *)(ts4_word)(a1) + 4);
            t6 = *(float *)((char *)(ts4_word)(t1) + 1120);
            p7 = (ts4_word)t2;
            if (!(t5 == t6)) {
                p7 = (ts4_word)1;
            }
            p10 = (ts4_word)p7;
        } else {
            p10 = (ts4_word)1;
        }
        p11 = (ts4_word)p10;
    } else {
        p11 = (ts4_word)1;
    }
    *(unsigned char *)((char *)(ts4_word)(t1) + 1181) = (unsigned char)p11;
    *(float *)((char *)(ts4_word)(t1) + 1116) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(t1) + 1120) = (*(float *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Swing_DLL.xex 0x886ECA70: loop_set u8@0x0, u8@0x0 */
void ts4_loop_set_u8_off0_886ECA70(ts4_word a0)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p6;
    ts4_word p7;
    ts4_word t4;

    *(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22072)) + 0) = (unsigned char)2;
    lv1 = (ts4_word)0;
    do {
        lv2 = (ts4_word)0;
        do {
            t4 = *(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22064)) + lv2);
            if ((ts4_word)t4 == (ts4_word)lv1) {
                *(unsigned char *)((char *)(ts4_word)((lv1 + a0)) + ((65536) | 22068)) = (unsigned char)((ts4_word)lv2 < (ts4_word)(*(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22072)) + 0)));
                break;
            }
            p6 = (ts4_word)(lv2 + 1);
            lv2 = p6;
        } while ((ts4_word)p6 < 4);
        p7 = (ts4_word)(lv1 + 1);
        lv1 = p7;
    } while ((ts4_word)p7 < 4);
    return;
}

/* Swing_DLL.xex 0x886ED950: get u8@0x2d, u32@0x74, u8@0x7c, u32@0x20, u32@0x31c, u32@0x30 */
void ts4_get_u8_off2d_886ED950(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 45);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    *(unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 796) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 804) = (unsigned char)((((int)2 < (int)(*(ts4_word *)((char *)(ts4_word)(a1) + 24))) - (!((ts4_word)t2 <= 2))) != 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    return;
}

/* Swing_DLL.xex 0x886F5768: if_call_seq u32@0x94, fn_886F2298, u32@lbl_88D45A48, u8@0x71, fn_886F0B30 */
void ts4_if_call_seq_u32_off94_886F5768(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, float f1, ts4_word a5, float f2, float f3, float f4)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    float t5;
    float t6;
    float t7;

    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    fn_886F2298((ts4_word)(((a1 + (a1 << 1)) << 6) + t1), f1, f2, f3, (ts4_word)a5, f4);
    t3 = *(ts4_word *)lbl_88D45A48;
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 113);
    if ((ts4_word)t4 != 0) {
        t5 = *(float *)((char *)(ts4_word)(t3) + 128);
        t6 = *(float *)((char *)(ts4_word)(t3) + 124);
        t7 = *(float *)((char *)(ts4_word)(t3) + 116);
        fn_886F0B30((ts4_word)(((a1 + (a1 << 1)) << 6) + t1), (*(float *)((char *)(ts4_word)(t3) + 120)), t7, t6, t5, (ts4_word)((((a1 + (a1 << 1)) << 6) + t1) + 64), (ts4_word)((((a1 + (a1 << 1)) << 6) + t1) + 128));
    }
    return;
}

/* Swing_DLL.xex 0x8871B6A0: loop_get u32@0x44, u32@0x48, u32@0x0, u32@0x11c, u32@0x14, vcall */
void ts4_loop_get_u32_off44_8871B6A0(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p16;
    ts4_word lv21;
    ts4_word p34;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t19;
    ts4_word t22;
    ts4_word t24;
    ts4_word t26;
    ts4_word t30;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    lv3 = (ts4_word)t1;
    while ((ts4_word)lv3 != (ts4_word)t2) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t4) + 20))))((ts4_word)lv3, (ts4_word)t5);
        if ((ts4_word)(t7 & 0xff) != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
            fn_8870DAB0((ts4_word)lv3);
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 12))))((ts4_word)lv3);
        p16 = (ts4_word)(lv3 + 44);
        lv3 = p16;
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if (((ts4_word)t19 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t19) + 12)) != 0) && (ts4_word)t1 != (ts4_word)t2) {
        lv21 = (ts4_word)t1;
        do {
            t22 = *(unsigned char *)((char *)(ts4_word)(a0) + 288);
            if ((ts4_word)t22 != 0) {
                t24 = fn_8870DF38((ts4_word)lv21, (ts4_word)t19, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
                t26 = fn_8870DE10((ts4_word)lv21, (ts4_word)t19, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
                if ((ts4_word)(t24 & 0xff) != 0 || (ts4_word)(t26 & 0xff) != 0) {
                    fn_88717218((ts4_word)a0, (ts4_word)lv21);
                }
                t30 = fn_886F34D0((ts4_word)lv21, (ts4_word)t19, (*(float *)((char *)(ts4_word)(a0) + 308)));
                if ((ts4_word)(t30 & 0xff) != 0) {
                    fn_8870DD10((ts4_word)lv21);
                }
            } else {
                *(unsigned char *)((char *)(ts4_word)(lv21) + 16) = (unsigned char)0;
            }
            p34 = (ts4_word)(lv21 + 44);
            lv21 = p34;
        } while ((ts4_word)p34 != (ts4_word)t2);
    }
    return;
}

/* Swing_DLL.xex 0x8883EBA8: call_seq u32@0x24, ts4_find_record_by_key_881ACD38, u32@0x4, u32@0x4 */
ts4_word ts4_call_seq_u32_off24_8883EBA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    t2 = ts4_find_record_by_key_881ACD38((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 260), (ts4_word)(ts4_word)&a2);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t3 + a1);
    return (t3 + a1);
}

/* Swing_DLL.xex 0x8883EEE8: call_seq u32@0x24, ts4_find_record_by_key_881AC778, u32@0x4 */
ts4_word ts4_call_seq_u32_off24_8883EEE8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = ts4_find_record_by_key_881AC778((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 116), (ts4_word)(ts4_word)&a1);
    return (*(ts4_word *)((char *)(ts4_word)(t2) + 4));
}

/* Swing_DLL.xex 0x88840960: call_seq u32@0x8, ts4_find_record_by_key_881AD100, u32@0x64, u32@0x0 */
ts4_word ts4_call_seq_u32_off8_88840960(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = ts4_find_record_by_key_881AD100((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)), (ts4_word)(ts4_word)&a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 100));
    return a0;
}

/* Swing_DLL.xex 0x888409A8: call_seq u32@0x8, ts4_find_record_by_key_881AD100, u32@0x60, u32@0x0 */
ts4_word ts4_call_seq_u32_off8_888409A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = ts4_find_record_by_key_881AD100((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)), (ts4_word)(ts4_word)&a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 96));
    return a0;
}

/* Swing_DLL.xex 0x888409F0: call_seq u32@0x8, ts4_find_record_by_key_881AD100, u32@0x5c, u32@0x0 */
ts4_word ts4_call_seq_u32_off8_888409F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = ts4_find_record_by_key_881AD100((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)), (ts4_word)(ts4_word)&a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 92));
    return a0;
}

/* Swing_DLL.xex 0x8884D930: call_seq u32@lbl_88D459E8, u32@0x24, ts4_find_record_by_key_881ACD90, ts4_loop_get_u32_off0_8883C2B0, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8884D930(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    t3 = ts4_find_record_by_key_881ACD90((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 36)) + 3304), (ts4_word)(ts4_word)&a3);
    t4 = ts4_loop_get_u32_off0_8883C2B0((ts4_word)t3, (ts4_word)((190447616) | 25912));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    fn_8884B120((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    t9 = ts4_loop_get_u32_off0_8883C2B0((ts4_word)t3, (ts4_word)((756285440) | 29634));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 0));
    fn_8884B120((ts4_word)a0, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a2) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 8));
    return t3;
}

/* Swing_DLL.xex 0x8884D9D8: call_seq u32@lbl_88D459E8, u32@0x24, ts4_find_record_by_key_881ACD90, ts4_loop_get_u32_off0_8883C2B0, u32@0x0, fn_8884B120 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8884D9D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;

    t3 = ts4_find_record_by_key_881ACD90((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 36)) + 3304), (ts4_word)(ts4_word)&a2);
    t4 = ts4_loop_get_u32_off0_8883C2B0((ts4_word)t3, (ts4_word)((190447616) | 25912));
    fn_8884B120((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    return t3;
}

/* Swing_DLL.xex 0x88921680: if_call_seq u32@0x20, u8@0xf0, fn_88921558, u32@0x44, u32@0x430, u32@0x58 */
void ts4_if_call_seq_u32_off20_88921680(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 240);
    if ((ts4_word)t2 == 0) {
        t3 = fn_88921558((ts4_word)a0, (ts4_word)a1);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 68) = (ts4_word)((675348480) | 54742);
            *(ts4_word *)((char *)(ts4_word)(t3) + 88) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1072));
            *(float *)((char *)(ts4_word)(t3) + 56) = (*(float *)((char *)(ts4_word)(a1) + 1076));
        }
    }
    return;
}

/* Swing_DLL.xex 0x889216E0: if_call_seq u32@0x20, u8@0xf0, fn_88921558, u32@0x44, u32@0x430, u32@0x5c */
void ts4_if_call_seq_u32_off20_889216E0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 240);
    if ((ts4_word)t2 == 0) {
        t3 = fn_88921558((ts4_word)a0, (ts4_word)a1);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 68) = (ts4_word)((1950679040) | 41599);
            *(ts4_word *)((char *)(ts4_word)(t3) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1072));
            *(float *)((char *)(ts4_word)(t3) + 96) = (*(float *)((char *)(ts4_word)(a1) + 1076));
        }
    }
    return;
}

/* Swing_DLL.xex 0x8893B648: if_call_seq u8@0x2c, u32@g_ts4_session_context, u32@0x3c, u8@0x68, u32@0x6c, u32@0x70 */
void ts4_if_call_seq_u8_off2c_8893B648(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;
    int t10;
    ts4_word t11;
    int t12;
    ts4_word t13;
    int t15;
    ts4_word t17;
    ts4_word t16;
    ts4_word t14;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 44);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    if ((ts4_word)t1 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t3) + 104)) == 1) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 108);
        if ((ts4_word)t5 == (ts4_word)((2696740864) | 58926) && (int)(*(ts4_word *)((char *)(ts4_word)(t3) + 112)) != 1) {
            t8 = fn_881542F8((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)((3350265856) | 47176));
            fn_88151560((ts4_word)a0, (ts4_word)t8);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
            if ((int)t10 >= 0) {
                t11 = *(ts4_word *)g_ts4_session_context;
                t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
                t13 = *(ts4_word *)((char *)(ts4_word)(t11) + 60);
                *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t10 + 1);
                if ((int)(t10 + 1) < (int)t12) {
                    t15 = *(ts4_word *)((char *)(ts4_word)(t13) + 808);
                    if ((int)(t10 + 1) < (int)t15) {
                        t17 = fn_88153120((ts4_word)a0, (ts4_word)((3367501824) | 6458));
                        fn_88151560((ts4_word)a0, (ts4_word)t17);
                        return;
                    }
                    t16 = *(ts4_word *)((char *)(ts4_word)(t11) + 60);
                    *(ts4_word *)((char *)(ts4_word)(t16) + 96) = (ts4_word)((2696740864) | 58926);
                    *(ts4_word *)((char *)(ts4_word)(t16) + 100) = (ts4_word)0;
                    *(unsigned char *)((char *)(ts4_word)(t16) + 93) = (unsigned char)1;
                    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
                    return;
                }
                t14 = *(ts4_word *)((char *)(ts4_word)(t11) + 60);
                *(ts4_word *)((char *)(ts4_word)(t14) + 96) = (ts4_word)((2696740864) | 58926);
                *(ts4_word *)((char *)(ts4_word)(t14) + 100) = (ts4_word)0;
                *(unsigned char *)((char *)(ts4_word)(t14) + 93) = (unsigned char)1;
                *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
                return;
            }
            return;
        }
        return;
    }
    return;
}

/* Swing_DLL.xex 0x889905A8: if_call_seq u8@0x0, fn_8815A998, u32@0x8, ts4_destroy_owned_object */
float ts4_if_call_seq_u8_off0_889905A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    float t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return (*(float *)lbl_8814B440);
    }
    t2 = fn_8815A998((ts4_word)(ts4_word)&loc50[0], (ts4_word)(((int)(((((a1 << 1) + a2) + 9) << 1) + a3) * 28) + a0), (ts4_word)(((a3 + (a3 << 2)) << 3) + a4));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    t4 = loc50[2];
    t5 = *(float *)((char *)(ts4_word)(t3) + 0);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    return ((*(float *)((char *)(ts4_word)((((int)((((a1 << 1) + a2) << 1) + a3) * 28) + a0)) + 528)) + t5);
}
