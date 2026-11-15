/* HKA family copy of W9C ts4_load_pair_88651060 (identical body at Swing_DLL.xex 0x886514B8). Plain route /Oc. */
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

void ts4_load_pair_886514B8(W9cA2O *s, W9cA2H h)
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
