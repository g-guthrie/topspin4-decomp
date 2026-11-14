/* Swing_DLL.xex 0x885FA140-0x885FA204, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
struct Rec3 { char pad0[0x10]; const char *s1; const char *s2; const char *s3; };

u32 ts4_packed_size3_885FA140(struct Rec3 *r)
{
    u32 l1, l2, l3;
    if (r->s1) l1 = (u32)strlen(r->s1) + 2; else l1 = 2;
    if (r->s2) l2 = (u32)strlen(r->s2) + 2; else l2 = 2;
    if (r->s3) l3 = (u32)strlen(r->s3) + 2; else l3 = 2;
    return l3 + l2 + l1 + 0x44;
}
