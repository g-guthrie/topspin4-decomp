/* Loader_DLL.xex 0x8319CFB0-0x831A19D8, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char lbl_8300CA98[];
extern char lbl_8300CAA8[];
extern char lbl_8300CAE0[];
extern char lbl_8300CAFC[];
ts4l_word KeSetEvent();
ts4l_word fn_8319CCD0();
ts4l_word fn_8319D070();
ts4l_word fn_8319D0F8();
ts4l_word fn_8319D868();
ts4l_word fn_8319DBA0();
ts4l_word fn_8319DC30();
ts4l_word fn_8319E2A8();
ts4l_word fn_8319E408();
ts4l_word fn_8319E468();
ts4l_word fn_8319ECB8();
ts4l_word fn_8319F538();
ts4l_word fn_8319FD00();
ts4l_word fn_831A08E0();
ts4l_word fn_831A0918();
ts4l_word fn_831A0A58();
ts4l_word fn_831A0AF0();
ts4l_word fn_831A0C18();
ts4l_word fn_831A0C88();
ts4l_word fn_831A0D40();
ts4l_word fn_831A0E00();
ts4l_word fn_831A0F10();
ts4l_word fn_831A0FD0();
ts4l_word fn_831A1198();
ts4l_word fn_831A1308();
ts4l_word fn_831F2FE8();
ts4l_word fn_831F4390();
ts4l_word fn_83218A90();
ts4l_word fn_8340D860();

/* Loader_DLL.xex 0x8319CFB0: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4l_word ts4l_if_get_u32_off18_8319CFB0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    if ((ts4l_word)a1 == (ts4l_word)t1) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    } else {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 8);
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    }
    t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 28);
    if ((ts4l_word)a1 == (ts4l_word)t8) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    } else {
        t9 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 4);
        *(ts4l_word *)((char *)(ts4l_word)(t9) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    }
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0));
    t15 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x8319D020: if_call_seq fn_831F2FE8, fn_8319CCD0 */
ts4l_word ts4l_if_call_seq_fn_831F2FE8_8319D020(ts4l_word a0, ts4l_word a1)
{

    fn_831F2FE8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8319CCD0((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8319D368: if_call_seq fn_8319D0F8, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4l_word ts4l_if_call_seq_fn_8319D0F8_8319D368(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;

    t1 = fn_8319D0F8((ts4l_word)a0);
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)a1;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 28));
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 28);
        if ((ts4l_word)t3 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)t1;
        } else {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)t1;
        }
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)t1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8319D3E8: if_call_seq fn_8319D070, fn_831F2FE8, fn_8319CCD0 */
ts4l_word ts4l_if_call_seq_fn_8319D070_8319D3E8(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p2;
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word t4;
    ts4l_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 == 0) {
        p5 = (ts4l_word)a0;
        if ((ts4l_word)a2 != 0) {
            fn_831F2FE8((ts4l_word)a2);
            t4 = fn_8319CCD0((ts4l_word)a2);
            p5 = (ts4l_word)t4;
        }
        p6 = (ts4l_word)p5;
    } else {
        p2 = (ts4l_word)a0;
        if ((ts4l_word)a2 != 0) {
            t1 = fn_8319D070((ts4l_word)a2, (ts4l_word)3);
            p2 = (ts4l_word)t1;
        }
        p6 = (ts4l_word)p2;
    }
    return p6;
}

/* Loader_DLL.xex 0x8319DCF0: set fn_8340D860, u32@0x10, u32@0x14, KeSetEvent, fn_8319DC30, u32@0x0 */
ts4l_word ts4l_set_fn_8340D860_8319DCF0(ts4l_word a0)
{
    ts4l_word t1;

    t1 = fn_8340D860();
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)t1;
    KeSetEvent((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 20)), (ts4l_word)1, (ts4l_word)0);
    fn_8319DC30((ts4l_word)a0, (ts4l_word)-1);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 0))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)0;
    return 0;
}

/* Loader_DLL.xex 0x8319E200: if_get u32@0xcc, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4l_word ts4l_if_get_u32_offcc_8319E200(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 204);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    if ((ts4l_word)a1 == (ts4l_word)t1) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 204) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    } else {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 8);
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    }
    t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 208);
    if ((ts4l_word)a1 == (ts4l_word)t8) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 208) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    } else {
        t9 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 4);
        *(ts4l_word *)((char *)(ts4l_word)(t9) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    }
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0));
    t15 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 212);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 212) = (ts4l_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x8319E5E0: if_call_seq u32@0x4, lbl_8300CA98, u32@0x0, fn_8319DBA0, u32@0x20, fn_8319E408 */
