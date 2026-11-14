/* Loader_DLL.xex 0x833A1EC8-0x8348BC68, executable version 0.0.0.3.
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
extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif

extern char fn_8344FF38[];
extern char fn_8344FFB8[];
extern char fn_8344FFC0[];
extern char fn_83450038[];
extern char fn_83450188[];
extern char fn_834502A0[];
extern char fn_834502E0[];
ts4l_word fn_830AF1B8();
ts4l_word fn_8328B5B8();
ts4l_word fn_83353C08();
ts4l_word fn_8339C7E0();
ts4l_word fn_833A2558();
ts4l_word fn_833E1758();
ts4l_word fn_8340D250();
ts4l_word fn_83440030();
ts4l_word fn_83445FC0();
ts4l_word fn_83450640();
ts4l_word fn_83450710();
ts4l_word fn_83488E48();

/* Loader_DLL.xex 0x833A1EC8: call_seq fn_8339C7E0, fn_83353C08 */
ts4l_word ts4l_call_seq_fn_8339C7E0_833A1EC8(ts4l_word a0, ts4l_word a1)
{
    fn_8339C7E0();
    fn_83353C08((ts4l_word)a0, (ts4l_word)a1);
    return 0;
}

/* Loader_DLL.xex 0x833A3300: if_call_seq fn_833A2558, fn_833E1758 */
ts4l_word ts4l_if_call_seq_fn_833A2558_833A3300(ts4l_word a0, ts4l_word a1)
{
    fn_833A2558((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_833E1758((ts4l_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x833C5288: if_call_seq u32@0xc, u32@0x2c, fn_8328B5B8, u32@0x10, u32@0x2c, fn_8328B5B8 */
ts4l_word ts4l_if_call_seq_u32_offc_833C5288(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word p8;
    ts4l_word p12;
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t5;
    ts4l_word t7;
    ts4l_word t9;
    ts4l_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = fn_8328B5B8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)t1);
        p4 = (ts4l_word)t3;
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
    p8 = (ts4l_word)p4;
    if ((ts4l_word)t5 != 0) {
        t7 = fn_8328B5B8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)t5);
        p8 = (ts4l_word)t7;
    }
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    p12 = (ts4l_word)p8;
    if ((ts4l_word)t9 != 0) {
        t11 = fn_8328B5B8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)t9);
        p12 = (ts4l_word)t11;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    return p12;
}

/* Loader_DLL.xex 0x833D4000: if_call_seq u32@0x0, fn_830AF1B8, u32@0x4, fn_830AF1B8 */
ts4l_word ts4l_if_call_seq_u32_off0_833D4000(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
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
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((ts4l_word)t1 != 0) {
        fn_830AF1B8((ts4l_word)t1);
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    p6 = (ts4l_word)t4;
    if ((ts4l_word)t4 != 0) {
        t5 = fn_830AF1B8((ts4l_word)t4);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x833D4408: if_call_seq u32@0x0, fn_830AF1B8, u32@0x4, fn_830AF1B8, u32@0x8, fn_830AF1B8 */
ts4l_word ts4l_if_call_seq_u32_off0_833D4408(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p21;
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t7;
    ts4l_word t10;
    ts4l_word t13;
    ts4l_word t16;
    ts4l_word t19;
    ts4l_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((ts4l_word)t1 != 0) {
        fn_830AF1B8((ts4l_word)t1);
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    if ((ts4l_word)t4 != 0) {
        fn_830AF1B8((ts4l_word)t4);
    }
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    if ((ts4l_word)t7 != 0) {
        fn_830AF1B8((ts4l_word)t7);
    }
    t10 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    if ((ts4l_word)t10 != 0) {
        fn_830AF1B8((ts4l_word)t10);
    }
    t13 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
    if ((ts4l_word)t13 != 0) {
        fn_830AF1B8((ts4l_word)t13);
    }
    t16 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    if ((ts4l_word)t16 != 0) {
        fn_830AF1B8((ts4l_word)t16);
    }
    t19 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    p21 = (ts4l_word)t19;
    if ((ts4l_word)t19 != 0) {
        t20 = fn_830AF1B8((ts4l_word)t19);
        p21 = (ts4l_word)t20;
    }
    return p21;
}

/* Loader_DLL.xex 0x833D4940: if_call_seq u32@0x0, fn_830AF1B8, u32@0x4, fn_830AF1B8 */
ts4l_word ts4l_if_call_seq_u32_off0_833D4940(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
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
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((ts4l_word)t1 != 0) {
        fn_830AF1B8((ts4l_word)t1);
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    p6 = (ts4l_word)t4;
    if ((ts4l_word)t4 != 0) {
        t5 = fn_830AF1B8((ts4l_word)t4);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x833D4D30: if_call_seq u32@0x0, fn_830AF1B8, u32@0x4, fn_830AF1B8 */
ts4l_word ts4l_if_call_seq_u32_off0_833D4D30(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
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
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((ts4l_word)t1 != 0) {
        fn_830AF1B8((ts4l_word)t1);
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    p6 = (ts4l_word)t4;
    if ((ts4l_word)t4 != 0) {
        t5 = fn_830AF1B8((ts4l_word)t4);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8344E298: if_get u32@0x4, u32@0x24, vcall, u32@0x10, u32@0x134, u32@0x14 */
ts4l_word ts4l_if_get_u32_off4_8344E298(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word p9;
    ts4l_word t1;
    ts4l_word t3;
    int t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    p9 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t1) + 36))))((ts4l_word)a0, (ts4l_word)1);
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 16);
        if ((int)t4 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 308) = (ts4l_word)0;
            p6 = (ts4l_word)200;
        } else {
            p6 = (ts4l_word)100;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)p6;
        p9 = (ts4l_word)t3;
    }
    return p9;
}

/* Loader_DLL.xex 0x8344E300: if_get u32@0x4, u32@0x28, vcall, u32@0x4, u32@0x14 */
ts4l_word ts4l_if_get_u32_off4_8344E300(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t1) + 40))))((ts4l_word)a0);
        p4 = (ts4l_word)t3;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
    return p4;
}

