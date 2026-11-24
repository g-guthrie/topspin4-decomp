/* Loader_DLL.xex 0x8319E7D8-0x8334FAE0, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char lbl_830009E0[];
extern char lbl_8300CB70[];
extern char lbl_8300CBA8[];
extern char lbl_8300CBE0[];
extern char lbl_8300CBFC[];
extern char lbl_8300CC28[];
extern char lbl_8300CC54[];
extern char lbl_8300CC90[];
extern char lbl_83025C04[];
extern char lbl_83025C34[];
extern char lbl_83025C68[];
extern char lbl_8303AE10[];
extern char lbl_8353AF34[];
ts4l_word fn_830FF250();
ts4l_word fn_830FFBE8();
ts4l_word fn_83120518();
ts4l_word fn_83120540();
ts4l_word fn_8317E1A8();
ts4l_word fn_8319D868();
ts4l_word fn_8319E5E0();
ts4l_word fn_831A0918();
ts4l_word fn_831A0A58();
ts4l_word fn_831A0AF0();
ts4l_word fn_831A2020();
ts4l_word fn_831A26D0();
ts4l_word fn_831F2E18();
ts4l_word fn_831F2FE8();
ts4l_word fn_831F3568();
ts4l_word fn_831F3B08();
ts4l_word fn_831F45E8();
ts4l_word fn_831F4CF8();
ts4l_word fn_831F4E18();
ts4l_word fn_831F59A0();
ts4l_word fn_8320C070();
ts4l_word fn_8320C1E0();
ts4l_word fn_8320C2A8();
ts4l_word fn_8321BC08();
ts4l_word fn_8321CBA0();
ts4l_word fn_832863B0();
ts4l_word fn_8328B5B0();
ts4l_word fn_8333E5D8();
ts4l_word fn_833E1758();
ts4l_word fn_833E6DD0();

/* Loader_DLL.xex 0x8319E7D8: if_call_seq fn_8319E5E0, fn_8319D868 */
ts4l_word ts4l_if_call_seq_fn_8319E5E0_8319E7D8(ts4l_word a0, ts4l_word a1)
{

    fn_8319E5E0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8319D868((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831A0C18: if_get u32@0x4, lbl_8300CB70, u32@0x0, u32@0x0, u32@0xc, vcall */
ts4l_word ts4l_if_get_u32_off4_831A0C18(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CB70;
    p6 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        t4 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 12))))((ts4l_word)t1, (ts4l_word)0);
        t5 = fn_831A0A58((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
        p6 = (ts4l_word)t5;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    return p6;
}

/* Loader_DLL.xex 0x831A1A50: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0918, u32@0xc */
ts4l_word ts4l_get_u32_offc_831A1A50(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0918((ts4l_word)(a0 + 4), (ts4l_word)0);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x831A1CC8: call_seq fn_831A0AF0, u32@0x1c, lbl_8300CBE0, lbl_8300CBA8, u32@0x0, u32@0x4 */
ts4l_word ts4l_call_seq_fn_831A0AF0_831A1CC8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    fn_831A0AF0((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)a4;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CBE0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CBA8;
    return a0;
}

/* Loader_DLL.xex 0x831A1E88: get u32@0xc, u32@0x0, u32@0x8, vcall, u32@0x14, fn_8317E1A8 */
ts4l_word ts4l_get_u32_offc_831A1E88(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t7;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    fn_8317E1A8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 20)), (ts4l_word)a1, (ts4l_word)a2);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t7) + 0))) + 20))))((ts4l_word)t7);
    return 0;
}

/* Loader_DLL.xex 0x831A2268: if_call_seq lbl_8300CBFC, u32@0x0, fn_831A2020 */
ts4l_word ts4l_if_call_seq_lbl_8300CBFC_831A2268(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CBFC;
    if ((int)(a1 & 0x1) != 0) {
        fn_831A2020();
    }
    return a0;
}

