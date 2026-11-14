/* Swing_DLL.xex 0x88578958-0x885789F0, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _recalloc. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern u32 ts4_crt_msize_8856D8F0(void *block);
extern void *fn_88565320(void *block, u32 size);

void *ts4_crt_recalloc_88578958(void *block, u32 count, u32 size)
{
    void *retp = 0;
    u32 size_orig = 0;
    u32 old_size = 0;
    if (count > 0 && 0xFFFFF000u / count < size) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 12;
        return 0;
    }
    size_orig = size = count * size;
    if (block != 0)
        old_size = ts4_crt_msize_8856D8F0(block);
    retp = fn_88565320(block, size);
    if (retp != 0 && old_size < size_orig)
        memset(old_size + (char *)retp, 0, size_orig - old_size);
    return retp;
}
