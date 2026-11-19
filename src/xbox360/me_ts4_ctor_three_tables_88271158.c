/* 0x88271158: constructor. Two embedded 0x44-byte tables (vtable 0x880D7600, four words and a twelve-word body, all
 * zero; the first is the object itself), a 0x14-byte header at +0x88 (vtable 0x880D75FC, four zero words), a zero word at
 * +0x9C and two floats at +0xA0 set to g_ts4_event_value. Matches on the LTCG route (+ pp1_pool_primer.c), /Oc; plain
 * /Oc schedules the float load after the stores (18 off). */
typedef struct Quad { int w[4]; } Quad;
typedef struct Sub { void *vt; int a[4]; union { int b[12]; Quad q[3]; }; } Sub;
typedef struct Tail { void *vt; Quad q; } Tail;
typedef struct Self { Sub base; Sub s44; Tail s88; int g9c; float f[2]; } Self;
extern char lbl_880D7600[];
extern char lbl_880D75FC[];
extern float g_ts4_event_value;
static __inline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __inline void arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
static __inline void sub_init(Sub *p) { p->vt = lbl_880D7600; arr_init(p->b); p->a[0] = 0; p->a[1] = 0; p->a[2] = 0; p->a[3] = 0; }
static __inline void tail_init(Tail *p) { p->vt = lbl_880D75FC; quad_init(&p->q); }
Self *ts4_ctor_three_tables_88271158(Self *s)
{
    float z;
    z = g_ts4_event_value;
    sub_init(&s->base);
    sub_init(&s->s44);
    tail_init(&s->s88);
    s->f[0] = z; s->f[1] = z;
    s->g9c = 0;
    return s;
}
