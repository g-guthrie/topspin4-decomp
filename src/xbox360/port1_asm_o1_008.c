/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l2b_asm_o1_008.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

#ifdef _MSC_VER
#pragma function(memcpy)
#endif
#ifdef _MSC_VER
void *memcpy(void *dst, const void *src, unsigned int size);
#else
#include <string.h>
#endif

/* Swing_DLL.xex 0x885AA668 */
ts4_word ts4_get_u32_off0_885AA668(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)0, (ts4_word)t4, (ts4_word)((((int)t3 * (int)t2) + 3) << 2));
    t9 = (ts4_word)memcpy((void *)a1, (const void *)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), 12);
    return t9;
}

