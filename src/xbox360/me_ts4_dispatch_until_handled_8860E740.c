/* 0x8860E740: offers the event to each enabled listener in the vector at +0x24 until one handles it (slot 15) */
/* Matched on /Oc (agAH). done byte in r3, 'L **end = t->end, **it;' initialised in the declaration, loop test 'end != it && !done'. */
typedef struct L L;
typedef struct LVt { void *f[15]; unsigned char (*handle)(L *l, void *ev); } LVt;
struct L { LVt *vt; char p[0x1c]; unsigned char enabled; };
typedef struct T { char p[0x24]; L **begin; L **end; } T;
void fn_8860E740(T *t, void *ev)
{
    unsigned char done = 0;
    L **end = t->end, **it;
    for (it = t->begin; end != it && !done; it++) {
        L *l = *it;
        if (l && l->enabled)
            done = l->vt->handle(l, ev);
    }
}
