/* nearmiss: 2 off (q5s 2026-11-24); concrete blocker: the target schedules `lis r8,0xdfa2` AFTER the first `stw r11,0(r3)`, every C and C++ form puts it first. Tried as a real C++ ctor `??0Self@@QAA@XZ` /Oc: Base9 base ctor zeroing w[9], Slot{-1,0,0} ctor, Pair74 ctor, Sub24 ctor with a/b/m38 clears, hash set in Self body / via Id struct setter / via a Pair74(h) temporary (59 off) / Sub24 body (6 off); all others stay 2 off. */
/* agP 2026-11-19: pointer-local hash/header stores and a pointer-local w[] base do not move the lis (still 2 off both routes). */
/* NEAR MISS 0x88151088 (fn_88151088), 2 instructions off on both plain /Oc and LTCG routes (work/army/ME/v.py chk, matching-b133).
 * Only difference: the target schedules `lis r8,0xdfa2` before the first `stw r11,0x0(r3)`; ours puts it after.
 * Tried: hash via const local, one-member id struct, header words through a helper or local pointer, b7c moved. */
/* 0x88151088: constructor. Clears the header words, sets the slot at +0x2C to -1, stores the hash 0xDFA2AFF1 at +0x74,
 * clears the remaining fields and runs ts4_record184_init on the object. */
typedef struct Pair74 { unsigned hash; int v; } Pair74;
typedef struct Sub24 { int a, b, idx, c, d; int m38[15]; Pair74 p74; } Sub24;
typedef struct Self88151088 {
    int w[9]; Sub24 s24; unsigned char b7c; char p7d[3];
    int m80[4]; char p90[0xc0]; int m150[2]; char p158[0x14]; int m16c[5];
} Self88151088;
void ts4_record184_init_88151180(Self88151088 *s);
static __inline void pair_clear(Pair74 *p) { p->hash = 0; p->v = 0; }
static __inline void sub24_init(Sub24 *s) { s->idx = -1; s->c = 0; s->d = 0; pair_clear(&s->p74); s->a = 0; s->b = 0; }
Self88151088 *fn_88151088(Self88151088 *s)
{
    s->w[0] = 0; s->w[1] = 0; s->w[2] = 0; s->w[3] = 0; s->w[4] = 0; s->w[5] = 0; s->w[6] = 0; s->w[7] = 0; s->w[8] = 0;
    sub24_init(&s->s24);
    s->s24.m38[0] = 0; s->s24.m38[1] = 0; s->s24.m38[2] = 0; s->s24.m38[3] = 0; s->s24.m38[4] = 0; s->s24.m38[5] = 0; s->s24.m38[6] = 0;
    s->s24.m38[7] = 0; s->s24.m38[8] = 0; s->s24.m38[9] = 0; s->s24.m38[10] = 0; s->s24.m38[11] = 0; s->s24.m38[12] = 0; s->s24.m38[13] = 0;
    s->s24.m38[14] = 0;
    s->s24.p74.hash = 0xDFA2AFF1u; s->s24.p74.v = 0; s->b7c = 0;
    s->m80[0] = 0; s->m80[1] = 0; s->m80[2] = 0; s->m80[3] = 0;
    s->m150[0] = 0; s->m150[1] = 0;
    s->m16c[0] = 0; s->m16c[1] = 0; s->m16c[2] = 0; s->m16c[3] = 0; s->m16c[4] = 0;
    ts4_record184_init_88151180(s);
    return s;
}
