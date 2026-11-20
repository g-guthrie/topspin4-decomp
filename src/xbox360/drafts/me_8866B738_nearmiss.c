/* near-miss 0x8866B738 (plain /Oc): 76 instructions off, same size, same control flow. Open: register numbering (target keeps owner in r9), out->pending load hoisted above the float store, li 0 placement. Restrict out-pointer variant got worse (95). */
/* 0x8866B738: records the frame offset of the current swing event's phase mark (backswing, contact, follow, recover)
 * relative to the clip start; clears the pending flag. */
typedef unsigned int u32;
typedef struct SwEvent { char p[0x18]; u32 kind; char p2[0x2c - 0x1c]; int mark[4]; } SwEvent;
typedef struct SwClip { char p[0x68]; int start; } SwClip;
typedef struct SwAnim { char p[0x24]; SwClip *clip; } SwAnim;
typedef struct SwOut { char p[0x6f1]; unsigned char pending; char p2[0xcf8 - 0x6f2]; float value; float offset; } SwOut;
typedef struct SwOwner { char p[0x10]; unsigned char active; char p2[0x4c - 0x11]; SwAnim *anim; SwEvent *event; char p3[0x74 - 0x54]; SwOut *out; } SwOwner;
typedef struct SwState { char p[0x1c]; SwOwner *owner; } SwState;
extern float g_ts4_event_value;
static __inline void set_offset(SwState *s, int mark)
{
    s->owner->out->offset = (float)(mark - s->owner->anim->clip->start);
}
void fn_8866B738(SwState *s)
{
    SwOwner *o = s->owner;
    if (o->active) {
        SwEvent *e = o->event;
        u32 k = e->kind;
        if (k == 0xF578057Au) { set_offset(s, e->mark[0]); o->out->pending = 0; return; }
        if (k == 0xD9FA1B37u) { set_offset(s, e->mark[1]); o->out->pending = 0; return; }
        if (k == 0xFC6F57A1u) { set_offset(s, e->mark[2]); o->out->pending = 0; return; }
        if (k == 0xC718DAAAu) { set_offset(s, e->mark[3]); o->out->pending = 0; return; }
    } else {
        o->out->value = g_ts4_event_value;
    }
    o->out->pending = 0;
}
