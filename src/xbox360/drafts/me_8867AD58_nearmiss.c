/* me_8867AD58 near-miss: 36 off (plain /Oc and LTCG same). Structure/control flow match; residue: target reloads
   s->m (0x48) for rules->limit in the fl->on arm, and the m/kind registers are r8/r9 swapped vs ours.
   Tried 8 variants (bool/?: flag, volatile m field, inline accessor, local placement, volatile self cast). */

typedef struct Clock { char p[0x310]; int frame; } Clock;
typedef struct Rules { char p[0x30]; unsigned char tiebreak; char q[0xaf]; int limit; } Rules;
typedef struct RulesRef { char p[0x20]; Rules *r; } RulesRef;
typedef struct Kind { int v; } Kind;
typedef struct Shot { char p[0x84]; unsigned int id; } Shot;
typedef struct ShotRef { char p[0x88]; Shot *shot; } ShotRef;
typedef struct Match { char p[4]; ShotRef **players; char q[0x28]; Clock *clock; char r[0x28]; RulesRef *rules; char s[0x18]; Kind *kind; } Match;
typedef struct Idx { char p[0x48]; int i; } Idx;
typedef struct IdxRef { char p[0x24]; Idx *idx; } IdxRef;
typedef struct Hist { char p[0x14c]; int base; } Hist;
typedef struct HistRef { char p[0x6c]; Hist *h; } HistRef;
typedef struct Flags { char p[0x5e3]; unsigned char on; } Flags;
typedef struct Cnt { char p[0x464]; int n; } Cnt;
typedef struct Req { char p[4]; int frame; unsigned int id; } Req;
typedef struct Self { char p[0x44]; HistRef *hist; Match *m; IdxRef *ir; char q[0x24]; Flags *fl; Cnt *cnt; char s[0x10]; Req *req; } Self;

int fn_8867AD58(Self *s)
{
    Match *m = s->m;
    Req *rq = s->req;
    int r = rq->frame;
    unsigned int id = 0xCA68AAECu;
    unsigned char flag; int t;
    if (m->kind->v == 2)
        id = m->players[s->ir->idx->i]->shot->id;
    flag = m->rules->r->tiebreak || id == 0x280AE84Du || id == 0x2C59FAEAu;
    if (s->fl->on) {
        t = s->cnt->n;
        if (t < s->m->rules->r->limit && !flag) goto tail;
        if (t < r) r = t;
    } else if (flag) {
        t = m->clock->frame + 1;
        if (t < r - s->hist->h->base) t = r - s->hist->h->base;
        if (t < r) r = t;
    } else if (id == 0x81A72B79u || id == 0xCA68AAECu) {
        t = m->clock->frame + 10;
        if (t < r) r = t;
    }
tail:
    if (rq->id == 0xA03CA0EDu) {
        t = m->clock->frame + 10;
        if (t < r) r = t;
    }
    return r;
}
