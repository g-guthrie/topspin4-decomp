/* Loader_DLL.xex 0x8319E408-0x83234120, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif
typedef unsigned long ts4l_word;
extern long _InterlockedDecrement(volatile long *value);
extern long _InterlockedExchange(volatile long *value, long v);
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement, _InterlockedExchange, _InterlockedIncrement)
#endif

ts4l_word fn_8319D868();
ts4l_word fn_831A2020();
ts4l_word fn_83227710();
ts4l_word fn_83233D10();
ts4l_word fn_83235E58();
ts4l_word fn_833E3A30();
ts4l_word fn_833E3AD0();
ts4l_word ts4_if_call_seq_fn_8340D830_83233DD0();
ts4l_word ts4_set_u32_off0_83234710();
ts4l_word ts4_set_u8_off5f4_83233C68();
ts4l_word ts4l_call_seq_u32_off0_83233D68();

/* Loader_DLL.xex 0x8319E408: if_atomic interlocked_dec, u8@0x0, fn_8319D868 */
ts4l_word ts4l_if_atomic_interlocked_dec_8319E408(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4l_word)((a0 + 16)));
    if ((ts4l_word)t1 == 0) {
        *(unsigned char *)((char *)(ts4l_word)(a0) + 0) = (unsigned char)15;
        fn_8319D868();
    }
    return 1;
}

/* Loader_DLL.xex 0x831A2508: if_atomic interlocked_dec, u8@0x0, fn_831A2020 */
ts4l_word ts4l_if_atomic_interlocked_dec_831A2508(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4l_word)((a0 + 16)));
    if ((ts4l_word)t1 == 0) {
        *(unsigned char *)((char *)(ts4l_word)(a0) + 0) = (unsigned char)15;
        fn_831A2020();
    }
    return 1;
}

/* Loader_DLL.xex 0x831A2560: if_get u32@0x0, interlocked_dec, u8@0x0, fn_831A2020, u32@0x0 */
ts4l_word ts4l_if_get_u32_off0_831A2560(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;

    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p5 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0 && (int)t1 != -1) {
        t2 = _InterlockedDecrement((volatile long *)(ts4l_word)((t1 + 16)));
        p4 = (ts4l_word)t1;
        if ((ts4l_word)t2 == 0) {
            *(volatile unsigned char *)((char *)(ts4l_word)(t1) + 0) = (unsigned char)15;
            t3 = fn_831A2020((ts4l_word)t1, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)(t1 + 16));
            p4 = (ts4l_word)t3;
        }
        *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        p5 = (ts4l_word)p4;
    }
    return p5;
}

/* Loader_DLL.xex 0x831A3458: if_get u32@-0x20, u32@0x3c, vcall, u32@0xc, interlocked_xchg, u32@0xc */
ts4l_word ts4l_if_get_u32_0x20_831A3458(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t8;
    ts4l_word t10;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + -32))) + 60))))((ts4l_word)(a0 + -32));
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    if ((ts4l_word)t4 == 0) {
        t5 = _InterlockedExchange((volatile long *)(ts4l_word)((a0 + 8)), (long)-1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)t5;
    }
    fn_833E3AD0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 12)), (ts4l_word)a1, (ts4l_word)a2);
    t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    t10 = fn_833E3AD0((ts4l_word)((t8 << 1) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))), (ts4l_word)a1, (ts4l_word)a2);
    return t10;
}

/* Loader_DLL.xex 0x832263D0: if_get u64@0x38, u32@0x30, u64@0x58, u64@0x40, u64@0x38, u32@0x30 */
ts4l_word ts4l_if_get_u64_off38_832263D0(ts4l_word a0, int a1)
{
    ts4l_u64 t2;
    ts4l_u64 t3;
    ts4l_u64 t1;

    if ((int)a1 != 1 && (int)a1 == 3) {
        t2 = *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 64);
        t3 = *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 56);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)1;
        *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 88) = (ts4l_u64)(t2 + t3);
        return 0;
    }
    t1 = *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 56);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 88) = (ts4l_u64)t1;
    return 0;
}

/* Loader_DLL.xex 0x83227040: if_get u32@0xc, interlocked_dec, u32@0x0, u32@0x0, vcall */
ts4l_word ts4l_if_get_u32_offc_83227040(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    if ((ts4l_word)t1 == 1) {
        ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 0))))((ts4l_word)a0, (ts4l_word)1);
        return 0;
    }
    t2 = _InterlockedDecrement((volatile long *)(ts4l_word)((a0 + 12)));
    return t2;
}

