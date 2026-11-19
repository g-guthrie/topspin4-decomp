/* NEAR MISS 0x8869FAD8 shot-stats ctor (agD 2026-11-19): 58 off plain /Oc (LTCG worse, ~115). Five counter groups (vtable 0x880D7600, four totals and a 12-word history), 24 float averages (zero; [17] = g_ts4_script_constants[0], 1.0), four reset words and two tail words.
 * All nine dead addis appear. Reading z between g[3] and g[4] and storing avg[17] last gave 129 -> 58. Remaining: the target
 * interleaves the g[4] init with the avg stores (z in f0, 1.0 in f13 loaded mid-way); ours does g[4] first and is 4 bytes longer. */
typedef struct Quad { int w[4]; } Quad;
typedef struct Sub { const void *vt; int a[4]; union { int b[12]; Quad q[3]; }; } Sub;
typedef struct Self { int pad; Sub g[5]; int w[4]; float avg[24]; int tail[2]; } Self;
extern const void *lbl_880D7600[];
extern float g_ts4_event_value;
extern float g_ts4_script_constants[];
static __inline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __inline void arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
static __inline void sub_init(Sub *p) { p->vt = lbl_880D7600; arr_init(p->b); p->a[0] = 0; p->a[1] = 0; p->a[2] = 0; p->a[3] = 0; }
Self *ts4_shot_stats_ctor_8869FAD8(Self *s)
{
    float z;
    sub_init(&s->g[0]); sub_init(&s->g[1]); sub_init(&s->g[2]); sub_init(&s->g[3]);
    z = g_ts4_event_value;
    sub_init(&s->g[4]);
    s->avg[0] = z; s->avg[1] = z; s->avg[2] = z; s->avg[3] = z; s->avg[4] = z; s->avg[5] = z; s->avg[6] = z; s->avg[7] = z;
    s->avg[8] = z; s->avg[9] = z; s->avg[10] = z; s->avg[11] = z; s->avg[12] = z; s->avg[13] = z; s->avg[14] = z; s->avg[15] = z;
    s->avg[16] = z; s->avg[17] = z; s->avg[18] = z; s->avg[19] = z; s->avg[20] = z; s->avg[21] = z; s->avg[22] = z; s->avg[23] = z;
    s->avg[17] = g_ts4_script_constants[0];
    s->w[0] = 0; s->w[1] = 0; s->w[2] = 0; s->w[3] = 0;
    s->tail[0] = 0; s->tail[1] = 0;
    return s;
}
