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

ts4_word fn_882C7B38();
ts4_word fn_8832EDB0();
ts4_word fn_883E2E20();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word ts4_fn_883E63B8();
ts4_word ts4_if_get_u32_off0_882CDB18();

/* Swing_DLL.xex 0x882C8400: if_get fn_882C7B38, u32@0x10, u32@0x0, u32@0x8, vcall, u32@0x14 */
ts4_word ts4_if_get_fn_882C7B38_882C8400(ts4_word a0)
{
    ts4_word t10;

    fn_882C7B38((ts4_word)a0);
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)) != 0) {
        ((ts4_word (*)(void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))))) + 0))) + 8))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)))));
    }
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)) != 0) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(612433920));
    }
    t10 = ts4_if_get_u32_off0_882CDB18((ts4_word)a0);
    return t10;
}

/* Swing_DLL.xex 0x883D0740: if_get fn_8832EDB0, u32@0x114, u32@0x0, u32@0x4, vcall, fn_8832EDB0 */
ts4_word ts4_if_get_fn_8832EDB0_883D0740(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)8, (ts4_word)284);
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 276)) != 0) {
        t5 = ((ts4_word (*)(void *, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 276))))) + 0))) + 4))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 276)))), (ts4_word)a1);
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)8, (ts4_word)t5);
    }
    return 0;
}

/* Swing_DLL.xex 0x883E8340: if_get u32@0x24, ts4_fn_883E63B8, u32@0x0, u32@0x8, vcall, ts4_fn_883E63B8 */
ts4_word ts4_if_get_u32_off24_883E8340(ts4_word a0)
{
    ts4_word p7;
    ts4_word p8;
    int t5;
    ts4_word t6;
    ts4_word t2;

    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)) != 0) {
        t5 = ((ts4_word (*)(void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))))) + 0))) + 8))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)))));
        p7 = (ts4_word)t5;
        if ((int)t5 == 0) {
            t6 = ts4_fn_883E63B8((ts4_word)a0);
            p7 = (ts4_word)t6;
        }
        p8 = (ts4_word)p7;
    } else {
        t2 = ts4_fn_883E63B8((ts4_word)a0);
        p8 = (ts4_word)t2;
    }
    return p8;
}

/* Swing_DLL.xex 0x883E8E08: if_get fn_8832EDB0, u32@0x10, u32@0x14, fn_8832EDB0, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_fn_8832EDB0_883E8E08(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word p12;
    int t9;

    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)36);
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)) != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)) * 12));
    }
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)) != 0) {
        t9 = ((ts4_word (*)(void *, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))))) + 0))) + 4))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 24)))), (ts4_word)a1);
        p11 = (ts4_word)t9;
        if ((int)t9 == 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)24);
            p11 = (ts4_word)0;
        }
        p12 = (ts4_word)p11;
    } else {
        p12 = (ts4_word)0;
    }
    return p12;
}

/* Swing_DLL.xex 0x883F2898: if_call_seq fn_883E2E20, u32@0x18, u32@0x20, u32@0x20 */
ts4_word ts4_if_call_seq_fn_883E2E20_883F2898(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_883E2E20((ts4_word)a1);
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)) != 0) {
        *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) & 0xffffffff)) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) & 0xffffffff)) + 32)) + 1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883F28E8: if_get u32@0x18, u32@0x20, u32@0x20 */
ts4_word ts4_if_get_u32_off18_883F28E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a0;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)) != 0) {
        *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) & 0xffffffff)) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) & 0xffffffff)) + 32)) + -1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB288: if_get u32@0xc, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_offc_883FB288(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)) != 0) {
        return ((ts4_word (*)(void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))))) + 0))) + 8))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)))));
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB2B8: if_get u32@0xc, u32@0x0, u32@0x10 */
ts4_word ts4_if_get_u32_offc_883FB2B8(ts4_word a0)
{
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)) != 0) {
        return ((ts4_word (*)(void *))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))))) + 0))) + 16))))(((void *)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)))));
    }
    return 0;
}

/* Swing_DLL.xex 0x885CF3C8: if_get u32@0xb0, u32@0xb8, u32@0xac, u32@0xac, u32@0x0, u32@0x8 */
void ts4_if_get_u32_offb0_885CF3C8(ts4_word a0)
{
    ts4_word p6;

    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 176)) == 0) {
        if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 184)) == 0) {
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 184)) & 0xffffffff)) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 184)) & 0xffffffff)) + 8)) | 64);
        return;
    }
    if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172)) != 0) {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 172))) + 0));
    } else {
        p6 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(p6) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 8)) | 64);
    return;
}