/* Loader_DLL.xex 0x83228090: if_call_seq u32@0x218, ts4_set_u32_off0_83234710, u32@0x0, u32@0x218 */
ts4l_word ts4l_if_call_seq_u32_off218_83228090(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;
    int t2;
    ts4l_word t3;

    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 536);
    if ((ts4l_word)t1 == 0) {
        p4 = (ts4l_word)((2152726528) | 168);
    } else {
        t2 = ts4_set_u32_off0_83234710((ts4l_word)t1, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5);
        if ((int)t2 >= 0) {
            t3 = *(ts4l_word *)((char *)(ts4l_word)(a3) + 0);
            if ((ts4l_word)t3 == 0) {
                *(ts4l_word *)((char *)(ts4l_word)(a0) + 536) = (ts4l_word)t3;
            }
        }
        p4 = (ts4l_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x83228910: if_call_seq u32@0x0, u32@0x224, u32@0x260, ts4_set_u8_off5f4_83233C68, u32@0x260, fn_83227710 */
ts4l_word ts4l_if_call_seq_u32_off0_83228910(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p12;
    ts4l_word p14;
    ts4l_word loc50[2];
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a0 != 0) {
        t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
        if ((ts4l_word)t1 != 0) {
            loc50[0] = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 548));
            ts4_set_u8_off5f4_83233C68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 608)));
            t5 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 608);
            fn_83227710((ts4l_word)t1);
            t7 = loc50[0];
            if ((ts4l_word)t7 != 0) {
                fn_83235E58((ts4l_word)t7);
                ts4l_call_seq_u32_off0_83233D68((ts4l_word)t5, (ts4l_word)8, (ts4l_word)(ts4l_word)&loc50[0]);
            }
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
            ts4_if_call_seq_fn_8340D830_83233DD0((ts4l_word)t5);
            p12 = (ts4l_word)0;
        } else {
            p12 = (ts4l_word)4;
        }
        p14 = (ts4l_word)p12;
    } else {
        p14 = (ts4l_word)4;
    }
    return p14;
}

/* Loader_DLL.xex 0x83228D40: if_get u32@0x210, u32@0x4, u32@0x5c, u32@0x4, u32@0x5c, u32@0x58 */
ts4l_word ts4l_if_get_u32_off210_83228D40(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    if (((ts4l_word)a0 != 0 && (ts4l_word)a2 != 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 528)) != 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
        t5 = *(ts4l_word *)((char *)(ts4l_word)(t4) + 92);
        if ((ts4l_word)(a1 & 0xffff) >= (ts4l_word)t5) {
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 0) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 8) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 16) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 24) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 32) = (ts4l_u64)0;
            return 34;
        }
        t7 = *(ts4l_word *)((char *)(ts4l_word)(t4) + 88);
        if ((ts4l_word)t7 == 0) {
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 0) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 8) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 16) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 24) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 32) = (ts4l_u64)0;
            return 29;
        }
        *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 0) = (ts4l_u64)(*(ts4l_u64 *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 0));
        *(ts4l_u64 *)((char *)(ts4l_word)(a2) + 8) = (ts4l_u64)(*(ts4l_u64 *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 8));
        *(unsigned short *)((char *)(ts4l_word)(a2) + 16) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 16));
        *(ts4l_word *)((char *)(ts4l_word)(a2) + 20) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 20));
        *(ts4l_word *)((char *)(ts4l_word)(a2) + 24) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 24));
        *(ts4l_word *)((char *)(ts4l_word)(a2) + 28) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 28));
        *(ts4l_word *)((char *)(ts4l_word)(a2) + 32) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(((((a1 & 0xffff) + ((a1 & 0xffff) << 2)) << 3) + t7)) + 32));
        return 0;
    }
    return 4;
}

/* Loader_DLL.xex 0x8322D720: if_get u16@0x3c, u32@0x0, u16@0x4c, u32@0x8, u32@0x40, u32@0x4 */
ts4l_word ts4l_if_get_u16_off3c_8322D720(ts4l_word a0, ts4l_word a1)
{
    if ((ts4l_word)a0 != 0 && (ts4l_word)a1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 60));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 8) = (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 76));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 64));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 12) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 32));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 16) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 20));
        *(ts4l_u64 *)((char *)(ts4l_word)(a1) + 24) = (ts4l_u64)(*(ts4l_u64 *)((char *)(ts4l_word)(a0) + 40));
        *(ts4l_u64 *)((char *)(ts4l_word)(a1) + 32) = (ts4l_u64)(*(ts4l_u64 *)((char *)(ts4l_word)(a0) + 48));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 40) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 548));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 44) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 220));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 48) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 68)) << 3);
        *(unsigned short *)((char *)(ts4l_word)(a1) + 52) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(a0) + 88));
        *(unsigned short *)((char *)(ts4l_word)(a1) + 54) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(a0) + 90));
        *(unsigned short *)((char *)(ts4l_word)(a1) + 56) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(a0) + 92));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 76) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 96));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 60) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 100));
        *(unsigned short *)((char *)(ts4l_word)(a1) + 64) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(a0) + 104));
        *(unsigned short *)((char *)(ts4l_word)(a1) + 66) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(a0) + 106));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 68) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 108));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 72) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 112));
        return 0;
    }
    return 2;
}

/* Loader_DLL.xex 0x8322EE08: if_get u32@0x3c, u32@0x34, u32@0x3c, interlocked_inc, u32@0x3c, interlocked_inc */
void ts4l_if_get_u32_off3c_8322EE08(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 60);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 52);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)(t1 + 1);
    if ((ts4l_word)(t1 + 1) >= (ts4l_word)t2) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
        _InterlockedIncrement((volatile long *)(ts4l_word)((a0 + 68)));
        return;
    }
    _InterlockedIncrement((volatile long *)(ts4l_word)((a0 + 68)));
    return;
}

/* Loader_DLL.xex 0x832340B8: if_call_seq u32@0x0, u32@0x1fc, u32@0x204, fn_83233D10, u32@0x204, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_832340B8(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t1;
    int t3;
    ts4l_word t4;

    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)0;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 508);
    t3 = fn_83233D10((ts4l_word)t1, (ts4l_word)2, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 516)), (ts4l_word)a2);
    if ((int)t3 >= 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 516);
        fn_833E3A30((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)), (ts4l_word)0, (ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(((a1 & 0xff) << 2)) + a0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 0));
    }
    return t3;
}
