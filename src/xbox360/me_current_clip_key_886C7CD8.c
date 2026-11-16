/* 0x886C7CD8: reports the key of the clip a controller is playing: the clip named by the swing
 * state's selected index when one is selected, else the clip of the topmost animation layer; 0 when
 * the layer stack is empty. */
typedef struct Clip { char p[0x84]; unsigned int key; char p2[0x8c - 0x88]; } Clip;
typedef struct ClipTable { int offset; int count; } ClipTable;
typedef struct ClipBank { char p[0x50]; ClipTable clips; } ClipBank;
typedef struct Desc { char p[0xc]; ClipBank *bank; } Desc;
typedef struct SwingState { char p[0x448]; int selected; } SwingState;
typedef struct Swing { char p[0x14]; SwingState *state; Desc *desc; } Swing;
typedef struct LayerInner { char p[8]; Clip *clip; } LayerInner;
typedef struct Layer { char p[4]; LayerInner *inner; } Layer;
typedef struct LayerVec { Layer **begin; Layer **end; } LayerVec;
typedef struct AnimStack { char p[0x5c]; LayerVec layers; } AnimStack;
typedef struct Ctl { char p[0x28]; Swing *swing; AnimStack *stack; } Ctl;
static __inline Swing *swing_of(Ctl *c) { return c->swing; }
static __inline Clip *clip_at(ClipTable *t, int i) { return (Clip *)((char *)t + (i * sizeof(Clip) + t->offset)); }
static __inline int lempty(LayerVec *v) { return v->begin == v->end; }
static __inline Layer *lback(LayerVec *v) { return v->end[-1]; }
static __inline Clip *selected_clip(Swing *s) { return clip_at(&s->desc->bank->clips, s->state->selected); }
void ts4_current_clip_key_886C7CD8(unsigned int *__restrict out, Ctl *c)
{
    *out = 0;
    if (swing_of(c)->state->selected > -1) {
        *out = clip_at(&swing_of(c)->desc->bank->clips, swing_of(c)->state->selected)->key;
    } else if (!lempty(&c->stack->layers)) {
        *out = lback(&c->stack->layers)->inner->clip->key;
    }
}
