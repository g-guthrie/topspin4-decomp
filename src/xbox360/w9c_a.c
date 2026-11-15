/* W9C matched functions, plain route /Oc. */
typedef struct W9cAElt { char p[0xc]; int f0c; char p2[8]; } W9cAElt;
typedef struct W9cAHdr { int rel; } W9cAHdr;
typedef struct W9cAT { char p[0x1d4]; int type; } W9cAT;
typedef struct W9cAP4 { char p[0x38]; W9cAT *f38; } W9cAP4;
typedef struct W9cAP8 { char p[0x24]; W9cAHdr h; char p2[0x38]; unsigned f60; unsigned f64; } W9cAP8;
typedef struct W9cAS { char p[4]; W9cAP4 *p4; W9cAP8 *p8; } W9cAS;
static __inline W9cAElt *w9ca_elt(W9cAHdr *h, int i) { return (W9cAElt *)((char *)h + (i * 0x18 + h->rel)); }
/* 0x886779C0: choose a tier constant from the type and two self-relative counters. */
void ts4_pick_level_886779C0(W9cAS *s)
{
    unsigned char hi = 0;
    unsigned char mid = 0;
    int n;
    s->p8->f60 = s->p8->f64;
    {
        n = w9ca_elt(&s->p8->h, 0)->f0c + w9ca_elt(&s->p8->h, 1)->f0c;
    }
    switch (s->p4->f38->type) {
    case 6:
        if (n >= 8) hi = 1; else if (n >= 4) mid = 1;
        break;
    case 11:
        if (n >= 16) hi = 1; else if (n >= 8) mid = 1;
        break;
    case 21:
        if (n >= 34) hi = 1; else if (n >= 18) mid = 1;
        break;
    }
    if (hi) s->p8->f64 = 0xC920AC38u;
    else if (mid) s->p8->f64 = 0x4850AF43u;
    else s->p8->f64 = 0x26296DD2u;
}

typedef struct W9cA2H { unsigned a, b, c; } W9cA2H;
typedef struct W9cA2T16 { unsigned a, b, c, d; } W9cA2T16;
typedef struct W9cA2Ref { unsigned tgt; unsigned off; unsigned extra; } W9cA2Ref;
typedef struct W9cA2Tgt { struct W9cA2Vt *vt; } W9cA2Tgt;
typedef struct W9cA2Vt { void *s[10]; unsigned (*f28)(W9cA2Tgt *, W9cA2Ref *, unsigned, int); } W9cA2Vt;
typedef struct W9cA2O { char p[0x10]; unsigned f10, f14; } W9cA2O;
extern W9cA2Ref *ts4_handle_forward_88150770(W9cA2Ref *out, W9cA2H *h, unsigned *hash);
extern W9cA2H *ts4_handle_forward_88610A48(W9cA2H *out, W9cA2H *h, unsigned *hash);
extern void ts4_get_ts4_handle_forward_88150770_8864F6E8(W9cA2O *self, W9cA2H h);
static __inline unsigned w9ca2_get(W9cA2Ref *r, int n) { W9cA2Tgt *t = (W9cA2Tgt *)(unsigned long)r->tgt; return t->vt->f28(t, r, r->off, n); }
/* 0x88651060: base-construct from the handle, then read two xdata views (type hashes 0x3CD06B6C, 0xF2E1E039) of the same node into +0x10 and +0x14. */
void ts4_load_pair_88651060(W9cA2O *s, W9cA2H h)
{
    W9cA2T16 tmp[2];
    unsigned k[2];
    unsigned k2[2];
    unsigned v = 0xDCB67730u;
    W9cA2Ref *r;
    ts4_get_ts4_handle_forward_88150770_8864F6E8(s, h);
    k[0] = 0x3CD06B6Cu;
    k[1] = v;
    r = ts4_handle_forward_88150770((W9cA2Ref *)&tmp[1], ts4_handle_forward_88610A48((W9cA2H *)&tmp[0], &h, &k[0]), &k[1]);
    s->f10 = w9ca2_get(r, 4);
    k2[0] = 0xF2E1E039u;
    k2[1] = v;
    r = ts4_handle_forward_88150770((W9cA2Ref *)&tmp[0], ts4_handle_forward_88610A48((W9cA2H *)&tmp[1], &h, &k2[0]), &k2[1]);
    s->f14 = w9ca2_get(r, 4);
}

typedef struct W9cA3H { unsigned a, b, c; } W9cA3H;
typedef struct W9cA3Rec { int rel; unsigned cnt; unsigned f8; unsigned fc; unsigned f10; unsigned f14; } W9cA3Rec;
typedef struct W9cA3Node { int rel; unsigned type; } W9cA3Node;
extern unsigned ts4_offset_886CC4B8(W9cA3H h, void *p);
extern void ts4_walk_886CC560(void *self, W9cA3Node *n, W9cA3H *h);
/* 0x886CC560: recursive walk of a self-relative node tree; two node kinds fill a result slot from the handle and recurse into their children. */
void ts4_walk_886CC560(void *self, W9cA3Node *n, W9cA3H *h)
{
    int pad0 = 0;
    int pad1 = 0;
    unsigned t = n->type;
    if (t == 0x8361F2CAu) {
        W9cA3Rec *r = (W9cA3Rec *)((char *)n + n->rel);
        unsigned i;
        r->f10 = ts4_offset_886CC4B8(*h, &r->fc);
        for (i = 0; i < r->cnt; i++)
            ts4_walk_886CC560(self, (W9cA3Node *)((char *)r + (r->rel + i * 8)), h);
    } else if (t != 0xA0B2A282u && t == 0x1F84BB8Du) {
        W9cA3Rec *r = (W9cA3Rec *)((char *)n + n->rel);
        unsigned i;
        r->f14 = ts4_offset_886CC4B8(*h, &r->fc);
        for (i = 0; i < r->cnt; i++)
            ts4_walk_886CC560(self, (W9cA3Node *)((char *)r + (r->rel + i * 12)), h);
    }
    (void)pad0;
    (void)pad1;
}
