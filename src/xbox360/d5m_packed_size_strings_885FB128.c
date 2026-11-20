/* Swing_DLL.xex 0x885FB128-0x885FB4C4, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
struct Rec { char pad0[0x10]; u32 a; u32 pad14; u32 b; const char *s1; const char *s2; };

u32 ts4_packed_size_885FB128(struct Rec *r)
{
    u32 l1, l2;
    if (r->s1) l1 = (u32)strlen(r->s1) + 2; else l1 = 2;
    if (r->s2) l2 = (u32)strlen(r->s2) + 2; else l2 = 2;
    return r->b + r->a + l2 + l1 + 0x16;
}

struct Rec2 { char pad0[0x24]; u32 b; u32 pad28; u32 a; u32 pad30; const char *s1; const char *s2; };

u32 ts4_packed_size_885FB438(struct Rec2 *r)
{
    u32 l1, l2;
    if (r->s1) l1 = (u32)strlen(r->s1) + 2; else l1 = 2;
    if (r->s2) l2 = (u32)strlen(r->s2) + 2; else l2 = 2;
    return r->a + r->b + l2 + l1 + 0x2a;
}
