/* Swing_DLL.xex 0x8864E420: return 1 when any object in the vector answers 1 from vtable slot 4.
 * nm1: lwzx (index, begin) needs the vector as a computed-address local `v = &l->v` numbered 7
 * (params l, arg are 0 and 1; five dead locals before it). */
struct Nm1HObj;
struct Nm1HVt { void *s[4]; unsigned char (*fn)(struct Nm1HObj *, void *); };
struct Nm1HObj { struct Nm1HVt *vt; };
struct Nm1HVec { struct Nm1HObj **begin; struct Nm1HObj **end; };
struct Nm1HList { char pad[0x10]; struct Nm1HVec v; };

unsigned char ts4_any_handles_8864E420(struct Nm1HList *l, void *arg)
{
    int nm1_pad0 = 0; int nm1_pad1 = 0; int nm1_pad2 = 0; int nm1_pad3 = 0; int nm1_pad4 = 0;
    struct Nm1HVec *v = &l->v;
    unsigned n = (unsigned)(v->end - v->begin);
    unsigned i;
    (void)nm1_pad0; (void)nm1_pad1; (void)nm1_pad2; (void)nm1_pad3; (void)nm1_pad4;
    for (i = 0; i < n; i++) {
        struct Nm1HObj *o = v->begin[i];
        if (o->vt->fn(o, arg) == 1)
            return 1;
    }
    return 0;
}