ts4l_word ts4l_if_call_seq_u32_off4_8319E5E0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p11;
    int t1;
    ts4l_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CA98;
    p11 = (ts4l_word)a0;
    if ((int)t1 != 0) {
        fn_8319DBA0((ts4l_word)a0);
        fn_8319E408((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 32)));
        fn_8319E408((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 28)));
        fn_8319E408((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 24)));
        t10 = fn_8319E408((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 20)));
        p11 = (ts4l_word)t10;
    }
    return p11;
}

/* Loader_DLL.xex 0x8319E828: if_get u32@0x40, u32@0x4, vcall, fn_8319E468 */
ts4l_word ts4l_if_get_u32_off40_8319E828(ts4l_word a0)
{
    ts4l_word p5;
    int t3;
    ts4l_word t4;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 64))) + 4))))((ts4l_word)(a0 + 64));
    p5 = (ts4l_word)t3;
    if ((int)t3 >= 0) {
        t4 = fn_8319E468((ts4l_word)a0);
        p5 = (ts4l_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8319EA78: if_call_seq fn_8319E2A8, u32@0x0, u32@0xcc, u32@0x4, u32@0x8, u32@0xcc */
ts4l_word ts4l_if_call_seq_fn_8319E2A8_8319EA78(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;

    t1 = fn_8319E2A8((ts4l_word)a0);
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)a1;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 204));
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)0;
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 204);
        if ((ts4l_word)t3 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t3) + 8) = (ts4l_word)t1;
        } else {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 208) = (ts4l_word)t1;
        }
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 212);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 204) = (ts4l_word)t1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 212) = (ts4l_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8319EAF8: if_call_seq fn_8319E2A8, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4l_word ts4l_if_call_seq_fn_8319E2A8_8319EAF8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;

    t1 = fn_8319E2A8((ts4l_word)a0);
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)a1;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 208));
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 208);
        if ((ts4l_word)t3 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)t1;
        } else {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 204) = (ts4l_word)t1;
        }
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 212);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 208) = (ts4l_word)t1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 212) = (ts4l_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8319F070: if_call_seq fn_8319ECB8, fn_8319D868 */
ts4l_word ts4l_if_call_seq_fn_8319ECB8_8319F070(ts4l_word a0, ts4l_word a1)
{

    fn_8319ECB8((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8319D868((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8319F1C8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0C88, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F1C8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0C88((ts4l_word)(a0 + 4), (ts4l_word)a1);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F240: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0D40, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F240(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0D40((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F2A8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0E00, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F2A8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0E00((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F318: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A08E0, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F318(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A08E0((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2, (ts4l_word)a3);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F380: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0F10, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F380(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0F10((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F3F8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0FD0, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F3F8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0FD0((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F470: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0918, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F470(ts4l_word a0)
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

/* Loader_DLL.xex 0x8319F5F8: call_seq fn_831A0AF0, u32@0x1c, lbl_8300CAE0, lbl_8300CAA8, u32@0x0, u32@0x4 */
ts4l_word ts4l_call_seq_fn_831A0AF0_8319F5F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    fn_831A0AF0((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)a4;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8300CAE0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CAA8;
    return a0;
}

/* Loader_DLL.xex 0x8319F658: if_call_seq lbl_8300CAA8, u32@0x0, u32@0x4, fn_831A0C18, fn_8319F538 */
ts4l_word ts4l_if_call_seq_lbl_8300CAA8_8319F658(ts4l_word a0, ts4l_word a1)
{

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CAA8;
    fn_831A0C18((ts4l_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        fn_8319F538((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8319F8B8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0C88, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F8B8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0C88((ts4l_word)(a0 + 4), (ts4l_word)a1);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F930: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0D40, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F930(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0D40((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319F998: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0E00, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319F998(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0E00((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319FA10: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A08E0, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319FA10(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A08E0((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319FA80: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0F10, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319FA80(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0F10((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319FAE8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0FD0, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319FAE8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0FD0((ts4l_word)(a0 + 4), (ts4l_word)a1, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319FB50: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0918, u32@0xc */
ts4l_word ts4l_get_u32_offc_8319FB50(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0918((ts4l_word)(a0 + 4), (ts4l_word)a1);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x8319FBC8: get u32@0xc, u32@0x0, u32@0x8, vcall, u32@0x94, fn_831F4390 */
ts4l_word ts4l_get_u32_offc_8319FBC8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t7;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    fn_831F4390((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 148)), (ts4l_word)a1);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t7) + 0))) + 20))))((ts4l_word)t7);
    return 0;
}

/* Loader_DLL.xex 0x8319FE70: if_call_seq lbl_8300CAFC, u32@0x0, u32@0x4, fn_831A0C18, fn_8319FD00 */
ts4l_word ts4l_if_call_seq_lbl_8300CAFC_8319FE70(ts4l_word a0, ts4l_word a1)
{

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CAFC;
    fn_831A0C18((ts4l_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        fn_8319FD00((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831A0930: get u32@0x4, u32@0x0, u32@0x10, vcall, u32@0xc, u32@0x0 */
ts4l_word ts4l_get_u32_off4_831A0930(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t8;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 16))))((ts4l_word)t1);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    t8 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t5) + 0))) + 4))))((ts4l_word)t5, (ts4l_word)1);
    return t8;
}

/* Loader_DLL.xex 0x831A0988: get u32@0x4, u32@0x10, u32@0x0, u32@0x14, vcall, u32@0xc */
ts4l_word ts4l_get_u32_off4_831A0988(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t6;
    ts4l_word t9;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 16);
    ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 20))))((ts4l_word)t1, (ts4l_word)t2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    t9 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 4))))((ts4l_word)t6, (ts4l_word)0);
    return t9;
}

/* Loader_DLL.xex 0x831A1090: if_call_seq fn_831A0C18, fn_831A0A58 */
ts4l_word ts4l_if_call_seq_fn_831A0C18_831A1090(ts4l_word a0, ts4l_word a1)
{

    fn_831A0C18((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_831A0A58((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831A10F8: if_call_seq u32@0x0, fn_83218A90, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_831A10F8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p4;
    ts4l_word loc50[4];
    int t2;
    ts4l_word t3;

    t2 = fn_83218A90((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)), (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t3 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)t3;
        p4 = (ts4l_word)1;
    } else {
        p4 = (ts4l_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x831A1298: if_get u32@0xcc, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4l_word ts4l_if_get_u32_offcc_831A1298(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 204);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    if ((ts4l_word)a1 == (ts4l_word)t1) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 204) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    } else {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 8);
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 4));
    }
    t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 208);
    if ((ts4l_word)a1 == (ts4l_word)t8) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 208) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    } else {
        t9 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 4);
        *(ts4l_word *)((char *)(ts4l_word)(t9) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 8));
    }
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0));
    t15 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 212);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 212) = (ts4l_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x831A1430: if_call_seq fn_831A1308, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4l_word ts4l_if_call_seq_fn_831A1308_831A1430(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;

    t1 = fn_831A1308((ts4l_word)a0);
    if ((ts4l_word)t1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)a1;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 208));
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 208);
        if ((ts4l_word)t3 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)t1;
        } else {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 204) = (ts4l_word)t1;
        }
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 212);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 208) = (ts4l_word)t1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 212) = (ts4l_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x831A1638: if_get u32@0xc, u32@0x0, u32@0x0, vcall, u32@0x8, fn_831A1198 */
ts4l_word ts4l_if_get_u32_offc_831A1638(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;

    (void)a0;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
    t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 0))))((ts4l_word)t1);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 8);
    if ((ts4l_word)t5 != 5) {
        fn_831A1198((ts4l_word)a1);
    }
    return t4;
}

/* Loader_DLL.xex 0x831A1888: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0E00, u32@0xc */
ts4l_word ts4l_get_u32_offc_831A1888(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0E00((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x831A18F8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A08E0, u32@0xc */
ts4l_word ts4l_get_u32_offc_831A18F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A08E0((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2, (ts4l_word)a3);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x831A1960: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0F10, u32@0xc */
ts4l_word ts4l_get_u32_offc_831A1960(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0F10((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x831A19D8: get u32@0xc, u32@0x0, u32@0x8, vcall, fn_831A0FD0, u32@0xc */
ts4l_word ts4l_get_u32_offc_831A19D8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t6;

    (void)a1;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
    t5 = fn_831A0FD0((ts4l_word)(a0 + 4), (ts4l_word)0, (ts4l_word)a2);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 20))))((ts4l_word)t6);
    return t5;
}
