/* 0x883E84A8: with config flag bit 0 (+0x80AC) set, sends a {+0x54, owner id, +0x3C} event to the sink (virtual slot 3) with context +0x48; otherwise flushes the node at +0x44 when its 0x300 flags are set and the resource at +0x38 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); C++ virtual calls; returns the first error. */
struct Cfg { char pad[0x80AC]; unsigned int flags; };
extern "C" Cfg *lbl_88CAC988;
struct Ev { int a; int b; int c; };
struct Node { char pad[0x18]; unsigned int flags; };
struct Snk { virtual void v0(); virtual void v1(); virtual void v2(); virtual int send(Ev *ev, void *ctx); };
struct T {
    virtual void v0(); virtual void v1(); virtual void *owner();
    char p4[0x38 - 4]; void *res; int p3c; char p40[4]; Node *node; void *ctx; int p4c[2]; int p54;
};
extern "C" int ts4_if_get_u32_off4_883E51B8(void *o);
extern "C" int ts4_release_ids_then_update_883DD7A0(Node *n, int *p, int a);
extern "C" int ts4_if_get_fn_8832BFC0_88317EC0(void *r);
extern "C" int ts4_post_or_flush_883E84A8(T *t, Snk *s)
{
    int r;
    Ev ev;
    if (lbl_88CAC988->flags & 1) {
        if (t->ctx) {
            ev.a = t->p54;
            ev.b = ts4_if_get_u32_off4_883E51B8(t->owner());
            ev.c = t->p3c;
            r = s->send(&ev, t->ctx);
            if (r) return r;
        }
    } else {
        if (t->node && (t->node->flags & 0x300)) {
            r = ts4_release_ids_then_update_883DD7A0(t->node, t->p4c, 1);
            if (r) return r;
        }
        if (t->res) {
            r = ts4_if_get_fn_8832BFC0_88317EC0(t->res);
            if (r) return r;
        }
    }
    return 0;
}
