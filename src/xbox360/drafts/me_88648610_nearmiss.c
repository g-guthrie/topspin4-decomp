/* me_88648610 near-miss: 36 off (plain /Oc). Stepper command switch on cfg->kind: 0 = reset + start, 1 = reset
   (inlined ts4_reset_floats_886468B8), 2 = stop, 3/4 = nudge the 2D offset by +-(kind == 3 ? fwd : -back).
   Residue: the target re-reads s->cfg and re-tests kind == 3 inside cases 3 and 4; MSVC here folds the test using
   the switch value (tried int/unsigned kind, local switch value, s-taking helper, volatile cfg copy, non-inline
   helper, nudge(s, back) helper). Also reset store order 0x30/0x34. 8 variants. */
extern const float lbl_880C8FB0; /* 10.0f */
typedef struct MeV3 { float x, y, z; } MeV3;
typedef struct MeV2 { float x, y; } MeV2;
typedef struct StepCfg { unsigned first; char p4[4]; float fwd; float back; int kind; } StepCfg;
typedef struct Stepper {
    char pad[0x1c];
    unsigned char active; unsigned char moved; unsigned char started; char p1f;
    unsigned v20;
    char p24[4];
    MeV2 p;
    MeV3 a;
    char p3c[4]; StepCfg *cfg; char p44[0x20];
    MeV3 b;
} Stepper;
static __inline void me_v3_set(MeV3 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; }
static __inline void reset_floats(Stepper *s)
{
    s->v20 = 0;
    s->p.x = 0.0f;
    s->p.y = 0.0f;
    me_v3_set(&s->a, 0.0f, lbl_880C8FB0, 0.0f);
    me_v3_set(&s->b, 0.0f, 0.0f, 0.0f);
}
static __inline float step_amount(Stepper *s) { return s->cfg->kind == 3 ? s->cfg->fwd : -s->cfg->back; }
static __inline void v2_add(MeV2 *v, float d) { v->x = v->x + d; v->y = d + v->y; }

void fn_88648610(Stepper *s)
{
    switch (s->cfg->kind) {
    case 0:
        reset_floats(s);
        s->active = 1;
        s->started = 1;
        s->v20 = s->cfg->first;
        break;
    case 1:
        reset_floats(s);
        break;
    case 2:
        s->active = 0;
        break;
    case 3:
        v2_add(&s->p, step_amount(s));
        s->moved = 1;
        break;
    case 4:
        v2_add(&s->p, -step_amount(s));
        s->moved = 1;
        break;
    }
}
