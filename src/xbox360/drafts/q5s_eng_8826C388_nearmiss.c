/* nearmiss: ~20 off (LTCG /Oc, pp1_pool_primer.c; callee ts4_fn_88273620 opaque, no callee context).
 * Self-relative 16-byte array find with key getter call. Target keeps a dead zero result in r24 and does NOT hoist the
 * self+offset add, yet loads offset and *key once in the preheader. With the callee source in context LTCG inlines or
 * uses volatile registers across the call (fk_004.c, also with flags(/Ob0)/(/Ob1)/(/Od)). Sisters 8826C400/8826C478/
 * 8826C4F0 (8-byte, noop getter) share the shape. Blocker: the callee is ICF-folded (ts4_fn_88273620 = `a0+12`), and the
 * original non-inlined, register-clobbering but pure call has no context form found. */
typedef unsigned int u32;
typedef struct SrArr { int offset; int count; } SrArr;
typedef struct E16 { u32 w[4]; } E16;
u32 *ts4_fn_88273620(E16 *e);
E16 *ts4_srarr16_find_8826C388(SrArr *self, const u32 *key)
{
    E16 *r = 0; int n = self->count; int i;
    for (i = 0; i < n; i++) { E16 *e = (E16 *)((char *)self + (i * 16 + self->offset)); if (*ts4_fn_88273620(e) == *key) return e; }
    return r;
}
