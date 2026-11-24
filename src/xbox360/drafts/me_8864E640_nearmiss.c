/* agAM: still 2 off with per-component inline ad(F1 *p, float d){p->f += d;} on (F1*)&o->v.x etc.: x and y operands swapped, z right. */
/* NEAR MISS 0x8864E640 (fn_8864E640), /Oc: 2 off. Both fadds for y and z have swapped operands (f2,f12 / f3,f10). The pointer-local stores fixed the store/load order; operand order of += and = x + *p made no difference (agU 2026-11-19, work/army/ME/v.py chk, matching-b154). */
typedef struct { char p[0x30]; float x, y, z; } S;
void ts4_nearmiss_8864E640(S *s, float x, float y, float z) { s->x = x + s->x; { float *p = &s->y; *p = *p + y; } { float *p = &s->z; *p = *p + z; } }
