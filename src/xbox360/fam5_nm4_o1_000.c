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

extern char lbl_88D3CAF4[];
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88150878();

/* Swing_DLL.xex 0x88158A38: if_call_seq u32@0x0, u32@0x4, u32@0x8, ts4_if_call_seq_u32_lbl_88D45B38_88150878, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88158A38(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word p2;
    ts4_word t1;

    q80 = a0 + 8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    p2 = (ts4_word)0;
    if ((ts4_word)a1 != 0) {
        t1 = ts4_if_call_seq_u32_lbl_88D45B38_88150878((ts4_word)(q80));
        p2 = (ts4_word)t1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p2;
    *(ts4_word *)((char *)(ts4_word)((q80)) + 0) = (ts4_word)(p2 + a1);
    memset((ts4_word)p2, (ts4_word)0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(p2 + a1);
    return a0;
}

