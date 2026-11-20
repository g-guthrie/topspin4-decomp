#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x88608540-0x88939A38, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
#include "ts4_vector.h"
extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif

extern char g_ts4_script_constants[];
extern char lbl_880C84C0[];
extern char lbl_880C8B18[];
extern char lbl_880DB5A8[];
extern char lbl_8814B910[];
extern char lbl_88C4770C[];
extern char lbl_88C6B4B0[];
extern char lbl_88C6B6C0[];
extern char lbl_88C6B728[];
extern char lbl_88C6B760[];
extern char lbl_88C6B7C0[];
extern char lbl_88D3EB60[];
extern char lbl_88D45A60[];
extern char lbl_88D45A8C[];
extern char lbl_88D45A90[];
extern char lbl_88D45A94[];
extern char lbl_88D45B1C[];
ts4_word fn_88161540();
ts4_word fn_8817EA90();
ts4_word fn_88565258();
ts4_word fn_88617D88();
ts4_word ts4_loop_get_u32_off84_88637170();
ts4_word fn_886379E0();
ts4_word fn_887573E0();
ts4_word fn_88824CF8();
ts4_word fn_8882E368();
ts4_word fn_888CEAA8();
ts4_word fn_888CF650();
ts4_word fn_888D8368();
ts4_word fn_8892D5F8();
ts4_word fn_88938F38();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word ts4_if_get_u8_off420_88934FB8();
ts4_word ts4_loop_get_u32_off0_8891B7A0();
ts4_word ts4_memset();
ts4_word ts4_span28_append();
ts4_word ts4_tailcall_NetDll_XNetGetTitleXnAddr_884F0000();
ts4_word ts4_tailcall_NetDll_XNetInAddrToString_884EFF00();

/* Swing_DLL.xex 0x8860CDD8: call_seq fn_88565258, u32@0x17c, u32@0x184, u32@0x180, ts4_memset */
static ts4_word ts4_call_seq_ts4_crt_nh_malloc_88565258_8860CDD8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88565258((ts4_word)((2752512) | 47488));
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)((0) | 50000);
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    t2 = ts4_memset((ts4_word)t1, (ts4_word)0, (ts4_word)((2752512) | 47488));
    return t2;
}

/* Swing_DLL.xex 0x886378F0: if_get u32@0x84, u32@0x4, vcall, ts4_loop_get_u32_off84_88637170, u8@0x110, u32@0x0 */
ts4_word ts4_if_get_u32_off84_886378F0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    p6 = (ts4_word)0;
    t4 = ts4_loop_get_u32_off84_88637170((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t4 != 0) {
        p6 = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t4) + 272));
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return p6;
}

/* Swing_DLL.xex 0x88638770: if_get u32@0x84, u32@0x4, vcall, fn_886379E0, u32@0xc, u32@0x0 */
ts4_word ts4_if_get_u32_off84_88638770(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    p6 = (ts4_word)0;
    t4 = fn_886379E0((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    if ((ts4_word)t4 != 0) {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 12));
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return p6;
}

/* Swing_DLL.xex 0x88779BB0: if_get u32@0x0, u32@-0xc, u32@0x0, u16@-0x2, lbl_88C4770C, u32@0x0 */
static void ts4_if_get_u32_off0_88779BB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + -12);
    if ((int)t2 >= 1) {
        t3 = *(unsigned short *)((char *)(ts4_word)(((t2 << 1) + t1)) + -2);
        if ((int)(t3 + -48) >= 0 && (int)(t3 + -48) <= 9) {
            t5 = *(ts4_word *)((char *)(ts4_word)(((t3 + -48) << 2)) + (ts4_word)lbl_88C4770C);
            if ((int)t2 != 1 && (int)((*(unsigned short *)((char *)(ts4_word)(((t2 + -2) << 1)) + t1)) + -48) == 1) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1877475328) | 12985);
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1628962816) | 21754);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1628962816) | 21754);
    return;
}

/* Swing_DLL.xex 0x8882ED00: loop_call_seq u8@0x0, fn_88824CF8, fn_8882E368 */
static ts4_word lib3_lua_dostring_8882ED00(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p3;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    lv1 = (ts4_word)a1;
    do {
        t2 = *(unsigned char *)((char *)(ts4_word)(lv1) + 0);
        p3 = (ts4_word)(lv1 + 1);
        lv1 = p3;
    } while ((ts4_word)t2 != 0);
    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)((lv1 - a1) + -1);
    t4 = fn_88824CF8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t5 = fn_8882E368((ts4_word)a0, (ts4_word)t4);
    return t5;
}

/* Swing_DLL.xex 0x888CAFE8: call_seq fn_88617D88, lbl_880DB5A8, u32@0x20, u32@0x1c, u32@0x0, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888CAFE8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB5A8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)((983040) | 65535);
    return a0;
}

/* Swing_DLL.xex 0x888CFBC8: call_seq fn_888CF650 */
static ts4_word ts4_call_seq_fn_888CF650_888CFBC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[6];
    ts4_word t1;

    (void)a1;
    (void)a2;
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)-1;
    loc50[2] = (ts4_word)0;
    *(unsigned char *)((char *)loc50 + 12) = (unsigned char)0;
    *(unsigned char *)((char *)loc50 + 13) = (unsigned char)0;
    *(unsigned char *)((char *)loc50 + 14) = (unsigned char)0;
    *(unsigned char *)((char *)loc50 + 15) = (unsigned char)0;
    t1 = fn_888CF650((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)-1);
    return t1;
}

