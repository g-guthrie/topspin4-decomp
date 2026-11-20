typedef unsigned short u16;
struct W8bKey { u16 id; u16 v; };
struct W8bRelK { int rel; };
struct W8bObjK { unsigned char pad00[0x9c]; struct W8bRelK hdr; };
struct W8bSrcB { unsigned char pad00[0xc]; struct W8bObjK *o; };
struct W8bSrcA { unsigned char pad00[0x18]; struct W8bSrcB *b; };
struct W8bSrcC { unsigned char pad00[0x18]; struct W8bSrcA *a; };
struct W8bSel { unsigned char pad00[0x24]; u16 lo; u16 hi; };

int ts4_find_key_id_886C4760(struct W8bSrcC *self, struct W8bSel *sel, float x)
{
    struct W8bRelK *h = &self->a->b->o->hdr;
    int t = (int)(x * 65535.0f);
    int lo = sel->lo;
    int hi = sel->hi;
    int best, i, r = -1;
    if (lo != hi) {
        struct W8bKey *e;
        best = lo;
        for (i = lo; i != hi; i++) {
            e = (struct W8bKey *)((char *)h + (i * 4 + h->rel));
            if (e->v >= t)
                break;
            best = i;
        }
        e = (struct W8bKey *)((char *)h + (best * 4 + h->rel));
        r = e->id;
        if (r == 0xffff)
            r = -1;
    }
    return r;
}
