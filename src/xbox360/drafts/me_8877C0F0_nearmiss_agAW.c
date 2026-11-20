/* agAW near-miss, 3 off: target loads t->rel (lwz 0x214) before li/addi. plain /Oc and LTCG ctx=[] same. */

typedef struct Ent { int pad0[3]; int val; int pad1[3]; int key; } Ent;
typedef struct Tab { int rel; } Tab;
typedef struct Mgr Mgr;
typedef struct MgrVt { void *s[18]; Mgr *(*get)(Mgr *, int); } MgrVt;
struct Mgr { MgrVt *vt; char pad[0x210]; Tab t; };
static __inline Ent *at(Tab *t, int i) { return (Ent *)((char *)t + (i * 32 + t->rel)); }
extern Mgr *fn_884B5DA0(unsigned int);
int fn_8877C0F0(int key)
{
    Mgr *m = fn_884B5DA0(0x8C5A4922);
    Tab *t;
    int i;
    m = m->vt->get(m, 0);
    t = &m->t;
    for (i = 0; i < 4; i++) {
        if (at(t, i)->key == key) return at(t, i)->val;
    }
    return -1;
}
