/* Q5 round 4 near-miss of 0x88678708 ts4_target_within_radius (fn_check_ltcg, /Oc, pool primer): 10 instructions off; gaps: &rel address form and mr r5,r6 for fn_8866BC48's unused 3rd arg. Not a match. */
#include "w6a_types.h"
struct Q5Actor {
    unsigned char pad00[0x8e0];
    __vector4 pos;                      /* +0x8e0 */
    unsigned char pad8f0[0xbc8 - 0x8f0];
    int index;                          /* +0xbc8 */
    unsigned char padbcc[0xbd1 - 0xbcc];
    unsigned char flag;                 /* +0xbd1 */
};
struct Q5Target { unsigned char pad00[0x74]; Q5Actor *actor; };
struct Q5RelArr {
    int pad0; int rel;
    const __vector4 &operator[](int i) const { return *(const __vector4 *)((const char *)&rel + (i * 16 + rel)); }
};
struct Q5Paths { Q5RelArr a; unsigned char pad[0x60 - 8]; Q5RelArr b; };
struct Q5Probe { float f0, f4, radius; };
struct Q5Self {
    unsigned char pad00[0x2c];
    Q5Paths *paths;                     /* +0x2c */
    unsigned char pad30[0x154 - 0x30];
    Q5Target *target;                   /* +0x154 */
    Q5Actor *Actor() const { return target->actor; }
    const Q5RelArr &Path() const { return Actor()->flag ? paths->a : paths->b; }
};
extern "C" unsigned char fn_8866BC48(Q5Self *self, const Q5Probe *p, const Q5Actor *actor);
extern "C" int ts4_target_within_radius_88678708(Q5Self *self, const Q5Probe *p)
{
    const Q5RelArr &path = self->Path();
    Q5Actor *a = self->Actor();
    __vector4 d = __vsubfp(path[self->Actor()->index], self->Actor()->pos);
    __vector4 s = __vmsum3fp(d, d);
    unsigned char hit = fn_8866BC48(self, p, a);
    unsigned char close = s.v[0] < p->radius * p->radius;
    if (hit || close)
        return 1;
    return 0;
}
