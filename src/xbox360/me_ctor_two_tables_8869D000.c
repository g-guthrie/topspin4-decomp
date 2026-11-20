/* 0x8869D000 (hand match): constructor; two embedded 0x48-byte tables zeroed, then the four header words. */
typedef struct Quad { int w[4]; } Quad;
typedef struct Sub { void *vt; int a[4]; union { int b[12]; Quad q[3]; }; int pad; } Sub;
typedef struct Self { void *vt; int f4, f8, fc, f10; Sub s14; Sub s5c; } Self;
extern char lbl_880F4468[];
extern char lbl_880D7600[];
static __inline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __inline void arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
static __inline void sub_init(Sub *p) { p->vt = lbl_880D7600; arr_init(p->b); p->a[0] = 0; p->a[1] = 0; p->a[2] = 0; p->a[3] = 0; }
Self *ts4_ctor_two_tables_8869D000(Self *s)
{
    s->vt = lbl_880F4468;
    sub_init(&s->s14);
    sub_init(&s->s5c);
    s->f8 = 0;
    s->f4 = 0;
    s->f10 = 0;
    s->fc = 0;
    return s;
}
