/* agAU near-miss: LTCG ctx=[] build, 3 off: target holds m->res in r11, candidate in r3. */

typedef unsigned int u32;
typedef struct { u32 key; int val; } Pair;
typedef struct { char p0[0x64]; u32 w; u32 h; } Disp;
typedef struct { u32 pad; Pair *begin; Pair *end; } PairMap;
typedef struct { PairMap map; char p0[0x18]; char *arr; char p1[0x30]; u32 v58; } Res;
typedef struct { char p0[0x10]; Res *res; } Mgr;
typedef struct { char p0[0x34]; u32 hw; u32 hh; u32 h; } Obj;
extern Disp *lbl_88D45A4C;
extern Mgr *lbl_88D45AD4;
static Pair *find(Pair *p, Pair *e, u32 k){ for (; p != e; p++) if (p->key == k) break; return p; }
static int lookup(PairMap *r, u32 k){ Pair *p = find(r->begin, r->end, k); if (p != r->end) return p->val; return -1; }
int fn_886F99C8(Obj *o){ Disp *d = lbl_88D45A4C; Mgr *m = lbl_88D45AD4; int idx;
 o->hw = d->w >> 1; o->hh = d->w >> 1; o->h = d->h;
 idx = lookup(&m->res->map, 0x496663FF); *(u32 *)(m->res->arr + idx * 0x44 + 8) = m->res->v58; return 1; }
