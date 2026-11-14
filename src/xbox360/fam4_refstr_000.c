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
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;
extern long _InterlockedDecrement(volatile long *value);
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement, _InterlockedIncrement)
#endif
#include "fam4_refstr.h"

extern char g_ts4_default_script_value[];
extern char lbl_880D90A4[];
extern char lbl_880DD088[];
extern char lbl_880DD280[];
extern char lbl_880E74C4[];
extern char lbl_880E74E4[];
extern char lbl_880E7704[];
extern char lbl_880E7B80[];
extern char lbl_880E8618[];
extern char lbl_880E8AE8[];
extern char lbl_880E8BB4[];
extern char lbl_880E8BF0[];
extern char lbl_880E9358[];
extern char lbl_880E9420[];
extern char lbl_880E94A4[];
extern char lbl_880E96D8[];
extern char lbl_880E97F0[];
extern char lbl_880E9890[];
extern char lbl_880E9AC0[];
extern char lbl_880E9B68[];
extern char lbl_880E9CC0[];
extern char lbl_880E9E8C[];
extern char lbl_880EA028[];
extern char lbl_880F62E4[];
extern char lbl_88D2F130[];
extern char lbl_88D41F80[];
extern char lbl_88D41FC4[];
extern char lbl_88D45A60[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_8818A530();
ts4_word fn_8818EB10();
ts4_word fn_8818ECC0();
ts4_word fn_881935D8();
ts4_word fn_881992A8();
ts4_word fn_8819B2A0();
ts4_word fn_881AAF10();
ts4_word fn_881B19A0();
ts4_word fn_881C36D0();
ts4_word ts4_counted_ptr_assign_881C38D0();
ts4_word fn_881C5950();
ts4_word fn_881C88B0();
ts4_word fn_881CECD0();
ts4_word fn_881CF4E8();
ts4_word fn_881E1D70();
ts4_word fn_881E7948();
ts4_word fn_881E9010();
ts4_word fn_881EB370();
ts4_word fn_881EF828();
ts4_word fn_881EFE08();
ts4_word fn_881F0008();
ts4_word fn_881F0388();
ts4_word ts4_if_call_seq_u32_off0_881F0598();
ts4_word fn_881F1668();
ts4_word ts4_call_seq_lbl_880E9660_881F41E8();
ts4_word fn_881F6930();
ts4_word fn_881FB5C8();
ts4_word fn_881FBC60();
ts4_word ts4_if_get_u32_lbl_88D3E418_882016F8();
ts4_word fn_88201BA0();
ts4_word fn_88202900();
ts4_word fn_88204320();
ts4_word fn_88204478();
ts4_word fn_885938B0();
ts4_word fn_88627EC0();
ts4_word fn_887A3F38();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_call_seq_fn_881FBB40_881FB860();
ts4_word ts4_call_seq_ts4_copy_bytes_88864B98();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_get_u32_off0_88197750();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word ts4_if_call_seq_lbl_880E7494_881E0B80();
ts4_word ts4_if_call_seq_u32_off0_8818FFE8();
ts4_word ts4_if_call_seq_u32_off0_881F2498();
ts4_word ts4_if_call_seq_u32_off0_881FFDC0();
ts4_word ts4_loop_call_seq_u32_off4_881E49E8();
ts4_word ts4_memset();
ts4_word ts4_tailcall_fn_88564B00_88564770();

/* Swing_DLL.xex 0x88151988: if_atomic interlocked_dec, u32@0x0, u32@0x0, u32@0x8 */
void ts4_if_atomic_interlocked_dec_88151988(ts4_word a0)
{
    int t1;
    ts4_word t2;

    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 12)));
    if ((int)t1 != 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ((void (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 8))))((ts4_word)t2, (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x8818EDD0: if_call_seq fn_8818ECC0, u32@0x18, fn_8818A530, u32@0x18, u32@0x14, fn_8818A530 */
void ts4_if_call_seq_fn_8818ECC0_8818EDD0(ts4_word a0)
{
    ts4_word t5;
    ts4_word t8;

    if ((ts4_word)a0 != 0) {
        fn_8818ECC0((ts4_word)(a0 + 20));
        fn_8818A530((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((ts4_word)t5 != 0) {
            fn_881992A8((ts4_word)0, (ts4_word)t5);
        }
        t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
        ts4_str_release((ts4_word)t8);
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x8818F850: if_call_seq u32@0xc, ts4_if_atomic_interlocked_dec_881876D0, u32@0xc, ts4_if_call_seq_u32_off0_8818FFE8, u32@0x4, ts4_str_release_fn */
void ts4_if_call_seq_u32_offc_8818F850(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    }
    ts4_if_call_seq_u32_off0_8818FFE8((ts4_word)(a0 + 8));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_str_release((ts4_word)t5);
    return;
}

/* Swing_DLL.xex 0x881929F8: if_call_seq u32@0x8, lbl_880DD280, u32@0x0, fn_881935D8, u32@0x2c, ts4_if_atomic_interlocked_dec_881876D0 */
void ts4_if_call_seq_u32_off8_881929F8(ts4_word a0)
{
    int t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD280;
    if ((int)t1 != 0) {
        fn_881935D8();
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t4 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t7 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t7);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    ts4_str_release((ts4_word)t10);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x8819AD80: call_seq u32@0x0, ts4_str_release_fn */
void ts4_call_seq_u32_off0_8819AD80(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ts4_str_release((ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x881A2570: call_seq u32@0x0, ts4_str_release_fn */
ts4_word ts4_call_seq_u32_off0_881A2570(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ts4_str_release((ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x881BD8A0: if_call_seq lbl_880E74C4, u32@0x0, u32@0x14, ts4_if_atomic_interlocked_dec_881876D0, u32@0x14, u32@0x10 */
void ts4_if_call_seq_lbl_880E74C4_881BD8A0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E74C4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    ts4_str_release((ts4_word)t4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881BD990: call_seq u32@0x18, lbl_880E74E4, u32@0x0, ts4_str_release_fn, u32@0x10, ts4_str_release_fn */
void ts4_call_seq_u32_off18_881BD990(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E74E4;
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    ts4_str_release((ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881C3820: if_call_seq u32@0x10, u32@0xc, ts4_if_atomic_interlocked_dec_881876D0, u32@0xc, u32@0x8, ts4_if_atomic_interlocked_dec_881876D0 */
void ts4_if_call_seq_u32_off10_881C3820(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t4 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_str_release((ts4_word)t7);
    fn_881E1D70((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x881C57A8: if_call_seq u32@0x3c, u32@0x3c, fn_881992A8, u32@0x3c, fn_881C5950, u32@0x8 */
void ts4_if_call_seq_u32_off3c_881C57A8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t9;

    if ((ts4_word)a0 != 0) {
        t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
        if ((ts4_word)t2 != 0) {
            fn_881992A8((ts4_word)0, (ts4_word)t2);
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
        fn_881C5950((ts4_word)(a0 + 4));
        fn_8818A530((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
        ts4_str_release((ts4_word)t9);
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x881C6008: call_seq fn_881B19A0, u32@0x14, ts4_str_release_fn, u32@0x10, ts4_str_release_fn */
void ts4_call_seq_fn_881B19A0_881C6008(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    fn_881B19A0((ts4_word)(a0 + 24));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    ts4_str_release((ts4_word)t2);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    ts4_str_release((ts4_word)t4);
    return;
}

/* Swing_DLL.xex 0x881CCDF0: call_seq u32@0xc, ts4_str_release_fn, lbl_880E96D8, u32@0x0, fn_881C88B0, lbl_880DD088 */
void ts4_call_seq_u32_offc_881CCDF0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E96D8;
    fn_881C88B0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881CD908: call_seq u32@0x28, lbl_880E7B80, u32@0x0, ts4_str_release_fn, ts4_call_seq_lbl_880E9660_881F41E8 */
void ts4_call_seq_u32_off28_881CD908(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7B80;
    ts4_str_release((ts4_word)t1);
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x881CF7A0: call_seq lbl_880E7704, ts4_assign_text_from_c_string, u32@0x0, u32@-0xc, fn_8819B2A0, fn_881F6930 */
ts4_word ts4_call_seq_lbl_880E7704_881CF7A0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E7704);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    fn_8819B2A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + -12)));
    t5 = fn_881F6930((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t6 = loc50[0];
    ts4_str_release((ts4_word)t6);
    return t5;
}

/* Swing_DLL.xex 0x881D2DE8: if_get u32@0x10, u32@0x384, u32@g_ts4_default_script_value, u32@0x380, fn_8818EB10, u32@lbl_88D41FC4 */
ts4_word ts4_if_get_u32_off10_881D2DE8(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    fn_8818EB10((ts4_word)(ts4_word)&loc54[0], (ts4_word)(p5 + 16));
    t8 = fn_881E7948((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)(ts4_word)&loc54[0]);
    _InterlockedIncrement((volatile long *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t8) + 0)) + 4)));
    t11 = loc50[0];
    if ((ts4_word)t11 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t11);
        loc50[0] = (ts4_word)0;
    }
    t15 = loc54[0];
    ts4_str_release((ts4_word)t15);
    return 0;
}

/* Swing_DLL.xex 0x881D2ED0: if_call_seq u32@0x10, u32@0x384, u32@g_ts4_default_script_value, u32@0x380, fn_8818EB10, u32@lbl_88D41FC4 */
ts4_word ts4_if_call_seq_u32_off10_881D2ED0(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    fn_8818EB10((ts4_word)(ts4_word)&loc54[0], (ts4_word)(p5 + 16));
    t8 = fn_881E7948((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)(ts4_word)&loc54[0]);
    ts4_if_atomic_interlocked_dec_881876D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t8) + 0)));
    t11 = loc50[0];
    if ((ts4_word)t11 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t11);
        loc50[0] = (ts4_word)0;
    }
    t14 = loc54[0];
    ts4_str_release((ts4_word)t14);
    return 0;
}

/* Swing_DLL.xex 0x881D4110: if_call_seq u32@0x14, ts4_str_release_fn, u32@0x10, ts4_if_atomic_interlocked_dec_881876D0, u32@0x10, lbl_880DD088 */
void ts4_if_call_seq_u32_off14_881D4110(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t3 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881D9098: if_call_seq lbl_880E8618, u32@0x0, u32@0x10, ts4_if_atomic_interlocked_dec_881876D0, u32@0x10, u32@0xc */
void ts4_if_call_seq_lbl_880E8618_881D9098(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8618;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_str_release((ts4_word)t4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881DBB08: call_seq u32@0x1c, lbl_880E8BB4, u32@0x0, ts4_str_release_fn, lbl_880E96D8, u32@0x18 */
void ts4_call_seq_u32_off1c_881DBB08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8BB4;
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E96D8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_881C88B0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881DBC88: if_get u32@0x10, u32@0x0, interlocked_inc, u32@0x10, fn_881F1668, u32@0x10 */
void ts4_if_get_u32_off10_881DBC88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        loc50[0] = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            _InterlockedIncrement((volatile long *)(ts4_word)((t2 + 4)));
        }
        fn_881F1668((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(ts4_word)&loc50[0]);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 72))))((ts4_word)t8, (ts4_word)(t9 != 0));
    }
    return;
}

/* Swing_DLL.xex 0x881DD6F8: if_call_seq u32@0x1c, lbl_880E8BF0, u32@0x0, ts4_str_release_fn, u32@0x18, ts4_if_atomic_interlocked_dec_881876D0 */
void ts4_if_call_seq_u32_off1c_881DD6F8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8BF0;
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t3 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    ts4_str_release((ts4_word)t6);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    ts4_str_release((ts4_word)t8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E96D8;
    fn_881C88B0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881DD858: if_call_seq u32@lbl_88D41FC4, ts4_get_u32_off0_88197750, fn_8818EB10, fn_881EB370, ts4_str_release_fn, ts4_counted_ptr_assign_881C38D0 */
void ts4_if_call_seq_u32_lbl_88D41FC4_881DD858(ts4_word a0, ts4_word a1)
{
    ts4_word loc54[1];
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;

    t1 = *(ts4_word *)lbl_88D41FC4;
    t2 = ts4_get_u32_off0_88197750((ts4_word)(ts4_word)&loc54[0], (ts4_word)(t1 + 20), (ts4_word)a1);
    t3 = fn_8818EB10((ts4_word)(ts4_word)&loc58[0], (ts4_word)t2);
    fn_881EB370((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)t3);
    t5 = loc54[0];
    ts4_str_release((ts4_word)t5);
    ts4_counted_ptr_assign_881C38D0((ts4_word)(a0 + 24), (ts4_word)(ts4_word)&loc50[0]);
    t8 = loc50[0];
    if ((ts4_word)t8 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x881E0A88: call_seq lbl_880E8AE8, ts4_assign_text_from_c_string, ts4_if_call_seq_lbl_880E7494_881E0B80, u32@0x74, fn_881CECD0, fn_881C36D0 */
void ts4_call_seq_lbl_880E8AE8_881E0A88(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;

    ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E8AE8);
    t2 = ts4_if_call_seq_lbl_880E7494_881E0B80((ts4_word)(ts4_word)&loc54[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t4 = fn_881CECD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116)));
    fn_881C36D0((ts4_word)t4, (ts4_word)t2);
    t6 = loc54[0];
    ts4_str_release((ts4_word)t6);
    t8 = loc50[0];
    ts4_str_release((ts4_word)t8);
    return;
}

/* Swing_DLL.xex 0x881E3178: if_addr lbl_880E9358, u32@lbl_88D41F80, u32@0x0, u32@0x0, u32@0x14, u32@0x10 */
ts4_word ts4_if_addr_lbl_880E9358_881E3178(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;

    t1 = *(ts4_word *)lbl_88D41F80;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9358;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 84))))((ts4_word)t1, (ts4_word)t4, (ts4_word)t3);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_str_release((ts4_word)t8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E96D8;
    fn_881C88B0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881EF9A0: if_call_seq u32@0x0, ts4_str_release_fn, u32@0x0, u32@0x0, u32@0x30, u32@0x18 */
void ts4_if_call_seq_u32_off0_881EF9A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t5 + -1);
    if ((ts4_word)(t5 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t7 = fn_881F0388((ts4_word)a0, (ts4_word)(t5 + -1));
        fn_881EF828((ts4_word)a0, (ts4_word)t7);
    }
    return;
}

/* Swing_DLL.xex 0x881F0208: if_call_seq u32@0x0, ts4_str_release_fn, u32@0x0, u32@0x0, u32@0x30, u32@0x18 */
void ts4_if_call_seq_u32_off0_881F0208(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t5 + -1);
    if ((ts4_word)(t5 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t7 = fn_881F0388((ts4_word)a0, (ts4_word)(t5 + -1));
        fn_881EFE08((ts4_word)a0, (ts4_word)t7);
    }
    return;
}

/* Swing_DLL.xex 0x881F02C8: if_call_seq u32@0x0, ts4_str_release_fn, u32@0x0, u32@0x0, u32@0x30, u32@0x18 */
void ts4_if_call_seq_u32_off0_881F02C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t5 + -1);
    if ((ts4_word)(t5 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t7 = fn_881F0388((ts4_word)a0, (ts4_word)(t5 + -1));
        fn_881F0008((ts4_word)a0, (ts4_word)t7);
    }
    return;
}

/* Swing_DLL.xex 0x881F0400: call_seq u32@0x4, ts4_str_release_fn, u32@0x0, ts4_str_release_fn */
void ts4_call_seq_u32_off4_881F0400(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ts4_str_release((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x881F1130: if_call_seq u32@0x44, lbl_880E9420, u32@0x0, ts4_str_release_fn, u32@0x24, ts4_if_atomic_interlocked_dec_881876D0 */
void ts4_if_call_seq_u32_off44_881F1130(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9420;
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t3 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x881F1BE0: if_addr lbl_880E94A4, u32@0xc, u32@0x0, u32@lbl_88D41F80, u32@0x0, u32@0x3c */
ts4_word ts4_if_addr_lbl_880E94A4_881F1BE0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E94A4;
    t2 = *(ts4_word *)lbl_88D41F80;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 60))))((ts4_word)t2, (ts4_word)t1);
    ts4_if_call_seq_u32_off0_881F2498((ts4_word)(a0 + 16));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ts4_str_release((ts4_word)t7);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881F27E8: call_seq u32@0x1c, fn_881CF4E8, u32@0x0, ts4_str_release_fn */
ts4_word ts4_call_seq_u32_off1c_881F27E8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    t2 = fn_881CF4E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28)));
    t3 = loc50[0];
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    ts4_str_release((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x881F7090: call_seq u32@0x8, ts4_str_release_fn, u32@0x4, ts4_str_release_fn */
void ts4_call_seq_u32_off8_881F7090(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_str_release((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x881F8F40: if_call_seq lbl_880E97F0, u32@0x0, fn_881FB5C8, fn_881FB5C8, ts4_loop_call_seq_u32_off4_881E49E8, ts4_loop_call_seq_u32_off4_881E49E8 */
void ts4_if_call_seq_lbl_880E97F0_881F8F40(ts4_word a0)
{
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;
    ts4_word t18;
    ts4_word t21;
    ts4_word t23;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E97F0;
    fn_881FB5C8((ts4_word)(a0 + 44));
    fn_881FB5C8((ts4_word)(a0 + 56));
    ts4_loop_call_seq_u32_off4_881E49E8((ts4_word)(a0 + 56));
    ts4_loop_call_seq_u32_off4_881E49E8((ts4_word)(a0 + 44));
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t5 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t5);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t8 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    t11 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t11 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t11);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    t14 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t14 != 0) {
        fn_881FBC60((ts4_word)t14);
        fn_881992A8((ts4_word)0, (ts4_word)t14);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    t18 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t18 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t18);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t21 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_str_release((ts4_word)t21);
    t23 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t23 != 0) {
        ts4_call_seq_fn_881FBB40_881FB860((ts4_word)t23);
        fn_881992A8((ts4_word)0, (ts4_word)t23);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881FBD90: if_call_seq u32@0x4, ts4_if_atomic_interlocked_dec_881876D0, u32@0x4, u32@0x0, ts4_str_release_fn, u32@0x0 */
void ts4_if_call_seq_u32_off4_881FBD90(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ts4_str_release((ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t8 + -1);
    if ((ts4_word)(t8 + -1) < (ts4_word)t7 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t10 = fn_881F0388((ts4_word)a0, (ts4_word)(t8 + -1));
        fn_881F0008((ts4_word)a0, (ts4_word)t10);
    }
    return;
}

/* Swing_DLL.xex 0x881FBE68: if_call_seq u32@0x4, ts4_if_atomic_interlocked_dec_881876D0, u32@0x4, u32@0x0, ts4_str_release_fn */
void ts4_if_call_seq_u32_off4_881FBE68(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ts4_str_release((ts4_word)t4);
    return;
}

/* Swing_DLL.xex 0x881FC180: if_call_seq lbl_880E9890, u32@0x0, u32@0x60, ts4_if_atomic_interlocked_dec_881876D0, u32@0x60, u32@0x5c */
void ts4_if_call_seq_lbl_880E9890_881FC180(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9890;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92);
    ts4_str_release((ts4_word)t4);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    ts4_str_release((ts4_word)t6);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x881FD2E0: call_seq u32@0x0, ts4_assign_text_from_c_string, u32@lbl_88D41FC4, u32@0xb4, ts4_if_call_seq_u32_off0_881FFDC0, ts4_str_release_fn */
void ts4_call_seq_u32_off0_881FD2E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word t6;

    (void)a0;
    ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    ts4_if_call_seq_u32_off0_881FFDC0((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 180)));
    t6 = loc50[0];
    ts4_str_release((ts4_word)t6);
    return;
}

/* Swing_DLL.xex 0x88201338: call_seq u32@0x24, lbl_880E9AC0, u32@0x0, ts4_str_release_fn, ts4_call_seq_lbl_880E9660_881F41E8 */
void ts4_call_seq_u32_off24_88201338(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9AC0;
    ts4_str_release((ts4_word)t1);
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x882019D0: if_call_seq u32@0x6c, lbl_880E9B68, u32@0x0, ts4_str_release_fn, u32@0x5c, ts4_str_release_fn */
void ts4_if_call_seq_u32_off6c_882019D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;
    ts4_word t14;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9B68;
    ts4_str_release((ts4_word)t1);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92);
    ts4_str_release((ts4_word)t3);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t5 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t5);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    ts4_str_release((ts4_word)t8);
    fn_88204478((ts4_word)(a0 + 32));
    fn_8818A530((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    fn_8818A530((ts4_word)0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    t14 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    ts4_str_release((ts4_word)t14);
    fn_88204320((ts4_word)(a0 + 20));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    ts4_if_call_seq_u32_off0_881F0598((ts4_word)(a0 + 16));
    fn_881E1D70((ts4_word)(a0 + 12));
    fn_881E1D70((ts4_word)(a0 + 8));
    fn_881E1D70((ts4_word)(a0 + 4));
    return;
}

/* Swing_DLL.xex 0x88202438: call_seq u32@0x2c, ts4_str_release_fn */
void ts4_call_seq_u32_off2c_88202438(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    ts4_str_release((ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88202BF8: loop_call_seq u32@0x10, u32@0x14, ts4_if_get_u32_lbl_88D3E418_882016F8, u32@0x10, u32@0x14, u32@0x10 */
void ts4_loop_call_seq_u32_off10_88202BF8(ts4_word a0, ts4_word a1)
{
    ts4_word lv9;
    ts4_word p16;
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t13;
    ts4_word t21;

    ts4_if_get_u32_lbl_88D3E418_882016F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 20)) + 8));
    t4 = loc50[3];
    if ((ts4_word)a1 == (ts4_word)t4) {
        fn_88202900((ts4_word)a0);
    } else {
        lv9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 20));
        while ((ts4_word)lv9 != 0) {
            t13 = *(ts4_word *)((char *)(ts4_word)(lv9) + 20);
            if ((ts4_word)a1 == (ts4_word)t13) {
                *(unsigned char *)((char *)(ts4_word)(lv9) + 13) = (unsigned char)1;
                break;
            }
            p16 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv9) + 0));
            lv9 = p16;
        }
    }
    t21 = loc50[0];
    ts4_str_release((ts4_word)t21);
    return;
}

