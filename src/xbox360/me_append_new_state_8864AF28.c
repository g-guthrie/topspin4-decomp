/* 0x8864AF28 (hand match): creates a state record (0xC0 bytes, 16-aligned, from the main heap), copies the
 * owner's two current settings into it and appends it to the owner's record list; returns the record. */
typedef struct State { char p[0xb0]; int setting_b; int setting_a; char p1[8]; } State;
typedef struct Vec { State **first; State **last; State **end; } Vec;
typedef struct Obj { char p[0x28]; Vec states; int setting_a; int setting_b; } Obj;
extern void *lbl_88D45B38;
void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int flags, int tag);
State *ts4_init_state_8864A920(void *memory);
void fn_88174A38(Vec *v, State **where, State **value);
State *ts4_append_new_state_8864AF28(Obj *o)
{
    void *m = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0xc0, 0x10, 0, 2);
    State *s;
    State *t;
    Vec *v;
    if (m != 0)
        s = ts4_init_state_8864A920(m);
    else
        s = 0;
    t = s;
    s->setting_b = o->setting_b;
    s->setting_a = o->setting_a;
    v = &o->states;
    { if (v->last != v->end) { if (v->last != 0) *v->last = s; v->last++; return s; } fn_88174A38(v, v->last, &t); return t; }
}
