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

extern char lbl_880B97F0[];
extern char lbl_880BD390[];
extern char lbl_88C42CC8[];
extern char lbl_88C6A10C[];
extern char lbl_88C6E210[];
extern char lbl_88D459EC[];
ts4_word fn_88292F80();
ts4_word fn_882C1F28();
ts4_word fn_882C3030();
ts4_word fn_882C3760();
ts4_word fn_885DBA80();
ts4_word fn_885DCE58();
ts4_word fn_885E5BC8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_call_seq_u32_off814_885E1990();
ts4_word ts4_read_indexed_u32_property_885DCDA8();

/* Swing_DLL.xex 0x8828CAD0: get u32@0x292c, u32@0x292c, u64@0x10, u64@0x10 */
void ts4_get_u32_off292c_8828CAD0(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 10540) = (ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 10540)) & 0xfff0ffff) | (a1 << 16));
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)((*(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 16)) | 8192);
    return;
}

/* Swing_DLL.xex 0x8828CC00: get u32@0x2930, u32@0x2930, u64@0x10, u64@0x10 */
void ts4_get_u32_off2930_8828CC00(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 10544) = (ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 10544)) & 0xfff0ffff) | (a1 << 16));
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)((*(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 16)) | 4096);
    return;
}

/* Swing_DLL.xex 0x88293440: if_call_seq fn_88292F80, memcpy, u32@0x3554, u32@0x30 */
ts4_word ts4_if_call_seq_fn_88292F80_88293440(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88292F80((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4);
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = memcpy((ts4_word)t1, (ts4_word)a3, (ts4_word)((int)a2 * (int)a4));
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13652));
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Swing_DLL.xex 0x882C38F0: if_call_seq u32@lbl_88C6E210, fn_882C1F28, fn_882C3030, fn_882C3760 */
ts4_word ts4_if_call_seq_u32_lbl_88C6E210_882C38F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word p6;
    int t1;
    ts4_word t5;
    int t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88C6E210;
    if ((int)t1 != 0) {
        t5 = fn_882C3760((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p6 = (ts4_word)t5;
    } else {
        t2 = fn_882C1F28((ts4_word)(a0 + 8), (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
        p4 = (ts4_word)t2;
        if ((int)t2 >= 0) {
            t3 = fn_882C3030((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
            p4 = (ts4_word)t3;
        }
        p6 = (ts4_word)p4;
    }
    return p6;
}

/* Swing_DLL.xex 0x885DB690: call_seq u32@0x8, fn_885DBA80, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_u32_off8_885DB690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;

    loc54[0] = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    fn_885DBA80((ts4_word)t1, (ts4_word)a1, (ts4_word)60, (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)256;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)1;
    return 0;
}

/* Swing_DLL.xex 0x885DD9C0: if_addr ts4_read_indexed_u32_property_885DCDA8, fn_885DCE58, lbl_88C42CC8, lbl_880B97F0, u32@0x38, vcall */
ts4_word ts4_if_addr_ts4_read_indexed_u32_property_885DCDA8_885DD9C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word t1;

    t1 = ts4_read_indexed_u32_property_885DCDA8((ts4_word)a0, (ts4_word)27, (ts4_word)a1);
    if ((ts4_word)t1 == 1) {
        if ((ts4_word)a2 != 0) {
            fn_885DCE58((ts4_word)a2, (ts4_word)8, (ts4_word)a1, (ts4_word)1);
        }
        if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B97F0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 56)), (ts4_word)14, (ts4_word)a1, (ts4_word)1);
        }
        p12 = (ts4_word)1;
    } else {
        if ((ts4_word)a2 != 0) {
            fn_885DCE58((ts4_word)a2, (ts4_word)8, (ts4_word)a1, (ts4_word)0);
        }
        if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B97F0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 56)), (ts4_word)14, (ts4_word)a1, (ts4_word)0);
        }
        p12 = (ts4_word)0;
    }
    return p12;
}

/* Swing_DLL.xex 0x885E5DA0: call_seq fn_885E5BC8, lbl_880BD390, u32@0x10, u32@0x0, u32@0xe4, u32@0xe4 */
ts4_word ts4_call_seq_fn_885E5BC8_885E5DA0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_885E5BC8((ts4_word)a0, (ts4_word)48, (ts4_word)a1);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880BD390;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 228) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 228)) | 18);
    ts4_call_seq_u32_off814_885E1990((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 2736)), (ts4_word)t1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)48;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888134F0: get u32@lbl_88C6A10C, u32@lbl_88D459EC, u32@0x0, u32@0x0 */
void ts4_get_u32_lbl_88C6A10C_888134F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)lbl_88C6A10C;
    t2 = *(volatile ts4_word *)lbl_88D459EC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    return;
}
