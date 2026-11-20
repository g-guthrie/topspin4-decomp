/* 0x88695568: constructor. Installs the vtable, clears the header words, initialises two embedded 0x44-byte
 * tables (their own vtable, four words and a twelve-word body, all zero), then clears the count and the flag.
 * The first two header zeros are stored through block-local pointers so that the vtable store is scheduled first. */
typedef struct Quad { int w[4]; } Quad;
typedef struct Sub { void *vt; int a[4]; union { int b[12]; Quad q[3]; }; } Sub;
typedef struct Self { void *vt; int count; int f8, fc, f10, f14, f18, f1c; Sub s20; Sub s64; unsigned char flag; } Self;
extern char lbl_880F4608[];
extern char lbl_880D7600[];
static __inline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
static __inline void arr_init(int *b) { Quad *q = (Quad *)b; quad_init(&q[0]); quad_init(&q[1]); quad_init(&q[2]); }
static __inline void sub_init(Sub *p) { p->vt = lbl_880D7600; arr_init(p->b); p->a[0] = 0; p->a[1] = 0; p->a[2] = 0; p->a[3] = 0; }
Self *ts4_ctor_two_tables_88695568(Self *s)
{
    s->vt = lbl_880F4608;
    { int *p = &s->f8; *p = 0; }
    { int *p = &s->fc; *p = 0; }
    s->f10 = 0;
    s->f14 = 0;
    s->f18 = 0;
    s->f1c = 0;
    sub_init(&s->s20);
    sub_init(&s->s64);
    s->count = 0;
    s->flag = 0;
    return s;
}
