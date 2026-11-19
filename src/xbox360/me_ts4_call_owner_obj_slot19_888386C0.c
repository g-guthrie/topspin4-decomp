/* 0x888386C0: calls virtual slot 19 (+0x4C) with 0 on the object at s->p->o (+4, +0xC); 0 when there is none. */
/* Matched on /Oc (agAB). r = 0 first, then the call through a local p = s->p, which gives the clrrwi copy of p->o. */
typedef struct O O;
typedef struct OVt { void *f[19]; int (*fn)(O *o, int a); } OVt;
struct O { OVt *vt; };
typedef struct P { char pad[0xc]; O *o; } P;
typedef struct S { int p0; P *p; } S;
int fn_888386C0(S *s)
{
    int r = 0;
    P *p = s->p;
    if (p->o)
        r = p->o->vt->fn(p->o, 0);
    return r;
}
