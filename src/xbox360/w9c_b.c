/* W9C matched functions, LTCG route (/Oc, pool primer context). */
typedef struct W9cBElt { char p[0xc]; int f0c; char p2[8]; } W9cBElt;
typedef struct W9cBHdr { int rel; char p[0xc]; unsigned char b10; } W9cBHdr;
typedef struct W9cBT38 { char p[0x1d4]; int type; } W9cBT38;
typedef struct W9cBE30 { char p[0x330]; float f330; } W9cBE30;
typedef struct W9cBP4 { char p[0x30]; W9cBE30 *f30; char p2[4]; W9cBT38 *f38; char p3[0x10]; void *f4c; } W9cBP4;
typedef struct W9cBP8 { char p[0x24]; W9cBHdr h; } W9cBP8;
struct W9cBS;
typedef struct W9cBVt { char p[0x1c]; void (*f1c)(struct W9cBS *); char p2[0x38 - 0x20]; void (*f38)(struct W9cBS *); void (*f3c)(struct W9cBS *); } W9cBVt;
typedef struct W9cBS { W9cBVt *vt; W9cBP4 *p4; W9cBP8 *p8; int fc; unsigned char b10; } W9cBS;
extern void fn_88674BC8(void *p);
extern const float g_ts4_event_value;
extern float lbl_8814B45C;
extern const float g_ts4_script_constants[];
static __inline W9cBElt *w9cb_elt(W9cBHdr *h, int i) { return (W9cBElt *)((char *)h + (i * 0x18 + h->rel)); }
/* 0x886781E0: reset the state object: clear counters, call the virtual hooks, pick the tuning constant. */
void ts4_reset_886781E0(W9cBS *s)
{
    int t;
    W9cBHdr *h;
    float f;
    s->vt->f3c(s);
    s->vt->f38(s);
    h = &s->p8->h;
    h->b10 = 1;
    w9cb_elt(h, 0)->f0c = 0;
    w9cb_elt(h, 1)->f0c = 0;
    s->vt->f1c(s);
    s->fc = -1;
    fn_88674BC8(s->p4->f4c);
    t = s->p4->f38->type;
    if (t == 0x14)
        f = lbl_8814B45C;
    else
        f = g_ts4_script_constants[19];
    s->p4->f30->f330 = f;
    s->b10 = t < 0x14;
}

typedef struct W9cB2Id { unsigned a, b, c; } W9cB2Id;
typedef struct W9cB2Rec { char p[0x38]; float f38; char p2[8]; unsigned f44; char p3[0x10]; unsigned f58; char p4[0x80 - 0x5c]; } W9cB2Rec;
typedef struct W9cB2Hdr { int rel; unsigned cnt; } W9cB2Hdr;
typedef struct W9cB2Arg { char p[0x4c]; float f4c; char p2[0x78 - 0x50]; unsigned f78; } W9cB2Arg;
typedef struct W9cB2P14 { char p[0x49c]; W9cB2Hdr h; } W9cB2P14;
typedef struct W9cB2P1c { char p[0x14]; W9cB2P14 *p14; char p2[0x548 - 0x18]; W9cB2Id id; } W9cB2P1c;
typedef struct W9cB2S { char p[0x1c]; W9cB2P1c *p1c; } W9cB2S;
extern unsigned char *fn_88923530(unsigned c, W9cB2Id id, unsigned key);
/* 0x886CC318: claim the first free slot of the record table and fill it from the argument. */
void ts4_apply_886CC318(W9cB2S *s, W9cB2Arg *a)
{
    W9cB2Id id = s->p1c->id;
    unsigned char *r = fn_88923530(id.c, id, 0x25FCD125u);
    if (r[0x1030] == 0) {
        W9cB2P14 *x = s->p1c->p14;
        W9cB2Hdr *h = &x->h;
        int rel = x->h.rel;
        W9cB2Rec *begin, *end, *p;
        begin = 0;
        if (rel != -1)
            begin = (W9cB2Rec *)((char *)h + rel);
        end = 0;
        if (rel != -1)
            end = (W9cB2Rec *)((char *)h + (h->cnt * 0x80 + rel));
        for (p = begin; p != end; p++) {
            if (p->f44 == 0) {
                p->f44 = 0x2841D5D6u;
                p->f38 = a->f4c;
                p->f58 = a->f78;
                break;
            }
        }
    }
}
