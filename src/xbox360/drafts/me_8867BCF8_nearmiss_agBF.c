/* 0x8867BCF8 near miss (agBF, 2 off): clears three vectors of a gameplay object: a byte vector at +0xa8
 * (self-erase via memmove fn_88562DC0), an 8-byte record vector at +0x9c (per-element ts4_zero_field4_8890D7C0,
 * then ts4_dc8_erase_8826B830), and an 8-byte POD vector at +0x90 (inline erase copy loop).
 * LTCG, ctx flags(/Ob1):src/xbox360/fj_small_a.c and flags(/Ob1):src/xbox360/cx27_dc_a.c.
 * Remaining diff: the target loads end (0xa0) before first (0x9c) for the destroy loop. */

typedef unsigned int u32;
typedef struct Dc8 { u32 a, b; } Dc8;
typedef struct Dc8V { Dc8 *first; Dc8 *end; } Dc8V;
typedef struct { char *first, *last; } BV;
extern void *fn_88562DC0(void *d, const void *s, u32 n);
extern void ts4_zero_field4_8890D7C0(char *a);
extern Dc8 *ts4_dc8_erase_8826B830(Dc8V *v, Dc8 *dst, Dc8 *first);
typedef struct { char pad[0x90]; Dc8V c; char p2[4]; Dc8V b; char p3[4]; BV a; } O;
static char *bcopy_(char *first, char *last, char *dest) { if (first == last) { return dest; } else { u32 n = (u32)(last - first); dest = (char *)fn_88562DC0(dest, first, n); return dest + n; } }
static void bv_clear(BV *v) { v->last = bcopy_(v->last, v->last, v->first); }
static void dc_clear(Dc8V *v) { Dc8 *p, *e; for (e = v->end, p = v->first; p != e; p++) ts4_zero_field4_8890D7C0((char *)p);
    ts4_dc8_erase_8826B830(v, v->first, v->end); }
static Dc8 *e8_erase(Dc8V *v, Dc8 *dst, Dc8 *first) {
    int n = v->end - first; Dc8 *p = dst; Dc8 *s = first;
    while (n > 0) { p->a = s->a; p->b = s->b; n--; p++; s++; }
    v->end = p; return dst;
}
void ts4_clear_vectors_8867BCF8(O *o) {
    bv_clear(&o->a);
    dc_clear(&o->b);
    { Dc8V *v = &o->c; e8_erase(v, v->first, v->end); }
}
