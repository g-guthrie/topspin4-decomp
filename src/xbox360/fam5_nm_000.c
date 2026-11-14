/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, ...).
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

extern char g_ts4_session_context[];
extern char lbl_880D2EFC[];
extern char lbl_8814B440[];
extern char lbl_88C4770C[];
extern char lbl_88C6B4AC[];
extern char lbl_88D41FC0[];
extern char lbl_88D41FC4[];
extern char lbl_88D45930[];
extern char lbl_88D45B1C[];
ts4_word fn_88198CE0();
ts4_word fn_8819B0C8();
ts4_word fn_8819B2A0();
ts4_word fn_8819B818();
ts4_word fn_8819BC18();
ts4_word fn_881ABC10();
ts4_word fn_881E88D0();
ts4_word fn_881EC8C8();
ts4_word fn_882253A0();
ts4_word fn_88263908();
ts4_word fn_88614938();
ts4_word fn_888CC218();
ts4_word fn_88931388();
ts4_word fn_88933EF8();
ts4_word fn_88936AF0();
ts4_word fn_88936BB0();
ts4_word fn_88938E98();
ts4_word fn_88939040();
ts4_word fn_88939210();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_8893BF30();
ts4_word fn_889A7890();
ts4_word ts4_find_record_by_key_881ACBA8();
ts4_word ts4_find_service();
ts4_word ts4_hash_lookup_null_8884E330();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();
ts4_word ts4_loop_get_u32_off0_8891B7A0();
ts4_word ts4_set_scaled_or_default_mode_8893C880(ts4_word, float);
ts4_word ts4_tailcall_fn_8857A338_8857A3F0();
ts4_word ts4_vec_erase_one_881AAE10();

/* Swing_DLL.xex 0x881D0828: if_get u16@0x20, u32@lbl_88D41FC4, u32@0x4, u32@0x13e4, u8@0xa8, u32@0x6dc */
void ts4_if_get_u16_off20_881D0828(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)lbl_88D41FC4;
    if ((ts4_word)((t1 >> 1) & 0x3ff) != 1023) {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 4))) + 5092))) + (((t1 >> 1) & 0x3ff) << 2)));
    } else {
        p6 = (ts4_word)0;
    }
    t9 = *(unsigned char *)((char *)(ts4_word)(p6) + 168);
    if ((ts4_word)t9 != 0) {
        return;
    }
    fn_881E88D0((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1756)), (ts4_word)0);
    return;
}

/* Swing_DLL.xex 0x881E78C0: loop_call_seq u32@lbl_88D41FC0, fn_88198CE0, fn_8819B0C8, fn_8819B818, fn_8819BC18, lbl_880D2EFC */
void ts4_loop_call_seq_u32_lbl_88D41FC0_881E78C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p8;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)a1);
    fn_8819B818((ts4_word)(a0 + 12), (ts4_word)47, (ts4_word)92);
    t5 = fn_8819BC18((ts4_word)(a0 + 12));
    lv6 = (ts4_word)(ts4_word)lbl_880D2EFC;
    do {
        t7 = *(unsigned char *)((char *)(ts4_word)(lv6) + 0);
        p8 = (ts4_word)(lv6 + 1);
        lv6 = p8;
    } while ((ts4_word)t7 != 0);
    fn_8819B2A0((ts4_word)t5, (ts4_word)(ts4_word)lbl_880D2EFC, (ts4_word)((lv6 - (ts4_word)lbl_880D2EFC) + -1));
    fn_88198CE0((ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x8820DF70: if_get u32@0x50, u32@-0xc, u16@0x20, u32@lbl_88D41FC4, u16@0x20, u32@lbl_88D41FC4 */
void ts4_if_get_u32_off50_8820DF70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p10;
    int t2;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + -12);
    if ((int)t2 != 0) {
        t5 = *(unsigned short *)((char *)(ts4_word)(a0) + 32);
        t6 = *(ts4_word *)lbl_88D41FC4;
        if ((ts4_word)((t5 >> 1) & 0x3ff) != 1023) {
            p10 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 4))) + 5092))) + (((t5 >> 1) & 0x3ff) << 2)));
        } else {
            p10 = (ts4_word)0;
        }
        fn_881EC8C8((ts4_word)t6, (ts4_word)(a0 + 80), (ts4_word)(a0 + 88), (ts4_word)p10);
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 92))))((ts4_word)a0, (ts4_word)(a0 + 88));
    return;
}

