/* 0x886F34D0: once per pending flag, test whether time t has reached the current key's (positive) time. */
typedef struct AnimKey { unsigned id; float time; } AnimKey;
typedef struct AnimKeyArr { int rel; } AnimKeyArr;
typedef struct AnimClip { char pad[0x20]; AnimKeyArr keys; } AnimClip;
typedef struct AnimInst { char pad[0xc]; AnimClip *clip; } AnimInst;
typedef struct AnimCursor { char pad[0x30]; int idx; } AnimCursor;
typedef struct AnimTrigger { struct AnimTriggerVt *vt; char pad[8]; AnimCursor *cur; unsigned char pending; } AnimTrigger;
typedef struct AnimTriggerVt { char pad[0x18]; unsigned char (*active)(AnimTrigger *); } AnimTriggerVt;
static AnimKey *anim_key_at(AnimKeyArr *a, int i) { return (AnimKey *)((char *)a + (i * sizeof(AnimKey) + a->rel)); }
unsigned char anim_key_reached_886F34D0(AnimTrigger *o, AnimInst *in, float t)
{
    if (o->vt->active(o) && o->pending) {
        AnimKey *k;
        o->pending = 0;
        k = anim_key_at(&in->clip->keys, o->cur->idx);
        {
            float kt = k->time;
            if (kt > 0.0f && t >= kt) return 1;
        }
    }
    return 0;
}
