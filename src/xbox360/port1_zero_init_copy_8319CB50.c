/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l3b_zero_init_copy_8319CB50.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif

typedef struct {
    unsigned short a, b;
    unsigned c, d;
    unsigned short e, f;
    unsigned g;
    unsigned short h, i;
} Ts4lPacked24;

typedef struct {
    unsigned c, b, g, f;
} Ts4lSource16;



/* Swing_DLL.xex 0x885B51A0 */
void ts4_repack_record_885B51A0(const Ts4lSource16 *s, Ts4lPacked24 *d)
{
    memset(d, 0, 24);
    d->a = 0;
    d->b = (unsigned short)s->b;
    d->c = s->c;
    d->d = 0;
    d->e = 0;
    d->f = (unsigned short)s->f;
    d->g = s->g;
    d->h = 0;
}

