/*
 * Q5S swan: swing animation engine, 2-vector target set and scale (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_scale.c <name>=<addr> --flags /Oc --auto-context
 */
typedef struct Q5sVec2 { float x, y; } Q5sVec2;

typedef struct Q5sScaleBlk {
    unsigned char pad_00[0x14];
    float ratio;                /* +0x14 V 886CEEC0 (scale = ratio - 1) */
} Q5sScaleBlk;

typedef struct Q5sScaleInner {
    unsigned char pad_00[0x08];
    Q5sScaleBlk *blk;           /* +0x08 V 886CEEC0 */
} Q5sScaleInner;

typedef struct Q5sScaleSrc {
    unsigned char pad_00[0x04];
    Q5sScaleInner *inner;       /* +0x04 V 886CEEC0 */
    unsigned char pad_08[0x14 - 0x08];
    float pivot;                /* +0x14 V 886CEEC0 (subtracted from both lanes) */
    unsigned char pad_18[0x24 - 0x18];
    float offset;               /* +0x24 V 886CEEC0 (added to both lanes) */
} Q5sScaleSrc;

typedef struct Q5sScaleDst {
    unsigned char pad_00[0x04];
    Q5sVec2 target;             /* +0x04 V 886CEEC0 */
    Q5sVec2 cur;                /* +0x0c V 886CEEC0 */
} Q5sScaleDst;

static __inline void q5s_vec2_scale(Q5sVec2 *v, float k, float pivot, float offset)
{
    v->x = (v->x - pivot) * k + offset;
    v->y = (v->y - pivot) * k + offset;
}

/* 0x886CEEC0: sets the target, copies it to the current value (word copy), then scales the current value
 * about `pivot` by (ratio - 1) and adds `offset`. The `addi r11,r3,0xc` is the dead &d->cur kept by the
 * local `c` used for both the copy and the inline scale; the literal 1.0f (pool word 0 of
 * g_ts4_script_constants) gives the late constant load, `g_ts4_script_constants[0]` loads it too early. */
void ts4_vec2_set_scale_886CEEC0(Q5sScaleDst *d, Q5sScaleSrc *s, float x, float y)
{
    Q5sVec2 *c = &d->cur;
    d->target.x = x;
    d->target.y = y;
    *c = d->target;
    q5s_vec2_scale(c, s->inner->blk->ratio - 1.0f, s->pivot, s->offset);
}
