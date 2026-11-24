/* 0x886B7F68 near miss (33 off as written; 25 off with `void *graph = o->ent->graphs->graph;` read before the
 * stores). Phase start: body weight 0/1 by busy flag, binds the selection (fn_88694030), prints entry rates, clears
 * 16 blend floats, runs fn_88693FA8, phase = 2. Residue: the game interleaves the graph loads into the 16 stores;
 * restrict pointer / inline clear helper: 27 / 29. */
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct Ts4Body { char p[0x99]; unsigned char busy; char p2[0xb4 - 0x9a]; char states[4]; } Ts4Body;
typedef struct Ts4Rig { char p[0x1c]; char *anim; char p2[0x28 - 0x20]; void *cfg; } Ts4Rig;
typedef struct Ts4Actor { char p[0x1c]; char *anim; char p2[0x28 - 0x20]; void *rates; char p3[0x44 - 0x2c]; Ts4Body *body; } Ts4Actor;
typedef struct Ts4Graphs { char p[0x28]; void *graph; } Ts4Graphs;
typedef struct Ts4Ent { char p[0x48]; Ts4Actor *actor; char p2[4]; Ts4Graphs *graphs; } Ts4Ent;
typedef struct Ts4Out { char p[0xf8]; float blend[16]; char p2[0x1b8 - 0x138]; float weight; } Ts4Out;
typedef struct Ts4Owner { char p[8]; Ts4Ent *ent; char p2[0x28 - 0xc]; Ts4Out *out; } Ts4Owner;
typedef struct Ts4Phase { char p[0x1c]; Ts4Owner *owner; unsigned phase; char sel[4]; } Ts4Phase;
void *fn_88694030(Ts4Ent *ent, Ts4Out *out, void *sel, char *anim);
void ts4_print_entry_rates_886B63B8(void *sel, void *rates);
void fn_88693FA8(void *graph, void *res, char *states);
static __inline void blend_clear(float *b, float z)
{
    b[0] = z;
    b[1] = z;
    b[2] = z;
    b[3] = z;
    b[4] = z;
    b[5] = z;
    b[6] = z;
    b[7] = z;
    b[8] = z;
    b[9] = z;
    b[10] = z;
    b[11] = z;
    b[12] = z;
    b[13] = z;
    b[14] = z;
    b[15] = z;
}
void ts4_phase_begin(Ts4Phase *self)
{
    float zero = g_ts4_event_value;
    Ts4Owner *o = self->owner;
    void *res;
    Ts4Out *out;
    o->out->weight = o->ent->actor->body->busy ? zero : g_ts4_script_constants[0];
    res = fn_88694030(self->owner->ent, self->owner->out, self->sel, self->owner->ent->actor->anim + 0xb4);
    ts4_print_entry_rates_886B63B8(self->sel, self->owner->ent->actor->rates);
    {
    o = self->owner;
    out = o->out;
    blend_clear(out->blend, zero);
    fn_88693FA8(o->ent->graphs->graph, res, self->owner->ent->actor->body->states);
    }
    self->phase = 2;
}
