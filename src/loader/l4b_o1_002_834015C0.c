/* Loader_DLL.xex 0x834015C0-0x83488F18, executable version 0.0.0.3.
   Small accessor / call-sequence functions generated from the original
   control flow; parameters are untyped words and fields are byte offsets. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif
typedef unsigned long ts4l_word;

extern char lbl_83544784[];
ts4l_word fn_83400AD8();
ts4l_word fn_83401118();
ts4l_word fn_83401250();
ts4l_word fn_83487878();
ts4l_word fn_83487B40();
ts4l_word fn_83488720();

/* Loader_DLL.xex 0x834015C0: if_call_seq u32@0x4, u32@0x0, u32@0x0, fn_83401250, fn_83400AD8, fn_83401118 */
ts4l_word ts4l_if_call_seq_u32_off4_834015C0(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    if ((int)(t1 & 0xff000000) <= (int)(16777216)) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
        if (((ts4l_word)t3 != 0 && (int)a1 != 2) && (int)a1 != 3) {
            if ((int)a1 != 0) {
                t5 = fn_83400AD8((ts4l_word)a1);
                fn_83401118((ts4l_word)a0, (ts4l_word)t5);
            }
        } else {
            fn_83401250((ts4l_word)a0, (ts4l_word)a1);
        }
    }
    return a0;
}

/* Loader_DLL.xex 0x83488918: if_call_seq u32@lbl_83544784, fn_83487878, fn_83487B40, fn_83488720 */
ts4l_word ts4l_if_call_seq_u32_lbl_83544784_83488918(ts4l_word a0)
{
    ts4l_word p4;
    ts4l_word p6;
    int t1;
    ts4l_word t5;
    int t2;
    ts4l_word t3;

    t1 = *(ts4l_word *)lbl_83544784;
    if ((int)t1 != 0) {
        t5 = fn_83488720((ts4l_word)a0);
        p6 = (ts4l_word)t5;
    } else {
        t2 = fn_83487878();
        p4 = (ts4l_word)t2;
        if ((int)t2 >= 0) {
            t3 = fn_83487B40((ts4l_word)a0);
            p4 = (ts4l_word)(((int)t3 >> 31) & t3);
        }
        p6 = (ts4l_word)p4;
    }
    return p6;
}
