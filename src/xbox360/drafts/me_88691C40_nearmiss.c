/* agI 2026-11-19: still 2 off. No effect (2): dead int pads 1-8 at function top and 1-6 in loop body; e/k/i declaration order; c in inner block or as inner copy; e-key or c-key local (same order); volatile e; *& forms. Worse: c-field locals before the loop (102), any order where c is loaded first (4-6), subtraction tests (3-5). Observation: MSVC always puts the first-loaded register on the left of cmplw; target loads e then c yet compares c,e. */
/* agF 2026-11-19: 12 -> 2 off (LTCG, same context). Fix: write the select zero and zero init as the literal 0.0f instead of a static kZero; LTCG puts it in g_ts4_event_value's pool slot, keeps it in f29 and copies it to f28. Left: cmplw operand order for the key0 and f4 tests (target loads e first, compares c,e); swaps, !=, casts, ueq helpers, const c: 2-6. */
/* near miss 0x88691C40 (LTCG route, /Oc, context: src/xbox360/fk6_000.c src/xbox360/me_phase_timer_flags_8866FB60.c
 *   src/xbox360/w5a_h.c, then pp1_pool_primer.c): about 12 real instruction differences (39 after alignment, most of
 *   them branch displacements shifted by one extra instruction); 4 by mnemonic.
 * Behaviour: compacts the 20-entry timer ring (ts4_loop_get_u32_off10_8865FE20), then walks it backwards from the newest
 * entry. For every entry with the newest entry's id or key it takes the phase timer and flags, clamps the time to the
 * curve table unless flag b is set, and if flag a is set moves the target value by the time delta clamped to
 * [-0.01, 0.01]. When the info record is armed, it copies one of two values chosen by an id lookup
 * (fn_8826CCD8). It writes the rest value into slot 2 when the f4 key matches and the record is not armed.
 * Residue: the target loads the zero once from g_ts4_event_value (0x8814B440) into f29, keeps it across the loop for both
 * mfcr/fsel selects and copies it into f28 for `rest` (savefpr_28). Here the named static kZero is rematerialised:
 * loaded into f2, reloaded after the fn_8826CCD8 call, and only f29-f31 are saved (stfd x3). Comparing against
 * g_ts4_event_value or a zero local turns the selects into branches. */
typedef unsigned char u8;
typedef struct Back { int offset; } Back;
typedef struct Entry { unsigned int key0, f4, id; int idx; int f10; float *val; char p[0x2d - 0x18]; u8 busy; char p2[0x30 - 0x2e]; } Entry;
typedef struct Sel { char p[0x10]; unsigned int key; char p2[0x1c - 0x14]; float a; float b; } Sel;
typedef struct Info { char p[0x10]; Sel sel; char p2[0x4a - 0x34]; u8 f4a; } Info;
typedef struct Tbl6c { char p[0x14]; char arr[4]; } Tbl6c;
typedef struct Ctx1c { char p[0x6c]; Tbl6c *f6c; } Ctx1c;
typedef struct Own { char p[0x1c]; Ctx1c *f1c; char p2[0x30 - 0x20]; Info *f30; } Own;
typedef struct Machine { char p[0x10]; Back cur; } Machine;
typedef struct Self { char p[4]; u8 f4; char p1[0x10 - 5]; int head; int count; char p2[0x1c - 0x18]; Own *f1c; Machine *f20; float f24_unused; float f28;
    char p3[0x4c - 0x2c]; void *f4c; char p4[0x5c - 0x50]; Entry ring[20]; } Self;
extern float g_ts4_script_constants[];
void ts4_loop_get_u32_off10_8865FE20(Self *s);
void ts4_phase_timer_flags_8866FB60(Self *o, float *time, u8 *a, u8 *b);
void ts4_clamp_to_table_88691B38(Self *self, void *t, int idx, float *val);
unsigned int *fn_8826CCD8(void *arr, const unsigned int *key);
static __inline float vmax(float a, float b) { return (a - b >= 0.0f) ? a : b; }
static __inline float vmin(float a, float b) { return (a - b >= 0.0f) ? b : a; }
static __inline void *cur(Back *b) { return (char *)b - b->offset; }
void ts4_ring_apply_timers_88691C40(Self *s)
{
    void *tbl;
    float zero, rest;
    int last, n;
    Entry *c;
    ts4_loop_get_u32_off10_8865FE20(s);
    tbl = cur(&s->f20->cur);
    zero = 0.0f;
    rest = zero;
    if (s->f4c) rest = s->f28;
    n = s->count;
    last = s->head + n - 1;
    if (n == 0) return;
    c = &s->ring[last % 20];
    if (n > 0) {
        int i = last + 20;
        unsigned int k = n;
        float lo = -0.01f, hi = 0.01f;
        do {
            Entry *e = &s->ring[i % 20];
            if (c->id == e->id || e->key0 == c->key0) {
                float t; u8 a, b;
                ts4_phase_timer_flags_8866FB60(s, &t, &a, &b);
                if (!b) ts4_clamp_to_table_88691B38(s, tbl, e->idx, &t);
                if (a) {
                    float *pv = e->val;
                    float base = *pv;
                    *pv = vmin(vmax(t - base, lo), hi) + base;
                }
                {
                    Own *o = s->f1c;
                    Info *in = o->f30;
                    Sel *sl = &in->sel;
                    if (in->f4a) {
                        unsigned int *r = fn_8826CCD8(o->f1c->f6c->arr, &sl->key);
                        float *pf = (e->id == *r) ? &sl->a : &sl->b;
                        *e->val = *pf;
                    }
                }
                if (s->f4 && !s->f1c->f30->f4a && e->f4 == c->f4) e->val[2] = rest;
            }
            i--;
        } while (--k);
    }
}
