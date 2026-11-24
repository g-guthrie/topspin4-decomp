/* nearmiss: 48 off (LTCG, --context src/xbox360/pp1_pool_primer.c); head, segment search loop and n==2 lerp match.
 * Open: (1) the n==1 lerp must stay unfused (target fmuls f6=r*dy; fadds f5=y0,f6), every spelling fuses to fmadds and
 * #pragma fp_contract(off) has no effect on the LTCG route (tool limit: one instruction short shifts the rest);
 * (2) the two clamp blocks store value/limit with the opposite FPR numbering (f0/f13) to every literal/extern form
 * tried (named extern: alias scheduling; literal 2.0f: lands in the main pool, wrong relocation layout).
 * Blocks 0x886CB778 and, through it, 0x886D5F78 (LTCG clobber knowledge needs this body). */
/* Swing_DLL.xex 0x886C6758: piecewise-linear curve evaluation into {value, limit, clamped} */
typedef unsigned char u8;
extern const float g_ts4_event_value[];
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
static __inline void out_set(CurveOut *o, float v, float l, u8 c)
{
    o->clamped = c;
    o->value = v;
    o->limit = l;
}
void ts4_curve_eval_886C6758(Curve *c, CurveOut *out, float t)
{
    int below = c->start < t;
    u8 past = c->length + c->start < t;
    SegTable *tab;
    int n, i;
    Seg *s;
    if (!past) {
        tab = (SegTable *)((char *)c + c->table);
        i = 0;
        n = tab->count;
        if ((u8)below) {
            i = seg_find(tab, n, t);
            if (i < 0) {
                out_set(out, g_ts4_script_constants[19], g_ts4_event_value[7], 1);
                return;
            }
            n -= i;
        }
        if (n == 0) {
            out_set(out, g_ts4_script_constants[19], g_ts4_event_value[7], 1);
            return;
        }
        if (n == 1) {
            s = seg_at(tab, i);
            out->clamped = 1;
            out->value = s->y0;
            out->limit = s->y1;
            if ((u8)below) {
                float d = (t - s->x0) / (s->x1 - s->x0) * (s->y1 - s->y0);
                out->value = s->y0 + d;
            }
            return;
        }
        if (n == 2) {
            float v, lim;
            s = seg_at(tab, i);
            v = s->y0;
            if ((u8)below)
                v = (t - s->x0) / (s->x1 - s->x0) * (s->y1 - v) + v;
            lim = s[1].y1;
            if (lim < v) {
                out->limit = lim; out->value = v; out->clamped = 0;
                return;
            }
        }
        out_set(out, g_ts4_event_value[0], g_ts4_script_constants[0], 1);
        return;
    }
    out_set(out, g_ts4_script_constants[19], g_ts4_event_value[7], 1);
}
