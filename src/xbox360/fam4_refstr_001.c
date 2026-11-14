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
#include "fam4_refstr.h"

extern char lbl_880DD088[];
extern char lbl_880E83EC[];
extern char lbl_880E9660[];
extern char lbl_880E96D8[];
ts4_word ts4_if_call_seq_u32_offc_8818F850();
ts4_word fn_881992A8();
ts4_word ts4_call_seq_u32_off0_8819AD80();
ts4_word ts4_if_call_seq_u32_off0_8819B0C8();
ts4_word fn_8819BE18();
ts4_word fn_8819BE88();
ts4_word ts4_if_call_seq_u32_off3c_881C57A8();
ts4_word fn_881C88B0();
ts4_word ts4_call_seq_u32_offc_881CCDF0();
ts4_word fn_881F4CC8();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word ts4_if_call_seq_u32_off0_8819B8D0();
ts4_word ts4_if_call_seq_u32_off0_8819B9A8();
ts4_word ts4_loop_get_u32_off14_881F4C00();

/* Swing_DLL.xex 0x88190770: call_seq ts4_if_call_seq_u32_offc_8818F850, u32@0x0, ts4_str_release_fn */
void ts4_call_seq_fn_8818F850_88190770(ts4_word a0)
{
    ts4_word t2;

    ts4_if_call_seq_u32_offc_8818F850((ts4_word)(a0 + 4));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ts4_str_release((ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x881C5C30: call_seq u32@0x4, ts4_if_call_seq_u32_off3c_881C57A8, u32@0x4, u32@0x0, ts4_str_release_fn */
void ts4_call_seq_u32_off4_881C5C30(ts4_word a0)
{
    ts4_word t3;

    ts4_if_call_seq_u32_off3c_881C57A8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    ts4_str_release((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x881D5988: if_call_seq u32@0x3c, lbl_880E83EC, u32@0x0, ts4_str_release_fn, u32@0x38, ts4_if_atomic_interlocked_dec_881876D0 */
void ts4_if_call_seq_u32_off3c_881D5988(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E83EC;
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t3 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t6 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t6);
    }
    ts4_call_seq_u32_offc_881CCDF0((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x881F41E8: call_seq lbl_880E9660, u32@0x0, fn_881F4CC8, ts4_loop_get_u32_off14_881F4C00, u32@0xc, ts4_str_release_fn */
void ts4_call_seq_lbl_880E9660_881F41E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9660;
    t1 = fn_881F4CC8((ts4_word)a0);
    ts4_loop_get_u32_off14_881F4C00((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_str_release((ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E96D8;
    fn_881C88B0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x8863C490: if_call_seq ts4_if_call_seq_u32_off0_8819B0C8, ts4_if_call_seq_u32_off0_8819B9A8, ts4_if_call_seq_u32_off0_8819B9A8, u32@0x0, u32@-0xc, fn_8819BE18 */
ts4_word ts4_if_call_seq_fn_8819B0C8_8863C490(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word loc54[1];
    int t2;
    int t3;
    ts4_word t7;
    ts4_word t9;
    int t11;
    ts4_word t14;
    ts4_word t18;

    ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)(a0 + 8));
    t2 = ts4_if_call_seq_u32_off0_8819B9A8((ts4_word)(a0 + 8), (ts4_word)47);
    t3 = ts4_if_call_seq_u32_off0_8819B9A8((ts4_word)(a0 + 8), (ts4_word)92);
    p4 = (ts4_word)t3;
    if ((int)t2 > (int)t3) {
        p4 = (ts4_word)t2;
    }
    t7 = fn_8819BE18((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 8), (ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0))) + -12)) - p4) + -1));
    ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)(a0 + 12), (ts4_word)t7);
    t9 = loc50[0];
    ts4_str_release((ts4_word)t9);
    t11 = ts4_if_call_seq_u32_off0_8819B8D0((ts4_word)(a0 + 12), (ts4_word)46, (ts4_word)0);
    if ((int)t11 > -1 && (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 12)) + 0))) + -12)) > (int)t11) {
        t14 = fn_8819BE88((ts4_word)(ts4_word)&loc54[0], (ts4_word)(a0 + 12), (ts4_word)t11);
        ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)(a0 + 12), (ts4_word)t14);
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc54[0]);
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ts4_str_release((ts4_word)t18);
    return 1;
}
