/* Loader_DLL.xex 0x8329FAF8-0x8333E494, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
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
extern long _InterlockedDecrement(volatile long *value);
extern long _InterlockedExchange(volatile long *value, long v);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement, _InterlockedExchange)
#endif

extern char lbl_8352B9C8[];
extern char lbl_8353AF58[];
ts4_word ts4l_pool_unmark_83288808();
ts4_word ts4l_signal_events_8329FF70();
ts4_word fn_832A3B70();
ts4_word fn_83352FA0();
ts4_word fn_83492E58();
ts4_word fn_834B5958();
ts4_word fn_834B5A30();
ts4_word fn_834CFF80();

/* Loader_DLL.xex 0x8329FAF8: loop_get u32@0x0, lbl_8353AF58, interlocked_xchg, u32@lbl_8353AF58, interlocked_xchg, u32@0x26c */
void ts4l_loop_get_u32_off0_8329FAF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    int t2;
    int t3;
    int t4;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        return;
    }
    t2 = _InterlockedExchange((volatile long *)(ts4_word)((ts4_word)lbl_8353AF58), (long)1);
    if ((int)t2 != 0) {
        do {
            do {
                t3 = *(volatile ts4_word *)lbl_8353AF58;
            } while ((int)t3 != 0);
            t4 = _InterlockedExchange((volatile long *)(ts4_word)((ts4_word)lbl_8353AF58), (long)1);
        } while ((int)t4 != 0);
    }
    if ((ts4_word)a1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 620) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a1) + 620)) + 1);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t10 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t10) + 620) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t10) + 620)) + -1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353AF58) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8329FBB0: loop_addr lbl_8353AF58, interlocked_xchg, u32@lbl_8353AF58, interlocked_xchg, u32@0x0, u32@0x0 */
void ts4l_loop_addr_lbl_8353AF58_8329FBB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    int t1;
    int t2;
    int t3;
    ts4_word t6;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = _InterlockedExchange((volatile long *)(ts4_word)((ts4_word)lbl_8353AF58), (long)1);
    if ((int)t1 != 0) {
        do {
            do {
                t2 = *(volatile ts4_word *)lbl_8353AF58;
            } while ((int)t2 != 0);
            t3 = _InterlockedExchange((volatile long *)(ts4_word)((ts4_word)lbl_8353AF58), (long)1);
        } while ((int)t3 != 0);
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t6;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t7;
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353AF58) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x832A3C88: if_atomic interlocked_xchg, u32@0x80, ts4l_pool_unmark_83288808, interlocked_dec, fn_832A3B70 */
ts4_word ts4l_if_atomic_interlocked_xchg_832A3C88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedExchange((volatile long *)(ts4_word)(a1), (long)0);
    if ((ts4_word)t1 != 0) {
        ts4l_pool_unmark_83288808((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)), (ts4_word)t1);
        _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 796)));
    }
    t8 = fn_832A3B70((ts4_word)a0, (ts4_word)a1);
    return t8;
}

/* Loader_DLL.xex 0x832A9278: if_atomic fn_83492E58, interlocked_xchg, u32@0x6070, fn_83352FA0, u32@0x6070, ts4l_signal_events_8329FF70 */
ts4_word ts4l_if_atomic_fn_83492E58_832A9278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)-9;
    if ((int)(a0 + 15984) != 0) {
        t1 = fn_83492E58((ts4_word)a0, (ts4_word)(a0 + 15984), (ts4_word)a1);
        p3 = (ts4_word)t1;
    }
    t4 = _InterlockedExchange((volatile long *)(ts4_word)(((a0 + 65536) + -20296)), (long)0);
    if ((ts4_word)t4 != 0) {
        fn_83352FA0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24688)) + 80), (ts4_word)t4);
        ts4l_signal_events_8329FF70((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24688)));
    }
    return p3;
}

