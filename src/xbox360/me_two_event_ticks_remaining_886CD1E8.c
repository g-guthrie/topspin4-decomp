/* 0x886CD1E8: ticks remaining until the second event of the topmost animation layer whose clip
 * descriptor is a two-event kind (2). Returns -1 when no such layer exists or when it lies below the
 * stack's active layer index. */
typedef struct Event { char p[0x38]; float time; } Event;
typedef struct Events { volatile int offset; } Events;
static Event *events_begin(Events *t) { Event *r = 0; int off = t->offset; if (off != -1) r = (Event *)((char *)t + off); return r; }
static Event *events_data(Events *t) { int off = t->offset; return (Event *)((char *)t + off); }
typedef struct ClipDesc { char p[0x14]; float time_ratio; char p2[0x70 - 0x18]; Events events; unsigned int kind; } ClipDesc;
typedef struct LayerInner { char p[8]; ClipDesc *desc; } LayerInner;
typedef struct Layer { char p[4]; LayerInner *inner; char p2[0x14 - 8]; float rate; char p3[0x24 - 0x18]; float base_time; } Layer;
typedef struct LayerVec { Layer **begin; Layer **end; } LayerVec;
typedef struct AnimStack { char p[0x18]; float now; char p2[0x5c - 0x1c]; LayerVec layers; } AnimStack;
typedef struct Ctl { char p[0x2c]; AnimStack *stack; } Ctl;
extern float g_ts4_script_constants[];
int ts4_anim_layer_index_886C66C0(AnimStack *stack);
static int vec_size(LayerVec *v) { return (int)(v->end - v->begin); }
static Layer *vec_at(LayerVec *v, int i) { return v->begin[i]; }
static int top_layer_of_kind(AnimStack *st, unsigned int kind)
{
    LayerVec *v = &st->layers;
    int i;
    for (i = vec_size(v) - 1; i >= 0; i--)
        if (vec_at(&st->layers, i)->inner->desc->kind == kind) return i;
    return -1;
}
int ts4_two_event_ticks_remaining_886CD1E8(Ctl *self)
{
    int i = top_layer_of_kind(self->stack, 2);
    if (i != -1 && ts4_anim_layer_index_886C66C0(self->stack) <= i) {
        Layer *l = self->stack->layers.begin[i];
        ClipDesc *d = l->inner->desc;
        Event *ev = events_data(&d->events);
        return (int)((ev->time - l->rate) * (d->time_ratio - g_ts4_script_constants[0]) + l->base_time - self->stack->now);
    }
    return -1;
}