/* Swing_DLL.xex 0x885B5160: get u32@0x4, u32@0x0, u16@0x2, u32@0x4, u32@0x10, u32@0x8 */
void ts4_get_u32_off4_885B5160(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 2));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 14));
    t5 = *(unsigned short *)((char *)(ts4_word)(a0) + 14);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)((int)(t5 + 7) / 8);
    return;
}

/* Swing_DLL.xex 0x88614840: if_get ts4_find_service, u32@0x0, u32@0x18, vcall, u8@0x20 */
void ts4_if_get_ts4_find_service_88614840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t4;

    (void)a0;
    t1 = ts4_find_service((ts4_word)a1);
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)(ts4_word)&a2);
        if ((ts4_word)t4 != 0) {
            *(unsigned char *)((char *)(ts4_word)(t4) + 32) = (unsigned char)a3;
        }
    }
    return;
}

/* Swing_DLL.xex 0x886150D8: if_call_seq u32@0x14, u32@0x1c, u32@0x8, u32@0x4, u32@0x1c, u32@0x8 */
void ts4_if_call_seq_u32_off14_886150D8(ts4_word a0, ts4_word a1)
{
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    if ((ts4_word)a1 != (ts4_word)((983040) | 65535) && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)) != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
        if ((ts4_word)t7 != (ts4_word)t6) {
            if ((ts4_word)t7 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)a1;
            }
            *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 4)) + 4);
            return;
        }
        fn_88263908((ts4_word)t5, (ts4_word)t7, (ts4_word)(ts4_word)&a1, (ts4_word)1, (ts4_word)1);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x886FE540: call_seq fn_882253A0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_call_seq_fn_882253A0_886FE540(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_882253A0((ts4_word)(ts4_word)&a1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88779018: if_get u16@0x54, u16@0x94, u8@0x95, u8@0x5a, u16@0x94, u8@0x5d */
void ts4_if_get_u16_off54_88779018(ts4_word a0, ts4_word a1)
{
    unsigned short t1;
    unsigned short t2;
    ts4_word t3;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 84);
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 148);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 149);
    *(unsigned char *)((char *)(ts4_word)(a0) + 90) = (unsigned char)((int)((short)t2) < (int)(-(int)((short)t1)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)((int)((short)t1) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 148))));
    *(unsigned char *)((char *)(ts4_word)(a0) + 96) = (unsigned char)((int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 152))) < (int)(-(int)((short)t1)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 99) = (unsigned char)((int)((short)t1) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 152))));
    *(unsigned char *)((char *)(ts4_word)(a0) + 89) = (unsigned char)((int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 140))) < (int)(-(int)((short)t1)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)((int)((short)t1) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 140))));
    *(unsigned char *)((char *)(ts4_word)(a0) + 95) = (unsigned char)((int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 144))) < (int)(-(int)((short)t1)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 98) = (unsigned char)((int)((short)t1) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 144))));
    if ((ts4_word)t3 == 1) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 91) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 94) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 97) = (unsigned char)0;
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)((int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 132))) < (int)(-(int)((short)t1)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 91) = (unsigned char)((int)((short)t1) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 132))));
    *(unsigned char *)((char *)(ts4_word)(a0) + 94) = (unsigned char)((int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 136))) < (int)(-(int)((short)t1)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 97) = (unsigned char)((int)((short)t1) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 136))));
    return;
}

/* Swing_DLL.xex 0x88779BB0: if_get u32@0x0, u32@-0xc, u32@0x0, u16@-0x2, lbl_88C4770C, u32@0x0 */
void ts4_if_get_u32_off0_88779BB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + -12);
    if ((int)t2 >= 1) {
        t3 = *(unsigned short *)((char *)(ts4_word)(((t2 << 1) + t1)) + -2);
        if ((int)(t3 + -48) >= 0 && (int)(t3 + -48) <= 9) {
            t5 = *(ts4_word *)((char *)(ts4_word)(((t3 + -48) << 2)) + (ts4_word)lbl_88C4770C);
            if ((int)t2 != 1 && (int)((*(unsigned short *)((char *)(ts4_word)(((t2 + -2) << 1)) + t1)) + -48) == 1) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1877475328) | 12985);
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1628962816) | 21754);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1628962816) | 21754);
    return;
}