/* Loader_DLL.xex 0x832A9658: if_atomic fn_834B5958, fn_834B5A30, interlocked_xchg, u32@0x6070, fn_83352FA0, u32@0x6070 */
ts4_word ts4l_if_atomic_fn_834B5958_832A9658(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t2;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p3 = (ts4_word)-9;
    if ((int)(a0 + 15984) != 0) {
        fn_834B5958((ts4_word)a0, (ts4_word)(a0 + 15984));
        t2 = fn_834B5A30((ts4_word)a0, (ts4_word)(a0 + 15984), (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    t5 = _InterlockedExchange((volatile long *)(ts4_word)(((a0 + 65536) + -20296)), (long)0);
    if ((ts4_word)t5 != 0) {
        fn_83352FA0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24688)) + 80), (ts4_word)t5);
        ts4l_signal_events_8329FF70((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24688)));
    }
    return p3;
}

/* Loader_DLL.xex 0x832C5CA8: get u32@0x54, u64@0x0, u64@0x68, u32@0x54, u32@0x8, u32@0x70 */
void ts4l_get_u32_off54_832C5CA8(ts4_word a0, ts4_word a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a1) + 104) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 0));
    *(ts4_word *)((char *)(ts4_word)(a1) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 12));
    *(ts4_word *)((char *)(ts4_word)(a1) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 16));
    *(ts4_word *)((char *)(ts4_word)(a1) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 20));
    *(ts4_word *)((char *)(ts4_word)(a1) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 24));
    *(ts4_word *)((char *)(ts4_word)(a1) + 132) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 136) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 32));
    *(ts4_word *)((char *)(ts4_word)(a1) + 140) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 36));
    *(ts4_word *)((char *)(ts4_word)(a1) + 144) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 40));
    *(ts4_word *)((char *)(ts4_word)(a1) + 148) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 44));
    *(ts4_word *)((char *)(ts4_word)(a1) + 152) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 48));
    return;
}

/* Loader_DLL.xex 0x832C5D40: get u32@0x54, u64@0x68, u64@0x0, u32@0x54, u32@0x70, u32@0x8 */
void ts4l_get_u32_off54_832C5D40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;
    ts4_word t15;
    ts4_word t17;
    ts4_word t19;
    ts4_word t21;
    ts4_word t23;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_u64 *)((char *)(ts4_word)(t1) + 0) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 104));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t5) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t9) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t11) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t13) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 132));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t15) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 136));
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t17) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 140));
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t19) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 144));
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t21) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 148));
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(t23) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 152));
    return;
}

/* Loader_DLL.xex 0x832C61D0: if_call_seq u32@0x14, u32@0x0, u8@0xa0, fn_834CFF80, u32@0x18, u32@0x14 */
ts4_word ts4l_if_call_seq_u32_off14_832C61D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t4 = fn_834CFF80((ts4_word)a0, (ts4_word)t2, (ts4_word)(*(unsigned char *)((char *)(ts4_word)((a0 + a2)) + 160)), (ts4_word)t1);
    if ((int)t4 == -1) {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 24))) + 0) = (unsigned char)0;
        p10 = (ts4_word)-1;
    } else {
        t5 = *(ts4_word *)((char *)(ts4_word)(a3) + 24);
        *(ts4_word *)((char *)(ts4_word)(a3) + 20) = (ts4_word)(((t4 & 0x7f) << 1) + t1);
        *(unsigned char *)((char *)(ts4_word)(t5) + 0) = (unsigned char)t4;
        *(ts4_word *)((char *)(ts4_word)(a3) + 24) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 24)) + 1);
        p10 = (ts4_word)0;
    }
    return p10;
}

/* Loader_DLL.xex 0x8333E3F8: if_get u32@0x0, lbl_8352B9C8, u32@0x0, u32@0x0, u32@0x0, u32@0x704 */
void ts4l_if_get_u32_off0_8333E3F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    int t5;
    int t7;
    int t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(((t1 & 0x3) << 2)) + (ts4_word)lbl_8352B9C8)) + t1) >> 1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(((t3 & 0x3) << 2)) + (ts4_word)lbl_8352B9C8)) + t3) >> 1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 1796);
    if ((int)t5 == 0) {
        return;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)(t7 & 0x1) != 0) {
        if ((int)t7 > 0) {
            p8 = (ts4_word)(t7 + -1);
        } else {
            p8 = (ts4_word)(t7 + 1);
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p8;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((int)(t10 & 0x1) == 0) {
        return;
    }
    if ((int)t10 > 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(t10 + -1);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(t10 + 1);
    return;
}
