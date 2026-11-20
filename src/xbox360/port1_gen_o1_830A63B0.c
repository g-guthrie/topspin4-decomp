/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l1b_gen_o1_830A63B0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

ts4_word fn_88292F80();
#ifdef _MSC_VER
#pragma function(memcpy)
#endif
#ifdef _MSC_VER
void *memcpy(void *dst, const void *src, unsigned int size);
#else
#include <string.h>
#endif

/* Swing_DLL.xex 0x884F23E8 */
ts4_word ts4_if_call_seq_u16_off28_884F23E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    unsigned short t1;
    unsigned short t2;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        p5 = (ts4_word)((2147483648) | 16389);
    } else {
        t2 = *(unsigned short *)((char *)(ts4_word)(a0) + 42);
        memcpy((void *)a2, (const void *)(ts4_word)(((int)t2 * (int)a1) + (*(ts4_word *)((char *)(ts4_word)(a0) + 48))), 24);
        p5 = (ts4_word)0;
    }
    return p5;
}

