/* Swing_DLL.xex 0x886C5160: point every item of a pointer vector at owner->p34 + 0x110.
 * nm1: the lwzx (index, begin) order needs the vector as a computed-address local `v = &s->v`
 * numbered 7 (OP1 rule extended to a load off a sub-object local; six dead locals before it). */
struct Nm1OwnItem { char pad[0xc4]; char *owner; };
struct Nm1ItemVec { struct Nm1OwnItem **begin; struct Nm1OwnItem **end; };
struct Nm1OwnerSet { char pad[0x34]; char *p34; char pad2[0x18]; struct Nm1ItemVec v; };

void ts4_set_owner_ptrs_886C5160(struct Nm1OwnerSet *s)
{
    int nm1_pad0 = 0; int nm1_pad1 = 0; int nm1_pad2 = 0; int nm1_pad3 = 0; int nm1_pad4 = 0; int nm1_pad5 = 0;
    struct Nm1ItemVec *v = &s->v;
    unsigned n = v->end - v->begin;
    char *dst = s->p34 + 0x110;
    unsigned i;
    for (i = 0; i < n; i++)
        v->begin[i]->owner = dst;
    (void)nm1_pad0; (void)nm1_pad1; (void)nm1_pad2; (void)nm1_pad3; (void)nm1_pad4; (void)nm1_pad5;
}
