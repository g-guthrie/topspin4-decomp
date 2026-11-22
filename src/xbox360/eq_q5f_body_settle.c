/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886AD1F0 - EQUIVALENT tier, not byte-matched.
 * fn_check: not matched.
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_body_settle.equiv.json (flags /Oc) */
typedef unsigned int u32;
extern const float lbl_8814B440;    /* 0.0f */

/* ---- 0x886AD1F0: settle a body: clear its done/step counters, run the negative-product
 * fix-up (0x886AB250) when +0x110 * +0x100 is not >= 0, then step the solver
 * (0x889C2818 on +0x5dc) until done or 600 steps. Not byte-matched: LTCG keeps r3/r4
 * live into 0x886AB250. */
typedef struct Q5Body { char pad[0x14]; u32 done; u32 steps; char pad1c[0xe4]; float f100; char pad104[0xc]; float f110; } Q5Body;
typedef struct Q5Solver { char pad[0x5dc]; void *solver; } Q5Solver;
extern void fn_886AB250(Q5Solver *s, Q5Body *b);
extern void fn_889C2818(void *solver, Q5Body *b);

/* Swing_DLL.xex 0x886AD1F0 */
void ts4_body_settle_886AD1F0(Q5Solver *s, Q5Body *b)
{
    u32 i = 0;
    b->steps = 0;
    b->done = 0;
    if (!(b->f110 * b->f100 >= lbl_8814B440))
        fn_886AB250(s, b);
    while (!b->done && i < 600) {
        b->steps++;
        fn_889C2818(s->solver, b);
        i++;
    }
}