/* Loader_DLL.xex 0x831A22E8: if_call_seq lbl_8300CC54, lbl_8300CC28, lbl_8300CBFC, u32@0x0, u32@0x4, u32@0x4 */
ts4l_word ts4l_if_call_seq_lbl_8300CC54_831A22E8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CC54;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CC28;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CBFC;
    if ((int)(a1 & 0x1) != 0) {
        fn_831A2020();
    }
    return a0;
}

/* Loader_DLL.xex 0x831A2970: if_call_seq fn_831A26D0, fn_831A2020 */
ts4l_word ts4l_if_call_seq_fn_831A26D0_831A2970(ts4l_word a0, ts4l_word a1)
{

    fn_831A26D0();
    if ((int)(a1 & 0x1) != 0) {
        fn_831A2020((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831A2D90: if_call_seq u16@0x0, lbl_8300CC90, fn_833E6DD0, u32@0x18 */
ts4l_word ts4l_if_call_seq_u16_off0_831A2D90(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word p5;
    unsigned short t1;
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile unsigned short *)((char *)(ts4l_word)(a0) + 0);
    p5 = (ts4l_word)t1;
    if ((ts4l_word)t1 == 65534) {
        t2 = fn_833E6DD0((ts4l_word)(a0 + 28), (ts4l_word)((ts4l_word)lbl_8300CC90 + 4), (ts4l_word)12);
        if ((int)t2 == 0) {
            p4 = (ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 24)) & 0xffff);
        } else {
            p4 = (ts4l_word)0;
        }
        p5 = (ts4l_word)p4;
    }
    return p5;
}

/* Loader_DLL.xex 0x831A3370: if_get u32@0xc, u32@0x10, u32@0x14, u32@0x8, vcall */
ts4l_word ts4l_if_get_u32_offc_831A3370(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word p8;
    ts4l_word loc50[4];
    ts4l_word loc60[12];
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;

    (void)a7;
    p8 = (ts4l_word)a0;
    if ((ts4l_word)a1 != (ts4l_word)a2) {
        t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
        *(float *)((char *)loc50 + 0) = (*(float *)lbl_830009E0);
        p3 = (ts4l_word)(ts4l_word)&loc50[0];
        if ((ts4l_word)t1 != 0) {
            p3 = (ts4l_word)t1;
        }
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
        t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
        loc60[2] = (ts4l_word)p3;
        loc60[0] = (ts4l_word)a1;
        loc60[1] = (ts4l_word)a2;
        loc60[4] = (ts4l_word)t4;
        loc60[9] = (ts4l_word)t5;
        loc60[5] = (ts4l_word)((int)(a4 & 0xffff) * (int)a3);
        loc60[6] = (ts4l_word)(a4 & 0xffff);
        loc60[8] = (ts4l_word)a6;
        loc60[7] = (ts4l_word)(a5 & 0xffff);
        t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
        loc60[3] = (ts4l_word)0;
        t7 = ((ts4l_word (*)(ts4l_word))(t6))((ts4l_word)(ts4l_word)&loc60[0]);
        p8 = (ts4l_word)t7;
    }
    return p8;
}

/* Loader_DLL.xex 0x831F2F10: get u32@0x0, u32@0x8, vcall, u32@0x24, u32@0x24, u32@0x0 */
ts4l_word ts4l_get_u32_off0_831F2F10(ts4l_word a0)
{
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 8))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 36)) + 1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x831F3278: if_get u32@0x0, u32@0x8, vcall, u32@0x28, u32@0x24, u32@0x0 */
ts4l_word ts4l_if_get_u32_off0_831F3278(ts4l_word a0)
{
    ts4l_word p10;
    ts4l_word t4;
    ts4l_word t9;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 8))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)1;
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 36);
    if ((ts4l_word)t4 == 0) {
        fn_831F2FE8((ts4l_word)a0);
        t9 = fn_831F2E18((ts4l_word)a0);
        p10 = (ts4l_word)t9;
    } else {
        t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 20))))((ts4l_word)a0);
        p10 = (ts4l_word)t7;
    }
    return p10;
}

