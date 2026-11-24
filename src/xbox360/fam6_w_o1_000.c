/* Small functions produced by the asm2c translator (FAM4/FAM5 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM6: FAM5 near misses fixed by a per-function hill climb over source-level
   variants. Besides FAM5's mutations (operand order, retyped locals, volatile
   reloads, statement swaps, if/else inversion, members for `this`), it uses:
   a ||/&& condition kept in an unsigned char/int temporary; compound
   assignment; resized/reordered stack arrays; a load hoisted out of both
   branches or above a store; strlen() instead of an inline byte scan (the
   intrinsic returns through `clrrwi`); a one-word struct argument read from
   memory (also `clrrwi`). Callers and callees sit in different files.
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

ts4_word ts4_get_bits_24_1b_1_883E1880();
ts4_word ts4_range_acc_update_8859A008();

/* Swing_DLL.xex 0x883D45F8: if_call_seq ts4_get_bits_24_1b_1_883E1880, u32@0x14, u32@0xc, u32@0xc, u16@0x36 */
ts4_word ts4_if_call_seq_ts4_get_bits_24_1b_1_883E1880_883D45F8(ts4_word a0)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word t1;

    t1 = ts4_get_bits_24_1b_1_883E1880();
    b80 = !((int)(t1 & 0xff) == 0) || ((ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 12))) + 12))) + 54)) != 0);
    p7 = (ts4_word)b80;
    return (p7 & 0xff);
}

/* Swing_DLL.xex 0x8859E980: if_call_seq ts4_range_acc_update_8859A008, u32@0x34, u32@0x1c, u32@0x1c, u32@0x34, u32@0x1c0 */
ts4_word ts4_if_call_seq_fn_8859A008_8859E980(ts4_word a0, int a1)
{
    ts4_word p10;
    ts4_word p11;
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t5;
    ts4_word t7;

    t1 = ts4_range_acc_update_8859A008((ts4_word)a0, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 28);
    if (!((int)a1 != 0)) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)(t3 + 1);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        p10 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 448)) + (*(ts4_word *)((char *)(ts4_word)(t7) + 32)));
        p11 = (ts4_word)t7;
    } else {
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)(t3 + -1);
        t4 = *(ts4_word *)(52 + (char *)(ts4_word)(a0));
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 448);
        p10 = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t4) + 32))) - t5);
        p11 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(p11) + 32) = (ts4_word)p10;
    return t1;
}
