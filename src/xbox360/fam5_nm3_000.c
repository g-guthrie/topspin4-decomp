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

extern char lbl_8803E660[];
extern char lbl_880D6AC4[];
extern char lbl_880D72B0[];
extern char lbl_880F7EE4[];
extern char lbl_88CACF08[];
extern char lbl_88D45B1C[];
ts4_word KeTlsGetValue();
ts4_word fn_88170398();
ts4_word fn_88177110();
ts4_word fn_88177288();
ts4_word fn_881B9148();
ts4_word fn_881BF3E8();
ts4_word fn_881C6168();
ts4_word fn_881C63E0();
ts4_word fn_881C6808();
ts4_word fn_881C68D0();
ts4_word fn_8841A510();
ts4_word fn_8841C678();
ts4_word fn_8846B678();
ts4_word fn_8846D4A0();
ts4_word fn_884758C0();
ts4_word fn_884B3FF8();
ts4_word fn_8860BBD8();
ts4_word fn_88912090();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_call_seq_fn_8847EF68_884A4898();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_destroy_polymorphic_value_range();
ts4_word ts4_if_call_seq_u32_off2d0_881C2330();
ts4_word ts4_string_unshare_8819B308();

/* Swing_DLL.xex 0x881BF330: if_call_seq ts4_if_call_seq_u32_off2d0_881C2330, fn_881C63E0, u32@0x2f8, ts4_string_unshare_8819B308, u32@0x6c8, u32@0x6cc */
void ts4_if_call_seq_ts4_if_call_seq_u32_off2d0_881C2330_881BF330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, float f1)
{
    ts4_word q83;
    ts4_word q82;
    ts4_word q81;
    ts4_word q80;
    ts4_word t6;
    ts4_word t7;
    unsigned char t11;

    q83 = a2 + 912;
    q82 = a0 + 1772;
    q80 = a0 + 28;
    ts4_if_call_seq_u32_off2d0_881C2330((ts4_word)(q80));
    q81 = a0 + 768;
    fn_881C63E0((ts4_word)(q81));
    *(ts4_word *)((char *)(ts4_word)(a0) + 760) = (ts4_word)a1;
    if ((ts4_word)a1 != 0) {
        ts4_string_unshare_8819B308((ts4_word)(q82));
        *(ts4_word *)((char *)(ts4_word)(a0) + 1736) = (ts4_word)a3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 1740) = (ts4_word)a4;
        *(ts4_word *)((char *)(ts4_word)(a0) + 1744) = (ts4_word)a5;
        fn_881C68D0((ts4_word)(q81), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 900)));
        t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 900);
        t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 896);
        fn_881C6808((ts4_word)(*(ts4_word *)((char *)(ts4_word)((q81)) + 896)), (ts4_word)t7, (ts4_word)t6);
        fn_881C6168((ts4_word)((q81) + 912), (ts4_word)(q83));
        t11 = *(unsigned char *)((char *)(ts4_word)(a0) + 1768);
        *(float *)((char *)(ts4_word)(a0) + 1760) = f1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 1756) = (ts4_word)a6;
        *(unsigned char *)((char *)(ts4_word)(a0) + 1768) = (unsigned char)((t11 & 0xff) & 0xfffffff3);
        fn_881BF3E8((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x881C22D0: loop_get u32@0x0, u32@0x18, vcall, u32@0x0 */
void ts4_loop_get_u32_off0_881C22D0(ts4_word a0, ts4_word a1)
{
    ts4_word q90;
    ts4_word lv2;
    ts4_word p6;

    lv2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    while ((ts4_word)lv2 != 0) {
        q90 = lv2 + 4;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(q90) + 20))))((ts4_word)q90, (ts4_word)a1);
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 0));
        lv2 = p6;
    }
    return;
}

/* Swing_DLL.xex 0x88202720: loop_get u32@0x54, vcall, u32@0x4, u32@0x18, vcall, u32@0x0 */
void ts4_loop_get_u32_off54_88202720(ts4_word a0, ts4_word a1)
{
    ts4_word q90;
    ts4_word lv5;
    ts4_word p9;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))(t1))((ts4_word)a1);
    }
    lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    while ((ts4_word)lv5 != 0) {
        q90 = lv5 + 4;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(q90) + 20))))((ts4_word)q90, (ts4_word)a1);
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0));
        lv5 = p9;
    }
    return;
}

