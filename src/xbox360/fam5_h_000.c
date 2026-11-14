/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, a named pointer
   for a repeated base+offset, ||/&& conditions kept in a bool temporary,
   ...).  In .cpp files a function whose first argument is `this` is a member
   of a one-function struct ts4_obj_<ADDR>: MSVC orders the operands of
   commutative instructions differently for `this` than for a plain argument.
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
#include "fam4_refstr.h"

extern char lbl_8803A308[];
extern char lbl_880DCE3C[];
extern char lbl_880DD088[];
extern char lbl_88C6B4AC[];
extern char lbl_88D45B38[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_88179740();
ts4_word fn_88198CE0();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word fn_881C2390();
ts4_word fn_881C23E8();
ts4_word fn_881C6998();
ts4_word fn_881E1D70();
ts4_word fn_8841C678();
ts4_word fn_884214A8();
ts4_word fn_88423660();
ts4_word fn_88423730();
ts4_word fn_88423858();
ts4_word ts4_if_get_u16_off4_88475AE8();
ts4_word fn_88606788();
ts4_word fn_8860D460();
ts4_word fn_8866F028();
ts4_word ts4_if_call_seq_ts4_tailcall_MmFreePhysicalMemory_8857B158_88884200();
ts4_word fn_8890F1E8();
ts4_word fn_88911668();
ts4_word fn_88936BB0();
ts4_word fn_88939040();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word ts4_call_seq_fn_881B19A0_881C6008();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();
ts4_word ts4_memset();
ts4_word ts4_string_unshare_8819B308();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8818E928: loop_get u32@0x14, RtlEnterCriticalSection, u32@0x4, fn_88198CE0, u32@0x40, u32@0x0 */
void ts4_loop_get_u32_off14_8818E928(ts4_word a0)
{
    ts4_word q80;
    ts4_word p3;
    ts4_word lv8;
    ts4_word p13;
    int t1;
    ts4_word t6;

    q80 = a0 + 24;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p3 = (ts4_word)0;
    if ((int)t1 == -1) {
        RtlEnterCriticalSection((ts4_word)((q80) + 8));
        p3 = (ts4_word)1;
    }
    t6 = fn_88198CE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    lv8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    while ((ts4_word)lv8 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv8) + 0))) + 52))))((ts4_word)lv8);
        p13 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv8) + 148));
        lv8 = p13;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    fn_88198CE0((ts4_word)t6);
    if ((int)p3 != 0 && (int)t1 == -1) {
        RtlLeaveCriticalSection((ts4_word)((q80) + 8));
    }
    return;
}

/* Swing_DLL.xex 0x881BDDB0: if_call_seq u32@0x6ec, ts4_str_release_fn, u32@0x6cc, u32@0x6c8, ts4_call_seq_fn_881B19A0_881C6008, u32@0x680 */
void ts4_if_call_seq_u32_off6ec_881BDDB0(ts4_word a0)
{
    ts4_word q82;
    ts4_word q81;
    ts4_word q80;
    ts4_word t1;
    ts4_word t4;
    ts4_word t8;
    ts4_word t12;
    ts4_word t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1772);
    ts4_str_release((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1740) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1736) = (ts4_word)0;
    q80 = a0 + 768;
    ts4_call_seq_fn_881B19A0_881C6008((ts4_word)((q80) + 912));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 1664);
    if ((ts4_word)t4 != 0) {
        fn_881C2390((ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((q80)) + 900)));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 748);
    if ((ts4_word)t8 != 0) {
        fn_881C23E8((ts4_word)t8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 752)));
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t12 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    }
    q81 = a0 + 16;
    fn_881E1D70((ts4_word)(q81));
    q82 = a0 + 12;
    fn_881E1D70((ts4_word)(q82));
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ts4_str_release((ts4_word)t17);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return;
}

