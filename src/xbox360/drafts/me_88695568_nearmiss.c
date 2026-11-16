/* NEAR MISS (7 off: lis/li/addi constant materialization order at the top; stores all match).
 * Tried base-init helper, vtable local, symbol types. 0x88695568: constructor; header words cleared, two embedded 0x44-byte tables
 * (own vtable, four words, twelve-word body) zeroed, then the count and the flag. */
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
    s->f8 = 0;
    s->fc = 0;
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