/* Swing_DLL.xex 0x8884E938: if_call_seq ts4_hash_lookup_null_8884E330, ts4_find_record_by_key_881ACBA8, u32@0x8, u32@0x8 */
void ts4_if_call_seq_ts4_hash_lookup_null_8884E330_8884E938(ts4_word a0, int a1)
{
    ts4_word t1;
    ts4_word t2;

    if ((int)a1 > 0) {
        t1 = ts4_hash_lookup_null_8884E330();
        t2 = ts4_find_record_by_key_881ACBA8((ts4_word)t1, (ts4_word)(ts4_word)&a0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 8)) + a1);
    }
    return;
}

/* Swing_DLL.xex 0x88865028: if_call_seq u32@0x4, u32@0x0, fn_881ABC10, ts4_vec_erase_one_881AAE10 */
void ts4_if_call_seq_u32_off4_88865028(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_881ABC10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1, (ts4_word)(ts4_word)&a1);
    if ((ts4_word)t3 != (ts4_word)t1) {
        ts4_vec_erase_one_881AAE10((ts4_word)a0, (ts4_word)t3);
    }
    return;
}

/* Swing_DLL.xex 0x888CEC20: if_call_seq u32@lbl_88D45930, u8@0xe5, fn_888CC218 */
void ts4_if_call_seq_u32_lbl_88D45930_888CEC20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45930;
    if ((ts4_word)t1 != 0) {
        fn_888CC218((ts4_word)t1, (ts4_word)a1, (ts4_word)(ts4_word)&a2, (ts4_word)a3, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 229)));
    }
    return;
}

/* Swing_DLL.xex 0x8891B1C0: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_8891B1C0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    ts4_set_scaled_or_default_mode_8893C880((ts4_word)a1, (*(float *)((char *)(ts4_word)(a0) + 1072)));
    t12 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    if ((ts4_word)t12 != 0) {
        ts4_set_scaled_or_default_mode_8893C880((ts4_word)a1, (*(float *)((char *)(ts4_word)(a0) + 1076)));
    }
    return;
}

/* Swing_DLL.xex 0x8891B250: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_8891B250(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    t10 = *(unsigned char *)((char *)(ts4_word)(a0) + 1069);
    t11 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t11 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t10);
    }
    return;
}

/* Swing_DLL.xex 0x8891B5B0: if_call_seq fn_88939470, fn_88936BB0, u8@0x460, fn_889395D8, fn_889395D8, fn_889395D8 */
void ts4_if_call_seq_fn_88939470_8891B5B0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    float t4;
    ts4_word t11;
    ts4_word t16;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3);
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1120));
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 1120);
    t4 = *(float *)lbl_8814B440;
    if ((ts4_word)t3 != 0) {
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1080));
    } else {
        *(float *)((char *)(ts4_word)(a0) + 1072) = t4;
        *(float *)((char *)(ts4_word)(a0) + 1076) = t4;
        *(float *)((char *)(ts4_word)(a0) + 1080) = t4;
    }
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1123));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1124));
    t11 = *(unsigned char *)((char *)(ts4_word)(a0) + 1123);
    if ((ts4_word)t11 == 0) {
        t16 = *(unsigned char *)((char *)(ts4_word)((a0 + 1124)) + 0);
        if ((ts4_word)t16 == 0) {
            *(float *)((char *)(ts4_word)(a0) + 1084) = t4;
            *(ts4_word *)((char *)(ts4_word)(a0) + 1104) = (ts4_word)t16;
            *(float *)((char *)(ts4_word)(a0) + 1088) = t4;
            *(float *)((char *)(ts4_word)(a0) + 1092) = t4;
        } else {
            fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1084));
            fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1088));
            fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1092));
            fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1104));
        }
    } else {
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1084));
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1088));
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1092));
        fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1104));
    }
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1096));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1100));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1108));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1121));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1122));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1125));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1126));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1128));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1132));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1136));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1140));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1144));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1148));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1152));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1156));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1160));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1164));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1168));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1116));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1112));
    return;
}

