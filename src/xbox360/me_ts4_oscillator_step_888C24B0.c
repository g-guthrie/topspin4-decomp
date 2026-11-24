/* 0x888C24B0: ping-pong/clamp/wrap oscillator step; per-edge mode 0 reverses step, 1 sets hi, 2 sets lo; value resets to 0 when the countdown hits 0 (agAY). Plain /Oc. */
typedef struct Osc { int count; float v; float step; float hi; float lo; unsigned hiMode; unsigned loMode; } Osc;
extern const float g_ts4_event_value;
void ts4_oscillator_step_888C24B0(Osc *o)
{
    float v = o->v + o->step;
    o->v = v;
    if (v >= o->hi) {
        switch (o->hiMode) {
        case 0: o->step = -o->step; break;
        case 1: o->v = o->hi; break;
        case 2: o->v = o->lo; break;
        }
    } else if (v <= o->lo) {
        switch (o->loMode) {
        case 0: o->step = -o->step; break;
        case 1: o->v = o->hi; break;
        case 2: o->v = o->lo; break;
        }
    }
    if (--o->count == 0) o->v = g_ts4_event_value;
}
