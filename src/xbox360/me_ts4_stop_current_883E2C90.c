/* 0x883E2C90: stops the node through fn_883E1608, and for the current item (+0x28) clears flag 0x200 and fires event 7 on the sink (+0x20) for kind-3 entries or for kind-0 entries without data when config flag bit 0 is set; then clears current/active and releases the resource at +0x30 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); the entry index comes from the parent at +0x54, or from the node itself. */
typedef struct Cfg { char pad[0x80AC]; unsigned int flags; } Cfg;
extern Cfg *lbl_88CAC988;
typedef struct Ent { int kind; int p4; void *p8; char pc[8]; int arg; } Ent;
typedef struct Tbl { char pad[0x10]; int arg; char p14[0x28 - 0x14]; Ent *ents; } Tbl;
typedef struct Def { char pad[0xC]; Tbl *tbl; } Def;
typedef struct Cur { char pad[0x40]; unsigned int flags; } Cur;
typedef struct Sink { char pad[0x74]; void *cb; } Sink;
typedef struct T { char pad[0x14]; Def *def; char p18[8]; Sink *sink; char p24[4]; Cur *cur; unsigned char active; char p2d[3]; void *res; char p34[0x3E - 0x34]; short index; char p40[0x54 - 0x40]; struct T *parent; } T;
int fn_883E1608(T *t, int a);
void ts4_call_cb_883C7220(Sink *s, int ev, int arg, int c);
int ts4_if_get_fn_8832BFC0_88317EC0(void *r);
int ts4_stop_current_883E2C90(T *t)
{
    T *ctx = t->parent ? t->parent : t;
    Cur *cur = t->cur;
    Tbl *tbl;
    Ent *e;
    int r;
    r = fn_883E1608(t, 1);
    if (r) return r;
    if (cur) {
        cur->flags &= ~0x200;
        tbl = t->def->tbl;
        e = &tbl->ents[ctx->index];
        if (e->kind == 3) {
            if (t->sink->cb)
                ts4_call_cb_883C7220(t->sink, 7, tbl->arg, (int)cur);
        } else if (e->kind == 0 && !e->p8 && (lbl_88CAC988->flags & 1) && t->sink->cb) {
            ts4_call_cb_883C7220(t->sink, 7, e->arg, (int)cur);
        }
    }
    t->cur = 0;
    t->active = 0;
    if (t->res) {
        ts4_if_get_fn_8832BFC0_88317EC0(t->res);
        t->res = 0;
    }
    return 0;
}