/* Swing_DLL.xex 0x881C63E0: if_call_seq u32@0x380, u32@0x384, fn_881C2390, u32@0x380, u32@0x384, u32@0x388 */
void ts4_if_call_seq_u32_off380_881C63E0(ts4_word a0)
{
    ts4_word q80;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 896);
    if ((ts4_word)t1 != 0) {
        fn_881C2390((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 900)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 896) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 900) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 904) = (ts4_word)0;
    fn_881C6998((ts4_word)a0, (ts4_word)16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 912) = (ts4_word)0;
    q80 = a0 + 912;
    ts4_string_unshare_8819B308((ts4_word)((q80) + 16));
    fn_881B19A0((ts4_word)((q80) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 960) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88428628: if_call_seq fn_88423730, u32@0x10, fn_88423660, u32@0x8, u32@0x0 */
void ts4_if_call_seq_fn_88423730_88428628(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q80;
    int t1;
    int t2;
    ts4_word t4;

    q80 = a0 + 8;
    t1 = fn_88423730((ts4_word)(q80), (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 <= (int)t2) {
        t4 = *(ts4_word *)((char *)(ts4_word)((q80)) + 8);
        *(ts4_word *)((char *)(ts4_word)((((t4 + t1) + 1) << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_word)a2;
        return;
    }
    fn_88423660((ts4_word)(q80), (ts4_word)a1, (ts4_word)a2);
    return;
}

/* Swing_DLL.xex 0x88428C10: if_call_seq fn_884214A8, u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x0 */
void ts4_if_call_seq_fn_884214A8_88428C10(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word t1;
    ts4_word t2;
    int t3;
    ts4_word t6;

    t1 = fn_884214A8((ts4_word)a1);
    q80 = a0 + 12;
    t2 = *(ts4_word *)((char *)(ts4_word)((q80)) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    if ((int)t3 == (int)(t2 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)4);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    *(ts4_word *)((char *)(ts4_word)((t6 << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 1);
    return;
}

/* Swing_DLL.xex 0x8847ADD0: if_call_seq u32@0x30, ts4_if_get_u16_off4_88475AE8, u32@0x8, u32@0x4, fn_8841C678, u32@0x4 */
void ts4_if_call_seq_u32_off30_8847ADD0(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    int t1;
    ts4_word t2;
    ts4_word t6;
    int t7;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t1 < 2) {
        t2 = *(ts4_word *)((char *)(ts4_word)(((t1 + 5) << 2)) + a0);
        if ((ts4_word)t2 == 0) {
            *(ts4_word *)((char *)(ts4_word)(((t1 + 5) << 2)) + a0) = (ts4_word)a1;
            ts4_if_get_u16_off4_88475AE8((ts4_word)a1);
        }
    }
    q80 = a0 + 44;
    t6 = *(ts4_word *)((char *)(ts4_word)((q80)) + 8);
    t7 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    if ((int)t7 == (int)(t6 & 0x3fffffff)) {
        fn_8841C678((ts4_word)(q80), (ts4_word)4);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    *(ts4_word *)((char *)(ts4_word)((t10 << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 1);
    ts4_if_get_u16_off4_88475AE8((ts4_word)a1);
    return;
}

/* Swing_DLL.xex 0x884CA108: if_get fn_88423730, u32@0x8, u32@0x0, u32@0x8, vcall, fn_88423858 */
void ts4_if_get_fn_88423730_884CA108(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    q80 = a0 + 16;
    t1 = fn_88423730((ts4_word)(q80), (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)((q80)) + 8);
    t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((((t2 + t1) + 1) << 2)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))))) + 8);
    if ((ts4_word)t5 != 0) {
        ((ts4_word (*)(ts4_word))(t5))((ts4_word)a1);
    }
    fn_88423858((ts4_word)(q80), (ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x8860D030: call_seq RtlEnterCriticalSection, u32@0x178, u32@0x24, u32@0x2c, u32@0x17c, u32@0x168 */
void ts4_call_seq_RtlEnterCriticalSection_8860D030(ts4_word a0)
{
    ts4_word q80;
    ts4_word t2;
    ts4_word t3;

    q80 = a0 + 68;
    RtlEnterCriticalSection((ts4_word)((q80) + 4));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)(t3 + t2);
    RtlLeaveCriticalSection((ts4_word)((q80) + 4));
    return;
}

/* Swing_DLL.xex 0x8860D8E8: loop_call_seq RtlEnterCriticalSection, u32@0x180, u32@0x184, u32@0x0, u32@0x0, u32@0xc */
void ts4_loop_call_seq_RtlEnterCriticalSection_8860D8E8(ts4_word a0)
{
    ts4_word q80;
    ts4_word lv5;
    ts4_word p7;
    ts4_word lv10;
    ts4_word p12;
    ts4_word t2;
    ts4_word t3;

    q80 = a0 + 68;
    RtlEnterCriticalSection((ts4_word)((q80) + 4));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 384);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 388);
    lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
    while ((ts4_word)t3 != (ts4_word)lv5) {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0));
        lv5 = p7;
    }
    lv10 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 12));
    while ((ts4_word)t3 != (ts4_word)lv10) {
        p12 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv10) + 12));
        lv10 = p12;
    }
    RtlLeaveCriticalSection((ts4_word)((q80) + 4));
    return;
}