/* Loader_DLL.xex 0x831F3658: call_seq fn_8320C1E0, u32@0x7c, u32@0x84, lbl_83025C04, u32@0x78, u32@0x0 */
ts4l_word ts4l_call_seq_fn_8320C1E0_831F3658(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    fn_8320C1E0((ts4l_word)a0, (ts4l_word)a3);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 132) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83025C04;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 128) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 148) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 152) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a2) + 4) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 116) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831F36F0: if_get u32@0x84, u32@0x8c, u32@0x0, u32@0x94, u32@0x80, u32@0x18 */
ts4l_word ts4l_if_get_u32_off84_831F36F0(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    int t7;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 132);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 140);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 148);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 128);
    t7 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t3) + 24))))((ts4l_word)t1, (ts4l_word)t5, (ts4l_word)(t2 == 0), (ts4l_word)(t4 == 0));
    if ((int)t7 == (int)((143130624) | 1638)) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 152) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 152)) + 1);
    }
    return t7;
}

/* Loader_DLL.xex 0x831F37D8: if_call_seq u32@0x84, u32@0x4, u32@0x0, fn_8320C2A8, fn_831F3568 */
ts4l_word ts4l_if_call_seq_u32_off84_831F37D8(ts4l_word a0, ts4l_word a1)
{

    *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 132))) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    fn_8320C2A8();
    if ((int)(a1 & 0x1) != 0) {
        fn_831F3568((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831F3A98: call_seq fn_8320C1E0, lbl_83025C34, u32@0x78, u32@0x0, u32@0x7c */
ts4l_word ts4l_call_seq_fn_8320C1E0_831F3A98(ts4l_word a0, ts4l_word a1)
{
    fn_8320C1E0((ts4l_word)a0, (ts4l_word)a1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83025C34;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831F3CA0: if_call_seq u32@0x78, lbl_83025C34, u32@0x0, fn_831F3B08, u32@0x78, u32@0x7c */
ts4l_word ts4l_if_call_seq_u32_off78_831F3CA0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 120);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83025C34;
    if ((ts4l_word)t1 != 0) {
        fn_831F3B08((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 124);
    if ((ts4l_word)t4 != 0) {
        fn_831F3B08((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    t7 = fn_8320C2A8((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x831F44D0: if_get u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4l_word ts4l_if_get_u32_off0_831F44D0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p5 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        p5 = (ts4l_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x831F4520: if_get u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4l_word ts4l_if_get_u32_off0_831F4520(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p5 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        p5 = (ts4l_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x831F5230: if_get u32@0x8, u64@0xc8, u32@0xc0, u32@0x0, u32@0x1c, vcall */
ts4l_word ts4l_if_get_u32_off8_831F5230(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p19;
    ts4l_word p31;
    ts4l_word t1;
    ts4l_word t6;
    ts4l_word t11;
    ts4l_word t12;
    ts4l_word t14;
    ts4l_word t15;
    ts4l_word t16;
    ts4l_word t17;
    int t25;
    ts4l_word t27;
    ts4l_word t30;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x10) != 0) {
        t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
        *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 200) = (ts4l_u64)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 192) = (ts4l_word)0;
        if ((ts4l_word)t1 != 0) {
            ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 28))))((ts4l_word)t1);
        }
        t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
        if ((ts4l_word)t6 != 0) {
            ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 28))))((ts4l_word)t6);
        }
        t11 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 184);
        if ((ts4l_word)t11 != 0) {
            t12 = *(ts4l_word *)((char *)(ts4l_word)(t11) + 16);
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 188) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t11) + 0)) + t12);
            t14 = *(ts4l_word *)((char *)(ts4l_word)(t11) + 0);
            t15 = *(ts4l_word *)((char *)(ts4l_word)(t11) + 16);
            t16 = *(ts4l_word *)((char *)(ts4l_word)(t11) + 28);
            t17 = *(ts4l_word *)((char *)(ts4l_word)(t11) + 24);
            if ((ts4l_word)(t14 + t15) < (ts4l_word)((t16 + t17) + t14)) {
                p19 = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t11) + 32));
            } else {
                p19 = (ts4l_word)0;
            }
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 192) = (ts4l_word)p19;
        }
    }
    if ((int)(a1 & 0x20) != 0) {
        t25 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 8))))((ts4l_word)a0);
        if ((int)t25 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)1;
        }
    } else {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 116) = (ts4l_word)1;
    }
    t27 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 264);
    p31 = (ts4l_word)t27;
    if ((ts4l_word)t27 != 0) {
        t30 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t27) + 0))) + 4))))((ts4l_word)t27, (ts4l_word)a1);
        p31 = (ts4l_word)t30;
    }
    return p31;
}