/* Swing_DLL.xex 0x8891E978: loop_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_loop_get_u32_off0_8891E978(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word lv11;
    ts4_word p13;
    ts4_word p25;
    ts4_word p26;
    ts4_word lv28;
    ts4_word p30;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t6;
    ts4_word t7;
    ts4_word t10;
    int t19;
    ts4_word t20;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;
    ts4_word t27;
    ts4_word t37;
    ts4_word t38;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
    if ((ts4_word)(t7 & 0xff) != 0) {
        if ((int)t6 < 0) {
            p8 = (ts4_word)1;
            p9 = (ts4_word)(-(int)t6);
        } else {
            p8 = (ts4_word)0;
            p9 = (ts4_word)t6;
        }
        t10 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
        if ((ts4_word)(t10 & 0xff) != 0) {
            lv11 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p9 >> lv11) & 0x1));
                p13 = (ts4_word)(lv11 + 1);
                lv11 = p13;
            } while ((ts4_word)p13 < 3);
        }
        fn_88936AF0((ts4_word)a1, (ts4_word)p8);
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 1080);
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 1076);
    t22 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    t23 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)t22, (ts4_word)t20);
    t24 = fn_88933EF8((ts4_word)t23, (ts4_word)3);
    if ((ts4_word)(t24 & 0xff) != 0) {
        if ((int)t19 < 0) {
            p25 = (ts4_word)1;
            p26 = (ts4_word)(-(int)t19);
        } else {
            p25 = (ts4_word)0;
            p26 = (ts4_word)t19;
        }
        t27 = fn_88933EF8((ts4_word)t23, (ts4_word)3);
        if ((ts4_word)(t27 & 0xff) != 0) {
            lv28 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)t23, (ts4_word)((p26 >> lv28) & 0x1));
                p30 = (ts4_word)(lv28 + 1);
                lv28 = p30;
            } while ((ts4_word)p30 < 3);
        }
        fn_88936AF0((ts4_word)t23, (ts4_word)p25);
    }
    t37 = *(unsigned char *)((char *)(ts4_word)(a0) + 1084);
    t38 = fn_88933EF8((ts4_word)t23, (ts4_word)1);
    if ((ts4_word)(t38 & 0xff) != 0) {
        fn_88936AF0((ts4_word)t23, (ts4_word)t37);
    }
    return;
}

/* Swing_DLL.xex 0x88920088: if_call_seq ts4_loop_get_u32_off0_8891B7A0, u8@0x460, fn_88933EF8, fn_88936AF0, u8@0x460, ts4_if_call_seq_fn_88933EF8_889396A8 */
void ts4_if_call_seq_ts4_loop_get_u32_off0_8891B7A0_88920088(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t18;
    ts4_word t21;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t31;
    ts4_word t34;
    ts4_word t44;
    ts4_word t46;
    ts4_word t47;
    ts4_word t50;
    ts4_word t51;
    ts4_word t54;
    ts4_word t55;
    ts4_word t58;
    ts4_word t59;
    ts4_word t63;
    ts4_word t66;
    ts4_word t69;
    ts4_word t72;
    ts4_word t75;
    ts4_word t78;
    ts4_word t81;
    ts4_word t84;
    ts4_word t87;
    ts4_word t90;
    ts4_word t93;

    ts4_loop_get_u32_off0_8891B7A0();
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 1120);
    t3 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t3 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t2);
    }
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1120);
    if ((ts4_word)t6 != 0) {
        *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1072));
        t8 = loc50[0];
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t8);
        *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1076));
        t11 = loc50[0];
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t11);
        *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1080));
        t14 = loc50[0];
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t14);
    }
    t17 = *(unsigned char *)((char *)(ts4_word)(a0) + 1123);
    t18 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t18 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t17);
    }
    t21 = *(unsigned char *)((char *)(ts4_word)(a0) + 1124);
    t22 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t22 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t21);
    }
    t25 = *(unsigned char *)((char *)(ts4_word)(a0) + 1123);
    if ((ts4_word)t25 != 0 || (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 1124)) != 0) {
        *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1084));
        t28 = loc50[0];
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t28);
        *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1088));
        t31 = loc50[0];
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t31);
        *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1092));
        t34 = loc50[0];
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t34);
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1104)));
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1096)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1100)));
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1108));
    t44 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t44);
    t46 = *(unsigned char *)((char *)(ts4_word)(a0) + 1121);
    t47 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t47 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t46);
    }
    t50 = *(unsigned char *)((char *)(ts4_word)(a0) + 1122);
    t51 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t51 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t50);
    }
    t54 = *(unsigned char *)((char *)(ts4_word)(a0) + 1125);
    t55 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t55 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t54);
    }
    t58 = *(unsigned char *)((char *)(ts4_word)(a0) + 1126);
    t59 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t59 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t58);
    }
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1128));
    t63 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t63);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1132));
    t66 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t66);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1136));
    t69 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t69);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1140));
    t72 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t72);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1144));
    t75 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t75);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1148));
    t78 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t78);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1152));
    t81 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t81);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1156));
    t84 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t84);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1160));
    t87 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t87);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1164));
    t90 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t90);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1168));
    t93 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t93);
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1116)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1112)));
    return;
}