/* Swing_DLL.xex 0x8860DA28: loop_call_seq fn_88606788, RtlEnterCriticalSection, u32@0x190, u32@0x0, RtlLeaveCriticalSection */
void ts4_loop_call_seq_fn_88606788_8860DA28(ts4_word a0)
{
    ts4_word q80;
    ts4_word lv4;
    ts4_word p6;

    fn_88606788((ts4_word)a0);
    q80 = a0 + 68;
    RtlEnterCriticalSection((ts4_word)((q80) + 4));
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 400));
    while ((ts4_word)lv4 != 0) {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 0));
        lv4 = p6;
    }
    RtlLeaveCriticalSection((ts4_word)((q80) + 4));
    return;
}

/* Swing_DLL.xex 0x88612CA0: loop_call_seq RtlEnterCriticalSection, u32@0x180, u32@0x8, RtlLeaveCriticalSection */
void ts4_loop_call_seq_RtlEnterCriticalSection_88612CA0(ts4_word a0)
{
    ts4_word q81;
    ts4_word q80;
    ts4_word lv3;
    ts4_word p5;

    q80 = a0 + 68;
    RtlEnterCriticalSection((ts4_word)((q80) + 4));
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 384));
    q81 = a0 + 376;
    while ((ts4_word)(q81) != (ts4_word)lv3) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 8));
        lv3 = p5;
    }
    RtlLeaveCriticalSection((ts4_word)((q80) + 4));
    return;
}

/* Swing_DLL.xex 0x88618718: if_call_seq RtlEnterCriticalSection, u8@0xe5, u32@0xe8, u32@0x178, u32@0xe8, u32@0x178 */
void ts4_if_call_seq_RtlEnterCriticalSection_88618718(ts4_word a0)
{
    ts4_word q80;
    unsigned char t2;
    int t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    q80 = a0 + 68;
    RtlEnterCriticalSection((ts4_word)((q80) + 4));
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 229);
    if ((ts4_word)t2 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
        if ((int)t5 != 0) {
            ts4_tsu_cleanup_end((ts4_word)t6);
        } else {
            ts4_memset((ts4_word)t6, (ts4_word)-3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
            if ((ts4_word)t9 != 0) {
                t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 388);
                ts4_if_call_seq_ts4_tailcall_MmFreePhysicalMemory_8857B158_88884200((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)t10);
            }
        }
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    RtlLeaveCriticalSection((ts4_word)((q80) + 4));
    return;
}

