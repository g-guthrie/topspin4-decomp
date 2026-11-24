/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset.
   FAM4 variants: void returns, repeated member reads (MSVC turns the
   re-read of a tested pointer into `clrrwi rX,rY,0`), the inlined
   reference-counted string release of fam4_refstr.h. */
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
#include "fam4_refstr.h"

extern char lbl_880DD750[];
extern char lbl_880DD768[];
extern char lbl_88B3302C[];
extern char lbl_88B33128[];
extern char lbl_88D2E270[];
extern char lbl_88D45B1C[];
ts4_word fn_881D9FD0();
ts4_word fn_881DA100();
ts4_word fn_88331EC0();
ts4_word fn_88332838();
ts4_word fn_88339AF0();
ts4_word fn_883ACE00();
ts4_word fn_88424900();
ts4_word fn_885E7AD8();
ts4_word fn_8860BAB8();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word ts4_set_u32_off34_883ACE40();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88199A70: if_call_seq lbl_880DD768, u32@0x0, u32@0x4, ts4_str_release_fn, lbl_880DD750, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880DD768_88199A70(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD768;
    ts4_str_release((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD750;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881C8600: if_get u32@0x0, u8@0x8, u32@0xc, u32@0x0, interlocked_inc, u32@0x0 */
ts4_word ts4_if_get_u32_off0_881C8600(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word p9;
    ts4_word t14;
    ts4_word t7;
    ts4_word t8;

    if ((ts4_word)((*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8)) & 0x10) != 0) {
        t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
        return t14;
    }
    if ((ts4_word)((*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8)) & 0x20) != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12));
    } else {
        p4 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 12);
    }
    _InterlockedIncrement((volatile long *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) + 4)));
    t7 = *(ts4_word *)((char *)(ts4_word)(p4) + 0);
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t7);
        p9 = (ts4_word)t8;
    }
    *(ts4_word *)((char *)(ts4_word)(p4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8)) | 1);
    return p9;
}

/* Swing_DLL.xex 0x881D9230: if_get u32@0x14, u32@0x20, u32@-0x4, interlocked_inc, fn_881D9FD0, ts4_if_atomic_interlocked_dec_881876D0 */
ts4_word ts4_if_get_u32_off14_881D9230(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p7;
    ts4_word loc50[2];

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4_word)a2;
    if ((ts4_word)a2 > (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20))) {
        p2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    }
    p7 = (ts4_word)0;
    if ((ts4_word)p2 != 0) {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + (p2 << 2))) + -4));
    }
    loc50[0] = (ts4_word)a1;
    if ((ts4_word)a1 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((a1 + 4)));
    }
    fn_881D9FD0((ts4_word)(a0 + 12), (ts4_word)p2, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)a1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)a1);
    }
    fn_881DA100((ts4_word)(a0 + 28), (ts4_word)p2, (ts4_word)p7);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0, (ts4_word)p2);
    return 1;
}

/* Swing_DLL.xex 0x883323B8: if_call_seq u32@lbl_88B3302C, u32@0x4c, fn_88331EC0, u32@lbl_88B3302C, u32@0x4c */
ts4_word ts4_if_call_seq_u32_lbl_88B3302C_883323B8(void)
{
    ts4_word p7;
    ts4_word t3;

    p7 = (ts4_word)0;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 76)) != 0) {
        t3 = fn_88331EC0(((void *)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 76)))));
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 76) = (ts4_word)0;
        p7 = (ts4_word)t3;
    }
    return p7;
}

/* Swing_DLL.xex 0x88332938: loop_call_seq u32@lbl_88B3302C, u32@0x30, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, lbl_88B33128, u32@lbl_88B33128, u8@0x14a */
ts4_word ts4_loop_call_seq_u32_lbl_88B3302C_88332938(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p10;
    unsigned char t6;
    ts4_word t7;

    (void)a0;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)) != 0) {
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(((void *)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)))));
        lv5 = (ts4_word)(*(ts4_word *)lbl_88B33128);
        while ((ts4_word)lv5 != (ts4_word)(ts4_word)lbl_88B33128) {
            t6 = *(unsigned char *)((char *)(ts4_word)(lv5) + 330);
            t7 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            if ((ts4_word)t6 != 0) {
                fn_88332838((ts4_word)lv5);
            }
            p10 = (ts4_word)t7;
            lv5 = p10;
        }
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)));
    }
    return 0;
}

