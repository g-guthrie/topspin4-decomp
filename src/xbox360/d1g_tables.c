/*
 * D1G: data-table evaluators (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Formats: docs/gameplay/df.md section 4.4 (curve16 and the 2-D table used by the reach,
 * timing and movement tunables).
 */
#include "d1g_types.h"

/* One row of a 2-D table: a curve16 over y, keyed by x. */
struct Ts4Table2DRow {
    struct Ts4RelArray curve;   /* +0x00 curve16 keys {x0, x1, y0, y1} */
    ts4_u32 unk_08;
    float key;                  /* +0x0C ascending row key */
};

extern const float lbl_8814B440; /* 0.0f */
float ts4_range_lookup_881899D8(float x, struct Ts4Table2DRow *curve);

/* Sign bit of a float, read from its high half-word (true when negative). */
#define D1G_FLOAT_SIGN(f) (((unsigned short *)&(f))[0] >> 15)

/* 2-D table: find the last row whose key is <= x and interpolate linearly in x between that row's
   curve(y) and the next row's; outside the keyed range only the nearest row's curve is used.
   Swing_DLL.xex 0x8826D278 */
float ts4_table2d_eval_8826D278(struct Ts4RelArray *table, float x, float y)
{
    struct Ts4Table2DRow *end = 0;
    struct Ts4Table2DRow *it;
    struct Ts4Table2DRow *lo;
    if (table->offset != -1)
        end = (struct Ts4Table2DRow *)((char *)table + (table->count * 16 + table->offset));
    it = 0;
    if (table->offset != -1)
        it = (struct Ts4Table2DRow *)((char *)table + table->offset);
    lo = it;
    do {
        float d = x - it->key;
        if (D1G_FLOAT_SIGN(d))
            break;
        lo = it;
        it++;
    } while (it != end);
    if (lo != it && it != end) {
        float a = ts4_range_lookup_881899D8(y, lo);
        float b = ts4_range_lookup_881899D8(y, it);
        float d = x - lo->key;
        float span = it->key - lo->key;
        if (d <= lbl_8814B440)
            return a;
        if (d >= span)
            return b;
        return (b - a) * (d / span) + a;
    }
    return ts4_range_lookup_881899D8(y, lo);
}