/* Swing_DLL.xex 0x88202798: loop_get u32@0x58, vcall, u32@0x8, u32@0x18, vcall, u32@0x0 */
void ts4_loop_get_u32_off58_88202798(ts4_word a0, ts4_word a1)
{
    ts4_word q90;
    ts4_word lv5;
    ts4_word p9;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))(t1))((ts4_word)a1);
    }
    lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    while ((ts4_word)lv5 != 0) {
        q90 = lv5 + 4;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(q90) + 20))))((ts4_word)q90, (ts4_word)a1);
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0));
        lv5 = p9;
    }
    return;
}

/* Swing_DLL.xex 0x88408B78: if_call_seq u32@0x34, u32@0x30, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
void ts4_if_call_seq_u32_off34_88408B78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word q80;
    ts4_word t1;
    int t2;
    ts4_word t5;

    q80 = a0 + 44;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)4, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x3fffffff), (ts4_word)t2);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    *(ts4_word *)((char *)(ts4_word)((t5 << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 1);
    return;
}

/* Swing_DLL.xex 0x88442EE8: if_call_seq u32@0x3c, u32@0x38, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
void ts4_if_call_seq_u32_off3c_88442EE8(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word t1;
    int t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    q80 = a0 + 52;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)56);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 0);
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)(t5 + 1);
    memcpy((ts4_word)(((int)t5 * 56) + t6), (ts4_word)a1, (ts4_word)56);
    t8 = *(ts4_word *)((char *)(ts4_word)((((int)t5 * 56) + t6)) + 32);
    if ((ts4_word)t8 == 0) {
        *(ts4_word *)((char *)(ts4_word)((((int)t5 * 56) + t6)) + 48) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)((((int)t5 * 56) + t6)) + 40) = (ts4_word)(ts4_word)lbl_8803E660;
        *(ts4_word *)((char *)(ts4_word)((((int)t5 * 56) + t6)) + 32) = (ts4_word)(ts4_word)lbl_8803E660;
    }
    return;
}

/* Swing_DLL.xex 0x88492920: if_call_seq u32@0xb8, u32@0x4c, u16@0x94, u32@0x4c, u32@0x50, fn_8841C678 */
void ts4_if_call_seq_u32_offb8_88492920(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    int t2;
    ts4_word t3;
    ts4_word t6;

    q80 = a0 + 72;
    *(ts4_word *)((char *)(ts4_word)(a1) + 184) = (ts4_word)a0;
    *(unsigned short *)((char *)(ts4_word)(a1) + 148) = (unsigned short)(*(ts4_word *)((char *)(ts4_word)(a0) + 76));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t2 == (int)(t3 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)4);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    *(ts4_word *)((char *)(ts4_word)((t6 << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 1);
    return;
}

/* Swing_DLL.xex 0x8849E418: if_get u32@0x68, u16@0x0, u16@0x2, u16@0x2, u32@0x4, u32@0x4 */
void ts4_if_get_u32_off68_8849E418(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word q80;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    q80 = a2 + 16;
    if ((int)(q80) != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 104);
        *(unsigned short *)((char *)(ts4_word)((q80)) + 0) = (unsigned short)4;
        *(unsigned short *)((char *)(ts4_word)((q80)) + 2) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a0) + 2));
        *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        *(ts4_word *)((char *)(ts4_word)((q80)) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
        *(ts4_word *)((char *)(ts4_word)((q80)) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
        *(unsigned char *)((char *)(ts4_word)((q80)) + 24) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 88));
        *(ts4_word *)((char *)(ts4_word)((q80)) + 16) = (ts4_word)t1;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 108));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884A3F88: if_call_seq u32@0x8, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884758C0 */