/* Swing_DLL.xex 0x88332DC8: loop_call_seq u32@lbl_88B3302C, u32@0x30, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, lbl_88B33128, u32@lbl_88B33128, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_lbl_88B3302C_88332DC8(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p8;
    ts4_word t6;

    (void)a0;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)) != 0) {
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(((void *)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)))));
        lv5 = (ts4_word)(*(ts4_word *)lbl_88B33128);
        while ((ts4_word)lv5 != (ts4_word)(ts4_word)lbl_88B33128) {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            fn_88332838((ts4_word)lv5);
            p8 = (ts4_word)t6;
            lv5 = p8;
        }
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)));
    }
    return 0;
}

/* Swing_DLL.xex 0x883812A8: if_get u32@0x2ac, fn_88339AF0, u32@0x0, u32@0x50, vcall, fn_88339AF0 */
ts4_word ts4_if_get_u32_off2ac_883812A8(ts4_word a0)
{
    int t5;
    ts4_word t6;
    ts4_word t2;

    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 684)) != 0) {
        t5 = ((ts4_word (*)(void *, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 684))))) + 0))) + 80))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 684)))), (ts4_word)0, (ts4_word)0);
        if ((int)t5 < 0) {
            return 59;
        }
        t6 = fn_88339AF0((ts4_word)a0);
        return t6;
    }
    t2 = fn_88339AF0((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x88385C40: if_call_seq fn_883ACE00, u32@0x30c, u32@0x30c, u32@0x38, u32@0x190, u32@0x1c */
ts4_word ts4_if_call_seq_fn_883ACE00_88385C40(ts4_word a0)
{
    ts4_word p10;
    int t1;

    t1 = fn_883ACE00((ts4_word)a0);
    p10 = (ts4_word)t1;
    if ((int)t1 == 0) {
        if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 780)) != 0) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 780)) & 0xffffffff)) + 400))) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 780))) + 400))) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
        }
        p10 = (ts4_word)0;
    }
    return p10;
}

/* Swing_DLL.xex 0x88385CA8: if_call_seq ts4_set_u32_off34_883ACE40, u32@0x30c, u32@0x30c, u32@0x34, u32@0x190, u32@0x28 */
ts4_word ts4_if_call_seq_ts4_set_u32_off34_883ACE40_88385CA8(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    int t1;

    t1 = ts4_set_u32_off34_883ACE40((ts4_word)a0, (ts4_word)a1);
    p10 = (ts4_word)t1;
    if ((int)t1 == 0) {
        if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 780)) != 0) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 780)) & 0xffffffff)) + 400))) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52));
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 780))) + 400))) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 780))) + 400))) + 44)) + 1);
        }
        p10 = (ts4_word)0;
    }
    return p10;
}

/* Swing_DLL.xex 0x8841DC28: if_get u32@0x8, u8@0x0, u32@0x0, u32@0xc, vcall */
ts4_word ts4_if_get_u32_off8_8841DC28(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)) != 0) {
        ((ts4_word (*)(ts4_word, void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))))) + 0))) + 12))))((ts4_word)a0, ((void *)((*(ts4_word *)((char *)(ts4_word)(a1) + 8)))));
        return a0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88424A98: if_get fn_88424900, u32@0x8, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_fn_88424900_88424A98(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t5;

    t1 = fn_88424900();
    p6 = (ts4_word)t1;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)) != 0) {
        t5 = ((ts4_word (*)(void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))))) + 0))) + 20))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)))));
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88424AE8: if_get u32@0x8, u32@0x0, u32@0x18, vcall, u8@0x0, u8@0x0 */
ts4_word ts4_if_get_u32_off8_88424AE8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word loc50[4];
    ts4_word t4;

    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)) != 0) {
        t4 = ((ts4_word (*)(ts4_word, void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))))) + 0))) + 24))))((ts4_word)(ts4_word)&loc50[0], ((void *)((*(ts4_word *)((char *)(ts4_word)(a1) + 8)))));
        p5 = (ts4_word)t4;
    } else {
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)1;
        p5 = (ts4_word)(ts4_word)&loc50[0];
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(p5) + 0));
    return a0;
}

