/* Loader_DLL.xex 0x8319CB50-0x83242E58, executable version 0.0.0.3.
 * Repack of a 16-byte record into a zero-initialised 24-byte record. */

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

void ts4l_repack_record_8319CB50(const Ts4lSource16 *s, Ts4lPacked24 *d)
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

void ts4l_repack_record_83242E58(const Ts4lSource16 *s, Ts4lPacked24 *d)
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
