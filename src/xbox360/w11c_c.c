/* W11C: LTCG-route matches (context: pp1_pool_primer.c). Record reset at +0x44 of the object two links down. */
struct W11cRec { unsigned char p[0x18]; unsigned h18; unsigned char q[0x2c-0x1c]; float f2c; };
struct W11cHdr { int rel; int f4; };
struct W11cOwn { unsigned char p[0x44]; struct W11cHdr h; };
struct W11cMid { unsigned char p[0x28]; struct W11cOwn *o; };
struct W11cTop { unsigned char p[0x1c]; struct W11cMid *m; unsigned w20; };
void ts4_reset_rec_88672828(struct W11cTop *s)
{
    struct W11cHdr *h = &s->m->o->h;
    struct W11cRec *r;
    h->f4 = 1;
    r = (struct W11cRec *)((char *)h + h->rel);
    r->h18 = 0x968230b3u;
    r = (struct W11cRec *)((char *)h + h->rel);
    r->f2c = 3.402823466e+38f;
    s->w20 = 0;
}