/* Loader_DLL.xex 0x83450460: get u32@0x4, u32@0x0, vcall, u32@0x164, fn_8344FFC0, fn_83450038 */
ts4l_word ts4l_get_u32_off4_83450460(ts4l_word a0)
{
    ts4l_word t3;

    t3 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 0))))((ts4l_word)a0, (ts4l_word)1, (ts4l_word)32);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 356) = (ts4l_word)t3;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 0) = (ts4l_word)(ts4l_word)fn_8344FFC0;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 4) = (ts4l_word)(ts4l_word)fn_83450038;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 8) = (ts4l_word)(ts4l_word)fn_83450188;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 12) = (ts4l_word)(ts4l_word)fn_834502A0;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 16) = (ts4l_word)(ts4l_word)fn_834502E0;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 20) = (ts4l_word)(ts4l_word)fn_8344FF38;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 24) = (ts4l_word)(ts4l_word)fn_8344FFB8;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 28) = (ts4l_word)0;
    return t3;
}

/* Loader_DLL.xex 0x83450C28: if_call_seq fn_83450640, fn_83440030, fn_83445FC0, fn_83450710 */
ts4l_word ts4l_if_call_seq_fn_83450640_83450C28(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t5;

    fn_83450640((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a3);
    if ((ts4l_word)a2 != 0 && (ts4l_word)a3 != 0) {
        fn_83440030((ts4l_word)a0, (ts4l_word)a2, (ts4l_word)a3);
        fn_83445FC0((ts4l_word)a0, (ts4l_word)a2, (ts4l_word)a3);
    }
    t5 = fn_83450710((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x8348B668: if_get fn_8340D250, u8@0x2d, interlocked_dec, fn_83488E48, fn_833E1758, interlocked_dec */
ts4l_word ts4l_if_get_fn_8340D250_8348B668(ts4l_word a0)
{
    unsigned char t2;
    int t3;
    int t8;

    fn_8340D250((ts4l_word)(a0 + 4));
    t2 = *(unsigned char *)((char *)(ts4l_word)(a0) + 45);
    if ((ts4l_word)t2 == 0) {
        t3 = _InterlockedDecrement((volatile long *)(ts4l_word)((a0 + 48)));
        if ((int)t3 == 0) {
            fn_83488E48((ts4l_word)a0);
            fn_833E1758((ts4l_word)a0);
        }
    }
    t8 = _InterlockedDecrement((volatile long *)(ts4l_word)((a0 + 48)));
    if ((int)t8 == 0) {
        fn_83488E48((ts4l_word)a0);
        fn_833E1758((ts4l_word)a0);
    }
    return 0;
}