void ts4_if_call_seq_u32_off8_884A3F88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q80;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    int t15;
    ts4_word t16;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t4 = fn_8841A510((ts4_word)t3, (ts4_word)208, (ts4_word)21);
        *(unsigned short *)((char *)(ts4_word)(t4) + 4) = (unsigned short)208;
        t5 = fn_884758C0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
    }
    fn_8846B678((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    q80 = a0 + 12;
    fn_8846D4A0((ts4_word)a1, (ts4_word)(q80));
    if ((ts4_word)(a2 & 0xff) != 0) {
        t10 = *(ts4_word *)lbl_88CACF08;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)0;
        loc50[1] = (ts4_word)0;
        t11 = KeTlsGetValue((ts4_word)t10);
        t12 = fn_8841A510((ts4_word)t11, (ts4_word)80, (ts4_word)47);
        *(unsigned short *)((char *)(ts4_word)(t12) + 4) = (unsigned short)80;
        t13 = ts4_call_seq_fn_8847EF68_884A4898((ts4_word)t12);
        fn_884B3FF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t13);
        *(unsigned char *)((char *)(ts4_word)(t13) + 64) = (unsigned char)0;
        t15 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
        t16 = *(ts4_word *)((char *)(ts4_word)((q80)) + 8);
        if ((int)t15 == (int)(t16 & 0x3fffffff)) {
            fn_8841C678((ts4_word)(q80), (ts4_word)4);
        }
        t19 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
        *(ts4_word *)((char *)(ts4_word)((t19 << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_word)t13;
        *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 1);
    }
    return;
}

/* Swing_DLL.xex 0x884D3710: if_call_seq u32@0x3c, u32@0x38, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
void ts4_if_call_seq_u32_off3c_884D3710(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q80;
    ts4_word t1;
    int t2;
    ts4_word t5;
    ts4_word t6;

    q80 = a0 + 52;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)8);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 0);
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)(t5 + 1);
    *(ts4_word *)((char *)(ts4_word)((t5 << 3)) + t6) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(((t5 << 3) + t6)) + 4) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x884D3770: if_call_seq u32@0x48, u32@0x44, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
void ts4_if_call_seq_u32_off48_884D3770(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q80;
    ts4_word t1;
    int t2;
    ts4_word t5;
    ts4_word t6;

    q80 = a0 + 64;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)8);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 0);
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)(t5 + 1);
    *(ts4_word *)((char *)(ts4_word)((t5 << 3)) + t6) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(((t5 << 3) + t6)) + 4) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x88912A38: if_call_seq lbl_880D72B0, u32@0x0, fn_88177110, fn_88912090, u32@0x14, ts4_destroy_owned_object */
void ts4_if_call_seq_lbl_880D72B0_88912A38(ts4_word a0)
{
    ts4_word q80;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D72B0;
    q80 = a0 + 8;
    fn_88177110((ts4_word)(q80));
    fn_88912090((ts4_word)a0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    fn_88177288((ts4_word)(*(ts4_word *)((char *)(ts4_word)((q80)) + 0)), (ts4_word)t6);
    t9 = *(ts4_word *)((char *)(ts4_word)((q80)) + 0);
    if ((ts4_word)t9 != 0) {
        ts4_destroy_owned_object((ts4_word)t9);
    }
    fn_8860BBD8((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x88928468: loop_get u32@0x20, u32@0x1c, u32@0x0, u32@0xc, vcall, u32@0x4 */
void ts4_loop_get_u32_off20_88928468(ts4_word a0)
{
    ts4_word q81;
    ts4_word q80;
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 12))))((ts4_word)lv3);
            p7 = (ts4_word)(lv3 + 12);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t1);
    }
    q80 = a0 + 28;
    t10 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    fn_88170398((ts4_word)(q80), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q80)) + 0)), (ts4_word)t10);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    q81 = a0 + 16;
    fn_881B9148((ts4_word)(q81));
    return;
}

/* Swing_DLL.xex 0x889284D8: loop_get u32@0x20, u32@0x1c, lbl_880D6AC4, u32@0x0, u32@0x0, u32@0xc */
void ts4_loop_get_u32_off20_889284D8(ts4_word a0)
{
    ts4_word q81;
    ts4_word q80;
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t21;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6AC4;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 12))))((ts4_word)lv3);
            p7 = (ts4_word)(lv3 + 12);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t1);
    }
    q80 = a0 + 28;
    t10 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    fn_88170398((ts4_word)(q80), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q80)) + 0)), (ts4_word)t10);
    t13 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    ts4_destroy_polymorphic_value_range((ts4_word)(*(ts4_word *)((char *)(ts4_word)((q80)) + 0)), (ts4_word)t13);
    t16 = *(ts4_word *)((char *)(ts4_word)((q80)) + 0);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 568) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7EE4;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    q81 = a0 + 16;
    fn_881B9148((ts4_word)(q81));
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t21 != 0) {
        ts4_destroy_owned_object((ts4_word)t21);
    }
    fn_8860BBD8((ts4_word)a0);
    return;
}
