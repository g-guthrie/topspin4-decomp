/* near-miss 0x8866ECA8 (plain /Oc): 90 instructions off (size 0x198 vs 0x19C). Open: target reloads the event list offset for end() and puts li 0 for begin first; rule/event compare order; saved-register numbering (r29 state vs our r27). Volatile offset gave too many reloads. */
/* 0x8866ECA8: sums the bonus of every scoring rule matched by an event in this frame's event list (negative bonuses
 * only count when the 0x96FE1E55 property is set; the base value is added when the extra flag is on) and adds it to
 * the frame score. Rules flagged edge-only fire only when their latch was clear and the event's state is 1. */
typedef unsigned int u32;
typedef struct ScEvent { u32 a; u32 b; int pad; unsigned char state; char p[3]; } ScEvent;
typedef struct ScRule { u32 a; u32 b; float bonus; float base; unsigned char edge; char p[3]; } ScRule;
typedef struct RelArr { int self_off; u32 count; } RelArr;
typedef struct ScOut { char p[0x2a0]; RelArr events; char p2[0x5db - 0x2a8]; unsigned char add_base; char p3[0xf28 - 0x5dc]; float score; } ScOut;
typedef struct ScRules { char p[0x618]; RelArr rules; } ScRules;
typedef struct ScOwner { char p[0x2c]; ScRules *rules; char p2[0x74 - 0x30]; ScOut *out; char p3[0x94 - 0x78]; char props[1]; } ScOwner;
typedef struct ScState { ScOwner *owner; char p[0x1c8 - 4]; unsigned char *latch; } ScState;
extern float g_ts4_event_value;
unsigned char fn_8826ACB8(void *props, u32 *key);
static __inline unsigned sign_bit(float f) { return *(unsigned short *)&f >> 15; }
static __inline ScEvent *ev_begin(RelArr *a)
{
    ScEvent *p = 0;
    if (a->self_off != -1) p = (ScEvent *)((char *)a + a->self_off);
    return p;
}
static __inline ScEvent *ev_end(RelArr *a)
{
    ScEvent *p = 0;
    if (a->self_off != -1) p = (ScEvent *)((char *)a + (a->count * sizeof(ScEvent) + a->self_off));
    return p;
}
void fn_8866ECA8(ScState *s)
{
    float zero = g_ts4_event_value;
    float sum = zero;
    RelArr *ev = &s->owner->out->events;
    RelArr *rl = &s->owner->rules->rules;
    u32 n = rl->count;
    ScEvent *it = ev_begin(ev);
    ScEvent *end = ev_end(ev);
    for (; it != end; it++) {
        u32 j;
        for (j = 0; j < n; j++) {
            ScRule *r = (ScRule *)((char *)rl + (j * sizeof(ScRule) + rl->self_off));
            if (r->a != it->a || r->b != it->b) continue;
            if (!r->edge || (!s->latch[j] && it->state == 1)) {
                float v = r->bonus;
                if (sign_bit(v)) {
                    u32 key = 0x96FE1E55u;
                    if (!fn_8826ACB8(s->owner->props, &key)) v = zero;
                }
                if (s->owner->out->add_base) v = r->base + v;
                sum = v + sum;
            }
            s->latch[j] = it->state;
        }
    }
    s->owner->out->score = s->owner->out->score + sum;
}
