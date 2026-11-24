/*
 * RA1, LTCG route only (spec work/specs/RA1/ra1_ltcg_a.ltcg.json).
 * Swing_DLL.xex 0x886AD030 ts4_init_886AD030: `if (n) c = f(n); else c = 0;` (explicit else, not `c = 0; if (n) ...`)
 * makes the CSE'd zero (stores of the 8-word block, the `c` phi and the tail-duplicated `b` phi) take r31 above
 * s=r30. The `b = 0` else arm gives the duplicated `stw; mr r3,r31; bl` tail. On the plain route the reload of
 * lbl_88D45B38 is scheduled after the `c->f5dc` store and `c` lands in r3 (33 off); under LTCG it matches.
 */
typedef struct W9cObj W9cObj;
typedef struct W9cVt { void *s[10]; unsigned *(*get)(W9cObj *, void *out, unsigned x, int n); } W9cVt;
struct W9cObj { W9cVt *vt; };
typedef struct W9cPair { W9cObj *obj; unsigned x; } W9cPair;
typedef struct W9cB { unsigned w[8]; } W9cB;
typedef struct W9cC { char p[0x5dc]; unsigned f5dc; } W9cC;
typedef struct W9cP1c { char p[0x7c]; unsigned f7c; } W9cP1c;
typedef struct W9cS1 { char p[0x14]; unsigned f14; char p2[4]; W9cP1c *p1c; char p3[4]; W9cC *f24; W9cB *f28; } W9cS1;
extern char lbl_880C8F40[];
extern void *lbl_88D45B38;
extern W9cPair *ts4_if_set_u32_off0_8862BE08(W9cPair *out, const char *name);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int flags, int tag);
extern W9cC *fn_886A77E8(void *p);
extern void ts4_call_seq_u32_lbl_88D45B38_8890E148(void *p);
void ts4_init_886AD030(W9cS1 *s)
{
    W9cPair tmp;
    unsigned *r;
    void *n;
    W9cC *c;
    W9cB *b;
    ts4_if_set_u32_off0_8862BE08(&tmp, lbl_880C8F40);
    r = tmp.obj->vt->get(tmp.obj, &tmp, tmp.x, 4);
    s->f14 = *r;
    n = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x610, 0x10, 0, 2);
    if (n)
        c = fn_886A77E8(n);
    else
        c = 0;
    s->f24 = c;
    c->f5dc = s->p1c->f7c;
    n = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x20, 4, 0, 2);
    if (n) {
        b = (W9cB *)n;
        b->w[2] = 0; b->w[3] = 0; b->w[6] = 0; b->w[7] = 0; b->w[0] = 0; b->w[1] = 0; b->w[4] = 0; b->w[5] = 0;
    } else {
        b = 0;
    }
    s->f28 = b;
    ts4_call_seq_u32_lbl_88D45B38_8890E148(b);
}
