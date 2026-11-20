/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: zutil.c allocator of the second statically linked zlib copy (/Os). zcalloc is replaced by the game's
 * tagged allocator plus an alignment check and a clear; zcfree (0x883040B8) is matched elsewhere. */

#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#define __debugbreak() __builtin_trap()
#endif

#define PNG2_ZLIB_MEM_TAG 0x24810000u

void *fn_88888668(unsigned int size, unsigned int tag); /* game allocator */

/* Allocate items*size bytes from the game heap, break into the debugger if the block is not size-aligned, and
 * zero it (zlib zcalloc). Swing_DLL.xex 0x88304058 */
void *png2_zlib_zcalloc_88304058(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int n = items * size;
    unsigned char *p = (unsigned char *)fn_88888668(n, PNG2_ZLIB_MEM_TAG);

    (void)opaque;
    if (p) {
        if ((unsigned long)p % size != 0)
            __debugbreak();
        memset(p, 0, n);
    }
    return p;
}