/* Swing_DLL.xex 0x8893B080: loop_get u32@0x14, ts4_if_call_seq_fn_88933EF8_889396A8, u32@0x18, u32@0x0, u32@0x4, vcall */
void ts4_loop_get_u32_off14_8893B080(ts4_word a0, ts4_word a1)
{
    ts4_word lv15;
    ts4_word p17;
    ts4_word lv22;
    ts4_word p31;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;
    ts4_word t14;
    ts4_word t20;
    ts4_word t23;
    ts4_word t26;

    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3, (ts4_word)a1);
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
    t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 36);
    t10 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t10 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t9);
    }
    t13 = fn_88931388((ts4_word)a0);
    t14 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
    if ((ts4_word)(t14 & 0xff) != 0) {
        lv15 = (ts4_word)0;
        do {
            fn_88936AF0((ts4_word)a1, (ts4_word)((t13 >> lv15) & 0x1));
            p17 = (ts4_word)(lv15 + 1);
            lv15 = p17;
        } while ((ts4_word)p17 < 3);
    }
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    lv22 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    while ((ts4_word)lv22 != (ts4_word)t20) {
        t23 = *(ts4_word *)((char *)(ts4_word)(lv22) + 0);
        t26 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 24))))((ts4_word)t23);
        if ((ts4_word)(t26 & 0xff) != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 4))))((ts4_word)t23, (ts4_word)a1);
        }
        p31 = (ts4_word)(lv22 + 4);
        lv22 = p31;
    }
    return;
}

/* Swing_DLL.xex 0x8893BB68: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_8893BB68(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    return;
}

/* Swing_DLL.xex 0x8893BC28: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_if_get_u32_off0_8893BC28(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 1072);
    t9 = fn_88933EF8((ts4_word)t7, (ts4_word)8);
    if ((ts4_word)(t9 & 0xff) != 0) {
        fn_88938E98((ts4_word)t7, (ts4_word)t8);
    }
    fn_88939040((ts4_word)t7, (ts4_word)(a0 + 1073), (ts4_word)256);
    return;
}

/* Swing_DLL.xex 0x8893CA98: loop_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_loop_get_u32_off0_8893CA98(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word lv11;
    ts4_word p13;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t19;
    ts4_word t20;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)2);
    if ((ts4_word)(t7 & 0xff) != 0) {
        if ((int)t6 < 0) {
            p8 = (ts4_word)1;
            p9 = (ts4_word)(-(int)t6);
        } else {
            p8 = (ts4_word)0;
            p9 = (ts4_word)t6;
        }
        t10 = fn_88933EF8((ts4_word)a1, (ts4_word)2);
        if ((ts4_word)(t10 & 0xff) != 0) {
            lv11 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p9 >> lv11) & 0x1));
                p13 = (ts4_word)(lv11 + 1);
                lv11 = p13;
            } while ((ts4_word)p13 < 2);
        }
        fn_88936AF0((ts4_word)a1, (ts4_word)p8);
    }
    t19 = *(unsigned char *)((char *)(ts4_word)(a0) + 1072);
    t20 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t20 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t19);
    }
    return;
}

/* Swing_DLL.xex 0x8893CD70: loop_call_seq fn_88939210, u32@0x4, ts4_if_call_seq_fn_88933EF8_889396A8, u32@0x8, fn_88933EF8, fn_88933EF8 */
void ts4_loop_call_seq_fn_88939210_8893CD70(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word lv9;
    ts4_word p11;
    int t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t17;
    ts4_word t18;

    fn_88939210((ts4_word)a1, (ts4_word)(a0 + 33));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t5 = fn_88933EF8((ts4_word)a1, (ts4_word)2);
    if ((ts4_word)(t5 & 0xff) != 0) {
        if ((int)t4 < 0) {
            p6 = (ts4_word)1;
            p7 = (ts4_word)(-(int)t4);
        } else {
            p6 = (ts4_word)0;
            p7 = (ts4_word)t4;
        }
        t8 = fn_88933EF8((ts4_word)a1, (ts4_word)2);
        if ((ts4_word)(t8 & 0xff) != 0) {
            lv9 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p7 >> lv9) & 0x1));
                p11 = (ts4_word)(lv9 + 1);
                lv9 = p11;
            } while ((ts4_word)p11 < 2);
        }
        fn_88936AF0((ts4_word)a1, (ts4_word)p6);
    }
    t17 = *(unsigned char *)((char *)(ts4_word)(a0) + 109);
    t18 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t18 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t17);
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)));
    return;
}

