/* nearmiss: 19 off (fn_check_ltcg /Oc, context reach3-style 3-arg 8866BC48 + fk5_001.c + pp1_pool_primer.c, --include 8866BC48).
   Concrete blocker: register allocation after the Path() join. Target reloads self->target once (r9), loads
   rel (lwz r10,4(r11); addi r11,r11,4) BEFORE the actor reload, loads actor into r6 and passes it as a late-CSE
   copy (mr r5,r6). Candidate keeps two separate reloads (one for the 3rd argument, one for index/pos). 101 accessor
   combinations (direct / Actor() / local / ActorRef()) plateau at 19; the owning class at self+0x154 has no shared
   type yet, so the original accessor form is unknown. Callee 8866BC48 matches with an unused 3rd parameter. */
#include "w6a_types.h"
struct Q5Actor {
    unsigned char pad00[0x8e0];
    __vector4 pos;
    unsigned char pad8f0[0xbc8 - 0x8f0];
    int index;
    unsigned char padbcc[0xbd1 - 0xbcc];
    unsigned char flag;
};
struct Q5Target { unsigned char pad00[0x74]; Q5Actor *actor; };
struct Q5RelArr {
    int rel;
    const __vector4 &operator[](int i) const { return *(const __vector4 *)((const char *)this + (i * 16 + rel)); }
};
struct Q5Entry { int pad0; Q5RelArr a; unsigned char pad[0x60 - 8]; };
struct Q5Probe { float f0, f4, radius; };
struct Q5Self {
    unsigned char pad00[0x2c];
    Q5Entry *paths;
    unsigned char pad30[0x154 - 0x30];
    Q5Target *target;
    Q5Actor *Actor() const { return target->actor; }
    Q5Actor *const &ActorRef() const { return target->actor; }
    const Q5Entry &Path() const { return Actor()->flag ? paths[0] : paths[1]; }
};
extern "C" unsigned char ts4_planner_ball_reachable_in_time_8866BC48(Q5Self *self, const Q5Probe *p, const Q5Actor *actor);
extern "C" int ts4_target_within_radius_88678708(Q5Self *self, const Q5Probe *p)
{
    const Q5Entry &path = self->Path();
    Q5Actor *a = self->Actor();
    __vector4 d = __vsubfp(path.a[a->index], self->Actor()->pos);
    __vector4 s = __vmsum3fp(d, d);
    unsigned char hit = ts4_planner_ball_reachable_in_time_8866BC48(self, p, self->ActorRef());
    unsigned char close = s.v[0] < p->radius * p->radius;
    if (hit || close)
        return 1;
    return 0;
}