/* Swing_DLL.xex 0x88204898: call_seq u32@0x34, ts4_str_release_fn, u32@0x0, u32@0x0, u32@0x1c, u32@0x0 */
void ts4_call_seq_u32_off34_88204898(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 52);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(t4 + -1);
    return;
}

/* Swing_DLL.xex 0x88204930: call_seq u32@0x8, ts4_str_release_fn, u32@0x0, u32@0x0, u32@0x1c, u32@0x0 */
void ts4_call_seq_u32_off8_88204930(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(t4 + -1);
    return;
}

/* Swing_DLL.xex 0x88206CA0: if_call_seq u32@0xc, lbl_880E9CC0, u32@0x0, fn_881992A8, u32@0x8, u32@0xc */
void ts4_if_call_seq_u32_offc_88206CA0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9CC0;
    if ((ts4_word)t1 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    ts4_str_release((ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x882099C8: if_call_seq lbl_880E9E8C, u32@0x0, u32@0x14, ts4_if_atomic_interlocked_dec_881876D0, u32@0x14, u32@0x10 */
void ts4_if_call_seq_lbl_880E9E8C_882099C8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9E8C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    ts4_str_release((ts4_word)t4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x8820D100: call_seq u32@0x58, lbl_880EA028, u32@0x0, ts4_str_release_fn, u32@0x50, ts4_str_release_fn */
void ts4_call_seq_u32_off58_8820D100(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA028;
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    ts4_str_release((ts4_word)t3);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ts4_str_release((ts4_word)t5);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ts4_str_release((ts4_word)t7);
    ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x8820F5B8: if_call_seq u32@lbl_88D41FC4, ts4_get_u32_off0_88197750, fn_8818EB10, fn_881EB370, ts4_str_release_fn, ts4_counted_ptr_assign_881C38D0 */
void ts4_if_call_seq_u32_lbl_88D41FC4_8820F5B8(ts4_word a0, ts4_word a1)
{
    ts4_word loc54[1];
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;

    (void)a0;
    t1 = *(ts4_word *)lbl_88D41FC4;
    t2 = ts4_get_u32_off0_88197750((ts4_word)(ts4_word)&loc54[0], (ts4_word)(t1 + 20));
    t3 = fn_8818EB10((ts4_word)(ts4_word)&loc58[0], (ts4_word)t2);
    fn_881EB370((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)t3);
    t5 = loc54[0];
    ts4_str_release((ts4_word)t5);
    ts4_counted_ptr_assign_881C38D0((ts4_word)(a1 + 52), (ts4_word)(ts4_word)&loc50[0]);
    t8 = loc50[0];
    if ((ts4_word)t8 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x8820FBF8: if_call_seq u32@lbl_88D41FC4, ts4_get_u32_off0_88197750, fn_8818EB10, fn_881EB370, ts4_str_release_fn, ts4_counted_ptr_assign_881C38D0 */
void ts4_if_call_seq_u32_lbl_88D41FC4_8820FBF8(ts4_word a0, ts4_word a1)
{
    ts4_word loc54[1];
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;

    (void)a0;
    t1 = *(ts4_word *)lbl_88D41FC4;
    t2 = ts4_get_u32_off0_88197750((ts4_word)(ts4_word)&loc54[0], (ts4_word)(t1 + 20));
    t3 = fn_8818EB10((ts4_word)(ts4_word)&loc58[0], (ts4_word)t2);
    fn_881EB370((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)t3);
    t5 = loc54[0];
    ts4_str_release((ts4_word)t5);
    ts4_counted_ptr_assign_881C38D0((ts4_word)(a1 + 68), (ts4_word)(ts4_word)&loc50[0]);
    t8 = loc50[0];
    if ((ts4_word)t8 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x88210D70: call_seq fn_881E1D70, u32@0x34, ts4_str_release_fn, u32@0x30, ts4_str_release_fn, u32@0x8 */
void ts4_call_seq_fn_881E1D70_88210D70(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;

    fn_881E1D70((ts4_word)(a0 + 64));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ts4_str_release((ts4_word)t2);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ts4_str_release((ts4_word)t4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ts4_str_release((ts4_word)t6);
    return;
}

/* Swing_DLL.xex 0x88219840: loop_call_seq u32@0x4, ts4_str_release_fn */
void ts4_loop_call_seq_u32_off4_88219840(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p4;
    ts4_word t2;

    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 4);
        ts4_str_release((ts4_word)t2);
        p4 = (ts4_word)(lv1 + 8);
        lv1 = p4;
    }
    return;
}

/* Swing_DLL.xex 0x88593BB0: if_atomic interlocked_dec, lbl_88D2F130, RtlEnterCriticalSection, fn_885938B0, RtlLeaveCriticalSection */
void ts4_if_atomic_interlocked_dec_88593BB0(ts4_word a0)
{
    ts4_word t1;

    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 12)));
    if ((ts4_word)t1 == 0) {
        RtlEnterCriticalSection((ts4_word)((ts4_word)lbl_88D2F130 + 84));
        fn_885938B0((ts4_word)a0, (ts4_word)0);
        RtlLeaveCriticalSection((ts4_word)((ts4_word)lbl_88D2F130 + 84));
    }
    return;
}

/* Swing_DLL.xex 0x8863AF38: call_seq u32@0xc, lbl_880F62E4, u32@0x0, ts4_str_release_fn, u32@0x8, ts4_str_release_fn */
void ts4_call_seq_u32_offc_8863AF38(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F62E4;
    ts4_str_release((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ts4_str_release((ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x8879C3F0: if_get fn_88627EC0, ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, ts4_assign_text_from_c_string */
void ts4_if_get_fn_88627EC0_8879C3F0(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc58[2];
    ts4_word loc60[4];
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;
    ts4_word t13;
    ts4_word t16;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc58[0] = (ts4_word)((2521104384) | 13620);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc58[0]);
    t4 = loc60[0];
    t5 = loc60[1];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 80))))((ts4_word)t4, (ts4_word)(ts4_word)&loc60[0], (ts4_word)t5, (ts4_word)1);
    ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc54[0], (ts4_word)t8);
    t11 = fn_881E9010((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)(ts4_word)&loc54[0]);
    ts4_counted_ptr_assign_881C38D0((ts4_word)(a0 + 28), (ts4_word)t11);
    t13 = loc50[0];
    if ((ts4_word)t13 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t13);
        loc50[0] = (ts4_word)0;
    }
    t16 = loc54[0];
    ts4_str_release((ts4_word)t16);
    return;
}

/* Swing_DLL.xex 0x8879ED98: if_get u32@0x10, u32@0x384, u32@g_ts4_default_script_value, u32@0x380, fn_8818EB10, interlocked_dec */
ts4_word ts4_if_get_u32_off10_8879ED98(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    fn_8818EB10((ts4_word)(ts4_word)&loc50[0], (ts4_word)(p5 + 16));
    t7 = loc50[0];
    ts4_str_release((t7));
    return 0;
}

/* Swing_DLL.xex 0x8886ECE8: call_seq ts4_memset, ts4_memset, ts4_memset, ts4_memset, ts4_memset, ts4_call_seq_ts4_copy_bytes_88864B98 */
void ts4_call_seq_ts4_memset_8886ECE8(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word loc78[3];
    ts4_word loc98[3];
    ts4_word loc88[3];
    ts4_word loc50[2];
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t14;

    ts4_memset((ts4_word)(ts4_word)&loc58[0], (ts4_word)0, (ts4_word)10);
    ts4_memset((ts4_word)(ts4_word)&loc68[0], (ts4_word)0, (ts4_word)10);
    ts4_memset((ts4_word)(ts4_word)&loc78[0], (ts4_word)0, (ts4_word)10);
    ts4_memset((ts4_word)(ts4_word)&loc98[0], (ts4_word)0, (ts4_word)10);
    ts4_memset((ts4_word)(ts4_word)&loc88[0], (ts4_word)0, (ts4_word)10);
    ts4_call_seq_ts4_copy_bytes_88864B98((ts4_word)a0, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc98[0], (ts4_word)(ts4_word)&loc88[0]);
    t7 = ts4_tailcall_fn_88564B00_88564770((ts4_word)(ts4_word)&loc58[0]);
    t8 = ts4_tailcall_fn_88564B00_88564770((ts4_word)(ts4_word)&loc68[0]);
    t9 = ts4_tailcall_fn_88564B00_88564770((ts4_word)(ts4_word)&loc78[0]);
    t11 = fn_887A3F38((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D45A60), (ts4_word)t9, (ts4_word)t8, (ts4_word)t7, (ts4_word)0);
    fn_881AAF10((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 0)));
    t14 = loc50[0];
    ts4_str_release((ts4_word)t14);
    return;
}

/* Swing_DLL.xex 0x88905A10: call_seq lbl_880D90A4, ts4_assign_text_from_c_string, u32@lbl_88D41FC4, u32@0x6c, fn_88201BA0, ts4_str_release_fn */
ts4_word ts4_call_seq_lbl_880D90A4_88905A10(void)
{
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t5;

    ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D90A4);
    t4 = fn_88201BA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 108)), (ts4_word)(ts4_word)&loc50[0]);
    t5 = loc50[0];
    ts4_str_release((ts4_word)t5);
    return t4;
}
