/* 0x883DF7F8: clamps v to [lbl_88001A20, lbl_88001A68] and stores it at +0x20 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); forwards scale(+0x24)*v to the sink at +0x44, returning its error. */
extern const float lbl_88001A68;
extern const float lbl_88001A20;
typedef struct T { char pad[0x20]; float level; float scale; char pad2[0x44 - 0x28]; void *sink; } T;
int ts4_fetch_then_use_float_88317A60(void *sink, float v);
int ts4_set_clamped_level_883DF7F8(T *t, float v)
{
    if (v > lbl_88001A68)
        v = lbl_88001A68;
    if (v < lbl_88001A20)
        v = lbl_88001A20;
    t->level = v;
    if (t->sink) {
        int r = ts4_fetch_then_use_float_88317A60(t->sink, t->scale * v);
        if (r)
            return r;
    }
    return 0;
}
