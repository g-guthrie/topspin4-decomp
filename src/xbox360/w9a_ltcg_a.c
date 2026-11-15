/* W9A: LTCG route, /Oc. Entry reset loop. */
extern void fn_886DF3B0(void *p);
extern void fn_881B8360(void *p);
extern void ga6_run_hold_set_886D7C28(void *a, unsigned b);
extern void fn_886D9788(void *p);

typedef struct W9Pw { unsigned char pad[0x55]; unsigned char b55; unsigned char pad56[3]; unsigned char b59; unsigned char pad5a[0xfc - 0x5a]; unsigned char bfc; } W9Pw;
typedef struct W9Ob { void (**vt)(void *, int); } W9Ob;
typedef struct W9S { void *w00; unsigned char pad04[0x20]; void *w24; void *w28; } W9S;
typedef struct W9R { unsigned char pad00[0x70]; W9S s; unsigned pad9c; W9Ob *wa0; } W9R;
typedef struct W9Entry {
    unsigned char pad00[0x14];
    W9Pw *p;                       /* +0x14 */
    unsigned char pad18[0x30 - 0x18];
    unsigned char sub30[0x5c - 0x30];
    W9R *r;                        /* +0x5c */
    unsigned char pad60[0x150 - 0x60];
    unsigned char sub150[4];
} W9Entry;
typedef struct W9Mgr {
    unsigned char pad00[0x40];
    void *w40;
    unsigned char pad44[4];
    unsigned w48;
    unsigned char pad4c[4];
    W9Entry **begin;               /* +0x50 */
    W9Entry **end;                 /* +0x54 */
} W9Mgr;

void ts4_reset_entries_886E0E60(W9Mgr *m)
{
    unsigned n = m->end - m->begin;
    unsigned i;
    for (i = 0; i != n; i++) {
        W9S *s;
        W9R *r;
        m->begin[i]->p->bfc = 0;
        m->begin[i]->p->b59 = 1;
        m->begin[i]->p->b55 = 0;
        fn_886DF3B0(m->begin[i]->sub30);
        fn_886DF3B0(m->begin[i]->sub150);
        r = m->begin[i]->r;
        s = &r->s;
        if (s->w28) fn_881B8360(s->w28);
        {
            void *t = s->w24;
            s->w28 = 0;
            if (t) fn_881B8360(t);
        }
        s->w24 = 0;
        s->w00 = 0;
        if (r->wa0) {
            (*r->wa0->vt)(r->wa0, 1);
            r->wa0 = 0;
        }
    }
    ga6_run_hold_set_886D7C28(m->w40, m->w48 + 0x1f4);
    fn_886D9788(m->w40);
}
