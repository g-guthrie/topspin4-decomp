/* 0x883EAC40: stores the argument and, when a resource is attached, binds it through the target's slot 2 (global flag 0x80AC bit 0; 0x24 when nothing bound) or via 883DE6A8 / 883E8760 depending on the resource flags, then marks ready. The vtable slot-2 key call is taken as one-argument; 883DE6A8's draft prototype names its third argument const int *ids */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Cfg { char pad[0x80ac]; unsigned int flags; } Cfg;
extern Cfg *lbl_88CAC988;
typedef struct Res { char pad[0x18]; unsigned int flags; char pad2[0x20 - 0x1c]; void *src; } Res;
typedef struct Req { int a; int b; int c; } Req;
typedef struct Tgt Tgt;
typedef struct TgtVt { void *f0, *f1; int (*bind)(Tgt *g, Req *r, void **out); } TgtVt;
struct Tgt { TgtVt *vt; };
typedef struct T T;
typedef struct TVt { void *f0, *f1; void *(*key)(T *t); } TVt;
struct T {
    TVt *vt;
    char pad0[0x38 - 4];
    int slot;
    int id;
    char pad1[0x44 - 0x40];
    Res *res;
    void *bound;
    int ids;
    int arg;
    int a54;
    unsigned char ready;
};
int ts4_if_get_u32_off4_883E51B8(void *k);
int fn_883DE6A8(Res *t, unsigned int flags, const int *ids, int n);
int ts4_if_get_u32_lbl_88CAC988_883E8760(T *t, void *src, int *slot, int arg);

int fn_883EAC40(T *t, Tgt *g, int arg)
{
    int r;
    t->arg = arg;
    if (t->res) {
        if (lbl_88CAC988->flags & 1) {
            Req q;
            q.a = t->a54;
            q.b = ts4_if_get_u32_off4_883E51B8(t->vt->key(t));
            t->bound = 0;
            q.c = t->id;
            r = g->vt->bind(g, &q, &t->bound);
            if (r)
                return r;
            if (!t->bound)
                return 0x24;
        } else {
            if (t->res->flags & 0x300) {
                r = fn_883DE6A8(t->res, 1, &t->ids, 1);
                if (r)
                    return r;
            } else {
                r = ts4_if_get_u32_lbl_88CAC988_883E8760(t, t->res->src, &t->slot, arg);
                if (r)
                    return r;
            }
        }
    }
    t->ready = 1;
    return 0;
}
