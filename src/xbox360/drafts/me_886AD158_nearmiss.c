/* agP 2026-11-19: pointer-local vtable/f40 stores with z loaded after f40: 22 (LTCG) / 33 (plain, size +4); no gain. */
/* 0x886AD158 near miss (23 off, /Oc plain): constructor: vtables lbl_880F4850 (+0) and lbl_880D7604 (+0x24 inner),
 * zero floats/ints, 20 x 0x30-byte slots (3 ints cleared each). Residue: store scheduling and the target dead
 * `addi r10,r3,0x24` / loop base r3+0x34. */
extern const char lbl_880F4850[];
extern const char lbl_880D7604[];
extern const float lbl_8814B440;
#define g_ts4_event_value lbl_8814B440
typedef struct Slot3 { int a, b, c; char rest[0x24]; } Slot3;
typedef struct Inner {
    const void *vtbl;           /* +0x24 */
    float v[4];                 /* +0x28 */
    int f38, f3c, f40, f44, f48, f4c, f50;
    int pad54, pad58;
    Slot3 slots[20];            /* +0x5c */
} Inner;
typedef struct Outer {
    const void *vtbl; unsigned char active; int f08, f0c; int f10[5];
    Inner inner;
} Outer;
static __inline void inner_init(Inner *s)
{
    int i;
    float z = g_ts4_event_value;
    s->vtbl = lbl_880D7604;
    s->f38 = 0; s->f3c = 0; s->f40 = 0;
    s->v[0] = z; s->v[1] = z; s->f48 = 0; s->v[2] = z; s->f4c = 0; s->v[3] = z; s->f50 = 0; s->f44 = 0;
    for (i = 0; i < 20; i++) { s->slots[i].a = 0; s->slots[i].b = 0; s->slots[i].c = 0; }
}
void ts4_outer_init(Outer *o)
{
    o->vtbl = lbl_880F4850;
    o->f08 = 0; o->f0c = 0;
    inner_init(&o->inner);
    o->f10[0] = 0; o->f10[1] = 0; o->f10[2] = 0; o->f10[3] = 0; o->f10[4] = 0;
    o->active = 0;
}