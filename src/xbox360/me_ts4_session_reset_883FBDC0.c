/* 0x883FBDC0: resets each 0x20-byte entry of the table at +0x10, the inner block at +0x20, zeroes the 40-byte state at +0x58 and the stamp at +0x88, then notifies the callback at +0x98 with event 4 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the inner reset is an inline helper with its own if (r) return r; return 0; which gives the outer cmpwi cr6. */
typedef struct St { unsigned char a, b; char p2[2]; float level; __int64 c, d, e; int f, g; } St;
typedef struct Sub { int w[6]; } Sub;
typedef struct In { int p0, p4; Sub a; Sub b; } In;
typedef int (*Cb)(int ev, int a, int b, void *ctx);
typedef struct T { char pad[0xC]; int n; char *ents; char p14[0x20 - 0x14]; In in; St st; char p80[8]; __int64 p88; char p90[8]; Cb cb; void *ctx; } T;
int ts4_if_call_seq_u32_off4_883FB928(void *ent);
int ts4_if_call_seq_fn_883FADF0_883FAE48(Sub *s);
static int in_reset(In *in)
{
    in->a.w[3] = 0;
    { int r = ts4_if_call_seq_fn_883FADF0_883FAE48(&in->b); if (r) return r; }
    return 0;
}
int ts4_session_reset_883FBDC0(T *t)
{
    int i, r;
    St s;
    for (i = 0; i < t->n; ++i) {
        r = ts4_if_call_seq_u32_off4_883FB928(t->ents + i * 0x20);
        if (r) return r;
    }
    r = in_reset(&t->in);
    if (r) return r;
    s.a = 0; s.b = 0; s.level = 0.0f; s.c = 0; s.d = 0; s.e = 0; s.f = 0; s.g = 0;
    t->st = s;
    t->p88 = 0;
    if (t->cb) {
        r = t->cb(4, 0, 0, t->ctx);
        if (r) return r;
    }
    return 0;
}
