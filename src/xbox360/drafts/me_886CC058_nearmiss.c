/* agP 2026-11-19: pointer-local vtable / a.n,b.n / f30-f04 stores: 38-48 (LTCG best 38 with vtables via pointers), size still 0xc0. */
/* 0x886CC058 near miss (48 off, /Oc): tracker constructor: two vtables (+0, +8), clears floats/ints, scale (+0x3c) = 1.0,
 * then an inlined reset clears the +0x44 accumulator again. Residue: store scheduling (we hoist int stores ahead of the
 * float stores); target also keeps a dead `addi r10,r3,0x44` (sub-object helper). Inline-helper form reloads the zero. */
extern const char lbl_880F3798[];
extern const char lbl_880D6B70[];
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct Accum4 { float v[4]; int n; } Accum4;
typedef struct Tracker {
    const void *vtbl; int f04; const void *vtbl2;
    float f0c[9];
    int f30, f34;
    float f38, scale, f40;
    Accum4 a, b;
    int f6c; float f70; int f74, f78, f7c; unsigned char f80;
} Tracker;
void ts4_tracker_init(Tracker *t)
{
    float z = g_ts4_event_value;
    t->vtbl = lbl_880F3798;
    t->vtbl2 = lbl_880D6B70;
    t->a.v[0] = z; t->a.n = 0; t->a.v[1] = z; t->a.v[2] = z; t->a.v[3] = z;
    t->b.n = 0; t->b.v[0] = z; t->b.v[1] = z; t->b.v[2] = z; t->b.v[3] = z;
    t->f30 = 0; t->f34 = 0; t->f04 = 0;
    t->scale = g_ts4_script_constants[0];
    t->f38 = z; t->f40 = z;
    t->f0c[0] = z; t->f0c[1] = z; t->f0c[2] = z; t->f0c[3] = z;
    t->a.n = 0; t->a.v[0] = z; t->a.v[1] = z; t->a.v[2] = z; t->a.v[3] = z;
    t->f6c = 0; t->f0c[4] = z; t->f74 = 0; t->f0c[5] = z; t->f78 = 0; t->f0c[6] = z; t->f7c = 0;
    t->f0c[7] = z; t->f80 = 0; t->f0c[8] = z; t->f70 = z;
}