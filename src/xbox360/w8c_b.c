/* W8C: 0x8865F858, progress through a [lo, hi] range stored in the owner block, written to the
 * current element of a self-relative array (0 when the range is not larger than 1.0). LTCG route. */
struct W8cRel { unsigned char pad[0x104]; int rel; };
struct W8cD { unsigned char pad[0x44]; struct W8cRel *p44; };
struct W8cRange { unsigned char pad[0xf60]; float cur; unsigned char pad64[0xf6c - 0xf64]; float lo; float hi; };
struct W8cA {
    unsigned char pad[0x14]; int idx; unsigned char pad18[0x48 - 0x18];
    struct W8cD *p48; unsigned char pad4c[0x74 - 0x4c]; struct W8cRange *p74;
};
struct W8cO { struct W8cA *a; };
struct W8cElem { unsigned char pad[0x24]; float progress; };
extern const float g_ts4_event_value;

void ts4_set_range_progress_8865F858(struct W8cO *o)
{
    struct W8cA *a = o->a;
    struct W8cRange *b = a->p74;
    float lo = b->lo;
    float d = b->hi - lo;
    if (d > 1.0f) {
        float t = (b->cur - lo) / d;
        int *h = &a->p48->p44->rel;
        ((struct W8cElem *)((char *)h + (a->idx * 0x140 + *h)))->progress = t;
    } else {
        float z = g_ts4_event_value;
        int *h = &a->p48->p44->rel;
        ((struct W8cElem *)((char *)h + (a->idx * 0x140 + *h)))->progress = z;
    }
}
