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

ts4_word ts4_if_call_seq_fn_88868A88_88869E80();

/* Swing_DLL.xex 0x8886B150: loop_call_seq u32@0x30, u32@0x2c, u32@0x4, u32@0x0, ts4_if_call_seq_fn_88868A88_88869E80 */
void ts4_loop_call_seq_u32_off30_8886B150(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
        if ((ts4_word)a1 == (ts4_word)((55902208) | 14141) || (ts4_word)t4 == (ts4_word)a1) {
            ts4_if_call_seq_fn_88868A88_88869E80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0)), (ts4_word)t4, (ts4_word)a2);
        }
        p8 = (ts4_word)(lv3 + 8);
        lv3 = p8;
    }
    return;
}
