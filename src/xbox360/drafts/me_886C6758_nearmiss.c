/* 0x886C6758 near miss (76 off, /Oc plain C). Piecewise-linear curve lookup: segments {x0,x1,y0,y1} at a relative
 * table; outputs {value, limit, clamped}. Residue is block layout: target puts the clamp-high exit right after the search
 * loop and tests n-i with cmpwi (we emit subf.). Tried: inline find returning -1, explicit gotos with the exit block
 * placed after the loop (same code), C++ bool, f_lt helper, store order of the clamp exit; int 'below' fixed the prologue. */
typedef unsigned char u8;
extern const float lbl_8814B440[];
extern const float g_ts4_script_constants[];
typedef struct Seg { float x0, x1, y0, y1; } Seg;
typedef struct SegTable { int offset; int count; } SegTable;
typedef struct Curve { int table; char _4[0xC]; float start, length; } Curve;
typedef struct CurveOut { float value, limit; u8 clamped; } CurveOut;
static __inline Seg *seg_at(SegTable *t, int i) { return (Seg *)((char *)t + t->offset) + i; }
static __inline int seg_find(SegTable *t, int n, float x)
{
    int k;
    for (k = 0; k < n; k++)
        if (x <= seg_at(t, k)->x1)
            return k;
    return -1;
}
void ts4_curve_eval_886C6758(Curve *c, CurveOut *out, float t)
{
    int below = c->start < t;
    u8 past = c->length + c->start < t;
    u8 inside;
    SegTable *tab;
    int n, i, left;
    Seg *s;
    if (past)
        goto clamp_hi;
    inside = (u8)below;
    tab = (SegTable *)((char *)c + c->table);
    i = 0;
    n = tab->count;
    if (inside) {
        i = seg_find(tab, n, t);
        if (i < 0) goto clamp_hi;
    }
    left = n - i;
    if (left == 0) goto clamp_hi;
    if (left == 1) {
        s = seg_at(tab, i);
        out->clamped = 1;
        out->value = s->y0;
        out->limit = s->y1;
        if (inside)
            out->value = s->y0 + (t - s->x0) / (s->x1 - s->x0) * (s->y1 - s->y0);
        return;
    }
    if (left == 2) {
        float v, lim;
        s = seg_at(tab, i);
        v = s->y0;
        if (inside)
            v = (t - s->x0) / (s->x1 - s->x0) * (s->y1 - v) + v;
        lim = s[1].y1;
        if (lim < v) {
            out->value = v; out->limit = lim; out->clamped = 0;
            return;
        }
    }
    out->clamped = 1;
    out->value = lbl_8814B440[0];
    out->limit = g_ts4_script_constants[0];
    return;
clamp_hi:
    out->clamped = 1;
    out->value = g_ts4_script_constants[19];
    out->limit = lbl_8814B440[7];
}