/* Loader_DLL.xex 0x831F5890: if_call_seq fn_831F4E18, u32@0x0, u32@0x4, u32@0x28, u32@0x8, u32@0x28 */
ts4l_word ts4l_if_call_seq_fn_831F4E18_831F5890(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;

    t1 = fn_831F4E18((ts4l_word)a0);
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)a1;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 40));
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 40);
        if ((ts4l_word)t3 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)t1;
        } else {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)t1;
        }
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)t1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x831F5910: call_seq fn_8320C1E0, u32@0x80, lbl_83025C68, u32@0x78, u32@0x0, u32@0x7c */
ts4l_word ts4l_call_seq_fn_8320C1E0_831F5910(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    fn_8320C1E0((ts4l_word)a0, (ts4l_word)a2);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 128) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_83025C68;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
    fn_831F4CF8((ts4l_word)(a0 + 132));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 184) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 188) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 240) = (ts4l_word)(a0 + 208);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 192) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 200) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 244) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 248) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 252) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 256) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 260) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 264) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 208) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 216) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 224) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 232) = (ts4l_u64)0;
    return a0;
}

/* Loader_DLL.xex 0x831F5F50: if_call_seq fn_831F59A0, fn_831F45E8 */
ts4l_word ts4l_if_call_seq_fn_831F59A0_831F5F50(ts4l_word a0, ts4l_word a1)
{

    fn_831F59A0();
    if ((int)(a1 & 0x1) != 0) {
        fn_831F45E8((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8320C368: if_call_seq fn_8320C2A8, fn_8320C070 */
ts4l_word ts4l_if_call_seq_fn_8320C2A8_8320C368(ts4l_word a0, ts4l_word a1)
{

    fn_8320C2A8();
    if ((int)(a1 & 0x1) != 0) {
        fn_8320C070((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8321BFB8: if_call_seq fn_830FF250, u32@0x0, fn_8321BC08, u32@0x4, fn_830FFBE8 */
ts4l_word ts4l_if_call_seq_fn_830FF250_8321BFB8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p8;
    ts4l_word loc50[4];
    ts4l_word t2;
    ts4l_word t5;
    ts4l_word t7;

    (void)a0;
    fn_830FF250((ts4l_word)a1, (ts4l_word)(ts4l_word)&loc50[0]);
    t2 = loc50[0];
    if ((ts4l_word)t2 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)) == 5) {
        fn_8321BC08((ts4l_word)t2);
        t5 = loc50[0];
        t7 = fn_830FFBE8((ts4l_word)(t5 + 4), (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 4)));
        p8 = (ts4l_word)(((int)t7 >> 31) & t7);
    } else {
        p8 = (ts4l_word)((2147942400) | 87);
    }
    return p8;
}

/* Loader_DLL.xex 0x8321C528: if_call_seq fn_830FF250, fn_8321BC08, fn_830FFBE8 */
ts4l_word ts4l_if_call_seq_fn_830FF250_8321C528(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p6;
    ts4l_word loc50[4];
    ts4l_word t2;
    ts4l_word t4;
    ts4l_word t5;

    fn_830FF250((ts4l_word)a0, (ts4l_word)(ts4l_word)&loc50[0]);
    t2 = loc50[0];
    if ((ts4l_word)t2 == 0) {
        p6 = (ts4l_word)((2147942400) | 87);
    } else {
        fn_8321BC08((ts4l_word)t2);
        t4 = loc50[0];
        t5 = fn_830FFBE8((ts4l_word)(t4 + 4), (ts4l_word)a1);
        p6 = (ts4l_word)(((int)t5 >> 31) & t5);
    }
    return p6;
}

/* Loader_DLL.xex 0x8321CB40: if_call_seq fn_8321BC08, u32@0x4, fn_83120540, u32@0x4, fn_83120540 */
ts4l_word ts4l_if_call_seq_fn_8321BC08_8321CB40(ts4l_word a0, ts4l_word a1)
{

    fn_8321BC08();
    fn_83120540((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8321D488: if_call_seq fn_83120518, fn_8321CBA0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_83120518_8321D488(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t2;

    t1 = fn_83120518((ts4l_word)104);
    if ((ts4l_word)t1 != 0) {
        t2 = fn_8321CBA0((ts4l_word)t1);
        p3 = (ts4l_word)t2;
    } else {
        p3 = (ts4l_word)0;
    }
    if ((ts4l_word)p3 == 0) {
        p5 = (ts4l_word)((2147942400) | 14);
    } else {
        *(ts4l_word *)((char *)(ts4l_word)(p3) + 0) = (ts4l_word)a0;
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)p3;
        p5 = (ts4l_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x83274EE8: if_get u32@lbl_8353AF34, u32@0x0, u32@0x8, vcall */
ts4l_word ts4l_if_get_u32_lbl_8353AF34_83274EE8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p6;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word loc50[2];
    ts4l_word t1;
    int t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    loc50[0] = (ts4l_word)16;
    t1 = *(volatile ts4l_word *)lbl_8353AF34;
    if ((ts4l_word)t1 == 0) {
        p8 = (ts4l_word)((2147483648) | 16387);
    } else {
        if ((ts4l_word)a0 == 0) {
            p7 = (ts4l_word)((2147942400) | 87);
        } else {
            t4 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(volatile ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1, (ts4l_word)a0, (ts4l_word)(ts4l_word)&loc50[0]);
            p6 = (ts4l_word)t4;
            if ((int)t4 >= 0 && (ts4l_word)(loc50[0]) != 16) {
                p6 = (ts4l_word)((2147483648) | 16389);
            }
            p7 = (ts4l_word)p6;
        }
        p8 = (ts4l_word)p7;
    }
    return p8;
}

/* Loader_DLL.xex 0x8327F710: if_call_seq lbl_8303AE10, u32@0x0, fn_833E1758 */
ts4l_word ts4l_if_call_seq_lbl_8303AE10_8327F710(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8303AE10;
    if ((int)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x832D90F0: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x4, vcall, u32@0x0 */
ts4l_word ts4l_if_get_u32_off0_832D90F0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p5 = (ts4l_word)0;
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 0));
        t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t1) + 4))))((ts4l_word)a0);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)t1;
        p5 = (ts4l_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8334FAE0: if_call_seq fn_8333E5D8, fn_8333E5D8, u32@0x0, fn_832863B0, u32@0x0, fn_8328B5B0 */
ts4l_word ts4l_if_call_seq_fn_8333E5D8_8334FAE0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p7;
    ts4l_word t3;
    ts4l_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4l_word)a0;
    if ((ts4l_word)a1 != 0) {
        fn_8333E5D8((ts4l_word)(a1 + 4));
        fn_8333E5D8((ts4l_word)(a1 + 16));
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
        if ((ts4l_word)t3 != 0) {
            fn_832863B0((ts4l_word)t3);
            *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
        }
        t6 = fn_8328B5B0((ts4l_word)a0, (ts4l_word)a1);
        p7 = (ts4l_word)t6;
    }
    return p7;
}