/* Swing_DLL.xex 0x8893DFF0: loop_get fn_8893BF30, u32@0x438, ts4_if_call_seq_fn_88933EF8_889396A8, u32@0x43c, ts4_if_call_seq_fn_88933EF8_889396A8, u8@0x440 */
void ts4_loop_get_fn_8893BF30_8893DFF0(ts4_word a0, ts4_word a1)
{
    ts4_word lv15;
    ts4_word p20;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t24;

    fn_8893BF30();
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1080)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1084)));
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1088);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 1096);
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)((int)(t10 - (*(ts4_word *)((char *)(ts4_word)(a0) + 1092))) >> 2));
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 1096);
    lv15 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1092));
    while ((ts4_word)lv15 != (ts4_word)t13) {
        t16 = *(ts4_word *)((char *)(ts4_word)(lv15) + 0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 4))))((ts4_word)t16, (ts4_word)a1);
        p20 = (ts4_word)(lv15 + 4);
        lv15 = p20;
    }
    t24 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 28);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t24) + 0))) + 28))))((ts4_word)t24, (ts4_word)a1);
    return;
}

/* Swing_DLL.xex 0x88996128: if_call_seq u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10, ts4_tailcall_fn_8857A338_8857A3F0 */
void ts4_if_call_seq_u32_lbl_88D45B1C_88996128(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t3;

    (void)a0;
    t3 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a1);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16));
    } else {
        p5 = (ts4_word)-1;
    }
    ts4_tailcall_fn_8857A338_8857A3F0((ts4_word)p5, (ts4_word)a2, (ts4_word)1, (ts4_word)(ts4_word)&a3);
    return;
}

/* Swing_DLL.xex 0x88996188: if_call_seq u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10, ts4_tailcall_fn_8857A338_8857A3F0 */
void ts4_if_call_seq_u32_lbl_88D45B1C_88996188(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word t3;

    (void)a0;
    t3 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a1);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16));
    } else {
        p5 = (ts4_word)-1;
    }
    ts4_tailcall_fn_8857A338_8857A3F0((ts4_word)p5, (ts4_word)a2, (ts4_word)1, (ts4_word)(ts4_word)&a3);
    return;
}

/* Swing_DLL.xex 0x8899AD18: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_8899AD18(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    return;
}

/* Swing_DLL.xex 0x889AF4F0: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_889AF4F0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    return;
}

/* Swing_DLL.xex 0x889AF5B0: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_889AF5B0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1076)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1080)));
    return;
}

/* Swing_DLL.xex 0x889AFEE8: if_call_seq u32@0x0, ts4_if_call_seq_fn_88933EF8_889396A8, u32@0x4, ts4_if_call_seq_fn_88933EF8_889396A8, u8@0xc, fn_88933EF8 */
void ts4_if_call_seq_u32_off0_889AFEE8(ts4_word a0, ts4_word a1)
{
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    t6 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t6 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t5);
    }
    t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    t10 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t10 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t9);
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    fn_88939210((ts4_word)a1, (ts4_word)(a0 + 24));
    fn_88939210((ts4_word)a1, (ts4_word)(a0 + 40));
    return;
}

/* Swing_DLL.xex 0x889B0020: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u8@0x42c */
void ts4_if_get_u32_off0_889B0020(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t6);
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1076)));
    fn_889A7890((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1080)));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1084)));
    return;
}

/* Swing_DLL.xex 0x889B0590: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_if_get_u32_off0_889B0590(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 1072);
    t9 = fn_88933EF8((ts4_word)t7, (ts4_word)1);
    if ((ts4_word)(t9 & 0xff) != 0) {
        fn_88936AF0((ts4_word)t7, (ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x889B0708: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_if_get_u32_off0_889B0708(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 1072);
    t9 = fn_88933EF8((ts4_word)t7, (ts4_word)1);
    if ((ts4_word)(t9 & 0xff) != 0) {
        fn_88936AF0((ts4_word)t7, (ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x889B0780: if_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_if_get_u32_off0_889B0780(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t9 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    t11 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1076)));
    t12 = *(unsigned char *)((char *)(ts4_word)(a0) + 1080);
    t13 = fn_88933EF8((ts4_word)t11, (ts4_word)1);
    if ((ts4_word)(t13 & 0xff) != 0) {
        fn_88936AF0((ts4_word)t11, (ts4_word)t12);
    }
    return;
}
