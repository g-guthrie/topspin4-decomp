/* nearmiss: 41 off (size 0x80 vs 0xa4); concrete blocker: the known open "one-arm operand sunk into the branch"
 * select (matching-tips.md, W-section "Still open: the table select ..."). The target computes both arms
 * (t - start, end - t) and selects with mfcr/lfsx/fsel; MSVC only if-converts when each arm is an
 * already-live value: probes show `(a >= kZero) ? b : a` with b a param -> fsel, with b = e - t -> branch,
 * in C and C++, under /Oc /O2 /Ox /Os, with extern or static zero, inline or cross-TU (LTCG-inlined) helper.
 * Swing_DLL.xex 0x886C48C8: index of the last layer whose weight != 0 and whose window [start, end]
 * contains t; -1 if none. Blocks 0x886C66C0 -> 0x886C7C28 (LTCG register preservation). */
extern float g_ts4_event_value;

struct Layer { unsigned char pad[0x20]; float weight; float start; float end; };
struct Vec { unsigned hdr; struct Layer **first; struct Layer **last; };
static __inline float h(float a,float b,float c,float d){ return (a - b >= g_ts4_event_value) ? c : d; }
static __inline unsigned char in_w(struct Layer *l, float t){ return h(t, l->start, l->end - t, t - l->start) >= g_ts4_event_value; }
int ts4_layer_last_active_at_886C48C8(struct Vec *v, float t)
{
    int i;
    for (i = (int)(v->last - v->first) - 1; i >= 0; --i) {
        struct Layer *l = v->first[i];
        if (l->weight != g_ts4_event_value && in_w(l, t))
            return i;
    }
    return -1;
}
