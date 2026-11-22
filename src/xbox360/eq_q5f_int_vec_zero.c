/* Top Spin 4 (Xbox 360, Swing_DLL.xex) - EQUIVALENT tier, not byte-matched.
 * fn_check: 5 instructions off (the target reloads `first` with lwz r3,0x14(r3) after
 * the subtract; every C/C++ spelling tried gives mr/clrrwi instead).
 * fn_equiv/3 evidence: work/q5/evidence/eq_q5f_int_vec_zero.equiv.json
 * (the blr after the memset tail branch is statically unreachable and excluded). */
typedef unsigned int u32;

typedef struct Q5fIntVec {
    char pad0[0x14];
    int *first;         /* +0x14 */
    int *last;          /* +0x18 */
} Q5fIntVec;

extern void *ts4_memset(void *dst, int c, u32 n);

/* Swing_DLL.xex 0x887F73F0: zero every int of a [first, last) vector. */
/* byte-gap: 6 off; reason not recorded */
void ts4_int_vec_zero_887F73F0(Q5fIntVec *v)
{
    if (v->first != v->last)
        ts4_memset(v->first, 0, (u32)(v->last - v->first) * sizeof(int));
}