/* Swing_DLL.xex 0x886195A0: if_call_seq u8@0x68, u32@0x20, u32@lbl_88D45B38, fn_8860D460, RtlEnterCriticalSection, u32@0x40 */
void ts4_if_call_seq_u8_off68_886195A0(ts4_word a0)
{
    ts4_word q83;
    ts4_word q82;
    ts4_word q81;
    ts4_word q80;
    ts4_word loc50[4];
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
        fn_8860D460((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)(ts4_word)&loc50[0]);
    }
    q80 = a0 + 68;
    RtlEnterCriticalSection((ts4_word)((q80) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    RtlLeaveCriticalSection((ts4_word)((q80) + 4));
    q81 = a0 + 108;
    ts4_memset((ts4_word)(q81), (ts4_word)0, (ts4_word)120);
    q82 = a0 + 236;
    ts4_memset((ts4_word)(q82), (ts4_word)0, (ts4_word)120);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    q83 = a0 + 16;
    fn_881B9148((ts4_word)(q83));
    return;
}

/* Swing_DLL.xex 0x88645570: set u32@0x8, u32@0x6c, u32@0x4, u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off8_88645570(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 108);
    q80 = a1 + 108;
    *(ts4_word *)((char *)(ts4_word)(((q80) + t1)) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(((q80) + t1)) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(((q80) + t1)) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return;
}

/* Swing_DLL.xex 0x886A1250: if_call_seq fn_8890F1E8, fn_8890F1E8, fn_8890F1E8, u32@0x10, ts4_destroy_owned_object */
void ts4_if_call_seq_fn_8890F1E8_886A1250(ts4_word a0)
{
    ts4_word q81;
    ts4_word q80;
    ts4_word t4;

    q80 = a0 + 260;
    fn_8890F1E8((ts4_word)(q80));
    q81 = a0 + 28;
    fn_8890F1E8((ts4_word)((q81) + 68));
    fn_8890F1E8((ts4_word)(q81));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    return;
}

/* Swing_DLL.xex 0x886B62E0: call_seq u32@0x4c, u32@0x74, u32@0x4, u32@0x44, fn_8866F028, fn_88911668 */
void ts4_call_seq_u32_off4c_886B62E0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 116)) + 2176);
    loc50[0] = (ts4_word)((918355968) | 58878);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
    fn_88911668((ts4_word)(a0 + 8), (ts4_word)(a1 + 816), (ts4_word)(fn_8866F028((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0])), (ts4_word)(t2 + 140), (ts4_word)(t2 + 212));
    return;
}

/* Swing_DLL.xex 0x88890718: if_get u32@0x8, lbl_880DCE3C, u32@0x0, u8@0xc, u32@0x0, u32@0x4 */
void ts4_if_get_u32_off8_88890718(ts4_word a0)
{
    ts4_word q80;
    int t1;
    ts4_word t4;

    q80 = a0 + 8;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCE3C;
    if ((int)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 12)) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 88))))((ts4_word)t4, (ts4_word)(q80));
    }
    *(ts4_word *)((char *)(ts4_word)((q80)) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x8890DFC8: loop_call_seq u32@0x4, u32@0x1c, u32@0x4, u32@0x4, u32@0x0, fn_88179740 */
void ts4_loop_call_seq_u32_off4_8890DFC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word q80;
    ts4_word p2;
    ts4_word p5;
    ts4_word lv7;
    ts4_word p12;
    int t1;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    q80 = a1 + 28;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 28);
    p2 = (ts4_word)0;
    if ((int)t1 != -1) {
        p2 = (ts4_word)(t1 + (q80));
    }
    p5 = (ts4_word)0;
    if ((int)t1 != -1) {
        p5 = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) << 3) + t1) + (q80));
    }
    lv7 = (ts4_word)p2;
    while ((ts4_word)lv7 != (ts4_word)p5) {
        t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 4);
        if ((ts4_word)t8 == (ts4_word)((2570584064) | 38086)) {
            fn_88179740((ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv7) + 0)) + lv7));
        }
        p12 = (ts4_word)(lv7 + 8);
        lv7 = p12;
    }
    return;
}

/* Swing_DLL.xex 0x889194C0: call_seq fn_88939470, fn_889395D8, fn_889395D8, fn_88939470, fn_88936BB0 */
void ts4_call_seq_fn_88939470_889194C0(ts4_word a0, ts4_word a1)
{

    fn_88936BB0((ts4_word)(fn_88939470((ts4_word)(fn_889395D8((ts4_word)(fn_889395D8((ts4_word)(fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3)), (ts4_word)(a0 + 1072))), (ts4_word)(a0 + 1076))), (ts4_word)(a0 + 1080), (ts4_word)3)), (ts4_word)(a0 + 1084));
    return;
}

/* Swing_DLL.xex 0x8891F5C8: call_seq fn_88939470, fn_889395D8, fn_889395D8, fn_889395D8, fn_889395D8 */
void ts4_call_seq_fn_88939470_8891F5C8(ts4_word a0, ts4_word a1)
{

    fn_889395D8((ts4_word)(fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3)), (ts4_word)(a0 + 1072));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1080));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1084));
    return;
}

/* Swing_DLL.xex 0x8893BD10: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
void ts4_get_u32_off0_8893BD10(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 1076);
    fn_88939040((ts4_word)(ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)(ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)))), (ts4_word)t8)), (ts4_word)(a0 + 1080), (ts4_word)256);
    return;
}
