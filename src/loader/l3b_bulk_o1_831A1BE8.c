/* Loader_DLL.xex 0x831A1BE8-0x8320C2A8, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char lbl_8300CBA8[];
extern char lbl_830299C8[];
ts4l_word fn_8319CF50();
ts4l_word fn_8319D2D8();
ts4l_word fn_831A0C18();
ts4l_word fn_831A1B40();
ts4l_word fn_831F31F8();
ts4l_word fn_831F36F0();
ts4l_word fn_831F3B08();
ts4l_word fn_831F3CA0();
ts4l_word fn_831F44D0();
ts4l_word fn_831F4520();

/* Loader_DLL.xex 0x831A1BE8: if_call_seq lbl_8300CBA8, u32@0x0, u32@0x4, fn_831A0C18, fn_831A1B40 */
ts4l_word ts4l_if_call_seq_lbl_8300CBA8_831A1BE8(ts4l_word a0, ts4l_word a1)
{

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(ts4l_word)lbl_8300CBA8;
    fn_831A0C18((ts4l_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        fn_831A1B40((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831F3900: if_get u32@0x94, u32@0x8c, u32@0x90, u32@0x84, u32@0x80, u32@0x0 */
ts4l_word ts4l_if_get_u32_off94_831F3900(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    int t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t6;
    ts4l_word t8;
    ts4l_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 148);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 140) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 144) = (ts4l_word)0;
    if ((int)t1 != 0) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 132);
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 128);
        t6 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t2) + 0))) + 20))))((ts4l_word)t2, (ts4l_word)t3);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 136) = (ts4l_word)t6;
    }
    t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 120);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t8) + 0))) + 40))))((ts4l_word)t8, (ts4l_word)1, (ts4l_word)(t9 + 56), (ts4l_word)1, (ts4l_word)(a0 + 136), (ts4l_word)1);
    fn_831F36F0((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x831F3FB8: if_call_seq fn_831F3CA0, fn_831F3B08 */
ts4l_word ts4l_if_call_seq_fn_831F3CA0_831F3FB8(ts4l_word a0, ts4l_word a1)
{

    fn_831F3CA0((ts4l_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_831F3B08((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8320C2A8: loop_get u32@0x8, lbl_830299C8, u32@0x0, u32@0x0, u32@0x24, vcall */
ts4l_word ts4l_loop_get_u32_off8_8320C2A8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t9;
    ts4l_word t12;
    ts4l_word t13;
    ts4l_word t15;
    ts4l_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_830299C8;
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 36))))((ts4l_word)t1);
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    if ((ts4l_word)t6 != 0) {
        do {
            t7 = fn_8319CF50((ts4l_word)(a0 + 16));
            fn_831F31F8((ts4l_word)t7);
            t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
        } while ((ts4l_word)t9 != 0);
    }
    t12 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 88);
    if ((ts4l_word)t12 != 0) {
        do {
            t13 = fn_8319CF50((ts4l_word)(a0 + 56));
            fn_831F31F8((ts4l_word)t13);
            t15 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 88);
        } while ((ts4l_word)t15 != 0);
    }
    fn_831F44D0((ts4l_word)(a0 + 8));
    fn_831F4520((ts4l_word)(a0 + 12));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    fn_8319D2D8((ts4l_word)(a0 + 56));
    t21 = fn_8319D2D8((ts4l_word)(a0 + 16));
    return t21;
}
