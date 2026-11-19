/* NEAR MISS 0x888C72E8 (fn_888C72E8), /Oc: 1 off, cmplw operand order (target cmplw r10,r11). a == b, b == a, int/unsigned, early-return and local forms tried (agU 2026-11-19, work/army/ME/v.py chk, matching-b154). */
typedef struct { char p[0x18]; unsigned a; unsigned busy; unsigned q; unsigned b; } S;
unsigned char ts4_nearmiss_888C72E8(S *s) { return s->busy || s->b == s->a; }
