/* 0x88479F38: calls slot 4 (src at +0x10, pair arg, ctx, x) on every {obj, arg} pair back to front; ctx defaults to the owner's +0x6C */
/* Matched on /Oc (agAH). Plain reverse indexed loop with the chain written in full. */
typedef struct Pair { struct Obj *obj; void *arg; } Pair;
typedef struct Obj Obj;
typedef struct OVt { void *f[4]; void (*notify)(Obj *o, void *src, void *arg, void *ctx, void *x); } OVt;
struct Obj { OVt *vt; };
typedef struct Own { char p[0x6c]; void *ctx; } Own;
typedef struct T { char p[8]; Own *own; char p2[4]; char src[0x140]; Pair *pairs; int count; } T;
void fn_88479F38(T *t, void *x, void *ctx)
{
    int i;
    if (!ctx)
        ctx = t->own->ctx;
    for (i = t->count - 1; i >= 0; i--)
        t->pairs[i].obj->vt->notify(t->pairs[i].obj, t->src, t->pairs[i].arg, ctx, x);
}