/* Swing_DLL.xex 0x88463498: if_get u32@0xc, u32@0x0, u32@0x24, vcall, u32@0x10, u32@0x0 */
ts4_word ts4_if_get_u32_offc_88463498(ts4_word a0, ts4_word a1)
{
    ts4_word p9;
    ts4_word t4;
    ts4_word t8;

    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 0))) + 36))))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    p9 = (ts4_word)t4;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)) != 0) {
        t8 = ((ts4_word (*)(void *, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))))) + 0))) + 36))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)))), (ts4_word)a1);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x884C9230: if_get fn_885E7AD8, u32@0x18, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_fn_885E7AD8_884C9230(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;

    t1 = fn_885E7AD8((ts4_word)(a0 + 8), (ts4_word)a1, (ts4_word)a1);
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)) != 0) {
        t5 = ((ts4_word (*)(void *, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))))) + 0))) + 16))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 24)))), (ts4_word)t1);
        return t5;
    }
    return 0;
}

/* Swing_DLL.xex 0x884D4138: if_get fn_885E7AD8, u32@0x1c, u32@0x1c, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_fn_885E7AD8_884D4138(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t6;

    t1 = fn_885E7AD8((ts4_word)(a0 + 12), (ts4_word)a1, (ts4_word)0);
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)) != 0) {
            t6 = ((ts4_word (*)(void *, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))))) + 0))) + 16))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)))), (ts4_word)a1);
            p7 = (ts4_word)t6;
        } else {
            p7 = (ts4_word)0;
        }
        p8 = (ts4_word)p7;
    }
    return p8;
}

/* Swing_DLL.xex 0x88501910: if_get u32@lbl_88D2E270 */
ts4_word ts4_if_get_u32_lbl_88D2E270_88501910(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)lbl_88D2E270) != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word))(((*(ts4_word *)lbl_88D2E270) & 0xffffffff)))((ts4_word)1, (ts4_word)a0);
    }
    return ((2147483648) | 16385);
}

/* Swing_DLL.xex 0x88501940: if_addr lbl_88D2E270, u32@0x10 */
ts4_word ts4_if_addr_lbl_88D2E270_88501940(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2E270) + 16)) != 0) {
        return ((ts4_word (*)(ts4_word))(((*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2E270) + 16)) & 0xffffffff)))((ts4_word)a0);
    }
    return 120;
}

/* Swing_DLL.xex 0x88501968: if_addr lbl_88D2E270, u32@0x14 */
ts4_word ts4_if_addr_lbl_88D2E270_88501968(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2E270) + 20)) != 0) {
        return ((ts4_word (*)(ts4_word))(((*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2E270) + 20)) & 0xffffffff)))((ts4_word)a0);
    }
    return 120;
}

/* Swing_DLL.xex 0x886EFA20: if_get u32@0xc, u32@0xc, u32@0x10, u32@0xc, u32@0x10, u32@0xc */
ts4_word ts4_if_get_u32_offc_886EFA20(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)) != 0) {
        if ((int)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0xffffffff)) + 12)) != (int)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0xffffffff)) + 16))) {
            return fn_8860BAB8((ts4_word)((*(ts4_word *)lbl_88D45B1C) + 552), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 12)), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 16)));
        }
        return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 12));
    }
    return 100;
}

/* Swing_DLL.xex 0x886EFA70: if_get u32@0xc, u32@0x4, u32@0x8, u32@0x4, u32@0x8, u32@0x4 */
ts4_word ts4_if_get_u32_offc_886EFA70(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)) != 0) {
        if ((int)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0xffffffff)) + 4)) != (int)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) & 0xffffffff)) + 8))) {
            return fn_8860BAB8((ts4_word)((*(ts4_word *)lbl_88D45B1C) + 552), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 4)), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 8)));
        }
        return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 4));
    }
    return 3600;
}

/* Swing_DLL.xex 0x8876DE48: if_get u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_if_get_u32_off8_8876DE48(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 0)) != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 0)) & 0xffffffff)) + 8));
    }
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4)) != 0) {
        *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4)) & 0xffffffff)) + 8));
    }
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 8)) == 0) {
        return;
    }
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 8)) & 0xffffffff)) + 8));
    return;
}

/* Swing_DLL.xex 0x88916EE8: if_get u32@0x8, u32@0x42c, u32@0x240, u32@0x8, u32@0x430, u32@0x244 */
void ts4_if_get_u32_off8_88916EE8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) & 0xffffffff)) + 576) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1068));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 580) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1072));
    return;
}
