/* nearmiss: 1 off (LTCG /Oc, pp1_pool_primer.c only; callee ts4_noop_881B3360 opaque).
 * Only `add r11,r30,r11` operand order differs (target index-first, candidate offset-first) on the strength-reduced
 * i*8 induction temp. matching-tips OP1 says the pad-local rule does not cover strength-reduced induction temps;
 * 0-11 referenced pad locals at the top, sizeof stride, offset-first, header local, at() helper all stay 1 off.
 * Same open residue as 88265E30/88265938 (matching-tips). Blocker: no known source form for this operand order. */
typedef unsigned int u32;
typedef struct SrArr { int offset; int count; } SrArr;
typedef struct E8 { u32 key; u32 value; } E8;
E8 *ts4_noop_881B3360(E8 *e);
E8 *ts4_srarr8_find_881BBC00(SrArr *self, const u32 *key)
{
    E8 *r = 0; int n = self->count; int i;
    for (i = 0; i < n; i++) { SrArr *h = self; E8 *e = (E8 *)((char *)h + (i * 8 + h->offset)); u32 k = *key; if (ts4_noop_881B3360(e)->key == k) { r = e; break; } }
    return r;
}
