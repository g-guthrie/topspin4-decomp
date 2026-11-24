/* 0x884D7A38: calls s->vt slot 3 with (s, a, b, ctx, c), where ctx is slot 5 of the global object lbl_88D26F84. */
/* Matched on /Oc (agAF). The inner call written inside the argument list loads s->vt first (into r31); a vt local or a ctx local does not. */
typedef struct G G;
typedef struct GVt { void *f[5]; void *(*get)(G *g); } GVt;
struct G { GVt *vt; };
extern G *lbl_88D26F84;
typedef struct S S;
typedef struct SVt { void *f[3]; void (*call)(S *s, void *a, void *b, void *ctx, void *c); } SVt;
struct S { SVt *vt; };
void fn_884D7A38(S *s, void *a, void *b, void *c)
{
    s->vt->call(s, a, b, lbl_88D26F84->vt->get(lbl_88D26F84), c);
}
