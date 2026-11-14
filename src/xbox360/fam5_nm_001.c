/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, ...).
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

ts4_word fn_88933EF8();
ts4_word fn_88936AF0();
ts4_word fn_88939040();
ts4_word fn_8893CD70();

/* Swing_DLL.xex 0x8899B2E8: if_call_seq fn_8893CD70, fn_88939040, u8@0x78, fn_88933EF8, fn_88936AF0 */
void ts4_if_call_seq_fn_8893CD70_8899B2E8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    fn_8893CD70();
    fn_88939040((ts4_word)a1, (ts4_word)(a0 + 112), (ts4_word)8);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 120);
    t4 = fn_88933EF8((ts4_word)a1, (ts4_word)1);
    if ((ts4_word)(t4 & 0xff) != 0) {
        fn_88936AF0((ts4_word)a1, (ts4_word)t3);
    }
    return;
}
