/*
 * RA1 (register assignment) match.
 * Swing_DLL.xex 0x88657810 ts4_register_name_88657810:
 * - the third argument of the f48 vcall is a 4-byte hash struct passed by value (W9cId). A zero-valued struct
 *   argument is copied from the CSE'd zero register (`mr r5,r31`); a plain int 0 argument is always a fresh `li`.
 *   The struct temporaries also give the target's 0x10 larger frame.
 * - `if (lbl_88D45B08) { g = lbl_88D45B08; ...}`: g first assigned inside the block, so its saved register is
 *   the lowest (r28, copied from r3 after the test); `g = global; if (g)` gives g r31.
 */
typedef struct W9cRec { unsigned a, b, c, d; } W9cRec;
struct W9cG;
typedef struct W9cId { unsigned v; } W9cId;
typedef struct W9cGVt { char p[0x48]; void (*f48)(struct W9cG *, W9cRec *, W9cId); unsigned (*f4c)(struct W9cG *); } W9cGVt;
typedef struct W9cG { W9cGVt *vt; } W9cG;
struct W9cT;
typedef struct W9cTVt { char p[0x18]; void (*f18)(struct W9cT *, const char *); } W9cTVt;
typedef struct W9cT { W9cTVt *vt; } W9cT;
typedef struct W9cS { char p[0x50]; W9cT *p50; } W9cS;
extern W9cG *lbl_88D45B08;
extern void *ts4_memset(void *p, int c, unsigned n);
void ts4_register_name_88657810(W9cS *s, const char *name)
{
    W9cRec rec;
    char buf[0x40];
    char *p;
    const char *q;
    W9cG *g;
    rec.a = 0; rec.b = 0; rec.c = 0; rec.d = 0;
    ts4_memset(buf, 0, 0x40);
    rec.d = 0x8BB0F713u;
    p = buf;
    q = name;
    while (p != buf + 0x3f) {
        char c = *q;
        if (c == 0)
            break;
        *p = c;
        p++;
        q++;
    }
    *p = 0;
    if (lbl_88D45B08) {
        g = lbl_88D45B08;
        rec.a = 0x50;
        rec.c = g->vt->f4c(g);
        rec.b = 0xC397B739u;
        {
            W9cId h;
            h.v = 0xDEC70121u;
            g->vt->f48(g, &rec, h);
        }
        {
            W9cId h0;
            h0.v = 0;
            g->vt->f48(g, &rec, h0);
        }
    }
    s->p50->vt->f18(s->p50, name);
}
