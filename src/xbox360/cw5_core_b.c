/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif

extern char lbl_88D3E3A4[];
extern char lbl_88D3E3A8[];
extern char lbl_88D3E418[];
extern char lbl_88D45B38[];
ts4_word fn_881519D0();
ts4_word fn_8818A3E0();
ts4_word fn_8818EB10();
ts4_word fn_8818F1D8();
ts4_word fn_88190570();
ts4_word fn_88195368();
ts4_word fn_88196708();
ts4_word fn_88198CE0();
ts4_word fn_8819A0B0();
ts4_word ts4_if_get_u32_lbl_88D45B38_8819A938();
ts4_word ts4_string_make_unique_8819B390();
ts4_word fn_881C5AA8();
ts4_word fn_881F0388();
ts4_word fn_88613268();
ts4_word ts4_call_seq_lbl_880DD434_88193BE0();
ts4_word ts4_counted_ptr_assign_881C38D0();

/* Swing_DLL.xex 0x88190490: if_get u32@0x14, u32@0x1c, fn_881C5AA8, fn_8818F1D8, fn_8818EB10, fn_881519D0 */
ts4_word ts4_if_get_u32_off14_88190490(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t16;
    ts4_word t17;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 == 0) {
        fn_881C5AA8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)1);
    }
    t5 = fn_8818F1D8((ts4_word)a0);
    if ((ts4_word)t5 != 0) {
        fn_8818EB10((ts4_word)t5, (ts4_word)a1);
        t7 = fn_881519D0();
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 16))))((ts4_word)t7);
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)(t10 + 16);
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 24) = (ts4_word)a3;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t12 + 1);
    *(volatile ts4_word *)((char *)(ts4_word)(t5) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a2 << 2)) + t13));
    *(volatile ts4_word *)((char *)(ts4_word)((a2 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20))) = (ts4_word)t5;
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t16 > (ts4_word)t17 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t19 = fn_881F0388((ts4_word)a0, (ts4_word)t16);
        fn_88190570((ts4_word)a0, (ts4_word)t19);
    }
    return t5;
}

/* Swing_DLL.xex 0x88195D00: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88195D00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)3;
    *(ts4_word *)((char *)(ts4_word)(t13) + 16) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(t13) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t13) + 24) = (ts4_word)0;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    ts4_counted_ptr_assign_881C38D0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 100), (ts4_word)a2);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a3);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88195DF0: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88195DF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(t13) + 16) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(t13) + 20) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(t13) + 24) = (ts4_word)a2;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    ts4_counted_ptr_assign_881C38D0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 100), (ts4_word)a5);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a6);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88195EE0: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88195EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(t13) + 16) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(t13) + 20) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(t13) + 24) = (ts4_word)a2;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    ts4_counted_ptr_assign_881C38D0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 100), (ts4_word)a5);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a6);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88195FD0: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88195FD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)4;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    ts4_counted_ptr_assign_881C38D0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 100), (ts4_word)a2);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a3);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x881960A8: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_881960A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;
    ts4_word t15;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)5;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t15) + 124) = (ts4_word)a2;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t15 + 100), (ts4_word)a3);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a4);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88196188: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88196188(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;
    ts4_word t15;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)6;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t15) + 20) = (ts4_word)a2;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t15 + 100), (ts4_word)a3);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a4);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88196268: if_get u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88196268(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;
    ts4_word t15;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D3E3A8;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        fn_88195368();
        p6 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t9 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 4)) + 68));
    if ((ts4_word)t9 != 0) {
        t10 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t9);
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p11;
    if ((ts4_word)p11 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p11 + 4)));
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t13) + 12) = (ts4_word)7;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t13 + 32), (ts4_word)a1);
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t15) + 124) = (ts4_word)a2;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t15 + 100), (ts4_word)a3);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a4);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x8819A938: if_get u32@lbl_88D45B38, fn_88613268, fn_8819A0B0, u32@lbl_88D3E418, ts4_if_get_u32_lbl_88D45B38_8819A938, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D45B38_8819A938(void)
{
    ts4_word p5;
    ts4_word p7;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t10;
    ts4_word t14;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1856, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8819A0B0((ts4_word)t2);
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    *(ts4_word *)lbl_88D3E418 = (ts4_word)p5;
    if ((int)(p5 + 4) != 0) {
        if ((ts4_word)p5 != 0) {
            p7 = (ts4_word)p5;
        } else {
            t6 = ((ts4_word (*)())ts4_if_get_u32_lbl_88D45B38_8819A938)();
            p7 = (ts4_word)t6;
        }
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 16))))((ts4_word)p7);
        *(ts4_word *)((char *)(ts4_word)((p5 + 4)) + 0) = (ts4_word)(t10 + 16);
    }
    t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p5) + 0))) + 20))))((ts4_word)p5);
    ts4_string_make_unique_8819B390((ts4_word)t14);
    return (*(ts4_word *)lbl_88D3E418);
}
